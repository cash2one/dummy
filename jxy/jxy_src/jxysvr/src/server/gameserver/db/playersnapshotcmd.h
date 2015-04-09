///<------------------------------------------------------------------------------
//< @file:   gameserver\db\playersnapshotcmd.h
//< @author: hongkunan
//< @date:   2014��5��30�� 11:6:4
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _playersnapshotcmd_h_
#define _playersnapshotcmd_h_

#include <db/basedbccmd.h>
#include <db/dbmgr.h>
#include <sddb.h>

class CSavePlayerSnapShotCMD : public CBaseDBCMD
{
public:
    CSavePlayerSnapShotCMD()
    {
    }

public:
    // �����ݿ��߳�ִ��
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted(){}

    // @impl
    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVE_PLAYER_SNAP_SHOT; }

private:
    BOOL BuildSql(SGDP::ISDDBConnection *poDBConn, CHAR* pszSql);

private:
    DT_PLAYER_NOPVP_DATA m_stPlayerNoPvPData;
};

class CDelPlayerSnapShotCMD : public CBaseDBCMD
{
public:
    CDelPlayerSnapShotCMD(){}

public:
    // �����ݿ��߳�ִ��
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted(){}

    // @impl
    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType() { return EDBCT_DEL_PLAYER_SNAP_SHOT; }

private:
    UINT32 m_dwPlayerID;
};

#endif //_playersnapshotcmd_h_