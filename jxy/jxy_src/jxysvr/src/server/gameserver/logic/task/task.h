#ifndef _TASK_H_
#define _TASK_H_

#include "taskprop.h"
#include <logic/base/baseobj.h>


//ÿ����������Ϣ,ÿ����Ҷ����������ȵ��������������Ƿ�ﵽ��������
//�½���Ҿ͸������ߵĵ�һ������
//�����������Լ��������ڶ������Ե�


//ETS_GIVEN = 0,//����
//ETS_ACCEPTED = 1,//����,��״̬��������������豣��
//ETS_ENCOURAGE = 2,//������ɣ�����ȡ����
//ETS_FINISHED = 3,//������Ѿ���ȡ����,���ܻ�����ڸ���û����һ������ʱ


class CPlayer;
class CTask: public CBaseObj
{
public:
    CTask();
    ~CTask();
public:
    BOOL		Init(DT_TASK_DATA* pstDT_TASK_DATA, CPlayer* poOwner);
    UINT16	CheckAccept();//�����������Ƿ�ɹ�������������ѡ���Լ�¼
    BOOL		CheckFinish();//�����������Ƿ�ɹ����������ɷ���TRUE��������������������
    DT_TASK_DATA& GetDT_TASK_DATA()
    {
        return m_stDT_TASK_DATA;
    }
    DT_TASK_CONDITION& GetConditionRecord()
    {
        return m_stDT_TASK_DATA.stTaskConditionInfo;
    }
    STaskProp* GetTaskProp();
    VOID	GetDT_TASK_BASE_DATA_CLI(DT_TASK_BASE_DATA& stDT_TASK_BASE_DATA);
    VOID	GetDT_TASK_ENCOURAGE_DATA(DT_TASK_ENCOURAGE_DATA& stTaskEncourage);

    UINT16	Encourage();//����

    UINT8	GetCanAcceptFalg()
    {
        return m_byCanAcceptFlag;
    }
protected:
    BOOL		CheckFinish(CFinishCondition* poFinishCondition);
    UINT16	CheckAccept(CAcceptType2CheckMap& mapAcceptCondition);
private:
    DT_TASK_DATA		m_stDT_TASK_DATA;//�����¼
    UINT8				m_byCanAcceptFlag;//�Ƿ�ɽ�(���ڸ���״̬������)
};

#endif

