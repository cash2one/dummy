///<------------------------------------------------------------------------------
//< @file:   pkpipechannel.cpp
//< @author: hongkunan
//< @date:   2014��1��3�� 13:52:23
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "pkpipechannel.h"

#include "logic/gvg/local/gvgbuild.h"

void CPKPipeChannel::OnEstablish()
{
    CGvGBuild::Instance()->SendGetGvGActivityReq();
}
