

#ifndef _UNBIND_H_
#define _UNBIND_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CUnBindDeviceCMD : public CBaseDBCMD
{
public:
    CUnBindDeviceCMD();
    ~CUnBindDeviceCMD();

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

public:
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_UNBIND_DEVICE ;
    }

protected:
    BOOL UnBind(SGDP::ISDDBConnection* poDBConn, PKT_CLIZS_UN_BIND_DEVICE_REQ* pstReq);
private:
    PKT_CLIZS_UN_BIND_DEVICE_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

