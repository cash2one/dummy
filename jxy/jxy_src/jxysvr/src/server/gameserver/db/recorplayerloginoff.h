#ifndef _RECORD_PLAYER_LOGINOFF_H
#define _RECORD_PLAYER_LOGINOFF_H

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"

typedef struct tagPlayerLogin
{
    tagPlayerLogin()
    {
        dwPlayerID = 0;
        bLogin = FALSE;
    }

    UINT32 dwPlayerID;
    BOOL bLogin;
	string strIP;
} SPlayerLogin;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CRecordPlayerLoginoff: public CBaseDBCMD
{
public:
    CRecordPlayerLoginoff();
    ~CRecordPlayerLoginoff();
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

    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_LOGINOFFINFO;
    }
private:
    SPlayerLogin m_stLogin; //����ǳ���Ϣ
    string m_strSql; //ִ�е�SQL���ļ�¼
};

#endif