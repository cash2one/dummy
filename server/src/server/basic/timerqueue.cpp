///<------------------------------------------------------------------------------
//< @file:   server\basic\timerqueue.cpp
//< @author: ������
//< @date:   2015��1��25�� 19:4:12
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "timerqueue.h"

int TimerQueue::run()
{
	if(m_timers.empty()) {
		return -1;
	}

	// ��ȡ��ǰʱ��
	Timestamp now = timetool::getTimeOfDay();

	// ����ȡ�����ѵ��ڵĶ�ʱ����ִ��
	while(!m_timers.empty()) {
		Timer &timer = *m_timers.top();
		if(timer.m_at > now) {
			return (int)(timer.m_at - now);
		}

		m_timers.pop();

		timer.run();
		timer.gotoDead();

		if(timer.isAlive()) {
			timer.m_at = now + timer.m_interval;
			m_timers.push(&timer);
		} else {
			delete &timer;
		}
	}

	return -1;
}

void TimerQueue::runAt(Timer *pTask, Timestamp at)
{
	pTask->m_at = at;
	m_timers.push(pTask);
}

void TimerQueue::runAfter(const Task &task, TimeInMs delay)
{
	TaskTimer *taskTimer = new TaskTimer(task);
	runAfter(taskTimer, delay);
}

void TimerQueue::runEvery(const Task &task, TimeInMs interval)
{
	TaskTimer *taskTimer = new TaskTimer(task);
	runEvery(taskTimer, interval);
}

void TimerQueue::runAfter(Timer *pTask, TimeInMs delay)
{
	Timestamp now = timetool::getTimeOfDay();
	pTask->m_life = 1;
	runAt(pTask, now + delay);
}

void TimerQueue::runEvery(Timer *pTask, TimeInMs interval, int times/* �������� */)
{
	runAfter(pTask, interval);
	pTask->m_life = times;
}

void TimerQueue::runEvery(Timer *pTask, TimeInMs interval)
{
	runAfter(pTask, interval);
	pTask->m_life = FOREVER_ALIVE;
	pTask->m_interval = interval;
}