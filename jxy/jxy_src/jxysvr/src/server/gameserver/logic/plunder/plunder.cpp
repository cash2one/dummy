#include "plunder.h"
#include "plundermgr.h"
#include "plunderbattlelogmgr.h"
#include "plundercapturemgr.h"
#include "plunderbasepropmgr.h"
#include "plundergridpropmgr.h"
#include <logic/player/playermgr.h>
#include <common/client/errdef.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <logic/player/playergetdatamgr.h>
#include <protocol/server/protogsdb.h>
#include <net/cli/user.h>
#include <net/gt/gtpktbuilder.h>
#include <logic/event/timereventmgr.h>
#include <logic/player/playersavemgr.h>
#include <db/autosqlbuf.h>
#include "json/json.h"
#include "logic/record/recordmgr.h"
#include <logic/vip/vippropmgr.h>
#include <logic/lua/luamgr.h>
#include <logic/base/basedefine.h>
#include <logic/bag/bag.h>
#include <logic/task/taskmgr.h>
#include <logic/enemy/enemy.h>
#include <logic/player/player.h>
#include <utility.h>

using namespace SGDP;

IMPLEMENT_CLASS_POOL_MGR(CPlunder)
CPlunder::CPlunder()
{
    memset(&m_stDT_PLUNDER_BASE_DATA, 0, sizeof(m_stDT_PLUNDER_BASE_DATA));
    m_deqPlunderBattleLog.clear();
    m_mapCapture.Clear();
    m_mapCridCapture.Clear();
    memset(&m_stRecommendPlayerRcd, 0, sizeof(m_stRecommendPlayerRcd));
    m_dwPlunderNeedGold = 0;
    SPlunderBaseProp& stPlunderBaseProp = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp();
    m_dwCaptureKeepSecond = stPlunderBaseProp.dwCaptureKeepSecond;
    //m_dwDriveAwayBaseGold = stPlunderBaseProp.dwDriveAwayBaseGold;
    //m_dwDriveAwayIncGold = stPlunderBaseProp.dwDriveAwayIncGold;
    m_wPlunderLowerLevelItemID = CPlunderBasePropMgr::Instance()->GetPlunderLowerLevelItemID();
    m_dwPlayerID = 0;
    m_mapPlunderReq.clear();
}


CPlunder::~CPlunder()
{
    for(CPlunderBattleLogDeqItr itr = m_deqPlunderBattleLog.begin(); itr != m_deqPlunderBattleLog.end(); itr++)
    {
        CPlunderBattleLog* poBattleLog = *itr;
        if(poBattleLog)
        {
            CPlunderBattleLogMgr::Instance()->RemoveBattleLog(poBattleLog);
        }
    }
    m_deqPlunderBattleLog.clear();


    CPlunderCapture* poCapture = m_mapCapture.GetFistData();
    while(poCapture)
    {
        CPlunderCaptureMgr::Instance()->RemovePlunderCapture(m_dwPlayerID, poCapture->GetDT_CAPTURE_DATA().dwCapturePlayerID);

        poCapture = m_mapCapture.GetNextData();
    }
    m_mapCapture.Clear();
    m_mapCridCapture.Clear();
}


BOOL CPlunder::Init(DT_PLUNDER_DATA& stDT_PLUNDER_DATA, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }
    memcpy(&m_stDT_PLUNDER_BASE_DATA, &stDT_PLUNDER_DATA.stPlunderBaseData, sizeof(DT_PLUNDER_BASE_DATA));
    m_poOwner = poOwner;
    m_dwPlayerID = m_poOwner->GetDT_PLAYER_BASE_DATA().dwID;

    if(!InitBattleLog(stDT_PLUNDER_DATA.stPlunderBattleLog))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitBattleLog failed!"), MSG_MARK);
        return FALSE;
    }

    if(!InitCapture(stDT_PLUNDER_DATA.stCaptureData))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitCapture failed!"), MSG_MARK);
        return FALSE;
    }
    m_poOwner->SetPlunder(this);

    //DBG_INFO( _SDT( "[%s: %d]:PlayerID:%u, Init 0" ), MSG_MARK, m_poOwner->GetID() );

    CkBeRelease();

    //DBG_INFO( _SDT( "[%s: %d]:PlayerID:%u, Init 1" ), MSG_MARK, m_poOwner->GetID() );

    CkCaptureRelease();

	CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(m_poOwner);
	CPlayerBaseDataCacheMgr::Instance()->OnOpenPlunder(poOwner->GetID());
    return TRUE;
}

BOOL CPlunder::InitBattleLog(const DT_PLUNDER_BATTLELOG_DATA_LIST& stPlunderBattleLog)
{
    UINT8 bySize = stPlunderBattleLog.byBattleLogNum;
    //���/�����Ѱ����ڴӴ�С����
    for(UINT8 byIdx = 0; byIdx < bySize; byIdx++)
    {
        const DT_PLUNDER_BATTLELOG_DATA& stDT_PLUNDER_BATTLELOG_DATA = stPlunderBattleLog.astBattleLogInfo[byIdx];
        CPlunderBattleLog* poBattleLog = CPlunderBattleLogMgr::Instance()->CreateBattleLog();
        if(NULL == poBattleLog)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CreateBattleLog failed!"), MSG_MARK);
            return FALSE;
        }
        m_deqPlunderBattleLog.push_back(poBattleLog);//�����ݷź���
        if(!poBattleLog->Init(&stDT_PLUNDER_BATTLELOG_DATA, m_poOwner, this))
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CPlunderBattleLog init failed!"), MSG_MARK);
            CPlunderBattleLogMgr::Instance()->RemoveBattleLog(poBattleLog);
            return FALSE;
        }
    }

    return TRUE;
}


BOOL CPlunder::InitCapture(const DT_CAPTURE_DATA_LIST& stCaptureData)
{
    UINT8 bySize = stCaptureData.byCaptureNum;
    for(UINT8 byIdx = 0; byIdx < bySize; byIdx++)
    {
        const DT_CAPTURE_DATA& stDT_CAPTURE_DATA = stCaptureData.astCaptureInfo[byIdx];
        CPlunderCapture* poPlunderCaptures = CPlunderCaptureMgr::Instance()->CreatePlunderCapture(m_dwPlayerID, stDT_CAPTURE_DATA.dwCapturePlayerID);
        if(NULL == poPlunderCaptures)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CreatePlunderCapture failed!"), MSG_MARK);
            return FALSE;
        }
        m_mapCapture.AddData(stDT_CAPTURE_DATA.dwCapturePlayerID, poPlunderCaptures);
        if(!poPlunderCaptures->Init(&stDT_CAPTURE_DATA, m_poOwner, this))
        {
            SYS_CRITICAL(_SDT("[%s: %d]: Capture init failed!"), MSG_MARK);
            return FALSE;
        }
        if(m_mapCridCapture.GetData(stDT_CAPTURE_DATA.byCaptureGridIdx))
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CaptureGridIdx[%u] repeat!"), MSG_MARK, stDT_CAPTURE_DATA.byCaptureGridIdx);
            for(UINT8 byIdx = 0; byIdx < 4; byIdx++)
            {
                if(!m_mapCridCapture.GetData(byIdx))
                {
                    m_mapCridCapture.AddData(byIdx, poPlunderCaptures);
                    ((DT_CAPTURE_DATA*)(&stDT_CAPTURE_DATA))->byCaptureGridIdx = byIdx;
                    SYS_CRITICAL(_SDT("[%s: %d]: CaptureGridIdx set [%u]!"), MSG_MARK, byIdx);
                    break;
                }
            }
        }
        else
        {
            m_mapCridCapture.AddData(stDT_CAPTURE_DATA.byCaptureGridIdx, poPlunderCaptures);
        }
    }

    return TRUE;
}

VOID CPlunder::CkCaptureRelease()
{
    //����Ƿ��з�²���ͷ�
    CPlunderCapture* poCapture = m_mapCapture.GetFistData();
    while(NULL != poCapture)
    {
        UINT32 dwCapturePlayerID = poCapture->GetDT_CAPTURE_DATA().dwCapturePlayerID;
        DT_CAPTURE_DATA& stDT_CAPTURE_DATA = poCapture->GetDT_CAPTURE_DATA();
        INT64 dnGap = SDTimeSecs() - stDT_CAPTURE_DATA.qwCaptureTime;
        if((dnGap >= (INT64)m_dwCaptureKeepSecond) || (dnGap < 0))
        {
            UINT32 dwCoin = 0;
            UINT32 dwScience = 0;
            CPlunderMgr::Instance()->GetLeftIncome(m_poOwner, dwCapturePlayerID, dwCoin, dwScience);
            //��¼ս��
            CPlunderMgr::Instance()->AddReleaseBattleLog(m_dwPlayerID, dwCapturePlayerID, EPBLT_AUTOFREE, dwCoin, dwScience);

            USR_INFO( _SDT( "[%s: %d]: PlayerID:%u, CaptureID:%u" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );

            CaptureBefree(dwCapturePlayerID);

            CPlunderCaptureMgr::Instance()->RemovePlunderCapture(m_dwPlayerID, dwCapturePlayerID);
            m_mapCridCapture.DelData(poCapture->GetDT_CAPTURE_DATA().byCaptureGridIdx);
            m_mapCapture.DelData(poCapture->GetDT_CAPTURE_DATA().dwCapturePlayerID);

            CTimerEventMgr::Instance()->DelReleaseCaptureEvent(m_dwPlayerID, dwCapturePlayerID);
            CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(m_poOwner, CPlayerMgr::Instance()->FindPlayer(dwCapturePlayerID), NULL);
        }
        else
        {
            //����¼�
            CTimerEventMgr::Instance()->AddReleaseCaptureEvent(m_dwPlayerID, dwCapturePlayerID, (m_dwCaptureKeepSecond - (UINT32)dnGap));
        }
        poCapture = m_mapCapture.GetNextData();
    }

    UINT32 dwReleaseCountdown = m_dwCaptureKeepSecond - (UINT32)(SDTimeSecs() - m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime);
}


BOOL CPlunder::AddBattleLog(DT_PLUNDER_BATTLELOG_DATA* pstDT_PLUNDER_BATTLELOG_DATA)
{
    //������,�����¼
    if(0 != m_poOwner->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        return TRUE;
    }

    UINT8 bySize = m_deqPlunderBattleLog.size();
    CPlunderBattleLog* poBattleLog = CPlunderBattleLogMgr::Instance()->CreateBattleLog();
    if(NULL == poBattleLog)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CreateBattleLog failed!"), MSG_MARK);
        return FALSE;
    }
    if(!poBattleLog->Init(pstDT_PLUNDER_BATTLELOG_DATA, m_poOwner, this))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CPlunderBattleLog init failed!"), MSG_MARK);
        CPlunderBattleLogMgr::Instance()->RemoveBattleLog(poBattleLog);
        return FALSE;
    }
    //���Ƽ�¼�������ΪMAX_PLUNDER_BATTLELOG_NUM
    //�Ѿ��ﵽ����¼�����������֮ǰ�ļ�¼
    if(bySize >= MAX_PLUNDER_BATTLELOG_NUM)
    {
        CPlunderBattleLog* poOldBattleLog = m_deqPlunderBattleLog.back();
        m_deqPlunderBattleLog.pop_back();
        CPlunderBattleLogMgr::Instance()->RemoveBattleLog(poOldBattleLog);
        m_deqPlunderBattleLog.push_front(poBattleLog);
    }
    //δ�ﵽ��¼�������ޣ�����
    else
    {
        m_deqPlunderBattleLog.push_front(poBattleLog);
    }
    //��������������Ҫ++
    if(m_dwPlayerID != pstDT_PLUNDER_BATTLELOG_DATA->dwActivePlayerID)
    {
        m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum++;
    }
    m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum = m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum > MAX_PLUNDER_BATTLELOG_NUM ? MAX_PLUNDER_BATTLELOG_NUM : m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum;
    //SetSaveState(ESS_WANT_SAVE);

    PKT_CLIGS_PLUNDER_BATTLELOG_NTF stNtf;
    stNtf.byUnreadNum = m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum;
    stNtf.qwPlayerCoin = m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin;
    stNtf.qwPlayerScience = m_poOwner->GetDT_PLAYER_BASE_DATA().qwScience;
    poBattleLog->GetDT_PLUNDER_BATTLELOG_DATA_CLI(stNtf.stBattleLog);
    //�·�ս��֪ͨ
    m_poOwner->SendMsg((CHAR*)(&stNtf), CLIGS_PLUNDER_BATTLELOG_NTF);

    return TRUE;
}

//������ɻص�(�۳�Ԫ��/���ߵ�)
VOID CPlunder::OnPlunderComplete(BOOL bSuccess, PKT_CLIGS_PLUNDER_REQ& stReqRaram)
{
    //�۳��缶����
    if(1 == stReqRaram.byUseItemFlag)
    {
        CGoods* poGoods = m_poOwner->GetBag().GetGoodsItem(m_wPlunderLowerLevelItemID);
        if(NULL == poGoods)
        {
            //�쳣
            SYS_CRITICAL(_SDT("[%s: %d]: poGoods is NULL!"), MSG_MARK);
            return;
        }
        if(poGoods->GetCurPileNum() >= m_wUseItemNum)
        {
            //��־
            //CRecordMgr::Instance()->RecordInfo( m_poOwner->GetID(), ERM_DECITEM, CRecordMgr::EDIT_MAKEGOODS, poGoods->GetItemKindID(), SDTimeToString(SDNow()), poGoods->GetCurPileNum(),
            //	m_poOwner->GetLevel(), m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel, m_wUseItemNum);

            //         poGoods->GetDT_GOODS_DATA().wPileCount -= m_wUseItemNum;

            //�۳�����
            poGoods->DecPileNum(m_wUseItemNum, CRecordMgr::EDIT_MAKEGOODS);
        }
        else
        {
            //�쳣
            SYS_CRITICAL(_SDT("[%s: %d]: wPileCount < m_wUseItemNum!"), MSG_MARK);

            //��־
            //CRecordMgr::Instance()->RecordInfo( m_poOwner->GetID(), ERM_DECITEM, CRecordMgr::EDIT_MAKEGOODS, poGoods->GetItemKindID(), SDTimeToString(SDNow()), poGoods->GetCurPileNum(),
            //	m_poOwner->GetLevel(), m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel, poGoods->GetDT_GOODS_DATA().wPileCount);

            //poGoods->GetDT_GOODS_DATA().wPileCount = 0;

            //�۳�����
            poGoods->DecPileNum(poGoods->GetDT_GOODS_DATA().wPileCount, CRecordMgr::EDIT_MAKEGOODS);
        }

        //poGoods->SetSaveState(ESS_WANT_SAVE);
        if(0 == poGoods->GetDT_GOODS_DATA().wPileCount)
        {
            m_poOwner->OnDeleteItem(poGoods);
        }
    }

    //��������¼�Ӷ����
    if(0 == stReqRaram.byResistFlag)
    {
        m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum++;
        //�۳��շ��Ӷ�Ԫ��
        if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold > m_dwPlunderNeedGold)
        {

            m_poOwner->DecGold(m_dwPlunderNeedGold, CRecordMgr::EDGT_PLUNDER);
        }
        else
        {
            m_poOwner->DecGold( UINT32(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold), CRecordMgr::EDGT_PLUNDER );
        }
    }
    m_stDT_PLUNDER_BASE_DATA.qwLastPlunderTime = SDTimeSecs();

    m_poOwner->AddGuideRecord( EGF_PLUNDER);

    CTaskMgr::Instance()->OnPlunder(m_poOwner);

}

UINT16 CPlunder::CkContiction(CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stPlunderReq)
{
    if(1 == stPlunderReq.byResistFlag)
    {
        return ERR_PLUNDER::ID_SUCCESS;
    }

    UINT16 wErrCode = ERR_PLUNDER::ID_SUCCESS;

    //�鿴����ս����
    if(0 == GetCanPlunderNum())
    {
        return ERR_PLUNDER::ID_REACH_MAX_TIMES;
    }

    //�鿴�Ƿ񳬳��Ӷ᷶Χ
    wErrCode = CkOutPlunderLevelRang(poCapture, stPlunderReq.byUseItemFlag);
    if(ERR_PLUNDER::ID_SUCCESS != wErrCode)
    {
        return wErrCode;
    }

    //����Ƿ�²���� �Ƿ����
    wErrCode = CkIdleCaptureGrid(stPlunderReq.byCaptureGridIdx);
    if(ERR_PLUNDER::ID_SUCCESS != wErrCode)
    {
        return wErrCode;
    }

    //����Ƿ�������ķ�²
    wErrCode = CkYourCapture(poCapture);
    if(ERR_PLUNDER::ID_SUCCESS != wErrCode)
    {
        return wErrCode;
    }

    //����Ƿ��շ��Ӷἰ�㹻Ԫ��
    wErrCode = CkPlunderNeedGold();
    if(ERR_PLUNDER::ID_SUCCESS != wErrCode)
    {
        return wErrCode;
    }

    //����Ƿ��Ӷ᷽ʽ����
    wErrCode = CkPlunderType(poEnemy, poCapture);
    if(ERR_PLUNDER::ID_SUCCESS != wErrCode)
    {
        return wErrCode;
    }

    return wErrCode;
}

VOID CPlunder::SetReqParam(UINT32 dwPlayerID, PKT_CLIGS_PLUNDER_REQ& stPlunderReq)
{
    m_mapPlunderReq[dwPlayerID] = stPlunderReq;
}

PKT_CLIGS_PLUNDER_REQ& CPlunder::GetReqParam(UINT32 dwPlayerID)
{
    return m_mapPlunderReq[dwPlayerID]; //û���򷵻�Ĭ�Ͻṹ
}

VOID CPlunder::GetShowPlunderBattleLog(UINT8& byShowNum, DT_PLUNDER_BATTLELOG_DATA_CLI astPlunderBattleLogInfo[MAX_PLUNDER_BATTLELOG_NUM])
{
    byShowNum = 0;
    UINT8 bySize = m_deqPlunderBattleLog.size();
    if(0 == bySize)
    {
        return;
    }
    for(CPlunderBattleLogDeqItr itr = m_deqPlunderBattleLog.begin(); ((itr != m_deqPlunderBattleLog.end()) && (byShowNum < MAX_PLUNDER_BATTLELOG_NUM)) ; itr++)
    {
        CPlunderBattleLog* poBattleLog = *itr;
        if(poBattleLog)
        {
            poBattleLog->GetDT_PLUNDER_BATTLELOG_DATA_CLI(astPlunderBattleLogInfo[byShowNum++]);
            poBattleLog->GetDT_PLUNDER_BATTLELOG_DATA().byNewFlag = 0;//��Ϊ����ս��, Ŀǰû���õ�
        }

    }

    if( m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum > 0)
    {
        m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum = 0;
        CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(m_poOwner);
    }
}


UINT16 CPlunder::GetCanPlunderNum()
{
    UINT16 wPlunderMaxTimesPerDay = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    //�ж��Ӷ����
    //����
    if(IsToday(m_stDT_PLUNDER_BASE_DATA.qwLastPlunderTime))
    {
        if(m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum >= wPlunderMaxTimesPerDay)
        {
            return 0;
        }
    }
    //����û��ս
    else
    {
        //�����Ӷ����
        m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum = 0;
    }

    return wPlunderMaxTimesPerDay < m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum ? 0 : (wPlunderMaxTimesPerDay - m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum);
}


UINT16	CPlunder::GetFreePlunderNum()
{
    SPlunderBaseProp& stPlunderBaseProp = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp();
    UINT16 wPlunderFreeTimesPerDay = stPlunderBaseProp.wPlunderFreeTimesPerDay;
    UINT16 wPlunderMaxTimesPerDay = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    UINT16 wChargeTimesPerDay = wPlunderMaxTimesPerDay - wPlunderFreeTimesPerDay;
    UINT16 wCanPlunderNum = GetCanPlunderNum();
    UINT16 wFreePlunderNum = 0;
    if(wCanPlunderNum > wChargeTimesPerDay)
    {
        wFreePlunderNum = wCanPlunderNum - wChargeTimesPerDay;
    }
    else
    {
        //��һ���Ӷ��շ�Ԫ��
        wFreePlunderNum = 0;
    }
    return wFreePlunderNum;
}

//�ͷ��п��и���
BOOL CPlunder::HaveIdleGrid()
{
    if(m_mapCapture.Size() < CPlunderGridPropMgr::Instance()->GetUnlockNum(m_poOwner->GetLevel()))
    {
        return TRUE;
    }

    return FALSE;
}

set<UINT32> CPlunder::GetEnemySet()
{
    set<UINT32> setEnemyID;
    vector<CEnemy *> vecEnemy = m_poOwner->GetEnemyList();
    for( UINT32 dwIndex = 0; dwIndex < vecEnemy.size(); ++dwIndex )
    {
        setEnemyID.insert( vecEnemy[dwIndex]->GetDT_ENEMY_DATA().dwEnemyPlayerID );
    }

    return setEnemyID;
}

//����Ƿ񳬳��Ӷ᷶Χ��byUseItemFlagΪ�Ƿ�ʹ�õ����Ӷ����5�����ϵ����
UINT16 CPlunder::CkOutPlunderLevelRang(CPlayer* poEnemy, UINT8 byUseItemFlag)
{
    if(NULL == poEnemy)
    {
        RETURN_OTHER_ERR;
    }
    //todo,��Ҫ���߼��������ã�
    m_wUseItemNum = 0;
    //�Ӷ�����˲���缶�Ӷ��
    if(ERFK_PLUNDER == poEnemy->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        return ERR_PLUNDER::ID_SUCCESS;
    }

    INT16 shGap = m_poOwner->GetLevel() - poEnemy->GetLevel();
    if(shGap <= 5)
    {
        return ERR_PLUNDER::ID_SUCCESS;
    }
    //>5�����ϣ����õ��ߣ����Ӷᳬ����Χ
    if(0 == byUseItemFlag)
    {
        return ERR_PLUNDER::ID_OUT_PLUNDER_RANG;
    }

    //��Ҫ����
    //5��1��
    m_wUseItemNum = ((shGap - 6) / 5) + 1;
    CGoods* poGoods = m_poOwner->GetBag().GetGoodsItem(m_wPlunderLowerLevelItemID);
    if(NULL == poGoods)
    {
        return ERR_PLUNDER::ID_ITEM_NOT_ENOUGH;
    }
    if(poGoods->GetCurPileNum() < m_wUseItemNum)
    {
        return ERR_PLUNDER::ID_ITEM_NOT_ENOUGH;
    }

    return ERR_PLUNDER::ID_SUCCESS;
}

//����Ƿ��п��з�²����
UINT16 CPlunder::CkIdleCaptureGrid(UINT8 byCaptureGridIdx)
{
    if(NULL != m_mapCridCapture.GetData(byCaptureGridIdx))
    {
        return ERR_PLUNDER::ID_GRID_NOT_IDLE;
    }

    //���Ӵ�0��ʼ
    if((byCaptureGridIdx + 1) > CPlunderGridPropMgr::Instance()->GetUnlockNum(m_poOwner->GetLevel()))
    {
        return ERR_PLUNDER::ID_GRID_NOT_UNLOCK;
    }

    return ERR_PLUNDER::ID_SUCCESS;
}


//����շ��Ӷ�Ԫ���Ƿ��㹻
UINT16 CPlunder::CkPlunderNeedGold()
{
    m_dwPlunderNeedGold = 0;
    SPlunderBaseProp& stPlunderBaseProp = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp();

    //��ҿ��Ӷ�Ĵ���
    UINT16	wPlunderMaxTimesPerDay = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);

    if(m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum >= wPlunderMaxTimesPerDay )
    {
        return ERR_PLUNDER::ID_REACH_MAX_TIMES;
    }

    if(m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum < stPlunderBaseProp.wPlunderFreeTimesPerDay)
    {
        return ERR_PLUNDER::ID_SUCCESS;
    }

    UINT16 wNum = m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum - stPlunderBaseProp.wPlunderFreeTimesPerDay;
    m_dwPlunderNeedGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_PLUNDERBUYNUM, m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum);

    if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold < m_dwPlunderNeedGold)
    {
        return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
    }

    return ERR_PLUNDER::ID_SUCCESS;
}


//���ץ�������Ƿ���ȷ
UINT16 CPlunder::CkPlunderType(CPlayer* poEnemy, CPlayer* poCapture)
{
    if(poEnemy == poCapture)
    {
        CPlunder* poPlunder = poEnemy->GetPlunder();
        if(poPlunder)
        {
            if(0 != poPlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID) //�ѱ���²������Ӧ���������²������ͬʱ����������Ӷᵼ��
            {
                return ERR_PLUNDER::ID_HAVE_BECAPTURE;
            }
        }
        else
        {
            return ERR_PLUNDER::ID_ENEMY_UNLOCK;
        }
    }

    return ERR_PLUNDER::ID_SUCCESS;
}

//����Ƿ�������ķ�²
UINT16 CPlunder::CkYourCapture(CPlayer* poEnemy)
{
    if(NULL != m_mapCapture.GetData(poEnemy->GetDT_PLAYER_BASE_DATA().dwID))
    {
        /*
        if(poCapture->CkNeedRelease())
        {
        	DelCapture(dwCapturePlayerID);
        }
        else
        {
        	return ERR_PLUNDER::ID_YOUR_CAPTURE;
        }
        */
        return ERR_PLUNDER::ID_YOUR_CAPTURE;
    }

    return ERR_PLUNDER::ID_SUCCESS;
}

UINT16 CPlunder::OpenCaptureTab(DT_BECAPTURE_DATA& stOwner, UINT16& wPlunderNumPerDay, UINT16& wCanPlunderNum, UINT16& wVipExtNum, UINT16& wFreePlunderNum, UINT8& byCaptureNum, UINT32 &dwPlunderGold,
                                DT_CAPTURE_DATA_CLI astCaptureInfo[MAX_CAPTURE_NUM], UINT16 awUnlockGridLevel[MAX_CAPTURE_NUM], UINT8& byUnreadPlunderBattleLogNum,
                                DT_PLUNDER_BATTLELOG_DATA_CLI& stLastBattleLog, DT_PLUNDER_GRID_DATA astCaptureGridInfo[MAX_CAPTURE_NUM])
{
    GetBeCaptureInfo(stOwner);
    wPlunderNumPerDay = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);

    wCanPlunderNum = GetCanPlunderNum();
    wVipExtNum = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    wFreePlunderNum = GetFreePlunderNum();
    dwPlunderGold = GetPlunderGold();
    GetCapture(byCaptureNum, astCaptureInfo);

    CPlunderGridPropMgr::Instance()->GetUnlockGridLevel(awUnlockGridLevel);

    byUnreadPlunderBattleLogNum = m_stDT_PLUNDER_BASE_DATA.byUnreadBattleLogNum;

    if(m_deqPlunderBattleLog.size() > 0)
    {
        CPlunderBattleLog* poLog = m_deqPlunderBattleLog.front();
        if(poLog)
        {
            poLog->GetDT_PLUNDER_BATTLELOG_DATA_CLI(stLastBattleLog);
        }
    }

    memcpy(astCaptureGridInfo, &m_stDT_PLUNDER_BASE_DATA.astCaptureGridInfo, sizeof(m_stDT_PLUNDER_BASE_DATA.astCaptureGridInfo));

    return ERR_OPEN_CAPTURE_TAB::ID_SUCCESS;
}


VOID CPlunder::CkBeRelease()
{
    //SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(m_poOwner->GetID());
    //if(NULL == pstPlayerBaseData)
    //{
    //	//�쳣,ֻ����reset����ʱ�Żᷢ��������
    //	USR_INFO( _SDT( "[%s: %d]: PlayerID:%u Not Found BaseDataCache " ), MSG_MARK, m_poOwner->GetID());
    //	return ;
    //}

    //@2013-04-26���÷�²��ID��Ӧ���Ի��������Ϊ׼�����ݿ�����ݲ��ٿ��š�
    //m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID = pstPlayerBaseData->dwCaptureOwner;
    if(0 == m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID)
    {
        return;
    }
    //@2013-04-26 end

    UINT32 dwPassTime = (UINT32)(SDTimeSecs() - m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime);
    if(dwPassTime >= m_dwCaptureKeepSecond)
    {
        CPlunderMgr::Instance()->OnReleaseCaptureEvent(m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID, m_dwPlayerID);
        CTimerEventMgr::Instance()->DelReleaseCaptureEvent(m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID, m_dwPlayerID);
    }
    else
    {
        CTimerEventMgr::Instance()->AddReleaseCaptureEvent(m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID, m_dwPlayerID, m_dwCaptureKeepSecond - dwPassTime);
    }
}

VOID CPlunder::GetBeCaptureInfo(DT_BECAPTURE_DATA& stBeCaptureInfo)
{
    //�����Ӷ�Ļ����˲���¼��²�����ɱ������Ӷ�
    if(ERFK_PLUNDER == m_poOwner->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        stBeCaptureInfo.dwOwnerID = 0;
    }

    //���ⶨʱ����׼ȷ
    CkBeRelease();

    if(0 != m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID)
    {
        stBeCaptureInfo.dwOwnerID = m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID;
        const SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID);
        if(pstPlayerBaseData)
        {
            SDStrcpy(stBeCaptureInfo.aszOwnerDispName, pstPlayerBaseData->aszDispName);
            stBeCaptureInfo.wOwnerLevel = pstPlayerBaseData->wLevel;
            stBeCaptureInfo.dwOwnerPower = pstPlayerBaseData->dwPower;
            //stBeCaptureInfo.dwReleaseCountdown = m_dwCaptureKeepSecond - (UINT32)(SDTimeSecs() - m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime);//CkBeRelease�Ѽ������ε��ù���Ӧ�ò��ỻ�룬����0

            // 2013-02-25 �޸�ʱ����ܴ���쳣���⣬����ū��û���ͷţ�ʱ�䳬�ڣ���ʱ��û�м�⴦��
            UINT64 qwBetwenTime = SDTimeSecs() - m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime;
            if (m_dwCaptureKeepSecond > qwBetwenTime)
            {
                stBeCaptureInfo.dwReleaseCountdown = m_dwCaptureKeepSecond - (UINT32)qwBetwenTime;
            }
            else
            {
                stBeCaptureInfo.dwOwnerID = 0;
                stBeCaptureInfo.dwReleaseCountdown = 0;
                m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID = 0;
                m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime = SDTimeSecs() - m_dwCaptureKeepSecond;
            }
            // end
        }
        else
        {
            stBeCaptureInfo.dwOwnerID = 0;
        }
    }
    else
    {
        stBeCaptureInfo.dwOwnerID = 0;
    }

}


//��ӷ�²��
BOOL CPlunder::AddCapture(UINT32 dwCapturePlayerID, UINT8 byGridIdx)
{
    if(m_mapCapture.GetData(dwCapturePlayerID))
    {
        return TRUE;
    }

    DT_CAPTURE_DATA stDT_CAPTURE_DATA;
    memset(&stDT_CAPTURE_DATA, 0, sizeof(DT_CAPTURE_DATA));
    stDT_CAPTURE_DATA.dwCapturePlayerID = dwCapturePlayerID;
    stDT_CAPTURE_DATA.qwCaptureTime = SDTimeSecs();
    stDT_CAPTURE_DATA.qwLastCollectTime = SDTimeSecs();
    stDT_CAPTURE_DATA.byCaptureGridIdx = byGridIdx;
    stDT_CAPTURE_DATA.byIncomeType = EPWT_COIN ;// Ĭ��ͭǮ��δ���þ���ͭǮ
    CPlunderCapture* poPlunderCapture = CPlunderCaptureMgr::Instance()->CreatePlunderCapture(m_dwPlayerID, dwCapturePlayerID);
    if(NULL == poPlunderCapture)
    {
        return FALSE;
    }
    if(!poPlunderCapture->Init(&stDT_CAPTURE_DATA, m_poOwner, this))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: capture init failed!"), MSG_MARK);
        return FALSE;
    }

    USR_INFO(_SDT("[%s: %d]: player id :%u, capture id:%u!"), MSG_MARK, m_dwPlayerID, dwCapturePlayerID);

    m_mapCapture.AddData(dwCapturePlayerID, poPlunderCapture);
    m_mapCridCapture.AddData(byGridIdx, poPlunderCapture);

    CTimerEventMgr::Instance()->AddReleaseCaptureEvent(m_dwPlayerID, dwCapturePlayerID, m_dwCaptureKeepSecond);

    return TRUE;
}

//�ͷŷ�²,�ͷŶ��󼰹���
BOOL CPlunder::DelCapture(UINT32 dwCapturePlayerID)
{
    CPlunderCapture* poCapture = m_mapCapture.GetData(dwCapturePlayerID);
    if(NULL == poCapture)
    {
        USR_INFO(_SDT("[%s: %d]: capture not exist!, CapturePlayerID:%u"), MSG_MARK, dwCapturePlayerID);

        CPlayer *poCapturePlayer = CPlayerMgr::Instance()->FindPlayer(dwCapturePlayerID);
        if (NULL == poCapturePlayer)
        {
            const SPlayerBaseData* poBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwCapturePlayerID);
            if((poBaseData) && (poBaseData->dwCaptureOwner == m_dwPlayerID))
            {
                USR_INFO( _SDT( "[%s: %d]: capture[%u] not exist, but owner is my[%u]"), MSG_MARK, dwCapturePlayerID, m_dwPlayerID);
                CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCapturePlayerID, 0);
            }
            return FALSE;
        }
        //�쳣��������²�������Լ������ͷ�
        CPlunder* poCapturePlunder = poCapturePlayer->GetPlunder();
        if(poCapturePlunder)
        {
            if(poCapturePlunder->GetDT_PLUNDER_BASE_DATA().dwCaptureOwnerPlayerID == m_dwPlayerID)
            {
                USR_INFO( _SDT( "[%s: %d]: capture[%u] not exist, but owner is my[%u]"), MSG_MARK, dwCapturePlayerID, m_dwPlayerID);
                poCapturePlunder->OnFree();
            }
        }
        else
        {
            const SPlayerBaseData* poBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(dwCapturePlayerID);
            if((poBaseData) && (poBaseData->dwCaptureOwner == m_dwPlayerID))
            {
                USR_INFO( _SDT( "[%s: %d]: capture[%u] not exist, but owner is my[%u]"), MSG_MARK, dwCapturePlayerID, m_dwPlayerID);
                CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCapturePlayerID, 0);
            }
        }

        //�쳣��֮ǰ�Ӷ��Ѿ����ж�
        return FALSE;
    }

    USR_INFO( _SDT( "[%s: %d]:PlayerID:%u, delete capture:%u *****************" ), MSG_MARK, m_dwPlayerID, dwCapturePlayerID );

    CaptureBefree(dwCapturePlayerID);

    m_mapCridCapture.DelData(poCapture->GetDT_CAPTURE_DATA().byCaptureGridIdx);
    m_mapCapture.DelData(dwCapturePlayerID);
    CPlunderCaptureMgr::Instance()->RemovePlunderCapture(m_dwPlayerID, dwCapturePlayerID);
    if( !CTimerEventMgr::Instance()->DelReleaseCaptureEvent(m_dwPlayerID, dwCapturePlayerID) )
    {
        USR_INFO( _SDT( "[%s:%d] CTimerEventMgr::Instance()->DelReleaseCaptureEventʧ�ܣ�m_dwPlayerID=%d, dwCapturePlayerID=%d" ),
                  MSG_MARK, m_dwPlayerID, dwCapturePlayerID );
    }

    return TRUE;
}


//��²���ͷ�
VOID CPlunder::CaptureBefree(UINT32 dwCapturePlayerID)
{
    //ɾ����²
    USR_INFO( _SDT( "[%s: %d]:PlayerID:%u delete capture ID:%u " ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );

    //�����Ӷ�Ļ����˲���¼��²�����ɱ������Ӷ�
    if(ERFK_PLUNDER == m_poOwner->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        USR_INFO( _SDT( "[%s: %d]:PlayerID:%u delete capture ID:%u, Robot" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );
        return;
    }

    CPlayer *poCapturePlayer = CPlayerMgr::Instance()->FindPlayer(dwCapturePlayerID);
    if (NULL == poCapturePlayer)
    {
        CGetPlayerDataMgr::Instance()->GetPlayerData(dwCapturePlayerID, GET_PLAYERDATATYPE_SYNCDATA, dwCapturePlayerID);
        CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCapturePlayerID, 0);
        USR_INFO( _SDT( "[%s: %d] PlayerID:%u delete capture ID:%u, OK, RSYNC" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );
        return;
    }

    //��²�Ļص�Free
    CPlunder* poCapturePlunder = poCapturePlayer->GetPlunder();
    if(poCapturePlunder)
    {
        poCapturePlunder->OnFree();
        USR_INFO( _SDT( "[%s: %d] PlayerID:%u delete capture ID:%u OK" ), MSG_MARK , m_poOwner->GetID(), dwCapturePlayerID );
    }
    //��²�����ڴ��У���ȥDBȡ����ͬ��
    else
    {
        CGetPlayerDataMgr::Instance()->GetPlayerData(dwCapturePlayerID, GET_PLAYERDATATYPE_SYNCDATA, dwCapturePlayerID);
        CPlayerBaseDataCacheMgr::Instance()->OnCapture(dwCapturePlayerID, 0);
        USR_INFO( _SDT( "[%s: %d] PlayerID:%u delete capture ID:%u, OK, RSYNC" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );
    }

}

//���Ƿ�²�������ʱ�ص�
BOOL CPlunder::OnFree()
{
    m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID = 0;
    m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime = 0;

    CPlayerBaseDataCacheMgr::Instance()->OnCapture(m_dwPlayerID, 0);
    return TRUE;
}

//�Լ�����²ʱ�ص�
BOOL CPlunder::OnCapture(UINT32 dwPlayerID)
{
    //�����Ӷ�Ļ����˲���¼��²�����ɱ������Ӷ�
    if(ERFK_PLUNDER == m_poOwner->GetDT_PLAYER_BASE_DATA().byRobotFunc)
    {
        return TRUE;
    }

    m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID = dwPlayerID;
    m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime = SDTimeSecs();

    return TRUE;
}

CPlunderCapture* CPlunder::GetCapture(UINT32 dwCapturePlayerID)
{
    return m_mapCapture.GetData(dwCapturePlayerID);
}

//��ȡ��²��Ϣ���ͻ���
VOID CPlunder::GetCapture(UINT8& byCaptureNum, DT_CAPTURE_DATA_CLI astCaptureInfo[MAX_CAPTURE_NUM])
{
    byCaptureNum = 0;

    USR_INFO( _SDT( "[%s: %d]:PlayerID:%u, GetCapture Info" ), MSG_MARK, m_poOwner->GetID() );

    //���ⶨʱ����׼ȷ
    CkCaptureRelease();

    //����ͷ�
    CPlunderCapture* poCapture = m_mapCapture.GetFistData();
    while(poCapture)
    {
        poCapture->GetDT_CAPTURE_DATA_CLI(astCaptureInfo[byCaptureNum]);
        byCaptureNum++;
        poCapture = m_mapCapture.GetNextData();
    }
}

VOID CPlunder::GetCapture(UINT32 dwCaptureID, DT_CAPTURE_DATA_CLI& stCaptureInfo)
{
    CPlunderCapture* poCapture = GetCapture(dwCaptureID);
    if(poCapture)
    {
        poCapture->GetDT_CAPTURE_DATA_CLI(stCaptureInfo);
    }
}


//�ͷŷ�²
UINT16 CPlunder::FreeCapture(UINT32 dwCapturePlayerID, UINT32& dwCoinIncome, UINT32& dwScienceIncome)
{
    CPlunderCapture* poPlunderCapture = GetCapture(dwCapturePlayerID);
    if(NULL == poPlunderCapture)
    {
        return ERR_FREE_CAPTURE::ID_SUCCESS;
    }

    CPlunderMgr::Instance()->GetLeftIncome(m_poOwner, dwCapturePlayerID, dwCoinIncome, dwScienceIncome, TRUE);
    CPlunderMgr::Instance()->AddReleaseBattleLog(m_dwPlayerID, dwCapturePlayerID, EPBLT_MANUALFREE, dwCoinIncome, dwScienceIncome);
    //�ͷŷ�²

    USR_INFO( _SDT( "[%s: %d]:PlayerID:%u, delete capture ID:%u" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );

    DelCapture(dwCapturePlayerID);
    CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(m_poOwner, CPlayerMgr::Instance()->FindPlayer(dwCapturePlayerID));

    //CTaskMgr::Instance()->OnFreeCapture(m_poOwner);

    return ERR_FREE_CAPTURE::ID_SUCCESS;
}

UINT16 CPlunder::DriveAway(UINT32& dwDriveAwayGold)
{
    UINT32 dwCaptureOwnerPlayerID = m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID;
    if(0 == dwCaptureOwnerPlayerID)
    {
        return ERR_DRIVE_AWAY_OWNER::ID_OWNER_NOT_EXIST;
    }
    dwDriveAwayGold = GetDriveAwayGold();
    if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold < dwDriveAwayGold)
    {
        return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
    }

    USR_INFO( _SDT( "[%s: %d]:DriveAway PlayerID:%d CaptureOwnerID:%d" ), MSG_MARK, m_dwPlayerID, dwCaptureOwnerPlayerID );
    //

    CPlayer *poCapturePlayer = CPlayerMgr::Instance()->FindPlayer(dwCaptureOwnerPlayerID);
    if (NULL == poCapturePlayer)
    {
        RETURN_OTHER_ERR;
    }

    CPlunder* poOwnerPlunder = poCapturePlayer->GetPlunder();
    if(NULL == poOwnerPlunder)
    {
        RETURN_OTHER_ERR;
    }
    else
    {
        USR_INFO( _SDT( "[%s: %d]:PlayerIDID:%u, Delete capture ID:%u *****************" ), MSG_MARK, m_poOwner->GetID(), m_dwPlayerID );
        poOwnerPlunder->DelCapture(m_dwPlayerID);
    }


    //m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold -= dwCostGold;
    m_poOwner->DecGold(dwDriveAwayGold, CRecordMgr::EDGT_DRIVEAWAY);

    m_stDT_PLUNDER_BASE_DATA.wLastDriveAwayNum++;
    m_stDT_PLUNDER_BASE_DATA.qwLastDriveAwayTime = SDTimeSecs();

    UINT32 dwCoin = 0;
    UINT32 dwScience = 0;
    CPlunderMgr::Instance()->GetLeftIncome(CPlayerMgr::Instance()->FindPlayer(dwCaptureOwnerPlayerID), m_dwPlayerID, dwCoin, dwScience, TRUE);
    CPlunderMgr::Instance()->AddReleaseBattleLog(dwCaptureOwnerPlayerID, m_dwPlayerID, EPBLT_DRIVEAWAY, dwCoin, dwScience);
    CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(CPlayerMgr::Instance()->FindPlayer(dwCaptureOwnerPlayerID), CPlayerMgr::Instance()->FindPlayer(m_dwPlayerID));

    return ERR_DRIVE_AWAY_OWNER::ID_SUCCESS;
}

//��ȡ�Ӷ���Ϣ
VOID CPlunder::GetPlunderData(UINT16& wCanPlunderNum, UINT16& wFreePlunderNum, UINT32& dwPlunderGold, UINT16& wPlunderItemNum, UINT32& dwCaptureOwnerPlayerID)
{
    //������չ������Ҫ��
    //m_stDT_PLUNDER_BASE_DATA.wExtPlunderNum //

    SPlunderBaseProp& stPlunderBaseProp = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp();
    UINT16 wPlunderFreeTimesPerDay = stPlunderBaseProp.wPlunderFreeTimesPerDay;
    UINT16 wPlunderMaxTimesPerDay = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    UINT16 wChargeTimesPerDay = wPlunderMaxTimesPerDay - wPlunderFreeTimesPerDay;
    wCanPlunderNum = GetCanPlunderNum();
    if(wCanPlunderNum > wChargeTimesPerDay)
    {
        wFreePlunderNum = wCanPlunderNum - wChargeTimesPerDay;
    }
    else
    {
        //��һ���Ӷ��շ�Ԫ��
        wFreePlunderNum = 0;
        dwPlunderGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_PLUNDERBUYNUM, m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum);
        //dwPlunderGold = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp().dwPlunderBaseGold + (wChargeTimesPerDay - wCanPlunderNum) * stPlunderBaseProp.dwPlunderIncGold;
        //dwPlunderGold = dwPlunderGold > stPlunderBaseProp.dwPlunderMaxGold ? stPlunderBaseProp.dwPlunderMaxGold : dwPlunderGold;
    }
    //�ж��Ƿ����Խ���Ӷ����
    CGoods* poGoods = m_poOwner->GetBag().GetGoodsItem(m_wPlunderLowerLevelItemID);
    if(NULL == poGoods)
    {
        wPlunderItemNum = 0;
    }
    else
    {
        wPlunderItemNum = poGoods->GetCurPileNum();
    }

    //���Լ�����²�������ͷ����ͷ�(��Ϊ��²������û��¼��û�д����ͷŷ�²)
    //CkBeRelease();

    dwCaptureOwnerPlayerID = m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID;
}

/*
VOID CPlunder::CkBeRelease()
{
	if(0 == m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID)
	{
		return;
	}

	//���ʱ�䵽���Զ��ͷ�(��Ϊ��²������û��¼��û�д����ͷŷ�²)
	INT64 dnGap = SDTimeSecs() - m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime;
	if(dnGap > (INT64)m_dwCaptureKeepSecond)//
	{
		//�����²��,��Ӧ�ķ�²���ķ�²����������Լ�ͨ����ͬ��qwBeCaptureTime�жϣ����Ӧ��һ�����ͷŷ�²
		m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID = 0;
		m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime = 0;
		CPlayerBaseDataCacheMgr::Instance()->OnCapture(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, 0);
		return ;
	}

	//��鱻��²�������ͷ�,��ֹ�������ͷ�ʱû�����µ��ڴ���ʱGS����û���浽
	CPlunder* poOwnerPlunder = CPlunderMgr::Instance()->FindPlunder(m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID);
	if(poOwnerPlunder) //
	{
		//�Ѿ�����²�������ͷ�
		if(NULL == poOwnerPlunder->GetCapture(m_dwPlayerID))
		{
			m_stDT_PLUNDER_BASE_DATA.dwCaptureOwnerPlayerID = 0;
			m_stDT_PLUNDER_BASE_DATA.qwBeCaptureTime = 0;
			CPlayerBaseDataCacheMgr::Instance()->OnCapture(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, 0);
			return ;
		}
	}
	else
	{
		//�������ȥDBȡ����,��²���ͷŷ�²ʱ��ص�
	}
}
*/


UINT16 CPlunder::CollectIncome(UINT32 dwCapturePlayerID, UINT32& dwIncomeValue, DT_CAPTURE_WORK_DATA_CLI& stWorkInfo, UINT8& byCaptureReleaseFlag, UINT8 &byHalved)
{
    CPlunderCapture* poCapture = GetCapture(dwCapturePlayerID);
    if(NULL == poCapture)
    {
        return ERR_COLLECT_INCOME::ID_CAPTURE_NOT_EXIST;
    }
    UINT16 wErrCode = poCapture->CollectIncome(dwIncomeValue, stWorkInfo, byHalved);
    if(ERR_COLLECT_INCOME::ID_SUCCESS == wErrCode)
    {
        //�ж��Ƿ����ͷŷ�²
        if(0 == stWorkInfo.dwAllCollectIncome)
        {
            byCaptureReleaseFlag = 1;
            USR_INFO( _SDT( "[%s: %d]:PlayerID:%u, Delete CaptureID:%u" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );
            DelCapture(dwCapturePlayerID);

            //��¼ս��
            CPlunderMgr::Instance()->AddReleaseBattleLog(m_dwPlayerID, dwCapturePlayerID, EPBLT_INCOME, 0, 0);
            CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(CPlayerMgr::Instance()->FindPlayer(dwCapturePlayerID), CPlayerMgr::Instance()->FindPlayer(m_dwPlayerID));
        }
        else
        {
            CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(CPlayerMgr::Instance()->FindPlayer(m_dwPlayerID));
        }
    }

    return wErrCode;
}

UINT16 CPlunder::BleedCapture(UINT32 dwCapturePlayerID, UINT8& byIncomeType, UINT32& dwIncomeValue)
{
    CPlunderCapture* poCapture = GetCapture(dwCapturePlayerID);
    if(NULL == poCapture)
    {
        return ERR_COLLECT_INCOME::ID_CAPTURE_NOT_EXIST;
    }
    UINT16 wErrCode = poCapture->BleedCapture(byIncomeType, dwIncomeValue);
    if(ERR_COLLECT_INCOME::ID_SUCCESS == wErrCode)
    {
        USR_INFO( _SDT( "[%s: %d]:PlayerID:%u, Delete CaptureID:%u" ), MSG_MARK, m_poOwner->GetID(), dwCapturePlayerID );

        DelCapture(dwCapturePlayerID);

        //��¼ս��
        CPlunderMgr::Instance()->AddReleaseBattleLog(m_dwPlayerID, dwCapturePlayerID, EPBLT_BLEED, 0, 0);
        CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(CPlayerMgr::Instance()->FindPlayer(dwCapturePlayerID), CPlayerMgr::Instance()->FindPlayer(m_dwPlayerID));
        //CTaskMgr::Instance()->OnBleedCapture(m_poOwner);
    }
    return wErrCode;
}

UINT16 CPlunder::SetWorkType(UINT32 dwCapturePlayerID, UINT8 byIncomeType, DT_CAPTURE_WORK_DATA_CLI& stWorkInfo)
{
    CPlunderCapture* poCapture = GetCapture(dwCapturePlayerID);
    if(NULL == poCapture)
    {
        return ERR_SET_WORK_TYPE::ID_CAPTURE_NOT_EXIST;
    }

    CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(m_poOwner);
    return poCapture->SetWorkType(byIncomeType, stWorkInfo);
}


UINT32 CPlunder::GetDriveAwayGold()
{
    //�ж�ʱ��
    //�����Ѿ��ջ��
    if(!IsToday(m_stDT_PLUNDER_BASE_DATA.qwLastDriveAwayTime))
    {
        m_stDT_PLUNDER_BASE_DATA.wLastDriveAwayNum = 0;
    }
    return CLuamgr::Instance()->GetFuncCost( m_poOwner, EGCF_PLUNDERDRIVEAWAY, m_stDT_PLUNDER_BASE_DATA.wLastDriveAwayNum );
}


UINT16 CPlunder::RecvLeftIncome(UINT8 byGridIdx, UINT8& byIncomeType, UINT32& dwIncomeValue)
{
    if(byGridIdx >= MAX_CAPTURE_NUM)
    {
        return ERR_RECV_LEFT_INCOME::ID_GRID_INVALID;
    }

    DT_PLUNDER_GRID_DATA& stDT_PLUNDER_GRID_DATA = m_stDT_PLUNDER_BASE_DATA.astCaptureGridInfo[byGridIdx];
    if((EPWT_UNSET == stDT_PLUNDER_GRID_DATA.byIncomeType) || (0 == stDT_PLUNDER_GRID_DATA.dwIncomeValue))
    {
        return ERR_RECV_LEFT_INCOME::ID_NO_INCOME;
    }

    switch(stDT_PLUNDER_GRID_DATA.byIncomeType)
    {
    case EPWT_COIN:
    {
        //m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin += stDT_PLUNDER_GRID_DATA.dwIncomeValue;
        m_poOwner->AddCoin(stDT_PLUNDER_GRID_DATA.dwIncomeValue, CRecordMgr::EACT_PLUNDER);
    }
    break;
    case EPWT_SCIENCE:
    {
        //m_poOwner->GetDT_PLAYER_BASE_DATA().qwScience += stDT_PLUNDER_GRID_DATA.dwIncomeValue;
        m_poOwner->AddScience(stDT_PLUNDER_GRID_DATA.dwIncomeValue, CRecordMgr::EAST_PLUNDER);
    }
    break;
    default:
        return ERR_RECV_LEFT_INCOME::ID_NO_INCOME;
        break;
    }

    byIncomeType = stDT_PLUNDER_GRID_DATA.byIncomeType;
    dwIncomeValue = stDT_PLUNDER_GRID_DATA.dwIncomeValue;

    stDT_PLUNDER_GRID_DATA.byIncomeType = EPWT_UNSET;
    stDT_PLUNDER_GRID_DATA.dwIncomeValue = 0;

    CPlayerSaveMgr::Instance()->AddPlayerPlunderSaveData(m_poOwner);

    return ERR_RECV_LEFT_INCOME::ID_SUCCESS;
}

//��ȡ�Ӷ���Ϣ
UINT32 CPlunder::GetPlunderGold()
{
    //������չ������Ҫ��
    UINT32 dwPlunderGold = 0;
    UINT16 wCanPlunderNum = 0;
    SPlunderBaseProp& stPlunderBaseProp = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp();
    UINT16 wPlunderFreeTimesPerDay = stPlunderBaseProp.wPlunderFreeTimesPerDay;
    UINT16 wPlunderMaxTimesPerDay = CVipPropMgr::Instance()->GetIncNum(EVINF_PLUNDERBUYNUM, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel);
    UINT16 wChargeTimesPerDay = wPlunderMaxTimesPerDay - wPlunderFreeTimesPerDay;
    wCanPlunderNum = GetCanPlunderNum();
    if(wCanPlunderNum > wChargeTimesPerDay)
    {
        dwPlunderGold = 0;
    }
    else
    {
        dwPlunderGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_PLUNDERBUYNUM, m_stDT_PLUNDER_BASE_DATA.wLastPlunderNum);
        //dwPlunderGold = CPlunderBasePropMgr::Instance()->GetPlunderBaseProp().dwPlunderBaseGold + (wChargeTimesPerDay - wCanPlunderNum) * stPlunderBaseProp.dwPlunderIncGold;
        //dwPlunderGold = dwPlunderGold > stPlunderBaseProp.dwPlunderMaxGold ? stPlunderBaseProp.dwPlunderMaxGold : dwPlunderGold;
    }
    return dwPlunderGold;
}

