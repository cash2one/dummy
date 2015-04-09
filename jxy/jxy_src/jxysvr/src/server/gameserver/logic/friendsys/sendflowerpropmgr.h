#ifndef _SEND_FLOWER_PROPMGR_H_
#define _SEND_FLOWER_PROPMGR_H_

#include <sdtype.h>
#include <sdhashmap.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>
#include <dll/sdu/sdobjectpool.h>

#include "friends.h"
#include "logic/base/jsonencourage.h"

using namespace SGDP;

struct tagDT_SEND_FLOWER_PROP_LIST_CLI;
typedef tagDT_SEND_FLOWER_PROP_LIST_CLI DT_SEND_FLOWER_PROP_LIST_CLI;

// ���ʻ�����
struct SSendFlowerProp
{
    UINT32 dwFlowerNum; // �ʻ�����
    UINT16 wSendMaxTimes; // ʹ�ô���
    UINT8  byNeedVipLvl; // ��Ҫ��Vip�ȼ�
    UINT16 wCostKindID; // ���ѵ���Դ����(1ͭǮ��2Ԫ��)
    UINT32 dwCostKindIDNum; // ���ѵ���Դ����
    UINT16 wGetKindID; // ��õ���Դ����
    UINT32 dwGetKindIDNum; // ��õ���Դ����
};


typedef map<UINT32, SSendFlowerProp> CSendFlowerPropMap; // keyΪ�ʻ�������
typedef CSendFlowerPropMap::iterator CSendFlowerPropMapIter;

typedef struct _tagSendFlowerEncourage
{
    _tagSendFlowerEncourage()
    {
        dwFlowerNum = 0;
    }
    UINT32				dwFlowerNum;
    CJsonResItemVectorInfo	vecJsonEncourageItemInfo;
} SSendFlowerEncourage;

typedef vector<SSendFlowerEncourage> CSendFlowerPropVector; // keyΪ�ʻ�������
typedef CSendFlowerPropVector::iterator CSendFlowerPropVectorItr;
typedef CSendFlowerPropVector::reverse_iterator CSendFlowerPropVectorRItr;



typedef struct _tagRecvFlowerEncourage
{
    _tagRecvFlowerEncourage()
    {
        wKindID = 0;
    }
    UINT32				wKindID;
    CJsonResItemVectorInfo	vecJsonEncourageItemInfo;
} SRecvFlowerEncourage;

typedef vector<SRecvFlowerEncourage> CRecvFlowerPropVector; // keyΪ�ʻ�������
typedef CRecvFlowerPropVector::iterator CRecvFlowerPropVectorItr;


class CSendFlowerMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CSendFlowerMgr);

public:
    virtual EConfigModule GetConfigModuleType()
    {
        return ECM_SENDFLOWER;
    }

    BOOL Init();

    VOID UnInit();

public:
    CSendFlowerPropMap& GetSendFlowerPropMap()
    {
        return m_mapSendFlowerPropMap;
    }

	CRecvFlowerPropVector& GetCRecvFlowerPropVector()
	{
		return m_vecRecvFlowerProp;
	}

    // ��ȡ���ʻ������б�(for �����ʻ����)
    UINT16 GetSendFlowerProp(DT_SEND_FLOWER_PROP_LIST_CLI& stSendFlowerPropList);

	SSendFlowerEncourage *GetSendFlowerEncourage(UINT32	dwFlowerNum);

	SSendFlowerEncourage *GetNextSendFlowerEncourage(UINT32 dwFlowerNum, UINT32 &dwNextFlowerNum);

	SRecvFlowerEncourage *GetRecvFlowerEncourage(UINT16	wKindID);

	SSendFlowerEncourage *GetMaxSendFlowerEncourage();

public:
    CSendFlowerMgr();
    virtual ~CSendFlowerMgr();

protected:
    BOOL LoadSendFlowerPropFromDB();

private:
    CSendFlowerPropMap	m_mapSendFlowerPropMap; // ���ʻ�����

    CSendFlowerPropVector m_vecSendFlowerProp;

    CRecvFlowerPropVector m_vecRecvFlowerProp;
};

#endif // 




