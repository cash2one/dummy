

#ifndef _ACTIVITY_ENCOURAGE_CMD_H_
#define _ACTIVITY_ENCOURAGE_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "logic/activityencourage/activityencouragemgr.h"

using namespace std;



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CActivityEncourageCMD : public CBaseDBCMD
{
public:
    CActivityEncourageCMD();
    ~CActivityEncourageCMD();

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
        return EDBCT_ACTIVITYENCOURAGE ;
    }

    virtual VOID SetUserData(VOID* pUserData);

protected:
    BOOL GetActivityEncourageProp(SGDP::ISDDBConnection* poDBConn);

private:
    CActivityEncouragePropMap			m_mapActivityEncourageProp;
    BOOL								m_bGetDataSuccess;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

