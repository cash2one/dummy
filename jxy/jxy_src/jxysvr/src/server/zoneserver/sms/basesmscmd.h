

#ifndef _BASESMSCMD_H_
#define _BASESMSCMD_H_

#include <sdframework.h>
#include <sddb.h>
#include <curl/curl.h>

#include "common//client/errdef.h"



#define SAVE_USER_DATA			10000

//��������
enum ESMSCmdType
{
	ESMS_RESETPASSWD = 1,//��������
};


#define ACTION_MT		"http://vip.4001185185.com/sdk/smssdk!mt.action"
#define SDK			"13779953612"
#define CODE			"qtk88888"
#define PHONES		"18150155123"
#define MSG			"�������"
#define RESULTTYPE	"xml"
#define SUBCODE		"2278"
#define RESULTSTR		"<result>���ͳɹ�</result>"


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CBaseSmsCMD
{
public:
    CBaseSmsCMD();
    ~CBaseSmsCMD();

    /**
    * @brief �ͷ�DBCommand,�û�����ر�֤��DBCommand���ݱ���ȫ�ͷ�
    * @return VOID
    */
    VOID SDAPI Release();

	/////////////////////////////////////////////////////////////////////

    /**
    * @brief �����û��ض�����
    * @param pUserData ���õ��û�����
    * @param dwLen ���õ��û����ݳ���
    * @param dwTransID ���õ�TransID
    */
    VOID SetUserData(VOID* pUserData, UINT32 dwLen, UINT32 dwTransID, UINT32 dwUserID = 0, VOID* pParm = NULL);


	//����ִ��
	virtual VOID OnExecute(void);

	//����ִ�����ص�
	virtual VOID OnExecuted(void);

public:
	virtual ESMSCmdType GetSMSCmdType() = 0;

protected:

    /**
    * @brief ���ͻ�����Ϣ
    * @param pBuf ��Ҫ����������
    * @return VOID
    */
    VOID ResponseMsg(UINT16 wMsgID, const CHAR* pBuf);

	static size_t OnRecv(void *buffer, size_t size, size_t count, void *user_p);

protected:
    CHAR				m_pUserData[65535];
    INT32			m_dwDataLen;
    volatile BOOL		m_bSuccess;		///< ���ݿ�����ɹ���־
    UINT32			m_dwTransID;
	UINT32			m_dwUserID;
    CHAR				m_szParm[1024];
	string			m_strNetData;
};

#endif //#ifndef _BASEDBCMD_H_

