

#ifndef _SMSUSERMGR_H_
#define _SMSUSERMGR_H_

#include "smsuser.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdtype.h>
#include <sdidpool.h>
#include <map>
#include <protocol/server/protoclizs.h>

using namespace std ;
using namespace SGDP;


#define MAX_USER	10000

typedef map<string , CSmsUser*> CSmsID2UserMap; //keyΪCUser��userID
typedef CSmsID2UserMap::iterator CSmsID2UserMapItr;

/**
* @brief �ͻ������ӹ�����
* ���������Ϸ�����������пͻ�������
*/
class CSmsUserMgr
{
public:
    DECLARE_SINGLETON(CSmsUserMgr)

public:
    BOOL			Init();
    //�����û����������ڷ��ش����û�
    BOOL			CreateUser(string strKey, UINT32 dwUserID, TCHAR* pszUserName, TCHAR* pszMobile, TCHAR* pszVerCode);

	BOOL			CkUser(TCHAR *pszMobile, UINT8 abyToken[MAX_RESET_PASSWD_TOKEN_NUM], UINT16 &wCountdown);

	BOOL			CkUser(string strKey, TCHAR* pszVerCode, TCHAR *pszUserName);

	BOOL			CkAuth(string strKey, UINT32 &dwUserID);

    VOID			CkUserDisconnect();

protected:
    CSmsUserMgr();
    ~CSmsUserMgr();
protected:

private:
    //CUser�����
    CSDObjectPool<CSmsUser, CSDMutex>		m_oUserPool;
    //�û���������
    CSmsID2UserMap						m_mapSmsID2User;
    CSDMutex								m_oMutex	;
};



#endif //#ifndef _SDF_OBJFACTORY_H_

