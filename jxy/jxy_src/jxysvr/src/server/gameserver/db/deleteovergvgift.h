///<------------------------------------------------------------------------------
//< @file:   gameserver\db\deleteovergvgift.h
//< @author: Kang_zhiquan
//< @date:   2014��5��8�� 9:52:16
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _deleteovergvgift_h_
#define _deleteovergvgift_h_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "dbmgr.h"

class CDeleteOverGvGift: public CBaseDBCMD
{
public:
	CDeleteOverGvGift();
	virtual ~CDeleteOverGvGift();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_DELETE_GVG_GIFT; }

private:
	UINT16 m_wSessionID;//���ڽ���
};
#endif //_deleteovergvgift_h_