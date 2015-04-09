

#ifndef _GET_PLAYER_NOTITY_INFO_H_
#define _GET_PLAYER_NOTITY_INFO_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"






/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetPlayerNotifyInfoCMD : public CBaseDBCMD
{
public:
    CGetPlayerNotifyInfoCMD();
    ~CGetPlayerNotifyInfoCMD();

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
        return EDBCT_GET_PLAYER_NOTIFY_INFO ;
    }

private:
	CPlayerNotifyInfoMap m_mapPlayerNotifyInfo;
};

#endif //#ifndef _LOGINCMD_H_

