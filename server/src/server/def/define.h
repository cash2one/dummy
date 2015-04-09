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

#define MAX_PACKET_LEN (1024 * 1024)

namespace global
{
// ������Ϣ����
	// Ԥ���������Ϣ���ڴ�
	static char* g_packetBuf = new char[MAX_PACKET_LEN];
	static uint32 g_packetBufSize = MAX_PACKET_LEN;
	static Message *g_lastMessage = NULL;

// ���ݿ�
	static thread_local char g_sql[2048] = {0};
	static thread_local char g_recvBuf[80960] = {0};

// ʱ��
	static char g_formatBuf[32] = {0};

// ��ӡ
	static thread_local char g_sprintfBuf[4096] = {0};

// ȫ�ֻ�������
	static ObjectPool<Buffer> g_bufferPool;

	void init();
	void uninit();
}

#endif //_define_h_