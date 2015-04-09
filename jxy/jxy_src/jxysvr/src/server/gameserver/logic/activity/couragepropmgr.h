
#ifndef _COURAGEPROPMGR_H
#define _COURAGEPROPMGR_H


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdobjectpool.h>
#include <map>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>
#include <sdxmlfile.h>
#include "logic/base/jsonencourage.h"
#include "logic/instance/instancepropmgr.h"
using namespace SGDP;

//�ʱ������
struct SCourageActivityTimeProp
{
    UINT8	byActivityKind;
    UINT8	byStartHour; //���ʼʱ��Сʱ
    UINT8	byStartMin; //���ʼʱ���
    UINT16	wKeepTime; //�����ʱ�䣬��λ��

    UINT32	dwStartTime; //��ʼʱ��(byStartHour+byStartMin������)
    UINT32	dwEndTime; //����ʱ��(dwStartTime+wKeepTime)
    UINT16  wMaxGroupNum; //�ͻ��˽��յĶ�������
};

//ͨ�ؽ�������
struct SCouragePassEncourageProp
{
    UINT16   wLevel;      //����ƽ���ȼ�
    UINT32   dwMedal;     //����ѫ��
    UINT32   dwStory;     //����
    //UINT32   dwCoin;      //ͭǮ
    //UINT32   dwExperience;//����,ÿ���佫��һ��
    //UINT32   dwGold;      //���
    //UINT32   dwBlueGas;   //����
};

typedef struct _tagCourageEncourage
{
    _tagCourageEncourage()
    {
        wLevel = 0;
    }
    UINT16   wLevel;
    CJsonResItemVectorInfo	vecJsonEncourageItemInfo;
} SCourageEncourage;

typedef vector<SCourageEncourage> CCouragePropVector; 
typedef CCouragePropVector::iterator CCouragePropVectorItr;
typedef CCouragePropVector::reverse_iterator CCouragePropVectorRItr;


//������������Ϣ
struct SGroupMonsterProp
{
    UINT16	wLevel;//����ȼ�Ҫ��
    UINT8	byRoundNum;//ս���غ���
    UINT8	byPercentageHp;//Ѫ���ٷֱ�
    vector<SWholeMonsterProp*> vecWholeMonsterProp;//��������
    UINT16 wMainMonsterKindID;//��Ҫ����ID�����1�����������
    UINT32 dwMaxMonsterPower; //���Ĺ���ս��

    SGroupMonsterProp()
    {
        wLevel = 0;
    }
    //~SGroupMonsterProp();
};
//���¾�����
struct SPassCourageEncourageProp
{
    UINT32	 dwCoin;
    UINT32   dwStory;
    UINT32   dwExperience;//����,ÿ���佫��һ��
};

//ÿ����Ʒ��Ϣ
struct SItemCourageGroupProp
{
    SItemCourageGroupProp(): wFirstItemKindID(0), wFirstItemPileNum(0)
    {
        mapItem.clear();
        memset(&stCourageBoxItem, 0, sizeof(stCourageBoxItem));
    };

    CItemRateMap	mapItem;			//��Ʒ
    UINT16			wFirstItemKindID; //��һ��ͨ�ظ�����Ʒ,0��ʾû���״αر���Ʒ
    UINT16			wFirstItemPileNum;//��һ��ͨ�ظ�����Ʒ�ĵ�����
    UINT8			byFirstItemHitIdx;//��һ��ͨ�ظ�����Ʒ����mapItem�е�λ�ã���1��ʼ��0��ʾδ����

    DT_ITEM_DATA_LIST_CLI stCourageBoxItem;//����ͨ��ת����Ʒ(�ڲ�����չ��),���ڷ��ظ��ͻ��ˣ�����ÿ�ζ����¼���
};

typedef map<UINT8, SItemCourageGroupProp> CItemCourageGroupMap; //keyΪ����ţ���1��ʼ
typedef CItemCourageGroupMap::iterator CItemCourageGroupMapItr;

//����ͨ�ر�������
struct SPassCourageBoxProp
{
    CItemCourageGroupMap	mapItemGroup; ///< �����ĵ����鼰��Ӧ����/����,�ڲ�����ȫ��չ��
    DT_BURST_ITEM_DATA stDT_BURST_ITEM_DATA;//���õĿ��ܱ�������Ʒ(�ڲ����䲻չ��),���ڷ��ظ��ͻ��ˣ�����ÿ�ζ����¼���
};

//������Ϣ ��ʱֻ�н��� ����û��  
struct SCourageInfoProp
{
    UINT16	wLevel;	//����
    SPassCourageEncourageProp stPassCourageEncourageProp; //����ͨ�ؽ�������
    SPassCourageBoxProp stPassCourageBoxProp; //����ͨ�ر�������
};

typedef map<UINT16, SCourageInfoProp> CCourageInfoPropMap;
typedef CCourageInfoPropMap::iterator CCourageInfoPropMapItr;

typedef map<UINT8, SCourageActivityTimeProp> CCouragePropMap;
typedef CCouragePropMap::iterator CCouragePropMapItr;

typedef map<UINT32, SCourageActivityTimeProp> CCourageActivityTimePropMap;//keyΪdwEndTime
typedef CCourageActivityTimePropMap::iterator CCourageActivityTimePropMapItr;
typedef CCourageActivityTimePropMap::const_iterator CCourageActivityTimePropMapCItr;

typedef map<UINT16, SCouragePassEncourageProp> SCouragePassEncouragePropMap; //keyΪ�ȼ�
typedef SCouragePassEncouragePropMap::iterator SCouragePassEncouragePropMapItr;

typedef map<UINT16, SCourageEncourage> SCourageEncouragePropMap; //keyΪ�ȼ�
typedef SCourageEncouragePropMap::iterator SCourageEncouragePropMapItr;

typedef HashMap<UINT16 , SGroupMonsterProp*> CGroupMonsterPropMap;
typedef CGroupMonsterPropMap::iterator CGroupMonsterPropMapItr;

class CCouraPropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CCouraPropMgr);

public:
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_COURAGE ;
    }

    BOOL Init();

    VOID UnInit();
public:

    const SCourageActivityTimeProp* GetCouragePropByID(UINT8 byActivityId)
    {
        CCouragePropMapItr itr = m_mapCouragProp.find(byActivityId);
        if (itr != m_mapCouragProp.end())
        {
            return &itr->second;
        }
        else
        {
            return NULL;
        }
    }
    const CCourageActivityTimePropMap& GetCourageActivityTimePropMap()
    {
        return m_mapCourageActivityTimeProp;
    }
    const SCourageActivityTimeProp* GetCourageActivityTimeProp(UINT8 byActivityKind)
    {
        CCourageActivityTimePropMapItr itr = m_mapCourageActivityTimeProp.find(byActivityKind);
        if (itr != m_mapCourageActivityTimeProp.end())
        {
            return &itr->second;
        }
        else
        {
            return NULL;
        }
    }
    const SCourageActivityTimeProp* GetActivityTimeProp(UINT64 qwEnterTime = SDTimeSecs()); //��ȡ����ʱ�䴦�ڵĻʱ������ã�����ǰ���ڻʱ�����򷵻�NULL
    const CCourageActivityTimePropMap& GetCourageActivityStartTimeProp() { return m_mapCourageActivityTimeProp; }
    const CCourageActivityTimePropMap& GetCourageActivityEndTimeProp() { return m_mapCourageActivityEndTimeProp; }
    const SCourageActivityTimeProp* GetNextActivityTimeProp(UINT64 qwStartTime = SDTimeSecs()); //��ȡָ��ʱ���ʼ�Ļʱ�������, ������Ѿ�û�л�򷵻�����ĵ�һ���
    const UINT16 GetMaxGroupNum(){return wMaxGroupNum;}
    SCourageInfoProp* GetCourageInfoProp(UINT16 wLevel);
    SCouragePassEncourageProp* GetCourageAwardProp(UINT16 wLevel);
    SGroupMonsterProp* GetCourageMonsterProp(UINT16 wLevel);
public:
    CCouraPropMgr();
    virtual ~CCouraPropMgr();
protected:

    BOOL LoadActivityTimeFromDB();
    //BOOL LoadBasePropFromDB();
    BOOL LoadAwardFromDB();
    BOOL LoadCourageAwardFromDB();
    BOOL LoadCourageMonsterFDB();
private:
    CCouragePropMap             m_mapCouragProp;
    CCourageActivityTimePropMap	m_mapCourageActivityTimeProp;
    CCourageActivityTimePropMap	m_mapCourageActivityEndTimeProp;
    CCourageInfoPropMap         m_mapCourageInfoProp;    // ������Ϣ ������Ϣ
    SCouragePassEncouragePropMap m_mapCouragePassEnProp;
    SCourageEncouragePropMap    m_mapCourageEncourageProp;
    CGroupMonsterPropMap        m_mapGroupMonsterProp;
    UINT16                      wMaxGroupNum; 
    UINT32	ReadOneValue(EBurstKind eBurstKind, CSDXMLNode& xmlNode);//��ȡ��������ֵ
    BOOL	ReadEncourageItem(SPassCourageBoxProp& stPassBoxProp, CSDXMLNode& xmlNode);//��ȡ����Item
    //BOOL	ReadEncourageItemGroup(SPassBoxProp& stPassBoxProp, UINT8 byGroupIdx, CSDXMLNode& xmlNode);//��ȡItem��
};

#endif // 
