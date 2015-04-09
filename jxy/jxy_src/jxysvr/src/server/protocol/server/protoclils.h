/*       Version Number: 3          */

#ifndef PROTOCLILS_H_INCLUDE_VERSION_3
#define PROTOCLILS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "protocommondata.h"
#include "sdtype.h"
#include "sdstring.h"
#pragma pack(push, 1)

/*Defines Begin*/
#define INFO_LEN                 512
#define MAX_EXPAND_DATA_LEN      512
#define MAX_EXPAND_FUN_NUM       10
#define EXPAND_MOBILE            1
#define AUTH_KEY                 1024
#define PROTOCLILS_MSGID_RANGE 1074
#define PROTOCLILS_MSGID_OFFSET 0
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagPKT_CLILS_LOGIN_REQ{
	tagPKT_CLILS_LOGIN_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_LOGIN_REQ)); }
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
}PKT_CLILS_LOGIN_REQ;

typedef struct tagPKT_CLILS_LOGIN_ACK{
	tagPKT_CLILS_LOGIN_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_LOGIN_ACK)); }
	UINT16           wErrCode; //�û������֤
	DT_VERSION_DATA  stVersionInfo; //�汾��Ϣ
	DT_NOTICE_DATA   stNoticeInfo; //������Ϣ
	UINT8            byOtherDeviceLoginFlag; //�Ƿ������豸��¼��
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT16           wZoneID; //��ID
	TCHAR            aszZoneName[ZONENAME_LEN]; //������
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ�����������(PlayerIDΪ0)��Ч
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
}PKT_CLILS_LOGIN_ACK;

typedef struct tagPKT_CLILS_LOGIN_EX_REQ{
	tagPKT_CLILS_LOGIN_EX_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_LOGIN_EX_REQ)); }
	UINT32           dwCliVersion; //�ͻ��˰汾��,ȡ2λС����(/100)
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT16           wZoneID; //��ID
	UINT32           dwUserID; //�û�ID
	UINT32           dwPlayerID; //���ID
	UINT16           wCareerID; //ְҵ����
	UINT8            byAuthType; //��֤����
	TCHAR            aszAuthKey[AUTH_KEY]; //��֤�ַ���
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
}PKT_CLILS_LOGIN_EX_REQ;

typedef struct tagPKT_CLILS_LOGIN_EX_ACK{
	tagPKT_CLILS_LOGIN_EX_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_LOGIN_EX_ACK)); }
	UINT16           wErrCode; //�û������֤
	DT_VERSION_DATA  stVersionInfo; //�汾��Ϣ
	DT_NOTICE_DATA   stNoticeInfo; //������Ϣ
	UINT8            byOtherDeviceLoginFlag; //�Ƿ������豸��¼��
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT16           wZoneID; //��ID
	TCHAR            aszZoneName[ZONENAME_LEN]; //������
	UINT32           dwPlayerID; //���ID
	UINT16           wCareerID; //ְҵ
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
}PKT_CLILS_LOGIN_EX_ACK;

typedef struct tagPKT_CLILS_REGISTER_REQ{
	tagPKT_CLILS_REGISTER_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_REQ)); }
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	TCHAR            aszUserPwd[USERPWD_LEN]; //����
	UINT32           dwUserID; //�ͻ��˲�����д
}PKT_CLILS_REGISTER_REQ;

typedef struct tagPKT_CLILS_REGISTER_ACK{
	tagPKT_CLILS_REGISTER_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_ACK)); }
	UINT16           wErrCode; //������
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
}PKT_CLILS_REGISTER_ACK;

typedef struct tagPKT_CLILS_BIND_REQ{
	tagPKT_CLILS_BIND_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_REQ)); }
	UINT8            byAuthType; //��֤����
	UINT32           dwPlayerID; //���ID
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	TCHAR            aszNickName[USERNAME_LEN]; //�û��ǳ�
}PKT_CLILS_BIND_REQ;

typedef struct tagPKT_CLILS_BIND_ACK{
	tagPKT_CLILS_BIND_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLILS_BIND_ACK;

typedef struct tagPKT_CLILS_BIND_EX_REQ{
	tagPKT_CLILS_BIND_EX_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_EX_REQ)); }
	UINT8            byAuthType; //��֤����
	UINT32           dwPlayerID; //���ID
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	TCHAR            aszNickName[USERNAME_LEN]; //�û��ǳ�
	UINT8            byTokenLen; //�û�TokenKey����
	UINT8            abyTokenKey[USERNAME_LEN]; //�û�TokenKey
}PKT_CLILS_BIND_EX_REQ;

typedef struct tagPKT_CLILS_BIND_EX_ACK{
	tagPKT_CLILS_BIND_EX_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_EX_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLILS_BIND_EX_ACK;

typedef struct tagPKT_CLILS_UNBIND_REQ{
	tagPKT_CLILS_UNBIND_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_UNBIND_REQ)); }
	UINT8            byAuthType; //��֤����
	UINT32           dwPlayerID; //���ID
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
}PKT_CLILS_UNBIND_REQ;

typedef struct tagPKT_CLILS_UNBIND_ACK{
	tagPKT_CLILS_UNBIND_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_UNBIND_ACK)); }
	UINT16           wErrCode; //�û������֤
}PKT_CLILS_UNBIND_ACK;

typedef struct tagPKT_CLILS_LOGOUT_REQ{
	tagPKT_CLILS_LOGOUT_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_LOGOUT_REQ)); }
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸ID
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_LOGOUT_REQ;

typedef struct tagPKT_CLILS_LOGOUT_ACK{
	tagPKT_CLILS_LOGOUT_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_LOGOUT_ACK)); }
	UINT16           wErrCode; //�û������֤
}PKT_CLILS_LOGOUT_ACK;

typedef struct tagPKT_CLILS_CHANGE_PWD_REQ{
	tagPKT_CLILS_CHANGE_PWD_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_CHANGE_PWD_REQ)); }
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT8            byNewPwdLen; //�����볤��
	UINT8            abyNewUserPwd[USERNAME_LEN]; //������
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_CHANGE_PWD_REQ;

typedef struct tagPKT_CLILS_CHANGE_PWD_ACK{
	tagPKT_CLILS_CHANGE_PWD_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_CHANGE_PWD_ACK)); }
	UINT16           wErrCode; //�û������֤
}PKT_CLILS_CHANGE_PWD_ACK;

typedef struct tagPKT_CLILS_BIND_MOBILE_REQ{
	tagPKT_CLILS_BIND_MOBILE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_MOBILE_REQ)); }
	UINT8            abyMObile[MAX_MOBILE_LENGTH]; //�û��ֻ���
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_BIND_MOBILE_REQ;

typedef struct tagPKT_CLILS_BIND_MOBILE_ACK{
	tagPKT_CLILS_BIND_MOBILE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_MOBILE_ACK)); }
	UINT16           wErrCode; //�û������֤
	UINT16           wCountdown; //����ʱ
}PKT_CLILS_BIND_MOBILE_ACK;

typedef struct tagPKT_CLILS_BIND_CHECK_VER_CODE_REQ{
	tagPKT_CLILS_BIND_CHECK_VER_CODE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_CHECK_VER_CODE_REQ)); }
	UINT8            abyVerCode[MAX_MOBILE_LENGTH]; //��֤��
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_BIND_CHECK_VER_CODE_REQ;

typedef struct tagPKT_CLILS_BIND_CHECK_VER_CODE_ACK{
	tagPKT_CLILS_BIND_CHECK_VER_CODE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_BIND_CHECK_VER_CODE_ACK)); }
	UINT16           wErrCode; //�û������֤
	UINT8            abyMObile[MAX_MOBILE_LENGTH]; //�û��ֻ���
}PKT_CLILS_BIND_CHECK_VER_CODE_ACK;

typedef struct tagPKT_CLILS_UNBIND_MOBILE_REQ{
	tagPKT_CLILS_UNBIND_MOBILE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_UNBIND_MOBILE_REQ)); }
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_UNBIND_MOBILE_REQ;

typedef struct tagPKT_CLILS_UNBIND_MOBILE_ACK{
	tagPKT_CLILS_UNBIND_MOBILE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_UNBIND_MOBILE_ACK)); }
	UINT16           wErrCode; //�û������֤
	UINT16           wCountdown; //����ʱ
}PKT_CLILS_UNBIND_MOBILE_ACK;

typedef struct tagPKT_CLILS_UNBIND_CHECK_VER_CODE_REQ{
	tagPKT_CLILS_UNBIND_CHECK_VER_CODE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_UNBIND_CHECK_VER_CODE_REQ)); }
	UINT8            abyVerCode[MAX_MOBILE_LENGTH]; //��֤��
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_UNBIND_CHECK_VER_CODE_REQ;

typedef struct tagPKT_CLILS_UNBIND_CHECK_VER_CODE_ACK{
	tagPKT_CLILS_UNBIND_CHECK_VER_CODE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_UNBIND_CHECK_VER_CODE_ACK)); }
	UINT16           wErrCode; //�û������֤
}PKT_CLILS_UNBIND_CHECK_VER_CODE_ACK;

typedef struct tagDT_EXPAND_FUNC_PARAM{
	UINT8            byExpandType; //��չ����
	UINT8            byExpandLen; //��չ����
	UINT8            abyExpandData[MAX_EXPAND_DATA_LEN]; //����3
}DT_EXPAND_FUNC_PARAM;

typedef struct tagDT_EXPAND_FUNC_PARAM_LST{
	UINT8            byExpandNum; //��չ������
	DT_EXPAND_FUNC_PARAM astExpandFuncParaInfo[MAX_EXPAND_FUN_NUM]; //��չ������Ϣ
}DT_EXPAND_FUNC_PARAM_LST;

typedef struct tagPKT_CLILS_GET_USER_EXPAND_REQ{
	tagPKT_CLILS_GET_USER_EXPAND_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_GET_USER_EXPAND_REQ)); }
	UINT32           dwUserID; //�û�ID
}PKT_CLILS_GET_USER_EXPAND_REQ;

typedef struct tagPKT_CLILS_GET_USER_EXPAND_ACK{
	tagPKT_CLILS_GET_USER_EXPAND_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_GET_USER_EXPAND_ACK)); }
	UINT16           wErrCode; //������
	DT_EXPAND_FUNC_PARAM_LST stExpandFuncParaLst; //�û���չ��Ϣ
}PKT_CLILS_GET_USER_EXPAND_ACK;

/*Define Structs and Unions        End*/


enum EN_ProtoCliLS_MessageID
{
	CLILS_LOGIN_REQ                 = 1050        ,
	CLILS_LOGIN_ACK                 = 1051        ,
	CLILS_REGISTER_REQ              = 1052        ,
	CLILS_REGISTER_ACK              = 1053        ,
	CLILS_BIND_REQ                  = 1054        ,
	CLILS_BIND_ACK                  = 1055        ,
	CLILS_UNBIND_REQ                = 1056        ,
	CLILS_UNBIND_ACK                = 1057        ,
	CLILS_LOGIN_EX_REQ              = 1058        ,
	CLILS_LOGIN_EX_ACK              = 1059        ,
	CLILS_LOGOUT_REQ                = 1060        ,
	CLILS_LOGOUT_ACK                = 1061        ,
	CLILS_CHANGE_PWD_REQ            = 1062        ,
	CLILS_CHANGE_PWD_ACK            = 1063        ,
	CLILS_BIND_MOBILE_REQ           = 1064        ,
	CLILS_BIND_MOBILE_ACK           = 1065        ,
	CLILS_BIND_CHECK_VER_CODE_REQ   = 1066        ,
	CLILS_BIND_CHECK_VER_CODE_ACK   = 1067        ,
	CLILS_UNBIND_MOBILE_REQ         = 1068        ,
	CLILS_UNBIND_MOBILE_ACK         = 1069        ,
	CLILS_UNBIND_CHECK_VER_CODE_REQ  = 1070        ,
	CLILS_UNBIND_CHECK_VER_CODE_ACK  = 1071        ,
	CLILS_GET_USER_EXPAND_REQ       = 1072        ,
	CLILS_GET_USER_EXPAND_ACK       = 1073        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodePKT_CLILS_LOGIN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_LOGIN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_LOGIN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_LOGIN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_LOGIN_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_LOGIN_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_LOGIN_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_LOGIN_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_REGISTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_REGISTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_UNBIND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_UNBIND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_UNBIND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_UNBIND_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_LOGOUT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_LOGOUT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_LOGOUT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_LOGOUT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_CHANGE_PWD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_CHANGE_PWD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_CHANGE_PWD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_CHANGE_PWD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_MOBILE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_MOBILE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_MOBILE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_MOBILE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_CHECK_VER_CODE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_CHECK_VER_CODE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_BIND_CHECK_VER_CODE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_BIND_CHECK_VER_CODE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_UNBIND_MOBILE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_UNBIND_MOBILE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_UNBIND_MOBILE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_UNBIND_MOBILE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_UNBIND_CHECK_VER_CODE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_UNBIND_CHECK_VER_CODE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_UNBIND_CHECK_VER_CODE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_UNBIND_CHECK_VER_CODE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EXPAND_FUNC_PARAM(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXPAND_FUNC_PARAM(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EXPAND_FUNC_PARAM_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXPAND_FUNC_PARAM_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_GET_USER_EXPAND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_GET_USER_EXPAND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_GET_USER_EXPAND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_GET_USER_EXPAND_ACK(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoCliLS)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoCliLS)(void *pHost, CNetData* poNetData);

class CProtoCliLS : public CSDProtocol
{
public:
    static CProtoCliLS * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoCliLS FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoCliLS FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoCliLS();
	virtual ~CProtoCliLS();
	EnFuncCProtoCliLS m_EncodeFuncArray[PROTOCLILS_MSGID_RANGE];
	DeFuncCProtoCliLS m_DecodeFuncArray[PROTOCLILS_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
