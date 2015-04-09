

#ifndef _TWO_DAYS_NOT_ONLINE_NOTICEINFO_H_
#define _TWO_DAYS_NOT_ONLINE_NOTICEINFO_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"





/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CTwoDaysNotOnlineNoticeInfoCMD : public CBaseDBCMD
{
public:
    CTwoDaysNotOnlineNoticeInfoCMD();
    ~CTwoDaysNotOnlineNoticeInfoCMD();

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
        return EDBCT_TWO_DAYS_NOT_ONLINE_NOTICE_INFO ;
    }

private:
	CPlayerNotifyInfoMap m_mapPlayerNotifyInfo;
};

#endif //#ifndef _LOGINCMD_H_

