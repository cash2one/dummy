///<------------------------------------------------------------------------------
//< @file:   server\net\connector.h
//< @author: ������
//< @date:   2015��3��4�� 12:25:54
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _connector_h_
#define _connector_h_

#include "netaddress.h"
#include "net/net.h"

class INetReactor;

class Connector : public IFd
{
public:
	Connector(NetAddress &peerAddr, INetReactor*, INet*, task_queue_pool_t*);

	virtual socket_t socket() const {return m_sockfd;}
	virtual int handleRead();
	virtual int handleWrite(); // ���ڷ�����connect�������ӳɹ�����ʱ����������ɿ�д
	virtual int handleError();
	virtual void close();

	bool connect();

	bool onConnected();

	bool connecting();

	bool retry(socket_t);

private:
	Link* createLink(socket_t newfd, NetAddress &peerAddr);

private:
	static const int MaxRetryDelayMs = 30 * 1000;
	static const int InitRetryDelayMs = 500;

	enum States { kDisconnected, kConnecting, kConnected };

private:
	NetAddress m_peerAddr;
	INetReactor *m_pNetReactor;
	INet *m_net;
	task_queue_pool_t* m_taskQueuePool;

	socket_t m_sockfd;
	int m_retryDelayMs;
	States m_state;
};

#endif //_connector_h_