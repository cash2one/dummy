

#ifndef _SAVEPLUNDERSPLUNDERDATACMD_H_
#define _SAVEPLUNDERSPLUNDERDATACMD_H_

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
class CSavePlayersPlunderDataCMD : public CBaseDBCMD
{
public:
	CSavePlayersPlunderDataCMD();
	~CSavePlayersPlunderDataCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVEPLUNDER ; }

protected:
	///////////////////////////////////////////////////////////////////////////////////////////////
	BOOL	SaveData(ISDDBConnection* poDBConn);//����
	
private:
	

	CPlayersPlunderSaveData* m_poPlayersPlunderSaveInfo;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

