///<------------------------------------------------------------------------------
//< @file:   gvgpropmgr.h
//< @author: hongkunan
//< @date:   2014��1��16�� 20:28:49
//< @brief:  �������ս����
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgpropmgr_h_
#define _gvgpropmgr_h_

#include "logic/base/basedefine.h"
#include "logic/base/jsonencourage.h"
#include "logic/base/basepropmgr.h"
#include "logic/gvg/gvgdef.h"

#include <sdsingleton.h>
#include <protocligs.h>

// ���ɿ��սʱ��ӿ�
namespace gvgtimeutil
{
    // ��ָ��ʱ�������ܵ���һ�賿���𣬼����һ���������ʱ��
    UINT64 GetTimeFromWeek(UINT64 qwTime, UINT32 dwAddWeekTime);

    // ���ݴ������һ~���ռ�����ʱ�䣬��ȡ���ܾ���������
    UINT32 GetTimeInWeek(UINT8 byWeek /* 1-7�ֱ������һ~���� */, UINT32 dwDayTime);

    // ���ݴ���ʱ���ȡ�����賿0��ʱ��
    UINT64 GetWeekZeroTime(UINT64 qwTime);
}

// �������ս����������
struct SGvGProp
{
    SGvGProp(){ memset(this, 0, sizeof(*this)); }

    UINT32 dwForbidFormationTime;     // ���������ʼʣ�����ʱ��ʱֹͣ�����룩
    UINT16 wRePullInterval;           // ��ȡ��ҵ�ʱ�������룩
    UINT16 wWinAddScore;              // �ܾ����л�ʤ�߻�õĻ���
    UINT16 wLoseAddScore;             // �ܾ�����ʧ���߻�õĻ���
    UINT32 dwChaosWarEachRoundTime;   // ���ɴ��Ҷ�ÿ�ֵ�ʱ�䣨�룩
    UINT32 dwFinalWarEachRoundTime;   // �ķ������ܾ���ÿ�ֵ�ʱ�䣨�룩
                                      
    UINT16 wJoinGVGPlayerLevel;       // ����GVGҪ����ҵȼ�
    UINT32 dwJoinGVGFactionLevel;     // ����GVGҪ�����ɵȼ�
    UINT32 dwJoinGVGRank;             // ����GVGҪ�����������
                
    UINT16 wHonorLevel;               // ��������Ҫ��ȼ�

    UINT16 wAutoJoinFactionCnt;       // ���ɿ��ս�����ʱ�ö��ٸ������Զ�����
    UINT16 wAutoFormationCnt;         // ���ɱ���ʱ�ö��ٸ���Ա�Զ�����
    UINT16 bFakeActTime;              // �Ƿ�α����սʱ��
    BOOL bTest;                       // �Ƿ��ǲ���ģʽ������ģʽ�²��Զ������κν���
    UINT32 dwFakeGap;                 // α��������սʱ��ʱÿ���ִμ�ļ�����룩
    UINT16 wOpenUpRequiredFactionCnt; // һ������Ҫ�������ɴﵽ�ȼ����ܿ������ɿ��ս�
    UINT16 wAutoApplyExceptZone;      // ��ָֹ�����Զ�������������ģ����ԣ�
    BOOL wDisplayVideoMVPCnt;         // �ۿ�ս��ʱ��ն�����б��Ĭ����ʾ����
    BOOL bUsePlayerSnapShot;          // �Ƿ�ʹ����ҿ���
    BOOL bOpenActivity;               // �Ƿ񿪷����ɿ��ս���������ս�Ŀ���
};

// ��ն����
struct SGvGKillComboProp
{
    SGvGKillComboProp(){ memset(this, 0, sizeof(*this)); }

    UINT16 wKillCombo;        // ��ն��
    UINT32 wDoorAward;        // �Ź�����
    UINT16 wAddScore;         // ��ȡ���Ļ���
    UINT8 byRecoverHPPercent; // ��Ѫ�ٷֱȣ�20����ٷ�֮20

    UINT8 byEnegy;           // ��Ӧ����ֵ
    UINT8 byWeakenPercent;    // ȫ���ԣ�����+4�������ԣ������ı�����50����ȫ���Ծ���Ϊԭ����50%
};

// ����ս���
struct SGvGGiftProp
{
	SGvGGiftProp()
	{
		byGiftID = 0;
		strGiftName = "";
	}

	UINT8 byGiftID;
	string strGiftName;
	CJsonResItemVectorInfo stGiftValue;
};

// Ѻע����
struct SGvGGambleAward
{
    SGvGGambleAward(){ memset(this, 0, sizeof(*this)); }

    UINT16 wPlayerLevel;
    UINT32 dwDoubleWarCoin; // ˫��ѺעͭǮ����
    UINT32 dwFinalWarCoin;  // �ķ�ѺעͭǮ����
};

class CGvGPropMgr : public CBasePopMgr
{
public:
    typedef std::vector<UINT64> GvGOpenDateVec;  // ����������ս��Ŀ�ʼ����
    typedef std::vector<UINT32> GvGStageTimeVec; // �������ս������׶ε�ʱ�䣬�׶βμ�: GVG_STAGE
    typedef std::vector<DT_GVG_TIME_INFO> SGvGRoundTimeVec;
    typedef std::vector<SGvGKillComboProp> SKillComboVec;
    typedef std::vector<SGvGGambleAward> SGvGGambleAwardVec;

    typedef std::map<UINT16, GroupZoneIDMap> ArenaZoneIDMap; // ��̨����map��ֵ = ��̨ID, ֵ = ����̨������Ա�б�
    typedef std::map<ZoneID, ArenaID> ZoneIDToArenaIDMap;

	typedef map<UINT8, SGvGGiftProp> CMapGvGGiftProp;
    typedef CMapGvGGiftProp::iterator CMapGvGGiftPropItr;

    typedef std::map<UINT16, std::string> ZoneNameMap;
	typedef std::map<ArenaID, UINT16> UnLockMap; // key = ����ID��val = ���������ڵڼ��쿪��

public:
    DECLARE_SINGLETON_PROPMGR(CGvGPropMgr);
	CGvGPropMgr()
	{
		memset(m_aszGvGRule, 0x00, MAX_GVG_RULE);
	}
	~CGvGPropMgr()
	{
		memset(m_aszGvGRule, 0x00, MAX_GVG_RULE);
	}
public:
    virtual EConfigModule GetConfigModuleType() { return ECM_GVG; }

    BOOL Init();

    VOID UnInit();

    SGvGProp& GetGvGProp(){ return m_stGvGProp; }
    
    GvGStageTimeVec& GetGvGStageTimeVec(){ return m_vecStageTime; }

    DT_GVG_SCHEDULE_INFO& GetGvGSchedule(){ return m_stDisplaySchedule; }

	UINT16 GetGvGGameRule(TCHAR* pszRule);
	VOID GetGambleReward(DT_PLAYER_RES_DATA& stWinRes, GvGRound, UINT16 wPlayerLevel);

    // ��ȡ��������Ա������
    ArenaZoneIDMap& GetArenaZoneIDMap(){ return m_mapArenZoneID; }

    // �������ɵȼ���ȡ������λ��
	UINT8 GetFormationUnlockPosNum(UINT32 dwFactionLevel);
	UINT8 GetMaxFormationPosNum();
	UINT8 GetNeedFactionLevelByPosNum(UINT8 byPosNum);
	BOOL GetGiftProp(UINT8 byID, SGvGGiftProp& stProp); 

    // ������ն����ȡ�Ź�
	UINT32 GetContinuKillDoorsTribute(UINT16 wKillCombo);

    // ������ն����ȡ����
    UINT16 CalcScoreByKillCombo(GvGRound eRound, UINT16 wKillCombo);

    // ������ն����ȡ��Ѫ�ٷֱ�
    UINT16 CalcRecoverHPByKillCombo(UINT16 wKillCombo);

    // ������ն����ȡ����ֵ
    UINT8 GetEnegyByKillCombo(UINT16 wKillCombo);

    // ������ն����ȡ��������
    UINT8 GetWeakPercentByKillCombo(UINT16 wKillCombo);

    // ��ҵ��ﵽ��ǰ��ն�����Ƿ��ø�Ϊ����
    BOOL IsMoreWeaker(UINT16 wKillCombo);

    // ��ȡ��������Ҫ�����ҵȼ�
	UINT16 GetHonorLevel();

    // ��ȡĳ��������սָ���׶εĿ���ʱ��
    UINT64 GetStageStartTime(UINT64 qwActivityStartTime, GVG_STAGE);

    // α��������ս�Ļʱ�䣬�������ڲ���
    void FakeGvGTime(UINT64 qwActivityStartTime, GVG_STAGE);

    // ��ȡָ����Ļ����ʱ��
    UINT64 GetOpenDateBySession(UINT16 wSessionID);

    // ��ȡָ�������Ļ����ʱ��
    UINT64 GetOpenDateByArena(ArenaID);

    // ��ȡָ�����Ļ����ʱ��
    UINT64 GetOpenDateByZone(ZoneID);

    // ��ȡָ����������
    const std::string& GetZoneName(ZoneID);

    // ��ȡָ��������������id
    ArenaID GetArenaIDByZoneID(ZoneID);

    // ��ȡ����������ս�������ҵȼ�
    UINT16 GetJoinGVGPlayerLevel(){ return m_stGvGProp.wJoinGVGPlayerLevel; }
    
    // ��ȡ�����������ս��������ɵȼ�
    UINT32 GetJoinGVGFactionLevel(){ return m_stGvGProp.dwJoinGVGFactionLevel; }

    // ��ȡ�����������ս�������������
    UINT32 GetJoinGvGRank(){ return m_stGvGProp.dwJoinGVGRank; }

    // �Ƿ�α��������ս�ʱ��
    BOOL IsFakeTime(){ return m_stGvGProp.bFakeActTime; }

    // �Ƿ��ڲ���ģʽ
    BOOL IsTest(){ return m_stGvGProp.bTest; }

    // �����ĸ���Ա���Ƿ���ѿ��ſ������ս
    BOOL IsArenaOpenUp(ArenaID);

    // ��ӡ��ָ��������δ���ſ������ս�ĳ�Ա���б�
    void PrintNotOpenUpArenaZone(ArenaID);

    // ��ȡ��������
    UINT16 GetUnLockSession(ArenaID);

    // ת���ɿͻ����������ʾ�����ɿ��ս����
    VOID ConvertToClientDisplayTimeByDate(UINT64 qwOpenDate);
    VOID ConvertToClientDisplayTime(UINT16 wSession);

    // ���ִ�ʱ���ת��Ϊ�׶�ʱ��㣬�Է������˽��ж�ʱ
    BOOL TranslateIntoStageSchedule();

public:
    // ��������
    BOOL LoadGvGPropDB();
    
    // �������ִ�ʱ������
    BOOL LoadGvGTimePropDB();
    
    // ����������ʱ������
    BOOL LoadGvGOpenDatePropDB();
    
    // �������������ʱ������
    BOOL LoadGvGUnLockPropDB();
    
    // ������ն��������
    BOOL LoadGvGKillComboPropDB();
    
    // ��������������������
    BOOL LoadGvGArenaPropDB();
    
    // �������ɲ�����λ��������
	BOOL LoadGvGFormationPropFromDB();
    
    // �����������
    BOOL LoadGvGGiftPropFromDB();
    
    // ����Ѻע��������
	BOOL LoadGvGGambleAwardPropFromDB();
    
    // ������������
    BOOL LoadZoneNameDB();

private:
    VOID Clear();

private:
    // �������ս����������
    SGvGProp m_stGvGProp;

	TCHAR m_aszGvGRule[MAX_GVG_RULE]; //GVG����
	C88Map m_mapFormationProp;	      //���ɵȼ���Ӧ������λ�ý�����
	C88Map m_mapPosNumToFactionLevel; //λ�ö�Ӧ�����ɵȼ�
	CMapGvGGiftProp m_mapGvGGiftProp; //���ɽ�������

    // ���ɿ��ս����ִ�ʱ���
    SGvGRoundTimeVec m_vecRoundTime;

    // ���ɿ��ս����׶�ʱ���
    GvGStageTimeVec m_vecStageTime;

    // ��Ҵﵽĳ����ն����Ӧ�Ľ���
    SKillComboVec m_vecKillCombo;

    // �ͻ����������ʾ�����ɿ��ս���ȣ������������ڷ�����ͻ���ͬ����ע�⣬���ʱ����������ò����ģ���
    DT_GVG_SCHEDULE_INFO m_stDisplaySchedule;

    // ��̨������ÿ����̨������Ա
    ArenaZoneIDMap m_mapArenZoneID;

    // ��¼ÿ�������������ĸ�����
    ZoneIDToArenaIDMap m_mapZoneIDToArenaID;

    // �����Ŀ�������
    GvGOpenDateVec m_vecOpenDate;

    // ���������Ľ�������
    UnLockMap m_mapUnLock;

    // ���������б�
    ZoneNameMap m_mapZoneName;

    // Ѻע�����б�
    SGvGGambleAwardVec m_vecGambleAward;
};

#endif //_gvgpropmgr_h_