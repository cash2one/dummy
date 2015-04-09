

#ifndef _BASEDBCMD_H_
#define _BASEDBCMD_H_

#include "sdframework.h"
#include <sddb.h>
#include "dbmgr.h"
#include "protocol/server/protogsdb.h"

#define SAVE_USER_DATA			10000


#include <map>
using namespace std;


struct SPlayerNotifyInfo
{
	SPlayerNotifyInfo()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(SPlayerNotifyInfo));
	}
	UINT32       dwPlayerID;
	UINT8		byZoneID;
	UINT8		byCareerID;
	UINT8		byAuthType;	//��֤����
	UINT8		byAction;	//0��ʾû�м�¼
	CHAR			aszToken[64];
	CHAR			aszUserName[64];
};

typedef map<UINT32, SPlayerNotifyInfo> CPlayerNotifyInfoMap;
typedef CPlayerNotifyInfoMap::iterator CPlayerNotifyInfoMapItr;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CBaseDBCMD: public SGDP::ISDDBCommand
{
public:
	CBaseDBCMD();
	~CBaseDBCMD();

	/**
	* @brief �ͷ�DBCommand,�û�����ر�֤��DBCommand���ݱ���ȫ�ͷ�
	* @return VOID
	*/
    VOID SDAPI Release();

/////////////////////////////////////////////////////////////////////

	/**
	* @brief �����û��ض�����
	* @param pUserData ���õ��û�����
	* @param dwLen ���õ��û����ݳ���
	* @param dwTransID ���õ�TransID
	*/
	VOID SetUserData(const VOID* pUserData, const UINT32 dwLen, const UINT32 dwTransID);

	
public:
	virtual EDBCmdType GetDBCmdType() = 0;

protected:

	/**
	* @brief ���ͻ�����Ϣ
	* @param pBuf ��Ҫ����������
	* @return VOID
	*/
	VOID ResponseMsg(UINT16 wMsgID,const CHAR* pBuf);


protected:
	CHAR    m_pUserData[65535];
	INT32   m_dwDataLen;
	
    volatile BOOL m_bSuccess;		///< ���ݿ�����ɹ���־

	UINT32 m_dwTransID;
};

#endif //#ifndef _BASEDBCMD_H_

