#ifndef _SET_MY_PAY_PROCESSED_H_
#define _SET_MY_PAY_PROCESSED_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>


//�Լ������������
struct SMyPayProcessed
{
	SMyPayProcessed()
	{
		wZoneID = 0;
		dwPlayerID=0;
		dwGivenGold=0;
		wErrCode = 0;
		dwRMB = 0;
		dwSessionID = 0;
		bySandBoxFlag = 0;
	}
	UINT16 wZoneID;
	UINT32 dwPlayerID;	//���ID
	UINT32 dwGivenGold;	//Ԫ����
	string strOrderID;	
	string strComment;
	UINT32 dwRMB;			//��λΪ��
	UINT8  bySandBoxFlag;
	UINT32 dwSessionID;
	UINT16 wErrCode;
};



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetMyPayProcessed : public CBaseDBCMD
{
public:
	CSetMyPayProcessed();
	virtual ~CSetMyPayProcessed();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SETMYPAYPPROCESSED ; }

private:
	BOOL SetPayProcessed(SGDP::ISDDBConnection* poDBConn);
private:
	SMyPayProcessed m_stMyPayProcessed; //������������Ϣ
	BOOL m_bSuccess; //�Ƿ�ɹ�
};


#endif