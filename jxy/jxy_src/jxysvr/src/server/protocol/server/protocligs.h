/*       Version Number: 3          */

#ifndef PROTOCLIGS_H_INCLUDE_VERSION_3
#define PROTOCLIGS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "protocommondata.h"
#include "sdtype.h"
#include "sdstring.h"
#pragma pack(push, 1)

/*Defines Begin*/
#define MAX_CHAT_CONTENT_NUM     512
#define MAX_CHAT_NUM             20
#define MAX_YABIAO_PLAYER_NUM    40
#define MAX_BUY_GOLD_NUM         20
#define MAX_RESOURCES_NUM        50
#define MAX_RECHARGE_ITEM_NUM    50
#define MAX_FLOWERS_ITEM_NUM     50
#define MAX_SCORE_ITEM_NUM       50
#define MAX_ACTIVITY_ENCOURAGE_ITEM_LEN 50
#define MAX_APP_ADDRESS_NUM      512
#define MAX_DOGFECES_BUILD_TIP_NUM 56
#define MAX_ACTIVITY_ENCOURAGE_NAME_LEN 256
#define MAX_ACTIVITY_ENCOURAGE_DESC_LEN 1024
#define MAX_ACTIVITY_ENCOURAGE_NUM 10
#define MAX_COMMON_TXT_NUM       256
#define MAX_SERIES_NO_NUM        256
#define MAX_FACTION_CLI_NUM      100
#define MAX_VIP_PRO_CONTEXT_LEN  2048
#define MAX_BUY_URL_LEN          256
#define NOTIN                    0
#define OWNER                    1
#define MAX_INCREASE             4
#define MAX_COMMON_TXT_LEN       1024
#define MAX_GEN_GAS_INFO_LEN     256
#define ITEM_EXCHANGE_ITEM_NUM   5
#define MAX_PRODUCTID_LEN        128
#define COIN                     1
#define GOLD                     2
#define STORY                    3
#define PHYSTRENGTH              4
#define SCIENCE                  5
#define BLUEGAS                  6
#define PURPLEGAS                7
#define JINGJIE                  8
#define EXPERIENCE               9
#define POWER                    10
#define UPGRADEEXPERIENCE        11
#define MAX_RES_VER_LEN          512
#define MAX_FLOWER_ITEM_NUM      20
#define MAX_EDIT_LEN             256
#define MAX_SOUL_CONTINUE_SEARCH 10
#define MAX_EXCHANGE_SOUL_NUM    9
#define MAX_SOUL_CARD_NAME_LENGTH 64
#define MAX_EXCHANGE_SOUL_METERIAL_NUM 5
#define MAX_EXCHANGE_SOUL_CARD_NUM 64
#define MAX_SOUL_PIC_LEN         64
#define MAX_SOUL_NAME_LEN        64
#define MAX_GVG_ERR_MSG_LEN      512
#define MAX_PRODUCTPET_EXTRA_ITEM_NUM 20
#define MAX_PRODUCTPET_NUM       10
#define MAX_STAR_DRAGON_ITEMTYPE_NUM 7
#define MAX_PET_STORE_ITEM_NUM   48
#define MAX_PET_RULE_LEN         6000
#define MAX_PET_BOOK_NUM         32
#define MAX_PET_SKILL_NUM        8
#define MAX_SOUL_POTENCY_LEVEL   5
#define MAX_SOUL_POTENCY_SUB_LEVEL 8
#define MAX_SOUL_POTENCY_ATTR_NUM 3
#define MAX_SOUL_POTENCY_ADD_ATTR_NUM 15
#define MAX_NEIDAN_INSTANCE_NUM  50
#define MAX_GROUP_ITEM_NUM       10
#define MAX_NEIDAN_MONSTER_NUM   20
#define PROTOCLIGS_MSGID_RANGE 3194
#define PROTOCLIGS_MSGID_OFFSET 0
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagDT_POWER_CHANGE_DATA{
	UINT32           dwOldPower; //ԭʼս��
	UINT32           dwCurPower; //��ǰս��
}DT_POWER_CHANGE_DATA;

typedef struct tagDT_SKILL_BUFF_DATA{
	UINT8            byBuffKindID; //����Ч��ID
	UINT8            byBuffRound; //buff�����غ���
	UINT8            byTriggerRate; //buff��������
	UINT16           wEffectParam; //Ч������
}DT_SKILL_BUFF_DATA;

typedef struct tagDT_SKILL_ACTION_DATA_CLI{
	UINT16           wActionID; //��ʽID
	UINT16           wActionLevel; //��ʽ�ȼ�
	UINT16           wEffectHurtRate; //�˺�����
	UINT32           dwExtHurtValue; //�����˺�ֵ
	UINT32           dwCurExp; //��ʽ��ǰ�ȼ����飨��ȥ֮ǰ�ȼ����飬�����ֵ��
	UINT32           dwUpgradeExp; //��ʽ��ǰ�ȼ������辭��(��ȥ֮ǰ�ȼ����飬�����ֵ)
}DT_SKILL_ACTION_DATA_CLI;

typedef struct tagDT_SKILL_EFFECT_DATA_CLI{
	UINT16           wEffectID; //Ч��ID
	UINT8            byOnceEffectKindID; //���μ���Ч��ID
	UINT16           wOnceEffectParam; //����Ч������
	UINT8            byBuffNum; //����BUFF��
	DT_SKILL_BUFF_DATA astBuffInfo[MAX_SKILL_BUFF_NUM]; //����BUFF��Ϣ
	UINT16           wUnlockLevel; //����������ʽ�ȼ�
}DT_SKILL_EFFECT_DATA_CLI;

typedef struct tagDT_EFFECT_RECOMMEND_CLI{
	UINT16           wHeroID; //������ID
	UINT16           wRecommendEffectKindID; //���䵥Ч��ID(0��ʾû��)
	UINT8            byRecommendHeroRangKind; //���似�ܷ�Χ
	UINT8            byRecommendHeroRangBuff; //���似�ܷ�Χ׷��buff
}DT_EFFECT_RECOMMEND_CLI;

typedef struct tagDT_SKILL_EFFECT_DATA_CLI2{
	DT_SKILL_EFFECT_DATA_CLI stEffectInfo; //Ч��
	DT_EFFECT_RECOMMEND_CLI astRecommendInfo[2]; //�Ƽ�����
}DT_SKILL_EFFECT_DATA_CLI2;

typedef struct tagDT_ATTACK_RANG_DATA_CLI{
	DT_ATTACK_RANG_DATA stRangInfo; //���ܷ�Χ
	UINT16           wUnlockLevel; //����������ʽ�ȼ�
	UINT16           wAttackRangHurtRate; //������Χ���˺����ʣ���ʽ�˺������ϣ�
}DT_ATTACK_RANG_DATA_CLI;

typedef struct tagDT_SKILL_DATA_CLI{
	DT_SKILL_ACTION_DATA_CLI stActionInfo; //������ʽ
	DT_SKILL_EFFECT_DATA_CLI stEffectInfo; //����Ч��
	DT_ATTACK_RANG_DATA_CLI stRangInfo; //���ܷ�Χ
}DT_SKILL_DATA_CLI;

typedef struct tagDT_HERO_BASE_DATA_CLI{
	UINT16           wKindID; //�佫����
	UINT8            byCareerID; //ְҵID
	UINT8            byCoach; //���佫��־,1Ϊ���佫
	UINT8            byPos; //λ�ñ�־,0Я����1Ϊ��ս��2����ļ����
	UINT8            byFormationIdx; //����λ��
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����(������ҩ)
	UINT32           dwExperience; //����
	UINT32           dwUpgradeExperience; //��������
	UINT8            byRecuitedFlag; //�Ƿ���ļ��
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //ս������(����չ���ԣ��������г���װ�����Լӳ�),��Ϊ����������������Լӳ�
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttribute; //����ս������
	UINT16           wGodweaponQuality; //����Ʒ��(0Ϊû������)
	UINT16           wGodweaponLevel; //�����ȼ�
	UINT32           dwPower; //ս��
	UINT8            byMaxAbsorbNum; //�������ո���
	UINT8            byAbsorbNum; //��ǰ���մ�����
	UINT16           awKindIDLst[MAX_ABSORB_NUM]; //�佫��Ϣ
	UINT8            byColor; //�佫��ɫ��Ϣ
	UINT16           wAbsorbKindID; //��ǰ�佫�����յ��佫ID
}DT_HERO_BASE_DATA_CLI;

typedef struct tagDT_EQUIP_DATA_STRENGTHEN_CLI{
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT8            byCanStrengthenFlag; //�Ƿ����ǿ����1����ǿ����0����ǿ��
	UINT32           dwStrengthenCoin; //ǿ�����
	UINT32           dwStrengthenGold; //ǿ��Ԫ��
	UINT16           wStrengthenRate; //ǿ���ɹ���
	DT_BATTLE_ATTRIBUTE stNextBattleAttribute; //��һ��ս������
}DT_EQUIP_DATA_STRENGTHEN_CLI;

typedef struct tagDT_EQUIP_XIANGQIAN_DES{
	TCHAR            aszAttrType[MAX_EQUIP_XIANGQIAN_NUM]; //����
}DT_EQUIP_XIANGQIAN_DES;

typedef struct tagDT_ALL_EQUIP_XIANGQIAN_DES{
	TCHAR            aszEquipPos1Des[MAX_EQUIP_XIANGQIAN_NUM]; //����
	TCHAR            aszEquipPos2Des[MAX_EQUIP_XIANGQIAN_NUM]; //����
	TCHAR            aszEquipPos3Des[MAX_EQUIP_XIANGQIAN_NUM]; //����
	TCHAR            aszEquipPos4Des[MAX_EQUIP_XIANGQIAN_NUM]; //����
}DT_ALL_EQUIP_XIANGQIAN_DES;

typedef struct tagDT_XIANGQIAN_ATTR_DATA{
	UINT16           wKindID; //��ʯID
	UINT32           dwAttrType; //��������
	UINT32           dwAddValue; //���ӵ�ֵ
	UINT32           dwAddPercentValue; //���ӵİٷֱ�
}DT_XIANGQIAN_ATTR_DATA;

typedef struct tagDT_EQUIP_DATA_CLI{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT8            byDressPos; //����λ��
	UINT16           wLevel; //װ���ȼ�
	UINT16           wDressLevel; //װ�������ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //��ǰս������
	UINT32           dwRecoverPrice; //���ռ۸�
	UINT32           dwMinScience; //��������
	UINT32           dwMaxScience; //��������
	UINT8            byXiangqianNum; //��Ƕ����
	DT_XIANGQIAN_ATTR_DATA astXiangqianList[MAX_XIANGQIAN_NUM]; //��Ƕ�б�
}DT_EQUIP_DATA_CLI;

typedef struct tagDT_EQUIP_MELT_DATA_CLI{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT8            byDressPos; //����λ��
	UINT16           wLevel; //װ���ȼ�
	UINT16           wDressLevel; //װ�������ȼ�
	UINT32           dwMinScience; //��������
	UINT32           dwMaxScience; //��������
	UINT8            byMeltTip; //������ʶ��0��������1��װ����Ƕ����ʯ�����ܽ������� 2��װ���ѱ���ħ���޷�Ͷ������¯��ֻ��ͨ�����۷�ʽ����
	UINT32           dwMeltGold; //Ԫ����������Ԫ��
}DT_EQUIP_MELT_DATA_CLI;

typedef struct tagDT_GOOD_MELT_DATA_CLI{
	UINT16           wKindID; //��ƷID
	UINT16           wNum; //��Ʒ����
	UINT32           dwMinScience; //��������
	UINT32           dwMaxScience; //��������
	UINT32           dwMeltGold; //Ԫ����������Ԫ��
}DT_GOOD_MELT_DATA_CLI;

typedef struct tagDT_EQUIP_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI astEquipList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_EQUIP_DATA_LST_CLI;

typedef struct tagDT_EQUIP_MELT_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_MELT_DATA_CLI astEquipList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_EQUIP_MELT_DATA_LST_CLI;

typedef struct tagDT_GOOD_MELT_DATA_LST_CLI{
	UINT16           wGoodNum; //װ������
	DT_GOOD_MELT_DATA_CLI astGoodList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_GOOD_MELT_DATA_LST_CLI;

typedef struct tagDT_HERO_EQUIP_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI astEquipList[EQUIP_POS_NUM]; //װ����Ϣ
}DT_HERO_EQUIP_DATA_LST_CLI;

typedef struct tagDT_EQUIP_DATA_CLI_v410{
	DT_EQUIP_DATA_CLI stEquipData; //װ�����ͣ�����ĵ�ǰս������Ϊ�����ԣ������°汾��˵�Ƿ������õģ�
	DT_BATTLE_ATTRIBUTE2 stBasicAttr; //װ�������������
	DT_BATTLE_ATTRIBUTE2 stStrengthenAttr; //ǿ����������
	DT_BATTLE_ATTRIBUTE2 stEnchantAttr; //��ħ��������
	DT_BATTLE_ATTRIBUTE2 stTotalAttr; //������
	UINT16           wEnchantLevel; //��ħ�ȼ�
}DT_EQUIP_DATA_CLI_v410;

typedef struct tagDT_HERO_EQUIP_DATA_LST_CLI_v410{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI_v410 astEquipList[EQUIP_POS_NUM]; //װ����Ϣ
}DT_HERO_EQUIP_DATA_LST_CLI_v410;

typedef struct tagDT_NEED_ITEM_DATA{
	UINT16           wItemKindID; //�������ID
	UINT8            byNum; //�������
	UINT16           wCurNum; //��ǰ����
	DT_INSTANCE_ID   stBurstInstance; //���ܵ���ĸ���
}DT_NEED_ITEM_DATA;

typedef struct tagDT_ESTIMATE_EQUIP_DATA{
	UINT16           wKindID; //װ������
	UINT16           wLevel; //װ���ȼ�
	UINT16           wDressLevel; //װ�������ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //��ǰս������
}DT_ESTIMATE_EQUIP_DATA;

typedef struct tagDT_ESTIMATE_DRUG_DATA{
	UINT16           wKindID; //��Ʒ����
	UINT16           wBaseTalent; //��Ϊ�����ӳ�ֵ
	UINT16           wDecTalent; //ÿ��ʹ��1����Ϊ�ӳɵݼ�ֵ
}DT_ESTIMATE_DRUG_DATA;

typedef union tagDT_ESTIMATE_ITEM_DATA_UNOIN{
	DT_ESTIMATE_EQUIP_DATA stEquip; //ս���仯��Ϣ
	DT_ESTIMATE_DRUG_DATA stDrug; //ս���仯��Ϣ
}DT_ESTIMATE_ITEM_DATA_UNOIN;

typedef struct tagDT_ESTIMATE_ITEM_DATA{
	UINT8            byItemType; //��������
	DT_ESTIMATE_ITEM_DATA_UNOIN stItemInfo; //��������
}DT_ESTIMATE_ITEM_DATA;

typedef struct tagDT_EQUIP_COMPOSE_DATA_CLI{
	UINT8            byItemNum; //������߸���(0��ʾ���ɺϳ�)
	DT_NEED_ITEM_DATA astItemInfoList[MAX_ITEM_MAKER_NEED_NUM]; //���������Ϣ
	DT_ESTIMATE_EQUIP_DATA stEstimateEquip; //Ԥ�ƺϳɵ�װ����Ϣ
	UINT8            bySuccessRate; //�ϳɳɹ���
	UINT32           dwSuccessGold; //100%�ɹ�������Ԫ��
}DT_EQUIP_COMPOSE_DATA_CLI;

typedef struct tagDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI astEquipInfo[MAX_BAG_OPEN_NUM]; //װ����Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI astEquipStrengthenInfo[MAX_BAG_OPEN_NUM]; //װ��ǿ����Ϣ
}DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI;

typedef struct tagDT_SEED_DATA_CLI{
	UINT8            byType; //��������
	UINT32           dwValue; //����ֵ
	UINT16           wKindID; //��ȡ����ƷID
}DT_SEED_DATA_CLI;

typedef struct tagDT_GOODS_DATA_CLI{
	UINT16           wKindID; //��Ʒ����
	UINT8            byGoodsMainKindID; //��Ʒ����
	UINT16           wUseLevel; //ʹ�õȼ�����Ϊ��ʯ�����ʾ��ʯ�ȼ���
	UINT16           wPileCount; //������
	UINT32           dwRecoverPrice; //���ռ۸�
	UINT32           dwParam1; //����1����Ϊ��ʯ�����ʾ��ʯ���ͣ�
	UINT32           dwParam2; //����2
	UINT32           dwParam3; //����3
	UINT32           dwValue; //ʹ��Ч��ֵ(��ͬ��Ʒ��ͬ����)
	UINT16           wComposeCount; //��Ʒ�ϳɸ���
	UINT16           wComposeKindID; //��Ʒ�ϳ�ID
	UINT8            byComposeItemNum; //���Ϻϳɵĵ���/����еĵ���
	UINT16           awComposeItem[MAX_COMPOSE_ITEM_NUM]; //������Ϣ
	UINT8            bySeedFlag; //���ӱ�־
	DT_SEED_DATA_CLI astSeedData[1]; //������Ϣ
	UINT32           dwParam4; //����4(��Ϊ��ʯ�����ʾ��ת��������)
}DT_GOODS_DATA_CLI;

typedef struct tagDT_GOODS_DATA_LST_CLI{
	UINT16           wGoodsNum; //װ������
	DT_GOODS_DATA_CLI astGoodsList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_GOODS_DATA_LST_CLI;

typedef struct tagDT_ITEM_DATA_CLI{
	UINT16           wKindID; //����
	UINT8            byGoodsMainKindID; //��Ʒ�����ͣ�ֻ����Ʒ���͵�����Ч
	UINT16           wPileNum; //������
}DT_ITEM_DATA_CLI;

typedef struct tagDT_ITEM_DATA_LIST_CLI{
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI astItemList[MAX_BAG_OPEN_NUM]; //������Ϣ
}DT_ITEM_DATA_LIST_CLI;

typedef union tagDT_ITEM_DATA_UNOIN{
	DT_EQUIP_DATA_CLI stEquip; //ս���仯��Ϣ
	DT_GOODS_DATA_CLI stGoods; //ս���仯��Ϣ
}DT_ITEM_DATA_UNOIN;

typedef struct tagDT_ITEM_DATA_CLI2{
	UINT8            byItemType; //��������
	DT_ITEM_DATA_UNOIN stItemInfo; //��������
}DT_ITEM_DATA_CLI2;

typedef struct tagDT_PHYSTRENGTH_DATA_CLI{
	UINT16           wPhyStrength; //��ǰ����
	UINT16           wMaxPhyStrength; //��������
	UINT16           wPhyStrengthRefreshCD; //����ˢ�¼��,��λs
	UINT16           wPhyStrengthCountDown; //����ˢ�µ���ʱ
}DT_PHYSTRENGTH_DATA_CLI;

typedef struct tagDT_NEW_EQUIP_PROMPT_DATA{
	UINT8            byEquipNum; //װ������
	UINT16           awEquipIDInfo[EQUIP_POS_NUM]; //װ��������Ϣ
	UINT16           wHeroID; //�������ĵ�һ�����(װ����������0��Ч)��0��ʾû��
}DT_NEW_EQUIP_PROMPT_DATA;

typedef struct tagDT_FUNC_COMMON_PROMPT{
	UINT8            byBuildKindID; //��������
	UINT8            byFuncFlag; //��������(0������ʾ��>0��ͬ��ֵ��ͬ������ʾ��ͬ����)
	UINT32           dwFuncCountDown; //���ܵĵ���ʱ
	UINT8            byExt; //��չ�ֶ�
	UINT16           wAheadTime; //��ǰ����ʱ��(��λ��)
}DT_FUNC_COMMON_PROMPT;

typedef struct tagDT_FUNC_PROMPT_DATA{
	UINT8            byBuildNum; //��������
	DT_FUNC_COMMON_PROMPT astBuildPromptInfo[MAX_BUILD_NUM]; //������ʾ��Ϣ
}DT_FUNC_PROMPT_DATA;

typedef struct tagDT_OTHER_PROMPT_DATA{
	UINT8            byHaveBetterHeroFlag; //�Ƿ��и�ǿ������ļ��1�У�0û��
}DT_OTHER_PROMPT_DATA;

typedef struct tagDT_RES_ITEM_DATA{
	UINT8            byResNum; //��Դ����
	DT_RES_DATA      astResList[MAX_PLAYER_RES_NUM]; //��Դ��Ϣ
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemList[MAX_PLAYER_RES_NUM]; //������Ϣ
}DT_RES_ITEM_DATA;

typedef struct tagDT_RSYNC_RES_ITEM_DATA{
	UINT8            byResNum; //��Դ����
	DT_RES_DATA      astResList[MAX_PLAYER_RES_NUM]; //��Դ��Ϣ
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemList[MAX_PLAYER_RES_NUM]; //������Ϣ
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}DT_RSYNC_RES_ITEM_DATA;

typedef struct tagDT_ITEM_DATA_LIST_CLI2{
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemList[MAX_BAG_OPEN_NUM]; //������Ϣ
}DT_ITEM_DATA_LIST_CLI2;

typedef struct tagDT_TASK_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwGold; //Ԫ��
	UINT16           wPhyStrength; //����
	UINT32           dwScience; //�����
	UINT32           dwExperience; //����
	UINT32           dwStory; //����
	UINT32           dwBlueGas; //����
	UINT32           dwPurpleGas; //����
	UINT32           dwJingJie; //����
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI astItemInfoList[MAX_ENCOURAGE_ITEM_KIND_NUM]; //������Ϣ
}DT_TASK_ENCOURAGE_DATA;

typedef struct tagDT_TASK_BASE_DATA{
	TCHAR            aszTaskDispName[MAX_TASK_DSPNAME_LEN]; //������ʾ����
	TCHAR            aszTaskDesc[MAX_TASK_DESC_LEN]; //������
	UINT8            byTaskType; //��������
	DT_TASK_CONDITION stTaskConditionInfo; //��������
	DT_TASK_ENCOURAGE_DATA stTaskEncourage; //������
}DT_TASK_BASE_DATA;

typedef struct tagDT_GIVEN_TASK_DATA{
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	UINT64           qwStateUpdateTime; //״̬����ʱ��
	DT_TASK_BASE_DATA stTaskBaseData; //���������Ϣ
	UINT8            byCanAccept; //��ǰ�Ƿ�ɽ�
	UINT16           wPlayerLevel; //��ҵȼ�(0��ʾ����Ҫ)
	DT_INSTANCE_ID   stInstanceID; //ͨ���ƶ�����(SceneIdxΪ0��ʾ����Ҫ)
}DT_GIVEN_TASK_DATA;

typedef struct tagDT_ACCEPT_TASK_DATA{
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	UINT64           qwStateUpdateTime; //״̬����ʱ��
	DT_TASK_BASE_DATA stTaskBaseData; //���������Ϣ
}DT_ACCEPT_TASK_DATA;

typedef struct tagDT_ENCOURAGE_TASK_DATA{
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	UINT64           qwStateUpdateTime; //״̬����ʱ��
	UINT8            byHaveBaseData; //�Ƿ������������Ϣ(���ڽ���ʱ������ɵ�����)
	DT_TASK_BASE_DATA astTaskBaseData[1]; //���������Ϣ
}DT_ENCOURAGE_TASK_DATA;

typedef struct tagDT_INVALID_TASK_DATA{
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
}DT_INVALID_TASK_DATA;

typedef union tagDT_TASK_UNION{
	DT_GIVEN_TASK_DATA stGivenTask; //ս���仯��Ϣ
	DT_ACCEPT_TASK_DATA stAcceptTask; //ս���仯��Ϣ
	DT_ENCOURAGE_TASK_DATA stEncourageTask; //ս���仯��Ϣ
	DT_INVALID_TASK_DATA stInvalidTask; //ս���仯��Ϣ
}DT_TASK_UNION;

typedef struct tagDT_TASK_DATA_CLI{
	UINT8            byTaskState; //����״̬
	DT_TASK_UNION    stTaskInfo; //��������
}DT_TASK_DATA_CLI;

typedef struct tagDT_TASK_DATA_LIST_CLI{
	UINT8            byTaskNum; //������(ÿ��1��)
	DT_TASK_DATA_CLI astTaskInfoList[MAX_TASK_LINE_NUM]; //������Ϣ
}DT_TASK_DATA_LIST_CLI;

typedef struct tagDT_ACCEPT_TASK_COND_RECORD{
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	UINT8            byTaskType; //��������
	DT_TASK_CONDITION stTaskCondRecord; //�������������¼
}DT_ACCEPT_TASK_COND_RECORD;

typedef struct tagDT_TASK_COND_RECORD_LIST{
	UINT8            byTaskNum; //������(ÿ��1��)
	DT_ACCEPT_TASK_COND_RECORD astTaskConRecordList[MAX_TASK_LINE_NUM]; //������Ϣ
}DT_TASK_COND_RECORD_LIST;

typedef struct tagDT_EXPERIENCE_DATA{
	UINT32           dwExperience; //����(�ȱ����������ľ���)
	UINT32           dwUpgradeExperience; //��������
}DT_EXPERIENCE_DATA;

typedef struct tagDT_PLAYER_BASE_DATA_CLI{
	UINT32           dwID; //���ΨһID
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT16           wLevel; //�ȼ�
	DT_EXPERIENCE_DATA stExperienceInfo; //������Ϣ
	UINT64           qwScience; //��ǰ�����
	UINT32           dwPower; //ս��
	DT_LOCALE_DATA   stLocaleData; //��ҵ�ǰλ����Ϣ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ��ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����
	UINT8            byVipLevel; //VIP�ȼ�
}DT_PLAYER_BASE_DATA_CLI;

typedef struct tagDT_BUILD_DATA_CLI{
	UINT8            byKindID; //��������
	UINT16           wLevel; //�ȼ�
	UINT8            bySort; //��������
	UINT8            byHaveOpenFlag; //�����Ƿ�򿪹���1Ϊ�򿪹�
}DT_BUILD_DATA_CLI;

typedef struct tagDT_ONLINE_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwGold; //Ԫ��
	UINT32           dwScience; //�����
	UINT32           dwExperience; //����
	UINT16           wPhyStrength; //����
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI astItemInfoList[MAX_ENCOURAGE_ITEM_KIND_NUM]; //������Ϣ
}DT_ONLINE_ENCOURAGE_DATA;

typedef struct tagDT_DATA_AFTER_ONLINE_ENCOURAGE{
	UINT64           qwCurCoin; //��ǰ���ͭǮ
	UINT64           qwCurGold; //��ǰ���Ԫ��
	UINT64           qwCurScience; //��ǰ��������
	UINT16           wPhyStrength; //��ǰ�������
}DT_DATA_AFTER_ONLINE_ENCOURAGE;

typedef struct tagDT_VIP_NUM_FUNC_DATA{
	UINT8            byNumFuncKind; //��������
	UINT32           dwCommonNum; //������ͨ����
	UINT32           dwIncNum; //��ǰvip�ȼ��������ܵĴ���
}DT_VIP_NUM_FUNC_DATA;

typedef struct tagDT_VIP_LEVEL_DATA{
	UINT8            byVipLevel; //VIP�ȼ�
	UINT32           dwNeedRechargeGold; //�����ֵ��Ԫ��
	UINT8            byExtNumFuncNum; //��ǰ�ȼ��������ܴ����Ĺ�����
	DT_VIP_NUM_FUNC_DATA astVipNumFuncInfo[MAX_VIP_FUNC]; //��ǰ�ȼ��������ܴ����Ĺ�����Ϣ
	UINT8            byOpenVipFuncNum; //��ǰ�ȼ����ŵ�vip������
	UINT8            abyOpenVipFuncInfo[MAX_VIP_FUNC]; //��ǰ�ȼ����ŵ�vip������Ϣ
}DT_VIP_LEVEL_DATA;

typedef struct tagDT_VIP_TAB_DATA_CLI{
	UINT8            byCurVipLevel; //��ǰVIP�ȼ�
	UINT32           dwHaveRechargeGold; //�Ѿ���ֵ��Ԫ��
	UINT8            byVipLevelNum; //VIP�ȼ���
	DT_VIP_LEVEL_DATA astVipLevelInfo[MAX_VIP_LEVEL]; //VIP�ȼ���Ϣ
}DT_VIP_TAB_DATA_CLI;

typedef struct tagDT_UNREAD_BATTLE_LOG_DATA_CLI{
	UINT8            byBattleLogType; //ս������
	UINT8            byUnreadNum; //δ������
}DT_UNREAD_BATTLE_LOG_DATA_CLI;

typedef struct tagDT_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwGold; //Ԫ��
	UINT16           wPhyStrength; //����
	UINT32           dwScience; //�����
	UINT32           dwStory; //����
	UINT32           dwBlueGas; //����
	UINT32           dwPurpleGas; //����
	UINT32           dwJingJie; //����
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemInfoList[MAX_ENCOURAGE_ITEM_KIND_NUM]; //������Ϣ
}DT_ENCOURAGE_DATA;

typedef struct tagDT_RSYNC_RECV_ENCOURAGE_DATA{
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurStory; //��ҵ�ǰ������
	UINT64           qwCurBlueGas; //��ҵ�ǰ������
	UINT64           qwCurPurpleGas; //��ҵ�ǰ������
	UINT64           qwCurJingJie; //��ҵ�ǰ�ľ���
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}DT_RSYNC_RECV_ENCOURAGE_DATA;

typedef struct tagPKT_CLIGS_ENTERGS_REQ{
	tagPKT_CLIGS_ENTERGS_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTERGS_REQ)); }
	UINT16           wZoneID; //��ID
	TCHAR            aszDeviceID[DEVICEID_LEN]; //��ID
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //��ID
	TCHAR            aszUserName[USERNAME_LEN]; //��ID
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ������Ϸ��Ч
	UINT32           dwCliVer; //�ͻ��˰汾
}PKT_CLIGS_ENTERGS_REQ;

typedef struct tagDT_OPERATING_ACTIVITY_DATA{
	UINT8            byNum; //���
	UINT32           dwVersionID; //��汾���
	TCHAR            aszDesc[MAX_COMMON_TXT_LEN]; //����
	TCHAR            aszUrl[MAX_COMMON_TXT_LEN]; //Url
	UINT8            byWebTabType; //web�������
	TCHAR            aszExtContext[MAX_COMMON_TXT_LEN]; //��չ��Ϣ
}DT_OPERATING_ACTIVITY_DATA;

typedef struct tagPKT_CLIGS_ENTERGS_ACK{
	tagPKT_CLIGS_ENTERGS_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTERGS_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCliVer; //�ͻ��˰汾
	UINT32           dwResVer; //��Դ�汾
	UINT32           dwUIVer; //UI�汾
	DT_PLAYER_BASE_DATA_CLI stPlayerInfo; //�����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_BASE_DATA_CLI astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	UINT16           wBuildNum; //������Ŀ
	DT_BUILD_DATA_CLI astBuildInfo[MAX_BUILD_NUM]; //������Ϣ
	UINT8            byOnlineEncourageFlag; //�Ƿ�������߽�����Ϣ
	DT_ONLINE_ENCOURAGE_DATA astOnlineEncourage[1]; //��ǰ���߽�����Ϣ
	UINT16           awRecvCountDown[1]; //��ȡ���߽�������ʱ����λ��
	UINT8            byBattleLogTypeNum; //ս�����͸���
	DT_UNREAD_BATTLE_LOG_DATA_CLI astUnreadBattleLogInfo[MAX_BATTLE_LOG_TYPE_NUM]; //δ��ս����Ϣ
	UINT16           wJuniorLevel; //���ֵȼ�
	DT_VIP_TAB_DATA_CLI stVipTabInfo; //VIP�����Ϣ
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
	UINT64           qwServerTime; //������ʱ��
	UINT16           wCanUseBoxGoodsID; //��ʹ�������ƷID,0Ϊû��
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_NOTICE_DATA   stNoticeInfo; //������Ϣ
	DT_OPERATING_ACTIVITY_DATA stOperatingActivityInfo; //��Ӫ���Ϣ
	UINT16           wUnreadOfflineMsgNum; //δ������˽����Ϣ����
	TCHAR            aszResVer[MAX_RES_VER_LEN]; //�汾��Ϣ
	UINT8            byHaveFaction; //�Ƿ�������0 û�����ɣ� 1������
	UINT8            byHaveVipGift; //�Ƿ���VIP���0 û������� 1�����
	UINT8            byEditDspName; //1���Ƿ���޸����
	TCHAR            aszEditDspName[MAX_EDIT_LEN]; //�޸�����������Ϣ
	DT_NOTICE_DATA_NEW stNoticeNewInfo; //������Ϣ
	UINT8            byIsFly; //�����Ƿ��ѷ���
}PKT_CLIGS_ENTERGS_ACK;

typedef struct tagDT_BAG_DATA_CLI{
	UINT8            byMaxOpenNum; //��������
	UINT8            byInitOpenNum; //��ʼ���򿪸�����
	UINT8            byCurOpenNum; //��ǰ�򿪸�����(������ʼֵ)
	UINT32           dwBaseOpenCoin; //��ʼ�򿪸�����Ҫ��ң���ѡ1
	UINT32           dwOpenCoinIncrease; //ÿ���1���ӵ������
	UINT32           dwBaseOpenGold; //��ʼ�򿪸�����ҪԪ������ѡ1
	UINT32           dwOpenGoldIncrease; //ÿ���1���ӵ���Ԫ��
}DT_BAG_DATA_CLI;

typedef struct tagDT_BAG_DATA_CLI2{
	UINT16           wMaxOpenNum; //��������
	UINT16           wInitOpenNum; //��ʼ���򿪸�����
	UINT16           wCurOpenNum; //��ǰ�򿪸�����(������ʼֵ)
	UINT32           dwBaseOpenCoin; //��ʼ�򿪸�����Ҫ��ң���ѡ1
	UINT32           dwOpenCoinIncrease; //ÿ���1���ӵ������
	UINT32           dwBaseOpenGold; //��ʼ�򿪸�����ҪԪ������ѡ1
	UINT32           dwOpenGoldIncrease; //ÿ���1���ӵ���Ԫ��
}DT_BAG_DATA_CLI2;

typedef struct tagDT_EQUIP_BAG_DATA_CLI{
	DT_BAG_DATA_CLI  stBagInfo; //����������Ϣ
	DT_EQUIP_DATA_LST_CLI stBagEquipDataList; //��ұ���װ����Ϣ
}DT_EQUIP_BAG_DATA_CLI;

typedef struct tagPKT_CLIGS_GET_HERO_INFO_REQ{
	tagPKT_CLIGS_GET_HERO_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_HERO_INFO_REQ)); }
	UINT32           dwPlayerID; //���ID
	UINT8            byEquipBagFlag; //�Ƿ�װ��������Ϣ
}PKT_CLIGS_GET_HERO_INFO_REQ;

typedef struct tagDT_ATTR_ENABLE_UPDATE_INFO{
	UINT8            byEnableAttrHPUpdate; //HP��������
	UINT8            byEnableAttrAttackUpdate; //������������
}DT_ATTR_ENABLE_UPDATE_INFO;

typedef struct tagDT_HERO_DATA_CLI{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_BASE_DATA_CLI astHeroBaseData[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST_CLI astEquipDataList[MAX_HERO_NUM]; //�佫װ����Ϣ
	DT_ATTR_ENABLE_UPDATE_INFO astEnableAttrUpdate[MAX_HERO_NUM]; //����������Ϣ
	DT_SKILL_DATA_CLI astSkillInfo[MAX_HERO_NUM]; //�佫������Ϣ
}DT_HERO_DATA_CLI;

typedef struct tagDT_PLAYER_BATTLE_INFO{
	TCHAR            aszDisplayName[USERNAME_LEN]; //�������
	UINT32           dwCurPower; //ս��
	UINT32           dwRank; //����䶷������
}DT_PLAYER_BATTLE_INFO;

typedef struct tagPKT_CLIGS_GET_HERO_INFO_ACK{
	tagPKT_CLIGS_GET_HERO_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_HERO_INFO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwPlayerID; //���ID
	UINT16           wCoachExpRate; //���Ǿ��鱶��(�ٷֱ�)
	DT_PLAYER_BATTLE_INFO stPlayerBattleInfo; //���ս����Ϣ
	DT_HERO_DATA_CLI stHeroInfo; //�佫��Ϣ
	UINT8            byEquipBagFlag; //�Ƿ�װ��������Ϣ
	DT_EQUIP_BAG_DATA_CLI astEquipBagDataInfo[1]; //δװ����װ����Ϣ
	UINT8            byGoodsCellNum; //��Ʒռ�ø�����
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
	UINT8            byVipLevel; //VIP�ȼ�
}PKT_CLIGS_GET_HERO_INFO_ACK;

typedef struct tagDT_ACTIVI_SIDE_PROMPT_DATA{
	UINT8            byActiviID; //����ID���
	UINT32           dwActiviCountDown; //���ܵ���ʱ
}DT_ACTIVI_SIDE_PROMPT_DATA;

typedef struct tagDT_ACTIVI_SIDE_PROMPT_DATA_LST{
	UINT8            byActiviNum; //������ʾ����
	DT_ACTIVI_SIDE_PROMPT_DATA astActiviPrompt[MAX_ACTIVI_SIDE_PROMPT_NUM]; //��ʾ����
}DT_ACTIVI_SIDE_PROMPT_DATA_LST;

typedef struct tagPKT_CLIGS_ENTER_HOME_REQ{
	tagPKT_CLIGS_ENTER_HOME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTER_HOME_REQ)); }
	UINT8            byKind; //�����԰����(�ͻ��˾�����ԭ������)
}PKT_CLIGS_ENTER_HOME_REQ;

typedef struct tagPKT_CLIGS_ENTER_HOME_ACK{
	tagPKT_CLIGS_ENTER_HOME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTER_HOME_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byKind; //�����԰����(�ͻ��˾�����ԭ������)
	UINT16           wBuildNum; //������Ŀ
	DT_BUILD_DATA_CLI astBuildInfo[MAX_BUILD_NUM]; //������Ϣ
	UINT8            byLoginEncourageState; //��¼����״̬(0,������ʾ��1����ʾ��2�赯��)
	UINT8            byBattleLogTypeNum; //ս�����͸���
	DT_UNREAD_BATTLE_LOG_DATA_CLI astUnreadBattleLogInfo[MAX_BATTLE_LOG_TYPE_NUM]; //δ��ս����Ϣ
	UINT16           awUnlockHeroID[MAX_UNLOCK_HERO_NUM]; //���������ʾ(0��ʾû��)
	UINT16           wUnlockEquipLevel; //����װ����ʾ(0��ʾû��)
	UINT32           dwUnlockElite; //������Ӣ������ʾ(0��ʾû�У���1���ֽڱ�ʾ��Ӣ��������idx����2/3���ֽڱ�ʾ������ID)
	UnlockScienceInfo stUnlockScienceList; //�����Ƽ���ʾ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_OTHER_PROMPT_DATA stOtherPromptInfo; //������ʾ��Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	UINT16           wEliteUnBattleNum; //δ��ľ�Ӣ��������
	UINT8            byHaveFactionState; //�Ƿ�������
	DT_ACTIVI_SIDE_PROMPT_DATA_LST stActiveSidePrompt; //���湦����ʾ
}PKT_CLIGS_ENTER_HOME_ACK;

typedef struct tagDT_BATTLE_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwExperience; //����
	UINT32           dwStory; //����
	UINT32           dwJingJie; //����
}DT_BATTLE_ENCOURAGE_DATA;

typedef struct tagDT_DATA_AFTER_BATTLE_ENCOURAGE{
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurStory; //��ǰ����
	UINT64           qwCurJingJie; //��ǰ����
	UINT8            byHeroNum; //�佫����
	DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
}DT_DATA_AFTER_BATTLE_ENCOURAGE;

typedef struct tagDT_RACE_CHALLENGE_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwScience; //�����
	UINT32           dwJingJie; //�����
}DT_RACE_CHALLENGE_ENCOURAGE_DATA;

typedef struct tagDT_RACE_RANK_ENCOURAGE_DATA{
	UINT32           dwRank; //����
	UINT32           dwCoin; //ͭǮ
	UINT32           dwScience; //�����
	UINT32           dwJingJie; //�����
}DT_RACE_RANK_ENCOURAGE_DATA;

typedef struct tagPKT_CLIGS_ENTER_INSTANCE_REQ{
	tagPKT_CLIGS_ENTER_INSTANCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTER_INSTANCE_REQ)); }
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byNewFlag; //�Ƿ����½��븱��(����֮ǰ�ڸ�����ʱ���븱��)��1Ϊ���¿�������
}PKT_CLIGS_ENTER_INSTANCE_REQ;

typedef struct tagDT_PASS_ENCOURAGE_DATA{
	UINT32           dwStory; //����
	UINT32           dwCoachExperience; //�������Ǿ���
	UINT32           dwExperience; //������龭��
	UINT32           dwCoin; //ͭǮ
}DT_PASS_ENCOURAGE_DATA;

typedef struct tagDT_DATA_AFTER_PASS_ENCOURAGE{
	UINT8            byHeroNum; //�佫����
	DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
}DT_DATA_AFTER_PASS_ENCOURAGE;

typedef struct tagDT_PASS_ENCOURAGE_BOX_GROUP_DATA{
	UINT32           dwCoin; //ͭǮ(��0��ת������ͭǮ)
	UINT32           dwGold; //Ԫ��(��0��ת������Ԫ��)
	UINT8            byHitItemIdx; //���е������(ͭǮ/Ԫ����0ʱ��Ч��0��ʾδ����,��1��ʼ,<=ItemNum)
	DT_ITEM_DATA_LIST_CLI stItemInfo; //������Ϣ
	UINT32           dwBlueGas; //����(��0��ת����������)
}DT_PASS_ENCOURAGE_BOX_GROUP_DATA;

typedef struct tagDT_PASS_ENCOURAGE_BOX_DATA{
	UINT8            byGroupNum; //���������
	DT_PASS_ENCOURAGE_BOX_GROUP_DATA astBoxGroupInfo[MAX_ENCOURAGE_BOX_GROUP_NUM]; //��������Ϣ
}DT_PASS_ENCOURAGE_BOX_DATA;

typedef struct tagDT_PASS_ENCOURAGE_BOX_DATA2{
	UINT8            byGroupNum; //���������
	DT_PASS_ENCOURAGE_BOX_GROUP_DATA astBoxGroupInfo[MAX_GVE_ENCOURAGE_BOX_GROUP_NUM]; //��������Ϣ
}DT_PASS_ENCOURAGE_BOX_DATA2;

typedef struct tagDT_HERO_UPGRADE_DATA_LIST{
	UINT8            byUpgradeHeroNum; //�����佫����
	DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
}DT_HERO_UPGRADE_DATA_LIST;

typedef struct tagPKT_CLIGS_ENTER_INSTANCE_ACK{
	tagPKT_CLIGS_ENTER_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTER_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCliVer; //�ͻ��˰汾
	UINT32           dwResVer; //��Դ�汾
	UINT32           dwUIVer; //UI�汾
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT32           dwMaxHP; //��HP���������������佫���ԣ�
	UINT32           dwCurHP; //��ǰHP���������������佫���ԣ�
	DT_MONSTER_DATA_LIST stMonsterInfo; //������Ϣ
	UINT8            byHaveBoxFlag; //�Ƿ��н������䣬1Ϊ�б���
	DT_PASS_ENCOURAGE_BOX_DATA astBoxInfo[1]; //����������Ϣ
	DT_HERO_UPGRADE_DATA_LIST astHeroUpgradeInfo[1]; //���������Ϣ
	UINT16           wDoubleExpNum; //����˫��������������0��ʾ��ʹ��˫����
	UINT8            byScore; //��������
	TCHAR            aszResVer[MAX_RES_VER_LEN]; //�汾��Ϣ
}PKT_CLIGS_ENTER_INSTANCE_ACK;

typedef struct tagPKT_CLIGS_BATTLE_REQ{
	tagPKT_CLIGS_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BATTLE_REQ)); }
	UINT8            byBattleIndex; //ս�����(�ڼ����֣���1��ʼ)
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
}PKT_CLIGS_BATTLE_REQ;

typedef struct tagDT_BURST_ITEM_DATA{
	UINT8            byBurstItemNum; //������Ʒ����
	UINT16           awBurstItemList[MAX_ENCOURAGE_ITEM_KIND_NUM]; //������Ʒ������Ϣ
}DT_BURST_ITEM_DATA;

typedef struct tagDT_NEXT_INSTANCE_DATA{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT16           wEnterLevel; //����ȼ�Ҫ��
	UINT16           wEnterPhyStrength; //��������Ҫ��
}DT_NEXT_INSTANCE_DATA;

typedef struct tagDT_UNLOCK_DATA{
	UINT16           wUnlockMainTownLevel; //�������ǵȼ�,0��ʾû�б仯
	UINT8            byUnlockBuildKindID; //�����������ͣ�0��ʾû���½����Ľ���
	UINT16           awUnlockHeroID[MAX_UNLOCK_HERO_NUM]; //�����佫����,0��ʾû���½������佫
}DT_UNLOCK_DATA;

typedef struct tagPKT_CLIGS_BATTLE_ACK3{
	tagPKT_CLIGS_BATTLE_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_BATTLE_ACK3)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA3  stBattleInfo; //ս����Ϣ
	DT_BATTLE_ENCOURAGE_DATA stBattleEncourage; //ս������
	DT_DATA_AFTER_BATTLE_ENCOURAGE stAfterBattleEncourage; //��ȡս�������������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_PASS_ENCOURAGE_DATA astPassEncourage[1]; //ͨ�ؽ���
	DT_DATA_AFTER_PASS_ENCOURAGE astAfterPassEncourage[1]; //��ȡͨ�ؽ����������Ϣ
	DT_PASS_ENCOURAGE_BOX_DATA astPassEncourageBox[1]; //ͨ�ر��佱����Ϣ
	DT_UNLOCK_DATA   astUnlockInfo[1]; //������Ϣ
	UINT8            byHaveNextInstance; //�Ƿ�����һ������
	DT_NEXT_INSTANCE_DATA astNextInstanceInfo[1]; //��һ��������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	TCHAR            aszExtContext[MAX_COMMON_TXT_LEN]; //��չ��Ϣ
}PKT_CLIGS_BATTLE_ACK3;

typedef struct tagPKT_CLIGS_EXIT_INSTANCE_REQ{
	tagPKT_CLIGS_EXIT_INSTANCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EXIT_INSTANCE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_EXIT_INSTANCE_REQ;

typedef struct tagPKT_CLIGS_EXIT_INSTANCE_ACK{
	tagPKT_CLIGS_EXIT_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EXIT_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_PLAYER_BASE_DATA_CLI stPlayerInfo; //��ǰ�����Ϣ(�����л�������������Ϣ)
}PKT_CLIGS_EXIT_INSTANCE_ACK;

typedef struct tagDT_INSTANCE_RECORD_DATA_CLI{
	UINT8            byIndex; //�������
	UINT8            byScore; //��������
	UINT16           wEnterLevel; //����ȼ�Ҫ��
	DT_BURST_ITEM_DATA stBurstItemInfo; //������Ʒ��Ϣ
	UINT32           dwBurstExperience; //��������
	UINT32           dwMaxMonstorPower; //�������ս��
	DT_PASS_ENCOURAGE_DATA stPassEncourage; //ͨ�ؽ�����Ϣ
}DT_INSTANCE_RECORD_DATA_CLI;

typedef struct tagDT_TOWN_INSTANCE_RECORD_DATA_CLI{
	UINT8            byIndex; //�������
	UINT16           wMainMonsterKindID; //��ʾ����������ID��0������ʾ
	UINT8            byCanBattle; //�Ƿ���Դ�1���Դ�
	UINT8            byInstanceNum; //������
	DT_INSTANCE_RECORD_DATA_CLI astInstanceInfo[MAX_INSTANCE_PER_TOWN_NUM]; //������¼��Ϣ
}DT_TOWN_INSTANCE_RECORD_DATA_CLI;

typedef struct tagPKT_CLIGS_GET_SCENE_INSTANCE_REQ{
	tagPKT_CLIGS_GET_SCENE_INSTANCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_SCENE_INSTANCE_REQ)); }
	UINT16           wIndex; //�������
}PKT_CLIGS_GET_SCENE_INSTANCE_REQ;

typedef struct tagDT_CHAPTER_SCORE{
	UINT8            byFlag; //��ȡ��־0��������ȡ�� 1������ȡ�� 2������ȡ
	DT_ENCOURAGE_DATA stChapterEncourage; //���ֽ�����Ϣ
}DT_CHAPTER_SCORE;

typedef struct tagDT_ACCUMULATED_SCORE_ENCOURAGE_BOX_DATA{
	UINT8            byGroupNum; //���������
	DT_PASS_ENCOURAGE_BOX_GROUP_DATA astBoxGroupInfo[MAX_ENCOURAGE_BOX_GROUP_NUM]; //��������Ϣ
}DT_ACCUMULATED_SCORE_ENCOURAGE_BOX_DATA;

typedef struct tagDT_ACCUMULATED_SCORE_ENCOURAGE{
	UINT32           dwCurSocre; //��ǰ������
	UINT32           dwEncourageSocre; //����ȡ��������
	DT_ACCUMULATED_SCORE_ENCOURAGE_BOX_DATA stAccumulatedEncourageBox; //����������Ϣ
	UINT8            byFlag; //��ȡ��־0��������ȡ�� 1������ȡ
	DT_ENCOURAGE_DATA stAccumulatedEncourage; //����������Ϣ
}DT_ACCUMULATED_SCORE_ENCOURAGE;

typedef struct tagPKT_CLIGS_GET_SCENE_INSTANCE_ACK{
	tagPKT_CLIGS_GET_SCENE_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_SCENE_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wIndex; //�������
	UINT8            byEnterPhyStrength; //��������Ҫ��
	DT_INSTANCE_ID   stMaxInstanceData; //��󸱱���Ϣ
	DT_INSTANCE_ID   stMaxUnlockInstance; //����������Ϣ
	UINT8            byTownNum; //������
	DT_TOWN_INSTANCE_RECORD_DATA_CLI astTownInstanceInfo[MAX_TOWN_PER_SCENE_NUM]; //���򸱱���Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	TCHAR            aszContent[MAX_CONTENT_SIZE]; //����Ҫ��ʾ����
	UINT8            byChapterNum; //����
	DT_CHAPTER_SCORE astChapterInfo[MAX_TOWN_PER_SCENE_NUM]; //����������Ϣ
	DT_ACCUMULATED_SCORE_ENCOURAGE stAccumulatedEncourage; //���۽�����Ϣ
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
	UINT32           dwFlyExp; //���ȼ��ѵ�120�����ڷ����ڼ�ʱ�ۻ��ľ���
}PKT_CLIGS_GET_SCENE_INSTANCE_ACK;

typedef struct tagDT_EQUIP_ENCHANT_DATA_CLI{
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT8            byCanEnchantFlag; //�Ƿ�ɸ�ħ
	UINT16           wEnchantStoneID; //���踽ħʯID
	UINT16           wCurEnchantStone; //��ǰ��ħʯ��
	UINT16           wCostEnchantStone; //���踽ħʯ��
	DT_BATTLE_ATTRIBUTE2 stNextBattleAttribute; //��һ��ս������
}DT_EQUIP_ENCHANT_DATA_CLI;

typedef struct tagPKT_CLIGS_EQUIP_STRENGTHEN_REQ{
	tagPKT_CLIGS_EQUIP_STRENGTHEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_STRENGTHEN_REQ)); }
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT8            byStrengthenType; //ǿ����ʽ��0��ң�1Ԫ��
	UINT16           wLevel; //Ҫ�����ĵȼ�(ÿ��ֻ����1����0��ʾֱ������10��)
}PKT_CLIGS_EQUIP_STRENGTHEN_REQ;

typedef struct tagPKT_CLIGS_EQUIP_STRENGTHEN_ACK{
	tagPKT_CLIGS_EQUIP_STRENGTHEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_STRENGTHEN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EQUIP_DATA_CLI stEquipInfo; //װ����Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //װ��ǿ����Ϣ
	UINT16           wStrengthenCountDown; //װ��ǿ������ʱ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT32           dwPlayerMaxHP; //��ҵ�ǰ��Ѫ��
	UINT32           dwPlayerCurHP; //��ҵ�ǰѪ��(�ڸ�������Ч)
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT32           dwStrengthen10Coin; //װ����10������ҪͭǮ��Ϣ
	DT_EQUIP_ENCHANT_DATA_CLI stEquipEnchantInfo; //ǿ���ɹ���װ���ĸ�ħ��Ϣ
}PKT_CLIGS_EQUIP_STRENGTHEN_ACK;

typedef struct tagPKT_CLIGS_OPEN_SMITHY_REQ{
	tagPKT_CLIGS_OPEN_SMITHY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SMITHY_REQ)); }
	UINT8            byBuildKindID; //��������
}PKT_CLIGS_OPEN_SMITHY_REQ;

typedef struct tagDT_BUY_EQUIP_DATA{
	UINT16           wEquipID; //װ��ID
	UINT32           dwBuyCoin; //����ͭ��
}DT_BUY_EQUIP_DATA;

typedef struct tagPKT_CLIGS_OPEN_SMITHY_ACK{
	tagPKT_CLIGS_OPEN_SMITHY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SMITHY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wStrengthenCountDown; //װ��ǿ������ʱ
	UINT16           wStrengthenCD; //װ��ǿ����CD
	UINT32           dwClrCDGold; //���CD����Ԫ��
	DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI stEquipList; //װ�������б�
	DT_BUY_EQUIP_DATA astByEquipInfo[EQUIP_POS_NUM]; //�ɹ������װ����Ϣ(�����±�+1Ϊ����λ��)
	UINT64           qwBlueGas; //��ǰ����
	UINT16           wEquipNum; //װ������
	UINT8            abyEquipOpenLightFlagInfo[MAX_BAG_OPEN_NUM]; //װ�������־��Ϣ(0���ɿ��⣬1�ɿ��⣬2�ѿ���)
	UINT32           adwStrengthen10CoinInfo[MAX_BAG_OPEN_NUM]; //װ����10������ҪͭǮ��Ϣ
}PKT_CLIGS_OPEN_SMITHY_ACK;

typedef struct tagPKT_CLIGS_OPEN_RECRUIT_REQ{
	tagPKT_CLIGS_OPEN_RECRUIT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECRUIT_REQ)); }
	UINT8            byBuildKindID; //��������
}PKT_CLIGS_OPEN_RECRUIT_REQ;

typedef struct tagDT_HERO_ATTR_ADD_CLI{
	UINT32           dwAddAttack; //����
	UINT32           dwAddHP; //Ѫ��
	UINT32           dwAddTalent; //����
}DT_HERO_ATTR_ADD_CLI;

typedef struct tagDT_RECRUIT_HERO_DATA{
	UINT8            byNeedVisitNum; //��ݷô���
	UINT8            byCurVisitNum; //��ǰ�Ѱݷô���
	UINT32           dwVisitCoin; //ÿ�ΰݷ�ͭ��
	DT_HERO_BASE_DATA_CLI stHeroBaseInfo; //�佫������Ϣ
	DT_HERO_ATTR_ADD_CLI stHeroAttrAddInfo; //�佫���Լӳ���Ϣ
	DT_SKILL_DATA_CLI stSkillInfo; //�佫������Ϣ
	UINT16           wVisitGold; //��ǧԪ��
	UINT16           wRecuitLevel; //��ļ�ȼ�
	UINT16           wRequireJingjieLevel; //��ļ���辳��׵ȼ�
	UINT8            byRecuitUnLock; //�Ƿ�ɲ���
	UINT8            byRecommend; //�Ƿ��Ƽ�
}DT_RECRUIT_HERO_DATA;

typedef struct tagPKT_CLIGS_OPEN_RECRUIT_ACK{
	tagPKT_CLIGS_OPEN_RECRUIT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECRUIT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wJingJieLevel; //����ȼ�
	UINT16           wHeroNum; //�佫��Ŀ
	DT_RECRUIT_HERO_DATA astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_OPEN_RECRUIT_ACK;

typedef struct tagPKT_CLIGS_RECRUIT_HERO_REQ{
	tagPKT_CLIGS_RECRUIT_HERO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECRUIT_HERO_REQ)); }
	UINT16           wHeroKindID; //�佫����
}PKT_CLIGS_RECRUIT_HERO_REQ;

typedef struct tagPKT_CLIGS_RECRUIT_HERO_ACK{
	tagPKT_CLIGS_RECRUIT_HERO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECRUIT_HERO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_HERO_BASE_DATA_CLI stHeroBaseInfo; //�佫������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT64           qwPlayerCoin; //��ҵ�ͭǮ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_RECRUIT_HERO_ACK;

typedef struct tagPKT_CLIGS_VISIT_HERO_REQ{
	tagPKT_CLIGS_VISIT_HERO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_VISIT_HERO_REQ)); }
	UINT16           wHeroKindID; //�佫����
	UINT8            bySizeFlag; //��С��־
	UINT8            byGoldFlag; //��ǧ��־
}PKT_CLIGS_VISIT_HERO_REQ;

typedef struct tagPKT_CLIGS_VISIT_HERO_ACK{
	tagPKT_CLIGS_VISIT_HERO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_VISIT_HERO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byWinFlag; //��Ӯ��־
	UINT16           wHeroKindID; //�佫����
	UINT8            byNeedVisitNum; //��ݷô���
	UINT8            byCurVisitNum; //��ǰ�Ѱݷô���
	UINT64           qwPlayerCoin; //��ҵ�ͭǮ
	UINT64           qwPlayerGold; //��ҵ�Ԫ��
	UINT16           wUpgradeVisitNum; //�����øж�
	UINT32           dwReturnCoin; //������ͭǮ��
}PKT_CLIGS_VISIT_HERO_ACK;

typedef struct tagDT_BATTLE_ATTR_EXT_INFO_CLI{
	UINT8            byKindID; //����Ŀ��(commondef.h)
	UINT32           dwKindValue; //����ֵ
	UINT8            byExtLevel; //���ӵȼ�
	UINT32           dwExtValue; //����ֵ
	UINT32           dwValueType; //ֵ���ͣ�1�̶�ֵ�� 2�ٷ������ο�commondef.h ValueType
}DT_BATTLE_ATTR_EXT_INFO_CLI;

typedef struct tagDT_BATTLE_ATTR_EXT_LST_INFO_CLI{
	UINT8            byExtAttrNum; //������������
	DT_BATTLE_ATTR_EXT_INFO_CLI astExtAttrInfo[MAX_SCIENCE_ATTR_NUM]; //����������Ϣ
}DT_BATTLE_ATTR_EXT_LST_INFO_CLI;

typedef struct tagDT_JEWELRY_DATA_CLI{
	UINT16           wJewelryID; //��ƷID
	UINT16           wJewelryLevel; //��Ʒ����Level
	UINT8            byJewelryDressPos; //��Ʒ����(����λ��commondef.f JewelryDressPos)
	DT_BATTLE_ATTR_LST_INFO stBaseAttrLst; //��Ʒ��������
	DT_BATTLE_ATTR_EXT_LST_INFO_CLI stExtAttrLst; //��Ʒ��������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wStrengLevel; //��Ʒǿ���ȼ�
	UINT16           wHeroID; //�����佫
	UINT8            byExtStrengNum; //��ǰ��������ʣ��ǿ������
	UINT8            byStrengExtLevel; //��ǿ���������Լ���ȼ�
}DT_JEWELRY_DATA_CLI;

typedef union tagDT_ITEM_DATA_UNOIN2{
	DT_EQUIP_DATA_CLI stEquip; //ս���仯��Ϣ
	DT_GOODS_DATA_CLI stGoods; //ս���仯��Ϣ
	DT_JEWELRY_DATA_CLI stJewelry; //ս���仯��Ϣ
}DT_ITEM_DATA_UNOIN2;

typedef struct tagDT_ITEM_DATA_CLI3{
	UINT8            byItemType; //��������
	DT_ITEM_DATA_UNOIN2 stItemInfo; //��������
}DT_ITEM_DATA_CLI3;

typedef struct tagDT_ITEM_DATA_LIST_CLI3{
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI3 astItemList[MAX_BAG_OPEN_NUM]; //������Ϣ
}DT_ITEM_DATA_LIST_CLI3;

typedef struct tagDT_ITEM_DATA_LIST_CLI4{
	UINT16           wItemNum; //���߸���
	DT_ITEM_DATA_CLI3 astItemList[MAX_BAG_OPEN_NUM_NEW]; //������Ϣ
}DT_ITEM_DATA_LIST_CLI4;

typedef struct tagDT_ITEM_NUM_DATA_CLI{
	UINT16           wItemID; //��ƷID
	UINT16           wItemNum; //��Ʒ����
	UINT16           wItemIdx; //��ͬ������Ʒ����ţ�����������ͬ���͵�װ����װ������Ʒ��Ҫ����ֶΣ�
}DT_ITEM_NUM_DATA_CLI;

typedef struct tagDT_ITEM_NUM_DATA_LIST_CLI{
	UINT16           wItemNum; //���߸���
	DT_ITEM_NUM_DATA_CLI astItemList[MAX_BAG_OPEN_NUM_NEW]; //������Ϣ
}DT_ITEM_NUM_DATA_LIST_CLI;

typedef struct tagDT_ITEM_DATA_LIST_LESS_CLI3{
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI3 astItemList[MAX_DISPALY_GOODS_NUM]; //������Ϣ
}DT_ITEM_DATA_LIST_LESS_CLI3;

typedef struct tagDT_RES_ITEM_DATA2{
	UINT8            byResNum; //��Դ����
	DT_RES_DATA      astResList[MAX_PLAYER_RES_NUM]; //��Դ��Ϣ
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI3 astItemList[MAX_PLAYER_RES_NUM]; //������Ϣ
}DT_RES_ITEM_DATA2;

typedef struct tagPKT_CLIGS_OPEN_BAG_REQ{
	tagPKT_CLIGS_OPEN_BAG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAG_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_BAG_REQ;

typedef struct tagPKT_CLIGS_OPEN_BAG_ACK{
	tagPKT_CLIGS_OPEN_BAG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BAG_DATA_CLI  stBagInfo; //����������Ϣ
	DT_ITEM_DATA_LIST_CLI2 stBagItemInfo; //����������Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
	DT_ITEM_DATA_LIST_CLI3 stBagItemInfo2; //����������Ϣ
}PKT_CLIGS_OPEN_BAG_ACK;

typedef struct tagPKT_CLIGS_OPEN_BAG_ACK2{
	tagPKT_CLIGS_OPEN_BAG_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAG_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BAG_DATA_CLI2 stBagInfo; //����������Ϣ
	DT_ITEM_DATA_LIST_CLI4 stBagItemInfo; //����������Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
}PKT_CLIGS_OPEN_BAG_ACK2;

typedef struct tagPKT_CLIGS_ACCEPT_TASK_REQ{
	tagPKT_CLIGS_ACCEPT_TASK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ACCEPT_TASK_REQ)); }
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
}PKT_CLIGS_ACCEPT_TASK_REQ;

typedef struct tagDT_INSTANCE_DATA_CLI{
	DT_INSTANCE_ID   stInstanceID; //�������
	UINT16           wEnterLevel; //����ȼ�Ҫ��
	DT_BURST_ITEM_DATA stBurstItemInfo; //������Ʒ��Ϣ
	UINT32           dwBurstExperience; //��������
	UINT32           dwMaxMonstorPower; //�������ս��
}DT_INSTANCE_DATA_CLI;

typedef struct tagPKT_CLIGS_ACCEPT_TASK_ACK{
	tagPKT_CLIGS_ACCEPT_TASK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ACCEPT_TASK_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�(��״̬��ƥ���·�����������Ϣ)
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT8            byUnlockNewInstanceFlag; //�Ƿ�����¸���
	DT_INSTANCE_ID   astUnlockCommonInstanceID[1]; //��������ͨ����ID
	UINT8            byHaveNewInstanceFlag; //�Ƿ����¿ɴ���ͨ����,1��Ч
	DT_INSTANCE_DATA_CLI astNewCommonInstanceID[1]; //�¿ɴ���ͨ����ID
}PKT_CLIGS_ACCEPT_TASK_ACK;

typedef struct tagPKT_CLIGS_GIVEUP_TASK_REQ{
	tagPKT_CLIGS_GIVEUP_TASK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GIVEUP_TASK_REQ)); }
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
}PKT_CLIGS_GIVEUP_TASK_REQ;

typedef struct tagPKT_CLIGS_GIVEUP_TASK_ACK{
	tagPKT_CLIGS_GIVEUP_TASK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GIVEUP_TASK_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�(��״̬��ƥ���·�����������Ϣ)
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_GIVEUP_TASK_ACK;

typedef struct tagPKT_CLIGS_RECV_TASK_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_TASK_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_TASK_ENCOURAGE_REQ)); }
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
}PKT_CLIGS_RECV_TASK_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_TASK_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_TASK_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_TASK_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byTaskLineIdx; //���������
	UINT32           dwTaskIdx; //�������
	DT_HERO_UPGRADE_DATA stMainHeroUpgradeInfo; //����������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�(��״̬�ı����·����������߸��ͻ���,����ֻ�·��仯������)
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	UINT16           wUnlockEquipLevel; //����װ����ʾ(0��ʾû��)
	UnlockScienceInfo stUnlockScienceList; //�����Ƽ���ʾ
	UINT8            byUnlockNewInstanceFlag; //�Ƿ�����¸���
	DT_INSTANCE_ID   astUnlockCommonInstanceID[1]; //��������ͨ����ID
	UINT8            byHaveNewInstanceFlag; //�Ƿ����¿ɴ���ͨ����,1��Ч
	DT_INSTANCE_DATA_CLI astNewCommonInstanceID[1]; //�¿ɴ���ͨ����ID
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	UINT64           qwStory; //��ҵ�ǰ������
	UINT64           qwBlueGas; //��ҵ�ǰ������
	UINT64           qwPurpleGas; //��ҵ�ǰ������
	UINT64           qwJingJie; //��ҵ�ǰ�ľ���
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT8            byHeroNum; //�����佫����
	DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
}PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_OPEN_RACE_BUILD_REQ{
	tagPKT_CLIGS_OPEN_RACE_BUILD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RACE_BUILD_REQ)); }
	UINT8            byBuildKindID; //��������
}PKT_CLIGS_OPEN_RACE_BUILD_REQ;

typedef struct tagDT_CHALLENGE_PLAYER_DATA{
	UINT32           dwID; //���ΨһID
	UINT16           wHeroKindID; //���佫����
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT16           wLevel; //��ҵȼ�
	UINT32           dwRank; //����
	UINT32           dwPower; //ս��
	UINT32           dwFirstAttack; //�ȹ�ֵ
}DT_CHALLENGE_PLAYER_DATA;

typedef struct tagPKT_CLIGS_OPEN_RACE_BUILD_ACK{
	tagPKT_CLIGS_OPEN_RACE_BUILD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RACE_BUILD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wLevel; //��ҵȼ�
	UINT32           dwRank; //����
	UINT16           wContiWin; //��ǰ��ʤ����
	UINT64           qwScience; //�����
	UINT64           qwJingJie; //�����
	UINT32           dwPower; //ս��
	UINT32           dwFirstAttack; //�ȹ�ֵ
	UINT8            byHaveRecvEncourageFlag; //�����Ƿ���ȡ����������
	DT_RACE_RANK_ENCOURAGE_DATA stTodayRankEncourage; //���տ���ȡ����������(δ��ȡ��Ч)
	DT_RACE_RANK_ENCOURAGE_DATA stTomorrowRankEncourage; //���տ���ȡ����������
	UINT16           wTotalChallengeNum; //�����ս�ܴ���
	UINT16           wCanChallengeNum; //��ҵ�ǰ����ս����
	UINT16           wVipExtNum; //VIP�������ӵ���ս����
	UINT16           wFreeChallengeNum; //���տ������ս����
	UINT32           dwChallengeNeedGold; //�շ���ս��Ԫ����
	UINT16           wChallengeCountDown; //��ս����ʱ����λ��
	UINT32           dwClrCDGold; //���CD����Ԫ��(ÿ����)
	UINT8            byChallengeNum; //��ս��Ҹ���
	DT_CHALLENGE_PLAYER_DATA astChallengePlayerList[MAX_CHALLENGE_NUM]; //��ս�����Ϣ�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT8            byHaveWorship; //�Ƿ��Ѿ�Ĥ�ݣ�1Ϊ�Ѿ�Ĥ��
	UINT8            byRecvEncCountDown; //����ȡ������������������ʱ
}PKT_CLIGS_OPEN_RACE_BUILD_ACK;

typedef struct tagDT_ENEMY_EQUIP_DATA{
	UINT16           wKindID; //װ������
	UINT16           wLevel; //װ���ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //��ǰ����
}DT_ENEMY_EQUIP_DATA;

typedef struct tagDT_ENEMY_EQUIP_DATA_LST{
	UINT16           wEquipNum; //װ������
	DT_ENEMY_EQUIP_DATA astEquipList[EQUIP_POS_NUM]; //װ����Ϣ
}DT_ENEMY_EQUIP_DATA_LST;

typedef struct tagDT_ENEMY_HERO_DATA{
	UINT16           wKindID; //�佫����
	UINT8            byCoach; //���佫��־,1Ϊ���佫
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //ս������
	DT_ENEMY_EQUIP_DATA_LST stEquipList; //װ����Ϣ
}DT_ENEMY_HERO_DATA;

typedef struct tagPKT_CLIGS_CHALLENGE_REQ{
	tagPKT_CLIGS_CHALLENGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_REQ)); }
	UINT32           dwRank; //����
}PKT_CLIGS_CHALLENGE_REQ;

typedef struct tagPKT_CLIGS_CHALLENGE_ACK3{
	tagPKT_CLIGS_CHALLENGE_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_ACK3)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //�Է������Ϣ
	UINT8            byEnemyHeroNum; //�Է���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //�Է���Ϣ
	DT_BATTLE_DATA3  stBattleInfo; //ս����Ϣ
	DT_RACE_CHALLENGE_ENCOURAGE_DATA stChallengeEncourage; //��ս����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ����
	UINT64           qwCurJingJie; //��ҵ�ǰ�ľ����
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_CHALLENGE_ACK3;

typedef struct tagPKT_CLIGS_RECV_RANK_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_RANK_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_RANK_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_RECV_RANK_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_RANK_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_RANK_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_RANK_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RACE_RANK_ENCOURAGE_DATA stRankEncourage; //��������
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwJingJie; //�����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_GET_RANK_REQ{
	tagPKT_CLIGS_GET_RANK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_RANK_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_GET_RANK_REQ;

typedef struct tagDT_RANK_DATA{
	UINT32           dwRank; //����
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT16           wHeroKindID; //���佫����
	UINT16           wLevel; //�ȼ�
	DT_RACE_RANK_ENCOURAGE_DATA stRankEncourage; //��������
	UINT32           dwPower; //ս��
}DT_RANK_DATA;

typedef struct tagPKT_CLIGS_GET_RANK_ACK{
	tagPKT_CLIGS_GET_RANK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_RANK_ACK)); }
	UINT16           wErrCode; //ս���仯��Ϣ
	UINT8            byShowNum; //��ʾ��������
	DT_RANK_DATA     astRankShowInfo[MAX_RANK_SHOW_NUM]; //������Ϣ
}PKT_CLIGS_GET_RANK_ACK;

typedef struct tagPKT_CLIGS_GET_RACE_BATTLELOG_REQ{
	tagPKT_CLIGS_GET_RACE_BATTLELOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_RACE_BATTLELOG_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_GET_RACE_BATTLELOG_REQ;

typedef struct tagDT_RACE_BATTLELOG_DATA_CLI{
	DT_RACE_BATTLELOG_DATA stBattlelogInfo; //ս����Ϣ
	TCHAR            aszEnemyDispName[USERNAME_LEN]; //�Է��ǳ�
}DT_RACE_BATTLELOG_DATA_CLI;

typedef struct tagPKT_CLIGS_GET_RACE_BATTLELOG_ACK{
	tagPKT_CLIGS_GET_RACE_BATTLELOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_RACE_BATTLELOG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byShowNum; //��ʾս������
	DT_RACE_BATTLELOG_DATA_CLI astRankBattleLogInfo[MAX_RACE_BATTLELOG_NUM]; //ս����Ϣ
}PKT_CLIGS_GET_RACE_BATTLELOG_ACK;

typedef struct tagPKT_CLIGS_OPEN_SHOP_REQ{
	tagPKT_CLIGS_OPEN_SHOP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SHOP_REQ)); }
	UINT8            byTabID; //��ǩID
}PKT_CLIGS_OPEN_SHOP_REQ;

typedef struct tagDT_ITEM_DATA_SHOP{
	DT_ITEM_DATA_CLI2 stItemInfo; //������Ϣ
	UINT32           dwBuyCoin; //����ͭ�Ҽ۸�
	UINT32           dwBuyGold; //����Ԫ���۸�
}DT_ITEM_DATA_SHOP;

typedef struct tagPKT_CLIGS_OPEN_SHOP_ACK{
	tagPKT_CLIGS_OPEN_SHOP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SHOP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byTabID; //��ǩID
	UINT8            byItemNum; //������Ϣ
	DT_ITEM_DATA_SHOP astItemDataList[MAX_SHOP_ITEM_NUM]; //������Ϣ
}PKT_CLIGS_OPEN_SHOP_ACK;

typedef struct tagPKT_CLIGS_BUY_ITEM_REQ{
	tagPKT_CLIGS_BUY_ITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_ITEM_REQ)); }
	UINT8            byTabID; //��ǩID
	UINT16           wKindID; //��������
	UINT16           wPileCount; //������
}PKT_CLIGS_BUY_ITEM_REQ;

typedef struct tagPKT_CLIGS_BUY_ITEM_ACK{
	tagPKT_CLIGS_BUY_ITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_ITEM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byTabID; //��ǩID
	UINT16           wKindID; //��������
	UINT16           wPileCount; //������
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
}PKT_CLIGS_BUY_ITEM_ACK;

typedef struct tagPKT_CLIGS_SELL_ITEM_REQ{
	tagPKT_CLIGS_SELL_ITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SELL_ITEM_REQ)); }
	UINT16           wKindID; //����
	UINT16           wIdx; //��ţ���ƷΪ1
	UINT16           wNum; //���۸���
}PKT_CLIGS_SELL_ITEM_REQ;

typedef struct tagPKT_CLIGS_SELL_ITEM_ACK{
	tagPKT_CLIGS_SELL_ITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SELL_ITEM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wKindID; //����
	UINT16           wIdx; //��ţ�װ����Ч
	UINT16           wNum; //���۸���
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	DT_ITEM_NUM_DATA_LIST_CLI stItemNumList; //���ۺ���ߺ��������Ʒ�ĵ�ǰ������ĳЩװ�����ۺ���Ի����Ʒ���總ħװ�����ۺ���Եõ���ħʯ��
}PKT_CLIGS_SELL_ITEM_ACK;

typedef struct tagPKT_CLIGS_DISBAND_HERO_REQ{
	tagPKT_CLIGS_DISBAND_HERO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DISBAND_HERO_REQ)); }
	UINT16           wHeroKindID; //�佫����
}PKT_CLIGS_DISBAND_HERO_REQ;

typedef struct tagPKT_CLIGS_DISBAND_HERO_ACK{
	tagPKT_CLIGS_DISBAND_HERO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DISBAND_HERO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫����
	UINT32           dwPlayerHP; //�����Ѫ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_DISBAND_HERO_ACK;

typedef struct tagPKT_CLIGS_EQUIP_REQ{
	tagPKT_CLIGS_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_REQ)); }
	UINT16           wHeroKindID; //Ҫ�������佫
	UINT8            byDressType; //������ʽ(װ��/ж��/�滻)
	UINT16           wDressItemKindID; //Ҫ������װ������
	UINT16           wDressItemIdx; //Ҫ������װ�����
	UINT16           wUndressItemKindID; //Ҫж�µ�װ������(ж�£��滻ʱ��Ч)
	UINT16           wUndressItemIdx; //Ҫж�µ�װ�����(ж�£��滻ʱ��Ч)
}PKT_CLIGS_EQUIP_REQ;

typedef struct tagDT_HERO_PANEL_CLI{
	UINT16           wKindID; //�佫ID
	DT_BATTLE_ATTRIBUTE2 stBattleAttribute; //ս������
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttribute; //����ս������
	UINT32           dwPower; //ս��
	UINT8            byPos; //λ�ñ�־,0Я����1Ϊ��ս��2����ļ����
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����(������ҩ)
	UINT32           dwExperience; //����
	UINT32           dwUpgradeExperience; //��������
}DT_HERO_PANEL_CLI;

typedef struct tagDT_HERO_PANEL_LST_CLI{
	UINT16           wHeroNum; //�佫����
	DT_HERO_PANEL_CLI astHeroPanelInfo[MAX_HERO_NUM]; //�佫�����Ϣ
}DT_HERO_PANEL_LST_CLI;

typedef struct tagPKT_CLIGS_EQUIP_ACK{
	tagPKT_CLIGS_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //Ҫ�������佫
	UINT8            byDressType; //������ʽ(װ��/ж��/�滻)
	UINT16           wDressItemKindID; //Ҫ������װ������
	UINT16           wDressItemIdx; //Ҫ������װ�����
	UINT16           wUndressItemKindID; //Ҫж�µ�װ������(ж�£��滻ʱ��Ч)
	UINT16           wUndressItemIdx; //Ҫж�µ�װ�����(ж�£��滻ʱ��Ч)
	UINT32           dwPlayerHP; //�����Ѫ��
	DT_POWER_CHANGE_DATA stHeroPowerInfo; //�佫ս����Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_HERO_PANEL_LST_CLI stHeroPanelInfo; //�佫�������Ϣ
}PKT_CLIGS_EQUIP_ACK;

typedef struct tagPKT_CLIGS_REGISTER_USERNAME_NTF{
	tagPKT_CLIGS_REGISTER_USERNAME_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_REGISTER_USERNAME_NTF)); }
	UINT8            byExt; //��չ��δʹ��
}PKT_CLIGS_REGISTER_USERNAME_NTF;

typedef struct tagPKT_CLIGS_OPEN_EMBATTLE_REQ{
	tagPKT_CLIGS_OPEN_EMBATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EMBATTLE_REQ)); }
	UINT8            byExt; //��չ����(δʹ��)
}PKT_CLIGS_OPEN_EMBATTLE_REQ;

typedef struct tagDT_HERO_EMBATLE_DATA{
	UINT16           wKindID; //�佫����
	UINT8            byCareerID; //ְҵID
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //ս������
	UINT32           dwPower; //ս��
	DT_SKILL_DATA_CLI stSkillInfo; //������Ϣ
}DT_HERO_EMBATLE_DATA;

typedef struct tagPKT_CLIGS_OPEN_EMBATTLE_ACK{
	tagPKT_CLIGS_OPEN_EMBATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EMBATTLE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_EMBATLE_DATA astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	DT_FORMATION_DATA stFormationInfo; //������Ϣ
}PKT_CLIGS_OPEN_EMBATTLE_ACK;

typedef struct tagPKT_CLIGS_EMBATTLE_REQ{
	tagPKT_CLIGS_EMBATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EMBATTLE_REQ)); }
	DT_FORMATION_DATA stFormationInfo; //������Ϣ
}PKT_CLIGS_EMBATTLE_REQ;

typedef struct tagPKT_CLIGS_EMBATTLE_ACK{
	tagPKT_CLIGS_EMBATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EMBATTLE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_EMBATTLE_ACK;

typedef struct tagPKT_CLIGS_CLR_PLAYER_DATA_REQ{
	tagPKT_CLIGS_CLR_PLAYER_DATA_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_PLAYER_DATA_REQ)); }
	UINT8            byExt; //��չ����
}PKT_CLIGS_CLR_PLAYER_DATA_REQ;

typedef struct tagPKT_CLIGS_MAKE_ITEM_REQ{
	tagPKT_CLIGS_MAKE_ITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MAKE_ITEM_REQ)); }
	UINT16           wItemKindID; //��������������
	UINT16           wEquipKindID; //װ������
	UINT16           wEquipIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
}PKT_CLIGS_MAKE_ITEM_REQ;

typedef struct tagPKT_CLIGS_MAKE_ITEM_ACK{
	tagPKT_CLIGS_MAKE_ITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MAKE_ITEM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_ITEM_DATA_CLI2 stItemInfo; //���ɵĵ�����Ϣ
	DT_ITEM_DATA_LIST_CLI2 stGoodsBagItemInfo; //��Ʒ������Ϣ
	UINT64           qwBlueGas; //��ǰ����
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ
	DT_ITEM_DATA_LIST_CLI3 stGoodsBagItemInfo2; //��Ʒ������Ϣ
	DT_ITEM_NUM_DATA_LIST_CLI stBagItemNumInfo; //�����и���Ʒ�ĵ�ǰ������Ϣ
}PKT_CLIGS_MAKE_ITEM_ACK;

typedef struct tagPKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ�δʹ��
}PKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wRecvCountDown; //��ȡ���߽�������ʱ����λ��
	UINT8            byNextOnlineEncourageFlag; //�Ƿ������һ�����߽�����Ϣ
	DT_ONLINE_ENCOURAGE_DATA astNextOnlineEncourage[1]; //��һ�����߽�����Ϣ
	DT_DATA_AFTER_ONLINE_ENCOURAGE stCurPlayerInfo; //��ǰ�����Ϣ
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
}PKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK;

typedef struct tagDT_DATA_AFTER_PASS_ENCOURAGE_BOX{
	UINT64           qwCurCoin; //ͭǮ
	UINT64           qwCurGold; //Ԫ��
	UINT64           qwCurBlueGas; //��ǰ����
}DT_DATA_AFTER_PASS_ENCOURAGE_BOX;

typedef struct tagPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ{
	tagPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ)); }
	UINT8            byExt; //��չ�ֶΣ�δʹ��
}PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ;

typedef struct tagPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK{
	tagPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_PASS_ENCOURAGE_BOX_DATA stPassEncourage; //ͨ�ؽ���������Ϣ
	DT_DATA_AFTER_PASS_ENCOURAGE_BOX stAfterPassEncourage; //��ȡͨ�ؽ�������������Ϣ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
}PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK;

typedef struct tagPKT_CLIGS_INCREASE_BAG_SIZE_REQ{
	tagPKT_CLIGS_INCREASE_BAG_SIZE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_INCREASE_BAG_SIZE_REQ)); }
	UINT8            byInc2Size; //���ӵ�������
	UINT8            byGoldFlag; //�Ƿ�ʹ��Ԫ����1Ϊʹ��Ԫ������
}PKT_CLIGS_INCREASE_BAG_SIZE_REQ;

typedef struct tagPKT_CLIGS_INCREASE_BAG_SIZE_ACK{
	tagPKT_CLIGS_INCREASE_BAG_SIZE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_INCREASE_BAG_SIZE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
}PKT_CLIGS_INCREASE_BAG_SIZE_ACK;

typedef struct tagPKT_CLIGS_ONHOOK_REQ{
	tagPKT_CLIGS_ONHOOK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ONHOOK_REQ)); }
	DT_INSTANCE_ID   stInstanceID; //����ID
	UINT8            byRunTimes; //����ɨ������
}PKT_CLIGS_ONHOOK_REQ;

typedef struct tagDT_HERO_UPGRADE_DATA2{
	UINT16           wHeroKindID; //�佫����ID
	UINT8            byUpgradeFlag; //�Ƿ�����
	UINT16           wStartLevel; //��ʼ�ȼ�
	UINT16           wCurLevel; //��ǰ�ȼ�
	UINT32           dwEncExperience; //��������
	UINT32           dwExperience; //��ǰ����
	UINT32           dwUpgradeExperience; //��һ����������
	UINT16           wCanUseBoxGoodsID; //��ʹ�������ƷID,0Ϊû��
}DT_HERO_UPGRADE_DATA2;

typedef struct tagDT_DATA_AFTER_ONHOOK{
	UINT8            byUpgradeHeroNum; //�����佫����
	DT_HERO_UPGRADE_DATA2 astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //��ǰ����
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //��ǰ���������Ϣ
	DT_EXPERIENCE_DATA stExperienceInfo; //������Ϣ
	UINT16           wUnlockEquipLevel; //����װ����ʾ(0��ʾû��)
	UnlockScienceInfo stUnlockScienceList; //�����Ƽ���ʾ
	UINT8            byUnlockNewInstanceFlag; //�Ƿ�����¸���
	DT_INSTANCE_ID   astUnlockCommonInstanceID[1]; //��������ͨ����ID
	UINT8            byHaveNewInstanceFlag; //�Ƿ����¿ɴ���ͨ����,1��Ч
	DT_INSTANCE_DATA_CLI astNewCommonInstanceID[1]; //�¿ɴ���ͨ����ID
	UINT64           qwCurBlueGas; //��ǰ����
}DT_DATA_AFTER_ONHOOK;

typedef struct tagDT_PLAYER_RES_DATA{
	UINT8            byResKind; //��Դ����
	UINT64           qwResValue; //��Դֵ
}DT_PLAYER_RES_DATA;

typedef struct tagDT_PLAYER_RES_LST_DATA{
	UINT8            byResNum; //��Դ����
	DT_PLAYER_RES_DATA astPlayerRes[MAX_PLAYER_RES_NUM]; //��Դ��Ϣ
}DT_PLAYER_RES_LST_DATA;

typedef struct tagPKT_CLIGS_ONHOOK_ACK{
	tagPKT_CLIGS_ONHOOK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ONHOOK_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_ONHOOK_RESULT stOnhookResult; //ɨ�����
	DT_DATA_AFTER_ONHOOK stAfterOnhookData; //ɨ����Һ���Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	UINT8            byUnlockNewInstanceFlag; //�Ƿ�����¸���
	DT_INSTANCE_ID   astUnlockCommonInstanceID[1]; //��������ͨ����ID
	UINT8            byHaveNewInstanceFlag; //�Ƿ����¿ɴ���ͨ����,1��Ч
	DT_INSTANCE_DATA_CLI astNewCommonInstanceID[1]; //�¿ɴ���ͨ����ID
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	UINT32           dwFlyExp; //���ȼ��ѵ�120�����ڷ����ڼ�ʱ�ۻ��ľ���
}PKT_CLIGS_ONHOOK_ACK;

typedef struct tagPKT_CLIGS_CLR_CHALLENGE_CD_REQ{
	tagPKT_CLIGS_CLR_CHALLENGE_CD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_CHALLENGE_CD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_CLR_CHALLENGE_CD_REQ;

typedef struct tagPKT_CLIGS_CLR_CHALLENGE_CD_ACK{
	tagPKT_CLIGS_CLR_CHALLENGE_CD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_CHALLENGE_CD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_CLR_CHALLENGE_CD_ACK;

typedef struct tagPKT_CLIGS_SYNC_TIME_REQ{
	tagPKT_CLIGS_SYNC_TIME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SYNC_TIME_REQ)); }
	UINT64           qwCliTime; //�ͻ��˵�ǰʱ��
}PKT_CLIGS_SYNC_TIME_REQ;

typedef struct tagPKT_CLIGS_SYNC_TIME_ACK{
	tagPKT_CLIGS_SYNC_TIME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SYNC_TIME_ACK)); }
	UINT64           qwCliTime; //�ͻ��˵�ǰʱ��
	UINT64           qwServTime; //��������ǰʱ��
}PKT_CLIGS_SYNC_TIME_ACK;

typedef struct tagPKT_CLILS_REGISTER_DSPNAME_REQ{
	tagPKT_CLILS_REGISTER_DSPNAME_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_DSPNAME_REQ)); }
	TCHAR            aszDspName[USERNAME_LEN]; //ս���仯��Ϣ
}PKT_CLILS_REGISTER_DSPNAME_REQ;

typedef struct tagPKT_CLILS_REGISTER_DSPNAME_ACK{
	tagPKT_CLILS_REGISTER_DSPNAME_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_DSPNAME_ACK)); }
	UINT16           wErrCode; //ս���仯��Ϣ
	TCHAR            aszDspName[USERNAME_LEN]; //ս���仯��Ϣ
}PKT_CLILS_REGISTER_DSPNAME_ACK;

typedef struct tagPKT_CLILS_USE_GOODS_REQ{
	tagPKT_CLILS_USE_GOODS_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_USE_GOODS_REQ)); }
	UINT16           wGoodsKindID; //��Ʒ����ID
	UINT8            byGetBagInfoFlag; //�Ƿ񷵻ر�����Ϣ
	UINT16           wUseNum; //ʹ�ø���
}PKT_CLILS_USE_GOODS_REQ;

typedef struct tagPKT_CLILS_USE_GOODS_ACK{
	tagPKT_CLILS_USE_GOODS_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_USE_GOODS_ACK)); }
	UINT16           wErrCode; //ս���仯��Ϣ
	UINT64           qwCoin; //��ǰ���ͭǮ
	UINT64           qwGold; //��ǰ���Ԫ��
	UINT16           wPhyStrength; //��ǰ�������
	UINT64           qwScience; //��ǰ��������
	UINT8            byMainHeroUpgradeFlag; //�Ƿ�������������Ϣ
	DT_HERO_UPGRADE_DATA astMainHeroUpgradeInfo[1]; //����������Ϣ
	UINT8            byUseBoxFlag; //�Ƿ��Ǳ���ʹ��
	DT_ITEM_DATA_LIST_CLI2 astBoxItemInfo[1]; //���������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT64           qwBlueGas; //��ǰ���������
	UINT64           qwPurpleGas; //��ǰ���������
	UINT64           qwJingJie; //��ǰ��Ҿ����
	UINT8            byGetBagInfoFlag; //�Ƿ񷵻ر�����Ϣ
	DT_ITEM_DATA_LIST_CLI2 astBagInfo[1]; //������Ϣ
	UINT16           wGoodsKindID; //��Ʒ����ID
	UINT16           wUseNum; //ʹ�ø���
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
	DT_ITEM_DATA_LIST_CLI3 astBagInfo2[1]; //������Ϣ
	DT_ITEM_NUM_DATA_LIST_CLI stBagItemNumInfo; //�����и���Ʒ�ĵ�ǰ������Ϣ
}PKT_CLILS_USE_GOODS_ACK;

typedef struct tagPKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ{
	tagPKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ;

typedef struct tagDT_LOGIN_ENCOURAG_DATA{
	DT_ITEM_DATA_CLI astItemInfo[MAX_LOGIN_ENCOURAGE_ITEM_NUM]; //���н����ĵ���
	UINT8            byHitIdx; //��ǰѡ�е����(��1��ʼ)
	UINT8            byHaveSelectFlag; //�Ƿ��Ѿ�ѡ��
	UINT16           wKeepDays; //������¼����
	UINT8            byCanRecvNumToday; //����ʣ�ཱ������
}DT_LOGIN_ENCOURAG_DATA;

typedef struct tagPKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK{
	tagPKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //ս���仯��Ϣ
	DT_LOGIN_ENCOURAG_DATA stLoginEncourageInfo; //��¼������Ϣ
}PKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK;

typedef struct tagPKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ{
	tagPKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ;

typedef struct tagPKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK{
	tagPKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK;

typedef struct tagPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ{
	tagPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ;

typedef struct tagPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK{
	tagPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK)); }
	UINT16           wErrCode; //ս���仯��Ϣ
	UINT8            byHaveEncourageFlag; //�����Ƿ��н���
	DT_LOGIN_ENCOURAG_DATA astLoginEncourageInfo[1]; //��¼������Ϣ
}PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK;

typedef struct tagDT_CAPTURE_WORK_DATA_CLI{
	UINT32           dwWorkCountdown; //��²��������ʱ(��λ��)
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT32           dwCaptureWorkSecond; //��²����ʱ��
	UINT32           dwCollectIncome; //�ܹ�����ֵ
	UINT32           dwUncollectIncome; //δ��ȡ����
	UINT32           dwAllCollectIncome; //ʣ�����п���ȡ����
}DT_CAPTURE_WORK_DATA_CLI;

typedef struct tagDT_CAPTURE_DATA_CLI{
	UINT32           dwCapturePlayerID; //����²�����ID
	TCHAR            aszCaptureDispName[USERNAME_LEN]; //��²�ǳ�
	UINT16           wCaptureCareerID; //��²ְҵ
	UINT16           wCaptureLevel; //��²�ȼ�
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
	UINT32           dwReleaseCountdown; //��²�ͷŵ���ʱ(��λ��,Ӳ���ͷ�ʱ��)
	DT_CAPTURE_WORK_DATA_CLI stWorkInfo; //��²����������Ϣ
}DT_CAPTURE_DATA_CLI;

typedef struct tagPKT_CLIGS_PLUNDER_REQ{
	tagPKT_CLIGS_PLUNDER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLUNDER_REQ)); }
	UINT32           dwEnemyID; //Ҫս�������ID
	UINT32           dwCaptureID; //��²���ID(��EnemyID��ͬ��ʾ�Ӷ����CaptureID��ң���ͬ��ʾ����CaptureID��²)
	UINT8            byUseItemFlag; //�Ƿ�ʹ�õ����Ӷ����5�����ϵ����
	UINT8            byResistFlag; //�Ƿ񷴿�(1��ʾ����)
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
}PKT_CLIGS_PLUNDER_REQ;

typedef struct tagDT_PLUNDER_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭ��
	UINT32           dwScience; //�����
}DT_PLUNDER_ENCOURAGE_DATA;

typedef struct tagDT_BECAPTURE_DATA{
	UINT32           dwOwnerID; //��²��ID(0��ʾû�б���²)
	TCHAR            aszOwnerDispName[USERNAME_LEN]; //��²���ǳ�
	UINT16           wOwnerLevel; //��²���ȼ�
	UINT32           dwOwnerPower; //��²��ս��
	UINT32           dwReleaseCountdown; //�ͷŵ���ʱ(��λ��,Ӳ���ͷ�ʱ��)
}DT_BECAPTURE_DATA;

typedef struct tagPKT_CLIGS_PLUNDER_ACK3{
	tagPKT_CLIGS_PLUNDER_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_PLUNDER_ACK3)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwEnemyID; //Ҫս�������ID
	UINT32           dwCaptureID; //��²���ID(��EnemyID��ͬ��ʾ�Ӷ����CaptureID��ң���ͬ��ʾ����CaptureID��²)
	UINT8            byUseItemFlag; //�Ƿ�ʹ�õ����Ӷ����5�����ϵ����
	UINT8            byResistFlag; //�Ƿ񷴿�(1��ʾ����)
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
	DT_BECAPTURE_DATA stBeCaptureInfo; //��²��ҵı�����Ϣ
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //ս���з������Ϣ
	UINT8            byEnemyHeroNum; //ս���з���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //ս���з���Ϣ
	DT_BATTLE_DATA3  stBattleInfo; //ս����Ϣ
	DT_PLUNDER_ENCOURAGE_DATA stPlunderEncourage; //�Ӷά��
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
	UINT16           wVipExtNum; //VIP�������ӵĴ���
	UINT16           wFreePlunderNum; //�������Ӷ����
	UINT32           dwPlunderGold; //�շ��Ӷ�Ԫ��(��������ѵ���Ϊ0)
	UINT16           wPlunderItemNum; //��ǰӵ�е��Ӷ����
	UINT8            byCaptureFlag; //�Ƿ��²��ң�1Ϊ�Է���Ϊ��ķ�²
	DT_CAPTURE_DATA_CLI astCaptureInfo[1]; //��²��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_PLUNDER_ACK3;

typedef struct tagDT_PLUNDER_BATTLELOG_DATA_CLI{
	DT_PLUNDER_BATTLELOG_DATA stBattelogInfo; //ս����Ϣ
	TCHAR            aszActiveDispName[USERNAME_LEN]; //����������ǳ�
	TCHAR            aszPassiveDispName[USERNAME_LEN]; //����������ǳ�
	TCHAR            aszCaptureDispName[USERNAME_LEN]; //��²�ǳ�
}DT_PLUNDER_BATTLELOG_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_CAPTURE_TAB_REQ{
	tagPKT_CLIGS_OPEN_CAPTURE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CAPTURE_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_CAPTURE_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_CAPTURE_TAB_ACK{
	tagPKT_CLIGS_OPEN_CAPTURE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CAPTURE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ǰͭ��
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurScience; //��ǰ�����
	UINT32           dwCurPower; //��ǰս��
	DT_BECAPTURE_DATA stOwner; //��²����Ϣ
	UINT16           wPlunderNumPerDay; //���ÿ����Ӷ����
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
	UINT16           wVipExtNum; //VIP�������ӵĴ���
	UINT16           wFreeCanPlunderNum; //��ҵ�ǰ������Ӷ����
	UINT8            byCaptureNum; //��²����
	DT_CAPTURE_DATA_CLI astCaptureInfo[MAX_CAPTURE_NUM]; //��²��Ϣ
	UINT16           awUnlockGridLevel[MAX_CAPTURE_NUM]; //��²���ӽ����ȼ���Ϣ(��˳��)
	UINT8            byUnreadPlunderBattleLogNum; //δ�ۿ��Ӷ�ս������
	DT_PLUNDER_BATTLELOG_DATA_CLI stLastBattleLog; //���һ��ս��
	UINT8            byBleedPerGoldClrMin; //ե��ÿԪ�����������
	UINT32           dwDriveAwayGold; //��������Ԫ��
	DT_PLUNDER_GRID_DATA astCaptureGridInfo[MAX_CAPTURE_NUM]; //��²������Ϣ(����û��²ʱ��Ч)
	UINT32           dwPlunderGold; //�շ��Ӷ�Ԫ��
}PKT_CLIGS_OPEN_CAPTURE_TAB_ACK;

typedef struct tagDT_ENEMY_DATA_CLI{
	UINT32           dwEnemyPlayerID; //������ID
	TCHAR            aszEnemyDispName[USERNAME_LEN]; //����ǳ�
	UINT16           wCareerID; //���ְҵ
	UINT16           wEnemyLevel; //��еȼ�
	UINT16           wBattleNum; //���ִ���
	UINT32           dwPower; //ս��
	UINT8            byHaveOwnerFlag; //�Ƿ��з�²��
	DT_BECAPTURE_DATA astOwnerInfo[1]; //��²����Ϣ
}DT_ENEMY_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_ENEMY_TAB_REQ{
	tagPKT_CLIGS_OPEN_ENEMY_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ENEMY_TAB_REQ)); }
	UINT16           wStartIdx; //��ʼ�����ţ���0��ʼ
}PKT_CLIGS_OPEN_ENEMY_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_ENEMY_TAB_ACK{
	tagPKT_CLIGS_OPEN_ENEMY_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ENEMY_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wStartIdx; //��ʼ�����ţ���0��ʼ
	UINT16           wTotalNum; //����ܸ���
	UINT16           wCurNum; //��ǰ���س�и���
	DT_ENEMY_DATA_CLI astEnemyInfo[MAX_GET_ENEMY_NUM]; //�����Ϣ
}PKT_CLIGS_OPEN_ENEMY_TAB_ACK;

typedef struct tagPKT_CLIGS_DEL_ENEMY_REQ{
	tagPKT_CLIGS_DEL_ENEMY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DEL_ENEMY_REQ)); }
	UINT32           dwEnemyID; //������ID
	UINT16           wStartIdx; //��ǰҳ��ʼ������ţ���0��ʼ
}PKT_CLIGS_DEL_ENEMY_REQ;

typedef struct tagPKT_CLIGS_DEL_ENEMY_ACK{
	tagPKT_CLIGS_DEL_ENEMY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DEL_ENEMY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwEnemyID; //������ID
	UINT16           wStartIdx; //��ʼ������ţ���0��ʼ
	UINT16           wTotalNum; //����ܸ���
	UINT16           wCurNum; //��ǰ���س�и���
	DT_ENEMY_DATA_CLI astEnemyInfo[MAX_GET_ENEMY_NUM]; //�����Ϣ
}PKT_CLIGS_DEL_ENEMY_ACK;

typedef struct tagPKT_CLIGS_PLUNDER_BATTLELOG_NTF{
	tagPKT_CLIGS_PLUNDER_BATTLELOG_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_PLUNDER_BATTLELOG_NTF)); }
	UINT8            byUnreadNum; //δ�ۿ�ս������
	DT_PLUNDER_BATTLELOG_DATA_CLI stBattleLog; //ս��
	UINT64           qwPlayerCoin; //��ҵ�ǰͭ��
	UINT64           qwPlayerScience; //��ҵ�ǰ�����
}PKT_CLIGS_PLUNDER_BATTLELOG_NTF;

typedef struct tagPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ{
	tagPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ;

typedef struct tagDT_PLUNDER_PLAYER_DATA{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT16           wMainHeroKindID; //����ID
	UINT8            byRobotFunc; //�����˹���,>0��Ϊ�����ˣ���ͬ��ֵΪ��ͬ�Ĺ��ܡ�0Ϊ���
	UINT16           wLevel; //�ȼ�
	UINT32           dwPower; //ս��
	UINT8            byHaveOwnerFlag; //�Ƿ��з�²��
	DT_BECAPTURE_DATA astOwnerInfo[1]; //��²����Ϣ
}DT_PLUNDER_PLAYER_DATA;

typedef struct tagPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK{
	tagPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
	UINT16           wFreePlunderNum; //�������Ӷ����
	UINT32           dwPlunderGold; //�շ��Ӷ�Ԫ��(��������ѵ���Ϊ0)
	UINT8            byUseItemGapLevel; //�����ټ���Ҫ1���Ӷ����
	UINT16           wPlunderItemNum; //��ǰӵ�е��Ӷ����
	UINT16           wPlunderItemID; //�Ӷ����ID
	UINT32           dwPlunderItemPrice; //�Ӷ���߼۸�
	UINT32           dwClrCDGold; //���CD����Ԫ��(ÿ����)
	UINT8            byPlunderPlayerNum; //��ǰ�����Ƽ����Ӷ���Ҹ���
	DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM]; //�Ƽ����Ӷ������Ϣ
}PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK;

typedef struct tagPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ{
	tagPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ;

typedef struct tagPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK{
	tagPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byPlunderPlayerNum; //��ǰ������Ҹ���
	DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM]; //�����Ϣ
}PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK;

typedef struct tagPKT_CLIGS_FREE_CAPTURE_REQ{
	tagPKT_CLIGS_FREE_CAPTURE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FREE_CAPTURE_REQ)); }
	UINT32           dwCapturePlayerID; //��²���ID
}PKT_CLIGS_FREE_CAPTURE_REQ;

typedef struct tagPKT_CLIGS_FREE_CAPTURE_ACK{
	tagPKT_CLIGS_FREE_CAPTURE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FREE_CAPTURE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCapturePlayerID; //��²���ID
	UINT32           dwCoinIncome; //����ͭ��
	UINT32           dwScienceIncome; //��������
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_FREE_CAPTURE_ACK;

typedef struct tagPKT_CLIGS_COLLECT_INCOME_REQ{
	tagPKT_CLIGS_COLLECT_INCOME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COLLECT_INCOME_REQ)); }
	UINT32           dwCapturePlayerID; //��²���ID
	UINT32           dwIncomeValue; //��ȡ����ֵ
}PKT_CLIGS_COLLECT_INCOME_REQ;

typedef struct tagPKT_CLIGS_COLLECT_INCOME_ACK{
	tagPKT_CLIGS_COLLECT_INCOME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COLLECT_INCOME_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCapturePlayerID; //��²���ID
	UINT32           dwIncomeValue; //��ȡ����ֵ(����ʵ������)
	DT_CAPTURE_WORK_DATA_CLI stWorkInfo; //��²����������Ϣ
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT8            byHalved; //��������־
	UINT8            byCaptureReleaseFlag; //�Ƿ����ͷŷ�²��1Ϊ�ͷ�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_COLLECT_INCOME_ACK;

typedef struct tagPKT_CLIGS_BLEED_CAPTURE_REQ{
	tagPKT_CLIGS_BLEED_CAPTURE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BLEED_CAPTURE_REQ)); }
	UINT32           dwCapturePlayerID; //��²���ID
}PKT_CLIGS_BLEED_CAPTURE_REQ;

typedef struct tagPKT_CLIGS_BLEED_CAPTURE_ACK{
	tagPKT_CLIGS_BLEED_CAPTURE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BLEED_CAPTURE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCapturePlayerID; //��²���ID
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT32           dwIncomeValue; //����ֵ
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_BLEED_CAPTURE_ACK;

typedef struct tagPKT_CLIGS_SET_WORK_TYPE_REQ{
	tagPKT_CLIGS_SET_WORK_TYPE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SET_WORK_TYPE_REQ)); }
	UINT32           dwCapturePlayerID; //��²���ID
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
}PKT_CLIGS_SET_WORK_TYPE_REQ;

typedef struct tagPKT_CLIGS_SET_WORK_TYPE_ACK{
	tagPKT_CLIGS_SET_WORK_TYPE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SET_WORK_TYPE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCapturePlayerID; //��²���ID
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	DT_CAPTURE_WORK_DATA_CLI stWorkInfo; //��²����������Ϣ
}PKT_CLIGS_SET_WORK_TYPE_ACK;

typedef struct tagDT_MONEY_TREE_DATA_CLI{
	UINT16           wCanRockNum; //����ʣ���ҡǮ����
	UINT16           wVipExtNum; //VIP�������ӵĴ���
	UINT16           wTotalCanRockNum; //�����ҡǮ����
	UINT32           dwRockNeedGold; //ҡǮ����Ԫ��
	UINT8            byMoodValue; //����ֵ
	UINT32           dwRockBaseCoin; //ҡǮ����ͭ��
	UINT8            byGetCoinRate; //�ܹ����汶��(�ٷֱ�)
	UINT16           wMoodKeepTime; //����ֵ����ʱ��(��λ��)
	UINT16           wMoodOverCountDown; //����ֵ��������ʱ
}DT_MONEY_TREE_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_MONEY_TREE_REQ{
	tagPKT_CLIGS_OPEN_MONEY_TREE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MONEY_TREE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_MONEY_TREE_REQ;

typedef struct tagPKT_CLIGS_OPEN_MONEY_TREE_ACK{
	tagPKT_CLIGS_OPEN_MONEY_TREE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MONEY_TREE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_MONEY_TREE_DATA_CLI stMoneyTreeInfo; //ҡǮ����Ϣ
	UINT16           wGetCoinRate2; //�ܹ����汶��(�ٷֱ�)
}PKT_CLIGS_OPEN_MONEY_TREE_ACK;

typedef struct tagPKT_CLIGS_ROCK_MONEY_TREE_REQ{
	tagPKT_CLIGS_ROCK_MONEY_TREE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ROCK_MONEY_TREE_REQ)); }
	UINT8            byGuideFlag; //������־(1Ϊ��������,����1����ֵ)
}PKT_CLIGS_ROCK_MONEY_TREE_REQ;

typedef struct tagPKT_CLIGS_ROCK_MONEY_TREE_ACK{
	tagPKT_CLIGS_ROCK_MONEY_TREE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ROCK_MONEY_TREE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byGuideFlag; //������־(1Ϊ��������,����1����ֵ)
	DT_MONEY_TREE_DATA_CLI stMoneyTreeInfo; //ҡǮ����Ϣ
	UINT32           dwGetCoin; //���ͭ��
	UINT64           qwPlayerCoin; //��ҵ�ǰͭ��
	UINT64           qwPlayerGold; //��ҵ�ǰԪ��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT16           wGetCoinRate2; //�ܹ����汶��(�ٷֱ�)
}PKT_CLIGS_ROCK_MONEY_TREE_ACK;

typedef struct tagPKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ{
	tagPKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ;

typedef struct tagPKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK{
	tagPKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCaptureOwnerID; //��²��
	UINT8            byShowNum; //��ʾս������
	DT_PLUNDER_BATTLELOG_DATA_CLI astBattleLogInfo[MAX_PLUNDER_BATTLELOG_NUM]; //ս����Ϣ
}PKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK;

typedef struct tagDT_GODWEAPON_ATTR_DATA{
	DT_BATTLE_ATTRIBUTE stBattleAttr; //ս������
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttr; //���ص�ս������
	DT_EXT_BATTLE_ATTRIBUTE stExtBattleAttr; //��չ��ս������
}DT_GODWEAPON_ATTR_DATA;

typedef struct tagDT_GODWEAPON_DATA_CLI{
	UINT16           wHeroKindID; //�佫����ID
	UINT16           wMaxQuality; //���Ʒ��
	UINT16           wQuality; //��ǰƷ��
	UINT16           wLevel; //�ȼ�
	DT_GODWEAPON_ATTR_DATA stIncAttr; //��������������
	DT_ATTR_INC_DATA stNextLevelIncAttr; //��һ������������
	UINT16           wQualityRequireLevel; //����������ҵȼ�Ҫ��
	UINT32           dwUpgrageScience; //��һ������������(�Ƽ�)��
	UINT64           qwRecoverScience; //�ͷ���������������(�Ƽ�)��
	UINT64           qwPerfectRecoverScience; //�����ͷ���������������(�Ƽ�)��
	UINT16           wUpgradeQualityNeedItemNum; //������Ҫ�Ľ��׵��߸���
	UINT8            byMaxLevelFlag; //�Ǵﵽ���ȼ�(1Ϊ�ﵽ���ȼ�)
	UINT8            byEncAttrNum; //��ǰƷ��
	DT_ATTR_INC_DATA astQualityUpgradeEncAttr[MAX_GODWEAPON_QUALITY_NUM]; //����Ʒ��������������
}DT_GODWEAPON_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_GODWEAPON_REQ{
	tagPKT_CLIGS_OPEN_GODWEAPON_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GODWEAPON_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_GODWEAPON_REQ;

typedef struct tagPKT_CLIGS_OPEN_GODWEAPON_ACK{
	tagPKT_CLIGS_OPEN_GODWEAPON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GODWEAPON_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wUpgradeQualityItemNum; //��ǰӵ�еĽ��׵���
	UINT32           dwUpgradeQualityItemPrice; //���׵��߼۸�
	UINT16           wUpgradeQualityItemID; //���׷�ID
	UINT32           dwActiveCoin; //��������ͭ��
	UINT64           qwPlayerScience; //��ҵ�ǰ������(�Ƽ�)��
	UINT16           wGodweaponNum; //������Ŀ
	DT_GODWEAPON_DATA_CLI astGodweaponLst[MAX_HERO_NUM]; //������Ϣ
	UINT8            byOpenNeedVipLevel; //�����ͷſ�����Ҫ��VIP�ȼ�
	UINT8            byPerfectFreeGodweapon; //�����ͷ������Ƿ����,0Ϊ������
	UINT16           wPerfectFreeGodweaponCost; //�����ͷ���������Ԫ��
	UINT64           qwCurGold; //��ǰԪ��
	TCHAR            aszExtContext[MAX_COMMON_TXT_LEN]; //�����չ��Ϣ
}PKT_CLIGS_OPEN_GODWEAPON_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_GODWEAPON_REQ{
	tagPKT_CLIGS_UPGRADE_GODWEAPON_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_GODWEAPON_REQ)); }
	UINT16           wHeroKindID; //�佫����ID
	UINT16           wQuality; //Ʒ��
	UINT16           wLevel; //�ȼ�(����ʱ��Ч)
}PKT_CLIGS_UPGRADE_GODWEAPON_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_GODWEAPON_ACK{
	tagPKT_CLIGS_UPGRADE_GODWEAPON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_GODWEAPON_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwPlayerScience; //��ҵ�ǰ������(�Ƽ�)��
	UINT16           wUpgradeQualityItemNum; //��ǰӵ�еĽ��׵���
	DT_GODWEAPON_DATA_CLI stGodweaponInfo; //������Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT64           qwCurCoin; //��ǰͭǮ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_UPGRADE_GODWEAPON_ACK;

typedef struct tagPKT_CLIGS_FREE_GODWEAPON_REQ{
	tagPKT_CLIGS_FREE_GODWEAPON_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FREE_GODWEAPON_REQ)); }
	UINT16           wHeroKindID; //�佫����ID
	UINT8            byUseGold; //�Ƿ�ʹ��Ԫ���ͷţ���0Ϊʹ��
}PKT_CLIGS_FREE_GODWEAPON_REQ;

typedef struct tagPKT_CLIGS_FREE_GODWEAPON_ACK{
	tagPKT_CLIGS_FREE_GODWEAPON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FREE_GODWEAPON_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫����ID
	UINT64           qwPlayerScience; //��ҵ�ǰ������(�Ƽ�)��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_GODWEAPON_DATA_CLI stGodweaponInfo; //������Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT64           qwCurGold; //��ǰԪ��
}PKT_CLIGS_FREE_GODWEAPON_ACK;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_TAB_REQ{
	tagPKT_CLIGS_OPEN_AWAKEN_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_TAB_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_AWAKEN_TAB_REQ;

typedef struct tagDT_STUDY_DATA_CLI{
	UINT8            byStudyColorKind; //�ĵ���ɫ����1��ʼ��0��ʾû������
	UINT8            byStudyAttrKind; //�ĵ�����(��Ӧ��������)
	UINT8            byStudyLevel; //�ĵõȼ�(��1��ʼ��������0)
	UINT32           dwStudyAttrValue; //�ĵ�����ֵ
	UINT32           dwStudyExp; //�ĵþ���ֵ
	UINT32           dwNextLevelAttrValue; //��һ���ĵ�����ֵ
	UINT32           dwUpgradeNeedExp; //��������һ�������ĵþ���
}DT_STUDY_DATA_CLI;

typedef struct tagDT_AWAKEN_TAB_DATA{
	DT_AWAKEN_BASE_DATA1 stBaseInfo; //���������Ϣ
	DT_STUDY_DATA_CLI astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT16           wMaxStudyLevel; //�ĵ����ȼ�
	UINT32           adwAwakenCoin[MAX_AWAKEN_NUM]; //�������ͭ��
	UINT32           dwAwakenGold; //�������Ԫ��
	UINT16           wTatalCallNum; //�ܹ����ٻ�����
	UINT16           wCanCallNum; //ʣ����ٻ�����
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
}DT_AWAKEN_TAB_DATA;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_TAB_ACK{
	tagPKT_CLIGS_OPEN_AWAKEN_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_AWAKEN_TAB_DATA stAwakenInfo; //��������Ϣ
}PKT_CLIGS_OPEN_AWAKEN_TAB_ACK;

typedef struct tagPKT_CLIGS_AWAKEN_REQ{
	tagPKT_CLIGS_AWAKEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_AWAKEN_REQ)); }
	UINT8            byQuickFlag; //�Ƿ�ʹ��һ�������һ�����ʱԪ�������Ч
	UINT8            byGoldFlag; //�Ƿ�ʹ��Ԫ�����
}PKT_CLIGS_AWAKEN_REQ;

typedef struct tagDT_AWAKEN_GET_DATA{
	UINT32           dwGetCoin; //����ͭǮ
	UINT8            byStudyBagIdx; //�����ĵ����(��Ӧ�ĵñ�����ţ���0��ʼ)������ͭǮΪ0ʱ��Ч
	UINT8            byAwakenLevel; //����ȼ�
}DT_AWAKEN_GET_DATA;

typedef struct tagPKT_CLIGS_AWAKEN_ACK{
	tagPKT_CLIGS_AWAKEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_AWAKEN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byQuickFlag; //�Ƿ�ʹ��һ�������һ�����ʱԪ�������Ч
	UINT8            byGoldFlag; //�Ƿ�ʹ��Ԫ�����
	UINT8            byAwakenNum; //�ܹ��������
	DT_AWAKEN_GET_DATA astAwakenGetInfo[MAX_AWAKEN_NUM]; //���������Ϣ
	DT_AWAKEN_TAB_DATA stAwakenTabInfo; //��������Ϣ
}PKT_CLIGS_AWAKEN_ACK;

typedef struct tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ{
	tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ;

typedef struct tagDT_HERO_STUDY_DATA_CLI{
	UINT16           wHeroID; //�佫ID
	DT_STUDY_DATA_CLI astStudyInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵ���Ϣ
}DT_HERO_STUDY_DATA_CLI;

typedef struct tagDT_DRESS_STUDY_TAB_DATA{
	DT_STUDY_DATA_CLI astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT16           awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵý����ȼ���Ϣ
	UINT8            byHeroNum; //�佫����
	DT_HERO_STUDY_DATA_CLI astHeroStudyInfo[MAX_FORMATION_IDX_NUM]; //�佫�ĵ���Ϣ
	UINT64           qwStudyExp; //�ĵþ���
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
}DT_DRESS_STUDY_TAB_DATA;

typedef struct tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK{
	tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_DRESS_STUDY_TAB_DATA stDressStudyTabInfo; //�����ĵ������Ϣ
}PKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK;

typedef struct tagPKT_CLIGS_DRESS_STUDY_REQ{
	tagPKT_CLIGS_DRESS_STUDY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_STUDY_REQ)); }
	UINT16           wHeroKindID; //�佫ID
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byHeroGridIdx; //�佫�ĵ�λ�ã���0��ʼ
}PKT_CLIGS_DRESS_STUDY_REQ;

typedef struct tagPKT_CLIGS_DRESS_STUDY_ACK{
	tagPKT_CLIGS_DRESS_STUDY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_STUDY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byHeroGridIdx; //�佫�ĵ�λ�ã���0��ʼ
	DT_STUDY_DATA_CLI astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	DT_HERO_STUDY_DATA_CLI stHeroStudyInfo; //�佫�ĵ���Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_DRESS_STUDY_ACK;

typedef struct tagPKT_CLIGS_STUDY_TO_EXP_REQ{
	tagPKT_CLIGS_STUDY_TO_EXP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_TO_EXP_REQ)); }
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byAllFlag; //ת�������ĵñ����е��ĵ�,1ת������
	UINT8            abySelectConvertColor[MAX_COLOR_NUM]; //ѡ��ת������ɫ(��Ӧ��ɫ�±�-1��0��ʾ��ת����1��ʾ��ת��)
}PKT_CLIGS_STUDY_TO_EXP_REQ;

typedef struct tagPKT_CLIGS_STUDY_TO_EXP_ACK{
	tagPKT_CLIGS_STUDY_TO_EXP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_TO_EXP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            abySelectConvertColor[MAX_COLOR_NUM]; //ת������ɫ(��Ӧ��ɫ�±�-1��0��ʾ��ת����1��ʾ��ת��)
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byAllFlag; //ת�������ĵñ����е��ĵ�,1ת������
	UINT32           dwGenStudyExp; //ת�������ĵþ���
	DT_STUDY_DATA_CLI astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT64           qwCurStudyExp; //��ǰ�ĵþ���
}PKT_CLIGS_STUDY_TO_EXP_ACK;

typedef struct tagPKT_CLIGS_STUDY_UPGRADE_REQ{
	tagPKT_CLIGS_STUDY_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_UPGRADE_REQ)); }
	UINT16           wHeroKindID; //�佫ID
	UINT8            byGridIdx; //�ĵ�λ�ã���0��ʼ
	UINT8            byLevel; //Ҫ�������ĵȼ�
}PKT_CLIGS_STUDY_UPGRADE_REQ;

typedef struct tagPKT_CLIGS_STUDY_UPGRADE_ACK{
	tagPKT_CLIGS_STUDY_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_UPGRADE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID
	UINT8            byGridIdx; //�ĵ�λ�ã���0��ʼ
	UINT8            byLevel; //Ҫ�������ĵȼ�
	DT_HERO_STUDY_DATA_CLI stHeroStudyInfo; //�佫�ĵ���Ϣ
	UINT64           qwCurStudyExp; //��ǰ�ĵþ���
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_STUDY_UPGRADE_ACK;

typedef struct tagPKT_CLIGS_RACE_BATTLELOG_NTF{
	tagPKT_CLIGS_RACE_BATTLELOG_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_RACE_BATTLELOG_NTF)); }
	UINT8            byUnreadNum; //δ�ۿ�ս������
	DT_RACE_BATTLELOG_DATA_CLI stBattleLog; //ս��
	UINT64           qwPlayerCoin; //��ҵ�ǰͭ��
	UINT64           qwPlayerScience; //��ҵ�ǰ�����
}PKT_CLIGS_RACE_BATTLELOG_NTF;

typedef struct tagPKT_CLIGS_BUY_PHYSTRENGTH_REQ{
	tagPKT_CLIGS_BUY_PHYSTRENGTH_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_PHYSTRENGTH_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_BUY_PHYSTRENGTH_REQ;

typedef struct tagPKT_CLIGS_BUY_PHYSTRENGTH_ACK{
	tagPKT_CLIGS_BUY_PHYSTRENGTH_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_PHYSTRENGTH_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCurPhyStrength; //��ǰ����
	UINT64           qwCurGold; //��ǰԪ��
	UINT8            byCanBuyNum; //ʣ�๺�����
	UINT16           wVipExtNum; //VIP�������ӵĹ������
	UINT32           dwNextBuyGold; //�´ι�������Ԫ��
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
}PKT_CLIGS_BUY_PHYSTRENGTH_ACK;

typedef struct tagPKT_CLIGS_CLR_PLUNDER_CD_REQ{
	tagPKT_CLIGS_CLR_PLUNDER_CD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_PLUNDER_CD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_CLR_PLUNDER_CD_REQ;

typedef struct tagPKT_CLIGS_CLR_PLUNDER_CD_ACK{
	tagPKT_CLIGS_CLR_PLUNDER_CD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_PLUNDER_CD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
}PKT_CLIGS_CLR_PLUNDER_CD_ACK;

typedef struct tagPKT_CLIGS_OPEN_MAINTOWN_REQ{
	tagPKT_CLIGS_OPEN_MAINTOWN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MAINTOWN_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_MAINTOWN_REQ;

typedef struct tagPKT_CLIGS_OPEN_MAINTOWN_ACK{
	tagPKT_CLIGS_OPEN_MAINTOWN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MAINTOWN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCurLevel; //��ǰ��ҵȼ�
	UINT8            byCanCrowFlag; //�Ƿ���ջ�1��ʾ���ջ�
	UINT32           dwCrownCoin; //���ջ�ͭǮ
	UINT32           dwCrownGold; //���ջ�Ԫ��
	UINT32           dwCrownJingJie; //���ջ񾳽��
	UINT32           dwLevyCountDown; //���յĵ���ʱ
	UINT32           dwLevyCoin; //�����յ�ͭ��
	UINT32           dwLevyJingJie; //�����յľ����
	UINT8            byLevyNum; //�����յĴ���
	UINT8            byTotalLevyNum; //���յ��ܴ���
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurJingJie; //��ǰ�����
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_OPEN_MAINTOWN_ACK;

typedef struct tagPKT_CLIGS_RECV_MAINTOWN_INCOME_REQ{
	tagPKT_CLIGS_RECV_MAINTOWN_INCOME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_MAINTOWN_INCOME_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_RECV_MAINTOWN_INCOME_REQ;

typedef struct tagPKT_CLIGS_RECV_MAINTOWN_INCOME_ACK{
	tagPKT_CLIGS_RECV_MAINTOWN_INCOME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_MAINTOWN_INCOME_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byCanCrowFlag; //�Ƿ���ջ�1��ʾ���ջ�
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurJingJie; //��ǰ����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_RECV_MAINTOWN_INCOME_ACK;

typedef struct tagPKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ{
	tagPKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ;

typedef struct tagPKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK{
	tagPKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurJingJie; //��ǰ����
	UINT32           dwLevyCountDown; //���յĵ���ʱ
	UINT8            byLevyNum; //�����յĴ���
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK;

typedef struct tagPKT_CLIGS_DRIVE_AWAY_OWNER_REQ{
	tagPKT_CLIGS_DRIVE_AWAY_OWNER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRIVE_AWAY_OWNER_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_DRIVE_AWAY_OWNER_REQ;

typedef struct tagPKT_CLIGS_DRIVE_AWAY_OWNER_ACK{
	tagPKT_CLIGS_DRIVE_AWAY_OWNER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRIVE_AWAY_OWNER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ǰԪ��
	UINT32           dwDriveAwayGold; //��������Ԫ��
}PKT_CLIGS_DRIVE_AWAY_OWNER_ACK;

typedef struct tagPKT_CLIGS_COMPOSE_EQUIP_REQ{
	tagPKT_CLIGS_COMPOSE_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COMPOSE_EQUIP_REQ)); }
	UINT16           wEquipItemID; //װ��ID
	UINT16           wEquipIdx; //װ��ID
	UINT8            byGoldComposeFlag; //Ԫ���ϳɱ�־,1ΪԪ���ϳ�
}PKT_CLIGS_COMPOSE_EQUIP_REQ;

typedef struct tagPKT_CLIGS_COMPOSE_EQUIP_ACK{
	tagPKT_CLIGS_COMPOSE_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COMPOSE_EQUIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wSrcEquipItemID; //ԭװ��ID
	UINT16           wSrcEquipIdx; //ԭװ��ID
	UINT8            bySrcItemNum; //ԭװ��������Ϣ
	DT_NEED_ITEM_DATA astStrItemInfoList[MAX_ITEM_MAKER_NEED_NUM]; //ԭװ��������Ϣ���������Ϣ
	DT_EQUIP_DATA_CLI stEquipInfo; //װ����Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //װ��ǿ����Ϣ
	UINT64           qwCurGold; //��ҵ�ǰԪ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_COMPOSE_EQUIP_ACK;

typedef struct tagDT_ACTIVITY_TIME_DATA{
	UINT8            byStartHour; //�����ʱ�䣬Сʱ
	UINT8            byStartMin; //�����ʱ�䣬����
	UINT16           wKeepTime; //�����ʱ��
	UINT16           wEndCountDown; //���������ʱ����ʱ,�ڻʱ������Ч
	UINT16           wAheadTime; //��ǰ����ʱ��(��λ��)
	UINT8            byHaveFinishFlag; //�Ƿ�����ɣ�1�����
}DT_ACTIVITY_TIME_DATA;

typedef struct tagDT_ACTIVITY_BASE_DATA{
	UINT8            byKindID; //�����
	UINT8            byActivityTimeNum; //�ʱ�����
	DT_ACTIVITY_TIME_DATA astActivityTimeInfo[MAX_ACTIVITY_TIME_NUM]; //�ʱ�����Ϣ
	UINT8            byNotity; //�Ƿ��֪ͨ
}DT_ACTIVITY_BASE_DATA;

typedef struct tagPKT_CLIGS_OPEN_PHYSTRENGTH_REQ{
	tagPKT_CLIGS_OPEN_PHYSTRENGTH_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PHYSTRENGTH_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδ��
}PKT_CLIGS_OPEN_PHYSTRENGTH_REQ;

typedef struct tagPKT_CLIGS_OPEN_PHYSTRENGTH_ACK{
	tagPKT_CLIGS_OPEN_PHYSTRENGTH_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PHYSTRENGTH_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byStrength; //����ֵ
	UINT8            byTotalBuyTimes; //�ܹ��������
	UINT8            byBuyTimes; //�������
	UINT16           wVipExtNum; //VIP�������ӵ���ս����
	UINT32           dwBuyGold; //���ѵ�Ԫ��
	UINT8            byActivityNum; //�������
	DT_ACTIVITY_BASE_DATA astActivityInfo[MAX_ACTIVITY_NUM]; //�����
}PKT_CLIGS_OPEN_PHYSTRENGTH_ACK;

typedef struct tagPKT_CLIGS_RECV_LEFT_INCOME_REQ{
	tagPKT_CLIGS_RECV_LEFT_INCOME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_LEFT_INCOME_REQ)); }
	UINT8            byGridIdx; //�������(��0��ʼ)
}PKT_CLIGS_RECV_LEFT_INCOME_REQ;

typedef struct tagPKT_CLIGS_RECV_LEFT_INCOME_ACK{
	tagPKT_CLIGS_RECV_LEFT_INCOME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_LEFT_INCOME_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byGridIdx; //�������(��0��ʼ)
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT32           dwIncomeValue; //����ֵ
	UINT64           qwCurCoin; //��ǰͭ��
	UINT64           qwCurScience; //��ǰ����
}PKT_CLIGS_RECV_LEFT_INCOME_ACK;

typedef struct tagPKT_CLIGS_SMITHY_BUY_EQUIP_REQ{
	tagPKT_CLIGS_SMITHY_BUY_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SMITHY_BUY_EQUIP_REQ)); }
	UINT16           wHeroKindID; //�佫ID
	UINT8            byEquipPos; //װ��λ��
}PKT_CLIGS_SMITHY_BUY_EQUIP_REQ;

typedef struct tagPKT_CLIGS_SMITHY_BUY_EQUIP_ACK{
	tagPKT_CLIGS_SMITHY_BUY_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SMITHY_BUY_EQUIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EQUIP_DATA_CLI stEquipInfo; //װ����Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //װ��ǿ����Ϣ
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT32           dwStrengthen10Coin; //װ����10������ҪͭǮ��Ϣ
}PKT_CLIGS_SMITHY_BUY_EQUIP_ACK;

typedef struct tagPKT_CLIGS_CLR_STRENGTHEN_CD_REQ{
	tagPKT_CLIGS_CLR_STRENGTHEN_CD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_STRENGTHEN_CD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_CLR_STRENGTHEN_CD_REQ;

typedef struct tagPKT_CLIGS_CLR_STRENGTHEN_CD_ACK{
	tagPKT_CLIGS_CLR_STRENGTHEN_CD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_STRENGTHEN_CD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
}PKT_CLIGS_CLR_STRENGTHEN_CD_ACK;

typedef struct tagDT_CROP_SEED_INFO_DATA{
	UINT16           wCropKindID; //����ID
	UINT16           wCropSeedNum; //���Ӹ���
	UINT8            byCropType; //��ֲ����
	UINT32           dwCropTime; //��ֲʱ��
	UINT32           dwCropValue; //��������
	UINT16           wCropGainKindID; //�������ƷID
	UINT32           dwCoin; //����ͭ�Ҽ۸�
	UINT32           dwGold; //����Ԫ���۸�
	UINT16           wComposeCount; //���Ӻϳ�����Ҫ����
	UINT16           wComposeKindID; //�ϳ�����ID
}DT_CROP_SEED_INFO_DATA;

typedef struct tagDT_CROP_FIELD_INFO_DATA{
	UINT8            byOpen; //��ؿ���
	UINT8            byLevel; //��Ҫ�ĵȼ�
	UINT32           dwCoin; //���ѵ�ͭ��
	UINT32           dwGold; //���ѵ�Ԫ��
}DT_CROP_FIELD_INFO_DATA;

typedef struct tagDT_CROP_MORE_INFO_DATA{
	UINT16           wCropKindID; //��ֲID
	UINT32           dwCropTime; //�ջ񵹼�ʱ��
	UINT8            byCropType; //��ֲ����
	UINT32           dwCropValue; //��������
	UINT16           wCropGainKindID; //�������ƷID
}DT_CROP_MORE_INFO_DATA;

typedef struct tagPKT_CLIGS_OPEN_CROP_REQ{
	tagPKT_CLIGS_OPEN_CROP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_CROP_REQ;

typedef struct tagPKT_CLIGS_OPEN_CROP_ACK{
	tagPKT_CLIGS_OPEN_CROP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byCropSeedNum; //���Ӹ���
	DT_CROP_SEED_INFO_DATA astCropSeedInfoList[MAX_CROP_SEED_NUM]; //������Ϣ
	DT_CROP_FIELD_INFO_DATA astCropFieldInfoList[MAX_CROP_NUM]; //�����Ϣ
	DT_CROP_MORE_INFO_DATA astCropMoreInfoList[MAX_CROP_NUM]; //��ֲ��Ϣ
	UINT16           wNoCDGoldPerMin; //�������ÿ��������Ԫ��
	UINT8            byBagFullFlag; //�����Ƿ�����1Ϊ��
	UINT64           qwGold; //Ԫ��
	UINT64           qwCoin; //ͭǮ
	UINT64           qwScience; //����
	UINT64           qwStory; //����
	UINT64           qwJingJie; //����
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_OPEN_CROP_ACK;

typedef struct tagPKT_CLIGS_OPEN_CROP_FIELD_REQ{
	tagPKT_CLIGS_OPEN_CROP_FIELD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_FIELD_REQ)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_OPEN_CROP_FIELD_REQ;

typedef struct tagPKT_CLIGS_OPEN_CROP_FIELD_ACK{
	tagPKT_CLIGS_OPEN_CROP_FIELD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_FIELD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	DT_CROP_FIELD_INFO_DATA stCropFieldInfo; //�����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_OPEN_CROP_FIELD_ACK;

typedef struct tagPKT_CLIGS_CROP_REQ{
	tagPKT_CLIGS_CROP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CROP_REQ)); }
	UINT8            byFieldID; //���ID
	UINT16           wCropKindID; //����ID
}PKT_CLIGS_CROP_REQ;

typedef struct tagPKT_CLIGS_CROP_ACK{
	tagPKT_CLIGS_CROP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CROP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	DT_CROP_MORE_INFO_DATA stCropMoreInfo; //��ֲ��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_CROP_FIELD_INFO_DATA stCropFieldInfo; //�����Ϣ
}PKT_CLIGS_CROP_ACK;

typedef struct tagPKT_CLIGS_GAIN_CROP_REQ{
	tagPKT_CLIGS_GAIN_CROP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GAIN_CROP_REQ)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_GAIN_CROP_REQ;

typedef struct tagPKT_CLIGS_GAIN_CROP_ACK{
	tagPKT_CLIGS_GAIN_CROP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GAIN_CROP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCoin; //ͭǮ
	UINT64           qwScience; //����
	UINT64           qwStory; //����
	UINT64           qwJingJie; //����
	UINT8            byCropType; //��ֲ����
	UINT32           dwCropValue; //��������
	UINT16           wCropKindID; //������ƷID
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_CROP_MORE_INFO_DATA stCropMoreInfo; //��ֲ��Ϣ
	DT_CROP_FIELD_INFO_DATA stCropFieldInfo; //�����Ϣ
}PKT_CLIGS_GAIN_CROP_ACK;

typedef struct tagPKT_CLIGS_CLR_CROP_REQ{
	tagPKT_CLIGS_CLR_CROP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_CROP_REQ)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_CLR_CROP_REQ;

typedef struct tagPKT_CLIGS_CLR_CROP_ACK{
	tagPKT_CLIGS_CLR_CROP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_CROP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	UINT64           qwGold; //Ԫ��
	DT_CROP_MORE_INFO_DATA stCropMoreInfo; //��ֲ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_CLR_CROP_ACK;

typedef struct tagPKT_CLIGS_OPEN_EXPERIENCE_REQ{
	tagPKT_CLIGS_OPEN_EXPERIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EXPERIENCE_REQ)); }
	UINT16           wHeroID; //�佫ID
}PKT_CLIGS_OPEN_EXPERIENCE_REQ;

typedef struct tagDT_EXPERIENCE_DRUG_DATA{
	UINT16           wExperienceDrugID; //���鵤�ȼ�
	UINT32           dwExperience; //���Ӿ���ֵ
	UINT16           wBagNum; //�������鵤����
}DT_EXPERIENCE_DRUG_DATA;

typedef struct tagDT_GOLD_EXPERIENCE_DRUG_DATA{
	UINT16           wExperienceDrugID; //���鵤ID��99��
	UINT32           dwExperience; //���Ӿ���ֵ
	UINT32           dwCostGold; //����Ԫ��
	UINT16           wRemainNum; //���鵤ʣ��ʹ��
	UINT16           wOpenVipLevel; //������VIP�ȼ�
	UINT16           wMaxNum; //��ǰVIP�ܴ���
	UINT16           wNextVipLevelMaxNum; //�¼�VIP�ܴ��������VIP��������Ϊ0
}DT_GOLD_EXPERIENCE_DRUG_DATA;

typedef struct tagPKT_CLIGS_OPEN_EXPERIENCE_ACK{
	tagPKT_CLIGS_OPEN_EXPERIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EXPERIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wLevel; //�佫�ȼ�
	UINT32           dwExperience; //��ǰ����
	UINT32           dwUpgradeExperience; //��������
	DT_EXPERIENCE_DRUG_DATA astExperienceDrugDataList[3]; //���鵤��Ϣ
	DT_GOLD_EXPERIENCE_DRUG_DATA stGoldExperienceDrugData; //Ԫ�����鵤��Ϣ
}PKT_CLIGS_OPEN_EXPERIENCE_ACK;

typedef struct tagPKT_CLIGS_USER_EXPERIENCE_REQ{
	tagPKT_CLIGS_USER_EXPERIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_USER_EXPERIENCE_REQ)); }
	UINT16           wHeroID; //�佫ID
	UINT16           wExperienceDrugID; //���鵤ID
	UINT16           wRemainGoldExperienceDrugCnt; //���鵤�����������Ԫ�����鵤���ͻ�������Ҫ�ϴ���ǰʣ�������
}PKT_CLIGS_USER_EXPERIENCE_REQ;

typedef struct tagPKT_CLIGS_USER_EXPERIENCE_ACK{
	tagPKT_CLIGS_USER_EXPERIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_USER_EXPERIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EXPERIENCE_DRUG_DATA stExperienceDrugData; //���鵤��Ϣ
	DT_GOLD_EXPERIENCE_DRUG_DATA stGoldExperienceDrugData; //Ԫ�����鵤��Ϣ
	DT_POWER_CHANGE_DATA stPowerChangeData; //�佫ս����Ϣ
	DT_HERO_BASE_DATA_CLI stHeroBaseDataCli; //�佫�����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT64           qwCurGold; //��ǰԪ��
}PKT_CLIGS_USER_EXPERIENCE_ACK;

typedef struct tagPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ{
	tagPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_SCIENCE_BUILD_REQ;

typedef struct tagDT_SCIENCE_ALREADY_OPEN_DATA{
	UINT8            byKind; //��������
	UINT16           wLevel; //����
	UINT32           dwCurValue; //��ǰ��ֵ
	UINT32           dwNextValue; //��������ֵ
	UINT32           dwCostStory; //������������
	UINT16           wNeedPlayerLevel; //������������ȼ�
	UINT8            byMaxLevel; //�Ƿ�����
}DT_SCIENCE_ALREADY_OPEN_DATA;

typedef struct tagDT_SCIENCE_WILL_OPEN_DATA{
	UINT8            byKind; //��������
	UINT16           wOpenLevel; //���ŵȼ�
	UINT32           dwLv1Value; //��һ������ֵ
	UINT32           dwCostStory; //������������
}DT_SCIENCE_WILL_OPEN_DATA;

typedef struct tagPKT_CLIGS_OPEN_SCIENCE_BUILD_ACK{
	tagPKT_CLIGS_OPEN_SCIENCE_BUILD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SCIENCE_BUILD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurStory; //��ǰ����ֵ
	UINT8            byAlreadyOpenScienceNum; //�Ѿ��������ĿƼ���
	DT_SCIENCE_ALREADY_OPEN_DATA astAlreadyOpenScienceList[MAX_SCIENCE_KIND_NUM]; //�Ѿ��������ĿƼ��б�
	UINT8            byWillOpenScienceNum; //��Ҫ���Դ򿪵ĿƼ���
	DT_SCIENCE_WILL_OPEN_DATA astWillOpenScienceList[MAX_SCIENCE_KIND_NUM]; //��Ҫ���Դ򿪵ĿƼ��б�
}PKT_CLIGS_OPEN_SCIENCE_BUILD_ACK;

typedef struct tagPKT_CLIGS_UPDATE_SCIENCE_REQ{
	tagPKT_CLIGS_UPDATE_SCIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPDATE_SCIENCE_REQ)); }
	UINT16           wCurLevel; //��ǰ�ȼ�
	UINT8            byKind; //��������������
}PKT_CLIGS_UPDATE_SCIENCE_REQ;

typedef struct tagPKT_CLIGS_UPDATE_SCIENCE_ACK{
	tagPKT_CLIGS_UPDATE_SCIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPDATE_SCIENCE_ACK)); }
	UINT16           wErrorCode; //��������
	DT_SCIENCE_ALREADY_OPEN_DATA stUpdatedData; //������������Ϣ
	DT_POWER_CHANGE_DATA stPower; //ս���ı����
	UINT64           qwCurStory; //��ǰ����ֵ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_UPDATE_SCIENCE_ACK;

typedef struct tagPKT_CLIGS_OPEN_MELT_EQUIP_REQ{
	tagPKT_CLIGS_OPEN_MELT_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MELT_EQUIP_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_MELT_EQUIP_REQ;

typedef struct tagPKT_CLIGS_OPEN_MELT_EQUIP_ACK{
	tagPKT_CLIGS_OPEN_MELT_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MELT_EQUIP_ACK)); }
	UINT16           wErrorCode; //��������
	DT_EQUIP_MELT_DATA_LST_CLI stEquipInfo; //װ����Ϣ
	DT_GOOD_MELT_DATA_LST_CLI stGoodInfo; //��Ʒ��Ϣ
}PKT_CLIGS_OPEN_MELT_EQUIP_ACK;

typedef struct tagDT_MELT_EQUIP_DATA{
	UINT16           wEquipID; //װ��ID
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
}DT_MELT_EQUIP_DATA;

typedef struct tagDT_MELT_GOOD_DATA{
	UINT16           wKindID; //��ƷID
	UINT16           wNum; //��Ʒ����
}DT_MELT_GOOD_DATA;

typedef struct tagPKT_CLIGS_MELT_REQ{
	tagPKT_CLIGS_MELT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MELT_REQ)); }
	UINT16           wEquipNum; //װ������
	DT_MELT_EQUIP_DATA astMeltEquipDataList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
	UINT8            byGoldFlag; //�Ƿ�Ԫ������,1Ԫ������
	UINT16           wGoodNum; //��Ʒ����
	DT_MELT_GOOD_DATA astMeltGoodDataList[MAX_BAG_OPEN_NUM]; //��Ʒ��Ϣ
}PKT_CLIGS_MELT_REQ;

typedef struct tagPKT_CLIGS_MELT_ACK{
	tagPKT_CLIGS_MELT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MELT_ACK)); }
	UINT16           wErrorCode; //��������
	UINT32           dwAddScience; //���������
	UINT64           qwScience; //��ǰ�����
	DT_EQUIP_MELT_DATA_LST_CLI stEquipInfo; //װ����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ����
	DT_GOOD_MELT_DATA_LST_CLI stGoodInfo; //��Ʒ��Ϣ
}PKT_CLIGS_MELT_ACK;

typedef struct tagPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ{
	tagPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ)); }
	UINT16           wKindID; //�������ID
	UINT8            byAttrKind; //��������ID
}PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ;

typedef struct tagDT_UPDATE_ATTR_DATA{
	UINT8            byAttrKind; //��������
	UINT16           wCurCount; //��ǰ����
	UINT16           wTotalCount; //�ܴ���
	UINT32           dwCurLevelValue; //��ǰ��ֵ
	UINT32           dwNextLevelValue; //�¼���ֵ
	UINT32           dwCostCoin; //��������ͭǮ����
	UINT32           dwCostItemNum; //�������ĵ�������
	UINT64           qwCurCoinNum; //ͭǮ
	UINT32           dwItemID; //��ƷID
	UINT32           dwItemNum; //��Ʒ������
}DT_UPDATE_ATTR_DATA;

typedef struct tagPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK{
	tagPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK)); }
	UINT16           wErrorCode; //��������
	DT_UPDATE_ATTR_DATA stUpdateAttr; //��������
}PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK;

typedef struct tagPKT_CLIGS_UPDATE_ATTR_REQ{
	tagPKT_CLIGS_UPDATE_ATTR_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPDATE_ATTR_REQ)); }
	UINT16           wKindID; //�������ID
	UINT16           wCurCount; //��ǰ����
	UINT8            byAttrType; //��������
	UINT8            byUpdateType; //����������ʽ
}PKT_CLIGS_UPDATE_ATTR_REQ;

typedef struct tagDT_UPDATED_ATTR_BATTLE_DATA{
	UINT32           dwOldTotalPower; //�ɵ���ս��
	UINT32           dwTotalPower; //��ս��
	UINT32           dwSelfOldPower; //�ɵ�ս��
	UINT32           dwSelfPower; //ս��
	UINT32           dwHPValue; //Ѫ��
	UINT32           dwAttackValue; //������
}DT_UPDATED_ATTR_BATTLE_DATA;

typedef struct tagPKT_CLIGS_UPDATE_ATTR_ACK{
	tagPKT_CLIGS_UPDATE_ATTR_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPDATE_ATTR_ACK)); }
	UINT16           wErrorCode; //��������
	UINT16           wKindID; //�佫����
	DT_UPDATE_ATTR_DATA stAttrRet; //��ǰ����������Ϣ
	DT_UPDATED_ATTR_BATTLE_DATA stBattleInfo; //�����������ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_UPDATE_ATTR_ACK;

typedef struct tagPKT_CLIGS_COMPOSE_REQ{
	tagPKT_CLIGS_COMPOSE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COMPOSE_REQ)); }
	UINT16           wItemID; //�ϳɵ���ƷID
	UINT8            byComposeFlag; //�ϳ����ͱ�ʶ��1Ϊ��Ƕ���ϳ�,0Ϊ��ͨ�ϳ�,2 Ϊ�������װ���ϳɣ�3Ϊ���������Ʒ�ϳ�
}PKT_CLIGS_COMPOSE_REQ;

typedef struct tagPKT_CLIGS_COMPOSE_ACK{
	tagPKT_CLIGS_COMPOSE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COMPOSE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_ITEM_DATA_CLI2 stItemInfo; //���ɵĵ�����Ϣ
	DT_ITEM_DATA_LIST_CLI2 stGoodsBagItemInfo; //��Ʒ������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_ITEM_DATA_LIST_CLI3 stGoodsBagItemInfo2; //��Ʒ������Ϣ
	DT_ITEM_NUM_DATA_LIST_CLI stBagItemNumInfo; //�����и���Ʒ�ĵ�ǰ������Ϣ
}PKT_CLIGS_COMPOSE_ACK;

typedef struct tagPKT_CLIGS_REFRESH_ELITE_REQ{
	tagPKT_CLIGS_REFRESH_ELITE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REFRESH_ELITE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_REFRESH_ELITE_REQ;

typedef struct tagPKT_CLIGS_REFRESH_ELITE_ACK{
	tagPKT_CLIGS_REFRESH_ELITE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REFRESH_ELITE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ǰ���Ԫ��
}PKT_CLIGS_REFRESH_ELITE_ACK;

typedef struct tagPKT_CLIGS_ONHOOK_ELITE_REQ{
	tagPKT_CLIGS_ONHOOK_ELITE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ONHOOK_ELITE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_ONHOOK_ELITE_REQ;

typedef struct tagPKT_CLIGS_ONHOOK_ELITE_ACK{
	tagPKT_CLIGS_ONHOOK_ELITE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ONHOOK_ELITE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_ONHOOK_ELITE_ACK;

typedef struct tagPKT_CLIGS_GET_ITEM_REQ{
	tagPKT_CLIGS_GET_ITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ITEM_REQ)); }
	UINT16           wItemKindID; //��ƷID
}PKT_CLIGS_GET_ITEM_REQ;

typedef struct tagPKT_CLIGS_GET_ITEM_ACK{
	tagPKT_CLIGS_GET_ITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ITEM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wItemKindID; //��ƷID
	UINT16           wItemNum; //������Ʒ����
	UINT8            byshop; //j�̵���Ʒ�Ƿ�ɹ���
	UINT8            byTab; //�̵����
	DT_INSTANCE_ID   stBurstInstance; //���ܵ���ĸ���
}PKT_CLIGS_GET_ITEM_ACK;

typedef struct tagPKT_CLIGS_GET_ORDER_ID_REQ{
	tagPKT_CLIGS_GET_ORDER_ID_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ORDER_ID_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_ORDER_ID_REQ;

typedef struct tagPKT_CLIGS_GET_ORDER_ID_ACK{
	tagPKT_CLIGS_GET_ORDER_ID_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ORDER_ID_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	TCHAR            aszOrderID[MAX_ORDER_ID_LEN]; //������
}PKT_CLIGS_GET_ORDER_ID_ACK;

typedef struct tagPKT_CLIGS_EXCHANGE_RESULT{
	tagPKT_CLIGS_EXCHANGE_RESULT() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_RESULT)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwGold; //��ǰԪ����
	UINT32           dwExchangeGold; //��ֵԪ����
	UINT8            byVipLevel; //VIP�ȼ�
	UINT32           dwTotalExchangeGold; //�ܳ�ֵ��
}PKT_CLIGS_EXCHANGE_RESULT;

typedef struct tagPKT_CLIGS_CHECK_APPSTORE_ORDER_ID_REQ{
	tagPKT_CLIGS_CHECK_APPSTORE_ORDER_ID_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHECK_APPSTORE_ORDER_ID_REQ)); }
	CHAR             szTransactionID[MAX_RECEIPT_DATA_LEN]; //������
	CHAR             szReceiptData[MAX_RECEIPT_DATA_LEN]; //�ͻ���AppStore���صĳ�ֵ�ֶ�
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_CHECK_APPSTORE_ORDER_ID_REQ;

typedef struct tagPKT_CLIGS_CHECK_APPSTORE_ORDER_ID_ACK{
	tagPKT_CLIGS_CHECK_APPSTORE_ORDER_ID_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHECK_APPSTORE_ORDER_ID_ACK)); }
	UINT16           wErrCode; //������
	UINT32           dwExchangeGold; //��ֵԪ����
	UINT64           qwGold; //��ǰԪ����
	UINT8            byVipLevel; //VIP�ȼ�
	UINT32           dwTotalExchangeGold; //�ܳ�ֵ��
	CHAR             szTransactionID[MAX_RECEIPT_DATA_LEN]; //������
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_CHECK_APPSTORE_ORDER_ID_ACK;

typedef struct tagPKT_CLIGS_SEED_COMPOSE_REQ{
	tagPKT_CLIGS_SEED_COMPOSE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEED_COMPOSE_REQ)); }
	UINT16           wItemID; //�ϳɵ���ƷID
}PKT_CLIGS_SEED_COMPOSE_REQ;

typedef struct tagPKT_CLIGS_SEED_COMPOSE_ACK{
	tagPKT_CLIGS_SEED_COMPOSE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SEED_COMPOSE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_ITEM_DATA_CLI2 stItemInfo; //���ɵĵ�����Ϣ
	UINT8            byCropSeedNum; //���Ӹ���
	DT_CROP_SEED_INFO_DATA astCropSeedInfoList[MAX_CROP_SEED_NUM]; //������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_SEED_COMPOSE_ACK;

typedef struct tagCHAT_DATA{
	UINT32           dwSerialNumber; //������ˮ��
	UINT32           dwPlayerID; //��������ID
	TCHAR            aszUserName[USERNAME_LEN]; //������������
	UINT8            byChatType; //��������
	UINT64           qwChatTime; //����ʱ��
	UINT32           dwChatLen; //���쳤��
	UINT8            abyChatContent[MAX_CHAT_CONTENT_NUM]; //��������
}CHAT_DATA;

typedef struct tagPKT_CLIGS_OPEN_CHAT_REQ{
	tagPKT_CLIGS_OPEN_CHAT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CHAT_REQ)); }
	UINT32           dwSerialNumber; //������ˮ��
}PKT_CLIGS_OPEN_CHAT_REQ;

typedef struct tagPKT_CLIGS_OPEN_CHAT_ACK{
	tagPKT_CLIGS_OPEN_CHAT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CHAT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byChatNum; //�����¼����
	CHAT_DATA        astChatData[MAX_CHAT_NUM]; //��������
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ(��ֵ����������ڴ�����)
	UINT8            abyVipLevel[MAX_CHAT_NUM]; //�������vip�ȼ�����������ҪΪ���Э����ݣ�
	UINT8            abyFactionIconIDList[MAX_CHAT_NUM]; //����������ɵ�����ͼ��ID��ֵΪNULL_FACTION_ICON_IDʱ���������ɣ��汾��<303�Ŀͻ��˽����Ӵ��ֶΣ�
}PKT_CLIGS_OPEN_CHAT_ACK;

typedef struct tagPKT_CLIGS_CHAT_REQ{
	tagPKT_CLIGS_CHAT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHAT_REQ)); }
	UINT32           dwPlayerID; //��������ID
	UINT8            byChatType; //��������
	UINT32           dwChatLen; //��������
	UINT8            abyChatContent[MAX_CHAT_CONTENT_NUM]; //��������
}PKT_CLIGS_CHAT_REQ;

typedef struct tagPKT_CLIGS_CHAT_ACK{
	tagPKT_CLIGS_CHAT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHAT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	CHAT_DATA        stChatData; //��������
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ(��ֵ����������ڴ�����)
	UINT8            byVipLevel; //�������vip�ȼ�����������ҪΪ���Э����ݣ�
	UINT8            byFactionIconID; //����������ɵ�����ͼ��ID��ֵΪNULL_FACTION_ICON_IDʱ���������ɣ��汾��<303�Ŀͻ��˽����Ӵ��ֶΣ�
}PKT_CLIGS_CHAT_ACK;

typedef struct tagPKT_CLIGS_CHAT_NTF{
	tagPKT_CLIGS_CHAT_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_CHAT_NTF)); }
	UINT8            byChatNum; //�����¼����
	CHAT_DATA        astChatData[MAX_CHAT_NUM]; //��������
	UINT8            abyVipLevel[MAX_CHAT_NUM]; //�������vip�ȼ�����������ҪΪ���Э����ݣ�
	UINT8            abyFactionIconIDList[MAX_CHAT_NUM]; //����������ɵ�����ͼ��ID��ֵΪNULL_FACTION_ICON_IDʱ���������ɣ��汾��<303�Ŀͻ��˽����Ӵ��ֶΣ�
}PKT_CLIGS_CHAT_NTF;

typedef struct tagPKT_CLIGS_CROSS_DAY_NTF{
	tagPKT_CLIGS_CROSS_DAY_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_CROSS_DAY_NTF)); }
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT8            byOnlineEncourageFlag; //�Ƿ�������߽�����Ϣ
	DT_ONLINE_ENCOURAGE_DATA astOnlineEncourage[1]; //��ǰ���߽�����Ϣ
	UINT16           awRecvCountDown[1]; //��ȡ���߽�������ʱ����λ��
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
}PKT_CLIGS_CROSS_DAY_NTF;

typedef struct tagPKT_CLIGS_OPNE_ACTIVITY_CENTER_REQ{
	tagPKT_CLIGS_OPNE_ACTIVITY_CENTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPNE_ACTIVITY_CENTER_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPNE_ACTIVITY_CENTER_REQ;

typedef struct tagPKT_CLIGS_OPNE_ACTIVITY_CENTER_ACK{
	tagPKT_CLIGS_OPNE_ACTIVITY_CENTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPNE_ACTIVITY_CENTER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byActivityNum; //���
	DT_ACTIVITY_BASE_DATA astActivityInfo[MAX_ACTIVITY_NUM]; //�
	UINT8            abyActivityStartCountDown[MAX_ACTIVITY_NUM]; //�������������ʱ
}PKT_CLIGS_OPNE_ACTIVITY_CENTER_ACK;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_PROMPT_REQ{
	tagPKT_CLIGS_GET_ACTIVITY_PROMPT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_PROMPT_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_ACTIVITY_PROMPT_REQ;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_PROMPT_ACK{
	tagPKT_CLIGS_GET_ACTIVITY_PROMPT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_PROMPT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FUNC_COMMON_PROMPT stPromptInfo; //��ʾ��Ϣ
}PKT_CLIGS_GET_ACTIVITY_PROMPT_ACK;

typedef struct tagPKT_CLIGS_OPNE_EAT_BREAD_REQ{
	tagPKT_CLIGS_OPNE_EAT_BREAD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPNE_EAT_BREAD_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPNE_EAT_BREAD_REQ;

typedef struct tagPKT_CLIGS_OPNE_EAT_BREAD_ACK{
	tagPKT_CLIGS_OPNE_EAT_BREAD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPNE_EAT_BREAD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wEndCountDown; //���������ʱ
	UINT8            byMaxObtainPhyStrengthen; //�ɵõ���������
	UINT16           wTimePerPhyStrengthen; //��ÿɻ��1������
	UINT16           wOarNumPerPhyStrengthen; //�����οɻ��1������
	UINT32           dwOnceSpeedCoin; //1�����ɻ��ͭǮ
	UINT8            byHaveObtainPhyStrengthen; //�ѻ������
	UINT32           dwHaveObtainCoin; //�ѻ��ͭǮ
	UINT16           wHaveUseTime; //����ʱ��
	UINT16           wCurPhyStrength; //��ǰ����
	UINT64           qwCurCoin; //��ǰͭǮ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
}PKT_CLIGS_OPNE_EAT_BREAD_ACK;

typedef struct tagPKT_CLIGS_OBTAIN_PHYSTRENGTHEN_REQ{
	tagPKT_CLIGS_OBTAIN_PHYSTRENGTHEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OBTAIN_PHYSTRENGTHEN_REQ)); }
	UINT8            byHaveObtainPhyStrengthenCli; //����õ�������(�ӻ��ʼ����ǰ)
	UINT32           dwHaveObtainCoinCli; //����õ���ͭǮ(�ӻ��ʼ����ǰ)
}PKT_CLIGS_OBTAIN_PHYSTRENGTHEN_REQ;

typedef struct tagPKT_CLIGS_OBTAIN_PHYSTRENGTHEN_ACK{
	tagPKT_CLIGS_OBTAIN_PHYSTRENGTHEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OBTAIN_PHYSTRENGTHEN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byHaveObtainPhyStrengthenCli; //����õ�������(�ӻ��ʼ����ǰ)
	UINT32           dwHaveObtainCoinCli; //����õ���ͭǮ(�ӻ��ʼ����ǰ)
	UINT8            byHaveObtainPhyStrengthen; //�õ�������(�ӻ��ʼ����ǰ)
	UINT32           dwHaveObtainCoin; //�õ���ͭǮ(�ӻ��ʼ����ǰ)
	UINT16           wHaveUseTime; //����ʱ��
}PKT_CLIGS_OBTAIN_PHYSTRENGTHEN_ACK;

typedef struct tagPKT_CLIGS_LEAVE_EAT_BREAD_REQ{
	tagPKT_CLIGS_LEAVE_EAT_BREAD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_EAT_BREAD_REQ)); }
	UINT8            byHaveObtainPhyStrengthenCli; //����õ�������(�ӻ��ʼ����ǰ)
	UINT32           dwHaveObtainCoinCli; //����õ���ͭǮ(�ӻ��ʼ����ǰ)
}PKT_CLIGS_LEAVE_EAT_BREAD_REQ;

typedef struct tagPKT_CLIGS_LEAVE_EAT_BREAD_ACK{
	tagPKT_CLIGS_LEAVE_EAT_BREAD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_EAT_BREAD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byHaveObtainPhyStrengthen; //�õ�������(�ӻ��ʼ����ǰ)
	UINT32           dwHaveObtainCoin; //�õ���ͭǮ(�ӻ��ʼ����ǰ)
	UINT16           wCurPhyStrength; //��ǰ����
	UINT64           qwCurCoin; //��ǰͭǮ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //������Ϣ
}PKT_CLIGS_LEAVE_EAT_BREAD_ACK;

typedef struct tagPKT_CLIGS_OPEN_PAOSHANG_BUILD_REQ{
	tagPKT_CLIGS_OPEN_PAOSHANG_BUILD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PAOSHANG_BUILD_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_PAOSHANG_BUILD_REQ;

typedef struct tagDT_BIAO_INFO{
	UINT8            byQualityLevel; //����
	UINT32           dwCoin; //���ͭǮ
	UINT32           dwScience; //�������
	UINT32           dwJingjie; //��þ����
	UINT16           wCostTime; //����ʱ�䣨��λ�룩
}DT_BIAO_INFO;

typedef struct tagBIAO_OPERATE_INFO{
	UINT8            byRemianOperateCnt; //�ɲ�������
	UINT8            byTotalOperateCnt; //�ܲ�������
}BIAO_OPERATE_INFO;

typedef struct tagPKT_CLIGS_OPEN_PAOSHANG_BUILD_ACK{
	tagPKT_CLIGS_OPEN_PAOSHANG_BUILD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PAOSHANG_BUILD_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byYabiaoFlag; //Ѻ�ڱ�ʶ(0Ϊ����Ѻ�ڣ�1Ϊ����Ѻ���У�2ΪѺ����ϣ�������ȡ����)
	UINT16           wAlreadyYabiaoTime; //�Ѿ�Ѻ��ʱ�䣨��λ�룩
	DT_BIAO_INFO     stBiaoInfo; //����Ϣ
	UINT8            byRemainYabiaoCnt; //ʣ��Ѻ�ڴ���
	UINT8            byRemainJiebiaoCnt; //ʣ�����ش���
	UINT16           wAllPlayerYabiaoCnt; //������Ѻ�ڵ�����
	UINT8            byEnemyYabiaoCnt; //������Ѻ�ڵĳ�������
	UINT64           qwCoinEncourage; //ͭǮ
	UINT32           dwScienceEncourage; //����
	UINT16           wJiebiaoCD; //��ȴʱ��
	UINT16           wClearCDCostGoldPerMin; //���CDÿ��������Ԫ��
}PKT_CLIGS_OPEN_PAOSHANG_BUILD_ACK;

typedef struct tagPKT_CLIGS_OPEN_YABIAO_REQ{
	tagPKT_CLIGS_OPEN_YABIAO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_YABIAO_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_YABIAO_REQ;

typedef struct tagPKT_CLIGS_OPEN_YABIAO_ACK{
	tagPKT_CLIGS_OPEN_YABIAO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_YABIAO_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byYabiaoing; //�Ƿ��Ѿ���Ѻ��
	UINT16           wCurBiaoIndex; //��ǰ�ڵ����
	UINT16           wFlushCount; //ˢ�´���
	UINT16           wFlushCostGold; //ˢ������Ԫ��
	UINT16           wDirectMaxLevelCostGold; //�ﵽ��߼����ĵ�Ԫ��
	UINT16           wBiaoQualityNum; //�ڵ�Ʒ������
	DT_BIAO_INFO     astBiaoInfo[MAX_BIAO_QUALITY]; //��Ʒ�ʵ���Ϣ
	UINT8            byFreeFlushCnt; //�ڵ���Ѵ���
	UINT8            byFreeFlushRemainCnt; //�ڵ������ʹ�ô���
}PKT_CLIGS_OPEN_YABIAO_ACK;

typedef struct tagPKT_CLIGS_FLUSH_BIAO_QUALITY_REQ{
	tagPKT_CLIGS_FLUSH_BIAO_QUALITY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FLUSH_BIAO_QUALITY_REQ)); }
	UINT16           wQuality; //��ǰƷ��
	UINT8            byDirectMaxLevel; //�Ƿ�ֱ�Ӵ����Ʒ��
}PKT_CLIGS_FLUSH_BIAO_QUALITY_REQ;

typedef struct tagPKT_CLIGS_FLUSH_BIAO_QUALITY_ACK{
	tagPKT_CLIGS_FLUSH_BIAO_QUALITY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FLUSH_BIAO_QUALITY_ACK)); }
	UINT16           wErrCode; //������
	DT_BIAO_INFO     stBiaoInfo; //����Ϣ
	UINT16           wFlushCount; //ˢ�´���
	UINT16           wFlushCostGold; //ˢ������Ԫ��
	UINT64           qwCurGold; //��ǰԪ��
	UINT8            byDirectMaxLevel; //�Ƿ�ֱ�Ӵ����Ʒ�ʣ��ͻ��˴�ֱֵ�ӷ��أ�
	UINT8            byFreeFlushCnt; //�ڵ���Ѵ���
	UINT8            byFreeFlushRemainCnt; //�ڵ������ʹ�ô���
}PKT_CLIGS_FLUSH_BIAO_QUALITY_ACK;

typedef struct tagPKT_CLIGS_BEGIN_YABIAO_REQ{
	tagPKT_CLIGS_BEGIN_YABIAO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGIN_YABIAO_REQ)); }
	UINT16           wQuality; //Ʒ��
}PKT_CLIGS_BEGIN_YABIAO_REQ;

typedef struct tagPKT_CLIGS_BEGIN_YABIAO_ACK{
	tagPKT_CLIGS_BEGIN_YABIAO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGIN_YABIAO_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wAlreadyYabiaoTime; //�Ѿ�Ѻ��ʱ�䣨��λ�룩
	UINT16           wTotalYabiaoTime; //Ѻ����ʱ�䣨��λ�룩
	BIAO_OPERATE_INFO stBeJiebiaoInfo; //�ɱ����ش���
	UINT64           qwBeJiebiaoCoinEncourage; //������ͭǮ����
	UINT32           dwBeJiebiaoScienceEncourage; //�������꽱��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ��1��Ѻ�ڣ�2��ʾѺ���У�0��ʾ����ʾ��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT8            byFactionIconID; //����ͷ��ID
}PKT_CLIGS_BEGIN_YABIAO_ACK;

typedef struct tagPKT_CLIGS_OPEN_JIEBIAO_REQ{
	tagPKT_CLIGS_OPEN_JIEBIAO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JIEBIAO_REQ)); }
	UINT8            byViewYabiaoType; //��������(0ȫ����1����)
	UINT16           wLongestYabiaoEndTime; //����Ѻ����ҵ�ʣ���Ѻ��ʱ��
	UINT8            byNeedPlayerNum; //�����ɫ��
}PKT_CLIGS_OPEN_JIEBIAO_REQ;

typedef struct tagDT_YABIAO_PLAYER_INFO{
	UINT32           dwID; //���ΨһID
	UINT16           wKindID; //���ְҵID
	UINT16           wLevel; //��ҵȼ�
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT32           dwPower; //ս��
	UINT8            byQuality; //Ʒ��
	BIAO_OPERATE_INFO stBeJiebiaoInfo; //�ɱ��ٴ���
	UINT16           wAlreadyYabiaoTime; //�Ѿ�Ѻ��ʱ�䣨��λ�룩
	UINT16           wTotalYabiaoTime; //Ѻ����ʱ�䣨��λ�룩
	UINT64           qwCoinEncourage; //���ؽ���
	UINT32           dwScienceEncourage; //�������꽱��
	UINT8            byCanJiebiao; //�Ƿ�ɽ���
}DT_YABIAO_PLAYER_INFO;

typedef struct tagDT_YABIAO_PLAYER_INFO_FACTION_NAME{
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��ǰ��������
	UINT8            bySameFaction; //�Ƿ���ͬһ��������
}DT_YABIAO_PLAYER_INFO_FACTION_NAME;

typedef struct tagPKT_CLIGS_OPEN_JIEBIAO_ACK{
	tagPKT_CLIGS_OPEN_JIEBIAO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JIEBIAO_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byYabiaoPlayerNum; //�����
	DT_YABIAO_PLAYER_INFO astYabiaoPlayerInfo[MAX_YABIAO_PLAYER_NUM]; //�������
	UINT16           wLongestYabiaoEndTime; //����Ѻ����ҵ�ʣ���Ѻ��ʱ��
	UINT16           wJiebiaoCD; //��ȴʱ��
	UINT8            byRemainJiebiaoCnt; //ʣ�����ش���
	UINT16           wClearCDCostGoldPerMin; //���CDÿ��������Ԫ��
	UINT8            byYabiaoFlag; //Ѻ�ڱ�ʶ(0Ϊ����Ѻ�ڣ�1Ϊ����Ѻ���У�2ΪѺ����ϣ�������ȡ����)
	UINT16           wAlreadyYabiaoTime; //�Ѿ�Ѻ��ʱ�䣨��λ�룩
	DT_BIAO_INFO     stBiaoInfo; //�Լ���ǰ������Ϣ
	UINT64           qwCurJingjie; //��ǰ����
	UINT8            byRemainYabiaoCnt; //ʣ��Ѻ�ڴ���
	UINT64           qwCoinEncourage; //ͭǮ
	UINT64           qwScienceEncourage; //����
	UINT64           qwJingjieEncourage; //����
	UINT32           dwJiebiaoReduceCoin; //�����ص��˵Ľ�Ǯ��
	UINT32           dwJiebiaoReduceScience; //�����ص��˵�������
	DT_YABIAO_PLAYER_INFO_FACTION_NAME astYaBiaoFactionName[MAX_YABIAO_PLAYER_NUM]; //Ѻ����Ұ�������
	UINT8            abyFactionIconID[MAX_YABIAO_PLAYER_NUM]; //����ͷ��ID
	UINT8            byDisPlayJieBiao; //�Ƿ�ɽ���0���ɽ��ڣ�1�ɽ���
}PKT_CLIGS_OPEN_JIEBIAO_ACK;

typedef struct tagPKT_CLIGS_BEGIN_JIEBIAO_REQ{
	tagPKT_CLIGS_BEGIN_JIEBIAO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGIN_JIEBIAO_REQ)); }
	UINT32           dwPlayerID; //����ID
	UINT8            byCurCount; //��ǰ����
}PKT_CLIGS_BEGIN_JIEBIAO_REQ;

typedef struct tagPKT_CLIGS_BEGIN_JIEBIAO_ACK3{
	tagPKT_CLIGS_BEGIN_JIEBIAO_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGIN_JIEBIAO_ACK3)); }
	UINT16           wErrCode; //������
	UINT8            byYabiaoFlag; //Ѻ�ڱ�ʶ(0Ϊ����Ѻ�ڣ�1Ϊ����Ѻ���У�2ΪѺ����ϣ�������ȡ����)
	DT_BATTLE_DATA3  stBattleData; //ս����Ϣ
	UINT64           qwCoinEncourage; //����
	UINT32           dwScienceEncourage; //�������꽱��
	UINT64           qwCurCoin; //��ǰͭǮ��
	UINT64           qwCurScience; //��ǰ����
	UINT32           dwBeJiebiaoPlayerID; //�����ض���
	BIAO_OPERATE_INFO stBeJiebiaoInfo; //������Ϣ
	UINT32           dwJiebiaoPlayerID; //���ض���
	BIAO_OPERATE_INFO stJiebiaoInfo; //������Ϣ
	UINT16           wJiebiaoCD; //��ȴʱ��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_BEGIN_JIEBIAO_ACK3;

typedef struct tagPKT_CLIGS_CLEAR_JIEBIAO_CD_REQ{
	tagPKT_CLIGS_CLEAR_JIEBIAO_CD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLEAR_JIEBIAO_CD_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_CLEAR_JIEBIAO_CD_REQ;

typedef struct tagPKT_CLIGS_CLEAR_JIEBIAO_CD_ACK{
	tagPKT_CLIGS_CLEAR_JIEBIAO_CD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLEAR_JIEBIAO_CD_ACK)); }
	UINT16           wErrCode; //������
	UINT64           qwCurGold; //Ԫ��
	UINT16           wJiebiaoCD; //CD
}PKT_CLIGS_CLEAR_JIEBIAO_CD_ACK;

typedef struct tagPKT_CLIGS_BE_JIEBIAO_NTF{
	tagPKT_CLIGS_BE_JIEBIAO_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_BE_JIEBIAO_NTF)); }
	UINT8            byResult; //ս��ʤ����־(0ʤ��,1ʧ��)
	UINT64           qwIndex; //ս����Ϣ����
	UINT64           qwCoinDec; //��ʧͭǮ
	UINT32           dwScienceDec; //��ʧ����
	TCHAR            aszEnemyDispName[USERNAME_LEN]; //�Է�����
	UINT16           wEnemyLevel; //�Է��ȼ�
	UINT32           dwEnemyPower; //�Է�ս��
	UINT8            byUnreadBattleLogNum; //δ�ۿ�ս������
}PKT_CLIGS_BE_JIEBIAO_NTF;

typedef struct tagPKT_CLIGS_QUERY_YABIAO_BATTLELOG_REQ{
	tagPKT_CLIGS_QUERY_YABIAO_BATTLELOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_YABIAO_BATTLELOG_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_QUERY_YABIAO_BATTLELOG_REQ;

typedef struct tagDT_YABIAO_BATTLELOG_DATA_CLI{
	DT_YABIAO_BATTLELOG_DATA stBattleLogData; //ս��������Ϣ
	TCHAR            aszEnemyDispName[USERNAME_LEN]; //�ǳ�
}DT_YABIAO_BATTLELOG_DATA_CLI;

typedef struct tagPKT_CLIGS_QUERY_YABIAO_BATTLELOG_ACK{
	tagPKT_CLIGS_QUERY_YABIAO_BATTLELOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_YABIAO_BATTLELOG_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byLogNum; //ս������
	DT_YABIAO_BATTLELOG_DATA_CLI astYabiaoBattleLog[MAX_YABIAO_BATTLELOG_NUM]; //ս����Ϣ
}PKT_CLIGS_QUERY_YABIAO_BATTLELOG_ACK;

typedef struct tagPKT_CLIGS_QUERY_YABIAO_ENCOURAGE_REQ{
	tagPKT_CLIGS_QUERY_YABIAO_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_YABIAO_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_QUERY_YABIAO_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_QUERY_YABIAO_ENCOURAGE_ACK{
	tagPKT_CLIGS_QUERY_YABIAO_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_YABIAO_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //������
	UINT64           qwCoinEncourage; //ͭǮ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwScienceEncourage; //����
	UINT64           qwCurScience; //��ǰ����
	UINT64           qwJingjieEncourage; //����
	UINT64           qwCurJingjie; //��ǰ����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_QUERY_YABIAO_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_QUERY_BATTLE_RECORD_REQ{
	tagPKT_CLIGS_QUERY_BATTLE_RECORD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_BATTLE_RECORD_REQ)); }
	UINT32           dwIndex; //����
}PKT_CLIGS_QUERY_BATTLE_RECORD_REQ;

typedef struct tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK3{
	tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK3)); }
	UINT16           wErrCode; //������
	DT_BATTLE_DATA3  stBattleData; //ս����Ϣ
}PKT_CLIGS_QUERY_BATTLE_RECORD_ACK3;

typedef struct tagDT_CLIMB_TOWER_INFO{
	UINT16           wIndex; //�������
	UINT8            byEnterPhyStrength; //��������Ҫ��
	UINT8            byMaxInstanceNum; //��󸱱���Ϣ
	UINT8            byMaxUnlockInstanceNum; //����������Ϣ
	DT_INSTANCE_RECORD_DATA_CLI stCurInstanceInfo; //��ǰ������¼��Ϣ
	UINT16           wCanResetClimbTownNum; //��ǰ�����ô���
	UINT16           wResetClimbTownNumPerDay; //ÿ������ô���
	UINT16           wBuyResetClimbTownGold; //����Ԫ��
}DT_CLIMB_TOWER_INFO;

typedef struct tagPKT_CLIGS_OPEN_CLIMB_TOWER_REQ{
	tagPKT_CLIGS_OPEN_CLIMB_TOWER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CLIMB_TOWER_REQ)); }
	UINT16           wIndex; //�������
}PKT_CLIGS_OPEN_CLIMB_TOWER_REQ;

typedef struct tagPKT_CLIGS_OPEN_CLIMB_TOWER_ACK{
	tagPKT_CLIGS_OPEN_CLIMB_TOWER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CLIMB_TOWER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_CLIMB_TOWER_INFO stClimbTowerInfo; //������Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT64           qwBlueGas; //��ǰ����
}PKT_CLIGS_OPEN_CLIMB_TOWER_ACK;

typedef struct tagPKT_CLIGS_CLIMB_TOWER_RESET_REQ{
	tagPKT_CLIGS_CLIMB_TOWER_RESET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLIMB_TOWER_RESET_REQ)); }
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
}PKT_CLIGS_CLIMB_TOWER_RESET_REQ;

typedef struct tagPKT_CLIGS_CLIMB_TOWER_RESET_ACK{
	tagPKT_CLIGS_CLIMB_TOWER_RESET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLIMB_TOWER_RESET_ACK)); }
	UINT16           wErrCode; //������
	UINT64           qwGold; //��ǰ���Ԫ����
	DT_CLIMB_TOWER_INFO stClimbTowerInfo; //������Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_CLIMB_TOWER_RESET_ACK;

typedef struct tagPKT_CLIGS_CLIMB_TOWER_ONHOOK_REQ{
	tagPKT_CLIGS_CLIMB_TOWER_ONHOOK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLIMB_TOWER_ONHOOK_REQ)); }
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
}PKT_CLIGS_CLIMB_TOWER_ONHOOK_REQ;

typedef struct tagPKT_CLIGS_CLIMB_TOWER_ONHOOK_ACK{
	tagPKT_CLIGS_CLIMB_TOWER_ONHOOK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLIMB_TOWER_ONHOOK_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byOnhookResultNum; //ɨ����������
	DT_ONHOOK_RESULT astOnhookResult[MAX_INSTANCE_CLIMB_TOWER_NUM]; //ɨ�������
	DT_DATA_AFTER_ONHOOK stAfterOnhookData; //ɨ����Һ���Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	UINT8            byUnlockNewInstanceFlag; //�Ƿ�����¸���
	DT_INSTANCE_ID   astUnlockCommonInstanceID[1]; //��������ͨ����ID
	UINT8            byHaveNewInstanceFlag; //�Ƿ����¿ɴ���ͨ����,1��Ч
	DT_INSTANCE_DATA_CLI astNewCommonInstanceID[1]; //�¿ɴ���ͨ����ID
	DT_CLIMB_TOWER_INFO stClimbTowerInfo; //������Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_CLIMB_TOWER_ONHOOK_ACK;

typedef struct tagPKT_CLIGS_BUY_CLIMB_TOWER_RESET_REQ{
	tagPKT_CLIGS_BUY_CLIMB_TOWER_RESET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_CLIMB_TOWER_RESET_REQ)); }
	UINT8            byBuyNum; //�������
}PKT_CLIGS_BUY_CLIMB_TOWER_RESET_REQ;

typedef struct tagPKT_CLIGS_BUY_CLIMB_TOWER_RESET_ACK{
	tagPKT_CLIGS_BUY_CLIMB_TOWER_RESET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_CLIMB_TOWER_RESET_ACK)); }
	UINT16           wErrCode; //������
	UINT64           qwGold; //��ҵ�ǰԪ����
	UINT16           wCanResetClimbTownNum; //ÿ������ô���
	UINT16           wCanBuyResetClimbTownNum; //ÿ��ɹ������
	UINT16           wBuyResetClimbTownGold; //����Ԫ��
}PKT_CLIGS_BUY_CLIMB_TOWER_RESET_ACK;

typedef struct tagDT_JINGJIE_PER_LEVEL_DATA{
	DT_ATTR_INC_DATA astSubLevelIncAttrInfo[MAX_JINGJIE_SUBLEVEL_NUM]; //�������Ӽ�����������
	UINT32           adwSubLevelCostJingJieInfo[MAX_JINGJIE_SUBLEVEL_NUM]; //�������Ӽ����������ĵľ����
}DT_JINGJIE_PER_LEVEL_DATA;

typedef struct tagDT_JINGJIE_DATA_CLI{
	DT_JINGJIE_BASE_DATA stBaseData; //���������Ϣ
	DT_JINGJIE_PER_LEVEL_DATA stJingJiePerLevelData; //���籾����Ϣ
	UINT8            byIncAttrNum; //�����������Ը���
	DT_ATTR_INC_DATA astIncAttrInfo[MAX_JINGJIE_ATTR_INC_NUM]; //��������������Ϣ
	UINT16           wCurCoachTalent; //��ǰ��������
}DT_JINGJIE_DATA_CLI;

typedef struct tagPKT_CLIGS_UPGRADE_JINGJIE_REQ{
	tagPKT_CLIGS_UPGRADE_JINGJIE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_JINGJIE_REQ)); }
	UINT16           wLevel; //�ȼ�
}PKT_CLIGS_UPGRADE_JINGJIE_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_JINGJIE_ACK{
	tagPKT_CLIGS_UPGRADE_JINGJIE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_JINGJIE_ACK)); }
	UINT16           wErrCode; //������
	DT_JINGJIE_DATA_CLI stJingJieInfo; //������Ϣ
	UINT64           qwCurJingJie; //��ǰ�����
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT8            byColor; //������ɫ
}PKT_CLIGS_UPGRADE_JINGJIE_ACK;

typedef struct tagDT_GEN_GAS_DATA_CLI{
	UINT8            byCollectState; //�ռ�״̬,0���ɣ�1��ȡ
	DT_GAS_BALL_DATA astGasBollInfo[MAX_GAS_BALL_NUM]; //��������Ϣ
	UINT32           dwGenGasCoin; //��������ͭ��
	UINT32           dwGenGasGold; //��������Ԫ��
	UINT32           dwCommonUpGasGold; //��ͨ��������������Ԫ��
	UINT32           dwFullLevelUpGasGold; //������������������Ԫ��
	UINT16           wTotalGenNum; //�������ܴ���
	UINT16           wCanGenNum; //����������
	UINT16           wTotalFreeCommonUpGasNum; //�����ͨ�����������ܴ���
	UINT16           wCanFreeCommonUpGasNum; //�������ͨ�������������
}DT_GEN_GAS_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_GEN_GAS_TAB_REQ{
	tagPKT_CLIGS_OPEN_GEN_GAS_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GEN_GAS_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_GEN_GAS_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_GEN_GAS_TAB_ACK{
	tagPKT_CLIGS_OPEN_GEN_GAS_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GEN_GAS_TAB_ACK)); }
	UINT16           wErrCode; //������
	DT_GEN_GAS_DATA_CLI stGenGasInfo; //���������Ϣ
	TCHAR            aszTipsInfo[MAX_GEN_GAS_INFO_LEN]; //������Ϣ
}PKT_CLIGS_OPEN_GEN_GAS_TAB_ACK;

typedef struct tagPKT_CLIGS_GEN_GAS_BALL_REQ{
	tagPKT_CLIGS_GEN_GAS_BALL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GEN_GAS_BALL_REQ)); }
	UINT8            byFlag; //������־
}PKT_CLIGS_GEN_GAS_BALL_REQ;

typedef struct tagPKT_CLIGS_GEN_GAS_BALL_ACK{
	tagPKT_CLIGS_GEN_GAS_BALL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GEN_GAS_BALL_ACK)); }
	UINT16           wErrCode; //������
	DT_GEN_GAS_DATA_CLI stGenGasInfo; //���������Ϣ
	UINT64           qwCurCoin; //��ǰ���ͭǮ
	UINT64           qwCurGold; //��ǰ���Ԫ��
}PKT_CLIGS_GEN_GAS_BALL_ACK;

typedef struct tagPKT_CLIGS_UP_GAS_BALL_LEVEL_REQ{
	tagPKT_CLIGS_UP_GAS_BALL_LEVEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UP_GAS_BALL_LEVEL_REQ)); }
	UINT8            byFullLevelFlag; //������������־
}PKT_CLIGS_UP_GAS_BALL_LEVEL_REQ;

typedef struct tagPKT_CLIGS_UP_GAS_BALL_LEVEL_ACK{
	tagPKT_CLIGS_UP_GAS_BALL_LEVEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UP_GAS_BALL_LEVEL_ACK)); }
	UINT16           wErrCode; //������
	DT_GEN_GAS_DATA_CLI stGenGasInfo; //���������Ϣ
	UINT64           qwCurCoin; //��ǰ���ͭǮ
	UINT64           qwCurGold; //��ǰ���Ԫ��
}PKT_CLIGS_UP_GAS_BALL_LEVEL_ACK;

typedef struct tagPKT_CLIGS_COLLECT_GAS_REQ{
	tagPKT_CLIGS_COLLECT_GAS_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COLLECT_GAS_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_COLLECT_GAS_REQ;

typedef struct tagPKT_CLIGS_COLLECT_GAS_ACK{
	tagPKT_CLIGS_COLLECT_GAS_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COLLECT_GAS_ACK)); }
	UINT16           wErrCode; //������
	DT_GEN_GAS_DATA_CLI stGenGasInfo; //���������Ϣ
	UINT64           qwScience; //�ռ����ľ���
}PKT_CLIGS_COLLECT_GAS_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ{
	tagPKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ)); }
	UINT16           wActionID; //��ʽID
	UINT16           wActionLevelCli; //�ȼ�
}PKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ;

typedef struct tagDT_ATTACK_RANG_DATA_LST{
	UINT8            byNum; //�ܸ���
	DT_ATTACK_RANG_DATA_CLI astInfo[MAX_SKILL_ACTION_LEVEL_NUM]; //��Ϣ
}DT_ATTACK_RANG_DATA_LST;

typedef struct tagDT_EFFECT_DATA_LST2{
	UINT8            byNum; //�ܸ���
	DT_SKILL_EFFECT_DATA_CLI2 astInfo[MAX_SKILL_ACTION_LEVEL_NUM]; //��Ϣ
}DT_EFFECT_DATA_LST2;

typedef struct tagDT_SKILL_TAB_DATA_CLI{
	DT_SKILL_DATA_CLI stSkillInfo; //��ǰ������Ϣ
	DT_ATTACK_RANG_DATA_LST stAttackRangInfo; //���ܷ�Χ��Ϣ�б�
	DT_EFFECT_DATA_LST2 stEffectInfo; //����Ч����Ϣ�б�
	UINT16           wAddExpPerUpgrade; //ÿ���������ӵľ���ֵ
	UINT16           wCostGasPerUpgrade; //ÿ���������ĵ�����
	UINT16           wCurPlayerLevel; //��ǰ��ҵȼ�
	UINT64           qwCurCoin; //��ǰ���ͭǮ
	UINT64           qwCurGold; //��ǰ���Ԫ��
	UINT64           qwCurPurpleGas; //��ǰ����
}DT_SKILL_TAB_DATA_CLI;

typedef struct tagPKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK{
	tagPKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK)); }
	UINT16           wErrCode; //������
	DT_SKILL_TAB_DATA_CLI stSkillTabInfo; //���������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
}PKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK;

typedef struct tagPKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ{
	tagPKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ)); }
	UINT16           wActionID; //��ʽID
	UINT16           wEffectID; //Ч��ID
	UINT8            byAttackRangKind; //������Χ����
	UINT8            byTraceBuffKind; //׷�ٵ�buff����(ֻ��AttackRangKindΪEARK_BUFF��Ч)
}PKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ;

typedef struct tagPKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK{
	tagPKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK)); }
	UINT16           wErrCode; //������
	DT_SKILL_TAB_DATA_CLI stSkillTabInfo; //���������Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
}PKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK;

typedef struct tagPKT_CLIGS_OPEN_JINGJIE_TAB_REQ{
	tagPKT_CLIGS_OPEN_JINGJIE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JINGJIE_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_JINGJIE_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_JINGJIE_TAB_ACK{
	tagPKT_CLIGS_OPEN_JINGJIE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JINGJIE_TAB_ACK)); }
	UINT16           wErrCode; //������
	DT_JINGJIE_DATA_CLI stJingJieInfo; //������Ϣ
	UINT16           wMaxQualityLevel; //��߾���׵ȼ�
	UINT64           qwCurJingJie; //��ǰ����
}PKT_CLIGS_OPEN_JINGJIE_TAB_ACK;

typedef struct tagPKT_CLIGS_OPEN_SKILL_TAB_REQ{
	tagPKT_CLIGS_OPEN_SKILL_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SKILL_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_SKILL_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_SKILL_TAB_ACK{
	tagPKT_CLIGS_OPEN_SKILL_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SKILL_TAB_ACK)); }
	UINT16           wErrCode; //������
	DT_SKILL_TAB_DATA_CLI stSkillTabInfo; //���������Ϣ
}PKT_CLIGS_OPEN_SKILL_TAB_ACK;

typedef struct tagPKT_CLIGS_BLUE_TO_PURPLE_REQ{
	tagPKT_CLIGS_BLUE_TO_PURPLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BLUE_TO_PURPLE_REQ)); }
	UINT32           dwBlueGas; //Ҫת��������
}PKT_CLIGS_BLUE_TO_PURPLE_REQ;

typedef struct tagPKT_CLIGS_BLUE_TO_PURPLE_ACK{
	tagPKT_CLIGS_BLUE_TO_PURPLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BLUE_TO_PURPLE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurBlueGas; //��ǰ����
	UINT64           qwCurPurpleGas; //��ǰ����
}PKT_CLIGS_BLUE_TO_PURPLE_ACK;

typedef struct tagPKT_CLIGS_OPEN_VIP_TAB_REQ{
	tagPKT_CLIGS_OPEN_VIP_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_VIP_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_VIP_TAB_REQ;

typedef struct tagDT_BUY_GOLD_INFO{
	UINT32           dwGoldNum; //Ԫ��
	UINT32           dwRMB; //�����
	UINT32           dwProductID; //��ƷID
}DT_BUY_GOLD_INFO;

typedef struct tagDT_BUY_GOLD_INFO_EX{
	UINT32           dwGoldNum; //Ԫ��
	UINT32           dwRMB; //�����
	TCHAR            aszProductID[MAX_PRODUCTID_LEN]; //��ƷID
}DT_BUY_GOLD_INFO_EX;

typedef struct tagDT_BUY_GOLD_TXT{
	TCHAR            aszBuyGoldInfo[MAX_COMMON_TXT_NUM]; //VIP������Ϣtxt
}DT_BUY_GOLD_TXT;

typedef struct tagPKT_CLIGS_OPEN_VIP_TAB_ACK{
	tagPKT_CLIGS_OPEN_VIP_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_VIP_TAB_ACK)); }
	UINT16           wErrCode; //������
	DT_VIP_TAB_DATA_CLI stVipTabInfo; //VIP�����Ϣ
	UINT8            byBuyGoldInfoNum; //�б���
	DT_BUY_GOLD_INFO astBuyGoldLst[MAX_BUY_GOLD_NUM]; //����Ԫ���б�
	DT_BUY_GOLD_TXT  astBuyGoldTxtLst[MAX_BUY_GOLD_NUM]; //VIP������Ϣtxt�б�
	TCHAR            aszProContextHead[MAX_COMMON_TXT_NUM]; //VIP��ʾ��Ϣ����
	TCHAR            aszVipProContext[MAX_VIP_PRO_CONTEXT_LEN]; //VIP��ʾ��Ϣ
	TCHAR            aszBuyUrl[MAX_BUY_URL_LEN]; //�����ַ
	DT_BUY_GOLD_INFO_EX astBuyGoldLstEx[MAX_BUY_GOLD_NUM]; //����Ԫ���б�
}PKT_CLIGS_OPEN_VIP_TAB_ACK;

typedef struct tagPKT_CLIGS_OPEN_XIANGQIAN_TAB_REQ{
	tagPKT_CLIGS_OPEN_XIANGQIAN_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_XIANGQIAN_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_XIANGQIAN_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_XIANGQIAN_TAB_ACK{
	tagPKT_CLIGS_OPEN_XIANGQIAN_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_XIANGQIAN_TAB_ACK)); }
	UINT16           wErrCode; //������
	DT_ITEM_DATA_LIST_CLI2 stBagItemInfo; //������ʯ������Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
}PKT_CLIGS_OPEN_XIANGQIAN_TAB_ACK;

typedef struct tagPKT_CLIGS_XIANGQIAN_REQ{
	tagPKT_CLIGS_XIANGQIAN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_XIANGQIAN_REQ)); }
	UINT16           wHeroID; //�佫ID
	UINT16           wEquipID; //װ��ID
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wItemID; //�����ϳɵ���ƷID
	UINT8            byPos; //λ��
}PKT_CLIGS_XIANGQIAN_REQ;

typedef struct tagDT_XIANGQIAN_DATA_CLI{
	DT_EQUIP_DATA_CLI stEquip; //װ����Ϣ
	DT_ITEM_DATA_LIST_CLI2 stBagItemInfo; //������ʯ������Ϣ
}DT_XIANGQIAN_DATA_CLI;

typedef struct tagPKT_CLIGS_XIANGQIAN_ACK{
	tagPKT_CLIGS_XIANGQIAN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_XIANGQIAN_ACK)); }
	UINT16           wErrCode; //������
	DT_XIANGQIAN_DATA_CLI stXiangqianData; //��Ƕ���װ��������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
}PKT_CLIGS_XIANGQIAN_ACK;

typedef struct tagPKT_CLIGS_REMOVE_XIANGQIAN_REQ{
	tagPKT_CLIGS_REMOVE_XIANGQIAN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REMOVE_XIANGQIAN_REQ)); }
	UINT16           wHeroID; //�佫ID
	UINT16           wEquipID; //װ��ID
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT8            byRemoveAll; //һ���Ƴ�ȫ��
	UINT8            byPos; //��ʯλ��
}PKT_CLIGS_REMOVE_XIANGQIAN_REQ;

typedef struct tagPKT_CLIGS_REMOVE_XIANGQIAN_ACK{
	tagPKT_CLIGS_REMOVE_XIANGQIAN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REMOVE_XIANGQIAN_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wHeroID; //�佫ID
	DT_XIANGQIAN_DATA_CLI stXiangqianData; //��Ƕ���װ��������Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
}PKT_CLIGS_REMOVE_XIANGQIAN_ACK;

typedef struct tagPKT_CLIGS_RESET_ELITE_INSTANCE_REQ{
	tagPKT_CLIGS_RESET_ELITE_INSTANCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RESET_ELITE_INSTANCE_REQ)); }
	UINT8            byIndex; //�������
	UINT16           wRemainResetNum; //ʣ�����ô���(���������·����ͻ��˵���ֵ����)
}PKT_CLIGS_RESET_ELITE_INSTANCE_REQ;

typedef struct tagDT_ELITE_INSTANCE_VIP_EXT_DATA_CLI{
	UINT64           qwCurGold; //��ǰԪ��
	UINT16           wNextVipLevelNum; //�¸�VIP����������ܴ��������Ϊ0��VIP�����ˣ�
}DT_ELITE_INSTANCE_VIP_EXT_DATA_CLI;

typedef struct tagPKT_CLIGS_RESET_ELITE_INSTANCE_ACK{
	tagPKT_CLIGS_RESET_ELITE_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RESET_ELITE_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byIndex; //�������
	UINT16           wRemainResetNum; //ʣ�����ô���
	UINT16           wMaxResetNum; //�����ô���
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_ELITE_INSTANCE_VIP_EXT_DATA_CLI stEliteInstanceVipExt; //��Ӣ����VIP��չ��Ϣ
	UINT64           qwCostGold; //��һ�����𻨷�Ԫ��
}PKT_CLIGS_RESET_ELITE_INSTANCE_ACK;

typedef struct tagPKT_CLIGS_ELITE_INSTANCE_ON_HOOK_REQ{
	tagPKT_CLIGS_ELITE_INSTANCE_ON_HOOK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ELITE_INSTANCE_ON_HOOK_REQ)); }
	UINT8            byIndex; //�������
}PKT_CLIGS_ELITE_INSTANCE_ON_HOOK_REQ;

typedef struct tagDT_ELITE_INSTANCE_RECORD_DATA{
	UINT8            byIndex; //�������
	DT_BURST_ITEM_DATA stBurstItemInfo; //������Ʒ��Ϣ
	UINT16           wMainMonsterKindID; //��ʾ����������ID��0������ʾ
	UINT8            byCanBattle; //�Ƿ���Դ�1���Դ�
}DT_ELITE_INSTANCE_RECORD_DATA;

typedef struct tagDT_ELITE_INSTANCE_RECORD_DATA_CLI{
	UINT8            byIndex; //�������
	UINT8            byInstanceNum; //������
	DT_ELITE_INSTANCE_RECORD_DATA astInstanceInfo[MAX_INSTANCE_PER_TOWN_NUM]; //������¼��Ϣ
	UINT16           wRemainResetNum; //ʣ�����ô���
	UINT64           qwCostGold; //���û���Ԫ��
	UINT16           wOnhookLevel; //�һ��ȼ�Ҫ��
}DT_ELITE_INSTANCE_RECORD_DATA_CLI;

typedef struct tagDT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI{
	UINT8            byInstanceNum; //������
	UINT8            abyScore[MAX_INSTANCE_PER_TOWN_NUM]; //������¼��Ϣ
	DT_CHAPTER_SCORE stChapterInfo; //����������Ϣ
}DT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI;

typedef struct tagPKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK{
	tagPKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byOnhookResultNum; //ɨ����������
	DT_ONHOOK_RESULT astOnhookResult[MAX_INSTANCE_CLIMB_TOWER_NUM]; //ɨ�������
	DT_DATA_AFTER_ONHOOK stAfterOnhookData; //ɨ����Һ���Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT16           wAllOnhookNum; //�ܵĿɹһ���
	DT_ELITE_INSTANCE_RECORD_DATA_CLI stInstanceData; //������Ϣ
	DT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI stInstanceScoreData; //����������Ϣ
}PKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK;

typedef struct tagPKT_CLIGS_GET_ELITE_INSTANCE_REQ{
	tagPKT_CLIGS_GET_ELITE_INSTANCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ELITE_INSTANCE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_GET_ELITE_INSTANCE_REQ;

typedef struct tagPKT_CLIGS_GET_ELITE_INSTANCE_ACK{
	tagPKT_CLIGS_GET_ELITE_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ELITE_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_INSTANCE_ID   stMaxInstanceData; //��󸱱���Ϣ
	UINT8            byTownNum; //������
	DT_ELITE_INSTANCE_RECORD_DATA_CLI astTownInstanceInfo[MAX_TOWN_PER_SCENE_NUM]; //���򸱱���Ϣ
	UINT16           wNextUnlockInstanceTownID; //��һ������δ���������ĸ�����
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_ELITE_INSTANCE_VIP_EXT_DATA_CLI stEliteInstanceVipExt; //��Ӣ����VIP��չ��Ϣ
	UINT16           wMaxResetNum; //�����ô���
	DT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI astTownInstanceScoreInfo[MAX_TOWN_PER_SCENE_NUM]; //���򸱱�������Ϣ
	DT_ACCUMULATED_SCORE_ENCOURAGE stAccumulatedEncourage; //���۽�����Ϣ
	UINT16           wRemainResetNum; //ʣ�����ô���
}PKT_CLIGS_GET_ELITE_INSTANCE_ACK;

typedef struct tagDT_EQUIP_ID{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //װ�����
}DT_EQUIP_ID;

typedef struct tagPKT_CLIGS_QUICK_EQUIP_REQ{
	tagPKT_CLIGS_QUICK_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_QUICK_EQUIP_REQ)); }
	UINT16           wHeroKindID; //Ҫ�������佫
	UINT8            byEquipNum; //װ������
	DT_EQUIP_ID      astEquipIDLst[EQUIP_POS_NUM]; //Ҫ������װ��.0��ʾû��
}PKT_CLIGS_QUICK_EQUIP_REQ;

typedef struct tagPKT_CLIGS_QUICK_EQUIP_ACK{
	tagPKT_CLIGS_QUICK_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_QUICK_EQUIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //Ҫ�������佫
	UINT8            byEquipNum; //װ������
	DT_EQUIP_ID      astEquipIDLst[EQUIP_POS_NUM]; //Ҫ������װ��.0��ʾû��
	UINT32           dwPlayerHP; //�����Ѫ��
	DT_POWER_CHANGE_DATA stHeroPowerInfo; //�佫ս����Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_HERO_PANEL_LST_CLI stHeroPanelInfo; //�佫����Ϣ
}PKT_CLIGS_QUICK_EQUIP_ACK;

typedef struct tagPKT_CLIGS_PKBATTLE_REQ{
	tagPKT_CLIGS_PKBATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PKBATTLE_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PKBATTLE_REQ;

typedef struct tagPKT_CLIGS_PKBATTLE_ACK3{
	tagPKT_CLIGS_PKBATTLE_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_PKBATTLE_ACK3)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA3  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_PKBATTLE_ACK3;

typedef struct tagDT_RESOURCES_PROMPT{
	UINT8            byKindID; //����
	UINT8            byFlag; //����
}DT_RESOURCES_PROMPT;

typedef struct tagDT_RESOURCES_PROMPT_DATA{
	UINT8            byRsNum; //��Դ����
	DT_RESOURCES_PROMPT astRsPromptInfo[MAX_RESOURCES_NUM]; //��Դ��ʾ��Ϣ
}DT_RESOURCES_PROMPT_DATA;

typedef struct tagPKT_CLIGS_RESOURCES_PROMPT_REQ{
	tagPKT_CLIGS_RESOURCES_PROMPT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RESOURCES_PROMPT_REQ)); }
	UINT32           dwRsID; //��Դ
}PKT_CLIGS_RESOURCES_PROMPT_REQ;

typedef struct tagPKT_CLIGS_RESOURCES_PROMPT_ACK{
	tagPKT_CLIGS_RESOURCES_PROMPT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RESOURCES_PROMPT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RESOURCES_PROMPT_DATA stRsPromptData; //��Դ��Ϣ
}PKT_CLIGS_RESOURCES_PROMPT_ACK;

typedef struct tagDT_BOSSB_PLAYER_DATA_CLI{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT16           wHeroKindID; //���佫����
	UINT16           wLevel; //�ȼ�
	UINT16           wPosX; //λ����ϢX
	UINT16           wPosY; //λ����ϢY
}DT_BOSSB_PLAYER_DATA_CLI;

typedef struct tagDT_BOSSB_PLAYER_DATA_CLI_LST{
	UINT8            byNum; //����
	DT_BOSSB_PLAYER_DATA_CLI astInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //��Ϣ
}DT_BOSSB_PLAYER_DATA_CLI_LST;

typedef struct tagDT_BOSSB_DATA_CLI{
	UINT16           wBossID; //BOSS��ID
	UINT16           wBossLevel; //BOSS�ȼ�
	UINT32           dwTotalBossHP; //BOSS��Ѫ��
	UINT32           dwCurBossHP; //BOSS��ǰѪ��
	UINT32           dwHPPerGrid; //HPÿ��Ѫ��
	UINT32           dwPlayerNum; //��ǰ����
	UINT16           wReadyCountDown; //��ȴ�����ʱ
	UINT16           wStopCountDown; //���������ʱ
	UINT16           wReliveGold; //����Ԫ��
}DT_BOSSB_DATA_CLI;

typedef struct tagDT_BOSSB_DATA_CLI2{
	UINT16           wBossID; //BOSS��ID
	UINT16           wBossLevel; //BOSS�ȼ�
	UINT64           qwTotalBossHP; //BOSS��Ѫ��
	UINT64           qwCurBossHP; //BOSS��ǰѪ��
	UINT64           qwHPPerGrid; //HPÿ��Ѫ��
	UINT32           dwPlayerNum; //��ǰ����
	UINT16           wReadyCountDown; //��ȴ�����ʱ
	UINT16           wStopCountDown; //���������ʱ
	UINT16           wReliveGold; //����Ԫ��
}DT_BOSSB_DATA_CLI2;

typedef struct tagDT_BOSSB_MY_DATA_CLI{
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurJingJie; //��ǰ����
	UINT64           qwCurStory; //��ǰ����
	UINT16           wPosY; //λ����ϢY
	UINT16           wPosX; //λ����ϢX
	UINT16           wIncPowerRate; //����ս���ٷֱ�
	UINT16           wReliveCountDown; //�����ʱ
	UINT16           wGoldReliveCountDown; //Ԫ�������������ʱ
	UINT32           dwHurtValue; //��Boss���˺�
	UINT32           dwHurtRate; //��Boss���˺���������ֱȣ�
}DT_BOSSB_MY_DATA_CLI;

typedef struct tagDT_HURT_ENC_DATA{
	UINT32           dwEncCoin; //ͭǮ
	UINT32           dwEncJingJie; //����
}DT_HURT_ENC_DATA;

typedef struct tagPKT_ENTER_BOSSB_REQ{
	tagPKT_ENTER_BOSSB_REQ() { memset(this, 0, sizeof(tagPKT_ENTER_BOSSB_REQ)); }
	UINT16           wPosY; //λ����ϢY
	UINT16           wPosX; //λ����ϢX
}PKT_ENTER_BOSSB_REQ;

typedef struct tagPKT_ENTER_BOSSB_ACK{
	tagPKT_ENTER_BOSSB_ACK() { memset(this, 0, sizeof(tagPKT_ENTER_BOSSB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCliVer; //�ͻ��˰汾
	UINT32           dwResVer; //��Դ�汾
	UINT32           dwUIVer; //UI�汾
	DT_BOSSB_MY_DATA_CLI stMyBossBInfo; //�Լ���Ϣ
	DT_BOSSB_PLAYER_DATA_CLI_LST stPlayerInfo; //��ʾ�����Ϣ�б�
	DT_BOSSB_DATA_CLI stBossBInfo; //BOSSս��Ϣ
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	DT_HURT_ENC_DATA stHurtEncInfo; //�ѻ�õ��˺�����
	TCHAR            aszResVer[MAX_RES_VER_LEN]; //�汾��Ϣ
}PKT_ENTER_BOSSB_ACK;

typedef struct tagPKT_ENTER_BOSSB_ACK2{
	tagPKT_ENTER_BOSSB_ACK2() { memset(this, 0, sizeof(tagPKT_ENTER_BOSSB_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCliVer; //�ͻ��˰汾
	UINT32           dwResVer; //��Դ�汾
	UINT32           dwUIVer; //UI�汾
	DT_BOSSB_MY_DATA_CLI stMyBossBInfo; //�Լ���Ϣ
	DT_BOSSB_PLAYER_DATA_CLI_LST stPlayerInfo; //��ʾ�����Ϣ�б�
	DT_BOSSB_DATA_CLI2 stBossBInfo; //BOSSս��Ϣ
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	DT_HURT_ENC_DATA stHurtEncInfo; //�ѻ�õ��˺�����
	TCHAR            aszResVer[MAX_RES_VER_LEN]; //�汾��Ϣ
}PKT_ENTER_BOSSB_ACK2;

typedef struct tagPKT_LEAVE_BOSSB_REQ{
	tagPKT_LEAVE_BOSSB_REQ() { memset(this, 0, sizeof(tagPKT_LEAVE_BOSSB_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_LEAVE_BOSSB_REQ;

typedef struct tagPKT_LEAVE_BOSSB_ACK{
	tagPKT_LEAVE_BOSSB_ACK() { memset(this, 0, sizeof(tagPKT_LEAVE_BOSSB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_LEAVE_BOSSB_ACK;

typedef struct tagPKT_BOSSB_MOVE_REQ{
	tagPKT_BOSSB_MOVE_REQ() { memset(this, 0, sizeof(tagPKT_BOSSB_MOVE_REQ)); }
	UINT16           wPosX; //λ����ϢX
	UINT16           wPosY; //λ����ϢY
}PKT_BOSSB_MOVE_REQ;

typedef struct tagPKT_BOSSB_MOVE_ACK{
	tagPKT_BOSSB_MOVE_ACK() { memset(this, 0, sizeof(tagPKT_BOSSB_MOVE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wPosX; //λ����ϢX
	UINT16           wPosY; //λ����ϢY
	UINT16           wOldPosX; //ԭλ����ϢX
	UINT16           wOldPosY; //ԭλ����ϢY
}PKT_BOSSB_MOVE_ACK;

typedef struct tagPKT_BOSSB_HURT_REQ{
	tagPKT_BOSSB_HURT_REQ() { memset(this, 0, sizeof(tagPKT_BOSSB_HURT_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_BOSSB_HURT_REQ;

typedef struct tagPKT_BOSSB_HURT_ACK{
	tagPKT_BOSSB_HURT_ACK() { memset(this, 0, sizeof(tagPKT_BOSSB_HURT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCurHurtValue; //�����˺�ֵ
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�Լ��˺�ͳ��
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	DT_HURT_ENC_DATA stHurtEncInfo; //�ѻ�õ��˺�����
	UINT16           wReliveCountDown; //�����ʱ
	UINT16           wGoldReliveCountDown; //Ԫ�������������ʱ
	UINT32           dwTotalBossHP; //��ǰBoss��Ѫ��
	UINT32           dwCurBossHP; //��ǰBossѪ��
}PKT_BOSSB_HURT_ACK;

typedef struct tagPKT_BOSSB_HURT_ACK2{
	tagPKT_BOSSB_HURT_ACK2() { memset(this, 0, sizeof(tagPKT_BOSSB_HURT_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwCurHurtValue; //�����˺�ֵ
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�Լ��˺�ͳ��
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	DT_HURT_ENC_DATA stHurtEncInfo; //�ѻ�õ��˺�����
	UINT16           wReliveCountDown; //�����ʱ
	UINT16           wGoldReliveCountDown; //Ԫ�������������ʱ
	UINT64           qwTotalBossHP; //��ǰBoss��Ѫ��
	UINT64           qwCurBossHP; //��ǰBossѪ��
}PKT_BOSSB_HURT_ACK2;

typedef struct tagPKT_BOSSB_POS_NTF{
	tagPKT_BOSSB_POS_NTF() { memset(this, 0, sizeof(tagPKT_BOSSB_POS_NTF)); }
	UINT8            bySyncType; //ͬ������
	DT_BOSSB_PLAYER_DATA_CLI stPlayerInfo; //��Ϣ
	UINT32           dwPlayerNum; //��ǰ����
}PKT_BOSSB_POS_NTF;

typedef struct tagDT_BOSSB_POS{
	UINT32           dwPlayerID; //���ID
	UINT16           wPosX; //λ����ϢX
	UINT16           wPosY; //λ����ϢY
}DT_BOSSB_POS;

typedef struct tagDT_BOSSB_HURT{
	UINT32           dwPlayerID; //���ID
	UINT32           dwHurtValue; //�˺�ֵ
}DT_BOSSB_HURT;

typedef struct tagPKT_BOSSB_INFO_SYNC_NTF{
	tagPKT_BOSSB_INFO_SYNC_NTF() { memset(this, 0, sizeof(tagPKT_BOSSB_INFO_SYNC_NTF)); }
	UINT32           dwPlayerNum; //��ǰ����
	UINT32           dwTotalBossHP; //��ǰBoss��Ѫ��
	UINT32           dwCurBossHP; //��ǰBossѪ��
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	UINT8            byLeaveNum; //�뿪����
	UINT32           adwLeaveInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //�뿪��Ϣ
	UINT8            byEnterNum; //��������
	DT_BOSSB_PLAYER_DATA_CLI astEnterInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //������Ϣ
	UINT8            byMoveNum; //�ƶ�����
	DT_BOSSB_POS     astMoveInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //�ƶ���Ϣ
	UINT8            byHurtNum; //�˺�����
	DT_BOSSB_HURT    astHurtInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //�˺���Ϣ
}PKT_BOSSB_INFO_SYNC_NTF;

typedef struct tagPKT_BOSSB_INFO_SYNC_NTF2{
	tagPKT_BOSSB_INFO_SYNC_NTF2() { memset(this, 0, sizeof(tagPKT_BOSSB_INFO_SYNC_NTF2)); }
	UINT32           dwPlayerNum; //��ǰ����
	UINT64           qwTotalBossHP; //��ǰBoss��Ѫ��
	UINT64           qwCurBossHP; //��ǰBossѪ��
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	UINT8            byLeaveNum; //�뿪����
	UINT32           adwLeaveInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //�뿪��Ϣ
	UINT8            byEnterNum; //��������
	DT_BOSSB_PLAYER_DATA_CLI astEnterInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //������Ϣ
	UINT8            byMoveNum; //�ƶ�����
	DT_BOSSB_POS     astMoveInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //�ƶ���Ϣ
	UINT8            byHurtNum; //�˺�����
	DT_BOSSB_HURT    astHurtInfo[MAX_BOSSB_SHOW_PLAYER_NUM]; //�˺���Ϣ
}PKT_BOSSB_INFO_SYNC_NTF2;

typedef struct tagDT_BOSSB_OVER_INFO{
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�������˺�
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	UINT32           dwTotalBossHP; //��ǰBoss��Ѫ��
	UINT32           dwCurBossHP; //��ǰBossѪ��
	DT_BOSS_BATTLE_ENC_DATA stHurtEncInfo; //�˺�������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stHeroEncInfo; //Ӣ�۽�����Ϣ
	DT_BOSS_BATTLE_ENC_DATA astTopEncInfo[MAX_BOSS_ENC_TOP_NUM]; //top������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stKillEncInfo; //���1��������Ϣ
	UINT8            byBossDeadFlag; //BOSS�Ƿ�����,1����
	UINT8            byNeedUpgrade; //BOSS�Ƿ�����,1����
}DT_BOSSB_OVER_INFO;

typedef struct tagDT_BOSSB_OVER_INFO2{
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�������˺�
	DT_BOSSB_HURT_RATE astTopHurtInfo[MAX_BOSS_ENC_TOP_NUM]; //����˺�ͳ������
	UINT64           qwTotalBossHP; //��ǰBoss��Ѫ��
	UINT64           qwCurBossHP; //��ǰBossѪ��
	DT_BOSS_BATTLE_ENC_DATA stHurtEncInfo; //�˺�������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stHeroEncInfo; //Ӣ�۽�����Ϣ
	DT_BOSS_BATTLE_ENC_DATA astTopEncInfo[MAX_BOSS_ENC_TOP_NUM]; //top������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stKillEncInfo; //���1��������Ϣ
	UINT8            byBossDeadFlag; //BOSS�Ƿ�����,1����
	UINT8            byNeedUpgrade; //BOSS�Ƿ�����,1����
}DT_BOSSB_OVER_INFO2;

typedef struct tagPKT_BOSSB_OVER_NTF{
	tagPKT_BOSSB_OVER_NTF() { memset(this, 0, sizeof(tagPKT_BOSSB_OVER_NTF)); }
	DT_BOSSB_OVER_INFO stBossOverInfo; //bossս�������Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //��ǰ����
	UINT64           qwCurJingJie; //��ǰ����
	UINT8            byUnreadBattleLogNum; //δ��ս������
}PKT_BOSSB_OVER_NTF;

typedef struct tagPKT_BOSSB_OVER_NTF2{
	tagPKT_BOSSB_OVER_NTF2() { memset(this, 0, sizeof(tagPKT_BOSSB_OVER_NTF2)); }
	DT_BOSSB_OVER_INFO2 stBossOverInfo; //bossս�������Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //��ǰ����
	UINT64           qwCurJingJie; //��ǰ����
	UINT8            byUnreadBattleLogNum; //δ��ս������
}PKT_BOSSB_OVER_NTF2;

typedef struct tagPKT_OPEN_INSPIRE_TAB_REQ{
	tagPKT_OPEN_INSPIRE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_OPEN_INSPIRE_TAB_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_OPEN_INSPIRE_TAB_REQ;

typedef struct tagDT_INSPIRE_TAB_DATA{
	UINT16           wHaveIncPowerRate; //������ս���ٷֱ�
	UINT16           wIncCostStory; //����ս����������
	UINT16           wIncCostGold; //����ս������Ԫ��
	UINT16           wStoryIncRate; //��������ս���ٷֱ�
	UINT16           wGoldIncRate; //Ԫ������ս���ٷֱ�
	UINT16           wCanIncPowerRate; //������ս���ٷֱ�
}DT_INSPIRE_TAB_DATA;

typedef struct tagPKT_OPEN_INSPIRE_TAB_ACK{
	tagPKT_OPEN_INSPIRE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_OPEN_INSPIRE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_INSPIRE_TAB_DATA stInspireTabInfo; //���������Ϣ
}PKT_OPEN_INSPIRE_TAB_ACK;

typedef struct tagPKT_INSPIRE_POWER_REQ{
	tagPKT_INSPIRE_POWER_REQ() { memset(this, 0, sizeof(tagPKT_INSPIRE_POWER_REQ)); }
	UINT8            byGoldInspireFlag; //�Ƿ�Ԫ�����跽ʽ��1Ϊʹ��Ԫ������
}PKT_INSPIRE_POWER_REQ;

typedef struct tagPKT_INSPIRE_POWER_ACK{
	tagPKT_INSPIRE_POWER_ACK() { memset(this, 0, sizeof(tagPKT_INSPIRE_POWER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_INSPIRE_TAB_DATA stInspireTabInfo; //���������Ϣ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //��ǰ����
}PKT_INSPIRE_POWER_ACK;

typedef struct tagPKT_BOSSB_RELIVE_REQ{
	tagPKT_BOSSB_RELIVE_REQ() { memset(this, 0, sizeof(tagPKT_BOSSB_RELIVE_REQ)); }
	UINT16           wExt; //��չ�ֶ�
}PKT_BOSSB_RELIVE_REQ;

typedef struct tagPKT_BOSSB_RELIVE_ACK{
	tagPKT_BOSSB_RELIVE_ACK() { memset(this, 0, sizeof(tagPKT_BOSSB_RELIVE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ǰԪ��
}PKT_BOSSB_RELIVE_ACK;

typedef struct tagPKT_BOSSB_GET_LAST_BOSSB_INFO_REQ{
	tagPKT_BOSSB_GET_LAST_BOSSB_INFO_REQ() { memset(this, 0, sizeof(tagPKT_BOSSB_GET_LAST_BOSSB_INFO_REQ)); }
	UINT16           wExt; //��չ�ֶ�
}PKT_BOSSB_GET_LAST_BOSSB_INFO_REQ;

typedef struct tagPKT_BOSSB_GET_LAST_BOSSB_INFO_ACK{
	tagPKT_BOSSB_GET_LAST_BOSSB_INFO_ACK() { memset(this, 0, sizeof(tagPKT_BOSSB_GET_LAST_BOSSB_INFO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BOSSB_OVER_INFO stBossOverInfo; //bossս�������Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //��ǰ����
	UINT64           qwCurJingJie; //��ǰ����
}PKT_BOSSB_GET_LAST_BOSSB_INFO_ACK;

typedef struct tagPKT_BOSSB_GET_LAST_BOSSB_INFO_ACK2{
	tagPKT_BOSSB_GET_LAST_BOSSB_INFO_ACK2() { memset(this, 0, sizeof(tagPKT_BOSSB_GET_LAST_BOSSB_INFO_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BOSSB_OVER_INFO2 stBossOverInfo; //bossս�������Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //��ǰ����
	UINT64           qwCurJingJie; //��ǰ����
}PKT_BOSSB_GET_LAST_BOSSB_INFO_ACK2;

typedef struct tagPKT_CLILS_OPEN_RECHARGE_ENCOURAGE_REQ{
	tagPKT_CLILS_OPEN_RECHARGE_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_OPEN_RECHARGE_ENCOURAGE_REQ)); }
	UINT16           wExt; //��չ�ֶ�
}PKT_CLILS_OPEN_RECHARGE_ENCOURAGE_REQ;

typedef struct tagPKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK{
	tagPKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFlag; //��־λ��0���ɳ�ֵ��ʾ�� 1������ȡ��ֵ����
	DT_HERO_BASE_DATA_CLI stHeroBaseInfo; //�佫������Ϣ
	DT_SKILL_DATA_CLI stSkillInfo; //�佫������Ϣ
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemList[MAX_RECHARGE_ITEM_NUM]; //������Ϣ
}PKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_RECV_RECHARGE_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_RECHARGE_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_RECHARGE_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ�δʹ��
}PKT_CLIGS_RECV_RECHARGE_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK;

typedef struct tagPKT_CLILS_OPEN_SCORE_ENCOURAGE_REQ{
	tagPKT_CLILS_OPEN_SCORE_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_OPEN_SCORE_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLILS_OPEN_SCORE_ENCOURAGE_REQ;

typedef struct tagPKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK{
	tagPKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byAppAddNum; //��ַ����
	UINT8            abyAppAddress[MAX_APP_ADDRESS_NUM]; //��ַ��Ϣ
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemList[MAX_SCORE_ITEM_NUM]; //������Ϣ
}PKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_RECV_SCORE_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_SCORE_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_SCORE_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶΣ�δʹ��
}PKT_CLIGS_RECV_SCORE_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_GET_RANDOM_DSPNAME_REQ{
	tagPKT_CLIGS_GET_RANDOM_DSPNAME_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_RANDOM_DSPNAME_REQ)); }
	UINT8            byExt; //��չ�ֶΣ�δʹ��
}PKT_CLIGS_GET_RANDOM_DSPNAME_REQ;

typedef struct tagPKT_CLIGS_GET_RANDOM_DSPNAME_ACK{
	tagPKT_CLIGS_GET_RANDOM_DSPNAME_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_RANDOM_DSPNAME_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	TCHAR            aszDspName[USERNAME_LEN]; //�ǳ�
}PKT_CLIGS_GET_RANDOM_DSPNAME_ACK;

typedef struct tagDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_CLI{
	UINT64           qwOverTime; //�����ʱ��
	UINT16           wBossID; //�BOSSID
	DT_BOSSB_HURT_RATE stMyHurtInfo; //�������˺�
	DT_BOSS_BATTLE_ENC_DATA stHurtEncInfo; //�˺�������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stHeroEncInfo; //Ӣ�۽�����Ϣ
	DT_BOSS_BATTLE_ENC_DATA astBossBTopEncInfo[MAX_BOSS_ENC_TOP_NUM]; //top������Ϣ
	DT_BOSS_BATTLE_ENC_DATA stBossBKillEncInfo; //���1��������Ϣ
}DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ{
	tagPKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ)); }
	UINT8            byExt; //��չ�ֶΣ�δʹ��
}PKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ;

typedef struct tagPKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK{
	tagPKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byNum; //ս������
	DT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_CLI astBossBattleBL[MAX_BOSSB_BATTLE_LOG_NUM]; //ս����Ϣ
}PKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK;

typedef struct tagDT_HERO_UPGRADE_LEVEL{
	UINT8            byFreeLevel; //��ѿɻ�ȡ�ȼ�
	UINT8            byGoldLevel; //ʹ��Ԫ���ɻ�ȡ�ȼ�
}DT_HERO_UPGRADE_LEVEL;

typedef struct tagPKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ{
	tagPKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ)); }
	UINT16           wHeroID; //�佫ID
}PKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ;

typedef struct tagPKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK{
	tagPKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFreePercentage; //��ѿɻ�ȡ����ٷֱ�
	UINT8            byGoldPercentage; //ʹ��Ԫ���ɻ�ȡ����ٷֱ�
	UINT16           wGold; //Ԫ����
	DT_HERO_BASE_DATA_CLI stHeroInfo; //��ǰ�佫��Ϣ
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_BASE_DATA_CLI astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	DT_HERO_UPGRADE_LEVEL astUpgradeHeroInfoLst[MAX_HERO_NUM]; //�佫������Ϣ
}PKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK;

typedef struct tagPKT_CLIGS_EXPERIENCE_TRANSFER_REQ{
	tagPKT_CLIGS_EXPERIENCE_TRANSFER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EXPERIENCE_TRANSFER_REQ)); }
	UINT16           wHeroID; //Ҫ���ݵ��佫ID
	UINT16           wTransHeroID; //�����ݵ��佫ID
	UINT8            byGold; //ʹ��Ԫ����־��1ʹ��Ԫ��
}PKT_CLIGS_EXPERIENCE_TRANSFER_REQ;

typedef struct tagPKT_CLIGS_EXPERIENCE_TRANSFER_ACK{
	tagPKT_CLIGS_EXPERIENCE_TRANSFER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EXPERIENCE_TRANSFER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_POWER_CHANGE_DATA stPowerChangeData; //�佫ս����Ϣ
	DT_HERO_BASE_DATA_CLI stHeroInfo; //��ǰ�佫��Ϣ
	DT_HERO_BASE_DATA_CLI stTransHeroInfo; //�������佫��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT64           qwCurGold; //��ǰԪ��
}PKT_CLIGS_EXPERIENCE_TRANSFER_ACK;

typedef struct tagDT_RDCHALLENGE_POINT_DATA_CLI{
	UINT16           wCurChallengePoint; //��ǰ��ս��
	UINT16           wMaxChallengePoint; //�����ս��
	UINT16           wRefreshCD; //��ս��ˢ�¼��,��λs
	UINT16           wCountDown; //��ս��ˢ�µ���ʱ
}DT_RDCHALLENGE_POINT_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_RDCHALLENGE_TAB_REQ{
	tagPKT_CLIGS_OPEN_RDCHALLENGE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RDCHALLENGE_TAB_REQ)); }
	UINT8            byRefreshFlag; //�Ƿ�ˢ�£�1Ϊˢ��
}PKT_CLIGS_OPEN_RDCHALLENGE_TAB_REQ;

typedef struct tagDT_RDC_ENC_DATA{
	UINT32           dwJingJie; //�����
	UINT32           dwPurpleGas; //����
}DT_RDC_ENC_DATA;

typedef struct tagDT_RDC_PLAYER_DATA_CLI{
	DT_RDC_PLAYER_DATA stPlayerInfo; //�����Ϣ
	DT_RDC_ENC_DATA  stSuccessEnc; //Ӯ������Ϣ
	DT_RDC_ENC_DATA  stFailEnc; //�佱����Ϣ
}DT_RDC_PLAYER_DATA_CLI;

typedef struct tagDT_RDC_TAB_DATA{
	UINT8            byPlayerNum; //��ǰ������Ҹ���
	DT_RDC_PLAYER_DATA_CLI astPlayerInfo[MAX_GET_RDC_NUM]; //�����Ϣ
	DT_RDCHALLENGE_POINT_DATA_CLI stChallengePointInfo; //��ս����Ϣ
	UINT16           wChallengeCountDown; //��ս����ʱ
	UINT32           dwRefreshCoin; //ˢ������ͭǮ
	UINT32           dwClrCDGold; //���CDԪ��
}DT_RDC_TAB_DATA;

typedef struct tagPKT_CLIGS_OPEN_RDCHALLENGE_TAB_ACK{
	tagPKT_CLIGS_OPEN_RDCHALLENGE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RDCHALLENGE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RDC_TAB_DATA  stTabInfo; //�����ս�����Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurJingJie; //��ǰ�����
	UINT64           qwCurPurpleGas; //��ǰ����
	UINT8            byHaveWorship; //�Ƿ��Ѿ�Ĥ�ݣ�1Ϊ�Ѿ�Ĥ��
}PKT_CLIGS_OPEN_RDCHALLENGE_TAB_ACK;

typedef struct tagPKT_CLIGS_RDCHALLENGE_REQ{
	tagPKT_CLIGS_RDCHALLENGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RDCHALLENGE_REQ)); }
	UINT32           dwPlayerID; //Ҫ��ս�����ID
}PKT_CLIGS_RDCHALLENGE_REQ;

typedef struct tagPKT_CLIGS_RDCHALLENGE_ACK3{
	tagPKT_CLIGS_RDCHALLENGE_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_RDCHALLENGE_ACK3)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA3  stBattleInfo; //ս����Ϣ
	DT_RDC_TAB_DATA  stTabInfo; //�����ս�����Ϣ
	DT_RDC_ENC_DATA  stEncInfo; //�����ս������Ϣ
	UINT64           qwCurJingJie; //��ǰ�����
	UINT64           qwCurPurpleGas; //��ǰ����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT16           wKindID; //��õ��ʻ�ID
}PKT_CLIGS_RDCHALLENGE_ACK3;

typedef struct tagPKT_CLIGS_CLR_RDCHALLENGE_CD_REQ{
	tagPKT_CLIGS_CLR_RDCHALLENGE_CD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_RDCHALLENGE_CD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_CLR_RDCHALLENGE_CD_REQ;

typedef struct tagPKT_CLIGS_CLR_RDCHALLENGE_CD_ACK{
	tagPKT_CLIGS_CLR_RDCHALLENGE_CD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_RDCHALLENGE_CD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
}PKT_CLIGS_CLR_RDCHALLENGE_CD_ACK;

typedef struct tagDT_WORSHIP_DATA_CLI{
	UINT8            byWorshipTypeLevel; //Ĥ�ݼ���1Ϊ��ߵȼ�
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT32           dwPlayerID; //���ID
	UINT32           dwCoachID; //����ID
	UINT32           dwNeedCoin; //Ĥ������ͭǮ��0Ϊ����Ҫ
	UINT32           dwNeedGold; //Ĥ������Ԫ����0Ϊ����Ҫ
	UINT8            byNeedVipLevel; //Ĥ������VIP�ȼ���0Ϊ����Ҫ
	UINT32           dwEncJingJie; //Ĥ�ݿɻ�þ���
	UINT32           dwEncPurpleGas; //Ĥ�ݿɻ������
	UINT8            byHaveWorship; //�Ƿ��Ѿ�Ĥ�ݣ�1Ϊ�Ѿ�Ĥ��
}DT_WORSHIP_DATA_CLI;

typedef struct tagDT_WORSHIP_DATA_CLI_LST{
	UINT16           wNum; //����
	DT_WORSHIP_DATA_CLI astWorshipInfo[MAX_WORSHIP_NUM]; //��Ϣ
}DT_WORSHIP_DATA_CLI_LST;

typedef struct tagPKT_CLIGS_OPEN_WORSHIP_TAB_REQ{
	tagPKT_CLIGS_OPEN_WORSHIP_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_WORSHIP_TAB_REQ)); }
	UINT8            byWorshipType; //Ĥ������
}PKT_CLIGS_OPEN_WORSHIP_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_WORSHIP_TAB_ACK{
	tagPKT_CLIGS_OPEN_WORSHIP_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_WORSHIP_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_WORSHIP_DATA_CLI_LST stWorshipInfo; //Ĥ����Ϣ�б�
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT64           qwCurJingJie; //��ҵ�ǰ�ľ���
	UINT64           qwCurPurpleGas; //��ҵ�ǰ������
}PKT_CLIGS_OPEN_WORSHIP_TAB_ACK;

typedef struct tagPKT_CLIGS_WORSHIP_REQ{
	tagPKT_CLIGS_WORSHIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_WORSHIP_REQ)); }
	UINT8            byWorshipType; //Ĥ������
	UINT8            byWorshipTypeLevel; //Ĥ�ݼ���
}PKT_CLIGS_WORSHIP_REQ;

typedef struct tagPKT_CLIGS_WORSHIP_ACK{
	tagPKT_CLIGS_WORSHIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_WORSHIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_WORSHIP_DATA_CLI_LST stWorshipInfo; //Ĥ����Ϣ�б�
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT64           qwCurJingJie; //��ҵ�ǰ�ľ���
	UINT64           qwCurPurpleGas; //��ҵ�ǰ������
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_WORSHIP_ACK;

typedef struct tagPKT_CLIGS_ACTIVITY_NOTIFY_REQ{
	tagPKT_CLIGS_ACTIVITY_NOTIFY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ACTIVITY_NOTIFY_REQ)); }
	UINT8            byActivityType; //����
	UINT8            byNotify; //֪ͨ
}PKT_CLIGS_ACTIVITY_NOTIFY_REQ;

typedef struct tagPKT_CLIGS_ACTIVITY_NOTIFY_ACK{
	tagPKT_CLIGS_ACTIVITY_NOTIFY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ACTIVITY_NOTIFY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_ACTIVITY_NOTIFY_ACK;

typedef struct tagDT_DOGFECES_BUILD_TIP{
	UINT16           wBuildID; //����ID
	UINT32           dwParameter1; //����
	UINT32           dwParameter2; //����
	UINT32           dwParameter3; //����
	UINT32           dwParameter4; //����
	UINT32           dwParameter5; //����
}DT_DOGFECES_BUILD_TIP;

typedef struct tagPKT_CLIGS_OPEN_DOGFECES_REQ{
	tagPKT_CLIGS_OPEN_DOGFECES_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DOGFECES_REQ)); }
	UINT8            byType; //��������
}PKT_CLIGS_OPEN_DOGFECES_REQ;

typedef struct tagPKT_CLIGS_OPEN_DOGFECES_ACK{
	tagPKT_CLIGS_OPEN_DOGFECES_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DOGFECES_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byNum; //����
	DT_DOGFECES_BUILD_TIP astDogFecesBuildTip[MAX_DOGFECES_BUILD_TIP_NUM]; //������Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_OPEN_DOGFECES_ACK;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_CENTER_REQ{
	tagPKT_CLIGS_GET_ACTIVITY_CENTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_CENTER_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_ACTIVITY_CENTER_REQ;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_CENTER_ACK{
	tagPKT_CLIGS_GET_ACTIVITY_CENTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_CENTER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byActivityNum; //���
	DT_ACTIVITY_BASE_DATA astActivityInfo[MAX_ACTIVITY_NUM]; //�
	UINT8            abyActivityStartCountDown[MAX_ACTIVITY_NUM]; //�������������ʱ
}PKT_CLIGS_GET_ACTIVITY_CENTER_ACK;

typedef struct tagDT_ACTIVITY_ENCOURAGE_DATA_CLI{
	UINT16           wActivityID; //�����
	UINT8            byCanReceive; //�Ƿ����ȡ
	UINT8            bySeriesNo; //�Ƿ���ϵ�кű�־
	TCHAR            aszActivityName[MAX_ACTIVITY_ENCOURAGE_NAME_LEN]; //�����
	TCHAR            aszActivityDesc[MAX_ACTIVITY_ENCOURAGE_DESC_LEN]; //�����
	TCHAR            aszObtainingConditions[MAX_ACTIVITY_ENCOURAGE_DESC_LEN]; //��ȡ����
	DT_ENCOURAGE_DATA stEncourageData; //������Ϣ
}DT_ACTIVITY_ENCOURAGE_DATA_CLI;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ{
	tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK{
	tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byActivityEncourageNum; //���
	DT_ACTIVITY_ENCOURAGE_DATA_CLI astActivityEncourageInfo[MAX_ACTIVITY_ENCOURAGE_NUM]; //�������Ϣ
}PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK;

typedef struct tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ{
	tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ)); }
	UINT16           wActivityID; //�����
	TCHAR            aszSeriesNo[MAX_SERIES_NO_NUM]; //ϵ����
}PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK{
	tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wActivityIDOld; //�����
	DT_RSYNC_RECV_ENCOURAGE_DATA stRsyncRecvEncourageData; //ͬ����ȡ������������ݱ仯
	UINT8            byHide; //����
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ
}PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK;

typedef struct tagDT_ACTIVITY_ENCOURAGE_DATA_CLI2{
	UINT64           qwActivityID; //�����
	UINT8            byCanReceive; //�Ƿ����ȡ
	UINT8            bySeriesNo; //�Ƿ���ϵ�кű�־
	TCHAR            aszActivityName[MAX_ACTIVITY_ENCOURAGE_NAME_LEN]; //�����
	TCHAR            aszActivityDesc[MAX_ACTIVITY_ENCOURAGE_DESC_LEN]; //�����
	TCHAR            aszObtainingConditions[MAX_ACTIVITY_ENCOURAGE_DESC_LEN]; //��ȡ����
	DT_ENCOURAGE_DATA stEncourageData; //������Ϣ
}DT_ACTIVITY_ENCOURAGE_DATA_CLI2;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2{
	tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2;

typedef struct tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2{
	tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byActivityEncourageNum; //���
	DT_ACTIVITY_ENCOURAGE_DATA_CLI2 astActivityEncourageInfo[MAX_ACTIVITY_ENCOURAGE_NUM]; //�������Ϣ
}PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2;

typedef struct tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2{
	tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2)); }
	UINT64           qwActivityID; //�����
	TCHAR            aszSeriesNo[MAX_SERIES_NO_NUM]; //ϵ����
}PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2;

typedef struct tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2{
	tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwActivityID; //�����
	DT_RSYNC_RECV_ENCOURAGE_DATA stRsyncRecvEncourageData; //ͬ����ȡ������������ݱ仯
	UINT8            byHide; //����
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ
}PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2;

typedef struct tagDT_GEM_MAKER_DATA{
	UINT16           wMakerKindID; //��������ƷID
	UINT16           wPileNum; //����
	UINT16           wGemKindID; //�����ɵı�ʯ��ƷID
	UINT16           wGemLevel; //������ʯ�ȼ�
	UINT32           dwNeedBlueGas; //������������
	UINT8            byOpenNeedTowerNum; //����������������
	TCHAR            aszSuccessRate[MAX_COMMON_TXT_NUM]; //�ɹ���
	DT_ITEM_DATA_LIST_CLI2 stGemInfo; //�ɺϳɱ�ʯ��Ϣ
}DT_GEM_MAKER_DATA;

typedef struct tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_REQ{
	tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_GEM_MAKER_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_ACK{
	tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurBlueGas; //��ǰ����
	UINT8            byCurTowerNum; //��ǰ����������
	UINT8            byMakerNum; //���������(��δȫ�����ţ�����·�һ��δ���ŵ�)
	DT_GEM_MAKER_DATA astGemMakerInfo[MAX_GEM_LEVEL]; //��ʯ��������Ϣ
	TCHAR            aszOtherPrompt[MAX_COMMON_TXT_NUM]; //��ʾ
}PKT_CLIGS_OPEN_GEM_MAKER_TAB_ACK;

typedef struct tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ{
	tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ;

typedef struct tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK{
	tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurBlueGas; //��ǰ����
	UINT8            byCurTowerNum; //��ǰ����������
	UINT8            byMakerNum; //���������(��δȫ�����ţ�����·�һ��δ���ŵ�)
	DT_GEM_MAKER_DATA astGemMakerInfo[MAX_GEM_LEVEL_EX]; //��ʯ��������Ϣ
	TCHAR            aszOtherPrompt[MAX_COMMON_TXT_NUM]; //��ʾ
}PKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK;

typedef struct tagPKT_CLIGS_RECV_RATING_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_RATING_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_RATING_ENCOURAGE_REQ)); }
	UINT16           wSceneIdx; //��������
	UINT8            byType; //��������0������ͨ�أ�1�����۽���
	UINT16           wChapterID; //�½�ID��ֻ������ͨ�ز���ֵ�����۽���ֱ��Ϊ0����
}PKT_CLIGS_RECV_RATING_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_RATING_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_RATING_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_RATING_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byType; //��������0������ͨ�أ�1�����۽���
	UINT16           wChapterID; //�½�ID��ֻ������ͨ�ز���ֵ�����۽���ֱ��Ϊ0����
	DT_RSYNC_RECV_ENCOURAGE_DATA stRsyncRecvEncourageData; //ͬ����ȡ������������ݱ仯
	DT_ACCUMULATED_SCORE_ENCOURAGE stAccumulatedEncourage; //���۽�����Ϣ
}PKT_CLIGS_RECV_RATING_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ{
	tagPKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ;

typedef struct tagDT_STUDY_DATA_CLI2{
	UINT8            byStudyColorKind; //�ĵ���ɫ����1��ʼ��0��ʾû������
	UINT8            byStudyAttrKind1; //�ĵ�����(��Ӧ��������,0��ʾֻ��ת������)
	UINT8            byStudyLevel; //�ĵõȼ�(��1��ʼ��������0)
	UINT32           dwStudyAttrValue1; //�ĵ�����ֵ
	UINT32           dwStudyExp; //�ĵþ���ֵ
	UINT32           dwNextLevelAttrValue1; //��һ���ĵ�����ֵ
	UINT32           dwUpgradeNeedExp; //��������һ�������ĵþ���
	UINT8            byStudyAttrKind2; //�ĵ�����(��Ӧ��������)
	UINT32           dwStudyAttrValue2; //�ĵ�����ֵ
	UINT32           dwNextLevelAttrValue2; //��һ���ĵ�����ֵ
}DT_STUDY_DATA_CLI2;

typedef struct tagDT_AWAKEN_TAB_DATA2{
	DT_AWAKEN_BASE_DATA stBaseInfo; //���������Ϣ
	DT_STUDY_DATA_CLI2 astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT16           wMaxStudyLevel; //�ĵ����ȼ�
	UINT32           adwAwakenCoin[MAX_AWAKEN_NUM]; //�������ͭ��
	UINT32           dwAwakenGold; //�������Ԫ��
	UINT16           wTatalCallNum; //�ܹ����ٻ�����
	UINT16           wCanCallNum; //ʣ����ٻ�����
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	DT_STUDY_DATA_CLI2 stCallStudy; //�ٻ��ɵ��ĵ�
}DT_AWAKEN_TAB_DATA2;

typedef struct tagDT_AWAKEN_STUDY_EXCHANGE_DATA{
	DT_STUDY_DATA_CLI2 stStudyInfo; //�ĵ���Ϣ
	UINT32           dwNeedCoin; //�һ�����ͭǮ
	UINT32           dwNeedClip; //�һ�������Ƭ
	UINT16           wNeePlayerLevel; //���ŵȼ�
}DT_AWAKEN_STUDY_EXCHANGE_DATA;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK{
	tagPKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byExchangeNum; //�һ��ĵ���
	DT_AWAKEN_STUDY_EXCHANGE_DATA astStudyExchangeInfo[MAX_EXCHANGE_STUDY_NUM]; //�ĵöһ���Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurStudyClip; //��ǰ�ĵ���Ƭ
}PKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK;

typedef struct tagPKT_CLIGS_EXCHANGE_STUDY_REQ{
	tagPKT_CLIGS_EXCHANGE_STUDY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_STUDY_REQ)); }
	UINT8            byStudyColorKind; //�ĵ���ɫ
	UINT8            byStudyAttrKind1; //�ĵ�����
	UINT8            byStudyAttrKind2; //�ĵ�����
	UINT8            byStudyLevel; //�ĵõȼ�
}PKT_CLIGS_EXCHANGE_STUDY_REQ;

typedef struct tagPKT_CLIGS_EXCHANGE_STUDY_ACK{
	tagPKT_CLIGS_EXCHANGE_STUDY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_STUDY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byStudyBagIdx; //�����ĵ����(��Ӧ�ĵñ�����ţ���0��ʼ)
	DT_AWAKEN_TAB_DATA2 stAwakenTabInfo; //��������Ϣ
}PKT_CLIGS_EXCHANGE_STUDY_ACK;

typedef struct tagPKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ{
	tagPKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ;

typedef struct tagDT_COMPOSE_EQUIP_DATA_CLI{
	UINT16           wKindID; //װ������
	UINT8            byDressPos; //����λ��
	UINT16           wStrengthenLevel; //װ��ǿ���ȼ�
	UINT16           wDressLevel; //װ��������)�ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //��ǰս������
}DT_COMPOSE_EQUIP_DATA_CLI;

typedef struct tagDT_EQUIP_COMPOSE_LEVEL_DATA_CLI{
	UINT16           wEquipLevel; //װ���ȼ�
	UINT8            byEquipNum; //װ������
	DT_COMPOSE_EQUIP_DATA_CLI astEquipInfo[MAX_BAG_OPEN_NUM]; //װ����Ϣ
	UINT16           wEquipClipNum; //��ǰ�ȼ�װ����Ƭ��
	UINT16           wComposeNeedNum; //�ϳɸõȼ�װ��������Ƭ��
	UINT8            byCurLowColor; //��ǰ�����ɫ
	UINT16           wHitKindID; //��ǰ����װ��ID
	UINT32           dwColorComposeNeedGold; //��ǰ��ɫ�ϳ�����Ԫ��
	UINT32           dwCommonComposeNeedGold; //��ͨ�ϳ�����Ԫ��
}DT_EQUIP_COMPOSE_LEVEL_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK{
	tagPKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byEquipLevelNum; //װ���ȼ�����
	DT_EQUIP_COMPOSE_LEVEL_DATA_CLI astEquipLevelInfo[MAX_EQUIPLEVEL_NUM]; //װ���ȼ���Ϣ
	UINT16           wComposeCountDown; //�ϳɵ���ʱ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurBlueGas; //��ǰ����
}PKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK;

typedef struct tagPKT_CLIGS_EQUIP_COMPOSE_REQ{
	tagPKT_CLIGS_EQUIP_COMPOSE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_COMPOSE_REQ)); }
	UINT16           wEquipLevel; //װ���ȼ�
	UINT8            byCurColorFlag; //��ǰ�����ɫ�������кϳɣ�1Ϊѡ��
}PKT_CLIGS_EQUIP_COMPOSE_REQ;

typedef struct tagPKT_CLIGS_EQUIP_COMPOSE_ACK{
	tagPKT_CLIGS_EQUIP_COMPOSE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_COMPOSE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EQUIP_COMPOSE_LEVEL_DATA_CLI stEquipLevelInfo; //װ���ȼ���Ϣ
	UINT16           wComposeCountDown; //�ϳɵ���ʱ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurBlueGas; //��ǰ����
}PKT_CLIGS_EQUIP_COMPOSE_ACK;

typedef struct tagPKT_CLIGS_RECV_COMPOSE_EQUIP_REQ{
	tagPKT_CLIGS_RECV_COMPOSE_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_COMPOSE_EQUIP_REQ)); }
	UINT16           wEquipLevel; //װ���ȼ�
}PKT_CLIGS_RECV_COMPOSE_EQUIP_REQ;

typedef struct tagPKT_CLIGS_RECV_COMPOSE_EQUIP_ACK{
	tagPKT_CLIGS_RECV_COMPOSE_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_COMPOSE_EQUIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EQUIP_COMPOSE_LEVEL_DATA_CLI stEquipLevelInfo; //װ���ȼ���Ϣ
	DT_EQUIP_DATA_CLI stRecvEquipInfo; //��ȡ��װ����Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI stRecvEquipStrengthenInfo; //��ȡ��װ����Ϣ����ǿ����
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	UINT32           dwStrengthen10Coin; //װ����10������ҪͭǮ��Ϣ
}PKT_CLIGS_RECV_COMPOSE_EQUIP_ACK;

typedef struct tagDT_FACTION_DATA_TO_CLI{
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT32           dwFactionRank; //��������
	UINT32           dwFactionLevel; //���ɵȼ�
	UINT32           dwFactionFunds; //�����ʽ�
	TCHAR            aszFactionAnnouncement[MAX_FACTION_DESC_NUM]; //���ɹ���
	UINT32           dwFactionID; //����ID
}DT_FACTION_DATA_TO_CLI;

typedef struct tagDT_FACTION_BASE_DATA_CLI{
	UINT8            byJoinFlag; //�����־0:δ���� 1�������� 2���ɹ�����
	TCHAR            aszDispName[USERNAME_LEN]; //��������
	UINT16           wFactionNumberPeople; //���ɵ�ǰ����
	UINT16           wFactionMaxPeople; //������������
	DT_FACTION_DATA_TO_CLI stFactionBaseData; //������Ϣ
}DT_FACTION_BASE_DATA_CLI;

typedef struct tagDT_FACTION_BASE_DATA_CLI_LST{
	UINT16           wFactionNum; //���ɸ���
	DT_FACTION_BASE_DATA_CLI astFactionBaseData[MAX_FACTION_CLI_NUM]; //������Ϣ
}DT_FACTION_BASE_DATA_CLI_LST;

typedef struct tagDT_OPEN_FACTION_BASE_DATA{
	UINT32           dwCreateFactionCoin; //���ɻ��ѵ�ͭǮ��
	UINT32           dwCreateFactionGold; //���ɻ��ѵ��汦��
	DT_FACTION_BASE_DATA_CLI_LST stRankFactionBaseDataCliLst; //��������
}DT_OPEN_FACTION_BASE_DATA;

typedef struct tagDT_FACTION_PLAYER_CLI{
	UINT32           dwPlayerID; //���ID
	UINT16           wHeroKindID; //���佫ID
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT16           wLevel; //��ҵȼ�
	UINT16           wRank; //��Ҿ���������
	UINT8            byJobType; //ְҵ����
	UINT32           dwDoorsTributeValues; //ʣ�๱��
	UINT64           qwDoorsTributeSum; //�ۻ��Ź�
	UINT32           dwOffLineSeconds; //���߾����������� 0����ǰ���ߣ� > 0����
}DT_FACTION_PLAYER_CLI;

typedef struct tagDT_FACTION_PLAYER_CLI_LST{
	UINT16           wFactionNum; //���ɸ���
	DT_FACTION_PLAYER_CLI astFactionPlayerCli[DT_FACTION_PLAYER_NUM]; //������Ϣ
}DT_FACTION_PLAYER_CLI_LST;

typedef struct tagDT_FACTION_BASE_OWNER_DATA_CLI{
	DT_FACTION_BASE_DATA stFactionBaseData; //������Ϣ
	UINT16           wFactionNumberPeople; //������������
	UINT16           wMaxFactionNumberPeople; //�����������
	UINT32           dwFactionFunds; //�����ʽ�
	DT_FACTION_AUTHORITY stFactionAuthority; //����Ȩ����Ϣ
	TCHAR            aszHeadName[NORMAL_MSG_LEN]; //��������
	UINT32           dwMyDoorsTribute; //�ҵ��Ź�
	UINT64           qwMySumDoorsTribute; //�ҵ��ۻ��Ź�
	UINT8            byRecvFlag; //���콱��־ 0 �����콱�� 1���콱
}DT_FACTION_BASE_OWNER_DATA_CLI;

typedef struct tagDT_FACTION_OWNER_DATA{
	DT_FACTION_BASE_OWNER_DATA_CLI stFactionBaseData; //�������ɻ�����Ϣ
	DT_FACTION_PLAYER_CLI_LST stFactionPlayerCliLst; //���������Ϣ
	UINT8            byAuditNum; //�������
}DT_FACTION_OWNER_DATA;

typedef union tagDT_OPEN_FACTION_CONDITION{
	DT_OPEN_FACTION_BASE_DATA stOpenFactionBaseData; //�����ɻ�����Ϣ
	DT_FACTION_OWNER_DATA stFactionOwnerData; //���Ѽ����������Ϣ
}DT_OPEN_FACTION_CONDITION;

typedef struct tagPKT_CLIGS_APPLY_FACTION_REQ{
	tagPKT_CLIGS_APPLY_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_APPLY_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_APPLY_FACTION_REQ;

typedef struct tagPKT_CLIGS_APPLY_FACTION_ACK{
	tagPKT_CLIGS_APPLY_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_APPLY_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwFactionID; //����ID
	UINT32           dwJoinFactionCDTime; //��������CD
}PKT_CLIGS_APPLY_FACTION_ACK;

typedef struct tagPKT_CLIGS_CANCEL_APPLY_FACTION_REQ{
	tagPKT_CLIGS_CANCEL_APPLY_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CANCEL_APPLY_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_CANCEL_APPLY_FACTION_REQ;

typedef struct tagPKT_CLIGS_CANCEL_APPLY_FACTION_ACK{
	tagPKT_CLIGS_CANCEL_APPLY_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CANCEL_APPLY_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_CANCEL_APPLY_FACTION_ACK;

typedef struct tagPKT_CLIGS_CREATE_FACTION_REQ{
	tagPKT_CLIGS_CREATE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CREATE_FACTION_REQ)); }
	UINT16           wCreateFactionType; //����������������, 0��ͭǮ 1��Ԫ��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	TCHAR            aszFactionDescName[MAX_FACTION_DESC_NUM]; //��������
}PKT_CLIGS_CREATE_FACTION_REQ;

typedef struct tagPKT_CLIGS_CREATE_FACTION_ACK{
	tagPKT_CLIGS_CREATE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CREATE_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_OWNER_DATA stFactionOwnerData; //���Ѽ����������Ϣ
	UINT64           qwLeftTime; //�������ɵ�CDʱ��
}PKT_CLIGS_CREATE_FACTION_ACK;

typedef struct tagPKT_CLIGS_SEARCH_FACTION_REQ{
	tagPKT_CLIGS_SEARCH_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEARCH_FACTION_REQ)); }
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
}PKT_CLIGS_SEARCH_FACTION_REQ;

typedef struct tagPKT_CLIGS_SEARCH_FACTION_ACK{
	tagPKT_CLIGS_SEARCH_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SEARCH_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_BASE_DATA_CLI_LST stSearchFactionBaseDataCliLst; //��ѯ
}PKT_CLIGS_SEARCH_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_OWNER_FACTION_REQ{
	tagPKT_CLIGS_OPEN_OWNER_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_OWNER_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_OWNER_FACTION_REQ;

typedef struct tagDT_FACTION_PLAYER_AUDIT_CLI{
	UINT32           dwID; //���ΨһID
	UINT16           wHeroKindID; //���佫����
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT16           wLevel; //��ҵȼ�
	UINT32           dwRank; //����
	UINT32           dwPower; //ս��
	UINT32           dwFirstAttack; //�ȹ�ֵ
}DT_FACTION_PLAYER_AUDIT_CLI;

typedef struct tagDT_FACTION_PLAYER_AUDIT_CLI_LST{
	UINT16           wFactionNum; //���ɸ���
	DT_FACTION_PLAYER_AUDIT_CLI astFactionPlayerAuditCli[DT_FACTION_PLAYER_NUM]; //������Ϣ
}DT_FACTION_PLAYER_AUDIT_CLI_LST;

typedef struct tagPKT_CLIGS_OPEN_OWNER_FACTION_ACK{
	tagPKT_CLIGS_OPEN_OWNER_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_OWNER_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_OWNER_DATA stFactionOwnerData; //���Ѽ����������Ϣ
}PKT_CLIGS_OPEN_OWNER_FACTION_ACK;

typedef struct tagDT_ITEM_LIST_INFO{
	UINT8            byItemNum; //ͬ����Ʒ����
	DT_ITEM_DATA_CLI2 astItemInfo[MAX_ENCOURAGE_ITEM_KIND_NUM]; //��Ʒ��Ϣ
}DT_ITEM_LIST_INFO;

typedef struct tagPKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ{
	tagPKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ;

typedef struct tagDT_DOORS_TRIBUTE_BASE_DATA{
	UINT16           wCoinMaxTimeEveryDay; //ͭǮÿ��������ȡ�Ĵ���
	UINT32           dwCoinEveryTimeValues; //ͭǮÿ�ι���ֵ
	UINT32           dwCoinEveryTimeDoorsTributeValues; //ͭǮÿ���ܻ�õ��Ź�
	UINT32           dwCoinEveryTimeFundsValues; //ͭǮÿ���ܻ�õ������ʽ�
	UINT16           wGoldMaxTimeEveryDay; //Ԫ��ÿ��������ȡ�Ĵ���
	UINT32           dwGoldEveryTimeValues; //Ԫ��ÿ�ι���ֵ
	UINT32           dwGoldEveryTimeDoorsTributeValues; //Ԫ��ÿ���ܻ�õ��Ź�
	UINT32           dwGoldEveryTimeFundsValues; //Ԫ��ÿ���ܻ�õ������ʽ�
}DT_DOORS_TRIBUTE_BASE_DATA;

typedef struct tagDT_DOORS_TRIBUTE_TODAY_DATA{
	UINT8            byCoinRecvFlag; //��ȡ������־ 0������ȡ 1:����ȡ 2����ȡ��
	UINT16           wCoinTodaysDoorsTributeTimes; //����ͭǮ���״���
	UINT8            byGoldRecvFlag; //��ȡ������־ 1:����ȡ
	UINT16           wGoldTodaysDoorsTributeTimes; //����Ԫ�����״���
}DT_DOORS_TRIBUTE_TODAY_DATA;

typedef struct tagPKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK{
	tagPKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_DOORS_TRIBUTE_BASE_DATA stDoorsTributeBaseData; //�Ź�������Ϣ
	DT_ITEM_LIST_INFO stEncourageData; //������Ϣ
	DT_DOORS_TRIBUTE_TODAY_DATA stDoorsTributeTodayData; //���ͻ������ɹ��׵�����Ϣ
	UINT32           dwDoorsTribute; //��ҵ��Ź�ֵ
	UINT8            byCoinRequireTime; //����ٴο���ȡ����
}PKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK;

typedef struct tagPKT_CLIGS_DOORS_TRIBUTE_FACTION_REQ{
	tagPKT_CLIGS_DOORS_TRIBUTE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DOORS_TRIBUTE_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
	UINT32           dwDoorsTributeFlag; //��־0��ͭǮ��1��Ԫ��
}PKT_CLIGS_DOORS_TRIBUTE_FACTION_REQ;

typedef struct tagPKT_CLIGS_DOORS_TRIBUTE_FACTION_ACK{
	tagPKT_CLIGS_DOORS_TRIBUTE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DOORS_TRIBUTE_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_DOORS_TRIBUTE_BASE_DATA stDoorsTributeBaseData; //�Ź�������Ϣ
	DT_DOORS_TRIBUTE_TODAY_DATA stDoorsTributeTodayData; //���ͻ������ɹ��׵�����Ϣ
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	UINT32           dwDoorsTribute; //��ҵ��Ź�ֵ
	UINT32           dwFactionFunds; //�����ʽ�
	UINT8            byDoorsTributeFlag; //��־0��ͭǮ��1��Ԫ��
	UINT64           qwSumDoorsTribute; //����ۻ��Ź�
	UINT8            byNeedVIPLevel; //��Ҫ��VIP�ȼ���������ʱ��Ч��
}PKT_CLIGS_DOORS_TRIBUTE_FACTION_ACK;

typedef struct tagPKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ{
	tagPKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ)); }
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK{
	tagPKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_ITEM_LIST_INFO stRewardInfo; //������Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_KICKED_FACTION_REQ{
	tagPKT_CLIGS_KICKED_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_KICKED_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_KICKED_FACTION_REQ;

typedef struct tagPKT_CLIGS_KICKED_FACTION_ACK{
	tagPKT_CLIGS_KICKED_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_KICKED_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_PLAYER_CLI_LST stFactionPlayer; //����б�
	UINT16           wMaxPlayerNum; //������������
	DT_DOORSTRIBUTE_LEVE_DATA_LST stDoorsTributeLst; //���׶��б�
}PKT_CLIGS_KICKED_FACTION_ACK;

typedef struct tagPKT_CLIGS_JOB_FACTION_REQ{
	tagPKT_CLIGS_JOB_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JOB_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
	UINT32           dwPlayerID; //���ID
	UINT8            byFlag; //��־0����ְ1����ְ
}PKT_CLIGS_JOB_FACTION_REQ;

typedef struct tagPKT_CLIGS_JOB_FACTION_ACK{
	tagPKT_CLIGS_JOB_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JOB_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_PLAYER_CLI_LST stFactionPlayerDataLst; //���������Ϣ
	DT_DOORSTRIBUTE_LEVE_DATA_LST stDoorsTributeLst; //���׶��б�
}PKT_CLIGS_JOB_FACTION_ACK;

typedef struct tagPKT_CLIGS_SET_NOTICE_FACTION_REQ{
	tagPKT_CLIGS_SET_NOTICE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SET_NOTICE_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
	UINT8            byFlag; //��־0������1��֪ͨ
	TCHAR            aszFactionNotice[MAX_FACTION_DESC_NUM]; //����֪ͨ
}PKT_CLIGS_SET_NOTICE_FACTION_REQ;

typedef struct tagPKT_CLIGS_SET_NOTICE_FACTION_ACK{
	tagPKT_CLIGS_SET_NOTICE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SET_NOTICE_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFlag; //��־0������1��֪ͨ
	TCHAR            aszFactionNotice[MAX_FACTION_DESC_NUM]; //����֪ͨ
}PKT_CLIGS_SET_NOTICE_FACTION_ACK;

typedef struct tagPKT_CLIGS_DISSOLVE_FACTION_REQ{
	tagPKT_CLIGS_DISSOLVE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DISSOLVE_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_DISSOLVE_FACTION_REQ;

typedef struct tagPKT_CLIGS_DISSOLVE_FACTION_ACK{
	tagPKT_CLIGS_DISSOLVE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DISSOLVE_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_DISSOLVE_FACTION_ACK;

typedef struct tagDT_FACTION_AUDIT_PLAYER_DATA{
	UINT32           dwPlayerID; //�����û���Ϣ
	UINT8            byAuditFlag; //��־0�����ûͨ�� 1�����ͨ��
}DT_FACTION_AUDIT_PLAYER_DATA;

typedef struct tagPKT_CLIGS_AUDIT_FACTION_REQ{
	tagPKT_CLIGS_AUDIT_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_AUDIT_FACTION_REQ)); }
	UINT32           dwFactionID; //����ID
	UINT32           dwFactionNum; //�û���
	DT_FACTION_AUDIT_PLAYER_DATA astAuditPlayerData[DT_FACTION_PLAYER_NUM]; //�����û���Ϣ
}PKT_CLIGS_AUDIT_FACTION_REQ;

typedef struct tagPKT_CLIGS_AUDIT_FACTION_ACK{
	tagPKT_CLIGS_AUDIT_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_AUDIT_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwPassPlayerNum; //���ͨ������
	UINT32           dwNoPassPlayerNum; //��������
	UINT8            byLeftPlayerNum; //ʣ������
	UINT16           wCurPlayerNum; //���ɵ�ǰ����
	UINT16           wMaxPlayerNum; //������������
	DT_FACTION_PLAYER_AUDIT_CLI_LST stFactionPlayerAuditCliLst; //��������û���Ϣ
	UINT16           wLeftAuditNum; //ʣ��������� �����ڴ�����ʾ��
}PKT_CLIGS_AUDIT_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_APPLY_FACTION_REQ{
	tagPKT_CLIGS_OPEN_APPLY_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_APPLY_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_APPLY_FACTION_REQ;

typedef struct tagPKT_CLIGS_OPEN_APPLY_FACTION_ACK{
	tagPKT_CLIGS_OPEN_APPLY_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_APPLY_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_BASE_DATA_CLI_LST stApplyFactionBaseDataCliLst; //�����������
}PKT_CLIGS_OPEN_APPLY_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_RANK_FACTION_REQ{
	tagPKT_CLIGS_OPEN_RANK_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RANK_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_RANK_FACTION_REQ;

typedef struct tagPKT_CLIGS_OPEN_RANK_FACTION_ACK{
	tagPKT_CLIGS_OPEN_RANK_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RANK_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_BASE_DATA_CLI_LST stRankFactionBaseDataCliLst; //�����������
	UINT64           qwNeedGold; //������������Ԫ��
	UINT64           qwNeedCoin; //������������ͭǮ
}PKT_CLIGS_OPEN_RANK_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_AUDIT_FACTION_REQ{
	tagPKT_CLIGS_OPEN_AUDIT_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AUDIT_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_AUDIT_FACTION_REQ;

typedef struct tagPKT_CLIGS_OPEN_AUDIT_FACTION_ACK{
	tagPKT_CLIGS_OPEN_AUDIT_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AUDIT_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_PLAYER_AUDIT_CLI_LST stFactionPlayerAuditCliLst; //������������û���Ϣ
}PKT_CLIGS_OPEN_AUDIT_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_LOG_FACTION_REQ{
	tagPKT_CLIGS_OPEN_LOG_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_LOG_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_LOG_FACTION_REQ;

typedef struct tagDT_FACTION_LOG_DATA_CLI{
	TCHAR            aszDispName1[USERNAME_LEN]; //�������
	UINT8            byJobType1; //���ְλID
	TCHAR            aszDispName2[USERNAME_LEN]; //�������
	UINT8            byJobType2; //���ְλID
	UINT8            byAction; //�¼�ID
	UINT32           adwParamList[FACTION_LOG_LIST_MAX_NUM]; //��������
	UINT64           qwLogTime; //ʱ��
}DT_FACTION_LOG_DATA_CLI;

typedef struct tagDT_FACTION_LOG_DATA_CLI_LST{
	UINT16           wFactionLogNum; //������־����
	DT_FACTION_LOG_DATA_CLI astFactionLogDataCli[MAX_FACTION_LOG_NUM]; //������־��Ϣ
}DT_FACTION_LOG_DATA_CLI_LST;

typedef struct tagPKT_CLIGS_OPEN_LOG_FACTION_ACK{
	tagPKT_CLIGS_OPEN_LOG_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_LOG_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_LOG_DATA_CLI_LST stFactionLogDataCliLst; //������־��Ϣ
}PKT_CLIGS_OPEN_LOG_FACTION_ACK;

typedef struct tagDT_GATHER_SCIENCE_DATA_CLI{
	UINT64           qwCoinScience; //ͭǮȡ���������
	UINT16           wCoinMaxNum; //ͭǮ���ɾۻ����
	UINT16           wCoinNum; //ͭǮ��ǰʹ�þۻ����
	UINT32           dwCoinValues; //����ͭǮ
	UINT64           qwGoldScience; //Ԫ��ȡ���������
	UINT16           wGoldMaxNum; //Ԫ�����ɾۻ����
	UINT16           wGoldNum; //Ԫ����ǰʹ�þۻ����
	UINT32           dwGoldValues; //����Ԫ��
	UINT8            byIncrease; //����
	UINT8            abyIncrease[MAX_INCREASE]; //������Ϣ
}DT_GATHER_SCIENCE_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_GATHER_SCIENCE_REQ{
	tagPKT_CLIGS_OPEN_GATHER_SCIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GATHER_SCIENCE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_GATHER_SCIENCE_REQ;

typedef struct tagPKT_CLIGS_OPEN_GATHER_SCIENCE_ACK{
	tagPKT_CLIGS_OPEN_GATHER_SCIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GATHER_SCIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwScience; //������
	DT_GATHER_SCIENCE_DATA_CLI stGatherScience; //�ۻ������Ϣ
}PKT_CLIGS_OPEN_GATHER_SCIENCE_ACK;

typedef struct tagPKT_CLIGS_GATHER_SCIENCE_REQ{
	tagPKT_CLIGS_GATHER_SCIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GATHER_SCIENCE_REQ)); }
	UINT8            byGatherType; //�ۻ����� 0��ͭǮ 1��Ԫ��
}PKT_CLIGS_GATHER_SCIENCE_REQ;

typedef struct tagPKT_CLIGS_GATHER_SCIENCE_ACK{
	tagPKT_CLIGS_GATHER_SCIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GATHER_SCIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwScience; //������
	UINT64           qwGold; //Ԫ��
	UINT64           qwCoin; //ͭǮ
	DT_GATHER_SCIENCE_DATA_CLI stGatherScience; //�ۻ������Ϣ
}PKT_CLIGS_GATHER_SCIENCE_ACK;

typedef struct tagPKT_CLIGS_NOTICE_NTF{
	tagPKT_CLIGS_NOTICE_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_NOTICE_NTF)); }
	DT_NOTICE_DATA   stNoticeInfo; //������Ϣ
}PKT_CLIGS_NOTICE_NTF;

typedef struct tagPKT_CLIGS_NOTICE_NEW_NTF{
	tagPKT_CLIGS_NOTICE_NEW_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_NOTICE_NEW_NTF)); }
	DT_NOTICE_DATA_NEW stNoticeInfo; //������Ϣ
}PKT_CLIGS_NOTICE_NEW_NTF;

typedef struct tagPKT_CLIGS_ACTIVITY_ENC_NTF{
	tagPKT_CLIGS_ACTIVITY_ENC_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_ACTIVITY_ENC_NTF)); }
	UINT8            byEncNum; //���������
}PKT_CLIGS_ACTIVITY_ENC_NTF;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_TAB_REQ2{
	tagPKT_CLIGS_OPEN_AWAKEN_TAB_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_TAB_REQ2)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_AWAKEN_TAB_REQ2;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_TAB_ACK2{
	tagPKT_CLIGS_OPEN_AWAKEN_TAB_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_TAB_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_AWAKEN_TAB_DATA2 stAwakenInfo; //��������Ϣ
	UINT8            bySingleResolve; //�Ƿ���Էֽⵥ������ 0������ 1Ϊ����
	UINT8            byDoubleResolve; //�Ƿ���Էֽ�˫������ 0������ 1Ϊ����
}PKT_CLIGS_OPEN_AWAKEN_TAB_ACK2;

typedef struct tagPKT_CLIGS_AWAKEN_REQ2{
	tagPKT_CLIGS_AWAKEN_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_AWAKEN_REQ2)); }
	UINT8            byQuickFlag; //�Ƿ�ʹ��һ�������һ�����ʱԪ�������Ч
	UINT8            byGoldFlag; //�Ƿ�ʹ��Ԫ�����
}PKT_CLIGS_AWAKEN_REQ2;

typedef struct tagDT_AWAKEN_GET_DATA2{
	UINT32           dwGetCoin; //����ͭǮ
	UINT8            byStudyBagIdx; //�����ĵ����(��Ӧ�ĵñ�����ţ���0��ʼ)������ͭǮ/��ƬΪ0ʱ��Ч
	UINT8            byAwakenLevel; //����ȼ�
	UINT32           dwGetStudyClip; //�����ĵ���Ƭ
}DT_AWAKEN_GET_DATA2;

typedef struct tagPKT_CLIGS_AWAKEN_ACK2{
	tagPKT_CLIGS_AWAKEN_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_AWAKEN_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byQuickFlag; //�Ƿ�ʹ��һ�������һ�����ʱԪ�������Ч
	UINT8            byGoldFlag; //�Ƿ�ʹ��Ԫ�����
	UINT8            byAwakenNum; //�ܹ��������
	DT_AWAKEN_GET_DATA2 astAwakenGetInfo[MAX_AWAKEN_NUM]; //���������Ϣ
	DT_AWAKEN_TAB_DATA2 stAwakenTabInfo; //��������Ϣ
}PKT_CLIGS_AWAKEN_ACK2;

typedef struct tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ2{
	tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ2)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ2;

typedef struct tagDT_HERO_STUDY_DATA_CLI2{
	UINT16           wHeroID; //�佫ID
	DT_STUDY_DATA_CLI2 astStudyInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵ���Ϣ
}DT_HERO_STUDY_DATA_CLI2;

typedef struct tagDT_DRESS_STUDY_TAB_DATA2{
	DT_STUDY_DATA_CLI2 astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT16           awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵý����ȼ���Ϣ
	UINT8            byHeroNum; //�佫����
	DT_HERO_STUDY_DATA_CLI2 astHeroStudyInfo[MAX_FORMATION_IDX_NUM]; //�佫�ĵ���Ϣ
	UINT64           qwStudyExp; //�ĵþ���
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
}DT_DRESS_STUDY_TAB_DATA2;

typedef struct tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK2{
	tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_DRESS_STUDY_TAB_DATA2 stDressStudyTabInfo; //�����ĵ������Ϣ
}PKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK2;

typedef struct tagPKT_CLIGS_DRESS_STUDY_REQ2{
	tagPKT_CLIGS_DRESS_STUDY_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_STUDY_REQ2)); }
	UINT16           wHeroKindID; //�佫ID
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byHeroGridIdx; //�佫�ĵ�λ�ã���0��ʼ
}PKT_CLIGS_DRESS_STUDY_REQ2;

typedef struct tagPKT_CLIGS_DRESS_STUDY_ACK2{
	tagPKT_CLIGS_DRESS_STUDY_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_STUDY_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byHeroGridIdx; //�佫�ĵ�λ�ã���0��ʼ
	DT_STUDY_DATA_CLI2 astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	DT_HERO_STUDY_DATA_CLI2 stHeroStudyInfo; //�佫�ĵ���Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT8            byHaveSecondsUndress; //�Ƿ�ж2������1Ϊ��
	UINT8            byBagGridIdx2; //�ڶ���ж�µ������ŵı����ĵ�λ�ã���0��ʼ��HaveSecondsUndressΪ1��Ч
	UINT8            byHeroGridIdx2; //�佫�ڶ���ж�µ������ĵ�λ�ã���0��ʼ��HaveSecondsUndressΪ1��Ч
}PKT_CLIGS_DRESS_STUDY_ACK2;

typedef struct tagPKT_CLIGS_STUDY_TO_EXP_REQ2{
	tagPKT_CLIGS_STUDY_TO_EXP_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_TO_EXP_REQ2)); }
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byAllFlag; //ת�������ĵñ����е��ĵ�,1ת������
	UINT8            abySelectConvertColor[MAX_COLOR_NUM]; //ѡ��ת������ɫ(��Ӧ��ɫ�±�-1��0��ʾ��ת����1��ʾ��ת��)
}PKT_CLIGS_STUDY_TO_EXP_REQ2;

typedef struct tagPKT_CLIGS_STUDY_TO_EXP_ACK2{
	tagPKT_CLIGS_STUDY_TO_EXP_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_TO_EXP_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            abySelectConvertColor[MAX_COLOR_NUM]; //ת������ɫ(��Ӧ��ɫ�±�-1��0��ʾ��ת����1��ʾ��ת��)
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT8            byAllFlag; //ת�������ĵñ����е��ĵ�,1ת������
	UINT32           dwGenStudyExp; //ת�������ĵþ���
	DT_STUDY_DATA_CLI2 astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT64           qwCurStudyExp; //��ǰ�ĵþ���
}PKT_CLIGS_STUDY_TO_EXP_ACK2;

typedef struct tagPKT_CLIGS_STUDY_UPGRADE_REQ2{
	tagPKT_CLIGS_STUDY_UPGRADE_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_UPGRADE_REQ2)); }
	UINT16           wHeroKindID; //�佫ID
	UINT8            byGridIdx; //�ĵ�λ�ã���0��ʼ
	UINT8            byLevel; //Ҫ�������ĵȼ�
}PKT_CLIGS_STUDY_UPGRADE_REQ2;

typedef struct tagPKT_CLIGS_STUDY_UPGRADE_ACK2{
	tagPKT_CLIGS_STUDY_UPGRADE_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_UPGRADE_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID
	UINT8            byGridIdx; //�ĵ�λ�ã���0��ʼ
	UINT8            byLevel; //Ҫ�������ĵȼ�
	DT_HERO_STUDY_DATA_CLI2 stHeroStudyInfo; //�佫�ĵ���Ϣ
	UINT64           qwCurStudyExp; //��ǰ�ĵþ���
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_STUDY_UPGRADE_ACK2;

typedef struct tagDT_BEGBLUE_PLAYER_RES_CLI{
	UINT64           qwGold; //��ҵ�ǰԪ����
	UINT64           qwBlue; //��ҵ�ǰ��¶��
	UINT64           qwStory; //��ҵ�ǰ������
}DT_BEGBLUE_PLAYER_RES_CLI;

typedef struct tagDT_BEGBLUE_INFO_CLI{
	UINT32           dwMaxBegTimes; //�����������
	UINT32           dwLeftBegTimes; //ʣ���������
}DT_BEGBLUE_INFO_CLI;

typedef struct tagDT_IMPROVELUCK_INFO_CLI{
	UINT32           dwFreeImproveLuckMaxTimes; //������Ѹ��˴�������
	UINT32           dwLeftFreeImproveLuckTimes; //ʣ����Ѹ��˴���
	UINT32           dwGoldImproveLuckIdx; //�´�Ԫ���������(���ÿ������¶���´�����¶������)
	UINT32           dwNextImproveLuckGold; //�´θ����軨�ѵ�Ԫ��
}DT_IMPROVELUCK_INFO_CLI;

typedef struct tagDT_BEGBLUE_RES_DATA_CLI{
	UINT16           wSmileNum; //Ц������
	UINT32           dwBlueUnit; //������¶
	UINT32           dwStoryUnit; //��������
	UINT16           wXnMultiple; //����
	TCHAR            aszLuckPrompt[BEGBLUE_LUCK_PROMPT]; //������ʾ
}DT_BEGBLUE_RES_DATA_CLI;

typedef struct tagDT_BEGBLUE_RESULT_CLI{
	DT_BEGBLUE_INFO_CLI stBegBlueInfo; //����¶������Ϣ
	DT_IMPROVELUCK_INFO_CLI stImproveLuckInfo; //������Ϣ
	DT_BEGBLUE_RES_DATA_CLI stBegBlueResCli; //����õ�����Դ
}DT_BEGBLUE_RESULT_CLI;

typedef union tagDT_BLUE_PAVILION_UNION_DATA_CLI{
	DT_BEGBLUE_INFO_CLI stBegBlueInfo; //��ͨ��¶��
	DT_BEGBLUE_RESULT_CLI stBegBlueResult; //������������¶��
}DT_BLUE_PAVILION_UNION_DATA_CLI;

typedef struct tagDT_BLUE_PAVILION_DATA_CLI{
	UINT8            byBluePavilionType; //��¶������
	DT_BLUE_PAVILION_UNION_DATA_CLI stBluePavilionUnion; //��¶������
	TCHAR            aszClimbTowerPrompt[BEGBLUE_CLIMB_TOWER_PROMPT]; //������ʾ
}DT_BLUE_PAVILION_DATA_CLI;

typedef struct tagDT_BLUE_ENCOURAGEINFO{
	UINT32           dwBlue; //��¶
	UINT16           wSmileNum; //Ц������
}DT_BLUE_ENCOURAGEINFO;

typedef struct tagDT_BLUE_ENCOURAGEINFO_CLI{
	UINT16           wSmileNum; //�ۼ�Ц������
	UINT8            byGetAward; //�Ƿ������ȡ���� 0����á�����1��á�����2���ա���
	DT_BLUE_ENCOURAGEINFO stEncourageData; //��������
}DT_BLUE_ENCOURAGEINFO_CLI;

typedef struct tagPKT_CLIGS_OPEN_BLUE_PAVILION_REQ{
	tagPKT_CLIGS_OPEN_BLUE_PAVILION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BLUE_PAVILION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_BLUE_PAVILION_REQ;

typedef struct tagPKT_CLIGS_OPEN_BLUE_PAVILION_ACK{
	tagPKT_CLIGS_OPEN_BLUE_PAVILION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BLUE_PAVILION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BEGBLUE_PLAYER_RES_CLI stPlayerResInfo; //��ҵ�ǰ��Դ��Ϣ
	DT_BLUE_PAVILION_DATA_CLI stBluePavilion; //��¶������
	UINT8            byIsIgnoreXnMultiple; //�Ƿ��������¶����(0�����ԣ�1����)
	DT_BLUE_ENCOURAGEINFO_CLI stEncourage; //������Ϣ
}PKT_CLIGS_OPEN_BLUE_PAVILION_ACK;

typedef struct tagPKT_CLIGS_BEGBLUE_REQ{
	tagPKT_CLIGS_BEGBLUE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGBLUE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_BEGBLUE_REQ;

typedef struct tagPKT_CLIGS_BEGBLUE_ACK{
	tagPKT_CLIGS_BEGBLUE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGBLUE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BEGBLUE_RESULT_CLI stBegBlueResult; //����¶�����Ϣ
}PKT_CLIGS_BEGBLUE_ACK;

typedef struct tagPKT_CLIGS_IMPROVELUCK_REQ{
	tagPKT_CLIGS_IMPROVELUCK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_IMPROVELUCK_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_IMPROVELUCK_REQ;

typedef struct tagPKT_CLIGS_IMPROVELUCK_ACK{
	tagPKT_CLIGS_IMPROVELUCK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_IMPROVELUCK_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwGold; //��ҵ�ǰԪ����
	DT_BEGBLUE_RES_DATA_CLI stBegBlueResCli; //���˺�õ�����Դ
	DT_IMPROVELUCK_INFO_CLI stImproveLuckInfo; //������Ϣ
}PKT_CLIGS_IMPROVELUCK_ACK;

typedef struct tagPKT_CLIGS_COMFIRM_BEGBLUE_REQ{
	tagPKT_CLIGS_COMFIRM_BEGBLUE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COMFIRM_BEGBLUE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_COMFIRM_BEGBLUE_REQ;

typedef struct tagPKT_CLIGS_COMFIRM_BEGBLUE_ACK{
	tagPKT_CLIGS_COMFIRM_BEGBLUE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COMFIRM_BEGBLUE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BEGBLUE_PLAYER_RES_CLI stPlayerResInfo; //��ҵ�ǰ��Դ��Ϣ
	DT_BEGBLUE_INFO_CLI stBegBlueInfo; //����¶������Ϣ
	DT_BLUE_ENCOURAGEINFO_CLI stEncourage; //������Ϣ
}PKT_CLIGS_COMFIRM_BEGBLUE_ACK;

typedef struct tagPKT_CLIGS_GET_OPENLIGHT_INFO_REQ{
	tagPKT_CLIGS_GET_OPENLIGHT_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_OPENLIGHT_INFO_REQ)); }
	UINT16           wEquipKindID; //װ��ID
	UINT16           wEquipIdx; //װ�����
}PKT_CLIGS_GET_OPENLIGHT_INFO_REQ;

typedef struct tagPKT_CLIGS_GET_OPENLIGHT_INFO_ACK{
	tagPKT_CLIGS_GET_OPENLIGHT_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_OPENLIGHT_INFO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wEquipKindID; //װ��ID
	UINT16           wEquipIdx; //װ�����
	DT_EQUIP_DATA_CLI stAfterOpenLightInfo; //װ���������Ϣ
	UINT16           wOpenLightGoodsID; //��ǰ����ʯ��ƷID
	UINT16           wNeedOpenLightGoodsNum; //������Ҫ�Ŀ���ʯ��Ʒ����
	UINT16           wOpenLightGoodsNum; //��ǰ����ʯ��Ʒ����
	UINT8            byOpenLightRate; //����ɹ���
	UINT32           dwOpenLightGold; //����ɹ�Ԫ��
	DT_BATTLE_ATTRIBUTE stOldEquipInitBatlAttr; //��װ��0��ս������
	DT_BATTLE_ATTRIBUTE stNewEquipInitBatlAttr; //��װ��0��ս������
	DT_BATTLE_ATTRIBUTE stOldEquipCurrBatlAttr; //��װ����ǰս������
}PKT_CLIGS_GET_OPENLIGHT_INFO_ACK;

typedef struct tagPKT_CLIGS_OPENLIGHT_INFO_REQ{
	tagPKT_CLIGS_OPENLIGHT_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPENLIGHT_INFO_REQ)); }
	UINT16           wEquipKindID; //װ��ID
	UINT16           wEquipIdx; //װ�����
	UINT8            byGoldFlag; //Ԫ����־
}PKT_CLIGS_OPENLIGHT_INFO_REQ;

typedef struct tagPKT_CLIGS_OPENLIGHT_INFO_ACK{
	tagPKT_CLIGS_OPENLIGHT_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPENLIGHT_INFO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wEquipKindID; //װ��ID
	UINT16           wEquipIdx; //װ�����
	UINT8            byOpenLightFlagInfo; //װ�������־��Ϣ(0���ɿ��⣬1�ɿ��⣬2�ѿ���)
	UINT64           qwCurGold; //��ǰԪ��
	UINT16           wOpenLightGoodsID; //��ǰ�Ŀ���ʯ
	UINT16           wOpenLightGoodsNum; //��ǰ����ʯ��Ʒ����
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
}PKT_CLIGS_OPENLIGHT_INFO_ACK;

typedef struct tagPKT_CLIGS_CHANGE_CAREER_REQ{
	tagPKT_CLIGS_CHANGE_CAREER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_CAREER_REQ)); }
	UINT8            byCareerID; //ְҵID
}PKT_CLIGS_CHANGE_CAREER_REQ;

typedef struct tagPKT_CLIGS_CHANGE_CAREER_ACK{
	tagPKT_CLIGS_CHANGE_CAREER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_CAREER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byCareerID; //ְҵID
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_CHANGE_CAREER_ACK;

typedef struct tagPKT_CLIGS_CHALLENGE_MYSELF_REQ{
	tagPKT_CLIGS_CHALLENGE_MYSELF_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_MYSELF_REQ)); }
	UINT8            byCareerID; //ְҵID
}PKT_CLIGS_CHALLENGE_MYSELF_REQ;

typedef struct tagPKT_CLIGS_OPEN_ITEM_EXCHANGE_REQ{
	tagPKT_CLIGS_OPEN_ITEM_EXCHANGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ITEM_EXCHANGE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_ITEM_EXCHANGE_REQ;

typedef struct tagITEM_NUM_DATA{
	UINT16           wItemKindID; //����ID
	UINT16           wNeedNum; //�������
	UINT16           wCurNum; //��ǰ����
}ITEM_NUM_DATA;

typedef struct tagITEM_EXCHANGE_DATA{
	TCHAR            aszTitle[MAX_COMMON_TXT_NUM]; //����
	TCHAR            aszDscInfo[MAX_COMMON_TXT_NUM]; //����
	UINT16           wExchangeIdx; //�һ���
	UINT8            byNeedItemNum; //������
	ITEM_NUM_DATA    astNeedItemInfo[ITEM_EXCHANGE_ITEM_NUM]; //�һ���Ϣ
	UINT16           wExchangeItemKindID; //�ɶһ��ĵ���ID
	UINT16           wExchangeItemNum; //�ɶһ��ĵ�������
}ITEM_EXCHANGE_DATA;

typedef struct tagPKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK{
	tagPKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK)); }
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ
	UINT8            byExchangeNum; //�һ���
	ITEM_EXCHANGE_DATA astExchangeInfo[ITEM_EXCHANGE_ITEM_NUM]; //�һ���Ϣ
}PKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK;

typedef struct tagPKT_CLIGS_ITEM_EXCHANGE_REQ{
	tagPKT_CLIGS_ITEM_EXCHANGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ITEM_EXCHANGE_REQ)); }
	UINT16           wExchangeIdx; //�һ���
}PKT_CLIGS_ITEM_EXCHANGE_REQ;

typedef struct tagPKT_CLIGS_ITEM_EXCHANGE_ACK{
	tagPKT_CLIGS_ITEM_EXCHANGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ITEM_EXCHANGE_ACK)); }
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ
	DT_ITEM_DATA_CLI2 stExchangeItemInfo; //�һ����õĵ�����Ϣ
	UINT8            byExchangeNum; //�һ���
	ITEM_EXCHANGE_DATA astExchangeInfo[ITEM_EXCHANGE_ITEM_NUM]; //�һ���Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
}PKT_CLIGS_ITEM_EXCHANGE_ACK;

typedef struct tagDT_WANTED_INFO_CLI{
	UINT16           wWantedIndex; //ͨ�������
	TCHAR            aszWantedName[WANTED_DSPNAME_LEN]; //ͨ������
	TCHAR            aszWantedDesc[WANTED_DESC_LEN]; //ͨ��������
	UINT8            byWantedState; //״̬(1δ������2�ﱸ�У�3����ս��4�ѻ�ɱ)
	DT_TASK_ENCOURAGE_DATA stEncourage; //����
	UINT32           dwScoreThreshold; //�ɻ�ɱ������������ֵ
}DT_WANTED_INFO_CLI;

typedef struct tagDT_WANTED_LIST_CLI{
	UINT8            byWantedNum; //ͨ��������
	DT_WANTED_INFO_CLI astListData[MAX_WANTED_NUM]; //ͨ������Ϣ�б�
}DT_WANTED_LIST_CLI;

typedef struct tagPKT_CLIGS_OPEN_BIGREWARD_TAB_REQ{
	tagPKT_CLIGS_OPEN_BIGREWARD_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BIGREWARD_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_BIGREWARD_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_BIGREWARD_TAB_ACK{
	tagPKT_CLIGS_OPEN_BIGREWARD_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BIGREWARD_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	DT_WANTED_LIST_CLI stWantedList; //ͨ�����б�
	UINT32           dwCurClueScore; //��ǰ��������
	UINT32           dwHerosRecoverCD; //Ӣ�����˻ָ�CD(0��ʾû��CD, ������ֵ���Ǿ����CD)
}PKT_CLIGS_OPEN_BIGREWARD_TAB_ACK;

typedef struct tagDT_CLUE_TASK_INFO_CLI{
	UINT16           wIdx; //�б����
	UINT16           wClueTaskType; //������������
	UINT32           dwClueScore; //��������
	UINT8            byState; //�Ƿ�ѡ�й�(0δ��ѡ�й���1��ѡ�й�������ɣ�2��ѡ��δ���(���״ֻ̬���ܻ���������һ�����������״ֵ̬��))
}DT_CLUE_TASK_INFO_CLI;

typedef struct tagDT_CLUE_TASK_LIST_CLI{
	UINT32           dwClueTaskNum; //�������
	DT_CLUE_TASK_INFO_CLI astListData[MAX_CLUE_TASK_NUM]; //�б���Ϣ
}DT_CLUE_TASK_LIST_CLI;

typedef struct tagDT_CLUE_TASK_KILL_MONSTER_NAVI{
	TCHAR            aszDesc[CLUE_TASK_NAVI_DESC_LEN]; //����
	UINT16           wTargetNum; //��ɱ��Ŀ������
	UINT16           wKilledNum; //�ѻ�ɱ������
	DT_INSTANCE_ID   stInstanceID; //������Ϣ
	UINT32           dwClueScore; //�������ֽ���
	DT_TASK_ENCOURAGE_DATA stEncourage; //����(ͭǮ��Ԫ��������)
	UINT32           dwOnHookCoin; //������ɻ��ѵ�ͭǮ
}DT_CLUE_TASK_KILL_MONSTER_NAVI;

typedef struct tagDT_CLUE_TASK_ITEM_BOX_NAVI{
	TCHAR            aszDesc[CLUE_TASK_NAVI_DESC_LEN]; //����
	DT_ITEM_DATA_LIST_CLI stItemInfo; //����
}DT_CLUE_TASK_ITEM_BOX_NAVI;

typedef struct tagDT_CLUE_TASK_FORTUNE_GRID_NAVI{
	TCHAR            aszDesc[CLUE_TASK_NAVI_DESC_LEN]; //����
	UINT32           dwClueScore; //�������ֽ���
	DT_TASK_ENCOURAGE_DATA stEncourage; //����(ͭǮ��Ԫ��������)
	UINT16           wNextIdx; //��һ��ֱ��ǰ���ĸ���
}DT_CLUE_TASK_FORTUNE_GRID_NAVI;

typedef union tagDT_CLUE_TASK_NAVI_UNION{
	DT_CLUE_TASK_KILL_MONSTER_NAVI stKillMonster; //��ɱ��������
	DT_CLUE_TASK_ITEM_BOX_NAVI stItemBox; //���䵼������
	DT_CLUE_TASK_FORTUNE_GRID_NAVI stFortuneGrid; //���˸񵼺�����
}DT_CLUE_TASK_NAVI_UNION;

typedef struct tagDT_CLUE_TASK_NAVI_CLI{
	UINT8            byClueTaskType; //����
	DT_CLUE_TASK_NAVI_UNION stConcreteNavi; //�����������ĵ�����Ϣ����
}DT_CLUE_TASK_NAVI_CLI;

typedef struct tagDT_DICE_INFO_CLI{
	UINT16           wFreeShakeMaxTimes; //�������ҡ���Ӵ�������
	UINT16           wLeftFreeShakeTimes; //ʣ�����ҡ���Ӵ���
	UINT32           dwBuyShakeTimesGold; //�´ι���ҡ���ӵ�Ԫ��
	UINT16           wFreeRefreshMaxTimes; //�����ҡ��������
	UINT16           wLeftFreeRefreshTimes; //ʣ�����ҡ����
	UINT32           dwBuyRefreshTimesGold; //�´ι�����ҡ��Ԫ��
	UINT32           dwCheatDiceGold; //�´γ�ǧ��Ԫ��
	UINT8            byLastDicePoint; //���һ�����ӵ���
}DT_DICE_INFO_CLI;

typedef struct tagPKT_CLIGS_OPEN_COLLECT_CLUE_TAB_REQ{
	tagPKT_CLIGS_OPEN_COLLECT_CLUE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_COLLECT_CLUE_TAB_REQ)); }
	UINT16           wWantedIndex; //ͨ�������
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_COLLECT_CLUE_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_COLLECT_CLUE_TAB_ACK{
	tagPKT_CLIGS_OPEN_COLLECT_CLUE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_COLLECT_CLUE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT32           dwCurClueScore; //��ǰ��������
	DT_WANTED_INFO_CLI stCurWantedInfo; //��ǰͨ������Ϣ(����ӿ��в����������Ϣ��������ϢΪNULL)
	DT_CLUE_TASK_LIST_CLI stClueTaskList; //���������б�
	UINT16           wCurClueTaskIdx; //��ǰ��������ĸ������
	DT_DICE_INFO_CLI stDiceInfo; //������Ϣ
}PKT_CLIGS_OPEN_COLLECT_CLUE_TAB_ACK;

typedef struct tagPKT_CLIGS_OPEN_CLUE_GRID_REQ{
	tagPKT_CLIGS_OPEN_CLUE_GRID_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CLUE_GRID_REQ)); }
	UINT16           wIdx; //�б����
}PKT_CLIGS_OPEN_CLUE_GRID_REQ;

typedef struct tagPKT_CLIGS_OPEN_CLUE_GRID_ACK{
	tagPKT_CLIGS_OPEN_CLUE_GRID_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CLUE_GRID_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_CLUE_TASK_NAVI_CLI stClueTaskNavi; //�����������񵼺���Ϣ(����û����ɵĵ�����Ϣ������������Ϣ)
}PKT_CLIGS_OPEN_CLUE_GRID_ACK;

typedef struct tagPKT_CLIGS_SHAKE_DICE_REQ{
	tagPKT_CLIGS_SHAKE_DICE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SHAKE_DICE_REQ)); }
	UINT8            byCheatFlag; //��ǧ��ʶ(0����ǧ��n��ʶ��ǧָ���ĵ���)
}PKT_CLIGS_SHAKE_DICE_REQ;

typedef struct tagPKT_CLIGS_SHAKE_DICE_ACK{
	tagPKT_CLIGS_SHAKE_DICE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SHAKE_DICE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byDicePoint; //���ӵ���
	UINT16           wFreeShakeMaxTimes; //�������ҡ���Ӵ�������
	UINT16           wFreeShakeLeftTimes; //ʣ�����ҡ���Ӵ���
	UINT32           dwBuyShakeTimesGold; //�´ι���ҡ���ӵ�Ԫ��
	UINT32           dwCheatDiceGold; //�´γ�ǧ��Ԫ��
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
}PKT_CLIGS_SHAKE_DICE_ACK;

typedef struct tagPKT_CLIGS_REFRESH_DICE_REQ{
	tagPKT_CLIGS_REFRESH_DICE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REFRESH_DICE_REQ)); }
	UINT8            byCheatFlag; //��ǧ��ʶ(0����ǧ��n��ʶ��ǧָ���ĵ���)
}PKT_CLIGS_REFRESH_DICE_REQ;

typedef struct tagPKT_CLIGS_REFRESH_DICE_ACK{
	tagPKT_CLIGS_REFRESH_DICE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REFRESH_DICE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byDicePoint; //���ӵ���
	UINT16           wFreeRefreshMaxTimes; //�����ҡ��������
	UINT16           wLeftFreeRefreshTimes; //ʣ��������ҡ����
	UINT32           dwBuyRefreshTimesGold; //�´ι�����ҡ��Ԫ��
	UINT32           dwCheatDiceGold; //�´γ�ǧ��Ԫ��
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
}PKT_CLIGS_REFRESH_DICE_ACK;

typedef struct tagPKT_CLIGS_COMFIRM_DICE_POINT_REQ{
	tagPKT_CLIGS_COMFIRM_DICE_POINT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COMFIRM_DICE_POINT_REQ)); }
	UINT8            byDicePoint; //���ӵ���
}PKT_CLIGS_COMFIRM_DICE_POINT_REQ;

typedef struct tagPKT_CLIGS_COMFIRM_DICE_POINT_ACK{
	tagPKT_CLIGS_COMFIRM_DICE_POINT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COMFIRM_DICE_POINT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wDestClueTaskIdx; //ǰ������������ĸ������
}PKT_CLIGS_COMFIRM_DICE_POINT_ACK;

typedef struct tagPKT_CLIGS_PLAYER_RES_NTF{
	tagPKT_CLIGS_PLAYER_RES_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_RES_NTF)); }
	UINT8            byResNum; //��Դ��
	DT_PLAYER_RES_DATA astResInfo[MAX_PLAYER_RES_NUM]; //�佫��Ϣ
}PKT_CLIGS_PLAYER_RES_NTF;

typedef struct tagPKT_CLIGS_OPERATING_ACTIVITY_NTF{
	tagPKT_CLIGS_OPERATING_ACTIVITY_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_OPERATING_ACTIVITY_NTF)); }
	DT_OPERATING_ACTIVITY_DATA stOperatingActivityInfo; //��Ӫ���Ϣ
}PKT_CLIGS_OPERATING_ACTIVITY_NTF;

typedef struct tagPKT_CLIGS_OPERATING_ACTIVITY_BATTLE_REQ{
	tagPKT_CLIGS_OPERATING_ACTIVITY_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPERATING_ACTIVITY_BATTLE_REQ)); }
	TCHAR            aszBattleKey[MAX_COMMON_TXT_LEN]; //�����ս��ȷ�ϴ�
}PKT_CLIGS_OPERATING_ACTIVITY_BATTLE_REQ;

typedef struct tagDT_FRIEND_SYS_PLAYER_INFO{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszPlayerName[USERNAME_LEN]; //�������
	UINT16           wMainHeroKindID; //������ǽ�ɫID
	UINT8            byIsOnline; //�Ƿ�����
}DT_FRIEND_SYS_PLAYER_INFO;

typedef struct tagDT_FRIEND_SYS_PLAYER_LIST_CLI{
	UINT32           dwPlayerNum; //��Ҹ���
	DT_FRIEND_SYS_PLAYER_INFO astListData[MAX_FRIEND_SYS_PLAYER_LIST_ELEM_NUM]; //�б���Ϣ
}DT_FRIEND_SYS_PLAYER_LIST_CLI;

typedef struct tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ{
	tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ)); }
	UINT8            byGetListType; //��ȡ�б������(0����, 1İ����, 2������)
	UINT8            byPageCapacity; //ÿҳ����ʾ����
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
}PKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ;

typedef struct tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK{
	tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byGetListType; //��ȡ�б������(0����, 1İ����, 2������)
	UINT32           dwTotalNum; //ĳ�����б�����ܸ���
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
	DT_FRIEND_SYS_PLAYER_LIST_CLI stPlayerList; //����б�
}PKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK;

typedef struct tagDT_FRIEND_SYS_PLAYER_INFO2{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszPlayerName[USERNAME_LEN]; //�������
	UINT16           wMainHeroKindID; //������ǽ�ɫID
	UINT8            byIsOnline; //�Ƿ�����
	UINT8            byRelation; //��ҹ�ϵ
}DT_FRIEND_SYS_PLAYER_INFO2;

typedef struct tagDT_FRIEND_SYS_PLAYER_LIST_CLI2{
	UINT32           dwPlayerNum; //��Ҹ���
	DT_FRIEND_SYS_PLAYER_INFO2 astListData[MAX_FRIEND_SYS_PLAYER_LIST_ELEM_NUM]; //�б���Ϣ
}DT_FRIEND_SYS_PLAYER_LIST_CLI2;

typedef struct tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2{
	tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2)); }
	UINT8            byGetListType; //��ȡ�б������(0����, 1İ����, 2������)
	UINT8            byPageCapacity; //ÿҳ����ʾ����
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
}PKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2;

typedef struct tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2{
	tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byGetListType; //��ȡ�б������(0����, 1İ����, 2������)
	UINT32           dwTotalNum; //ĳ�����б�����ܸ���
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
	DT_FRIEND_SYS_PLAYER_LIST_CLI2 stPlayerList; //����б�
}PKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2;

typedef struct tagPKT_CLIGS_DEL_FRIEND_REQ{
	tagPKT_CLIGS_DEL_FRIEND_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DEL_FRIEND_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_DEL_FRIEND_REQ;

typedef struct tagPKT_CLIGS_DEL_FRIEND_ACK{
	tagPKT_CLIGS_DEL_FRIEND_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DEL_FRIEND_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_DEL_FRIEND_ACK;

typedef struct tagPKT_CLIGS_SEARCH_PLAYER_REQ{
	tagPKT_CLIGS_SEARCH_PLAYER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEARCH_PLAYER_REQ)); }
	TCHAR            aszPlayerName[USERNAME_LEN]; //�������
	UINT8            byPageCapacity; //ÿҳ����ʾ����
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
}PKT_CLIGS_SEARCH_PLAYER_REQ;

typedef struct tagPKT_CLIGS_SEARCH_PLAYER_ACK{
	tagPKT_CLIGS_SEARCH_PLAYER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SEARCH_PLAYER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwTotalNum; //�б�����ܸ���
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
	DT_FRIEND_SYS_PLAYER_LIST_CLI stSearchRltList; //��������б�
}PKT_CLIGS_SEARCH_PLAYER_ACK;

typedef struct tagPKT_CLIGS_SEARCH_PLAYER_REQ2{
	tagPKT_CLIGS_SEARCH_PLAYER_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_SEARCH_PLAYER_REQ2)); }
	TCHAR            aszPlayerName[USERNAME_LEN]; //�������
	UINT8            byPageCapacity; //ÿҳ����ʾ����
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
}PKT_CLIGS_SEARCH_PLAYER_REQ2;

typedef struct tagPKT_CLIGS_SEARCH_PLAYER_ACK2{
	tagPKT_CLIGS_SEARCH_PLAYER_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_SEARCH_PLAYER_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwTotalNum; //�б�����ܸ���
	UINT8            byPageNo; //��ѯ��ҳ��(��1��ʼ)
	DT_FRIEND_SYS_PLAYER_LIST_CLI2 stSearchRltList; //��������б�
}PKT_CLIGS_SEARCH_PLAYER_ACK2;

typedef struct tagDT_FRIEND_SYS_PLAYER_GENERAL_INFO_CLI{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszPlayerName[USERNAME_LEN]; //�������
	UINT16           wMainHeroKindID; //������ǽ�ɫID
	UINT16           wPlayerLvl; //��ҵȼ�
	UINT32           dwPlayerPower; //���ս��
	UINT64           qwFlowerSum; //����ʻ�����
	UINT8            byRelationType; //��ϵ����(0����, 1İ����, 2������)
	UINT32           dwRank; //��Ҿ�������
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT8            byVipLevel; //VIP�ȼ�
}DT_FRIEND_SYS_PLAYER_GENERAL_INFO_CLI;

typedef struct tagPKT_CLIGS_VIEW_PLAYER_REQ{
	tagPKT_CLIGS_VIEW_PLAYER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_VIEW_PLAYER_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_VIEW_PLAYER_REQ;

typedef struct tagDT_HERO_ATTR_LST_INFO{
	UINT16           wHeroNum; //������
	UINT16           awHeroID[MAX_HERO_NUM]; //���ID
	UINT16           awTalent[MAX_HERO_NUM]; //����
	DT_BATTLE_ATTRIBUTE2 astBaseAttr[MAX_HERO_NUM]; //��������
	DT_HIDE_BATTLE_ATTRIBUTE astHideAttr[MAX_HERO_NUM]; //��������
	UINT32           adwPower[MAX_HERO_NUM]; //ս����
	UINT16           awLevel[MAX_HERO_NUM]; //�ȼ�
}DT_HERO_ATTR_LST_INFO;

typedef struct tagDT_SPECIAL_EFFECT_DESC{
	UINT8            byEffectType; //��Ч����
	UINT16           wTriggerProbValue; //�������ʵȼ�
	UINT16           wEffectPercentValue; //Ч���ٷֱȵȼ�
	UINT16           wLimitNumValue; //���ƴ����ȼ�
}DT_SPECIAL_EFFECT_DESC;

typedef struct tagDT_SPECIAL_EFFECT_LST_DESC{
	UINT8            byDescNum; //��������
	DT_SPECIAL_EFFECT_DESC astSkillDesc[MAX_SKILL_SOUL_NUM]; //����
}DT_SPECIAL_EFFECT_LST_DESC;

typedef struct tagDT_SPECIAL_EFFECT_DATA_CLI{
	UINT16           wEffectID; //��ЧID
	TCHAR            aszEffectName[MAX_NAME_LEN]; //��Ч��������
	UINT8            byIsActivity; //�Ƿ񼤻�
	UINT8            byUnlockLevel; //��Ч���������ȼ�
	DT_SPECIAL_EFFECT_LST_DESC stSkillLstDesc; //����
}DT_SPECIAL_EFFECT_DATA_CLI;

typedef struct tagDT_SOUL_ATTR_DATA_CLI{
	UINT8            byKindID; //����ID
	UINT32           dwKindValue; //����ֵ
	UINT32           dwKindPercent; //���԰ٷֱ�
}DT_SOUL_ATTR_DATA_CLI;

typedef struct tagDT_SOUL_DATA_CLI{
	UINT16           wSoulID; //ս��ID
	UINT32           dwSoulIdx; //ս��Idx(����ͬ��ս��)
	UINT8            bySoulStar; //ս���Ǽ�
	UINT8            bySoulType; //ս������ 1�������� 2���������
	UINT8            bySoulLevel; //ս��ȼ�
	UINT32           dwSoulExperience; //ս�꾭��
	UINT32           dwMaxExperience; //��ǰ����������
	UINT32           dwReturnExperience; //��������
	UINT8            byIsNormalSoul; //0 �������ɻ� 1 ������ͨ��
	UINT8            byBaseNum; //ս��������Ը���
	DT_SOUL_ATTR_DATA_CLI astSoulAttr[MAX_SOUL_ATTR_NUM]; //ս������
	UINT8            byBaseAfterNum; //ս��������Ը���(ϴ����)
	DT_SOUL_ATTR_DATA_CLI astSoulAfterAttr[MAX_SOUL_ATTR_NUM]; //ս������(ϴ����)
	TCHAR            aszSoulName[MAX_SOUL_NAME_LEN]; //ս������
	TCHAR            aszSoulPic[MAX_SOUL_PIC_LEN]; //ս��ͼƬ����
	DT_SPECIAL_EFFECT_DATA_CLI stSpecialEffect; //���⼼��
	TCHAR            aszNamePic[MAX_SOUL_PIC_LEN]; //ս������ͼƬ����
	UINT8            abySoulAttrLock[MAX_SOUL_ATTR_NUM]; //������
}DT_SOUL_DATA_CLI;

typedef struct tagDT_SOUL_POTENCY_CLI{
	UINT8            byPotencyLevel; //Ǳ�ܵȽ�
	UINT8            byPotencySubLevel; //Ǳ�ܵȼ�
}DT_SOUL_POTENCY_CLI;

typedef struct tagDT_SOUL_DATA_LST_CLI{
	UINT16           wSoulNum; //ս�����
	DT_SOUL_DATA_CLI astSoulLstData[MAX_SOUL_BAG_NUM]; //ս����Ϣ
}DT_SOUL_DATA_LST_CLI;

typedef struct tagDT_SOUL_POTENCY_DATA_LST_CLI{
	UINT16           wSoulNum; //ս�����
	DT_SOUL_POTENCY_CLI astSoulLstData[MAX_SOUL_BAG_NUM]; //ս����Ϣ
}DT_SOUL_POTENCY_DATA_LST_CLI;

typedef struct tagDT_HERO_SOUL_DATA_LST_CLI{
	UINT16           wSoulEquipNum; //װ��ս�����
	DT_SOUL_DATA_CLI astSoulEquipLstData[MAX_SOUL_EQUIP_NUM]; //װ��ս����Ϣ
}DT_HERO_SOUL_DATA_LST_CLI;

typedef struct tagDT_HERO_SOUL_POTENCY_DATA_LST_CLI{
	UINT16           wSoulEquipNum; //װ��ս�����
	DT_SOUL_POTENCY_CLI astSoulEquipLstData[MAX_SOUL_EQUIP_NUM]; //װ��ս����Ϣ
}DT_HERO_SOUL_POTENCY_DATA_LST_CLI;

typedef struct tagDT_HERO_LST_SOUL_POTENCY_DATA_LST_CLI{
	UINT16           wHeroNum; //Ӣ�۸���
	DT_HERO_SOUL_POTENCY_DATA_LST_CLI astSoulEquipLstData[MAX_HERO_NUM]; //ս����Ϣ
}DT_HERO_LST_SOUL_POTENCY_DATA_LST_CLI;

typedef struct tagDT_ATTR_BASE_DATA{
	UINT8            byKindID; //����ID
	UINT32           dwAttrValue; //����ֵ
	UINT8            byValueType; //����ֵ���ͣ�1�̶�ֵ�� 2�ٷ������ο�commondef.h ValueType
}DT_ATTR_BASE_DATA;

typedef struct tagDT_ATTR_BASE_LST_DATA{
	UINT8            byAttrNum; //���Ը���
	DT_ATTR_BASE_DATA astAttrInfo[MAX_SCIENCE_ATTR_NUM]; //����ֵ
}DT_ATTR_BASE_LST_DATA;

typedef struct tagDT_MEDAL_DATA_CLI{
	TCHAR            aszMedalName[MAX_NAME_LEN]; //ѫ������
	TCHAR            aszMedalIconName[MAX_NAME_LEN]; //ѫ������
	TCHAR            aszFinishDesc[MAX_MEDAL_DESC_LEN]; //ѫ���������
	UINT8            byIsActivate; //ѫ�¼���״̬
	DT_ATTR_BASE_LST_DATA stCurAttrInfo; //ѫ�µ�ǰ����
	DT_ATTR_BASE_LST_DATA stNextAttrInfo; //ѫ����һ������
	UINT16           wMedalLevel; //ѫ�µȼ�
	UINT64           qwValidityTime; //ѫ����Ч��
	UINT64           qwOverTime; //ѫ�¹���ʱ��
	UINT8            byMedalType; //ѫ�����
	UINT16           wSmallType; //ѫ���������(����С�������У��ɲ�����)
	UINT8            byMedalColor; //������ɫ
	UINT8            byIsLevelMedal; //�Ƿ��ǵȼ�ѫ��
}DT_MEDAL_DATA_CLI;

typedef struct tagDT_MEDAL_DATA_LST_CLI{
	UINT16           wMedalNum; //ѫ�¸���
	DT_MEDAL_DATA_CLI astMedalInfo[MAX_MEDAL_NUM]; //ѫ����Ϣ
}DT_MEDAL_DATA_LST_CLI;

typedef struct tagPKT_CLIGS_VIEW_PLAYER_ACK{
	tagPKT_CLIGS_VIEW_PLAYER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_VIEW_PLAYER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FRIEND_SYS_PLAYER_GENERAL_INFO_CLI stPlayerGeneralInfo; //��Ҹ�Ҫ��Ϣ
	UINT8            byFactionIconID; //��ǰ����ͷ��ID
	DT_HERO_ATTR_LST_INFO stAttrInfo; //������Ϣ
	UINT8            byJewelryOpen; //��Ʒ����״̬��0δ���ţ� 1���ţ�
	UINT8            byGodWeaponOpen; //��������״̬��0δ���ţ� 1���ţ�
	UINT8            byAwakenOpen; //���󿪷�״̬��0δ���ţ� 1���ţ�
	UINT8            bySoulOpen; //ս�꿪��״̬��0δ���ţ� 1���ţ�
	UINT16           wHeroNum; //������
	UINT8            abyJobType[MAX_HERO_NUM]; //ְҵ����
	DT_MEDAL_DATA_LST_CLI stMedalInfo; //���ѫ��
	UINT8            byPetOpen; //���￪��״̬��0δ���ţ� 1���ţ�
}PKT_CLIGS_VIEW_PLAYER_ACK;

typedef struct tagPKT_CLIGS_ADD_FRIEND_REQ{
	tagPKT_CLIGS_ADD_FRIEND_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ADD_FRIEND_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_ADD_FRIEND_REQ;

typedef struct tagPKT_CLIGS_ADD_FRIEND_ACK{
	tagPKT_CLIGS_ADD_FRIEND_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ADD_FRIEND_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_ADD_FRIEND_ACK;

typedef struct tagDT_SEND_FLOWER_PROP_INFO{
	UINT32           dwFlowerNum; //�ʻ���
	UINT32           dwCoin; //���ѵ�ͭǮ
	UINT32           dwGold; //���ѵ�Ԫ��
	UINT16           wGoodsKindID; //�õ�����ƷKindID
	UINT32           dwGoodsNum; //�õ�����Ʒ����
	UINT32           dwLeftSendTimes; //ʣ�����ʹ���
	UINT8            byNeedVipLvl; //��Ҫ��VIP�ȼ�(0��ʾ����ҪVIP�ȼ�)
}DT_SEND_FLOWER_PROP_INFO;

typedef struct tagDT_SEND_FLOWER_PROP_LIST_CLI{
	UINT32           dwPropNum; //���ø���
	DT_SEND_FLOWER_PROP_INFO astListData[MAX_SEND_FLOWER_PROP_NUM]; //�б���Ϣ
}DT_SEND_FLOWER_PROP_LIST_CLI;

typedef struct tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_REQ{
	tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
	UINT32           dwRecvPlayerID; //�ջ����ID
}PKT_CLIGS_OPEN_SEND_FLOWER_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_ACK{
	tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_SEND_FLOWER_PROP_LIST_CLI stSendFlowerPropList; //���ʻ�������Ϣ�б�
}PKT_CLIGS_OPEN_SEND_FLOWER_TAB_ACK;

typedef struct tagPKT_CLIGS_SEND_FLOWER_REQ{
	tagPKT_CLIGS_SEND_FLOWER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEND_FLOWER_REQ)); }
	UINT32           dwRecvPlayerID; //�ջ����ID
	UINT32           dwSendFlowerNum; //�ͻ�������
}PKT_CLIGS_SEND_FLOWER_REQ;

typedef struct tagPKT_CLIGS_SEND_FLOWER_ACK{
	tagPKT_CLIGS_SEND_FLOWER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SEND_FLOWER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurCoin; //��ǰ��ͭǮ
	UINT64           qwCurGold; //��ǰ��Ԫ��
	UINT16           wGoodsKindID; //�õ�����ƷKindID
	UINT64           qwCurGoodsNum; //��ǰ����Ʒ����
	UINT64           qwRecverFlowerSum; //�շ����ʻ�����
}PKT_CLIGS_SEND_FLOWER_ACK;

typedef struct tagDT_RECV_FLOWER_LOG{
	UINT32           dwSendPlayerID; //�ͻ������ID
	TCHAR            aszSendPlayerName[USERNAME_LEN]; //�ͻ����������
	UINT32           dwFlowerNum; //�ʻ���
	UINT64           qwSendTime; //�ͻ���ʱ��
}DT_RECV_FLOWER_LOG;

typedef struct tagDT_RECV_FLOWER_LOG_LIST_CLI{
	UINT32           dwLogNum; //��¼����
	DT_RECV_FLOWER_LOG astListData[MAX_RECV_FLOWER_LOG_LIST_ELEM_NUM]; //�б���Ϣ
}DT_RECV_FLOWER_LOG_LIST_CLI;

typedef struct tagPKT_CLIGS_GET_FLOWER_BY_PLAYERID_REQ{
	tagPKT_CLIGS_GET_FLOWER_BY_PLAYERID_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FLOWER_BY_PLAYERID_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_GET_FLOWER_BY_PLAYERID_REQ;

typedef struct tagPKT_CLIGS_GET_FLOWER_BY_PLAYERID_ACK{
	tagPKT_CLIGS_GET_FLOWER_BY_PLAYERID_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FLOWER_BY_PLAYERID_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwFlowerSum; //�ҵ��ʻ�����
	UINT32           dwMyFlowerRanking; //�ҵ��ʻ�������
	DT_RECV_FLOWER_LOG_LIST_CLI stRecvFlowerLogList; //�ջ���¼
}PKT_CLIGS_GET_FLOWER_BY_PLAYERID_ACK;

typedef struct tagDT_FLOWER_RANKING_INFO{
	UINT32           dwPlayerID; //�ͻ������ID
	TCHAR            aszPlayerName[USERNAME_LEN]; //�ͻ����������
	UINT64           qwFlowerSum; //�ʻ���
	UINT32           dwFlowerRanking; //�ʻ�����
}DT_FLOWER_RANKING_INFO;

typedef struct tagDT_FLOWER_RANKING_LIST_CLI{
	UINT32           dwRankingNum; //���и���
	DT_FLOWER_RANKING_INFO astListData[MAX_FLOWER_RANKING_LIST_ELEM_NUM]; //�б���Ϣ
}DT_FLOWER_RANKING_LIST_CLI;

typedef struct tagPKT_CLIGS_GET_FLOWER_RANKING_REQ{
	tagPKT_CLIGS_GET_FLOWER_RANKING_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FLOWER_RANKING_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_FLOWER_RANKING_REQ;

typedef struct tagPKT_CLIGS_GET_FLOWER_RANKING_ACK{
	tagPKT_CLIGS_GET_FLOWER_RANKING_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_FLOWER_RANKING_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FLOWER_RANKING_LIST_CLI stFlowerRankingList; //��չ�ֶ�
}PKT_CLIGS_GET_FLOWER_RANKING_ACK;

typedef struct tagDT_PRIVATE_MSG_DATA{
	UINT32           dwMsgIdx; //��Ϣ���(Խ�����Ϣ��MsgIdxԽС)
	TCHAR            aszMsgContent[PRIVATE_MSG_CONTENT_LEN]; //˽����Ϣ����
	UINT8            byIsRecv; //�շ���ʶ(0���Լ������ģ�1��Է���������)
	UINT64           qwSendTime; //�ͻ���ʱ��
}DT_PRIVATE_MSG_DATA;

typedef struct tagDT_PRIVATE_MSG_LIST_CLI{
	UINT32           dwMsgNum; //��Ϣ����
	DT_PRIVATE_MSG_DATA astListData[MAX_PRIVATE_MSG_LIST_ELEM_NUM]; //�б���Ϣ
}DT_PRIVATE_MSG_LIST_CLI;

typedef struct tagPKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ{
	tagPKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ)); }
	UINT32           dwPlayerID; //���ID
	UINT32           dwStartIdx; //��ʼ���
	UINT8            byGetMsgNum; //��ȡ��Ϣ����(���С����ŷ���ȡ)
}PKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ;

typedef struct tagPKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK{
	tagPKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwTotalNum; //��Ϣ������
	UINT32           dwStartIdx; //����ʱ����ʼ���
	DT_PRIVATE_MSG_LIST_CLI stPrivateMsgList; //˽����Ϣ��¼�б�
	UINT8            byPeerRole; //�Է���ʲô��ɫ����ͨ���0 / GM 1����:PrivateChatRoleType
}PKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK;

typedef struct tagPKT_CLIGS_SEND_PRIVATE_MSG_REQ{
	tagPKT_CLIGS_SEND_PRIVATE_MSG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEND_PRIVATE_MSG_REQ)); }
	UINT32           dwRecvPlayerID; //�շ����ID
	TCHAR            aszMsgContent[PRIVATE_MSG_CONTENT_LEN]; //˽����Ϣ����
}PKT_CLIGS_SEND_PRIVATE_MSG_REQ;

typedef struct tagPKT_CLIGS_SEND_PRIVATE_MSG_ACK{
	tagPKT_CLIGS_SEND_PRIVATE_MSG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SEND_PRIVATE_MSG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	TCHAR            aszErrInfo[MAX_COMMON_TXT_NUM]; //������Ϣ(��ֵ����������ڴ�����)
}PKT_CLIGS_SEND_PRIVATE_MSG_ACK;

typedef struct tagPKT_CLIGS_DEL_PRIVATE_MSG_LOG_REQ{
	tagPKT_CLIGS_DEL_PRIVATE_MSG_LOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DEL_PRIVATE_MSG_LOG_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_DEL_PRIVATE_MSG_LOG_REQ;

typedef struct tagPKT_CLIGS_DEL_PRIVATE_MSG_LOG_ACK{
	tagPKT_CLIGS_DEL_PRIVATE_MSG_LOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DEL_PRIVATE_MSG_LOG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_DEL_PRIVATE_MSG_LOG_ACK;

typedef struct tagPKT_CLIGS_ADD_TO_BLACKLIST_REQ{
	tagPKT_CLIGS_ADD_TO_BLACKLIST_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ADD_TO_BLACKLIST_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_ADD_TO_BLACKLIST_REQ;

typedef struct tagPKT_CLIGS_ADD_TO_BLACKLIST_ACK{
	tagPKT_CLIGS_ADD_TO_BLACKLIST_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ADD_TO_BLACKLIST_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_ADD_TO_BLACKLIST_ACK;

typedef struct tagPKT_CLIGS_MOVE_FROM_BLACKLIST_REQ{
	tagPKT_CLIGS_MOVE_FROM_BLACKLIST_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MOVE_FROM_BLACKLIST_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_MOVE_FROM_BLACKLIST_REQ;

typedef struct tagPKT_CLIGS_MOVE_FROM_BLACKLIST_ACK{
	tagPKT_CLIGS_MOVE_FROM_BLACKLIST_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MOVE_FROM_BLACKLIST_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_MOVE_FROM_BLACKLIST_ACK;

typedef struct tagPKT_CLIGS_ONLINE_PRIVATE_MSG_NTF{
	tagPKT_CLIGS_ONLINE_PRIVATE_MSG_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_ONLINE_PRIVATE_MSG_NTF)); }
	UINT32           dwMsgIdx; //��Ϣ���(Խ�����Ϣ��MsgIdxԽС)
	UINT32           dwSendPlayerID; //�������ID
	TCHAR            aszSendPlayerName[USERNAME_LEN]; //�����������
	UINT16           wMainHeroKindID; //������ǽ�ɫID
	UINT8            byRelationType; //��ϵ����(0����, 1İ����, 2������,100��Ӻ���֪ͨ)
	TCHAR            aszMsgContent[PRIVATE_MSG_CONTENT_LEN]; //˽����Ϣ����
	UINT64           qwSendTime; //����ʱ��
}PKT_CLIGS_ONLINE_PRIVATE_MSG_NTF;

typedef struct tagDT_OFFLINE_MSG_SENDER_INFO{
	UINT32           dwSendPlayerID; //�������ID
	TCHAR            aszSendPlayerName[USERNAME_LEN]; //�����������
	UINT16           wMainHeroKindID; //������ǽ�ɫID
	UINT8            byRelationType; //��ϵ����(0����, 1İ����, 2������,100��Ӻ�������֪ͨ)
	UINT16           wOfflineMsgCnt; //˽����Ϣ����
}DT_OFFLINE_MSG_SENDER_INFO;

typedef struct tagDT_SEND_OFFLINE_MSG_PLAYER_LIST_CLI{
	UINT32           dwPlayerNum; //��Ҹ���
	DT_OFFLINE_MSG_SENDER_INFO astListData[MAX_SEND_OFFLINE_MSG_PLAYER_LIST_ELEM_NUM]; //�б���Ϣ
}DT_SEND_OFFLINE_MSG_PLAYER_LIST_CLI;

typedef struct tagPKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ{
	tagPKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ;

typedef struct tagPKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK{
	tagPKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_SEND_OFFLINE_MSG_PLAYER_LIST_CLI stPlayerList; //��������Ϣ������б�
}PKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK;

typedef struct tagPKT_CLIGS_READ_OFFLINE_MSG_REQ{
	tagPKT_CLIGS_READ_OFFLINE_MSG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_READ_OFFLINE_MSG_REQ)); }
	UINT32           dwSendPlayerID; //�������ID
}PKT_CLIGS_READ_OFFLINE_MSG_REQ;

typedef struct tagPKT_CLIGS_READ_OFFLINE_MSG_ACK{
	tagPKT_CLIGS_READ_OFFLINE_MSG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_READ_OFFLINE_MSG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_READ_OFFLINE_MSG_ACK;

typedef struct tagDT_RAREITEM_INFO_CLI{
	UINT8            byRareItemType; //��Ʒ����(��װ��,��ҩƷ��3��Դ��4���ߣ�5����)
	DT_ITEM_DATA_CLI2 stRareItemInfo; //��Ʒ��Ϣ
	UINT8            byRareItemExchangeRule; //��Ʒ�һ�����(1���� 2���� 3���� 4����)
	UINT32           dwRareItemSumRequire; //�ۻ��Ź�Ҫ��
	UINT32           dwRareItemExchangeMoney; //��Ʒ�һ��Ź�����
	UINT32           dwRareItemLeftExchange; //��Ʒ�һ�ʣ�����
	UINT8            byIsUnLock; //�Ƿ����0δ���� , 1������
	UINT8            byUnlockLevel; //�����ȼ�
	UINT8            byDoorsTributeEnough; //ʣ���Ź����㣨0 �����㣬 1���㣩
	UINT8            bySumDoorsTributeEnough; //�ۻ��Ź����㣨0 �����㣬 1���㣩
	UINT8            byBuyNeedLevel; //����ȼ���0û�еȼ�Ҫ��
	UINT8            byNeedLeveEnough; //����ȼ����㣨0 �����㣬 1���㣩
}DT_RAREITEM_INFO_CLI;

typedef struct tagDT_RAREITEM_INFO_LIST_CLI{
	UINT8            byRareItemNum; //��Ʒ����
	DT_RAREITEM_INFO_CLI astRareItemInfoList[MAX_RAREITEM_RES_NUM]; //��Ʒ����
}DT_RAREITEM_INFO_LIST_CLI;

typedef struct tagDT_RAREITEM_ROOM_INFO_CLI{
	UINT32           dwRemainMoney; //����ʣ���Ź�
	UINT64           qwAccumulateMoney; //�����ۻ��Ź�
	UINT8            byRareItemGrade; //��Ʒ��ȼ���Ϣ
	UINT8            byUpgradeLimit; //-����Ȩ��
}DT_RAREITEM_ROOM_INFO_CLI;

typedef struct tagPKT_CLIGS_OPEN_RAREITEMROOM_REQ{
	tagPKT_CLIGS_OPEN_RAREITEMROOM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RAREITEMROOM_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_RAREITEMROOM_REQ;

typedef struct tagPKT_CLIGS_OPEN_RAREITEMROOM_ACK{
	tagPKT_CLIGS_OPEN_RAREITEMROOM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RAREITEMROOM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RAREITEM_ROOM_INFO_CLI stRareItemRoomInfo; //��Ʒ����Ϣ
	DT_RAREITEM_INFO_LIST_CLI stRareItemInfo; //��Ʒ��Ϣ
}PKT_CLIGS_OPEN_RAREITEMROOM_ACK;

typedef struct tagPKT_CLIGS_BUY_RAREITEM_REQ{
	tagPKT_CLIGS_BUY_RAREITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_RAREITEM_REQ)); }
	UINT32           dwGoodsID; //��ƷID
}PKT_CLIGS_BUY_RAREITEM_REQ;

typedef struct tagPKT_CLIGS_BUY_RAREITEM_ACK{
	tagPKT_CLIGS_BUY_RAREITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_RAREITEM_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_RAREITEM_INFO_CLI stRareItemInfo; //�ܺ���Ʒ��Ϣ
	UINT32           dwLeftDoorsTributes; //���ʣ���Ź�
}PKT_CLIGS_BUY_RAREITEM_ACK;

typedef struct tagPKT_CLIGS_OPEN_UPGRADERAREITEM_REQ{
	tagPKT_CLIGS_OPEN_UPGRADERAREITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_UPGRADERAREITEM_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_UPGRADERAREITEM_REQ;

typedef struct tagDT_UPGRADE_RAREITEM_INFO{
	UINT32           dwUpgradeKindID; //������ƷID
	UINT16           wRateItemNum; //��������
}DT_UPGRADE_RAREITEM_INFO;

typedef struct tagDT_UPGRADE_MSG_LIST{
	TCHAR            aszUpgradeMsg[FACTION_UPGRADE_MSG_LEN]; //��Ʒ����������Ϣ
}DT_UPGRADE_MSG_LIST;

typedef struct tagDT_UPGRADE_REQUIRE_INFO_CLI{
	UINT32           dwConsumptionMoney; //��Ҫ���ʽ�
	UINT8            byFactionFundsEnough; //�����ʽ��Ƿ��㹻(0 ���� 1 �㹻)
	UINT8            byUnitedGrade; //Ҫ�����ɵȼ�
	UINT8            byFactionIsEnough; //���ɵȼ��Ƿ�ﵽ
	UINT8            byInfoListNum; //��Ϣ�������
	DT_UPGRADE_MSG_LIST astUpgradeInfoList[MAX_UPGRADE_INFO_NUM]; //������Ϣ����
	UINT8            byBuildLevel; //����ǰ�ĵȼ�
	UINT8            byIsUpgradeLimit; //����Ȩ��0 û����Ȩ�ޣ� 1������Ȩ��
}DT_UPGRADE_REQUIRE_INFO_CLI;

typedef struct tagPKT_CLIGS_OPEN_UPGRADERAREITEM_ACK{
	tagPKT_CLIGS_OPEN_UPGRADERAREITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_UPGRADERAREITEM_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_UPGRADE_REQUIRE_INFO_CLI stUpgradeRequireInfo; //����Ҫ������
}PKT_CLIGS_OPEN_UPGRADERAREITEM_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_RAREITEM_REQ{
	tagPKT_CLIGS_UPGRADE_RAREITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_RAREITEM_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_UPGRADE_RAREITEM_REQ;

typedef struct tagDT_AFTER_UPGRADE_INFO_CLI{
	UINT8            byRareItemGrade; //���������Ʒ��ȼ�
	UINT8            byIsMaxLevel; //���������ɵȼ��Ƿ�ﵽ����(0 δ�ﵽ����, 1�ﵽ����)
	DT_RAREITEM_INFO_LIST_CLI stRareItemInfo; //��Ʒ��Ϣ
}DT_AFTER_UPGRADE_INFO_CLI;

typedef struct tagPKT_CLIGS_UPGRADE_RAREITEM_ACK{
	tagPKT_CLIGS_UPGRADE_RAREITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_RAREITEM_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_AFTER_UPGRADE_INFO_CLI stAfterUpgradeInfo; //���������Ϣ
	DT_UPGRADE_REQUIRE_INFO_CLI stUpgradeRequireInfo; //��һ������Ҫ��
	UINT32           dwFactionFunds; //�ʽ�ͬ��
}PKT_CLIGS_UPGRADE_RAREITEM_ACK;

typedef struct tagPKT_CLIGS_OPEN_GYMNASIUM_REQ{
	tagPKT_CLIGS_OPEN_GYMNASIUM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GYMNASIUM_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_GYMNASIUM_REQ;

typedef struct tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ{
	tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ)); }
	UINT32           dwSkillID; //����ID
}PKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ;

typedef struct tagPKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ{
	tagPKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ;

typedef struct tagPKT_CLIGS_GYMNASIUM_UPGRADE_REQ{
	tagPKT_CLIGS_GYMNASIUM_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GYMNASIUM_UPGRADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_GYMNASIUM_UPGRADE_REQ;

typedef struct tagDT_GYMNASIUM_CLI_INFO{
	UINT8            byGymnasiumLevel; //���õȼ�
	UINT32           dwDoorsTribute; //�Ź�
	UINT8            byUpgradeLimit; //����Ȩ��
}DT_GYMNASIUM_CLI_INFO;

typedef struct tagDT_SKILL_CLI_INFO{
	UINT8            bySkillID; //����ID
	TCHAR            aszGymnasiumSkillName[SKILL_NAME_LEN]; //��������
	UINT8            bySkillFlag; //����״̬��1��ѧϰ��2�ﵽ��ǰ������3 �ﵽ��������4�Ź����㣬5 δ���� 6�ۻ��Ź�����
	UINT8            byCurMaxSkillLevel; //��ǰ��������
	UINT8            bySkillLevel; //���ܵȼ�
	TCHAR            aszSkillMsg[SKILL_MSG_LEN]; //������Ϣ
	UINT32           dwCostDoorsTribute; //�����Ź�
	UINT32           dwGymnasiumLevelRequire; //��Ҫ���õȼ�
}DT_SKILL_CLI_INFO;

typedef struct tagPKT_CLIGS_OPEN_GYMNASIUM_ACK{
	tagPKT_CLIGS_OPEN_GYMNASIUM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GYMNASIUM_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_GYMNASIUM_CLI_INFO stGymnasiumInfo; //������Ϣ
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_CLI_INFO astSkillInfo[MAX_GYMNASIUM_SKILL_NUM]; //������Ϣ
	UINT32           adwSkillSumDoorsTribute[MAX_GYMNASIUM_SKILL_NUM]; //�ۻ��Ź�Ҫ��
}PKT_CLIGS_OPEN_GYMNASIUM_ACK;

typedef struct tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK{
	tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_SKILL_CLI_INFO stSkillInfo; //������Ϣ
	UINT32           dwLeftDoorsTribute; //���ʣ���Ź�
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	UINT32           dwSumDoorsTribute; //�ۻ��Ź�Ҫ��
}PKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK;

typedef struct tagPKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK{
	tagPKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_UPGRADE_REQUIRE_INFO_CLI stUpgradeRequireInfo; //����Ҫ������
}PKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK;

typedef struct tagPKT_CLIGS_GYMNASIUM_UPGRADE_ACK{
	tagPKT_CLIGS_GYMNASIUM_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GYMNASIUM_UPGRADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_CLI_INFO astAfterUpgradeInfo[MAX_GYMNASIUM_SKILL_NUM]; //������ļ�����Ϣ
	DT_UPGRADE_REQUIRE_INFO_CLI stUpgradeRequireInfo; //��һ������Ҫ��
	UINT8            byFullLevelMark; //������ʶ
	UINT8            byGymnasiumLevel; //����������õȼ�
	UINT32           dwFactionFunds; //�ʽ�ͬ��
	UINT32           adwSkillSumDoorsTribute[MAX_GYMNASIUM_SKILL_NUM]; //�ۻ��Ź�Ҫ��
}PKT_CLIGS_GYMNASIUM_UPGRADE_ACK;

typedef struct tagPKT_CLIGS_OPEN_SHADE_REQ{
	tagPKT_CLIGS_OPEN_SHADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SHADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_SHADE_REQ;

typedef struct tagDT_SHADE_INFO{
	UINT32           dwShadeLevel; //�����ȼ�
	UINT32           dwDoorsTribute; //�Ź�
	UINT64           qwGold; //Ԫ��
	UINT64           qwCoin; //ͭǮ
	UINT8            byUpgradeLimit; //����Ȩ��
	UINT8            byPlayerVIPLevel; //���VIP�ȼ�
}DT_SHADE_INFO;

typedef struct tagDT_HUNTING_POT_INFO{
	TCHAR            aszPotName[HUNTING_POT_NAME]; //��������
	UINT32           dwCurIntegral; //��ǰ����
	UINT32           dwMaxintegral; //��������
	UINT32           dwRewardFunds; //�����������ʽ�
}DT_HUNTING_POT_INFO;

typedef struct tagDT_HUNTING_POT_INFO2{
	TCHAR            aszPotName[HUNTING_POT_NAME]; //��������
	UINT32           dwCurIntegral; //��ǰ����
	UINT32           dwMaxintegral; //��������
	UINT32           dwRewardFunds; //�����������ʽ�
	UINT8            byIsUnlock; //�Ƿ����(0δ������ 1����)
	UINT8            byUnLockLevel; //�����ȼ�
}DT_HUNTING_POT_INFO2;

typedef struct tagDT_REWARD_SINGLE_INFO{
	UINT8            byGoodsType; //��������
	UINT32           dwRewardValue; //����ֵ
	UINT8            byOutProbability; //���ָ���
	UINT8            byMulti; //���� 0Ϊ������1Ϊ�ӱ�
}DT_REWARD_SINGLE_INFO;

typedef struct tagDT_HUNTING_SCHEDULE_INFO{
	UINT8            byHuntingPotPos; //��ǰ׽����λ��
	UINT8            byHuntingPotNum; //׽��������
	DT_HUNTING_POT_INFO astHuntingPotInfo[MAX_HUTING_POT_NUM]; //׽������Ϣ
	UINT32           dwFactionFunds; //�����ʽ�
	UINT32           dwDoorsTribute; //����ʣ���Ź�
}DT_HUNTING_SCHEDULE_INFO;

typedef struct tagDT_HUNTING_SCHEDULE_INFO2{
	UINT8            byHuntingPotPos; //��ǰ׽����λ��
	UINT8            byHuntingPotNum; //׽��������
	DT_HUNTING_POT_INFO2 astHuntingPotInfo[MAX_HUNTING_POT_NUM_NEW]; //׽������Ϣ
	UINT32           dwFactionFunds; //�����ʽ�
	UINT32           dwDoorsTribute; //����ʣ���Ź�
	UINT8            byLastSchedule; //�ϴε���
}DT_HUNTING_SCHEDULE_INFO2;

typedef struct tagDT_HUNTING_INFO_CLI{
	UINT8            byTaskID; //����ID
	TCHAR            aszTaskBeginTimeMsg[NORMAL_MSG_LEN]; //������ʱ����ʾ��Ϣ
	TCHAR            aszTaskDescMsg[TASK_DESCRIBE_MSG_LEN]; //������ʾ��Ϣ
	DT_HUNTING_SCHEDULE_INFO stHuntingScheduleInfo; //׽��������Ϣ
	UINT8            byHuntingNum; //׽��������Ϣ
	UINT8            byActiviFlag; //���ʼ��ʼ��ʶ0 δ������ 1����
	UINT32           dwHuntingCountDown; //׽������ʱ
	DT_ACTIVITY_BASE_DATA stActiviInfo; //���Ϣ
}DT_HUNTING_INFO_CLI;

typedef struct tagPKT_CLIGS_OPEN_SHADE_ACK{
	tagPKT_CLIGS_OPEN_SHADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SHADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_SHADE_INFO    stShadeInfo; //������Ϣ
	DT_HUNTING_INFO_CLI stHuntingInfo; //׽��ģ����Ϣ
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
}PKT_CLIGS_OPEN_SHADE_ACK;

typedef struct tagPKT_CLIGS_OPEN_SHADE_UPGRADE_REQ{
	tagPKT_CLIGS_OPEN_SHADE_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SHADE_UPGRADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_SHADE_UPGRADE_REQ;

typedef struct tagDT_SHADE_UPGRADE_INFO{
	UINT8            byFactionFundsEnough; //���������ʽ��Ƿ��㹻
	UINT32           dwUpgradeNeedFactionFunds; //���������ʽ�
	UINT8            byFactionLevelEnough; //�����������ɵȼ��Ƿ�ﵽ
	UINT32           dwUpgradeNeedFactionLevel; //�����������ɵȼ�
	UINT8            byUpgradeMsgNum; //������Ϣ����
	DT_UPGRADE_MSG_LIST astUpgradeMsgLst[SHADE_UPGRADE_MSG_NUM]; //��Ϣ����
	UINT8            byShadelevel; //����ǰ�İ����ȼ�
	UINT8            byIsUpgradeLimit; //����Ȩ��0û������Ȩ�ޣ� 1������Ȩ��
}DT_SHADE_UPGRADE_INFO;

typedef struct tagPKT_CLIGS_OPEN_SHADE_UPGRADE_ACK{
	tagPKT_CLIGS_OPEN_SHADE_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SHADE_UPGRADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_SHADE_UPGRADE_INFO stUpgradeInfo; //�������������Ϣ
}PKT_CLIGS_OPEN_SHADE_UPGRADE_ACK;

typedef struct tagPKT_CLIGS_SHADE_UPGRADE_REQ{
	tagPKT_CLIGS_SHADE_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SHADE_UPGRADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_SHADE_UPGRADE_REQ;

typedef struct tagPKT_CLIGS_SHADE_UPGRADE_ACK{
	tagPKT_CLIGS_SHADE_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SHADE_UPGRADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_HUNTING_INFO_CLI stAfterUpgradeHuntingInfo; //�������׽����Ϣ
	DT_SHADE_UPGRADE_INFO stNextUpgradeInfo; //��һ����������Ϣ
	UINT8            byFullLevelMark; //������ʶ
	UINT8            byShadeLevel; //������İ����ȼ�
	UINT32           dwFactionFunds; //�ʽ�ͬ��
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
}PKT_CLIGS_SHADE_UPGRADE_ACK;

typedef struct tagDT_REWARD_INFO{
	UINT8            byRewardType; //����Ʒ������ commondef.h  EColor��
	UINT8            byRewardNum; //��������
	DT_REWARD_SINGLE_INFO astRewardMsg[HUNTING_REWARD_MGS_NUM]; //������Ϣ
}DT_REWARD_INFO;

typedef struct tagDT_MONSTER_INFO{
	UINT16           wMonsterID; //����ID
	UINT32           dwMonsterPower; //����ս��
	DT_REWARD_INFO   stMonsterReward; //���ｱ��
}DT_MONSTER_INFO;

typedef struct tagPKT_CLIGS_OPEN_GOLDMODE_REQ{
	tagPKT_CLIGS_OPEN_GOLDMODE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GOLDMODE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_GOLDMODE_REQ;

typedef struct tagPKT_CLIGS_OPEN_GOLDMODE_ACK{
	tagPKT_CLIGS_OPEN_GOLDMODE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GOLDMODE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_MONSTER_INFO  stCurMonsterInfo; //���������Ϣ
	UINT32           dwSyncGold; //ͬ��Ԫ������
}PKT_CLIGS_OPEN_GOLDMODE_ACK;

typedef struct tagPKT_CLIGS_OPEN_HUNTING_REQ{
	tagPKT_CLIGS_OPEN_HUNTING_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HUNTING_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_HUNTING_REQ;

typedef struct tagDT_REWARD_INFO_ALL{
	UINT8            byTypeNum; //����Ʒ�ʸ���
	DT_REWARD_INFO   astRewardInfo[MONSTER_TYPE_NUM]; //������Ϣ
}DT_REWARD_INFO_ALL;

typedef struct tagDT_CHANGE_MONSTER_INFO{
	UINT8            byMaxFreeNum; //�������
	UINT8            byCurFreeNum; //ʣ����Ѵ���
	UINT32           dwChangeMonsterGold; //��������Ԫ��
}DT_CHANGE_MONSTER_INFO;

typedef struct tagDT_FIND_MONSTER_INFO{
	UINT8            byPlayerVIPLevel; //���VIP�ȼ�
	UINT8            byNeedVIPLevel; //��ҪVIP�ȼ�
	UINT32           dwNeedGold; //��ҪԪ��
}DT_FIND_MONSTER_INFO;

typedef struct tagDT_HUNTING_OTHER_INFO{
	UINT64           qwGold; //Ԫ��
	UINT32           dwDoorsTribute; //�Ź�
	UINT8            byCanHuntingNum; //���տ�׽Ծ������Ϣ
	UINT32           dwHuntingTime; //׽��ʱ��
	DT_CHANGE_MONSTER_INFO stChangeMonsterMsg; //��Ѵ���
	DT_FIND_MONSTER_INFO stFindMonsterMsg; //���ʹ��˵��
	UINT32           dwMaxTaskIntegral; //�����������
	UINT32           dwCurTaskIntegral; //��ǰ����
	TCHAR            aszCurHuntingPotName[HUNTING_POT_NAME]; //��ǰ����������
	UINT8            byCurPotNum; //��ǰ׽����λ��
	UINT8            bySumPotNum; //��׽��������
}DT_HUNTING_OTHER_INFO;

typedef struct tagPKT_CLIGS_OPEN_HUNTING_ACK{
	tagPKT_CLIGS_OPEN_HUNTING_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HUNTING_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_REWARD_INFO_ALL stRewardInfoAll; //������Ϣ
	DT_MONSTER_INFO  stMonsterInfo; //��ǰ������Ϣ
	DT_HUNTING_OTHER_INFO stOtherInfo; //����������Ϣ
	UINT8            byMonsterExist; //���ִ��ڱ�ʶ0 û�У� 1 Ϊ���ϴ�δ��������
	UINT8            byOpenGoldFlag; //�������鿪��״̬ 0δ������ 1 �ѿ���
	UINT8            byVIPLevel; //��������������Ҫ��VIP
	UINT32           dwNeedGold; //��������������Ҫ��Ԫ��
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //������Ϣ
}PKT_CLIGS_OPEN_HUNTING_ACK;

typedef struct tagPKT_CLIGS_FIND_MONSTER_REQ{
	tagPKT_CLIGS_FIND_MONSTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FIND_MONSTER_REQ)); }
	UINT8            byFindType; //Ѱ�����ͣ�1 ��ʼѰ�ң� 2 ǧ���� 3 �������
	UINT8            byMonsterNum; //���й���ĸ���
	UINT16           awMonsterBlue[MONSTER_GROUP_NUM]; //��ɫ����
	UINT16           awMonsterPurple[MONSTER_GROUP_NUM]; //��ɫ����
	UINT16           awMonsterRed[MONSTER_GROUP_NUM]; //��ɫ����
	UINT16           awMonsterOrange[MONSTER_GROUP_NUM]; //��ɫ����
}PKT_CLIGS_FIND_MONSTER_REQ;

typedef struct tagPKT_CLIGS_FIND_MONSTER_ACK{
	tagPKT_CLIGS_FIND_MONSTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FIND_MONSTER_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_CHANGE_MONSTER_INFO stFreeMsg; //�����ʾ��Ϣ
	UINT32           dwGoldNum; //ͬ��Ԫ��
	DT_MONSTER_INFO  stMonsterInfo; //������Ϣ
	UINT8            byFindType; //Ѱ�����ͣ�1 ��ʼѰ�ң� 2 ǧ���� 3 �������
	UINT8            byGoldModeFlag; //�Ƿ��ڻƽ�ģʽ��0 ��ͨ״̬ 1 �ƽ�ģʽ��
}PKT_CLIGS_FIND_MONSTER_ACK;

typedef struct tagPKT_CLIGS_HUNTING_BATTLE_REQ{
	tagPKT_CLIGS_HUNTING_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_HUNTING_BATTLE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_HUNTING_BATTLE_REQ;

typedef struct tagPKT_CLIGS_HUNTING_BATTLE_ACK2{
	tagPKT_CLIGS_HUNTING_BATTLE_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_HUNTING_BATTLE_ACK2)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_BATTLE_DATA3  stBattleInfo; //ս����Ϣ
	DT_REWARD_INFO   stBattleReward; //ս������
	DT_HUNTING_SCHEDULE_INFO stTaskScheduleInfo; //���������Ϣ
	UINT32           dwClosedMonsterNeedGold; //������Ҫ��Ԫ��
	TCHAR            aszBattleLostMsg[MAX_FACTION_DESC_NUM]; //ս��ʧ����Ϣ
	UINT32           dwSyncDoorsTribute; //ͬ������
	UINT8            byScheduleChangeFlag; //�����ı��ʶ��0 û�䣬 1�䣩
	UINT8            byHuntingLeftNum; //׽������ͬ��
	UINT8            byIsGoldMode; //�Ƿ��ڻƽ�ģʽ
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
}PKT_CLIGS_HUNTING_BATTLE_ACK2;

typedef struct tagPKT_CLIGS_CHANGE_SCHEDEULE_NTF{
	tagPKT_CLIGS_CHANGE_SCHEDEULE_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_SCHEDEULE_NTF)); }
	UINT8            byTaskID; //����ID
	UINT64           qwNTFTime; //֪ͨʱ��
	DT_HUNTING_SCHEDULE_INFO stScheduleInfo; //��ǰ����
	DT_REWARD_INFO   stBattleReward; //��������
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
}PKT_CLIGS_CHANGE_SCHEDEULE_NTF;

typedef struct tagPKT_CLIGS_OPEN_HOT_SPRING_REQ{
	tagPKT_CLIGS_OPEN_HOT_SPRING_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HOT_SPRING_REQ)); }
	UINT16           wPosX; //λ��X
	UINT16           wPosY; //λ��Y
}PKT_CLIGS_OPEN_HOT_SPRING_REQ;

typedef struct tagDT_HOT_SPRING_PLAYER_DATA_CLI{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�ǳ�
	UINT16           wHeroKindID; //���佫����
	UINT16           wLevel; //�ȼ�
	UINT16           wPosX; //λ����ϢX
	UINT16           wPosY; //λ����ϢY
	UINT8            byTuhaoGoldMark; //�������ʶλ
}DT_HOT_SPRING_PLAYER_DATA_CLI;

typedef struct tagDT_HOT_SPRING_PLAYER_DATA_CLI_LST{
	UINT32           dwPlayerNum; //����
	DT_HOT_SPRING_PLAYER_DATA_CLI astHotSpringPlayerLst[MAX_HOT_SPRING_SHOW_PLAYER_NUM]; //��Ȫ�����Ϣ�б�
}DT_HOT_SPRING_PLAYER_DATA_CLI_LST;

typedef struct tagDT_HOT_SPRING_SELF_DATA_CLI{
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurSkill; //��ǰ���������ܣ�
	UINT64           qwCurPhystrength; //��ǰ����
	UINT16           wPosY; //λ����ϢY
	UINT16           wPosX; //λ����ϢX
	UINT64           qwMaxPhystrength; //��������
	UINT8            byGiveWineLimit; //�;�Ȩ�� 0 û��Ȩ�ޣ� 1 ��Ȩ��
}DT_HOT_SPRING_SELF_DATA_CLI;

typedef struct tagDT_DIDNOT_GIVE_WINE_CLI{
	UINT8            byLeftGiveWineNum; //����ʣ��;ƴ���
	UINT32           dwGiveWineCost; //�;�����
	UINT32           dwGiveWineCountDown; //�;���ȴ����ʱ
	UINT32           dwGiveWineCDValue; //�;�CD
}DT_DIDNOT_GIVE_WINE_CLI;

typedef struct tagDT_DIDNOT_DRINGK_WINE_LIST_CLI{
	UINT8            byWineNum; //�Ƶ�����
	DT_WINE_DATA_CLI astAllWineInfo[HOT_SPRING_WINE_NUM]; //���־�
	TCHAR            aszExtMsg[WINE_MSG_LEN]; //��ʾ��Ϣ
}DT_DIDNOT_DRINGK_WINE_LIST_CLI;

typedef struct tagDT_HOTSPRING_ACTIVITY_TIME_DATA{
	UINT8            byStartHour; //�����ʱ�䣬Сʱ
	UINT8            byStartMin; //�����ʱ�䣬����
	UINT16           wKeepTime; //�����ʱ��
}DT_HOTSPRING_ACTIVITY_TIME_DATA;

typedef struct tagDT_HOT_SPRING_EXPERIENCE{
	UINT32           dwMaxExperience; //����ȡ��������
	UINT32           dwCurExperience; //��ǰ����ȡ����
	UINT32           dwExperienceBase; //�������
	UINT32           dwAddInterval; //�������Ӽ��ʱ��
}DT_HOT_SPRING_EXPERIENCE;

typedef struct tagPKT_CLIGS_OPEN_HOT_SPRING_ACK{
	tagPKT_CLIGS_OPEN_HOT_SPRING_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HOT_SPRING_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_HOT_SPRING_PLAYER_DATA_CLI_LST stPlayerInfo; //����б�
	DT_HOT_SPRING_SELF_DATA_CLI stPlayerSelf; //�Լ���Ϣ
	UINT8            byBeforeWineState; //�һ�״̬
	UINT8            byGiveWineState; //�򿪴;�״̬
	DT_WINE_DATA_CLI stWineDataCli; //�Ƶ���Ϣ
	UINT64           qwActiviTime; //�;Ƶ���ʱ
	UINT8            byHaveOverReward; //�Ƿ��й��ڽ���
	DT_OVER_GIVE_WINE_REWARD stOverReward; //���ڽ���
	DT_HOT_SPRING_EXPERIENCE stPlayerExprience; //Ӣ�۾���
}PKT_CLIGS_OPEN_HOT_SPRING_ACK;

typedef struct tagPKT_CLIGS_SELECT_WINE_REQ{
	tagPKT_CLIGS_SELECT_WINE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SELECT_WINE_REQ)); }
	UINT32           dwWineID; //�Ƶ�ID
}PKT_CLIGS_SELECT_WINE_REQ;

typedef struct tagPKT_CLIGS_SELECT_WINE_ACK{
	tagPKT_CLIGS_SELECT_WINE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SELECT_WINE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwGold; //Ԫ��
	UINT64           qwCoin; //ͭǮ
	DT_WINE_DATA_CLI stWineDataCli; //�Ƶ���Ϣ
	UINT8            bySelectWineState; //ѡ��״̬0 Ϊ��ͨ����  1 Ϊ�һ�����
}PKT_CLIGS_SELECT_WINE_ACK;

typedef struct tagPKT_CLIGS_DRINK_WINE_REQ{
	tagPKT_CLIGS_DRINK_WINE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRINK_WINE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_DRINK_WINE_REQ;

typedef struct tagPKT_CLIGS_DRINK_WINE_ACK{
	tagPKT_CLIGS_DRINK_WINE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRINK_WINE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_WINE_DATA_CLI stWineDataCli; //�Ƶ���Ϣ
	UINT8            byRewardID1; //����ID1
	UINT32           dwSyncValue1; //ͬ������1
	UINT8            byRewardID2; //����ID2
	UINT32           dwSyncValue2; //ͬ������2
}PKT_CLIGS_DRINK_WINE_ACK;

typedef struct tagPKT_CLIGS_DRINK_WINE_MOVE_REQ{
	tagPKT_CLIGS_DRINK_WINE_MOVE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRINK_WINE_MOVE_REQ)); }
	UINT16           wPosX; //λ��x
	UINT16           wPosY; //λ��y
}PKT_CLIGS_DRINK_WINE_MOVE_REQ;

typedef struct tagPKT_CLIGS_DRINK_WINE_MOVE_ACK{
	tagPKT_CLIGS_DRINK_WINE_MOVE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRINK_WINE_MOVE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_DRINK_WINE_MOVE_ACK;

typedef struct tagPKT_CLIGS_LEAVE_HOT_SPRING_REQ{
	tagPKT_CLIGS_LEAVE_HOT_SPRING_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_HOT_SPRING_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_LEAVE_HOT_SPRING_REQ;

typedef struct tagPKT_CLIGS_LEAVE_HOT_SPRING_ACK{
	tagPKT_CLIGS_LEAVE_HOT_SPRING_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_HOT_SPRING_ACK)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_LEAVE_HOT_SPRING_ACK;

typedef struct tagPKT_CLIGS_HOT_SPRING_POS_NTF{
	tagPKT_CLIGS_HOT_SPRING_POS_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_HOT_SPRING_POS_NTF)); }
	UINT8            byEnterPalyerNum; //��������
	DT_HOT_SPRING_PLAYER_DATA_CLI astEnterPlayerInfo[MAX_HOT_SPRING_SHOW_PLAYER_NUM]; //������Ա��Ϣ
	UINT8            byLeavePlayerNum; //ɾ������
	DT_HOT_SPRING_PLAYER_DATA_CLI astLeavePlayerInfo[MAX_HOT_SPRING_SHOW_PLAYER_NUM]; //ɾ����Ա��Ϣ
	UINT8            byMovePlayerNum; //�ƶ���Ա
	DT_HOT_SPRING_PLAYER_DATA_CLI astMovePlayerInfo[MAX_HOT_SPRING_SHOW_PLAYER_NUM]; //�ƶ���Ա��Ϣ
}PKT_CLIGS_HOT_SPRING_POS_NTF;

typedef struct tagPKT_CLIGS_CHANGE_OTHER_REQ{
	tagPKT_CLIGS_CHANGE_OTHER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_OTHER_REQ)); }
	UINT32           dwSendPlayerID; //ս���仯��Ϣ
}PKT_CLIGS_CHANGE_OTHER_REQ;

typedef struct tagPKT_CLIGS_CHANGE_OTHER_ACK{
	tagPKT_CLIGS_CHANGE_OTHER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_OTHER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_PLAYER_CLI_LST stFactionPlayerDataLst; //���������Ϣ
	DT_FACTION_AUTHORITY_EX stFactionAuthority; //����Ȩ����Ϣ
	DT_DOORSTRIBUTE_LEVE_DATA_LST stDoorsTributeLst; //���׶��б�
}PKT_CLIGS_CHANGE_OTHER_ACK;

typedef struct tagPKT_CLIGS_GIVE_WINE_REQ{
	tagPKT_CLIGS_GIVE_WINE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GIVE_WINE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_GIVE_WINE_REQ;

typedef struct tagPKT_CLIGS_GIVE_WINE_ACK{
	tagPKT_CLIGS_GIVE_WINE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GIVE_WINE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_DIDNOT_GIVE_WINE_CLI stGiveWineInfo; //�;���Ϣ
}PKT_CLIGS_GIVE_WINE_ACK;

typedef struct tagPKT_CLIGS_CLICK_SELECT_WINE_REQ{
	tagPKT_CLIGS_CLICK_SELECT_WINE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLICK_SELECT_WINE_REQ)); }
	UINT8            byDrinkWIneState; //����״̬ 0 ���� 1 �һ�
}PKT_CLIGS_CLICK_SELECT_WINE_REQ;

typedef struct tagPKT_CLIGS_CLICK_SELECT_WINE_ACK{
	tagPKT_CLIGS_CLICK_SELECT_WINE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLICK_SELECT_WINE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_DIDNOT_DRINGK_WINE_LIST_CLI stWineDataList; //�Ƶ���Ϣ
}PKT_CLIGS_CLICK_SELECT_WINE_ACK;

typedef struct tagPKT_CLIGS_SURE_GIVE_WINE_REQ{
	tagPKT_CLIGS_SURE_GIVE_WINE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SURE_GIVE_WINE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_SURE_GIVE_WINE_REQ;

typedef struct tagPKT_CLIGS_SURE_GIVE_WINE_ACK{
	tagPKT_CLIGS_SURE_GIVE_WINE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SURE_GIVE_WINE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwActiviTime; //�����ʱ
}PKT_CLIGS_SURE_GIVE_WINE_ACK;

typedef struct tagPKT_CLIGS_CLOSED_MONSTER_REQ{
	tagPKT_CLIGS_CLOSED_MONSTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLOSED_MONSTER_REQ)); }
	UINT8            byChoice; //����ѡ�� 0�������� 1����
}PKT_CLIGS_CLOSED_MONSTER_REQ;

typedef struct tagPKT_CLIGS_CLOSED_MONSTER_ACK{
	tagPKT_CLIGS_CLOSED_MONSTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLOSED_MONSTER_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	UINT8            byRewardNum; //��������
	DT_REWARD_SINGLE_INFO astRewardMsg[HUNTING_REWARD_MGS_NUM]; //������Ϣ
	UINT32           dwSyncDoorsTribute; //ͬ������
	DT_HUNTING_SCHEDULE_INFO stTaskScheduleInfo; //���������Ϣ
	UINT8            byScheduleChangeFlag; //�����ı��ʶ��0 û�䣬 1�䣩
	UINT8            byHuntingLeftNum; //׽������ͬ��
	UINT8            byCloseMonsterChoice; //����ѡ��
	UINT64           qwSyncGold; //Ԫ��ͬ��
	UINT8            byIsGoldMode; //�Ƿ��ڻƽ�ģʽ0������״̬�� 1����
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
}PKT_CLIGS_CLOSED_MONSTER_ACK;

typedef struct tagPKT_CLIGS_FACTION_PLAYER_CHANGE_REQ{
	tagPKT_CLIGS_FACTION_PLAYER_CHANGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_PLAYER_CHANGE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_FACTION_PLAYER_CHANGE_REQ;

typedef struct tagPKT_CLIGS_FACTION_PLAYER_CHANGE_ACK{
	tagPKT_CLIGS_FACTION_PLAYER_CHANGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_PLAYER_CHANGE_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byChangeFlag; //���ɱ䶯��ʶ   0 û�б䶯   1 �б䶯
}PKT_CLIGS_FACTION_PLAYER_CHANGE_ACK;

typedef struct tagPKT_CLIGS_GIVE_WINE_ACTIVITY_NTF{
	tagPKT_CLIGS_GIVE_WINE_ACTIVITY_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_GIVE_WINE_ACTIVITY_NTF)); }
	UINT64           qwCountDownTime; //����ʱ
}PKT_CLIGS_GIVE_WINE_ACTIVITY_NTF;

typedef struct tagPKT_CLIGS_LEAVE_FACTION_REQ{
	tagPKT_CLIGS_LEAVE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_LEAVE_FACTION_REQ;

typedef struct tagPKT_CLIGS_LEAVE_FACTION_ACK{
	tagPKT_CLIGS_LEAVE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_FACTION_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIGS_LEAVE_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_LEAVE_FACTION_REQ{
	tagPKT_CLIGS_OPEN_LEAVE_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_LEAVE_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_LEAVE_FACTION_REQ;

typedef struct tagPKT_CLIGS_OPEN_LEAVE_FACTION_ACK{
	tagPKT_CLIGS_OPEN_LEAVE_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_LEAVE_FACTION_ACK)); }
	UINT16           wErrCode; //������
	UINT32           dwIntervalTime; //���ܼ�������ʱ�䣬��λ���룩
	UINT8            byLeaveFactionMark; //��ʶλ��0�˳����� 1 ��ɢ���ɣ�
}PKT_CLIGS_OPEN_LEAVE_FACTION_ACK;

typedef struct tagPKT_CLIGS_OPEN_FACTION_UPGRADE_REQ{
	tagPKT_CLIGS_OPEN_FACTION_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_UPGRADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_FACTION_UPGRADE_REQ;

typedef struct tagDT_FACTION_UPGRADE_ALL_INFO{
	UINT32           dwNeedFactionFunds; //Ҫ�������ʽ�
	UINT8            byFunds_Is_Enough; //�����ʽ��Ƿ��㹻 0 ���� 1 �㹻
	UINT8            byUpgradeNum; //������Ϣ����
	DT_UPGRADE_MSG_LIST astUpgradeInfo[MAX_FACTION_UPGRADE_NUM]; //������Ϣ
	UINT8            byFactionLevel; //����ǰ�����ɵȼ�
	UINT8            byIsUpgradeLimit; //�Ƿ���Ȩ��0 û������Ȩ�ޣ� 1������Ȩ��
}DT_FACTION_UPGRADE_ALL_INFO;

typedef struct tagPKT_CLIGS_OPEN_FACTION_UPGRADE_ACK{
	tagPKT_CLIGS_OPEN_FACTION_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_UPGRADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_FACTION_UPGRADE_ALL_INFO stUpgradeAllInfo; //����Ҫ����Ϣ
}PKT_CLIGS_OPEN_FACTION_UPGRADE_ACK;

typedef struct tagDT_FACTION_BUILD_LEVEL{
	UINT8            byRareitemLevel; //��Ʒ��0������ ��0Ϊ�����ȼ���
	UINT8            byGymnasiumLevel; //����
	UINT8            byShadeLevel; //����
	UINT8            byHotSpringLevel; //��Ȫ
	UINT8            byColdPrisonLevel; //����
	UINT8            byFactionTowerLevel; //�����
}DT_FACTION_BUILD_LEVEL;

typedef struct tagPKT_CLIGS_FACTION_UPGRADE_REQ{
	tagPKT_CLIGS_FACTION_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_UPGRADE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_FACTION_UPGRADE_REQ;

typedef struct tagDT_FACTION_SYNC_INFO{
	UINT32           dwFactionFunds; //�����ʽ�ͬ��
	UINT32           dwFactionMaxNum; //��������ͬ��
	UINT8            byRareitemFlag; //��Ʒ����״̬
	UINT8            byGymnasiumFlag; //���ÿ���״̬
	UINT8            byShadeFlag; //��������״̬
	UINT8            byHotFlag; //��Ȫ����״̬
	UINT8            byColdPrisonFlag; //���ο���״̬
	UINT8            byFactionTowerFlag; //���������״̬
	UINT8            byFactionRank; //���ɵ�ǰ����
}DT_FACTION_SYNC_INFO;

typedef struct tagPKT_CLIGS_FACTION_UPGRADE_ACK{
	tagPKT_CLIGS_FACTION_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_UPGRADE_ACK)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_FACTION_SYNC_INFO stSyncInfo; //�������ͬ������
	UINT8            byIsMaxLevel; //�Ƿ�ﵽ����
	DT_FACTION_UPGRADE_ALL_INFO stNextUpgradeAllInfo; //��һ������Ч��
	UINT8            byFactionLevel; //����������ɵȼ�
	UINT32           dwFactionFunds; //�ʽ�ͬ��
	DT_FACTION_BUILD_LEVEL stCurBuildLevel; //��ǰ����Ⱥ�ȼ�
}PKT_CLIGS_FACTION_UPGRADE_ACK;

typedef struct tagDT_EQUIP_MASTER_DETAIL_CLI{
	UINT8            byEquipKind; //��ͨװ�����ͣ�ͷ����ս�ۡ�������սѥ��
	UINT8            byMasterRank; //��ͨ�׼���δ����0����1����2����3����4��
	UINT16           wMasterLevel; //��ͨ�ȼ�
	UINT32           dwCurMasterExp; //װ����ͨ��ǰ����
	UINT32           dwMaxMasterExp; //װ����ͨ�����
	UINT16           wCurPromote; //��ǰ���Լӳ�
	UINT16           wNextPromote; //��һ�����Լӳ�
	UINT8            byActivateOrBreak; //��ǰ״̬��������(0)���ɼ���(1)����ͻ��(2)���޷�������(3)����ͻ�Ƶ��ȼ�����(4)
	UINT32           dwMedalCost; //����ѫ������
	UINT16           wRequiredPlayerLevel; //ͻ���������ҵȼ�
}DT_EQUIP_MASTER_DETAIL_CLI;

typedef struct tagDT_MASTER_EXP_BOOK_DETAIL_CLI{
	UINT8            byBigExpBookCnt; //�м��������飨0����1����2����3����
}DT_MASTER_EXP_BOOK_DETAIL_CLI;

typedef struct tagDT_MASTER_CHEAT_INFO_CLI{
	UINT16           wCheatGold; //��ǧ����Ԫ��
	UINT8            byFreeCheatCnt; //��������ѳ�ǧ����
}DT_MASTER_CHEAT_INFO_CLI;

typedef struct tagDT_MASTER_EXP_BOOK_PANEL_CLI{
	DT_MASTER_EXP_BOOK_DETAIL_CLI astExpBooks[MASTER_EXP_BOOK_COUNT]; //��������еľ�����
	UINT16           wBigBookExp; //ÿ��������Ӷ��پ���
	UINT16           wSmallBookExp; //ÿ��С������Ӷ��پ���
	UINT8            byIsOpenUpCheat; //��ǧ�Ƿ��ѿ��ţ��ѿ���1��δ����0
	DT_MASTER_CHEAT_INFO_CLI stCheatInfo; //��ǧ��Ϣ
}DT_MASTER_EXP_BOOK_PANEL_CLI;

typedef struct tagDT_MASTER_LEVEL_UP{
	UINT32           dwMaxMasterExp; //�õȼ��������
	UINT16           wPromote; //�õȼ������Լӳ�
	UINT16           wNextPromote; //��һ��ʱ�����Լӳ�
}DT_MASTER_LEVEL_UP;

typedef struct tagDT_MASTER_LEVEL_UP_INFO{
	UINT8            byLevelDiff; //�м���˼����������1������3������ֻ����һ��
	DT_MASTER_LEVEL_UP astLevelUp[MASTER_MAX_LEVEL_UP]; //�м����������
	UINT16           wPreLevel; //����ǰ�ĵȼ�
	UINT16           wUpExp; //���μ��˶��پ���
}DT_MASTER_LEVEL_UP_INFO;

typedef struct tagPKT_CLIGS_OPEN_EQUIP_MASTER_REQ{
	tagPKT_CLIGS_OPEN_EQUIP_MASTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EQUIP_MASTER_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_EQUIP_MASTER_REQ;

typedef struct tagPKT_CLIGS_OPEN_EQUIP_MASTER_ACK{
	tagPKT_CLIGS_OPEN_EQUIP_MASTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EQUIP_MASTER_ACK)); }
	UINT16           wErrCode; //������
	DT_EQUIP_MASTER_DETAIL_CLI astEquipMasterDetail[EQUIP_KIND_COUNT]; //�����4��װ���ľ�ͨ��Ϣ
	UINT32           dwGetBookMedalCost; //������֮ͨ���ѫ������
	UINT8            byExpBookPanelState; //������֮ͨ��������ʾ״̬������ʾ0����ʾ��δ�ο�1���ѹο���δȷ��2
	DT_MASTER_EXP_BOOK_PANEL_CLI stExpBookPanelData; //����ϴ�û���꣬�����ʾ���������ҽ��Ź�
	UINT64           qwCoin; //��ǰͭǮ
	UINT32           dwGold; //��ǰԪ��
	UINT32           dwMedal; //��ǰ����ѫ��
}PKT_CLIGS_OPEN_EQUIP_MASTER_ACK;

typedef struct tagPKT_CLIGS_ACTIVATE_MASTER_REQ{
	tagPKT_CLIGS_ACTIVATE_MASTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ACTIVATE_MASTER_REQ)); }
	UINT8            byEquipKind; //װ�����ͣ�ͷ����ս�ۡ�������սѥ��
}PKT_CLIGS_ACTIVATE_MASTER_REQ;

typedef struct tagPKT_CLIGS_ACTIVATE_MASTER_ACK{
	tagPKT_CLIGS_ACTIVATE_MASTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ACTIVATE_MASTER_ACK)); }
	UINT16           wErrCode; //������
	DT_EQUIP_MASTER_DETAIL_CLI stEquipMasterInfo; //װ���ľ�ͨ��Ϣ
	UINT32           dwMedal; //��ǰ����ѫ��
	UINT32           dwOldPower; //ԭʼս��
	UINT32           dwCurPower; //��ǰս��
	UINT8            byCanGetMasterBook; //�Ƿ����������֮ͨ�飺��1����0
}PKT_CLIGS_ACTIVATE_MASTER_ACK;

typedef struct tagPKT_CLIGS_BREAK_MASTER_REQ{
	tagPKT_CLIGS_BREAK_MASTER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BREAK_MASTER_REQ)); }
	UINT8            byEquipKind; //װ�����ͣ�ͷ����ս�ۡ�������սѥ��
}PKT_CLIGS_BREAK_MASTER_REQ;

typedef struct tagPKT_CLIGS_BREAK_MASTER_ACK{
	tagPKT_CLIGS_BREAK_MASTER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BREAK_MASTER_ACK)); }
	UINT16           wErrCode; //������
	DT_EQUIP_MASTER_DETAIL_CLI stEquipMasterInfo; //װ���ľ�ͨ��Ϣ
	UINT32           dwMedal; //��ǰ����ѫ��
	UINT32           dwOldPower; //ԭʼս��
	UINT32           dwCurPower; //��ǰս��
}PKT_CLIGS_BREAK_MASTER_ACK;

typedef struct tagPKT_CLIGS_GET_MASTER_BOOK_REQ{
	tagPKT_CLIGS_GET_MASTER_BOOK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_MASTER_BOOK_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_GET_MASTER_BOOK_REQ;

typedef struct tagPKT_CLIGS_GET_MASTER_BOOK_ACK{
	tagPKT_CLIGS_GET_MASTER_BOOK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_MASTER_BOOK_ACK)); }
	UINT16           wErrCode; //������
	DT_MASTER_EXP_BOOK_PANEL_CLI stExpBookPanelData; //�ι��������Ϣ
	UINT32           dwNextMedalCost; //�´������������ĵ�����ѫ��
	UINT32           dwMedal; //��ǰ����ѫ��
}PKT_CLIGS_GET_MASTER_BOOK_ACK;

typedef struct tagPKT_CLIGS_WIPE_MASTER_BOOK_REQ{
	tagPKT_CLIGS_WIPE_MASTER_BOOK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_WIPE_MASTER_BOOK_REQ)); }
	DT_MASTER_EXP_BOOK_PANEL_CLI stExpBookPanelData; //�ι��������Ϣ
}PKT_CLIGS_WIPE_MASTER_BOOK_REQ;

typedef struct tagPKT_CLIGS_WIPE_MASTER_BOOK_ACK{
	tagPKT_CLIGS_WIPE_MASTER_BOOK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_WIPE_MASTER_BOOK_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIGS_WIPE_MASTER_BOOK_ACK;

typedef struct tagPKT_CLIGS_MASTER_CHEAT_REQ{
	tagPKT_CLIGS_MASTER_CHEAT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MASTER_CHEAT_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_MASTER_CHEAT_REQ;

typedef struct tagPKT_CLIGS_MASTER_CHEAT_ACK{
	tagPKT_CLIGS_MASTER_CHEAT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MASTER_CHEAT_ACK)); }
	UINT16           wErrCode; //������
	DT_MASTER_EXP_BOOK_DETAIL_CLI astExpBooks[EQUIP_KIND_COUNT]; //��������еľ�����
	UINT32           dwGold; //��ǰԪ��
	DT_MASTER_CHEAT_INFO_CLI stCheatInfo; //�´γ�ǧ��Ϣ
}PKT_CLIGS_MASTER_CHEAT_ACK;

typedef struct tagPKT_CLIGS_CONFIRM_MASTER_BOOK_REQ{
	tagPKT_CLIGS_CONFIRM_MASTER_BOOK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CONFIRM_MASTER_BOOK_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_CONFIRM_MASTER_BOOK_REQ;

typedef struct tagPKT_CLIGS_CONFIRM_MASTER_BOOK_ACK{
	tagPKT_CLIGS_CONFIRM_MASTER_BOOK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CONFIRM_MASTER_BOOK_ACK)); }
	UINT16           wErrCode; //������
	DT_EQUIP_MASTER_DETAIL_CLI astEquipMasterDetail[EQUIP_KIND_COUNT]; //�����4��װ���ľ�ͨ��Ϣ
	DT_MASTER_LEVEL_UP_INFO astLevelUpInfo[EQUIP_KIND_COUNT]; //�����4��װ������������
	UINT16           wCurPlayerLevel; //��ǰ��ҵȼ�
	UINT32           dwOldPower; //ԭʼս��
	UINT32           dwCurPower; //��ǰս��
}PKT_CLIGS_CONFIRM_MASTER_BOOK_ACK;

typedef struct tagPKT_CLIGS_OPEN_BAD_REWARD_REQ{
	tagPKT_CLIGS_OPEN_BAD_REWARD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAD_REWARD_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_BAD_REWARD_REQ;

typedef struct tagPKT_CLIGS_OPEN_BAD_REWARD_ACK{
	tagPKT_CLIGS_OPEN_BAD_REWARD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAD_REWARD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwNeedCoin; //��ҪͭǮ��
	UINT8            byLeftTimes; //ʣ�����
	UINT8            byRewardID1; //����ID1
	UINT32           dwRewardValue1; //����ֵ1
	UINT8            byRewardID2; //����2
	UINT32           dwRewardValue2; //����ֵ2
}PKT_CLIGS_OPEN_BAD_REWARD_ACK;

typedef struct tagPKT_CLIGS_GET_BAD_REWARD_REQ{
	tagPKT_CLIGS_GET_BAD_REWARD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_BAD_REWARD_REQ)); }
	UINT8            byExt; //��ť 0 ȡ�� 1 ȷ��
}PKT_CLIGS_GET_BAD_REWARD_REQ;

typedef struct tagPKT_CLIGS_GET_BAD_REWARD_ACK{
	tagPKT_CLIGS_GET_BAD_REWARD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_BAD_REWARD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byRewardID1; //����ID1
	UINT32           dwRewardValue1; //����ֵ1
	UINT32           dwSyncValue1; //ͬ������1
	UINT8            byRewardID2; //����ID2
	UINT32           dwRewardValue2; //����ֵ2
	UINT32           dwSyncValue2; //ͬ������2
}PKT_CLIGS_GET_BAD_REWARD_ACK;

typedef struct tagDT_COURAGE_INFO_CLI{
	UINT32           dwMaxCourageTimes; //������������
	UINT32           dwLeftCourageTimes; //ʣ����������
	UINT32           dwHelpCourageTimes; //��Э������
	TCHAR            aszHelpCouragePrompt[HELP_COURAGE_LEN]; //Э������
	UINT8            byBattleType; //ս������ 0������ս���� 1��Э��ս��
}DT_COURAGE_INFO_CLI;

typedef struct tagDT_COURAGE_GROUP_LEADER_DATA_CLI{
	TCHAR            aszDispPlayerName[USERNAME_LEN]; //����ǳ�
	UINT16           wLevel; //��ҵȼ�
	UINT16           wKindID; //���ְҵID
}DT_COURAGE_GROUP_LEADER_DATA_CLI;

typedef struct tagDT_COURAGE_GROUP_BASE_DATA_CLI{
	UINT32           dwGroupID; //��ID
	UINT8            byJoinType; //�������� 0��ȫ�� 1�����ɣ�2������
	UINT16           wPlayerMaxNum; //���������
	UINT16           wPlayerNum; //��ǰ��Ҹ���
	DT_COURAGE_GROUP_LEADER_DATA_CLI stLeaderData; //�ӳ���Ϣ
	UINT16           wMinLevel; //������׵ȼ�
	DT_INSTANCE_ID   stInstanceID; //�������
}DT_COURAGE_GROUP_BASE_DATA_CLI;

typedef struct tagDT_COURAGE_GROUP_DATA_CLI_LST{
	UINT16           wTeamNum; //��������
	DT_COURAGE_GROUP_BASE_DATA_CLI astTeamInfo[MAX_COURAGE_GROUP_NUM]; //������Ϣ
}DT_COURAGE_GROUP_DATA_CLI_LST;

typedef struct tagPKT_CLIGS_OPEN_COURAGE_REQ{
	tagPKT_CLIGS_OPEN_COURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_COURAGE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_COURAGE_REQ;

typedef union tagDT_COURAGE_GROUP_UNION_DATA_CLI{
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //���û�ж���
	DT_COURAGE_GROUP_DATA stPlayerGroupData; //����ж���
}DT_COURAGE_GROUP_UNION_DATA_CLI;

typedef struct tagDT_COURAGE_ALL_GROUP_DATA_CLI{
	UINT8            byPlayerGroupType; //������Ϣ����
	DT_COURAGE_GROUP_UNION_DATA_CLI stCourageGroupUnion; //������������
}DT_COURAGE_ALL_GROUP_DATA_CLI;

typedef struct tagPKT_CLIGS_OPEN_COURAGE_ACK{
	tagPKT_CLIGS_OPEN_COURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_COURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwGold; //��ҵ�ǰԪ����
	UINT64           qwCopper; //��ҵ�ǰͭǮ��
	DT_COURAGE_INFO_CLI stPlayerCourageData; //�������������Ϣ
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //�����б�
	UINT16           wMinLevel; //����������׵ȼ�
	UINT64           qwStory; //����
	UINT64           qwMedal; //����ѫ��
	UINT8            bySelect; //ɸѡ������em_Join_Type��
}PKT_CLIGS_OPEN_COURAGE_ACK;

typedef struct tagPKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ{
	tagPKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ;

typedef struct tagDT_COURAGE_CHALLENGE_NUM_DATA{
	UINT16           wChallengeGroupNum; //��ս����
}DT_COURAGE_CHALLENGE_NUM_DATA;

typedef struct tagDT_COURAGE_CHALLENGE_NUM_CLI{
	UINT8            byInstanceNum; //������Ŀ
	DT_COURAGE_CHALLENGE_NUM_DATA astInstanceChallenge[MAX_INSTANCE_PER_TOWN_NUM]; //������ս������Ŀ
}DT_COURAGE_CHALLENGE_NUM_CLI;

typedef struct tagPKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK{
	tagPKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_INSTANCE_ID   stMaxSceneData; //���δ��������
	UINT16           wMaxLevel; //���δ��������Ҫ��ȼ�
	UINT8            byTownNum; //������
	DT_TOWN_INSTANCE_RECORD_DATA_CLI astTownInstanceInfo[MAX_TOWN_PER_SCENE_NUM]; //���򸱱���Ϣ
	UINT16           awChallengeNums[MAX_TOWN_PER_SCENE_NUM]; //�����ж��ٸ���������ս
}PKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK;

typedef struct tagPKT_CLIGS_COURAGE_CREATE_GROUP_REQ{
	tagPKT_CLIGS_COURAGE_CREATE_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_CREATE_GROUP_REQ)); }
	UINT8            byJoinType; //��Ա�������� 0��ȫ�� 1�����ɣ�2������
	DT_INSTANCE_ID   stSceneData; //ѡ�񴴽�����ĸ�����Ϣ
}PKT_CLIGS_COURAGE_CREATE_GROUP_REQ;

typedef struct tagPKT_CLIGS_COURAGE_CREATE_GROUP_ACK{
	tagPKT_CLIGS_COURAGE_CREATE_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_CREATE_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwGroupID; //��ID
}PKT_CLIGS_COURAGE_CREATE_GROUP_ACK;

typedef struct tagDT_COURAGE_HERO_DATA{
	UINT16           wKindID; //�������ID
	UINT16           wLevel; //���ȼ�
	TCHAR            aszDispName[USERNAME_LEN]; //����ǳ�
}DT_COURAGE_HERO_DATA;

typedef struct tagDT_COURAGE_GROUP_HERO_DATA_CLI{
	UINT16           wHeroNum; //�������
	DT_COURAGE_HERO_DATA astHeroData[MAX_HERO_NUM]; //�����Ϣ
}DT_COURAGE_GROUP_HERO_DATA_CLI;

typedef struct tagPKT_CLIGS_COURAGE_OPERATE_HERO_REQ{
	tagPKT_CLIGS_COURAGE_OPERATE_HERO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_OPERATE_HERO_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_OPERATE_HERO_REQ;

typedef struct tagPKT_CLIGS_COURAGE_OPERATE_HERO_ACK{
	tagPKT_CLIGS_COURAGE_OPERATE_HERO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_OPERATE_HERO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_COURAGE_GROUP_HERO_DATA_CLI stHeroData; //�����Ϣ
}PKT_CLIGS_COURAGE_OPERATE_HERO_ACK;

typedef struct tagPKT_CLIGS_COURAGE_CONFIRM_HERO_REQ{
	tagPKT_CLIGS_COURAGE_CONFIRM_HERO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_CONFIRM_HERO_REQ)); }
	UINT16           wKindID; //�������ID
}PKT_CLIGS_COURAGE_CONFIRM_HERO_REQ;

typedef struct tagPKT_CLIGS_COURAGE_CONFIRM_HERO_ACK{
	tagPKT_CLIGS_COURAGE_CONFIRM_HERO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_CONFIRM_HERO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_COURAGE_HERO_DATA stHeroData; //�����Ϣ
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_COURAGE_CONFIRM_HERO_ACK;

typedef struct tagPKT_CLIGS_COURAGE_JOIN_GROUP_REQ{
	tagPKT_CLIGS_COURAGE_JOIN_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_JOIN_GROUP_REQ)); }
	UINT8            byAddBattleType; //����ս����ʽ 0:ѡ����� 1���������
	UINT32           dwGroupID; //��ID
}PKT_CLIGS_COURAGE_JOIN_GROUP_REQ;

typedef struct tagPKT_CLIGS_COURAGE_JOIN_GROUP_ACK{
	tagPKT_CLIGS_COURAGE_JOIN_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_JOIN_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_COURAGE_JOIN_GROUP_ACK;

typedef struct tagPKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ{
	tagPKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ)); }
	UINT32           dwPlayerID; //���ID
	UINT32           dwGroupID; //��ID
}PKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ;

typedef struct tagPKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK{
	tagPKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwPlayerID; //���߶�ԱID
	UINT16           wAverageLevel; //����ƽ���ȼ�
}PKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK;

typedef struct tagPKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ{
	tagPKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ;

typedef struct tagPKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK{
	tagPKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byTotalTimes; //������ܹ�����
	UINT64           qwCurGold; //��ǰԪ��
	UINT8            byCurTimes; //��ǰ����
	UINT32           dwNextBuyGold; //�´ι�������Ԫ��
	UINT8            byLeftBuyTimes; //ʣ�๺�����
}PKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_READY_REQ{
	tagPKT_CLIGS_COURAGE_PLAYER_READY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_READY_REQ)); }
	UINT8            byExt; //׼��״̬
}PKT_CLIGS_COURAGE_PLAYER_READY_REQ;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_READY_ACK{
	tagPKT_CLIGS_COURAGE_PLAYER_READY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_READY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byReadyType; //׼������ 0��׼���У� 1���Ѿ�׼��
}PKT_CLIGS_COURAGE_PLAYER_READY_ACK;

typedef struct tagDT_COURAGE_AWARD_DATA{
	UINT64           qwStory; //����
	UINT64           qwMedal; //����ѫ��
}DT_COURAGE_AWARD_DATA;

typedef struct tagDT_COURAGE_PLAYERID_HEROID_DATA{
	UINT32           dwPlayID; //���ID
	UINT16           wHeroID; //���ID
	UINT16           wKindID; //���ְҵID
	UINT8            byBattleType; //ս������ 0������ս���� 1��Э��ս��
	UINT32           dwExperience; //��ҵ�ǰ����
	UINT16           wLevel; //��ҵȼ�
	TCHAR            aszDispPlayerName[USERNAME_LEN]; //����ǳ�
	UINT8            byCurAttackObjIdx; //����ID
	UINT32           dwUpgradeExperience; //�����������
	UINT8            byColor; //�����ɫ
}DT_COURAGE_PLAYERID_HEROID_DATA;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_START_REQ{
	tagPKT_CLIGS_COURAGE_PLAYER_START_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_START_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_PLAYER_START_REQ;

typedef struct tagDT_COURAGE_PLAYER_BATTLE_DATA{
	UINT8            byBattleNum; //ս������
	DT_BATTLE_DATA2  astBattleInfo[MAX_COURAGE_MEMBER_NUM]; //ս����Ϣ
}DT_COURAGE_PLAYER_BATTLE_DATA;

typedef struct tagDT_COURAGE_PLAYER_BATTLE_DATA2{
	UINT8            byBattleNum; //ս������
	DT_BATTLE_DATA3  astBattleInfo[MAX_COURAGE_MEMBER_NUM]; //ս����Ϣ
}DT_COURAGE_PLAYER_BATTLE_DATA2;

typedef struct tagDT_COURAGE_GROUP_PLAYER_BATTLE_DATA{
	UINT8            byPlayerNum; //�������
	DT_COURAGE_PLAYERID_HEROID_DATA astPlayerInfo[MAX_COURAGE_MEMBER_NUM]; //�����Ϣ
}DT_COURAGE_GROUP_PLAYER_BATTLE_DATA;

typedef struct tagDT_COURAGE_JEWELRY_DATA_LST{
	UINT16           wJewelryNum; //���θ���
	DT_JEWELRY_DATA_CLI astJewelryInfo[MAX_BAG_OPEN_NUM]; //��Ʒ��Ϣ
}DT_COURAGE_JEWELRY_DATA_LST;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_START_ACK2{
	tagPKT_CLIGS_COURAGE_PLAYER_START_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_START_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_MONSTER_DATA_LIST stMonsterInfo; //������Ϣ
	DT_COURAGE_PLAYER_BATTLE_DATA2 stBattleInfoCli; //ս����Ϣ
	DT_COURAGE_GROUP_PLAYER_BATTLE_DATA stGroupPlayerInfo; //������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ�� 0ͨ�� 1��ͨ��
	DT_INSTANCE_ID   stInstanceID; //�������
	DT_COURAGE_JEWELRY_DATA_LST stjewelryInfoLst; //��Ʒ��Ϣ
	UINT8            byHelpID; //Э������ 1�ٽ���1�Σ� 2Э��������1�Σ�3�Ѿ����Ͳ�����������
}PKT_CLIGS_COURAGE_PLAYER_START_ACK2;

typedef struct tagPKT_CLIGS_COURAGE_LEADER_START_NTF2{
	tagPKT_CLIGS_COURAGE_LEADER_START_NTF2() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_LEADER_START_NTF2)); }
	PKT_CLIGS_COURAGE_PLAYER_START_ACK2 stBattleInfo; //ս����Ϣ
}PKT_CLIGS_COURAGE_LEADER_START_NTF2;

typedef struct tagPKT_CLIGS_COURAGE_JOIN_GROUP_NTF{
	tagPKT_CLIGS_COURAGE_JOIN_GROUP_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_JOIN_GROUP_NTF)); }
	UINT32           dwAverageLevel; //����ƽ���ȼ�
	DT_COURAGE_PLAYER_DATA stPlayerGroupData; //�������������Ϣ
}PKT_CLIGS_COURAGE_JOIN_GROUP_NTF;

typedef struct tagPKT_CLIGS_COURAGE_QUIT_GROUP_NTF{
	tagPKT_CLIGS_COURAGE_QUIT_GROUP_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_QUIT_GROUP_NTF)); }
	UINT16           wAverageLevel; //����ƽ���ȼ�
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_COURAGE_QUIT_GROUP_NTF;

typedef struct tagDT_COURAGE_PLAYER_HERO_NTF_DATA{
	UINT32           dwPlayerID; //���ID
	UINT32           dwHeroID; //���ID
}DT_COURAGE_PLAYER_HERO_NTF_DATA;

typedef struct tagPKT_CLIGS_COURAGE_OPERATE_HERO_NTF{
	tagPKT_CLIGS_COURAGE_OPERATE_HERO_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_OPERATE_HERO_NTF)); }
	DT_COURAGE_PLAYER_DATA stPlayerGroupData; //���Ļ��������Ϣ
}PKT_CLIGS_COURAGE_OPERATE_HERO_NTF;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_READY_NTF{
	tagPKT_CLIGS_COURAGE_PLAYER_READY_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_READY_NTF)); }
	UINT32           dwPlayerID; //���ID
	UINT8            byReadyType; //׼������ 0���Ѿ�׼���� 1��׼����
}PKT_CLIGS_COURAGE_PLAYER_READY_NTF;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_FIRED_NTF{
	tagPKT_CLIGS_COURAGE_PLAYER_FIRED_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_FIRED_NTF)); }
	UINT8            byErrCode; //���ߴ�����
	DT_COURAGE_INFO_CLI stPlayerCourageData; //�������������Ϣ
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //������Ϣ�б�
}PKT_CLIGS_COURAGE_PLAYER_FIRED_NTF;

typedef struct tagPKT_CLIGS_COURAGE_LEAVE_GROUP_REQ{
	tagPKT_CLIGS_COURAGE_LEAVE_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_LEAVE_GROUP_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_LEAVE_GROUP_REQ;

typedef struct tagPKT_CLIGS_COURAGE_LEAVE_GROUP_ACK{
	tagPKT_CLIGS_COURAGE_LEAVE_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_LEAVE_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwGold; //��ҵ�ǰԪ����
	UINT64           qwCopper; //��ҵ�ǰͭǮ��
	DT_COURAGE_INFO_CLI stPlayerCourageData; //�������������Ϣ
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //������Ϣ�б�
}PKT_CLIGS_COURAGE_LEAVE_GROUP_ACK;

typedef struct tagPKT_CLIGS_OPEN_COURAGE_SHOP_REQ{
	tagPKT_CLIGS_OPEN_COURAGE_SHOP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_COURAGE_SHOP_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδ��
}PKT_CLIGS_OPEN_COURAGE_SHOP_REQ;

typedef struct tagPKT_CLIGS_OPEN_COURAGE_SHOP_ACK{
	tagPKT_CLIGS_OPEN_COURAGE_SHOP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_COURAGE_SHOP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byLeftBuyTimes; //ʣ�๺�����
	UINT32           dwBuyGold; //��������Ԫ��
	UINT64           qwCurGold; //��ǰԪ��
}PKT_CLIGS_OPEN_COURAGE_SHOP_ACK;

typedef struct tagPKT_CLIGS_PLAYER_FACTION_BATTLELOG_NTF{
	tagPKT_CLIGS_PLAYER_FACTION_BATTLELOG_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_FACTION_BATTLELOG_NTF)); }
	UINT8            byUnReadLogNum; //�������ս����Ϣ
	UINT8            byLastOperateType; //����������
}PKT_CLIGS_PLAYER_FACTION_BATTLELOG_NTF;

typedef struct tagPKT_CLIGS_PLAYER_FACTION_READ_REQ{
	tagPKT_CLIGS_PLAYER_FACTION_READ_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_FACTION_READ_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_PLAYER_FACTION_READ_REQ;

typedef struct tagPKT_CLIGS_PLAYER_FACTION_READ_ACK{
	tagPKT_CLIGS_PLAYER_FACTION_READ_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_FACTION_READ_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byLogNum; //ս������
	DT_PLAYER_FACTION_BATTLELOG_DATA astPlayerFactionLogList[MAX_FACTION_BATTLE_LOG_NUM]; //ս����Ϣ
}PKT_CLIGS_PLAYER_FACTION_READ_ACK;

typedef struct tagPKT_CLIGS_OPEN_FIND_DRINK_REQ{
	tagPKT_CLIGS_OPEN_FIND_DRINK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FIND_DRINK_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_OPEN_FIND_DRINK_REQ;

typedef struct tagPKT_CLIGS_OPEN_FIND_DRINK_ACK{
	tagPKT_CLIGS_OPEN_FIND_DRINK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FIND_DRINK_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIGS_OPEN_FIND_DRINK_ACK;

typedef struct tagPKT_CLIGS_COURAGE_BATTLE_REQ{
	tagPKT_CLIGS_COURAGE_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_BATTLE_REQ)); }
	UINT8            byMonsterIndex; //�ڼ�����
}PKT_CLIGS_COURAGE_BATTLE_REQ;

typedef struct tagPKT_CLIGS_COURAGE_BATTLE_ACK{
	tagPKT_CLIGS_COURAGE_BATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_BATTLE_ACK)); }
	UINT16           wErrCode; //������
	DT_BATTLE_DATA2  stBattleInfo; //ս����Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_COURAGE_AWARD_DATA stCourageAwardInfo; //������Ϣ
}PKT_CLIGS_COURAGE_BATTLE_ACK;

typedef struct tagPKT_CLIGS_COURAGE_BATTLE_NTF{
	tagPKT_CLIGS_COURAGE_BATTLE_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_BATTLE_NTF)); }
	UINT16           wErrCode; //������
	DT_BATTLE_DATA2  stBattleInfo; //ս����Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_COURAGE_AWARD_DATA stCourageAwardInfo; //������Ϣ
}PKT_CLIGS_COURAGE_BATTLE_NTF;

typedef struct tagPKT_CLIGS_OPEN_FACTION_BUILD_GROUP_REQ{
	tagPKT_CLIGS_OPEN_FACTION_BUILD_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_BUILD_GROUP_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_FACTION_BUILD_GROUP_REQ;

typedef struct tagPKT_CLIGS_OPEN_FACTION_BUILD_GROUP_ACK{
	tagPKT_CLIGS_OPEN_FACTION_BUILD_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_BUILD_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_BUILD_LEVEL stBuildFlag; //���ɽ�����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	UINT8            byFactionLevel; //���ɵȼ�
	UINT32           dwFactionFunds; //�����ʽ�
	UINT32           dwMyDoorTribute; //�ҵ��Ź�
	TCHAR            aszFactionName[MAX_FACTION_NAME_LEN]; //��������
	DT_FACTION_BUILD_LEVEL stCurBuildLevel; //���ɸ�������ǰ�ȼ�
	TCHAR            aszNewFactionName[MAX_FACTION_NUM]; //��������(��ֹΪ׼)
	UINT8            byFactionIconID; //��ǰ����ͷ��ID
	UINT8            byEditFacName; //�Ƿ���޸���������
	TCHAR            aszEditFacName[MAX_EDIT_LEN]; //�޸�����������Ϣ
	UINT8            byUnDisplayBuildNum; //��������
	UINT8            abyUnDisplayBuildID[16]; //�����Ƿ���ʾ
}PKT_CLIGS_OPEN_FACTION_BUILD_GROUP_ACK;

typedef struct tagPKT_CLIGS_COURAGE_GROUP_DISMISS_NTF{
	tagPKT_CLIGS_COURAGE_GROUP_DISMISS_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GROUP_DISMISS_NTF)); }
	UINT8            byErrCode; //��ɢ֪ͨ������
	DT_COURAGE_INFO_CLI stPlayerCourageData; //�������������Ϣ
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //������Ϣ�б�
}PKT_CLIGS_COURAGE_GROUP_DISMISS_NTF;

typedef struct tagPKT_CLIGS_HOT_SPRING_REWARD_NTF{
	tagPKT_CLIGS_HOT_SPRING_REWARD_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_HOT_SPRING_REWARD_NTF)); }
	UINT8            byRewardID1; //����ID1
	UINT16           wEachReward1; //�������ν���ֵ1
	UINT16           wSumReward1; //����ȡ����ֵ1
	UINT8            byRewardID2; //����ID1
	UINT16           wEachReward2; //�������ν���ֵ1
	UINT16           wSumReward2; //����ȡ����ֵ1
}PKT_CLIGS_HOT_SPRING_REWARD_NTF;

typedef struct tagPKT_CLIGS_COURAGE_GROUP_REFRESH_REQ{
	tagPKT_CLIGS_COURAGE_GROUP_REFRESH_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GROUP_REFRESH_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_COURAGE_GROUP_REFRESH_REQ;

typedef struct tagPKT_CLIGS_COURAGE_GROUP_REFRESH_ACK{
	tagPKT_CLIGS_COURAGE_GROUP_REFRESH_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GROUP_REFRESH_ACK)); }
	UINT16           wErrCode; //������
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //������Ϣ�б�
}PKT_CLIGS_COURAGE_GROUP_REFRESH_ACK;

typedef struct tagPKT_CLIGS_COURAGE_ENTER_GROUP_REQ{
	tagPKT_CLIGS_COURAGE_ENTER_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_ENTER_GROUP_REQ)); }
	UINT8            byExt; //��չ
}PKT_CLIGS_COURAGE_ENTER_GROUP_REQ;

typedef struct tagPKT_CLIGS_COURAGE_ENTER_GROUP_ACK{
	tagPKT_CLIGS_COURAGE_ENTER_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_ENTER_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_COURAGE_GROUP_DATA stGroupData; //��������������Ϣ
}PKT_CLIGS_COURAGE_ENTER_GROUP_ACK;

typedef struct tagPKT_CLIGS_LEAVE_COURAGE_REQ{
	tagPKT_CLIGS_LEAVE_COURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_COURAGE_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_LEAVE_COURAGE_REQ;

typedef struct tagPKT_CLIGS_LEAVE_COURAGE_ACK{
	tagPKT_CLIGS_LEAVE_COURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_COURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_LEAVE_COURAGE_ACK;

typedef struct tagPKT_CLIGS_HOT_SPRING_OVER_REWARD_REQ{
	tagPKT_CLIGS_HOT_SPRING_OVER_REWARD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_HOT_SPRING_OVER_REWARD_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_HOT_SPRING_OVER_REWARD_REQ;

typedef struct tagPKT_CLIGS_HOT_SPRING_OVER_REWARD_ACK{
	tagPKT_CLIGS_HOT_SPRING_OVER_REWARD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_HOT_SPRING_OVER_REWARD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_HOT_SPRING_OVER_REWARD_ACK;

typedef struct tagPKT_CLIGS_OPEN_GOLD_NTF{
	tagPKT_CLIGS_OPEN_GOLD_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GOLD_NTF)); }
	UINT8            byOpenFlag; //����״̬ 0 Ϊ �ر� 1Ϊ����
}PKT_CLIGS_OPEN_GOLD_NTF;

typedef struct tagPKT_CLIGS_HUNTING_ITEGRAL_REQ{
	tagPKT_CLIGS_HUNTING_ITEGRAL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_HUNTING_ITEGRAL_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_HUNTING_ITEGRAL_REQ;

typedef struct tagPKT_CLIGS_HUNTING_ITEGRAL_ACK{
	tagPKT_CLIGS_HUNTING_ITEGRAL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_HUNTING_ITEGRAL_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_HUNTING_SCHEDULE_INFO stScheduleInfo; //���������Ϣ
	UINT8            byIsChangeFlag; //�Ƿ�䵵��0 û�У� 1 �б䵵��
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
}PKT_CLIGS_HUNTING_ITEGRAL_ACK;

typedef struct tagPKT_CLIGS_ACTIVITY_END_NTF{
	tagPKT_CLIGS_ACTIVITY_END_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_ACTIVITY_END_NTF)); }
	UINT8            byBuildID; //����ID
	UINT8            byFuncTypeID; //����ID
}PKT_CLIGS_ACTIVITY_END_NTF;

typedef struct tagPKT_CLIGS_PROMPT_IGNORE_REQ{
	tagPKT_CLIGS_PROMPT_IGNORE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PROMPT_IGNORE_REQ)); }
	UINT8            byActiviID; //�����ID
}PKT_CLIGS_PROMPT_IGNORE_REQ;

typedef struct tagPKT_CLIGS_PROMPT_IGNORE_ACK{
	tagPKT_CLIGS_PROMPT_IGNORE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PROMPT_IGNORE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byActiviID; //�����ID
}PKT_CLIGS_PROMPT_IGNORE_ACK;

typedef struct tagPKT_CLIGS_COURAGE_GROUP_REFRESH_NTF{
	tagPKT_CLIGS_COURAGE_GROUP_REFRESH_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GROUP_REFRESH_NTF)); }
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //������Ϣ�б�
}PKT_CLIGS_COURAGE_GROUP_REFRESH_NTF;

typedef struct tagPKT_CLIGS_HOME_BUILD_PROMPT_NTF{
	tagPKT_CLIGS_HOME_BUILD_PROMPT_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_HOME_BUILD_PROMPT_NTF)); }
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_HOME_BUILD_PROMPT_NTF;

typedef struct tagPKT_CLIGS_OPEN_LEAVE_HOT_SPRING_REQ{
	tagPKT_CLIGS_OPEN_LEAVE_HOT_SPRING_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_LEAVE_HOT_SPRING_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_LEAVE_HOT_SPRING_REQ;

typedef struct tagPKT_CLIGS_OPEN_LEAVE_HOT_SPRING_ACK{
	tagPKT_CLIGS_OPEN_LEAVE_HOT_SPRING_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_LEAVE_HOT_SPRING_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	TCHAR            aszPromptMsg[MAX_LEAVE_HOT_SPRING_PROMPT_MSG]; //������ʾ��Ϣ
}PKT_CLIGS_OPEN_LEAVE_HOT_SPRING_ACK;

typedef struct tagPKT_CLIGS_FACTION_OPERATE_NTF{
	tagPKT_CLIGS_FACTION_OPERATE_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_OPERATE_NTF)); }
	UINT8            byFactionLogType; //��־���� em_Faction_BattleLog_Type
}PKT_CLIGS_FACTION_OPERATE_NTF;

typedef struct tagPKT_CLIGS_FACTION_PROMPT_NTF{
	tagPKT_CLIGS_FACTION_PROMPT_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_PROMPT_NTF)); }
	DT_FUNC_COMMON_PROMPT stFactionPrompt; //������ʾ����
}PKT_CLIGS_FACTION_PROMPT_NTF;

typedef struct tagPKT_CLIGS_COURAGE_GET_AWARD_REQ{
	tagPKT_CLIGS_COURAGE_GET_AWARD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GET_AWARD_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_GET_AWARD_REQ;

typedef struct tagPKT_CLIGS_COURAGE_GET_AWARD_ACK{
	tagPKT_CLIGS_COURAGE_GET_AWARD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GET_AWARD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_COURAGE_GET_AWARD_ACK;

typedef struct tagPKT_CLIGS_COURAGE_GET_BATTLE_RESULT_REQ{
	tagPKT_CLIGS_COURAGE_GET_BATTLE_RESULT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GET_BATTLE_RESULT_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_GET_BATTLE_RESULT_REQ;

typedef struct tagPKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK{
	tagPKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byHavePass; //�Ƿ�ͨ�� 0ͨ�� 1ûͨ��
	DT_COURAGE_GROUP_PLAYER_BATTLE_DATA stGroupPlayerInfo; //������Ϣ
	DT_COURAGE_JEWELRY_DATA_LST stjewelryInfoLst; //��Ʒ��Ϣ
	UINT8            byHelpID; //Э������ 1�ٽ���1�Σ� 2Э��������1�Σ�3�Ѿ����Ͳ�����������
}PKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK;

typedef struct tagPKT_CLIGS_DOORSTRIBUTE_SYNC_NTF{
	tagPKT_CLIGS_DOORSTRIBUTE_SYNC_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_DOORSTRIBUTE_SYNC_NTF)); }
	UINT32           dwCurDoorTribute; //��ǰ�Ź�
	UINT64           qwSumDoorsTribute; //�ۻ��Ź�
}PKT_CLIGS_DOORSTRIBUTE_SYNC_NTF;

typedef struct tagPKT_CLIGS_AUDIT_FACTION_REQ2{
	tagPKT_CLIGS_AUDIT_FACTION_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_AUDIT_FACTION_REQ2)); }
	UINT32           dwAuditPlayerID; //���ID
	UINT8            byAuditWay; //��˷�ʽ�� 1 ͨ����0 �ܾ�
}PKT_CLIGS_AUDIT_FACTION_REQ2;

typedef struct tagPKT_CLIGS_AUDIT_FACTION_ACK2{
	tagPKT_CLIGS_AUDIT_FACTION_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_AUDIT_FACTION_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwAuditPlayerID; //���ID
	UINT8            byAuditWay; //��˷�ʽ�� 1 ͨ����0 �ܾ� )
	UINT16           wFactionCurPlayerNum; //���ɵ�ǰ����
	UINT16           wFactionMaxPlayerNum; //�����������
	UINT16           wLeftAuditPlayerNum; //���ɽ��컹���������
	UINT16           wLeftApplyNum; //����б�ʣ������
}PKT_CLIGS_AUDIT_FACTION_ACK2;

typedef struct tagDT_CROP_FIELD_INFO_DATA2{
	UINT8            byOpen; //��ؿ���
	UINT8            byLevel; //��Ҫ�ĵȼ�
	UINT32           dwCoin; //���ѵ�ͭ��
	UINT32           dwGold; //���ѵ�Ԫ��
	UINT8            byFieldLevel; //��صȼ� Ĭ��Ϊ1��
	UINT8            byCanUpgrade; //�Ƿ������ 0Ϊ�������� 1Ϊ������
	UINT32           dwUpGold; //�������軨�ѵ�Ԫ��
	UINT32           dwCurSeedNum; //��ǰ��صȼ��ɲ�������
	UINT32           dwNexSeedNum; //������غ�ɲ�������
	UINT8            byNeedVipLevel; //��������Vip�ȼ�
}DT_CROP_FIELD_INFO_DATA2;

typedef struct tagDT_CROP_MORE_INFO_DATA2{
	UINT16           wCropKindID; //��ֲID
	UINT32           dwCropTime; //�ջ񵹼�ʱ��
	UINT8            byCropType; //��ֲ����
	UINT32           dwCropValue; //��������
	UINT16           wCropGainKindID; //�������ƷID
	UINT32           dwCropNum; //��ֲ����
}DT_CROP_MORE_INFO_DATA2;

typedef struct tagPKT_CLIGS_OPEN_CROP_REQ2{
	tagPKT_CLIGS_OPEN_CROP_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_REQ2)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_CROP_REQ2;

typedef struct tagPKT_CLIGS_OPEN_CROP_ACK2{
	tagPKT_CLIGS_OPEN_CROP_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byCropSeedNum; //���Ӹ���
	DT_CROP_SEED_INFO_DATA astCropSeedInfoList[MAX_CROP_SEED_NUM]; //������Ϣ
	DT_CROP_FIELD_INFO_DATA2 astCropFieldInfoList[MAX_CROP_NUM]; //�����Ϣ
	DT_CROP_MORE_INFO_DATA2 astCropMoreInfoList[MAX_CROP_NUM]; //��ֲ��Ϣ
	UINT16           wNoCDGoldPerMin; //�������ÿ��������Ԫ��
	UINT8            byBagFullFlag; //�����Ƿ�����1Ϊ��
	UINT64           qwGold; //Ԫ��
	UINT64           qwCoin; //ͭǮ
	UINT64           qwScience; //����
	UINT64           qwStory; //����
	UINT64           qwJingJie; //����
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
}PKT_CLIGS_OPEN_CROP_ACK2;

typedef struct tagPKT_CLIGS_OPEN_CROP_FIELD_REQ2{
	tagPKT_CLIGS_OPEN_CROP_FIELD_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_FIELD_REQ2)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_OPEN_CROP_FIELD_REQ2;

typedef struct tagPKT_CLIGS_OPEN_CROP_FIELD_ACK2{
	tagPKT_CLIGS_OPEN_CROP_FIELD_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CROP_FIELD_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	DT_CROP_FIELD_INFO_DATA2 stCropFieldInfo; //�����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_OPEN_CROP_FIELD_ACK2;

typedef struct tagPKT_CLIGS_CROP_REQ2{
	tagPKT_CLIGS_CROP_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_CROP_REQ2)); }
	UINT8            byFieldID; //���ID
	UINT16           wCropKindID; //����ID
	UINT32           dwSeedNum; //��������
}PKT_CLIGS_CROP_REQ2;

typedef struct tagPKT_CLIGS_CROP_ACK2{
	tagPKT_CLIGS_CROP_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_CROP_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	DT_CROP_MORE_INFO_DATA2 stCropMoreInfo; //��ֲ��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_CROP_FIELD_INFO_DATA2 stCropFieldInfo; //�����Ϣ
}PKT_CLIGS_CROP_ACK2;

typedef struct tagPKT_CLIGS_GAIN_CROP_REQ2{
	tagPKT_CLIGS_GAIN_CROP_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_GAIN_CROP_REQ2)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_GAIN_CROP_REQ2;

typedef struct tagPKT_CLIGS_GAIN_CROP_ACK2{
	tagPKT_CLIGS_GAIN_CROP_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_GAIN_CROP_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCoin; //ͭǮ
	UINT64           qwScience; //����
	UINT64           qwStory; //����
	UINT64           qwJingJie; //����
	UINT8            byCropType; //��ֲ����
	UINT32           dwCropValue; //��������
	UINT16           wCropKindID; //������ƷID
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_CROP_MORE_INFO_DATA2 stCropMoreInfo; //��ֲ��Ϣ
	DT_CROP_FIELD_INFO_DATA2 stCropFieldInfo; //�����Ϣ
}PKT_CLIGS_GAIN_CROP_ACK2;

typedef struct tagPKT_CLIGS_CLR_CROP_REQ2{
	tagPKT_CLIGS_CLR_CROP_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_CROP_REQ2)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_CLR_CROP_REQ2;

typedef struct tagPKT_CLIGS_CLR_CROP_ACK2{
	tagPKT_CLIGS_CLR_CROP_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_CROP_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	UINT64           qwGold; //Ԫ��
	DT_CROP_MORE_INFO_DATA2 stCropMoreInfo; //��ֲ��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_CLR_CROP_ACK2;

typedef struct tagPKT_CLIGS_UPGRADE_CROP_FIELD_REQ{
	tagPKT_CLIGS_UPGRADE_CROP_FIELD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_CROP_FIELD_REQ)); }
	UINT8            byFieldID; //���ID
}PKT_CLIGS_UPGRADE_CROP_FIELD_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_CROP_FIELD_ACK{
	tagPKT_CLIGS_UPGRADE_CROP_FIELD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_CROP_FIELD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFieldID; //���ID
	UINT64           qwGold; //��ǰԪ��
	DT_CROP_FIELD_INFO_DATA stCropFieldInfo; //�����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_UPGRADE_CROP_FIELD_ACK;

typedef struct tagPKT_CLIGS_AUDIT_ALL_REFUSE_REQ{
	tagPKT_CLIGS_AUDIT_ALL_REFUSE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_AUDIT_ALL_REFUSE_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_AUDIT_ALL_REFUSE_REQ;

typedef struct tagPKT_CLIGS_AUDIT_ALL_REFUSE_ACK{
	tagPKT_CLIGS_AUDIT_ALL_REFUSE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_AUDIT_ALL_REFUSE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_AUDIT_ALL_REFUSE_ACK;

typedef struct tagDT_FACTION_PLAYER_AUDIT_CLI2{
	UINT32           dwID; //���ΨһID
	UINT16           wHeroKindID; //���佫����
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT16           wLevel; //��ҵȼ�
	UINT32           dwPower; //ս��
	UINT8            byVIPLevel; //VIP�ȼ�
}DT_FACTION_PLAYER_AUDIT_CLI2;

typedef struct tagDT_FACTION_PLAYER_AUDIT_CLI_LST2{
	UINT16           wPlayerNum; //��Ҹ���
	DT_FACTION_PLAYER_AUDIT_CLI2 astFactionPlayerAuditCli[DT_FACTION_PLAYER_NUM]; //������Ϣ
}DT_FACTION_PLAYER_AUDIT_CLI_LST2;

typedef struct tagPKT_CLIGS_OPEN_AUDIT_FACTION_REQ2{
	tagPKT_CLIGS_OPEN_AUDIT_FACTION_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AUDIT_FACTION_REQ2)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_AUDIT_FACTION_REQ2;

typedef struct tagPKT_CLIGS_OPEN_AUDIT_FACTION_ACK2{
	tagPKT_CLIGS_OPEN_AUDIT_FACTION_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AUDIT_FACTION_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_PLAYER_AUDIT_CLI_LST2 stFactionPlayerAuditCliLst; //����б�
	UINT16           wLeftAuditNum; //ʣ���������
	UINT16           wCurPlayerNum; //���ɵ�ǰ����
	UINT16           wMaxPlayerNum; //������������
}PKT_CLIGS_OPEN_AUDIT_FACTION_ACK2;

typedef struct tagDT_VIP_GIFT_EACH_DATA{
	UINT32           dwRequireOldSourceNum; //����Ҫ���ĵľ���Դ����
	UINT32           dwRequireNewSourceNum; //����Ҫ���ĵ�����Դ����
	DT_RES_ITEM_DATA stVipItemData; //��Ʒ������
	UINT16           wVipGiftGetNum; //ÿһVIP�ȼ���Ӧ�Ŀ���ȡ����Ĵ���
}DT_VIP_GIFT_EACH_DATA;

typedef struct tagDT_VIP_GIFT_DATA{
	UINT8            byMaxVipGift; //�����������
	DT_VIP_GIFT_EACH_DATA astVipGiftData[MAX_VIP_GIFT]; //ÿһ���������Ʒ����
}DT_VIP_GIFT_DATA;

typedef struct tagPKT_CLIGS_OPEN_VIP_GIFT_REQ{
	tagPKT_CLIGS_OPEN_VIP_GIFT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_VIP_GIFT_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_VIP_GIFT_REQ;

typedef struct tagPKT_CLIGS_OPEN_VIP_GIFT_ACK{
	tagPKT_CLIGS_OPEN_VIP_GIFT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_VIP_GIFT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwVipMaxLevel; //���VIP�ȼ�
	DT_VIP_GIFT_DATA astGiftItemData[MAX_VIP_LEVEL]; //ÿһVIP�ȼ����������
	UINT32           dwCurVipLevel; //��ǰVIP�ȼ�
}PKT_CLIGS_OPEN_VIP_GIFT_ACK;

typedef struct tagPKT_CLIGS_GET_VIP_GIFT_REQ{
	tagPKT_CLIGS_GET_VIP_GIFT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_VIP_GIFT_REQ)); }
	UINT8            byLevel; //��ȡ������ȼ�
	UINT8            byIndex; //��ȡ���������
}PKT_CLIGS_GET_VIP_GIFT_REQ;

typedef struct tagPKT_CLIGS_GET_VIP_GIFT_ACK{
	tagPKT_CLIGS_GET_VIP_GIFT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_VIP_GIFT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RES_ITEM_DATA stResItemData; //��ý�������Ʒ����
	DT_RSYNC_RES_ITEM_DATA stRsyncResItemData; //��Դ�б�
	UINT8            byVipLevel; //VIP������ݱ���ȼ�
	UINT8            byIndex; //VIP������ݱ������
	UINT16           wVipGiftGetNum; //VIP�����ȡʣ�����
}PKT_CLIGS_GET_VIP_GIFT_ACK;

typedef struct tagDT_RECV_FLOWER_LOG_CLI_EX{
	UINT32           dwSendPlayerID; //�ͻ������ID
	TCHAR            aszSendPlayerName[USERNAME_LEN]; //�ͻ����������
	UINT32           dwKindID; //�ʻ�ID
	UINT64           qwSendTime; //�ͻ���ʱ��
	UINT8            byFlag; //�ͻ���ʱ��0:����ȡ��1��δ��ȡ
	DT_RES_ITEM_DATA stResItemData; //��Դ�б�
	UINT64           qwExpires; //����ʱ��
}DT_RECV_FLOWER_LOG_CLI_EX;

typedef struct tagDT_RECV_FLOWER_LOG_LIST_CLI_EX{
	UINT8            byLogNum; //��¼����
	DT_RECV_FLOWER_LOG_CLI_EX astListData[MAX_RECV_FLOWER_LOG_LIST_ELEM_EX_NUM]; //�б���Ϣ
	UINT8            byAlsoReceive; //���ɽ���
	UINT8            byUnReceiveNum; //δ�ջ�����
}DT_RECV_FLOWER_LOG_LIST_CLI_EX;

typedef struct tagPKT_CLIGS_OPEN_RECV_FLOWER_TAB_REQ{
	tagPKT_CLIGS_OPEN_RECV_FLOWER_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECV_FLOWER_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_RECV_FLOWER_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_RECV_FLOWER_TAB_ACK{
	tagPKT_CLIGS_OPEN_RECV_FLOWER_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECV_FLOWER_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RECV_FLOWER_LOG_LIST_CLI_EX stRecvFlowerLogListCLiEx; //�����ʻ���־
}PKT_CLIGS_OPEN_RECV_FLOWER_TAB_ACK;

typedef struct tagPKT_CLIGS_ACCEPT_FLOWER_REQ{
	tagPKT_CLIGS_ACCEPT_FLOWER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ACCEPT_FLOWER_REQ)); }
	UINT32           dwSendPlayerID; //�ͻ������ID
	UINT64           qwSendTime; //�ͻ���ʱ��
}PKT_CLIGS_ACCEPT_FLOWER_REQ;

typedef struct tagPKT_CLIGS_ACCEPT_FLOWER_ACK{
	tagPKT_CLIGS_ACCEPT_FLOWER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ACCEPT_FLOWER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RES_ITEM_DATA stGainResItemData; //�����Դ�б�
	DT_RSYNC_RES_ITEM_DATA stRsyncResItemData; //ͬ����Դ�б�
	DT_RECV_FLOWER_LOG_LIST_CLI_EX stRecvFlowerLogListCLiEx; //�����ʻ���־
}PKT_CLIGS_ACCEPT_FLOWER_ACK;

typedef struct tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ{
	tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ)); }
	UINT8            byExt; //��չ�ֶ�
}PKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ;

typedef struct tagDT_FRIENDS_CLI{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispName[USERNAME_LEN]; //�����Ϣ
	UINT8            byCareerID; //ְҵID
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT8            bySameFaction; //�Ƿ�ͬһ����
}DT_FRIENDS_CLI;

typedef struct tagDT_ITEM_FLOWER{
	DT_ITEM_DATA_CLI2 stItem; //�ʻ���Ϣ
	DT_RES_ITEM_DATA stResItemData; //������Դ�б�
}DT_ITEM_FLOWER;

typedef struct tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK{
	tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byItemNum; //���߸���
	DT_ITEM_FLOWER   astItemList[MAX_FLOWER_ITEM_NUM]; //������Ϣ
	UINT8            byFriendsNum; //���Ѹ���
	DT_FRIENDS_CLI   astFriendsList[MAX_RELATION_LIST_ELEM_NUM]; //������Ϣ
	UINT8            byAgainNum; //���ͼ��λ�ý���
	DT_RES_ITEM_DATA stResItemData; //������Դ�б�
	UINT8            byUnReceiveNum; //δ�ջ�����
}PKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK;

typedef struct tagPKT_CLIGS_BUY_RAREITEM_REQ2{
	tagPKT_CLIGS_BUY_RAREITEM_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_RAREITEM_REQ2)); }
	UINT32           dwGoodsID; //��ƷID
	UINT8            byLeftTime; //��Ʒʣ�����
}PKT_CLIGS_BUY_RAREITEM_REQ2;

typedef struct tagPKT_CLIGS_BUY_RAREITEM_ACK2{
	tagPKT_CLIGS_BUY_RAREITEM_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_RAREITEM_ACK2)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_RAREITEM_INFO_CLI stRareItemInfo; //�ܺ���Ʒ��Ϣ
	UINT32           dwLeftDoorsTributes; //���ʣ���Ź�
}PKT_CLIGS_BUY_RAREITEM_ACK2;

typedef struct tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ2{
	tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ2)); }
	UINT32           dwSkillID; //����ID
	UINT8            bySkillCurLevel; //���ܵ�ǰ�ȼ�
}PKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ2;

typedef struct tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK2{
	tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK2)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_SKILL_CLI_INFO stSkillInfo; //������Ϣ
	UINT32           dwLeftDoorsTribute; //���ʣ���Ź�
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	UINT32           dwSumDoorsTribute; //�ۻ��Ź�Ҫ��
}PKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK2;

typedef struct tagPKT_CLIGS_SEND_FLOWER_EX_REQ{
	tagPKT_CLIGS_SEND_FLOWER_EX_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEND_FLOWER_EX_REQ)); }
	UINT32           dwRecvPlayerID; //�ջ����ID
	UINT32           dwKindID; //�ͻ���ID
}PKT_CLIGS_SEND_FLOWER_EX_REQ;

typedef struct tagPKT_CLIGS_SEND_FLOWER_EX_ACK{
	tagPKT_CLIGS_SEND_FLOWER_EX_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SEND_FLOWER_EX_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI2 astItemList[MAX_FLOWER_ITEM_NUM]; //������Ϣ
	DT_RES_ITEM_DATA stGainResItemData; //�����Դ�б�
	DT_RSYNC_RES_ITEM_DATA stRsyncResItemData; //ͬ����Դ�б�
	UINT8            byAgainNum; //���ͼ��λ�ý���
	DT_RES_ITEM_DATA stResItemData; //������Դ�б�
}PKT_CLIGS_SEND_FLOWER_EX_ACK;

typedef struct tagDT_FACTION_INFO_CLI{
	UINT8            byIconID; //ͷ��ID ��0 Ϊ��ͷ��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT32           dwFactionLevel; //���ɵȼ�
	TCHAR            aszHeadName[NORMAL_MSG_LEN]; //��������
	UINT16           wFactionNumberPeople; //������������
	UINT16           wMaxFactionNumberPeople; //�����������
	UINT32           dwFactionFunds; //�����ʽ�
	UINT8            byAuditNum; //�������е���������
	TCHAR            aszFactionNotice[MAX_FACTION_DESC_NUM]; //����֪ͨ
	TCHAR            aszFactionAnnouncement[MAX_FACTION_DESC_NUM]; //���ɹ���
	UINT32           dwFactionRank; //��������
}DT_FACTION_INFO_CLI;

typedef struct tagDT_FACTION_SELF_INFO_CLI{
	UINT32           dwMyDoorsTribute; //�ҵ��Ź�
	UINT64           qwMySumDoorsTribute; //�ҵ��ۻ��Ź�
	UINT64           qwJoinFactionTime; //��������ʱ��
	UINT8            byRecvFlag; //���콱��־ 0 �����콱�� 1���콱, 2����ȡ
	UINT8            byFindBackDoorsTribute; //�Ƿ��п��һ��Ź� ��0 û�У� 1�У�
	DT_FACTION_AUTHORITY_EX stFactionAuthority; //����Ȩ����Ϣ
}DT_FACTION_SELF_INFO_CLI;

typedef struct tagDT_FACTION_MANAGER_INFO_CLI{
	UINT8            byPlayerJobType; //���ְλID
	TCHAR            aszPlayerName[NORMAL_MSG_LEN]; //�������
}DT_FACTION_MANAGER_INFO_CLI;

typedef struct tagDT_FACTION_MANAGER_INFO_LST_CLI{
	UINT8            byManagerNum; //������Ա����
	DT_FACTION_MANAGER_INFO_CLI astManagerInfo[MAX_FACTION_MANAGER_NUM]; //������Ա��Ϣ
}DT_FACTION_MANAGER_INFO_LST_CLI;

typedef struct tagPKT_CLIGS_OPEN_FACTION_REQ{
	tagPKT_CLIGS_OPEN_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_FACTION_REQ;

typedef struct tagPKT_CLIGS_OPEN_FACTION_ACK{
	tagPKT_CLIGS_OPEN_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_INFO_CLI stFactionInfo; //������Ϣ
	DT_FACTION_MANAGER_INFO_LST_CLI stManagerInfo; //������Ա��Ϣ
	DT_FACTION_SELF_INFO_CLI stPlayerInfo; //������Ϣ
}PKT_CLIGS_OPEN_FACTION_ACK;

typedef struct tagDT_PLAYER_POWER_INFO_LST{
	UINT16           wPlayerNum; //��Ҹ���
	UINT32           adwPowerInfo[DT_FACTION_PLAYER_NUM]; //���ս��
}DT_PLAYER_POWER_INFO_LST;

typedef struct tagPKT_CLIGS_FACTION_PLAYERS_INFO_REQ{
	tagPKT_CLIGS_FACTION_PLAYERS_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_PLAYERS_INFO_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_FACTION_PLAYERS_INFO_REQ;

typedef struct tagPKT_CLIGS_FACTION_PLAYERS_INFO_ACK{
	tagPKT_CLIGS_FACTION_PLAYERS_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FACTION_PLAYERS_INFO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_PLAYER_CLI_LST stFactionPlayerCliLst; //���������Ϣ
	DT_DOORSTRIBUTE_LEVE_DATA_LST stDoorsTributeLst; //���׶��б�
	DT_FACTION_AUTHORITY_EX stFactionAuthority; //����Ȩ����Ϣ
	DT_PLAYER_POWER_INFO_LST stPlayerPowerInfo; //���ս��
}PKT_CLIGS_FACTION_PLAYERS_INFO_ACK;

typedef struct tagPKT_CLIGS_VIEW_FACTION_MEMBERS_REQ{
	tagPKT_CLIGS_VIEW_FACTION_MEMBERS_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_VIEW_FACTION_MEMBERS_REQ)); }
	UINT32           dwFactionID; //����ID
}PKT_CLIGS_VIEW_FACTION_MEMBERS_REQ;

typedef struct tagPKT_CLIGS_VIEW_FACTION_MEMBERS_ACK{
	tagPKT_CLIGS_VIEW_FACTION_MEMBERS_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_VIEW_FACTION_MEMBERS_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_FACTION_MEMBER_INFO_LIST stMemberList; //���������Ϣ
	UINT8            byIsLocalFaction; //�Ƿ񱾷����ɣ�1��/0�񣩣��Ǳ��������޷������Ҳ鿴����������Ϣ
}PKT_CLIGS_VIEW_FACTION_MEMBERS_ACK;

typedef struct tagPKT_CLIGS_OPEN_CHANGE_FACTION_ICON_REQ{
	tagPKT_CLIGS_OPEN_CHANGE_FACTION_ICON_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CHANGE_FACTION_ICON_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_CHANGE_FACTION_ICON_REQ;

typedef struct tagPKT_CLIGS_OPEN_CHANGE_FACTION_ICON_ACK{
	tagPKT_CLIGS_OPEN_CHANGE_FACTION_ICON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_CHANGE_FACTION_ICON_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFreeNum; //ʣ����Ѵ���(��Ϊ0ʱ������Ԫ��)
	UINT32           dwCostGold; //��Ҫ����Ԫ��
	UINT8            byIconID; //��ǰͷ��ID(0Ĭ��)
	UINT64           qwGoldNum; //���Ԫ��
	UINT8            byChangeNum; //��ǰ�ڼ��θ���
}PKT_CLIGS_OPEN_CHANGE_FACTION_ICON_ACK;

typedef struct tagPKT_CLIGS_CHANGE_FACTION_ICON_REQ{
	tagPKT_CLIGS_CHANGE_FACTION_ICON_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_FACTION_ICON_REQ)); }
	UINT8            byIconID; //ͷ��ID
}PKT_CLIGS_CHANGE_FACTION_ICON_REQ;

typedef struct tagPKT_CLIGS_CHANGE_FACTION_ICON_ACK{
	tagPKT_CLIGS_CHANGE_FACTION_ICON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_FACTION_ICON_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byIconID; //�������ͷ��ID
	UINT64           qwGoldSync; //Ԫ��ͬ��
}PKT_CLIGS_CHANGE_FACTION_ICON_ACK;

typedef struct tagPKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ{
	tagPKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ;

typedef struct tagPKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK{
	tagPKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byNormalPercent; //��ͨ�һصİٷֱ�
	UINT8            byPerfectPercent; //�����һصİٷֱ�
	DT_RES_DATA      stNormalCost; //��ͨ�һ�����
	DT_RES_DATA      stPerfectCost; //�����һ�����
	UINT32           dwFindBackDoorsTribute; //���һ��Ź�
}PKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK;

typedef struct tagPKT_CLIGS_FIND_BACK_DOORSTRIBUTE_REQ{
	tagPKT_CLIGS_FIND_BACK_DOORSTRIBUTE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FIND_BACK_DOORSTRIBUTE_REQ)); }
	UINT8            byFindBackType; //�һط�ʽ��0 ��ͨ�һأ� 1�����һأ�
}PKT_CLIGS_FIND_BACK_DOORSTRIBUTE_REQ;

typedef struct tagPKT_CLIGS_FIND_BACK_DOORSTRIBUTE_ACK{
	tagPKT_CLIGS_FIND_BACK_DOORSTRIBUTE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FIND_BACK_DOORSTRIBUTE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwSyncDoorsTribute; //�Ź�ͬ��
}PKT_CLIGS_FIND_BACK_DOORSTRIBUTE_ACK;

typedef struct tagPKT_CLIGS_LEAVE_COURAGE_BATTLE_REQ{
	tagPKT_CLIGS_LEAVE_COURAGE_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_COURAGE_BATTLE_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_LEAVE_COURAGE_BATTLE_REQ;

typedef struct tagPKT_CLIGS_LEAVE_COURAGE_BATTLE_ACK{
	tagPKT_CLIGS_LEAVE_COURAGE_BATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_LEAVE_COURAGE_BATTLE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_LEAVE_COURAGE_BATTLE_ACK;

typedef struct tagPKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ{
	tagPKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ)); }
	UINT32           dwExt; //��չ�ֶ�
}PKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ;

typedef struct tagPKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK{
	tagPKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwGroupID; //������ID
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //�����б�
}PKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK;

typedef struct tagPKT_CLIGS_OPEN_EMBATTLE_REQ2{
	tagPKT_CLIGS_OPEN_EMBATTLE_REQ2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EMBATTLE_REQ2)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_EMBATTLE_REQ2;

typedef struct tagDT_FORMATION_DATA_LEVEL{
	UINT8            byFormationID; //����ID
	UINT8            byFormationLevel; //���͵ȼ�
	UINT8            byFormationType; //���ͼӳ�����(commondef.h EBattleAttributeKind)
	UINT32           dwFormationValue; //���ͼӳ�ֵ
	DT_RES_DATA      stUpgradeCost; //������������
	UINT8            byMaxPlayerNum; //���������������(����λ����)
	UINT8            byIsUpgrade; //��Դ�Ƿ��㹻������0 ������ 1�Ƽ�δ������ 2��Դ���㣬3 ��ҵȼ���������, 4δ��ʾ�󷨣� 5δ�����󷨣� 6������
	UINT8            byNeedPlayerLevel; //�������������ȼ�
}DT_FORMATION_DATA_LEVEL;

typedef struct tagDT_NEW_FORMATION_INFO_CLI{
	UINT8            byFormationID; //����ID
	UINT8            byPostionNum; //λ�ø���
	DT_NEW_FORMATION_POSTION_INFO astPostionInfo[MAX_FORMATION_IDX_NUM]; //λ����Ϣ
	DT_FORMATION_DATA_LEVEL stFormationLevel; //���͵ȼ���Ϣ
}DT_NEW_FORMATION_INFO_CLI;

typedef struct tagDT_NEW_FORMATION_LST_CLI{
	UINT8            bySelectIndex; //ѡ�е�����
	UINT8            byFormationNum; //���͸���
	DT_NEW_FORMATION_INFO_CLI astFormationArray[MAX_NEW_FORMATION_NUM]; //����������Ϣ
}DT_NEW_FORMATION_LST_CLI;

typedef struct tagDT_NEW_HERO_EMBATLE_DATA{
	UINT16           wKindID; //�佫����
	UINT8            byCareerID; //ְҵID
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����
	UINT8            byFormationNum; //���͸���
	UINT32           adwPower[MAX_NEW_FORMATION_NUM]; //ս��
	DT_BATTLE_ATTRIBUTE astBattleAttribute[MAX_NEW_FORMATION_NUM]; //ս������
	DT_SKILL_DATA_CLI stSkillInfo; //������Ϣ
}DT_NEW_HERO_EMBATLE_DATA;

typedef struct tagPKT_CLIGS_OPEN_EMBATTLE_ACK2{
	tagPKT_CLIGS_OPEN_EMBATTLE_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EMBATTLE_ACK2)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroNum; //�佫��Ŀ
	DT_NEW_HERO_EMBATLE_DATA astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	DT_NEW_FORMATION_LST_CLI stFormationInfo; //������Ϣ
	DT_RES_DATA      stCurRes; //��ǰ����
}PKT_CLIGS_OPEN_EMBATTLE_ACK2;

typedef struct tagPKT_CLIGS_OPEN_FORMATION_SCIENCE_REQ{
	tagPKT_CLIGS_OPEN_FORMATION_SCIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FORMATION_SCIENCE_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_FORMATION_SCIENCE_REQ;

typedef struct tagPKT_CLIGS_OPEN_FORMATION_SCIENCE_ACK{
	tagPKT_CLIGS_OPEN_FORMATION_SCIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FORMATION_SCIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFormationNum; //����
	DT_FORMATION_DATA_LEVEL astFormationInfo[MAX_NEW_FORMATION_NUM]; //����Ϣ
	DT_RES_DATA      stCurRes; //��ǰ����
}PKT_CLIGS_OPEN_FORMATION_SCIENCE_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_FORMATION_REQ{
	tagPKT_CLIGS_UPGRADE_FORMATION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_FORMATION_REQ)); }
	UINT8            byFormationID; //��ID
	DT_FORMATION_DATA stFormationInfo; //������Ϣ
}PKT_CLIGS_UPGRADE_FORMATION_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_FORMATION_ACK{
	tagPKT_CLIGS_UPGRADE_FORMATION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_FORMATION_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroNum; //�佫��Ŀ
	DT_NEW_HERO_EMBATLE_DATA astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
	DT_NEW_FORMATION_LST_CLI stFormationInfo; //������Ϣ
	DT_POWER_CHANGE_DATA stPower; //ս���ı����
	DT_FUNC_COMMON_PROMPT stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_RES_DATA      stSyncRes; //����ͬ��
}PKT_CLIGS_UPGRADE_FORMATION_ACK;

typedef struct tagPKT_CLILS_REGISTER_FACTION_REQ{
	tagPKT_CLILS_REGISTER_FACTION_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_FACTION_REQ)); }
	TCHAR            aszDspName[MAX_FACTION_NUM]; //ս���仯��Ϣ
}PKT_CLILS_REGISTER_FACTION_REQ;

typedef struct tagPKT_CLILS_REGISTER_FACTION_ACK{
	tagPKT_CLILS_REGISTER_FACTION_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_FACTION_ACK)); }
	UINT16           wErrCode; //ս���仯��Ϣ
	TCHAR            aszDspName[MAX_FACTION_NUM]; //ս���仯��Ϣ
}PKT_CLILS_REGISTER_FACTION_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_FORMATION_SCIENCE_REQ{
	tagPKT_CLIGS_UPGRADE_FORMATION_SCIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_FORMATION_SCIENCE_REQ)); }
	UINT8            byFormationID; //��ID
}PKT_CLIGS_UPGRADE_FORMATION_SCIENCE_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_FORMATION_SCIENCE_ACK{
	tagPKT_CLIGS_UPGRADE_FORMATION_SCIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_FORMATION_SCIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byFormationNum; //����
	DT_FORMATION_DATA_LEVEL astFormationInfo[MAX_NEW_FORMATION_NUM]; //������Ϣ
	DT_POWER_CHANGE_DATA stPower; //ս���ı����
	DT_FUNC_COMMON_PROMPT stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_RES_DATA      stSyncRes; //����ͬ��
}PKT_CLIGS_UPGRADE_FORMATION_SCIENCE_ACK;

typedef struct tagPKT_CLIGS_GET_BLUE_ENCOURAGE_REQ{
	tagPKT_CLIGS_GET_BLUE_ENCOURAGE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_BLUE_ENCOURAGE_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_GET_BLUE_ENCOURAGE_REQ;

typedef struct tagPKT_CLIGS_GET_BLUE_ENCOURAGE_ACK{
	tagPKT_CLIGS_GET_BLUE_ENCOURAGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_BLUE_ENCOURAGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BEGBLUE_PLAYER_RES_CLI stPlayerResInfo; //��ҵ�ǰ��Դ��Ϣ
	DT_BLUE_ENCOURAGEINFO_CLI stEncourage; //������Ϣ
	UINT32           dwBlue; //��ȡ����¶
}PKT_CLIGS_GET_BLUE_ENCOURAGE_ACK;

typedef struct tagPKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ{
	tagPKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ)); }
	UINT32           dwExprienceValue; //����ȡ���飨�ο�ֵ�����2���ڣ���
}PKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ;

typedef struct tagPKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK{
	tagPKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_HOT_SPRING_EXPERIENCE stPlayerExprience; //������ʾ
	DT_HERO_UPGRADE_DATA stHeroUpgradeInfo; //������Ϣ��ʾ
	UINT32           dwExprienceValue; //��ȡ�ľ���ֵ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
}PKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK;

typedef struct tagPKT_CLIGS_OPEN_FACTION_SKILL_REQ{
	tagPKT_CLIGS_OPEN_FACTION_SKILL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_SKILL_REQ)); }
	UINT8            byExt; //��չ��Ϣ
}PKT_CLIGS_OPEN_FACTION_SKILL_REQ;

typedef struct tagPKT_CLIGS_OPEN_FACTION_SKILL_ACK{
	tagPKT_CLIGS_OPEN_FACTION_SKILL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_SKILL_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_CLI_INFO astSkillInfo[MAX_GYMNASIUM_SKILL_NUM]; //������Ϣ
	UINT8            byStatu; //״̬��0������1δ��������δѧϰ����, 2�������ɣ����ÿ�����δѧϰ���ܣ� 3�������ɣ�����δ������
}PKT_CLIGS_OPEN_FACTION_SKILL_ACK;

typedef struct tagPKT_CLIGS_RESOURCE_SYNC_NTF{
	tagPKT_CLIGS_RESOURCE_SYNC_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_RESOURCE_SYNC_NTF)); }
	DT_RSYNC_RES_ITEM_DATA stResourceSync; //��Դͬ��
}PKT_CLIGS_RESOURCE_SYNC_NTF;

typedef struct tagPKT_CLIGS_OPEN_RESOLVE_TRIGRAM_REQ{
	tagPKT_CLIGS_OPEN_RESOLVE_TRIGRAM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RESOLVE_TRIGRAM_REQ)); }
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
}PKT_CLIGS_OPEN_RESOLVE_TRIGRAM_REQ;

typedef struct tagPKT_CLIGS_OPEN_RESOLVE_TRIGRAM_ACK{
	tagPKT_CLIGS_OPEN_RESOLVE_TRIGRAM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RESOLVE_TRIGRAM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCommonNum; //��ͨ�ֽ��õ���Ƭ����
	UINT16           wSpecialNum; //Ԫ���ֽ��õ���Ƭ����
	UINT32           dwGoldNum; //Ԫ���ֽ�����Ԫ��
	UINT32           dwCoinNum; //��ͨ�ֽ�����ͭǮ
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
}PKT_CLIGS_OPEN_RESOLVE_TRIGRAM_ACK;

typedef struct tagPKT_CLIGS_RESOLVE_TRIGRAM_REQ{
	tagPKT_CLIGS_RESOLVE_TRIGRAM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RESOLVE_TRIGRAM_REQ)); }
	UINT8            byUseGold; //�Ƿ�ʹ��Ԫ�� 1Ϊʹ�ã�0Ϊ��ʹ��
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
}PKT_CLIGS_RESOLVE_TRIGRAM_REQ;

typedef struct tagPKT_CLIGS_RESOLVE_TRIGRAM_ACK{
	tagPKT_CLIGS_RESOLVE_TRIGRAM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RESOLVE_TRIGRAM_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byBagGridIdx; //�����ĵ�λ�ã���0��ʼ
	UINT64           qwStudyClip; //�ܹ��ĵ���Ƭ
	UINT32           dwGetStudyClip; //�ֽ������ĵ���Ƭ
	DT_STUDY_DATA_CLI2 astBagStudyInfo[MAX_BAG_STUDY_GRID_NUM]; //�����ĵ���Ϣ
	UINT64           qwGoldNum; //���Ԫ��
	UINT64           qwCoinNum; //���ͭǮ
	UINT8            byUseGold; //�Ƿ�ʹ��Ԫ�� 1Ϊʹ�ã�0Ϊ��ʹ��
}PKT_CLIGS_RESOLVE_TRIGRAM_ACK;

typedef struct tagDT_JEWELRY_DATA_LST_CLI{
	UINT16           wJewelryNum; //��Ʒ����
	DT_JEWELRY_DATA_CLI astJewelryList[MAX_BAG_OPEN_NUM]; //��Ʒ��Ϣ
}DT_JEWELRY_DATA_LST_CLI;

typedef struct tagDT_SKILL_DATA_LST_CLI{
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_DATA_CLI astSkillInfo[MAX_SKILL_NUM]; //������Ϣ
}DT_SKILL_DATA_LST_CLI;

typedef struct tagDT_HERO_JEWELRY_DATA_LST_CLI{
	UINT16           wJewelryNum; //��Ʒ����
	DT_JEWELRY_DATA_CLI astJewelryList[MAX_JEWELRY_POS]; //��Ʒ��Ϣ
}DT_HERO_JEWELRY_DATA_LST_CLI;

typedef struct tagDT_HERO_DATA_CLI2{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_PANEL_CLI astHeroBaseData[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST_CLI astEquipDataList[MAX_HERO_NUM]; //�佫װ����Ϣ
	DT_ATTR_ENABLE_UPDATE_INFO astEnableAttrUpdate[MAX_HERO_NUM]; //����������Ϣ
	DT_SKILL_DATA_LST_CLI astSkillInfo[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_JEWELRY_DATA_LST_CLI astJewelryInfo[MAX_HERO_NUM]; //��Ʒ��Ϣ
	DT_HERO_SOUL_DATA_LST_CLI astSoulInfo[MAX_HERO_NUM]; //ս����Ϣ
}DT_HERO_DATA_CLI2;

typedef struct tagDT_HERO_DATA_CLI_v410{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_PANEL_CLI astHeroBaseData[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST_CLI_v410 astEquipDataList[MAX_HERO_NUM]; //�佫װ����Ϣ
	DT_ATTR_ENABLE_UPDATE_INFO astEnableAttrUpdate[MAX_HERO_NUM]; //����������Ϣ
	DT_SKILL_DATA_LST_CLI astSkillInfo[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_JEWELRY_DATA_LST_CLI astJewelryInfo[MAX_HERO_NUM]; //��Ʒ��Ϣ
	DT_HERO_SOUL_DATA_LST_CLI astSoulInfo[MAX_HERO_NUM]; //ս����Ϣ
}DT_HERO_DATA_CLI_v410;

typedef struct tagDT_HERO_DATA_CLI2_OLD{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_PANEL_CLI astHeroBaseData[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST_CLI astEquipDataList[MAX_HERO_NUM]; //�佫װ����Ϣ
	DT_ATTR_ENABLE_UPDATE_INFO astEnableAttrUpdate[MAX_HERO_NUM]; //����������Ϣ
	DT_SKILL_DATA_LST_CLI astSkillInfo[MAX_HERO_NUM]; //�佫������Ϣ
	DT_HERO_JEWELRY_DATA_LST_CLI astJewelryInfo[MAX_HERO_NUM]; //��Ʒ��Ϣ
}DT_HERO_DATA_CLI2_OLD;

typedef struct tagDT_JEWELRY_SUIT_LVL_ATTR{
	UINT8            byAttrType; //��װ������𣬼� JewelryExtAttr
	UINT32           dwAttrVal; //��װ����������ֵ
	UINT8            byValType; //��װ�������������ͣ��̶�ֵ���ٷֱȣ��� ValueType
}DT_JEWELRY_SUIT_LVL_ATTR;

typedef struct tagDT_JEWELRY_SUIT_ATTR{
	UINT16           wSuitLvl; //��װ�ȼ�
	DT_JEWELRY_SUIT_LVL_ATTR stLvlAttr; //�ü���Ӧ������
}DT_JEWELRY_SUIT_ATTR;

typedef struct tagDT_JEWELRY_SUIT_CLI{
	UINT16           wSuitLvl; //��װ�ȼ�
	UINT8            bySuitAttrNum; //��װ�ȼ�
	DT_JEWELRY_SUIT_ATTR astSuitAttrLst[MAX_JEWELRY_SUIT_ATTR_NUM]; //��װ���������б�
}DT_JEWELRY_SUIT_CLI;

typedef struct tagDT_JEWELRY_SUIT_LIST_CLI{
	UINT16           wHeroNum; //�����Ϣ
	DT_JEWELRY_SUIT_CLI astSuitList[MAX_HERO_NUM]; //ÿ��������ϵ���Ʒ��װ��Ϣ
}DT_JEWELRY_SUIT_LIST_CLI;

typedef struct tagDT_PLAYER_INFO_PANEL{
	DT_HERO_DATA_CLI2 stHeroInfo; //�����Ϣ
	DT_ITEM_DATA_LIST_CLI3 stItemInfo; //װ����Ϣ��װ������Ƭ������ʯ��
	DT_ITEM_DATA_LIST_CLI3 stJewelryInfo; //������Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
	UINT8            byGoodsCellNum; //װ����ռ�ø����� ����װ���⣬������Ʒռ������
	UINT8            byJewelryCellNum; //��Ʒ��ռ�ø�����(����Ʒ�⣬������Ʒռ����)
	DT_SOUL_DATA_LST_CLI stSoulInfo; //ս�걳��
}DT_PLAYER_INFO_PANEL;

typedef struct tagDT_PLAYER_INFO_PANEL_OLD{
	DT_HERO_DATA_CLI2_OLD stHeroInfo; //�����Ϣ
	DT_ITEM_DATA_LIST_CLI3 stItemInfo; //װ����Ϣ��װ������Ƭ������ʯ��
	DT_ITEM_DATA_LIST_CLI3 stJewelryInfo; //������Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
	UINT8            byGoodsCellNum; //װ����ռ�ø����� ����װ���⣬������Ʒռ������
	UINT8            byJewelryCellNum; //��Ʒ��ռ�ø�����(����Ʒ�⣬������Ʒռ����)
}DT_PLAYER_INFO_PANEL_OLD;

typedef struct tagPKT_CLIGS_OPEN_PLAYER_PANEL_REQ{
	tagPKT_CLIGS_OPEN_PLAYER_PANEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLAYER_PANEL_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_PLAYER_PANEL_REQ;

typedef struct tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK_OLD{
	tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK_OLD() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK_OLD)); }
	UINT16           wErrCode; //������
	DT_PLAYER_INFO_PANEL_OLD stPlayerPanel; //���������Ϣ
	DT_BAG_DATA_CLI  stBagInfo; //����������Ϣ
	UINT16           wCoachExpRate; //���Ǿ��鱶��(�ٷֱ�)
}PKT_CLIGS_OPEN_PLAYER_PANEL_ACK_OLD;

typedef struct tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK{
	tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_INFO_PANEL stPlayerPanel; //���������Ϣ
	DT_BAG_DATA_CLI  stBagInfo; //����������Ϣ
	UINT16           wCoachExpRate; //���Ǿ��鱶��(�ٷֱ�)
}PKT_CLIGS_OPEN_PLAYER_PANEL_ACK;

typedef struct tagDT_PLAYER_INFO_PANEL_v410{
	DT_HERO_DATA_CLI2 stHeroInfo; //�����Ϣ
	DT_ITEM_DATA_LIST_CLI4 stItemInfo; //װ����Ϣ��װ������Ƭ������ʯ��
	DT_ITEM_DATA_LIST_CLI4 stJewelryInfo; //������Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
	UINT16           wGoodsCellNum; //װ����ռ�ø����� ����װ���⣬������Ʒռ������
	UINT16           wJewelryCellNum; //��Ʒ��ռ�ø�����(����Ʒ�⣬������Ʒռ����)
	DT_SOUL_DATA_LST_CLI stSoulInfo; //ս�걳��
}DT_PLAYER_INFO_PANEL_v410;

typedef struct tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410{
	tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410)); }
	UINT16           wErrCode; //������
	DT_PLAYER_INFO_PANEL_v410 stPlayerPanel; //���������Ϣ
	DT_BAG_DATA_CLI2 stBagInfo; //����������Ϣ
	UINT16           wCoachExpRate; //���Ǿ��鱶��(�ٷֱ�)
	DT_JEWELRY_SUIT_LIST_CLI stHeroJewelrySuitInfo; //ÿ��������ϵ���Ʒ��װ��Ϣ
	DT_HERO_LST_SOUL_POTENCY_DATA_LST_CLI stHeroSoulPotencyInfo; //ÿ��������ϵ�ս��Ǳ����Ϣ
	DT_SOUL_POTENCY_DATA_LST_CLI stBagSoulPotencyInfo; //������ս��Ǳ����Ϣ
}PKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410;

typedef struct tagPKT_CLIGS_PLAYER_INFO_AWAKEN_REQ{
	tagPKT_CLIGS_PLAYER_INFO_AWAKEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_AWAKEN_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PLAYER_INFO_AWAKEN_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_AWAKEN_ACK{
	tagPKT_CLIGS_PLAYER_INFO_AWAKEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_AWAKEN_ACK)); }
	UINT16           wErrCode; //������
	UINT16           awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵý����ȼ���Ϣ
	UINT8            byHeroNum; //�佫����
	DT_HERO_STUDY_DATA_CLI2 astHeroStudyInfo[MAX_HERO_NUM]; //�佫�ĵ���Ϣ
	UINT16           awHeroLevel[MAX_HERO_NUM]; //�佫�ȼ�
	UINT8            byAwakenOpenState; //�ĵý�����ʶ(0δ������1 ����)
}PKT_CLIGS_PLAYER_INFO_AWAKEN_ACK;

typedef struct tagPKT_CLIGS_PLAYER_INFO_SKILL_REQ{
	tagPKT_CLIGS_PLAYER_INFO_SKILL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_SKILL_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PLAYER_INFO_SKILL_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_SKILL_ACK{
	tagPKT_CLIGS_PLAYER_INFO_SKILL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_SKILL_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byHeroNum; //�佫����
	DT_SKILL_DATA_LST_CLI astSkillInfo[MAX_HERO_NUM]; //�佫������Ϣ
}PKT_CLIGS_PLAYER_INFO_SKILL_ACK;

typedef struct tagPKT_CLIGS_PLAYER_INFO_GODWEAPON_REQ{
	tagPKT_CLIGS_PLAYER_INFO_GODWEAPON_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_GODWEAPON_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PLAYER_INFO_GODWEAPON_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_GODWEAPON_ACK{
	tagPKT_CLIGS_PLAYER_INFO_GODWEAPON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_GODWEAPON_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wGodweaponNum; //������Ŀ
	DT_GODWEAPON_DATA_CLI astGodweaponLst[MAX_HERO_NUM]; //������Ϣ
	UINT8            abyLockStatu[MAX_HERO_NUM]; //����״̬(0δ������ 1����)
}PKT_CLIGS_PLAYER_INFO_GODWEAPON_ACK;

typedef struct tagPKT_CLIGS_PLAYER_INFO_JEWELRY_REQ{
	tagPKT_CLIGS_PLAYER_INFO_JEWELRY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_JEWELRY_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PLAYER_INFO_JEWELRY_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_JEWELRY_ACK{
	tagPKT_CLIGS_PLAYER_INFO_JEWELRY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_JEWELRY_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byHeroNum; //�佫����
	DT_HERO_JEWELRY_DATA_LST_CLI astJewelryInfo[MAX_HERO_NUM]; //�佫��Ʒ��Ϣ-
	DT_JEWELRY_SUIT_CLI astJewelrySuit[MAX_HERO_NUM]; //�佫��Ʒ��Ϣ-
}PKT_CLIGS_PLAYER_INFO_JEWELRY_ACK;

typedef struct tagPKT_CLIGS_PLAYER_INFO_SOUL_REQ{
	tagPKT_CLIGS_PLAYER_INFO_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_SOUL_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PLAYER_INFO_SOUL_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_SOUL_ACK{
	tagPKT_CLIGS_PLAYER_INFO_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_SOUL_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byHeroNum; //�佫����
	DT_HERO_SOUL_DATA_LST_CLI astSoulInfo[MAX_HERO_NUM]; //ս����Ϣ
	DT_HERO_SOUL_POTENCY_DATA_LST_CLI astSoulPotencyInfo[MAX_HERO_NUM]; //ս��Ǳ����Ϣ
}PKT_CLIGS_PLAYER_INFO_SOUL_ACK;

typedef struct tagPKT_CLIGS_DRESS_JEWELRY_REQ{
	tagPKT_CLIGS_DRESS_JEWELRY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_JEWELRY_REQ)); }
	UINT16           wHeroKindID; //Ҫ�������佫
	UINT8            byDressType; //������ʽ(װ��/ж��/�滻)(commondef.h EDressType)
	UINT16           wDressJewelryID; //Ҫ��������ƷID
	UINT16           wDressItemIdx; //Ҫ������װ�����
	UINT16           wUndressJewelryID; //Ҫж�µ���ƷID(ж�£��滻ʱ��Ч)
	UINT16           wUndressItemIdx; //Ҫж�µ�װ�����(ж�£��滻ʱ��Ч)
	UINT8            byReqPos; //����λ�ã�0 �������, 1�ϳ���壩
}PKT_CLIGS_DRESS_JEWELRY_REQ;

typedef struct tagPKT_CLIGS_DRESS_JEWELRY_ACK{
	tagPKT_CLIGS_DRESS_JEWELRY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_JEWELRY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //Ҫ�������佫
	UINT8            byDressType; //������ʽ(װ��/ж��/�滻)
	UINT16           wDressJewelryID; //Ҫ������װ������
	UINT16           wDressItemIdx; //Ҫ������װ�����
	UINT16           wUndressJewelryID; //Ҫж�µ�װ������(ж�£��滻ʱ��Ч)
	UINT16           wUndressItemIdx; //Ҫж�µ�װ�����(ж�£��滻ʱ��Ч)
	UINT32           dwPlayerHP; //�����Ѫ��
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
	DT_HERO_PANEL_LST_CLI stHeroPanelInfo; //�佫�������Ϣ
	UINT8            byIsDown; //�Ƿ��·�0 ���·��� 1�·�
	DT_JEWELRY_DATA_LST_CLI astJewelryInfo[1]; //������Ϣ
	DT_FUNC_PROMPT_DATA stBuildPrompt; //������ʾ
	DT_JEWELRY_SUIT_CLI stJewelrySuitInfo; //������Ϣ
}PKT_CLIGS_DRESS_JEWELRY_ACK;

typedef struct tagPKT_CLIGS_OPEN_HERO_SELECT_PANEL_REQ{
	tagPKT_CLIGS_OPEN_HERO_SELECT_PANEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HERO_SELECT_PANEL_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_HERO_SELECT_PANEL_REQ;

typedef struct tagPKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK{
	tagPKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_BASE_DATA_CLI astHeroBaseData[MAX_HERO_NUM]; //�佫������Ϣ
	UINT8            abyFlyFlagList[MAX_HERO_NUM]; //�Ƿ�ɷ������飺�ɷ���true/���ɷ���false
}PKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK;

typedef struct tagPKT_CLIGS_OPEN_JEWELRY_GENERATE_REQ{
	tagPKT_CLIGS_OPEN_JEWELRY_GENERATE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JEWELRY_GENERATE_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_JEWELRY_GENERATE_REQ;

typedef struct tagPKT_CLIGS_OPEN_JEWELRY_GENERATE_ACK{
	tagPKT_CLIGS_OPEN_JEWELRY_GENERATE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JEWELRY_GENERATE_ACK)); }
	UINT16           wErrCode; //������
	DT_JEWELRY_DATA_LST_CLI stJewelryInfo; //������Ϣ
	DT_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_OPEN_JEWELRY_GENERATE_ACK;

typedef struct tagPKT_CLIGS_JEWELRY_GENERATE_REQ{
	tagPKT_CLIGS_JEWELRY_GENERATE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_GENERATE_REQ)); }
	UINT16           wFirstID; //��һ����ƷID��ֵΪ0ʱû����Ʒ��
	UINT16           wFirstIdx; //��һ����ƷIdx
	UINT16           wSecondID; //�ڶ�����ƷID
	UINT16           wSecondIdx; //�ڶ�����ƷIdx
	UINT16           wThirdID; //��������ƷID
	UINT16           wThirdIdx; //��������ƷIdx
	UINT16           wFourthID; //���ĸ���ƷID
	UINT16           wFourthIdx; //���ĸ���ƷIdx
}PKT_CLIGS_JEWELRY_GENERATE_REQ;

typedef struct tagPKT_CLIGS_JEWELRY_GENERATE_ACK{
	tagPKT_CLIGS_JEWELRY_GENERATE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_GENERATE_ACK)); }
	UINT16           wErrCode; //������
	DT_JEWELRY_DATA_CLI stJewelryInfo; //������Ʒ����Ϣ
	DT_JEWELRY_DATA_LST_CLI stBagJewelryInfo; //ͬ��������Ʒ��Ϣ
	DT_RSYNC_RES_ITEM_DATA stResourceSnyc; //��Դͬ����Ϣ
	DT_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
	DT_JEWELRY_DATA_CLI stCompareJewelry; //�Աȵ���Ʒ(�����ڻ������)
}PKT_CLIGS_JEWELRY_GENERATE_ACK;

typedef struct tagDT_STRENGTH_INFO{
	UINT16           wItemID; //����ID
	UINT32           dwCostItemNum; //���߸���
	UINT32           dwCurItemNum; //���ߵ�ǰ����
	DT_PLAYER_RES_DATA stCostRes; //��Ʒ��������(����)
}DT_STRENGTH_INFO;

typedef struct tagDT_STRENGTH_LST_INFO{
	UINT8            byItemKindNum; //�����������
	DT_STRENGTH_INFO astItemInfo[MAX_JEWELRY_STRENG_NUM]; //ǿ��������Ϣ
}DT_STRENGTH_LST_INFO;

typedef struct tagPKT_CLIGS_JEWELRY_STRENGTH_REQ{
	tagPKT_CLIGS_JEWELRY_STRENGTH_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_STRENGTH_REQ)); }
	UINT16           wJewelryID; //��һ����ƷID��ֵΪ0ʱû����Ʒ��
	UINT16           wJewelryIdx; //��һ����ƷIdx
}PKT_CLIGS_JEWELRY_STRENGTH_REQ;

typedef struct tagPKT_CLIGS_JEWELRY_STRENGTH_ACK{
	tagPKT_CLIGS_JEWELRY_STRENGTH_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_STRENGTH_ACK)); }
	UINT16           wErrCode; //������
	DT_JEWELRY_DATA_CLI stAfterJewelryInfo; //ǿ�������Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
	DT_JEWELRY_DATA_CLI stStrengthJewelry; //ǿ�������Ʒ��Ϣ�б�
	DT_STRENGTH_INFO stStringth; //ǿ������
	UINT8            byMaxMark; //ǿ�����ޱ�ʶ��0δ�ﵽ���ޣ� 1�Ѵﵽ���ޣ�
	DT_FUNC_PROMPT_DATA stBuildPrompt; //������ʾ
	DT_STRENGTH_LST_INFO stJewelryStrengResSync; //��Ʒ����ʯͬ��
}PKT_CLIGS_JEWELRY_STRENGTH_ACK;

typedef struct tagPKT_CLIGS_JEWELRY_GENERATE_INFO_REQ{
	tagPKT_CLIGS_JEWELRY_GENERATE_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_GENERATE_INFO_REQ)); }
	UINT16           wFirstID; //��һ����ƷID��ֵΪ0ʱû����Ʒ��
	UINT16           wFirstIdx; //��һ����ƷIdx
	UINT16           wSecondID; //�ڶ�����ƷID
	UINT16           wSecondIdx; //�ڶ�����ƷIdx
	UINT16           wThirdID; //��������ƷID
	UINT16           wThirdIdx; //��������ƷIdx
	UINT16           wFourthID; //���ĸ���ƷID
	UINT16           wFourthIdx; //���ĸ���ƷIdx
}PKT_CLIGS_JEWELRY_GENERATE_INFO_REQ;

typedef struct tagPKT_CLIGS_JEWELRY_GENERATE_INFO_ACK{
	tagPKT_CLIGS_JEWELRY_GENERATE_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_GENERATE_INFO_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wGenerateLevel; //�ϳɵĵȼ�
	UINT8            byGenerateType; //�ϳɵ�Ʒ��
	DT_RES_DATA      stGenerateCost; //�ϳ�����
	UINT8            byState; //״̬λ��0������ 1����ǿ��������Ʒ�� 2ͭǮ���㣬 3��Ʒû��ȫ��
	DT_RSYNC_RES_ITEM_DATA stResourceSnyc; //��Դͬ����Ϣ
}PKT_CLIGS_JEWELRY_GENERATE_INFO_ACK;

typedef struct tagPKT_CLIGS_JEWELRY_RESOLVE_REQ{
	tagPKT_CLIGS_JEWELRY_RESOLVE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_RESOLVE_REQ)); }
	UINT16           wJewelryID; //��ƷID
	UINT16           wJewelryIdx; //��Ʒidx
	UINT8            byBagKind; //����λ�ã�1������ 2��Ʒ������ 3��Ʒ�ϳɣ�
}PKT_CLIGS_JEWELRY_RESOLVE_REQ;

typedef struct tagPKT_CLIGS_JEWELRY_RESOLVE_ACK{
	tagPKT_CLIGS_JEWELRY_RESOLVE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_RESOLVE_ACK)); }
	UINT16           wErrCode; //������
	DT_GOODS_DATA_LST_CLI stItemInfo; //��ɢ���ĵ�����Ϣ
	DT_ITEM_DATA_LIST_CLI3 stJewelryInfo; //������Ʒ��Ϣ
	DT_RSYNC_RES_ITEM_DATA stResourceSnyc; //��Դͬ����Ϣ
}PKT_CLIGS_JEWELRY_RESOLVE_ACK;

typedef struct tagPKT_CLIGS_JEWELRY_RESOLVE_ACK2{
	tagPKT_CLIGS_JEWELRY_RESOLVE_ACK2() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_RESOLVE_ACK2)); }
	UINT16           wErrCode; //������
	DT_GOODS_DATA_LST_CLI stItemInfo; //��ɢ���ĵ�����Ϣ
	DT_RSYNC_RES_ITEM_DATA stResourceSnyc; //��Դͬ����Ϣ
}PKT_CLIGS_JEWELRY_RESOLVE_ACK2;

typedef struct tagPKT_CLIGS_PLAYER_INFO_EQUIP_REQ{
	tagPKT_CLIGS_PLAYER_INFO_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_EQUIP_REQ)); }
	UINT32           dwPlayerID; //���ID
}PKT_CLIGS_PLAYER_INFO_EQUIP_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_EQUIP_ACK{
	tagPKT_CLIGS_PLAYER_INFO_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_EQUIP_ACK)); }
	UINT16           wErrCode; //������
	UINT32           dwPlayerID; //���ID
	UINT8            byHeroNum; //�佫����
	DT_HERO_EQUIP_DATA_LST_CLI astEquipDataList[MAX_HERO_NUM]; //�佫װ����Ϣ
	DT_ALL_EQUIP_XIANGQIAN_DES stEquipXiangqianDes; //װ����Ƕ��Ϣ����
	UINT8            byVipLevel; //VIP�ȼ�
	DT_HERO_BASE_DATA_CLI astHeroBaseData[MAX_HERO_NUM]; //�佫������Ϣ
}PKT_CLIGS_PLAYER_INFO_EQUIP_ACK;

typedef struct tagPKT_CLIGS_OPEN_JEWELRY_STRENGTH_REQ{
	tagPKT_CLIGS_OPEN_JEWELRY_STRENGTH_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JEWELRY_STRENGTH_REQ)); }
	UINT16           wJewelryID; //��ƷID
	UINT16           wJewelryIdx; //��Ʒidx
}PKT_CLIGS_OPEN_JEWELRY_STRENGTH_REQ;

typedef struct tagDT_HERO_JEWELRY_STRENGTH_INFO{
	UINT16           wHeroID; //���ID
	DT_JEWELRY_DATA_CLI astJewelryList[MAX_JEWELRY_POS]; //��Ʒ��Ϣ
	DT_JEWELRY_DATA_CLI astStrengthJewelryList[MAX_JEWELRY_POS]; //ǿ�������Ʒ��Ϣ�б�
	DT_STRENGTH_INFO astStringth[MAX_JEWELRY_POS]; //ǿ������
	UINT8            abyMaxMark[MAX_JEWELRY_POS]; //ǿ�����ޱ�ʶ��0δ�ﵽ���ޣ� 1�Ѵﵽ���ޣ�
}DT_HERO_JEWELRY_STRENGTH_INFO;

typedef struct tagDT_BAG_JEWELRY_STRENGTH_INFO{
	UINT8            byJewelryNum; //��Ʒ����
	DT_JEWELRY_DATA_CLI astJewelryList[MAX_BAG_OPEN_NUM]; //��Ʒ��Ϣ
	DT_JEWELRY_DATA_CLI astStrengthJewelryList[MAX_BAG_OPEN_NUM]; //ǿ�������Ʒ��Ϣ�б�
	DT_STRENGTH_INFO astStringth[MAX_BAG_OPEN_NUM]; //ǿ������
	UINT8            abyMaxMark[MAX_BAG_OPEN_NUM]; //ǿ�����ޱ�ʶ��0δ�ﵽ���ޣ� 1�Ѵﵽ���ޣ�
}DT_BAG_JEWELRY_STRENGTH_INFO;

typedef struct tagPKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK{
	tagPKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byHeroNum; //������
	DT_HERO_JEWELRY_STRENGTH_INFO astHeroJewelryStrengInfo[MAX_HERO_NUM]; //�����Ʒǿ����Ϣ
	DT_BAG_JEWELRY_STRENGTH_INFO stBagJewelryStrengInfo; //������Ʒǿ����Ϣ
	DT_PLAYER_RES_LST_DATA stPlayerRes; //ͭǮԪ��
}PKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK;

typedef struct tagPKT_CLIGS_JEWELRY_COMPARE_REQ{
	tagPKT_CLIGS_JEWELRY_COMPARE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_COMPARE_REQ)); }
	UINT16           wJewelryID; //�Ա���ƷID
	UINT16           wJewelryIdx; //�Ա���ƷIdx
}PKT_CLIGS_JEWELRY_COMPARE_REQ;

typedef struct tagPKT_CLIGS_JEWELRY_COMPARE_ACK{
	tagPKT_CLIGS_JEWELRY_COMPARE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_COMPARE_ACK)); }
	UINT16           wErrCode; //������
	DT_JEWELRY_DATA_CLI stDressJewelryInfo; //������Ʒ
	DT_JEWELRY_DATA_CLI stCompareJewelryInfo; //�Ա���Ʒ
}PKT_CLIGS_JEWELRY_COMPARE_ACK;

typedef struct tagPKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ{
	tagPKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ)); }
	UINT16           wJewelryID; //��ƷID
	UINT16           wJewelryIdx; //��ƷIdx
	UINT8            byExtID; //Ҫǿ����������ID
}PKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ;

typedef struct tagPKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK{
	tagPKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK)); }
	UINT16           wErrCode; //������
	DT_JEWELRY_DATA_CLI stJewelryInfo; //��Ʒ��Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
	DT_JEWELRY_DATA_CLI stStrengthJewelry; //ǿ�������Ʒ��Ϣ�б�
	UINT8            byMaxMark; //ǿ�����ޱ�ʶ��0δ�ﵽ���ޣ� 1�Ѵﵽ���ޣ�
	DT_FUNC_PROMPT_DATA stBuildPrompt; //������ʾ
	DT_STRENGTH_INFO stStrengInfo; //ǿ������
}PKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK;

typedef struct tagPKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ{
	tagPKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ)); }
	UINT16           wJewelryID; //��ƷID
	UINT16           wJewelryIdx; //��ƷIdx
}PKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ;

typedef struct tagPKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK{
	tagPKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK)); }
	UINT16           wErrCode; //������
	DT_STRENGTH_LST_INFO stBaseItem; //��������(���)
	DT_STRENGTH_LST_INFO stReturnItem; //���ص��ߣ�100%��
	DT_PLAYER_RES_DATA stCostRes; //����
}PKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK;

typedef struct tagPKT_CLIGS_COURAGE_GROUP_OVERTIME_NTF{
	tagPKT_CLIGS_COURAGE_GROUP_OVERTIME_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_GROUP_OVERTIME_NTF)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_COURAGE_GROUP_OVERTIME_NTF;

typedef struct tagDT_GVG_FORMATION_PLAYER_ID_LST_CLI{
	UINT8            byPlayerNum; //����������
	UINT32           adwPlayerIDForFormation[DT_FACTION_PLAYER_NUM]; //�������ID����˳���·���
}DT_GVG_FORMATION_PLAYER_ID_LST_CLI;

typedef struct tagDT_GVG_FORMATION_HERO_LST_INFO{
	UINT8            byHeroNum; //����������
	UINT32           adwHeroID[MAX_FORMATION_IDX_NUM]; //������ID����˳���·���
	UINT8            abyHeroCareerID[MAX_FORMATION_IDX_NUM]; //-������ְҵ
}DT_GVG_FORMATION_HERO_LST_INFO;

typedef struct tagDT_GVG_FORMATION_PLAYER_DATA_CLI{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispPlayerName[USERNAME_LEN]; //����ǳ�
	UINT16           wLevel; //��ҵȼ�
	UINT32           dwCoachID; //�������ID
	UINT32           dwPower; //ս��
	UINT8            byPlayerPosition; //������ְλ commondef (em_Faction_Job)
	UINT32           dwDoorsTributeLevel; //�Ź��ȼ�
	DT_GVG_FORMATION_HERO_LST_INFO stFrontRow; //ǰ��
	DT_GVG_FORMATION_HERO_LST_INFO stBackRow; //����
	UINT8            byColor; //������ɫ
}DT_GVG_FORMATION_PLAYER_DATA_CLI;

typedef struct tagDT_GVG_FORMATION_SIMPLE_PLAYER_DATA_CLI{
	UINT32           dwPlayerID; //���ID
	TCHAR            aszDispPlayerName[USERNAME_LEN]; //����ǳ�
	UINT32           dwCoachID; //�������ID
	UINT32           dwPower; //ս��
	UINT8            byPosIdx; //λ����Ϣ(0δ������)
	UINT8            byJobType; //���ְλ
}DT_GVG_FORMATION_SIMPLE_PLAYER_DATA_CLI;

typedef struct tagDT_GVG_FORMATION_SIMPLE_PLAYER_DATA_LST_CLI{
	UINT8            byPlayerNum; //��ѡ��Ҹ���
	DT_GVG_FORMATION_SIMPLE_PLAYER_DATA_CLI astPlayerInfo[DT_FACTION_PLAYER_NUM]; //�����Ϣ
}DT_GVG_FORMATION_SIMPLE_PLAYER_DATA_LST_CLI;

typedef struct tagDT_FACTION_FORMATION_POS_INFO{
	UINT8            byLockState; //����״̬��0δ������1������
	UINT16           wNeedFactionLevel; //������Ҫ�����ɵȼ�
}DT_FACTION_FORMATION_POS_INFO;

typedef struct tagDT_FACTION_FORMATION_POS_LST_INFO{
	UINT8            byPosNum; //λ����
	DT_FACTION_FORMATION_POS_INFO astFormationPosInfo[MAX_GVG_FORMATION_PLAYER_CNT]; //��λ��Ϣ
	UINT8            byUnlockPosNum; //������λ����
}DT_FACTION_FORMATION_POS_LST_INFO;

typedef struct tagPKT_CLIGS_OPEN_GVG_FORMATION_REQ{
	tagPKT_CLIGS_OPEN_GVG_FORMATION_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_FORMATION_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_GVG_FORMATION_REQ;

typedef struct tagPKT_CLIGS_OPEN_GVG_FORMATION_ACK{
	tagPKT_CLIGS_OPEN_GVG_FORMATION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_FORMATION_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_FORMATION_SIMPLE_PLAYER_DATA_LST_CLI stPlayerLstInfo; //�����Ϣ�б�
	UINT16           wCurFactionLevel; //��ǰ���ɵȼ�
	DT_FACTION_FORMATION_POS_LST_INFO stFormationInfo; //���������Ϣ�������ȣ�
}PKT_CLIGS_OPEN_GVG_FORMATION_ACK;

typedef struct tagDT_GVG_TIME_INFO{
	UINT8            byStartWeek; //��ʼ���ڣ�0�������ڣ�1����һ��7�����죩
	UINT32           dwStartTime; //��ʼ����ʱ��(��)
	UINT8            byEndWeek; //�������ڣ�0�������ڣ�1����һ��7�����죩
	UINT32           dwEndTime; //��������ʱ��(��)
}DT_GVG_TIME_INFO;

typedef struct tagDT_GVG_SCHEDULE_INFO{
	DT_GVG_TIME_INFO stApply; //����ʱ��
	DT_GVG_TIME_INFO stMoneyGame; //����һ�֣��������ƴ��
	DT_GVG_TIME_INFO stChaosWar; //�������֣����Ҷ���
	DT_GVG_TIME_INFO stDouble16TO8; //˫��16��8
	DT_GVG_TIME_INFO stDouble8TO4; //˫��8��4
	DT_GVG_TIME_INFO stFinalWar; //�ܾ���
	UINT8            byCurRound; //��ǰ�ִΣ��� commondef.h �� GvGRound
	UINT32           dwRefreshTime; //�����´�ˢ�����ļ��(��)��ʱ�䵽��������ˢ���������
	UINT8            byGetGiftNum; //����ȡ�����
	UINT16           wSessionID; //�ڼ�������
	UINT8            byUnReadLogCnt; //δ������ս������
	UINT8            byFormationState; //�����ʶ(0������1û������ 2δ������3����������ʼ��4ûȨ�ޣ� 5���������У� 6������ս�ѽ���)
}DT_GVG_SCHEDULE_INFO;

typedef struct tagPKT_CLIGS_GVG_APPLAY_ACK{
	tagPKT_CLIGS_GVG_APPLAY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_APPLAY_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_SCHEDULE_INFO stScheduleInfo; //���ս������Ϣ
	DT_GVG_FACTION_RANK_DATA stLastChampionInfo; //�Ͻ�ھ���Ϣ
	UINT8            byIsApplyTime; //��ǰ�Ƿ��ڱ���ʱ��
	UINT32           dwCountDown; //���뱨�������ĵ���ʱ
}PKT_CLIGS_GVG_APPLAY_ACK;

typedef struct tagDT_GVG_RANK_MONEY_DATA{
	UINT16           wRank; //����
	UINT64           qwFactionFunds; //�ʽ�
	UINT64           qwSumPower; //��ս��
	DT_FACTION_BASE_DATA_CLI2 stFactionBaseInfo; //���ɻ�������
}DT_GVG_RANK_MONEY_DATA;

typedef struct tagDT_GVG_SIMPLE_RANK_MONEY_DATA{
	UINT16           wRank; //����
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT64           qwFactionFunds; //�ۻ��ʽ�
}DT_GVG_SIMPLE_RANK_MONEY_DATA;

typedef struct tagDT_GVG_RANK_MONEY_LST_DATA{
	UINT16           wRankNum; //��������
	DT_GVG_RANK_MONEY_DATA astMoneyRank[MAX_RANK_DISPLAY]; //��������
}DT_GVG_RANK_MONEY_LST_DATA;

typedef struct tagDT_GVG_SIMPLE_RANK_MONEY_LST_DATA{
	UINT16           wRankNum; //��������
	DT_GVG_SIMPLE_RANK_MONEY_DATA astMoneyRank[MAX_RANK_DISPLAY]; //��������
}DT_GVG_SIMPLE_RANK_MONEY_LST_DATA;

typedef struct tagPKT_CLIGS_OPEN_ALREAD_APPLAY_REQ{
	tagPKT_CLIGS_OPEN_ALREAD_APPLAY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ALREAD_APPLAY_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_ALREAD_APPLAY_REQ;

typedef struct tagPKT_CLIGS_OPEN_ALREAD_APPLAY_ACK{
	tagPKT_CLIGS_OPEN_ALREAD_APPLAY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ALREAD_APPLAY_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_RANK_MONEY_LST_DATA stApplyInfo; //����
}PKT_CLIGS_OPEN_ALREAD_APPLAY_ACK;

typedef struct tagPKT_CLIGS_GVG_LAST_RESULT_REQ{
	tagPKT_CLIGS_GVG_LAST_RESULT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_LAST_RESULT_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_GVG_LAST_RESULT_REQ;

typedef struct tagPKT_CLIGS_GVG_LAST_RESULT_ACK{
	tagPKT_CLIGS_GVG_LAST_RESULT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_LAST_RESULT_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_FACTION_RANK_LST_DATA stLastResult; //�Ͻ�����
}PKT_CLIGS_GVG_LAST_RESULT_ACK;

typedef struct tagPKT_CLIGS_GVG_MONEY_CHAOS_ACK{
	tagPKT_CLIGS_GVG_MONEY_CHAOS_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_MONEY_CHAOS_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_SCHEDULE_INFO stScheduleInfo; //���ս������Ϣ
	DT_GVG_SIMPLE_RANK_MONEY_LST_DATA stMoneyRank; //������Ϣ
	DT_SIMPLE_FACTION_LST_INFO stBattleInfo; //���Ҷ�
	DT_SIMPLE_FACTION_LST_INFO stMoneyInfo; //������ƴ
	UINT64           qwCountDwonTime; //����ʱ
	UINT8            byCurPanel; //��ǰ��壨1�������ƴ�� 2���Ҷ������У�3�������ʱ��
	UINT8            bySmallRound; //��ǰС�ִ�
}PKT_CLIGS_GVG_MONEY_CHAOS_ACK;

typedef struct tagPKT_CLIGS_GVG_OPEN_MY_GAMBLE_REQ{
	tagPKT_CLIGS_GVG_OPEN_MY_GAMBLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_OPEN_MY_GAMBLE_REQ)); }
	UINT16           wExt; //��չλ
}PKT_CLIGS_GVG_OPEN_MY_GAMBLE_REQ;

typedef struct tagDT_GAMBLE_GAME_INFO{
	DT_GVG_ROUND     stGameKind; //������� commondef (GvGFightLogStage)
	UINT8            byResult; //Ѻע���0����1ʤ��2��δ����, 3δѺע commondef.h GvGGambleResult
	DT_GAMBLE_FACTION_INFO stFactionInfo1; //����1
	DT_GAMBLE_FACTION_INFO stFactionInfo2; //����2
	UINT64           qwVideoID; //¼��ID
}DT_GAMBLE_GAME_INFO;

typedef struct tagDT_GAMBLE_GAME_LST_INFO{
	UINT8            byGambleNum; //Ѻע����
	DT_GAMBLE_GAME_INFO astGameInfo[MAX_GAMBLE_NUM]; //������Ϣ
}DT_GAMBLE_GAME_LST_INFO;

typedef struct tagDT_GAMBLE_GIFT_DATA{
	UINT8            byGambleType; //Ѻע�����0����1ʤ��2��δ����, 3δѺע commondef.h GvGGambleResult��
	DT_PLAYER_RES_DATA stGambleReward; //Ѻע����
}DT_GAMBLE_GIFT_DATA;

typedef struct tagPKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK{
	tagPKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_RES_DATA stWinRes; //�ѻ�ȡ������
	DT_GAMBLE_GIFT_DATA astGambleInfo[MAX_GAMBLE_NUM]; //Ѻע��Ϣ��0����1ʤ��2��δ����, 3δѺע commondef.h GvGGambleResult��
	DT_GAMBLE_GAME_LST_INFO stGambleGameInfo; //Ѻע�ı�����Ϣ
}PKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK;

typedef struct tagPKT_CLIGS_GVG_OPEN_GAMBLE_REQ{
	tagPKT_CLIGS_GVG_OPEN_GAMBLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_OPEN_GAMBLE_REQ)); }
	UINT64           qwGambleID; //¼��ID
}PKT_CLIGS_GVG_OPEN_GAMBLE_REQ;

typedef struct tagDT_FACTION_GAMBLE_INFO{
	UINT32           dwFactionID; //����ID
	UINT16           wZoneID; //��ID
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	TCHAR            aszHeadName[USERNAME_LEN]; //��������
	UINT16           wJoinNum; //��ս����
	UINT64           qwSumPower; //��ս��
	UINT32           dwSumIntegral; //��������
	UINT32           dwSupportNum; //֧������
	UINT8            byIconID; //����ͷ��ID
}DT_FACTION_GAMBLE_INFO;

typedef struct tagPKT_CLIGS_GVG_OPEN_GAMBLE_ACK{
	tagPKT_CLIGS_GVG_OPEN_GAMBLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_OPEN_GAMBLE_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_RES_DATA stWinRes; //ʤ������
	DT_FACTION_GAMBLE_INFO stFactionInfo1; //����1
	DT_FACTION_GAMBLE_INFO stFactionInfo2; //����2
	UINT64           qwVideoID; //¼��ID
}PKT_CLIGS_GVG_OPEN_GAMBLE_ACK;

typedef struct tagPKT_CLIGS_OPEN_GVG_RULE_REQ{
	tagPKT_CLIGS_OPEN_GVG_RULE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_RULE_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_GVG_RULE_REQ;

typedef struct tagPKT_CLIGS_OPEN_GVG_RULE_ACK{
	tagPKT_CLIGS_OPEN_GVG_RULE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_RULE_ACK)); }
	UINT16           wErrCode; //������
	TCHAR            aszContent[MAX_GVG_RULE]; //����
}PKT_CLIGS_OPEN_GVG_RULE_ACK;

typedef struct tagPKT_CLIGS_GVG_GAMBLE_REQ{
	tagPKT_CLIGS_GVG_GAMBLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_GAMBLE_REQ)); }
	UINT32           dwWinFactionID; //Ѻע������ID
	UINT64           qwGambleID; //¼��ID
}PKT_CLIGS_GVG_GAMBLE_REQ;

typedef struct tagPKT_CLIGS_GVG_GAMBLE_ACK{
	tagPKT_CLIGS_GVG_GAMBLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_GAMBLE_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIGS_GVG_GAMBLE_ACK;

typedef struct tagPKT_CLIGS_OPEN_GVG_ACTIVITY_REQ{
	tagPKT_CLIGS_OPEN_GVG_ACTIVITY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_ACTIVITY_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_GVG_ACTIVITY_REQ;

typedef struct tagPKT_CLIGS_OPEN_FACTION_MONEY_RANK_REQ{
	tagPKT_CLIGS_OPEN_FACTION_MONEY_RANK_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_MONEY_RANK_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_FACTION_MONEY_RANK_REQ;

typedef struct tagPKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK{
	tagPKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_RANK_MONEY_LST_DATA stMoneyRank; //������Ϣ
}PKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK;

typedef struct tagPKT_CLIGS_READ_FORMATION_PLAYER_TIP_REQ{
	tagPKT_CLIGS_READ_FORMATION_PLAYER_TIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_READ_FORMATION_PLAYER_TIP_REQ)); }
	UINT32           dwReqPlayerID; //��������ID
}PKT_CLIGS_READ_FORMATION_PLAYER_TIP_REQ;

typedef struct tagPKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK{
	tagPKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_FORMATION_PLAYER_DATA_CLI stTipInfo; //���TIP��Ϣ
}PKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK;

typedef struct tagPKT_CLIGS_GVG_FACTION_EMBATTLE_REQ{
	tagPKT_CLIGS_GVG_FACTION_EMBATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_FACTION_EMBATTLE_REQ)); }
	DT_GVG_FORMATION_PLAYER_ID_LST_CLI stFormation; //������Ϣ
}PKT_CLIGS_GVG_FACTION_EMBATTLE_REQ;

typedef struct tagPKT_CLIGS_GVG_FACTION_EMBATTLE_ACK{
	tagPKT_CLIGS_GVG_FACTION_EMBATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_FACTION_EMBATTLE_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIGS_GVG_FACTION_EMBATTLE_ACK;

typedef struct tagDT_GIFT_DETAILS_INFO{
	UINT8            byKindType; //��Դ���ͣ�commondef.h ACTE_KIND_TYPE��
	UINT16           wKindID; //��ԴID������Ϊ��Ʒʱ��Ч,ValueΪ��ƷID��
	UINT32           dwKindNum; //��Դ����
}DT_GIFT_DETAILS_INFO;

typedef struct tagDT_GIFT_DETAILS_LST_INFO{
	UINT8            byGoodsNum; //��Ʒ����
	DT_GIFT_DETAILS_INFO astGoodsInfo[MAX_GIFT_GOODS_NUM]; //��Ʒ��Ϣ
}DT_GIFT_DETAILS_LST_INFO;

typedef struct tagDT_GVG_GIFT_DATA_CLI{
	UINT16           wSessionID; //�ڼ���������ս
	UINT8            byGvGRound; //��ս�ִΣ�commondef.h GvGRound��
	UINT8            byBattleIdx; //��ǰ�ִ��еĵڼ���ս��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��ս��������
	UINT8            byBattleResult; //��ս�����0�䣬1ʤ����
	DT_GIFT_DETAILS_LST_INFO stGiftInfo; //�������
	UINT8            byGiftGetState; //�����ȡ״̬��0δ��ȡ�� 1��ȡ��
	UINT64           qwGiftID; //���ID
	UINT8            byGiftType; //������GvGiftType��
	UINT8            byRank; //����
}DT_GVG_GIFT_DATA_CLI;

typedef struct tagDT_GVG_GIFT_DATA_LST_CLI{
	UINT8            byGiftNum; //�����
	DT_GVG_GIFT_DATA_CLI astGiftInfo[MAX_GVG_GIFT_NUM]; //�����Ϣ
}DT_GVG_GIFT_DATA_LST_CLI;

typedef struct tagPKT_CLIGS_OPEN_GVG_GIFT_REQ{
	tagPKT_CLIGS_OPEN_GVG_GIFT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_GIFT_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_GVG_GIFT_REQ;

typedef struct tagPKT_CLIGS_OPEN_GVG_GIFT_ACK{
	tagPKT_CLIGS_OPEN_GVG_GIFT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_GIFT_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_GIFT_DATA_LST_CLI stGiftLstInfo; //�����Ϣ
}PKT_CLIGS_OPEN_GVG_GIFT_ACK;

typedef struct tagPKT_CLIGS_GET_GVG_GIFT_REQ{
	tagPKT_CLIGS_GET_GVG_GIFT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_GVG_GIFT_REQ)); }
	UINT64           qwGiftID; //���ID(0Ϊȫ����ȡ)
}PKT_CLIGS_GET_GVG_GIFT_REQ;

typedef struct tagPKT_CLIGS_GET_GVG_GIFT_ACK{
	tagPKT_CLIGS_GET_GVG_GIFT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_GVG_GIFT_ACK)); }
	UINT16           wErrCode; //������
	DT_RSYNC_RES_ITEM_DATA stSyncInfo; //��Ϣͬ������ͬ����Ʒ��
	UINT64           qwGiftID; //���ID
	UINT8            byLeftGiftNum; //δ��ȡ�����
}PKT_CLIGS_GET_GVG_GIFT_ACK;

typedef struct tagPKT_CLIGS_APPLY_GVG_REQ{
	tagPKT_CLIGS_APPLY_GVG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_APPLY_GVG_REQ)); }
	UINT8            byExt; //���ֶ�
}PKT_CLIGS_APPLY_GVG_REQ;

typedef struct tagPKT_CLIGS_APPLY_GVG_ACK{
	tagPKT_CLIGS_APPLY_GVG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_APPLY_GVG_ACK)); }
	UINT8            byExt; //���ֶ�
}PKT_CLIGS_APPLY_GVG_ACK;

typedef struct tagDT_FINAL_WAR_FACTION_INFO_CLI{
	UINT8            byRank; //����
	UINT32           dwFactionID; //����ID
	UINT32           dwZoneID; //��ID
	UINT16           wFactionIconID; //����ͼ��
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	UINT16           wFactionLevel; //���ɵȼ�
	UINT64           qwSumPower; //��ս��
	UINT16           wJoinNum; //��ս����
	UINT32           dwScore; //����
	UINT64           qwVideoID; //¼��ID
	TCHAR            aszZoneName[ZONENAME_LEN]; //�������ڵ�����
}DT_FINAL_WAR_FACTION_INFO_CLI;

typedef struct tagPKT_CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF{
	tagPKT_CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF)); }
	UINT8            byUnReadCnt; //��ʣ����������ս��δ��
}PKT_CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF;

typedef struct tagPKT_CLIGS_OPEN_GVG_LOG_REQ{
	tagPKT_CLIGS_OPEN_GVG_LOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_LOG_REQ)); }
	UINT32           dwFactionID; //Ŀ������ID��0����򿪱���ս��
}PKT_CLIGS_OPEN_GVG_LOG_REQ;

typedef struct tagPKT_CLIGS_OPEN_GVG_LOG_ACK{
	tagPKT_CLIGS_OPEN_GVG_LOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_GVG_LOG_ACK)); }
	UINT16           wErrCode; //������
	DT_FACTION_GVG_LOG stLog; //����ս��
	UINT32           dwRefreshTime; //�����´�ˢ�����ļ��(��)��ʱ�䵽��������ˢ������ս�����
}PKT_CLIGS_OPEN_GVG_LOG_ACK;

typedef struct tagPKT_CLIGS_16_TO_8_TO_4_ACK{
	tagPKT_CLIGS_16_TO_8_TO_4_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_16_TO_8_TO_4_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_SCHEDULE_INFO stScheduleInfo; //���ս������Ϣ
	UINT8            byNextRound; //������ʼ���ִΣ�16��8��8��4�������ܾ�������commondef.h��GvGRound
	UINT32           dwCountDownTime; //��һ�ֵ���ʱ(��)
	DT_FACTION_BASE_DATA_CLI2 astFactionList[GVG_16_TO_8_FACTION_CNT]; //˫��ǰ16������ѡ���б�
	UINT8            byWin8Cnt; //16��8��ʤ��������
	UINT8            abyWin8List[GVG_16_TO_8_WIN_CNT]; //16��8��ʤ����������б�(���:1-16)
	UINT8            byWin4Cnt; //8��4��ʤ��������
	UINT8            abyWin4List[GVG_8_TO_4_WIN_CNT]; //8��4��ʤ����������б�(���:1-16)
	UINT64           aqwVideoIDList16To8[GVG_16_TO_8_WIN_CNT]; //16��8��¼��ID�б�(��δ����ʤ��ǰ����ѺעID����ʱѺעIDΪ0���ʾ�޷�Ѻע������ʤ�ߺ���������¼���ID)
	UINT64           aqwVideoIDList8To4[GVG_8_TO_4_WIN_CNT]; //8��4��¼��ID�б�(��δ����ʤ��ǰ����ѺעID����ʱѺעIDΪ0���ʾ�޷�Ѻע������ʤ�ߺ���������¼���ID)
	UINT8            byGamblePos; //�Ѷ��ĸ����(1~16)�����ɽ���Ѻע��Ϊ0���ʾ����δѺע
}PKT_CLIGS_16_TO_8_TO_4_ACK;

typedef struct tagPKT_CLIGS_FINAL_WAR_ACK{
	tagPKT_CLIGS_FINAL_WAR_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FINAL_WAR_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_SCHEDULE_INFO stScheduleInfo; //���ս������Ϣ
	UINT8            byFactionCnt; //������
	DT_FINAL_WAR_FACTION_INFO_CLI astFactionList[GVG_FINAL_WAR_FACTION_CNT]; //�����б�
	UINT32           dwCountDwonTime; //��һ�ֵ���ʱ(��)
	UINT8            byPassedStageCnt; //�ѽ����ִ�
	UINT8            byTotalStage; //���ִ�
	UINT8            byCurStage; //��ǰ�׶Σ�0����δ��ʼ��1�ķ����������ڽ����С�2�����ܾ����ѽ���
	UINT32           dwGambleFactionID; //Ѻע������ID��Ϊ0������δѺע��
}PKT_CLIGS_FINAL_WAR_ACK;

typedef struct tagPKT_CLIGS_GVG_CHAMPION_ACK{
	tagPKT_CLIGS_GVG_CHAMPION_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_CHAMPION_ACK)); }
	UINT16           wErrCode; //������
	DT_GVG_SCHEDULE_INFO stScheduleInfo; //���ս������Ϣ
	DT_GVG_FACTION_RANK_LST_DATA stNo123; //������Ǽ�����Ϣ
}PKT_CLIGS_GVG_CHAMPION_ACK;

typedef struct tagPKT_CLIGS_GVG_ERR_MSG_ACK{
	tagPKT_CLIGS_GVG_ERR_MSG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_ERR_MSG_ACK)); }
	TCHAR            aszErrMsg[MAX_GVG_ERR_MSG_LEN]; //������ʾ������
}PKT_CLIGS_GVG_ERR_MSG_ACK;

typedef struct tagDT_GVG_VIDEO_FACTION_INFO{
	UINT8            byFactionIconID; //����ͼ��ID
	TCHAR            aszFactionName[MAX_FACTION_NUM]; //��������
	TCHAR            aszNickName[USERNAME_LEN]; //�����������
	UINT8            byJob; //��������������е�ְλ����commondef.h��em_Faction_Job
	UINT8            byRemainPlayerCnt; //����ʣ������
	UINT8            byKillCombo; //��ǰ��ն��
	TCHAR            aszZoneName[ZONENAME_LEN]; //�������ڵ�����
}DT_GVG_VIDEO_FACTION_INFO;

typedef struct tagPKT_CLIGS_SEE_GVG_VIDEO_REQ{
	tagPKT_CLIGS_SEE_GVG_VIDEO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SEE_GVG_VIDEO_REQ)); }
	UINT64           qwVideoID; //¼��ID
	UINT8            byVideoNum; //����ĳ���
}PKT_CLIGS_SEE_GVG_VIDEO_REQ;

typedef struct tagPKT_CLIGS_SEE_GVG_VIDEO_ACK_v400{
	tagPKT_CLIGS_SEE_GVG_VIDEO_ACK_v400() { memset(this, 0, sizeof(tagPKT_CLIGS_SEE_GVG_VIDEO_ACK_v400)); }
	UINT16           wErrCode; //������
	UINT64           qwVideoID; //¼��ID
	UINT8            byVideoNum; //��ս�����ڵڼ���
	DT_GVG_VIDEO_FACTION_INFO stG1; //����1��Ϣ
	DT_GVG_VIDEO_FACTION_INFO stG2; //����2��Ϣ
	DT_EMPTY_HP_VIDEO_v400 stVideo; //¼������
	UINT8            byHaveNextVideo; //�Ƿ�����һ��: 1�ǡ�0��
	UINT8            byEnegy1; //������:0~100��ֵԽС���Խ������
	UINT8            byEnegy2; //������:0~100��ֵԽС���Խ������
	UINT8            byIsWeak1; //������ұ����Ƿ�����
	UINT8            byIsWeak2; //������ұ����Ƿ�����
}PKT_CLIGS_SEE_GVG_VIDEO_ACK_v400;

typedef struct tagPKT_CLIGS_SEE_GVG_VIDEO_ACK_v410{
	tagPKT_CLIGS_SEE_GVG_VIDEO_ACK_v410() { memset(this, 0, sizeof(tagPKT_CLIGS_SEE_GVG_VIDEO_ACK_v410)); }
	UINT16           wErrCode; //������
	UINT64           qwVideoID; //¼��ID
	UINT8            byVideoNum; //��ս�����ڵڼ���
	DT_GVG_VIDEO_FACTION_INFO stG1; //����1��Ϣ
	DT_GVG_VIDEO_FACTION_INFO stG2; //����2��Ϣ
	DT_EMPTY_HP_VIDEO stVideo; //¼������
	UINT8            byHaveNextVideo; //�Ƿ�����һ��: 1�ǡ�0��
	UINT8            byEnegy1; //������:0~100��ֵԽС���Խ������
	UINT8            byEnegy2; //������:0~100��ֵԽС���Խ������
	UINT8            byIsWeak1; //������ұ����Ƿ�����
	UINT8            byIsWeak2; //������ұ����Ƿ�����
}PKT_CLIGS_SEE_GVG_VIDEO_ACK_v410;

typedef struct tagPKT_CLIGS_END_GVG_VIDEO_REQ{
	tagPKT_CLIGS_END_GVG_VIDEO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_END_GVG_VIDEO_REQ)); }
	UINT64           qwVideoID; //¼��ID
	UINT8            byEndType; //�������ͣ��Զ�����0/�ֶ������ť����1
}PKT_CLIGS_END_GVG_VIDEO_REQ;

typedef struct tagPKT_CLIGS_END_GVG_VIDEO_ACK_v400{
	tagPKT_CLIGS_END_GVG_VIDEO_ACK_v400() { memset(this, 0, sizeof(tagPKT_CLIGS_END_GVG_VIDEO_ACK_v400)); }
	UINT16           wErrCode; //������
	UINT64           qwVideoID; //¼��ID
	DT_GVG_VIDEO_FACTION_INFO stG1; //����1��Ϣ
	DT_GVG_VIDEO_FACTION_INFO stG2; //����2��Ϣ
	DT_EMPTY_HP_VIDEO_v400 stVideo; //��Ѫ¼������
	DT_GVG_MVP_LIST  stMVPList; //����ұ����б�
	UINT8            byEndType; //�������ͣ��Զ�����0/�ֶ������ť����1
	DT_GVG_ROUND     stRound; //��¼�������ִΣ����ڿͻ����ж��Ƿ���ʾ����
}PKT_CLIGS_END_GVG_VIDEO_ACK_v400;

typedef struct tagPKT_CLIGS_END_GVG_VIDEO_ACK_v410{
	tagPKT_CLIGS_END_GVG_VIDEO_ACK_v410() { memset(this, 0, sizeof(tagPKT_CLIGS_END_GVG_VIDEO_ACK_v410)); }
	UINT16           wErrCode; //������
	UINT64           qwVideoID; //¼��ID
	DT_GVG_VIDEO_FACTION_INFO stG1; //����1��Ϣ
	DT_GVG_VIDEO_FACTION_INFO stG2; //����2��Ϣ
	DT_EMPTY_HP_VIDEO stVideo; //��Ѫ¼������
	DT_GVG_MVP_LIST  stMVPList; //����ұ����б�
	UINT8            byEndType; //�������ͣ��Զ�����0/�ֶ������ť����1
	DT_GVG_ROUND     stRound; //��¼�������ִΣ����ڿͻ����ж��Ƿ���ʾ����
}PKT_CLIGS_END_GVG_VIDEO_ACK_v410;

typedef struct tagPKT_CLIGS_SHOW_GVG_MVP_REQ{
	tagPKT_CLIGS_SHOW_GVG_MVP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SHOW_GVG_MVP_REQ)); }
	UINT64           qwVideoID; //¼��ID
}PKT_CLIGS_SHOW_GVG_MVP_REQ;

typedef struct tagPKT_CLIGS_SHOW_GVG_MVP_ACK{
	tagPKT_CLIGS_SHOW_GVG_MVP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SHOW_GVG_MVP_ACK)); }
	UINT16           wErrCode; //������
	UINT64           qwVideoID; //¼��ID
	DT_GVG_MVP_LIST  stMVPList; //¼����
}PKT_CLIGS_SHOW_GVG_MVP_ACK;

typedef struct tagPKT_CLIGS_SELECT_GROUP_TYPE_REQ{
	tagPKT_CLIGS_SELECT_GROUP_TYPE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SELECT_GROUP_TYPE_REQ)); }
	UINT8            bySelect; //ɸѡ���� ��em_Join_Type��
}PKT_CLIGS_SELECT_GROUP_TYPE_REQ;

typedef struct tagPKT_CLIGS_SELECT_GROUP_TYPE_ACK{
	tagPKT_CLIGS_SELECT_GROUP_TYPE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SELECT_GROUP_TYPE_ACK)); }
	UINT16           wErrCode; //������
	DT_COURAGE_GROUP_DATA_CLI_LST stGroupData; //������Ϣ�б�
	UINT8            bySelect; //ɸѡ������em_Join_Type��
}PKT_CLIGS_SELECT_GROUP_TYPE_ACK;

typedef struct tagPKT_CLIGS_GVG_FACTION_APPLAY_REQ{
	tagPKT_CLIGS_GVG_FACTION_APPLAY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_FACTION_APPLAY_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_GVG_FACTION_APPLAY_REQ;

typedef struct tagPKT_CLIGS_GVG_FACTION_APPLAY_ACK{
	tagPKT_CLIGS_GVG_FACTION_APPLAY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GVG_FACTION_APPLAY_ACK)); }
	UINT16           wErrCode; //������
}PKT_CLIGS_GVG_FACTION_APPLAY_ACK;

typedef struct tagPKT_CLIGS_READ_BATTLE_LOG_REQ{
	tagPKT_CLIGS_READ_BATTLE_LOG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_READ_BATTLE_LOG_REQ)); }
	UINT8            byKindID; //��ȡ����
}PKT_CLIGS_READ_BATTLE_LOG_REQ;

typedef struct tagDT_BATTLE_LOG_MSG_CLI{
	UINT8            byLogType; //ս��С����
	UINT64           qwLogTime; //ս��ʱ��
	UINT8            byParamNum; //��������
	UINT64           aqwParamLst[MAX_BATTLE_LOG_PARAM_NUM]; //����
	UINT8            byStrNum; //�ַ�������
	DT_TSTRING_MSG   astStrLst[MAX_BATTLE_LOG_PARAM_STR]; //�ַ���
}DT_BATTLE_LOG_MSG_CLI;

typedef struct tagDT_BATTLE_LOG_MSG_LST_CLI{
	UINT8            byLogNum; //ս������
	DT_BATTLE_LOG_MSG_CLI astLogData[MAX_BATTLE_LOG_NUM]; //ս����Ϣ
}DT_BATTLE_LOG_MSG_LST_CLI;

typedef struct tagPKT_CLIGS_READ_BATTLE_LOG_ACK{
	tagPKT_CLIGS_READ_BATTLE_LOG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_READ_BATTLE_LOG_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byLogType; //ս��������
	DT_BATTLE_LOG_MSG_LST_CLI stLogInfo; //ս����Ϣ
}PKT_CLIGS_READ_BATTLE_LOG_ACK;

typedef struct tagDT_BATTLE_LOG_UNREAD_INFO{
	UINT8            byLogType; //ս������EBattleLogType
	UINT8            byUnReadNum; //δ������
}DT_BATTLE_LOG_UNREAD_INFO;

typedef struct tagPKT_CLIGS_UNREAD_BATTLE_NTF{
	tagPKT_CLIGS_UNREAD_BATTLE_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_UNREAD_BATTLE_NTF)); }
	UINT8            byLogNum; //ս��������
	DT_BATTLE_LOG_UNREAD_INFO astLogInfo[MAX_BATTLE_LOG_NUM]; //ս����Ϣ
}PKT_CLIGS_UNREAD_BATTLE_NTF;

typedef struct tagPKT_CLIGS_BATTLE_ACK4{
	tagPKT_CLIGS_BATTLE_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_BATTLE_ACK4)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_ENCOURAGE_DATA stBattleEncourage; //ս������
	DT_DATA_AFTER_BATTLE_ENCOURAGE stAfterBattleEncourage; //��ȡս�������������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_PASS_ENCOURAGE_DATA astPassEncourage[1]; //ͨ�ؽ���
	DT_DATA_AFTER_PASS_ENCOURAGE astAfterPassEncourage[1]; //��ȡͨ�ؽ����������Ϣ
	DT_PASS_ENCOURAGE_BOX_DATA astPassEncourageBox[1]; //ͨ�ر��佱����Ϣ
	DT_UNLOCK_DATA   astUnlockInfo[1]; //������Ϣ
	UINT8            byHaveNextInstance; //�Ƿ�����һ������
	DT_NEXT_INSTANCE_DATA astNextInstanceInfo[1]; //��һ��������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	TCHAR            aszExtContext[MAX_COMMON_TXT_LEN]; //��չ��Ϣ
	DT_BATTLE_DATA4  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_BATTLE_ACK4;

typedef struct tagPKT_CLIGS_CHALLENGE_ACK4{
	tagPKT_CLIGS_CHALLENGE_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_ACK4)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //�Է������Ϣ
	UINT8            byEnemyHeroNum; //�Է���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //�Է���Ϣ
	DT_RACE_CHALLENGE_ENCOURAGE_DATA stChallengeEncourage; //��ս����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ����
	UINT64           qwCurJingJie; //��ҵ�ǰ�ľ����
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_BATTLE_DATA4  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_CHALLENGE_ACK4;

typedef struct tagPKT_CLIGS_PLUNDER_ACK4{
	tagPKT_CLIGS_PLUNDER_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_PLUNDER_ACK4)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwEnemyID; //Ҫս�������ID
	UINT32           dwCaptureID; //��²���ID(��EnemyID��ͬ��ʾ�Ӷ����CaptureID��ң���ͬ��ʾ����CaptureID��²)
	UINT8            byUseItemFlag; //�Ƿ�ʹ�õ����Ӷ����5�����ϵ����
	UINT8            byResistFlag; //�Ƿ񷴿�(1��ʾ����)
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
	DT_BECAPTURE_DATA stBeCaptureInfo; //��²��ҵı�����Ϣ
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //ս���з������Ϣ
	UINT8            byEnemyHeroNum; //ս���з���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //ս���з���Ϣ
	DT_PLUNDER_ENCOURAGE_DATA stPlunderEncourage; //�Ӷά��
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
	UINT16           wVipExtNum; //VIP�������ӵĴ���
	UINT16           wFreePlunderNum; //�������Ӷ����
	UINT32           dwPlunderGold; //�շ��Ӷ�Ԫ��(��������ѵ���Ϊ0)
	UINT16           wPlunderItemNum; //��ǰӵ�е��Ӷ����
	UINT8            byCaptureFlag; //�Ƿ��²��ң�1Ϊ�Է���Ϊ��ķ�²
	DT_CAPTURE_DATA_CLI astCaptureInfo[1]; //��²��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_BATTLE_DATA4  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_PLUNDER_ACK4;

typedef struct tagPKT_CLIGS_PKBATTLE_ACK4{
	tagPKT_CLIGS_PKBATTLE_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_PKBATTLE_ACK4)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA4  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_PKBATTLE_ACK4;

typedef struct tagPKT_CLIGS_RDCHALLENGE_ACK4{
	tagPKT_CLIGS_RDCHALLENGE_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_RDCHALLENGE_ACK4)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RDC_TAB_DATA  stTabInfo; //�����ս�����Ϣ
	DT_RDC_ENC_DATA  stEncInfo; //�����ս������Ϣ
	UINT64           qwCurJingJie; //��ǰ�����
	UINT64           qwCurPurpleGas; //��ǰ����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT16           wKindID; //��õ��ʻ�ID
	DT_BATTLE_DATA4  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_RDCHALLENGE_ACK4;

typedef struct tagPKT_CLIGS_HUNTING_BATTLE_ACK3{
	tagPKT_CLIGS_HUNTING_BATTLE_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_HUNTING_BATTLE_ACK3)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_REWARD_INFO   stBattleReward; //ս������
	DT_HUNTING_SCHEDULE_INFO stTaskScheduleInfo; //���������Ϣ
	UINT32           dwClosedMonsterNeedGold; //������Ҫ��Ԫ��
	TCHAR            aszBattleLostMsg[MAX_FACTION_DESC_NUM]; //ս��ʧ����Ϣ
	UINT32           dwSyncDoorsTribute; //ͬ������
	UINT8            byScheduleChangeFlag; //�����ı��ʶ��0 û�䣬 1�䣩
	UINT8            byHuntingLeftNum; //׽������ͬ��
	UINT8            byIsGoldMode; //�Ƿ��ڻƽ�ģʽ
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
	DT_BATTLE_DATA4  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_HUNTING_BATTLE_ACK3;

typedef struct tagDT_COURAGE_PLAYER_BATTLE_DATA3{
	UINT8            byBattleNum; //ս������
	DT_BATTLE_DATA4  astBattleInfo[MAX_COURAGE_MEMBER_NUM]; //ս����Ϣ
}DT_COURAGE_PLAYER_BATTLE_DATA3;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_START_ACK3{
	tagPKT_CLIGS_COURAGE_PLAYER_START_ACK3() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_START_ACK3)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_MONSTER_DATA_LIST stMonsterInfo; //������Ϣ
	DT_COURAGE_GROUP_PLAYER_BATTLE_DATA stGroupPlayerInfo; //������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ�� 0ͨ�� 1��ͨ��
	DT_INSTANCE_ID   stInstanceID; //�������
	DT_COURAGE_JEWELRY_DATA_LST stjewelryInfoLst; //��Ʒ��Ϣ
	UINT8            byHelpID; //Э������ 1�ٽ���1�Σ� 2Э��������1�Σ�3�Ѿ����Ͳ�����������
	DT_COURAGE_PLAYER_BATTLE_DATA3 stBattleInfoCli; //ս����Ϣ
}PKT_CLIGS_COURAGE_PLAYER_START_ACK3;

typedef struct tagPKT_CLIGS_COURAGE_LEADER_START_NTF3{
	tagPKT_CLIGS_COURAGE_LEADER_START_NTF3() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_LEADER_START_NTF3)); }
	PKT_CLIGS_COURAGE_PLAYER_START_ACK3 stBattleInfo; //ս����Ϣ
}PKT_CLIGS_COURAGE_LEADER_START_NTF3;

typedef struct tagPKT_CLIGS_BEGIN_JIEBIAO_ACK4{
	tagPKT_CLIGS_BEGIN_JIEBIAO_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGIN_JIEBIAO_ACK4)); }
	UINT16           wErrCode; //������
	UINT8            byYabiaoFlag; //Ѻ�ڱ�ʶ(0Ϊ����Ѻ�ڣ�1Ϊ����Ѻ���У�2ΪѺ����ϣ�������ȡ����)
	UINT64           qwCoinEncourage; //����
	UINT32           dwScienceEncourage; //�������꽱��
	UINT64           qwCurCoin; //��ǰͭǮ��
	UINT64           qwCurScience; //��ǰ����
	UINT32           dwBeJiebiaoPlayerID; //�����ض���
	BIAO_OPERATE_INFO stBeJiebiaoInfo; //������Ϣ
	UINT32           dwJiebiaoPlayerID; //���ض���
	BIAO_OPERATE_INFO stJiebiaoInfo; //������Ϣ
	UINT16           wJiebiaoCD; //��ȴʱ��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_BATTLE_DATA4  stBattleData; //ս����Ϣ
}PKT_CLIGS_BEGIN_JIEBIAO_ACK4;

typedef struct tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK4{
	tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK4() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK4)); }
	UINT16           wErrCode; //������
	DT_BATTLE_DATA4  stBattleData; //ս����Ϣ
}PKT_CLIGS_QUERY_BATTLE_RECORD_ACK4;

typedef struct tagDT_CLIGS_SOUL_MARK_DATA{
	UINT16           wHeroId; //0��������ս�� Ӣ��id��Ӧ���ϵ�ս��
	UINT16           wSoulID; //ս��ID
	UINT32           dwSoulIdx; //ս��IDX
}DT_CLIGS_SOUL_MARK_DATA;

typedef struct tagDT_CLIGS_SOUL_MARK_LST_DATA{
	UINT16           wSoulNum; //ս����
	DT_CLIGS_SOUL_MARK_DATA astSoulLstMark[MAX_SOUL_BAG_NUM]; //ս���ʶ
}DT_CLIGS_SOUL_MARK_LST_DATA;

typedef struct tagPKT_CLIGS_OPEN_DEVOUR_SOUL_REQ{
	tagPKT_CLIGS_OPEN_DEVOUR_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DEVOUR_SOUL_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stSoulID; //ս����Ϣ
}PKT_CLIGS_OPEN_DEVOUR_SOUL_REQ;

typedef struct tagPKT_CLIGS_OPEN_DEVOUR_SOUL_ACK{
	tagPKT_CLIGS_OPEN_DEVOUR_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DEVOUR_SOUL_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_DATA_LST_CLI stSoulBag; //ս�걳��
	DT_SOUL_DATA_CLI stMainSoul; //��ս����Ϣ
	DT_PLAYER_RES_LST_DATA stResData; //��Դ��Ϣ
	DT_PLAYER_RES_DATA stCostRes; //����������Դ��Ϣ
	UINT8            byAttrUpPer; //���������ٷֱ�
	DT_SOUL_POTENCY_CLI stPotencyInfo; //Ǳ����Ϣ
}PKT_CLIGS_OPEN_DEVOUR_SOUL_ACK;

typedef struct tagPKT_CLIGS_DEVOUR_SOUL_REQ{
	tagPKT_CLIGS_DEVOUR_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DEVOUR_SOUL_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stMainSoul; //��ս��
	DT_CLIGS_SOUL_MARK_LST_DATA stDevourSoul; //����ս��
}PKT_CLIGS_DEVOUR_SOUL_REQ;

typedef struct tagPKT_CLIGS_DEVOUR_SOUL_ACK{
	tagPKT_CLIGS_DEVOUR_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DEVOUR_SOUL_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_DATA_LST_CLI stSoulBag; //ս�걳��
	DT_SOUL_DATA_CLI stMainSoul; //��ս����Ϣ
	DT_PLAYER_RES_LST_DATA stResData; //��Դ��Ϣ
	DT_PLAYER_RES_DATA stCostRes; //����������Դ��Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
	DT_HERO_PANEL_CLI stHeroInfo; //Ӣ������
	UINT8            byAttrUpPer; //���������ٷֱ�
}PKT_CLIGS_DEVOUR_SOUL_ACK;

typedef struct tagPKT_CLIGS_OPEN_REFLASH_SOUL_REQ{
	tagPKT_CLIGS_OPEN_REFLASH_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_REFLASH_SOUL_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stMainSoul; //��ս��
}PKT_CLIGS_OPEN_REFLASH_SOUL_REQ;

typedef struct tagPKT_CLIGS_OPEN_REFLASH_SOUL_ACK{
	tagPKT_CLIGS_OPEN_REFLASH_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_REFLASH_SOUL_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_DATA_CLI stSoulData; //ս��
	DT_PLAYER_RES_LST_DATA stResData; //��Դ��Ϣ
	DT_PLAYER_RES_DATA stCostRes; //ϴ��������Դ��Ϣ
}PKT_CLIGS_OPEN_REFLASH_SOUL_ACK;

typedef struct tagPKT_CLIGS_REFLASH_SOUL_REQ{
	tagPKT_CLIGS_REFLASH_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REFLASH_SOUL_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stMainSoul; //��ս��
	UINT8            byLockNum; //��������
	UINT8            abyLockIDLst[MAX_SOUL_ATTR_NUM]; //�������
}PKT_CLIGS_REFLASH_SOUL_REQ;

typedef struct tagPKT_CLIGS_REFLASH_SOUL_ACK{
	tagPKT_CLIGS_REFLASH_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REFLASH_SOUL_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_DATA_CLI stSoulData; //ս��
	DT_PLAYER_RES_LST_DATA stResData; //��Դ��Ϣ
}PKT_CLIGS_REFLASH_SOUL_ACK;

typedef struct tagPKT_CLIGS_SAVE_REFLASH_SOUL_REQ{
	tagPKT_CLIGS_SAVE_REFLASH_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SAVE_REFLASH_SOUL_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stMainSoul; //��ս��
	UINT8            byIsSave; //������0�������� 1������
}PKT_CLIGS_SAVE_REFLASH_SOUL_REQ;

typedef struct tagPKT_CLIGS_SAVE_REFLASH_SOUL_ACK{
	tagPKT_CLIGS_SAVE_REFLASH_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SAVE_REFLASH_SOUL_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_DATA_CLI stSoulData; //ս��
	DT_PLAYER_RES_LST_DATA stResData; //��Դ��Ϣ
	DT_PLAYER_RES_DATA stCostRes; //ϴ��������Դ��Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
	DT_CLIGS_SOUL_MARK_DATA stMainSoul; //��ս����Ϣ
	DT_HERO_PANEL_CLI stHeroInfo; //Ӣ������
}PKT_CLIGS_SAVE_REFLASH_SOUL_ACK;

typedef struct tagDT_CLIGS_PRODUCTSOUL_COST{
	UINT8            byCostType; //�������� 2����ͭǮ 3����Ԫ��
	UINT32           dwCostNum; //������Ŀ
}DT_CLIGS_PRODUCTSOUL_COST;

typedef struct tagDT_SOUL_REP_INFO{
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
	DT_CLIGS_PRODUCTSOUL_COST astNormalCost[MAX_SOUL_PRODUCT_TYPE]; //��ͨ̽�����ֲ������ͻ���
	DT_CLIGS_PRODUCTSOUL_COST astContinusCost[MAX_SOUL_PRODUCT_TYPE]; //10��̽�����ֲ������ͻ���
	UINT8            abyMinStar[MAX_SOUL_PRODUCT_TYPE]; //���������С�Ǽ�
	UINT8            abyMaxStar[MAX_SOUL_PRODUCT_TYPE]; //�����������Ǽ�
}DT_SOUL_REP_INFO;

typedef struct tagPKT_CLIGS_SOULREP_INFO_REQ{
	tagPKT_CLIGS_SOULREP_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SOULREP_INFO_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_SOULREP_INFO_REQ;

typedef struct tagPKT_CLIGS_SOULREP_INFO_ACK{
	tagPKT_CLIGS_SOULREP_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SOULREP_INFO_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_REP_INFO stSoulRepInfo; //ս�긱����Ϣ
	UINT8            byOpenActivity; //0����û����� 1�������
}PKT_CLIGS_SOULREP_INFO_ACK;

typedef struct tagPKT_CLIGS_PRODUCT_SOUL_REQ{
	tagPKT_CLIGS_PRODUCT_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PRODUCT_SOUL_REQ)); }
	UINT8            byProductType; //����������� ֵС��MAX_SOUL_PRODUCT_TYPE
	UINT8            bySearchType; //0Ϊ��ͨ̽�� 1Ϊ10��̽��
}PKT_CLIGS_PRODUCT_SOUL_REQ;

typedef struct tagPKT_CLIGS_PRODUCT_SOUL_ACK{
	tagPKT_CLIGS_PRODUCT_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PRODUCT_SOUL_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byMeterialNum; //��������ս�����
	DT_GOODS_DATA_CLI astMeterialGood[MAX_SOUL_CONTINUE_SEARCH]; //��õ�ս�����
	UINT8            bySoulNum; //��������ս��
	DT_SOUL_DATA_CLI astSoulData[MAX_SOUL_CONTINUE_SEARCH]; //��õ�ս��
	DT_SOUL_REP_INFO stSoulRepInfo; //ս�긱����Ϣ
	UINT8            byBoxType; //������̬ 0ͭ 1�� 2��
}PKT_CLIGS_PRODUCT_SOUL_ACK;

typedef struct tagPKT_CLIGS_HERO_EQUIP_SOUL_REQ{
	tagPKT_CLIGS_HERO_EQUIP_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_HERO_EQUIP_SOUL_REQ)); }
	UINT16           wHeroId; //Ӣ��id
	UINT16           wSoulID; //ս�걳����Ҫ��Ӣ�۴���ս��ID
	UINT32           dwSoulIdx; //ս�걳����Ҫ��Ӣ�۴���ս��index
}PKT_CLIGS_HERO_EQUIP_SOUL_REQ;

typedef struct tagPKT_CLIGS_HERO_EQUIP_SOUL_ACK{
	tagPKT_CLIGS_HERO_EQUIP_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_HERO_EQUIP_SOUL_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wSoulID; //ս�걳����Ҫ��Ӣ�۴���ս��ID
	UINT32           dwSoulIdx; //ս�걳����Ҫ��Ӣ�۴���ս��index
	DT_POWER_CHANGE_DATA stPowerInfo; //ս�걳����Ҫ��Ӣ�۴���ս��index
	DT_HERO_PANEL_CLI stHeroInfo; //ս�걳����Ҫ��Ӣ�۴���ս��index
}PKT_CLIGS_HERO_EQUIP_SOUL_ACK;

typedef struct tagPKT_CLIGS_HERO_UNDRESS_SOUL_REQ{
	tagPKT_CLIGS_HERO_UNDRESS_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_HERO_UNDRESS_SOUL_REQ)); }
	UINT16           wHeroId; //Ӣ��id
	UINT16           wSoulID; //Ӣ������װ���� ׼������ս��ID
	UINT32           dwSoulIdx; //Ӣ������װ���� ׼������ս��index
}PKT_CLIGS_HERO_UNDRESS_SOUL_REQ;

typedef struct tagPKT_CLIGS_HERO_UNDRESS_SOUL_ACK{
	tagPKT_CLIGS_HERO_UNDRESS_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_HERO_UNDRESS_SOUL_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wSoulID; //Ӣ������װ���� ׼������ս��ID
	UINT32           dwSoulIdx; //Ӣ������װ���� ׼������ս��index
	DT_POWER_CHANGE_DATA stPowerInfo; //Ӣ������װ���� ׼������ս��index
	DT_HERO_PANEL_CLI stHeroInfo; //Ӣ������װ���� ׼������ս��index
}PKT_CLIGS_HERO_UNDRESS_SOUL_ACK;

typedef struct tagPKT_CLIGS_HERO_REPLACE_SOUL_REQ{
	tagPKT_CLIGS_HERO_REPLACE_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_HERO_REPLACE_SOUL_REQ)); }
	UINT16           wHeroId; //Ӣ��id
	UINT16           wBagSoulID; //ս�걳����Ҫ��Ӣ�۴���ս��ID
	UINT32           dwBagSoulIdx; //ս�걳����Ҫ��Ӣ�۴���ս��index
	UINT16           wHeroSoulID; //Ӣ������װ���� ׼������ս��ID
	UINT32           dwHeroSoulIdx; //Ӣ������װ���� ׼������ս��index
}PKT_CLIGS_HERO_REPLACE_SOUL_REQ;

typedef struct tagPKT_CLIGS_HERO_REPLACE_SOUL_ACK{
	tagPKT_CLIGS_HERO_REPLACE_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_HERO_REPLACE_SOUL_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wBagSoulID; //ս�걳����Ҫ��Ӣ�۴���ս��ID
	UINT32           dwBagSoulIdx; //ս�걳����Ҫ��Ӣ�۴���ս��index
	UINT16           wHeroSoulID; //Ӣ������װ���� ׼������ս��ID
	UINT32           dwHeroSoulIdx; //Ӣ������װ���� ׼������ս��index
	DT_POWER_CHANGE_DATA stPowerInfo; //Ӣ������װ���� ׼������ս��index
	DT_HERO_PANEL_CLI stHeroInfo; //Ӣ������װ���� ׼������ս��index
}PKT_CLIGS_HERO_REPLACE_SOUL_ACK;

typedef struct tagDT_SOUL_EXCHANGE_METERIAL{
	UINT32           dwMeterialID; //����ID
	UINT32           dwMeterialNum; //��������
}DT_SOUL_EXCHANGE_METERIAL;

typedef struct tagDT_SOUL_EXCHANGE_CARD{
	UINT32           dwID; //�һ���ID
	TCHAR            aszName[MAX_SOUL_CARD_NAME_LENGTH]; //�һ�������
	UINT8            byMeterialNum; //�һ���Ҫ�Ĳ�������
	DT_SOUL_EXCHANGE_METERIAL astMeterialInfo[MAX_EXCHANGE_SOUL_METERIAL_NUM]; //�һ��Ĳ�����Ϣ
}DT_SOUL_EXCHANGE_CARD;

typedef struct tagPKT_CLIGS_SOULEXCHANGE_INFO_REQ{
	tagPKT_CLIGS_SOULEXCHANGE_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SOULEXCHANGE_INFO_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_SOULEXCHANGE_INFO_REQ;

typedef struct tagPKT_CLIGS_SOULEXCHANGE_INFO_ACK{
	tagPKT_CLIGS_SOULEXCHANGE_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SOULEXCHANGE_INFO_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byExchangeCardNum; //�һ�������
	DT_SOUL_EXCHANGE_CARD astExchangeCardInfo[MAX_EXCHANGE_SOUL_CARD_NUM]; //�һ�����Ϣ
	UINT8            byMeterialNum; //�����һ���������
	DT_GOODS_DATA_CLI astMeterialInfo[MAX_BAG_OPEN_NUM]; //�����һ�������Ϣ
}PKT_CLIGS_SOULEXCHANGE_INFO_ACK;

typedef struct tagPKT_CLIGS_EXCHANGE_SOUL_REQ{
	tagPKT_CLIGS_EXCHANGE_SOUL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_SOUL_REQ)); }
	UINT32           dwSoulExchangeId; //ս���仯��Ϣ
	UINT32           dwExchangeNum; //ս���仯��Ϣ
}PKT_CLIGS_EXCHANGE_SOUL_REQ;

typedef struct tagPKT_CLIGS_EXCHANGE_SOUL_ACK{
	tagPKT_CLIGS_EXCHANGE_SOUL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_SOUL_ACK)); }
	UINT16           wErrCode; //������
	UINT8            bySoulNum; //�һ���������
	DT_SOUL_DATA_CLI astSoulInfo[MAX_EXCHANGE_SOUL_NUM]; //�һ���õĽ���
	UINT8            byMeterialNum; //�����һ���������
	DT_GOODS_DATA_CLI astMeterialInfo[MAX_BAG_OPEN_NUM]; //�����һ�������Ϣ
}PKT_CLIGS_EXCHANGE_SOUL_ACK;

typedef struct tagPKT_CLIGS_OPEN_MY_MEDAL_REQ{
	tagPKT_CLIGS_OPEN_MY_MEDAL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MY_MEDAL_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_MY_MEDAL_REQ;

typedef struct tagPKT_CLIGS_OPEN_MY_MEDAL_ACK{
	tagPKT_CLIGS_OPEN_MY_MEDAL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_MY_MEDAL_ACK)); }
	UINT16           wErrCode; //������
	DT_ATTR_BASE_LST_DATA stAttrInfo; //�����ۼ�
	DT_MEDAL_DATA_LST_CLI stMedalLstInfo; //ѫ����Ϣ
}PKT_CLIGS_OPEN_MY_MEDAL_ACK;

typedef struct tagDT_MEDAL_ICON_NAME{
	TCHAR            aszMedalIconName[MAX_NAME_LEN]; //ս���仯��Ϣ
}DT_MEDAL_ICON_NAME;

typedef struct tagDT_MEDAL_ICON_ID_LST_CLI{
	UINT16           wMedalNum; //ѫ�¸���
	DT_MEDAL_ICON_NAME astMedalIconID[MAX_MEDAL_NUM]; //����
}DT_MEDAL_ICON_ID_LST_CLI;

typedef struct tagPKT_CLIGS_MEDAL_NTF{
	tagPKT_CLIGS_MEDAL_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_MEDAL_NTF)); }
	DT_MEDAL_ICON_ID_LST_CLI stUnLockMedal; //����ѫ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
}PKT_CLIGS_MEDAL_NTF;

typedef struct tagPKT_CLIGS_OPEN_OUT_BOUND_REQ{
	tagPKT_CLIGS_OPEN_OUT_BOUND_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_OUT_BOUND_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_OUT_BOUND_REQ;

typedef struct tagDT_OUT_BOUND_DETAIL_DATA{
	DT_INSTANCE_ID   stInstanceID; //�������
	TCHAR            aszInstanceName[NORMAL_MSG_LEN]; //��������
	UINT8            byLeftCrossNum; //����ÿ��ʣ�ള�ش���
	UINT8            byState; //�Ƿ�ɹһ�0������1�ɹһ���2δ����(�ȼ�����)��3��һ����δ�������ȼ����ˣ�
	UINT16           wLevelReq; //����Ҫ��
	UINT8            byIsMajor; //�Ƿ�����Ҫ����������
	DT_PLAYER_RES_LST_DATA stResInfo; //ʤ�����
	DT_ITEM_DATA_LIST_LESS_CLI3 stItemInfo; //���ʻ��
}DT_OUT_BOUND_DETAIL_DATA;

typedef struct tagDT_OUT_BOUND_DETAIL_LST_DATA{
	UINT8            byInstanceNum; //��������
	DT_OUT_BOUND_DETAIL_DATA astInstanceInfo[MAX_OUT_BOUND_INSTANCE_NUM]; //������Ϣ
	UINT8            bySelectIdx; //��ǰѡ�еڼ�Ļ
}DT_OUT_BOUND_DETAIL_LST_DATA;

typedef struct tagDT_OUT_BOUND_SIMPLE_DATA{
	UINT16           wScenceIdx; //����IDX
	UINT8            byTownIdx; //����IDX
	UINT8            byState; //״̬(0������1δ������2δ����,3���سɹ�)
	TCHAR            aszUnlockReq[MAX_OUT_BOUND_DESC_LEN]; //����Ҫ��
	TCHAR            aszHeroDesc[MAX_OUT_BOUND_DESC_LEN]; //Ӣ�۽�������
	TCHAR            aszItemDesc[MAX_OUT_BOUND_DESC_LEN]; //��Ʒ��������
}DT_OUT_BOUND_SIMPLE_DATA;

typedef struct tagPKT_CLIGS_OPEN_OUT_BOUND_ACK{
	tagPKT_CLIGS_OPEN_OUT_BOUND_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_OUT_BOUND_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_RES_LST_DATA stResInfo; //��Դ��Ϣ
	UINT8            byOutBoundNum; //�⴫����
	DT_OUT_BOUND_SIMPLE_DATA astOutBoundInfo[MAX_OUT_BOUND_NUM]; //�⴫��Ϣ
}PKT_CLIGS_OPEN_OUT_BOUND_ACK;

typedef struct tagPKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ{
	tagPKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ)); }
	UINT8            byTownIdx; //����IDX
}PKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ;

typedef struct tagPKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK{
	tagPKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK)); }
	UINT16           wErrCode; //������
	DT_OUT_BOUND_DETAIL_LST_DATA stInstanceLstInfo; //������Ϣ
}PKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK;

typedef struct tagPKT_CLIGS_OUT_BOUND_BATTLE_REQ{
	tagPKT_CLIGS_OUT_BOUND_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OUT_BOUND_BATTLE_REQ)); }
	DT_INSTANCE_ID   stInstanceID; //����ID
	UINT8            byIsHook; //�Ƿ�һ�0���һ���1�һ�
}PKT_CLIGS_OUT_BOUND_BATTLE_REQ;

typedef struct tagPKT_CLIGS_OUT_BOUND_BATTLE_ACK{
	tagPKT_CLIGS_OUT_BOUND_BATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OUT_BOUND_BATTLE_ACK)); }
	UINT16           wErrCode; //������
	DT_OUT_BOUND_DETAIL_LST_DATA stInstanceLstInfo; //������Ϣ
	UINT8            byHaveBattleInfo; //�Ƿ���Ҫս����Ϣ0����Ҫ��1��Ҫ
	DT_BATTLE_DATA5  astBattleInfo[1]; //ս����Ϣ
	DT_BATTLE_ENCOURAGE_DATA stBattleEncourage; //ս������
	DT_DATA_AFTER_BATTLE_ENCOURAGE stAfterBattleEncourage; //��ȡս�������������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_PASS_ENCOURAGE_DATA astPassEncourage[1]; //ͨ�ؽ���
	DT_DATA_AFTER_PASS_ENCOURAGE astAfterPassEncourage[1]; //��ȡͨ�ؽ����������Ϣ
	DT_PASS_ENCOURAGE_BOX_DATA astPassEncourageBox[1]; //ͨ�ر��佱����Ϣ
	DT_PLAYER_RES_LST_DATA stResInfo; //��Դ��Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_OUT_BOUND_BATTLE_ACK;

typedef struct tagPKT_CLIGS_OPEN_STORE_REQ{
	tagPKT_CLIGS_OPEN_STORE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STORE_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_STORE_REQ;

typedef struct tagDT_GOODS_EXCHANGE_INFO{
	DT_PLAYER_RES_DATA stResReq; //�һ�Ҫ����Դ
	DT_ITEM_DATA_CLI3 stGoodsInfo; //��Ʒ��Ϣ
}DT_GOODS_EXCHANGE_INFO;

typedef struct tagDT_GOODS_EXCHANGE_LST_INFO{
	UINT16           wGoodsNum; //��Ʒ����
	DT_GOODS_EXCHANGE_INFO astGoodsInfo[MAX_BAG_OPEN_NUM_NEW]; //��Ʒ��Ϣ
}DT_GOODS_EXCHANGE_LST_INFO;

typedef struct tagPKT_CLIGS_OPEN_STORE_ACK{
	tagPKT_CLIGS_OPEN_STORE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STORE_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_RES_LST_DATA stResInfo; //��Դ��Ϣ
	DT_GOODS_EXCHANGE_LST_INFO stItemInfo; //��Ʒ��Ϣ
}PKT_CLIGS_OPEN_STORE_ACK;

typedef struct tagPKT_CLIGS_EXCHANGE_GOODS_REQ{
	tagPKT_CLIGS_EXCHANGE_GOODS_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_GOODS_REQ)); }
	UINT16           wGoodsID; //��ƷID
	UINT16           wGoodsNum; //��Ʒ����
}PKT_CLIGS_EXCHANGE_GOODS_REQ;

typedef struct tagPKT_CLIGS_EXCHANGE_GOODS_ACK{
	tagPKT_CLIGS_EXCHANGE_GOODS_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EXCHANGE_GOODS_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_RES_LST_DATA stResInfo; //��Դ��Ϣ
	UINT16           wItemsID; //��Ʒ��Ϣ
	UINT16           wItemNum; //��Ʒ����
}PKT_CLIGS_EXCHANGE_GOODS_ACK;

typedef struct tagDT_SKILL_INFO{
	UINT16           wSkillID; //����ID
	UINT8            byHurtPeople; //�˺�����
	UINT16           wHurtRate; //�˺�����
	UINT16           wSpecialParam; //��Ч����1
	UINT8            byBeginRound; //��ʼ���ûغ�
	UINT16           wFinalHurtRate; //�����˺��ӳ�
	UINT16           wBuffParam; //BUFF����
	UINT8            byBuffRound; //BUFF���ûغ���
}DT_SKILL_INFO;

typedef struct tagDT_SKILL_LST_INFO{
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_INFO    astSkillInfo[MAX_PET_SKILL_NUM]; //������Ϣ
}DT_SKILL_LST_INFO;

typedef struct tagDT_PET_CLI_DATA{
	UINT16           wPetId; //idΨһ��־
	UINT8            byStarLv; //�ǽ�
	UINT16           wLv; //�ȼ�
	UINT16           wMaxLv; //�ȼ�����
	UINT32           dwLvExp; //�ȼ�����
	UINT32           dwNextLvExp; //��һ�ȼ�����
	TCHAR            aszPetName[MAX_PET_NAME_LENGTH]; //����
	UINT32           dwCurPhychicVal; //��ǰ��������
	UINT32           dwMaxPhychicVal; //������������
	UINT32           dwCurLingli; //����ֵ
	UINT32           dwBeAteExp; //���Ե�����
	TCHAR            aszPetPic[MAX_PET_NAME_LENGTH]; //����ͼƬ
	UINT8            byPetState; //��������¼
	DT_PET_WASHQUALITY_DATA astWashQualityData[MAX_PET_WASH_PSYCHIC_CELL_CNT]; //����ϴ��������Ϣ
	UINT8            byIsUpStar; //�Ƿ������� 0�� 1��
	UINT8            byPetColor; //������ɫ
	DT_SKILL_LST_INFO stSkillInfo; //������Ϣ
	UINT8            byPetQuality; //����Ʒ��
	UINT8            byPetType; //����Ʒ��
	UINT16           wPetCfgID; //����ID
	UINT64           qwScore; //����
}DT_PET_CLI_DATA;

typedef struct tagDT_PET_CLI_DATA_LST{
	UINT16           wPetNum; //��������
	DT_PET_CLI_DATA  astPetData[MAX_PET_NUM]; //��������
}DT_PET_CLI_DATA_LST;

typedef struct tagPKT_CLIGS_PETREP_INFO_REQ{
	tagPKT_CLIGS_PETREP_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PETREP_INFO_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_PETREP_INFO_REQ;

typedef struct tagPKT_CLIGS_PETREP_INFO_ACK{
	tagPKT_CLIGS_PETREP_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PETREP_INFO_ACK)); }
	UINT16           wErrCode; //������
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
	UINT32           dwNormalCostGold; //��ͨ�ٻ�����Ԫ��
	UINT32           dwGoodCostGold; //�����ٻ�����Ԫ��
	UINT32           dwNormalLeftTime; //��ͨ�ٻ���������ٻ���ʱ��
	UINT32           dwGoodLeftTime; //�����ٻ���������ٻ���ʱ��
	UINT32           dwNormalFreeCnt; //������ͨʣ�����
	UINT8            byRuleFlag; //�����ʶ(0,������1��)
}PKT_CLIGS_PETREP_INFO_ACK;

typedef struct tagPKT_CLIGS_PRODUCT_PET_REQ{
	tagPKT_CLIGS_PRODUCT_PET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PRODUCT_PET_REQ)); }
	UINT8            byProductType; //�������� 1ΪA�� 2ΪB��
}PKT_CLIGS_PRODUCT_PET_REQ;

typedef struct tagPKT_CLIGS_PRODUCT_PET_ACK{
	tagPKT_CLIGS_PRODUCT_PET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PRODUCT_PET_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byGoodNum; //����������Ʒ
	DT_GOODS_DATA_CLI astPetGood[MAX_PRODUCTPET_EXTRA_ITEM_NUM]; //��õ���Ʒ
	UINT8            byPetNum; //������ֻ����
	DT_PET_CLI_DATA  astPetData[MAX_PRODUCTPET_NUM]; //������������
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
	UINT32           dwNormalCostGold; //��ͨ�ٻ�����Ԫ��
	UINT32           dwGoodCostGold; //�����ٻ�����Ԫ��
	UINT32           dwNormalLeftTime; //��ͨ�ٻ���������ٻ���ʱ��
	UINT32           dwGoodLeftTime; //�����ٻ���������ٻ���ʱ��
	UINT32           dwNormalFreeCnt; //������ͨʣ�����
}PKT_CLIGS_PRODUCT_PET_ACK;

typedef struct tagDT_STAR_DRAGON_ITEM_INFO{
	UINT32           dwItemID; //����ID
	UINT32           dwItemNum; //��������
}DT_STAR_DRAGON_ITEM_INFO;

typedef struct tagDT_UP_STAR_INFO{
	UINT16           wStarLv; //ս���仯��Ϣ
	UINT16           wLingliPer; //ս���仯��Ϣ
	UINT16           wLvLimit; //ս���仯��Ϣ
}DT_UP_STAR_INFO;

typedef struct tagPKT_CLIGS_OPEN_STAR_PANEL_REQ{
	tagPKT_CLIGS_OPEN_STAR_PANEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STAR_PANEL_REQ)); }
	UINT8            byPetId; //����id
}PKT_CLIGS_OPEN_STAR_PANEL_REQ;

typedef struct tagPKT_CLIGS_OPEN_STAR_PANEL_ACK{
	tagPKT_CLIGS_OPEN_STAR_PANEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STAR_PANEL_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byIsFullStartLv; //�ǽ��Ƿ�����
	DT_UP_STAR_INFO  stCurUpStarInfo; //��ǰ�����ٷֱ�
	DT_UP_STAR_INFO  stNextUpStarInfo; //���Ǻ������ٷֱ�
	UINT8            byBagDragonItemNum; //���������������
	DT_GOODS_DATA_CLI astBagDragonItemInfo[MAX_BAG_OPEN_NUM]; //�������������Ϣ
	UINT8            byNeedDragonNum; //������Ҫ�������
	DT_STAR_DRAGON_ITEM_INFO astNeedDragonInfo[MAX_STAR_DRAGON_ITEMTYPE_NUM]; //������Ҫ������Ϣ
}PKT_CLIGS_OPEN_STAR_PANEL_ACK;

typedef struct tagPKT_CLIGS_UP_STAR_LV_REQ{
	tagPKT_CLIGS_UP_STAR_LV_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UP_STAR_LV_REQ)); }
	UINT8            byPetId; //����id
}PKT_CLIGS_UP_STAR_LV_REQ;

typedef struct tagPKT_CLIGS_UP_STAR_LV_ACK{
	tagPKT_CLIGS_UP_STAR_LV_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UP_STAR_LV_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA  stPetData; //��������
}PKT_CLIGS_UP_STAR_LV_ACK;

typedef struct tagPKT_CLIGS_OPEN_PET_PANEL_REQ{
	tagPKT_CLIGS_OPEN_PET_PANEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_PANEL_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_OPEN_PET_PANEL_REQ;

typedef struct tagPKT_CLIGS_OPEN_PET_PANEL_ACK{
	tagPKT_CLIGS_OPEN_PET_PANEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_PANEL_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA_LST stAllPetInfo; //������Ϣ
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_OPEN_PET_PANEL_ACK;

typedef struct tagPKT_CLIGS_OPEN_PETFEED_REQ{
	tagPKT_CLIGS_OPEN_PETFEED_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PETFEED_REQ)); }
	UINT8            byPetId; //����id
}PKT_CLIGS_OPEN_PETFEED_REQ;

typedef struct tagPKT_CLIGS_OPEN_PETFEED_ACK{
	tagPKT_CLIGS_OPEN_PETFEED_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PETFEED_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byPetId; //����id
	UINT32           dwIsCanFeed; //�Ƿ����ι��
	UINT32           dwLeftFreeFeedCnt; //�������ʣ��ι������
	UINT32           dwVipFeedCostGold; //VIPι������Ԫ��
	UINT32           dwTotalFeedCnt; //�ܹ�ι���Ĵ���
	UINT8            abyCurFruitType[MAX_PET_FEED_FRUIT_CNT]; //����ι��ˮ����Ϣ��¼
	UINT32           dwFruitScore; //ˮ������
	UINT32           dwReStartCost; //��ҡԪ������
	UINT32           dwAMaxCost; //һ��MAXԪ������
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_OPEN_PETFEED_ACK;

typedef struct tagPKT_CLIGS_FIRST_DRAW_REQ{
	tagPKT_CLIGS_FIRST_DRAW_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FIRST_DRAW_REQ)); }
	UINT8            byPetId; //����id
}PKT_CLIGS_FIRST_DRAW_REQ;

typedef struct tagPKT_CLIGS_FIRST_DRAW_ACK{
	tagPKT_CLIGS_FIRST_DRAW_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FIRST_DRAW_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byPetId; //����id
	UINT8            abyCurFruitType[MAX_PET_FEED_FRUIT_CNT]; //����ι��ˮ����Ϣ��¼
	UINT32           dwFruitScore; //ˮ������
	UINT32           dwIsCanFeed; //�Ƿ����ι��
	UINT32           dwLeftFreeFeedCnt; //�������ʣ��ι������
	UINT32           dwVipFeedCostGold; //VIPι������Ԫ��
	UINT32           dwTotalFeedCnt; //�ܹ�ι���Ĵ���
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_FIRST_DRAW_ACK;

typedef struct tagPKT_CLIGS_RESET_DRAW_REQ{
	tagPKT_CLIGS_RESET_DRAW_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RESET_DRAW_REQ)); }
	UINT8            byPetId; //����id
	UINT8            byResetType; //0��ͨ���� 1 һ��Max����
}PKT_CLIGS_RESET_DRAW_REQ;

typedef struct tagPKT_CLIGS_RESET_DRAW_ACK{
	tagPKT_CLIGS_RESET_DRAW_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RESET_DRAW_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byPetId; //����id
	UINT8            abyCurFruitType[MAX_PET_FEED_FRUIT_CNT]; //����ι��ˮ����Ϣ��¼
	UINT32           dwFruitScore; //ˮ������
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_RESET_DRAW_ACK;

typedef struct tagPKT_CLIGS_CONFIRM_FEED_REQ{
	tagPKT_CLIGS_CONFIRM_FEED_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CONFIRM_FEED_REQ)); }
	UINT8            byPetId; //����id
}PKT_CLIGS_CONFIRM_FEED_REQ;

typedef struct tagPKT_CLIGS_CONFIRM_FEED_ACK{
	tagPKT_CLIGS_CONFIRM_FEED_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CONFIRM_FEED_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA  stPetInfo; //������Ϣ
}PKT_CLIGS_CONFIRM_FEED_ACK;

typedef struct tagPKT_CLIGS_MERGE_PET_REQ{
	tagPKT_CLIGS_MERGE_PET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MERGE_PET_REQ)); }
	UINT8            byEatPetId; //�Եĳ���id
	UINT8            byBeAtePetNum; //���Եĳ�������
	UINT8            abyBeAtePetId[MAX_PET_NUM]; //���Եĳ���id
}PKT_CLIGS_MERGE_PET_REQ;

typedef struct tagPKT_CLIGS_MERGE_PET_ACK{
	tagPKT_CLIGS_MERGE_PET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MERGE_PET_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA_LST stAllPetInfo; //�������г�����Ϣ
}PKT_CLIGS_MERGE_PET_ACK;

typedef struct tagPKT_CLIGS_TEST_REQ{
	tagPKT_CLIGS_TEST_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_TEST_REQ)); }
	UINT8            byErrCode; //��չλ
}PKT_CLIGS_TEST_REQ;

typedef struct tagPKT_CLIGS_TEST_ACK{
	tagPKT_CLIGS_TEST_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_TEST_ACK)); }
	TCHAR            aszWenzi[1024]; //����
}PKT_CLIGS_TEST_ACK;

typedef struct tagDT_PET_STORE_INFO{
	UINT16           wStoreId; //�̳�id
	UINT8            byCostType; //�������� ��������ֶ��ж��ڻ����� Ԫ����
	UINT32           dwCostNum; //������Ŀ
	DT_ITEM_DATA_CLI2 stStoreGood; //�̳���Ʒ
	UINT8            byItemType; //����
	UINT8            byLvLimit; //�ȼ�����
}DT_PET_STORE_INFO;

typedef struct tagPKT_CLIGS_OPEN_PET_STORE_REQ{
	tagPKT_CLIGS_OPEN_PET_STORE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_STORE_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_OPEN_PET_STORE_REQ;

typedef struct tagPKT_CLIGS_OPEN_PET_STORE_ACK{
	tagPKT_CLIGS_OPEN_PET_STORE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_STORE_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wStoreItemNum; //�̳ǵ�������
	DT_PET_STORE_INFO astStoreItems[MAX_PET_STORE_ITEM_NUM]; //�̳ǵ�����Ϣ
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_OPEN_PET_STORE_ACK;

typedef struct tagPKT_CLIGS_BUY_PET_STORE_ITEM_REQ{
	tagPKT_CLIGS_BUY_PET_STORE_ITEM_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_PET_STORE_ITEM_REQ)); }
	UINT16           wStoreItemId; //����ID
}PKT_CLIGS_BUY_PET_STORE_ITEM_REQ;

typedef struct tagPKT_CLIGS_BUY_PET_STORE_ITEM_ACK{
	tagPKT_CLIGS_BUY_PET_STORE_ITEM_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BUY_PET_STORE_ITEM_ACK)); }
	UINT16           wErrCode; //������
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_BUY_PET_STORE_ITEM_ACK;

typedef struct tagPKT_CLIGS_OPEN_REFINEPET_REQ{
	tagPKT_CLIGS_OPEN_REFINEPET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_REFINEPET_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_OPEN_REFINEPET_REQ;

typedef struct tagPKT_CLIGS_OPEN_REFINEPET_ACK{
	tagPKT_CLIGS_OPEN_REFINEPET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_REFINEPET_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA_LST stAllPetInfo; //������Ϣ
}PKT_CLIGS_OPEN_REFINEPET_ACK;

typedef struct tagPKT_CLIGS_REFINEPET_REQ{
	tagPKT_CLIGS_REFINEPET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REFINEPET_REQ)); }
	UINT16           wPetId1; //��������1
	UINT16           wPetId2; //��������2
}PKT_CLIGS_REFINEPET_REQ;

typedef struct tagPKT_CLIGS_REFINEPET_ACK{
	tagPKT_CLIGS_REFINEPET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REFINEPET_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA  stRefineGetPet; //������õĳ���
	DT_PET_CLI_DATA_LST stAllPetInfo; //������Ϣ
}PKT_CLIGS_REFINEPET_ACK;

typedef struct tagDT_BAG_ITEM_INFO{
	UINT16           wItemNum; //������Ʒ����
	DT_ITEM_DATA_CLI2 stItemData; //������Ʒ��Ϣ��Ʒ
}DT_BAG_ITEM_INFO;

typedef struct tagPKT_CLIGS_OPEN_WASH_QUALITY_REQ{
	tagPKT_CLIGS_OPEN_WASH_QUALITY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_WASH_QUALITY_REQ)); }
	UINT16           wPetId; //����ID
}PKT_CLIGS_OPEN_WASH_QUALITY_REQ;

typedef struct tagDT_PET_WASHQUALITY_COST_ITEM{
	UINT32           dwItemId; //ϴ������ƷID
	UINT32           dwItemNum; //ϴ������Ʒ����
}DT_PET_WASHQUALITY_COST_ITEM;

typedef struct tagDT_PET_WASHQUALITY_COST_ITEM_LIST{
	UINT8            byNum; //����
	DT_PET_WASHQUALITY_COST_ITEM astItemInfo[MAX_PET_WASH_PSYCHIC_ITEMTYPE_CNT]; //��Ϣ
	UINT32           dwLockCostGold; //��ס���ĵ�Ԫ��
}DT_PET_WASHQUALITY_COST_ITEM_LIST;

typedef struct tagPKT_CLIGS_OPEN_WASH_QUALITY_ACK{
	tagPKT_CLIGS_OPEN_WASH_QUALITY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_WASH_QUALITY_ACK)); }
	UINT16           wErrCode; //������
	UINT32           dwSlotVal; //һ������ֵ
	DT_PET_WASHQUALITY_COST_ITEM_LIST astCostItemInfo[MAX_PET_WASH_PSYCHIC_CELL_CNT]; //ϴ�������ĵ���Ʒ��Ϣ
	UINT32           dwBagItemNum; //ϴ������Ʒ����
	DT_GOODS_DATA_CLI astBagItemInfo[MAX_BAG_OPEN_NUM]; //�����һ�ϴ������Ʒ��Ϣ
	TCHAR            aszWashDesc[128]; //ϴ��������
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_OPEN_WASH_QUALITY_ACK;

typedef struct tagPKT_CLIGS_WASH_QUALITY_REQ{
	tagPKT_CLIGS_WASH_QUALITY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_WASH_QUALITY_REQ)); }
	UINT16           wPetId; //����ID
	UINT8            byIsLock; //�Ƿ���ס0 ���� 1 ��
	UINT8            byWashCell; //ϴ�ĸ����� ȡֵ��Χ [1, MAX_PET_WASH_PSYCHIC_CELL_CNT] ע���Ǳ�����
}PKT_CLIGS_WASH_QUALITY_REQ;

typedef struct tagPKT_CLIGS_WASH_QUALITY_ACK{
	tagPKT_CLIGS_WASH_QUALITY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_WASH_QUALITY_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA  stPetData; //ϴ���ʺ�ĳ�������
	DT_PET_WASHQUALITY_COST_ITEM_LIST astCostItemInfo[MAX_PET_WASH_PSYCHIC_CELL_CNT]; //ϴ�������ĵ���Ʒ��Ϣ
	UINT32           dwBagItemNum; //ϴ������Ʒ����
	DT_GOODS_DATA_CLI astBagItemInfo[MAX_BAG_OPEN_NUM]; //�����һ�ϴ������Ʒ��Ϣ
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_WASH_QUALITY_ACK;

typedef struct tagPKT_CLIGS_CHANGE_PET_STATE_REQ{
	tagPKT_CLIGS_CHANGE_PET_STATE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_PET_STATE_REQ)); }
	UINT16           wPetId; //����ID
	UINT8            byPetState; //�ı��״̬ 0 ���� 1 ���� 2 ��ս
}PKT_CLIGS_CHANGE_PET_STATE_REQ;

typedef struct tagPKT_CLIGS_CHANGE_PET_STATE_ACK{
	tagPKT_CLIGS_CHANGE_PET_STATE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHANGE_PET_STATE_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA  stPetData; //�ı���������
}PKT_CLIGS_CHANGE_PET_STATE_ACK;

typedef struct tagDT_PET_AFTER_INHERIT_DATA{
	UINT16           wPetId; //����ֻ����̳�
	UINT8            byStarLv; //�ǽ�
	UINT16           wLv; //�ȼ�
	DT_PET_WASHQUALITY_DATA astWashQualityData[MAX_PET_WASH_PSYCHIC_CELL_CNT]; //����ϴ��������Ϣ
	UINT32           dwCostGold; //Ԫ������
}DT_PET_AFTER_INHERIT_DATA;

typedef struct tagPKT_CLIGS_OPEN_PET_INHERIT_REQ{
	tagPKT_CLIGS_OPEN_PET_INHERIT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_INHERIT_REQ)); }
	UINT16           wPetId; //����ID
}PKT_CLIGS_OPEN_PET_INHERIT_REQ;

typedef struct tagPKT_CLIGS_OPEN_PET_INHERIT_ACK{
	tagPKT_CLIGS_OPEN_PET_INHERIT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_INHERIT_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wPetNum; //��������
	DT_PET_AFTER_INHERIT_DATA astNormalAfterInheritData[MAX_PET_NUM]; //����ͨ�̳е���ֵ�仯
	DT_PET_AFTER_INHERIT_DATA astPerfectAfterInheritData[MAX_PET_NUM]; //��Ԫ���̳е���ֵ�仯
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
	UINT32           dwCostGold; //�����������ѵ�Ԫ��
	UINT32           dwCostCoin; //��ͨ�������ѵ�ͭǮ
}PKT_CLIGS_OPEN_PET_INHERIT_ACK;

typedef struct tagPKT_CLIGS_PET_INHERIT_REQ{
	tagPKT_CLIGS_PET_INHERIT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PET_INHERIT_REQ)); }
	UINT16           wPetId; //����ID ���Ա��˵ģ�
	UINT16           wInheritedPetId; //���̳г���ID �����Եģ�
	UINT8            byIsPerfectInherit; //�Ƿ�Ϊ�����̳� 0 �� 1 ��
}PKT_CLIGS_PET_INHERIT_REQ;

typedef struct tagPKT_CLIGS_PET_INHERIT_ACK{
	tagPKT_CLIGS_PET_INHERIT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PET_INHERIT_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA  stPetData; //�ı���������
	DT_PET_CLI_DATA  stInheritedPetData; //�ı�󱻼̳г�������
	UINT16           wPetNum; //��������
	DT_PET_AFTER_INHERIT_DATA astNormalAfterInheritData[MAX_PET_NUM]; //����ͨ�̳е���ֵ�仯
	DT_PET_AFTER_INHERIT_DATA astPerfectAfterInheritData[MAX_PET_NUM]; //��Ԫ���̳е���ֵ�仯
	DT_RSYNC_RES_ITEM_DATA stResInfo; //��Դ��Ϣ
}PKT_CLIGS_PET_INHERIT_ACK;

typedef struct tagPKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ{
	tagPKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ;

typedef struct tagPKT_CLIGS_OPEN_PLAYERPET_PANEL_ACK{
	tagPKT_CLIGS_OPEN_PLAYERPET_PANEL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PLAYERPET_PANEL_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byIsHaveFightPet; //�Ƿ��г�ս���� 0 �� 1��
	DT_PET_CLI_DATA  stPetInfo; //������Ϣ
}PKT_CLIGS_OPEN_PLAYERPET_PANEL_ACK;

typedef struct tagPKT_CLIGS_REQUEST_ALL_PET_INFO_REQ{
	tagPKT_CLIGS_REQUEST_ALL_PET_INFO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_REQUEST_ALL_PET_INFO_REQ)); }
	UINT8            byPlaceholder; //��չλ��û����
}PKT_CLIGS_REQUEST_ALL_PET_INFO_REQ;

typedef struct tagPKT_CLIGS_REQUEST_ALL_PET_INFO_ACK{
	tagPKT_CLIGS_REQUEST_ALL_PET_INFO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_REQUEST_ALL_PET_INFO_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_CLI_DATA_LST stAllPetInfo; //������Ϣ
}PKT_CLIGS_REQUEST_ALL_PET_INFO_ACK;

typedef struct tagDT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI_v410 astEquipInfo[MAX_BAG_OPEN_NUM]; //װ����Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI astEquipStrengthenInfo[MAX_BAG_OPEN_NUM]; //װ��ǿ����Ϣ
	UINT16           wEnchantEquipNum; //װ����ħ��������ħ����δ����ǰ����Ϊ0�Խ�ʡ������
	DT_EQUIP_ENCHANT_DATA_CLI astEquipEnchantInfo[MAX_BAG_OPEN_NUM]; //װ����ħ��Ϣ
	UINT8            abyEquipOpenLightFlagInfo[MAX_BAG_OPEN_NUM]; //װ�������־��Ϣ(0���ɿ��⣬1�ɿ��⣬2�ѿ���)
	UINT32           adwStrengthen10CoinInfo[MAX_BAG_OPEN_NUM]; //װ����10������ҪͭǮ��Ϣ
}DT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI;

typedef struct tagDT_HERO_ATTR_ADD_CLI_v410{
	UINT32           dwAddAttack; //����
	UINT32           dwAddHP; //Ѫ��
	UINT32           dwAddTalent; //����
	UINT32           dwDefense; //����
	UINT32           dwAddDefense; //���ӷ���
}DT_HERO_ATTR_ADD_CLI_v410;

typedef struct tagDT_RECRUIT_HERO_INFO{
	DT_HERO_BASE_DATA_CLI stHeroBaseInfo; //�佫������Ϣ
	DT_HERO_ATTR_ADD_CLI_v410 stHeroAttrAddInfo; //�佫���Լӳ���Ϣ
	DT_SKILL_DATA_CLI stSkillInfo; //�佫������Ϣ
}DT_RECRUIT_HERO_INFO;

typedef struct tagDT_MATERIAL{
	UINT8            byMaterialType; //�������ͣ���Ϊ��EIK_EQUIP��EIK_GOODS
	UINT16           wMaterialID; //����ID
	UINT16           wCurNum; //ӵ�в�����
	UINT16           wRequiredNum; //���������
	DT_INSTANCE_ID   stDropInstanceID; //�ò������ĸ��⴫��������
	UINT8            byGetFlag; //�ò��ϵĻ�ñ�ʶ��0. �ɻ�� 1. ��ʾ���ò������ڸ���δͨ��
}DT_MATERIAL;

typedef struct tagDT_MATERIAL_LIST{
	UINT8            byMaterialCnt; //�������ͣ���Ϊ��EIK_EQUIP��EIK_GOODS
	DT_MATERIAL      astMaterialList[MAX_MATERIAL_NUM]; //��ļ�����б�
}DT_MATERIAL_LIST;

typedef struct tagDT_RECRUIT_HERO_DATA_v410{
	DT_RECRUIT_HERO_INFO stHeroInfo; //�����Ϣ
	UINT8            byNeedVisitNum; //��ݷô���
	UINT8            byCurVisitNum; //��ǰ�Ѱݷô���
	UINT32           dwVisitCoin; //ÿ�ΰݷ�ͭ��
	UINT16           wVisitGold; //��ǧԪ��
	UINT16           wRecuitLevel; //��ļ�ȼ�
	UINT16           wRequireJingjieLevel; //��ļ���辳��׵ȼ�
	UINT8            byRecuitUnLock; //�Ƿ�ɲ���
	UINT8            byRecommend; //�Ƿ��Ƽ�
	DT_MATERIAL_LIST stUpgradeMaterials; //���ײ����б�
	DT_MATERIAL_LIST stRecruitMaterials; //��ļ�����б�
	UINT8            byIsFlyHero; //�Ƿ����⴫Ӣ��
	UINT8            byCanUpgrade; //�Ƿ�ɽ���
	DT_RECRUIT_HERO_INFO astUpgradeHeroInfo[1]; //���׺�Ļ����Ϣ
}DT_RECRUIT_HERO_DATA_v410;

typedef struct tagDT_EQUIP_MAKE_BOOK{
	UINT16           wBookID; //������ID
	UINT16           wEquipID; //��������װ��
	UINT16           wBookCnt; //ӵ����������
	UINT8            byIsMakable; //�Ƿ������
	UINT16           wEquipDressLvl; //װ���ɴ����ȼ�
	UINT8            byQuality; //Ʒ�ף��졢�ء������ƣ��� FlyEquipQuality
	UINT8            byEquipType; //װ�����ͣ�ͷ����ս�ۡ�������սѥ���� EEquipPosType
	DT_MATERIAL_LIST stMaterials; //���������б�
	UINT32           dwBuyGold; //����ʣ���������Ԫ����
	UINT32           dwCostCoin; //����������ͭǮ
	DT_BATTLE_ATTRIBUTE2 stAttr; //װ������
}DT_EQUIP_MAKE_BOOK;

typedef struct tagDT_EQUIP_MAKE_BOOK_INFO_CLI{
	UINT16           wBookID; //������ID
	UINT32           dwBuyGold; //����ʣ���������Ԫ����
}DT_EQUIP_MAKE_BOOK_INFO_CLI;

typedef struct tagDT_EQUIP_SERIES{
	UINT16           wSeriesID; //ϵ��ID
	UINT16           wSeriesLevel; //��ϵ�м���
	TCHAR            aszSeriesName[MAX_EQUIP_SERIES_NAME_LEN]; //��װ��ϵ�е�����
	UINT8            byMakeCnt; //��ϵ�п�������װ����
	UINT16           wMakeBookCnt; //��ϵ����������
	DT_EQUIP_MAKE_BOOK astMakeBookList[MAX_MAKE_BOOKS_NUM_OF_1_SERIES]; //��ϵ���������б�
}DT_EQUIP_SERIES;

typedef struct tagDT_FLY_COST{
	UINT16           wItemID; //��ƷID
	UINT16           wCurNum; //��ǰ����
	UINT16           wRequiredNum; //��������
}DT_FLY_COST;

typedef struct tagDT_FLY_GOAL{
	TCHAR            aszFlyGoalText[100]; //������������
	UINT8            byIsAchieveFlyGoal; //�Ƿ��Ѵ�ɷ�������:��true����false
}DT_FLY_GOAL;

typedef struct tagDT_FLY_GOAL_LIST{
	UINT8            byFlyGoalCnt; //����������
	DT_FLY_GOAL      astFlyFoalList[MAX_FLY_GOAL_NUM]; //���������б�
}DT_FLY_GOAL_LIST;

typedef struct tagPKT_CLIGS_EQUIP_ENCHANT_REQ{
	tagPKT_CLIGS_EQUIP_ENCHANT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_ENCHANT_REQ)); }
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wLevel; //Ҫ�����ĵȼ�(ÿ��ֻ����1����0��ʾֱ������10��)
}PKT_CLIGS_EQUIP_ENCHANT_REQ;

typedef struct tagPKT_CLIGS_EQUIP_ENCHANT_ACK{
	tagPKT_CLIGS_EQUIP_ENCHANT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_ENCHANT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EQUIP_DATA_CLI_v410 stEquipInfo; //װ����Ϣ
	DT_EQUIP_ENCHANT_DATA_CLI stEnchantInfo; //��ħ��Ϣ
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //��ħ֮����Ӱ���װ��ǿ����Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT32           dwEnchantStoneNum; //��ǰ��ħʯ����
}PKT_CLIGS_EQUIP_ENCHANT_ACK;

typedef struct tagPKT_CLIGS_OPEN_SMITHY_ACK_v410{
	tagPKT_CLIGS_OPEN_SMITHY_ACK_v410() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SMITHY_ACK_v410)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wStrengthenCountDown; //װ��ǿ������ʱ
	UINT16           wStrengthenCD; //װ��ǿ����CD
	UINT32           dwClrCDGold; //���CD����Ԫ��
	DT_BUY_EQUIP_DATA astByEquipInfo[EQUIP_POS_NUM]; //�ɹ������װ����Ϣ(�����±�+1Ϊ����λ��)
	UINT64           qwBlueGas; //��ǰ����
	DT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI stEquipList; //װ�������б�
	UINT8            byBuildID; //�ͻ����������Ľ���ID:ǿ��/��ħ
}PKT_CLIGS_OPEN_SMITHY_ACK_v410;

typedef struct tagPKT_CLIGS_OPEN_RECRUIT_ACK_v410{
	tagPKT_CLIGS_OPEN_RECRUIT_ACK_v410() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECRUIT_ACK_v410)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wJingJieLevel; //����ȼ�
	UINT16           wHeroNum; //�佫��Ŀ
	DT_RECRUIT_HERO_DATA_v410 astHeroList[MAX_HERO_NUM]; //�佫��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_OPEN_RECRUIT_ACK_v410;

typedef struct tagPKT_CLIGS_UPGRADE_HERO_REQ{
	tagPKT_CLIGS_UPGRADE_HERO_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_HERO_REQ)); }
	UINT16           wHeroID; //���׻��ID
}PKT_CLIGS_UPGRADE_HERO_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_HERO_ACK{
	tagPKT_CLIGS_UPGRADE_HERO_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_HERO_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroID; //���׻��ID
	DT_RECRUIT_HERO_DATA_v410 stUpgradeHero; //���׺�Ļ����Ϣ
	DT_POWER_CHANGE_DATA stPowerChange; //ս���仯��Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ��ľƹݽ�����ʾ��Ϣ
}PKT_CLIGS_UPGRADE_HERO_ACK;

typedef struct tagPKT_CLIGS_OPEN_EQUIP_MAKE_REQ{
	tagPKT_CLIGS_OPEN_EQUIP_MAKE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EQUIP_MAKE_REQ)); }
	UINT16           wSeriesID; //�⴫ϵ��ID
}PKT_CLIGS_OPEN_EQUIP_MAKE_REQ;

typedef struct tagPKT_CLIGS_OPEN_EQUIP_MAKE_ACK{
	tagPKT_CLIGS_OPEN_EQUIP_MAKE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EQUIP_MAKE_ACK)); }
	UINT16           wErrCode; //������
	UINT8            bySeriesCnt; //�⴫ϵ����
	DT_EQUIP_SERIES  astSeriesList[MAX_SERIES_NUM]; //�⴫ϵ���б�
	UINT8            byBuyMaterialVipLvl; //Ԫ��������Ϲ��ܿ�������vip�ȼ�
}PKT_CLIGS_OPEN_EQUIP_MAKE_ACK;

typedef struct tagPKT_CLIGS_EQUIP_MAKE_REQ{
	tagPKT_CLIGS_EQUIP_MAKE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_MAKE_REQ)); }
	UINT16           wEquipBookID; //������ID
	UINT16           wCurBookNum; //��ǰ�����������(��ֹ������������ɷ������յ������������)
	UINT8            byIsBuyMaterial; //�Ƿ���ʣ�����
}PKT_CLIGS_EQUIP_MAKE_REQ;

typedef struct tagPKT_CLIGS_EQUIP_MAKE_ACK{
	tagPKT_CLIGS_EQUIP_MAKE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_MAKE_ACK)); }
	UINT16           wErrCode; //������
	DT_EQUIP_MAKE_BOOK stEquipBook; //��������Ϣ
	UINT64           qwCoin; //ͭǮ��
	UINT32           dwGold; //Ԫ����
	UINT16           wUpdateMakeBookCnt; //��ϵ�и��µ���������
	DT_EQUIP_MAKE_BOOK_INFO_CLI astUpdateMakeBookList[MAX_MAKE_BOOKS_NUM_OF_1_SERIES]; //��ϵ�и��µ��������б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ��������̽�����ʾ��Ϣ
}PKT_CLIGS_EQUIP_MAKE_ACK;

typedef struct tagPKT_CLIGS_OPEN_FLY_REQ{
	tagPKT_CLIGS_OPEN_FLY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FLY_REQ)); }
	UINT16           wHeroID; //���
}PKT_CLIGS_OPEN_FLY_REQ;

typedef struct tagPKT_CLIGS_OPEN_FLY_ACK{
	tagPKT_CLIGS_OPEN_FLY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_FLY_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byBasicAttrPromote; //�������Զ���ӳ�
	DT_FLY_GOAL_LIST stFlyGoals; //����Ŀ��
	DT_FLY_COST      astFlyCostList[FLY_COST_MATERIAL_NUM]; //��������Ʒ�б�
}PKT_CLIGS_OPEN_FLY_ACK;

typedef struct tagPKT_CLIGS_FLY_REQ{
	tagPKT_CLIGS_FLY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_FLY_REQ)); }
	UINT32           dwHeroID; //���
}PKT_CLIGS_FLY_REQ;

typedef struct tagPKT_CLIGS_FLY_ACK{
	tagPKT_CLIGS_FLY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FLY_ACK)); }
	UINT16           wErrCode; //������
	UINT16           wHeroID; //���
	UINT16           wHeroLvl; //������Ļ��ȼ�
	DT_EXPERIENCE_DATA stCoachHeroExpInfo; //���ǵľ�����Ϣ
	DT_POWER_CHANGE_DATA stPowerChange; //ս���仯��Ϣ
}PKT_CLIGS_FLY_ACK;

typedef struct tagPKT_CLIGS_BATTLE_ACK5{
	tagPKT_CLIGS_BATTLE_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_BATTLE_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_ENCOURAGE_DATA stBattleEncourage; //ս������
	DT_DATA_AFTER_BATTLE_ENCOURAGE stAfterBattleEncourage; //��ȡս�������������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_PASS_ENCOURAGE_DATA astPassEncourage[1]; //ͨ�ؽ���
	DT_DATA_AFTER_PASS_ENCOURAGE astAfterPassEncourage[1]; //��ȡͨ�ؽ����������Ϣ
	DT_PASS_ENCOURAGE_BOX_DATA astPassEncourageBox[1]; //ͨ�ر��佱����Ϣ
	DT_UNLOCK_DATA   astUnlockInfo[1]; //������Ϣ
	UINT8            byHaveNextInstance; //�Ƿ�����һ������
	DT_NEXT_INSTANCE_DATA astNextInstanceInfo[1]; //��һ��������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT8            abyGuide[MAX_GUIDE_NUM]; //������Ϣ(ÿһ�ֽڱ�ʾһ��������0��ʾ����Ҫ��1��Ҫ��2�����)
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	TCHAR            aszExtContext[MAX_COMMON_TXT_LEN]; //��չ��Ϣ
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_BATTLE_ACK5;

typedef struct tagPKT_CLIGS_CHALLENGE_ACK5{
	tagPKT_CLIGS_CHALLENGE_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //�Է������Ϣ
	UINT8            byEnemyHeroNum; //�Է���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //�Է���Ϣ
	DT_RACE_CHALLENGE_ENCOURAGE_DATA stChallengeEncourage; //��ս����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ����
	UINT64           qwCurJingJie; //��ҵ�ǰ�ľ����
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_CHALLENGE_ACK5;

typedef struct tagPKT_CLIGS_PLUNDER_ACK5{
	tagPKT_CLIGS_PLUNDER_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_PLUNDER_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT32           dwEnemyID; //Ҫս�������ID
	UINT32           dwCaptureID; //��²���ID(��EnemyID��ͬ��ʾ�Ӷ����CaptureID��ң���ͬ��ʾ����CaptureID��²)
	UINT8            byUseItemFlag; //�Ƿ�ʹ�õ����Ӷ����5�����ϵ����
	UINT8            byResistFlag; //�Ƿ񷴿�(1��ʾ����)
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
	DT_BECAPTURE_DATA stBeCaptureInfo; //��²��ҵı�����Ϣ
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //ս���з������Ϣ
	UINT8            byEnemyHeroNum; //ս���з���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //ս���з���Ϣ
	DT_PLUNDER_ENCOURAGE_DATA stPlunderEncourage; //�Ӷά��
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
	UINT16           wVipExtNum; //VIP�������ӵĴ���
	UINT16           wFreePlunderNum; //�������Ӷ����
	UINT32           dwPlunderGold; //�շ��Ӷ�Ԫ��(��������ѵ���Ϊ0)
	UINT16           wPlunderItemNum; //��ǰӵ�е��Ӷ����
	UINT8            byCaptureFlag; //�Ƿ��²��ң�1Ϊ�Է���Ϊ��ķ�²
	DT_CAPTURE_DATA_CLI astCaptureInfo[1]; //��²��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_PLUNDER_ACK5;

typedef struct tagPKT_CLIGS_PKBATTLE_ACK5{
	tagPKT_CLIGS_PKBATTLE_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_PKBATTLE_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_PKBATTLE_ACK5;

typedef struct tagPKT_CLIGS_RDCHALLENGE_ACK5{
	tagPKT_CLIGS_RDCHALLENGE_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_RDCHALLENGE_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_RDC_TAB_DATA  stTabInfo; //�����ս�����Ϣ
	DT_RDC_ENC_DATA  stEncInfo; //�����ս������Ϣ
	UINT64           qwCurJingJie; //��ǰ�����
	UINT64           qwCurPurpleGas; //��ǰ����
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	UINT16           wKindID; //��õ��ʻ�ID
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_RDCHALLENGE_ACK5;

typedef struct tagPKT_CLIGS_CHALLENGE_MYSELF_ACK5{
	tagPKT_CLIGS_CHALLENGE_MYSELF_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_MYSELF_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_CHALLENGE_MYSELF_ACK5;

typedef struct tagPKT_CLIGS_HUNTING_BATTLE_ACK5{
	tagPKT_CLIGS_HUNTING_BATTLE_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_HUNTING_BATTLE_ACK5)); }
	UINT16           wErrCode; //������,��0Ϊ����
	DT_REWARD_INFO   stBattleReward; //ս������
	DT_HUNTING_SCHEDULE_INFO stTaskScheduleInfo; //���������Ϣ
	UINT32           dwClosedMonsterNeedGold; //������Ҫ��Ԫ��
	TCHAR            aszBattleLostMsg[MAX_FACTION_DESC_NUM]; //ս��ʧ����Ϣ
	UINT32           dwSyncDoorsTribute; //ͬ������
	UINT8            byScheduleChangeFlag; //�����ı��ʶ��0 û�䣬 1�䣩
	UINT8            byHuntingLeftNum; //׽������ͬ��
	UINT8            byIsGoldMode; //�Ƿ��ڻƽ�ģʽ
	DT_HUNTING_SCHEDULE_INFO2 stNewHuntingScheduleInfo; //׽��������Ϣ
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_HUNTING_BATTLE_ACK5;

typedef struct tagDT_COURAGE_PLAYER_BATTLE_DATA5{
	UINT8            byBattleNum; //ս������
	DT_BATTLE_DATA5  astBattleInfo[MAX_COURAGE_MEMBER_NUM]; //ս����Ϣ
}DT_COURAGE_PLAYER_BATTLE_DATA5;

typedef struct tagPKT_CLIGS_COURAGE_PLAYER_START_ACK5{
	tagPKT_CLIGS_COURAGE_PLAYER_START_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_PLAYER_START_ACK5)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_MONSTER_DATA_LIST stMonsterInfo; //������Ϣ
	DT_COURAGE_GROUP_PLAYER_BATTLE_DATA stGroupPlayerInfo; //������Ϣ
	UINT8            byPassFlag; //�Ƿ�ͨ�� 0ͨ�� 1��ͨ��
	DT_INSTANCE_ID   stInstanceID; //�������
	DT_COURAGE_JEWELRY_DATA_LST stjewelryInfoLst; //��Ʒ��Ϣ
	UINT8            byHelpID; //Э������ 1�ٽ���1�Σ� 2Э��������1�Σ�3�Ѿ����Ͳ�����������
	DT_COURAGE_PLAYER_BATTLE_DATA5 stBattleInfoCli; //ս����Ϣ
}PKT_CLIGS_COURAGE_PLAYER_START_ACK5;

typedef struct tagPKT_CLIGS_COURAGE_LEADER_START_NTF5{
	tagPKT_CLIGS_COURAGE_LEADER_START_NTF5() { memset(this, 0, sizeof(tagPKT_CLIGS_COURAGE_LEADER_START_NTF5)); }
	PKT_CLIGS_COURAGE_PLAYER_START_ACK5 stBattleInfo; //ս����Ϣ
}PKT_CLIGS_COURAGE_LEADER_START_NTF5;

typedef struct tagPKT_CLIGS_BEGIN_JIEBIAO_ACK5{
	tagPKT_CLIGS_BEGIN_JIEBIAO_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_BEGIN_JIEBIAO_ACK5)); }
	UINT16           wErrCode; //������
	UINT8            byYabiaoFlag; //Ѻ�ڱ�ʶ(0Ϊ����Ѻ�ڣ�1Ϊ����Ѻ���У�2ΪѺ����ϣ�������ȡ����)
	UINT64           qwCoinEncourage; //����
	UINT32           dwScienceEncourage; //�������꽱��
	UINT64           qwCurCoin; //��ǰͭǮ��
	UINT64           qwCurScience; //��ǰ����
	UINT32           dwBeJiebiaoPlayerID; //�����ض���
	BIAO_OPERATE_INFO stBeJiebiaoInfo; //������Ϣ
	UINT32           dwJiebiaoPlayerID; //���ض���
	BIAO_OPERATE_INFO stJiebiaoInfo; //������Ϣ
	UINT16           wJiebiaoCD; //��ȴʱ��
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
	DT_BATTLE_DATA5  stBattleData; //ս����Ϣ
}PKT_CLIGS_BEGIN_JIEBIAO_ACK5;

typedef struct tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK5{
	tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_QUERY_BATTLE_RECORD_ACK5)); }
	UINT16           wErrCode; //������
	DT_BATTLE_DATA5  stBattleData; //ս����Ϣ
}PKT_CLIGS_QUERY_BATTLE_RECORD_ACK5;

typedef struct tagPKT_CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5{
	tagPKT_CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5() { memset(this, 0, sizeof(tagPKT_CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5)); }
	TCHAR            aszErrInfo[MAX_COMMON_TXT_LEN]; //������Ϣ
	TCHAR            aszBattleKey[MAX_COMMON_TXT_LEN]; //�����ս��ȷ�ϴ�
	UINT8            byPassFlag; //�Ƿ�ͨ��
	DT_PASS_ENCOURAGE_BOX_DATA astPassEncourageBox[1]; //ͨ�ر��佱����Ϣ
	DT_DATA_AFTER_PASS_ENCOURAGE_BOX astResSync[1]; //ͨ����Դͬ����Ϣ
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5;

typedef struct tagPKT_CLIGS_OPEN_PET_RULE_REQ{
	tagPKT_CLIGS_OPEN_PET_RULE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_RULE_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_PET_RULE_REQ;

typedef struct tagDT_PET_BOOK_DATA{
	DT_PET_CLI_DATA  stPetInfo; //������Ϣ
	UINT8            byPetState; //����״̬(0������1�ҵ�,2�ʺ�)
}DT_PET_BOOK_DATA;

typedef struct tagDT_PET_BOOK_DATA_LST{
	UINT16           wPetNum; //��������
	DT_PET_BOOK_DATA astPetData[MAX_PET_BOOK_NUM]; //��������
	TCHAR            aszTitle[NORMAL_MSG_LEN]; //̧ͷ
}DT_PET_BOOK_DATA_LST;

typedef struct tagPKT_CLIGS_OPEN_PET_RULE_ACK{
	tagPKT_CLIGS_OPEN_PET_RULE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PET_RULE_ACK)); }
	UINT16           wErrCode; //������
	DT_PET_BOOK_DATA_LST stLowPetInfo; //1-20��
	DT_PET_BOOK_DATA_LST stMiddlePetInfo; //20���Ժ�
	DT_PET_BOOK_DATA_LST stHighPetInfo; //��������
	DT_ITEM_DATA_LIST_LESS_CLI3 stItemsInfo; //����
	TCHAR            aszPetRule[MAX_PET_RULE_LEN]; //����
	TCHAR            aszItemDesc[NORMAL_MSG_LEN]; //��������
}PKT_CLIGS_OPEN_PET_RULE_ACK;

typedef struct tagPKT_CLIGS_PLAYER_INFO_PET_REQ{
	tagPKT_CLIGS_PLAYER_INFO_PET_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_PET_REQ)); }
	UINT32           dwPlayerID; //�Է����ID
}PKT_CLIGS_PLAYER_INFO_PET_REQ;

typedef struct tagPKT_CLIGS_PLAYER_INFO_PET_ACK{
	tagPKT_CLIGS_PLAYER_INFO_PET_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLAYER_INFO_PET_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byHavePet; //�Ƿ��г���(0û�У�1��)
	DT_PET_CLI_DATA  astPetInfo[1]; //������Ϣ
}PKT_CLIGS_PLAYER_INFO_PET_ACK;

typedef struct tagDT_ITEM_EXCHANGE_INFO{
	UINT8            byItemNum; //���߸���
	DT_ITEM_DATA_CLI3 astItemList[MAX_DISPALY_GOODS_NUM]; //������Ϣ
	UINT16           awItemNeedNum[MAX_DISPALY_GOODS_NUM]; //�����������
}DT_ITEM_EXCHANGE_INFO;

typedef struct tagDT_POTENCY_ATTR_INFO{
	UINT8            byPotencyID; //����ID
	UINT32           dwPotencyValue; //����ֵ
}DT_POTENCY_ATTR_INFO;

typedef struct tagDT_POTENCY_ATTR_LST_INFO{
	UINT8            byAttrNum; //���Ը���
	DT_POTENCY_ATTR_INFO astAttrInfo[MAX_SOUL_POTENCY_ADD_ATTR_NUM]; //������Ϣ
}DT_POTENCY_ATTR_LST_INFO;

typedef struct tagDT_POTENCY_ATTR_DATA{
	UINT8            byAttrNum; //���Ը���
	DT_POTENCY_ATTR_INFO astAttrInfo[MAX_SOUL_POTENCY_ATTR_NUM]; //������Ϣ
	DT_ITEM_EXCHANGE_INFO stItemsInfo; //������Ϣ
	UINT16           wNeedSoulLevel; //��Ʒ��Ҫ��ս��ȼ�
}DT_POTENCY_ATTR_DATA;

typedef struct tagDT_POTENCY_ATTR_DATA_LST{
	UINT8            byNum; //���Ը���
	DT_POTENCY_ATTR_DATA astAttrValue[MAX_SOUL_POTENCY_SUB_LEVEL]; //����ֵ
}DT_POTENCY_ATTR_DATA_LST;

typedef struct tagDT_POTENCY_DATA{
	UINT8            byPotencyLevel; //Ǳ�ܵȽ�
	DT_POTENCY_ATTR_DATA_LST stPotencyInfo; //Ǳ����Ϣ
}DT_POTENCY_DATA;

typedef struct tagDT_POTENCY_DATA_LST{
	UINT8            byPotencyNum; //Ǳ�ܵȽ���
	DT_POTENCY_DATA  astPotencyLst[MAX_SOUL_POTENCY_LEVEL]; //����Ǳ����Ϣ
}DT_POTENCY_DATA_LST;

typedef struct tagPKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ{
	tagPKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stSoulMark; //ս���ʶ
}PKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ;

typedef struct tagPKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK{
	tagPKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_POTENCY_CLI stPotencyInfo; //��ǰǱ����Ϣ
	DT_POTENCY_DATA_LST stAllPotency; //���мӳ���Ϣ
	DT_POTENCY_ATTR_LST_INFO stCountInfo; //ͳ����Ϣ
}PKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK;

typedef struct tagPKT_CLIGS_SOUL_UPDATE_TYPE_REQ{
	tagPKT_CLIGS_SOUL_UPDATE_TYPE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SOUL_UPDATE_TYPE_REQ)); }
	DT_CLIGS_SOUL_MARK_DATA stSoulMark; //ս���ʶ
}PKT_CLIGS_SOUL_UPDATE_TYPE_REQ;

typedef struct tagPKT_CLIGS_SOUL_UPDATE_TYPE_ACK{
	tagPKT_CLIGS_SOUL_UPDATE_TYPE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SOUL_UPDATE_TYPE_ACK)); }
	UINT16           wErrCode; //������
	DT_SOUL_POTENCY_CLI stPotencyInfo; //��ǰǱ����Ϣ
	DT_POTENCY_ATTR_LST_INFO stCountInfo; //ͳ����Ϣ
	DT_ITEM_NUM_DATA_LIST_CLI stItemsInfo; //����ͬ����Ϣ
	DT_POWER_CHANGE_DATA stPowerChangeInfo; //ս���仯
}PKT_CLIGS_SOUL_UPDATE_TYPE_ACK;

typedef struct tagDT_ITEM_MARK_DATA{
	UINT16           wItemID; //��ƷID
	UINT16           wItemIdx; //��ƷIDX
}DT_ITEM_MARK_DATA;

typedef struct tagDT_NEIDAN_BAG_MARK_LST_DATA{
	UINT8            byNum; //����
	DT_ITEM_MARK_DATA astNeiDanInfo[MAX_NEI_DAN_BAG_NUM]; //��Ϣ
}DT_NEIDAN_BAG_MARK_LST_DATA;

typedef struct tagDT_NEIDAN_PET_MARK_LST_DATA{
	UINT8            byNum; //����
	DT_ITEM_MARK_DATA astNeiDanInfo[MAX_PET_NEIDAN_NUM]; //��Ϣ
}DT_NEIDAN_PET_MARK_LST_DATA;

typedef struct tagPKT_CLIGS_DRESS_NEIDAN_REQ{
	tagPKT_CLIGS_DRESS_NEIDAN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_NEIDAN_REQ)); }
	UINT8            byDressType; //������ʽ�� EDressType ��
	DT_ITEM_MARK_DATA stNeiDan; //�ڵ�
	UINT16           wPetID; //����ID
}PKT_CLIGS_DRESS_NEIDAN_REQ;

typedef struct tagPKT_CLIGS_DRESS_NEIDAN_ACK{
	tagPKT_CLIGS_DRESS_NEIDAN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_NEIDAN_ACK)); }
	UINT16           wErrCode; //������
	UINT8            byDressType; //������ʽ
	DT_NEIDAN_PET_MARK_LST_DATA stPetNeiDan; //�����ڵ�ͬ��
	DT_NEIDAN_BAG_MARK_LST_DATA stBagNeiDan; //�ڵ�����ͬ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
}PKT_CLIGS_DRESS_NEIDAN_ACK;

typedef struct tagDT_NEIDAN_CLI{
	DT_ITEM_MARK_DATA stNeiDan; //�ڵ�ID
	UINT16           wNeiDanLevel; //�ڵ��ȼ�
	UINT32           dwCurExperience; //��ǰ����
	UINT32           dwMaxExperience; //�ڵ���������
	UINT64           qwBackExperience; //�ڵ���������
	UINT16           wDressReq; //��������
	UINT32           dwCostCoin; //���ɺķ�ͭǮ
	UINT32           dwLingLi; //�ӳ�����ֵ
}DT_NEIDAN_CLI;

typedef struct tagDT_PET_NEIDAN_CLI{
	UINT8            byNum; //�ڵ�����
	DT_NEIDAN_CLI    astNeiDanInfo[MAX_PET_NEIDAN_NUM]; //��Ϣ
}DT_PET_NEIDAN_CLI;

typedef struct tagDT_BAG_NEIDAN_CLI{
	UINT8            byNum; //�ڵ�����
	DT_NEIDAN_CLI    astNeiDanInfo[MAX_NEI_DAN_BAG_NUM]; //��Ϣ
}DT_BAG_NEIDAN_CLI;

typedef struct tagPKT_CLIGS_OPEN_NEIDAN_REQ{
	tagPKT_CLIGS_OPEN_NEIDAN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_NEIDAN_REQ)); }
	UINT16           wPetID; //PetID
}PKT_CLIGS_OPEN_NEIDAN_REQ;

typedef struct tagPKT_CLIGS_OPEN_NEIDAN_ACK{
	tagPKT_CLIGS_OPEN_NEIDAN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_NEIDAN_ACK)); }
	UINT16           wErrCode; //������
	TCHAR            aszPetPic[MAX_PET_NAME_LENGTH]; //����ͼƬ
	DT_PET_NEIDAN_CLI stPetNeiDan; //�����ڵ�
	DT_BAG_NEIDAN_CLI stBagNeiDan; //�����ڵ�
}PKT_CLIGS_OPEN_NEIDAN_ACK;

typedef struct tagPKT_CLIGS_UPDATA_NEIDAN_REQ{
	tagPKT_CLIGS_UPDATA_NEIDAN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPDATA_NEIDAN_REQ)); }
	DT_ITEM_MARK_DATA stNeiDan; //���ڵ�
	DT_NEIDAN_BAG_MARK_LST_DATA stDevorNeiDan; //�����ɵ��ڵ�
}PKT_CLIGS_UPDATA_NEIDAN_REQ;

typedef struct tagPKT_CLIGS_UPDATA_NEIDAN_ACK{
	tagPKT_CLIGS_UPDATA_NEIDAN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPDATA_NEIDAN_ACK)); }
	UINT16           wErrCode; //������
	DT_NEIDAN_CLI    stNeiDan; //���ڵ�
	DT_NEIDAN_BAG_MARK_LST_DATA stBagNeiDan; //�����ڵ�
	DT_PLAYER_RES_DATA stResSync; //��Դͬ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս���仯
}PKT_CLIGS_UPDATA_NEIDAN_ACK;

typedef struct tagPKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ{
	tagPKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ;

typedef struct tagDT_NAIDAN_INSTANCE_DATA{
	DT_INSTANCE_ID   stInstanceID; //����ID
	TCHAR            aszInstanceName[NORMAL_MSG_LEN]; //��������
	TCHAR            aszItemDesc[NORMAL_MSG_LEN]; //������Ʒ
	UINT16           wPlayerLevelReq; //����ȼ�Ҫ��
	UINT8            byState; //����״̬��0������û�ܹأ���1ͨ�أ�2������ս��
}DT_NAIDAN_INSTANCE_DATA;

typedef struct tagDT_NAIDAN_INSTANCE_LST_DATA{
	UINT8            byInstanceNum; //��������
	DT_NAIDAN_INSTANCE_DATA astInstanceInfo[MAX_NEIDAN_INSTANCE_NUM]; //������Ϣ
}DT_NAIDAN_INSTANCE_LST_DATA;

typedef struct tagPKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK{
	tagPKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK)); }
	UINT16           wErrCode; //������
	DT_PLAYER_RES_LST_DATA stResInfo; //��Դ��Ϣ
	UINT16           wCanBattleNum; //��ս��Ϣ
	DT_INSTANCE_ID   stSelectInstance; //��������
	DT_NAIDAN_INSTANCE_LST_DATA stInstanceLst; //������Ϣ
}PKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK;

typedef struct tagPKT_CLIGS_NEIDAN_BATTLE_REQ{
	tagPKT_CLIGS_NEIDAN_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_NEIDAN_BATTLE_REQ)); }
	DT_INSTANCE_ID   stInstanceID; //����ID
}PKT_CLIGS_NEIDAN_BATTLE_REQ;

typedef struct tagPKT_CLIGS_NEIDAN_BATTLE_ACK{
	tagPKT_CLIGS_NEIDAN_BATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_NEIDAN_BATTLE_ACK)); }
	UINT16           wErrCode; //������
	DT_PASS_ENCOURAGE_BOX_DATA stPassEncourage; //ͨ�ؽ���������Ϣ
	DT_BATTLE_DATA5  stBattleInfo; //ս����Ϣ
}PKT_CLIGS_NEIDAN_BATTLE_ACK;

typedef struct tagPKT_CLIGS_RECV_NEIDAN_AWARD_REQ{
	tagPKT_CLIGS_RECV_NEIDAN_AWARD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_NEIDAN_AWARD_REQ)); }
	UINT8            byExt; //��չλ
}PKT_CLIGS_RECV_NEIDAN_AWARD_REQ;

typedef struct tagPKT_CLIGS_RECV_NEIDAN_AWARD_ACK{
	tagPKT_CLIGS_RECV_NEIDAN_AWARD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_RECV_NEIDAN_AWARD_ACK)); }
	UINT16           wErrCode; //������
	DT_INSTANCE_ID   stNextInstance; //��һ����
	DT_PASS_ENCOURAGE_BOX_DATA stPassEncourage; //�����Ʒ
}PKT_CLIGS_RECV_NEIDAN_AWARD_ACK;

typedef struct tagPKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ{
	tagPKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ)); }
	DT_INSTANCE_ID   stInstanceID; //����ID
}PKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ;

typedef struct tagDT_ITEM_NUM_INFO{
	UINT16           wItemID; //��ƷID
	UINT16           wItemNum; //��Ʒ����
}DT_ITEM_NUM_INFO;

typedef struct tagDT_ITEM_NUM_INFO_LST{
	UINT8            byNum; //��Ʒ������
	DT_ITEM_NUM_INFO astItemInfo[MAX_GROUP_ITEM_NUM]; //��Ʒ��Ϣ
}DT_ITEM_NUM_INFO_LST;

typedef struct tagDT_SKIP_NEIDAN_AWARD_ITEM_INFO{
	UINT8            byMonsterNum; //����
	DT_ITEM_NUM_INFO_LST astAwardItemInfoLst[MAX_NEIDAN_MONSTER_NUM]; //��Ʒ��Ϣ
}DT_SKIP_NEIDAN_AWARD_ITEM_INFO;

typedef struct tagPKT_CLIGS_SKIP_NEIDAN_BATTLE_ACK{
	tagPKT_CLIGS_SKIP_NEIDAN_BATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_SKIP_NEIDAN_BATTLE_ACK)); }
	UINT16           wErrCode; //������
	DT_SKIP_NEIDAN_AWARD_ITEM_INFO stAwardInfo; //�����б�
}PKT_CLIGS_SKIP_NEIDAN_BATTLE_ACK;

/*Define Structs and Unions        End*/


enum EN_ProtoCliGS_MessageID
{
	CLIGS_ENTERGS_REQ               = 2000        ,
	CLIGS_ENTERGS_ACK               = 2001        ,
	CLIGS_GET_HERO_INFO_REQ         = 2004        ,
	CLIGS_GET_HERO_INFO_ACK         = 2005        ,
	CLIGS_ENTER_HOME_REQ            = 2006        ,
	CLIGS_ENTER_HOME_ACK            = 2007        ,
	CLIGS_ENTER_INSTANCE_REQ        = 2008        ,
	CLIGS_ENTER_INSTANCE_ACK        = 2009        ,
	CLIGS_BATTLE_REQ                = 2010        ,
	CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ  = 2012        ,
	CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK  = 2013        ,
	CLIGS_EXIT_INSTANCE_REQ         = 2014        ,
	CLIGS_EXIT_INSTANCE_ACK         = 2015        ,
	CLIGS_GET_SCENE_INSTANCE_REQ    = 2016        ,
	CLIGS_GET_SCENE_INSTANCE_ACK    = 2017        ,
	CLIGS_EQUIP_STRENGTHEN_REQ      = 2022        ,
	CLIGS_EQUIP_STRENGTHEN_ACK      = 2023        ,
	CLIGS_OPEN_SMITHY_REQ           = 2024        ,
	CLIGS_OPEN_SMITHY_ACK           = 2025        ,
	CLIGS_OPEN_RECRUIT_REQ          = 2026        ,
	CLIGS_OPEN_RECRUIT_ACK          = 2027        ,
	CLIGS_RECRUIT_HERO_REQ          = 2028        ,
	CLIGS_RECRUIT_HERO_ACK          = 2029        ,
	CLIGS_OPEN_BAG_REQ              = 2032        ,
	CLIGS_OPEN_BAG_ACK              = 2033        ,
	CLIGS_RECV_TASK_ENCOURAGE_REQ   = 2040        ,
	CLIGS_RECV_TASK_ENCOURAGE_ACK   = 2041        ,
	CLIGS_OPEN_RACE_BUILD_REQ       = 2042        ,
	CLIGS_OPEN_RACE_BUILD_ACK       = 2043        ,
	CLIGS_CHALLENGE_REQ             = 2044        ,
	CLIGS_RECV_RANK_ENCOURAGE_REQ   = 2046        ,
	CLIGS_RECV_RANK_ENCOURAGE_ACK   = 2047        ,
	CLIGS_OPEN_SHOP_REQ             = 2048        ,
	CLIGS_OPEN_SHOP_ACK             = 2049        ,
	CLIGS_BUY_ITEM_REQ              = 2050        ,
	CLIGS_BUY_ITEM_ACK              = 2051        ,
	CLIGS_SELL_ITEM_REQ             = 2052        ,
	CLIGS_SELL_ITEM_ACK             = 2053        ,
	CLIGS_DISBAND_HERO_REQ          = 2054        ,
	CLIGS_DISBAND_HERO_ACK          = 2055        ,
	CLIGS_EQUIP_REQ                 = 2056        ,
	CLIGS_EQUIP_ACK                 = 2057        ,
	CLIGS_REGISTER_USERNAME_NTF     = 2058        ,
	CLIGS_EMBATTLE_REQ              = 2060        ,
	CLIGS_EMBATTLE_ACK              = 2061        ,
	CLIGS_CLR_PLAYER_DATA_REQ       = 2062        ,
	CLIGS_OPEN_EMBATTLE_REQ         = 2064        ,
	CLIGS_OPEN_EMBATTLE_ACK         = 2065        ,
	CLIGS_MAKE_ITEM_REQ             = 2068        ,
	CLIGS_MAKE_ITEM_ACK             = 2069        ,
	CLIGS_ONHOOK_REQ                = 2074        ,
	CLIGS_ONHOOK_ACK                = 2075        ,
	CLIGS_RECV_ONLINE_ENCOURAGE_REQ  = 2078        ,
	CLIGS_RECV_ONLINE_ENCOURAGE_ACK  = 2079        ,
	CLIGS_INCREASE_BAG_SIZE_REQ     = 2080        ,
	CLIGS_INCREASE_BAG_SIZE_ACK     = 2081        ,
	CLIGS_CLR_CHALLENGE_CD_REQ      = 2086        ,
	CLIGS_CLR_CHALLENGE_CD_ACK      = 2087        ,
	CLIGS_SYNC_TIME_REQ             = 2088        ,
	CLIGS_SYNC_TIME_ACK             = 2089        ,
	CLILS_REGISTER_DSPNAME_REQ      = 2090        ,
	CLILS_REGISTER_DSPNAME_ACK      = 2091        ,
	CLILS_USE_GOODS_REQ             = 2092        ,
	CLILS_USE_GOODS_ACK             = 2093        ,
	CLILS_OPEN_LOGIN_ENCOURAGE_REQ  = 2094        ,
	CLILS_OPEN_LOGIN_ENCOURAGE_ACK  = 2095        ,
	CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ  = 2096        ,
	CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK  = 2097        ,
	CLILS_RATE_LOGIN_ENCOURAGE_REQ  = 2098        ,
	CLILS_RATE_LOGIN_ENCOURAGE_ACK  = 2099        ,
	CLIGS_GET_RANK_REQ              = 2100        ,
	CLIGS_GET_RANK_ACK              = 2101        ,
	CLIGS_GET_RACE_BATTLELOG_REQ    = 2102        ,
	CLIGS_GET_RACE_BATTLELOG_ACK    = 2103        ,
	CLIGS_ACCEPT_TASK_REQ           = 2104        ,
	CLIGS_ACCEPT_TASK_ACK           = 2105        ,
	CLIGS_GIVEUP_TASK_REQ           = 2106        ,
	CLIGS_GIVEUP_TASK_ACK           = 2107        ,
	CLIGS_PLUNDER_REQ               = 2108        ,
	CLIGS_OPEN_CAPTURE_TAB_REQ      = 2110        ,
	CLIGS_OPEN_CAPTURE_TAB_ACK      = 2111        ,
	CLIGS_COLLECT_INCOME_REQ        = 2112        ,
	CLIGS_COLLECT_INCOME_ACK        = 2113        ,
	CLIGS_BLEED_CAPTURE_REQ         = 2114        ,
	CLIGS_BLEED_CAPTURE_ACK         = 2115        ,
	CLIGS_DEL_ENEMY_REQ             = 2116        ,
	CLIGS_DEL_ENEMY_ACK             = 2117        ,
	CLIGS_OPEN_ENEMY_TAB_REQ        = 2118        ,
	CLIGS_OPEN_ENEMY_TAB_ACK        = 2119        ,
	CLIGS_PLUNDER_BATTLELOG_NTF     = 2126        ,
	CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ  = 2128        ,
	CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK  = 2129        ,
	CLIGS_FREE_CAPTURE_REQ          = 2132        ,
	CLIGS_FREE_CAPTURE_ACK          = 2133        ,
	CLIGS_OPEN_MONEY_TREE_REQ       = 2134        ,
	CLIGS_OPEN_MONEY_TREE_ACK       = 2135        ,
	CLIGS_ROCK_MONEY_TREE_REQ       = 2136        ,
	CLIGS_ROCK_MONEY_TREE_ACK       = 2137        ,
	CLIGS_GET_PLUNDER_BATTLELOG_REQ  = 2138        ,
	CLIGS_GET_PLUNDER_BATTLELOG_ACK  = 2139        ,
	CLIGS_OPEN_GODWEAPON_REQ        = 2140        ,
	CLIGS_OPEN_GODWEAPON_ACK        = 2141        ,
	CLIGS_UPGRADE_GODWEAPON_REQ     = 2142        ,
	CLIGS_UPGRADE_GODWEAPON_ACK     = 2143        ,
	CLIGS_FREE_GODWEAPON_REQ        = 2144        ,
	CLIGS_FREE_GODWEAPON_ACK        = 2145        ,
	CLIGS_OPEN_AWAKEN_TAB_REQ       = 2148        ,
	CLIGS_OPEN_AWAKEN_TAB_ACK       = 2149        ,
	CLIGS_AWAKEN_REQ                = 2150        ,
	CLIGS_AWAKEN_ACK                = 2151        ,
	CLIGS_OPEN_DRESS_STUDY_TAB_REQ  = 2154        ,
	CLIGS_OPEN_DRESS_STUDY_TAB_ACK  = 2155        ,
	CLIGS_DRESS_STUDY_REQ           = 2156        ,
	CLIGS_DRESS_STUDY_ACK           = 2157        ,
	CLIGS_STUDY_TO_EXP_REQ          = 2160        ,
	CLIGS_STUDY_TO_EXP_ACK          = 2161        ,
	CLIGS_STUDY_UPGRADE_REQ         = 2162        ,
	CLIGS_STUDY_UPGRADE_ACK         = 2163        ,
	CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ  = 2166        ,
	CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK  = 2167        ,
	CLIGS_RACE_BATTLELOG_NTF        = 2172        ,
	CLIGS_VISIT_HERO_REQ            = 2180        ,
	CLIGS_VISIT_HERO_ACK            = 2181        ,
	CLIGS_BUY_PHYSTRENGTH_REQ       = 2182        ,
	CLIGS_BUY_PHYSTRENGTH_ACK       = 2183        ,
	CLIGS_CLR_PLUNDER_CD_REQ        = 2184        ,
	CLIGS_CLR_PLUNDER_CD_ACK        = 2185        ,
	CLIGS_OPEN_MAINTOWN_REQ         = 2186        ,
	CLIGS_OPEN_MAINTOWN_ACK         = 2187        ,
	CLIGS_RECV_MAINTOWN_INCOME_REQ  = 2188        ,
	CLIGS_RECV_MAINTOWN_INCOME_ACK  = 2189        ,
	CLIGS_LEVY_MAINTOWN_INCOME_REQ  = 2190        ,
	CLIGS_LEVY_MAINTOWN_INCOME_ACK  = 2191        ,
	CLIGS_SET_WORK_TYPE_REQ         = 2192        ,
	CLIGS_SET_WORK_TYPE_ACK         = 2193        ,
	CLIGS_DRIVE_AWAY_OWNER_REQ      = 2194        ,
	CLIGS_DRIVE_AWAY_OWNER_ACK      = 2195        ,
	CLIGS_COMPOSE_EQUIP_REQ         = 2212        ,
	CLIGS_COMPOSE_EQUIP_ACK         = 2213        ,
	CLIGS_OPEN_PHYSTRENGTH_REQ      = 2214        ,
	CLIGS_OPEN_PHYSTRENGTH_ACK      = 2215        ,
	CLIGS_RECV_LEFT_INCOME_REQ      = 2216        ,
	CLIGS_RECV_LEFT_INCOME_ACK      = 2217        ,
	CLIGS_SMITHY_BUY_EQUIP_REQ      = 2218        ,
	CLIGS_SMITHY_BUY_EQUIP_ACK      = 2219        ,
	CLIGS_CLR_STRENGTHEN_CD_REQ     = 2220        ,
	CLIGS_CLR_STRENGTHEN_CD_ACK     = 2221        ,
	CLIGS_OPEN_CROP_REQ             = 2222        ,
	CLIGS_OPEN_CROP_ACK             = 2223        ,
	CLIGS_OPEN_CROP_FIELD_REQ       = 2224        ,
	CLIGS_OPEN_CROP_FIELD_ACK       = 2225        ,
	CLIGS_CROP_REQ                  = 2226        ,
	CLIGS_CROP_ACK                  = 2227        ,
	CLIGS_GAIN_CROP_REQ             = 2228        ,
	CLIGS_GAIN_CROP_ACK             = 2229        ,
	CLIGS_OPEN_SCIENCE_BUILD_REQ    = 2230        ,
	CLIGS_OPEN_SCIENCE_BUILD_ACK    = 2231        ,
	CLIGS_UPDATE_SCIENCE_REQ        = 2232        ,
	CLIGS_UPDATE_SCIENCE_ACK        = 2233        ,
	CLIGS_CLR_CROP_REQ              = 2234        ,
	CLIGS_CLR_CROP_ACK              = 2235        ,
	CLIGS_OPEN_EXPERIENCE_REQ       = 2236        ,
	CLIGS_OPEN_EXPERIENCE_ACK       = 2237        ,
	CLIGS_USER_EXPERIENCE_REQ       = 2238        ,
	CLIGS_USER_EXPERIENCE_ACK       = 2239        ,
	CLIGS_OPEN_MELT_EQUIP_REQ       = 2240        ,
	CLIGS_OPEN_MELT_EQUIP_ACK       = 2241        ,
	CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ  = 2244        ,
	CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK  = 2245        ,
	CLIGS_UPDATE_ATTR_REQ           = 2246        ,
	CLIGS_UPDATE_ATTR_ACK           = 2247        ,
	CLIGS_COMPOSE_REQ               = 2248        ,
	CLIGS_COMPOSE_ACK               = 2249        ,
	CLIGS_REFRESH_ELITE_REQ         = 2250        ,
	CLIGS_REFRESH_ELITE_ACK         = 2251        ,
	CLIGS_ONHOOK_ELITE_REQ          = 2252        ,
	CLIGS_ONHOOK_ELITE_ACK          = 2253        ,
	CLIGS_GET_ITEM_REQ              = 2254        ,
	CLIGS_GET_ITEM_ACK              = 2255        ,
	CLIGS_GET_ORDER_ID_REQ          = 2256        ,
	CLIGS_GET_ORDER_ID_ACK          = 2257        ,
	CLIGS_EXCHANGE_RESULT           = 2258        ,
	CLIGS_SEED_COMPOSE_REQ          = 2260        ,
	CLIGS_SEED_COMPOSE_ACK          = 2261        ,
	CLIGS_CHAT_REQ                  = 2262        ,
	CLIGS_CHAT_ACK                  = 2263        ,
	CLIGS_CHAT_NTF                  = 2264        ,
	CLIGS_CROSS_DAY_NTF             = 2266        ,
	CLIGS_OPNE_ACTIVITY_CENTER_REQ  = 2268        ,
	CLIGS_OPNE_ACTIVITY_CENTER_ACK  = 2269        ,
	CLIGS_OPNE_EAT_BREAD_REQ        = 2270        ,
	CLIGS_OPNE_EAT_BREAD_ACK        = 2271        ,
	CLIGS_OBTAIN_PHYSTRENGTHEN_REQ  = 2272        ,
	CLIGS_OBTAIN_PHYSTRENGTHEN_ACK  = 2273        ,
	CLIGS_LEAVE_EAT_BREAD_REQ       = 2274        ,
	CLIGS_LEAVE_EAT_BREAD_ACK       = 2275        ,
	CLIGS_OPEN_PAOSHANG_BUILD_REQ   = 2276        ,
	CLIGS_OPEN_PAOSHANG_BUILD_ACK   = 2277        ,
	CLIGS_OPEN_YABIAO_REQ           = 2278        ,
	CLIGS_OPEN_YABIAO_ACK           = 2279        ,
	CLIGS_FLUSH_BIAO_QUALITY_REQ    = 2280        ,
	CLIGS_FLUSH_BIAO_QUALITY_ACK    = 2281        ,
	CLIGS_CLIMB_TOWER_RESET_REQ     = 2282        ,
	CLIGS_CLIMB_TOWER_RESET_ACK     = 2283        ,
	CLIGS_CLIMB_TOWER_ONHOOK_REQ    = 2284        ,
	CLIGS_CLIMB_TOWER_ONHOOK_ACK    = 2285        ,
	CLIGS_BEGIN_YABIAO_REQ          = 2286        ,
	CLIGS_BEGIN_YABIAO_ACK          = 2287        ,
	CLIGS_OPEN_JIEBIAO_REQ          = 2288        ,
	CLIGS_OPEN_JIEBIAO_ACK          = 2289        ,
	CLIGS_BEGIN_JIEBIAO_REQ         = 2290        ,
	CLIGS_BE_JIEBIAO_NTF            = 2292        ,
	CLIGS_QUERY_BATTLE_RECORD_REQ   = 2294        ,
	CLIGS_QUERY_YABIAO_BATTLELOG_REQ  = 2296        ,
	CLIGS_QUERY_YABIAO_BATTLELOG_ACK  = 2297        ,
	CLIGS_QUERY_YABIAO_ENCOURAGE_REQ  = 2298        ,
	CLIGS_QUERY_YABIAO_ENCOURAGE_ACK  = 2299        ,
	CLIGS_UPGRADE_JINGJIE_REQ       = 2300        ,
	CLIGS_UPGRADE_JINGJIE_ACK       = 2301        ,
	CLIGS_GEN_GAS_BALL_REQ          = 2302        ,
	CLIGS_GEN_GAS_BALL_ACK          = 2303        ,
	CLIGS_UP_GAS_BALL_LEVEL_REQ     = 2304        ,
	CLIGS_UP_GAS_BALL_LEVEL_ACK     = 2305        ,
	CLIGS_COLLECT_GAS_REQ           = 2306        ,
	CLIGS_COLLECT_GAS_ACK           = 2307        ,
	CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ  = 2308        ,
	CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK  = 2309        ,
	CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ  = 2310        ,
	CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK  = 2311        ,
	CLIGS_OPEN_JINGJIE_TAB_REQ      = 2312        ,
	CLIGS_OPEN_JINGJIE_TAB_ACK      = 2313        ,
	CLIGS_OPEN_GEN_GAS_TAB_REQ      = 2314        ,
	CLIGS_OPEN_GEN_GAS_TAB_ACK      = 2315        ,
	CLIGS_OPEN_SKILL_TAB_REQ        = 2316        ,
	CLIGS_OPEN_SKILL_TAB_ACK        = 2317        ,
	CLIGS_CLEAR_JIEBIAO_CD_REQ      = 2318        ,
	CLIGS_CLEAR_JIEBIAO_CD_ACK      = 2319        ,
	CLIGS_OPEN_VIP_TAB_REQ          = 2320        ,
	CLIGS_OPEN_VIP_TAB_ACK          = 2321        ,
	CLIGS_OPEN_CLIMB_TOWER_REQ      = 2322        ,
	CLIGS_OPEN_CLIMB_TOWER_ACK      = 2323        ,
	CLIGS_BUY_CLIMB_TOWER_RESET_REQ  = 2324        ,
	CLIGS_BUY_CLIMB_TOWER_RESET_ACK  = 2325        ,
	CLIGS_OPEN_XIANGQIAN_TAB_REQ    = 2326        ,
	CLIGS_OPEN_XIANGQIAN_TAB_ACK    = 2327        ,
	CLIGS_XIANGQIAN_REQ             = 2330        ,
	CLIGS_XIANGQIAN_ACK             = 2331        ,
	CLIGS_CHECK_APPSTORE_ORDER_ID_REQ  = 2332        ,
	CLIGS_CHECK_APPSTORE_ORDER_ID_ACK  = 2333        ,
	CLIGS_REMOVE_XIANGQIAN_REQ      = 2334        ,
	CLIGS_REMOVE_XIANGQIAN_ACK      = 2335        ,
	CLIGS_RESET_ELITE_INSTANCE_REQ  = 2336        ,
	CLIGS_RESET_ELITE_INSTANCE_ACK  = 2337        ,
	CLIGS_ELITE_INSTANCE_ON_HOOK_REQ  = 2338        ,
	CLIGS_ELITE_INSTANCE_ON_HOOK_ACK  = 2339        ,
	CLIGS_GET_ELITE_INSTANCE_REQ    = 2340        ,
	CLIGS_GET_ELITE_INSTANCE_ACK    = 2341        ,
	CLIGS_QUICK_EQUIP_REQ           = 2342        ,
	CLIGS_QUICK_EQUIP_ACK           = 2343        ,
	CLIGS_GET_ACTIVITY_PROMPT_REQ   = 2344        ,
	CLIGS_GET_ACTIVITY_PROMPT_ACK   = 2345        ,
	CLIGS_OPEN_CHAT_REQ             = 2346        ,
	CLIGS_OPEN_CHAT_ACK             = 2347        ,
	CLIGS_BLUE_TO_PURPLE_REQ        = 2348        ,
	CLIGS_BLUE_TO_PURPLE_ACK        = 2349        ,
	CLIGS_PKBATTLE_REQ              = 2350        ,
	CLIGS_RESOURCES_PROMPT_REQ      = 2352        ,
	CLIGS_RESOURCES_PROMPT_ACK      = 2353        ,
	ENTER_BOSSB_REQ                 = 2354        ,
	ENTER_BOSSB_ACK                 = 2355        ,
	LEAVE_BOSSB_REQ                 = 2356        ,
	LEAVE_BOSSB_ACK                 = 2357        ,
	BOSSB_MOVE_REQ                  = 2358        ,
	BOSSB_MOVE_ACK                  = 2359        ,
	BOSSB_HURT_REQ                  = 2360        ,
	BOSSB_HURT_ACK                  = 2361        ,
	BOSSB_POS_NTF                   = 2362        ,
	BOSSB_OVER_NTF                  = 2366        ,
	OPEN_INSPIRE_TAB_REQ            = 2368        ,
	OPEN_INSPIRE_TAB_ACK            = 2369        ,
	INSPIRE_POWER_REQ               = 2370        ,
	INSPIRE_POWER_ACK               = 2371        ,
	BOSSB_RELIVE_REQ                = 2372        ,
	BOSSB_RELIVE_ACK                = 2373        ,
	BOSSB_GET_LAST_BOSSB_INFO_REQ   = 2374        ,
	BOSSB_GET_LAST_BOSSB_INFO_ACK   = 2375        ,
	CLILS_OPEN_RECHARGE_ENCOURAGE_REQ  = 2376        ,
	CLILS_OPEN_RECHARGE_ENCOURAGE_ACK  = 2377        ,
	CLIGS_RECV_RECHARGE_ENCOURAGE_REQ  = 2378        ,
	CLIGS_RECV_RECHARGE_ENCOURAGE_ACK  = 2379        ,
	CLILS_OPEN_SCORE_ENCOURAGE_REQ  = 2380        ,
	CLILS_OPEN_SCORE_ENCOURAGE_ACK  = 2381        ,
	CLIGS_RECV_SCORE_ENCOURAGE_REQ  = 2382        ,
	CLIGS_RECV_SCORE_ENCOURAGE_ACK  = 2383        ,
	CLIGS_GET_RANDOM_DSPNAME_REQ    = 2384        ,
	CLIGS_GET_RANDOM_DSPNAME_ACK    = 2385        ,
	CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ  = 2386        ,
	CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK  = 2387        ,
	CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ  = 2388        ,
	CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK  = 2389        ,
	CLIGS_EXPERIENCE_TRANSFER_REQ   = 2390        ,
	CLIGS_EXPERIENCE_TRANSFER_ACK   = 2391        ,
	CLIGS_OPEN_RDCHALLENGE_TAB_REQ  = 2392        ,
	CLIGS_OPEN_RDCHALLENGE_TAB_ACK  = 2393        ,
	CLIGS_RDCHALLENGE_REQ           = 2394        ,
	CLIGS_CLR_RDCHALLENGE_CD_REQ    = 2396        ,
	CLIGS_CLR_RDCHALLENGE_CD_ACK    = 2397        ,
	CLIGS_OPEN_WORSHIP_TAB_REQ      = 2398        ,
	CLIGS_OPEN_WORSHIP_TAB_ACK      = 2399        ,
	CLIGS_WORSHIP_REQ               = 2400        ,
	CLIGS_WORSHIP_ACK               = 2401        ,
	CLIGS_RECV_RATING_ENCOURAGE_REQ  = 2402        ,
	CLIGS_RECV_RATING_ENCOURAGE_ACK  = 2403        ,
	CLIGS_ACTIVITY_NOTIFY_REQ       = 2406        ,
	CLIGS_ACTIVITY_NOTIFY_ACK       = 2407        ,
	CLIGS_OPEN_DOGFECES_REQ         = 2408        ,
	CLIGS_OPEN_DOGFECES_ACK         = 2409        ,
	CLIGS_GET_ACTIVITY_CENTER_REQ   = 2410        ,
	CLIGS_GET_ACTIVITY_CENTER_ACK   = 2411        ,
	BOSSB_INFO_SYNC_NTF             = 2412        ,
	CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ  = 2414        ,
	CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK  = 2415        ,
	CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ  = 2416        ,
	CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK  = 2417        ,
	CLIGS_OPEN_GEM_MAKER_TAB_REQ    = 2418        ,
	CLIGS_OPEN_GEM_MAKER_TAB_ACK    = 2419        ,
	CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ  = 2420        ,
	CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK  = 2421        ,
	CLIGS_EXCHANGE_STUDY_REQ        = 2422        ,
	CLIGS_EXCHANGE_STUDY_ACK        = 2423        ,
	CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ  = 2424        ,
	CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK  = 2425        ,
	CLIGS_EQUIP_COMPOSE_REQ         = 2426        ,
	CLIGS_EQUIP_COMPOSE_ACK         = 2427        ,
	CLIGS_RECV_COMPOSE_EQUIP_REQ    = 2428        ,
	CLIGS_RECV_COMPOSE_EQUIP_ACK    = 2429        ,
	CLIGS_OPEN_FACTION_REQ          = 2430        ,
	CLIGS_OPEN_FACTION_ACK          = 2431        ,
	CLIGS_APPLY_FACTION_REQ         = 2432        ,
	CLIGS_APPLY_FACTION_ACK         = 2433        ,
	CLIGS_CANCEL_APPLY_FACTION_REQ  = 2434        ,
	CLIGS_CANCEL_APPLY_FACTION_ACK  = 2435        ,
	CLIGS_CREATE_FACTION_REQ        = 2436        ,
	CLIGS_CREATE_FACTION_ACK        = 2437        ,
	CLIGS_SEARCH_FACTION_REQ        = 2438        ,
	CLIGS_SEARCH_FACTION_ACK        = 2439        ,
	CLIGS_OPEN_OWNER_FACTION_REQ    = 2440        ,
	CLIGS_OPEN_OWNER_FACTION_ACK    = 2441        ,
	CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ  = 2442        ,
	CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK  = 2443        ,
	CLIGS_DOORS_TRIBUTE_FACTION_REQ  = 2444        ,
	CLIGS_DOORS_TRIBUTE_FACTION_ACK  = 2445        ,
	CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ  = 2446        ,
	CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK  = 2447        ,
	CLIGS_KICKED_FACTION_REQ        = 2448        ,
	CLIGS_KICKED_FACTION_ACK        = 2449        ,
	CLIGS_JOB_FACTION_REQ           = 2450        ,
	CLIGS_JOB_FACTION_ACK           = 2451        ,
	CLIGS_SET_NOTICE_FACTION_REQ    = 2452        ,
	CLIGS_SET_NOTICE_FACTION_ACK    = 2453        ,
	CLIGS_DISSOLVE_FACTION_REQ      = 2454        ,
	CLIGS_DISSOLVE_FACTION_ACK      = 2455        ,
	CLIGS_AUDIT_FACTION_REQ         = 2456        ,
	CLIGS_AUDIT_FACTION_ACK         = 2457        ,
	CLIGS_OPEN_APPLY_FACTION_REQ    = 2458        ,
	CLIGS_OPEN_APPLY_FACTION_ACK    = 2459        ,
	CLIGS_OPEN_RANK_FACTION_REQ     = 2460        ,
	CLIGS_OPEN_RANK_FACTION_ACK     = 2461        ,
	CLIGS_OPEN_AUDIT_FACTION_REQ    = 2462        ,
	CLIGS_OPEN_AUDIT_FACTION_ACK    = 2463        ,
	CLIGS_OPEN_GATHER_SCIENCE_REQ   = 2464        ,
	CLIGS_OPEN_GATHER_SCIENCE_ACK   = 2465        ,
	CLIGS_GATHER_SCIENCE_REQ        = 2466        ,
	CLIGS_GATHER_SCIENCE_ACK        = 2467        ,
	CLIGS_MELT_REQ                  = 2468        ,
	CLIGS_MELT_ACK                  = 2469        ,
	CLIGS_NOTICE_NTF                = 2470        ,
	CLIGS_ACTIVITY_ENC_NTF          = 2472        ,
	CLIGS_OPEN_AWAKEN_TAB_REQ2      = 2474        ,
	CLIGS_OPEN_AWAKEN_TAB_ACK2      = 2475        ,
	CLIGS_AWAKEN_REQ2               = 2476        ,
	CLIGS_AWAKEN_ACK2               = 2477        ,
	CLIGS_OPEN_DRESS_STUDY_TAB_REQ2  = 2478        ,
	CLIGS_OPEN_DRESS_STUDY_TAB_ACK2  = 2479        ,
	CLIGS_DRESS_STUDY_REQ2          = 2480        ,
	CLIGS_DRESS_STUDY_ACK2          = 2481        ,
	CLIGS_STUDY_TO_EXP_REQ2         = 2482        ,
	CLIGS_STUDY_TO_EXP_ACK2         = 2483        ,
	CLIGS_STUDY_UPGRADE_REQ2        = 2484        ,
	CLIGS_STUDY_UPGRADE_ACK2        = 2485        ,
	CLIGS_OPEN_BLUE_PAVILION_REQ    = 2486        ,
	CLIGS_OPEN_BLUE_PAVILION_ACK    = 2487        ,
	CLIGS_BEGBLUE_REQ               = 2488        ,
	CLIGS_BEGBLUE_ACK               = 2489        ,
	CLIGS_IMPROVELUCK_REQ           = 2490        ,
	CLIGS_IMPROVELUCK_ACK           = 2491        ,
	CLIGS_COMFIRM_BEGBLUE_REQ       = 2492        ,
	CLIGS_COMFIRM_BEGBLUE_ACK       = 2493        ,
	CLIGS_GET_OPENLIGHT_INFO_REQ    = 2508        ,
	CLIGS_GET_OPENLIGHT_INFO_ACK    = 2509        ,
	CLIGS_OPENLIGHT_INFO_REQ        = 2510        ,
	CLIGS_OPENLIGHT_INFO_ACK        = 2511        ,
	CLIGS_CHANGE_CAREER_REQ         = 2512        ,
	CLIGS_CHANGE_CAREER_ACK         = 2513        ,
	CLIGS_CHALLENGE_MYSELF_REQ      = 2514        ,
	CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ  = 2516        ,
	CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK  = 2517        ,
	CLIGS_OPEN_ITEM_EXCHANGE_REQ    = 2518        ,
	CLIGS_OPEN_ITEM_EXCHANGE_ACK    = 2519        ,
	CLIGS_ITEM_EXCHANGE_REQ         = 2520        ,
	CLIGS_ITEM_EXCHANGE_ACK         = 2521        ,
	CLIGS_OPEN_BIGREWARD_TAB_REQ    = 2522        ,
	CLIGS_OPEN_BIGREWARD_TAB_ACK    = 2523        ,
	CLIGS_OPEN_COLLECT_CLUE_TAB_REQ  = 2524        ,
	CLIGS_OPEN_COLLECT_CLUE_TAB_ACK  = 2525        ,
	CLIGS_OPEN_CLUE_GRID_REQ        = 2526        ,
	CLIGS_OPEN_CLUE_GRID_ACK        = 2527        ,
	CLIGS_SHAKE_DICE_REQ            = 2528        ,
	CLIGS_SHAKE_DICE_ACK            = 2529        ,
	CLIGS_REFRESH_DICE_REQ          = 2530        ,
	CLIGS_REFRESH_DICE_ACK          = 2531        ,
	CLIGS_COMFIRM_DICE_POINT_REQ    = 2532        ,
	CLIGS_COMFIRM_DICE_POINT_ACK    = 2533        ,
	CLIGS_PLAYER_RES_NTF            = 2536        ,
	CLIGS_OPERATING_ACTIVITY_NTF    = 2568        ,
	CLIGS_OPERATING_ACTIVITY_BATTLE_REQ  = 2538        ,
	CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ  = 2540        ,
	CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK  = 2541        ,
	CLIGS_DEL_FRIEND_REQ            = 2542        ,
	CLIGS_DEL_FRIEND_ACK            = 2543        ,
	CLIGS_SEARCH_PLAYER_REQ         = 2544        ,
	CLIGS_SEARCH_PLAYER_ACK         = 2545        ,
	CLIGS_VIEW_PLAYER_REQ           = 2546        ,
	CLIGS_VIEW_PLAYER_ACK           = 2547        ,
	CLIGS_ADD_FRIEND_REQ            = 2548        ,
	CLIGS_ADD_FRIEND_ACK            = 2549        ,
	CLIGS_OPEN_SEND_FLOWER_TAB_REQ  = 2550        ,
	CLIGS_OPEN_SEND_FLOWER_TAB_ACK  = 2551        ,
	CLIGS_SEND_FLOWER_REQ           = 2552        ,
	CLIGS_SEND_FLOWER_ACK           = 2553        ,
	CLIGS_GET_FLOWER_BY_PLAYERID_REQ  = 2554        ,
	CLIGS_GET_FLOWER_BY_PLAYERID_ACK  = 2555        ,
	CLIGS_GET_FLOWER_RANKING_REQ    = 2556        ,
	CLIGS_GET_FLOWER_RANKING_ACK    = 2557        ,
	CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ  = 2558        ,
	CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK  = 2559        ,
	CLIGS_SEND_PRIVATE_MSG_REQ      = 2560        ,
	CLIGS_SEND_PRIVATE_MSG_ACK      = 2561        ,
	CLIGS_DEL_PRIVATE_MSG_LOG_REQ   = 2562        ,
	CLIGS_DEL_PRIVATE_MSG_LOG_ACK   = 2563        ,
	CLIGS_ADD_TO_BLACKLIST_REQ      = 2564        ,
	CLIGS_ADD_TO_BLACKLIST_ACK      = 2565        ,
	CLIGS_MOVE_FROM_BLACKLIST_REQ   = 2566        ,
	CLIGS_MOVE_FROM_BLACKLIST_ACK   = 2567        ,
	CLIGS_ONLINE_PRIVATE_MSG_NTF    = 2570        ,
	CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ  = 2572        ,
	CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK  = 2573        ,
	CLIGS_READ_OFFLINE_MSG_REQ      = 2574        ,
	CLIGS_READ_OFFLINE_MSG_ACK      = 2575        ,
	CLIGS_OPEN_RAREITEMROOM_REQ     = 2576        ,
	CLIGS_OPEN_RAREITEMROOM_ACK     = 2577        ,
	CLIGS_BUY_RAREITEM_REQ          = 2578        ,
	CLIGS_BUY_RAREITEM_ACK          = 2579        ,
	CLIGS_OPEN_UPGRADERAREITEM_REQ  = 2580        ,
	CLIGS_OPEN_UPGRADERAREITEM_ACK  = 2581        ,
	CLIGS_UPGRADE_RAREITEM_REQ      = 2582        ,
	CLIGS_UPGRADE_RAREITEM_ACK      = 2583        ,
	CLIGS_OPEN_GYMNASIUM_REQ        = 2584        ,
	CLIGS_OPEN_GYMNASIUM_ACK        = 2585        ,
	CLIGS_LEARN_GYMNASIUM_SKILL_REQ  = 2586        ,
	CLIGS_LEARN_GYMNASIUM_SKILL_ACK  = 2587        ,
	CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ  = 2588        ,
	CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK  = 2589        ,
	CLIGS_GYMNASIUM_UPGRADE_REQ     = 2590        ,
	CLIGS_GYMNASIUM_UPGRADE_ACK     = 2591        ,
	CLIGS_OPEN_SHADE_REQ            = 2592        ,
	CLIGS_OPEN_SHADE_ACK            = 2593        ,
	CLIGS_OPEN_SHADE_UPGRADE_REQ    = 2594        ,
	CLIGS_OPEN_SHADE_UPGRADE_ACK    = 2595        ,
	CLIGS_SHADE_UPGRADE_REQ         = 2596        ,
	CLIGS_SHADE_UPGRADE_ACK         = 2597        ,
	CLIGS_OPEN_GOLDMODE_REQ         = 2598        ,
	CLIGS_OPEN_GOLDMODE_ACK         = 2599        ,
	CLIGS_OPEN_HUNTING_REQ          = 2600        ,
	CLIGS_OPEN_HUNTING_ACK          = 2601        ,
	CLIGS_FIND_MONSTER_REQ          = 2602        ,
	CLIGS_FIND_MONSTER_ACK          = 2603        ,
	CLIGS_HUNTING_BATTLE_REQ        = 2606        ,
	CLIGS_CHANGE_SCHEDEULE_NTF      = 2608        ,
	CLIGS_OPEN_HOT_SPRING_REQ       = 2610        ,
	CLIGS_OPEN_HOT_SPRING_ACK       = 2611        ,
	CLIGS_SELECT_WINE_REQ           = 2612        ,
	CLIGS_SELECT_WINE_ACK           = 2613        ,
	CLIGS_DRINK_WINE_REQ            = 2614        ,
	CLIGS_DRINK_WINE_ACK            = 2615        ,
	CLIGS_DRINK_WINE_MOVE_REQ       = 2616        ,
	CLIGS_DRINK_WINE_MOVE_ACK       = 2617        ,
	CLIGS_LEAVE_HOT_SPRING_REQ      = 2618        ,
	CLIGS_LEAVE_HOT_SPRING_ACK      = 2619        ,
	CLIGS_HOT_SPRING_POS_NTF        = 2620        ,
	CLIGS_CHANGE_OTHER_REQ          = 2622        ,
	CLIGS_CHANGE_OTHER_ACK          = 2623        ,
	CLIGS_GIVE_WINE_REQ             = 2626        ,
	CLIGS_GIVE_WINE_ACK             = 2627        ,
	CLIGS_CLICK_SELECT_WINE_REQ     = 2628        ,
	CLIGS_CLICK_SELECT_WINE_ACK     = 2629        ,
	CLIGS_SURE_GIVE_WINE_REQ        = 2630        ,
	CLIGS_SURE_GIVE_WINE_ACK        = 2631        ,
	CLIGS_CLOSED_MONSTER_REQ        = 2632        ,
	CLIGS_CLOSED_MONSTER_ACK        = 2633        ,
	CLIGS_FACTION_PLAYER_CHANGE_REQ  = 2634        ,
	CLIGS_FACTION_PLAYER_CHANGE_ACK  = 2635        ,
	CLIGS_GIVE_WINE_ACTIVITY_NTF    = 2636        ,
	CLIGS_LEAVE_FACTION_REQ         = 2638        ,
	CLIGS_LEAVE_FACTION_ACK         = 2639        ,
	CLIGS_OPEN_LEAVE_FACTION_REQ    = 2640        ,
	CLIGS_OPEN_LEAVE_FACTION_ACK    = 2641        ,
	CLIGS_OPEN_FACTION_UPGRADE_REQ  = 2642        ,
	CLIGS_OPEN_FACTION_UPGRADE_ACK  = 2643        ,
	CLIGS_FACTION_UPGRADE_REQ       = 2644        ,
	CLIGS_FACTION_UPGRADE_ACK       = 2645        ,
	CLIGS_OPEN_EQUIP_MASTER_REQ     = 2646        ,
	CLIGS_OPEN_EQUIP_MASTER_ACK     = 2647        ,
	CLIGS_ACTIVATE_MASTER_REQ       = 2648        ,
	CLIGS_ACTIVATE_MASTER_ACK       = 2649        ,
	CLIGS_BREAK_MASTER_REQ          = 2650        ,
	CLIGS_BREAK_MASTER_ACK          = 2651        ,
	CLIGS_GET_MASTER_BOOK_REQ       = 2652        ,
	CLIGS_GET_MASTER_BOOK_ACK       = 2653        ,
	CLIGS_WIPE_MASTER_BOOK_REQ      = 2654        ,
	CLIGS_WIPE_MASTER_BOOK_ACK      = 2655        ,
	CLIGS_MASTER_CHEAT_REQ          = 2722        ,
	CLIGS_MASTER_CHEAT_ACK          = 2723        ,
	CLIGS_CONFIRM_MASTER_BOOK_REQ   = 2656        ,
	CLIGS_CONFIRM_MASTER_BOOK_ACK   = 2657        ,
	CLIGS_OPEN_BAD_REWARD_REQ       = 2658        ,
	CLIGS_OPEN_BAD_REWARD_ACK       = 2659        ,
	CLIGS_GET_BAD_REWARD_REQ        = 2660        ,
	CLIGS_GET_BAD_REWARD_ACK        = 2661        ,
	CLIGS_OPEN_COURAGE_REQ          = 2662        ,
	CLIGS_OPEN_COURAGE_ACK          = 2663        ,
	CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ  = 2664        ,
	CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK  = 2665        ,
	CLIGS_COURAGE_CREATE_GROUP_REQ  = 2666        ,
	CLIGS_COURAGE_CREATE_GROUP_ACK  = 2667        ,
	CLIGS_COURAGE_JOIN_GROUP_REQ    = 2668        ,
	CLIGS_COURAGE_JOIN_GROUP_ACK    = 2669        ,
	CLIGS_COURAGE_OPERATE_HERO_REQ  = 2670        ,
	CLIGS_COURAGE_OPERATE_HERO_ACK  = 2671        ,
	CLIGS_COURAGE_CONFIRM_HERO_REQ  = 2672        ,
	CLIGS_COURAGE_CONFIRM_HERO_ACK  = 2673        ,
	CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ  = 2674        ,
	CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK  = 2675        ,
	CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ  = 2676        ,
	CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK  = 2677        ,
	CLIGS_COURAGE_PLAYER_READY_REQ  = 2678        ,
	CLIGS_COURAGE_PLAYER_READY_ACK  = 2679        ,
	CLIGS_COURAGE_PLAYER_START_REQ  = 2680        ,
	CLIGS_COURAGE_JOIN_GROUP_NTF    = 2682        ,
	CLIGS_COURAGE_QUIT_GROUP_NTF    = 2684        ,
	CLIGS_COURAGE_OPERATE_HERO_NTF  = 2686        ,
	CLIGS_COURAGE_PLAYER_READY_NTF  = 2688        ,
	CLIGS_COURAGE_PLAYER_FIRED_NTF  = 2690        ,
	CLIGS_COURAGE_LEAVE_GROUP_REQ   = 2692        ,
	CLIGS_COURAGE_LEAVE_GROUP_ACK   = 2693        ,
	CLIGS_OPEN_COURAGE_SHOP_REQ     = 2694        ,
	CLIGS_OPEN_COURAGE_SHOP_ACK     = 2695        ,
	CLIGS_PLAYER_FACTION_BATTLELOG_NTF  = 2696        ,
	CLIGS_PLAYER_FACTION_READ_REQ   = 2698        ,
	CLIGS_PLAYER_FACTION_READ_ACK   = 2699        ,
	CLIGS_OPEN_FIND_DRINK_REQ       = 2700        ,
	CLIGS_OPEN_FIND_DRINK_ACK       = 2701        ,
	CLIGS_OPEN_LOG_FACTION_REQ      = 2702        ,
	CLIGS_OPEN_LOG_FACTION_ACK      = 2703        ,
	CLIGS_COURAGE_BATTLE_REQ        = 2704        ,
	CLIGS_COURAGE_BATTLE_ACK        = 2705        ,
	CLIGS_COURAGE_BATTLE_NTF        = 2706        ,
	CLIGS_OPEN_FACTION_BUILD_GROUP_REQ  = 2708        ,
	CLIGS_OPEN_FACTION_BUILD_GROUP_ACK  = 2709        ,
	CLIGS_COURAGE_GROUP_DISMISS_NTF  = 2710        ,
	CLIGS_HOT_SPRING_REWARD_NTF     = 2712        ,
	CLIGS_COURAGE_GROUP_REFRESH_REQ  = 2714        ,
	CLIGS_COURAGE_GROUP_REFRESH_ACK  = 2715        ,
	CLIGS_COURAGE_ENTER_GROUP_REQ   = 2716        ,
	CLIGS_COURAGE_ENTER_GROUP_ACK   = 2717        ,
	CLIGS_LEAVE_COURAGE_REQ         = 2718        ,
	CLIGS_LEAVE_COURAGE_ACK         = 2719        ,
	CLIGS_HOT_SPRING_OVER_REWARD_REQ  = 2720        ,
	CLIGS_HOT_SPRING_OVER_REWARD_ACK  = 2721        ,
	CLIGS_OPEN_GOLD_NTF             = 2722        ,
	CLIGS_HUNTING_ITEGRAL_REQ       = 2724        ,
	CLIGS_HUNTING_ITEGRAL_ACK       = 2725        ,
	CLIGS_ACTIVITY_END_NTF          = 2726        ,
	CLIGS_PROMPT_IGNORE_REQ         = 2728        ,
	CLIGS_PROMPT_IGNORE_ACK         = 2729        ,
	CLIGS_COURAGE_GROUP_REFRESH_NTF  = 2730        ,
	CLIGS_HOME_BUILD_PROMPT_NTF     = 2732        ,
	CLIGS_OPEN_LEAVE_HOT_SPRING_REQ  = 2736        ,
	CLIGS_OPEN_LEAVE_HOT_SPRING_ACK  = 2737        ,
	CLIGS_FACTION_OPERATE_NTF       = 2738        ,
	CLIGS_FACTION_PROMPT_NTF        = 2740        ,
	CLIGS_COURAGE_GET_AWARD_REQ     = 2742        ,
	CLIGS_COURAGE_GET_AWARD_ACK     = 2743        ,
	CLIGS_COURAGE_GET_BATTLE_RESULT_REQ  = 2744        ,
	CLIGS_COURAGE_GET_BATTLE_RESULT_ACK  = 2745        ,
	CLIGS_DOORSTRIBUTE_SYNC_NTF     = 2746        ,
	CLIGS_AUDIT_FACTION_REQ2        = 2748        ,
	CLIGS_AUDIT_FACTION_ACK2        = 2749        ,
	CLIGS_AUDIT_ALL_REFUSE_REQ      = 2750        ,
	CLIGS_AUDIT_ALL_REFUSE_ACK      = 2751        ,
	CLIGS_OPEN_AUDIT_FACTION_REQ2   = 2752        ,
	CLIGS_OPEN_AUDIT_FACTION_ACK2   = 2753        ,
	CLIGS_OPEN_VIP_GIFT_REQ         = 2758        ,
	CLIGS_OPEN_VIP_GIFT_ACK         = 2759        ,
	CLIGS_GET_VIP_GIFT_REQ          = 2760        ,
	CLIGS_GET_VIP_GIFT_ACK          = 2761        ,
	CLIGS_UPGRADE_CROP_FIELD_REQ    = 2762        ,
	CLIGS_UPGRADE_CROP_FIELD_ACK    = 2763        ,
	CLIGS_OPEN_CROP_REQ2            = 2764        ,
	CLIGS_OPEN_CROP_ACK2            = 2765        ,
	CLIGS_OPEN_CROP_FIELD_REQ2      = 2766        ,
	CLIGS_OPEN_CROP_FIELD_ACK2      = 2767        ,
	CLIGS_CROP_REQ2                 = 2768        ,
	CLIGS_CROP_ACK2                 = 2739        ,
	CLIGS_GAIN_CROP_REQ2            = 2770        ,
	CLIGS_GAIN_CROP_ACK2            = 2771        ,
	CLIGS_CLR_CROP_REQ2             = 2772        ,
	CLIGS_CLR_CROP_ACK2             = 2773        ,
	CLIGS_OPEN_RECV_FLOWER_TAB_REQ  = 2774        ,
	CLIGS_OPEN_RECV_FLOWER_TAB_ACK  = 2775        ,
	CLIGS_ACCEPT_FLOWER_REQ         = 2776        ,
	CLIGS_ACCEPT_FLOWER_ACK         = 2777        ,
	CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ  = 2778        ,
	CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK  = 2779        ,
	CLIGS_BUY_RAREITEM_REQ2         = 2780        ,
	CLIGS_BUY_RAREITEM_ACK2         = 2781        ,
	CLIGS_LEARN_GYMNASIUM_SKILL_REQ2  = 2782        ,
	CLIGS_LEARN_GYMNASIUM_SKILL_ACK2  = 2783        ,
	CLIGS_SEND_FLOWER_EX_REQ        = 2784        ,
	CLIGS_SEND_FLOWER_EX_ACK        = 2785        ,
	CLIGS_FACTION_PLAYERS_INFO_REQ  = 2786        ,
	CLIGS_FACTION_PLAYERS_INFO_ACK  = 2787        ,
	CLIGS_CHANGE_FACTION_ICON_REQ   = 2788        ,
	CLIGS_CHANGE_FACTION_ICON_ACK   = 2789        ,
	CLIGS_OPEN_CHANGE_FACTION_ICON_REQ  = 2790        ,
	CLIGS_OPEN_CHANGE_FACTION_ICON_ACK  = 2791        ,
	CLIGS_FIND_BACK_DOORSTRIBUTE_REQ  = 2792        ,
	CLIGS_FIND_BACK_DOORSTRIBUTE_ACK  = 2793        ,
	CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ  = 2794        ,
	CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK  = 2795        ,
	CLIGS_LEAVE_COURAGE_BATTLE_REQ  = 2796        ,
	CLIGS_LEAVE_COURAGE_BATTLE_ACK  = 2797        ,
	CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ  = 2798        ,
	CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK  = 2799        ,
	CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2  = 2800        ,
	CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2  = 2801        ,
	CLIGS_SEARCH_PLAYER_REQ2        = 2802        ,
	CLIGS_SEARCH_PLAYER_ACK2        = 2803        ,
	CLIGS_OPEN_EMBATTLE_REQ2        = 2804        ,
	CLIGS_OPEN_EMBATTLE_ACK2        = 2805        ,
	CLIGS_UPGRADE_FORMATION_REQ     = 2806        ,
	CLIGS_UPGRADE_FORMATION_ACK     = 2807        ,
	CLIGS_OPEN_FORMATION_SCIENCE_REQ  = 2808        ,
	CLIGS_OPEN_FORMATION_SCIENCE_ACK  = 2809        ,
	CLILS_REGISTER_FACTION_REQ      = 2810        ,
	CLILS_REGISTER_FACTION_ACK      = 2811        ,
	CLIGS_UPGRADE_FORMATION_SCIENCE_REQ  = 2812        ,
	CLIGS_UPGRADE_FORMATION_SCIENCE_ACK  = 2813        ,
	CLIGS_GET_BLUE_ENCOURAGE_REQ    = 2814        ,
	CLIGS_GET_BLUE_ENCOURAGE_ACK    = 2815        ,
	CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ  = 2816        ,
	CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK  = 2817        ,
	CLIGS_OPEN_FACTION_SKILL_REQ    = 2818        ,
	CLIGS_OPEN_FACTION_SKILL_ACK    = 2819        ,
	CLIGS_RESOURCE_SYNC_NTF         = 2820        ,
	CLIGS_OPEN_PLAYER_PANEL_REQ     = 2822        ,
	CLIGS_OPEN_PLAYER_PANEL_ACK     = 2823        ,
	CLIGS_PLAYER_INFO_AWAKEN_REQ    = 2824        ,
	CLIGS_PLAYER_INFO_AWAKEN_ACK    = 2825        ,
	CLIGS_PLAYER_INFO_GODWEAPON_REQ  = 2826        ,
	CLIGS_PLAYER_INFO_GODWEAPON_ACK  = 2827        ,
	CLIGS_PLAYER_INFO_JEWELRY_REQ   = 2828        ,
	CLIGS_PLAYER_INFO_JEWELRY_ACK   = 2829        ,
	CLIGS_OPEN_RESOLVE_TRIGRAM_REQ  = 2830        ,
	CLIGS_OPEN_RESOLVE_TRIGRAM_ACK  = 2831        ,
	CLIGS_RESOLVE_TRIGRAM_REQ       = 2832        ,
	CLIGS_RESOLVE_TRIGRAM_ACK       = 2833        ,
	CLIGS_DRESS_JEWELRY_REQ         = 2834        ,
	CLIGS_DRESS_JEWELRY_ACK         = 2835        ,
	CLIGS_OPEN_HERO_SELECT_PANEL_REQ  = 2836        ,
	CLIGS_OPEN_HERO_SELECT_PANEL_ACK  = 2837        ,
	CLIGS_OPEN_JEWELRY_GENERATE_REQ  = 2838        ,
	CLIGS_OPEN_JEWELRY_GENERATE_ACK  = 2839        ,
	CLIGS_JEWELRY_GENERATE_INFO_REQ  = 2840        ,
	CLIGS_JEWELRY_GENERATE_INFO_ACK  = 2841        ,
	CLIGS_JEWELRY_GENERATE_REQ      = 2842        ,
	CLIGS_JEWELRY_GENERATE_ACK      = 2843        ,
	CLIGS_JEWELRY_STRENGTH_REQ      = 2844        ,
	CLIGS_JEWELRY_STRENGTH_ACK      = 2845        ,
	CLIGS_JEWELRY_RESOLVE_REQ       = 2846        ,
	CLIGS_JEWELRY_RESOLVE_ACK       = 2847        ,
	CLIGS_PLAYER_INFO_SKILL_REQ     = 2848        ,
	CLIGS_PLAYER_INFO_SKILL_ACK     = 2849        ,
	CLIGS_PLAYER_INFO_EQUIP_REQ     = 2850        ,
	CLIGS_PLAYER_INFO_EQUIP_ACK     = 2851        ,
	CLIGS_OPEN_JEWELRY_STRENGTH_REQ  = 2852        ,
	CLIGS_OPEN_JEWELRY_STRENGTH_ACK  = 2853        ,
	CLIGS_JEWELRY_COMPARE_REQ       = 2854        ,
	CLIGS_JEWELRY_COMPARE_ACK       = 2855        ,
	CLIGS_JEWELRY_EXT_UPGRADE_REQ   = 2856        ,
	CLIGS_JEWELRY_EXT_UPGRADE_ACK   = 2857        ,
	CLIGS_OPEN_JEWELRY_RESOLVE_REQ  = 2858        ,
	CLIGS_OPEN_JEWELRY_RESOLVE_ACK  = 2859        ,
	CLIGS_COURAGE_GROUP_OVERTIME_NTF  = 2860        ,
	CLIGS_BATTLE_ACK3               = 2861        ,
	CLIGS_CHALLENGE_ACK3            = 2863        ,
	CLIGS_PLUNDER_ACK3              = 2865        ,
	CLIGS_PKBATTLE_ACK3             = 2867        ,
	CLIGS_RDCHALLENGE_ACK3          = 2869        ,
	CLIGS_HUNTING_BATTLE_ACK2       = 2873        ,
	CLIGS_COURAGE_PLAYER_START_ACK2  = 2875        ,
	CLIGS_COURAGE_LEADER_START_NTF2  = 2876        ,
	CLIGS_BEGIN_JIEBIAO_ACK3        = 2877        ,
	CLIGS_QUERY_BATTLE_RECORD_ACK3  = 2879        ,
	CLIGS_OPEN_GVG_ACTIVITY_REQ     = 2882        ,
	CLIGS_GVG_APPLAY_ACK            = 2883        ,
	CLIGS_GVG_MONEY_CHAOS_ACK       = 2885        ,
	CLIGS_16_TO_8_TO_4_ACK          = 2887        ,
	CLIGS_FINAL_WAR_ACK             = 2889        ,
	CLIGS_GVG_CHAMPION_ACK          = 2927        ,
	CLIGS_GVG_ERR_MSG_ACK           = 2929        ,
	CLIGS_OPEN_GVG_FORMATION_REQ    = 2890        ,
	CLIGS_OPEN_GVG_FORMATION_ACK    = 2891        ,
	CLIGS_OPEN_ALREAD_APPLAY_REQ    = 2892        ,
	CLIGS_OPEN_ALREAD_APPLAY_ACK    = 2893        ,
	CLIGS_GVG_LAST_RESULT_REQ       = 2894        ,
	CLIGS_GVG_LAST_RESULT_ACK       = 2895        ,
	CLIGS_GVG_OPEN_MY_GAMBLE_REQ    = 2896        ,
	CLIGS_GVG_OPEN_MY_GAMBLE_ACK    = 2897        ,
	CLIGS_GVG_OPEN_GAMBLE_REQ       = 2898        ,
	CLIGS_GVG_OPEN_GAMBLE_ACK       = 2899        ,
	CLIGS_OPEN_GVG_RULE_REQ         = 2900        ,
	CLIGS_OPEN_GVG_RULE_ACK         = 2901        ,
	CLIGS_GVG_GAMBLE_REQ            = 2902        ,
	CLIGS_GVG_GAMBLE_ACK            = 2903        ,
	CLIGS_OPEN_FACTION_MONEY_RANK_REQ  = 2904        ,
	CLIGS_OPEN_FACTION_MONEY_RANK_ACK  = 2905        ,
	CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF  = 2908        ,
	CLIGS_OPEN_GVG_LOG_REQ          = 2910        ,
	CLIGS_OPEN_GVG_LOG_ACK          = 2911        ,
	CLIGS_SEE_GVG_VIDEO_REQ         = 2912        ,
	CLIGS_SEE_GVG_VIDEO_ACK_v400    = 2913        ,
	CLIGS_END_GVG_VIDEO_REQ         = 2914        ,
	CLIGS_END_GVG_VIDEO_ACK_v400    = 2915        ,
	CLIGS_SHOW_GVG_MVP_REQ          = 2916        ,
	CLIGS_SHOW_GVG_MVP_ACK          = 2917        ,
	CLIGS_READ_FORMATION_PLAYER_TIP_REQ  = 2918        ,
	CLIGS_READ_FORMATION_PLAYER_TIP_ACK  = 2919        ,
	CLIGS_GVG_FACTION_EMBATTLE_REQ  = 2920        ,
	CLIGS_GVG_FACTION_EMBATTLE_ACK  = 2921        ,
	CLIGS_OPEN_GVG_GIFT_REQ         = 2922        ,
	CLIGS_OPEN_GVG_GIFT_ACK         = 2923        ,
	CLIGS_GET_GVG_GIFT_REQ          = 2924        ,
	CLIGS_GET_GVG_GIFT_ACK          = 2925        ,
	CLIGS_BATTLE_ACK4               = 2935        ,
	CLIGS_CHALLENGE_ACK4            = 2937        ,
	CLIGS_PLUNDER_ACK4              = 2939        ,
	CLIGS_PKBATTLE_ACK4             = 2941        ,
	CLIGS_RDCHALLENGE_ACK4          = 2943        ,
	CLIGS_HUNTING_BATTLE_ACK3       = 2947        ,
	CLIGS_COURAGE_PLAYER_START_ACK3  = 2949        ,
	CLIGS_COURAGE_LEADER_START_NTF3  = 2950        ,
	CLIGS_BEGIN_JIEBIAO_ACK4        = 2953        ,
	CLIGS_QUERY_BATTLE_RECORD_ACK4  = 2955        ,
	CLIGS_SELECT_GROUP_TYPE_REQ     = 3000        ,
	CLIGS_SELECT_GROUP_TYPE_ACK     = 3001        ,
	CLIGS_GVG_FACTION_APPLAY_REQ    = 3002        ,
	CLIGS_GVG_FACTION_APPLAY_ACK    = 3003        ,
	CLIGS_READ_BATTLE_LOG_REQ       = 3004        ,
	CLIGS_READ_BATTLE_LOG_ACK       = 3005        ,
	CLIGS_UNREAD_BATTLE_NTF         = 3006        ,
	CLIGS_OPEN_DEVOUR_SOUL_REQ      = 3008        ,
	CLIGS_OPEN_DEVOUR_SOUL_ACK      = 3009        ,
	CLIGS_DEVOUR_SOUL_REQ           = 3010        ,
	CLIGS_DEVOUR_SOUL_ACK           = 3011        ,
	CLIGS_OPEN_REFLASH_SOUL_REQ     = 3012        ,
	CLIGS_OPEN_REFLASH_SOUL_ACK     = 3013        ,
	CLIGS_REFLASH_SOUL_REQ          = 3014        ,
	CLIGS_REFLASH_SOUL_ACK          = 3015        ,
	CLIGS_SAVE_REFLASH_SOUL_REQ     = 3016        ,
	CLIGS_SAVE_REFLASH_SOUL_ACK     = 3017        ,
	CLIGS_SOULREP_INFO_REQ          = 3020        ,
	CLIGS_SOULREP_INFO_ACK          = 3021        ,
	CLIGS_PRODUCT_SOUL_REQ          = 3024        ,
	CLIGS_PRODUCT_SOUL_ACK          = 3025        ,
	CLIGS_HERO_EQUIP_SOUL_REQ       = 3026        ,
	CLIGS_HERO_EQUIP_SOUL_ACK       = 3027        ,
	CLIGS_HERO_UNDRESS_SOUL_REQ     = 3028        ,
	CLIGS_HERO_UNDRESS_SOUL_ACK     = 3029        ,
	CLIGS_SOULEXCHANGE_INFO_REQ     = 3030        ,
	CLIGS_SOULEXCHANGE_INFO_ACK     = 3031        ,
	CLIGS_EXCHANGE_SOUL_REQ         = 3032        ,
	CLIGS_EXCHANGE_SOUL_ACK         = 3033        ,
	CLIGS_PLAYER_INFO_SOUL_REQ      = 3034        ,
	CLIGS_PLAYER_INFO_SOUL_ACK      = 3035        ,
	CLIGS_HERO_REPLACE_SOUL_REQ     = 3036        ,
	CLIGS_HERO_REPLACE_SOUL_ACK     = 3037        ,
	CLIGS_OPEN_MY_MEDAL_REQ         = 3038        ,
	CLIGS_OPEN_MY_MEDAL_ACK         = 3039        ,
	CLIGS_MEDAL_NTF                 = 3040        ,
	CLIGS_OPEN_PLAYER_PANEL_ACK_OLD  = 3043        ,
	CLIGS_VIEW_FACTION_MEMBERS_REQ  = 3044        ,
	CLIGS_VIEW_FACTION_MEMBERS_ACK  = 3045        ,
	CLIGS_OPEN_OUT_BOUND_REQ        = 3046        ,
	CLIGS_OPEN_OUT_BOUND_ACK        = 3047        ,
	CLIGS_OPEN_OUT_BOUND_MAP_REQ    = 3048        ,
	CLIGS_OPEN_OUT_BOUND_MAP_ACK    = 3049        ,
	CLIGS_OUT_BOUND_BATTLE_REQ      = 3050        ,
	CLIGS_OUT_BOUND_BATTLE_ACK      = 3051        ,
	CLIGS_TEST_REQ                  = 3052        ,
	CLIGS_TEST_ACK                  = 3053        ,
	CLIGS_OPEN_BAG_ACK2             = 3055        ,
	CLIGS_OPEN_PLAYER_PANEL_ACK_v410  = 3059        ,
	CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2  = 3060        ,
	CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2  = 3061        ,
	CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2  = 3062        ,
	CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2  = 3063        ,
	CLIGS_BATTLE_ACK5               = 3065        ,
	CLIGS_CHALLENGE_ACK5            = 3067        ,
	CLIGS_PLUNDER_ACK5              = 3069        ,
	CLIGS_PKBATTLE_ACK5             = 3071        ,
	CLIGS_RDCHALLENGE_ACK5          = 3073        ,
	CLIGS_CHALLENGE_MYSELF_ACK5     = 3075        ,
	CLIGS_HUNTING_BATTLE_ACK5       = 3077        ,
	CLIGS_COURAGE_PLAYER_START_ACK5  = 3079        ,
	CLIGS_COURAGE_LEADER_START_NTF5  = 3080        ,
	CLIGS_BEGIN_JIEBIAO_ACK5        = 3083        ,
	CLIGS_QUERY_BATTLE_RECORD_ACK5  = 3085        ,
	CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5  = 3087        ,
	CLIGS_OPEN_STORE_REQ            = 3088        ,
	CLIGS_OPEN_STORE_ACK            = 3089        ,
	CLIGS_EXCHANGE_GOODS_REQ        = 3090        ,
	CLIGS_EXCHANGE_GOODS_ACK        = 3091        ,
	CLIGS_NOTICE_NEW_NTF            = 3092        ,
	CLIGS_OPEN_PET_RULE_REQ         = 3094        ,
	CLIGS_OPEN_PET_RULE_ACK         = 3095        ,
	CLIGS_PETREP_INFO_REQ           = 3100        ,
	CLIGS_PETREP_INFO_ACK           = 3101        ,
	CLIGS_PRODUCT_PET_REQ           = 3102        ,
	CLIGS_PRODUCT_PET_ACK           = 3103        ,
	CLIGS_OPEN_REFINEPET_REQ        = 3104        ,
	CLIGS_OPEN_REFINEPET_ACK        = 3105        ,
	CLIGS_REFINEPET_REQ             = 3106        ,
	CLIGS_REFINEPET_ACK             = 3107        ,
	CLIGS_OPEN_STAR_PANEL_REQ       = 3108        ,
	CLIGS_OPEN_STAR_PANEL_ACK       = 3109        ,
	CLIGS_UP_STAR_LV_REQ            = 3110        ,
	CLIGS_UP_STAR_LV_ACK            = 3111        ,
	CLIGS_OPEN_PET_PANEL_REQ        = 3112        ,
	CLIGS_OPEN_PET_PANEL_ACK        = 3113        ,
	CLIGS_OPEN_PETFEED_REQ          = 3114        ,
	CLIGS_OPEN_PETFEED_ACK          = 3115        ,
	CLIGS_FIRST_DRAW_REQ            = 3116        ,
	CLIGS_FIRST_DRAW_ACK            = 3117        ,
	CLIGS_RESET_DRAW_REQ            = 3118        ,
	CLIGS_RESET_DRAW_ACK            = 3119        ,
	CLIGS_CONFIRM_FEED_REQ          = 3120        ,
	CLIGS_CONFIRM_FEED_ACK          = 3121        ,
	CLIGS_MERGE_PET_REQ             = 3122        ,
	CLIGS_MERGE_PET_ACK             = 3123        ,
	CLIGS_OPEN_PET_STORE_REQ        = 3124        ,
	CLIGS_OPEN_PET_STORE_ACK        = 3125        ,
	CLIGS_BUY_PET_STORE_ITEM_REQ    = 3126        ,
	CLIGS_BUY_PET_STORE_ITEM_ACK    = 3127        ,
	CLIGS_OPEN_WASH_QUALITY_REQ     = 3128        ,
	CLIGS_OPEN_WASH_QUALITY_ACK     = 3129        ,
	CLIGS_WASH_QUALITY_REQ          = 3130        ,
	CLIGS_WASH_QUALITY_ACK          = 3131        ,
	CLIGS_CHANGE_PET_STATE_REQ      = 3132        ,
	CLIGS_CHANGE_PET_STATE_ACK      = 3133        ,
	CLIGS_OPEN_PET_INHERIT_REQ      = 3134        ,
	CLIGS_OPEN_PET_INHERIT_ACK      = 3135        ,
	CLIGS_PET_INHERIT_REQ           = 3136        ,
	CLIGS_PET_INHERIT_ACK           = 3137        ,
	CLIGS_EQUIP_ENCHANT_REQ         = 3138        ,
	CLIGS_EQUIP_ENCHANT_ACK         = 3139        ,
	CLIGS_OPEN_SMITHY_ACK_v410      = 3141        ,
	CLIGS_OPEN_RECRUIT_ACK_v410     = 3143        ,
	CLIGS_UPGRADE_HERO_REQ          = 3144        ,
	CLIGS_UPGRADE_HERO_ACK          = 3145        ,
	CLIGS_OPEN_EQUIP_MAKE_REQ       = 3146        ,
	CLIGS_OPEN_EQUIP_MAKE_ACK       = 3147        ,
	CLIGS_EQUIP_MAKE_REQ            = 3148        ,
	CLIGS_EQUIP_MAKE_ACK            = 3149        ,
	CLIGS_OPEN_FLY_REQ              = 3150        ,
	CLIGS_OPEN_FLY_ACK              = 3151        ,
	CLIGS_FLY_REQ                   = 3152        ,
	CLIGS_FLY_ACK                   = 3153        ,
	CLIGS_OPEN_PLAYERPET_PANEL_REQ  = 3154        ,
	CLIGS_OPEN_PLAYERPET_PANEL_ACK  = 3155        ,
	CLIGS_PLAYER_INFO_PET_REQ       = 3156        ,
	CLIGS_PLAYER_INFO_PET_ACK       = 3157        ,
	CLIGS_SEE_GVG_VIDEO_ACK_v410    = 3159        ,
	CLIGS_END_GVG_VIDEO_ACK_v410    = 3161        ,
	BOSSB_HURT_ACK2                 = 3163        ,
	ENTER_BOSSB_ACK2                = 3165        ,
	BOSSB_INFO_SYNC_NTF2            = 3166        ,
	BOSSB_OVER_NTF2                 = 3168        ,
	BOSSB_GET_LAST_BOSSB_INFO_ACK2  = 3171        ,
	CLIGS_REQUEST_ALL_PET_INFO_REQ  = 3172        ,
	CLIGS_REQUEST_ALL_PET_INFO_ACK  = 3173        ,
	CLIGS_JEWELRY_RESOLVE_ACK2      = 3175        ,
	CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ  = 3176        ,
	CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK  = 3177        ,
	CLIGS_SOUL_UPDATE_TYPE_REQ      = 3178        ,
	CLIGS_SOUL_UPDATE_TYPE_ACK      = 3179        ,
	CLIGS_OPEN_NEIDAN_REQ           = 3180        ,
	CLIGS_OPEN_NEIDAN_ACK           = 3181        ,
	CLIGS_DRESS_NEIDAN_REQ          = 3182        ,
	CLIGS_DRESS_NEIDAN_ACK          = 3183        ,
	CLIGS_UPDATA_NEIDAN_REQ         = 3184        ,
	CLIGS_UPDATA_NEIDAN_ACK         = 3185        ,
	CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ  = 3186        ,
	CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK  = 3187        ,
	CLIGS_NEIDAN_BATTLE_REQ         = 3188        ,
	CLIGS_NEIDAN_BATTLE_ACK         = 3189        ,
	CLIGS_RECV_NEIDAN_AWARD_REQ     = 3190        ,
	CLIGS_RECV_NEIDAN_AWARD_ACK     = 3191        ,
	CLIGS_SKIP_NEIDAN_BATTLE_REQ    = 3192        ,
	CLIGS_SKIP_NEIDAN_BATTLE_ACK    = 3193        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodeDT_POWER_CHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POWER_CHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_BUFF_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_BUFF_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_ACTION_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_ACTION_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_EFFECT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_EFFECT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EFFECT_RECOMMEND_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EFFECT_RECOMMEND_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_EFFECT_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_EFFECT_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ATTACK_RANG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_RANG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_DATA_STRENGTHEN_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_STRENGTHEN_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_XIANGQIAN_DES(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_XIANGQIAN_DES(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ALL_EQUIP_XIANGQIAN_DES(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ALL_EQUIP_XIANGQIAN_DES(void *pHost, CNetData* poNetData);
INT32 EncodeDT_XIANGQIAN_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_XIANGQIAN_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_MELT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MELT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOOD_MELT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOOD_MELT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_MELT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MELT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOOD_MELT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOOD_MELT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_DATA_CLI_v410(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_CLI_v410(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_EQUIP_DATA_LST_CLI_v410(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EQUIP_DATA_LST_CLI_v410(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEED_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEED_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ESTIMATE_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ESTIMATE_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ESTIMATE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ESTIMATE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_ESTIMATE_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_ESTIMATE_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_ESTIMATE_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ESTIMATE_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_COMPOSE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_COMPOSE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SEED_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SEED_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOODS_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOODS_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PHYSTRENGTH_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PHYSTRENGTH_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEW_EQUIP_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_EQUIP_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FUNC_COMMON_PROMPT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FUNC_COMMON_PROMPT(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FUNC_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FUNC_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OTHER_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OTHER_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RES_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RES_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RSYNC_RES_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RSYNC_RES_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_LIST_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_TASK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_TASK_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GIVEN_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GIVEN_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACCEPT_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCEPT_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ENCOURAGE_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENCOURAGE_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_INVALID_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INVALID_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_TASK_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_TASK_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_TASK_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_TASK_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACCEPT_TASK_COND_RECORD(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCEPT_TASK_COND_RECORD(void *pHost, CNetData* poNetData);
INT32 EncodeDT_TASK_COND_RECORD_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_COND_RECORD_LIST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EXPERIENCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXPERIENCE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BUILD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ONLINE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONLINE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DATA_AFTER_ONLINE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_ONLINE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 EncodeDT_VIP_NUM_FUNC_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_NUM_FUNC_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_VIP_LEVEL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_LEVEL_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_VIP_TAB_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_TAB_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UNREAD_BATTLE_LOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UNREAD_BATTLE_LOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RSYNC_RECV_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RSYNC_RECV_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ENTERGS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTERGS_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OPERATING_ACTIVITY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OPERATING_ACTIVITY_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ENTERGS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTERGS_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BAG_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_HERO_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_HERO_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ATTR_ENABLE_UPDATE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTR_ENABLE_UPDATE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_BATTLE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_BATTLE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_HERO_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_HERO_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACTIVI_SIDE_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVI_SIDE_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACTIVI_SIDE_PROMPT_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVI_SIDE_PROMPT_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ENTER_HOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_HOME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ENTER_HOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_HOME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BATTLE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DATA_AFTER_BATTLE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_BATTLE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RACE_CHALLENGE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_CHALLENGE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RACE_RANK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_RANK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ENTER_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PASS_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DATA_AFTER_PASS_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_PASS_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PASS_ENCOURAGE_BOX_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_BOX_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PASS_ENCOURAGE_BOX_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_BOX_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PASS_ENCOURAGE_BOX_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_BOX_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_UPGRADE_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPGRADE_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ENTER_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BURST_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BURST_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEXT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEXT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UNLOCK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UNLOCK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BATTLE_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BATTLE_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXIT_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXIT_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXIT_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXIT_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_TOWN_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TOWN_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_SCENE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_SCENE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CHAPTER_SCORE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHAPTER_SCORE(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACCUMULATED_SCORE_ENCOURAGE_BOX_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCUMULATED_SCORE_ENCOURAGE_BOX_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACCUMULATED_SCORE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCUMULATED_SCORE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_SCENE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_SCENE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_ENCHANT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_ENCHANT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_STRENGTHEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_STRENGTHEN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_STRENGTHEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_STRENGTHEN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SMITHY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SMITHY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BUY_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUY_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SMITHY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SMITHY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RECRUIT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECRUIT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_ATTR_ADD_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_ATTR_ADD_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECRUIT_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUIT_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RECRUIT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECRUIT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECRUIT_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECRUIT_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECRUIT_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECRUIT_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_VISIT_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VISIT_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_VISIT_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VISIT_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BATTLE_ATTR_EXT_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTR_EXT_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BATTLE_ATTR_EXT_LST_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTR_EXT_LST_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JEWELRY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_ITEM_DATA_UNOIN2(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_ITEM_DATA_UNOIN2(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_CLI3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_CLI3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_LIST_CLI3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_CLI3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_LIST_CLI4(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_CLI4(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_NUM_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_NUM_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_NUM_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_NUM_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_LIST_LESS_CLI3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_LESS_CLI3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RES_ITEM_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RES_ITEM_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BAG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BAG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BAG_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAG_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACCEPT_TASK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACCEPT_TASK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_INSTANCE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACCEPT_TASK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACCEPT_TASK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GIVEUP_TASK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVEUP_TASK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GIVEUP_TASK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVEUP_TASK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_TASK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_TASK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_TASK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_TASK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RACE_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RACE_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CHALLENGE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHALLENGE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RACE_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RACE_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ENEMY_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ENEMY_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ENEMY_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHALLENGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHALLENGE_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_RANK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RANK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_RANK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RANK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_RANK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RANK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RANK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RANK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_RANK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RANK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_RACE_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RACE_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RACE_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_RACE_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RACE_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SHOP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHOP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_SHOP(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_SHOP(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SHOP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHOP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELL_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELL_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELL_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELL_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DISBAND_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DISBAND_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DISBAND_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DISBAND_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_PANEL_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_PANEL_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_PANEL_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_PANEL_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REGISTER_USERNAME_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REGISTER_USERNAME_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_EMBATLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EMBATLE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_PLAYER_DATA_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_PLAYER_DATA_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MAKE_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MAKE_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MAKE_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MAKE_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DATA_AFTER_PASS_ENCOURAGE_BOX(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_PASS_ENCOURAGE_BOX(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_INCREASE_BAG_SIZE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_INCREASE_BAG_SIZE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_INCREASE_BAG_SIZE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_INCREASE_BAG_SIZE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ONHOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_UPGRADE_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPGRADE_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DATA_AFTER_ONHOOK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_ONHOOK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_RES_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_RES_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_RES_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_RES_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ONHOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_CHALLENGE_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CHALLENGE_CD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_CHALLENGE_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CHALLENGE_CD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SYNC_TIME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SYNC_TIME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SYNC_TIME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SYNC_TIME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_REGISTER_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_REGISTER_DSPNAME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_DSPNAME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_USE_GOODS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_USE_GOODS_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_USE_GOODS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_USE_GOODS_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_LOGIN_ENCOURAG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOGIN_ENCOURAG_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CAPTURE_WORK_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_WORK_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CAPTURE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLUNDER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLUNDER_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BECAPTURE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BECAPTURE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLUNDER_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLUNDER_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CAPTURE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CAPTURE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CAPTURE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CAPTURE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ENEMY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_ENEMY_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ENEMY_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_ENEMY_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ENEMY_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEL_ENEMY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_ENEMY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEL_ENEMY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_ENEMY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLUNDER_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLUNDER_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FREE_CAPTURE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_CAPTURE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FREE_CAPTURE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_CAPTURE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COLLECT_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COLLECT_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COLLECT_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COLLECT_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BLEED_CAPTURE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BLEED_CAPTURE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BLEED_CAPTURE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BLEED_CAPTURE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SET_WORK_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SET_WORK_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SET_WORK_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SET_WORK_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MONEY_TREE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONEY_TREE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ROCK_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ROCK_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ROCK_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ROCK_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GODWEAPON_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GODWEAPON_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FREE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FREE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_AWAKEN_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AWAKEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AWAKEN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_AWAKEN_GET_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_GET_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AWAKEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AWAKEN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DRESS_STUDY_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRESS_STUDY_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_STUDY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_STUDY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_STUDY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_STUDY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_TO_EXP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_TO_EXP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_TO_EXP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_TO_EXP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RACE_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RACE_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_PLUNDER_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_PLUNDER_CD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_PLUNDER_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_PLUNDER_CD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MAINTOWN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MAINTOWN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MAINTOWN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MAINTOWN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRIVE_AWAY_OWNER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRIVE_AWAY_OWNER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRIVE_AWAY_OWNER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRIVE_AWAY_OWNER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMPOSE_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMPOSE_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACTIVITY_TIME_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_TIME_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACTIVITY_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_LEFT_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_LEFT_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_LEFT_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_LEFT_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SMITHY_BUY_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SMITHY_BUY_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SMITHY_BUY_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SMITHY_BUY_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_STRENGTHEN_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_STRENGTHEN_CD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_STRENGTHEN_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_STRENGTHEN_CD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CROP_SEED_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_SEED_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CROP_FIELD_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_FIELD_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CROP_MORE_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_MORE_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_FIELD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_FIELD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_FIELD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_FIELD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GAIN_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GAIN_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GAIN_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GAIN_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EXPERIENCE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXPERIENCE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOLD_EXPERIENCE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOLD_EXPERIENCE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_USER_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_USER_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_USER_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_USER_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SCIENCE_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SCIENCE_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SCIENCE_ALREADY_OPEN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_ALREADY_OPEN_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SCIENCE_WILL_OPEN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_WILL_OPEN_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SCIENCE_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SCIENCE_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPDATE_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPDATE_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MELT_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MELT_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MELT_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MELT_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MELT_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MELT_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MELT_GOOD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MELT_GOOD_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MELT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MELT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MELT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MELT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPDATE_ATTR_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_ATTR_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UPDATED_ATTR_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPDATED_ATTR_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPDATE_ATTR_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_ATTR_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFRESH_ELITE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_ELITE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFRESH_ELITE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_ELITE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ONHOOK_ELITE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_ELITE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ONHOOK_ELITE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_ELITE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ORDER_ID_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ORDER_ID_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ORDER_ID_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ORDER_ID_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_RESULT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_RESULT(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHECK_APPSTORE_ORDER_ID_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHECK_APPSTORE_ORDER_ID_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHECK_APPSTORE_ORDER_ID_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHECK_APPSTORE_ORDER_ID_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEED_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEED_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEED_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEED_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeCHAT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeCHAT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CHAT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CHAT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CHAT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CHAT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHAT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHAT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHAT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHAT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHAT_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHAT_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CROSS_DAY_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROSS_DAY_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPNE_ACTIVITY_CENTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPNE_ACTIVITY_CENTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPNE_ACTIVITY_CENTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPNE_ACTIVITY_CENTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_PROMPT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_PROMPT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_PROMPT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_PROMPT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPNE_EAT_BREAD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPNE_EAT_BREAD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPNE_EAT_BREAD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPNE_EAT_BREAD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OBTAIN_PHYSTRENGTHEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OBTAIN_PHYSTRENGTHEN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OBTAIN_PHYSTRENGTHEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OBTAIN_PHYSTRENGTHEN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_EAT_BREAD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_EAT_BREAD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_EAT_BREAD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_EAT_BREAD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PAOSHANG_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PAOSHANG_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BIAO_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BIAO_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeBIAO_OPERATE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeBIAO_OPERATE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PAOSHANG_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PAOSHANG_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_YABIAO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_YABIAO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_YABIAO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_YABIAO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FLUSH_BIAO_QUALITY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FLUSH_BIAO_QUALITY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FLUSH_BIAO_QUALITY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FLUSH_BIAO_QUALITY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGIN_YABIAO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGIN_YABIAO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGIN_YABIAO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGIN_YABIAO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JIEBIAO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JIEBIAO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_YABIAO_PLAYER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_PLAYER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_YABIAO_PLAYER_INFO_FACTION_NAME(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_PLAYER_INFO_FACTION_NAME(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JIEBIAO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JIEBIAO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGIN_JIEBIAO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGIN_JIEBIAO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGIN_JIEBIAO_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGIN_JIEBIAO_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLEAR_JIEBIAO_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLEAR_JIEBIAO_CD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLEAR_JIEBIAO_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLEAR_JIEBIAO_CD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BE_JIEBIAO_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BE_JIEBIAO_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_YABIAO_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_YABIAO_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_YABIAO_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_YABIAO_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_YABIAO_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_YABIAO_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_YABIAO_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_YABIAO_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_YABIAO_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_YABIAO_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_BATTLE_RECORD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_BATTLE_RECORD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_BATTLE_RECORD_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_BATTLE_RECORD_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLIMB_TOWER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLIMB_TOWER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CLIMB_TOWER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CLIMB_TOWER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CLIMB_TOWER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CLIMB_TOWER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLIMB_TOWER_RESET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLIMB_TOWER_RESET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLIMB_TOWER_RESET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLIMB_TOWER_RESET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLIMB_TOWER_ONHOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLIMB_TOWER_ONHOOK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLIMB_TOWER_ONHOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLIMB_TOWER_ONHOOK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_CLIMB_TOWER_RESET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_CLIMB_TOWER_RESET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_CLIMB_TOWER_RESET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_CLIMB_TOWER_RESET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JINGJIE_PER_LEVEL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JINGJIE_PER_LEVEL_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JINGJIE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JINGJIE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_JINGJIE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_JINGJIE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_JINGJIE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_JINGJIE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GEN_GAS_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GEN_GAS_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GEN_GAS_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GEN_GAS_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GEN_GAS_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GEN_GAS_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GEN_GAS_BALL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GEN_GAS_BALL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GEN_GAS_BALL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GEN_GAS_BALL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UP_GAS_BALL_LEVEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UP_GAS_BALL_LEVEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UP_GAS_BALL_LEVEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UP_GAS_BALL_LEVEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COLLECT_GAS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COLLECT_GAS_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COLLECT_GAS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COLLECT_GAS_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ATTACK_RANG_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_RANG_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EFFECT_DATA_LST2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EFFECT_DATA_LST2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_TAB_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_TAB_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_SKILL_ACTION_LEVEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELECT_SKILL_ACTION_EFFECT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JINGJIE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JINGJIE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JINGJIE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JINGJIE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SKILL_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SKILL_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SKILL_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SKILL_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BLUE_TO_PURPLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BLUE_TO_PURPLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BLUE_TO_PURPLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BLUE_TO_PURPLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_VIP_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_VIP_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BUY_GOLD_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUY_GOLD_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BUY_GOLD_INFO_EX(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUY_GOLD_INFO_EX(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BUY_GOLD_TXT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUY_GOLD_TXT(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_VIP_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_VIP_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_XIANGQIAN_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_XIANGQIAN_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_XIANGQIAN_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_XIANGQIAN_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_XIANGQIAN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_XIANGQIAN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_XIANGQIAN_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_XIANGQIAN_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_XIANGQIAN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_XIANGQIAN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REMOVE_XIANGQIAN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REMOVE_XIANGQIAN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REMOVE_XIANGQIAN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REMOVE_XIANGQIAN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESET_ELITE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESET_ELITE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ELITE_INSTANCE_VIP_EXT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITE_INSTANCE_VIP_EXT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESET_ELITE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESET_ELITE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ELITE_INSTANCE_ON_HOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ELITE_INSTANCE_ON_HOOK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ELITE_INSTANCE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITE_INSTANCE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ELITE_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITE_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ELITE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ELITE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ELITE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ELITE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_ID(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_ID(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUICK_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUICK_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUICK_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUICK_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PKBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PKBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PKBATTLE_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PKBATTLE_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RESOURCES_PROMPT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RESOURCES_PROMPT(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RESOURCES_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RESOURCES_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESOURCES_PROMPT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESOURCES_PROMPT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESOURCES_PROMPT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESOURCES_PROMPT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_PLAYER_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_PLAYER_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_MY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_MY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HURT_ENC_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HURT_ENC_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_ENTER_BOSSB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_ENTER_BOSSB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_ENTER_BOSSB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_ENTER_BOSSB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_ENTER_BOSSB_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_ENTER_BOSSB_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_LEAVE_BOSSB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_LEAVE_BOSSB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_LEAVE_BOSSB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_LEAVE_BOSSB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_MOVE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_MOVE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_MOVE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_MOVE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_HURT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_HURT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_HURT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_HURT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_HURT_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_HURT_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_POS_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_POS_NTF(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_POS(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_POS(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_HURT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_HURT(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_INFO_SYNC_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_INFO_SYNC_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_INFO_SYNC_NTF2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_INFO_SYNC_NTF2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_OVER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_OVER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSSB_OVER_INFO2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSSB_OVER_INFO2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_OVER_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_OVER_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_OVER_NTF2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_OVER_NTF2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_OPEN_INSPIRE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_OPEN_INSPIRE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_INSPIRE_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSPIRE_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_OPEN_INSPIRE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_OPEN_INSPIRE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_INSPIRE_POWER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_INSPIRE_POWER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_INSPIRE_POWER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_INSPIRE_POWER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_RELIVE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_RELIVE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_RELIVE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_RELIVE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_GET_LAST_BOSSB_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_GET_LAST_BOSSB_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_GET_LAST_BOSSB_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_GET_LAST_BOSSB_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_BOSSB_GET_LAST_BOSSB_INFO_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_BOSSB_GET_LAST_BOSSB_INFO_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_OPEN_RECHARGE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_RECHARGE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_RECHARGE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RECHARGE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_OPEN_SCORE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_SCORE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_SCORE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_SCORE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_RANDOM_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RANDOM_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_RANDOM_DSPNAME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RANDOM_DSPNAME_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BOSS_BATTLE_PLAYER_BATTLE_LOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BOSSB_BATTLE_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_UPGRADE_LEVEL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPGRADE_LEVEL(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXPERIENCE_TRANSFER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXPERIENCE_TRANSFER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXPERIENCE_TRANSFER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXPERIENCE_TRANSFER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RDCHALLENGE_POINT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RDCHALLENGE_POINT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RDCHALLENGE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RDCHALLENGE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RDC_ENC_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RDC_ENC_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RDC_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RDC_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RDC_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RDC_TAB_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RDCHALLENGE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RDCHALLENGE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RDCHALLENGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RDCHALLENGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RDCHALLENGE_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RDCHALLENGE_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_RDCHALLENGE_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_RDCHALLENGE_CD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_RDCHALLENGE_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_RDCHALLENGE_CD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_WORSHIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WORSHIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_WORSHIP_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WORSHIP_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_WORSHIP_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_WORSHIP_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_WORSHIP_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_WORSHIP_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_WORSHIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_WORSHIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_WORSHIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_WORSHIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACTIVITY_NOTIFY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACTIVITY_NOTIFY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACTIVITY_NOTIFY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACTIVITY_NOTIFY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DOGFECES_BUILD_TIP(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DOGFECES_BUILD_TIP(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DOGFECES_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DOGFECES_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DOGFECES_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DOGFECES_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_CENTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_CENTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_CENTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_CENTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACTIVITY_ENCOURAGE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_ENCOURAGE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ACTIVITY_ENCOURAGE_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVITY_ENCOURAGE_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GEM_MAKER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GEM_MAKER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GEM_MAKER_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GEM_MAKER_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GEM_MAKER_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GEM_MAKER_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GEM_MAKER_TAB_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_RATING_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RATING_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_RATING_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RATING_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_STUDY_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_AWAKEN_TAB_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_TAB_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_AWAKEN_STUDY_EXCHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_STUDY_EXCHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_EXCHANGE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_STUDY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_STUDY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_STUDY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_STUDY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COMPOSE_EQUIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COMPOSE_EQUIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_COMPOSE_LEVEL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_COMPOSE_LEVEL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EQUIP_COMPOSE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_COMPOSE_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_COMPOSE_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_COMPOSE_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_COMPOSE_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_DATA_TO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_DATA_TO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_BASE_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BASE_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OPEN_FACTION_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OPEN_FACTION_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_PLAYER_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_PLAYER_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_BASE_OWNER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BASE_OWNER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_OWNER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_OWNER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_OPEN_FACTION_CONDITION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_OPEN_FACTION_CONDITION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodePKT_CLIGS_APPLY_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_APPLY_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_APPLY_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_APPLY_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CANCEL_APPLY_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CANCEL_APPLY_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CANCEL_APPLY_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CANCEL_APPLY_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CREATE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CREATE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CREATE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CREATE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEARCH_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEARCH_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEARCH_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEARCH_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_OWNER_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_OWNER_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_PLAYER_AUDIT_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_AUDIT_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_PLAYER_AUDIT_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_AUDIT_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_OWNER_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_OWNER_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_LIST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_LIST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DOORS_TRIBUTE_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DOORS_TRIBUTE_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DOORS_TRIBUTE_TODAY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DOORS_TRIBUTE_TODAY_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DOORS_TRIBUTE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DOORS_TRIBUTE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DOORS_TRIBUTE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DOORS_TRIBUTE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DOORS_TRIBUTE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_KICKED_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_KICKED_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_KICKED_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_KICKED_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JOB_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JOB_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JOB_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JOB_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SET_NOTICE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SET_NOTICE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SET_NOTICE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SET_NOTICE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DISSOLVE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DISSOLVE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DISSOLVE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DISSOLVE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_AUDIT_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_AUDIT_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AUDIT_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AUDIT_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AUDIT_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AUDIT_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_APPLY_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_APPLY_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_APPLY_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_APPLY_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RANK_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RANK_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RANK_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RANK_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AUDIT_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AUDIT_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AUDIT_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AUDIT_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_LOG_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_LOG_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_LOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_LOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_LOG_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_LOG_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_LOG_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_LOG_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GATHER_SCIENCE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GATHER_SCIENCE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GATHER_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GATHER_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GATHER_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GATHER_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GATHER_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GATHER_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GATHER_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GATHER_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_NOTICE_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_NOTICE_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_NOTICE_NEW_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_NOTICE_NEW_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACTIVITY_ENC_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACTIVITY_ENC_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_TAB_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_TAB_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_TAB_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_TAB_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AWAKEN_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AWAKEN_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_AWAKEN_GET_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_GET_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AWAKEN_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AWAKEN_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_STUDY_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_STUDY_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DRESS_STUDY_TAB_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRESS_STUDY_TAB_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DRESS_STUDY_TAB_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_STUDY_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_STUDY_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_STUDY_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_STUDY_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_TO_EXP_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_TO_EXP_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_TO_EXP_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_TO_EXP_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_UPGRADE_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_UPGRADE_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_STUDY_UPGRADE_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_UPGRADE_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BEGBLUE_PLAYER_RES_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BEGBLUE_PLAYER_RES_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BEGBLUE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BEGBLUE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_IMPROVELUCK_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_IMPROVELUCK_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BEGBLUE_RES_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BEGBLUE_RES_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BEGBLUE_RESULT_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BEGBLUE_RESULT_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_BLUE_PAVILION_UNION_DATA_CLI(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_BLUE_PAVILION_UNION_DATA_CLI(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_BLUE_PAVILION_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BLUE_PAVILION_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BLUE_ENCOURAGEINFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BLUE_ENCOURAGEINFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BLUE_ENCOURAGEINFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BLUE_ENCOURAGEINFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BLUE_PAVILION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BLUE_PAVILION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BLUE_PAVILION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BLUE_PAVILION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGBLUE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGBLUE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGBLUE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGBLUE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_IMPROVELUCK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_IMPROVELUCK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_IMPROVELUCK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_IMPROVELUCK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMFIRM_BEGBLUE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMFIRM_BEGBLUE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMFIRM_BEGBLUE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMFIRM_BEGBLUE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_OPENLIGHT_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_OPENLIGHT_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_OPENLIGHT_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_OPENLIGHT_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPENLIGHT_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPENLIGHT_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPENLIGHT_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPENLIGHT_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_CAREER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_CAREER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_CAREER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_CAREER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHALLENGE_MYSELF_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_MYSELF_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_ITEM_EXCHANGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ITEM_EXCHANGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeITEM_NUM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeITEM_NUM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeITEM_EXCHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeITEM_EXCHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ITEM_EXCHANGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ITEM_EXCHANGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ITEM_EXCHANGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ITEM_EXCHANGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ITEM_EXCHANGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_WANTED_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WANTED_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_WANTED_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_WANTED_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BIGREWARD_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BIGREWARD_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BIGREWARD_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BIGREWARD_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLUE_TASK_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLUE_TASK_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLUE_TASK_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLUE_TASK_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLUE_TASK_KILL_MONSTER_NAVI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLUE_TASK_KILL_MONSTER_NAVI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLUE_TASK_ITEM_BOX_NAVI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLUE_TASK_ITEM_BOX_NAVI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLUE_TASK_FORTUNE_GRID_NAVI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLUE_TASK_FORTUNE_GRID_NAVI(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_CLUE_TASK_NAVI_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_CLUE_TASK_NAVI_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_CLUE_TASK_NAVI_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLUE_TASK_NAVI_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DICE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DICE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_COLLECT_CLUE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_COLLECT_CLUE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_COLLECT_CLUE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_COLLECT_CLUE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CLUE_GRID_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CLUE_GRID_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CLUE_GRID_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CLUE_GRID_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SHAKE_DICE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SHAKE_DICE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SHAKE_DICE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SHAKE_DICE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFRESH_DICE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_DICE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFRESH_DICE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_DICE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMFIRM_DICE_POINT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMFIRM_DICE_POINT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COMFIRM_DICE_POINT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMFIRM_DICE_POINT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_RES_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_RES_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPERATING_ACTIVITY_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPERATING_ACTIVITY_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPERATING_ACTIVITY_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPERATING_ACTIVITY_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FRIEND_SYS_PLAYER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIEND_SYS_PLAYER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FRIEND_SYS_PLAYER_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIEND_SYS_PLAYER_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FRIEND_SYS_PLAYER_INFO2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIEND_SYS_PLAYER_INFO2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FRIEND_SYS_PLAYER_LIST_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIEND_SYS_PLAYER_LIST_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FRIEND_SYS_PLAYER_LIST_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEL_FRIEND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_FRIEND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEL_FRIEND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_FRIEND_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEARCH_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEARCH_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEARCH_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEARCH_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEARCH_PLAYER_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEARCH_PLAYER_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEARCH_PLAYER_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEARCH_PLAYER_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FRIEND_SYS_PLAYER_GENERAL_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIEND_SYS_PLAYER_GENERAL_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_VIEW_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VIEW_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_ATTR_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_ATTR_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SPECIAL_EFFECT_DESC(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SPECIAL_EFFECT_DESC(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SPECIAL_EFFECT_LST_DESC(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SPECIAL_EFFECT_LST_DESC(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SPECIAL_EFFECT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SPECIAL_EFFECT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_ATTR_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_ATTR_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_POTENCY_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_POTENCY_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_POTENCY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_POTENCY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_SOUL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_SOUL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_SOUL_POTENCY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_SOUL_POTENCY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_LST_SOUL_POTENCY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_LST_SOUL_POTENCY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ATTR_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTR_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ATTR_BASE_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTR_BASE_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MEDAL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MEDAL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_VIEW_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VIEW_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ADD_FRIEND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ADD_FRIEND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ADD_FRIEND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ADD_FRIEND_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SEND_FLOWER_PROP_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SEND_FLOWER_PROP_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SEND_FLOWER_PROP_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SEND_FLOWER_PROP_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEND_FLOWER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEND_FLOWER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEND_FLOWER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEND_FLOWER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECV_FLOWER_LOG(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_LOG(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECV_FLOWER_LOG_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_LOG_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FLOWER_BY_PLAYERID_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FLOWER_BY_PLAYERID_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FLOWER_BY_PLAYERID_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FLOWER_BY_PLAYERID_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FLOWER_RANKING_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FLOWER_RANKING_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FLOWER_RANKING_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FLOWER_RANKING_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FLOWER_RANKING_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FLOWER_RANKING_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_FLOWER_RANKING_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_FLOWER_RANKING_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PRIVATE_MSG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PRIVATE_MSG_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PRIVATE_MSG_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PRIVATE_MSG_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_PRIVATE_MSG_LOG_LIST_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEND_PRIVATE_MSG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEND_PRIVATE_MSG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEND_PRIVATE_MSG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEND_PRIVATE_MSG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEL_PRIVATE_MSG_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_PRIVATE_MSG_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEL_PRIVATE_MSG_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_PRIVATE_MSG_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ADD_TO_BLACKLIST_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ADD_TO_BLACKLIST_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ADD_TO_BLACKLIST_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ADD_TO_BLACKLIST_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MOVE_FROM_BLACKLIST_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MOVE_FROM_BLACKLIST_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MOVE_FROM_BLACKLIST_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MOVE_FROM_BLACKLIST_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ONLINE_PRIVATE_MSG_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONLINE_PRIVATE_MSG_NTF(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OFFLINE_MSG_SENDER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OFFLINE_MSG_SENDER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SEND_OFFLINE_MSG_PLAYER_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SEND_OFFLINE_MSG_PLAYER_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_SEND_OFFLINE_MSG_PLAYER_LIST_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_READ_OFFLINE_MSG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_READ_OFFLINE_MSG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_READ_OFFLINE_MSG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_READ_OFFLINE_MSG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RAREITEM_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RAREITEM_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RAREITEM_INFO_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RAREITEM_INFO_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RAREITEM_ROOM_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RAREITEM_ROOM_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RAREITEMROOM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RAREITEMROOM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RAREITEMROOM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RAREITEMROOM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_RAREITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_RAREITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_RAREITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_RAREITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_UPGRADERAREITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPGRADERAREITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UPGRADE_RAREITEM_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADE_RAREITEM_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UPGRADE_MSG_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADE_MSG_LIST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UPGRADE_REQUIRE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADE_REQUIRE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_UPGRADERAREITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPGRADERAREITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_RAREITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_RAREITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_AFTER_UPGRADE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AFTER_UPGRADE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_RAREITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_RAREITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GYMNASIUM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GYMNASIUM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GYMNASIUM_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GYMNASIUM_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GYMNASIUM_CLI_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GYMNASIUM_CLI_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_CLI_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_CLI_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GYMNASIUM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GYMNASIUM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GYMNASIUM_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GYMNASIUM_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GYMNASIUM_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SHADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SHADE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SHADE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HUNTING_POT_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_POT_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HUNTING_POT_INFO2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_POT_INFO2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_REWARD_SINGLE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_REWARD_SINGLE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HUNTING_SCHEDULE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_SCHEDULE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HUNTING_SCHEDULE_INFO2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_SCHEDULE_INFO2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HUNTING_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SHADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SHADE_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHADE_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SHADE_UPGRADE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SHADE_UPGRADE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SHADE_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHADE_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SHADE_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SHADE_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SHADE_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SHADE_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_REWARD_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_REWARD_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MONSTER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONSTER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GOLDMODE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GOLDMODE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GOLDMODE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GOLDMODE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_HUNTING_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HUNTING_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_REWARD_INFO_ALL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_REWARD_INFO_ALL(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CHANGE_MONSTER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHANGE_MONSTER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FIND_MONSTER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FIND_MONSTER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HUNTING_OTHER_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HUNTING_OTHER_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_HUNTING_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HUNTING_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FIND_MONSTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FIND_MONSTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FIND_MONSTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FIND_MONSTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HUNTING_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HUNTING_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HUNTING_BATTLE_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HUNTING_BATTLE_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_SCHEDEULE_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_SCHEDEULE_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HOT_SPRING_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HOT_SPRING_PLAYER_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_PLAYER_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HOT_SPRING_SELF_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_SELF_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DIDNOT_GIVE_WINE_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DIDNOT_GIVE_WINE_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_DIDNOT_DRINGK_WINE_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DIDNOT_DRINGK_WINE_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HOTSPRING_ACTIVITY_TIME_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOTSPRING_ACTIVITY_TIME_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HOT_SPRING_EXPERIENCE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HOT_SPRING_EXPERIENCE(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELECT_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELECT_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELECT_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELECT_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRINK_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRINK_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRINK_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRINK_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRINK_WINE_MOVE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRINK_WINE_MOVE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRINK_WINE_MOVE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRINK_WINE_MOVE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HOT_SPRING_POS_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HOT_SPRING_POS_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_OTHER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_OTHER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_OTHER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_OTHER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GIVE_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVE_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GIVE_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVE_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLICK_SELECT_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLICK_SELECT_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLICK_SELECT_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLICK_SELECT_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SURE_GIVE_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SURE_GIVE_WINE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SURE_GIVE_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SURE_GIVE_WINE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLOSED_MONSTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLOSED_MONSTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLOSED_MONSTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLOSED_MONSTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_PLAYER_CHANGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_PLAYER_CHANGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_PLAYER_CHANGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_PLAYER_CHANGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GIVE_WINE_ACTIVITY_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVE_WINE_ACTIVITY_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_LEAVE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_LEAVE_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_LEAVE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_LEAVE_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_UPGRADE_ALL_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_UPGRADE_ALL_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_BUILD_LEVEL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_BUILD_LEVEL(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_SYNC_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_SYNC_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_MASTER_DETAIL_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MASTER_DETAIL_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MASTER_EXP_BOOK_DETAIL_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MASTER_EXP_BOOK_DETAIL_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MASTER_CHEAT_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MASTER_CHEAT_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MASTER_EXP_BOOK_PANEL_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MASTER_EXP_BOOK_PANEL_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MASTER_LEVEL_UP(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MASTER_LEVEL_UP(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MASTER_LEVEL_UP_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MASTER_LEVEL_UP_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EQUIP_MASTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EQUIP_MASTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EQUIP_MASTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EQUIP_MASTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACTIVATE_MASTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACTIVATE_MASTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACTIVATE_MASTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACTIVATE_MASTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BREAK_MASTER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BREAK_MASTER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BREAK_MASTER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BREAK_MASTER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_MASTER_BOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_MASTER_BOOK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_MASTER_BOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_MASTER_BOOK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_WIPE_MASTER_BOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_WIPE_MASTER_BOOK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_WIPE_MASTER_BOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_WIPE_MASTER_BOOK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MASTER_CHEAT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MASTER_CHEAT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MASTER_CHEAT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MASTER_CHEAT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CONFIRM_MASTER_BOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CONFIRM_MASTER_BOOK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CONFIRM_MASTER_BOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CONFIRM_MASTER_BOOK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BAD_REWARD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAD_REWARD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_BAD_REWARD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAD_REWARD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_BAD_REWARD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_BAD_REWARD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_BAD_REWARD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_BAD_REWARD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_GROUP_LEADER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_LEADER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_GROUP_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_GROUP_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_DATA_CLI_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_COURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_COURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeUnDT_COURAGE_GROUP_UNION_DATA_CLI(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_COURAGE_GROUP_UNION_DATA_CLI(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_COURAGE_ALL_GROUP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_ALL_GROUP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_COURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_COURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_CHALLENGE_NUM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_CHALLENGE_NUM_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_CHALLENGE_NUM_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_CHALLENGE_NUM_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_OPEN_CREATE_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_CREATE_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_CREATE_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_CREATE_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_CREATE_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_GROUP_HERO_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_HERO_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_OPERATE_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_OPERATE_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_OPERATE_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_OPERATE_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_CONFIRM_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_CONFIRM_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_CONFIRM_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_CONFIRM_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_JOIN_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_JOIN_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_JOIN_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_JOIN_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_FIRE_GROUP_MEMBER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_BUY_PRACTISE_TIMES_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_READY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_READY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_READY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_READY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_AWARD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_AWARD_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_PLAYERID_HEROID_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYERID_HEROID_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_START_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_START_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_PLAYER_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_PLAYER_BATTLE_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_BATTLE_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_GROUP_PLAYER_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_GROUP_PLAYER_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_JEWELRY_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_JEWELRY_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_START_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_START_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_LEADER_START_NTF2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_LEADER_START_NTF2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_JOIN_GROUP_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_JOIN_GROUP_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_QUIT_GROUP_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_QUIT_GROUP_NTF(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_PLAYER_HERO_NTF_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_HERO_NTF_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_OPERATE_HERO_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_OPERATE_HERO_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_READY_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_READY_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_FIRED_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_FIRED_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_LEAVE_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_LEAVE_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_LEAVE_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_LEAVE_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_COURAGE_SHOP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_COURAGE_SHOP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_COURAGE_SHOP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_COURAGE_SHOP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_FACTION_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_FACTION_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_FACTION_READ_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_FACTION_READ_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_FACTION_READ_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_FACTION_READ_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FIND_DRINK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FIND_DRINK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FIND_DRINK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FIND_DRINK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_BATTLE_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_BATTLE_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_BUILD_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_BUILD_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_BUILD_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_BUILD_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GROUP_DISMISS_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GROUP_DISMISS_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HOT_SPRING_REWARD_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HOT_SPRING_REWARD_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GROUP_REFRESH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GROUP_REFRESH_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GROUP_REFRESH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GROUP_REFRESH_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_ENTER_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_ENTER_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_ENTER_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_ENTER_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_COURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_COURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_COURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_COURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HOT_SPRING_OVER_REWARD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HOT_SPRING_OVER_REWARD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HOT_SPRING_OVER_REWARD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HOT_SPRING_OVER_REWARD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GOLD_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GOLD_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HUNTING_ITEGRAL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HUNTING_ITEGRAL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HUNTING_ITEGRAL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HUNTING_ITEGRAL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACTIVITY_END_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACTIVITY_END_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PROMPT_IGNORE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PROMPT_IGNORE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PROMPT_IGNORE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PROMPT_IGNORE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GROUP_REFRESH_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GROUP_REFRESH_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HOME_BUILD_PROMPT_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HOME_BUILD_PROMPT_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_LEAVE_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_LEAVE_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_LEAVE_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_LEAVE_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_OPERATE_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_OPERATE_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_PROMPT_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_PROMPT_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GET_AWARD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GET_AWARD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GET_AWARD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GET_AWARD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GET_BATTLE_RESULT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GET_BATTLE_RESULT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GET_BATTLE_RESULT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DOORSTRIBUTE_SYNC_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DOORSTRIBUTE_SYNC_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AUDIT_FACTION_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AUDIT_FACTION_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AUDIT_FACTION_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AUDIT_FACTION_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CROP_FIELD_INFO_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_FIELD_INFO_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CROP_MORE_INFO_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_MORE_INFO_DATA2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_FIELD_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_FIELD_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CROP_FIELD_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_FIELD_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GAIN_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GAIN_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GAIN_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GAIN_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CROP_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CLR_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CROP_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_CROP_FIELD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_CROP_FIELD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_CROP_FIELD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_CROP_FIELD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AUDIT_ALL_REFUSE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AUDIT_ALL_REFUSE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_AUDIT_ALL_REFUSE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AUDIT_ALL_REFUSE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_PLAYER_AUDIT_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_AUDIT_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_PLAYER_AUDIT_CLI_LST2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_PLAYER_AUDIT_CLI_LST2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AUDIT_FACTION_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AUDIT_FACTION_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_AUDIT_FACTION_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AUDIT_FACTION_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_VIP_GIFT_EACH_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_GIFT_EACH_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_VIP_GIFT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VIP_GIFT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_VIP_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_VIP_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_VIP_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_VIP_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_VIP_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_VIP_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_VIP_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_VIP_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECV_FLOWER_LOG_CLI_EX(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_LOG_CLI_EX(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECV_FLOWER_LOG_LIST_CLI_EX(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECV_FLOWER_LOG_LIST_CLI_EX(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RECV_FLOWER_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECV_FLOWER_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RECV_FLOWER_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECV_FLOWER_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACCEPT_FLOWER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACCEPT_FLOWER_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_ACCEPT_FLOWER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACCEPT_FLOWER_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FRIENDS_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FRIENDS_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_FLOWER(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_FLOWER(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_RAREITEM_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_RAREITEM_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_RAREITEM_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_RAREITEM_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEARN_GYMNASIUM_SKILL_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEND_FLOWER_EX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEND_FLOWER_EX_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEND_FLOWER_EX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEND_FLOWER_EX_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_SELF_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_SELF_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_MANAGER_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_MANAGER_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_MANAGER_INFO_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_MANAGER_INFO_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_POWER_INFO_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_POWER_INFO_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_PLAYERS_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_PLAYERS_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FACTION_PLAYERS_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FACTION_PLAYERS_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_VIEW_FACTION_MEMBERS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VIEW_FACTION_MEMBERS_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_VIEW_FACTION_MEMBERS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VIEW_FACTION_MEMBERS_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CHANGE_FACTION_ICON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CHANGE_FACTION_ICON_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_CHANGE_FACTION_ICON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CHANGE_FACTION_ICON_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_FACTION_ICON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_FACTION_ICON_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_FACTION_ICON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_FACTION_ICON_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FIND_BACK_DOORSTRIBUTE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FIND_BACK_DOORSTRIBUTE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FIND_BACK_DOORSTRIBUTE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FIND_BACK_DOORSTRIBUTE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FIND_BACK_DOORSTRIBUTE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_COURAGE_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_COURAGE_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_LEAVE_COURAGE_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEAVE_COURAGE_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_RANDOM_JOIN_GROUP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EMBATTLE_REQ2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EMBATTLE_REQ2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FORMATION_DATA_LEVEL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_DATA_LEVEL(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEW_FORMATION_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_FORMATION_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEW_FORMATION_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_FORMATION_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEW_HERO_EMBATLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_HERO_EMBATLE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EMBATTLE_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EMBATTLE_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FORMATION_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FORMATION_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FORMATION_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FORMATION_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_FORMATION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_FORMATION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_FORMATION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_FORMATION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_REGISTER_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_FACTION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLILS_REGISTER_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_FACTION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_FORMATION_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_FORMATION_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_FORMATION_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_FORMATION_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_BLUE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_BLUE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_BLUE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_BLUE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_EXPRIENCE_HOT_SPRING_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESOURCE_SYNC_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESOURCE_SYNC_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RESOLVE_TRIGRAM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RESOLVE_TRIGRAM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RESOLVE_TRIGRAM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RESOLVE_TRIGRAM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESOLVE_TRIGRAM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESOLVE_TRIGRAM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESOLVE_TRIGRAM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESOLVE_TRIGRAM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JEWELRY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_JEWELRY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_JEWELRY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_DATA_CLI_v410(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_CLI_v410(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_DATA_CLI2_OLD(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_CLI2_OLD(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JEWELRY_SUIT_LVL_ATTR(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_SUIT_LVL_ATTR(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JEWELRY_SUIT_ATTR(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_SUIT_ATTR(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JEWELRY_SUIT_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_SUIT_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_JEWELRY_SUIT_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_JEWELRY_SUIT_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_INFO_PANEL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_INFO_PANEL(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_INFO_PANEL_OLD(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_INFO_PANEL_OLD(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLAYER_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLAYER_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLAYER_PANEL_ACK_OLD(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLAYER_PANEL_ACK_OLD(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLAYER_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLAYER_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PLAYER_INFO_PANEL_v410(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_INFO_PANEL_v410(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLAYER_PANEL_ACK_v410(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_AWAKEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_AWAKEN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_AWAKEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_AWAKEN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_JEWELRY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_JEWELRY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_JEWELRY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_JEWELRY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_JEWELRY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_JEWELRY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_JEWELRY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_JEWELRY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_HERO_SELECT_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HERO_SELECT_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HERO_SELECT_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JEWELRY_GENERATE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JEWELRY_GENERATE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JEWELRY_GENERATE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JEWELRY_GENERATE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_GENERATE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_GENERATE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_GENERATE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_GENERATE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_STRENGTH_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTH_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_STRENGTH_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTH_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_STRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_STRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_STRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_STRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_GENERATE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_GENERATE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_GENERATE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_GENERATE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_RESOLVE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_RESOLVE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_RESOLVE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_RESOLVE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_RESOLVE_ACK2(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_RESOLVE_ACK2(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JEWELRY_STRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JEWELRY_STRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_JEWELRY_STRENGTH_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_JEWELRY_STRENGTH_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BAG_JEWELRY_STRENGTH_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_JEWELRY_STRENGTH_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_COMPARE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_COMPARE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_COMPARE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_COMPARE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_GROUP_OVERTIME_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_GROUP_OVERTIME_NTF(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_FORMATION_PLAYER_ID_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_PLAYER_ID_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_FORMATION_HERO_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_HERO_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_FORMATION_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_FORMATION_SIMPLE_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_SIMPLE_PLAYER_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_FORMATION_SIMPLE_PLAYER_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_FORMATION_SIMPLE_PLAYER_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_FORMATION_POS_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_FORMATION_POS_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_FORMATION_POS_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_FORMATION_POS_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_FORMATION_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_FORMATION_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_FORMATION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_FORMATION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_TIME_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_TIME_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_SCHEDULE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_SCHEDULE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_APPLAY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_APPLAY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_RANK_MONEY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_RANK_MONEY_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_SIMPLE_RANK_MONEY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_SIMPLE_RANK_MONEY_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_RANK_MONEY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_RANK_MONEY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_SIMPLE_RANK_MONEY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_SIMPLE_RANK_MONEY_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_ALREAD_APPLAY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ALREAD_APPLAY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_ALREAD_APPLAY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ALREAD_APPLAY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_LAST_RESULT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_LAST_RESULT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_LAST_RESULT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_LAST_RESULT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_MONEY_CHAOS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_MONEY_CHAOS_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_OPEN_MY_GAMBLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_OPEN_MY_GAMBLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GAMBLE_GAME_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GAMBLE_GAME_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GAMBLE_GAME_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GAMBLE_GAME_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GAMBLE_GIFT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GAMBLE_GIFT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_OPEN_GAMBLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_OPEN_GAMBLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FACTION_GAMBLE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FACTION_GAMBLE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_OPEN_GAMBLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_OPEN_GAMBLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_RULE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_RULE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_RULE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_RULE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_GAMBLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_GAMBLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_GAMBLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_GAMBLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_ACTIVITY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_ACTIVITY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_MONEY_RANK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_MONEY_RANK_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FACTION_MONEY_RANK_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_READ_FORMATION_PLAYER_TIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_READ_FORMATION_PLAYER_TIP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_FACTION_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_FACTION_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_FACTION_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_FACTION_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GIFT_DETAILS_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GIFT_DETAILS_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GIFT_DETAILS_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GIFT_DETAILS_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_GIFT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_GIFT_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_GIFT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_GIFT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_GVG_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_GVG_GIFT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GET_GVG_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_GVG_GIFT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_APPLY_GVG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_APPLY_GVG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_APPLY_GVG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_APPLY_GVG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FINAL_WAR_FACTION_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FINAL_WAR_FACTION_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_LOG_RESET_UNREAD_CNT_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_GVG_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GVG_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_16_TO_8_TO_4_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_16_TO_8_TO_4_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FINAL_WAR_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FINAL_WAR_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_CHAMPION_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_CHAMPION_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_ERR_MSG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_ERR_MSG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GVG_VIDEO_FACTION_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GVG_VIDEO_FACTION_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEE_GVG_VIDEO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEE_GVG_VIDEO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEE_GVG_VIDEO_ACK_v400(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEE_GVG_VIDEO_ACK_v400(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SEE_GVG_VIDEO_ACK_v410(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEE_GVG_VIDEO_ACK_v410(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_END_GVG_VIDEO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_END_GVG_VIDEO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_END_GVG_VIDEO_ACK_v400(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_END_GVG_VIDEO_ACK_v400(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_END_GVG_VIDEO_ACK_v410(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_END_GVG_VIDEO_ACK_v410(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SHOW_GVG_MVP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SHOW_GVG_MVP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SHOW_GVG_MVP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SHOW_GVG_MVP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELECT_GROUP_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELECT_GROUP_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SELECT_GROUP_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELECT_GROUP_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_FACTION_APPLAY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_FACTION_APPLAY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_GVG_FACTION_APPLAY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GVG_FACTION_APPLAY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_READ_BATTLE_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_READ_BATTLE_LOG_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BATTLE_LOG_MSG_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_LOG_MSG_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BATTLE_LOG_MSG_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_LOG_MSG_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_READ_BATTLE_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_READ_BATTLE_LOG_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BATTLE_LOG_UNREAD_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_LOG_UNREAD_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UNREAD_BATTLE_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UNREAD_BATTLE_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BATTLE_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BATTLE_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHALLENGE_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLUNDER_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PKBATTLE_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PKBATTLE_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RDCHALLENGE_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RDCHALLENGE_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HUNTING_BATTLE_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HUNTING_BATTLE_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_PLAYER_BATTLE_DATA3(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_BATTLE_DATA3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_START_ACK3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_START_ACK3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_LEADER_START_NTF3(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_LEADER_START_NTF3(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGIN_JIEBIAO_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGIN_JIEBIAO_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_BATTLE_RECORD_ACK4(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_BATTLE_RECORD_ACK4(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLIGS_SOUL_MARK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLIGS_SOUL_MARK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLIGS_SOUL_MARK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLIGS_SOUL_MARK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DEVOUR_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DEVOUR_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_DEVOUR_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DEVOUR_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEVOUR_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEVOUR_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DEVOUR_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEVOUR_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_REFLASH_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_REFLASH_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_REFLASH_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_REFLASH_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFLASH_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFLASH_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFLASH_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFLASH_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SAVE_REFLASH_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SAVE_REFLASH_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SAVE_REFLASH_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SAVE_REFLASH_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_CLIGS_PRODUCTSOUL_COST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CLIGS_PRODUCTSOUL_COST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_REP_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_REP_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SOULREP_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SOULREP_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SOULREP_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SOULREP_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PRODUCT_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PRODUCT_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PRODUCT_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PRODUCT_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HERO_EQUIP_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HERO_EQUIP_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HERO_EQUIP_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HERO_EQUIP_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HERO_UNDRESS_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HERO_UNDRESS_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HERO_UNDRESS_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HERO_UNDRESS_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HERO_REPLACE_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HERO_REPLACE_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HERO_REPLACE_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HERO_REPLACE_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_EXCHANGE_METERIAL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_EXCHANGE_METERIAL(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SOUL_EXCHANGE_CARD(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SOUL_EXCHANGE_CARD(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SOULEXCHANGE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SOULEXCHANGE_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SOULEXCHANGE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SOULEXCHANGE_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_SOUL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_SOUL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MY_MEDAL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MY_MEDAL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_MY_MEDAL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MY_MEDAL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MEDAL_ICON_NAME(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_ICON_NAME(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MEDAL_ICON_ID_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MEDAL_ICON_ID_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MEDAL_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MEDAL_NTF(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_OUT_BOUND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_OUT_BOUND_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OUT_BOUND_DETAIL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OUT_BOUND_DETAIL_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OUT_BOUND_DETAIL_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OUT_BOUND_DETAIL_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_OUT_BOUND_SIMPLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OUT_BOUND_SIMPLE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_OUT_BOUND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_OUT_BOUND_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OUT_BOUND_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OUT_BOUND_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OUT_BOUND_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OUT_BOUND_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_STORE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STORE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOODS_EXCHANGE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_EXCHANGE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_GOODS_EXCHANGE_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_EXCHANGE_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_STORE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STORE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_GOODS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_GOODS_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EXCHANGE_GOODS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_GOODS_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKILL_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_CLI_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_CLI_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_CLI_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_CLI_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PETREP_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PETREP_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PETREP_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PETREP_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PRODUCT_PET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PRODUCT_PET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PRODUCT_PET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PRODUCT_PET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_STAR_DRAGON_ITEM_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STAR_DRAGON_ITEM_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_UP_STAR_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UP_STAR_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_STAR_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STAR_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_STAR_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STAR_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UP_STAR_LV_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UP_STAR_LV_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UP_STAR_LV_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UP_STAR_LV_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PETFEED_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PETFEED_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PETFEED_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PETFEED_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FIRST_DRAW_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FIRST_DRAW_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FIRST_DRAW_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FIRST_DRAW_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESET_DRAW_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESET_DRAW_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RESET_DRAW_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RESET_DRAW_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CONFIRM_FEED_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CONFIRM_FEED_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CONFIRM_FEED_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CONFIRM_FEED_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MERGE_PET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MERGE_PET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_MERGE_PET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MERGE_PET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_TEST_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_TEST_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_TEST_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_TEST_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_STORE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_STORE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_STORE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_STORE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_STORE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_STORE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_PET_STORE_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_PET_STORE_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BUY_PET_STORE_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_PET_STORE_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_REFINEPET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_REFINEPET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_REFINEPET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_REFINEPET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFINEPET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFINEPET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REFINEPET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFINEPET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BAG_ITEM_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_ITEM_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_WASH_QUALITY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_WASH_QUALITY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_WASHQUALITY_COST_ITEM(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_WASHQUALITY_COST_ITEM(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_WASHQUALITY_COST_ITEM_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_WASHQUALITY_COST_ITEM_LIST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_WASH_QUALITY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_WASH_QUALITY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_WASH_QUALITY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_WASH_QUALITY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_WASH_QUALITY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_WASH_QUALITY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_PET_STATE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_PET_STATE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHANGE_PET_STATE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHANGE_PET_STATE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_AFTER_INHERIT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_AFTER_INHERIT_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_INHERIT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_INHERIT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_INHERIT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_INHERIT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PET_INHERIT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PET_INHERIT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PET_INHERIT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PET_INHERIT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PLAYERPET_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLAYERPET_PANEL_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REQUEST_ALL_PET_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REQUEST_ALL_PET_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_REQUEST_ALL_PET_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REQUEST_ALL_PET_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_HERO_ATTR_ADD_CLI_v410(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_ATTR_ADD_CLI_v410(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECRUIT_HERO_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUIT_HERO_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MATERIAL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MATERIAL(void *pHost, CNetData* poNetData);
INT32 EncodeDT_MATERIAL_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MATERIAL_LIST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_RECRUIT_HERO_DATA_v410(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUIT_HERO_DATA_v410(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_MAKE_BOOK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MAKE_BOOK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_MAKE_BOOK_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_MAKE_BOOK_INFO_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_EQUIP_SERIES(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_SERIES(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FLY_COST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FLY_COST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FLY_GOAL(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FLY_GOAL(void *pHost, CNetData* poNetData);
INT32 EncodeDT_FLY_GOAL_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FLY_GOAL_LIST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_ENCHANT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_ENCHANT_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_ENCHANT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_ENCHANT_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SMITHY_ACK_v410(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SMITHY_ACK_v410(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_RECRUIT_ACK_v410(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECRUIT_ACK_v410(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPGRADE_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EQUIP_MAKE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EQUIP_MAKE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_EQUIP_MAKE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EQUIP_MAKE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_MAKE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_MAKE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_EQUIP_MAKE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_MAKE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FLY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FLY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_FLY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_FLY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FLY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FLY_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_FLY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FLY_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHALLENGE_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLUNDER_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PKBATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PKBATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RDCHALLENGE_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RDCHALLENGE_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_CHALLENGE_MYSELF_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_MYSELF_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_HUNTING_BATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_HUNTING_BATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodeDT_COURAGE_PLAYER_BATTLE_DATA5(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COURAGE_PLAYER_BATTLE_DATA5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_PLAYER_START_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_PLAYER_START_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_COURAGE_LEADER_START_NTF5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COURAGE_LEADER_START_NTF5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_BEGIN_JIEBIAO_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BEGIN_JIEBIAO_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_QUERY_BATTLE_RECORD_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_QUERY_BATTLE_RECORD_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPERATING_ACTIVITY_BATTLE_ACK5(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_RULE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_RULE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_BOOK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_BOOK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_BOOK_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_BOOK_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_PET_RULE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PET_RULE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_PET_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_PET_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_PLAYER_INFO_PET_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLAYER_INFO_PET_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_EXCHANGE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_EXCHANGE_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_POTENCY_ATTR_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POTENCY_ATTR_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_POTENCY_ATTR_LST_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POTENCY_ATTR_LST_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_POTENCY_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POTENCY_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_POTENCY_ATTR_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POTENCY_ATTR_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_POTENCY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POTENCY_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_POTENCY_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POTENCY_DATA_LST(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SOUL_UPDATE_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SOUL_UPDATE_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SOUL_UPDATE_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SOUL_UPDATE_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_MARK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_MARK_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEIDAN_BAG_MARK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEIDAN_BAG_MARK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEIDAN_PET_MARK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEIDAN_PET_MARK_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_NEIDAN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_NEIDAN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_DRESS_NEIDAN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_NEIDAN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NEIDAN_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEIDAN_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_PET_NEIDAN_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PET_NEIDAN_CLI(void *pHost, CNetData* poNetData);
INT32 EncodeDT_BAG_NEIDAN_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_NEIDAN_CLI(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_NEIDAN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_NEIDAN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_NEIDAN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_NEIDAN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPDATA_NEIDAN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATA_NEIDAN_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_UPDATA_NEIDAN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATA_NEIDAN_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NAIDAN_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NAIDAN_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 EncodeDT_NAIDAN_INSTANCE_LST_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NAIDAN_INSTANCE_LST_DATA(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_NEIDAN_ALL_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_NEIDAN_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_NEIDAN_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_NEIDAN_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_NEIDAN_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_NEIDAN_AWARD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_NEIDAN_AWARD_REQ(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_RECV_NEIDAN_AWARD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_NEIDAN_AWARD_ACK(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_NUM_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_NUM_INFO(void *pHost, CNetData* poNetData);
INT32 EncodeDT_ITEM_NUM_INFO_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_NUM_INFO_LST(void *pHost, CNetData* poNetData);
INT32 EncodeDT_SKIP_NEIDAN_AWARD_ITEM_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKIP_NEIDAN_AWARD_ITEM_INFO(void *pHost, CNetData* poNetData);
INT32 EncodePKT_CLIGS_SKIP_NEIDAN_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SKIP_NEIDAN_BATTLE_ACK(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef INT32 (*EnFuncCProtoCliGS)(void *pHost, CNetData* poNetData);
typedef INT32 (*DeFuncCProtoCliGS)(void *pHost, CNetData* poNetData);

class CProtoCliGS : public CSDProtocol
{
public:
    static CProtoCliGS * Instance();
    virtual INT32 Encode(INT32 iMsgID, void *pHost, CHAR *pNet, INT32 iNetSize);
    virtual INT32 Decode(INT32 iMsgID, CHAR *pNet,INT32 iNetSize, void *pHost, INT32 iHostSize);
	INT32 GetMaxPkgSize(){ return m_iMaxPkgSize; }
	EnFuncCProtoCliGS FindEncodeFunc(INT32 iMsgID);
	DeFuncCProtoCliGS FindDecodeFunc(INT32 iMsgID);
	BOOL Init();

private:
	CProtoCliGS();
	virtual ~CProtoCliGS();
	EnFuncCProtoCliGS m_EncodeFuncArray[PROTOCLIGS_MSGID_RANGE];
	DeFuncCProtoCliGS m_DecodeFuncArray[PROTOCLIGS_MSGID_RANGE];
	CNetData m_oData;
	INT32 m_iMaxPkgSize;

};

#pragma pack(pop)
#endif
