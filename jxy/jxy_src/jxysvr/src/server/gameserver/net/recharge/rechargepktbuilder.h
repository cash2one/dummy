

#ifndef _RECHARGE_PACKAGE_BUILDER_H_
#define _RECHARGE_PACKAGE_BUILDER_H_

#include "sdframework.h"
#include <protoclizs.h>
#include "rechargeclient.h"

#define PROCESS_EXCHANGE_SUCCESS 0
#define PROCESS_EXCHANGE_ORDER_ID_REPEAT 1
#define PROCESS_EXCHANGE_ORDER_ID_INVAID 2

//�����ظ�
#define APP_ORDER_ID_REPEAT 9999

class CPlayer;

class CRechargePktBuilder : public CSDPacketBuilder
{
public:
    static CRechargePktBuilder* Instance() { static CRechargePktBuilder oCliPkgBuilder; return &oCliPkgBuilder;}
protected:
    CRechargePktBuilder();
    ~CRechargePktBuilder();
public:
	UINT16 RechargeAck(tstring strRechargeAck);
	UINT16 SendHeart(); //��������
	UINT16 QueryOrderID( UINT32 dwPlayerID, const string &strDispName, UINT16 wPlayerLevel, UINT16 wZoneID, UINT32 dwUserID ); //������Ҷ���ID
	UINT16 GenGUIDAck2GT( const string &strRet, CPlayer **ppPlayerSend ); //����GUID���ɽ�������ظ��ͻ���
	VOID ProcessExchangeAck2GT( const string &strRet, CRechargeClient*poClient ); //�����ֵ�ɹ������ظ��ͻ���
	//UINT16 QueryAppOrderIDCheck( CPlayer *poPlayer, const string &strReceiptData ); //������app������
};

#endif //#ifndef _GATE_SERVER_PACKAGE_BUILDER_H_

