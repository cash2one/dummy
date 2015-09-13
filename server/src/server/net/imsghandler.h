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
// ������֮������ȡ��IMsgHandler�ӿ���Ϊ�˷�ֹģ���ļ�����������±��벻����
template <typename LinkType>
class IMsgHandler
{
public:
	virtual ~IMsgHandler() {}

	virtual void clear() = 0;
};

#endif //_imsghandler_h_