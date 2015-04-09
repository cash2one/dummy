#ifndef _SAVE_PLAYER_CONSUME_H_
#define _SAVE_PLAYER_CONSUME_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "protocol/server/protocommondata.h"

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSavePlayerConsume : public CBaseDBCMD
{
public:
	CSavePlayerConsume();
	virtual ~CSavePlayerConsume();
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

	//��������
	virtual VOID SetUserData(VOID* pUserData);

public:
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVE_PLAYER_CONSUME ; }

private:
	BOOL Execute(SGDP::ISDDBConnection* poDBConn);
private:
	DT_PLAYER_TODAY_CONSUME_DATA m_stDT_PLAYER_TODAY_CONSUME_DATA;

};



#endif