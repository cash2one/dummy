

#ifndef _UNBIND_CHECK_VER_CODE_CMD_H_
#define _UNBIND_CHECK_VER_CODE_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CUnBindCheckVerCodeCMD : public CBaseDBCMD
{
public:
    CUnBindCheckVerCodeCMD();
    ~CUnBindCheckVerCodeCMD();

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
        return EDBCT_UNBINDCHECKVERCODE ;
    }

protected:
    BOOL CheckVerCode(SGDP::ISDDBConnection* poDBConn, PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ* pstReq);
private:
    PKT_CLILS_UNBIND_CHECK_VER_CODE_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

