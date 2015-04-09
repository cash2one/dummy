

#ifndef _DB_MANAGER_H_
#define _DB_MANAGER_H_

#pragma once

#include <sddb.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <sdobjectpool.h>
#include <protocol/server/protocommondata.h>
#include <map>
#include <string>


using namespace std;
using namespace SGDP;

//DB��������
enum EDBCmdType
{
    EDBCT_LOGIN = 1,//��֤
    EDBCT_LVLUP = 2,//�ȼ�����
    EDBCT_REGNAME = 3,//ע���û�
    EDBCT_DSPNAMEUP = 4,//�ȼ�����
    EDBCT_BIND = 5,//�û���
    EDBCT_UNBIND = 6,//�û���
    EDBCT_LOGIN_EX = 7,
    EDBCT_LOGOUT = 8,
    EDBCT_ACTIVITY_NOTIFY = 9,
    EDBCT_CHANGE_PWD	= 10,//��������
    EDBCT_SYNC_DATA	= 11,//ͬ������
	EDBCT_BINDMOBILE	= 12,//���ֻ���
	EDBCT_BINDCHECKVERCODE	= 13,//��֤��
	EDBCT_UNBINDMOBILE	= 14,//���ֻ���
	EDBCT_UNBINDCHECKVERCODE	= 15,//��֤��
	EDBCT_GETUSEREXPAND	= 16,	//��ȡ��չ���� 

};


class CBaseDBCMD;
class CLoginCMD;
class CLoginExCMD;
class CPlayUpgrateCMD;
class CRegisterUserNameCMD;
class CPlayDspNameUpgradeCMD;
class CPlayBindCMD;
class CPlayUnBindCMD;
class CLogoutCMD;
class CActivityNotifyCMD;
class CChangePwdCMD;
class CSyncDataCMD;
class CBindMobileCMD;
class CBindCheckVerCodeCMD;
class CUnBindMobileCMD;
class CUnBindCheckVerCodeCMD;
class CGetUserExpandCMD;


struct SVersionNoticeInfo
{
    SVersionNoticeInfo()
    {
        Init();
    }
    void Init()
    {
        memset(this, 0x00, sizeof(SVersionNoticeInfo));
    }
    UINT32				dwMinUnupdateVersionID;
    DT_VERSION_DATA		stVersionInfo;//�汾��Ϣ
    DT_NOTICE_DATA		stNoticeInfo1; //������Ϣ
    DT_NOTICE_DATA		stNoticeInfo2; //������Ϣ
};


typedef map<string, UINT8> CForbidLoginbyDeviceIDMap;
typedef CForbidLoginbyDeviceIDMap::iterator CForbidLoginbyDeviceIDMapItr;

typedef map<UINT32, UINT8> CForbidLoginbyUserIDMap;
typedef CForbidLoginbyUserIDMap::iterator CForbidLoginbyUserIDMapItr;

typedef map<UINT32, UINT8> CForbidLoginbyPlayerIDMap;
typedef CForbidLoginbyPlayerIDMap::iterator CForbidLoginbyPlayerIDMapItr;


typedef map<string, UINT8> CForbidRegisteredbyDeviceIDMap;
typedef CForbidRegisteredbyDeviceIDMap::iterator CForbidRegisteredbyDeviceIDMapItr;

typedef map<UINT32, UINT8> CForbidRegisteredbyUserIDMap;
typedef CForbidRegisteredbyUserIDMap::iterator CForbidRegisteredbyUserIDMapItr;


class CDBMgr
{
public:
    CDBMgr();
    ~CDBMgr();

    BOOL Init();
    VOID Release();
    BOOL Run();
    BOOL AddCommand(SGDP::ISDDBCommand* poDBCommand);
    SGDP::ISDDBSession* GetDBSession();
    /////////////////
    CBaseDBCMD*	CreateCmd(EDBCmdType eDbCmdType);
    VOID		FreeCmd(CBaseDBCMD* poBaseDBCMD);

    VOID SetVersionNoticeInf(SVersionNoticeInfo stVersionNoticeInfo)
    {
        m_stVersionNoticeInfo = stVersionNoticeInfo;
    }

    SVersionNoticeInfo & GetVersionNoticeInf()
    {
        return   m_stVersionNoticeInfo;
    }

    VOID SetForbidLoginbyDeviceIDMap(CForbidLoginbyDeviceIDMap mapForbidLoginbyDeviceID)
    {
		CSDMutexLock lock(m_oMutex);
        m_mapForbidLoginbyDeviceID.clear();
        m_mapForbidLoginbyDeviceID = mapForbidLoginbyDeviceID;
    }

    inline BOOL IsFindForbidLoginbyDeviceIDMap(string strDeviceID)
    {
        CSDMutexLock lock(m_oMutex);
        return m_mapForbidLoginbyDeviceID.find(strDeviceID) != m_mapForbidLoginbyDeviceID.end() ? TRUE : FALSE;
    }

    VOID SetForbidLoginbyUserIDMap(CForbidLoginbyUserIDMap mapForbidLoginbyUserID)
    {
        CSDMutexLock lock(m_oMutex);
        m_mapForbidLoginbyUserID.clear();
        m_mapForbidLoginbyUserID = mapForbidLoginbyUserID;
    }

    inline BOOL IsFindForbidLoginbyUserIDMap(UINT32 dwUserID)
    {
        CSDMutexLock lock(m_oMutex);
        return m_mapForbidLoginbyUserID.find(dwUserID) != m_mapForbidLoginbyUserID.end() ? TRUE : FALSE;
    }

    VOID SetForbidLoginbyPlayerIDMap(CForbidLoginbyPlayerIDMap mapForbidLoginbyPlayerID)
    {
        CSDMutexLock lock(m_oMutex);
        m_mapForbidLoginbyPlayerID.clear();
        m_mapForbidLoginbyPlayerID = mapForbidLoginbyPlayerID;
    }

    inline BOOL IsFindForbidLoginbyPlayerIDMap(UINT32 dwPlayerID)
    {
        CSDMutexLock lock(m_oMutex);
        return m_mapForbidLoginbyPlayerID.find(dwPlayerID) != m_mapForbidLoginbyPlayerID.end() ? TRUE : FALSE;
    }

    VOID SetForbidRegisteredbyDeviceIDMap(CForbidRegisteredbyDeviceIDMap mapForbidRegisteredbyDeviceID)
    {
        CSDMutexLock lock(m_oMutex);
        m_mapForbidRegisteredbyDeviceID.clear();
        m_mapForbidRegisteredbyDeviceID = mapForbidRegisteredbyDeviceID;
    }

    inline BOOL IsForbidRegisteredbyDeviceIDMap(string strDeviceID)
    {
        CSDMutexLock lock(m_oMutex);
        return m_mapForbidRegisteredbyDeviceID.find(strDeviceID) != m_mapForbidRegisteredbyDeviceID.end() ? TRUE : FALSE;
    }

    VOID SetForbidRegisteredbyUserIDMap(CForbidRegisteredbyUserIDMap mapForbidRegisteredbyUserID)
    {
        CSDMutexLock lock(m_oMutex);
        m_mapForbidRegisteredbyUserID.clear();
        m_mapForbidRegisteredbyUserID = mapForbidRegisteredbyUserID;
    }

    inline BOOL IsFindForbidRegisteredbyUserID(UINT32 dwUserID)
    {
        CSDMutexLock lock(m_oMutex);
        return m_mapForbidRegisteredbyUserID.find(dwUserID) != m_mapForbidRegisteredbyUserID.end() ? TRUE : FALSE;
    }

private:
    CDBMgr(const CDBMgr& rhs);
    CDBMgr& operator = (const CDBMgr& rhs);

private:
    SGDP::ISDDBModule*  m_pDBModule;
    SGDP::ISDDBSession* m_pDBSession;
    CSDObjectPool<CLoginCMD, CSDMutex>				m_oLoginCMDPool;
    CSDObjectPool<CLoginExCMD, CSDMutex>			m_oLoginExCMDPool;
    CSDObjectPool<CPlayUpgrateCMD, CSDMutex>			m_oPlayUpgrateCMDPool;
    CSDObjectPool<CRegisterUserNameCMD, CSDMutex>	m_oRegisterUserNameCMDPool;
    CSDObjectPool<CPlayDspNameUpgradeCMD, CSDMutex>	m_oPlayDspNameUpgradeCMDPool;
    CSDObjectPool<CPlayBindCMD, CSDMutex>			m_oPlayBindCMDPool;
    CSDObjectPool<CPlayUnBindCMD, CSDMutex>			m_oPlayUnBindCMDPool;
    CSDObjectPool<CLogoutCMD, CSDMutex>				m_oLogoutCMDPool;
    CSDObjectPool<CActivityNotifyCMD, CSDMutex>		m_oActivityNotifyCMDPool;
    CSDObjectPool<CChangePwdCMD, CSDMutex>			m_oChangePwdCMDPool;
    CSDObjectPool<CSyncDataCMD, CSDMutex>			m_oSyncDataCMDPool;

	CSDObjectPool<CBindMobileCMD, CSDMutex>			m_oBindMobileCMDPool;
	CSDObjectPool<CBindCheckVerCodeCMD, CSDMutex>	m_oBindCheckVerCodeCMDPool;
	CSDObjectPool<CUnBindMobileCMD, CSDMutex>		m_oUnBindMobileCMDPool;
	CSDObjectPool<CUnBindCheckVerCodeCMD, CSDMutex>	m_oUnBindCheckVerCodeCMDPool;
	CSDObjectPool<CGetUserExpandCMD, CSDMutex>		m_oGetUserExpandCMDPool;

    CSDMutex										m_oMutex;
    CForbidLoginbyDeviceIDMap						m_mapForbidLoginbyDeviceID;
    CForbidLoginbyUserIDMap						m_mapForbidLoginbyUserID;
    CForbidLoginbyPlayerIDMap						m_mapForbidLoginbyPlayerID;
    CForbidRegisteredbyDeviceIDMap					m_mapForbidRegisteredbyDeviceID;
    CForbidRegisteredbyUserIDMap					m_mapForbidRegisteredbyUserID;
    SVersionNoticeInfo							m_stVersionNoticeInfo;
};

#endif

