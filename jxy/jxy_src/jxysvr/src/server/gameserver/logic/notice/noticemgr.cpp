#include "noticemgr.h"
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <db/autosqlbuf.h>
#include <framework/gsconfig.h>
#include <net/cli/usermgr.h>
#include "logic/player/playerbasedatacachemgr.h"
#include "logic/activity/eatbreadpropmgr.h"
#include "logic/activity/bossbattlepropmgr.h"
#include <logic/other/errmsgmgr.h>
#include <framework/gsapi.h>

IMPLEMENT_SINGLETON(CNoticeMgr)


CNoticeMgr::CNoticeMgr()
{

}

CNoticeMgr::~CNoticeMgr()
{

}

BOOL CNoticeMgr::Init()
{
    return TRUE;
}

VOID CNoticeMgr::UnInit()
{

}

VOID CNoticeMgr::OnRankNotify()
{
	SPlayerBaseData *poPlayerBaseData = NULL;
	CPlayerID2PlayerBaseDataMapConstItr itr;
	const CPlayerID2PlayerBaseDataMap &  mapPlayerID2PlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerID2PlayerBaseDataMap();
	itr = mapPlayerID2PlayerBaseData.begin();
	for (itr; itr != mapPlayerID2PlayerBaseData.end(); itr++)
	{
		poPlayerBaseData = itr->second;
		if (NULL == poPlayerBaseData)
		{
			continue;
		}

		//�������Ƿ��ǻ����ˡ�
		if(ERFK_PLAYER != poPlayerBaseData->byRobotFunc)
		{
			continue;
		}

		//���ǵ����ܸտ��ž����������Ĭ�ϲ����ڵ�����
		if (0 == poPlayerBaseData->dwRank || 0 == poPlayerBaseData->dwNotifyRank)
		{
			continue;
		}


		//�����������������������
		if (poPlayerBaseData->dwRank >= poPlayerBaseData->dwNotifyRank)
		{
			continue;
		}

		//����¼ʱ����ڵǳ�ʱ�䣬������Ҹպ����ߣ����߳���
		if (poPlayerBaseData->qwLoginTime > poPlayerBaseData->qwLogoffTime)
		{
			poPlayerBaseData->qwLogoffTime = poPlayerBaseData->qwLoginTime;
		}

		//û�п�������֪ͨ�ģ�ֱ�� �Ź���
		//if (0 == strlen((char*)poPlayerBaseData->abyToken))
		//{
		//	continue;
		//}

		CSDDateTime oNow(SDTimeSecs());
		CSDDateTime oLogoffTime(poPlayerBaseData->qwLogoffTime);
		//������ʱ���Ƿ��Ѵ�����δ��½������ÿ���ٴ��췢һ�Ρ�
		UINT64 qwDiffDay = oNow.DiffDay(oLogoffTime);	//�������ߵ�������
		if ((qwDiffDay % 2 == 0) && (qwDiffDay / 2 != 0))
		{
			char szPayLoad[256] = {0};
			sprintf(szPayLoad, "rank %u down to %u", poPlayerBaseData->dwRank, poPlayerBaseData->dwNotifyRank);
			gsapi::NoticeMsg(poPlayerBaseData->dwID, ENT_RACE, (CHAR*)poPlayerBaseData->abyToken, (CHAR*)SDGBK2UTF8(szPayLoad).c_str());

			USR_INFO(_SDT("[%s: %d]: playerid:%u PayLoad:%s"), MSG_MARK, poPlayerBaseData->dwID, szPayLoad);
		}
		else
		{
			DBG_INFO(_SDT("[%s: %d]:playerid [%u] nod dif two day"), MSG_MARK, poPlayerBaseData->dwID);
		}
	}
}

VOID CNoticeMgr::OnActivityNotifyEatBread(UINT8 byStartHour, UINT8 byStartMin)
{
	SPlayerBaseData *poPlayerBaseData = NULL;
	CPlayerID2PlayerBaseDataMapConstItr itr;
	const CPlayerID2PlayerBaseDataMap &  mapPlayerID2PlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerID2PlayerBaseDataMap();
	itr = mapPlayerID2PlayerBaseData.begin();
	for (itr; itr != mapPlayerID2PlayerBaseData.end(); itr++)
	{
		poPlayerBaseData = itr->second;
		if (NULL == poPlayerBaseData)
		{
			continue;
		}

		//�������Ƿ��ǻ����ˡ�
		if(ERFK_PLAYER != poPlayerBaseData->byRobotFunc)
		{
			continue;
		}

		if (0 == poPlayerBaseData->bEatBreadNotify)
		{
			continue;
		}

		//û�п�������֪ͨ�ģ�ֱ�� �Ź���
		//if (0 == strlen((char*)poPlayerBaseData->abyToken))
		//{
		//	continue;
		//}

		CHAR szPayLoad[256] = {0};
		//sprintf(szPayLoad, "�԰��ӻ����%u:%u��ʼ", byStartHour, byStartMin);
		//((CGSApplication*)SDGetApp())->NoticeMsg(poPlayerBaseData->dwID, ENT_EATBREAD, (CHAR*)poPlayerBaseData->abyToken, (CHAR*)SDGBK2UTF8(szPayLoad).c_str());
		vector<string> vecFillMsg;
		CHAR szBuff[32] = {0};
		sprintf(szBuff, "%u", byStartHour);
		vecFillMsg.push_back(szBuff);
		sprintf(szBuff, "%u", byStartMin);
		vecFillMsg.push_back(szBuff);
		gsapi::NoticeMsg(poPlayerBaseData->dwID, ENT_EATBREAD, (CHAR*)poPlayerBaseData->abyToken, CMsgDefMgr::Instance()->GetErrMsg("EATBREAD_PROMPT", &vecFillMsg).c_str());
	}
}

VOID CNoticeMgr::OnActivityNotifyBossBattle(UINT8 byStartHour, UINT8 byStartMin)
{
	SPlayerBaseData *poPlayerBaseData = NULL;
	CPlayerID2PlayerBaseDataMapConstItr itr;
	const CPlayerID2PlayerBaseDataMap &  mapPlayerID2PlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerID2PlayerBaseDataMap();
	itr = mapPlayerID2PlayerBaseData.begin();
	for (itr; itr != mapPlayerID2PlayerBaseData.end(); itr++)
	{
		poPlayerBaseData = itr->second;
		if (NULL == poPlayerBaseData)
		{
			continue;
		}

		//�������Ƿ��ǻ����ˡ�
		if(ERFK_PLAYER != poPlayerBaseData->byRobotFunc)
		{
			continue;
		}

		if (0 == poPlayerBaseData->bBossBattleNotify)
		{
			continue;
		}

		//û�п�������֪ͨ�ģ�ֱ�� �Ź���
		//if (0 == strlen((char*)poPlayerBaseData->abyToken))
		//{
		//	continue;
		//}

		CHAR szPayLoad[256] = {0};
		//sprintf(szPayLoad, "��ɱBOSSս�����%u:%u��ʼ", byStartHour, byStartMin);
		//((CGSApplication*)SDGetApp())->NoticeMsg(poPlayerBaseData->dwID, ENT_BOSSBATTLE, (CHAR*)poPlayerBaseData->abyToken, (CHAR*)SDGBK2UTF8(szPayLoad).c_str());
		vector<string> vecFillMsg;
		CHAR szBuff[32] = {0};
		sprintf(szBuff, "%u", byStartHour);
		vecFillMsg.push_back(szBuff);
		sprintf(szBuff, "%u", byStartMin);
		vecFillMsg.push_back(szBuff);
		gsapi::NoticeMsg(poPlayerBaseData->dwID, ENT_BOSSBATTLE, (CHAR*)poPlayerBaseData->abyToken, CMsgDefMgr::Instance()->GetErrMsg("BOSSB_PROMPT", &vecFillMsg).c_str());
	}
}

VOID CNoticeMgr::OnActivityNotifyCourage( UINT8 byStartHour, UINT8 byStartMin )
{
    SPlayerBaseData *poPlayerBaseData = NULL;
    CPlayerID2PlayerBaseDataMapConstItr itr;
    const CPlayerID2PlayerBaseDataMap &  mapPlayerID2PlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerID2PlayerBaseDataMap();
    itr = mapPlayerID2PlayerBaseData.begin();
    for (itr; itr != mapPlayerID2PlayerBaseData.end(); itr++)
    {
        poPlayerBaseData = itr->second;
        if (NULL == poPlayerBaseData)
        {
            continue;
        }

        //�������Ƿ��ǻ����ˡ�
        if(ERFK_PLAYER != poPlayerBaseData->byRobotFunc)
        {
            continue;
        }

        if (0 == poPlayerBaseData->bCoruageNotify)
        {
            continue;
        }

        //û�п�������֪ͨ�ģ�ֱ�� �Ź���
        //if (0 == strlen((char*)poPlayerBaseData->abyToken))
        //{
        //	continue;
        //}

        CHAR szPayLoad[256] = {0};
        //sprintf(szPayLoad, "�԰��ӻ����%u:%u��ʼ", byStartHour, byStartMin);
        //((CGSApplication*)SDGetApp())->NoticeMsg(poPlayerBaseData->dwID, ENT_EATBREAD, (CHAR*)poPlayerBaseData->abyToken, (CHAR*)SDGBK2UTF8(szPayLoad).c_str());
        vector<string> vecFillMsg;
        CHAR szBuff[32] = {0};
        sprintf(szBuff, "%u", byStartHour);
        vecFillMsg.push_back(szBuff);
        sprintf(szBuff, "%u", byStartMin);
        vecFillMsg.push_back(szBuff);
        gsapi::NoticeMsg(poPlayerBaseData->dwID, ENT_COURAGETTLE, (CHAR*)poPlayerBaseData->abyToken, CMsgDefMgr::Instance()->GetErrMsg("COURAGE_PROMPT", &vecFillMsg).c_str());
    }
}
