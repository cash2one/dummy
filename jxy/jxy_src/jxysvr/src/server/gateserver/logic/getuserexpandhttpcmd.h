#ifndef _GETUSEREXPAND_HTTP_CMD_H_
#define _GETUSEREXPAND_HTTP_CMD_H_


#include <sdframework.h>
#include <curl/curl.h>
#include "basehttpcmd.h"
#include "protocol/server/protoclils.h"
#include <algorithm/sdmd5.h>


struct SGetUserExpandInfo
{
	UINT32 dwUserID;
	UINT32 dwPlayerID;
};

class CGetUserExpandHttpCMD : public CBaseHttpCMD
{
public:
	CGetUserExpandHttpCMD();
	~CGetUserExpandHttpCMD();

	virtual BOOL  Init();
	 /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID);
public:
	virtual EHttpCmdType GetHttpCmdType(){ return EHCT_GET_USER_EXPAND; }

protected:
    /**
    * @brief ���ͻ�����Ϣ
    * @param pBuf ��Ҫ����������
    * @return VOID
    */
    //����ִ�����ص�
    virtual BOOL OnExecuted();
	BOOL SendMessage(UINT16 wErrcode, DT_EXPAND_FUNC_PARAM_LST* stExpandLst);
private:
	SGetUserExpandInfo m_stGetUserExpandInfo;
};

#endif