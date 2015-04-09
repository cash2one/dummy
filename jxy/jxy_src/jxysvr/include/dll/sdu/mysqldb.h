/******************************************************************************


���ļ�������CMySqlConnection�Ķ��壬mysql���ݿⲻ�����ֶδ�Сд

�ļ���ʷ��
1.�޸�ʱ�䣺	2011-07-25
�޸�������    �����ļ� 
�޸���  �� 	xujun
����
******************************************************************************/

#ifndef _MYSQLDB_INCLUDE_H_
#define _MYSQLDB_INCLUDE_H_

#include <sdnetutils.h>
#include "mysql.h"
#include <sdstring.h>
#include <sdtime.h>
#include <map>

namespace SGDP
{
    /**
    * @brief ��װMySQL�ļ�¼��
    *
    *	��װMySQL�ļ�¼���������ɶ���߳�ͬʱ����������ʵ��
    */

    class CMySQLRecordSet
    {
//         struct CmpObj
//         {
//             BOOL operator()(std::string pSrc, std::string pDst) const 
//             {
//                 return SDStrcmp(pSrc.c_str(), pDst.c_str()) < 0;
//             }
// 
//         }; 
        typedef std::map<std::string, INT32> CNameToIndexMap;              //�洢������������ӳ���ϵ
        typedef std::map<std::string, INT32>::iterator CNameToIndexMapItr;
        friend class CMySQLConnection;
    public:
        /*mysql֧�ֵĳ�����������*/
        enum mysqltype
        {
            MYSQL_INT32=1,
            MYSQL_INT64,
            MYSQL_DOUBLE,
            MYSQL_BLOB,
            MYSQL_NULL,
            MYSQL_STRING};

	/**
	* @brief ���캯������ʼ��mysql��¼������
	*/
        CMySQLRecordSet(): m_poRes(NULL), m_oRow(NULL)
        {
        }

	/**
	* @brief �����������ͷ�mysql��¼��
	*/
        ~CMySQLRecordSet()
        {
            if(m_poRes)
                mysql_free_result(m_poRes);
        }

        /**
        * @brief  ��ȡ��¼����
        * @return ��¼����
        */
        UINT32  GetRecordCount() ;

        /**
        * @brief  ��ȡ�ֶθ���
        * @return �ֶθ���
        */
        UINT32  GetFieldCount();

        /**
        * @brief  ��ȡ��һ����¼��
        * @return TRUE:������һ����¼ FALSE:��ǰ��¼Ϊ���һ����¼
        */
        BOOL  GetRecord();

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶεĳ���
        * @param nIndex : �ֶε�����λ��
        * @return �ֶγ���
        */
        const UINT32  GetFieldLenth(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�����
        * @param nIndex : �ֶε�����λ��
        * @return �ֶ�����
        */
        const UINT32  GetFieldType(UINT32 nIndex)
        {
            UINT32 num_poFields = GetFieldCount();
            if (nIndex >= num_poFields)
                return -1;

            m_poField = mysql_fetch_field(m_poRes);//��ȡ�ֶεĽṹ����Ϣ
            UINT32 nTypeIndex = 0;
            if(m_poField[nIndex].type == MYSQL_TYPE_TINY||MYSQL_TYPE_SHORT||
                MYSQL_TYPE_LONG||MYSQL_TYPE_INT24)//4������(<32λ��
            {
                nTypeIndex = MYSQL_INT32; 
            }
            else if(m_poField[nIndex].type == MYSQL_TYPE_LONGLONG)//�����ͣ�64λ��
            {
                nTypeIndex = MYSQL_INT64;
            }
            else if(m_poField[nIndex].type == MYSQL_TYPE_DECIMAL||MYSQL_TYPE_NEWDECIMAL
                ||MYSQL_TYPE_FLOAT||MYSQL_TYPE_DOUBLE)//������
            {
                nTypeIndex = MYSQL_DOUBLE;
            }
            else if(m_poField[nIndex].type == MYSQL_TYPE_TINY_BLOB||MYSQL_TYPE_MEDIUM_BLOB
                ||MYSQL_TYPE_LONG_BLOB||MYSQL_TYPE_BLOB)//����������
            {
                nTypeIndex = MYSQL_BLOB;
            }
            else if(m_poField[nIndex].type == MYSQL_TYPE_NULL)//������
            {
                nTypeIndex = MYSQL_NULL;
            }
            else
                nTypeIndex = MYSQL_STRING;//Ĭ���ַ�������
            return nTypeIndex;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(����)
        * @param nIndex : �ֶε�����λ��
        * @return �����ֶ�ֵ
        */
        const INT32  GetFieldValueInt32(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(����)
        * @param pszFieldName : �ֶ���
        * @return �����ֶ�ֵ
        */
        const INT32  GetFieldValueInt32(CHAR* pszFieldName)
        {
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return 0;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueInt32(m_mapFieldName[SDStrlwr(tmpStr)]);
            }
            return 0;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(������)
        * @param nIndex : �ֶε�����λ��
        * @return �������ֶ�ֵ
        */
        const INT64  GetFieldValueInt64(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(������)
        * @param pszFieldName : �ֶ���
        * @return �������ֶ�ֵ
        */
        const INT64  GetFieldValueInt64(CHAR* pszFieldName)
        {
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return 0;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueInt64(m_mapFieldName[SDStrlwr(tmpStr)]);
            }
            return 0;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(������)
        * @param nIndex : �ֶε�����λ��
        * @return �������ֶ�ֵ
        */
        const DOUBLE  GetFieldValueDouble(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(������)
        * @param pszFieldName : �ֶ���
        * @return �������ֶ�ֵ
        */
        const DOUBLE  GetFieldValueDouble(CHAR* pszFieldName)
        {
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return 0;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueDouble(m_mapFieldName[SDStrlwr(tmpStr)]);
            }
            return 0;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(�ַ�����)
        * @param nIndex : �ֶε�����λ��
        * @return �ַ������ֶ�ֵ
        */
        const CHAR*  GetFieldValueString(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(�ַ�����)
        * @param pszFieldName : �ֶ���
        * @return �ַ������ֶ�ֵ
        */
        const CHAR*  GetFieldValueString(CHAR* pszFieldName)
        {
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return NULL;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueString(m_mapFieldName[SDStrlwr(tmpStr)]);
            }
            return NULL;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(����������)
        * @param nIndex : �ֶε�����λ��
        * @param nLength      : ���������ݵĳ���
        * @return �����������ֶ�ֵ
        */
        const VOID*  GetFieldValueBinary(UINT32 nIndex,UINT32& nLength);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(����������)
        * @param pszFieldName : �ֶ���
        * @param nLength      : ���������ݵĳ���
        * @return ���������ֶ�ֵ
        */
        const VOID*  GetFieldValueBinary(CHAR* pszFieldName,UINT32& nLength)
        {
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return NULL;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueBinary(m_mapFieldName[SDStrlwr(tmpStr)],nLength);
            }
            return NULL;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(BOOL��)
        * @param nIndex : �ֶε�����λ��
        * @return BOOL���ֶ�ֵ
        */
        const BOOL  GetFieldValueBoolean(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(BOOL��)
        * @param pszFieldName : �ֶ���
        * @return BOOL���ֶ�ֵ
        */
        const BOOL  GetFieldValueBoolean(CHAR* pszFieldName)
        {
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return FALSE;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueBoolean(m_mapFieldName[SDStrlwr(tmpStr)]);
            }
            return FALSE;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(DateTime����)
        * @param nIndex : �ֶε�����λ��
        * @return DateTime�����ֶ�ֵ
        */
        const CSDDateTime  GetFieldValueDatetime(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(DateTime��)
        * @param pszFieldName : �ֶ���
        * @return DateTime���ֶ�ֵ
        */
        const CSDDateTime  GetFieldValueDatetime(CHAR* pszFieldName)
        {
            CSDDateTime t;
            std::string tmpStr = pszFieldName;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return t;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(SDStrlwr(tmpStr));
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueDatetime(m_mapFieldName[SDStrlwr(tmpStr)]);
            }
            return t;
        }

        /**
        * @brief  ��ȡ��ǰ��¼����ĳһ���ֶε�����
        * @param nIndex : �ֶε�����λ��
        * @return �ֶ�����
        */
        const CHAR* GetFieldName(UINT32 nIndex);
    private:
    
        /**
        * @brief  ����ֶ�������������ӳ���ϵ <!ע��:map�д�����ֶ�������Сд��>
        * @return TRUE:���ɹ� FALSE:���ʧ��
        */
        BOOL _FillMap()
        {
            if(NULL == m_poRes)
            {
                return FALSE;
            }
            MYSQL_FIELD* field = NULL;
            INT32 nIndex = 0;
            while(field = mysql_fetch_field(m_poRes))
            {
                std::string tmpStr = field->name;
                m_mapFieldName[SDStrlwr(tmpStr)] = nIndex;
                ++nIndex;
            }
            return TRUE;
        }

    private:
        MYSQL_RES*  m_poRes;
        MYSQL_ROW   m_oRow;       
        MYSQL_FIELD* m_poField;
        CNameToIndexMap m_mapFieldName;
    };

    /**
    @brief ��װMySQL������
    *
    *	��װMySQL�����ӣ������ɶ���߳�ͬʱ����������ʵ��
    */

    class CMySQLConnection
    {
#define SDMYSQLDB_MAX_NAME_SIZE 64
        enum ESDMYSQLDBCode
        {
            SDMYSQLDB_ERR_UNKNOWN    = -999, // δ֪����
            SDMYSQLDB_ERR_CONN       = -2,   // ���Ӵ���
            SDMYSQLDB_DISCONNECT     = -1,   // �Ͽ��������������
            SDMYSQLDB_SUCCESS        = 0,    // �����ɹ�
            SDMYSQLDB_NO_RECORDSET   = 1,    // �����ɹ�����û�н����
            SDMYSQLDB_HAS_RECORDSET  = 2     // �����ɹ����н����
        };
    public:

	/**
	* @brief ���캯��
	*/
        CMySQLConnection();

	/**
	* @brief �����������ر�mysql����
	*/
        ~CMySQLConnection();

        /**
        * @brief ����������Ϣ
        * @param pszServerAddr : mysql���ݿ��������ַ
        * @param nServerPort   : mysql���ݿ�������˿�
        * @param pszDBName     : mysql���ݿ���
        * @param pszUserID     : mysql���ݿ��û���
        * @param pszPassword   : mysql���ݿ�����
        * @param pszCharset    : mysql���ݿ��ַ���
        * @return VOID
        */
        VOID  SetConnectionString(const CHAR* pszServerAddr, INT32 nServerPort, 
            const CHAR* pszDBName, const CHAR* pszUserID, const CHAR* pszPassword,
            const CHAR* pszCharset);

        /**
        * @brief ������
        * @param pszServerAddr : mysql���ݿ��������ַ
        * @param nServerPort   : mysql���ݿ�������˿�
        * @param pszDBName     : mysql���ݿ���
        * @param pszUserID     : mysql���ݿ��û���
        * @param pszPassword   : mysql���ݿ�����
        * @param pszCharset    : mysql���ݿ��ַ���
        * @return TRUE:���ӳɹ� FALSE:����ʧ��
        */
        BOOL  Connect(const CHAR* pszServerAddr, INT32 nServerPort, 
            const CHAR* pszDBName, const CHAR* pszUserID, const CHAR* pszPassword,
            const CHAR* pszCharset);

        /**
        * @brief �����ӣ�������������Ϣ�����
        * @return TRUE:���ӳɹ� FALSE:����ʧ��
        */
        BOOL  Connect();

        /**
        * @brief �ر�����
        * @return VOID
        */
        VOID  Close();

        /**
        * @brief �Ƿ�������
        * @return TRUE:�Ѿ����� FALSE:û����
        */
        BOOL  IsConnected();

        /**
        * @brief mysql_ping�ķ�װ
        * @return pingֵ
        */
        INT32  Ping();

        /**
        * @brief ת���ַ�����ʹ֮������MYSQL��ѯ
        * @param pszSrc : Դ�ַ���
        * @param nSize  : �ַ�������
        * @param pszDest: Ŀ���ַ���
        * @return ����ɹ�ת�����򷵻�pszDest;���򷵻�NULL
        */
        CHAR*  EscapeString(const CHAR* pszSrc, INT32 nSize, CHAR* pszDest)
        {		
            if (m_poMyConnection)
            {
                mysql_real_escape_string(m_poMyConnection, pszDest, pszSrc, nSize);
                return pszDest;
            }
            else
                return NULL;
        }

        /**
        * @brief �����յ����һ��UPDATE��DELETE��INSERT��ѯӰ��(�仯)������
        * @return ��Ӱ�������
        */
        UINT32  GetAffectedRows() 
        { 
            return (UINT32)mysql_affected_rows(m_poMyConnection); 
        }

        /**
        * @brief ת���ַ�����ʹ֮������MYSQL��ѯ
        * @param pszSrc : Դ�ַ���
        * @param pszDest: Ŀ���ַ���
        * @return ת���ַ���
        */
        CHAR*  EscapeString(const CHAR* pszSrc, CHAR* pszDest)
        {
            return EscapeString(pszSrc, (INT32)strlen(pszSrc), pszDest);
        }

        /**
        * @brief ת���ַ�����ʹ֮������MYSQL��ѯ����Ҫ����ת��2��������
        * @param pszSrc : Դ�ַ���
        * @param nSize��: Դ�ַ�����С
        * @param pszDest: Ŀ���ַ���
        * @return 0:ת��ʧ�� ��0:ת��ɹ�
        */
        UINT32  EscapeStringEx(const CHAR* pszSrc, INT32 nSize, CHAR* pszDest)
        {
            if (m_poMyConnection)
            {
                return mysql_real_escape_string(m_poMyConnection, pszDest, pszSrc, nSize);
            }
            else
            {
                return 0;
            }
        }

        /**
        * @brief �޲��ִ��SQL��䣬ͨ������ֵ�жϾ���Ч��
        * @param pszSQL : SQL���
        * @param rcSet  : mysql��¼��
        * @return ESDMYSQLDBCode(��ö�ٶ���)
        */
        ESDMYSQLDBCode   ExecuteEx(const CHAR* pszSQL, CMySQLRecordSet& rcdSet);

        /**
        * @brief �޲��ִ��SQL��䣬ͨ������ֵ�жϾ���Ч��(֧�ֶ����ƴ�������)
        * @param pszSQL : SQL���
        * @param nLength: ���������ݳ���
        * @param rcdSet : mysql��¼��
        * @return ESDMYSQLDBCode(��ö�ٶ���)
        */
        ESDMYSQLDBCode   ExecuteEx(const CHAR* pszSQL, INT32 nLength,CMySQLRecordSet& rcdSet);

        /**
        * @brief ִ��һ��SQL��䣬�����ؼ�¼��
        * @param pszSQL : SQL���
        * @return TRUE:ִ�гɹ� FALSE:ִ��SQL���ʧ��
        */
        BOOL  Execute(const CHAR* pszSQL);

        /**
        * @brief ִ��һ��SQL��䣬���ؼ�¼��
        * @param pszSQL : SQL���
        * @param rcdSet : mysql��¼��
        * @return TRUE:ִ�гɹ� FALSE:ִ��SQL���ʧ��
        */
        BOOL  Execute(const CHAR* pszSQL, CMySQLRecordSet& rcdSet);

        /**
        * @brief ��ȡ��һ�δ����
        * @return �����
        */
        ULONG  GetLastError() 
        { 
            if(m_poMyConnection!=NULL)
            {
                return (ULONG)mysql_errno(m_poMyConnection);
            }
            return  0;
        }

        /**
        * @brief ��ȡ��һ�δ�������
        * @return ��������
        */
        const CHAR*  GetLastErrorInfo()
        { 
            if(m_poMyConnection!=NULL)
            {
                return mysql_error(m_poMyConnection);
            }
            return NULL;
        }

    private:

        /**
        * @brief ��ȡmysql���ݿ��ַ�����Ϣ
        * @return TRUE:��ȡ�ɹ� FALSE:��ȡʧ��
        */
        BOOL _GetDBSCharSetInfo();

        /**
        * @brief ����ַ����ļ�����
        * @return TRUE:���� FALSE:������
        */
        BOOL _IsCompatiableCharSet();

        /**
        * @brief ���÷���������
        * @return TRUE:���óɹ� FALSE:����ʧ��
        */
        BOOL _SetServerNames();

        /**
        * @brief ����û�����ı��뼯�Ƿ����mysql�Ĺ淶
        * @param pszSetName : �û�����ı��뼯
        * @return TRUE:���� FALSE:������
        */
        BOOL _IsValidCharacterSet(const CHAR* pszSetName);
        //

    private:

        CHAR    m_szServerAddr[SDMYSQLDB_MAX_NAME_SIZE];
        CHAR    m_szDBName[SDMYSQLDB_MAX_NAME_SIZE];
        CHAR    m_szCharset[SDMYSQLDB_MAX_NAME_SIZE];
        CHAR    m_szUserID[SDMYSQLDB_MAX_NAME_SIZE];
        CHAR    m_szPassword[SDMYSQLDB_MAX_NAME_SIZE];

        INT32   m_nServerPort;
        MYSQL*  m_poMyConnection;
        BOOL    m_bConnected;

        typedef std::map<std::string, std::string> Charsets;
        Charsets m_oCharsets;
    };

    /*
    //mysql��������
    */
    ///��ȡ��¼����
    inline UINT32 CMySQLRecordSet::GetRecordCount() 
    { 
        return (m_poRes ? (UINT32)mysql_num_rows(m_poRes) : 0);
    }

    ///��ȡ�ֶθ���
    inline UINT32 CMySQLRecordSet::GetFieldCount() 
    { 
        return (m_poRes ? (UINT32)mysql_num_fields(m_poRes) : 0);
    }

    ///��ȡ��һ����¼��
    inline BOOL CMySQLRecordSet::GetRecord()
    {
        if (m_poRes == NULL)
            return FALSE;
        m_oRow = mysql_fetch_row(m_poRes);
        return (m_oRow != NULL);
    }

    //��ȡ��ǰ��¼��ĳһ���ֶεĳ���
    inline const UINT32 CMySQLRecordSet::GetFieldLenth(UINT32 nIndex)
    {
        UINT32 num_poFields = GetFieldCount();
        if (nIndex >= num_poFields)
            return 0;
        ULONG* lengths = mysql_fetch_lengths(m_poRes);
        if (NULL==lengths)
        {
            return 0;
        }
        return lengths[nIndex];
    }

    //��ȡ������(char*תint32)
    inline const INT32 CMySQLRecordSet::GetFieldValueInt32(UINT32 nIndex)
    {
        return SDAtoi(m_oRow[nIndex]);
    }

    //��ȡ������(char*תint64)
    inline const INT64 CMySQLRecordSet::GetFieldValueInt64(UINT32 nIndex)
    {
        return SDAtoi64(m_oRow[nIndex]); 
    }

    //��ȡ��������(char*תdouble)
    inline const DOUBLE CMySQLRecordSet::GetFieldValueDouble(UINT32 nIndex)
    {
        return SDStrtod(m_oRow[nIndex],NULL);
    }

    //��ȡ�ַ�����
    inline const CHAR* CMySQLRecordSet::GetFieldValueString(UINT32 nIndex)
    {
        if (m_oRow == NULL)
            return NULL;
        if (nIndex >= GetFieldCount())
            return NULL;
        return m_oRow[nIndex];
    }

    //��ȡ������������
    inline const VOID* CMySQLRecordSet::GetFieldValueBinary(UINT32 nIndex,UINT32& nLength)
    {
        nLength = GetFieldLenth(nIndex);
        VOID* bData = NULL;
        memcpy(bData,m_oRow[nIndex],GetFieldLenth(nIndex));
        return bData;
    }

    //��ȡboolֵ
    inline const BOOL CMySQLRecordSet::GetFieldValueBoolean(UINT32 nIndex)
    {
        if(SDStrcmp(m_oRow[nIndex],"true")==0)
            return TRUE;
        else if(SDStrcmp(m_oRow[nIndex],"false")==0)
            return FALSE;
        return FALSE;
    }

    //��ȡ����ʱ��ֵ
    inline const CSDDateTime CMySQLRecordSet::GetFieldValueDatetime(UINT32 nIndex)
    {
        CSDDateTime t;
        if( TRUE == SDTimeFromString(_SDTA2T(m_oRow[nIndex]),t) )
            return t;
        return t;
    }

    //��ȡ��ǰ��¼����ĳһ���ֶε�����
    inline const CHAR* CMySQLRecordSet::GetFieldName(UINT32 nIndex)
    {
        if (m_oRow == NULL)
            return NULL;
        if (nIndex >= GetFieldCount())
            return NULL;
        return m_poField[nIndex].name;
    }

};

#endif


