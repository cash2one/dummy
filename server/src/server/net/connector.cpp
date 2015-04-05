///<------------------------------------------------------------------------------
//< @file:   server\net\connector.cpp
//< @author: ������
//< @date:   2015��3��4�� 12:26:11
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "connector.h"

#include <stdlib.h>

#include "tool/sockettool.h"
#include "net/netaddress.h"
#include "net/netreactor.h"
#include "net/link.h"
#include "basic/timerqueue.h"
#include "basic/taskqueue.h"

Connector::Connector(NetAddress &peerAddr, INetReactor *netReactor, INet *net, task_queue_pool_t *taskQueuePool)
	: m_peerAddr(peerAddr)
	, m_pNetReactor(netReactor)
	, m_net(net)
	, m_taskQueuePool(taskQueuePool)
	, m_retryDelayMs(InitRetryDelayMs)
	, m_state(kDisconnected)
	, m_errno(0)
{
	m_sockfd = socktool::createSocket();
	socktool::setNonBlocking(m_sockfd);
	socktool::setTcpNoDelay(m_sockfd);
}

bool Connector::connect()
{
	int ret = socktool::connect(m_sockfd, m_peerAddr.getSockAddr());

	int err = ((ret == SOCKET_ERROR) ? socktool::geterrno() : 0);
	switch (err) {
	case 0:
		// ���ӳɹ������ͻ��˺ͷ���������ͬһ̨�����ϵ�ʱ��connect�����Ϸ���0��
		LOG_WARN << "warn: socket<" << m_sockfd << "> connect to localhost<" << m_peerAddr.toIpPort() << "> success";
		onConnected();
		break;

#ifdef WIN
	// linux�µ�EAGAIN��EWOULDBLOCK��ͬһ��ֵ������ᱨ��
	case EAGAIN:
#endif
	case EWOULDBLOCK:
	case EINTR:
	case EISCONN:
	case EINPROGRESS:
		// LOG_WARN << "warn: socket <" << m_sockfd << "> starting connecting err = <" << err << ">";

		// �������ӣ�tcp�����������ڽ��У�
		connecting();
		break;

	case EADDRINUSE:
	case EADDRNOTAVAIL:
	case ECONNREFUSED:
	case ENETUNREACH:
		// ����ʧ�ܣ�����
		retry();
		break;

	case EACCES:
	case EPERM:
	case EAFNOSUPPORT:
	case EALREADY:
	case EBADF:
	case EFAULT:
	case ENOTSOCK:
		// �����쳣���ж�
		retry();
		break;

	default:
		// ����δʶ���쳣
		// LOG_SOCKET_ERR << "socket<" << m_sockfd << "> connect to peer<" << m_peerAddr.toIpPort() << "> fail, unexpected error = " << err;
		retry();
		break;
	}

	return true;
}

int Connector::handleRead()
{
	return handleWrite();
}

int Connector::handleWrite()
{
	// �ȼ���׽����Ƿ����쳣
	m_errno = socktool::getSocketError(m_sockfd);
	if (m_errno > 0) {
		// LOG_SYSTEM_ERR << "Connector::handleWrite - SOCK_ERROR = " << err;
		retry();

		return -1;
	}

	// �ɹ���������

	onConnected();
	return 0;
}

int Connector::handleError()
{
	// LOG_ERROR << "Connector::handleError socket<" << m_sockfd << ">";
	retry();
	return true;
}

void Connector::close()
{
	m_net->delFd(this);
}

void OpenLink(Link *link)
{
	link->open();
}

bool Connector::onConnected()
{
	// �ɹ������϶Զ�
	Link* link = createLink(m_sockfd, m_peerAddr);
	this->close();

	link->open();
	m_pNetReactor->getTaskQueue().put(task_binder_t::gen(&INetReactor::onConnected, m_pNetReactor, link, link->m_localAddr, m_peerAddr));
	m_pNetReactor->getTaskQueue().put(task_binder_t::gen(&Link::enableRead, link));

	return true;
}

bool Connector::connecting()
{
	if (m_state == kDisconnected) {
		m_net->addFd(this);
		m_net->enableWrite(this);

		m_state = kConnecting;
	}
	else if(m_state == kConnecting) {
		m_net->enableWrite(this);
	}

	return true;
}

bool Connector::retry()
{
	// ע�⣺�����ӡ�Ĵ���������ο�����Ϊ������ʽ��connect���ѻ�ȡ��ʵ�ʵ�����ʧ��ԭ��
	if (0 == m_errno) {
		m_errno = socktool::getSocketError(m_sockfd);

		if (0 == m_errno) {
			m_errno = socktool::geterrno();
		}
	}

	LOG_SOCKET_ERR(m_sockfd, m_errno) << "socket<" << m_sockfd << "> connect to peer<" << m_peerAddr.toIpPort() << "> fail, retry after <" << m_retryDelayMs << "> ms";
	m_errno = 0;

	if (m_state == kConnecting) {
		m_net->disableAll(this);

#ifndef WIN
		m_state = kDisconnected;
#endif
	}

	TimerQueue &timerQueue = m_net->getTimerQueue();
	timerQueue.runAfter(task_binder_t::gen(&Connector::connect, this), m_retryDelayMs);

	m_retryDelayMs = MIN(m_retryDelayMs * 2, MaxRetryDelayMs);
	return true;
}

Link* Connector::createLink(socket_t newfd, NetAddress &peerAddr)
{
	NetAddress localAddr(socktool::getLocalAddr(newfd));
	Link *link = new Link(newfd, localAddr, peerAddr, m_taskQueuePool->alloc(newfd), m_net, m_pNetReactor);
	link->m_isCreateByConnector = true;
	return link;
}