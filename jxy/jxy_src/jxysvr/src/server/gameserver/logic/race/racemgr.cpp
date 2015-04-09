
#include "racemgr.h"
#include "racepropmgr.h"
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <protocol/server/protocommondata.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <logic/player/player.h>
#include <common/client/errdef.h>
#include <logic/battle/battlemgr.h>
#include <logic/player/playersavemgr.h>
#include <logic/event/timereventmgr.h>
#include <logic/hero/hero.h>
#include <logic/task/taskmgr.h>
#include <framework/gsconfig.h>
#include "logic/race/racebattlelogmgr.h"
#include "logic/other/singleprammgr.h"
#include "protocol/server/protogsdb.h"
#include "logic/player/playermgr.h"
#include "logic/medal/playermedal.h"
#include "logic/other/fewparam.h"
using namespace SGDP;

namespace raceutil
{
    // ����ս��ֵ��С���أ�> = <
    const char* CmpPower(UINT32 dwNewPower, UINT32 dwOldPower)
    {
        static std::string astrCmpOperator[] = 
        {
            ">",
            "=",
            "<"
        };

        BYTE byOperatorIdx = 0;
        if(dwNewPower > dwOldPower)
        { 
            byOperatorIdx = 0;
        }
        else if(dwNewPower == dwOldPower)
        {
            byOperatorIdx = 1; 
        }
        else
        { 
            byOperatorIdx = 2;
        }

        return astrCmpOperator[byOperatorIdx].c_str();
    }
}

IMPLEMENT_SINGLETON(CRaceMgr)

CRaceMgr::CRaceMgr()
    : m_dwMaxRank (0)
    , m_wLastOfflineRacerRank(0)
{
}

CRaceMgr::~CRaceMgr()
{
    CRacePropMgr::DestroyInstance();
    CRaceBattleLogMgr::DestroyInstance();

}


BOOL CRaceMgr::Init()
{
    //��ȡ�����ļ�

    // ��ʼ��CRacePropMgr������
    if(FALSE == CRacePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRacePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CRacePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRacePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CRaceBattleLogMgr������
    if(FALSE == CRaceBattleLogMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRaceBattleLogMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CRaceBattleLogMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CRaceBattleLogMgr Init failed!"), MSG_MARK);
        return FALSE;
    }
    if(!InitEvent())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitEvent failed!"), MSG_MARK);
        return FALSE;
    }

    return TRUE;

}

BOOL CRaceMgr::InitEvent()
{
    //��ǰʱ��
    UINT32 dwStartTime = CGSConfig::Instance()->GetTimerNotice() * 3600;
    CTimerEventMgr::Instance()->AddNoticeEventEvent(ENT_RACE, dwStartTime, 0);
    return TRUE;
}


VOID CRaceMgr::UnInit()
{
    CRacePropMgr::Instance()->UnInit();
    CRaceBattleLogMgr::Instance()->UnInit();
}

//CRace* CRaceMgr::CreateRace(UINT32 dwPlayerID)
//{
//    CRace* poRace = m_oRaceShmemObjMgr.Alloc();
//    if(NULL == poRace)
//    {
//        return NULL;
//    }
//    m_mapID2Race[dwPlayerID] = poRace;
//
//    return poRace;
//}
//
//VOID CRaceMgr::RemoveRace(UINT32 dwPlayerID)
//{
//    CID2RaceMapItr itr = m_mapID2Race.find(dwPlayerID);
//    if (m_mapID2Race.end() != itr)
//    {
//        CRace* poRace = itr->second;
//        m_oRaceShmemObjMgr.Free(poRace);
//        m_mapID2Race.erase(itr);
//    }
//}

VOID CRaceMgr::GetChallengePlayerList(UINT32 dwRank, UINT8& byChallengeNum, DT_CHALLENGE_PLAYER_DATA astChallengePlayerList[])
{
    UINT32 dwInterval = CRacePropMgr::Instance()->GetInterval(dwRank);
    UINT8 byChaNum = CRacePropMgr::Instance()->GetChallengeNum();

    INT32 nRankTmp = 0;
    UINT8 byReverse = 0;
    UINT8 byLoopNum = 10;
    BOOL  bReverse = FALSE;
    byChallengeNum = 0;
    map<UINT32, SPlayerBaseData*> mapChallengePlayer;//��������
    //������20�Σ��ҳ�byChaNum��(һ��10��)��ս���û�
    for(UINT8 byIdx = 1; ((byIdx <= byLoopNum) && (byChallengeNum < byChaNum)); byIdx++)
    {
        nRankTmp = dwRank - dwInterval * byIdx;
        if(nRankTmp <= 0)
        {
            if(!bReverse)
            {
                byReverse = byIdx - 1;
                bReverse = TRUE;
            }
            nRankTmp = dwRank + (byIdx - byReverse);
        }
        if(nRankTmp <= 0)
        {
            continue;
        }
        CRank2PlayerBaseDataMapItr itr = m_mapRank2PlayerBaseData.find(nRankTmp);
        if(itr == m_mapRank2PlayerBaseData.end())
        {
            SYS_CRITICAL(_SDT("[%s: %d]: nRankTmp[%d] not found!"), MSG_MARK, nRankTmp);
            continue;
        }
        SPlayerBaseData* pstPlayerBaseData = itr->second;
        if(NULL == pstPlayerBaseData)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: pstPlayerBaseData is nULL!"), MSG_MARK);
            continue;
        }

        mapChallengePlayer[nRankTmp] = pstPlayerBaseData;
        byChallengeNum++;
    }

    //�����·�
    byChallengeNum = 0;
    for(map<UINT32, SPlayerBaseData*>::iterator itr = mapChallengePlayer.begin(); itr != mapChallengePlayer.end(); itr++)
    {
        GetChallengePlayerData(itr->second, astChallengePlayerList[byChallengeNum++]);
    }

}


VOID CRaceMgr::GetChallengePlayerData(UINT32 dwPlayerID, DT_CHALLENGE_PLAYER_DATA& stDT_CHALLENGE_PLAYER_DATA)
{
    const SPlayerBaseData* poPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwPlayerID);
	if(NULL == poPlayerBaseData)
	{
		return;
	}
    GetChallengePlayerData(poPlayerBaseData, stDT_CHALLENGE_PLAYER_DATA);
}


VOID CRaceMgr::GetChallengePlayerData(const SPlayerBaseData* pstPlayerBaseData, DT_CHALLENGE_PLAYER_DATA& stDT_CHALLENGE_PLAYER_DATA)
{
    if(NULL == pstPlayerBaseData)
    {
        return;
    }
    stDT_CHALLENGE_PLAYER_DATA.dwID = pstPlayerBaseData->dwID;
    _SDTStrncpy(stDT_CHALLENGE_PLAYER_DATA.aszDispName, pstPlayerBaseData->aszDispName, USERNAME_LEN - 1);
    stDT_CHALLENGE_PLAYER_DATA.wHeroKindID = pstPlayerBaseData->wMainHeroKindID;
    stDT_CHALLENGE_PLAYER_DATA.wLevel = pstPlayerBaseData->wLevel;
    stDT_CHALLENGE_PLAYER_DATA.dwRank = pstPlayerBaseData->dwRank;
    stDT_CHALLENGE_PLAYER_DATA.dwPower = pstPlayerBaseData->dwPower;
    stDT_CHALLENGE_PLAYER_DATA.dwFirstAttack = pstPlayerBaseData->dwFirstAttack;
}


BOOL CRaceMgr::OnChallenge(CRace* poChallenge, CRace* poBeChallenge , BOOL bChallengeSuccess)
{
    if((NULL == poChallenge) || (NULL == poBeChallenge))
    {
        return FALSE;
    }
    DT_RACE_BASE_DATA& stChallengeData = poChallenge->GetDT_RACE_BASE_DATA();
    DT_RACE_BASE_DATA& stBeChallengeData = poBeChallenge->GetDT_RACE_BASE_DATA();
	
    //��¼ս��
    DT_RACE_BATTLELOG_DATA stChallengeLog;
    DT_RACE_BATTLELOG_DATA stBechallengeLog;
    memset(&stChallengeLog, 0, sizeof(stChallengeLog));
    memset(&stBechallengeLog, 0, sizeof(stBechallengeLog));
    stChallengeLog.byChallengeFlag = 0;
    stBechallengeLog.byChallengeFlag = 1;
    stChallengeLog.qwChallengeTime = SDTimeSecs();
    stBechallengeLog.qwChallengeTime = SDTimeSecs();
    stChallengeLog.dwEnemyPlayerID = poBeChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID;
    stBechallengeLog.dwEnemyPlayerID = poChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID;
    stChallengeLog.byResult = bChallengeSuccess == TRUE ? 0 : 1;
    stBechallengeLog.byResult = bChallengeSuccess == FALSE ? 0 : 1;
    stChallengeLog.dwBeginChallengeRank = stChallengeData.dwRank;
    stBechallengeLog.dwBeginChallengeRank = stBeChallengeData.dwRank;
    stChallengeLog.byNewFlag = 1;
    stBechallengeLog.byNewFlag = 1;

    if(bChallengeSuccess)
    {
        BOOL bChange = FALSE;

        //��ս���ж�
        //��Ա����ʱ���п�����ս���Լ������͵ģ����Լ������Ͳ���������
        //����λ��
        if(stBeChallengeData.dwRank < stChallengeData.dwRank)
        {
            DBG_INFO(_SDT("[%s: %d]: PlayerID[%u], Rank[%u]"), MSG_MARK, poChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID, stChallengeData.dwRank);
            DBG_INFO(_SDT("[%s: %d]: PlayerID[%u], Rank[%d]"), MSG_MARK, poBeChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID, stBeChallengeData.dwRank);

            //�޸Ļ�������
            if(!CPlayerBaseDataCacheMgr::Instance()->OnRankExchange(poChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID,
                    stChallengeData.dwRank,
                    poBeChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID,
                    stBeChallengeData.dwRank))
            {
                SYS_CRITICAL(_SDT("[%s: %d]: change Rank Faild!"), MSG_MARK);
                return FALSE;
            }

            DBG_INFO(_SDT("[%s: %d]: PlayerID[%u], Rank[%u]"), MSG_MARK, poChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID, stChallengeData.dwRank);
            DBG_INFO(_SDT("[%s: %d]: PlayerID[%u], Rank[%d]"), MSG_MARK, poBeChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID, stBeChallengeData.dwRank);
            UINT32 dwRankTmp = stChallengeData.dwRank;
            stChallengeData.dwRank = stBeChallengeData.dwRank;
            //��������ȡ������������ֵ��ǰ����Ϊ�������������
            //�����Ѿ���ȡ��
            if(IsToday(stChallengeData.qwRecvEncourageTime))
            {
                stChallengeData.dwRecvEncourageRank = stChallengeData.dwRank;
            }
			else if ( !IsToday(stChallengeData.qwNotifyRankTime) )//����������ʱ�䲻�ǽ����򱣴�һ�������������Է��Ž���
			{
				stChallengeData.dwRecvEncourageRank = dwRankTmp;
			}

            stBeChallengeData.dwRank = dwRankTmp;
            if(IsToday(stBeChallengeData.qwRecvEncourageTime))
            {
                stBeChallengeData.dwRecvEncourageRank = stBeChallengeData.dwRank;
            }
			else if( !IsToday(stBeChallengeData.qwNotifyRankTime))//����������ʱ�䲻�ǽ����򱣴�һ�������������Է��Ž���
			{
				stBeChallengeData.dwRecvEncourageRank = stChallengeData.dwRank;
			}
            //���������������ʱ��
            stChallengeData.dwNotifyRank = stChallengeData.dwRank;
            stChallengeData.qwNotifyRankTime = SDTimeSecs();

            stBeChallengeData.dwNotifyRank = stBeChallengeData.dwRank;
            stBeChallengeData.qwNotifyRankTime = SDTimeSecs();

        }

        //��ս����Ϣ�޸�
        stChallengeData.byChallTimes++;
        stChallengeData.wContiWin++;
        stChallengeData.qwLastChallTime = SDTimeSecs();
        stChallengeData.byFailedFlag = 0;
		CPlayerMedal* poPlayerMedal = poChallenge->GetOwner()->GetPlayerMedal();
		if ( NULL != poPlayerMedal)
		{
			poPlayerMedal->CheckMedalBySmallType(EMST_RACE_CONTINUE_KILL);
		}
    }
    else
    {
        stChallengeData.byChallTimes++;
        stChallengeData.wContiWin = 0;
        stChallengeData.qwLastChallTime = SDTimeSecs();
        stChallengeData.byFailedFlag = 1;
    }

    //��¼ս��
    stChallengeLog.dwAfterChallengeRank = stChallengeData.dwRank;
    stBechallengeLog.dwAfterChallengeRank = stBeChallengeData.dwRank;
    poChallenge->AddBattleLog(&stChallengeLog, TRUE);
    poBeChallenge->AddBattleLog(&stBechallengeLog);

    //������������
    /*
    //��¼���
    poChallenge->GetOwner()->AddEnemy(poBeChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID);
    poBeChallenge->GetOwner()->AddEnemy(poChallenge->GetOwner()->GetDT_PLAYER_BASE_DATA().dwID);
    */

    //poChallenge->SetSaveState(ESS_WANT_SAVE);
    //poBeChallenge->SetSaveState(ESS_WANT_SAVE);

    //��ս����ս��ɻص�
    poChallenge->OnRaceComplete(bChallengeSuccess);

    return TRUE;
}


SPlayerBaseData* CRaceMgr::GetPlayerBaseData(UINT32 dwRank)
{
    CRank2PlayerBaseDataMapItr itr = m_mapRank2PlayerBaseData.find(dwRank);
    if(itr != m_mapRank2PlayerBaseData.end())
    {
        return itr->second;
    }

    return NULL;
}


//����Ƿ񳬳���ս��Χ,TRUEΪ������Χ
BOOL CRaceMgr::CkOutChallengeRang(UINT32 dwMyselfRank, UINT32 dwEnemyRank)
{
    UINT32 dwInterval = CRacePropMgr::Instance()->GetInterval(dwMyselfRank);
    UINT8 byChaNum = CRacePropMgr::Instance()->GetChallengeNum();

    //��С������ս
    INT32 nTmp = dwMyselfRank - dwInterval * byChaNum;
    if(nTmp <= 0)
    {
        nTmp = 1;
    }
    if(dwEnemyRank < (UINT32)nTmp)
    {
        return TRUE;
    }

    //����С����ս�����������ս����������������ģ�
    if((dwMyselfRank < (UINT32)byChaNum) && (dwEnemyRank > ((UINT32)byChaNum + 1)))
    {
        return TRUE;
    }

    return FALSE;
}


UINT16 CRaceMgr::GetSHowRank(UINT8& byShowNum, DT_RANK_DATA astRankShowInfo[MAX_RANK_SHOW_NUM])
{
    byShowNum = 0;
    for(CRank2PlayerBaseDataMapItr itr = m_mapRank2PlayerBaseData.begin(); ((itr != m_mapRank2PlayerBaseData.end()) && (byShowNum < MAX_RANK_SHOW_NUM)); itr++)
    {
        DT_RANK_DATA& stDT_RANK_DATA = astRankShowInfo[byShowNum];
        SPlayerBaseData* pstPlayerBaseData = itr->second;
        if(NULL == pstPlayerBaseData)
        {
            continue;
        }
        stDT_RANK_DATA.dwRank = pstPlayerBaseData->dwRank;
        stDT_RANK_DATA.dwPlayerID = pstPlayerBaseData->dwID;
        SDStrcpy(stDT_RANK_DATA.aszDispName, pstPlayerBaseData->aszDispName);
        stDT_RANK_DATA.wLevel = pstPlayerBaseData->wLevel;
        //stDT_RANK_DATA.dwFame = pstPlayerBaseData->dwFame;
        stDT_RANK_DATA.wHeroKindID = pstPlayerBaseData->wMainHeroKindID;
        CRacePropMgr::Instance()->GetRankEncourage(stDT_RANK_DATA.dwRank, stDT_RANK_DATA.stRankEncourage);
        stDT_RANK_DATA.dwPower = pstPlayerBaseData->dwPower;

        byShowNum++;
    }

    return ERR_GET_RANK::ID_SUCCESS;
}

BOOL CRaceMgr::Challenge(CPlayer* poMyself, CPlayer* poEnemy, DT_BATTLE_DATA5& stDT_BATTLE_DATA, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallengeEncourage)
{
    if((NULL == poMyself) || (NULL == poEnemy))
    {
        return FALSE;
    }

    BOOL bRobot = (poEnemy->GetDT_PLAYER_BASE_DATA().dwID == CRacePropMgr::Instance()->GetRaceProp().dwRobotID) ? TRUE : FALSE;
    //�������˸�ֵ����Ϊ�Լ���1/4
    if(bRobot)
    {
        DT_BATTLE_BASE_ATTRIBUTE& stMyselfAttr = poMyself->GetCoachHero()->GetDT_BATTLE_ATTRIBUTE();
        DT_BATTLE_BASE_ATTRIBUTE& stEnemyAttr = poEnemy->GetCoachHero()->GetDT_BATTLE_ATTRIBUTE();
        stEnemyAttr.qwHP = stMyselfAttr.qwHP;
        stEnemyAttr.dwAttack = stMyselfAttr.dwAttack >> 2;
    }

    if(!CBattleMgr::Instance()->Battle4(poMyself, poEnemy, stDT_BATTLE_DATA, TRUE))
    {
        return FALSE;
    }

    //��ս�ص�
    BOOL bSuccess = stDT_BATTLE_DATA.byBattleResult == EBT_SUCCESS ? TRUE : FALSE;
	CFewParam& oFewParam = poMyself->GetFewParam();
	if ( bSuccess)
	{
		oFewParam.AddRaceSuccess();
	}
	else
	{
		oFewParam.AddRaceFailed();
	}
    if(!bRobot) //�ǻ�����
    {
        if(!CRaceMgr::Instance()->OnChallenge(poMyself->GetRace(), poEnemy->GetRace(), bSuccess))
        {
            return FALSE;
        }
    }
    else
    {
        stDT_BATTLE_DATA.byBattleResult = EBT_SUCCESS;
        bSuccess = TRUE;
    }
    poMyself->GetRace()->ChallengeEncourage(bSuccess, stChallengeEncourage);
    poMyself->AddGuideRecord(EGF_RACE);
    CTaskMgr::Instance()->OnChallenge(poMyself);

    if(!bRobot) //�ǻ�����
    {
        CPlayerSaveMgr::Instance()->AddPlayerRaceSaveData(poMyself, poEnemy);
    }
    else
    {
        CPlayerSaveMgr::Instance()->AddPlayerRaceSaveData(poMyself, NULL);
    }

    return TRUE;
}

BOOL CRaceMgr::Challenge2(CPlayer* poMyself, CPlayer* poEnemy, DT_BATTLE_DATA3& stDT_BATTLE_DATA, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallengeEncourage)
{
    if((NULL == poMyself) || (NULL == poEnemy))
    {
        return FALSE;
    }

    BOOL bRobot = (poEnemy->GetDT_PLAYER_BASE_DATA().dwID == CRacePropMgr::Instance()->GetRaceProp().dwRobotID) ? TRUE : FALSE;
    //�������˸�ֵ����Ϊ�Լ���1/4
    if(bRobot)
    {
        DT_BATTLE_BASE_ATTRIBUTE& stMyselfAttr = poMyself->GetCoachHero()->GetDT_BATTLE_ATTRIBUTE();
        DT_BATTLE_BASE_ATTRIBUTE& stEnemyAttr = poEnemy->GetCoachHero()->GetDT_BATTLE_ATTRIBUTE();
        stEnemyAttr.qwHP = stMyselfAttr.qwHP;
        stEnemyAttr.dwAttack = stMyselfAttr.dwAttack >> 2;
    }

    if(!CBattleMgr::Instance()->Battle2(poMyself, poEnemy, stDT_BATTLE_DATA, TRUE))
    {
        return FALSE;
    }

    //��ս�ص�
    BOOL bSuccess = stDT_BATTLE_DATA.byBattleResult == EBT_SUCCESS ? TRUE : FALSE;
	CFewParam& oFewParam = poMyself->GetFewParam();
	if ( bSuccess)
	{
		oFewParam.AddRaceSuccess();
	}
	else
	{
		oFewParam.AddRaceFailed();
	}
    if(!bRobot) //�ǻ�����
    {
        if(!CRaceMgr::Instance()->OnChallenge(poMyself->GetRace(), poEnemy->GetRace(), bSuccess))
        {
            return FALSE;
        }
    }
    else
    {
        stDT_BATTLE_DATA.byBattleResult = EBT_SUCCESS;
        bSuccess = TRUE;
    }
    poMyself->GetRace()->ChallengeEncourage(bSuccess, stChallengeEncourage);
    poMyself->AddGuideRecord(EGF_RACE);
    CTaskMgr::Instance()->OnChallenge(poMyself);

    if(!bRobot) //�ǻ�����
    {
        CPlayerSaveMgr::Instance()->AddPlayerRaceSaveData(poMyself, poEnemy);
    }
    else
    {
        CPlayerSaveMgr::Instance()->AddPlayerRaceSaveData(poMyself, NULL);
    }

    return TRUE;
}

BOOL CRaceMgr::Challenge3(CPlayer* poMyself, CPlayer* poEnemy, DT_BATTLE_DATA4& stDT_BATTLE_DATA, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallengeEncourage)
{
	if((NULL == poMyself) || (NULL == poEnemy))
	{
		return FALSE;
	}

	BOOL bRobot = (poEnemy->GetDT_PLAYER_BASE_DATA().dwID == CRacePropMgr::Instance()->GetRaceProp().dwRobotID) ? TRUE : FALSE;
	//�������˸�ֵ����Ϊ�Լ���1/4
	if(bRobot)
	{
		DT_BATTLE_BASE_ATTRIBUTE& stMyselfAttr = poMyself->GetCoachHero()->GetDT_BATTLE_ATTRIBUTE();
		DT_BATTLE_BASE_ATTRIBUTE& stEnemyAttr = poEnemy->GetCoachHero()->GetDT_BATTLE_ATTRIBUTE();
		stEnemyAttr.qwHP = stMyselfAttr.qwHP;
		stEnemyAttr.dwAttack = stMyselfAttr.dwAttack >> 2;
	}

	if(!CBattleMgr::Instance()->Battle3(poMyself, poEnemy, stDT_BATTLE_DATA, TRUE))
	{
		return FALSE;
	}

	//��ս�ص�
	BOOL bSuccess = stDT_BATTLE_DATA.byBattleResult == EBT_SUCCESS ? TRUE : FALSE;
	CFewParam& oFewParam = poMyself->GetFewParam();
	if ( bSuccess)
	{
		oFewParam.AddRaceSuccess();
	}
	else
	{
		oFewParam.AddRaceFailed();
	}
	if(!bRobot) //�ǻ�����
	{
		if(!CRaceMgr::Instance()->OnChallenge(poMyself->GetRace(), poEnemy->GetRace(), bSuccess))
		{
			return FALSE;
		}
	}
	else
	{
		stDT_BATTLE_DATA.byBattleResult = EBT_SUCCESS;
		bSuccess = TRUE;
	}
	poMyself->GetRace()->ChallengeEncourage(bSuccess, stChallengeEncourage);
	poMyself->AddGuideRecord(EGF_RACE);
	CTaskMgr::Instance()->OnChallenge(poMyself);

	if(!bRobot) //�ǻ�����
	{
		CPlayerSaveMgr::Instance()->AddPlayerRaceSaveData(poMyself, poEnemy);
	}
	else
	{
		CPlayerSaveMgr::Instance()->AddPlayerRaceSaveData(poMyself, NULL);
	}

	return TRUE;
}
SPlayerBaseData* CRaceMgr::GetRankPlayerBaseData(UINT32 dwRank)
{
    CRank2PlayerBaseDataMapItr itr = m_mapRank2PlayerBaseData.find(dwRank);
    if(itr != m_mapRank2PlayerBaseData.end())
    {
        return itr->second;
    }

    return NULL;
}

// ���뾺������ǰ����(һ����ǰ100��)��������¼�����ս��
VOID CRaceMgr::LoadTopRacerPower()
{
    UINT16 wTopNum = CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer();/*ǰ���ٸ�*/
    for(UINT32 wRank = 1; wRank <= wTopNum; wRank++)
    {
        SPlayerBaseData *pstPlayerBase = GetRankPlayerBaseData(wRank);
        if(NULL == pstPlayerBase)
        {
            continue;
        }

        m_mapOfflineRacerBaseData[wRank] = *pstPlayerBase;
        m_wLastOfflineRacerRank = wRank;

        // ȡ��������ݣ����½���ս��������
        CGetPlayerDataMgr::Instance()->GetPlayerData(pstPlayerBase->dwID, GET_PLAYERDATATYPE_RECALC_POWER, pstPlayerBase->dwID);
    }
}

// ����������ʱ��ǰ���������ȫ������ɹ�
VOID CRaceMgr::OnAllOfflineRacerLoaded()
{
    // ��ӡս���Ա��б�
    UINT16 wTotalChangedCnt = EchoRacerPowerComparison();
    
    // ����Ƿ������ս����д�����ݿ�
    if(CSinglePramMgr::Instance()->GetIsSaveNewRacerPowerToDB())
    {
        SaveOfflineRacerPowerAtStartUp();
    }

    ClearOfflineRacerAtStartUp();

    if(wTotalChangedCnt > 0)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Error: detecting there are %u of top %u race players' power different from db, terminate game server!!!"),
            MSG_MARK, wTotalChangedCnt, CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer());

        SDGetApp()->Terminate();
    }
}

// ����������ʱ����������������Ļص�
VOID CRaceMgr::OnLoadOfflineRacerAtStartUp(CPlayer *poOfflineRacer)
{
    if(NULL == poOfflineRacer)
    {
        return;
    }

    // �ھ�������ǰ������ұ�ȫ������ǰ�������������������е�ĳЩ����Ѿ����ߣ���Ȼ�����쳣�������Ӧ�������߷�����ս���ȶԣ�
    if(poOfflineRacer->GetUser())
    {
        return;
    }

    m_mapOfflineRacerAtStartUp[poOfflineRacer->GetRank()] = poOfflineRacer;
    
    UINT16 wRacerRank = poOfflineRacer->GetRank();
    if(wRacerRank == m_wLastOfflineRacerRank)
    {
        OnAllOfflineRacerLoaded();
    }
}

// ������ʱ����ľ������������ս����д�����ݿ�
VOID CRaceMgr::SaveOfflineRacerPowerAtStartUp()
{
    DBG_INFO(_SDT("start save top %u players' power into DB"), CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer());
    DBG_INFO(_SDT("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"));

    UINT16 wTotalSaveCnt = 0;

    // ��ս�������仯�ľ������������һһ��д�����ݿ�
    UINT16 wHowManyRacer = CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer();
    for(UINT16 i = wHowManyRacer; i > 0; i--)
    {
        CPlayer *poOfflineRacer = m_mapOfflineRacerAtStartUp[i];
        if(NULL == poOfflineRacer)
        {
            continue;
        }

        COfflineRacerBaseDataMap::iterator itr = m_mapOfflineRacerBaseData.find(i);
        if(itr == m_mapOfflineRacerBaseData.end())
        {
            continue;
        }

        SPlayerBaseData &poPlayerBase = itr->second;

        UINT32 dwNewPower = poOfflineRacer->GetDT_PLAYER_BASE_DATA().dwPower;
        UINT32 dwOldPower = poPlayerBase.dwPower;

        (dwNewPower != dwOldPower) ? ++wTotalSaveCnt : 0;

        // �Ѹ���ҵ�����ս����д�����ݿ�
        CPlayerSaveMgr::Instance()->SavePlayerData(poOfflineRacer);

        DBG_INFO(_SDT("// rank<%-3u>: save newest power [%-8u] %s old power[%-8u], playerID=%-8u, name=%-12s //"), 
            i, dwNewPower, raceutil::CmpPower(dwNewPower, dwOldPower), dwOldPower, poOfflineRacer->GetID(), SDUTF82Local(poOfflineRacer->GetDT_PLAYER_BASE_DATA().aszDispName).c_str());
    }

    DBG_INFO(_SDT("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"));
    DBG_INFO(_SDT("end save, total save count = %u"), wTotalSaveCnt);
}

// ������ʱ����ľ����������յ�
VOID CRaceMgr::ClearOfflineRacerAtStartUp()
{
    BOOL bSaveNewPower = CSinglePramMgr::Instance()->GetIsSaveNewRacerPowerToDB();
    UINT16 wHowManyRacer = CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer();

    // ��յ��������ݣ����ң������ֹ��д����ս������removeplayer�Է�ֹ�Զ���ʱ��д
    for(UINT16 i = 0; i < wHowManyRacer; i++)
    {
        CPlayer *poOfflineRacer = m_mapOfflineRacerAtStartUp[i];
        if(NULL == poOfflineRacer)
        {
            continue;
        }

        if(poOfflineRacer->GetUser())
        {
            continue;
        }

        // �Ƿ������ս����д�����ݿ�
        // ��������ս�������쳣ʱ�����ⲻ���Ǿ�ս��ֵ�Է�����٣�
        if(FALSE == bSaveNewPower)
        {
            // �Ƴ�playerΪ�˷�ֹ�Զ���ʱ��д����
            CPlayerMgr::Instance()->RemovePlayer(poOfflineRacer->GetID());
        }
    }

    m_mapOfflineRacerAtStartUp.clear();
    m_mapOfflineRacerBaseData.clear();
}

// ��ӡ������������¾�ս���Ա��б�������ս��ǰ��ƥ����������
UINT16 CRaceMgr::EchoRacerPowerComparison()
{
    DBG_INFO(_SDT("start power compare, load top %u players"), CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer());
    DBG_INFO(_SDT("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"));

    UINT16 wTotalChangedCnt = 0;

    // ���ζԱ�������ǰ�ľ�������ҵ��¾�ս����д����־
    UINT16 wHowManyRacer = CSinglePramMgr::Instance()->GetReCalcHowManyTopRacer();
    for(UINT16 i = wHowManyRacer; i > 0; i--)
    {
        CPlayer *poOfflineRacer = m_mapOfflineRacerAtStartUp[i];
        if(NULL == poOfflineRacer)
        {
            continue;
        }

        COfflineRacerBaseDataMap::iterator itr = m_mapOfflineRacerBaseData.find(i);
        if(itr == m_mapOfflineRacerBaseData.end())
        {
            continue;
        }

        SPlayerBaseData &poPlayerBase = itr->second;

        UINT32 dwNewPower = poOfflineRacer->GetDT_PLAYER_BASE_DATA().dwPower;
        UINT32 dwOldPower = poPlayerBase.dwPower;

        (dwNewPower != dwOldPower) ? ++wTotalChangedCnt : 0;
        
        DBG_INFO(_SDT("// rank<%-3u>: new power[%-8u] %s old power[%-8u], playerID=%-8u, name=%-12s //"), 
            i, dwNewPower, raceutil::CmpPower(dwNewPower, dwOldPower), dwOldPower, poOfflineRacer->GetID(), SDUTF82Local(poOfflineRacer->GetDT_PLAYER_BASE_DATA().aszDispName).c_str());
    }

    DBG_INFO(_SDT("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"));
    DBG_INFO(_SDT("end power compare, total changed count = %u"), wTotalChangedCnt);

    return wTotalChangedCnt;
}