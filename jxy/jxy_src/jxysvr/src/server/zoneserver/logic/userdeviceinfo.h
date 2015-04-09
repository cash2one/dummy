

#ifndef _USER_DEVICE_INFO_H_
#define _USER_DEVICE_INFO_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CUserDeviceInfoCMD : public CBaseDBCMD
{
public:
	CUserDeviceInfoCMD();
	~CUserDeviceInfoCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_USER_DEVICE_INFO ; }

private:
	PKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

