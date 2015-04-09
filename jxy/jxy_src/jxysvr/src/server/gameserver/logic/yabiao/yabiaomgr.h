#ifndef _YABIAO_MGR_H_
#define _YABIAO_MGR_H_

#include "yabiaoinfo.h"

#include <sdsingleton.h>
#include <logic/base/basedefine.h>
#include <common/client/commondef.h>
#include <logic/shmem/shmemmap.h>
#include <set>
#include <logic/base/basepropmgr.h>

#include <sdobjectpool.h>
#include <sdmutex.h>

struct SYabiaoEncourage
{
    SYabiaoEncourage()
    {
        dbCoinFactor = 0;
        nScience = 0;
    }
    SYabiaoEncourage( DOUBLE _dbCoinFactor, INT32 _nScience, INT32 _nJingjie )
    {
        dbCoinFactor = _dbCoinFactor;
        nScience = _nScience;
        nJingjie = _nJingjie;
    }

    DOUBLE dbCoinFactor;
    INT32 nScience;
    INT32 nJingjie;
};

struct SBiaoBaseInfo
{
    SBiaoBaseInfo()
    {
        nTime = 0;
        nFlushUpdateRate = 0;
    }
    //�ڵ�ʱ��
    INT32 nTime;
    //����
    SYabiaoEncourage oEncourage;

    //ˢ�������ĸ���
    INT32 nFlushUpdateRate;
};

struct SYabiaoCfgInfo
{
    SYabiaoCfgInfo()
    {
        Reset();
    }
    VOID Reset()
    {
        vecBiaoInfo.clear();
        vecFlushCostGold.clear();
    }

    vector<SBiaoBaseInfo> vecBiaoInfo; //�ڵĻ�����Ϣ,��˳���ȡ���ͼ���ǰ���߼��ں�
    vector<INT32> vecFlushCostGold; //ˢ�����ĵ�Ԫ��
};

struct SYabiaoPlayerInfo
{
    SYabiaoPlayerInfo()
    {
        dwPlayerID = 0;
    }

    UINT32 dwPlayerID;

};

struct SJiebiaoInfo
{
    SJiebiaoInfo()
    {
        dwCoinEncourage = 0;
    }

    UINT32 dwCoinEncourage;
};

class CPlayer;

typedef map<UINT16, C32Vec> CLevel2PlayerVecMap;
typedef CLevel2PlayerVecMap::iterator CLevel2PlayerVecMapItr;

class CYabiaoMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CYabiaoMgr);
    //������Ϣ����
    CYabiaoMgr();
    ~CYabiaoMgr();
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_YABIAO ;
    }
    BOOL Init();
    VOID UnInit();

    UINT8 GetTotalYabiaoCnt();
    UINT8 GetTotalJiebiaoCnt();
    UINT8 GetTotalBeJiebiaoCnt();

    //������Ʒ�ʵĵȼ�
    INT32 GetMaxQualityLevel();

    //��ö�Ӧ�ȼ�Ѻ�������ʱ��(�ȼ���1��ʼ)
    INT32 GetCostTime( INT32 nQuality );

    //ֱ����ߵȼ����ĵ�Ԫ��
    INT32 GetDirectMaxLevelCostGold();

    //���ˢ�����ĵ�Ԫ��
    INT32 GetFlushCostGoldByCount( INT32 nCount );

    //���ָ��Ʒ�ʵĽ���
    SYabiaoEncourage GetEncourage( INT32 nQuality );

    //��������Ѻ�ڵ����
    INT32 AddPlayer( UINT32 dwPlayer );

    //��������Ѻ�ڵ����
    BOOL DeletePlayer( UINT32 dwPlayer );

    //ʧ�ܷ���0
    UINT32 GetPlayerIDByIndex( INT32 nIndex );
    INT32 GetPlayerCount();

    //�����Ѻ�ڵĳ������
    vector<UINT32> GetEnemy( UINT16 wPlayerLevel, const set<UINT32> &setEnemy, UINT8 byNum = 0, UINT16 wTimeToEnd = 0 );

    vector<UINT32> GetYabiaoPlayer( UINT16 wPlayerLevel, UINT16 wTimeToEnd = 0, UINT8 byNum = 0 );

    //���سɹ����ߺ��İ�
    BOOL FlushToUpdateQuality( INT32 nQuality );

    BOOL FillPlayerYabiaoInfo( PKT_CLIGS_OPEN_JIEBIAO_ACK &ack, const vector<UINT32> &vecPlayer, UINT32 dwViewerID, UINT16 wJiebiaoLevel,CPlayer *pOwner );

    UINT16 GetJiebiaoCD();

	INT32 BeginJiebiao( CPlayer &playerSelf, UINT32 dwBeJiebiaoPlayerID, UINT64 &qwEncourageCoin, UINT32 &dwEncourageScience,
		DT_BATTLE_DATA5 &stDT_BATTLE_DATA, UINT64 &qwBattleIndexOut );
    //VOID OnCrossDay();

    //PKT_CLIGS_BEGIN_JIEBIAO_ACK *GetJiebiaoAck( UINT32 dwPlayerID, UINT32 dwCount );
    //VOID AddJiebiaoAck( UINT32 dwPlayerID, UINT32 dwCount, const PKT_CLIGS_BEGIN_JIEBIAO_ACK &ack );

    vector<SBiaoBaseInfo> GetBiaoInfoList();

    //byLevel��ָƷ�ʣ�wPlayerLevel��ָ��ҵȼ�
    DT_BIAO_INFO GetBiaoInfo( UINT8 byLevel, UINT16 wPlayerLevel );

    //���Ѻ�ڵ����
    BOOL AddPlayerToContainer( CPlayer* poPlayer);
private:
    BOOL LoadFromDBEx();

    vector<UINT32> GetLimitYabiaoPlayer( UINT16 wPlayerLevel,  BOOL bGetEnemy, UINT32 dwGetNum, const vector<UINT32> &vecSrc, UINT16 wTimeToEnd );

    VOID FillBiaoAckInfo( PKT_CLIGS_FLUSH_BIAO_QUALITY_ACK &ack, CPlayer &oPlayer );
    UINT64 GetJiebiaoCacheKey( UINT32 dwPlayerID, UINT32 dwCount ); //���ڵ����ID�����ڴ���

    //VOID ClearJiebiaoCache();

    UINT32 CalcCoin( UINT8 byQuality, UINT16 wLevel );

private:
    SYabiaoCfgInfo m_oCfgInfo; //������Ϣ
    vector< UINT32 > m_vecYabiaoPlayer; //Ѻ�ڵ������Ϣ
    set< UINT32 > m_setYabiaoPlayer; //Ѻ�ڵ������Ϣ
    CLevel2PlayerVecMap	m_mapLevel2PlayerVecMap;////Ѻ�ڵ������Ϣ,keyΪ��ҵȼ�
    //MAP_JIEBIAO_CACHE_TYPE m_mapJiebiaoAckCache;
};


#endif
