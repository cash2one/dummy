///<------------------------------------------------------------------------------
//< @file:   server\net\imsghandler.h
//< @author: ������
//< @date:   2015��3��17�� 23:37:25
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _imsghandler_h_
#define _imsghandler_h_

// ��Ϣ������
template <typename LinkType>
class IMsgHandler
{
public:
	virtual ~IMsgHandler() {}

	virtual void onMessage(LinkType& link, int msgId, const char* data, int len, Timestamp receiveTime) const = 0;

	virtual void clear() = 0;
};

#endif //_imsghandler_h_