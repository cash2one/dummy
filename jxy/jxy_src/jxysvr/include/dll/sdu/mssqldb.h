
#ifndef _MSSQLDB_INCLUDE_H_
#define _MSSQLDB_INCLUDE_H_

#if (defined(WIN32) || defined(WIN64))
#include <sdtype.h>
#include <string>
#include <sdstring.h>
#include <comutil.h>
#import "c:\program files\common files\system\ado\msado25.tlb" no_namespace rename ("EOF", "adoEOF")


namespace SGDP
{
class CMSSQLConnection;

/**
@brief ��װADO��_CommandPtr������Ҫ�������CMSSQLConnectionִ�д洢����
*
* CMSSQLCommand��װ��ADO�е�Command���󣬲����ɶ���߳�ͬʱ����������ʵ��
* ��Ҫ�������CMSSQLConnectionִ�д洢����
* ����CMSSQLCommandʱ��Ҫ����CMSSQLConnection�Ķ���ָ��
* ���״ε���AddParameterʱ��Ҫȷ�������б������
* �ɵ��÷����𲶻�_com_error �쳣
*/

class CMSSQLCommand
{
    friend class CMSSQLConnection;
public:
    /**
    * @brief ���캯��
    */
    CMSSQLCommand()
    {
        m_pCommand.CreateInstance(__uuidof(Command));
    }

    /**
    * @brief ��������
    */
    ~CMSSQLCommand()
    {
    }

    /**
    * @brief ����Command Type
    * @param Type : ָ������������
    */
    VOID SetCommandType(enum CommandTypeEnum Type)
    {
        m_pCommand->CommandType = Type;
    }

    /**
    * @brief ����Command ����
    * @param Type : ָ������������
    */
    VOID SetCommandText(const CHAR* pszText)
    {
        m_pCommand->CommandText = pszText;
    }

    /**
    * @brief ���������е�һ������
    * @param Type : ������������
    * @param Direction : ��������
    * @param Size : ��������
    * @param Value : ����ֵ
    */
    VOID AddParameter(const CHAR* Name, enum DataTypeEnum Type, enum ParameterDirectionEnum Direction,
                      long Size, const _variant_t& Value = vtMissing)
    {
        m_pCommand->Parameters->Append(m_pCommand->CreateParameter(Name, Type, Direction, Size, Value));
    }

    /**
    * @brief ��ȡĳ�������ķ���ֵ
    * @param Name : ָ������������
    */
    _variant_t GetItemValue(const CHAR* Name)
    {
        return m_pCommand->Parameters->GetItem(Name)->GetValue();
    }
    /**
    * @brief ������в�����Ŀǰδ�ṩ
    */
    void ClearParameters()
    {
        for (long i = m_pCommand->Parameters->Count - 1; i >= 0; i--)
            m_pCommand->Parameters->Delete(i);
    }
    /**
    * @brief ɾ��һ������
    * @param Name : ָ������������
    */
    void DeleteParameter(const CHAR* Name)
    {
        m_pCommand->Parameters->Delete(Name);
    }

private:
    _CommandPtr m_pCommand;   ///< �������
};

/**
@brief ��װADO��_RecordsetPtr����
*
*	��װADO��_RecordsetPtr���󣬲����ɶ���߳�ͬʱ����������ʵ��
*  �ɵ��÷����𲶻�_com_error �쳣
*/

class CMSSQLRecordSet
{
    friend class CMSSQLConnection;
public:
    /**
    * @brief ���캯��
    */
    CMSSQLRecordSet() {}
    /**
    * @brief ��������
    */
    ~CMSSQLRecordSet() {};

    /**
    * @brief �ƶ�����¼���ײ�
    */
    void MoveFirst()
    {
        if (m_pRecordSet)  m_pRecordSet->MoveFirst();
    }
    /**
    * @brief �ƶ�����¼����һ��
    */
    void MoveNext()
    {
        if (m_pRecordSet) m_pRecordSet->MoveNext();
    }

    ///�ƶ�����¼����һ��
    void MovePrevious()
    {
        if (m_pRecordSet)  m_pRecordSet->MovePrevious();
    }

    /**
    * @brief �ƶ�����¼��β��
    */
    void MoveLast()
    {
        if (m_pRecordSet) m_pRecordSet->MoveLast();
    }

    /**
    * @brief �Ƿ�Խ����¼��ĩβ
    */
    BOOL IsEof()
    {
        if (m_pRecordSet)
            return m_pRecordSet->adoEOF;
        else
            return FALSE;
    }
    /**
    * @brief �Ƿ�Խ����¼���ײ�
    */
    BOOL IsBof()
    {
        if (m_pRecordSet)
            return m_pRecordSet->BOF;
        else
            return FALSE;
    }

    /**
    * @brief �õ���¼����
    */
    DWORD GetRecordCount()
    {
        DWORD nRows = 0;

        nRows = (DWORD)m_pRecordSet->GetRecordCount();

        if(nRows == -1)
        {
            nRows = 0;
            if(m_pRecordSet->adoEOF != VARIANT_TRUE)
                m_pRecordSet->MoveFirst();

            while(m_pRecordSet->adoEOF != VARIANT_TRUE)
            {
                nRows++;
                m_pRecordSet->MoveNext();
            }
            if(nRows > 0)
                m_pRecordSet->MoveFirst();
        }

        return nRows;
    }
    /**
    * @brief ��ȡĳһ�ֶε�ֵ
    */
    _variant_t GetFieldValue(const CHAR* pszFieldName)
    {
        _variant_t vtResult;
        if (m_pRecordSet)
            vtResult = m_pRecordSet->Fields->GetItem(pszFieldName)->Value;
        else
            vtResult.vt = VT_NULL;
        return vtResult;
    }

    ///
    /**
    * @brief �õ���¼�����ֶεĸ���
    */
    DWORD GetFieldCount()
    {
        if (m_pRecordSet)
            return m_pRecordSet->Fields->Count;
        else
            return 0;
    }
private:
    _RecordsetPtr m_pRecordSet;         ///< ��¼��
};


/**
@brief ��װADO��_ConnectionPtr����
*
*  ��װADO��_ConnectionPtr���󣬲����ɶ���߳�ͬʱ����������ʵ��
*  �ڽ���_com_error�쳣���񣬵�����FALSEʱGetLastErrorInfo�ɻ�ô�������
*/

class CMSSQLConnection
{
    friend class CMSSQLCommand;
    friend class CMSSQLRecordSet;
public:
    /**
    * @brief ���캯��
    */
    CMSSQLConnection(void);
    /**
    * @brief ��������
    */
    ~CMSSQLConnection(void);

    /**
    * @brief ���������ַ���
    */
    void SetConnectionString(const CHAR* pszConnectionString)
    {
        m_strConnectionString = pszConnectionString;
    }

    /**
    * @brief ������
    */
    BOOL Connect(const CHAR* pszConnectionString);

    /**
    * @brief ������
    */
    BOOL Connect();
    /**
    * @brief �ر�����
    */
    void Close();

    /**
    * @brief ִ��һ��CMSSQLCommand���󣬲����ؼ�¼��
    */
    BOOL Execute(CMSSQLCommand& command, CMSSQLRecordSet& pSet);

    /**
    * @brief ִ��һ��CMSSQLCommand���󣬲����ؼ�¼��
    */
    BOOL Execute(CMSSQLCommand& command);

    /**
    * @brief ִ��һ��SQL��䣬�����ؼ�¼��
    */
    BOOL Execute(CHAR* pszSQL, CMSSQLRecordSet& pSet);

    /**
    * @brief ִ��һ��SQL��䣬�����ؼ�¼��
    */
    BOOL Execute(CHAR* pszSQL);

    /**
    * @brief �Ƿ�������
    */
    BOOL IsConnected();

    ///��ȡ��һ�������
    DWORD GetLastError()
    {
        return m_dwErrCode;
    }

    ///��ȡ��һ����������
    const char* GetLastErrorInfo()
    {
        return m_strErrInfo.c_str();
    }

protected:

private:
    //driver=sql Server;PWD=sa;UID=sa;database=db;server=127.0.0.1
    std::string     m_strConnectionString;
    _ConnectionPtr  m_pDBConnection;
    DWORD           m_dwErrCode;
    std::string     m_strErrInfo;
    void SetLastError(DWORD dwErrCode)
    {
        m_dwErrCode = dwErrCode;
    }
    void SetLastError(_com_error& e)
    {
        m_dwErrCode = e.WCode();
        m_strErrInfo = e.Description();
    }
    void SetLastErrorInfo(const CHAR* pszErrInfo)
    {
        m_strErrInfo = pszErrInfo;
    }
    inline void TESTHR(HRESULT x)
    {
        if FAILED(x) _com_issue_error(x);
    }
};

};
#endif
#endif

