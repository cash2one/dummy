
#ifndef _MONSTERPROPMGR_H_
#define _MONSTERPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <protocol/server/protocommondata.h>
#include <logic/base/basepropmgr.h>
#include <map>
#include <vector>
using namespace std;


/// ��������������󳤶�
#define NAME_LEN_MAX	32


/**
 * @brief 
 */
typedef struct tagMonsterProp
{
	UINT16	wKindID;		///< ��������
	TCHAR	szName[NAME_LEN_MAX];		///< ��������
	UINT8	byType;		//����(��ͨ1/boss2/��Ӣ3)
	UINT8   byFuncType;	//�������� 1 ��ǰ��ͨ���� 2 ����
	UINT8	byCareerID;//ְҵ����
	UINT16	wLevel;	//�ȼ�
	UINT64	qwHP;	// ����	
	UINT32	dwAttack; // ������
	UINT32  dwDefend;//����
	UINT16  wHitRate;//����(�ٷֱ�)
	UINT16	wDodgeRate;//����(�ٷֱ�)
	UINT16  wCritRate;//����(�ٷֱ�)
	UINT16	wDeCritRate;//����(�ٷֱ�)
	UINT16	wAngryValue;//ŭ��ֵ
	UINT16	wSkillID;//ӵ�еļ���ID
	UINT16	wSkillLevel;//ӵ�еļ��ܵȼ�
	UINT16	wSkillActionID; // ������ʽID
	UINT16	wSkillActionLevel; // ������ʽ�ȼ�
	UINT16	wSkillEffectID; // ����Ч��ID
	UINT16	wGodweaponQuality;//����Ʒ��
	UINT16	wGodweaponLevel;//�����ȼ�
	UINT32	dwGodweaponHP;//����HP
	UINT32	dwGodweaponAttack;//��������
	UINT16	wFakeID;	//����ٵ�ID��ֻ������Ͽͻ�����ʾ
}SMonsterProp;

typedef multimap<UINT16, SMonsterProp>	CMapShadeMonster;
typedef CMapShadeMonster::iterator  CMapShadeMonsterItr;

typedef vector<SMonsterProp*> CVecShadeMonster;
typedef CVecShadeMonster::iterator CVecShadeMonsterItr;

typedef std::map<UINT32, SMonsterProp> CMonsterPropMap;
typedef std::map<UINT32, SMonsterProp>::iterator CMonsterPropMapItr;

class CMonsterPropMgr  : public CBasePopMgr
{
public:



    DECLARE_SINGLETON_PROPMGR(CMonsterPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_MONSTER ; }
    BOOL Init();
    VOID UnInit();

public:
	SMonsterProp* GetMonsterProp(UINT16 wKindID);
	SMonsterProp* GetMonsterProp(UINT16 wKindID, UINT16 wLevel);
	SMonsterProp* GetShadeMonsterProp(UINT16 wKindID);
	const CMonsterPropMap& GetShadeMonsterProp() { return m_mapKind2ShadeMonsterProp; }

public:
    CMonsterPropMgr();
    virtual ~CMonsterPropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
	BOOL LoadFromDB();
private:
	CMonsterPropMap m_mapKind2ShadeMonsterProp;
	CMonsterPropMap m_mapKind2MonsterProp; //
	CMonsterPropMap m_mapKindLvl2MonsterProp; //ֻ��BOSS���в�ͬ�ȼ��������BOSS��������
};

#endif // #ifndef _MONSTERPROPMGR_H_
