/*       Version Number: 3          */

#ifndef PROTOGTLS_H_INCLUDE_VERSION_3
#define PROTOGTLS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "protocommondata.h"
#include "protogtcommon.h"
#include "protoclils.h"
#include "protogsls.h"
#include "sdtype.h"
#include "sdstring.h"
#pragma pack(push, 1)

/*Defines Begin*/
#define MAX_IP_LENGTH            56
#define PROTOGTLS_MSGID_RANGE 1404
#define PROTOGTLS_MSGID_OFFSET 0
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagPKT_GTLS_LOGIN_REQ{
	tagPKT_GTLS_LOGIN_REQ() { memset(this, 0, sizeof(tagPKT_GTLS_LOGIN_REQ)); }
	UINT32           dwCliVersion; //�ͻ��˰汾��,ȡ2λС����(/100)
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT16           wZoneID; //��ID
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ�����������(PlayerIDΪ0)��Ч
	UINT8            byAuthMethod; //��֤��ʽ
	UINT32           dwSerialNumber; //��ˮ��
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
	TCHAR            aszIP[MAX_IP_LENGTH]; //IP
}PKT_GTLS_LOGIN_REQ;

typedef struct tagPKT_GTLS_LOGIN_ACK{
	tagPKT_GTLS_LOGIN_ACK() { memset(this, 0, sizeof(tagPKT_GTLS_LOGIN_ACK)); }
	UINT16           wErrCode; //�û������֤
	DT_VERSION_DATA  stVersionInfo; //�汾��Ϣ
	DT_NOTICE_DATA   stNoticeInfo1; //������Ϣ
	DT_NOTICE_DATA   stNoticeInfo2; //������Ϣ
	UINT8            byOtherDeviceLoginFlag; //�Ƿ������豸��¼��
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT16           wZoneID; //��ID
	TCHAR            aszZoneName[USERNAME_LEN]; //������
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ�����������(PlayerIDΪ0)��Ч
	UINT32           dwUserID; //�û�ID
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
}PKT_GTLS_LOGIN_ACK;

typedef struct tagPKT_GTLS_LOGIN_EX_REQ{
	tagPKT_GTLS_LOGIN_EX_REQ() { memset(this, 0, sizeof(tagPKT_GTLS_LOGIN_EX_REQ)); }
	UINT32           dwCliVersion; //�ͻ��˰汾��,ȡ2λС����(/100)
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT16           wZoneID; //��ID
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ�����������(PlayerIDΪ0)��Ч
	UINT8            byAuthMethod; //��֤��ʽ
	TCHAR            aszIP[MAX_IP_LENGTH]; //IP
}PKT_GTLS_LOGIN_EX_REQ;

typedef struct tagPKT_GTLS_LOGIN_EX_ACK{
	tagPKT_GTLS_LOGIN_EX_ACK() { memset(this, 0, sizeof(tagPKT_GTLS_LOGIN_EX_ACK)); }
	UINT16           wErrCode; //�û������֤
	DT_VERSION_DATA  stVersionInfo; //�汾��Ϣ
	DT_NOTICE_DATA   stNoticeInfo1; //������Ϣ
	DT_NOTICE_DATA   stNoticeInfo2; //������Ϣ
	UINT8            byOtherDeviceLoginFlag; //�Ƿ������豸��¼��
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT16           wZoneID; //��ID
	TCHAR            aszZoneName[USERNAME_LEN]; //������
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ�����������(PlayerIDΪ0)��Ч
	UINT32           dwUserID; //�û�ID
}PKT_GTLS_LOGIN_EX_ACK;

typedef struct tagPKT_GTLS_CHANGE_PWD_REQ{
	tagPKT_GTLS_CHANGE_PWD_REQ() { memset(this, 0, sizeof(tagPKT_GTLS_CHANGE_PWD_REQ)); }
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT8            byNewPwdLen; //�����볤��
	UINT8            abyNewUserPwd[USERNAME_LEN]; //������
	UINT32           dwUserID; //�û�ID
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸ID
}PKT_GTLS_CHANGE_PWD_REQ;

/*Define Structs and Unions        End*/


enum EN_ProtoGTLS_MessageID
{
	GTLS_LOGIN_REQ                  = 1351        ,
	GTLS_LOGIN_ACK                  = 1352        ,
	GTLS_LOGIN_EX_REQ               = 1353        ,
	GTLS_LOGIN_EX_ACK               = 1354        ,
	GTLS_CHANGE_PWD_REQ             = 1355        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodePKT_GTLS_LOGIN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GTLS_LOGIN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GTLS_LOGIN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GTLS_LOGIN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GTLS_LOGIN_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GTLS_LOGIN_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GTLS_LOGIN_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GTLS_LOGIN_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GTLS_CHANGE_PWD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GTLS_CHANGE_PWD_REQ(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoGTLS)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoGTLS)(void *pHost, CNetData* poNetData);

class CProtoGTLS : public CSDProtocol
{
public:
    static CProtoGTLS * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoGTLS FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoGTLS FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoGTLS();
	virtual ~CProtoGTLS();
	EnFuncCProtoGTLS m_EncodeFuncArray[PROTOGTLS_MSGID_RANGE];
	DeFuncCProtoGTLS m_DecodeFuncArray[PROTOGTLS_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
