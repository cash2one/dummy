///<------------------------------------------------------------------------------
//< @file:   server\net\net.h
//< @author: hongkunan
//< @date:   2015��1��13�� 14:10:49
//< @brief:	 �������ģ��ṩ����ָ��<ip:�˿�>������ָ��<�˿�>����������ӿ�
//< Copyright (c) 2015 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _net_h_
#define _net_h_

#include "basic/thread.h"

class NetModel;
class TaskQueuePool;
class Thread;
class Listener;
class Link;
class Connector;
class INetLogic;

// ����ͨ�����ģ��ṩ����ָ��<ip:�˿�>������ָ��<�˿�>����������ӿ�
class Net
{
	friend class Listener;
	friend class Connector;

	typedef std::vector<Listener*>	ListenerVec;
	typedef std::vector<Connector*> ConnectorVec;

private:
	// ÿ�������߳������󽫿�ʼִ�б�����
	static void runNet(void *e);

public:
	Net();

	// ��ʼ�����磺���忪���߳��������ӳؿռ�
	bool init(int threadCnt, int initLinkCnt = 100);

	// ��ʼִ���������
	void start();

	// ִֹͣ�����������������ֱ�����������̹߳رգ�
	void stop();

	// ����ָ����ip�Ͷ˿ڣ��ɴ����INetLogic����������
	Listener* listen(const string& ip, int port, INetLogic&);

	// ��������ָ����ip�Ͷ˿ڣ��ɴ����INetLogicִ�����ӽ��ճɹ���Ĳ���
	Connector* connect(const string& ip, int port, INetLogic&, const char* remoteHostName);

private:
	// �ӵ�2�������߳������λ�ȡ��һ�������̣߳�����1�������߳�ʱ��ֻ����1����
	NetModel *nextNetModel();

public:

	std::vector<NetModel*>	m_nets;			// ����ģ��: linux��epoll / windows��select

	int						m_allocNetIdx;	// ��һ�η���������߳�����

	Thread					m_netThread;	// �����߳�

	bool					m_started;		// �Ƿ���������־

	ListenerVec				m_listeners;	// ����������б�

	ConnectorVec			m_connectors;	// �����������б�
};

#endif //_net_h_