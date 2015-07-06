///<------------------------------------------------------------------------------
//< @file:   robot\http\handshakehttpcmd.cpp
//< @author: ������
//< @date:   2015��6��12�� 12:22:47
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "handshakehttpcmd.h"
#include "robot.h"
#include <tool/echotool.h>

bool HandShakeHttpCmd::init()
{
	m_url = "http://127.0.0.1/phpinfo.php";

	m_fields =
	    "time=" + std::string(echotool::getmsg("%u", timetool::FormatNow())) +
	    "&deviceid=" + m_robot->m_deviceid +
	    "&ip=" + m_robot->m_ip;

	m_fields = "";

	// m_url = signUrl(HTTP_URL_SIGN);
	return true;
}


void HandShakeHttpCmd::onExecuted()
{
	m_robot->m_publickey = "MAGSKMNA2jNNF";
	m_robot->auth();
}
