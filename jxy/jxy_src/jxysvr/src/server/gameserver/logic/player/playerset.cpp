#include "player.h"
#include "logic/vip/vippropmgr.h"
#include "logic/record/recordmgr.h"
#include "playersavemgr.h"
#include <stdlib.h>
#include <net/db/dbpktbuilder.h>
#include <net/cli/user.h>
#include <framework/gsapi.h>
#include <logic/awaken/awaken.h>
#include "logic/medal/playermedal.h"

VOID CPlayer::SetPower(UINT32 dwPower)
{
    m_stDT_PLAYER_BASE_DATA.dwPower = dwPower;
}

VOID CPlayer::SetFirstAttack(UINT32 dwFirstAttack)
{
    m_stDT_PLAYER_BASE_DATA.dwFirstAttack = dwFirstAttack;
}

VOID CPlayer::SetTodayFirstLoginTime(UINT64 qwTodayFirstLoginTime)
{
    m_stDT_PLAYER_BASE_DATA.qwTodayFirstLoginTime = qwTodayFirstLoginTime;
}
VOID CPlayer::SetBagOpenNum(UINT8 byOpenNum)
{
    m_stDT_PLAYER_BASE_DATA.byBagOpenNum = byOpenNum;
}

VOID CPlayer::AddCoin(UINT32 dwCoin, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwCoin;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddCoin::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwCoin += dwCoin;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddCoin += dwCoin;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterCoin = m_stDT_PLAYER_BASE_DATA.qwCoin;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDCOIN, wOpType, dwCoin, m_stDT_PLAYER_BASE_DATA.qwCoin, 
        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

// dwRMB ��λΪ��
VOID CPlayer::AddGold(UINT32 dwGold, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment, UINT32 dwRMB)
{
    INT32 nTmp = dwGold;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddGold::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwGold += dwGold;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddGold += dwGold;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterGold = m_stDT_PLAYER_BASE_DATA.qwGold;

    UINT32 dwAddRMBGold     = 0;
    UINT32 dwAddRMBGoldGift = 0;
    UINT32 dwAddGmGold      = 0;
    UINT32 dwAddGameGold    = 0;

    // ����Ƿ���ͨ����ֵ��ʽ��ӵ�Ԫ��
    if( CRecordMgr::EGGT_ADDFLAGEXCHANGE == wOpType || CRecordMgr::EGGT_GM_FLAGEXCHANGE == wOpType)
    {
        //��Ϊ��ҳ�ֵ�����ܳ�����˴����ԣ�ǿתû������
        //��תԪ������ һԪ������ʮ�֡�
        AddTotalAmount( dwGold );
        m_stDT_PLAYER_BASE_DATA.qwTotalRMB += dwRMB;

        m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddTotalRMB += dwRMB;
        m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterTotalRMB = m_stDT_PLAYER_BASE_DATA.qwTotalRMB;

        // ��ֵԪ������Դ;�� = ��ֵ����ң�Ԫ��1:10�һ���Ԫ�� + ����ҳ�ֵʱ����Ԫ�� + ϵͳ����Ԫ��
        if(CRecordMgr::EGGT_ADDFLAGEXCHANGE == wOpType)
        {
            // ��ҳ�ֵʱ��õ�Ԫ���У�����<����ң�Ԫ�� * 10>�Ĳ�����������Ҷһ�Ԫ����ʣ����ǳ�ֵ����Ԫ��
            // ע�⣬��������ҵĵ�λ�ǣ���
            dwAddRMBGold = dwRMB / 10;
            dwAddRMBGoldGift = (dwGold > dwAddRMBGold ? dwGold - dwAddRMBGold : 0);

            m_stDT_PLAYER_BASE_DATA.dwRMBGold     += dwAddRMBGold;
            m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift += dwAddRMBGoldGift;
        }
        else if(CRecordMgr::EGGT_GM_FLAGEXCHANGE == wOpType)
        {
            dwAddGmGold  = dwGold;
            m_stDT_PLAYER_BASE_DATA.dwGmGold      += dwAddGmGold;
        }

        //��ֵ�����ϱ���
        CPlayerSaveMgr::Instance()->SavePlayerData(this);
    }
    else
    {
        // ��ͨ��Ϸ��Ԫ��
        dwAddGameGold = dwGold;
    }

    // �������ǰ����ϷԪ��
    UINT64 qwCashGold = m_stDT_PLAYER_BASE_DATA.dwRMBGold + m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift + m_stDT_PLAYER_BASE_DATA.dwGmGold;
    UINT64 qwGameGold = (m_stDT_PLAYER_BASE_DATA.qwGold > qwCashGold ? (m_stDT_PLAYER_BASE_DATA.qwGold - qwCashGold) : 0);

    // ��¼Ԫ�������Ϣ
    CRecordMgr::Instance()->RecordGold(this->GetOriginalZoneID(), this->GetID(), this->GetLevel(), this->GetDT_PLAYER_BASE_DATA().byVipLevel, ERM_ADDGOLD, wOpType, 
        dwAddRMBGold, dwAddRMBGoldGift, dwAddGmGold, dwAddGameGold,
        m_stDT_PLAYER_BASE_DATA.dwRMBGold, m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift, m_stDT_PLAYER_BASE_DATA.dwGmGold, qwGameGold,
        qwParam1, qwParam2, qwParam3, qwParam4, strComment);

    //Ԫ�������Ϣ�ɼ�
    /*
    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDGOLD, wOpType, dwGold, m_stDT_PLAYER_BASE_DATA.qwGold, 
        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
    */
}
VOID CPlayer::AddStory(UINT32 dwStory, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwStory;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddStory::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwStory += dwStory;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddStory += dwStory;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterStory = m_stDT_PLAYER_BASE_DATA.qwStory;
    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDSTORY, wOpType, dwStory, m_stDT_PLAYER_BASE_DATA.qwStory, 
        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

VOID CPlayer::AddTotalAmount( UINT32 dwAmount )
{
    INT32 nTmp = dwAmount;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddTotalAmount::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        //return;	//vip������
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.dwTotalAmount += dwAmount;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.dwAddAmount += dwAmount;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.dwAfterAmount = m_stDT_PLAYER_BASE_DATA.dwTotalAmount;

    UINT8 byNewVipLevel = CVipPropMgr::Instance()->GetVipLevel( m_stDT_PLAYER_BASE_DATA.dwTotalAmount );

    if( byNewVipLevel > m_stDT_PLAYER_BASE_DATA.byVipLevel )
    {
        SetVipLevel( byNewVipLevel );
    }

}


VOID CPlayer::AddPhyStrength(UINT16 wPhyStrength, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT16 nTmp = wPhyStrength;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddPhyStrength::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.wPhyStrength += wPhyStrength;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.wAddPhyStrength += wPhyStrength;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.wAfterPhyStrength = m_stDT_PLAYER_BASE_DATA.wPhyStrength;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDPHYSTRENGTH, wOpType, wPhyStrength, m_stDT_PLAYER_BASE_DATA.wPhyStrength, 
        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::AddScience(UINT32 dwScience, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwScience;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddScience::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwScience += dwScience;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddScience += dwScience;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterScience = m_stDT_PLAYER_BASE_DATA.qwScience;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDSCIENCE, wOpType, dwScience, m_stDT_PLAYER_BASE_DATA.qwScience, 
        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::AddBlueGas(UINT32 dwGas, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwGas;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddBlueGas::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwBlueGas += dwGas;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddBlueGas += dwGas;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterBlueGas = m_stDT_PLAYER_BASE_DATA.qwBlueGas;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDBLUEGAS, wOpType, dwGas, m_stDT_PLAYER_BASE_DATA.qwBlueGas,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);

}
VOID CPlayer::AddPurpleGas(UINT32 dwGas, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwGas;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddPurpleGas::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwPurpleGas += dwGas;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddPurpleGas += dwGas;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterPurpleGas = m_stDT_PLAYER_BASE_DATA.qwPurpleGas;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDPURPLEGAS, wOpType, dwGas, m_stDT_PLAYER_BASE_DATA.qwPurpleGas,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::AddJingJie(UINT32 dwJingJie, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwJingJie;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddJingJie::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwJingJie += dwJingJie;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddJingJie += dwJingJie;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterJingJie = m_stDT_PLAYER_BASE_DATA.qwJingJie;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDJINGJIE, wOpType, dwJingJie, m_stDT_PLAYER_BASE_DATA.qwJingJie,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

VOID CPlayer::AddMedal(UINT32 dwMedal, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwMedal;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: AddJingJie::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwMedal += dwMedal;

    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAddMedal = dwMedal;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterMedal = m_stDT_PLAYER_BASE_DATA.qwMedal;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDMEDAL, wOpType, dwMedal, m_stDT_PLAYER_BASE_DATA.qwMedal,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

VOID CPlayer::SetJingJie(UINT32 dwJingJie, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwJingJie;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: SetJingJie::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwJingJie = dwJingJie;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterJingJie = m_stDT_PLAYER_BASE_DATA.qwJingJie;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_ADDJINGJIE, wOpType, dwJingJie, m_stDT_PLAYER_BASE_DATA.qwJingJie,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);

}

VOID CPlayer::DecCoin(UINT32 dwCoin, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwCoin;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecCoin::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwCoin = m_stDT_PLAYER_BASE_DATA.qwCoin < dwCoin ? 0 : (m_stDT_PLAYER_BASE_DATA.qwCoin - dwCoin);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecCoin += dwCoin;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterCoin = m_stDT_PLAYER_BASE_DATA.qwCoin;


    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECCOIN, wOpType, dwCoin, m_stDT_PLAYER_BASE_DATA.qwCoin,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::DecGold(UINT32 dwDecGold, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwDecGold;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecGold::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();


    UINT32 dwDecRMBGold     = 0;
    UINT32 dwDecRMBGoldGift = 0;
    UINT32 dwDecGmGold      = 0;
    UINT32 dwDecGameGold    = 0;

    m_stDT_PLAYER_BASE_DATA.qwGold = m_stDT_PLAYER_BASE_DATA.qwGold < dwDecGold ? 0 : (m_stDT_PLAYER_BASE_DATA.qwGold - dwDecGold);

    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecGold += dwDecGold;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterGold = m_stDT_PLAYER_BASE_DATA.qwGold;

    // ������Ӫ�����Ҫ����ҵ�ÿ��Ԫ�����Ѷ���Ҫע�����ж��������ڣ���ֵԪ������ֵ����Ԫ����ϵͳ����Ԫ������ϷԪ�������Կ۳�Ԫ�����鷳һ��
    // ���У�
    // ��ֵԪ�� = �����Ԫ�� = ���ÿ�γ�ֵʱ������ң�Ԫ�� * 10
    // ��ֵ����Ԫ�� = ÿ�γ�ֵʱʵ�ʻ�õ�Ԫ�� - ��ҵ��γ�ֵ������ң�Ԫ�� * 10����ÿ�γ�ֵʱ����Ķ���Ԫ��
    // ϵͳ����Ԫ�� = ͨ��GM��ʽ�������ӵĳ�ֵԪ����GM���Ը������ӳ�ֵԪ������ͨԪ����
    // ��Ϸ��Ԫ��   = ��Ϸ��������ҵ�Ԫ��
    // 
    // �۳��������£�
    // 1. ��������Ԫ�����㹻�Ļ��������ȿ۳������Ԫ��
    if(m_stDT_PLAYER_BASE_DATA.dwRMBGold >= dwDecGold)
    {
        dwDecRMBGold = dwDecGold; 
        m_stDT_PLAYER_BASE_DATA.dwRMBGold -= dwDecGold;
    }
    else
    {
        dwDecRMBGold = m_stDT_PLAYER_BASE_DATA.dwRMBGold;
        m_stDT_PLAYER_BASE_DATA.dwRMBGold = 0;

        UINT32 dwRemainDecGold = dwDecGold - dwDecRMBGold;

        // 2. �ٴӳ�ֵ����Ԫ���п۳�
        if(m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift >= dwRemainDecGold)
        {
            dwDecRMBGoldGift = dwRemainDecGold;
            m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift -= dwRemainDecGold;
        }
        else
        {
            dwDecRMBGoldGift = m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift;
            m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift = 0;

            dwRemainDecGold -= dwDecRMBGoldGift;

            // 3. ��ϵͳ����Ԫ���п۳�
            if(m_stDT_PLAYER_BASE_DATA.dwGmGold >= dwRemainDecGold)
            {
                dwDecGmGold = dwRemainDecGold;
                m_stDT_PLAYER_BASE_DATA.dwGmGold -= dwRemainDecGold;
            }
            else
            {
                dwDecGmGold = m_stDT_PLAYER_BASE_DATA.dwGmGold;
                m_stDT_PLAYER_BASE_DATA.dwGmGold = 0;

                // 4. ����ٴ���ϷԪ���п۳�
                dwDecGameGold = dwRemainDecGold - dwDecGmGold;
            }
        }
    }

    // �������ǰ����ϷԪ��
    UINT64 qwCashGold = m_stDT_PLAYER_BASE_DATA.dwRMBGold + m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift + m_stDT_PLAYER_BASE_DATA.dwGmGold;
    UINT64 qwGameGold = (m_stDT_PLAYER_BASE_DATA.qwGold > qwCashGold ? (m_stDT_PLAYER_BASE_DATA.qwGold - qwCashGold) : 0);

    CRecordMgr::Instance()->RecordGold(this->GetOriginalZoneID(), this->GetID(), this->GetLevel(), this->GetDT_PLAYER_BASE_DATA().byVipLevel, ERM_DECGOLD, wOpType, 
        dwDecRMBGold, dwDecRMBGoldGift, dwDecGmGold, dwDecGameGold,
        m_stDT_PLAYER_BASE_DATA.dwRMBGold, m_stDT_PLAYER_BASE_DATA.dwRMBGoldGift, m_stDT_PLAYER_BASE_DATA.dwGmGold, qwGameGold,
        qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

VOID CPlayer::DecStory(UINT32 dwStory, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwStory;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecStory::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwStory = m_stDT_PLAYER_BASE_DATA.qwStory < dwStory ? 0 : (m_stDT_PLAYER_BASE_DATA.qwStory - dwStory);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecStory += dwStory;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterStory = m_stDT_PLAYER_BASE_DATA.qwStory;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECSTORY, wOpType, dwStory, m_stDT_PLAYER_BASE_DATA.qwStory,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::DecPhyStrength(UINT16 wPhyStrength, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT16 nTmp = wPhyStrength;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecPhyStrength::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.wPhyStrength = m_stDT_PLAYER_BASE_DATA.wPhyStrength < wPhyStrength ? 0 : (m_stDT_PLAYER_BASE_DATA.wPhyStrength - wPhyStrength);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.wDecPhyStrength += wPhyStrength;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.wAfterPhyStrength = m_stDT_PLAYER_BASE_DATA.wPhyStrength;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECPHYSTRENGTH, wOpType, wPhyStrength, m_stDT_PLAYER_BASE_DATA.wPhyStrength,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::DecScience(UINT32 dwScience, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwScience;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecScience::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwScience = m_stDT_PLAYER_BASE_DATA.qwScience < dwScience ? 0 : (m_stDT_PLAYER_BASE_DATA.qwScience - dwScience);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecScience += dwScience;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterScience = m_stDT_PLAYER_BASE_DATA.qwScience;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECSCIENCE, wOpType, dwScience, m_stDT_PLAYER_BASE_DATA.qwScience,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

VOID CPlayer::DecBlueGas(UINT32 dwGas, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwGas;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecBlueGas::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwBlueGas = m_stDT_PLAYER_BASE_DATA.qwBlueGas < dwGas ? 0 : (m_stDT_PLAYER_BASE_DATA.qwBlueGas - dwGas);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecBlueGas += dwGas;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterBlueGas = m_stDT_PLAYER_BASE_DATA.qwBlueGas;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECBLUEGAS, wOpType, dwGas, m_stDT_PLAYER_BASE_DATA.qwBlueGas,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);

}
VOID CPlayer::DecPurpleGas(UINT32 dwGas, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwGas;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecPurpleGas::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwPurpleGas = m_stDT_PLAYER_BASE_DATA.qwPurpleGas < dwGas ? 0 : (m_stDT_PLAYER_BASE_DATA.qwPurpleGas - dwGas);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecPurpleGas += dwGas;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterPurpleGas = m_stDT_PLAYER_BASE_DATA.qwPurpleGas;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECPURPLEGAS, wOpType, dwGas, m_stDT_PLAYER_BASE_DATA.qwPurpleGas,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}
VOID CPlayer::DecJingJie(UINT32 dwJingJie, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwJingJie;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecJingJie::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwJingJie = m_stDT_PLAYER_BASE_DATA.qwJingJie < dwJingJie ? 0 : (m_stDT_PLAYER_BASE_DATA.qwJingJie - dwJingJie);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecJingJie += dwJingJie;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterJingJie = m_stDT_PLAYER_BASE_DATA.qwJingJie;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECJINGJIE, wOpType, dwJingJie, m_stDT_PLAYER_BASE_DATA.qwJingJie,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);

}

VOID CPlayer::DecMedal(UINT32 dwMedal, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    INT32 nTmp = dwMedal;
    if(nTmp <= 0)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: DecJingJie::Value is ivalid[%d]!"), MSG_MARK, nTmp);
        return;
    }
    CkToday();
    m_stDT_PLAYER_BASE_DATA.qwMedal = m_stDT_PLAYER_BASE_DATA.qwMedal < dwMedal ? 0 : (m_stDT_PLAYER_BASE_DATA.qwMedal - dwMedal);
    //��¼��������Ѽ�¼
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwDecMedal += dwMedal;
    m_stDT_PLAYER_TODAY_CONSUME_DATA.qwAfterMedal = m_stDT_PLAYER_BASE_DATA.qwMedal;

    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECMEDAL, wOpType, dwMedal, m_stDT_PLAYER_BASE_DATA.qwMedal,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);

}

VOID CPlayer::AddStudyCli(UINT32 dwOpValue, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    CAwaken* poAwaken = GetAwaken();
    if(NULL == poAwaken)
    {
        return;
    }

	poAwaken->GetDT_AWAKEN_DATA().stBaseInfo.qwStudyClip += dwOpValue;
    CRecordMgr::Instance()->RecordInfo( this->GetID(), ERM_DECSTUDYCLIP, wOpType, dwOpValue, poAwaken->GetDT_AWAKEN_DATA().stBaseInfo.qwStudyClip,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

VOID CPlayer::DecStudyCli(UINT32 dwOpValue, UINT16 wOpType, UINT64 qwParam1, UINT64 qwParam2, UINT64 qwParam3, UINT64 qwParam4, string strComment)
{
    CAwaken* poAwaken = GetAwaken();
    if(NULL == poAwaken)
    {
        return;
    }
	DT_AWAKEN_BASE_DATA& stBase = poAwaken->GetDT_AWAKEN_DATA().stBaseInfo;
	stBase.qwStudyClip = stBase.qwStudyClip >= dwOpValue ? stBase.qwStudyClip - dwOpValue  : 0;

    CRecordMgr::Instance()->RecordInfo( GetID(), ERM_ADDSTUDYCLIP, wOpType, dwOpValue, poAwaken->GetDT_AWAKEN_DATA().stBaseInfo.qwStudyClip,
                                        GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, qwParam1, qwParam2, qwParam3, qwParam4, strComment);
}

UINT64 CPlayer::GetMedal() // ��ȡ����ѫ��
{
    return m_stDT_PLAYER_BASE_DATA.qwMedal;
}

VOID CPlayer::SetVipLevel( UINT8 byVipLevel, UINT32 dwTotalAmount)
{
    //���������ֵ
    if (byVipLevel > CVipPropMgr::Instance()->GetMaxVipLevel())
    {
        byVipLevel = CVipPropMgr::Instance()->GetMaxVipLevel();
    }
    m_stDT_PLAYER_BASE_DATA.byVipLevel = byVipLevel;
	CPlayerMedal* poPlayerMedal = GetPlayerMedal();
	if ( NULL != poPlayerMedal)
	{
		poPlayerMedal->CheckMedalBySmallType(EMST_PLAYER_VIP_LEVEL);
	}
    m_stDT_PLAYER_TODAY_CONSUME_DATA.byAddVipLevel += (byVipLevel - m_stDT_PLAYER_TODAY_CONSUME_DATA.byAfterVipLevel);
    m_stDT_PLAYER_TODAY_CONSUME_DATA.byAfterVipLevel = m_stDT_PLAYER_BASE_DATA.byVipLevel;

    if (0 != dwTotalAmount)
    {
        m_stDT_PLAYER_BASE_DATA.dwTotalAmount = dwTotalAmount;
    }
	CPlayerBaseDataCacheMgr::Instance()->SetVipLevel(m_dwPlayerID, byVipLevel);
}

VOID CPlayer::DecPayByGM(UINT32 dwDecRMB)
{
    USR_INFO(_SDT("[%s: %d]: DecPayByGM::PlayerID[%u] DecRMB[%u]!"), MSG_MARK, m_stDT_PLAYER_BASE_DATA.dwID, dwDecRMB);
    SBuyGoldProp buyInfo;
    UINT32 dwDecGold = 0;
    if(!CVipPropMgr::Instance()->GetBuyPropByRMB(GetAuthType(), dwDecRMB, buyInfo ))
    {
        dwDecGold = dwDecRMB * 10;
        USR_INFO(_SDT("[%s: %d]: DecPayByGM::PlayerID[%u] GetBuyPropByRMB[%u] not found! DecRMB = %u, DecGold is %u"), MSG_MARK, m_stDT_PLAYER_BASE_DATA.dwID, GetAuthType(), dwDecRMB, dwDecGold);

    }
    else
    {
        dwDecGold = buyInfo.dwGold;
        USR_INFO(_SDT("[%s: %d]: DecPayByGM::PlayerID[%u] DecRMB = %u, DecGold is %u"), MSG_MARK, m_stDT_PLAYER_BASE_DATA.dwID, dwDecRMB, dwDecGold);
    }

    USR_INFO(_SDT("[%s: %d]: DecPayByGM::PlayerID[%u] Before op TotalAmount is %u, VipLevel is %u"), MSG_MARK, m_stDT_PLAYER_BASE_DATA.dwID, m_stDT_PLAYER_BASE_DATA.dwTotalAmount, m_stDT_PLAYER_BASE_DATA.byVipLevel);
    m_stDT_PLAYER_BASE_DATA.dwTotalAmount = m_stDT_PLAYER_BASE_DATA.dwTotalAmount >  dwDecGold ? m_stDT_PLAYER_BASE_DATA.dwTotalAmount - dwDecGold : 0;
    UINT8 byNewVipLevel = CVipPropMgr::Instance()->GetVipLevel( m_stDT_PLAYER_BASE_DATA.dwTotalAmount );
    SetVipLevel( byNewVipLevel );
    USR_INFO(_SDT("[%s: %d]: DecPayByGM::PlayerID[%u] After op TotalAmount is %u, VipLevel is %u"), MSG_MARK, m_stDT_PLAYER_BASE_DATA.dwID, m_stDT_PLAYER_BASE_DATA.dwTotalAmount, m_stDT_PLAYER_BASE_DATA.byVipLevel);
}

void CPlayer::CkToday()
{
    //����Ƿ��������
    if(!IsToday(m_stDT_PLAYER_TODAY_CONSUME_DATA.qwUTCLastConsumeTime))
    {
        CBaseDBCMD* poCMD = gsapi::GetDBMgr()->CreateCmd(EDBCT_SAVE_PLAYER_CONSUME);
        if(NULL == poCMD)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CreateCmd failed!"), MSG_MARK);
            return ;
        }
        poCMD->SetUserData((VOID*)&GetDT_PLAYER_TODAY_CONSUME_DATA(), GetID());
        gsapi::GetDBMgr()->AddCommand(poCMD);

        CSDDateTime	oDateTime(m_stDT_PLAYER_TODAY_CONSUME_DATA.qwUTCLastConsumeTime);
        tstring		strDateTime = SDTimeToString(oDateTime);
        // DBG_INFO( _SDT( "[%s: %d]:player:%d LastConsumeTime:%llu, LastConsumeTime:%s" ), MSG_MARK, m_dwPlayerID, m_stDT_PLAYER_TODAY_CONSUME_DATA.qwUTCLastConsumeTime, strDateTime.c_str());


        //��յ�ǰ�����Ѽ�¼
        memset(&m_stDT_PLAYER_TODAY_CONSUME_DATA, 0x00, sizeof(DT_PLAYER_TODAY_CONSUME_DATA));
        InitDT_PLAYER_TODAY_CONSUME_DATA();
    }
}

VOID CPlayer::AddFlowerNum( UINT32 dwFlowerNum )
{
    INT32 nTmp = dwFlowerNum;
    if(nTmp <= 0)
    {
        return;
    }
    m_stDT_PLAYER_BASE_DATA.dwFlowerSum += dwFlowerNum;
}
