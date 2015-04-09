

#ifndef _RESETPASSWDMOBILE_HTTP_CMD_H_
#define _RESETPASSWDMOBILE_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclizs.h"
#include <algorithm/sdmd5.h>






/**
* @brief DBCommand,�첽������DBCommand
*
*
*/
class CResetPasswdMobileHttpCMD : public CBaseHttpCMD
{
public:
    CResetPasswdMobileHttpCMD();
    ~CResetPasswdMobileHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_RESETPASSWDMOBILE;
    }
    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);

private:
    VOID	ProcessResult();

private:
    PKT_CLIZS_RESET_PASSWD_MOBILE_REQ stReq;
	PKT_CLIZS_RESET_PASSWD_MOBILE_ACK stAck;

};

#endif //#ifndef _BASEDBCMD_H_
