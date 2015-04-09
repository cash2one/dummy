

#ifndef _LOGINEX_HTTP_CMD_H_
#define _LOGINEX_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SLoginInfoEx
{
    SLoginInfoEx()
    {
		Init();
    }
	void Init()
	{
		strIp = "";
		memset(&stReq, 0x00, sizeof(PKT_CLILS_LOGIN_EX_REQ));
	}
	PKT_CLILS_LOGIN_EX_REQ		stReq;
	string					strIp;

};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CLoginExHttpCMD : public CBaseHttpCMD
{
public:
    CLoginExHttpCMD();
    ~CLoginExHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_LOGINEX;
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
    BOOL	OnLoginExAck_Failed (UINT16 wErrCode);

    BOOL	OnLoginExAck_Success (UINT32 dwUserID, UINT8 byDaiChong);

	void GetPacketBuffer();

private:
    SLoginInfoEx			stLoginInfo;
	PKT_CLILS_LOGIN_EX_ACK	stAck;

    // ���ԭ�����ڵ���������Ҵ�����ɫʱ���ڵ����������ID�����ڲ����ģ�
    UINT16 m_wOriZoneID;
};

#endif //#ifndef _BASEDBCMD_H_

