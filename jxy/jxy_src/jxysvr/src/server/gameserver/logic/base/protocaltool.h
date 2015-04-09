///<------------------------------------------------------------------------------
//< @file:   protocaltool.h
//< @author: yewenhui
//< @date:   2014��6��13�� 15��20��
//< @brief:  Э�鹤�� ��Ҫ�ǳ������Э��ͬ������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------
#pragma once
#ifndef _PROTOCAL_TOOL_H_
#define _PROTOCAL_TOOL_H_
#include "sdtype.h"
#include "protocol/server/protocligs.h"

class CPlayer;

namespace ProtocalTool
{
	VOID		FillBagItemData(CPlayer* pPlayer, UINT32 unItemId, DT_BAG_ITEM_INFO& rBagItemInfo);
	VOID		FillPetModuleRes(CPlayer* pPlayer, DT_PLAYER_RES_LST_DATA& rResLstData);

}

#endif // _PROTOCAL_TOOL_H_
