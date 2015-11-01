///<------------------------------------------------------------------------------
//< @file:   server\def\global.h
//< @author: ������
//< @date:   2015��4��7�� 20:32:19
//< @brief:	 ά��ȫ�ֶ���ı�������ȫ��������ڴ�ռ�
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _global_h_
#define _global_h_

#include "basic/objectpool.h"
#include "basic/buffer.h"

namespace global
{
// ����
	// Ԥ���������Ϣ���ڴ棺���ڹ�����յ�����Ϣ��
	extern char* g_recvPacketBuf;
	extern uint32 g_recvPacketBufSize;

	// Ԥ���������Ϣ���ڴ�: ���ڹ��췵�ص���Ϣ��
	extern char* g_packetBuf;
	extern uint32 g_packetBufSize;
	extern Message *g_lastMessage;

// ���ݿ�
	extern char g_sql[2048];

// ʱ��
	extern char g_formatBuf[32];

// ��ӡ
	extern char g_sprintfBuf[4096];

	// ȫ�ֳ�ʼ��
	void init();

	// ȫ�ֻ�����Դ
	void uninit();
}

#endif //_define_h_