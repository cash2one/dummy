

#ifndef _PLAYUNBINDCMD_H_
#define _PLAYUNBINDCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include <protocol/server/protogsdb.h>


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CPlayUnBindCMD : public CBaseDBCMD
{
public:
    CPlayUnBindCMD();
    ~CPlayUnBindCMD();

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
        return EDBCT_UNBIND ;
    }

protected:
    BOOL UnBind(SGDP::ISDDBConnection* poDBConn, UINT8  byAuthType, UINT32 dwPlayID, TCHAR* pszUserName);

private:
    tagPKT_CLILS_UNBIND_ACK	m_stAck;
};

#endif //#ifndef _LOGINCMD_H_

