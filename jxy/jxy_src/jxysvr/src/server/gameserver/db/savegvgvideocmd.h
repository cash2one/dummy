///<------------------------------------------------------------------------------
//< @file:   gameserver\db\savegvgvideocmd.h
//< @author: hongkunan
//< @date:   2014��2��12�� 10:12:59
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _savegvgvideocmd_h_
#define _savegvgvideocmd_h_


#include "logic/gvg/gvgvideomgr.h"

#include <db/basedbccmd.h>
#include <sddb.h>

class CSaveGvGVideoCMD : public CBaseDBCMD
{
public:
    // �����ݿ��߳�ִ��
	VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted();

    // @impl
	virtual VOID SetUserData(VOID* pUserData);

public:
	virtual EDBCmdType GetDBCmdType() { return EDBCT_SAVE_GVG_VIDEO; }

private:
    // �Ѵ��洢��¼���б�ƴ�ӳ�sql������䣬���ص��ַ���������磺insert into gvgvideo( VideoID, Date, PvPVideo) values ('2014/2/12 00:00:00', '¼��Ķ���������'), ('2014/2/12 00:00:00', '¼��Ķ���������'), ......
    std::string BuildSql(SGDP::ISDDBConnection*);

    // �ѵ���¼������ƴ�ӳ�sql��䣬���ص��ַ���������磺('2013/12/10 00:00:00', '¼��Ķ���������')
    std::string BuildGvGVideoSql(SGvGVideo &stVideo, SGDP::ISDDBConnection*);

    std::string BuildPKVideoSql(SGvGVideo &stVideo, SGDP::ISDDBConnection*);

private:
    // ����¼��
    SGvGVideo *m_pstVideo;

    VideoID m_videoID;

    BOOL m_bOK;
};

class CClearGvGVideoCMD : public CBaseDBCMD
{
public:
    // �����ݿ��߳�ִ��
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection*);

    // ���߼��߳�ִ��
    VOID SDAPI OnExecuted(){}

    // @impl
    virtual VOID SetUserData(VOID* pUserData){}

public:
    virtual EDBCmdType GetDBCmdType() { return EDBCT_CLEAR_GVG_VIDEO; }
};

#endif //_savegvgvideocmd_h_