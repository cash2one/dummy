

#ifndef _LOGINCMD_H_
#define _LOGINCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CRegisterUserNameCMD : public CBaseDBCMD
{
public:
	CRegisterUserNameCMD();
	~CRegisterUserNameCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_REG ; }
	
protected:


	BOOL Register(SGDP::ISDDBConnection* poDBConn,
		TCHAR* pszDeviceID,
		TCHAR* pszUserName);

private:

};

#endif //#ifndef _LOGINCMD_H_

