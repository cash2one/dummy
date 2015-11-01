///<------------------------------------------------------------------------------
//< @file:   server\net\connector.h
//< @author: ������
//< @date:   2015��3��4�� 12:25:54
//< @brief:  ����������
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _connector_h_
#define _connector_h_

#include "netaddress.h"
#include "netdefine.h"

class Net;
class NetModel;

// ����������������������ָ����<ip,�˿�>�������ӣ�������Ӳ��Ͻ���ʱ��������ֱ���ɹ�
class Connector : public IFd
{
	static const int max_retry_delay_ms = 30 * 1000; // ���������������
	static const int init_retry_delay_ms = 3000;	  // ��һ�γ��������ļ��

	// ����������״̬
	enum ConnectState {
		StateDisconnected, // δ����
		StateConnecting,   // ������
		StateConnected	   // �����ӳɹ�
	};

public:
	Connector(NetAddress &peerAddr, INetLogic*, NetModel*, const char* remoteHostName, Net*);

	// ��ʼ����������
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
	// ����һ���µ�����ʵ��
	Link* allocLink(socket_t newfd, NetAddress &peerAddr);

private:
	// �Զ˵������ַ
	NetAddress m_peerAddr;

	// �뱾�������󶨵��߼�ʵ��
	INetLogic *m_logic;

	// ��������
	NetModel *m_netModel;

	// �����������׽���
	socket_t m_sockfd;

	// ���������ļ��
	int m_retryDelayMs;

	// ��ǰ����������״̬��δ���ӡ������С������ӳɹ�
	ConnectState m_state;

	// ��ǰ���ӵ�socket������
	int m_errno;

	// �Զ˵�ҵ������
	std::string m_remoteHostName;

	// ��������
	Net *m_net;
};

#endif //_connector_h_