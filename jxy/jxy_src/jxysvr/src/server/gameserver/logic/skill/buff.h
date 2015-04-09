

#ifndef _BUFF_H_
#define _BUFF_H_

#include <protocol/server/protocommondata.h>
#include <logic/base/baseobj.h>
#include "buffaffect.h"


using namespace std ;


#define  BUFF_INVALID_KINDID  0  //��ЧbuffID


/*************************

����1�غ��߼������ҷ�����1�Σ��Է�����1�η���1�غ�
buff���ǵ�ǰ�غ�������Ч������buff���ڹ���֮�����buff����Ӱ�칥�����������2�غ�

*************************/

class CBattleAttrObj;

class CBuff: public CBaseObj
{
public:
    CBuff();
    ~CBuff();
public:
    //
    BOOL Init(UINT16 wSkillID, UINT8 byBuffKindID, CBattleAttrObj* poGiver, CBattleAttrObj* poActor, UINT16 wParamValue, UINT8 byRoundNum);
    //Ч����Ч����,buff���ǹ���ǰ��Ч
    VOID Affect(EBuffAffectPhase ePhase, BOOL bMyAttack, CBattleAttrObj* poAttacker, CBattleAttrObj* poNormalAttackTarget);//poAttackerΪ������
    VOID EndRound(BOOL bEndBigRound);//�غϽ���

    UINT16	GetSkillID()
    {
        return m_wSkillID;
    }
    UINT8	GetKindID()
    {
        return m_byBuffKindID;
    }
    UINT8	GetRoundNum()
    {
        return m_byRoundNum;
    }
    CBattleAttrObj* GetActor()
    {
        return m_poActor;
    }
	VOID SetExtValue(UINT32 dwExtValue)
	{
		m_dwExtValue = dwExtValue;
	}

protected:

private:
    ///����
    UINT16			m_wSkillID;		//�ͷŸ�buff�ļ���ID
    UINT8			m_byBuffKindID;	//buff����
    CBattleAttrObj*	m_poActor;		//buff������
    CBattleAttrObj*	m_poGiver;		//buff�����ߣ�	�����߽�buff�ŵ�����������
    UINT16			m_wParamValue;	//buff����ֵ
    UINT8			m_byRoundNum;		//�����غ���
    CBuffAffect*		m_poBuffAffect;	//Ч��������
    //
    UINT8			m_byCurRoundIdx; //��ǰ�غ���
    BOOL				m_bRoundDecFlag; //�غ���--��־

	UINT32		m_dwExtValue;//һ���û���������
public:
    VOID		SetMemID(UINT32 dwMemID)
    {
        m_dwMemID = dwMemID;
    }
    UINT32		GetMemID()
    {
        return m_dwMemID;
    }
private:
    UINT32		m_dwMemID;//�ڴ�ID�����ڹ�����map����

};



#endif //#ifndef _BUFF_H_

