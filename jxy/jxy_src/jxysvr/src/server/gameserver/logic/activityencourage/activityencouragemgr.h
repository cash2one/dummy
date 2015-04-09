
#ifndef _RECHARGEENCOURAGEMGR_H_
#define _RECHARGEENCOURAGEMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdmutex.h>

#include "activityencourage.h"
#include <protocligs.h>
#include "logic/base/jsonencourage.h"

//�����
enum ACTE_TYPE
{
    ACTE_RECHARGE = 1,	//�׳影��
    ACTE_SCORE = 2,		//���ֽ���
};


typedef struct tagRangPlayerID
{
    UINT32 dwStartPlayerID;
    UINT32 dwEndPlayerID;
} SRangPlayerID;

typedef std:: vector<SRangPlayerID>				CRangPlayerIDVector;
typedef CRangPlayerIDVector::iterator			CRangPlayerIDVectorItr;



typedef std::map<UINT32, UINT32>				CActivityEncouragePlayerMap; //keyΪPlayerID
typedef CActivityEncouragePlayerMap::iterator	CActivityEncouragePlayerMapItr;

typedef std::vector<string>					CActivityEncourageCdKeyVector; //keyΪLevel
typedef CActivityEncourageCdKeyVector::iterator	CActivityEncourageCdKeyVectorItr;

typedef struct tagActivityEncouragePro
{
    UINT64						qwActivityID;				//�ID
    UINT8						byNeedCdKey;
    TCHAR						szActivityName[MAX_ACTIVITY_ENCOURAGE_NAME_LEN];
    TCHAR						szActivityDesc[MAX_ACTIVITY_ENCOURAGE_DESC_LEN];
    UINT64						qwStartTime;
    UINT64						qwEndTime;
    CJsonResItemVectorInfo			vecActivityEncourageItemInfo;
    CActivityEncouragePlayerMap	mapActivityEncourageStartPlayerID;//��ȡ������PlayerID��Χ��key��ʼID�������Լ�,value����ID�������Լ�
    CActivityEncouragePlayerMap	mapActivityEncourageEndPlayerID;//��ȡ������PlayerID��Χ��key����ID�������Լ�,value����ID�������Լ�
    CActivityEncourageCdKeyVector	vecActivityEncourageCdKey;
    tagActivityEncouragePro()
    {
        Init();
    }
    void Init()
    {
        qwActivityID = 0;
        byNeedCdKey = 0;
        qwStartTime = 0;
        qwEndTime = 0;
        memset(szActivityName, 0x00, sizeof(szActivityName));
        memset(szActivityDesc, 0x00, sizeof(szActivityDesc));
        mapActivityEncourageStartPlayerID.clear();
        mapActivityEncourageEndPlayerID.clear();
        vecActivityEncourageCdKey.clear();
    }
} SActivityEncouragePro;


typedef std::map<UINT64, SActivityEncouragePro> CActivityEncouragePropMap; //keyΪdwActivityID
typedef CActivityEncouragePropMap::iterator CActivityEncouragePropMapItr;

typedef struct _tatChangeActivityEncouragePro
{
    UINT16				wZoneID;
    UINT16				wDelActivityID;
    BOOL					bChangeFlag;
    SActivityEncouragePro	stActivityEncourageProp;
    _tatChangeActivityEncouragePro()
    {
        Init();
    }
    void Init()
    {
        wZoneID = 0;
        wDelActivityID = 0;
        bChangeFlag = 0;
        stActivityEncourageProp.Init();
    }
} SChangeActivityEncouragePro;




class CActivityEncourageMgr
{
public:
    DECLARE_SINGLETON(CActivityEncourageMgr);

public:

    BOOL Init();

    VOID UnInit();
public:

    CActivityEncouragePropMap & GetNorActivityEncouragePropMap()
    {
        return m_mapActivityEncourageProp;
    }

    CJsonResItemVectorInfo & GetRechargeActivityEncourageItem()
    {
        return m_vecRechargeActivityEncourageItemInfo;
    }

    CJsonResItemVectorInfo & GetScoreActivityEncourageItem()
    {
        return m_vecScoreActivityEncourageItemInfo;
    }



    VOID SetActivityEncouragePropMap(CActivityEncouragePropMap	 &mapActivityEncourageProp);

    VOID AddActivityProp(SActivityEncouragePro& stActivityEncouragePro);
//    VOID DeleteActivityProp(UINT64 dwActivityID);

    VOID AddPlayerActivity(UINT64 dwActivityID, UINT32 dwStartPlayerID, UINT32 dwEndPlayerID);

    SActivityEncouragePro  * GetActivityEncouragePro(UINT64 qwActivityID);
    SActivityEncouragePro  * GetChatActivityEncouragePro(UINT64 qwActivityID);

    UINT8	IsNeedCdKey(UINT64 dwActivityID);

    BOOL CkActivityCdKeyValid(UINT32 dwPlayerID, UINT64 dwActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM]);

    UINT16 GetHeroID();

    BOOL OnEvent();

protected:
    CActivityEncourageMgr();
    virtual ~CActivityEncourageMgr();
protected:

    BOOL LoadFromDBCfg();
    BOOL LoadFromDBPay();

private:
    CJsonResItemVectorInfo				m_vecRechargeActivityEncourageItemInfo;
    CJsonResItemVectorInfo				m_vecScoreActivityEncourageItemInfo;

    CActivityEncouragePropMap			m_mapActivityEncourageProp;
    SChangeActivityEncouragePro		m_stChangeActivityEncouragePro;
    UINT16							m_wZoneID;
};




#endif //#ifndef _ROLEMGR_H_

