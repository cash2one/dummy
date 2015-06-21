///<------------------------------------------------------------------------------
//< @file:   server\http\httpmgr.cpp
//< @author: ������
//< @date:   2015��6��11�� 21:48:12
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "httpmgr.h"
#include "httpcmd.h"

bool HttpMgr::init()
{
	return true;
}

void HttpMgr::uninit()
{

}

void HttpMgr::run()
{
	// ���ڻ��浱ǰ��ִ����ɵ�http����
	HttpCmdList httpcmds = m_httpCmdList;

	for(HttpCmdList::iterator itr = httpcmds.begin(); itr != httpcmds.end(); ++itr) {
		HttpCmd *httpcmd = *itr;

		httpcmd->onExecuted();
		httpcmd->release();
	}
}

size_t HttpMgr::onRecvResponse(void *buffer, size_t size, size_t count, void *pointer)
{
	if( NULL == pointer ) {
		return 0;
	}

	//���յ�����
	HttpCmd *httpcmd = (HttpCmd *)(pointer);
	httpcmd->m_html.append((char *)buffer, size * count );
	return size * count;
}

bool HttpMgr::addCmd(HttpCmd*)
{
	return true;
}
