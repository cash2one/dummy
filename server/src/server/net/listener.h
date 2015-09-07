///<------------------------------------------------------------------------------
//< @file:   server\net\listener.h
//< @author: ������
//< @date:   2014��11��25�� 19:14:27
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _listener_h_
#define _listener_h_

#include "net.h"
#include "netaddress.h"

class INetReactor;
class Link;
class NetAddress;
class NetFactory;

// ���������������ָ���˿��Ͻ��յ���������
class Listener : public IFd
{
public:
	Listener(NetModel*, INetReactor*);

	// ��ʼ����
	virtual bool open(const string& ip, int port);

	// ֹͣ����
	virtual void close();

	// ɾ����������
	virtual void erase();

	// ���ؼ����׽���
	virtual socket_t socket() const {return m_listenFd;}

	// ����ɶ��¼������ڷ�����listen�������յ�������ʱ����������ɿɶ�
	virtual int handleRead();

	// �����д�¼�
	virtual int handleWrite();

	// �����쳣�¼�
	virtual int handleError();

private:
	Link* createLink(socket_t newfd, NetAddress &peerAddr);

public:
	// ��ǰ���ڼ����ĵ�ַ
	NetAddress m_listenAddr;

private:
	// ��������
	NetModel *m_net;

	// �뱾�������󶨵��߼�ʵ��
	INetReactor *m_pNetReactor;

	// ���ڼ�����socket
	socket_t m_listenFd;
};

#endif //_listener_h_