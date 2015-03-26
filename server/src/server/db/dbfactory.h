///<------------------------------------------------------------------------------
//< @file:   server\db\dbfactory.h
//< @author: ������
//< @date:   2015��3��26�� 20:3:29
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbfactory_h_
#define _dbfactory_h_

class DBSession;
class DBConnection;
struct DBAccount;

class DBFactory
{
	DBSession* createDBSession(DBAccount&);

	DBConnection* createDBConnection(DBAccount&);
};

#endif //_dbfactory_h_