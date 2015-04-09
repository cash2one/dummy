/******************************************************************************
            

���ļ�������CSqlite3Connection�Ķ���,֧��UTF_8��UTF_16����,sqlite���ݿ������ֶδ�Сд

�ļ���ʷ��
1.�޸�ʱ�䣺	2011-07-20
  �޸�������    �����ļ� 
  �޸���  �� 	xujun
  ����
******************************************************************************/

#ifndef _SQLITE3DB_INCLUDE_H_
#define _SQLITE3DB_INCLUDE_H_

#include "sqlite3.h"
#include "stdio.h"
#include "sddebug.h"
#include "sdstring.h"
#include "sdtime.h"
#include <map>
#include <string.h>
using namespace std;

namespace SGDP
{
/**
@brief ��װSqlite3�ļ�¼��
*
*����	:ʵ����sqlite3�ļ�¼������
*/
	class CSqlite3RecordSet
	{
#define SDSQLITE_MAX_NAME_SIZE 64       //�ļ�����󳤶�
#define SDSQLITE_MAX_NUMBER_SIZE 64     //����ֽ���

        typedef std::map<string, INT32> CNameToIndexMap;  //�����ֶ���������ֵ֮���ӳ���ϵ
        typedef std::map<string, INT32>::iterator CNameToIndexMapItr;

		friend class CSqlite3Conn;
	public:

		/**
		* @brief ���캯������ʼ��sqlite��¼������
		*/
		CSqlite3RecordSet():m_poRes(NULL)
		{
		}

		/**
		* @brief �����������ͷ�sqlite��¼��
		*/
		~CSqlite3RecordSet()
		{
			if(NULL != m_poRes)
			{
				sqlite3_finalize(m_poRes);
			}
		}

		/**
        * @brief  ��ȡ�ֶθ���
        * @return �ֶθ���
        */
        UINT32  GetFieldCount();
	
		/**
        * @brief  ��ȡ��һ����¼��
        * @return TRUE:������һ����¼ FALSE:��ǰ��¼Ϊ���һ����¼
        */
		BOOL  GetRecord()
		{
			if(m_poRes == NULL)
				return FALSE;
			INT32 rc = sqlite3_step(m_poRes);//���ҽ����
			if(rc == SQLITE_BUSY)
			{
				fprintf(stderr,"SQL error :Sqlite busy!\n");
				return FALSE;
			}
			return (rc == SQLITE_ROW);      //���ص��м�
		}

		/**
        * @brief �����ֶ�����ȡ�ֶ�ֵ��std::string����)<ע�⣺ͨ�ýӿڣ������ݿ���ȡ�������ݶ�Ϊstring>
        * @param nIndex : �ֶε�����λ��
        * @return std::string���͵��ֶ�ֵ
        */
        const std::string  GetFieldValue(UINT32 nIndex)
		{
			CHAR* buf;
			string strValue = "";
			INT32 n = sqlite3_column_type(m_poRes,nIndex);
			switch(n)
			{
			case SQLITE_INTEGER:
				{
					CHAR tmpStr[SDSQLITE_MAX_NUMBER_SIZE] = {0};
					SDSnprintf(tmpStr,SDSQLITE_MAX_NUMBER_SIZE,"%d",sqlite3_column_int(m_poRes,nIndex));
                    strValue = tmpStr;
				}
				break;
			case SQLITE_FLOAT:
				{
					CHAR tmpStr[SDSQLITE_MAX_NUMBER_SIZE] = {0};
					SDSnprintf(tmpStr,SDSQLITE_MAX_NUMBER_SIZE,"%f",sqlite3_column_double(m_poRes,nIndex));
                    strValue = tmpStr;
				}
				break;
			case SQLITE_TEXT:
				{
					CHAR tmpStr[SDSQLITE_MAX_NAME_SIZE] = {0};
					SDSnprintf(tmpStr,SDSQLITE_MAX_NAME_SIZE,"%s",sqlite3_column_text(m_poRes,nIndex));
                    strValue = tmpStr;
				}
				break;
			case SQLITE_BLOB:
				{
					INT32 lenth = sqlite3_column_bytes(m_poRes,nIndex);//���������ݵĳ���
					buf = SDNew CHAR[lenth];
					const VOID* bData = sqlite3_column_blob(m_poRes,nIndex);//����������
					memcpy(buf,bData,lenth);
                    for(INT32 i=0;i<sizeof(buf);i++)
                        strValue.push_back(buf[i]);
                    SDDelete[] buf;
				}
				break;
			case SQLITE_NULL://���ؿ��ַ�������ʱ
				{
                    strValue = "\0";
				}
				break;
			default:break;
			}

			return strValue;
		}
		
		/**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�����
        * @param nIndex : �ֶε�����λ��
        * @return �ֶ�����
        */
		UINT32  GetFieldType(UINT32 nIndex);		

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
        const INT64  GetFieldValueInt64(const CHAR* pszFieldName)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return 0;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueInt64(m_mapFieldName[pszFieldName]);
            }
            return 0;
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
        const INT32  GetFieldValueInt32(const CHAR* pszFieldName)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return 0;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueInt32(m_mapFieldName[pszFieldName]);
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
        const DOUBLE  GetFieldValueDouble(const CHAR* pszFieldName)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return 0;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueDouble(m_mapFieldName[pszFieldName]);
            }
            return 0;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(�ַ�����)
        * @param nIndex : �ֶε�����λ��
        * @return �ַ������ֶ�ֵ
        */
		const UCHAR*  GetFieldValueString(UINT32 nIndex);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(�ַ�����)
        * @param pszFieldName : �ֶ���
        * @return �ַ������ֶ�ֵ
        */
        const UCHAR*  GetFieldValueString(const CHAR* pszFieldName)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return NULL;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueString(m_mapFieldName[pszFieldName]);
            }
            return NULL;
        }

        /**
        * @brief  ��ȡ��ǰ��¼��ָ������λ���ֶε�ֵ(����������)
        * @param nIndex : �ֶε�����λ��
        * @param nLength      : ���������ݵĳ���
        * @return �����������ֶ�ֵ
        */
		const VOID*  GetFieldValueBinary(UINT32 nIndex,UINT32 nLength);

        /**
        * @brief  ��ȡ��ǰ��¼��ָ���ֶ�����Ӧ���ֶ�ֵ(����������)
        * @param pszFieldName : �ֶ���
        * @param nLength      : ���������ݵĳ���
        * @return ���������ֶ�ֵ
        */
        const VOID*  GetFieldValueBinary(const CHAR* pszFieldName,UINT32 nLength)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return NULL;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueBinary(m_mapFieldName[pszFieldName],nLength);
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
        const BOOL  GetFieldValueBoolean(const CHAR* pszFieldName)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return FALSE;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueBoolean(m_mapFieldName[pszFieldName]);
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
        const CSDDateTime  GetFieldValueDatetime(const CHAR* pszFieldName)
        {
            CSDDateTime t;
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return t;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValueDatetime(m_mapFieldName[pszFieldName]);
            }
            return t;
        }

        /**
        * @brief ��ȡ��ָ�е��ֽ���
        * @param nIndex : �ֶε�����λ��
        * @return �ֽ���
        */
		const INT32  GetFieldBytes(UINT32 nIndex);

        /**
        * @brief ��ȡ��ǰ��¼����ĳһ���ֶε�����
        * @param nIndex : �ֶε�����λ��
        * @return �ֶ���
        */
		const CHAR*  GetFieldName(UINT32 nIndex);

        /**
        * @brief �����ֶ�����ȡ�ֶ�ֵ��std::string����)<ע�⣺ͨ�ýӿڣ������ݿ���ȡ�������ݶ�Ϊstring>
        * @param pszFieldName : �ֶ���
        * @return std::string���͵��ֶ�ֵ
        */
        const std::string GetFieldValueByName(const CHAR* pszFieldName)
        {
            // ���ε���ʱ�����Map���Ժ�ÿ�μ��Map�Ƿ���ֵ��
            if(0 == m_mapFieldName.size())
            {
                if (FALSE == _FillMap())
                {
                    return NULL;
                }
            }
            CNameToIndexMapItr itrFind;
            itrFind= m_mapFieldName.find(pszFieldName);
            if(itrFind != m_mapFieldName.end())
            {
                return this->GetFieldValue(m_mapFieldName[pszFieldName]);
            }
            return NULL;
        }

    protected:

        /**
        * @brief  ����ֶ�������������ӳ���ϵ
        * @return TRUE:���ɹ� FALSE:���ʧ��
        */
        BOOL	_FillMap()
        {
            if(NULL == m_poRes)
            {
                return FALSE;
            }
            UINT32 nCount = GetFieldCount();
            for(UINT32 i=0;i<nCount;i++)
            {
                m_mapFieldName[GetFieldName(i)] = i;
            }
            return TRUE;
        }
	protected:
		sqlite3_stmt*   m_poRes;
        CNameToIndexMap m_mapFieldName;
	};

/**
@brief ��װSqlite3������
*
*����	:ʵ����sqlite3�����Ӳ���
*/
	class CSqlite3Conn
	{
	public:

		/**
		* @brief ���캯������ʼ��sqlite���Ӷ������ݿ�����
		*/
		CSqlite3Conn();

		/**
		* @brief �����������ر�sqlite����
		*/
		~CSqlite3Conn();

		/**
        * @brief ������
        * @param pszDBName : ���ݿ���
        * @return TRUE:���ӳɹ� FALSE:����ʧ��
        */
		BOOL  Connect(const CHAR* pszDBName);

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
        * @brief ִ��һ��SQL��䣬�����ؼ�¼��
        * @param pszSQL : SQL���
        * @return TRUE:ִ�гɹ� FALSE:ִ��SQL���ʧ��
        */
        BOOL  Execute(const CHAR* pszSQL);
        
        /**
        * @brief ִ��һ��SQL��䣬���ؼ�¼��
        * @param pszSQL : SQL���
        * @param rcdSet : sqlite��¼��
        * @return TRUE:ִ�гɹ� FALSE:ִ��SQL���ʧ��
        */
        BOOL  Execute(const CHAR* pszSQL, CSqlite3RecordSet* rcdSet);

        /**
        * @brief �������������(../../�����������е�����ֵ����1��ʼ������/������Դ����/������Դ���ݵ��ֽ���)
        * @param pszSQL : SQL���
        * @param rcdSet : sqlite��¼��
        * @param nIndex : �ֶ�����λ��
        * @param pData  : ȡ�õĶ��������ݻ�����
        * @param nLength: ���������ݻ���������
        * @return TRUE:ִ�гɹ� FALSE:ִ��SQL���ʧ��
        */
		BOOL  ExecuteEx(const CHAR* pszSQL,CSqlite3RecordSet* rcdSet,UINT32 nIndex,VOID* pData,INT32 nLength);

	private:
		CHAR        m_szDBName[SDSQLITE_MAX_NAME_SIZE];
		sqlite3*    m_poConnection; 
		BOOL        m_bConnected;
	};


    /*
    //sqlite3db����������
    */
    //��ȡ�ֶθ���
    inline  UINT32 CSqlite3RecordSet::GetFieldCount()
    {
        return sqlite3_column_count(m_poRes);
    }
    //**�������ͷֱ��ȡ��Ӧ�ֶε�ֵ**//
    //���жϵ�ǰ��¼����ĳһ�е��ֶ����ͣ�1-int,2-double,3-unsigned char*,4-void *,5-���ַ���
    inline UINT32 CSqlite3RecordSet::GetFieldType(UINT32 nIndex)
    {
        return sqlite3_column_type(m_poRes,nIndex);
    }		

    inline	const INT64 CSqlite3RecordSet::GetFieldValueInt64(UINT32 nIndex)
    {
        return sqlite3_column_int64(m_poRes,nIndex);
    }

    inline  const INT32 CSqlite3RecordSet::GetFieldValueInt32(UINT32 nIndex)
    {
        return sqlite3_column_int(m_poRes,nIndex);
    }

    inline const DOUBLE CSqlite3RecordSet::GetFieldValueDouble(UINT32 nIndex)
    {
        return sqlite3_column_double(m_poRes,nIndex);
    }

    inline const UCHAR* CSqlite3RecordSet::GetFieldValueString(UINT32 nIndex)
    {
        return sqlite3_column_text(m_poRes,nIndex);
    }

    inline const VOID* CSqlite3RecordSet::GetFieldValueBinary(UINT32 nIndex,UINT32 nLength)
    {
        nLength = sqlite3_column_bytes(m_poRes,nIndex);//���������ݵĳ���
        return sqlite3_column_blob(m_poRes,nIndex);
    }

    inline const BOOL CSqlite3RecordSet::GetFieldValueBoolean(UINT32 nIndex)
    {
        if(SDStrcmp(GetFieldValue(nIndex).c_str(),"true")==0)
            return TRUE;
        else if(SDStrcmp(GetFieldValue(nIndex).c_str(),"false")==0)
            return FALSE;
        return FALSE;
    }

    //��ȡ����ʱ��ֵ
    inline const CSDDateTime CSqlite3RecordSet::GetFieldValueDatetime(UINT32 nIndex)
    {
        CSDDateTime t;
        if( TRUE == SDTimeFromString(_SDTA2T(GetFieldValue(nIndex).c_str()),t) )
            return t;
        return t;
    }

    //��ȡ��ָ�е��ֽ���
    inline const INT32 CSqlite3RecordSet::GetFieldBytes(UINT32 nIndex)
    {
        INT32 lenth = sqlite3_column_bytes(m_poRes,nIndex);//���ݵĳ���
        return lenth;
    }
    //��ȡ��ǰ��¼����ĳһ���ֶε�����
    inline const CHAR* CSqlite3RecordSet::GetFieldName(UINT32 nIndex)
    {
        return sqlite3_column_name(m_poRes,nIndex);
    }

};

#endif

