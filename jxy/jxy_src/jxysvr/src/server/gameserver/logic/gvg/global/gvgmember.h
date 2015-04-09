///<------------------------------------------------------------------------------
//< @file:   logic\gvg\gvgmember.h
//< @author: hongkunan
//< @date:   2014��2��18�� 17:29:11
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgmember_h_
#define _gvgmember_h_

#include <protocommondata.h>
#include <sdobjectpool.h>

#include "logic/gvg/global/pullgroup.h"
#include "logic/gvg/gvgdef.h"

// ��ս����
class CPKFaction
{
public:
    CPKFaction()
    {
        Clear();
    }

public:
    BOOL Init(DT_PK_FACTION&);
    void SaveTo(DT_PK_FACTION&);

    void Clear();

    DT_PK_FACTION& GetData(){ return m_stFaction; }

    UINT16 GetZoneID(){ return m_stFaction.stBaseData.wZoneID; }
    UINT32 GetFactionID(){ return m_stFaction.stBaseData.stBaseData.dwFactionID; }

    // ��ȡ��������ݳɹ�����
    void ResetMembers(CPullPlayerMap&);

    CPlayer* FindPlayer(UINT32 dwPlayerID);

    BOOL IsMatrixEmpty(){ return 0 == m_stFaction.stFormation.byPlayerNum; }

    CPlayerVec GetFormationPlayers();

public:

    // ���ɵĻ�����Ϣ
    DT_PK_FACTION m_stFaction;
    CPullPlayerMap m_mapPlayers; // ���ɲ�ս��ҵ������б�
};

// ��ս��
class CPKZone
{
    typedef std::map<UINT32, CPKFaction*> CPKFactionMap; // ����ʵ��map���� = ����ID�� ֵ = ����ʵ��

public:
    CPKZone()
        : m_zoneID(0)
    {
    }

    // ��ʼ�����ɵ����ͺͲ�ս�������
    BOOL Init(DT_PK_FACTION_LIST&);

    void Clear();

    CPKFaction* FindPKFaction(UINT32 dwFactionID);

    BOOL IsEmpty()
    {
        return m_mapPKFaction.empty();
    }

    void AddPKFaction(CPKFaction *poPKFaction);

public:
    ZoneID m_zoneID;
    CPKFactionMap m_mapPKFaction; // �����ڵĲ�ս�����б�
};

#endif //_gvgmember_h_