

#ifndef _CSaveFeedBackCMD_H_
#define _CSaveFeedBackCMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclizs.h"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSaveFeedBackCMD : public CBaseDBCMD
{
public:
    CSaveFeedBackCMD();
    ~CSaveFeedBackCMD();

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
        return EDBCT_SAVE_FEED_BACK ;
    }
};

#endif //#ifndef _LOGINCMD_H_

