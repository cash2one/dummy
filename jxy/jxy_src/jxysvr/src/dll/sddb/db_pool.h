
#ifndef SGDP_DB_POOL_H_20100729
#define SGDP_DB_POOL_H_20100729

#include "sddb.h"
#include "db_conn.h"
#include <map>
#include <set>
#include <list>
#include "sdthreadpool.h"
#include "sdmutex.h"

class CConnPool : public SGDP::ISDRunable
{
public:
	CConnPool();
	~CConnPool();

	/**
	 * @desc ��ʼ�����ݿ����ӳ�
	 *
	 * @param pstDBAccount ���ӵ����ݿ�������Ĳ���
	 * @param coreSize ���ݿ����ӳصĺ��������������ݿ����ӳ�����ӵ��coreSize������
	 * @param maxSize ���ݿ����ӳ��ܹ����������������
	 *
	 * @return trueΪ���ݿ����ӳس�ʼ���ɹ���falseΪ���ݿ����ӳس�ʼ�����ɹ�
	 **/
	bool Init(SGDP::SDDBAccount *pstDBAccount, INT32 coreSize, INT32 maxSize);

	/**
	 * @desc ��ȡ����
	 *
	 * @return ���������ӣ��������ֵΪNULL������û�п��õ�����
	 **/
	SGDP::ISDDBConnection * SDAPI GetConnection(INT32 timeout = 0);

	bool SDAPI SelectDB(const CHAR *pcDBName);

	void Return(SGDP::ISDDBConnection * pConnection);

	/**
	 * @desc ���һ��DB����첽ִ��DB����
	 *
	 * @param poDBCommand ��Ҫִ�е�DB����
	 * 
	 * @return true�������ɹ���falseΪ�������ʧ��
	 **/
	bool SDAPI AddDBCommand(SGDP::ISDDBCommand *poDBCommand);

	/**
	 * @desc �������һ��DB����첽ִ��DB����
	 *
	 * @param poDBCommand ��Ҫִ�е�DB����
	 *
	 * @return true�������ɹ���falseΪ�������ʧ��
	 **/
    bool SDAPI QuickAddDBCommand(SGDP::ISDDBCommand *poDBCommand);

	/**
	 * @desc ����DB������߼�����
	 * 
	 * @param nCount ��Ҫִ��DB���������
	 *
	 * @return ���еĽ����true��������������Ҫ����ɵ�DB���
	 * false����û�����
	 **/
	bool SDAPI Run(UINT32& dwCount);

	/**
	 * @desc ��ȡ��ִ��db������DB���������
	 * 
	 * @return ��ǰ��ִ��db������DB���������
	 **/
	UINT32 SDAPI GetExcuteCmdCount();

	/**
	 * @desc ��ȡ��ִ��db������DB���������
	 * 
	 * @return ��ǰ�����е�DB���������
	 **/
	UINT32 SDAPI GetExcutedCmdCount();

	/**
	 * @desc ��ȡ���ӵ�����
	 *
	 * @return ��ȡ���ӵ�����
	 **/
	INT32 SDAPI GetConnCount();

	/**
	 * @desc ��ȡ������������
	 *
	 * @return ��ȡ������������
	 **/
	INT32 SDAPI GetRemainConnCount();

	//�̺߳���
	void Run();

	typedef std::map<int, IConn *> ConnMap;
	typedef std::set<IConn *> ConnSet;
	typedef std::list<SGDP::ISDDBCommand *> CDBCommandList;

	void SDAPI SetCheckConn(bool bCheckConn);

private:
	//��ȡһ����װ��������
	IConn * _Borrow();

	IConn * _Borrow(IConn * pConn);

	//����һ����װ��������
	void _Return(IConn * pConn);

	//����һ������
	IConn * _CreateConnection();

	//��ȡһ�������첽ִ����������ӣ��������ֵΪNULL���������޿��õ�����
	IConn * _GetAsynConnection(int nGroupId);

	//�ڲ���ȡһ������
	IConn * _GetConnection(INT32 timeout = 0);

	//������������е�DBCommand
	void _ClearCommandQueue();

	//������������Map�����е�����
	void _ClearConnMap();

	//ɾ����ConnMap�е�һ������
	void _RemoveConnMap(IConn * pConn);

	//ִ��DBCommand
	void _ExecuteDBCommand(IConn * pConn, SGDP::ISDDBCommand * poDBCommand);

private:
	SGDP::CSDMutex m_PoolLock;
	SGDP::CSDMutex m_CommandLock;
	SGDP::CSDMutex m_ExcutedCommandLock;
	SGDP::CSDMutex m_MapLock;
	ConnMap m_ConnMap;
	ConnSet m_ConnSet;
	CDBCommandList m_DBCommandList;
	CDBCommandList m_ExcutedDBCommandList;

	//SGDP::ISDThreadCtrl * m_poThreadCtrl;
	SGDP::CSDThreadPool * m_poThreadPool;

	INT32 m_nCoreSize;
	INT32 m_nMaxSize;

	CHAR m_szServerAddr[SDDB_MAX_NAME_SIZE];
	CHAR m_szDBName[SDDB_MAX_NAME_SIZE];
	CHAR m_szLoginName[SDDB_MAX_NAME_SIZE];
	CHAR m_szPassword[SDDB_MAX_NAME_SIZE];
	CHAR m_szCharactSet[SDDB_MAX_CHARACTSET_SIZE];
	CHAR m_szUnixSocket[SDDB_MAX_NAME_SIZE];

	INT32 m_nServerPort;
	INT32 m_wDBType;

	volatile bool m_bCheckConn;

	volatile INT32 m_nConnCount;
	volatile INT32 m_nRemainConnCount;
	volatile bool m_bRun;

	const static INT32 SLEEP_INTERVAL;
};

#endif

