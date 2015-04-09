
#include "skillaffect.h"
#include "buff.h"
#include <common/client/commondef.h>
#include <logic/battle/battleobj.h>
#include <logic/battle/battleattrobj.h>
#include "logic/hero/hero.h"
#include "logic/pet/pet.h"

//�˺�
BOOL CSkillOnceAffect_Hurt::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}

	return FALSE;
}


BOOL CSkillOnceAffect_SingleCure::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100);
		//wParamValueΪ��Ϊ��Ѫ�ٷֱ�
		UINT32 dwCureHP = poAttacker->GetDT_BATTLE_ATTRIBUTE().dwAttack * wParamValue / 100;
		poAttacker->AddHPChange(dwCureHP, ET_SKILL, EHPCR_BUFF, poAttacker->GetFormationIdx());
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}

	return FALSE;
}

BOOL CSkillOnceAffect_WholeCure::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100);

		//wParamValueΪ��Ϊ��Ѫ�ٷֱ�
		UINT32 dwCureHP = poAttacker->GetDT_BATTLE_ATTRIBUTE().dwAttack * wParamValue / 100;
		for(UINT8 byIdx = 0; byIdx < MAX_FORMATION_IDX_NUM+1; byIdx++)
		{
			CBattleAttrObj* poObj = poMyself->GetFormationObj(byIdx);
			if((poObj) && (!poObj->IsDead()))
			{
				poObj->AddHPChange(dwCureHP, ET_SKILL, EHPCR_BUFF, poAttacker->GetFormationIdx());
				poObj->AddSkillEffectID(GetSkillEffectKind());
			}
		}

		return TRUE;
	}

	return FALSE;
}


BOOL CSkillOnceAffect_DecAngry::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100);	
		return TRUE;
	}
	if(ESAP_HIT_HURT == ePhase)
	{
		//wParamValue�ԶԷ����͵�ŭ��ֵ
		if(poTarget)
		{
			poTarget->AddSkillEffectID(GetSkillEffectKind());
			poTarget->AddAngryChange((INT16)(-wParamValue));
		}	
		return TRUE;
	}


	return FALSE;
}

//����������
 
BOOL CSkillOnceAffect_SecondAttack::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate / 100;
		poAttacker->AddSkillExtHur(dwExtHurtValue);

		return TRUE;
	}
	else if (ESAP_SECOND_ATTACK == ePhase)
	{
		CPet* poPet = dynamic_cast<CPet*>(poAttacker);
		if ( NULL != poPet)
		{
			poTarget->AddHPChange( -(INT32)(poPet->GetLastHurt() * wParamValue / 100), ET_PET_SKILL, EHPCR_NORMAL_SKILL, 0);
		}
		return TRUE;
	}
	return FALSE;
}

//��ϵ����
BOOL CSkillOnceAffect_Critial::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wSkillCritical = 100;
		CPet* poPet = dynamic_cast<CPet*>(poAttacker);
		if ( NULL != poPet)
		{
			UINT32 dwRandowValue = RandomReseed(1000) % 100;
			if ( dwRandowValue < wEffectRate)
			{
				poPet->GetSkillCritical() = TRUE;
				wSkillCritical = wParamValue;
			}
		}
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wSkillCritical / 10000;
		
		poAttacker->AddSkillExtHur(dwExtHurtValue);
		return TRUE;
	}
	return FALSE;
}

BOOL CSkillOnceAffect_Water::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}

	return FALSE;
}

//����
BOOL CSkillOnceAffect_Soil::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//������

BOOL CSkillOnceAffect_Ice::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//ɰ����
BOOL CSkillOnceAffect_Sand::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//������

BOOL CSkillOnceAffect_Spark::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//���겻ɢ

BOOL CSkillOnceAffect_Haunting::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//����þ�

BOOL CSkillOnceAffect_Drame::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//��ǣ����

BOOL CSkillOnceAffect_Soul::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}

//�Ϲ����

BOOL CSkillOnceAffect_Charm::Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget)
{
	if(ESAP_BEFORE_COUNT_HURT == ePhase)
	{
		UINT16 wAttackRankHurtRate = poAttacker->GetAttackRankHurtRate();
		poAttacker->GetSkillHurtRate() = poAttacker->GetSkillHurtRate() * wHurtRate * wAttackRankHurtRate/ 10000;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poAttacker->GetSkillHurtRate());
		UINT32 dwJewelryExtHur = 0;
		CHero* poHero = dynamic_cast<CHero*>(poAttacker);
		if ( NULL != poHero)
		{
			dwJewelryExtHur = poHero->GetJewelryAttr(EJEA_SKILL_ATTACK);
		}
		poAttacker->AddSkillExtHur(dwExtHurtValue * wAttackRankHurtRate / 100 + dwJewelryExtHur);
		poAttacker->AddSkillEffectID(GetSkillEffectKind());
		return TRUE;
	}
	return FALSE;
}
