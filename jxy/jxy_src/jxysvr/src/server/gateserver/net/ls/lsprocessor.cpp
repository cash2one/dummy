#include "framework/gtapplication.h"

#include "net/ls/lsprocessor.h"
#include "net/cli/clipktbuilder.h"
#include "net/gs/gspktbuilder.h"
#include "net/ls/lspktbuilder.h"
#include "logic/usermgr.h"
#include <common/server/utility.h>
#include <common/client/errdef.h>


CLSProcessor::CLSProcessor()
{
    Init();
}

CLSProcessor::~CLSProcessor()
{
}

BOOL CLSProcessor::Init()
{
    RegisterCommand(GTLS_LOGIN_ACK,        CLSProcessor::OnLoginAck);
    RegisterCommand(GTLS_LOGIN_EX_ACK,		CLSProcessor::OnLoginExAck);
    return TRUE;
}


//����CLILS_LOGIN_ACK��Ϣ
BOOL CLSProcessor::OnLoginAck(VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    //CAutoCycle oAutoCycle("OnLoginAck");

    SDPipeMsgHeader* pPipeHeader = (SDPipeMsgHeader*)pHeader;
    CGTApplication* poGTApplication = (CGTApplication*)SDGetApp();
    //�ҵ�client
    CGTClient* poCliSession = poGTApplication->GetClientMgr()->FindCliSession(pPipeHeader->dwTransID);
    if (NULL == poCliSession)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    PKT_GTLS_LOGIN_ACK* pstAck = (PKT_GTLS_LOGIN_ACK*)pszBody;



    CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetGSServer();
    if ((NULL == poSDPipeChannel) && (ERR_LOGIN::ID_VERSION_NEED_UPDATE != pstAck->wErrCode)) //���Ȱ汾ǿ�Ƹ���
    {
        //���ش�����Ϣ
        pstAck->wErrCode = ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP;

        //���͵��ͻ���
        UINT16 wMsgID =  CLSPktBuilder::Instance()->LoginAck(*pstAck, FALSE);

        poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());
		
		SDSleep(0);
		poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }

    //��֤ʧ�ܣ�ֱ�ӷ���
    if (SUCCESS != pstAck->wErrCode)
    {
        poCliSession->SetState(CLIENT_STATE_UNAUTHED);        

        DBG_INFO(_SDT("[%s:%d]: Auth Failed,  PlayerID[%d], UserID[%d], "), MSG_MARK, pstAck->dwPlayerID, pstAck->dwUserID);

        UINT16 wMsgID = 0;
        if (pstAck->wErrCode == ERR_LOGIN::ID_SYSTEM_MAINTAIN)
        {
            pstAck->wErrCode = ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP;
            wMsgID =  CLSPktBuilder::Instance()->LoginAck(*pstAck, FALSE);
        }
        else
        {
            wMsgID =  CLSPktBuilder::Instance()->LoginAck(*pstAck, TRUE);
        }

        //���͵��ͻ���
        poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());

		SDSleep(0);
		poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }

	//����Ƿ�������
	if(CUserMgr::Instance()->BeKickOut(pstAck->dwPlayerID))
	{
		pstAck->wErrCode = ERR_LOGIN::ID_FORBID_LOGIN;
		UINT16 wMsgID =  CLSPktBuilder::Instance()->LoginAck(*pstAck, TRUE);
		//���͵��ͻ���
		poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());

		SDSleep(0);
		poCliSession->Disconnect();//�Ͽ�����

		return FALSE;
	}

    poCliSession->SetState(CLIENT_STATE_AUTHED);

    //��¼�û�����
    CUser* poUser = CUserMgr::Instance()->CreateUser(pstAck->aszUserName, pstAck->aszDeviceID, pstAck->aszNotifyID, pstAck->wZoneID, 0, pstAck->dwUserID, pstAck->dwPlayerID, pstAck->wCareerID, pstAck->byAuthType, poCliSession, 0);
    if(NULL == poUser)
    {
        //�쳣
        DBG_INFO(_SDT("[%s:%d]: CreateUser failed! UserID[%d], UserName[%s], DeviceID[%s]"), MSG_MARK, pstAck->dwPlayerID, pstAck->aszUserName, pstAck->aszDeviceID);
		SDSleep(0);
		poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����
        return FALSE;
    }
    poCliSession->SetUser(poUser);

    //���͵��ͻ���
    UINT16 wMsgID =  CLSPktBuilder::Instance()->LoginAck(*pstAck, TRUE);
    poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());

    return FALSE; //�ѷ��ͣ�����ת��
}


//����CLILS_LOGIN_EX_ACK��Ϣ
BOOL CLSProcessor::OnLoginExAck(VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen)
{
    //CAutoCycle oAutoCycle("OnLoginAck");

    SDPipeMsgHeader* pPipeHeader = (SDPipeMsgHeader*)pHeader;
    CGTApplication* poGTApplication = (CGTApplication*)SDGetApp();
    //�ҵ�client
    CGTClient* poCliSession = poGTApplication->GetClientMgr()->FindCliSession(pPipeHeader->dwTransID);
    if (NULL == poCliSession)
    {
        DBG_INFO(_SDT("[%s:%d]: Find client session failed"), MSG_MARK);
        return FALSE;
    }
    PKT_GTLS_LOGIN_EX_ACK* pstAck = (PKT_GTLS_LOGIN_EX_ACK*)pszBody;



    CSDPipeChannel* poSDPipeChannel = ((CGTApplication*)SDGetApp())->GetGSServer();
    if ((NULL == poSDPipeChannel) && (ERR_LOGIN::ID_VERSION_NEED_UPDATE != pstAck->wErrCode)) //���Ȱ汾ǿ�Ƹ���
    {
        //���ش�����Ϣ
        pstAck->wErrCode = ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP;

        //���͵��ͻ���
        UINT16 wMsgID =  CLSPktBuilder::Instance()->LoginExAck(*pstAck, FALSE);

        poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());

		SDSleep(0);
		poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }

    //��֤ʧ�ܣ�ֱ�ӷ���
    if (SUCCESS != pstAck->wErrCode)
    {
        poCliSession->SetState(CLIENT_STATE_UNAUTHED);
 
        DBG_INFO(_SDT("[%s:%d]: Auth Failed,  PlayerID[%d], UserID[%d], "), MSG_MARK, pstAck->dwPlayerID, pstAck->dwUserID);

        UINT16 wMsgID = 0;
        if (pstAck->wErrCode == ERR_LOGIN::ID_SYSTEM_MAINTAIN)
        {
            pstAck->wErrCode = ERR_LOGIN::ID_GS_SERVER_NOT_STARTUP;
            wMsgID =  CLSPktBuilder::Instance()->LoginExAck(*pstAck, FALSE);
        }
        else
        {
            wMsgID =  CLSPktBuilder::Instance()->LoginExAck(*pstAck, TRUE);
        }

        //���͵��ͻ���
        poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());

		SDSleep(0);
		poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }

    poCliSession->SetState(CLIENT_STATE_AUTHED);

    //��¼�û�����
    CUser* poUser = CUserMgr::Instance()->CreateUser(pstAck->aszUserName, pstAck->aszDeviceID, pstAck->aszNotifyID, pstAck->wZoneID, 0, pstAck->dwUserID, pstAck->dwPlayerID, pstAck->wCareerID, pstAck->byAuthType, poCliSession, 0);
    if(NULL == poUser)
    {
        //�쳣
        DBG_INFO(_SDT("[%s:%d]: CreateUser failed! UserID[%d], UserName[%s], DeviceID[%s]"), MSG_MARK, pstAck->dwPlayerID, pstAck->aszUserName, pstAck->aszDeviceID);

		SDSleep(0);
		poCliSession->Disconnect();//��֤ʧ��Ҫ�Ͽ�����

        return FALSE;
    }
    poCliSession->SetUser(poUser);

    //���͵��ͻ���
    UINT16 wMsgID =  CLSPktBuilder::Instance()->LoginExAck(*pstAck, TRUE);
    poCliSession->SendMsg(wMsgID, CLSPktBuilder::Instance()->GetPacketBuffer());



    return FALSE; //�ѷ��ͣ�����ת��
}

CSDProtocol* CLSProcessor::GetProtocol()
{
    return CProtoGTLS::Instance();
}

