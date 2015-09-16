///<------------------------------------------------------------------------------
//< @file:   src\gateserver\gateserver.h
//< @author: ������
//< @date:   2015��3��9�� 16:11:49
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gateserver_h_
#define _gateserver_h_

#include "server.h"
#include "net/clientmgr.h"
#include "config/gateconfig.h"

class GameSvrLink;

class GateServer : public Singleton<GateServer>, public Server
{
public:
	GateServer();

	bool init(const char* jsonConfig);

	void start();

	virtual void stopping();

	virtual void run();

	// ���յ��µķ���������
	virtual ServerLink* onAcceptServer(Link&, ServerType, int serverId);

	// ��������Ͽ�����
	virtual void onDisconnectServer(Link&, ServerType, int serverId);

public:
	void sendToGameServer(uint32 clientId, uint16 msgId, const char* data, uint32 len);

private:
	// �������ģ����������������ӣ��磺����ҵ�����
	NetFactory m_wan;

	// ����Ϸ��������
	GameSvrLink *m_gamesvrLink;

	// �ͻ��˹�������
	ClientMgr m_clientMgr;

	// ��������
	GateConfig m_config;
};

#endif //_gateserver_h_