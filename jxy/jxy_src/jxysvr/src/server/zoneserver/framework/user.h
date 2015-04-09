

#ifndef _SDF_CLISESSION_H_
#define _SDF_CLISESSION_H_

#include <sdtime.h>
#include <sdstring.h>
#include <map>
#include <protocol/server/protocommondata.h>


using namespace std ;




class CUserMgr;
/**
* @brief �ͻ���������
* ���յ����ػ㱨���пͻ��˽���ʱ�������ʵ��
* ���յ����ػ㱨���пͻ����뿪ʱ�ͷŸ���ʵ��
*/
class CUser
{
	friend class CUserMgr;
public:
    CUser();
    ~CUser();
public:
	UINT32		GetUserID() { return m_dwUserID; }
	UINT8		GetAuthType() { return m_byAuthType; }
	UINT8		GetAuthMethod() { return m_byAuthMethod; }
	TCHAR*		GetUserName() { return m_szUserName; }
	TCHAR*		GetDeviceID() { return m_szDeviceID; }
	TCHAR*		GetNickName() { return m_szNickName; }
	TCHAR*		GetPasswd() { return m_szPasswd; }

	void			SetPasswd(TCHAR* pszPasswd);
	BOOL			CkUserDisconnect();
	VOID			SetUserProp(UINT32 dwUserID, UINT8  byAuthType, UINT8  byAuthMethod, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNickName);
	BOOL			CkUser(UINT32 &dwUserID, UINT8  byAuthType, UINT8  byAuthMethod, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNickName);
private:
	
	UINT32			m_dwUserID;//�û�ID
	UINT8			m_byAuthType;
	UINT8			m_byAuthMethod;
	TCHAR			m_szUserName[USERNAME_LEN];
	TCHAR			m_szPasswd[USERPWD_LEN];
	TCHAR			m_szNickName[USERNAME_LEN];
	TCHAR			m_szDeviceID[DEVICEID_LEN];
	UINT64			m_qwLastRecvMsgTime; //�ϴ��յ���Ϣʱ��
};


#endif //#ifndef _SDF_CLISESSION_H_

