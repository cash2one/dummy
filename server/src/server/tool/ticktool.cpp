///<------------------------------------------------------------------------------
//< @file:   server\tool\ticktool.cpp
//< @author: ������
//< @date:   2015��3��27�� 21:43:37
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "ticktool.h"

namespace ticktool
{
	// ��ȡCPUÿ��ĵδ����
	uint64 GetTickFrequency()
	{
		static LARGE_INTEGER static_perfFreq = {0};
		if(0 == static_perfFreq.QuadPart) {
			QueryPerformanceFrequency(&static_perfFreq);
		}

		return static_perfFreq.QuadPart;
	}

	uint64 tick()
	{
		LARGE_INTEGER tick;

		QueryPerformanceCounter(&tick);
		return tick.QuadPart;
	}

	uint32 tickDiff(uint64 old_tick)
	{
		uint64 tick_now = tick();

		uint32 ms = (uint32)((tick_now - old_tick) * 1000 / GetTickFrequency());
		return ms;
	}
}

void Tick::startTick()
{
	m_tick = ticktool::tick();
}


// ������
double Tick::endTick()
{
	uint64 tick_now = ticktool::tick();
	uint64 diff = tick_now - m_tick;

	// uint32_t ms = (double)((tick_now - old_tick) * 1000 / GetTickFrequency());

	double passed_sec = (double)diff / ticktool::GetTickFrequency();
	return passed_sec;
}