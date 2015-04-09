

#ifndef _NAME_HTTP_CMD_H_
#define _LOGIN_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SNameInfo
{
    SNameInfo()
    {
        dwPlayerID = 0;
        strName = "";
        strOldName = "";
		byAuthType = 0;
    }
    UINT32   dwPlayerID; //���ID
    string	strName;
    string	strOldName;
	UINT8 byAuthType;
};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CNameHttpCMD : public CBaseHttpCMD
{
public:
    CNameHttpCMD();
    ~CNameHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_NAME;
    }
    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
private:
    SNameInfo stNameInfo;

};

#endif //#ifndef _BASEDBCMD_H_

