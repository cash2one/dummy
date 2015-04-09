/*       Version Number: 3          */

#ifndef PROTOGTGS_H_INCLUDE_VERSION_3
#define PROTOGTGS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "protocommondata.h"
#include "protogtcommon.h"
#include "protocligs.h"
#include "protogsls.h"
#include "sdtype.h"
#include "sdstring.h"
#pragma pack(push, 1)

/*Defines Begin*/
#define PROTOGTGS_MSGID_RANGE 3194
#define PROTOGTGS_MSGID_OFFSET 0
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagPKT_GSGT_CLR_CACHE_RPT{
	tagPKT_GSGT_CLR_CACHE_RPT() { memset(this, 0, sizeof(tagPKT_GSGT_CLR_CACHE_RPT)); }
	UINT8            byExt; //��չ�ֶΣ�0Ϊ״̬�ж��Ƿ����µ�¼��1Ϊǿ��������
}PKT_GSGT_CLR_CACHE_RPT;

typedef struct tagPKT_GSGT_REGISTER_USERNAME_REQ{
	tagPKT_GSGT_REGISTER_USERNAME_REQ() { memset(this, 0, sizeof(tagPKT_GSGT_REGISTER_USERNAME_REQ)); }
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
}PKT_GSGT_REGISTER_USERNAME_REQ;

typedef struct tagPKT_GSGT_REGISTER_USERNAME_ACK{
	tagPKT_GSGT_REGISTER_USERNAME_ACK() { memset(this, 0, sizeof(tagPKT_GSGT_REGISTER_USERNAME_ACK)); }
	UINT16           wErrCode; //������
	TCHAR            aszUserName[USERNAME_LEN]; //�û���
}PKT_GSGT_REGISTER_USERNAME_ACK;

typedef struct tagPKT_GTGS_ENTERGS_REQ{
	tagPKT_GTGS_ENTERGS_REQ() { memset(this, 0, sizeof(tagPKT_GTGS_ENTERGS_REQ)); }
	TCHAR            aszDeviceID[41]; //�豸��
	TCHAR            aszNotifyID[65]; //֪ͨ��
	TCHAR            aszUserName[41]; //�û���
	UINT16           wZoneID; //��ID
	UINT16           wOriZoneID; //���ԭ�����ڵ���������Ҵ�����ɫʱ���ڵ����������ID�����ڲ����ģ�
	UINT32           dwUserID; //�û�ID
	UINT32           dwPlayerID; //���ID
	UINT16           wCareerID; //ְҵ������Ϸ��Ч
	UINT32           dwLoginIP; //��¼IP
	UINT32           dwCliVer; //�ͻ��˰汾
	UINT8            byAuthType; //��֤����
	UINT8            byDaiChong; //�����־
}PKT_GTGS_ENTERGS_REQ;

typedef struct tagPKT_GSGT_KICK_OUT_REQ{
	tagPKT_GSGT_KICK_OUT_REQ() { memset(this, 0, sizeof(tagPKT_GSGT_KICK_OUT_REQ)); }
	UINT32           dwPlayerID; //PlayerID
	UINT8            byKickOutType; //T�������� 0ΪGM 1���ڻص�
}PKT_GSGT_KICK_OUT_REQ;

typedef struct tagPKT_GSGT_KICK_OUT_ACK{
	tagPKT_GSGT_KICK_OUT_ACK() { memset(this, 0, sizeof(tagPKT_GSGT_KICK_OUT_ACK)); }
	TCHAR            aszErrMsg[128]; //������Ϣ
}PKT_GSGT_KICK_OUT_ACK;

/*Define Structs and Unions        End*/


enum EN_ProtoGTGS_MessageID
{
	GSGT_CLR_CACHE_RPT              = 1300        ,
	GSGT_REGISTER_USERNAME_REQ      = 1302        ,
	GSGT_REGISTER_USERNAME_ACK      = 1303        ,
	GTGS_ENTERGS_REQ                = 1304        ,
	GSGT_KICK_OUT_REQ               = 1306        ,
	GSGT_KICK_OUT_ACK               = 1307        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodePKT_GSGT_CLR_CACHE_RPT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGT_CLR_CACHE_RPT(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGT_REGISTER_USERNAME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGT_REGISTER_USERNAME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGT_REGISTER_USERNAME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGT_REGISTER_USERNAME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GTGS_ENTERGS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GTGS_ENTERGS_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGT_KICK_OUT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGT_KICK_OUT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_GSGT_KICK_OUT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_GSGT_KICK_OUT_ACK(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoGTGS)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoGTGS)(void *pHost, CNetData* poNetData);

class CProtoGTGS : public CSDProtocol
{
public:
    static CProtoGTGS * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoGTGS FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoGTGS FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoGTGS();
	virtual ~CProtoGTGS();
	EnFuncCProtoGTGS m_EncodeFuncArray[PROTOGTGS_MSGID_RANGE];
	DeFuncCProtoGTGS m_DecodeFuncArray[PROTOGTGS_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
