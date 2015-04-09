
#ifndef _BATTLEMGR_H_
#define _BATTLEMGR_H_


#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdmutex.h>
#include <protocol/server/protocommondata.h>
#include "battleobj.h"
#include <logic/skill/buff.h>


using namespace SGDP;

#define MAX_DEFENSE	5000 //��������

//�����߱�־
enum EAttackerFlag
{
	EAF_MYSELF = 0,//�ҷ�
	EAF_ENEMY = 1,//�з�
};


//�غϽ��
enum ERoundResult
{	
	ERR_CONTINUE = 0, //�����ûغϵ��½׶�
	ERR_SKIP = 1, //�����ûغ�
	ERR_DEAD = 2, //�Է�����
};

class CPlayer;
class CMonsterGroup;
class CSpecialEffect;
/**
* @brief ս��������
*/
class CBattleMgr
{
public:
    DECLARE_SINGLETON(CBattleMgr)

    /**
    * @brief
    * ��ʼ������,��ȡ�����ļ���
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL Init();

    /**
    * @brief
    * ж�غ���
    */
    VOID UnInit();


    /**
    * @brief
    * ս��
	* poMyself	:�Լ�
	* poEnemy	:����(����)
	* stDT_BATTLE_DATA	:ս������
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL Battle(
        CBattleObj* poMyself, 
        CBattleObj* poEnemy, 
        DT_BATTLE_DATA2& stDT_BATTLE_DATA, 
        BOOL bPVP = FALSE, 
        DT_BATTLE_OBJ_GROUP_HP *pstAfterMyselfInfo = NULL, 
        BOOL bChallengFirst = FALSE
    );

        /**
    * @brief
    * ս��
	* poMyself	:�Լ�
	* poEnemy	:����(����)
	* stDT_BATTLE_DATA	:ս������
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    * pstAfterMyselfInfo : �Լ�ս�������Ϣ
    //////////����������Կ��ս////////////
    * pstAfterMyselfInfo2 ���Լ�ս��������ݣ�����Ѫ����KindID
    * pstAfterEnemyInfo2��������ս��������ݣ�����Ѫ����KindID
    * byRound : �����غ�, 0ΪĬ��ս����ʽ 1Ϊ�Լ����в�Ѫ 2Ϊ���˻��в�Ѫ
    * pstNewMyselfInfo2 ���Լ��ڵ�һ��ս��������� ������ֵ���ڶ���ս��
    * pstNewEnemyInfo2 �������ڵ�һ��ս��������� ������ֵ���ڶ���ս��
    */
    BOOL Battle2(
        CBattleObj* poMyself, 
        CBattleObj* poEnemy, 
        DT_BATTLE_DATA3& stDT_BATTLE_DATA, 
        BOOL bPVP = FALSE, 
        BOOL bChallengFirst = FALSE, 

        DT_BATTLE_OBJ_GROUP_HP *pstAfterMyselfHP = NULL, 
        DT_BATTLE_OBJ_GROUP_HP *pstAfterEnemyHP = NULL,
        DT_BATTLE_OBJ_GROUP_HP *pstInitMyselfHP = NULL, 
        DT_BATTLE_OBJ_GROUP_HP *pstInitEnemyHP = NULL
    );

	/**
    * @brief
    * ս��
	* poMyself	:�Լ�
	* poEnemy	:����(����)
	* stDT_BATTLE_DATA	:ս������
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    * pstAfterMyselfInfo : �Լ�ս�������Ϣ
    //////////����������Կ��ս////////////
    * pstAfterMyselfHP ���洢��ս����������
    * pstAfterEnemyHP�����洢�ҷ�ս����������
    * pstInitMyselfHP �� �󷽳�ʼ��ʱ��Ѫ��
    * pstInitEnemyHP ��  �ҷ���ʼ��ʱ��Ѫ��
    * byMyselfWeakenPercent: ��ǿ���ı������磬30��ʾ���ȫ���ԣ�����+4�������ԣ���Ϊԭ����30%��130����ȫ���Ա�Ϊԭ����130%
    * byEnemyWeakenPercent:  �ҷ�ǿ���ı���
    */
    BOOL Battle3(
        CBattleObj* poMyself, 
        CBattleObj* poEnemy, 
        DT_BATTLE_DATA4& stDT_BATTLE_DATA, 
        BOOL bPVP = FALSE, 
        BOOL bChallengFirst = FALSE, 

        DT_BATTLE_OBJ_GROUP_HP *pstAfterMyselfHP = NULL, 
        DT_BATTLE_OBJ_GROUP_HP *pstAfterEnemyHP = NULL,
        DT_BATTLE_OBJ_GROUP_HP *pstInitMyselfHP = NULL, 
        DT_BATTLE_OBJ_GROUP_HP *pstInitEnemyHP = NULL,
        UINT8 byMyselfStrongPercent = 100,
        UINT8 byEnemyStrongPercent  = 100
    );

		/**
    * @brief
    * ս��
	* poMyself	:�Լ�
	* poEnemy	:����(����)
	* stDT_BATTLE_DATA	:ս������
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    * pstAfterMyselfInfo : �Լ�ս�������Ϣ
    //////////����������Կ��ս////////////
    * pstAfterMyselfHP ���洢��ս����������
    * pstAfterEnemyHP�����洢�ҷ�ս����������
    * pstInitMyselfHP �� �󷽳�ʼ��ʱ��Ѫ��
    * pstInitEnemyHP ��  �ҷ���ʼ��ʱ��Ѫ��
    * byMyselfWeakenPercent: ��ǿ���ı������磬30��ʾ���ȫ���ԣ�����+4�������ԣ���Ϊԭ����30%��130����ȫ���Ա�Ϊԭ����130%
    * byEnemyWeakenPercent:  �ҷ�ǿ���ı���
    */
    BOOL Battle4(
        CBattleObj* poMyself, 
        CBattleObj* poEnemy, 
        DT_BATTLE_DATA5& stDT_BATTLE_DATA, 
        BOOL bPVP = FALSE, 
        BOOL bChallengFirst = FALSE, 

        DT_BATTLE_OBJ_GROUP_HP *pstAfterMyselfHP = NULL, 
        DT_BATTLE_OBJ_GROUP_HP *pstAfterEnemyHP = NULL,
        DT_BATTLE_OBJ_GROUP_HP *pstInitMyselfHP = NULL, 
        DT_BATTLE_OBJ_GROUP_HP *pstInitEnemyHP = NULL,
        UINT8 byMyselfStrongPercent = 100,
        UINT8 byEnemyStrongPercent  = 100
    );
	//ת���汾
	//��4ת��Ϊ2
	VOID Convert5To3(const DT_BATTLE_DATA5& stData4, DT_BATTLE_DATA3& stData3);
	VOID Convert5To4(const DT_BATTLE_DATA5& stData4, DT_BATTLE_DATA4& stData3);
	VOID Convert4To3(const DT_BATTLE_DATA4& stData4, DT_BATTLE_DATA3& stData3);
	VOID Convert4To2(const DT_BATTLE_DATA4& stData4, DT_BATTLE_DATA2& stData2);
	VOID Convert2To4(const DT_BATTLE_DATA2& stData2, DT_BATTLE_DATA4& stData4);
	VOID Convert3To4(const DT_BATTLE_DATA3& stData3, DT_BATTLE_DATA4& stData4);
	VOID ReplaceBattleData(const vector<UINT16>& vecMonsterID, DT_BATTLE_DATA2& stDT_BATTLE_DATA);
  
	UINT32 CountHurt(CBattleAttrObj* poCurAttacker, CBattleAttrObj* poBeattacker, UINT8* byAttackSpecialEffectFlag, UINT8* byEnemySpecialEffectFlag);
	UINT32 SecondCountHurt(CBattleAttrObj* poCurAttacker, CBattleAttrObj* poBeattacker, CSpecialEffect* byAttackType, UINT8* byAttackSpecialEffectFlag = NULL, UINT8* byEnemySpecialEffectFlag = NULL);
	VOID BattleData221(DT_BATTLE_DATA2& stBattleInfo2, DT_BATTLE_DATA& stBattleInfo1);

	UINT16 BattleMyself(CPlayer* poMyself, UINT8 byCareerID, DT_BATTLE_DATA5& stDT_BATTLE_DATA, DT_BATTLE_OBJ_GROUP_HP *pstAfterMyselfInfo = NULL);

	DT_BATTLE_ATTRIBUTE& NewToOldBattleAttribute(const DT_BATTLE_BASE_ATTRIBUTE& stAttr2);
	DT_BATTLE_ATTRIBUTE& NewToOldBattleAttribute(const DT_BATTLE_ATTRIBUTE2& stAttr2);
	DT_BATTLE_ATTRIBUTE2 ConvertAttribute2ToBase(const DT_BATTLE_BASE_ATTRIBUTE& stAttr);
	VOID VerifyBattle(const DT_BATTLE_DATA5& stBattleData4);
protected:
    /**
    * @brief
    * ս��һ�غ�
	* poAttacker	:������
	* poBeattacker	:��������
	* bAttackerFlag :�����߱�־��FALSEΪ��ս��
	* stDT_BATTLE_ROUND_DATA:�غϼ�¼
    * @return �غϽ��
    */

	ERoundResult OnceRound3(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag& eAttackerFlag, DT_BATTLE_ROUND_DATA4& stBattleRoundInfo, CBattleAttrObj*& poEnemy); 

	ERoundResult OnceRound4(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag& eAttackerFlag, DT_BATTLE_ROUND_DATA5& stBattleRoundInfo, CBattleAttrObj*& poEnemy); 
	//���ι���
	ERoundResult SecondAttack(CBattleObj* poAttacker, CBattleAttrObj* poObj, CBattleObj* poBeattacker, CBattleAttrObj* poEnemyObj, EAttackerFlag& eAttackFlag, CSpecialEffect* byAttackType, DT_BATTLE_ROUND_DATA4& stBattleInfo);
	//���ι���
	ERoundResult SecondAttack(CBattleObj* poAttacker, CBattleAttrObj* poObj, CBattleObj* poBeattacker, CBattleAttrObj* poEnemyObj, EAttackerFlag& eAttackFlag, CSpecialEffect* byAttackType, DT_BATTLE_ROUND_DATA5& stBattleInfo);
	//���﹥��
	ERoundResult PetBattle(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag& eAttackerFlag, DT_BATTLE_ROUND_DATA5& stBattleRoundInfo, vector<CBattleAttrObj*>& vecTargetObj);
	//������ι���
	ERoundResult PetSecondBattle(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag& eAttackerFlag, DT_BATTLE_ROUND_DATA5& stBattleRoundInfo, vector<CBattleAttrObj*>& vecTargetObj);
	//�����˺�����
	VOID PetCountHurt(CPet* poAttack, CBattleAttrObj* poBeattacker);

	VOID BuffAffect(EBuffAffectPhase eBuffAffectPhase, CBattleObj* poAttacker, CBattleObj* poBeattacker);
	

	VOID BuffRoundDec(CBattleObj* poBattleObj, BOOL bEndBigRound = FALSE);//buff�غϼ���

	ERoundResult ActionJudge(CBattleObj* poAttacker);

	VOID CountAttackBackHurt(CBattleAttrObj* poAttacker, CBattleAttrObj* poBeattacker);

	BOOL JudgeDead(CBattleObj* poAttacker, CBattleObj* poBeattacker);

	VOID GetAttackData(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag eAttackerFlag, BOOL bBeforeAttack, DT_ATTACK_DATA& stDT_ATTACK_DATA);

    VOID GetAttackData2(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag eAttackerFlag, BOOL bBeforeAttack, DT_ATTACK_DATA2& stDT_ATTACK_DATA);

	VOID GetAttackData3(CBattleObj* poAttacker, CBattleObj* poBeattacker, EAttackerFlag eAttackerFlag, BOOL bBeforeAttack, DT_ATTACK_DATA3& stDT_ATTACK_DATA);

	VOID CkGodweaponAttack(CBattleAttrObj* poAttacker, CBattleAttrObj* poBeattacker, DT_GODWEAPON_ATTACK_DATA& stGodweaponAttackInfo);//�������������������ֵ
	VOID CkGodweaponAttack(CBattleAttrObj* poAttacker, CBattleAttrObj* poBeattacker, DT_GODWEAPON_ATTACK_DATA2& stGodweaponAttackInfo);//�������������������ֵ

	//////////////////////////////////////////////////////////////////////////////////////////

	VOID BuffAffect(EBuffAffectPhase eBuffAffectPhase, BOOL bMyAttack, CBattleAttrObj* poAttrObj, CBattleAttrObj* poAttacker, CBattleAttrObj* poNormalAttackTarget);	
	VOID SetChangeHP(UINT8& byNum, INT32 anHpChangeInfo[], vector<INT32>& vecHP, BOOL bReverse = FALSE);
	INT32 GetTotalChangeHP(vector<INT32>& vecHP);
	VOID GetAttackData(CBattleAttrObj* poObj, BOOL bBeforeAttack, DT_ATTACK_OBJ_DATA& stDT_ATTACK_OBJ_DATA);
    VOID GetAttackData2(CBattleAttrObj* poObj, BOOL bBeforeAttack, DT_ATTACK_OBJ_DATA2& stDT_ATTACK_OBJ_DATA);
	VOID GetAttackData3(CBattleAttrObj* poObj, BOOL bBeforeAttack, DT_ATTACK_OBJ_DATA3& stDT_ATTACK_OBJ_DATA);

protected:
	CBattleMgr();
	~CBattleMgr();
private:

};




#endif //#ifndef

