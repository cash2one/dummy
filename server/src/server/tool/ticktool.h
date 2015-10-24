///<------------------------------------------------------------------------------
//< @file:   server\tool\ticktool.h
//< @author: ������
//< @date:   2015��3��27�� 21:42:31
//< @brief:	 ʱ�����ڹ���
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _ticktool_h_
#define _ticktool_h_

#include "log/log.h"

namespace ticktool
{
	// ����ʱ������
	uint64 tick();

	// ��������ʱ�����ڵ����
	double tickDiff(uint64 old_tick);
}

// ��ʱ�������ڲ���ʱ��ķ�
class Tick
{
public:
	Tick(const char* jobText, int jobCnt = 0)
		: m_jobText(jobText)
		, m_jobCnt(jobCnt)
		, m_born(0)
		, m_retickNum(0)
		, m_historyMax(0)
	{
		// LOG_WARN << "------- start " << m_msg << std::endl;
		startTick();

		m_born = m_tick;
	}

	~Tick()
	{
		if (1 == m_retickNum) {
			print(m_jobCnt);
		} else {
			printHistoryMax();
		}
	}

	// ��ʼ��ʱ
	void startTick();

	// ������ʱ�������ص�ǰʱ�����ʱ����ʱ����λ����
	double endTick();

	// ���ر���ʱ�����������ڵ�ʱ�䣬��λ����
	double life();

	// ��ӡ��ǰ���ʱ����ʱ��ƽ��ÿ�κ�ʱ��ƽ��ÿ��ִ�д���
	void print(int jobCnt, const char *text = "")
	{
		if (jobCnt <= 0) {
			jobCnt = 1;
		}

		m_jobCnt += jobCnt;

		double costTime = endTick();

		double speed = costTime / jobCnt;
		double per = 1.0f / speed;

		LOG_WARN << "------ " << m_jobText << text << " jobcnt = " << m_jobCnt << ", cost time = " << costTime << ", avg cost = " << speed << ", per second = " << per << "" << std::endl;

		if (m_historyMax < per) {
			m_historyMax = per;
		}
	}

	// ��ӡ����ʷ��ߵ�ÿ��ִ�д���
	void printHistoryMax()
	{
		double lifetime = ticktool::tickDiff(m_born);
		double speed = lifetime / m_jobCnt;

		double avg = 1.0f / speed;

		LOG_WARN << "------ " << m_jobText << " avg per second = " << avg << ", history max excute per second = " << m_historyMax;
	}

public:
	// ����ʱ������ҵע��
	std::string m_jobText;

private:
	// ����ʱ���ĳ���ʱ��
	uint64 m_born;

	// ��ʱ��㣬��ʱ�������ֶ�����
	uint64 m_tick;

	// ��ʷ�����ﵽ�������ÿ��ִ�д���
	double m_historyMax;

	// ��ʷִ�й�����ҵ��
	int m_jobCnt;

	// ���¼�ʱ����
	int m_retickNum;
};


#endif //_ticktool_h_