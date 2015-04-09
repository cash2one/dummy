

#ifndef _UN_BIND_MOBILE_HTTP_CMD_H_
#define _UN_BIND_MOBILE_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SUnBindInfo
{
    SUnBindInfo()
    {
        dwUserID = 0;
    }
    UINT32           dwUserID; //�û�ID
};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CUnBindMobileHttpCMD : public CBaseHttpCMD
{
public:
    CUnBindMobileHttpCMD();
    ~CUnBindMobileHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_UNBIND_MOBILE;
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
    //������֤��Ϣ
    BOOL	OnUnBindMobileAck (UINT32 dwTransID, UINT16 wErrCode);

    BOOL	OnUnBindMobileAck (UINT32 dwTransID, UINT16 wErrCode, UINT16 wCountDown);

private:
    SUnBindInfo stUnBindInfo;

};

#endif //#ifndef _BASEDBCMD_H_

