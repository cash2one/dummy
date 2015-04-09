/*       Version Number: 10          */

#ifndef PROTOCOMMONDATA_H_INCLUDE_VERSION_10
#define PROTOCOMMONDATA_H_INCLUDE_VERSION_10

#include "netdata.h"
#include "sdtype.h"
#include "sdstring.h"
#include <cjson.h>
#include <dll/sdframework/sdutil.h>
#pragma pack(push, 1)

/*Defines Begin*/
#define SUCCESS                  0
#define FAIL                     1
#define REFUSE_LOGIN             2
#define SESSIONID_LEN            8
#define DEVICEID_LEN             41
#define NOTIFYID_LEN             65
#define USERNAME_LEN             41
#define ZONENAME_LEN             41
#define USERTYPE_LEN             41
#define USERPWD_LEN              17
#define MSG_LEN                  1024
#define IPSTR_LEN                17
#define BEGBLUE_CLIMB_TOWER_PROMPT 61
#define BEGBLUE_LUCK_PROMPT      21
#define WANTED_DSPNAME_LEN       21
#define WANTED_DESC_LEN          128
#define CLUE_TASK_NAVI_DESC_LEN  128
#define LOGIN_TYPE_USER          0
#define LOGIN_TYPE_IPHONE        1
#define MAX_HERO_NUM             90
#define NEED                     1
#define NONNEED                  0
#define MAX_BAG_OPEN_NUM         200
#define MAX_BAG_OPEN_NUM_NEW     600
#define CURRENCY_TYPE_COIN       0
#define CURRENCY_TYPE_GOLD       1
#define MAX_SKILL_NUM            12
#define MAX_GAS_BALL_NUM         8
#define MAX_SKILL_SLOT_NUM       3
#define MAX_SKILL_BUFF_NUM       3
#define MAX_EFFECT_RECOMMEND_NUM 2
#define MAX_BAG_NUM              5
#define MAX_BUILD_NUM_BEFORE_v410 50
#define MAX_BUILD_NUM            100
#define MAX_HANG_NUM             50
#define MAX_BATTLE_ROUND_NUM     60
#define MAX_NEW_BATTLE_ROUND_NUM 120
#define MAX_ENCOURAGE_ITEM_NUM   10
#define MAX_INSTANCE_MONSTER_NUM 10
#define PICKUP_KIND_ITEM         0
#define PICKUP_KIND_HANG         1
#define MAX_SCENCE_NUM           2
#define MAX_TOWN_PER_SCENE_NUM   200
#define MAX_INSTANCE_PER_TOWN_NUM 19
#define MAX_INSTANCE_PER_SCENE_NUM 600
#define INSTANCE_INDEX_STR_LEN   15
#define MAX_HP_CHANGE_TIMES_PER_ROUND 30
#define MAX_ANGRY_CHANGE_TIMES_PER_ROUND 10
#define MAX_NEW_ANGRY_CHANGE_TIMES_PER_ROUND 30
#define MAX_BUFF_CHANGE_TIMES_PER_ROUND 10
#define MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND 30
#define MAX_SCIENCE_ATTR_NUM     20
#define MAX_TASK_LINE_NUM        30
#define MAX_KILL_MONSTER_INSTANCE_NUM 5
#define MAX_ITEM_KIND_COLLECT_NUM 5
#define MAX_UPDATE_ATTR_NUM      20
#define MAX_XIANGQIAN_NUM        8
#define INVALID                  0
#define CROWN                    1
#define RECRUITHERO              2
#define UPGRADESKILL             3
#define UPGRADEJINGJIE           4
#define FIRSTPASSINSTANCE        5
#define SCOREPASSINSTANCE        6
#define TIMESPASSINSTANCE        7
#define KILLMONSTERINSTANCE      8
#define STRENGTHENEQUIPLEVEL     9
#define STRENGTHENEQUIPNUM       10
#define MOSAICGEM                11
#define ACTIVATEGODWEAPON        12
#define UPGRADEGODWEAPON         13
#define CHALLENGE                14
#define PLUNDER                  15
#define CLIMBTOWER               16
#define DRESSEQUIP               17
#define COMPOSEGOOD              18
#define ELITEINSTANCE            19
#define UPGRADSCIENCE            20
#define STRENGTHATTACK           21
#define STRENGTHLIFE             22
#define CROP                     23
#define USEEXPRIENCEDRUG         24
#define MELTEQUIP                25
#define STUDY                    26
#define RECRUITHERONUM           27
#define OPENLIGHT                28
#define MAX_TASK_DSPNAME_LEN     40
#define MAX_TASK_DESC_LEN        100
#define ETS_GIVEN                0
#define ETS_ACCEPTED             1
#define ETS_ENCOURAGE            2
#define ETS_FINISHED             3
#define ETS_INVALID              4
#define MAX_CHALLENGE_NUM        10
#define MAX_SHOP_ITEM_NUM        100
#define MAX_ENCOURAGE_ITEM_KIND_NUM 20
#define MAX_ENCOURAGE_BOX_GROUP_NUM 3
#define MAX_GVE_ENCOURAGE_BOX_GROUP_NUM 6
#define MAX_UNLOCK_HERO_NUM      3
#define EPL_HOME                 0
#define EPL_INSTANCE             1
#define EPL_ONHOOK               2
#define EPL_PAGODA               3
#define EPL_EATBREAD             4
#define EPL_BOSSB                5
#define EPL_HOT_SPRING           6
#define EPL_COURAGE              7
#define EPL_FACTION              8
#define EPL_COURAGE_BATTLE       9
#define EPL_SOUL                 10
#define EPL_PET                  11
#define EPL_NEIDAN               12
#define EIK_EQUIP                0
#define EIK_GOODS                1
#define EIK_JEWELRY              2
#define MAX_DRUG_LEVEL           6
#define MAX_FORMATION_NUM        9
#define MAX_FORMATION_IDX_NUM    6
#define MAX_ITEM_MAKER_NEED_NUM  6
#define EEIK_EQUIP               0
#define EEIK_DRUG                1
#define MAX_INSTANCE_RUN_TIMES   40
#define EIT_COMMON               1
#define EIT_ELITE                2
#define EIT_TOWER                3
#define EIT_OAI                  4
#define EIT_COURAGE              5
#define EIT_OUT_BOUND            6
#define EIT_NEIDAN               7
#define GET_ZONE_NUM             20
#define MAX_LOGIN_ENCOURAGE_ITEM_NUM 8
#define MAX_RANK_SHOW_NUM        100
#define MAX_RACE_BATTLELOG_NUM   50
#define MAX_YABIAO_BATTLELOG_NUM 50
#define MAX_BIAO_QUALITY         5
#define MAX_COMPOSE_ITEM_NUM     5
#define MAX_PLUNDER_BATTLELOG_NUM 50
#define MAX_CAPTURE_NUM          4
#define MAX_GET_ENEMY_NUM        5
#define MAX_GET_PLUNDER_ENEMY_NUM 5
#define MAX_GET_RDC_NUM          5
#define MAX_ROBOT_NUM            10
#define MAX_ENEMY_NUM            200
#define MAX_GODWEAPON_QUALITY_NUM 50
#define MAX_BUFF_NUM             27
#define MAX_INSTANCE_NUM         200
#define EQUIP_POS_NUM            4
#define MAX_CROP_NUM             9
#define MAX_CROP_SEED_NUM        50
#define MAX_SCIENCE_KIND_NUM     15
#define MAX_CONTENT_SIZE         1024
#define MAX_NOTICE_CONTENT_LEN   4096
#define MAX_ORDER_ID_LEN         255
#define MAX_RECEIPT_DATA_LEN     2550
#define AUTH_TYPE_DEVECEID       0
#define AUTH_TYPE_TONGBU         1
#define AUTH_TYPE_91             2
#define AUTH_TYPE_MAXNET         3
#define AUTH_TYPE_PP             4
#define MAX_ACTIVITY_NUM         10
#define MAX_ACTIVITY_TIME_NUM    10
#define MAX_CLIMB_TOWER_NUM      7
#define MAX_BOOK_DATA_NUM        7
#define MAX_TOKEN_NUM            64
#define MAX_JINGJIE_ATTR_INC_NUM 7
#define MAX_JINGJIE_SUBLEVEL_NUM 13
#define MAX_SKILL_ACTION_LEVEL_NUM 90
#define MAX_BIND_EFFECT_NUM_PER_ACTION 3
#define MAX_PARM_LEN             1024
#define MAX_VIP_LEVEL            20
#define MAX_VIP_FUNC             100
#define MAX_AWAKEN_LEVEL         5
#define MAX_AWAKEN_NUM           100
#define MAX_BAG_STUDY_GRID_NUM   16
#define MAX_HERO_STUDY_GRID_NUM  4
#define MAX_EXCHANGE_STUDY_NUM   20
#define MAX_INSTANCE_CLIMB_TOWER_NUM 255
#define MAX_GEM_LEVEL            12
#define MAX_GEM_LEVEL_EX         32
#define EQUIP_GEM_NUM            4
#define MAX_GUIDE_NUM            128
#define MAX_LUAACTIVITY_RECORD_NUM 100
#define MAX_ELITE_INSTANCE_TOWN_NUM 15
#define MAX_COLOR_NUM            4
#define MAX_EQUIP_XIANGQIAN_NUM  255
#define MAX_BOSS_ENC_TOP_NUM     6
#define MAX_BOSSB_SHOW_PLAYER_NUM 50
#define BOSSB_POS_TYPE_ENTER     0
#define BOSSB_POS_TYPE_LEAVE     1
#define BOSSB_POS_TYPE_MOVE      2
#define MAX_BOSSB_NUM_PER_DAY    3
#define MAX_BATTLE_LOG_TYPE_NUM  20
#define MAX_BOSSB_BATTLE_LOG_NUM 20
#define MAX_ABSORB_NUM           56
#define MAX_WORSHIP_NUM          20
#define EVERY_CHAPTER_NUM        9
#define MAX_EXT_FUN_NUM          10
#define MAX_ACTIVITY_ENCOURAGE_INFO_NUM 512
#define MAX_EQUIPLEVEL_NUM       50
#define MAX_FACTION_NUM          64
#define MAX_FACTION_DESC_NUM     255
#define DT_FACTION_PLAYER_NUM    100
#define MAX_FACTION_LOG_NUM      100
#define FOR_NEW_BEGBLUE          1
#define FOR_TO_COMFIRM_BEGBLUE   2
#define MAX_MOBILE_LENGTH        20
#define MAX_WANTED_NUM           5
#define MAX_CLUE_TASK_NUM        100
#define KILL_MONSTER_NAVI        1
#define ITEM_BOX_NAVI            2
#define FORTUNE_GRID_NAVI        3
#define MAX_FRIEND_SYS_PLAYER_LIST_ELEM_NUM 10
#define MAX_SEND_FLOWER_PROP_NUM 3
#define MAX_RECV_FLOWER_LOG_LIST_ELEM_NUM 20
#define MAX_RECV_FLOWER_LOG_LIST_ELEM_EX_NUM 128
#define MAX_RELATION_LIST_ELEM_NUM 200
#define MAX_FINALLY_CONTACT_DATA_NUM 50
#define MAX_FLOWER_RANKING_LIST_ELEM_NUM 20
#define PRIVATE_MSG_CONTENT_LEN  200
#define MAX_PRIVATE_MSG_LIST_ELEM_NUM 10
#define MAX_NEW_PRIVATE_MSG_NOTICE_NUM 50
#define MAX_NEW_RECV_FLOWER_NOTICE_NUM 50
#define MAX_SEND_FLOWER_DATA_NUM 5
#define MAX_SEND_OFFLINE_MSG_PLAYER_LIST_ELEM_NUM 100
#define MAX_RAREITEM_RES_NUM     100
#define MAX_RAREITEM_ROOM_GRADE  100
#define MAX_UPGRADE_INFO_NUM     6
#define FACTION_UPGRADE_MSG_LEN  64
#define MAX_GYMNASIUM_SKILL_NUM  24
#define SKILL_MSG_LEN            32
#define SKILL_NAME_LEN           18
#define NORMAL_MSG_LEN           50
#define TASK_DESCRIBE_MSG_LEN    128
#define HUNTING_REWARD_MGS_NUM   3
#define SHADE_UPGRADE_MSG_NUM    4
#define MONSTER_TYPE_NUM         4
#define MAX_HOT_SPRING_SHOW_PLAYER_NUM 50
#define HOT_SPRING_WINE_NUM      3
#define GIVE_WINE_DRINK          1
#define GIVE_WINE_NOT_DRINK      2
#define GIVE_WINE_FINISH         3
#define NOT_GIVE_WINE_DRINK      4
#define NOT_GIVE_WINE_NOT_DRINK  5
#define SYNC_INTERVAL_HOT_SPRING 1000
#define WINE_MSG_LEN             128
#define MAX_FACTION_UPGRADE_NUM  5
#define MAX_COURAGE_GROUP_PLAYER_NUM 3
#define MAX_COURAGE_GROUP_NUM    1024
#define EQUIP_KIND_COUNT         4
#define MASTER_RANK_COUNT        4
#define MASTER_EXP_BOOK_COUNT_PER_KIND 3
#define MASTER_EXP_BOOK_COUNT    12
#define MASTER_MAX_LEVEL_UP      10
#define FACTION_LOG_LIST_MAX_NUM 10
#define HELP_COURAGE_LEN         80
#define COURAGE_HERO_NUM         4
#define COURAGE_NO_GROUP         1
#define COURAGE_HAVE_GROUP       2
#define MAX_FACTION_BATTLE_LOG_NUM 50
#define MAX_ACTIVI_SIDE_PROMPT_NUM 36
#define MAX_HUTING_POT_NUM       5
#define MAX_HUNTING_POT_NUM_NEW  64
#define HUNTING_POT_NAME         32
#define MAX_FACTION_NAME_LEN     12
#define MAX_LEAVE_HOT_SPRING_PROMPT_MSG 125
#define MONSTER_GROUP_NUM        3
#define MAX_RESOURCE_NUM         20
#define MAX_MONSTER_NUM          9
#define MAX_COURAGE_MEMBER_NUM   3
#define MAX_VIP_GIFT_ITEM_NUM    10
#define MAX_FACTION_MANAGER_NUM  64
#define MAX_VIP_GIFT             3
#define MAX_NEW_FORMATION_NUM    20
#define MAX_PLAYER_RES_NUM       32
#define BEGBLUE_ENCOURAGE_PROMPT 61
#define BEGBLUE_CONSUME_TIMES    30
#define MAX_JEWELRY_POS          4
#define MAX_JEWELRY_STRENG_NUM   10
#define MAX_GVG_PK_VIDEO_CNT     100
#define MAX_GVG_TOP_FACTION_CNT  8
#define GVG_16_TO_8_FACTION_CNT  16
#define MAX_GVG_ARENA_FACTION_CNT 32
#define GVG_16_TO_8_WIN_CNT      8
#define GVG_8_TO_4_WIN_CNT       4
#define GVG_FINAL_WAR_FACTION_CNT 8
#define MAX_GVG_LOG_CNT          25
#define MAX_GVG_SIMPLE_LOG_CNT   12
#define MAX_GVG_ARENA_ZONE_CNT   8
#define MAX_GVG_MVP_CNT          100
#define MAX_RANK_DISPLAY         100
#define MAX_GVG_FORMATION_PLAYER_CNT 80
#define MAX_GAMBLE_NUM           9
#define MAX_GVG_RULE             4096
#define MAX_FACTION_APPLAY_NUM   500
#define MAX_FACTION_AREA_NUM     4
#define MAX_GVG_GROUP_NUM        2
#define MAX_FACTION_BATTLE_NUM   16
#define MAX_GVG_FACTION_NUM      32
#define MAX_GVG_GIFT_NUM         200
#define MAX_GIFT_GOODS_NUM       10
#define MAX_BATTLE_LOG_LEN       256
#define MAX_BATTLE_LOG_NUM       100
#define MAX_BATTLE_LOG_PARAM_NUM 20
#define MAX_BATTLE_LOG_PARAM_STR 10
#define MAX_SOUL_BAG_NUM         255
#define MAX_SOUL_EQUIP_NUM       2
#define MAX_SOUL_ATTR_NUM        16
#define MAX_SOUL_PRODUCT_TYPE    4
#define MAX_NAME_LEN             64
#define MAX_MEDAL_DESC_LEN       128
#define MAX_MEDAL_NUM            512
#define MAX_SKILL_SOUL_NUM       8
#define MAX_OUT_BOUND_NUM        255
#define MAX_OUT_BOUND_INSTANCE_NUM 32
#define MAX_DISPALY_GOODS_NUM    32
#define MAX_PET_NUM              150
#define MAX_PET_NAME_LENGTH      32
#define MAX_OUT_BOUND_DESC_LEN   128
#define MAX_PET_FEED_FRUIT_CNT   5
#define MAX_PET_WASH_PSYCHIC_CELL_CNT 5
#define MAX_PET_WASH_PSYCHIC_QUALITY_CNT 10
#define MAX_PET_WASH_PSYCHIC_ITEMTYPE_CNT 10
#define RECRUIT_FLY_HERO_MATERIAL_NUM 5
#define UPGRADE_HERO_MATERIAL_NUM 5
#define MAX_MATERIAL_NUM         10
#define MAX_SERIES_NUM           50
#define MAKE_EQUIP_MATERIAL_NUM  4
#define MAX_MAKE_BOOKS_NUM_OF_1_SERIES 40
#define FLY_GOAL_DESC_LENGTH     100
#define FLY_COST_MATERIAL_NUM    4
#define MAX_FLY_GOAL_NUM         8
#define MAX_EQUIP_SERIES_NAME_LEN 50
#define MAX_JEWELRY_SUIT_ATTR_NUM 20
#define MAX_PET_NEIDAN_NUM       5
#define MAX_NEI_DAN_BAG_NUM      200
#define PROTOCOMMONDATA_MSGID_RANGE 1
#define PROTOCOMMONDATA_MSGID_OFFSET 0
#define PROTOCOL_VERSION 10
/*Defines End*/



#define INDEX_NUM_HEAD_SIZE	1	//��������ͷ��С
#define ARRAY_NUM_HEAD_SIZE	2	//�������ͷ��С

struct SIndex
{
	UINT8	byIdx;
	UINT32	dwContextLen;
};

/*Define Structs and Unions        Begin*/
typedef struct tagDT_RES_DATA{
	UINT8            byResKind; //��Դ����
	UINT64           qwResValue; //��Դֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RES_DATA;

typedef struct tagDT_ITEM_DATA{
	UINT16           wKindID; //��������ID
	UINT16           wNum; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ITEM_DATA;

typedef struct tagDT_RES_NUM_ITEM_DATA{
	UINT8            byResNum; //��Դ����
	DT_RES_DATA      astResList[MAX_PLAYER_RES_NUM]; //��Դ��Ϣ
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA     astItemList[MAX_PLAYER_RES_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RES_NUM_ITEM_DATA;

typedef struct tagDT_GUIDE_RECORD_DATA{
	UINT8            abyGuideRecordData[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GUIDE_RECORD_DATA;

typedef struct tagDT_PLAYER_BASE_DATA{
	UINT32           dwID; //���ΨһID
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	UINT64           qwStory; //����
	UINT16           wPhyStrength; //��ǰ����
	UINT64           qwScience; //��ǰ�Ƽ���
	DT_GUIDE_RECORD_DATA stGuideRecordData; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	UINT8            byRobotFunc; //�����˹���,>0��Ϊ�����ˣ���ͬ��ֵΪ��ͬ�Ĺ��ܡ�0Ϊ���
	UINT32           dwPower; //ս��(���initʱ���¸�ֵ)
	UINT32           dwFirstAttack; //�ȹ�ֵ
	UINT64           qwTodayFirstLoginTime; //�����һ�ε�½ʱ��
	UINT8            byBagOpenNum; //�����򿪸�����(��ԭ��������)
	UINT64           qwBlueGas; //����
	UINT64           qwPurpleGas; //����
	UINT8            byVipLevel; //VIP�ȼ�
	UINT32           dwTotalAmount; //�ܹ���ֵԪ����
	UINT64           qwJingJie; //�����
	UINT64           qwTotalRMB; //�ܹ���ֵ���
	UINT64           qwStudyExp; //������
	UINT64           qwRecvRankEncTime; //��ȡ��������ʱ��
	UINT32           dwExtData; //��չ�ֶΣ������ڲ������¼����1��ʾ0829����Ҳ�����¶/��������
	UINT32           dwFlowerSum; //�ʻ�ͳ��
	UINT64           qwMedal; //����ѫ��
	UINT32           dwRMBGold; //��ǰ�����Ԫ���������Ԫ�� = ��������1:10�һ���Ԫ����������ҳ���6Ԫ�������75Ԫ���������е�<6 * 10 = 60>Ԫ�����������Ԫ����ʣ�µ�15Ԫ�����ڳ�ֵ����Ԫ����
	UINT32           dwRMBGoldGift; //��ֵ����Ԫ�� = ��ֵʱ��õ�Ԫ�� - �ôγ�ֵ������ң�Ԫ�� * 10
	UINT32           dwGmGold; //ϵͳ����Ԫ����ͨ��gm�������͸���ҵĳ�ֵԪ����ע�⣬GM������2�ַ�ʽ��������Ԫ����1.��ӳ�ֵԪ�� 2.�����ͨ��ϷԪ��
	UINT16           wOriZoneID; //��Ҵ�����ɫʱ���ڵ��������ں������Ԫ��ͳ���ã�Ԫ����־Ҫ���ֳ����ԭ���������ĸ�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_BASE_DATA;

typedef struct tagDT_BATTLE_ATTRIBUTE{
	UINT32           dwHP; //Ѫ��
	UINT32           dwAttack; //������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ATTRIBUTE;

typedef struct tagDT_BATTLE_ATTRIBUTE2{
	UINT32           dwHP; //Ѫ��
	UINT32           dwAttack; //������
	UINT32           dwDefend; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ATTRIBUTE2;

typedef struct tagDT_BATTLE_BASE_ATTRIBUTE{
	UINT64           qwHP; //Ѫ��
	UINT32           dwAttack; //������
	UINT32           dwDefend; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_BASE_ATTRIBUTE;

typedef struct tagDT_HIDE_BATTLE_ATTRIBUTE{
	UINT16           wHitRate; //������
	UINT16           wDodgeRate; //������
	UINT16           wCritRate; //������
	UINT16           wDeCritRate; //������
	UINT16           wAngryValue; //ŭ��ֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HIDE_BATTLE_ATTRIBUTE;

typedef struct tagDT_EXT_BATTLE_ATTRIBUTE{
	UINT16           wIncHurtRate; //������(���ӵ��˺��ٷֱ�)
	UINT16           wDecHurtRate; //������(���ٵ��˺��ٷֱ�)
	UINT16           wOddAngry; //ŭ��ʣ��ֵ(�����ͷź�ʣ���ŭ��ֵ)
	UINT32           dwFirstAttack; //�ȹ�
	UINT16           wCoachTalent; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EXT_BATTLE_ATTRIBUTE;

typedef struct tagDT_HERO_UPDATE_ATTR_DATA{
	UINT16           wAttrHP; //Ѫ��
	UINT16           wAttrAttack; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_UPDATE_ATTR_DATA;

typedef struct tagDT_HERO_ATTR_DATA{
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //ս������
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttr; //����ս������
	DT_HERO_UPDATE_ATTR_DATA stUpdateAttrInfo; //����������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_ATTR_DATA;

typedef struct tagDT_SPECIAL_EFFECT_DATA{
	UINT16           wEffectID; //��ЧID
	UINT8            byIsActivity; //�Ƿ񼤻�
	UINT8            bySkillNum; //��Ч����
	UINT8            abyEffectSmallType[MAX_SKILL_SOUL_NUM]; //��Ч����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SPECIAL_EFFECT_DATA;

typedef struct tagDT_SOUL_ATTR_DATA{
	UINT8            byKindID; //����ID
	UINT8            byKindPrecent; //������ռ�ٷֱ�
	UINT32           dwKindValue; //����ֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SOUL_ATTR_DATA;

typedef struct tagDT_SOUL_POTENCY_DATA{
	UINT8            byPotencyLevel; //Ǳ�ܵȽ�
	UINT8            byPotencySubLevel; //Ǳ�ܵȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SOUL_POTENCY_DATA;

typedef struct tagDT_SOUL_POTENCY_LST_DATA{
	UINT16           wSoulNum; //ս�����
	DT_SOUL_POTENCY_DATA astSoulPotencyLstData[MAX_SOUL_BAG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SOUL_POTENCY_LST_DATA;

typedef struct tagDT_SOUL_DATA{
	UINT16           wSoulID; //ս��ID
	UINT32           dwSoulIdx; //ս��Idx(����ͬ��ս��)
	UINT8            bySoulStar; //ս���Ǽ�
	UINT8            bySoulType; //ս������ 1�������� 2���������
	UINT8            bySoulLevel; //ս��ȼ�
	UINT32           dwSoulExperience; //ս�꾭��
	UINT8            byIsNormalSoul; //0 �������ɻ� 1 ������ͨ��
	UINT32           dwDevourExp; //���ɾ���
	UINT8            byBaseNum; //ս��������Ը���
	DT_SOUL_ATTR_DATA astSoulAttr[MAX_SOUL_ATTR_NUM]; //ս������
	UINT8            byBaseAfterNum; //ս��������Ը�����ϴ����
	DT_SOUL_ATTR_DATA astSoulAfterAttr[MAX_SOUL_ATTR_NUM]; //ս�����ԣ�ϴ����
	UINT8            byHaveEffect; //�Ƿ�����Ч
	DT_SPECIAL_EFFECT_DATA stSpecialEffect; //���⼼��
	UINT8            abySoulAttrLock[MAX_SOUL_ATTR_NUM]; //������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SOUL_DATA;

typedef struct tagDT_HERO_SOUL_DATA{
	UINT16           wSoulNum; //ս�����
	DT_SOUL_DATA     astSoulLstData[MAX_SOUL_EQUIP_NUM]; //װ��ս����Ϣ
	DT_SOUL_POTENCY_DATA astSoulPotencyLstData[MAX_SOUL_EQUIP_NUM]; //Ǳ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_SOUL_DATA;

typedef struct tagDT_HERO_BASE_DATA{
	UINT16           wKindID; //�佫����
	UINT8            byCoach; //���佫��־,1Ϊ���佫
	UINT8            byPos; //λ�ñ�־,0Я����1Ϊ��ս��2����ļ����
	UINT8            byFormationIdx; //����λ��
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����
	UINT64           qwExperience; //����
	UINT8            byRecuitedFlag; //�Ƿ���ļ��
	UINT8            byVisitNum; //�ݷô���
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //ս������
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttr; //����ս������
	UINT8            byLastUseDrugLevel; //�ϴ�ʹ�õĵ�ҩ�ȼ�(Ʒ)
	UINT64           qwLastUseDrugTime; //�ϴ�ʹ�õ�ҩʱ��
	UINT8            byUseExperienceDrugPerDay; //ÿ���������������
	UINT64           qwLastUseExperienceDrugTime; //�ϴ�ʹ�þ��鵤ʱ��
	DT_HERO_UPDATE_ATTR_DATA stUpdateAttrInfo; //����������Ϣ
	UINT8            byIsFly; //�Ƿ��ѷ���
	UINT32           dwFlyExp; //���ȼ��ѵ�120�����ڷ����ڼ�ʱ�ۻ��ľ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_BASE_DATA;

typedef struct tagDT_XIANGQIAN_DATA{
	UINT16           wItemID; //��ƷID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_XIANGQIAN_DATA;

typedef struct tagDT_EQUIP_DATA{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT16           wLevel; //װ���ȼ�
	UINT16           wBagPos; //���ڱ���λ��
	UINT64           qwItemNewTime; //��������ʱ��
	DT_XIANGQIAN_DATA astXiangqianList[MAX_XIANGQIAN_NUM]; //��Ƕ�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EQUIP_DATA;

typedef struct tagDT_HERO_EQUIP_DATA_LST{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA    astEquipList[EQUIP_POS_NUM]; //װ����Ϣ
	UINT16           awEnchantLevel[EQUIP_POS_NUM]; //��װ����ħ�ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_EQUIP_DATA_LST;

typedef struct tagDT_BAG_EQUIP_DATA_LST{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA    astEquipList[MAX_BAG_OPEN_NUM_NEW]; //װ����Ϣ
	UINT16           awEnchantLevel[MAX_BAG_OPEN_NUM_NEW]; //��װ����ħ�ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BAG_EQUIP_DATA_LST;

typedef struct tagDT_GOODS_DATA{
	UINT16           wKindID; //��Ʒ����
	UINT16           wPileCount; //������
	UINT64           qwLastUseTime; //�ϴ�ʹ��ʱ��
	UINT16           wLastUseNum; //�ϴ�ʹ�ô���
	UINT16           wBagPos; //���ڱ���λ��
	UINT64           qwItemNewTime; //��������ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GOODS_DATA;

typedef struct tagDT_BAG_GOODS_DATA_LST{
	UINT16           wGoodsNum; //װ������
	DT_GOODS_DATA    astGoodsList[MAX_BAG_OPEN_NUM_NEW]; //װ����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BAG_GOODS_DATA_LST;

typedef struct tagDT_DRUG_DATA{
	UINT8            byLevel; //��ҩ�ȼ�
	UINT8            byNum; //��ҩ����
	UINT16           wHeroKindID; //ʹ�õ��佫ID���������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DRUG_DATA;

typedef struct tagDT_DRUG_DATA_LST{
	UINT8            byDrugLevelNum; //��ҩ�������
	DT_DRUG_DATA     astDrugList[MAX_DRUG_LEVEL]; //��ҩ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DRUG_DATA_LST;

typedef struct tagDT_GODWEAPON_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT16           wQuality; //Ʒ��
	UINT16           wLevel; //�ȼ�
	UINT16           wHeroKindID; //ӵ�е��佫����ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GODWEAPON_DATA;

typedef struct tagDT_ATTACK_RANG_DATA{
	UINT8            byAttackRangKind; //������Χ����
	UINT8            byTraceBuffKind; //׷�ٵ�buff����(ֻ��AttackRangKindΪEARK_BUFF��Ч)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_RANG_DATA;

typedef struct tagDT_SKILL_DATA{
	UINT16           wActionID; //ʹ����ʽ
	UINT16           wActionLevel; //ʹ����ʽ�ȼ�
	UINT16           wEffectID; //ʹ��Ч��
	DT_ATTACK_RANG_DATA stAttackRangInfo; //������Χ
	UINT32           dwActionExp; //��ʽ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SKILL_DATA;

typedef struct tagDT_SKILL_DATA_LST{
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_DATA    astSkillInfo[MAX_SKILL_SLOT_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SKILL_DATA_LST;

typedef struct tagDT_STUDY_DATA{
	UINT8            byStudyColorKind; //�ĵ���ɫ����1��ʼ��0��ʾû������
	UINT8            byStudyAttrKind1; //�ĵ�����(��Ӧ��������,0��ʾֻ��ת������)
	UINT8            byStudyLevel; //�ĵõȼ�
	UINT8            byStudyAttrKind2; //�ĵ�����(��Ӧ��������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STUDY_DATA;

typedef struct tagDT_AWAKEN_BASE_DATA{
	UINT8            byLevel; //����ȼ���0��û�����ݣ�
	UINT8            byGoldFlag; //�Ƿ�Ԫ�������־��0���ǣ�1�ǣ�
	UINT64           qwStudyExp; //�ĵþ���
	UINT16           wHaveCallNum; //���ٻ�����
	UINT64           qwlastCallTime; //�ϴ��ٻ�ʱ��
	UINT64           qwStudyClip; //�ĵ���Ƭ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_AWAKEN_BASE_DATA;

typedef struct tagDT_AWAKEN_BASE_DATA1{
	UINT8            byLevel; //����ȼ���0��û�����ݣ�
	UINT8            byGoldFlag; //�Ƿ�Ԫ�������־��0���ǣ�1�ǣ�
	UINT64           qwStudyExp; //�ĵþ���
	UINT16           wHaveCallNum; //���ٻ�����
	UINT64           qwlastCallTime; //�ϴ��ٻ�ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_AWAKEN_BASE_DATA1;

typedef struct tagDT_AWAKEN_DATA{
	DT_AWAKEN_BASE_DATA stBaseInfo; //���������Ϣ
	DT_STUDY_DATA    astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT8            byZTSUseTime; //����ʦ�������Դ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_AWAKEN_DATA;

typedef struct tagDT_AWAKEN_DATA_LST{
	DT_STUDY_DATA    astStudyInfo[MAX_HERO_STUDY_GRID_NUM]; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_AWAKEN_DATA_LST;

typedef struct tagDT_ABSORB_DATA_LST{
	UINT8            byAbsorbNum; //��ǰ���մ���
	UINT16           awKindIDLst[MAX_ABSORB_NUM]; //���� �佫��Ϣ
	UINT16           wAbsorbKindID; //���չ���ǰ�佫���佫ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ABSORB_DATA_LST;

typedef struct tagDT_ATTR_INC_DATA{
	UINT8            byAttrKind; //��������
	UINT32           dwAttrValue; //����ֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTR_INC_DATA;

typedef struct tagDT_BATTLE_ATTR_LST_INFO{
	UINT8            byAttrNum; //��������
	DT_ATTR_INC_DATA astAttrInfo[MAX_SCIENCE_ATTR_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ATTR_LST_INFO;

typedef struct tagDT_BATTLE_ATTR_EXT_INFO{
	UINT8            byKindID; //����Ŀ��(commondef.h)
	UINT32           dwKindValue; //����ֵ
	UINT8            byLevel; //���ӵȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ATTR_EXT_INFO;

typedef struct tagDT_BATTLE_ATTR_EXT_LST_INFO{
	UINT8            byExtAttrNum; //������������
	DT_BATTLE_ATTR_EXT_INFO astExtAttrInfo[MAX_SCIENCE_ATTR_NUM]; //����������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ATTR_EXT_LST_INFO;

typedef struct tagDT_JEWELRY_DATA{
	UINT16           wJewelryID; //��ƷID
	UINT16           wJewelryLevel; //��ƷLevel
	UINT8            byJewelryDressPos; //��Ʒ����(����λ��)
	DT_BATTLE_ATTR_LST_INFO stBaseAttrLst; //��Ʒ��������
	DT_BATTLE_ATTR_EXT_LST_INFO stExtAttrLst; //��Ʒ��������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT16           wBagPos; //���ڱ���λ��
	UINT64           qwItemNewTime; //��������ʱ��
	UINT16           wStrengLevel; //��Ʒǿ���ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_JEWELRY_DATA;

typedef struct tagDT_JEWELRY_DATA_LST{
	UINT16           wJewelryNum; //���θ���
	DT_JEWELRY_DATA  astJewelryInfo[MAX_JEWELRY_POS]; //��Ʒ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_JEWELRY_DATA_LST;

typedef struct tagDT_BAG_JEWELRY_DATA_LST{
	UINT16           wJewelryNum; //���θ���
	DT_JEWELRY_DATA  astJewelryInfo[MAX_BAG_OPEN_NUM_NEW]; //װ����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BAG_JEWELRY_DATA_LST;

typedef struct tagDT_HERO_DATA{
	DT_HERO_BASE_DATA stHeroBaseData; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST stEquipDataInfo; //�佫װ����Ϣ
	DT_DRUG_DATA_LST stDrugDataInfo; //��ҩ��Ϣ
	DT_GODWEAPON_DATA stGodweaponInfo; //������Ϣ
	DT_SKILL_DATA_LST stSkillInfo; //������Ϣ
	DT_AWAKEN_DATA_LST stStudyInfo; //�ĵ���Ϣ
	DT_ABSORB_DATA_LST stAbsorbInfo; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_DATA;

typedef struct tagDT_HERO_DATA_LIST{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_DATA     astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	DT_JEWELRY_DATA_LST astjewelryInfoLst[MAX_HERO_NUM]; //��Ʒ��Ϣ
	DT_HERO_SOUL_DATA astSoulInfoLst[MAX_HERO_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_DATA_LIST;

typedef struct tagDT_BUILD_BASE_DATA{
	UINT8            byKindID; //��������
	UINT16           wLevel; //�ȼ�
	UINT64           qwValue1; //��������Ϊ�ջ�ʱ��
	UINT64           qwValue2; //��������Ϊ����ʱ��
	UINT8            byValue3; //��������Ϊ���յĴ���
	UINT8            bySort; //��������
	UINT8            byHaveOpenFlag; //�����Ƿ�򿪹���1Ϊ�򿪹�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BUILD_BASE_DATA;

typedef struct tagDT_BUILD_DATA_LIST{
	UINT16           wBuildNum; //������Ŀ
	DT_BUILD_BASE_DATA astBuildInfoLst[MAX_BUILD_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BUILD_DATA_LIST;

typedef struct tagDT_INSTANCE_ID{
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
	UINT8            byInstanceIdx; //�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_INSTANCE_ID;

typedef struct tagDT_INSTANCE_DATA{
	DT_INSTANCE_ID   stInstanceID; //�������
	UINT64           qwLastPassTime; //�ϴθ���ͨ��ʱ��
	UINT8            byScore; //����ͨ�ص÷�
	UINT32           dwSuccessNum; //ͨ�سɹ�����
	UINT32           dwFailedNum; //ͨ��ʧ�ܴ���
	UINT16           wLastConFailedNum; //�ϴδ򸱱�ʧ�ܴ���
	UINT16           wMaxConFailedNum; //�򸱱����ʧ�ܴ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_INSTANCE_DATA;

typedef struct tagDT_INSTANCE_DATA_LIST{
	UINT16           wSceneIdx; //�������
	UINT16           wInstanceNum; //������Ŀ
	DT_INSTANCE_DATA astInstanceInfo[MAX_INSTANCE_PER_SCENE_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_INSTANCE_DATA_LIST;

typedef struct tagDT_SCIENCE_ATTREXT{
	UINT8            byAttrKindID; //��������
	UINT16           wAttrLevel; //�Ƽ����Եȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SCIENCE_ATTREXT;

typedef struct tagDT_SCIENCE_ATTREXT_LIST{
	UINT8            byAttrNum; //�Ƽ���������Ŀ
	DT_SCIENCE_ATTREXT astBuildInfoLst[MAX_SCIENCE_ATTR_NUM]; //�Ƽ���������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SCIENCE_ATTREXT_LIST;

typedef struct tagDT_CROWN_TASK_CONDITION{
	UINT16           wCrownTimes; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CROWN_TASK_CONDITION;

typedef struct tagDT_BUILDUPGRADE_TASK_CONDITION{
	UINT8            byBuildKindID; //
	UINT16           wLevel; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BUILDUPGRADE_TASK_CONDITION;

typedef struct tagDT_RECRUITHERO_TASK_CONDITION{
	UINT16           wRecruitHeroKindID1; //
	UINT16           wRecruitHeroKindID2; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RECRUITHERO_TASK_CONDITION;

typedef struct tagDT_CROWN_HEROCOLOR_CONDITION{
	UINT16           wHeroColor; //
	UINT8            byNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CROWN_HEROCOLOR_CONDITION;

typedef struct tagDT_CROWN_HEROUPGRADE_CONDITION{
	UINT16           wHeroLevel; //
	UINT8            byNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CROWN_HEROUPGRADE_CONDITION;

typedef struct tagDT_FIRSTPASSINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FIRSTPASSINSTANCE_TASK_CONDITION;

typedef struct tagDT_SCOREPASSINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byScore; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SCOREPASSINSTANCE_TASK_CONDITION;

typedef struct tagDT_TIMESPASSINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byTimes; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_TIMESPASSINSTANCE_TASK_CONDITION;

typedef struct tagDT_KILLMONSTERINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT16           wMonsterKindID; //
	UINT8            byKillNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_KILLMONSTERINSTANCE_TASK_CONDITION;

typedef struct tagDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION{
	UINT16           wEquipKindID; //
	UINT16           wLevel; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION;

typedef struct tagDT_STRENGTHENEQUIPNUM_TASK_CONDITION{
	UINT16           wEquipKindID; //
	UINT16           wNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STRENGTHENEQUIPNUM_TASK_CONDITION;

typedef struct tagDT_ITEMCOLLECT_TASK_CONDITION{
	UINT16           wItemKindNum; //
	UINT8            abyItemCollectInfo[MAX_ITEM_KIND_COLLECT_NUM]; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ITEMCOLLECT_TASK_CONDITION;

typedef struct tagDT_ACTIVATEGODWEAPON_TASK_CONDITION{
	UINT16           wHeroKindID; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ACTIVATEGODWEAPON_TASK_CONDITION;

typedef struct tagDT_UPGRADEGODWEAPON_TASK_CONDITION{
	UINT16           wHeroKindID; //
	UINT16           wQuality; //
	UINT16           wLevel; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UPGRADEGODWEAPON_TASK_CONDITION;

typedef struct tagDT_UPGRADEDRUG_TASK_CONDITION{
	UINT16           wUpgradeNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UPGRADEDRUG_TASK_CONDITION;

typedef struct tagDT_CHALLENGE_TASK_CONDITION{
	UINT16           wChallengeNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CHALLENGE_TASK_CONDITION;

typedef struct tagDT_PLUNDER_TASK_CONDITION{
	UINT16           wPlunderNum; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLUNDER_TASK_CONDITION;

typedef struct tagDT_DRESSSKILL_TASK_CONDITION{
	UINT16           wSkillID; //
	UINT8            byDressFlag; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DRESSSKILL_TASK_CONDITION;

typedef struct tagDT_DRESSEQUIP_TASK_CONDITION{
	UINT16           wEquipID; //
	UINT8            byDressFlag; //

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DRESSEQUIP_TASK_CONDITION;

typedef struct tagDT_UPGRADEEQUIP_TASK_CONDITION{
	UINT16           wEquipID; //װ��ID
	UINT8            byUpgradeFlag; //��ɱ�־

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UPGRADEEQUIP_TASK_CONDITION;

typedef struct tagDT_USEEXPRIENCEDRUG_TASK_CONDITION{
	UINT16           wNum; //���ô���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_USEEXPRIENCEDRUG_TASK_CONDITION;

typedef struct tagDT_MELT_EQUIP_TASK_CONDITION{
	UINT16           wNum; //���ô���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MELT_EQUIP_TASK_CONDITION;

typedef struct tagDT_COMPOSEGOOD_TASK_CONDITION{
	UINT16           wMaterialID; //ԭ��ID
	UINT16           wMaterialNum; //ԭ�Ϻϳɸ���
	UINT16           wKindID; //�ϳɵ���ƷID
	UINT16           wNum; //�ϳɴ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COMPOSEGOOD_TASK_CONDITION;

typedef struct tagDT_ELITEINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byUpgradeFlag; //��ɱ�־

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ELITEINSTANCE_TASK_CONDITION;

typedef struct tagDT_UPGRADSCIENCE_TASK_CONDITION{
	UINT16           wNum; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UPGRADSCIENCE_TASK_CONDITION;

typedef struct tagDT_STRENGTHATTACK_TASK_CONDITION{
	UINT16           wNum; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STRENGTHATTACK_TASK_CONDITION;

typedef struct tagDT_STRENGTHLIFE_TASK_CONDITION{
	UINT16           wNum; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STRENGTHLIFE_TASK_CONDITION;

typedef struct tagDT_CROP_TASK_CONDITION{
	UINT16           wNum; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CROP_TASK_CONDITION;

typedef struct tagDT_UPGRADESKILL_TASK_CONDITION{
	UINT16           wSkillActionID; //��ֵ��Դ��Ϣ
	UINT16           wLevel; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UPGRADESKILL_TASK_CONDITION;

typedef struct tagDT_UPGRADEJINGJIE_TASK_CONDITION{
	UINT16           wLevel; //�������� ��
	UINT16           wSubLevel; //�������� ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UPGRADEJINGJIE_TASK_CONDITION;

typedef struct tagDT_MOSAICGEM_TASK_CONDITION{
	UINT16           wNum; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MOSAICGEM_TASK_CONDITION;

typedef struct tagDT_CLIMBTOWER_TASK_CONDITION{
	UINT16           wNum; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CLIMBTOWER_TASK_CONDITION;

typedef struct tagDT_STUDY_TASK_CONDITION{
	UINT8            byLevel; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STUDY_TASK_CONDITION;

typedef struct tagDT_RECRUITHERO_NUM_TASK_CONDITION{
	UINT16           wNum; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RECRUITHERO_NUM_TASK_CONDITION;

typedef struct tagDT_OPENLIGHT_TASK_CONDITION{
	UINT8            byExt; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_OPENLIGHT_TASK_CONDITION;

typedef union tagDT_TASK_CONDITION{
	DT_CROWN_TASK_CONDITION stCrown; //��ֵ��Դ��Ϣ
	DT_RECRUITHERO_TASK_CONDITION stRecruitHero; //��ֵ��Դ��Ϣ
	DT_UPGRADESKILL_TASK_CONDITION stUpgradeSkill; //��ֵ��Դ��Ϣ
	DT_UPGRADEJINGJIE_TASK_CONDITION stUpgradeJingJie; //��ֵ��Դ��Ϣ
	DT_FIRSTPASSINSTANCE_TASK_CONDITION stFirstPassInstance; //��ֵ��Դ��Ϣ
	DT_SCOREPASSINSTANCE_TASK_CONDITION stScorePassInstance; //��ֵ��Դ��Ϣ
	DT_TIMESPASSINSTANCE_TASK_CONDITION stTimesPassInstance; //��ֵ��Դ��Ϣ
	DT_KILLMONSTERINSTANCE_TASK_CONDITION stKillMonstersInstance; //��ֵ��Դ��Ϣ
	DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION stStrengthenEquipLevel; //��ֵ��Դ��Ϣ
	DT_STRENGTHENEQUIPNUM_TASK_CONDITION stStrengthenEquipNum; //��ֵ��Դ��Ϣ
	DT_MOSAICGEM_TASK_CONDITION stMosaicGem; //��ֵ��Դ��Ϣ
	DT_ACTIVATEGODWEAPON_TASK_CONDITION stActivateGodweapon; //��ֵ��Դ��Ϣ
	DT_UPGRADEGODWEAPON_TASK_CONDITION stUpgradeGodweapon; //��ֵ��Դ��Ϣ
	DT_CHALLENGE_TASK_CONDITION stChallenge; //��ֵ��Դ��Ϣ
	DT_PLUNDER_TASK_CONDITION stPlunder; //��ֵ��Դ��Ϣ
	DT_CLIMBTOWER_TASK_CONDITION stClimbTower; //��ֵ��Դ��Ϣ
	DT_DRESSEQUIP_TASK_CONDITION stDressEquip; //��ֵ��Դ��Ϣ
	DT_USEEXPRIENCEDRUG_TASK_CONDITION stUseExprienceDrug; //��ֵ��Դ��Ϣ
	DT_COMPOSEGOOD_TASK_CONDITION stComposeGood; //��ֵ��Դ��Ϣ
	DT_ELITEINSTANCE_TASK_CONDITION stEliteInstance; //��ֵ��Դ��Ϣ
	DT_UPGRADSCIENCE_TASK_CONDITION stUpgradeScience; //��ֵ��Դ��Ϣ
	DT_STRENGTHATTACK_TASK_CONDITION stStrengthAttack; //��ֵ��Դ��Ϣ
	DT_STRENGTHLIFE_TASK_CONDITION stStrengthLife; //��ֵ��Դ��Ϣ
	DT_CROP_TASK_CONDITION stCrop; //��ֵ��Դ��Ϣ
	DT_MELT_EQUIP_TASK_CONDITION stMeltEquip; //��ֵ��Դ��Ϣ
	DT_STUDY_TASK_CONDITION stStudy; //��ֵ��Դ��Ϣ
	DT_RECRUITHERO_NUM_TASK_CONDITION stRecruitHeroNum; //��ֵ��Դ��Ϣ
	DT_OPENLIGHT_TASK_CONDITION stOpenLight; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(const UINT8 bySelectType, CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const UINT8 bySelectType, const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_TASK_CONDITION;

typedef struct tagDT_TASK_DATA{
	UINT8            byTaskLine; //������
	UINT32           dwTaskIdx; //�������(�ڸ��������ڵ�)
	UINT64           qwStateUpdateTime; //״̬����ʱ��
	UINT8            byTaskState; //����״̬��0δ���ܣ�1�ѽ���δ���
	UINT8            byTaskType; //�������������¼
	DT_TASK_CONDITION stTaskConditionInfo; //�������������¼

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_TASK_DATA;

typedef struct tagDT_TASK_DATA_LIST{
	UINT8            byTaskNum; //������(ÿ��1��)
	DT_TASK_DATA     astTaskInfoList[MAX_TASK_LINE_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_TASK_DATA_LIST;

typedef struct tagDT_RACE_BASE_DATA{
	UINT32           dwRank; //����
	UINT16           wContiWin; //��ǰ��ʤ����
	UINT64           qwRecvEncourageTime; //��ȡ����������ʱ��
	UINT64           qwLastChallTime; //������սʱ��
	UINT8            byChallTimes; //������ս����
	UINT8            byFailedFlag; //�Ƿ�������ս��
	UINT8            byUnreadBattleLogNum; //δ�ۿ�ս������
	UINT32           dwRecvEncourageRank; //��ȡ��������(��һ��(��������)������)
	UINT64           qwNotifyRankTime; //��󽻻�����ʱ��
	UINT32           dwNotifyRank; //��󽻻�����
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RACE_BASE_DATA;

typedef struct tagDT_LOCALE_HOME{
	UINT8            byExt; //��չ�ֶΣ���ʱ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCALE_HOME;

typedef struct tagDT_LOCALE_INSTANCE{
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
	UINT8            byInstanceIdx; //�������
	UINT8            byBattleIdx; //ս�����
	UINT8            bySuccessFlag; //ս����Ӯ��0Ϊ����1ΪӮ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCALE_INSTANCE;

typedef struct tagDT_LOCALE_ONHOOK{
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
	UINT8            byInstanceIdx; //�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCALE_ONHOOK;

typedef struct tagDT_LOCALE_MARK{
	UINT8            byExt; //��չ�ֶΣ���ʱ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCALE_MARK;

typedef union tagDT_LOCALE_DATA_UNION{
	DT_LOCALE_HOME   stHome; //��ֵ��Դ��Ϣ
	DT_LOCALE_INSTANCE stInstance; //��ֵ��Դ��Ϣ
	DT_LOCALE_ONHOOK stOnhook; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stEatBread; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stBossB; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stHotSpring; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stCourage; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stFaction; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stCourageBattle; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stSoul; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stPet; //��ֵ��Դ��Ϣ
	DT_LOCALE_MARK   stNeiDan; //��ֵ��Դ��Ϣ

	INT32 EncodeSaveData(const UINT8 bySelectType, CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const UINT8 bySelectType, const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCALE_DATA_UNION;

typedef struct tagDT_LOCALE_DATA{
	UINT8            byLocaleType; //λ������
	DT_LOCALE_DATA_UNION stLocaleInfo; //λ����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCALE_DATA;

typedef struct tagUnlockScienceInfo{
	UINT8            byUnlockNum; //�����Ƽ���
	UINT8            abyUnlockScienceID[MAX_SCIENCE_ATTR_NUM]; //�Ƽ�ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}UnlockScienceInfo;

typedef struct tagDT_HERO_UPGRADE_DATA{
	UINT16           wHeroKindID; //�佫����ID
	UINT8            byUpgradeFlag; //�Ƿ�����
	UINT16           wLevel; //��ǰ�ȼ�
	UINT32           dwEncExperience; //��������
	UINT32           dwExperience; //��ǰ����
	UINT32           dwUpgradeExperience; //��һ����������
	UINT16           wCanUseBoxGoodsID; //��ʹ�������ƷID,0Ϊû��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_UPGRADE_DATA;

typedef struct tagDT_STATE_DATA{
	UINT32           dwInstanceMAXHP; //HP
	UINT32           dwInstanceCurHP; //HP
	UINT16           wDoubleExpNum; //���鱶�ʸ����ȴ���
	UINT8            byOpenBoxFlag; //�Ƿ�򿪹���������
	UINT8            abyHitItemIdx[MAX_ENCOURAGE_BOX_GROUP_NUM]; //���еı�����Ʒ���
	UINT16           awUnlockHeroID[MAX_UNLOCK_HERO_NUM]; //���������ʾ
	UINT16           wUnlockSkillID; //����������ʾ
	UINT16           wUnlockEquipLevel; //����װ����ʾ
	UnlockScienceInfo stUnlockScienceList; //�����Ƽ���ʾ
	UINT64           qwRegisterDispNameTime; //ע���ǳ�ʱ�䣬0��ʾδע��
	UINT32           dwUnlockElite; //������Ӣ������ʾ(0��ʾû�У���1���ֽڱ�ʾ��Ӣ��������idx����2/3���ֽڱ�ʾ������ID)
	UINT8            byUpgradeHeroNum; //�����佫����
	DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_STATE_DATA;

typedef struct tagDT_MONSTER_BASE_DATA{
	UINT16           wKindID; //����������
	UINT16           wLevel; //������ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MONSTER_BASE_DATA;

typedef struct tagDT_MONSTER_DATA_LIST{
	UINT16           wMonsterNum; //�������
	DT_MONSTER_BASE_DATA astMonsterInfListo[MAX_INSTANCE_MONSTER_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MONSTER_DATA_LIST;

typedef struct tagDT_GODWEAPON_BATTLE_DATA{
	UINT16           wQuality; //�����׼�Ʒ�ʣ�0��ʾû��
	UINT16           wLevel; //�����ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttr; //ս������
	UINT8            byHPGridNum; //HP������
	UINT16           wMaxQuality; //������߽׼�Ʒ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GODWEAPON_BATTLE_DATA;

typedef struct tagDT_BATTLE_OBJ_DATA{
	UINT16           wKindID; //����ID
	UINT8            byCareerID; //ְҵID
	UINT16           wLevel; //�ȼ�
	UINT8            byFomationIdx; //����λ��(��1��ʼ)
	DT_BATTLE_ATTRIBUTE stBattleAttr; //ս������
	UINT16           wSkillActionID; //������ʽID(0��ʾû�м���)
	UINT16           wSkillActionLevel; //������ʽ�ȼ�
	UINT16           wNeedAngry; //�ͷ�����ŭ��
	UINT16           wInitAngry; //��ʼŭ��
	UINT8            byHPGridNum; //HP������
	UINT8            byColor; //��ɫ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_DATA;

typedef struct tagDT_BATTLE_OBJ_DATA2{
	UINT16           wKindID; //����ID
	UINT8            byCareerID; //ְҵID
	UINT16           wLevel; //�ȼ�
	UINT8            byFomationIdx; //����λ��(��1��ʼ)
	DT_BATTLE_ATTRIBUTE stBattleAttr; //ս������
	UINT16           wSkillActionID; //������ʽID(0��ʾû�м���)
	UINT16           wSkillActionLevel; //������ʽ�ȼ�
	UINT16           wNeedAngry; //�ͷ�����ŭ��
	UINT16           wInitAngry; //��ʼŭ��
	UINT8            byHPGridNum; //HP������
	UINT8            byColor; //��ɫ
	DT_GODWEAPON_BATTLE_DATA stGodweaponInfo; //����ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_DATA2;

typedef struct tagDT_BATTLE_OBJ_GROUP_DATA{
	UINT8            byObjNum; //ս������Ϣ
	DT_BATTLE_OBJ_DATA astBattleObjInfo[MAX_FORMATION_IDX_NUM]; //ս������Ϣ
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT32           dwPlayerID; //���ID������Ϊ0��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_GROUP_DATA;

typedef struct tagDT_BATTLE_OBJ_GROUP_DATA2{
	UINT8            byObjNum; //ս������Ϣ
	DT_BATTLE_OBJ_DATA2 astBattleObjInfo[MAX_FORMATION_IDX_NUM]; //ս������Ϣ
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT32           dwPlayerID; //���ID������Ϊ0��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_GROUP_DATA2;

typedef struct tagDT_BUFF_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT16           wAddDelFlag; //����/ɾ����־(0,������1ɾ��)
	UINT8            byBuffID; //BuffID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BUFF_DATA;

typedef struct tagDT_HP_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	INT32            nHP; //HP, >0���Ѫ��<0��ȥѪ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HP_DATA;

typedef struct tagDT_ANGRY_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	INT16            shAngry; //ŭ��, >0��ӣ�<0��ȥ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ANGRY_DATA;

typedef struct tagDT_PARRY_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT8            byParryFlag; //�񵲱�־��1��,
	UINT8            byBeCritFlag; //��������־��1������,

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PARRY_DATA;

typedef struct tagDT_SKILL_EFFECT_ID_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT16           wEffectID; //Ч��ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SKILL_EFFECT_ID_DATA;

typedef struct tagDT_ATTACK_OBJ_DATA{
	UINT8            byBuffChangeNum; //buff�仯
	DT_BUFF_DATA     astBuffChangeInfo[MAX_BUFF_CHANGE_TIMES_PER_ROUND]; //buff�仯
	UINT8            byHpChangeNum; //Ѫ���仯,>0���Ѫ��<0��ȥѪ
	DT_HP_DATA       astHpChangeInfo[MAX_HP_CHANGE_TIMES_PER_ROUND]; //Ѫ���仯,>0���Ѫ��<0��ȥѪ
	UINT8            byAngryChangeNum; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	DT_ANGRY_DATA    astAngryChangeInfo[MAX_ANGRY_CHANGE_TIMES_PER_ROUND]; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	UINT8            bySkillEffectIDChangeNum; //����Ч���仯
	DT_SKILL_EFFECT_ID_DATA astSkillEffectIDChangeInfo[MAX_BUFF_CHANGE_TIMES_PER_ROUND]; //����Ч���仯

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_OBJ_DATA;

typedef struct tagDT_ATTACK_OBJ_DATA2{
	UINT8            byBuffChangeNum; //buff�仯
	DT_BUFF_DATA     astBuffChangeInfo[MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND]; //buff�仯
	UINT8            byHpChangeNum; //Ѫ���仯,>0���Ѫ��<0��ȥѪ
	DT_HP_DATA       astHpChangeInfo[MAX_HP_CHANGE_TIMES_PER_ROUND]; //Ѫ���仯,>0���Ѫ��<0��ȥѪ
	UINT8            byAngryChangeNum; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	DT_ANGRY_DATA    astAngryChangeInfo[MAX_NEW_ANGRY_CHANGE_TIMES_PER_ROUND]; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	UINT8            bySkillEffectIDChangeNum; //����Ч���仯
	DT_SKILL_EFFECT_ID_DATA astSkillEffectIDChangeInfo[MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND]; //����Ч���仯

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_OBJ_DATA2;

typedef struct tagDT_ATTACK_DATA{
	DT_ATTACK_OBJ_DATA stMyselfObjInfo; //�ҷ���Ϣ
	DT_ATTACK_OBJ_DATA stEnemyObjInfo; //�з���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_DATA;

typedef struct tagDT_ATTACK_DATA2{
	DT_ATTACK_OBJ_DATA2 stMyselfObjInfo; //�ҷ���Ϣ
	DT_ATTACK_OBJ_DATA2 stEnemyObjInfo; //�з���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_DATA2;

typedef struct tagDT_GODWEAPON_ATTACK_DATA{
	UINT8            byAttackFlag; //������־��0��������1Ϊ����
	UINT32           dwAttackHurtValue; //�����Եз����˺�
	UINT8            byAngryChangeNum; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	DT_ANGRY_DATA    astAngryChangeInfo[MAX_ANGRY_CHANGE_TIMES_PER_ROUND]; //ŭ���仯,>0���Ѫ��<0��ȥѪ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GODWEAPON_ATTACK_DATA;

typedef struct tagDT_GODWEAPON_ATTACK_DATA2{
	UINT8            byAttackFlag; //������־��0��������1Ϊ����
	UINT32           dwAttackHurtValue; //�����Եз����˺�
	UINT8            byEnemyFormationIdx; //�Է�����λ��
	UINT8            byAngryChangeNum; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	DT_ANGRY_DATA    astAngryChangeInfo[MAX_ANGRY_CHANGE_TIMES_PER_ROUND]; //ŭ���仯,>0���Ѫ��<0��ȥѪ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GODWEAPON_ATTACK_DATA2;

typedef struct tagDT_ATTACK_ALL_DATA{
	UINT8            byAttackerIdx; //������������ţ���1��ʼ)
	UINT16           wAttackSkillID; //����������ʽKindID(0Ϊ��ͨ����������Ϊ������ʽID)
	UINT8            bySkipFlag; //����������־(1��������)
	UINT8            byBeAttackerIdxNum; //�ܻ�����/������Ϣ����1��ʼ)
	DT_PARRY_DATA    astBeAttackerIdxInfo[MAX_FORMATION_IDX_NUM]; //�ܻ�����/������Ϣ����1��ʼ)
	DT_ATTACK_DATA   stBeforeAttack; //�ܻ�ǰ��Ϣ
	DT_ATTACK_DATA   stAfterAttack; //�ܻ�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_ALL_DATA;

typedef struct tagDT_ATTACK_ALL_DATA2{
	UINT8            byAttackerIdx; //������������ţ���1��ʼ)
	UINT16           wAttackSkillID; //����������ʽKindID(0Ϊ��ͨ����������Ϊ������ʽID)
	UINT8            bySkipFlag; //����������־(1��������)
	UINT8            byBeAttackerIdxNum; //�ܻ�����/������Ϣ����1��ʼ)
	DT_PARRY_DATA    astBeAttackerIdxInfo[MAX_FORMATION_IDX_NUM]; //�ܻ�����/������Ϣ����1��ʼ)
	DT_ATTACK_DATA   stBeforeAttack; //�ܻ�ǰ��Ϣ
	DT_ATTACK_DATA   stAfterAttack; //�ܻ�����Ϣ
	DT_GODWEAPON_ATTACK_DATA stGodweaponAttackInfo; //����������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_ALL_DATA2;

typedef struct tagDT_ATTACK_ALL_DATA3{
	UINT8            byAttackerIdx; //������������ţ���1��ʼ)
	UINT16           wAttackSkillID; //����������ʽKindID(0Ϊ��ͨ����������Ϊ������ʽID)
	UINT8            bySkipFlag; //����������־(1��������)
	UINT8            byBeAttackerIdxNum; //�ܻ�����/������Ϣ����1��ʼ)
	DT_PARRY_DATA    astBeAttackerIdxInfo[MAX_FORMATION_IDX_NUM]; //�ܻ�����/������Ϣ����1��ʼ)
	DT_ATTACK_DATA2  stBeforeAttack; //�ܻ�ǰ��Ϣ
	DT_ATTACK_DATA2  stAfterAttack; //�ܻ�����Ϣ
	DT_GODWEAPON_ATTACK_DATA stGodweaponAttackInfo; //����������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_ALL_DATA3;

typedef struct tagDT_BATTLE_ANGRY_DATA{
	UINT8            bySlot; //���ܲ�(��0��ʼ)
	UINT16           wCurAngry; //��ǰŭ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ANGRY_DATA;

typedef struct tagDT_BATTLE_ROUND_DATA{
	UINT8            byAttackerFlag; //�����߱�־��0Ϊ�ҷ�
	DT_ATTACK_ALL_DATA stAttackData; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ROUND_DATA;

typedef struct tagDT_BATTLE_ROUND_DATA2{
	UINT8            byAttackerFlag; //�����߱�־��0Ϊ�ҷ�
	DT_ATTACK_ALL_DATA2 stAttackData; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ROUND_DATA2;

typedef struct tagDT_BATTLE_ROUND_DATA3{
	UINT8            byAttackerFlag; //�����߱�־��0Ϊ�ҷ�
	DT_ATTACK_ALL_DATA3 stAttackData; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ROUND_DATA3;

typedef struct tagDT_BATTLE_DATA{
	DT_BATTLE_OBJ_GROUP_DATA stMyselfInfo; //�ҷ���Ϣ(����/������)
	DT_BATTLE_OBJ_GROUP_DATA stEnemyInfo; //�з���Ϣ
	UINT8            byBattleResult; //��սս�������0Ϊ�ҷ�Ӯ��1�Է�Ӯ��2�ҷ�Ӯ������ͨ��
	UINT8            byScore; //ս������
	UINT8            byBattleRoundNum; //ս���غ���
	DT_BATTLE_ROUND_DATA astBattleRoundInfo[MAX_BATTLE_ROUND_NUM]; //ս���غ���Ϣ
	DT_BATTLE_ATTRIBUTE stMyselfInfoAfterBattle; //ս�����ҷ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_DATA;

typedef struct tagDT_BATTLE_DATA2{
	DT_BATTLE_OBJ_GROUP_DATA2 stMyselfInfo; //�ҷ���Ϣ(����/������)
	DT_BATTLE_OBJ_GROUP_DATA2 stEnemyInfo; //�з���Ϣ
	UINT8            byBattleResult; //��սս�������0Ϊ�ҷ�Ӯ��1�Է�Ӯ��2�ҷ�Ӯ������ͨ��
	UINT8            byScore; //ս������
	UINT8            byBattleRoundNum; //ս���غ���
	DT_BATTLE_ROUND_DATA2 astBattleRoundInfo[MAX_BATTLE_ROUND_NUM]; //ս���غ���Ϣ
	DT_BATTLE_ATTRIBUTE stMyselfInfoAfterBattle; //ս�����ҷ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_DATA2;

typedef struct tagDT_BATTLE_DATA3{
	DT_BATTLE_OBJ_GROUP_DATA2 stMyselfInfo; //�ҷ���Ϣ(����/������)
	DT_BATTLE_OBJ_GROUP_DATA2 stEnemyInfo; //�з���Ϣ
	UINT8            byBattleResult; //��սս�������0Ϊ�ҷ�Ӯ��1�Է�Ӯ��2�ҷ�Ӯ������ͨ��
	UINT8            byScore; //ս������
	UINT8            byBattleRoundNum; //ս���غ���
	DT_BATTLE_ROUND_DATA3 astBattleRoundInfo[MAX_NEW_BATTLE_ROUND_NUM]; //ս���غ���Ϣ
	DT_BATTLE_ATTRIBUTE stMyselfInfoAfterBattle; //ս�����ҷ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_DATA3;

typedef struct tagDT_SHIELD_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT8            byAddDelFlag; //����/ɾ����־(0,������1ɾ��)
	UINT8            bySheldID; //SheldID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SHIELD_DATA;

typedef struct tagDT_HP_DATA2{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	INT32            nHP; //HP, >0���Ѫ��<0��ȥѪ
	UINT8            byEnemyIdx; //���ö���
	UINT8            byReason; //��Ѫԭ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HP_DATA2;

typedef struct tagDT_ATTACK_OBJ_DATA3{
	UINT8            byBuffChangeNum; //buff�仯
	DT_BUFF_DATA     astBuffChangeInfo[MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND]; //buff�仯
	UINT8            byHpChangeNum; //Ѫ���仯,>0���Ѫ��<0��ȥѪ
	DT_HP_DATA2      astHpChangeInfo[MAX_HP_CHANGE_TIMES_PER_ROUND]; //Ѫ���仯,>0���Ѫ��<0��ȥѪ
	UINT8            byAngryChangeNum; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	DT_ANGRY_DATA    astAngryChangeInfo[MAX_NEW_ANGRY_CHANGE_TIMES_PER_ROUND]; //ŭ���仯,>0���Ѫ��<0��ȥѪ
	UINT8            bySkillEffectIDChangeNum; //����Ч���仯
	DT_SKILL_EFFECT_ID_DATA astSkillEffectIDChangeInfo[MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND]; //����Ч���仯
	UINT8            byShieldChangeNum; //�����ֱ仯
	DT_SHIELD_DATA   astShieldChangeInfo[MAX_FORMATION_IDX_NUM]; //�����ֱ仯

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_OBJ_DATA3;

typedef struct tagDT_ATTACK_DATA3{
	DT_ATTACK_OBJ_DATA3 stMyselfObjInfo; //�ҷ���Ϣ
	DT_ATTACK_OBJ_DATA3 stEnemyObjInfo; //�з���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_DATA3;

typedef struct tagDT_PARRY_DATA2{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT8            byParryFlag; //�񵲱�־��1��,
	UINT8            byBeCritFlag; //��������־��1������,
	UINT8            byDodge; //���ܱ�־��1����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PARRY_DATA2;

typedef struct tagDT_ATTACK_ALL_DATA4{
	UINT8            byAttackerIdx; //������������ţ���1��ʼ)
	UINT16           wAttackSkillID; //����������ʽKindID(0Ϊ��ͨ����������Ϊ������ʽID)
	UINT8            bySkipFlag; //����������־(1��������)
	UINT8            byBeAttackerIdxNum; //�ܻ�����/������Ϣ����1��ʼ)
	DT_PARRY_DATA2   astBeAttackerIdxInfo[MAX_FORMATION_IDX_NUM]; //�ܻ�����/������Ϣ����1��ʼ)
	DT_ATTACK_DATA3  stBeforeAttack; //�ܻ�ǰ��Ϣ
	DT_ATTACK_DATA3  stAfterAttack; //�ܻ�����Ϣ
	DT_GODWEAPON_ATTACK_DATA2 stGodweaponAttackInfo; //����������Ϣ
	UINT8            byAttackSpecialEffectFlag; //���⹥����־EBattleSpecialEffects
	UINT8            byEnemySpecialEffectFlag; //���⹥����־EBattleSpecialEffects

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_ALL_DATA4;

typedef struct tagDT_BATTLE_ROUND_DATA4{
	UINT8            byAttackerFlag; //�����߱�־��0Ϊ�ҷ�
	DT_ATTACK_ALL_DATA4 stAttackData; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ROUND_DATA4;

typedef struct tagDT_BATTLE_DATA4{
	DT_BATTLE_OBJ_GROUP_DATA2 stMyselfInfo; //�ҷ���Ϣ(����/������)
	DT_BATTLE_OBJ_GROUP_DATA2 stEnemyInfo; //�з���Ϣ
	UINT8            byBattleResult; //��սս�������0Ϊ�ҷ�Ӯ��1�Է�Ӯ��2�ҷ�Ӯ������ͨ��
	UINT8            byScore; //ս������
	UINT8            byBattleRoundNum; //ս���غ���
	DT_BATTLE_ROUND_DATA4 astBattleRoundInfo[MAX_NEW_BATTLE_ROUND_NUM]; //ս���غ���Ϣ
	DT_BATTLE_ATTRIBUTE stMyselfInfoAfterBattle; //ս�����ҷ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_DATA4;

typedef struct tagDT_ATTACK_ALL_DATA5{
	UINT8            byAttackerIdx; //������������ţ���1��ʼ)
	UINT16           wAttackSkillID; //����������ʽKindID(0Ϊ��ͨ����������Ϊ������ʽID)
	UINT8            bySkipFlag; //����������־(1��������)
	UINT8            byBeAttackerIdxNum; //�ܻ�����/������Ϣ����1��ʼ)
	DT_PARRY_DATA2   astBeAttackerIdxInfo[MAX_FORMATION_IDX_NUM]; //�ܻ�����/������Ϣ����1��ʼ)
	DT_ATTACK_DATA3  stBeforeAttack; //�ܻ�ǰ��Ϣ
	DT_ATTACK_DATA3  stAfterAttack; //�ܻ�����Ϣ
	DT_GODWEAPON_ATTACK_DATA2 stGodweaponAttackInfo; //����������Ϣ
	UINT8            byAttackSpecialEffectFlag; //���⹥����־EBattleSpecialEffects
	UINT8            byEnemySpecialEffectFlag; //���⹥����־EBattleSpecialEffects
	UINT8            byPetAttack; //�Ƿ��ǳ��﹥��0���ǣ�1���﹥��
	UINT16           wPetSkillID; //���﹥������ID
	UINT8            byAttackObj; //�����ҷ������ѷ�commdef.h AttackTarget

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ATTACK_ALL_DATA5;

typedef struct tagDT_BATTLE_ROUND_DATA5{
	UINT8            byAttackerFlag; //�����߱�־��0Ϊ�ҷ�
	DT_ATTACK_ALL_DATA5 stAttackData; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_ROUND_DATA5;

typedef struct tagDT_PET_BATTLE_DATA{
	UINT16           wPetID; //����ID
	UINT16           wPetLevel; //����Level
	UINT8            byPetQuality; //����Ʒ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_BATTLE_DATA;

typedef struct tagDT_BATTLE_OBJ_GROUP_DATA3{
	UINT8            byObjNum; //ս������Ϣ
	DT_BATTLE_OBJ_DATA2 astBattleObjInfo[MAX_FORMATION_IDX_NUM]; //ս������Ϣ
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT32           dwPlayerID; //���ID������Ϊ0��
	DT_PET_BATTLE_DATA stPetInfo; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_GROUP_DATA3;

typedef struct tagDT_BATTLE_DATA5{
	DT_BATTLE_OBJ_GROUP_DATA3 stMyselfInfo; //�ҷ���Ϣ(����/������)
	DT_BATTLE_OBJ_GROUP_DATA3 stEnemyInfo; //�з���Ϣ
	UINT8            byBattleResult; //��սս�������0Ϊ�ҷ�Ӯ��1�Է�Ӯ��2�ҷ�Ӯ������ͨ��
	UINT8            byScore; //ս������
	UINT8            byBattleRoundNum; //ս���غ���
	DT_BATTLE_ROUND_DATA5 astBattleRoundInfo[MAX_NEW_BATTLE_ROUND_NUM]; //ս���غ���Ϣ
	DT_BATTLE_ATTRIBUTE stMyselfInfoAfterBattle; //ս�����ҷ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_DATA5;

typedef struct tagDT_BATTLE_OBJ_MAX_HP{
	UINT8            byFomationIdx; //����λ��(��1��ʼ)
	UINT32           dwMaxHP; //��ѪHP

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_MAX_HP;

typedef struct tagDT_BATTLE_OBJ_MAX_HP_INFO{
	UINT8            byObjNum; //ս���߸���
	DT_BATTLE_OBJ_MAX_HP astBattleObjMaxHPInfo[MAX_FORMATION_IDX_NUM]; //ս������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_OBJ_MAX_HP_INFO;

typedef struct tagDT_EMPTY_HP_VIDEO_v400{
	DT_BATTLE_OBJ_MAX_HP_INFO stMyselfMaxHPInfo; //�������ϸ��������Ѫ��
	DT_BATTLE_OBJ_MAX_HP_INFO stEnemyMaxHPInfo; //�з����ϸ��������Ѫ��
	DT_BATTLE_OBJ_MAX_HP_INFO stMyselfBeforeRecoverHPInfo; //������Ѫǰ���ϸ����ĵ�ǰѪ��
	DT_BATTLE_OBJ_MAX_HP_INFO stEnemyBeforeRecoverHPInfo; //�з���Ѫǰ���ϸ����ĵ�ǰѪ��
	DT_BATTLE_DATA4  stEmptyHPVideo; //¼������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EMPTY_HP_VIDEO_v400;

typedef struct tagDT_EMPTY_HP_VIDEO{
	DT_BATTLE_OBJ_MAX_HP_INFO stMyselfMaxHPInfo; //�������ϸ��������Ѫ��
	DT_BATTLE_OBJ_MAX_HP_INFO stEnemyMaxHPInfo; //�з����ϸ��������Ѫ��
	DT_BATTLE_OBJ_MAX_HP_INFO stMyselfBeforeRecoverHPInfo; //������Ѫǰ���ϸ����ĵ�ǰѪ��
	DT_BATTLE_OBJ_MAX_HP_INFO stEnemyBeforeRecoverHPInfo; //�з���Ѫǰ���ϸ����ĵ�ǰѪ��
	DT_BATTLE_DATA5  stEmptyHPVideo; //¼������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EMPTY_HP_VIDEO;

typedef struct tagDT_FINAL_ROUND_BATTLE_OBJ_INFO{
	DT_BATTLE_OBJ_GROUP_DATA3 stMyselfObj; //�������ϸ��������Ѫ��
	DT_BATTLE_OBJ_GROUP_DATA3 stEnemyObj; //�з����ϸ��������Ѫ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FINAL_ROUND_BATTLE_OBJ_INFO;

typedef struct tagDT_ONLINE_ENCOURAGE_RECORD_DATA{
	UINT8            byRecvDays; //����ȡ����
	UINT64           qwLastRecvTime; //�ϴ���ȡʱ��
	UINT8            byLastRecvIndex; //�ϴ���ȡ�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ONLINE_ENCOURAGE_RECORD_DATA;

typedef struct tagDT_LOGIN_ENCOURAGE_RECORD_DATA{
	UINT16           wKeepDays; //������¼����
	UINT8            byLastRecvNum; //�ϴ���ȡ����
	UINT64           qwLastRecvTime; //�ϴ���ȡʱ��
	UINT8            byLastSelectIndex; //�ϴ�ѡ�е����(��1��ʼ)
	UINT8            byStateFlag; //״̬(LastSelectIndex��Ϊ0ʱ��Ч)(0���·���1��ѡ��2�����)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOGIN_ENCOURAGE_RECORD_DATA;

typedef struct tagDT_RACE_BATTLELOG_DATA{
	UINT8            byChallengeFlag; //��ս��־,0Ϊ������ս��1Ϊ����ս
	UINT64           qwChallengeTime; //��սʱ��
	UINT32           dwEnemyPlayerID; //�Է����ID
	UINT8            byResult; //��ս�����0Ϊ�ҷ�Ӯ��1Ϊ�Է�Ӯ
	UINT32           dwBeginChallengeRank; //��սǰ����
	UINT32           dwAfterChallengeRank; //��ս������
	UINT8            byNewFlag; //�Ƿ���ս����1Ϊ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RACE_BATTLELOG_DATA;

typedef struct tagDT_RACE_BATTLELOG_DATA_LIST{
	UINT8            byBattleLogNum; //ս������
	DT_RACE_BATTLELOG_DATA astBattleLogInfo[MAX_RACE_BATTLELOG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RACE_BATTLELOG_DATA_LIST;

typedef struct tagDT_CAPTURE_DATA{
	UINT32           dwCapturePlayerID; //����²�����ID
	UINT64           qwCaptureTime; //��²��ʱ��
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT64           qwLastCollectTime; //�ϴ���ȡ����ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CAPTURE_DATA;

typedef struct tagDT_CAPTURE_DATA_LIST{
	UINT8            byCaptureNum; //��²����
	DT_CAPTURE_DATA  astCaptureInfo[MAX_CAPTURE_NUM]; //��²��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CAPTURE_DATA_LIST;

typedef struct tagDT_PLUNDER_BATTLELOG_DATA{
	UINT8            byPlunderFlag; //�Ӷ��־
	UINT64           qwPlunderTime; //�Ӷ�ʱ��(��־7/8Ϊ�Զ��ͷ�ʱ��)
	UINT32           dwActivePlayerID; //���������ID(��־7/8Ϊ�ͷŷ�²�ķ�²��ID)
	UINT32           dwPassivePlayerID; //���������ID��־7/8Ϊ���ͷŵķ�²ID)
	UINT32           dwCapturePlayerID; //��²���ID
	UINT8            byResult; //�����0Ϊ������Ӯ��1Ϊ������Ӯ
	UINT64           qwPlunderCoin; //�Ӷ�ͭ��
	UINT64           qwPlunderScience; //�Ӷ������
	UINT8            byNewFlag; //�Ƿ���ս����1Ϊ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLUNDER_BATTLELOG_DATA;

typedef struct tagDT_PLUNDER_BATTLELOG_DATA_LIST{
	UINT8            byBattleLogNum; //ս������
	DT_PLUNDER_BATTLELOG_DATA astBattleLogInfo[MAX_PLUNDER_BATTLELOG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLUNDER_BATTLELOG_DATA_LIST;

typedef struct tagDT_PLUNDER_GRID_DATA{
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT32           dwIncomeValue; //����ֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLUNDER_GRID_DATA;

typedef struct tagDT_PLUNDER_BASE_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT32           dwCaptureOwnerPlayerID; //��²������ID��0��ʾû�б���²
	UINT64           qwBeCaptureTime; //����²��ʱ��
	UINT16           wExtPlunderNum; //�������ӵ��Ӷ����
	UINT64           qwLastPlunderTime; //�ϴ��Ӷ�ʱ��
	UINT16           wLastPlunderNum; //�ϴ�(����)�Ӷ����
	UINT8            byUnreadBattleLogNum; //δ�ۿ�ս������
	UINT64           qwLastDriveAwayTime; //�ϴ����Ϸ�²��ʱ��
	UINT16           wLastDriveAwayNum; //�ϴ�(����)���Ϸ�²������
	DT_PLUNDER_GRID_DATA astCaptureGridInfo[MAX_CAPTURE_NUM]; //��²������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLUNDER_BASE_DATA;

typedef struct tagDT_ENEMY_DATA{
	UINT32           dwEnemyPlayerID; //������ID
	UINT16           wBattleNum; //���ִ���
	UINT64           qwAddTime; //���ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ENEMY_DATA;

typedef struct tagDT_ENEMY_DATA_LIST{
	UINT8            byEnemyNum; //ս������
	DT_ENEMY_DATA    astEnemyInfo[MAX_ENEMY_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ENEMY_DATA_LIST;

typedef struct tagDT_MONEY_TREE_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT16           wRockNum; //�ϴ���ҡ����
	UINT64           qwRockTime; //�ϴ�ҡ��ʱ��
	UINT8            byMoodValue; //�ϴ�����ֵ
	UINT64           qwMoodStartTime; //�ϴ�����ֵ��ʼʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MONEY_TREE_DATA;

typedef struct tagDT_INSTANCE_BATTLE_DATA{
	DT_INSTANCE_ID   stInstanceID; //�������
	UINT8            byBattleIndex; //ս�����
	UINT64           qwBattleTime; //�ϴ�ս��ʱ��
	UINT16           wMaxRounds; //��󹥻��غ���
	UINT16           wMaxPercentageHp; //���ʣ��Ѫ���ٷֱ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_INSTANCE_BATTLE_DATA;

typedef struct tagDT_PHYSTRENGTH_DATA{
	UINT64           qwLastPhyStrengthRefreshTime; //�ϴ�����ˢ��ʱ��
	UINT64           qwLastBuyPhyStrengthTime; //�ϴι�������ʱ��
	UINT16           wLastBuyPhyStrengthNum; //�ϴι�����������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PHYSTRENGTH_DATA;

typedef struct tagDT_ONHOOK_RESULT{
	UINT8            byCurRunTimes; //��ǰɨ������
	UINT8            byAllRunTimes; //�ܹ�ɨ������
	UINT32           dwStory; //����
	UINT32           dwExperience; //��������
	UINT32           dwCoin; //ͭǮ
	UINT32           dwGold; //Ԫ��
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA     astItemInfoList[MAX_ENCOURAGE_ITEM_KIND_NUM]; //������Ϣ
	UINT32           dwBlueGas; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ONHOOK_RESULT;

typedef struct tagDT_ONHOOK_RCD_DATA{
	UINT8            byOnhookFlag; //�Ƿ�һ���
	DT_ONHOOK_RESULT stOnhookResult; //�һ������¼
	DT_INSTANCE_ID   stOnhookInstanceID; //�һ�����,wSceneIdxΪ0��ʾû�йһ�
	UINT64           qwLastOnhookResultReqTime; //�ϴ�����һ����ʱ��
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ONHOOK_RCD_DATA;

typedef struct tagDT_FEW_PARAM_DATA{
	UINT64           qwLastStrengthenTime; //�ϴ�ǿ��ʱ��
	UINT16           wLastStrengthenCD; //�ϴ�ǿ���ۼ�CD
	UINT64           qwLastRefreshEliteTime; //�ϴ�ˢ�¾�Ӣ����ʱ��
	UINT16           wLastRefreshEliteNum; //�ϴ�ˢ�¾�Ӣ��������
	UINT64           qwCountTime; //�ϴ�ͳ��ˢ��ʱ��
	UINT16           wGVETimes; //��������ͨ�ش���
	UINT16           wRaceSuccess; //�������ɹ�����
	UINT16           wRaceFailed; //������ʧ�ܴ���
	UINT16           wTrialSuccess; //�������ɹ�����
	UINT16           wTrialFailed; //������ʧ�ܴ���
	UINT16           wInterceptSuccess; //����ȡ�����سɹ�����
	UINT16           wInterceptFailed; //����ȡ������ʧ�ܴ���
	UINT16           wAwakenNum; //�����������
	UINT16           wResetTowerNum; //��������
	UINT16           wWorldPassNum; //�˼�ͨ�ش���
	UINT16           wHellPassNum; //����ͨ�ش���
	UINT16           wHeavenPassNum; //����ͨ�ش���
	UINT16           wXiJingHorse; //������
	UINT16           wXiJingThird; //ɳɮ
	UINT16           wXiJingSecond; //��˽�
	UINT16           wXiJingFirst; //��ʦ��
	UINT16           wXiJingMaster; //ʦ��
	UINT16           wExperienceDrug; //3�����鵤
	UINT16           wPassNaiDanNum; //ͨ��ն�޴���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FEW_PARAM_DATA;

typedef struct tagDT_CROP_INFO_DATA{
	UINT8            byOpen; //��ֲID
	UINT16           wCropKindID; //��ֲID
	UINT64           qwLastCropTime; //��ֲʱ��
	UINT8            byFieldLevel; //��صȼ�
	UINT32           dwSeedNum; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CROP_INFO_DATA;

typedef struct tagDT_CROP_DATA{
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_CROP_INFO_DATA astCropInfoList[MAX_CROP_NUM]; //��ֲ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CROP_DATA;

typedef struct tagDT_SCIENCE_TREE_DATA{
	UINT16           wAttractLevel; //����
	UINT16           wHPLevel; //����
	UINT16           wCritLevel; //����
	UINT16           wShieldLevel; //����
	UINT16           wHitLevel; //ӥ��
	UINT16           wDodgeLevel; //����
	UINT32           dwFirstAttack; //�ȹ�
	UINT16           wCoachTalent; //��������
	UINT16           wAttractLevel2; //����2
	UINT16           wHPLevel2; //����2
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	UINT16           wQingLogLevel; //������
	UINT16           wBaiHuLevel; //�׻���
	UINT16           wZhuQueLevel; //��ȸ��
	UINT16           wXuanWuLevel; //������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SCIENCE_TREE_DATA;

typedef struct tagDT_FORMATION_HERO_DATA{
	UINT8            byFormationIdx; //����λ��(��1��ʼ��1��6)
	UINT16           wHeroID; //�佫ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FORMATION_HERO_DATA;

typedef struct tagDT_FORMATION_IDX_DATA{
	UINT8            byFormationKind; //��������
	UINT8            byOpenIdxNum; //���Ϳ���λ����
	DT_FORMATION_HERO_DATA astOpenIdxInfo[MAX_FORMATION_IDX_NUM]; //���Ϳ���λ����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FORMATION_IDX_DATA;

typedef struct tagDT_FORMATION_DATA_LIST{
	UINT8            byFormationKindNum; //����������
	DT_FORMATION_IDX_DATA astFormationInfo[MAX_FORMATION_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FORMATION_DATA_LIST;

typedef struct tagDT_FORMATION_DATA{
	UINT8            bySelectIdx; //��ѡ������ţ���0��ʼ��
	DT_FORMATION_DATA_LIST stFormationList; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FORMATION_DATA;

typedef struct tagDT_NEW_FORMATION_POSTION_INFO{
	UINT8            byPostionIndex; //λ�����
	UINT16           wHeroID; //HeroID
	UINT8            byIsUnlock; //����״̬��0δ����, 1������
	UINT8            byNeedLevel; //������Ҫ�ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NEW_FORMATION_POSTION_INFO;

typedef struct tagDT_NEW_FORMATION_INFO{
	UINT8            byFormationID; //����ID
	UINT8            byPostionNum; //λ�ø���
	DT_NEW_FORMATION_POSTION_INFO astPostionInfo[MAX_FORMATION_IDX_NUM]; //λ����Ϣ
	UINT8            byFormationLevel; //���͵ȼ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NEW_FORMATION_INFO;

typedef struct tagDT_NEW_FORMATION_DATA_LST{
	UINT8            byFormationNum; //���͸���
	DT_NEW_FORMATION_INFO astFormationArray[MAX_NEW_FORMATION_NUM]; //����������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NEW_FORMATION_DATA_LST;

typedef struct tagDT_NEW_FORMATION_DATA{
	UINT8            bySelectIdx; //��ѡ������ţ���0��ʼ��
	DT_FORMATION_DATA_LIST stFormationList; //������Ϣ
	UINT8            byNewSelectIdx; //��ѡ���������
	DT_NEW_FORMATION_DATA_LST stNewFormationLst; //��������Ϣ����0��ʼ��
	DT_NEW_FORMATION_DATA_LST stLockFormationLst; //δ��������
	UINT8            byIsUseNewFormation; //�Ƿ�ʹ�������ͣ�1Ϊ�Ѿ�ʹ�ã�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NEW_FORMATION_DATA;

typedef struct tagDT_VERSION_DATA{
	UINT32           dwVersionID; //�汾ID,ȡ2λС����(/100)
	UINT8            byForceUpdateFlag; //�Ƿ�ǿ�Ƹ��£�1ǿ�Ƹ���
	TCHAR            aszUpdateContent[MAX_CONTENT_SIZE]; //��������
	TCHAR            aszUpdateURL[MAX_CONTENT_SIZE]; //���µ�ַ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_VERSION_DATA;

typedef struct tagDT_NOTICE_DATA{
	UINT32           dwNoticeID; //����ID
	UINT8            byForcePopFlag; //�Ƿ���뵯,1Ϊ���뵯��
	UINT8            byUrlFlag; //����Ϊurl��־
	TCHAR            aszNoticeContent[MAX_CONTENT_SIZE]; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NOTICE_DATA;

typedef struct tagDT_NOTICE_DATA_DB{
	UINT32           dwNoticeID; //����ID
	UINT8            byForcePopFlag; //�Ƿ���뵯,1Ϊ���뵯��
	UINT8            byUrlFlag; //����Ϊurl��־
	TCHAR            aszNoticeContent[MAX_NOTICE_CONTENT_LEN]; //��������
	UINT64           qwExpiresTime; //����ʱ��
	UINT32           dwBeginChannelID; //��ʼ����ID
	UINT32           dwEndChannelID; //��������ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NOTICE_DATA_DB;

typedef struct tagDT_NOTICE_DATA_NEW{
	UINT32           dwNoticeID; //����ID
	UINT8            byForcePopFlag; //�Ƿ���뵯,1Ϊ���뵯��
	UINT8            byUrlFlag; //����Ϊurl��־
	TCHAR            aszNoticeContent[MAX_NOTICE_CONTENT_LEN]; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NOTICE_DATA_NEW;

typedef struct tagDT_EAT_BREAD_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT64           qwEnterTime; //����ʱ�䣬0��ʾû��
	UINT8            byHaveObtainPhyStrengthen; //�ѵõ�������(�ӻ��ʼ����ǰ)
	UINT32           dwHaveObtainCoin; //�ѵõ���ͭǮ(�ӻ��ʼ����ǰ)
	UINT8            byHaveLeaveFlag; //�Ƿ����뿪
	UINT16           wHaveUseTime; //����ʱ��
	UINT8            byHaveGivePhyStrengthen; //�ѽ��������
	UINT32           dwHaveGiveCoin; //�ѽ����ͭǮ
	UINT8            byNotity; //�Ƿ��֪ͨ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EAT_BREAD_DATA;

typedef struct tagDT_YABIAO_BASE_DATA{
	UINT64           qwLastYabiaoTime; //�ϴο�ʼѺ�ڵ�ʱ�䣨���������ж��Ƿ������ˢ���ˣ�
	UINT8            byAlreadyYabiaoCount; //�Ѿ�Ѻ�ڵĴ���
	UINT8            byQuality; //�ڵ�Ʒ��
	UINT8            byBeJiebiaoCount; //�����ڵĴ���
	UINT16           wBiaoRunTime; //�����ܵ�ʱ��(��Ϊ��λ)
	UINT16           wBiaoFlushCount; //��ǰ���Ѿ�ˢ�Ĵ���
	UINT8            byYabiaoFlag; //��ǰѺ��״̬(0����Ѻ�ڣ�1��Ѻ�ڣ�2Ѻ�����)
	UINT8            byAlreadyJiebiaoCount; //�Ѿ����ڴ���
	UINT64           qwLastJiebiaoTime; //�ϴν���ʱ��
	UINT64           qwLastEncourageCoin; //�ϴ�Ѻ�ڵ�ͭǮ����
	UINT64           qwLastEncourageScience; //�ϴ�Ѻ�ڵ����꽱��
	UINT64           qwBeJiebiaoTime; //�����ڵ�ʱ��
	UINT64           qwLastEncourageJingjie; //�ڵľ��罱��
	UINT32           dwJiebiaoDecCoin; //���ڶ�ʧ�Ľ�Ǯ
	UINT32           dwJiebiaoDecScience; //���ڶ�ʧ������
	UINT32           dwAlreadyFlushBiaoCnt; //��ˢ���ڵ��ܴ���
	UINT64           qwLastFlushTime; //�ϴ�ˢ���ڵ�ʱ��
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_YABIAO_BASE_DATA;

typedef struct tagDT_YABIAO_BATTLELOG_DATA{
	UINT8            byFlag; //���ڱ�־,0Ϊ�������ڣ�1Ϊ������, 2ΪѺ�ڳɹ�
	UINT64           qwBattleTime; //ս��ʱ��
	UINT32           dwEnemyPlayerID; //�Է����ID
	UINT8            byResult; //�����0Ϊ�ҷ�Ӯ��1Ϊ�Է�Ӯ
	UINT32           dwCoinChange; //��û�����ʧͭǮ�������ڱ�־��
	UINT32           dwScienceChange; //��û�����ʧ���꣨�����ڱ�־��
	UINT8            byNewFlag; //�Ƿ���ս����1Ϊ��
	UINT64           qwBattleDataIndex; //ս������
	UINT8            byQuality; //�ڵ�Ʒ��
	UINT32           dwJingjieChange; //��û�����ʧ����㣨�����ڱ�־��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_YABIAO_BATTLELOG_DATA;

typedef struct tagDT_YABIAO_BATTLELOG_DATA_LIST{
	UINT8            byBattleLogNum; //ս������
	DT_YABIAO_BATTLELOG_DATA astPaoshangBattleLogInfo[MAX_YABIAO_BATTLELOG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_YABIAO_BATTLELOG_DATA_LIST;

typedef struct tagDT_SKILL_ACTION_DATA{
	UINT16           wID; //ID
	UINT16           wLevel; //�ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SKILL_ACTION_DATA;

typedef struct tagDT_SKILL_ACTION_DATA_LIST{
	UINT8            byActionNum; //������ʽ����
	DT_SKILL_ACTION_DATA astActionInfo[MAX_SKILL_SLOT_NUM]; //������ʽ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SKILL_ACTION_DATA_LIST;

typedef struct tagDT_JINGJIE_BASE_DATA{
	UINT8            byCareerID; //ְҵ
	UINT16           wLevel; //�ȼ�
	UINT16           wSubLevel; //�ӵȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_JINGJIE_BASE_DATA;

typedef struct tagDT_GAS_BALL_DATA{
	UINT8            byKind; //����������
	UINT8            byLevel; //����������
	UINT32           dwGasValue; //����ֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GAS_BALL_DATA;

typedef struct tagDT_COLLECT_GAS_DATA{
	UINT8            byCollectState; //�ռ�״̬,0���ɣ�1��ȡ
	DT_GAS_BALL_DATA astGasBollInfo[MAX_GAS_BALL_NUM]; //��������Ϣ
	UINT16           wLastCoinGenNum; //�ϴ�ͭǮ��������
	UINT64           qwLastCoinGenTime; //�ϴ�ͭǮ����ʱ��
	UINT16           wLastCoinRandomUpNum; //�ϴ�ͭǮ�����������
	UINT64           qwLastCoinRandomUpTime; //�ϴ�ͭǮ�������ʱ��
	UINT8            byLastCoinFullNum; //�ϴ�ͭǮһ���ɳ�����
	UINT64           qwLastCoinFullTime; //�ϴ�ͭǮһ���ɳ�ʱ��
	UINT16           wLastGoldGenNum; //�ϴ�Ԫ����������
	UINT64           qwLastGoldGenTime; //�ϴ�Ԫ������ʱ��
	UINT16           wLastGoldRandomUpNum; //�ϴ�Ԫ�������������
	UINT64           qwLastGoldRandomUpTime; //�ϴ�Ԫ���������ʱ��
	UINT8            byLastGoldFullUpNum; //�ϴ�Ԫ��һ���ɳ�����
	UINT64           qwLastGoldFullUpTime; //�ϴ�Ԫ��һ���ɳ�ʱ��
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COLLECT_GAS_DATA;

typedef struct tagDT_JINGJIE_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	DT_JINGJIE_BASE_DATA stBaseData; //���������Ϣ
	DT_COLLECT_GAS_DATA stCollectData; //�����ռ���Ϣ
	DT_SKILL_ACTION_DATA_LIST stSkillActionData; //������ʽ��Ϣ�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_JINGJIE_DATA;

typedef struct tagDT_CLIMB_TOWER_DATA{
	UINT16           wResetClimbTownNum; //�����ô���
	UINT64           qwResetClimbTownTime; //�������ʱ��
	UINT16           wBuyResetClimbTownNum; //ÿ��ɹ������
	UINT64           qwBuyResetClimbTownTime; //ÿ�������ʱ��
	UINT8            byClimbTownInstance; //�����Ҳ���
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CLIMB_TOWER_DATA;

typedef struct tagDT_ELITE_INSTANCE_RESET_DATA{
	UINT16           wResetEliteInstanceNum; //���þ�Ӣ��������
	UINT64           qwLastResetEliteInstanceTime; //�ϴ����þ�Ӣ������ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ELITE_INSTANCE_RESET_DATA;

typedef struct tagDT_VIP_GET_NUM_EACH_DATA{
	UINT16           wVipHaveNum; //ÿһVIP�ȼ���Ӧ�Ŀ���ȡ�Ĵ���
	UINT16           wVipGetNum; //ÿһVIP�ȼ���Ӧ������ȡ�Ĵ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_VIP_GET_NUM_EACH_DATA;

typedef struct tagDT_VIP_GET_NUM_LEVEL_DATA{
	UINT16           wMaxVipGift; //ÿһVIP�ȼ���Ӧ�Ŀ���ȡ�Ĵ���
	DT_VIP_GET_NUM_EACH_DATA astVipGetNum[MAX_VIP_GIFT]; //ÿһVIP�ȼ���Ӧ������ȡ�Ĵ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_VIP_GET_NUM_LEVEL_DATA;

typedef struct tagDT_VIP_EXT_DATA{
	UINT16           wEatGoldExperienceCnt; //������Ԫ�����鵤����
	UINT64           qwLastEatTime; //�ϴη���Ԫ�����鵤��ʱ��
	UINT16           wEliteInstanceTownNum; //��Ӣ����������
	DT_ELITE_INSTANCE_RESET_DATA astEliteInstanceData[MAX_ELITE_INSTANCE_TOWN_NUM]; //��Ӣ������������
	UINT64           qwLastGetTime; //���һ����ȡ�����ʱ��
	UINT8            byVipMaxLevel; //VIP���ȼ�
	DT_VIP_GET_NUM_LEVEL_DATA astVipGiftNumByLevel[MAX_VIP_LEVEL]; //ÿһVIP�ȼ���Ӧ�Ŀ���ȡ�Ĵ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_VIP_EXT_DATA;

typedef struct tagDT_LUAACTIVITY_RECORD_DATA{
	UINT32           dwID; //ID
	UINT16           wFinishNum; //��ɴ���
	UINT64           qwFinishTime; //�ϴ����ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LUAACTIVITY_RECORD_DATA;

typedef struct tagDT_LUAACTIVITY_RECORD_LIST_DATA{
	UINT8            byRecordNum; //��¼��
	DT_LUAACTIVITY_RECORD_DATA astHaveFinishActivityInfo[MAX_LUAACTIVITY_RECORD_NUM]; //����ɻID��¼��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LUAACTIVITY_RECORD_LIST_DATA;

typedef struct tagDT_BOSSB_HURT_RATE{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT32           dwHurtValue; //��Ҷ�Boss���˺�(���˺�֪ͨΪ��ʱ�����˺�ֵ)
	UINT32           dwHurtRate; //��Ҷ�Boss���˺���������ֱȣ�
	UINT32           dwHurtRank; //��Ҷ�Boss���˺�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSSB_HURT_RATE;

typedef struct tagDT_BOSS_BATTLE_ENC_DATA{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT32           dwCoin; //ͭǮ
	UINT32           dwJingJie; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_ENC_DATA;

typedef struct tagDT_BOSS_BATTLE_PLAYER_DATA{
	UINT64           qwLastEnterActivityTime; //�ϴν���ʱ��
	UINT64           qwLastLeaveActivityTime; //�ϴ��뿪�ʱ��
	UINT16           wIncPowerRate; //����ս���ٷֱ�
	UINT32           dwTotalHurtValue; //�Ѿ���ɵ��˺�ֵ
	UINT32           dwHurtRank; //��Ҷ�Boss���˺�����
	UINT32           dwEncCoin; //�˺�ͭǮ
	UINT32           dwEncJingJie; //�˺�����
	UINT16           wPosX; //λ����ϢX
	UINT16           wPosY; //λ����ϢY
	UINT32           dwSyncStartIdx; //ͬ������ʼIdx
	UINT8            byLastReliveType; //�ϴθ��ʽ��0��ͨ���1Ԫ������
	UINT64           qwLastReliveTime; //�ϴθ���ʱ��
	UINT64           qwLastDeadTime; //�ϴ�����ʱ��
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�������˺�
	DT_BOSS_BATTLE_ENC_DATA stHurtEncInfo; //�˺�������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stHeroEncInfo; //Ӣ�۽�����Ϣ
	UINT8            byUnreadBattleLogNum; //δ�ۿ�ս������
	UINT8            byNotity; //�Ƿ��֪ͨ
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT64           qwLastKillBossTime; //�ϴλ�ɱBOSSʱ��
	UINT64           qwBossHurtTime; //�ϴ��˺�����1%ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_PLAYER_DATA;

typedef struct tagDT_BOSS_BATTLE_DATA{
	UINT64           qwOverTime; //�����ʱ��
	UINT64           qwStartTime; //���ʼʱ��
	UINT64           qwSaveTime; //��������ʱ��
	UINT8            byActivityID; //�ID
	UINT16           wBossID; //BOSSID
	UINT16           wLastLevel; //�ϴεĵȼ�
	UINT8            byNeedUpgrade; //�Ƿ�������
	UINT32           dwTotalHP; //BOSS��Ѫ��
	UINT32           dwCurHP; //BOSS��ʱѪ��
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	DT_BOSS_BATTLE_ENC_DATA astBossBTopEncInfo[MAX_BOSS_ENC_TOP_NUM]; //top������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stBossBKillEncInfo; //���1��������Ϣ
	UINT64           qwTotalHP; //BOSS��Ѫ��
	UINT64           qwCurHP; //BOSS��ʱѪ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_DATA;

typedef struct tagDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA{
	UINT64           qwOverTime; //�����ʱ��
	UINT8            byActivityID; //�ID
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�������˺�
	DT_BOSS_BATTLE_ENC_DATA stHurtEncInfo; //�˺�������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stHeroEncInfo; //Ӣ�۽�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA;

typedef struct tagDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST{
	UINT8            byNum; //ս������
	DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA astBossBattleBL[MAX_BOSSB_BATTLE_LOG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST;

typedef struct tagDT_BOSS_BATTLE_MODULE_DATA{
	UINT8            byNum; //����
	DT_BOSS_BATTLE_DATA astBossBattleInfo[MAX_BOSSB_NUM_PER_DAY]; //��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_MODULE_DATA;

typedef struct tagDT_ACTIVITY_ENCOURAGE_INFO{
	UINT32           dwActivityID; //����ID
	UINT64           qwActivityTime; //��ȡ����ʱ��
	UINT8            byActivityTimes; //��ȡ��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ACTIVITY_ENCOURAGE_INFO;

typedef struct tagDT_ACTIVITY_ENCOURAGE_INFO2{
	UINT64           qwActivityID; //����ID
	UINT64           qwActivityTime; //��ȡ����ʱ��
	UINT8            byActivityTimes; //��ȡ��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ACTIVITY_ENCOURAGE_INFO2;

typedef struct tagDT_ACTIVITY_ENCOURAGE_DATA{
	UINT8            byRechargeFlag; //��ֵ������־
	UINT64           qwRechargeRecvTime; //��ȡ��ֵ����ʱ��
	UINT8            byScoreFlag; //���ֽ�����־
	UINT64           qwScoreRecvTime; //��ȡ���ֽ���ʱ��
	UINT16           wInfoNumOld; //��������
	DT_ACTIVITY_ENCOURAGE_INFO astActivityInfoOld[MAX_ACTIVITY_ENCOURAGE_INFO_NUM]; //������Ϣ
	UINT16           wInfoNum; //��������
	DT_ACTIVITY_ENCOURAGE_INFO2 astActivityInfo[MAX_ACTIVITY_ENCOURAGE_INFO_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ACTIVITY_ENCOURAGE_DATA;

typedef struct tagDT_RDC_PLAYER_DATA{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT16           wMainHeroKindID; //�����ID
	UINT8            byRobotFunc; //�����˹���,>0��Ϊ�����ˣ���ͬ��ֵΪ��ͬ�Ĺ��ܡ�0Ϊ���
	UINT16           wLevel; //�ȼ�
	UINT32           dwPower; //ս��
	UINT8            byHaveChallengeFlag; //�Ƿ�����ս��1Ϊ����ս

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RDC_PLAYER_DATA;

typedef struct tagDT_RANDOM_CHALLENGE_DATA{
	UINT16           wCurChallengePoint; //��ǰ��ս��
	UINT64           qwLastRCPoinRefreshTime; //�ϴ���ս��ˢ��ʱ��
	UINT64           qwLastBuyRCPoinTime; //�ϴι�����ս��ʱ��
	UINT16           wLastBuyRCPoinNum; //�ϴι�����ս�����
	UINT64           qwLastRCTime; //�ϴ���սʱ��
	UINT8            byLastRCRet; //�ϴ���ս�����0Ӯ1��
	UINT8            byClrCDFlag; //�Ƿ������CD��1�����CD
	UINT8            byPlayerNum; //��ǰ������Ҹ���
	DT_RDC_PLAYER_DATA astPlayerInfo[MAX_GET_RDC_NUM]; //�����Ϣ
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RANDOM_CHALLENGE_DATA;

typedef struct tagDT_WORSHIP_DATA{
	UINT8            byWorshipType; //Ĥ������
	UINT8            byWorshipTypeLevel; //Ĥ�ݼ���1Ϊ��ߵȼ�
	UINT64           qwLastWorshipTime; //Ĥ��ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_WORSHIP_DATA;

typedef struct tagDT_WORSHIP_DATA_LST{
	UINT16           wNum; //����
	DT_WORSHIP_DATA  astWorshipInfo[MAX_WORSHIP_NUM]; //��Ϣ
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_WORSHIP_DATA_LST;

typedef struct tagDT_CHAPTER_SCORE_DATA{
	UINT16           wSceneidx; //����ID
	UINT16           wChapterIdx; //�½�ID
	UINT64           qwtime; //��ȡ����ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CHAPTER_SCORE_DATA;

typedef struct tagDT_ACCUMULATED_SCORE_DATA{
	UINT16           wgrade; //����ID
	UINT64           qwtime; //��ȡ����ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ACCUMULATED_SCORE_DATA;

typedef struct tagDT_SCORE_DATA_LST{
	UINT8            byChapterNum; //����
	DT_CHAPTER_SCORE_DATA astChapterData[MAX_TOWN_PER_SCENE_NUM]; //��ȡ����ʱ��
	UINT8            byAccumulatedNum; //���۸���
	DT_ACCUMULATED_SCORE_DATA astAccumulatedData[MAX_TOWN_PER_SCENE_NUM]; //��ȡ����ʱ��
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SCORE_DATA_LST;

typedef struct tagDT_EQUIP_LEVEL_COMPOSE_DATA{
	UINT16           wEquipLevel; //װ���ȼ�
	UINT8            byCurLowColor; //��ǰ�����ɫ
	UINT16           wHitKindID; //��ǰ����װ��ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EQUIP_LEVEL_COMPOSE_DATA;

typedef struct tagDT_EQUIP_COMPOSE_DATA{
	UINT8            byEquipLevelNum; //�ȼ�װ����
	DT_EQUIP_LEVEL_COMPOSE_DATA astEquipLevelInfo[MAX_EQUIPLEVEL_NUM]; //װ���ȼ��ϳ���Ϣ
	UINT64           qwLastComposeTime; //�ϴκϳ�ʱ��
	UINT16           wLastComposeEquipLevel; //�ϴκϳ�װ���ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EQUIP_COMPOSE_DATA;

typedef struct tagDT_GATHER_SCIENCE_DATA{
	UINT16           wCoinNum; //ͭǮ��ǰʹ�þۻ����
	UINT64           qwCoinLastTime; //ʹ��ͭǮʱ��
	UINT16           wGoldNum; //Ԫ����ǰʹ�þۻ����
	UINT64           qwGoldLastTime; //ʹ��Ԫ��ʱ��
	UINT8            byIncrease; //����
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GATHER_SCIENCE_DATA;

typedef struct tagDT_BEGBLUE_RES{
	UINT16           wSmileNum; //Ц������
	UINT32           dwBlueUnit; //������¶
	UINT32           dwStoryUnit; //��������
	UINT16           wXnMultiple; //����
	TCHAR            aszLuckPrompt[BEGBLUE_LUCK_PROMPT]; //������ʾ
	UINT64           qwCreateTime; //���ɵ�ʱ��
	UINT64           qwUpdateTime; //���˸��µ�ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BEGBLUE_RES;

typedef struct tagDT_CONSUME_BEGBLUE_SMILE_LST{
	UINT16           wConsumeTimes; //���ĵĴ���
	UINT16           awConsumeSmileNum[BEGBLUE_CONSUME_TIMES]; //���ĵ�Ц������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CONSUME_BEGBLUE_SMILE_LST;

typedef struct tagDT_BEGBLUE_DATA{
	UINT64           qwBegBlueLastTime; //�������¶ʱ��
	TCHAR            aszClimbTowerPrompt[BEGBLUE_CLIMB_TOWER_PROMPT]; //������ʾ
	UINT32           dwMaxBegTimes; //�����������
	UINT32           dwUsedBegTimes; //�����������
	UINT32           dwFreeImproveLuckMaxTimes; //������Ѹ��˴�������
	UINT32           dwUsedFreeImproveLuckTimes; //������Ѹ��˴���
	UINT32           dwGoldImproveLuckIdx; //�´�Ԫ���������(�´�����¶��ֵ������)
	UINT32           dwNextImproveLuckGold; //�´θ����軨�ѵ�Ԫ��
	UINT8            byIsHaveToComfirmBegBlueInfo; //�Ƿ��д�ȷ�ϵ�����¶���(0ľ�У�1��)
	DT_BEGBLUE_RES   stBegBlueRes; //����õ�����Դ
	UINT8            byIsIgnoreXnMultiple; //�Ƿ��������¶����(0�����ԣ�1����)
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	UINT16           wSmileNum; //Ц������
	DT_CONSUME_BEGBLUE_SMILE_LST stDtConsumeSmile; //������Ц��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BEGBLUE_DATA;

typedef struct tagDT_SEND_FLOWER_DATA{
	UINT32           dwSendFlowerNum; //�ͻ�������
	UINT8            byUsedSendTimes; //������ʹ�õ����ʻ�����(��Բ�ͬ���ͻ��������ͻ��������޸���ͬ)
	UINT8            byExt; //��չ�ֶ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SEND_FLOWER_DATA;

typedef struct tagDT_FINALLY_CONTACT_DATA{
	UINT32           dwPlayerID; //���ID
	UINT64           qwLastContactTime; //�����ϵʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FINALLY_CONTACT_DATA;

typedef struct tagDT_FINALLY_CONTACT_DATA_LST{
	UINT8            byFinallyContactNum; //��¼����
	DT_FINALLY_CONTACT_DATA astFinallyContactData[MAX_FINALLY_CONTACT_DATA_NUM]; //��ҹ�ϵ�б���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FINALLY_CONTACT_DATA_LST;

typedef struct tagDT_RECV_FLOWER_DATA_EX_LOG{
	UINT32           dwSendPlayerID; //�ͻ������ID
	UINT32           dwKindID; //�ʻ�ID
	UINT64           qwSendTime; //�ͻ���ʱ��
	UINT8            byFlag; //�Ƿ��Ѷ� 0����ȡ�� 1��δ��ȡ�� 2��δ��
	DT_RES_NUM_ITEM_DATA stResNumItemData; //��ȡ��Դ�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RECV_FLOWER_DATA_EX_LOG;

typedef struct tagDT_FRIENDS_BASE_DATA{
	UINT64           qwLastSendFlowerTime; //����ͻ�ʱ��
	UINT8            byElemNum; //Ԫ�ظ���
	DT_SEND_FLOWER_DATA astListData[MAX_SEND_FLOWER_DATA_NUM]; //�б���Ϣ
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_FINALLY_CONTACT_DATA_LST stFinallyContactDataList; //�����ϵ�б�
	UINT64           qwLastRecvFlowerTime; //����ջ�ʱ��
	UINT32           dwRecvFlowerTimes; //�ջ��Ĵ���
	UINT32           dwSendFlowerTimes; //�ͻ��Ĵ���
	UINT32           dwLogNum; //��¼����
	DT_RECV_FLOWER_DATA_EX_LOG astLogData[MAX_RECV_FLOWER_LOG_LIST_ELEM_EX_NUM]; //�б���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FRIENDS_BASE_DATA;

typedef struct tagDT_RAREITEM_GOODS_INFO{
	UINT16           wRareItemID; //��ƷID
	UINT32           dwRareItemHaveExchangeNum; //��Ʒ�Ѷһ�����
	UINT64           qwLastResetTime; //��Ʒ�ϴζһ�ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RAREITEM_GOODS_INFO;

typedef struct tagDT_RAREITEM_GOODS_DATA{
	UINT8            byRareItemNum; //��Ʒ����
	DT_RAREITEM_GOODS_INFO astRareItemGoodInfo[MAX_RAREITEM_RES_NUM]; //��Ʒ��Ϣ
	UINT64           qwLastUpdataTime; //�ϴθ���ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RAREITEM_GOODS_DATA;

typedef struct tagDT_GYMNASIUM_SKILL_INFO{
	UINT8            bySkillID; //����ID
	UINT8            byCurSkillLevel; //��ǰ�ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GYMNASIUM_SKILL_INFO;

typedef struct tagDT_GYMNASIUM_DATA{
	UINT8            bySkillNum; //��������
	DT_GYMNASIUM_SKILL_INFO astGymnasiumSkillInfo[MAX_GYMNASIUM_SKILL_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GYMNASIUM_DATA;

typedef struct tagDT_HUNTING_INFO{
	UINT32           dwHuntionNum; //��׽������
	UINT8            byHuntingChangeNum; //׽����������
	UINT8            byAbandomMonster; //�з���������״̬ 0û�� 1 �з�����
	UINT8            byCurMonsterType; //��ǰ���ֵ�Ʒ��
	UINT8            byGoldModeFlag; //�ƽ�ģʽ����״̬
	UINT64           qwGoldModeTime; //�ƽ�ģʽ����ʱ��
	UINT64           qwLastSyncIntegral; //�ϴ�ͬ������ʱ��
	UINT8            byIsIgnorePrompt; //�Ƿ������ʾ��Ϣ 0 ������ 1 ����
	UINT8            byMonsterNum; //�������й������
	UINT16           awMonsterGroup[MONSTER_GROUP_NUM]; //��ǰ������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HUNTING_INFO;

typedef struct tagDT_SHADE_DATA{
	DT_HUNTING_INFO  stHuntingInfo; //׽����Ϣ
	UINT64           qwLastUpdataTime; //�ϴθ���ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SHADE_DATA;

typedef struct tagDT_FACTION_HUNTING_SCHEDULE_DATA{
	UINT8            byTaskID; //����ID
	UINT8            byOpenHuntingFlag; //׽������״̬
	UINT32           dwMaxHuntingNum; //׽����������
	UINT8            byCollectiveTaskSchedule; //�����ܵ���
	UINT8            byCurCollectiveTaskSchedule; //��ǰ������
	UINT32           dwCurIntegral; //��ǰ����
	UINT32           dwMaxIntegral; //��ǰ��������
	UINT64           qwLastUpdateTime; //��ȥ����ʱ��
	UINT64           qwLastChangeScheduleTime; //�ϴλ���ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_HUNTING_SCHEDULE_DATA;

typedef struct tagDT_HOT_SPRING_TIME_DATA{
	UINT8            byGiveWineOpenState; //����״̬
	UINT64           qwGiveWineOpenTime; //����ʱ��
	UINT8            byTodayOpenNum; //���տ�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HOT_SPRING_TIME_DATA;

typedef struct tagDT_SHADE_TASK_OPEN_MARK{
	UINT8            byHuntingUnlockMark; //׽�����������ʶ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SHADE_TASK_OPEN_MARK;

typedef struct tagDT_FACTION_ICON_DATA{
	UINT8            byIcon; //ͷ��ID
	UINT8            byChangeNum; //��������
	UINT64           qwlastChangeTime; //����ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_ICON_DATA;

typedef struct tagDT_FACTION_COMMON_DATA{
	DT_FACTION_HUNTING_SCHEDULE_DATA stHuntingTaskSchedule; //׽���������
	DT_HOT_SPRING_TIME_DATA stHotSpringData; //��Ȫ״̬����
	DT_FACTION_ICON_DATA stIconData; //ͷ����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_COMMON_DATA;

typedef struct tagDT_WINE_DATA_CLI{
	UINT32           dwWineID; //�Ƶ�ID
	UINT8            byCostType; //��������
	UINT32           dwCostValue; //����ֵ
	UINT32           dwDrinkWineCD; //��CDֵ
	UINT8            byLeftDrinkNum; //�Ƶ�ʣ�����
	UINT8            byRewardID1; //����ID1
	UINT32           dwRewardValue1; //����ֵ1
	UINT8            byRewardID2; //����ID2
	UINT32           dwRewardValue2; //����ֵ2
	UINT8            byNeedVIPLevel; //VIP�ȼ�����
	UINT32           dwEachRewardValue1; //ÿ�ν���1
	UINT32           dwEachRewardValue2; //ÿ�ν���2
	UINT32           dwCountDown; //���Ƶ�ʱ
	UINT32           dwDrinkMaxTime; //�����ƴ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_WINE_DATA_CLI;

typedef struct tagDT_PLAYER_POS_INFO{
	UINT16           wPosX; //λ��X
	UINT16           wPosY; //λ��Y
	UINT8            byMoveState; //�Ƿ����ƶ� 0û���ƶ� 1 ���ƶ�
	UINT64           qwSyncTimeLast; //�ϴ�ͬ��ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_POS_INFO;

typedef struct tagDT_OVER_GIVE_WINE_REWARD{
	UINT8            byRewardID1; //����ID1
	UINT32           dwRewardValue1; //����ֵ1
	UINT8            byRewardID2; //����ID2
	UINT32           dwRewardValue2; //����ֵ2

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_OVER_GIVE_WINE_REWARD;

typedef struct tagDT_HOT_SPRING_DATA{
	UINT8            byLastDrinkWineState; //�Ƿ��о�δ�� 0û��δ���ľ�, 1��δ���ľ�
	UINT8            byDrinkWineState; //����״̬ 0δ�����ƣ� 1 ��������
	DT_WINE_DATA_CLI stWineInfo; //�Ƶ���Ϣ
	DT_PLAYER_POS_INFO stPlayerPosInfo; //���λ����Ϣ
	UINT64           qwFirstDrinkTime; //��һ������ʱ��
	UINT32           dwDrinkKeepTime; //�Ѻ�ʱ��(��)
	UINT8            byIsJoinCurActivity; //�Ƿ�μӱ��λ
	UINT8            byTodayBackTime; //�����һش���
	UINT64           qwUpgradeTime; //����ʱ��
	UINT8            byActivityStat; //����
	UINT8            byHaveOverReward; //�Ƿ��й��ڽ���
	DT_OVER_GIVE_WINE_REWARD stOverReward; //���ڽ���
	UINT8            byIsIgnorePrompt; //�Ƿ������ʾ 0������ 1����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HOT_SPRING_DATA;

typedef struct tagDT_LEAVE_FACTION_MARK{
	UINT8            byLeaveMark; //�˳���ʶ
	UINT64           qwLeaveTime; //�˳�ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LEAVE_FACTION_MARK;

typedef struct tagDT_PLAYER_DONATE_INFO{
	UINT64           qwLastCoinDoorsTributeTime; //ͭǮ�Ź�ʱ��
	UINT16           wTodaysCoinDoorsTributeTimes; //����ͭǮ�Ź�����
	UINT8            byTodaysCoinDoorsTributeEncourage; //����ͭǮ�Ź���ȡ������־
	UINT64           qwLastGoldDoorsTributeTime; //Ԫ���Ź�ʱ��
	UINT16           wTodaysGoldDoorsTributeTimes; //����Ԫ���Ź�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_DONATE_INFO;

typedef struct tagDT_PLAYER_MARK_DATA{
	UINT8            byFactionPlayerMark; //���������Ա�䶯��ʶ
	DT_LEAVE_FACTION_MARK stLeaveFactionMark; //�˳����ɱ�ʶ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_MARK_DATA;

typedef struct tagDT_PLAYER_FACTION_BATTLELOG_DATA{
	UINT8            byFactionLogType; //��־���� em_Faction_BattleLog_Type
	UINT64           qwLogTime; //����ʱ��
	UINT8            byNewFlag; //�Ƿ���δ�Ķ�0 ���Ķ� 1 δ�Ķ�
	TCHAR            aszDescMsg[NORMAL_MSG_LEN]; //��������,���߳�����ʱ�Ǳ�˭�ߣ���������ʱ����������
	UINT8            byParamNum; //��������
	UINT8            abyparamList[FACTION_LOG_LIST_MAX_NUM]; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_FACTION_BATTLELOG_DATA;

typedef struct tagDT_PLAYER_FACTION_BATTLELOG_DATA_LIST{
	UINT8            byLogNum; //ս������
	DT_PLAYER_FACTION_BATTLELOG_DATA astPlayerFactionLog[MAX_FACTION_BATTLE_LOG_NUM]; //��־��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_FACTION_BATTLELOG_DATA_LIST;

typedef struct tagDT_HOT_SPRING_EXT_DATA{
	UINT64           qwLastEnterTime; //�ϴν�����Ȫʱ��
	UINT64           qwExprienceTime; //�ۻ�ʱ��
	UINT8            byDrinkTime; //��������Ȫ����
	UINT8            byFindBackTime; //�����һ���Ȫ����
	UINT8            byEnterHotSpringType; //������Ȫ��ʽ��0�Ӻ�̨���룬 1���½��룩

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HOT_SPRING_EXT_DATA;

typedef struct tagDT_PLAYER_FACTION_DATA{
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_RAREITEM_GOODS_DATA stRareItemGoodsData; //��Ʒ����Ϣ
	DT_GYMNASIUM_DATA stGymnasiumSkillData; //������Ϣ
	DT_SHADE_DATA    stShadeData; //������Ϣ
	DT_HOT_SPRING_DATA stHotSpringData; //��Ȫ��Ϣ
	DT_PLAYER_FACTION_BATTLELOG_DATA_LIST stPlayerFactionLog; //����������־��Ϣ��¼
	DT_PLAYER_MARK_DATA stPlayerMark; //��ұ�־��Ϣ
	DT_PLAYER_DONATE_INFO stPlayerDoNate; //���ɾ�����Ϣ
	UINT32           dwFindBackDoorsTribute; //���һ��Ź�
	DT_HOT_SPRING_EXT_DATA stHotSpringExt; //��Ȫ��չ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_FACTION_DATA;

typedef struct tagDT_PLAYER_TODAY_CONSUME_DATA{
	UINT32           dwID; //���ID
	UINT64           qwUTCLastConsumeTime; //����ʱ��ʱ��
	UINT64           qwAddExperience; //����
	UINT64           qwAfterExperience; //����
	UINT16           wAddLevel; //�ȼ�
	UINT16           wAfterLevel; //�ȼ�
	UINT8            byAddVipLevel; //VIP�ȼ�
	UINT8            byAfterVipLevel; //VIP�ȼ�
	UINT64           qwAddCoin; //ͭǮ
	UINT64           qwDecCoin; //ͭǮ
	UINT64           qwAfterCoin; //ͭǮ
	UINT64           qwAddGold; //Ԫ��
	UINT64           qwDecGold; //Ԫ��
	UINT64           qwAfterGold; //Ԫ��
	UINT64           qwAddStory; //����
	UINT64           qwDecStory; //����
	UINT64           qwAfterStory; //����
	UINT16           wAddPhyStrength; //��ǰ����
	UINT16           wDecPhyStrength; //��ǰ����
	UINT16           wAfterPhyStrength; //��ǰ����
	UINT64           qwAddScience; //��ǰ�Ƽ���
	UINT64           qwDecScience; //��ǰ�Ƽ���
	UINT64           qwAfterScience; //��ǰ�Ƽ���
	UINT64           qwAddBlueGas; //����
	UINT64           qwDecBlueGas; //����
	UINT64           qwAfterBlueGas; //����
	UINT64           qwAddPurpleGas; //����
	UINT64           qwDecPurpleGas; //����
	UINT64           qwAfterPurpleGas; //����
	UINT64           qwAddJingJie; //�����
	UINT64           qwDecJingJie; //�����
	UINT64           qwAfterJingJie; //�����
	UINT64           qwAddStudyExp; //������
	UINT64           qwDecStudyExp; //������
	UINT64           qwAfterStudyExp; //������
	UINT64           qwAddMedal; //����ѫ��
	UINT64           qwDecMedal; //����ѫ��
	UINT64           qwAfterMedal; //����ѫ��
	UINT32           dwAddAmount; //��ֵԪ��
	UINT32           dwAfterAmount; //��ֵԪ��
	UINT64           qwAddTotalRMB; //��ֵ���
	UINT64           qwAfterTotalRMB; //��ֵ���
	TCHAR            aszLastConsumeTime[USERNAME_LEN]; //����ʱ��ʱ��
	UINT64           qwAddDoorsTribute; //�����Ź�
	UINT64           qwDecDoorsTribute; //�����Ź�
	UINT64           qwAfterDoorsTribute; //�����Ź�
	UINT64           qwAddRedStudyNum; //��������
	UINT64           qwAddTaijiStudyNum; //��������
	UINT64           qwBuyPhyStrengthNum; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_TODAY_CONSUME_DATA;

typedef struct tagDT_RECV_FLOWER_DATA_LOG{
	UINT32           dwSendPlayerID; //�ͻ������ID
	UINT32           dwFlowerNum; //�ʻ���
	UINT64           qwSendTime; //�ͻ���ʱ��
	UINT8            byIsRead; //�Ƿ��Ѷ� 0����ȡ�� 1��δ���� 2���Ѷ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RECV_FLOWER_DATA_LOG;

typedef struct tagDT_RECV_FLOWER_LOG_LIST{
	UINT32           dwLogNum; //��¼����
	DT_RECV_FLOWER_DATA_LOG astListData[MAX_RECV_FLOWER_LOG_LIST_ELEM_NUM]; //�б���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RECV_FLOWER_LOG_LIST;

typedef struct tagDT_RELATION_DATA{
	UINT32           dwPlayerIDB; //���ID B
	UINT8            byrelation; //��ϵ����
	UINT64           qwAddTime; //����ʱ��
	UINT8            byisRead; //��Ϣ�Ƿ��Ѷ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RELATION_DATA;

typedef struct tagDT_RELATION_DATA_LIST{
	UINT32           dwRelationNum; //��¼����
	DT_RELATION_DATA astListData[MAX_RELATION_LIST_ELEM_NUM]; //�б���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RELATION_DATA_LIST;

typedef struct tagDT_RELATION_DATA_EVEN{
	UINT32           dwPlayerIDA; //���ID
	UINT8            byisRead; //��Ϣ�Ƿ��Ѷ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RELATION_DATA_EVEN;

typedef struct tagDT_UNREAD_DATA_EVEN{
	UINT32           dwSendPid; //���ID
	UINT32           dwUnReadNum; //��Ϣ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_UNREAD_DATA_EVEN;

typedef struct tagDT_DATA_EVEN_LIST{
	UINT32           dwRelationNum; //��¼����
	DT_RELATION_DATA_EVEN astRelationEvenData[MAX_RELATION_LIST_ELEM_NUM]; //��ҹ�ϵ�б���Ϣ
	UINT32           dwUnReadNum; //δ����¼����
	DT_UNREAD_DATA_EVEN astUnReadEvenData[MAX_RELATION_LIST_ELEM_NUM]; //δ���б���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DATA_EVEN_LIST;

typedef struct tagDT_COURAGE_PLAYER_HEROID_DATA{
	UINT32           dwPlayID; //���ID
	UINT16           wHeroID; //���ID
	UINT16           wKindID; //���ְҵID
	UINT8            byBattleType; //ս������ 0������ս���� 1��Э��ս��
	UINT32           dwExperience; //��Ҿ���
	UINT16           wLevel; //��ҵȼ�
	TCHAR            aszDispPlayerName[USERNAME_LEN]; //����ǳ�
	UINT8            byCurAttackObjIdx; //����ID
	UINT32           dwUpgradeExperience; //�����������
	UINT8            byColor; //�����ɫ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_PLAYER_HEROID_DATA;

typedef struct tagDT_COURAGE_COMMON_PLAYER_BATTLE_DATA{
	UINT8            byPlayerNum; //�������
	DT_COURAGE_PLAYER_HEROID_DATA astPlayerInfo[MAX_COURAGE_MEMBER_NUM]; //�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_COMMON_PLAYER_BATTLE_DATA;

typedef struct tagDT_COURAGE_ITEM_DATA_CLI{
	UINT16           wKindID; //����
	UINT8            byGoodsMainKindID; //��Ʒ�����ͣ�ֻ����Ʒ���͵�����Ч
	UINT16           wPileNum; //������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_ITEM_DATA_CLI;

typedef struct tagDT_COURAGE_ITEM_DATA_LIST{
	UINT8            byItemNum; //���߸���
	DT_COURAGE_ITEM_DATA_CLI astItemList[MAX_BAG_OPEN_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_ITEM_DATA_LIST;

typedef struct tagDT_COURAGE_ENCOURAGE_BOX_GROUP_DATA{
	UINT32           dwCoin; //ͭǮ(��0��ת������ͭǮ)
	UINT32           dwGold; //Ԫ��(��0��ת������Ԫ��)
	UINT8            byHitItemIdx; //���е������(ͭǮ/Ԫ����0ʱ��Ч��0��ʾδ����,��1��ʼ,<=ItemNum)
	DT_COURAGE_ITEM_DATA_LIST stItemInfo; //������Ϣ
	UINT32           dwBlueGas; //����(��0��ת����������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_ENCOURAGE_BOX_GROUP_DATA;

typedef struct tagDT_COURAGE_ENCOURAGE_BOX_DATA2{
	UINT8            byGroupNum; //���������
	DT_COURAGE_ENCOURAGE_BOX_GROUP_DATA astBoxGroupInfo[MAX_GVE_ENCOURAGE_BOX_GROUP_NUM]; //��������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_ENCOURAGE_BOX_DATA2;

typedef struct tagDT_COURAGE_DATA{
	UINT64           qwLastTime; //�����ʵ�ʱ��
	UINT32           dwBuyTimes; //�������
	UINT32           dwBuyAddTimes; //�������ӵĴ���
	UINT32           dwTodayJoinTimes; //����ʣ��Ĵ���
	UINT32           dwGroupID; //��ҵ���ID
	UINT16           wGroupIndex; //������������� 0,1,2
	UINT32           dwTodayHelpTimes; //����Э���Ĵ���
	UINT32           dwGiveFreeTimes; //�����Ƿ������������������ 0:û�У�1��
	UINT32           dwTotalTimes; //�����ܹ���������
	UINT8            byNotity; //�Ƿ��֪ͨ
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT16           wAverageLevel; //����ƽ���ȼ������콱
	UINT8            byHavePass; //�Ƿ�ͨ�� 0δͨ�� 1ͨ��
	UINT8            byHaveAward; //�Ƿ���ȡ���� 0��ȡ�� 1δ��ȡ
	DT_COURAGE_COMMON_PLAYER_BATTLE_DATA stGroupPlayerInfo; //������Ϣ
	DT_INSTANCE_ID   stSceneData; //������Ϣ
	DT_BAG_JEWELRY_DATA_LST stjewelryInfoLst; //��Ʒ��Ϣ
	UINT8            bySelectGroupType; //ɸѡ������CourageGroupType��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_DATA;

typedef struct tagDT_EQUIP_MASTER_DETAIL{
	UINT8            byMasterKind; //װ�����ͷ����ս�ۡ�������սѥ��
	UINT8            byMasterRank; //��ͨ�׼�����1����2����3����4��
	UINT16           wMasterLevel; //��ͨ�ȼ�
	UINT32           dwExp; //��ǰ��ͨ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EQUIP_MASTER_DETAIL;

typedef struct tagDT_MASTER_EXP_BOOK_DETAIL{
	UINT8            byBigExpBookCnt; //�������м�����0����1����2����3����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MASTER_EXP_BOOK_DETAIL;

typedef struct tagDT_EQUIP_MASTER{
	DT_EQUIP_MASTER_DETAIL astMasterInfo[EQUIP_KIND_COUNT]; //4������װ����ͨ����
	UINT8            byCultivatePanelState; //������֮ͨ�����״̬��δ�������0���򿪵�δ�ο�1���ο���δȷ��2����EMasterBookPanelState
	DT_MASTER_EXP_BOOK_DETAIL astExpBookPanel[EQUIP_KIND_COUNT]; //������֮ͨ���������
	UINT8            byCheatTimes; //��ǧ����
	UINT8            byHaveDataFlag; //�Ƿ�����������������(0��δ������/1����������)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EQUIP_MASTER;

typedef struct tagDT_FRIENDS_DATA{
	DT_FRIENDS_BASE_DATA stFriendsBaseData; //���ѻ�������
	DT_RECV_FLOWER_LOG_LIST stRecvFlowerLogList; //�ջ���־
	DT_RELATION_DATA_LIST stRelationDataList; //��ҹ�ϵ�б�
	DT_DATA_EVEN_LIST stDataEvenList; //�¼��б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FRIENDS_DATA;

typedef struct tagDT_INSTANCE_DB_DATA{
	DT_INSTANCE_DATA_LIST stCommonInstanceData; //�����ͨ������Ϣ
	DT_INSTANCE_DATA_LIST stEliteInstanceData; //��Ҿ�Ӣ������Ϣ
	DT_INSTANCE_DATA_LIST stClimbTowerInstanceData; //�������������Ϣ
	DT_INSTANCE_BATTLE_DATA stCommonBattleRcd; //��ͨ����ս����¼
	DT_INSTANCE_BATTLE_DATA stEliteBattleRcd; //��Ӣ����ս����¼
	DT_INSTANCE_BATTLE_DATA stClimbTowerBattleRcd; //��������ս����¼
	DT_INSTANCE_DATA_LIST stOutBoundInstanceData; //�⴫������Ϣ
	DT_INSTANCE_DATA_LIST stNeiDanInstanceData; //�ڵ�������Ϣ
	DT_INSTANCE_BATTLE_DATA stNeiDanBattleRcd; //�ڵ�ս����¼

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_INSTANCE_DB_DATA;

typedef struct tagDT_RACE_DATA{
	DT_RACE_BASE_DATA stRaceBaseData; //��Ҿ�������Ϣ
	DT_RACE_BATTLELOG_DATA_LIST stRaceBattleLog; //��Ҿ�����ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_RACE_DATA;

typedef struct tagDT_PLUNDER_DATA{
	DT_PLUNDER_BASE_DATA stPlunderBaseData; //�Ӷ������Ϣ
	DT_PLUNDER_BATTLELOG_DATA_LIST stPlunderBattleLog; //�Ӷ�ս����Ϣ
	DT_CAPTURE_DATA_LIST stCaptureData; //�Ӷ��²��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLUNDER_DATA;

typedef struct tagDT_YABIAO_DATA{
	DT_YABIAO_BASE_DATA stYabiaoBaseInfo; //Ѻ����Ϣ
	DT_YABIAO_BATTLELOG_DATA_LIST stYabiaoBattleLog; //�������ս����¼

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_YABIAO_DATA;

typedef struct tagDT_BOSS_BATTLE_PLAYER_DATA_INFO{
	DT_BOSS_BATTLE_PLAYER_DATA stBossBattleData; //Bossս��Ϣ
	DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST stBossBBLData; //bossսս��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BOSS_BATTLE_PLAYER_DATA_INFO;

typedef struct tagDT_EXCHANGE_RESULT_LOG{
	UINT8            byNtfFlag; //���ͱ�־
	UINT32           dwExchangeGold; //��ֵԪ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EXCHANGE_RESULT_LOG;

typedef struct tagDT_GAMBLE_DATA{
	UINT64           qwGameID; //Ѻע����ID
	UINT32           dwSupportFactionID; //Ѻע������ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GAMBLE_DATA;

typedef struct tagDT_GVG_GIFT_REWARD_DATA{
	UINT16           wSessionID; //�ڼ���������ս
	UINT8            byGvGRound; //��ս�ִΣ�commondef.h GvGRound��
	UINT8            byBattleIdx; //��ǰ�ִ��еĵڼ���ս��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��ս��������
	UINT8            byBattleResult; //��ս�����0�䣬1ʤ����
	UINT8            byGiftID; //���ID
	UINT32           dwPlayerID; //���ID
	UINT8            byGiftType; //������ͣ�GvGiftType��
	UINT8            byRank; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_GIFT_REWARD_DATA;

typedef struct tagDT_GVG_GIFT_REWARD_LST_DATA{
	UINT8            byGiftNum; //�����
	DT_GVG_GIFT_REWARD_DATA astGiftInfo[MAX_GVG_GIFT_NUM]; //�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_GIFT_REWARD_LST_DATA;

typedef struct tagDT_GVG_GIFT_KEY_LST_DATA{
	UINT8            byGiftNum; //�����
	UINT64           aqwGiftKey[MAX_GVG_GIFT_NUM]; //���KEY

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_GIFT_KEY_LST_DATA;

typedef struct tagDT_PLAYER_GVG_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�����������������(0��δ������/1����������)
	DT_GAMBLE_DATA   astGambleLstInfo[MAX_GAMBLE_NUM]; //Ѻע��Ϣ����
	DT_GVG_GIFT_KEY_LST_DATA stGetGiftData; //����ȡ���Key(��4���ؼ������)
	UINT16           wSessionID; //�������ɿ��ս����
	UINT16           wReadLogCnt; //�����Ѷ�����ս����
	UINT8            byIsGetGamble; //��ȡѺע������ʶ��0δ��ȡ�� 1����ȡ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_GVG_DATA;

typedef struct tagDT_GVG_FORMATION_DATA{
	UINT8            byPlayerNum; //��������
	UINT32           adwPlayerIDList[MAX_GVG_FORMATION_PLAYER_CNT]; //��ս��־

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FORMATION_DATA;

typedef struct tagDT_FACTION_BASE_DATA_CLI2{
	UINT32           dwFactionID; //����ID
	UINT8            byIconID; //����ͷ��ID
	TCHAR            aszHeadName[USERNAME_LEN]; //��������
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT16           wCurPlayerNum; //���ɵ�ǰ����
	UINT16           wMaxPlayerNum; //������������
	UINT32           dwFactionRank; //��������(�ȼ����ۻ��ʽ�����)
	UINT32           dwFactionLevel; //���ɵȼ�
	UINT32           dwFactionFunds; //����ʣ���ʽ�
	UINT64           qwFactionFundsSum; //�����ۻ��ʽ�
	TCHAR            aszFactionAnnouncement[MAX_FACTION_DESC_NUM]; //���ɹ���
	TCHAR            aszZoneName[ZONENAME_LEN]; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_BASE_DATA_CLI2;

typedef struct tagDT_GAMBLE_FACTION_INFO{
	DT_FACTION_BASE_DATA_CLI2 stFactionInfo; //������Ϣ
	UINT16           wZoneID; //������ID
	UINT8            byIsWin; //�Ƿ��ʤ 0�䣬 1Ӯ
	UINT8            byIsGamble; //�Ƿ�Ѻע0δѺע�� 1Ѻע

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GAMBLE_FACTION_INFO;

typedef struct tagDT_GVG_ROUND{
	UINT8            byBigRound; //����ս�������Ĵ��ִΣ��� GvGRound
	UINT8            bySmallRound; //���ִ��еĵ�С�ִ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_ROUND;

typedef struct tagDT_FACTION_GVG_SINGLE_LOG{
	DT_GVG_ROUND     stRound; //�ִ���Ϣ
	UINT64           qwVideoID; //¼��ID
	UINT8            byResult; //ս�����:���� GvGLogResult
	UINT16           wScore; //���֣�Ϊ0ʱ����ʾ
	DT_GAMBLE_FACTION_INFO stG1; //����1
	DT_GAMBLE_FACTION_INFO stG2; //����2

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_GVG_SINGLE_LOG;

typedef struct tagDT_FACTION_SIMPLE_GVG_LOG{
	UINT32           dwFactionID1; //�������ID
	UINT32           dwFactionID2; //�ұ�����ID
	DT_GVG_ROUND     stRound; //�ִ���Ϣ
	UINT64           qwVideoID; //¼��ID
	UINT8            byLogResult; //ս�������δ��ʼ��Ӯ���䣬�� GvGLogResult
	UINT8            byGvGResult; //ս�������δ��ʼ���������Ӯ���ұ�����Ӯ���� GvGResult
	UINT16           wAddScore; //��û��֣�Ϊ0ʱ����ʾ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_SIMPLE_GVG_LOG;

typedef struct tagDT_FACTION_GVG_LOG_LIST{
	UINT16           wLogCnt; //ս����¼��
	DT_FACTION_GVG_SINGLE_LOG astLogs[MAX_GVG_LOG_CNT]; //ս����¼�б�
	UINT16           wSessionID; //��ǰ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_GVG_LOG_LIST;

typedef struct tagDT_FACTION_SIMPLE_GVG_LOG_LIST{
	UINT32           dwFactionID; //����ID
	UINT16           wLogCnt; //ս����¼��
	DT_FACTION_SIMPLE_GVG_LOG astLogs[MAX_GVG_SIMPLE_LOG_CNT]; //ս����¼�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_SIMPLE_GVG_LOG_LIST;

typedef struct tagDT_FACTION_LIST_SIMPLE_GVG_LOG{
	UINT16           wFactionCnt; //ս����¼��
	DT_FACTION_SIMPLE_GVG_LOG_LIST astLogList[MAX_GVG_ARENA_FACTION_CNT]; //ս����¼�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_LIST_SIMPLE_GVG_LOG;

typedef struct tagDT_GVG_LOG_FACTION_INFO{
	UINT32           dwFactionID; //����ID
	UINT16           wFactionIconID; //����ͼ��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	TCHAR            aszHeadName[USERNAME_LEN]; //��������
	UINT32           dwScore; //����
	UINT16           wFactionLevel; //���ɵȼ�
	UINT64           qwSumPower; //��ս��
	UINT16           wJoinNum; //��ս����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_LOG_FACTION_INFO;

typedef struct tagDT_FACTION_GVG_LOG{
	DT_GVG_LOG_FACTION_INFO stFlag; //����ս������ߵ�ս��
	DT_FACTION_GVG_LOG_LIST stLogList; //ս����¼

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_GVG_LOG;

typedef struct tagDT_FACTION_GVG_DATA{
	DT_FACTION_GVG_LOG_LIST stGvGLogList; //����ս��
	DT_GVG_FORMATION_DATA stGvGFormation; //���ɲ�����Ϣ
	UINT64           qwGVGFactionFunds; //GVG�ۻ��ʽ�
	UINT64           qwSumPower; //������ս��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_GVG_DATA;

typedef struct tagDT_GVG_FORMATION_PLAYER_INFO{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszPlayerName[USERNAME_LEN]; //�������
	UINT8            byPlayerJob; //���ְλ����commondef.h�� em_Faction_Job
	UINT8            byKillCombo; //��ն��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FORMATION_PLAYER_INFO;

typedef struct tagDT_GVG_FORMATION_PLAYER_LIST{
	UINT8            byPlayerCnt; //�������
	DT_GVG_FORMATION_PLAYER_INFO astPlayerList[MAX_GVG_FORMATION_PLAYER_CNT]; //�����ְλ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FORMATION_PLAYER_LIST;

typedef struct tagDT_DOORSTRIBUTE_LEVEL_DATA{
	UINT8            byCrownNum; //�ʹڸ���
	UINT8            bySunNum; //̫������
	UINT8            byMoonNum; //��������
	UINT8            byStarNum; //���Ǹ���
	UINT32           dwNextUpgradeNeed; //��һ�����������ۻ��Ź�
	UINT16           wDoorsTributeLevel; //�Ź��ȼ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DOORSTRIBUTE_LEVEL_DATA;

typedef struct tagDT_DOORSTRIBUTE_LEVE_DATA_LST{
	UINT16           wDoorsTributeNum; //���׶ȸ���
	DT_DOORSTRIBUTE_LEVEL_DATA astDoorsTributeInfo[DT_FACTION_PLAYER_NUM]; //���׶���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DOORSTRIBUTE_LEVE_DATA_LST;

typedef struct tagDT_FACTION_MEMBER_INFO{
	UINT32           dwPlayerID; //��Ա����
	UINT16           wHeroKindID; //���佫����
	TCHAR            aszPlayerName[USERNAME_LEN]; //��Ա����
	UINT16           wPlayerLevel; //���ְλ����commondef.h�� em_Faction_Job
	UINT8            byPlayerJob; //���ְ��
	UINT32           dwPower; //���ս��
	UINT32           dwRank; //����������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_MEMBER_INFO;

typedef struct tagDT_FACTION_MEMBER_INFO_LIST{
	UINT8            byMemberCnt; //�������
	DT_FACTION_MEMBER_INFO astMembers[DT_FACTION_PLAYER_NUM]; //�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_MEMBER_INFO_LIST;

typedef struct tagDT_GVG_FACTION{
	UINT16           wZoneID; //��ID
	DT_FACTION_BASE_DATA_CLI2 stBaseData; //���ɻ�����Ϣ
	UINT8            byJoinCnt; //��ս����
	UINT64           qwSumPower; //��սս��
	UINT16           wScore; //��ǰ����
	UINT32           dwGambleCnt; //Ѻע����
	UINT8            byWinCnt; //��ǰʤ������
	UINT8            byLoseCnt; //��ǰʧ�ܳ���
	UINT16           wOriZoneID; //�����ɺ���ǰ���ڵ���
	DT_FACTION_MEMBER_INFO_LIST stMembers; //���ɳ�Ա��Ϣ�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FACTION;

typedef struct tagDT_PK_FACTION{
	DT_GVG_FACTION   stBaseData; //���ɻ�����Ϣ
	DT_GVG_FORMATION_DATA stFormation; //���ɲ���
	DT_GVG_FORMATION_PLAYER_LIST stPlayerList; //��ս��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PK_FACTION;

typedef struct tagDT_PVP_VIDEO_DATA{
	UINT32           dwVideoID; //¼��ID
	UINT64           qwVideoTime; //¼��ʱ��
	DT_BATTLE_DATA3  stPvPVideo; //¼������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PVP_VIDEO_DATA;

typedef struct tagDT_GVG_MVP{
	UINT8            byFactionIconID; //����ͼ��ID
	TCHAR            aszPlayerName[USERNAME_LEN]; //MVP���
	UINT8            byKillCombo; //��ն��
	UINT8            byScore; //���ֹ���
	UINT32           dwAward; //����
	UINT8            byWinOrLose; //ս�������1ʤ/0��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_MVP;

typedef struct tagDT_GVG_MVP_LIST{
	UINT8            byMVPCnt; //MVP����
	DT_GVG_MVP       astMVPList[MAX_GVG_MVP_CNT]; //MVP�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_MVP_LIST;

typedef struct tagDT_GVG_VIDEO_FACTION{
	UINT16           wZoneID; //���������ڵ�����
	UINT32           dwFactionID; //����ID
	UINT8            byFactionIconID; //����ͼ��ID
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	DT_GVG_FORMATION_PLAYER_LIST stPlayerList; //��������������б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_VIDEO_FACTION;

typedef struct tagDT_GVG_PK_VIDEO{
	UINT8            byPlayerIdx1; //���1������1�еڼ����ϳ���
	UINT8            byPlayerIdx2; //���2������2�еڼ����ϳ���
	UINT8            byKillCombo1; //���1��ն��
	UINT8            byKillCombo2; //���2��ն��
	DT_EMPTY_HP_VIDEO stPKVideo; //���PK¼��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_PK_VIDEO;

typedef struct tagDT_GVG_PK_VIDEO_LIST{
	UINT8            byPKVideoCnt; //pk����
	DT_GVG_PK_VIDEO  astPKVideoList[MAX_GVG_PK_VIDEO_CNT]; //�����ɼ�����pk¼��ID�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_PK_VIDEO_LIST;

typedef struct tagDT_GVG_VIDEO{
	UINT64           qwVideoID; //¼��ID
	UINT64           qwTime; //¼��ʱ��
	DT_GVG_ROUND     stRound; //�ִ���Ϣ
	DT_GVG_VIDEO_FACTION stG1; //����1��Ϣ
	DT_GVG_VIDEO_FACTION stG2; //����2��Ϣ
	DT_FINAL_ROUND_BATTLE_OBJ_INFO stFinalRoundInfo; //���һ�ֵ������Ϣ
	UINT8            byBattleResult; //ս�������δ��ʼ���������Ӯ���ұ�����Ӯ���� GvGResult
	UINT8            byPKVideoCnt; //pk����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_VIDEO;

typedef struct tagDT_GVG_ZONE_MEMBER_DATA{
	UINT8            byZoneCnt; //������
	UINT32           adwZoneIDList[MAX_GVG_ARENA_ZONE_CNT]; //��ID�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_ZONE_MEMBER_DATA;

typedef struct tagDT_ZONE_FACTION_ID{
	UINT32           dwZoneID; //�����������ĸ���
	UINT32           dwFactionID; //����ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ZONE_FACTION_ID;

typedef struct tagDT_DIFF_ZONE_FACTION_ID_LIST{
	UINT8            byFactionCnt; //�ж��ٸ�����
	DT_ZONE_FACTION_ID astFactionList[GVG_16_TO_8_FACTION_CNT]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_DIFF_ZONE_FACTION_ID_LIST;

typedef struct tagDT_ONE_ZONE_FACTION_ID_LIST{
	UINT16           wZoneID; //��ID
	UINT8            byFactionCnt; //�ж��ٸ�����
	UINT32           adwFactionList[GVG_16_TO_8_FACTION_CNT]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ONE_ZONE_FACTION_ID_LIST;

typedef struct tagDT_ZONE_LIST{
	UINT8            byZoneCnt; //��ID
	DT_ONE_ZONE_FACTION_ID_LIST astZoneList[MAX_GVG_ARENA_ZONE_CNT]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ZONE_LIST;

typedef struct tagDT_ZONE_ID_LIST{
	UINT8            byZoneCnt; //��ID
	UINT16           awZoneIDList[MAX_GVG_ARENA_ZONE_CNT]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ZONE_ID_LIST;

typedef struct tagDT_FACTION_LIST_GVG_LOG{
	UINT16           wFactionCnt; //������
	DT_FACTION_GVG_LOG astFactionLogs[GVG_16_TO_8_FACTION_CNT]; //�����ɵ�ս��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_LIST_GVG_LOG;

typedef struct tagDT_VIDEO_ID{
	UINT64           qwVideoID; //¼��ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_VIDEO_ID;

typedef struct tagDT_FINAL_WAR_EACH_ROUND_FACTION_INFO{
	UINT8            byEnemyPos; //�����ɵĶ����������б��е�λ��
	UINT16           wScore; //��ǰ����
	UINT64           qwVideoID; //¼��ID
	UINT8            byResult; //������� GvGLogResult

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FINAL_WAR_EACH_ROUND_FACTION_INFO;

typedef struct tagDT_FINAL_WAR_ROUND_INFO{
	UINT8            byFactionCnt; //����������
	UINT8            abyRankList[GVG_FINAL_WAR_FACTION_CNT]; //�����б�
	DT_FINAL_WAR_EACH_ROUND_FACTION_INFO astFactionList[GVG_FINAL_WAR_FACTION_CNT]; //���ָ����ɵ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FINAL_WAR_ROUND_INFO;

typedef struct tagDT_16_TO_8_TO_4_WAR_INFO{
	UINT8            byFactionCnt; //˫������ѡ����
	DT_GVG_FACTION   astFactionList[GVG_16_TO_8_FACTION_CNT]; //˫������ѡ���б�
	UINT8            byWin8Cnt; //16��8��ʤ��������
	UINT8            abyWin8List[GVG_16_TO_8_WIN_CNT]; //16��8��ʤ����������б�(���:1-16)
	UINT8            byWin4Cnt; //8��4��ʤ��������
	UINT8            abyWin4List[GVG_8_TO_4_WIN_CNT]; //8��4��ʤ����������б�(���:1-16)
	UINT64           aqwVideoIDList16To8[GVG_16_TO_8_WIN_CNT]; //16��8��¼��ID�б�
	UINT64           aqwVideoIDList8To4[GVG_8_TO_4_WIN_CNT]; //8��4��¼��ID�б�
	UINT8            byRolled; //�Ƿ������
	UINT8            byReady16To8; //16��8���Ƿ��Ѿ�����
	UINT8            byReady8To4; //8��4���Ƿ��Ѿ�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_16_TO_8_TO_4_WAR_INFO;

typedef struct tagDT_FINAL_WAR_INFO{
	UINT8            byTotalRound; //���ִ�
	UINT8            byFactionCnt; //�ķ�����ѡ����
	DT_GVG_FACTION   astFactionList[GVG_FINAL_WAR_FACTION_CNT]; //�ķ�����ѡ���б�
	UINT8            byTopCnt; //�����б��е���������δ�������ʱ��Ϊ0
	UINT8            abyTopList[GVG_FINAL_WAR_FACTION_CNT]; //�����������б������������������Ԫ�����ݷֱ��ǣ���һ��������š��ڶ���������š�.....�ڰ����������
	DT_FINAL_WAR_ROUND_INFO astEachRoundInfo[GVG_FINAL_WAR_FACTION_CNT]; //�����ִε�¼��ID�б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FINAL_WAR_INFO;

typedef struct tagDT_GVG_STAGE_FINISH_FLAG_LIST{
	UINT8            abyFlagList[30]; //��Ǹ����ִ��Ƿ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_STAGE_FINISH_FLAG_LIST;

typedef struct tagDT_GROUP_ZONE{
	UINT8            byGroupID; //���ID
	UINT16           awZoneIDList[2]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GROUP_ZONE;

typedef struct tagDT_GROUP_ZONE_ID_LIST{
	UINT8            byGroupCnt; //����
	DT_GROUP_ZONE    astGroupList[MAX_GVG_GROUP_NUM]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GROUP_ZONE_ID_LIST;

typedef struct tagDT_WAR_16_TO_8_LIST{
	UINT8            byWarCnt; //˫����ս����
	DT_16_TO_8_TO_4_WAR_INFO astWar16To8To4Info[MAX_GVG_GROUP_NUM]; //���˫����ս��Ķ�ս��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_WAR_16_TO_8_LIST;

typedef struct tagDT_GVG_ARENA_DATA{
	UINT16           wArenaID; //����̨��ID
	UINT8            byCurStage; //��ǰ�׶�
	UINT8            byIsDone; //�������Ƿ�����ɵ�ǰС�ִε�����
	DT_ZONE_ID_LIST  stZoneIDList; //����̨����ID�б�
	DT_GROUP_ZONE_ID_LIST stGroupZoneIDList; //����̨����ID�б�
	DT_WAR_16_TO_8_LIST stWar16To8List; //���˫���Ķ�ս��Ϣ�б�
	DT_FINAL_WAR_INFO stFinalWarInfo; //�ķ������ܾ�����Ϣ
	DT_FACTION_LIST_SIMPLE_GVG_LOG stFactionsLog; //��ǰ�����ɵ�ս��
	DT_GVG_STAGE_FINISH_FLAG_LIST stStageDoneFlagList; //��Ǹ����׶��Ƿ����������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_ARENA_DATA;

typedef struct tagDT_ZONE_FACTION_MEMBER{
	UINT32           dwZoneID; //����ID
	UINT8            byFactionCnt; //�����м������ɲ���
	UINT32           adwFactionIDList[MAX_GVG_TOP_FACTION_CNT]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_ZONE_FACTION_MEMBER;

typedef struct tagDT_GVG_ACTIVITY_DATA{
	UINT16           wSessionID; //���ο��ս�Ľ���
	UINT64           qwStartTime; //���ο��ս�Ŀ�ʼʱ��
	UINT8            byCurStage; //��ǰ��չ���ڼ��֣��� GVG_STAGE
	UINT8            byDone; //���ֵĹ����Ƿ�����ɣ����Խ��뵽��һ�֣���1/��0
	UINT8            byArenaCnt; //������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_ACTIVITY_DATA;

typedef struct tagDT_GVG_LOCAL_ACTIVITY_DATA{
	UINT16           wSessionID; //���ο��ս�Ľ���
	UINT64           qwStartTime; //���ο��ս�Ŀ�ʼʱ��
	UINT8            byCurStage; //��ǰ��չ���ڼ��֣��� GVG_STAGE
	UINT8            byDone; //���ֵĹ����Ƿ�����ɣ����Խ��뵽��һ�֣���1/��0
	DT_GVG_ARENA_DATA stArena; //����������������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_LOCAL_ACTIVITY_DATA;

typedef struct tagDT_TSTRING_MSG{
	TCHAR            aszTstringMsg[NORMAL_MSG_LEN]; //��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_TSTRING_MSG;

typedef struct tagDT_BATTLE_LOG_MSG_DATA{
	UINT32           dwPlayerID; //���ID
	UINT8            byLogBigType; //ս��������
	UINT8            byLogSmallType; //ս��С����
	UINT64           qwLogTime; //ս��ʱ��
	UINT8            byParamNum; //��������
	UINT64           aqwParamLst[MAX_BATTLE_LOG_PARAM_NUM]; //����
	UINT8            byStrNum; //�ַ�������
	DT_TSTRING_MSG   astStrLst[MAX_BATTLE_LOG_PARAM_STR]; //�ַ���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_LOG_MSG_DATA;

typedef struct tagDT_BATTLE_LOG_MSG_LST_DATA{
	UINT8            byLogNum; //ս������
	DT_BATTLE_LOG_MSG_DATA astLogData[MAX_BATTLE_LOG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_BATTLE_LOG_MSG_LST_DATA;

typedef struct tagDT_SOUL_LST_DATA{
	UINT16           wSoulNum; //ս�����
	DT_SOUL_DATA     astSoulLstData[MAX_SOUL_BAG_NUM]; //ս����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SOUL_LST_DATA;

typedef struct tagDT_PLAYER_SOUL_DATA{
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_SOUL_LST_DATA stSoulBagData; //ս�걳��
	UINT64           qwLastTime; //�ϴβ�����������ʱ��
	UINT8            abyTodayCoinCnt[MAX_SOUL_PRODUCT_TYPE]; //���������ʣ��ʹ��ͭǮ��
	UINT16           wFiveStarCnt; //���ǿ�����̽������������ֲ��ܻ�ȡ
	UINT16           wSixStarCnt; //���ǿ�����̽������������ֲ��ܻ�ȡ
	DT_SOUL_POTENCY_LST_DATA stSoulPotencyBagData; //ս��Ǳ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_SOUL_DATA;

typedef struct tagDT_MEDAL_DATA{
	UINT16           wMedalID; //ѫ��ID
	UINT64           qwActivateTime; //����ʱ��
	UINT8            byIsActivate; //�Ƿ񼤻�(0δ���1����)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MEDAL_DATA;

typedef struct tagDT_MEDAL_LST_DATA{
	UINT16           wMedalNum; //ѫ�¸���
	DT_MEDAL_DATA    astMedalLstData[MAX_MEDAL_NUM]; //ѫ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MEDAL_LST_DATA;

typedef struct tagDT_MEDAL_BASE_DATA{
	UINT32           dwLoginDayNum; //��ҵ�¼����
	UINT64           qwLoginTime; //����ϴε���ʱ��
	UINT32           dwBuyPhystrength; //����������
	UINT32           dwInterceptNum; //���ش���
	UINT32           dwEscortNum; //���ʹ���
	UINT32           dwRockMoneyNum; //�вƴ���
	UINT32           dwNormalGatherNum; //��ͨ�ۻ����
	UINT32           dwGoldGatherNum; //Ԫ���ۻ����
	UINT32           dwWorshipPlayer1Num; //Ĥ��1�������
	UINT32           dwWorshipPlayer2Num; //Ĥ��2�������
	UINT32           dwWorshipPlayer3Num; //Ĥ��3�������
	UINT32           dwWorshipGod1Num; //����1�������
	UINT32           dwWorshipGod2Num; //����2�������
	UINT32           dwWorshipGod3Num; //����3�������
	UINT32           dwZTSNum; //����ʦ���Դ���
	UINT32           dwSmileNum; //Ц������
	UINT32           dwArrestNum; //С����ץ������
	UINT32           dwDriveNum; //С�ڲ����ϴ���
	UINT32           dwTowerResetNum; //�������ô���
	UINT32           dwEliteInstanceResetNum; //��Ӣ�������ô���
	UINT32           dwGVEJoinNum; //��������
	UINT32           dwRaceRank; //����
	UINT64           qwLastRaceTime; //��������ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_MEDAL_BASE_DATA;

typedef struct tagDT_PLAYER_MEDAL_DATA{
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_MEDAL_LST_DATA stMealData; //ѫ������
	UINT64           qwLastUpdateTime; //����ʱ��
	DT_MEDAL_BASE_DATA stMedalBaseData; //ѫ�»�������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_MEDAL_DATA;

typedef struct tagDT_PET_WASHQUALITY_DATA{
	UINT8            byIsCanWash; //�Ƿ����ϴ
	UINT8            byCurWashQuality; //��ǰƷ��
	UINT32           dwPsychicVal; //����ֵ
	UINT32           dwMaxPsychicVal; //����ֵ���ֵ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_WASHQUALITY_DATA;

typedef struct tagDT_PET_DATA{
	UINT16           wPetId; //idΨһ��־
	UINT16           wPetCfgId; //����id
	UINT8            byStarLv; //�ǽ�
	UINT16           wLv; //�ȼ�
	UINT32           dwLvExp; //�ȼ�����
	TCHAR            aszPetName[MAX_PET_NAME_LENGTH]; //����
	UINT8            abyFeedFruit[MAX_PET_FEED_FRUIT_CNT]; //����ι����Ϣ��¼
	UINT8            byPetState; //��������¼
	DT_PET_WASHQUALITY_DATA astWashQualityData[MAX_PET_WASH_PSYCHIC_CELL_CNT]; //����ϴ��������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_DATA;

typedef struct tagDT_NEIDAN_DATA{
	UINT16           wNeiDanID; //�ڵ�ID
	UINT16           wNeiDanIdx; //�ڵ�����IDX
	UINT16           wNeiDanLevel; //�ڵ��ȼ�
	UINT64           qwNeiDanExcpetion; //�ڵ�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NEIDAN_DATA;

typedef struct tagDT_PET_NEIDAN_DATA_LST{
	DT_NEIDAN_DATA   astNeiDanInfoLst[MAX_PET_NEIDAN_NUM]; //�ڵ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_NEIDAN_DATA_LST;

typedef struct tagDT_PLAYER_NEIDAN_DATA_LST{
	UINT16           wPetNum; //��������
	DT_PET_NEIDAN_DATA_LST astNeiDanInfo[MAX_PET_NUM]; //�ڵ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_NEIDAN_DATA_LST;

typedef struct tagDT_NEIDAN_DATA_LST{
	UINT16           wNeiDanNum; //�ڵ�����
	DT_NEIDAN_DATA   astNeiDanInfo[MAX_NEI_DAN_BAG_NUM]; //�ڵ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_NEIDAN_DATA_LST;

typedef struct tagDT_PET_DATA_LIST{
	UINT16           wPetNum; //��������
	DT_PET_DATA      astPetData[MAX_PET_NUM]; //��������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_DATA_LIST;

typedef struct tagDT_PET_CALL_DATA{
	UINT16           wPetCfgID; //��������ID
	UINT32           dwPetCallNum; //�����ٻ�����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_CALL_DATA;

typedef struct tagDT_PET_CALL_LST_DATA{
	UINT16           wPetNum; //����
	DT_PET_CALL_DATA astCallInfo[MAX_PET_NUM]; //�ٻ���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PET_CALL_LST_DATA;

typedef struct tagDT_HERO_HP_DATA{
	UINT16           wHeroID; //heroID
	UINT32           dwHeroHP; //HP
	UINT8            byFormationIdx; //λ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_HP_DATA;

typedef struct tagDT_HERO_HP_DATA_LST{
	UINT8            byHeroNum; //Ӣ�۸���
	DT_HERO_HP_DATA  astHeroHPLst[MAX_FORMATION_IDX_NUM]; //Ӣ��Ѫ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_HERO_HP_DATA_LST;

typedef struct tagDT_PLAYER_PET_DATA{
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_PET_DATA_LIST stPetDataLst; //��������
	UINT64           qwNormalLastTime; //��ͨ�ٻ��ϴβ���ʱ��
	UINT64           qwGoodLastTime; //�����ٻ��ϴβ���ʱ��
	UINT16           wNormalProductNum; //������ͨ�ٻ�����
	UINT16           wGoodProductNum; //���������ٻ�����
	UINT64           qwProductLastTime; //�ϴβ���ʱ��
	UINT32           dwPetScore; //�������
	UINT64           qwLastFeedTime; //�ϴ�ι��ʱ��
	UINT32           dwLeftFreeFeedCnt; //�������ι������
	UINT32           dwVIPFeedCnt; //����VIPι������
	DT_PET_CALL_LST_DATA stPetCallData; //�ٻ����ĳ������������
	UINT16           wFreeNormalProductCnt; //��ͨ�ٻ�ʣ�����
	UINT8            byCallFlag; //�Ƿ������ٻ���ʶ
	DT_PLAYER_NEIDAN_DATA_LST stPetNeiDan; //�����ڵ���Ϣ
	DT_NEIDAN_DATA_LST stPetNeiDanBag; //�ڵ�����
	DT_HERO_HP_DATA_LST stHeroLstInfo; //Ӣ��Ѫ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_PET_DATA;

typedef struct tagDT_PLAYER_NOPVP_DATA{
	DT_PLAYER_BASE_DATA stBaseData; //��һ�����Ϣ
	DT_HERO_DATA_LIST stHeroData; //����佫��Ϣ�б�
	DT_BAG_EQUIP_DATA_LST stBagEquipData; //��ұ���װ��������Ϣ(����ڱ�����װ������������װ����װ��)
	DT_BAG_GOODS_DATA_LST stBagGoodsData; //��ұ�����Ʒ������Ϣ
	DT_BUILD_DATA_LIST stBuildData; //��ҽ�����Ϣ
	DT_TASK_DATA_LIST stTaskData; //���������Ϣ
	DT_LOCALE_DATA   stLocaleData; //��ҵ�ǰλ����Ϣ
	DT_STATE_DATA    stCurState; //��ҵ�ǰ״̬��Ϣ
	DT_ONLINE_ENCOURAGE_RECORD_DATA stOnlineEncRecdData; //���߽�����Ϣ
	DT_LOGIN_ENCOURAGE_RECORD_DATA stLoginEncRecdData; //��½������Ϣ
	DT_INSTANCE_DB_DATA stInstanceData; //��ͨ������Ϣ
	DT_MONEY_TREE_DATA stMoneyTreeData; //ҡǮ����Ϣ
	DT_ONHOOK_RCD_DATA stOnhookRcdData; //�һ���¼��Ϣ
	DT_JINGJIE_DATA  stJingJieData; //������Ϣ
	DT_PHYSTRENGTH_DATA stPhystrengthData; //������Ϣ
	DT_FEW_PARAM_DATA stFewParamData; //�ٲ�����Ϣ
	DT_CROP_DATA     stCropData; //��ֲ��Ϣ
	DT_SCIENCE_TREE_DATA stScienceTree; //�Ƽ�����Ϣ
	DT_NEW_FORMATION_DATA stFormationInfo; //������Ϣ
	CHAR             szLastOrderID[MAX_ORDER_ID_LEN]; //�ϴδ���Ķ����ţ����ڱ����ظ�����
	DT_EAT_BREAD_DATA stEatBreadInfo; //�԰�����Ϣ
	DT_YABIAO_DATA   stYabiaoInfo; //Ѻ����Ϣ
	UINT8            abyNoticeID[MAX_TOKEN_NUM]; //�����Ϣ����ID
	UINT64           qwLoginTime; //����¼ʱ��
	UINT64           qwLogoffTime; //���ǳ�ʱ��
	DT_CLIMB_TOWER_DATA stClimbTowerData; //�������������Ϣ
	DT_AWAKEN_DATA   stAwakenData; //�����Ϣ
	DT_VIP_EXT_DATA  stVipExtData; //VIP���ӵ���Ϣ
	DT_LUAACTIVITY_RECORD_LIST_DATA stLuaActivityRecordData; //lua�ű����¼
	DT_COLLECT_GAS_DATA stGasCollectData; //�����ռ���Ϣ
	DT_BOSS_BATTLE_PLAYER_DATA_INFO stBossBattlePlayerDataInfo; //Bossս��Ϣ
	DT_ACTIVITY_ENCOURAGE_DATA stActivityEncourageData; //������Ϣ
	DT_RANDOM_CHALLENGE_DATA stRdChallengeData; //�����ս��Ϣ
	DT_WORSHIP_DATA_LST stWorshipData; //Ĥ����Ϣ
	DT_SCORE_DATA_LST stScoreData; //����������Ϣ
	DT_EQUIP_COMPOSE_DATA stEquipComposeData; //װ���ϳ���Ϣ
	DT_GATHER_SCIENCE_DATA stGatherScienceData; //�ۻ���Ϣ
	DT_BEGBLUE_DATA  stBegBlueData; //����¶��Ϣ
	DT_PLAYER_TODAY_CONSUME_DATA stTodayConsume; //���������
	DT_FRIENDS_DATA  stFriendsData; //���ʻ�����
	DT_PLAYER_FACTION_DATA stPlayerFactionData; //���������Ϣ
	DT_COURAGE_DATA  stCourageData; //���������Ϣ
	DT_EQUIP_MASTER  stEquipMasterData; //װ����ͨ��Ϣ
	DT_EXCHANGE_RESULT_LOG stExchangeResultLog; //������־
	DT_BAG_JEWELRY_DATA_LST stBagJewelryInfo; //�����Ʒ��Ϣ
	DT_PLAYER_GVG_DATA stGvGData; //���gvg��Ϣ
	DT_PLAYER_SOUL_DATA stSoulData; //���ս�걳��
	DT_PLAYER_MEDAL_DATA stMedalData; //���ѫ����Ϣ
	DT_PLAYER_PET_DATA stPetData; //��ҳ�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_NOPVP_DATA;

typedef struct tagDT_PLAYER_PVP_DATA{
	DT_RACE_DATA     stRaceData; //��������Ϣ
	DT_PLUNDER_DATA  stPlunderData; //�Ӷ���Ϣ
	DT_ENEMY_DATA_LIST stEnemyData; //�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_PVP_DATA;

typedef struct tagDT_PLAYER_DATA{
	DT_PLAYER_NOPVP_DATA stPlayerNoPvpData; //��ҷ�PVP��Ϣ
	DT_PLAYER_PVP_DATA stPlayerPvpData; //���PVP��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_PLAYER_DATA;

typedef struct tagDT_EXT_FUNC_PARAM{
	UINT8            byParam1; //����1
	UINT16           wParam2; //����2
	UINT32           dwParam3; //����3

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EXT_FUNC_PARAM;

typedef struct tagDT_EXT_FUNC_PARAM_LST{
	UINT8            byFuncNum; //��չ������
	DT_EXT_FUNC_PARAM astExtFuncParaInfo[MAX_EXT_FUN_NUM]; //��չ������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_EXT_FUNC_PARAM_LST;

typedef struct tagDT_CONTINUE_KILL_DATA{
	UINT8            byNum; //������
	UINT64           aqwKeyLst[MAX_FACTION_BATTLE_NUM]; //����ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CONTINUE_KILL_DATA;

typedef struct tagDT_FACTION_PLAYER_DATA{
	UINT32           dwJoinPlayerID; //���ID
	UINT8            byJoinState; //��ҵ�ǰ״̬
	UINT8            byJobType; //ְҵ����
	UINT32           dwDoorsTribute; //ʣ���Ź�
	UINT64           qwDoorsTributeSum; //�ۻ��Ź�
	UINT8            byDrinkFlag; //�����¼�������ʶ
	UINT8            byNewGoodFlag; //�»���
	UINT8            byNewSkillFlag; //�¼���
	DT_PLAYER_FACTION_BATTLELOG_DATA_LIST stUnLoginBattleLogList; //����δ��ս��
	UINT64           qwJoinTime; //��������ʱ��
	DT_CONTINUE_KILL_DATA stContinueKillKey; //��ȡ����ն���

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_PLAYER_DATA;

typedef struct tagDT_FACTION_PLAYER_DATA_LST{
	UINT32           dwFactionNum; //�û���
	DT_FACTION_PLAYER_DATA astFactionPlayerData[DT_FACTION_PLAYER_NUM]; //�����û���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_PLAYER_DATA_LST;

typedef struct tagDT_FACTION_LOG_DATA{
	UINT32           dwPlayerID1; //���ID
	UINT8            byPlayerJobType1; //���ְλ
	UINT32           dwPlayerID2; //���ID
	UINT8            byPlayerJobType2; //���ְλ
	UINT8            byAction; //�¼�ID
	UINT32           adwParamList[FACTION_LOG_LIST_MAX_NUM]; //��������
	UINT64           qwLogTime; //ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_LOG_DATA;

typedef struct tagDT_FACTION_LOG_DATA_LST{
	UINT16           wFactionLogNum; //�û���
	DT_FACTION_LOG_DATA astFactionLogData[MAX_FACTION_LOG_NUM]; //�����û���Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_LOG_DATA_LST;

typedef struct tagDT_FACTION_BASE_DATA{
	UINT32           dwFactionID; //����ID
	UINT32           dwFactionPlayerID; //����ID
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT32           dwFactionRank; //��������
	UINT32           dwFactionLevel; //���ɵȼ�
	TCHAR            aszFactionNotice[MAX_FACTION_DESC_NUM]; //����֪ͨ
	TCHAR            aszFactionAnnouncement[MAX_FACTION_DESC_NUM]; //���ɹ���
	UINT64           qwFactionCreateTime; //���ɴ���ʱ��
	UINT32           dwRareItemRoomGrade; //�䱦��ȼ�
	UINT32           dwGymnasiumLevel; //���õȼ�
	UINT32           dwShadeLevel; //�����ȼ�
	UINT32           dwFactionFunds; //�����ʽ�
	UINT32           dwHotSpringLevel; //��Ȫ�ȼ�
	UINT32           dwColdPrisonLevel; //���εȼ�
	UINT32           dwFactionTowerLevel; //������ȼ�
	UINT64           qwFactionFundsSum; //�����ۻ��ʽ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_BASE_DATA;

typedef struct tagDT_FACTION_DATA{
	DT_FACTION_BASE_DATA stFactionBaseData; //���ɻ�������
	DT_FACTION_PLAYER_DATA_LST stFactionPlayerDataLst; //�������������Ϣ
	DT_FACTION_LOG_DATA_LST stFactionLogDataLst; //������־������Ϣ
	DT_FACTION_COMMON_DATA stFactionCommonData; //����״̬��Ϣ
	UINT8            byFactionException; //���������쳣��ʶ��0 Ϊ������ 1 Ϊ�쳣��
	UINT8            byTodayPassNum; //�������ͨ������
	UINT64           qwLastAuditTime; //���һ�����ʱ��
	UINT8            byExt; //��չλ��Ϣ
	DT_FACTION_GVG_DATA stGvGData; //����gvg����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_DATA;

typedef struct tagDT_FACTION_AUTHORITY{
	UINT8            byKickedNormal; //�߳���ͨ����
	UINT8            byKickedElite; //�߳���Ӣ����
	UINT8            byPromotion; //��ְ
	UINT8            byDemotion; //��ְ
	UINT8            byBuild; //�������ɽ���
	UINT8            byActivity; //������������
	UINT8            bySignUp; //��������ս
	UINT8            byAudit; //���
	UINT8            byEditSetting; //�޸���������
	UINT8            byShowLog; //�鿴��־
	UINT8            byChangeOther; //��λ����
	UINT8            byBecomeHead; //��λ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_AUTHORITY;

typedef struct tagDT_FACTION_AUTHORITY_EX{
	UINT8            byKickedNormal; //�߳���ͨ����
	UINT8            byKickedElite; //�߳���Ӣ����
	UINT8            byPromotion; //��ְ
	UINT8            byDemotion; //��ְ
	UINT8            byBuild; //�������ɽ���
	UINT8            byActivity; //������������
	UINT8            bySignUp; //��������ս
	UINT8            byAudit; //���
	UINT8            byEditSetting; //�޸���������
	UINT8            byShowLog; //�鿴��־
	UINT8            byChangeOther; //��λ����
	UINT8            byBecomeHead; //��λ����
	UINT8            byChangeIcon; //�ı�ͷ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_AUTHORITY_EX;

typedef struct tagDT_COURAGE_PLAYER_DATA{
	TCHAR            aszDispPlayerName[USERNAME_LEN]; //����ǳ�
	UINT16           wLevel; //��ҵȼ�
	UINT32           dwPlayerID; //���ID
	UINT8            byMemberType; //��Ա���� 0����Ա�� 1���ӳ�
	UINT8            byBattleType; //ս������ 0������ս���� 1��Э��ս��
	UINT8            byReadyType; //׼������ 0��׼���У� 1���Ѿ�׼��
	UINT16           wHeroID; //���ID
	UINT16           wKindID; //���ְҵID
	UINT16           wHeroLevel; //���ȼ�
	UINT8            byColor; //�佫��ɫ��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_PLAYER_DATA;

typedef struct tagDT_COURAGE_GROUP_DATA{
	UINT32           dwGroupID; //��ID
	UINT8            byJoinType; //�������� 0��ȫ�� 1�����ɣ�2������
	UINT16           wMinLevel; //������׵ȼ�
	UINT16           wPlayerNum; //��Ҹ���
	DT_COURAGE_PLAYER_DATA astPlayerData[MAX_COURAGE_GROUP_PLAYER_NUM]; //���������Ϣ
	UINT32           dwLeaderID; //�ӳ�ID
	UINT16           wAverageLevel; //����ƽ���ȼ�
	DT_INSTANCE_ID   stInstanceID; //�������
	UINT16           wPlayerMaxNum; //���������

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_GROUP_DATA;

typedef struct tagDT_COURAGE_GROUP_DATA_LST{
	UINT64           qwOverTime; //�����ʱ��
	UINT64           qwStartTime; //���ʼʱ��
	UINT64           qwSaveTime; //��������ʱ��
	UINT8            byActivityID; //�ID
	UINT16           wGroupNum; //��Ҹ���
	DT_COURAGE_GROUP_DATA astGroupData[MAX_COURAGE_GROUP_NUM]; //�����Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_COURAGE_GROUP_DATA_LST;

typedef struct tagDT_FACTION_APPLAY_DATA{
	UINT64           qwApplayTime; //����ʱ��
	UINT32           dwFactionID; //����ID
	UINT8            byWinCnt; //��ʤ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_APPLAY_DATA;

typedef struct tagDT_FACTION_APPLAY_LST_DATA{
	UINT16           wApplayNum; //��������
	DT_FACTION_APPLAY_DATA astFactionApplayLst[MAX_FACTION_APPLAY_NUM]; //�����б�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_APPLAY_LST_DATA;

typedef struct tagDT_SIMPLE_FACTION_INFO{
	DT_FACTION_BASE_DATA_CLI2 stFactionBaseInfo; //���ɻ�������
	UINT32           dwZoneID; //������ID
	UINT16           wRank; //������������ʱ��Ч��
	UINT8            byPosID; //λ��ID(ֻ����˫��սʱ��Ч)

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SIMPLE_FACTION_INFO;

typedef struct tagDT_SIMPLE_FACTION_LST_INFO{
	UINT16           wFactionNum; //��������
	DT_SIMPLE_FACTION_INFO astFactionInfo[MAX_RANK_DISPLAY]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_SIMPLE_FACTION_LST_INFO;

typedef struct tagDT_GVG_FACTION_RANK_DATA{
	UINT16           wRank; //����
	DT_FACTION_BASE_DATA_CLI2 stFactionBaseInfo; //���ɻ�������
	UINT64           qwSumPower; //��ս��
	UINT32           dwSumIntegral; //�ܻ���
	UINT8            byWinNum; //ʤ����
	UINT8            byLostNum; //ʧ����
	UINT16           wZoneID; //����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FACTION_RANK_DATA;

typedef struct tagDT_GVG_FACTION_RANK_LST_DATA{
	UINT16           wRankNum; //��������
	DT_GVG_FACTION_RANK_DATA astFactionRank[MAX_RANK_DISPLAY]; //��������
	DT_GVG_FACTION   stNo1; //�ھ�

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FACTION_RANK_LST_DATA;

typedef struct tagDT_FACTION_BATTLE_RESULT{
	UINT32           dwFactionID1; //��ս����ID1
	UINT32           dwFactionID2; //��ս����ID2
	UINT32           dwWinFactionID; //ʤ������ID

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_BATTLE_RESULT;

typedef struct tagDT_FACTION_BATTLE_RESULT_LST{
	UINT8            byResultNum; //��Ϣ����
	DT_FACTION_BATTLE_RESULT astBattleInfo[MAX_FACTION_BATTLE_NUM]; //��ս��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_FACTION_BATTLE_RESULT_LST;

typedef struct tagDT_LOCAL_WAR_FACTION_SEED{
	UINT32           dwFactionID; //����ID
	UINT8            byWinCnt; //�����ɴ��Ҷ��еĻ�ʤ����

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCAL_WAR_FACTION_SEED;

typedef struct tagDT_LOCAL_WAR_FACTION_SEED_LIST{
	UINT16           wFactionCnt; //����ѡ������
	UINT32           adwFactionIDList[MAX_FACTION_APPLAY_NUM]; //��ս��Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_LOCAL_WAR_FACTION_SEED_LIST;

typedef struct tagDT_CHAOS_WAR{
	UINT8            byChaosRound; //���δ��Ҷ����м����ִ�
	DT_SIMPLE_FACTION_LST_INFO stChaosResult; //���Ҷ���������
	DT_LOCAL_WAR_FACTION_SEED_LIST stFactionSeedList; //��һ������ѡ����Ա���ԵĹ���Ϊ<��1������ vs ��2������>��<��3������ vs ��4������>...

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_CHAOS_WAR;

typedef struct tagDT_GVG_BUILD_DATA{
	DT_FACTION_APPLAY_LST_DATA stApplayInfo; //���ɱ�����Ϣ
	DT_GVG_FACTION_RANK_LST_DATA stLastResult; //�Ͻ���Ϣ
	DT_SIMPLE_FACTION_LST_INFO stMoneyResult; //������������
	DT_CHAOS_WAR     stChaosWar; //���Ҷ���������
	DT_16_TO_8_TO_4_WAR_INFO stWar16To8To4Info; //����������˫�����ս��Ϣ
	DT_WAR_16_TO_8_LIST stWar16To8List; //���˫���Ķ�ս��Ϣ�б�
	DT_FINAL_WAR_INFO stFinalWarInfo; //�ķ������ܾ�����Ϣ
	DT_FACTION_LIST_SIMPLE_GVG_LOG stFactionsLog; //�����ɵ�ս��
	DT_GVG_STAGE_FINISH_FLAG_LIST stStageFlagList; //��Ǹ����׶��Ƿ����������
	UINT8            byCurStage; //��ǰ��չ���ڼ��֣��� GVG_STAGE
	UINT16           wSessionID; //���ο��ս�Ľ���
	UINT16           wArenaID; //������������ID
	UINT64           qwStartTime; //���ο��ս�Ŀ���ʱ��

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_BUILD_DATA;

typedef struct tagDT_GVG_FACTION_LIST{
	UINT8            byFactionNum; //���ɸ���
	DT_GVG_FACTION   astFactionLstData[MAX_GVG_FACTION_NUM]; //������Ϣ

	INT32 EncodeSaveData(CHAR *pBuff, const UINT32 dwBuffLen);
	INT32 DecodeSaveData(const CHAR *pBuff, const UINT32 dwBuffLen);
}DT_GVG_FACTION_LIST;

/*Define Structs and Unions        End*/


/*Define MaxEnLen MAC Begin*/
#define  MAXENLEN_DT_RES_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_ITEM_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_RES_NUM_ITEM_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+2+MAX_PLAYER_RES_NUM*MAXENLEN_DT_RES_DATA+sizeof(UINT8)+2+MAX_PLAYER_RES_NUM*MAXENLEN_DT_ITEM_DATA )
#define  MAXENLEN_DT_GUIDE_RECORD_DATA	( 1+1*sizeof(SIndex)+2+MAX_GUIDE_NUM*sizeof(UINT8) )
#define  MAXENLEN_DT_PLAYER_BASE_DATA	( 1+28*sizeof(SIndex)+sizeof(UINT32)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+MAXENLEN_DT_GUIDE_RECORD_DATA+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16) )
#define  MAXENLEN_DT_BATTLE_ATTRIBUTE	( 1+2*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_BATTLE_ATTRIBUTE2	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_BATTLE_BASE_ATTRIBUTE	( 1+3*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_HIDE_BATTLE_ATTRIBUTE	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_EXT_BATTLE_ATTRIBUTE	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT16) )
#define  MAXENLEN_DT_HERO_UPDATE_ATTR_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_HERO_ATTR_DATA	( 1+3*sizeof(SIndex)+MAXENLEN_DT_BATTLE_ATTRIBUTE+MAXENLEN_DT_HIDE_BATTLE_ATTRIBUTE+MAXENLEN_DT_HERO_UPDATE_ATTR_DATA )
#define  MAXENLEN_DT_SPECIAL_EFFECT_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_SKILL_SOUL_NUM*sizeof(UINT8) )
#define  MAXENLEN_DT_SOUL_ATTR_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_SOUL_POTENCY_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_SOUL_POTENCY_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_SOUL_BAG_NUM*MAXENLEN_DT_SOUL_POTENCY_DATA )
#define  MAXENLEN_DT_SOUL_DATA	( 1+15*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_SOUL_ATTR_NUM*MAXENLEN_DT_SOUL_ATTR_DATA+sizeof(UINT8)+2+MAX_SOUL_ATTR_NUM*MAXENLEN_DT_SOUL_ATTR_DATA+sizeof(UINT8)+MAXENLEN_DT_SPECIAL_EFFECT_DATA+2+MAX_SOUL_ATTR_NUM*sizeof(UINT8) )
#define  MAXENLEN_DT_HERO_SOUL_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+2+MAX_SOUL_EQUIP_NUM*MAXENLEN_DT_SOUL_DATA+2+MAX_SOUL_EQUIP_NUM*MAXENLEN_DT_SOUL_POTENCY_DATA )
#define  MAXENLEN_DT_HERO_BASE_DATA	( 1+18*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_BATTLE_ATTRIBUTE+MAXENLEN_DT_HIDE_BATTLE_ATTRIBUTE+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT64)+MAXENLEN_DT_HERO_UPDATE_ATTR_DATA+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_XIANGQIAN_DATA	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_EQUIP_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64)+2+MAX_XIANGQIAN_NUM*MAXENLEN_DT_XIANGQIAN_DATA )
#define  MAXENLEN_DT_HERO_EQUIP_DATA_LST	( 1+3*sizeof(SIndex)+sizeof(UINT16)+2+EQUIP_POS_NUM*MAXENLEN_DT_EQUIP_DATA+2+EQUIP_POS_NUM*sizeof(UINT16) )
#define  MAXENLEN_DT_BAG_EQUIP_DATA_LST	( 1+3*sizeof(SIndex)+sizeof(UINT16)+2+MAX_BAG_OPEN_NUM_NEW*MAXENLEN_DT_EQUIP_DATA+2+MAX_BAG_OPEN_NUM_NEW*sizeof(UINT16) )
#define  MAXENLEN_DT_GOODS_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_BAG_GOODS_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_BAG_OPEN_NUM_NEW*MAXENLEN_DT_GOODS_DATA )
#define  MAXENLEN_DT_DRUG_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_DRUG_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_DRUG_LEVEL*MAXENLEN_DT_DRUG_DATA )
#define  MAXENLEN_DT_GODWEAPON_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_ATTACK_RANG_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_SKILL_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+MAXENLEN_DT_ATTACK_RANG_DATA+sizeof(UINT32) )
#define  MAXENLEN_DT_SKILL_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_SKILL_SLOT_NUM*MAXENLEN_DT_SKILL_DATA )
#define  MAXENLEN_DT_STUDY_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_AWAKEN_BASE_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_AWAKEN_BASE_DATA1	( 1+5*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_AWAKEN_DATA	( 1+4*sizeof(SIndex)+MAXENLEN_DT_AWAKEN_BASE_DATA+2+MAX_BAG_STUDY_GRID_NUM*MAXENLEN_DT_STUDY_DATA+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_AWAKEN_DATA_LST	( 1+1*sizeof(SIndex)+2+MAX_HERO_STUDY_GRID_NUM*MAXENLEN_DT_STUDY_DATA )
#define  MAXENLEN_DT_ABSORB_DATA_LST	( 1+3*sizeof(SIndex)+sizeof(UINT8)+2+MAX_ABSORB_NUM*sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_ATTR_INC_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_BATTLE_ATTR_LST_INFO	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_SCIENCE_ATTR_NUM*MAXENLEN_DT_ATTR_INC_DATA )
#define  MAXENLEN_DT_BATTLE_ATTR_EXT_INFO	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_BATTLE_ATTR_EXT_LST_INFO	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_SCIENCE_ATTR_NUM*MAXENLEN_DT_BATTLE_ATTR_EXT_INFO )
#define  MAXENLEN_DT_JEWELRY_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+MAXENLEN_DT_BATTLE_ATTR_LST_INFO+MAXENLEN_DT_BATTLE_ATTR_EXT_LST_INFO+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16) )
#define  MAXENLEN_DT_JEWELRY_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_JEWELRY_POS*MAXENLEN_DT_JEWELRY_DATA )
#define  MAXENLEN_DT_BAG_JEWELRY_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_BAG_OPEN_NUM_NEW*MAXENLEN_DT_JEWELRY_DATA )
#define  MAXENLEN_DT_HERO_DATA	( 1+7*sizeof(SIndex)+MAXENLEN_DT_HERO_BASE_DATA+MAXENLEN_DT_HERO_EQUIP_DATA_LST+MAXENLEN_DT_DRUG_DATA_LST+MAXENLEN_DT_GODWEAPON_DATA+MAXENLEN_DT_SKILL_DATA_LST+MAXENLEN_DT_AWAKEN_DATA_LST+MAXENLEN_DT_ABSORB_DATA_LST )
#define  MAXENLEN_DT_HERO_DATA_LIST	( 1+4*sizeof(SIndex)+sizeof(UINT16)+2+MAX_HERO_NUM*MAXENLEN_DT_HERO_DATA+2+MAX_HERO_NUM*MAXENLEN_DT_JEWELRY_DATA_LST+2+MAX_HERO_NUM*MAXENLEN_DT_HERO_SOUL_DATA )
#define  MAXENLEN_DT_BUILD_BASE_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_BUILD_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_BUILD_NUM*MAXENLEN_DT_BUILD_BASE_DATA )
#define  MAXENLEN_DT_INSTANCE_ID	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_INSTANCE_DATA	( 1+7*sizeof(SIndex)+MAXENLEN_DT_INSTANCE_ID+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_INSTANCE_DATA_LIST	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+2+MAX_INSTANCE_PER_SCENE_NUM*MAXENLEN_DT_INSTANCE_DATA )
#define  MAXENLEN_DT_SCIENCE_ATTREXT	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_SCIENCE_ATTREXT_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_SCIENCE_ATTR_NUM*MAXENLEN_DT_SCIENCE_ATTREXT )
#define  MAXENLEN_DT_CROWN_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_BUILDUPGRADE_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_RECRUITHERO_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_CROWN_HEROCOLOR_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_CROWN_HEROUPGRADE_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_FIRSTPASSINSTANCE_TASK_CONDITION	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_SCOREPASSINSTANCE_TASK_CONDITION	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_TIMESPASSINSTANCE_TASK_CONDITION	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_KILLMONSTERINSTANCE_TASK_CONDITION	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_STRENGTHENEQUIPNUM_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_ITEMCOLLECT_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_ITEM_KIND_COLLECT_NUM*sizeof(UINT8) )
#define  MAXENLEN_DT_ACTIVATEGODWEAPON_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_UPGRADEGODWEAPON_TASK_CONDITION	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_UPGRADEDRUG_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_CHALLENGE_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_PLUNDER_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_DRESSSKILL_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_DRESSEQUIP_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_UPGRADEEQUIP_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_USEEXPRIENCEDRUG_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_MELT_EQUIP_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_COMPOSEGOOD_TASK_CONDITION	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_ELITEINSTANCE_TASK_CONDITION	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_UPGRADSCIENCE_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_STRENGTHATTACK_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_STRENGTHLIFE_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_CROP_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_UPGRADESKILL_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_UPGRADEJINGJIE_TASK_CONDITION	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_MOSAICGEM_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_CLIMBTOWER_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_STUDY_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT8) )
#define  MAXENLEN_DT_RECRUITHERO_NUM_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT16) )
#define  MAXENLEN_DT_OPENLIGHT_TASK_CONDITION	( 1+1*sizeof(SIndex)+sizeof(UINT8) )
#define  MAXENLEN_DT_TASK_CONDITION ( 10*sizeof(DT_TASK_CONDITION) )
#define  MAXENLEN_DT_TASK_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(DT_TASK_CONDITION) )
#define  MAXENLEN_DT_TASK_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_TASK_LINE_NUM*MAXENLEN_DT_TASK_DATA )
#define  MAXENLEN_DT_RACE_BASE_DATA	( 1+11*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOCALE_HOME	( 1+1*sizeof(SIndex)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOCALE_INSTANCE	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOCALE_ONHOOK	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOCALE_MARK	( 1+1*sizeof(SIndex)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOCALE_DATA_UNION ( 10*sizeof(DT_LOCALE_DATA_UNION) )
#define  MAXENLEN_DT_LOCALE_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(DT_LOCALE_DATA_UNION) )
#define  MAXENLEN_UnlockScienceInfo	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_SCIENCE_ATTR_NUM*sizeof(UINT8) )
#define  MAXENLEN_DT_HERO_UPGRADE_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16) )
#define  MAXENLEN_DT_STATE_DATA	( 1+13*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT8)+2+MAX_ENCOURAGE_BOX_GROUP_NUM*sizeof(UINT8)+2+MAX_UNLOCK_HERO_NUM*sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+MAXENLEN_UnlockScienceInfo+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_HERO_UPGRADE_DATA )
#define  MAXENLEN_DT_MONSTER_BASE_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_MONSTER_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_INSTANCE_MONSTER_NUM*MAXENLEN_DT_MONSTER_BASE_DATA )
#define  MAXENLEN_DT_GODWEAPON_BATTLE_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+MAXENLEN_DT_BATTLE_ATTRIBUTE+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_BATTLE_OBJ_DATA	( 1+11*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+MAXENLEN_DT_BATTLE_ATTRIBUTE+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_BATTLE_OBJ_DATA2	( 1+12*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+MAXENLEN_DT_BATTLE_ATTRIBUTE+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_GODWEAPON_BATTLE_DATA )
#define  MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_BATTLE_OBJ_DATA+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT32) )
#define  MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2	( 1+4*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_BATTLE_OBJ_DATA2+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT32) )
#define  MAXENLEN_DT_BUFF_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_HP_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(INT32) )
#define  MAXENLEN_DT_ANGRY_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(INT16) )
#define  MAXENLEN_DT_PARRY_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_SKILL_EFFECT_ID_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_ATTACK_OBJ_DATA	( 1+8*sizeof(SIndex)+sizeof(UINT8)+2+MAX_BUFF_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_BUFF_DATA+sizeof(UINT8)+2+MAX_HP_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_HP_DATA+sizeof(UINT8)+2+MAX_ANGRY_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_ANGRY_DATA+sizeof(UINT8)+2+MAX_BUFF_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_SKILL_EFFECT_ID_DATA )
#define  MAXENLEN_DT_ATTACK_OBJ_DATA2	( 1+8*sizeof(SIndex)+sizeof(UINT8)+2+MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_BUFF_DATA+sizeof(UINT8)+2+MAX_HP_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_HP_DATA+sizeof(UINT8)+2+MAX_NEW_ANGRY_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_ANGRY_DATA+sizeof(UINT8)+2+MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_SKILL_EFFECT_ID_DATA )
#define  MAXENLEN_DT_ATTACK_DATA	( 1+2*sizeof(SIndex)+MAXENLEN_DT_ATTACK_OBJ_DATA+MAXENLEN_DT_ATTACK_OBJ_DATA )
#define  MAXENLEN_DT_ATTACK_DATA2	( 1+2*sizeof(SIndex)+MAXENLEN_DT_ATTACK_OBJ_DATA2+MAXENLEN_DT_ATTACK_OBJ_DATA2 )
#define  MAXENLEN_DT_GODWEAPON_ATTACK_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_ANGRY_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_ANGRY_DATA )
#define  MAXENLEN_DT_GODWEAPON_ATTACK_DATA2	( 1+5*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_ANGRY_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_ANGRY_DATA )
#define  MAXENLEN_DT_ATTACK_ALL_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_PARRY_DATA+MAXENLEN_DT_ATTACK_DATA+MAXENLEN_DT_ATTACK_DATA )
#define  MAXENLEN_DT_ATTACK_ALL_DATA2	( 1+8*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_PARRY_DATA+MAXENLEN_DT_ATTACK_DATA+MAXENLEN_DT_ATTACK_DATA+MAXENLEN_DT_GODWEAPON_ATTACK_DATA )
#define  MAXENLEN_DT_ATTACK_ALL_DATA3	( 1+8*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_PARRY_DATA+MAXENLEN_DT_ATTACK_DATA2+MAXENLEN_DT_ATTACK_DATA2+MAXENLEN_DT_GODWEAPON_ATTACK_DATA )
#define  MAXENLEN_DT_BATTLE_ANGRY_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_BATTLE_ROUND_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_ATTACK_ALL_DATA )
#define  MAXENLEN_DT_BATTLE_ROUND_DATA2	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_ATTACK_ALL_DATA2 )
#define  MAXENLEN_DT_BATTLE_ROUND_DATA3	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_ATTACK_ALL_DATA3 )
#define  MAXENLEN_DT_BATTLE_DATA	( 1+7*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_BATTLE_ROUND_NUM*MAXENLEN_DT_BATTLE_ROUND_DATA+MAXENLEN_DT_BATTLE_ATTRIBUTE )
#define  MAXENLEN_DT_BATTLE_DATA2	( 1+7*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_BATTLE_ROUND_NUM*MAXENLEN_DT_BATTLE_ROUND_DATA2+MAXENLEN_DT_BATTLE_ATTRIBUTE )
#define  MAXENLEN_DT_BATTLE_DATA3	( 1+7*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_NEW_BATTLE_ROUND_NUM*MAXENLEN_DT_BATTLE_ROUND_DATA3+MAXENLEN_DT_BATTLE_ATTRIBUTE )
#define  MAXENLEN_DT_SHIELD_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_HP_DATA2	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(INT32)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_ATTACK_OBJ_DATA3	( 1+10*sizeof(SIndex)+sizeof(UINT8)+2+MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_BUFF_DATA+sizeof(UINT8)+2+MAX_HP_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_HP_DATA2+sizeof(UINT8)+2+MAX_NEW_ANGRY_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_ANGRY_DATA+sizeof(UINT8)+2+MAX_NEW_BUFF_CHANGE_TIMES_PER_ROUND*MAXENLEN_DT_SKILL_EFFECT_ID_DATA+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_SHIELD_DATA )
#define  MAXENLEN_DT_ATTACK_DATA3	( 1+2*sizeof(SIndex)+MAXENLEN_DT_ATTACK_OBJ_DATA3+MAXENLEN_DT_ATTACK_OBJ_DATA3 )
#define  MAXENLEN_DT_PARRY_DATA2	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_ATTACK_ALL_DATA4	( 1+10*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_PARRY_DATA2+MAXENLEN_DT_ATTACK_DATA3+MAXENLEN_DT_ATTACK_DATA3+MAXENLEN_DT_GODWEAPON_ATTACK_DATA2+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_BATTLE_ROUND_DATA4	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_ATTACK_ALL_DATA4 )
#define  MAXENLEN_DT_BATTLE_DATA4	( 1+7*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA2+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_NEW_BATTLE_ROUND_NUM*MAXENLEN_DT_BATTLE_ROUND_DATA4+MAXENLEN_DT_BATTLE_ATTRIBUTE )
#define  MAXENLEN_DT_ATTACK_ALL_DATA5	( 1+13*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_PARRY_DATA2+MAXENLEN_DT_ATTACK_DATA3+MAXENLEN_DT_ATTACK_DATA3+MAXENLEN_DT_GODWEAPON_ATTACK_DATA2+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_BATTLE_ROUND_DATA5	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_ATTACK_ALL_DATA5 )
#define  MAXENLEN_DT_PET_BATTLE_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA3	( 1+5*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_BATTLE_OBJ_DATA2+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT32)+MAXENLEN_DT_PET_BATTLE_DATA )
#define  MAXENLEN_DT_BATTLE_DATA5	( 1+7*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA3+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA3+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_NEW_BATTLE_ROUND_NUM*MAXENLEN_DT_BATTLE_ROUND_DATA5+MAXENLEN_DT_BATTLE_ATTRIBUTE )
#define  MAXENLEN_DT_BATTLE_OBJ_MAX_HP	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_BATTLE_OBJ_MAX_HP )
#define  MAXENLEN_DT_EMPTY_HP_VIDEO_v400	( 1+5*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_DATA4 )
#define  MAXENLEN_DT_EMPTY_HP_VIDEO	( 1+5*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_OBJ_MAX_HP_INFO+MAXENLEN_DT_BATTLE_DATA5 )
#define  MAXENLEN_DT_FINAL_ROUND_BATTLE_OBJ_INFO	( 1+2*sizeof(SIndex)+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA3+MAXENLEN_DT_BATTLE_OBJ_GROUP_DATA3 )
#define  MAXENLEN_DT_ONLINE_ENCOURAGE_RECORD_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOGIN_ENCOURAGE_RECORD_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_RACE_BATTLELOG_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_RACE_BATTLELOG_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_RACE_BATTLELOG_NUM*MAXENLEN_DT_RACE_BATTLELOG_DATA )
#define  MAXENLEN_DT_CAPTURE_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_CAPTURE_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_CAPTURE_NUM*MAXENLEN_DT_CAPTURE_DATA )
#define  MAXENLEN_DT_PLUNDER_BATTLELOG_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_PLUNDER_BATTLELOG_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_PLUNDER_BATTLELOG_NUM*MAXENLEN_DT_PLUNDER_BATTLELOG_DATA )
#define  MAXENLEN_DT_PLUNDER_GRID_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_PLUNDER_BASE_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+2+MAX_CAPTURE_NUM*MAXENLEN_DT_PLUNDER_GRID_DATA )
#define  MAXENLEN_DT_ENEMY_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_ENEMY_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_ENEMY_NUM*MAXENLEN_DT_ENEMY_DATA )
#define  MAXENLEN_DT_MONEY_TREE_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_INSTANCE_BATTLE_DATA	( 1+5*sizeof(SIndex)+MAXENLEN_DT_INSTANCE_ID+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_PHYSTRENGTH_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16) )
#define  MAXENLEN_DT_ONHOOK_RESULT	( 1+9*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_ENCOURAGE_ITEM_KIND_NUM*MAXENLEN_DT_ITEM_DATA+sizeof(UINT32) )
#define  MAXENLEN_DT_ONHOOK_RCD_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_ONHOOK_RESULT+MAXENLEN_DT_INSTANCE_ID+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_FEW_PARAM_DATA	( 1+24*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_CROP_INFO_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_CROP_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_CROP_NUM*MAXENLEN_DT_CROP_INFO_DATA )
#define  MAXENLEN_DT_SCIENCE_TREE_DATA	( 1+15*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_FORMATION_HERO_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_FORMATION_IDX_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_FORMATION_HERO_DATA )
#define  MAXENLEN_DT_FORMATION_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FORMATION_NUM*MAXENLEN_DT_FORMATION_IDX_DATA )
#define  MAXENLEN_DT_FORMATION_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_FORMATION_DATA_LIST )
#define  MAXENLEN_DT_NEW_FORMATION_POSTION_INFO	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_NEW_FORMATION_INFO	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_NEW_FORMATION_POSTION_INFO+sizeof(UINT8) )
#define  MAXENLEN_DT_NEW_FORMATION_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_NEW_FORMATION_NUM*MAXENLEN_DT_NEW_FORMATION_INFO )
#define  MAXENLEN_DT_NEW_FORMATION_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_FORMATION_DATA_LIST+sizeof(UINT8)+MAXENLEN_DT_NEW_FORMATION_DATA_LST+MAXENLEN_DT_NEW_FORMATION_DATA_LST+sizeof(UINT8) )
#define  MAXENLEN_DT_VERSION_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_CONTENT_SIZE*sizeof(UINT16)+2+MAX_CONTENT_SIZE*sizeof(UINT16) )
#define  MAXENLEN_DT_NOTICE_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_CONTENT_SIZE*sizeof(UINT16) )
#define  MAXENLEN_DT_NOTICE_DATA_DB	( 1+7*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_NOTICE_CONTENT_LEN*sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_NOTICE_DATA_NEW	( 1+4*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_NOTICE_CONTENT_LEN*sizeof(UINT16) )
#define  MAXENLEN_DT_EAT_BREAD_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_YABIAO_BASE_DATA	( 1+18*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_YABIAO_BATTLELOG_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_YABIAO_BATTLELOG_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_YABIAO_BATTLELOG_NUM*MAXENLEN_DT_YABIAO_BATTLELOG_DATA )
#define  MAXENLEN_DT_SKILL_ACTION_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_SKILL_ACTION_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_SKILL_SLOT_NUM*MAXENLEN_DT_SKILL_ACTION_DATA )
#define  MAXENLEN_DT_JINGJIE_BASE_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_GAS_BALL_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_COLLECT_GAS_DATA	( 1+15*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GAS_BALL_NUM*MAXENLEN_DT_GAS_BALL_DATA+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_JINGJIE_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_JINGJIE_BASE_DATA+MAXENLEN_DT_COLLECT_GAS_DATA+MAXENLEN_DT_SKILL_ACTION_DATA_LIST )
#define  MAXENLEN_DT_CLIMB_TOWER_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_ELITE_INSTANCE_RESET_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_VIP_GET_NUM_EACH_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16) )
#define  MAXENLEN_DT_VIP_GET_NUM_LEVEL_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_VIP_GIFT*MAXENLEN_DT_VIP_GET_NUM_EACH_DATA )
#define  MAXENLEN_DT_VIP_EXT_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+2+MAX_ELITE_INSTANCE_TOWN_NUM*MAXENLEN_DT_ELITE_INSTANCE_RESET_DATA+sizeof(UINT64)+sizeof(UINT8)+2+MAX_VIP_LEVEL*MAXENLEN_DT_VIP_GET_NUM_LEVEL_DATA )
#define  MAXENLEN_DT_LUAACTIVITY_RECORD_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_LUAACTIVITY_RECORD_LIST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_LUAACTIVITY_RECORD_NUM*MAXENLEN_DT_LUAACTIVITY_RECORD_DATA )
#define  MAXENLEN_DT_BOSSB_HURT_RATE	( 1+5*sizeof(SIndex)+sizeof(UINT32)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_BOSS_BATTLE_ENC_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT32)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_BOSS_BATTLE_PLAYER_DATA	( 1+21*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+MAXENLEN_DT_BOSSB_HURT_RATE+MAXENLEN_DT_BOSS_BATTLE_ENC_DATA+MAXENLEN_DT_BOSS_BATTLE_ENC_DATA+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_BOSS_BATTLE_DATA	( 1+14*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+2+MAX_BOSS_ENC_TOP_NUM*MAXENLEN_DT_BOSSB_HURT_RATE+2+MAX_BOSS_ENC_TOP_NUM*MAXENLEN_DT_BOSS_BATTLE_ENC_DATA+MAXENLEN_DT_BOSS_BATTLE_ENC_DATA+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT8)+MAXENLEN_DT_BOSSB_HURT_RATE+MAXENLEN_DT_BOSS_BATTLE_ENC_DATA+MAXENLEN_DT_BOSS_BATTLE_ENC_DATA )
#define  MAXENLEN_DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_BOSSB_BATTLE_LOG_NUM*MAXENLEN_DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA )
#define  MAXENLEN_DT_BOSS_BATTLE_MODULE_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_BOSSB_NUM_PER_DAY*MAXENLEN_DT_BOSS_BATTLE_DATA )
#define  MAXENLEN_DT_ACTIVITY_ENCOURAGE_INFO	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_ACTIVITY_ENCOURAGE_INFO2	( 1+3*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_ACTIVITY_ENCOURAGE_DATA	( 1+8*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+2+MAX_ACTIVITY_ENCOURAGE_INFO_NUM*MAXENLEN_DT_ACTIVITY_ENCOURAGE_INFO+sizeof(UINT16)+2+MAX_ACTIVITY_ENCOURAGE_INFO_NUM*MAXENLEN_DT_ACTIVITY_ENCOURAGE_INFO2 )
#define  MAXENLEN_DT_RDC_PLAYER_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT32)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_RANDOM_CHALLENGE_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_GET_RDC_NUM*MAXENLEN_DT_RDC_PLAYER_DATA+sizeof(UINT8) )
#define  MAXENLEN_DT_WORSHIP_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_WORSHIP_DATA_LST	( 1+3*sizeof(SIndex)+sizeof(UINT16)+2+MAX_WORSHIP_NUM*MAXENLEN_DT_WORSHIP_DATA+sizeof(UINT8) )
#define  MAXENLEN_DT_CHAPTER_SCORE_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_ACCUMULATED_SCORE_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_SCORE_DATA_LST	( 1+5*sizeof(SIndex)+sizeof(UINT8)+2+MAX_TOWN_PER_SCENE_NUM*MAXENLEN_DT_CHAPTER_SCORE_DATA+sizeof(UINT8)+2+MAX_TOWN_PER_SCENE_NUM*MAXENLEN_DT_ACCUMULATED_SCORE_DATA+sizeof(UINT8) )
#define  MAXENLEN_DT_EQUIP_LEVEL_COMPOSE_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_EQUIP_COMPOSE_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+2+MAX_EQUIPLEVEL_NUM*MAXENLEN_DT_EQUIP_LEVEL_COMPOSE_DATA+sizeof(UINT64)+sizeof(UINT16) )
#define  MAXENLEN_DT_GATHER_SCIENCE_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_BEGBLUE_RES	( 1+7*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16)+2+BEGBLUE_LUCK_PROMPT*sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_CONSUME_BEGBLUE_SMILE_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+BEGBLUE_CONSUME_TIMES*sizeof(UINT16) )
#define  MAXENLEN_DT_BEGBLUE_DATA	( 1+14*sizeof(SIndex)+sizeof(UINT64)+2+BEGBLUE_CLIMB_TOWER_PROMPT*sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+MAXENLEN_DT_BEGBLUE_RES+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+MAXENLEN_DT_CONSUME_BEGBLUE_SMILE_LST )
#define  MAXENLEN_DT_SEND_FLOWER_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_FINALLY_CONTACT_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT64) )
#define  MAXENLEN_DT_FINALLY_CONTACT_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FINALLY_CONTACT_DATA_NUM*MAXENLEN_DT_FINALLY_CONTACT_DATA )
#define  MAXENLEN_DT_RECV_FLOWER_DATA_EX_LOG	( 1+5*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8)+MAXENLEN_DT_RES_NUM_ITEM_DATA )
#define  MAXENLEN_DT_FRIENDS_BASE_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT8)+2+MAX_SEND_FLOWER_DATA_NUM*MAXENLEN_DT_SEND_FLOWER_DATA+sizeof(UINT8)+MAXENLEN_DT_FINALLY_CONTACT_DATA_LST+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+2+MAX_RECV_FLOWER_LOG_LIST_ELEM_EX_NUM*MAXENLEN_DT_RECV_FLOWER_DATA_EX_LOG )
#define  MAXENLEN_DT_RAREITEM_GOODS_INFO	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT64) )
#define  MAXENLEN_DT_RAREITEM_GOODS_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+2+MAX_RAREITEM_RES_NUM*MAXENLEN_DT_RAREITEM_GOODS_INFO+sizeof(UINT64) )
#define  MAXENLEN_DT_GYMNASIUM_SKILL_INFO	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_GYMNASIUM_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GYMNASIUM_SKILL_NUM*MAXENLEN_DT_GYMNASIUM_SKILL_INFO )
#define  MAXENLEN_DT_HUNTING_INFO	( 1+10*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+2+MONSTER_GROUP_NUM*sizeof(UINT16) )
#define  MAXENLEN_DT_SHADE_DATA	( 1+2*sizeof(SIndex)+MAXENLEN_DT_HUNTING_INFO+sizeof(UINT64) )
#define  MAXENLEN_DT_FACTION_HUNTING_SCHEDULE_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_HOT_SPRING_TIME_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_SHADE_TASK_OPEN_MARK	( 1+1*sizeof(SIndex)+sizeof(UINT8) )
#define  MAXENLEN_DT_FACTION_ICON_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_FACTION_COMMON_DATA	( 1+3*sizeof(SIndex)+MAXENLEN_DT_FACTION_HUNTING_SCHEDULE_DATA+MAXENLEN_DT_HOT_SPRING_TIME_DATA+MAXENLEN_DT_FACTION_ICON_DATA )
#define  MAXENLEN_DT_WINE_DATA_CLI	( 1+14*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_PLAYER_POS_INFO	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_OVER_GIVE_WINE_REWARD	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_HOT_SPRING_DATA	( 1+13*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_WINE_DATA_CLI+MAXENLEN_DT_PLAYER_POS_INFO+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_OVER_GIVE_WINE_REWARD+sizeof(UINT8) )
#define  MAXENLEN_DT_LEAVE_FACTION_MARK	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64) )
#define  MAXENLEN_DT_PLAYER_DONATE_INFO	( 1+5*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16) )
#define  MAXENLEN_DT_PLAYER_MARK_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_LEAVE_FACTION_MARK )
#define  MAXENLEN_DT_PLAYER_FACTION_BATTLELOG_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+2+NORMAL_MSG_LEN*sizeof(UINT16)+sizeof(UINT8)+2+FACTION_LOG_LIST_MAX_NUM*sizeof(UINT8) )
#define  MAXENLEN_DT_PLAYER_FACTION_BATTLELOG_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FACTION_BATTLE_LOG_NUM*MAXENLEN_DT_PLAYER_FACTION_BATTLELOG_DATA )
#define  MAXENLEN_DT_HOT_SPRING_EXT_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_PLAYER_FACTION_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_RAREITEM_GOODS_DATA+MAXENLEN_DT_GYMNASIUM_DATA+MAXENLEN_DT_SHADE_DATA+MAXENLEN_DT_HOT_SPRING_DATA+MAXENLEN_DT_PLAYER_FACTION_BATTLELOG_DATA_LIST+MAXENLEN_DT_PLAYER_MARK_DATA+MAXENLEN_DT_PLAYER_DONATE_INFO+sizeof(UINT32)+MAXENLEN_DT_HOT_SPRING_EXT_DATA )
#define  MAXENLEN_DT_PLAYER_TODAY_CONSUME_DATA	( 1+49*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT64)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_RECV_FLOWER_DATA_LOG	( 1+4*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_RECV_FLOWER_LOG_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT32)+2+MAX_RECV_FLOWER_LOG_LIST_ELEM_NUM*MAXENLEN_DT_RECV_FLOWER_DATA_LOG )
#define  MAXENLEN_DT_RELATION_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_RELATION_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT32)+2+MAX_RELATION_LIST_ELEM_NUM*MAXENLEN_DT_RELATION_DATA )
#define  MAXENLEN_DT_RELATION_DATA_EVEN	( 1+2*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_UNREAD_DATA_EVEN	( 1+2*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_DATA_EVEN_LIST	( 1+4*sizeof(SIndex)+sizeof(UINT32)+2+MAX_RELATION_LIST_ELEM_NUM*MAXENLEN_DT_RELATION_DATA_EVEN+sizeof(UINT32)+2+MAX_RELATION_LIST_ELEM_NUM*MAXENLEN_DT_UNREAD_DATA_EVEN )
#define  MAXENLEN_DT_COURAGE_PLAYER_HEROID_DATA	( 1+10*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT16)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_COURAGE_COMMON_PLAYER_BATTLE_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_COURAGE_MEMBER_NUM*MAXENLEN_DT_COURAGE_PLAYER_HEROID_DATA )
#define  MAXENLEN_DT_COURAGE_ITEM_DATA_CLI	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_COURAGE_ITEM_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_BAG_OPEN_NUM*MAXENLEN_DT_COURAGE_ITEM_DATA_CLI )
#define  MAXENLEN_DT_COURAGE_ENCOURAGE_BOX_GROUP_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+MAXENLEN_DT_COURAGE_ITEM_DATA_LIST+sizeof(UINT32) )
#define  MAXENLEN_DT_COURAGE_ENCOURAGE_BOX_DATA2	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVE_ENCOURAGE_BOX_GROUP_NUM*MAXENLEN_DT_COURAGE_ENCOURAGE_BOX_GROUP_DATA )
#define  MAXENLEN_DT_COURAGE_DATA	( 1+18*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_COURAGE_COMMON_PLAYER_BATTLE_DATA+MAXENLEN_DT_INSTANCE_ID+MAXENLEN_DT_BAG_JEWELRY_DATA_LST+sizeof(UINT8) )
#define  MAXENLEN_DT_EQUIP_MASTER_DETAIL	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT32) )
#define  MAXENLEN_DT_MASTER_EXP_BOOK_DETAIL	( 1+1*sizeof(SIndex)+sizeof(UINT8) )
#define  MAXENLEN_DT_EQUIP_MASTER	( 1+5*sizeof(SIndex)+2+EQUIP_KIND_COUNT*MAXENLEN_DT_EQUIP_MASTER_DETAIL+sizeof(UINT8)+2+EQUIP_KIND_COUNT*MAXENLEN_DT_MASTER_EXP_BOOK_DETAIL+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_FRIENDS_DATA	( 1+4*sizeof(SIndex)+MAXENLEN_DT_FRIENDS_BASE_DATA+MAXENLEN_DT_RECV_FLOWER_LOG_LIST+MAXENLEN_DT_RELATION_DATA_LIST+MAXENLEN_DT_DATA_EVEN_LIST )
#define  MAXENLEN_DT_INSTANCE_DB_DATA	( 1+9*sizeof(SIndex)+MAXENLEN_DT_INSTANCE_DATA_LIST+MAXENLEN_DT_INSTANCE_DATA_LIST+MAXENLEN_DT_INSTANCE_DATA_LIST+MAXENLEN_DT_INSTANCE_BATTLE_DATA+MAXENLEN_DT_INSTANCE_BATTLE_DATA+MAXENLEN_DT_INSTANCE_BATTLE_DATA+MAXENLEN_DT_INSTANCE_DATA_LIST+MAXENLEN_DT_INSTANCE_DATA_LIST+MAXENLEN_DT_INSTANCE_BATTLE_DATA )
#define  MAXENLEN_DT_RACE_DATA	( 1+2*sizeof(SIndex)+MAXENLEN_DT_RACE_BASE_DATA+MAXENLEN_DT_RACE_BATTLELOG_DATA_LIST )
#define  MAXENLEN_DT_PLUNDER_DATA	( 1+3*sizeof(SIndex)+MAXENLEN_DT_PLUNDER_BASE_DATA+MAXENLEN_DT_PLUNDER_BATTLELOG_DATA_LIST+MAXENLEN_DT_CAPTURE_DATA_LIST )
#define  MAXENLEN_DT_YABIAO_DATA	( 1+2*sizeof(SIndex)+MAXENLEN_DT_YABIAO_BASE_DATA+MAXENLEN_DT_YABIAO_BATTLELOG_DATA_LIST )
#define  MAXENLEN_DT_BOSS_BATTLE_PLAYER_DATA_INFO	( 1+2*sizeof(SIndex)+MAXENLEN_DT_BOSS_BATTLE_PLAYER_DATA+MAXENLEN_DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST )
#define  MAXENLEN_DT_EXCHANGE_RESULT_LOG	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT32) )
#define  MAXENLEN_DT_GAMBLE_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT32) )
#define  MAXENLEN_DT_GVG_GIFT_REWARD_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+2+MAX_FACTION_NUM*sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_GIFT_REWARD_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_GIFT_NUM*MAXENLEN_DT_GVG_GIFT_REWARD_DATA )
#define  MAXENLEN_DT_GVG_GIFT_KEY_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_GIFT_NUM*sizeof(UINT64) )
#define  MAXENLEN_DT_PLAYER_GVG_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GAMBLE_NUM*MAXENLEN_DT_GAMBLE_DATA+MAXENLEN_DT_GVG_GIFT_KEY_LST_DATA+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_FORMATION_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_FORMATION_PLAYER_CNT*sizeof(UINT32) )
#define  MAXENLEN_DT_FACTION_BASE_DATA_CLI2	( 1+12*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+2+USERNAME_LEN*sizeof(UINT16)+2+MAX_FACTION_NUM*sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64)+2+MAX_FACTION_DESC_NUM*sizeof(UINT16)+2+ZONENAME_LEN*sizeof(UINT16) )
#define  MAXENLEN_DT_GAMBLE_FACTION_INFO	( 1+4*sizeof(SIndex)+MAXENLEN_DT_FACTION_BASE_DATA_CLI2+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_ROUND	( 1+2*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_FACTION_GVG_SINGLE_LOG	( 1+6*sizeof(SIndex)+MAXENLEN_DT_GVG_ROUND+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT16)+MAXENLEN_DT_GAMBLE_FACTION_INFO+MAXENLEN_DT_GAMBLE_FACTION_INFO )
#define  MAXENLEN_DT_FACTION_SIMPLE_GVG_LOG	( 1+7*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+MAXENLEN_DT_GVG_ROUND+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_FACTION_GVG_LOG_LIST	( 1+3*sizeof(SIndex)+sizeof(UINT16)+2+MAX_GVG_LOG_CNT*MAXENLEN_DT_FACTION_GVG_SINGLE_LOG+sizeof(UINT16) )
#define  MAXENLEN_DT_FACTION_SIMPLE_GVG_LOG_LIST	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+2+MAX_GVG_SIMPLE_LOG_CNT*MAXENLEN_DT_FACTION_SIMPLE_GVG_LOG )
#define  MAXENLEN_DT_FACTION_LIST_SIMPLE_GVG_LOG	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_GVG_ARENA_FACTION_CNT*MAXENLEN_DT_FACTION_SIMPLE_GVG_LOG_LIST )
#define  MAXENLEN_DT_GVG_LOG_FACTION_INFO	( 1+8*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+2+MAX_FACTION_NUM*sizeof(UINT16)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT16) )
#define  MAXENLEN_DT_FACTION_GVG_LOG	( 1+2*sizeof(SIndex)+MAXENLEN_DT_GVG_LOG_FACTION_INFO+MAXENLEN_DT_FACTION_GVG_LOG_LIST )
#define  MAXENLEN_DT_FACTION_GVG_DATA	( 1+4*sizeof(SIndex)+MAXENLEN_DT_FACTION_GVG_LOG_LIST+MAXENLEN_DT_GVG_FORMATION_DATA+sizeof(UINT64)+sizeof(UINT64) )
#define  MAXENLEN_DT_GVG_FORMATION_PLAYER_INFO	( 1+4*sizeof(SIndex)+sizeof(UINT32)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_FORMATION_PLAYER_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_FORMATION_PLAYER_CNT*MAXENLEN_DT_GVG_FORMATION_PLAYER_INFO )
#define  MAXENLEN_DT_DOORSTRIBUTE_LEVEL_DATA	( 1+6*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT16) )
#define  MAXENLEN_DT_DOORSTRIBUTE_LEVE_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+DT_FACTION_PLAYER_NUM*MAXENLEN_DT_DOORSTRIBUTE_LEVEL_DATA )
#define  MAXENLEN_DT_FACTION_MEMBER_INFO	( 1+7*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT16)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_FACTION_MEMBER_INFO_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+DT_FACTION_PLAYER_NUM*MAXENLEN_DT_FACTION_MEMBER_INFO )
#define  MAXENLEN_DT_GVG_FACTION	( 1+10*sizeof(SIndex)+sizeof(UINT16)+MAXENLEN_DT_FACTION_BASE_DATA_CLI2+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+MAXENLEN_DT_FACTION_MEMBER_INFO_LIST )
#define  MAXENLEN_DT_PK_FACTION	( 1+3*sizeof(SIndex)+MAXENLEN_DT_GVG_FACTION+MAXENLEN_DT_GVG_FORMATION_DATA+MAXENLEN_DT_GVG_FORMATION_PLAYER_LIST )
#define  MAXENLEN_DT_PVP_VIDEO_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT64)+MAXENLEN_DT_BATTLE_DATA3 )
#define  MAXENLEN_DT_GVG_MVP	( 1+6*sizeof(SIndex)+sizeof(UINT8)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_MVP_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_MVP_CNT*MAXENLEN_DT_GVG_MVP )
#define  MAXENLEN_DT_GVG_VIDEO_FACTION	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_FACTION_NUM*sizeof(UINT16)+MAXENLEN_DT_GVG_FORMATION_PLAYER_LIST )
#define  MAXENLEN_DT_GVG_PK_VIDEO	( 1+5*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_EMPTY_HP_VIDEO )
#define  MAXENLEN_DT_GVG_PK_VIDEO_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_PK_VIDEO_CNT*MAXENLEN_DT_GVG_PK_VIDEO )
#define  MAXENLEN_DT_GVG_VIDEO	( 1+8*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+MAXENLEN_DT_GVG_ROUND+MAXENLEN_DT_GVG_VIDEO_FACTION+MAXENLEN_DT_GVG_VIDEO_FACTION+MAXENLEN_DT_FINAL_ROUND_BATTLE_OBJ_INFO+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_ZONE_MEMBER_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_ARENA_ZONE_CNT*sizeof(UINT32) )
#define  MAXENLEN_DT_ZONE_FACTION_ID	( 1+2*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_DIFF_ZONE_FACTION_ID_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+GVG_16_TO_8_FACTION_CNT*MAXENLEN_DT_ZONE_FACTION_ID )
#define  MAXENLEN_DT_ONE_ZONE_FACTION_ID_LIST	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+2+GVG_16_TO_8_FACTION_CNT*sizeof(UINT32) )
#define  MAXENLEN_DT_ZONE_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_ARENA_ZONE_CNT*MAXENLEN_DT_ONE_ZONE_FACTION_ID_LIST )
#define  MAXENLEN_DT_ZONE_ID_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_ARENA_ZONE_CNT*sizeof(UINT16) )
#define  MAXENLEN_DT_FACTION_LIST_GVG_LOG	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+GVG_16_TO_8_FACTION_CNT*MAXENLEN_DT_FACTION_GVG_LOG )
#define  MAXENLEN_DT_VIDEO_ID	( 1+1*sizeof(SIndex)+sizeof(UINT64) )
#define  MAXENLEN_DT_FINAL_WAR_EACH_ROUND_FACTION_INFO	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_FINAL_WAR_ROUND_INFO	( 1+3*sizeof(SIndex)+sizeof(UINT8)+2+GVG_FINAL_WAR_FACTION_CNT*sizeof(UINT8)+2+GVG_FINAL_WAR_FACTION_CNT*MAXENLEN_DT_FINAL_WAR_EACH_ROUND_FACTION_INFO )
#define  MAXENLEN_DT_16_TO_8_TO_4_WAR_INFO	( 1+11*sizeof(SIndex)+sizeof(UINT8)+2+GVG_16_TO_8_FACTION_CNT*MAXENLEN_DT_GVG_FACTION+sizeof(UINT8)+2+GVG_16_TO_8_WIN_CNT*sizeof(UINT8)+sizeof(UINT8)+2+GVG_8_TO_4_WIN_CNT*sizeof(UINT8)+2+GVG_16_TO_8_WIN_CNT*sizeof(UINT64)+2+GVG_8_TO_4_WIN_CNT*sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_FINAL_WAR_INFO	( 1+6*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+2+GVG_FINAL_WAR_FACTION_CNT*MAXENLEN_DT_GVG_FACTION+sizeof(UINT8)+2+GVG_FINAL_WAR_FACTION_CNT*sizeof(UINT8)+2+GVG_FINAL_WAR_FACTION_CNT*MAXENLEN_DT_FINAL_WAR_ROUND_INFO )
#define  MAXENLEN_DT_GVG_STAGE_FINISH_FLAG_LIST	( 1+1*sizeof(SIndex)+2+30*sizeof(UINT8) )
#define  MAXENLEN_DT_GROUP_ZONE	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+2*sizeof(UINT16) )
#define  MAXENLEN_DT_GROUP_ZONE_ID_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_GROUP_NUM*MAXENLEN_DT_GROUP_ZONE )
#define  MAXENLEN_DT_WAR_16_TO_8_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_GROUP_NUM*MAXENLEN_DT_16_TO_8_TO_4_WAR_INFO )
#define  MAXENLEN_DT_GVG_ARENA_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_ZONE_ID_LIST+MAXENLEN_DT_GROUP_ZONE_ID_LIST+MAXENLEN_DT_WAR_16_TO_8_LIST+MAXENLEN_DT_FINAL_WAR_INFO+MAXENLEN_DT_FACTION_LIST_SIMPLE_GVG_LOG+MAXENLEN_DT_GVG_STAGE_FINISH_FLAG_LIST )
#define  MAXENLEN_DT_ZONE_FACTION_MEMBER	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+2+MAX_GVG_TOP_FACTION_CNT*sizeof(UINT32) )
#define  MAXENLEN_DT_GVG_ACTIVITY_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_GVG_LOCAL_ACTIVITY_DATA	( 1+5*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_GVG_ARENA_DATA )
#define  MAXENLEN_DT_TSTRING_MSG	( 1+1*sizeof(SIndex)+2+NORMAL_MSG_LEN*sizeof(UINT16) )
#define  MAXENLEN_DT_BATTLE_LOG_MSG_DATA	( 1+8*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+2+MAX_BATTLE_LOG_PARAM_NUM*sizeof(UINT64)+sizeof(UINT8)+2+MAX_BATTLE_LOG_PARAM_STR*MAXENLEN_DT_TSTRING_MSG )
#define  MAXENLEN_DT_BATTLE_LOG_MSG_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_BATTLE_LOG_NUM*MAXENLEN_DT_BATTLE_LOG_MSG_DATA )
#define  MAXENLEN_DT_SOUL_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_SOUL_BAG_NUM*MAXENLEN_DT_SOUL_DATA )
#define  MAXENLEN_DT_PLAYER_SOUL_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_SOUL_LST_DATA+sizeof(UINT64)+2+MAX_SOUL_PRODUCT_TYPE*sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+MAXENLEN_DT_SOUL_POTENCY_LST_DATA )
#define  MAXENLEN_DT_MEDAL_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT8) )
#define  MAXENLEN_DT_MEDAL_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_MEDAL_NUM*MAXENLEN_DT_MEDAL_DATA )
#define  MAXENLEN_DT_MEDAL_BASE_DATA	( 1+23*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64) )
#define  MAXENLEN_DT_PLAYER_MEDAL_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_MEDAL_LST_DATA+sizeof(UINT64)+MAXENLEN_DT_MEDAL_BASE_DATA )
#define  MAXENLEN_DT_PET_WASHQUALITY_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_PET_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT32)+2+MAX_PET_NAME_LENGTH*sizeof(UINT16)+2+MAX_PET_FEED_FRUIT_CNT*sizeof(UINT8)+sizeof(UINT8)+2+MAX_PET_WASH_PSYCHIC_CELL_CNT*MAXENLEN_DT_PET_WASHQUALITY_DATA )
#define  MAXENLEN_DT_NEIDAN_DATA	( 1+4*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_PET_NEIDAN_DATA_LST	( 1+1*sizeof(SIndex)+2+MAX_PET_NEIDAN_NUM*MAXENLEN_DT_NEIDAN_DATA )
#define  MAXENLEN_DT_PLAYER_NEIDAN_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_PET_NUM*MAXENLEN_DT_PET_NEIDAN_DATA_LST )
#define  MAXENLEN_DT_NEIDAN_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_NEI_DAN_BAG_NUM*MAXENLEN_DT_NEIDAN_DATA )
#define  MAXENLEN_DT_PET_DATA_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_PET_NUM*MAXENLEN_DT_PET_DATA )
#define  MAXENLEN_DT_PET_CALL_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT32) )
#define  MAXENLEN_DT_PET_CALL_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_PET_NUM*MAXENLEN_DT_PET_CALL_DATA )
#define  MAXENLEN_DT_HERO_HP_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_HERO_HP_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FORMATION_IDX_NUM*MAXENLEN_DT_HERO_HP_DATA )
#define  MAXENLEN_DT_PLAYER_PET_DATA	( 1+17*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_PET_DATA_LIST+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+MAXENLEN_DT_PET_CALL_LST_DATA+sizeof(UINT16)+sizeof(UINT8)+MAXENLEN_DT_PLAYER_NEIDAN_DATA_LST+MAXENLEN_DT_NEIDAN_DATA_LST+MAXENLEN_DT_HERO_HP_DATA_LST )
#define  MAXENLEN_DT_PLAYER_NOPVP_DATA	( 1+49*sizeof(SIndex)+MAXENLEN_DT_PLAYER_BASE_DATA+MAXENLEN_DT_HERO_DATA_LIST+MAXENLEN_DT_BAG_EQUIP_DATA_LST+MAXENLEN_DT_BAG_GOODS_DATA_LST+MAXENLEN_DT_BUILD_DATA_LIST+MAXENLEN_DT_TASK_DATA_LIST+MAXENLEN_DT_LOCALE_DATA+MAXENLEN_DT_STATE_DATA+MAXENLEN_DT_ONLINE_ENCOURAGE_RECORD_DATA+MAXENLEN_DT_LOGIN_ENCOURAGE_RECORD_DATA+MAXENLEN_DT_INSTANCE_DB_DATA+MAXENLEN_DT_MONEY_TREE_DATA+MAXENLEN_DT_ONHOOK_RCD_DATA+MAXENLEN_DT_JINGJIE_DATA+MAXENLEN_DT_PHYSTRENGTH_DATA+MAXENLEN_DT_FEW_PARAM_DATA+MAXENLEN_DT_CROP_DATA+MAXENLEN_DT_SCIENCE_TREE_DATA+MAXENLEN_DT_NEW_FORMATION_DATA+2+MAX_ORDER_ID_LEN*sizeof(UINT8)+MAXENLEN_DT_EAT_BREAD_DATA+MAXENLEN_DT_YABIAO_DATA+2+MAX_TOKEN_NUM*sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT64)+MAXENLEN_DT_CLIMB_TOWER_DATA+MAXENLEN_DT_AWAKEN_DATA+MAXENLEN_DT_VIP_EXT_DATA+MAXENLEN_DT_LUAACTIVITY_RECORD_LIST_DATA+MAXENLEN_DT_COLLECT_GAS_DATA+MAXENLEN_DT_BOSS_BATTLE_PLAYER_DATA_INFO+MAXENLEN_DT_ACTIVITY_ENCOURAGE_DATA+MAXENLEN_DT_RANDOM_CHALLENGE_DATA+MAXENLEN_DT_WORSHIP_DATA_LST+MAXENLEN_DT_SCORE_DATA_LST+MAXENLEN_DT_EQUIP_COMPOSE_DATA+MAXENLEN_DT_GATHER_SCIENCE_DATA+MAXENLEN_DT_BEGBLUE_DATA+MAXENLEN_DT_PLAYER_TODAY_CONSUME_DATA+MAXENLEN_DT_FRIENDS_DATA+MAXENLEN_DT_PLAYER_FACTION_DATA+MAXENLEN_DT_COURAGE_DATA+MAXENLEN_DT_EQUIP_MASTER+MAXENLEN_DT_EXCHANGE_RESULT_LOG+MAXENLEN_DT_BAG_JEWELRY_DATA_LST+MAXENLEN_DT_PLAYER_GVG_DATA+MAXENLEN_DT_PLAYER_SOUL_DATA+MAXENLEN_DT_PLAYER_MEDAL_DATA+MAXENLEN_DT_PLAYER_PET_DATA )
#define  MAXENLEN_DT_PLAYER_PVP_DATA	( 1+3*sizeof(SIndex)+MAXENLEN_DT_RACE_DATA+MAXENLEN_DT_PLUNDER_DATA+MAXENLEN_DT_ENEMY_DATA_LIST )
#define  MAXENLEN_DT_PLAYER_DATA	( 1+2*sizeof(SIndex)+MAXENLEN_DT_PLAYER_NOPVP_DATA+MAXENLEN_DT_PLAYER_PVP_DATA )
#define  MAXENLEN_DT_EXT_FUNC_PARAM	( 1+3*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT32) )
#define  MAXENLEN_DT_EXT_FUNC_PARAM_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_EXT_FUN_NUM*MAXENLEN_DT_EXT_FUNC_PARAM )
#define  MAXENLEN_DT_CONTINUE_KILL_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FACTION_BATTLE_NUM*sizeof(UINT64) )
#define  MAXENLEN_DT_FACTION_PLAYER_DATA	( 1+11*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+MAXENLEN_DT_PLAYER_FACTION_BATTLELOG_DATA_LIST+sizeof(UINT64)+MAXENLEN_DT_CONTINUE_KILL_DATA )
#define  MAXENLEN_DT_FACTION_PLAYER_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT32)+2+DT_FACTION_PLAYER_NUM*MAXENLEN_DT_FACTION_PLAYER_DATA )
#define  MAXENLEN_DT_FACTION_LOG_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+2+FACTION_LOG_LIST_MAX_NUM*sizeof(UINT32)+sizeof(UINT64) )
#define  MAXENLEN_DT_FACTION_LOG_DATA_LST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_FACTION_LOG_NUM*MAXENLEN_DT_FACTION_LOG_DATA )
#define  MAXENLEN_DT_FACTION_BASE_DATA	( 1+16*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+2+MAX_FACTION_NUM*sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT32)+2+MAX_FACTION_DESC_NUM*sizeof(UINT16)+2+MAX_FACTION_DESC_NUM*sizeof(UINT16)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT64) )
#define  MAXENLEN_DT_FACTION_DATA	( 1+9*sizeof(SIndex)+MAXENLEN_DT_FACTION_BASE_DATA+MAXENLEN_DT_FACTION_PLAYER_DATA_LST+MAXENLEN_DT_FACTION_LOG_DATA_LST+MAXENLEN_DT_FACTION_COMMON_DATA+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT64)+sizeof(UINT8)+MAXENLEN_DT_FACTION_GVG_DATA )
#define  MAXENLEN_DT_FACTION_AUTHORITY	( 1+12*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_FACTION_AUTHORITY_EX	( 1+13*sizeof(SIndex)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8) )
#define  MAXENLEN_DT_COURAGE_PLAYER_DATA	( 1+10*sizeof(SIndex)+2+USERNAME_LEN*sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_COURAGE_GROUP_DATA	( 1+9*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+2+MAX_COURAGE_GROUP_PLAYER_NUM*MAXENLEN_DT_COURAGE_PLAYER_DATA+sizeof(UINT32)+sizeof(UINT16)+MAXENLEN_DT_INSTANCE_ID+sizeof(UINT16) )
#define  MAXENLEN_DT_COURAGE_GROUP_DATA_LST	( 1+6*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT64)+sizeof(UINT8)+sizeof(UINT16)+2+MAX_COURAGE_GROUP_NUM*MAXENLEN_DT_COURAGE_GROUP_DATA )
#define  MAXENLEN_DT_FACTION_APPLAY_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_FACTION_APPLAY_LST_DATA	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_FACTION_APPLAY_NUM*MAXENLEN_DT_FACTION_APPLAY_DATA )
#define  MAXENLEN_DT_SIMPLE_FACTION_INFO	( 1+4*sizeof(SIndex)+MAXENLEN_DT_FACTION_BASE_DATA_CLI2+sizeof(UINT32)+sizeof(UINT16)+sizeof(UINT8) )
#define  MAXENLEN_DT_SIMPLE_FACTION_LST_INFO	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_RANK_DISPLAY*MAXENLEN_DT_SIMPLE_FACTION_INFO )
#define  MAXENLEN_DT_GVG_FACTION_RANK_DATA	( 1+7*sizeof(SIndex)+sizeof(UINT16)+MAXENLEN_DT_FACTION_BASE_DATA_CLI2+sizeof(UINT64)+sizeof(UINT32)+sizeof(UINT8)+sizeof(UINT8)+sizeof(UINT16) )
#define  MAXENLEN_DT_GVG_FACTION_RANK_LST_DATA	( 1+3*sizeof(SIndex)+sizeof(UINT16)+2+MAX_RANK_DISPLAY*MAXENLEN_DT_GVG_FACTION_RANK_DATA+MAXENLEN_DT_GVG_FACTION )
#define  MAXENLEN_DT_FACTION_BATTLE_RESULT	( 1+3*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT32) )
#define  MAXENLEN_DT_FACTION_BATTLE_RESULT_LST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_FACTION_BATTLE_NUM*MAXENLEN_DT_FACTION_BATTLE_RESULT )
#define  MAXENLEN_DT_LOCAL_WAR_FACTION_SEED	( 1+2*sizeof(SIndex)+sizeof(UINT32)+sizeof(UINT8) )
#define  MAXENLEN_DT_LOCAL_WAR_FACTION_SEED_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT16)+2+MAX_FACTION_APPLAY_NUM*sizeof(UINT32) )
#define  MAXENLEN_DT_CHAOS_WAR	( 1+3*sizeof(SIndex)+sizeof(UINT8)+MAXENLEN_DT_SIMPLE_FACTION_LST_INFO+MAXENLEN_DT_LOCAL_WAR_FACTION_SEED_LIST )
#define  MAXENLEN_DT_GVG_BUILD_DATA	( 1+13*sizeof(SIndex)+MAXENLEN_DT_FACTION_APPLAY_LST_DATA+MAXENLEN_DT_GVG_FACTION_RANK_LST_DATA+MAXENLEN_DT_SIMPLE_FACTION_LST_INFO+MAXENLEN_DT_CHAOS_WAR+MAXENLEN_DT_16_TO_8_TO_4_WAR_INFO+MAXENLEN_DT_WAR_16_TO_8_LIST+MAXENLEN_DT_FINAL_WAR_INFO+MAXENLEN_DT_FACTION_LIST_SIMPLE_GVG_LOG+MAXENLEN_DT_GVG_STAGE_FINISH_FLAG_LIST+sizeof(UINT8)+sizeof(UINT16)+sizeof(UINT16)+sizeof(UINT64) )
#define  MAXENLEN_DT_GVG_FACTION_LIST	( 1+2*sizeof(SIndex)+sizeof(UINT8)+2+MAX_GVG_FACTION_NUM*MAXENLEN_DT_GVG_FACTION )
/*DDefine MaxEnLen MAC End*/


enum EN_ProtoCommonData_MessageID
{
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodeDT_RES_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RES_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RES_DATA( DT_RES_DATA &data );
INT32 EncodeDT_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ITEM_DATA( DT_ITEM_DATA &data );
INT32 EncodeDT_RES_NUM_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RES_NUM_ITEM_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RES_NUM_ITEM_DATA( DT_RES_NUM_ITEM_DATA &data );
INT32 EncodeDT_GUIDE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GUIDE_RECORD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GUIDE_RECORD_DATA( DT_GUIDE_RECORD_DATA &data );
INT32 EncodeDT_PLAYER_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_BASE_DATA( DT_PLAYER_BASE_DATA &data );
INT32 EncodeDT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ATTRIBUTE( DT_BATTLE_ATTRIBUTE &data );
INT32 EncodeDT_BATTLE_ATTRIBUTE2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTRIBUTE2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ATTRIBUTE2( DT_BATTLE_ATTRIBUTE2 &data );
INT32 EncodeDT_BATTLE_BASE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_BASE_ATTRIBUTE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_BASE_ATTRIBUTE( DT_BATTLE_BASE_ATTRIBUTE &data );
INT32 EncodeDT_HIDE_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HIDE_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HIDE_BATTLE_ATTRIBUTE( DT_HIDE_BATTLE_ATTRIBUTE &data );
INT32 EncodeDT_EXT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EXT_BATTLE_ATTRIBUTE( DT_EXT_BATTLE_ATTRIBUTE &data );
INT32 EncodeDT_HERO_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_UPDATE_ATTR_DATA( DT_HERO_UPDATE_ATTR_DATA &data );
INT32 EncodeDT_HERO_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_ATTR_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_ATTR_DATA( DT_HERO_ATTR_DATA &data );
INT32 EncodeDT_SPECIAL_EFFECT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SPECIAL_EFFECT_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SPECIAL_EFFECT_DATA( DT_SPECIAL_EFFECT_DATA &data );
INT32 EncodeDT_SOUL_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_ATTR_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SOUL_ATTR_DATA( DT_SOUL_ATTR_DATA &data );
INT32 EncodeDT_SOUL_POTENCY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_POTENCY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SOUL_POTENCY_DATA( DT_SOUL_POTENCY_DATA &data );
INT32 EncodeDT_SOUL_POTENCY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_POTENCY_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SOUL_POTENCY_LST_DATA( DT_SOUL_POTENCY_LST_DATA &data );
INT32 EncodeDT_SOUL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SOUL_DATA( DT_SOUL_DATA &data );
INT32 EncodeDT_HERO_SOUL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_SOUL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_SOUL_DATA( DT_HERO_SOUL_DATA &data );
INT32 EncodeDT_HERO_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_BASE_DATA( DT_HERO_BASE_DATA &data );
INT32 EncodeDT_XIANGQIAN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_XIANGQIAN_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_XIANGQIAN_DATA( DT_XIANGQIAN_DATA &data );
INT32 EncodeDT_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EQUIP_DATA( DT_EQUIP_DATA &data );
INT32 EncodeDT_HERO_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_EQUIP_DATA_LST( DT_HERO_EQUIP_DATA_LST &data );
INT32 EncodeDT_BAG_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BAG_EQUIP_DATA_LST( DT_BAG_EQUIP_DATA_LST &data );
INT32 EncodeDT_GOODS_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GOODS_DATA( DT_GOODS_DATA &data );
INT32 EncodeDT_BAG_GOODS_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_GOODS_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BAG_GOODS_DATA_LST( DT_BAG_GOODS_DATA_LST &data );
INT32 EncodeDT_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DRUG_DATA( DT_DRUG_DATA &data );
INT32 EncodeDT_DRUG_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DRUG_DATA_LST( DT_DRUG_DATA_LST &data );
INT32 EncodeDT_GODWEAPON_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GODWEAPON_DATA( DT_GODWEAPON_DATA &data );
INT32 EncodeDT_ATTACK_RANG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_RANG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_RANG_DATA( DT_ATTACK_RANG_DATA &data );
INT32 EncodeDT_SKILL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SKILL_DATA( DT_SKILL_DATA &data );
INT32 EncodeDT_SKILL_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SKILL_DATA_LST( DT_SKILL_DATA_LST &data );
INT32 EncodeDT_STUDY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STUDY_DATA( DT_STUDY_DATA &data );
INT32 EncodeDT_AWAKEN_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_AWAKEN_BASE_DATA( DT_AWAKEN_BASE_DATA &data );
INT32 EncodeDT_AWAKEN_BASE_DATA1(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_BASE_DATA1(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_AWAKEN_BASE_DATA1( DT_AWAKEN_BASE_DATA1 &data );
INT32 EncodeDT_AWAKEN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_AWAKEN_DATA( DT_AWAKEN_DATA &data );
INT32 EncodeDT_AWAKEN_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_AWAKEN_DATA_LST( DT_AWAKEN_DATA_LST &data );
INT32 EncodeDT_ABSORB_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ABSORB_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ABSORB_DATA_LST( DT_ABSORB_DATA_LST &data );
INT32 EncodeDT_ATTR_INC_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTR_INC_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTR_INC_DATA( DT_ATTR_INC_DATA &data );
INT32 EncodeDT_BATTLE_ATTR_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTR_LST_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ATTR_LST_INFO( DT_BATTLE_ATTR_LST_INFO &data );
INT32 EncodeDT_BATTLE_ATTR_EXT_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTR_EXT_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ATTR_EXT_INFO( DT_BATTLE_ATTR_EXT_INFO &data );
INT32 EncodeDT_BATTLE_ATTR_EXT_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTR_EXT_LST_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ATTR_EXT_LST_INFO( DT_BATTLE_ATTR_EXT_LST_INFO &data );
INT32 EncodeDT_JEWELRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_JEWELRY_DATA( DT_JEWELRY_DATA &data );
INT32 EncodeDT_JEWELRY_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_JEWELRY_DATA_LST( DT_JEWELRY_DATA_LST &data );
INT32 EncodeDT_BAG_JEWELRY_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_JEWELRY_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BAG_JEWELRY_DATA_LST( DT_BAG_JEWELRY_DATA_LST &data );
INT32 EncodeDT_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_DATA( DT_HERO_DATA &data );
INT32 EncodeDT_HERO_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_DATA_LIST( DT_HERO_DATA_LIST &data );
INT32 EncodeDT_BUILD_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILD_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BUILD_BASE_DATA( DT_BUILD_BASE_DATA &data );
INT32 EncodeDT_BUILD_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILD_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BUILD_DATA_LIST( DT_BUILD_DATA_LIST &data );
INT32 EncodeDT_INSTANCE_ID(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_ID(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_INSTANCE_ID( DT_INSTANCE_ID &data );
INT32 EncodeDT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_INSTANCE_DATA( DT_INSTANCE_DATA &data );
INT32 EncodeDT_INSTANCE_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_INSTANCE_DATA_LIST( DT_INSTANCE_DATA_LIST &data );
INT32 EncodeDT_SCIENCE_ATTREXT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_ATTREXT(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SCIENCE_ATTREXT( DT_SCIENCE_ATTREXT &data );
INT32 EncodeDT_SCIENCE_ATTREXT_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_ATTREXT_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SCIENCE_ATTREXT_LIST( DT_SCIENCE_ATTREXT_LIST &data );
INT32 EncodeDT_CROWN_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROWN_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CROWN_TASK_CONDITION( DT_CROWN_TASK_CONDITION &data );
INT32 EncodeDT_BUILDUPGRADE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILDUPGRADE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BUILDUPGRADE_TASK_CONDITION( DT_BUILDUPGRADE_TASK_CONDITION &data );
INT32 EncodeDT_RECRUITHERO_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUITHERO_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RECRUITHERO_TASK_CONDITION( DT_RECRUITHERO_TASK_CONDITION &data );
INT32 EncodeDT_CROWN_HEROCOLOR_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROWN_HEROCOLOR_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CROWN_HEROCOLOR_CONDITION( DT_CROWN_HEROCOLOR_CONDITION &data );
INT32 EncodeDT_CROWN_HEROUPGRADE_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROWN_HEROUPGRADE_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CROWN_HEROUPGRADE_CONDITION( DT_CROWN_HEROUPGRADE_CONDITION &data );
INT32 EncodeDT_FIRSTPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FIRSTPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FIRSTPASSINSTANCE_TASK_CONDITION( DT_FIRSTPASSINSTANCE_TASK_CONDITION &data );
INT32 EncodeDT_SCOREPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCOREPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SCOREPASSINSTANCE_TASK_CONDITION( DT_SCOREPASSINSTANCE_TASK_CONDITION &data );
INT32 EncodeDT_TIMESPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TIMESPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_TIMESPASSINSTANCE_TASK_CONDITION( DT_TIMESPASSINSTANCE_TASK_CONDITION &data );
INT32 EncodeDT_KILLMONSTERINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_KILLMONSTERINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_KILLMONSTERINSTANCE_TASK_CONDITION( DT_KILLMONSTERINSTANCE_TASK_CONDITION &data );
INT32 EncodeDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION( DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION &data );
INT32 EncodeDT_STRENGTHENEQUIPNUM_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHENEQUIPNUM_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STRENGTHENEQUIPNUM_TASK_CONDITION( DT_STRENGTHENEQUIPNUM_TASK_CONDITION &data );
INT32 EncodeDT_ITEMCOLLECT_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEMCOLLECT_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ITEMCOLLECT_TASK_CONDITION( DT_ITEMCOLLECT_TASK_CONDITION &data );
INT32 EncodeDT_ACTIVATEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVATEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ACTIVATEGODWEAPON_TASK_CONDITION( DT_ACTIVATEGODWEAPON_TASK_CONDITION &data );
INT32 EncodeDT_UPGRADEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UPGRADEGODWEAPON_TASK_CONDITION( DT_UPGRADEGODWEAPON_TASK_CONDITION &data );
INT32 EncodeDT_UPGRADEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UPGRADEDRUG_TASK_CONDITION( DT_UPGRADEDRUG_TASK_CONDITION &data );
INT32 EncodeDT_CHALLENGE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHALLENGE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CHALLENGE_TASK_CONDITION( DT_CHALLENGE_TASK_CONDITION &data );
INT32 EncodeDT_PLUNDER_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLUNDER_TASK_CONDITION( DT_PLUNDER_TASK_CONDITION &data );
INT32 EncodeDT_DRESSSKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRESSSKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DRESSSKILL_TASK_CONDITION( DT_DRESSSKILL_TASK_CONDITION &data );
INT32 EncodeDT_DRESSEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRESSEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DRESSEQUIP_TASK_CONDITION( DT_DRESSEQUIP_TASK_CONDITION &data );
INT32 EncodeDT_UPGRADEEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UPGRADEEQUIP_TASK_CONDITION( DT_UPGRADEEQUIP_TASK_CONDITION &data );
INT32 EncodeDT_USEEXPRIENCEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_USEEXPRIENCEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_USEEXPRIENCEDRUG_TASK_CONDITION( DT_USEEXPRIENCEDRUG_TASK_CONDITION &data );
INT32 EncodeDT_MELT_EQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MELT_EQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MELT_EQUIP_TASK_CONDITION( DT_MELT_EQUIP_TASK_CONDITION &data );
INT32 EncodeDT_COMPOSEGOOD_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COMPOSEGOOD_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COMPOSEGOOD_TASK_CONDITION( DT_COMPOSEGOOD_TASK_CONDITION &data );
INT32 EncodeDT_ELITEINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITEINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ELITEINSTANCE_TASK_CONDITION( DT_ELITEINSTANCE_TASK_CONDITION &data );
INT32 EncodeDT_UPGRADSCIENCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADSCIENCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UPGRADSCIENCE_TASK_CONDITION( DT_UPGRADSCIENCE_TASK_CONDITION &data );
INT32 EncodeDT_STRENGTHATTACK_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHATTACK_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STRENGTHATTACK_TASK_CONDITION( DT_STRENGTHATTACK_TASK_CONDITION &data );
INT32 EncodeDT_STRENGTHLIFE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHLIFE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STRENGTHLIFE_TASK_CONDITION( DT_STRENGTHLIFE_TASK_CONDITION &data );
INT32 EncodeDT_CROP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CROP_TASK_CONDITION( DT_CROP_TASK_CONDITION &data );
INT32 EncodeDT_UPGRADESKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADESKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UPGRADESKILL_TASK_CONDITION( DT_UPGRADESKILL_TASK_CONDITION &data );
INT32 EncodeDT_UPGRADEJINGJIE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEJINGJIE_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UPGRADEJINGJIE_TASK_CONDITION( DT_UPGRADEJINGJIE_TASK_CONDITION &data );
INT32 EncodeDT_MOSAICGEM_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MOSAICGEM_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MOSAICGEM_TASK_CONDITION( DT_MOSAICGEM_TASK_CONDITION &data );
INT32 EncodeDT_CLIMBTOWER_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLIMBTOWER_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CLIMBTOWER_TASK_CONDITION( DT_CLIMBTOWER_TASK_CONDITION &data );
INT32 EncodeDT_STUDY_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STUDY_TASK_CONDITION( DT_STUDY_TASK_CONDITION &data );
INT32 EncodeDT_RECRUITHERO_NUM_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUITHERO_NUM_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RECRUITHERO_NUM_TASK_CONDITION( DT_RECRUITHERO_NUM_TASK_CONDITION &data );
INT32 EncodeDT_OPENLIGHT_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OPENLIGHT_TASK_CONDITION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_OPENLIGHT_TASK_CONDITION( DT_OPENLIGHT_TASK_CONDITION &data );
INT32 EncodeUnDT_TASK_CONDITION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_TASK_CONDITION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_TASK_DATA( DT_TASK_DATA &data );
INT32 EncodeDT_TASK_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_TASK_DATA_LIST( DT_TASK_DATA_LIST &data );
INT32 EncodeDT_RACE_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RACE_BASE_DATA( DT_RACE_BASE_DATA &data );
INT32 EncodeDT_LOCALE_HOME(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_HOME(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCALE_HOME( DT_LOCALE_HOME &data );
INT32 EncodeDT_LOCALE_INSTANCE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_INSTANCE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCALE_INSTANCE( DT_LOCALE_INSTANCE &data );
INT32 EncodeDT_LOCALE_ONHOOK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_ONHOOK(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCALE_ONHOOK( DT_LOCALE_ONHOOK &data );
INT32 EncodeDT_LOCALE_MARK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_MARK(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCALE_MARK( DT_LOCALE_MARK &data );
INT32 EncodeUnDT_LOCALE_DATA_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_LOCALE_DATA_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_LOCALE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCALE_DATA( DT_LOCALE_DATA &data );
INT32 EncodeUnlockScienceInfo(void *pHost, CNetData* poNetData);
INT32 DecodeUnlockScienceInfo(void *pHost, CNetData* poNetData);
cJSON* GetJsonUnlockScienceInfo( UnlockScienceInfo &data );
INT32 EncodeDT_HERO_UPGRADE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPGRADE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_UPGRADE_DATA( DT_HERO_UPGRADE_DATA &data );
INT32 EncodeDT_STATE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STATE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_STATE_DATA( DT_STATE_DATA &data );
INT32 EncodeDT_MONSTER_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONSTER_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MONSTER_BASE_DATA( DT_MONSTER_BASE_DATA &data );
INT32 EncodeDT_MONSTER_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONSTER_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MONSTER_DATA_LIST( DT_MONSTER_DATA_LIST &data );
INT32 EncodeDT_GODWEAPON_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_BATTLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GODWEAPON_BATTLE_DATA( DT_GODWEAPON_BATTLE_DATA &data );
INT32 EncodeDT_BATTLE_OBJ_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_DATA( DT_BATTLE_OBJ_DATA &data );
INT32 EncodeDT_BATTLE_OBJ_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_DATA2( DT_BATTLE_OBJ_DATA2 &data );
INT32 EncodeDT_BATTLE_OBJ_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_GROUP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_GROUP_DATA( DT_BATTLE_OBJ_GROUP_DATA &data );
INT32 EncodeDT_BATTLE_OBJ_GROUP_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_GROUP_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_GROUP_DATA2( DT_BATTLE_OBJ_GROUP_DATA2 &data );
INT32 EncodeDT_BUFF_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUFF_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BUFF_DATA( DT_BUFF_DATA &data );
INT32 EncodeDT_HP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HP_DATA( DT_HP_DATA &data );
INT32 EncodeDT_ANGRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ANGRY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ANGRY_DATA( DT_ANGRY_DATA &data );
INT32 EncodeDT_PARRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PARRY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PARRY_DATA( DT_PARRY_DATA &data );
INT32 EncodeDT_SKILL_EFFECT_ID_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_EFFECT_ID_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SKILL_EFFECT_ID_DATA( DT_SKILL_EFFECT_ID_DATA &data );
INT32 EncodeDT_ATTACK_OBJ_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_OBJ_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_OBJ_DATA( DT_ATTACK_OBJ_DATA &data );
INT32 EncodeDT_ATTACK_OBJ_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_OBJ_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_OBJ_DATA2( DT_ATTACK_OBJ_DATA2 &data );
INT32 EncodeDT_ATTACK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_DATA( DT_ATTACK_DATA &data );
INT32 EncodeDT_ATTACK_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_DATA2( DT_ATTACK_DATA2 &data );
INT32 EncodeDT_GODWEAPON_ATTACK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_ATTACK_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GODWEAPON_ATTACK_DATA( DT_GODWEAPON_ATTACK_DATA &data );
INT32 EncodeDT_GODWEAPON_ATTACK_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_ATTACK_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GODWEAPON_ATTACK_DATA2( DT_GODWEAPON_ATTACK_DATA2 &data );
INT32 EncodeDT_ATTACK_ALL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_ALL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_ALL_DATA( DT_ATTACK_ALL_DATA &data );
INT32 EncodeDT_ATTACK_ALL_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_ALL_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_ALL_DATA2( DT_ATTACK_ALL_DATA2 &data );
INT32 EncodeDT_ATTACK_ALL_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_ALL_DATA3(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_ALL_DATA3( DT_ATTACK_ALL_DATA3 &data );
INT32 EncodeDT_BATTLE_ANGRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ANGRY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ANGRY_DATA( DT_BATTLE_ANGRY_DATA &data );
INT32 EncodeDT_BATTLE_ROUND_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ROUND_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ROUND_DATA( DT_BATTLE_ROUND_DATA &data );
INT32 EncodeDT_BATTLE_ROUND_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ROUND_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ROUND_DATA2( DT_BATTLE_ROUND_DATA2 &data );
INT32 EncodeDT_BATTLE_ROUND_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ROUND_DATA3(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ROUND_DATA3( DT_BATTLE_ROUND_DATA3 &data );
INT32 EncodeDT_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_DATA( DT_BATTLE_DATA &data );
INT32 EncodeDT_BATTLE_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_DATA2( DT_BATTLE_DATA2 &data );
INT32 EncodeDT_BATTLE_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_DATA3(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_DATA3( DT_BATTLE_DATA3 &data );
INT32 EncodeDT_SHIELD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SHIELD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SHIELD_DATA( DT_SHIELD_DATA &data );
INT32 EncodeDT_HP_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HP_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HP_DATA2( DT_HP_DATA2 &data );
INT32 EncodeDT_ATTACK_OBJ_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_OBJ_DATA3(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_OBJ_DATA3( DT_ATTACK_OBJ_DATA3 &data );
INT32 EncodeDT_ATTACK_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_DATA3(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_DATA3( DT_ATTACK_DATA3 &data );
INT32 EncodeDT_PARRY_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PARRY_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PARRY_DATA2( DT_PARRY_DATA2 &data );
INT32 EncodeDT_ATTACK_ALL_DATA4(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_ALL_DATA4(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_ALL_DATA4( DT_ATTACK_ALL_DATA4 &data );
INT32 EncodeDT_BATTLE_ROUND_DATA4(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ROUND_DATA4(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ROUND_DATA4( DT_BATTLE_ROUND_DATA4 &data );
INT32 EncodeDT_BATTLE_DATA4(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_DATA4(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_DATA4( DT_BATTLE_DATA4 &data );
INT32 EncodeDT_ATTACK_ALL_DATA5(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_ALL_DATA5(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ATTACK_ALL_DATA5( DT_ATTACK_ALL_DATA5 &data );
INT32 EncodeDT_BATTLE_ROUND_DATA5(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ROUND_DATA5(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_ROUND_DATA5( DT_BATTLE_ROUND_DATA5 &data );
INT32 EncodeDT_PET_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_BATTLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_BATTLE_DATA( DT_PET_BATTLE_DATA &data );
INT32 EncodeDT_BATTLE_OBJ_GROUP_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_GROUP_DATA3(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_GROUP_DATA3( DT_BATTLE_OBJ_GROUP_DATA3 &data );
INT32 EncodeDT_BATTLE_DATA5(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_DATA5(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_DATA5( DT_BATTLE_DATA5 &data );
INT32 EncodeDT_BATTLE_OBJ_MAX_HP(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_MAX_HP(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_MAX_HP( DT_BATTLE_OBJ_MAX_HP &data );
INT32 EncodeDT_BATTLE_OBJ_MAX_HP_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_MAX_HP_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_OBJ_MAX_HP_INFO( DT_BATTLE_OBJ_MAX_HP_INFO &data );
INT32 EncodeDT_EMPTY_HP_VIDEO_v400(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EMPTY_HP_VIDEO_v400(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EMPTY_HP_VIDEO_v400( DT_EMPTY_HP_VIDEO_v400 &data );
INT32 EncodeDT_EMPTY_HP_VIDEO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EMPTY_HP_VIDEO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EMPTY_HP_VIDEO( DT_EMPTY_HP_VIDEO &data );
INT32 EncodeDT_FINAL_ROUND_BATTLE_OBJ_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINAL_ROUND_BATTLE_OBJ_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FINAL_ROUND_BATTLE_OBJ_INFO( DT_FINAL_ROUND_BATTLE_OBJ_INFO &data );
INT32 EncodeDT_ONLINE_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONLINE_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ONLINE_ENCOURAGE_RECORD_DATA( DT_ONLINE_ENCOURAGE_RECORD_DATA &data );
INT32 EncodeDT_LOGIN_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOGIN_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOGIN_ENCOURAGE_RECORD_DATA( DT_LOGIN_ENCOURAGE_RECORD_DATA &data );
INT32 EncodeDT_RACE_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RACE_BATTLELOG_DATA( DT_RACE_BATTLELOG_DATA &data );
INT32 EncodeDT_RACE_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RACE_BATTLELOG_DATA_LIST( DT_RACE_BATTLELOG_DATA_LIST &data );
INT32 EncodeDT_CAPTURE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CAPTURE_DATA( DT_CAPTURE_DATA &data );
INT32 EncodeDT_CAPTURE_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CAPTURE_DATA_LIST( DT_CAPTURE_DATA_LIST &data );
INT32 EncodeDT_PLUNDER_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLUNDER_BATTLELOG_DATA( DT_PLUNDER_BATTLELOG_DATA &data );
INT32 EncodeDT_PLUNDER_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLUNDER_BATTLELOG_DATA_LIST( DT_PLUNDER_BATTLELOG_DATA_LIST &data );
INT32 EncodeDT_PLUNDER_GRID_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_GRID_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLUNDER_GRID_DATA( DT_PLUNDER_GRID_DATA &data );
INT32 EncodeDT_PLUNDER_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLUNDER_BASE_DATA( DT_PLUNDER_BASE_DATA &data );
INT32 EncodeDT_ENEMY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ENEMY_DATA( DT_ENEMY_DATA &data );
INT32 EncodeDT_ENEMY_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ENEMY_DATA_LIST( DT_ENEMY_DATA_LIST &data );
INT32 EncodeDT_MONEY_TREE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONEY_TREE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MONEY_TREE_DATA( DT_MONEY_TREE_DATA &data );
INT32 EncodeDT_INSTANCE_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_BATTLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_INSTANCE_BATTLE_DATA( DT_INSTANCE_BATTLE_DATA &data );
INT32 EncodeDT_PHYSTRENGTH_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PHYSTRENGTH_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PHYSTRENGTH_DATA( DT_PHYSTRENGTH_DATA &data );
INT32 EncodeDT_ONHOOK_RESULT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONHOOK_RESULT(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ONHOOK_RESULT( DT_ONHOOK_RESULT &data );
INT32 EncodeDT_ONHOOK_RCD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONHOOK_RCD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ONHOOK_RCD_DATA( DT_ONHOOK_RCD_DATA &data );
INT32 EncodeDT_FEW_PARAM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FEW_PARAM_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FEW_PARAM_DATA( DT_FEW_PARAM_DATA &data );
INT32 EncodeDT_CROP_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_INFO_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CROP_INFO_DATA( DT_CROP_INFO_DATA &data );
INT32 EncodeDT_CROP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CROP_DATA( DT_CROP_DATA &data );
INT32 EncodeDT_SCIENCE_TREE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_TREE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SCIENCE_TREE_DATA( DT_SCIENCE_TREE_DATA &data );
INT32 EncodeDT_FORMATION_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_HERO_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FORMATION_HERO_DATA( DT_FORMATION_HERO_DATA &data );
INT32 EncodeDT_FORMATION_IDX_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_IDX_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FORMATION_IDX_DATA( DT_FORMATION_IDX_DATA &data );
INT32 EncodeDT_FORMATION_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FORMATION_DATA_LIST( DT_FORMATION_DATA_LIST &data );
INT32 EncodeDT_FORMATION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FORMATION_DATA( DT_FORMATION_DATA &data );
INT32 EncodeDT_NEW_FORMATION_POSTION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_FORMATION_POSTION_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NEW_FORMATION_POSTION_INFO( DT_NEW_FORMATION_POSTION_INFO &data );
INT32 EncodeDT_NEW_FORMATION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_FORMATION_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NEW_FORMATION_INFO( DT_NEW_FORMATION_INFO &data );
INT32 EncodeDT_NEW_FORMATION_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_FORMATION_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NEW_FORMATION_DATA_LST( DT_NEW_FORMATION_DATA_LST &data );
INT32 EncodeDT_NEW_FORMATION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_FORMATION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NEW_FORMATION_DATA( DT_NEW_FORMATION_DATA &data );
INT32 EncodeDT_VERSION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VERSION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_VERSION_DATA( DT_VERSION_DATA &data );
INT32 EncodeDT_NOTICE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NOTICE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NOTICE_DATA( DT_NOTICE_DATA &data );
INT32 EncodeDT_NOTICE_DATA_DB(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NOTICE_DATA_DB(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NOTICE_DATA_DB( DT_NOTICE_DATA_DB &data );
INT32 EncodeDT_NOTICE_DATA_NEW(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NOTICE_DATA_NEW(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NOTICE_DATA_NEW( DT_NOTICE_DATA_NEW &data );
INT32 EncodeDT_EAT_BREAD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EAT_BREAD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EAT_BREAD_DATA( DT_EAT_BREAD_DATA &data );
INT32 EncodeDT_YABIAO_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_YABIAO_BASE_DATA( DT_YABIAO_BASE_DATA &data );
INT32 EncodeDT_YABIAO_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_YABIAO_BATTLELOG_DATA( DT_YABIAO_BATTLELOG_DATA &data );
INT32 EncodeDT_YABIAO_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_YABIAO_BATTLELOG_DATA_LIST( DT_YABIAO_BATTLELOG_DATA_LIST &data );
INT32 EncodeDT_SKILL_ACTION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_ACTION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SKILL_ACTION_DATA( DT_SKILL_ACTION_DATA &data );
INT32 EncodeDT_SKILL_ACTION_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_ACTION_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SKILL_ACTION_DATA_LIST( DT_SKILL_ACTION_DATA_LIST &data );
INT32 EncodeDT_JINGJIE_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JINGJIE_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_JINGJIE_BASE_DATA( DT_JINGJIE_BASE_DATA &data );
INT32 EncodeDT_GAS_BALL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GAS_BALL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GAS_BALL_DATA( DT_GAS_BALL_DATA &data );
INT32 EncodeDT_COLLECT_GAS_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COLLECT_GAS_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COLLECT_GAS_DATA( DT_COLLECT_GAS_DATA &data );
INT32 EncodeDT_JINGJIE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JINGJIE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_JINGJIE_DATA( DT_JINGJIE_DATA &data );
INT32 EncodeDT_CLIMB_TOWER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLIMB_TOWER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CLIMB_TOWER_DATA( DT_CLIMB_TOWER_DATA &data );
INT32 EncodeDT_ELITE_INSTANCE_RESET_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITE_INSTANCE_RESET_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ELITE_INSTANCE_RESET_DATA( DT_ELITE_INSTANCE_RESET_DATA &data );
INT32 EncodeDT_VIP_GET_NUM_EACH_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_GET_NUM_EACH_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_VIP_GET_NUM_EACH_DATA( DT_VIP_GET_NUM_EACH_DATA &data );
INT32 EncodeDT_VIP_GET_NUM_LEVEL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_GET_NUM_LEVEL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_VIP_GET_NUM_LEVEL_DATA( DT_VIP_GET_NUM_LEVEL_DATA &data );
INT32 EncodeDT_VIP_EXT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_EXT_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_VIP_EXT_DATA( DT_VIP_EXT_DATA &data );
INT32 EncodeDT_LUAACTIVITY_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LUAACTIVITY_RECORD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LUAACTIVITY_RECORD_DATA( DT_LUAACTIVITY_RECORD_DATA &data );
INT32 EncodeDT_LUAACTIVITY_RECORD_LIST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LUAACTIVITY_RECORD_LIST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LUAACTIVITY_RECORD_LIST_DATA( DT_LUAACTIVITY_RECORD_LIST_DATA &data );
INT32 EncodeDT_BOSSB_HURT_RATE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_HURT_RATE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSSB_HURT_RATE( DT_BOSSB_HURT_RATE &data );
INT32 EncodeDT_BOSS_BATTLE_ENC_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_ENC_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_ENC_DATA( DT_BOSS_BATTLE_ENC_DATA &data );
INT32 EncodeDT_BOSS_BATTLE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_PLAYER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_PLAYER_DATA( DT_BOSS_BATTLE_PLAYER_DATA &data );
INT32 EncodeDT_BOSS_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_DATA( DT_BOSS_BATTLE_DATA &data );
INT32 EncodeDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA( DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA &data );
INT32 EncodeDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST( DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_LST &data );
INT32 EncodeDT_BOSS_BATTLE_MODULE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_MODULE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_MODULE_DATA( DT_BOSS_BATTLE_MODULE_DATA &data );
INT32 EncodeDT_ACTIVITY_ENCOURAGE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_ENCOURAGE_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ACTIVITY_ENCOURAGE_INFO( DT_ACTIVITY_ENCOURAGE_INFO &data );
INT32 EncodeDT_ACTIVITY_ENCOURAGE_INFO2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_ENCOURAGE_INFO2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ACTIVITY_ENCOURAGE_INFO2( DT_ACTIVITY_ENCOURAGE_INFO2 &data );
INT32 EncodeDT_ACTIVITY_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ACTIVITY_ENCOURAGE_DATA( DT_ACTIVITY_ENCOURAGE_DATA &data );
INT32 EncodeDT_RDC_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RDC_PLAYER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RDC_PLAYER_DATA( DT_RDC_PLAYER_DATA &data );
INT32 EncodeDT_RANDOM_CHALLENGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RANDOM_CHALLENGE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RANDOM_CHALLENGE_DATA( DT_RANDOM_CHALLENGE_DATA &data );
INT32 EncodeDT_WORSHIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WORSHIP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_WORSHIP_DATA( DT_WORSHIP_DATA &data );
INT32 EncodeDT_WORSHIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WORSHIP_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_WORSHIP_DATA_LST( DT_WORSHIP_DATA_LST &data );
INT32 EncodeDT_CHAPTER_SCORE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHAPTER_SCORE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CHAPTER_SCORE_DATA( DT_CHAPTER_SCORE_DATA &data );
INT32 EncodeDT_ACCUMULATED_SCORE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCUMULATED_SCORE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ACCUMULATED_SCORE_DATA( DT_ACCUMULATED_SCORE_DATA &data );
INT32 EncodeDT_SCORE_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCORE_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SCORE_DATA_LST( DT_SCORE_DATA_LST &data );
INT32 EncodeDT_EQUIP_LEVEL_COMPOSE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_LEVEL_COMPOSE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EQUIP_LEVEL_COMPOSE_DATA( DT_EQUIP_LEVEL_COMPOSE_DATA &data );
INT32 EncodeDT_EQUIP_COMPOSE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_COMPOSE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EQUIP_COMPOSE_DATA( DT_EQUIP_COMPOSE_DATA &data );
INT32 EncodeDT_GATHER_SCIENCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GATHER_SCIENCE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GATHER_SCIENCE_DATA( DT_GATHER_SCIENCE_DATA &data );
INT32 EncodeDT_BEGBLUE_RES(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BEGBLUE_RES(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BEGBLUE_RES( DT_BEGBLUE_RES &data );
INT32 EncodeDT_CONSUME_BEGBLUE_SMILE_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CONSUME_BEGBLUE_SMILE_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CONSUME_BEGBLUE_SMILE_LST( DT_CONSUME_BEGBLUE_SMILE_LST &data );
INT32 EncodeDT_BEGBLUE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BEGBLUE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BEGBLUE_DATA( DT_BEGBLUE_DATA &data );
INT32 EncodeDT_SEND_FLOWER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SEND_FLOWER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SEND_FLOWER_DATA( DT_SEND_FLOWER_DATA &data );
INT32 EncodeDT_FINALLY_CONTACT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINALLY_CONTACT_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FINALLY_CONTACT_DATA( DT_FINALLY_CONTACT_DATA &data );
INT32 EncodeDT_FINALLY_CONTACT_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINALLY_CONTACT_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FINALLY_CONTACT_DATA_LST( DT_FINALLY_CONTACT_DATA_LST &data );
INT32 EncodeDT_RECV_FLOWER_DATA_EX_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_DATA_EX_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RECV_FLOWER_DATA_EX_LOG( DT_RECV_FLOWER_DATA_EX_LOG &data );
INT32 EncodeDT_FRIENDS_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIENDS_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FRIENDS_BASE_DATA( DT_FRIENDS_BASE_DATA &data );
INT32 EncodeDT_RAREITEM_GOODS_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RAREITEM_GOODS_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RAREITEM_GOODS_INFO( DT_RAREITEM_GOODS_INFO &data );
INT32 EncodeDT_RAREITEM_GOODS_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RAREITEM_GOODS_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RAREITEM_GOODS_DATA( DT_RAREITEM_GOODS_DATA &data );
INT32 EncodeDT_GYMNASIUM_SKILL_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GYMNASIUM_SKILL_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GYMNASIUM_SKILL_INFO( DT_GYMNASIUM_SKILL_INFO &data );
INT32 EncodeDT_GYMNASIUM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GYMNASIUM_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GYMNASIUM_DATA( DT_GYMNASIUM_DATA &data );
INT32 EncodeDT_HUNTING_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HUNTING_INFO( DT_HUNTING_INFO &data );
INT32 EncodeDT_SHADE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SHADE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SHADE_DATA( DT_SHADE_DATA &data );
INT32 EncodeDT_FACTION_HUNTING_SCHEDULE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_HUNTING_SCHEDULE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_HUNTING_SCHEDULE_DATA( DT_FACTION_HUNTING_SCHEDULE_DATA &data );
INT32 EncodeDT_HOT_SPRING_TIME_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_TIME_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HOT_SPRING_TIME_DATA( DT_HOT_SPRING_TIME_DATA &data );
INT32 EncodeDT_SHADE_TASK_OPEN_MARK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SHADE_TASK_OPEN_MARK(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SHADE_TASK_OPEN_MARK( DT_SHADE_TASK_OPEN_MARK &data );
INT32 EncodeDT_FACTION_ICON_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_ICON_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_ICON_DATA( DT_FACTION_ICON_DATA &data );
INT32 EncodeDT_FACTION_COMMON_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_COMMON_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_COMMON_DATA( DT_FACTION_COMMON_DATA &data );
INT32 EncodeDT_WINE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WINE_DATA_CLI(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_WINE_DATA_CLI( DT_WINE_DATA_CLI &data );
INT32 EncodeDT_PLAYER_POS_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_POS_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_POS_INFO( DT_PLAYER_POS_INFO &data );
INT32 EncodeDT_OVER_GIVE_WINE_REWARD(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OVER_GIVE_WINE_REWARD(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_OVER_GIVE_WINE_REWARD( DT_OVER_GIVE_WINE_REWARD &data );
INT32 EncodeDT_HOT_SPRING_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HOT_SPRING_DATA( DT_HOT_SPRING_DATA &data );
INT32 EncodeDT_LEAVE_FACTION_MARK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LEAVE_FACTION_MARK(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LEAVE_FACTION_MARK( DT_LEAVE_FACTION_MARK &data );
INT32 EncodeDT_PLAYER_DONATE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_DONATE_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_DONATE_INFO( DT_PLAYER_DONATE_INFO &data );
INT32 EncodeDT_PLAYER_MARK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_MARK_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_MARK_DATA( DT_PLAYER_MARK_DATA &data );
INT32 EncodeDT_PLAYER_FACTION_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_FACTION_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_FACTION_BATTLELOG_DATA( DT_PLAYER_FACTION_BATTLELOG_DATA &data );
INT32 EncodeDT_PLAYER_FACTION_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_FACTION_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_FACTION_BATTLELOG_DATA_LIST( DT_PLAYER_FACTION_BATTLELOG_DATA_LIST &data );
INT32 EncodeDT_HOT_SPRING_EXT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_EXT_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HOT_SPRING_EXT_DATA( DT_HOT_SPRING_EXT_DATA &data );
INT32 EncodeDT_PLAYER_FACTION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_FACTION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_FACTION_DATA( DT_PLAYER_FACTION_DATA &data );
INT32 EncodeDT_PLAYER_TODAY_CONSUME_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_TODAY_CONSUME_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_TODAY_CONSUME_DATA( DT_PLAYER_TODAY_CONSUME_DATA &data );
INT32 EncodeDT_RECV_FLOWER_DATA_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_DATA_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RECV_FLOWER_DATA_LOG( DT_RECV_FLOWER_DATA_LOG &data );
INT32 EncodeDT_RECV_FLOWER_LOG_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_LOG_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RECV_FLOWER_LOG_LIST( DT_RECV_FLOWER_LOG_LIST &data );
INT32 EncodeDT_RELATION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RELATION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RELATION_DATA( DT_RELATION_DATA &data );
INT32 EncodeDT_RELATION_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RELATION_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RELATION_DATA_LIST( DT_RELATION_DATA_LIST &data );
INT32 EncodeDT_RELATION_DATA_EVEN(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RELATION_DATA_EVEN(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RELATION_DATA_EVEN( DT_RELATION_DATA_EVEN &data );
INT32 EncodeDT_UNREAD_DATA_EVEN(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UNREAD_DATA_EVEN(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_UNREAD_DATA_EVEN( DT_UNREAD_DATA_EVEN &data );
INT32 EncodeDT_DATA_EVEN_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_EVEN_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DATA_EVEN_LIST( DT_DATA_EVEN_LIST &data );
INT32 EncodeDT_COURAGE_PLAYER_HEROID_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_HEROID_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_PLAYER_HEROID_DATA( DT_COURAGE_PLAYER_HEROID_DATA &data );
INT32 EncodeDT_COURAGE_COMMON_PLAYER_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_COMMON_PLAYER_BATTLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_COMMON_PLAYER_BATTLE_DATA( DT_COURAGE_COMMON_PLAYER_BATTLE_DATA &data );
INT32 EncodeDT_COURAGE_ITEM_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_ITEM_DATA_CLI(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_ITEM_DATA_CLI( DT_COURAGE_ITEM_DATA_CLI &data );
INT32 EncodeDT_COURAGE_ITEM_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_ITEM_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_ITEM_DATA_LIST( DT_COURAGE_ITEM_DATA_LIST &data );
INT32 EncodeDT_COURAGE_ENCOURAGE_BOX_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_ENCOURAGE_BOX_GROUP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_ENCOURAGE_BOX_GROUP_DATA( DT_COURAGE_ENCOURAGE_BOX_GROUP_DATA &data );
INT32 EncodeDT_COURAGE_ENCOURAGE_BOX_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_ENCOURAGE_BOX_DATA2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_ENCOURAGE_BOX_DATA2( DT_COURAGE_ENCOURAGE_BOX_DATA2 &data );
INT32 EncodeDT_COURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_DATA( DT_COURAGE_DATA &data );
INT32 EncodeDT_EQUIP_MASTER_DETAIL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MASTER_DETAIL(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EQUIP_MASTER_DETAIL( DT_EQUIP_MASTER_DETAIL &data );
INT32 EncodeDT_MASTER_EXP_BOOK_DETAIL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MASTER_EXP_BOOK_DETAIL(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MASTER_EXP_BOOK_DETAIL( DT_MASTER_EXP_BOOK_DETAIL &data );
INT32 EncodeDT_EQUIP_MASTER(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MASTER(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EQUIP_MASTER( DT_EQUIP_MASTER &data );
INT32 EncodeDT_FRIENDS_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIENDS_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FRIENDS_DATA( DT_FRIENDS_DATA &data );
INT32 EncodeDT_INSTANCE_DB_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DB_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_INSTANCE_DB_DATA( DT_INSTANCE_DB_DATA &data );
INT32 EncodeDT_RACE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_RACE_DATA( DT_RACE_DATA &data );
INT32 EncodeDT_PLUNDER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLUNDER_DATA( DT_PLUNDER_DATA &data );
INT32 EncodeDT_YABIAO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_YABIAO_DATA( DT_YABIAO_DATA &data );
INT32 EncodeDT_BOSS_BATTLE_PLAYER_DATA_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_PLAYER_DATA_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BOSS_BATTLE_PLAYER_DATA_INFO( DT_BOSS_BATTLE_PLAYER_DATA_INFO &data );
INT32 EncodeDT_EXCHANGE_RESULT_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXCHANGE_RESULT_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EXCHANGE_RESULT_LOG( DT_EXCHANGE_RESULT_LOG &data );
INT32 EncodeDT_GAMBLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GAMBLE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GAMBLE_DATA( DT_GAMBLE_DATA &data );
INT32 EncodeDT_GVG_GIFT_REWARD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_GIFT_REWARD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_GIFT_REWARD_DATA( DT_GVG_GIFT_REWARD_DATA &data );
INT32 EncodeDT_GVG_GIFT_REWARD_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_GIFT_REWARD_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_GIFT_REWARD_LST_DATA( DT_GVG_GIFT_REWARD_LST_DATA &data );
INT32 EncodeDT_GVG_GIFT_KEY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_GIFT_KEY_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_GIFT_KEY_LST_DATA( DT_GVG_GIFT_KEY_LST_DATA &data );
INT32 EncodeDT_PLAYER_GVG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_GVG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_GVG_DATA( DT_PLAYER_GVG_DATA &data );
INT32 EncodeDT_GVG_FORMATION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FORMATION_DATA( DT_GVG_FORMATION_DATA &data );
INT32 EncodeDT_FACTION_BASE_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BASE_DATA_CLI2(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_BASE_DATA_CLI2( DT_FACTION_BASE_DATA_CLI2 &data );
INT32 EncodeDT_GAMBLE_FACTION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GAMBLE_FACTION_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GAMBLE_FACTION_INFO( DT_GAMBLE_FACTION_INFO &data );
INT32 EncodeDT_GVG_ROUND(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_ROUND(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_ROUND( DT_GVG_ROUND &data );
INT32 EncodeDT_FACTION_GVG_SINGLE_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_GVG_SINGLE_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_GVG_SINGLE_LOG( DT_FACTION_GVG_SINGLE_LOG &data );
INT32 EncodeDT_FACTION_SIMPLE_GVG_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_SIMPLE_GVG_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_SIMPLE_GVG_LOG( DT_FACTION_SIMPLE_GVG_LOG &data );
INT32 EncodeDT_FACTION_GVG_LOG_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_GVG_LOG_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_GVG_LOG_LIST( DT_FACTION_GVG_LOG_LIST &data );
INT32 EncodeDT_FACTION_SIMPLE_GVG_LOG_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_SIMPLE_GVG_LOG_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_SIMPLE_GVG_LOG_LIST( DT_FACTION_SIMPLE_GVG_LOG_LIST &data );
INT32 EncodeDT_FACTION_LIST_SIMPLE_GVG_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_LIST_SIMPLE_GVG_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_LIST_SIMPLE_GVG_LOG( DT_FACTION_LIST_SIMPLE_GVG_LOG &data );
INT32 EncodeDT_GVG_LOG_FACTION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_LOG_FACTION_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_LOG_FACTION_INFO( DT_GVG_LOG_FACTION_INFO &data );
INT32 EncodeDT_FACTION_GVG_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_GVG_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_GVG_LOG( DT_FACTION_GVG_LOG &data );
INT32 EncodeDT_FACTION_GVG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_GVG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_GVG_DATA( DT_FACTION_GVG_DATA &data );
INT32 EncodeDT_GVG_FORMATION_PLAYER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_PLAYER_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FORMATION_PLAYER_INFO( DT_GVG_FORMATION_PLAYER_INFO &data );
INT32 EncodeDT_GVG_FORMATION_PLAYER_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_PLAYER_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FORMATION_PLAYER_LIST( DT_GVG_FORMATION_PLAYER_LIST &data );
INT32 EncodeDT_DOORSTRIBUTE_LEVEL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DOORSTRIBUTE_LEVEL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DOORSTRIBUTE_LEVEL_DATA( DT_DOORSTRIBUTE_LEVEL_DATA &data );
INT32 EncodeDT_DOORSTRIBUTE_LEVE_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DOORSTRIBUTE_LEVE_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DOORSTRIBUTE_LEVE_DATA_LST( DT_DOORSTRIBUTE_LEVE_DATA_LST &data );
INT32 EncodeDT_FACTION_MEMBER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_MEMBER_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_MEMBER_INFO( DT_FACTION_MEMBER_INFO &data );
INT32 EncodeDT_FACTION_MEMBER_INFO_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_MEMBER_INFO_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_MEMBER_INFO_LIST( DT_FACTION_MEMBER_INFO_LIST &data );
INT32 EncodeDT_GVG_FACTION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FACTION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FACTION( DT_GVG_FACTION &data );
INT32 EncodeDT_PK_FACTION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PK_FACTION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PK_FACTION( DT_PK_FACTION &data );
INT32 EncodeDT_PVP_VIDEO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PVP_VIDEO_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PVP_VIDEO_DATA( DT_PVP_VIDEO_DATA &data );
INT32 EncodeDT_GVG_MVP(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_MVP(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_MVP( DT_GVG_MVP &data );
INT32 EncodeDT_GVG_MVP_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_MVP_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_MVP_LIST( DT_GVG_MVP_LIST &data );
INT32 EncodeDT_GVG_VIDEO_FACTION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_VIDEO_FACTION(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_VIDEO_FACTION( DT_GVG_VIDEO_FACTION &data );
INT32 EncodeDT_GVG_PK_VIDEO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_PK_VIDEO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_PK_VIDEO( DT_GVG_PK_VIDEO &data );
INT32 EncodeDT_GVG_PK_VIDEO_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_PK_VIDEO_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_PK_VIDEO_LIST( DT_GVG_PK_VIDEO_LIST &data );
INT32 EncodeDT_GVG_VIDEO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_VIDEO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_VIDEO( DT_GVG_VIDEO &data );
INT32 EncodeDT_GVG_ZONE_MEMBER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_ZONE_MEMBER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_ZONE_MEMBER_DATA( DT_GVG_ZONE_MEMBER_DATA &data );
INT32 EncodeDT_ZONE_FACTION_ID(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ZONE_FACTION_ID(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ZONE_FACTION_ID( DT_ZONE_FACTION_ID &data );
INT32 EncodeDT_DIFF_ZONE_FACTION_ID_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DIFF_ZONE_FACTION_ID_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_DIFF_ZONE_FACTION_ID_LIST( DT_DIFF_ZONE_FACTION_ID_LIST &data );
INT32 EncodeDT_ONE_ZONE_FACTION_ID_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONE_ZONE_FACTION_ID_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ONE_ZONE_FACTION_ID_LIST( DT_ONE_ZONE_FACTION_ID_LIST &data );
INT32 EncodeDT_ZONE_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ZONE_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ZONE_LIST( DT_ZONE_LIST &data );
INT32 EncodeDT_ZONE_ID_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ZONE_ID_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ZONE_ID_LIST( DT_ZONE_ID_LIST &data );
INT32 EncodeDT_FACTION_LIST_GVG_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_LIST_GVG_LOG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_LIST_GVG_LOG( DT_FACTION_LIST_GVG_LOG &data );
INT32 EncodeDT_VIDEO_ID(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIDEO_ID(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_VIDEO_ID( DT_VIDEO_ID &data );
INT32 EncodeDT_FINAL_WAR_EACH_ROUND_FACTION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINAL_WAR_EACH_ROUND_FACTION_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FINAL_WAR_EACH_ROUND_FACTION_INFO( DT_FINAL_WAR_EACH_ROUND_FACTION_INFO &data );
INT32 EncodeDT_FINAL_WAR_ROUND_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINAL_WAR_ROUND_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FINAL_WAR_ROUND_INFO( DT_FINAL_WAR_ROUND_INFO &data );
INT32 EncodeDT_16_TO_8_TO_4_WAR_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_16_TO_8_TO_4_WAR_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_16_TO_8_TO_4_WAR_INFO( DT_16_TO_8_TO_4_WAR_INFO &data );
INT32 EncodeDT_FINAL_WAR_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINAL_WAR_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FINAL_WAR_INFO( DT_FINAL_WAR_INFO &data );
INT32 EncodeDT_GVG_STAGE_FINISH_FLAG_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_STAGE_FINISH_FLAG_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_STAGE_FINISH_FLAG_LIST( DT_GVG_STAGE_FINISH_FLAG_LIST &data );
INT32 EncodeDT_GROUP_ZONE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GROUP_ZONE(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GROUP_ZONE( DT_GROUP_ZONE &data );
INT32 EncodeDT_GROUP_ZONE_ID_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GROUP_ZONE_ID_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GROUP_ZONE_ID_LIST( DT_GROUP_ZONE_ID_LIST &data );
INT32 EncodeDT_WAR_16_TO_8_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WAR_16_TO_8_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_WAR_16_TO_8_LIST( DT_WAR_16_TO_8_LIST &data );
INT32 EncodeDT_GVG_ARENA_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_ARENA_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_ARENA_DATA( DT_GVG_ARENA_DATA &data );
INT32 EncodeDT_ZONE_FACTION_MEMBER(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ZONE_FACTION_MEMBER(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_ZONE_FACTION_MEMBER( DT_ZONE_FACTION_MEMBER &data );
INT32 EncodeDT_GVG_ACTIVITY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_ACTIVITY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_ACTIVITY_DATA( DT_GVG_ACTIVITY_DATA &data );
INT32 EncodeDT_GVG_LOCAL_ACTIVITY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_LOCAL_ACTIVITY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_LOCAL_ACTIVITY_DATA( DT_GVG_LOCAL_ACTIVITY_DATA &data );
INT32 EncodeDT_TSTRING_MSG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TSTRING_MSG(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_TSTRING_MSG( DT_TSTRING_MSG &data );
INT32 EncodeDT_BATTLE_LOG_MSG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_LOG_MSG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_LOG_MSG_DATA( DT_BATTLE_LOG_MSG_DATA &data );
INT32 EncodeDT_BATTLE_LOG_MSG_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_LOG_MSG_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_BATTLE_LOG_MSG_LST_DATA( DT_BATTLE_LOG_MSG_LST_DATA &data );
INT32 EncodeDT_SOUL_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SOUL_LST_DATA( DT_SOUL_LST_DATA &data );
INT32 EncodeDT_PLAYER_SOUL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_SOUL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_SOUL_DATA( DT_PLAYER_SOUL_DATA &data );
INT32 EncodeDT_MEDAL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MEDAL_DATA( DT_MEDAL_DATA &data );
INT32 EncodeDT_MEDAL_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MEDAL_LST_DATA( DT_MEDAL_LST_DATA &data );
INT32 EncodeDT_MEDAL_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_MEDAL_BASE_DATA( DT_MEDAL_BASE_DATA &data );
INT32 EncodeDT_PLAYER_MEDAL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_MEDAL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_MEDAL_DATA( DT_PLAYER_MEDAL_DATA &data );
INT32 EncodeDT_PET_WASHQUALITY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_WASHQUALITY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_WASHQUALITY_DATA( DT_PET_WASHQUALITY_DATA &data );
INT32 EncodeDT_PET_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_DATA( DT_PET_DATA &data );
INT32 EncodeDT_NEIDAN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEIDAN_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NEIDAN_DATA( DT_NEIDAN_DATA &data );
INT32 EncodeDT_PET_NEIDAN_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_NEIDAN_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_NEIDAN_DATA_LST( DT_PET_NEIDAN_DATA_LST &data );
INT32 EncodeDT_PLAYER_NEIDAN_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_NEIDAN_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_NEIDAN_DATA_LST( DT_PLAYER_NEIDAN_DATA_LST &data );
INT32 EncodeDT_NEIDAN_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEIDAN_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_NEIDAN_DATA_LST( DT_NEIDAN_DATA_LST &data );
INT32 EncodeDT_PET_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_DATA_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_DATA_LIST( DT_PET_DATA_LIST &data );
INT32 EncodeDT_PET_CALL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_CALL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_CALL_DATA( DT_PET_CALL_DATA &data );
INT32 EncodeDT_PET_CALL_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_CALL_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PET_CALL_LST_DATA( DT_PET_CALL_LST_DATA &data );
INT32 EncodeDT_HERO_HP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_HP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_HP_DATA( DT_HERO_HP_DATA &data );
INT32 EncodeDT_HERO_HP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_HP_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_HERO_HP_DATA_LST( DT_HERO_HP_DATA_LST &data );
INT32 EncodeDT_PLAYER_PET_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_PET_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_PET_DATA( DT_PLAYER_PET_DATA &data );
INT32 EncodeDT_PLAYER_NOPVP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_NOPVP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_NOPVP_DATA( DT_PLAYER_NOPVP_DATA &data );
INT32 EncodeDT_PLAYER_PVP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_PVP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_PVP_DATA( DT_PLAYER_PVP_DATA &data );
INT32 EncodeDT_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_PLAYER_DATA( DT_PLAYER_DATA &data );
INT32 EncodeDT_EXT_FUNC_PARAM(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXT_FUNC_PARAM(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EXT_FUNC_PARAM( DT_EXT_FUNC_PARAM &data );
INT32 EncodeDT_EXT_FUNC_PARAM_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXT_FUNC_PARAM_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_EXT_FUNC_PARAM_LST( DT_EXT_FUNC_PARAM_LST &data );
INT32 EncodeDT_CONTINUE_KILL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CONTINUE_KILL_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CONTINUE_KILL_DATA( DT_CONTINUE_KILL_DATA &data );
INT32 EncodeDT_FACTION_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_PLAYER_DATA( DT_FACTION_PLAYER_DATA &data );
INT32 EncodeDT_FACTION_PLAYER_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_PLAYER_DATA_LST( DT_FACTION_PLAYER_DATA_LST &data );
INT32 EncodeDT_FACTION_LOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_LOG_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_LOG_DATA( DT_FACTION_LOG_DATA &data );
INT32 EncodeDT_FACTION_LOG_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_LOG_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_LOG_DATA_LST( DT_FACTION_LOG_DATA_LST &data );
INT32 EncodeDT_FACTION_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BASE_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_BASE_DATA( DT_FACTION_BASE_DATA &data );
INT32 EncodeDT_FACTION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_DATA( DT_FACTION_DATA &data );
INT32 EncodeDT_FACTION_AUTHORITY(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_AUTHORITY(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_AUTHORITY( DT_FACTION_AUTHORITY &data );
INT32 EncodeDT_FACTION_AUTHORITY_EX(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_AUTHORITY_EX(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_AUTHORITY_EX( DT_FACTION_AUTHORITY_EX &data );
INT32 EncodeDT_COURAGE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_PLAYER_DATA( DT_COURAGE_PLAYER_DATA &data );
INT32 EncodeDT_COURAGE_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_GROUP_DATA( DT_COURAGE_GROUP_DATA &data );
INT32 EncodeDT_COURAGE_GROUP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_DATA_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_COURAGE_GROUP_DATA_LST( DT_COURAGE_GROUP_DATA_LST &data );
INT32 EncodeDT_FACTION_APPLAY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_APPLAY_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_APPLAY_DATA( DT_FACTION_APPLAY_DATA &data );
INT32 EncodeDT_FACTION_APPLAY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_APPLAY_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_APPLAY_LST_DATA( DT_FACTION_APPLAY_LST_DATA &data );
INT32 EncodeDT_SIMPLE_FACTION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SIMPLE_FACTION_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SIMPLE_FACTION_INFO( DT_SIMPLE_FACTION_INFO &data );
INT32 EncodeDT_SIMPLE_FACTION_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SIMPLE_FACTION_LST_INFO(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_SIMPLE_FACTION_LST_INFO( DT_SIMPLE_FACTION_LST_INFO &data );
INT32 EncodeDT_GVG_FACTION_RANK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FACTION_RANK_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FACTION_RANK_DATA( DT_GVG_FACTION_RANK_DATA &data );
INT32 EncodeDT_GVG_FACTION_RANK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FACTION_RANK_LST_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FACTION_RANK_LST_DATA( DT_GVG_FACTION_RANK_LST_DATA &data );
INT32 EncodeDT_FACTION_BATTLE_RESULT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BATTLE_RESULT(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_BATTLE_RESULT( DT_FACTION_BATTLE_RESULT &data );
INT32 EncodeDT_FACTION_BATTLE_RESULT_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BATTLE_RESULT_LST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_FACTION_BATTLE_RESULT_LST( DT_FACTION_BATTLE_RESULT_LST &data );
INT32 EncodeDT_LOCAL_WAR_FACTION_SEED(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCAL_WAR_FACTION_SEED(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCAL_WAR_FACTION_SEED( DT_LOCAL_WAR_FACTION_SEED &data );
INT32 EncodeDT_LOCAL_WAR_FACTION_SEED_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCAL_WAR_FACTION_SEED_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_LOCAL_WAR_FACTION_SEED_LIST( DT_LOCAL_WAR_FACTION_SEED_LIST &data );
INT32 EncodeDT_CHAOS_WAR(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHAOS_WAR(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_CHAOS_WAR( DT_CHAOS_WAR &data );
INT32 EncodeDT_GVG_BUILD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_BUILD_DATA(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_BUILD_DATA( DT_GVG_BUILD_DATA &data );
INT32 EncodeDT_GVG_FACTION_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FACTION_LIST(void *pHost, CNetData* poNetData);
cJSON* GetJsonDT_GVG_FACTION_LIST( DT_GVG_FACTION_LIST &data );
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoCommonData)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoCommonData)(void *pHost, CNetData* poNetData);

class CProtoCommonData : public CSDProtocol
{
public:
    static CProtoCommonData * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoCommonData FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoCommonData FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoCommonData();
	virtual ~CProtoCommonData();
	EnFuncCProtoCommonData m_EncodeFuncArray[PROTOCOMMONDATA_MSGID_RANGE];
	DeFuncCProtoCommonData m_DecodeFuncArray[PROTOCOMMONDATA_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
