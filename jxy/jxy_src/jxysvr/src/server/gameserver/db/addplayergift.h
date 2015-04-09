///<------------------------------------------------------------------------------
//< @file:   gameserver\db\addplayergift.h
//< @author: Kang_zhiquan
//< @date:   2014��6��10�� 14:53:17
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _addplayergift_h_
#define _addplayergift_h_
#include <db/basedbccmd.h>
#include <sddb.h>
#include "dbmgr.h"
#include <string>

struct SActivityGift
{
	UINT32 dwStartPlayerID;
	UINT32 dwEndPlayerID;
	UINT32 dwZoneID;
	string strGiftName;
	string strGiftDesc;
	string strJson;
	string strTime;
	UINT8 bySelectType;
	SActivityGift()
	{
		dwStartPlayerID = 0;
		dwEndPlayerID = 0;
		dwZoneID = 0;
		strGiftDesc = "";
		strGiftName = "";
		strJson = "";
		strTime = "";
		bySelectType = 0;
	}
};

class CAddPlayerGiftCMD : public CBaseDBCMD
{
public:
	CAddPlayerGiftCMD();
	virtual ~CAddPlayerGiftCMD();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_ADD_PLAYER_GIFT; }
private: 
	SActivityGift m_stGiftData;
};
#endif //_addplayergift_h_