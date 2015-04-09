/*       Version Number: 3          */

#ifndef PROTOGSGS_H_INCLUDE_VERSION_3
#define PROTOGSGS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "sdtype.h"
#include "sdstring.h"
#pragma pack(push, 1)

/*Defines Begin*/
#define MAX_PLAYER_DATA_LEN      900000
#define DEVICEID_LEN2            41
#define NOTIFYID_LEN2            65
#define USERNAME_LEN2            41
#define MAX_SYNC_DSPNAME_ONCE    100
#define PROTOGSGS_MSGID_RANGE 9
#define PROTOGSGS_MSGID_OFFSET 1250
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagPKT_GSGS_START_SYNC_PLAYER_RPT{
	tagPKT_GSGS_START_SYNC_PLAYER_RPT() { memset(this, 0, sizeof(tagPKT_GSGS_START_SYNC_PLAYER_RPT)); }
	UINT64           qwServerStartTime; //������ʱ��
}PKT_GSGS_START_SYNC_PLAYER_RPT;

typedef struct tagDT_USER_DATA{
	TCHAR            aszDeviceID[DEVICEID_LEN2]; //�豸��
	TCHAR            aszNotifyID[NOTIFYID_LEN2]; //֪ͨ��
	TCHAR            aszUserName[USERNAME_LEN2]; //�û���
	UINT16           wZoneID; //��ID
	UINT16           wOriZoneID; //��Ҵ�����ɫʱ���ڵ���ID
	UINT32           dwUserID; //�û�ID
	UINT32           dwPlayerID; //���ID
	UINT16           wCareerID; //ְҵ������Ϸ��Ч
	UINT32           dwLoginIP; //��¼IP
	UINT32           dwCliVer; //�ͻ��˰汾
	UINT8            byAuthType; //��֤����
}DT_USER_DATA;

typedef struct tagPKT_GSGS_SYNC_PLAYER_REQ{
	tagPKT_GSGS_SYNC_PLAYER_REQ() { memset(this, 0, sizeof(tagPKT_GSGS_SYNC_PLAYER_REQ)); }
	UINT32           dwPlayerDataLen; //������ݳ���
	UINT8            abyPlayerDataInfo[MAX_PLAYER_DATA_LEN]; //���������Ϣ
	UINT8            byHaveUserFlag; //�Ƿ���User��Ϣ
	DT_USER_DATA     astUserInfo[1]; //User��Ϣ(ԴGS������)
}PKT_GSGS_SYNC_PLAYER_REQ;

typedef struct tagPKT_GSGS_SYNC_PLAYER_RPT{
	tagPKT_GSGS_SYNC_PLAYER_RPT() { memset(this, 0, sizeof(tagPKT_GSGS_SYNC_PLAYER_RPT)); }
	UINT16           wErrCode; //�����룬 0�ɹ�����0����
	UINT32           dwPlayerID; //���ID
}PKT_GSGS_SYNC_PLAYER_RPT;

typedef struct tagDT_PLAYER_DSPNAME_DATA{
	UINT32           dwPlayerID; //ID
	TCHAR            aszDspName[USERNAME_LEN2]; //�ǳ�
}DT_PLAYER_DSPNAME_DATA;

typedef struct tagPKT_GSGS_SYNC_DSPNAME_REQ{
	tagPKT_GSGS_SYNC_DSPNAME_REQ() { memset(this, 0, sizeof(tagPKT_GSGS_SYNC_DSPNAME_REQ)); }
	UINT16           wSyncNum; //������ݳ���
	DT_PLAYER_DSPNAME_DATA astPlayerDspNameInfo[MAX_SYNC_DSPNAME_ONCE]; //���������Ϣ
}PKT_GSGS_SYNC_DSPNAME_REQ;

typedef struct tagPKT_GSGS_SYNC_DSPNAME_RPT{
	tagPKT_GSGS_SYNC_DSPNAME_RPT() { memset(this, 0, sizeof(tagPKT_GSGS_SYNC_DSPNAME_RPT)); }
	UINT16           wErrCode; //�����룬 0�ɹ�����0����
	UINT32           dwLastPlayerID; //���1��ID
}PKT_GSGS_SYNC_DSPNAME_RPT;

typedef struct tagPKT_GSGS_SYNC_BOSSB_REQ{
	tagPKT_GSGS_SYNC_BOSSB_REQ() { memset(this, 0, sizeof(tagPKT_GSGS_SYNC_BOSSB_REQ)); }
	UINT8            byActivityID; //BOSSս�ID
	UINT64           qwCurHP; //BOSSѪ��
	UINT64           qwStartTime; //���ʼʱ��
}PKT_GSGS_SYNC_BOSSB_REQ;

typedef struct tagPKT_GSGS_SYNC_BOSSB_RPT{
	tagPKT_GSGS_SYNC_BOSSB_RPT() { memset(this, 0, sizeof(tagPKT_GSGS_SYNC_BOSSB_RPT)); }
	UINT16           wErrCode; //�����룬 0�ɹ�����0����
}PKT_GSGS_SYNC_BOSSB_RPT;

/*Define Structs and Unions        End*/


enum EN_ProtoGSGS_MessageID
{
	GSGS_START_SYNC_PLAYER_RPT      = 1250        ,
	GSGS_SYNC_PLAYER_REQ            = 1252        ,
	GSGS_SYNC_PLAYER_RPT            = 1254        ,
	GSGS_SYNC_DSPNAME_REQ           = 1255        ,
	GSGS_SYNC_DSPNAME_RPT           = 1256        ,
	GSGS_SYNC_BOSSB_REQ             = 1257        ,
	GSGS_SYNC_BOSSB_RPT             = 1258        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodePKT_GSGS_START_SYNC_PLAYER_RPT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_START_SYNC_PLAYER_RPT(void *pHost, CNetData* poNetData);
INT32 EncodeDT_USER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_USER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGS_SYNC_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_SYNC_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGS_SYNC_PLAYER_RPT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_SYNC_PLAYER_RPT(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_DSPNAME_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_DSPNAME_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGS_SYNC_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_SYNC_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGS_SYNC_DSPNAME_RPT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_SYNC_DSPNAME_RPT(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGS_SYNC_BOSSB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_SYNC_BOSSB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGS_SYNC_BOSSB_RPT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGS_SYNC_BOSSB_RPT(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoGSGS)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoGSGS)(void *pHost, CNetData* poNetData);

class CProtoGSGS : public CSDProtocol
{
public:
    static CProtoGSGS * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoGSGS FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoGSGS FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoGSGS();
	virtual ~CProtoGSGS();
	EnFuncCProtoGSGS m_EncodeFuncArray[PROTOGSGS_MSGID_RANGE];
	DeFuncCProtoGSGS m_DecodeFuncArray[PROTOGSGS_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
