///<------------------------------------------------------------------------------
//< @file:   logic\specialeffects\specialeffects.h
//< @author: Kang_zhiquan
//< @date:   2014��6��4�� 17:28:12
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _specialeffects_h_
#define _specialeffects_h_
#include "logic/base/baseobj.h"
#include "protocol/server/protocligs.h"
#include "utility.h"
#include "logic/base/basedefine.h"
#include "commondef.h"
#include "logic/specialeffects/specialeffectsmgr.h"
class CPlayer;
class CBattleAttrObj;
class CSoul;
class CSpecialEffect : public CBaseObj
{
public:
	CSpecialEffect()
	{
		memset(&m_stSpecialEffectData, 0, sizeof(DT_SPECIAL_EFFECT_DATA));
		m_wLimitNum = 0;
		m_bySelectIdx = 0;
		m_poMySelf = NULL;
		m_wExtLimitNum = 0;
		m_wExtEffectPercent = 0;
		m_wExtTrigerProb = 0;
	}
	~CSpecialEffect()
	{
		memset(&m_stSpecialEffectData, 0, sizeof(DT_SPECIAL_EFFECT_DATA));
		m_wLimitNum = 0;
		m_bySelectIdx = 0;
		m_poMySelf = NULL;
		m_wExtLimitNum = 0;
		m_wExtEffectPercent = 0;
		m_wExtTrigerProb = 0;
	}
	DT_SPECIAL_EFFECT_DATA& GetSpecialEffectData(){ return m_stSpecialEffectData; }
	BOOL GetSpecialEffectDataCli(DT_SPECIAL_EFFECT_DESC& stCli);
	virtual ATTACK_TYPE GetAttackType() = 0;

	VOID SetOwner(CBattleAttrObj* poObj);
public:
	BOOL Init(CPlayer* poPlayer, CBattleAttrObj* poMySelf, const DT_SPECIAL_EFFECT_DATA& stData, UINT8 bySelectIdx);
	//�Ƿ��ܼ���
	BOOL IsActivity();
	//����
	BOOL SetActivity();
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag) = 0;
	//����ս������
	virtual VOID ResetData();
	//�������ô���
	VOID AddEffectNum();
	//��ȡ��ЧID
	UINT16 GetEffectID();
	//��ȡ��Ч������
	UINT8 GetEffectBigType();
	//��ȡ��ЧС����
	UINT8 GetEffectSmallType();
	//��ȡʣ�����ô���
	UINT16 GetLeftEffectNum();
	//��ȡ��Ч����
	UINT32 GetTrigerProb();
	//��ȡЧ����
	UINT16 GetEffectPercent();
	//��ȡ����
	const SSpecialEffectProp* GetProp();

	VOID SetExtLimit(UINT16 );
	VOID SetExtEffectPercent(UINT16);
	VOID SetExtTrigerProb(UINT16);
protected:
	CBattleAttrObj* m_poMySelf;//������
	DT_SPECIAL_EFFECT_DATA m_stSpecialEffectData;
	UINT16 m_wLimitNum;//�����ô���
	UINT8 m_bySelectIdx;

	UINT16 m_wExtLimitNum;//�������ô���
	UINT16 m_wExtEffectPercent;//����Ч��
	UINT16 m_wExtTrigerProb;//���ⴥ������
};

class CAttackSpecialEffect : public CSpecialEffect
{
	
};

class CDefendSpecialEffect : public CSpecialEffect
{

};
//����
class CContinueAttackEffect : public CAttackSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	 ATTACK_TYPE GetAttackType() { return EAT_ATTACK;}
};
//��Ѫ
class CSuckBloodEffect : public CAttackSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_ATTACK;}
};
//����
class CPhysicalImmunityEffect : public CAttackSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_ATTACK;}
};
//ħ��
class CMagicImmunityEffect : public CAttackSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_ATTACK;}
};
//����
class CAddBloodEffect : public CDefendSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_DEFEND;}
};
//����
class CReboundEffect : public CDefendSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_DEFEND;}
};
//����
class CBeatBack : public CDefendSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_DEFEND;}
};
//����
class CDodgeEffect : public CDefendSpecialEffect
{
public:
	//��Ч������
	virtual VOID Effect(UINT64 dwHurtValue, BOOL bIsSkill, CBattleAttrObj* poEnemy, CSpecialEffect* poEnemyEffect, UINT8* bySpecialEffectFlag);
	ATTACK_TYPE GetAttackType() { return EAT_DEFEND;}
};
DECLARE_CLASS_POOL_MGR(CContinueAttackEffect)
DECLARE_CLASS_POOL_MGR(CSuckBloodEffect)
DECLARE_CLASS_POOL_MGR(CPhysicalImmunityEffect)
DECLARE_CLASS_POOL_MGR(CMagicImmunityEffect)
DECLARE_CLASS_POOL_MGR(CAddBloodEffect)
DECLARE_CLASS_POOL_MGR(CReboundEffect)
DECLARE_CLASS_POOL_MGR(CBeatBack)
DECLARE_CLASS_POOL_MGR(CDodgeEffect)
#endif //_specialeffects_h_
