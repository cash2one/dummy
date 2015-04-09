#ifndef _GET_BATTLE_DATA_H_
#define _GET_BATTLE_DATA_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "recordbattledata.h"

struct SBattleDataParam
{
	SBattleDataParam()
	{
		memset(this, 0, sizeof( SBattleDataParam ));
	}
	
	UINT32 dwPlayerID;
	UINT64 qwDataIndex; 
};

class CGetBattleData: public CBaseDBCMD
{
public:
	CGetBattleData();
	virtual ~CGetBattleData();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GETBATTLEDATA; }

private:
	string m_strSql; //ִ�е�SQL���ļ�¼
	DT_BATTLE_DATA5 m_battleData;
	SBattleDataParam m_oDataParam;
	BOOL m_bHaveBattleData;
};

#endif