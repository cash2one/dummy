///<------------------------------------------------------------------------------
//< @file:   server\db\dbfactory.h
//< @author: ������
//< @date:   2015��3��26�� 20:3:29
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbfactory_h_
#define _dbfactory_h_

#include "db.h"
#include "basic/lock.h"
#include "basic/thread.h"

class DBSession;
class DBConnection;
struct DBAccount;

// db���������࣬ά����һ�����ݿ�������Ķ������
class DBFactory : public Singleton<DBFactory>
{
public:
	DBFactory();

	DBSession* createDBSession(DBAccount&, int minPoolSize = 1, int maxPoolSize = 1);

	void close();

	void del(DBSession*);

public:
	std::string name();

	bool init(const DBAccount &dbaccount);

	// ���������ַ���ת��Ϊ���ݿ��ʶ�����0��β���ַ���
	bool escape(const char *pSrc, int nSrcSize, char *pDest, int nDstSize);

	DB::DBExecuteCode execute(const char *sql, uint32 strlen = 0, uint64 *pInsertId = NULL, uint32* pEffectRowNum = NULL);

	DB::DBQueryCode query(const char *sql, DBRecordSet **pRes);

	// ִ���������ʵ��ִ�е�������
	uint32 run(uint32 loopcnt);

	// ����������ݿ��߳�ִ�е�run����
	void threadrun();

	void addDBCommand(DBCommand*);

	DBConnection* getConnection(int groupId);

	void recycle(DBConnection*);

	void stop();

private:
	void executeCmd(DBCommand*);

	DBConnection* connect();

	DBConnection* borrow();

	DBConnection* onUsed(DBConnection*);

	//ɾ����ConnectionMap�е�һ������
	void removeConnFromMap(DBConnection*);


public:
	DBAccount m_dbaccount;

private:
	typedef std::vector<DBCommand*> DBCommandList;
	typedef tr1::unordered_map<int /* ��Id */, DBConnection*> ConnectionMap; // ���Id <-> ����
	typedef tr1::unordered_set<DBConnection*> ConnectionPool;

	friend class DBFactory;

	DBCommandList m_cmdList;
	DBCommandList m_executedCmdList;

	mutex_t m_cmdLock;
	mutex_t m_executedCmdLock;
	mutex_t m_poolLock;
	mutex_t m_mapLock;
	condition_var_t m_cmdCondition;

	volatile bool m_running;

	int m_minPoolSize;
	int m_maxPoolSize;

	ConnectionPool m_connPool;
	ConnectionMap m_connMap;

	volatile int m_connCount;

	Thread m_dbthread;

private:
	typedef std::vector<DBSession*> DBSessions;
	DBSessions m_dbsessions;
};

#endif //_dbfactory_h_