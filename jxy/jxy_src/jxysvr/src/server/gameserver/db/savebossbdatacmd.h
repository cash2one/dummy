

#ifndef _SAVEBOSSBDATACMD_H_
#define _SAVEBOSSBDATACMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playersavemgr.h>

using namespace  SGDP;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSaveBossBDataCMD : public CBaseDBCMD
{
public:
	CSaveBossBDataCMD();
	~CSaveBossBDataCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVEBOSSB ; }

protected:
	///////////////////////////////////////////////////////////////////////////////////////////////
	BOOL	SaveData(ISDDBConnection* poDBConn);//����
	
	

private:
	DT_BOSS_BATTLE_DATA m_stBossBData;

};

#endif //#ifndef _GETPLAYERDATACMD_H_

