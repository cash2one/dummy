

#ifndef _GET_USER_INFO_HTTP_CMD_H_
#define _GET_USER_INFO_HTTP_CMD_H_

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
class CGetUserInfoHttpCMD : public CBaseHttpCMD
{
public:
    CGetUserInfoHttpCMD();
    ~CGetUserInfoHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_GET_USER_INFO;
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
	PKT_CLIZS_GET_USERINFO_REQ stReq;
	PKT_CLIZS_GET_USERINFO_ACK stAck;


};

#endif //#ifndef _BASEDBCMD_H_

