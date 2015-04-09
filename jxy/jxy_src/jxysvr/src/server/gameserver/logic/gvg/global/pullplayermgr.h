///<------------------------------------------------------------------------------
//< @file:   pullplayermgr.h
//< @author: hongkunan
//< @date:   2014��1��15�� 11:51:47
//< @brief:  ��ȡ������ģ�λ�ڿ��ս��������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pullplayermgr_h_
#define _pullplayermgr_h_

#include <protogspk.h>
#include <sdsingleton.h>
#include <sdobjectpool.h>

#include "logic/gvg/global/pullgroup.h"

// ��ȡ������ģ���λ�ڿ��ս�������£�ר�Ÿ�������Ϸ��������ȡ������ݣ����������ȡ��ҵ���
class CPullPlayerMgr
{
    DECLARE_SINGLETON(CPullPlayerMgr)

public:
    CPullPlayerMgr()
        : m_dwAllocGroupID(0)
        , m_oGvGGroupPool(5)
    {
    }

    BOOL Init(){ return TRUE; }

    // �ɹ����յ��������
    VOID HandleRetPlayer(UINT16 zoneID, PKT_GSPK_RET_PLAYER_ACK&);

    CPullGroup* FindPullGroup(GroupID);

    // �½�������
    CPullGroup* NewGroup(EPullGroupType ePKType);

    VOID EraseGroup(GroupID);

    void Pull();

    void ClearDeadGroup();

private:
    GroupID AllocGroupID(){ return ++m_dwAllocGroupID; }
    
    CPullGroupMap m_mapPullGroup; // ���п��ս�� = PvP + PvE + GvG + GvE

    CSDObjectPool<CGvGPullGroup> m_oGvGGroupPool; // ����vs�������

private:
    GroupID m_dwAllocGroupID;
};

#endif //_pullplayermgr_h_