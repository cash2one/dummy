

#ifndef _REGISTER_HTTP_CMD_H_
#define _REGISTER_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclizs.h"
#include <algorithm/sdmd5.h>






/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CRegisterUserNameHttpCMD : public CBaseHttpCMD
{
public:
    CRegisterUserNameHttpCMD();
    ~CRegisterUserNameHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_REGISTER_USERNAME;
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
	PKT_CLIZS_REGISTER_USERNAME_REQ stReq;
	PKT_CLIZS_REGISTER_USERNAME_ACK stAck;

};

#endif //#ifndef _BASEDBCMD_H_

