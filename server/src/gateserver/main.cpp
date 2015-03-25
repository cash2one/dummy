///<------------------------------------------------------------------------------
//< @file:   src\gateserver\main.cpp
//< @author: ������
//< @date:   2015��3��9�� 16:9:38
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "gateserver.h"

int main(int argc, char **argv)
{
	GateServer &svr = GateServer::Instance();
	if (!svr.init()) {
		svr.uninit();
		return 0;
	}

	svr.start();
	return 0;
}