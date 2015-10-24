#ifndef _dbserver_h_
#define _dbserver_h_


#include "server.h"
#include "config/dbconfig.h"

class GateLink;
class DBMgr;

class DBServer : public Singleton<DBServer>, public Server
{
public:
	DBServer();

	bool init(const char* jsonConfig);

	void start();

	virtual void stoppping();

	void run();

	virtual ServerLink* onAcceptServer(Link&, ServerType, int serverId);

	virtual void onDisconnectServer(Link&, ServerType, int serverId);

private:
	// �������ģ������������з�������ͨ��
	NetFactory m_lan;

	DBMgr *m_dbmgr;

	DBConfig m_config;

private:
	// ����Ϸ��������
	ServerLink* m_gameLink;
};


#endif