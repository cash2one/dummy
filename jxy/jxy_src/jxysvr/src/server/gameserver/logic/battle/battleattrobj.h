
#ifndef _BATTLEATTROBJ_H_
#define _BATTLEATTROBJ_H_


#include <sdtype.h>
#include <protocol/server/protocommondata.h>
#include <logic/base/baseobj.h>
#include <logic/skill/skill.h>
#include <logic/skill/buffmgr.h>
#include <logic/battle/otherlife.h>
#include "logic/base/basedefine.h"
class CSpecialEffect;
typedef HashMap<UINT8, CBuff*> CBuffID2BuffMap; //keyΪBuffKindID
typedef CBuffID2BuffMap::iterator CBuffID2BuffMapItr;

typedef HashMap<UINT32, DT_BUFF_DATA> CBuffDataMap; //keyΪskillID+buffID
typedef CBuffDataMap::iterator CBuffDataMapItr;

typedef map<UINT32, CSpecialEffect*> CMapID2SpecialEffect;
typedef CMapID2SpecialEffect::iterator CMapID2SpecialEffectItr;

#define ROUND_ANGRY 50	//�غ����ӵ�ŭ��
#define FULL_ANGRY	100 //��ŭ��ֵ

class CBattleObj;
struct DT_BATTLE_OBJ_HP;

//ս�������࣬��ս�����Ե��඼�̳и���
class CBattleAttrObj:public CBaseObj
{
	friend class CBattleObj;
public:
	CBattleAttrObj();
	~CBattleAttrObj();
public:	
	DT_BATTLE_BASE_ATTRIBUTE&	GetDT_BATTLE_ATTRIBUTE() 
	{ 
		return m_stBattleAttribute;
	}
	DT_HIDE_BATTLE_ATTRIBUTE& GetDT_HIDE_BATTLE_ATTRIBUTE() {  return m_stHideBattleAttr; }
	DT_EXT_BATTLE_ATTRIBUTE& GetDT_EXT_BATTLE_ATTRIBUTE() {  return m_stExtBattleAttr; }

	virtual inline UINT8 GetFormationIdx() = 0;
protected:
	virtual VOID InitBattleAttribute() = 0;//��m_stBattleAttribute��ֵ		
protected:
	DT_BATTLE_BASE_ATTRIBUTE			m_stBattleAttribute;	//ÿ�������ս������(ֻ�洢���ڴ棬���洢�����ݿ�)
	DT_BATTLE_BASE_ATTRIBUTE			m_stCurBattleAttribute;	//��ǰս������ֵ��ÿ�ν��븱��������,ս��������+buffӰ��ֵ��Ѫ��������ֱ��+���������ͷ�����ֻ��buff�غ�����Ч				
	DT_HIDE_BATTLE_ATTRIBUTE		m_stHideBattleAttr;		//ÿ�����������ս������
	DT_EXT_BATTLE_ATTRIBUTE		m_stExtBattleAttr;		//ÿ���������չս������
	
	CBuffID2BuffMap					m_mapKindID2Buff;		//���ڲ����Ƿ���ڸ�buff���޵���Ч����ѯ��
	CSkill*							m_apoSlotSKill[MAX_SKILL_SLOT_NUM+1];//���ܲ��еļ���	
	CSkill**						m_ppoFormationSkill; //��ʹ�õ�1�����ܲ۵ļ��ܣ�������չ���޸�
	COtherLife*						m_poOtherLife;//��������������
protected:
	VOID InitBattleMidParam();//��ʼ��ս���м����
public:
	inline DT_BATTLE_BASE_ATTRIBUTE& GetCurDT_BATTLE_ATTRIBUTE() 
	{
		return m_stCurBattleAttribute;
	}
	inline BOOL IsDead() { return (0 == m_stCurBattleAttribute.qwHP) ? TRUE : FALSE ; }
	inline BOOL& CanGetData() { return m_bCanGetData; }
	inline CSkill* GetFormationSkill() { return *m_ppoFormationSkill; }
	VOID InitCurBattleAttr(DT_BATTLE_OBJ_HP *pstInitHP = NULL);

    void BeStrong(UINT16 wStrongPercent);
	VOID BuffRoundDec(BOOL bEndBigRound);

	VOID ResetBattleRadom();
	//////////////////////////////////������Ч////////////////////////////////////////
	//�����Ч���ô���
	virtual VOID ResetSpecialEffects();
	virtual VOID ReleaseSpecialEffect();
	//��������״̬
	VOID SetPhysicalImmunity(BOOL bState);
	//����ħ��״̬
	VOID SetMagicImmumity(BOOL bState);
	//��ȡ����״̬
	BOOL GetPhysicalImmunity();
	//��ȡħ��״̬
	BOOL GetMagicImmumity();
	//���ָ������
	BOOL AddSpecialEffects( CSpecialEffect* poEffect);
	//ɾ��ָ����Ч
	 CSpecialEffect* DelSpecialEffects(UINT8 bySpecialEffectID);
	 //��ȡ�����Ĺ�����Ч
	 //���ܹ�����ʱ��IsSkillΪTURE
	 CSpecialEffect* GetSpecialEffectsByAttack(BOOL bIsSkill);
	 //��ȡ�����ķ�����Ч
	 CSpecialEffect* GetSpecialEffectsByDefend(BOOL bIsSkill);
	//��������״̬
	 VOID SetContinueAttack(CSpecialEffect* poEffect);
	 //��ȡ����״̬
	 CSpecialEffect* GetContinueAttack();
	 //���÷���״̬
	 VOID SetBeatBack(CSpecialEffect* poEffect);
	 //��ȡ����״̬
	 CSpecialEffect* GetBeatBack();
	//////////////////////////////////������Ч////////////////////////////////////////
	VOID RemoveBuff(CBuff* poBuff);
	//�ͷ�ս�������е�buff
	VOID ReleaseBuff();
	CSkill* TrigerSkill();//�Ƿ񴥷�����(�п���δ���м���)������NULLΪδ���м��ܣ�ʹ����ͨ����	
	BOOL AddBuff(CBuff* poBuff);//���buff
	BOOL AddSkillEffectID(UINT16 wSkillEffectID);//��Ӽ���Ч��ID

	CBuffID2BuffMap& GetAllBuff() { return  m_mapKindID2Buff; }	
	VOID AddHPChange(INT32 nHP, EATTACK_TYPE bAttackType, UINT8 byReason, UINT8 byEmenyIdx, BOOL bAddToVec = TRUE);
	VOID AddAngryChange(INT16 shAngry);
	inline BOOL HaveBuff(UINT8 byBuffKind) {  return m_mapKindID2Buff.find(byBuffKind) != m_mapKindID2Buff.end() ? TRUE : FALSE; }

	VOID SetOtherLife(COtherLife* poOtherLife) 
	{ 
		m_poOtherLife = poOtherLife; 
	}
	COtherLife* GetOtherLife() { return m_poOtherLife; }

public:	
	UINT32	GetCurAttack(CBattleAttrObj* poTarget = NULL, UINT16 wAttackScale = 100);//��õ�ǰ�Ĺ�����
	VOID	CKParryHurt(CBattleAttrObj* poTarget);//�жϸ�/�˺����񵲷���TRUE
	VOID	OnRoundEnd(CBattleAttrObj* poAttacker, CBattleAttrObj* poBettacker) ;//����غϽ�����ŭ�����㣬����ûغϵĸ���Ч����������غϵ���buff���
	UINT16	GetAttackRankHurtRate(); const //��ù�����Χ���˺�����
	/////////////////////////////////////////////////////////////////////////	
	inline UINT16 GetSkillActionID() const { return m_wSkillActionID; }
	inline UINT16 GetCurAngry() { return m_wCurAngry; }
	inline vector<DT_ANGRY_DATA>& GetAngryChange() { return m_vecAngryChange; }
	inline BOOL& GetCanNormalAttack() { return m_bCanNormalAttack; }
	inline BOOL& GetCanSkillAttack() { return m_bCanSkillAttack; }
	inline UINT8& GetChaos(){ return m_byChaosState; }
	inline BOOL& GetCanDodge() { return m_bCanDodge; }
	inline BOOL& GetNotAnger(){ return m_bNotAnger; }
	inline vector<DT_HP_DATA>& GetHPChange() { return m_vecHPChange; }
	inline vector<DT_HP_DATA2>& GetHPChange2() { return m_vecHPChange2; }
	inline UINT16& GetAddDodgeRate() { return m_wAddDodgeRate; }
	inline UINT16& GetAddCritRate() { return m_wAddCritRate; }
	inline UINT8& GetCritFlag() { return m_byCritFlag; }
	inline UINT16& GetAttackHurtRate() { return m_wAttackHurtRate; }
	inline UINT32& GetExtHur() { return m_dwExtHur; }
	inline UINT16& GetSkillHurtRate() { return m_wSkillHurtRate; }
	inline UINT32& GetSkillExtHur() { return m_dwSkillExtHur; }
	inline UINT16& GetFinalDecHurt(){ return m_wFinalDecHurt; }
	inline UINT16& GetFinalAddHurt(){ return m_wFinalAddHurt; }

	inline vector<DT_BUFF_DATA>& GetBuffChange() { return m_vecBuffChange; }
	inline vector<DT_SKILL_EFFECT_ID_DATA>& GetSkillEffectIDChange() { return m_vecfSkillEffectIDChange; }
	inline vector<DT_SHIELD_DATA>& GetShiledChange() { return m_vecShieldChange; }
	inline UINT32& GetDefenseHP() { return m_dwDefenseHP; }
	inline VOID	AddExtHur(UINT32 dwExtHur) { m_dwExtHur += dwExtHur; }
	inline VOID	AddSkillExtHur(UINT32 dwExtHur) { m_dwSkillExtHur += dwExtHur; }
	inline UINT8& GetParryFlag() { return m_byParryFlag; }
	inline UINT16& GetDecHurtRate() { return m_wDecHurtRate; }
	inline UINT16& GetAddDefendRate(){ return m_wAddDefendRate; }
	inline UINT8& GetDodge(){ return m_byDodgeFlag; }
	VOID InitAttack();
	inline BOOL IsMoster() { return m_bMonster; }

protected:	
	BOOL	m_bMonster;//�Ƿ�Ϊ�������ͻ����·�����ID
	BOOL	m_bCanNormalAttack;//��ǰ�غ��Ƿ���ܽ�����ͨ����
	BOOL	m_bCanSkillAttack;//��ǰ�غ��Ƿ���ܽ��м��ܹ���
	BOOL	m_bCanDodge;//�Ƿ������
	BOOL	m_bCanCrit;//�Ƿ�ɱ���
	UINT8	m_byChaosState;//���ұ�ʶ//EBK_NONE ���������� EBK_CHAOS���Ҳ��ֵ��ң�EBK_DREAMLAND�ξ�ֻ�����ҷ�
	BOOL m_bPhysicalImmunity;//�����ʶ
	BOOL m_bMagicImmunity;//ħ���ʶ
	BOOL	m_bCanGetData; //�Ƿ��ȡ���ݣ��û�ս��������ȡ����
	BOOL    m_bNotAnger;//ʧȥ��־��ʶ��ŭ���ޱ仯��
	UINT8	m_byCritFlag;//������־
	UINT8	m_byParryFlag;//�񵲱�־
	UINT8   m_byDodgeFlag;//���ܱ�־


	UINT16	m_wSkillActionID; //����ID,0Ϊ��ͨ����
	//UINT16	m_wSkillLevel; //���ܵȼ�
	UINT16	m_wCurAngry;	//��ǰŭ��
	UINT16	m_wAddDodgeRate;//��ǰ�غ����ӵ�����(�ٷֱ�)
	UINT16  m_wAddCritRate;//��ǰ�غ����ӵı���(�ٷֱ�)
	UINT16	m_wAttackHurtRate;	//��������(�ٷֱ�)
	UINT32	m_dwExtHur;//���ӵ��˺�ֵ
	UINT16	m_wSkillHurtRate;//���ܹ�������(�ٷֱ�)
	UINT32	m_dwSkillExtHur;//���ӵ��˺�ֵ
	UINT32	m_dwDefenseHP;//�ֵ���HP
	UINT16	m_wDecHurtRate;//���˰ٷֱ�
	UINT16  m_wAddDefendRate;//���ӷ����ٷֱ�
	UINT16  m_wFinalDecHurt;//���������˺���
	UINT16  m_wFinalAddHurt;//��ǿ�����˺���

	vector<DT_ANGRY_DATA> m_vecAngryChange;//ŭ���仯
	vector<DT_HP_DATA>	m_vecHPChange;	//��ǰ�غ�Ѫ���仯
	vector<DT_HP_DATA2>	m_vecHPChange2;	//��ǰ�غ�Ѫ���仯
	vector<DT_BUFF_DATA> m_vecBuffChange;//buff�仯
	vector<DT_SKILL_EFFECT_ID_DATA> m_vecfSkillEffectIDChange;//����Ч���仯
	vector<DT_SHIELD_DATA> m_vecShieldChange;//���ֱ仯


	//�������ܵ��������
	vector<UINT8> avecCritRadom[MAX_FORMATION_IDX_NUM+1];//�����������
	UINT8 abyLastCritRadomIdx[MAX_FORMATION_IDX_NUM+1];//�ϴ�ʹ�õı�������������
	UINT8 abyLastInitCritRate[MAX_FORMATION_IDX_NUM+1];//�ϴγ�ʼ���ı�����
	vector<UINT8> avecParryRadom[MAX_FORMATION_IDX_NUM+1];//���������
	UINT8 abyLastParryRadomIdx[MAX_FORMATION_IDX_NUM+1];//�ϴ�ʹ�õĸ�����������
	UINT8 abyLastParryHitRate[MAX_FORMATION_IDX_NUM+1];//�ϴγ�ʼ���ĸ���	


	CSpecialEffect* m_bContinueAttack;//��ǰ�����Ƿ񴥷�����
	CSpecialEffect* m_bBeatBack;//��ǰ�Ƿ񴥷�����

	//ս��Ŀ����ӵ�е����⹥��
	CMapID2SpecialEffect m_mapSpecialEffect;
};


#endif

