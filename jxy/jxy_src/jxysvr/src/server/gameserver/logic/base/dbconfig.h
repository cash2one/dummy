
#ifndef _DBCONFIG_H_
#define _DBCONFIG_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sqlite3db.h>

using namespace SGDP;

/**
* @brief ���ݿ�����������Ϣ������
*/
class CDBConfig
{
    DECLARE_SINGLETON(CDBConfig);

public:
    /**
     * @brief ��ʼ����������Դ��ȡ����
     * @return ��ʼ�����
     */
    BOOL Init();

    /**
     * @brief ж��
     * @return ж�ؽ��
     */
    VOID UnInit();

    /**
     * @brief ��ȡ���ݿ�������Ϣ����
     * @return ���ݿ�������Ϣ�����ָ�룬ʧ�ܷ���NULL
     */
    SGDP::SDDBAccount* GetDBAccount();

    /**
     * @brief ��ȡ����SQLite�����ļ�·��
     * @return ����SQLite�����ļ�·��
     */
    const CHAR* GetConfigDataPath();

    /**
     * @brief ��ȡSQLite���ݿ�����
     * @return SQLite���ݿ�����
     */
    //CSqlite3Conn* GetConnection();

protected:
    CDBConfig();
    virtual ~CDBConfig();

protected:
    SGDP::SDDBAccount   m_oDBAccount;   ///< ���ݿ�������Ϣ
    CHAR                m_szPath[256];  ///< ����SQLite�����ļ�·��
    BOOL                m_bStatus;      ///< �����Ƿ����
    CSqlite3Conn*       m_poConnection; ///< SQLite���ݿ�����
};

#endif // #ifndef _DBCONFIG_H_

