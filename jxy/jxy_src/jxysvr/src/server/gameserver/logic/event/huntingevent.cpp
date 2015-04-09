#include "huntingevent.h"
#include <logic/faction/factionmgr.h>
#include "timereventmgr.h"
#include <logic/faction/factionprop.h>
#include <logic/factionshade/shadepropmgr.h>
#include "logic/other/errmsgmgr.h"
CHuntingEvent::CHuntingEvent()
{
	m_bOpenFlag = FALSE;
}

CHuntingEvent::~CHuntingEvent()
{
	m_bOpenFlag = FALSE;
}

UINT32 CHuntingEvent::OnEvent()
{
	if (m_bOpenFlag)
	{
		DT_FACTION_LOG_DATA stLogData = {0};
		stLogData.byAction = EFLID_ShadeActivity;
		stLogData.adwParamList[0] = EFB_Shade;
		stLogData.qwLogTime = SGDP::SDTimeSecs();
		CShadePropMgr::Instance()->SetOpenFlag(m_bOpenFlag);
		const CMapFaction& mapFaction = CFactionMgr::Instance()->GetFactions();
		for ( CMapFaction::const_iterator itr = mapFaction.begin(); itr != mapFaction.end(); itr++)
		{
			itr->second->SendMessageByShadePrompt();
			if( 0 != itr->second->GetDT_FACTION_BASE_DATA().dwShadeLevel)
			{
				itr->second->AddFactionLogData(stLogData);
			}
		}
		string strMsg = CMsgDefMgr::Instance()->GetErrMsg("FACTION_ACTIVI_HUNTING", NULL);
		CFactionMgr::Instance()->AddFactionActivityChat(strMsg);
	}
	else
	{
		CShadePropMgr::Instance()->SetOpenFlag(m_bOpenFlag);
		CFactionMgr::Instance()->SendHuntingActiviEndNtf();
	}
	
	CTimerEventMgr::Instance()->ResetHuntingEvent(this);
	return 0;
}

INT32 CHuntingEvent::OnDestroy()
{
	return 0;
}

VOID CHuntingEvent::SetParam( BOOL bOpenFlag)
{
	m_bOpenFlag = bOpenFlag;
}

UINT32 CHuntingEvent::GetInterval()
{
	SShadeTaskInfoProp stProp;
	CFactorPropMgr::Instance()->GetTaskInfoProp(EFTT_HUNTING, stProp);
	
	CSDDateTime oCurDataTime(SGDP::SDTimeSecs());
	CSDDateTime oActiviDataTime(SGDP::SDTimeSecs());

	BOOL bFlag = CShadePropMgr::Instance()->GetOpenFlag();
	if ( m_bOpenFlag )//����������¼�
	{

		oActiviDataTime.SetTime(stProp.byStartHour, stProp.byStartMin, 0);
		INT64 qwDiffTime = oActiviDataTime.DiffSecond(oCurDataTime);

		if ( bFlag )
		{
			oActiviDataTime.IncDay(1);
			return static_cast<UINT32>(oActiviDataTime.DiffSecond(oCurDataTime));//����ʼ
		}
		else
		{
			if (0 < qwDiffTime)	//δ�����
			{
				return static_cast<UINT32>(qwDiffTime);
			}
			else if ( 0 < (stProp.wKeepTime + qwDiffTime))
			{
				return 1; //��У�1 �����
			}
			else
			{
				oActiviDataTime.IncDay(1);
				return static_cast<UINT32>(oActiviDataTime.DiffSecond(oCurDataTime));//����ʼ
			}
		}

		
	}
	else//�ر��¼�
	{
		oActiviDataTime.SetTime(stProp.byStartHour, stProp.byStartMin, 0);
		oActiviDataTime.IncSecond(stProp.wKeepTime);
		INT64 qwDiffTime = oActiviDataTime.DiffSecond(oCurDataTime);
		if ( bFlag)
		{
			return static_cast<UINT32>(qwDiffTime);
		}
		else
		{
			if ( 0 < qwDiffTime)
			{
				return static_cast<UINT32>(qwDiffTime);
			}
			else
			{
				oActiviDataTime.IncDay(1);
				return static_cast<UINT32>(oActiviDataTime.DiffSecond(oCurDataTime));//������
			}
		}
		
	}
}