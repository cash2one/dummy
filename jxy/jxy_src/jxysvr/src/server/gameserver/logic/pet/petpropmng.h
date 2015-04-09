///<------------------------------------------------------------------------------
//< @file:   logic\pet\petpropmng.h
//< @author: yewenhui10@qq.com
//< @date:   2014��8��6�� 16:47:00
//< @brief:  �������ù���
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------
#ifndef _PET_PROP_MNG_H_
#define _PET_PROP_MNG_H_

#include "petdef.h"

#include "logic/base/singleton.h"
#include "logic/base/basepropmgr.h"
#include "logic/base/basedefine.h"
class CPlayer;

class CPetPropMng
	: public Singleton<CPetPropMng>
	, public CBasePopMgr
{
public:
	CPetPropMng();
	~CPetPropMng();

	// CBasePopMgr
	virtual BOOL		ReLoadProp() { 
		return TRUE;
	}
	EConfigModule		GetConfigModuleType() {
		return ECM_PET; 
	}
	BOOL				Init();
	VOID				UnInit();

	const PetSysCfg&	GetPetSysCfg() const;
	const PetBaseCfg*	GetPetBaseCfg(UINT16 usPetCfgId);
	const PetProductCfg* GetProductCfg(UINT16 usPlayerLv, UINT8 ucProductType);
	const PetProductExtraCfg* GetProductExtraCfg(UINT8 ucProductPhrase
									, BOOL bIsGoodProduct, UINT16 usProductCnt);

	const PetStarCfg*	GetPetStarCfg(UINT8 ucPetType, UINT8 ucPetQuality, UINT8 ucStarLv) const;

	const PetBaseCfgList& GetPetBaseCfgList() {
		return m_mpPetBaseCfg;
	}

	const PetLvCfg*		GetPetLvCfg(UINT16 usPetLv);
	const PetFeedCfg*	GetPetFeedCfg(UINT8 ucFruitType) const;

	const MapPetStoreCfg& GetAllPetStoreCfg() {
		return m_mpStoreCfg;
	}

	const PetStoreCfg* GetPetStoreCfg(UINT16 usStoreId);

	const PetWashCfg*	GetPetWashCfg(UINT8 ucPetType, UINT8 ucPetQuality, UINT8 ucWashQuality);
	UINT8				GetWashQuality(UINT8 ucPetType, UINT8 ucPetQuality, UINT32 unQualityVal);

	const PetRefineCfg*	GetRefineCfg(UINT8 ucPetTypeLevel, UINT8 ucPetQuality);

	BOOL GetLevel(UINT32 dwExp, UINT8 byStarLv, UINT16* wLevel = NULL, UINT32* dwMaxExp = NULL);

	BOOL GetLowPetCli(CPlayer* poPlayerPet, DT_PET_BOOK_DATA_LST& stBookData);
	BOOL GetMiddlePetCli(CPlayer* poPlayerPet, DT_PET_BOOK_DATA_LST& stBookData);
	BOOL GetHighPetCli(CPlayer* poPlayerPet, DT_PET_BOOK_DATA_LST& stBookData);

	VOID GetPetCli(CPlayer* poPlayer, const PetBaseCfg* poBaseCgf, DT_PET_BOOK_DATA& stData);
	VOID GetPetSkillCli(UINT16 wSkillID, UINT16 wPetLevel, DT_SKILL_INFO& stSkillInfo);

	SPetNeiDanProp* GetPetNeiDanProp(UINT16 wNeiDanID);
	SPetNeiDanUpdateProp* GetPetNeiDanUpdataProp(UINT16 wLevel, UINT8 byQuality, UINT8 byType);
	UINT16 GetNeiDanLevel(UINT64 qwExperience, UINT8 byQuality, UINT8 byType);
private:
	BOOL				LoadPetSkill(vector<UINT16>& vecSkill, const string& strSkillValue);
	BOOL				LoadPetSysCfg();
	BOOL				LoadPetBaseCfg();
	BOOL				LoadPetLvCfg();
	BOOL				LoadPetProductCfg();
	BOOL				LoadPetProductExtraCfg();
	BOOL				LoadPetStarCfgList();
	BOOL				LoadFeedCfg();
	BOOL				LoadStoreCfg();
	BOOL				LoadWashCfg();
	BOOL				LoadPetRefineCfg();
	BOOL				LoadPetNeiDanCfg();
	BOOL				LoadPetNeiDanUpdateCfg();
private:
	PetSysCfg			m_PetSysCfg;			// ����ϵͳ����
	PetBaseCfgList		m_mpPetBaseCfg;			// �����������
	MapPetLvCfg			m_mpPetLvCfg;			// ����ȼ�����
	C3232Map			m_mapExpToLevel;		// �����Ӧ�ĵȼ�
	PetProductCfgList	m_vPetProductCfg;		// �����������
	PetProductExtraCfgList m_vProductExtraCfg;	// ���������������
	MapPetStarCfg		m_mpPetStarCfg;			// �����ǽ�����
	MapPetFeedCfg		m_mpFeedCfg;			// ����ι������
	MapPetStoreCfg		m_mpStoreCfg;			// �����̳�����
	MapPetWashCfg		m_mpWashCfg;			// ����ϴ��������
	MapRefineCfg		m_mpRefineCfg;			

	CMapPetNeiDanProp   m_mapPetNeiDanProp;		//�ڵ�����
	CMapPetNeiDanUpdateProp m_mapNeiDanUpdateProp;//�ڵ���������
	map<UINT16, map<UINT64, UINT16>> m_mapNeiDanExperience;

	CMultiMapBaseProp	m_mapBaseCfgByTypeQulity;//��������

};


#endif // _PET_PROP_MNG_H_
