///<------------------------------------------------------------------------------
//< @file:   server\basic\log.cpp
//< @author: ������
//< @date:   2014��11��25�� 16:45:18
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#include "log.h"


//����Ϣ������������ļ��� LOG(ERROR)
void SignalHandle(const char* data, int size)
{
	std::string str(data, size);
	LOG_ERROR << str;

	// std::ofstream fs("glog_dump.log", std::ios::app);
	// fs << str;
	// fs.close();
}

namespace logging
{
	void init(const char* program, const char* log_path)
	{
#ifdef DEBUG
		google::SetStderrLogging(google::GLOG_INFO); //���ü������ google::INFO ����־ͬʱ�������Ļ
#else
		google::SetStderrLogging(google::GLOG_INFO);//���ü������ google::FATAL ����־ͬʱ�������Ļ
#endif

		google::InitGoogleLogging(program); // ��ʼ��

		google::SetLogDestination(google::GLOG_INFO, log_path);//����INFO����ģ���¼�ڵ�ǰĿ¼���ļ���Ϊlog_ǰ׺

		/*
		google::SetLogDestination(google::GLOG_FATAL, "./log/log_fatal_"); // ���� google::FATAL �������־�洢·�����ļ���ǰ׺
		google::SetLogDestination(google::GLOG_ERROR, "./log/log_error_"); //���� google::ERROR �������־�洢·�����ļ���ǰ׺
		google::SetLogDestination(google::GLOG_WARNING, "./log/log_warning_"); //���� google::WARNING �������־�洢·�����ļ���ǰ׺
		google::SetLogDestination(google::GLOG_INFO, "./log/log_info_"); //���� google::INFO �������־�洢·�����ļ���ǰ׺
		*/

		FLAGS_colorlogtostderr			= true; //�����������Ļ����־��ʾ��Ӧ��ɫ
		FLAGS_logbufsecs				= 0; //������־�����Ĭ��Ϊ30�룬�˴���Ϊ�������
		FLAGS_max_log_size				= 100; //�����־��СΪ 100MB
		FLAGS_stop_logging_if_full_disk = true; //�����̱�д��ʱ��ֹͣ��־���

#ifndef WIN
		// Ĭ�ϲ�׽ SIGSEGV �ź���Ϣ���������� stderr������ͨ������ķ����Զ��������ʽ��
		google::InstallFailureSignalHandler();
		google::InstallFailureWriter(&SignalHandle);
#endif
	}

	void uninit()
	{
		// google::ShutdownGoogleLogging();
	}
}