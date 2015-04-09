#include <common/server/utility.h>
#include <logic/base/dbconfig.h>
#include <sdstring.h>
#include <sdutil.h>
#include <framework/gsapplication.h>
#include "gmpropmgr.h"


#define SQL_READ_FORMATION_STRING "select * from formationprop"


IMPLEMENT_SINGLETON(CGmPropMgr);

CGmPropMgr::CGmPropMgr()
{
}

CGmPropMgr::~CGmPropMgr()
{
}

BOOL CGmPropMgr::Init()
{
    return LoadFromDB();
}

VOID CGmPropMgr::UnInit()
{

}


// ������Դ��ȡ����
BOOL CGmPropMgr::LoadFromDB()
{
	/*
	SGDP::ISDDBSession*	pDBSession = ((CGSApplication*)SDGetApp())->GetDBMgr()->GetCfgDBSession();
	if(NULL == pDBSession)
	{
	return FALSE;
	}
	SGDP::ISDDBRecordSet* pRes = NULL;
	UINT32 dwErrID = 0;
	string strErr;
	INT32 nRet = pDBSession->ExecuteSqlRs(SQL_READ_FORMATION_STRING, &pRes, &dwErrID,  &strErr);
	if(SDDB_HAS_RECORDSET != nRet)
	{
	SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);      
	return FALSE;
	}
	BOOL bHaveDataFlag = FALSE;
	// ��ӡ��ѯ�ı���
	while(pRes->GetRecord())// �����н��ʱ
	{
        SGmUnlockProp stGmUnlockProp;
        memset(&stGmUnlockProp, 0, sizeof(stGmUnlockProp));

		stGmUnlockProp.byGmIdx = SGDP::SDAtou(pRes->GetFieldValueByName("GmIdx"));
		stGmUnlockProp.wUnlockLevel = SGDP::SDAtou(pRes->GetFieldValueByName("UnlockLevel"));

		m_mapGmIdx2UnlockLevel[stGmUnlockProp.byGmIdx] = stGmUnlockProp;

		bHaveDataFlag = TRUE;
	}
    if(NULL != pRes)
    {
        pRes->Release();
        pRes = NULL;
    }

    return bHaveDataFlag;
	*/

	return TRUE;
}

