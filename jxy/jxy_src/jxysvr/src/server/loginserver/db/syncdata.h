

#ifndef _VERSION_NOTICE_CMD_H_
#define _VERSION_NOTICE_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include <protocol/server/protogsdb.h>
#include "dbmgr.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSyncDataCMD : public CBaseDBCMD
{
public:
	CSyncDataCMD();
	~CSyncDataCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SYNC_DATA ; }

protected:

	BOOL GetVersionNotice(SGDP::ISDDBConnection* poDBConn);
	BOOL GetForbidLogin(SGDP::ISDDBConnection* poDBConn);
	BOOL GetForbidRegistered(SGDP::ISDDBConnection* poDBConn);
private:
	SVersionNoticeInfo			m_stVersionNoticeInfo;

	CForbidLoginbyDeviceIDMap		m_mapForbidLoginbyDeviceID;
	CForbidLoginbyUserIDMap		m_mapForbidLoginbyUserID;
	CForbidLoginbyPlayerIDMap		m_mapForbidLoginbyPlayerID;

	CForbidRegisteredbyDeviceIDMap	m_mapForbidRegisteredbyDeviceID;
	CForbidRegisteredbyUserIDMap	m_mapForbidRegisteredbyUserID;
};

#endif //#ifndef _LOGINCMD_H_

