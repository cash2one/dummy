#ifndef _SAVEPRIVATEMSGLOG_CMD_H_
#define _SAVEPRIVATEMSGLOG_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "logic/friendsys/privatemsgmgr.h"




/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSavePrivateMsgLogCmd : public CBaseDBCMD
{
public:
    CSavePrivateMsgLogCmd();
    virtual ~CSavePrivateMsgLogCmd();
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
        return EDBCT_SAVEPRIVATEMSGLOG ;
    }

private:
    UINT16				m_wErrCode;
	CPrivateMsgList		m_dbPrivateMsgList;
};


#endif