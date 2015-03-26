///<------------------------------------------------------------------------------
//< @file:   server\log\log.cpp
//< @author: ������
//< @date:   2014��11��25�� 16:45:18
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#include "log.h"

thread_local char t_errnobuf[512];

const char* strerror_threadlocal(int savedErrno)
{
	strerror_s(t_errnobuf, sizeof t_errnobuf, savedErrno);
	return t_errnobuf;
}

//����Ϣ������������ļ��� LOG(ERROR)
void SignalHandle(const char* data, int size)
{
	std::string str = std::string(data, size);
	LOG_ERROR << str;

	// std::ofstream fs("glog_dump.log", std::ios::app);
	// fs << str;
	// fs.close();
}

namespace logging
{
	void init(const char* program, const char* log_path)
	{
		google::InitGoogleLogging(program); // ��ʼ��
		google::SetLogDestination(google::GLOG_INFO, log_path);//����INFO����ģ���¼�ڵ�ǰĿ¼���ļ���Ϊlog_ǰ׺
		google::SetStderrLogging(google::GLOG_INFO); //�����������׼�������������ռǼ���

		FLAGS_colorlogtostderr = true;

// 		google::InstallFailureSignalHandler();
// 		// Ĭ�ϲ�׽ SIGSEGV �ź���Ϣ���������� stderr������ͨ������ķ����Զ��������ʽ��
// 		google::InstallFailureWriter(&SignalHandle);
	}
}