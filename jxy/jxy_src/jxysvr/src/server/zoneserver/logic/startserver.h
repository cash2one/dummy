

#ifndef _START_SERVER_CMD_H_
#define _START_SERVER_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


typedef struct _tagSTART_TIME
{
	UINT16		wZoneID;
	CHAR			aszTime[256];
	_tagSTART_TIME()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(_tagSTART_TIME));
	}
} tSTART_TIME;


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CStartServerCMD : public CBaseDBCMD
{
public:
    CStartServerCMD();
    ~CStartServerCMD();

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
        return EDBCT_STARTSERVICE ;
    }

protected:
    BOOL Start(SGDP::ISDDBConnection* poDBConn, tSTART_TIME* pstReq);

private:
	UINT16 m_wErrCode;
};

#endif //#ifndef _LOGINCMD_H_

