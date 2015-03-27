///<------------------------------------------------------------------------------
//< @file:   server\db\dbrecordset.h
//< @author: ������
//< @date:   2015��3��26�� 22:31:34
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbrecordset_h_
#define _dbrecordset_h_

#include <mysql.h>

struct CmpName {
	bool operator()(const char *pSrc, const char *pDst) const
	{
		return strcmp(pSrc, pDst) < 0;
	}
};

typedef std::map<const char*, int, CmpName> NameToIndexMap;

class DBRecordSet
{
	friend class DBConnection;

public:
	DBRecordSet();
	~DBRecordSet();

	//
	// ������:  GetRecordCount
	// ����:    ��ȡ��¼����
	// ����ֵ:  ��¼����
	//
	uint32 GetRecordCount();

	//
	// ������:  GetFieldCount
	// ����:    ��ȡ�ֶθ���
	// ����ֵ:  �ֶθ���
	//
	uint32 GetFieldCount();

	//
	// ������:  GetRecord
	// ����:    ��ȡ��һ����¼��
	// ����ֵ:  �������ֵΪTRUE��ʾ��ȡ�ɹ������Ϊfalse��ʾ��ȡʧ��
	//
	bool GetRecord();

	//
	// ������:  GetFieldValue
	// ����:    ��ȡ��ǰ��¼����ĳһ���ֶε�ֵ
	// ����:    [in] dwIndex:�ֶζ�Ӧ����������0��ʼ
	// ����ֵ:  ��Ӧ�������ֶ�ֵ
	//
	const char * GetFieldValue(uint32 dwIndex);

	//
	// ������:  GetFieldLength
	// ����:    ��ȡ�ֶλ���������
	// ����:    [in] dwIndex:�ֶζ�Ӧ����������0��ʼ
	// ����ֵ:  ������Ӧ�ֶεĻ���������
	//
	int GetFieldLength(uint32 dwIndex);

	/**
	* @brief ��ȡ�ֶ���
	*
	* @param dwIndex �ֶε�Index
	* @return ����и�Index���򣬷����ֶ�����
	* ���û�и�Index���򣬷���NULL��
	*/
	const char* GetFieldName(uint32 dwIndex) ;

	//
	// ������:  Release
	// ����:    �ͷŽ����¼��
	//
	void Release();

	//
	// ��������
	// ���ܣ���ȡ��ǰ��¼���е�ĳһ�ֶ�ֵ
	// ������[in] pszFieldName:�ֶε�����
	// ����ֵ��������Ӧ���ֶ�ֵ
	const char * GetFieldValueByName(const char *pszFieldName);

	//
	// ������:  GetFieldLengthByName
	// ����:    ��ȡ�ֶλ���������
	// ����:    [in] pszFieldName:�ֶε�����
	// ����ֵ:  ������Ӧ�ֶεĻ���������
	//
	int GetFieldLengthByName(const char *pszFieldName);

	void print();

protected:
	bool	_FillMap();

protected:
	MYSQL_RES *m_res;
	MYSQL_ROW m_row;
	unsigned long *m_adwLengths;

	NameToIndexMap m_mapFieldName;
};

#endif //_dbrecordset_h_