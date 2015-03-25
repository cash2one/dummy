///<------------------------------------------------------------------------------
//< @file:   server\net\session.h
//< @author: ������
//< @date:   2015��3��14�� 23:51:18
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _session_h_
#define _session_h_

// �Ự����������
class ISession
{
public:
	virtual void onEstablish() = 0;

	virtual void onTerminate() = 0;

	virtual void onRecv(Link&, Buffer&) = 0;

	virtual void setLink(Link&) = 0;
};

// �Ự������ר�����ڴ����Ự
class ISessionFactory
{
public:
	virtual ISession* createSession(Link&) = 0;
};

#endif //_session_h_