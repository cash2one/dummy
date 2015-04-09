
#ifndef _ONLINEENCOURAGEMGR_H_
#define _ONLINEENCOURAGEMGR_H_

#include <sdsingleton.h>
#include <sdtype.h>
#include <sddb.h>
#include <logic/instance/instance.h>
#include <logic/base/burstprop.h>
#include <logic/base/basepropmgr.h>

#include "onlineencouragerecord.h"

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdmutex.h>

using namespace std;
using namespace SGDP;

//���߽�����ֻ��ǰ3�죨���䣩��ÿ����ȡ���и�CDʱ��
struct SOnlineEncourageProp
{
	SOnlineEncourageProp() { wRecvCD = 0; memset(&stDT_ONLINE_ENCOURAGE_DATA, 0, sizeof(stDT_ONLINE_ENCOURAGE_DATA)); }
		
	DT_ONLINE_ENCOURAGE_DATA stDT_ONLINE_ENCOURAGE_DATA;//����
	UINT16 wRecvCD;//���ν�����ȡCD(��λ��)
};

typedef vector <SOnlineEncourageProp> COnlineEncouragePropVec;
typedef COnlineEncouragePropVec::iterator COnlineEncouragePropVecItr;

class COnlineEncourageMgr : public CBasePopMgr
{
public:

	DECLARE_SINGLETON_PROPMGR(COnlineEncourageMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_ONLINE_ENC ; }
	BOOL Init();
	VOID UnInit();

public:	
	SOnlineEncourageProp* GetEncourage(UINT8 byIdx);
	UINT8 GetMaxPerDay() { return m_byMaxPerDay; }

public:
	COnlineEncourageMgr();
	virtual ~COnlineEncourageMgr();

protected:
	BOOL LoadFromDB();
	BOOL ParseItem(UINT8& byItemNum, DT_ITEM_DATA_CLI astItemInfoList[MAX_ENCOURAGE_ITEM_KIND_NUM], const CHAR* szInput);

//public:
//    COnlineEncourageRecord* CreateOnlineEncourageRecord();
//    VOID  RemoveOnlineEncourageRecord(COnlineEncourageRecord*);
//
//private:
//    CSDObjectPool<COnlineEncourageRecord, CSDMutex>  m_oOnlineEncourageRecordPool;

private:
	COnlineEncouragePropVec	m_vecOnlineEncourageProp;//���߽����������±�
	UINT8					m_byMaxPerDay;//ÿ�������ȡ����, Ŀǰÿ����һ����
};

#endif 
