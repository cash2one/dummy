///<------------------------------------------------------------------------------
//< @file:   server\net\msgdispatcher.h
//< @author: ������
//< @date:   2015��3��8�� 15:1:8
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _msgdispatcher_h_
#define _msgdispatcher_h_

#include <google/protobuf/message.h>

#include "net/link.h"
#include "tool/timetool.h"
#include "imsghandler.h"

template <typename LinkType>
class MsgDispatcher
{
private:
	typedef tr1::unordered_map<int, IMsgHandler<LinkType>*> MsgHandlerMap;
	typedef std::vector<IMsgHandler<LinkType>*> MsgHandlerVec;

public:
	// ����register����ԭ��������ͻ��������Register
	void Register(int msgId, IMsgHandler<LinkType> *msgHandler)
	{
		m_msgMap[msgId] = msgHandler;
	}

	void dispatch(LinkType& link, int msgId, const char* data, int len, Timestamp receiveTime)
	{
		typename MsgHandlerMap::const_iterator itr = m_msgMap.find(msgId);
		if (itr == m_msgMap.end()) {
			return;
		}

		IMsgHandler<LinkType> *msgMgr = itr->second;
		msgMgr->onMessage(link, msgId, data, len, receiveTime);
	}

	void addMsgHandler(IMsgHandler<LinkType> *msgHandler)
	{
		m_msgHandlerVec.push_back(msgHandler);
	}

	void clear()
	{
		for (size_t i = 0; i < m_msgHandlerVec.size(); i++) {
			IMsgHandler<LinkType> *msgHandler = m_msgHandlerVec[i];
			msgHandler->clear();
			delete msgHandler;
		}

		m_msgHandlerVec.clear();
	}

private:
	MsgHandlerMap m_msgMap;
	MsgHandlerVec m_msgHandlerVec;;
};

#endif //_msgdispatcher_h_