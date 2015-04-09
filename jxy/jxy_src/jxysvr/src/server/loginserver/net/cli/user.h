

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
	UINT32		GetUserSessionID() { return m_dwPlayerID; }
	UINT32		GetPlayerID() { return m_dwPlayerID; }
	UINT32		GetUserID() { return m_dwUserID; }
	UINT16		GetCareerID() { return m_wCareerID; }

	TCHAR*		GetUserName() { return m_szUserName; }
	TCHAR*		GetDeviceID() { return m_szDeviceID; }
	TCHAR*		GetNotifyID() { return m_szNotifyID; }
	UINT16		GetZoneID() { return m_wZoneID; }
	UINT32		GetCliVer() { return m_dwCliVer; }

	BOOL			CkUserDisconnect();

	VOID			SetUserProp(UINT32 dwUserID, UINT8  byAuthType, UINT8  byAuthMethod, UINT32 dwPlayerID, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNotifyID, TCHAR *pszZoneName, UINT16 wCareerID, UINT16 wZoneID, UINT32 dwCliVer);
	UINT16		CkUser(UINT32 &dwUserID, TCHAR *pszZoneName, UINT8  byAuthType, UINT8  byAuthMethod, UINT32 dwPlayerID, TCHAR* pszUserName, TCHAR* pszPasswd, TCHAR* pszDeviceID, TCHAR* pszNotifyID, UINT16 wCareerID, UINT16 wZoneID, UINT32 dwCliVer);
	VOID			ChangePwd(TCHAR* pszPasswd);
private:
	
	UINT32			m_dwUserID;//�û�ID
	UINT32			m_dwPlayerID;//�û��ỰID��PlayerID
	UINT16			m_wCareerID;//ְҵID���´����û���Ч
	UINT16			m_wZoneID;//��ID
	UINT8			m_byAuthType;
	UINT8			m_byAuthMethod;
	UINT32			m_dwCliVer;//�ͻ��˰汾
	TCHAR			m_szUserName[USERNAME_LEN];
	TCHAR			m_szPasswd[USERPWD_LEN];
	TCHAR			m_szDeviceID[DEVICEID_LEN];
	TCHAR			m_szNotifyID[NOTIFYID_LEN];
	TCHAR			m_aszZoneName[USERNAME_LEN];
	UINT64			m_qwLastRecvMsgTime; //�ϴ��յ���Ϣʱ��

};


#endif //#ifndef _SDF_CLISESSION_H_

