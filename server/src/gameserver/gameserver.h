///<------------------------------------------------------------------------------
//< @file:   src\gameserver\gameserver.h
//< @author: ������
//< @date:   2015��3��2�� 21:11:31
//< @brief:	 ��Ϸ������
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gameserver_h_
#define _gameserver_h_

#include "server.h"

#include "logic/clientmgr.h"
#include "net/http/gamehttpmgr.h"
#include "config/gameconfig.h"

#include "db/dbagent.h"

class GateLink;

// ��Ϸ������: ����������Ϸ�߼�
class GameServer : public Singleton<GameServer>, public Server
{
public:
	GameServer();

	bool init(const char* jsonConfig);

	void start();

	virtual void stoppping();

	void run();

	virtual ServerLink* onAcceptServer(Link&, ServerType, int serverId);

	virtual void onDisconnectServer(Link&, ServerType, int serverId);

	// ������Ϣ��db������
	bool sendToDBServer(uint16 msgId, Message&);

private:
	GateLink *m_gateLink;
	ServerLink *m_dbLink;

	ClientMgr m_clientMgr;
	GameHttpMgr m_httpMgr;

	// ��Ϸ����������
	GameConfig m_config;

	DbAgent m_gamedb;
	DbAgent m_logdb;
};

#endif //_gameserver_h_