#include "courageevent.h"
#include "timereventmgr.h"
#include <logic/activity/couragemgr.h>
#include <sdutil.h>
#include "logic/activity/couragepropmgr.h"


CCourageEvent::CCourageEvent()
{
    m_bStartFlag = TRUE;
    m_bFirstFlag = TRUE;
    m_byActivityID = 0;
}

CCourageEvent::~CCourageEvent()
{

}

UINT32 CCourageEvent::OnEvent()
{
    if(m_bStartFlag)
    {
        CCourageMgr::Instance()->OnStartEvent(m_byActivityID);
    }
    else
    {
        CCourageMgr::Instance()->OnEndEvent(m_byActivityID);
    }

    CTimerEventMgr::Instance()->ResetCourageEventInterval(this);

    return 0;
}

BOOL CCourageEvent::OnDestroy()
{
    return TRUE;
}

UINT32 CCourageEvent::GetInterval()
{
    UINT32 dwInterval = 3600 * 24 - 1; //���ⲻ׼����ǰ1��
    UINT32 dwPassSec = GetDayPassSecond();
    UINT32 dwTime = 0;
    const SCourageActivityTimeProp* poProp = CCouraPropMgr::Instance()->GetCouragePropByID(m_byActivityID);
    if(NULL == poProp)
    {
        SYS_CRITICAL( _SDT("[%s: %d] SCourageActivityTimeProp[%d] Failed!"), MSG_MARK, m_byActivityID);
        return 0xFFFFFFFF; //�൱������ö�ʱ��
    }
    //��ʼ�
    if(m_bStartFlag)
    {
        //��Ѿ�������������Ϊ����
        if(dwPassSec >= poProp->dwEndTime)
        {
            dwInterval = (3600 * 24 - dwPassSec) + poProp->dwStartTime;
        }
        //�δ����
        else if(dwPassSec < poProp->dwStartTime)
        {
            dwInterval = poProp->dwStartTime - dwPassSec;
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
                dwInterval = (3600 * 24 - dwPassSec) + poProp->dwStartTime;
            }
        }

        m_bFirstFlag  = FALSE;
    }
    //�رջ
    else
    {
        //��Ѿ�������������Ϊ����
        if(dwPassSec >= poProp->dwEndTime)
        {
            dwInterval = (3600 * 24 - dwPassSec) + poProp->dwEndTime;
        }
        //�δ����
        else
        {
            dwInterval = poProp->dwEndTime - dwPassSec;
        }
    }

    return  dwInterval;
}

