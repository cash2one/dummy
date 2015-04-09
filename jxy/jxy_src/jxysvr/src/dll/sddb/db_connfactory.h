
#ifndef SGDP_DB_CONNFACTORY_H_20100721
#define SGDP_DB_CONNFACTORY_H_20100721

#include "db_conn.h"

/**
  @desc IConn�ļ򵥹����࣬���ڴ���DBConnection
**/
class CConnFactory
{
private:
	/**
	  @desc CConnFactory�Ĺ��캯��
	**/
	CConnFactory();

public:
	/**
	  @desc CConnFactory����������
	**/
	~CConnFactory();

	/**
	  @param pstDBAccount ���ݿ�������Ϣ
	  @return IConn* ����һ��Connection
	  @desc ��ȡһ��Connection
	**/
	static IConn * GetConnection(SGDP::SDDBAccount *pstDBAccount);

	/**
	  @param wDBType ���ݿ�����
	  @param pszServerAddr ���ݿ��������IP��ַ
	  @param nServerPort ���ݿ�������Ķ˿ں�
	  @param pszDBName ���ݿ�DB������
	  @param pszLoginName ���ݿ�ĵ�½��
	  @param pszPassword ���ݿ������
	  @param pszCharactSet���ݿ���ַ���
	  @return IConn* ����һ��Connection
	  @desc ��ȡһ��Connection
	**/
	static IConn * GetConnection(INT32 wDBType, const CHAR * pszServerAddr, int nServerPort, const CHAR * pszDBName, 
				const CHAR * pszLoginName, const CHAR * pszPassword, const CHAR * pszCharactSet, const CHAR* pszUnixSocket);

	/**
	  @return ����һ��ģ���Connection
	  @desc ��ȡһ��ģ���Connection
	**/
	static IConn * GetMockConnection();
};

#endif

