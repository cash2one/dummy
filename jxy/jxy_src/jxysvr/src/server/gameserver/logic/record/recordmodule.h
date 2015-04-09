#ifndef _RECORD_MODULE_H_
#define _RECORD_MODULE_H_
#include <deque>
#include <sdlock.h>
#include <sddb.h>

using namespace std;
using namespace SGDP;

class CRecordModule
{
public:
	CRecordModule(ISDDBSession* pDBRecordSession);
	virtual ~CRecordModule();

	BOOL AddData( const string &strInfo );
	deque<string> &GetQueue();
	VOID Clear();
	CSDMutex &GetDataMutex();
	string GetRecordModuleName(UINT32& dwNextID);
	inline VOID SetCurID(UINT32 dwID) { m_dwNextID = dwID; }
private:
	const static INT32 ms_nMaxDataNum=50000; //������ݻ�������
	deque<string> m_deqData;
	CSDMutex m_mutex;
	ISDDBSession* m_pDBRecordSession; //���ݿ�����
	UINT32 m_dwNextID;		//�ڴ��м�¼����ֹȡ����ʱid��1��ʼ
	string m_strTableName;	//�ϴεı�������ֹȡ����ʱд�ļ�û�б���
};


#endif