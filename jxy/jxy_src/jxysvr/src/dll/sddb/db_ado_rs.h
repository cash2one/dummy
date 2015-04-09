
#ifndef SGDP_DB_ADO_RECODRSET_H_20100824
#define SGDP_DB_ADO_RECODRSET_H_20100824

#if (defined(WIN32) || defined(WIN64))

#include "sddb.h"
#include <list>
#include "SDMutex.h"
#import "C:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "adoEOF")
// 
// ������   : CADORecordSet
// ����     : <�̳в�ʵ����ISDDBRecordSet��Ľӿڣ��ṩSQLִ�н����¼������ز���>
//
class CADORecordSet : public SGDP::ISDDBRecordSet
{
	friend class CADOConn;
public:
	CADORecordSet();
	~CADORecordSet();

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
	void ClearDatas();

private:
	_RecordsetPtr m_rsPtr;
	volatile bool m_bFirstRecord;
	std::list<CHAR *> m_Datas;
};

#endif

#endif

