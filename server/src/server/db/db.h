///<------------------------------------------------------------------------------
//< @file:   server\db\db.h
//< @author: ������
//< @date:   2015��3��26�� 20:9:33
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _db_h_
#define _db_h_

class DBConnection;

// ���ݿ���Ϣ���Ƶ���󳤶�
#define SDDB_MAX_NAME_SIZE		        64

// ���ݿ��ַ������Ƶ���󳤶�
#define SDDB_MAX_CHARACTSET_SIZE		32

// ���ݿ��������½��Ϣ
struct DBAccount {
	std::string m_dbIp;       // ���ݿ������IP��ַ
	std::string m_dbName;     // �����ӵ����ݿ�����

	std::string m_loginName;  // ��½�û���
	std::string m_loginPwd;   // ��½����

	std::string m_charactset; // ���ݿ���뼯
	std::string m_unixSocket; // mysql��unix socket

	uint16 m_dbPort;		  // ���ݿ�����˿�

	DBAccount()
		: m_dbPort(0)
	{
	}
};

// DBCommand�ӿ��࣬�����첽ִ��SQL��DB�����������Ϊ��
// ��������->OnExecuteSql(�첽)->(ִ��ISDDBSession::Runʱ)OnExecuted(ͬ��)->Release(ͬ��)
class IDBCommand
{
public:
	/**
	* @brief ������ķ���ID��
	* ��Ҫע����ǣ��첽ִ�е�SQL��������ͬһ��Group�У����Ǳ�֤����������ʱ��ʱ�����ִ��SQL����
	* �������Ϊ��1�����ǲ���֤����������ʱ��ʱ�����ִ��SQL����
	* ʹ��QuickAddDBCommand������ͬ������ִ֤��SQL�����ʱ��˳��
	*/
	virtual int GetGroupId() {return 0;};

	/**
	* @brief ִ��SQL����
	*
	* @param poDBConn : ִ���������õ�����
	* ע�⣺�����ӳ����ж�����ӵ�����£��˺��������ǡ��̰߳�ȫ�ġ�
	*/
	virtual void OnExecuteSql(DBConnection &poDBConnection) = 0;

	/**
	* @brief ִ�����SQL��������û��߳���ִ��ISDDBSession::Runʱ��
	* ִ�д˺����е�ҵ���߼������û����ԣ��˺����е�ִ����ͬ���ġ�
	* ע�⣺������һ��Session��ִ�е�����˺����ڴ�Session::Run()��˳�����У�
	* Ҳ����˵�����ȫ��ֻ��һ���ط�ִ��Session::Run()���򣬴˺������̰߳�ȫ�ġ�
	*/
	virtual void OnExecuted() = 0;

	// ִ����ҵ���߼���ִ�д�Release���������û����ԣ��˺����е�ִ����ͬ����
	virtual void Release(void) = 0;
};


#endif //_db_h_