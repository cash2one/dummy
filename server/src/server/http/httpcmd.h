///<------------------------------------------------------------------------------
//< @file:   server\http\httpcmd.h
//< @author: ������
//< @date:   2015��6��11�� 21:56:12
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _httpcmd_h_
#define _httpcmd_h_

#include "httpmgr.h"

#include <curl/curl.h>
#include <tool/timetool.h>

#define HTTP_URL_SIGN	"Bef^3rwsvn!29jcx57ng"

class HttpCmd
{
	friend class HttpMgr;

public:
	HttpCmd();
	virtual ~HttpCmd() {};

	void release() { delete this; }

public:
	virtual bool init() = 0;

	void bind();

	// virtual HttpCmdType getHttpCmdType() = 0;

protected:
	virtual void onExecuted() = 0;

	// ��url����ǩ����������&sign=?����
	virtual string signUrl(const char *sign);

public:
	// �ڵ�ǰ�߳���ͬ��ִ�б��������ֱ�����ؽ��
	void syncExecute();

protected:
	CURL *m_curl; // URL����Ϣ

	Timestamp m_lastAddTime; // �ϴ����URL����ʱ��

	char m_errorBuf[256]; //������Ϣ

	string		m_url;
	string		m_fields;
	string		m_html; // ���ص�htmlҳ����

	bool m_ok; // �Ƿ�ɹ�ִ�б�����
};

#endif //_httpcmd_h_