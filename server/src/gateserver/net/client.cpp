///<------------------------------------------------------------------------------
//< @file:   gateserver\net\client.cpp
//< @author: ������
//< @date:   2015��3��14�� 21:4:7
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "client.h"

#include <client.pb.h>
#include <protocol.pb.h>
#include <protocol/message.h>

#include "clientmgr.h"
#include "gateserver.h"
#include <net/netaddress.h>
#include <server.h>
#include <tool/encrypttool.h>
#include <tool/randtool.h>

Client::Client()
	: m_link(NULL)
	, m_clientId(0)
	, m_taskQueue(NULL)
	, m_clientMgr(NULL)
{
	memset(m_encryptKey, 0, sizeof(m_encryptKey));
}

void Client::onEstablish()
{
	// ���������֤��
	randtool::secureRandom(m_authKey, sizeof(m_authKey), '0', 'z');
	randtool::secureRandom(m_encryptKey, sizeof(m_encryptKey), '0', 'z');



	//���ͼӽ�����Կ
	EncryptKeyNtf *ntf = msgtool::allocPacket<EncryptKeyNtf>();
	ntf->set_publickey((const char*)m_encryptKey, sizeof(m_encryptKey));
	ntf->set_privatekey((const char*)m_encryptKey, sizeof(m_encryptKey));
	ntf->set_authkey((const char*)m_authKey, sizeof(m_authKey));

	m_link->send(eEncryptKeyNtf, *ntf);
}

void Client::onDisconnect(Link *link, const NetAddress& localAddr, const NetAddress& peerAddr)
{
	LOG_INFO << "client [" << peerAddr.toIpPort() << "] <-> gatesvr [" << localAddr.toIpPort() << "] broken";
	m_clientMgr->delClient(this);
}

void Client::onRecv(Link *link, Buffer &buf)
{
	while(true) {
		// ����ͷ����
		size_t bytes = buf.readableBytes();
		if (bytes < sizeof(NetMsgHead)) {
			return;
		}

		NetMsgHead *msgHead = (NetMsgHead*)buf.peek();
		uint16 msgId = endiantool::networkToHost16(msgHead->msgId);
		uint32 dataLen = endiantool::networkToHost32(msgHead->msgLen);

		// �����
		if (dataLen > bytes) {
// 			LOG_WARN << "gatesvr [" << link->m_localAddr.toIpPort() << "] <-> client [" << link->m_peerAddr.toIpPort()
// 			          << "] msgLen(" << msgLen << ") > bytes(" << bytes << ")";
			return;
		}

		//�Ƚ���
		uint8* encryptBuf =  (uint8*)(buf.peek() + sizeof(NetMsgHead));
		int encryptBufLen = dataLen - sizeof(NetMsgHead);

		if(!encrypttool::decrypt(encryptBuf, encryptBufLen, m_encryptKey, sizeof(m_encryptKey))) {
			LOG_ERROR << "gatesvr [" << link->m_localAddr.toIpPort() << "] <-> client [" << link->m_peerAddr.toIpPort()
			          << "] decrypt msg [len=" << encryptBufLen << "] failed";
			buf.skip(dataLen);
			continue;
		}

		char *msg = (char*)buf.peek() + sizeof(NetMsgHead) + EncryptHeadLen;
		uint32 msgLen = dataLen - sizeof(NetMsgHead) - EncryptHeadLen - EncryptTailLen;

		// �ж��Ƿ���Ҫת����
		if (needRoute(msgId)) {
			// ת������Ϸ������
			GateServer::Instance().sendToGameServer(m_clientId, msgId, msg, msgLen);
		}
		else {
			// ֱ�ӱ��ؽ��д���
			Buffer deepCopyBuf;
			deepCopyBuf.append(msg, msgLen);
			Server::instance->getTaskQueue().put(boost::bind(&ClientMgr::handleMsg, m_clientMgr, this, msgId, deepCopyBuf, 0));
		}

		buf.skip(dataLen);
	};
}

bool Client::needRoute(int msgId)
{
	// �ж��Ƿ���Ҫת��
	if (eClientGateMsgIdMin < msgId && msgId < eClientGateMsgIdMax) {
		return false;
	}

	return true;
}

bool Client::send(int msgId, const char* data, int len)
{
	if (!m_link->isopen()) {
		return false;
	}

	//�ȼ���
	char *netBuf = global::g_packetBuf;
	uint32 headSize = sizeof(NetMsgHead);

	memcpy(netBuf + headSize + EncryptHeadLen, data, len);

	uint8* decryptBuf = (uint8*)(netBuf + headSize);
	int decryptBufLen = len + EncryptHeadLen + EncryptTailLen;//��Ӽӽ���ͷβ

	encrypttool::encrypt(decryptBuf, decryptBufLen, m_encryptKey, sizeof(m_encryptKey));

	NetMsgHead* pHeader = (NetMsgHead*)netBuf;

	int packetLen = msgtool::buildNetHeader(pHeader, msgId, decryptBufLen);
	m_link->send(netBuf, packetLen);

	return true;
}

bool Client::send(int msgId, Message &msg)
{
	if (!m_link->isopen()) {
		return false;
	}

	int size = msg.ByteSize();

	Buffer buf(size);

	bool ok = msg.SerializeToArray((void*)buf.beginWrite(), size);
	if (!ok) {
		LOG_ERROR << "client [" << m_link->m_peerAddr.toIpPort()
		          << "] send msg failed, SerializeToArray error, [len=" << size << "] failed, content = [" << msgtool::getMsgString(msg) << "]";

		return false;
	}

	buf.hasWritten(size);

	this->send(msgId, buf.peek(), buf.readableBytes());
	return true;
}