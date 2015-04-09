
#ifndef _MONSTERMGR_H_
#define _MONSTERMGR_H_

#include "monster.h"
#include "shademonster.h"
#include "monstergroup.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <logic/instance/instancepropmgr.h>
#include <protocol/server/protocommondata.h>


using namespace SGDP;


typedef HashMap<UINT64, CMonsterGroup*> CID2MonsterGroupMap; //keyΪwInstanceIdx(wSceneIdx+byTownIdx+byInstanceIdx)+wMonsterIdx(��0��ʼ)
typedef CID2MonsterGroupMap::iterator	CID2MonsterGroupMapItr;


typedef HashMap<UINT64, DT_MONSTER_DATA_LIST> CInstanceID2MonsterGroupMap; //keyΪwSceneIdx+byTownIdx+byInstanceIdx
typedef CInstanceID2MonsterGroupMap::iterator CInstanceID2MonsterGroupMapItr;


class CMonsterGroup;
/**
* @brief ���������
*/
class CMonsterMgr
{
    friend class CMonsterGroup;
public:
    DECLARE_SINGLETON(CMonsterMgr)

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
    * ���ҹ���ڹ������ڲ���(ÿ������),��û���򴴽�
    * @param wInstanceIdx   : �������
    * @param wMonsterIdx	: �������
    * @return CMonster*     : ���ҵ��Ĺ���
    */
    CMonsterGroup*		FindMonsterGroup(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 wMonsterIdx);
	/**
    * @brief
    * ���ҹ���ڹ������ڲ���(ÿ������),��û���򴴽�
    * @param vector<SSingleMonsterProp>   : ����ID��
    * @return CMonster*     : ���ҵ��Ĺ���
    */
	CMonsterGroup*		FindMonsterGroup(vector<SSingleMonsterProp> vecMonster);
    /**
    * @brief
    * ��ȡ�����еĹ�����Ϣ��û���򷵻�NULL
    * @return VOID
    */
    DT_MONSTER_DATA_LIST* GetInstanceMonster(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);

    CMonster*			CreateMonster();
    VOID					RemoveMonster(CMonster* poMonster);
    VOID					RemoveAllMonster();
	
protected:
    CMonsterMgr();
    ~CMonsterMgr();
    BOOL				CreateMonsterGroup(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);
    CMonsterGroup*	CreateMonsterGroup(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 wMonsterIdx, DT_MONSTER_DATA_LIST& stDT_MONSTER_DATA_LIST);
    VOID				RemoveMonsterGroup(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 wMonsterIdx);

    UINT64			GetMonsterKey(UINT16 wSceneIdx, UINT16 byTownIdx, UINT16 byInstanceIdx, UINT16 wMonsterIdx);
    UINT64			GetInstanceKey(UINT16 wSceneIdx, UINT16 byTownIdx, UINT16 byInstanceIdx);
	UINT64			GetShadeMonsterKey( UINT8 byType, UINT32 dwPlayerID);
	UINT64			GetMonsterKey(vector<SSingleMonsterProp> vecMonster);

	//������ID����������
	CMonsterGroup*	CreateMonsterGroup(vector<SSingleMonsterProp> vecMonster);

private:
    CID2MonsterGroupMap					m_mapID2MonsterGroup;
    CInstanceID2MonsterGroupMap			m_mapInstanceID2MonsterGroup;

    CSDObjectPool<CMonster, CSDMutex>		m_oMonsterPool;
    CSDObjectPool<CMonsterGroup, CSDMutex>	m_oMonsterGroupPool;
    static UINT32						m_dwMonsterIDGen;//���������ڴ��е�ID
    static UINT32						m_dwMonsterGroupIDGen;//���������ڴ��е�ID
};




#endif //#ifndef

