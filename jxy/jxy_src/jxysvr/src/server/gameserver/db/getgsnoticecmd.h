

#ifndef _GET_GS_NOTICE_CMD_H_
#define _GET_GS_NOTICE_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include <protocommondata.h>

using namespace std;



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetGsNoticeCMD : public CBaseDBCMD
{
public:
	CGetGsNoticeCMD();
	~CGetGsNoticeCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GETGSNOTICE ; }

	virtual VOID SetUserData(VOID* pUserData);
protected:


private:
	DT_NOTICE_DATA_DB		m_stGsNoticeInfo; //������Ϣ
	UINT16				m_wZoneID;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

