#include "setcenterpayprocessed.h"
#include <framework/gsapi.h>
#include "logic/record/recordmgr.h"
#include <net/gt/gtpktbuilder.h>
#include "common/server/dblock.h"
#include <logic/player/player.h>
#include <logic/player/playermgr.h>
#include <net/recharge/rcclient.h>

CSetCenterPayProcessed::CSetCenterPayProcessed()
{
    m_bSuccess = FALSE;
}

CSetCenterPayProcessed::~CSetCenterPayProcessed()
{

}


VOID SDAPI CSetCenterPayProcessed::OnExecuteSql(SGDP::ISDDBConnection* poDBConn)
{
    poDBConn->BeginTransaction();
    if( SetPayProcessed( poDBConn ) )
    {
        poDBConn->CommitTransaction();
    }
    else
    {
        poDBConn->RollbackTransaction();
    }
}

/**
* @brief ͬ��ִ��SQL������ص��߼�����
* @return VOID
*/
VOID SDAPI CSetCenterPayProcessed::OnExecuted()
{
    //��ʱ�����͵�Ԫ�����ֵ����
    CRCClient* poClinet = gsapi::GetRCClientMgr()->FindCliSession(m_stCenterPayProcessed.dwSessionID);
    if(poClinet && 0 != m_stCenterPayProcessed.wErrCode)
    {
        poClinet->SendPayRet(m_stCenterPayProcessed.strOrderID, m_stCenterPayProcessed.wErrCode, NULL, m_stCenterPayProcessed.dwGold);
        return;
    }
	else if(NULL == poClinet)
	{
		SYS_CRITICAL(_SDT("[%s:%d]: SetMyPayProcessed find CRCClient[%d] OrderID[%s] failed!"), MSG_MARK, m_stCenterPayProcessed.dwSessionID, m_stCenterPayProcessed.strOrderID.c_str());
	}

    if( !m_bSuccess )
    {
        return;
    }


    CPlayer *pPlayer = CPlayerMgr::Instance()->FindPlayer( m_stCenterPayProcessed.dwPlayerID );
    if( NULL == pPlayer )
    {
        //�����Ҳ�����,��������,����������
        CGetPlayerDataMgr::Instance()->GetPlayerData( m_stCenterPayProcessed.dwSessionID , GET_PLAYERDATATYPE_EXCHANGE, m_stCenterPayProcessed.dwPlayerID,
                m_stCenterPayProcessed.dwPlayerID, m_stCenterPayProcessed.dwGold, m_stCenterPayProcessed.dwRMB, (char *)m_stCenterPayProcessed.strOrderID.c_str() );
        return;
    }

    //������ߣ�������Ԫ��
    pPlayer->AddGold( m_stCenterPayProcessed.dwGold, CRecordMgr::EGGT_ADDFLAGEXCHANGE, 0, 0, 0, 0, m_stCenterPayProcessed.strOrderID, m_stCenterPayProcessed.dwRMB);

    //����VIP�ȼ�
    //pPlayer->SetVipLevel(m_stCenterPayProcessed.byVipLevel);

    if (poClinet)
    {
        //ֱ�Ӹ�Ӧ��
        poClinet->SendPayRet(m_stCenterPayProcessed.strOrderID, m_stCenterPayProcessed.wErrCode, pPlayer, m_stCenterPayProcessed.dwGold);
    }


    //_SDTStrcpy( pPlayer->GetLastOrderID(), m_stCenterPayProcessed.strOrderID.c_str() );

    ////֪ͨ���
    //UINT32 dwMsgID = INVALID_MSGID;
    ////�������ݣ������֪ͨ��Һͳ�ֵ��Ҳ���ͬһ������ô��ô��Ҳû��ϵ����Ϊ�������ͬһ������ô�ͻ��˲���ʾ����ĳ�ֵ��������Կ�����㸳ֵ��
    //DT_PLAYER_BASE_DATA stDT_PLAYER_BASE_DATA = pPlayer->GetDT_PLAYER_BASE_DATA();
    //dwMsgID = CGTPktBuilder::Instance()->OnAppPaySuccess( stDT_PLAYER_BASE_DATA.byVipLevel, stDT_PLAYER_BASE_DATA.dwTotalAmount, stDT_PLAYER_BASE_DATA.qwGold, m_stCenterPayProcessed.dwGold, m_stCenterPayProcessed.strOrderID, stDT_PLAYER_BASE_DATA.dwID);
    //if( dwMsgID == INVALID_MSGID )
    //{
    //    return;
    //}

    //pPlayer->SendMsg( CGTPktBuilder::Instance()->GetPacketBuffer(), dwMsgID );
}

//��������
VOID CSetCenterPayProcessed::SetUserData(VOID* pUserData)
{
    m_stCenterPayProcessed = *(SCenterPayProcessed*)pUserData;
}

BOOL CSetCenterPayProcessed::SetPayProcessed(SGDP::ISDDBConnection* poDBConn)
{

    CHAR szSql[512] = {0};

    //sprintf( szSql, "call sp_AddRecharge('%s', %d, %d, %d, %d, '%s', %d)", m_stCenterPayProcessed.strOrderID.c_str(), m_stCenterPayProcessed.dwPlayerID, m_stCenterPayProcessed.dwGold, m_stCenterPayProcessed.dwRMB,
    //         m_stCenterPayProcessed.bySandBoxFlag, m_stCenterPayProcessed.strComment.c_str(), m_stCenterPayProcessed.dwPayID);

    sprintf( szSql, "call sp_AddRecharge('%s', %d, %d, %d, %d, '%s')", m_stCenterPayProcessed.strOrderID.c_str(), m_stCenterPayProcessed.dwPlayerID, m_stCenterPayProcessed.dwGold, m_stCenterPayProcessed.dwRMB,
             m_stCenterPayProcessed.bySandBoxFlag, m_stCenterPayProcessed.strComment.c_str());
	USR_INFO("[%s:%u] PaySql: %s", MSG_MARK, szSql);
    ISDDBRecordSet*pRecordSet = NULL;
    string strError;
    UINT32 dwErr = 0;
    INT32 nRet = poDBConn->ExecuteSqlRs(szSql, &pRecordSet, &dwErr, &strError);
    if(SDDB_HAS_RECORDSET == nRet && pRecordSet->GetRecord())
    {
        m_bSuccess = TRUE;
        m_stCenterPayProcessed.wErrCode = SGDP::SDAtou(pRecordSet->GetFieldValueByName("ErrCode"));
    }
    else
    {
        m_bSuccess = FALSE;
        m_stCenterPayProcessed.wErrCode = 99;
        SYS_CRITICAL(_SDT("[%s:%d]: exec sql failed! sql:%s, sqlerror:%s"), MSG_MARK, szSql, strError.c_str());
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    return TRUE;
}