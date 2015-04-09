///<------------------------------------------------------------------------------
//< @file:   pullgroup.cpp
//< @author: hongkunan
//< @date:   2014��1��15�� 13:59:14
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "logic/gvg/global/pullgroup.h"

#include <protogspk.h>
#include <sdloggerimpl.h>

#include "framework/gsapi.h"
#include "logic/gvg/global/gvgmgr.h"
#include "pullplayermgr.h"
#include "net/db/dbprocessor.h"

using namespace SGDP;

namespace innerutil
{
    // �����������ݴ������ʵ��
    CPlayer* BuildPlayerFromPkt(DT_PLAYER_DATA &stDT_PLAYER_DATA)
    {
        CPlayer* poPlayer = CPlayerPoolMgr::Instance()->Create();
        if (NULL == poPlayer)
        {
            SYS_CRITICAL(_SDT("[%s: %d] CPlayerPoolMgr create player Failed, player[%u : %s]!"), 
                MSG_MARK, stDT_PLAYER_DATA.stPlayerNoPvpData.stBaseData.dwID, stDT_PLAYER_DATA.stPlayerNoPvpData.stBaseData.aszDispName);

            return NULL;
        }

        //������Ҷ���
        if(!poPlayer->Init(stDT_PLAYER_DATA))
        {
            SYS_CRITICAL(_SDT("[%s: %d] player[%u : %s] Init failed!"), 
                MSG_MARK, stDT_PLAYER_DATA.stPlayerNoPvpData.stBaseData.dwID, stDT_PLAYER_DATA.stPlayerNoPvpData.stBaseData.aszDispName);

            CPlayerPoolMgr::Instance()->Remove(poPlayer);
            return NULL;
        }

        return poPlayer;
    }
}

CPullPlayer::CPullPlayer(ZoneID zoneID/* ��������� */, CPlayer *poPlayer)
    : m_zoneID(zoneID)
    , m_poPlayer(poPlayer)
{

}

// �ɹ���ȡ��ĳ����ҵ�����ʱִ�еĲ���
VOID CPullGroup::HandleRetPlayerPkt(UINT16 wZoneID, PKT_GSPK_RET_PLAYER_ACK &oSyncAck)
{
    // ������id�����Ϣ���Ƿ��ɷ�����ȷ����
    if(oSyncAck.dwPKGroupID != m_groupID)
    {
        // ˵����Ϣ���ɷ�����
        SYS_CRITICAL(_SDT("[%s: %d]: detecting sync pkt<groupid = %u> was assigned to wrong PKGroup<groupid = %u>!"), MSG_MARK, oSyncAck.dwPKGroupID, m_groupID);
        return;
    }

    if(0 == oSyncAck.byRetCnt)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: detecting sync pkt<groupid = %u> contains 0 players!"), MSG_MARK, oSyncAck.dwPKGroupID);
        return;
    }

    DT_PLAYER_DATA stPlayerData;

    // ����Ϣ���д���CPlayer
    for(BYTE i = 0; i < oSyncAck.byRetCnt; ++i)
    {
        DT_SYNC_PLAYER &stSyncPlayer = oSyncAck.astPlayerList[i];

        UINT32 dwPlayerID = stSyncPlayer.stPlayerNoPvpData.stBaseData.dwID;

        // ��������Ƿ��ڴ���ȡ��ҵ�������
        if(FALSE == InPullingList(dwPlayerID))
        {
            if(FALSE == IsPulled(dwPlayerID))
            {
                SYS_CRITICAL(_SDT("[%s: %d]: detecting group[groupid = %u] pulled wrong player[player id = %u], discard it!"), MSG_MARK, oSyncAck.dwPKGroupID, m_groupID);
            }

            continue;
        }
        
        memset(&stPlayerData.stPlayerPvpData, 0, sizeof(stPlayerData.stPlayerPvpData));
        stPlayerData.stPlayerNoPvpData = stSyncPlayer.stPlayerNoPvpData;

        CPlayer *poPlayer = innerutil::BuildPlayerFromPkt(stPlayerData);
        if(NULL == poPlayer)
        {
            continue;
        }

        CPullPlayer *poPullPlayer = new CPullPlayer(wZoneID, poPlayer);
        m_mapPulledPlayer[poPlayer->GetID()] = poPullPlayer;

        // ����ҴӴ���ȡ��ҵ��������Ƴ�
        EraseFromPullList(poPlayer->GetID());
    }
}

// ������Ƿ��ڴ���ȡ��ҵ�������
BOOL CPullGroup::InPullingList(PlayerID playerID)
{
    return m_pullingList.find(playerID) != m_pullingList.end();
}

BOOL CPullGroup::IsPulled(PlayerID playerID)
{
    return m_mapPulledPlayer.find(playerID) != m_mapPulledPlayer.end();
}

// ����ҴӴ���ȡ��ҵ��������Ƴ�
VOID CPullGroup::EraseFromPullList(PlayerID playerID)
{
    m_pullingList.erase(playerID);
}

void CPullGroup::UnInit()
{
    for(CPullPlayerMap::iterator itr = m_mapPulledPlayer.begin(); itr != m_mapPulledPlayer.end(); ++itr)
    {
        CPullPlayer *poPullPlayer = itr->second;
        if(NULL == poPullPlayer)
        {
            continue;
        }

        CPlayerPoolMgr::Instance()->Remove(poPullPlayer->m_poPlayer);
        delete poPullPlayer;
    }

    m_mapPulledPlayer.clear();
}

VOID CPullGroup::Pull()
{
    if(IsPullOut())
    {
        return;
    }

    ++m_dwTryCnt;
    OnTryTooManyTimes();

    // һһ���Ӧ�ĸ��������������б�
    for(ZoneToPlayersMap::iterator itr = m_mapZone2Players.begin(); itr != m_mapZone2Players.end(); ++itr)
    {
        ZoneID zoneID = itr->first;
        CPlayerIDSet &pullList = itr->second;

        SendPullReq(zoneID, pullList);
    }
}

void CPullGroup::SendPullReq(ZoneID zoneID, CPlayerIDSet &pullList)
{
    PKT_PKGS_GET_PLAYER_REQ req;
    req.dwPKGroupID = m_groupID;
    req.byGetCnt    = 0;

    // ����������ָ������ȡ���
    for (CPlayerIDSet::iterator itr = pullList.begin(); itr != pullList.end(); ++itr)
    {
        PlayerID playerID = *itr;
        req.adwPlayerIDList[req.byGetCnt++] = playerID;

        // �������������࣬���ֳɼ�����Ϣ�����η���
        if(MAX_REQ_SYNC_PLAYER_CNT_ONCE == req.byGetCnt)
        {
            // ����������ȡ���
            gsapi::SendMsg2GS(zoneID, (CHAR*)&req, PKGS_GET_PLAYER_REQ);

            memset(&req, 0, sizeof(req));
            req.dwPKGroupID = m_groupID;
        }
    }

    /*
    // �ݶ�: ֻ��ȡһ��
    req.byGetCnt = 1;
    */

    // ��ȡʣ������
    if(req.byGetCnt > 0)
    {
        gsapi::SendMsg2GS(zoneID, (CHAR*)&req, PKGS_GET_PLAYER_REQ);
    }
}

VOID CGvGPullGroup::AddPullPlayerIDList(CPKFaction &oPKFaction)
{
    DT_GVG_FORMATION_DATA stMatrix = oPKFaction.GetData().stFormation;
    ZoneID zoneID = oPKFaction.GetZoneID();

    for(UINT16 i = 0; i < stMatrix.byPlayerNum; i++)
    {
        UINT32 dwPlayerID = stMatrix.adwPlayerIDList[i];
        if(0 == dwPlayerID)
        {
            continue;
        }

        m_pullingList.insert(dwPlayerID);

        // ������ȡ��Ұ������з���
        m_mapZone2Players[zoneID].insert(dwPlayerID);
    }

    m_pullingList.erase(0);
}

VOID CGvGPullGroup::OnPullOut()
{
    CGvGMgr::Instance()->OnArenaReadyGo(this);
}

void CGvGPullGroup::OnTryTooManyTimes()
{
    if(0 == m_dwTryCnt % 10)
    {
        SYS_CRITICAL(_SDT("[%s: %d] CGvGPullGroup::OnTryTooManyTimes pullgroup of arena[%u] try too many times[%u]!"), MSG_MARK, m_arenaID, m_dwTryCnt);
    }
}