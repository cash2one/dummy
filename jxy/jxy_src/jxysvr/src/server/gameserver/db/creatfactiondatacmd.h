

#ifndef _CREATE_FACTION_DATA_CMD_H_
#define _CREATE_FACTION_DATA_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <protocligs.h>
#include <logic/player/playersavemgr.h>

using namespace  SGDP;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CCreateFactionDataCMD : public CBaseDBCMD
{
public:
	CCreateFactionDataCMD();
	~CCreateFactionDataCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_CREATE_FACTION ; }

protected:
	///////////////////////////////////////////////////////////////////////////////////////////////
	BOOL	CreateData(ISDDBConnection* poDBConn);//����
	
	

private:
	UINT16	m_wErrCode;
	UINT32	m_dwFactionID;
	PKT_CLIGS_CREATE_FACTION_REQ m_stReq;

};

#endif //#ifndef _GETPLAYERDATACMD_H_

