///<------------------------------------------------------------------------------
//< @file:   server\tool\servertool.cpp
//< @author: ������
//< @date:   2015��3��10�� 14:50:47
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "servertool.h"

namespace svrtool
{
	static string g_svrName[eServerTypeMax] = {
		"UnknownServer",
		"GameServer",
		"GateServer"
	};

	string& getSvrName(ServerType svrType)
	{
		if (svrType < 0 || svrType >= eServerTypeMax) {
			svrType = eNullServer;
		}

		return g_svrName[svrType];
	}
}
