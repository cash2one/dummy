#ifndef _LOGOUT_HTTP_CMD_H_
#define _LOGOUT_HTTP_CMD_H_


#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>


struct SLogoutInfo
{
	SLogoutInfo()
	{
		byAuthType = 0;
		strDeviceID = "";
		dwUserID = 0;
		dwPlayerID = 0;
	}
	UINT8 byAuthType; //��֤����
	string strDeviceID; //�豸ID
	UINT32 dwUserID; //�û�ID
	UINT32 dwPlayerID;
};

class CLogoutHttpCMD : public CBaseHttpCMD
{
public:
	CLogoutHttpCMD();
	~CLogoutHttpCMD();

	virtual BOOL  Init();
	 /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
public:
	virtual EHttpCmdType GetHttpCmdType(){ return EHCT_LOGOUT; }

protected:
    /**
    * @brief ���ͻ�����Ϣ
    * @param pBuf ��Ҫ����������
    * @return VOID
    */
    //����ִ�����ص�
    virtual BOOL OnExecuted();
	BOOL SendMessage(UINT16 wErrcode);
private:
	SLogoutInfo m_stLogoutInfo;
};

#endif