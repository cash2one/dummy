#ifndef _SET_TONGBU_PAY_PROCESSED_H_
#define _SET_TONGBU_PAY_PROCESSED_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>

#define STR_GLOBAL_TABLE_NAME "global_amount"

//ͬ�������������
struct STongBuPayProcessed
{
    STongBuPayProcessed()
    {
        dwPlayerID = 0;
        dwGold = 0;
        wErrCode = 0;
        dwSessionID = 0;
		dwRMB = 0;
    }
    UINT32 dwPlayerID;	//���ID
    UINT32 dwGold;		//��ֵԪ����
    string strTableName;	//�÷���Ӧ�����ݿ����
    string strOrderID;
    string strSource;
    string strPartner;
    UINT16 wErrCode;
    UINT32 dwSessionID;
	UINT32 dwRMB;			//��ֵ�����Է�Ϊ��λ��

};

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetTongBuPayProcessed : public CBaseDBCMD
{
public:
    CSetTongBuPayProcessed();
    virtual ~CSetTongBuPayProcessed();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SETTONGBUPAYPPROCESSED ; }

private:
    BOOL SetPayProcessed(SGDP::ISDDBConnection* poDBConn);
private:
    STongBuPayProcessed m_stPayProcessed; //������������Ϣ
};


#endif