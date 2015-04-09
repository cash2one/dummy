

#ifndef _BASEDBCMD_H_
#define _BASEDBCMD_H_


#include "dbmgr.h"
#include <sddb.h>

#define SAVE_USER_DATA			10000

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CBaseDBCMD: public SGDP::ISDDBCommand
{
public:
	CBaseDBCMD();
	virtual ~CBaseDBCMD();

	/**
	* @brief �ͷ�DBCommand,�û�����ر�֤��DBCommand���ݱ���ȫ�ͷ�
	* @return VOID
	*/
    VOID SDAPI Release();

/////////////////////////////////////////////////////////////////////

	/**
	* @brief �����û��ض�����,�ص������SetUserData
	* @param pUserData ���õ��û�����
	* @param dwTransID ���õ�TransID
	*/
	VOID SetUserData(VOID* pUserData, UINT32 dwTransID );
	virtual VOID SetUserData(VOID* pUserData) = 0;
	
public:
	virtual EDBCmdType GetDBCmdType() = 0;

protected:

	/**
	* @brief ���ͻ�����Ϣ
	* @param pBuf ��Ҫ����������
	* @return VOID
	*/
	VOID ResponseMsg(UINT16 wMsgID,const CHAR* pBuf);


protected:
	
    volatile BOOL m_bSuccess;		///< ���ݿ�����ɹ���־    
	UINT32 m_dwTransID;
};

#endif //#ifndef _BASEDBCMD_H_

