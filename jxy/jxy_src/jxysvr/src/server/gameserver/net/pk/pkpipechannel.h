///<------------------------------------------------------------------------------
//< @file:   pkpipechannel.h
//< @author: hongkunan
//< @date:   2014��1��3�� 13:52:8
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pkpipechannel_h_
#define _pkpipechannel_h_

#include <dll/sdframework/sdpipechannel.h>

// ��Ϸ���������е�����ս������������
class CPKPipeChannel:public CSDPipeChannel
{
protected:
    ///<@impl>
    virtual void OnEstablish();
};

#endif //_pkpipechannel_h_