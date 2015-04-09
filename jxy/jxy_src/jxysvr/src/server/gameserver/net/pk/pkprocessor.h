///<------------------------------------------------------------------------------
//< @file:   pkprocessor.h
//< @author: hongkunan
//< @date:   2014��1��3�� 13:54:25
//< @brief:  gameserver�Ŀ��ս��������Ϣ����������������ս����������������Ϣ��
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pkprocessor_h_
#define _pkprocessor_h_

#include "sdframework.h"

typedef struct tagDT_SYNC_PLAYER DT_SYNC_PLAYER;

namespace SGDP { 
    class CSDProtocol;
}

// gameserver�Ŀ��ս��������Ϣ��������
class CPKProcessor : public CSDPacketProcessor
{
public:
    static CPKProcessor* Instance()
    {
        static CPKProcessor oProcessor;
        return &oProcessor;
    }

    CPKProcessor();
    ~CPKProcessor();

    ///<@impl>
    virtual BOOL Init();

    ///<@impl>
    virtual CSDProtocol* GetProtocol();

protected:
    static BOOL OnGvGNextRoundNotify(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnGetTopFactions(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnRetTopFactions(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnGetFactions(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnRetFactions(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnGetPlayerReq(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnRetPlayerAck(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);    
    
    static BOOL OnGetVideo(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnRetVideo(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnSyncVideo(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnSyncGvG(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnSupportFaction(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnRecvFactionSupportList(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnAskGvGReady(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnRecvGvGReadyReply(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnGetGvGActivityDataReq(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

private:
    static BOOL TakePlayer(UINT32 dwPlayerID, DT_SYNC_PLAYER &stSyncPlayer, UINT32 dwPKGroupID);
};

#endif //_pkprocessor_h_