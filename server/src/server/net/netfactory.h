///<------------------------------------------------------------------------------
//< @file:   server\net\netfactory.h
//< @author: hongkunan
//< @date:   2015��1��13�� 14:10:49
//< @brief:
//< Copyright (c) 2015 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _netfactory_h_
#define _netfactory_h_

#include "basic/thread.h"
#include "basic/objectpool.h"
#include "net.h"
#include "link.h"

class Epoll;
class Select;
class TaskQueuePool;
class Thread;
class Listener;
class Link;
class Connector;
class INetReactor;

// ����ͨ�����ģ��ṩlisten��connect����������ӿ�
class NetFactory
{
	friend class Listener;
	friend class Connector;

	typedef std::vector<Listener*> ListenerVec;
	typedef std::vector<Connector*> ConnectorVec;

private:
	// �����߳������󽫿�ʼִ�б�����
	static void runNet(void *e);

public:
	NetFactory();

	// ��ʼ�����磺���忪���߳��������ӳؿռ�
	bool init(int threadCnt, int initLinkCnt = 200);

	// ��ʼִ���������
	void start();

	// ִֹͣ�����������������ֱ�����������̹߳رգ�
	void stop();

	// ����ָ����ip�Ͷ˿ڣ��ɴ����INetReactor����������
	Listener* listen(const string& ip, int port, INetReactor&);

	// ��������ָ����ip�Ͷ˿ڣ��ɴ����INetReactorִ�����ӽ��ճɹ���Ĳ���
	Connector* connect(const string& ip, int port, INetReactor&, const char* remoteHostName);

	// ����һ�������߳���ȡ������ͨ������ָ��
	NetModel *nextNet();

public:
	// ����ģ��: linux��epoll / windows��select
	std::vector<NetModel*> m_nets;

	int m_curNetIdx;

	// �����߳�
	Thread m_netThread;

	// �Ƿ���������־
	bool m_started;

	// ����������б�
	ListenerVec m_listeners;

	// �����������б�
	ConnectorVec m_connectors;
};

#endif //_netfactory_h_