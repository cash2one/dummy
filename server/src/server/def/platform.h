///<------------------------------------------------------------------------------
//< @file:   server\def\platform.h
//< @author: ������
//< @date:   2014��11��25�� 15:35:3
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _platform_h_
#define _platform_h_

#include <assert.h>

/*
#ifdef WIN
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#undef WIN32_LEAN_AND_MEAN
	#include <io.h>
	#include <tchar.h>
#else
	#include<pthread.h>
#endif
*/

// ��ǰ�����ĸ�ƽ̨ ?
#if !defined(PLATFORM)
	#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
		#define WIN
	#else
		#define POSIX
	#endif
	#define PLATFORM
#endif

// ƽ̨��ص�ͷ�ļ�����
#if defined(WIN)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
		#define __UNDEF_LEAN_AND_MEAN
	#endif

	#include <windows.h>

	#ifdef __UNDEF_LEAN_AND_MEAN
		#undef WIN32_LEAN_AND_MEAN
		#undef __UNDEF_LEAN_AND_MEAN
	#endif
#else
	#include <pthread.h>
	#include <signal.h>
	#include <sched.h>
	#include <unistd.h>
#endif

// �̡߳���
#ifdef WIN
	#include <process.h>
	#include <sys/locking.h>
#else
	#include <pthread.h>
#endif

// �׽��֡�����
#ifdef WIN
	#define FD_SETSIZE 1024

	#include <winsock2.h>
	#include <ws2tcpip.h>
	#include <io.h>
#else
	#include <netinet/in.h>
	#include <sys/socket.h>
	#include <sys/epoll.h>
	#include <arpa/inet.h>
#endif

// ��������
#ifdef WIN
	#define fstat _fstati64
	#define stat _stati64
	#define mode_t int
	#define sleep Sleep
#else
	#define sprintf_s snprintf
#endif

// �������Ƿ�֧��c++11��ȫ������ ?
#if (__cplusplus > 199711L) || (defined(__STDCXX_VERSION__) && (__STDCXX_VERSION__ >= 201001L))
	#define _CPP11_
#endif

// �ֲ߳̾��洢
#if !defined(_TTHREAD_CPP11_) && !defined(thread_local)
	#if defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__SUNPRO_CC) || defined(__IBMCPP__)
		#define thread_local __thread
	#else
		#define thread_local __declspec(thread)
	#endif
#endif

#ifdef WIN
	#define bzero(buf, len) memset(buf, 0, len)
#endif

#include <string>
#include <list>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <basic/singleton.h>
#include <log/log.h>

// unordered_map��unordered_setͷ�ļ�·������
#ifdef WIN
	#include <unordered_map> // �����map�������Բ���Ҫ��Ļ����뾡����unorder_map����map
	#include <unordered_set>
#else
	#include <tr1/unordered_map>
	#include <tr1/unordered_set>
#endif

using namespace std;

// �׽��֡�����
#ifdef WIN
	#define NetModel Select

	#define MSG_NOSIGNAL 0
#else
	#define NetModel Epoll

	#define SOCKET_ERROR (-1)
#endif

// �������ض���
#ifdef WIN
	#undef EWOULDBLOCK
	#undef EINPROGRESS
	#undef EALREADY
	#undef ENOTSOCK
	#undef EDESTADDRREQ
	#undef EMSGSIZE
	#undef EPROTOTYPE
	#undef ENOPROTOOPT
	#undef EPROTONOSUPPORT
	#undef ESOCKTNOSUPPORT
	#undef EOPNOTSUPP
	#undef EPFNOSUPPORT
	#undef EAFNOSUPPORT
	#undef EADDRINUSE
	#undef EADDRNOTAVAIL
	#undef ENETDOWN
	#undef ENETUNREACH
	#undef ENETRESET
	#undef ECONNABORTED
	#undef ECONNRESET
	#undef ENOBUFS
	#undef EISCONN
	#undef ENOTCONN
	#undef ESHUTDOWN
	#undef ETOOMANYREFS
	#undef ETIMEDOUT
	#undef ECONNREFUSED
	#undef ELOOP
	#undef ENAMETOOLONG
	#undef EHOSTDOWN
	#undef EHOSTUNREACH
	#undef ENOTEMPTY
	#undef EPROCLIM
	#undef EUSERS
	#undef EDQUOT
	#undef ESTALE
	#undef EREMOTE

	#define EWOULDBLOCK             WSAEWOULDBLOCK
	#define EINPROGRESS             WSAEINPROGRESS
	#define EALREADY                WSAEALREADY
	#define ENOTSOCK                WSAENOTSOCK
	#define EDESTADDRREQ            WSAEDESTADDRREQ
	#define EMSGSIZE                WSAEMSGSIZE
	#define EPROTOTYPE              WSAEPROTOTYPE
	#define ENOPROTOOPT             WSAENOPROTOOPT
	#define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
	#define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
	#define EOPNOTSUPP              WSAEOPNOTSUPP
	#define EPFNOSUPPORT            WSAEPFNOSUPPORT
	#define EAFNOSUPPORT            WSAEAFNOSUPPORT
	#define EADDRINUSE              WSAEADDRINUSE
	#define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
	#define ENETDOWN                WSAENETDOWN
	#define ENETUNREACH             WSAENETUNREACH
	#define ENETRESET               WSAENETRESET
	#define ECONNABORTED            WSAECONNABORTED
	#define ECONNRESET              WSAECONNRESET
	#define ENOBUFS                 WSAENOBUFS
	#define EISCONN                 WSAEISCONN
	#define ENOTCONN                WSAENOTCONN
	#define ESHUTDOWN               WSAESHUTDOWN
	#define ETOOMANYREFS            WSAETOOMANYREFS
	#define ETIMEDOUT               WSAETIMEDOUT
	#define ECONNREFUSED            WSAECONNREFUSED
	#define ELOOP                   WSAELOOP
	#define ENAMETOOLONG            WSAENAMETOOLONG
	#define EHOSTDOWN               WSAEHOSTDOWN
	#define EHOSTUNREACH            WSAEHOSTUNREACH
	#define ENOTEMPTY               WSAENOTEMPTY
	#define EPROCLIM                WSAEPROCLIM
	#define EUSERS                  WSAEUSERS
	#define EDQUOT                  WSAEDQUOT
	#define ESTALE                  WSAESTALE
	#define EREMOTE                 WSAEREMOTE
#endif

// ���Ժ��ض���
#ifdef WIN
	#define _FUNC_ __FUNCTION__
#else
	#define _FUNC_ << __FUNCTION__ <<
#endif

#ifndef MAX
	#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
	#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif //_platform_h_