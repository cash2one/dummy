

#ifndef _PLAYERLEVELUPGRADECMD_H_
#define _PLAYERLEVELUPGRADECMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CPlayUpgrateCMD : public CBaseDBCMD
{
public:
	CPlayUpgrateCMD();
	~CPlayUpgrateCMD();

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

public:
	virtual EDBCmdType GetDBCmdType() { return EDBCT_LVLUP ; }

protected:


	BOOL UpdateLevel(SGDP::ISDDBConnection* poDBConn,
		UINT32	dwPlayerID,
		UINT16 wPlayerLevel);

private:

};

#endif //#ifndef _LOGINCMD_H_

