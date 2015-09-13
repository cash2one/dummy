///<------------------------------------------------------------------------------
//< @file:   src\robot\robot.cpp
//< @author: ������
//< @date:   2015��3��16�� 11:43:14
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "robot.h"

#include <net/netaddress.h>
#include <net/link.h>
#include <client.pb.h>
#include <protocol/message.h>
#include <tool/encrypttool.h>
#include <protocol.pb.h>
#include "robotmgr.h"

#include "http/handshakehttpcmd.h"
#include <tool/randtool.h>
#include <tool/echotool.h>
#include <tool/ticktool.h>

#include <protocol.pb.h>
#include <client.pb.h>

Robot::Robot()
	: m_link(NULL)
	, m_robotMgr(NULL)
	, m_isEncrypt(false)
	, m_robotId(0)
	, m_cliversion(110)
	, m_pingpongCount(0)
{
	bzero(m_encryptKey, sizeof(m_encryptKey));

	randomRobot();
}

Robot::~Robot()
{
	// LOG_WARN << "robot ~robot";
}

std::string Robot::name()
{
	return echotool::getmsg("robot<%d>", m_robotId);
}

void Robot::randomRobot()
{
	uint8 randNum[64] = {0};

	m_cliversion = randtool::random(1, 1200);

	randtool::secureRandom(randNum, sizeof(randNum) - 1, 65, 97);
	m_deviceid = std::string("deviceid_") + (const char*)randNum;
	m_username = std::string("username_") + (const char*)randNum;
	m_password = std::string("password_") + (const char*)randNum;
	m_ip = std::string("127.0.0.") + echotool::getmsg("%u", randtool::random(1, 254));
}


void Robot::onConnected(Link *link, const NetAddress& localAddr, const NetAddress& peerAddr)
{
	static int g_connectedRobotCnt = 0;
	++g_connectedRobotCnt;

	m_link = link;

	if (g_connectedRobotCnt % 100 == 0) {
		LOG_INFO << name() << " <" << localAddr.toIpPort() << "> connect to <" << peerAddr.toIpPort() << "> success, current robot cnt = " << g_connectedRobotCnt;
	}

	// m_link->send("1\r\n");
}

void Robot::onDisconnect(Link *link, const NetAddress& localAddr, const NetAddress& peerAddr)
{
	/*
	if (link->m_isCreateByConnector) {
		Robot *robot = m_robotMgr->createRobot();
		m_robotMgr->m_wan.connect(peerAddr.toIp(), peerAddr.toPort(), *robot);
	}
	*/

	if (m_robotMgr->m_robotMap.size() - 1 % 100 == 0) {
		LOG_INFO << "robot<" << m_robotId << "> <" << localAddr.toIpPort() << "> to gateserver <" << peerAddr.toIpPort() << "> closed! current robot cnt = " << m_robotMgr->m_robotMap.size() - 1;
	}

	m_robotMgr->onRobotDisconnect(this);
}

void Robot::onRecv(Link *link, Buffer &buf)
{
	// ֱ�ӱ��ؽ��д���
	m_robotMgr->m_taskQueue.put(boost::bind(&Robot::handleMsg, this));
}

void Robot::handleMsg()
{
	Link *link = m_link;
	Buffer buf;

	{
		lock_guard_t<> lock(link->m_recvBufLock);
		link->m_isWaitingRead = false;
		buf.swap(link->m_recvBuf);
	}

	while(true) {
		// �����
		size_t bytes = buf.readableBytes();
		if (bytes < sizeof(NetMsgHead)) {
			break;
		}

		NetMsgHead *msgHead = (NetMsgHead*)buf.peek();
		uint16 msgId = endiantool::networkToHost16(msgHead->msgId);
		uint32 msgLen = endiantool::networkToHost32(msgHead->msgLen);

		if (msgLen > bytes) {
			break;
		}

		// δ����
		if (!m_isEncrypt) {
			m_robotMgr->m_dispatcher.dispatch(*this, msgId, buf.peek() + sizeof(NetMsgHead), msgLen - sizeof(NetMsgHead), 0);
			buf.skip(msgLen);
			continue;
		}

		//�Ƚ���
		uint8* encryptBuf =  (uint8*)(buf.peek() + sizeof(NetMsgHead));
		int encryptBufLen = msgLen - sizeof(NetMsgHead);

		if(!encrypttool::decrypt(encryptBuf, encryptBufLen, m_encryptKey, sizeof(m_encryptKey))) {
			LOG_ERROR << "robot [" << link->m_localAddr.toIpPort() << "] <-> gatesvr [" << link->m_peerAddr.toIpPort()
			          << "] receive invalid msg[len=" << encryptBufLen << "]";
			buf.skip(msgLen);
			continue;
		}

		char *msg = (char*)buf.peek() + sizeof(NetMsgHead) + EncryptHeadLen;

		Buffer copyBuf;
		copyBuf.append(msg, msgLen - sizeof(NetMsgHead) - EncryptHeadLen - EncryptTailLen);

		// ֱ�ӱ��ؽ��д���
		m_robotMgr->m_dispatcher.dispatch(*this, msgId, msg, msgLen - sizeof(NetMsgHead) - EncryptHeadLen - EncryptTailLen, 0);
		buf.skip(msgLen);
	}

	if (!buf.empty()) {
		{
			lock_guard_t<> lock(link->m_recvBufLock);
			if (!link->m_recvBuf.empty()) {
				buf.append(link->m_recvBuf.peek(), link->m_recvBuf.readableBytes());
				link->m_recvBuf.swap(buf);
			} else {
				link->m_recvBuf.swap(buf);
			}
		}
	}
}

TaskQueue& Robot::getTaskQueue()
{
	return m_robotMgr->m_taskQueue;
}

bool Robot::send(int msgId, Message &msg)
{
	if (!m_link->isopen()) {
		// LOG_ERROR << "robot<" << m_robotId << "> [" << m_link->m_localAddr.toIpPort() << "] <-> gatesvr [" << m_link->m_peerAddr.toIpPort() << "] is not open";
		return false;
	}

	if (!m_isEncrypt) {
		m_link->send(msgId, msg);
		return true;
	}

	uint32 headSize = sizeof(NetMsgHead);
	int size = msg.ByteSize();

	bool ok = msg.SerializeToArray(global::g_encryptBuf + headSize + EncryptHeadLen, size);
	if (!ok) {
		LOG_ERROR << "robot<" << m_robotId << "> [" << m_link->m_localAddr.toIpPort() << "] <-> gatesvr [" << m_link->m_peerAddr.toIpPort()
		          << "] send msg failed, SerializeToArray error, [len=" << size << "] failed, content = [" << msgtool::getMsgDebugString(msg) << "]";

		return false;
	}

	// ��Ӽӽ���ͷβ
	uint8* decryptBuf = (uint8*)(global::g_encryptBuf + headSize);
	int decryptBufLen = size + EncryptHeadLen + EncryptTailLen;

	encrypttool::encrypt(decryptBuf, decryptBufLen, m_encryptKey, sizeof(m_encryptKey));

	NetMsgHead* pHeader = (NetMsgHead*)global::g_encryptBuf;

	int packetLen = msgtool::buildNetHeader(pHeader, msgId, decryptBufLen);
	if (packetLen <= 0) {
		LOG_ERROR << "robot<" << m_robotId << "> [" << m_link->m_localAddr.toIpPort() << "] <-> gatesvr [" << m_link->m_peerAddr.toIpPort()
		          << "] pakcetLen = " << packetLen;
		return false;
	}

	m_link->send(global::g_encryptBuf, packetLen);

	return true;
}

void Robot::start()
{
	handshake();
}

void Robot::handshake()
{
	HandShakeHttpCmd *handshakeHttpCmd = new HandShakeHttpCmd;
	handshakeHttpCmd->m_robot = this;
	handshakeHttpCmd->init();

	m_robotMgr->m_httpMgr.addCmd(handshakeHttpCmd);
}

void Robot::auth()
{

}

void Robot::login()
{

}

void Robot::pingpongTest()
{
	PingPong p;
	p.set_pingpong("123456789|");
	p.set_time(0);

	LOG_WARN << "robot <" << m_robotId << "> start pingpong test, pingpong packet size = " << p.ByteSize();

	send(ePing, p);
}

void Robot::speedTest()
{
	static int g_speedTestCnt = 0;

	g_speedTestCnt++;

	PingPong p;
	p.set_pingpong("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
	p.set_time(0);

	if (g_speedTestCnt % 100 == 0) {
		LOG_WARN << name() << " start speed test, g_speedTestCnt = " << g_speedTestCnt << ", speed packet size = " << p.ByteSize();
	}

	int count = 1000;
	// 	Tick tick("send() speed test");

	for (int i = 0; i < count; i++) {
		send(eSpeedTest, p);
	}

	// RobotMgr::Instance().stop();
	// 	double costTime = tick.endTick();
	// 	double avgTime = costTime / count;
	// 	double speed = 1.0f / avgTime;
	// 	LOG_WARN << "send packet count = " << count << ", avg cost time = " << avgTime << ", total cost time = " << costTime << ", exe count per second = " << speed;
	// 	exit(0);
}

void Robot::latencyTest()
{
	static int g_latencyTestCnt = 0;

	g_latencyTestCnt++;

	PingPong p;
	p.set_pingpong("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");

	if (g_latencyTestCnt % 100 == 0) {
		LOG_WARN << "robot <" << m_robotId << "> start latency test, g_latencyTestCnt = " << g_latencyTestCnt << ", latency packet size = " << p.ByteSize();
	}

	for (int i = 0; i < 1000; i++) {
		p.set_time(ticktool::tick());
		send(eLatencyTest, p);
	}

	m_link->close();
}