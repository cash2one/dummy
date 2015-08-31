///<------------------------------------------------------------------------------
//< @file:   gateserver\net\client.h
//< @author: ������
//< @date:   2015��3��14�� 20:29:53
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _client_h_
#define _client_h_

#include <net/netreactor.h>
#include <client.pb.h>

class Link;
class ClientMgr;

class Client : public INetReactor
{
public:
	Client();

public:
	std::string name();

	// @override
	virtual void onDisconnect(Link*, const NetAddress& localAddr, const NetAddress& peerAddr);

	virtual void onRecv(Link*, Buffer&);

	virtual TaskQueue& getTaskQueue() { return *m_taskQueue; }

public:
	void onEstablish();

	bool send(int msgId, Message&);

	void close();

	void handleMsg();

	bool needRoute(int msgId);

public:
	Link *m_link;
	uint32 m_clientId;

	TaskQueue *m_taskQueue;
	ClientMgr *m_clientMgr;

	uint8 m_encryptKey[EncryptKeyLen];

	uint8 m_authKey[AuthKeyLen];

public:
	int m_pingCount;
	int m_speedTestCount;
	int m_latencyTestCount;
};

#endif //_client_h_