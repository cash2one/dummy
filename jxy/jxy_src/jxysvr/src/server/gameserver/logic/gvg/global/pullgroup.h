///<------------------------------------------------------------------------------
//< @file:   pullgroup.h
//< @author: hongkunan
//< @date:   2014��1��15�� 11:56:19
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pullgroup_h_
#define _pullgroup_h_

#include <protogspk.h>

#include "logic/gvg/gvgdef.h"

// ������ս����ҵ�ʵ����
class CPullPlayer
{
public:
    CPullPlayer(ZoneID/* ��������� */, CPlayer*);

public:
    // ���ʵ��
    CPlayer *m_poPlayer;

    // �������������
    ZoneID m_zoneID;
};

// �����飬ÿ������һ������ȡ��ҵ����������齫����������ȡ���
class CPullGroup
{
public:
    CPullGroup()
        : m_groupID(0)
        , m_dwTryCnt(0)
    {

    }
    
    ~CPullGroup()
    {
        UnInit();
    }

    void UnInit();

    // �����в�ս��ҵ����ݼ���ʱ������������
    virtual VOID OnPullOut() = 0;

    virtual VOID OnTryTooManyTimes(){}

    virtual EPullGroupType GetGroupType() = 0;

public:
    // ��ȡʣ��δ��������
    VOID Pull();

    void SendPullReq(ZoneID, CPlayerIDSet&);

    // �ɹ���ȡ��ĳ����ҵ�����ʱִ�еĲ���
    VOID HandleRetPlayerPkt(UINT16 wZoneID, PKT_GSPK_RET_PLAYER_ACK&);

    GroupID GetGroupID(){ return m_groupID; }
    VOID SetGroupID(GroupID groupID){ m_groupID = groupID; }

    CPullPlayerMap& GetPlayers(){ return m_mapPulledPlayer; }

    // �Ƿ�����ȡ�걾�����������
    BOOL IsPullOut(){ return m_pullingList.empty(); }

private:
    // ������Ƿ��ڴ���ȡ��ҵ�������
    BOOL InPullingList(PlayerID playerID);

    // ����ҴӴ���ȡ��ҵ��������Ƴ�
    VOID EraseFromPullList(PlayerID playerID);

    // �Ƿ�����ȡ��ָ�������
    BOOL IsPulled(PlayerID playerID);

protected:
    // �����ID
    GroupID m_groupID;

    // ������ȡ�Ĵ���
    UINT32 m_dwTryCnt;

    ZoneToPlayersMap m_mapZone2Players;

    // ʣ��Ĵ���ȡ�����id�б�
    CPlayerIDSet m_pullingList;

    // ����ȡ���Ĳ�ս����б�
    CPullPlayerMap m_mapPulledPlayer;
};

// ��ȡ��
class CGvGPullGroup : public CPullGroup
{
public:
    CGvGPullGroup(){}

    VOID AddPullPlayerIDList(CPKFaction &oPKFaction);    

private:
    // @impl
    virtual void OnPullOut();

    // @impl
    virtual EPullGroupType GetGroupType(){ return EPullType_GvG; }

    // @override
    virtual void OnTryTooManyTimes();

public:
    // ����ID
    ArenaID m_arenaID;
};

#endif //_pullgroup_h_