
#ifndef _SKILLMGR_H_
#define _SKILLMGR_H_

#include "skill.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>

using namespace SGDP;


typedef HashMap<UINT64, CSkill*> CID2SkillMap;
typedef CID2SkillMap::iterator	CID2SkillMapItr;


/**
* @brief ���ܹ�����
*/
class CSkillMgr
{
public:
    DECLARE_SINGLETON(CSkillMgr)

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

public:

	CSkill*		CreateSkill();
	VOID		RemoveSkill(CSkill* poSkill);    

	VOID AddBuff(CBattleAttrObj* poSkillOwner, CBattleAttrObj* poTargetObj, UINT16 wSkillID, const SSkillOnceBuffProp& stBuffProp);
	VOID AddSleepBuff(CBattleAttrObj* poSkillOwner, CBattleAttrObj* poTargetObj);
protected:
    CSkillMgr();
    ~CSkillMgr();
	/////////////////////

private:
    CID2SkillMap					m_mapID2Skill;
	CSDObjectPool<CSkill, CSDMutex> m_oSkillShmemObjMgr;
};




#endif //#ifndef _ROLEMGR_H_

