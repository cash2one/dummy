
#ifndef _BUILDPROPMGR_H_
#define _BUILDPROPMGR_H_

#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basedefine.h>
#include <common/client/commondef.h>
#include <protocol/server/protocligs.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;
using namespace std;

namespace SGDP
{
    class CSDXMLNode;
}

//ս������
class SBattleEncourageProp
{
public:
    SBattleEncourageProp()
    {
        Clear();
    }
    VOID Clear()
    {
        dwCoin  = 0 ;
        dwExperience = 0;
        dwStory = 0;
        dwJingJie = 0;
    }
public:
    UINT32          dwCoin;
    UINT32			dwExperience;//����,ÿ���佫��һ��
    UINT32          dwStory;
    UINT32          dwJingJie;
};


//���������
struct SSingleMonsterProp
{
    UINT16 wMonsterID;//����KindID���
    UINT8  byFormationIdx;//�������
};

//���������
struct SWholeMonsterProp
{
    vector<SSingleMonsterProp> vecMonster;//����KindID��ϣ���һ��Ϊ����

    SWholeMonsterProp()
    {
        vecMonster.clear();
    }
};

typedef HashMap<UINT8, UINT8> CUnlockBuildKindMap;//key/valueΪ��������
typedef CUnlockBuildKindMap::iterator CUnlockBuildKindMapItr;

typedef HashMap<UINT16, DT_INSTANCE_ID> CUnlockEliteInstanceIDMap;//key,key/valueΪ��������
typedef CUnlockEliteInstanceIDMap::iterator CUnlockEliteInstanceIDMapItr;


//�佫��������
struct SHeroUnlockProp
{
    UINT8  byCarryNum;//����Я������(��ǰ����δ����ȡ�ϴε����ã���֤��ֵ)
    UINT16 wUnlockHeroKindID[MAX_UNLOCK_HERO_NUM];//�����佫���ͣ�0Ϊû�н���
    SHeroUnlockProp()
    {
        byCarryNum = 0;
        for (int i = 0; i < MAX_UNLOCK_HERO_NUM; i++)
        {
            wUnlockHeroKindID[i] = 0;
        }
        //memset(this, 0x00, sizeof(SHeroUnlockProp));
    }
};

#define  MAX_INSTANCE_NAME 64



//����ͨ�ؽ�������
class SPassEncourageProp
{
public:
    SPassEncourageProp(): dwCoin(0), dwStory(0), dwExperience(0) {};
public:
    UINT32			 dwCoin;
    UINT32            dwStory;
    UINT32			 dwExperience;//����,ÿ���佫��һ��
};

//ÿ����Ʒ��Ϣ
struct SItemGroupProp
{
    SItemGroupProp(): wFirstItemKindID(0), wFirstItemPileNum(0)
    {
        mapItem.clear();
        memset(&stBoxItem, 0, sizeof(stBoxItem));
    };

    CItemRateMap	mapItem;			//��Ʒ
    UINT16			wFirstItemKindID; //��һ��ͨ�ظ�����Ʒ,0��ʾû���״αر���Ʒ
    UINT16			wFirstItemPileNum;//��һ��ͨ�ظ�����Ʒ�ĵ�����
    UINT8			byFirstItemHitIdx;//��һ��ͨ�ظ�����Ʒ����mapItem�е�λ�ã���1��ʼ��0��ʾδ����

    DT_ITEM_DATA_LIST_CLI stBoxItem;//����ͨ��ת����Ʒ(�ڲ�����չ��),���ڷ��ظ��ͻ��ˣ�����ÿ�ζ����¼���
};

typedef map<UINT8, SItemGroupProp> CItemGroupMap; //keyΪ����ţ���1��ʼ
typedef CItemGroupMap::iterator CItemGroupMapItr;



//����ͨ�ر�������
class SPassBoxProp
{
public:
    SPassBoxProp()
    {
        mapItemGroup.clear();
        memset(&stDT_BURST_ITEM_DATA, 0, sizeof(stDT_BURST_ITEM_DATA));
    };
public:
    CItemGroupMap	mapItemGroup; ///< �����ĵ����鼰��Ӧ����/����,�ڲ�����ȫ��չ��

    DT_BURST_ITEM_DATA stDT_BURST_ITEM_DATA;//���õĿ��ܱ�������Ʒ(�ڲ����䲻չ��),���ڷ��ظ��ͻ��ˣ�����ÿ�ζ����¼���
};


//�������ŵĹ���
struct SInstanceOpenFunc
{
    //vector<UINT8> mapOpenBuild;//���ŵ������н���
    set<UINT8> setOpenBuild;//���ŵ������н���
    vector<UINT16> vecOpenHero;//���ŵ������л��
    //map<UINT16, UINT16> mapOpenHero;//���ŵ������л��
    vector<UINT16> vecUnlockSkill;//���ŵ������м���
};


//ÿ������������Ϣ
struct SInstanceProp
{
    UINT8	byIndex;	//��������(��˳�򿪷�)
    string	strName; //��������
	string  strInstanceDesc;//��������
    tstring	strDispName; //������ʾ����
    UINT16	wEnterLevel;//����ȼ�Ҫ��
    UINT8	byRoundNum;//ս���غ���
    UINT8	byPercentageHp;//Ѫ���ٷֱ�
    SPassEncourageProp stPassEncourageProp; //����ͨ�ؽ�������
    SPassBoxProp stPassBoxProp; //����ͨ�ر�������
    vector<SWholeMonsterProp*> vecWholeMonsterProp;//��������
    CUnlockBuildKindMap			mapUnlockBuildKind;//�����Ľ���
    CUnlockEliteInstanceIDMap		mapUnlockEliteInstanceID;
    SHeroUnlockProp stHeroUnlockProp;//�佫������Ϣ
    DT_INSTANCE_ID stUnlockEliteInstanceID;//��ǰ�����ľ�Ӣ����
    DT_INSTANCE_ID stUnlock2EliteInstanceID;//��ǰ�������ľ�Ӣ����
    UINT16 wUnlockSKillID;//�����ļ���ID,0��ʾû��
	UINT8 byBattleNum;//ÿ�����ս����
	string strLeveReqDesc;//�ȼ�Ҫ������
	vector<DT_INSTANCE_ID> vecUnlockInstance;
	DT_INSTANCE_ID stParentInstance;
	string strParentReqDesc;//����Ҫ������
	BOOL bIsMajor;//�ǲ��Ǿ�����
	string strItemDesc;//����װ������
	string strHeroDesc;//����Ӣ������
	SPassEncourageProp stOutBoundEncourage; //�⴫����ͨ�ؽ�������
	vector<UINT32> vecDisplayItem;//��ʾ����ƷID

    UINT16 wMainMonsterKindID;//��Ҫ����ID�����1�����������
    UINT32 dwAllExperience; //�����������ܾ��飬���ڷ��ظ��ͻ���
    SInstanceOpenFunc stInstanceOpenFunc;//�ø������ŵ������й��ܣ����ڳ�ʼ���������ʱ��ȫȱ��/�����Ĺ���
    UINT32 dwMaxMonsterPower; //���Ĺ���ս��

    SInstanceProp()
    {
        wEnterLevel = 0;
        dwAllExperience = 0;
		byBattleNum = 0;
		strInstanceDesc ="";
		bIsMajor = FALSE;
		strLeveReqDesc = "";
		strParentReqDesc = "";
		strHeroDesc = "";
		strItemDesc = "";
		memset(&stParentInstance, 0, sizeof(DT_INSTANCE_ID));
		memset(&stOutBoundEncourage, 0, sizeof(SPassEncourageProp));
    }
    ~SInstanceProp();
};


typedef map<UINT16 , SInstanceProp*> CIndex2InstancePropMap;
typedef CIndex2InstancePropMap::iterator CIndex2InstancePropMapItr;

//����ӵ�еĸ���
struct STownInstanceProp
{
    UINT8 byTownIndex;
    CIndex2InstancePropMap m_mapInstance;
    UINT16 wOnhookLevel;
    ~STownInstanceProp();
};

typedef map<UINT16 , STownInstanceProp*> CIndex2TownInstancePropMap;
typedef CIndex2TownInstancePropMap::iterator CIndex2TownInstancePropMapItr;
//����ӵ�еĳ���
struct SSceneTownProp
{
    UINT16 wSceneIndex;
    CIndex2TownInstancePropMap m_mapTownInstance;
    ~SSceneTownProp();
};

typedef map<UINT16 , SSceneTownProp*> CIndex2SceneTownPropMap;
typedef CIndex2SceneTownPropMap::iterator CIndex2SceneTownPropMapItr;


//��һ����������
enum ENextInstanceType
{
    ENIT_NEXT_INSTANCE = 0,
    ENIT_NEXT_TOWN,
};

//��һ��������Ϣ
struct SNextInstance
{
    BOOL bHaveNext;
    ENextInstanceType eNextInstanceType;
    DT_INSTANCE_DATA stDT_INSTANCE_DATA;
    SInstanceProp*	pstInstanceProp;
    SNextInstance()
    {
        bHaveNext = FALSE;
        memset(&stDT_INSTANCE_DATA, 0, sizeof(DT_INSTANCE_DATA));
        pstInstanceProp = NULL;
    }
};

//��������
typedef HashMap<UINT8, DT_INSTANCE_ID> CUnlockBuildKind2InstanceIDMap; //keyΪ��������
typedef CUnlockBuildKind2InstanceIDMap::iterator CUnlockBuildKind2InstanceIDMapItr;


//�佫����
typedef HashMap<UINT32, SHeroUnlockProp> CInstanceID2HeroUnlockPropMap; //keyΪ��������ID��DT_INSTANCE_ID)
typedef CInstanceID2HeroUnlockPropMap::iterator CInstanceID2HeroUnlockPropMapItr;


//���ǵȼ�����
typedef HashMap<UINT16, DT_INSTANCE_ID> CMainTownLevelUnlock2InstanceIDMap; //keyΪ���ǵȼ�
typedef CMainTownLevelUnlock2InstanceIDMap::iterator CMainTownLevelUnlock2InstanceIDMapItr;


//������Ʒ���Ͷ�Ӧ����
typedef HashMap<UINT16,  DT_INSTANCE_ID> CBurstItemKind2InstanceIDMap;//keyΪ����kindid
typedef CBurstItemKind2InstanceIDMap::iterator CBurstItemKind2InstanceIDMapItr;

//�������϶�Ӧ���⴫����
typedef std::vector<DT_INSTANCE_ID> InstanceVec; // �����б�
typedef std::map<UINT16, InstanceVec> BurstItemID2InstancesMap; // <����ID, �����õ��ߵĸ����б�>

//��������ID��Ӧ����
typedef HashMap<UINT16,  DT_INSTANCE_ID> CUnlockSKillID2InstanceIDMap;//keyΪ����ID
typedef CUnlockSKillID2InstanceIDMap::iterator CUnlockSKillID2InstanceIDMapItr;

/**
 * @brief ���Թ�����
 *
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */

class CInstancePropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CInstancePropMgr);

public:
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_INSTANCE ;
    }
    BOOL Init();
    VOID UnInit();
public:
    CIndex2SceneTownPropMap& GetAllSceneInstance()
    {
        return m_mapIndex2SceneTownProp;
    };
	SSceneTownProp* GetSceneTownProp(UINT16 wSceneIdx);
    STownInstanceProp* GetSceneInstance(UINT16 wSceneIdx, UINT8 byTownIdx);
    SInstanceProp* GetInstanceProp(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);
    VOID	GetNextInstance(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, SNextInstance& stNextInstance);
    SHeroUnlockProp* GetUnlockHero(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);//��ȡ�����佫����
    DT_INSTANCE_ID* GetBurstItemInstancdID(UINT16 wItemKindID);//��ȡ��Ʒ�����ĸ���

    InstanceVec* GetDropInstanceListOfItem(UINT16 wItemKindID);//��ȡ��Ʒ�����ĸ����б�

    vector<UINT16>& GetUnlockSkill(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);
    DT_INSTANCE_ID* GetUnlockSkillInstancdID(UINT16 wSkillID);//��ȡ�������ܵĸ���
	UINT8 GetMaxOutBoundTownIdx();
	UINT8 GetMaxOutBoundInstanceIdx(UINT8 byTownIdx);
	VOID GetNeiDanAllInstance(CPlayer* poPlayer, DT_NAIDAN_INSTANCE_LST_DATA& stInstanceLst);
	UINT8 GetMaxNaiDanInstanceIdx(){ return m_byMaxNeiDanInstanceIdx; }
public:
    CInstancePropMgr();
    virtual ~CInstancePropMgr();
protected:
    BOOL LoadFromXML();
    BOOL LoadFromData(STownInstanceProp* pstTownInstanceProp, const CHAR* pszData, const UINT32 dwDataLen);
	BOOL LoadOutBound();
	BOOL LoadNeiDanInstance();
	//��ȡ����
	BOOL ReadEncourage(SInstanceProp* poInstanceProp,const string& strItemID, const string& strItemNum, const string& strItemRate, const string& strFirstFlag, const string& strDisPlayItem);
	//��ȡ�佫
	BOOL ReadHero(SInstanceProp* pstInstance, const string& strJson);
	//��ȡ����
	BOOL ReadBuild(SInstanceProp* pstInstanceProp, const string& strJson);
	//��ȡ����
	BOOL ReadMonster(SInstanceProp* pstInstanceProp, const string& strjson);
    //��ȡ����
    BOOL ReadEncourage(SInstanceProp* pstInstanceProp, CSDXMLNode& xmlNode);

    //��ȡ����
    BOOL ReadMonster(SInstanceProp* pstInstanceProp, CSDXMLNode& xmlNode);

	//��ȡ�⴫����
	BOOL ReadOutBound(SInstanceProp* pstInsanceProp, CSDXMLNode& xmlNode);

    //��ȡ����
    BOOL ReadBuild(SInstanceProp* pstInstanceProp, CSDXMLNode& xmlNode);

    //��ȡ�佫
    BOOL ReadHero(SInstanceProp* pstInstanceProp, CSDXMLNode& xmlNode);//Ϊ�˲�����ļ������Ϣ����ļ����(Я��������)��������Ϣ���밴˳�򣡣���

    //��ȡ������Ӣ����
    BOOL ReadEliteInstance(SInstanceProp* pstInstanceProp, CSDXMLNode& xmlNode);

    //��ȡ��������ID
    BOOL ReadUnlockSkill(SInstanceProp* pstInstanceProp, CSDXMLNode& xmlNode);

	//ͳ�Ƹ���������¼
	VOID ReadInstanceUnlock();
protected:
    UINT32	ReadOneValue(EBurstKind eBurstKind, CSDXMLNode& xmlNode);//��ȡ��������ֵ
    BOOL	ReadEncourageItem(SPassBoxProp& stPassBoxProp, CSDXMLNode& xmlNode);//��ȡ����Item
    BOOL	ReadEncourageItemGroup(SPassBoxProp& stPassBoxProp, UINT8 byGroupIdx, CSDXMLNode& xmlNode);//��ȡItem��

    BOOL	InitBoxBurstItem(SInstanceProp* pstInstanceProp);//��ʼ�����õĿ��ܱ����ı�����Ʒ,���ڷ��ظ��ͻ��ˣ�����ÿ�ζ����¼���
    BOOL	InitBurstExp(SInstanceProp* pstInstanceProp);//��ʼ�����õĿ��ܱ����ľ���,���ڷ��ظ��ͻ��ˣ�����ÿ�ζ����¼���
    BOOL	InitMaxPower(SInstanceProp* pstInstanceProp); //��ʼ��������ս����Ϣ

private:
    CIndex2SceneTownPropMap			m_mapIndex2SceneTownProp;
    CUnlockBuildKind2InstanceIDMap	m_mapUnlockBuildKind2InstanceID;//��������map,�������ͽ�����Ӧ�ĸ������
    CInstanceID2HeroUnlockPropMap	m_mapInstanceID2HeroUnlockProp;//�佫������ÿ��ȡ1�������ò���1����¼����������κθ����Ľ�������
    CBurstItemKind2InstanceIDMap	m_mapBurstItemKind2InstanceID;//������Ʒ���Ͷ�Ӧ������ֻ���¼�������õ��ߵġ�һ������Ҳ��Ӧ��ͬ�������ڲ�ͬ��������

    BurstItemID2InstancesMap m_mapDropItemID2InstanceList; // �������϶�Ӧ���⴫�����б�ͬһ���Ͽ����ڲ�ͬ�⴫�����ڳ��֣�

    DT_INSTANCE_ID	m_stInstanceIDTmp;//������ʱ�����ȡ�����ļ�
    UINT8		m_byLastCarryNum;//����Я������,������ʱ�����ȡ�����ļ�,û������ʱʹ���ϴμ�¼
    DT_INSTANCE_ID m_stLastEliteInstanceID;//�������ľ�Ӣ����,������ʱ�����ȡ�����ļ�,û������ʱʹ���ϴμ�¼
    SInstanceProp* m_pstLastInstanceProp;//��һ��������������ʱ�����ȡ�����ļ�
    CUnlockSKillID2InstanceIDMap m_mapUnlockSKillID2InstanceID;// ��������ID��Ӧ�ĸ���
    UINT8		m_byCurHeroIndex; //�佫������

	UINT8 m_byMaxNeiDanInstanceIdx;
    UINT8	m_byRoundNum;//ս���غ���
    UINT8	m_byPercentageHp;//Ѫ���ٷֱ�
};

#endif
