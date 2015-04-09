

#ifndef _CHAGNE_PWD_CMD_H_
#define _CHAGNE_PWD_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CChangePwdCMD : public CBaseDBCMD
{
public:
    CChangePwdCMD();
    ~CChangePwdCMD();

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
        return EDBCT_CHANGE_PWD ;
    }

protected:
    BOOL ChangePwd(SGDP::ISDDBConnection* poDBConn, PKT_GTLS_CHANGE_PWD_REQ* pstReq);
private:
    PKT_CLILS_CHANGE_PWD_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

