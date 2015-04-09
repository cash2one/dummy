///<------------------------------------------------------------------------------
//< @file:   medal\nonetime\blackroomdrivemedal.cpp
//< @author: Kang_zhiquan
//< @date:   2014��6��27�� 10:59:13
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------
#include "logic/medal/nonetime/blackroomdrivemedal.h"
#include "logic/medal/playermedal.h"
BOOL CBlackRoomDriveMedal::CheckActivate()
{
	return FALSE;
	if ( m_stMedalData.byIsActivate)
	{
		return TRUE;
	}

	const SMedalProp* poMedalProp = NULL;
	if ( !GetProp(poMedalProp))
	{
		return FALSE;
	}
	CPlayerMedal* poPlayerMedal = m_poOwner->GetPlayerMedal();
	if(NULL == poPlayerMedal)
	{
		return FALSE;
	}
	if ( (poMedalProp->qwFirstCondition <= poPlayerMedal->GetDT_MEDAL_BASE_DATA().dwDriveNum) && (poPlayerMedal->GetDT_MEDAL_BASE_DATA().dwDriveNum <= poMedalProp->qwSecondCondition))
	{
		return TRUE;
	}

	return FALSE;
}