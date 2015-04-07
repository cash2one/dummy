///<------------------------------------------------------------------------------
//< @file:   server\tool\timetool.cpp
//< @author: ������
//< @date:   2015��1��16�� 22:55:27
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "timetool.h"

#ifndef WIN
	#include <sys/time.h>
#endif

namespace timetool
{
#ifdef WIN
	Timestamp FileTimeToInt64(const FILETIME& time)
	{
		ULARGE_INTEGER tt;
		tt.LowPart = time.dwLowDateTime;
		tt.HighPart = time.dwHighDateTime;
		return(tt.QuadPart);
	}

	FILETIME Int64ToFileTime(const Timestamp& stamp)
	{
		ULARGE_INTEGER tt;
		tt.QuadPart = stamp;

		FILETIME filetime;
		filetime.dwLowDateTime = tt.LowPart;
		filetime.dwHighDateTime = tt.HighPart;

		return filetime;
	}

	Timestamp getTimeOfDay()
	{
		FILETIME now;
		GetSystemTimeAsFileTime (&now); // ���ϵͳUTC��ʽʱ��

		int64 nowIn100ns = FileTimeToInt64(now);// ��λ100ns
		return nowIn100ns / 10000; //ת��Ϊms��λ
	}

	Timestamp GetLocalTime()
	{
		FILETIME local;
		GetSystemTimeAsFileTime (&local); // ���ϵͳUTC��ʽʱ��
		FileTimeToLocalFileTime(&local, &local); // ת��Ϊ����ʱ��

		int64 localIn100ns = FileTimeToInt64(local);// ��λ100ns
		return localIn100ns / 10000;
	}

	const char* FormatTime(const Timestamp& time)
	{
		Timestamp utc = time * 10000;

		FILETIME filetime = Int64ToFileTime(utc);

		SYSTEMTIME systime;
		FileTimeToSystemTime(&filetime, &systime);

		sprintf_s(global::g_formatBuf, sizeof global::g_formatBuf, "%02d/%02d/%d-%02d:%02d:%02d:%-6d",
		          systime.wDay, systime.wMonth, systime.wYear,
		          systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds
		         );

		return global::g_formatBuf;
	}

	const char* FormatNow()
	{
		FILETIME local;
		SYSTEMTIME systime;
		GetSystemTimeAsFileTime (&local); // ���ϵͳUTC��ʽʱ��
		FileTimeToLocalFileTime(&local, &local); // ת��Ϊ����ʱ��
		FileTimeToSystemTime(&local, &systime);

		sprintf_s(global::g_formatBuf, sizeof global::g_formatBuf, "%02d/%02d/%d-%02d:%02d:%02d:%-6d",
		          systime.wDay, systime.wMonth, systime.wYear,
		          systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds
		         );

		return global::g_formatBuf;
	}

#else
	Timestamp getTimeOfDay()
	{
		struct timeval tv;
		gettimeofday(&tv, NULL);
		Timestamp seconds = tv.tv_sec;
		return seconds * 1000 + tv.tv_usec / 1000;
	}
#endif
}