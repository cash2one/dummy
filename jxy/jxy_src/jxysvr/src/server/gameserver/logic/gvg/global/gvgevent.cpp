///<------------------------------------------------------------------------------
//< @file:   gvgevent.cpp
//< @author: hongkunan
//< @date:   2014��1��16�� 22:22:57
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "gvgevent.h"
#include "logic/gvg/global/pullgroup.h"
#include "logic/event/timereventmgr.h"
#include "logic/gvg/gvgpropmgr.h"
#include "logic/gvg/global/pullplayermgr.h"
#include "logic/gvg/global/gvgmgr.h"
#include "logic/gvg/local/gvgbuild.h"
#include "common/server/utility.h"

#include <sdtime.h>

#define DAYS_OF_WEEK 7
#define SECONDS_OF_DAY 86400

UINT32 CGvGEvent::OnEvent()
{
    // �����ս���ɻ�Ƿ�Ӧ������һ�ִ�
    UINT32 dwInterval = GetInterval();
    if(dwInterval > 0)
    {
        // ��⵽���������һ�ִλ�ʣ�ºܶ��룬˵�������������ù��ʱ�䣬��ʱ���½�����һ�ֱ����Ķ�ʱ�������¼�����
        CTimerEventMgr::Instance()->ResetGvGEventInterval(this, this->GetInterval());
        return 0;
    }

    GVG_STAGE eCurStage  = (GVG_STAGE)CGvGMgr::Instance()->GetCurStage();
    GVG_STAGE eNextStage = gvgutil::GetNextStage(eCurStage);

    // ����Ƿ��ѳɹ����뵽��һ��
    BOOL bSucc = CGvGMgr::Instance()->EnterNextStage();
    if(FALSE == bSucc)
    {
        dwInterval = 3;

        // ������һ��ʧ�ܣ�˵����һ��δ������ϻ��߳������쳣����ʱ���½��뱾�֣�����ÿ��һ��ʱ�䳢���Ž�����һ�ִΣ�ֱ�����Խ�����һ��
        CGvGMgr::Instance()->ReEnterCurStage();
        CTimerEventMgr::Instance()->ResetGvGEventInterval(this, dwInterval);

        SYS_CRITICAL(_SDT("[%s: %d]: CGvGMgr::EnterNextStage fail, session = %u, <current stage = %u>, <target stage = %u>, reenter current stage now, interval = %us"), MSG_MARK, CGvGMgr::Instance()->GetCurSession(), eCurStage, eNextStage, dwInterval);
    }
    else
    {
        dwInterval = GetInterval();

        // �ɹ�������һ�֣����½�����һ�ֱ����Ķ�ʱ
        CTimerEventMgr::Instance()->ResetGvGEventInterval(this, dwInterval);
        USR_INFO(_SDT("[%s: %d]: CGvGMgr::EnterNextStage success, session = %u, <before stage = %u>, <current stage = %u>, interval to next stage = %s"), MSG_MARK, CGvGMgr::Instance()->GetCurSession(), eCurStage, eNextStage, gvgutil::TimeToDayHourMinuteSec(dwInterval).c_str());
    }

    return 0;
}

UINT32 CGvGEvent::GetInterval()
{
    if (!CGvGPropMgr::Instance()->GetGvGProp().bOpenActivity)
    {
        return 86400;
    }

    UINT64 qwNow      = SDTimeSecs();

    GVG_STAGE eCurStage  = CGvGMgr::Instance()->GetCurStage();
    GVG_STAGE eNextStage = gvgutil::GetNextStage(eCurStage);

    DT_GVG_ACTIVITY_DATA &stActData = CGvGMgr::Instance()->GetActivityData();

    UINT64 qwNextStageTime = 0;

    // ���ս��Ƿ��ǵ�һ�ο���
    BOOL bFirstActivity = (0 == stActData.qwStartTime || 0 == stActData.wSessionID);
    if(bFirstActivity){
        stActData.wSessionID  = 0;
        stActData.qwStartTime = 0;
    }

    if(bFirstActivity || GVG_APPLY == eNextStage){
        // ��һ��ı���ʱ��
        UINT64 qwNextActivityOpenDate = CGvGPropMgr::Instance()->GetOpenDateBySession(stActData.wSessionID + 1);

        // ���δ�����һ��Ŀ���ʱ�䣬�Ͳ�������һ���ˣ�ֱ��һֱ������ȥ����������һ��
        if (0 == qwNextActivityOpenDate){
            qwNextStageTime = qwNow + 86400;
        }else{
            qwNextStageTime = CGvGPropMgr::Instance()->GetStageStartTime(qwNextActivityOpenDate, GVG_1_APPLY);
        }
    }
    else
    {
        qwNextStageTime = CGvGPropMgr::Instance()->GetStageStartTime(stActData.qwStartTime, eNextStage);
    }

    UINT32 dwInterval = (UINT32)(qwNow < qwNextStageTime ? qwNextStageTime - qwNow : 0);
    // DBG_INFO(_SDT("[%s: %d]: CGvGEvent::GetInterval get next interval = %u, current stage = %u"), MSG_MARK, dwInterval, eCurStage);
    return dwInterval;
}

UINT32 CGvGReloadPropEvent::OnEvent()
{
    UINT32 dwPreInterval = 0;
    CGvGEvent *poGvGEvent = CTimerEventMgr::Instance()->GetGvGEvent();
    if (poGvGEvent){
        dwPreInterval = poGvGEvent->GetInterval();
    }

    // ����ط�������ʽ��ȡ���ݿ�
    CGvGPropMgr::Instance()->LoadGvGArenaPropDB();
    CGvGPropMgr::Instance()->LoadGvGPropDB();
    // CGvGPropMgr::Instance()->LoadZoneNameDB();

    if (!CGvGPropMgr::Instance()->IsFakeTime()){
        CGvGPropMgr::Instance()->LoadGvGTimePropDB();
        CGvGPropMgr::Instance()->LoadGvGOpenDatePropDB();
    }
    
    CGvGPropMgr::Instance()->LoadGvGUnLockPropDB();

    if (CGvGMgr::Instance()){
        CGvGMgr::Instance()->CheckOpenUp();
        CGvGPropMgr::Instance()->ConvertToClientDisplayTime(CGvGMgr::Instance()->GetCurSession());
    }

    if (CGvGBuild::Instance()){
        CGvGBuild::Instance()->CheckOpenUp();
        CGvGPropMgr::Instance()->ConvertToClientDisplayTime(CGvGBuild::Instance()->GetCurSession());
    }
    
    if (dwPreInterval > 0 && poGvGEvent){
        UINT32 dwNowInterval = poGvGEvent->GetInterval();
        if (dwNowInterval < dwPreInterval){
            CTimerEventMgr::Instance()->StopGvGEvent();
            CTimerEventMgr::Instance()->AddGvGEvent();
        }
    }

    return 0;
}

UINT32 CGvGReloadPropEvent::GetInterval()
{
    return 300;
}

UINT32 CGvGRePullEvent::OnEvent()
{
    CPullPlayerMgr::Instance()->Pull();
    return 0;
}

UINT32 CGvGRePullEvent::GetInterval()
{
    GVG_STAGE eCurGvGStage = CGvGMgr::Instance()->GetCurStage();

    UINT32 dwInterval = 0;

    BOOL bDone = CGvGMgr::Instance()->IsDone(eCurGvGStage);
    if(!bDone)
    {
        dwInterval = CGvGPropMgr::Instance()->GetGvGProp().wRePullInterval;
    }
    else
    {
        dwInterval = CTimerEventMgr::Instance()->GetGvGEventInterval();
    }

    if(0 == dwInterval)
    {
        dwInterval = CGvGPropMgr::Instance()->GetGvGProp().wRePullInterval;

        if(0 == dwInterval)
        {
            dwInterval = 10;
        }
    }
    
    return dwInterval;    
}
