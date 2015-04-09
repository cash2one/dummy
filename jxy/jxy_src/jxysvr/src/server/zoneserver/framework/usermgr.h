

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

typedef map<string , CUser*> CSessionID2UserMap; //keyΪCUser��SessionID
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
    BOOL			CreateUser(UINT32 dwUserID, UINT8  byAuthType, UINT8  byAuthMethod, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNickName);

    BOOL			CkUser(UINT32 &dwUserID, UINT8  byAuthType, UINT8  byAuthMethod, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNickName);

    VOID			CkUserDisconnect();

    void			ReleaseUser(UINT32 dwUserID);

private:
    VOID			_ReleaseUser(CUser* poUser);
    CUser*		_FindUser(string strkey);

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

