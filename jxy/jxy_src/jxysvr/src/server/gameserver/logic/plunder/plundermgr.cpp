
#include "plundermgr.h"
#include "plunderbattlelogmgr.h"
#include "plundercapturemgr.h"
#include "plunder.h"
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <protocol/server/protocommondata.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <logic/player/player.h>
#include <common/client/errdef.h>
#include <logic/player/playermgr.h>
#include <logic/event/timereventmgr.h>
#include <logic/battle/battlemgr.h>
#include <logic/player/playersavemgr.h>
#include <logic/record/recordmgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/item/goods/goodspropmgr.h>
#include <logic/hero/hero.h>
#include <protogsdb.h>
#include <logic/player/playergetdatamgr.h>
#include "plunderbasepropmgr.h"
#include "plundergridpropmgr.h"
#include <utility.h>
#include <sdloggerimpl.h>


using namespace SGDP;



IMPLEMENT_SINGLETON(CPlunderMgr)

CPlunderMgr::CPlunderMgr()
{
    memset(&m_astPlunderRobot, 0, sizeof(m_astPlunderRobot));
    m_dwPlunderItemPrice = 0;
    m_wPlunderOpenLevel = 0;
    m_bRobotInit = FALSE;
}

CPlunderMgr::~CPlunderMgr()
{
    CPlunderBasePropMgr::DestroyInstance();
    CPlunderGridPropMgr::DestroyInstance();
    CPlunderBattleLogMgr::DestroyInstance();
    CPlunderCaptureMgr::DestroyInstance();
}


BOOL CPlunderMgr::Init()
{
    //��ȡ�����ļ�

    // ��ʼ��CPlunderBasePropMgr������
    if(FALSE == CPlunderBasePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderBasePropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlunderBasePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderBasePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CPlunderGridPropMgr������
    if(FALSE == CPlunderGridPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderGridPropMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlunderGridPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderGridPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CPlunderCaptureMgr������
    if(FALSE == CPlunderCaptureMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderCaptureMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlunderCaptureMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderCaptureMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CPlunderBattleLogMgr������
    if(FALSE == CPlunderBattleLogMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderBattleLogMgr::CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CPlunderBattleLogMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderBattleLogMgr Init failed!"), MSG_MARK);
        return FALSE;
    }


    //��ʼ���Ӷ������
    if(!InitRobot())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitRobot failed!"), MSG_MARK);
        return FALSE;
    }

    SGoodsProp* pstGoodsProp = CGoodsPropMgr::Instance()->GetPropByPrimaryKey(CPlunderBasePropMgr::Instance()->GetPlunderLowerLevelItemID());
    if(pstGoodsProp)
    {
        m_dwPlunderItemPrice = pstGoodsProp->dwBuyGold;
        m_wPlunderItemID = pstGoodsProp->wKindID;
    }

    m_dwCaptureWorkSecond = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp().dwCaptureWorkSecond;
    m_wPlunderOpenLevel = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp().wPlunderOpenLevel;

    return TRUE;

}



BOOL CPlunderMgr::InitRobot()
{
    if( CPlayerBaseDataCacheMgr::Instance()->GetPlunderRobot().size() == 0 )
    {
        //�����Ű�Ļ����˲����ڣ���ô���³�ʼ��һ�����ݣ���Ϊ�����������һ���������ݿ���û�л����˵ģ�
        //֮ǰ�����������ڵ�һ��ʱ�����˻����������ݿ��У�������Ҫ�ڴ����³�ʼ��
        //CPlayerBaseDataCacheMgr::Instance()->InitDataFromDB();
    }
    const CPlayerID2PlayerBaseDataMap& mapRobot = CPlayerBaseDataCacheMgr::Instance()->GetPlunderRobot();
    UINT8 byNum = 0;
    for(CPlayerID2PlayerBaseDataMapConstItr itr = mapRobot.begin(); ((itr != mapRobot.end()) & (byNum < MAX_ROBOT_NUM)); itr++)
    {
        SPlayerBaseData* pstPlayerBaseData = itr->second;
        if(pstPlayerBaseData)
        {
            m_astPlunderRobot[byNum].dwPlayerID = pstPlayerBaseData->dwID;
            SDStrcpy(m_astPlunderRobot[byNum].aszDispName, pstPlayerBaseData->aszDispName);
            m_astPlunderRobot[byNum].byRobotFunc = pstPlayerBaseData->byRobotFunc;
            m_astPlunderRobot[byNum].wMainHeroKindID = pstPlayerBaseData->wMainHeroKindID;
            m_astPlunderRobot[byNum].wLevel = pstPlayerBaseData->wLevel;
            m_astPlunderRobot[byNum].dwPower = pstPlayerBaseData->dwPower;
            byNum++;

            if( !m_bRobotInit )
            {
                m_bRobotInit = TRUE;
            }

        }
    }

    return TRUE;
}

VOID CPlunderMgr::UnInit()
{
    CPlunderBasePropMgr::Instance()->UnInit();
    CPlunderGridPropMgr::Instance()->UnInit();
    CPlunderCaptureMgr::Instance()->UnInit();
    CPlunderBattleLogMgr::Instance()->UnInit();

}

//�Ӷ�ص�
BOOL CPlunderMgr::OnPlunder(CPlayer* poMyself, CPlayer* poEney, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, BOOL bChallengeSuccess, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage)
{
    if((NULL == poMyself) || (NULL == poEney) || (NULL == poCapture))
    {
        return FALSE;
    }

    CPlunder* poMyselfPlunder = poMyself->GetPlunder();
    if(NULL == poMyselfPlunder)
    {
        return FALSE;
    }

    //�Ӷ�Ƹ�(ͭ��/����)
    PlunderEncourage(poMyself, poEney, stReqRaram.byResistFlag, bChallengeSuccess, stPlunderEncourage.dwCoin, stPlunderEncourage.dwScience);

    //��¼ս��
    //AddPlunderBattleLog(poMyself, poEney, poCapture, byResistFlag, bChallengeSuccess, stPlunderEncourage.dwCoin, stPlunderEncourage.dwScience);

    //��²��Ϣ�仯
    CaptureChange(poMyself, poEney, poCapture, stReqRaram.byResistFlag, stReqRaram.byCaptureGridIdx, bChallengeSuccess);

    //�Ӷ���ɻص�(�۳�ʹ�õ���/Ԫ��)
    poMyself->GetPlunder()->OnPlunderComplete(bChallengeSuccess, stReqRaram);

    //��ӳ����Ϣ.�����˲�����ӵ������
    if(ERFK_PLUNDER != poEney->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        poMyself->AddEnemy(poEney->GetDT_PLAYER_BASE_DATA().dwID);
        poEney->AddEnemy(poMyself->GetDT_PLAYER_BASE_DATA().dwID);
        if((poCapture != poEney) && (poCapture != poMyself))
        {
            poCapture->AddEnemy(poMyself->GetDT_PLAYER_BASE_DATA().dwID);
        }
    }

    //��¼ս��
    AddPlunderBattleLog(poMyself, poEney, poCapture, stReqRaram.byResistFlag, bChallengeSuccess, stPlunderEncourage.dwCoin, stPlunderEncourage.dwScience);

    CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(poMyself, poEney, poCapture);

    return TRUE;
}

VOID CPlunderMgr::CaptureChange(CPlayer* poMyself, CPlayer* poEney, CPlayer* poCapture, UINT8 byResistFlag, UINT8 byCaptureGridIdx, BOOL bChallengeSuccess)
{
    //DBG_INFO( _SDT( "[%s: %d]:CaptureChange, Myself[%u] Enemy[%u] Capture[%u] ResistFlag[%u] CaptureGridIdx[%u] ChallengeSuccess[%u] *****************" ),
    //	 MSG_MARK, poMyself->GetID(),  poEney->GetID(), poCapture->GetID(), 	byResistFlag,  byCaptureGridIdx, bChallengeSuccess);

    //ս��ʧ�ܣ����²�������仯
    if(!bChallengeSuccess)
    {
        return;
    }

    CPlunder* poMyselfPlunder = poMyself->GetPlunder();
    CPlunder* poEnemyPlunder = poEney->GetPlunder();
    CPlunder* poCapturePlunder = poCapture->GetPlunder();
    if((NULL == poMyselfPlunder) || (NULL == poEnemyPlunder) || (NULL == poCapturePlunder))
    {
        return;
    }

    //����
    if(1 == byResistFlag)
    {

        //DBG_INFO( _SDT( "[%s: %d]:resist del capture:%u *****************" ), MSG_MARK, poMyself->GetDT_PLAYER_BASE_DATA().dwID );

        poEnemyPlunder->DelCapture(poMyself->GetDT_PLAYER_BASE_DATA().dwID);
        poMyselfPlunder->OnFree();
        CPlayerBaseDataCacheMgr::Instance()->OnCapture(poMyself->GetDT_PLAYER_BASE_DATA().dwID, 0);//���·�²��ID
    }

    //�Ӷ�
    if((1 != byResistFlag) && (poEney == poCapture))
    {
        poMyselfPlunder->AddCapture(poEney->GetDT_PLAYER_BASE_DATA().dwID, byCaptureGridIdx);
        poEnemyPlunder->OnCapture(poMyself->GetDT_PLAYER_BASE_DATA().dwID);
        CPlayerBaseDataCacheMgr::Instance()->OnCapture(poEney->GetDT_PLAYER_BASE_DATA().dwID, poMyself->GetDT_PLAYER_BASE_DATA().dwID);//���·�²��ID
    }

    //�����²
    if((1 != byResistFlag) && (poEney != poCapture))
    {

        //DBG_INFO( _SDT( "[%s: %d]:del capture:%u *****************" ), MSG_MARK, poCapture->GetDT_PLAYER_BASE_DATA().dwID );

        poEnemyPlunder->DelCapture(poCapture->GetDT_PLAYER_BASE_DATA().dwID);
        poMyselfPlunder->AddCapture(poCapture->GetDT_PLAYER_BASE_DATA().dwID, byCaptureGridIdx);
        poCapturePlunder->OnCapture(poMyself->GetDT_PLAYER_BASE_DATA().dwID);
        CPlayerBaseDataCacheMgr::Instance()->OnCapture(poCapture->GetDT_PLAYER_BASE_DATA().dwID, poMyself->GetDT_PLAYER_BASE_DATA().dwID);//���·�²��ID
    }
}


BOOL CPlunderMgr::AddPlunderBattleLog(CPlayer* poMyself, CPlayer* poEney, CPlayer* poCapture, UINT8 byResistFlag, BOOL bChallengeSuccess, UINT64 qwPlunderCoin, UINT64 qwPlunderScience)
{
    CPlunder* poMyselfPlunder = poMyself->GetPlunder();
    CPlunder* poEnemyPlunder = poEney->GetPlunder();
    CPlunder* poCapturePlunder = poCapture->GetPlunder();
    if((NULL == poMyselfPlunder) || (NULL == poEnemyPlunder) || (NULL == poCapturePlunder))
    {
        return FALSE;
    }


    //���㱻�������µ����档
    UINT32 dwCoin = 0;
    UINT32 dwScience = 0;
    GetLeftIncome(poEney, poCapture->GetDT_PLAYER_BASE_DATA().dwID, dwCoin, dwScience);

    //��¼ս��
    UINT8 byPlunderFlag = GetPlunderBattleLogType(poEney, poCapture, byResistFlag);
    DT_PLUNDER_BATTLELOG_DATA stBattleLog;
    memset(&stBattleLog, 0, sizeof(stBattleLog));
    stBattleLog.byPlunderFlag = byPlunderFlag;
    stBattleLog.qwPlunderTime = SDTimeSecs();
    stBattleLog.dwActivePlayerID = poMyself->GetDT_PLAYER_BASE_DATA().dwID;
    stBattleLog.dwPassivePlayerID = poEney->GetDT_PLAYER_BASE_DATA().dwID;
    stBattleLog.dwCapturePlayerID = poCapture->GetDT_PLAYER_BASE_DATA().dwID;
    stBattleLog.byResult = bChallengeSuccess == TRUE ? 0 : 1;
    //stBattleLog.qwPlunderCoin = qwPlunderCoin;
    //stBattleLog.qwPlunderScience = qwPlunderScience;

    stBattleLog.qwPlunderCoin = dwCoin;
    stBattleLog.qwPlunderScience = dwScience;
    poMyselfPlunder->AddBattleLog(&stBattleLog);
    poEnemyPlunder->AddBattleLog(&stBattleLog);
    //�����²֮ս����²Ҳ��¼ս��
    if((poEney != poCapture) && (0 == byResistFlag))
    {
        poCapturePlunder->AddBattleLog(&stBattleLog);
    }

    return TRUE;
}

EPlunderBattleLogType CPlunderMgr::GetPlunderBattleLogType(CPlayer* poEney, CPlayer* poCapture, UINT8 byResistFlag)
{
    //����
    if(1 == byResistFlag)
    {
        return EPBLT_RESIST;
    }

    if(poEney == poCapture)
    {
        return EPBLT_PLUNDER;
    }
    else
    {
        return EPBLT_RAP;
    }
}

VOID CPlunderMgr::PlunderEncourage(CPlayer* poMyself, CPlayer* poEney, UINT8 byResistFlag, BOOL bChallengeSuccess, UINT32& dwCoin, UINT32& dwScience)
{
    //����û���κν�������dwCoin/dwScience��ֵ����ս��������²�����·�²����������
    if(1 == byResistFlag)
    {
        if(!bChallengeSuccess)
        {
            return;
        }

        GetLeftIncome(poEney, poMyself->GetDT_PLAYER_BASE_DATA().dwID, dwCoin, dwScience);
        return; //����û���κν���
    }

    //�Ӷ���ȥ��������������
    dwCoin = 0;
    dwScience = 0;
}


UINT16 CPlunderMgr::OpenPlunderScence(CPlayer* poOwner, UINT16& wCanPlunderNum, UINT16& wFreePlunderNum, UINT32& dwPlunderGold,  UINT16& wPlunderItemNum,
                                      UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM])
{
    CPlunder* poPlunder = poOwner->GetPlunder();
    if(NULL == poPlunder)
    {
        return ERR_OPEN_PLUNDER_RECOMMEND_PLAYER::ID_PLUNDER_UNLOCK;
    }
    UINT32 dwCaptureOwnerPlayerID = 0;
    poPlunder->GetPlunderData(wCanPlunderNum, wFreePlunderNum, dwPlunderGold, wPlunderItemNum, dwCaptureOwnerPlayerID);

    //��ȡ�Ƽ����
    UINT16 wPlayerLevel = poOwner->GetLevel();
    SRecommendPlayerRcd& stRecommendPlayerRcd = poPlunder->GetRecommendPlayerRcd();
    if((wPlayerLevel < m_wPlunderOpenLevel + 2) || (poOwner->CKGuide( EGF_PLUNDER)))
    {
        GetRecommendRobot(wPlayerLevel, byPlunderPlayerNum, astPlunderPlayerInfo, *poPlunder);
    }
    else if(wPlayerLevel < m_wPlunderOpenLevel + 6)
    {
        GetRecommendLimit(poOwner->GetDT_PLAYER_BASE_DATA().dwID, poOwner->GetLevel(), stRecommendPlayerRcd, byPlunderPlayerNum, astPlunderPlayerInfo, TRUE, *poPlunder);
    }
    else
    {
        GetRecommendLimit(poOwner->GetDT_PLAYER_BASE_DATA().dwID, poOwner->GetLevel(), stRecommendPlayerRcd, byPlunderPlayerNum, astPlunderPlayerInfo, FALSE, *poPlunder);
    }


    return ERR_OPEN_PLUNDER_RECOMMEND_PLAYER::ID_SUCCESS;
}


//��ȡ�Ƽ���ң�20~21 ������
VOID CPlunderMgr::GetRecommendRobot(UINT16 wLevel, UINT8& byPlunderPlayerNum,
                                    DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM], CPlunder &oOwnPlunder)
{
    if( !m_bRobotInit )
    {
        //֮ǰδ��ʼ���ɹ������ڴ˳�ʼ��
        InitRobot();
    }
    byPlunderPlayerNum = MAX_GET_PLUNDER_ENEMY_NUM;
    memcpy(astPlunderPlayerInfo, m_astPlunderRobot, sizeof(m_astPlunderRobot));
    for( INT32 nIndex = 0, nCurIndex = 0; nIndex < MAX_ROBOT_NUM && nCurIndex < MAX_GET_PLUNDER_ENEMY_NUM; ++nIndex )
    {
        if( NULL != oOwnPlunder.GetCaptureMap().GetData( astPlunderPlayerInfo[nIndex].dwPlayerID ) )
        {
            continue;
        }

        memcpy(&astPlunderPlayerInfo[nCurIndex++], &m_astPlunderRobot[nIndex], sizeof(DT_PLUNDER_PLAYER_DATA));
    }


    for(UINT8 byIdx = 0; byIdx < MAX_GET_PLUNDER_ENEMY_NUM; byIdx++)
    {
        astPlunderPlayerInfo[byIdx].wLevel = wLevel;
    }
}

//��ȡ�Ƽ���ң�22~25 û�б���²,25���� �ȼ�����
VOID CPlunderMgr::GetRecommendLimit(UINT32 dwPlayerID, UINT16 wPlayerLevel, SRecommendPlayerRcd& stRecommendPlayerRcd,
                                    UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM], BOOL bNotBecapture, CPlunder &oOwnPlunder)
{
    byPlunderPlayerNum = 0;
    CPlayerBaseDataVec vecPlayer;

    C3232Map mapHave;
    //��ȡ���Լ���1�������1��
    UINT8 byNum = 1;
    CPlayerBaseDataCacheMgr::Instance()->GetPlayerByLevel(dwPlayerID, wPlayerLevel + 1, byNum, vecPlayer, stRecommendPlayerRcd.dwPlayerH1, oOwnPlunder, bNotBecapture);
    GetPlayerData(vecPlayer, byPlunderPlayerNum, astPlunderPlayerInfo, mapHave);
    UINT8 bySize = vecPlayer.size();
    if(bySize > 0)
    {
        stRecommendPlayerRcd.dwPlayerH1 = vecPlayer[bySize - 1]->dwID; //��¼�������´�ˢ�²�ͬ���
    }
    vecPlayer.clear();
    //��ȡ�ȼ�һ�������3��
    byNum = 3 + (byNum - bySize);////��ȡ�ȼ�һ�������3��,����1��û�У���ͬ�ȼ��Ĳ���
    CPlayerBaseDataCacheMgr::Instance()->GetPlayerByLevel(dwPlayerID, wPlayerLevel, byNum, vecPlayer, stRecommendPlayerRcd.dwPlayerE, oOwnPlunder, bNotBecapture);
    GetPlayerData(vecPlayer, byPlunderPlayerNum, astPlunderPlayerInfo, mapHave);
    bySize = vecPlayer.size();
    if(bySize > 1)
    {
        stRecommendPlayerRcd.dwPlayerE = vecPlayer[bySize - 1]->dwID; //��¼�������´�ˢ�²�ͬ���
    }
	else
	{
		stRecommendPlayerRcd.dwPlayerE = 0;
    }
    vecPlayer.clear();
    //��ȡ���Լ���1�������1��
    byNum = 1 + (byNum - bySize);////��ȡ��1�ȼ����1��,��ͬ�ȼ���û�У����1���Ĳ���
    CPlayerBaseDataCacheMgr::Instance()->GetPlayerByLevel(dwPlayerID, wPlayerLevel - 1, byNum, vecPlayer, stRecommendPlayerRcd.dwPlayerL1, oOwnPlunder, bNotBecapture);
    GetPlayerData(vecPlayer, byPlunderPlayerNum, astPlunderPlayerInfo, mapHave);
    bySize = vecPlayer.size();
    if(bySize > 0)
    {
        stRecommendPlayerRcd.dwPlayerL1 = vecPlayer[bySize - 1]->dwID; //��¼�������´�ˢ�²�ͬ���
    }
	else
	{
		stRecommendPlayerRcd.dwPlayerL1 = 0;
    }
    //������������ȡ�ȼ��ӽ������
    if(byPlunderPlayerNum < MAX_GET_PLUNDER_ENEMY_NUM)
    {
        UINT8 byLoopNum = (UINT8)(CSinglePramMgr::Instance()->GetMaxPlayerLevel());
        UINT16 wNextLevel = wPlayerLevel - 2;
        UINT8 byGap = 2;
        for(; (((byPlunderPlayerNum < MAX_GET_PLUNDER_ENEMY_NUM)) && (byLoopNum > 0) && (wNextLevel > 0)); byLoopNum--, byGap++)
        {
            UINT8 byNum = MAX_GET_PLUNDER_ENEMY_NUM - byPlunderPlayerNum;
            if(0 == byLoopNum % 2)
            {
                wNextLevel = wPlayerLevel - byGap;
            }
            else
            {
                wNextLevel = wPlayerLevel + byGap;
            }
            CPlayerBaseDataCacheMgr::Instance()->GetPlayerByLevel(dwPlayerID, wNextLevel, byNum, vecPlayer, 0, oOwnPlunder, bNotBecapture);
            GetPlayerData(vecPlayer, byPlunderPlayerNum, astPlunderPlayerInfo, mapHave);
        }
    }
    //���������ǲ�����ȡ������
    if(byPlunderPlayerNum < MAX_GET_PLUNDER_ENEMY_NUM)
    {
        if( !m_bRobotInit )
        {
            //֮ǰδ��ʼ���ɹ������ڴ˳�ʼ��
            InitRobot();
        }
        byNum = MAX_GET_PLUNDER_ENEMY_NUM - byPlunderPlayerNum;
        for(UINT8 byIdx = 0, nCurIndex = 0; byIdx < byNum && nCurIndex < MAX_ROBOT_NUM; nCurIndex++)
        {
            if( NULL != oOwnPlunder.GetCaptureMap().GetData( m_astPlunderRobot[nCurIndex].dwPlayerID ) )
            {

                continue;
            }
            memcpy(&astPlunderPlayerInfo[byPlunderPlayerNum + byIdx], &m_astPlunderRobot[nCurIndex], sizeof(DT_PLUNDER_PLAYER_DATA));
            astPlunderPlayerInfo[byPlunderPlayerNum + byIdx].wLevel = wPlayerLevel;
            byIdx++;
        }
        byPlunderPlayerNum = MAX_GET_PLUNDER_ENEMY_NUM;
    }
}


//��ȡ�����Ϣ
VOID CPlunderMgr::GetPlayerData(CPlayerBaseDataVec& vecPlayer, UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM], C3232Map& mapHave)
{
    UINT8 bySize = vecPlayer.size();
    for(UINT8 byIdx = 0; ((byIdx < bySize) && (byPlunderPlayerNum < MAX_GET_PLUNDER_ENEMY_NUM)); byIdx++)
    {
        SPlayerBaseData* pstPlayerBaseData = vecPlayer[byIdx];
        if(mapHave.find(pstPlayerBaseData->dwID) != mapHave.end())
        {
            continue;
        }
        DT_PLUNDER_PLAYER_DATA& stPlunderPlayerData = astPlunderPlayerInfo[byPlunderPlayerNum];
        stPlunderPlayerData.dwPlayerID = pstPlayerBaseData->dwID;
        SDStrcpy(stPlunderPlayerData.aszDispName, pstPlayerBaseData->aszDispName);
        stPlunderPlayerData.wMainHeroKindID = pstPlayerBaseData->wMainHeroKindID;
        stPlunderPlayerData.byRobotFunc = pstPlayerBaseData->byRobotFunc;
        stPlunderPlayerData.wLevel = pstPlayerBaseData->wLevel;
        stPlunderPlayerData.dwPower = pstPlayerBaseData->dwPower;
        if(0 != pstPlayerBaseData->dwCaptureOwner)
        {
            const SPlayerBaseData* pstOwnerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(pstPlayerBaseData->dwCaptureOwner);
            if(pstOwnerBaseData)
            {
                stPlunderPlayerData.byHaveOwnerFlag = 1;
                DT_BECAPTURE_DATA& stOwnerInfo = stPlunderPlayerData.astOwnerInfo[0];
                stOwnerInfo.dwOwnerID = pstOwnerBaseData->dwID;
                SDStrcpy(stOwnerInfo.aszOwnerDispName, pstOwnerBaseData->aszDispName);
                stOwnerInfo.wOwnerLevel = pstOwnerBaseData->wLevel;
                stOwnerInfo.dwOwnerPower = pstOwnerBaseData->dwPower;
                stOwnerInfo.dwReleaseCountdown = 0;// �Ƽ����ʱ��ֵ���и�ֵ
            }
        }
        else
        {
            stPlunderPlayerData.byHaveOwnerFlag = 0;
        }

        mapHave[pstPlayerBaseData->dwID] = pstPlayerBaseData->dwID;
        byPlunderPlayerNum++;
    }

}

VOID CPlunderMgr::GetPlunderLevelGapItem(UINT8& byUseItemGapLevel, UINT32& dwPlunderItemPrice, UINT16& wPlunderItemID)
{
    byUseItemGapLevel = 5; //���ã�todo
    dwPlunderItemPrice = m_dwPlunderItemPrice;
    wPlunderItemID = m_wPlunderItemID;
}


//�����Ӷ����
UINT16 CPlunderMgr::RefreshPlunderRecommend(CPlayer* poOwner, UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM])
{
    CPlunder* poPlunder = poOwner->GetPlunder();
    if(NULL == poPlunder)
    {
        return ERR_REFRESH_PLUNDER_RECOMMEND::ID_PLUNDER_UNLOCK;
    }

    //��ȡ�Ƽ����
    UINT16 wPlayerLevel = poOwner->GetLevel();
    SRecommendPlayerRcd& stRecommendPlayerRcd = poPlunder->GetRecommendPlayerRcd();
    if(wPlayerLevel < m_wPlunderOpenLevel + 2)
    {
        GetRecommendRobot(wPlayerLevel, byPlunderPlayerNum, astPlunderPlayerInfo, *poPlunder);
    }
    else if(wPlayerLevel < m_wPlunderOpenLevel + 6)
    {
        GetRecommendLimit(poOwner->GetDT_PLAYER_BASE_DATA().dwID, poOwner->GetLevel(), stRecommendPlayerRcd, byPlunderPlayerNum, astPlunderPlayerInfo, TRUE, *poPlunder);
    }
    else
    {
        GetRecommendLimit(poOwner->GetDT_PLAYER_BASE_DATA().dwID, poOwner->GetLevel(), stRecommendPlayerRcd, byPlunderPlayerNum, astPlunderPlayerInfo, FALSE, *poPlunder);
    }

    return ERR_REFRESH_PLUNDER_RECOMMEND::ID_SUCCESS;
}


VOID CPlunderMgr::OnReleaseCaptureEvent(UINT32 dwOwnerID, UINT32 dwCaptureID)
{
    CPlayer* poOwner = CPlayerMgr::Instance()->FindPlayer(dwOwnerID);
    //��²���ͷŷ�²
    if(poOwner)
    {
        CPlunder* poPlunder = poOwner->GetPlunder();
        if(poPlunder)
        {
            CPlunderCapture* poCapture = poPlunder->GetCapture(dwCaptureID);
            if(poCapture)
            {
                UINT32 dwCoin = 0;
                UINT32 dwScience = 0;
                CPlunderMgr::Instance()->GetLeftIncome(poOwner, dwCaptureID, dwCoin, dwScience);

                AddReleaseBattleLog(dwOwnerID, dwCaptureID, EPBLT_AUTOFREE, dwCoin, dwScience);

                USR_INFO( _SDT( "[%s: %d]:PlayerID:%u delete CaptureID:%u *****************" ), MSG_MARK, dwOwnerID, dwCaptureID );

                poPlunder->DelCapture(dwCaptureID);
                CTimerEventMgr::Instance()->DelReleaseCaptureEvent(dwOwnerID, dwCaptureID);
                CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(poOwner, CPlayerMgr::Instance()->FindPlayer(dwCaptureID), NULL);
            }
            else
            {
                //���ݳ���ū����û��ū����Ϣ
                CPlayer* poCaptureTemp = CPlayerMgr::Instance()->FindPlayer(dwCaptureID);
                if (poCaptureTemp)
                {
                    //��ȡū���Ӷ���Ϣ
                    CPlunder* poPlunder = poCaptureTemp->GetPlunder();
                    if (poPlunder)
                    {
                        //���ū��IDeas�Ƿ����
                        if (poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID == dwOwnerID)
                        {
                            poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID = 0;
                            CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCaptureID, 0);
                        }
                    }
                }
            }
        }
        else
        {

            //���ݳ���ū����û��ū����Ϣ
            CPlayer* poCaptureTemp = CPlayerMgr::Instance()->FindPlayer(dwCaptureID);
            if (poCaptureTemp)
            {
                //��ȡū���Ӷ���Ϣ
                CPlunder* poPlunder = poCaptureTemp->GetPlunder();
                if (poPlunder)
                {
                    //���ū��IDeas�Ƿ����
                    if (poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID == dwOwnerID)
                    {
                        poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID = 0;
                        CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCaptureID, 0);
                    }
                }
            }
            USR_INFO( _SDT( "[%s: %d]: On Time BUG*****************" ), MSG_MARK );
        }
    }
    else
    {
        //��²����CPlunder::Initʱ���⣬����ò���vecReleaseCaptureID.push_back
        //SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwOwnerID);
        //if(pstPlayerBaseData)
        //{
        //    pstPlayerBaseData->stSyncProp.vecReleaseCaptureID.push_back(dwCaptureID);
        //}

        //���ݳ���ū����û��ū����Ϣ
        CPlayer* poCaptureTemp = CPlayerMgr::Instance()->FindPlayer(dwCaptureID);
        if (poCaptureTemp)
        {
            //��ȡū���Ӷ���Ϣ
            CPlunder* poPlunder = poCaptureTemp->GetPlunder();
            if (poPlunder)
            {
                //���ū��ID�Ƿ����
                if (poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID == dwOwnerID)
                {
                    poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID = 0;
                    CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCaptureID, 0);
                }
            }
        }
        else
        {
            CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCaptureID, 0);
        }

        CTimerEventMgr::Instance()->DelReleaseCaptureEvent(dwOwnerID, dwCaptureID);

        //DBG_INFO( _SDT( "[%s: %d]: On Time  ��SYNC Data *****************" ), MSG_MARK );

        CGetPlayerDataMgr::Instance()->GetPlayerData(dwOwnerID, GET_PLAYERDATATYPE_SYNCDATA, dwOwnerID);
    }
}


//��ӷ�²�ͷ�ս��
BOOL CPlunderMgr::AddReleaseBattleLog(UINT32 dwOwnerID, UINT32 dwCaptureID, EPlunderBattleLogType eReleaseType, UINT32 dwCoin, UINT32 dwScience)
{
    DT_PLUNDER_BATTLELOG_DATA stBattleLog;
    memset(&stBattleLog, 0, sizeof(stBattleLog));
    stBattleLog.byPlunderFlag = eReleaseType;
    stBattleLog.qwPlunderTime = SDTimeSecs();
    stBattleLog.dwCapturePlayerID = dwCaptureID;
    stBattleLog.qwPlunderCoin = dwCoin;
    stBattleLog.qwPlunderScience = dwScience;

    switch(eReleaseType)
    {
        //����
    case EPBLT_DRIVEAWAY:
    {
        stBattleLog.dwActivePlayerID = dwCaptureID;
        stBattleLog.dwPassivePlayerID = dwOwnerID;

        CPlayer *poOwnerPlayer = CPlayerMgr::Instance()->FindPlayer(dwOwnerID);
        if (NULL == poOwnerPlayer)
        {
            break;
        }

        CPlunder* poOwnerPlunder = poOwnerPlayer->GetPlunder();
        if(poOwnerPlunder)
        {
            poOwnerPlunder->AddBattleLog(&stBattleLog);
        }
        else
        {
            const SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwOwnerID);
            if(pstPlayerBaseData)
            {
                (const_cast<SPlayerBaseData*>(pstPlayerBaseData))->stSyncProp.vecPlunderLog.push_back(stBattleLog);
                (const_cast<SPlayerBaseData*>(pstPlayerBaseData))->stSyncProp.vecReleaseCaptureID.push_back(dwCaptureID);
            }
        }

        CPlayer *poCapturePlayer = CPlayerMgr::Instance()->FindPlayer(dwCaptureID);
        if (NULL == poCapturePlayer)
        {
            break;
        }
        CPlunder* poCapturePlunder = poCapturePlayer->GetPlunder();
        if(poCapturePlunder)
        {
            poCapturePlunder->AddBattleLog(&stBattleLog);
        }
        else
        {
            //����Ϊ��²��������������
        }
    }
    break;
    //�Զ��ͷţ����¼�������²���ص�
    case EPBLT_AUTOFREE:
        //�ֶ��ͷ�
    case EPBLT_MANUALFREE:
        //�����������
    case EPBLT_INCOME:
        //ե������
    case EPBLT_BLEED:
    {
        stBattleLog.dwActivePlayerID = dwOwnerID;
        stBattleLog.dwPassivePlayerID = dwCaptureID;
		CPlayer *poOwnerPlayer = CPlayerMgr::Instance()->FindPlayer(dwOwnerID);
		if (NULL == poOwnerPlayer)
		{
			break;
		}

        CPlunder* poOwnerPlunder = poOwnerPlayer->GetPlunder();
        if(poOwnerPlunder)
        {
            poOwnerPlunder->AddBattleLog(&stBattleLog);
        }
        else
        {
            //�Զ��ͷţ����¼�������²���ص�����������
            //�ֶ��ͷ�Ϊ���˴�������������
            //���������ͷ�Ϊ���˴�������������
            //ե�������ͷ�Ϊ���˴�������������
        }

		CPlayer *poCapturePlayer = CPlayerMgr::Instance()->FindPlayer(dwCaptureID);
		if (NULL == poCapturePlayer)
		{
			break;
		}
		CPlunder* poCapturePlunder = poCapturePlayer->GetPlunder();
        if(poCapturePlunder)
        {
            poCapturePlunder->AddBattleLog(&stBattleLog);
        }
        else
        {
            const SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwCaptureID);
            if(pstPlayerBaseData)
            {
                (const_cast<SPlayerBaseData*>(pstPlayerBaseData))->stSyncProp.vecPlunderLog.push_back(stBattleLog);
            }
        }
    }
    break;
    }


    return TRUE;
}


//��������
VOID CPlunderMgr::GetLeftIncome(CPlayer* poOwner, UINT32 dwCaptureID, UINT32& dwCoin, UINT32& dwScience, BOOL bManualFree)
{
    dwCoin = 0;
    dwScience = 0;
    if(NULL == poOwner)
    {
        return;
    }
    CPlunder* poPlunder = poOwner->GetPlunder();
    if(NULL == poPlunder)
    {
        return;
    }
    CPlunderCapture* poCapture = poPlunder->GetCapture(dwCaptureID);
    if(NULL == poCapture)
    {
        return;
    }
    DT_CAPTURE_DATA& stDT_CAPTURE_DATA = poCapture->GetDT_CAPTURE_DATA();
    //δ���ù������ͣ���������
    if(EPWT_UNSET == stDT_CAPTURE_DATA.byIncomeType)
    {
        return;
    }
    if(stDT_CAPTURE_DATA.byCaptureGridIdx >= MAX_CAPTURE_NUM)
    {
        return;
    }

    if(stDT_CAPTURE_DATA.qwLastCollectTime < stDT_CAPTURE_DATA.qwCaptureTime)//�쳣,
    {
        stDT_CAPTURE_DATA.qwLastCollectTime = stDT_CAPTURE_DATA.qwCaptureTime;
    }

    const SPlayerBaseData* pstCaptureBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(stDT_CAPTURE_DATA.dwCapturePlayerID);
    UINT16 wCaptureLevel = 0;
    if(pstCaptureBaseData)
    {
        wCaptureLevel = pstCaptureBaseData->wLevel;
    }
    else
    {
        wCaptureLevel = poOwner->GetLevel();//�쳣��ȡ��ҵȼ�
    }

    //����Ƿ��ǻ�����
    if(pstCaptureBaseData && ERFK_PLUNDER == pstCaptureBaseData->byRobotFunc)
    {
        wCaptureLevel = poOwner->GetLevel();
    }

    //�ѹ�����ʱ��
    UINT32 dwPassTime = (UINT32)(SDTimeSecs() - stDT_CAPTURE_DATA.qwLastCollectTime);
    //�ѹ�������ʱ��
    dwPassTime = dwPassTime > m_dwCaptureWorkSecond ? m_dwCaptureWorkSecond : dwPassTime;

    //DBG_INFO( _SDT("PlayerID[%u] LastCollectTime:%s, Current Time:%s, CollectTime:%u"), poOwner->GetID(),
    //          Time_ToString(stDT_CAPTURE_DATA.qwLastCollectTime).c_str(),
    //          Time_ToString().c_str(),
    //          dwPassTime);

    UINT32 dwIncomeValue = 0;
    UINT32 dwCaptureOwnerPlayerID = poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID;
    switch(stDT_CAPTURE_DATA.byIncomeType)
    {
    case EPWT_COIN:
    {
        dwCoin = (UINT32)(CPlunderBasePropMgr::Instance()->GetWorkCoin(wCaptureLevel) * dwPassTime /  m_dwCaptureWorkSecond);
        if(0 != dwCaptureOwnerPlayerID)//�з�²��������80%
        {
            dwCoin = dwCoin  * 8 / 10;
        }
        dwIncomeValue = dwCoin;

    }
    break;
    case EPWT_SCIENCE:
    {
        dwScience = (UINT32)(CPlunderBasePropMgr::Instance()->GetWorkScience(wCaptureLevel) * dwPassTime /  m_dwCaptureWorkSecond);
        if(0 != dwCaptureOwnerPlayerID)//�з�²��������80%
        {
            dwScience = dwScience  * 8 / 10;
        }
        dwIncomeValue = dwScience;
    }
    break;
    default:
    {
        USR_INFO( _SDT( "default IncomeType=%d" ), stDT_CAPTURE_DATA.byIncomeType );
        dwScience = (UINT32)(CPlunderBasePropMgr::Instance()->GetWorkScience(wCaptureLevel) * dwPassTime /  m_dwCaptureWorkSecond);
        if(0 != dwCaptureOwnerPlayerID)//�з�²��������80%
        {
            dwScience = dwScience  * 8 / 10;
        }
        dwIncomeValue = dwScience;
    }
    break;
    }

    USR_INFO( _SDT("PlayerID[%u] Get Science:%d,Coin:%d, IncomeType:%d"), poOwner->GetID(), dwScience, dwCoin, stDT_CAPTURE_DATA.byIncomeType );
    //�ֶ��ͷ�ֱ�Ӹ�Ǯ
    if(bManualFree)
    {
        //poOwner->GetDT_PLAYER_BASE_DATA().qwCoin += dwCoin;
        //poOwner->GetDT_PLAYER_BASE_DATA().qwScience += dwScience;
        poOwner->AddCoin(dwCoin, CRecordMgr::EACT_PLUNDER);
        poOwner->AddScience(dwScience, CRecordMgr::EAST_PLUNDER);
    }
    else
    {
        DT_PLUNDER_GRID_DATA& stDT_PLUNDER_GRID_DATA = poPlunder->GetDT_PLUNDER_BASE_DATA().astCaptureGridInfo[stDT_CAPTURE_DATA.byCaptureGridIdx];
        stDT_PLUNDER_GRID_DATA.byIncomeType = stDT_CAPTURE_DATA.byIncomeType;
        stDT_PLUNDER_GRID_DATA.dwIncomeValue = dwIncomeValue;
    }
}



BOOL CPlunderMgr::Plunder(CPlayer* poMyself, CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, DT_BATTLE_DATA5& stDT_BATTLE_DATA, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage)
{
    if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
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

    //�Ӷ�ص�
    BOOL bSuccess = (EBT_SUCCESS == stDT_BATTLE_DATA.byBattleResult) ? TRUE : FALSE;
    if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        stDT_BATTLE_DATA.byBattleResult = EBT_SUCCESS;
        bSuccess = TRUE;
    }
    CPlunderMgr::Instance()->OnPlunder(poMyself, poEnemy, poCapture, stReqRaram, bSuccess, stPlunderEncourage);

    return TRUE;
}

BOOL CPlunderMgr::Plunder2(CPlayer* poMyself, CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, DT_BATTLE_DATA3& stDT_BATTLE_DATA, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage)
{
    if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
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

    //�Ӷ�ص�
    BOOL bSuccess = (EBT_SUCCESS == stDT_BATTLE_DATA.byBattleResult) ? TRUE : FALSE;
    if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        stDT_BATTLE_DATA.byBattleResult = EBT_SUCCESS;
        bSuccess = TRUE;
    }
    CPlunderMgr::Instance()->OnPlunder(poMyself, poEnemy, poCapture, stReqRaram, bSuccess, stPlunderEncourage);

    return TRUE;
}

BOOL CPlunderMgr::Plunder3(CPlayer* poMyself, CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, DT_BATTLE_DATA4& stDT_BATTLE_DATA, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage)
{
	if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
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

	//�Ӷ�ص�
	BOOL bSuccess = (EBT_SUCCESS == stDT_BATTLE_DATA.byBattleResult) ? TRUE : FALSE;
	if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
	{
		stDT_BATTLE_DATA.byBattleResult = EBT_SUCCESS;
		bSuccess = TRUE;
	}
	CPlunderMgr::Instance()->OnPlunder(poMyself, poEnemy, poCapture, stReqRaram, bSuccess, stPlunderEncourage);

	return TRUE;
}