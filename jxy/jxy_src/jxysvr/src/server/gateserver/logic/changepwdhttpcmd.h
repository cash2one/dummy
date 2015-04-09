#ifndef _CHANGEPWD_HTTP_CMD_H_
#define _CHANGEPWD_HTTP_CMD_H_


#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>


struct SChangePwdInfo
{
	SChangePwdInfo()
	{
		strDeviceid = "";
		dwUserID = 0;
		strNewPwd = "";
		strOldPwd = "";
		dwPlayerID = 0;
	}
	string strDeviceid;
	UINT32 dwUserID;
	string strNewPwd;
	string strOldPwd;
	UINT32 dwPlayerID;
};

class CChangePwdHttpCMD : public CBaseHttpCMD
{
public:
	CChangePwdHttpCMD();
	~CChangePwdHttpCMD();

	virtual BOOL  Init();
	 /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
public:
	virtual EHttpCmdType GetHttpCmdType(){ return EHCT_CHANGEPWD; }

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
	SChangePwdInfo m_stChangePwdInfo;
};

#endif