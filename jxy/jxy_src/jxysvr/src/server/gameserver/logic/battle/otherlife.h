#ifndef _OTHERLIFE_H_
#define _OTHERLIFE_H_

#include <logic/base/baseobj.h>

#include <vector>
#include <protocommondata.h>

class COtherLife: public CBaseObj
{
public:
    COtherLife();
    ~COtherLife();

public:
	VOID InitCurBattleAttr();
public:
	INT32 AddHPChange(INT32 nHP);
	inline BOOL IsDead() { return m_stCurDT_BATTLE_ATTRIBUTE.dwHP == 0 ? TRUE : FALSE; }
	inline const DT_BATTLE_ATTRIBUTE& GetDT_BATTLE_ATTRIBUTE() { return m_stDT_BATTLE_ATTRIBUTE; }
	inline const DT_BATTLE_ATTRIBUTE& GetCurDT_BATTLE_ATTRIBUTE() { return m_stCurDT_BATTLE_ATTRIBUTE; }
	virtual UINT32 GetHurtValue(){ return m_stCurDT_BATTLE_ATTRIBUTE.dwAttack; }
	VOID AddAngryChange(INT16 shAngry);
	inline UINT16 GetCurAngry() { return m_wCurAngry; }
	inline vector<DT_ANGRY_DATA>& GetAngryChange() { return m_vecAngryChange; }
public:

protected:

protected:
	DT_BATTLE_ATTRIBUTE			m_stDT_BATTLE_ATTRIBUTE;	//��Ϊ��������Ϊ����ӵ�е�ս�����ԣ�����HPѪ������������
	DT_BATTLE_ATTRIBUTE			m_stCurDT_BATTLE_ATTRIBUTE;	
	DT_HIDE_BATTLE_ATTRIBUTE	m_stHideBattleAttr;
	UINT16						m_wCurAngry;		//��ǰŭ��
	vector<DT_ANGRY_DATA>		m_vecAngryChange;	//ŭ���仯
};

#endif
