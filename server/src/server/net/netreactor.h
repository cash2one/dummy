///<------------------------------------------------------------------------------
//< @file:   server\net\netreactor.h
//< @author: ������
//< @date:   2015��1��28�� 15:36:14
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _netreactor_h_
#define _netreactor_h_

class Link;
class NetAddress;
class Buffer;
class TaskQueue;

// �����߼�ʵ�������ڲ��������Ϸ������¼�
class INetReactor
{
public:
	// ��ȡ�������߼�ʵ��������
	virtual std::string name() = 0;

	// �ɹ����������϶Զ�
	virtual void onConnected(Link*, const NetAddress& localAddr, const NetAddress& peerAddr) {}

	// �ɹ����յ��µ�����
	virtual void onAccepted(Link*, const NetAddress& localAddr, const NetAddress& peerAddr) {}

	// �Զ����ӹر�
	virtual void onDisconnect(Link*, const NetAddress& localAddr, const NetAddress& peerAddr) = 0;

	// ���յ��µ�����
	virtual void onRecv(Link*, Buffer&) = 0;

	// ��ȡ��ʵ��������ҵ�����������
	virtual TaskQueue& getTaskQueue() = 0;
};

#endif //_netreactor_h_