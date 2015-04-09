#ifndef _MONSTERGODWEAPON_H_
#define _MONSTERGODWEAPON_H_

#include <logic/battle/otherlife.h>
#include "common/server/utility.h"

using namespace SGDP;


class CMonster;
class CShadeMonster;
class CMonsterGodWeapon: public COtherLife
{
public:
    CMonsterGodWeapon();
    ~CMonsterGodWeapon();

public:

    //��ʼ����ض���
    BOOL Init(UINT16 wQuality, UINT16 wLevel, UINT32 dwHP, UINT32 dwAttack, CMonster* poMonster);
	BOOL Init(UINT16 wQuality, UINT16 wLevel, UINT32 dwHP, UINT32 dwAttack, CShadeMonster* poMonster);
	VOID GetDT_GODWEAPON_BATTLE_DATA(DT_GODWEAPON_BATTLE_DATA& stGodweaponInfo);
protected:

private:
	CMonster*	m_poMonster;
	CShadeMonster* m_poShadeMonster;
	UINT16      m_wQuality; //�����׼�Ʒ�ʣ�0��ʾû��
	UINT16      m_wLevel; //�����ȼ�
};

DECLARE_CLASS_POOL_MGR(CMonsterGodWeapon);

#endif
