
#ifndef _EQUIPPROPMGR_H_
#define _EQUIPPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <protocol/server/protogtgs.h>
#include <logic/base/basepropmgr.h>

using namespace std;
using namespace SGDP;

/// װ������������󳤶�
#define NAME_LEN_MAX	32
/// װ������������󳤶�
#define INTRODUCTION_LEN_MAX	255


/**
 * @brief
 */
typedef struct tagEquipProp
{
    UINT16	wKindID;					///< װ������
    TCHAR	szName[NAME_LEN_MAX];		///< װ������
    TCHAR	szIntroduction[INTRODUCTION_LEN_MAX];		///< װ������
    UINT8	byPosKindID;				///< װ��λ������(��ͷ/��/����/����/���/�ҽ�)���� EEquipPosType
    UINT8	byEquipColor;				///< װ����ɫ
    UINT16	wDressLevel;				///< �����ȼ�Ҫ��
    UINT32	dwBuyCoin;				 ///< �����Ҽ۸񣬶�ѡһ��0��ʾ��֧�֣�������������ͭ��Ϊ��
    UINT32	dwBuyGold;				 ///< ����Ԫ���۸񣬶�ѡһ��0��ʾ��֧�֣�������������ͭ��Ϊ��
    UINT32	dwRecoverPrice;			 ///< ���ռ۸�(Ҫ����ǿ���۸񣬻���ȫ�����)
    UINT32	dwHP;					 ///< ����
    UINT32	dwAttack;				 ///< ������
    UINT32	dwDefend;				 ///< ����
    UINT16	wStrengthenHPPerLvl;	 ///< ÿǿ��һ�μӵ�����
    UINT16	wStrengthenAttackPerLvl; ///< ÿǿ��һ�μӵĹ�����
    UINT16	wEnchantHPPerLvl;		 ///< ÿ��ħһ�μӵ�����
    UINT16	wEnchantAttackPerLvl;	 ///< ÿ��ħһ�μӵĹ�����
    UINT16	wEnchantDefendPerLvl;	 ///< ÿ��ħһ�μӵķ���
	UINT16	wUpgradeToEquipID;		 ///< ���׵�����һװ��
	UINT16	wUpgradeSuccessRate;	 ///< �����ɹ���
	UINT16	wUpgradeSuccessGold;	 ///< ���ӳɹ�����Ҫ��Ԫ����
	UINT32	dwScience;				 ///< ����
	UINT32	dwStrengthenScience;	 ///< ǿ�����ӵ������
    UINT32	dwEnchantSciencePerLvl;	 ///< ��ħ���ӵ������
    BOOL    bIsLegendEquip;		     ///< �Ƿ����⴫װ��

	UINT8   byComposeItemNum;					//�����������
	UINT16  awComposeItem[MAX_COMPOSE_ITEM_NUM];	//�����������
} SEquipProp;

typedef HashMap<UINT16, UINT16> CUnlockEquipDressLevelMap; //��������װ�������ȼ�, 
typedef CUnlockEquipDressLevelMap::iterator CUnlockEquipDressLevelMapItr;


typedef HashMap<UINT16, SEquipProp> CEquipPropMap;		//key?awKindID
typedef CEquipPropMap::iterator CEquipPropMapItr;
/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CEquipPropMgr : public CBasePopMgr
{
public:
    //typedef HashMap<UINT32, SEquipProp> CEquipPropMap;		//keyΪwKindID+wQuality

    DECLARE_SINGLETON_PROPMGR(CEquipPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_EQUIP ; }

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
    //SEquipProp* GetProp(UINT16 wKindID, UINT16 wQuality);
    SEquipProp* GetProp(UINT16 wKindID);
	CEquipPropMap& GetEquipProp() { return m_mapEquipProp; }

	VOID GetDT_ESTIMATE_EQUIP_DATA(DT_ESTIMATE_EQUIP_DATA & stDT_ESTIMATE_EQUIP_DATA, UINT16 wKindID);

	UINT16 GetUnlockEquipDressLevel(UINT16 wPlayerLevel); 

public:
    CEquipPropMgr();
    virtual ~CEquipPropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

	VOID InitUnlockEquipDressLevel(); //��ʼ��������������װ�������ȼ�

private:
    CEquipPropMap	m_mapEquipProp;
	CUnlockEquipDressLevelMap m_mapUnlockEquipDressLevel; //��������װ�������ȼ���key/valueΪ�����ȼ�
};

#endif // #ifndef _EQUIPPROPMGR_H_
