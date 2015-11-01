///<------------------------------------------------------------------------------
//< @file:   gateserver\net\userlink.h
//< @author: ������
//< @date:   2015��3��14�� 20:14:51
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _userlink_h_
#define _userlink_h_

#include <net/netdefine.h>
#include <net/serverlink.h>

class Link;
class NetAddress;

class UserLink : public INetLogic
{
	virtual void OnDisconnect(Link*, const NetAddress& localAddr, const NetAddress& peerAddr);

	virtual void OnRecv(Link*);

	virtual TaskQueue& GetTaskQueue();
};


#endif //_userlink_h_