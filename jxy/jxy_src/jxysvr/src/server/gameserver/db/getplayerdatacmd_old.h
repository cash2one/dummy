

#ifndef _GETPLAYERDATACMDOLD_H_
#define _GETPLAYERDATACMDOLD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
//class CGetPlayerDataCMD_OLD : public CBaseDBCMD
//{
//public:
//	CGetPlayerDataCMD_OLD();
//	~CGetPlayerDataCMD_OLD();
//
//	/**
//	* @brief �첽ִ��SQL����
//	* @poDBConn �첽ִ��SQL�����Connection����
//	* @return VOID
//	*/						
//	VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection* poDBConn);
//
//	/**
//	* @brief ͬ��ִ��SQL������ص��߼�����
//	* @return VOID
//	*/
//    VOID SDAPI OnExecuted();
//
//
//	virtual VOID SetUserData(VOID* pUserData);
//
//public:
//	virtual EDBCmdType GetDBCmdType() { return EDBCT_GET_OLD ; }
//
//protected:
//
//	/**
//	* @brief ��ȡ�û���Ϣ
//	* @param poDBConn ���ݿ�����
//	* @param pUserType �û�����
//	* @param pUserName �û���
//	* @param pstData �������,��ȡ���û�����
//	* @return �����Ƿ��쳣��TRUE:�������쳣��FALSE�������쳣���쳣�������ڴ�
//	*/
//	BOOL GetData(SGDP::ISDDBConnection* poDBConn);
//
//	BOOL GetPlayerData(SGDP::ISDDBConnection* poDBConn);
//	BOOL GetPlayerPvpData(SGDP::ISDDBConnection* poDBConn);
//
//private:
//	SGetPlayerData* m_pstGetPlayerData;	
//};

#endif //#ifndef _GETPLAYERDATACMD_H_

