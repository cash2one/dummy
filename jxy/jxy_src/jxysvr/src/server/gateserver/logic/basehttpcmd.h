

#ifndef _BASE_HTTP_CMD_H_
#define _BASE_HTTP_CMD_H_

#include <string>
#include <sdtype.h>
#include "curl/curl.h"
using namespace std;

//HTTP��������
enum EHttpCmdType
{
	EHCT_LOGINEX = 1,
	EHCT_NOTICE = 2,
	EHCT_REGISTER = 3,	//ע��
	EHCT_LOGOUT = 4,	//�ǳ�
	EHCT_CHANGEPWD = 5,	//�޸�����
	EHCT_BIND_MOBILE = 6,//���ֻ�
	EHCT_BIND_CHECK_VER_CODE = 7,	//���ֻ�ͨ����֤��
	EHCT_UNBIND_MOBILE = 8,	//����ֻ�
	EHCT_UNBIND_CHECK_VER_CODE = 9,//����ֻ�ͨ����֤��
	EHCT_GET_USER_EXPAND = 10,	//��ȡ�û�������Ϣ
	EHCT_LOGIN = 11,	//����

};

#define CENTER_SIGN	"Bef^3rwsvn!29jcx57ng"

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


	VOID ResponseMsg(UINT16 wMsgID, const CHAR* pBuf, BOOL bDisconnect = FALSE);

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

