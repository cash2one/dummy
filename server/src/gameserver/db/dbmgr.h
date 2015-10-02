///<------------------------------------------------------------------------------
//< @file:   gameserver\db\dbmgr.h
//< @author: ������
//< @date:   2015��3��27�� 17:21:26
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbmgr_h_
#define _dbmgr_h_

#include "tool/timetool.h"

class DBFactory;
class DBSession;

class DBMgr
{
public:
	DBMgr()
		: m_gamedb(NULL)
		, m_logdb(NULL)
		, m_old(0)
	{
	}

	bool init();

	void run();

	void stop();

	void test();

private:
	DBFactory *m_gamedb;
	DBFactory *m_logdb;

private:
	Timestamp m_old;
};

#endif //_dbmgr_h_