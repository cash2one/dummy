///<------------------------------------------------------------------------------
//< @file:   server\db\dbcommand.h
//< @author: ������
//< @date:   2015��3��27�� 11:49:23
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dbcommand_h_
#define _dbcommand_h_

#include "db.h"

// DBCommand�ӿ��࣬�����첽ִ��SQL��DB�����������Ϊ��
// ��������->OnExecuteSql(�첽)->(ִ��ISDDBSession::Runʱ)OnExecuted(ͬ��)->Release(ͬ��)
class DBCommand
{
public:
	static thread_local char s_sql[2048];

public:
	/**
	* @brief ������ķ���ID��
	*/
	virtual int getGroupId() {return 0;};

	// �����ݿ��߳�ִ��
	virtual void execute(DBConnection &poDBConnection) = 0;

	// ��ҵ���߼��߳�ִ��
	virtual void onExecuted() = 0;

	// ִ����ҵ���߼���ִ�д�release���������û����ԣ��˺����е�ִ����ͬ����
	virtual void release() = 0;
};

#endif //_dbcommand_h_