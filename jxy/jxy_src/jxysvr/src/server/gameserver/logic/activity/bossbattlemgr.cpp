#include "bossbattlemgr.h"
#include "bossbattle.h"
#include "bossbbattlelog.h"
#include <logic/player/playermgr.h>
#include <logic/monster/monster.h>
#include <logic/battle/battlemgr.h>
#include <framework/gsapi.h>
#include <db/dbmgr.h>
#include <logic/event/timereventmgr.h>
#include <logic/monster/monstermgr.h>
#include <logic/lua/luamgr.h>
#include <net/db/dbpktbuilder.h>
#include <logic/record/recordmgr.h>
#include <algorithm>
#include <functional>
#include <net/cli/usermgr.h>
#include <logic/base/basedefine.h>
#include <logic/other/singleprammgr.h>
#include <logic/other/locale.h>
#include <logic/vip/vippropmgr.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <logic/build/build.h>
#include <framework/gsconfig.h>
#include <logic/player/player.h>
#include <logic/other/errmsgmgr.h>
#include <logic/chat/chatmgr.h>

#include <errdef.h>

using namespace std;

IMPLEMENT_SINGLETON(CBossBattleMgr)

CBossBattleMgr::CBossBattleMgr()
{
    m_poBoss = NULL;
    m_pstCurBossBProp = NULL;
    m_bActivityOver = TRUE;
    m_wIncRateByStory = 0;
    m_wIncRateByGold = 0;
    m_qwStartTime = 0;
    m_byLastActivityID = 0;
    m_qwBossTotalHP = 0;
    m_bySyncActivityID = 0;
    m_qwSyncCurBossHP = 0;
    m_qwSyncStartTime = 0;
    m_bSyncFlag = FALSE;

    m_vecAllEnterPlayer.clear();
    m_mapAllEnterPlayer.clear();
    m_mapAllPlayer.clear();
    m_itrCur = m_mapAllEnterPlayer.end();
}

CBossBattleMgr::~CBossBattleMgr()
{

}

CBossBBattleLog* CBossBattleMgr::CreateBattleLog()
{
    return m_oBossBBLShmemObjMgr.Alloc();
}

VOID CBossBattleMgr::RemoveBattleLog(CBossBBattleLog* poBossBBattleLog)
{
    if(poBossBBattleLog)
    {
        m_oBossBBLShmemObjMgr.Free(poBossBBattleLog);
    }
}


BOOL CBossBattleMgr::Init()
{
    // ��ʼ��CBossBattlePropMgr������
    if(FALSE == CBossBattlePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBossBattlePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CBossBattlePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CBossBattlePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    if(!InitModuleDataFromDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitDataFromDB failed!"), MSG_MARK);
        return FALSE;
    }

    if(!InitModuleLogDataFromDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitModuleLogDataFromDB failed!"), MSG_MARK);
        return FALSE;
    }

    if(!InitEvent())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitEvent failed!"), MSG_MARK);
        return FALSE;
    }

	if (! LoadCloseArea())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: LoadCloseArea failed!"), MSG_MARK);
		return FALSE;
	}


    return TRUE;
}

BOOL CBossBattleMgr::LoadCloseArea()
{
	SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetCfgDBSession();
	if(NULL == pDBSession)
	{
		return FALSE;
	}

	CHAR szSql[1024] = {0};
	sprintf(szSql, "select * from closedarea ;");

	SGDP::ISDDBRecordSet* pRecordSet = NULL;
	string strError;
	INT32 nRet = pDBSession->ExecuteSqlRs(szSql, &pRecordSet, 0, &strError );
	if(SDDB_HAS_RECORDSET == nRet)
	{
		while(pRecordSet->GetRecord())
		{
			UINT16 wZoneID = SGDP::SDAtou( pRecordSet->GetFieldValueByName("ZoneID"));
			m_setCloseArea.insert(wZoneID);
		}
	}
	else if(SDDB_NO_RECORDSET == nRet)
	{
		if(NULL != pRecordSet)
		{
			pRecordSet->Release();
			pRecordSet = NULL;
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	if(NULL != pRecordSet)
	{
		pRecordSet->Release();
		pRecordSet = NULL;
	}

	return TRUE;
}



BOOL CBossBattleMgr::InitModuleDataFromDB()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }

    CHAR szSql[1024] = {0};
    sprintf(szSql, "select * from module where KeyID = '%d';", EMDT_BossBattle);

    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    string strError;
    INT32 nRet = pDBSession->ExecuteSqlRs(szSql, &pRecordSet, 0, &strError );
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            UINT32 dwLen = pRecordSet->GetFieldLengthByName( "Value" );
            if (0 != dwLen)
            {
                DT_BOSS_BATTLE_DATA stDT_BOSS_BATTLE_DATA = {0};
                if( -1 == stDT_BOSS_BATTLE_DATA.DecodeSaveData( pRecordSet->GetFieldValueByName("Value"), dwLen ) )
                {
                    SYS_CRITICAL( _SDT("[%s: %d] DT_BOSS_BATTLE_DATA.DecodeSaveData Failed!"), MSG_MARK);
                    return FALSE;
                }
                m_mapBassBattleModuleData[stDT_BOSS_BATTLE_DATA.byActivityID] = stDT_BOSS_BATTLE_DATA;
            }
        }
    }
    else if(SDDB_NO_RECORDSET == nRet)
    {
        if(NULL != pRecordSet)
        {
            pRecordSet->Release();
            pRecordSet = NULL;
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    return TRUE;
}


BOOL CBossBattleMgr::InitModuleLogDataFromDB()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }

    CHAR szSql[1024] = {0};
    sprintf(szSql, "select * from modulelog where KeyID = '%d' order by OverTime desc limit %u;", EMDT_BossBattle, MAX_BOSSB_BATTLE_LOG_NUM * 2);

    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    string strError;
    INT32 nRet = pDBSession->ExecuteSqlRs(szSql, &pRecordSet, 0, &strError );
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            string strOverTime = pRecordSet->GetFieldValueByName( "OverTime" );
            UINT32 dwLen = pRecordSet->GetFieldLengthByName( "Value" );
            if (0 != dwLen)
            {
                DT_BOSS_BATTLE_DATA stDT_BOSS_BATTLE_DATA = {0};
                if( -1 == stDT_BOSS_BATTLE_DATA.DecodeSaveData( pRecordSet->GetFieldValueByName("Value"), dwLen ) )
                {
                    SYS_CRITICAL( _SDT("[%s: %d] DT_BOSS_BATTLE_DATA.DecodeSaveData Failed!"), MSG_MARK);
                    continue;
                }
                m_mapBossBBLData[stDT_BOSS_BATTLE_DATA.qwOverTime] = stDT_BOSS_BATTLE_DATA;
            }
        }

    }
    else if(SDDB_NO_RECORDSET == nRet)
    {
        if(NULL != pRecordSet)
        {
            pRecordSet->Release();
            pRecordSet = NULL;
        }
        return TRUE;
    }
    else
    {
        SYS_CRITICAL( _SDT("[%s: %d] InitModuleLogDataFromDB exec sql failed[%s]!"), MSG_MARK, strError.c_str());
        return FALSE;
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    return TRUE;
}


BOOL CBossBattleMgr::InitEvent()
{
    CBossBPropMap& mapBossBProp = CBossBattlePropMgr::Instance()->GetBossBPropMap();
    for(CBossBPropMapItr itr = mapBossBProp.begin(); itr != mapBossBProp.end(); itr++)
    {
        SBossBProp& stProp = itr->second;
        CTimerEventMgr::Instance()->AddBossBattleEvent(stProp.byActivityId, TRUE);
        CTimerEventMgr::Instance()->AddBossBattleEvent(stProp.byActivityId, FALSE);

        //BOSSս������
        //CTimerEventMgr::Instance()->AddNoticeEventEvent(ENT_BOSSBATTLE, stProp.dwStartTime, stProp.dwEndTime, stProp.dwStartEnterTime);
    }

    return TRUE;
}


VOID CBossBattleMgr::UnInit()
{
    CBossBattlePropMgr::Instance()->UnInit();
    CBossBattlePropMgr::DestroyInstance();
}


BOOL CBossBattleMgr::OnStartEvent(UINT8 byActivityID)
{
    SBossBProp* pstBossBProp = CBossBattlePropMgr::Instance()->GetBossBPropByID(byActivityID);
    if(NULL == pstBossBProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: pstBossBProp[%d] is NULL!"), MSG_MARK, byActivityID);
        return FALSE;
    }

    if(SDNow().DiffDateDay(CGSConfig::Instance()->GetServerOpentTime()) < pstBossBProp->wOpenActivityPassDay)
    {
        //����ǰ2�첻����
        return TRUE;
    }

    CMonster* m_poMonster = CMonsterMgr::Instance()->CreateMonster();
    if(NULL == m_poMonster)
    {
        return FALSE;
    }

	//��ֵ�ȼ�
	m_wBossLevel = pstBossBProp->wBossStartLevel;

    map<UINT8, DT_BOSS_BATTLE_DATA>::iterator itr = m_mapBassBattleModuleData.find(byActivityID);
    if(itr != m_mapBassBattleModuleData.end())
    {
        m_wBossLevel = 0 == itr->second.wLastLevel ? m_wBossLevel : itr->second.wLastLevel;
        if(itr->second.byNeedUpgrade)
        {
            m_wBossLevel++;
        }
    }
    m_wBossLevel = m_wBossLevel > pstBossBProp->wBossMaxLevel ? pstBossBProp->wBossMaxLevel : m_wBossLevel;
    if(!m_poMonster->Init(pstBossBProp->wBossMonsterID, 1, TRUE, m_wBossLevel))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: boss[%d] init failed!"), MSG_MARK, pstBossBProp->wBossMonsterID);
        return FALSE;
    }

    //�����֮ǰ��boss
    if(m_poBoss)
    {
        CMonsterMgr::Instance()->RemoveMonster(m_poBoss);
        m_poBoss = NULL;
    }

    UINT64 qwNow = SDTimeSecs();

    m_poBoss = m_poMonster;
    m_pstCurBossBProp = pstBossBProp;
    m_bActivityOver = FALSE;
    m_qwStartTime = SDTimeSecs();
    m_byLastActivityID = m_pstCurBossBProp->byActivityId;

    m_wIncRateByStory = CLuamgr::Instance()->GetIncRateByStory();
    m_wIncRateByGold = CLuamgr::Instance()->GetIncRateByGold();

    m_qwBossTotalHP = m_poBoss->GetDT_BATTLE_ATTRIBUTE().qwHP;

    memset(m_astTopHurtInfo, 0, sizeof(m_astTopHurtInfo));

    // ������Ƶ����ʾ���ʼ֪ͨ
    AddChatOnActivityStart(qwNow - GetDayPassSecond(qwNow) + m_pstCurBossBProp->dwStartTime/*���Ԥ�ڿ�ʼʱ��*/, qwNow);

    //ͬ��HP
    if((m_pstCurBossBProp->byActivityId == m_bySyncActivityID) && (m_qwSyncCurBossHP < m_qwBossTotalHP) && (0 != m_qwSyncCurBossHP) && (0 != m_bySyncActivityID)) //Ѫ��Ϊ0˵���Ѿ�����������ͬ��
    {
        USR_INFO(_SDT("[%s: %d]: sync bossb data, sync activityid[%u], sync cur hp[%llu],  "), MSG_MARK, m_bySyncActivityID, m_qwSyncCurBossHP);
        m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP = m_qwSyncCurBossHP;
        m_bySyncActivityID = 0;
        m_qwSyncCurBossHP = 0;
        m_qwStartTime = m_qwSyncStartTime;
        m_bSyncFlag = TRUE;
    }
    else
    {
        //��������ʹ��֮ǰ��Ѫ��
        map<UINT8, DT_BOSS_BATTLE_DATA>::iterator itr = m_mapBassBattleModuleData.find(m_pstCurBossBProp->byActivityId);
        if(itr != m_mapBassBattleModuleData.end())
        {
            DT_BOSS_BATTLE_DATA& stDT_BOSS_BATTLE_DATA = itr->second;
            if(IsToday(stDT_BOSS_BATTLE_DATA.qwSaveTime))
            {
                USR_INFO(_SDT("[%s: %d]: reset bossb data, activityid[%u], sync cur hp[%llu],  "), MSG_MARK, m_pstCurBossBProp->byActivityId, stDT_BOSS_BATTLE_DATA.qwCurHP);
                if(0 != stDT_BOSS_BATTLE_DATA.qwCurHP) //�ѽ������������¸�ֵ
                {
                    m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP = stDT_BOSS_BATTLE_DATA.qwCurHP;
                    //m_qwStartTime = stDT_BOSS_BATTLE_DATA.qwStartTime;
                    memcpy(m_astTopHurtInfo, stDT_BOSS_BATTLE_DATA.astTopHurtInfo, sizeof(m_astTopHurtInfo));
                }
            }
        }
    }

    //��ֵ������ǰ��¼
    DT_BOSS_BATTLE_DATA& stDT_BOSS_BATTLE_DATA = m_mapBassBattleModuleData[m_pstCurBossBProp->byActivityId];
    memset(&stDT_BOSS_BATTLE_DATA.astBossBTopEncInfo, 0, sizeof(stDT_BOSS_BATTLE_DATA.astBossBTopEncInfo));
    memset(&stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo, 0, sizeof(stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo));
    stDT_BOSS_BATTLE_DATA.qwOverTime = 0;
    stDT_BOSS_BATTLE_DATA.qwStartTime = m_qwStartTime;
    stDT_BOSS_BATTLE_DATA.byActivityID = m_pstCurBossBProp->byActivityId;
    stDT_BOSS_BATTLE_DATA.wLastLevel = m_wBossLevel;
    stDT_BOSS_BATTLE_DATA.qwSaveTime = SDTimeSecs();

    return TRUE;
}



BOOL CBossBattleMgr::OnEndEvent(UINT8 byActivityID)
{
    //AUTOCYCLE;

    //�ʱ�������δ��ɱ��������
    if(!m_bActivityOver)
    {
        ActivityOver();
    }

    m_vecAllEnterPlayer.clear();
    m_mapAllEnterPlayer.clear();
    m_mapAllPlayer.clear();
    m_pstCurBossBProp = NULL;
    m_bActivityOver = TRUE;
    m_bSyncFlag = FALSE;

    return TRUE;
}


//��ҽ���
UINT16 CBossBattleMgr::OnEnter(CPlayer* poPlayer, UINT16 wPosX, UINT16 wPosY, DT_BOSSB_MY_DATA_CLI& stMyBossBInfo, DT_BOSSB_PLAYER_DATA_CLI_LST& stPlayerInfo,
                               DT_BOSSB_DATA_CLI2& stBossBInfo, DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM], DT_HURT_ENC_DATA& stHurtEncInfo)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    CBuild* poBuild = poPlayer->GetBuild(EBK_BOSSBATTLE);
    if(NULL == poBuild)
    {
        return ERR_ENTER_BOSSB::ID_BOSSB_UNLOCK;
    }
    poBuild->OnOpen();

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return ERR_ENTER_BOSSB::ID_BOSSB_UNSTART;
    }
    UINT8 byEnterType = 0; //0 ��һ�ν���, 1 �������뿪, 2 �������ǰֻ������ͬ������
    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        RETURN_OTHER_ERR;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
    UINT32 dwPassSec = GetDayPassSecond(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime);
    if(!IsToday(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime) || (dwPassSec < m_pstCurBossBProp->dwStartEnterTime) || (dwPassSec > m_pstCurBossBProp->dwEndTime)) //�ϴν��벻�ǽ��� || �ϴν��벻�ǵ�ǰ������½���
    {
        byEnterType = 0;
    }
    else
    {
        if(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastLeaveActivityTime >= stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime)
        {
            byEnterType = 1;
        }
        else
        {
            byEnterType = 2;
        }
    }

    //��ӹ���
    if(m_mapAllEnterPlayer.find(dwPlayerID) == m_mapAllEnterPlayer.end())
    {
        m_mapAllEnterPlayer[dwPlayerID] = dwPlayerID;
        m_vecAllEnterPlayer.push_back(dwPlayerID);
        m_mapAllPlayer[dwPlayerID] = dwPlayerID;
    }

    //��տ��������������ˣ���������֮ǰ����Ķ������¼������
    if(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime < m_qwStartTime)
    {
        byEnterType = 0;
    }

    switch(byEnterType)
    {
        //��һ�ν���
    case 0:
    {
        memset(&stDT_BOSS_BATTLE_PLAYER_DATA, 0, sizeof(stDT_BOSS_BATTLE_PLAYER_DATA));
        poBossBattle->InitEnterData();

        ////λ�ø�ֵ������
        //stDT_BOSS_BATTLE_PLAYER_DATA.wPosX = m_pstCurBossBProp->wBirthPosX;
        //stDT_BOSS_BATTLE_PLAYER_DATA.wPosY = m_pstCurBossBProp->wBirthPosY;
        //ʹ�ÿͻ��˵�����
        stDT_BOSS_BATTLE_PLAYER_DATA.wPosX = wPosX;
        stDT_BOSS_BATTLE_PLAYER_DATA.wPosY = wPosY;

        //��ֵʱ��
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime = SDTimeSecs();
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastLeaveActivityTime = 0;

        //��ֵ��ʼ��עIdx
        stDT_BOSS_BATTLE_PLAYER_DATA.dwSyncStartIdx = RandomReseed(m_vecAllEnterPlayer.size());

        //��ӹ�ע
        Addattention(poPlayer);
    }
    break;
    //�뿪�ֽ���
    case 1:
    {
        poBossBattle->InitEnterData();

        //ʹ�ÿͻ��˵�����
        stDT_BOSS_BATTLE_PLAYER_DATA.wPosX = wPosX;
        stDT_BOSS_BATTLE_PLAYER_DATA.wPosY = wPosY;

        //��ֵʱ��
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime = SDTimeSecs();
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastLeaveActivityTime = 0;

        //��ֵ��ʼ��עIdx
        stDT_BOSS_BATTLE_PLAYER_DATA.dwSyncStartIdx = RandomReseed(m_vecAllEnterPlayer.size());

        //��ӹ�ע
        Addattention(poPlayer);
    }
    break;
    //�������ǰֻ������ͬ������
    case 2:
        if(m_bSyncFlag)//gsͬ������ң�������ӹ�ע
        {
            poBossBattle->InitEnterData();

            //��ӹ�ע
            Addattention(poPlayer);
        }
        break;
    default:
        memset(&stDT_BOSS_BATTLE_PLAYER_DATA, 0, sizeof(stDT_BOSS_BATTLE_PLAYER_DATA));
        poBossBattle->InitEnterData();

        ////λ�ø�ֵ������
        //stDT_BOSS_BATTLE_PLAYER_DATA.wPosX = m_pstCurBossBProp->wBirthPosX;
        //stDT_BOSS_BATTLE_PLAYER_DATA.wPosY = m_pstCurBossBProp->wBirthPosY;
        //ʹ�ÿͻ��˵�����
        stDT_BOSS_BATTLE_PLAYER_DATA.wPosX = wPosX;
        stDT_BOSS_BATTLE_PLAYER_DATA.wPosY = wPosY;

        //��ֵʱ��
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime = SDTimeSecs();
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastLeaveActivityTime = 0;

        //��ֵ��ʼ��עIdx
        stDT_BOSS_BATTLE_PLAYER_DATA.dwSyncStartIdx = RandomReseed(m_vecAllEnterPlayer.size());

        //��ӹ�ע
        Addattention(poPlayer);

        break;
    }

    GetDT_BOSSB_MY_DATA_CLI(poPlayer, stDT_BOSS_BATTLE_PLAYER_DATA, stMyBossBInfo);

    GetDT_BOSSB_DATA_CLI(stBossBInfo);

    //������ʾ�����Ϣ
    GetShowPlayerInfo(poPlayer, stDT_BOSS_BATTLE_PLAYER_DATA.dwSyncStartIdx, stPlayerInfo);

    GetTopHurtRate(astTopHurtInfo);

    GetHurtEncInfo(poPlayer->GetLevel(), stDT_BOSS_BATTLE_PLAYER_DATA, stHurtEncInfo);

    poPlayer->GetLocale().OnEnterBossB();

    return ERR_ENTER_BOSSB::ID_SUCCESS;
}

VOID CBossBattleMgr::GetTopHurtRate(DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM])
{
    //AUTOCYCLE;

    for(UINT8 byIdx = 0; byIdx < MAX_BOSS_ENC_TOP_NUM; byIdx++)
    {
        DT_BOSSB_HURT_RATE& stTopEnc1 = astTopHurtInfo[byIdx];
        stTopEnc1.dwPlayerID = m_astTopHurtInfo[byIdx].dwPlayerID;
        SDStrcpy(stTopEnc1.aszDispName, m_astTopHurtInfo[byIdx].aszDispName);
        stTopEnc1.dwHurtValue = m_astTopHurtInfo[byIdx].dwHurtValue;
        stTopEnc1.dwHurtRate = m_astTopHurtInfo[byIdx].dwHurtRate;
        stTopEnc1.dwHurtRank = byIdx + 1;
    }
}

VOID CBossBattleMgr::GetHurtEncInfo(UINT16 wPlayerLevel, DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, DT_HURT_ENC_DATA& stHurtEncInfo, UINT32 dwHurtValue)
{
    //AUTOCYCLE;

    UINT32 dwEncCoin = 0;
    UINT32 dwEncJingJie = 0;
    if(0 != dwHurtValue)
    {
        dwEncCoin =  CLuamgr::Instance()->GetBossBHurtEncCoin(wPlayerLevel, dwHurtValue);
        dwEncJingJie =  CLuamgr::Instance()->GetBossBHurtEncJingJie(wPlayerLevel, dwHurtValue);
    }
    stDT_BOSS_BATTLE_PLAYER_DATA.dwEncCoin += dwEncCoin;
    stDT_BOSS_BATTLE_PLAYER_DATA.dwEncJingJie += dwEncJingJie;
    stHurtEncInfo.dwEncCoin = stDT_BOSS_BATTLE_PLAYER_DATA.dwEncCoin;
    stHurtEncInfo.dwEncJingJie = stDT_BOSS_BATTLE_PLAYER_DATA.dwEncJingJie;
}


VOID CBossBattleMgr::Addattention(CPlayer* poNoticePlayer)
{
    //AUTOCYCLE;

    if(NULL == poNoticePlayer)
    {
        return;
    }
    UINT32 dwNoticePlayerID = poNoticePlayer->GetID();
    CBossBattle* poNoticeBossBattle = poNoticePlayer->GetBossBattle();
    UINT32 dwSize = m_vecAllEnterPlayer.size();
    //PKT_BOSSB_POS_NTF stNtf;
    //stNtf.dwPlayerNum = m_vecAllEnterPlayer.size();
    //stNtf.bySyncType = BOSSB_POS_TYPE_ENTER;
    //GetBOSSB_PLAYER_DATA_CLI(poNoticePlayer, stNtf.stPlayerInfo);
    if(dwSize <= (UINT32)(m_pstCurBossBProp->byShowNum + 1))
    {
        for(UINT8 byIdx = 0; (byIdx < dwSize); byIdx++)
        {
            UINT32 dwID = m_vecAllEnterPlayer[byIdx];
            if(dwNoticePlayerID == dwID)
            {
                continue;
            }
            CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(dwID);
            if(NULL == poPlayer)
            {
                continue;
            }
            ////����ע����ҷ�Enter֪ͨ
            //poPlayer->SendMsg((const CHAR*)(&stNtf), BOSSB_POS_NTF);
            //���ӹ�ע
            poNoticeBossBattle->OnAddBeattaction(dwID, TRUE);
            CBossBattle *poBossBattle = poPlayer->GetBossBattle();
            if(poBossBattle)
                poBossBattle->OnAddBeattaction(dwNoticePlayerID);
        }
    }
    else
    {
        BOOL bRereturn = FALSE;
        UINT32 dwSyncStartIdx = poNoticeBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().dwSyncStartIdx;
        UINT8 byNum = 0;
        for(UINT8 byIdx = dwSyncStartIdx; ((byIdx < dwSize) && (byNum < MAX_BOSSB_SHOW_PLAYER_NUM) && (byNum < m_pstCurBossBProp->byShowNum)); )
        {
            UINT32 dwPlayerID = m_vecAllEnterPlayer[byIdx];
            if(dwNoticePlayerID != dwPlayerID)
            {
                CPlayer* poPlayerTmp = CPlayerMgr::Instance()->FindPlayer(dwPlayerID);
                if(poPlayerTmp)
                {
                    CBossBattle *poBossBattle = poPlayerTmp->GetBossBattle();
                    if(poBossBattle)
                        poBossBattle->OnAddBeattaction(dwNoticePlayerID, TRUE);
                    byNum++;
                }
            }

            byIdx++;
            if((byIdx >= dwSize) &&  (!bRereturn )) //��ĩβ����ͷ
            {
                byIdx = 0;
                bRereturn = TRUE;
            }
            if(bRereturn && byIdx >= dwSyncStartIdx) //�Ѿ�����ʼ��
            {
                break;
            }
        }
    }
}


VOID CBossBattleMgr::Delattention(CPlayer* poNoticePlayer)
{
    //AUTOCYCLE;

    if(NULL == poNoticePlayer)
    {
        return;
    }
    CBossBattle* poNoticeBossBattle = poNoticePlayer->GetBossBattle();
    if(NULL == poNoticeBossBattle)
    {
        return;
    }
    UINT32 dwNoticePlayerID = poNoticePlayer->GetID();
    UINT32 dwSize = m_vecAllEnterPlayer.size();
    //PKT_BOSSB_POS_NTF stNtf;
    //stNtf.dwPlayerNum = m_vecAllEnterPlayer.size();
    //stNtf.bySyncType = BOSSB_POS_TYPE_LEAVE;
    //GetBOSSB_PLAYER_DATA_CLI(poNoticePlayer, stNtf.stPlayerInfo);
    C3232Map& mapBeattentionID = poNoticeBossBattle->GetBeattentionIDMap();
    for(C3232MapItr itr = mapBeattentionID.begin(); itr != mapBeattentionID.end(); )
    {
        UINT32 dwID = itr->first;
        CPlayer* poFans = CPlayerMgr::Instance()->FindPlayer(dwID);
        if((NULL == poFans) || (poFans == poNoticePlayer) || (m_mapAllEnterPlayer.find(dwID) == m_mapAllEnterPlayer.end()))
        {
            mapBeattentionID.erase(itr++);
            continue;
        }
        ////����ע����ҷ�Leave֪ͨ
        //poFans->SendMsg((const CHAR*)(&stNtf), BOSSB_POS_NTF);
        CBossBattle* poFansBossBattle = poFans->GetBossBattle();
        poFansBossBattle->OnDelBeattaction(dwNoticePlayerID);
        if(dwSize > m_pstCurBossBProp->byShowNum)//������㹻����poFans�����ע
        {
            PKT_BOSSB_POS_NTF stEnterNtf;
            UINT32 dwSyncIdx = poFansBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().dwSyncStartIdx;
            UINT32 dwEnterID = m_vecAllEnterPlayer[(dwSyncIdx + m_pstCurBossBProp->byShowNum - 1) % dwSize]; //
            if(dwEnterID != dwID)
            {
                poFansBossBattle->OnAddBeattaction(dwEnterID);
                //CPlayer* poEnterPlayer =CPlayerMgr::Instance()->FindPlayer(dwEnterID);
                //if(poEnterPlayer)
                //{
                //	GetBOSSB_PLAYER_DATA_CLI(poEnterPlayer, stEnterNtf.stPlayerInfo);
                //	//����Enter֪ͨ
                //	poFans->SendMsg((const CHAR*)(&stNtf), BOSSB_POS_NTF);
                //}
            }
        }
        itr++;
    }
    mapBeattentionID.clear();
}

//����뿪
UINT16 CBossBattleMgr::OnLeave(CPlayer* poPlayer, BOOL bDisconnect)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //���ڻʱ����ڣ�ֱ�ӷ��سɹ�
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        return ERR_LEAVE_BOSSB::ID_SUCCESS;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    if(!poPlayer->GetBuild(EBK_BOSSBATTLE))
    {
        return ERR_LEAVE_BOSSB::ID_BOSSB_UNLOCK;
    }

    //��ֵ�뿪ʱ��
    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_LEAVE_BOSSB::ID_BOSSB_UNLOCK;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
    stDT_BOSS_BATTLE_PLAYER_DATA.qwLastLeaveActivityTime = SDTimeSecs();

    //�������
    m_mapAllEnterPlayer.erase(dwPlayerID);
    vector<UINT32>::iterator itr = find(m_vecAllEnterPlayer.begin(), m_vecAllEnterPlayer.end(), dwPlayerID);
    if(itr != m_vecAllEnterPlayer.end())
    {
        m_vecAllEnterPlayer.erase(itr);
    }

    //ȥ����ע
    Delattention(poPlayer);

    if(!bDisconnect)
    {
        poPlayer->GetLocale().OnLeaveBossB();
    }

    return ERR_LEAVE_BOSSB::ID_SUCCESS;
}

//����ƶ�
UINT16 CBossBattleMgr::OnMove(CPlayer* poPlayer, UINT16 wPosX, UINT16 wPosY, UINT16& wOldPosX, UINT16& wOldPosY)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    if(!poPlayer->GetBuild(EBK_BOSSBATTLE))
    {
        return ERR_BOSSB_MOVE::ID_BOSSB_UNLOCK;
    }

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return ERR_BOSSB_MOVE::ID_BOSSB_UNSTART;
    }

    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_LEAVE_BOSSB::ID_BOSSB_UNLOCK;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
    wOldPosX = stDT_BOSS_BATTLE_PLAYER_DATA.wPosX;
    wOldPosY = stDT_BOSS_BATTLE_PLAYER_DATA.wPosY;

    //�ж��Ƿ��ѽ���bossս
    UINT32 dwPassSec = GetDayPassSecond(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime);
    if((dwPassSec < m_pstCurBossBProp->dwStartEnterTime) || (dwPassSec > m_pstCurBossBProp->dwEndTime))
    {
        return ERR_BOSSB_MOVE::ID_NOT_IN_ACTIVITY;
    }

    //�ڻδ��ʼ�������Խ��룬�ƶ����ܳ�����ʼ��
    if (dwPassSec < m_pstCurBossBProp->dwStartTime)
    {
        wPosX = 450;
    }

    if(m_mapAllEnterPlayer.find(dwPlayerID) == m_mapAllEnterPlayer.end())
    {
        return ERR_BOSSB_MOVE::ID_NOT_IN_ACTIVITY;
    }

    ////�Ƿ�׼��CD��
    //if((GetDayPassSecond() < m_pstCurBossBProp->dwStartTime))// < m_pstCurBossBProp->wReadyCD) && (wPosY > m_pstCurBossBProp->wMaxReadyPosY))
    //{
    //	return ERR_BOSSB_MOVE::ID_READY_CD;
    //}

    //�ж�λ���Ƿ�û�ı�
    if((wPosX == stDT_BOSS_BATTLE_PLAYER_DATA.wPosX) && (wPosY == stDT_BOSS_BATTLE_PLAYER_DATA.wPosY))
    {
        return ERR_BOSSB_MOVE::ID_SUCCESS;
    }

    ////�ж��Ƿ񸴻�CD��
    //if(0 != GetReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA))
    //{
    //	return ERR_BOSSB_MOVE::ID_RELIVE_CD;
    //}

    //�ж��ƶ��Ƿ����Ƶ��
    SDGetTickCount();
    UINT64& qwLastMoveTime = poBossBattle->GetLastMoveTime();
    if(SDTimeMilliSec() - qwLastMoveTime < m_pstCurBossBProp->wMoveMinCD)
    {
        return ERR_BOSSB_MOVE::ID_MOVE_FREQUENTLY;
    }

    //�ͻ����жϼ���
    ////�ж��ƶ�λ���Ƿ����
    //if(abs(stDT_BOSS_BATTLE_PLAYER_DATA.wPosX - wPosX) >= m_pstCurBossBProp->wMoveMaxLen)
    //{
    //	return ERR_BOSSB_MOVE::ID_MOVE_LEN_INVALID;
    //}

    //��ֵ
    stDT_BOSS_BATTLE_PLAYER_DATA.wPosX = wPosX;
    stDT_BOSS_BATTLE_PLAYER_DATA.wPosY = wPosY;
    qwLastMoveTime = SDTimeMilliSec();

    ////Move֪ͨ
    //UINT32 dwSize = m_vecAllEnterPlayer.size();
    //PKT_BOSSB_POS_NTF stNtf;
    //stNtf.bySyncType = BOSSB_POS_TYPE_MOVE;
    //GetBOSSB_PLAYER_DATA_CLI(poPlayer, stNtf.stPlayerInfo);
    //stNtf.dwPlayerNum = m_vecAllEnterPlayer.size();
    C3232Map& mapBeattentionID = poBossBattle->GetBeattentionIDMap();
    for(C3232MapItr itr = mapBeattentionID.begin(); itr != mapBeattentionID.end();)
    {
        UINT32 dwID = itr->first;
        CPlayer* poFans = CPlayerMgr::Instance()->FindPlayer(dwID);
        if((NULL == poFans) || (poFans == poPlayer) || (m_mapAllEnterPlayer.find(dwID) == m_mapAllEnterPlayer.end()))
        {
            poBossBattle->LeaveID(dwID);
            mapBeattentionID.erase(itr++);
            continue;
        }
        ////�������Move֪ͨ
        //poFans->SendMsg((const CHAR*)(&stNtf), BOSSB_POS_NTF);

        CBossBattle *poBossBattle = poFans->GetBossBattle();
        if(poBossBattle)
            poBossBattle->MoveID(dwPlayerID);

        itr++;
    }

    wOldPosX = stDT_BOSS_BATTLE_PLAYER_DATA.wPosX;
    wOldPosY = stDT_BOSS_BATTLE_PLAYER_DATA.wPosY;

    return 0;
}

//��ҹ���
UINT16 CBossBattleMgr::OnHurt(CPlayer* poPlayer, UINT32& dwCurHurtValue, DT_BOSSB_HURT_RATE& stMyHurtInfo, DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM],
                              DT_HURT_ENC_DATA& stHurtEncInfo, UINT16& wReliveCountDown, UINT16& wGoldReliveCountDown, UINT64& qwTotalBossHP, UINT64& qwCurBossHP)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    if(!poPlayer->GetBuild(EBK_BOSSBATTLE))
    {
        return ERR_BOSSB_HURT::ID_BOSSB_UNLOCK;
    }

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return ERR_BOSSB_HURT::ID_BOSSB_UNSTART;
    }

    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_BOSSB_HURT::ID_BOSSB_UNLOCK;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();

    //�ж��Ƿ��ѽ���bossս
    UINT32 dwPassSec = GetDayPassSecond(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime);
    if((dwPassSec < m_pstCurBossBProp->dwStartEnterTime) || (dwPassSec > m_pstCurBossBProp->dwEndTime))
    {
        return ERR_BOSSB_HURT::ID_NOT_IN_ACTIVITY;
    }
    if(m_mapAllEnterPlayer.find(dwPlayerID) == m_mapAllEnterPlayer.end())
    {
        return ERR_BOSSB_HURT::ID_NOT_IN_ACTIVITY;
    }

    //�Ƿ�׼��CD��
    //if(GetDayPassSecond() - m_pstCurBossBProp->dwStartTime < m_pstCurBossBProp->wReadyCD)
    if(GetDayPassSecond() < m_pstCurBossBProp->dwStartTime)
    {
        return ERR_BOSSB_HURT::ID_READY_CD;
    }

    //�ж��Ƿ񸴻�CD��,������·��ʱ��Ϊ1��
    if(0 != GetReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA, 1))
    {
        return ERR_BOSSB_HURT::ID_RELIVE_CD;
    }

    if(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime > stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: LastDeadTime:%llu, LastReliveTime:%llu, Now:%llu, between dead:%llu!, PlayerID=%lu"),
                     MSG_MARK, stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime, stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime, SDTimeSecs(), SDTimeSecs() - stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime, 
					 poPlayer->GetID());
    }
    else
    {
        SYS_CRITICAL(_SDT("[%s: %d]: LastDeadTime:%llu, LastReliveTime:%llu, Now:%llu, between relive:%llu!, PlayerID=%lu"),
                     MSG_MARK, stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime, stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime, SDTimeSecs(), stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime - stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime,
					 poPlayer->GetID());
    }

    stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime = SDTimeSecs();

    //�����˺�����¼
    dwCurHurtValue = CountHurtValue(poPlayer, stMyHurtInfo, astTopHurtInfo);
	
    GetHurtEncInfo(poPlayer->GetLevel(), stDT_BOSS_BATTLE_PLAYER_DATA, stHurtEncInfo, dwCurHurtValue);
    wReliveCountDown = GetReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA);
    wGoldReliveCountDown = GetGoldReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA);

    qwTotalBossHP = m_poBoss->GetDT_BATTLE_ATTRIBUTE().qwHP;
    qwCurBossHP = m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP;

    return ERR_BOSSB_HURT::ID_SUCCESS;
}


VOID CBossBattleMgr::GetShowPlayerInfo(CPlayer* poPlayer, UINT32 dwSyncStartIdx, DT_BOSSB_PLAYER_DATA_CLI_LST& stDT_BOSSB_PLAYER_DATA_CLI_LST)
{
    //AUTOCYCLE;

    UINT32 dwSize = m_vecAllEnterPlayer.size();
    if(dwSyncStartIdx >= m_vecAllEnterPlayer.size())
    {
        dwSyncStartIdx = 0;
    }

    UINT32 dwMyID = poPlayer->GetID();
    UINT8& byNum = stDT_BOSSB_PLAYER_DATA_CLI_LST.byNum;
    BOOL bRereturn = FALSE;
    for(UINT8 byIdx = dwSyncStartIdx; ((byIdx < dwSize) && (byNum < MAX_BOSSB_SHOW_PLAYER_NUM) && (byNum < m_pstCurBossBProp->byShowNum)); )
    {
        UINT32 dwPlayerID = m_vecAllEnterPlayer[byIdx];
        if(dwMyID != dwPlayerID)
        {
            CPlayer* poPlayerTmp = CPlayerMgr::Instance()->FindPlayer(dwPlayerID);
            if(poPlayerTmp)
            {
                GetBOSSB_PLAYER_DATA_CLI(poPlayerTmp, stDT_BOSSB_PLAYER_DATA_CLI_LST.astInfo[stDT_BOSSB_PLAYER_DATA_CLI_LST.byNum++]);
            }
        }

        byIdx++;
        if((byIdx >= dwSize) &&  (!bRereturn )) //��ĩβ����ͷ
        {
            byIdx = 0;
            bRereturn = TRUE;
        }
        if(bRereturn && byIdx >= dwSyncStartIdx) //�Ѿ�����ʼ��
        {
            break;
        }
    }

}

VOID CBossBattleMgr::GetBOSSB_PLAYER_DATA_CLI(CPlayer* poPlayer, DT_BOSSB_PLAYER_DATA_CLI& stDT_BOSSB_PLAYER_DATA_CLI)
{
    //AUTOCYCLE;

    stDT_BOSSB_PLAYER_DATA_CLI.dwPlayerID = poPlayer->GetID();
    SDStrcpy(stDT_BOSSB_PLAYER_DATA_CLI.aszDispName, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName);
    stDT_BOSSB_PLAYER_DATA_CLI.wHeroKindID = poPlayer->GetCoachHeroKindID();
    stDT_BOSSB_PLAYER_DATA_CLI.wLevel = poPlayer->GetLevel();
    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(poBossBattle)
    {
        stDT_BOSSB_PLAYER_DATA_CLI.wPosX = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().wPosX;
        stDT_BOSSB_PLAYER_DATA_CLI.wPosY = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().wPosY;
    }
}

UINT32 CBossBattleMgr::CountHurtValue(CPlayer* poPlayer, DT_BOSSB_HURT_RATE& stMyHurtInfo, DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM])
{
    //AUTOCYCLE;

    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return 0;
    }
    UINT32 dwHurtValue = 0;
    //UINT32 dwIncHurtValue = 0;
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();

    UINT32 dwPower = (UINT32)(UINT64(poPlayer->GetDT_PLAYER_BASE_DATA().dwPower) * (100 + stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate) / 100);
    dwHurtValue = CLuamgr::Instance()->GetBossBHurtValueByPower(dwPower);

    //stDT_BOSS_BATTLE_PLAYER_DATA.dwTotalHurtValue += (dwHurtValue + dwIncHurtValue);
    m_poBoss->AddHPChange(-(INT32)dwHurtValue, ET_NORMAL, EHPCR_NORMAL_SKILL, 0);
	USR_INFO(_SDT("[%s:%u] CurHurtValue = %lu, PlayerID = %u, CurBossHP = %llu"), MSG_MARK, dwHurtValue, poPlayer->GetID(), m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP);
    stDT_BOSS_BATTLE_PLAYER_DATA.dwTotalHurtValue += (dwHurtValue);

    if(0 != m_qwBossTotalHP)
    {
        stMyHurtInfo.dwHurtValue = stDT_BOSS_BATTLE_PLAYER_DATA.dwTotalHurtValue;
        stMyHurtInfo.dwHurtRate = (UINT32)((UINT64)(stMyHurtInfo.dwHurtValue) * 100 * 100 / m_qwBossTotalHP); //��ֱ�
    }
    else
    {
        stMyHurtInfo.dwHurtRate = 0;
    }
    UINT32 dwPlayerID = poPlayer->GetID();
    stMyHurtInfo.dwPlayerID = dwPlayerID;
    SDStrcpy(stMyHurtInfo.aszDispName, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName);

    SortTopHurt(stMyHurtInfo);

    memcpy(astTopHurtInfo, m_astTopHurtInfo, sizeof(m_astTopHurtInfo));

    C3232Map& mapBeattentionID = poBossBattle->GetBeattentionIDMap();
    for(C3232MapItr itr = mapBeattentionID.begin(); itr != mapBeattentionID.end(); )
    {
        UINT32 dwID = itr->first;
        CPlayer* poFans = CPlayerMgr::Instance()->FindPlayer(dwID);
        if((NULL == poFans) || (poFans == poPlayer) || (m_mapAllEnterPlayer.find(dwID) == m_mapAllEnterPlayer.end()))
        {
            poBossBattle->LeaveID(dwID);
            mapBeattentionID.erase(itr++);
            continue;
        }
        //poFans->GetBossBattle()->HurtID(dwPlayerID, dwCurTotalHurtValue);
        CBossBattle *poBossBattle = poFans->GetBossBattle();
        if(poBossBattle)
            poBossBattle->HurtID(dwPlayerID, dwHurtValue);

        itr++;
    }

    //�����������
    if(m_poBoss->IsDead())
    {
        ActivityOver(poPlayer);
    }

    poPlayer->EndBattle();

    //return dwCurTotalHurtValue;
    return dwHurtValue;
}


VOID CBossBattleMgr::SortTopHurt(DT_BOSSB_HURT_RATE& stMyHurtInfo)
{
    BOOL bChange = FALSE;
    vector<DT_BOSSB_HURT_RATE> vecTmp;
    vecTmp.reserve(MAX_BOSS_ENC_TOP_NUM + 1);
    for(UINT8 byIdx = 0; byIdx < MAX_BOSS_ENC_TOP_NUM ; byIdx++)
    {
        DT_BOSSB_HURT_RATE& stDT_BOSSB_HURT_RATE = m_astTopHurtInfo[byIdx];
        if((0 == stDT_BOSSB_HURT_RATE.dwHurtValue) && (!bChange))
        {
            vecTmp.push_back(stMyHurtInfo);
            bChange = TRUE;
        }
        if(((stMyHurtInfo.dwHurtValue > stDT_BOSSB_HURT_RATE.dwHurtValue) || ((stMyHurtInfo.dwHurtValue == stDT_BOSSB_HURT_RATE.dwHurtValue) && (stMyHurtInfo.dwPlayerID == stDT_BOSSB_HURT_RATE.dwPlayerID)))
                && (!bChange))
        {
            vecTmp.push_back(stMyHurtInfo);
            bChange = TRUE;
        }
        if((bChange) && (stDT_BOSSB_HURT_RATE.dwPlayerID == stMyHurtInfo.dwPlayerID))
        {
            continue;
        }
        vecTmp.push_back(stDT_BOSSB_HURT_RATE);
    }

    if(bChange)
    {
        memset(m_astTopHurtInfo, 0, sizeof(m_astTopHurtInfo));
        UINT8 bySize = vecTmp.size();
        for(UINT8 byIdx = 0; ((byIdx < MAX_BOSS_ENC_TOP_NUM) && ( byIdx < bySize)); byIdx++)
        {
            memcpy(&(m_astTopHurtInfo[byIdx]), &(vecTmp[byIdx]), sizeof(DT_BOSSB_HURT_RATE));
        }
    }
}

// ���ʼʱ�ѿ�ʼ֪ͨ���������Ƶ��
void CBossBattleMgr::AddChatOnActivityStart(UINT64 qwActivityStartTime, UINT64 qwNow)
{
    // ����Ѿ������������ʼʱ�䣬�򲻱�������Ƶ���������ʼ�Ĺ��棨��Ϊ��˵����������������
    if(qwActivityStartTime > 0 && qwNow > qwActivityStartTime)
    {
        return;
    }

    // ��ӻ���죺BOSSս�ѿ�ʼ�����λ��������ǰ�����붴��ѹ������
    string strChat = CMsgDefMgr::Instance()->GetErrMsg("BOSS_BATTLE_START");
    CChatMgr::Instance()->AddActivityChat(strChat, qwActivityStartTime);
}

//�����ʱ��bossսս�����������Ƶ��
void CBossBattleMgr::AddChatOnActivityOver(DT_BOSS_BATTLE_DATA& stReport)
{
    std::vector<string> vecFillMsg;

    // ������Ϣǰ׺�����λ�ɱ�������У�
    string strReportPrefix = CMsgDefMgr::Instance()->GetErrMsg("BOSS_BATTLE_REPORT");

    CHAR szBuf[64] = {0};

    // ͳ���˺���ߵ�ǰ������ҵĽ�����Ϣ��2014��1��2��ע������ֻ����ʾǰ3����ҵĽ������ӵ�4����ʼ��playeID������ǳ���Ȼ����Ϊ�գ���ͭǮ�;��罱����Ϊ0�������ˣ�
    for(BYTE i = 0; i < 3; ++i)
    {
        DT_BOSS_BATTLE_ENC_DATA &stEnc = stReport.astBossBTopEncInfo[i];
        if(0 == stEnc.dwPlayerID)
        {
            break;
        }

        vecFillMsg.clear();

        sprintf(szBuf, "%u", i + 1);
        vecFillMsg.push_back(szBuf);
        vecFillMsg.push_back(stEnc.aszDispName);
        sprintf(szBuf, "%u", stEnc.dwCoin);
        vecFillMsg.push_back(szBuf);
        sprintf(szBuf, "%u", stEnc.dwJingJie);
        vecFillMsg.push_back(szBuf);

        // ���ϣ���{xx}����{�������}��,����ͭǮ{M},�����{N}
        string strReport = strReportPrefix + CMsgDefMgr::Instance()->GetErrMsg("BOSS_BATTLE_RANK_ENCOURAGE", &vecFillMsg); // ֱ����+=

        // �����������Ϣ�ǣ����λ�ɱ�������У���x��[{�������}]������ͭǮ{x}�㣬����{y}��
        CChatMgr::Instance()->AddActivityChat(strReport);
    }
}

//�Boss����ɱʱ����boss��ɱ��Ϣ���������Ƶ��
void CBossBattleMgr::AddChatOnBossKilled(DT_BOSS_BATTLE_DATA& stData)
{
    CHAR szBuf[32] = {0};
    std::vector<string> vecFillMsg;

    vecFillMsg.push_back(stData.stBossBKillEncInfo.aszDispName);
    sprintf(szBuf, "%u", stData.stBossBKillEncInfo.dwCoin);
    vecFillMsg.push_back(szBuf);

    // ��ʾ������BOSS�������ѱ����{�������}��ɱ����ý���:ͭǮ{x}.
    string strActivityNoticeChat = CMsgDefMgr::Instance()->GetErrMsg("BOSS_BATTLE_BOSS_BE_KILLED", &vecFillMsg);
    CChatMgr::Instance()->AddActivityChat(strActivityNoticeChat);
}

VOID CBossBattleMgr::ActivityOver(CPlayer* poKiller)
{
    //AUTOCYCLE;

    //����
    SortHurtRank();

    //����������㽱��������֪ͨ,��¼ģ������
    UINT64 qwOverTime = SDTimeSecs();
    PKT_BOSSB_OVER_NTF2 stNtf;
    DT_BOSSB_OVER_INFO2& stBossOverInfo = stNtf.stBossOverInfo;
    //����ģ������
    DT_BOSS_BATTLE_DATA& stDT_BOSS_BATTLE_DATA = m_mapBassBattleModuleData[m_pstCurBossBProp->byActivityId];
    memset(&stDT_BOSS_BATTLE_DATA , 0 , sizeof(stDT_BOSS_BATTLE_DATA));
    stDT_BOSS_BATTLE_DATA.qwOverTime = qwOverTime;

    //top����
    for(UINT8 byIdx = 0; byIdx < MAX_BOSS_ENC_TOP_NUM; byIdx++)
    {
        DT_BOSS_BATTLE_ENC_DATA& stTopEnc1 = stDT_BOSS_BATTLE_DATA.astBossBTopEncInfo[byIdx];
        if(0 == m_astTopHurtInfo[byIdx].dwPlayerID)
        {
            continue;
        }
        stTopEnc1.dwPlayerID = m_astTopHurtInfo[byIdx].dwPlayerID;
        stTopEnc1.dwCoin =  CLuamgr::Instance()->GetBossBTopEncCoin(CPlayerBaseDataCacheMgr::Instance()->GetLevel(m_astTopHurtInfo[byIdx].dwPlayerID), byIdx + 1);
        stTopEnc1.dwJingJie =  CLuamgr::Instance()->GetBossBTopEncJingJie(CPlayerBaseDataCacheMgr::Instance()->GetLevel(m_astTopHurtInfo[byIdx].dwPlayerID), byIdx + 1);
        SDStrcpy(stTopEnc1.aszDispName, m_astTopHurtInfo[byIdx].aszDispName);
        memcpy(&stBossOverInfo.astTopEncInfo[byIdx], &stTopEnc1, sizeof(stTopEnc1));
    }
    //��ɱ����
    if(poKiller)
    {
		CBossBattle* poBossBattle = poKiller->GetBossBattle();
		if ( NULL != poBossBattle)
		{
			poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().qwLastKillBossTime = SGDP::SDTimeSecs();
		}
        DT_BOSS_BATTLE_ENC_DATA& stKillEnc1 = stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo;
        stKillEnc1.dwPlayerID = poKiller->GetID();
        stKillEnc1.dwCoin =  CLuamgr::Instance()->GetBossBKillEncCoin(m_wBossLevel);
        stKillEnc1.dwJingJie =  CLuamgr::Instance()->GetBossBKillEncJingJie(m_wBossLevel);
        SDStrcpy(stKillEnc1.aszDispName, poKiller->GetDT_PLAYER_BASE_DATA().aszDispName);
        memcpy(&stBossOverInfo.stKillEncInfo, &stKillEnc1, sizeof(stKillEnc1));

        stBossOverInfo.byBossDeadFlag = 1;
        if(GetDayPassSecond() - m_pstCurBossBProp->dwStartTime < m_pstCurBossBProp->wUpgradeCostMaxKillSecs)
        {
            //���BOSS�ﵽ��ߵȼ��������·�������ʾ��Ϣ
            if (m_pstCurBossBProp->wBossMaxLevel > m_wBossLevel)
            {
                stDT_BOSS_BATTLE_DATA.byNeedUpgrade = TRUE;
                stBossOverInfo.byNeedUpgrade = 1;
            }
        }

        // ��boss����ɱ��Ϣ���������Ƶ��
        AddChatOnBossKilled(stDT_BOSS_BATTLE_DATA);
    }
    //top�˺�
    memcpy(stBossOverInfo.astTopHurtInfo, m_astTopHurtInfo, sizeof(m_astTopHurtInfo));
    stBossOverInfo.qwTotalBossHP = m_poBoss->GetDT_BATTLE_ATTRIBUTE().qwHP;
    stBossOverInfo.qwCurBossHP = m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP;

    //��������������֪ͨ
    UINT32 dwSize = m_mapAllPlayer.size();
    for(C3232MapItr itr = m_mapAllPlayer.begin(); itr != m_mapAllPlayer.end(); itr++)
    {
        UINT32 dwID = itr->second;
        CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(dwID);
        if(NULL == poPlayer)//�Ӧ�ò��ᳬ��1��Сʱ�����治���ڴ�����ʱ��������
        {
            continue;
        }
        CBossBattle* poBossBattle = poPlayer->GetBossBattle();
        if(NULL == poBossBattle)
        {
            continue;
        }
        DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
        //�����˺�
        DT_BOSSB_HURT_RATE& stMyHurtInfo = stBossOverInfo.stMyHurtInfo;
        //if(0 != dwBossTotalHurt)
        if(0 != m_qwBossTotalHP)
        {
            stMyHurtInfo.dwHurtValue = stDT_BOSS_BATTLE_PLAYER_DATA.dwTotalHurtValue;
            stMyHurtInfo.dwHurtRate = (UINT32)((UINT64)(stMyHurtInfo.dwHurtValue) * 100 * 100 / m_qwBossTotalHP); //��ֱ�
            stMyHurtInfo.dwHurtRate = stMyHurtInfo.dwHurtRate > 10000 ? 10000 : stMyHurtInfo.dwHurtRate;
        }
        else
        {
            stMyHurtInfo.dwHurtRate = 0;
        }
        stMyHurtInfo.dwHurtRank = stDT_BOSS_BATTLE_PLAYER_DATA.dwHurtRank;
        stMyHurtInfo.dwPlayerID = poPlayer->GetID();
        SDStrcpy(stMyHurtInfo.aszDispName, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName);
        memcpy(&stDT_BOSS_BATTLE_PLAYER_DATA.stMyHurtInfo, &stMyHurtInfo, sizeof(stMyHurtInfo));

        //�˺�����
        DT_BOSS_BATTLE_ENC_DATA& stHurtEncInfo = stBossOverInfo.stHurtEncInfo;
        stHurtEncInfo.dwCoin = stDT_BOSS_BATTLE_PLAYER_DATA.dwEncCoin;
        stHurtEncInfo.dwJingJie = stDT_BOSS_BATTLE_PLAYER_DATA.dwEncJingJie;
        stHurtEncInfo.dwPlayerID = poPlayer->GetID();
        SDStrcpy(stMyHurtInfo.aszDispName, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName);
        memcpy(&stDT_BOSS_BATTLE_PLAYER_DATA.stHurtEncInfo, &stHurtEncInfo, sizeof(stHurtEncInfo));

        //Ӣ�۽���, >=1%
        DT_BOSS_BATTLE_ENC_DATA& stHeroEncInfo = stBossOverInfo.stHeroEncInfo;
        memset(&stHeroEncInfo, 0, sizeof(DT_BOSS_BATTLE_ENC_DATA));
        memset(&stDT_BOSS_BATTLE_PLAYER_DATA.stHeroEncInfo, 0, sizeof(DT_BOSS_BATTLE_ENC_DATA));
        if(stMyHurtInfo.dwHurtRate >= 100)
        {
			CBossBattle* poBossBattle = poPlayer->GetBossBattle();
			if ( NULL != poBossBattle)
			{
				poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().qwBossHurtTime = SGDP::SDTimeSecs();
			}
            stHeroEncInfo.dwCoin = CLuamgr::Instance()->GetBossBHeroHurtEncCoin();
            stHeroEncInfo.dwJingJie = CLuamgr::Instance()->GetBossBHeroHurtEncJingJie();
            stHeroEncInfo.dwPlayerID = poPlayer->GetID();
            SDStrcpy(stHeroEncInfo.aszDispName, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName);
            memcpy(&stDT_BOSS_BATTLE_PLAYER_DATA.stHeroEncInfo, &stHeroEncInfo, sizeof(DT_BOSS_BATTLE_ENC_DATA));
        }

        //������
        GiveEnc(poPlayer, stNtf.stBossOverInfo);

        const DT_PLAYER_BASE_DATA& stDT_PLAYER_BASE_DATA = poPlayer->GetDT_PLAYER_BASE_DATA();
        stNtf.qwCurCoin = stDT_PLAYER_BASE_DATA.qwCoin;
        stNtf.qwCurGold = stDT_PLAYER_BASE_DATA.qwGold;
        stNtf.qwCurStory = stDT_PLAYER_BASE_DATA.qwStory;
        stNtf.qwCurJingJie = stDT_PLAYER_BASE_DATA.qwJingJie;

        //��¼ս��
        DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA = {0};
        stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA.byActivityID = m_pstCurBossBProp->byActivityId;
        stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA.qwOverTime = qwOverTime;
        memcpy(&stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA.stMyHurtInfo, &stBossOverInfo.stMyHurtInfo, sizeof(DT_BOSSB_HURT_RATE));
        memcpy(&stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA.stHurtEncInfo, &stBossOverInfo.stHurtEncInfo, sizeof(DT_BOSS_BATTLE_ENC_DATA));
        memcpy(&stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA.stHeroEncInfo, &stBossOverInfo.stHeroEncInfo, sizeof(DT_BOSS_BATTLE_ENC_DATA));
        poBossBattle->AddBattleLog(&stDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA);
        stNtf.byUnreadBattleLogNum = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().byUnreadBattleLogNum;

        //֪ͨ
		if ( VER_PET <= poPlayer->GetCliVer())
		{
			poPlayer->SendMsg((const CHAR*)(&stNtf), BOSSB_OVER_NTF2);
		}
		else
		{
			static PKT_BOSSB_OVER_NTF stNtfOld;
			stNtfOld.byUnreadBattleLogNum = stNtf.byUnreadBattleLogNum;
			stNtfOld.qwCurCoin = stNtf.qwCurCoin;
			stNtfOld.qwCurGold = stNtf.qwCurGold;
			stNtfOld.qwCurJingJie = stNtf.qwCurJingJie;
			stNtfOld.qwCurStory =stNtf.qwCurStory;
			ConvertInfo2ToInfo(stNtf.stBossOverInfo, stNtfOld.stBossOverInfo);
			poPlayer->SendMsg((const CHAR*)(&stNtfOld), BOSSB_OVER_NTF);
		}
        

        //�˳�λ��

        poPlayer->GetLocale().OnLeaveBossB();
    }

    //��bossսս�����������Ƶ��
    AddChatOnActivityOver(stDT_BOSS_BATTLE_DATA);

    //������δ����bossս�����ѿ���bossս������������ҷ���֪ͨ
    const CSessionID2UserMap& mapUser = CUserMgr::Instance()->GetAllUserMap();
    //������˽���
    memset(&stBossOverInfo.stMyHurtInfo, 0, sizeof(stBossOverInfo.stMyHurtInfo));
    memset(&stBossOverInfo.stHurtEncInfo, 0, sizeof(stBossOverInfo.stHurtEncInfo));
    memset(&stBossOverInfo.stHeroEncInfo, 0, sizeof(stBossOverInfo.stHeroEncInfo));
    for(CSessionID2UserMapConstItr itr = mapUser.begin(); itr != mapUser.end(); itr++)
    {
        UINT32 dwID = itr->first;
        //��������bossս
        if(m_mapAllEnterPlayer.find(dwID) != m_mapAllEnterPlayer.end())
        {
            continue;
        }
        CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(dwID);
        if((NULL == poPlayer) || (!poPlayer->CkLogin())) //Ҫ���������
        {
            continue;
        }
        CBossBattle* poBossBattle = poPlayer->GetBossBattle();
        if(NULL == poBossBattle)
        {
            stNtf.byUnreadBattleLogNum = 0;
        }
        else
        {
            stNtf.byUnreadBattleLogNum = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().byUnreadBattleLogNum;
        }

        const DT_PLAYER_BASE_DATA& stDT_PLAYER_BASE_DATA = poPlayer->GetDT_PLAYER_BASE_DATA();
        stNtf.qwCurCoin = stDT_PLAYER_BASE_DATA.qwCoin;
        stNtf.qwCurGold = stDT_PLAYER_BASE_DATA.qwGold;
        stNtf.qwCurStory = stDT_PLAYER_BASE_DATA.qwStory;
        stNtf.qwCurJingJie = stDT_PLAYER_BASE_DATA.qwJingJie;
		if ( VER_PET <= poPlayer->GetCliVer())
		{
			//֪ͨ
			poPlayer->SendMsg((const CHAR*)(&stNtf), BOSSB_OVER_NTF2);
		}
		else
		{
			static PKT_BOSSB_OVER_NTF stNtfOld;
			stNtfOld.byUnreadBattleLogNum = stNtf.byUnreadBattleLogNum;
			stNtfOld.qwCurCoin = stNtf.qwCurCoin;
			stNtfOld.qwCurGold = stNtf.qwCurGold;
			stNtfOld.qwCurJingJie = stNtf.qwCurJingJie;
			stNtfOld.qwCurStory =stNtf.qwCurStory;
			ConvertInfo2ToInfo(stNtf.stBossOverInfo, stNtfOld.stBossOverInfo);
			poPlayer->SendMsg((const CHAR*)(&stNtfOld), BOSSB_OVER_NTF);
		}
    }

    //��¼ģ��
    OnSave();
    m_mapBossBBLData[stDT_BOSS_BATTLE_DATA.qwOverTime] = stDT_BOSS_BATTLE_DATA;

    //����
    m_bActivityOver = TRUE;
    m_pstCurBossBProp = NULL;
}

VOID CBossBattleMgr::GiveEnc(CPlayer* poPlayer, DT_BOSSB_OVER_INFO2& stNtf)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        return;
    }

    //�˺�������Ϣ
    poPlayer->AddCoin(stNtf.stHurtEncInfo.dwCoin, CRecordMgr::EACT_BOSSB_HURTENC);
    poPlayer->AddJingJie(stNtf.stHurtEncInfo.dwJingJie, CRecordMgr::EAJT_BOSSB_HURTENC);

    //Ӣ�۽�����Ϣ
    poPlayer->AddCoin(stNtf.stHeroEncInfo.dwCoin, CRecordMgr::EACT_BOSSB_HEROENC);
    poPlayer->AddJingJie(stNtf.stHeroEncInfo.dwJingJie, CRecordMgr::EAJT_BOSSB_HEROENC);

    //top������Ϣ
    UINT32 dwPlayerID = poPlayer->GetID();
    for(UINT8 byIdx = 0; byIdx < MAX_BOSS_ENC_TOP_NUM; byIdx++)
    {
        DT_BOSS_BATTLE_ENC_DATA& stTopEnc = stNtf.astTopEncInfo[byIdx];
        if(dwPlayerID == stTopEnc.dwPlayerID)
        {
            poPlayer->AddCoin(stTopEnc.dwCoin, CRecordMgr::EACT_BOSSB_TOPENC, byIdx + 1);
            poPlayer->AddJingJie(stTopEnc.dwJingJie, CRecordMgr::EAJT_BOSSB_TOPENC, byIdx + 1);
            break;
        }
    }

    //���1��������Ϣ
    DT_BOSS_BATTLE_ENC_DATA& stKillEnc = stNtf.stKillEncInfo;
    if(dwPlayerID == stKillEnc.dwPlayerID)
    {
        poPlayer->AddCoin(stKillEnc.dwCoin, CRecordMgr::EACT_BOSSB_KILLENC);
        poPlayer->AddJingJie(stKillEnc.dwJingJie, CRecordMgr::EAJT_BOSSB_KILLENC);
    }
}


UINT16 CBossBattleMgr::OnOpenInspireTab(CPlayer* poPlayer, DT_INSPIRE_TAB_DATA& stInspireTabInfo)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    if(!poPlayer->GetBuild(EBK_BOSSBATTLE))
    {
        return ERR_OPEN_INSPIRE_TAB::ID_BOSSB_UNLOCK;
    }

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return ERR_OPEN_INSPIRE_TAB::ID_BOSSB_UNSTART;
    }

    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_LEAVE_BOSSB::ID_BOSSB_UNLOCK;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
    //�ж��Ƿ��ѽ���bossս
    UINT32 dwPassSec = GetDayPassSecond(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime);
    if((dwPassSec < m_pstCurBossBProp->dwStartEnterTime) || (dwPassSec > m_pstCurBossBProp->dwEndTime))
    {
        return ERR_OPEN_INSPIRE_TAB::ID_NOT_IN_ACTIVITY;
    }

    GetDT_INSPIRE_TAB_DATA(stDT_BOSS_BATTLE_PLAYER_DATA, stInspireTabInfo);

    return ERR_OPEN_INSPIRE_TAB::ID_SUCCESS;
}

UINT16 CBossBattleMgr::OnInspirePower(CPlayer* poPlayer, UINT8 byGoldInspireFlag, DT_INSPIRE_TAB_DATA& stInspireTabInfo)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    if(!poPlayer->GetBuild(EBK_BOSSBATTLE))
    {
        return ERR_INSPIRE_POWER::ID_BOSSB_UNLOCK;
    }

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return ERR_INSPIRE_POWER::ID_BOSSB_UNSTART;
    }

    //
    if((byGoldInspireFlag) && (!CVipPropMgr::Instance()->CkOpenFunc(EVF_BOSSBGOLDINSPIREPOWER, poPlayer->GetDT_PLAYER_BASE_DATA().byVipLevel)))
    {
        return ERR_COMMON::ID_VIP_LEVEL_NOT_REACH;
    }

    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_LEAVE_BOSSB::ID_BOSSB_UNLOCK;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
    //�ж��Ƿ��ѽ���bossս
    UINT32 dwPassSec = GetDayPassSecond(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime);
    if((dwPassSec < m_pstCurBossBProp->dwStartEnterTime) || (dwPassSec > m_pstCurBossBProp->dwEndTime))
    {
        return ERR_INSPIRE_POWER::ID_NOT_IN_ACTIVITY;
    }

    if(stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate >= m_pstCurBossBProp->wCanIncPowerRate)
    {
        GetDT_INSPIRE_TAB_DATA(stDT_BOSS_BATTLE_PLAYER_DATA, stInspireTabInfo);
        return ERR_INSPIRE_POWER::ID_REACH_MAX;
    }

    const DT_PLAYER_BASE_DATA& stDT_PLAYER_BASE_DATA = poPlayer->GetDT_PLAYER_BASE_DATA();
    if(0 == byGoldInspireFlag)
    {
        if(stDT_PLAYER_BASE_DATA.qwStory < m_pstCurBossBProp->wIncCostStory)
        {
            return ERR_INSPIRE_POWER::ID_STORY_NOT_ENOUGH;
        }
        poPlayer->DecStory(m_pstCurBossBProp->wIncCostStory, CRecordMgr::EDST_BOSSB_INSPIREPOWER);
    }
    else
    {
        if(stDT_PLAYER_BASE_DATA.qwGold < m_pstCurBossBProp->wIncCostGold)
        {
            return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
        }
        poPlayer->DecGold(m_pstCurBossBProp->wIncCostGold, CRecordMgr::EDGT_BOSSBINSPIRE);
    }
    stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate += CLuamgr::Instance()->GetInspireRate(byGoldInspireFlag, stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate);
    if(stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate > m_pstCurBossBProp->wCanIncPowerRate)
    {
        stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate = m_pstCurBossBProp->wCanIncPowerRate;
    }

    GetDT_INSPIRE_TAB_DATA(stDT_BOSS_BATTLE_PLAYER_DATA, stInspireTabInfo);

    return ERR_INSPIRE_POWER::ID_SUCCESS;
}

UINT16 CBossBattleMgr::OnBossBRelive(CPlayer* poPlayer)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    //�ж�����Ƿ񿪷�bossս
    UINT32 dwPlayerID = poPlayer->GetID();
    if(!poPlayer->GetBuild(EBK_BOSSBATTLE))
    {
        return ERR_BOSSB_RELIVE::ID_BOSSB_UNLOCK;
    }

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return ERR_BOSSB_RELIVE::ID_BOSSB_UNSTART;
    }

    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_LEAVE_BOSSB::ID_BOSSB_UNLOCK;
    }
    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();

    //�ж��Ƿ��ѽ���bossս
    UINT32 dwPassSec = GetDayPassSecond(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastEnterActivityTime);
    if((dwPassSec < m_pstCurBossBProp->dwStartEnterTime) || (dwPassSec > m_pstCurBossBProp->dwEndTime))
    {
        return ERR_BOSSB_RELIVE::ID_NOT_IN_ACTIVITY;
    }

    //�ж��Ƿ񸴻�CD��
    if(0 != GetReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA))
    {
        if(0 != GetGoldReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA))
        {
            return ERR_BOSSB_RELIVE::ID_GOLD_RELIVE_CD;
        }
        if(poPlayer->GetDT_PLAYER_BASE_DATA().qwGold < m_pstCurBossBProp->wReliveGold)
        {
            return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
        }
        stDT_BOSS_BATTLE_PLAYER_DATA.byLastReliveType = 1;
        stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime = SDTimeSecs();
        poPlayer->DecGold(m_pstCurBossBProp->wReliveGold, CRecordMgr::EDGT_BOSSBRELIVE);
    }
    else //����CD�У�ֱ�ӷ��سɹ�
    {
        return  ERR_BOSSB_RELIVE::ID_SUCCESS;
    }

    return  ERR_BOSSB_RELIVE::ID_SUCCESS;
}
BOOL CBossBattleMgr::IsCloseArea(UINT16 wZoneID)
{
	if ( m_setCloseArea.find(wZoneID) == m_setCloseArea.end())
	{
		return FALSE;
	}
	return TRUE;
}

UINT16 CBossBattleMgr::OnGetLastBossBInfo(CPlayer* poPlayer, DT_BOSSB_OVER_INFO2& stBossOverInfo)
{
    //AUTOCYCLE;

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    UINT32 dwPlayerID = poPlayer->GetID();
    CBossBattle* poBossBattle = poPlayer->GetBossBattle();
    if(NULL == poBossBattle)
    {
        return ERR_GET_LAST_BOSSB_INFO::ID_BOSSB_UNLOCK;
    }
    //�δ����
    if((m_pstCurBossBProp) || (!m_bActivityOver))
    {
        return ERR_GET_LAST_BOSSB_INFO::ID_BOSSB_UNOVER;
    }

    DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
    memcpy(&stBossOverInfo.stMyHurtInfo, &stDT_BOSS_BATTLE_PLAYER_DATA.stMyHurtInfo, sizeof(DT_BOSSB_HURT_RATE));

    DT_BOSS_BATTLE_DATA& stDT_BOSS_BATTLE_DATA = m_mapBassBattleModuleData[m_byLastActivityID];
    memcpy(&stBossOverInfo.astTopEncInfo, &stDT_BOSS_BATTLE_DATA.astBossBTopEncInfo, sizeof(stBossOverInfo.astTopEncInfo));
    memcpy(&stBossOverInfo.astTopHurtInfo, &stDT_BOSS_BATTLE_DATA.astTopHurtInfo, sizeof(stBossOverInfo.astTopHurtInfo));
    DT_BOSS_BATTLE_ENC_DATA& stKillEnc = stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo;
    //if(dwPlayerID == stKillEnc.dwPlayerID)
    {
        memcpy(&stBossOverInfo.stKillEncInfo, &stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo, sizeof(stBossOverInfo.stKillEncInfo));
    }
    memcpy(&stBossOverInfo.stHurtEncInfo, &stDT_BOSS_BATTLE_PLAYER_DATA.stHeroEncInfo, sizeof(DT_BOSS_BATTLE_ENC_DATA));
    stBossOverInfo.stHurtEncInfo.dwCoin = stDT_BOSS_BATTLE_PLAYER_DATA.dwEncCoin;
    stBossOverInfo.stHurtEncInfo.dwJingJie = stDT_BOSS_BATTLE_PLAYER_DATA.dwEncJingJie;
    memcpy(&stBossOverInfo.stHeroEncInfo, &stDT_BOSS_BATTLE_PLAYER_DATA.stHeroEncInfo, sizeof(DT_BOSS_BATTLE_ENC_DATA));

    stBossOverInfo.qwTotalBossHP = stDT_BOSS_BATTLE_DATA.qwTotalHP;
    stBossOverInfo.qwCurBossHP = stDT_BOSS_BATTLE_DATA.qwCurHP;
    stBossOverInfo.byBossDeadFlag = stDT_BOSS_BATTLE_DATA.qwCurHP == 0 ? 1 : 0;
    stBossOverInfo.byNeedUpgrade = stDT_BOSS_BATTLE_DATA.byNeedUpgrade;

    //�����쳣
    if(0 == stBossOverInfo.stMyHurtInfo.dwPlayerID || 0 == stBossOverInfo.stMyHurtInfo.dwHurtRank )
    {
        SYS_CRITICAL(_SDT("[%s: %d]: OnGetLastBossBInfo data 0, playerid:%d!"), MSG_MARK, dwPlayerID);
    }
    return ERR_GET_LAST_BOSSB_INFO::ID_SUCCESS;
}

VOID CBossBattleMgr::GetDT_INSPIRE_TAB_DATA(DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, DT_INSPIRE_TAB_DATA& stInspireTabInfo)
{
    //AUTOCYCLE;

    stInspireTabInfo.wHaveIncPowerRate = stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate;
    stInspireTabInfo.wIncCostStory = m_pstCurBossBProp->wIncCostStory;
    stInspireTabInfo.wIncCostGold = m_pstCurBossBProp->wIncCostGold;
    stInspireTabInfo.wCanIncPowerRate = m_pstCurBossBProp->wCanIncPowerRate;
    stInspireTabInfo.wStoryIncRate = m_wIncRateByStory;
    stInspireTabInfo.wGoldIncRate = m_wIncRateByGold;
}

VOID CBossBattleMgr::GetDT_BOSSB_MY_DATA_CLI(CPlayer* poPlayer, DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, DT_BOSSB_MY_DATA_CLI& stMyBossBInfo)
{
    //AUTOCYCLE;

    if(NULL == m_pstCurBossBProp)
    {
        return ;
    }
    const DT_PLAYER_BASE_DATA& stDT_PLAYER_BASE_DATA = poPlayer->GetDT_PLAYER_BASE_DATA();
    stMyBossBInfo.qwCurCoin = stDT_PLAYER_BASE_DATA.qwCoin;
    stMyBossBInfo.qwCurGold = stDT_PLAYER_BASE_DATA.qwGold;
    stMyBossBInfo.qwCurJingJie = stDT_PLAYER_BASE_DATA.qwJingJie;
    stMyBossBInfo.qwCurStory = stDT_PLAYER_BASE_DATA.qwStory;
    stMyBossBInfo.wPosX = stDT_BOSS_BATTLE_PLAYER_DATA.wPosX;
    stMyBossBInfo.wPosY = stDT_BOSS_BATTLE_PLAYER_DATA.wPosY;
    stMyBossBInfo.wIncPowerRate = stDT_BOSS_BATTLE_PLAYER_DATA.wIncPowerRate;

    stMyBossBInfo.wReliveCountDown = GetReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA);
    stMyBossBInfo.wGoldReliveCountDown = GetGoldReliveCountDown(stDT_BOSS_BATTLE_PLAYER_DATA);
    stMyBossBInfo.dwHurtValue = stDT_BOSS_BATTLE_PLAYER_DATA.dwTotalHurtValue;

    if(0 != m_qwBossTotalHP)
    {
        stMyBossBInfo.dwHurtRate = (UINT32)((UINT64)(stDT_BOSS_BATTLE_PLAYER_DATA.dwTotalHurtValue) * 100  * 100 / m_qwBossTotalHP);
    }
    else
    {
        stMyBossBInfo.dwHurtRate = 0;
    }
}

UINT16 CBossBattleMgr::GetReliveCountDown(DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, UINT8 byCalculateWalk)
{
    //AUTOCYCLE;
    if(NULL == m_pstCurBossBProp)
    {
        return 0;
    }

    //����������������ʱ������ڸ���ʱ��
    if(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime >= stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime)
    {
        UINT64 qwPassTime =  SDTimeSecs() - stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime ;
        if( qwPassTime < (m_pstCurBossBProp->wReliveCD + byCalculateWalk))
        {
            return m_pstCurBossBProp->wReliveCD - (UINT16)qwPassTime + byCalculateWalk;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

UINT16 CBossBattleMgr::GetGoldReliveCountDown(DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA)
{
    //AUTOCYCLE;

    if(NULL == m_pstCurBossBProp)
    {
        return 0;
    }
    if(stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime > stDT_BOSS_BATTLE_PLAYER_DATA.qwLastReliveTime)
    {
        UINT64 qwPassTime =  SDTimeSecs() - stDT_BOSS_BATTLE_PLAYER_DATA.qwLastDeadTime ;
        if( qwPassTime < m_pstCurBossBProp->wGoldReliveCD)
        {
            return m_pstCurBossBProp->wGoldReliveCD - (UINT16)qwPassTime;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 0;
}

VOID CBossBattleMgr::GetDT_BOSSB_DATA_CLI(DT_BOSSB_DATA_CLI2& stBossBInfo)
{
    //AUTOCYCLE;

    if(NULL == m_pstCurBossBProp)
    {
        return;
    }

    stBossBInfo.wBossID = m_pstCurBossBProp->wBossMonsterID;
    stBossBInfo.wBossLevel = m_wBossLevel;
    stBossBInfo.qwTotalBossHP = m_poBoss->GetDT_BATTLE_ATTRIBUTE().qwHP;
    stBossBInfo.qwCurBossHP = m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP;
    stBossBInfo.qwHPPerGrid = m_pstCurBossBProp->wHPPerGrid;
    stBossBInfo.dwPlayerNum = m_vecAllEnterPlayer.size();
    UINT32 dwDayPassTime = GetDayPassSecond();
    if(dwDayPassTime > m_pstCurBossBProp->dwStartTime)
    {
        stBossBInfo.wStopCountDown = m_pstCurBossBProp->dwEndTime > dwDayPassTime ? m_pstCurBossBProp->dwEndTime - dwDayPassTime : 0;
    }
    else
    {
        stBossBInfo.wStopCountDown = m_pstCurBossBProp->wKeepTime;
    }
    //stBossBInfo.wReadyCountDown  = m_pstCurBossBProp->dwReadyOverTime > dwDayPassTime ? m_pstCurBossBProp->dwReadyOverTime - dwDayPassTime : 0;
    stBossBInfo.wReadyCountDown  = m_pstCurBossBProp->dwStartTime > dwDayPassTime ? m_pstCurBossBProp->dwStartTime - dwDayPassTime : 0;
    stBossBInfo.wReliveGold = m_pstCurBossBProp->wReliveGold;
}


BOOL MyCmp (CBossBattle* poA, CBossBattle* poB)
{
    return poA->GetDT_BOSS_BATTLE_PLAYER_DATA().dwTotalHurtValue < poB->GetDT_BOSS_BATTLE_PLAYER_DATA().dwTotalHurtValue;
};


VOID CBossBattleMgr::SortHurtRank()
{
    //AUTOCYCLE;

    vector<CBossBattle*> vecAllEnterPlayerBossB;
    for(C3232MapItr itr = m_mapAllPlayer.begin(); itr != m_mapAllPlayer.end(); itr++)
    {
        CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(itr->second);
        if(NULL == poPlayer)
        {
            continue;
        }
        CBossBattle* poBossBattle = poPlayer->GetBossBattle();
        if((NULL == poBossBattle) || (0 == poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA().dwTotalHurtValue)) //�˺�0���μ�����
        {
            continue;
        }
        vecAllEnterPlayerBossB.push_back(poBossBattle);
    }

    sort(vecAllEnterPlayerBossB.begin(), vecAllEnterPlayerBossB.end(), MyCmp);
    UINT32 dwSize = vecAllEnterPlayerBossB.size();
    for(UINT32 dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        vecAllEnterPlayerBossB[dwIdx]->GetDT_BOSS_BATTLE_PLAYER_DATA().dwHurtRank = dwSize - dwIdx;
    }

}

VOID CBossBattleMgr::GetBattleLog(UINT64 qwOverTime, UINT16& wBossID, DT_BOSS_BATTLE_ENC_DATA astBossBTopEncInfo[MAX_BOSS_ENC_TOP_NUM], DT_BOSS_BATTLE_ENC_DATA& stBossBKillEncInfo)
{
    //AUTOCYCLE;

    memset(astBossBTopEncInfo, 0, sizeof(DT_BOSS_BATTLE_ENC_DATA) * MAX_BOSS_ENC_TOP_NUM);
    map<UINT64, DT_BOSS_BATTLE_DATA>::iterator itr = m_mapBossBBLData.find(qwOverTime);
    if(itr == m_mapBossBBLData.end())
    {
        return;
    }

    DT_BOSS_BATTLE_DATA& stDT_BOSS_BATTLE_DATA = itr->second;
    wBossID = stDT_BOSS_BATTLE_DATA.wBossID;
    memcpy(astBossBTopEncInfo, stDT_BOSS_BATTLE_DATA.astBossBTopEncInfo, sizeof(stDT_BOSS_BATTLE_DATA.astBossBTopEncInfo));
    memcpy(&stBossBKillEncInfo, &stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo, sizeof(stDT_BOSS_BATTLE_DATA.stBossBKillEncInfo));
}

BOOL CBossBattleMgr::OnSave()
{
    //AUTOCYCLE;

    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return FALSE;
    }
    DT_BOSS_BATTLE_DATA& stDT_BOSS_BATTLE_DATA = m_mapBassBattleModuleData[m_pstCurBossBProp->byActivityId];
    stDT_BOSS_BATTLE_DATA.byActivityID = m_pstCurBossBProp->byActivityId;
    stDT_BOSS_BATTLE_DATA.wLastLevel = m_wBossLevel;
    stDT_BOSS_BATTLE_DATA.qwTotalHP = m_qwBossTotalHP;
    stDT_BOSS_BATTLE_DATA.qwCurHP = m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP;
    stDT_BOSS_BATTLE_DATA.qwSaveTime = SDTimeSecs();
    memcpy(stDT_BOSS_BATTLE_DATA.astTopHurtInfo, m_astTopHurtInfo, sizeof(m_astTopHurtInfo));
    CDBPktBuilder::Instance()->SaveBossBDataReq(&stDT_BOSS_BATTLE_DATA);

    return TRUE;
}

BOOL CBossBattleMgr::Run()
{
    //��Ƿ���
    if((NULL == m_pstCurBossBProp) || (m_bActivityOver))
    {
        //�δ��ʼ
        return TRUE;
    }

    if(m_itrCur == m_mapAllEnterPlayer.end())
    {
        m_itrCur = m_mapAllEnterPlayer.begin();
    }
    for(UINT16 wNum = 0 ; ((m_itrCur != m_mapAllEnterPlayer.end()) && (wNum < m_pstCurBossBProp->wDealNum)); m_itrCur++)
    {
        CPlayer* poPlayer = CPlayerMgr::Instance()->FindPlayer(m_itrCur->first);
        if(NULL == poPlayer)
        {
            continue;
        }
        CBossBattle *poBossBattle = poPlayer->GetBossBattle();
        if(NULL == poBossBattle)
        {
            continue;
        }

        if(SDTimeMilliSec() - poBossBattle->GetLastDealTime() < m_pstCurBossBProp->wDealInterval)
        {
            continue;
        }
        SyncInfo(poPlayer);

        poBossBattle->GetLastDealTime() = SDTimeMilliSec();
    }

    return TRUE;
}
VOID CBossBattleMgr::ConvertInfo2ToInfo(const DT_BOSSB_OVER_INFO2& stBossInfo2, DT_BOSSB_OVER_INFO& stBossOverInfo)
{
	stBossOverInfo.stMyHurtInfo = stBossInfo2.stMyHurtInfo;
	memcpy( stBossOverInfo.astTopEncInfo, stBossInfo2.astTopEncInfo, sizeof(stBossOverInfo.astTopEncInfo));
	memcpy( stBossOverInfo.astTopHurtInfo, stBossInfo2.astTopHurtInfo, sizeof(stBossOverInfo.astTopHurtInfo));
	stBossOverInfo.byBossDeadFlag = stBossInfo2.byBossDeadFlag;
	stBossOverInfo.byNeedUpgrade = stBossInfo2.byNeedUpgrade;
	stBossOverInfo.dwCurBossHP = (UINT32)stBossInfo2.qwCurBossHP;
	stBossOverInfo.dwTotalBossHP = (UINT32)stBossInfo2.qwTotalBossHP;
	stBossOverInfo.stHeroEncInfo = stBossInfo2.stHeroEncInfo;
	stBossOverInfo.stHurtEncInfo = stBossInfo2.stHurtEncInfo;
	stBossOverInfo.stKillEncInfo = stBossInfo2.stKillEncInfo;
	stBossOverInfo.stMyHurtInfo = stBossInfo2.stMyHurtInfo;
}

VOID CBossBattleMgr::SyncInfo(CPlayer* poPlayer)
{
    CBossBattle* poBossBattle = poPlayer->GetBossBattle();

    PKT_BOSSB_INFO_SYNC_NTF2 stNtf;
    stNtf.dwPlayerNum = m_vecAllEnterPlayer.size();
    stNtf.qwTotalBossHP = m_poBoss->GetDT_BATTLE_ATTRIBUTE().qwHP;
    stNtf.qwCurBossHP = m_poBoss->GetCurDT_BATTLE_ATTRIBUTE().qwHP;
    memcpy(stNtf.astTopHurtInfo, m_astTopHurtInfo, sizeof(m_astTopHurtInfo));

    C3232Map& mapLeave = poBossBattle->GetLeaveID();
    for(C3232MapItr itr = mapLeave.begin(); ((itr != mapLeave.end()) && (stNtf.byLeaveNum < MAX_BOSSB_SHOW_PLAYER_NUM)); itr++)
    {
        stNtf.adwLeaveInfo[stNtf.byLeaveNum++] = itr->first;
    }
    C3232Map& mapEnter = poBossBattle->GetEnterID();
    for(C3232MapItr itr = mapEnter.begin(); ((itr != mapEnter.end()) && (stNtf.byEnterNum < MAX_BOSSB_SHOW_PLAYER_NUM)); itr++)
    {
        CPlayer* poEnter = CPlayerMgr::Instance()->FindPlayer(itr->first);
        if(NULL == poEnter)
        {
            continue;
        }
        GetBOSSB_PLAYER_DATA_CLI(poEnter, stNtf.astEnterInfo[stNtf.byEnterNum++]);
    }
    C3232Map& mapMove = poBossBattle->GetMoveID();
    for(C3232MapItr itr = mapMove.begin(); ((itr != mapMove.end()) && (stNtf.byMoveNum < MAX_BOSSB_SHOW_PLAYER_NUM)); itr++)
    {
        CPlayer* poMove = CPlayerMgr::Instance()->FindPlayer(itr->first);
        if(NULL == poMove)
        {
            continue;
        }

        CBossBattle *poBossBattle = poMove->GetBossBattle();
        if(NULL == poBossBattle)
        {
            continue;
        }

        DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA = poBossBattle->GetDT_BOSS_BATTLE_PLAYER_DATA();
        DT_BOSSB_POS& stDT_BOSSB_POS = stNtf.astMoveInfo[stNtf.byMoveNum++];
        stDT_BOSSB_POS.dwPlayerID = itr->first;
        stDT_BOSSB_POS.wPosX = stDT_BOSS_BATTLE_PLAYER_DATA.wPosX;
        stDT_BOSSB_POS.wPosY = stDT_BOSS_BATTLE_PLAYER_DATA.wPosY;
    }
    C3232Map& mapHurt = poBossBattle->GetHurtID();
    for(C3232MapItr itr = mapHurt.begin(); ((itr != mapHurt.end()) && (stNtf.byHurtNum < MAX_BOSSB_SHOW_PLAYER_NUM)); itr++)
    {
        stNtf.astHurtInfo[stNtf.byHurtNum].dwPlayerID = itr->first;
        stNtf.astHurtInfo[stNtf.byHurtNum].dwHurtValue = itr->second;
        stNtf.byHurtNum++;
    }
	if ( VER_PET <= poPlayer->GetCliVer())
	{
		poPlayer->SendMsg((const CHAR*)(&stNtf), BOSSB_INFO_SYNC_NTF2);
	}
	else
	{
		static PKT_BOSSB_INFO_SYNC_NTF stOldNtf;
		memcpy(stOldNtf.adwLeaveInfo, stNtf.adwLeaveInfo, sizeof(stOldNtf.adwLeaveInfo));
		memcpy(stOldNtf.astEnterInfo, stNtf.astEnterInfo, sizeof(stOldNtf.astEnterInfo));
		memcpy(stOldNtf.astHurtInfo, stNtf.astHurtInfo, sizeof(stOldNtf.astHurtInfo));
		memcpy(stOldNtf.astMoveInfo, stNtf.astMoveInfo, sizeof(stOldNtf.astMoveInfo));
		memcpy(stOldNtf.astTopHurtInfo, stNtf.astTopHurtInfo, sizeof(stOldNtf.astTopHurtInfo));
		stOldNtf.byEnterNum = stNtf.byEnterNum;
		stOldNtf.byHurtNum = stNtf.byHurtNum;
		stOldNtf.byLeaveNum = stNtf.byLeaveNum;
		stOldNtf.byMoveNum = stNtf.byMoveNum;
		stOldNtf.dwCurBossHP = (UINT32)stNtf.qwCurBossHP;
		stOldNtf.dwPlayerNum = stNtf.dwPlayerNum;
		stOldNtf.dwTotalBossHP = (UINT32)stNtf.qwTotalBossHP;
		poPlayer->SendMsg((const CHAR*)(&stOldNtf), BOSSB_INFO_SYNC_NTF);
	}
    

    poBossBattle->EndSync();
}


