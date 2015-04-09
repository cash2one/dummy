#ifndef _JEWELRY_PROP_MGR_H_
#define _JEWELRY_PROP_MGR_H_
#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <protocol/server/protocommondata.h>
#include <protocol/server/protocligs.h>
#include <logic/base/basepropmgr.h>
#include <logic/base/propcontainer.h>
#include <map>
#include <vector>
#include <sdmutex.h>
#include <sdobjectpool.h>
#include "common/server/utility.h"
#include "logic/base/basedefine.h"
using namespace SGDP;
using namespace std;

enum
{ 
	EJS_NORMAL = 0, //����
	EJS_ALREAD_STRENG = 1,//�Ѿ�ǿ���� 
	EJS_COIN_NOT_ENOUGH = 2,//ͭǮ����
	EJS_JEWELRY_IS_NULL = 3,//��Ʒû��ȫ
};

class CJewelry;
class CPlayer;
struct SJewelryProp
{
	UINT16 wKindID;
	UINT16 wDressLevel;//�����Ҫ�ȼ�
	UINT8 byColorType;//Ʒ�ʣ��� commondef.h�е�EColor
	TCHAR aszName[NORMAL_MSG_LEN];
	UINT32 dwDefend;
	UINT32 dwHP;
	UINT32 dwAttack;
	UINT32 dwHitRate;
	UINT32 dwDodgeRate;
	UINT32 dwCriRate;
	UINT32 dwDecRitRate;
	UINT8 byPosKindID;//���λ��
	UINT32 dwFirstBase;
	UINT32 dwSecondBase;
};

typedef map<UINT16, SJewelryProp> CMapJewelryProp;
typedef CMapJewelryProp::iterator CMapJewelryPropItr;

typedef map<UINT32, SJewelryProp> CMapJewelryPropByLevelColor;
typedef CMapJewelryPropByLevelColor::iterator CMapJewelryPropByLevelColorItr;


struct SJewelryUpgradeProp
{
	UINT16 wJewelryLevel;	//��Ʒ�ȼ�
	UINT16 wStrengLevel;	//ǿ���ȼ�
	UINT32 dwUpgradeItemID;	//������ƷID
	UINT16 wUpgradeNum;	//������Ʒ����
};

typedef map<UINT32, SJewelryUpgradeProp> CMapJewelryUpgradeProp;
typedef CMapJewelryUpgradeProp::iterator CMapJewelryUpgradePropItr;

struct SJewelryResolveItemProp
{
	UINT16 wItemProbility;
	UINT16 wItemNum;
	UINT16 wItemID;
};

typedef map<UINT32, SJewelryResolveItemProp> CMapJewelryResolveItemProp;
typedef CMapJewelryResolveItemProp::iterator CMapJewelryResolveItemPropItr;
struct SJewelryResolveProp
{
	UINT16 wJewelryLevel;
	UINT8 byColorType;
	CMapJewelryResolveItemProp mapItemProp;
	C3232Map mapItemRandom;
	UINT32 dwCostRes;
};

typedef map<UINT32, SJewelryResolveProp> CMapJewelryResolveProp;
typedef CMapJewelryResolveProp::iterator CMapJewelryResolvePropItr;

typedef map<UINT16, UINT32> CMapUpgradeItemNum;	//IDΪKEY, VALUE��Ʒ���� 
typedef CMapUpgradeItemNum::iterator CMapUpgradeItemNumItr;

typedef map<UINT32, CMapUpgradeItemNum> CMapLevelUpgradeItemProp;//��Ʒ�ȼ�����Ʒǿ���ȼ�ΪKEY�� VALUECMapUpgradeItemNum
typedef CMapLevelUpgradeItemProp::iterator CMapLevelUpgradeItemPropItr;


struct SJewelryStrengProp
{
	UINT16 wJewelryLevel;	//��Ʒ�ȼ�
	UINT8 byColorType;		//��ƷƷ��	
	UINT8 byExtAttrID;		//��������I
	UINT16 wStrengLevel;	//ǿ���ȼ�
	UINT32 dwExtValue;		//������ֵ
};

struct SJewelrySuitAttrProp
{
    SJewelrySuitAttrProp(){
        memset(this, 0, sizeof(*this));
    }

    UINT16 wJewelryStrengLvl;	 // ��Ʒ�����ȼ�

    JewelryExtAttr eAttrType; // �������
    UINT32 dwAttrVal;   // ����������ֵ
    ValueType eValType; // ֵ�����ͣ��̶�ֵ���ٷֱ�
};

typedef std::vector<SJewelrySuitAttrProp> JewelrySuitAttrVec;

// ��Ʒ��װ��Ϣ
struct SJewelrySuitProp
{
    SJewelrySuitProp(){
        Clear();
    }

    void Clear(){
        wJewelryDressLvl = 0;
        vecAttr.clear();
        memset(&stSuitCli, 0, sizeof(stSuitCli));
    }

    UINT16 wJewelryDressLvl;	 // ��Ʒ�����ȼ�

    JewelrySuitAttrVec vecAttr;
    DT_JEWELRY_SUIT_CLI stSuitCli; // �����������ڿͻ�����ʾ
};

typedef map<UINT64, SJewelryStrengProp> CMapJewelryStrengProp;
typedef CMapJewelryStrengProp::iterator CMapJewelryStrengPropItr;

typedef map<UINT32, C3232Map> CMapJewelryRandom;
typedef CMapJewelryRandom::iterator CMapJewelryRandomItr;

typedef std::map<UINT16, SJewelrySuitProp> CMapJewelrySuit;

class CJewelryPropMgr : CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CJewelryPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_JEWELRY ; }

    /**
     * @brief ��ʼ�����Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL Init();

    /**
     * @brief �������Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    VOID UnInit();

    /**
    * @brief ��������
    * @return ����
    */
    SJewelryProp* GetProp(UINT16 wKindID);
	CMapJewelryProp& GetJewelryPropMap() { return m_mapJewelryProp; }
	UINT16 GetRandomJewelryID(UINT16 wLevel, UINT8 byColor);
	BOOL GenerateJewelryData(CPlayer* poPlayer, UINT16 wKindID, DT_JEWELRY_DATA& stJewelryData);
	BOOL GenerateJewelryData(CPlayer* poPlayer, UINT16 wKindID, C32Vec& vec32, DT_JEWELRY_DATA& stJewelryData);
	VOID GetStrentItemInfo(CPlayer* poPlayer, DT_STRENGTH_LST_INFO& stItemInfo);
	//��������
	BOOL SetBaseBattleAttr(UINT16 wKindID, DT_JEWELRY_DATA& stJewelryData);
	
	BOOL SetBaseInof(UINT16 wKindID, DT_JEWELRY_DATA& stJewelryData);
	BOOL SetBaseInof(SJewelryProp& stProp, DT_JEWELRY_DATA& stJewelryData);
	BOOL SetHideBattleAttr(UINT16 wKindID, DT_JEWELRY_DATA& stJewelryData);
	BOOL SetHideBattleAttr(UINT16 wKindID, C32Vec& vec32, DT_JEWELRY_DATA& stJewelryData);
	UINT32 GetPosRandom();
	UINT32 GetExtAttrRandom(CRandomMap& mapRandom);
	SJewelryUpgradeProp* GetUpgradeProp(UINT16 wJewelryLevel, UINT16 wStrengLevel);//��������

	UINT32 GetBaseAttrValue(UINT16 wJewelryID, UINT8 byKindID, UINT16 wStrengLevel);//��������ֵ
	UINT32 GetExtAttrValue(UINT16 wKindID,  UINT8 byExtId, UINT16 wStrengLevel);//��������ֵ 
	SJewelryUpgradeProp* GetUpgradeItemProp(UINT16 wJewelryLevel, UINT16 wStrengLevel);//��ȡǿ������ID

	SJewelryResolveProp* GetResolveProp(UINT16 wJewelryLevel, UINT8 byColorType);//�����ֽ�����

	CMapUpgradeItemNum* GetResolveReturn(UINT16 wJewelryLevel, UINT16 wStrengLevel);//��������ͳ��
	UINT8 GetValueType(UINT8 byExtID){ return m_mapExtIDValueType[byExtID]; }

	CJewelry* CompareJewelry(CJewelry* poJewelry1, CJewelry* poJewelry2);
    VOID GetJewelryCli(DT_JEWELRY_DATA& stInData, DT_JEWELRY_DATA_CLI& stOutData);
	BOOL IsStrengItemID(UINT16 wKindID);

    SJewelrySuitProp* GetJewelrySuitProp(UINT16 wJewelryLevel, UINT16 wStrengLvl);

    UINT16 GetJewelrySuitLvl(SJewelrySuitProp&, UINT16 wStrengLvl);

public:
    CJewelryPropMgr();
    virtual ~CJewelryPropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadBaseAttrFromDB();
	BOOL LoadRandomFromDB();
	BOOL LoadStrengAttrFromDB();
	BOOL LoadUpgradeFromDB();
	BOOL LoadResolveFromDB();
    BOOL LoadExtRandomFromDB();
	BOOL LoadSuitAttFromDB();
private:
    CMapJewelryProp	m_mapJewelryProp;
	CMapJewelryPropByLevelColor m_mapJewelryPropByLevel;
	CMapJewelryUpgradeProp m_mapJewelryUpgradeProp;
	CMapJewelryResolveProp m_mapJewelryResoleProp;
	CMapLevelUpgradeItemProp m_mapLevelToItemProp;
	CMapJewelryStrengProp m_mapJewelryStrengProp;

	C3232Map m_mapPosRandom;
	C3232Map m_mapExtIDRandom;
	C88Map m_mapExtIDValueType;

    CMapJewelryRandom m_mapAttrRandom;
	CMapJewelrySuit m_mapSuit;
};

#endif