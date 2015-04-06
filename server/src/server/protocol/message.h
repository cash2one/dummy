///<------------------------------------------------------------------------------
//< @file:   server\protocol\message.h
//< @author: ������
//< @date:   2015��3��8�� 15:53:38
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _message_h_
#define _message_h_

#include <google/protobuf/message.h>

typedef google::protobuf::Message Message;

// namespace google {namespace protobuf { class Message; }}

struct NetMsgHead {
	uint16 msgId;
	uint32 msgLen;
};

#define MAX_PACKET_LEN (1024 * 1024)

namespace msgtool
{
	string getMsgString(const google::protobuf::Message &msg);

	// ���������ͷ
	int buildNetHeader(NetMsgHead *pstHead, uint16 msgId, uint32 msgLen);

	// ������1MB�ڴ�
	extern char* g_packetBuf;
	extern int g_packetBufSize;
	extern ::google::protobuf::Message *g_lastMessage;

	// ��Ԥ�ȷ���õ��ڴ�������һ��Message
	template<typename T>
	T* allocPacket()
	{
		if (g_packetBufSize < sizeof(T)) {
			delete[] g_packetBuf;
			g_packetBuf = new char[MAX_PACKET_LEN];
			g_packetBufSize = sizeof(T);
		}

		if (g_lastMessage) {
			g_lastMessage->~Message();
		}

		T* t = new ((T*)g_packetBuf)T();
		g_lastMessage = t;
		return t;
	}

	template<typename T>
	void freePacket(T *obj)
	{
		obj->~T();
	}
}

#endif //_message_h_