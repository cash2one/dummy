///<------------------------------------------------------------------------------
//< @file:   tick_tool.h
//< @author: ������
//< @date:   2014��9��20�� 11:46:18
//< @brief:  
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _ticktool_h_
#define _ticktool_h_

#include "type.h"
#include <iostream>
#include <string>

typedef uint64 Tick;
namespace ticktool
{
    Tick get_tick();

    // ��������ʱ�����ڵĺ����
    uint32_t tick_diff(Tick old_tick);
}

class tick_t
{
public:
    tick_t(const char* msg)
        : m_msg(msg)
    {
        start_tick();
    }

    ~tick_t()
    {
        std::cout << m_msg << " = " << end_tick() << std::endl;
    }


    void start_tick()
    {
        m_tick = ticktool::get_tick();
    }

    // ������
    double end_tick();

private:
    Tick m_tick;
    std::string m_msg;
};

#endif //_ticktool_h_