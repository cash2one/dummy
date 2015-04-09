
#ifndef SGDP_DB_ODBC_RECODRSET_H_20100823
#define SGDP_DB_ODBC_RECODRSET_H_20100823

#if (defined(WIN32) || defined(WIN64))

#include "sddb.h"
#include <sqlext.h>
// 
// ������   : CODBCRecordSet
// ����     : <�̳в�ʵ����ISDDBRecordSet��Ľӿڣ��ṩSQLִ�н����¼������ز���>
//
class CODBCRecordSet : public SGDP::ISDDBRecordSet
{
	friend class CODBCConn;
public:
	CODBCRecordSet();
	~CODBCRecordSet();

	//
	// ������:  GetRecordCount
	// ����:    ��ȡ��¼����
	// ����ֵ:  ��¼����
	//
	UINT32 SDAPI GetRecordCount();

	//
	// ������:  GetFieldCount
	// ����:    ��ȡ�ֶθ���
	// ����ֵ:  �ֶθ���
	//
	UINT32 SDAPI GetFieldCount();

	//
	// ������:  GetRecord
	// ����:    ��ȡ��һ����¼��
	// ����ֵ:  �������ֵΪTRUE��ʾ��ȡ�ɹ������Ϊfalse��ʾ��ȡʧ��
	//
	bool SDAPI GetRecord();

	//
	// ������:  GetFieldValue
	// ����:    ��ȡ��ǰ��¼����ĳһ���ֶε�ֵ
	// ����:    [in] dwIndex:�ֶζ�Ӧ����������0��ʼ
	// ����ֵ:  ��Ӧ�������ֶ�ֵ
	//
	const CHAR * SDAPI GetFieldValue(UINT32 dwIndex);

	//
	// ������:  GetFieldLength
	// ����:    ��ȡ�ֶλ���������
	// ����:    [in] dwIndex:�ֶζ�Ӧ����������0��ʼ
	// ����ֵ:  ������Ӧ�ֶεĻ���������
	//
	INT32 SDAPI GetFieldLength(UINT32 dwIndex);

	//
	// ������:  Release
	// ����:    �ͷŽ����¼��
	//
	void SDAPI Release();

	//
	// ��������
	// ���ܣ���ȡ��ǰ��¼���е�ĳһ�ֶ�ֵ
	// ������[in] pszFieldName:�ֶε�����
	// ����ֵ��������Ӧ���ֶ�ֵ
	const CHAR * SDAPI GetFieldValueByName(const CHAR *pszFieldName);

	//
	// ������:  GetFieldLengthByName
	// ����:    ��ȡ�ֶλ���������
	// ����:    [in] pszFieldName:�ֶε�����
	// ����ֵ:  ������Ӧ�ֶεĻ���������
	//
	INT32 SDAPI GetFieldLengthByName(const CHAR *pszFieldName);

private:
	SQLHSTMT m_hstmt;
	SQLINTEGER m_RowCount;
	SQLSMALLINT m_ColumnCount;
	CHAR buffer[65535];
};

#endif

#endif

