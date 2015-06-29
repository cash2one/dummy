///<------------------------------------------------------------------------------
//< @file:   server\http\httpcmd.cpp
//< @author: ������
//< @date:   2015��6��11�� 21:56:20
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "httpcmd.h"

HttpCmd::HttpCmd()
	: m_lastAddTime(0)
	, m_ok(true)
{
	m_curl = curl_easy_init();
	memset(m_errorBuf, 0x00, sizeof(m_errorBuf));
}

void HttpCmd::bind()
{
	curl_easy_setopt(m_curl, CURLOPT_URL, m_url.c_str());
	curl_easy_setopt(m_curl, CURLOPT_ERRORBUFFER, m_errorBuf);
	curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);
	curl_easy_setopt(m_curl, CURLOPT_POST, 1 );
	curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, m_fields.c_str());
}

void HttpCmd::syncExecute()
{

}

string HttpCmd::signUrl(const char *sign)
{
	std::string md5PlainText = m_url + sign; //  md5ԭ��

	// 1. ����md5��ϢժҪ

	// 2. ȡmd5��ǰ16λתΪʮ�����ƴ�
	CHAR hex[32] = {0};

	CHAR hexDigest[256] = {0};
	for (UINT8 byIdx = 0; byIdx < 16; byIdx++) {
		sprintf(hex, "%02x", (UINT8)hexDigest[byIdx]);
		strcat(hexDigest, hex);
	}

	// 3. ��ԭurl�󸽼�_sign�ֶ�
	std::string signText = m_url + "?_sign=" + hexDigest;
	return signText;
}
