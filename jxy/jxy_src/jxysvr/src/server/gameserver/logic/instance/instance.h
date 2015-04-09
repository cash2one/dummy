
#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <logic/base/baseobj.h>
#include <logic/shmem/shmemmap.h>
#include "instancepropmgr.h"
#include "instancerecord.h"
#include "instancebattlercd.h"
#include <logic/score/scorepropmgr.h>
#include <common/server/utility.h>

using namespace std ;

class CPlayer;

#define NONINSTANCE	0 //û�ڸ���


//��ҵ�ǰս���������˳�ʱwSceneIdx = NONINSTANCE
struct SCurBattleInstance
{
    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
    UINT8 byBattleIdx;

    BOOL bPass;//�Ƿ��Ѿ�ͨ��
    BOOL bFirstPass;
    UINT8 byBattleNum;//��ǰ������ս����(������)

    SCurBattleInstance()
    {
        Clear();
    }
    VOID Clear()
    {
        wSceneIdx = NONINSTANCE;
        byTownIdx = 0;
        byInstanceIdx = 0;
        byBattleIdx = 0;
        bPass = FALSE;
        bFirstPass = FALSE;
        byBattleNum = 0;
    }
};

// �����ṹ��
struct SInstanceID
{
    UINT16 wSceneIdx;
    UINT8 byTownIdx;
    UINT8 byInstanceIdx;
};

/*
//һ������ӵ�еĸ�����Ϣ
typedef HashMap<UINT8, CInstanceRecord*> CIndex2InstanceRecordMap;
typedef CIndex2InstanceRecordMap::iterator CIndex2InstanceRecordMapItr;

//һ�ŵ�ͼӵ�еĳ�����Ϣ
typedef HashMap<UINT8, CIndex2InstanceRecordMap> CIndex2TownRecordMap;
typedef CIndex2TownRecordMap::iterator CIndex2TownRecordMapItr;

//���еĵ�ͼ��Ϣ
typedef HashMap<UINT16, CIndex2TownRecordMap> CIndex2SceneRecordMap;
typedef CIndex2SceneRecordMap::iterator CIndex2SceneRecordMapItr;
*/

typedef CShmemMap<UINT32, CInstanceRecord> CInstanceRecordShmemMap; //keyΪInstanceID

class CMonsterGroup;

//����ͨ�ؽ�����¼
struct SPassEncourage
{
    SPassEncourage()
    {
        Clear();
    }
    VOID Clear()
    {
        dwCoin = 0;
        dwGold = 0;
        wPhyStrength = 0;
        dwScience = 0;
        dwExperience = 0;
        byHitItemIdx = 0;
    }
    UINT32          dwCoin;
    UINT32          dwGold;
    UINT16          wPhyStrength;
    UINT32          dwScience;
    UINT32			dwExperience;//����,ÿ���佫��һ��
    UINT8			byHitItemIdx;
};


struct SSceneInstanceRecord;
class CInstance: public CBaseObj
{
public:
    CInstance();
    ~CInstance();

public:
    DT_INSTANCE_ID& GetMaxCommonInstanceID()
    {
        return m_stMaxCommonInstanceID;
    };
    DT_INSTANCE_ID& GetMaxEliteInstanceID()
    {
        return m_stMaxEliteInstanceID;
    };
    DT_INSTANCE_ID& GetMaxClimbTownInstanceID()
    {
        return m_stMaxClimbTowerInstanceID;
    };
	DT_INSTANCE_ID& GetMaxNaiDanInstanceID()
	{
		return m_stMaxNanDanInstanceID;
	};

    //��ʼ����ض���
    BOOL	Init(DT_INSTANCE_DB_DATA &stDT_INSTANCE_DB_DATA, CPlayer* poOwner);
    CInstanceRecordShmemMap& GetCommonInstanceRecord()
    {
        return m_mapCommonInstanceRecord;
    }
    CInstanceRecordShmemMap& GetEliteInstanceRecord()
    {
        return m_mapEliteInstanceRecord;
    }
    CInstanceRecordShmemMap& GetClimbTowerInstanceRecord()
    {
        return m_mapClimbTowerInstanceRecord;
    }
	CInstanceRecordShmemMap& GetOutBoundInstanceRecord()
	{
		return m_mapOutBoundRecord;
	}
	CInstanceRecordShmemMap& GetNeiDanInstanceRecord()
	{
		return m_mapNeiDanInstanceRecord;
	}

	
	UINT8 GetNewCommonInstanceID(UINT8 UnlockNewInstanceFlag, DT_INSTANCE_DATA_CLI& stNewCommonInstanceID);//��ȡ�¿ɴ���ͨ����,1��ʾ���µĿɴ򸱱�


    VOID	ExitInstanceWhenPass(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byScore); //ͨ���˳������ص�����¼��������Ϣ(������������ǵ�һ��ͨ�ؼ�¼����)��������һ���������Դ�ĸ���������db
    VOID	DoUnlock(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8& byBuildID, UINT16 awUnlockHeroID[MAX_UNLOCK_HERO_NUM]);//������Ӧ����

    VOID	AddSceneInstanceRecord(UINT16 wScenceIdx, DT_INSTANCE_DATA_LIST& stInstanceData);//��ӳ���������¼��Ϣ

    BOOL	GetInstanceRecord(UINT16 wSceneIdx, PKT_CLIGS_GET_SCENE_INSTANCE_ACK& stAck);//��ȡ����������¼��Ϣ,û�з���FALSE
    BOOL	CkHaveRecord(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);//����Ƿ���ڸ�����¼
	UINT16  GetOutBoundInfo(PKT_CLIGS_OPEN_OUT_BOUND_ACK& stAck);//�⴫Ŀ¼
	UINT16  OnOpenOutBoundMapAck(PKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ& stReq, PKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK& stAck);
	UINT16 OnOutBoundBattleAck(PKT_CLIGS_OUT_BOUND_BATTLE_REQ& stReq, PKT_CLIGS_OUT_BOUND_BATTLE_ACK& stAck);
	UINT16  GetDetailOutBound(UINT8 byTownIdx, DT_OUT_BOUND_DETAIL_LST_DATA& stInstanceLstInfo);
    UINT16	CkCanEnter(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byNewFlag);//����Ƿ���Խ��븱��

    SCurBattleInstance& GetCurBattleInstance()
    {
        return m_stCurBattleInstance;
    }

    BOOL	EnterInstance(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);//���븱���ص�
    UINT16	EnterBattle(UINT8 byBattleIndex);//ս���ص�
    BOOL	BattlePass(CMonsterGroup* poMonsterGroup, UINT8 byBattleIndex);//ս��ͨ���ص�,ս��ͨ�����һ���ص�
    BOOL	ExitInstance();//�뿪�����ص�

    CInstanceRecord* GetSingleInstaceRecord(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, BOOL bGetSuccessRecord = TRUE);//��ȡ����������¼��

    UINT8	GetCanCarryNum();//��ȡ��ǰ��Я��������0Ϊ����

    DT_INSTANCE_ID* GetCurMaxUnlockEliteInstanceID();

    //DT_INSTANCE_ID GetCurMaxUnlockClimbTowerInstanceID();

    UINT16  OpenEncourageBox(DT_PASS_ENCOURAGE_BOX_DATA& stDT_PASS_ENCOURAGE_BOX_DATA, DT_DATA_AFTER_PASS_ENCOURAGE_BOX* pstAfterEncourage); //�򿪸����������䣬���н���
    static BOOL	CkLessEqualID(UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byTargeTownIdx, UINT8 byTargeInstanceIdx);//��鸱��ID�Ƿ�С�ڵ���

    //////////////////
    CInstanceBattleRcd& GetCommonBattleRcd()
    {
        return m_oCommonInstanceBattleRcd;
    }

    CInstanceBattleRcd& GetEliteBattleRcd()
    {
        return m_oEliteInstanceBattleRcd;
    }

    CInstanceBattleRcd& GetClimbTowerBattleRcd()
    {
        return m_oClimbTowerInstanceBattleRcd;
    }

    //////////////////////////////
    VOID	PassEncourage(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byRunTimes = 1, DT_PASS_ENCOURAGE_DATA* pstDT_PASS_ENCOURAGE_DATA = NULL, DT_DATA_AFTER_PASS_ENCOURAGE* pstAfterEncourage = NULL);//ͨ�ؽ���
    VOID	RatePassBoxEnc(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, DT_PASS_ENCOURAGE_BOX_DATA& stPassEncourageBox, BOOL bOnhook = FALSE);//����ͨ�ر��佱��
    UINT16	PassBoxEnc(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, DT_PASS_ENCOURAGE_BOX_DATA& stDT_PASS_ENCOURAGE_BOX_DATA, DT_DATA_AFTER_PASS_ENCOURAGE_BOX* pstAfterPassEncourage = NULL);//ͨ�ر��佱��
    ///////////////
    VOID	GenEncInfo(UINT8& byHaveBoxFlag, DT_PASS_ENCOURAGE_BOX_DATA& stBoxInfo, DT_HERO_UPGRADE_DATA_LIST& stHeroUpgradeInfo);
    VOID	ClrChallengeTime(); //�����սʱ��
    UINT16 ResetEliteTime(UINT8 byTownIdx);//������սʱ��

    //��ȡ��Ӣ��������Ҫ����
    VOID GetEliteInstanceData( PKT_CLIGS_RESET_ELITE_INSTANCE_ACK &ackData, UINT8 byIndex );

    UINT16 ResetChallengeTime(UINT8 byTownIdx);//������սʱ��
    BOOL	GetClimbTowerInstanceAck(PKT_CLIGS_OPEN_CLIMB_TOWER_ACK& stAck);

    VOID GetClimbTownInstanceNum(UINT32 &dwMaxInstanceNum, UINT32  &dwMaxUnlockInstanceNum);//������//������¼��Ϣ

    UINT16 GetClimbTownInstanceInfo(UINT8 &byMaxInstanceNum, UINT8  &byMaxUnlockInstanceNum, DT_INSTANCE_RECORD_DATA_CLI &stInstanceInfo);//������//������¼��Ϣ

    void	DelClimbTownInstaceRecord(UINT16 wSceneIdx, UINT8 byTownIdx);//ɾ������������¼��
    BOOL	CkEliteUnlock(UINT8 byTownIdx, UINT8 byInstanceIdx); //����Ƿ�����þ�Ӣ����

    //��ȡ��ǰ�������������
    UINT16 GetMaxPassClimbTower();

    //��ȡָ�������Ѿ�ս�����ľ�Ӣ����
    UINT8 GetAlreadyBattleMaxIndex( UINT8 byTownIdx );

    //��ȡ��Ӣ������Ϣ
    BOOL	GetEliteInstanceRecordAck(PKT_CLIGS_GET_ELITE_INSTANCE_ACK& stAck);

    //��ȡ��Ӣ����VIP��չ��Ϣ
    DT_ELITE_INSTANCE_VIP_EXT_DATA_CLI GetEliteInstanceVipExt();


    VOID		GetEliteInstanceNum(UINT32 &dwMaxInstanceNum, UINT32  &dwMaxUnlockInstanceNum);//������//������¼��Ϣ

    UINT8	GetEliteInstanceRecordData( DT_ELITE_INSTANCE_RECORD_DATA_CLI &stData, DT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI &stScoreData, UINT8 byTownIndex);

    UINT16	GetCurrentClimbTower();

    UINT16	RecvRatingEncourageReq(UINT16 wSceneIdx, UINT8 byType, UINT16 wChapterIdx, DT_ACCUMULATED_SCORE_ENCOURAGE &stAccumulatedEncourage);

    VOID		AddFailedRecord(UINT16 wScenceIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);

    // ��ȡ����ָ����Ʒ�������ͨ���⴫����
    DT_INSTANCE_ID GetMaxPassInstanceOfItem(UINT16 wItemID);
	UINT8 GetInstanceStateByNeiDan(UINT8 byTownIdx);
	UINT16 GetNeiDanCanBattleNum();
protected:
    VOID		GiveFirstInsance(PKT_CLIGS_GET_SCENE_INSTANCE_ACK& stAck);//����һ����ͨ����


    BOOL		GetCommonInstanceRecord(PKT_CLIGS_GET_SCENE_INSTANCE_ACK& stAck);

    UINT8	UnlockBuild(SInstanceProp* pstInstanceProp);//��������������ͨ���ص�,���ؽ�������ID
    UINT16	UnlockHero(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 awUnlockHeroID[MAX_UNLOCK_HERO_NUM]);//�佫����������ͨ���ص�,�佫�������ҵ���ļ����,���ؽ������佫����(0û�н���)
    UINT32	UnlockEliteTownIdx(SInstanceProp* pstInstanceProp);//��Ӣ��������������ͨ���ص�,���ؽ����ľ�Ӣ�����������(0û�н���)

    BOOL		GetRatingEncourage(SScoreProp *poScoreProp);
    BOOL		GetRatingEncourage(CScoreAccumulateProp *poScoreAccumulateProp);

    BOOL		PackRatingEncourage(DT_ENCOURAGE_DATA &stChapterEncourage, SScoreProp *poScoreProp);
    BOOL		PackRatingEncourage(DT_ENCOURAGE_DATA &stAccumulatedEncourage, CScoreAccumulateProp *poScoreAccumulateProp);


private:
    DT_INSTANCE_ID				m_stMaxCommonInstanceID;//�����ͨ������¼��Ϣ(��ǰ�򵽵���߸�����¼(ͨ�غ����¸�ֵ))
    DT_INSTANCE_ID				m_stMaxEliteInstanceID; //���Ӣ������¼��Ϣ(��ǰ�򵽵���߸�����¼(ͨ�غ����¸�ֵ))
    DT_INSTANCE_ID				m_stMaxClimbTowerInstanceID; //���Ӣ������¼��Ϣ(��ǰ�򵽵���߸�����¼(ͨ�غ����¸�ֵ))
	DT_INSTANCE_ID				m_stMaxNanDanInstanceID; //���ն�����긱����¼��Ϣ(��ǰ�򵽵���߸�����¼(ͨ�غ����¸�ֵ))

    CInstanceRecordShmemMap		m_mapCommonInstanceRecord; //ͨ�ص���ͨ����������¼��������δͨ�ص�
    CInstanceRecordShmemMap		m_mapEliteInstanceRecord; //ͨ�صľ�Ӣ����������¼��������δͨ�ص�
    CInstanceRecordShmemMap		m_mapClimbTowerInstanceRecord; //ͨ�صľ�Ӣ����������¼��������δͨ�ص�
	CInstanceRecordShmemMap		m_mapNeiDanInstanceRecord; //ͨ�ص�ն�����곡��������¼��������δͨ�ص�
	CInstanceRecordShmemMap		m_mapOutBoundRecord;//ͨ���⴫��������δͨ�ص�

    SCurBattleInstance			m_stCurBattleInstance;	//��ǰ���븱����¼

    CInstanceBattleRcd			m_oCommonInstanceBattleRcd;//��ͨ����ս����¼����ͨ�أ�ͨ�������¼������ID��ScenceIDȫ0��
    CInstanceBattleRcd			m_oEliteInstanceBattleRcd;	//��Ӣ����ս����¼����ͨ�أ�ͨ�������¼������ID��ScenceIDȫ0��
    CInstanceBattleRcd			m_oClimbTowerInstanceBattleRcd;	//��Ӣ����ս����¼����ͨ�أ�ͨ�������¼������ID��ScenceIDȫ0��

    UINT8						m_byCommonPhyStrength;//������ͨ������������
    BOOL							m_bHaveEnterInstance;//�Ƿ��ѽ��������,�����ж��Ƿ������������gs����������ڴ��ٵ�¼��Ϸ�����ˢ1��
	UINT64 m_qwLastResetOutBoundTime;//��������⴫����ʱ��
};

DECLARE_CLASS_POOL_MGR(CInstance)

#endif //#ifndef 

