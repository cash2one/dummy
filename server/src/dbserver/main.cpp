///<------------------------------------------------------------------------------
//< @file:   src\dbserver\main.cpp
//< @author: ������
//< @date:   2015��9��29�� 14:14:4
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "dbserver.h"

int main(int argc, char **argv)
{
	DBServer &svr = DBServer::Instance();
	if (!svr.init("../dbconfig.json")) {
		svr.uninit();
		return 0;
	}

	svr.start();
	return 0;
}