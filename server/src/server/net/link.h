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

// Link = tcp connection
class Link : public IFd
{
public:
	explicit Link(int sockfd, NetAddress &localAddr, NetAddress &peerAddr, task_queue_i *pQueue, INet *pNet, INetReactor *pNetReactor)
		: m_sockfd(sockfd)
		, m_localAddr(localAddr)
		, m_peerAddr(peerAddr)
		, m_tq(pQueue)
		, m_net(pNet)
		, m_pNetReactor(pNetReactor)
		, m_isClosing(false)
		, m_isCreateByConnector(false)
	{
	}

	~Link() {}

	void open();
	virtual void close();

	void onLogicClose();
	void onClose();
	void onSend(Buffer &buff);

	void send(Buffer&);
	void send(const char *data, int len);
	void send(const char *msg);
	void send(string &msg);
	void send(int msgId, google::protobuf::Message &msg);
	void send(int msgId, const char *data, int len);

	bool isOpen() { return m_sockfd > 0; }

	virtual socket_t socket() const {return m_sockfd;}

	virtual int handleRead();
	virtual int handleWrite();
	virtual int handleError();

	int handleReadTask();
	int handleWriteTask();
	int handleErrorTask();

	NetAddress getLocalAddr();

private:
	// ����һ���Է������ݣ�������δ���͵����ݳ���
	int trySend(Buffer&);

public:
	const NetAddress m_peerAddr;
	const NetAddress m_localAddr;

	INetReactor *m_pNetReactor;

	bool m_isCreateByConnector;

private:
	bool m_isClosing;

	socket_t m_sockfd;
	INet *m_net;

	task_queue_i *m_tq;

	Buffer m_recvBuf;
	Buffer m_sendBuf;
};

#endif //_link_h_