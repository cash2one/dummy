///<------------------------------------------------------------------------------
//< @file:   server\net\msghandler.h
//< @author: ������
//< @date:   2015��3��17�� 23:59:29
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _msghandler_h_
#define _msghandler_h_

#include <google/protobuf/message.h>

// #include "basic/bind.h"
#include "tool/timetool.h"
#include "protocol/message.h"
#include "net/msgdispatcher.h"
#include "net/imsghandler.h"

class Link;

// ��Ϣ������
// ������֮������ȡ��IMsgHandler�ӿ���Ϊ�˷�ֹģ���ļ�����������±��벻����
// ��LinkType���������ʵ�����ϵõ���message���������ͻ������ӵ�Client������ײ��������ӵ�Link�ȣ�
template <typename LinkType>
class MsgHandler : public IMsgHandler<LinkType>
{
private:
	typedef tr1::unordered_map<int, Callback<LinkType>*> CallbackMap;

public:
	MsgHandler(MsgDispatcher<LinkType> *msgDispacher)
		: m_msgDispacher(msgDispacher)
	{
	}

	// ��ĳ����Ϣidע���Ӧ�Ļص�����
	template <typename MessageType>
	void registerMsg(int msgId, void (*callback)(LinkType*, MessageType* message, Timestamp))
	{
		CallbackT<LinkType, MessageType> *pd = new CallbackT<LinkType, MessageType>(callback);
		m_callbackMap[msgId] = pd;

		m_msgDispacher->registerMsg(msgId, pd);
	}

	// ����������Դ�������ڴ�
	void clear()
	{
		typename CallbackMap::iterator itr(m_callbackMap.begin());
		typename CallbackMap::iterator end(m_callbackMap.end());

		for (; itr != end; ++itr) {
			Callback<LinkType> *callBack = itr->second;

			// LOG_INFO << "delete";
			delete callBack;
		}

		m_callbackMap.clear();
	}

	CallbackMap					m_callbackMap;		// ��Ϣ�ص�map

	MsgDispatcher<LinkType>*	m_msgDispacher;	// ��Ϣ�ɷ���
};

#endif //_msghandler_h_