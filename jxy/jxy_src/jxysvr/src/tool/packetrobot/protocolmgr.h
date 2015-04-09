// SHANDA GAMES PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Shanda Games and may not 
// be copied or disclosed except in accordance with the terms of that 
// agreement.
//
//      Copyright (c) 1999-2010 Shanda Games.
//      All Rights Reserved.
//
// Shanda Games Limited, Shanghai, China, 201203
// http://www.shandagames.com

#ifndef _PROTPCOLMGR_H_
#define _PROTPCOLMGR_H_

#pragma warning(disable : 4251)
#pragma warning(disable : 4275)

#define SDF_MAX_PROCTOL_MSG     30000

/**
 * @file Э���������
 *
 * ���ڴ��Э������Ϣ��ӳ��
 *
 * @author �������ķ��������沿
 */
#include "netdata.h"
#include <map>
#include <string>

using namespace std;
//using namespace SGDP;

/**
 * @brief Э���������
 */
class CProtocolMgr: public map<string ,CSDProtocol*>
{
private:
    CProtocolMgr();
    ~CProtocolMgr();

public:
    /**
     * @brief ��ȡʵ��
     * @return ��ȡʵ������ָ��
     */
    static CProtocolMgr*  Instance();

    /**
     * @brief ��������Э��
     */
    VOID                  DeleteAll();

    /**
     * @brief ����Э��
     */
    CSDProtocol*		  AddProtocol( CSDProtocol *pProtocol);

    /**
     * @brief ������Ϣ�Ų���Э��
     */
    CSDProtocol*		  FindProtocol(UINT32 nMsgID);

    /**
     * @brief �������Ʋ���Э��
     */
    CSDProtocol*		  FindProtocol(string strName);

    /**
     * @brief ��������ɾ��ָ��Э��
     */
    CSDProtocol*		  RemoveProtocol(string strName);

private:
    /// Э������
    CSDProtocol*          m_SDProtocol[SDF_MAX_PROCTOL_MSG];
};

#endif // #ifndef _PROTPCOLMGR_H_

