#ifndef _GET_PLAYER_CONSUME_H_
#define _GET_PLAYER_CONSUME_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "protocol/server/protocommondata.h"


typedef struct _tagGetPlayerConsume
{
    UINT32 dwPlayerID;
    string strStartDate;
    string strEndDate;
} DT_GetPlayerConsume;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetPlayerConsume : public CBaseDBCMD
{
public:
    CGetPlayerConsume();
    virtual ~CGetPlayerConsume();
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

    //��������
    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_GET_PLAYER_CONSUME ;
    }

private:
	DT_GetPlayerConsume					m_stGetPlayerConsume;
    DT_PLAYER_TODAY_CONSUME_DATA			m_stDT_PLAYER_TODAY_CONSUME_DATA;

};

#endif