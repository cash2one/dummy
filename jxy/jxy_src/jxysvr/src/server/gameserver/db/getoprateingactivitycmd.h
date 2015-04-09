

#ifndef _GET_OPRATEINGACTIVITY_CMD_H_
#define _GET_OPRATEINGACTIVITY_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <protocol/server/protocligs.h>
using namespace std;


//��Ӫ�����
struct SOprateingActivityProp
{
	DT_OPERATING_ACTIVITY_DATA stProtData;//Э����Ϣ
	UINT64	qwStartTime;				//����ʱ��
	UINT64	qwEndTime;					//����ʱ��
	BOOL	bOpenSoulAty;				// ����ս��
	//UINT8	byTowerIdx;					//����Idx
	//UINT8	byInstanceIdx;				//����Idx
	//UINT8	byInstanceIdx2;				//����Idx2
	//UINT8	byInstanceIdx3;				//����Idx3

};

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetOprateingActivityCMD : public CBaseDBCMD
{
public:
	CGetOprateingActivityCMD();
	~CGetOprateingActivityCMD();

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
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GETOPRATEINGACTIVITY ; }

	virtual VOID SetUserData(VOID* pUserData);
protected:


private:
	SOprateingActivityProp		m_stOprateingActivityProp;
	UINT16						m_wZoneID;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

