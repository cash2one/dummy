

#ifndef _CLRPLAYERDATACMD_H_
#define _CLRPLAYERDATACMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/instance/instance.h>



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CClrPlayerDataCMD : public CBaseDBCMD
{
public:
	CClrPlayerDataCMD();
	~CClrPlayerDataCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_CLR ; }

protected:

	BOOL ClrData(SGDP::ISDDBConnection* poDBConn);

private:
	UINT32 m_dwPlayerID;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

