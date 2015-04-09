///<------------------------------------------------------------------------------
//< @file:   logic\http\pushplayerinfohttpcmd.h
//< @author: hongkunan
//< @date:   2014��4��1�� 9:28:43
//< @brief:  �����µ������Ϣ<�ȼ����ǳơ�ְҵ>���͵��û�����
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pushplayerinfohttpcmd_h_
#define _pushplayerinfohttpcmd_h_

#include "basehttpcmd.h"

struct SPlayerBaseInfo
{
    SPlayerBaseInfo()
        : dwPlayerID(0)
        , wLevel(0)
        , wCoachHeroID(0)
		, byVipLv(0)
		, byAuthType(0)
    {
        dwPlayerID = 0;
    }

    UINT32 dwPlayerID;  // ���ID
    UINT16 wLevel;      // ����ҵ�ǰ�ȼ�
    UINT16 wCoachHeroID;        // ����ҵ�ǰְҵ
	UINT8  byVipLv;		// ���vip�ȼ�
	UINT8 byAuthType; 
    string strNickName; // ����ҵ�ǰ�ǳ�
};

// �����µ������Ϣ<�ȼ����ǳơ�ְҵ>���͵��û�����
class CPushPlayerInfoHttpCMD : public CBaseHttpCMD
{
public:
    CPushPlayerInfoHttpCMD();
    ~CPushPlayerInfoHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_PUSH_PLAYER_INFO;
    }

    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);

private:
    void EscapeFields();
    void EscapeUrl(CHAR szUrl[], UINT16 wLen);

private:
    SPlayerBaseInfo m_stPlayerInfo;
};

#endif //_pushplayerinfohttpcmd_h_