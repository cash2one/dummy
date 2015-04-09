
#include "framework/zsapplication.h"
#include "getuserinfo.h"
#include <sdutil.h>
#include <common/client/errdef.h>
#include <common/server/utility.h>



CGetUserInfoCMD::CGetUserInfoCMD()
{
    memset(&m_stAck, 0, sizeof(m_stAck));
}


CGetUserInfoCMD::~CGetUserInfoCMD()
{

}

VOID CGetUserInfoCMD::OnExecuteSql(SGDP::ISDDBConnection *poDBConn)
{

    m_bSuccess = FALSE;
    PKT_CLIZS_GET_USERINFO_REQ* pstReq = (PKT_CLIZS_GET_USERINFO_REQ*)m_pUserData;
    if(NULL == pstReq)
        return;
    UserInfo(poDBConn, pstReq);
}

VOID CGetUserInfoCMD::OnExecuted()
{
    ResponseMsg(CLIZS_GET_USERINFO_ACK, (CHAR*)(&m_stAck));
}


BOOL CGetUserInfoCMD::UserInfo(SGDP::ISDDBConnection* poDBConn, PKT_CLIZS_GET_USERINFO_REQ* pstReq)
{
    m_stAck.dwErrCode = ERR_GET_USERINFO::ID_SUCCESS;
    CHAR		szSQL[1024] = {0};
    ISDDBRecordSet* pRecordSet = NULL;

    CHAR szErrMsg[128] = {0};
    sprintf(szSQL, "call GetUserInfo(%d, '%s', @ErrCode, @ErrMsg);", pstReq->byAuthType, pstReq->aszDeviceID);
    SYS_CRITICAL(_SDT("%s"), szSQL);


    BOOL		bTypeDev =	FALSE;
    UINT32	dwNum	=	0;
    UINT32	dwLen	=	0;
    UINT32	dwUserID	=	0;
    INT32	nRet		=	poDBConn->ExecuteSqlRs(szSQL, &pRecordSet);
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord() && dwNum < MAX_USER_INFO_NUM)
        {
            //�û�ID
            dwUserID = SDAtou(pRecordSet->GetFieldValueByName("UserID"));

            //�û�����
            dwLen = pRecordSet->GetFieldLengthByName("UserName");
            dwLen = dwLen > USERNAME_LEN ? USERNAME_LEN : dwLen;
            SDStrncpy(m_stAck.astUserInfo[dwNum].aszUserName, pRecordSet->GetFieldValueByName("UserName"), dwLen);

            //�û����
            dwLen = pRecordSet->GetFieldLengthByName("NickName");
            dwLen = dwLen > USERNAME_LEN ? USERNAME_LEN : dwLen;
            SDStrncpy(m_stAck.astUserInfo[dwNum].aszNickName, pRecordSet->GetFieldValueByName("NickName"), dwLen);

            //�û�����
            m_stAck.astUserInfo[dwNum].byType = SDAtou(pRecordSet->GetFieldValueByName("AuthType"));

            if(AUTH_TYPE_DEVECEID == m_stAck.astUserInfo[dwNum].byType)
            {
                bTypeDev = TRUE;
                char v_szTemp[256] = {0};
                sprintf(v_szTemp, "(�ο�ID:%u)", dwUserID);
                SDStrncpy(m_stAck.astUserInfo[dwNum].aszUserName, SDGBK2UTF8(v_szTemp).c_str(), SDGBK2UTF8(v_szTemp).size());
            }
            dwNum++;
        }
    }

    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    //����һ֡δ�󶨵��˺ŵ�¼
    if (!bTypeDev)
    {
        m_stAck.astUserInfo[dwNum].byType = AUTH_TYPE_DEVECEID;
        SDStrncpy(m_stAck.astUserInfo[dwNum].aszUserName, SDGBK2UTF8("(���ٿ�ʼ����Ϸ)").c_str(), SDGBK2UTF8("(���ٿ�ʼ����Ϸ)").size());
        dwNum++;
    }
    m_stAck.byNum = dwNum;


    sprintf(szSQL, "select @ErrCode, @ErrMsg;");
    nRet = poDBConn->ExecuteSqlRs(szSQL, &pRecordSet);
    if((SDDB_HAS_RECORDSET == nRet) && (pRecordSet->GetRecord()))
    {
        m_stAck.dwErrCode = SDAtou(pRecordSet->GetFieldValueByName("@ErrCode"));
        SDStrncpy(szErrMsg, pRecordSet->GetFieldValueByName("@ErrMsg"), 128);
        switch(m_stAck.dwErrCode)
        {
        case 0:
            m_stAck.dwErrCode = ERR_GET_USERINFO::ID_SUCCESS;
            break;
        case 1:
            m_stAck.dwErrCode = ERR_GET_USERINFO::ID_FORBID;
            break;
        default:
            m_stAck.dwErrCode = ERR_COMMON::ID_OTHER_ERR;
            break;
        }
    }
    else
    {
        m_stAck.dwErrCode = ERR_COMMON::ID_OTHER_ERR;
    }

    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    return TRUE;
}
