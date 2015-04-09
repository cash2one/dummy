///<------------------------------------------------------------------------------
//< @file:   recharge\deal\dealframe76setgvgpair.h
//< @author: hongkunan
//< @date:   2014��8��13�� 10:35:34
//< @brief:  ���ÿ��ս��16ǿѡ�ֶԾ����������ڴ��Ҷ���������16ǿδ��ʼ֮���ʱ����ڱ��ӿ���Ч
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _dealframe76setgvgpair_h_
#define _dealframe76setgvgpair_h_

#include "gmdealframe.h"

class CDealFrame76SetGvGPair : public InterfaceDealBase::CGmDealFrame
{
public:
    CDealFrame76SetGvGPair(InterfaceDealBase::CGmManager * IN_pManager)
    {
        m_pManager=IN_pManager;
        RegisterDealFrame(this);
    }

    virtual UINT16 GetFrameType(){ return EGMT_SET_GVG_PAIR; }
    virtual string GetStrFrameType(){ return SET_GVG_PAIR; }
    virtual string GetStrFrameDesc();

    virtual void Interface(CRCClient* poClinet);
    virtual void Deal(CRCClient* poClinet,UINT32 dwSerialNumber,UINT32 dwAreaID,UINT32 dwPlayerID,map<string,string> &mapField);
    virtual void Deal(CRCClient* poClinet, UINT32 dwSerialNumber, UINT8 byAction, UINT32 dwAreaID, UINT32 dwPlayerID, UINT32 dwParam1, UINT64 qwParam2, UINT64 qwParam3, TCHAR* pszParam4, TCHAR* pszParam5 , TCHAR *pszDesc);

    void SwapFactionPos(CRCClient* poClinet, UINT32 dwZoneID, UINT8 byOldPos, UINT8 byNewPos);
};

#endif //_dealframe76setgvgpair_h_