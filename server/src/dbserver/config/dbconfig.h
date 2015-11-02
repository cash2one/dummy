///<------------------------------------------------------------------------------
//< @file:   dbconfig.h
//< @author: ������
//< @date:   2015��11��2��
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbconfig_h_
#define _dbconfig_h_

#include <db/db.h>

struct IpPort {
	IpPort()
		: port(0)
	{}

	std::string ip;
	int port;
};

struct DBConfig {
	DBConfig()
		: m_lanThreadNum(0)
	{}

	bool load(const char* configFile);

	std::vector<IpPort> m_lanListens;
	int m_lanThreadNum;

	DBAccount m_gamedbAccnt;
	DBAccount m_logdbAccnt;
};

#endif // _dbconfig_h_