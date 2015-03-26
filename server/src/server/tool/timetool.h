///<------------------------------------------------------------------------------
//< @file:   server\tool\timetool.h
//< @author: ������
//< @date:   2015��1��16�� 22:54:23
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _timetool_h_
#define _timetool_h_

typedef int64 Timestamp; // utc��ʽʱ�䣬sin 1900 in ms���뵥λ
typedef int32 TimeInMs; // in ms���뵥λ

#define MsPerSecond 1000 // ����
#define UsPerSecond (1000 * 1000) // ΢��

namespace timetool
{
	Timestamp GetTimeOfDay();

	Timestamp GetLocalTime();

	const char* FormatTime(const Timestamp& time);

	const char* FormatNow();

	void EchoNow();
}

#endif //_timetool_h_