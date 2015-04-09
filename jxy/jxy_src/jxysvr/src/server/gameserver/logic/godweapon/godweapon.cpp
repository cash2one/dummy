#include "godweapon.h"
#include "godweaponbasepropmgr.h"
#include "godweaponpropmgr.h"
#include <common/client/errdef.h>
#include <common/client/commondef.h>
#include <logic/player/player.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <logic/other/singleprammgr.h>
#include <logic/hero/heromgr.h>
#include <logic/record/recordmgr.h>
#include <logic/task/taskmgr.h>
#include <logic/base/logicfunc.h>
#include <logic/bag/bag.h>
#include "logic/item/jewelry/jewelrypropmgr.h"
using namespace SGDP;

IMPLEMENT_CLASS_POOL_MGR(CGodWeapon)
CGodWeapon::CGodWeapon()
{
    m_poHero = NULL;
    memset(&m_stDT_GODWEAPON_DATA, 0, sizeof(m_stDT_GODWEAPON_DATA));
    memset(&m_stDT_GODWEAPON_DATA_CLI, 0, sizeof(m_stDT_GODWEAPON_DATA_CLI));
	m_dwExtAttack = 0;
	m_dwExtDefend = 0;
}


CGodWeapon::~CGodWeapon()
{
	m_dwExtAttack = 0;
	m_dwExtDefend = 0;
}

BOOL CGodWeapon::Init(DT_GODWEAPON_DATA* pstDT_GODWEAPON_DATA, CPlayer* poOwner, CHero*	poHero)
{
    if((NULL == poOwner) || (NULL == poHero))
    {
        return FALSE;
    }
    m_poOwner = poOwner;
    m_poHero = poHero;

    memcpy(&m_stDT_GODWEAPON_DATA, pstDT_GODWEAPON_DATA, sizeof(DT_GODWEAPON_DATA));
    m_stDT_GODWEAPON_DATA.wHeroKindID = poHero->GetHeroID();

	//����293�汾�Ŀͻ���
	if(m_poOwner->GetCliVer() <= 293 && m_stDT_GODWEAPON_DATA.wQuality > MAX_GODWEAPON_QUALITY_NUM)
	{
		m_stDT_GODWEAPON_DATA.wLevel = 10;
		m_stDT_GODWEAPON_DATA.wQuality = MAX_GODWEAPON_QUALITY_NUM;
	}

    if(!InitData())
    {
        return FALSE;
    }
    return TRUE;
}

UINT16 CGodWeapon::Upgrade(UINT16 wQuality, UINT16 wLevel)
{
    UINT8 byQualityUpdateNum = CGodweaponBasePropMgr::Instance()->GetQualityUpdateNum();
    if(wQuality > CGodweaponPropMgr::Instance()->GetMaxQuality(m_poHero->GetHeroID()))
    {
        return ERR_UPGRADE_GODWEAPON::ID_QUALITY_INVALID;
    }


    //�ж��ǽ��׻�����ͨ����
    if(0 == wLevel)
    {
        if(wQuality <= m_stDT_GODWEAPON_DATA.wQuality)
        {
            return ERR_UPGRADE_GODWEAPON::ID_SUCCESS;
        }
        if((wQuality != m_stDT_GODWEAPON_DATA.wQuality + 1))
        {
            return ERR_UPGRADE_GODWEAPON::ID_QUALITY_INVALID;
        }

        //û�дﵽ��ǰƷ�ʵ����ȼ������ܽ���
        if(m_stDT_GODWEAPON_DATA.wLevel != byQualityUpdateNum)
        {
            return ERR_UPGRADE_GODWEAPON::ID_NOT_REACH_MAX_LEVEL;
        }

        //����
        return UpgradeQuality();
    }
    else if(wQuality == m_stDT_GODWEAPON_DATA.wQuality)
    {
        //����ȼ�С�ڵ�ǰ�ȼ���ֱ�ӷ��سɹ�
        if(wLevel <= m_stDT_GODWEAPON_DATA.wLevel)
        {
            return ERR_UPGRADE_GODWEAPON::ID_SUCCESS;
        }

        if(wLevel > byQualityUpdateNum)
        {
            return ERR_UPGRADE_GODWEAPON::ID_LEVEL_INVALID;
        }

        if(wLevel == m_stDT_GODWEAPON_DATA.wLevel + 1)
        {
            //����
            return UpgradeLevel();
        }
        else
        {
            return ERR_UPGRADE_GODWEAPON::ID_LEVEL_INVALID;
        }
    }
    else
    {
        return ERR_UPGRADE_GODWEAPON::ID_QUALITY_INVALID;
    }

    CTaskMgr::Instance()->OnUpgradeGodweapon(m_poOwner);

    return ERR_UPGRADE_GODWEAPON::ID_SUCCESS;
}

VOID CGodWeapon::Recover(BOOL bUseGold) //���������
{
    //m_poOwner->GetDT_PLAYER_BASE_DATA().qwScience += m_stDT_GODWEAPON_DATA_CLI.qwRecoverScience;
    if( bUseGold )
    {
        //ʹ��Ԫ���������ָ�����
        UINT64 qwRecover = 0;
        if( CGodweaponBasePropMgr::Instance()->GetGodWeaponRecoverRate() != 0 )
        {
            qwRecover = m_stDT_GODWEAPON_DATA_CLI.qwRecoverScience * 100 / CGodweaponBasePropMgr::Instance()->GetGodWeaponRecoverRate();
        }
        else
        {
            SYS_CRITICAL( _SDT( "GodWeaponRecoverRate=0, cfg error!" ) );
        }
        m_poOwner->AddScience((UINT32)qwRecover, CRecordMgr::EAST_FREEGODWEAPON, m_stDT_GODWEAPON_DATA.wQuality, m_stDT_GODWEAPON_DATA.wLevel);
    }
    else
    {
        m_poOwner->AddScience((UINT32)(m_stDT_GODWEAPON_DATA_CLI.qwRecoverScience), CRecordMgr::EAST_FREEGODWEAPON, m_stDT_GODWEAPON_DATA.wQuality, m_stDT_GODWEAPON_DATA.wLevel);
    }

    Reupdate();
}

//���¸���Ϊ�տ���
VOID CGodWeapon::Reupdate()
{
    m_stDT_GODWEAPON_DATA.byHaveDataFlag = 1;
    m_stDT_GODWEAPON_DATA.wHeroKindID = m_poHero->GetDT_HERO_BASE_DATA().wKindID;
    m_stDT_GODWEAPON_DATA.wQuality = 1;
    m_stDT_GODWEAPON_DATA.wLevel = 0;//��0��ʼ

    InitData();
}


BOOL CGodWeapon::InitData()
{
//   SGodweaponQualityUpgradeProp* pstGodweaponQualityUpgradeProp = NULL;
    //pstGodweaponQualityUpgradeProp = CGodweaponPropMgr::Instance()->GetGodweaponQualiryUpgradeProp(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality);
//   if(NULL == pstGodweaponQualityUpgradeProp)
//   {
//       SYS_CRITICAL(_SDT("[%s: %d]: CGodWeapon InitData failed![HeroKindID:%d, Quality:%d]"), MSG_MARK, m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality);
//       return FALSE;
//   }

    m_stDT_GODWEAPON_DATA_CLI.wQuality = m_stDT_GODWEAPON_DATA.wQuality;
    m_stDT_GODWEAPON_DATA_CLI.wLevel = m_stDT_GODWEAPON_DATA.wLevel;
    m_stDT_GODWEAPON_DATA_CLI.wHeroKindID = m_stDT_GODWEAPON_DATA.wHeroKindID;
    m_stDT_GODWEAPON_DATA_CLI.wMaxQuality = CGodweaponPropMgr::Instance()->GetMaxQuality(m_stDT_GODWEAPON_DATA.wHeroKindID);
    CGodweaponPropMgr::Instance()->GetGodweaponAttr(m_poOwner->GetCliVer(), m_stDT_GODWEAPON_DATA.wHeroKindID,
            m_stDT_GODWEAPON_DATA.wQuality,
            m_stDT_GODWEAPON_DATA.wLevel,
            m_stDT_GODWEAPON_DATA_CLI.stIncAttr,
            m_stDT_GODWEAPON_DATA_CLI.byEncAttrNum,
            m_stDT_GODWEAPON_DATA_CLI.astQualityUpgradeEncAttr,
            m_stDT_GODWEAPON_DATA_CLI.wQualityRequireLevel,
            m_stDT_GODWEAPON_DATA_CLI.dwUpgrageScience,
            m_stDT_GODWEAPON_DATA_CLI.wUpgradeQualityNeedItemNum,
            m_stDT_GODWEAPON_DATA_CLI.stNextLevelIncAttr);

    if(m_stDT_GODWEAPON_DATA.wLevel >= CGodweaponBasePropMgr::Instance()->GetQualityUpdateNum())
    {
        m_stDT_GODWEAPON_DATA_CLI.byMaxLevelFlag = 1;
    }
    else
    {
        m_stDT_GODWEAPON_DATA_CLI.byMaxLevelFlag = 0;
    }

    ////�°�ͻ�����ʾ����������Ҳ����
    const SAllAttrProp* pstGodWeaponAttr = GetCurGodWeaponAttr();
    if(pstGodWeaponAttr)
    {
        memset(&m_stDT_GODWEAPON_DATA_CLI.stIncAttr, 0, sizeof(m_stDT_GODWEAPON_DATA_CLI.stIncAttr));
		DT_BATTLE_BASE_ATTRIBUTE stBaseBattleAttr = {0};
        CLogicFunc::AddAttr(pstGodWeaponAttr, stBaseBattleAttr, m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stHideBattleAttr, m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stExtBattleAttr);
		m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stBattleAttr.dwHP = (UINT32)stBaseBattleAttr.qwHP;
		m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stBattleAttr.dwAttack = stBaseBattleAttr.dwAttack;
    }

    UINT64 qwCostScience = CGodweaponPropMgr::Instance()->GetUpgradeTotalScience(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality, m_stDT_GODWEAPON_DATA.wLevel);
    UINT64 qwRecoverScience = CGodweaponBasePropMgr::Instance()->GetGodWeaponRecoverRate() * qwCostScience / 100;
    m_stDT_GODWEAPON_DATA_CLI.qwRecoverScience = qwRecoverScience;
    m_stDT_GODWEAPON_DATA_CLI.qwPerfectRecoverScience = m_stDT_GODWEAPON_DATA_CLI.qwRecoverScience * 100 / CGodweaponBasePropMgr::Instance()->GetGodWeaponRecoverRate();


    m_stDT_BATTLE_ATTRIBUTE = m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stBattleAttr;
    m_stCurDT_BATTLE_ATTRIBUTE = m_stDT_BATTLE_ATTRIBUTE;

    //�ɰ�����¼��㽱��������,Ϊ�˾ɰ�����ͻ��ˡ�����
    if(m_poOwner->GetCliVer() <= 290)
    {
        if(0 != m_stDT_GODWEAPON_DATA.wQuality)
        {
            DT_ATTR_INC_DATA& stQualityUpgradeEncAttr = m_stDT_GODWEAPON_DATA_CLI.astQualityUpgradeEncAttr[0];
            UINT32 dwHP = 0;
            for(UINT8 byIdx = 0; byIdx < m_stDT_GODWEAPON_DATA.wQuality - 1; byIdx++)
            {
                dwHP += m_stDT_GODWEAPON_DATA_CLI.astQualityUpgradeEncAttr[byIdx].dwAttrValue;
            }
            stQualityUpgradeEncAttr.dwAttrValue += m_stDT_BATTLE_ATTRIBUTE.dwHP - dwHP;
        }
    }
	//������Ʒ��������Ӱ��
	AddBattleByJewelry();
	m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stBattleAttr.dwAttack += m_dwExtAttack;
	m_stDT_GODWEAPON_DATA_CLI.stIncAttr.stBattleAttr.dwHP += m_dwExtDefend;
    //�����佫��ս������
    m_poHero->InitBattleAttribute();

    //�����������
    m_poOwner->ResetBattleAttr();

    return TRUE;
}

UINT32 CGodWeapon::GetHurtValue()
{ 
	return m_stCurDT_BATTLE_ATTRIBUTE.dwAttack + m_dwExtAttack; 
}
//��������
UINT16 CGodWeapon::UpgradeQuality()
{
    if(m_stDT_GODWEAPON_DATA.wQuality >= CGodweaponPropMgr::Instance()->GetMaxQuality(m_poHero->GetHeroID()))
    {
        return ERR_UPGRADE_GODWEAPON::ID_QUALITY_INVALID;
    }

    //�Ƿ�ﵽ���׵ȼ�Ҫ��
    SGodweaponQualityUpgradeProp* pstNextGodweaponProp = CGodweaponPropMgr::Instance()->GetGodweaponQualiryUpgradeProp(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality + 1);
    if(NULL == pstNextGodweaponProp)
    {
        return ERR_UPGRADE_GODWEAPON::ID_QUALITY_INVALID;
    }
    if(m_poHero->GetDT_HERO_BASE_DATA().wLevel < pstNextGodweaponProp->wRequirePlayerLevel)
    {
        return ERR_UPGRADE_GODWEAPON::ID_HERO_LEVEL_NOT_REACH;
    }

    //�Ƿ�ﵽ���׵ȼ�Ҫ��
    SGodweaponQualityUpgradeProp* pstGodweaponQualityUpgradeProp = CGodweaponPropMgr::Instance()->GetGodweaponQualiryUpgradeProp(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality);
    if(NULL == pstGodweaponQualityUpgradeProp)
    {
        return ERR_UPGRADE_GODWEAPON::ID_QUALITY_INVALID;
    }

    //�Ƿ��н�����Ʒ
    CGoods* poGoods = m_poOwner->GetBag().GetGoodsItem(CGodweaponBasePropMgr::Instance()->GetUpgradeQualityItemID());
    if(NULL == poGoods)
    {
        return ERR_UPGRADE_GODWEAPON::ID_ITEM_NOT_EXIST;
    }
    if(poGoods->GetCurPileNum() < pstGodweaponQualityUpgradeProp->wUpgradeQualityItemNum)
    {
        return ERR_UPGRADE_GODWEAPON::ID_ITEM_NOT_ENOUGH;
    }

    //�۳����׵���
    poGoods->DecPileNum(pstGodweaponQualityUpgradeProp->wUpgradeQualityItemNum, CRecordMgr::EDIT_GODWEAPON);

    if(0 == poGoods->GetDT_GOODS_DATA().wPileCount)
    {
        m_poOwner->OnDeleteItem(poGoods);
    }

    //����
    m_stDT_GODWEAPON_DATA.wQuality++;
    m_stDT_GODWEAPON_DATA.wLevel = 0;//

    //���³�ʼ������
    InitData();

    CTaskMgr::Instance()->OnUpgradeGodweapon(m_poOwner);
    return ERR_UPGRADE_GODWEAPON::ID_SUCCESS;
}

//��ͨ����
UINT16 CGodWeapon::UpgradeLevel()
{
    UINT64 qwCostScience = CGodweaponPropMgr::Instance()->GetUpgradeScience(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality, m_stDT_GODWEAPON_DATA.wLevel + 1);
    //����㲻��
    if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwScience < qwCostScience)
    {
        return ERR_UPGRADE_GODWEAPON::ID_NOT_ENOUGH_SCIENCE;
    }

    //�۳������
    //m_poOwner->GetDT_PLAYER_BASE_DATA().qwScience -= qwCostScience;
    m_poOwner->DecScience((UINT32)qwCostScience, CRecordMgr::EDSCT_GODWEAPONUPGRADE, m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality, m_stDT_GODWEAPON_DATA.wLevel);

    //����
    m_stDT_GODWEAPON_DATA.wLevel++;

    //���³�ʼ������
    InitData();


    CTaskMgr::Instance()->OnUpgradeGodweapon(m_poOwner);
    return ERR_UPGRADE_GODWEAPON::ID_SUCCESS;
}

const SAllAttrProp* CGodWeapon::GetCurGodWeaponAttr()
{
    if(0 == m_stDT_GODWEAPON_DATA.wLevel)
    {
        SGodweaponQualityUpgradeProp* pstProp = CGodweaponPropMgr::Instance()->GetGodweaponQualiryUpgradeProp(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality);
        if(pstProp)
        {
            return &pstProp->stAllAttr;
        }
    }
    else
    {
        SGodweaponLevelUpgradeProp* pstProp = CGodweaponPropMgr::Instance()->GetGodweaponLevelUpgradeProp(m_stDT_GODWEAPON_DATA.wHeroKindID, m_stDT_GODWEAPON_DATA.wQuality, m_stDT_GODWEAPON_DATA.wLevel);
        if(pstProp)
        {
            return &pstProp->stAllAttr;
        }
    }

    return NULL;
}

VOID CGodWeapon::GetDT_GODWEAPON_BATTLE_DATA(UINT16 wHeroKindID, DT_GODWEAPON_BATTLE_DATA& stGodweaponInfo)
{
    stGodweaponInfo.wQuality = m_stDT_GODWEAPON_DATA.wQuality;
    stGodweaponInfo.wLevel = m_stDT_GODWEAPON_DATA.wLevel;
    stGodweaponInfo.stBattleAttr = m_stDT_BATTLE_ATTRIBUTE;
    stGodweaponInfo.byHPGridNum = 0; //��CHPGridMgr::Instance()->SetHPGridNum��ֵ
    stGodweaponInfo.wMaxQuality = CGodweaponPropMgr::Instance()->GetMaxQuality(wHeroKindID);
}

VOID CGodWeapon::UpgradeByScience(UINT32 dwScience)
{
    UINT16 wCurQuality = m_stDT_GODWEAPON_DATA.wQuality;
    UINT16 wCurLevel = m_stDT_GODWEAPON_DATA.wLevel;
    UINT8 byQualityUpdateNum = CGodweaponBasePropMgr::Instance()->GetQualityUpdateNum();
    UINT16 wMaxQuality = CGodweaponPropMgr::Instance()->GetMaxQuality(m_stDT_GODWEAPON_DATA.wHeroKindID);
    BOOL bNextQuality = FALSE;
    UINT64 qwCostScience = 0;
    BOOL bMatch = FALSE;
    UINT16 wQualityIdx = wCurQuality;
    UINT16 wLevelIdx = wCurLevel;
    for(wQualityIdx = wCurQuality; wQualityIdx <= wMaxQuality; wQualityIdx++)
    {
        wLevelIdx = 1;
        if(!bNextQuality)
        {
            wLevelIdx = wCurLevel + 1;
        }
        for(; wLevelIdx <= byQualityUpdateNum; wLevelIdx++)
        {
            qwCostScience += CGodweaponPropMgr::Instance()->GetUpgradeScience(m_stDT_GODWEAPON_DATA.wHeroKindID, wQualityIdx, wLevelIdx);
            if(qwCostScience >= dwScience)
            {
                bMatch = TRUE;
                break;
            }
        }
        if(bMatch)
        {
            break;
        }
        bNextQuality = TRUE;
    }
    m_stDT_GODWEAPON_DATA.wQuality = wQualityIdx;
    m_stDT_GODWEAPON_DATA.wLevel = wLevelIdx;

    //���³�ʼ������
    InitData();

}

VOID CGodWeapon::AddBattleByJewelry()
{
	UINT32 dwAddAttack = m_poHero->GetJewelryAttr(EJEA_WEAPON_ATTACK);
	UINT32 dwAddDefend = m_poHero->GetJewelryAttr(EJEA_WEAPON_DEFEND);
	m_dwExtAttack = AddValueByValueType(m_stDT_BATTLE_ATTRIBUTE.dwAttack, dwAddAttack, CJewelryPropMgr::Instance()->GetValueType(EJEA_WEAPON_ATTACK));
	m_dwExtDefend = AddValueByValueType(m_stDT_BATTLE_ATTRIBUTE.dwHP, dwAddDefend, CJewelryPropMgr::Instance()->GetValueType(EJEA_WEAPON_DEFEND));
}