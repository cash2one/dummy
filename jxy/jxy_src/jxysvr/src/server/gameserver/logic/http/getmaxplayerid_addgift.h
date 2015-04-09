///<------------------------------------------------------------------------------
//< @file:   logic\http\getmaxplayerid_addgift.h
//< @author: Kang_zhiquan
//< @date:   2014��7��28�� 16:30:36
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _getmaxplayerid_addgift_h_
#define _getmaxplayerid_addgift_h_

#include "basehttpcmd.h"
#include "db/addplayergift.h"
#include "logic/http/httpmgr.h"

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetMaxPlayerID_AddGift : public CBaseHttpCMD
{
public:
    CGetMaxPlayerID_AddGift();
    ~CGetMaxPlayerID_AddGift();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_GET_MAX_PLAYERID_ADD_GIFT;
    }
    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
private:
	SActivityGift m_stGift;
};

#endif //_getmaxplayerid_addgift_h_