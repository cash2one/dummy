///<------------------------------------------------------------------------------
//< @file:   gameserver\db\delplayerlog.h
//< @author: Kang_zhiquan
//< @date:   2014��5��21�� 21:7:25
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _delplayerlog_h_
#define _delplayerlog_h_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "dbmgr.h"

class CDelPlayerLogCMD : public CBaseDBCMD
{
public:
	CDelPlayerLogCMD();
	virtual ~CDelPlayerLogCMD();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_DEL_PLAYER_LOG; }
private: 
	UINT64 m_qwKey;
};
#endif //_delplayerlog_h_