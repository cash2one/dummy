

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
typedef CSessionID2UserMap::const_iterator CSessionID2UserMapConstItr;

/**
* @brief �ͻ������ӹ�����
* ���������Ϸ�����������пͻ�������
*/
class CUserMgr
{
	friend class CChatMgr;	
	friend class CNoticeMgr;
public:


    typedef map<tstring , CUser*> CNameDevice2UserMap;//keyΪUserName+DeviceID
    typedef CNameDevice2UserMap::iterator CNameDevice2UserMapItr;

    DECLARE_SINGLETON(CUserMgr)

public:
    BOOL				Init();
    //�����û����������ڷ��ش����û�
    CUser*          CreateUser(UINT32 dwUserID, UINT32 dwPlayerID, UINT16 wCareerID, TCHAR* pszUserName, TCHAR* pszDeviceID, TCHAR* pszNotifyID, 
        UINT16 wZoneID, UINT16 wOriZoneID, UINT32 dwLoginIP, UINT32 dwCliVer, UINT8 byAuthType, UINT8 byDaichong = 0);

    VOID            ReleaseUser(CUser* poUser);

    //��dwUserSessionIDΪ׼
    //CUser*          FindUser(TCHAR* pszUserName, TCHAR* pszDeviceID);

    CUser*          FindUser(UINT32 dwPlayerID);

	VOID				CkUserDisconnect();
	//�ṩ�����÷�ʽ����ֹmap���ݱ��ı�
	inline const CSessionID2UserMap& GetAllUserMap(){ return m_mapSessionID2User; }

	inline	UINT32	GetConnectedNum() { return m_dwConnectedNum; }
	inline	VOID		IncConnectedNum() { m_dwConnectedNum++; }
	inline	VOID		DecConnectedNum() { if(m_dwConnectedNum>0) m_dwConnectedNum--; }

protected:
    CUserMgr();
    ~CUserMgr();
protected:

private:
    //CUser�����
    CSDObjectPool<CUser, CSDMutex>		m_oUserPool;
    //�û���������
    CSessionID2UserMap				m_mapSessionID2User;

	CSessionID2UserMapItr			m_itrCurDealUser;//

	UINT32							m_dwConnectedNum;
};



#endif //#ifndef _SDF_OBJFACTORY_H_

