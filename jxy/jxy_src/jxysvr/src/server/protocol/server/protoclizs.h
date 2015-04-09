/*       Version Number: 3          */

#ifndef PROTOCLIZS_H_INCLUDE_VERSION_3
#define PROTOCLIZS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "protocommondata.h"
#include "sdtype.h"
#include "sdstring.h"
#pragma pack(push, 1)

/*Defines Begin*/
#define ENDEC_KEY_LEN            32
#define INFO_LEN                 512
#define MAX_PLAYER_NUM_PER_ZONE  9
#define MAX_DOMAIN_NAME_LEN      128
#define MAX_USER_INFO_NUM        32
#define MAX_USER_DEVIDE_INFO_LEN 1024
#define MAX_INFO_NUM             128
#define MAX_RESET_PASSWD_TOKEN_NUM 128
#define MAX_ZONE_NUM             255
#define PROTOCLIZS_MSGID_RANGE 1030
#define PROTOCLIZS_MSGID_OFFSET 0
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagPKT_CLIZS_ENDEC_KEY_NTF{
	tagPKT_CLIZS_ENDEC_KEY_NTF() { memset(this, 0, sizeof(tagPKT_CLIZS_ENDEC_KEY_NTF)); }
	UINT8            abyKeyInfo[ENDEC_KEY_LEN]; //�ӽ�����Կ
}PKT_CLIZS_ENDEC_KEY_NTF;

typedef struct tagPKT_CLIZS_GET_ZONE_INFO_REQ{
	tagPKT_CLIZS_GET_ZONE_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_ZONE_INFO_REQ)); }
	UINT16           wID; //�ӽ�����Կ
}PKT_CLIZS_GET_ZONE_INFO_REQ;

typedef struct tagPKT_CLIZS_GET_ZONE_INFO_ACK{
	tagPKT_CLIZS_GET_ZONE_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_ZONE_INFO_ACK)); }
	UINT32           dwErrCode; //������
	UINT8            byDomainLen; //��������
	UINT8            abyDomainName[MAX_DOMAIN_NAME_LEN]; //����
	UINT16           wZonePort; //�˿�
}PKT_CLIZS_GET_ZONE_INFO_ACK;

typedef struct tagDT_ZONE_PLAYER_DATA{
	UINT32           dwPlayerID; //���ID
	UINT8            byPlayerCareer; //���ְҵ
	UINT16           wPlayerLevel; //��ҵȼ�
	TCHAR            aszPlayerDspName[USERNAME_LEN]; //������
}DT_ZONE_PLAYER_DATA;

typedef struct tagDT_ZONE_DATA{
	UINT16           wID; //��ID
	UINT8            byDomainLen; //��������
	UINT8            abyDomainName[MAX_DOMAIN_NAME_LEN]; //����
	UINT16           wZonePort; //�˿�
	TCHAR            aszZoneName[USERNAME_LEN]; //ѡ������
	UINT8            byBusyFlag; //����æ�̶�(0������1��æ��2��, 3�ܾ�����,4ά����)
	UINT8            byPlayerNum; //��Ҹ���
	DT_ZONE_PLAYER_DATA astPlayerInfo[MAX_PLAYER_NUM_PER_ZONE]; //��Ҹ���
}DT_ZONE_DATA;

typedef struct tagPKT_CLIGT_SELECT_ZONE_REQ{
	tagPKT_CLIGT_SELECT_ZONE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGT_SELECT_ZONE_REQ)); }
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT16           wZoneIdx; //��������������
	UINT8            byAuthMethod; //��֤��ʽ
	TCHAR            aszNickName[USERNAME_LEN]; //�û��ǳ�
	UINT8            byBindType; //������ 0�����󶨣� 1����
	UINT32           dwCliVersion; //�ͻ��˰汾��,ȡ2λС����(/100)
}PKT_CLIGT_SELECT_ZONE_REQ;

typedef struct tagPKT_CLIGT_SELECT_ZONE_ACK{
	tagPKT_CLIGT_SELECT_ZONE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGT_SELECT_ZONE_ACK)); }
	UINT16           wErrCode; //�ӽ�����Կ
	UINT8            byZoneNum; //�ӽ�����Կ
	DT_ZONE_DATA     astZoneList[MAX_ZONE_NUM]; //�ӽ�����Կ
}PKT_CLIGT_SELECT_ZONE_ACK;

typedef struct tagPKT_CLIGT_SELECT_ZONE_EX_REQ{
	tagPKT_CLIGT_SELECT_ZONE_EX_REQ() { memset(this, 0, sizeof(tagPKT_CLIGT_SELECT_ZONE_EX_REQ)); }
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT16           wZoneIdx; //��������������
	UINT8            byAuthMethod; //��֤��ʽ
	TCHAR            aszNickName[USERNAME_LEN]; //�û��ǳ�
}PKT_CLIGT_SELECT_ZONE_EX_REQ;

typedef struct tagPKT_CLIGT_SELECT_ZONE_EX_ACK{
	tagPKT_CLIGT_SELECT_ZONE_EX_ACK() { memset(this, 0, sizeof(tagPKT_CLIGT_SELECT_ZONE_EX_ACK)); }
	UINT16           wErrCode; //�ӽ�����Կ
	UINT8            byZoneNum; //�ӽ�����Կ
	DT_ZONE_DATA     astZoneList[GET_ZONE_NUM]; //�ӽ�����Կ
}PKT_CLIGT_SELECT_ZONE_EX_ACK;

typedef struct tagPKT_CLIGT_SELECT_ZONE_EX2_REQ{
	tagPKT_CLIGT_SELECT_ZONE_EX2_REQ() { memset(this, 0, sizeof(tagPKT_CLIGT_SELECT_ZONE_EX2_REQ)); }
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸��
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	UINT8            byPwdLen; //���볤��
	UINT8            abyUserPwd[USERNAME_LEN]; //����
	UINT16           wZoneIdx; //��������������
	UINT8            byAuthMethod; //��֤��ʽ
	TCHAR            aszNickName[USERNAME_LEN]; //�û��ǳ�
	UINT8            byBindType; //������ 0�����󶨣� 1����
}PKT_CLIGT_SELECT_ZONE_EX2_REQ;

typedef struct tagPKT_CLIGT_SELECT_ZONE_EX2_ACK{
	tagPKT_CLIGT_SELECT_ZONE_EX2_ACK() { memset(this, 0, sizeof(tagPKT_CLIGT_SELECT_ZONE_EX2_ACK)); }
	UINT16           wErrCode; //�ӽ�����Կ
	UINT8            byZoneNum; //�ӽ�����Կ
	DT_ZONE_DATA     astZoneList[GET_ZONE_NUM]; //�ӽ�����Կ
}PKT_CLIGT_SELECT_ZONE_EX2_ACK;

typedef struct tagPKT_CLIGT_FIND_ZONE_REQ{
	tagPKT_CLIGT_FIND_ZONE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGT_FIND_ZONE_REQ)); }
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�ӽ�����Կ
	TCHAR            aszUserName[USERNAME_LEN]; //�ӽ�����Կ
	TCHAR            aszUserPwd[USERPWD_LEN]; //�ӽ�����Կ
	TCHAR            aszZoneName[USERNAME_LEN]; //�ӽ�����Կ
}PKT_CLIGT_FIND_ZONE_REQ;

typedef struct tagPKT_CLIGT_FIND_ZONE_ACK{
	tagPKT_CLIGT_FIND_ZONE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGT_FIND_ZONE_ACK)); }
	UINT16           wErrCode; //�ӽ�����Կ
	UINT8            byZoneNum; //�ӽ�����Կ
	DT_ZONE_DATA     astZoneList[GET_ZONE_NUM]; //�ӽ�����Կ
}PKT_CLIGT_FIND_ZONE_ACK;

typedef struct tagPKT_CLIZS_GET_VERSION_NOTICE_REQ{
	tagPKT_CLIZS_GET_VERSION_NOTICE_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_VERSION_NOTICE_REQ)); }
	UINT32           dwCliVersion; //�ͻ��˰汾��,ȡ2λС����(/100)
}PKT_CLIZS_GET_VERSION_NOTICE_REQ;

typedef struct tagPKT_CLIZS_GET_VERSION_NOTICE_ACK{
	tagPKT_CLIZS_GET_VERSION_NOTICE_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_VERSION_NOTICE_ACK)); }
	DT_VERSION_DATA  stVersionInfo; //�汾��Ϣ
	DT_NOTICE_DATA   stNoticeInfo; //������Ϣ
}PKT_CLIZS_GET_VERSION_NOTICE_ACK;

typedef struct tagPKT_CLIZS_GET_USERINFO_REQ{
	tagPKT_CLIZS_GET_USERINFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_USERINFO_REQ)); }
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸ID
}PKT_CLIZS_GET_USERINFO_REQ;

typedef struct tagDT_USERINFO{
	UINT8            byType; //�û�����
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	TCHAR            aszNickName[USERNAME_LEN]; //�û��ǳ�
}DT_USERINFO;

typedef struct tagPKT_CLIZS_GET_USERINFO_ACK{
	tagPKT_CLIZS_GET_USERINFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_USERINFO_ACK)); }
	UINT32           dwErrCode; //������
	UINT8            byNum; //�û���Ϣ����
	DT_USERINFO      astUserInfo[MAX_USER_INFO_NUM]; //����
}PKT_CLIZS_GET_USERINFO_ACK;

typedef struct tagPKT_CLIZS_REGISTER_USERNAME_REQ{
	tagPKT_CLIZS_REGISTER_USERNAME_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_REGISTER_USERNAME_REQ)); }
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸ID
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
	TCHAR            aszUserPwd[USERPWD_LEN]; //����
}PKT_CLIZS_REGISTER_USERNAME_REQ;

typedef struct tagPKT_CLIZS_REGISTER_USERNAME_ACK{
	tagPKT_CLIZS_REGISTER_USERNAME_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_REGISTER_USERNAME_ACK)); }
	UINT16           wErrCode; //�ӽ�����Կ
}PKT_CLIZS_REGISTER_USERNAME_ACK;

typedef struct tagPKT_CLIZS_REPORT_USER_DEVICE_INFO_REQ{
	tagPKT_CLIZS_REPORT_USER_DEVICE_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_REPORT_USER_DEVICE_INFO_REQ)); }
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸ID
	TCHAR            aszPlatform[MAX_INFO_NUM]; //��װƽ̨
	TCHAR            aszGameVersion[MAX_INFO_NUM]; //��Ϸ�汾��
	TCHAR            aszOSType[MAX_INFO_NUM]; //ϵͳ����
	TCHAR            aszOSVersion[MAX_INFO_NUM]; //ϵͳ�汾
	TCHAR            aszHardwareVersion[MAX_INFO_NUM]; //Ӳ��ƽ̨
	TCHAR            aszExtInfo[MAX_USER_DEVIDE_INFO_LEN]; //��չ��Ϣ
}PKT_CLIZS_REPORT_USER_DEVICE_INFO_REQ;

typedef struct tagPKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK{
	tagPKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK;

typedef struct tagPKT_CLIZS_UN_BIND_DEVICE_REQ{
	tagPKT_CLIZS_UN_BIND_DEVICE_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_UN_BIND_DEVICE_REQ)); }
	UINT8            byAuthType; //��֤����
	TCHAR            aszDeviceID[DEVICEID_LEN]; //�豸ID
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
}PKT_CLIZS_UN_BIND_DEVICE_REQ;

typedef struct tagPKT_CLIZS_UN_BIND_DEVICE_ACK{
	tagPKT_CLIZS_UN_BIND_DEVICE_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_UN_BIND_DEVICE_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIZS_UN_BIND_DEVICE_ACK;

typedef struct tagPKT_CLIZS_GET_VERSION_NOTICE_REQ2{
	tagPKT_CLIZS_GET_VERSION_NOTICE_REQ2() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_VERSION_NOTICE_REQ2)); }
	UINT32           dwCliVersion; //�ͻ��˰汾��,ȡ2λС����(/100)
}PKT_CLIZS_GET_VERSION_NOTICE_REQ2;

typedef struct tagDT_VERSION_DATA2{
	UINT32           dwVersionID; //�汾ID,ȡ2λС����(/100)
	UINT8            byForceUpdateFlag; //�Ƿ�ǿ�Ƹ��£�1ǿ�Ƹ���
	UINT32           dwResVer; //��Դ�汾
	UINT32           dwUIVer; //UI�汾
	TCHAR            aszUpdateContent[MAX_CONTENT_SIZE]; //��������
	TCHAR            aszUpdateURL[MAX_CONTENT_SIZE]; //���µ�ַ
}DT_VERSION_DATA2;

typedef struct tagPKT_CLIZS_GET_VERSION_NOTICE_ACK2{
	tagPKT_CLIZS_GET_VERSION_NOTICE_ACK2() { memset(this, 0, sizeof(tagPKT_CLIZS_GET_VERSION_NOTICE_ACK2)); }
	DT_VERSION_DATA2 stVersionInfo; //�汾��Ϣ
	DT_NOTICE_DATA   stNoticeInfo; //������Ϣ
}PKT_CLIZS_GET_VERSION_NOTICE_ACK2;

typedef struct tagPKT_CLIZS_RESET_PASSWD_MOBILE_REQ{
	tagPKT_CLIZS_RESET_PASSWD_MOBILE_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_RESET_PASSWD_MOBILE_REQ)); }
	UINT8            abyMObile[MAX_MOBILE_LENGTH]; //�û��ֻ���
}PKT_CLIZS_RESET_PASSWD_MOBILE_REQ;

typedef struct tagPKT_CLIZS_RESET_PASSWD_MOBILE_ACK{
	tagPKT_CLIZS_RESET_PASSWD_MOBILE_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_RESET_PASSWD_MOBILE_ACK)); }
	UINT16           wErrCode; //������
	UINT8            abyToken[MAX_RESET_PASSWD_TOKEN_NUM]; //�����
	UINT16           wCountdown; //����ʱ
}PKT_CLIZS_RESET_PASSWD_MOBILE_ACK;

typedef struct tagPKT_CLIZS_RESET_PASSWD_VER_CODE_REQ{
	tagPKT_CLIZS_RESET_PASSWD_VER_CODE_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_RESET_PASSWD_VER_CODE_REQ)); }
	UINT8            abyToken[MAX_RESET_PASSWD_TOKEN_NUM]; //�����
	UINT8            abyVerCode[MAX_MOBILE_LENGTH]; //��֤��
}PKT_CLIZS_RESET_PASSWD_VER_CODE_REQ;

typedef struct tagPKT_CLIZS_RESET_PASSWD_VER_CODE_ACK{
	tagPKT_CLIZS_RESET_PASSWD_VER_CODE_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_RESET_PASSWD_VER_CODE_ACK)); }
	UINT16           wErrCode; //��֤��
	UINT16           wCountdown; //����ʱ
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
}PKT_CLIZS_RESET_PASSWD_VER_CODE_ACK;

typedef struct tagPKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ{
	tagPKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ() { memset(this, 0, sizeof(tagPKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ)); }
	UINT8            abyToken[MAX_RESET_PASSWD_TOKEN_NUM]; //�����
	UINT8            byPwdLen; //���볤��
	UINT8            abyNewPassWd[USERNAME_LEN]; //����
}PKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ;

typedef struct tagPKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK{
	tagPKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK() { memset(this, 0, sizeof(tagPKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK;

/*Define Structs and Unions        End*/


enum EN_ProtoCliZS_MessageID
{
	CLIZS_ENDEC_KEY_NTF             = 1000        ,
	CLIZS_GET_ZONE_INFO_REQ         = 1002        ,
	CLIZS_GET_ZONE_INFO_ACK         = 1003        ,
	CLIGT_SELECT_ZONE_REQ           = 1004        ,
	CLIGT_SELECT_ZONE_ACK           = 1005        ,
	CLIGT_FIND_ZONE_REQ             = 1006        ,
	CLIGT_FIND_ZONE_ACK             = 1007        ,
	CLIZS_GET_VERSION_NOTICE_REQ    = 1008        ,
	CLIZS_GET_VERSION_NOTICE_ACK    = 1009        ,
	CLIZS_GET_USERINFO_REQ          = 1010        ,
	CLIZS_GET_USERINFO_ACK          = 1011        ,
	CLIZS_REGISTER_USERNAME_REQ     = 1012        ,
	CLIZS_REGISTER_USERNAME_ACK     = 1013        ,
	CLIGT_SELECT_ZONE_EX_REQ        = 1014        ,
	CLIGT_SELECT_ZONE_EX_ACK        = 1015        ,
	CLIZS_REPORT_USER_DEVICE_INFO_REQ  = 1016        ,
	CLIZS_REPORT_USER_DEVICE_INFO_ACK  = 1017        ,
	CLIZS_UN_BIND_DEVICE_REQ        = 1018        ,
	CLIZS_UN_BIND_DEVICE_ACK        = 1019        ,
	CLIGT_SELECT_ZONE_EX2_REQ       = 1020        ,
	CLIGT_SELECT_ZONE_EX2_ACK       = 1021        ,
	CLIZS_GET_VERSION_NOTICE_REQ2   = 1022        ,
	CLIZS_GET_VERSION_NOTICE_ACK2   = 1023        ,
	CLIZS_RESET_PASSWD_MOBILE_REQ   = 1024        ,
	CLIZS_RESET_PASSWD_MOBILE_ACK   = 1025        ,
	CLIZS_RESET_PASSWD_VER_CODE_REQ  = 1026        ,
	CLIZS_RESET_PASSWD_VER_CODE_ACK  = 1027        ,
	CLIZS_RESET_PASSWD_NEWPASSWD_REQ  = 1028        ,
	CLIZS_RESET_PASSWD_NEWPASSWD_ACK  = 1029        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodePKT_CLIZS_ENDEC_KEY_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_ENDEC_KEY_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_ZONE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_ZONE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_ZONE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_ZONE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ZONE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ZONE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ZONE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ZONE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_SELECT_ZONE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_SELECT_ZONE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_SELECT_ZONE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_SELECT_ZONE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_SELECT_ZONE_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_SELECT_ZONE_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_SELECT_ZONE_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_SELECT_ZONE_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_SELECT_ZONE_EX2_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_SELECT_ZONE_EX2_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_SELECT_ZONE_EX2_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_SELECT_ZONE_EX2_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_FIND_ZONE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_FIND_ZONE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGT_FIND_ZONE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGT_FIND_ZONE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_VERSION_NOTICE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_VERSION_NOTICE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_VERSION_NOTICE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_VERSION_NOTICE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_USERINFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_USERINFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_USERINFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_USERINFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_USERINFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_USERINFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_REGISTER_USERNAME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_REGISTER_USERNAME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_REGISTER_USERNAME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_REGISTER_USERNAME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_REPORT_USER_DEVICE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_REPORT_USER_DEVICE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_REPORT_USER_DEVICE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_UN_BIND_DEVICE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_UN_BIND_DEVICE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_UN_BIND_DEVICE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_UN_BIND_DEVICE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_VERSION_NOTICE_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_VERSION_NOTICE_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_VERSION_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VERSION_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_GET_VERSION_NOTICE_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_GET_VERSION_NOTICE_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_RESET_PASSWD_MOBILE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_RESET_PASSWD_MOBILE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_RESET_PASSWD_MOBILE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_RESET_PASSWD_MOBILE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_RESET_PASSWD_VER_CODE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_RESET_PASSWD_VER_CODE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_RESET_PASSWD_VER_CODE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_RESET_PASSWD_VER_CODE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_RESET_PASSWD_NEWPASSWD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIZS_RESET_PASSWD_NEWPASSWD_ACK(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoCliZS)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoCliZS)(void *pHost, CNetData* poNetData);

class CProtoCliZS : public CSDProtocol
{
public:
    static CProtoCliZS * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoCliZS FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoCliZS FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoCliZS();
	virtual ~CProtoCliZS();
	EnFuncCProtoCliZS m_EncodeFuncArray[PROTOCLIZS_MSGID_RANGE];
	DeFuncCProtoCliZS m_DecodeFuncArray[PROTOCLIZS_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
