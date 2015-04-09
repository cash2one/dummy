

#ifndef _LOGOUT_H_
#define _LOGOUT_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CLogoutCMD : public CBaseDBCMD
{
public:
    CLogoutCMD();
    ~CLogoutCMD();

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
        return EDBCT_LOGOUT ;
    }

protected:
    BOOL Logout(SGDP::ISDDBConnection* poDBConn, PKT_CLILS_LOGOUT_REQ* pstReq);
private:
    PKT_CLILS_LOGOUT_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

