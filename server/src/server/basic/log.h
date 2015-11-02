///<------------------------------------------------------------------------------
//< @file:   server\basic\log.h
//< @author: ������
//< @date:   2014��11��25�� 15:10:13
//< @brief:	 ��־����api
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _log_h_
#define _log_h_

#include "tool/sockettool.h"
#include "tool/echotool.h"

#define GLOG_NO_ABBREVIATED_SEVERITIES
#define GOOGLE_GLOG_DLL_DECL
// #define GOOGLE_STRIP_LOG 0

#ifdef WIN
	#pragma warning( disable : 4355 )
#endif

#define  __STDC_FORMAT_MACROS
#include <glog/logging.h>
#include <glog/raw_logging.h>

// ��¼�ɹ���־����ɫ���壩
#define LOG_OK(...) echotool::changeToColor(COLOR_GREEN); LOG(INFO) << "" _FUNC_ "() " << __VA_ARGS__; echotool::changeToOldColor();

// ��¼����ʱ��־
#define LOG_INFO LOG(INFO) << "" _FUNC_ "() "

// ��¼������־
#define LOG_DEBUG LOG(INFO) << "" _FUNC_ "() "

// ��¼���棨��ɫ���壩
#define LOG_WARN LOG(WARNING) << "" _FUNC_ "() "

// ��¼���棨��ɫ���壩
#define LOG_ERROR LOG(ERROR) << "" _FUNC_ "() "

// ��¼��������
#define LOG_FATAL LOG(FATAL) << "" _FUNC_ "() "

// ��¼ϵͳ����
#define LOG_SYSTEM_ERR LOG_ERROR << "[[socket --err=<" << socktool::geterrno() << "> --errmsg=<" << socktool::getErrorMsg(socktool::geterrno()) << ">]]"

// ��¼socket����
#define LOG_SOCKET_ERR(sockfd, errnum) LOG_ERROR << "[[socket<" << sockfd << "> --err=<" << errnum << "> --errmsg=<" << socktool::getErrorMsg(errnum) << ">]]"

// �����̰߳�ȫ��log
#define SAFE_LOG(...) RAW_LOG(WARNING, __VA_ARGS__)

namespace logging
{
	void init(const char* program, const char* log_path);
	void uninit();
}

#endif //_log_h_