///<------------------------------------------------------------------------------
//< @file:   server\basic\thread.h
//< @author: ������
//< @date:   2015��1��13�� 17:40:25
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _thread_h_
#define _thread_h_

#include "taskqueue.h"

// �߳��ࣺ�ɹ�����ϵͳ�߳�
class Thread
{
#ifdef WIN
	typedef vector<HANDLE> ThreadIdList;
#else
	typedef list<pthread_t> ThreadIdList;
#endif

public:
#ifdef WIN
	static unsigned int __stdcall run(void* p);
#else
	static void* run(void* p);
#endif


	inline void yield()
	{
#if defined(WIN)
		Sleep(0);
#else
		sched_yield();
#endif
	}

public:
	// ����num���̣߳�ÿ���߳�һ������ִ�д��������
	int createThread(Task task, int num);

	// �ȴ�ֱ�������߳��˳�
	int join();

private:
	// ���е�ϵͳ�߳�id�б�
	ThreadIdList m_tidList;
};

#endif //_thread_h_