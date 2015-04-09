
#ifndef _PHYSTRENGTHMGR_H_
#define _PHYSTRENGTHMGR_H_

#include "phystrength.h"


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

#include <sdobjectpool.h>
#include <sdmutex.h>

//������������
struct  SBuyPhystrengthProp
{
    UINT8	byBuyPhyStrength;//���������ֵ
    //UINT8	byBuyMaxNumPerDay;//ÿ����๺�����
};

class CPlayer;
class CPhystrengthMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CPhystrengthMgr);

public:
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_PHYSTRENGTH ;
    }

    BOOL Init();

    VOID UnInit();
public:
    UINT8 GetCommonPhyStrength()
    {
        return m_byCommonPhyStrength ;
    }
    UINT8 GetElitePhyStrength()
    {
        return m_byElitePhyStrength ;
    }
    UINT16 GetPhyStrengthRefreshCD()
    {
        return m_wPhyStrengthRefreshCD;
    }
    SBuyPhystrengthProp& GetBuyPhystrengthProp()
    {
        return m_stBuyPhystrengthProp;
    }
public:
    CPhystrengthMgr();
    virtual ~CPhystrengthMgr();
protected:

    BOOL LoadFromDB();


private:
    UINT8	m_byCommonPhyStrength;//������ͨ������������
    UINT8	m_byElitePhyStrength;//���뾫Ӣ������������
    UINT16	m_wPhyStrengthRefreshCD;//�����ָ�1������ʱ��(��λ��)
    SBuyPhystrengthProp m_stBuyPhystrengthProp;//������������
};

#endif // 
