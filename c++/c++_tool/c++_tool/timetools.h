/********************************************************************
            Copyright (c) 2010, �������߹�����
                   All rights reserved
         
    ��������:	2010��1��14�� 13ʱ49��
    �ļ�����:	TimeTools.h
    ˵    ��:	ʱ�����͹���

    ��ǰ�汾:	1.00
    ��    ��:	wy
				czq 
    ��    ��:	

*********************************************************************/
#pragma once
#include <time.h>
#include <stdint.h>

typedef uint64_t time64_t;

class TimeTools
{
public:
	TimeTools();
	~TimeTools();
	// ��ʼ��ʱ��ƫ��
	static void init(int deviationZone);

	// ��õ�ǰʱ��,��������ʱ��
	static time64_t getCurrentTime();
	// ��õ�ǰʱ��+ƫ�Ƶ�ʱ�䣬��Ӫʱ��
	static time64_t getOperatingTime();

	// ��õ�ǰʱ��, ��Ӫʱ��
	static const tm* getCurrentTM();
	// ���tm
	static const tm* getTMFromTime_t(time64_t tt);
	// ��ȡ��Ӫtm
	static const tm* getOperatingTMFromTime_t(time64_t tt);

	// ʱ���ַ���ת����time64_t��ʽ(�ַ�����ʽ��2010-01-01 01:01:01)
	static time64_t conversionStrTimeToTime_t(const char* pStr);
	// ʱ���ַ���ת����time64_t��ʽ(�ַ�����ʽ��2010,01,01,01,01,01)
	static time64_t conversionStrTimeToTime_tEx(const char* pStr);

	// ʱ���ַ���ת������ʱ��(�ַ�����ʽ��2010,01,01,01,01,01)
	static time64_t conversionStrTimeToSecond(const char* pStr);

	// ��ʱ��ת�����ַ���(�ַ�����ʽ��2010-01-01 01:01:01)
	static const char* conversionTime_tToStr(time64_t t);
	// ��ʱ��ת�����ַ���(�ַ�����ʽ��2010,01,01,01,01,01)
	static const char* conversionTime_tToStrEx(time64_t t);

	// ���ʱ��
	static long getTimeZone();
	// ���ر�׼ʱ��, ��Ӫʱ��
	//static time64_t getLocalTime();

	// ʱ���ʽ 00:00:00 ���� 00:00 ������
	static long	StrTimeToNum(const char* pszTime);
	// ��ʽ%H:%M:%S
	static char *LocalTimeToStr(bool bSec = false);
	// 2010-01-01 01:01:01
	static char *getLocalDateTimeStr();
	// 2010-01-01 01:01:01
	static char *getDateTimeStr(time64_t tt);
	// ��õ�����ʱ��
	static int getDeviationZone();
	// ��ȡʱ���ַ�����ʽ(������ʽ) 20100102030405
	static char *getLocalDateTimeStrSeq();

	// ��ȡ��һ������һ�����������ʱ��
	static time64_t getLastMondayTime(time64_t t);
	// ��ȡ��һ������һ�����������ʱ��
	static time64_t getLastMondayTime(time64_t t, const tm* pTm);
	// ��ȡ����00:00:00��ʱ��
	static time64_t getTodayBeginTime(time64_t t);

private:
	// ʱ��ƫ��
	static int s_deviationZone;
	// ʱ��ƫ�� * 3600
	static long long s_deviationTime;
};
