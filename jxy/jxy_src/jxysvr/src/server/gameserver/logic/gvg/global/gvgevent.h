///<------------------------------------------------------------------------------
//< @file:   gvgevent.h
//< @author: hongkunan
//< @date:   2014��1��16�� 22:22:54
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgevent_h_
#define _gvgevent_h_

#include "eventreactor.h"

using namespace SGDP;

class CGvGEvent: public CEvent
{
public:
    CGvGEvent(){}
    virtual ~CGvGEvent(){}

    virtual UINT32 OnEvent();
    virtual BOOL OnDestroy(){ return TRUE; }

public:
    UINT32	GetInterval();
};

// gvg���ػ���ʱ����ÿ��һ��ʱ�佫�ƶ����ֿ��ս�Ľ���
class CGvGReloadPropEvent : public CEvent
{
public:
    CGvGReloadPropEvent(){}
    virtual ~CGvGReloadPropEvent(){}

    virtual UINT32 OnEvent();
    virtual BOOL OnDestroy(){ return TRUE; }

public:
    UINT32	GetInterval();
};

class CGvGRePullEvent : public CEvent
{
public:
    CGvGRePullEvent(){}
    virtual ~CGvGRePullEvent(){}

    virtual UINT32 OnEvent();
    virtual BOOL OnDestroy(){ return TRUE; }

public:
    // ��λ:��
    UINT32 GetInterval();
};

#endif //_gvgevent_h_