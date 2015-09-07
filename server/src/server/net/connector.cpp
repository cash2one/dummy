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

Connector::Connector(NetAddress &peerAddr, INetReactor *netReactor, NetModel *net, const char* remoteHostName)
	: m_peerAddr(peerAddr)
	, m_pNetReactor(netReactor)
	, m_net(net)
	, m_retryDelayMs(InitRetryDelayMs)
	, m_state(StateDisconnected)
	, m_errno(0)
	, m_remoteHostName(remoteHostName)
{
	m_sockfd = socktool::createSocket();
	socktool::setNonBlocking(m_sockfd);
	//socktool::setTcpNoDelay(m_sockfd);
}

void Connector::connect()
{
	// ֱ������
	// ע�⣺�����Ƿ�����connect��һ����������� EINPROGRESS ���󣬱�ʾ���Ӳ������ڽ����У�������δ��ɣ����ͬʱ TCP �������ֲ�����ͬʱ����
	// ����֮�����ǿ��Բ����д�¼��Լ�error�¼��������������Ƿ����ɹ�
	int ret = ::connect(m_sockfd, (struct sockaddr *)&m_peerAddr.getSockAddr(), static_cast<socklen_t>(sizeof sockaddr_in));

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
}

int Connector::handleRead()
{
	// һ���ǲ�����յ����¼��ģ����������ӡerror
	LOG_ERROR << m_pNetReactor->name() << "recv read event, socket = " << m_sockfd;
	return 0;
}

int Connector::handleWrite()
{
	// �ȼ���׽����Ƿ����쳣
	m_errno = socktool::getSocketError(m_sockfd);
	if (m_errno > 0) {
		// ����⵽�쳣��������
		LOG_SOCKET_ERR(m_sockfd, m_errno) << m_pNetReactor->name();
		retry();

		return -1;
	}

	// �ɹ���������
	onConnected();
	return 0;
}

int Connector::handleError()
{
	// LOG_SYSTEM_ERR << m_pNetReactor->name() << " socket<" << m_sockfd << ">";
	retry();
	return true;
}

void Connector::close()
{
	//LOG_INFO << "Connector::close, socket = " << m_sockfd;
	m_net->disableAll(this);
	m_net->delFd(this);
}

void Connector::erase()
{
	delete this;
}

bool Connector::onConnected()
{
	// �ɹ������϶Զ�
	Link* link = createLink(m_sockfd, m_peerAddr);
	if (NULL == link) {
		LOG_ERROR << m_pNetReactor->name() << " connector create link failed, socket = " << m_sockfd;
		this->close();
		socktool::closeSocket(m_sockfd);
		return false;
	}

	this->close();

	link->open();

	// �����ӳɹ�����ϢͶ��ҵ���
	m_pNetReactor->getTaskQueue().put(boost::bind(&INetReactor::onConnected, m_pNetReactor, link, link->m_localAddr, m_peerAddr));

	// ��ҵ��㴦���������Ӻ󣬲���������ӿ�ʼ��
	m_pNetReactor->getTaskQueue().put(boost::bind(&NetModel::enableRead, m_net, link));

	return true;
}

bool Connector::connecting()
{
	if (m_state == StateDisconnected) {
		// ����������ע�ᵽ����
		m_net->addFd(this);

		// ע��д�¼�
		m_net->enableWrite(this);

		m_state = StateConnecting;
	} else if(m_state == StateConnecting) {
		// ����ע��д�¼���������Ҫ��������������ע�ᵽ���磩
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

	LOG_SOCKET_ERR(m_sockfd, m_errno) << "socket<" << m_sockfd << "> connect to " << m_remoteHostName << "<" << m_peerAddr.toIpPort() << "> fail, retry after <" << m_retryDelayMs << "> ms";
	m_errno = 0;

	if (m_state == StateConnecting) {
		// ���������¼�����ֹ���޴���exception
		m_net->disableAll(this);

#ifndef WIN
		m_state = StateDisconnected;
#endif
	}

	// ���ö�ʱ���񣺸�һ��ʱ�����������
	TimerQueue &timerQueue = m_net->getTimerQueue();
	timerQueue.runAfter(boost::bind(&Connector::connect, this), m_retryDelayMs);

	// ����ʱ�� = ����ʱ�� * 2
	m_retryDelayMs = MIN(m_retryDelayMs * 2, MaxRetryDelayMs);
	return true;
}

Link* Connector::createLink(socket_t newfd, NetAddress &peerAddr)
{
	LinkPool &linkPool = m_net->getLinkPool();
	NetAddress localAddr(socktool::getLocalAddr(newfd));

	Link *link = linkPool.alloc(newfd, localAddr, peerAddr, m_net, m_pNetReactor);
	if (NULL == link) {
		return NULL;
	}

	link->m_isAutoReconnect = true;
	return link;
}