

#ifndef _RECORD_INFO_H_
#define _RECORD_INFO_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CRecordInfoCMD : public CBaseDBCMD
{
public:
	CRecordInfoCMD();
	~CRecordInfoCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_RECORD_INFO ; }
};

#endif //#ifndef _LOGINCMD_H_

