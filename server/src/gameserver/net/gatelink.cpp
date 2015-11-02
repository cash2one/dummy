///<------------------------------------------------------------------------------
//< @file:   gameserver\net\gatelink.cpp
//< @author: ������
//< @date:   2015��3��8�� 21:15:50
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "gatelink.h"

#include <net/netaddress.h>
#include <net/link.h>

#include <server.h>
#include <protocol/message.h>

#include "logic/clientmgr.h"

void GateLink::OnRecv(Link *link, Buffer &buf)
{
	while(true) {
		// ����ͷ����
		size_t bytes = buf.readableBytes();
		if (bytes < sizeof(LanMsgHead)) {
			return;
		}

		LanMsgHead *msgHead	= (LanMsgHead*)buf.peek();
		uint32 clientId		= endiantool::networkToHost(msgHead->clientId);
		uint16 msgId			= endiantool::networkToHost(msgHead->msgId);
		uint32 dataLen			= endiantool::networkToHost(msgHead->msgLen);

		// �����
		if (dataLen > bytes) {
			// 			LOG_WARN << "gatesvr [" << link->m_localAddr.toIpPort() << "] <-> client [" << link->m_peerAddr.toIpPort()
			// 			          << "] msgLen(" << msgLen << ") > bytes(" << bytes << ")";
			return;
		}

		char *msg		= (char*)buf.peek() + sizeof(LanMsgHead);
		uint32 msgLen	= dataLen - sizeof(LanMsgHead);

		Client *client = ClientMgr::Instance().FindClient(clientId);
		if (NULL == client) {
			return;
		}

		// ֱ�ӱ��ؽ��д���
		Buffer deepCopyBuf;
		deepCopyBuf.append(msg, msgLen);
		Server::instance->getTaskQueue().put(boost::bind(&ClientMgr::handleMsg, &ClientMgr::Instance(), *client, msgId, deepCopyBuf, 0));

		buf.skip(dataLen);
	};
}
