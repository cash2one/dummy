

#ifndef _LEVEL_HTTP_CMD_H_
#define _LEVEL_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SLevelInfo
{
    SLevelInfo()
    {
        dwPlayerID = 0;
        wLevel = 0;
		strDeviceID = "";
		strIp = "";
		byAuthType = 0;
    }
    UINT32	dwPlayerID; //ʵ�ʶ�����Ӧ�����ID
    UINT16	wLevel;
	string	strDeviceID;
	string	strIp;
	UINT8 byAuthType;
};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CLevelHttpCMD : public CBaseHttpCMD
{
public:
    CLevelHttpCMD();
    ~CLevelHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_LEVEL;
    }
    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
private:
    SLevelInfo stLevelInfo;

};

#endif //#ifndef _BASEDBCMD_H_

