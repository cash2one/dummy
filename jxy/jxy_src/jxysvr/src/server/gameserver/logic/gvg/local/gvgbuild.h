///<------------------------------------------------------------------------------
//< @file:   gvgbuild.h
//< @author: 
//< @date:   2014��1��18�� 17:18:37
//< @brief:  ���ս������ÿ��gamesvr����ֻ��һ��
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgbuild_h_
#define _gvgbuild_h_

#include "logic/gvg/gvgdef.h"
#include "logic/activity/activity.h"

#include <list>
#include <sdsingleton.h>
#include "protocol/server/protocligs.h"

#define SAVE_GVG_BUILD_INTERVAL 20

typedef struct tagPKT_PKGS_SYNC_GVG_NTF PKT_PKGS_SYNC_GVG_NTF;

typedef list<DT_FACTION_APPLAY_DATA> CFactionApplayDataLst; // ���������б�
typedef CFactionApplayDataLst::iterator CFactionApplayDataLstItr;

typedef map<UINT16, DT_SIMPLE_FACTION_INFO> CMapSimpleFaction; // ������ƴ�ʹ��Ҷ�����б�
typedef CMapSimpleFaction::iterator CMapSimpleFactionItr;

typedef map<UINT16, DT_GVG_FACTION_RANK_DATA> CMapFactionLastRank; // ���������б�
typedef CMapFactionLastRank::iterator CMapFactionLastRankItr;

typedef set<UINT32> C32Set;
typedef C32Set::iterator C32SetItr;

typedef struct tagDT_FACTION_SUPPORT_LIST DT_FACTION_SUPPORT_LIST;

enum{ FIRST_RANK = 1, LAST_RNAK = 4};

class CPlayerGVG;

// �洢2�����ɼ��ս�������Ϣ
struct SGvGFightResult
{
    SGvGFightResult(){ memset(this, 0, sizeof(*this)); }

    VideoID videoID;
    UINT32 dwFactionID1;
    UINT32 dwFactionID2;

    GvGRound eBigRound;
    UINT8 bySmallRound;

    GvGResult eResult; // ʤ�ܽ��
};

typedef std::map<VideoID, SGvGFightResult> GvGFightResultMap; // �����ɼ�Ķ�ս�����key = ��ս¼��id��value = ��ս���

// ���ɿ��ս������ÿ��gamesvr����ֻ��һ��
class CGvGBuild
{
    DECLARE_SINGLETON(CGvGBuild)

    typedef std::vector<CFaction*> CFactionVec;    

public:
    CGvGBuild()
        : m_eStage(GVG_0_NOT_START)
        , m_eRound(GVG_SLEEPING)
        , m_bGiveChaosWarAward(FALSE)
        , m_bGiveFinalWarAward(FALSE)
    {
		memset(&m_stGvGBuildData, 0, sizeof(DT_GVG_BUILD_DATA));
		m_stFactionApplayDataLst.clear();
		
    }
	~CGvGBuild()
	{
		memset(&m_stGvGBuildData, 0, sizeof(DT_GVG_BUILD_DATA));
		m_stFactionApplayDataLst.clear();
		m_eRound = GVG_SLEEPING;
		
	}
public:
    BOOL Init();
    BOOL LoadBuildDataFromDB();
	VOID InitData();
	VOID Run();
	VOID SaveToDB();

public:
    // ������ս����һ��
    void EnterStage(GVG_STAGE);

    // ���յ����ս���������͵Ľ�����һ����Ϣ
    void OnEnterStageNotify(GVG_STAGE);

    // ����ս������
    void SendGetGvGActivityReq();

    // �ָ����ս�Ľ���
    void ReEnterStage();

    // �������Կ��ս��������ͬ��֪ͨ
    void HandleSyncGvGNtf(PKT_PKGS_SYNC_GVG_NTF&);

    // �������Կ��ս��������ͬ������֧������֪ͨ
    void HandleSyncSupportNtf(DT_FACTION_SUPPORT_LIST&);

    // ȡ����������¼��id�б�
    void TakeRequiredVideoIDList(VideoIDSet &mapVideoIDs);

    // ָ���׶��Ƿ���׼������
    BOOL IsReadyByStage(GVG_STAGE eStage);

    // �ж�ָ���׶��Ƿ������
    BOOL IsLogicReady(GVG_STAGE eStage);

    // ���������Զ��������������ã�
    void AutoApply();

    // ��ʼ�������ɿ��ս�
    void GvGStart();

    // ��������Ŀ������ս��������
    void Clear();

    // ���뱾����ս��������
    void GvGSleep();

    // �����������ɿ��ս�
    void GvGOver();

    // ������սѫ��
    void GiveMedal();

    // ��Ȿ���Ƿ������ɿ��ս
    void CheckOpenUp();

    // �������������վ�Ƿ���δ����
    BOOL IsLockActivity();

    // ��ǰ�Ƿ��ڿ������ս���̣�δ�������ѽ��������ڽ����У�
    BOOL IsActivityTime();

    // ����ӳ�����ɿ��ս�Ļ����
    void Remapping();

    // �������ս��Ƿ��ѿ���
    inline BOOL IsOpenUp();

    // �����Ƿ����㿪���������ս�������
    BOOL CanOpenUp();
    
    // �ж�ָ���׶��Ƿ��ѱ���ʶΪ�����
    BOOL IsStageDone(GVG_STAGE);

    // ����ָ���׶εı�־Ϊ�������
    void SetStageDone(GVG_STAGE);

    // ���ø��׶εı�־λ
    void ResetStageFlag();

    // ��ǰ�Ƿ����ڽ���ս��
    BOOL IsInWar();

    // �Ƿ񼴽���ʼս��
    BOOL IsWillWar();

    // ��ȡ�����Ŀ��ս����
	const DT_GVG_BUILD_DATA& GetDT_GVG_BUILD_DATA(){ return m_stGvGBuildData; }

public:
    // ��������������ɵĹ��ڿ��ս����ս��
    void ClearExpiredFactionGvG();

    // ������ɶ�ս���
    void AddGvGFightResult(SGvGFightResult&);

    // ��ȡ���ɶ�ս���������false˵���Ҳ�����ս���
    BOOL GetGvGFightResult(VideoID, SGvGFightResult&);

    // �������ɶ�ս���
    SGvGFightResult* FindGvGFightResult(VideoID);

    // ���¸��¸�������Ϣ
    void UpdateGvGFaction();

    // ��������б�
    void AddGvGFaction(DT_GVG_FACTION astFactionList[], UINT8 byFactionCnt);

    // ���¸����ɼ�Ķ�ս�б�
    void UpdateFightResult();

    // ��������ս����������������
    void DispatchGvGLog();

    // ������ս����չ������ս���Է������
    void SimpleGvGLogToFullLog(DT_FACTION_GVG_LOG_LIST &stLogList, DT_FACTION_SIMPLE_GVG_LOG_LIST &stSimpleLogList);

    // ˢ�±��������Ĵ��ִ�
    void SetStage(GVG_STAGE);

    // ���ɴ��Ҷ��Ƿ��ѽ�����ϣ������ִξ���ᣩ
    BOOL IsChaosWarEnd();
    
    // �ķ��ܾ����Ƿ��ѽ�չ������ϣ������ִξ���ᣩ
    BOOL IsFinalWarEnd();

    // ���������ɴ��Ҷ���ѡ��
    void RollChaosWarSeed();

    // �������ɴ��Ҷ��ִ�
    void ChaosWarBegin();

    // �������ɴ��Ҷ�
    void ChaosWarGo();

    // ��ӡ��������
    void PrintApplyList();

    // ��ӡ������ǰ8ǿ���������ƴǰ4�������ɴ��Ҷ�ǰ4��
    void PrintLocalTop8();
    
    // ��ӡ����������������
    void PrintFinalWinners();

    void EraseFactionOfflinePlayers(CFactionVec &vecFaction);

    // ��ȡ���ɴ��Ҷ�������ѡ��
    void GetChaosWarSeed(CFactionVec &vecSeed);

	//��ȡ��ǰ�ڼ�����ս
	UINT16 GetCurSession(){ return m_stGvGBuildData.wSessionID; }

	//��ȡ��ǰ�׶�
	GVG_STAGE GetCurStage(){ return m_eStage; }

    //��ȡ��ǰ�ִ�
	GvGRound GetCurRound(){ return m_eRound; }

    // ��������
	BOOL ApplyGVGGame(UINT32 dwFactionID);

	//�Ƿ��ǲ������ƴ
	BOOL IsMoneyGame(UINT32 dwFactionID);

    // ��ȡ��ǰ�ִε������Ӧ��ʾ�ĵ���ʱ
    UINT32 GetDisplayCountDownTime();

    // ��ȡָ���׶εĿ���ʱ��
    UINT64 GetStageTime(GVG_STAGE);

    // ��ȡ16��8��8��4�������ʾ����һ��
    GvGRound GetNextRoundAt16To8To4Panel();

    // �洢������������
    void StoreLastWinners();

public:
	///////////////Э��////////////////
// һ�����
    // �������
    UINT16 OpenGVGApplyPanel(PKT_CLIGS_GVG_APPLAY_ACK& stAck, CPlayerGVG* poGvG);//�򿪱����׶����
    
    // ������ƴ���
    UINT16 OpenGvGMoneyWarAck(PKT_CLIGS_GVG_MONEY_CHAOS_ACK& stAck, CPlayerGVG* poGvG);//�������ƴ�׶�(��δ����)

    // �������ɴ��Ҷ����
    UINT16 OpenGvGChaosWarAck(PKT_CLIGS_GVG_MONEY_CHAOS_ACK& stAck, CPlayerGVG* poGvG);//���Ҷ��׶Σ���δ��ʼ��
    
    // ˫��16��8��8��4��̭�����
    UINT16 OpenGVG16To8To4Ack(CPlayer* poPlayer, PKT_CLIGS_16_TO_8_TO_4_ACK& stAck);

    // �ķ������ܾ������
    UINT16 OpenGVGFinalWarAck(CPlayer* poPlayer, PKT_CLIGS_FINAL_WAR_ACK& stAck);

    // ������Ǽ������
    UINT16 OpenGVGChampionAck(CPlayer* poPlayer, PKT_CLIGS_GVG_CHAMPION_ACK& stAck);
    
    // ���ɿ��սδ������ʾ
    void OpenGVGNotOpenMsgAck(CPlayer* poPlayer, PKT_CLIGS_GVG_ERR_MSG_ACK&);


// �������
	UINT16 GetFactionMoneyRank(PKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK& stAck);//�򿪲�������
	UINT16 GetApplayFaction(PKT_CLIGS_OPEN_ALREAD_APPLAY_ACK& stAck);//���ѱ����������� 
	UINT16 OpenGVGFormation(PKT_CLIGS_OPEN_GVG_FORMATION_ACK& stAck, CPlayer* poPlayer);//��GVG�������Ͳ���
	UINT16 GetGambleInfoAck(PKT_CLIGS_GVG_OPEN_GAMBLE_REQ& stReq, PKT_CLIGS_GVG_OPEN_GAMBLE_ACK& stAck, CPlayerGVG* poGvG);
	void GetLastResult(DT_GVG_FACTION_RANK_LST_DATA&);
	UINT16 FactionApplyAck(CPlayer* poPlayer);

    // �ۿ�����ս��¼��
    UINT16 SeeGvGVideo(PKT_CLIGS_SEE_GVG_VIDEO_ACK_v410&, UINT64 qwVideoID, BYTE byVideoNum);
	
    // �����ۿ�����ս��¼��
    UINT16 EndGvGVideo(PKT_CLIGS_END_GVG_VIDEO_ACK_v410&, UINT64 qwVideoID, BYTE byEndType);

    // �鿴����ս����MVP�б�
    UINT16 ShowGvGMVP(PKT_CLIGS_SHOW_GVG_MVP_ACK&, UINT64 qwVideoID);

    // �鿴����ս��
    UINT16 OpenGvGLog(PKT_CLIGS_OPEN_GVG_LOG_ACK&, CPlayer&, UINT32 dwFactionID);

public:
    //�Ƿ��ǲ���ʱ��: True Ϊ�ڲ���ʱ�䣬 FALSE Ϊ�ǲ���ʱ��
    BOOL IsFormationTime();

    //�Ƿ����� True Ϊ�ѱ����� False Ϊδ����
    BOOL IsApply(UINT32 dwFactionID);

    // �Ƿ�������ѡ��
    BOOL IsSeedFaction(UINT32 dwFactionID);

    //��ǰ�Ƿ��ڻ����ʱ��
    BOOL IsApplyTime();

    // ��ȡ����Ŀ���ʱ��
    UINT64 GetStartTime();

    // ���ɳ�Ա�Ƿ����뿪ָ������
    BOOL CanLeaveFaction(UINT32 dwFactionID);

    // ��ȡ����Ľ���ʱ��
    UINT64 GetEndTime();

    // ��ȡ��ǰ��ʾ������ս������
    UINT16 GetReadableGvGLogCnt(DT_FACTION_GVG_LOG_LIST &stLogList);

    // ֧��ָ������
    void AddFactionSupport(UINT32 dwFactionID);

    // ��ȡ������ǰ8ǿ
    BOOL TakeLocalWarWinners(CFactionVec &vecTopFaction);
    
    // ���������¼���Ƿ��Ѿ��ӿ��ս��������ȡ����
    BOOL IsAllVideoHere();

private:
    // �Ƿ���Ҫ���ظ�ս��
    BOOL IsNeedHideGvGLog(UINT8 byBigRound, UINT8 bySmallRound);

    // ��ս���Ƿ��ѵó����
    BOOL IsGvGLogStart(UINT8 byBigRound, UINT8 bySmallRound);

    // ��ȡ�������ɵ�ս��
    void GetLocalFactionGvGLog(DT_FACTION_GVG_LOG&, CFaction&);

    // ��ȡ�������ɵ�ս��
    void GetGlobalFactionGvGLog(DT_FACTION_GVG_LOG&, UINT32 dwFactionID);

    // ���ص����ֵ�ǰ��Ӧ��ʾ������ս��
    void HideGvGLog(DT_FACTION_GVG_LOG_LIST &stLogList);

    //��ȡѺע�غ�
    DT_GVG_ROUND GetGambleRound();

    // ��ȡָ�����ɵ�ǰ�������Ӧ��ʾ�Ļ���
    UINT32 GetDisplayFactionScore(UINT32 dwFactionID);
    
    // �����ķ��ܾ�������
    void GiveFinalWarAward();

    // �������ƴ����
    void GiveMoneyWarAward();        

    // ����ս�����������ȡ���������¼��
    void TakeThisZoneVideo();

    // ���ɴ��Ҷ�����
    void GiveChaosWarAward();

    // ˫��16��8����
    void Give16To8Award();

    // ˫��8��4����
    void Give8To4Award();

    // ���轱������ս��������ն������������������ҫ�����ȣ�
    void GiveAward();

    // ����ս���������ʤ������ο����
    void GiveAwardByGvGResult(const DT_GVG_FACTION &stFaction1, const DT_GVG_FACTION &stFaction2, VideoID videoID);

    // ����ָ��ս������ն����
    void GiveKillComboAward(UINT32 dwFactionID, VideoID videoID);

private:
    //������ҿ��ս����
    void GivePlayerAward();
	//��ӱ�������
	UINT16 AddApplyFaction(UINT32 dwFactionID, UINT64 qwStartTime = SGDP::SDTimeSecs());
    //��ӻ�ʤ����
    void AddWinCnt(UINT32 dwFactionID);
	//���ñ�������
	VOID ResetApplayFaction();
	//��ӽ������
	VOID AddResult(UINT16 wRank, DT_GVG_FACTION_RANK_DATA& stInfo);
	//�����Ͻ���
	VOID ResetResult();
	//���ò������н��
	VOID ResetMoneyRank();
    //���ø������ۻ�����
    void ResetFactionFunds();
	//��Ӳ������н��
	VOID AddMoneyRank(UINT16 wRank, DT_SIMPLE_FACTION_INFO& stInfo);
	//���ô��Ҷ����
	VOID ResetChaosResult();
    //���ô��Ҷ�����б�
    VOID ResetChaosPair();
	//��Ӵ��Ҷ����
	VOID AddChaosResult(UINT16 wRank, DT_SIMPLE_FACTION_INFO& stInfo);
	//��ȡ�ʽ�����
	VOID GetMoneyRank(DT_GVG_RANK_MONEY_LST_DATA& stMoneyData);
	//��ȡ�����ʽ�����
	VOID GetSimpleMoneyRank(DT_GVG_SIMPLE_RANK_MONEY_LST_DATA& stMoneyData);
	//��ȡ��ǰ����
	BOOL GetCurSchedule(DT_GVG_SCHEDULE_INFO& stScheduleInfo, CPlayerGVG* poPlayer);
	//��ȡ������ƴ���
	VOID GetMoneyWarResult(DT_SIMPLE_FACTION_LST_INFO& stLstInfo);
	//��ȡ���Ҷ����
	VOID GetChaosWarResult(DT_SIMPLE_FACTION_LST_INFO& stLstInfo);

	//��ȡ��һ�ֵĵ���ʱ
	UINT32 GetNextStageCountDown();

    // ����ͻ����´�Ӧ�����������ˢ����壨�����·��ʹ�Э�飩
    UINT32 GetClientRefreshTime();

    // ͬ��������������֧����
    void SyncFactionSupport();

    // ������ת�����ṹ����
    void SaveLastWinnersToStruct();

    //�������ƴ����������
    VOID AfterMoneyWar();

private:
    // ��ǰС�ִ�
    GVG_STAGE m_eStage;

    // ��ǰ���ִ�
    GvGRound m_eRound;

    // ���������ɿ��ս���ݣ����е�16��8��8��4���ܾ��������ݶ����ɿ��ս������ͬ��������
	DT_GVG_BUILD_DATA m_stGvGBuildData;

	C32Set m_setApplyFaction;//�����������б�
	CFactionApplayDataLst m_stFactionApplayDataLst;//�����б�
	CMapFactionLastRank m_mapLastResult;//�Ͻ��������������ı䣩
	CMapSimpleFaction m_mapMoneyResult;//����������������ı䣩
	CMapSimpleFaction m_mapChaosResult;//���Ҷ�������������ı䣩

    GvGFightResultMap m_mapGvGResult; // �洢�����ɼ�Ķ�ս�������¼��IDΪ����

    FactionSupportMap m_mapFactionSupport;
    UINT32 m_dwRecentSupportCnt; // �����ͶƱ����

    BOOL m_bGiveChaosWarAward; // �Ƿ��Ѹ�����Ҷ�����
    BOOL m_bGiveFinalWarAward; // �Ƿ��Ѹ�����Ҷ�����
};

#endif //_gvgbuild_h_