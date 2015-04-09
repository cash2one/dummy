#include "dbconfig.h"
#include <framework/gsconfig.h>
#include <sdstring.h>

IMPLEMENT_SINGLETON(CDBConfig)

CDBConfig::CDBConfig()
{
    memset(m_szPath , 0, sizeof(m_szPath));
    m_poConnection = NULL;
    m_bStatus = FALSE;
}

CDBConfig::~CDBConfig()
{

}

// ��ʼ����������Դ��ȡ����
BOOL CDBConfig::Init()
{
    CGSConfig::Instance()->GetDBConfig(m_oDBAccount.m_szHostName, 
        m_oDBAccount.m_wConnPort,
        m_oDBAccount.m_szLoginName,
        m_oDBAccount.m_szLoginPwd,
        m_oDBAccount.m_szDBName,
        m_oDBAccount.m_szCharactSet,
		m_oDBAccount.m_szUnixSocket);
    m_oDBAccount.m_wDBType = SGDP::SDDB_DBTYPE_MYSQL;
    //// ��ȡSQLite���ݿ��ļ���ַ
    //CGSConfig::Instance()->GetConfigDataPath(m_szPath);
    //// ����SQLite���ݿ�
    //m_poConnection = SDNew CSqlite3Conn();
    //m_poConnection->Connect(m_szPath);
    //if(FALSE == m_poConnection->IsConnected())
    //{
    //    // �������ݿ�ʧ��
    //    return FALSE;
    //}

    // ִ�гɹ�
    m_bStatus = TRUE;
    return TRUE;
}

// ж��
VOID CDBConfig::UnInit()
{
    memset(&m_oDBAccount, 0 , sizeof(SGDP::SDDBAccount));
    m_poConnection->Close();
    m_poConnection = NULL;
    m_bStatus = FALSE;
}

// ��ȡ���ݿ�������Ϣ����
SGDP::SDDBAccount* CDBConfig::GetDBAccount()
{
    if(FALSE == m_bStatus)
    {
        return NULL;
    }
    else
    {
        return &m_oDBAccount;
    }
}

// ��ȡ����SQLite�����ļ�·��
const CHAR* CDBConfig::GetConfigDataPath()
{
    return m_szPath;
}

// ��ȡSQLite���ݿ�����
//CSqlite3Conn* CDBConfig::GetConnection()
//{
//    return m_poConnection;
//}

