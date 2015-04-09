

#ifndef _RESET_PASSWD_MOBILE_CMD_H_
#define _RESET_PASSWD_MOBILE_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CResetPasswdMobileCMD : public CBaseDBCMD
{
public:
    CResetPasswdMobileCMD();
    ~CResetPasswdMobileCMD();

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
        return EDBCT_RESETPASSWDMOBILE ;
    }

protected:
    BOOL CheckMobile(SGDP::ISDDBConnection* poDBConn, PKT_CLIZS_RESET_PASSWD_MOBILE_REQ* pstReq);

private:
	UINT32							m_dwUserID;
	TCHAR							m_aszUserName[USERNAME_LEN]; //�û���
	PKT_CLIZS_RESET_PASSWD_MOBILE_ACK	m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

