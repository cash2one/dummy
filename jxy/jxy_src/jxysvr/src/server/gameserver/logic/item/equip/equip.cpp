#include "equip.h"
#include "equippropmgr.h"
#include <logic/item/equip/strengthenpropmgr.h>
#include <logic/player/player.h>
#include <common/client/commondef.h>
#include <common/client/errdef.h>
#include <logic/hero/hero.h>
#include <logic/item/itemcomposepropmgr.h>
#include "dll/sdu/sdtime.h"
#include <db/autosqlbuf.h>
#include "logic/record/recordmgr.h"
#include <logic/other/xiangqianmgr.h>
#include <logic/lua/luamgr.h>
#include <logic/base/basedefine.h>
#include <logic/other/singleprammgr.h>
#include <logic/other/fewparam.h>
#include <logic/task/taskmgr.h>
#include "logic/battle/battlemgr.h"
#include <logic/bag/bag.h>
#include "logic/fly/flydef.h"
#include "logic/fly/flypropmgr.h"
#include <dll/sdframework/sdloggerimpl.h>
#include <utility.h>

static const UINT8 gs_byUpMaxLevel = 10;

CEquip::CEquip()
    : m_wEnchantLevel(0)
{
    memset(&m_stDT_EQUIP_DATA, 0, sizeof(m_stDT_EQUIP_DATA));
    memset(&m_stBattleAttribute, 0, sizeof(m_stBattleAttribute));

    m_poHero = NULL;
}


CEquip::~CEquip()
{

}


BOOL CEquip::Init(VOID* pData, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }

    SEquipProperty *pstEquipProperty = (SEquipProperty*)(pData);

    SEquipProp* pstEquipProp =  CEquipPropMgr::Instance()->GetProp(pstEquipProperty->pstEquip->wKindID);
    if(NULL == pstEquipProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: pstEquipProp is NULL,KindID[%d]!"), MSG_MARK, pstEquipProperty->pstEquip->wKindID);
        return FALSE;
    }

    m_stDT_EQUIP_DATA = *pstEquipProperty->pstEquip;
    m_wEnchantLevel = pstEquipProperty->wEnchantLevel;

    if(!pstEquipProp->bIsLegendEquip){
        m_wEnchantLevel = 0;
    }

    m_poOwner = poOwner;
    InitBattleAttribute();
    return TRUE;
}

VOID CEquip::InitBattleAttribute()
{
    memset(&m_stBattleAttribute, 0, sizeof(m_stBattleAttribute));

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return ;
    }

    //���ݵȼ���������
    m_stBattleAttribute = CalcAttrByLevel(m_stDT_EQUIP_DATA.wLevel, m_wEnchantLevel, pstEquipProp);

    //�����佫��ս������
    if(m_poHero)
    {
        m_poHero->InitBattleAttribute();
    }
}

DT_BATTLE_ATTRIBUTE	CEquip::BattleAttCountByLevel(UINT16 wLevel, UINT16 wEnchantLevel, SEquipProp* pstEquipProp)
{
    DT_BATTLE_ATTRIBUTE2 stAttrWithDenfend = CalcAttrByLevel(wLevel, wEnchantLevel, pstEquipProp);
    DT_BATTLE_ATTRIBUTE stDT_BATTLE_ATTRIBUTE = CBattleMgr::Instance()->NewToOldBattleAttribute(stAttrWithDenfend);

    return stDT_BATTLE_ATTRIBUTE;
}

DT_BATTLE_ATTRIBUTE2 CEquip::CalcAttrByLevel(UINT16 wLevel, UINT16 wEnchantLevel/* ��ħ�ȼ� */, SEquipProp* pstEquipProp)
{
    DT_BATTLE_ATTRIBUTE2 stAttr;
    memset(&stAttr, 0, sizeof(stAttr));

    if(NULL == pstEquipProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: pstEquipProp is NULL!"), MSG_MARK);
        return stAttr;
    }

    stAttr.dwHP = pstEquipProp->dwHP;
    stAttr.dwAttack = pstEquipProp->dwAttack;
    stAttr.dwDefend = pstEquipProp->dwDefend;

    stAttr.dwHP += pstEquipProp->wStrengthenHPPerLvl * wLevel + pstEquipProp->wEnchantHPPerLvl * wEnchantLevel;
    stAttr.dwAttack += pstEquipProp->wStrengthenAttackPerLvl * wLevel + pstEquipProp->wEnchantAttackPerLvl * wEnchantLevel;
    stAttr.dwDefend += pstEquipProp->wEnchantDefendPerLvl * wEnchantLevel;

    return stAttr;
}

VOID CEquip::SetHero(CHero* poHero)
{
    m_poHero = poHero;
    if(NULL == m_poHero)
    {
        m_stDT_EQUIP_DATA.wHeroKindID = 0;
    }
    else
    {
        m_stDT_EQUIP_DATA.wHeroKindID = m_poHero->GetDT_HERO_BASE_DATA().wKindID;
    }

    //SetSaveState(ESS_WANT_SAVE);
}

INT16 CEquip::Strengthen(UINT8 byStrengthenType, UINT16 wLevel)
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        RETURN_OTHER_ERR;
    }


    CBuild* poBuild = m_poOwner->GetBuild(EBK_SMITHY);
    if(NULL == poBuild)
    {
        return ERR_STRENGTHEN::ID_BUILD_NOT_EXIST_ERR;
    }
    else
    {
        //�ﵽ��ǰ���ǿ������
        if(m_stDT_EQUIP_DATA.wLevel >= m_poOwner->GetLevel()){
            return ERR_STRENGTHEN::ID_CANNT_OVER_PLAYER_LEVEL_ERR;
        }

        if (m_stDT_EQUIP_DATA.wLevel >= FLY_LEVEL){
            return ERR_STRENGTHEN::ID_CANNT_OVER_LEVEL_120;
        }
    }

    //�ж�CD
    DT_FEW_PARAM_DATA& stDT_FEW_PARAM_DATA = m_poOwner->GetFewParam().GetDT_FEW_PARAM_DATA();
    UINT64 qwPassTime = SDTimeSecs() - stDT_FEW_PARAM_DATA.qwLastStrengthenTime;
    if(qwPassTime >= (UINT64)stDT_FEW_PARAM_DATA.wLastStrengthenCD)
    {
        stDT_FEW_PARAM_DATA.wLastStrengthenCD = 0;
    }
    else
    {
        stDT_FEW_PARAM_DATA.wLastStrengthenCD -= (UINT16)qwPassTime;
    }
    stDT_FEW_PARAM_DATA.qwLastStrengthenTime = SDTimeSecs();//

    if(stDT_FEW_PARAM_DATA.wLastStrengthenCD > CEquipStrengthenPropMgr::Instance()->GetTotalCD())
    {
        return ERR_STRENGTHEN::ID_IN_CD;
    }

    UINT16 wErrCode = ERR_STRENGTHEN::ID_SUCCESS;

	//��ָ��Ϊ��ǰ�ȼ�+gs_byUpMaxLevel��Ϊ����ǿ��gs_byUpMaxLevel��
    if((wLevel == m_stDT_EQUIP_DATA.wLevel + gs_byUpMaxLevel) || (wLevel > CSinglePramMgr::Instance()->GetMaxPlayerLevel()))
	{
		wLevel = 0;
	}
	UINT8 byUpLevel = 1;
	if(0 == wLevel) //0��ʾֱ������gs_byUpMaxLevel��
	{
		if(m_stDT_EQUIP_DATA.wLevel + gs_byUpMaxLevel > m_poOwner->GetLevel())
		{
			return ERR_STRENGTHEN::ID_CANNT_OVER_PLAYER_LEVEL_ERR;
		}

        if(m_stDT_EQUIP_DATA.wLevel + gs_byUpMaxLevel > FLY_LEVEL){
            return ERR_STRENGTHEN::ID_CANNT_OVER_LEVEL_120;
        }

		byUpLevel = gs_byUpMaxLevel;
	}	
    else if(wLevel <= m_stDT_EQUIP_DATA.wLevel)
    {
        wErrCode = ERR_STRENGTHEN::ID_SUCCESS;
    }
    else if(wLevel == m_stDT_EQUIP_DATA.wLevel + 1)
    {
        if(wLevel > FLY_LEVEL){
            return ERR_STRENGTHEN::ID_CANNT_OVER_LEVEL_120;
        }

		byUpLevel = 1;
	}
	else
	{
		wErrCode = ERR_STRENGTHEN::ID_LEVEL_ERR;
	}
        
	UINT32 dwCost = 0; //δ������ǿ�����
    //���ǿ������
    if(!m_poOwner->CKGuide( EGF_STRENGTHEN))
    {
        //Ŀǰֻ��ͭ��ǿ��
		dwCost = GetUpLevelCoin(m_stDT_EQUIP_DATA.wLevel, byUpLevel, pstEquipProp->wDressLevel, m_poOwner->GetLevel());    
    }

    if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin < dwCost)
    {
        return ERR_COMMON::ID_COIN_NOT_ENOUGH;
    }

    //��Ǯ������
    m_poOwner->DecCoin(dwCost, CRecordMgr::EDCT_STRENGTHEN, m_stDT_EQUIP_DATA.wHeroKindID, m_stDT_EQUIP_DATA.wKindID, m_stDT_EQUIP_DATA.wLevel + 1 );
    m_stDT_EQUIP_DATA.wLevel += byUpLevel;
    

    if(ERR_STRENGTHEN::ID_SUCCESS == wErrCode)
    {
        stDT_FEW_PARAM_DATA.wLastStrengthenCD += CEquipStrengthenPropMgr::Instance()->GetCD(pstEquipProp->wDressLevel, pstEquipProp->byEquipColor);
        InitBattleAttribute();

        //�����������
        m_poOwner->ResetBattleAttr();

        CTaskMgr::Instance()->OnStrengthenEquip(m_poOwner, m_stDT_EQUIP_DATA.wKindID);

        //��¼ǿ������
        m_poOwner->AddGuideRecord( EGF_STRENGTHEN);
    }

    return wErrCode;
}

INT16 CEquip::Enchant(UINT16 wTargetEnchantLevel)
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp){
        RETURN_OTHER_ERR;
    }

    CBuild* poBuild = m_poOwner->GetBuild(EBK_ENCHANT);
    if(NULL == poBuild){
        return ERR_ENCHANT::ID_IS_UNOPEN;
    }

    if(!m_poOwner->IsFly() || m_poOwner->GetLevel() <= FLY_LEVEL){
        return ERR_ENCHANT::ID_NOT_FLY;
    }

    if (wTargetEnchantLevel <= m_wEnchantLevel){
        return ERR_ENCHANT::ID_SUCCESS;
    }

    if (wTargetEnchantLevel != m_wEnchantLevel + 1){
        return ERR_ENCHANT::ID_LEVEL_ERR;
    }

    if (FLY_LEVEL + wTargetEnchantLevel > m_poOwner->GetLevel()){
        return ERR_ENCHANT::ID_CANNOT_GREATER_THAN_PLAYER_LV;
    }

    // ���⴫װ���޷���ħ
    if (!pstEquipProp->bIsLegendEquip){
        return ERR_ENCHANT::ID_NOT_FLY_EQUIP;
    }

    // ��ǿ���ȼ� < 120ʱ����ħ���� = ǿ���ȼ�����/2
    // ��ǿ���ȼ� = 120ʱ����ħ����û������
    // ��ħ�ȼ��Ǹ���ת���ȼ� 1��1 ������ ����1�����ܸ�ħ1�Ρ�
    if (m_stDT_EQUIP_DATA.wLevel < FLY_LEVEL && wTargetEnchantLevel > m_stDT_EQUIP_DATA.wLevel / 2){
        return ERR_ENCHANT::ID_STRENGTHEN_LV_NOT_ENOUGH;
    }

    CBag &oBag = m_poOwner->GetBag();

    DT_EQUIP_ENCHANT_DATA_CLI stEnchantCli;
    memset(&stEnchantCli, 0, sizeof(stEnchantCli));

    GetDT_EQUIP_DATA_ENCHANT_CLI(stEnchantCli);

    // ���踽ħʯ
    if (stEnchantCli.wCurEnchantStone < stEnchantCli.wCostEnchantStone){
        return ERR_ENCHANT::ID_ENCHANT_STONE_NOT_ENOUGH;
    }

    if (!oBag.DelGoodItem(stEnchantCli.wEnchantStoneID, stEnchantCli.wCostEnchantStone)){
        return ERR_ENCHANT::ID_ENCHANT_STONE_NOT_ENOUGH;
    }
    
    m_wEnchantLevel = wTargetEnchantLevel;

    InitBattleAttribute();
    m_poOwner->ResetBattleAttr();    
    return ERR_ENCHANT::ID_SUCCESS;
}

BOOL CEquip::CanBeEnchant()
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp){
        return FALSE;
    }

    if (!pstEquipProp->bIsLegendEquip){
        return FALSE;
    }

    UINT16 wEnchantLevel = GetEnchantLevel();
    if (wEnchantLevel + FLY_LEVEL >= m_poOwner->GetLevel()){
        return FALSE;
    }

    // ��ǿ���ȼ� < 120ʱ����ħ���� = ǿ���ȼ�����/2
    // ��ǿ���ȼ� = 120ʱ����ħ����û������
    // ��ħ�ȼ��Ǹ���ת���ȼ� 1��1 ������ ����1�����ܸ�ħ1�Ρ�
    if (m_stDT_EQUIP_DATA.wLevel < FLY_LEVEL && wEnchantLevel >= m_stDT_EQUIP_DATA.wLevel / 2){
        return FALSE;
    }

    return TRUE;
}

BOOL CEquip::Xiangqian( UINT16 wItemID, UINT8 byPos )
{
    m_stDT_EQUIP_DATA.astXiangqianList[byPos].wItemID = wItemID;

    if( m_poHero )
    {
        m_poHero->InitBattleAttribute();
    }


    CGoods *pGoods = m_poOwner->GetBag().GetGoodsItem( wItemID );
    m_poOwner->ReduceItem( pGoods, CRecordMgr::EDIT_XIANGQIAN );
    m_poOwner->AddGuideRecord( EGF_XIANGQIAN);
    return TRUE;
}

UINT32 CEquip::GetStrengthenCost(UINT8 byStrengthenType, UINT16 wLevel)
{
    if(0 == wLevel)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: level 0 !"), MSG_MARK);
        return 0xFFFFFFFF;
    }

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return 0xFFFFFFFF;
    }

    UINT32 dwCost = 0xFFFFFFFF;
    switch(byStrengthenType)
    {
    case EQUIP_STRENGTHEN_COIN:
    {
        dwCost = CEquipStrengthenPropMgr::Instance()->GetStrengthenCoin(wLevel, pstEquipProp->wDressLevel);
    }
    break;
    //case EQUIP_STRENGTHEN_GOID:
    //{
    //    dwCost = CEquipStrengthenPropMgr::Instance()->GetStrengthenGold(wLevel, pstEquipProp->byEquipColor);
    //}
    break;
    default:
        break;
    }

    return dwCost;
}

UINT16 CEquip::GetEnchantCostStone(UINT16 wEnchantLevel)
{
    const UINT16 MAX_ENCHANT_STONE = 0xFFFF;

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp){
        return MAX_ENCHANT_STONE;
    }

    UINT16 dwCost = (UINT16)CEquipStrengthenPropMgr::Instance()->GetEnchantStone(wEnchantLevel + 1, pstEquipProp->wDressLevel);
    return dwCost;
}

UINT16 CEquip::GetEnchantStoneID(UINT16 wEnchantLevel)
{
    UINT16 wStoneID = CEquipStrengthenPropMgr::Instance()->GetEnchantStoneID(wEnchantLevel + 1);
    return wStoneID;
}

UINT32 CEquip::GetRecoverPrice()
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return 0x00;
    }


    if(0 == m_stDT_EQUIP_DATA.wLevel)
    {
        return pstEquipProp->dwRecoverPrice;
    }

    UINT32 dwStrengthenCost = CEquipStrengthenPropMgr::Instance()->GetAllStrengthenCoin(m_stDT_EQUIP_DATA.wLevel, pstEquipProp->wDressLevel);
    return pstEquipProp->dwRecoverPrice + UINT32(dwStrengthenCost * 0.85);
}

void	CEquip::GetRecoverScience(UINT32 & dwMinScience, UINT32 & dwMaxScience)//��������
{
    UINT32	dwScience = 0;
    SEquipProp* pstEquipProp =  GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return ;
    }


    //@ 2013-05-08 ȥ�����Ļظ�ǿ���ȼ����
    //װ������=��װ���۳���Ǯ��װ��������ʼ��Ǯ��/500+װ��������ʼ����
    //UINT32	dwRecoverPrice = GetRecoverPrice();
    //if(dwRecoverPrice > pstEquipProp->dwRecoverPrice)
    //{
    //    dwScience = (dwRecoverPrice - pstEquipProp->dwRecoverPrice) / 500;
    //}
    //dwScience += pstEquipProp->dwScience;
    //�ĳɸ�ǿ���ȼ���أ����ٸ�����ͭǮ��ء�
    dwScience = m_stDT_EQUIP_DATA.wLevel * pstEquipProp->dwStrengthenScience;
    dwScience += pstEquipProp->dwScience;
    //@ end

    dwMinScience = (UINT32)(dwScience * 0.5);
    dwMaxScience = (UINT32)(dwScience * 1.5);

    return ;
}


VOID	CEquip::GetRecoverScience(UINT16 wKindID, UINT32 & dwMinScience, UINT32 & dwMaxScience)//��������
{
	UINT32	dwScience = 0;
	SEquipProp* pstEquipProp =  CEquipPropMgr::Instance()->GetProp(wKindID);
	if(NULL == pstEquipProp)
	{
		return ;
	}


	//@ 2013-05-08 ȥ�����Ļظ�ǿ���ȼ����
	//װ������=��װ���۳���Ǯ��װ��������ʼ��Ǯ��/500+װ��������ʼ����
	//UINT32	dwRecoverPrice = GetRecoverPrice();
	//if(dwRecoverPrice > pstEquipProp->dwRecoverPrice)
	//{
	//    dwScience = (dwRecoverPrice - pstEquipProp->dwRecoverPrice) / 500;
	//}
	//dwScience += pstEquipProp->dwScience;
	//�ĳɸ�ǿ���ȼ���أ����ٸ�����ͭǮ��ء�
	//dwScience = 0 * pstEquipProp->dwStrengthenScience;
	dwScience += pstEquipProp->dwScience;
	//@ end

	dwMinScience = (UINT32)(dwScience * 0.5);
	dwMaxScience = (UINT32)(dwScience * 1.5);

	return ;
}

//UINT32	CEquip::GetRecoverScience()//��������
//{
//	UINT32	dwScience = 0;
//	SEquipProp* pstEquipProp =  GetEquipProp();
//	if(NULL == pstEquipProp)
//	{
//		return 0x00;
//	}
//
//	//װ������=��װ���۳���Ǯ��װ��������ʼ��Ǯ��/500+װ��������ʼ����
//	UINT32	dwRecoverPrice = GetRecoverPrice();
//	if(dwRecoverPrice > pstEquipProp->dwRecoverPrice)
//	{
//		dwScience = (dwRecoverPrice - pstEquipProp->dwRecoverPrice) / 500;
//	}
//	dwScience += pstEquipProp->dwScience;
//	return dwScience;
//}

//��ȡ��װ������������װ���ȼ�
UINT16 CEquip::GetUpgradeDressLevel()
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return 0;
    }

    SEquipProp* pstProp = CEquipPropMgr::Instance()->GetProp(pstEquipProp->wUpgradeToEquipID);
    if(pstProp)
    {
        return pstProp->wDressLevel;
    }

    return 0;
}

//��ȡװ��ս������
VOID CEquip::GetBattleAttribute(DT_BATTLE_ATTRIBUTE& stBattleAttr)
{
    DT_BATTLE_ATTRIBUTE2 stBattleAttr2;
    GetBattleAttribute2(stBattleAttr2);

    stBattleAttr = CBattleMgr::Instance()->NewToOldBattleAttribute(stBattleAttr2);
}

VOID CEquip::GetBattleAttribute2(DT_BATTLE_ATTRIBUTE2& stBattleAttr)
{
    memset(&stBattleAttr, 0, sizeof(DT_BATTLE_ATTRIBUTE));

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return ;
    }

    stBattleAttr = CalcAttrByLevel(m_stDT_EQUIP_DATA.wLevel, m_wEnchantLevel, pstEquipProp);
}

VOID CEquip::GetBasicAttr(DT_BATTLE_ATTRIBUTE2& stBasicAttr)
{
    memset(&stBasicAttr, 0, sizeof(stBasicAttr));

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return;
    }

    stBasicAttr.dwHP = pstEquipProp->dwHP;
    stBasicAttr.dwAttack = pstEquipProp->dwAttack;
}

VOID CEquip::GetAttrAddByStrengthen(DT_BATTLE_ATTRIBUTE2& stAddAttr)
{
    memset(&stAddAttr, 0, sizeof(stAddAttr));

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return;
    }

    UINT16 wLevel = m_stDT_EQUIP_DATA.wLevel;
    stAddAttr.dwHP += (pstEquipProp->wStrengthenHPPerLvl * wLevel);
    stAddAttr.dwAttack += (pstEquipProp->wStrengthenAttackPerLvl * wLevel);
}

VOID CEquip::GetAttrAddByEnchant(DT_BATTLE_ATTRIBUTE2& stAddAttr)
{
    memset(&stAddAttr, 0, sizeof(stAddAttr));

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return;
    }

    stAddAttr.dwHP += (pstEquipProp->wStrengthenHPPerLvl * m_wEnchantLevel);
    stAddAttr.dwAttack += (pstEquipProp->wStrengthenAttackPerLvl * m_wEnchantLevel);
}

//��ȡװ����һ����ս������
VOID CEquip::GetNextLevelBattleAttr(DT_BATTLE_ATTRIBUTE& stBattleAttribute)
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return;
    }

    memset(&stBattleAttribute, 0, sizeof(DT_BATTLE_ATTRIBUTE));

    stBattleAttribute = BattleAttCountByLevel(m_stDT_EQUIP_DATA.wLevel + 1, m_wEnchantLevel, pstEquipProp);
}

VOID CEquip::GetNextEnchantLevelBattleAttr(DT_BATTLE_ATTRIBUTE2& stBattleAttribute)
{
    memset(&stBattleAttribute, 0, sizeof(stBattleAttribute));

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return;
    }

    stBattleAttribute = CalcAttrByLevel(m_stDT_EQUIP_DATA.wLevel, m_wEnchantLevel + 1, pstEquipProp);
}

//��ȡǿ����Ϣ
VOID CEquip::GetStrengthenInfo(UINT8& byCanStrengthenFlag, UINT32& dwStrengthenCoin, UINT32& dwStrengthenGold, UINT16& wStrengthenRate)
{
    byCanStrengthenFlag = 0;
    UINT16 wCanStrengthenLevel = 0;

    if(NULL == m_poOwner->GetBuild(EBK_SMITHY))
    {
        return ;
    }

    byCanStrengthenFlag = m_stDT_EQUIP_DATA.wLevel < m_poOwner->GetLevel() ? 1 : 0;

    dwStrengthenCoin = GetStrengthenCost(EQUIP_STRENGTHEN_COIN, m_stDT_EQUIP_DATA.wLevel + 1);
    dwStrengthenGold = GetStrengthenCost(EQUIP_STRENGTHEN_GOID, m_stDT_EQUIP_DATA.wLevel + 1);
    wStrengthenRate = 100;//ǿ���ɹ���,todo,
}

VOID CEquip::GetDT_EQUIP_DATA_CLI(DT_EQUIP_DATA_CLI& stDT_EQUIP_DATA_CLI)
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return;
    }

    stDT_EQUIP_DATA_CLI.wKindID = m_stDT_EQUIP_DATA.wKindID;
    stDT_EQUIP_DATA_CLI.wIdx = m_stDT_EQUIP_DATA.wIdx;
    stDT_EQUIP_DATA_CLI.wLevel = m_stDT_EQUIP_DATA.wLevel;
    stDT_EQUIP_DATA_CLI.byDressPos = pstEquipProp->byPosKindID;

    GetRecoverScience(stDT_EQUIP_DATA_CLI.dwMinScience, stDT_EQUIP_DATA_CLI.dwMaxScience);
    if(pstEquipProp)
    {
        stDT_EQUIP_DATA_CLI.wDressLevel = pstEquipProp->wDressLevel;
    }
    else
    {
        stDT_EQUIP_DATA_CLI.wDressLevel = 1;
    }

    //��ֵ��Ƕ����
    stDT_EQUIP_DATA_CLI.byXiangqianNum = CXiangqianMgr::Instance()->GetUnlockNum( stDT_EQUIP_DATA_CLI.wDressLevel );

    for( UINT32 dwIndex = 0; dwIndex < stDT_EQUIP_DATA_CLI.byXiangqianNum; ++dwIndex )
    {
        CXiangqianMgr::Instance()->GetAddValue( m_stDT_EQUIP_DATA.astXiangqianList[dwIndex].wItemID,
                                                stDT_EQUIP_DATA_CLI.astXiangqianList[dwIndex].dwAddValue,
                                                stDT_EQUIP_DATA_CLI.astXiangqianList[dwIndex].dwAddPercentValue,
                                                stDT_EQUIP_DATA_CLI.astXiangqianList[dwIndex].dwAttrType );

        stDT_EQUIP_DATA_CLI.astXiangqianList[dwIndex].wKindID = m_stDT_EQUIP_DATA.astXiangqianList[dwIndex].wItemID;
    }

    GetBattleAttribute(stDT_EQUIP_DATA_CLI.stBattleAttribute);
    stDT_EQUIP_DATA_CLI.dwRecoverPrice = GetRecoverPrice();
}

VOID CEquip::GetDT_EQUIP_DATA_CLI_with_enchant_lvl(DT_EQUIP_DATA_CLI& stEquipCli)
{
    GetDT_EQUIP_DATA_CLI(stEquipCli);

    // ����Ǹ�ħװ��������Ҫ��ʾ��ħ�ȼ�����DT_EQUIP_DATA_CLI�ֶ�û�취ֱ�ӼӸ�ħ�ȼ��ֶΣ�����ᵼ�ºܶ��õ�DT_EQUIP_DATA_CLI��Э���޷���С��v410�ͻ��˼���
    // ���ԣ�������һ�ֶ��ĵķ�����ʱ��������dwMinScience > 0��dwMaxScience = 0�Ļ�����dwMinScience����ħ�ȼ�
    if (GetEnchantLevel() > 0){
        stEquipCli.dwMinScience = GetEnchantLevel();
        stEquipCli.dwMaxScience = 0;
    }
}

VOID CEquip::GetDT_EQUIP_DATA_CLI_v410(DT_EQUIP_DATA_CLI_v410 &stEquipCli)
{
    GetDT_EQUIP_DATA_CLI(stEquipCli.stEquipData);

    GetBasicAttr(stEquipCli.stBasicAttr);
    GetAttrAddByStrengthen(stEquipCli.stStrengthenAttr);
    GetAttrAddByEnchant(stEquipCli.stEnchantAttr);

    stEquipCli.stTotalAttr = m_stBattleAttribute;
    stEquipCli.wEnchantLevel = m_wEnchantLevel;
}

VOID CEquip::GetDT_EQUIP_DATA_STRENGTHEN_CLI(DT_EQUIP_DATA_STRENGTHEN_CLI& stDT_EQUIP_DATA_CLI)
{
    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return ;
    }

    if(m_poHero)
    {
        stDT_EQUIP_DATA_CLI.wHeroKindID = m_poHero->GetDT_HERO_BASE_DATA().wKindID;
    }
    else
    {
        stDT_EQUIP_DATA_CLI.wHeroKindID = 0;
    }
    GetNextLevelBattleAttr(stDT_EQUIP_DATA_CLI.stNextBattleAttribute);
    GetStrengthenInfo(stDT_EQUIP_DATA_CLI.byCanStrengthenFlag, stDT_EQUIP_DATA_CLI.dwStrengthenCoin, stDT_EQUIP_DATA_CLI.dwStrengthenGold, stDT_EQUIP_DATA_CLI.wStrengthenRate);
}

VOID CEquip::GetDT_EQUIP_DATA_ENCHANT_CLI(DT_EQUIP_ENCHANT_DATA_CLI &stEnchantCli)
{
    if(NULL == m_poOwner->GetBuild(EBK_ENCHANT))
    {
        return ;
    }

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp)
    {
        return ;
    }

    stEnchantCli.wHeroKindID = (m_poHero ? m_poHero->GetDT_HERO_BASE_DATA().wKindID : 0);
    stEnchantCli.byCanEnchantFlag = pstEquipProp->bIsLegendEquip;
    if (!stEnchantCli.byCanEnchantFlag){
        return;
    }

    GetNextEnchantLevelBattleAttr(stEnchantCli.stNextBattleAttribute);

    stEnchantCli.wEnchantStoneID = GetEnchantStoneID(m_wEnchantLevel);
    stEnchantCli.wCurEnchantStone = m_poOwner->GetBag().GetGoodsPileNum(stEnchantCli.wEnchantStoneID);
    stEnchantCli.wCostEnchantStone = GetEnchantCostStone(m_wEnchantLevel);
}

VOID CEquip::GetDT_EQUIP_DATA_COMPOSE_CLI(DT_EQUIP_COMPOSE_DATA_CLI& stDT_EQUIP_DATA_CLI)//��ȡװ���ϳɵ���Ϣ
{
    SEquipProp* pstEquipProp = CEquipPropMgr::Instance()->GetProp(m_stDT_EQUIP_DATA.wKindID);
    if (NULL == pstEquipProp)
    {
        return;
    }

    SEquipProp* pstNewEquipProp = CEquipPropMgr::Instance()->GetProp(pstEquipProp->wUpgradeToEquipID);
    if (NULL == pstNewEquipProp)
    {
        return;
    }

    for (UINT8 i = 0; i < pstEquipProp->byComposeItemNum && i < MAX_COMPOSE_ITEM_NUM; i++)
    {
        //��ȡ�ϳ���Ʒ��Ϣ
        CItemComposePropMgr::Instance()->GetDT_NEED_ITEM_DATA(m_poOwner, stDT_EQUIP_DATA_CLI.astItemInfoList[i], m_stDT_EQUIP_DATA.wKindID, pstEquipProp->awComposeItem[i]);
        stDT_EQUIP_DATA_CLI.byItemNum++;
    }

    //��ȡ����װ����Ϣ
    //CEquipPropMgr::Instance()->GetDT_ESTIMATE_EQUIP_DATA(stDT_EQUIP_DATA_CLI.stEstimateEquip, pstEquipProp->wUpgradeToEquipID);

    stDT_EQUIP_DATA_CLI.stEstimateEquip.wKindID = pstNewEquipProp->wKindID;
    stDT_EQUIP_DATA_CLI.stEstimateEquip.wLevel = CEquipStrengthenPropMgr::Instance()->GetConvertLevel(m_stDT_EQUIP_DATA.wLevel, pstEquipProp->wDressLevel, pstNewEquipProp->wDressLevel);
    stDT_EQUIP_DATA_CLI.stEstimateEquip.wDressLevel = pstNewEquipProp->wDressLevel;
    stDT_EQUIP_DATA_CLI.stEstimateEquip.stBattleAttribute = CEquip::BattleAttCountByLevel(stDT_EQUIP_DATA_CLI.stEstimateEquip.wLevel, 0, pstNewEquipProp);
    stDT_EQUIP_DATA_CLI.dwSuccessGold = pstEquipProp->wUpgradeSuccessGold;
    stDT_EQUIP_DATA_CLI.bySuccessRate = static_cast<UINT8>(pstEquipProp->wUpgradeSuccessRate);
}


VOID CEquip::GetDT_ENEMY_EQUIP_DATA(DT_ENEMY_EQUIP_DATA& stDT_ENEMY_EQUIP_DATA)
{
    stDT_ENEMY_EQUIP_DATA.wKindID = m_stDT_EQUIP_DATA.wKindID;
    stDT_ENEMY_EQUIP_DATA.wLevel = m_stDT_EQUIP_DATA.wLevel;

    GetBattleAttribute(stDT_ENEMY_EQUIP_DATA.stBattleAttribute);
}

UINT16 CEquip::Sell(UINT16 wNum, DT_ITEM_NUM_DATA_LIST_CLI &stRecvItemNumList)
{
    if(NULL == m_poOwner)
    {
        RETURN_OTHER_ERR;
    }
    UINT32 dwRecoverCoin = GetRecoverPrice();
    if(0 == dwRecoverCoin){
        return ERR_SELL_ITEM::ID_SELL_PROHIBIT;
    }

    // ����Ǹ�ħװ�����򰴱������ظ�ħʯ
    if (GetEnchantLevel() > 0){
        EnchantStone2NumMap mapStone2Num = GetSellEnchantStone();
        if (mapStone2Num.empty()){
            return ERR_SELL_ITEM::ID_SELL_PROHIBIT;
        }

        CBag &oBag = m_poOwner->GetBag();

        UINT16 wNeedSpace = 0;
        for(EnchantStone2NumMap::iterator itr = mapStone2Num.begin(); itr != mapStone2Num.end(); ++itr){
            GoodsID wStoneID = itr->first;
            if (NULL == oBag.GetGoodsItem(wStoneID)){
                wNeedSpace++;
            }
        }

        if (oBag.GetIdleSize() < wNeedSpace){
            return ERR_SELL_ITEM::ID_BAG_FULL;
        }

        ECreateItemRet eRet = ECIR_SUCCESS;

        for(EnchantStone2NumMap::iterator itr = mapStone2Num.begin(); itr != mapStone2Num.end(); ++itr){
            GoodsID wStoneID = itr->first;
            UINT32 dwStoneNum = itr->second;

            CItemMgr::Instance()->CreateItemIntoBag(m_poOwner, wStoneID, dwStoneNum, eRet, 0, CRecordMgr::EAIT_SELL_ENCHANT_EQUIP);

            DT_ITEM_NUM_DATA_CLI &stItemNumCli = stRecvItemNumList.astItemList[stRecvItemNumList.wItemNum++];
            stItemNumCli.wItemID  = wStoneID;
            stItemNumCli.wItemIdx = 0;
            stItemNumCli.wItemNum = dwStoneNum;
        }
    }

    //��Ǯ
    m_poOwner->AddCoin(dwRecoverCoin, CRecordMgr::EACT_SELLEQUIP, m_stDT_EQUIP_DATA.wKindID, m_stDT_EQUIP_DATA.wLevel);

    //���
    m_poOwner->OnDeleteEquip(this);

    return ERR_SELL_ITEM::ID_SUCCESS;
}


UINT16	CEquip::Melt(UINT8 byGoldFlag)//����
{
    if(NULL == m_poOwner)
    {
        RETURN_OTHER_ERR;
    }

    UINT32	dwDisScience = 0;
    UINT32	dwMinScience = 0;
    UINT32	dwMaxScience = 0;
    GetRecoverScience(dwMinScience, dwMaxScience);

    if (dwMaxScience > dwMinScience)
    {
        dwDisScience = dwMaxScience - dwMinScience;
    }
    else
    {
        dwDisScience = 0;
    }

	UINT32	dwScience = 0;
	if(byGoldFlag)
	{
		dwScience = dwMaxScience;
	}
	else
	{
		//����ֵ�Ŵ�100������ֹ��С�����
		dwDisScience = dwDisScience * 100;
		//���ֳ��嵵
		dwDisScience = dwDisScience / 10;

		//�������ֵ
		CRandomVec vecRandom;
		vecRandom.push_back(10);
		vecRandom.push_back(20);
		vecRandom.push_back(40);
		vecRandom.push_back(20);
		vecRandom.push_back(10);

		//���
		INT32 nRandomHitIdx = GetRandomIdxMustHit(vecRandom);
		if(RANDOM_UNHIT == nRandomHitIdx)
		{
			RETURN_OTHER_ERR;
		}

		//�����ֵ
		UINT32 dwHitScience = 0;
		switch(nRandomHitIdx)
		{
		case 0:
			dwHitScience = SDRandom(dwDisScience);
			break;
		case 1:
			dwHitScience = dwDisScience + SDRandom(dwDisScience * 2);
			break;
		case 2:
			dwHitScience = 3 * dwDisScience + SDRandom(dwDisScience * 4);
			break;
		case 3:
			dwHitScience = 7 * dwDisScience + SDRandom(dwDisScience * 2);
			break;
		case 4:
			dwHitScience = 9 * dwDisScience + SDRandom(dwDisScience);
			break;
		default:
			break;
		}
		dwScience = dwHitScience / 100;
		dwScience += dwMinScience;
	}

    m_poOwner->AddScience(dwScience, CRecordMgr::EAST_MELT, m_stDT_EQUIP_DATA.wKindID, m_stDT_EQUIP_DATA.wIdx, m_stDT_EQUIP_DATA.wLevel);
    m_poOwner->AddGuideRecord( EGF_MELTING);
    CTaskMgr::Instance()->OnMelt(m_poOwner);

    //��¼����װ����־
	CRecordMgr::Instance()->RecordInfo( m_poOwner->GetID(), ERM_DECITEM, CRecordMgr::EDIT_MELT, GetItemKindID(), 0, 
        m_poOwner->GetLevel(), m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel, m_stDT_EQUIP_DATA.wLevel, 1);
	
	USR_INFO(_SDT("[%s: %d]: Melt Equip PlayerID: %u, KindID:%u Level:%u!"), MSG_MARK, m_poOwner->GetID(), m_stDT_EQUIP_DATA.wKindID, m_stDT_EQUIP_DATA.wLevel);

    //���
    m_poOwner->OnDeleteEquip(this);
    return ERR_MELT_EQUIP::ID_SUCCESS;
}

SEquipProp* CEquip::GetEquipProp()
{
    SEquipProp* pstEquipProp =  CEquipPropMgr::Instance()->GetProp(m_stDT_EQUIP_DATA.wKindID);
    if(NULL == pstEquipProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: pstEquipProp is NULL,KindID[%d]!"), MSG_MARK, m_stDT_EQUIP_DATA.wKindID);
    }

    return pstEquipProp;
}

UINT8	CEquip::GetMosaicGemNum()
{
    UINT8	byTotal = 0;
    UINT8	byIdex = 0;
    for (byIdex = 0; byIdex < MAX_XIANGQIAN_NUM; byIdex++)
    {
		//����Ƿ������ƷID
		if(0 == m_stDT_EQUIP_DATA.astXiangqianList[byIdex].wItemID)
		{
			continue;
		}
		//��ȡ��Ʒ���������
		SGoodsProp *poGoodsProp = CGoodsPropMgr::Instance()->GetPropByPrimaryKey(m_stDT_EQUIP_DATA.astXiangqianList[byIdex].wItemID);
		if (NULL == poGoodsProp)
		{
			continue;
		}
		//��ȡ��Ʒ�Ƿ��Ǳ�ʯ
		if (15 != poGoodsProp->byMainKindID)
		{
			continue;
		}
		byTotal++;
    }
	
    return byTotal;
}

VOID CEquip::GetDT_EQUIP_MELT_DATA_CLI(DT_EQUIP_MELT_DATA_CLI& stEquipMeltCli)
{
	SEquipProp* pstEquipProp = GetEquipProp();
	if(NULL == pstEquipProp)
	{
		return;
	}

	stEquipMeltCli.wKindID = m_stDT_EQUIP_DATA.wKindID;
	stEquipMeltCli.wIdx = m_stDT_EQUIP_DATA.wIdx;
	stEquipMeltCli.wLevel = m_stDT_EQUIP_DATA.wLevel;
	stEquipMeltCli.byDressPos = pstEquipProp->byPosKindID;

    stEquipMeltCli.wDressLevel = (pstEquipProp ? pstEquipProp->wDressLevel : 1);

	GetRecoverScience(stEquipMeltCli.dwMinScience, stEquipMeltCli.dwMaxScience);

    stEquipMeltCli.byMeltTip = 0; // 0 = �ɸ�ħ
    if (GetEnchantLevel() > 0){
        stEquipMeltCli.byMeltTip = 2; // 2 = ��װ���ѱ���ħ���޷�Ͷ������¯��ֻ��ͨ�����۷�ʽ����
    }else{
        UINT8 byXiangqianNum = CXiangqianMgr::Instance()->GetUnlockNum( stEquipMeltCli.wDressLevel );
        for(UINT8 byIndex = 0; byIndex < byXiangqianNum; byIndex++){
            if(0 != m_stDT_EQUIP_DATA.astXiangqianList[byIndex].wItemID){
                stEquipMeltCli.byMeltTip = 1; // 1 = ��װ����Ƕ����ʯ�����ܽ�������
                break;
            }
        }
    }

	stEquipMeltCli.dwMeltGold = CLuamgr::Instance()->GetMeltGold(stEquipMeltCli.dwMaxScience);
}


UINT32  CEquip::GetUpLevelCoin(UINT8 byUpLevel)
{
	SEquipProp* pstEquipProp = GetEquipProp();
	if(NULL == pstEquipProp)
	{
		return 0xFFFFFFFF;
	}
	//if(m_stDT_EQUIP_DATA.wLevel+byUpLevel > m_poOwner->GetLevel())
	//{
	//	return 0xFFFFFFFF;
	//}
	UINT16 wDressLevel = pstEquipProp->wDressLevel;
	UINT32 dwCost = 0;
	UINT16 wMaxLevel = CSinglePramMgr::Instance()->GetMaxPlayerLevel();
	for(UINT8 byIdx = 1; byIdx <= byUpLevel; byIdx++)
	{
		UINT16 wLevel = m_stDT_EQUIP_DATA.wLevel+byIdx;
		if(wLevel > wMaxLevel)
		{
			break;
		}
		dwCost += CEquipStrengthenPropMgr::Instance()->GetStrengthenCoin(wLevel, wDressLevel);		
	}

	return dwCost;
}

CEquip::EnchantStone2NumMap CEquip::GetSellEnchantStone()
{
    // ���ڲ�ͬ��ħ�ȼ�ʱ����ĸ�ħʯ���ܲ�һ���������map����ʽ�����
    EnchantStone2NumMap mapStone2Num;

    SEquipProp* pstEquipProp = GetEquipProp();
    if(NULL == pstEquipProp){
        return mapStone2Num;
    }

    // ��1������ǰ��ħ�ȼ������и�ħʯ�ۼ�
    for(UINT16 wLvl = 1; wLvl <= m_wEnchantLevel; wLvl++){
        GoodsID wStoneID = CEquipStrengthenPropMgr::Instance()->GetEnchantStoneID(wLvl);
        UINT16 wStoneNum = (UINT16)CEquipStrengthenPropMgr::Instance()->GetEnchantStone(wLvl, pstEquipProp->wDressLevel);

        mapStone2Num[wStoneID] += wStoneNum;
    }

    // ��һ��������
    const SFlyProp &stFlyProp = CFlyPropMgr::Instance()->GetFlyProp();
    for(EnchantStone2NumMap::iterator itr = mapStone2Num.begin(); itr != mapStone2Num.end(); ++itr){
        UINT32 &dwStoneNum = itr->second;
        dwStoneNum = (UINT32)(dwStoneNum * stFlyProp.fSellEnchantStonePercent);
    }

    return mapStone2Num;
}

UINT32  CEquip::GetUpLevelCoin(UINT16 wCurStrengthenLevel, UINT8 byUpLevel, UINT16 wDressLevel, UINT16 wPlayerLevel)
{
	UINT16 wMaxLevel = CSinglePramMgr::Instance()->GetMaxPlayerLevel();
	if(wCurStrengthenLevel+byUpLevel > wMaxLevel)
	{
		if(wCurStrengthenLevel > wMaxLevel)
		{
			return 0xFFFFFFFF;
		}
		else if(wCurStrengthenLevel == wMaxLevel)
		{
			return CEquipStrengthenPropMgr::Instance()->GetStrengthenCoin(wMaxLevel, wDressLevel);
		}
		else 
		{
				byUpLevel = wPlayerLevel - wCurStrengthenLevel;
		}
	}
	UINT32 dwCost = 0;
	for(UINT8 byIdx = 1; byIdx <= byUpLevel; byIdx++)
	{
		dwCost += CEquipStrengthenPropMgr::Instance()->GetStrengthenCoin(wCurStrengthenLevel+byIdx, wDressLevel);		
	}

	return dwCost;
}

VOID CEquip::ClearJewelryAttr()
{
	m_mapJewelryAttr.clear();
}

VOID CEquip::AddJewelryAttribute(UINT32 dwKey, UINT32 dwValue)
{
	m_mapJewelryAttr[dwKey] += dwValue;
}

VOID CEquip::GetJewelryAttribute(UINT32& dwHP, UINT32& dwAttack)
{
	dwHP = m_mapJewelryAttr[EBAK_HP];
	dwAttack = m_mapJewelryAttr[EBAK_ATTACK];
}