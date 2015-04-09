///<------------------------------------------------------------------------------
//< @file:   logic\fly\flypropmgr.h
//< @author: hongkunan
//< @date:   2014��8��27�� 19:49:46
//< @brief:  ��������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _flypropmgr_h_
#define _flypropmgr_h_

#include "logic/base/singleton.h"
#include "logic/base/basepropmgr.h"
#include "logic/fly/flydef.h"

// ��������
struct SFlyProp
{
    SFlyProp(){ Clear(); }
    void Clear(){ wFlyRequiredJingjieLevel = 0; byEquipMakeBuyMaterialVipLvl = 0; byFlyAttrPromote = 0; fFlyAttrPromoteCoef = 0.0f; }

    UINT16 wFlyRequiredJingjieLevel;    // ���辳��ȼ�
    UINT8 byFlyAttrPromote;             // ������������������ٷֱȣ�50����50%
    float fFlyAttrPromoteCoef;          // �����������������ϵ�� = (1 + �����ٷֱ�) / 100
    UINT8 byEquipMakeBuyMaterialVipLvl; // װ�����������������vip�ȼ�
    
    UINT8 bySellEnchantStonePercent;    // �۳���ħװ��ʱ�����ĸ�ħʯ�ٷֱȣ�50����50%
    float fSellEnchantStonePercent;     // �۳���ħװ��ʱ�����ĸ�ħʯ�ٷֱ�
};

// ��������
class CFlyPropMgr
    : public Singleton<CFlyPropMgr>
    , public CBasePopMgr
{
public:
    ///< @impl >
    BOOL ReLoadProp(){ return TRUE; }

    EConfigModule GetConfigModuleType() { return ECM_FLY; }

    BOOL Init();
    VOID UnInit(){}

    const SFlyProp& GetFlyProp(){ return m_stFlyProp; }

private:
    BOOL LoadFlyProp();

private:
    SFlyProp m_stFlyProp;
};

#endif //_flypropmgr_h_