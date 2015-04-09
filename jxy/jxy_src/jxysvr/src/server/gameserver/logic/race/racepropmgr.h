
#ifndef _RACEPROPMGR_H_
#define _RACEPROPMGR_H_

#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basedefine.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;
using namespace std;

class CPlayer;

struct tagDT_RACE_RANK_ENCOURAGE_DATA;
typedef tagDT_RACE_RANK_ENCOURAGE_DATA DT_RACE_RANK_ENCOURAGE_DATA;

struct tagDT_RACE_CHALLENGE_ENCOURAGE_DATA;
typedef tagDT_RACE_CHALLENGE_ENCOURAGE_DATA DT_RACE_CHALLENGE_ENCOURAGE_DATA;

struct SRaceBaseProp
{
	//UINT16 wMaxChallengeNumPerDay; //һ��������ս����
	UINT16 wFreeChallengeNumPerDay;//һ��������ս����
	UINT32 dwChallengeFailedCD;//��ս�������´���սCD,��λ��
	UINT32 dwClrCDGoldPerMinute;//���CDʱ��ÿ��������Ԫ��
	UINT8  byChallengeNum;//ChallengeNumΪÿ����ʾ����ս�����(�ȼ������Լ���)������������ChallengeNum����ȥ������������Ҳ��ϣ����油�ļ��1)
	UINT16 wRankShowNum;//RankShowNumΪ���а���ʾ������ǰ��������������ս
	UINT32 dwLimitRank;//LimitRankΪ�ٽ�����,������սս������(�ڸ�����������ս��2��)	
	UINT32 dwRobotID;//������ID
	UINT16 wRecvRankPassDay;//�༸��������ȡ��������
};

//��ս���������
struct SChallengeSec
{
	UINT32 dwMin; //��ʼ����
	UINT32 dwMax; //����������0��ʾ���
	UINT16 wInterval;//���
};

typedef vector<SChallengeSec> CChallengeSecVec; //��dwMix��������
typedef CChallengeSecVec::iterator CChallengeSecVecItr;

typedef HashMap<UINT32, UINT32> CChanllengeEncourageMap;//����Ϊ��ҵȼ�
typedef CChanllengeEncourageMap::iterator CChanllengeEncourageMapItr;


/**
* @brief ���������ù�����
*/
class CRacePropMgr : public CBasePopMgr
{
public:
	DECLARE_SINGLETON_PROPMGR(CRacePropMgr)

	virtual EConfigModule	GetConfigModuleType() { return ECM_RACE ; }

	BOOL Init();
	VOID UnInit();	

	UINT32	GetChallengeNum() { return m_stRaceBaseProp.byChallengeNum; }
	UINT32	GetInterval(UINT32 dwRank);//��ȡ��ս���	
	VOID	GetRankEncourage(UINT32 dwRank, DT_RACE_RANK_ENCOURAGE_DATA& stRankEncourage);
	VOID	GetChallengeEncourage(UINT32 dwPlayerLevel, BOOL bWinFlag, DT_RACE_CHALLENGE_ENCOURAGE_DATA& stChallEncourage);
	VOID	GetCanChallengeTimes(CPlayer* poPlayer, UINT64 qwLastChallTime, UINT8 byChallTimes, UINT16 wContiWin, UINT8 byFailedFlag, UINT16& wChallengeCountDown, 
		UINT16& wTotalChallengeNum, UINT16& wCanChallengeNum, UINT16& wVipExtNum, UINT16& wFreeChallengeNum, UINT32& dwChallengeNeedGold);
	SRaceBaseProp& GetRaceProp() { return m_stRaceBaseProp; }
	CChallengeSecVec& GetChallengeSecVec() { return m_vecChallengeSec; }	
public:
	CRacePropMgr();
	~CRacePropMgr();
protected:
	BOOL LoadFromDB();
	BOOL LoadRaceBaseProp();
	BOOL LoadChallengeSec();
	//BOOL LoadCRankEncourage();
	//BOOL InitChallengeEncourage();

	static BOOL MyCompare(const SChallengeSec &t1, const SChallengeSec &t2);

private:
	SRaceBaseProp		m_stRaceBaseProp;
	CChallengeSecVec	m_vecChallengeSec;//�����谴��������
	//CChanllengeEncourageMap m_mapChanllengeEncCoin;
	//CChanllengeEncourageMap m_mapChanllengeEncScience;
};



#endif
