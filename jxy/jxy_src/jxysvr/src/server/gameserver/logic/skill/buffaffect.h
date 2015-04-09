

#ifndef _BUFFAFFECT_H_
#define _BUFFAFFECT_H_


#include <sdtype.h>
#include <common/client/commondef.h>

using namespace std ;


//buff���ý׶�
//Ŀǰ����buff�����ý׶�ȫ����Ϊ�غϿ�ʼ�׶Σ�����
enum EBuffAffectPhase
{
	EBAP_ROUND_BEGIN = 1, //�غϿ�ʼ�׶�
	//EBAP_BEFORE_HIT = 2, //����ǰ
	//EBAP_BEFORE_COUNT_HURT = 3, //���к󣬼����˺�ǰ
	//EBAP_AFTER_COUNT_HURT = 4, //���к󣬼����˺���
};



//buff����Ŀ��
enum EBuffTarget
{
	EBT_MYSELF = 1, //�Լ�
	EBT_ENEMY = 2, //����
	EBT_MYALL = 3, //�Լ�ȫ��
	EBT_MY_FIRST = 4,//�ҷ�һ��
};

class CBattleAttrObj;
class CBuffAffectHandler;

/**
* @brief buffЧ�����ýӿڻ���
*/
class CBuffAffect
{
public:
	CBuffAffect(){};
    virtual ~CBuffAffect(){};

public:


    /**
    * @brief
    * Ч�����ú����ӿڣ����еĲ������ǵ��øýӿ�
    * @return VOID
    */
    virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue) = 0;

	virtual EBuffKind GetBuffState() = 0;
	virtual EBuffTarget GetBuffTarget() = 0;
	virtual BOOL BigRound() = 0; 
	// ȥ���������ܼ������������ܣ�����buffĿ��Ϊ�Լ�����������ʱ�������buff��debuffĿ��Ϊ�Է������к����
	//virtual	BOOL WantHit() = 0; //�Ƿ������в������buff 
protected:


protected:

};



//��ֹ,�ݶ�ӵ�и�״̬�߱��غ��ڹ��������ڸ���״̬
class CBuffAffect_Static: public CBuffAffect
{
public:
	static CBuffAffect_Static* Instance() { static CBuffAffect_Static oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_Static(){};        
	~CBuffAffect_Static(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_STATIC; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return TRUE; } ;
	//virtual	BOOL WantHit() { return TRUE; }

};


//��Ĭ���ݶ�ӵ�и�״̬�߱��غ���ʹ�ü��ܣ����ڸ���״̬
class CBuffAffect_NoSkill: public CBuffAffect
{
public:
	static CBuffAffect_NoSkill* Instance() { static CBuffAffect_NoSkill oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_NoSkill(){};        
	~CBuffAffect_NoSkill(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_NO_SKILL; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return TRUE; } ;
	//virtual	BOOL WantHit() { return TRUE; }
	
};


//�ж���ʹ��ӵ�и�״̬�߱��غ��ڵ��ٷֱ�Ѫ�������ڸ���״̬
class CBuffAffect_Poisoning: public CBuffAffect
{
public:
	static CBuffAffect_Poisoning* Instance() { static CBuffAffect_Poisoning oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_Poisoning(){};        
	~CBuffAffect_Poisoning(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_POISONING; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; } ;
	//virtual	BOOL WantHit() { return TRUE; }
	
};

//˺�ѣ�ʹ��ӵ�и�״̬�߱��غ��ڵ��ٷֱ�Ѫ�������ڸ���״̬
class CBuffAffect_Tear: public CBuffAffect
{
public:
	static CBuffAffect_Tear* Instance() { static CBuffAffect_Tear oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_Tear(){};        
	~CBuffAffect_Tear(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_TEAR; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; } ;
	//virtual	BOOL WantHit() { return TRUE; }

};

//�зϣ�ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱȽ��ͣ����ڸ���״̬
class CBuffAffect_DecAttack: public CBuffAffect
{
public:
	static CBuffAffect_DecAttack* Instance() { static CBuffAffect_DecAttack oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_DecAttack(){};        
	~CBuffAffect_DecAttack(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_DEC_ATTACK; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return TRUE; } ;
	//virtual	BOOL WantHit() { return TRUE; }
	
};

//��Ѫ(����)�� ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱ���������������״̬	
class CBuffAffect_BloodthirstySingle: public CBuffAffect
{
public:
	static CBuffAffect_BloodthirstySingle* Instance() { static CBuffAffect_BloodthirstySingle oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_BloodthirstySingle(){};        
	~CBuffAffect_BloodthirstySingle(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_BLOODTHIRSTY_S; }
	virtual EBuffTarget GetBuffTarget() { return EBT_MYSELF; }
	virtual BOOL BigRound() { return TRUE; } ;
	//virtual	BOOL WantHit() { return FALSE; }
};


//��Ѫ(ȫ��)�� ʹ��ӵ�и�״̬�߱��غ��ڹ��������ٷֱ���������������״̬	
class CBuffAffect_BloodthirstyAll: public CBuffAffect
{
public:
	static CBuffAffect_BloodthirstyAll* Instance() { static CBuffAffect_BloodthirstyAll oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_BloodthirstyAll(){};        
	~CBuffAffect_BloodthirstyAll(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_BLOODTHIRSTY_A; }
	virtual EBuffTarget GetBuffTarget() { return EBT_MYALL; }
	virtual BOOL BigRound() { return TRUE; } ;
	//virtual	BOOL WantHit() { return FALSE; }
};

//����(����)��ʹ��ӵ�и�״̬���ܻ�����ʱ�����˺�ֵ����������״̬
class CBuffAffect_DecHurtSingle: public CBuffAffect
{
public:
	static CBuffAffect_DecHurtSingle* Instance() { static CBuffAffect_DecHurtSingle oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_DecHurtSingle(){};        
	~CBuffAffect_DecHurtSingle(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_DECHURT_S; }
	virtual EBuffTarget GetBuffTarget() { return EBT_MYSELF; }
	virtual BOOL BigRound() { return FALSE; } ;
	//virtual	BOOL WantHit() { return TRUE; }
};


//����(ȫ��)��ʹ��ӵ�и�״̬���ܻ�����ʱ�����˺�ֵ����������״̬
class CBuffAffect_DecHurtAll: public CBuffAffect
{
public:
	static CBuffAffect_DecHurtAll* Instance() { static CBuffAffect_DecHurtAll oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_DecHurtAll(){};        
	~CBuffAffect_DecHurtAll(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_DECHURT_A; }
	virtual EBuffTarget GetBuffTarget() { return EBT_MYALL; }
	virtual BOOL BigRound() { return FALSE; } ;
	//virtual	BOOL WantHit() { return TRUE; }
};

class CBuffAffect_AddBlood: public CBuffAffect
{
public:
	static CBuffAffect_AddBlood* Instance() { static CBuffAffect_AddBlood oBuffAffet; return &oBuffAffet;}
protected:
	CBuffAffect_AddBlood(){};        
	~CBuffAffect_AddBlood(){};
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_ADD_BLOOD; }
	virtual EBuffTarget GetBuffTarget() { return EBT_MY_FIRST; }
	virtual BOOL BigRound() { return FALSE; } ;
};

//���ӷ������ٷֱȣ�,Ϊǰ�ŵ������ӷ�������������״̬
class CBuffAffect_DefendPercent : public CBuffAffect
{
public:
	static CBuffAffect_DefendPercent* Instance()
	{ 
		static CBuffAffect_DefendPercent oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_DefendPercent(){}
	~CBuffAffect_DefendPercent(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_DEFEND_PERCENT; }
	virtual EBuffTarget GetBuffTarget() { return EBT_MY_FIRST; }
	virtual BOOL BigRound() { return FALSE; }
};

//���ᣬʹĿ�궳�ᣬ��ͣ��״̬�߻غ��ڹ��������ڸ���״̬
class CBuffAffect_Frost : public CBuffAffect
{
public:
	static CBuffAffect_Frost* Instance()
	{ 
		static CBuffAffect_Frost oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_Frost(){}
	~CBuffAffect_Frost(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_FROST; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};

//���ң�ʹ��״̬�߲��ֵ���ѡ��Ŀ�깥�������ڸ���״̬
class CBuffAffect_Chaos : public CBuffAffect
{
public:
	static CBuffAffect_Chaos* Instance()
	{ 
		static CBuffAffect_Chaos oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_Chaos(){}
	~CBuffAffect_Chaos(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_CHAOS; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};

//���գ�ʹĿ����ʧ���������ڸ���״̬
class CBuffAffect_Firing : public CBuffAffect
{
public:
	static CBuffAffect_Firing* Instance()
	{ 
		static CBuffAffect_Firing oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_Firing(){}
	~CBuffAffect_Firing(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_FIRING; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};

//���ţ����͹����˺������ڸ���״̬
class CBuffAffect_Disturb : public CBuffAffect
{
public:
	static CBuffAffect_Disturb* Instance()
	{ 
		static CBuffAffect_Disturb oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_Disturb(){}
	~CBuffAffect_Disturb(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_DISTURB; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};

//ʧȥ��־��ʹĿ���������ڼ����޷����ŭ�������ڸ���״̬
class CBuffAffect_NotAnger : public CBuffAffect
{
public:
	static CBuffAffect_NotAnger* Instance()
	{ 
		static CBuffAffect_NotAnger oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_NotAnger(){}
	~CBuffAffect_NotAnger(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_NOT_ANGER; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};

//��˯��ʹĿ���˯�غ����޷����������ڸ���״̬
class CBuffAffect_Sleep : public CBuffAffect
{
public:
	static CBuffAffect_Sleep* Instance()
	{ 
		static CBuffAffect_Sleep oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_Sleep(){}
	~CBuffAffect_Sleep(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_SLEEP; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};

class CBuffAffect_Dreamland : public CBuffAffect
{
public:
	static CBuffAffect_Dreamland* Instance()
	{ 
		static CBuffAffect_Dreamland oBuffAffect; return &oBuffAffect;
	}
protected:
	CBuffAffect_Dreamland(){}
	~CBuffAffect_Dreamland(){}
public:
	virtual BOOL Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, CBattleAttrObj* poNormalAttackTarget, UINT32 dwExtValue);
	virtual EBuffKind GetBuffState() { return EBK_DREAMLAND; }
	virtual EBuffTarget GetBuffTarget() { return EBT_ENEMY; }
	virtual BOOL BigRound() { return FALSE; }
};
#endif //#ifndef _BUFFAFFECT_H_

