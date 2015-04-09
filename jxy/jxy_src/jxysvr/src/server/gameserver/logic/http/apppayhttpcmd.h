

#ifndef _APP_PAY_HTTP_CMD_H_
#define _APP_PAY_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>



struct SAppPayInfo
{
	SAppPayInfo()
	{
		dwPlayerID = 0;
		dwQueryPlayerID = 0;
		strOrderID = "";
		strReceipt = "";
		nQueryCnt = 0;
		bBuyEnv = TRUE;
	}

	UINT32	dwPlayerID; //ʵ�ʶ�����Ӧ�����ID
	UINT32	dwQueryPlayerID; //�����ֵ������˺�ID(����֪ͨ��ֵ�ɹ�)
	string	strOrderID; //������
	string	strReceipt; //���������
	INT32	nQueryCnt;
	BOOL		bBuyEnv;
};



/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CAppPayHttpCMD : public CBaseHttpCMD
{
public:
    CAppPayHttpCMD();
    ~CAppPayHttpCMD();

	virtual BOOL  Init();

    //����ִ�����ص�
    virtual BOOL OnExecuted();

    virtual EHttpCmdType GetHttpCmdType()
    {
        return EHCT_APP_PAY;
    }
    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);

	VOID ProcessPayResult();

	VOID SendErrorResult( INT32 dwPlayerID, INT32 nErrorCode, string strOrderID);

private:
	void Try( UINT32 dwPlayerID, string strReceipt, UINT32 dwQueryPlayerID, string strOrderID, INT32 nQueryCnt, BOOL bBuyEnv);
private:
    SAppPayInfo m_stAppPayInfo;

};

#endif //#ifndef _BASEDBCMD_H_

