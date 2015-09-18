///<------------------------------------------------------------------------------
//< @file:   server\net\link.cpp
//< @author: ������
//< @date:   2015��1��14�� 23:7:5
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "link.h"

#include <google/protobuf/message.h>

#include "netaddress.h"
#include "netreactor.h"
#include "listener.h"
#include "session.h"

#include "log/log.h"
#include "tool/sockettool.h"
#include "protocol/message.h"

#include "tool/atomictool.h"

void Link::open()
{
	socktool::setNonBlocking(m_sockfd);
	socktool::setKeepAlive(m_sockfd, true, 120);

	// socktool::setSendBufSize(m_sockfd, 256 * 1024);
	// socktool::setRecvBufSize(m_sockfd, 256 * 1024);

	if (!socktool::setTcpNoDelay(m_sockfd)) {
		LOG_ERROR << m_pNetReactor->name() << " " << getLocalAddr().toIpPort() << "<-->" << getPeerAddr().toIpPort() << " setTcpNoDelay failed = " << m_localAddr.toPort();
	}

	m_net->addFd(this);

	// ע��д�¼����Դ��������ӿ�дʱ�ٳ��Է���
	m_net->enableWrite(this);
}

void Link::close()
{
	// ����Ƿ��ظ�close
	if (m_closed) {
		return;
	}

	// LOG_INFO << m_pNetReactor->name() << " Link::close, socket = " << m_sockfd;

	// ���δ�����������Ƚ�δ���͵����ݷ������
	if (!m_error) {
		if (m_isWaitingClose) {
			lock_guard_t<> lock(m_sendBufLock);
			if (!m_sendBuf.empty()) {
				return;
			}
		} else {
			// ������δ������ϣ����ݻ��رգ�ֹֻͣ�������ݣ��ȴ�֮ǰ�ķ��Ͳ���ִ����Ϻ��ٹر�
			m_isWaitingClose = true;
			m_net->disableRead(this);

// 			if (!m_isWaitingWrite) {
// 				LOG_ERROR << m_pNetReactor->name() << " m_sendBuf != empty(), left size = " << m_sendBuf.readableBytes() << ", socket = " << m_sockfd << ", waiting left data to be sent";
// 			}

			return;
		};
	}

	m_closed = true;

// �������α������ϵ������������
	socktool::closeSocket(m_sockfd);

#ifdef WIN
	// ����windowsƽ̨������Ҫ�ٴӶ�д����ȡ��ע��
	m_net->disableAll(this);
#endif

// ��ҵ��㴦��ùرղ���
	m_pNetReactor->getTaskQueue().put(boost::bind(&Link::onLogicClose, this));
}

void Link::erase()
{
	LinkPool &linkPool = m_net->getLinkPool();
	linkPool.free(this);
}

void Link::onLogicClose()
{
	m_pNetReactor->onDisconnect(this, m_localAddr, m_peerAddr);
	m_net->delFd(this);
}

void Link::onSend()
{
	if (!isopen()) {
		return;
	}

	// LOG_INFO << "Link::onSend, socket = " << m_sockfd;
	{
		lock_guard_t<> lock(m_sendBufLock);
		if(m_sendBuf.empty()) {
			// LOG_ERROR << m_pNetReactor->name() << " m_sendBuf.empty(), m_isWaitingWrite = " << m_isWaitingWrite;
			return;
		}
	}

	// 1. �����ͻ�����������ȫ��ȡ��
	Buffer buf;

	{
		lock_guard_t<> lock(m_sendBufLock);
		buf.swap(m_sendBuf);

		m_isWaitingWrite = false;
	}

	// 2. ���Է������ݣ�������δ��ȫ�����ͣ���ע��д�¼�
	int left = trySend(buf);
	if (left < 0) {
		// �������쳣����ر�����
		// LOG_ERROR << m_pNetReactor->name() << " = socket<" << m_sockfd << "> trySend fail, ret = " << left;
		m_error = true;
		this ->close();
		return;
	} else if (left > 0) {
		// ������δ��ȫ�����ͣ��򽫲����������¿��������ͻ�������ͷ���Ա�����ȷ�ķ���˳��
		// LOG_ERROR << m_pNetReactor->name() << " register write, socket = " << m_sockfd;
		{
			lock_guard_t<> lock(m_sendBufLock);
			if (!m_sendBuf.empty()) {
				buf.append(m_sendBuf.peek(), m_sendBuf.readableBytes());
				m_sendBuf.swap(buf);
			} else {
				m_sendBuf.swap(buf);
			}

			m_isWaitingWrite = true;
			// LOG_INFO << m_pNetReactor->name() << " register write, m_sendBuf.readableBytes() = " << m_sendBuf.readableBytes();
		}
		// LOG_WARN << "m_net->enableWrite <" << m_sockfd << ">";
	} else {
		// ���������ѷ��ͳɹ�
		// ����������鱾�����Ƿ���<���ر�>���ǵĻ���������������ȫ�����ͳɹ����ڴ��ڼ�û���µ����ݵȴ����ͣ���ִ��close����
		bool isWaitingClose = false;
		{
			lock_guard_t<> lock(m_sendBufLock);
			isWaitingClose = (m_isWaitingClose && m_sendBuf.empty());

			if (!m_sendBuf.empty() && !m_isWaitingWrite) {
				LOG_ERROR << m_pNetReactor->name() << " m_sendBuf.readableBytes() = " << m_sendBuf.readableBytes()
				          << "&& m_isWaitingWrite = " << m_isWaitingWrite << ", m_isWaitingClose = " << m_isWaitingClose;
			}
		}

		if(isWaitingClose) {
			// LOG_ERROR << m_pNetReactor->name() << "isWaitingClose = true m_sendBuf.readableBytes() = " << m_sendBuf.readableBytes() << " && m_isWaitingWrite = " << m_isWaitingWrite;
			close();
		}
	}
}

void Link::sendBuffer()
{
	if (!isopen()) {
		return;
	}

	{
		lock_guard_t<> lock(m_sendBufLock);
		if (m_isWaitingWrite) {
			return;
		}

		if (m_sendBuf.empty()) {
			// LOG_ERROR << m_pNetReactor->name() << " m_sendBuf.empty(), socket = " << m_sockfd;
			return;
		}

		m_isWaitingWrite = true;
	}

	// m_net->interruptLoop();
	m_net->getTaskQueue()->put(boost::bind(&Link::onSend, this));
}

void Link::send(const char *data, int len)
{
	if (!isopen()) {
		return;
	}

	{
		lock_guard_t<> lock(m_sendBufLock);
		m_sendBuf.append(data, len);

		if (m_isWaitingWrite) {
			return;
		}
	}

	this->sendBuffer();
}

void Link::send(const char *text)
{
	send(text, strlen(text));
}

void Link::send(int msgId, Message & msg)
{
	if (!isopen()) {
		return;
	}

	int size = msg.ByteSize();

	NetMsgHead msgHead = {0, 0};
	msgtool::buildNetHeader(&msgHead, msgId, size);

	msg.SerializeToArray(m_net->g_sendBuf, size);

	{
		lock_guard_t<> lock(m_sendBufLock);
		m_sendBuf.append((const char*)&msgHead, sizeof(msgHead));
		m_sendBuf.append(m_net->g_sendBuf, size);

		if (m_isWaitingWrite) {
			return;
		}
	}

	this->sendBuffer();
}

void Link::send(int msgId, const char *data, int len)
{
	if (!isopen()) {
		return;
	}

	NetMsgHead *msgHead = (NetMsgHead*)m_net->g_sendBuf;
	msgtool::buildNetHeader(msgHead, msgId, len);

	{
		lock_guard_t<> lock(m_sendBufLock);
		m_sendBuf.append(m_net->g_sendBuf, sizeof(msgHead));
		m_sendBuf.append(data, len);

		if (m_isWaitingWrite) {
			return;
		}
	}

	this->sendBuffer();
}

void Link::handleRead()
{
	// LOG_WARN << "socket<" << m_sockfd << "> read task";
	if (!isopen()) {
		return;
	}

	// ѭ����������ֱ���޷��ٽ���
	int nread = 0;
	do {
		nread = ::recv(m_sockfd, m_net->g_recvBuf, MAX_PACKET_LEN, NULL);
		if (nread > 0) {
			// ���ɹ����յ����ݣ��򽫱��ν��յ������ݿ��������ջ�����ĩβ
			{
				lock_guard_t<> lock(m_recvBufLock);
				m_recvBuf.append(m_net->g_recvBuf, nread);
			}

			// �����ν������ݳ��Ȳ�δ���������ճ��ȣ���˵��Ŀǰ�������ϵ�������ȫ���������
			if (nread < MAX_PACKET_LEN) {
				break; // �൱��EWOULDBLOCK
			}
		} else if (0 == nread) { // eof
			// �����յ�0�ֽڵ����ݣ���˵���Ѽ�⵽�Զ˹رգ���ʱֱ�ӹرձ����ӣ����ٴ���δ���͵�����

			// LOG_WARN << "socket<" << m_sockfd << "> read 0, closed! buffer len = " << MAX_PACKET_LEN;
			this->close();
			return;
		} else {
			// �����쳣��EAGAIN��EWOULDBLOCK�ź�˵���ѽ�����ϣ�EINTR�ź�Ӧ���ԣ������ź�˵�������ӷ�������
			int err = socktool::geterrno();
			if(EINTR == err) {
				// LOG_WARN << "socket<" << m_sockfd << "> error = EINTR " << err;
				continue;
			} else if(EAGAIN == err || EWOULDBLOCK == err) {
				// LOG_WARN << "read task socket<" << m_sockfd << "> EWOULDBLOCK || EAGAIN, err = " << err;
				break;
			} else {
				// LOG_SOCKET_ERR(m_sockfd, err) << m_pNetReactor->name() << " recv fail, err = " << err << ", history recv buf size = " << m_recvBuf.readableBytes();
				m_error = true;
				this->close();
				return;
			}
		}
	} while(true);

	//m_pNetReactor->getTaskQueue().put(boost::bind(&INetReactor::onRecv, m_pNetReactor, this, m_recvBuf));

	// ���ҵ����Ƿ��Ѵ��ڴ������ӽ������ݵ����������������ٴ�֪ͨҵ��㣬��֮ǰ�����ݴ�������һ�������ν��յ�����������
	{
		lock_guard_t<> lock(m_recvBufLock);
		if (m_isWaitingRead) {
			return;
		}

		m_isWaitingRead = true;
	}

	// ��ҵ���������ݽ��մ���
	m_pNetReactor->onRecv(this, m_recvBuf);
}

void Link::handleWrite()
{
	// LOG_INFO << m_pNetReactor->name() << " socket <" << m_sockfd << "> is writable";
	if (!isopen()) {
		return;
	}

#ifdef WIN
	// windows��selectģ������LT����Ҫ���ο�д�¼�
	m_net->disableWrite(this);
#endif

	onSend();
	return;
}

void Link::handleError()
{
	if (m_error || m_isWaitingClose || !isopen()) {
		return;
	}

	// int err = socktool::getSocketError(m_sockfd);
	// LOG_SOCKET_ERR(m_sockfd, err) << m_pNetReactor->name() << " socket<" << m_sockfd << "> error";

	m_error = true;
	this->close();
	return;
}

int Link::trySend(Buffer &buffer)
{
	size_t nleft = buffer.readableBytes();
	int nwritten = 0;

	// ѭ����������ֱ���޷��ٷ���
	while(nleft > 0) {
		nwritten = ::send(m_sockfd, buffer.peek(), nleft, MSG_NOSIGNAL);
		if (nwritten > 0) {
			nleft  -= nwritten;
			buffer.skip(nwritten);
		} else if(SOCKET_ERROR == nwritten) {
			int err = socktool::geterrno();
			switch(err) {
			case EINTR:
				// ����(������˵������socket����send���������ᴥ��EINTR�źţ������Է���һ)
				break;

			case EAGAIN:
#ifdef WIN
			case EWOULDBLOCK:
#endif
				// ˵�����޷��ٷ��ͣ��жϷ���
				return nleft;

			default:
				// LOG_SOCKET_ERR(m_sockfd, err) << m_pNetReactor->name() << "  send fail, err = " << err << ",nleft = " << nleft << ", nwritten = " << nwritten;
				return -1;
			}
		}
	}

	return nleft;
}

NetAddress Link::getLocalAddr() const
{
	return NetAddress(socktool::getLocalAddr(m_sockfd));
}

NetAddress Link::getPeerAddr() const
{
	return NetAddress(socktool::getPeerAddr(m_sockfd));
}
