///<------------------------------------------------------------------------------
//< @file:   gsprocessor.h
//< @author: hongkunan
//< @date:   2014��1��2�� 21:9:41
//< @brief:  gameserver��Ϣ������������������gameserver����������Ϣ��
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gsprocessor_h_
#define _gsprocessor_h_

#include "sdframework.h"
#include "protocol/server/protogtgs.h"

using namespace std;

// gameserver��Ϣ������������gameserver����Ϣ�����ɱ�����������
class CGSProcessor :public CSDPacketProcessor
{
public:
    static CGSProcessor* Instance()
    {
        static CGSProcessor oProcessor;
        return &oProcessor;
    }

    ///<@impl>
    virtual BOOL Init();

    ///<@impl>
    virtual CSDProtocol* GetProtocol();
};

#endif //_gsprocessor_h_