#ifndef _RECHARGE_H_
#define _RECHARGE_H_

#include <sdbase.h>
#include <string>

using namespace std;
using namespace SGDP;


//��ֵ����������
enum ERechargeErrCode
{
	EREC_SUCCESS = 0,  //�ɹ�
	EREC_TIMEOUT = 1, //��ʱ
	EREC_INVALID_CHART = 2, //������Ч�ַ�
	EREC_INNERR = 3, //�ڲ�����
};



//��ֵ��Դ����
enum ERechargeFromType
{
	ERFT_TONGBU = 1, //ͬ��
	ERFT_PP = 2, //PP����
};


class CRechargeClient
{
public:
	virtual	VOID SDAPI	OnRechargeSuccess()=0;	
	virtual	VOID SDAPI	OnRechargeFailed(UINT16 wErrCode, TCHAR* pszErrCode)=0;
};


class CRechargeClientMgr
{
public:
	virtual CRechargeClient* SDAPI FindClient(UINT32 dwTransID) = 0;
};

class CRechargeModule
{
public:

	virtual BOOL SDAPI Init(const CHAR* pszModuleName, const CHAR* pszConfig, CRechargeClientMgr* poRechargeClientMgr) = 0;

	virtual BOOL SDAPI Recharge(UINT32 dwTransID, string strOrderInfo) = 0;

	virtual BOOL SDAPI Run(INT32 nCount = -1) = 0;

	virtual VOID SDAPI Release(VOID) = 0;
};

extern "C" CRechargeModule* SDAPI GetRechargeModule(void);

	
#endif 
