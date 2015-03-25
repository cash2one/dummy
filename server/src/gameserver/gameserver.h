///<------------------------------------------------------------------------------
//< @file:   src\gameserver\gameserver.h
//< @author: ������
//< @date:   2015��3��2�� 21:11:31
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gameserver_h_
#define _gameserver_h_

#include "server.h"

class GateLink;

class GameServer : public Singleton<GameServer>, public Server
{
public:
	GameServer();

	bool init();

	void start();

	void run();

	virtual ServerLink* OnAcceptServer(Link&, ServerType, int serverId);

	virtual void OnDisconnectServer(Link&, ServerType, int serverId);

private:
	GateLink *m_gateLink;
};

#endif //_gameserver_h_