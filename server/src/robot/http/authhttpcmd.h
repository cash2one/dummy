///<------------------------------------------------------------------------------
//< @file:   robot\http\authhttpcmd.h
//< @author: ������
//< @date:   2015��6��12�� 19:31:37
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _authhttpcmd_h_
#define _authhttpcmd_h_

#include <http/httpcmd.h>
class Robot;

class AuthHttpCmd : public HttpCmd
{
private:
	virtual bool init();

	virtual void onExecuted();

private:
	Robot *m_robot;
};

#endif //_authhttpcmd_h_