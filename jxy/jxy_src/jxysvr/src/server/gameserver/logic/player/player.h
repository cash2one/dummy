
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include <sdtime.h>
#include <sdstring.h>
#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <protocol/server/protocligs.h>
#include <common/client/errdef.h>

#include <logic/battle/battleobj.h>
#include <logic/bag/bag.h>
#include <logic/instance/instancemgr.h>


#include <logic/enemy/enemy.h>
#include <logic/skill/skillmgr.h>
#include <logic/base/logicfunc.h>


#include <logic/shmem/shmemmap.h>

#include <logic/faction/factionplayer.h>
#include <logic/friendsys/sendflowerpropmgr.h>
#include <logic/faction/faction.h>
#include <logic/equipmaster/equipmaster.h>


#include "playergetdatamgr.h"
#include <logic/mark/mark.h>
using namespace std ;


struct tagUpdateData;
typedef tagUpdateData SUpdateData;

class CEatBread;
class CCourage;
class CBossBattle;
class CTask;
class CCourageGroup;
class CRace;
class CPlunder;
class CBuild;
class CHero;
class CFriends;
class CBegBlue;
class CRdChallenge;
class CCollectGas;
class CWorship;
class CClimbTower;
class CScore;
class CGatherScience;
class CPhystrength;
class CFormation;
class CVipExtData;
class CYabiaoInfo;
class CJingJie;
class CBuild;
class CMoneyTree;
class CCrop;
class CScienceTree;
class CLuaActivity;
class CActivityEncourage;
class CEquipCompse;
class CLocale;
class CEquipMaster;
class CCrop;
class CFewParam;
class CState;
class COnhook;
class CAwaken;
class COnlineEncourageRecord;
class CLoginEncourageRecord;
class CJewelry;
class CPlayerGVG;
class CPlayerSoul;
class CPlayerMedal;
class CPlayerPet;
struct	SMaintownLevyProp;

struct	tagDT_BATTLE_ATTRIBUTE;
typedef	tagDT_BATTLE_ATTRIBUTE DT_BATTLE_ATTRIBUTE;

#define COACHHERO	1 //����

typedef HashMap<UINT16, UINT16> CItemKind2IdxMap; //keyΪ�������ͣ�valueΪ�����͵��ߵ����
typedef CItemKind2IdxMap::iterator CItemKind2IdxMapItr;


typedef HashMap<UINT16, CEquip*>CIdx2EquipMap;//keyΪIdx
typedef CIdx2EquipMap::iterator CIdx2EquipMapItr;
typedef HashMap<UINT16, CIdx2EquipMap> CKindID2EquipMMap; //keyΪװ������
typedef CKindID2EquipMMap::iterator CKindID2EquipMMapItr;

typedef map<UINT32, CEnemy*> CEnemyID2EnemyMap;	//��map���򣬷��������++��ȡ��У�����ÿ������
typedef CEnemyID2EnemyMap::iterator CEnemyID2EnemyMapItr;
typedef vector<CEnemy*> CEnemyVec;
typedef CEnemyVec::iterator CEnemyVecItr;

typedef HashMap<UINT16, CSkill*>CSKillID2SkillMap;//keyΪ����ID
typedef CSKillID2SkillMap::iterator CSKillID2SkillMapItr;

typedef CShmemMap<UINT8, CTask> CLineIdx2TaskShmemMap; //keyΪTaskLine
typedef CShmemMap<UINT32, CEquip> CPlayerEquipShmemMap;//keyΪKindID+Idx
typedef CShmemMap<UINT32, CJewelry> CPlayerJewelryShmemMap;

typedef CShmemMap<UINT16, CHero> CKindID2HeroShmemMap;
typedef CShmemMap<UINT8, CHero> CFormationHeroShmemMap; //�н�����size+1

class	CUser;
struct	SGetPlayerDataAck;
struct	SSceneInstanceRecord;
class	COnhookMgr;
class CPlayer: public CBattleObj
{
    typedef VOID (CPlayer::*DestoryObj) ();
    typedef vector<DestoryObj>		CDestoryVec;

    typedef CDestoryVec::iterator	CDestoryVecItr;
public:
    CPlayer();
    ~CPlayer();

////////////////////////////////////�̳����////////////////////////////////////
public:

    virtual VOID StartBattle(CBattleObj* poEnemy);//ÿ��ս��ǰ(���������¼�ȵ�)
    virtual EBattleObjType GetBattleObjType()
    {
        return EBOT_PLAYER;
    }
    virtual VOID EndBattle(); //ÿ��ս����(���ս�������еĲ��� buff,��սʤ��)

    virtual VOID GetDT_BATTLE_OBJ_GROUP_DATA(DT_BATTLE_OBJ_GROUP_DATA3& stDT_BATTLE_OBJ_GROUP_DATA);//��ֵս����ս��������


    virtual VOID GetDT_BATTLE_OBJ_GROUP_AFTER_DATA(DT_BATTLE_OBJ_GROUP_HP& stDT_BATTLE_OBJ_GROUP_AFTER_DATA);//��ֵս����ս��������

    UINT32 GetPlayerID();
////////////////////////////////////������////////////////////////////////////

public:
	CPet* GetBattlePet();
    UINT16 EnterInstance(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byNewFlag = 0); //ÿ�ν��븱��ǰ��������鼰�������Լ��㣬����������/�������0����ɹ�����0����
    VOID	ExitInstance();//ÿ���˳�����ǰ�ĸ������Լ���(���Ϊ�����������ȵ�)

public:
    BOOL Init(DT_PLAYER_DATA& stDT_PLAYER_DATA);//��ʼ����ض���
    BOOL InitDT_PLAYER_TODAY_CONSUME_DATA();
    BOOL GetDT_PLAYER_BASE_DATA_CLI(DT_PLAYER_BASE_DATA_CLI& stPlayerInfo); //��ȡ��һ������ݣ����ڸ���Э�飬������ݱ仯֪ͨ

    const DT_PLAYER_BASE_DATA& GetDT_PLAYER_BASE_DATA()
    {
        return m_stDT_PLAYER_BASE_DATA;
    }
	DT_PLAYER_TODAY_CONSUME_DATA& GetDT_PLAYER_TODAY_CONSUME_DATA()
	{
		return m_stDT_PLAYER_TODAY_CONSUME_DATA;
	}
    DT_EXCHANGE_RESULT_LOG &GetDT_EXCHANGE_RESULT_LOG()
    {
        return m_stDT_EXCHANGE_RESULT_LOG;
    }
    CUser*	GetUser();
    BOOL		SendMsg(const CHAR* pData, UINT16 wMsgID);
    VOID		OnLogin(BOOL bLoginFlag = TRUE);
    UINT64	GetUpdateTime()
    {
        return m_qwUpdateTime;
    }
    VOID    SetUpdateTime(UINT64 qwUpdateTime = SDTimeSecs())
    {
        m_qwUpdateTime = qwUpdateTime;
    }
    BOOL		CkLogin()
    {
        return m_bLoginFlag;
    }
    VOID		SetDisconnectTime()
    {
        m_qwLastDisconnectTime = SDTimeSecs();
    }
    UINT16	RegisterDspName(CHAR* pszDspName);//ע���ǳƣ���֪ͨLS����User��
    UINT64	GetTodayFirstLoginTime()
    {
        return m_stDT_PLAYER_BASE_DATA.qwTodayFirstLoginTime;
    }
    BOOL		IsRobot()
    {
        return m_stDT_PLAYER_BASE_DATA.byRobotFunc > 0 ? TRUE : FALSE;
    }
    VOID		SetSaveState(ESaveState eSaveState )
    {
        m_eSaveState = eSaveState;
        if(ESS_WANT_SAVE == eSaveState) SetUpdateTime();
    };
    ESaveState GetSaveState()
    {
        return m_eSaveState;
    }
    UINT32	GetID()
    {
        return m_dwPlayerID;
    }

    UINT32	GetOriginalZoneID()
    {
        return m_stDT_PLAYER_BASE_DATA.wOriZoneID;
    }

    void	SetOriZoneID(UINT16 wOriZoneID)
    {
        m_stDT_PLAYER_BASE_DATA.wOriZoneID = wOriZoneID;
    }

    VOID		RecordPlayerOnOffLine( BOOL bLogin );

    BOOL		CkOpenFunc();//��鿪�������Ƿ���������������ȫ

    CHAR *GetLastOrderID()
    {
        return m_aszOrderID;    //����ϴδ�����ϵĶ�����
    }
    UINT8 *GetNoticeID()
    {
        return m_abyNoticeID;
    }
    UINT64 GetLoginTime()
    {
        return m_qwLoginTime;
    }
    UINT64 GetLogoffTime()
    {
        return m_qwLogoffTime;
    }
    void ResetLoginTime(UINT64 qwLoginTime = SDTimeSecs());
    void ResetLogoffTime(UINT64 qwLogoffTime = SDTimeSecs());
    BOOL IsAddOnlineTime()
    {
        return m_bAddOnlineTime;
    }

    VOID GetCliVerInfo(UINT32& dwCliVer, UINT32& dwResVer, UINT32& dwUIVer, TCHAR aszResVer[MAX_RES_VER_LEN]);
    VOID GetDT_EXT_FUNC_PARAM_LST(DT_EXT_FUNC_PARAM_LST& stExtFuncParamLst);

    BOOL& GetNewPlayerFlag()
    {
        return m_bNewPlayerFlag;
    }
    UINT64& GetLastInsertTime()
    {
        return m_qwLastInsertTime;
    }

    UINT32 GetCliVer();

    UINT32 GetAuthType();
    UINT32 GetFactionID();

    // ��ȡ����������ɵ�ͼ��ID��δ���������򷵻أ�NULL_FACTION_ICON_ID
    BYTE GetFactionIconID();
	UINT32 GetDaiChong();
	//GM���ܣ�����
	VOID ChangeNameByGM(TCHAR* aszDisName);
    DT_PLAYER_POS_INFO* GetPositionHotSpring();
    CFaction* GetFaction();
	///////////////////////////////////////////////////////////////////////////��Դ����
    VOID AddReward(UINT8 byRewardType, UINT32 dwRewardValue, UINT16 wOpType);
	BOOL CheckRes(UINT8 byResType, UINT64 qwResValue);
	///////////////////////////////////////////////////////////////////////////
    UINT64 GetSyncReward(UINT8 byRewardType);
    UINT32 GetFactionID(UINT32 dwPlayerID);
	VOID GetSyncResource(DT_RSYNC_RES_ITEM_DATA& stData);
	UINT16 OpenPlayerPanel(DT_PLAYER_INFO_PANEL& stPanel, DT_BAG_DATA_CLI& stBagInfo);

	UINT16 OpenPlayerPanel_v410(PKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410&);
	UINT16 OpenHeroSelectPanel(PKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK& stAck);

    // �����Ƿ��ѷ���
    BOOL IsFly();

    // ����ָ����飨�������ǣ�
    UINT16 Fly(UINT16 wHeroID, PKT_CLIGS_FLY_ACK&);

    UINT64 GetCoin(){ return m_stDT_PLAYER_BASE_DATA.qwCoin;}
    UINT64 GetGold(){ return m_stDT_PLAYER_BASE_DATA.qwGold;}

public:
    UINT16	GetCoachDefaultSkillActionID();
    CSkill*	GetCoachSkill();
    UINT8	GetCoachCareerID();

    UINT16	OpenSkillTab(DT_SKILL_TAB_DATA_CLI& stSkillTabInfo);
    UINT16	UpgradeSkillAction(UINT16 ActionID, UINT16 wActionLevelCli, DT_SKILL_TAB_DATA_CLI& stSkillTabInfo);
    UINT16	SetActionEffectRangProp(UINT16 wActionID, UINT16 wEffectID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind, DT_SKILL_TAB_DATA_CLI& stSkillTabInfo);



protected:
    BOOL	SyncCacheData();//ͬ�������е�����

    //VOID CkDataFortest();
    VOID	CkData();
    //VOID	CkExtData();//�ж���չ�ֶΣ������ڲ���ֵת���ȵȣ���1��ʾ0829����Ҳ�����¶/��������

    VOID	EncGemBulegasGodweapon();
public:
    UINT32&	GetExtData()
    {
        return m_stDT_PLAYER_BASE_DATA.dwExtData;
    }
private:
    DT_PLAYER_BASE_DATA			m_stDT_PLAYER_BASE_DATA; //��һ�����Ϣ
    DT_PLAYER_TODAY_CONSUME_DATA	m_stDT_PLAYER_TODAY_CONSUME_DATA;//��ҵĵ������Ѽ�¼
    DT_EXCHANGE_RESULT_LOG			m_stDT_EXCHANGE_RESULT_LOG;
    UINT32				m_dwPlayerID;//���ID�����ڻ��棬����ÿ�λ�ȡ
    CHAR					m_aszOrderID[MAX_ORDER_ID_LEN]; //�ϴδ���Ķ�����
    BOOL					m_bLoginFlag;//�Ƿ��¼����,��Ҫ�����ж��Ƿ��Ǳ���սInit��Player�����Լ����ߵ�¼
    UINT64				m_qwUpdateTime;//����ʱ��(����սҲ����)
    UINT64				m_qwLastDisconnectTime;//�ϴζϿ�����ʱ��
    //UINT64	m_qwTodayFirstLoginTime;//�����һ�ε�¼ʱ��
    ESaveState			m_eSaveState;//����״̬�����ڷǵ�¼��ҵı����ж�
    UINT8				m_abyNoticeID[MAX_TOKEN_NUM]; //�����Ϣ����ID
    UINT64				m_qwLoginTime;//�������ʱ��
    UINT64				m_qwLogoffTime;//�������ʱ��
    BOOL					m_bAddOnlineTime; //�Ƿ��¼����ʱ��
    BOOL					m_bNewPlayerFlag;//�Ƿ������
    UINT64				m_qwLastInsertTime;//������ϴ����ݲ���ʱ�䣬���ڱ������ظ����뼰��ʱ���Բ����ж�
    UINT32				m_dwCliVer;//�ͻ��˰汾


////////////////////////////////////
    CDestoryVec			m_vecDestory;





////////////////////////////////////Ϊ�˷�����ü����ٺ�������ջ������friend////////////////////////////////////
    friend class COnhookMgr;
    friend class CPlayerSaveMgr;

////////////////////////////////////Set���////////////////////////////////////
#include "playerset.h"

////////////////////////////////////�佫���////////////////////////////////////
#include "playerhero.h"

////////////////////////////////////����/�������////////////////////////////////////
#include "playeritem.h"

////////////////////////////////////�������////////////////////////////////////
#include "playertask.h"

////////////////////////////////////ս�����////////////////////////////////////
#include "playerbattle.h"

////////////////////////////////////�������////////////////////////////////////
#include "playerbuild.h"

////////////////////////////////////������////////////////////////////////////
#include "playerenemy.h"

////////////////////////////////////��ʾ���////////////////////////////////////
#include "playerprompt.h"

////////////////////////////////////�����������////////////////////////////////////
#include "playerupdateattr.h"

////////////////////////////////////����////////////////////////////////////
#include "playeractivity.h"

////////////////////////////////////�������////////////////////////////////////
#include "playerguide.h"

	////////////////////////////////////�������////////////////////////////////////
	DECLARE_INIT_DESTORY(Instance, CInstance, DT_INSTANCE_DB_DATA)

	////////////////////////////////////�һ�����////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(Onhook, COnhook, DT_ONHOOK_RCD_DATA)

	////////////////////////////////////λ�����////////////////////////////////////
	DECLARE_INIT_DESTORY(Locale, CLocale, DT_LOCALE_DATA)

	////////////////////////////////////״̬���////////////////////////////////////
	DECLARE_INIT_DESTORY(State, CState, DT_STATE_DATA)

	////////////////////////////////////װ���ϳ����////////////////////////////////////
	DECLARE_INIT_DESTORY(EquipCompse, CEquipCompse, DT_EQUIP_COMPOSE_DATA)

	////////////////////////////////////������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(Awaken, CAwaken, DT_AWAKEN_DATA)

	////////////////////////////////////������ֲ////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(Crop, CCrop, DT_CROP_DATA)

	////////////////////////////////////�������////////////////////////////////////
	DECLARE_INIT_DESTORY(Phystrength, CPhystrength, DT_PHYSTRENGTH_DATA)

	////////////////////////////////////ϡ�ٲ������////////////////////////////////////
	DECLARE_INIT_DESTORY(FewParam, CFewParam, DT_FEW_PARAM_DATA)

	////////////////////////////////////�Ƽ������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(ScienceTree, CScienceTree, DT_SCIENCE_TREE_DATA)

	////////////////////////////////////�������////////////////////////////////////
	DECLARE_INIT_DESTORY(Formation, CFormation, DT_NEW_FORMATION_DATA)

	////////////////////////////////////Ѻ�����////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(YabiaoInfo, CYabiaoInfo, DT_YABIAO_DATA)

	////////////////////////////////////�������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(JingJie, CJingJie, DT_JINGJIE_DATA)

	////////////////////////////////////�������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(ClimbTower, CClimbTower, DT_CLIMB_TOWER_DATA)

	////////////////////////////////////VIP��չ���////////////////////////////////////
	DECLARE_INIT_DESTORY(VipExtData, CVipExtData, DT_VIP_EXT_DATA)

	////////////////////////////////////��ֵ�������////////////////////////////////////
	DECLARE_INIT_DESTORY(ActivityEncourage, CActivityEncourage, DT_ACTIVITY_ENCOURAGE_DATA)

	////////////////////////////////////���ֽ������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(Score, CScore, DT_SCORE_DATA_LST)

	////////////////////////////////////�������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(CollectGas, CCollectGas, DT_COLLECT_GAS_DATA)

	////////////////////////////////////ҡǮ��////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(MoneyTree, CMoneyTree, DT_MONEY_TREE_DATA)

	////////////////////////////////////���߽���////////////////////////////////////
	DECLARE_INIT_DESTORY(OnlineEncourageRecord, COnlineEncourageRecord, DT_ONLINE_ENCOURAGE_RECORD_DATA)

	////////////////////////////////////��¼����////////////////////////////////////
	DECLARE_INIT_DESTORY(LoginEncourageRecord, CLoginEncourageRecord, DT_LOGIN_ENCOURAGE_RECORD_DATA)

	////////////////////////////////////�ۻ�////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(GatherScience, CGatherScience, DT_GATHER_SCIENCE_DATA)

	////////////////////////////////////����¶////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(BegBlue, CBegBlue, DT_BEGBLUE_DATA)

	////////////////////////////////////����ϵͳ////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(Friends, CFriends, DT_FRIENDS_DATA)

	////////////////////////////////////�����������////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(FactionPlayer, CFactionPlayer, DT_PLAYER_FACTION_DATA)

	////////////////////////////////////װ����ͨ////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(EquipMaster, CEquipMaster, DT_EQUIP_MASTER)

	///////////////////// �ű�� /////////////////////////////
	DECLARE_INIT_DESTORY(LuaActivity, CLuaActivity, DT_LUAACTIVITY_RECORD_LIST_DATA)

	///////////////////// BOSSս /////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(BossBattle, CBossBattle, DT_BOSS_BATTLE_PLAYER_DATA_INFO)

	///////////////////// ���� /////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(Courage, CCourage, DT_COURAGE_DATA)

	///////////////////// �԰��� /////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(EatBread, CEatBread, DT_EAT_BREAD_DATA)

	/////////////////////////GVG/////////////////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(PlayerGVG , CPlayerGVG, DT_PLAYER_GVG_DATA)
	////////////////////////ս��////////////////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(PlayerSoul , CPlayerSoul, DT_PLAYER_SOUL_DATA)
	////////////////////////ѫ��//////////////////////////////////////////////////
	DECLARE_BUILD_INIT_DESTORY(PlayerMedal , CPlayerMedal, DT_PLAYER_MEDAL_DATA)
	// ����
	DECLARE_BUILD_INIT_DESTORY(PlayerPet , CPlayerPet, DT_PLAYER_PET_DATA)
};

DECLARE_CLASS_POOL_MGR(CPlayer)

#endif //#ifndef _PLAYER_H_

