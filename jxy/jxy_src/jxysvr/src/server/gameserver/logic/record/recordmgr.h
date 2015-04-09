#ifndef _RECORD_MGR_H_
#define _RECORD_MGR_H_

#include <sdsingleton.h>
#include <sdtype.h>
#include <sdstring.h>
#include <dll/sdu/sdthread.h>
#include <deque>
#include <map>
#include <list>
#include "recordmodule.h"
#include <dll/sddb/sddb.h>


#define ADD_STORY_STR "addstory"
#define DEC_STORY_STR "decstory"
#define ADD_COIN_STR "addcoin"
#define DEC_COIN_STR "deccoin"
#define ADD_GOLD_STR "addgold"
#define DEC_GOLD_STR "decgold"
#define ADD_SCIENCE_STR "addscience"
#define DEC_SCIENCE_STR "decscience"
#define ADD_PHYSTRENGTH_STR "addphystrength"
#define DEC_PHYSTRENGTH_STR "decphystrength"
#define ADD_BLUEGAS_STR "addbluegas"
#define DEC_BLUEGAS_STR "decbluegas"
#define ADD_PURPLEGAS_STR "addpurplegas"
#define DEC_PURPLEGAS_STR "decpurplegas"
#define ADD_ITEM_STR "additem"
#define DEC_ITEM_STR "decitem"
#define ADD_STUDY_EXP_STR "addstudyexp"
#define DEC_STUDY_EXP_STR "decstudyexp"
#define ADD_STUDY_STR "addstudy"
#define DEC_STUDY_STR "decstudy"
#define ADD_JINGJIE_STR "addjingjie"
#define DEC_JINGJIE_STR "decjingjie"

#define RECORD_CHART_MAX_VIP   12       // ������Դ����ͳ�Ʊ���ʱ�����vip�������12���������vip12+����
#define RECORD_CHART_MAX_LEVEL 120      // ������Դ����ͳ�Ʊ���ʱ������������120���������120+������

#define RECORD_CHART_LEVEL_SECTION_CNT ((RECORD_CHART_MAX_LEVEL / 10) + 1)  // ������Դ����ͳ��ʱ����ҵĵȼ�����Ϊ13�����䣺[1-9]��[10-19]��[20-29].........[110-119]��[120+]
#define RECORD_CHART_VIP_SECTION_CNT   (RECORD_CHART_MAX_VIP + 2)           // ������Դ����ͳ��ʱ��vip�ȼ���Ϊ14������vip0��vip1��vip2��vip3.....vip12��vip12+


class CNGString;

//ģ���ö��
enum ERecordModule
{
    //����
    ERM_ADDSTORY = 0,
    ERM_DECSTORY = 1,

    //ͭǮ
    ERM_ADDCOIN = 2,
    ERM_DECCOIN = 3,

    //����
    ERM_ADDSCIENCE = 4,
    ERM_DECSCIENCE = 5,

    //����
    ERM_ADDPHYSTRENGTH = 6,
    ERM_DECPHYSTRENGTH = 7,

    //����
    ERM_ADDBLUEGAS = 8,
    ERM_DECBLUEGAS = 9,

    //����
    ERM_ADDPURPLEGAS = 10,
    ERM_DECPURPLEGAS = 11,

    //Ԫ������
    ERM_ADDGOLD = 12,
    ERM_DECGOLD = 13,

    //��Ʒ����
    ERM_ADDITEM = 14,
    ERM_DECITEM = 15,

    //����
    ERM_ADDJINGJIE = 16,
    ERM_DECJINGJIE = 17,

    //����ĵþ���
    ERM_ADDSTUDYEXP = 18,
    ERM_DECSTUDYEXP = 19,

    //����ĵ�
    ERM_ADDSTUDY = 20,
    ERM_DECSTUDY = 21,

    //�����Ƭ
    ERM_ADDSTUDYCLIP = 22,
    ERM_DECSTUDYCLIP = 23,

    // ����ѫ��
    ERM_ADDMEDAL = 24,
    ERM_DECMEDAL = 25,

    //�Ź�
    ERM_ADDDOORSTRIBUTE = 26,
    ERM_DECDOORSTRIBUTE = 27,

    //�����ʽ�
    ERM_ADDFACTIONFUNDS = 28,
    ERM_DECFACTIONFUNDS = 29,

    // ��Ҹ��˲��������磬��������˳��ĸ����ɣ�������Ҹ���֮��ģ�
    ERM_PLAYER_OPERATE = 30,

    // ���ɿ��ս
    ERM_GVG_ACTIVITY = 31,

	// ս��
	ERM_ADDSOUL = 32,
	ERM_DECSOUL = 33,
	ERM_REFLASHSOUL = 34,

	// ����
    ERM_PETREP_ADDPET = 35, // ʹ����迨Ƭ�������
    ERM_REFINE_ADDPET = 36, // ���������裨�������ܣ����ϳɣ�
    ERM_USEITEM_ADDPET = 37, // ʹ����走�������
    ERM_REFINE_REMOVEPET = 38, // �����Ƴ���裨�������ܣ����ϳɣ�
    ERM_PETMERGE_REMOVEPET = 39, // �ں��Ƴ���裨�ںϹ��ܣ������ɣ�
    ERM_PET_UPSTAR = 40, // �������
    ERM_PET_FIRSTDRAW = 41, // ���ιʳ���ˣ�ιʳ���ܣ�
    ERM_PET_RESETDRAW = 42, // ���ιʳ��ҡ��ιʳ���ܣ�
    ERM_PET_CONFIRMFEED = 43, // ���ȷ��ιʳ��ιʳ���ܣ�
    ERM_PET_MERGE = 44, // �ں���裨�ںϹ��ܣ������ɣ�
    ERM_PET_BUYSTOREITEM = 45, // ��������̳ǵ���
    ERM_PET_WASHQUALITY = 46, // ���ϴ����
    ERM_PET_INHERIT = 47, // ���̳�
    ERM_GM_ADDPET = 48, // gm�ӿ�������

    // ��������
    ERM_FLY = 60,

	//ѫ��
	ERM_ADD_MEDAL = 61,//����ѫ��
	ERM_DEC_MEDAL = 62,//ѫ��ʧЧ


};

typedef std::vector<UINT64> DiffVipHistoryVec;   // ��ͬvip�ȼ�����Դ����, ��Ӧ{vip0��, vip1��, vip2��..... vip12+}����Դ����
typedef std::vector<UINT64> DiffLevelHistoryVec; // ��ͬ��ҵȼ��������Դ����, ��Ӧ{1-9��, 10����, 20����....., 120��+}����Դ����

typedef std::vector<std::string> CSqlVec;

// ���ĳ����Դ����������ͳ��
struct ConsumeRow
{
    ConsumeRow()
        : wModuleType(0)
        , wOpType(0)
        , qwOpTotal(0)
        , dwOpCnt(0)
        , dwMaxOpVal(0)
        , dwMinOpVal(0)
        , bSavedToDB(TRUE)
    {
        vecVipSumUp.resize(RECORD_CHART_VIP_SECTION_CNT);
        vecLevelSumUp.resize(RECORD_CHART_LEVEL_SECTION_CNT);
    }

    DiffVipHistoryVec vecVipSumUp;     // ��vip�ȼ���ҵ�����
    DiffLevelHistoryVec vecLevelSumUp; // ���ȼ�������ҵ�����

    UINT16 wModuleType;
    UINT16 wOpType;

    UINT64 qwOpTotal;       // �ܶ�
    UINT32 dwOpCnt;         // ������������ڸ�����Դ�Ϲ������˶��ٴ�
    UINT32 dwMaxOpVal;      // ������ҵĵ�����߼�¼��������ߵ�һ�εõ���xxxԪ������������xxxԪ��
    UINT32 dwMinOpVal;      // ������ҵĵ�����ͼ�¼���������ٵ�һ�εõ���xxxԪ������������xxxԪ��

    BOOL bSavedToDB;         // ���ڱ�ʶ�����Ƿ���ͬ�������ݿ�
};

typedef std::map<UINT64, ConsumeRow> ConsumeChartMap;          // ��Դ����map, key = ���ѵ���Դ���� + ��Ӧ��������, val = ��Ӧ����Դ����
typedef std::map<UINT64, ConsumeChartMap> Day2ConsumeChartMap; // �������Դ����map, key = ��, val = ���������ͳ�����

// �������ͳ�Ʊ���ͳ��ÿ����ҶԸ�����Դ�����ĺͻ��������Լ���Ҷ��Ǵ���Щ;�������Щ��Դ
class CConsumeChartMgr
{
    DECLARE_SINGLETON(CConsumeChartMgr);

public:
    CConsumeChartMgr();

    BOOL Init();

public:
    // ͳ����һ�û�������Դ�����
    VOID CountUp(UINT16 wPlayerLevel, BYTE byVipLevel, UINT16 wModuleType, UINT16 wOpType, UINT32 dwOpValue, CSDDateTime &oOpTime);

    // �����ݿ���ȡ���������Դ����ͳ������
    BOOL LoadFromDB();

    // �ɹ�������е�δͬ����־��Ϊ��ͬ��������������ͳ�Ƽ�¼
    void OnSaveDBSuccess();

    // ������ͳ�ƴ������ݿ�������±䶯�������ݣ�
    BOOL SaveToDB();

    // �����ϴα��浽db��ʱ��Ϊ��ǰʱ��
    void ResetLastSaveTime();
    UINT64 GetLastSaveTime()
    {
        return m_qwLastSaveTime;
    }

private:
    // ��ȡ������������ݿ��ֶ�sql��䣬���صĽ�����磺replace into ophistory(Date, ModuleType, OpType, OpValue...... vip0, vip1, vip2, ......, level_1_9, level_10, .......) values
    string& BuildInsertFieldSql();

    // ����Ҫ���µ���������ȡ����ƴ�ӳ�sql��䣬���ص��ַ���������磺("2013/12/10 00:00:00", 4, 5, 0, 0, 0.......), ("2013/12/10 00:00:00", 4, 5, 0, 0, 0.......),
    string BuildInsertValueSql();

    // ��������ͳ�Ƽ�¼
    void ClearYesterday();

private:
    // ��Դͳ��map�����map���ڴ�ռ�ù������£���69KB���£���ȫ���Գ��ܣ�
    Day2ConsumeChartMap m_mapRecord;

    // �ϴδ洢�����ݿ��ʱ��
    UINT64 m_qwLastSaveTime;

    // ����������ƴ��sql����ڼ���ֹ���ݸ���
    CSDMutex m_mutex;
};


class CPlayer;


class CRecordMgr: public CSDThread
{
    DECLARE_SINGLETON(CRecordMgr);

    typedef map<INT32, CRecordModule*> MAP_RECORD_MODULE_TYPE;
public:
    CRecordMgr();
    virtual ~CRecordMgr();
    BOOL Init();
    VOID UnInit();

    	

    // ��¼Ԫ������
    BOOL RecordGold(UINT16 wZoneID, UINT32 dwPlayerID, UINT16 wPlayerLevel, UINT16 wVipLevel, ERecordModule wModuleType, UINT16 wOpType,
        UINT32 dwOpRMBGold, UINT32 dwOpRMBGoldGift, UINT32 dwOpGmGold, UINT32 dwOpGameGold, 
        UINT32 dwAfterRMBGold, UINT32 dwAfterRMBGoldGift, UINT32 dwAfterGmGold, UINT64 qwAfterGameGold, 
        UINT64 qwParam1 = 0, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0, string strComment = "");

    BOOL RecordInfo(UINT32 dwPlayerID, UINT16 wModuleType, UINT16 wOpType, UINT32 dwOpValue, UINT64 qwAfterOpValue, UINT16 wPlayerLevel, UINT16 wVipLevel,
                    UINT64 qwParam1 = 0, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0, string strComment = "");

    ISDDBSession* GetRecordDBSession()
    {
        return m_pDBRecordSession;
    }

private:
    const static UINT32 ms_dwSleepTime = 1; //˯�ߵ�ʱ����
protected:
    //�߳�
    virtual VOID  ThrdProc();

private:
    VOID Stop();

    BOOL WriteDataToSqlServer();

    // ��ֳ��µ�Ԫ����¼��
    BOOL SplitNewGoldRecordTable(std::string &strNewTableName);

    // ��Ԫ��������¼�������ݿ�
    BOOL SaveGoldRecordToDB();    

    VOID AddSaveErrorSql(const string& strSql, CHAR szErrFileName[], BOOL bTrunc = FALSE);
    list<string> GetErrorSql(CHAR szErrFileName[]);

    VOID ExeErrFileSql();
    VOID ExeGoldErrFileSql();

private:
    BOOL m_bStop;
    MAP_RECORD_MODULE_TYPE m_mapRecordModule;

    time_t m_tLastWriteTime; //�ϴ�д�����ݿ��ʱ��
    SGDP::ISDDBModule*  m_pDBRecordModule; //���ݿ��¼ģ��
    SGDP::ISDDBSession* m_pDBRecordSession; //���ݿ�����
    CRecordModule*		m_poRecordModule;

    SGDP::ISDDBModule*  m_poGameDBModule;  // ��Ϸ���ݿ��ģ�飬���ڴ����͹ر�����Ϸ���ݿ�ĻỰ
    SGDP::ISDDBSession* m_poGameDBSession; // ����Ϸ���ݿ�ĻỰ���ӣ�ע�⣬�����CDBMgr�е���Ϸ���ݿ������ǲ�һ���ģ�����Ҳ���ܺ��ã�

    CSqlVec m_vecGoldSql; // �洢���Ԫ�����Ѽ�¼��sql����б�

    UINT32 m_dwCachedYear; // ���ڵ����£���201407
public:

    //�������
    enum EAddStoryType
    {
        EASTT_CROP = 1,		//��ֲ
        EASTT_INSTANCE = 2, //�������
        EASTT_TASK = 3,		//������
        EASTT_GMCOMMAND = 4, //GM����
        EASTT_ENCOURAGE = 5, //�����
        EASTT_RATING_SCORE = 6, //����ͨ��
        EASTT_RATING_SCORE_ACCUMULATE = 7, //�ۻ�����
        EASTT_BEG_BLUE_GAS = 8, //����¶����
        EASTT_GETGIVEGM = 9, //��Դ����GM

		EASTT_VIP_GIFT = 10,//VIP���

        EASTT_COURAGE = 11, //������������
		EASTT_GVG_GIFT = 12,//���ս��� 

    };

    //ʹ������
    enum EDecStoryType
    {
        EDST_UPDATESCIENCE = 1, //�����Ƽ���,p2��ʾ�Ƽ�������,p3��ʾ�Ƽ��ĵȼ�
        EDST_BOSSB_INSPIREPOWER = 2, //bossս����
        EDST_GETGIVEGM = 3, //��Դ����GM
		EDST_UPGRADE_FORMATION = 4, //������
		EDST_EXCHANGE_STORE = 5,//�̵�
    };

    //����ͭ��
    enum EAddCoinType
    {
        EACT_USEGOODS = 1,			//ʹ����Ʒ��û��
        EACT_ONLINEENCOURAGE = 2,	//���߽������
        EACT_GMCOMMAND = 3,			//GM������
        EACT_INSTANCE = 4,			//������û��
        EACT_INSTANCEGOODS = 5,		//����ֱ��ʹ����Ʒ���
        EACT_SELLGOODS = 6,			//������Ʒ��û��
        EACT_SELLEQUIP = 7,			//����װ�����
        EACT_GUIDEROCKMONEY = 8,		//�вƽ����������ͭǮ
        EACT_ROCKMONEY = 9,			//�вƽ������ͭǮ
        EACT_CROP = 10,				//�вƽ������ͭǮ
        EACT_PLUNDER = 11,			//��²
        EACT_RACECHALLENGE = 12,		//������
        EACT_RANK = 13,				//��������
        EACT_TASK = 14,				//����
        EACT_YABIAO = 15,			//Ѻ��
        EACT_EATBREAD = 16,			//�԰���
        EACT_USELOGINGOODS = 17,		//��¼����ʹ����Ʒ
        EACT_AWAKEN = 18,			//������
        EACT_JIEBIAO = 19,			//����
        EACT_LEVY = 20,				//����
        EACT_BOSSB_HURTENC = 21,				//BOSSս �˺�����
        EACT_BOSSB_HEROENC = 22,				//BOSSս Ӣ�۽���
        EACT_BOSSB_TOPENC = 23,				//BOSSս ��������
        EACT_BOSSB_KILLENC = 24,				//BOSSս ��ɱ����
        EACT_ENCOURAGE = 25,				//�����
        EACT_RATING_SCORE = 26,				//����ͨ�ؽ���
        EACT_RATING_SCORE_ACCUMULATE = 27,	//�����ۻ�����
        EACT_GETGIVEGM = 28,			//��Դ����GM
		EACT_VIP_GIFT = 29,				//VIP���
		EACT_GVG_GIFT = 30,//���ս���
		EACT_GVG_GAMBLE = 31,//Ѻע
    };


    //ʹ��ͭ��
    enum EDecCoinType
    {
        EDCT_CROP = 1,				//��ֲ�ؿ鿪������ͭǮ��	param2��ʾ�ؿ��ID
        EDCT_UPDATEATTR = 2,		//������������ͭǮ��		param2��ʾ�������ͣ�param3��ʾǿ��������Լ���
        EDCT_INCREASESIZE = 3,		//������������ͭǮ
        EDCT_SHOPBUY = 4,			//�̵깺������ͭǮ��		p2��ʾTabID��p3��ʾItemKindID��p4��ʾPileCount
        EDCT_AWAKEN = 5,			//�������ͭǮ
        EDCT_GODWEAPON = 6,			//���꿪������������ͭǮ,p2��ʾ���ID��p3Ʒ�ʣ�p4��ʾlevel
        EDCT_STRENGTHEN = 7,		//װ��ǿ������ͭǮ��p2��ʾ���ID��p3��ʾװ��ID��p4��ʾǿ����ĵȼ�
        EDCT_UPGASLEVEL = 8,		//�����������ĵȼ�����ͭǮ
        EDCT_GENGAS = 9,			//������������ͭǮ
        EDCT_RDCREFRESH = 10,		//�����սˢ������ͭǮ
        EDCT_WORSHIP = 11,			//Ĥ������ͭǮ
        EDCT_ENCOURAGE = 12,		//���������ͭǮ
        EDCT_EXCHANGESTUDY = 13,		//�һ���������ͭǮ
        EDCT_GM = 14,				//GM����ͭǮ
        EDCT_GATHERSCIENCE = 15,		//�ۻ�����ͭǮ
        EDCT_GETGIVEGM = 16,		//��Դ����GM
        EDCT_FACTION = 17,		//������������ͭǮ
        EDCT_VISITHERO = 21,		//��ļ�佫
        EDCT_FACTION_DOORSTRIBUTE  = 22, //�Ź�
        EDCT_SEND_FLOWER  = 23, //���ʻ�
        EDCT_DRINK_WINE = 24,		//����
		EDCT_FIND_BACK_DOORSTRUBUTE = 25,	//�һ��Ź�
		EDCT_VIP_GIFT = 26,//VIP���
		EDCT_GENERATE_JEWELRY = 27,//������Ʒ
		EDCT_RESOLVE_JEWELRY = 28,//�ֽ���Ʒ
		EDCT_DEVOUR_SOUL = 29,//����ս�꿨
        EDCT_EQUIP_MAKE = 30, // װ������
		EDCT_EXCHANGE_STORE = 31,//�̵�
		EDCT_NORMAL_INHERIT = 32,// ��ͨ�̳�
		EDCT_DEVOR_NEIDAN = 33,//�����ڵ�
    };

    //�������
    enum EAddScienceType
    {
        EAST_CROP = 1, //��ֲ���
        EAST_TASK = 2, //������
        EAST_RACECHALLENGE = 3, //��������ս���
        EAST_RACERANK = 4, //��������������
        EAST_USEGOODS = 5, //ʹ����Ʒ,p2Ϊ��ƷID
        EAST_ONLINEENCOURAGE = 6, //���߽���
        EAST_PLUNDER = 7, //��²
        EAST_GMCOMMAND = 8, //GM����
        EAST_FREEGODWEAPON = 9, //�ͷ�����
        EAST_USELOGINGOODS = 10, //�Զ�ʹ�õ�¼��Ʒ����
        EAST_MELT = 11, //װ������
        EAST_YABIAO = 12, //Ѻ��
        EAST_ENCOURAGE = 13, //�����
        EAST_RATING_SCORE = 14, //����ͨ��
        EAST_RATING_SCORE_ACCUMULATE = 15, //�ۻ�����
        EAST_GATHERSCIENCE = 16,//�ۻ�
        EAST_GAS = 17, //����
        EAST_GETGIVEGM = 18, //��Դ����GM
		EAST_VIP_GIFT = 19, //VIP���
		EAST_GVG_GIFT = 20,//���ս���
    };

    //ʹ������
    enum EDecScienceType
    {
        EDSCT_GODWEAPONUPGRADE = 1, //��������
        EDSCT_GETGIVEGM = 2, //��Դ����GM
    };

    //�������
    enum EAddPhyStrengthType
    {
        EAPST_RECOVER = 1, //�Զ��ָ�����
        EAPST_TASK = 2, //����ָ�����
        EAPST_ONLINEENCOURAGE = 3, //���߽���
        EAPST_ONLINEUSEGOODS = 4, //���߽���ֱ��ʹ����Ʒ
        EAPST_GMCOMMAND = 5, //GM����
        EAPST_USEGOOD = 6, //ʹ����Ʒ
        EAPST_EATBREAD = 7, //�԰���
        EAPST_BUY = 8, //��������
        EAPST_LOGINUSRGOOD = 9, //��¼����ֱ��ʹ����Ʒ
        EAPST_ENCOURAGE = 10, //�����
        EAPST_RATING_SCORE = 11, //����ͨ��
        EAPST_RATING_SCORE_ACCUMULATE = 12, //�ۻ�����
        EAPST_GETGIVEGM = 13, //��Դ����GM
        EAPST_DRINKWINE = 14, //����
		EAPST_VIP_GIFT = 15, //VIP���
		EAPST_GVG_GIFT = 16, //���ս��� 
    };

    enum EDecPhyStrengthType
    {
        EDPST_INSTANCE = 1, //����������
        EDPST_ONHOOK = 2, //�һ���������
        EDPST_GETGIVEGM = 3, //��Դ����GM
		EDPST_OUT_BOUND = 4,//���⴫
    };

    //�������
    enum EAddBlueGasType
    {
        EABGT_JINGJIECOLLECT = 1, //�������ռ�
        EABGT_GM = 2, //�������ռ�
        EABGT_TASK = 3, //������
        EABGT_ENCOURAGE = 4, //�����
        EABGT_GEMCONVERT = 5, //��ʯת��
        EABGT_USEGOODS = 6, //��Ʒʹ��
        EABGT_INSTANCEBURST = 7, //��������
        EABGT_RATING_SCORE = 8, //����ͨ��
        EABGT_RATING_SCORE_ACCUMULATE = 9, //�ۻ�����
        EABGT_BEG_BLUE_GAS = 10, //����¶����
        EABGT_GETGIVEGM = 11, //��Դ����GM
		EABGT_VIP_GIFT = 12,//VIP���
		EABGT_GVG_GIFT = 13,//���ս��� 
    };

    //ʹ������
    enum EDecBueGasType
    {
        EDBGT_UPGRADESKILLACTION = 1,//��������
        EDBGT_TASK = 2,			//��������
        EDBGT_CONVERT2PURPLE = 3, //ת������
        EDBGT_MAKERGEM = 4, //������ʯ
        EDBGT_GETGIVEGM = 5, //��Դ����GM
    };

    //�������
    enum EAddPurpleGasType
    {
        EAPGT_JINGJIECOLLECT = 1, //�������ռ�
        EAPGT_GM = 2, //�������ռ�
        EAPGT_CONVERT2PURPLE = 3, //ת������
        EAPGT_RDCHALLENGE = 4, //�����ս����
        EAPGT_WORSHIP = 5, //Ĥ��
        EAPGT_ENCOURAGE = 6, //�����
        EAPGT_USEGOODS = 7, //ʹ����Ʒ
        EAPGT_RATING_SCORE = 8, //����ͨ��
        EAPGT_RATING_SCORE_ACCUMULATE = 9, //�ۻ�����
        EAPGT_GETGIVEGM = 10, //��Դ����GM
        EAPGT_TASK = 11, //������
        EAPGT_DRINK_WINE = 12, //�Ⱦ�
		EAPGT_VIP_GIFT = 13,//VIP���
		EAPGT_GVG_GIFT = 14,//���ս���
    };

    //ʹ������
    enum EDecPurpleGasType
    {
        EDPGT_UPGRADESKILLACTION = 1,//��������
        EDPGT_GETGIVEGM = 2, //��Դ����GM
		EDPGT_EXCHANGE_STORE = 3,//�̵�
    };

    //���Ԫ��
    enum EGetGoldType
    {
        EGGT_ADDFLAGEXCHANGE = 1,			//��ֵ���Ԫ��
        EGGT_ADDFLAGCROWN = 2,				//���ջ��Ԫ��
        EGGT_ADDFLAGGM = 3,					//ͨ��GM���߻��Ԫ��
        EGGT_ADDGOLDTASK = 4,				//ͨ��������Ԫ��
        EGGT_ADDGOLDINSTANCE = 5,			//�������Ԫ��
        EGGT_ADDGOLDINSTANCEGOODS = 6,		//ͨ��������û��Ԫ��
        EGGT_USEGOODS = 7,					//ʹ����Ʒ���Ԫ��
        EGGT_ONLINEENCOURAGE = 8,			//���߽������Ԫ��
        EGGT_USELOGINGOODS = 9,				//��¼����ʹ����Ʒ���Ԫ��
        EGGT_ENCOURAGE = 10,				//��������Ԫ��
        EGGT_RATING_SCORE = 11,				//����ͨ�ػ��Ԫ��
        EGGT_RATING_SCORE_ACCUMULATE = 12,	//�ۻ��������Ԫ��
        EGGT_GETGIVEGM = 13,				//��Դ����GM
        EGGT_GM_FLAGEXCHANGE = 14,			//GM���ĳ�ֵЧ��
		EGGT_VIP_GIFT =  15,				//VIP���
		EGGT_GVG_GIFT = 16,//���ս���
		EGGT_BAG_GIFT = 17,//�����������
    };

    //ʹ��Ԫ��
    enum EDecGoldType
    {
        EDGT_CLRJIEBIAOCD = 1, //�������CD
        EDGT_OPENCROPFIELD = 2, //��Ԫ���򿪵ؿ�
        EDGT_CLRCROP = 3, //�����ֲCDʱ��
        EDGT_BUYCLIMBTOWERRESETREQ = 4, //��������
        EDGT_CLRUSEDRUGCD = 5, //���ʹ�õ�ҩCD
        EDGT_INCREASESIZE = 6, //��չ��������
        EDGT_CLRCHALLENGECD = 7, //�����սCDʱ��
        EDGT_ONRACECOMPLETE = 8, //�շ���ս
        EDGT_BUY = 9, //�̵깺��
        EDGT_PLUNDER = 10, //�շ��Ӷ�
        EDGT_DRIVEAWAY = 11, //����
        EDGT_BLEEDCAPTURE = 12, //ե��
        EDGT_ROCKMONEY = 13, //�вƽ���
        EDGT_AWAKENONCE = 14, //���
        EDGT_STRENGTHENEQUIP = 15, //װ��ǿ��
        EDGT_FLUSHBIAOINFO = 16, //ˢ������Ϣ
        EDGT_FLUSHBIAOINFOMAXLEVEL = 17, //ֱ��ˢ����õ���Ʒ��
        EDGT_BUYPHYSTRENGTH = 18, //��������
        EDGT_GENGAS = 19, //����
        EDGT_UPGASLEVEL = 20, //���������ȼ�
        EDGT_VISITHERO = 21, //��ļ�佫
        EDGT_PERFECTFREEGODWEAPON = 22, //�����ͷ�����
        EDGT_GOLDEXPERIENCE = 23, //����Ԫ�����鵤
        EDGT_GOLDRESETELITINSTANCE = 24, //���þ�Ӣ����
        EDGT_BOSSBINSPIRE = 25, //BOSSս����
        EDGT_BOSSBRELIVE = 26, //BOSSս����
        EDGT_EXPTRANS = 27, //���鴫��
        EDGT_CLRRDCCD = 28, //��������սCD
        EDGT_WORSHIP = 29, //Ĥ��
        EDGT_MELT = 30, //����
        EDGT_COMPOSEEQUIP = 31, //װ���ϳ�
        EDGT_GM = 32, //GM
        EDGT_GMDECPAY = 33, //GM�۳�
        EDGT_GATHER_SCIENCE = 34, //�ۻ�
        EDGT_BEG_BLUE_IMPRV_LUCK = 35, //����¶��������
        EDGT_EQUIP_OPENLIGHT = 36, //װ����������
        EDGT_GETGIVEGM = 37,		//��Դ����GM
        EDGT_FACTION = 38,		//��������
        EDGT_FACTION_DOORSTRIBUTE  = 39, //�Ź�
        EDGT_SEND_FLOWER  = 40, //���ʻ�
        EDGT_OPEN_GOLD_MODE = 41,   //�����ƽ�ģʽ
        EDGT_CHANGE_MONSTER = 43,   //ˢ��׽��������
        EDGT_DRINK_WINE = 44,		//����
        EDGT_FIND_ORANGE_MONSTER = 45,  //һ���ȹ�
        EDGT_BUY_COURAGE_TIMES  = 46, // ������������
        EDGT_EQUIP_MASTER_CHEAT = 47, // װ����ͨ��ǧ
        EDGT_CLOSE_MONSTER = 48, //����
		EDGT_CHANGE_FACTION_ICON = 49, //����ͷ�����
		EDGT_FIND_BACK_DOORSTRIBUTE = 50,//�һ��Ź�
		EDGT_VIP_GIFT = 51,//VIP���
        EDGT_CROPFIELDUPGRADE = 52, //��Ԫ�������ؿ�
		EDGT_PRODUCT_SOUL = 53, // �������
		EDGT_REFLASH_SOUL = 54,//ϴ��ս��
		EDGT_PRODUCT_PET = 55, // �������
		EDGT_FRUIT_RESET_DRAW = 56, // ˮ����ͨ��ȡ
		EDGT_FRUIT_MAX_DRAW = 57, // ˮ��һ����ȡ
		EDGT_BUY_PET_STORE_ITEM = 58, // ��������̳���Ʒ
		EDGT_WASH_PSYCHIC = 59, // ϴ����
        EDGT_PERFECT_INHERIT = 60, // �����̳�
		EDGT_EQUIP_MAKE_BUY_MATERIAL = 61, // װ������ʱ�������
		EDGT_VIP_PET_FEED = 62, // ����VIPι��
    };

    //������Ʒ
    enum EAddItemType
    {
        EAIT_MAKEGOODS = 1, //��Ʒ�ϳ�,p2��ʾǿ����Ʒ��ID
        EAIT_CROP = 2, //��ֲ���
        EAIT_MIXDRUG = 3, //��ҩ�ϳ�
        EAIT_GMCOMMAND = 4, //GM����
        EAIT_ONLINEENCOURAGE = 5, //���߽���
        EAIT_LOGINENCOURAGE = 6, //��¼����
        EAIT_BOX = 7, //���佱��,p2��ʾ����ID
        EAIT_REMOVEXIANGQIAN = 8, //�Ƴ���Ƕ
        EAIT_INSTANCE = 9, //��������
        EAIT_TASK = 10, //������
        EAIT_BUY = 11, //�̵깺����
        EAIT_COMPOSEGOODS = 12, //��Ʒ�ϳ�
        EAIT_MAKEEQUIP = 13, //װ���ϳ�
        EAIT_REPLACEXIANGQIAN = 14, //��Ƕ�滻
        EAIT_RECHARGE_ENCOURAGE = 15, //��ֵ����
        EAIT_SCORE_ENCOURAGE = 16, //���ֽ���
        EAIT_ENCOURAGE = 17, //�����
        EAIT_EQUIPCOMPOSE = 18, //װ���ϳ�
        EAIT_RATING_SCORE = 19, //����ͨ��
        EAIT_RATING_SCORE_ACCUMULATE = 20, //�ۻ�����
        EAIT_ITEMEXCHANGE = 21, //�һ���Ʒ��p1Ϊ�һ����
        EAIT_GETGIVEGM = 22,				//��Դ����GM
		EAIT_RAREITEM_EXCHANGE = 23, //�Ź��һ�
		EAIT_VIP_GIFT = 24,		//VIP���
        EAIT_RDCHALLENGE = 25,  //����������
        EAIT_SENDFLOWER = 26,  //���ʻ�����
        EAIT_COURAGE = 27,   //������������
		EAIT_JEWELRY = 28,//��Ʒ�ϳ�
		EAIT_RESOLVE_JEWELRY = 29,//�ֽ���Ʒ
		EAIT_GVG_GIFT = 30,//���ս���
		EAIT_GM = 31,//GM����
		EAIT_SOUL_METERIAL = 32,// ������ϲ���
		EAIT_PRODUCT_PET = 33,// ���������Ʒ
		EAIT_BUY_PET_STORE = 34,// �����̳ǹ������Ʒ
        EAIT_EXCHANGE_STORE = 35,//�̳Ƕһ�
        EAIT_EQUIP_MAKE = 36, // װ������
		EAIT_SELL_ENCHANT_EQUIP = 37, // ���۸�ħװ��
    };

    //ʹ����Ʒ
    enum EDecItemType
    {
        EDIT_MAKEGOODS = 2, //��Ʒ�ϳ�
        EDIT_UPDATEATTR = 3, //��������
        EDIT_USE = 4, //��Ʒʹ��,p3��ʾ��������
        EDIT_CROP = 5, //��ֲ,p2��ʾ������
        EDIT_CROPGUIDE = 6, //��ֲ���۳�������������
        EDIT_MAKEEQUIP = 7, //����װ��,p2��ʾ������,p3��ʾ��������
        EDIT_EATDRUG = 8 , //���þ��鵤,p2��ʾ������
        EDIT_XIANGQIAN = 9, //��Ƕ����,p2��ʾ������
        EDIT_SELL = 10, //������Ʒ,p2������,p3��ʾ��������
        EDIT_MELT = 11, //��������, p2������,p3��ʾװ��ǿ���ȼ�
        EDIT_GM = 12, //��������, p2������,p3��ʾװ��ǿ���ȼ�
        EDIT_EQUIPCOMPOSE = 13, //װ���ϳ�, p2������,p3��ʾװ��ǿ���ȼ�
        EDIT_OPENLIGHT = 14, //����, p2������,p3��ʾʹ�ø���
        EDIT_GETGIVEGM = 15,				//��Դ����GM
        EDIT_GODWEAPON = 16,				//������������
		EDIT_RESOLVE_ORANGE = 17,			//�ֽ���Ե���
		EDIT_SEND_FLOWER = 18,			//�ͻ�
		EDIT_UPGRADE_JEWELRY = 19,		//ǿ����Ʒ
		EDIT_GENERATE_JEWELRY = 20,		//�ϳ���Ʒ
        EDIT_SOUL_METERIAL = 20,		//�ϳ�ս��
        EDIT_EQUIP_MAKE = 21,		//װ������
        EDIT_FLY = 22,		// ����
        EDIT_RECRUIT_LEGEND_HERO = 23,		// ��ļ�⴫���
		EDIT_UPGRADE_HERO = 24,		// ���׻��
		EDIT_UPDATE_POTENCY_SOUL = 25,//ս�꿨��Ʒ
    };

    //��þ����
    enum EAddJingJieType
    {
        EAJT_LEVY = 1, //����
        EAJT_YABIAO = 2, //Ѻ�ڻ��
        EAJT_RACECHALLENGE = 3, //���������
        EAJT_INSTANCE = 4, //��ֻ�þ���
        EAJT_BOSSB_HURTENC = 5, //BOSSս �˺�����
        EAJT_BOSSB_HEROENC = 6, //BOSSս Ӣ�۽���
        EAJT_BOSSB_TOPENC = 7, //BOSSս TOP����
        EAJT_BOSSB_KILLENC = 8, //BOSSս ��ɱ����
        EAJT_RDCHALLENGE = 9, //�����ս����
        EAJT_WORSHIP = 10, //Ĥ��
        EAJT_ENCOURAGE = 17, //�����
        EAJT_USEGOODS = 18, //ʹ����Ʒ
        EAJT_GM = 19, //gm����
        EAJT_GMSET = 20, //gm��������
        EAJT_RATING_SCORE = 21, //����ͨ��
        EAJT_RATING_SCORE_ACCUMULATE = 22, //�ۻ�����
        EAJT_GETGIVEGM = 23, //��Դ����GM
        EAJT_TASK = 23, //������
        EAJT_SEND_FLOWER = 24, //���ʻ�
		EAJT_VIP_GIFT = 25,//VIP���
		EAJT_RACE_RANK = 26, //��������������
		EAJT_GVG_GIFT = 27,//���ս���
    };

    //ʹ�þ����
    enum EDecJingJieType
    {
        EDJT_UPJINGJIE = 1, //��������
        EDJT_GETGIVEGM = 2, //��Դ����GM
		EDJT_EXCHANGE_STORE = 3,//����
    };

    //����ĵþ���
    enum EAddStudyExpType
    {
        EASET_CONVERTSTUDYEXP = 1, //ת���ĵ�
        EASET_GMCOMMAND = 2, //GM����
        EASET_ENCOURAGE = 3, //�����
        EASET_RATING_SCORE = 4, //����ͨ��
        EASET_RATING_SCORE_ACCUMULATE = 5, //�ۻ�����
    };

    //ʹ���ĵþ���
    enum EDecStudyExpType
    {
        EDSET_UPGRADESTUDY = 1, //�����ĵ�,p2�ĵ����ͣ�p3�ĵ���ɫ��p4�ĵõȼ�
    };

    //����ĵ�
    enum EAddStudyType
    {
        EASTUDYT_AWAKEN = 1, //���,p2Ϊcolor,p3Ϊlevel
        EASTUDYT_GMCOMMAND = 2, //GM����,p2Ϊcolor,p3Ϊlevel
        EASTUDYT_ENCOURAGE = 3, //�����
        EASTUDYT_RATING_SCORE = 4, //����ͨ��
        EASTUDYT_RATING_SCORE_ACCUMULATE = 5, //�ۻ�����
    };

    enum EDecStudyType
    {
        EDSTUDYT_CONVERT = 1, //����ת��,p2Ϊcolor,p3Ϊlevel
    };

    //����ĵ�
    enum EAddStudyClipType
    {
        EASCTUDYTCLIP_AWAKEN = 1, //���,p2Ϊcolor,p3Ϊlevel
        EASCTUDYTCLIP_GETGIVEGM	= 2, //��Դ����GM
        //EASCTUDYTCLIP_HUNTING = 3,	//׽������
        EASCTUDYTCLIP_ENCOURAGE = 4,	//�����
		EASCTUDYTCLIP_RESOLVE_ORANGE = 5, //�ֽ��ɫ����
		EASCTUDYTCLIP_VIP_GIFT = 6,//VIP��� 
		EASCTUDYTCLIP_GVG_GIFT = 7,//GVG���
    };

    enum EDecStudyClipType
    {
        EDSCTUDYTCLIP_EXCHANGE = 1, //����һ�
        EDSCTUDYTCLIP_CONVERT = 2, //��Դ����GM
		EASCTUDYTCLIP_HUNTING = 3,	//׽������
    };

    // �������ѫ��
    enum EAddMedalType
    {
        EAMT_GM = 2, // ͨ��GM���߻������ѫ��
        EAMT_COURAGE = 3, //ͨ��������������
    };

	// �������ѫ��
	enum EAddSoulType
	{
		EAST_GM			= 1,	// ͨ��GM���߻������ѫ��
		EAST_Product	,		// ̽��
		EAST_Exchange	,		// �һ�
	};

    // ʹ������ѫ��
    enum EDecMedalType
    {
        EDMT_ACTIVATE_EQUIP_MASTER     = 1, // װ����ͨ����
        EDMT_BREAK_THROUGH_MASTER      = 2, // װ����ͨͻ��
        EDMT_GET_EQUIP_MASTER_EXP_BOOK = 3, // װ����ͨ������֮ͨ��
    };

    enum EAddDoorsTribute //����Ź�
    {
        EAT_HUNTING = 1,	//׽��
        EAT_DONATE_COIN = 2,		//����ͭǮ
        EAT_DONATE_GOLD = 3,		//����Ԫ��
        EAT_GM = 4,	//GM����
		EAT_USE_GOODS = 5, //ʹ����Ʒ���Ź����ƣ�
		EAT_FIND_BACK = 6, //�Ź��һ�
		EAT_VIP_GIFT = 7,//VIP������
		EAT_GVG_GIFT = 8,//GVG���
		EAT_GVG_CONTINUE_KILL = 9,//GVG��ն����
    };

    enum EDecDoorTribute	//ʹ���Ź�
    {
        EDDT_LEARN_SKILL = 1,	//ѧϰ���ü���
        EDDT_BUY_RAREITEM = 2,	//��Ʒ���һ���Ʒ
        EDDT_GM = 3,	//GM
    };

    enum EAddFactioinFunds
    {
        EAFF_DONATE_COIN = 1,	//ͭǮ����
        EAFF_DONATE_GOLD = 2,	//Ԫ������
        EAFF_HUNTING = 3,	//׽��
        EAFF_GM = 4,		//GM
		EAFF_VIP_GIFT = 5, //VIP������
		EAFF_GVG_GIFT = 6,//GVG���
    };

    enum EDecFactionFunds
    {
        EDFF_UPGRADE_FACTION = 1, //�������
        EDFF_UPGRADE_RAREITEM = 2,//������Ʒ
        EDFF_UPGRADE_GYMNASIUM = 3,//��������
        EDFF_UPGRADE_SHADE = 4,//��������
        EDFF_UPGRADE_HOTSPRING = 5,//������Ȫ
        EDFF_GM = 6, //GM
		EDFF_OPEN_HOTSPRING = 7, //������Ȫ
    };

    // ������Ҹ��˲���
    enum EPlayerOperate
    {
        EPO_RE_REG_NICK_NAME    = 1, // ��Ҹ���������ʱ�ǳƳ�ͻ����ҽ��õ�һ�θ������ᣩ
        EPO_RE_REG_FACTION_NAME = 2, // �����˶����ɽ��и���������ʱ�������������Ƴ�ͻ�����ͻ���ɽ��õ�һ�θ����ɸ������᣺ֻ�������������ģ�
    };

    // ���ɿ��ս�
    enum EGvGActivity
    {
        EGA_APPLY     = 1, // ���ɱ���
        EGA_GIVE_GIFT = 2, // �����������
        EGA_RECV_GIFT = 3, // ��ȡ���
        EGA_RANK = 4,      // ��������
    };

    // �����汾��������
    enum EFly
    {
        EF_FLY, // ����
        EF_UPGRADE_HERO, // ������
        EF_RECRUIT_HERO, // ��ļ���
    };
};




#endif