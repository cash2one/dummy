///<------------------------------------------------------------------------------
//< @file:   robot\http\robothttpmgr.h
//< @author: ������
//< @date:   2015��6��11�� 22:50:37
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _robothttpmgr_h_
#define _robothttpmgr_h_

#include <http/httpmgr.h>

class RobotHttpMgr : public Singleton<RobotHttpMgr>, public HttpMgr
{

};

#endif //_robothttpmgr_h_