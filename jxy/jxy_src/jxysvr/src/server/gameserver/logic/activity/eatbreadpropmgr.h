
#ifndef _EATBREADPROPMGR_H
#define _EATBREADPROPMGR_H


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdobjectpool.h>
#include <map>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;

using namespace SGDP;

//�԰��ӻʱ������
struct SEatBreadActivityTimeProp
{
	UINT8	byActivityKind;
	UINT8	byStartHour; //���ʼʱ��Сʱ
	UINT8	byStartMin; //���ʼʱ���	
	UINT16	wKeepTime; //�����ʱ�䣬��λ��

	UINT32	dwStartTime; //��ʼʱ��(byStartHour+byStartMin������)
	UINT32	dwEndTime; //����ʱ��(dwStartTime+wKeepTime)
};

typedef map<UINT32, SEatBreadActivityTimeProp> CEatBreakActivityTimePropMap;//keyΪdwEndTime
typedef CEatBreakActivityTimePropMap::iterator CEatBreakActivityTimePropMapItr;
typedef CEatBreakActivityTimePropMap::const_iterator CEatBreakActivityTimePropMapCItr;

class CEatBreadPropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CEatBreadPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_EATBREAD ; }

    BOOL Init();

    VOID UnInit();
public:
	inline UINT8	GetMaxObtainPhyStrengthen() { return m_byMaxObtainPhyStrengthen; }
	inline UINT32	GetMaxObtainCoin() { return m_dwMaxObtainCoin; }
	inline UINT16	GetTimePerPhyStrengthen () { return m_wTimePerPhyStrengthen; }
	inline UINT16	GetOarNumPerPhyStrengthen() { return m_wOarNumPerPhyStrengthen; }
	inline UINT32	GetOnceSpeedCoin() { return m_dwOnceSpeedCoin; }

	const SEatBreadActivityTimeProp* GetActivityTimeProp(UINT64 qwEnterTime = SDTimeSecs()); //��ȡ����ʱ�䴦�ڵĻʱ������ã�����ǰ���ڻʱ�����򷵻�NULL
	const CEatBreakActivityTimePropMap& GetEatBreadStartTimeProp() { return m_mapEatBreadStartTimeProp; }
	const CEatBreakActivityTimePropMap& GetEatBreadEndTimeProp() { return m_mapEatBreadEndTimeProp; }
	const SEatBreadActivityTimeProp* GetNextActivityTimeProp(UINT64 qwStartTime = SDTimeSecs()); //��ȡָ��ʱ���ʼ�Ļʱ�������, ������Ѿ�û�л�򷵻�����ĵ�һ���
public:
    CEatBreadPropMgr();
    virtual ~CEatBreadPropMgr();
protected:

    BOOL LoadActivityTimeFromDB();
	BOOL LoadBasePropFromDB();

private:	
	UINT8	m_byMaxObtainPhyStrengthen; //���������
	UINT32	m_dwMaxObtainCoin; //�����ͭ��
	UINT16	m_wTimePerPhyStrengthen; //��ÿɻ��1������
	UINT16	m_wOarNumPerPhyStrengthen; //�����οɻ��1������
	UINT32	m_dwOnceSpeedCoin; //1�����ɻ��ͭǮ

	CEatBreakActivityTimePropMap	m_mapEatBreadStartTimeProp;
	CEatBreakActivityTimePropMap	m_mapEatBreadEndTimeProp;

};

#endif // 
