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

struct evbuffer;

namespace google {namespace protobuf {class Message;}}

// �������ӣ�Link = tcp���ӣ��൱��connection
class Link : public IFd
{
public:
	explicit Link(int sockfd, NetAddress &localAddr, NetAddress &peerAddr, NetModel *pNet, INetReactor *pNetReactor)
		: m_localAddr(localAddr)
		, m_peerAddr(peerAddr)
		, m_pNetReactor(pNetReactor)
		, m_isAutoReconnect(false)
		, m_closed(false)
		, m_error(false)
		, m_sockfd(sockfd)
		, m_net(pNet)
		, m_isWaitingWrite(false)
		, m_isWaitingRead(false)
		, m_isWaitingClose(false)
		, m_isPeerClosed(false)
		, m_isRegisterWrite(false)
		, m_nil(0)
	{
	}

	~Link();

public:
	virtual socket_t socket() const {return m_sockfd;}

	virtual void handleRead();
	virtual void handleWrite();
	virtual void handleError();
	virtual void close();
	virtual void erase();

private:
	void closing();

public:
	// ���ñ����Ӳ�������ע�ᵽ����
	void open();

	// ��������
	void send(const char *data, int len);

	// �����ı�
	void send(const char *text);

	// ����δ���ܵ���Ϣ��
	void send(int msgId, Message &msg);

	// ���;������ܻ��������Ϣ��
	void send(int msgId, const char *data, int len);

	// �������Ƿ��
	inline bool isopen() const { return !m_closed; }

	// ��ȡ�����ӵı��ص�ַ
	NetAddress getLocalAddr() const;

	// ��ȡ�����ӵĶԶ˵�ַ
	NetAddress getPeerAddr() const;

private:
	// ���ͱ�������δ�����������
	void sendBuffer();

private:
	// ����㣺����һ���Է������ݣ�������δ���͵����ݳ���
	int trySend(evbuffer*);

	// ҵ��㣺�������ӵĹر�
	void onLogicClose();

	// ����㣺��ʼ��������
	void onSend();

public:
	const NetAddress m_localAddr;
	const NetAddress m_peerAddr;

	// ����������Ӧ���߼�ʵ��
	INetReactor *m_pNetReactor;

	// �Զ�������־λ����ʾ�����ӶϿ����Ƿ���Ҫ�Զ�����
	bool m_isAutoReconnect;

public:
	// �Ƿ��ѹرձ�־λ����ֹ�ظ�close
	bool m_closed;

	// �����־λ����ʾ�������Ƿ���������������Ҫ�ر����ӵĴ���
	bool m_error;

	// �Ƿ����ڵȴ��ر���
	bool m_isWaitingClose;

	// �׽���
	socket_t m_sockfd;

	// ��������
	NetModel *m_net;

	// ���ͻ�����
	evbuffer* m_sendBuf;

	// ���ջ�����
	evbuffer* m_recvBuf;

	// ���ͻ�������
	mutex_t m_sendBufLock;

	// ���ջ�������
	mutex_t m_recvBufLock;

	// �Ƿ����ڵȴ�д
	bool m_isWaitingWrite;

	// �Ƿ����ڵȴ���
	bool m_isWaitingRead;

	// �Զ��Ƿ��ѹر�
	bool m_isPeerClosed;

	// �Ƿ���ע����д�¼���д�¼�ע��һ�ξ��У�
	bool m_isRegisterWrite;

	evbuffer *m_sendSwapBuf;
	evbuffer *m_recvSwapBuf;

	Buffer m_nil;
};

#endif //_link_h_