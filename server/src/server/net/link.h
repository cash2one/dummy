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
struct RingBufferBlock;

namespace google {namespace protobuf {class Message;}}

// Link = tcp���ӣ��൱��connection
class Link : public IFd
{
public:
	explicit Link(int sockfd, NetAddress &localAddr, NetAddress &peerAddr, NetModel *pNet, INetReactor *pNetReactor)
		: m_localAddr(localAddr)
		, m_peerAddr(peerAddr)
		, m_pNetReactor(pNetReactor)
		, m_isAutoReconnect(false)
		, m_closed(false)
		, m_sockfd(sockfd)
		, m_net(pNet)
		, m_head(NULL)
		, m_tail(NULL)
		, m_isWaitingWrite(false)
		, m_isWaitingRead(false)
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

	bool isopen() { return !m_closed; }

private:
	void sendBuffer();

	NetAddress getLocalAddr();

private:
	// ����һ���Է������ݣ�������δ���͵����ݳ���
	int trySend(Buffer&);

	void onLogicClose();
	void onNetClose();
	void onSend();

public:
	const NetAddress m_localAddr;
	const NetAddress m_peerAddr;

	INetReactor *m_pNetReactor;

	bool m_isAutoReconnect;

	RingBufferBlock *m_head;
	RingBufferBlock *m_tail;

public:
	volatile bool m_closed;

	socket_t m_sockfd;
	NetModel *m_net;

	task_queue_i *m_taskQueue;

	Buffer m_recvBuf;
	Buffer m_sendBuf;

	fast_mutex m_sendBufLock;
	fast_mutex m_recvBufLock;

	bool m_isWaitingWrite;
	bool m_isWaitingRead;
};

#endif //_link_h_