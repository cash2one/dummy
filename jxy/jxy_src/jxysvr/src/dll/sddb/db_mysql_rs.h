
#ifndef SGDP_DB_RECODRSET_H_20070613
#define SGDP_DB_RECODRSET_H_20070613

#include "mysql.h"
#include "sddb.h"
#include <map>


struct CmpObj
{
	bool operator()(const CHAR *pSrc, const CHAR *pDst) const 
	{
		return strcmp(pSrc, pDst) < 0;
	}

}; 
typedef std::map<const CHAR*, INT32, CmpObj> NameToIndexMap;

// 
// ������   : CMySQLRecordSet
// ����     : <�̳в�ʵ����ISDDBRecordSet��Ľӿڣ��ṩSQLִ�н����¼������ز���>
//
class CMySQLRecordSet : public SGDP::ISDDBRecordSet
{
	friend class CMySQLConn;
public:
	CMySQLRecordSet();
	~CMySQLRecordSet();

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

	/**
	* @brief ��ȡ�ֶ���
	*
	* @param dwIndex �ֶε�Index
	* @return ����и�Index���򣬷����ֶ�����
	* ���û�и�Index���򣬷���NULL��
	*/
	const CHAR * SDAPI GetFieldName(UINT32 dwIndex) ;

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

protected:
	bool	_FillMap();

protected:
	MYSQL_RES *m_res;
	MYSQL_ROW m_row; 
	unsigned long *m_adwLengths;
	NameToIndexMap m_mapFieldName;
};

#endif

