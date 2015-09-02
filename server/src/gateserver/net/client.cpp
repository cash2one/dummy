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
	, m_pingCount(0)
	, m_speedTestCount(0)
	, m_latencyTestCount(0)
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
//
// 	Message *msg = ntf;
// 	msgtool::freePacket(msg);
}

std::string Client::name()
{
	return echotool::getmsg("client<%u>", m_clientId);
}

void Client::onDisconnect(Link *link, const NetAddress& localAddr, const NetAddress& peerAddr)
{
	LOG_INFO << name() << " [" << peerAddr.toIpPort() << "] <-> gatesvr [" << localAddr.toIpPort() << "] broken";
	m_clientMgr->delClient(this);
}

void Client::onRecv(Link *link, Buffer &buf)
{
	m_taskQueue->put(boost::bind(&Client::handleMsg, this));
}

void Client::handleMsg()
{
	Link *link = m_link;
	Buffer buf;

	{
		lock_guard_t<> lock(link->m_recvBufLock);
		link->m_isWaitingRead = false;
		buf.swap(link->m_recvBuf);
	}

	while(true) {
		// ����ͷ����
		size_t bytes = buf.readableBytes();
		if (bytes < sizeof(NetMsgHead)) {
			break;
		}

		NetMsgHead *msgHead = (NetMsgHead*)buf.peek();
		uint16 msgId = endiantool::networkToHost16(msgHead->msgId);
		uint32 dataLen = endiantool::networkToHost32(msgHead->msgLen);

		// �����
		if (dataLen > bytes) {
			// 			LOG_WARN << "gatesvr [" << link->m_localAddr.toIpPort() << "] <-> client [" << link->m_peerAddr.toIpPort()
			// 			          << "] msgLen(" << msgLen << ") > bytes(" << bytes << ")";
			break;
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
			//GateServer::Instance().sendToGameServer(client->m_clientId, msgId, msg, msgLen);
		} else {
			// ֱ�ӱ��ؽ��д���
			m_clientMgr->m_dispatcher.dispatch(*this, msgId, msg, msgLen, 0);
		}

		buf.skip(dataLen);
	};

	if (!buf.empty()) {
		{
			lock_guard_t<> lock(link->m_recvBufLock);
			if (!link->m_recvBuf.empty()) {
				buf.append(link->m_recvBuf.peek(), link->m_recvBuf.readableBytes());
				link->m_recvBuf.swap(buf);
			} else {
				link->m_recvBuf.swap(buf);
			}
		}
	}
}

bool Client::needRoute(int msgId)
{
	// �ж��Ƿ���Ҫת��
	if (eClientGateMsgIdMin < msgId && msgId < eClientGateMsgIdMax) {
		return false;
	}

	return true;
}

bool Client::send(int msgId, Message &msg)
{
	if (!m_link->isopen()) {
		return false;
	}

	uint32 headSize = sizeof(NetMsgHead);
	int size = msg.ByteSize();

	bool ok = msg.SerializeToArray(global::g_encryptBuf + headSize + EncryptHeadLen, size);
	if (!ok) {
		LOG_ERROR << "client [" << m_link->m_peerAddr.toIpPort()
		          << "] send msg failed, SerializeToArray error, [len=" << size << "] failed, content = [" << msgtool::getMsgString(msg) << "]";

		return false;
	}

	// ��Ӽӽ���ͷβ
	uint8* decryptBuf = (uint8*)(global::g_encryptBuf + headSize);
	int decryptBufLen = size + EncryptHeadLen + EncryptTailLen;

	encrypttool::encrypt(decryptBuf, decryptBufLen, m_encryptKey, sizeof(m_encryptKey));

	NetMsgHead* pHeader = (NetMsgHead*)global::g_encryptBuf;

	int packetLen = msgtool::buildNetHeader(pHeader, msgId, decryptBufLen);
	m_link->send(global::g_encryptBuf, packetLen);

	return true;
}

void Client::close()
{
	m_link->close();
}
