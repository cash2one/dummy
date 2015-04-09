
#ifndef _PLAYERBASEDATACACHEMGR_H
#define _PLAYERBASEDATACACHEMGR_H

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <protocol/server/protocommondata.h>
#include <protocol/server/protocligs.h>
#include <sddb.h>
#include <vector>

using namespace std;
using namespace SGDP;

typedef std::vector<UINT32> CPlayerIDVec;

//�첽��ͬ����Ϣ
struct SSyncProp
{
    SSyncProp()
    {
        Clr();
    };
    VOID Clr()
    {
        vecPlunderLog.clear();
        vecReleaseCaptureID.clear();
    }

    vector<DT_PLUNDER_BATTLELOG_DATA> vecPlunderLog;//�������Ӷ�ս��
    vector<UINT32>				vecReleaseCaptureID;//�������ͷŵķ�²ID
};

struct SPlayerBaseData
{
    SPlayerBaseData()
    {
        Init();
    }

    void Init()
    {
        dwID = 0;
        wMainHeroKindID = 0;
        wLevel = 0;
		byVipLevel = 0;
        dwRank = 0;
        byRobotFunc = 0;
        dwPower = 0;
        dwFirstAttack = 0;
        dwNotifyRank = 0;
        qwNotifyRankTime = 0;
        dwCaptureOwner = 0;
        bOpenPlunder = FALSE;
        qwLoginTime = 0;
        qwLogoffTime = 0;
        bEatBreadNotify = 0;
        bBossBattleNotify = 0;
        bCoruageNotify = 0;
        dwFlowerSum = 0;
        dwExperience = 0;
        memset(abyToken, 0, sizeof(abyToken));
        memset(aszDispName, 0, sizeof(aszDispName));
        stSyncProp.Clr();
    }

    UINT32          dwID;
    TCHAR           aszDispName[USERNAME_LEN];
    UINT16          wMainHeroKindID;
    UINT16          wLevel;
	UINT8           byVipLevel;
    UINT32          dwRank;//0��ʾû�м�¼
    UINT8			byRobotFunc;//�����˹���,>0��Ϊ�����ˣ���ͬ��ֵΪ��ͬ�Ĺ��ܡ�0Ϊ���
    UINT32			dwCaptureOwner;//��²����0��ʾû�б���²
    UINT64			qwCaptureOwnerTime;
    BOOL				bOpenPlunder;//�ͷſ����Ӷ�
    UINT32			dwPower;//ս��
    UINT32			dwFirstAttack;//�ȹ�
    UINT64			qwNotifyRankTime;//����������ʱ��
    UINT32			dwNotifyRank;//����������
    UINT64			qwLoginTime;//�������ʱ��
    UINT64			qwLogoffTime;//�������ʱ��
    UINT8			abyToken[MAX_TOKEN_NUM];
    UINT32			dwFlowerSum;
    UINT32          dwExperience;

    BOOL				bEatBreadNotify;//�԰���֪ͨ
    BOOL				bBossBattleNotify;//BOSSս֪ͨ
    BOOL             bCoruageNotify;//��������֪ͨ
    SSyncProp		stSyncProp;//�첽��ͬ����Ϣ
};

struct SPlayerRankData
{
    UINT32   dwPlayerID;                  //���ID
    UINT16   wLevel;                      //��ҵȼ�
    TCHAR    aszDispName[USERNAME_LEN];   //����ǳ�
    UINT32   dwExperience;
};

typedef HashMap<UINT32, SPlayerBaseData*>			CPlayerID2PlayerBaseDataMap; //keyΪ���ID
typedef CPlayerID2PlayerBaseDataMap::iterator		CPlayerID2PlayerBaseDataMapItr;
typedef CPlayerID2PlayerBaseDataMap::const_iterator	CPlayerID2PlayerBaseDataMapConstItr;

typedef vector<SPlayerBaseData*> CPlayerBaseDataVec;
typedef CPlayerBaseDataVec::iterator CPlayerBaseDataVecItr;
typedef CPlayerBaseDataVec::const_iterator CPlayerBaseDataVecConstItr;

typedef vector<SPlayerRankData> CPlayerRankDataVec;
typedef CPlayerRankDataVec::iterator CPlayerRankDataVecItr;
typedef CPlayerBaseDataVec::const_iterator CPlayerRankDataVecConstItr;


typedef HashMap<tstring, UINT32> CDspNameMap;
typedef CDspNameMap::iterator CDspNameMapItr;


#define MAX_PLAYER_CACHE_POOL_NUM	5000


class CRaceMgr;
class CPlayer;
class CPlunder;
class CNoticeMgr;
class CPlayerBaseDataCacheMgr
{
    //friend class CRaceMgr;
    //friend class CNoticeMgr;
public:
    DECLARE_SINGLETON(CPlayerBaseDataCacheMgr)

    BOOL Init();

    VOID UnInit();

public:
    BOOL AddPlayerBaseData(CPlayer* poPlayer); //�������������ҵĻ�����Ϣ
    const SPlayerBaseData* GetPlayerBaseData(UINT32 dwPlayerID);
    UINT16 GetLevel(UINT32 dwPlayerID);

    UINT16 RegDspName(UINT32 dwPlayerID, const TCHAR* pszDispName);//ע���ǳƣ��ɹ�����TRUE,�����ǳƳ�ͻ
    BOOL OnLevelChange(UINT32 dwPlayerID, UINT16 wLevel);//
    //BOOL OnFameChange(UINT32 dwPlayerID, UINT32 dwFame);//
    BOOL OnRankNew(UINT32 dwPlayerID, UINT32 dwRank);//Rank�仯ʱ�ص�,��������(ɾ��)����ʱ
    BOOL OnRankExchange(UINT32 dwPlayerID1, UINT32 dwRank1, UINT32 dwPlayerID2, UINT32 dwRank2);//��������ʱ�����ھ�������ս
    BOOL OnCapture(UINT32 dwPlayerID, UINT32 dwCaptureOwnerID);//����²/����²�ͷŻص�
    //VOID OnClrPlayerData(CPlayer* poPlayer); //fortest������������ʱ�ص�
    BOOL OnPowerChange(UINT32 dwPlayerID, UINT32 dwPower);//ս���仯�ص�
    BOOL OnFirstAttackChange(UINT32 dwPlayerID, UINT32 dwFirstAttack); //�ȹ��仯�ص�
    BOOL OnOpenPlunder(UINT32 dwPlayerID); //������²�ص�

    const CPlayerID2PlayerBaseDataMap& GetPlunderRobot()
    {
        return m_mapPlunderRobot;    //��ȡ�����Ӷ�Ļ�����
    }
    const CPlayerID2PlayerBaseDataMap &GetPlayerID2PlayerBaseDataMap()
    {
        return m_mapPlayerID2PlayerBaseData;
    };

	const CPlayerBaseDataVec &GetPlayerBaseDataVec()
	{
		return m_vecPlayerBaseData;
	};

    void ReSetLoginTime(UINT32 dwPlayerID);
    void ReSetLogoffTime(UINT32 dwPlayerID);
    //VOID GetPlayerByLevel(UINT16 wLevel, UINT8 byGetNum, CPlayerBaseDataVec& vecPlayer, BOOL bNotBecapture = FALSE);//��ȡָ���ȼ���ָ����Ŀ�����
    VOID GetPlayerByLevel(UINT32 dwMyPlayerID, UINT16 wLevel, UINT8 byGetNum, CPlayerBaseDataVec& vecPlayer,
                          UINT32 dwStartPlayerID, CPlunder &oOwnPlunder, BOOL bNotBecapture = FALSE);//��ȡָ���ȼ���ָ����Ŀ�����

    VOID GetPlayerByLevel(UINT32 dwMyPlayerID, UINT16 wLevel, UINT8 byGetNum, CPlayerBaseDataVec& vecPlayer,
                          UINT32 dwStartPlayerID, BOOL bHaveRobot = FALSE);//��ȡָ���ȼ���ָ����Ŀ�����

    BOOL	GetEatBreadNotify(UINT32 dwPlayerID);//�԰���֪ͨ
    BOOL	GetBossBattleNotify(UINT32 dwPlayerID);//BOSSս֪ͨ
    BOOL	GetCourageNotify(UINT32 dwPlayerID);//��������֪ͨ

    VOID	SetEatBreadNotify(UINT32 dwPlayerID, BOOL bValue);//�԰���֪ͨ
    VOID	SetBossBattleNotify(UINT32 dwPlayerID, BOOL bValue);//BOSSս֪ͨ
    VOID	SetCourageNotify(UINT32 dwPlayerID, BOOL bValue);//��������֪ͨ
    BOOL InitDataFromDB();

    BOOL CkHaveDspName(const TCHAR* pszDispName);

    CPlayerIDVec FindContainDspName(const TCHAR* pszDispName);

    UINT32 FindPlayer(const TCHAR* pszDispName);

	BOOL	AddFlower(UINT32 dwPlayerID, UINT32 dwFlower);

	BOOL	SetFlower(UINT32 dwPlayerID, UINT32 dwFlower);

	UINT32	GetFlower(UINT32 dwPlayerID);

	UINT32	GetFlowerRanking(UINT32 dwPlayerID);

	// ��ȡ�ʻ���
	UINT16 GetFlowerRankingList(DT_FLOWER_RANKING_LIST_CLI& stFlowerRankingList);
	
	VOID SetVipLevel(UINT32 dwPlayerID, UINT8 byVIPLevel);

    //��ȡһ�������ĵȼ�����
    VOID GetRankByLvEx(UINT32 dwNum, CPlayerRankDataVec &m_vecPlayerRankData);

	VOID SetExperience(UINT32 dwPlayerID, UINT32 dwExperience);

	const CPlayerBaseDataVec& GetPlayerBaseDatas() const;

protected:
    CPlayerBaseDataCacheMgr();
    ~CPlayerBaseDataCacheMgr();
protected:

private:
	CPlayerBaseDataVec							m_vecPlayerBaseData;
    CPlayerBaseDataVec							m_vecPlayerBaseData_LvEx;
    CPlayerID2PlayerBaseDataMap					m_mapPlayerID2PlayerBaseData; //keyΪPlayerID
    CSDObjectPool<SPlayerBaseData, CSDMutex>			m_oPlayerBaseDataPool;
    CPlayerID2PlayerBaseDataMap					m_mapPlunderRobot;//�Ӷ�Ļ�����
    UINT16										m_wMaxPlayerLevel;//�����ҵȼ�
    CPlayerID2PlayerBaseDataMap*					m_apmapPlayerLevel;//��ҵȼ���Ӧ�����иõȼ������
    CDspNameMap									m_mapDspName;
};



#endif

