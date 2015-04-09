

#ifndef _BIND_CHECK_VER_CODE_HTTP_CMD_H_
#define _BIND_CHECK_VER_CODE_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SBindCheckVerCodeInfo
{
    SBindCheckVerCodeInfo()
    {
        dwUserID = 0;
        memset(abyVerCode,0,sizeof(abyVerCode));
    }
    UINT32           dwUserID; //�û�ID
    UINT8            abyVerCode[MAX_MOBILE_LENGTH+1]; //��֤��
};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CBindCheckVerCodeHttpCMD : public CBaseHttpCMD
{
public:
    CBindCheckVerCodeHttpCMD();
    ~CBindCheckVerCodeHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_BIND_CHECK_VER_CODE;
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
    BOOL	OnBindCheckVerCodeAck (UINT32 dwTransID, UINT16 wErrCode);

    BOOL	OnBindCheckVerCodeAck (UINT32 dwTransID, UINT16 wErrCode, TCHAR aszMobile[MAX_MOBILE_LENGTH]);

private:
    SBindCheckVerCodeInfo stBindCheckVerCodeInfo;

};

#endif //#ifndef _BASEDBCMD_H_

