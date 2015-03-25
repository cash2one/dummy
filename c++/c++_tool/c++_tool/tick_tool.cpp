///<------------------------------------------------------------------------------
//< @file:   ticktool.cpp
//< @author: ������
//< @date:   2014��9��20�� 11:46:36
//< @brief:  
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#include "tick_tool.h"

#include <windows.h>

namespace ticktool
{
    // ��ȡCPUÿ��ĵδ����
    Tick GetTickFrequency()
    {
        static LARGE_INTEGER static_perfFreq = {0};
        if(0 == static_perfFreq.QuadPart){
            QueryPerformanceFrequency(&static_perfFreq); 
        }

        return static_perfFreq.QuadPart;
    }

    Tick get_tick()
    {
        LARGE_INTEGER tick;

        QueryPerformanceCounter(&tick);
        return tick.QuadPart;
    }

    uint32_t tick_diff(Tick old_tick)
    {
        Tick tick_now = get_tick();

        uint32_t ms = (uint32_t)((tick_now - old_tick) * 1000 / GetTickFrequency());
        return ms;
    }
}

// ������
double tick_t::end_tick()
{
    Tick tick_now = ticktool::get_tick();
    Tick diff = tick_now - m_tick;

    // uint32_t ms = (double)((tick_now - old_tick) * 1000 / GetTickFrequency());

    double passed_sec = (double)diff / ticktool::GetTickFrequency();
    return passed_sec;
}