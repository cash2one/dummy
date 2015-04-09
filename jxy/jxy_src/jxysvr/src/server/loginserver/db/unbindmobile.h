

#ifndef _UNBIND_MOBILE_CMD_H_
#define _UNBIND_MOBILE_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CUnBindMobileCMD : public CBaseDBCMD
{
public:
    CUnBindMobileCMD();
    ~CUnBindMobileCMD();

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
        return EDBCT_UNBINDMOBILE ;
    }

protected:
    BOOL UnBindMobile(SGDP::ISDDBConnection* poDBConn, PKT_CLILS_UNBIND_MOBILE_REQ* pstReq);
private:
	char		m_szMobile[MAX_MOBILE_LENGTH];
    PKT_CLILS_UNBIND_MOBILE_ACK m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

