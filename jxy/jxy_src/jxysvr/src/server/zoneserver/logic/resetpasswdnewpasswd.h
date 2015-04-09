

#ifndef _RESET_PASSWD_NEWPASSWD_CMD_H_
#define _RESET_PASSWD_NEWPASSWD_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CResetPasswdNewPassCMD : public CBaseDBCMD
{
public:
    CResetPasswdNewPassCMD();
    ~CResetPasswdNewPassCMD();

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
        return EDBCT_RESETPASSWDNEWPASSWD ;
    }

protected:
    BOOL NewPasswd(SGDP::ISDDBConnection* poDBConn, PKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ* pstReq);

private:
	PKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

