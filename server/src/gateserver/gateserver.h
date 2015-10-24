///<------------------------------------------------------------------------------
//< @file:   src\gateserver\gateserver.h
//< @author: ������
//< @date:   2015��3��9�� 16:11:49
//< @brief:	 ���ط�����
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gateserver_h_
#define _gateserver_h_

#include "server.h"
#include "net/clientmgr.h"
#include "config/gateconfig.h"

class GameSvrLink;

// ���ط�����������䵱��Һ���Ϸ������ת����������·�ɹ��ܣ����������Ϣ�����мӽ���
class GateServer : public Singleton<GateServer>, public Server
{
public:
	GateServer();

	// �������ó�ʼ�����ط�����
	bool init(const char* jsonConfig);

	// �������ط�����
	void start();

	// ���շ�������Դ
	virtual void stopping();

	// ÿ�η�����ѭ����ִ�е�����
	virtual void run();

	// ���յ��µķ���������
	virtual ServerLink* onAcceptServer(Link&, ServerType, int serverId);

	// ��������Ͽ�����
	virtual void onDisconnectServer(Link&, ServerType, int serverId);

public:
	// ��ָ����ҵ���Ϣ������Ϸ��
	void sendToGameServer(uint32 clientId, uint16 msgId, const char* data, uint32 len);

private:
	// ����ͨ�����ģ���������������ͨ�ţ��磺������ҵ�����
	NetFactory m_wan;

	// ����Ϸ��������
	GameSvrLink *m_gamesvrLink;

	// �ͻ��˹�������
	ClientMgr m_clientMgr;

	// ��������
	GateConfig m_config;
};

#endif //_gateserver_h_