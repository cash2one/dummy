

#ifndef _SAVECOURAGEDATACMD_H_
#define _SAVECOURAGEDATACMD_H_

#include "basedbccmd.h"
#include <protocommondata.h>

using namespace  SGDP;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSaveCourageDataCMD : public CBaseDBCMD
{
public:
    CSaveCourageDataCMD();
    ~CSaveCourageDataCMD();

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
        return EDBCT_SAVE_COURAGE_DATA ;
    }

protected:
    ///////////////////////////////////////////////////////////////////////////////////////////////
    BOOL	SaveData(ISDDBConnection* poDBConn);//����



private:
    DT_COURAGE_GROUP_DATA_LST m_stDT_COURAGE_GROUP_DATA_LST;

};

#endif //#ifndef _GETPLAYERDATACMD_H_

