#include "sddbconfig.h"
#include "sddebug.h"

#if ( defined(WIN32) || defined(WIN64) )
#include <WinSock2.h>
#endif

#include "db_mysqlconn.h"
#include "sdstring.h"
#include <errmsg.h>
using namespace SGDP ;
const static CHAR* ERR_CONN_IS_NULL = "disconnected from mysql.";
const static CHAR* g_stpCharSets[] =
{
    "big5",
    "dec8",
    "cp850",
    "hp8",
    "koi8r",
    "latin1",
    "latin2",
    "swe7",
    "ascii",
    "ujis",
    "sjis",
    "hebrew",
    "tis620",
    "euckr",
    "koi8u",
    "gb2312",
    "greek",
    "cp1250",
    "gbk",
    "latin5",
    "armscii8",
    "utf8",
    "ucs2",
    "cp866",
    "keybcs2",
    "macce",
    "macroman",
    "cp852",
    "latin7",
    "cp1251",
    "cp1256",
    "cp1257",
    "binary",
    "geostd8",
    "cp932",
    "eucjpms",
    "utf8mb4",
    NULL
};

CMySQLConn::CMySQLConn() :
    m_poConnection(NULL),
    m_bConnected(false),
    m_bUsed(false)
{
#if (defined(WIN32) || defined(WIN64))
    SGDP::SDZeroString(m_szServerAddr);
    SGDP::SDZeroString(m_szDBName);
    SGDP::SDZeroString(m_szLoginName);
    SGDP::SDZeroString(m_szPassword);
	SGDP::SDZeroString(m_szUnixSocket);
#else
    memset( m_szServerAddr, 0, sizeof(m_szServerAddr) );
    memset( m_szDBName, 0, sizeof(m_szDBName) );
    memset( m_szLoginName, 0, sizeof(m_szLoginName) );
    memset( m_szPassword, 0, sizeof(m_szPassword) );
	memset( m_szUnixSocket, 0, sizeof(m_szUnixSocket));
#endif

    SGDP::SDStrncpy(m_szCharactSet, "latin1", sizeof(m_szCharactSet));
}

CMySQLConn::~CMySQLConn()
{
    this->Release();
}

CMySQLConn::CMySQLConn(const CMySQLConn & rhs)
{
    //������������CMySQLConn
}

CMySQLConn & CMySQLConn::operator = (const CMySQLConn & rhs)
{
    //������ֵCMySQLConn
    return *this;
}

bool CMySQLConn::operator == (const CMySQLConn & rhs)
{
    return this->m_poConnection == rhs.m_poConnection;
}

bool CMySQLConn::CheckConnection()
{
    return m_bConnected && NULL != m_poConnection;
}

void CMySQLConn::Release()
{
    if(NULL != m_poConnection)
    {
        mysql_close(m_poConnection);
        m_poConnection = NULL;
    }
    m_bConnected = false;
    m_oCharsets.clear();

    MAP_STMT_TYPE::iterator itr = m_mapStmtPtr.begin();
    while( itr != m_mapStmtPtr.end() )
    {
        mysql_stmt_close( itr->second );
        ++itr;
    }

    INFO(_SDT("[%s] Close DB Successful----\tSvrIP:%s\tDBName:%s\tUnixSocket:%s"), _SDTA2T(__FUNCTION__), _SDTA2T(m_szServerAddr), _SDTA2T(m_szDBName), m_szUnixSocket);
}

UINT32 CMySQLConn::EscapeString(const CHAR *pSrc, INT32 nSrcSize, CHAR *pDest, INT32 nDstSize)
{
    if(false == this->_CheckConnection())
    {
        return 0;
    }

    if((2 * nSrcSize + 1) > nDstSize)
    {
        CRITICAL(_SDT("CMySQLConn::EscapeString exception: DestSize < 2 * nSrcSize + 1"));
        return 0;
    }

    return mysql_real_escape_string(m_poConnection, pDest, pSrc, nSrcSize);
}

INT32 CMySQLConn::ExecuteSql(const CHAR *pSQL, UINT64 *pInsertId, UINT32* pEffectRowNum, UINT32* pdwErr, string* pstrErr)
{
    if(false == this->_CheckConnection())
    {
        return SGDP::SDDB_ERR_CONN;
    }

    if(0 != mysql_query(m_poConnection, pSQL))
    {
        //==============��ѯ���ɹ�,��ӡ��־==============
        UINT32 dwErr = mysql_errno(m_poConnection);
		if(pdwErr)
		{
			*pdwErr = dwErr;
		}

        const CHAR * pszErrMsg = mysql_error(m_poConnection);
        if(pszErrMsg != NULL)
        {
			if(pstrErr)
			{
				*pstrErr = pszErrMsg;
			}
            CRITICAL(_SDT("ExecuteSql exception, SQL:%s, ErrorNo: %d, ErrorMsg: %s"), _SDTA2T(pSQL), dwErr, _SDTA2T(pszErrMsg));
        }
        else
        {
            CRITICAL(_SDT("ExecuteSql exception, SQL:%s, ErrorNo: %d"), _SDTA2T(pSQL), dwErr);
        }

        //==================��ӡ��־���==================
        if(CR_SERVER_LOST == dwErr || CR_CONN_HOST_ERROR == dwErr || CR_SERVER_GONE_ERROR == dwErr)
        {
            if(false == _ReConnect())
            {
                return SGDP::SDDB_ERR_CONN;
            }

            if(0 != mysql_query(m_poConnection, pSQL))
            {
                //==============�ٴβ�ѯ���ɹ�,��ӡ��־==============
                UINT32 dwErr = mysql_errno(m_poConnection);
                const CHAR * pszErrMsg = mysql_error(m_poConnection);
                if(pszErrMsg != NULL)
                {
                    CRITICAL(_SDT("ExecuteSql exception again: ErrorNo: %d, ErrorMsg: %s"), dwErr, _SDTA2T(pszErrMsg));
                }
                else
                {
                    CRITICAL(_SDT("ExecuteSql exception again: ErrorNo: %d"), dwErr);
                }
                //==================��ӡ��־���==================
                return SGDP::SDDB_ERR_UNKNOWN;
            }
        }
        else
        {
            return SGDP::SDDB_ERR_UNKNOWN;
        }
    }
    else
    {
        //��ѯ�ɹ�
        if(NULL != pInsertId)
        {
            *pInsertId = this->_GetInsertId();
        }
    }

    INT32 nRow = (INT32)mysql_affected_rows(m_poConnection);
	if(NULL != pEffectRowNum)
	{
		*pEffectRowNum = nRow;
	}
    do
    {
		MYSQL_RES * res = mysql_store_result(m_poConnection);
		if(NULL != res)
			mysql_free_result(res);
    }
    while (!mysql_next_result(m_poConnection));

    return 0;
}

INT32 CMySQLConn::ExecuteSqlRs(const CHAR *pSQL, SGDP::ISDDBRecordSet **ppoRs, UINT32* pdwErr, string* pstrErr)
{
    if(false == this->_CheckConnection())
    {
        return SGDP::SDDB_ERR_CONN;
    }

    if(0 != mysql_query(m_poConnection, pSQL))
    {
        //==============��ѯ���ɹ�,��ӡ��־==============
        UINT32 dwErr = mysql_errno(m_poConnection);
		if(pdwErr)
		{
			*pdwErr = dwErr;
		}
		const CHAR * pszErrMsg = mysql_error(m_poConnection);
		if(pszErrMsg != NULL)
		{
			if(pstrErr)
			{
				*pstrErr = pszErrMsg;
			}
			CRITICAL(_SDT("ExecuteSqlRs exception, SQL:%s, ErrorNo: %d, ErrorMsg: %s"), _SDTA2T(pSQL), dwErr, pszErrMsg);
		}
		else
		{
			CRITICAL(_SDT("ExecuteSqlRs exception, SQL:%s, ErrorNo: %d"), _SDTA2T(pSQL), dwErr);
		}
        //==================��ӡ��־���==================
        if(CR_SERVER_LOST == dwErr || CR_CONN_HOST_ERROR == dwErr || CR_SERVER_GONE_ERROR == dwErr)
        {
            if(false == this->_ReConnect())
            {
                return SGDP::SDDB_ERR_CONN;
            }

            if(0 != mysql_query(m_poConnection, pSQL))
            {
                //==============��ѯ���ɹ�,��ӡ��־==============
                UINT32 dwErr = mysql_errno(m_poConnection);
                if(pdwErr)
                {
                    *pdwErr = dwErr;
                }
                const CHAR * pszErrMsg = mysql_error(m_poConnection);
                if(pszErrMsg != NULL)
                {
                    if(pstrErr)
                    {
                        *pstrErr = pszErrMsg;
                    }
                    CRITICAL(_SDT("ExecuteSqlRs exception again: ErrorNo: %d, ErrorMsg: %s"), dwErr, _SDTA2T(pszErrMsg));
                }
                else
                {
                    CRITICAL(_SDT("ExecuteSqlRs exception again: ErrorNo: %d"), dwErr);
                }
                //==================��ӡ��־���==================
                //������ͻ
                if(1062 == dwErr)
                {
                    return SDDB_ERR_DUPLICATE;
                }
                else
                {
                    return SGDP::SDDB_ERR_UNKNOWN;
                }
            }
        }
        else
        {
            //������ͻ
            if(1062 == dwErr)
            {
                return SDDB_ERR_DUPLICATE;
            }
            else
            {
                return SGDP::SDDB_ERR_UNKNOWN;
            }
        }
    }
    CMySQLRecordSet * rs = SDNew CMySQLRecordSet();
    if(NULL == rs)
    {
        CRITICAL(_SDT("[%s] alloc CMySQLRecordSet Error"), _SDTA2T(__FUNCTION__));
        return SGDP::SDDB_ERR_UNKNOWN;
    }
    *ppoRs = rs;
    if(rs->m_res != NULL)
    {
        mysql_free_result(rs->m_res);
        rs->m_res = NULL;
    }

    rs->m_res = mysql_store_result(m_poConnection);
    if(NULL == rs->m_res)
    {
        if(0 == mysql_field_count(m_poConnection))      //ִ�е���insert��update���
        {
            rs->Release();
            *ppoRs = NULL;

            //�ͷŵ�����Ľ����
            while (0 == mysql_next_result(m_poConnection))
            {
                MYSQL_RES * res = mysql_store_result(m_poConnection);
                if(NULL != res)
                    mysql_free_result(res);
            }

            return SGDP::SDDB_NO_RECORDSET;
        }
        else
        {
            rs->Release();
            *ppoRs = NULL;

            //�ͷŵ�����Ľ����
            while (0 == mysql_next_result(m_poConnection))
            {
                MYSQL_RES * res = mysql_store_result(m_poConnection);
                if(NULL != res)
                    mysql_free_result(res);
            }

            return SGDP::SDDB_ERR_UNKNOWN;
        }

        return SGDP::SDDB_HAS_RECORDSET;
    }
    else
    {
        if(mysql_num_rows(rs->m_res) > 0)
        {
            //�ͷŵ�����Ľ����
            while (0 == mysql_next_result(m_poConnection))
            {
				MYSQL_RES * res = mysql_store_result(m_poConnection);
				if(NULL != res)
					mysql_free_result(res);
            }

            return SGDP::SDDB_HAS_RECORDSET;//�н������
        }
        else
        {
            rs->Release();
            *ppoRs = NULL;

			while (0 == mysql_next_result(m_poConnection))
			{
				MYSQL_RES * res = mysql_store_result(m_poConnection);
				if(NULL != res)
					mysql_free_result(res);
			}
            return SGDP::SDDB_NO_RECORDSET;
        }
    }

    return  SGDP::SDDB_ERR_UNKNOWN;
}

INT32 CMySQLConn::ExecuteSqlRs(const CHAR *pSQL, std::vector<SGDP::ISDDBRecordSet*>& vecRs, UINT32* pdwErr, string* pstrErr)
{
    if(false == this->_CheckConnection())
    {
        return SGDP::SDDB_ERR_CONN;
    }

    if(0 != mysql_query(m_poConnection, pSQL))
    {
        //==============��ѯ���ɹ�,��ӡ��־==============
        UINT32 dwErr = mysql_errno(m_poConnection);
        if(pdwErr)
        {
            *pdwErr = dwErr;
        }
        const CHAR * pszErrMsg = mysql_error(m_poConnection);
        if(pszErrMsg != NULL)
        {
            if(pstrErr)
            {
                *pstrErr = pszErrMsg;
            }
            CRITICAL(_SDT("ExecuteSqlRs exception, SQL:%s, ErrorNo: %d, ErrorMsg: %s"), _SDTA2T(pSQL), dwErr, pszErrMsg);
        }
        else
        {
            CRITICAL(_SDT("ExecuteSqlRs exception, SQL:%s, ErrorNo: %d"), _SDTA2T(pSQL), dwErr);
        }
        //==================��ӡ��־���==================
        if(CR_SERVER_LOST == dwErr || CR_CONN_HOST_ERROR == dwErr || CR_SERVER_GONE_ERROR == dwErr)
        {
            if(false == this->_ReConnect())
            {
                return SGDP::SDDB_ERR_CONN;
            }

            if(0 != mysql_query(m_poConnection, pSQL))
            {
                //==============��ѯ���ɹ�,��ӡ��־==============
                UINT32 dwErr = mysql_errno(m_poConnection);
                if(pdwErr)
                {
                    *pdwErr = dwErr;
                }
                const CHAR * pszErrMsg = mysql_error(m_poConnection);
                if(pszErrMsg != NULL)
                {
                    if(pstrErr)
                    {
                        *pstrErr = pszErrMsg;
                    }
                    CRITICAL(_SDT("ExecuteSqlRs exception again: ErrorNo: %d, ErrorMsg: %s"), dwErr, _SDTA2T(pszErrMsg));
                }
                else
                {
                    CRITICAL(_SDT("ExecuteSqlRs exception again: ErrorNo: %d"), dwErr);
                }
                //==================��ӡ��־���==================
                //������ͻ
                if(1062 == dwErr)
                {
                    return SDDB_ERR_DUPLICATE;
                }
                else
                {
                    return SGDP::SDDB_ERR_UNKNOWN;
                }
            }
        }
        else
        {
            //������ͻ
            if(1062 == dwErr)
            {
                return SDDB_ERR_DUPLICATE;
            }
            else
            {
                return SGDP::SDDB_ERR_UNKNOWN;
            }
        }
    }

    do
    {
        CMySQLRecordSet * rs = SDNew CMySQLRecordSet();
        rs->m_res = mysql_store_result(m_poConnection);
        if(NULL != rs->m_res)
        {
            vecRs.push_back(rs);
        }
        else
        {
            SDDelete rs;
            rs = NULL;
        }
    }
    while (0 == mysql_next_result(m_poConnection));

    if(vecRs.size() > 0)
    {
        return SGDP::SDDB_HAS_RECORDSET;//�н������
    }

    return SGDP::SDDB_NO_RECORDSET;
}


void CMySQLConn::BeginTransaction()
{
	if(NULL == m_poConnection)
	{
		return;
	}
    mysql_autocommit(m_poConnection, 0);
}

void CMySQLConn::CommitTransaction()
{
	if(NULL == m_poConnection)
	{
		return;
	}
    mysql_commit(m_poConnection);
    mysql_autocommit(m_poConnection, 1);
}

void CMySQLConn::RollbackTransaction()
{
	if(NULL == m_poConnection)
	{
		return;
	}
    mysql_rollback(m_poConnection);
    mysql_autocommit(m_poConnection, 1);
}

bool CMySQLConn::Connect(const CHAR *pszServerAddr, INT32 nServerPort,
                         const CHAR *pszDBName, const CHAR *pszLoginName,
                         const CHAR *pszPassword, const CHAR *pszCharactSet, 
						 const CHAR* pszUnixSocket)
{
    if(NULL == pszServerAddr || nServerPort <= 0 || NULL == pszDBName ||
            NULL == pszLoginName || NULL == pszPassword || NULL == pszCharactSet ||
			NULL == pszUnixSocket)
    {
        return false;
    }
    this->Release();
    this->_SetConnectionString(pszServerAddr, nServerPort, pszDBName, pszLoginName, pszPassword, pszCharactSet, pszUnixSocket);
    return _Connect();
}

UINT64 CMySQLConn::_GetInsertId()
{
    return mysql_insert_id(m_poConnection);
}

void CMySQLConn::_SetConnectionString(const CHAR* pszServerAddr, INT32 nServerPort, const CHAR* pszDBName,
                                      const CHAR* pszLoginName, const CHAR* pszPassword, const CHAR* pszCharactSet, const CHAR* pszUnixSocket)
{
    SGDP::SDStrncpy(m_szServerAddr, pszServerAddr, sizeof(m_szServerAddr));
    SGDP::SDStrncpy(m_szDBName, pszDBName, sizeof(m_szDBName));
    SGDP::SDStrncpy(m_szLoginName, pszLoginName, sizeof(m_szLoginName));
    SGDP::SDStrncpy(m_szPassword, pszPassword, sizeof(m_szPassword));
	SGDP::SDStrncpy(m_szUnixSocket, pszUnixSocket, sizeof(m_szPassword));

    if ('\0' != pszCharactSet[0])
    {
        SGDP::SDStrncpy(m_szCharactSet, pszCharactSet, sizeof(m_szCharactSet));
        INFO(_SDT("Set DB charset: %s\n"), _SDTA2T(m_szCharactSet));
    }
    else
    {
        INFO(_SDT("Using default DB charset: %s\n"), _SDTA2T(m_szCharactSet));
    }

    m_nServerPort = nServerPort;
}

bool CMySQLConn::_Connect()
{
    if(m_bConnected)
    {
        return true;
    }
    if(NULL == m_poConnection)
    {
        m_poConnection = mysql_init(NULL);
    }
    if(NULL == m_poConnection)
    {
        return false;
    }

    //����ͻ�������������ַ���������MYSQL���ַ�������
    if('\0' != m_szCharactSet[0])
    {
        if (false == _IsValidCharacterSet(m_szCharactSet))
        {
            return false;
        }
        if(mysql_options(m_poConnection, MYSQL_SET_CHARSET_NAME, m_szCharactSet))
        {
            return false;
        }
    }
    //m_poConnection = mysql_real_connect(m_poConnection, m_szServerAddr, m_szLoginName,
    //	m_szPassword, m_szDBName, m_nServerPort, NULL, CLIENT_MULTI_STATEMENTS);

    //if(NULL == m_poConnection)

	const CHAR* pszUnixSocketTmp = NULL;
#ifdef __linux__
	if(0 != m_szUnixSocket[0])
	{
		pszUnixSocketTmp = m_szUnixSocket;
	}
#endif

    if( !mysql_real_connect(m_poConnection, m_szServerAddr, m_szLoginName,
                            m_szPassword, m_szDBName, m_nServerPort, pszUnixSocketTmp, CLIENT_MULTI_STATEMENTS) )
    {
        CHAR *pErrStr = (CHAR *)mysql_error(m_poConnection);
        CRITICAL(_SDT("[%s]mysql_real_connect failed, error str:%s\n"), _SDTA2T(__FUNCTION__), pErrStr);
        this->Release();
        return false;
    }

    m_bConnected = true;

    //�����ַ���
    if(false == _SetServerNames())
    {
        this->Release();
        return false;
    }

    //��ȡ�������˵��ַ���
    if(false == _GetDBSCharSetInfo())
    {
        this->Release();
        return false;
    }

    //������ú���ַ����Ƿ����Ҫ��
    if(false == _IsCompatiableCharSet())
    {
        CRITICAL(_SDT("[%s]Charset inconformity: application charset is %s\n"), _SDTA2T(__FUNCTION__), _SDTA2T(m_szCharactSet));
        this->Release();
        return false;
    }

    INFO(_SDT("[%s] Connect DB Successful!\tSvrIP:%s\tDBName:%s\tUnixSocket:%s"), _SDTA2T(__FUNCTION__), _SDTA2T(m_szServerAddr), _SDTA2T(m_szDBName), m_szUnixSocket);
    return true;
}

bool CMySQLConn::_ReConnect()
{
    this->Release();
    return this->_Connect();
}

bool CMySQLConn::_CheckConnection()
{
    //�������:
    //1.���Ϊ���쳣���ӡ����ر����ӣ�ת����û�����ӡ�״̬��
    //2.���Ϊ��û�����ӡ����������ӣ�����ת�����������ӡ�״̬��
    //3.�����Ƿ��������ӡ�
    //
    //��ע:Ŀǰ����������״̬,
    // ��������(m_poConnection != NULL, m_bConnected == true),
    // �쳣����(m_poConnection != NULL, m_bConnected == false),
    // û������(m_poConnection == NULL, m_bConnected == false)
    if(!m_bConnected && NULL != m_poConnection)//���쳣���ӡ�״̬
    {
        this->Release();
    }
    if(NULL == m_poConnection)//��û�����ӡ�״̬
    {
        m_bConnected = this->_Connect();
    }
    return m_bConnected;
}

bool CMySQLConn::CreateDB(const CHAR *pcDBName, bool bForce, const CHAR *pcCharSet)
{
    if (pcDBName != NULL && m_poConnection != NULL)
    {
        if (bForce)
        {
            std::string dropSql = std::string("DROP DATABASE IF EXISTS ") + pcDBName;
            mysql_query(m_poConnection, dropSql.c_str());
        }

        std::string createSql = "CREATE DATABASE IF NOT EXISTS ";
        if (pcCharSet != NULL)
        {
            createSql += pcDBName;
            createSql += " CHARACTER SET = ";
            createSql += pcCharSet;
        }

        return 0 == mysql_query(m_poConnection, createSql.c_str());
    }

    return false;
}

bool CMySQLConn::SelectDB(const CHAR *pcDBName)
{
    if (pcDBName != NULL && m_poConnection != NULL )
    {
        return 0 == mysql_select_db(m_poConnection, pcDBName) ? true : false;
    }
    return false;
}

bool CMySQLConn::_GetDBSCharSetInfo()
{
#if 0 //  [�ϰ汾Mysqlû��character_set_system���� ]
    //WARING:��sql ����б�����˳��һ����ö�ٶ���һ��
    CHAR* pszSql = "select @@character_set_client, @@character_set_connection,   \
				   @@character_set_database, @@character_set_results,@@character_set_server,\
				   @@character_set_system";
#else
    const CHAR * pszSql = "show variables like 'character_%'";
#endif

    SGDP::ISDDBRecordSet * poRs = NULL;
    if(SGDP::SDDB_HAS_RECORDSET != ExecuteSqlRs(pszSql, &poRs))
    {
        if(NULL != poRs)
        {
            poRs->Release();
        }
        return false;
    }

    while(poRs->GetRecord())
    {
        const CHAR* pszVariableName = poRs->GetFieldValue(0);
        const CHAR* pszCharsetName  = poRs->GetFieldValue(1);

        m_oCharsets.insert(std::make_pair(std::string(pszVariableName), std::string(pszCharsetName)));
    }

    INFO(_SDT("SDDB Charset Info:"));
    Charsets::iterator i = m_oCharsets.begin();
    Charsets::iterator end = m_oCharsets.end();
    while(i != end)
    {
        INFO(_SDT("[varname]%s : [charset]%s\n"), _SDTA2T(i->first.c_str()), _SDTA2T(i->second.c_str()));
        ++i;
    }
    poRs->Release();
    return true;
}

bool CMySQLConn::_IsCompatiableCharSet()
{
    //��������
    //��Ҫ��֤character_set_client��m_szCharactSet�ͣ�character_set_connection, character_set_results,
    //character_set_database, character_set_server����ȫһ��

    std::string strClientCharset;

    Charsets::iterator i = m_oCharsets.find(std::string("character_set_client"));
    if(i != m_oCharsets.end())
    {
        strClientCharset = i->second;
    }
    else
    {
        CRITICAL(_SDT("[%s]Not found character_set_client variable! Check charset compatibility failed!"), _SDTA2T(__FUNCTION__));
        return false;
    }

    i = m_oCharsets.find(std::string("character_set_connection"));
    if(i != m_oCharsets.end())
    {
        if(strClientCharset != i->second)
        {
            CRITICAL(_SDT("[%s]character_set_connection(%s) and character_set_client(%s) is incompatible"),
                     _SDTA2T(__FUNCTION__), _SDTA2T(i->second.c_str()), _SDTA2T(strClientCharset.c_str()));

            return false;
        }
    }
    i = m_oCharsets.find(std::string("character_set_results"));
    if(i != m_oCharsets.end())
    {
        if(strClientCharset != i->second)
        {
            CRITICAL(_SDT("[%s]character_set_results(%s) and character_set_client(%s) is incompatible"),
                     _SDTA2T(__FUNCTION__), _SDTA2T(i->second.c_str()), _SDTA2T(strClientCharset.c_str()));

            return false;
        }
    }

    if(strClientCharset != std::string(m_szCharactSet))
    {
        CRITICAL(_SDT("[%s]character_set_client(%s) and Application Setting(%s) is incompatible\n"),
                 _SDTA2T(__FUNCTION__), _SDTA2T(strClientCharset.c_str()), _SDTA2T(m_szCharactSet));
        return false;
    }

    return true;
}

//������Ҫ����character_set_client, character_set_results, character_set_connection,
//ʹ�������ַ�����ͻ���������ַ�������һ�£��������ͻ�ִ�е�SQL����е��ַ�����ȷ���ܹ�ʶ��
bool CMySQLConn::_SetServerNames()
{
    //WARING:��sql ����б�����˳��һ����ö�ٶ���һ��
    CHAR pszSql[1024] = {0};
    _snprintf(pszSql, 1024, "set names %s", m_szCharactSet);

    if(ExecuteSql(pszSql) < 0)
    {
        CRITICAL(_SDT("[%s]Set charset names: %s Failed\n"), _SDTA2T(__FUNCTION__), _SDTA2T(m_szCharactSet));
        return false;
    }
    return true;
}

#ifndef _WIN32
#define stricmp strcasecmp
#endif
//����û�����ı��뼯�Ƿ����mysql�Ĺ淶
bool CMySQLConn::_IsValidCharacterSet(const CHAR* pszSetName)
{
    for(int i = 0; g_stpCharSets[i] != NULL; i++)
    {
        if(0 == stricmp(pszSetName, g_stpCharSets[i]))
        {
            return true;
        }
    }
    CRITICAL(_SDT("[%s]The DB charset setting(%s) is nonexistent\n"), _SDTA2T(__FUNCTION__), _SDTA2T(pszSetName));
    return false;
}

bool CMySQLConn::IsUsed()
{
    return m_bUsed;
}

void CMySQLConn::SetUsed(bool bUsed)
{
    this->m_bUsed = bUsed;
}

MYSQL_STMT *CMySQLConn::GetStatementPrepared( const string &strStrSql )
{
    if( m_mapStmtPtr.find( strStrSql ) != m_mapStmtPtr.end() )
    {
        return m_mapStmtPtr[strStrSql];
    }

    MYSQL_STMT *pStmt = mysql_stmt_init( m_poConnection );
    if( NULL == pStmt )
    {
        CRITICAL(_SDT("[%s]The DB mysql_stmt_init error, code:%d"), _SDTA2T(__FUNCTION__), mysql_errno(m_poConnection) );
        return NULL;
    }

    INT32 nRet = mysql_stmt_prepare( pStmt, strStrSql.c_str(), strStrSql.size() );
    if( nRet != 0 )
    {
        mysql_stmt_close( pStmt );
        CRITICAL(_SDT("[%s]The DB mysql_stmt_close error, code:%d"), _SDTA2T(__FUNCTION__), nRet );
        return NULL;
    }

    m_mapStmtPtr[strStrSql] = pStmt;
    return pStmt;
}

BOOL CMySQLConn::BindParam( MYSQL_STMT *pStmt, MYSQL_BIND *pBind )
{
    if( NULL == pStmt || NULL == pBind )
    {
        return FALSE;
    }

    my_bool bRet = mysql_stmt_bind_param( pStmt, pBind );
    if( bRet )
    {
        CRITICAL(_SDT("[%s]The DB BindParam error, code:%d"), _SDTA2T(__FUNCTION__),
                 mysql_stmt_error(pStmt), mysql_stmt_errno(pStmt) );
        return FALSE;
    }

    return TRUE;
}

BOOL CMySQLConn::ExecuteStatementPrepared( MYSQL_STMT *pStmt )
{
    if( NULL == pStmt )
    {
        return FALSE;
    }
    INT32 nRet = mysql_stmt_execute( pStmt );
    if( nRet != 0 )
    {
        CRITICAL(_SDT("[%s]The DB mysql_stmt_execute error, code:%d"), _SDTA2T(__FUNCTION__), nRet );
        return FALSE;
    }

    const char *pszError = mysql_error( m_poConnection );
    if( pszError != NULL )
    {
        CRITICAL(_SDT("[%s]The DB mysql_stmt_execute error, code:%s"), _SDTA2T(__FUNCTION__), pszError );
        return FALSE;
    }
    return TRUE;
}