

#ifndef _GETPLAYERDATACMD2_H_
#define _GETPLAYERDATACMD2_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetPlayerDataCMD2 : public CBaseDBCMD
{
public:
	CGetPlayerDataCMD2();
	~CGetPlayerDataCMD2();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GET2 ; }

protected:

	/**
	* @brief ��ȡ�û���Ϣ
	* @param poDBConn ���ݿ�����
	* @param pUserType �û�����
	* @param pUserName �û���
	* @param pstData �������,��ȡ���û�����
	* @return �����Ƿ��쳣��TRUE:�������쳣��FALSE�������쳣���쳣�������ڴ�
	*/
	BOOL GetData(SGDP::ISDDBConnection* poDBConn);

private:
	SGetPlayerData2* m_pstGetPlayerData;	
};

#endif //#ifndef _GETPLAYERDATACMD2_H_

