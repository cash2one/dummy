

#ifndef _BASE_HTTP_CMD_H_
#define _BASE_HTTP_CMD_H_

#include <string>
#include <curl/curl.h>
#include <sdtype.h>

#include "httpmgr.h"

using namespace std;



class CHttpMgr;
class CBaseHttpCMD
{
    friend class CHttpMgr;
public:
    CBaseHttpCMD();
    ~CBaseHttpCMD();

    virtual BOOL  Init() = 0;

    /**
    * @brief �ͷ�DBCommand,�û�����ر�֤��DBCommand���ݱ���ȫ�ͷ�
    * @return VOID
    */
    VOID  Release();

    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    virtual VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID) = 0;



public:
    virtual EHttpCmdType GetHttpCmdType() = 0;

protected:
    /**
    * @brief ���ͻ�����Ϣ
    * @param pBuf ��Ҫ����������
    * @return VOID
    */
    //����ִ�����ص�
    virtual BOOL OnExecuted() = 0;


	VOID ResponseMsg(UINT16 wMsgID, const CHAR* pBuf);

	virtual string UrlSig();

protected:
    CURL *		m_pEasyHandle; //URL����Ϣ
    UINT64		m_qwLastAddTime;//�ϴ����URL����ʱ��
    CHAR			m_szErrorBuff[CURL_ERROR_SIZE]; //������Ϣ
    string		m_strResult;
    string		m_strUrl;
    string		m_strfields;
    UINT32		m_dwTransID;
	BOOL			m_bError;
};

#endif //#ifndef _BASEDBCMD_H_

