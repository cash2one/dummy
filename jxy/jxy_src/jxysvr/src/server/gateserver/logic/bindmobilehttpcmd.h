

#ifndef _BIND_MOBILE_HTTP_CMD_H_
#define _BIND_MOBILE_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SBindInfo
{
    SBindInfo()
    {
        dwUserID = 0;
        memset(abyMObile,0,sizeof(abyMObile));
    }
    UINT32           dwUserID; //�û�ID
    UINT8            abyMObile[MAX_MOBILE_LENGTH+1]; //�û��ֻ���

};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CBindMobileHttpCMD : public CBaseHttpCMD
{
public:
    CBindMobileHttpCMD();
    ~CBindMobileHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_BIND_MOBILE;
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
    BOOL	OnBindMobileAck (UINT32 dwTransID, UINT16 wErrCode);

    BOOL	OnBindMobileAck (UINT32 dwTransID, UINT16 wErrCode, UINT16 wCountDown);

private:
    SBindInfo stBindInfo;

};

#endif //#ifndef _BASEDBCMD_H_

