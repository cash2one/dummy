

#ifndef _PLAYERDSPNAMEUPGRADECMD_H_
#define _PLAYERDSPNAMEUPGRADECMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CPlayDspNameUpgradeCMD : public CBaseDBCMD
{
public:
	CPlayDspNameUpgradeCMD();
	~CPlayDspNameUpgradeCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_DSPNAMEUP ; }

protected:


	BOOL UpdateDspName(SGDP::ISDDBConnection* poDBConn,
		UINT32	dwPlayerID,
		TCHAR* pszDspName);

private:

};

#endif //#ifndef _LOGINCMD_H_

