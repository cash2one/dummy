#include "playermgr.h"
#include "playerbasedatacachemgr.h"
#include "playersavemgr.h"
#include "playergetdatamgr.h"
#include <net/db/dbpktbuilder.h>
#include <framework/gsapi.h>
#include <sdstring.h>
#include <common/client/errdef.h>
#include <logic/skill/skillpropmgr.h>
#include <sdutil.h>
#include <logic/task/taskpropmgr.h>
#include <logic/task/task.h>
#include <framework/gsconfig.h>
#include <net/gt/gtpktbuilder.h>
#include <logic/event/timereventmgr.h>
#include <logic/formation/formationpropmgr.h>
#include <logic/hero/heropropmgr.h>
#include <logic/plunder/plunderbasepropmgr.h>
#include <db/dbmgr.h>
#include <net/cli/usermgr.h>
#include <logic/task/taskmgr.h>
#include <db/saveplayerdatacmd.h>
#include <logic/http/rechargehttpcmd.h>
#include <db/setretreatepayprocessed.h>
#include "net/recharge/rcclient.h"
#include "logic/http/httpmgr.h"
IMPLEMENT_SINGLETON(CPlayerMgr)

CPlayerMgr::CPlayerMgr()
{

}

CPlayerMgr::~CPlayerMgr()
{
    CPlayerSaveMgr::DestroyInstance();
    CGetPlayerDataMgr::DestroyInstance();
}


BOOL CPlayerMgr::Init()
{
    // ��ʼ��CPlayerSaveMgr������
    if(FALSE == CPlayerSaveMgr::CreateInstance())
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerSaveMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlayerSaveMgr::Instance()->Init())
    {
        USR_INFO(_SDT("[%s: %d]: CPlayerSaveMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CGetPlayerDataMgr������
    if(FALSE == CGetPlayerDataMgr::CreateInstance())
    {
        USR_INFO(_SDT("[%s: %d]: CGetPlayerDataMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CGetPlayerDataMgr::Instance()->Init())
    {
        USR_INFO(_SDT("[%s: %d]: CGetPlayerDataMg Init failed!"), MSG_MARK);
        return FALSE;
    }

    //��ʼ�����Ĭ������
    if(FALSE == InitPlayerDefault())
    {
        return FALSE;
    }

    //���������Ϊ�գ���ô��ʼ��������

    return TRUE;

}

BOOL CPlayerMgr::InitPlayerDefault()
{
    memset(&m_stPlayerDefault, 0, sizeof(m_stPlayerDefault));

    if(FALSE == ReadPlayerDefaltBase())
    {
        return FALSE;
    }

    ////////////////////////////// DT_TASK_DATA_LIST
    //ÿ��������Ҹ�ÿ�������ߵĵ�һ������
    CTaskLine2TaskLinePropMap mapTaskLine = CTaskPropMgr::Instance()->GetTaskLine2TaskLinePropMap();
    DT_TASK_DATA_LIST& stTaskDataList = m_stPlayerDefault.stPlayerNoPvpData.stTaskData;
    for(CTaskLine2TaskLinePropMapItr itr = mapTaskLine.begin(); ((itr != mapTaskLine.end()) && (stTaskDataList.byTaskNum < MAX_TASK_LINE_NUM)); itr++)
    {
        CTaskLineProp* pstTaskLineProp = itr->second;
        DT_TASK_DATA& stDT_TASK_DATA = stTaskDataList.astTaskInfoList[stTaskDataList.byTaskNum];
        stDT_TASK_DATA.byTaskLine = itr->first;
        stDT_TASK_DATA.dwTaskIdx = pstTaskLineProp->dwFirstTaskIdx;
        stDT_TASK_DATA.byTaskState = ETS_GIVEN;
        if(!CTaskMgr::Instance()->SetTaskCond(NULL, stDT_TASK_DATA.byTaskLine, stDT_TASK_DATA.dwTaskIdx, stDT_TASK_DATA.byTaskType, stDT_TASK_DATA.stTaskConditionInfo))
        {
            USR_INFO(_SDT("[%s: %d]: SetTaskCond failed!"), MSG_MARK);
            return FALSE;
        }

        stTaskDataList.byTaskNum++;
    }

    ////////////////////////////// DT_LOCALE_DATA
    //���λ�ã�Ĭ���ڵ�һ��������
    DT_LOCALE_DATA& stLocaleData = m_stPlayerDefault.stPlayerNoPvpData.stLocaleData;
    memset(&stLocaleData, 0, sizeof(stLocaleData));
    stLocaleData.byLocaleType = EPL_INSTANCE;
    stLocaleData.stLocaleInfo.stInstance.wSceneIdx = 1;
    stLocaleData.stLocaleInfo.stInstance.byTownIdx = 1;
    stLocaleData.stLocaleInfo.stInstance.byInstanceIdx = 1;
    stLocaleData.stLocaleInfo.stInstance.byBattleIdx = 0;

    ////////////////////////////// DT_STATE_DATA
    //���״̬
    DT_STATE_DATA& stCurState = m_stPlayerDefault.stPlayerNoPvpData.stCurState;
    memset(&stCurState, 0, sizeof(stCurState));
    stCurState.dwInstanceMAXHP = 100;
    stCurState.dwInstanceCurHP = 100;

    //////////////////////////////

    return TRUE;
}

BOOL CPlayerMgr::SetFormationByHeroID(UINT16 wCoachHeroID, DT_NEW_FORMATION_DATA& stFormationInfo)
{
    memset(&stFormationInfo, 0, sizeof(stFormationInfo));
    SHeroProp* pstHeroProp  = CHeroPropMgr::Instance()->GetHeroProp(wCoachHeroID);
    if(NULL == pstHeroProp)
    {
        return FALSE;
    }
	///////////////////////////////�ɰ�����///////////////////////////////////////////
    UINT8 byFormationKindID = 0;
	
    switch(pstHeroProp->byCareerID)
    {
    case ECK_ATTACK:
        byFormationKindID = ATTACK_FORMATION_KIND;
        break;
    case ECK_DEFENCE:
        byFormationKindID = DEFENCE_FORMATION_KIND;
        break;
    default:
        byFormationKindID = ATTACK_FORMATION_KIND;
        break;
    }

	CFormationKindMap& mapFormation = CFormationPropMgr::Instance()->GetFormationKindMap();
	CFormationKindMapItr itr = mapFormation.begin();
	stFormationInfo.stFormationList.byFormationKindNum = mapFormation.size();
	for ( UINT8 byIndex = 0; itr != mapFormation.end(); itr++, byIndex++)
	{
		if ( byFormationKindID == itr->second.byFormationKindID )
		{
			stFormationInfo.bySelectIdx = byIndex;
		}
		memcpy(&stFormationInfo.stFormationList.astFormationInfo[byIndex], &(itr->second.GetDT_FORMATION_IDX_DATA()), sizeof(DT_FORMATION_IDX_DATA));
		stFormationInfo.stFormationList.astFormationInfo[byIndex].astOpenIdxInfo[itr->second.byCoachFormationLstIdx].wHeroID = wCoachHeroID;//����λ��
	}

    ///////////////////////////////�°汾����///////////////////////////////////////////

	switch(byFormationKindID)
	{
	case ATTACK_FORMATION_KIND:
		byFormationKindID = BAIHU_FORMATION_KIND;
		break;
	case DEFENCE_FORMATION_KIND:
		byFormationKindID = QINGLONG_FORMATION_KIND;
		break;
	default:
		byFormationKindID = BAIHU_FORMATION_KIND;
		break;
	}

	const CMapFormationLevelMap& newFormationMap = CFormationPropMgr::Instance()->GetFormationLevelAllMap();
	
	CMapFormationLevelMapConstItr constItr = newFormationMap.begin();

	UINT8 byUnlockIdx = 0;
	UINT8 byLockIdx = 0;

	for ( UINT8 byIdx = 0; constItr != newFormationMap.end(); constItr++)
	{
		if ( byFormationKindID == constItr->first)
		{
			stFormationInfo.byNewSelectIdx = byIdx;	//Ĭ������
		}
		UINT8 byUnlockLevel = 0;
		UINT8 byVisableLevel = 0;
		BOOL bRet = CFormationPropMgr::Instance()->GetFormationUnlock(constItr->first, byVisableLevel, byUnlockLevel);
		
		DT_NEW_FORMATION_INFO* poInfo = NULL;
		if ( bRet )
		{
			if ( byVisableLevel <= 1)	//����ʾ
			{
				if ( byUnlockLevel <= 1) //�ѽ���
				{
					
					poInfo = &stFormationInfo.stNewFormationLst.astFormationArray[byUnlockIdx];
					byUnlockIdx++;
				}
				else	//����ʾ����δ����
				{
					poInfo = &stFormationInfo.stLockFormationLst.astFormationArray[byLockIdx];
					byLockIdx++;
				}
			}
			else
			{
				continue;
			}
		}
		else	//�Ҳ�����
		{
			continue;
		}


		CMapFormationLevelPropConstItr propItr = constItr->second.begin();
		UINT8 byPosIdx = 0;
		poInfo->byPostionNum = constItr->second.size();	//λ����
		poInfo->byFormationLevel = 1;
		for ( ; propItr != constItr->second.end(); propItr++)
		{
			if( ESM_YES == propItr->second.byCoachIdxFlag )
			{
				poInfo->byFormationID = propItr->second.byFormationID;	//����ID
				
				poInfo->astPostionInfo[byPosIdx].wHeroID = wCoachHeroID;	//����λ��
				poInfo->astPostionInfo[byPosIdx].byPostionIndex = propItr->second.byOpenIdx;
				poInfo->astPostionInfo[byPosIdx].byIsUnlock = ESM_YES;
				poInfo->astPostionInfo[byPosIdx].byNeedLevel = 0;
			}
			else
			{
				poInfo->astPostionInfo[byPosIdx].wHeroID = 0;
				poInfo->astPostionInfo[byPosIdx].byPostionIndex = propItr->second.byOpenIdx;
				poInfo->astPostionInfo[byPosIdx].byIsUnlock = ( 0 == propItr->second.byUnlockLevel ? ESM_YES : ESM_NO);
				poInfo->astPostionInfo[byPosIdx].byNeedLevel = propItr->second.byUnlockLevel;
			}
			byPosIdx++;
		}

		byIdx++;
	}

	stFormationInfo.stNewFormationLst.byFormationNum = byUnlockIdx;
	
    m_stPlayerDefault.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.byFormationIdx = 1; //�¾ɲ��ü��ݣ�Ĭ��λ��1

    return TRUE;
}


BOOL CPlayerMgr::SetFormationByHeroID(vector<UINT16>& vecHeroID, DT_NEW_FORMATION_DATA& stFormationInfo)
{
    if(0 == vecHeroID.size())
    {
        return FALSE;
    }
    memset(&stFormationInfo, 0, sizeof(stFormationInfo));
    SHeroProp* pstHeroProp  = CHeroPropMgr::Instance()->GetHeroProp(vecHeroID[0]); //0Ĭ��Ϊ����
    if(NULL == pstHeroProp)
    {
        return FALSE;
    }
    UINT8 byFormationKindID = 0;

	
    switch(pstHeroProp->byCareerID)
    {
    case ECK_ATTACK:
        byFormationKindID = ATTACK_FORMATION_KIND;
        break;
    case ECK_DEFENCE:
        byFormationKindID = DEFENCE_FORMATION_KIND;
        break;
    default:
        byFormationKindID = ATTACK_FORMATION_KIND;
        break;
    }
    SFormationProp* pstProp = CFormationPropMgr::Instance()->GetFormationProp(byFormationKindID);
    if(NULL == pstProp)
    {
        return FALSE;
    }
    stFormationInfo.bySelectIdx = 0;
    stFormationInfo.stFormationList.byFormationKindNum = 1;
    memcpy(&stFormationInfo.stFormationList.astFormationInfo[0], &(pstProp->GetDT_FORMATION_IDX_DATA()), sizeof(DT_FORMATION_IDX_DATA));
    CFormationIdxMap& mapOpenIdx = pstProp->mapOpenIdx;
    UINT8 bySize = vecHeroID.size();
    UINT8 byIdx = 0;
    for(CFormationIdxMapItr itr = pstProp->mapOpenIdx.begin(); ((itr != mapOpenIdx.end()) && (byIdx < bySize)) ; itr++, byIdx++)
    {
        stFormationInfo.stFormationList.astFormationInfo->astOpenIdxInfo[byIdx].wHeroID = vecHeroID[byIdx];//
        m_stPlayerDefault.stPlayerNoPvpData.stHeroData.astHeroInfoLst[byIdx].stHeroBaseData.byFormationIdx = itr->first;
    }

    return TRUE;
}

BOOL CPlayerMgr::ReadPlayerDefaltBase()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetCfgDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }
    SGDP::ISDDBRecordSet* pRes = NULL;
    UINT32 dwErrID = 0;
    string strErr;
    INT32 nRet = pDBSession->ExecuteSqlRs(GetPropTableSelectSql("playerdefaultprop").c_str(), &pRes, &dwErrID,  &strErr);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        USR_INFO(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }
    if(pRes->GetRecord())
    {
        DT_PLAYER_BASE_DATA& stBaseData = m_stPlayerDefault.stPlayerNoPvpData.stBaseData;
        memset(&stBaseData, 0, sizeof(DT_PLAYER_BASE_DATA));
        stBaseData.qwCoin = SGDP::SDAtou(pRes->GetFieldValueByName("Coin"));
        stBaseData.qwGold = SGDP::SDAtou(pRes->GetFieldValueByName("Gold"));
        stBaseData.wPhyStrength = SGDP::SDAtou(pRes->GetFieldValueByName("PhyStrength"));
        stBaseData.qwStory = SGDP::SDAtou(pRes->GetFieldValueByName("Story"));
        stBaseData.qwScience = SGDP::SDAtou(pRes->GetFieldValueByName("Science"));
        stBaseData.qwJingJie = SGDP::SDAtou(pRes->GetFieldValueByName("JingJie"));
        stBaseData.qwBlueGas = SGDP::SDAtou(pRes->GetFieldValueByName("BlueGas"));
        stBaseData.qwPurpleGas = SGDP::SDAtou(pRes->GetFieldValueByName("PurpleGas"));
    }
    if(NULL != pRes)
    {
        pRes->Release();
        pRes = NULL;
    }


    //������Ϣ
    memset(&m_stPlayerDefault.stPlayerNoPvpData.stHeroData, 0, sizeof(DT_HERO_DATA_LIST));
    m_stPlayerDefault.stPlayerNoPvpData.stHeroData.wHeroNum = 1;
    DT_HERO_BASE_DATA& stDT_HERO_BASE_DATA = m_stPlayerDefault.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData;
    stDT_HERO_BASE_DATA.wKindID = 1; //�û�ѡְҵʱ���¸�ֵ
    stDT_HERO_BASE_DATA.wLevel = 1;//��ʼ��1����ʼ
    stDT_HERO_BASE_DATA.byCoach = 1;
    stDT_HERO_BASE_DATA.byPos = EHP_BATTLE;//������ս
    stDT_HERO_BASE_DATA.byFormationIdx = 1;//������Զ��1����λ�ã������޸�
    stDT_HERO_BASE_DATA.byRecuitedFlag = 1;//�Ѿ���ļ��

    return TRUE;
}


VOID CPlayerMgr::UnInit()
{
    m_mapID2PlayerMap.clear();

    CGetPlayerDataMgr::Instance()->UnInit();
    CPlayerSaveMgr::Instance()->UnInit();

}

void	 CPlayerMgr::GetID2PlayerVec(CID2PlayerVec &vecPlayerCache)
{
    vecPlayerCache.clear();
    CID2PlayerMapItr itr = m_mapID2PlayerMap.begin();
    for (itr; itr != m_mapID2PlayerMap.end(); itr++)
    {
        vecPlayerCache.push_back(itr->first);
    }
}


CPlayer* CPlayerMgr::FindPlayer(UINT32 dwPlayerID)
{
    CID2PlayerMapItr itr = m_mapID2PlayerMap.find(dwPlayerID);
    if(itr != m_mapID2PlayerMap.end())
    {
        return itr->second;
    }

    return NULL;
}

CPlayer* CPlayerMgr::CreatePlayer(UINT32 dwPlayerID)
{
    CPlayer* poPlayer = FindPlayer(dwPlayerID);
    if(poPlayer)
    {
        return poPlayer;
    }

    poPlayer = CPlayerPoolMgr::Instance()->Create();
    if(NULL == poPlayer)
    {
        return NULL;
    }
    m_mapID2PlayerMap[dwPlayerID] = poPlayer;

    //������־
    DBG_INFO(_SDT("[%s: %d]: CreatePlayer, PlayerID:%u, address:%0x"), MSG_MARK, dwPlayerID, poPlayer);
    return poPlayer;
}

VOID CPlayerMgr::RemovePlayer(UINT32 dwPlayerID)
{
    CID2PlayerMapItr itr = m_mapID2PlayerMap.find(dwPlayerID);
    if (m_mapID2PlayerMap.end() != itr)
    {
        CPlayer *poPlayer = itr->second;

        //������־
        DBG_INFO(_SDT("[CPlayerMgr::%s:%d]: RemovePlayer [ %u : %s ], address:%0x"), MSG_MARK, dwPlayerID, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName, itr->second);

        m_mapID2PlayerMap.erase(itr);
        CPlayerPoolMgr::Instance()->Remove(poPlayer);
    }

    gsapi::GetDBMgr()->OnPlayerRelease(dwPlayerID);
}

//���������Ϣ�¼��ص��������������
VOID CPlayerMgr::OnSaveOnlineEvent(UINT32 dwPlayerID)
{
    CID2PlayerMapItr itr = m_mapID2PlayerMap.find(dwPlayerID);
    if(itr == m_mapID2PlayerMap.end())
    {
        return;
    }
    CPlayer* poPlayer = itr->second;

    //�Ѳ����ڴ���ң������¼������
    if(NULL == poPlayer)
    {
        CTimerEventMgr::Instance()->DelSaveOnlineEvent(dwPlayerID);
        return;
    }

    CPlayerSaveMgr::Instance()->SavePlayerData(poPlayer);
}


//����/���ǵ�¼���������ݣ���������ڴ������
VOID CPlayerMgr::OnSaveCkOfflineEvent(UINT32 dwPlayerID)
{
    CID2PlayerMapItr itr = m_mapID2PlayerMap.find(dwPlayerID);
    if(itr == m_mapID2PlayerMap.end())
    {
        return;
    }
    CPlayer* poPlayer = itr->second;

    //�Ѳ����ڴ���ң������¼������
    if(NULL == poPlayer)
    {
        CTimerEventMgr::Instance()->DelSaveCkOfflineEvent(dwPlayerID);
        return;
    }

    //����
    if(ESS_WANT_SAVE == poPlayer->GetSaveState())
    {
        CPlayerSaveMgr::Instance()->SavePlayerData(poPlayer);
        poPlayer->SetSaveState(ESS_SAVEING);
    }

    //�ѹ�����ʱ�䣬��󱣴�һ�����ݣ�������
    if(SDTimeSecs() - poPlayer->GetUpdateTime() > CGSConfig::Instance()->GetOfflineCacheTime())
    {
        CTimerEventMgr::Instance()->DelSaveCkOfflineEvent(dwPlayerID);

        //�����ٱ��棬ǰ���Ѿ�����
        //��󱣴�һ������
        CPlayerSaveMgr::Instance()->SavePlayerData(poPlayer);

        //�������
        CUserMgr::Instance()->ReleaseUser(poPlayer->GetUser());

        //������־
        DBG_INFO(_SDT("[%s: %d]: OnSaveCkOfflineEvent, PlayerID:%u, address:%0x"), MSG_MARK, dwPlayerID, poPlayer);


        m_mapID2PlayerMap.erase(dwPlayerID);
        CPlayerPoolMgr::Instance()->Remove(poPlayer);

        poPlayer = NULL;
    }
}


//���������ݣ�fortest��
//VOID CPlayerMgr::ClrPlayerData(CPlayer* poPlayer)
//{
//    if(NULL == poPlayer)
//    {
//        return;
//    }
//
//    UINT32 dwPlayerID = poPlayer->GetDT_PLAYER_BASE_DATA().dwID;
//
//    //��GT֪ͨ,�����������
//    UINT16 wMsgID = CGTPktBuilder::Instance()->ClrPlayerCache(1);
//    poPlayer->SendMsg(CGTPktBuilder::Instance()->GetPacketBuffer(), wMsgID);
//
//    //��DB֪ͨ������������
//    CDBPktBuilder::Instance()->ClrPlayerData	(dwPlayerID);
//
//    //�޸����������Լ������1����
//    //����������ݻ���
//    CPlayerBaseDataCacheMgr::Instance()->OnClrPlayerData(poPlayer);
//
//    //�������
//    CUserMgr::Instance()->ReleaseUser(poPlayer->GetUser());
//    m_mapID2PlayerMap.erase(dwPlayerID);
//    m_oPlayerShmemObjMgr.Free(poPlayer);
//    poPlayer = NULL;
//}

BOOL CPlayerMgr::CreateNewPlayer(UINT32 dwTransID, CUser* poUser)
{
    if(NULL == poUser)
    {
        return FALSE;
    }

    UINT16 wCareerID = poUser->GetCareerID();
    //ְҵID��Χ1��6
    if((wCareerID == 0) || (wCareerID > 6))
    {
        return FALSE;
    }
    DT_PLAYER_DATA	stPlayerData;
    memcpy(&stPlayerData, &m_stPlayerDefault, sizeof(DT_PLAYER_DATA));

    if(!SetFormationByHeroID(wCareerID, stPlayerData.stPlayerNoPvpData.stFormationInfo))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: SetFormationByHeroID failed!"), MSG_MARK);
        return FALSE;
    }

    //�����´������û���ǿ�Ƶ�����ֵ�����ʾ��Ϣ
    set_bit(stPlayerData.stPlayerNoPvpData.stBaseData.dwExtData, em_VIP);

    //ְҵID��������������ID
    stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wKindID = wCareerID;
    UINT32 dwPlayerID = poUser->GetPlayerID();
    stPlayerData.stPlayerNoPvpData.stBaseData.dwID = dwPlayerID;
    CDBPktBuilder::Instance()->CreatePlayerReq(dwTransID, dwPlayerID, poUser->GetUserName(), poUser->GetDeviceID(), poUser->GetNotifyID(), 0, stPlayerData);

    return TRUE;
}

//ȡ�����ַ�ʽ
/*
//���������ڴ棬���������
BOOL CPlayerMgr::CreateNewPlayerInMem(UINT32 dwTransID, CUser* poUser)
{
	if(NULL == poUser)
	{
		return FALSE;
	}

	UINT16 wCareerID = poUser->GetCareerID();
	//ְҵID��Χ1��6
	if((wCareerID == 0) || (wCareerID > 6))
	{
		return FALSE;
	}
	DT_PLAYER_DATA	stPlayerData;
	memcpy(&stPlayerData, &m_stPlayerDefault, sizeof(DT_PLAYER_DATA));

	if(!SetFormationByHeroID(wCareerID, stPlayerData.stPlayerNoPvpData.stFormationInfo))
	{
		SYS_CRITICAL(_SDT("[%s: %d]: SetFormationByHeroID failed!"), MSG_MARK);
		return FALSE;
	}

	//ְҵID��������������ID
	stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wKindID = wCareerID;
	UINT32 dwPlayerID = poUser->GetPlayerID();
	stPlayerData.stPlayerNoPvpData.stBaseData.dwID = dwPlayerID;
	//CDBPktBuilder::Instance()->CreatePlayerReq(dwTransID, dwPlayerID, poUser->GetUserName(), poUser->GetDeviceID(), poUser->GetNotifyID(), 0, stPlayerData);

	//��Ϊ���ڵ�¼�߼�����ʹ�ظ���¼Ҳû�й�ϵ�����Բ����ڴ���������
	BOOL bAlreadyLogin = FALSE;
	CPlayer* poPlayer = CDBProcessor::InitPlayer(stPlayerData, poUser, bAlreadyLogin);
	if(poPlayer)
	{
		poPlayer->GetNewPlayerFlag() = TRUE;
		poPlayer->OnLogin();//����
		poPlayer->ResetLoginTime(); //��������ʱ��
		poPlayer->RecordPlayerOnOffLine( TRUE );
		CPlayerBaseDataCacheMgr::Instance()->ReSetLoginTime(dwTransID);//��¼��������¼ʱ��
		SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwPlayerID);
		//������ң�����������Ϣ������
		if(NULL == pstPlayerBaseData)
		{
			CPlayerBaseDataCacheMgr::Instance()->AddPlayerBaseData(poPlayer);
		}

		//�·���Ϣ
		UINT16 wMsgID = CGTPktBuilder::Instance()->EnterGSAck(SUCCESS, poPlayer);
		if(INVALID_MSGID != wMsgID)
		{
			poUser->SendMsg(CGTPktBuilder::Instance()->GetPacketBuffer(), wMsgID);
		}
		poUser->SetUserStat(CLIS_IN_GAME);
	}
	else
	{
		UINT16 wErrCode = 0;
		SET_OTHER_ERR(wErrCode);
		UINT16 wMsgID = CGTPktBuilder::Instance()->EnterGSAck(wErrCode, poPlayer);
		if(INVALID_MSGID != wMsgID)
		{
			poUser->SendMsg(CGTPktBuilder::Instance()->GetPacketBuffer(), wMsgID);
		}
	}

	return TRUE;
}
*/

//���������(GM)
BOOL CPlayerMgr::CreateNewPlayerGM(UINT32 dwPlayerID, UINT8 byRobotFunc, UINT16 wLevel, TCHAR* pszDspName)
{
    //������IDС��5000������1000
    if((dwPlayerID >= 5000) || (dwPlayerID < 1000))
    {
        return FALSE;
    }

    //SDSetSeed(SDGetTickCount());
    //UINT16 wCareerID = SDRandom(6) + 1;
    UINT16 wCareerID = 1; //��ֹû����������

    vector<UINT16> vecHeroID;
    //ְҵID��������������ID
    DT_PLAYER_DATA	stPlayerData;
    memcpy(&stPlayerData, &m_stPlayerDefault, sizeof(DT_PLAYER_DATA));
    stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wKindID = wCareerID;
    vecHeroID.push_back(wCareerID);
    stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wLevel = wLevel;
    stPlayerData.stPlayerNoPvpData.stBaseData.byRobotFunc = byRobotFunc;
    stPlayerData.stPlayerNoPvpData.stBaseData.dwPower = 1000;//�����˲���ȥ����
    stPlayerData.stPlayerNoPvpData.stBaseData.dwFirstAttack = 100;//�����˲���ȥ����
    memset(&stPlayerData.stPlayerNoPvpData.stBaseData.aszDispName, 0, sizeof(stPlayerData.stPlayerNoPvpData.stBaseData.aszDispName));
    if(pszDspName)
    {
        SDStrcpy(stPlayerData.stPlayerNoPvpData.stBaseData.aszDispName, pszDspName);
    }
    else
    {
        SDStrcpy(stPlayerData.stPlayerNoPvpData.stBaseData.aszDispName, "robot");
    }
    switch(byRobotFunc)
    {
    case ERFK_PLUNDER:
    {
        DT_BUILD_BASE_DATA& stDT_BUILD_BASE_DATA = stPlayerData.stPlayerNoPvpData.stBuildData.astBuildInfoLst[stPlayerData.stPlayerNoPvpData.stBuildData.wBuildNum++];
        stDT_BUILD_BASE_DATA.byKindID = EBK_PLUNDER;
        stDT_BUILD_BASE_DATA.wLevel = 0;

        stPlayerData.stPlayerPvpData.stPlunderData.stPlunderBaseData.byHaveDataFlag = 1;

        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wLevel = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp().wPlunderOpenLevel;
        UINT16 wLevel = stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wLevel / 2;
        wLevel = wLevel == 0 ? 1 : wLevel;

        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[1].stHeroBaseData.wKindID = 100;
        vecHeroID.push_back(100);
        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[1].stHeroBaseData.wLevel = 1;

        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[2].stHeroBaseData.wKindID = 101;
        vecHeroID.push_back(101);
        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[2].stHeroBaseData.wLevel = 1;

        stPlayerData.stPlayerNoPvpData.stHeroData.wHeroNum = 3;
    }
    break;
    case ERFK_RACE:
    {
        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wLevel = 10;

        UINT16 wLevel = 5;

        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[1].stHeroBaseData.wKindID = 100;
        vecHeroID.push_back(100);
        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[1].stHeroBaseData.wLevel = 1;

        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[2].stHeroBaseData.wKindID = 101;
        vecHeroID.push_back(101);
        stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[2].stHeroBaseData.wLevel = 1;

        stPlayerData.stPlayerNoPvpData.stHeroData.wHeroNum = 3;
    }
    break;
    default:
        break;
    }

    if(!SetFormationByHeroID(vecHeroID, stPlayerData.stPlayerNoPvpData.stFormationInfo))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: SetFormationByHeroID failed!"), MSG_MARK);
        return FALSE;
    }

    CHAR szDeviceID[DEVICEID_LEN] = { 0 };
    sprintf(szDeviceID, "robot_%d", dwPlayerID);
    stPlayerData.stPlayerNoPvpData.stBaseData.dwID = dwPlayerID;
    CDBPktBuilder::Instance()->CreatePlayerReq(dwPlayerID, dwPlayerID, _SDT(szDeviceID), _SDT(szDeviceID), _SDT(""), 1, stPlayerData);

    return TRUE;
}

BOOL CPlayerMgr::CreateNewPlayerGMMoreParam(UINT32 dwPlayerID, UINT16 wCareerID, UINT32 dwAmount, UINT32 dwTotalAmount, UINT8 byVipLevel, TCHAR* pszDspName, TCHAR* pszDeviceID, TCHAR* pszNotifyID)
{
    //ְҵID��Χ1��6
    if((wCareerID == 0) || (wCareerID > 6))
    {
        return FALSE;
    }
    DT_PLAYER_DATA	stPlayerData;
    memcpy(&stPlayerData, &m_stPlayerDefault, sizeof(DT_PLAYER_DATA));

    if(!SetFormationByHeroID(wCareerID, stPlayerData.stPlayerNoPvpData.stFormationInfo))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: SetFormationByHeroID failed!"), MSG_MARK);
        return FALSE;
    }

    if(pszDspName)
    {
        //SDStrcpy(stPlayerData.stBaseData.aszDispName, SDGBK2UTF8(pszDspName).c_str());
    }

    //ְҵID��������������ID
    stPlayerData.stPlayerNoPvpData.stHeroData.astHeroInfoLst[0].stHeroBaseData.wKindID = wCareerID;
    stPlayerData.stPlayerNoPvpData.stBaseData.dwID = dwPlayerID;
    stPlayerData.stPlayerNoPvpData.stBaseData.byVipLevel = byVipLevel;
    stPlayerData.stPlayerNoPvpData.stBaseData.wPhyStrength = 48 + 200;
    stPlayerData.stPlayerNoPvpData.stBaseData.dwTotalAmount = dwTotalAmount;

    stPlayerData.stPlayerNoPvpData.stBaseData.qwGold += dwAmount;

    CDBPktBuilder::Instance()->CreatePlayerReq(dwPlayerID, dwPlayerID, pszDspName, pszDeviceID, pszNotifyID, 0, stPlayerData);

    return TRUE;
}


//���������������
VOID CPlayerMgr::SaveAllPlayerData()
{
    for(CID2PlayerMapItr itr = m_mapID2PlayerMap.begin(); itr != m_mapID2PlayerMap.end(); itr++)
    {
        CPlayer* poPlayer = itr->second;
        if(NULL == poPlayer)
        {
            continue;
        }

        //����������
        if(0 != poPlayer->GetDT_PLAYER_BASE_DATA().byRobotFunc)
        {
            continue;
        }

        if(((FALSE == poPlayer->CkLogin()) && (ESS_WANT_SAVE == poPlayer->GetSaveState())) || //��������ң�playerbasedata�����������£���������ģ������ǲ��豣��
                (TRUE == poPlayer->CkLogin()))
        {
            CPlayerSaveMgr::Instance()->SavePlayerData(poPlayer);
        }
    }
    CPlayerSaveMgr::Instance()->SaveAllPlayerPvpData();

}

VOID CPlayerMgr::GetTodaySavePlayerPath(TCHAR* aszSavePath, UINT32 dwPlayerID)
{
	if ( NULL == aszSavePath)
	{
		return ;
	}
	CSDDateTime oDataTime(SGDP::SDTimeSecs());
	SDSprintf(aszSavePath, "%s/%s/%u", SAVE_PLAYER_DATA_SQL, oDataTime.ToString("YYYY-mm-dd").c_str(), dwPlayerID);
}

BOOL CPlayerMgr::RetreatePlayerData(const UINT32 &dwPlayerId,string strFile,UINT64 dwTime)
{
	CPlayer* pPlayer = this->FindPlayer(dwPlayerId);

	if (NULL != pPlayer)
	{
		this->RemovePlayer(dwPlayerId);
	}

	UINT32 dwGold = 0;
	UINT32 dwRMB = 0;
	
	BOOL bResultAdd = gsapi::GetDBMgr()->GetRechargeGold(dwPlayerId,dwGold,dwRMB,dwTime);

	if (!bResultAdd)
	{ 
		return FALSE;
	}

	BOOL bResultDB = gsapi::GetDBMgr()->ReadRetreatePlayerData(strFile.c_str(),dwGold,dwRMB,dwPlayerId);

	return bResultDB;
}

BOOL CPlayerMgr::AllPlayerRetreate(UINT32 dwTransID)
{
	UINT32 dwIndex = 0;
	BOOL bResultDB = gsapi::GetDBMgr()->GetRetreateMaxIndex(dwIndex);

	CRCClient* poClinet = gsapi::GetRCClientMgr()->FindCliSession(dwTransID);

	if (poClinet == NULL)
	{
		return FALSE;
	}

	if (!bResultDB)
	{
		poClinet->Rspone(GetRsponeResult(ERR_GM_PARM_INFO::ID_OTHER_ERR).c_str());
		return FALSE;
	}

	SRechargeInfo stRechargeInfo;
	stRechargeInfo.ZoneID = gsapi::GetZoneID();;
	stRechargeInfo.IndexMax = dwIndex;
	CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_RECHARGE);

	if (NULL == poHttpCmd)
	{
		poClinet->Rspone(GetRsponeResult(ERR_GM_PARM_INFO::ID_OTHER_ERR).c_str());
		return FALSE;
	}

	poHttpCmd->SetUserData(&stRechargeInfo, sizeof(SRechargeInfo), dwTransID);
	poHttpCmd->Init();

	if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
	{
		poClinet->Rspone(GetRsponeResult(ERR_GM_PARM_INFO::ID_OTHER_ERR).c_str());
		return FALSE;
	}

	return TRUE;
}
