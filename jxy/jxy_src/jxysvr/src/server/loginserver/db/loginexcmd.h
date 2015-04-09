

#ifndef _LOGINEXCMD_H_
#define _LOGINEXCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include <protocol/server/protogsdb.h>


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CLoginExCMD : public CBaseDBCMD
{
public:
	CLoginExCMD();
	~CLoginExCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_LOGIN_EX ; }

protected:

	BOOL GetVersionNotice(UINT32 dwOldVersionID, DT_VERSION_DATA& stVersionInfo, DT_NOTICE_DATA& stNoticeInfo1, DT_NOTICE_DATA& stNoticeInfo2);	
	
	BOOL Auth(SGDP::ISDDBConnection* poDBConn,
		UINT8  byAuthType,
		TCHAR* pszDeviceID,
		TCHAR* pszNotifyID,
		TCHAR* pszUserName,
		TCHAR* pszUserPwd,
		UINT16 wCareerID,
		UINT32 dwPlayerID,
		UINT16 wZoneID,
		UINT8 byAuthMethod,
		TCHAR* pszIp);

private:

	TCHAR				m_aszZoneName[USERNAME_LEN];
	PKT_GTLS_LOGIN_EX_ACK	m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

