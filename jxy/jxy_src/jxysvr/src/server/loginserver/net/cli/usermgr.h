

#ifndef _USERMGR_H_
#define _USERMGR_H_

#include "user.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdtype.h>
#include <sdidpool.h>
#include <map>

using namespace std ;
using namespace SGDP;


#define MAX_USER	10000

typedef map<UINT32 , CUser*> CSessionID2UserMap; //keyΪCUser��SessionID
typedef CSessionID2UserMap::iterator CSessionID2UserMapItr;

/**
* @brief �ͻ������ӹ�����
* ���������Ϸ�����������пͻ�������
*/
class CUserMgr
{
public:
    DECLARE_SINGLETON(CUserMgr)

public:
    BOOL			Init();
    //�����û����������ڷ��ش����û�
	BOOL			CreateUser(UINT32 dwUserID, UINT8  byAuthType, UINT8  byAuthMethod, UINT32 dwPlayerID, UINT16 wCareerID, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNotifyID, TCHAR *pszZoneName, UINT16 wZoneID, UINT32 dwCliVer);
	
	UINT16		CkUser(UINT32 &dwUserID, TCHAR *pszZoneName, UINT8  byAuthType, UINT8  byAuthMethod, UINT32 dwPlayerID, UINT16 wCareerID, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNotifyID, UINT16 wZoneID, UINT32 dwCliVer);

	VOID			CkUserDisconnect();

	VOID			ChangePwd(UINT32 dwUserID, TCHAR* pszPasswd);
private:
	VOID			ReleaseUser(CUser* poUser);

	CUser*		FindUser(UINT32 dwPlayerID);



protected:
    CUserMgr();
    ~CUserMgr();
protected:

private:
    //CUser�����
    CSDObjectPool<CUser, CSDMutex>		m_oUserPool;
    //�û���������
    CSessionID2UserMap				m_mapPlayerID2User;
	CSDMutex							m_oMutex	;
};



#endif //#ifndef _SDF_OBJFACTORY_H_

