///<------------------------------------------------------------------------------
//< @file:   server\db\dbsession.h
//< @author: ������
//< @date:   2015��3��26�� 20:25:16
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbsession_h_
#define _dbsession_h_

#include "db.h"

// DBSession�ӿ��࣬������һ�����ݿ���������ӵĻỰ���ûỰҲ����ά���������
class DBSession
{
public:
	// ���������ַ���ת��Ϊ���ݿ��ʶ�����0��β���ַ���
	uint32 EscapeString(const char *pSrc, int srcSize, char *pDest, int nDstSize, int timeout = -1);

	int ExecuteSql(const char *pSQL, uint64 *pInsertId = NULL, int timeout = -1);

	int ExecuteSqlRs(const char *pSQL, int **ppoRs, UINT32* pdwErr = NULL, string* pstrErr = NULL, int timeout = -1);

	bool CreateDB(const char *pcDBName, bool bForce, const char *pcCharSet, int timeout = -1);

	bool SelectDB(const char *pcDBName, int timeout = -1);

	bool AddDBCommand(IDBCommand *poDBCommand);

	bool QuickAddDBCommand(IDBCommand*poDBCommand);

	bool Run(UINT32& dwCount);

private:
	friend class CSDDBModule;
};

#endif //_dbsession_h_