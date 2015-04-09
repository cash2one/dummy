

#ifndef _SAVEFACTIONDATACMD_H_
#define _SAVEFACTIONDATACMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playersavemgr.h>
#include <string>
#include <vector>
using namespace std;
using namespace  SGDP;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CSaveFactionDataCMD : public CBaseDBCMD
{
public:
	CSaveFactionDataCMD();
	~CSaveFactionDataCMD();

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
        return EDBCT_FACTION ;
    }

protected:
	///////////////////////////////////////////////////////////////////////////////////////////////
	BOOL	SaveData(ISDDBConnection* poDBConn);//����
	
    BOOL GetSql(SGDP::ISDDBConnection* poDBConn, vector<string>&vecSql );
	

private:
	DT_FACTION_DATA m_stDT_FACTION_DATA;

};

#endif //#ifndef _GETPLAYERDATACMD_H_

