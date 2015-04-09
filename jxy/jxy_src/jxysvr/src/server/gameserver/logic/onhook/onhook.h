
#ifndef _ONHOOK_H_
#define _ONHOOK_H_

#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <logic/base/baseobj.h>
#include <logic/instance/instancepropmgr.h>
#include <common/server/utility.h>

#include <list>
using namespace std;
using namespace std ;

typedef HashMap<UINT16, DT_ITEM_DATA*> CKindID2ItemDataMap;//keyΪ����ID
typedef CKindID2ItemDataMap::iterator CKindID2ItemDataMapItr;

//�һ�ʱ�佫������Ϣ
struct SOnhookHeroUpgrage
{
	SOnhookHeroUpgrage() { bHaveUpgrageFlag = FALSE; memset(&stDT_HERO_UPGRADE_DATA2, 0, sizeof(stDT_HERO_UPGRADE_DATA2)); }
	BOOL bHaveUpgrageFlag;//�Ƿ�������
	DT_HERO_UPGRADE_DATA2 stDT_HERO_UPGRADE_DATA2;
};


typedef HashMap<UINT16, SOnhookHeroUpgrage> CKindID2HeroDataMap;//keyΪ�佫ID
typedef CKindID2HeroDataMap::iterator CKindID2HeroDataMapItr;


//typedef list<DT_ONHOOK_RESULT> COnHookResultList;//keyΪ�佫ID
//typedef COnHookResultList::iterator COnHookResultListItr;


enum em_OnHook
{
	em_COMMON = 0,
	em_TOWER = 1,
};


class CPlayer;
class COnhook:public CBaseObj
{
public:
	COnhook();
	~COnhook();
public:
	//��ʼ����ض���
	BOOL Init(DT_ONHOOK_RCD_DATA& stOnhookRcdData, CPlayer* poOwner);
	DT_ONHOOK_RCD_DATA& GetDT_ONHOOK_RCD_DATA() { return m_stOnhookRcdData; }
	/////////////////////////////
	VOID SetOnHookParam(UINT8 byRunTimes, DT_INSTANCE_ID* pstDT_INSTANCE_ID);
	//UINT8 GetOhhookOddRunTimes() { return m_stOnhookRcdData.stOnhookResult.byAllRunTimes - m_stOnhookRcdData.stOnhookResult.byCurRunTimes; }
	//VOID GetDT_ONHOOK_RESULT(DT_ONHOOK_RESULT& stDT_ONHOOK_RESULT) {  memcpy(&stDT_ONHOOK_RESULT, &m_stOnhookRcdData.stOnhookResult, sizeof(DT_ONHOOK_RESULT)); }
	VOID GetOnhookResult(DT_ONHOOK_RESULT& stDT_ONHOOK_RESULT, DT_DATA_AFTER_ONHOOK& stAfterOnhookData);//��ȡ��ǰ�һ����
	BOOL OnHookEncourage(UINT8 &byRunTimes);//�����һ������ص�����һ�θ����ص�һ��.����������TRUE
	VOID GetOnhookInstanceID(DT_INSTANCE_ID& stOnhookInstanceID) { memcpy(&stOnhookInstanceID, &m_stOnhookRcdData.stOnhookInstanceID, sizeof(DT_INSTANCE_ID)); }
	UINT64 GetLastOnhookResultReqTime() { return m_stOnhookRcdData.qwLastOnhookResultReqTime; }
	BOOL OnhookFlag() { return (1 == m_stOnhookRcdData.byOnhookFlag); }
	UINT16& GetLastOnhookResultReqPassSec() { return m_wLastOnhookResultReqPassSec; }
	BOOL GetPause(){ return m_bPause; }
	VOID SetPause(BOOL bPause) { m_bPause = bPause; }

protected:
	BOOL GetHookEncourage(UINT8 &byRunTimes);//����������TRUE
	VOID InitHeroMonster();
private:
	DT_ONHOOK_RCD_DATA			m_stOnhookRcdData;
	vector<SWholeMonsterProp*>*	pvecWholeMonsterProp;//�һ�����������Ϣ
	CKindID2ItemDataMap			m_mapOnhookEncourageItem;//�һ��������ߣ����ڹ���
	CKindID2HeroDataMap			m_mapOnhookUpgrageHero;	 //�һ��������佫��Ϣ
	UINT16						m_wLastOnhookResultReqPassSec;//�ϴ�����һ����ʱɨ����ȥ��ʱ��
	BOOL							m_bPause;//�Ƿ���ͣ
	//COnHookResultList				m_listOnHookResultList;
};

DECLARE_CLASS_POOL_MGR(COnhook)
#endif //#ifndef 

