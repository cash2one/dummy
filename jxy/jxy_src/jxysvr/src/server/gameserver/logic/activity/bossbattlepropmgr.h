
#ifndef _BOSSBATTLEROPMGR_H_
#define _BOSSBATTLEROPMGR_H_


#include <common/client/commondef.h>
#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>
#include <map>

using namespace std;

struct SBossBProp
{
	UINT8	byActivityId;		//�ID(ÿ��Ĳ�ͬʱ��ID)
	UINT16	wBossMonsterID;		//boss����ID
	UINT16	wBossStartLevel;	//boss��ʼ�ȼ�
	UINT16	wBossMaxLevel;		//boss���ȼ�
	UINT8	byStartHour;		//��ʼʱ��Сʱ
	UINT8	byStartMin;			//��ʼʱ���	
	UINT16	wKeepTime;			//����ʱ�䣬��λ��
	
	UINT32	dwStartTime;		//��ʼʱ��
	UINT32	dwEndTime;			//����ʱ��	
	UINT32	dwStartEnterTime;	//��ʼ�ɽ���ʱ��

	UINT16	wBirthPosX;			//������X
	UINT16	wBirthPosY;			//������Y
	UINT8	byShowNum;			//ͬ����ʾ����Ҹ���
	UINT16	wReliveCD;			//����CD
	UINT16	wGoldReliveCD;		//Ԫ���������CD
	UINT16	wReliveGold;		//����Ԫ��
	UINT16	wMoveMinCD;			//�ƶ�CD����λ����	
	UINT16	wMoveMaxLen;		//ÿ���ƶ���󳤶ȣ���λ
	UINT16	wMaxReadyPosY;		//׼�������Y���꣬��λ
	UINT16	wReadyCD;			//׼��CD����λ��
	UINT16	wUpgradeCostMaxKillSecs; //boss��������ɱʱ��
	UINT32	wHPPerGrid;			//ÿ��Ѫ����Ѫ��
	UINT16  wIncCostStory;		//����ս����������
	UINT16  wIncCostGold;		//����ս������Ԫ��
	UINT16  wCanIncPowerRate;	//������ս���ٷֱ�
	UINT16	wDealNum;			//ÿ��run�������
	UINT16	wDealInterval;		//����������λ���룩
	UINT16	wOpenActivityPassDay;//�������쿪���
};

typedef map<UINT8, SBossBProp> CBossBPropMap;
typedef CBossBPropMap::iterator CBossBPropMapItr;

typedef map<UINT32, SBossBProp> CBossBActivityTimePropMap;//keyΪdwStartTime/dwEndTime
typedef CBossBActivityTimePropMap::iterator CBossBActivityTimePropMapItr;
typedef CBossBActivityTimePropMap::const_iterator CBossBActivityTimePropMapCItr;

class CBossBattlePropMgr : public CBasePopMgr
{
public:

	DECLARE_SINGLETON_PROPMGR(CBossBattlePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_BOSSB ; }

	BOOL Init();

	VOID UnInit();
public:
	SBossBProp* GetBossBPropByID(UINT8 byActivityId);
	CBossBPropMap& GetBossBPropMap() { return m_mapBossBProp; }
	const SBossBProp* GetActivityTimeProp(UINT64 qwEnterTime = SDTimeSecs()); //��ȡ����ʱ�䴦�ڵĻʱ������ã�����ǰ���ڻʱ�����򷵻�NULL
	const CBossBActivityTimePropMap& GetBossBStartTimeProp() { return m_mapBossBStartTimeProp; }
	const CBossBActivityTimePropMap& GetBossBEndTimeProp() { return m_mapBossBEndTimeProp; }
	const SBossBProp* GetNextActivityTimeProp(UINT64 qwStartTime = SDTimeSecs()); //��ȡָ��ʱ���ʼ�Ļʱ�������, ������Ѿ�û�л�򷵻�����ĵ�һ���

public:
	CBossBattlePropMgr();
	virtual ~CBossBattlePropMgr();

protected:
	BOOL LoadBossBPropFromDB();
	VOID Clr();

private:

	CBossBPropMap m_mapBossBProp;
	CBossBActivityTimePropMap	m_mapBossBStartTimeProp;
	CBossBActivityTimePropMap	m_mapBossBEndTimeProp;

};

#endif // 
