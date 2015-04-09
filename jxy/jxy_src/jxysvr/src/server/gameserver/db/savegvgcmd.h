///<------------------------------------------------------------------------------
//< @file:   gameserver\db\savegvgcmd.h
//< @author: hongkunan
//< @date:   2014��2��17�� 22:11:32
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _savegvgcmd_h_
#define _savegvgcmd_h_

#include <db/basedbccmd.h>
#include <db/dbmgr.h>
#include <sddb.h>

#include "logic/gvg/global/gvgmgr.h"

class CSaveGvGActivityCMD : public CBaseDBCMD
{
public:
    CSaveGvGActivityCMD()
    {
        memset(&m_stAct, 0, sizeof(m_stAct));
    }

public:
    // �����ݿ��߳�ִ��
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted();

    // @impl
    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVE_GVG_ACTIVITY; }

private:
    CHAR* BuildSql(SGDP::ISDDBConnection *poDBConn);

private:
    DT_GVG_ACTIVITY_DATA m_stAct;
};

class CSaveGvGArenaCMD : public CBaseDBCMD
{
public:
    CSaveGvGArenaCMD()
    {
        memset(&m_stArena, 0, sizeof(m_stArena));
    }

public:
    BOOL SaveData(SGDP::ISDDBConnection*);

    // �����ݿ��߳�ִ��
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted();

    // @impl
    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVE_GVG_ARENA; }

private:
    DT_GVG_ARENA_DATA m_stArena;
};

class CClearGvGActivityCMD : public CBaseDBCMD
{
public:
    // �����ݿ��߳�ִ��
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted(){}

    // @impl
    virtual VOID SetUserData(VOID* pUserData){}

public:
    virtual EDBCmdType GetDBCmdType() { return EDBCT_CLEAR_GVG_ACTIVITY; }
};


#endif //_savegvgcmd_h_