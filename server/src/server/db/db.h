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
typedef struct st_mysql MYSQL;
typedef struct st_mysql_stmt MYSQL_STMT;
class DBRecordSet;
class DBCommand;

// ���ݿ���Ϣ���Ƶ���󳤶�
#define SDDB_MAX_NAME_SIZE		        64

// ���ݿ��ַ������Ƶ���󳤶�
#define SDDB_MAX_CHARACTSET_SIZE		32

namespace DB
{
	enum DBExecuteCode {
		EXECUTE_ERR_UNKNOWN		  = -999, ///< δ֪����
		EXECUTE_ERR_DUPLICATE	  = -3,   ///< �����ظ�
		EXECUTE_ERR_CONN		  = -2,   ///< ���Ӵ���
		EXECUTE_ERR_DB_DISCONNECT = -1,   ///< �Ͽ��������������
		EXECUTE_OK			  = 0,    ///< �����ɹ�
	};

	enum DBQueryCode {
		QUERY_ERR_UNKNOWN       = -999, ///< δ֪����
		QUERY_ERR_CONN          = -2,   ///< ���Ӵ���
		QUERY_ERR_DB_DISCONNECT = -1,   ///< �Ͽ��������������
		QUERY_OK_NO_RECORDSET   = 1,    ///< �����ɹ�����û�н����
		QUERY_OK_HAVE_RECORDSET = 2     ///< �����ɹ����н����
	};
}

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

#endif //_db_h_