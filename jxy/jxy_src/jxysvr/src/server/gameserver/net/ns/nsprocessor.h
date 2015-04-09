#ifndef __NS_PACKETPROCESSOR_INCLUDE_H_
#define __NS_PACKETPROCESSOR_INCLUDE_H_

#include "sdframework.h"
#include <protocol/server/protogtgs.h>
#include <net/cli/usermgr.h>

using namespace SGDP;


class CNSProcessor :public CSDPacketProcessor
{
public:
    CNSProcessor();
    ~CNSProcessor();
public:
    virtual BOOL  Init() ;
    virtual CSDProtocol* GetProtocol() ;
private:
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////// δ����CUserʱ��Э��,ʹ��CGTPipeChannel���� ///////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    static BOOL        OnEnterGSReq(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
};

#endif

