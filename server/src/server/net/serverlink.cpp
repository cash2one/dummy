///<------------------------------------------------------------------------------
//< @file:   server\net\serverlink.cpp
//< @author: ������
//< @date:   2015��3��9�� 11:44:44
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "serverlink.h"
#include "server.h"

void ServerLink::onDisconnect(Link *link, const NetAddress& localAddr, const NetAddress& peerAddr)
{
	int svrId = Server::instance->getServerId(m_remoteSvrType, m_svrId);
	Server::instance->eraseSvrLink(svrId);

	Server::instance->onDisconnect(link, localAddr, peerAddr);
	Server::instance->onDisconnectServer(*link, m_remoteSvrType, m_svrId);

	if (link->m_isCreateByConnector) {
		Server::instance->m_lan.connect(peerAddr.toIp(), peerAddr.toPort(), *Server::instance);
	}
}

void ServerLink::onRecv(Link *link, Buffer &buf)
{
	Server::instance->onRecv(link, buf);
}
