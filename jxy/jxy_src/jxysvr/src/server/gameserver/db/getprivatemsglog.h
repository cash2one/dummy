#ifndef _GET_PRIVATE_MSG_LOG_CMD_H_
#define _GET_PRIVATE_MSG_LOG_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include "logic/friendsys/privatemsgmgr.h"


enum em_GetPrivateMsg
{
	em_Msg = 1,//�����¼
	em_Log = 2,//������־
};


typedef struct tagGET_PRIVATEMSGLOG
{
    tagGET_PRIVATEMSGLOG()
    {
		dwSenderID = 0;
		dwRecverID = 0;
		strMsgContent = "";
		dwStartIdx = 0;
		byGetMsgNum = 0;
    }
	BOOL   byType;
    UINT32 dwSenderID;
	UINT32 dwRecverID;
	string strMsgContent;
	UINT32 dwStartIdx; //��ʼ���
	UINT8  byGetMsgNum; //��ȡ��Ϣ����(���С����ŷ���ȡ)
} GET_PRIVATEMSGLOG;

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetPrivateMsgLogCmd : public CBaseDBCMD
{
public:
    CGetPrivateMsgLogCmd();
    virtual ~CGetPrivateMsgLogCmd();
    /**
    * @brief �첽ִ��SQL����
    * @poDBConn �첽ִ��SQL�����Connection����
    * @return VOID
    */
    VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection* poDBConn);

    /**
    * @brief ͬ��ִ��SQL������ص��߼�����
    * @return VOID
    */
    VOID SDAPI OnExecuted();

    //��������
    virtual VOID SetUserData(VOID* pUserData);

public:
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_GET_PRIVATEMSGLOG ;
    }

private:
    UINT16				m_wErrCode;
    GET_PRIVATEMSGLOG		m_GET_PRIVATEMSGLOG;
	//��Ϣ����
	SPrivateMsgList		m_listPrivateMsg;
};


#endif