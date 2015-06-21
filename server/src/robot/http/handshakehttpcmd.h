///<------------------------------------------------------------------------------
//< @file:   robot\http\handshakehttpcmd.h
//< @author: ������
//< @date:   2015��6��12�� 11:51:36
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _handshakehttpcmd_h_
#define _handshakehttpcmd_h_

#include <http/httpcmd.h>

class Robot;

// ��������
class HandShakeHttpCmd : public HttpCmd
{
private:
	virtual bool init();

	virtual void onExecuted();

private:
	Robot *m_robot;
};

#endif //_handshakehttpcmd_h_