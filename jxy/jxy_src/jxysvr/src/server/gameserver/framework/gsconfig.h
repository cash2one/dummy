


#ifndef _GAME_SERVER_SETTING_H_
#define _GAME_SERVER_SETTING_H_

#include <sdutil.h>
#include <sdframework.h>
#include <sdsingleton.h>
#include <sdxmlfile.h>
#include <sddb.h>
using namespace std;
using namespace SGDP;

#define PAY_TYPE_TONGBU	0	//��ֵΪͬ��
#define PAY_TYPE_APPSTORE 1	//��ֵΪappstore

#define IOS_AND_BOUND 100
#define IOS_DEFAULT_NOTICE 3
#define AND_DEFAULT_NOTICE 101

#define IOS_AND_ANDROID  0
#define SINGLE_IOS 1
#define SINGLE_ANDROID 2
#define BEGIN_MERGE_ZONE 146
#define BEGIN_AND_PLAYERID 100000000

struct SGateListenerInfo
{
    string					m_strIP;
    UINT16					m_wPort;
    UINT32					m_dwRecvBuf;
    UINT32					m_dwSendBuf;
};

class CGSConfig
{
public:
    DECLARE_SINGLETON(CGSConfig);

public:
    BOOL    Init(const TCHAR* pszConfig);
    VOID    UnInit();

public:

    /**
    * @brief ��ȡ���ݿ�������Ϣ
    * @param pszHost : ���ݿ������IP��ַ
    * @param wPort : ���ݿ�������˿�
    * @param pszLoginName : ���ݿ��ʺ�
    * @param pszPassword : ���ݿ�����
    * @param pszDBName : ���ݿ�����
    * @param pszCharacterSet : �ַ���
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL    GetDBConfig(CHAR* pszHost, UINT16 &wPort, CHAR* pszLoginName, CHAR* pszPassword, CHAR* pszDBName, CHAR* pszCharacterSet, CHAR* pszUnixSocket);

    /**
     * @brief ��ȡ�������ݿ��ļ���ַ
     * @param pszPath : �������ݿ��ļ���ַ������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL    GetConfigDataPath(CHAR* pszPath);

    tstring  GetConfigFile();

    // �Ƿ��ǿ��ս����������Ļ���Ϊ��Ϸ������
    BOOL GetIsPKServer(){ return m_bPKServer; }

    UINT32	GetOnlineSaveTimeInterval()
    {
        return m_dwOnlineSaveTimeInterval;
    }
    UINT32	GetOfflineSaveCkInterval()
    {
        return m_dwOfflineSaveCkInterval;
    }
    UINT32	GetOfflineCacheTime()
    {
        return m_dwOfflineCacheTime;
    }
    UINT32	GetPvpSaveCkInterval()
    {
        return m_dwPvpSaveCkInterval;
    }
    UINT32	GetPvpSaveNum()
    {
        return m_dwPvpSaveNum;
    }

    BOOL	GetDBAccount( SGDP::SDDBAccount& DBAccount );
    UINT32	GetPoolCoreSize();
    UINT32	GetPoolMaxSize();

    BOOL	GetRecordDBAccount( SGDP::SDDBAccount& DBAccount );
    UINT32	GetRecordPoolCoreSize();
    UINT32	GetRecordPoolMaxSize();

    BOOL	GetPayDBAccount( SGDP::SDDBAccount& DBAccount );
    UINT32	GetPayPoolCoreSize();
    UINT32	GetPayPoolMaxSize();

    BOOL	GetCfgDBAccount( SGDP::SDDBAccount& DBAccount );
    UINT32	GetCfgPoolCoreSize()
    {
        return 1;
    }
    UINT32	GetCfgPoolMaxSize()
    {
        return 1;
    }

    UINT32 GetTimerNotice()
    {
        return m_dwTimerNotice;
    };
    UINT32 GetChatSyncTime()
    {
        return m_dwChatSyncTime;
    };
    UINT32 GetChatSendNotice()
    {
        return m_dwChatSendNotice;
    };
    UINT32 GetSavePlayerInterval()
    {
        return m_dwPlayerSaveInterval;
    };
    UINT32 GetFillPlayerQueueInterval()
    {
        return m_dwFillePlayerQueueInterval;
    };
    std::string GetRechargeIP()
    {
        return m_strRechargeIP;
    };
    UINT32 GetRechargePort()
    {
        return m_dwRechargePort;
    };
    std::string GetAppPayUrl()
    {
        return m_strAppPayUrl;
    };
    std::string GetAppPayTableName()
    {
        return m_strAppPayTableName;
    };
    INT32  GetPayType()
    {
        return m_nPayType;
    };

    SGateListenerInfo& GetGateListenerInfo()
    {
        return m_stRechargeListenerInfo;
    }

    string GetSpeCfgTablePrefix()
    {
        return m_strSpeCfgTablePrefix;
    }

    UINT64 &GetServerOpentTime()
    {
        return m_qwServerOpentTime;
    }

protected:
    CGSConfig();
    ~CGSConfig();

    BOOL    _LoadCfg(CSDXMLFile* poConfig);
    BOOL	_LoadGateListenerInfo(CSDXMLFile* poSDXMLFile);

private:
    BOOL	CopyDBAccountInfo( SGDP::SDDBAccount &DBAccountDst, const SGDP::SDDBAccount &DBAccountSrc );
    BOOL	LoadDBConnInfo( CSDXMLNode &oNode, SGDP::SDDBAccount &oDBAccount );
private:

    CHAR    m_szDBConfigPath[MAX_PATH];
    CHAR    m_szConfigFile[MAX_PATH];
    SGDP::SDDBAccount  m_oDBAccount;
    UINT32  m_dwPoolCoreSize;
    UINT32  m_dwPoolMaxSize;

    BOOL    m_bPKServer;       // �Ƿ��ǿ��ս����������Ļ���Ϊ��Ϸ������
    
    //�ɼ����ݿ�������Ϣ

    SGDP::SDDBAccount  m_oRecordDBAccount; //�ɼ����ݿ���˺���Ϣ
    UINT32	m_dwRecordPoolCoreSize;
    UINT32  m_dwRecordPoolMaxSize;

    //app��ֵ�����ݿ������Ϣ
    SGDP::SDDBAccount  m_oPayDBAccount; //�ɼ����ݿ���˺���Ϣ
    UINT32	m_dwPayPoolCoreSize;
    UINT32  m_dwPayPoolMaxSize;

    SGDP::SDDBAccount  m_oCfgDBAccount; //�������ݿ���˺���Ϣ

    //��ʱ������
    UINT32	m_dwOnlineSaveTimeInterval;//��¼���db��ʱ������,��λ��
    UINT32	m_dwOfflineSaveCkInterval;//�ǵ�¼��ұ���/�����,��λ��
    UINT32	m_dwOfflineCacheTime;//�ǵ�¼����ڴ��б���ʱ��,��λ��
    UINT32	m_dwPvpSaveCkInterval;//pvp��Ϣ������,��λ��
    UINT32	m_dwPvpSaveNum;//pvpÿ�α������

    UINT32	m_dwTimerNotice;
    UINT32	m_dwChatSyncTime;
    UINT32	m_dwChatSendNotice;

    UINT32  m_dwPlayerSaveInterval; //��ұ���ļ���Ժ���Ϊ��λ
    UINT32  m_dwFillePlayerQueueInterval; //����������ݵĶ���ʱ�������Ժ���Ϊ��λ
    std::string  m_strRechargeIP; //��ֵIP
    UINT32  m_dwRechargePort; //��ֵ�ӿ�
    std::string  m_strAppPayUrl; //ƻ����ֵURL
    std::string  m_strAppPayTableName; //ƻ����ֵ���ݿ�ı���
    INT32	m_nPayType; //��ֵ����

    SGateListenerInfo	m_stRechargeListenerInfo; //ͬ����ֵ�˿�

    string	m_strSpeCfgTablePrefix;//��ָ���ñ�ǰ׺
    UINT64	m_qwServerOpentTime;//����ʱ��
};

#endif // #ifndef _GAME_SERVER_SETTING_H_

