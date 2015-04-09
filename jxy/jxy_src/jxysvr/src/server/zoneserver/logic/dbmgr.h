
#ifndef _DB_MANAGER_H_
#define _DB_MANAGER_H_

#pragma once

#include <sddb.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <sdobjectpool.h>
#include <protocol/server/protoclizs.h>
#include <vector>
#include <map>

using namespace std;
using namespace SGDP;

//DB��������
enum EDBCmdType
{
    EDBCT_SELECT_ZONE = 1,//ѡ��
    EDBCT_GET_ZONE_INFO = 4,//��ȡ����Ϣ
    EDBCT_GET_VERSION_NOTICE = 5,//��ȡ�汾��������Ϣ
    EDBCT_SYNC_ZONENOTICE = 6,//ͬ������������Ϣ
    EDBCT_GET_USERINFO = 7,//��ȡ�û���Ϣ
    EDBCT_REGISTER_USERNAME = 8,//ע���û���Ϣ
    EDBCT_USER_DEVICE_INFO = 9,//�豸��Ϣ
    EDBCT_UNBIND_DEVICE = 10,//�豸��Ϣ
    EDBCT_GET_VERSION_NOTICE2 = 11,//��ȡ�汾��������Ϣ
    EDBCT_CHANGE_PWD	=	12,//��������
    EDBCT_FORBID_LOGIN =	13, //��ֹ��¼
    EDBCT_FORBID_REGISTERED	=	14,//��ֹע��
    EDBCT_RESETPASSWDMOBILE	=	15,//����������֤�ֻ���
    EDBCT_RESETPASSWDNEWPASSWD	=	16,//�������� ����������
    EDBCT_SETACCOUNTTYPE		=	17,//�����˺�����
    EDBCT_STARTSERVICE		=	18,//���ÿ���ʱ��
};


class CBaseDBCMD;
class CSelectZoneCMD;
class CGetZoneInfoCMD;
class CGetVersionNoticeCMD;
class CGetVersionNoticeCMD2;
class CSyncZoneNoticeCMD;
class CGetUserInfoCMD;
class CRegisterCMD;
class CUserDeviceInfoCMD;
class CUnBindDeviceCMD;
class CChangePwdCMD;
class CForbidLoginCMD;
class CForbidRegisteredCMD;
class CResetPasswdMobileCMD;
class CResetPasswdNewPassCMD;
class CSetAccountTypeCMD;
class CStartServerCMD;


typedef struct _tagDT_ZONE_DATA_INFO
{
    UINT8		byVisible;
	UINT16		wMinVersionID;
	UINT16		wMaxVersionID;
    DT_ZONE_DATA stDT_ZONE_DATA;
    _tagDT_ZONE_DATA_INFO()
    {
        Init();
    }
    void Init()
    {
        memset(this, 0x00, sizeof(_tagDT_ZONE_DATA_INFO));
    }
} DT_ZONE_DATA_INFO;

typedef vector<DT_ZONE_DATA_INFO> CZoneInfoVec;
typedef CZoneInfoVec::iterator CZoneInfoVecItr;

struct SVersionNoticeInfo
{
    UINT32				dwMinUnupdateVersionID;
    DT_VERSION_DATA		stVersionInfo; //�汾��Ϣ
    DT_NOTICE_DATA		stNoticeInfo; //������Ϣ
};

struct SVersionNoticeInfo2
{
    UINT32				dwMinUnupdateVersionID;
    DT_VERSION_DATA2		stVersionInfo; //�汾��Ϣ
    DT_NOTICE_DATA		stNoticeInfo; //������Ϣ
};

//�ͻ��˰汾��Դ����
struct SCliVerInfoProp
{
    UINT32 dwCliVer;
    UINT32 dwResVer;
    UINT32 dwUIVer;
};

typedef map<UINT32, SCliVerInfoProp> CVerID2CliVerInfoMap;
typedef CVerID2CliVerInfoMap::iterator CVerID2CliVerInfoMapItr;

class CDBMgr
{
public:
    CDBMgr();
    ~CDBMgr();

    BOOL Init();
    VOID Release();
    BOOL Run();
    BOOL AddCommand(CBaseDBCMD* poDBCommand);
    UINT32 GetDBCommandCount();
    SGDP::ISDDBSession* GetDBSession();
    /////////////////
    CBaseDBCMD*	CreateCmd(EDBCmdType eDbCmdType);
    VOID		FreeCmd(CBaseDBCMD* poBaseDBCMD);

    /////////////////
    VOID SyncZoneInfo(CZoneInfoVec& vecZoneInfo);
    VOID SyncVersionNotice(SVersionNoticeInfo& stVersionNoticeInfo);
    VOID SyncVersionNotice2(SVersionNoticeInfo2& stVersionNoticeInfo2);
    VOID SyncResVer(CVerID2CliVerInfoMap& mapVerID2CliVerInfo);

    CZoneInfoVec GetZoneInfo()
    {
        return m_vecZoneInfo;
    }

    SVersionNoticeInfo GetVersionNotice()
    {
        return m_stVersionNoticeInfo;
    }
    SVersionNoticeInfo2 GetVersionNotice2()
    {
        return m_stVersionNoticeInfo2;
    }
    VOID GetCliVerInfo(UINT32 dwCliVer, UINT32& dwResVer, UINT32& dwUIVer);

private:
    CDBMgr(const CDBMgr& rhs);
    CDBMgr& operator = (const CDBMgr& rhs);

private:
    SGDP::ISDDBModule*  m_pDBModule;
    SGDP::ISDDBSession* m_pDBSession;
    CSDObjectPool<CSelectZoneCMD, CSDMutex>			m_oSelectZoneCMDPool;
    CSDObjectPool<CGetZoneInfoCMD, CSDMutex>			m_oGetZoneInfoCMDPool;
    CSDObjectPool<CGetVersionNoticeCMD, CSDMutex>	m_oGetVersionNoticeCMDPool;
    CSDObjectPool<CGetVersionNoticeCMD2, CSDMutex>	m_oGetVersionNoticeCMD2Pool;
    CSDObjectPool<CSyncZoneNoticeCMD, CSDMutex>		m_oSyncZoneNoticeCMDPool;
    CSDObjectPool<CGetUserInfoCMD, CSDMutex>			m_oGetUserInfoCMDPool;
    CSDObjectPool<CRegisterCMD, CSDMutex>			m_oRegisterCMDPool;
    CSDObjectPool<CUserDeviceInfoCMD, CSDMutex>		m_oUserDeviceInfoCMDPool;
    CSDObjectPool<CUnBindDeviceCMD, CSDMutex>		m_oUnBindDeviceCMDPool;
    CSDObjectPool<CChangePwdCMD, CSDMutex>			m_oChangePwdCMDPool;
    CSDObjectPool<CForbidLoginCMD, CSDMutex>			m_oForbidLoginCMDPool;
    CSDObjectPool<CForbidRegisteredCMD, CSDMutex>	m_oForbidRegisteredCMDPool;
    CSDObjectPool<CResetPasswdMobileCMD, CSDMutex>	m_oResetPasswdMobileCMDPool;
    CSDObjectPool<CResetPasswdNewPassCMD, CSDMutex>	m_oResetPasswdNewPassCMDPool;
    CSDObjectPool<CSetAccountTypeCMD, CSDMutex>		m_oSetAccountTypeCMDPool;
	CSDObjectPool<CStartServerCMD, CSDMutex>			m_oStartServerCMDPool;

    CZoneInfoVec									m_vecZoneInfo;
    SVersionNoticeInfo							m_stVersionNoticeInfo;
    SVersionNoticeInfo2							m_stVersionNoticeInfo2;
    CVerID2CliVerInfoMap							m_mapVerID2CliVerInfo;
};

#endif

