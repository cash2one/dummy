

#ifndef _SELECTZONECMD_H_
#define _SELECTZONECMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSelectZoneCMD : public CBaseDBCMD
{
public:
	CSelectZoneCMD();
	~CSelectZoneCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SELECT_ZONE ; }

protected:

	BOOL SelectInfo(SGDP::ISDDBConnection* poDBConn, PKT_CLIGT_SELECT_ZONE_REQ* pstReq);

private:
	PKT_CLIGT_SELECT_ZONE_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

