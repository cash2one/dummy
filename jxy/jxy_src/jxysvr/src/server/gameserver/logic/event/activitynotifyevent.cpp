
#include "activitynotifyevent.h"
#include <db/autosqlbuf.h>
#include "logic/activity/bossbattlepropmgr.h"

#include <sdutil.h>

CActivityNotifyEvent::CActivityNotifyEvent()
{

}

CActivityNotifyEvent::~CActivityNotifyEvent()
{

}

UINT32 CActivityNotifyEvent::OnEvent()
{
	//��ǰʱ��
	CSDDateTime SDNow(SDTimeSecs());
	//���BOSSս�Ƿ�Ҫ��ʼ
	CBossBActivityTimePropMap mapBossBStartTimeProp = CBossBattlePropMgr::Instance()->GetBossBStartTimeProp();
	CBossBActivityTimePropMapItr itr;
	for (itr = mapBossBStartTimeProp.begin(); itr != mapBossBStartTimeProp.end(); itr++)
	{
		SBossBProp & stBossBProp = itr->second;
		if (stBossBProp.byStartHour == SDNow.GetHour() && stBossBProp.byStartMin == SDNow.GetMinute())
		{

		}
	}
    return 0;
}

INT32  CActivityNotifyEvent::OnDestroy()
{
    return 0;
}




