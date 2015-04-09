///<------------------------------------------------------------------------------
//< @file:   logic\medal\playermedal.cpp
//< @author: Kang_zhiquan
//< @date:   2014��6��18�� 21:41:34
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "logic/medal/playermedal.h"
#include "logic/medal/medal.h"
#include "logic/medal/medalpropmgr.h"
#include "logic/build/build.h"
#include "logic/player/player.h"
#include "logic/base/logicfunc.h"
#include "common/client/errdef.h"
IMPLEMENT_CLASS_POOL_MGR(CPlayerMedal)
CPlayerMedal::CPlayerMedal()
{
	Clear();
}

CPlayerMedal::~CPlayerMedal()
{
	Clear();
}

VOID CPlayerMedal::Clear()
{
	memset(&m_stPlayerMedal, 0, sizeof(DT_PLAYER_MEDAL_DATA));
	memset(&m_stMedalBaseData, 0, sizeof(DT_MEDAL_BASE_DATA));
	m_qwLastUpdateTime = 0;
	for ( CMapMedalItr itr = m_mapAllMedal.begin(); itr != m_mapAllMedal.end(); itr++)
	{
		CMedalPropMgr::Instance()->FreeMedal( itr->second->GetSmallType(), itr->second);
	}
	m_mapAllMedal.clear();
	m_mapUseMedal.clear();
	m_mapBuildID.clear();
	m_multiMapAllMedal.clear();
	m_mapUnlockMedal.clear();
	m_mapBattleAttrFixed.clear();
	m_mapBattleAttrPercent.clear();
}

BOOL CPlayerMedal::Init(const DT_PLAYER_MEDAL_DATA& stData, CPlayer* poPlayer)
{
	if ( NULL == poPlayer)
	{
		return FALSE;
	}
	m_poOwner = poPlayer;
	
	CMedal* poMedal = NULL;
	for ( UINT16 wIdx = 0; wIdx < stData.stMealData.wMedalNum && wIdx < MAX_MEDAL_NUM; wIdx++)
	{
		poMedal = CMedalPropMgr::Instance()->CreateMedal(poPlayer, stData.stMealData.astMedalLstData[wIdx]);
		AddMedalToPlayer( poMedal );
	}
	AddNewMedal();
	DealEffectMedal();
	m_qwLastUpdateTime = stData.qwLastUpdateTime;
	m_stMedalBaseData = stData.stMedalBaseData;
	CheckEveryDay();
	//CheckLostMedal();
	InitBattleAttr();
	return TRUE;
}

VOID CPlayerMedal::CheckLostMedal()
{
	for ( CMultiMapMedalItr itr = m_mapUseMedal.begin(); itr != m_mapUseMedal.end(); )
	{
		if ( EMBT_LIMIT_TIME == itr->second->GetBigType())
		{
			CTimeMedal* poTimeMedal = dynamic_cast<CTimeMedal*>(itr->second);
			if ( NULL != poTimeMedal)
			{
				if( poTimeMedal->IsOverTime() )
				{
					m_mapUseMedal.erase(itr++);
					continue;
				}
			}
		}
		itr++;
	}
}

VOID CPlayerMedal::AddMedalToPlayer(CMedal* poMedal)
{
	if ( NULL == poMedal)
	{
		return ;
	}

	m_mapAllMedal[poMedal->GetMedalID()] = poMedal;
	m_multiMapAllMedal.insert(make_pair(poMedal->GetSmallType(), poMedal));
	if( 0 == poMedal->GetLevel())
	{
		m_mapUnlockMedal[poMedal->GetSmallType()] = poMedal;
	}
	m_mapBuildID.insert(make_pair(poMedal->GetBuildID(), poMedal->GetMedalID()));
	if ( poMedal->IsActivate() )
	{
	
		//�Ƿ�ɵ���
		if ( poMedal->GetIsOverlay() )
		{
			CMultiMapMedalItr itr = m_mapUseMedal.find( poMedal->GetSmallType() );
			if ( itr == m_mapUseMedal.end())
			{
				m_mapUseMedal.insert( make_pair( poMedal->GetSmallType(), poMedal));
			}
			else
			{
				//����ӵ���Դѫ�µȼ�����ԭ������Դѫ�µȼ������滻����ӵ���Դѫ����Ч
				if ( itr->second->GetLevel() < poMedal->GetLevel())
				{
					itr->second = poMedal;
				}
			}
		}
		else
		{
			m_mapUseMedal.insert( make_pair( poMedal->GetSmallType(), poMedal));
		}
	}

}

VOID CPlayerMedal::AddNewMedal()
{
	CShmemMap<UINT8, CBuild>& mapBuild = m_poOwner->GetBuildMap();
	CBuild* poBuild = mapBuild.GetFistData();
	while(poBuild)
	{
		UINT8 byBuildID = poBuild->GetBuildKind();
		UINT16 wSumMedalNum = CMedalPropMgr::Instance()->GetMedalNumByBuildID(byBuildID);
		UINT16 wMyMedalNum = m_mapBuildID.count(byBuildID);
		if ( wMyMedalNum < wSumMedalNum )
		{
			AddNewMedalByBuild(byBuildID);
		}
		poBuild = mapBuild.GetNextData();
	}
}

VOID CPlayerMedal::AddNewMedalByBuild(UINT8 byBuildID)
{
	const C1616MultiMap& mapBuild = CMedalPropMgr::Instance()->GetBuildNumMap();
	pair<C1616MultiMap::const_iterator, C1616MultiMap::const_iterator> pairItr = mapBuild.equal_range(byBuildID);
	CMedal* poMedal = NULL;
	for ( C1616MultiMap::const_iterator itr = pairItr.first; itr != pairItr.second; itr++)
	{
		CMapMedalItr medalItr = m_mapAllMedal.find(itr->second);
		if ( medalItr == m_mapAllMedal.end())
		{
			poMedal = CMedalPropMgr::Instance()->CreateMedal(m_poOwner, itr->second);
			AddMedalToPlayer( poMedal );
		}
	}
}

DT_PLAYER_MEDAL_DATA& CPlayerMedal::GetDT_PLAYER_MEDAL_DATA()
{
	memset( &m_stPlayerMedal, 0, sizeof(DT_PLAYER_MEDAL_DATA));
	m_stPlayerMedal.byHaveDataFlag = 1;
	UINT16 wIdx = 0;
	for ( CMapMedalItr itr = m_mapAllMedal.begin(); itr != m_mapAllMedal.end() && wIdx < MAX_MEDAL_NUM; itr++, wIdx++)
	{
		m_stPlayerMedal.stMealData.astMedalLstData[wIdx] = itr->second->GetMedalData();
	}

	m_stPlayerMedal.stMealData.wMedalNum = wIdx;
	m_stPlayerMedal.qwLastUpdateTime = m_qwLastUpdateTime;
	m_stPlayerMedal.stMedalBaseData = m_stMedalBaseData;
	return m_stPlayerMedal;
}

VOID CPlayerMedal::InitBattleAttr()
{
	m_mapBattleAttrFixed.clear();
	m_mapBattleAttrPercent.clear();
	for ( CMultiMapMedalItr itr = m_mapUseMedal.begin(); itr != m_mapUseMedal.end(); itr++)
	{
		const CVecJsonAttrBase* poVecAttr = NULL;
		if( itr->second->GetMedalAttr(poVecAttr) )
		{
			for ( CVecJsonAttrBase::const_iterator constItr = poVecAttr->begin(); constItr != poVecAttr->end(); constItr++)
			{
				if( EVT_FIX == constItr->byValueType)
				{
					m_mapBattleAttrFixed[constItr->byKindID] += constItr->dwAttrValue;
				}
				else if( EVT_PERCENT == constItr->byValueType)
				{
					m_mapBattleAttrPercent[constItr->byKindID] += constItr->dwAttrValue;
				}
			}
		}
	}
}

//��ȡ���Թ̶�ֵ
const C3232Map& CPlayerMedal::GetBattleAttrFix()
{
	return m_mapBattleAttrFixed;
}
//��ȡ���԰ٷֱ�
const C3232Map& CPlayerMedal::GetBattleAttrPercent()
{
	return m_mapBattleAttrPercent;
}

//���ѫ��
BOOL CPlayerMedal::CheckMedalBySmallType(UINT16 wSmallType)
{
	pair<CMultiMapMedalItr, CMultiMapMedalItr> pairItr = m_multiMapAllMedal.equal_range(wSmallType);
	BOOL bRet = FALSE;
	set<CMedal*> setMedal;
	for ( CMultiMapMedalItr itr = pairItr.first; itr != pairItr.second; itr++)
	{
		if ( !itr->second->IsActivate() )
		{
			if ( itr->second->CheckActivate())
			{
				setMedal.insert(itr->second);
				//�Ƿ�ɵ���
				if ( itr->second->GetIsOverlay() )
				{
					CMultiMapMedalItr findItr = m_mapUseMedal.find( itr->second->GetSmallType() );
					if ( findItr == m_mapUseMedal.end())
					{
						m_mapUseMedal.insert( make_pair( itr->second->GetSmallType(), itr->second));
					}
					else
					{
						//����ӵ���Դѫ�µȼ�����ԭ������Դѫ�µȼ������滻����ӵ���Դѫ����Ч
						if ( findItr->second->GetLevel() < itr->second->GetLevel())
						{
							findItr->second = itr->second;
						}
					}
				}
				else
				{
					m_mapUseMedal.insert( make_pair( itr->second->GetSmallType(), itr->second));
				}
				bRet = TRUE;
			}
		}
	}
	
	if ( 0 != setMedal.size() )
	{
		PKT_CLIGS_MEDAL_NTF stNtf;
		memset(&stNtf, 0, sizeof(stNtf));
		stNtf.stPowerInfo.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
		InitBattleAttr();
		m_poOwner->ResetBattleAttr(TRUE);
		stNtf.stPowerInfo.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
		UINT16 wIdx = 0;
		
		for ( set<CMedal*>::iterator itr = setMedal.begin(); itr != setMedal.end(); itr++, wIdx++ )
		{
			SDStrncpy(stNtf.stUnLockMedal.astMedalIconID[wIdx].aszMedalIconName, (*itr)->GetMedalIconID().c_str(), MAX_NAME_LEN - 1);
		}
		stNtf.stUnLockMedal.wMedalNum = wIdx;
		m_poOwner->SendMsg((CHAR*)&stNtf, CLIGS_MEDAL_NTF);
	}
	return bRet;
}

VOID CPlayerMedal::CheckEveryDay()
{
	if( !IsToday(GetDT_MEDAL_BASE_DATA().qwLastRaceTime))
	{
		SetRaceRank();
		CheckLimitMedal(EMST_RACE);
		m_poOwner->ResetBattleAttr(TRUE);
	}

	CheckLimitMedal(EMST_GVG_MEDAL);
}

//�����ʱѫ��
VOID CPlayerMedal::CheckLimitMedal(MEDAL_SMALL_TYPE eSmallType, BOOL bIsUnActivity)
{
	if ( bIsUnActivity )
	{
		UnActivityMedal(eSmallType);
	}

	set<CMedal*> setMedal;
	for ( CMapMedalItr itr = m_mapAllMedal.begin(); itr != m_mapAllMedal.end(); itr++)
	{
		if( eSmallType == itr->second->GetSmallType())
		{
			//��ѫ��PASS
			if ( itr->second->GetIsOverlay() )
			{
				if ( 0 != m_mapUseMedal.count(eSmallType))
				{
					return ;
				}
			}

			if (  itr->second->CheckActivate()  )
			{
				if ( m_mapUseMedal.end() == m_mapUseMedal.find(itr->second->GetSmallType()))
				{
					setMedal.insert(itr->second);
				}
				AddCanUseMedal(itr->second);
                
                break;
			}
		}
		
	}


	if ( 0 != setMedal.size() )
	{
		PKT_CLIGS_MEDAL_NTF stNtf;
		memset(&stNtf, 0, sizeof(stNtf));
		stNtf.stPowerInfo.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
		InitBattleAttr();
		m_poOwner->ResetBattleAttr(TRUE);
		stNtf.stPowerInfo.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
		UINT16 wIdx = 0;

		for ( set<CMedal*>::iterator itr = setMedal.begin(); itr != setMedal.end(); itr++, wIdx++ )
		{
			SDStrncpy(stNtf.stUnLockMedal.astMedalIconID[wIdx].aszMedalIconName, (*itr)->GetMedalIconID().c_str(), MAX_NAME_LEN - 1);
		}
		stNtf.stUnLockMedal.wMedalNum = wIdx;
		m_poOwner->SendMsg((CHAR*)&stNtf, CLIGS_MEDAL_NTF);
	}
}

BOOL CPlayerMedal::SetRaceRank()
{
	if( !IsToday(GetDT_MEDAL_BASE_DATA().qwLastRaceTime))
	{
		const SPlayerBaseData* poBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(m_poOwner->GetID());
		if ( NULL != poBaseData )
		{
			GetDT_MEDAL_BASE_DATA().dwRaceRank = poBaseData->dwRank;
		}
		GetDT_MEDAL_BASE_DATA().qwLastRaceTime = SDTimeSecs();
		return TRUE;
	}
	return FALSE;
}
//����ʧЧѫ��
VOID CPlayerMedal::DealLostMedal()
{
	for ( CMultiMapMedalItr itr = m_mapUseMedal.begin(); itr != m_mapUseMedal.end(); )
	{
		if ( EMBT_LIMIT_TIME == itr->second->GetBigType())
		{
			CTimeMedal* poTime = static_cast<CTimeMedal*>(itr->second);
			if (  poTime->IsOverTime() )
			{
				m_mapUseMedal.erase(itr++);
				continue;
			}
		}
		itr++;
	}
}
VOID CPlayerMedal::UnActivityMedal(MEDAL_SMALL_TYPE eSmallType)
{
	for ( CMultiMapMedalItr itr = m_mapUseMedal.begin(); itr != m_mapUseMedal.end(); )
	{
		if( eSmallType == itr->second->GetSmallType())
		{
			if( itr->second->SetActivateState(FALSE))
			{
				m_mapUseMedal.erase(itr++);
				continue;
			}
		}
		itr++;
	}
	InitBattleAttr();
}

//��������Чѫ��
VOID CPlayerMedal::DealEffectMedal()
{
	for ( CMapMedalItr itr = m_mapAllMedal.begin(); itr != m_mapAllMedal.end(); itr++)
	{
		if ( EMBT_NONE_TIME == itr->second->GetBigType())
		{
			if( itr->second->CheckActivate() )
			{
				//�Ƿ�ɵ���
				if ( itr->second->GetIsOverlay() )
				{
					CMultiMapMedalItr findItr = m_mapUseMedal.find( itr->second->GetSmallType() );
					if ( findItr == m_mapUseMedal.end())
					{
						m_mapUseMedal.insert( make_pair( itr->second->GetSmallType(), itr->second));
					}
					else
					{
						//����ӵ���Դѫ�µȼ�����ԭ������Դѫ�µȼ������滻����ӵ���Դѫ����Ч
						if ( findItr->second->GetLevel() < itr->second->GetLevel())
						{
							findItr->second = itr->second;
						}
					}
				}
				else
				{
					m_mapUseMedal.insert( make_pair( itr->second->GetSmallType(), itr->second));
				}
			}
		}
	}
}
VOID CPlayerMedal::AddCanUseMedal(CMedal* poMedal)
{

	if ( poMedal->GetIsOverlay() )
	{
		CMultiMapMedalItr itr = m_mapUseMedal.find(poMedal->GetSmallType());
		if ( itr != m_mapUseMedal.end())
		{
			if ( poMedal->GetLevel() <= itr->second->GetLevel())
			{
				itr->second = poMedal;
				return ;
			}
		}
	}

	m_mapUseMedal.insert(make_pair(poMedal->GetSmallType(), poMedal));
}

UINT16 CPlayerMedal::OnOpenMyMedal(PKT_CLIGS_OPEN_MY_MEDAL_ACK& stAck)
{
	C3232MapItr itr;
	UINT8 byIdx = 0;
	//�̶�ֵ
	for ( itr = m_mapBattleAttrFixed.begin(); itr != m_mapBattleAttrFixed.end() && byIdx < MAX_SCIENCE_ATTR_NUM; itr++, byIdx++)
	{
		stAck.stAttrInfo.astAttrInfo[byIdx].byKindID = itr->first;
		stAck.stAttrInfo.astAttrInfo[byIdx].byValueType = EVT_FIX;
		stAck.stAttrInfo.astAttrInfo[byIdx].dwAttrValue = itr->second;
	}
	//�ٷֱ�
	for ( itr = m_mapBattleAttrPercent.begin(); itr != m_mapBattleAttrPercent.end() && byIdx < MAX_SCIENCE_ATTR_NUM; itr++, byIdx++)
	{
		stAck.stAttrInfo.astAttrInfo[byIdx].byKindID = itr->first;
		stAck.stAttrInfo.astAttrInfo[byIdx].byValueType = EVT_PERCENT;
		stAck.stAttrInfo.astAttrInfo[byIdx].dwAttrValue = itr->second;
	}
	stAck.stAttrInfo.byAttrNum = byIdx;
	UINT16 wIdx = 0;
	//��Ч��ѫ��
	for ( CMultiMapMedalItr multiItr = m_mapUseMedal.begin(); multiItr != m_mapUseMedal.end() && wIdx < MAX_MEDAL_NUM; multiItr++, wIdx++)
	{
		multiItr->second->GetMedalCli(stAck.stMedalLstInfo.astMedalInfo[wIdx]);
		m_mapUnlockMedal.erase(multiItr->second->GetSmallType());
	}
	//δ�����ѫ��
	for (CMapMedalItr itr = m_mapUnlockMedal.begin(); itr != m_mapUnlockMedal.end() && wIdx < MAX_MEDAL_NUM; itr++, wIdx++)
	{
		itr->second->GetMedalCli(stAck.stMedalLstInfo.astMedalInfo[wIdx]);
	}
	stAck.stMedalLstInfo.wMedalNum = wIdx;
	return ERR_OPEN_MY_MEDAL::ID_SUCCESS;
}

VOID CPlayerMedal::GetUseMedal(DT_MEDAL_DATA_LST_CLI& stCli)
{
	UINT16 wIdx = 0;
	for ( CMultiMapMedalItr multiItr = m_mapUseMedal.begin(); multiItr != m_mapUseMedal.end() && wIdx < MAX_MEDAL_NUM; multiItr++, wIdx++)
	{
		multiItr->second->GetMedalCli(stCli.astMedalInfo[wIdx]);
	}
	stCli.wMedalNum = wIdx;
}

BOOL CPlayerMedal::CheckMedalByLogin()
{
	m_mapUseMedal.erase(EMST_LOGIN_DAY);
	pair<CMultiMapMedalItr, CMultiMapMedalItr> pairItr = m_multiMapAllMedal.equal_range(EMST_LOGIN_DAY);
	for ( CMultiMapMedalItr itr = pairItr.first; itr != pairItr.second; itr++)
	{
		if ( itr->second->CheckActivate() )
		{
			itr->second->SetActivateState(TRUE);
			CMultiMapMedalItr findItr = m_mapUseMedal.find( itr->second->GetSmallType() );
			if ( findItr == m_mapUseMedal.end())
			{
				m_mapUseMedal.insert( make_pair( itr->second->GetSmallType(), itr->second));
			}
			else
			{
				//����ӵ���Դѫ�µȼ�����ԭ������Դѫ�µȼ������滻����ӵ���Դѫ����Ч
				if ( findItr->second->GetLevel() < itr->second->GetLevel())
				{
					findItr->second = itr->second;
				}
			}
		}
		else
		{
			itr->second->SetActivateState(FALSE);
		}
	}
	return FALSE;
}

VOID CPlayerMedal::ContinueLogin()
{
	//if ( !IsToday(m_stMedalBaseData.qwLoginTime))
	//{
	//	CSDDateTime oDate(m_stMedalBaseData.qwLoginTime);
	//	CSDDateTime oCurDate = SDNow();
	//	UINT32 dwDay = static_cast<UINT32>(oCurDate.DiffDay(oDate));
	//	if ( 1 ==  dwDay)
	//	{
	//		m_stMedalBaseData.dwLoginDayNum++;
	//	}
	//	else
	//	{
	//		dwDay--;
	//		m_stMedalBaseData.dwLoginDayNum = (m_stMedalBaseData.dwLoginDayNum < dwDay ? 0 : m_stMedalBaseData.dwLoginDayNum - dwDay);
	//	}
	//	m_stMedalBaseData.qwLoginTime = SDTimeSecs();
	//}
}

//���㹺������
VOID CPlayerMedal::AddBuyPhystrength()
{
	m_stMedalBaseData.dwBuyPhystrength++;
}
//��ɮ
VOID CPlayerMedal::AddEscortNum()
{
//	m_stMedalBaseData.dwEscortNum++;
}
//�������ش���
VOID CPlayerMedal::AddInterceptNum()
{
	//m_stMedalBaseData.dwInterceptNum++;
}
//�вƴ���
VOID CPlayerMedal::AddRankMoneyNum()
{
	m_stMedalBaseData.dwRockMoneyNum++;
}
//��ͨ�ۻ����
VOID CPlayerMedal::AddNormalGatherNum()
{
//	m_stMedalBaseData.dwNormalGatherNum++;
}
//Ԫ���ۻ����
VOID CPlayerMedal::AddGoldGatherNum()
{
//	m_stMedalBaseData.dwGoldGatherNum++;
}
//Ĥ��1�������
VOID CPlayerMedal::AddWorshipPlayer1Num()
{
//	m_stMedalBaseData.dwWorshipPlayer1Num++;
}
//Ĥ��2�������
VOID CPlayerMedal::AddWorshipPlayer2Num()
{
	//m_stMedalBaseData.dwWorshipPlayer2Num++;
}
//Ĥ��3�������
VOID CPlayerMedal::AddWorshipPlayer3Num()
{
	//m_stMedalBaseData.dwWorshipPlayer3Num++;
}
//����1�������
VOID CPlayerMedal::AddWorshipGod1Num()
{
//	m_stMedalBaseData.dwWorshipGod1Num++;
}
//����2�������
VOID CPlayerMedal::AddWorshipGod2Num()
{
	//m_stMedalBaseData.dwWorshipGod2Num++;
}
//����3�������
VOID CPlayerMedal::AddWorshipGod3Num()
{
	//m_stMedalBaseData.dwWorshipGod3Num++;
}
//����ʦ���Դ���
VOID CPlayerMedal::AddZTSNum()
{
//	m_stMedalBaseData.dwZTSNum++;
}
//Ц������
VOID CPlayerMedal::AddSmileNum(UINT32 dwSmileNum)
{
	//m_stMedalBaseData.dwSmileNum += dwSmileNum;
}
//С����ץ������
VOID CPlayerMedal::AddArrestNum()
{
	//m_stMedalBaseData.dwArrestNum++;
}
//С�ڲ����ϴ���
VOID CPlayerMedal::AddDriveNum()
{
	//m_stMedalBaseData.dwDriveNum++;
}
//�������ô���
VOID CPlayerMedal::AddTowerResetNum()
{
	//m_stMedalBaseData.dwTowerResetNum++;
}
//��Ӣ�������ô���
VOID CPlayerMedal::AddEliteInstanceResetNum()
{
	//m_stMedalBaseData.dwEliteInstanceResetNum++;
}

VOID CPlayerMedal::AddGVECourageNum()
{
	//m_stMedalBaseData.dwGVEJoinNum++;
}