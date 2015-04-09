#include "moneytree.h"
#include "moneytreepropmgr.h"
#include "moneytreepropbasemgr.h"
#include <logic/player/player.h>
#include <common/client/errdef.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <common/server/utility.h>
#include <db/autosqlbuf.h>
#include "logic/record/recordmgr.h"
#include <logic/vip/vippropmgr.h>
#include "logic/medal/playermedal.h"
IMPLEMENT_CLASS_POOL_MGR(CMoneyTree)
CMoneyTree::CMoneyTree()
{
	memset(&m_stDT_MONEY_TREE_DATA, 0, sizeof(m_stDT_MONEY_TREE_DATA));
}


CMoneyTree::~CMoneyTree()
{

}

BOOL CMoneyTree::Init(DT_MONEY_TREE_DATA& stMoneyTreeData, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }
    memcpy(&m_stDT_MONEY_TREE_DATA, &stMoneyTreeData, sizeof(DT_MONEY_TREE_DATA));

    m_poOwner = poOwner;

    return TRUE;
}

VOID CMoneyTree::GetDT_MONEY_TREE_DATA_CLI(DT_MONEY_TREE_DATA_CLI& stDT_MONEY_TREE_DATA_CLI, UINT16 &wGetCoinRate2)
{
    //SMoneyTreeBaseProp&	stMoneyTreeBaseProp = CMoneyTreeBasePropMgr::Instance()->GetMoneyTreeBaseProp();
	UINT16 wTotalRockNum = CVipPropMgr::Instance()->GetIncNum(EVINF_MONEYTREE, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    //����ʱ��
    UINT16				wMoodKeepTime = CMoneyTreePropMgr::Instance()->GetMoodKeepTime();

	stDT_MONEY_TREE_DATA_CLI.wTotalCanRockNum  = wTotalRockNum;
    //����
    if(IsToday(m_stDT_MONEY_TREE_DATA.qwRockTime))
    {
        INT16 shCanRockNum = wTotalRockNum - m_stDT_MONEY_TREE_DATA.wRockNum;
        stDT_MONEY_TREE_DATA_CLI.wCanRockNum = shCanRockNum > 0 ? shCanRockNum : 0;
        stDT_MONEY_TREE_DATA_CLI.dwRockNeedGold = CMoneyTreeBasePropMgr::Instance()->GetRockNeedGold(m_poOwner, m_stDT_MONEY_TREE_DATA.wRockNum);
        INT64 dnGap = SDTimeSecs() - m_stDT_MONEY_TREE_DATA.qwMoodStartTime;
        if(dnGap  < 0)//�쳣
        {
            stDT_MONEY_TREE_DATA_CLI.byMoodValue = 0;
            stDT_MONEY_TREE_DATA_CLI.wMoodOverCountDown = 0;
        }

		//wMoodKeepTime = CMoneyTreePropMgr::Instance()->GetMoodKeepTime(stDT_MONEY_TREE_DATA_CLI.byMoodValue + 1);
        //�ѹ������ڣ�����
        else if(dnGap >= wMoodKeepTime)
        {
            stDT_MONEY_TREE_DATA_CLI.byMoodValue = 0;
            stDT_MONEY_TREE_DATA_CLI.wMoodOverCountDown = 0;
        }
        else
        {
            stDT_MONEY_TREE_DATA_CLI.byMoodValue = m_stDT_MONEY_TREE_DATA.byMoodValue;
            INT64 dnModGap = wMoodKeepTime - dnGap;
            if(dnModGap <= 0)
            {
                stDT_MONEY_TREE_DATA_CLI.wMoodOverCountDown = 0;
            }
            else
            {
                stDT_MONEY_TREE_DATA_CLI.wMoodOverCountDown = (UINT16)(dnModGap > wMoodKeepTime ? wMoodKeepTime : dnModGap);
            }
			//wMoodKeepTime = CMoneyTreePropMgr::Instance()->GetMoodKeepTime(stDT_MONEY_TREE_DATA_CLI.byMoodValue + 1);
        }
    }
    else
    {
        stDT_MONEY_TREE_DATA_CLI.byMoodValue = 0;
        stDT_MONEY_TREE_DATA_CLI.wMoodOverCountDown = 0;
        stDT_MONEY_TREE_DATA_CLI.wCanRockNum = wTotalRockNum;
        stDT_MONEY_TREE_DATA_CLI.dwRockNeedGold = CMoneyTreeBasePropMgr::Instance()->GetRockNeedGold(m_poOwner, 0);
		m_stDT_MONEY_TREE_DATA.wRockNum = 0;		//����
    }
	//������������0
	if(m_poOwner->CKGuide( EGF_ROCKMONEY))
	{
		stDT_MONEY_TREE_DATA_CLI.dwRockNeedGold = 0;
	}
    stDT_MONEY_TREE_DATA_CLI.dwRockBaseCoin = CMoneyTreeBasePropMgr::Instance()->GetProduceCoin(m_poOwner->GetLevel(), 0);
    wGetCoinRate2 = 100 + CMoneyTreePropMgr::Instance()->GetMoneyTreeIncMoneyRate(m_stDT_MONEY_TREE_DATA.byMoodValue);
	stDT_MONEY_TREE_DATA_CLI.byGetCoinRate = (UINT8)(wGetCoinRate2);
    stDT_MONEY_TREE_DATA_CLI.wMoodKeepTime = wMoodKeepTime;

}

UINT16 CMoneyTree::RockMoney(UINT32& dwGetCoin, UINT8 byGuideFlag, DT_MONEY_TREE_DATA_CLI& stMoneyTreeInfo, UINT16 &wGetCoinRate2)
{
    UINT32				dwCostGold = 0;
    //����ʱ��
	UINT16 wTotalRockNum = CVipPropMgr::Instance()->GetIncNum(EVINF_MONEYTREE, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
	stMoneyTreeInfo.wTotalCanRockNum = wTotalRockNum;
	stMoneyTreeInfo.wVipExtNum = CVipPropMgr::Instance()->GetIncNum(EVINF_MONEYTREE, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    UINT16				wMoodKeepTime = CMoneyTreePropMgr::Instance()->GetMoodKeepTime();
    //δ����
    if(m_poOwner->CKGuide( EGF_ROCKMONEY))
    {
        //����,���жϴ�����Ԫ����������1
        m_stDT_MONEY_TREE_DATA.byMoodValue = 1;
        dwGetCoin = CMoneyTreeBasePropMgr::Instance()->GetProduceCoin(m_poOwner->GetLevel(), m_stDT_MONEY_TREE_DATA.byMoodValue);
		//m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin += dwGetCoin;
		m_poOwner->AddCoin(dwGetCoin, CRecordMgr::EACT_GUIDEROCKMONEY, m_stDT_MONEY_TREE_DATA.byMoodValue, m_stDT_MONEY_TREE_DATA.wRockNum);
		m_stDT_MONEY_TREE_DATA.qwRockTime = SDTimeSecs();
		m_stDT_MONEY_TREE_DATA.wRockNum++;
    }
    //������
    else
    {
        //�ͻ���ָ�����ԣ�ֱ�ӷ�������,���жϴ�����Ԫ����Ҳ������ͭ��
        if(1 == byGuideFlag)
        {
            dwGetCoin = CMoneyTreeBasePropMgr::Instance()->GetProduceCoin(m_poOwner->GetLevel(), m_stDT_MONEY_TREE_DATA.byMoodValue);
            GetDT_MONEY_TREE_DATA_CLI(stMoneyTreeInfo, wGetCoinRate2);
            return ERR_ROCK_MONEY_TREE::ID_SUCCESS;
        }

        //����
        if(IsToday(m_stDT_MONEY_TREE_DATA.qwRockTime))
        {
            //�Ѳ�����ҡ
            if(m_stDT_MONEY_TREE_DATA.wRockNum >= wTotalRockNum)
            {
                return ERR_ROCK_MONEY_TREE::ID_USE_OUT_NUM;
            }
            else
            {
                //�ж�Ԫ��
                dwCostGold = CMoneyTreeBasePropMgr::Instance()->GetRockNeedGold(m_poOwner, m_stDT_MONEY_TREE_DATA.wRockNum);
                if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold < dwCostGold)
                {
                    return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
                }

                //�ж�����ֵ������
                INT64 dnGap = SDTimeSecs() - m_stDT_MONEY_TREE_DATA.qwMoodStartTime;
                if(dnGap  < 0)//�쳣
                {
                    m_stDT_MONEY_TREE_DATA.qwMoodStartTime = 0;
                    m_stDT_MONEY_TREE_DATA.byMoodValue = 0;
                }
                //�ѹ������ڣ�����
                else if(dnGap >= wMoodKeepTime)
                {
                    m_stDT_MONEY_TREE_DATA.qwMoodStartTime = 0;
                    m_stDT_MONEY_TREE_DATA.byMoodValue = 0;
                }
                dwGetCoin = CMoneyTreeBasePropMgr::Instance()->GetProduceCoin(m_poOwner->GetLevel(), m_stDT_MONEY_TREE_DATA.byMoodValue);
            }
        }
        //���ǽ��죬������ҡǮֵ
        else
        {
            m_stDT_MONEY_TREE_DATA.wRockNum = 0;
            m_stDT_MONEY_TREE_DATA.byMoodValue = 0;

            //�ж�Ԫ��
            dwCostGold = CMoneyTreeBasePropMgr::Instance()->GetRockNeedGold(m_poOwner, m_stDT_MONEY_TREE_DATA.wRockNum);
            if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold < dwCostGold)
            {
                return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
            }
            dwGetCoin = CMoneyTreeBasePropMgr::Instance()->GetProduceCoin(m_poOwner->GetLevel(), m_stDT_MONEY_TREE_DATA.byMoodValue);
        }

        //�۳�Ԫ�������ջ�ͭ��
        //m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold -= dwCostGold;
        //m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin += dwGetCoin;
		m_poOwner->DecGold(dwCostGold, CRecordMgr::EDGT_ROCKMONEY, m_stDT_MONEY_TREE_DATA.byMoodValue, m_stDT_MONEY_TREE_DATA.wRockNum);
		m_poOwner->AddCoin(dwGetCoin, CRecordMgr::EACT_ROCKMONEY, m_stDT_MONEY_TREE_DATA.byMoodValue, m_stDT_MONEY_TREE_DATA.wRockNum);
		
        //�����ֵ����ֵ
        if(RandomReseed(100) < CMoneyTreePropMgr::Instance()->GetMoneyTreeMoodRate(m_stDT_MONEY_TREE_DATA.byMoodValue))
        {
			UINT8 byMoodValue = m_stDT_MONEY_TREE_DATA.byMoodValue + 1;
			if(CMoneyTreePropMgr::Instance()->IsExist(byMoodValue))
			{
				m_stDT_MONEY_TREE_DATA.byMoodValue++;
			}
            m_stDT_MONEY_TREE_DATA.qwMoodStartTime = SDTimeSecs();//��������������ֵ������
        }
        m_stDT_MONEY_TREE_DATA.qwRockTime = SDTimeSecs();
        m_stDT_MONEY_TREE_DATA.wRockNum++;
		CPlayerMedal* poPlayerMedal = m_poOwner->GetPlayerMedal();
		if ( NULL != poPlayerMedal)
		{
			poPlayerMedal->CheckMedalBySmallType(EMST_ROCK_MONEY);
		}

    }

    //SetSaveState(ESS_WANT_SAVE);

    //��¼������
    m_poOwner->AddGuideRecord( EGF_ROCKMONEY);
    GetDT_MONEY_TREE_DATA_CLI(stMoneyTreeInfo, wGetCoinRate2);

    return ERR_ROCK_MONEY_TREE::ID_SUCCESS;
}