

#ifndef _SDF_CLISESSION_H_
#define _SDF_CLISESSION_H_

#include <sdsingleton.h>
#include <protocol/server/protocommondata.h>

using namespace std ;

class CPlayer;

enum EUserStat
{
    CLIS_LOGIN_INVALID        = -1,
    CLIS_GET_USER_DATA_ING    ,//��db���������û�������
    CLIS_GET_USER_DATA_COMPLETE    ,//���db���û�Ӧ�����ݰ�
    CLIS_WAIT_CLI_LOAD_FINISH    ,//�ȴ��ͻ���load���������
    CLIS_IN_GAME                ,//�������������Ϸ
	CLIS_DISCONNECT                ,//��ҶϿ�����
    CLIS_ALL           , //������������״̬
};


class CUserMgr;
/**
* @brief �ͻ���������
* ���յ����ػ㱨���пͻ��˽���ʱ�������ʵ��
* ���յ����ػ㱨���пͻ����뿪ʱ�ͷŸ���ʵ��
*/
class CUser
{
	friend class CUserMgr;
public:
    CUser();
    ~CUser();
public:
    /**
    * @brief
    * ��ͻ������ӷ�������
    * @param pData :  ��������
    * @param dwLen :  ���ݳ���
    * @return FALSE : ����ʧ�� ��TRUE : ���ͳɹ�
    **/
    BOOL            Send(const CHAR* pData, UINT32 dwLen);

    /**
    * @brief
    * ��ͻ������ӷ�����Ϣ�ṹ��
    * @param pData :  ��������
    * @param wMsgID :  ��Ϣ����
    * @return FALSE : ����ʧ�� ��TRUE : ���ͳɹ�
    **/
    BOOL            SendMsg(const CHAR* pData, UINT16 wMsgID);


    /**
    * @brief
    * ��ȡ��ǰ���û���GS�ϵ�״̬
    * �û�����������DBServerȡ��ɫ���ݵ�
    * @return �û���ǰ״̬
    **/
    EUserStat       GetUserStat();

    /**
    * @brief
    * ��ȡ��ǰ���û���GS�ϵ�״̬
    * �û�����������DBServerȡ��ɫ���ݵ�
    * @param enUserStat :  �û���ǰ״̬
    * @return �û���ǰ״̬
    **/
    VOID            SetUserStat(EUserStat enUserStat);

	    /**
    * @brief
    * ��ȡ��ǰ���û����
    * @return �û����
    **/
    //CPlayer*    GetPlayer() { return m_poPlayer; }

	CPlayer*    GetPlayer();

	/**
    * @brief
    * �����������
    * @return �û����
    **/
    //BOOL		SavePlayerData();

	VOID			SetDisconnectTime(UINT64 qwDisconnectTime = SDTimeSecs()) { m_qwDisconnectTime = qwDisconnectTime; }
	UINT64		GetDisconnectTime() { return m_qwDisconnectTime; }

	UINT32		GetUserSessionID() { return m_dwPlayerID; }
	UINT32		GetPlayerID() { return m_dwPlayerID; }
	UINT32		GetUserID() { return m_dwUserID; }
	UINT16		GetCareerID() { return m_wCareerID; }
	
	TCHAR*		GetUserName() { return m_szUserName; }
	TCHAR*		GetDeviceID() { return m_szDeviceID; }
	TCHAR*		GetNotifyID() { return m_szNotifyID; }
    UINT16		GetZoneID() { return m_wZoneID; }
	UINT16		GetOriginalZoneID() { return m_wOriZoneID; }
	UINT32		GetLoginIP() { return m_dwLoginIP; }
	UINT32		GetCliVer() { return m_dwCliVer; }
	UINT8		GetAuthType() { return m_byAuthType; }
	UINT8		GetDaiChong() { return m_byDaiChong; }

	VOID			CkUserLogin();
	VOID			CkUserDisconnect();

	VOID			SetUserProp(UINT32 dwUserID, UINT32 dwPlayerID, TCHAR* pszUserName, TCHAR* pszDeviceID, TCHAR* pszNotifyID, UINT16 wCareerID, UINT16 wZoneID, UINT16 wOriZoneID, UINT32 dwLoginIP, UINT32 dwCliVer, UINT8 byAuthType, UINT8 byDaiChong);
private:
    EUserStat       m_enUserStat;//��ǰSession��״̬
	
	UINT32			m_dwUserID;//�û�ID
	UINT32			m_dwPlayerID;//�û��ỰID��PlayerID
	
	UINT16			m_wCareerID;//ְҵID���´����û���Ч
    UINT16			m_wZoneID;//��ID
	UINT16			m_wOriZoneID;//��Ҵ�����ɫʱ���ڵ���ID
	UINT32			m_dwLoginIP;//��¼IP
	UINT32			m_dwCliVer;//�ͻ��˰汾
	UINT8			m_byAuthType;
	TCHAR			m_szUserName[USERNAME_LEN];
	TCHAR			m_szDeviceID[DEVICEID_LEN];
	TCHAR			m_szNotifyID[NOTIFYID_LEN];
	UINT64			m_qwDisconnectTime;	//����ʱ��,���ڹ������
	UINT64			m_qwLastRecvMsgTime; //�ϴ��յ���Ϣʱ��
	UINT8			m_byDaiChong;
};


#define ZERO_PACKET(PKT_ACK)\
	ZeroPacketBuffer(sizeof(PKT_ACK));\
	PKT_ACK* pstAck = (PKT_ACK*)(GetPacketBuffer());


#endif //#ifndef _SDF_CLISESSION_H_

