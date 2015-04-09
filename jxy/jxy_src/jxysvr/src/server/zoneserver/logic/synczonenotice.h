

#ifndef _SYNCZONENOTICECMD_H_
#define _SYNCZONENOTICECMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"
#include "dbmgr.h"

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSyncZoneNoticeCMD : public CBaseDBCMD
{
public:
	CSyncZoneNoticeCMD();
	~CSyncZoneNoticeCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SYNC_ZONENOTICE ; }

protected:

	BOOL CkZone(SGDP::ISDDBConnection* poDBConn);
	BOOL CkVersionNotice(SGDP::ISDDBConnection* poDBConn);
	BOOL CkVersionNotice2(SGDP::ISDDBConnection* poDBConn);
	BOOL CkResVer(SGDP::ISDDBConnection* poDBConn);

private:
	CZoneInfoVec			m_vecZoneInfo;
	SVersionNoticeInfo	m_stVersionNoticeInfo;
	SVersionNoticeInfo2	m_stVersionNoticeInfo2;
	CVerID2CliVerInfoMap	m_mapVerID2CliVerInfo;
};

#endif //#ifndef _LOGINCMD_H_

