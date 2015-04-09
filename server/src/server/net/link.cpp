///<------------------------------------------------------------------------------
//< @file:   server\net\link.cpp
//< @author: 洪坤安
//< @date:   2015年1月14日 23:7:5
//< @brief:
//< Copyright (c) 2015 服务器. All rights reserved.
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

void Link::open()
{
	socktool::setNonBlocking(m_sockfd);
	socktool::setTcpNoDelay(m_sockfd);

	m_net->addFd(this);
}

void Link::enableRead()
{
	m_net->enableRead(this);
}

void Link::close()
{
	// LOG_INFO << "Link::close, socket = " << m_sockfd;

	if (m_isClosing) {
		return;
	}

	m_isClosing = true;

	socktool::closeSocket(m_sockfd);
	m_net->disableAll(this);

	// LOG_WARN << "close socket<" << m_sockfd << ">";
	m_pNetReactor->getTaskQueue().put(task_binder_t::gen(&Link::onLogicClose, this));
}

void Link::erase()
{
	LinkPool &linkPool = m_net->getLinkPool();
	linkPool.free(this);
}

void Link::onLogicClose()
{
	// LOG_INFO << "Link::onLogicClose, socket = " << m_sockfd;

	m_pNetReactor->onDisconnect(this, m_localAddr, m_peerAddr);

#ifdef WIN
	m_net->getTaskQueue()->put(task_binder_t::gen(&Link::onNetClose, this));
#else
	m_taskQueue->produce(task_binder_t::gen(&Link::onNetClose, this));
#endif
}

void Link::onNetClose()
{
	// LOG_INFO << "Link::onNetClose, socket = " << m_sockfd;

	m_net->delFd(this);
}

void Link::onSend(Buffer &buf)
{
	if (!isopen()) {
		return;
	}

	// LOG_INFO << "Link::onSend, socket = " << m_sockfd;

	// 如果发送缓存区仍有数据未发送，则直接append
	if (m_sendBuf.readableBytes() > 0) {
		// LOG_WARN << "socket<" << m_sockfd << "> m_sendBuf.append(buf.peek(), buf.readableBytes());";
		m_sendBuf.append(buf.peek(), buf.readableBytes());
		return;
	}

	int ret = trySend(buf);

	if (ret < 0) {
		this ->close();
	}
	else if (ret > 0) {
		// LOG_WARN << "m_net->enableWrite <" << m_sockfd << ">";

		m_net->enableWrite(this);
		m_sendBuf.append(buf.peek(), buf.readableBytes());
	}
	else {
		// 发送成功
	}
}

void Link::sendBuffer(Buffer &buf)
{
	if (!isopen()) {
		return;
	}

#ifdef WIN
	m_net->getTaskQueue()->put(task_binder_t::gen(&Link::onSend, this, buf));
#else
	m_taskQueue->produce(task_binder_t::gen(&Link::onSend, this, buf));
#endif
}

void Link::send(const char *data, int len)
{
	if (!isopen()) {
		return;
	}

	Buffer buf(len);
	buf.append(data, len);
	sendBuffer(buf);
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

	Buffer buf;
	buf.append((const char*)&msgHead, sizeof(msgHead));

	msg.SerializeToArray((void*)buf.beginWrite(), size);
	buf.hasWritten(size);

	this->sendBuffer(buf);
}

void Link::send(int msgId, const char *data, int len)
{
	if (!isopen()) {
		return;
	}

	NetMsgHead msgHead = {0, 0};
	msgtool::buildNetHeader(&msgHead, msgId, len);

	Buffer buf(msgHead.msgLen);
	buf.append((const char*)&msgHead, sizeof(msgHead));
	buf.append(data, len);

	this->sendBuffer(buf);
}

int Link::handleRead()
{
#ifdef WIN32
	handleReadTask();
#else
	m_taskQueue->produce(task_binder_t::gen(&Link::handleReadTask, this));
#endif

	return 0;
}

int Link::handleWrite()
{
#ifdef WIN32
	handleWriteTask();
#else
	m_taskQueue->produce(task_binder_t::gen(&Link::handleWriteTask, this));
#endif

	return 0;
}

int Link::handleError()
{
	// LOG_WARN << "socket<" << m_sockfd << "> error";
	this->close();
	return 0;
}

int Link::handleReadTask()
{
	// LOG_WARN << "socket<" << m_sockfd << "> read task";

	if (!isopen()) {
		return 0;
	}

	int nread = 0;
	do {
		nread = ::recv(m_sockfd, global::g_recvBuf, sizeof(global::g_recvBuf) - 1, NULL);
		if (nread > 0) {
			m_recvBuf.append(global::g_recvBuf, nread);

			// LOG_WARN << "read task socket<" << m_sockfd << "> recv nread = " << nread;

			if (nread < int(sizeof(global::g_recvBuf) - 1)) {
				break; // 相当于EWOULDBLOCK
			}
		}
		else if (0 == nread) {   //! eof
			// LOG_WARN << "socket<" << m_sockfd << "> read 0, closed";
			this->close();
			return -1;
		}
		else {
			int err = socktool::geterrno();
			if (err == EINTR) {
				continue;
			}
			else if (err == EWOULDBLOCK || err == EAGAIN) {
				// LOG_WARN << "read task socket<" << m_sockfd << "> EWOULDBLOCK || EAGAIN, err = " << err;

				break;
			}
			else {
				// LOG_WARN << "socket<" << m_sockfd << "> error = " << err;
				this->close();
				return -1;
			}
		}
	}
	while(true);

	m_pNetReactor->onRecv(this, m_recvBuf);
	return 0;
}

int Link::handleWriteTask()
{
	// LOG_INFO << "socket <" << m_sockfd << "> is writable";
	if (!isopen()) {
		return 0;
	}

	int ret = 0;
	string left_buff;

#ifdef WIN
	// windows下select模型属于LT，需要屏蔽可写事件
	m_net->disableWrite(this);
#endif

	if (m_sendBuf.empty()) {
		return 0;
	}

	do {
		ret = trySend(m_sendBuf);

		if (ret < 0) {
			// LOG_WARN << "close socket<" << m_sockfd << ">";
			this->close();
			return -1;
		}
	}
	while (m_sendBuf.readableBytes() > 0);
	return 0;
}

int Link::trySend(Buffer &buffer)
{
	size_t nleft     = buffer.readableBytes();
	const char* buff = buffer.peek();

	int nwritten = 0;

	while(nleft > 0) {
		if((nwritten = ::send(m_sockfd, buff, nleft, MSG_NOSIGNAL)) <= 0) {
			int err = socktool::geterrno();
			if (EINTR == err) {
				nwritten = 0;
			}
			else if (EWOULDBLOCK == err || EAGAIN == err) {
				break;
			}
			else {
				// LOG_SYSTEM_ERR << "close socket<" << m_sockfd << ">";
				return -1;
			}
		}

		nleft  -= nwritten;
		buff   += nwritten;

		buffer.retrieve(nwritten);
	}

	return nleft;
}

NetAddress Link::getLocalAddr()
{
	return NetAddress(socktool::getLocalAddr(m_sockfd));
}
