#ifndef _RECORD_BATTLE_DATA_H_
#define _RECORD_BATTLE_DATA_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"

//���ս����Ϣ
struct SPlayerBattleData
{
	SPlayerBattleData()
	{
		memset(this, 0, sizeof(SPlayerBattleData));
	}
	UINT64 qwIndex; //�����ݿ��е�����
	DT_BATTLE_DATA2 oBattleData;
	UINT32 dwPlayerMyself; //������
	UINT32 dwPlayerEnemy; //����
};

class CRecordBattleData: public CBaseDBCMD
{
public:
	CRecordBattleData();
	virtual ~CRecordBattleData();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVEBATTLEDATA; }

private:
	//string m_strSql; //ִ�е�SQL���ļ�¼
	SPlayerBattleData m_stBattleData;  //ս����Ϣ
};

#endif