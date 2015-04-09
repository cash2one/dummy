#ifndef _TONGBU_PAY_MGR_H_
#define _TONGBU_PAY_MGR_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>

//��ҵ�ͬ����ֵ��Ϣ
struct STongBuPayInfo
{
	STongBuPayInfo()
	{
		dwPlayerID=0;
		dwUserID=0;
		dwZoneID=0;
		dwPlayerLevel=0;
		bSuccess = FALSE;
	}

	UINT32 dwPlayerID; //���ID
	string strOrderID; //������
	UINT32 dwUserID; //�û�ID
	UINT32 dwZoneID; //����ID
	UINT32 dwPlayerLevel; //��ҵȼ�
	string strSource; //Դ�����Ժδ�
	string strTableName; //��ֵ�������
	BOOL   bSuccess;
};

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetTongBuPayInfo : public CBaseDBCMD
{
public:
	CSetTongBuPayInfo();
	virtual ~CSetTongBuPayInfo();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SETTONGBUPAYINFO ; }

private:
	BOOL SaveTongBuPayInfo(SGDP::ISDDBConnection* poDBConn);
private:
	STongBuPayInfo m_stPayInfo; //��ֵ��Ϣ
};



#endif