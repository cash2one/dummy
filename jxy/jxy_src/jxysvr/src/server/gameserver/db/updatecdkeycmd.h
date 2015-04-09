#ifndef _UPDATE_CD_KEY_CMD_H_
#define _UPDATE_CD_KEY_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "protocol/server/protocligs.h"


typedef struct tagUPDATE_CK_KEY
{
	tagUPDATE_CK_KEY()
	{ 
		memset(this, 0, sizeof(tagUPDATE_CK_KEY)); 
	}
	UINT64           qwActivityID; //�����
	TCHAR            aszSeriesNo[MAX_SERIES_NO_NUM]; //ϵ����
}UPDATE_CK_KEY, *pUPDATE_CK_KEY;



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CUpdateCdKeyCmd : public CBaseDBCMD
{
public:
	CUpdateCdKeyCmd();
	virtual ~CUpdateCdKeyCmd();
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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_UPDATE_CK_KEY ; }

private:
	UINT16			m_wErrCode;
	UPDATE_CK_KEY		m_stData;
	BOOL CUpdateCdKey(SGDP::ISDDBConnection* poDBConn);

};


#endif