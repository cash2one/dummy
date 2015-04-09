#include "phystrength.h"
#include <net/db/dbpktbuilder.h>
#include <db/autosqlbuf.h>
#include <logic/player/player.h>
#include <common/client/errdef.h>
#include <logic/other/phystrengthmgr.h>
#include <db/autosqlbuf.h>
#include "logic/record/recordmgr.h"
#include <logic/vip/vippropmgr.h>
#include <logic/lua/luamgr.h>
#include "logic/medal/playermedal.h"

IMPLEMENT_CLASS_POOL_MGR(CPhystrength)
CPhystrength::CPhystrength()
{
    memset(&m_stDT_PHYSTRENGTH_DATA, 0 , sizeof(m_stDT_PHYSTRENGTH_DATA));
}

CPhystrength::~CPhystrength()
{

}

BOOL CPhystrength::Init(DT_PHYSTRENGTH_DATA& stDT_PHYSTRENGTH_DATA, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }

    memcpy(&m_stDT_PHYSTRENGTH_DATA, &stDT_PHYSTRENGTH_DATA, sizeof(stDT_PHYSTRENGTH_DATA));
    m_poOwner = poOwner;

    return TRUE;
}


UINT16 CPhystrength::OpenPhyStrength(UINT8 & byBuyPhyStrength, UINT8& byTotalBuyTimes, UINT8& byCanBuyNum, UINT16& wVipExtNum, UINT32& dwNextBuyGold)
{
    wVipExtNum = CVipPropMgr::Instance()->GetIncNum(EVINF_PHYSTRENGTHBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    //�ж�ʱ��
    SBuyPhystrengthProp& stBuyPhystrengthProp = CPhystrengthMgr::Instance()->GetBuyPhystrengthProp();
    //�����Ѿ������
    if(!IsToday(m_stDT_PHYSTRENGTH_DATA.qwLastBuyPhyStrengthTime))
    {
        //����û����������������0
        m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum = 0;
    }

    //����Ϊ����ʱ��
    m_stDT_PHYSTRENGTH_DATA.qwLastBuyPhyStrengthTime = SDTimeSecs();
    byBuyPhyStrength = stBuyPhystrengthProp.byBuyPhyStrength;

    dwNextBuyGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_PHYSTRENGTHBUYNUM, m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum);
    byTotalBuyTimes = (UINT8)CVipPropMgr::Instance()->GetIncNum(EVINF_PHYSTRENGTHBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    byCanBuyNum   = byTotalBuyTimes > m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum ? byTotalBuyTimes - m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum : 0;
    return ERR_OPEN_STRENGTH::ID_SUCCESS;
}


UINT16 CPhystrength::BuyPhyStrength(UINT8& byCanBuyNum, UINT32& dwNextBuyGold)
{
    //�ж�ʱ��
    SBuyPhystrengthProp& stBuyPhystrengthProp = CPhystrengthMgr::Instance()->GetBuyPhystrengthProp();
    UINT8 byBuyMaxNumPerDay = (UINT8)CVipPropMgr::Instance()->GetIncNum(EVINF_PHYSTRENGTHBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    //�����Ѿ������
    if(IsToday(m_stDT_PHYSTRENGTH_DATA.qwLastBuyPhyStrengthTime))
    {
        if(m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum >= byBuyMaxNumPerDay)
        {
            return ERR_BUY_PHYSTRENGTH::ID_REACH_MAX_NUM;
        }
    }
    //����û����������������0
    else
    {
        m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum = 0;
    }

    UINT32 dwCostGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_PHYSTRENGTHBUYNUM, m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum );
    if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold < dwCostGold)
    {
        return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
    }

    //m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold -= dwCostGold;
    //m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength +=  stBuyPhystrengthProp.byBuyPhyStrength;
    m_poOwner->DecGold(dwCostGold, CRecordMgr::EDGT_BUYPHYSTRENGTH, m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum);
    m_poOwner->AddPhyStrength(stBuyPhystrengthProp.byBuyPhyStrength, CRecordMgr::EAPST_BUY);
    //��¼���������ֵ
    if (stBuyPhystrengthProp.byBuyPhyStrength > 0)
    {
        m_poOwner->CkToday();
        m_poOwner->GetDT_PLAYER_TODAY_CONSUME_DATA().qwBuyPhyStrengthNum+=stBuyPhystrengthProp.byBuyPhyStrength;
    }
    m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum++;
	CPlayerMedal* poPlayerMedal = m_poOwner->GetPlayerMedal();
	if ( NULL != poPlayerMedal)
	{
		poPlayerMedal->AddBuyPhystrength();
		if( poPlayerMedal->CheckMedalBySmallType(EMST_PHYSTRENGTH) )
		{

		}
	}

    m_stDT_PHYSTRENGTH_DATA.qwLastBuyPhyStrengthTime = SDTimeSecs();
    byCanBuyNum   = byBuyMaxNumPerDay < m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum ? 0 : byBuyMaxNumPerDay - m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum;
    dwNextBuyGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_PHYSTRENGTHBUYNUM, m_stDT_PHYSTRENGTH_DATA.wLastBuyPhyStrengthNum);

    return ERR_BUY_PHYSTRENGTH::ID_SUCCESS;
}

BOOL CPhystrength::GetPhyStrengthInfo(DT_PHYSTRENGTH_DATA_CLI& stPhyStrengthInfo)
{
	//�Ȼظ�������ȡֵ
	PhyStrengthRecover();

	UINT16 wPhyStrengthRefreshCD = CPhystrengthMgr::Instance()->GetPhyStrengthRefreshCD();

	stPhyStrengthInfo.wPhyStrength = m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength;
	stPhyStrengthInfo.wPhyStrengthRefreshCD = wPhyStrengthRefreshCD;
	stPhyStrengthInfo.wMaxPhyStrength = MAXPHYSTRENGTH;

	if(0 == m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime)
	{
		stPhyStrengthInfo.wPhyStrengthCountDown = 0;
	}
	else
	{
		//�ж�ʱ��
		INT32 nInterval = (INT32)(SDTimeSecs() - m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime);
		if(nInterval < 0) //�쳣
		{
			stPhyStrengthInfo.wPhyStrengthCountDown = 0;
			SYS_CRITICAL(_SDT("[%s: %d]: oNow is oldder than qwPhyStrengthRefreshTime !"), MSG_MARK);
		}
		else if(nInterval > wPhyStrengthRefreshCD)
		{
			stPhyStrengthInfo.wPhyStrengthCountDown = 0;
		}
		else
		{
			stPhyStrengthInfo.wPhyStrengthCountDown = wPhyStrengthRefreshCD - nInterval;
		}
	}

	return TRUE;
}


//�����ָ��������Э�����󴥷���������ʱ��
VOID CPhystrength::PhyStrengthRecover()
{
	UINT64 qwCurSec = SDTimeSecs();
	if(0 == m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime)
	{
		if(m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength < MAXPHYSTRENGTH)
		{
			m_poOwner->AddPhyStrength( MAXPHYSTRENGTH - m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength, CRecordMgr::EAPST_RECOVER );
			SYS_CRITICAL(_SDT("[%s: %d]: player[%u]recover phystrength[%u]!"), MSG_MARK, m_poOwner->GetID(), m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength);
		}
		m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime = SDTimeSecs();
	}
	else
	{
		//�������Գ������ޣ����������򲻻ظ�
		if(m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength >= MAXPHYSTRENGTH)
		{
			m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime = qwCurSec;
			return;
		}

		//�ж�ʱ��
		UINT16		wPhyStrengthRecoverCD = CPhystrengthMgr::Instance()->GetPhyStrengthRefreshCD();
		UINT16		wPhyStrengthRecoverValue = 1;//ÿ�λָ�������1��
		UINT32		dwInterval = (UINT32)(qwCurSec - m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime);
		if(dwInterval > wPhyStrengthRecoverCD)
		{
			UINT16 wRecoverValue = (dwInterval / wPhyStrengthRecoverCD) *  wPhyStrengthRecoverValue;
			UINT16 wAddValue = wRecoverValue; //ʵ�����ӵ�ֵ
			if( m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength + wRecoverValue > MAXPHYSTRENGTH )
			{
				wAddValue = MAXPHYSTRENGTH - m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength;
			}
			m_poOwner->AddPhyStrength(wAddValue, CRecordMgr::EAPST_RECOVER);
			m_stDT_PHYSTRENGTH_DATA.qwLastPhyStrengthRefreshTime = qwCurSec - (dwInterval % wPhyStrengthRecoverCD);//����ˢ��ʱ��
		}
	}
}
