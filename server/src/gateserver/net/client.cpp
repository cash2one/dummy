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
#include <net/netaddress.h>
#include <server.h>
#include <tool/encrypttool.h>

namespace clienttool
{
	// ��ȡ������飬��������nums
	void generateRandomNums(uint8 nums[], uint32 cnt)
	{
		for (uint32 i = 0; i < cnt; i++) {
			nums[i] = rand() % 10 + 48;
		}
	}
}

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
	//���ͼӽ�����Կ
	clienttool::generateRandomNums(m_encryptKey, sizeof(m_encryptKey));

	EncryptKeyNtf *ntf = msgtool::allocPacket<EncryptKeyNtf>();
	ntf->set_encryptkey((const char*)m_encryptKey, sizeof(m_encryptKey));

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
		uint32 msgLen = endiantool::networkToHost32(msgHead->msgLen);

		// �����
		if (msgLen > bytes) {
// 			LOG_WARN << "gatesvr [" << link->m_localAddr.toIpPort() << "] <-> client [" << link->m_peerAddr.toIpPort()
// 			          << "] msgLen(" << msgLen << ") > bytes(" << bytes << ")";
			return;
		}

		//�Ƚ���
		uint8* encryptBuf =  (uint8*)(buf.peek() + sizeof(NetMsgHead));
		int encryptBufLen = msgLen - sizeof(NetMsgHead);

		if(!encrypttool::decrypt(encryptBuf, encryptBufLen, m_encryptKey, sizeof(m_encryptKey))) {
			LOG_ERROR << "gatesvr [" << link->m_localAddr.toIpPort() << "] <-> client [" << link->m_peerAddr.toIpPort()
			          << "] decrypt msg [len=" << encryptBufLen << "] failed";
			buf.retrieve(msgLen);
			return;
		}

		char *msg = (char*)buf.peek() + sizeof(NetMsgHead) + EncryptHeadLen;

		// �ж��Ƿ���Ҫת����
		if (needRoute(msgId)) {
			// ת������Ϸ������
		}
		else {
			// ֱ�ӱ��ؽ��д���
			Buffer deepCopyBuf;
			deepCopyBuf.append(msg, msgLen - sizeof(NetMsgHead) - EncryptHeadLen - EncryptTailLen);
			Server::instance->getTaskQueue().put(task_binder_t::gen(&ClientMgr::handleMsg, m_clientMgr, *this, msgId, deepCopyBuf, 0));
		}

		buf.retrieve(msgLen);
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
	//�ȼ���
	char *netBuf = msgtool::g_packetBuf;
	uint32 headSize = sizeof(NetMsgHead);

	memcpy(netBuf + headSize + EncryptHeadLen, data, len);

	uint8* decryptBuf = (uint8*)(netBuf + headSize);
	int decryptBufLen = len + EncryptHeadLen + EncryptTailLen;//��Ӽӽ���ͷβ

	encrypttool::encrypt(decryptBuf, decryptBufLen, m_encryptKey, sizeof(m_encryptKey));
	len = decryptBufLen; //��Ӽӽ���ͷβ

	NetMsgHead* pHeader = (NetMsgHead*)netBuf;

	int packetLen = msgtool::buildNetHeader(pHeader, msgId, len);
	m_link->send(netBuf, packetLen);

	return true;
}
