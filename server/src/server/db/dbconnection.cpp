///<------------------------------------------------------------------------------
//< @file:   server\db\dbconnection.cpp
//< @author: ������
//< @date:   2015��3��26�� 20:27:40
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "dbconnection.h"
#include <mysql.h>
#include <errmsg.h>
#include "dbrecordset.h"

bool DBConnection::connect()
{
	if (m_connected) {
		return true;
	}

	m_mysql = mysql_init(NULL);

	// �����Զ�����
	char value = 1;
	mysql_options(m_mysql, MYSQL_OPT_RECONNECT, &value);

	//����ͻ�������������ַ���������MYSQL���ַ�������
	if(!m_account.m_charactset.empty()) {
		if(mysql_options(m_mysql, MYSQL_SET_CHARSET_NAME, m_account.m_charactset.c_str())) {
			LOG_ERROR << "set mysql charactset<" << m_account.m_charactset << "> failed";
			return false;
		}
	}

	MYSQL *mysql = mysql_real_connect(m_mysql, m_account.m_dbIp.c_str(), m_account.m_loginName.c_str(),
	                                  m_account.m_loginPwd.c_str(), m_account.m_dbName.c_str(),
	                                  m_account.m_dbPort, m_account.m_unixSocket.c_str(), CLIENT_MULTI_STATEMENTS);

	if(NULL == mysql) {
		const char *err = (char*)mysql_error(m_mysql);
		LOG_ERROR << "mysql_real_connect failed, error str: <" << err << "> failed";
		this->release();

		return false;
	}

	m_connected = true;

	//�����ַ���
	if(false == setCharsetName()) {
		this->release();
		return false;
	}

	Charsets charsets;

	//��ȡ�������˵��ַ���
	if(false == getCharsets(charsets)) {
		this->release();
		return false;
	}

	//������ú���ַ����Ƿ����Ҫ��
	if(false == isCompatiableCharset(charsets)) {
		LOG_ERROR << "Charset inconformity: application charset is " << m_account.m_charactset;
		this->release();
		return false;
	}

	return true;
}

void DBConnection::release()
{
	if(m_mysql) {
		mysql_close(m_mysql);
		m_mysql = NULL;
	}

	m_connected = false;

	for(PreparedStmtMap::iterator itr = m_preparedStmtMap.begin(); itr != m_preparedStmtMap.end(); ++itr) {
		MYSQL_STMT *stmt = itr->second;
		mysql_stmt_close(stmt);
	}

	LOG_INFO << "close dbconnection successfully! ----\tsvrip:" << m_account.m_dbIp << "\tdbname:" << m_account.m_dbName << "\tunicsocket:" << m_account.m_unixSocket;
}

bool DBConnection::reconnect()
{
	this->release();
	return this->connect();
}

bool DBConnection::escape(const char *pSrc, int nSrcSize, char *pDest, int nDstSize)
{
	if(false == this->checkConnection()) {
		return false;
	}

	if((2 * nSrcSize + 1) > nDstSize) {
		LOG_ERROR << "escape exception: DestSize < 2 * nSrcSize + 1";
		return false;
	}

	return mysql_real_escape_string(m_mysql, pDest, pSrc, nSrcSize) > 0;
}

void DBConnection::beginTransaction()
{
	if(NULL == m_mysql) {
		return;
	}

	mysql_autocommit(m_mysql, 0);
}

void DBConnection::commit()
{
	if(NULL == m_mysql) {
		return;
	}

	mysql_commit(m_mysql);
	mysql_autocommit(m_mysql, 1);
}

void DBConnection::rollback()
{
	if(NULL == m_mysql) {
		return;
	}

	mysql_rollback(m_mysql);
	mysql_autocommit(m_mysql, 1);
}

bool DBConnection::selectdb(const char* dbname)
{
	if (dbname != NULL && m_mysql != NULL ) {
		return 0 == mysql_select_db(m_mysql, dbname) ? true : false;
	}

	return false;
}

DB::DBExecuteCode DBConnection::execute(const char *sql, uint32 sqlLength, uint64 *pInsertId, uint32* pEffectRowNum)
{
	if(false == this->checkConnection()) {
		return DB::EXECUTE_ERR_CONN;
	}

	if (0 == sqlLength) {
		sqlLength = strlen(sql);
	}

	if(0 != mysql_real_query(m_mysql, sql, sqlLength)) {
		//==============��ѯ���ɹ�,��ӡ��־==============
		uint32 errnum = mysql_errno(m_mysql);

		const char* errmsg = mysql_error(m_mysql);
		if(errmsg != NULL) {
			LOG_ERROR << "execute exception, sql" << sql << ", errno = " << errnum << ", errmsg = " << errmsg;
		}
		else {
			LOG_ERROR << "execute exception, sql" << sql << ", errno = " << errnum;
		}
		//==================��ӡ��־���==================

		if(CR_SERVER_LOST == errnum || CR_CONN_HOST_ERROR == errnum || CR_SERVER_GONE_ERROR == errnum) {
			if(false == this->reconnect()) {
				return DB::EXECUTE_ERR_CONN;
			}

			if (false == execute(sql, sqlLength, pInsertId, pEffectRowNum)) {
				LOG_ERROR << "svr lost, execute exception again, sql" << sql << ", errno = " << errnum;
				return DB::EXECUTE_ERR_CONN;
			}
		}
		else if(1062 == errnum) {
			//������ͻ
			return DB::EXECUTE_ERR_DUPLICATE;
		}

		return DB::EXECUTE_ERR_UNKNOWN;
	}

	//��ѯ�ɹ�
	if(NULL != pInsertId) {
		*pInsertId = mysql_insert_id(m_mysql);
	}

	int rowcnt = (int)mysql_affected_rows(m_mysql);
	if(NULL != pEffectRowNum) {
		*pEffectRowNum = rowcnt;
	}

	do {
		MYSQL_RES * res = mysql_store_result(m_mysql);
		if(NULL != res)
			mysql_free_result(res);
	}
	while (!mysql_next_result(m_mysql));

	return DB::EXECUTE_OK;
}

DB::DBQueryCode DBConnection::query(const char *sql, DBRecordSet **pRes)
{
	if(false == checkConnection()) {
		return DB::QUERY_ERR_CONN;
	}

	if(0 != mysql_real_query(m_mysql, sql, strlen(sql))) {
		//==============��ѯ���ɹ�,��ӡ��־==============
		uint32 errnum = mysql_errno(m_mysql);

		const char* errmsg = mysql_error(m_mysql);
		if(errmsg != NULL) {
			LOG_ERROR << "query exception, sql" << sql << ", errno = " << errnum << ", errmsg = " << errmsg;
		}
		else {
			LOG_ERROR << "query exception, sql" << sql << ", errno = " << errnum;
		}
		//==================��ӡ��־���==================

		if(CR_SERVER_LOST == errnum || CR_CONN_HOST_ERROR == errnum || CR_SERVER_GONE_ERROR == errnum) {
			if(false == this->reconnect()) {
				return DB::QUERY_ERR_CONN;
			}

			if (false == query(sql, pRes)) {
				LOG_ERROR << "svr lost, query exception again, sql" << sql << ", errno = " << errnum;
				return DB::QUERY_ERR_CONN;
			}
		}
		else {
			return DB::QUERY_ERR_UNKNOWN;
		}

		return DB::QUERY_ERR_UNKNOWN;
	}

	*pRes = NULL;

	DB::DBQueryCode code = DB::QUERY_ERR_UNKNOWN;

	MYSQL_RES *res = mysql_store_result(m_mysql);
	if(NULL == res) {
		if(0 == mysql_field_count(m_mysql)) {    //ִ�е���insert��update���
			code = DB::QUERY_OK_NO_RECORDSET;
		}
		else {
			code = DB::QUERY_ERR_UNKNOWN;
		}
	}
	else {
		if(mysql_num_rows(res) > 0) {
			DBRecordSet *rs = new DBRecordSet();
			rs->m_res = res;

			if(NULL == rs) {
				LOG_ERROR << "alloc DBRecordSet failed";
				code = DB::QUERY_ERR_UNKNOWN;
			}

			*pRes = rs;

			code = DB::QUERY_OK_HAVE_RECORDSET; //�н������
		}
		else {
			code = DB::QUERY_OK_NO_RECORDSET;
		}
	}

	//�ͷŵ�����Ľ����
	while (0 == mysql_next_result(m_mysql)) {
		MYSQL_RES * res = mysql_store_result(m_mysql);
		if(res) {
			mysql_free_result(res);
		}
	}

	return code;
}

bool DBConnection::setCharsetName()
{
	std::string sql = "set names " + m_account.m_charactset;
	if(execute(sql.c_str()) < 0) {
		LOG_ERROR << "Set charset names: <" << m_account.m_charactset << "> failed";
		return false;
	}

	return true;
}

bool DBConnection::getCharsets(Charsets &charset)
{
	const char* sql = "show variables like 'character_%'";

	DBRecordSet *pRes = NULL;
	if(DB::QUERY_OK_HAVE_RECORDSET != query(sql, &pRes)) {
		if(NULL != pRes) {
			pRes->Release();
		}

		return false;
	}

	while(pRes->GetRecord()) {
		const char* variableName = pRes->GetFieldValue(0);
		const char* charsetName  = pRes->GetFieldValue(1);

		charset.insert(std::make_pair(std::string(variableName), std::string(charsetName)));
	}

	std::string log = "db charset Info : \n "
	                  "{\n"
	                  "[varname] : [charset]\n";

	Charsets::iterator itr = charset.begin();
	Charsets::iterator end = charset.end();

	while(itr != end) {
		log += "" + itr->first + " : " + itr->second + "\n";
		++itr;
	}

	LOG_INFO << log << "}";

	pRes->Release();
	return true;
}

bool DBConnection::isCompatiableCharset(Charsets &charsets)
{
	//��������
	//��Ҫ��֤character_set_client��m_szCharactSet�ͣ�character_set_connection, character_set_results,
	//character_set_database, character_set_server����ȫһ��

	std::string clientCharset;

	Charsets::iterator itr = charsets.find(std::string("character_set_client"));
	if(itr != charsets.end()) {
		clientCharset = itr->second;
	}
	else {
		LOG_ERROR << "Not found character_set_client variable! Check charset compatibility failed!";
		return false;
	}

	itr = charsets.find(std::string("character_set_connection"));
	if(itr != charsets.end()) {
		if(clientCharset != itr->second) {
			LOG_ERROR << "character_set_connection(" << itr->second << ") and character_set_client(" << clientCharset << ") is incompatible";
			return false;
		}
	}

	itr = charsets.find(std::string("character_set_results"));
	if(itr != charsets.end()) {
		if(clientCharset != itr->second) {
			LOG_ERROR << "character_set_results(" << itr->second << ") and character_set_client(" << clientCharset << ") is incompatible";
			return false;
		}
	}

	if(clientCharset != m_account.m_charactset) {
		LOG_ERROR << "character_set_client(" << clientCharset << ") and Application Setting(" << m_account.m_charactset << ") is incompatible";
		return false;
	}

	return true;
}

bool DBConnection::checkConnection()
{
	//�������:
	//1.���Ϊ���쳣���ӡ����ر����ӣ�ת����û�����ӡ�״̬��
	//2.���Ϊ��û�����ӡ����������ӣ�����ת�����������ӡ�״̬��
	//3.�����Ƿ��������ӡ�
	//
	//��ע:Ŀǰ����������״̬,
	// ��������(m_poConnection != NULL, m_bConnected == true),
	// �쳣����(m_poConnection != NULL, m_bConnected == false),
	// û������(m_poConnection == NULL, m_bConnected == false)
	if(!m_connected && NULL != m_mysql) { //���쳣���ӡ�״̬
		reconnect();
	}

	if(NULL == m_mysql) { //��û�����ӡ�״̬
		m_connected = connect();
	}

	return m_connected;
}
