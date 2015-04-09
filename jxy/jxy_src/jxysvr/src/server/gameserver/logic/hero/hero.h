#ifndef _HERO_H_
#define _HERO_H_


#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <logic/item/itemmgr.h>
#include <logic/battle/battleattrobj.h>
#include <logic/talent/drugmgr.h>
#include <logic/talent/experiencedrugpropmgr.h>
#include <logic/godweapon/godweaponmgr.h>
#include <logic/shmem/shmemmap.h>
#include <logic/monster/playergroup.h>


struct tagHeroUpgradeProp;
typedef tagHeroUpgradeProp SHeroUpgradeProp;

struct tagHeroProp;
typedef tagHeroProp SHeroProp;

using namespace std ;


#define EQUIP_POS_NUM	4 //����λ����

typedef CShmemMap<UINT64, CEquip> CEquipMap; 
//typedef CEquipMap::iterator CEquipMapItr;

typedef CShmemMap<UINT8, CEquip> CEquipPosMap;//keyΪװ�����佫���ϵ�λ��
//typedef CEquipPosMap::iterator CEquipPosMapItr;

typedef CShmemMap<UINT16, CDrug> CLevel2DrugMap;//key��ҩ�ȼ�
//typedef CLevel2DrugMap::iterator CLevel2DrugMapItr;
typedef CShmemMap<UINT64, CJewelry> CJewelryMap;
typedef CShmemMap<UINT8, CJewelry> CJewelryPosMap;

class CPlayer;
class CPlayerGroup;

class CSoul;

class CHero:public CBattleAttrObj
{
public:
	CHero();
	~CHero();
public:
	virtual inline UINT8 GetFormationIdx();

	void SetPlayerGroup(CPlayerGroup *poPlayerGroup);

	virtual VOID ResetSpecialEffects();

	//��ʼ����ض���
	BOOL Init(DT_HERO_DATA* pstDT_HERO_DATA, DT_JEWELRY_DATA_LST& stJewelry, const DT_HERO_SOUL_DATA& rSoulData, CPlayer* poOwner);
	
    //��Ӿ���,����������������ֱ������
	BOOL AddExperience(UINT32 dwValue);

	//��Ӿ���,�����������������������ܳ�������ĵȼ�
	BOOL AddExperience(UINT32 dwValue, UINT16 wLevel);

    void AddFlyExp(UINT32 dwExp){ m_stDT_HERO_BASE_DATA.dwFlyExp += dwExp; }

    //��ֵ������Ϣ�����ͻ�����
    void SaveClientUpgradeExp();

    //��ȡ�佫�ȼ�
    UINT16 GetLevel(){ return m_stDT_HERO_BASE_DATA.wLevel; }

	//�����佫�ȼ�
	VOID SetLevel(UINT16 wLevel);

	DT_HERO_BASE_DATA&	GetDT_HERO_BASE_DATA() { return m_stDT_HERO_BASE_DATA; }
	DT_ABSORB_DATA_LST&	GetDT_ABSORB_DATA_LST() { return m_stAbsorbDataLst; }

    BOOL IsRecruit(){ return m_stDT_HERO_BASE_DATA.byRecuitedFlag; }
    BOOL IsUnLockRecruit(){ return m_stDT_HERO_BASE_DATA.byRecuitedFlag; }
	
	//DT_HERO_BASE_DATA_CLI &GetDT_HERO_BASE_DATA_Equip_CLI()	{	return m_stDT_HERO_BASE_DATA_CLI; }
	//DT_HERO_BASE_DATA_CLI &GetDT_HERO_BASE_DATA_Equip_CLI()	{	return m_stDT_HERO_BASE_DATA_CLI; }
	VOID GetDT_HERO_BASE_DATA_CLI(DT_HERO_BASE_DATA_CLI& stDT_HERO_BASE_DATA_CLI);
	UINT32 GetPower();
	VOID GetExperience(UINT32& dwExperience, UINT32& dwUpgradeExperience);
	DT_HERO_UPGRADE_DATA &GetDT_HERO_UPGRADE_DATA(){	return m_stDT_HERO_UPGRADE_DATA; } 
	VOID GetDT_HERO_EMBATLE_DATA(DT_HERO_EMBATLE_DATA& stDT_HERO_EMBATLE_DATA);
	VOID GetDT_NEW_HERO_EMBATLE_DATA(DT_NEW_HERO_EMBATLE_DATA& stDT_NEW_HERO_EMBATLE_DATA);
	VOID InitBattleAttribute();//����ս������
	VOID SoulPotencyAttribute(UINT16 wSoulID, UINT8 byPotencyLevel, UINT8 byPotencySubLevel);
	VOID AddBattleAttrBySoulPotency(UINT8 byPotencyID, UINT32 dwValue);
	VOID GetDT_HERO_BASE_DATA_EQUIP_CLI(DT_HERO_BASE_DATA_CLI& stDT_HERO_BASE_DATA_CLI, BOOL bGetEquipAttr = FALSE);//bGetEquipAttrΪFALSE���佫���Բ�����װ������,���������������. �򿪲���ȫ���ԣ�����������װ��
	CEquipMap&	GetEquipMap() { return m_mapEquip; }		
	VOID GetUpgrageInfo(DT_HERO_UPGRADE_DATA& stDT_HERO_UPGRADE_DATA);//��ȡ������Ϣ������ü�¼
	VOID GetUpgrageInfo2(DT_HERO_UPGRADE_DATA2& stDT_HERO_UPGRADE_DATA2);//��ȡ������Ϣ������ü�¼	
	//CPlayer* GetOwner() { return m_poOwner; }
	SHeroUpgradeProp* GetHeroUpgradeProp();
	SHeroProp* GetHeroProp();
	//////////////////////////////////////////////////////
	UINT16	OnDressEquip(UINT16 wDressItemKindID, UINT16 wDressItemIdx); //װ������,ͬʱ��������
	UINT16	OnUndressEquip(UINT16 wUndressItemKindID, UINT16 wUndressItemIdx); //ж������,ͬʱ��������
	UINT16	OnReplaceEquip(UINT16 wDressItemKindID, UINT16 wDressItemIdx, UINT16 wUndressItemKindID, UINT16 wUndressItemIdx);//�滻����,ͬʱ��������
    VOID GetEquip(DT_HERO_EQUIP_DATA_LST_CLI& stEquipDataList);//��ȡ�佫��װ��
	VOID GetEquip_v410(DT_HERO_EQUIP_DATA_LST_CLI_v410& stEquipDataList);//��ȡ�佫��װ��
	VOID GetEquipStrengthenCompose(DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI& stEquipDataList);//��ȡ�佫��װ��

    VOID GetEquipsStrengthenEnchantInfo_v410(DT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI& stEquipDataList);// ��ȡ�佫��װ������ǿ���͸�ħ��Ϣ��

	VOID GetEnemyEquip(DT_ENEMY_EQUIP_DATA_LST& stEquipList);//
	VOID GetExperienceInfo(DT_EXPERIENCE_DATA& stExperienceInfo);
	VOID DressMakeEquip(CEquip* poNewEquip);//�������ɾ�װ���������װ���������װ����¼
	VOID OnDeleteEquip(CEquip* poEquip);//���װ���ص�
	VOID OnAddEquip(CEquip* poEquip);//����װ���ص�
	VOID OnStrengthen();//ǿ���ص�
	CEquip* GetEquipByPos(UINT8 byEquipPos) { return m_mapEquipPos.GetData(byEquipPos); } //��ȡ����λ��װ��
		
	//////////////////////////////////////////////////////
	CGodWeapon* NewGodweapon(DT_GODWEAPON_DATA* pstDT_GODWEAPON_DATA);
	CGodWeapon* GetGodweapon() { return m_poGodWeapon; }

	BOOL FreeGodWeapon();//�ͷ�����ص�
	VOID GetDT_GODWEAPON_BATTLE_DATA(DT_GODWEAPON_BATTLE_DATA& stGodweaponInfo);//�������ս����Ϣ	

	//////////////////////////////////////////////////////
	DT_STUDY_DATA* GetStudyInfo() { return m_astStudy; }
	DT_STUDY_DATA* GetStudy(UINT8 byPos);
	VOID OnUpgradeStudy();//�����ĵûص�
	VOID OnDressStudy(); //�����ĵûص�
	BOOL CkHaveStudyAttrKind(UINT8 byStudyAttrKind);//����Ƿ��Ѵ���ͬ�����ĵ�
	VOID AddStudyBattleAttr();
	BOOL CkHaveStudyAttrKind2(UINT8 byStudyAttrKind1, UINT8 byStudyAttrKind2);//����Ƿ��Ѵ���ͬ�����ĵ�
	VOID AddStudyBattleAttr2();
	VOID AddBattleAttr(UINT8 byAttrKind, UINT32 dwValue, UINT8 byValueType = 1);
	VOID DecBattleAttr(UINT8 byAttrKink, UINT32 dwValue);
    BOOL GetStudyAttrGrid(UINT8 byStudyAttrKind, UINT8& byGridIdx);//��ȡ��������λ�ã�û�з���FALSE
    void AddJewelrySuitAttr(); // �����Ʒ��װ����
    void GetAllHeroAddAttr(C3232Map&); // �����Ʒ��װ����
	BOOL ReCheckJewelrySuit(); // ���¼���Ƿ����һ����Ʒ��װ
    BOOL IsDressJewelrySuit(); // ���أ����ϵ���Ʒ�Ƿ����һ����Ʒ��װ
	//////////////////////////////////////////////////////

	UINT16 GetTalent();//��ȡ�佫�������ʵ��ܺ�
	//////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	CDrug * GetDrug(UINT8 byDrugLevel);
	UINT16 UseDrug(SDrugProp* pstDrugProp);//ʹ�õ�ҩ
	UINT16 UseExperienceDrug(SExperienceDrugProp* pExperienceDrugProp);//ʹ�õ�ҩ
	VOID ClrUseDrugCD();
	VOID GetDrug(DT_DRUG_DATA_LST& stDT_DRUG_DATA_LST);//��ȡ�佫�ĵ�ҩ
	CLevel2DrugMap& GetDrugMap() { return m_mapLevel2Drug; }
	VOID GetAttrForAfterUseDrug(DT_BATTLE_ATTRIBUTE& stHeroBattleAttribute, UINT16& wHeroTalent);//��ȡʹ�õ�ҩ����佫����	

	//////////////////////////////////////////////////////
	VOID OnRecuit();//��ļ�ص�
	VOID OnDisband();//��ӻص�
	VOID OnVisit(UINT8 byVisitNum);//�ݷûص�
	VOID OnUp(UINT8 byFormationIdx);//����ص�
	VOID OnDown();//����ص�

	//////////////////////////////////////////////////////

	UINT16 OnUpdateAttr( UINT8 byAttrKind, UINT32 dwPerCountAddValue );  //��������

	vector< DT_SKILL_DATA_CLI > GetSkillList();

	VOID GetHeroSkill(DT_SKILL_DATA_LST& stDT_SKILL_DATA_LST); 
	VOID GetHeroSkillCli(DT_SKILL_DATA_CLI& stDT_SKILL_DATA_CLI); 
	VOID GetHeroSkillLstCli(DT_SKILL_DATA_LST_CLI& stDT_SKILL_DATA_LST_CLI);
	VOID GetHeroPanelInfo(DT_HERO_PANEL_CLI& stHeroCli);
	//������Եļ���
	UINT16 GetAttrLevel( UINT8 byAttrKind );

	//////////////////////////////////////////////////////
	VOID OnJingjieQualityUpgrade();//������׻ص�

	//��ȡװ���������Ƕ��ʯ������
	UINT8 GetMaxMosaicGemNum();

	UINT8 GetMaxStudyLevel(); //�ĵõȼ�

	inline UINT16 GetHeroID(){return m_stDT_HERO_BASE_DATA.wKindID;};
	
	//����������ӵ�����
	UINT8 GetGodweaponAddTalent();

	UINT16 UpgradeSkillAction(UINT16 wActionID, UINT16 wActionLevelCli);

	void		AddTransHeroID(UINT16 KindID);
	BOOL		GetTransHeroID(UINT16 KindID);
	UINT16	GetAbsorbKindID(){return m_stAbsorbDataLst.wAbsorbKindID;};
	void		SetAbsorbKindID(UINT16 KindID){m_stAbsorbDataLst.wAbsorbKindID = KindID;};
	VOID GetPowerByFormation(UINT8 byFormationID, UINT8 byFormationLevel, UINT32& dwPower, DT_BATTLE_ATTRIBUTE& stAttrBute);
	BOOL IsFormationHero();	//�Ƿ�������Ӣ��

	const DT_HERO_SOUL_DATA& GetHeroSoulData();

	// ���װ���Ļ�
	CSoul* GetEquipSoul(UINT16 usSoulID, UINT32 unIndex);
	// �Ƿ������Ѿ�ȫ�����ϻ�
	BOOL IsSoulAllEquip();
	// 
	BOOL IsHaveSameSoulType(CSoul* pSoul);
	// װ����
	BOOL EquipSoul(CSoul* pSoul);
	// ���»�
	BOOL UnDressSoul(CSoul* pSoul);
	// 
	VOID UpdateSoulData(CSoul* pSoul);

    // �Ƿ�������
    BOOL IsCoachHero(){ return m_stDT_HERO_BASE_DATA.byCoach; }

    // �Ƿ���ʾ�ɷ�����ť
    BOOL IsShowFly();

    // �Ƿ��ѷ���
    BOOL IsFly();

    // ���÷���
    BOOL ResetFly();

    // ��ȡ��������
    UINT32 GetFlyExp(){ return m_stDT_HERO_BASE_DATA.dwFlyExp; }
    
    UINT16 Fly(PKT_CLIGS_FLY_ACK &stAck);

    // ���û�����ϵ�ȫ�����ܣ�����
    void ResetSkill();
    void ResetEquipOwner();

//////�ڲ�����
public:
	UINT16 Change2NewCareer(UINT8 byCareerID);
	////////////////��ȡ�佫��Ʒ//////////////////////////////////
    VOID GetJeweryCli(DT_HERO_JEWELRY_DATA_LST_CLI& stJewelryDataList);
	VOID GetJewerySuitCli(DT_JEWELRY_SUIT_CLI& stJewelrySuit);
	VOID GetJeweryData(DT_JEWELRY_DATA_LST& stJewelryDataList);
	UINT16 OnDressJewelryAck(PKT_CLIGS_DRESS_JEWELRY_REQ& stReq, PKT_CLIGS_DRESS_JEWELRY_ACK& stAck);
	UINT16 DressJewelry(PKT_CLIGS_DRESS_JEWELRY_REQ& stReq, PKT_CLIGS_DRESS_JEWELRY_ACK& stAck);
	UINT16 GetOffJewelry(PKT_CLIGS_DRESS_JEWELRY_REQ& stReq, PKT_CLIGS_DRESS_JEWELRY_ACK& stAck);
	UINT16 ReplaceJewelry(PKT_CLIGS_DRESS_JEWELRY_REQ& stReq, PKT_CLIGS_DRESS_JEWELRY_ACK& stAck);
	CJewelryMap& GetJewelryMap(){ return m_mapJewelry; }
	BOOL DressJewelry(CJewelry* poJewelry);
	BOOL UnDressJewelry(CJewelry* poJewelry);
	UINT32 GetJewelryAttr(UINT32 dwKey);
	BOOL GetJewelryStrengthInfo(DT_HERO_JEWELRY_STRENGTH_INFO& stIfno);
	CJewelry* GetJewelryByPos(UINT8 byPosID);
	VOID OnDeleteJewelry(CJewelry* poJewelry);//����ص�

    BOOL InitAbsorb(DT_ABSORB_DATA_LST *pstAbsorbDataLst);

protected:	
	BOOL InitEquip(DT_HERO_EQUIP_DATA_LST* pstDT_EQUIP_DATA_LST);
	BOOL InitDrug(DT_DRUG_DATA_LST* pstDrugDataInfo);	
	BOOL InitGodweapon(DT_GODWEAPON_DATA* pstDT_GODWEAPON_DATA);
	BOOL InitSkill(DT_SKILL_DATA_LST& stDT_SKILL_DATA_LST);
	BOOL InitStudy(DT_STUDY_DATA astStudyInfo[MAX_HERO_STUDY_GRID_NUM]);
	BOOL InitJewelry(DT_JEWELRY_DATA_LST& pstDT_JEWELRY_DATA_LST);

	DT_BATTLE_BASE_ATTRIBUTE BattleAttrCountByLevelTalent(); //�ȼ�/����ͳ��ս�����ԣ����ݵȼ�/���ʼ�����õȼ�/���ʶ�Ӧ��ս������
	VOID XiangqianAttrCount( map<UINT32, UINT32> &mapCurAttr ); //������Ƕ��õļӳ�
	VOID XiangqianDecAttrCount( map<UINT32, UINT32> &mapCurAttr ); //�۳���Ƕ��õļӳ�
	DT_BATTLE_BASE_ATTRIBUTE BattleAttrCountByEquip(); //װ��ͳ��ս�����ԣ�����װ���������װ����Ӧ��ս������
	VOID Upgrade();	//����
	VOID SetUpgradeExperience(); //��ֵ�µȼ���������
	UINT16 GetDrugTalent();//��ȡ��ҩ����������
	VOID InitCliData(DT_BATTLE_ATTRIBUTE& stEquipAttr);//��ʼ���ͻ�����Ϣ

	UINT32 GetHPAttackPower(); //������ѪӰ��ս��
	UINT32 GetHidePower(); //��������Ӱ��ս��
	UINT32 GetGodweaponPower(); //����Ӱ��ս��
	UINT32 GetSkillPower(); //����Ӱ��ս��
	UINT32 GetHurtPower();//�����˺�Ӱ��ս��
private:
	VOID InitExperience();//���³�ʼ���ͻ��˵ľ�����Ϣ

	//����������������ӵ���
	UINT32 GetAttrUpdateAddition( UINT8 byAttr, BOOL bCoachHero );
	VOID ResetJewelryAttr();
	VOID JewelryCountBySelf(map<UINT32, UINT32>& mapAttr);
	VOID AddEquipAttr(UINT8 byPos,  UINT32 dwValue, UINT8 byJewelryExtID);
	VOID AddStudyAttr(UINT8 byPos,  UINT32 dwValue, UINT8 byJewelryExtID);
	UINT32 AddScienceLevel(UINT32 dwLevel);
	VOID SetFormationData(UINT8 byKindID , UINT32 dwValue );
	VOID SetFormationData();
	VOID SetOpenFormationStatu(BOOL bStatu = FALSE);

	VOID InitSoulData();

private:
	C3232Map m_mapJewelryAttr;				//�ӳ�ָ��
	C3232Map				m_mapJewelryValue;//�ӳ�ֵ Key:EBattleAttributeKind, Value:�ӳ�ֵ

	DT_HERO_BASE_DATA		m_stDT_HERO_BASE_DATA;		//�佫������Ϣ
	CEquipMap			m_mapEquip;				//�佫װ��	
	CEquipPosMap			m_mapEquipPos;			//�佫����װ��λ�ö�Ӧ��װ��
	CLevel2DrugMap		m_mapLevel2Drug;			//�佫��ҩ			
	DT_HERO_UPGRADE_DATA	m_stDT_HERO_UPGRADE_DATA;	//������Ϣ
	UINT64				m_qwUpgradeExperience;		//���ڻ����µȼ��������飬����ÿ��+���鶼��ѯ
	UINT16				m_dwDrugTalent;			//���е�ҩ���ʣ�ÿ��ʹ�õ�ҩ�����¼���
	UINT16				m_dwSkillTalent;			//���м������ʣ�ÿ�μ��ܱ仯�����¼��� .(ֻ��������Ч)
	CGodWeapon*			m_poGodWeapon;			//����,��һ����
	DT_STUDY_DATA			m_astStudy[MAX_HERO_STUDY_GRID_NUM];//�������ĵ�
	DT_ABSORB_DATA_LST	m_stAbsorbDataLst;
	
	CJewelryMap         m_mapJewelry;			//�佫��Ʒ	
	CJewelryPosMap		m_mapJewelryPos;        //�佫������Ʒλ�ö�Ӧ��װ��
	////////////////////////////////////////////////
	DT_ATTR_INC_DATA    m_stFormation;//������
	BOOL m_bIsOpenFormation; //TRUEΪ���󷨼���ս�����ݣ� FALSEΪ��������

	DT_HERO_SOUL_DATA	m_HeroSoulData; // Ӣ��װ��ս����Ϣ
	map<UINT64, CSoul>	m_mpSoul;

    UINT16 m_wJewelrySuitDressLvl; // ��ǰ���ϵ���Ʒ�������װ�Ĵ����ȼ���Ϊ0ʱ����������װ��ÿ�δ�������ж����Ʒ��������Ʒ���Լ�������߶������¼����װ��
    UINT16 m_wJewelrySuitLvl;      // ��ǰ���ϵ���Ʒ�������װ��ǿ���ȼ���ע�⣬��װǿ���ȼ�����Ϊ0

private:
	CPlayerGroup *m_poPlayerGroup;

};



#endif //#ifndef _HERO_H_

