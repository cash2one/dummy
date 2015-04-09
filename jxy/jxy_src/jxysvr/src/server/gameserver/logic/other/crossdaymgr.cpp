#include "crossdaymgr.h"
#include <net/cli/usermgr.h>
#include <common/client/errdef.h>
#include <logic/event/timereventmgr.h>
#include <net/gt/gtpktbuilder.h>
#include <logic/yabiao/yabiaomgr.h>
#include <logic/encourage/onlineencouragerecord.h>
#include <logic/player/player.h>
#include "logic/other/phystrength.h"
#include "logic/medal/playermedal.h"

VOID CCrossDayMgr::OnCrossDayEvent()
{
    DBG_INFO( "on crossday event!" );
    //�ڿ���ʱ����ս��ڵ����ݻ���
    //CYabiaoMgr::Instance()->OnCrossDay();

    CUser* poUser = NULL;
    CPlayer* poPlayer = NULL;
   
    const CSessionID2UserMap&  mapUser = CUserMgr::Instance()->GetAllUserMap();
    for (CSessionID2UserMapConstItr itr = mapUser.begin(); itr != mapUser.end(); itr++)
    {
        poUser = itr->second;
        if(NULL == poUser)
        {
            continue;
        }

        poPlayer = poUser->GetPlayer();
        if(NULL == poPlayer)
        {
            continue;
        }
		//���߽���
		OnOnlineEncourage(poPlayer);
		//��ʱѫ��
		OnLimitTimeMedal(poPlayer);
    }

    CTimerEventMgr::Instance()->ResetCrossDayEventInterval();
}

//���߽���
VOID CCrossDayMgr::OnOnlineEncourage(CPlayer* poPlayer)
{
	 static PKT_CLIGS_CROSS_DAY_NTF stNtf;

	 memset(&stNtf, 0, sizeof(stNtf));

	 poPlayer->GetPrompt(stNtf.stPromptInfo);

	 UINT16 encourageRet = poPlayer->GetOnlineEncourageRecord().GetCurEncourage(stNtf.awRecvCountDown[0], stNtf.astOnlineEncourage[0]);
	 if( ERR_RECV_ONLINE_ENCOURAGE::ID_SUCCESS == encourageRet )
	 {
		 stNtf.byOnlineEncourageFlag = 1;
	 }
	 poPlayer->GetPhystrength().GetPhyStrengthInfo(stNtf.stCurPhyStrengthInfo);
	 poPlayer->SendMsg((CHAR*)(&stNtf), CLIGS_CROSS_DAY_NTF);
}
//��ʱѫ�¼���
VOID CCrossDayMgr::OnLimitTimeMedal(CPlayer* poPlayer)
{
	CPlayerMedal* poPlayerMedal = poPlayer->GetPlayerMedal();
	if ( NULL == poPlayerMedal )
	{
		return ;
	}

	poPlayerMedal->CheckEveryDay();
}
