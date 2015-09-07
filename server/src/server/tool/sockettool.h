///<------------------------------------------------------------------------------
//< @file:   server\tool\sockettool.h
//< @author: ������
//< @date:   2014��11��25�� 14:4:34
//< @brief:  ����socket
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _sockettool_h_
#define _sockettool_h_

#include "net/net.h"

class NetAddress;

namespace socktool
{
	// �����µ�socket
	socket_t createSocket();

	// �ر�socket
	void closeSocket(socket_t);

	// ����socketΪ������
	bool setNonBlocking(socket_t);

	// �ر�Nagle�㷨
	bool setTcpNoDelay(socket_t);

	// ���ö˿����ã�ʹ�ô���TIME_WAIT״̬�µ�socket�����ظ���ʹ��
	// (һ����˵��һ���˿��ͷź��ȴ������ӣ���TIME_WAIT״̬��ʱ�䣩֮������ٱ�ʹ�ã�SO_REUSEADDR���ö˿��ͷź������Ϳ��Ա��ٴ�ʹ�ã�������ʾ"��ַ����ʹ����"
	// ����˳���Ӧ�õ���bind()֮ǰ����SO_REUSEADDR�׽���ѡ�TCP���ȵ���close()��һ�������TIME_WAIT״̬)
	void setReuseAddr(socket_t, bool on);

	// ���������ָ������û���κ���������,�����̽��
	void setKeepAlive(socket_t, bool on, int keepAliveTime);

	// windows��Ĭ�Ϸ��ͻ�������С = 8192��linux��Ĭ�Ϸ��ͻ�������С = 171480
	void setSendBufSize(socket_t, int size);

	// windows��Ĭ�Ͻ��ջ�������С = 8192��linux��Ĭ�Ͻ��ջ�������С = 87380
	void setRecvBufSize(socket_t, int size);

	// �����ӳٹر�socket��ʱ�䣬�ȴ��׽��ַ��ͻ������е����ݷ�����ɣ����ã���Ҫ�������ѡ���ý��ҵ��ͳ������д���
	void setLinger(socket_t, int waitTime);

	// ��ȡsocket�Ĵ����벢�ô�����Ϊ0
	int getSocketError(socket_t sockfd);

	// ��ӡ������Ŷ�Ӧ�Ĵ����ı�
	const char* getErrorMsg(int err);

	// ��ȡϵͳ����Ĵ����
	int geterrno();

	// ���ϵͳ����Ĵ����
	void clearerrno();

	// ��ȡ���˵�ַ
	struct sockaddr_in getLocalAddr(int sockfd);

	// ��ȡ�Զ˵�ַ
	struct sockaddr_in getPeerAddr(int sockfd);

	// Ϊ�׽�������������bind()����֮��Ϊsocket()�����������׽��ֹ���һ����Ӧ��ַ�����͵������ַ�����ݿ���ͨ�����׽��ֶ�ȡ��ʹ�á�
	bool bindAddress(socket_t sockfd, const NetAddress& localaddr);

	// ����socket
	bool listen(socket_t);
}

#endif //_sockettool_h_