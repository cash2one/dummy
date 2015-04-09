
#ifndef _SHADE_MONSTER_GROUP_H_
#define _SHADE_MONSTER_GROUP_H_

#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <logic/battle/battleobj.h>
#include <logic/instance/instancepropmgr.h>
#include "shademonster.h"

using namespace std ;

typedef vector<UINT16> CVecMonsterID;
typedef CVecMonsterID::iterator CVecMonsterIDItr;

class CPlayer;

typedef HashMap<UINT32, CShadeMonster*> CID2ShadeMonsterMap;
typedef CID2ShadeMonsterMap::iterator CID2ShadeMonsterMapItr;

struct SShadeMonsterFormation
{
	UINT8 byFormation;
	CShadeMonster* poShadeMonster;
};

typedef vector<SShadeMonsterFormation> CVecMonsterFormation;
typedef CVecMonsterFormation::iterator CVecMonsterFormationItr;

class CShadeMonsterGroup: public CBattleObj
{
public:
	CShadeMonsterGroup();
	virtual ~CShadeMonsterGroup();

public:
	virtual VOID StartBattle(CBattleObj* poEnemy);//
	virtual EBattleObjType GetBattleObjType()
	{
		return EBOT_MONSTERGROUP;
	}
	virtual VOID EndBattle(); //ÿ��ս����(���ս�������еĲ��� buff��)
	virtual VOID GetDT_BATTLE_OBJ_GROUP_DATA(DT_BATTLE_OBJ_GROUP_DATA3& stDT_BATTLE_OBJ_GROUP_DATA);//��ֵս����ս��������

	virtual VOID GetDT_BATTLE_OBJ_GROUP_AFTER_DATA(DT_BATTLE_OBJ_GROUP_HP& stDT_BATTLE_OBJ_GROUP_AFTER_DATA);//��ֵս����ս��������
public:
	//��ʼ����ض���
	BOOL Init(UINT16 wLevel, UINT8 byType, const vector<UINT16>& vecMonsterID);

	CShadeMonster* GetMainShadeMonster()
	{
		return m_poMainShadeMonster;
	}

private:
	CShadeMonster*		m_poMainShadeMonster;//����
	BOOL					m_bGenBattleAttribute; //�������Բ���ı䣬ֻ���ü���һ�ξͿ�����
	DT_BATTLE_OBJ_GROUP_DATA3 m_stBattleGroupData;//���ڷ���Э��,��Ϊ����̶���������������
	
	CID2ShadeMonsterMap m_mapShadeMonster;

};


#endif

