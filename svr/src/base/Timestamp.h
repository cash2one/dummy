#ifndef MUDUO_BASE_TIMESTAMP_H
#define MUDUO_BASE_TIMESTAMP_H

#include <common/Platform.h>


typedef int64 Timestamp; // utc��ʽʱ�䣬sin 1900 in ms���뵥λ
typedef int32 TimeInMs; // in ms���뵥λ
typedef int32 Sec; // ��

#define MsPerSecond 1000 // ����
#define UsPerSecond (1000 * 1000) // ΢��

namespace timeutil
{
    Timestamp GetTimeOfDay();

    Timestamp GetLocalTime();

    const char* FormatTime(const Timestamp& time);

    const char* FormatNow();

    void EchoNow();
}

#endif  // MUDUO_BASE_TIMESTAMP_H
