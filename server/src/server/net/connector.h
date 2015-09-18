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

class NetFactory;

class INetReactor;

// ������������������ָ����<ip,�˿�>�������ӣ�������Ӳ��Ͻ���ʱ��������ֱ���ɹ�
class Connector : public IFd
{
	static const int MaxRetryDelayMs = 30 * 1000; // ���������������
	static const int InitRetryDelayMs = 3000;	  // ��һ�γ��������ļ��

	// ����������״̬
	enum States {
		StateDisconnected, // δ����
		StateConnecting,   // ������
		StateConnected	   // �����ӳɹ�
	};

public:
	Connector(NetAddress &peerAddr, INetReactor*, NetModel*, const char* remoteHostName, NetFactory *pNetFactory);

	bool open();

	virtual socket_t socket() const {return m_sockfd;}

	// ����ɶ��¼�
	virtual void handleRead();

	// �����д�¼������ڷ�����connect�������ӳɹ�����ʱ����������ɿ�д
	virtual void handleWrite();

	// �����쳣�������쳣����һ��ʱ�䳢������
	virtual void handleError();

	// �رձ��������������α��������ϵ����������¼�����׼�������ڴ�
	virtual void close();

	// ɾ����������
	virtual void erase();

	// ��ʼ����
	void connect();

	// ���ӳɹ�
	bool onConnected();

	// ���������У�ע���¼��ȴ��������ӳɹ���ʧ�ܵ������ź�
	bool connecting();

	// ��һ��ʱ���������
	bool retry();

private:
	// ����һ��link
	Link* createLink(socket_t newfd, NetAddress &peerAddr);

private:
	// �Զ˵������ַ
	NetAddress m_peerAddr;

	// �뱾�������󶨵��߼�ʵ��
	INetReactor *m_pNetReactor;

	// ��������
	NetModel *m_net;

	// �����������׽���
	socket_t m_sockfd;

	// ���������ļ��
	int m_retryDelayMs;

	// ��ǰ����������״̬��δ���ӡ������С������ӳɹ�
	States m_state;

	// ��ǰ���ӵ�socket������
	int m_errno;

	// �Զ˵�ҵ������
	std::string m_remoteHostName;

	NetFactory *m_netNetFactory;
};

#endif //_connector_h_