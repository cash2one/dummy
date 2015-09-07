///<------------------------------------------------------------------------------
//< @file:   src\gateserver\net\clientmgr.h
//< @author: ������
//< @date:   2015��3��14�� 20:14:21
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _clientmgr_h_
#define _clientmgr_h_

#include <net/netreactor.h>
#include <net/msgdispatcher.h>
#include <net/client.h>
#include <basic/objectpool.h>

class Client;

// �ͻ��˹������ģ�����ǰ���ߵĿͻ�������ʵ��
class ClientMgr : public INetReactor
{
private:
	typedef std::tr1::unordered_map<uint32, Client*> ClientMap;

public:
	ClientMgr();
	~ClientMgr();

	void close();

public:
	virtual std::string name() { return "clientmgr"; }

	virtual void onAccepted(Link*, const NetAddress& localAddr, const NetAddress& peerAddr);

	virtual void onDisconnect(Link*, const NetAddress& localAddr, const NetAddress& peerAddr);

	virtual void onRecv(Link*, Buffer&);

	virtual TaskQueue& getTaskQueue() { return *m_taskQueue; }

	void delClient(Client*);

	int getClientCount() { return m_clientMap.size(); }

private:
	uint32 allocClientId();

public:
	TaskQueue *m_taskQueue;

	uint32 m_allocClientId;

	// ��ǰ���ߵĿͻ����б�
	ClientMap m_clientMap;

	// �ͻ�����Ϣ�ɷ������ɷ��ͻ��˷�������Ϣ
	MsgDispatcher<Client> m_dispatcher;

	// �ͻ��˳�
	ObjectPool<Client> m_clientPool;
};

#endif //_clientmgr_h_