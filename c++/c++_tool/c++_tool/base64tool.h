/********************************************************************
            Copyright (c) 2011, �������߹�����
                   All rights reserved
         
    �������ڣ�  2011��7��15�� 11ʱ19��
    �ļ����ƣ�  Base64Tool.h
    ˵    ����  base64���a����     
    
    ��ǰ�汾��  1.00
    ��    �ߣ�  Sizhi Huang
    ��    ����  ����    

*********************************************************************/
#pragma once
#include <string>
#include <sstream>
using namespace std;

namespace StringEncode {

	template<unsigned int size>
	const string Base64Encode(const unsigned char (&param)[size]) {
		return Base64Encode(param, size);
	}

	template<unsigned int size>
	const string Base64Encode(const char (&param)[size]) {
		return Base64Encode(param, size);
	}

	const string Base64Encode(const void *src, unsigned int bytes);

	template<unsigned int size>
	int Base64Decode(const string &str, unsigned char (&param)[size]) {
		return Base64Decode(str, param, size);
	}

	template<unsigned int size>
	int Base64Decode(const string &str, char (&param)[size]) {
		return Base64Decode(str, param, size);
	}

	int Base64Decode(const string &str, void *outBuff, unsigned int outSize);

};
