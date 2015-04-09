
#ifndef _MONSTERUPGRADEPROPMGR_H_
#define _MONSTERUPGRADEPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

/// ��������������󳤶�
#define NAME_LEN_MAX	32


/**
 * @brief 
 */
typedef struct tagMonsterUpgradeProp
{
	UINT16	wLevel;		///< �ȼ�(ֻ������ʾ)
	UINT8	byType;		///< ����(��ͨ1/boss2/��Ӣ3)
	//UINT8   byCareerID; /// ְҵID
	//UINT32	dwHP;		///< ����	
	//UINT32	dwAttack;		///< ������
	UINT32	dwEncourageExp;//��������
	UINT32	dwEncourageCoin;//����ͭ��	
	UINT32	dwEncourageStory;//����������δ���ſƼ�����
	UINT32	dwEncourageJingJie;//��������㣬δ���ž��粻�����������״βű�
}SMonsterUpgradeProp;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CMonsterUpgradePropMgr : public CBasePopMgr
{
public:
    typedef std::map<UINT32, SMonsterUpgradeProp> CMonsterUpgradePropMap;
    typedef std::map<UINT32, SMonsterUpgradeProp>::iterator CMonsterUpgradePropMapItr;

    DECLARE_SINGLETON_PROPMGR(CMonsterUpgradePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_MONSTER_UPGRADE ; }

    /**
     * @brief ��ʼ�����Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL Init();

    /**
     * @brief �������Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    VOID UnInit();


	SMonsterUpgradeProp* GetMonsterUpgradeProp(UINT16 wLevel, UINT8	byType);

public:
    CMonsterUpgradePropMgr();
    virtual ~CMonsterUpgradePropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
	BOOL LoadFromDB();

private:
	CMonsterUpgradePropMap m_mapMonsterUpgradeProp;
};

#endif // #ifndef _MONSTERPROPMGR_H_
