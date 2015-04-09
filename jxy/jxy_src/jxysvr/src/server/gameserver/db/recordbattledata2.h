#ifndef _RECORD_BATTLE_DATA2_H_
#define _RECORD_BATTLE_DATA2_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"

//���ս����Ϣ
struct SPlayerBattleData2
{
	SPlayerBattleData2()
	{
		memset(this, 0, sizeof(SPlayerBattleData2));
	}
	UINT64 qwIndex; //�����ݿ��е�����
	DT_BATTLE_DATA5 oBattleData;
	UINT32 dwPlayerMyself; //������
	UINT32 dwPlayerEnemy; //����
};

class CRecordBattleData2: public CBaseDBCMD
{
public:
	CRecordBattleData2();
	virtual ~CRecordBattleData2();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVEBATTLEDATA2; }

private:
	//string m_strSql; //ִ�е�SQL���ļ�¼
	SPlayerBattleData2 m_stBattleData;  //ս����Ϣ
};

#endif