///<------------------------------------------------------------------------------
//< @file:   medal\nonetime\playerviplevel.h
//< @author: Kang_zhiquan
//< @date:   2014��6��25�� 17:11:48
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _playerviplevelmedal_h_
#define _playerviplevelmedal_h_
#include "logic/medal/medal.h"

class CPlayerVipLevelMedal : public CNoneTimeMedal
{
public:
	virtual BOOL CheckActivate();
};
#endif //_playerviplevel_h_