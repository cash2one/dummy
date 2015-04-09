

#include "apppayhttpcmd.h"
#include <sdutil.h>
#include <json/json.h>
#include "common/server/utility.h"
#include "common/server/ngstring.h"
#include <framework/gsapi.h>
#include "common/client/errdef.h"
#include "common/server/base64.h"
#include "db/setapppayprocessed.h"
#include "framework/gsconfig.h"
#include "net/gt/gtpktbuilder.h"
#include "logic/vip/vippropmgr.h"
#include "httpmgr.h"
#include <common/client/commondef.h>
#include <logic/player/player.h>
#include <logic/player/playermgr.h>

void trimString(std::string & str)
{
    string::size_type locs = str.find_first_of("\"");
    if( locs == string::npos )
        return;
    string::size_type loce = str.find_last_of("\"");
    if( loce == string::npos )
        return;
    if (locs == loce)
        return;
    str = str.substr(locs + 1, loce - locs - 1);
    return;
}


#define APPLE_ENVIRONMENT			"environment"
#define APPLE_SANDBOX				"SANDBOX"
#define APPLE_BUY_HOST          	"https://buy.itunes.apple.com/verifyReceipt"
#define APPLE_SANDBOX_HOST         "https://sandbox.itunes.apple.com/verifyReceipt"
#define APPLE_BID					"com.737.jiongxiyou"


CAppPayHttpCMD::CAppPayHttpCMD()
{

}

CAppPayHttpCMD::~CAppPayHttpCMD()
{

}


BOOL CAppPayHttpCMD::Init()
{
    const string &strReceipt = m_stAppPayInfo.strReceipt;

    USR_INFO( _SDT( "[%s: %d]:Add Curl Req src, PlayerID[%u], QueryPlayerID[%u], OrderID[%s], Receipt[%s]!" ), MSG_MARK,
              m_stAppPayInfo.dwPlayerID, m_stAppPayInfo.dwQueryPlayerID, m_stAppPayInfo.strOrderID.c_str(), strReceipt.c_str());

    char szData[5014] = {0};
    Base64Encode( szData, sizeof(szData), (UINT8 *)strReceipt.c_str(), strReceipt.size());
    m_strfields = string("{\"receipt-data\":\"") + szData + "\"}";
    if (m_stAppPayInfo.bBuyEnv)
    {
        curl_easy_setopt(m_pEasyHandle, CURLOPT_URL, APPLE_BUY_HOST);
    }
    else
    {
        curl_easy_setopt(m_pEasyHandle, CURLOPT_URL, APPLE_SANDBOX_HOST);
    }

    curl_easy_setopt(m_pEasyHandle, CURLOPT_ERRORBUFFER, m_szErrorBuff);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_POST, 1 );
    curl_easy_setopt(m_pEasyHandle, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_POSTFIELDS, m_strfields.c_str());
    return TRUE;
}

BOOL CAppPayHttpCMD::OnExecuted()
{
    if (FALSE == m_bError)
    {
		SYS_CRITICAL(_SDT("[%s: %d]: app pay error:%s!!"), MSG_MARK, m_szErrorBuff);
        SendErrorResult(m_stAppPayInfo.dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
    }
    else
    {
        ProcessPayResult();
    }
	return TRUE;
}

VOID CAppPayHttpCMD::SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID)
{
    m_dwTransID = dwTransID;
    m_stAppPayInfo = *((SAppPayInfo*)pUserData);
}

VOID CAppPayHttpCMD::ProcessPayResult()
{
    const UINT32 &dwPlayerID = m_stAppPayInfo.dwPlayerID;
    const string &strOrderID = m_stAppPayInfo.strOrderID;
    const UINT32 &dwQueryPlayerID = m_stAppPayInfo.dwQueryPlayerID;

    USR_INFO( _SDT( "app store ck playerid:%u, ret:%s" ), dwPlayerID, m_strResult.c_str());
    Json::Value root;
    Json::Reader reader;
    if( !reader.parse( m_strResult, root ) )
    {
        SYS_CRITICAL( _SDT( "json parse error, result:%s" ), m_strResult.c_str() );
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //������ݸ��������Ϊ���Ϊ������ֹ����
    if (!root.isObject())
    {
        SYS_CRITICAL( _SDT( "json size error, result:%s" ), m_strResult.c_str() );
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //�������ص�״̬��
    INT32 nStatus = 0;
    if (root["status"].isInt())
    {
        nStatus = root["status"].asInt();
    }
    else
    {
        SYS_CRITICAL( _SDT( "json parse status error, result:%s" ), m_strResult.c_str() );
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //�����֤��ͨ������ֱ�ӷ��ش���
    if(nStatus > 0)
    {
        SYS_CRITICAL( "app orderid:%s pay playerid:%u query playerid:%u, error code:%d", strOrderID.c_str(), dwPlayerID, dwQueryPlayerID, nStatus);
        //����Ƿ��Ѿ����Թ�
        if( m_stAppPayInfo.nQueryCnt > 1 )
        {
            //�Ѿ����Թ��ط����ش�����
            switch (nStatus)
            {
            case 21000:
            case 21002:
            case 21003:
            case 21004:
            case 21006:
            case 21007:
            case 21008:
                SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_ORDER_ID_ERROR, m_stAppPayInfo.strOrderID );
                break;
            case 21005:
                SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
                break;
            default:
                break;
            }
            return;
        }

        switch (nStatus)
        {
        case 21000:
        case 21002:
        case 21003:
        case 21004:
        case 21005:
        case 21006:
            Try( m_stAppPayInfo.dwPlayerID, m_stAppPayInfo.strReceipt, m_stAppPayInfo.dwQueryPlayerID, m_stAppPayInfo.strOrderID, m_stAppPayInfo.nQueryCnt, m_stAppPayInfo.bBuyEnv);
            break;
        case 21007:
        case 21008:
            Try( m_stAppPayInfo.dwPlayerID, m_stAppPayInfo.strReceipt, m_stAppPayInfo.dwQueryPlayerID, m_stAppPayInfo.strOrderID, m_stAppPayInfo.nQueryCnt, !m_stAppPayInfo.bBuyEnv);
            break;
        default:
            break;
        }
        return;
    }

    //��ȡreceipt �ṹ
    Json::Value receipt;
    if(root["receipt"].isObject())
    {
        receipt = root["receipt"];
    }
    else
    {
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //��ȡ��ƷID
    string strProductID = "";
    if (receipt["product_id"].isString())
    {
        strProductID = receipt["product_id"].asString();
    }
    else
    {
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //������
    SBuyGoldProp buyInfo;
    if( !CVipPropMgr::Instance()->GetBuyPropByProductID(AUTH_TYPE_MAXNET, strProductID, buyInfo ) )
    {
        SYS_CRITICAL( _SDT( "[%s: %d]:GetBuyPropByProductID:%s failed" ), MSG_MARK, strProductID.c_str() );
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //��ȡ������
    string strTransactionId = "";
    if (receipt["transaction_id"].isString())
    {
        strTransactionId = receipt["transaction_id"].asCString();
    }
    else
    {
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }
    //�Ƚ϶������Ƿ�һ��
    if (strTransactionId != m_stAppPayInfo.strOrderID)
    {
        SYS_CRITICAL( _SDT( "[%s: %d]:TransactionId NOt Match:%s failed" ), MSG_MARK, strTransactionId.c_str() );
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }

    //��ȡBid
    string strBid = "";
    if (receipt["bid"].isString())
    {
        strBid = receipt["bid"].asCString();
    }
    else
    {
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_PROCESS_ERROR_WITH_APPLE, m_stAppPayInfo.strOrderID );
        return;
    }
    //�Ƚ�BID�Ƿ�һ��
    if (strBid != APPLE_BID)
    {
        SYS_CRITICAL( _SDT( "[%s: %d]:bid NOt Match:%s failed" ), MSG_MARK, APPLE_BID );
        SendErrorResult( dwQueryPlayerID, ERR_CHECK_APPSTORE_ORDER::ID_ORDER_ID_ERROR, m_stAppPayInfo.strOrderID );
        return;
    }

    //�����ֵ���ݵ����ݿ�,���ô���ɹ�,���ݿⱣ����֮�󣬲��������ҵ�Ԫ�����������Ϳ��Ա�������ظ���ֵ��BUG
    CBaseDBCMD *pCmd = gsapi::GetDBMgr()->CreateCmd( EDBCT_SETPAYPPROCESSED );
    if(NULL == pCmd)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CreateCmd failed!"), MSG_MARK);
        return;
    }

    SAppPayProcessed processedInfo;
    processedInfo.dwRMB			= buyInfo.wRMB * 100; //���ݿ��Ľ�λΪԪ������ұ�ĵ�λΪ�֡�
    processedInfo.dwGold			= buyInfo.dwGold;
    processedInfo.dwPlayerID		= dwPlayerID;
    processedInfo.strOrderID		= strOrderID;
    processedInfo.dwQueryPlayer	= dwQueryPlayerID;
    processedInfo.bBuyEnv			= m_stAppPayInfo.bBuyEnv;
    processedInfo.strTableName		= CGSConfig::Instance()->GetAppPayTableName();

    pCmd->SetUserData( &processedInfo );
    gsapi::GetDBMgr()->AddPayCommand(pCmd);
}

VOID CAppPayHttpCMD::SendErrorResult( INT32 dwPlayerID, INT32 nErrorCode, string strOrderID)
{
    CPlayer *pPlayer = CPlayerMgr::Instance()->FindPlayer( dwPlayerID );
    if( NULL == pPlayer )
    {
        //��֪ͨ��Ҳ����ߣ���֪ͨ
        USR_INFO( _SDT("[%s:%d]Query player pay, but can't find query player:%u in memory"), MSG_MARK, dwPlayerID );
        return;
    }

    UINT16 wMsgID = CGTPktBuilder::Instance()->OnAppIDCheckError( nErrorCode, dwPlayerID, strOrderID);
    if( wMsgID == INVALID_MSGID )
    {
        return;
    }

    pPlayer->SendMsg(CGTPktBuilder::Instance()->GetPacketBuffer(), wMsgID);
}

void CAppPayHttpCMD::Try( UINT32 dwPlayerID, string strReceipt, UINT32 dwQueryPlayerID, string strOrderID, INT32 nQueryCnt, BOOL bBuyEnv)
{
    SAppPayInfo Info;
    Info.dwPlayerID		=	m_stAppPayInfo.dwPlayerID;
    Info.dwQueryPlayerID	=	m_stAppPayInfo.dwQueryPlayerID;
    Info.strReceipt		=	m_stAppPayInfo.strReceipt;
    Info.strOrderID		=	m_stAppPayInfo.strOrderID;
    Info.nQueryCnt		=	nQueryCnt + 1;
    Info.bBuyEnv			=	bBuyEnv;
    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_APP_PAY);
    if (NULL == poHttpCmd)
    {
        SYS_CRITICAL( _SDT("[%s:%d]Query player pay, but can't CreateCmd player:%u in memory"), MSG_MARK, m_stAppPayInfo.dwQueryPlayerID );
        return;
    }
    poHttpCmd->SetUserData(&Info, sizeof(SAppPayInfo), 0);
    poHttpCmd->Init();
    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        SYS_CRITICAL( _SDT("[%s:%d]Query player pay, but can't AddCommand player:%u in memory"), MSG_MARK, m_stAppPayInfo.dwQueryPlayerID );
    }
}
