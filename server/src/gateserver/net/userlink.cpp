///<------------------------------------------------------------------------------
//< @file:   gateserver\net\userlink.cpp
//< @author: ������
//< @date:   2015��3��14�� 20:14:56
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "userlink.h"

#include "server.h"

void UserLink::OnDisconnect(Link*, const NetAddress& localAddr, const NetAddress& peerAddr)
{

}

void UserLink::OnRecv(Link *link)
{

}

TaskQueue& UserLink::GetTaskQueue()
{
	return Server::instance->getTaskQueue();
}