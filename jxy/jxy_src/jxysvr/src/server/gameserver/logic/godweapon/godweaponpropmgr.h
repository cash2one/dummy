
#ifndef _GODWEAPONUPGRADEPROPMGR_H_
#define _GODWEAPONUPGRADEPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <logic/base/basepropmgr.h>
#include <protocligs.h>
#include <logic/base/basedefine.h>

using namespace SGDP;

/// Ʒ������������󳤶�
#define QUALITYNAME_LEN_MAX	32

/// Ʒ������������
#define MAX_UPGRADE_QUALITY_ATTR_NUM 4

#define MAX_GODWEAPON_QUALITY_NUM_EX	255

//������������
typedef struct tagGodweaponQualityUpgradeProp
{
    UINT16   wHeroKindID;						///< �佫ID
    UINT16	wQualityLevel;						///< ����Ʒ�ʼ���
    TCHAR	szQualityName[QUALITYNAME_LEN_MAX];	///< Ʒ������
    UINT16	wRequirePlayerLevel;				///< ��Ҫ��Ҵﵽ�ĵȼ�
    UINT16	wUpgradeQualityItemNum;				///< ���׵���һ��������׷�����
    UINT8	abyBaseAttrKind[MAX_UPGRADE_QUALITY_ATTR_NUM];///< ��ǰ������������
    UINT32	adwBaseAttrValue[MAX_UPGRADE_QUALITY_ATTR_NUM];///< ��ǰ������������ֵ
    UINT8	byQualityUpgradeEncAttrKind;		///< ���׵���һ�׽�������
    UINT32	dwUpgradeQualityEncAttrValue;		///< ���׵���һ�׽�������ֵ

    SAllAttrProp stIncAttr;					///< ���ý׶�������������(����������)
    SAllAttrProp stEncAttr;					///< ���ý׶��������Ľ�������
    SAllAttrProp stAllAttr;					///< ���ý׶�����������������

} SGodweaponQualityUpgradeProp;


//������������
typedef struct tagGodweaponLevelUpgradeProp
{
    UINT16  wHeroKindID;					///< �佫ID
    UINT16	wQualityLevel;					///< ����Ʒ�ʼ���
    TCHAR	szQualityName[QUALITYNAME_LEN_MAX];	///< Ʒ������
    UINT16	wUpgradeLevel;					///< ����Ʒ���еĵȼ�
    UINT32	dwUpgradeScience;				///< �������ü����������(�Ƽ�)��
    UINT8	byUpgradeAttrKind;				///< ������������
    UINT32	dwUpgradeAttrValue;				///< ������������ֵ

    SAllAttrProp stIncAttr;					///< ���ý׶�������������(����������)
    SAllAttrProp stEncAttr;					///< ���ý׶��������Ľ�������
    SAllAttrProp stAllAttr;					///< ���ý׶�����������������
} SGodweaponLevelUpgradeProp;

//�佫����Ʒ��������������
typedef struct tagHeroGodweaponAllEncAttrProp
{
    UINT8			byEncAttrNum;
    DT_ATTR_INC_DATA	astQualityUpgradeEncAttr[MAX_GODWEAPON_QUALITY_NUM_EX]; //����Ʒ��������������
	tagHeroGodweaponAllEncAttrProp()
	{
		memset(this, 0x00, sizeof(tagHeroGodweaponAllEncAttrProp));
	}
} SHeroGodweaponAllEncAttrProp;



typedef HashMap<UINT32, SGodweaponQualityUpgradeProp> CGodweaponQualityUpgradePropMap; //keyΪ�佫ID+����Ʒ��
typedef CGodweaponQualityUpgradePropMap::iterator CGodweaponQualityUpgradePropMapItr;

typedef HashMap<UINT64, SGodweaponLevelUpgradeProp> CGodweaponLevelUpgradePropMap; //keyΪ�佫ID+����Ʒ��+�����ȼ�
typedef CGodweaponLevelUpgradePropMap::iterator CGodweaponLevelUpgradePropMapItr;

typedef HashMap<UINT64, UINT64> CQualityUpgradeNum2Science; //keyΪ����Ʒ��+��������,valueΪ����(�Ƽ�)��
typedef CQualityUpgradeNum2Science::iterator CQualityUpgradeNum2ScienceItr;

typedef HashMap<UINT16, SAllAttrProp> CHeroFullGodweaponAttrMap; //key�佫ID��valueΪ���佫������������������
typedef CHeroFullGodweaponAttrMap::iterator CHeroFullGodweaponAttrMapItr;

typedef HashMap<UINT16, SHeroGodweaponAllEncAttrProp> CHeroID2EncAttrPropMap; //keyΪ�佫ID,
typedef CHeroID2EncAttrPropMap::iterator CHeroID2EncAttrPropMapItr;



/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CGodweaponPropMgr: public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CGodweaponPropMgr);

public:

    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_GODWEAPON ;
    }

    BOOL Init();

    VOID UnInit();

    SGodweaponQualityUpgradeProp* GetGodweaponQualiryUpgradeProp(UINT16 wHeroKindID, UINT16 wQuality);

    SGodweaponLevelUpgradeProp* GetGodweaponLevelUpgradeProp(UINT16 wHeroKindID, UINT16 wQuality, UINT16 wLevel);

    UINT64 GetUpgradeScience(UINT16 wHeroKindID, UINT16 wCurQuality, UINT16 wCurLevel);//��ȡ�����������(�Ƽ�)��

    UINT64 GetNextUpgradeScience(UINT16 wHeroKindID, UINT16 wCurQuality, UINT16 wCurLevel);////��ȡ�����������(�Ƽ�)��


    //��ȡ��������Ʒ�ʵȼ��ܹ��������(�Ƽ�)��
    UINT64 GetUpgradeTotalScience(UINT16 wHeroKindID, UINT16 wCurQuality, UINT16 wCurLevel);

    VOID GetGodweaponAttr(UINT32 dwCliVer, UINT16 wHeroKindID, INT16 wQuality, UINT16 wLevel, DT_GODWEAPON_ATTR_DATA& stIncAttr, UINT8 &byEncAttrNum, DT_ATTR_INC_DATA astQualityUpgradeEncAttr[MAX_GODWEAPON_QUALITY_NUM],
                          UINT16& wQualityRequireLevel, UINT32& dwUpgrageScience, UINT16& wUpgradeQualityNeedItemNum, DT_ATTR_INC_DATA& stNextLevelIncAttr);//��ȡ��ǰƷ�ʼ��������

    UINT16 GetMaxQuality(UINT16 wHeroKindID);

    SHeroGodweaponAllEncAttrProp *GetGodweaponAllEncAttr( UINT16 wHeroID );
public:
    CGodweaponPropMgr();
    virtual ~CGodweaponPropMgr();

protected:

    BOOL LoadQualityUpgradeFromDB();
    BOOL LoadLevelUpgradeFromDB();

    BOOL InitUpgradeTotalScience();//��ʼ�������ܹ��������(�Ƽ�)��
    BOOL InitQualityLevelHaveAttr(); // ��ʼ��ÿƷÿ��������������

    VOID SetGodweaponQualityAttr(UINT16 wHeroKindID, INT16 wQuality, SAllAttrProp& stIncAttr, SAllAttrProp& stEncAttr);
    VOID SetGodweaponLevelAttr(SGodweaponLevelUpgradeProp* pstLevelProp, SAllAttrProp& stIncAttr, SAllAttrProp& stEncAttr);
    VOID AddGodweaponAttrProp(SAllAttrProp& stAllAttr, SAllAttrProp& stAttr1, SAllAttrProp& stAttr2);

    SAllAttrProp* GetFullIncAttr(UINT16 wHeroKindID);
    SAllAttrProp* GetFullEncAttr(UINT16 wHeroKindID);

private:
    CGodweaponQualityUpgradePropMap	m_mapGodweaponQualityUpgradeProp;
    CGodweaponLevelUpgradePropMap	m_mapGodweaponLevelUpgradeProp;
    CQualityUpgradeNum2Science		m_mapUpgradeScience;			//ÿ��Ʒ�ʵȼ���������һ������������
    CQualityUpgradeNum2Science		m_mapUpgradeTotalScience;		//��������Ʒ�ʵȼ��ܹ�����������
    //UINT16						m_wMaxQualityLevel;			//���Ʒ��
    UINT8						m_byQualityUpdateNum;
    CHeroFullGodweaponAttrMap		m_mapHeroFullGodweaponIncAttr;	//�佫I������������������(����������)
    CHeroFullGodweaponAttrMap		m_mapHeroFullGodweaponEncAttr;	//�佫I�������������Ľ�������
    CHeroID2EncAttrPropMap			m_mapHeroID2EncAttrProp; //�佫����Ʒ��������������
};

#endif // #ifndef _GODWEAPONUPGRADEPROPMGR_H_
