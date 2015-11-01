///<------------------------------------------------------------------------------
//< @file:   server\net\net.cpp
//< @author: hongkunan
//< @date:   2015��1��13�� 14:11:56
//< @brief:
//< Copyright (c) 2015 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "net.h"
#include "basic/taskqueue.h"
#include "net/netmodel.h"
#include "net/listener.h"
#include "net/connector.h"

void Net::runNet(void *e)
{
	NetModel *net = (NetModel*)e;
	net->eventLoop();
}

Net::Net()
	: m_started(false)
	, m_allocNetIdx(0)
{
}

bool Net::init(int threadCnt, int initLinkCnt)
{
	assert(threadCnt > 0);

	// ��ʼ��ÿ�������߳���Ҫ��������Դ
	for (int i = 0; i < threadCnt; i++) {
		NetModel *net = new NetModel;
		if (NULL == net) {
			LOG_SYSTEM_ERR << "net resource allocate failed not enough memory, aborted!";
			return false;
		}

		net->init(initLinkCnt, initLinkCnt);
		m_nets.push_back(net);
	}

	return true;
}

void Net::start()
{
	if (m_started) {
		return;
	}

	m_started = true;

	// �������������߳�
	for (size_t i = 0; i < m_nets.size(); i++) {
		NetModel *net = m_nets[i];
		m_netThread.createThread(boost::bind(&runNet, net), 1);
	}

	// m_netThread.createThread(boost::bind(&runNetIO, &m_queuePool), m_queuePool.size());
}

void Net::stop()
{
	if (!m_started) {
		return;
	}

	LOG_WARN << "stopping net ...";

#ifndef WIN
	// �ر����м�����
	for(size_t i = 0; i < m_listeners.size(); i++) {
		Listener *listener = m_listeners[i];
		listener->close();
	}

// 	for(size_t i = 0; i < m_connectors.size(); i++) {
// 		Connector *connector = m_connectors[i];
// 		connector->close();
// 	}
#endif

	// �ر�����
	for (size_t i = 0; i < m_nets.size(); i++) {
		NetModel *net = m_nets[i];
		net->close();
	}

	// �ȴ�ֱ�������߳��˳�
	m_netThread.join();

	// �ͷ�����ռ����Դ
	for (size_t i = 0; i < m_nets.size(); i++) {
		NetModel *net = m_nets[i];
		delete net;
	}

	m_nets.clear();

	m_started = false;

	m_listeners.clear();
	m_connectors.clear();

	LOG_WARN << "stop net successful";
}

Listener* Net::listen(const string& ip, int port, INetLogic &logic)
{
	if (0 == port) {
		LOG_SYSTEM_ERR << "listen at <" << ip << ": " << port << "> failed, port = 0!";
		return NULL;
	}

	// ����һ����������������������������ע�ᵽ��1��������
	Listener* listener = new Listener(m_nets[0], &logic, this);
	if (NULL == listener) {
		LOG_SYSTEM_ERR << "listen at <" << ip << ": " << port << "> failed, not enough memory";
		return NULL;
	}

	if (!listener->open(ip, port)) {
		LOG_ERROR << "listen at <" << ip << ": " << port << "> failed";

		delete listener;
		return NULL;
	}

	m_listeners.push_back(listener);
	return listener;
}

Connector* Net::connect(const string& ip, int port, INetLogic &logic, const char* remoteHostName)
{
	NetAddress peerAddr(ip, port);

	// ����һ������������������������������ע�ᵽ��1��������
	Connector* connector = new Connector(peerAddr, &logic, m_nets[0], remoteHostName, this);
	if (NULL == connector) {
		LOG_SYSTEM_ERR << "connect to <" << ip << ": " << port << "> failed, not enough memory";
		return NULL;
	}

	if (!connector->open()) {
		LOG_SYSTEM_ERR << "connect to <" << ip << ": " << port << "> failed, open failed";
		delete connector;
		return NULL;
	}

	connector->connect();

	m_connectors.push_back(connector);
	return connector;
}

NetModel* Net::nextNetModel()
{
	int n = m_nets.size();
	if (1 == n) {
		return m_nets[0];
	}

	m_allocNetIdx++;

	// ���ص�1�������̣߳����ⷵ�ص�0�������߳�
	if (m_allocNetIdx >= n) {
		m_allocNetIdx = 1;
	}

	return m_nets[m_allocNetIdx];
}
