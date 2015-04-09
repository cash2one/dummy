#ifndef _APP_PAY_MGR_H_
#define _APP_PAY_MGR_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>

//��ҵĳ�ֵ��Ϣ��ĿǰΪappstore��ֵ��
struct SPayInfo
{
	SPayInfo()
	{
		dwPlayerID=0;
		dwUserID=0;
		dwZoneID=0;
		dwPlayerLevel=0;
		dwQueryPlayerID=0;
		strOrderID = "";
		strTableName = "";
		strDeviceID = "";
		strReceipt = "";

	}

	UINT32 dwPlayerID; //���ID
	UINT32 dwQueryPlayerID; //��������ID
	string strOrderID; //������
	UINT32 dwUserID; //�û�ID
	UINT32 dwZoneID; //����ID
	string strSource; //Դ�����Ժδ�
	UINT32 dwPlayerLevel; //��ҵȼ�
	string strTableName; //��ֵ�������
	string strDeviceID;//�豸��
	string strReceipt; //app���ظ��ͻ��˵�receipt������ƻ��������������֤
};

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetAppPayInfo : public CBaseDBCMD
{
public:
	CSetAppPayInfo();
	virtual ~CSetAppPayInfo();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SETPAYINFO ; }

private:
	BOOL SaveAppPayInfo(SGDP::ISDDBConnection* poDBConn);
private:
	SPayInfo m_stPayInfo; //��ֵ��Ϣ
	BOOL m_bInsertSuccess; //�Ƿ�ɹ�
	BOOL m_bRepeat; //�Ƿ��ظ�����
	UINT32 m_dwAlreadyPayGoldValue; //��ֵԪ����,Ԫ��Ϊ��λ
};



#endif