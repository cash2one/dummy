#include "hotspring.h"
#include <logic/faction/factionmgr.h>
#include <logic/hotspring/hotspringpropmgr.h>
#include <logic/player/playermgr.h>
#include <logic/event/timereventmgr.h>
#include <logic/other/errmsgmgr.h>
#include <logic/other/locale.h>
#include "logic/other/singleprammgr.h"
#include "logic/lua/luamgr.h"
#include "logic/hero/hero.h"
BOOL CHotSpring::Init(DT_HOT_SPRING_DATA& stHotSpringData, CPlayer* poOwner, DT_HOT_SPRING_EXT_DATA& stExt)
{
	memcpy(&m_stHotSpringData, &stHotSpringData, sizeof(DT_HOT_SPRING_DATA));
	memcpy(&m_stHotSpringExt, &stExt, sizeof(DT_HOT_SPRING_EXT_DATA));
	m_poOwner = poOwner;
	CFaction* poFaction = GetFaction();
	if (NULL != poFaction)
	{
		DT_FACTION_PLAYER_DATA* stData = poFaction->GetDT_Faction_Player_Data(m_poOwner->GetID());
		if (NULL == stData)
		{
			return FALSE;
		}
		if (ESM_YES == stData->byDrinkFlag)
		{
			AfterGiveWineProc();
		}
		stData->byDrinkFlag = ESM_NO;
	}
	
	return TRUE;
}

CFaction* CHotSpring::GetFaction()
{
	UINT32 dwFactionID = 0;
	BOOL bRet = CFaction::CkFactionPlayerData(dwFactionID, m_poOwner->GetID());
	if ( !bRet )
	{
		return NULL;
	}
	return CFactionMgr::Instance()->GetFaction(dwFactionID);
}
UINT32 CHotSpring::GetFactionID()
{
	UINT32 dwFactionID = 0;
	BOOL bRet = CFaction::CkFactionPlayerData(dwFactionID, m_poOwner->GetID());
	if ( !bRet )
	{
		return NULL;
	}
	return dwFactionID;
}

VOID CHotSpring::WriteDownPosition(UINT16 wPosX, UINT16 wPosY)
{
	//�޼�¼ʱ������λ����Ϣ
	if (0 == m_stHotSpringData.stPlayerPosInfo.wPosX && 0 == m_stHotSpringData.stPlayerPosInfo.wPosY)
	{
		m_stHotSpringData.stPlayerPosInfo.wPosX = wPosX;
		m_stHotSpringData.stPlayerPosInfo.wPosY = wPosY;
	}
	//���������������
	else
	{
		//TODO
	}
}

UINT16 CHotSpring::OnOpenHotSpring(PKT_CLIGS_OPEN_HOT_SPRING_ACK& stAck)
{
	CFaction* poFaction = GetFaction();
	CheckByEveryTime();

	if ( NULL == poFaction)
	{
		return ERR_OPEN_HOT_SPRING::ID_FACTION_NOT_EXIST;
	}
	
	BOOL bRet = IsOpen();
	if ( !bRet )
	{
		return ERR_OPEN_HOT_SPRING::ID_HOT_SPRING_NOT_EXIST;
	}

	if ( ESM_NO == CSinglePramMgr::Instance()->GetHotSpringFlag())
	{
		//�����ʱ���루��˹����ɾ����
		return ERR_OPEN_HOT_SPRING::ID_HOT_SPRING_NOT_EXIST;
	}

	//���뼯�ϱ�ʾ��������Ȫ��
	CFactionMgr::Instance()->AddSetHotSpringPlayerID(m_poOwner->GetID());

	SetHotSpringSelfData(stAck.stPlayerSelf);

	SetHotSpringPlayerList(stAck.stPlayerInfo);
	DT_HOT_SPRING_TIME_DATA& stHotSpringTimeData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;

	//�����ϴ�δ�Ⱦ�״̬
	stAck.byBeforeWineState = m_stHotSpringData.byLastDrinkWineState;

	if (0 != m_stHotSpringData.stWineInfo.dwWineID && m_stHotSpringData.stWineInfo.byLeftDrinkNum !=0)
	{
		m_stHotSpringData.qwFirstDrinkTime = SGDP::SDTimeSecs();
	//	AddDrinkEvent();
	}

	if ( ESM_YES == stHotSpringTimeData.byGiveWineOpenState )
	{
		//byBeforeWineState = ESM_NO;
		//�����Ƿ�������״̬
		//������
		if (ESM_YES == m_stHotSpringData.byDrinkWineState)
		{

			stAck.byGiveWineState = GIVE_WINE_DRINK;
			SetDrinkWineData(stAck.stWineDataCli);
		}
		else
		{
			//����δ���ƼӲμӻ
			if ( 0 == m_stHotSpringExt.byDrinkTime )
			{
				m_stHotSpringData.byIsJoinCurActivity = ESM_NO;
			}

			if(!m_stHotSpringData.byIsJoinCurActivity)
			{
				stAck.byGiveWineState = GIVE_WINE_NOT_DRINK;
			}
			else
			{
				stAck.byGiveWineState = GIVE_WINE_FINISH;
			}
		}

		
		SGiveWineProp stGiveWineProp = {0};
		CHotSpringPropMgr::Instance()->GetGiveWinePropByFactionLevel(poFaction->GetDT_FACTION_BASE_DATA().dwFactionLevel, stGiveWineProp);
		UINT32 dwKeepTime = stGiveWineProp.dwKeepTime;
		UINT32 dwCurTimeSec = static_cast<UINT32>(SGDP::SDTimeSecs());
		if (  dwCurTimeSec < stHotSpringTimeData.qwGiveWineOpenTime + dwKeepTime)
		{
			stAck.qwActiviTime = stHotSpringTimeData.qwGiveWineOpenTime + dwKeepTime - dwCurTimeSec;
		}
		else
		{
			stAck.qwActiviTime = 0;
		}
	}
	else
	{
		//�Ƿ���δ����ľ�
		if (ESM_YES == m_stHotSpringData.byDrinkWineState)
		{
			stAck.byGiveWineState = NOT_GIVE_WINE_DRINK;
			SetDrinkWineData(stAck.stWineDataCli);
		}
		else
		{
			stAck.byGiveWineState = NOT_GIVE_WINE_NOT_DRINK;
		}
	}

	stAck.byHaveOverReward = m_stHotSpringData.byHaveOverReward;
	stAck.stOverReward = m_stHotSpringData.stOverReward;
	//0�Ӻ�̨���룬 1���½���
	if ( Enter_Normal == m_stHotSpringExt.byEnterHotSpringType)
	{
		//������Ȫʱ��
		m_stHotSpringExt.qwLastEnterTime = SGDP::SDTimeSecs();
		m_stHotSpringExt.byEnterHotSpringType = Enter_Back;
	}
	GetExprience(stAck.stPlayerExprience, SGDP::SDTimeSecs());
	//������Ȫλ�ü�¼
	m_poOwner->GetLocale().OnEnterHotSpring();
	return ERR_OPEN_HOT_SPRING::ID_SUCCESS;
}

VOID CHotSpring::CheckByEveryTime()
{
	CFaction* poFaction = GetFaction();
	if (NULL == poFaction)
	{
		return;
	}
	
	if ( !IsToday(m_stHotSpringData.qwUpgradeTime))
	{
		m_stHotSpringData.byTodayBackTime = 0;
		m_stHotSpringData.byIsIgnorePrompt = 0;
		m_stHotSpringExt.byDrinkTime = 0;
		m_stHotSpringExt.byFindBackTime = 0;
		m_stHotSpringData.qwUpgradeTime = SGDP::SDTimeSecs();
	}

	
	DT_HOT_SPRING_TIME_DATA& stHotSpringTimeData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;

	//2.�оƣ�����Ƿ�ȹ�

	ResetTimeByWine();

	if ( ESM_NO == stHotSpringTimeData.byGiveWineOpenState )
	{
		if ( 0 != m_stHotSpringData.stWineInfo.dwWineID )
		{
			memset(&m_stHotSpringData.stWineInfo, 0, sizeof(m_stHotSpringData.stWineInfo));
			m_stHotSpringData.byDrinkWineState = ESM_NO;
		}
	}
}

VOID CHotSpring::ResetTimeByWine()
{
	CFaction* poFaction = GetFaction();
	if (NULL == poFaction)
	{
		return ;
	}
	DT_HOT_SPRING_TIME_DATA& stFactionHotSpring = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;;
	if ( !IsToday(stFactionHotSpring.qwGiveWineOpenTime))
	{
		stFactionHotSpring.byTodayOpenNum = 0;
	}
	//�о�
	if ( 0 != m_stHotSpringData.stWineInfo.dwWineID)
	{
		SWinePropMap& stWineProp = CHotSpringPropMgr::Instance()->GetWinePropMap();
		SWinePropItr it = stWineProp.find(m_stHotSpringData.stWineInfo.dwWineID);

		if (it == stWineProp.end())
		{
			return ;
		}
		//����û����
		if ( m_stHotSpringData.stWineInfo.byLeftDrinkNum != 0)
		{
			UINT64 qwDrinkTime = SGDP::SDTimeSecs() - m_stHotSpringData.qwFirstDrinkTime;
			UINT64 qwPassTime = qwDrinkTime + m_stHotSpringData.dwDrinkKeepTime;
			UINT32 dwDrinkKeepTime = m_stHotSpringData.stWineInfo.dwDrinkWineCD * m_stHotSpringData.stWineInfo.dwDrinkMaxTime;
			//�ȾƵ���ʱ
			if ( qwPassTime < dwDrinkKeepTime )
			{
				m_stHotSpringData.stWineInfo.dwCountDown = dwDrinkKeepTime - static_cast<UINT32>(qwPassTime);
			}
			else
			{
				m_stHotSpringData.stWineInfo.dwCountDown = 0;
			}
		}
		else
		{
			m_stHotSpringData.byDrinkWineState = ESM_NO;
		}
	}
}

VOID CHotSpring::SetHotSpringSelfData(DT_HOT_SPRING_SELF_DATA_CLI& stPlayerSelf)
{
	CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(m_poOwner->GetID());
	if (NULL == poPlayer)
	{
		return ;
	}
	CFaction* poFaction = GetFaction();
	if (NULL == poFaction)
	{
		return;
	}
	stPlayerSelf.qwCurCoin = poPlayer->GetDT_PLAYER_BASE_DATA().qwCoin;
	stPlayerSelf.qwCurGold = poPlayer->GetDT_PLAYER_BASE_DATA().qwGold;
	stPlayerSelf.qwCurSkill = poPlayer->GetDT_PLAYER_BASE_DATA().qwPurpleGas;
	stPlayerSelf.qwCurPhystrength = poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength;
	stPlayerSelf.wPosX = m_stHotSpringData.stPlayerPosInfo.wPosX;
	stPlayerSelf.wPosY = m_stHotSpringData.stPlayerPosInfo.wPosY;
	DT_FACTION_PLAYER_CLI stFactionSelf = {0};
	poFaction->GetDT_FACTION_PLAYER_CLI_SELF(stFactionSelf, m_poOwner->GetID());
	stPlayerSelf.byGiveWineLimit = CFactorAuthorityPropMgr::Instance()->CkJobAuthority((em_Faction_Job)stFactionSelf.byJobType, EFA_Activity);
	//��������
	stPlayerSelf.qwMaxPhystrength = MAXPHYSTRENGTH;
}

VOID CHotSpring::SetHotSpringPlayerList(DT_HOT_SPRING_PLAYER_DATA_CLI_LST& stPlayerInfo)
{
	UINT32 dwFactionID = GetFactionID();
	CFactionMgr::Instance()->SetHotSpringPlayerList(stPlayerInfo, dwFactionID);
}

UINT16 CHotSpring::OnSelectWine(UINT32 dwWineID, UINT64& qwCoin, UINT64& qwGold, DT_WINE_DATA_CLI& stWineDataCli, UINT8& byState)
{
	CheckByEveryTime();

	BOOL bRet = IsOpen();
	if ( !bRet )
	{
		return ERR_SELECT_WINE::ID_HOT_SPRING_NOT_EXIST;
	}
	CFaction* poFaction = GetFaction();
	if ( NULL == poFaction)
	{
		return ERR_SELECT_WINE::ID_FACTION_NOT_EXIST;
	}
	UINT32 dwFactionLevel = poFaction->GetDT_FACTION_BASE_DATA().dwFactionLevel;
	SGiveWineProp stProp = {0};
	CHotSpringPropMgr::Instance()->GetGiveWinePropByFactionLevel(dwFactionLevel, stProp);
	
	if ( (stProp.byTodayOpenNum + 1) < m_stHotSpringExt.byFindBackTime)
	{
		return ERR_SELECT_WINE::ID_ALREAD_DRINK;
	}

	if ( stProp.byTodayOpenNum <= m_stHotSpringExt.byDrinkTime)
	{
		return ERR_SELECT_WINE::ID_ALREAD_DRINK;
	}

	UINT16 wRet = OnSelectWineMain(dwWineID, qwCoin, qwGold);
	stWineDataCli = m_stHotSpringData.stWineInfo;
	stWineDataCli.dwCountDown = m_stHotSpringData.stWineInfo.dwDrinkWineCD * m_stHotSpringData.stWineInfo.dwDrinkMaxTime;
	//ѡ���ȷ�ϲμӻ
	if ( ERR_SELECT_WINE::ID_SUCCESS == wRet )
	{
		//�ǲμӻ
		if ( ESM_YES == m_stHotSpringData.byActivityStat)
		{
			m_stHotSpringData.byIsJoinCurActivity = ESM_YES;
			byState = ESM_NO;
			m_stHotSpringData.byDrinkWineState = ESM_YES;
			m_stHotSpringData.qwFirstDrinkTime = SGDP::SDTimeSecs();
			CTimerEventMgr::Instance()->AddDrinkWineEvent(m_poOwner->GetID(), m_stHotSpringData.stWineInfo.dwDrinkWineCD);
			m_stHotSpringExt.byDrinkTime += 1;
		}
		else
		{
			byState = ESM_YES;
			//�һ����Ʊ�ʶΪ û��
			m_stHotSpringData.byLastDrinkWineState = ESM_NO;
			m_stHotSpringData.byTodayBackTime += 1;
			m_poOwner->AddReward(stWineDataCli.byRewardID1, stWineDataCli.dwRewardValue1, CRecordMgr::EAPST_DRINKWINE);
			m_poOwner->AddReward(stWineDataCli.byRewardID2, stWineDataCli.dwRewardValue2, CRecordMgr::EAPGT_DRINK_WINE);
			m_stHotSpringExt.byFindBackTime += 1;
		}
		
	}
	return wRet;
}

//ѡ������
UINT16 CHotSpring::OnSelectWineMain(UINT32 dwWineID, UINT64& qwCoin, UINT64& qwGold)
{

	memset(&m_stHotSpringData.stWineInfo, 0, sizeof(m_stHotSpringData.stWineInfo));

	if ( ESM_YES == m_stHotSpringData.byDrinkWineState)
	{
		return ERR_SELECT_WINE::ID_WINE_IS_DRINKING;
	}
	CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(m_poOwner->GetID());
	if (NULL == poPlayer)
	{
		return ERR_SELECT_WINE::ID_PLAYER_ID_NOT_FIND;
	}

	SWinePropMap& mapWineProp = CHotSpringPropMgr::Instance()->GetWinePropMap();
	SWinePropItr mapIt = mapWineProp.find(dwWineID);
	if ( mapIt == mapWineProp.end())
	{
		return ERR_SELECT_WINE::ID_WINE_NOT_EXIST;
	}

	DT_WINE_DATA_CLI& stWineProp = mapIt->second;
	const DT_PLAYER_BASE_DATA& stPlayerBaseData = poPlayer->GetDT_PLAYER_BASE_DATA();
	if( stPlayerBaseData.byVipLevel < stWineProp.byNeedVIPLevel )
	{
		return ERR_SELECT_WINE::ID_VIP_LEVEL_NOT_ENOUGH;
	}
	//ͭǮ
	if ( ACTE_COIN == stWineProp.byCostType )
	{
		if ( stPlayerBaseData.qwCoin < stWineProp.dwCostValue )
		{
			return ERR_SELECT_WINE::ID_COIN_NOT_ENOUGH;
		}
		//�۳�ͭǮ
		poPlayer->DecCoin(stWineProp.dwCostValue, CRecordMgr::EDCT_DRINK_WINE);

	}
	//Ԫ��
	else if(ACTE_GOLD == stWineProp.byCostType)
	{
		if ( stPlayerBaseData.qwGold < stWineProp.dwCostValue)
		{
			return ERR_SELECT_WINE::ID_GOLD_NOT_ENOUGH;
		}
		//�۳�Ԫ��
		poPlayer->DecGold(stWineProp.dwCostValue, CRecordMgr::EDGT_DRINK_WINE);
	}

	m_stHotSpringData.stWineInfo = stWineProp;
	//ѡ�ƺ���Ϊ0
	m_stHotSpringData.qwFirstDrinkTime = SGDP::SDTimeSecs();
	qwCoin = stPlayerBaseData.qwCoin;
	qwGold = stPlayerBaseData.qwGold;

	return ERR_SELECT_WINE::ID_SUCCESS;
}

//�ƶ���¼
UINT16 CHotSpring::OnDrinkWineMove(UINT16 wPosX, UINT16 wPosY)
{
	GetFaction();
	if (wPosY != m_stHotSpringData.stPlayerPosInfo.wPosY || wPosX != m_stHotSpringData.stPlayerPosInfo.wPosX)
	{
		m_stHotSpringData.stPlayerPosInfo.wPosX = wPosX;
		m_stHotSpringData.stPlayerPosInfo.wPosY = wPosY;
		m_stHotSpringData.stPlayerPosInfo.byMoveState = ESM_YES;
		CFactionMgr::Instance()->AddSetHotSpringPlayerID(m_poOwner->GetID());
	}
	return ERR_DRINK_WINE_MOVE::ID_SUCCESS;
}

VOID CHotSpring::LeaveHotSpring()
{
	GetFaction();
	CFactionMgr::Instance()->DelSetHotSpringPlayerID(m_poOwner->GetID());
	m_stHotSpringData.stPlayerPosInfo.wPosX = 0;
	m_stHotSpringData.stPlayerPosInfo.wPosY = 0;
	CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(m_poOwner->GetID());
	if (NULL == poPlayer)
	{
		return ;
	}
	//�뿪��Ȫ
	poPlayer->GetLocale().OnLeaveHotSpring();
	//WorkOutDrinkPassTime();
	//RemoveEvent
	//CTimerEventMgr::Instance()->DelDrinkWineEvent(m_poOwner->GetID());
	//�����þ���ʱ��
	m_stHotSpringExt.qwExprienceTime = SGDP::SDTimeSecs() - m_stHotSpringExt.qwLastEnterTime + m_stHotSpringExt.qwExprienceTime;
	m_stHotSpringExt.qwLastEnterTime = SGDP::SDTimeSecs();
	m_stHotSpringExt.byEnterHotSpringType = Enter_Normal;
}

VOID CHotSpring::WorkOutDrinkPassTime()
{
	GetFaction();
	if (0 != m_stHotSpringData.stWineInfo.dwWineID)
	{
		m_stHotSpringData.dwDrinkKeepTime += static_cast<UINT32>(SGDP::SDTimeSecs() - m_stHotSpringData.qwFirstDrinkTime);
	}

}

UINT16 CHotSpring::GiveWine( DT_DIDNOT_GIVE_WINE_CLI& stGiveWineInfo)
{
	CFaction* poFaction = GetFaction();
	CheckByEveryTime();
	if (NULL == poFaction)
	{
		return ERR_GIVE_WINE::ID_FACTION_NOT_EXIST;
	}

	BOOL bRet = IsOpen();
	if ( !bRet )
	{
		return ERR_GIVE_WINE::ID_HOT_SPRING_NOT_EXIST;
	}
	DT_HOT_SPRING_TIME_DATA& stHotSpringTimeData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;

	if ( ESM_YES == stHotSpringTimeData.byGiveWineOpenState )
	{
		return ERR_GIVE_WINE::ID_GIVE_WINE_IS_OPEN;
	}

	UINT8 byGiveWineLimit = CFactionMgr::Instance()->CheckPlayerAuthority(m_poOwner->GetID(), EFA_Activity);
	if (0 == byGiveWineLimit)
	{
		return ERR_GIVE_WINE::ID_LIMIT_NOT_ENOUGH;
	}

	return  SetGiveWineData(stGiveWineInfo);

}

UINT16 CHotSpring::SetGiveWineData(DT_DIDNOT_GIVE_WINE_CLI& stGiveWineCLi)
{
	CFaction* poFaction = GetFaction();
	if (NULL == poFaction)
	{
		return ERR_GIVE_WINE::ID_FACTION_NOT_EXIST;
	}
	const DT_HOT_SPRING_TIME_DATA& stHotSpringTime = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;
	SGiveWineProp stGiveWineProp = {0};
	CHotSpringPropMgr::Instance()->GetGiveWinePropByFactionLevel(poFaction->GetDT_FACTION_BASE_DATA().dwFactionLevel, stGiveWineProp);

	UINT8 byCanOpenNum = stGiveWineProp.byTodayOpenNum;
	UINT8 byOpenNum = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData.byTodayOpenNum;
	if ( byCanOpenNum <= byOpenNum)
	{
		return ERR_GIVE_WINE::ID_NOT_ACTIVI_TIME;
	}
	else
	{
		stGiveWineCLi.byLeftGiveWineNum = byCanOpenNum - byOpenNum;
		stGiveWineCLi.dwGiveWineCost = stGiveWineProp.dwOpenCost;

		UINT64 qwCurTime = SGDP::SDTimeSecs();
		if (qwCurTime < stHotSpringTime.qwGiveWineOpenTime + stGiveWineProp.dwIntegralTime)
		{
			stGiveWineCLi.dwGiveWineCountDown = static_cast<UINT32>(stHotSpringTime.qwGiveWineOpenTime) + 
				stGiveWineProp.dwIntegralTime - static_cast<UINT32>(qwCurTime);
			UINT32 dwInterval = stGiveWineProp.dwIntegralTime;
			UINT32 dwKeepTime = stGiveWineProp.dwKeepTime;
			if (dwInterval < dwKeepTime)
			{
				stGiveWineCLi.dwGiveWineCDValue = 0;
			}
			else
			{
				stGiveWineCLi.dwGiveWineCDValue = dwInterval - dwKeepTime;
			}
			return ERR_GIVE_WINE::ID_TIME_NOT_ENOUGH;
		}
		else
		{
			stGiveWineCLi.dwGiveWineCountDown = 0;
		}
	}
	return ERR_GIVE_WINE::ID_SUCCESS;
}

UINT16 CHotSpring::ClickSelectWineGiveWine(UINT8 byDrinkWineState, DT_DIDNOT_DRINGK_WINE_LIST_CLI& stWineDataList)
{
	CFaction* poFaction = GetFaction();
	CheckByEveryTime();

	if ( NULL == poFaction)
	{
		return ERR_CLICK_SELECT_WINE::ID_FACTION_NOT_EXIST;
	}

	BOOL bRet = IsOpen();
	if ( !bRet)
	{
		return ERR_CLICK_SELECT_WINE::ID_HOT_SPRING_NOT_EXIST;
	}

	if( ESM_YES == m_stHotSpringData.byDrinkWineState)
	{
		return ERR_CLICK_SELECT_WINE::ID_WINE_IS_DRINKING; 
	}
	//1 Ϊ�һ�����
	if ( ESM_YES == byDrinkWineState)
	{
		if ( ESM_NO == m_stHotSpringData.byLastDrinkWineState)
		{
			return ERR_CLICK_SELECT_WINE::ID_NOT_FIND_DRINK;
		}
		DT_HOT_SPRING_TIME_DATA& stHotSpringTimeData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;
		if ( ESM_YES == stHotSpringTimeData.byGiveWineOpenState )
		{
			return ERR_CLICK_SELECT_WINE::ID_NOW_CAN_NOT_SELECT;
		}
		//���ǻ��ʶ
		m_stHotSpringData.byActivityStat = ESM_NO;
	}
	else
	{
		//���ʶ
		m_stHotSpringData.byActivityStat = ESM_YES;
	}
	SetWineInfoAll(stWineDataList);

	return ERR_CLICK_SELECT_WINE::ID_SUCCESS;
}

VOID CHotSpring::SetWineInfoAll(DT_DIDNOT_DRINGK_WINE_LIST_CLI& stDidDrinkWineData)
{
	SWinePropMap& mapWineProp = CHotSpringPropMgr::Instance()->GetWinePropMap();
	stDidDrinkWineData.byWineNum = mapWineProp.size();
	UINT8 byIndex = 0;
	for ( SWinePropItr mapIt = mapWineProp.begin(); mapIt != mapWineProp.end(); mapIt++)
	{
		stDidDrinkWineData.astAllWineInfo[byIndex] = mapIt->second;

		byIndex++;
	}
	string strMsg = CMsgDefMgr::Instance()->GetErrMsg("SELECT_WINE_MSG");
	SDStrncpy(stDidDrinkWineData.aszExtMsg, strMsg.c_str(), sizeof(stDidDrinkWineData.aszExtMsg));
}

UINT16 CHotSpring::SureGiveWine(UINT64& qwActiviTime)
{
	CFaction* poFaction = GetFaction();
	UINT32 dwFactionID = GetFactionID();
	CheckByEveryTime();
	if ( ESM_NO == CSinglePramMgr::Instance()->GetHotSpringFlag())
	{
		//�����ʱ���루��˹����ɾ����
		return ERR_SURE_GIVE_WINE::ID_HOT_SPRING_NOT_EXIST;
	}
	if (NULL == poFaction)
	{
		return ERR_SURE_GIVE_WINE::ID_FACTION_NOT_EXIST;
	}

	BOOL bRet = IsOpen();
	if ( !bRet )
	{
		return ERR_SURE_GIVE_WINE::ID_HOT_SPRING_NOT_EXIST;
	}

	DT_HOT_SPRING_TIME_DATA& stHotSpringTimeData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;
	SGiveWineProp stGiveWineProp = {0};
	CHotSpringPropMgr::Instance()->GetGiveWinePropByFactionLevel(poFaction->GetDT_FACTION_BASE_DATA().dwFactionLevel, stGiveWineProp);

	if ( SGDP::SDTimeSecs() < stHotSpringTimeData.qwGiveWineOpenTime + stGiveWineProp.dwIntegralTime  )
	{
		return ERR_SURE_GIVE_WINE::ID_CD_TIME_NOT_ENOUGH;
	}

	if ( ESM_YES == stHotSpringTimeData.byGiveWineOpenState )
	{
		return ERR_GIVE_WINE::ID_GIVE_WINE_IS_OPEN;
	}

	UINT8 byCanOpenNum = stGiveWineProp.byTodayOpenNum;
	UINT8& byOpenNum = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData.byTodayOpenNum;
	if ( byCanOpenNum <= byOpenNum)
	{
		return ERR_SURE_GIVE_WINE::ID_ACTIVITY_TIME_NOT_ENOUGH;
	}

	if( poFaction->GetDT_FACTION_BASE_DATA().dwFactionFunds < stGiveWineProp.dwOpenCost)
	{
		return ERR_SURE_GIVE_WINE::ID_FACTION_FUNDS_NOT_ENOUGH;
	}
	//�۳������ʽ�
	poFaction->DecFactionFunds(stGiveWineProp.dwOpenCost, CRecordMgr::EDFF_OPEN_HOTSPRING);
	//�����;�
	stHotSpringTimeData.byGiveWineOpenState = ESM_YES;
	//����ʱ��
	stHotSpringTimeData.qwGiveWineOpenTime = SGDP::SDTimeSecs();
	byOpenNum++;
	qwActiviTime = stGiveWineProp.dwKeepTime;
	UINT32 dwInterval = stGiveWineProp.dwKeepTime;
	CTimerEventMgr::Instance()->AddGiveWineEvent(dwFactionID, dwInterval);
	
	//��־
	DT_FACTION_LOG_DATA stFactionLogData;
	stFactionLogData.dwPlayerID1 = m_poOwner->GetID();
	DT_FACTION_PLAYER_CLI stFactionPlayerCli = {0};
	poFaction->GetDT_FACTION_PLAYER_CLI_SELF(stFactionPlayerCli, m_poOwner->GetID());
	stFactionLogData.byPlayerJobType1 = stFactionPlayerCli.byJobType;
	stFactionLogData.byAction = EFLID_OpenActivity;
	stFactionLogData.qwLogTime = SGDP::SDTimeSecs();
	stFactionLogData.adwParamList[0] = stGiveWineProp.dwOpenCost;//��Ҫ�ʽ�
	stFactionLogData.adwParamList[1] = EFB_HotSpring;//����ID
	poFaction->AddFactionLogData(stFactionLogData);
	string strMsg = CMsgDefMgr::Instance()->GetErrMsg("FACTION_ACTIVI_HOTSPRING", NULL);
	poFaction->AddFactionActivityChat(strMsg);
	return ERR_SURE_GIVE_WINE::ID_SUCCESS;
}

UINT16 CHotSpring::OpenFindDrink()
{
	CFaction* poFaction = GetFaction();
	if (NULL == poFaction)
	{
		return ERR_OPEN_FIND_DRINK::ID_FACTION_NOT_EXIST;
	}
	BOOL bRet = IsOpen();
	if ( !bRet )
	{
		return ERR_OPEN_FIND_DRINK::ID_HOT_SPRING_NOT_EXIST;
	}
	DT_HOT_SPRING_TIME_DATA& stHotSpringTimeData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;


	if( ESM_NO == m_stHotSpringData.byLastDrinkWineState)
	{
		return ERR_OPEN_FIND_DRINK::ID_NOT_FIND_BACK_DRINK;
	}

	if (ESM_YES == stHotSpringTimeData.byGiveWineOpenState)
	{
		return ERR_OPEN_FIND_DRINK::ID_NOT_FIND_BACK_IN_GIVE_WINE;
	}

	if ( ESM_YES == m_stHotSpringData.byDrinkWineState)
	{
		return ERR_OPEN_FIND_DRINK::ID_HAVE_A_WINE;
	}


	return ERR_OPEN_FIND_DRINK::ID_SUCCESS;
}

VOID CHotSpring::GetDrinkReward(PKT_CLIGS_HOT_SPRING_REWARD_NTF* stNtf)
{
	GetFaction();
	if( 0 != m_stHotSpringData.stWineInfo.dwWineID && m_stHotSpringData.stWineInfo.byLeftDrinkNum != 0)
	{
		m_stHotSpringData.stWineInfo.byLeftDrinkNum--;
		stNtf->byRewardID1 = m_stHotSpringData.stWineInfo.byRewardID1;
		stNtf->byRewardID2 = m_stHotSpringData.stWineInfo.byRewardID2;
		stNtf->wEachReward1 = m_stHotSpringData.stWineInfo.dwEachRewardValue1;
		stNtf->wEachReward2 = m_stHotSpringData.stWineInfo.dwEachRewardValue2;
		m_poOwner->AddReward(stNtf->byRewardID1, stNtf->wEachReward1, CRecordMgr::EAPST_DRINKWINE);
		m_poOwner->AddReward(stNtf->byRewardID2, stNtf->wEachReward2, CRecordMgr::EAPGT_DRINK_WINE);
		UINT8 byDrinkNum = m_stHotSpringData.stWineInfo.dwDrinkMaxTime - m_stHotSpringData.stWineInfo.byLeftDrinkNum;
		stNtf->wSumReward1 = m_stHotSpringData.stWineInfo.dwEachRewardValue1 * byDrinkNum;
		stNtf->wSumReward2 = m_stHotSpringData.stWineInfo.dwEachRewardValue2 * byDrinkNum;
		m_stHotSpringData.dwDrinkKeepTime = m_stHotSpringData.stWineInfo.dwDrinkWineCD * (m_stHotSpringData.stWineInfo.dwDrinkMaxTime - m_stHotSpringData.stWineInfo.byLeftDrinkNum);
		m_stHotSpringData.qwFirstDrinkTime = SGDP::SDTimeSecs();
	}
}


VOID CHotSpring::AddDrinkEvent()
{
	GetFaction();
	if( 0 != m_stHotSpringData.stWineInfo.dwWineID && m_stHotSpringData.stWineInfo.byLeftDrinkNum != 0)
	{
		
		UINT32 dwInterval = 0;
		UINT32 dwUseTime = m_stHotSpringData.dwDrinkKeepTime % m_stHotSpringData.stWineInfo.dwDrinkWineCD;
		if (dwUseTime == 0)
		{
			dwInterval = m_stHotSpringData.stWineInfo.dwDrinkWineCD;
		}
		else
		{
			dwInterval = m_stHotSpringData.stWineInfo.dwDrinkWineCD - dwUseTime;
		}
		CTimerEventMgr::Instance()->AddDrinkWineEvent(m_poOwner->GetID(), dwInterval);
	}
	else
	{
		m_stHotSpringData.byDrinkWineState = ESM_NO;
		m_stHotSpringData.dwDrinkKeepTime = 0;
		m_stHotSpringData.qwFirstDrinkTime = 0;
		memset(&m_stHotSpringData.stWineInfo, 0, sizeof(m_stHotSpringData.stWineInfo));
	}
}

VOID CHotSpring::AfterGiveWineProc()
{
	CFaction* poFaction = GetFaction();
	if ( NULL != poFaction)
	{
		m_stHotSpringData.byDrinkWineState = ESM_NO;
		m_stHotSpringData.dwDrinkKeepTime = 0;
		m_stHotSpringData.qwFirstDrinkTime = 0;
		m_stHotSpringData.byIsIgnorePrompt = 0;
		if (m_stHotSpringData.stWineInfo.dwWineID != 0 && m_stHotSpringData.stWineInfo.byLeftDrinkNum != 0)
		{
			UINT8 byLeft = m_stHotSpringData.stWineInfo.dwDrinkMaxTime - m_stHotSpringData.stWineInfo.byLeftDrinkNum;
			m_stHotSpringData.byHaveOverReward = ESM_YES;
			m_stHotSpringData.stOverReward.byRewardID1 = m_stHotSpringData.stWineInfo.byRewardID1;
			m_stHotSpringData.stOverReward.byRewardID2 = m_stHotSpringData.stWineInfo.byRewardID2;
			m_stHotSpringData.stOverReward.dwRewardValue1 = m_stHotSpringData.stWineInfo.dwEachRewardValue1 * byLeft;
			m_stHotSpringData.stOverReward.dwRewardValue2 = m_stHotSpringData.stWineInfo.dwEachRewardValue2 * byLeft;
		}
		memset(&m_stHotSpringData.stWineInfo, 0, sizeof(m_stHotSpringData.stWineInfo));
		CTimerEventMgr::Instance()->DelDrinkWineEvent(m_poOwner->GetID());
		if(ESM_NO == m_stHotSpringData.byIsJoinCurActivity)
		{
			if (0 == m_stHotSpringData.byTodayBackTime )
			{
				//�һ�����
				m_stHotSpringData.byLastDrinkWineState = ESM_YES;
			}
		}
		else
		{
			m_stHotSpringData.byIsJoinCurActivity = ESM_NO;
		}
	}
	else
	{
		m_stHotSpringData.byActivityStat = ESM_NO;
		m_stHotSpringData.byDrinkWineState = ESM_NO;
		m_stHotSpringData.byIsIgnorePrompt = 0;
		m_stHotSpringData.byIsJoinCurActivity = ESM_NO;
		memset(&m_stHotSpringData.stWineInfo, 0, sizeof(DT_WINE_DATA_CLI));
		memset(&m_stHotSpringData.stOverReward, 0, sizeof(DT_OVER_GIVE_WINE_REWARD));
		CTimerEventMgr::Instance()->DelDrinkWineEvent(m_poOwner->GetID());
	}
	CheckByEveryTime();	
}


UINT16 CHotSpring::OverRewardAck()
{
	GetFaction();
	if( ESM_NO == m_stHotSpringData.byHaveOverReward)
	{
		return ERR_HOT_SPRING_OVER_REWARD::ID_NOT_OVER_REWARD;
	}
	else
	{
		m_stHotSpringData.byHaveOverReward = ESM_NO;
		memset(&m_stHotSpringData.stOverReward, 0, sizeof(m_stHotSpringData.stOverReward));
	}
	return ERR_HOT_SPRING_OVER_REWARD::ID_SUCCESS;
}

VOID CHotSpring::SetDrinkWineData(DT_WINE_DATA_CLI& stDrinkWineData)
{
	ResetTimeByWine();
	stDrinkWineData = m_stHotSpringData.stWineInfo;
}

BOOL CHotSpring::IsOpen()
{
	CFaction* poFaction =GetFaction();
	if ( NULL == poFaction)
	{
		return FALSE;
	}
	
	if ( 0 == poFaction->GetDT_FACTION_BASE_DATA().dwHotSpringLevel)
	{
		return FALSE;
	}

	return TRUE;
}

VOID CHotSpring::GetPrompt(DT_FUNC_COMMON_PROMPT& stPrompt)
{
	memset(&stPrompt, 0, sizeof(stPrompt));

	CFaction* poFaction = GetFaction();
	if (NULL == poFaction)
	{
		return ;
	}

	stPrompt.byBuildKindID = EFB_HotSpring;
	DT_HOT_SPRING_TIME_DATA& stData = poFaction->GetDT_FACTION_COMMON_DATA().stHotSpringData;
	if ( 1 == stData.byGiveWineOpenState )
	{
		stPrompt.byFuncFlag = EFPID_InActivi;//����ʱ��
		return ;
	}

	if (1 == m_stHotSpringData.byLastDrinkWineState)
	{
		stPrompt.byFuncFlag = EFPID_FindBack;//�һ�����
		return ;
	}
}

UINT16 CHotSpring::GetOpenLeaveHotSpringMsg(TCHAR* aszPromptMsg)
{
	string strMsg = CMsgDefMgr::Instance()->GetErrMsg("LEAVE_HOT_SPRING_MSG", NULL);
	SDStrncpy(aszPromptMsg, strMsg.c_str(), MAX_LEAVE_HOT_SPRING_PROMPT_MSG - 1);
	return ERR_OPEN_LEAVE_HOT_SPRING::ID_SUCCESS;
}

VOID CHotSpring::GetExprience(DT_HOT_SPRING_EXPERIENCE& stExprience, UINT64 qwNowTime)
{
	CFaction* poFaction = GetFaction();
	if ( NULL != poFaction)
	{
		stExprience.dwAddInterval = CSinglePramMgr::Instance()->GetExprienceAddInterval();
		stExprience.dwMaxExperience = CLuamgr::Instance()->GetMaxExprience( m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel, poFaction->GetDT_FACTION_BASE_DATA().dwFactionLevel);
		stExprience.dwExperienceBase = CLuamgr::Instance()->GetExprienceBase(m_poOwner->GetLevel(), poFaction->GetDT_FACTION_BASE_DATA().dwFactionLevel);
		/*����ʱ��+�ۻ�ʱ�� / ���ʱ��*/
		UINT32 dwCount = static_cast<UINT32>( ( (qwNowTime - m_stHotSpringExt.qwLastEnterTime) + m_stHotSpringExt.qwExprienceTime) / stExprience.dwAddInterval);
		stExprience.dwCurExperience = (stExprience.dwMaxExperience < (stExprience.dwExperienceBase * dwCount)) ? stExprience.dwMaxExperience : (stExprience.dwExperienceBase * dwCount) ;
	}
	 
}

VOID CHotSpring::ResetExprienceTime(UINT64 qwNowTime)
{
	UINT32 dwAddInterval = CSinglePramMgr::Instance()->GetExprienceAddInterval();
	UINT64 qwLeftTime = ((qwNowTime - m_stHotSpringExt.qwLastEnterTime) + m_stHotSpringExt.qwExprienceTime) % dwAddInterval;
	m_stHotSpringExt.qwLastEnterTime = qwNowTime;
	m_stHotSpringExt.qwExprienceTime = qwLeftTime;
}

UINT16 CHotSpring::GetExprienceHotSpring(PKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK& stAck, UINT32 dwExprienceValue)
{
	UINT64 qwNowTime = SGDP::SDTimeSecs();
	DT_HOT_SPRING_EXPERIENCE stExprience = {0};
	GetExprience(stExprience, qwNowTime);
	CHero* poHero = m_poOwner->GetCoachHero();
	if ( NULL == poHero)
	{
		return ERR_GET_EXPRIENCE_HOT_SPRING::ID_HERO_EXCEPTION;
	}
	UINT32 dwGetExprience = 0;
	//�������ֵ
	UINT32 dwMaxExprience = stExprience.dwCurExperience;
	
	if ( dwExprienceValue < dwMaxExprience )
	{
		dwGetExprience = dwExprienceValue;
	}
	else
	{
		dwGetExprience = stExprience.dwCurExperience;
	}
	stAck.stPowerInfo.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
	//��Ӿ���
	poHero->AddExperience(dwGetExprience);
	//���������Ϣ
	m_poOwner->GetMainHeroUpgradeInfo(stAck.stHeroUpgradeInfo);
	
	USR_INFO("[%s : %d] PlayerID=%lu, AddExperience=%lu", MSG_MARK, m_poOwner->GetID(), dwGetExprience);
	m_poOwner->ResetBattleAttr(TRUE);
	stAck.stPowerInfo.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
	
	//������� 
	ResetExprienceTime(qwNowTime);
	GetExprience(stAck.stPlayerExprience, qwNowTime);
	stAck.dwExprienceValue = dwGetExprience;
	return ERR_GET_EXPRIENCE_HOT_SPRING::ID_SUCCESS;
}
