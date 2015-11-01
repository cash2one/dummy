///<------------------------------------------------------------------------------
//< @file:   server\net\netdefine.h
//< @author: ������
//< @date:   2015��1��28��
//< @brief:	 ��������ͨ�ýӿ�
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _netdefine_h_
#define _netdefine_h_

class Link;
class NetAddress;
class TaskQueue;

// ��������������Ϣ��������С = 128KB
static const int MAX_PACKET_LEN = 128 * 1024;

// �����߼�ʵ�������ڲ��������Ϸ������¼�
class INetLogic
{
public:
	virtual ~INetLogic() {}

	// ��ȡ�������߼�ʵ��������
	virtual std::string name() = 0;

	// �ɹ����������϶Զ�
	virtual void onConnected(Link*, const NetAddress& localAddr, const NetAddress& peerAddr) {}

	// �ɹ����յ��µ�����
	virtual void onAccepted(Link*, const NetAddress& localAddr, const NetAddress& peerAddr) {}

	// �Զ����ӹر�
	virtual void onDisconnect(Link*, const NetAddress& localAddr, const NetAddress& peerAddr) = 0;

	// ���յ��µ�����
	virtual void onRecv(Link*) = 0;

	// ��ȡ��ʵ��������ҵ�����������
	virtual TaskQueue& getTaskQueue() = 0;
};

// �ļ��������ӿ�(file descriptor)������Link��������Listener��������Connector���Ӵ�������
class IFd
{
public:
	virtual ~IFd() {}

	// ����socketֵ
	virtual socket_t socket() const = 0;

	// ����ɶ��ź�
	virtual void handleRead()  = 0;

	// �����д�ź�
	virtual void handleWrite() = 0;

	// �����쳣�ź�
	virtual void handleError() = 0;

	// �ر�
	virtual void close() = 0;

	// ɾ����fd
	virtual void erase() = 0;

#ifndef WIN
public:
	uint32 m_events;
#endif
};

#endif