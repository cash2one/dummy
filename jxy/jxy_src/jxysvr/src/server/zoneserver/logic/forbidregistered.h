

#ifndef _FORBID_REGISTERED_CMD_H_
#define _FORBID_REGISTERED_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


typedef struct _tagForbidRegistered
{
	UINT32		dwUserID;
	TCHAR		aszDeviceID[DEVICEID_LEN]; //�豸��
	_tagForbidRegistered()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(_tagForbidRegistered));
	}
}tForbidRegistered ;


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CForbidRegisteredCMD : public CBaseDBCMD
{
public:
    CForbidRegisteredCMD();
    ~CForbidRegisteredCMD();

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
        return EDBCT_FORBID_REGISTERED ;
    }

protected:
    BOOL ForbidRegistered(SGDP::ISDDBConnection* poDBConn, tForbidRegistered* pstReq);

private:
	UINT16 m_wErrCode;
};

#endif //#ifndef _LOGINCMD_H_

