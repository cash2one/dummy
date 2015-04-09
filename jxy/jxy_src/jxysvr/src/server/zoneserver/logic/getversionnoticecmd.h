

#ifndef _CGETVERSIONNOTICECMD_H_
#define _CGETVERSIONNOTICECMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetVersionNoticeCMD : public CBaseDBCMD
{
public:
	CGetVersionNoticeCMD();
	~CGetVersionNoticeCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GET_VERSION_NOTICE ; }

	static BOOL GetVersionNotice(SGDP::ISDDBConnection* poDBConn, UINT32 dwOldVersionID, DT_VERSION_DATA& stVersionInfo, DT_NOTICE_DATA& stNoticeInfo);
protected:

	
private:
	PKT_CLIZS_GET_VERSION_NOTICE_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

