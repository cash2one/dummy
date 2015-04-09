

#ifndef _SELECT_ZONE_HTTP_CMD_H_
#define _SELECT_ZONE_HTTP_CMD_H_

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
class CSelectZoneHttpCMD : public CBaseHttpCMD
{
public:
    CSelectZoneHttpCMD();
    ~CSelectZoneHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_SELECTZONE;
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
    PKT_CLIGT_SELECT_ZONE_REQ stReq;
	PKT_CLIGT_SELECT_ZONE_ACK stAck;

};

#endif //#ifndef _BASEDBCMD_H_

