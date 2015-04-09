#ifndef _REGISTER_HTTP_CMD_H_
#define _REGISTER_HTTP_CMD_H_

#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>

struct SResgisterInfo
{
	SResgisterInfo()
	{
		strDeviceid = "";
		strUserName = "";
		strUserPwd = "";
		byAuthType = 0;
		dwPlayerID = 0;
		dwUserID = 0;
	}
	string strDeviceid;
	string strUserName;
	string strUserPwd;
	UINT8  byAuthType; //��֤����
	UINT32 dwPlayerID;
	UINT32 dwUserID;
};

class CRegisterHttpCMD : public CBaseHttpCMD
{
public:
	CRegisterHttpCMD();
	~CRegisterHttpCMD();

	  virtual BOOL  Init();

    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
public:
	virtual EHttpCmdType GetHttpCmdType(){ return EHCT_REGISTER; }

protected:
    /**
    * @brief ���ͻ�����Ϣ
    * @param pBuf ��Ҫ����������
    * @return VOID
    */
    //����ִ�����ص�
    virtual BOOL OnExecuted();
	BOOL SendMessage(UINT16 wErrcode, const TCHAR* aszUserName);
private:
	SResgisterInfo m_stRegisterInfo;
};
#endif