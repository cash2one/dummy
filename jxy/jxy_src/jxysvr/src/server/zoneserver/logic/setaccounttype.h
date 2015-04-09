

#ifndef _SET_ACCOUNT_TEST_CMD_H_
#define _SET_ACCOUNT_TEST_CMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protoclils.h"


typedef struct _tagSetAccountType
{
	UINT32		dwPlayerID;
	UINT8		byType;
	_tagSetAccountType()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(_tagSetAccountType));
	}
} tSetAccountType;


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSetAccountTypeCMD : public CBaseDBCMD
{
public:
    CSetAccountTypeCMD();
    ~CSetAccountTypeCMD();

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
        return EDBCT_SETACCOUNTTYPE ;
    }

protected:
    BOOL SetAccountType(SGDP::ISDDBConnection* poDBConn, tSetAccountType* pstReq);

private:
	UINT16 m_wErrCode;
};

#endif //#ifndef _LOGINCMD_H_

