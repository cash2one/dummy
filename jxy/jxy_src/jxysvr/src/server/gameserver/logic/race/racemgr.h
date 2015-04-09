
#ifndef _RACEMGR_H_
#define _RACEMGR_H_

#include "race.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <map>

using namespace SGDP;
using namespace std;

class CRaceBattleLog;

typedef HashMap<UINT32, CRace*> CID2RaceMap;
typedef CID2RaceMap::iterator	CID2RaceMapItr;

typedef HashMap<UINT64, CRaceBattleLog*> CID2RaceBattleLogMap;
typedef CID2RaceBattleLogMap::iterator	CID2RaceBattleLogMapItr;

struct SPlayerBaseData;
typedef map<UINT32, SPlayerBaseData*> CRank2PlayerBaseDataMap;//��map(HashMap����������)�� keyΪrank
typedef CRank2PlayerBaseDataMap::iterator CRank2PlayerBaseDataMapItr;

typedef vector<SPlayerBaseData*> CRank2PlayerBaseDataVector;
typedef CRank2PlayerBaseDataVector::iterator CRank2PlayerBaseDataVectorItr;


typedef map<UINT32, SPlayerBaseData*> CRepeatRank2PlayerBaseDataMap;//��map(HashMap����������)�� keyΪ���ID
typedef CRank2PlayerBaseDataMap::iterator CRepeatRank2PlayerBaseDataMapItr;

// ����ʱ��������߾���������б�
typedef map<UINT32, CPlayer*> COfflineRacerMap;                // key = ������val = ���ߵľ��������

// ����ʱ��������߾�������һ�����Ϣ�б�
typedef map<UINT32, SPlayerBaseData> COfflineRacerBaseDataMap; // key = ������val = ���߾�������ҵĻ�����Ϣ

class CPlayerBaseDataCacheMgr;
class CGSProcessor;
class CRaceMgr
{
	friend class CPlayerBaseDataCacheMgr;
	friend class CGSProcessor;
public:
    DECLARE_SINGLETON(CRaceMgr)

    BOOL Init();

    VOID UnInit();
public:
    // ���뾺������ǰ����(һ����ǰ100��)��������¼�����ս��
    VOID LoadTopRacerPower();

    // ����������ʱ����������������Ļص�
    VOID OnLoadOfflineRacerAtStartUp(CPlayer *poOfflineRacer);

private:
    // ����������ʱ��ǰ���������ȫ������ɹ�
    VOID OnAllOfflineRacerLoaded();

    // ������ʱ����ľ����������յ�
    VOID ClearOfflineRacerAtStartUp();

    // ������ʱ����ľ������������ս����д�����ݿ�
    VOID SaveOfflineRacerPowerAtStartUp();

    // ��ӡ������������¾�ս���Ա��б�������ս��ǰ��ƥ����������
    UINT16 EchoRacerPowerComparison();

public:
	UINT32		GetNewRankID() { return ++m_dwMaxRank; };//��ȡ����
	VOID		ReturnRankID() { if(m_dwMaxRank > 0) { m_dwMaxRank--; } };//�黹����

	SPlayerBaseData* GetPlayerBaseData(UINT32 dwRank);

	BOOL		CkOutChallengeRang(UINT32 dwMyselfRank, UINT32 dwEnemyRank);//����Ƿ񳬳���ս��Χ,TRUEΪ������Χ

	VOID		GetChallengePlayerData(UINT32 dwPlayerID, DT_CHALLENGE_PLAYER_DATA& stDT_CHALLENGE_PLAYER_DATA);
	VOID		GetChallengePlayerData(const SPlayerBaseData* pstPlayerBaseData, DT_CHALLENGE_PLAYER_DATA& stDT_CHALLENGE_PLAYER_DATA);

	BOOL		Challenge(CPlayer* poMyself, CPlayer* poEnemy, DT_BATTLE_DATA5& stDT_BATTLE_DATA, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallengeEncourage);	
    BOOL		Challenge2(CPlayer* poMyself, CPlayer* poEnemy, DT_BATTLE_DATA3& stDT_BATTLE_DATA, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallengeEncourage);	
	BOOL		Challenge3(CPlayer* poMyself, CPlayer* poEnemy, DT_BATTLE_DATA4& stDT_BATTLE_DATA, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallengeEncourage);	
	SPlayerBaseData* GetRankPlayerBaseData(UINT32 dwRank);
public:
	VOID		GetChallengePlayerList(UINT32 dwRank, UINT8& byChallengeNum, DT_CHALLENGE_PLAYER_DATA astChallengePlayerList[]);
	UINT16		GetSHowRank(UINT8& byShowNum, DT_RANK_DATA astRankShowInfo[MAX_RANK_SHOW_NUM]);
	
protected:
	BOOL		OnChallenge(CRace* poChallenge, CRace* poBeChallenge ,BOOL bChallengeSuccess);//��ս�ص�
protected:
    CRaceMgr();
    ~CRaceMgr();
	BOOL InitEvent();


private:
	CRank2PlayerBaseDataMap	m_mapRank2PlayerBaseData; //keyΪRank
	UINT32					m_dwMaxRank;//��ǰ�������

    COfflineRacerMap         m_mapOfflineRacerAtStartUp;    // ����������ʱ����ľ�����ǰ������ұ�
    UINT16                   m_wLastOfflineRacerRank;       // ����������ʱ��������һ��������ҵ�����
    COfflineRacerBaseDataMap m_mapOfflineRacerBaseData;     // ���߾�������ҵĻ�����Ϣ
};



#endif

