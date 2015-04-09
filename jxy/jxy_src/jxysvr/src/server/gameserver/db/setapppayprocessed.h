#ifndef _SET_APP_PAY_PROCESSED_H_
#define _SET_APP_PAY_PROCESSED_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>
#include "thirdparty/jsoncpp-src/include/json/json.h"

#define STR_GLOBAL_TABLE_NAME "global_amount"

//ƻ�������������
struct SAppPayProcessed
{
	SAppPayProcessed()
	{
		dwPlayerID=0;
		dwGold=0;
		dwErrorCode=0;
		dwQueryPlayer=0;
		bBuyEnv = 0;
		strTableName = "";
		strOrderID = "";
		dwRMB = 0;
	}
	UINT32	dwPlayerID;		//���ID
	UINT32	dwGold;			//��ֵ��
	UINT32	dwErrorCode;		//ƻ�����صĴ�����
	string	strTableName;		//�÷���Ӧ�����ݿ����
	string	strOrderID;		//������
	UINT32	dwQueryPlayer;	//��������
	BOOL		bBuyEnv;			//���͵ĵ�ַ��Ϣ
	UINT32	dwRMB;			//���Է�Ϊ��λ��
};

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetAppPayProcessed : public CBaseDBCMD
{
public:
	CSetAppPayProcessed();
	virtual ~CSetAppPayProcessed();
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

	//��������
	virtual VOID SetUserData(VOID* pUserData);

public:
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SETPAYPPROCESSED ; }

private:
	BOOL SetPayProcessed(SGDP::ISDDBConnection* poDBConn);
private:
	SAppPayProcessed m_stAppPayProcessed; //������������Ϣ
	BOOL m_bSuccess; //�Ƿ�ɹ�
};


#endif