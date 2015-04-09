
#ifndef _WORSHIPPROPMGR_H_
#define _WORSHIPPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>
#include <map>

using namespace std;

struct SWorshipProp
{
	UINT8	byWorshipType;//Ĥ������
	UINT8	byWorshipTypeLevel;//Ĥ�ݼ���

	UINT32	dwNeedCoin;//Ĥ������ͭǮ��0Ϊ����Ҫ
	UINT32	dwNeedGold;//Ĥ������Ԫ����0Ϊ����Ҫ
	UINT8	byNeedVipLevel;//Ĥ������VIP�ȼ���0Ϊ����Ҫ

	UINT32	dwEncJingJie; //Ĥ�ݿɻ�þ���
	UINT32	dwEncPurpleGas; //Ĥ�ݿɻ������
};

typedef map<UINT8, SWorshipProp> CLevel2WorshipPropMap;
typedef CLevel2WorshipPropMap::iterator CLevel2WorshipPropMapItr;

class CPlayer;
class CWorshipPropMgr: public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CWorshipPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_WORSHIP ; }

    BOOL Init();

    VOID UnInit();
public:
	SWorshipProp* GetWorshipProp(UINT8 byWorshipType, UINT8 byWorshipTypeLevel);
	CLevel2WorshipPropMap& GetRaceWorshipProp() { return m_mapRaceWorshipProp; }
	CLevel2WorshipPropMap& GetRDCWorshipProp() { return m_mapRDCWorshipProp; }
public:
    CWorshipPropMgr();
    virtual ~CWorshipPropMgr();
protected:

    BOOL LoadFromDB();

private:
	CLevel2WorshipPropMap	m_mapRaceWorshipProp;//������Ĥ��
	CLevel2WorshipPropMap	m_mapRDCWorshipProp;//�����սĤ��
};

#endif // 
