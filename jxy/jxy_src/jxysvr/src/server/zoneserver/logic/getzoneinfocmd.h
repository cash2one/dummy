

#ifndef _CGETZONEINFOCMD_H_
#define _CGETZONEINFOCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetZoneInfoCMD : public CBaseDBCMD
{
public:
	CGetZoneInfoCMD();
	~CGetZoneInfoCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GET_ZONE_INFO ; }

protected:

	BOOL GetInfo(SGDP::ISDDBConnection* poDBConn, UINT16 wID);

private:
	PKT_CLIZS_GET_ZONE_INFO_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

