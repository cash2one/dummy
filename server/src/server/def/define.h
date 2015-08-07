///<------------------------------------------------------------------------------
//< @file:   server\def\define.h
//< @author: ������
//< @date:   2015��4��7�� 20:32:19
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _define_h_
#define _define_h_

#include "basic/objectpool.h"
#include "basic/buffer.h"

#define MAX_PACKET_LEN (1024 * 1024) // 1MB

namespace global
{
// ����
	// Ԥ���������Ϣ���ڴ棺���ڹ�����յ�����Ϣ��
	static char* g_recvPacketBuf = new char[MAX_PACKET_LEN];
	static uint32 g_recvPacketBufSize = MAX_PACKET_LEN;

	// Ԥ���������Ϣ���ڴ�: ���ڹ��췵�ص���Ϣ��
	static char* g_packetBuf = new char[MAX_PACKET_LEN];
	static uint32 g_packetBufSize = MAX_PACKET_LEN;
	static Message *g_lastMessage = NULL;

	// Ԥ��������������ݻ�����: ���ڷ��ͺͽ�������ʱ���мӽ�������
	static char g_netBuf[MAX_PACKET_LEN] = {0};

	//
	static thread_local char g_recvBuf[80 * 1024] = {0};

// ���ݿ�
	static thread_local char g_sql[2048] = {0};

// ʱ��
	static char g_formatBuf[32] = {0};

// ��ӡ
	static thread_local char g_sprintfBuf[4096] = {0};

// ȫ�ֻ�������
	static ObjectPool<Buffer, mutex_t> g_bufferPool;

	void init();
	void uninit();
}

#endif //_define_h_