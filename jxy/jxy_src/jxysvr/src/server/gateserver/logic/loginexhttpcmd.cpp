


#include <sdutil.h>
#include <json/json.h>
#include "common/server/utility.h"
#include "common/server/ngstring.h"
#include "framework/gtclient.h"
#include "framework/gtapplication.h"
#include "net/cli/clipktbuilder.h"
#include "common/client/errdef.h"
#include "noticemgr.h"
#include "loginexhttpcmd.h"
#include "common/server/utility.h"



CLoginExHttpCMD::CLoginExHttpCMD()
{
    memset(&stAck, 0x00, sizeof(stAck));
    m_wOriZoneID = 0;

    m_strUrl = ((CGTApplication*)SDGetApp())->GetGTConfig()->GetLoginExUrl();
}

CLoginExHttpCMD::~CLoginExHttpCMD()
{

}

BOOL  CLoginExHttpCMD::Init()
{
    CNGString strTemp;
    char *efc = NULL;
    m_strfields.append("cliversion=");
    strTemp = stLoginInfo.stReq.dwCliVersion;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&deviceid=");
    TCHAR aszDeviceID[DEVICEID_LEN + 1] = {0};
    SDStrncpy(aszDeviceID, stLoginInfo.stReq.aszDeviceID, DEVICEID_LEN);
    strTemp = aszDeviceID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&notifyid=");
    TCHAR aszNotifyID[NOTIFYID_LEN + 1] = {0};
    SDStrncpy(aszNotifyID, stLoginInfo.stReq.aszNotifyID, NOTIFYID_LEN);
    strTemp = aszNotifyID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&username=");
    TCHAR aszUserName[USERNAME_LEN + 1] = {0};
    SDStrncpy(aszUserName, stLoginInfo.stReq.aszUserName, USERNAME_LEN);
    strTemp = aszUserName;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&zoneid=");
    strTemp = stLoginInfo.stReq.wZoneID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);


    m_strfields.append("&userid=");
    strTemp = stLoginInfo.stReq.dwUserID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&playerid=");
    strTemp = stLoginInfo.stReq.dwPlayerID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&careerid=");
    strTemp = stLoginInfo.stReq.wCareerID;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&authtype=");
    strTemp = stLoginInfo.stReq.byAuthType;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&authkey=");
    TCHAR aszAuthKey[AUTH_KEY + 1] = {0};
    SDStrncpy(aszAuthKey, stLoginInfo.stReq.aszAuthKey, AUTH_KEY);
    strTemp = aszAuthKey;
    efc = curl_easy_escape(m_pEasyHandle, strTemp.c_str(), 0);
    m_strfields.append(efc);
    curl_free(efc);

    m_strfields.append("&ip=");
    strTemp = stLoginInfo.strIp;
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

BOOL CLoginExHttpCMD::OnExecuted()
{
    if (FALSE == m_bError)
    {
        USR_INFO( _SDT( "Player:%u url error, msg:%s" ), stLoginInfo.stReq.dwPlayerID, m_szErrorBuff );
        OnLoginExAck_Failed(ERR_LOGIN::ID_LOGIN_TIME_OUT );
    }
    else
    {
        ProcessResult();
    }
    return TRUE;
}

VOID CLoginExHttpCMD::SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID)
{
    m_dwTransID = dwTransID;
    stLoginInfo = *((SLoginInfoEx*)pUserData);
}


VOID CLoginExHttpCMD::ProcessResult()
{
    USR_INFO( _SDT( "ack:%s" ), SDUTF82Local(m_strResult.c_str()).c_str());

    CC_LOOP_DO
    Json::Value root;
    Json::Reader reader;
    if( !reader.parse( m_strResult, root ) )
    {
        break;
    }

    //������ݸ��������Ϊ���Ϊ������ֹ����
    if (!root.isObject())
    {
        break;
    }

    //�������ص�״̬��
    if (!root["errcode"].isInt())
    {
        break;
    }
    stAck.wErrCode = root["errcode"].asInt();
    if (!root["datas"].isObject())
    {
        break;
    }

    Json::Value datas = root["datas"];
    UINT32 dwUserID = 0;
    if (!datas["userid"].isInt())
    {
        break;
    }
    dwUserID = datas["userid"].asInt();

    Json::Value jsVersionInfo;
    if (!datas["versioninfo"].isObject())
    {
        break;
    }
    jsVersionInfo = datas["versioninfo"];
    if (!jsVersionInfo["versionid"].isInt())
    {
        break;
    }
    stAck.stVersionInfo.dwVersionID  = jsVersionInfo["versionid"].asInt();
    if (!jsVersionInfo["forceupdateflag"].isInt())
    {
        break;
    }
    stAck.stVersionInfo.byForceUpdateFlag  = jsVersionInfo["forceupdateflag"].asInt();
    if (!jsVersionInfo["updatecontent"].isString())
    {
        break;
    }
    SDStrncpy(stAck.stVersionInfo.aszUpdateContent, jsVersionInfo["updatecontent"].asCString(), MAX_CONTENT_SIZE);
    if (!jsVersionInfo["updateurl"].isString())
    {
        break;
    }
    SDStrncpy(stAck.stVersionInfo.aszUpdateURL, jsVersionInfo["updateurl"].asCString(), MAX_CONTENT_SIZE);
    //֪ͨ

    Json::Value jsNoticeInfo;
    if (!datas["noticeinfo"].isObject())
    {
        break;
    }
    jsNoticeInfo = datas["noticeinfo"];

    if (!jsNoticeInfo["noticeid"].isInt())
    {
        break;
    }
    stAck.stNoticeInfo.dwNoticeID  = jsVersionInfo["noticeid"].asInt();

    if (!jsNoticeInfo["forcepopflag"].isInt())
    {
        break;
    }
    stAck.stNoticeInfo.byForcePopFlag  = jsVersionInfo["forcepopflag"].asInt();
    if (!jsNoticeInfo["urlflag"].isInt())
    {
        break;
    }
    stAck.stNoticeInfo.byUrlFlag  = jsVersionInfo["urlflag"].asInt();
    if (!jsNoticeInfo["noticecontent"].isString())
    {
        break;
    }
    SDStrncpy(stAck.stNoticeInfo.aszNoticeContent, jsNoticeInfo["noticecontent"].asCString(), MAX_CONTENT_SIZE);
    ////////////////////////////////////////////////////////////////////////

    if (!datas["otherdeviceloginflag"].isInt())
    {
        break;
    }
    stAck.byOtherDeviceLoginFlag = datas["otherdeviceloginflag"].asInt();


    if (!datas["authtype"].isInt())
    {
        break;
    }
    stAck.byAuthType = datas["authtype"].asInt();


    if (!datas["deviceid"].isString())
    {
        break;
    }
    SDStrncpy((char*)stAck.aszDeviceID, datas["deviceid"].asCString(), DEVICEID_LEN);

    if (!datas["notifyid"].isString())
    {
        break;
    }
    SDStrncpy((char*)stAck.aszNotifyID, datas["notifyid"].asCString(), NOTIFYID_LEN);

    if (!datas["username"].isString())
    {
        break;
    }
    SDStrncpy((char*)stAck.aszUserName, datas["username"].asCString(), USERNAME_LEN);

    if (!datas["zoneid"].isInt())
    {
        break;
    }
    stAck.wZoneID = datas["zoneid"].asInt();

    if (!datas["oldzoneid"].isInt())
    {
        break;
    }
    m_wOriZoneID = datas["oldzoneid"].asInt();

    if (!datas["zonename"].isString())
    {
        break;
    }
    SDStrncpy(stAck.aszZoneName, datas["zonename"].asCString(), ZONENAME_LEN);

    if (!datas["playerid"].isInt())
    {
        break;
    }
    stAck.dwPlayerID = datas["playerid"].asInt();

    if (!datas["careerid"].isInt())
    {
        break;
    }
    stAck.wCareerID = datas["careerid"].asInt();

    if (datas["minresver"].isInt())
    {
        stAck.stExtFuncParamLst.astExtFuncParaInfo[0].dwParam3 = datas["minresver"].asInt();
    }
    stAck.stExtFuncParamLst.byFuncNum = 1;

	UINT8 byDaiChong = 0;
	if (datas["daichong"].isInt())
	{
		byDaiChong = datas["daichong"].asInt();
	}
	stAck.stExtFuncParamLst.byFuncNum = 1;


    OnLoginExAck_Success(dwUserID, byDaiChong);

    return;
    CC_LOOP_WHILE(0)
    SYS_CRITICAL( _SDT( "json parse error, result:%s" ), SDUTF82Local(m_strResult.c_str()).c_str() );
    OnLoginExAck_Failed( ERR_LOGIN::ID_LS_SERVER_NOT_STARTUP);
}

BOOL CLoginExHttpCMD::OnLoginExAck_Failed (UINT16 wErrCode)
{
    //�ҵ�client
    CGTClient* poCliSession = ((CGTApplication*)SDGetApp())->GetClientMgr()->FindCliSession(m_dwTransID);
    if (NULL == poCliSession)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    //��֤ʧ�ܣ�ֱ�ӷ���
    poCliSession->SetState(CLIENT_STATE_UNAUTHED);
    DBG_INFO(_SDT("[%s:%d]: Auth Failed"), MSG_MARK);

    stAck.wErrCode = wErrCode;

    GetPacketBuffer();
    //���͵��ͻ���
    poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);

    SDSleep(0);
    poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

    return FALSE;
}


BOOL	CLoginExHttpCMD::OnLoginExAck_Success(UINT32 dwUserID, UINT8 byDaiChong)
{
    //�ҵ�client
    CGTClient* poCliSession = ((CGTApplication*)SDGetApp())->GetClientMgr()->FindCliSession(m_dwTransID);
    if (NULL == poCliSession)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetGSServer();
    if ((NULL == poSDPipeChannel) && (ERR_LOGIN::ID_VERSION_NEED_UPDATE != stAck.wErrCode)) //���Ȱ汾ǿ�Ƹ���
    {
        poCliSession->SetState(CLIENT_STATE_UNAUTHED);
        DBG_INFO(_SDT("[%s:%d]: Auth Failed,  PlayerID[%d], UserID[%d], "), MSG_MARK, stAck.dwPlayerID, dwUserID);

        //���ش�����Ϣ
        stAck.wErrCode = ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP;
        GetPacketBuffer();
        //���͵��ͻ���
        poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);
        SDSleep(0);
        poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }

    //��֤ʧ�ܣ�ֱ�ӷ���
    if (SUCCESS != stAck.wErrCode)
    {
        poCliSession->SetState(CLIENT_STATE_UNAUTHED);
        DBG_INFO(_SDT("[%s:%d]: Auth Failed,  PlayerID[%d], UserID[%d], "), MSG_MARK, stAck.dwPlayerID, dwUserID);

        //���͵��ͻ���
        poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);

        SDSleep(0);
        poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }

    //����Ƿ�������
    if(CUserMgr::Instance()->BeKickOut(stAck.dwPlayerID))
    {

        poCliSession->SetState(CLIENT_STATE_UNAUTHED);
        DBG_INFO(_SDT("[%s:%d]: Kick out,  PlayerID[%d], UserID[%d]"), MSG_MARK, stAck.dwPlayerID, dwUserID);

        //���͵��ͻ���
        poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);

        SDSleep(0);
        poCliSession->Disconnect();//�Ͽ�����

        return FALSE;
    }

    //�����ID�Ƿ���ȷ
    CSDServerID	oServerID(((CGTApplication*)SDGetApp())->GetLocalID());
    if(stAck.wZoneID != oServerID.GetAreaID())
    {
        poCliSession->SetState(CLIENT_STATE_UNAUTHED);
        DBG_INFO(_SDT("[%s:%d]: Kick out,  PlayerID[%d], UserID[%d], "), MSG_MARK, stAck.dwPlayerID, dwUserID);

        //���ش�����Ϣ
        stAck.wErrCode = ERR_LOGIN::ID_INVALID_ZONEID;
        //���͵��ͻ���
        poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);

        SDSleep(0);
        poCliSession->Disconnect();//�Ͽ�����

        return FALSE;
    }

    //��¼�û�����
    CUser* poUser = CUserMgr::Instance()->CreateUser(stAck.aszUserName, stAck.aszDeviceID, stAck.aszNotifyID, stAck.wZoneID, m_wOriZoneID, dwUserID, stAck.dwPlayerID, stAck.wCareerID, stAck.byAuthType, poCliSession, byDaiChong);
    if(NULL == poUser)
    {
        poCliSession->SetState(CLIENT_STATE_UNAUTHED);

        //���ش�����Ϣ
        stAck.wErrCode = ERR_LOGIN::ID_SYSTEM_MAINTAIN;
        //���͵��ͻ���
        poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);

        //�쳣
        DBG_INFO(_SDT("[%s:%d]: CreateUser failed! UserID[%d], UserName[%s], DeviceID[%s]"), MSG_MARK, stAck.dwPlayerID, stAck.aszUserName, stAck.aszDeviceID);
        SDSleep(0);
        poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����
        return FALSE;
    }

    poCliSession->SetUser(poUser);

    //��¼��֤�ɹ�
    poCliSession->SetState(CLIENT_STATE_AUTHED);

    //���͵��ͻ���
    poCliSession->SendMsg(CLILS_LOGIN_EX_ACK, (CHAR*)&stAck);

    return FALSE;
}

void CLoginExHttpCMD::GetPacketBuffer()
{
    //��ȡ������ֵֻ�����������
    DT_NOTICE_DATA *poDT_NOTICE_DATA = CNoticeMgr::Instance()->GetDT_NOTICE_DATA(stLoginInfo.stReq.byAuthType);

    if ((ERR_LOGIN::ID_SYSTEM_MAINTAIN == stAck.wErrCode
            || ERR_LOGIN::ID_LS_SERVER_NOT_STARTUP == stAck.wErrCode
            || ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP == stAck.wErrCode)
            && NULL != poDT_NOTICE_DATA)
    {
        memcpy(&stAck.stNoticeInfo, poDT_NOTICE_DATA, sizeof(DT_NOTICE_DATA));
    }
}



