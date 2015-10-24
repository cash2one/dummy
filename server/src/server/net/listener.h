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
	Listener(NetModel*, INetReactor*, NetFactory*);

	// ��ʼ����
	virtual bool open(const string& ip, int port);

	// ֹͣ����
	virtual void close();

	// ɾ����������
	virtual void erase();

	// ���ؼ����׽���
	virtual socket_t socket() const {return m_listenFd;}

	// ����ɶ��¼������ڷ�����listen�������յ�������ʱ����������ɿɶ�
	virtual void handleRead();

	// �����д�¼�
	virtual void handleWrite();

	// �����쳣�¼�
	virtual void handleError();

private:
	Link* createLink(socket_t newfd, NetAddress &peerAddr);

public:
	// ��ǰ���ڼ����ĵ�ַ
	NetAddress m_listenAddr;

private:
	// ��������
	NetModel *m_net;

	// �뱾�������󶨵��߼�ʵ��
	INetReactor *m_logic;

	// ���ڼ�����socket
	socket_t m_listenFd;

	NetFactory *m_netNetFactory;
};

#endif //_listener_h_