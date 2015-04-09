
#ifndef __GATEESERVER_CLIENT_CHANNEL_H
#define __GATEESERVER_CLIENT_CHANNEL_H

#include <sdframework.h>
#include <sdhashmap.h>
#include <sdtype.h>
#include <logic/mgencrypt.h>
#include "net/cli/cliprocessor.h"
#include "logic/usermgr.h"

/**
* @brief ����Client��Ϣ����״̬��ö��
*/
enum EClientState
{
    CLIENT_STATE_UNAUTHED,	
    CLIENT_STATE_AUTHING,
    CLIENT_STATE_AUTHED,
    CLIENT_STATE_ENTERING_GAME,
    CLIENT_STATE_IN_GS,		
    CLIENT_STATE_LEAVEING_GAME, //�Ѿ������뿪��Ϸ���Ѿ���GS����������Ϣ������Ҳ�����ٴη�������Ϣ�������첽�µ�¼��
	CLIENT_STATE_ENTERING_GAME_KICK,//���ˣ���֮ǰ�����������ߣ����������ڽ�����Ϸ��.��ʱ�����ӶϿ�����GS��������Ϣ
	CLIENT_STATE_RERI_USERNAME,//��ȥLSע���û�
	CLIENT_STATE_RERISTERING,//ȥLSע���û���	
};

/**
* @brief ����Client��Ϣ����ת�������ö��
*/
enum ETransferDirection
{
    CLIENT_DIRECTION_NONE,
    CLIENT_DIRECTION_LS,
    CLIENT_DIRECTION_GS,
};


class CGTClient: public ISDSession
{
public:
    CGTClient();
    virtual ~CGTClient();
public:
    virtual VOID SDAPI SetConnection(ISDConnection* poConnection);

    virtual bool SDAPI OnError(INT32 nSDError, INT32 nSysError);

    virtual VOID SDAPI OnEstablish();

	virtual VOID SDAPI OnTerminate();

	virtual VOID SDAPI OnRecv(const CHAR* pBuf, UINT32 nLen);

	virtual VOID SDAPI Release();

    ISDConnection* GetConnection();

    VOID SetCliSessionID(UINT32 dwCliSessionID);

    UINT32 GetCliSessionID();

    VOID SetState(EClientState eState);

    EClientState GetState();

    ETransferDirection GetTransferTarget(UINT16 wMsgID = 0);

    VOID Disconnect();

    BOOL SDAPI Send(UINT16 wMsgID, const CHAR* pBuf, INT32 nLen);

    BOOL SDAPI  SendMsg(UINT16 wMsgID ,const CHAR* pData);

    UINT64	GetLastTime() { return m_qwLastTime; } 
    VOID	SetTimeOutCloseFlag(BOOL bTimeOutClose = TRUE) { m_bTimeOutClose = bTimeOutClose; }
    BOOL	GetTimeOutCloseFlag() { return m_bTimeOutClose; }

    VOID SDAPI  SetPacketProcessor(CSDPacketProcessor*    pPacketProcessor);

	VOID	SetUser(CUser* poUser) { m_poUser = poUser; }
	CUser*  GetUser() { return m_poUser; }
	
    BOOL	SendRoleListReq();
    BOOL    SendSelectRole();
    BOOL	SendCliDownRpt();

	VOID	HeartbeatAck();

	MGEncrypt& GetMGEncrypt() { return m_oMGEncrypt; }

	inline UINT32 GetRemoteIP() { if(m_poConnection) return m_poConnection->GetRemoteIP();  return 0; }
	
	const string  GetRemoteIPStr()
	{
		string v_strip;
		if (NULL != m_poConnection)
		{
			v_strip =  m_poConnection->GetRemoteIPStr();
		}
		return v_strip;
	}

private:
    ISDConnection*				m_poConnection;		/** ��client֮������� */
    CSDPacketProcessor*			m_poPacketProcessor;
    EClientState   		        m_eState;	/** ��ǰclient�Ĵ���״̬ */
    UINT32						m_dwCliSessionID;		/** Gate Server��client���������ID */
    CUser*                       m_poUser;
    UINT64						m_qwLastTime;//�ϴ��յ�����ʱ��
    BOOL							m_bTimeOutClose;//�Ƿ��ǳ�ʱ��δ�յ������رյ�
	MGEncrypt					m_oMGEncrypt;//���ڼӽ���
};


class CGTClientMgr: public ISDSessionFactory
{
public:
    typedef HashMap<UINT32, CGTClient*>	    CGTClientMap;
    typedef CGTClientMap::iterator          CGTClientMapItr;
    CGTClientMgr();
    ~CGTClientMgr();
    virtual								ISDSession* SDAPI CreateSession(ISDConnection* poConnection);
public:
    BOOL								Init(UINT32 nMaxClient);
    VOID								UnInit();
    VOID								ReleaseCliSession(CGTClient* pSession);
    VOID								AddCliSession(CGTClient* poSession);
    VOID								RemoveCliSession(CGTClient* poSession);
    CGTClient*						    FindCliSession(UINT32 dwClientID);
    UINT32								GenerateClientID();
    UINT32								GetCliSessionCount();
    VOID								ChkSessionOnTimer();
    VOID                                GSDisConnect(UINT32 dwServerID);
	inline UINT32						GetSessionNum() { return m_mapCliSession.size(); }

private:
    CSDObjectPool<CGTClient,CSDMutex>*	m_poCliSessionPool;
    CGTClientMap			            m_mapCliSession;
    CSDMutex*							m_poLock;
    UINT32								m_dwCurClientID;    
    CGTClientMapItr			            m_itrCurDeal;
    CCliProcessor                       m_oCliProcessor;
};


#endif

