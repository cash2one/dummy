///<------------------------------------------------------------------------------
//< @file:   gspipechannel.h
//< @author: hongkunan
//< @date:   2014��1��2�� 20:18:55
//< @brief:  ���ս��������gameserver������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gspipechannel_h_
#define _gspipechannel_h_

#include <sdframework.h>

// ��gameserver������
class CGSPipeChannel : public CSDPipeChannel
{
    //@impl
    virtual VOID OnEstablish();
};

#endif //_gspipechannel_h_