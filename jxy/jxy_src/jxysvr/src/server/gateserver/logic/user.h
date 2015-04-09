#ifndef  _USER_H
#define _USER_H

#include <protocol/server/protocommondata.h>
#include <protocol/server/protoclils.h>

/**
* @brief �û�������Ϣ
*/

class CGTClient;
class CUserMgr;
class CUser
{
	friend class CUserMgr;
public:
	CUser();
	virtual ~CUser();
	UINT32		GetUserSessionID() { return m_dwPlayerID; }	
	CGTClient*	GetGTClient() { return m_poGTClient; }
	VOID			ReleaseGtClient(CGTClient* poGTClient);
	UINT32		GetRemoteIP();

public:
	inline TCHAR*	GetDeviceID() { return m_aszDeviceID; }
	inline TCHAR*	GetNotifyID() { return m_aszNotifyID; }
	inline TCHAR*	GetUserName() { return m_aszUserName; }
    inline UINT16	GetZoneID()  { return m_wZoneID; }
	inline UINT16	GetOriginalZoneID()  { return m_wOriZoneID; }
	inline UINT32	GetUserID()  { return m_dwUserID; }
	inline UINT32	GetPlayerID()  { return m_dwPlayerID; }
	inline UINT16	GetCareerID()  { return m_wCareerID; }
	inline UINT8	GetAuthType()  { return m_byAuthType; }
	inline UINT8	GetDaiChong()  { return m_byDaiChong; }
protected:
	VOID    SetUserProp(TCHAR* pszUserName, TCHAR* pszDeviceID, TCHAR* pszNotifyID, UINT16 wZoneID, UINT16 wOriZoneID, UINT32 dwUserID, UINT32 dwPlayerID, UINT16 wCareerID, UINT8 byAuthType, CGTClient* poGTClient, UINT8 byDaiChong);
	VOID		ResetGTClient(CGTClient* poGTClient);//�Ͽ�֮ǰ�����ӣ��������µ�����

private:

	//�û��ỰID������ͬ��GS/DB��ĻỰID,��ͬ��ISDSession�ĻỰID
	//�û��ظ���¼ʱ����֮ǰ�����������ߣ�CUser���������ӣ�User��SessionID���䣬����GSͨѶ��SessionID����
	//�û�����ʱ��GT�Ͽ����ӣ���CUser���������ڴ��У��ȴ�GS֪ͨ���

	//�����жϿͻ��˷������ĺ���֤�Ƿ�һ��
	TCHAR            m_aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            m_aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            m_aszUserName[USERNAME_LEN]; //�û���
    UINT16			m_wZoneID;//��ID
	UINT16			m_wOriZoneID;//��ID
	UINT32			m_dwUserID;//�û�ID
	UINT32           m_dwPlayerID; //���ID�����û���¼��Ч
	UINT16           m_wCareerID; //ְҵ�����������(PlayerIDΪ0)��Ч
	UINT8			m_byAuthType;//��֤����
	CGTClient*		m_poGTClient;
	UINT8			m_byDaiChong;//�����־ 
};


#endif

