#ifndef _GODWEAPON_H_
#define _GODWEAPON_H_

#include <logic/battle/otherlife.h>
#include "godweaponpropmgr.h"
#include <common/server/utility.h>

using namespace SGDP;


class CPlayer;
class CHero;
class CGodWeapon: public COtherLife
{
public:
    CGodWeapon();
    ~CGodWeapon();

public:

    //��ʼ����ض���
    BOOL Init(DT_GODWEAPON_DATA* pstDT_GODWEAPON_DATA, CPlayer* poOwner, CHero*	poHero);

    DT_GODWEAPON_DATA& GetDT_GODWEAPON_DATA() { return m_stDT_GODWEAPON_DATA; };

    VOID GetDT_GODWEAPON_DATA_CLI(DT_GODWEAPON_DATA_CLI& stDT_GODWEAPON_DATA_CLI) { memcpy(&stDT_GODWEAPON_DATA_CLI, &m_stDT_GODWEAPON_DATA_CLI, sizeof(DT_GODWEAPON_DATA_CLI)); }
    DT_GODWEAPON_DATA_CLI GetDT_GODWEAPON_DATA_CLI()  {  return m_stDT_GODWEAPON_DATA_CLI; }

	const SAllAttrProp* GetCurGodWeaponAttr();

	virtual UINT32 GetHurtValue();
	UINT32 GetExtDefend(){ return m_dwExtDefend;}
	CHero* GetHero() { return m_poHero; }

    UINT16 Upgrade(UINT16 wQuality, UINT16 wLevel);		//�����Ƽ����Լӳ�

	VOID Recover( BOOL bUseGold );//�ͷ�����,���������

    VOID Reupdate();//���¸���Ϊ�տ���
	//������Ʒ��������Ӱ��
	VOID AddBattleByJewelry();

    BOOL	InitData();//��ʼ������
public:
	VOID GetDT_GODWEAPON_BATTLE_DATA(UINT16 wHeroKindID, DT_GODWEAPON_BATTLE_DATA& stGodweaponInfo);
	VOID UpgradeByScience(UINT32 dwScience);
protected:
    UINT16	UpgradeQuality();//��������
    UINT16	UpgradeLevel();//��ͨ����

private:
    DT_GODWEAPON_DATA		m_stDT_GODWEAPON_DATA;//
    CHero*				m_poHero;//
    DT_GODWEAPON_DATA_CLI	m_stDT_GODWEAPON_DATA_CLI;//����ÿ�η��ظ��ͻ��˲����ظ�����
	UINT32 m_dwExtAttack;//�������ӵĹ���
	UINT32 m_dwExtDefend;//�������ӵķ��� �� ��HP
};
DECLARE_CLASS_POOL_MGR(CGodWeapon)
#endif
