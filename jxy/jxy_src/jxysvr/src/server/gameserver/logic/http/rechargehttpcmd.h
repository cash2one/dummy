

#ifndef _HTTP_RECHARGE_CMD_H_
#define _HTTP_RECHARGE_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include  "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>
#include <json/json.h>

struct SRechargeInfo
{
    SRechargeInfo()
    {
        ZoneID = 0;
        IndexMax = 0;
    }
    UINT32   ZoneID; //���ID
    UINT32	IndexMax;//��ǰplayer_recharge��������ID
};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CRechargeHttpCMD : public CBaseHttpCMD
{
public:
    CRechargeHttpCMD();
    ~CRechargeHttpCMD();

    virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_RECHARGE;
    }
    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pRechargeInfo, UINT32 dwLen, UINT32 dwTransID);
public:
	BOOL ProcessResult(Json::Value &datas);
private:
    SRechargeInfo stRechargeInfo;

};

#endif //#ifndef _BASEDBCMD_H_

