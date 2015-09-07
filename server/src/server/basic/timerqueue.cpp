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
		Timer &task = *m_timers.top();
		if(task.m_at > now) {
			return (int)(task.m_at - now);
		}

		m_timers.pop();

		task.run();
		task.gotoDead();

		if(task.m_life != 0) {
			task.m_at = now + task.m_interval;
			m_timers.push(&task);
		} else {
			delete &task;
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

void TimerQueue::runAfter(Timer *pTask, TimeInMs delay)
{
	Timestamp now = timetool::getTimeOfDay();
	pTask->m_life = 1;
	runAt(pTask, now + delay);
}

void TimerQueue::runEvery(Timer *pTask, TimeInMs interval, int times/* �������� */)
{
	pTask->m_life = times;
	runAfter(pTask, interval);
}

void TimerQueue::runEvery(Timer *pTask, TimeInMs interval)
{
	pTask->m_life = -1;
	runAfter(pTask, interval);
}