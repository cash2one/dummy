
#ifndef _MONSTERGROUP_H_
#define _MONSTERGROUP_H_

#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <logic/battle/battleobj.h>
#include <logic/instance/instancepropmgr.h>
#include "monster.h"

using namespace std ;

typedef vector<UINT16> CVecMonsterID;
typedef CVecMonsterID::iterator CVecMonsterIDItr;

class CPlayer;

typedef HashMap<UINT32, CMonster*> CID2MonsterMap;
typedef CID2MonsterMap::iterator CID2MonsterMapItr;

//typedef HashMap<UINT16, UINT32> CLevel2ExperienceMap;	//keyΪ��ҵȼ���valueΪ����ֵ
//typedef CLevel2ExperienceMap::iterator CLevel2ExperienceMapItr;

class CMonsterGroup: public CBattleObj
{
public:
    CMonsterGroup();
    virtual ~CMonsterGroup();

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
    BOOL Init(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 wMonsterIdx);

    BOOL Init(vector<SSingleMonsterProp> vecMonster);

    //DT_BATTLE_OBJ_GROUP_DATA& GetBattleGroupData() { return m_stBattleGroupData; }; //���ڷ���Э��
    CMonster* GetMainMonster()
    {
        return m_poMainMonster;
    }

    VOID Encourage(CPlayer* poPlayer, BOOL bFirst = FALSE, UINT8 byRunTimes = 1);//��սʤ������ҽ���

protected:

private:
    UINT16				m_wSceneIdx;
    UINT8				m_byTownIdx;
    UINT8				m_byInstanceIdx;
    UINT16				m_wMonsterIdx;

    CID2MonsterMap		m_mapID2Monster;
    CMonster*			m_poMainMonster;//����
    BOOL					m_bGenBattleAttribute; //�������Բ���ı䣬ֻ���ü���һ�ξͿ�����
    DT_BATTLE_OBJ_GROUP_DATA3 m_stBattleGroupData;//���ڷ���Э��,��Ϊ����̶���������������
    UINT32				m_dwExperience; //���ڿ��ٸ����飬����ÿ������
    UINT32				m_dwEncourageCoin;//����ͭ��
    UINT32				m_dwEncourageStory;//�����������Ƽ����ѿ��Ų���
    UINT32				m_dwEncourageJingJie; //��������㣬δ���ž��粻�����������״βű�
public:
    VOID			SetMemID(UINT32 dwMemID)
    {
        m_dwMemID = dwMemID;
    }
    UINT32		GetMemID()
    {
        return m_dwMemID;
    }
private:
    UINT32		m_dwMemID;//�ڴ�ID�����ڹ�����map����

///////////////////////////////////
public:


};


#endif

