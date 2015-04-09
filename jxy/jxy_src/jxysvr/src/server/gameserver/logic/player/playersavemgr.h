
#ifndef _PLAYERSAVEMGR_H_
#define _PLAYERSAVEMGR_H_

#include "player.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <logic/base/basedefine.h>

using namespace SGDP;


#define MAX_PLAYERSAVEDATA_POOL_NUM	100

class CPlayerSaveData
{
public:
	CPlayerSaveData()
	{ 
		m_wErrCode = 0; 
		memset(&m_stPlayerData, 0, sizeof(m_stPlayerData));
		//memset(&m_stLastPlayerData, 0, sizeof(m_stLastPlayerData));
		m_bAddOnlineTime=FALSE;
	}
	~CPlayerSaveData(){};
public:
	DT_PLAYER_DATA		m_stPlayerData;
	//DT_PLAYER_DATA		m_stLastPlayerData;
	UINT16				m_wErrCode;
	BOOL				m_bAddOnlineTime;
};

typedef HashMap<UINT32, CPlayerSaveData*> CID2PlayerSaveDataMap; //keyΪplayerid
typedef CID2PlayerSaveDataMap::iterator CID2PlayerSaveDataMapItr;

struct SPlunderSaveData
{
	SPlunderSaveData() { dwPlayerID = 0; memset(&stPlunderBaseData, 0, sizeof(stPlunderBaseData)); memset(&stPlunderBattleLog, 0, sizeof(stPlunderBattleLog)); 
		memset(&stCaptureData, 0, sizeof(stCaptureData)); memset(&stEnemyData, 0, sizeof(stEnemyData)); }
	~SPlunderSaveData(){};

	UINT32 dwPlayerID;
	DT_PLUNDER_BASE_DATA stPlunderBaseData; //�Ӷ������Ϣ
	DT_PLUNDER_BATTLELOG_DATA_LIST stPlunderBattleLog; //�Ӷ�ս����Ϣ
	DT_CAPTURE_DATA_LIST stCaptureData; //�Ӷ��²��Ϣ
	DT_ENEMY_DATA_LIST stEnemyData; //�����Ϣ	
};

class CPlayersPlunderSaveData
{
public:
	CPlayersPlunderSaveData(){ m_wErrCode = 0; m_vecPlunderSaveData.clear();}; 
	~CPlayersPlunderSaveData(){};
public:
	vector<SPlunderSaveData*> m_vecPlunderSaveData;

	UINT16				m_wErrCode;
};


struct SRaceSaveData
{
	SRaceSaveData() { dwPlayerID = 0; memset(&stRaceData, 0, sizeof(stRaceData)); memset(&stRaceBattleLog, 0, sizeof(stRaceBattleLog)); }
	~SRaceSaveData(){};

	UINT32 dwPlayerID;
	DT_RACE_BASE_DATA     stRaceData; //��Ҿ�������Ϣ
	DT_RACE_BATTLELOG_DATA_LIST stRaceBattleLog; //��Ҿ�����ս����Ϣ
};

class CPlayersRaceSaveData
{
public:
	CPlayersRaceSaveData(){ m_wErrCode = 0; m_vecRaceSaveData.clear();}; 
	~CPlayersRaceSaveData(){};
public:
	vector<SRaceSaveData*> m_vecRaceSaveData;

	UINT16				m_wErrCode;
};


//ָ���洢�����ݿ�����
enum ESaveDBType
{
	ESDBT_GAME=0, //��Ϸ���ݿ�
	ESDBT_RECORD, //�ɼ����ݿ�
};

class CPlayerSaveMgr
{
public:
	DECLARE_SINGLETON(CPlayerSaveMgr)

protected:
	CPlayerSaveMgr();
	~CPlayerSaveMgr();
public:
	BOOL Init();
	VOID UnInit();

public:
	BOOL	SavePlayerData( CPlayer* poPlayer, ESaveDBType type = ESDBT_GAME, DT_PLAYER_DATA *pstDT_PLAYER_DATA = NULL);//������һ�����Ϣ
	
	BOOL	SavePlayerNoPvPData(CPlayer* poPlayer, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);

    BOOL	SavePlayerPvPData(CPlayer* poPlayer, DT_PLAYER_PVP_DATA& stPlayerPvpData);

	VOID	SaveAllPlayerPvpData();

	//DT_PLAYER_DATA	GetPlayerData( CPlayer* poPlayer);
public:
	//////////////////////////////////////////////////////////
	VOID	AddPlayerPlunderSaveData(CPlayer* poPlayer1, CPlayer* poPlayer2 = NULL, CPlayer* poPlayer3 = NULL);//��������Ӷ������Ϣ
	VOID	AddPlayerRaceSaveData(CPlayer* poPlayer1, CPlayer* poPlayer2 = NULL);//������Ҿ�����������Ϣ
	//////////////////////////////////////////////////////////

	BOOL	OnSavePlayerDataAck(UINT32 dwPlayerID, CPlayerSaveData* poPlayerSaveData);//�������ACK����
	BOOL	OnSavePlayerDataAck(CPlayersPlunderSaveData* poPlayersPlunderSaveData);//�������ACK����
	BOOL	OnSavePlayerDataAck(CPlayersRaceSaveData* poPlayersRaceSaveData);//�������ACK����
public:	
	BOOL	GetPlayerBaseSaveData(CPlayer* poPlayer, DT_PLAYER_BASE_DATA& stPlayerBaseData);//��ȡҪ������һ�����Ϣ
	BOOL	GetPlayerTodayConsumeData(CPlayer* poPlayer, DT_PLAYER_TODAY_CONSUME_DATA &stDT_PLAYER_TODAY_CONSUME_DATA);//��ȡҪ������һ�����Ϣ
	BOOL	GetExchangeResultLog (CPlayer* poPlayer, DT_EXCHANGE_RESULT_LOG& stDT_EXCHANGE_RESULT_LOG);//��ȡҪ������һ�����Ϣ

	BOOL	GetHeroSaveData(CPlayer* poPlayer, DT_HERO_DATA_LIST& stHeroData);//��ȡҪ�����佫��Ϣ
	BOOL	GetBuildSaveData(CPlayer* poPlayer, DT_BUILD_DATA_LIST& stBuildData);//��ȡҪ���潨����Ϣ	
	BOOL	GetInstanceRecordSaveData(CPlayer* poPlayer, DT_INSTANCE_DATA_LIST& stCommonInstanceData, DT_INSTANCE_DATA_LIST& stEliteInstanceData, 
		DT_INSTANCE_DATA_LIST& stClimbTowerInstanceData, DT_INSTANCE_DATA_LIST& stOutBoundInstanceData);//��ȡҪ���渱����¼��Ϣ
	//BOOL	GetBagSaveData(CPlayer* poPlayer, DT_BAG_DATA& stBagData);//��ȡҪ���汳����Ϣ
	BOOL	GetBagItemSaveData(CPlayer* poPlayer, DT_BAG_EQUIP_DATA_LST& stBagEquipData, DT_BAG_GOODS_DATA_LST& stBagGoodsData, DT_BAG_JEWELRY_DATA_LST& stBagJewelryData);//��ȡҪ���汳��������Ϣ	
	BOOL	GetTaskSaveData(CPlayer* poPlayer, DT_TASK_DATA_LIST& stTaskData);//��ȡҪ����������Ϣ
	BOOL	GetRaceSaveData(CPlayer* poPlayer, DT_RACE_BASE_DATA& stRaceData);//��ȡҪ���澺����Ϣ
	BOOL	GetLocaleSaveData(CPlayer* poPlayer, DT_LOCALE_DATA& stLocaleData);//��ȡҪ���浱ǰλ����Ϣ
	BOOL	GetStateSaveData(CPlayer* poPlayer, DT_STATE_DATA& stStateData);//��ȡҪ���浱ǰ״̬��Ϣ
	BOOL	GetOnlineEncRecd(CPlayer* poPlayer, DT_ONLINE_ENCOURAGE_RECORD_DATA& stOnlineRecd);//��ȡҪ�������߽�����Ϣ
	BOOL	GetLoginEncRecd(CPlayer* poPlayer, DT_LOGIN_ENCOURAGE_RECORD_DATA& stLoginRecd);//��ȡҪ�����¼������Ϣ
	BOOL	GetOnhookRecd(CPlayer* poPlayer, DT_ONHOOK_RCD_DATA& stOnhookRcdData);//��ȡҪ����һ���Ϣ
	BOOL	GetRaceBattleLog(CPlayer* poPlayer, DT_RACE_BATTLELOG_DATA_LIST& stRaceBattleLog);//��ȡҪ���澺����ս����Ϣ
	BOOL	GetPlunderBase(CPlayer* poPlayer, DT_PLUNDER_BASE_DATA& stPlunderBaseData);//��ȡҪ�����Ӷ������Ϣ
	BOOL	GetPlunderBattleLog(CPlayer* poPlayer, DT_PLUNDER_BATTLELOG_DATA_LIST& stPlunderBattleLog);//��ȡҪ�����Ӷ�ս����Ϣ
	BOOL	GetPlunderCapture(CPlayer* poPlayer, DT_CAPTURE_DATA_LIST& stCaptureData);//��ȡҪ�����²��Ϣ
	BOOL	GetEnemy(CPlayer* poPlayer, DT_ENEMY_DATA_LIST& stEnemyData);//��ȡҪ��������Ϣ
	BOOL	GetMoneyTree(CPlayer* poPlayer, DT_MONEY_TREE_DATA& stMoneyTreeData);//��ȡҪ����ҡǮ����Ϣ
	BOOL	GetAwaken(CPlayer* poPlayer, DT_AWAKEN_DATA& stAwaken);//��ȡҪ���������Ϣ	
	BOOL	GetMaxBattleRecord(CPlayer* poPlayer, DT_INSTANCE_BATTLE_DATA& stCommonBattleRcd, DT_INSTANCE_BATTLE_DATA& stEliteBattleRcd, DT_INSTANCE_BATTLE_DATA& stClimbTowerBattleRcd);//��ȡҪ�������ս����¼��Ϣ	
	BOOL	GetJingJieSaveData(CPlayer* poPlayer, DT_JINGJIE_DATA& stJingJieData);//��ȡҪ���澳����Ϣ	
	BOOL	GetPhystrengthSaveData(CPlayer* poPlayer, DT_PHYSTRENGTH_DATA& stPhystrengthData);//��ȡҪ����������Ϣ	
	BOOL	GetCropSaveData(CPlayer* poPlayer, DT_CROP_DATA& stDT_CROP_DATA);//��ȡ��ֵ��Ϣ
	BOOL	GetFewParamSaveData(CPlayer* poPlayer, DT_FEW_PARAM_DATA& stFewParamData);//��ȡҪ����ϡ�ٲ�����Ϣ	
	BOOL	GetScienceTreeSaveData( CPlayer *poPlayer, DT_SCIENCE_TREE_DATA &stScienceTreeData ); //��ȡ�Ƽ�������Ϣ
	BOOL	GetFormationSaveData( CPlayer *poPlayer, DT_NEW_FORMATION_DATA &stFormationData ); //��ȡҪ����������Ϣ
	BOOL	GetYabiaoSaveData( CPlayer *poPlayer, DT_YABIAO_BASE_DATA &stYabiaoData ); //��ȡҪ����Ѻ����Ϣ
	BOOL	GetEatBreadSaveData( CPlayer *poPlayer, DT_EAT_BREAD_DATA &stEatBreadData ); //��ȡҪ����԰�����Ϣ
	BOOL	GetYabiaoBattleLogData( CPlayer *poPlayer, DT_YABIAO_BATTLELOG_DATA_LIST &stYabiaoBattleLogData ); //��ȡҪ����Ѻ��ս����Ϣ
	BOOL	GetClimbTowerSaveData(CPlayer* poPlayer, DT_CLIMB_TOWER_DATA & stDT_CLIMB_TOWER_DATA); //��ȡҪ����������Ϣ
	BOOL	GetActivityRecordDataSaveData(CPlayer* poPlayer, DT_LUAACTIVITY_RECORD_LIST_DATA & stActivityRecordData); //��ȡҪ����lua�ű����¼��Ϣ
	BOOL	GetVipExtData( CPlayer *poPlayer, DT_VIP_EXT_DATA &stDT_VIP_EXT_DATA );
	BOOL	GetCollectGas( CPlayer *poPlayer, DT_COLLECT_GAS_DATA &stCollectGas ); //��ȡҪ���漯����Ϣ	
	BOOL	GetActivityEncourageData( CPlayer *poPlayer, DT_ACTIVITY_ENCOURAGE_DATA &stActivityEncourage ); //��ȡҪ����������Ϣ
	BOOL	GetBossBBase(CPlayer* poPlayer, DT_BOSS_BATTLE_PLAYER_DATA& stBossBattlePlayerData); //��ȡҪ����bossս������Ϣ
	BOOL	GetBossBBLData(CPlayer* poPlayer, DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST& stBossBBLData); //��ȡҪ����bossսս����Ϣ
	BOOL	GetRdChallengeData(CPlayer* poPlayer, DT_RANDOM_CHALLENGE_DATA& stRdChallengeData); //��ȡҪ���������ս��Ϣ
	BOOL	GetWorshipData(CPlayer* poPlayer, DT_WORSHIP_DATA_LST& stWorshipData); //��ȡҪ����Ĥ����Ϣ
	BOOL	GetScoreData(CPlayer* poPlayer, DT_SCORE_DATA_LST& stScoreData); //��ȡҪ����������Ϣ
	BOOL	GetEquipCompose(CPlayer* poPlayer, DT_EQUIP_COMPOSE_DATA& stEquipComposeData); //��ȡҪ����װ���ϳ���Ϣ
	BOOL	GetGatherScience(CPlayer* poPlayer, DT_GATHER_SCIENCE_DATA &stGatherScienceData); //��ȡҪ����ۻ���Ϣ
	BOOL GetBegBlue(CPlayer* poPlayer, DT_BEGBLUE_DATA &stBegBlueData); //��ȡҪ��������¶��Ϣ
	BOOL GetFriendsBaseData(CPlayer* poPlayer, DT_FRIENDS_BASE_DATA& stDT_FRIENDS_BASE_DATA); //��ȡҪ��������ʻ���Ϣ 
	BOOL GetRelationDataList(CPlayer* poPlayer, DT_RELATION_DATA_LIST &stRelationDataList); //��ȡҪ�����������ѹ�ϵ
	BOOL GetDataEvenList(CPlayer* poPlayer, DT_DATA_EVEN_LIST &stDataEvenList); //��ȡҪ�����������ѹ�ϵ
    BOOL GetRecvFlowerLogList(CPlayer* poPlayer, DT_RECV_FLOWER_LOG_LIST &stRecvFlowerLogList); //��ȡ����ջ���־
	BOOL GetEquipMaster(CPlayer &oPlayer, DT_EQUIP_MASTER&); //��ȡװ����ͨ��Ϣ
	BOOL GetCourageData(CPlayer* poPlayer, DT_COURAGE_DATA &stDT_COURAGE_DATA); //��ȡ������Ϣ
	BOOL GetFactionPlayer(CPlayer* poPlayer, DT_PLAYER_FACTION_DATA& stPlayerFaction);//��ȡ������Ϣ
	BOOL GetPlayerMark( CPlayer* poPlayer, DT_PLAYER_MARK_DATA& stPlayerMark);	//��־��Ϣ
	BOOL GetPlayerGVG(CPlayer* poPlayer, DT_PLAYER_GVG_DATA& stGVGData);
	BOOL GetPlayerSoul(CPlayer* poPlayer, DT_PLAYER_SOUL_DATA& stSoulData);
	BOOL GetPlayerMedal(CPlayer* poPlayer, DT_PLAYER_MEDAL_DATA& stMedalData);
	BOOL GetPlayerPet(CPlayer* pPlayer, DT_PLAYER_PET_DATA& rPetData);

protected:
	VOID	SavePlayersPlunderData();
	VOID	SavePlayersRaceData();

private:
	CID2PlayerSaveDataMap							m_mapID2PlayerSaveData;
	CSDObjectPool<CPlayerSaveData, CSDMutex>			m_oPlayerSaveDataPool;	
	CSDObjectPool<SPlunderSaveData, CSDMutex>		m_oPlunderSaveDataPool;	
	CSDObjectPool<CPlayersPlunderSaveData, CSDMutex> m_oPlayersPlunderSaveDataPool;	
	CSDObjectPool<SRaceSaveData, CSDMutex>			m_oRaceSaveDataPool;	
	CSDObjectPool<CPlayersRaceSaveData, CSDMutex>	m_oPlayersRaceSaveDataPool;	
	HashMap<UINT32, UINT32> m_mapPlunderChangePlayer;
	HashMap<UINT32, UINT32> m_mapRaceChangePlayer;
	UINT32		m_dwPvpSaveNum;//pvpÿ�α������
// 	HashMap<CPlayersPlunderSaveData*, CPlayersPlunderSaveData*> m_mapSavingPlayersPlunder;
// 	HashMap<CPlayersRaceSaveData*, CPlayersRaceSaveData*> m_mapSavingPlayersRace;
};


#endif

