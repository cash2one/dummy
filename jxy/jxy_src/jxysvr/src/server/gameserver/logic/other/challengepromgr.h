
#ifndef _CHALLENGEPROP_H_
#define _CHALLENGEPROP_H_

#include <sdtype.h>
#include <sdhashmap.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>
#include <logic/base/basedefine.h>

using namespace SGDP;

//���߸���
struct SCItemRate
{
    UINT16	wRate;//��������(��ֱ�)
};
typedef map<UINT16, UINT16> CItemCRateMap;//keyΪ����kindid��valueΪSItemRate
typedef CItemCRateMap::iterator CItemCRateMapItr;

// ����¶����
struct SChallengeProp
{
    UINT16   wMylevel; // ��ǰЦ������
    UINT16   wEnemyLevel;

    CItemCRateMap		mapComposeItemWin;
    CItemCRateMap		mapComposeItemLose; 
    SChallengeProp()
    {
        wMylevel = 0;
        wEnemyLevel = 0;
        mapComposeItemLose.clear();
        mapComposeItemWin.clear();
    }
};


typedef HashMap<UINT16, SChallengeProp> CChallengePropMap; // 
typedef CChallengePropMap::iterator CChallengePropMapItr;



class CChallengePropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CChallengePropMgr);

public:
    virtual EConfigModule GetConfigModuleType() { return ECM_CHALLERGE; }

    BOOL Init();

    VOID UnInit();

public:	
    UINT16  RateItemID(UINT16 wMyLevel, UINT16 wEnemyLevel, UINT8 byWin);
public:
    CChallengePropMgr();
    virtual ~CChallengePropMgr();

protected:
    BOOL LoadChallengePropFromDB();

private:
    CChallengePropMap m_mapChallengePropMap; 
};

#endif // 

