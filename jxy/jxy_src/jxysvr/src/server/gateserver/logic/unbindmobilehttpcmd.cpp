

#include "unbindmobilehttpcmd.h"
#include <sdutil.h>
#include <json/json.h>
#include "common/server/utility.h"
#include "common/server/ngstring.h"
#include "framework/gtclient.h"
#include "framework/gtapplication.h"
#include "net/cli/clipktbuilder.h"
#include "common/client/errdef.h"
#include "noticemgr.h"




CUnBindMobileHttpCMD::CUnBindMobileHttpCMD()
{
    m_strUrl = ((CGTApplication*)SDGetApp())->GetGTConfig()->GetUnBindMobileUrl();
}

CUnBindMobileHttpCMD::~CUnBindMobileHttpCMD()
{

}

BOOL  CUnBindMobileHttpCMD::Init()
{
    CNGString strTemp;
    char *efc = NULL;
    m_strfields.append("_ch=");
    strTemp = AUTH_TYPE_MAXNET;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&userid=");
    strTemp = stUnBindInfo.dwUserID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    //��ʱ·�������ǩ��
    string	strTempUrl = m_strUrl;
    UINT8	abyDigest[16] = {0};
    string	strInput = m_strfields;
    strInput.append(CENTER_SIGN);
    SDMD5(abyDigest, (UINT8*)strInput.c_str(), strInput.length());
    CHAR szTemp[32] = {0};
    CHAR szHexDigest[256] = {0};
    for (UINT8 byIdx = 0; byIdx < 16; byIdx++)
    {
        sprintf(szTemp, "%02x", (UINT8)abyDigest[byIdx]);
        strcat(szHexDigest, szTemp);
    }
    strTempUrl.append("?_sig=");
    strTemp = szHexDigest;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    strTempUrl.append(efc);
    curl_free(efc);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_URL, strTempUrl.c_str());
    curl_easy_setopt(m_pEasyHandle, CURLOPT_ERRORBUFFER, m_szErrorBuff);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_POST, 1 );
	curl_easy_setopt(m_pEasyHandle, CURLOPT_TIMEOUT, 2);
    curl_easy_setopt(m_pEasyHandle, CURLOPT_POSTFIELDS, m_strfields.c_str());
    return TRUE;
}

BOOL CUnBindMobileHttpCMD::OnExecuted()
{
    if (FALSE == m_bError)
    {
        USR_INFO( _SDT( "UserID:%u url error, msg:%s" ), stUnBindInfo.dwUserID, m_szErrorBuff );
        OnUnBindMobileAck( m_dwTransID, ERR_COMMON::ID_OTHER_ERR);
    }
    else
    {
        ProcessResult();
    }
    return TRUE;
}

VOID CUnBindMobileHttpCMD::SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID)
{
    m_dwTransID = dwTransID;
    stUnBindInfo = *((SUnBindInfo*)pUserData);
}


VOID CUnBindMobileHttpCMD::ProcessResult()
{
	USR_INFO( _SDT( "ack:%s" ), SDUTF82Local(m_strResult.c_str()).c_str());

    Json::Value root;
    Json::Reader reader;
    if( !reader.parse( m_strResult, root ) )
    {
        SYS_CRITICAL( _SDT( "json parse error, result:%s,msg:%s" ), SDUTF82Local(m_strResult.c_str()).c_str(),m_szErrorBuff );
        OnUnBindMobileAck( m_dwTransID, ERR_COMMON::ID_OTHER_ERR);
        return;
    }

    //������ݸ��������Ϊ���Ϊ������ֹ����
    if (!root.isObject())
    {
        SYS_CRITICAL( _SDT( "json size error, result:%s,msg:%s" ), SDUTF82Local(m_strResult.c_str()).c_str(),m_szErrorBuff );
        OnUnBindMobileAck( m_dwTransID, ERR_COMMON::ID_OTHER_ERR);
        return;
    }

    //�������ص�״̬��
    INT16 wErrCode = 0;
    if (root["errcode"].isInt())
    {
        wErrCode = root["errcode"].asInt();
    }
    else
    {
        SYS_CRITICAL( _SDT( "json parse error, result:%s,msg:%s" ), SDUTF82Local(m_strResult.c_str()).c_str(),m_szErrorBuff );
        OnUnBindMobileAck( m_dwTransID, ERR_COMMON::ID_OTHER_ERR);
        return;
    }

    INT16 wCountDown = 0;
    if (root["datas"].isObject())
    {
        Json::Value datas = root["datas"];

        if (datas["countdown"].isInt())
        {
            wCountDown = datas["countdown"].asInt();
        }        
    }
    else
    {
        SYS_CRITICAL( _SDT( "json parse error, result:%s,msg:%s" ), SDUTF82Local(m_strResult.c_str()).c_str(),m_szErrorBuff );
        OnUnBindMobileAck( m_dwTransID, ERR_COMMON::ID_OTHER_ERR);
        return;
    }

    OnUnBindMobileAck(m_dwTransID, wErrCode, wCountDown);
}




BOOL CUnBindMobileHttpCMD::OnUnBindMobileAck (UINT32 dwTransID, UINT16 wErrCode)
{
    //�ҵ�client
    CGTClient* poCliSession = ((CGTApplication*)SDGetApp())->GetClientMgr()->FindCliSession(dwTransID);
    if (NULL == poCliSession)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    UINT16 wMsgID = CCliPktBuilder::Instance()->UnBindMobileAck(wErrCode);

    //���͵��ͻ���
    poCliSession->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());

    return FALSE;
}


BOOL CUnBindMobileHttpCMD::OnUnBindMobileAck( UINT32 dwTransID, UINT16 wErrCode, UINT16 wCountDown)
{
    //�ҵ�client
    CGTClient* poCliSession = ((CGTApplication*)SDGetApp())->GetClientMgr()->FindCliSession(dwTransID);
    if (NULL == poCliSession)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    };

    UINT16 wMsgID = CCliPktBuilder::Instance()->UnBindMobileAck(wErrCode,wCountDown);

    //���͵��ͻ���
    poCliSession->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());

    return FALSE;
}



