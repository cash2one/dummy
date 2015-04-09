
#ifndef _HEROPROPMGR_H_
#define _HEROPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>
#include "logic/fly/flydef.h"

#include <stddef.h>

/// �佫����������󳤶�
#define NAME_LEN_MAX	32

struct tagDT_HERO_BASE_DATA_CLI;
typedef tagDT_HERO_BASE_DATA_CLI DT_HERO_BASE_DATA_CLI;

struct tagDT_SKILL_DATA_CLI;
typedef tagDT_SKILL_DATA_CLI DT_SKILL_DATA_CLI;

/**
 * @brief
 */
typedef struct tagHeroProp
{
    tagHeroProp(){
        memset(this, 0, offsetof(tagHeroProp, wUpgradeFromHeroID));

        vecCostMaterial.clear();
        vecCostMaterial.clear();
    }

    UINT16	wKindID;		///< �佫����
    TCHAR	szName[NAME_LEN_MAX];		///< �佫����
    UINT8	byCareerID;		///< ְҵID
    UINT16   wTalent;		///< �佫����
    UINT16   wHitRate;//����(�ٷֱ�)
    UINT16	wDodgeRate;//����(�ٷֱ�)
    UINT16   wCritRate;//����(�ٷֱ�)
    UINT16	wDeCritRate;//����(�ٷֱ�)
    UINT16	wAngryValue;//ŭ��ֵ
    UINT32	dwVisitCoin;//�ݷ�����ͭ��
    UINT8	byVisitNum;//��ݷô���
	UINT16	wVisitGold;//��ݷ�Ԫ��
	UINT16	dwAttack;		//����
	UINT16	dwHP;			//Ѫ��
	UINT16	wProbability;		//����
	UINT16	wGoldLeopardProbability;		//��Ԫ�������Ӹ���
	UINT16	wCoinLeopardProbability;		//��ͭ�ҳ����Ӹ���
    UINT16	wSkillID;//ӵ�еļ���ID
    UINT16	wSkillLevel;//ӵ�еļ��ܵȼ�
	UINT16	wSkillActionID; ///< ������ʽID
	UINT16	wSkillActionLevel; ///< ������ʽ�ȼ�
	UINT16	wSkillEffectID; ///< ����Ч��ID

    UINT8	byIndex;//�������
	UINT16	wRecuitLevel;//����ļ�ȼ�
	UINT16	wRequireJingjieLevel;//��Ҫ�ľ���׵ȼ�

	UINT16	wMaxAbsorbNum;//���ɴ��ݴ���
	UINT8	byRecommend; //�Ƿ��Ƽ�

    BOOL bIsLegendHero; // �Ƿ����⴫Ӣ��
    UINT16 wUpgradeToHeroID; // ���׺�Ļ��ID
    UINT16 wUpgradeFromHeroID; // �û����ĸ�ǰ��������׶���

    MaterialVec vecCostMaterial; // ���ײ����б�
    MaterialVec vecFlyMaterial; // �û����������ĵĲ���
} SHeroProp;


typedef std::map<UINT16, SHeroProp> CHeroPropPriMap;
typedef std::map<UINT16, SHeroProp>::iterator CHeroPropPriMapItr;

/**
 * @brief 
 */
typedef struct tagHeroUpgradeProp
{
	UINT16	wLevel;		///< �佫�ȼ�
	UINT64	qwExperience;		///< ����(�ܾ���)
}SHeroUpgradeProp;

typedef std::map<UINT16, SHeroUpgradeProp> CHeroUpgradePropPriMap;
typedef std::map<UINT16, SHeroUpgradeProp>::iterator CHeroUpgradePropPriMapItr;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CHeroPropMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CHeroPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_HERO ; }

    BOOL Init();

    VOID UnInit();

	BOOL LoadFromDB();

public:
	SHeroProp* GetHeroProp(UINT16 wHeroKindID);
	SHeroUpgradeProp* GetHeroUpgradeProp(UINT16 wLevel);
	CHeroPropPriMap& GetHeroPropMap() { return m_mapHeroProp; }


	VOID GetDT_HERO_BASE_DATA_CLI(DT_HERO_BASE_DATA_CLI& stDT_HERO_BASE_DATA_CLI, DT_SKILL_DATA_CLI &stSkillInfo, UINT16 wHeroKindID);

	UINT16 GetLevel(UINT64	dwExperience);

public:
    CHeroPropMgr();
    virtual ~CHeroPropMgr();

protected:


    BOOL LoadHeroPropFromDB();
	BOOL LoadHeroUpgradePropFromDB();

private:
	CHeroPropPriMap			m_mapHeroProp;
	CHeroUpgradePropPriMap	m_mapHeroUpgradeProp;
};

#endif // #ifndef _HEROPROPMGR_H_
