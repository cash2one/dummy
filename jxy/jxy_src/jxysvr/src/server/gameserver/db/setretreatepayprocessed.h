#ifndef _SET_RECREATE_PAY_PROCESSED_H_
#define _SET_RECREATE_PAY_PROCESSED_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>


//�Լ������������
struct SRecreatePayProcessed
{
    SRecreatePayProcessed()
    {
        wZoneID = 0;
        dwPlayerID = 0;
        dwGold = 0;
        dwRMB = 0;
        dwSessionID = 0;
        bySandBoxFlag = 0;
        byVipLevel = 0;
		dwPayID = 0;
    }
    UINT16	wZoneID;
    UINT32	dwPlayerID; //���ID
    UINT32	dwGold; //Ԫ����
    string	strOrderID;
    string	strComment;
    UINT32	dwRMB;
    UINT8	bySandBoxFlag;
    UINT32	dwSessionID;
    UINT8	byVipLevel;
	UINT32	dwPayID;
};



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetRecreatePayProcessed : public CBaseDBCMD
{
public:
    CSetRecreatePayProcessed();
    virtual ~CSetRecreatePayProcessed();
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
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_SETRECREATEPAYPROCESSED ;
    }

private:
    BOOL SetPayProcessed(SGDP::ISDDBConnection* poDBConn);
private:
    vector<SRecreatePayProcessed> m_vecRecreatePayProcessed; //������������Ϣ
    BOOL m_bSuccess; //�Ƿ�ɹ�
};


#endif