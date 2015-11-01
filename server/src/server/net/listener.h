///<------------------------------------------------------------------------------
//< @file:   server\net\listener.h
//< @author: ������
//< @date:   2014��11��25�� 19:14:27
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _listener_h_
#define _listener_h_

#include "netdefine.h"
#include "netaddress.h"

class INetLogic;
class Link;
class NetAddress;
class Net;

// ���������������ָ���˿��Ͻ��յ���������
class Listener : public IFd
{
public:
	Listener(NetModel*, INetLogic*, Net*);

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

	// �����д�¼��������ǽ��ղ����ģ�
	virtual void handleWrite();

	// �����쳣�¼��������ǽ��ղ����ģ�
	virtual void handleError();

private:
	// ����һ���µ�����ʵ��
	Link* allocLink(socket_t newfd, NetAddress &peerAddr);

public:
	// ��ǰ���ڼ����ĵ�ַ
	NetAddress m_listenAddr;

private:
	// ��������
	NetModel *m_netModel;

	// �뱾�������󶨵��߼�ʵ��
	INetLogic *m_logic;

	// ���ڼ�����socket
	socket_t m_listenFd;

	Net *m_net;
};

#endif //_listener_h_