///<------------------------------------------------------------------------------
//< @file:   server\basic\timerqueue.h
//< @author: ������
//< @date:   2015��1��25�� 19:3:59
//< @brief:	 ��ʱ��
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _timerqueue_h_
#define _timerqueue_h_

#include <queue>

#include "tool/timetool.h"
#include "basic/taskqueue.h"

#define FOREVER_ALIVE -1

class TimerQueue;

// �����Ķ�ʱ��
class Timer
{
	friend class TimerQueue;

public:
	Timer()
		: m_interval(0)
		, m_life(0)
		, m_at(0)
	{

	}

	virtual ~Timer() {}

public:
	virtual void run() = 0;

	void cancel()
	{
		m_life = 0;
	}

public:
	// �ݼ�����ʱ����ʣ����������
	void gotoDead()
	{
		// �������ʱ���ѱ�����Ϊ���޴�������
		if(m_life == FOREVER_ALIVE) {
			return;
		}

		--m_life;

		if (m_life < 0) {
			m_life = 0;
		}
	}

	bool operator<(const Timer& rhs) const
	{
		return m_at < rhs.m_at;
	}
	bool operator==(const Timer& rhs) const
	{
		return m_at == rhs.m_at;
	}
	bool operator>(const Timer& rhs) const
	{
		return m_at > rhs.m_at;
	}

public:
	// �������
	Timestamp m_interval;

	// ʣ�������������ÿ����������1�δ���������Ϊ-1ʱ��ʾ����ʱ�������޴���ʱ������
	int m_life;

private:
	// ����ʱ���Ĵ���ʱ��
	Timestamp m_at;
};

// ����ʱ��������ʱ������ʱ��ִ��Ԥ�ȴ洢��Task
class TaskTimer : public Timer
{
public:
	TaskTimer(const Task &task)
		: m_task(task)
	{
	}

	virtual void run()
	{
		m_task.run();
	}

private:
	Task m_task;
};

// ��ʱ����������
class TimerQueue
{
public:
	// ���ص�ǰ�������һ����ʱ����ʱ�����룩��û�ж�ʱ���򷵻�-1
	int run();

	// ָ����xx��xxСʱxx��ʱ�����ִ��
	void runAt(Timer*, Timestamp clock);

	// ��ʱһ��ʱ��ִ��task����
	void runAfter(const Task&, TimeInMs delay);

	// ��ʱһ��ʱ��ִ��task����
	void runAfter(Timer*, TimeInMs delay);

	// ÿ��interval����ִ��һ�Σ�ֱ��ִ����ָ���������ս�
	void runEvery(Timer*, TimeInMs interval, int times/* �������� */);

	// ÿ��interval����ִ��һ�Σ������ս�
	void runEvery(Timer*, TimeInMs interval);

	int size() { return m_timers.size(); }

private:
	struct cmp {
		bool operator() ( Timer* a, Timer* b )
		{
			return *a > *b;
		}
	};

private:
	typedef std::priority_queue<Timer*, std::vector<Timer*>, cmp> TimerPriorityQueue;

	// ��ʱ��
	TimerPriorityQueue m_timers;
};

#endif //_timerqueue_h_