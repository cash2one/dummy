///<------------------------------------------------------------------------------
//< @file:   gameserver\db\operatingactivitycmd.cpp
//< @author: Kang_zhiquan
//< @date:   2014��7��29�� 15:3:21
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "db/operatingactivitycmd.h"
#include "db/autosqlbuf.h"
COperatingActivityCMD::COperatingActivityCMD()
{
	
}
COperatingActivityCMD::~COperatingActivityCMD()
{
	
}
	/**
	* @brief �첽ִ��SQL����
	* @poDBConn �첽ִ��SQL�����Connection����
	* @return VOID
	*/						
VOID COperatingActivityCMD::OnExecuteSql(SGDP::ISDDBConnection* poDBConn)
{

	CAutoSqlBuf oAutoSql;

	CHAR* pszSql		= oAutoSql.GetSqlBuf();
	
	SDSprintf(pszSql, "call sp_changeOperatingActivity(%u, %u, '%s', '%s')", m_stActivity.dwStartZoneID, m_stActivity.dwEndZoneID, m_stActivity.strStartTime.c_str(), m_stActivity.strEndTime.c_str());
	UINT32 dwErr;
	string strError;
	SGDP::ISDDBRecordSet* pRecordSet = NULL;
	INT32 nRet = poDBConn->ExecuteSqlRs(pszSql, &pRecordSet, &dwErr, &strError);
	if(SDDB_SUCCESS > nRet)
	{
		m_bSuccess = FALSE;
		SYS_CRITICAL(_SDT("[%s: %d]: add  playergift data error!, SQL: %s, Error: %s"), MSG_MARK, pszSql, strError.c_str());
		return ;
	}
}

	/**
	* @brief ͬ��ִ��SQL������ص��߼�����
	* @return VOID
	*/
VOID COperatingActivityCMD::OnExecuted()
{

}

VOID COperatingActivityCMD::SetUserData(VOID* pUserData)
{
	m_stActivity = *(SOperatingActivity*)pUserData;
}