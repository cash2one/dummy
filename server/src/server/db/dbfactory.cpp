///<------------------------------------------------------------------------------
//< @file:   server\db\dbfactory.cpp
//< @author: ������
//< @date:   2015��3��26�� 20:1:14
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "dbfactory.h"

#include "db.h"
#include "dbsession.h"

DBSession* DBFactory::createDBSession(DBAccount &account, int minPoolSize, int maxPoolSize)
{
	DBSession *dbsession = new DBSession;
	if (false == dbsession->init(account, minPoolSize, maxPoolSize)) {
		delete dbsession;
		return NULL;
	}

	m_dbsessions.push_back(dbsession);
	return dbsession;
}

void DBFactory::close()
{
	LOG_WARN << "closing db ...";

	for (size_t i = 0; i < m_dbsessions.size(); ++i) {
		DBSession *dbsession = m_dbsessions[i];
		dbsession->stop();
		delete dbsession;
	}

	m_dbsessions.clear();
	LOG_WARN << "close db successfully!";
}

void DBFactory::del(DBSession *delsession)
{
	for (size_t i = 0; i < m_dbsessions.size(); ++i) {
		DBSession *session = m_dbsessions[i];

		if (session == delsession) {
			m_dbsessions[i] = m_dbsessions.back();
			m_dbsessions.pop_back();

			break;
		}
	}

	delete delsession;
}
