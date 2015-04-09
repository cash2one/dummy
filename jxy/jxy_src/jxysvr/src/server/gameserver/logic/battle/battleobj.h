
#ifndef _BATTLEOBJ_H_
#define _BATTLEOBJ_H_

#include <protocol/server/protocommondata.h>
#include "common/client/commondef.h"
using namespace SGDP;
using namespace std ;



enum EBattleObjType
{
    EBOT_PLAYER = 1,//���
    EBOT_MONSTERGROUP = 2,//������
	EBOT_PLAYERGROUP = 2,//������
};


#define CRITRATE_UPPERLIMIT 80	//�������ްٷֱ�
#define CRITRATE_LOWERLIMIT 10	//�������ްٷֱ�

#define PARRY_UPPERLIMIT	80	//�����ްٷֱ�
#define PARRY_LOWERLIMIT	10	//�����ްٷֱ�


#define NORMAL_CRIT_RATE	150	//��ͨ������

#define PARRY_HURT_RATE	50		//���˺���



//���ڹ�Ѫ������ϵͳ
struct DT_BATTLE_OBJ_HP
{
    UINT32 dwHP; //Ѫ��
    UINT32 byFormationIdx; //��λ

    DT_BATTLE_OBJ_HP()
    {
        memset(this, 0x00, sizeof(DT_BATTLE_OBJ_HP));
    }
};

struct DT_BATTLE_OBJ_GROUP_HP
{
    UINT8				byObjNum; //ս������Ϣ
    DT_BATTLE_OBJ_HP	astBattleObjInfo[MAX_FORMATION_IDX_NUM]; //ս������Ϣ

    DT_BATTLE_OBJ_GROUP_HP()
    {
        memset(this, 0x00, sizeof(DT_BATTLE_OBJ_GROUP_HP));
    }

    UINT32 CalcTotalHP()
    {
        UINT32 dwTotalHP = 0;
        for (UINT8 i = 0; i < MAX_FORMATION_IDX_NUM; i++)
        {
            dwTotalHP += astBattleObjInfo[i].dwHP;
        }

        return dwTotalHP;
    }

    void CopyHPTo(DT_BATTLE_OBJ_GROUP_DATA2 &stObjGroup)
    {
        for (UINT8 byIdx = 0; byIdx < stObjGroup.byObjNum; byIdx++)
        {
            DT_BATTLE_OBJ_DATA2 &stObj = stObjGroup.astBattleObjInfo[byIdx];

            for (UINT8 i = 0 ; i < byObjNum; i++)
            {
                DT_BATTLE_OBJ_HP &stCurHP = astBattleObjInfo[i];
                if(stCurHP.byFormationIdx == stObj.byFomationIdx)
                {
                    stObj.stBattleAttr.dwHP = stCurHP.dwHP;
                    break;
                }
            }            
        }
    }
};

class CBattleAttrObj;
class CSkill;
class CPet;
class CBattleObj
{
public:
    CBattleObj();
    ~CBattleObj();

public:
	virtual CPet* GetBattlePet() { return NULL; };
    virtual VOID StartBattle(CBattleObj* poEnemy) = 0;//ÿ��ս��ǰ(����ս�����Եȵ�)
    virtual EBattleObjType GetBattleObjType() = 0; //������ս������
    virtual VOID EndBattle() = 0; //ÿ��ս����(���ս�������еĲ��� buff/hang��)
	virtual VOID GetDT_BATTLE_OBJ_GROUP_DATA(DT_BATTLE_OBJ_GROUP_DATA3& stDT_BATTLE_OBJ_GROUP_DATA) = 0;//��ֵս����ս��������

    virtual VOID GetDT_BATTLE_OBJ_GROUP_AFTER_DATA(DT_BATTLE_OBJ_GROUP_HP& stDT_BATTLE_OBJ_GROUP_AFTER_DATA) = 0;//��ֵս����ս��������
public:
    DT_BATTLE_BASE_ATTRIBUTE& GetCurDT_BATTLE_ATTRIBUTE()
    {
        return m_stCurBattleAttribute;
    }
    DT_BATTLE_BASE_ATTRIBUTE& GetMaxDT_BATTLE_ATTRIBUTE()
    {
        return m_stMaxBattleAttribute;
    }
	//��ȡ����״̬�Ĺ�������
	CBattleAttrObj* GetChaosBattleObj(CBattleObj* poAttack, CBattleObj* poBeAttack, CBattleAttrObj* poCurAttack);
    VOID OnRoundEnd(BOOL bAttacker) ;//����غϽ�����ŭ�����㣬����ûغϵĸ���Ч����������غϵ���buff���
    VOID GetSkillSlotAngry(DT_BATTLE_ANGRY_DATA astAttackerAngry[MAX_SKILL_SLOT_NUM]);//��ȡ���ܲ�ŭ��
    CBattleAttrObj* GetRoundNextObj(UINT8* pbyIdx = NULL);//��ȡ�غ��ڵ���һ��������
    BOOL RoundHaveNextObj();//�غ����Ƿ�����һ��������
    CBattleAttrObj* GetFirstAttacker(UINT8* pbyIdx = NULL);//��ȡ��һ��������
    CBattleAttrObj* GetCurAttacker(UINT8* pbyIdx = NULL);//��ȡ��ǰ������
    CBattleAttrObj* GetTarget(UINT8 byAttckerFormationIdx, UINT8* pbyIdx = NULL);//��ȡ����Ŀ�꣬��һ�žͽ�ԭ��

    BOOL IsDead();//�Ƿ�����
    CSkill* TrigerSkill(UINT8 byAttckerFormationIdx, vector<CBattleAttrObj*>& vecTargetObj);//�Ƿ񴥷�����(�п���δ���м���)������NULLΪδ���м��ܣ�ʹ����ͨ����.vecTargetIdxΪ������Ŀ�귶Χ
    CBattleAttrObj* GetFormationObj(UINT8 byIdx)
    {
        if(byIdx > MAX_FORMATION_IDX_NUM) return NULL;
        return m_apoFormationObj[byIdx];
    }
    VOID ResetCurAttackObjIdx()
    {
        m_byCurAttackObjIdx = 0;
    }

    //����ȹ�ֵ
    UINT32 GetFirstAttackValue();

    VOID InitCurBattleAttr(DT_BATTLE_OBJ_GROUP_HP *pstInitHP = NULL);

    void BeStronger(UINT16 wStrongPercent = 100 /* ȫ���ԣ�����+4�������ԣ�ǿ��������50����ȫ���Ա�Ϊԭ����50%��150�����Ϊԭ����150% */);
	
	VOID SetPetBattleState(BOOL bState){ m_bIsPetBattle = bState; }
	virtual UINT32 GetPower();
protected:
    VOID ResetBattleRadom();
    virtual VOID ResetSpecialEffects();
    //�ͷ�ս�������е�buff
    VOID ReleaseBuff();
	//�ͷ���Ч����
	virtual VOID ReleaseSpecialEffect();
    static VOID GetTargetObj(UINT8 byAttckerFormationIdx, DT_ATTACK_RANG_DATA stRangInfo, vector<CBattleAttrObj*>& vecTargetObj, CBattleObj* poTarget, ESkillEffectKind eKind = ESEK_MAX, UINT16 wLevel = 0);
protected:
    DT_BATTLE_BASE_ATTRIBUTE		m_stMaxBattleAttribute;		//���ս������ֵ��ÿ������Initʱ��ֵȷ����
    DT_BATTLE_BASE_ATTRIBUTE		m_stCurBattleAttribute;		//��ǰս������ֵ��ÿ�ν��븱��������,ս��������+buffӰ��ֵ��Ѫ��������ֱ��+���������ͷ�����ֻ��buff�غ�����Ч
    DT_HIDE_BATTLE_ATTRIBUTE	m_stHideBattleAttr;			//����ս������
    DT_EXT_BATTLE_ATTRIBUTE	 m_stExtBattleAttr;			//��չս������
    CBattleObj*				 m_poEnemy;//
    UINT8					 m_byCurAttackObjIdx; //��ǰ����������������
	BOOL m_bIsPetBattle;

public:
	CBattleAttrObj*			 m_apoFormationObj[MAX_FORMATION_IDX_NUM + 1]; //����Ķ���



};


#endif //#ifndef _PLAYER_H_

