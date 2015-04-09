
#ifndef _FACTORPROP_H_
#define _FACTORPROP_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <string>
#include <protocligs.h>
#include "common/client/commondef.h"
#include "logic/base/basedefine.h"
#define ICON_CROWN 4
#define ICON_SUN 3
#define ICON_MOON 2
#define ICON_STAR 1

//�����
struct SShadeTaskInfoProp
{
    UINT32 dwTaskID;		//�ID
    TCHAR  aszTaskName[16];	//�����
    UINT8	byStartHour; //���ʼʱ��Сʱ
    UINT8	byStartMin; //���ʼʱ���
    UINT16	wKeepTime; //�����ʱ�䣬��λ��

    UINT32	dwStartTime; //��ʼʱ��(byStartHour+byStartMin������)
    UINT32	dwEndTime; //����ʱ��(dwStartTime+wKeepTime)
    TCHAR   aszTaskDesc[TASK_DESCRIBE_MSG_LEN];
};

//������
struct STaskRewardProp
{
    UINT8 byShadeLevel;
    UINT8 byCollectiveTaskSchedule;			//����
    UINT32 dwMaxIntegral;					//������
    UINT8 byRewardType;						//��Ʒ����
    UINT32 dwReardValue;					//ֵ
};

struct SFactionUpgradeProp
{
    UINT32 dwFactionLevel;
    UINT32 dwNeedFactionFunds;
    UINT32 dwFactionPlayerMaxNum;
    UINT8 byRareitemMark;
    UINT8 byGymnasiumMark;
    UINT8 byShadeMark;
    UINT8 byHotSpringMark;
    UINT8 byColdPrison;
    UINT8 byFactionTower;
    UINT8 byCoinTimeByDay;
};
//���׽���
struct SDonateRewardProp
{
    UINT8 byFactionLevel;
    UINT8 byRewardType;
    UINT32 dwRewardValue;
    UINT8 byNum;
};

struct SFactinJobNumProp
{
    UINT8 byFactionLevel;
    UINT8 byMartialHead;
    UINT8 byProxyMartialHead;
    UINT8 byElder;
    UINT8 byCustodian;
    UINT8 byElite;
    UINT8 byNormal;
};

struct SDoorsTributeProp
{
	UINT16 wDoorsTributeLevel;
	UINT64 qwDoorsTributeValue;
};

typedef map<UINT64, UINT16> CMapDoorsTributeProp;
typedef CMapDoorsTributeProp::iterator CMapDoorsTributePropItr;

typedef map<UINT8 , SFactinJobNumProp> CMapFactionJobNum;
typedef CMapFactionJobNum::const_iterator CMapFactionJobNumItr;

typedef multimap<UINT8, SDonateRewardProp> CMapDonateReward;
typedef CMapDonateReward::const_iterator CMapDonateRewardItr;
typedef map<UINT32, SFactionUpgradeProp> SFactionUpgradePropMap;
typedef SFactionUpgradePropMap::iterator SFactionUpgradePropItr;
typedef map<UINT32, SShadeTaskInfoProp> SShadeTaskInfoPropMap;
typedef map<UINT32, SShadeTaskInfoProp>::iterator SShadeTaskInfoPropItr;
typedef multimap<UINT8, STaskRewardProp> STaskRewardPropMap;
typedef multimap<UINT8, STaskRewardProp>::iterator STaskRewardPropItr;

class CFactorPropMgr
{
public:
    DECLARE_SINGLETON(CFactorPropMgr);

public:

    BOOL Init();

    VOID UnInit();

public:
    //ͭǮÿ��������ȡ�Ĵ���
    UINT16	GetCoinMaxTimeEveryDay(UINT32 dwFactionLevel);

    //Ԫ��ÿ��������ȡ�Ĵ���
    UINT16	GetGoldMaxTimeEveryDay(UINT32 dwVIPLevel);

    string GetShadeTime()
    {
        return m_strShadeActiviTime;
    }
    UINT32 GetFactionPlayerMaxNum( UINT32 dwFactionLevel);
    BOOL GetTaskRewardProp(UINT8 byShadeLevel, UINT32 dwSchedule, STaskRewardProp& stTaskRewardProp);
    BOOL GetTaskInfoProp(UINT32 dwTaskID, SShadeTaskInfoProp& stShadeTaskInfo) ;
    BOOL GetFactionUpgradeProp(UINT32 dwFactionLevel, SFactionUpgradeProp& stFactionUpgrade);
    VOID InitEvent();
    const STaskRewardPropMap& GetTaskRewardMap()
    {
        return m_mapTaskRewardProp;
    }
    const CMapDonateReward& GetDonateReward()
    {
        return m_mapDonateReward;
    }
    BOOL GetFactionJobNum(UINT8 byFactionLevel, SFactinJobNumProp& stProp);
    UINT8 GetUnLockLevel(em_Faction_Build emFactionType);
	VOID GetDoorsTributeInfo(UINT64 qwDoorsTribute, DT_DOORSTRIBUTE_LEVEL_DATA& stLevelData);
	VOID GetDoorsTributeInfo(UINT64 dwValue, UINT16& wLevel, UINT32& dwNextValue);
protected:
    CFactorPropMgr();
    virtual ~CFactorPropMgr();
protected:
    BOOL LoadTaskInfoPropFromDB();
    BOOL LoadTaskRewardPropFromDB();
    BOOL LoadFactionUpgradeFromDB();
    BOOL LoadGiveWineProp();
    BOOL LoadDonateRewardProp();
    BOOL LoadFactionJobNumProp();
	BOOL LoadDoorsTributeProp();
	BOOL LoadDoorsTributeLevelProp();
private:
    CMapDonateReward m_mapDonateReward;
    CMapFactionJobNum m_mapFactionJobNum;
    string m_strShadeActiviTime;

    SShadeTaskInfoPropMap m_mapShadeTaskInfoProp;
    STaskRewardPropMap m_mapTaskRewardProp;	//��ShadeLevelΪKEY
    SFactionUpgradePropMap m_mapFactionUpgradeProp;
	CMapDoorsTributeProp m_mapDoorsTributeProp;
	C88Map m_mapDoorsTributeLevelProp;//���������ȼ�����

    UINT8			m_byUnlockLevelByRareItem;
    UINT8			m_byUnlockLevelByGymnasium;
    UINT8			m_byUnlockLevelByShade;
    UINT8			m_byUnlockLevelByHotSpring;
    UINT8			m_byUnlockLevelByColdPrison;
    UINT8			m_byUnlockLevelByFactionTower;
};




#endif //#ifndef _ROLEMGR_H_

