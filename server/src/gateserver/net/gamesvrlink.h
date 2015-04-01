///<------------------------------------------------------------------------------
//< @file:   gateserver\net\gamesvrlink.h
//< @author: ������
//< @date:   2015��3��9�� 16:14:42
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gamesvrlink_h_
#define _gamesvrlink_h_

#include <net/netreactor.h>
#include <net/serverlink.h>

class Link;
class NetAddress;
class Buffer;

class GameSvrLink : public ServerLink
{
	virtual void onRecv(Link*, Buffer &buf);
};

#endif //_gamesvrlink_h_