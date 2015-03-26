///<------------------------------------------------------------------------------
//< @file:   gateserver\net\gamesvrlink.cpp
//< @author: ������
//< @date:   2015��3��9�� 16:14:33
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "gamesvrlink.h"

#include <net/netaddress.h>
#include <net/link.h>
#include <basic/taskqueue.h>
#include <protocol/message.h>

#include <server.h>

void GameSvrLink::OnRecv(Link *link, Buffer &buf)
{
	ServerLink::OnRecv(link, buf);
}
