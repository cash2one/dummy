

#ifndef _SMSUSER_H_
#define _SMSUSER_H_

#include <sdtime.h>
#include <sdstring.h>
#include <map>
#include <protocol/server/protocommondata.h>


using namespace std ;


//���ų�ʱʱ��
#define MAX_MOBILE_TIME_OUT	60
#define MAX_MOBILE_DISCONNECT 	3600

class CSmsUserMgr;
/**
* @brief �ͻ���������
* ���յ����ػ㱨���пͻ��˽���ʱ�������ʵ��
* ���յ����ػ㱨���пͻ����뿪ʱ�ͷŸ���ʵ��
*/
class CSmsUser
{
	friend class CSmsUserMgr;
public:
    CSmsUser();
    ~CSmsUser();
public:
	UINT32		GetUserID() { return m_dwUserID; }
	TCHAR	*	GetUserName(){return m_szUserName;}
	TCHAR	*	GetVerCode(){return m_szVerCode;}
	TCHAR	*	GetMobile(){return m_szMobile;}
	BOOL			CkUserDisconnect();
	BOOL			SetUserProp(UINT32 dwUserID, TCHAR* pszUserName, TCHAR* pszMobile, TCHAR* pszVerCode);
	BOOL			CkUser(TCHAR* pszVerCode, TCHAR *pszUserName);
	BOOL			GetAuth() { return m_bAuth; }

	BOOL			CkUser(UINT16 &wCountdown);
private:
	BOOL				m_bAuth;
	UINT32			m_dwUserID;//�û�ID
	TCHAR			m_szUserName[USERNAME_LEN];
	TCHAR			m_szMobile[MAX_MOBILE_LENGTH];
	TCHAR			m_szVerCode[MAX_MOBILE_LENGTH];
	UINT64			m_qwRecvMsgTime;		//�ϴ��յ���Ϣʱ��
	UINT64			m_qwCreateTime;		//����ʱ��
};


#endif //#ifndef _SDF_CLISESSION_H_

