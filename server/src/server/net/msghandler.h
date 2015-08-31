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

template <typename LinkType>
class Callback
{
public:
	// virtual ~Callback() {};
	virtual void onMessage(LinkType&, const char* data, int len, Timestamp) const = 0;
};

template <typename LinkType, typename MessageType>
class CallbackT : public Callback<LinkType>
{
public:
	typedef void (*ProtobufMessageCallback)(LinkType*, MessageType* message, Timestamp);

	CallbackT(const ProtobufMessageCallback &callback)
		: m_callback(callback)
	{
	}

	virtual void onMessage(LinkType& link, const char* data, int len, Timestamp receiveTime) const
	{
		MessageType *t = msgtool::allocRecvPacket<MessageType>();

		bool ok = t->ParseFromArray(data, len);
		if (!ok) {
			LOG_ERROR << "decode packet <" << t->GetTypeName() << "> = <" << t->SerializeAsString() << "> error, data len = " << len;
			// LOG_INFO << "decode packet <" << msgtool::getMsgString(*t) << "> error";
			return;
		}

		// assert(t != NULL);
		m_callback(&link, t, receiveTime);
		msgtool::freePacket(t);
	}

private:
	ProtobufMessageCallback m_callback;
};

// ��Ϣ��������ʵ�֣�����֮������ȡ��IMsgHandler�ӿ���Ϊ�˷�ֹģ���ļ�����������±��벻����
// LinkType�����˭���ϵõ���message������Client��Link��
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

	void onMessage(LinkType& link, int msgId, const char* data, int len, Timestamp receiveTime) const
	{
		typename CallbackMap::const_iterator it = m_callbackMap.find(msgId);
		if (it == m_callbackMap.end()) {
			LOG_DEBUG << "Discard msg[id=" << msgId << "]";
			return;
		}

		Callback<LinkType> *callback = it->second;
		callback->onMessage(link, data, len, receiveTime);
	}

	template <typename MessageType>
	void registerMsg(int msgId, void (*callback)(LinkType*, MessageType* message, Timestamp))
	{
		CallbackT<LinkType, MessageType> *pd = new CallbackT<LinkType, MessageType>(callback);
		m_callbackMap[msgId] = pd;

		m_msgDispacher->Register(msgId, this);
	}

	void discardMessage(Link& link, const Message& message, Timestamp receiveTime) const
	{
		LOG_DEBUG << "Discarding " << msgtool::getMsgString(message);
	}

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

	CallbackMap m_callbackMap;
	MsgDispatcher<LinkType> *m_msgDispacher;
};

#endif //_msghandler_h_