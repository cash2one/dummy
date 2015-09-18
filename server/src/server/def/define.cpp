///<------------------------------------------------------------------------------
//< @file:   server\def\define.cpp
//< @author: ������
//< @date:   2015��4��7�� 20:34:48
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "define.h"

#include <google/protobuf/message.h>

#include "tool/randtool.h"
#include "protocol/message.h"

namespace global
{
	// ����
	// Ԥ���������Ϣ���ڴ棺���ڹ�����յ�����Ϣ��
	char* g_recvPacketBuf = new char[MAX_PACKET_LEN];
	uint32 g_recvPacketBufSize = MAX_PACKET_LEN;

	// Ԥ���������Ϣ���ڴ�: ���ڹ��췵�ص���Ϣ��
	char* g_packetBuf = new char[MAX_PACKET_LEN];
	uint32 g_packetBufSize = MAX_PACKET_LEN;
	Message *g_lastMessage = NULL;

	// ���ݿ�
	char g_sql[2048] = {0};

	// ʱ��
	char g_formatBuf[32] = {0};

	// ��ӡ
	char g_sprintfBuf[4096] = {0};

	// ȫ�ֻ�������
	// ObjectPool<Buffer, mutex_t> g_bufferPool;
}

namespace global
{
	bool g_inited = false;

	void init()
	{
		if (g_inited) {
			return;
		}

		g_inited = true;
		// g_bufferPool.init(1000, 500);

		randtool::initSeed();
	}

	void uninit()
	{
		delete[] g_recvPacketBuf;

		msgtool::freePacket(global::g_lastMessage);
		delete[] g_packetBuf;

		google::protobuf::ShutdownProtobufLibrary();
		logging::uninit();
		// g_bufferPool.clear();
	}
}