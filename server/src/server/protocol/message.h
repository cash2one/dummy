///<------------------------------------------------------------------------------
//< @file:   server\protocol\message.h
//< @author: ������
//< @date:   2015��3��8�� 15:53:38
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _message_h_
#define _message_h_

namespace google {namespace protobuf { class Message; }}

struct NetMsgHead {
	int msgId;
	int msgLen;
};

namespace msgtool
{
	string getMsgString(google::protobuf::Message &msg);

	// ���������ͷ
	int buildNetHeader(NetMsgHead *pstHead, uint16 msgId, uint32 msgLen);
}

#endif //_message_h_