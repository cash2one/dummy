#include "buffaffect.h"
#include <logic/battle/battleattrobj.h>
#include <common/client/commondef.h>
#include <db/autosqlbuf.h>


//��ֹ
BOOL CBuffAffect_Static::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetCanNormalAttack() = FALSE;
		poActor->GetCanSkillAttack() = FALSE;

		return TRUE;
	}

	//����ֹ�ˣ������غ�(����+�ܻ��غ�)��������,����غ���Ч
	poActor->GetCanDodge() = FALSE;

	return FALSE;
}


//��Ĭ
BOOL CBuffAffect_NoSkill::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetCanSkillAttack() = FALSE;

		return TRUE;
	}

	return FALSE;
}


//�ж�
BOOL CBuffAffect_Poisoning::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{	
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		//��Ѫ
		poActor->AddHPChange(-(INT32)(poGiver->GetDT_BATTLE_ATTRIBUTE().dwAttack * 	wParamValue / 100), ET_BUFF, EHPCR_BUFF, 0);

		return TRUE;
	}
	return FALSE;
}


//˺��
BOOL CBuffAffect_Tear::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{	
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		//��Ѫ
		poActor->AddHPChange(-(INT32)(poGiver->GetDT_BATTLE_ATTRIBUTE().dwAttack * 	wParamValue / 100), ET_BUFF, EHPCR_BUFF, 0);

		return TRUE;
	}
	return FALSE;
}

//���͹���
BOOL CBuffAffect_DecAttack::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		//���ٹ����ٷֱ�(�����˺��ٷֱ�)
		if(wParamValue <= 100 )
		{
			poActor->GetAttackHurtRate() = poActor->GetAttackHurtRate() * (100 - wParamValue) / 100;
		}
		else
		{
			poActor->GetAttackHurtRate() = 0;
		}
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poActor->GetAttackHurtRate());

		

		return TRUE;
	}

	return FALSE;
}


//��Ѫ�� ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱ���������������״̬	
BOOL CBuffAffect_BloodthirstySingle::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		//���������ٷֱ�
		poActor->GetAttackHurtRate() = poActor->GetAttackHurtRate() * (100 + wParamValue) / 100;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poActor->GetAttackHurtRate());
		return TRUE;
	}

	return FALSE;
}


//��Ѫ�� ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱ���������������״̬	
BOOL CBuffAffect_BloodthirstyAll::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		//���������ٷֱ�
		poActor->GetAttackHurtRate() = poActor->GetAttackHurtRate() * (100 + wParamValue) / 100;
		//SYS_CRITICAL(_SDT("[%s: %d]: m_wAttackHurtRate:%d"), MSG_MARK, poActor->GetAttackHurtRate());
		return TRUE;
	}

	return FALSE;
}


//���ˣ�ʹ��ӵ�и�״̬���ܻ�����ʱ�����˺�ֵ����������״̬
BOOL CBuffAffect_DecHurtSingle::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ�ܻ���ʱ��Ч
	if(poNormalAttackTarget == poActor)
	{
		//�����˺��ٷֱ�	
		poActor->GetDecHurtRate() = wParamValue;

		return TRUE;
	}

	return FALSE;
}

//���ˣ�ʹ��ӵ�и�״̬���ܻ�����ʱ�����˺�ֵ����������״̬
BOOL CBuffAffect_DecHurtAll::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ�ܻ���ʱ��Ч
	if(poNormalAttackTarget == poActor)
	{
		//�����˺��ٷֱ�	
		poActor->GetDecHurtRate() = wParamValue;

		return TRUE;
	}

	return FALSE;
}

//����Ѫ��BUFF
BOOL CBuffAffect_AddBlood::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ�ܻ���ʱ��Ч
	if(poAttacker == poActor)
	{
		poActor->AddHPChange( ( dwExtValue * wParamValue / 100), ET_BUFF, EHPCR_BUFF, 0);

		return TRUE;
	}

	return FALSE;
}

//�ӷ�
BOOL CBuffAffect_DefendPercent::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ�ܻ���ʱ��Ч
	if(poNormalAttackTarget == poActor)
	{
		//���ӷ������ٷֱȣ�
		poActor->GetAddDefendRate() = wParamValue;

		return TRUE;
	}

	return FALSE;
}

BOOL CBuffAffect_Frost::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetCanNormalAttack() = FALSE;
		poActor->GetCanSkillAttack() = FALSE;

		return TRUE;
	}

	//����ֹ�ˣ������غ�(����+�ܻ��غ�)��������,����غ���Ч
	poActor->GetCanDodge() = FALSE;

	return FALSE;
}

BOOL CBuffAffect_Chaos::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		if( EBK_NONE == poActor->GetChaos())
		{
			poActor->GetChaos() = EBK_CHAOS;
		}
		poActor->GetCanSkillAttack() = FALSE;
		return TRUE;
	}

	return FALSE;
}

BOOL CBuffAffect_Firing::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		//��Ѫ
		poActor->AddHPChange(-(INT32)(dwExtValue * 	wParamValue / 100), ET_BUFF, EHPCR_BUFF, 0);

		return TRUE;
	}
	return FALSE;
}

BOOL CBuffAffect_Disturb::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetFinalDecHurt() = wParamValue;

		return TRUE;
	}
	return FALSE;
}

BOOL CBuffAffect_NotAnger::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetNotAnger() = TRUE;

		return TRUE;
	}
	return FALSE;
}

BOOL CBuffAffect_Sleep::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetCanNormalAttack() = FALSE;
		poActor->GetCanSkillAttack() = FALSE;

		return TRUE;
	}
	return FALSE;
}

BOOL CBuffAffect_Dreamland::Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue)
{
	if(EBAP_ROUND_BEGIN != ePhase)
	{
		return FALSE;
	}

	//�Լ�Ϊ������ʱ��Ч
	if(poActor == poAttacker)
	{
		poActor->GetChaos() = EBK_DREAMLAND;
		poActor->GetCanSkillAttack() = FALSE;
		poActor->GetFinalAddHurt() += wParamValue;	
		return TRUE;
	}

	return FALSE;
}

