

#ifndef _SKILLAFFECT_H_
#define _SKILLAFFECT_H_


#include <sdtype.h>
#include <common/client/commondef.h>

using namespace std ;

class CBattleObj;
class CBattleAttrObj;




//����Ч�����ý׶Σ�1���غ��ڻ�����׶α�����2�Σ��ҷ�/�з�����ʱ
//Ŀǰ�϶�����
enum ESkillAffectPhase
{
	ESAP_BEFORE_COUNT_HURT = 1, //�����˺�ǰ
	//ESAP_AFTER_COUNT_HURT = 2, //�����˺���
	ESAP_HIT_HURT = 3, //�˺�����(���˺�������)
	ESAP_SECOND_ATTACK = 4,//�����˺�
};


class CSkillOnceAffectHandler;
/**
* @brief ����Ч�����ýӿڻ���
*/
class CSkillOnceAffect
{
public:
	CSkillOnceAffect(){};
    virtual ~CSkillOnceAffect(){};

public:

	//�������ò����Buff(����)
    virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget) = 0;

	virtual ESkillEffectKind GetSkillEffectKind() = 0;
	
	
protected:
	
protected:
};

//�˺�
class CSkillOnceAffect_Hurt: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Hurt* Instance() { static CSkillOnceAffect_Hurt oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Hurt(){};        
	~CSkillOnceAffect_Hurt(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_HURT; } 
};



//�����Ѫ
class CSkillOnceAffect_SingleCure: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_SingleCure* Instance() { static CSkillOnceAffect_SingleCure oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_SingleCure(){};        
	~CSkillOnceAffect_SingleCure(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_SINGLECUER; } 
};


//ȫ���Ѫ
class CSkillOnceAffect_WholeCure: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_WholeCure* Instance() { static CSkillOnceAffect_WholeCure oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_WholeCure(){};        
	~CSkillOnceAffect_WholeCure(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_WHOLECUER; } 
};

//����
class CSkillOnceAffect_DecAngry: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_DecAngry* Instance() { static CSkillOnceAffect_DecAngry oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_DecAngry(){};        
	~CSkillOnceAffect_DecAngry(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_DECANGRY; } 
};

//����������
class CSkillOnceAffect_SecondAttack: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_SecondAttack* Instance() { static CSkillOnceAffect_SecondAttack oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_SecondAttack(){};        
	~CSkillOnceAffect_SecondAttack(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_SECOND_ATTACK; } 
};
//��ϵ����

class CSkillOnceAffect_Critial : public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Critial* Instance() { static CSkillOnceAffect_Critial oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Critial(){};        
	~CSkillOnceAffect_Critial(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_CRITICAL; } 
};

//ˮ��
class CSkillOnceAffect_Water: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Water* Instance() { static CSkillOnceAffect_Water oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Water(){};        
	~CSkillOnceAffect_Water(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_WATER; } 
};
//����
class CSkillOnceAffect_Soil: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Soil* Instance() { static CSkillOnceAffect_Soil oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Soil(){};        
	~CSkillOnceAffect_Soil(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_SOIL; } 
};
//������
class CSkillOnceAffect_Ice: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Ice* Instance() { static CSkillOnceAffect_Ice oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Ice(){};        
	~CSkillOnceAffect_Ice(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_ICE; } 
};
//ɰ����
class CSkillOnceAffect_Sand: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Sand* Instance() { static CSkillOnceAffect_Sand oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Sand(){};        
	~CSkillOnceAffect_Sand(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_SAND; } 
};
//������
class CSkillOnceAffect_Spark: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Spark* Instance() { static CSkillOnceAffect_Spark oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Spark(){};        
	~CSkillOnceAffect_Spark(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_SPARK; } 
};
//���겻ɢ
class CSkillOnceAffect_Haunting: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Haunting* Instance() { static CSkillOnceAffect_Haunting oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Haunting(){};        
	~CSkillOnceAffect_Haunting(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_HAUNTING; } 
};
//����þ�
class CSkillOnceAffect_Drame: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Drame* Instance() { static CSkillOnceAffect_Drame oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Drame(){};        
	~CSkillOnceAffect_Drame(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_DERAM; } 
};
//��ǣ����
class CSkillOnceAffect_Soul: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Soul* Instance() { static CSkillOnceAffect_Soul oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Soul(){};        
	~CSkillOnceAffect_Soul(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_SOUL; } 
};
//�Ϲ����
class CSkillOnceAffect_Charm: public CSkillOnceAffect
{
public:
	static CSkillOnceAffect_Charm* Instance() { static CSkillOnceAffect_Charm oSkillAffet; return &oSkillAffet;}
protected:
	CSkillOnceAffect_Charm(){};        
	~CSkillOnceAffect_Charm(){};
public:
	virtual BOOL Affect (ESkillAffectPhase ePhase, CBattleAttrObj* poAttacker, CBattleObj* poMyself, CBattleObj* poEnemy, UINT16 wHurtRate, UINT32 dwExtHurtValue, UINT16 wParamValue, UINT16 wEffectRate, CBattleAttrObj* poTarget);
	virtual ESkillEffectKind GetSkillEffectKind() { return ESEK_CHARM; }

	ESkillEffectKind m_eLastEffect;

};


#endif //#ifndef _BUFFAFFECT_H_

