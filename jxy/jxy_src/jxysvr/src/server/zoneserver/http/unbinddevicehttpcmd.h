

#ifndef _UNBIND_DEVICE_HTTP_CMD_H_
#define _UNBIND_DEVICE_HTTP_CMD_H_

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
class CUnBindDeviceHttpCMD : public CBaseHttpCMD
{
public:
    CUnBindDeviceHttpCMD();
    ~CUnBindDeviceHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_UNBINDDEVICE;
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
	PKT_CLIZS_UN_BIND_DEVICE_ACK stAck;
    PKT_CLIZS_UN_BIND_DEVICE_REQ stReq;

};

#endif //#ifndef _BASEDBCMD_H_

