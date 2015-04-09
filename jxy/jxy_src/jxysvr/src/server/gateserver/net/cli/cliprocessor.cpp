#include "cliprocessor.h"
#include "sdutil.h"
#include "framework/gtapplication.h"
#include "clipktbuilder.h"
#include "net/gs/gspktbuilder.h"
#include <common/client/errdef.h>
#include <common/server/utility.h>
#include <logic/httpmgr.h>
#include "logic/loginexhttpcmd.h"
#include "logic/registerhttpcmd.h"
#include "logic/logouthttpcmd.h"
#include "logic/changepwdhttpcmd.h"
#include "logic/noticemgr.h"
#include "logic/bindmobilehttpcmd.h"
#include "logic/unbindmobilehttpcmd.h"
#include "logic/bindcheckvercode.h"
#include "logic/getuserexpandhttpcmd.h"
#include "logic/unbindcheckvercode.h"
CCliProcessor::CCliProcessor()
{
    Init();
}

CCliProcessor::~CCliProcessor()
{
}

BOOL CCliProcessor::Init()
{
    RegisterCommand(CLIGS_ENTERGS_REQ,				CCliProcessor::OnEnterGsReq);
    RegisterCommand(CLILS_REGISTER_REQ,				CCliProcessor::OnRegisterReq);
    RegisterCommand(CLILS_LOGIN_EX_REQ,				CCliProcessor::OnLoginExReq);
    RegisterCommand(CLILS_BIND_REQ,					CCliProcessor::OnBindReq);
    RegisterCommand(CLILS_UNBIND_REQ,				CCliProcessor::OnUnBindReq);
    RegisterCommand(CLILS_LOGOUT_REQ,				CCliProcessor::OnLogoutReq);
    RegisterCommand(CLILS_CHANGE_PWD_REQ,			CCliProcessor::OnChangePwdReq);
    RegisterCommand(CLILS_BIND_MOBILE_REQ,			CCliProcessor::OnBindMobileReq);
    RegisterCommand(CLILS_BIND_CHECK_VER_CODE_REQ,	CCliProcessor::OnBindCheckVerCodeReq);
    RegisterCommand(CLILS_UNBIND_MOBILE_REQ,			CCliProcessor::OnUnBindMobileReq);
    RegisterCommand(CLILS_UNBIND_CHECK_VER_CODE_REQ,	CCliProcessor::OnUnBindCheckVerCodeReq);
    RegisterCommand(CLILS_GET_USER_EXPAND_REQ,		CCliProcessor::OnGetUserExpandReq);
    return TRUE;
}

CSDProtocol* CCliProcessor::GetProtocol()
{
    return CProtoCliGT::Instance();
}


BOOL CCliProcessor::OnEnterGsReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    CUser* poUser = poGTClient->GetUser();
    if((NULL == poUser) || (CLIENT_STATE_AUTHED < poGTClient->GetState())) //δ��֤���ܽ�����Ϸ
    {
        USR_INFO(_SDT("[%s:%d]: enterGs failed, state[%d]!"), MSG_MARK, poGTClient->GetState());
        UINT16 wMsgID = CCliPktBuilder::Instance()->EnteGSAck(ERR_ENTER_GS::ID_INVALID_STATE);
        poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
        return FALSE;//������ת����GS
    }

    PKT_CLIGS_ENTERGS_REQ* pstReq = (PKT_CLIGS_ENTERGS_REQ*)pszBody;
    if((0 != SDStrcmp(pstReq->aszDeviceID, poUser->GetDeviceID())) ||
            (0 != SDStrcmp(pstReq->aszNotifyID, poUser->GetNotifyID())) ||
            (0 != SDStrcmp(pstReq->aszUserName, poUser->GetUserName())) ||
            (pstReq->dwPlayerID != poUser->GetPlayerID()) ||
            (pstReq->wCareerID != poUser->GetCareerID()))
    {
        UINT16 wMsgID = CCliPktBuilder::Instance()->EnteGSAck(ERR_ENTER_GS::ID_UNMATCH_PARAM);
        poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
        return FALSE;//������ת����GS
    }

    SDPipeMsgHeader* pPipeHeader = (SDPipeMsgHeader*)pHeader;
    pPipeHeader->dwTransID = SGDP::SDNtohl(pPipeHeader->dwTransID);
    pPipeHeader->wMsgID = SGDP::SDNtohs(pPipeHeader->wMsgID);
    PKT_CLIGS_ENTERGS_REQ* pstNtf = (PKT_CLIGS_ENTERGS_REQ*)((CHAR*)pHeader + sizeof(SDPipeMsgHeader) );
    pstNtf->wZoneID = SGDP::SDNtohs(poUser->GetZoneID());

    //ת����GS
    CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetGSServer();
    if (poSDPipeChannel)
    {
        UINT32 dwMsgID = CGSPktBuilder::Instance()->EnterGSReq(poUser->GetUserName(), poUser->GetDeviceID(), poUser->GetNotifyID(), poUser->GetZoneID(), poUser->GetOriginalZoneID(), poUser->GetUserID(),
                         poUser->GetPlayerID(), poUser->GetCareerID(), poUser->GetRemoteIP(), pstReq->dwCliVer, poUser->GetAuthType(), poUser->GetDaiChong());
        //����
        if (FALSE == poSDPipeChannel->SendMsg(poUser->GetUserSessionID(), dwMsgID, CGSPktBuilder::Instance()->GetPacketBuffer()))
        {
            DBG_INFO(_SDT("[%s:%d]: send packet failed"), MSG_MARK);
            return FALSE;
        }

        //poSDPipeChannel->Send((CHAR*)pHeader, dwLen + sizeof(SDPipeMsgHeader));
    }

    return FALSE; //�����ٴ�ת��

}


BOOL CCliProcessor::OnRegisterReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{

    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    PKT_CLILS_REGISTER_REQ* pstReq = (PKT_CLILS_REGISTER_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }


    CUser *poUser = poGTClient->GetUser();
    if (NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    pstReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_REGISTER);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    SResgisterInfo stRegisterInfo;
    stRegisterInfo.strDeviceid = poUser->GetDeviceID();
    stRegisterInfo.strUserName = pstReq->aszUserName;
    stRegisterInfo.strUserPwd = pstReq->aszUserPwd;
    stRegisterInfo.byAuthType = poUser->GetAuthType() == 0 ? AUTH_TYPE_MAXNET :  poUser->GetAuthType();
    stRegisterInfo.dwPlayerID = poUser->GetPlayerID();
    stRegisterInfo.dwUserID = poUser->GetUserID();
    poHttpCmd->SetUserData(&stRegisterInfo, sizeof(SResgisterInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();


    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }
    return TRUE;
}

BOOL CCliProcessor::OnLoginExReq(VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{

    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }


    PKT_CLILS_LOGIN_EX_REQ* pstReq = (PKT_CLILS_LOGIN_EX_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGINEX);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: CreateCmd failed"), MSG_MARK);
        return FALSE;
    }


    SLoginInfoEx stLoginInfo;
    stLoginInfo.Init();
    memcpy(&stLoginInfo.stReq, pstReq, sizeof(PKT_CLILS_LOGIN_EX_REQ));
    stLoginInfo.strIp = poGTClient->GetRemoteIPStr();
    poHttpCmd->SetUserData((void*)&stLoginInfo, sizeof(SLoginInfoEx), poGTClient->GetCliSessionID());
    poHttpCmd->Init();


    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {
        DBG_INFO(_SDT("[%s:%d]: Add Command failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }
    return FALSE;
}




//�����û�����Ϣ
BOOL	CCliProcessor::OnBindReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{

    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }


    PKT_CLILS_LOGIN_EX_REQ* pstReq = (PKT_CLILS_LOGIN_EX_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGIN);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    return TRUE;
}


//�����û�����Ϣ
BOOL	CCliProcessor::OnUnBindReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if(NULL == poGTClient)
    {
        return FALSE;
    }

    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //if (NULL == poSDPipeChannel || NULL == poGTClient)
    //{
    //    //���ش�����Ϣ
    //    PKT_CLILS_UNBIND_ACK stAck;
    //    SET_OTHER_ERR(stAck.wErrCode);
    //    memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_ACK));
    //    poGTClient->SendMsg(CLILS_UNBIND_ACK, (CHAR*)&stAck);
    //    return FALSE;
    //}

    //PKT_CLILS_BIND_REQ* pstReq = (PKT_CLILS_BIND_REQ*)pszBody;
    //if(poGTClient->GetUser()->GetUserSessionID() != pstReq->dwPlayerID)
    //{
    //    //���ش�����Ϣ
    //    PKT_CLILS_UNBIND_ACK stAck;
    //    stAck.wErrCode = ERR_UNBIND::ID_PLAYERID_IS_COMPETENCE;
    //    memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_ACK));
    //    poGTClient->SendMsg(CLILS_UNBIND_ACK, (CHAR*)&stAck);
    //    return FALSE;
    //}
    return TRUE;
}

//����ǳ���Ϣ
BOOL CCliProcessor::OnLogoutReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if(NULL == poGTClient)
    {
        return FALSE;
    }

    PKT_CLILS_LOGOUT_REQ * pReq = (PKT_CLILS_LOGOUT_REQ*)pszBody;
    if ( sizeof(PKT_CLILS_LOGOUT_REQ) != dwLen )
        return FALSE;


    CUser *poUser = poGTClient->GetUser();
    if (NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    pReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGOUT);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SLogoutInfo stLogoutInfo;

    stLogoutInfo.byAuthType = pReq->byAuthType == 0 ?  AUTH_TYPE_MAXNET : pReq->byAuthType;
    stLogoutInfo.strDeviceID = poUser->GetDeviceID();
    stLogoutInfo.dwUserID = poUser->GetUserID();
    stLogoutInfo.dwPlayerID = poUser->GetPlayerID();

    poHttpCmd->SetUserData(&stLogoutInfo, sizeof(SLogoutInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();


    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }

    return TRUE;
    ////���������
    //memset(pReq, 0x00, sizeof(PKT_CLILS_LOGOUT_REQ));

    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)
    ////�������
    //pReq->byAuthType	=	poUser->GetAuthType();
    //pReq->dwUserID	=	poUser->GetUserID();
    //SDStrcat(pReq->aszDeviceID, poUser->GetDeviceID());
    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
    ////����Ϸ��������������֪ͨ
    //poGTClient->SendCliDownRpt();

    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_LOGOUT_REQ, (CHAR*)pReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_LOGOUT_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_ACK));
    //poGTClient->SendMsg(CLILS_LOGOUT_ACK, (CHAR*)&stAck);
    return FALSE;
}

//�����޸���Ϣ
BOOL	CCliProcessor::OnChangePwdReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if(NULL == poGTClient)
    {
        return FALSE;
    }

    PKT_CLILS_CHANGE_PWD_REQ * pReq = (PKT_CLILS_CHANGE_PWD_REQ*)pszBody;
    if ( sizeof(PKT_CLILS_CHANGE_PWD_REQ) != dwLen )
        return FALSE;


    CUser *poUser = poGTClient->GetUser();
    if (NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    pReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_CHANGEPWD);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SChangePwdInfo stChangePwdInfo;

    stChangePwdInfo.strDeviceid = poUser->GetDeviceID();
    stChangePwdInfo.dwUserID = pReq->dwUserID;
    TCHAR aszPwd[USERNAME_LEN] = {0};
    SDStrncpy(aszPwd, (TCHAR*)pReq->abyUserPwd, pReq->byPwdLen);
    stChangePwdInfo.strOldPwd = aszPwd;
    SDStrncpy(aszPwd, (TCHAR*)pReq->abyNewUserPwd, pReq->byNewPwdLen);
    stChangePwdInfo.strNewPwd = aszPwd;
    stChangePwdInfo.dwPlayerID = poUser->GetPlayerID();


    poHttpCmd->SetUserData(&stChangePwdInfo, sizeof(SChangePwdInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();


    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }

    return TRUE;

    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)



    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)

    ////����û�ID�����ṹ���С�
    //PKT_GTLS_CHANGE_PWD_REQ stReq;
    //memset(&stReq, 0x00, sizeof(PKT_GTLS_CHANGE_PWD_REQ));
    //stReq.byPwdLen	=	pReq->byPwdLen;
    //memcpy(stReq.abyUserPwd, pReq->abyUserPwd, pReq->byPwdLen);
    //stReq.byNewPwdLen	=	pReq->byNewPwdLen;
    //memcpy(stReq.abyNewUserPwd, pReq->abyNewUserPwd, pReq->byNewPwdLen);
    //stReq.dwUserID	=	poUser->GetUserID();
    //SDStrcat(stReq.aszDeviceID, poUser->GetDeviceID());

    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), GTLS_CHANGE_PWD_REQ, (CHAR*)&stReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_CHANGE_PWD_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_CHANGE_PWD_ACK));
    //poGTClient->SendMsg(CLILS_CHANGE_PWD_ACK, (CHAR*)&stAck);
    return FALSE;
}


//�����޸���Ϣ
BOOL	CCliProcessor::OnBindMobileReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;

    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    PKT_CLILS_BIND_MOBILE_REQ* pstReq = (PKT_CLILS_BIND_MOBILE_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    CUser *poUser = poGTClient->GetUser();
    if(NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: GetUser() failed"), MSG_MARK);
        return FALSE;
    }
    pstReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_BIND_MOBILE);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SBindInfo stBindInfo;
    stBindInfo.dwUserID = pstReq->dwUserID;
    memcpy(stBindInfo.abyMObile, pstReq->abyMObile, MAX_MOBILE_LENGTH);

    poHttpCmd->SetUserData((void*)&stBindInfo, sizeof(SBindInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();

    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }
    return TRUE;
    //PKT_CLILS_BIND_MOBILE_REQ * pReq = (PKT_CLILS_BIND_MOBILE_REQ*)pszBody;
    //if ( sizeof(PKT_CLILS_BIND_MOBILE_REQ) != dwLen )
    //    return FALSE;

    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)



    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
    //pReq->dwUserID	=	poUser->GetUserID();
    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_BIND_MOBILE_REQ, (CHAR*)pReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_BIND_MOBILE_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_BIND_MOBILE_ACK));
    //poGTClient->SendMsg(CLILS_BIND_MOBILE_ACK, (CHAR*)&stAck);
    //return FALSE;
}

//�����޸���Ϣ
BOOL	CCliProcessor::OnBindCheckVerCodeReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;


    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }


    PKT_CLILS_BIND_CHECK_VER_CODE_REQ* pstReq = (PKT_CLILS_BIND_CHECK_VER_CODE_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    CUser *poUser = poGTClient->GetUser();
    if(NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: GetUser() failed"), MSG_MARK);
        return FALSE;
    }
    pstReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_BIND_CHECK_VER_CODE);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SBindCheckVerCodeInfo stBindCheckCodeInfo;
    stBindCheckCodeInfo.dwUserID = pstReq->dwUserID;
    memcpy(stBindCheckCodeInfo.abyVerCode, pstReq->abyVerCode, MAX_MOBILE_LENGTH);

    poHttpCmd->SetUserData((void*)&stBindCheckCodeInfo, sizeof(SBindCheckVerCodeInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();

    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }
    return TRUE;
    //CGTClient* poGTClient = (CGTClient*)poReceiver;
    //if(NULL == poGTClient)
    //{
    //    return FALSE;
    //}

    //PKT_CLILS_BIND_CHECK_VER_CODE_REQ * pReq = (PKT_CLILS_BIND_CHECK_VER_CODE_REQ*)pszBody;
    //if ( sizeof(PKT_CLILS_BIND_CHECK_VER_CODE_REQ) != dwLen )
    //    return FALSE;

    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)

    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)

    //pReq->dwUserID	=	poUser->GetUserID();
    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_BIND_CHECK_VER_CODE_REQ, (CHAR*)pReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_BIND_CHECK_VER_CODE_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_BIND_CHECK_VER_CODE_ACK));
    //poGTClient->SendMsg(CLILS_BIND_CHECK_VER_CODE_REQ, (CHAR*)&stAck);


    //return FALSE;

}

//�����޸���Ϣ
BOOL	CCliProcessor::OnUnBindMobileReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;


    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    PKT_CLILS_UNBIND_MOBILE_REQ* pstReq = (PKT_CLILS_UNBIND_MOBILE_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    CUser *poUser = poGTClient->GetUser();
    if(NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: GetUser() failed"), MSG_MARK);
        return FALSE;
    }
    pstReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_UNBIND_MOBILE);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SUnBindInfo stUnBindInfo;
    stUnBindInfo.dwUserID = pstReq->dwUserID;

    poHttpCmd->SetUserData((void*)&stUnBindInfo, sizeof(SUnBindInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();

    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }
    return TRUE;
    //CGTClient* poGTClient = (CGTClient*)poReceiver;
    //if(NULL == poGTClient)
    //{
    //    return FALSE;
    //}

    //PKT_CLILS_UNBIND_MOBILE_REQ * pReq = (PKT_CLILS_UNBIND_MOBILE_REQ*)pszBody;
    //if ( sizeof(PKT_CLILS_UNBIND_MOBILE_REQ) != dwLen )
    //    return FALSE;

    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)



    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
    //pReq->dwUserID	=	poUser->GetUserID();
    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_UNBIND_MOBILE_REQ, (CHAR*)pReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_UNBIND_MOBILE_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_MOBILE_ACK));
    //poGTClient->SendMsg(CLILS_UNBIND_MOBILE_ACK, (CHAR*)&stAck);
    return FALSE;
}

//�����޸���Ϣ
BOOL	CCliProcessor::OnUnBindCheckVerCodeReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{

    if(NULL == poReceiver)
    {
        return FALSE;
    }
    CGTClient* poGTClient = (CGTClient*)poReceiver;


    if (NULL == poGTClient)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }


    PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ* pstReq = (PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ*)pszBody;
    if (NULL == pstReq)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    CUser *poUser = poGTClient->GetUser();
    if(NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: GetUser() failed"), MSG_MARK);
        return FALSE;
    }
    pstReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_UNBIND_CHECK_VER_CODE);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SUnBindCheckVerCodeInfo stUnBindCheckCodeInfo;
    stUnBindCheckCodeInfo.dwUserID = pstReq->dwUserID;
    memcpy(stUnBindCheckCodeInfo.abyVerCode, pstReq->abyVerCode, MAX_MOBILE_LENGTH);

    poHttpCmd->SetUserData((void*)&stUnBindCheckCodeInfo, sizeof(SUnBindCheckVerCodeInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();

    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }
    return TRUE;

    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)

    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)

    //pReq->dwUserID	=	poUser->GetUserID();
    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_UNBIND_CHECK_VER_CODE_REQ, (CHAR*)pReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_UNBIND_CHECK_VER_CODE_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_CHECK_VER_CODE_ACK));
    //poGTClient->SendMsg(CLILS_UNBIND_CHECK_VER_CODE_ACK, (CHAR*)&stAck);
    return FALSE;

}

//�����޸���Ϣ
BOOL	CCliProcessor::OnGetUserExpandReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    CGTClient* poGTClient = (CGTClient*)poReceiver;
    if(NULL == poGTClient)
    {
        return FALSE;
    }

    PKT_CLILS_GET_USER_EXPAND_REQ * pReq = (PKT_CLILS_GET_USER_EXPAND_REQ*)pszBody;
    if ( sizeof(PKT_CLILS_GET_USER_EXPAND_REQ) != dwLen )
        return FALSE;


    CUser *poUser = poGTClient->GetUser();
    if (NULL == poUser)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    pReq->dwUserID = poUser->GetUserID();

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_GET_USER_EXPAND);
    if(NULL == poHttpCmd)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }

    SGetUserExpandInfo stInfo = {0};
    stInfo.dwUserID = pReq->dwUserID;
    stInfo.dwPlayerID = poUser->GetPlayerID();
    poHttpCmd->SetUserData(&stInfo, sizeof(SGetUserExpandInfo), poGTClient->GetCliSessionID());
    poHttpCmd->Init();


    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {

        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        return FALSE;
    }

    return TRUE;
    //CC_LOOP_DO
    ////��ȡ�������
    //CUser *poUser = poGTClient->GetUser();
    //CC_LOOP_BREAK(NULL == poUser)

    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
    //CC_LOOP_BREAK (NULL == poSDPipeChannel)

    //pReq->dwUserID	=	poUser->GetUserID();
    ////����
    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_GET_USER_EXPAND_REQ, (CHAR*)pReq))
    //return FALSE;
    //CC_LOOP_WHILE(0)

    ////���ش�����Ϣ
    //PKT_CLILS_GET_USER_EXPAND_ACK stAck;
    //SET_OTHER_ERR(stAck.wErrCode);
    //memset(&stAck, 0x00, sizeof(PKT_CLILS_GET_USER_EXPAND_ACK));
    //poGTClient->SendMsg(CLILS_GET_USER_EXPAND_ACK, (CHAR*)&stAck);
    return FALSE;
}

//
//#include "cliprocessor.h"
//#include "sdutil.h"
//#include "framework/gtapplication.h"
//#include "clipktbuilder.h"
//#include "net/gs/gspktbuilder.h"
//#include <common/client/errdef.h>
//#include <common/server/utility.h>
//#include <logic/httpmgr.h>
//#include "logic/loginexhttpcmd.h"
//#include "logic/registerhttpcmd.h"
//#include "logic/logouthttpcmd.h"
//#include "logic/changepwdhttpcmd.h"
//#include "logic/loginhttpcmd.h"
//#include "logic/noticemgr.h"
//
//
//CCliProcessor::CCliProcessor()
//{
//    Init();
//}
//
//CCliProcessor::~CCliProcessor()
//{
//}
//
//BOOL CCliProcessor::Init()
//{
//    RegisterCommand(CLIGS_ENTERGS_REQ,				CCliProcessor::OnEnterGsReq);
//    RegisterCommand(CLILS_REGISTER_REQ,				CCliProcessor::OnRegisterReq);
//    RegisterCommand(CLILS_LOGIN_REQ,				CCliProcessor::OnLoginReq);
//    RegisterCommand(CLILS_LOGIN_EX_REQ,				CCliProcessor::OnLoginExReq);
//    RegisterCommand(CLILS_BIND_REQ,					CCliProcessor::OnBindReq);
//    RegisterCommand(CLILS_UNBIND_REQ,				CCliProcessor::OnUnBindReq);
//    RegisterCommand(CLILS_LOGOUT_REQ,				CCliProcessor::OnLogoutReq);
//    RegisterCommand(CLILS_CHANGE_PWD_REQ,			CCliProcessor::OnChangePwdReq);
//    RegisterCommand(CLILS_BIND_MOBILE_REQ,			CCliProcessor::OnBindMobileReq);
//    RegisterCommand(CLILS_BIND_CHECK_VER_CODE_REQ,	CCliProcessor::OnBindCheckVerCodeReq);
//    RegisterCommand(CLILS_UNBIND_MOBILE_REQ,			CCliProcessor::OnUnBindMobileReq);
//    RegisterCommand(CLILS_UNBIND_CHECK_VER_CODE_REQ,	CCliProcessor::OnUnBindCheckVerCodeReq);
//    RegisterCommand(CLILS_GET_USER_EXPAND_REQ,		CCliProcessor::OnGetUserExpandReq);
//    return TRUE;
//}
//
//CSDProtocol* CCliProcessor::GetProtocol()
//{
//    return CProtoCliGT::Instance();
//}
//
//
//BOOL CCliProcessor::OnEnterGsReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    if(NULL == poReceiver)
//    {
//        return FALSE;
//    }
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    CUser* poUser = poGTClient->GetUser();
//    if((NULL == poUser) || (CLIENT_STATE_AUTHED < poGTClient->GetState())) //δ��֤���ܽ�����Ϸ
//    {
//        USR_INFO(_SDT("[%s:%d]: enterGs failed, state[%d]!"), MSG_MARK, poGTClient->GetState());
//        UINT16 wMsgID = CCliPktBuilder::Instance()->EnteGSAck(ERR_ENTER_GS::ID_INVALID_STATE);
//        poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//        return FALSE;//������ת����GS
//    }
//
//    PKT_CLIGS_ENTERGS_REQ* pstReq = (PKT_CLIGS_ENTERGS_REQ*)pszBody;
//    if((0 != SDStrcmp(pstReq->aszDeviceID, poUser->GetDeviceID())) ||
//            (0 != SDStrcmp(pstReq->aszNotifyID, poUser->GetNotifyID())) ||
//            (0 != SDStrcmp(pstReq->aszUserName, poUser->GetUserName())) ||
//            (pstReq->dwPlayerID != poUser->GetPlayerID()) ||
//            (pstReq->wCareerID != poUser->GetCareerID()))
//    {
//        UINT16 wMsgID = CCliPktBuilder::Instance()->EnteGSAck(ERR_ENTER_GS::ID_UNMATCH_PARAM);
//        poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//        return FALSE;//������ת����GS
//    }
//
//    SDPipeMsgHeader* pPipeHeader = (SDPipeMsgHeader*)pHeader;
//    pPipeHeader->dwTransID = SGDP::SDNtohl(pPipeHeader->dwTransID);
//    pPipeHeader->wMsgID = SGDP::SDNtohs(pPipeHeader->wMsgID);
//    PKT_CLIGS_ENTERGS_REQ* pstNtf = (PKT_CLIGS_ENTERGS_REQ*)((CHAR*)pHeader + sizeof(SDPipeMsgHeader) );
//    pstNtf->wZoneID = SGDP::SDNtohs(poUser->GetZoneID());
//
//    //ת����GS
//    CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetGSServer();
//    if (poSDPipeChannel)
//    {
//        UINT32 dwMsgID = CGSPktBuilder::Instance()->EnterGSReq(poUser->GetUserName(), poUser->GetDeviceID(), poUser->GetNotifyID(), poUser->GetZoneID(), poUser->GetUserID(),
//                         poUser->GetPlayerID(), poUser->GetCareerID(), poUser->GetRemoteIP(), pstReq->dwCliVer, poUser->GetAuthType());
//        //����
//        if (FALSE == poSDPipeChannel->SendMsg(poUser->GetUserSessionID(), dwMsgID, CGSPktBuilder::Instance()->GetPacketBuffer()))
//        {
//            DBG_INFO(_SDT("[%s:%d]: send packet failed"), MSG_MARK);
//            return FALSE;
//        }
//
//        //poSDPipeChannel->Send((CHAR*)pHeader, dwLen + sizeof(SDPipeMsgHeader));
//    }
//
//    return FALSE; //�����ٴ�ת��
//
//}
//
//
//BOOL CCliProcessor::OnRegisterReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//	if(NULL == poReceiver)
//	{
//		return FALSE;
//	}
//	CGTClient* poGTClient = (CGTClient*)poReceiver;
//	if (NULL == poGTClient)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	PKT_CLILS_REGISTER_REQ* pstReq = (PKT_CLILS_REGISTER_REQ*)pszBody;
//	if (NULL == pstReq)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	CUser *poUser = poGTClient->GetUser();
//	pstReq->dwUserID = poUser->GetUserID();
//
//	CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_REGISTER);
//	if(NULL == poHttpCmd)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//	SResgisterInfo stRegisterInfo = {0};
//	stRegisterInfo.strDeviceid = pstReq->aszDeviceID;
//	stRegisterInfo.strUserName = pstReq->aszUserName;
//	stRegisterInfo.strUserPwd = pstReq->aszUserPwd;
//	stRegisterInfo.byAuthType = poUser->GetAuthType();
//	stRegisterInfo.dwPlayerID = poUser->GetPlayerID();
//	poHttpCmd->SetUserData(&stRegisterInfo, sizeof(SResgisterInfo), poGTClient->GetCliSessionID());
//	poHttpCmd->Init();
//
//
//	if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
//	{
//
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		CHttpMgr::Instance()->FreeCmd(poHttpCmd);
//		return FALSE;
//	}
//	return TRUE;
//}
//
//
//BOOL CCliProcessor::OnLoginReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    if(NULL == poReceiver)
//    {
//        return FALSE;
//    }
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    PKT_CLILS_LOGIN_REQ* pstReq = (PKT_CLILS_LOGIN_REQ*)pszBody;
//
//
//	CUser *poUser = poGTClient->GetUser();
//
//	CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGIN);
//	if(NULL == poHttpCmd)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	SLoginInfo stLoginInfo = {0};
//	stLoginInfo.strDeviceID = pstReq->aszDeviceID;
//	stLoginInfo.strUserName = pstReq->aszUserName;
//	stLoginInfo.dwPlayerID = poUser->GetPlayerID();
//	stLoginInfo.byAuthType = pstReq->byAuthType;
//	stLoginInfo.byAuthMethod = pstReq->byAuthMethod;
//	stLoginInfo.dwCliVersion = pstReq->dwCliVersion;
//	stLoginInfo.dwSerialNumber = pstReq->dwSerialNumber;
//	stLoginInfo.strNotifyID = pstReq->aszNotifyID;
//	stLoginInfo.wCareerID = pstReq->wCareerID;
//	stLoginInfo.wZoneID = pstReq->wZoneID;
//	TCHAR aszUserPwd[41] = {0};
//	SDStrncpy(aszUserPwd, (TCHAR*)pstReq->abyUserPwd, pstReq->byPwdLen);
//	stLoginInfo.strUserPwd = aszUserPwd;
//	stLoginInfo.byIsBind = 0;
//	poHttpCmd->SetUserData(&stLoginInfo, sizeof(SLoginInfo), poGTClient->GetCliSessionID());
//	poHttpCmd->Init();
//
//	if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
//	{
//
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		CHttpMgr::Instance()->FreeCmd(poHttpCmd);
//		return FALSE;
//	}
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //if (NULL == poSDPipeChannel)
//    //{
//    //    //���ش�����Ϣ
//    //   UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_LS_SERVER_NOT_STARTUP, pstReq);
//    //    poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //    return FALSE;
//    //}
//
//    //if(CLIENT_DIRECTION_LS != poGTClient->GetTransferTarget())
//    //{
//    //    //���ش�����Ϣ
//    //    UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_INVALID_STATE, pstReq);
//    //    poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //    return FALSE;
//    //}
//
//    ////��ֹios7�豸�ŵ�¼
//    //if (0 == SDStrcmp(pstReq->aszDeviceID, "f0f7faffe4e9eed3d8ddc2c7cc33363b20252a2f") ||
//    //        0 == SDStrcmp(pstReq->aszDeviceID, "f9f5f8f8b1edebd6ded8c1c3c531343c75212f2a") ||
//    //        0 == SDStrcmp(pstReq->aszDeviceID, "f9f5f8f8b1edead1dbd996cfc531343c75212e2d"))
//    //{
//    //    //���ش�����Ϣ
//    //    UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP, pstReq, TRUE);
//    //    poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //    return FALSE;
//    //}
//
//
//
//    //if(AUTH_TYPE_DEVECEID != pstReq->byAuthType)
//    //{
//    //    UINT8* pszEncryptBuff =  (UINT8*)(pstReq->abyUserPwd);
//    //    INT32 nEncryptBuffLen = pstReq->byPwdLen;
//    //    if(nEncryptBuffLen > (ENCRYPT_HEAD_LEN + ENCRYPT_TAIL_LEN))
//    //    {
//    //        if(!poGTClient->GetMGEncrypt().decryptionDatas(pszEncryptBuff, nEncryptBuffLen))
//    //        {
//    //            //���ش�����Ϣ
//    //            UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_INVALID_USER, pstReq);
//    //            poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //            return FALSE;
//    //        }
//
//    //        //////////////////////////////////////////////////////////////////////////
//    //        UINT32	dwLen = 0;
//    //        TCHAR	aszUserPwd[USERNAME_LEN] = {0};
//    //        dwLen	= nEncryptBuffLen - ENCRYPT_HEAD_LEN - ENCRYPT_TAIL_LEN;
//
//    //        SDStrncpy(aszUserPwd, (CHAR*)(pszEncryptBuff + ENCRYPT_HEAD_LEN),  dwLen);
//
//    //        pstReq->byPwdLen = dwLen;
//    //        memset(pstReq->abyUserPwd, 0x00, USERNAME_LEN);
//    //        memcpy(pstReq->abyUserPwd, aszUserPwd, dwLen);
//
//    //        //���ٽ��벻��֤���룬ֻ��֤�û��������Ƿ�һ��
//    //        if (1 == pstReq->byAuthMethod)
//    //        {
//    //            if(0 != SDStrcmp(pstReq->aszUserName, aszUserPwd))
//    //            {
//    //                //���ش�����Ϣ
//    //                UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_INVALID_USER, pstReq);
//    //                poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //                return FALSE;
//    //            }
//    //        }
//    //        else
//    //        {
//    //            //ͬ�����������������Ӧ���û�����������һ���ġ�
//    //            if (AUTH_TYPE_TONGBU == pstReq->byAuthType || AUTH_TYPE_91 == pstReq->byAuthType)
//    //            {
//    //                if(0 != SDStrcmp(pstReq->aszUserName, aszUserPwd))
//    //                {
//    //                    //���ش�����Ϣ
//    //                    UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_INVALID_USER, pstReq);
//    //                    poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //                    return FALSE;
//    //                }
//    //            }
//    //        }
//    //    }
//    //    else
//    //    {
//    //        //���ش�����Ϣ
//    //        UINT16 wMsgID = CCliPktBuilder::Instance()->LoginAck(ERR_LOGIN::ID_INVALID_USER, pstReq);
//    //        poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//    //        return FALSE;
//    //    }
//    //}
//
//    ////ת����LS
//    //if (poSDPipeChannel)
//    //{
//    //    PKT_GTLS_LOGIN_REQ stReq;
//    //    memcpy(&stReq, pstReq, sizeof(PKT_CLILS_LOGIN_REQ));
//    //    SDStrcat(stReq.aszIP, poGTClient->GetRemoteIPStr().c_str());
//
//    //    //����
//    //    if (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), GTLS_LOGIN_REQ, (CHAR*)&stReq))
//    //    {
//    //        DBG_INFO(_SDT("[%s:%d]: send packet failed"), MSG_MARK);
//    //        return FALSE;
//    //    }
//    //    return FALSE;
//    //}
//
//    return FALSE;
//}
//
//BOOL CCliProcessor::OnLoginExReq(VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//	if(NULL == poReceiver)
//	{
//		return FALSE;
//	}
//	CGTClient* poGTClient = (CGTClient*)poReceiver;
//	if (NULL == poGTClient)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	PKT_CLILS_LOGIN_EX_REQ* pstReq = (PKT_CLILS_LOGIN_EX_REQ*)pszBody;
//	if (NULL == pstReq)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//    //�����ID�Ƿ���ȷ
//    CSDServerID	oServerID(((CGTApplication*)SDGetApp())->GetLocalID());
//    if(pstReq->wZoneID != oServerID.GetAreaID())
//    {
//        //��ȡ������ֵֻ�����������
//        DT_NOTICE_DATA *poDT_NOTICE_DATA = CNoticeMgr::Instance()->GetDT_NOTICE_DATA(pstReq->byAuthType);
//        UINT16 wMsgID = CCliPktBuilder::Instance()->LoginExAck(ERR_LOGIN::ID_INVALID_ZONEID, poDT_NOTICE_DATA);
//        //���͵��ͻ���
//        poGTClient->SendMsg(wMsgID, CCliPktBuilder::Instance()->GetPacketBuffer());
//        SDSleep(0);
//        poGTClient->Disconnect();//�Ͽ�����
//
//        DBG_INFO(_SDT("[%s:%d]: INVALID ZONEID PlayerID:%d"), MSG_MARK, pstReq->dwPlayerID);
//        return FALSE;
//    }
//
//    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGIN);
//    if(NULL == poHttpCmd)
//    {
//        DBG_INFO(_SDT("[%s:%d]: CreateCmd failed"), MSG_MARK);
//        return FALSE;
//    }
//
//    SLoginInfoEx stLoginInfo;
//    memcpy(&stLoginInfo.stReq, pstReq, sizeof(SLoginInfo));
//    stLoginInfo.strIp = poGTClient->GetRemoteIPStr();
//    poHttpCmd->SetUserData((void*)&stLoginInfo, sizeof(SLoginInfo), poGTClient->GetCliSessionID());
//    poHttpCmd->Init();
//
//    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
//    {
//        DBG_INFO(_SDT("[%s:%d]: Add Command failed"), MSG_MARK);
//        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
//        return FALSE;
//    }
//    return FALSE;
//}
//
//
//
//
////�����û�����Ϣ
//BOOL	CCliProcessor::OnBindReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//	if(NULL == poReceiver)
//	{
//		return FALSE;
//	}
//	CGTClient* poGTClient = (CGTClient*)poReceiver;
//	if (NULL == poGTClient)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	PKT_CLILS_LOGIN_EX_REQ* pstReq = (PKT_CLILS_LOGIN_EX_REQ*)pszBody;
//	if (NULL == pstReq)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//	CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGIN);
//	if(NULL == poHttpCmd)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//    return TRUE;
//}
//
//
////�����û�����Ϣ
//BOOL	CCliProcessor::OnUnBindReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //if (NULL == poSDPipeChannel || NULL == poGTClient)
//    //{
//    //    //���ش�����Ϣ
//    //    PKT_CLILS_UNBIND_ACK stAck;
//    //    SET_OTHER_ERR(stAck.wErrCode);
//    //    memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_ACK));
//    //    poGTClient->SendMsg(CLILS_UNBIND_ACK, (CHAR*)&stAck);
//    //    return FALSE;
//    //}
//
//    //PKT_CLILS_BIND_REQ* pstReq = (PKT_CLILS_BIND_REQ*)pszBody;
//    //if(poGTClient->GetUser()->GetUserSessionID() != pstReq->dwPlayerID)
//    //{
//    //    //���ش�����Ϣ
//    //    PKT_CLILS_UNBIND_ACK stAck;
//    //    stAck.wErrCode = ERR_UNBIND::ID_PLAYERID_IS_COMPETENCE;
//    //    memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_ACK));
//    //    poGTClient->SendMsg(CLILS_UNBIND_ACK, (CHAR*)&stAck);
//    //    return FALSE;
//    //}
//    return TRUE;
//}
//
////����ǳ���Ϣ
//BOOL CCliProcessor::OnLogoutReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    PKT_CLILS_LOGOUT_REQ * pReq = (PKT_CLILS_LOGOUT_REQ*)pszBody;
//    if ( sizeof(PKT_CLILS_LOGOUT_REQ) != dwLen )
//        return FALSE;
//
//
//	CUser *poUser = poGTClient->GetUser();
//	pReq->dwUserID = poUser->GetUserID();
//
//	CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LOGOUT);
//	if(NULL == poHttpCmd)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	SLogoutInfo stLogoutInfo = {0};
//
//	stLogoutInfo.byAuthType = pReq->byAuthType;
//	stLogoutInfo.strDeviceID = pReq->aszDeviceID;
//	stLogoutInfo.dwUserID = pReq->dwUserID;
//	stLogoutInfo.dwPlayerID = poUser->GetPlayerID();
//
//	poHttpCmd->SetUserData(&stLogoutInfo, sizeof(SLogoutInfo), poGTClient->GetCliSessionID());
//	poHttpCmd->Init();
//
//
//	if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
//	{
//
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		CHttpMgr::Instance()->FreeCmd(poHttpCmd);
//		return FALSE;
//	}
//
//	return TRUE;
//    ////���������
//    //memset(pReq, 0x00, sizeof(PKT_CLILS_LOGOUT_REQ));
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//    ////�������
//    //pReq->byAuthType	=	poUser->GetAuthType();
//    //pReq->dwUserID	=	poUser->GetUserID();
//    //SDStrcat(pReq->aszDeviceID, poUser->GetDeviceID());
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//    ////����Ϸ��������������֪ͨ
//    //poGTClient->SendCliDownRpt();
//
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_LOGOUT_REQ, (CHAR*)pReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_LOGOUT_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_ACK));
//    //poGTClient->SendMsg(CLILS_LOGOUT_ACK, (CHAR*)&stAck);
//    return FALSE;
//}
//
////�����޸���Ϣ
//BOOL	CCliProcessor::OnChangePwdReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    PKT_CLILS_CHANGE_PWD_REQ * pReq = (PKT_CLILS_CHANGE_PWD_REQ*)pszBody;
//    if ( sizeof(PKT_CLILS_CHANGE_PWD_REQ) != dwLen )
//        return FALSE;
//
//
//	CUser *poUser = poGTClient->GetUser();
//	pReq->dwUserID = poUser->GetUserID();
//
//	CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_CHANGEPWD);
//	if(NULL == poHttpCmd)
//	{
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		return FALSE;
//	}
//
//	SChangePwdInfo stChangePwdInfo = {0};
//
//	stChangePwdInfo.strDeviceid = poUser->GetDeviceID();
//	stChangePwdInfo.dwUserID = pReq->dwUserID;
//	TCHAR aszPwd[USERNAME_LEN] = {0};
//	sprintf(aszPwd, "%u", pReq->abyUserPwd);
//	stChangePwdInfo.strOldPwd = aszPwd;
//	sprintf(aszPwd, "%u", pReq->abyNewUserPwd);
//	stChangePwdInfo.strNewPwd = aszPwd;
//	stChangePwdInfo.dwPlayerID = poUser->GetPlayerID();
//
//
//	poHttpCmd->SetUserData(&stChangePwdInfo, sizeof(SChangePwdInfo), poGTClient->GetCliSessionID());
//	poHttpCmd->Init();
//
//
//	if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
//	{
//
//		DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
//		CHttpMgr::Instance()->FreeCmd(poHttpCmd);
//		return FALSE;
//	}
//
//	return TRUE;
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//
//
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//
//    ////����û�ID�����ṹ���С�
//    //PKT_GTLS_CHANGE_PWD_REQ stReq;
//    //memset(&stReq, 0x00, sizeof(PKT_GTLS_CHANGE_PWD_REQ));
//    //stReq.byPwdLen	=	pReq->byPwdLen;
//    //memcpy(stReq.abyUserPwd, pReq->abyUserPwd, pReq->byPwdLen);
//    //stReq.byNewPwdLen	=	pReq->byNewPwdLen;
//    //memcpy(stReq.abyNewUserPwd, pReq->abyNewUserPwd, pReq->byNewPwdLen);
//    //stReq.dwUserID	=	poUser->GetUserID();
//    //SDStrcat(stReq.aszDeviceID, poUser->GetDeviceID());
//
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), GTLS_CHANGE_PWD_REQ, (CHAR*)&stReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_CHANGE_PWD_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_CHANGE_PWD_ACK));
//    //poGTClient->SendMsg(CLILS_CHANGE_PWD_ACK, (CHAR*)&stAck);
//    return FALSE;
//}
//
//
////�����޸���Ϣ
//BOOL	CCliProcessor::OnBindMobileReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    //PKT_CLILS_BIND_MOBILE_REQ * pReq = (PKT_CLILS_BIND_MOBILE_REQ*)pszBody;
//    //if ( sizeof(PKT_CLILS_BIND_MOBILE_REQ) != dwLen )
//    //    return FALSE;
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//
//
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//    //pReq->dwUserID	=	poUser->GetUserID();
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_BIND_MOBILE_REQ, (CHAR*)pReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_BIND_MOBILE_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_BIND_MOBILE_ACK));
//    //poGTClient->SendMsg(CLILS_BIND_MOBILE_ACK, (CHAR*)&stAck);
//    return FALSE;
//}
//
////�����޸���Ϣ
//BOOL	CCliProcessor::OnBindCheckVerCodeReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    PKT_CLILS_BIND_CHECK_VER_CODE_REQ * pReq = (PKT_CLILS_BIND_CHECK_VER_CODE_REQ*)pszBody;
//    if ( sizeof(PKT_CLILS_BIND_CHECK_VER_CODE_REQ) != dwLen )
//        return FALSE;
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//
//    //pReq->dwUserID	=	poUser->GetUserID();
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_BIND_CHECK_VER_CODE_REQ, (CHAR*)pReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_BIND_CHECK_VER_CODE_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_BIND_CHECK_VER_CODE_ACK));
//    //poGTClient->SendMsg(CLILS_BIND_CHECK_VER_CODE_REQ, (CHAR*)&stAck);
//    return FALSE;
//
//}
//
////�����޸���Ϣ
//BOOL	CCliProcessor::OnUnBindMobileReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    PKT_CLILS_UNBIND_MOBILE_REQ * pReq = (PKT_CLILS_UNBIND_MOBILE_REQ*)pszBody;
//    if ( sizeof(PKT_CLILS_UNBIND_MOBILE_REQ) != dwLen )
//        return FALSE;
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//
//
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//    //pReq->dwUserID	=	poUser->GetUserID();
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_UNBIND_MOBILE_REQ, (CHAR*)pReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_UNBIND_MOBILE_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_MOBILE_ACK));
//    //poGTClient->SendMsg(CLILS_UNBIND_MOBILE_ACK, (CHAR*)&stAck);
//    return FALSE;
//}
//
////�����޸���Ϣ
//BOOL	CCliProcessor::OnUnBindCheckVerCodeReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ * pReq = (PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ*)pszBody;
//    if ( sizeof(PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ) != dwLen )
//        return FALSE;
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//
//    //pReq->dwUserID	=	poUser->GetUserID();
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_UNBIND_CHECK_VER_CODE_REQ, (CHAR*)pReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_UNBIND_CHECK_VER_CODE_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_UNBIND_CHECK_VER_CODE_ACK));
//    //poGTClient->SendMsg(CLILS_UNBIND_CHECK_VER_CODE_ACK, (CHAR*)&stAck);
//    return FALSE;
//
//}
//
////�����޸���Ϣ
//BOOL	CCliProcessor::OnGetUserExpandReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
//{
//    CGTClient* poGTClient = (CGTClient*)poReceiver;
//    if(NULL == poGTClient)
//    {
//        return FALSE;
//    }
//
//    PKT_CLILS_GET_USER_EXPAND_REQ * pReq = (PKT_CLILS_GET_USER_EXPAND_REQ*)pszBody;
//    if ( sizeof(PKT_CLILS_GET_USER_EXPAND_REQ) != dwLen )
//        return FALSE;
//
//    //CC_LOOP_DO
//    ////��ȡ�������
//    //CUser *poUser = poGTClient->GetUser();
//    //CC_LOOP_BREAK(NULL == poUser)
//
//    //CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetLSServer();
//    //CC_LOOP_BREAK (NULL == poSDPipeChannel)
//
//    //pReq->dwUserID	=	poUser->GetUserID();
//    ////����
//    //CC_LOOP_BREAK (FALSE == poSDPipeChannel->SendMsg(poGTClient->GetCliSessionID(), CLILS_GET_USER_EXPAND_REQ, (CHAR*)pReq))
//    //return FALSE;
//    //CC_LOOP_WHILE(0)
//
//    ////���ش�����Ϣ
//    //PKT_CLILS_GET_USER_EXPAND_ACK stAck;
//    //SET_OTHER_ERR(stAck.wErrCode);
//    //memset(&stAck, 0x00, sizeof(PKT_CLILS_GET_USER_EXPAND_ACK));
//    //poGTClient->SendMsg(CLILS_GET_USER_EXPAND_ACK, (CHAR*)&stAck);
//    return FALSE;
//}
//
//
