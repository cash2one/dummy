///<------------------------------------------------------------------------------
//< @file:   server\http\httpmgr.h
//< @author: ������
//< @date:   2015��6��11�� 21:47:59
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _httpmgr_h_
#define _httpmgr_h_

class HttpCmd;

// ���͵��û����ĵ�http��������
enum HttpCmdType {
	EHCT_APP_PAY = 1,
	EHCT_LEVEL = 2,
};

class HttpMgr
{
	typedef std::list<HttpCmd*> HttpCmdList;

public:
	bool init();

	void uninit();

	void run();

	bool addCmd(HttpCmd*);

private:
	// һ������http���ʱ�����ô˺���
	static size_t onRecvResponse(void *buffer, size_t size, size_t count, void *pointer);

private:
	HttpCmdList m_httpCmdList;
};

#endif //_httpmgr_h_