#include "setapppayinfo.h"
#include <db/autosqlbuf.h>
#include "logic/http/httpmgr.h"
#include "common/server/base64.h"
#include "logic/record/recordmgr.h"
#include "logic/player/playermgr.h"
#include "net/gt/gtpktbuilder.h"
#include "logic/http/httpmgr.h"
#include "logic/http/apppayhttpcmd.h"
#include <logic/player/player.h>


CSetAppPayInfo::CSetAppPayInfo()
{
    m_bInsertSuccess = FALSE;
    m_bRepeat = FALSE;
    m_dwAlreadyPayGoldValue = 0;
}

CSetAppPayInfo::~CSetAppPayInfo()
{

}

VOID SDAPI CSetAppPayInfo::OnExecuteSql(SGDP::ISDDBConnection* poDBConn)
{
    SaveAppPayInfo( poDBConn );
}

VOID SDAPI CSetAppPayInfo::OnExecuted()
{
    //ִ����ϣ����ֵ�����������ҵ���Ϣ������ƻ���Ĵ���
    if( m_bInsertSuccess )
    {
        if( m_bRepeat )
        {
            //�����������ң���ֵ�Ѿ��ɹ����������Һ�ʵ�ʳ�ֵ����ҿ��ܲ���ͬһ���û���
            CPlayer *pNotifyPlayer = CPlayerMgr::Instance()->FindPlayer( m_stPayInfo.dwQueryPlayerID );

            if( pNotifyPlayer )
            {
                //����֪ͨ
                CPlayer *pPayPlayer = CPlayerMgr::Instance()->FindPlayer( m_stPayInfo.dwPlayerID );
                if( pPayPlayer )
                {
                    //������ڴ��У�ֱ�ӷ��͸��ͻ��ˣ����߿ͻ�����֤�Ѿ��ɹ�
                    DT_PLAYER_BASE_DATA baseData = pPayPlayer->GetDT_PLAYER_BASE_DATA();
                    UINT32 dwMsgID = CGTPktBuilder::Instance()->OnAppPaySuccess( baseData.byVipLevel, baseData.dwTotalAmount, baseData.qwGold, m_dwAlreadyPayGoldValue, m_stPayInfo.strOrderID, m_stPayInfo.dwPlayerID);
                    if( dwMsgID == INVALID_MSGID )
                    {
                        return;
                    }
                    pNotifyPlayer->SendMsg( CGTPktBuilder::Instance()->GetPacketBuffer(), dwMsgID );
                }
                else
                {
                    //��Ҳ����ڴ���
                    UINT32 dwMsgID = CGTPktBuilder::Instance()->OnAppPaySuccess( 0, 0, 0, m_dwAlreadyPayGoldValue, m_stPayInfo.strOrderID, m_stPayInfo.dwPlayerID);
                    if( dwMsgID == INVALID_MSGID )
                    {
                        return;
                    }
                    pNotifyPlayer->SendMsg( CGTPktBuilder::Instance()->GetPacketBuffer(), dwMsgID );
                }

            }
            else
            {
                //��֪ͨ��Ҳ����ڴ��У����һ��������Ϣ
                SYS_CRITICAL( _SDT("[%s:%d]Query player pay, but can't find query player:%u in memory"), MSG_MARK, m_stPayInfo.dwQueryPlayerID );
            }

            return;

        }
        else
        {
            //char szData[5120]={0};
            //CAppPayMgr::Instance()->Add( m_stPayInfo.dwPlayerID, Base64Encode( szData, sizeof(szData), (UINT8 *)m_stPayInfo.strReceipt.c_str(),
            //	m_stPayInfo.strReceipt.size() ), m_stPayInfo.dwQueryPlayerID, m_stPayInfo.strOrderID, 0 );
            //CHttpMgr::Instance()->AddPay( m_stPayInfo.dwPlayerID, m_stPayInfo.strReceipt, m_stPayInfo.dwQueryPlayerID, m_stPayInfo.strOrderID, 0 );

            SAppPayInfo stPayInfo;
            stPayInfo.dwPlayerID		=	m_stPayInfo.dwPlayerID;
            stPayInfo.dwQueryPlayerID	=	m_stPayInfo.dwQueryPlayerID;
            stPayInfo.strReceipt		=	m_stPayInfo.strReceipt;
            stPayInfo.strOrderID		=	m_stPayInfo.strOrderID;
            stPayInfo.nQueryCnt		=	1;
            stPayInfo.bBuyEnv			=	TRUE;
            CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_APP_PAY);
            if (NULL == poHttpCmd)
            {
                SYS_CRITICAL( _SDT("[%s:%d]Query player pay, but can't CreateCmd player:%u in memory"), MSG_MARK, m_stPayInfo.dwQueryPlayerID );
                return;
            }
            poHttpCmd->SetUserData(&stPayInfo, sizeof(SAppPayInfo), 0);
            poHttpCmd->Init();
            if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
            {
                CHttpMgr::Instance()->FreeCmd(poHttpCmd);
                SYS_CRITICAL( _SDT("[%s:%d]Query player pay, but can't AddCommand player:%u in memory"), MSG_MARK, m_stPayInfo.dwQueryPlayerID );
            }
        }
    }
    else
    {
        SYS_CRITICAL( _SDT( "set player:%u order id error,can't post data to appserver" ), m_stPayInfo.dwPlayerID );
        CPlayer *pPlayer = CPlayerMgr::Instance()->FindPlayer( m_stPayInfo.dwQueryPlayerID );
        if( NULL == pPlayer )
        {
            //��֪ͨ��Ҳ����ߣ���֪ͨ
            USR_INFO( _SDT("[%s:%d]Query player pay, but can't find query player:%u in memory"), MSG_MARK, m_stPayInfo.dwQueryPlayerID );
            return;
        }

        UINT16 wMsgID = CGTPktBuilder::Instance()->OnAppIDCheckError( ERR_CHECK_APPSTORE_ORDER::ID_SERVER_INNER_ERROR, m_stPayInfo.dwQueryPlayerID, m_stPayInfo.strOrderID);
        if( wMsgID == INVALID_MSGID )
        {
            return;
        }
        pPlayer->SendMsg(CGTPktBuilder::Instance()->GetPacketBuffer(), wMsgID);
    }
}

BOOL CSetAppPayInfo::SaveAppPayInfo(SGDP::ISDDBConnection* poDBConn)
{
    CAutoSqlBuf oAutoSqlBuf;
    CHAR* pszSql = oAutoSqlBuf.GetSqlBuf();

    if((NULL == pszSql))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: GetSQLMemory is NULL"), MSG_MARK);
        return FALSE;
    }

    //���ж������ݿ����Ƿ��Ѿ����ڣ�����������ж��Ƿ񷴸�����
    sprintf( pszSql, "select * from %s where OrderID='%s'", m_stPayInfo.strTableName.c_str(), m_stPayInfo.strOrderID.c_str() );
    ISDDBRecordSet*pRecordSet = NULL;
    string strError;
    INT32 nRet = poDBConn->ExecuteSqlRs(pszSql, &pRecordSet, NULL, &strError);

    if(nRet < 0)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: exec sql failed! player[%d], error:%s"), MSG_MARK, m_stPayInfo.dwPlayerID, strError.c_str());
        return FALSE;
    }

    //������������Ѿ������ݿ�
    if( (SDDB_HAS_RECORDSET == nRet) && (pRecordSet->GetRecord()) )
    {
        BOOL bProcess = BOOL( SDAtou( pRecordSet->GetFieldValueByName( "IsProcess" ) ) );
        if( bProcess )
        {
            //�����Ѿ���������ϣ��ͻ���Ϊ�ظ����󣬴�ʱֻ�跢�͸��ͻ��˳ɹ�
            m_bRepeat = TRUE;
            m_bInsertSuccess = TRUE;
            m_dwAlreadyPayGoldValue = SDAtou( pRecordSet->GetFieldValueByName( "Amount" ) ) / 10; //��ת��ΪԪ��
        }
        else
        {
            //����δ��������ϣ��߶���������ϳɹ�������
            m_bInsertSuccess = TRUE;
        }

        pRecordSet->Release();
        pRecordSet = NULL;
        return TRUE;
    }

    if( pRecordSet )
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    {
        CAutoSqlBuf oAutoSqlBuf2;
        CHAR* pszSql2 = oAutoSqlBuf2.GetSqlBuf();

        sprintf( pszSql2, "insert into %s( OrderID, DeviceID, UserID, ZoneID, Source, Amount, RMB, PlayerID, DateCreate, IsProcess, PlayerLevel ) values "
                 "('%s', '%s', %u, %u, '%s',0, 0, %u, now(), 0, %d )",
                 m_stPayInfo.strTableName.c_str(),
                 m_stPayInfo.strOrderID.c_str(),
                 m_stPayInfo.strDeviceID.c_str(),
                 m_stPayInfo.dwUserID,
                 m_stPayInfo.dwZoneID,
                 m_stPayInfo.strSource.c_str(),
                 m_stPayInfo.dwPlayerID,
                 m_stPayInfo.dwPlayerLevel);

        ISDDBRecordSet*pRecordSet2 = NULL;
        string strError;
        INT32 nRet = poDBConn->ExecuteSqlRs(pszSql2, &pRecordSet2, NULL, &strError);
        if(NULL != pRecordSet2)
        {
            pRecordSet2->Release();
            pRecordSet2 = NULL;
            SYS_CRITICAL(_SDT("[%s: %d]: exec sql failed! player[%d], error:%s"), MSG_MARK, m_stPayInfo.dwPlayerID, strError.c_str());
            return FALSE;
        }
        if(nRet < 0)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: exec sql failed! player[%d], error:%s"), MSG_MARK, m_stPayInfo.dwPlayerID, strError.c_str());
            return FALSE;
        }

        m_bInsertSuccess = TRUE;
    }
    return TRUE;
}

VOID CSetAppPayInfo::SetUserData(VOID* pUserData)
{
    m_stPayInfo = *( (SPayInfo*)pUserData );
}


