///<------------------------------------------------------------------------------
//< @file:   logic\pet\pet.h
//< @author: yewenhui10@qq.com
//< @date:   2014��8��6�� 16:42:00
//< @brief:  �������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------
#ifndef _PET_H_ 
#define _PET_H_

#include <logic/battle/battleattrobj.h>
#include "logic/pet/petdef.h"
#include "logic/pet/petskill.h"

class PetStarCfg;
class CPlayer;
class CPetNeiDan;

class CPet :
	public CBattleAttrObj
{
public:
	CPet();
	~CPet();
	//////////////////////////////////ս�����////////////////////////////////////////////
	VOID			StartPetBattle();
	UINT32&			GetLastHurt(){ return m_dwLastHurt;}
	CPetSkill*& GetSecondHrut(){ return m_poSecondHurt; }
	BOOL&			GetSkillCritical() { return m_bSkillCritical;}
	///////////////////////////////////////ս�����////////////////////////////////////////
	BOOL			Init(const DT_PET_DATA& rPetData, CPlayer* pPlayer, const DT_PET_NEIDAN_DATA_LST& stNeiDanData);
	DT_PET_DATA&	GetDT_PET_DATA();
	DT_PET_NEIDAN_DATA_LST& GetDT_NeiDan_Data() { return m_stNeiDanData; }
	const DT_PET_DATA&	GetDT_PET_DATA() const;

	// todo
	VOID			SetPetId(UINT16 usPetId);
	UINT16			GetPetId() const {
		return m_PetData.wPetId;
	}

	VOID			FillDT_PET_CLI_DATA(DT_PET_CLI_DATA& rCliPetData) const;

	// �����ɵľ���
	UINT32			GetBeAteExp() const;
	// ��ȡ����
	UINT32			GetLingli() const;
	// ���Ӿ���
	VOID			AddPetExp(UINT32 unAddPetExp, BOOL bUpStarLv = FALSE);
	// ��ǰ����
	UINT32			GetCurPsychic() const;
	// �������
	UINT32			GetMaxPsychic() const;
	UINT16			GetLevel() const ;
	// CBattleAttrObj
	virtual inline UINT8 GetFormationIdx();

	const PetStarCfg* GetPetStarCfg() const;
	CPetSkill* GetCurSkill() ;
	BOOL EnterNextSkill();
	//��ȡ��������
	UINT64 GetPetScore() const ;
	//��ȡ���ﵵ��
	UINT8 GetPetGrade()const ;

	BOOL DressNeiDan(CPetNeiDan* poNeiDan);
	CPetNeiDan* UnDressNeiDan(UINT8 byPosType);
	
	VOID GetNeiDanCli(DT_PET_NEIDAN_CLI& stNeiDanCli);
	VOID GetNeiDanMark(DT_NEIDAN_PET_MARK_LST_DATA& stMark);
protected:
	// CBattleAttrObj
	virtual VOID	InitBattleAttribute();
	VOID InitSkill();
private:
	DT_PET_DATA		m_PetData;
	DT_PET_NEIDAN_DATA_LST m_stNeiDanData;//�ڵ���Ϣ
	map<UINT8, CPetNeiDan*> m_mapNeiDan;//�ڵ�



	UINT32			m_dwLastHurt;//�ϴ���ɵ��˺�
	CPetSkill*		m_poSecondHurt;//�����˺���ʶ
	BOOL			m_bSkillCritical;//���ܱ�ʶ
	vector<CPetSkill*> m_vecSkill;		//��������
	UINT32			m_dwSkillIdx;//���ܱ�ʶ
	UINT32			m_dwRoundIdx;//��ǰ�����غ�
	UINT32			m_dwCurLingMaiNum;//��ǰ���������
};

#endif //_PET_H_
