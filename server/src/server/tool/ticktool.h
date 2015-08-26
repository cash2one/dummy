///<------------------------------------------------------------------------------
//< @file:   server\tool\ticktool.h
//< @author: ������
//< @date:   2015��3��27�� 21:42:31
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _ticktool_h_
#define _ticktool_h_

#include "log/log.h"

namespace ticktool
{
	uint64 tick();

	// ��������ʱ�����ڵ����
	double tickDiff(uint64 old_tick);
}

class Tick
{
public:
	Tick(const char* msg)
		: m_msg(msg)
	{
		LOG_WARN << "------- start " << m_msg << std::endl;
		startTick();
	}

	~Tick()
	{
		LOG_WARN << "------ end " << m_msg << " , cost time = " << endTick() << std::endl;
	}

	// ��ʼ��ʱ
	void startTick();

	// ������
	double endTick();

private:
	uint64 m_tick;
	std::string m_msg;
};


#endif //_ticktool_h_