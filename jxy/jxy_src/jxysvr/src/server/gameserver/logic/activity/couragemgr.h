
#ifndef _COURAGEMGR_H_
#define _COURAGEMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdobjectpool.h>
#include <logic/base/basepropmgr.h>
#include <protocol/server/protocommondata.h>
#include <logic/base/logicfunc.h>
#include <map>
#include <list>
#include <protocligs.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <logic/monster/playergroup.h>
#include <logic/monster/monstermgr.h>
#include "courage.h"

using namespace std;
using namespace SGDP;

class CCourageGroup;
typedef map<UINT64, CCourageGroup*> CCourageGroupMap;
typedef CCourageGroupMap::iterator  CCourageGroupMapItr;


class CCourageGroup
{
public:
    CCourageGroup()
    {

    }
    ~CCourageGroup()
    {
        for (CCourageGroupMapItr itr = s_mapCourageGroup.begin(); itr != s_mapCourageGroup.end();)
        {
            if (itr->second == this)
            {
                s_mapCourageGroup.erase(itr++);
            }
            else
            {
                itr++;
            }
        }
    }
    void Init(DT_COURAGE_GROUP_DATA &stDT_COURAGE_GROUP_DATA)
    {
        for (UINT16 idx = 0; idx < stDT_COURAGE_GROUP_DATA.wPlayerNum; idx++)
        {
            s_mapCourageGroup[CLogicFunc::Get3232Key(stDT_COURAGE_GROUP_DATA.dwGroupID, stDT_COURAGE_GROUP_DATA.astPlayerData[idx].dwPlayerID)] = this;
        }
        memcpy(&m_stDT_COURAGE_GROUP_DATA, &stDT_COURAGE_GROUP_DATA, sizeof(DT_COURAGE_GROUP_DATA));
    }
	DT_COURAGE_GROUP_DATA &GetDT_COURAGE_GROUP_DATA()
	{
		return m_stDT_COURAGE_GROUP_DATA;
	}
    static CCourageGroup* GetCourageGroup(UINT32 dwGroupID, UINT32 dwPlayerID)
    {
        CCourageGroupMapItr itr = s_mapCourageGroup.find(CLogicFunc::Get3232Key(dwGroupID, dwPlayerID));
        if (itr != s_mapCourageGroup.end())
        {
            return itr->second;
        }
        else
        {
            return NULL;
        }
    }
private:
    DT_COURAGE_GROUP_DATA		m_stDT_COURAGE_GROUP_DATA;
    static CCourageGroupMap	s_mapCourageGroup;
};

//ս������
enum em_Battle_Type
{
    EBT_JOIN = 0, //����ս��
    EBT_HELP = 1, //Э��ս��
};

//��Ա���
enum em_Battle_Identity
{
    EBI_MEMBER = 0, //��Ա
    EBI_LEADER = 1, //�ӳ�
};

//׼��״̬
enum em_Battle_Ready
{
    EBR_READYING = 0, // ׼����
    EBR_READY  = 1, //�Ѿ�׼��
    EBR_NONE = 2,
};

//�����������
enum em_Join_Battle_Type
{
    EJBT_SELECT = 0, //ѡ�����
    EJBT_RAND = 1, //�������
};

enum em_Battle_State
{
    EBS_NO_BATTLE = 0, //����ս����
    EBS_BATTLING = 1, //��ս����
};

enum em_Battle_Result
{
    EBR_PASS = 0, //ͨ��ս��
    EBR_NO_PASS = 1, //ûͨ��ս��
};

class CCourageMgr
{
    typedef map<UINT32, CCourageGroup*> CGroupID2CourageGroupMap;
    typedef CGroupID2CourageGroupMap::iterator  CGroupID2CourageGroupMapItr;

    typedef map<UINT32, CPlayerGroup*> CPlayerGroupMap;
    typedef CPlayerGroupMap::iterator CPlayerGroupMapItr;
public:

    DECLARE_SINGLETON(CCourageMgr);

public:

    BOOL Init();

    BOOL Init(DT_COURAGE_GROUP_DATA_LST stDT_COURAGE_GROUP_DATA_LST);

    VOID UnInit();

	BOOL InitEvent();	
public:

	BOOL			OnStartEvent(UINT8 byActivityID);
	BOOL			OnEndEvent(UINT8 byActivityID);
	BOOL			OnSave();
    CCourage*       CreateCourage();
    VOID            RemoveCourage(CCourage* poCourage);
    VOID            SaveData();
    VOID            OnEvent();
	//����������
    UINT16  OnOpenCourage(CPlayer* poPlayer,DT_COURAGE_INFO_CLI &stCourageInfo,DT_COURAGE_GROUP_DATA_CLI_LST &stCORUAGE_GROUP_DATA, UINT8& bySelect);
    //�򿪴�������
    UINT16  OnCourageOpenCreateGroup(CPlayer* poPlayer, PKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK& psAck);
    //ȷ�ϴ�������
    UINT16  OnCourageCreateGroup(CPlayer* poPlayer,UINT8 byJoinType,DT_INSTANCE_ID wInstanceID,UINT32 &dwGroupID);
    //����������Э������
    UINT16  OnCourageJoinGroup(CPlayer* poPlayer,UINT8 byBattleType,UINT32 dwGroupID);
    //�������������Э������
    UINT16  OnCourageRandomJoinGroup(CPlayer* poPlayer,PKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK &stAck);
    //��ӻ��߸��Ļ��
    UINT16  OnCourageOperateHero(CPlayer* poPlayer ,DT_COURAGE_GROUP_HERO_DATA_CLI &stCOURAGE_GROUP_HERO_DATA);
    //ȷ����ӻ��߸��Ļ��
    UINT16  OnCourageConfirmHero(CPlayer* poPlayer,UINT16 dwKindID,DT_COURAGE_HERO_DATA& stCOURAGE_HERO_DATA);
    //�ߵ���Ա
    UINT16  OnCourageFireGroupMember(CPlayer* poPlayer,UINT32 dwGroupID,UINT32 dwPlayID ,UINT32 &dwFirePlayID, UINT16 &wAverage);
    //��������
    UINT16  OnCourageBuyPractiseTimes(CPlayer* poPlayer,PKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK &stk);
    //�򿪹�������
    UINT16  OnCourageOpenShop(CPlayer* poPlayer,UINT8 &byBuyTimes,UINT32 &dwGold);
    //���׼��
    UINT16  OnCouragePlayerReady(CPlayer* poPlayer,UINT8 byTpye,UINT8 &byReadyTpye);
    //��ҿ�ʼ
    UINT16 OnCouragPlayerStart(CPlayer* poPlayer, PKT_CLIGS_COURAGE_PLAYER_START_ACK5 &stk);
    //��ҿ�ʼ2
    UINT16 OnCouragPlayerStart2(CPlayer* poPlayer, PKT_CLIGS_COURAGE_PLAYER_START_ACK2 &stk);
	//��ҿ�ʼ3
	UINT16 OnCouragPlayerStart3(CPlayer* poPlayer, PKT_CLIGS_COURAGE_PLAYER_START_ACK3 &stk);
    //����뿪
    UINT16 OnCouragLeaveGroup(CPlayer* poPlayer,DT_COURAGE_INFO_CLI &stCOURAGE_INFO,DT_COURAGE_GROUP_DATA_CLI_LST &stCOURAGE_GROUP_DATA);
    //���ˢ�¶���
    UINT16 OnCourageRefreshGroup(CPlayer* poPlayer,DT_COURAGE_GROUP_DATA_CLI_LST &stCOURAGE_GROUP_DATA);
    //��ҽ���������
    UINT16 OnCourageEnterGroup(CPlayer* poPlayer,DT_COURAGE_GROUP_DATA &stCOURAGE_GROUP_DATA);
    //��������Ƿ�Ҫ����
    VOID    ResetCourageData(CPlayer* poPlayer);
    //��ȡ���´���
    VOID    GetCourageTimes(CPlayer* poPlayer);
    //ɸѡ���������Ķ���
    BOOL    GetRightGroup(CPlayer* poPlayer ,BOOL bReset = FALSE);
    //�����������鸳ֵ
    VOID    SetPlayerGroupValue(CPlayer* poPlayer,DT_COURAGE_INFO_CLI &stCOURAGE_INFO,DT_COURAGE_GROUP_DATA_CLI_LST &stCOURAGE_GROUP_DATA);
    //��ȡ��������
    UINT16 OnCourageGetAwardReq(CPlayer* poPlayer,PKT_CLIGS_COURAGE_GET_AWARD_ACK &stAck, UINT32 dwIndex = 0);
    //��ȡ����ս�����
    UINT16 OnCouragGetBattleResultReq(CPlayer* poPlayer, PKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK &stAck);
    //�ж��Ƿ��ڶ�����
    BOOL    HaveInGroup(CPlayer* poPlayer, DT_COURAGE_GROUP_DATA &stCOURAGE_GROUP_DATA ,UINT32 dwGroupID); 
    //����뿪
    UINT16  OnLeave(CPlayer* poPlayer, BOOL bDisconnect = FALSE);
    //���ս��ʱ���뿪
    UINT16  OnLeaveBattle(CPlayer* poPlayer);
    //����뿪
    UINT16  OnLeaveCourage(CPlayer* poPlayer);
    //��ʱ�뿪����
    VOID  OverTimeDismiss(UINT32 dwPlayerID);
    //ȷ��Я����һ�����
    BOOL  HaveBringHero(CPlayer* poPlayer);
    //����Ĭ�ϻ��
    UINT16  GetMaxLevelHero(CPlayer* poPlayer, UINT16 &wLevel);
    //����������ö�������
    BOOL    SetEnterGroupData(CPlayer* poPlayer);
    //�Ƚ϶�������
    UINT16  CompareMapGroup(CMapGroupIDNum	m_mapBackGroupID, CMapGroupIDNum m_mapGroupIDNum);
    //���ɶ���ս����Ϣ
    BOOL  CreateGroupPower(UINT32 dwGroupID, DT_COURAGE_PLAYERID_HEROID_DATA astPlayerInfo[MAX_COURAGE_MEMBER_NUM]);
    //ս������ת��
    VOID  TransData(const DT_BATTLE_DATA2& stBataData2, DT_BATTLE_DATA3 &stBataData3);
    VOID  TransData2(const DT_BATTLE_DATA3& stBataData3, DT_BATTLE_DATA2 &stBataData2);

protected:
    BOOL InitModuleDataFromDB();
    BOOL InitModuleLogDataFromDB();

	CCourageGroup *GetCourageGroup(CPlayer* poPlayer);

protected:
    CCourageMgr();
    virtual ~CCourageMgr();

protected:
	UINT64								m_qwOverTime;             //�����ʱ��
	UINT64								m_qwStartTime;            //���ʼʱ��
	UINT64								m_qwSaveTime;             //��������ʱ��
    UINT64                              m_qwRefreshTime;          //ˢ��ʱ��
	UINT8								m_m_byActivityID;         //�ID
    UINT32								m_dwGroupID;              //����������������ID
    CGroupID2CourageGroupMap			m_mapGroupID2CourageGroup;//���ж������Ϣ
    CPlayerGroupMap                     m_mapPlayerGroupMap;      //�������ս��      
    CSDObjectPool<CCourageGroup, CSDMutex>	m_oCourageGroupPool;  //��������
    CSDObjectPool<CCourage, CSDMutex>       m_oCourageShmemObjMgr;	
    CSDObjectPool<CPlayerGroup, CSDMutex>   m_oPlayerCouragePool; 
    BOOL		m_bActivityOver;
    //��ȡЭ����ʾ
    VOID GetHelpPrompt(CPlayer* poPlayer,TCHAR aszHelpCouragePrompt[HELP_COURAGE_LEN]);
    //ս��
    //UINT16 CourageBattle(CPlayerGroup* poMyself, CMonsterGroup* poEnemy,UINT8 byBattleIdx, UINT16 wLevel,DT_BATTLE_DATA2& stDT_BATTLE_DATA, UINT8& byPassFlag,
    //    DT_COURAGE_AWARD_DATA& stPassEncourage, DT_COURAGE_AWARD_DATA& stAfterPassEncourage);
    //ͨ��ս��
    VOID PassBattle(UINT32 dwGroupID,UINT16 wLevel, BOOL bPass);
    //������������������
    VOID ClearGroupMemberData(CPlayer* poPlayer);
    //��¼��������
    C3232Map	m_mapAllEnterPlayer;
    //��¼�������
    C3232Map    m_mapAllEnterGropPlayer;
    //ˢ�¶���
    VOID RefreshGroupNtf();
    //�����ȡ����
    //BOOL GetMonsterID(UINT16 wLevel, UINT8 byMonsterNum, vector<UINT16>& vecMonsterID);   
    //BOOL GetMonsterID(UINT16 wLevel, UINT8 byMonsterNum, map<UINT8,vector<UINT16>>& mapMonsterID);   
    //BOOL GetMonsterID(UINT16 wLevel, UINT8 byMonsterNum, CMapMonsterIID& mapMonsterID, vector<UINT16> vecMonsterFaceID); 
    //�����ҿ��Խ��븱������Ϣ
    VOID	GetGVEInstanceRecordData(CPlayer* poPlayer, DT_TOWN_INSTANCE_RECORD_DATA_CLI &stData, UINT16 wSceneIdx, UINT8 byTownIndex);
    //��֤��ǰ�����Ƿ����
    BOOL    CkGVEUnlock(UINT16 wLevel, UINT16 wSceanID, UINT8 byTownID);
    //��ȡ�����������Ϣ
    VOID    RatePassBoxEnc(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, DT_COURAGE_JEWELRY_DATA_LST& stJewlryDataList);
    //ͨ�ر�����Ϣ
    UINT16  PassBoxEnc(CPlayer* poPlayer, DT_PASS_ENCOURAGE_BOX_DATA2& stDT_PASS_ENCOURAGE_BOX_DATA, DT_DATA_AFTER_PASS_ENCOURAGE_BOX* pstAfterPassEncourage);
    //��ȡͨ�ر�����Ϣ
    VOID    GetPassBox(CPlayer* poPlayer, DT_PASS_ENCOURAGE_BOX_DATA2& stDT_PASS_ENCOURAGE_BOX_DATA);
    //��ñ��������ƷID
    UINT16  RateInnerBox(UINT16 wKindID);
    //�ڲ����䴴������
    UINT16  CreateItem(CPlayer* poPlayer);
    //��ȡ�������Ѷ�
    UINT8   GetScore(UINT16 wLevel);
    //�������ε��������
    VOID    CreateJewelryData(CPlayer* poPlayer, UINT16 wJewelryID, DT_JEWELRY_DATA &st_DT_JEWELRY_DATA);
    //��ȡЭ����ʾ�������Ϳͻ�����ϣ�
    UINT8   GetHelpID(UINT32 dwHelpTimes, UINT32 dwGiveFreeTimes);
    //��ȡ����ڶ������������
    UINT8   GetInGroupIndex(UINT32 dwPlayerID, UINT32 dwGroupID);


private:
    static UINT32 dwCreateGroupID;                   //��������ID
    BOOL   bHaveData;                                //���ݿ��Ƿ��ж�������
    VOID   CreateTestData();                         //���ɲ�������
    UINT32 CreateGroupNum[MAX_TOWN_PER_SCENE_NUM];   //��ǰ�������������
};

#endif // 
