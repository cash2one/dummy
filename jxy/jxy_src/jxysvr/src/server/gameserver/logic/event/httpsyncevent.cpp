#include "httpsyncevent.h"
#include <db/autosqlbuf.h>
#include <framework/gsapi.h>
#include "logic/http/httpmgr.h"
#include "logic/http/getconfigshttpcmd.h"



CHttpSyncEvent::CHttpSyncEvent()
{

}

CHttpSyncEvent::~CHttpSyncEvent()
{

}

UINT32 CHttpSyncEvent::OnEvent()
{
	//Ͷ��һ�λ�ȡ���ݵ�����
	CBaseHttpCMD *poCmd = CHttpMgr::Instance()->CreateCmd(EHCT_GETCONFIGS);
	if (NULL == poCmd)
	{
		return 0;
	}
	SGetConfigs stGetConfigs;
	//�����ID�Ƿ���ȷ
	CSDServerID	oServerID(gsapi::GetLocalID());
	stGetConfigs.wZoneID = oServerID.GetAreaID();
	poCmd->SetUserData(&stGetConfigs, sizeof(SGetConfigs), 0);
	poCmd->Init();
	if(!CHttpMgr::Instance()->AddCommand(poCmd))
	{
		CHttpMgr::Instance()->FreeCmd(poCmd);
	}
    return 0;
}

INT32  CHttpSyncEvent::OnDestroy()
{
    return 0;
}

UINT32	CHttpSyncEvent::GetInterval()
{
    return ms_nInterval;
}