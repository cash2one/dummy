
#ifndef _TASKMGR_H_
#define _TASKMGR_H_

#include "task.h"
#include "taskpropmgr.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <sdstring.h>

using namespace SGDP;



typedef HashMap<UINT64, CTask*> CID2TaskMap; //keyΪCTask��MemID
typedef CID2TaskMap::iterator CID2TaskMapItr;

typedef HashMap<UINT8, CTask*> CLineIdx2TaskMap; //keyΪ���������
typedef CLineIdx2TaskMap::iterator CLineIdx2TaskMapItr;

typedef vector<CTask*> CTaskVec;
typedef CTaskVec::iterator CTaskVecItr;

/**
* @brief ���������
*/
class CTaskMgr
{
public:
	DECLARE_SINGLETON(CTaskMgr)

	BOOL Init();

	VOID UnInit();

public:

	CTask*	CreateTask(UINT32 dwPlayerID, UINT8 byTaskLine);

	VOID	RemoveTask(UINT32 dwPlayerID, UINT8 byTaskLine);
public:
	VOID	CkWantCheckAccept(CPlayer* poPlayer);//��������Ƿ�ɽӣ���֮ǰ���ɽ��ֿɽ����¼Ϊ�仯����
	//��������
	//UINT16 AcceptTask(CPlayer* poPlayer, UINT8 byTaskLine, UINT8 byTaskIdx);

	//��������
	//UINT16 GiveUpTask(CPlayer* poPlayer, UINT8 byTaskLine, UINT8 byTaskIdx);

	//������������ж�
	VOID CheckFinish(CPlayer* poPlayer);//������ɼ�飬��������ܺ�(CkWantCheckAccept����ʱ)����

	////////////////////////////////////////////////
	//������������ص�
	VOID OnPassInstance(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);//����/�������,�״�ͨ����������,ָ������ͨ����������,ָ������ͨ����������
	VOID OnCrown(CPlayer* poPlayer);//�ջ�����,�����ջ���
	VOID OnRecruitHero(CPlayer* poPlayer, UINT16 wHeroKindID);//��ļ�佫����
	VOID OnClimbTower(CPlayer* poPlayer);//�佫��������
	VOID OnKillMonsterInstance(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 wMonsterKindID);//ָ������ɱ������
	VOID OnStrengthenEquip(CPlayer* poPlayer, UINT16 wEquipID);//ǿ��װ������
	VOID OnActivateGodweapon(CPlayer* poPlayer);//�������� ����
	VOID OnUpgradeGodweapon(CPlayer* poPlayer);//�������� ����
	VOID OnChallenge(CPlayer* poPlayer); //��������ս ����
	VOID OnPlunder(CPlayer* poPlayer); //�Ӷ� ����
	VOID OnUpgradeSkill(CPlayer* poPlayer); //�������� ����
	VOID OnUpgradeJingJie(CPlayer* poPlayer, UINT16 wLevel, UINT16 wSubLevel); //���׾��� ����
	VOID OnMosaicGem(CPlayer* poPlayer); //�������� ����
	VOID OnDressEquip(CPlayer* poPlayer, UINT16 wEquipID); //����װ�� ����
	VOID OnComposeGood(CPlayer* poPlayer, UINT16 wMaterialID); //�ϳ���Ʒ ����
	VOID OnEliteInstance(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx); //��Ӣ���� ����
	VOID OnUpgradeScience(CPlayer* poPlayer); //�����Ƽ������� ����
	VOID OnStrengthAttack(CPlayer* poPlayer); //ǿ������ ����
	VOID OnStrengthLife(CPlayer* poPlayer); //ǿ������ ����
	VOID OnCrop(CPlayer* poPlayer); //�ϳ���Ʒ ����
	VOID OnUseExprienceDrug(CPlayer* poPlayer); //ʹ�þ��鵤����
	VOID OnMelt(CPlayer* poPlayer);	//����
	VOID OnStudy(CPlayer* poPlayer);
	VOID OnRecruitHeroNum(CPlayer* poPlayer, UINT16 wHeroKindID);//��ļ�佫����

	VOID OnOpenLight(CPlayer* poPlayer);//��������
	////////////////////////////////////////////////
	BOOL GiveNextTask(CPlayer* poPlayer, CTask* poTask);	
	BOOL SetTaskCond(CPlayer* poPlayer, UINT8 byCurTaskLine, UINT32 dwCurTaskIdx, UINT8& byTaskConditonType, DT_TASK_CONDITION& stTaskConditionInfo);//������������

	////////////////////////////////////////////////
	UINT16 RecvTaskEncourage(CPlayer* poPlayer, UINT8 byTaskLine, UINT32 dwTaskIdx);
	
protected:		
	
	CTask* FindTask(UINT32 dwPlayerID, UINT8 byTaskLine);
	//VOID GiveBranchTask(CPlayer* poPlayer, STaskProp* pstLastMainTaskProp);//�����ߵ�֧������
protected:
	CTaskMgr();
	~CTaskMgr();
protected:

private:
	CID2TaskMap					m_mapID2Task;
	CSDObjectPool<CTask, CSDMutex> m_oTaskShmemObjMgr;
};




#endif //#ifndef _ROLEMGR_H_

