

#ifndef _SAVEPLAYERSRACEDATACMD_H_
#define _SAVEPLAYERSRACEDATACMD_H_

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
class CSavePlayersRaceDataCMD : public CBaseDBCMD
{
public:
	CSavePlayersRaceDataCMD();
	~CSavePlayersRaceDataCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVERACE ; }

protected:
	///////////////////////////////////////////////////////////////////////////////////////////////
	BOOL	SaveData(ISDDBConnection* poDBConn);//����
	
private:
	

	CPlayersRaceSaveData* m_poPlayersRaceSaveInfo;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

