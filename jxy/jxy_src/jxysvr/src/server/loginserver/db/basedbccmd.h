

#ifndef _BASEDBCMD_H_
#define _BASEDBCMD_H_

#include <sddb.h>
#include <protocol/server/protogsdb.h>
#include "sdframework.h"

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
	~CBaseDBCMD();

	/**
	* @brief �ͷ�DBCommand,�û�����ر�֤��DBCommand���ݱ���ȫ�ͷ�
	* @return VOID
	*/
    VOID SDAPI Release();

/////////////////////////////////////////////////////////////////////

	/**
	* @brief �����û��ض�����
	* @param pUserData ���õ��û�����
	* @param dwLen ���õ��û����ݳ���
	* @param dwTransID ���õ�TransID
	*/
	VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);

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
	CHAR    m_pUserData[10240];
	INT32   m_dwDataLen;
	
    volatile BOOL m_bSuccess;		///< ���ݿ�����ɹ���־

    volatile UINT16 m_wErrCode;      ///< ��ǰִ�еĲ����Ĵ�����

	VOID*   m_pMiddleData;			///< �м������ʱ����

	UINT32 m_dwTransID;
};

#endif //#ifndef _BASEDBCMD_H_

