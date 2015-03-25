/********************************************************************
            Copyright (c) 2009, �������߹�����
                   All rights reserved
         
    �������ڣ�  2009��12��11�� 11ʱ36��
    �ļ����ƣ�  StringConversion.h
    ˵    ����  �ַ���ת������
    
    ��ǰ�汾��  1.00
    ��    �ߣ�  Conserlin
    ��    ����  ����  [�Ǿ��̰�ȫ,��������ʹ��!!!!]

*********************************************************************/
#pragma once
#include <vector>
#include <string>
#include <sstream>
using std::vector;
using std::string;
using namespace std;

class StringConversion
{
public:
	StringConversion();
	~StringConversion();

// #ifdef __LINUX__
// 	// UTF8 ת�� ���ֽڵ�Unicode
// 	static const wchar_t* UTF8ToUnicode(const char *buffer);
// 	// Unicode ת�� UTF8
// 	static const char* unicodeToUTF8(const wchar_t *buffer);
// #endif // __LINUX__

	// UTF8 ת�� ���ֽڵ�Unicode
	static const wchar_t* UTF8ToUnicode(const char *buffer);
	// Unicode ת�� UTF8
	static const char* unicodeToUTF8(const wchar_t *buffer);
#ifdef WIN32
	// UTF8 ת�� ���ֽ�
	static const char* UTF8ToANSI(const char *buffer);

	// Unicode ת�� ���ֽ�
	static const char* unicodeToANSI(const wchar_t *buffer);

	// ���ֽ� ת�� UTF8
	static const char* ANSIToUTF8(const char *buffer);
	// ���ֽ� ת�� Unicode
	static const wchar_t* ANSIToUnicode(const char *buffer);
#endif // WIN32

    static void stringToLower(char* pStr);
};