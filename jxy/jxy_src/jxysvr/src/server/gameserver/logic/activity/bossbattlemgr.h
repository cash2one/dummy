
#ifndef _BOSSBATTLEMGR_H_
#define _BOSSBATTLEMGR_H_

#include "bossbattle.h"
#include "bossbattlepropmgr.h"
#include <sdsingleton.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <sdobjectpool.h>
#include <protocligs.h>
#include <set>
using namespace SGDP;
using namespace std;


class CBossBattle;
class CPlayer;
class CBossBattlePropMgr;
class CMonster;
class CBossBBattleLog;
class CGSProcessor;

/**
* @brief ����������
*/
class CBossBattleMgr
{
	friend class CBossBattlePropMgr;
	friend class CGSProcessor;

public:
    DECLARE_SINGLETON(CBossBattleMgr)

    BOOL Init();

    VOID UnInit();

public:
	BOOL			OnStartEvent(UINT8 byActivityID);
	BOOL			OnEndEvent(UINT8 byActivityID);
	BOOL			Run();

	CBossBBattleLog*	CreateBattleLog();
	VOID				RemoveBattleLog(CBossBBattleLog* poBossBBattleLog);

protected:
	CBossBattleMgr();
	~CBossBattleMgr();

protected:
	BOOL InitModuleDataFromDB();
	BOOL InitModuleLogDataFromDB();
	BOOL InitEvent();
	BOOL LoadCloseArea();
public:
	//��ҽ���
	UINT16 OnEnter(CPlayer* poPlayer, UINT16 wPosX, UINT16 wPosY, DT_BOSSB_MY_DATA_CLI& stMyBossBInfo, DT_BOSSB_PLAYER_DATA_CLI_LST& stPlayerInfo,
		DT_BOSSB_DATA_CLI2& stBossBInfo, DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM], DT_HURT_ENC_DATA& stHurtEncInfo);
	//����뿪
	UINT16 OnLeave(CPlayer* poPlayer, BOOL bDisconnect = FALSE);
	//����ƶ�
	UINT16 OnMove(CPlayer* poPlayer, UINT16 wPosX, UINT16 wPosY, UINT16& wOldPosX, UINT16& wOldPosY);
	//����˺�
	UINT16 OnHurt(CPlayer* poPlayer, UINT32& dwCurHurtValue, DT_BOSSB_HURT_RATE& stMyHurtInfo, DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM],
		DT_HURT_ENC_DATA& stHurtEncInfo, UINT16& wReliveCountDown, UINT16& wGoldReliveCountDown, UINT64& dwTotalBossHP, UINT64& dwCurBossHP);
	//�򿪹������
	UINT16 OnOpenInspireTab(CPlayer* poPlayer, DT_INSPIRE_TAB_DATA& stInspireTabInfo);
	//����ս��
	UINT16 OnInspirePower(CPlayer* poPlayer, UINT8 byGoldInspireFlag, DT_INSPIRE_TAB_DATA& stInspireTabInfo);
	//����
	UINT16 OnBossBRelive(CPlayer* poPlayer);
	//��ȡ�ϴ�bossս��Ϣ
	UINT16 OnGetLastBossBInfo(CPlayer* poPlayer, DT_BOSSB_OVER_INFO2& stBossOverInfo);
	
	BOOL IsCloseArea(UINT16 wZoneID);
public:
	VOID GetBattleLog(UINT64 qwOverTime, UINT16& wBossID, DT_BOSS_BATTLE_ENC_DATA astBossBTopEncInfo[MAX_BOSS_ENC_TOP_NUM], DT_BOSS_BATTLE_ENC_DATA& stBossBKillEncInfo);
	BOOL OnSave();//����bossսģ����Ϣ
	BOOL IsOver() { return m_bActivityOver; }
	UINT8 GetLastActivityID() { return m_byLastActivityID; }

    // ���ʼʱ�ѿ�ʼ֪ͨ���������Ƶ��
    void AddChatOnActivityStart(UINT64 qwActStartTime, UINT64 qwNow);
    //�����ʱ��bossսս�����������Ƶ��
    void AddChatOnActivityOver(DT_BOSS_BATTLE_DATA& stData);
    //�Boss����ɱʱ����boss��ɱ��Ϣ���������Ƶ��
    void AddChatOnBossKilled(DT_BOSS_BATTLE_DATA& stData);
	VOID ConvertInfo2ToInfo(const DT_BOSSB_OVER_INFO2& stBossInfo2, DT_BOSSB_OVER_INFO& stBossInfo);
protected:
	//��ӹ�ע
	VOID Addattention(CPlayer* poNoticePlayer);
	//ȥ����ע
	VOID Delattention(CPlayer* poNoticePlayer);
	//��ȡ��ʾ�����Ϣ
	VOID GetShowPlayerInfo(CPlayer* poPlayer, UINT32 dwSyncStartIdx, DT_BOSSB_PLAYER_DATA_CLI_LST& stDT_BOSSB_PLAYER_DATA_CLI_LST);
	//��ȡ��ʾ�����Ϣ
	VOID GetBOSSB_PLAYER_DATA_CLI(CPlayer* poPlayer, DT_BOSSB_PLAYER_DATA_CLI& stDT_BOSSB_PLAYER_DATA_CLI);
	//�����˺�
	UINT32 CountHurtValue(CPlayer* poPlayer, DT_BOSSB_HURT_RATE& stMyHurtInfo, DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]);
    //���ʼʱ�ѿ�ʼ֪ͨ���������Ƶ��

    //�����
	VOID ActivityOver(CPlayer* poKiller = NULL);
	//������
	VOID GiveEnc(CPlayer* poPlayer, DT_BOSSB_OVER_INFO2& stNtf);
	//��ȡDT_BOSSB_MY_DATA_CLI��Ϣ
	VOID GetDT_BOSSB_MY_DATA_CLI(CPlayer* poPlayer, DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, DT_BOSSB_MY_DATA_CLI& stMyBossBInfo);
	//��ȡDT_BOSSB_DATA_CLI��Ϣ
	VOID GetDT_BOSSB_DATA_CLI(DT_BOSSB_DATA_CLI2& stBossBInfo);
	//��ȡ���������Ϣ
	VOID GetDT_INSPIRE_TAB_DATA(DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, DT_INSPIRE_TAB_DATA& stInspireTabInfo);
	//��ȡ�����ʱ
	UINT16 GetReliveCountDown(DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, UINT8 byCalculateWalk = 0);
	//��ȡԪ�������������ʱ
	UINT16 GetGoldReliveCountDown(DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA);
	//��ȡ�˺�����
	VOID GetHurtEncInfo(UINT16 wPlayerLevel, DT_BOSS_BATTLE_PLAYER_DATA& stDT_BOSS_BATTLE_PLAYER_DATA, DT_HURT_ENC_DATA& stHurtEncInfo, UINT32 dwHurtValue = 0);
	//��ȡtop�˺���Ϣ
	VOID GetTopHurtRate(DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]);
	//�������е�����
	VOID SortHurtRank();
	//����TOP�˺�������
	VOID SortTopHurt(DT_BOSSB_HURT_RATE& stMyHurtInfo);
	//ͬ����Ϣ
	VOID SyncInfo(CPlayer* poPlayer);

///////////////////////////////////////////////////////
	
protected:

private:
	CSDObjectPool<CBossBattle, CSDMutex> m_oBossBattleShmemObjMgr;	
	CSDObjectPool<CBossBBattleLog, CSDMutex> m_oBossBBLShmemObjMgr;	
	C32Vec		m_vecAllEnterPlayer; //	
	C3232Map	m_mapAllEnterPlayer; //	
	C3232Map	m_mapAllPlayer;//�������н�����
	CMonster*	m_poBoss;
	SBossBProp* m_pstCurBossBProp;//
	BOOL		m_bActivityOver;
	UINT16		m_wBossLevel;
	UINT16		m_wIncRateByStory;		//��������ս���ٷֱ�
	UINT16		m_wIncRateByGold;		//Ԫ������ս���ٷֱ�
	DT_BOSSB_HURT_RATE m_astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM];
	map<UINT8, DT_BOSS_BATTLE_DATA> m_mapBassBattleModuleData;
	map<UINT64, DT_BOSS_BATTLE_DATA> m_mapBossBBLData;
	UINT64		m_qwStartTime;
	UINT8		m_byLastActivityID;
	UINT64		m_qwBossTotalHP;
	UINT8		m_bySyncActivityID;
	UINT64		m_qwSyncCurBossHP;
	UINT64		m_qwSyncStartTime;
	BOOL		m_bSyncFlag;
	C3232MapItr	m_itrCur;

	set<UINT16> m_setCloseArea;
};




#endif //#ifndef _ROLEMGR_H_

