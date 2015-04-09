///<------------------------------------------------------------------------------
//< @file:   gameserver\db\addplayerslog.h
//< @author: Kang_zhiquan
//< @date:   2014��5��22�� 10:29:7
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _addplayerslog_h_
#define _addplayerslog_h_
#include <db/basedbccmd.h>
#include <sddb.h>
#include "dbmgr.h"
#include "protocol/server/protocommondata.h"

class CAddPlayersLogCMD : public CBaseDBCMD
{
public:
	CAddPlayersLogCMD();
	virtual ~CAddPlayersLogCMD();
	/**
	* @brief �첽ִ��SQL����
	* @poDBConn �첽ִ��SQL�����Connection����
	* @return VOID
	*/						
	VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection* poDBConn);

	/**
	* @brief ͬ��ִ��SQL������ص��߼�����
	* @return VOID
	*/
    VOID SDAPI OnExecuted();

	virtual VOID SetUserData(VOID* pUserData);
public:
	virtual EDBCmdType GetDBCmdType() { return EDBCT_ADD_PLAYER_LOG; }
private: 
	DT_BATTLE_LOG_MSG_LST_DATA m_stLstData;
};
#endif //_addplayerslog_h_