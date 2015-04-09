///<------------------------------------------------------------------------------
//< @file:   gvgmgr.h
//< @author: hongkunan
//< @date:   2014��1��13�� 22:34:41
//< @brief:  ���ɿ��ս������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgmgr_h_
#define _gvgmgr_h_

#include <protocommondata.h>
#include <sdobjectpool.h>
#include <sdsingleton.h>

#include "gvgarena.h"

// ������ɶ�ս����ͼ
/*
 *          ���ս������                                             ��Ϸ������                                         ���ݿ�
 *
 *
 * ���gamesvr���Ͳ���������ѡ������                  ---->
 *                                                              
 *                                                    <----     ���������������ظ����������ú������������
 * �յ������ɵĲ������ݣ�Ϊÿ�����ɽ���������
 * ��������齫�����������������gamesvr��Ҫ�������  ---->
 *                                                              �յ�����������������������������
 *                                                              ����ҵõ���ҿ��գ���ֱ�ӽ����ݷ��ظ����ս������
 *                                                              �������ݿ���ȡ���������                  ---->
 *                                                                                                          <----   ȡ���������
 *                                                    <----     �õ�������ݣ�����CPlayer���ظ����ս������
 * ֱ���������ɾ��ѻ�ȡ��������ҵ����ݣ�
 * �����ɼ俪ʼ��ս
 *
 */

class CGvGArena;

// ����vs����
class CGvGMgr
{
    typedef std::map<ZoneID, ArenaID> ZoneToArenaMap;
    typedef std::map<ZoneID, UINT8> ZoneOpenReplyMap;

public:
    DECLARE_SINGLETON(CGvGMgr)

    CGvGMgr()
        : m_eStage(GVG_0_NOT_START)
    {
        memset(&m_stActData, 0, sizeof(m_stActData));
    }

    BOOL Init();

    void Run();

    // �����ݿ���ȡ�����ս����ݣ��磺���ս���������ʼʱ�����Ϣ
    BOOL LoadGvGActivityDB();

    // ��ȡ�������ս��������������
    BOOL LoadGvGArenaDB();

    // �ӵ�ǰȫ�ֻ��������ȡ��ĳ�������Ļ����
    void GlobalGvGToLocalGvG(DT_GVG_LOCAL_ACTIVITY_DATA&, const DT_GVG_ARENA_DATA &stArena);

    UINT16 GetCurSession(){ return m_stActData.wSessionID; }

    // ����ǰ�Ŀ��ս¼��ͬ����������
    void SyncVideo(ZoneID);
            
    // ����ǰ���ȴ������ݿ�
    BOOL SaveToDB();

    // ����������͸�ָ����
    void PushActivityDataToZone(ZoneID);

    // ��ʼ����ʱ�¼������磺����x1��x2��ʱ����16��8��������y1��y2�뿪��8��4����
    BOOL InitTimerEvent();

    // �ָ����ս�Ľ���
    BOOL RecoverProgress();

public:
    // ���ս������һ��
    BOOL EnterStage(GVG_STAGE eNextGvGRound);
    
    // ���ս���½��뵱ǰ�ִΣ�ȷ�����ս����������¼����жϣ��磺��Ϸ��������������ĳ��֪ͨδ���ʹ�����������¶�����
    BOOL ReEnterCurStage();

    // ���ս������һ��
    BOOL EnterNextStage();
    
    // ���µ�ǰ�ִ�
    void SetStage(GVG_STAGE);

    // ��ʼ�������ɿ��ս�
    BOOL GvGStart();

    // ��ʼ���ɿ��ս�����
    void ClearActivity();

    // ѯ�ʸ����Ƿ��ܿ����������ս�
    void AskCanOpen();

    // ������һ����ս��������
    BOOL GvGSleep();

    // �����������ɿ��ս�
    void GvGOver();

    // ָ����������ȡ��ȫ��������Ա�����Կ�ʼս��
    void OnArenaReadyGo(CGvGPullGroup*);

public:
    // ����1 vs ����2������ս�ֽ��
    static SGvGVideo& GvG(CFaction *g1, CFaction *g2);

    // ����1 vs ����2������ս�ֽ��
    static SGvGVideo& GvG(CPKFaction *g1, CPKFaction *g2);

    // ��Ҷ���vs��Ҷ���
    static void TeamVsTeam(CPlayerVec&, CPlayerVec&, SGvGVideo&);
    
    // �ɹ����յ�xxx������Ϸ�����ص�ǰ8ǿ��������
    void HandleRetTopFactions(ZoneID, PKT_GSPK_GVG_RET_TOP_8_ACK&);

    // �ɹ����յ�xxx������Ϸ�����صĲ�ս��������
    void HandleRetFactions(ZoneID, PKT_GSPK_RET_FACTIONS_ACK&);

    // ���յ�ĳ�����ľ����ظ�
    void OnZoneSayReady(ZoneID, PKT_GSPK_GVG_REPLY_READY_ACK&);

    // ���յ�ĳ�������Ƿ�ɿ��Żظ�
    void OnZoneSayCanOpen(ZoneID, PKT_GSPK_GVG_REPLY_OPEN_ACK&);
    
    // ��ȡ��ǰ�������ִ�
    GVG_STAGE GetCurStage(){ return m_eStage; }

    // ���ο��ս������������Ϣ
    DT_GVG_ACTIVITY_DATA& GetActivityData(){ return m_stActData; }

    // ��Ȿ���Ƿ������ɿ��ս
    void CheckOpenUp();

public:
    // �������ս��Ƿ��������ָ���׶�
    BOOL IsDone(GVG_STAGE);

    // ���������Ƿ�������ָ���׶ε�����
    BOOL IsAllArenaDone(GVG_STAGE);

    // ��������ɿ��������
    void ClearArena();

    // �����յĿ��������
    BOOL BuildEmptyArena();

    // ָ�������Ƿ񿪷�
    BOOL IsArenaOpenUp(ArenaID);

    // �Ƿ����е��������ر����ɿ���
    BOOL IsAllZoneReplyCanOpen(ArenaID);

    // �����յĿ��������
    ZoneIDSet GetArenaZoneIDList();

    // �����ź������Ž�����ӳ��map
    void BuildZoneIDToArenaIDMap();

    // ���ݿ�����ɾ�����ID��ȡ��Ӧ������ʵ��
    CGvGArena* GetArena(ArenaID);

    // �����µ����ɾ�����ʵ��
    CGvGArena* NewArena(ArenaID);

    // ����ĳ�������͹�����֧�������б�
    void SupportFaction(GvGRound, ArenaID arenaID, DT_FACTION_SUPPORT_LIST&);

    // ������ID��ȡ����ID
    ArenaID GetArenaIDByZoneID(ZoneID);

    // ������ID��ȡ����
    CGvGArena* GetArenaByZoneID(ZoneID);

private:
    // ��ǰС�׶�
    GVG_STAGE m_eStage;

    // ���� -> ����ID��ӳ���б�
    ZoneToArenaMap m_mapZoneToArena;

    // �洢�������Ƿ��Ѵﵽ�����������ս�������Ӧ��
    ZoneOpenReplyMap m_mapOpenReply;

private:
    // �����б�
    CGvGArenaVec m_vecArena;

    // ���ο��ս������������Ϣ���ӱ����ݽṹ���Ի�ԭ�����ս�Ľ��̺���ʷ��
	DT_GVG_ACTIVITY_DATA m_stActData;
};

#endif //_gvgmgr_h_