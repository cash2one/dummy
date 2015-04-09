///<------------------------------------------------------------------------------
//< @file:   logic\gvg\gvgvideomgr.h
//< @author: hongkunan
//< @date:   2014��2��11�� 21:1:22
//< @brief:  �������ɿ��ս��¼��
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgvideomgr_h_
#define _gvgvideomgr_h_

#include "gvgdef.h"
#include <sdsingleton.h>

typedef struct tagPKT_PKGS_RET_VIDEO_ACK PKT_PKGS_RET_VIDEO_ACK;

// ���ɿ��ս��ս¼��
struct SGvGVideo
{
    SGvGVideo() 
    {
        Clear();
    }

    void Clear()
    {
        memset(&stGvGInfo, 0, sizeof(stGvGInfo));
        vecPvPVideo.clear();
    }

    // ����Ҽ�Ķ�ս¼���Ƿ���ѵ�λ
    BOOL IsAllPKVideoHere()
    {
        if(0 == stGvGInfo.byPKVideoCnt)
        {
            return TRUE;
        }

        if(stGvGInfo.byPKVideoCnt > vecPvPVideo.size())
        {
            return FALSE;
        }

        for(UINT16 i = 0; i < vecPvPVideo.size(); i++)
        {
            DT_GVG_PK_VIDEO &stPKVideo = vecPvPVideo[i];
            if(0 == stPKVideo.byKillCombo1 + stPKVideo.byKillCombo2)
            {
                return FALSE;
            }
        }

        return TRUE;
    }

    // ���ɶ�ս��Ϣ
    DT_GVG_VIDEO stGvGInfo;

    // ��Ҷ�ս¼���б�
    SPvPVideoVec vecPvPVideo;
};

// �������ɿ��ս��¼���������¼��ÿ����һ�ο��ս��ʼʱ���ᱻȫ�����
class CGvGVideoMgr
{
public:
    typedef std::map<VideoID, SGvGVideo> GvGVideoMap;
    typedef std::vector<SGvGVideo> GvGVideoVec;

public:
    DECLARE_SINGLETON(CGvGVideoMgr)

    CGvGVideoMgr()
    {
        m_mapVideo.clear();
        m_setNotSavedVideoID.clear();
    }

public:
    BOOL Init();

    BOOL LoadGvGVideoFromDB();

    BOOL LoadPKVideoFromDB();

    BOOL SaveToDB();

    VOID Clear();

    void OnSaveVideo(BOOL bOK, VideoID);

    void ClearNotSavedList(){ m_setNotSavedVideoID.clear(); }

    void AddVideo(SGvGVideo&);

    void AddPKVideo(PKT_PKGS_RET_VIDEO_ACK&);

    SGvGVideo* GetVideo(VideoID);

    GvGVideoMap& GetVideos(){ return m_mapVideo; }

    VideoIDSet& GetNotSaveVideoIDList(){ return m_setNotSavedVideoID; }

    VideoID MakeVideoID(UINT32 dwFactionID1, UINT32 dwFactionID2);

    BOOL IsEmpty(){ return m_mapVideo.empty(); }

    // ��ӡȱʧ���ս��¼����б�
    void PrintMissingList();

    UINT16 CalcHereVideoCnt(VideoIDSet&);

private:
    // ���ս¼���ÿ��¼����һ��id����ʶ
    GvGVideoMap m_mapVideo;

    // δ���������ݿ��¼���б�
    VideoIDSet m_setNotSavedVideoID;
};

#endif //_gvgvideomgr_h_