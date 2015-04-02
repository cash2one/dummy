///<------------------------------------------------------------------------------
//< @file:   server\basic\timerqueue.h
//< @author: ������
//< @date:   2015��1��25�� 19:3:59
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _timerqueue_h_
#define _timerqueue_h_

#include <queue>

#include "tool/timetool.h"
#include "basic/taskqueue.h"

class TimerQueue;

class Timer
{
	friend class TimerQueue;

public:
	Timer()
		: m_interval(0)
		, m_life(0)
		, m_expired(0)
	{

	}

public:
	virtual void run() = 0;

	void cancel()
	{
		m_life = 0;
	}

public:
	void gotoDead()
	{
		--m_life;
	}

	bool operator<(const Timer& rhs) const
	{
		return m_expired < rhs.m_expired;
	}
	bool operator==(const Timer& rhs) const
	{
		return m_expired == rhs.m_expired;
	}
	bool operator>(const Timer& rhs) const
	{
		return m_expired > rhs.m_expired;
	}

public:
	Timestamp m_interval;
	int m_life; // ʣ�����������

private:
	Timestamp m_expired;
};

// �ö�ʱ��ʱ�䵽ʱ��ִ��ָ���ĺ���
class TaskTimer : public Timer
{
public:
	TaskTimer(const task_t &task)
		: m_task(task)
	{
	}

	virtual void run()
	{
		m_task.run();
	}

private:
	task_t m_task;
};

class TimerQueue
{
public:
	static Timestamp cachedNow;

public:
	void run();

	// ָ����xx��xxСʱxx��ʱ�����ִ��
	void runAt(Timer*, Timestamp clock);

	// ��ʱһ��ʱ��ִ��task����
	void runAfter(const task_t&, TimeInMs delay);

	// ��ʱһ��ʱ��ִ��task����
	void runAfter(Timer*, TimeInMs delay);

	// ÿ��interval����ִ��һ�Σ�ֱ��ִ����ָ���������ս�
	void runEvery(Timer*, TimeInMs interval, int times/* �������� */);

	// ÿ��interval����ִ��һ�Σ������ս�
	void runEvery(Timer*, TimeInMs interval);

private:
	struct cmp {
		bool operator() ( Timer* a, Timer* b )
		{
			return *a > *b;
		}
	};

private:
	typedef std::priority_queue<Timer*, std::vector<Timer*>, cmp> TaskPriorityQueue;
	TaskPriorityQueue m_taskqueue;
};

#endif //_timerqueue_h_