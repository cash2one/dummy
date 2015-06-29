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
	CURL *curl = NULL;

	CURLcode code = curl_global_init(CURL_GLOBAL_DEFAULT);
	if (code != CURLE_OK) {
		LOG_ERROR << "Failed to global init default " << code << "!";
		return false;
	}

	m_currentCurl = curl_multi_init();
	if( !m_currentCurl ) {
		LOG_ERROR << "curl_multi_init failed!";
		return false;
	}

	return true;
}

void HttpMgr::uninit()
{
	curl_multi_cleanup(m_currentCurl);
	curl_global_cleanup();
}

void HttpMgr::run()
{
	if (m_httpCmdList.empty()) {
		return;
	}

	int runningHandles = 0;
	CURLMcode code = curl_multi_perform( m_currentCurl, &runningHandles);
	if( CURLM_OK != code ) {
		LOG_ERROR << "curl_multi_perform failed!";
		return;
	}

	// ���ڻ��浱ǰ��ִ����ɵ�http����
	HttpCmdList doneHttpCmds;

	int MsgNumLeft = 0;
	CURLMsg* pMsg = NULL;

	// ��ȡ�ѷ��ؽ����http����
	while( pMsg = curl_multi_info_read( m_currentCurl, &MsgNumLeft ) ) {
		if( pMsg->msg != CURLMSG_DONE ) {
			continue;
		}

		HttpCmdList::iterator itr = m_httpCmdList.begin();
		HttpCmdList::iterator end = m_httpCmdList.end();
		for(; itr != end; ++itr) {
			if( (*itr)->m_curl != pMsg->easy_handle) {
				continue;
			}

			break;
		}

		if( itr == m_httpCmdList.end() ) {
			LOG_ERROR << "find easy handle failed!";
			break;
		}

		HttpCmd *cmd = *itr;
		cmd->m_ok = (CURLE_OK == pMsg->data.result) ? true : false;

		doneHttpCmds.push_back(cmd);
		m_httpCmdList.erase(itr);

		//�ͷ�
		curl_multi_remove_handle(m_currentCurl, cmd->m_curl);
	}

	// ��鳬ʱ
	HttpCmdList::iterator itr = m_httpCmdList.begin();
	HttpCmdList::iterator end = m_httpCmdList.end();

	Timestamp now = timetool::getTimeOfDay();
	for(; itr != end;) {
		HttpCmd *cmd = *itr;

		if(now - cmd->m_lastAddTime > 30 * 1000) {
			cmd->m_ok = false;

			doneHttpCmds.push_back(cmd);
			m_httpCmdList.erase(itr++);

			//�ͷ�
			curl_multi_remove_handle(m_currentCurl, cmd->m_curl);
		}
		else {
			itr++;
		}
	}

	// �����ѷ��ؽ����http����
	for(HttpCmdList::iterator itr = doneHttpCmds.begin(); itr != doneHttpCmds.end(); ++itr) {
		HttpCmd *httpcmd = *itr;

		httpcmd->onExecuted();
		httpcmd->release();
	}
}

size_t HttpMgr::onRecvHtml(void *buffer, size_t size, size_t count, void *pointer)
{
	if( NULL == pointer ) {
		return 0;
	}

	//���յ�����
	HttpCmd *httpcmd = (HttpCmd *)(pointer);
	httpcmd->m_html.append((char *)buffer, size * count );
	return size * count;
}

bool HttpMgr::addCmd(HttpCmd *cmd)
{
	cmd->bind();
	cmd->m_lastAddTime = timetool::getTimeOfDay();

	// ���ý��յ�html��Ļص�����
	curl_easy_setopt(cmd->m_curl, CURLOPT_WRITEFUNCTION, onRecvHtml);

	// ����DNS����ʱ��
	curl_easy_setopt(cmd->m_curl, CURLOPT_DNS_CACHE_TIMEOUT, 20);

	if( CURLM_OK != curl_multi_add_handle( m_currentCurl, cmd->m_curl) ) {
		LOG_ERROR << "curl_multi_add_handle failed!";
		cmd->release();
		return false;
	}

	m_httpCmdList.push_back(cmd);
	return true;
}
