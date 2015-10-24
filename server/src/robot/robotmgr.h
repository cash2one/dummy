///<------------------------------------------------------------------------------
//< @file:   src\robot\robotmgr.h
//< @author: ������
//< @date:   2015��3��16�� 11:43:59
//< @brief:  ����������
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _robotmgr_h_
#define _robotmgr_h_

#include <net/netreactor.h>
#include <basic/taskqueue.h>
#include <net/msgdispatcher.h>
#include <net/netfactory.h>

#include "http/robothttpmgr.h"
#include "robot.h"
#include "robotconfig.h"

// �����˹�����
class RobotMgr : public Singleton<RobotMgr>
{
	typedef tr1::unordered_map<uint32, Robot*> RobotMap;

public:
	RobotMgr()
		: m_allocRobotId(0)
		, m_run(false)
	{
	}

	virtual std::string name() { return string("robotmgr"); }

public:
	bool init(const char* jsonConfig);

	bool uninit();

	void start();

	void creareRobots();

	// ִֹͣ�У�������һ��ֹͣ����Ͷ���������
	void stop();

	// ִ������ֹͣ����
	void stopping();

	// ÿ����Ϸѭ����ִ�еĲ���
	void run();

	void onRobotDisconnect(Robot*);

	Robot* createRobot();

private:
	uint32 allocRobotId() { return ++m_allocRobotId; }

public:
	// �������
	TaskQueue m_taskQueue;

	// ��ʱ������
	TimerQueue m_timers;

	// <�Ƿ�������>��־λ
	bool m_run;

	// ���еĻ�����id
	uint32 m_allocRobotId;

	// �������б�
	RobotMap m_robotMap;

	// ��Ϣ�ɷ���
	MsgDispatcher<Robot> m_dispatcher;

	// �����������
	NetFactory m_wan;

	// http��������
	RobotHttpMgr m_httpMgr;

	// ����������
	RobotConfig m_config;
};

#endif //_robotmgr_h_