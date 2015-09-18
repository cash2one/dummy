///<------------------------------------------------------------------------------
//< @file:   src\robot\main.cpp
//< @author: ������
//< @date:   2015��3��16�� 11:11:8
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "robotmgr.h"

int main(int argc, char **argv)
{
	RobotMgr &robotMgr = RobotMgr::Instance();
	robotMgr.init("../robotconfig.json");
	robotMgr.start();
	return 0;
}