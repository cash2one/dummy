///<------------------------------------------------------------------------------
//< @file:   gameserver\logic\clientmgr.cpp
//< @author: ������
//< @date:   2015��6��10�� 22:36:32
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "clientmgr.h"
#include "net/clientmsghandler.h"

ClientMgr::ClientMgr()
{
	m_dispatcher.addMsgHandler(new ClientMsgHandler(&m_dispatcher));
}

Client* ClientMgr::FindClient(uint32 playerId)
{
	ClientMap::iterator itr = m_clients.find(playerId);
	if (itr == m_clients.end()) {
		return NULL;
	}

	return itr->second;
}

void ClientMgr::handleMsg(Client &client, uint16 msgId, Buffer&, Timestamp receiveTime)
{

}
