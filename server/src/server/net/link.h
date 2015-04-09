///<------------------------------------------------------------------------------
//< @file:   server\net\link.h
//< @author: ������
//< @date:   2015��1��14�� 23:3:23
//< @brief:	 Link = tcp����
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _link_h_
#define _link_h_

#include "net.h"
#include "netaddress.h"
#include "basic/buffer.h"
#include "protocol/protocol.h"

class NetAddress;
class INetReactor;

namespace google {namespace protobuf {class Message;}}

// Link = tcp���ӣ��൱��connection
class Link : public IFd
{
public:
	explicit Link(int sockfd, NetAddress &localAddr, NetAddress &peerAddr, task_queue_i *pQueue, NetModel *pNet, INetReactor *pNetReactor)
		: m_localAddr(localAddr)
		, m_peerAddr(peerAddr)
		, m_pNetReactor(pNetReactor)
		, m_isCreateByConnector(false)
		, m_isClosing(false)
		, m_sockfd(sockfd)
		, m_net(pNet)
		, m_taskQueue(pQueue)
	{
	}

	~Link() {}

public:
	virtual socket_t socket() const {return m_sockfd;}
	virtual int handleRead();
	virtual int handleWrite();
	virtual int handleError();
	virtual void close();
	virtual void erase();

public:
	void open();

	void enableRead();

	void send(const char *data, int len);
	void send(const char *text);
	void send(int msgId, Message &msg);
	void send(int msgId, const char *data, int len);

	bool isopen() { return !m_isClosing; }

private:
	void sendBuffer(Buffer*);

	NetAddress getLocalAddr();

private:
	// ����һ���Է������ݣ�������δ���͵����ݳ���
	int trySend(Buffer&);

	void onLogicClose();
	void onNetClose();
	void onSend(Buffer *buff);

	int handleReadTask();
	int handleWriteTask();

public:
	const NetAddress m_localAddr;
	const NetAddress m_peerAddr;

	INetReactor *m_pNetReactor;

	bool m_isCreateByConnector;

private:
	volatile bool m_isClosing;

	socket_t m_sockfd;
	NetModel *m_net;

	task_queue_i *m_taskQueue;

	Buffer m_recvBuf;
	Buffer m_sendBuf;
};

#endif //_link_h_