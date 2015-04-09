///<------------------------------------------------------------------------------
//< @file:   logic\pet\petskill.h
//< @author: Kang_zhiquan
//< @date:   2014��8��27�� 10:1:51
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _petskill_h_
#define _petskill_h_
#include "logic/battle/battleobj.h"
#include "common/server/utility.h"
#include "logic/skill/skillpropmgr.h"
#include "logic/skill/skillaffect.h"
#include "logic/base/baseobj.h"
class CPetSkill : public CBaseObj
{
public:
	CPetSkill();
	~CPetSkill();
	BOOL Init(UINT16 wSkillID, CPlayer* poPlayer, CPet* poPet);
	UINT16 GetID();
	const SPetSkillEffectProp& GetSkillProp()
	{
		return m_stProp;
	}
	UINT8 GetAttackType();
	//��ȡ��������
	UINT8 GetSkillType();
	//��ȡ�˺�����
	UINT16 GetHurtRate();
	//��ȡ�����˺�����
	UINT16 GetFinalHurtRate();
	//��ȡ���⹥������
	UINT32 GetOnceParam();
	VOID GetTriger(vector<CBattleAttrObj*>& vecObj, CBattleObj* poBattleObj);
	BOOL Use(ESkillAffectPhase ePhase, CBattleObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, CPet* poSkillOwner,
		vector<CBattleAttrObj*>& vecEnemyTargetObj, CBattleAttrObj* poSingleTarget = NULL);//ʹ�ü���
	VOID SetPetSkillProp();
	
protected:
	
private:
	UINT16 m_wSkillID;//����ID
	SPetSkillEffectProp m_stProp;
	CPet* m_poPet;
};



DECLARE_CLASS_POOL_MGR(CPetSkill);
#endif //_petskill_h_