

#ifndef _DB_MANAGER_H_
#define _DB_MANAGER_H_

#pragma once

#include <sddb.h>
#include <sdobjectpool.h>
#include <map>
#include <sdmutex.h>
#include <logic/player/playermgr.h>
#include <set>


using namespace std;
using namespace SGDP;

class CBaseDBCMD;
class CClrPlayerDataCMD;
class CGetPlayerDataCMD;
class CGetPlayerDataCMD2;
class CSavePlayerDataCMD;
class CCreatePlayerCMD;
class CRecordPlayerLoginoff;
class CSavePlayersPlunderDataCMD;
class CSavePlayersRaceDataCMD;
class CRecordBattleData;
class CRecordBattleData2;
class CGetBattleData;
class CGetBattleData2;
class CGetChatCMD;
class CGetPlayerDataCMD_OLD; //fortest
class CSaveBossBDataCMD;
class CSetAppPayInfo;
class CSetAppPayProcessed;//DB��������
class CSetTongBuPayInfo;
class CSetTongBuPayProcessed;
class CActivityEncourageCMD;
class CUpdateCdKeyCmd;
class CSetMyPayProcessed;
class CSaveFactionDataCMD;
class CGetGsNoticeCMD;
class CGetOprateingActivityCMD;
class CCreateFactionDataCMD;
class CSavePlayerConsume;
class CGetPlayerConsume;
class CSetCenterPayProcessed;
class CGetPrivateMsgLogCmd;
class CSavePrivateMsgLogCmd;
class CSaveCourageDataCMD;
class CPlayer;
class CLeaveFactionDataCMD;
class CSetRecreatePayProcessed;
class CSaveGvGVideoCMD;
class CSaveGvGActivityCMD;
class CSaveGvGArenaCMD;
class CSavePlayerSnapShotCMD;
class CSaveGvGBuildCMD;
class CDeleteOverGvGift;
class CAddGvGiftCMD;
class CAddPlayersLogCMD;
class CDelPlayerLogCMD;
class CClearGvGActivityCMD;
class CClearGvGVideoCMD;
class CDelPlayerSnapShotCMD;
class CSetReadPrivateMsgCMD;
class CAddPlayerGiftCMD;
class COperatingActivityCMD;

typedef struct tagDT_PLAYER_NOPVP_DATA DT_PLAYER_NOPVP_DATA;

struct tagDT_FACTION_DATA;
typedef tagDT_FACTION_DATA DT_FACTION_DATA;

enum EDBCmdType
{
    EDBCT_CREATE = 1,//���������Ϣ
    EDBCT_GET1 = 2,//��ȡ1�������Ϣ
    EDBCT_GET2 = 3,//��ȡ2�������Ϣ
    EDBCT_SAVE = 4,//���������Ϣ
    EDBCT_CLR = 5,//��������Ϣ
    EDBCT_REG = 6,//ע���û�����Ϣ
    EDBCT_LOGINOFFINFO = 7, //��ҵĵ���ǳ���Ϣ
    EDBCT_SAVEPLUNDER = 10 , //��������Ӷ���Ϣ
    EDBCT_SAVERACE = 11 , //������Ҿ�������Ϣ
    EDBCT_SAVEBATTLEDATA = 12, //����ս����Ϣ
    EDBCT_GETBATTLEDATA = 13, //���ս����Ϣ
    EDBCT_CHAT = 14, //��ȡ���칫����Ϣ
    //EDBCT_GET_OLD = 15,//OLD��ȡ�����Ϣ
    EDBCT_SAVEBOSSB = 16,//����bossսģ����Ϣ
    EDBCT_SETPAYINFO = 17, //���ó�ֵ��Ϣ
    EDBCT_SETPAYPPROCESSED = 18, //���ó�ֵ���;
    EDBCT_SAVEBOSSBDATA = 19, //����bossսģ����Ϣ
    EDBCT_SETTONGBUPAYINFO = 20, //����ͬ����ֵ��Ϣ
    EDBCT_SETTONGBUPAYPPROCESSED = 21, //����ͬ����ֵ���;
    EDBCT_ACTIVITYENCOURAGE = 22, //�������ʱ��;
    EDBCT_UPDATE_CK_KEY = 23, //����CdKey
    EDBCT_SETMYPAYPPROCESSED = 24, //�����Լ��ĳ�ֵ
    EDBCT_FACTION = 25,		//����
    EDBCT_GETGSNOTICE = 26,	//��ȡgs��������
    EDBCT_GETOPRATEINGACTIVITY = 27,	//��ȡ��Ӫ�����
    EDBCT_CREATE_FACTION = 28,		//��������
    EDBCT_SAVE_PLAYER_CONSUME = 29, //����������Ѽ�¼
    EDBCT_GET_PLAYER_CONSUME = 30, //��ȡ������Ѽ�¼
    EDBCT_SETCENTERPAYPPROCESSED = 31, //�����ֵ���ĵĳ�ֵ
    EDBCT_GET_PRIVATEMSGLOG = 32, //��ȡ˽����Ϣ
    EDBCT_SAVEPRIVATEMSGLOG = 33, //����������־
    EDBCT_SAVE_COURAGE_DATA = 34, //�����������
    EDBCT_LEAVE_FACTION = 35,	//�˳�����
    EDBCT_SETRECREATEPAYPROCESSED = 36,//����ص�ʱ�̻����ݵ����
    EDBCT_SAVE_GVG_VIDEO          = 37, // ��������gvg�е�ս��¼��
	EDBCT_SAVE_GVG_ACTIVITY       = 38, // �������ɿ��ս�����
    EDBCT_SAVE_GVG_BUILD          = 39, // ������������ɿ��ս����
    EDBCT_SAVE_PLAYER_SNAP_SHOT   = 40, // ������ҵĿ���
    EDBCT_GET_PLAYER_SNAP_SHOT    = 41, // ��ȡ��ҵĿ���
    EDBCT_SAVEBATTLEDATA2 = 42, //����ս����Ϣ2
    EDBCT_GETBATTLEDATA2 = 43, //���ս����Ϣ2
	EDBCT_DELETE_GVG_GIFT = 44,//ɾ���������
	EDBCT_ADD_GVG_GIFT = 45,//�������
	EDBCT_DEL_PLAYER_LOG = 46,//ɾ�����ս��
	EDBCT_ADD_PLAYER_LOG = 47,//������ս��
    EDBCT_SAVE_GVG_ARENA = 48, // �������ɿ��ս�е�������������
    EDBCT_CLEAR_GVG_ACTIVITY = 49, // ������ɿ��ս�Ļ����
    EDBCT_CLEAR_GVG_VIDEO = 50, // ��������gvg�е�ս��¼��
    EDBCT_DEL_PLAYER_SNAP_SHOT    = 51, // ɾ����ҵĿ���
	EDBCT_SET_READ_PRIVATE_MSG	  = 52,	// �����Ѷ���Ϣ
	EDBCT_ADD_PLAYER_GIFT = 53,//��Ӹ������
	EDBCT_OPERATING_ACTIVITY = 54,//�����ʱ��
};

//PlayerExt����ģ��ö������
enum EPlayerExtDataType
{
    EMDT_CurState = 1, // ���� ��Ϣ
    EMDT_CommonBattleRcd = 2, // ���� ��Ϣ
    EMDT_EliteBattleRcd = 3, // ���� ��Ϣ
    EMDT_LocaleData = 4, // ���� ��Ϣ
    EMDT_LoginEncRecdData = 5, // ���� ��Ϣ
    EMDT_MoneyTreeData = 6, // ���� ��Ϣ
    EMDT_OnlineEncRecdData = 7, // ���� ��Ϣ
    EMDT_PhystrengthData = 8, // ���� ��Ϣ
    EMDT_JingJieData = 9, // ���� ��Ϣ
    EMDT_CropData = 10, // ���� ��Ϣ
    EMDT_ScienceTree = 11, // ���� ��Ϣ
    EMDT_FewParamData = 12, // ���� ��Ϣ
    EMDT_FormationInfo = 13, // ���� ��Ϣ
    EMDT_YabiaoInfo = 14, // ���� ��Ϣ
    EMDT_ClimbTowerBattleRcd = 15, // ���� ��Ϣ
    EMDT_ClimbTowerData = 16, // ���� ��Ϣ
    EMDT_EatBreadInfo = 17, // ���� ��Ϣ
    EMDT_YabiaoBattleLog = 18, // ���� ��Ϣ
    EMDT_AwakenData = 19, // ���� ��Ϣ
    EMDT_VipExtData = 20, // ���� ��Ϣ
    EMDT_LuaActivityRecordData = 21, // ���� ��Ϣ
    EMDT_GasCollectData = 22, // ���� ��Ϣ
    EMDT_BossBattleData = 23, // ���� ��Ϣ
    EMDT_ACTIVITY_ENCOURAGE = 24, //��ֵ����
    EMDT_BossBBL = 25, //bossսս��
    EMDT_RdChallengeData = 26, //�����ս��Ϣ
    EMDT_WorshipData = 27, //Ĥ����Ϣ
    EMDT_ScoreData = 28, //����������Ϣ
    EMDT_EquipComposeData = 29, //װ���ϳ���Ϣ
    EMDT_GatherScienceData = 30, //װ���ϳ���Ϣ
    EMDT_BegBlueData = 31, // ����¶��Ϣ
    EMDT_FriendsBaseData = 32, // ���ѻ�����Ϣ
    EMDT_PlayerFactionData = 33,// ���������Ϣ
    EMDT_Courage = 34, // ���������Ϣ
    EMDT_EquipMaster = 35, // װ����ͨ��Ϣ
	EMDT_ExchangeResultLog = 36, // ��ֵ������Ϣ
	EMDT_GVGData = 37,//GVG��Ϣ
	EMDT_SoulData = 38,//ս��
	EMDT_MedalData = 39,//ѫ��
	EMDT_PetData = 40,//����
};

enum EPlayerPvpDataType
{
    EMDT_RaceData = 100,
    EMDT_RaceBattleLog = 101,
    EMDT_PlunderBaseData = 102,
    EMDT_PlunderBattleLog = 103,
    EMDT_CaptureData = 104,
    EMDT_EnemyData = 105,
};


//�����չ��Ϣ����
enum EHeroExtDataType
{
    EHEDT_Equip = 1, //װ�� ��Ϣ
    EHEDT_Drug = 2, //��ҩ ��Ϣ
    EHEDT_Godweapon = 3, //���� ��Ϣ
    EHEDT_Skill = 4, //���� ��Ϣ
    EHEDT_Study = 5, //�ĵ� ��Ϣ
    EHEDT_Absorb = 6, //���鴫����Ϣ
	EHEDT_Jewelry = 7,//��Ʒ��Ϣ
	EHEDT_SOUL = 8, // װ��ս����Ϣ
};

//ģ������
enum EModuleDataType
{
    EMDT_BossBattle = 1, //bossս
    EMDT_COURAGE = 3,	 //����
    EMDT_GVG = 4,	     //���ս
};


enum ESaveDataType
{
    EDT_PlayerBase = 1,
    EDT_PlayerExt ,
    EDT_PlayerBag ,
    EDT_PlayerBuildAll ,
    EDT_PlayerBuild ,
    EDT_PlayerHeroAll ,
    EDT_PlayerHeroBase ,
    EDT_PlayerHeroExt ,
    EDT_PlayerInstanceAll ,
    EDT_PlayerInstance ,
    EDT_PlayerTaskAll,
    EDT_PlayerTask,
};

class CPlayerDiff;
typedef map<UINT32, CPlayerDiff*> CPlayerDiffMap;
typedef CPlayerDiffMap::iterator CPlayerDiffMapItr;

class CFactionDiff;
typedef map<UINT32, CFactionDiff*> CFactionDiffMap;
typedef CFactionDiffMap::iterator CFactionDiffMapItr;

typedef map<UINT32, UINT64> CMapSavePlayerTime;
typedef CMapSavePlayerTime::iterator CMapSavePlayerTimeItr;




#define DB_ERROR_DIR_MAIN_NAME "db_error"

struct SErrorInfo
{
    SErrorInfo()
    {
		qwFileTimes = 0;
        strFilePath = "";
    }

    ~SErrorInfo()
    {

    }
	UINT64	qwFileTimes;
    string strFilePath; //�ļ�·��
};

#define ERROR_FILE_PREFIX_PLAYER	"E"
#define ERROR_FILE_PREFIX_FACTION	"F"

enum ERROR_SQL_MODULE
{
    ERROR_PLAYER = 1,
    ERROR_FACTION = 2,
};

class CDBMgr
{
    typedef map<UINT64, SErrorInfo> CErrorInfoMap;
    typedef CErrorInfoMap::iterator CErrorInfoMapItr;
public:
    CDBMgr();
    ~CDBMgr();

public:
    BOOL Init();
    VOID Release();
    BOOL Run(BOOL bSaveAll = FALSE);
    BOOL AddCommand(SGDP::ISDDBCommand* poDBCommand);
    BOOL AddRecordCommand( SGDP::ISDDBCommand *poDBCommand );
    BOOL AddPayCommand( SGDP::ISDDBCommand *poDBCommand );
    BOOL AddCfgCommand( SGDP::ISDDBCommand *poDBCommand );
    VOID AddDBCommandCount();
    VOID AddRecordDBCommandCount();
    VOID DecreaseDBCommandCount();
    VOID DecreaseRecordDBComandCount();
    UINT32 GetDBCommandCount();
    UINT32 GetRecordDBCommandCount();
    SGDP::ISDDBSession* GetDBSession();
    SGDP::ISDDBSession* GetRecordDBSession();

    VOID SetStartData( UINT32 dwPlayerID, const DT_PLAYER_NOPVP_DATA &data );
    const DT_PLAYER_NOPVP_DATA* GetLastData( UINT32 dwPlayerID );
    VOID StartDiff( UINT32 dwPlayerID, const DT_PLAYER_NOPVP_DATA &data );
    VOID EndDiff(UINT32 dwPlayerID);


    BOOL Changed(UINT32 dwFactionID, const DT_FACTION_DATA &stDT_FACTION_DATA);
    BOOL HaveChanged(UINT32 dwFactionID, const DT_FACTION_DATA &stDT_FACTION_DATA);


    CPlayerDiff* FindDiff(UINT32 dwPlayerID);
    BOOL HaveChanged(UINT32 dwPlayerID, ESaveDataType eTableType, UINT16 wKey1 = 0, UINT16 wKey2 = 0, UINT16 wKey3 = 0);

    VOID OnPlayerRelease(UINT32 dwPlayerID);

    VOID OnFactionRelease(UINT32 dwFactionID);

    SGDP::ISDDBSession* GetCfgDBSession();
    SGDP::ISDDBSession* GetPayDBSession();
    //SGDP::ISDDBSession* GetTmpDBSession() { return m_pTmpDBSession; }

    //���Ӳɼ���Ϣ
    BOOL AddRecordData( EDBCmdType eDbCmdType, void *pUserData );

    VOID SetSaveProcessed();

    VOID AddErrorInfo(ERROR_SQL_MODULE emModule, UINT32 dwKey, const vector<string> &vecStrErrorSql );
    BOOL IsExistErrorInfo(ERROR_SQL_MODULE emModule,  UINT32 dwKey );
    BOOL DeleteErrorInfo(ERROR_SQL_MODULE emModule,  UINT32 dwKey );
    vector<string> GetSqlList(ERROR_SQL_MODULE emModule,  UINT32 dwKey );
	BOOL ReadRetreatePlayerData(const char* FileName,UINT32 unAddGold,UINT32 unAddRMB,UINT32 dwPlayerID);//�Ը������ݽ��лص�
	BOOL	GetRetreateMaxIndex(UINT32 &dwIndex);//��ó�ֵ��¼��������������ID
	BOOL GetRechargeGold(UINT32 dwPlayerId,UINT32 &dwAddGold,UINT32 &dwAddRMB,UINT64 dwTime);//�����ҵ�ǰ��ʧ��Ԫ���������ֵ
    UINT64 GetErrorFileUpdateTime(ERROR_SQL_MODULE emModule,  UINT32 dwKey );

	BOOL CheckAndProcessBackupFactionSql(UINT32 dwFactionID );
	BOOL FindPlayerSaveTime(UINT32 dwPlayerID);
public:
    /////////////////
    CBaseDBCMD*	CreateCmd(EDBCmdType eDbCmdType);
    VOID			FreeCmd(CBaseDBCMD* poBaseDBCMD);
    VOID			SaveDataToDB();
    VOID			SaveAllDataToDB();

protected:
    //VOID		SaveErrorID();

private:
    CDBMgr(const CDBMgr& rhs);
    CDBMgr& operator = (const CDBMgr& rhs);

private:
    SGDP::ISDDBModule*  m_pDBModule;
    SGDP::ISDDBSession* m_pDBSession;
    SGDP::ISDDBSession* m_pCfgDBSession;
    //SGDP::ISDDBSession* m_pTmpDBSession;

    //�ɼ����ݿ����

    SGDP::ISDDBModule*  m_pDBRecordModule; //���ݲɼ���
    SGDP::ISDDBSession* m_pDBRecordSession; //���ݲɼ����ݿ�ĻỰ

    //app��ֵ���
    SGDP::ISDDBModule*  m_pDBPayModule; //���ݲɼ���
    SGDP::ISDDBSession* m_pDBPaySession; //���ݲɼ����ݿ�ĻỰ

    CSDObjectPool<CClrPlayerDataCMD, CSDMutex>	m_oCClrPlayerDataCMDPool;
    CSDObjectPool<CGetPlayerDataCMD, CSDMutex>	m_oCGetPlayerDataCMDPool;
    //CSDObjectPool<CGetPlayerDataCMD_OLD, CSDMutex>	m_oCGetPlayerDataCMDPoolOld;
    CSDObjectPool<CGetPlayerDataCMD2, CSDMutex>	m_oCGetPlayerDataCMD2Pool;
    CSDObjectPool<CSavePlayerDataCMD, CSDMutex>	m_oCSavePlayerDataCMDPool;
    CSDObjectPool<CCreatePlayerCMD, CSDMutex>	m_oCCreatePlayerCMDPool;
    CSDObjectPool<CRecordPlayerLoginoff, CSDMutex> m_oCCRecordPlayerLoginoffPool; //��ҵ���ǳ��ɼ����ݳ�
    CSDObjectPool<CSavePlayersPlunderDataCMD, CSDMutex> m_oCSavePlayersPlunderDataCMDPool; //��һ��Ԫ����¼
    CSDObjectPool<CSavePlayersRaceDataCMD, CSDMutex> m_oCSavePlayersRaceDataCMDPool; //��һ��Ԫ����¼
    CSDObjectPool<CRecordBattleData, CSDMutex>	m_oCRecordPlayerBattleDataCMDPool; //���ս����¼
    CSDObjectPool<CGetBattleData, CSDMutex>		m_oCGetPlayerBattleDataCMDPool; //���ս����¼
    CSDObjectPool<CRecordBattleData2, CSDMutex>	m_oCRecordPlayerBattleData2CMDPool; //���ս����¼2
    CSDObjectPool<CGetBattleData2, CSDMutex>		m_oCGetPlayerBattleData2CMDPool; //���ս����¼2
    CSDObjectPool<CGetChatCMD, CSDMutex>		m_oCGetChatCMDPool; //������칫����Ϣ
    CSDObjectPool<CSaveBossBDataCMD, CSDMutex>	m_oSaveBossBDataCMDPool; //bossս��Ϣ
    CSDObjectPool<CSetAppPayInfo, CSDMutex>		m_oCSetAppPayCMDPool; //���ó�ֵ��Ϣ
    CSDObjectPool<CSetAppPayProcessed, CSDMutex> m_oCSetAppPayProcessedCMDPool; //���ó�ֵ��Ϣ����ɹ�
    CSDObjectPool<CSetTongBuPayInfo, CSDMutex>		m_oCSetTongBuPayCMDPool; //����ͬ����ֵ��Ϣ
    CSDObjectPool<CSetTongBuPayProcessed, CSDMutex>	m_oCSetTongBuPayProcessedCMDPool; //���ó�ֵ��Ϣ����ɹ�
    CSDObjectPool<CActivityEncourageCMD, CSDMutex>	m_oCActivityEncourageCMDPool; //�������Ϣ����ɹ�
    CSDObjectPool<CUpdateCdKeyCmd, CSDMutex>			m_oUpdateCdKeyCMDPool; //�������Ϣ����ɹ�
    CSDObjectPool<CSetMyPayProcessed, CSDMutex>		m_oSetMyPayProcessedCMDPool; //�ҷ���ֵ
    CSDObjectPool<CSaveFactionDataCMD, CSDMutex>		m_oSaveFactionCMDPool; //�������Ϣ����ɹ�
    CSDObjectPool<CGetGsNoticeCMD, CSDMutex>		m_oGetGsNoticeCMDPool; //��ȡgs����
    CSDObjectPool<CGetOprateingActivityCMD, CSDMutex>	m_oGetOprateingActivityCMDPool; //��ȡ��Ӫ�����
    CSDObjectPool<CCreateFactionDataCMD, CSDMutex>	m_oCreateFactionDataCMDPool; //��ȡ��Ӫ�����
    CSDObjectPool<CSavePlayerConsume, CSDMutex>		m_oSavePlayerConsumeCMDPool; //����������Ѽ�¼
    CSDObjectPool<CGetPlayerConsume, CSDMutex>		m_oGetPlayerConsumeCMDPool; //����������Ѽ�¼
    CSDObjectPool<CSetCenterPayProcessed, CSDMutex>	m_oSetCenterPayProcessedCMDPool; //��ֵ����
    CSDObjectPool<CGetPrivateMsgLogCmd, CSDMutex>	m_oGetPrivateMsgLogCMDPool; //��ȡ�����¼
    CSDObjectPool<CSavePrivateMsgLogCmd, CSDMutex>	m_oSavePrivateMsgLogCMDPool; //��ȡ�����¼
    CSDObjectPool<CSaveCourageDataCMD, CSDMutex>		m_oSaveCourageCMDPool; //���������������
    CSDObjectPool<CLeaveFactionDataCMD, CSDMutex>   m_oLeaveFactionDataCMDPool;	//�˳�����
    CSDObjectPool<CSetRecreatePayProcessed, CSDMutex>   m_oSetRecreateProcessedCMDPool;	//�ص�
    CSDObjectPool<CSaveGvGVideoCMD, CSDMutex>       m_oSaveGvGVideoCMDPool;	//����gvg¼��
    CSDObjectPool<CSaveGvGActivityCMD, CSDMutex>            m_oSaveGvGActivityCMDPool;	//�������ɿ��ս�����
	CSDObjectPool<CSavePlayerSnapShotCMD, CSDMutex> m_oSavePlayerSnapShotCMDPool;	//������ҵĿ�������
    CSDObjectPool<CDelPlayerSnapShotCMD, CSDMutex> m_oDelPlayerSnapShotCMDPool;	//������ҵĿ�������
	CSDObjectPool<CSaveGvGBuildCMD, CSDMutex>       m_oSaveGvGBuildCMDPool;//GVG������Ϣ
	CSDObjectPool<CDeleteOverGvGift, CSDMutex>      m_oDeleteGvGiftCMDPool;//ȥ������GIFT
	CSDObjectPool<CAddGvGiftCMD, CSDMutex>          m_oAddGvGiftCMDPool;
	CSDObjectPool<CAddPlayersLogCMD, CSDMutex>      m_oAddPlayersLogCMDPool;
	CSDObjectPool<CDelPlayerLogCMD, CSDMutex>       m_oDelPlayersLogCMDPool;
    CSDObjectPool<CSaveGvGArenaCMD, CSDMutex>       m_oSaveGvGArenaCMDPool;	//�������ɿ��ս����������
    CSDObjectPool<CClearGvGVideoCMD, CSDMutex>      m_oClearGvGVideoCMDPool;	//������ɶ�ս¼��
    CSDObjectPool<CClearGvGActivityCMD, CSDMutex>      m_oClearGvGActivityCMDPool;	//�����һ�����ɿ��ս�Ļ����
	CSDObjectPool<CSetReadPrivateMsgCMD, CSDMutex>  m_oSetReadPrivateMsgCMDPool;//�����Ѷ�˽����Ϣ
	CSDObjectPool<CAddPlayerGiftCMD, CSDMutex> m_oAddPlayerGiftCMDPool;//�����Ҹ������
	CSDObjectPool<COperatingActivityCMD, CSDMutex> m_oOperatingActivityCMDPool;//�����ʱ��

    CFactionDiffMap			m_mapFactionSaveDiff;
    CPlayerDiffMap			m_mapPlayerSaveDiff; //���ڱȽ��Ƿ���Ҫ����
    CSDMutex					m_oDiffMutex;
    UINT64					m_qwLastFillQueueTick; // �ϴα�����ҵ�ʱ��
    UINT64					m_qwLastSaveTick; //�ϴα�����ҵ�tick
    BOOL						m_bSaveProcessed;
    CID2PlayerVec				m_vecPlayerCache;

	CSDMutex           m_oSaveMutex;//������
	CMapSavePlayerTime m_mapSavePlayerTime;

    //��¼���������Ϣ
    CSDMutex			m_muErrorInfo;
    CErrorInfoMap		m_mapErrorInfo;
};

#endif

