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
}

class Tick
{
public:
	Tick(const char* msg)
		: m_msg(msg)
	{
		startTick();
	}

	~Tick()
	{
		LOG_WARN << m_msg << " = " << endTick() << std::endl;
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