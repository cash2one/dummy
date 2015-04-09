///<------------------------------------------------------------------------------
//< @file:   logic/pet/playerpet.h
//< @author: yewenhui
//< @date:   2014��8��11�� 9��10��
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "logic/pet/petdef.h"
#include "logic/base/baseobj.h"
#include "common/server/utility.h"

#ifndef _PLAYER_PET_ 
#define _PLAYER_PET_

class CPet;
class CPlayer;
class CPetNeiDan;

typedef std::map<UINT16, CPet*> MapPet;

class CPlayerPet
	: public CBaseObj
{
public:
	CPlayerPet();
	~CPlayerPet();

	BOOL				Init(const DT_PLAYER_PET_DATA& rPetData, CPlayer *pPlayer);
	DT_PLAYER_PET_DATA& GetDT_PLAYER_PET_DATA();	

	BOOL				IsPetBagFull() {
		return m_mpPet.size() >= MAX_PET_NUM;
	}
	UINT32				GetPetBagIdleSize() {
		return MAX_PET_NUM - m_mpPet.size();
	}

	CPet*				GetPet(UINT16 usPetId);
	const CPet*			AddPet(const DT_PET_DATA& rPetData);
	BOOL				RemovePet(UINT16 usPetId);

	// ��ȡ��ս����
	const CPet*			GetFightPet() const; 
	// ��ȡ�������
	vector<const CPet*>	GetFollowPet() const; 

	const MapPet&		GetAllPet() {
		return m_mpPet;
	}
	BOOL HaveCall(UINT16 wCfgID);
	// �����ڴ�����
	VOID				UpdatePetLstData();

	VOID SetRuleState(BOOL bState);
	BOOL GetRuleState(){ return m_PlayerPetData.byCallFlag; }

    // ����Ƿ���죬���콫��������ٻ�����
    void CheckCrossDay();

	VOID ResetNeiDanHeroHP();
	VOID SetInitHeroHP(DT_BATTLE_OBJ_GROUP_HP& stInitHeroHP);
	VOID SetAfterHeroHP(DT_BATTLE_OBJ_GROUP_HP& stInitHeroHP);
	//////////////////////////////�ڵ�����////////////////////////////////////////////

	VOID GetNeiDanByBag(DT_BAG_NEIDAN_CLI& stBagNeiDan);
	VOID GetNeiDanMarkByBag(DT_NEIDAN_BAG_MARK_LST_DATA& stBagNeiDan);
	CPetNeiDan* GetNeiDan(UINT16 wID, UINT16 wIdx);
	CPetNeiDan* GetNeiDanByBag(UINT16 wID, UINT16 wIdx);
	BOOL AddNeiDanToBag(CPetNeiDan* poNeiDan);
	BOOL DelNeiDanByBag(CPetNeiDan* poNeiDan, BOOL bIsRemove = FALSE);
	BOOL DressNeiDanToPet(CPet* poPet, CPetNeiDan* poNeiDan);
	BOOL UnDressNeiDanByPet(CPet* poPet, CPetNeiDan* poNeiDan);
	//////////////////////////////�ڵ�����////////////////////////////////////////////

private:
	// ����һ������id
	UINT16				generatePetId();
	UINT16				GenerateNeiDanId(UINT16 wNeiDanID);
	CPet*				CreateTestPet();
private:
	DT_PLAYER_PET_DATA	m_PlayerPetData;
	MapPet				m_mpPet;
	C1616Map m_mapNeiDanID;
	map<UINT16, DT_PET_CALL_DATA> m_mapCallInfo;

	map<UINT32, CPetNeiDan*> m_mapNeiDanBag;//�ڵ�����
	map<UINT32, CPetNeiDan*> m_mapAllNeiDan;//�����ڵ��������������ϣ�
};

DECLARE_CLASS_POOL_MGR(CPlayerPet);

#endif // _PLAYER_PET_
