

#ifndef _NOTICE_HTTP_CMD_H_
#define _NOTICE_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SNoticeInfo
{
    SNoticeInfo()
    {
        wZoneID = 0;
    }
    UINT16	wZoneID; //��֤����
};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CNoticeHttpCMD : public CBaseHttpCMD
{
public:
    CNoticeHttpCMD();
    ~CNoticeHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_NOTICE;
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
    SNoticeInfo stNoticeInfo;

};

#endif //#ifndef _BASEDBCMD_H_

