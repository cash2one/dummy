///<------------------------------------------------------------------------------
//< @file:   gvg\global\gvgarena.h
//< @author: hongkunan
//< @date:   2014��5��5�� 15:23:16
//< @brief:  ���ɿ��ս����
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgarena_h_
#define _gvgarena_h_

#include <protocommondata.h>

#include "logic/gvg/gvgdef.h"
#include "logic/base/basedefine.h"
#include "gvgmember.h"

struct SGvGVideo;
class CPKZone;

// ���ɿ��ս��������һ�������ɶ�������
class CGvGArena
{
    typedef std::map<UINT32, DT_FACTION_SIMPLE_GVG_LOG_LIST> FactionSimpleLogMap;  // �����ɵļ�������ս���б�key = ����ID�� value = �����ɵ�ս����ʷ
    typedef std::map<VideoID, SGvGVideo*> GvGVideoPointerMap; // ���ɼ��ս¼��

public:
    CGvGArena()
        : m_dwPullGroupID(0)
        , m_eStage(GVG_0_NOT_START)
        , m_eRound(GVG_SLEEPING)
    {
        memset(&m_stArena, 0, sizeof(m_stArena));
    }

public:
    // ���ݴ�����������ݻ�ԭ��������
    BOOL Init(const DT_GVG_ARENA_DATA&);

    // ��ȡ������������
    DT_GVG_ARENA_DATA& GetArenaData(){ return m_stArena; }

    // ��ȡ������������ID
    ArenaID GetArenaID(){ return m_stArena.wArenaID; }

    // ����ָ���ִε�������Ϣ
    void UpdateFactionsByRound(GvGRound);

    // ���16��8������ѡ���б�
    void Add16To8Members(ZoneID, DT_GVG_FACTION astTop8List[], UINT8 byTopCnt);

    // ��ʼ���ܾ�������Χѡ��
    BOOL InitFinalWarMembers();

    // ����˫��16��8�ĶԾ�����
    BOOL RollPair16To8();

    // ���ɿ��ս��ָ���׶��Ƿ������
    BOOL IsDone(GVG_STAGE);

    // ���ݵ�ǰ���ɿ��ս��״�������ж�ָ���׶��Ƿ������
    BOOL IsLogicDone(GVG_STAGE);

    // �������Ƿ���ѷ��ؾ���Ӧ�����û�У�������ѯ��һ��
    void CheckEachZoneReady();

    // ���ս�������뱾�����ĸ���Ա���Ƿ���������
    BOOL IsAllZoneConnecting();

    // ��ʼ����ս�����˽ӿ�Ҫ���������ɡ�������������ѵ�λ��
    BOOL Go();

    // ��ȡָ���ִθ����Ĳ��������б�
    EachZoneFactionIDListMap SplitFactionsByZone(GvGRound);

    // �Ƿ��ѽ��յ���������ȫ����Ա������������
    BOOL IsAllZoneArrived(GvGRound);

    // �Ƿ��ѽ��յ�ָ��������������
    BOOL IsZoneArrived(ZoneID);

    // �����Ƿ�Ϊ��
    BOOL IsEmpty();

    // �������ĳ�Ա�������Ƿ����׼������
    BOOL IsAllZoneReady();

    // ��ո�����Ա���ľ���״̬
    void ClearReadyZoneList(){ m_setReadyZone.clear(); }

    // ���յ�ĳ�������صĸ�����������
    void OnRecvFaction(ZoneID, DT_PK_FACTION_LIST&);

    // ���յ�ĳ�������صĸ���ǰ��ǿ�����б�
    void OnRecvTopFaction(ZoneID zoneID, DT_GVG_FACTION astTopList[], UINT8 byTopCnt);

    // ��ָ�������Ϊ�Ѿ���
    void SetZoneArrived(ZoneID);

    // ��ʼ���������ɿ��ս�
    BOOL GvGStart();

    // �������������ɿ��ս�
    BOOL GvGSleep();

    // �������������ɿ��ս�
    BOOL GvGOver();

    // ѯ�ʱ������ĸ�����Ա������ǰ�׶��Ƿ��Ѿ���
    void AskReady();

    // ��Ա������Ӧ�𣺵�ǰ�׶��Ѿ���/δ����
    void OnZoneSayReady(ZoneID, PKT_GSPK_GVG_REPLY_READY_ACK&);

    // ��ȡ������ǰ8ǿ
    void GetEachZoneTop8();

    // �������ɴ��Ҷ�����������16��8�׶Σ���ʱ����Ӧ�Ѿ���ǰ8��
    void ChaosWarEnd();

    // ����16��8�ִΣ�Ϊ����ѡ�ֽ�����ԣ������δ��ʼս��
    BOOL War16To8Begin();

    // ����8��4�ִ�
    BOOL War8To4Begin();

    // �����ܾ���
    BOOL FinalWarBegin();

    // �����ܾ���δ��ʼս��
    void AddFinalWarNotStartLog(UINT8 byRound);

    // 16��8�ִΣ�����˫��ǰ8ǿ
    BOOL War16To8Go();

    // 8��4�ִΣ�����˫��ǰ4ǿ
    BOOL War8To4Go();

    // ��ӡ16��8��ʤ����
    void Print16To8Winner();

    // ��ӡ8��4��ʤ����
    void Print8To4Winner();
    
    // ��ӡ���վ�����ʤ����
    void PrintFinalWinner();

    // �ܾ�����׼����ʼ��ս
    BOOL PrepareFinalWarGo();

    // �ܾ�����һ�ֽ���Ƿ��Ѿ���
    BOOL IsFinalWarRoundComplete(UINT8 byRound);

    // �ܾ����Ƿ�Ӧ������չ��һ��
    BOOL IsShouldFinalWarMoveOn();

    // ���ݵ�ǰʱ���ȡ�ܾ�����ǰӦ�����ִΣ�����ִ� = ������
    UINT8 GetExpectFinalWarRound();

    // �ܾ�������ʼ��ս
    BOOL FinalWarGo();

    // ��ʼָ��С�ִε�ս��
    BOOL PrepareWarGo(GVG_STAGE);

    // ����ָ��С�ִε�ս��
    BOOL WarEnd(GVG_STAGE);

    // ��ʼָ��С�ִε�ս��
    BOOL War16To8End();

    // ��ո����������ݾ����б�
    void ClearArrivedZone(){ m_setArrivedZone.clear(); }

    // ���ñ��������ݣ�ȫ�����
    void Clear();

    // ִ�и��ִεı�����ʼǰ���峡����
    void ClearWar();

    // ��������֧���б�
    void SupportFaction(GvGRound, DT_FACTION_SUPPORT_LIST &stFactionList);

    // ͬ��������Ա����ǰ�����ɵ�֧������Ϣ
    void SyncFactionSupportCnt(FactionSupportMap &mapNowSupport);

    // ��ʼ���������ĳ�Ա���б�
    void InitZoneList(GroupZoneIDMap&);

    // �������������ݴ������ݿ�
    BOOL SaveToDB();

    // Ѱ��ָ���ľ�ս��
    CPKZone* FindPKZone(ZoneID zoneID);

    // Ѱ��ָ������ָ����ս����
    CPKFaction* FindPKFaction(ZoneID zoneID, UINT32 dwFactionID);

    // ˢ�¿�����ɾ������Ĳ���ѡ������
    void AddPlayers(CGvGPullGroup&);

    // Ϊ����Ա������һ����ʵ��
    void BuildZone();

    // ���������ĸ�������
    void ClearZones();

    // Ϊָ�����������µ���ʵ��
    CPKZone* NewPKZone(ZoneID);

    // ��ʼ��������ȡ��������ѡ������
    void StartPullPlayers();

    // ͬ��������¼��ָ����Ա��(��Ϊ0�����ͬ����������Ա��)
    void SyncVideo(ZoneID targetZoneID = 0);

    // ����ǰ�Ŀ��ս����ͬ����ָ����Ա��(��Ϊ0�����ͬ����������Ա��)
    void SyncActivity(ZoneID targetZoneID = 0);

    // ȡ����������¼���б�
    void TakeArenaVideo(GvGVideoPointerMap&);

    // ��ȡ������������Ա�б�
    ZoneIDSet GetThisArenaZoneIDSet();

    // ��ָ�����ս¼���ֳɶ����Ϣ�����͵�ָ����
    void SendPvPVideo(ZoneID zoneID, SGvGVideo &stVideo, PKT_PKGS_RET_VIDEO_ACK &stAck);

    // ���δ��ʼս��
    void AddNotStartLog(UINT32 dwFactionID1, UINT32 dwFactionID2, VideoID videoID, GvGRound eBigRound, UINT8 bySmallRound = 0);
    
    // ����ѽ���ս��
    void AddLog(UINT32 dwFactionID, const DT_GVG_VIDEO &stVideo, UINT16 wFactionAddScore);

    // ȡ�����ݵ��ṹ��
    void TakeDataToStruct();

    // �ж�ָ���׶��Ƿ��ѱ���ʶΪ�����
    BOOL IsStageDone(GVG_STAGE);

    // ����ָ���׶εı�־Ϊ�������
    void SetStageDone(GVG_STAGE);

    // ���ø��׶εı�־λ
    void ResetStageFlag();

    // ��ȡ16��8������ѡ���б�
    FactionIDSet Get16To8Seed();

    // ���ս������һ��
    BOOL EnterStage(GVG_STAGE eNextStage);

    // ���µ�ǰ�ִ�
    void UpdateRound();

    // ���µ�ǰ�ִ�
    void SetStage(GVG_STAGE);

    // ��ָ���ļ������б������ȡ��������
    void SendPullFactionReq(EachZoneFactionIDListMap &mapZones);

    // ֪ͨ����Ϸ�����ս������һ�׶�
    void NotifyStage(GVG_STAGE);

private:
    // ����ָ�������б��е�λ�ã��ҵõ�����1~4���Ҳ�������0
    BYTE GetGroupIDByZone(ZoneID);
    
    // ���¸�������������
    void UpdateFactions(DT_GVG_FACTION[], UINT16 dwFactionCnt);

public:
    // ���ִ����ѷ����������ݵ����б�ÿ���������ս�������һ�ִ�ʱ������б�ᱻ������գ�
    ZoneIDSet m_setArrivedZone;

    // ���ִ��б��������Ѿ��������б�ÿ���������ս�������һ�ִ�ʱ������б�ᱻ������գ�
    ZoneIDSet m_setReadyZone;

    // �����ڱ�������������ID
    UINT32 m_dwPullGroupID;

    // �洢�����ɵļ�������ս��
    FactionSimpleLogMap m_mapFactionLog;

protected:
    // �����ڱ������ĸ�������
    CPKZoneMap m_mapPKZone;

    // ������������
    DT_GVG_ARENA_DATA m_stArena;

    // ��ǰС�׶�
    GVG_STAGE m_eStage;

    // ��ǰ�ִ�
    GvGRound m_eRound;
};

#endif //_gvgarena_h_