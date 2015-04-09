
#ifndef _PLAYERGROUP_H_
#define _PLAYERGROUP_H_

#include <protocol/server/protocommondata.h>
#include <logic/battle/battleobj.h>
#include <logic/hero/hero.h>


using namespace std ;

class CPlayer;

class CPlayerGroup: public CBattleObj
{
public:
    CPlayerGroup();
    virtual ~CPlayerGroup();

public:

    virtual VOID StartBattle(CBattleObj* poEnemy);//

    virtual EBattleObjType GetBattleObjType()
    {
        return EBOT_PLAYERGROUP;
    }
    virtual VOID EndBattle(); //ÿ��ս����(���ս�������еĲ��� buff��)

	virtual VOID GetDT_BATTLE_OBJ_GROUP_DATA(DT_BATTLE_OBJ_GROUP_DATA3& stDT_BATTLE_OBJ_GROUP_DATA);//��ֵս����ս��������

    virtual VOID GetDT_BATTLE_OBJ_GROUP_AFTER_DATA(DT_BATTLE_OBJ_GROUP_HP& stDT_BATTLE_OBJ_GROUP_AFTER_DATA);//��ֵս����ս��������

public:
    //��ʼ����ض���
    BOOL Init(vector<CHero*> vecHero);

protected:

private:
    BOOL						m_bGenBattleAttribute; //�������Բ���ı䣬ֻ���ü���һ�ξͿ�����
    DT_BATTLE_OBJ_GROUP_DATA3	m_stBattleGroupData;//���ڷ���Э��,��Ϊ����̶���������������
///////////////////////////////////
public:


};


#endif

