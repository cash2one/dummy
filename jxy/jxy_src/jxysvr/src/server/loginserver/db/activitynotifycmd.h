

#ifndef _ACTIVITY_NOTIFYCMD_H_
#define _ACTIVITY_NOTIFYCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CActivityNotifyCMD : public CBaseDBCMD
{
public:
	CActivityNotifyCMD();
	~CActivityNotifyCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_ACTIVITY_NOTIFY ; }

protected:


	BOOL ActivityNotify(SGDP::ISDDBConnection* poDBConn,
		UINT32		dwPlayerID,
		UINT8		byActivityType,
		UINT8		byNotify);

private:

};

#endif //#ifndef _LOGINCMD_H_

