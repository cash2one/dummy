#include "bossbattleevent.h"
#include "timereventmgr.h"
#include <logic/activity/bossbattlemgr.h>
#include <sdutil.h>


CBossBattleEvent::CBossBattleEvent()
{
	m_bStartFlag = TRUE;
	m_bFirstFlag = TRUE;
	m_byActivityID = 0;
}

CBossBattleEvent::~CBossBattleEvent()
{

}

UINT32 CBossBattleEvent::OnEvent()
{
	if(m_bStartFlag)
	{
		CBossBattleMgr::Instance()->OnStartEvent(m_byActivityID);
	}
	else
	{
		CBossBattleMgr::Instance()->OnEndEvent(m_byActivityID);
	}
	
	CTimerEventMgr::Instance()->ResetBossBattleEventInterval(this);

	return 0;
}

BOOL CBossBattleEvent::OnDestroy()
{
	return TRUE;
}

UINT32 CBossBattleEvent::GetInterval()
{
	UINT32 dwInterval = 3600 * 24-1; //���ⲻ׼����ǰ1��
	UINT32 dwPassSec = GetDayPassSecond();
	UINT32 dwTime = 0;
	SBossBProp* poBossBProp = CBossBattlePropMgr::Instance()->GetBossBPropByID(m_byActivityID);
	if(NULL == poBossBProp)
	{
		SYS_CRITICAL( _SDT("[%s: %d] GetBossBPropByID[%d] Failed!"), MSG_MARK, m_byActivityID);		
		return 0xFFFFFFFF; //�൱������ö�ʱ��
	}
	//��ʼ�
	if(m_bStartFlag)
	{
		//��Ѿ�������������Ϊ����
		if(dwPassSec >= poBossBProp->dwEndTime)
		{
			dwInterval = (3600 * 24 - dwPassSec) + poBossBProp->dwStartEnterTime;
		}
		//�δ����
		else if(dwPassSec < poBossBProp->dwStartEnterTime)
		{
			dwInterval = poBossBProp->dwStartEnterTime - dwPassSec;
		}
		//��Ѿ�������δ����
		else
		{
			//�ѹ�����ʱ�䣬����������
			if(m_bFirstFlag)
			{
				dwInterval = 1;
			}
			//�Ѿ����������´�Ϊ����
			else
			{
				dwInterval = (3600 * 24 - dwPassSec) + poBossBProp->dwStartEnterTime;
			}			
		}

		m_bFirstFlag  = FALSE;
	}
	//�رջ
	else
	{
		//��Ѿ�������������Ϊ����
		if(dwPassSec >= poBossBProp->dwEndTime)
		{
			dwInterval = (3600 * 24 - dwPassSec) + poBossBProp->dwEndTime;
		}
		//�δ����
		else
		{
			dwInterval = poBossBProp->dwEndTime - dwPassSec;
		}
	}	

	return  dwInterval;
}

