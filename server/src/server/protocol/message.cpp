///<------------------------------------------------------------------------------
//< @file:   server\protocol\message.cpp
//< @author: ������
//< @date:   2015��3��9�� 12:22:32
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "message.h"

#include <google/protobuf/message.h>
#include "tool/endiantool.h"

namespace msgtool
{
	string getMsgString(const google::protobuf::Message &msg)
	{
		string text = msg.GetDescriptor()->DebugString();
		text += "\nvalue = {\n" + msg.DebugString() + "}";

		return text;
	}

	// ���������ͷ
	int buildNetHeader(NetMsgHead *pstHead, uint16 msgId, uint32 msgLen)
	{
		uint32 packetLen = msgLen + sizeof(NetMsgHead);

		pstHead->msgId	= endiantool::hostToNetwork16(msgId);
		pstHead->msgLen	= endiantool::hostToNetwork32(packetLen);

		return packetLen;
	}
}
