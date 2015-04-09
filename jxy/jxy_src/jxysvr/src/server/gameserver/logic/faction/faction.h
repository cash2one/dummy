
#ifndef _FACTION_H_
#define _FACTION_H_

#include <protocol/server/protocommondata.h>
#include <sdsingleton.h>
#include <sdmutex.h>
#include <sdobjectpool.h>
#include <logic/base/basedefine.h>
#include <logic/rareitemroom/rareitemroompropmgr.h>
#include <logic/gymnasium/gymnasiumpropmgr.h>
#include <protocol/server/protocligs.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <map>
#include <deque>
#include <list>
#include <set>
#include "logic/base/basedefine.h"
#include "logic/gvg/gvgdef.h"

// ����Ƶ��������ʷ��������
#define MAX_FACTION_CHAT_HISTORY (MAX_CHAT_NUM * 3)

class CPlayer;
class CFactionGvG;

struct ChatInfo;

using namespace SGDP;
using namespace std;

typedef set<UINT32> CSetHotSpringPlayerID;
typedef set<UINT32>::iterator CHotSpringPlayerIDItr;

//��¼�û�����
typedef map<UINT32, DT_FACTION_PLAYER_DATA>	CMapFactionPlayerData;
typedef CMapFactionPlayerData::iterator			CMapFactionPlayerDataItr;


//��¼�û���־
typedef deque<DT_FACTION_LOG_DATA>			CDequeFactionLogData;
typedef CDequeFactionLogData::iterator		CDequeFactionLogDataItr;

typedef map<UINT32, UINT32>						CMapFactionPlayerID;
typedef CMapFactionPlayerID::iterator				CMapFactionPlayerIDItr;

typedef multimap<UINT32, UINT32>					CMultiMapApplyFactionPlayer;
typedef CMultiMapApplyFactionPlayer::iterator		CMultiMapApplyFactionPlayerItr;
typedef CMultiMapApplyFactionPlayer::const_iterator	CMultiMapApplyFactionPlayerConstItr;
typedef pair<CMultiMapApplyFactionPlayerItr, CMultiMapApplyFactionPlayerItr> Range;

//����
typedef map<string, UINT16>		CMapFactionName;
typedef CMapFactionName::iterator	CMapFactionNameItr;

struct ChatInfo;

// �����¼ָ���б�
typedef std::list<ChatInfo*> CFactionChatList; // �����CChatDataList������ʵһ�������������<chatmag.h>�ᵼ��linux�±��벻ͨ������ʱͨ������������

typedef list<DT_FACTION_PLAYER_DATA*> CListSortPlayer;
typedef CListSortPlayer::iterator CListPlayerItr;
class CFactionMgr;
class CFaction
{

public:
    CFaction()
    {
        m_qwSaveTime = 0;
        m_dequeFactionLogData.clear();
        m_mapFactionPlayerData.clear();
        m_mapApplyFactionPlayerID.clear();
		m_setHotSpringPlayerID.clear();
		m_setAddHotSpringPlayerID.clear();
		m_setDelHotSpringPlayerID.clear();
		m_listSoryByJob.clear();
        m_listChat.clear();
        m_listChatPool.clear();
        m_bExceptionFlag = FALSE;
        m_byExt = 0;
		memset(&m_stDT_FACTION_BASE_DATA, 0x00, sizeof(DT_FACTION_BASE_DATA));
        memset(&m_stFactionGvGData, 0x00, sizeof(DT_FACTION_GVG_DATA));
		
    }

    ~CFaction()
    {
		m_setHotSpringPlayerID.clear();
		m_setAddHotSpringPlayerID.clear();
		m_setDelHotSpringPlayerID.clear();
        m_dequeFactionLogData.clear();
        m_mapFactionPlayerData.clear();
        m_mapApplyFactionPlayerID.clear();
		m_listSoryByJob.clear();
		memset(&m_stFactionGvGData, 0x00, sizeof(DT_FACTION_GVG_DATA));
        ClearChat(0);
    }

    void Init(DT_FACTION_DATA &stDT_FACTION_DATA);
    void Init(DT_FACTION_PLAYER_DATA_LST &stDT_FACTION_PLAYER_DATA_LST);

    DT_FACTION_BASE_DATA & GetDT_FACTION_BASE_DATA()
    {
        return m_stDT_FACTION_BASE_DATA;
    }

    UINT32 GetFactionID(){ return m_stDT_FACTION_BASE_DATA.dwFactionID; }
	
    UINT16 GetOriZoneID();

    //���ݿⱣ�����������
    void GetDT_FACTION_PLAYER_DATA_LST(DT_FACTION_PLAYER_DATA_LST &stDT_FACTION_PLAYER_DATA_LST);
    //���ݿⱣ����־������
    void GetDT_FACTION_LOG_DATA_LST(DT_FACTION_LOG_DATA_LST &stDT_FACTION_LOG_DATA_LST);
    //���ݿⱣ������GVG����
	VOID GetFactionGvGData(DT_FACTION_GVG_DATA& stGvGData);
    void GetDT_FACTION_PLAYER_CLI_LST(DT_FACTION_PLAYER_CLI_LST &stDT_FACTION_PLAYER_CLI_LST);
	void GetDT_FACTION_PLAYER_CLI(DT_FACTION_PLAYER_CLI& stCli, UINT32 dwPlayerID);
    void GetDT_FACTION_PLAYER_AUDIT_CLI_LST(DT_FACTION_PLAYER_AUDIT_CLI_LST &stDT_FACTION_PLAYER_AUDIT_CLI_LST);
	void GetDT_FACTION_PLAYER_AUDIT_CLI_LST2(DT_FACTION_PLAYER_AUDIT_CLI_LST2 &stDT_FACTION_PLAYER_AUDIT_CLI_LST);
	VOID GetDT_FACTION_COMMON_DATA(DT_FACTION_COMMON_DATA& stDT_FACTION_COMMON_DATA);

	DT_FACTION_COMMON_DATA& GetDT_FACTION_COMMON_DATA();
	//��ȡ��Ұ��ɵĻ�����Ϣ
	void GetDT_FACTION_BASE_OWNER_DATA_CLI(DT_FACTION_BASE_OWNER_DATA_CLI &stDT_FACTION_BASE_OWNER_DATA_CLI, UINT32 dwJoinPlayerID);

	//��ȡ����Լ�����Ϣ
	VOID GetDT_FACTION_PLAYER_CLI_SELF(DT_FACTION_PLAYER_CLI& stDTFACTION_PLAYER_CLI, UINT32 dwPlayerID);

    DT_FACTION_GVG_DATA& GetFactionGvGData(){ return m_stFactionGvGData; }    

    //����������
    UINT16 ApplyFactionData(UINT32 dwJoinPlayerID);

    //ȡ������������
    UINT16 CancelApplyFactionPlayerData(UINT32 dwJoinPlayerID);

    //��������
    UINT16 CreateFactionPlayerData(UINT32 dwJoinPlayerID, DT_FACTION_DATA &stDT_FACTION_DATA, vector<UINT32> &vec);

    //�޳����
    UINT16 KickedFaction(UINT32 dwJoinPlayerID, UINT32 dwKickedPlayerID, PKT_CLIGS_KICKED_FACTION_ACK& stAck);

    //�򿪰����Ź����
    UINT16 OpenDoorsTributeFaction(DT_DOORS_TRIBUTE_TODAY_DATA &stDoorsTributeTodayData, UINT32 dwJoinPlayerID);

    //�Ź�����
    UINT16 DoorsTributeFaction(DT_DOORS_TRIBUTE_TODAY_DATA &stDoorsTributeTodayData, UINT8 dwDoorsTributeFlag, CPlayer* poPlayer);

    //��ȡ����
    UINT16 RecvDoorsTributeFactionReq( CPlayer * poPlayer, PKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK& stAck );

    //������־
    void		AddFactionLogData(DT_FACTION_LOG_DATA stDT_FACTION_LOG_DATA);

    //�鿴����Ƿ��ڳɹ�����
    BOOL		CkFactionPlayerData(UINT32 dwJoinPlayerID);

    //�鿴����Ƿ��������������
    BOOL		CkFactionApplyPlayerData(UINT32 dwJoinPlayerID);

    //�鿴���ְҵ����
    UINT16	GetJobNum(em_Faction_Job ckjob);

    UINT16	JobFaction(UINT32 dwJoinPlayerID, UINT32 dwJobPlayerID, UINT8 byJobFlag );

    UINT16	SetNoticeFaction(UINT32 dwJoinPlayerID, UINT8 byFlag, TCHAR aszFactionNotice[MAX_FACTION_DESC_NUM]);

    UINT16	DissolveFaction( UINT32 dwJoinPlayerID );
	//��������Ϣ
    UINT16	AuditFaction( UINT32 dwJoinPlayerID, UINT8 byAuditFlag, UINT32 dwPlayerID, vector<UINT32> &vec, UINT32& dwPassNum, UINT32& dwNoPass);
	UINT16	AuditFaction( UINT8 byAuditFlag, UINT32 dwPlayerID, vector<UINT32> &vec);

	UINT16 CKAuditFaction( UINT8 byAuditFlag, UINT32 dwPlayerID );

	UINT16	GetDT_FACTION_LOG_DATA_CLI_LST(DT_FACTION_LOG_DATA_CLI_LST &stDT_FACTION_LOG_DATA_CLI_LST);

    static BOOL	CkFactionPlayerData(UINT32 &dwFactionID, UINT32 dwJoinPlayerID);
    static BOOL	CkFactionApplyPlayerData(UINT32 dwJoinPlayerID, list<UINT32> &vec);

	//��ǰ������
	UINT32 ResetMaxTaskIntegral();

	

	VOID AddSetHotSpringPlayerID(UINT32 dwPlayerID);

	VOID DelSetHotSpringPlayerID(UINT32 dwPlayerID);

	VOID SetHotSpringPlayerList(DT_HOT_SPRING_PLAYER_DATA_CLI_LST& stPlayerInfo);
	VOID SetHotSpringPlayerSingle(DT_HOT_SPRING_PLAYER_DATA_CLI& stPlayerInfo, UINT32 dwPlayerID);
	VOID SendSynchInfo();

	UINT16 ChangeOther(UINT32 dwPlayerID, UINT32 dwSendPlayerID, PKT_CLIGS_CHANGE_OTHER_ACK& stAck);
    UINT64 &GetSaveTime()
    {
        return m_qwSaveTime;
    }

	VOID GetFactionPlayerNum(UINT16& wFactionNumberPeople, UINT16& wMaxFactionNumberPeople);
	
	//��Ա�䶯��־
	VOID SetPlayerChangeToAll();

	VOID DeletePlayerDataByID(UINT32 dwPlayerID);

	

	VOID AfterGiveWineProc();

	VOID GetFactionBuileGroup(DT_FACTION_BUILD_LEVEL& stBuildFlag);

	UINT32 GetFactionBuildLevel(em_Faction_Build emBuildType);

	VOID GetFactionDataToCli(DT_FACTION_DATA_TO_CLI& stFactionData);
	//��ȡ������Ա����Ϣ
	VOID GetManagerInfo(DT_FACTION_PLAYER_CLI_LST& stPlayerLst);

//////////////////////////////////////////////////////////////////////////
	//��������Ʒ��
	VOID SetFactionRareInfo();

	VOID SetFactionSkillInfo();

    const UpgradeRareItemMap& GetRareItemMap()
    {
        return m_mapRareitemInfo;
    }

    const CMapFactionSkill& GetFactionSkillMap()
    {
        return m_mapFactionSkill;
    }

	VOID CleanAllApply();
	////////////////////////////�۳��������ʽ��Ź���//////////////////////////////////////////////


	UINT32 GetFactionFunds();
	UINT32 GetDoorsTribute(UINT32 dwPlayerID);
	UINT64 GetSumDoorsTribute(UINT32 dwPlayerID);
	//�������Э��
	VOID AddFactionFunds(UINT32 dwValue, UINT16 wOpType);
	//�۳������ʽ�
	VOID DecFactionFunds(UINT32 dwFunds, UINT16 wOpType);
	//��ȫ��������Ա���Ź�
	VOID AddDoorsTributeToAll(UINT32 dwDoorsTribute);
	//�۳��Ź�
	BOOL DeductDoorsTribute(UINT32 dwPlayerID, UINT32 dwDoorsTribute, UINT16 wOpType);
	//����Ź�
	VOID AddDoorsTribute(UINT32 dwPlayerID, UINT32 dwDoorsTribute, UINT16 wOpType, UINT64 qwParam1 = 0, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0);

	//��������׽���������
	VOID AddHuntingIntegral(UINT32 dwPlayerID, UINT32 dwValue);

	BOOL AddFindBackDoorsTribute(UINT32 dwPlayerID, UINT8 byFindType);
	/////////////////////////////////////GM///////////////////////////////////////////////////////
	VOID SetFactionLevelByGM(UINT32 dwFactionLevel);
	VOID ChangeFactionNameByGM(TCHAR aszFactionName[MAX_FACTION_NUM]);
	////////////////////////////�۳��������ʽ��Ź���//////////////////////////////////////////////

    CMapFactionPlayerData& GetFactionPlayers()
    {
        return m_mapFactionPlayerData;
    }

    // ��ӳ�Ա����������
	VOID AddChatData(const ChatInfo& stChatData);

    // ������ɻ���칫��
    VOID AddFactionActivityChat(const string &strChatContent);

    CFactionChatList& GetChat()
    {
        return m_listChat;
    }
    CFactionChatList& GetChatCache()
    {
        return m_listChatPool;
    }

    // ��������������¼�����������������¼��ʷ��
    VOID ClearChat(UINT16 wReserveCnt = MAX_FACTION_CHAT_HISTORY/* ������������ʷ��¼ */);

	VOID AfterHuntingProc();

	UINT32 GetApplyFactionNum();

	DT_FACTION_PLAYER_DATA* GetDT_Faction_Player_Data(UINT32 dwPlayerID);

	static UINT32 GetMultiApplyFaction(UINT32 dwPlayerID);
	//////////////////////////////////��ʾ��Ϣ////////////////////////////////////////////////////
	VOID SetAllNewRareItemFlag();
	VOID SetAllNewSkillFlag();
	BOOL IsCanBuyRareItem(UINT32 dwPlayerID);
	BOOL IsCanLearnSkill(UINT32 dwPlayerID);
	/////////////////////////////������Ϣ/////////////////////////////////////////////
	VOID SendMessage(TCHAR* aszMsg, UINT16 wMsgID, em_Faction_Authority emAuth);//����Ȩ�޷�����Ϣ
	VOID SendMessageToAllFactionPlayer(TCHAR* aszSendMsg, UINT16 wMsgID, UINT32 dwPlayerID = 0);
	VOID SendMessageByAuthPrompt( );
	VOID SendMessageByGymnasiumPrompt();
	VOID SendMessageByRareItemPrompt();
	VOID SendMessageByShadePrompt();
	VOID SendMessageByHotSpringPrompt();
	VOID SendMessageByFactionPrompt();
	VOID SendMessageByLogNtf(DT_PLAYER_FACTION_BATTLELOG_DATA& stData);
    VOID SetExceptionFlag(BOOL	bExceptionFlag)
    {
        m_bExceptionFlag = bExceptionFlag;
    }
	BOOL GetExceptionFlag()
	{
		return m_bExceptionFlag;
	}

    UINT8	&GetExt()
    {
        return m_byExt;
    }
    VOID		GetAuditData(UINT8& byTodayPassNum, UINT64& qwLastAuditTime, UINT8 &byExt);
	UINT8 GetTodayPassNum();

    // ���ɳ�Ա��Ϣ�б����ڲ鿴�������ɵĸ�Ҫ��Ա��Ϣ
    void GetFactionMemberInfoList(DT_FACTION_MEMBER_INFO_LIST&);

    // ��gvg����ı�����ս������ṹ�壬���ڿͻ���ͬ��
    BOOL SaveGvGPKInfoTo(DT_PK_FACTION&);

    BOOL SaveGvGInfoTo(DT_GVG_FACTION&);

    // �����ݿ��е�ȡ�����ɵ�������ҵ��ڴ���
    void TakeFormationPlayersFromDB();

    // �����ɱ���ʱĬ�ϳ�ʼ���������
    void AutoFormation(UINT16 wAutoFormationCnt);

    // �ߵ��뿪���ɵ��������
    void KickOutFormationLeavePlayers();

    BOOL IsAllFormationPlayerInMemory();

    CPlayerVec GetFormationPlayers();

    em_Faction_Job GetJob(UINT32 dwPlayerID);

	UINT8 GetFactionIconID();
	UINT16	RegisterFactionName(CHAR* pszDspName, CPlayer * poPlayer);//ע���ǳ�

	
	VOID GetFactionBaseDataCli2(DT_FACTION_BASE_DATA_CLI2& stBaseCli);

	///////////////////////////GVG���///////////////////////////////////////////////
	//��ȡ����������Ϣ
	VOID GetFormationInfo(
		DT_FACTION_FORMATION_POS_LST_INFO& stFormationInfo,
		DT_GVG_FORMATION_SIMPLE_PLAYER_DATA_LST_CLI& stPlayerLstInfo,
		UINT16& wCurFactionLevel);

	VOID ResetFormationInfo();
	UINT16 GvGFactionEmbattle(PKT_CLIGS_GVG_FACTION_EMBATTLE_REQ& stAck);
    UINT64 ReCalcSumPower();
	UINT64 GetFactionGVGFunds(){ return m_stFactionGvGData.qwGVGFactionFunds; }
	UINT64 GetSumPower(){ return m_stFactionGvGData.qwSumPower; }
	VOID AddGvGFactionFunds(UINT32 dwFactionFunds);
	VOID ResetGvGFactionFunds();

    void AddGvGLog(DT_FACTION_SIMPLE_GVG_LOG_LIST &stSimpleLogList);

    // ����뱾������ս����ս������ʱս��δ��ʼ
    void AddLocalGvGLogNotStarted(UINT32 dwFactionID1, UINT32 dwFactionID2, DT_GVG_ROUND&, VideoID videoID);

    // ����뱾������ս����ս������ʱս���ѽ���
    void AddLocalGvGLog(DT_GVG_VIDEO &stVideo);

    // ��ӱ����ڵ�ս��
    void AddNoEnemyGvGLog(DT_GVG_ROUND&);

    UINT16 GetReadbleGvGLogCnt();

    void ClearOldGvG();

    BOOL IsJoin(UINT32 dwPlayerID);

	//�����ն����
	VOID AddContinueKill(UINT32 dwPlayerID, UINT16 wSessionID, UINT8 byGvGRound, UINT8 byBattleIdx, UINT8 byKillNum);
	//��Ӹ�������ս��
	VOID AddPlayerBattleLog(const UINT32& dwPlayerID, DT_PLAYER_FACTION_BATTLELOG_DATA& stLogData);
	//��ӿ��ս�����ս��
	//�ֿ�ʱ��poFaction = NULL, bIsNext = TRUE ����ֱ�ӽ�����һ�֣� FALSE ����ֱ�ӽ���ǰ4
	VOID AddGvGFactionBattleLog(UINT8 byRound, UINT8 byBattleIdx, GvGLogResult eResult, const TCHAR* poFactionName, BOOL bIsNext = TRUE);
	//������ն����
	VOID ResetContinueKill();
	//����GVG����
	VOID ResetFactionGvGData();

    VOID AddPlayerTosnapshot();

	VOID CheckGvGMedal();
	
private:
	UINT8 m_byTodayPassNum;  //�������ͨ������
	UINT64 m_qwLastAuditTime;  //������ʱ��
    UINT8	m_byExt;				//��չ����

	DT_FACTION_GVG_DATA					m_stFactionGvGData;//����GVG��Ϣ
    CFactionChatList                    m_listChat;         // ���ɵ�ǰδ���͵������¼
    CFactionChatList                    m_listChatPool;     // �����ѷ��͵������¼��ʷ
    UINT64							    m_qwSaveTime;
    DT_FACTION_BASE_DATA			    m_stDT_FACTION_BASE_DATA;		//���ɻ�����Ϣ
    CMapFactionPlayerData			    m_mapFactionPlayerData;			//���ɵ�ǰ�����Ϣ
    CMapFactionPlayerID				    m_mapApplyFactionPlayerID;			//�������������Ϣ
	BOOL							    m_bExceptionFlag;					//�����쳣��ʶ
    CDequeFactionLogData			    m_dequeFactionLogData;			//��־��Ϣ
	CListSortPlayer					    m_listSoryByJob;

	UpgradeRareItemMap				    m_mapRareitemInfo;			//��������Ʒ����	//��ƷID����Ʒ����
	CMapFactionSkill				    m_mapFactionSkill;			//���������ü���

	CSetHotSpringPlayerID			    m_setHotSpringPlayerID;		//��Ȫ����б�
	CSetHotSpringPlayerID			    m_setAddHotSpringPlayerID;	//�½�������б�
	CSetHotSpringPlayerID			    m_setDelHotSpringPlayerID;	//�뿪����б�
	DT_FACTION_COMMON_DATA              m_stDT_FACTION_COMMON_DATA;	//����״̬����

	static CMapFactionPlayerID			s_mapFactionPlayerID;	//key playerID, value factionID
	static CMultiMapApplyFactionPlayer	s_multimapApplyFactionPlayer;
};

#endif //#ifndef _ROLEMGR_H_

