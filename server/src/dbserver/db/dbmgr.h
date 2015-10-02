///<------------------------------------------------------------------------------
//< @file:   dbserver\db\dbmgr.h
//< @author: ������
//< @date:   2015��9��29�� 17:21:26
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbmgr_h_
#define _dbmgr_h_

#include <basic/singleton.h>

class DBFactory;
class DBSession;
struct DBConfig;

class DBMgr : public Singleton<DBMgr>
{
public:
	DBMgr()
		: m_gamedb(NULL)
		, m_logdb(NULL)
	{
	}

	bool init(DBConfig&);

	void run();

	void stop();

	void test();

public:
	std::vector<std::string> m_sqls;

	DBFactory *m_gamedb;
	DBFactory *m_logdb;
};

#endif //_dbmgr_h_