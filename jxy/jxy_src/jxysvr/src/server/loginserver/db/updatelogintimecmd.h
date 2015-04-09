#ifndef		UpdateLoginTimeCMD_H
#define 	UpdateLoginTimeCMD_H

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/

class CUpdateLoginTimeCMD:public CBaseDBCMD
{
public:
	CUpdateLoginTimeCMD();
	~CUpdateLoginTimeCMD();

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

	VOID SetParam(UINT32 dwUserID, UINT16 wZoneID) {  m_dwUserID = dwUserID; m_wZoneID =  m_wZoneID; }
protected:


	BOOL UpdateLoginTime(SGDP::ISDDBConnection* poDBConn);//������������¼������Ϣ

private:
	UINT32 m_dwUserID;
	UINT16 m_wZoneID;
};

#endif //#ifndef _LOGINCMD_H_

