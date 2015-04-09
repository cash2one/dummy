

#ifndef _PLAYBINDCMD_H_
#define _PLAYBINDCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include <protocol/server/protogsdb.h>


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CPlayBindCMD : public CBaseDBCMD
{
public:
	CPlayBindCMD();
	~CPlayBindCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_BIND ; }

protected:
	BOOL Bind(SGDP::ISDDBConnection* poDBConn, UINT8  byAuthType, UINT32 dwPlayID, TCHAR* pszUserName, TCHAR* pszNickName);

private:
	PKT_CLILS_BIND_ACK	m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

