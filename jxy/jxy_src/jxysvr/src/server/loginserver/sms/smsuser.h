

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
	TCHAR	*	GetMobile(){return m_szMobile;}
	TCHAR	*	GetVerCode(){return m_szVerCode;}
	UINT64	&	GetRecvMsgTime(){return m_qwRecvMsgTime;}
	BOOL			CkUser(TCHAR *pszMobile, UINT16 &wCountdown);
	BOOL			CkUserDisconnect();
	BOOL			SetUserProp(UINT32 dwUserID, TCHAR* pszMobile, TCHAR* pszVerCode);

private:
	UINT8		m_dwOptType;
	UINT32		m_dwUserID;//�û�ID
	TCHAR		m_szMobile[MAX_MOBILE_LENGTH];
	TCHAR		m_szVerCode[MAX_MOBILE_LENGTH];
	UINT64		m_qwRecvMsgTime;		//�ϴ��յ���Ϣʱ��
	UINT64		m_qwCreateTime;		//����ʱ��
};


#endif //#ifndef _SDF_CLISESSION_H_

