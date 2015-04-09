/*       Version Number: 10          */

#ifndef PROTOCOMMONDATA_H_INCLUDE_VERSION_10
#define PROTOCOMMONDATA_H_INCLUDE_VERSION_10

#include "netdata.h"
#include "sdtype.h"
#include "sdstring.h"
#include <json/json.h>
#pragma pack(push, 1)

/*Defines Begin*/
#define SUCCESS                  0
#define FAIL                     1
#define SESSIONID_LEN            8
#define DEVICEID_LEN             41
#define NOTIFYID_LEN             65
#define USERNAME_LEN             41
#define USERTYPE_LEN             41
#define USERPWD_LEN              17
#define MSG_LEN                  1024
#define IPSTR_LEN                17
#define LOGIN_TYPE_USER          0
#define LOGIN_TYPE_IPHONE        1
#define MAX_HERO_NUM             30
#define NEED                     1
#define NONNEED                  0
#define MAX_BAG_OPEN_NUM         100
#define CURRENCY_TYPE_COIN       0
#define CURRENCY_TYPE_GOLD       1
#define MAX_SKILL_NUM            12
#define MAX_SKILL_SLOT_NUM       3
#define MAX_SKILL_BUFF_NUM       3
#define MAX_BAG_NUM              5
#define MAX_BUILD_NUM            50
#define MAX_HANG_NUM             50
#define MAX_BATTLE_ROUND_NUM     60
#define MAX_ENCOURAGE_ITEM_NUM   10
#define MAX_INSTANCE_MONSTER_NUM 10
#define PICKUP_KIND_ITEM         0
#define PICKUP_KIND_HANG         1
#define MAX_SCENCE_NUM           2
#define MAX_TOWN_PER_SCENE_NUM   200
#define MAX_INSTANCE_PER_TOWN_NUM 3
#define MAX_INSTANCE_PER_SCENE_NUM 300
#define INSTANCE_INDEX_STR_LEN   15
#define MAX_HP_CHANGE_TIMES_PER_ROUND 30
#define MAX_ANGRY_CHANGE_TIMES_PER_ROUND 10
#define MAX_BUFF_CHANGE_TIMES_PER_ROUND 10
#define MAX_SCIENCE_ATTR_NUM     20
#define MAX_TASK_LINE_NUM        30
#define MAX_KILL_MONSTER_INSTANCE_NUM 5
#define MAX_ITEM_KIND_COLLECT_NUM 5
#define MAX_UPDATE_ATTR_NUM      20
#define CROWN                    1
#define RECRUITHERO              2
#define FIRSTPASSINSTANCE        5
#define SCOREPASSINSTANCE        6
#define TIMESPASSINSTANCE        7
#define KILLMONSTERINSTANCE      8
#define STRENGTHENEQUIPLEVEL     9
#define STRENGTHENEQUIPNUM       10
#define ACTIVATEGODWEAPON        12
#define UPGRADEGODWEAPON         13
#define CHALLENGE                14
#define PLUNDER                  15
#define DRESSEQUIP               19
#define COMPOSEGOOD              20
#define ELITEINSTANCE            21
#define UPGRADSCIENCE            22
#define STRENGTHATTACK           23
#define STRENGTHLIFE             24
#define CROP                     25
#define USEEXPRIENCEDRUG         26
#define MULT                     27
#define MAX_TASK_DSPNAME_LEN     40
#define MAX_TASK_DESC_LEN        100
#define ETS_GIVEN                0
#define ETS_ACCEPTED             1
#define ETS_ENCOURAGE            2
#define ETS_FINISHED             3
#define ETS_INVALID              4
#define MAX_CHALLENGE_NUM        10
#define MAX_SHOP_ITEM_NUM        100
#define MAX_ENCOURAGE_ITEM_KIND_NUM 10
#define MAX_ENCOURAGE_BOX_GROUP_NUM 3
#define MAX_UNLOCK_HERO_NUM      3
#define EPL_HOME                 0
#define EPL_INSTANCE             1
#define EPL_ONHOOK               2
#define EPL_PAGODA               3
#define EIK_EQUIP                0
#define EIK_GOODS                1
#define MAX_DRUG_LEVEL           6
#define MAX_FORMATION_NUM        9
#define MAX_FORMATION_IDX_NUM    6
#define MAX_ITEM_MAKER_NEED_NUM  6
#define EEIK_EQUIP               0
#define EEIK_DRUG                1
#define MAX_INSTANCE_RUN_TIMES   40
#define EIT_COMMON               1
#define EIT_ELITE                2
#define GET_ZONE_NUM             20
#define MAX_LOGIN_ENCOURAGE_ITEM_NUM 8
#define MAX_RANK_SHOW_NUM        100
#define MAX_RACE_BATTLELOG_NUM   100
#define MAX_COMPOSE_ITEM_NUM     5
#define MAX_PLUNDER_BATTLELOG_NUM 100
#define MAX_CAPTURE_NUM          4
#define MAX_GET_ENEMY_NUM        5
#define MAX_GET_PLUNDER_ENEMY_NUM 5
#define MAX_ROBOT_NUM            10
#define MAX_ENEMY_NUM            200
#define STUDY_COLOR_NUM          4
#define MAX_GRID_STUDY_CLIP_NUM  16
#define MAX_STUDY_STORE_NUM      6
#define MAX_STUDY_KIND_NUM       8
#define MAX_HERO_STUDY_NUM       8
#define MAX_GODWEAPON_QUALITY_NUM 6
#define MAX_BUFF_NUM             27
#define MAX_INSTANCE_NUM         200
#define EQUIP_POS_NUM            4
#define MAX_CROP_NUM             6
#define MAX_CROP_SEED_NUM        50
#define MAX_SCIENCE_KIND_NUM     15
#define MAX_CONTENT_SIZE         255
#define MAX_ORDER_ID_LEN         255
#define AUTH_TYPE_MAXNET         0
#define AUTH_TYPE_TONGBU         1
#define AUTH_TYPE_91             2
#define PROTOCOMMONDATA_MSGID_RANGE 1
#define PROTOCOMMONDATA_MSGID_OFFSET 0
#define PROTOCOL_VERSION 10
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagDT_PLAYER_BASE_DATA{
	UINT32           dwID; //���ΨһID
	TCHAR            aszDispName[USERNAME_LEN]; //��ʾ����
	UINT64           qwCoin; //ͭǮ
	UINT64           qwGold; //Ԫ��
	UINT64           qwStory; //����
	UINT16           wPhyStrength; //��ǰ����
	UINT64           qwScience; //��ǰ�Ƽ���
	UINT64           qwGuideRecord; //������¼
	UINT8            byRobotFunc; //�����˹���,>0��Ϊ�����ˣ���ͬ��ֵΪ��ͬ�Ĺ��ܡ�0Ϊ���
	UINT32           dwPower; //ս��(���initʱ���¸�ֵ)
	UINT32           dwFirstAttack; //�ȹ�ֵ
	UINT64           qwTodayFirstLoginTime; //�����һ�ε�½ʱ��
}DT_PLAYER_BASE_DATA;

typedef struct tagDT_BATTLE_ATTRIBUTE{
	UINT32           dwHP; //Ѫ��
	UINT32           dwAttack; //������
}DT_BATTLE_ATTRIBUTE;

typedef struct tagDT_HIDE_BATTLE_ATTRIBUTE{
	UINT16           wHitRate; //������
	UINT16           wDodgeRate; //������
	UINT16           wCritRate; //������
	UINT16           wDeCritRate; //������
	UINT16           wAngryValue; //ŭ��ֵ
}DT_HIDE_BATTLE_ATTRIBUTE;

typedef struct tagDT_EXT_BATTLE_ATTRIBUTE{
	UINT16           wIncHurtRate; //������(���ӵ��˺��ٷֱ�)
	UINT16           wDecHurtRate; //������(���ٵ��˺��ٷֱ�)
	UINT16           wOddAngry; //ŭ��ʣ��ֵ(�����ͷź�ʣ���ŭ��ֵ)
	UINT32           dwFirstAttack; //�ȹ�
	UINT16           wCoachTalent; //��������
}DT_EXT_BATTLE_ATTRIBUTE;

typedef struct tagDT_HERO_UPDATE_ATTR_DATA{
	UINT16           wAttrHP; //Ѫ��
	UINT16           wAttrAttack; //����
}DT_HERO_UPDATE_ATTR_DATA;

typedef struct tagDT_HERO_BASE_DATA{
	UINT16           wKindID; //�佫����
	UINT8            byCoach; //���佫��־,1Ϊ���佫
	UINT8            byPos; //λ�ñ�־,0Я����1Ϊ��ս��2����ļ����
	UINT8            byFormationIdx; //����λ��
	UINT16           wLevel; //�ȼ�
	UINT16           wTalent; //����
	UINT32           dwExperience; //����
	UINT8            byRecuitedFlag; //�Ƿ���ļ��
	UINT8            byVisitNum; //�ݷô���
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //ս������
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttr; //����ս������
	UINT8            byLastUseDrugLevel; //�ϴ�ʹ�õĵ�ҩ�ȼ�(Ʒ)
	UINT64           qwLastUseDrugTime; //�ϴ�ʹ�õ�ҩʱ��
	UINT8            byUseExperienceDrugPerDay; //ÿ���������������
	UINT64           qwLastUseExperienceDrugTime; //�ϴ�ʹ�þ��鵤ʱ��
	DT_HERO_UPDATE_ATTR_DATA stUpdateAttrInfo; //����������Ϣ
	UINT16           wSelectSkillID; //��ѡ����
	UINT16           wSelectSkillLevel; //��ѡ���ܵȼ�
}DT_HERO_BASE_DATA;

typedef struct tagDT_EQUIP_DATA{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT16           wLevel; //װ���ȼ�
	UINT16           wBagPos; //���ڱ���λ��
	UINT64           qwItemNewTime; //��������ʱ��
}DT_EQUIP_DATA;

typedef struct tagDT_HERO_EQUIP_DATA_LST{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA    astEquipList[EQUIP_POS_NUM]; //װ����Ϣ
}DT_HERO_EQUIP_DATA_LST;

typedef struct tagDT_BAG_EQUIP_DATA_LST{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA    astEquipList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_BAG_EQUIP_DATA_LST;

typedef struct tagDT_GOODS_DATA{
	UINT16           wKindID; //��Ʒ����
	UINT16           wPileCount; //������
	UINT64           qwLastUseTime; //�ϴ�ʹ��ʱ��
	UINT16           wLastUseNum; //�ϴ�ʹ�ô���
	UINT16           wBagPos; //���ڱ���λ��
	UINT64           qwItemNewTime; //��������ʱ��
}DT_GOODS_DATA;

typedef struct tagDT_BAG_GOODS_DATA_LST{
	UINT16           wGoodsNum; //װ������
	DT_GOODS_DATA    astGoodsList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_BAG_GOODS_DATA_LST;

typedef struct tagDT_DRUG_DATA{
	UINT8            byLevel; //��ҩ�ȼ�
	UINT8            byNum; //��ҩ����
	UINT16           wHeroKindID; //ʹ�õ��佫ID���������
}DT_DRUG_DATA;

typedef struct tagDT_DRUG_DATA_LST{
	UINT8            byDrugLevelNum; //��ҩ�������
	DT_DRUG_DATA     astDrugList[MAX_DRUG_LEVEL]; //��ҩ��Ϣ
}DT_DRUG_DATA_LST;

typedef struct tagDT_GODWEAPON_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT16           wQuality; //Ʒ��
	UINT16           wLevel; //�ȼ�
	UINT16           wHeroKindID; //ӵ�е��佫����ID
}DT_GODWEAPON_DATA;

typedef struct tagDT_SKILL_DATA{
	UINT16           wID; //��������ID
	UINT16           wLevel; //���ܵȼ�
	UINT8            byTrainNum; //������������
	UINT8            bySlotIdx; //���ܲ�(0��ʾδʹ�ã�1��ʾʹ��(Ŀǰ1�����ֻ֧�ִ���1������)
}DT_SKILL_DATA;

typedef struct tagDT_SKILL_DATA_LIST{
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_DATA    astSkillInfo[MAX_SKILL_NUM]; //������Ϣ
}DT_SKILL_DATA_LIST;

typedef struct tagDT_HERO_DATA{
	DT_HERO_BASE_DATA stHeroBaseData; //�佫������Ϣ
	DT_HERO_EQUIP_DATA_LST stEquipDataInfo; //�佫װ����Ϣ
	DT_DRUG_DATA_LST stDrugDataInfo; //��ҩ��Ϣ
	DT_GODWEAPON_DATA stGodweaponInfo; //������Ϣ
	DT_SKILL_DATA_LIST stSkillData; //������Ϣ
}DT_HERO_DATA;

typedef struct tagDT_HERO_DATA_LIST{
	UINT16           wHeroNum; //�佫��Ŀ
	DT_HERO_DATA     astHeroInfoLst[MAX_HERO_NUM]; //�佫��Ϣ
}DT_HERO_DATA_LIST;

typedef struct tagDT_BAG_DATA{
	UINT8            byOpenNum; //�򿪸�����(��ԭ��������)
}DT_BAG_DATA;

typedef struct tagDT_BUILD_BASE_DATA{
	UINT8            byKindID; //��������
	UINT16           wLevel; //�ȼ�
	UINT64           qwValue1; //��������Ϊ�ջ�ʱ��
	UINT64           qwValue2; //��������Ϊ����ʱ��
	UINT8            byValue3; //��������Ϊ���յĴ���
	UINT8            bySort; //��������
	UINT8            byHaveOpenFlag; //�����Ƿ�򿪹���1Ϊ�򿪹�
}DT_BUILD_BASE_DATA;

typedef struct tagDT_BUILD_DATA_LIST{
	UINT16           wBuildNum; //������Ŀ
	DT_BUILD_BASE_DATA astBuildInfoLst[MAX_BUILD_NUM]; //������Ϣ
}DT_BUILD_DATA_LIST;

typedef struct tagDT_INSTANCE_ID{
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
	UINT8            byInstanceIdx; //�������
}DT_INSTANCE_ID;

typedef struct tagDT_INSTANCE_DATA{
	DT_INSTANCE_ID   stInstanceID; //�������
	UINT8            byScore; //��������
	UINT16           wPassTimes; //����ͨ�ش���(0���ʾδͨ��)
	UINT64           qwLastPassTime; //�ϴθ���ͨ��ʱ��
}DT_INSTANCE_DATA;

typedef struct tagDT_INSTANCE_DATA_LIST{
	UINT16           wSceneIdx; //�������
	UINT16           wInstanceNum; //������Ŀ
	DT_INSTANCE_DATA astInstanceInfo[MAX_INSTANCE_PER_SCENE_NUM]; //������Ϣ
}DT_INSTANCE_DATA_LIST;

typedef struct tagDT_SCIENCE_ATTREXT{
	UINT8            byAttrKindID; //��������
	UINT16           wAttrLevel; //�Ƽ����Եȼ�
}DT_SCIENCE_ATTREXT;

typedef struct tagDT_SCIENCE_ATTREXT_LIST{
	UINT8            byAttrNum; //�Ƽ���������Ŀ
	DT_SCIENCE_ATTREXT astBuildInfoLst[MAX_SCIENCE_ATTR_NUM]; //�Ƽ���������Ϣ
}DT_SCIENCE_ATTREXT_LIST;

typedef struct tagDT_CROWN_TASK_CONDITION{
	UINT16           wCrownTimes; //
}DT_CROWN_TASK_CONDITION;

typedef struct tagDT_BUILDUPGRADE_TASK_CONDITION{
	UINT8            byBuildKindID; //
	UINT16           wLevel; //
}DT_BUILDUPGRADE_TASK_CONDITION;

typedef struct tagDT_RECRUITHERO_TASK_CONDITION{
	UINT16           wRecruitHeroKindID; //
}DT_RECRUITHERO_TASK_CONDITION;

typedef struct tagDT_CROWN_HEROCOLOR_CONDITION{
	UINT16           wHeroColor; //
	UINT8            byNum; //
}DT_CROWN_HEROCOLOR_CONDITION;

typedef struct tagDT_CROWN_HEROUPGRADE_CONDITION{
	UINT16           wHeroLevel; //
	UINT8            byNum; //
}DT_CROWN_HEROUPGRADE_CONDITION;

typedef struct tagDT_FIRSTPASSINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
}DT_FIRSTPASSINSTANCE_TASK_CONDITION;

typedef struct tagDT_SCOREPASSINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byScore; //
}DT_SCOREPASSINSTANCE_TASK_CONDITION;

typedef struct tagDT_TIMESPASSINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byTimes; //
}DT_TIMESPASSINSTANCE_TASK_CONDITION;

typedef struct tagDT_KILLMONSTERINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT16           wMonsterKindID; //
	UINT8            byKillNum; //
}DT_KILLMONSTERINSTANCE_TASK_CONDITION;

typedef struct tagDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION{
	UINT16           wEquipKindID; //
	UINT16           wLevel; //
}DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION;

typedef struct tagDT_STRENGTHENEQUIPNUM_TASK_CONDITION{
	UINT16           wEquipKindID; //
	UINT16           wNum; //
}DT_STRENGTHENEQUIPNUM_TASK_CONDITION;

typedef struct tagDT_ITEMCOLLECT_TASK_CONDITION{
	UINT16           wItemKindNum; //
	UINT8            abyItemCollectInfo[MAX_ITEM_KIND_COLLECT_NUM]; //
}DT_ITEMCOLLECT_TASK_CONDITION;

typedef struct tagDT_ACTIVATEGODWEAPON_TASK_CONDITION{
	UINT16           wHeroKindID; //
}DT_ACTIVATEGODWEAPON_TASK_CONDITION;

typedef struct tagDT_UPGRADEGODWEAPON_TASK_CONDITION{
	UINT16           wHeroKindID; //
	UINT16           wQuality; //
	UINT16           wLevel; //
}DT_UPGRADEGODWEAPON_TASK_CONDITION;

typedef struct tagDT_UPGRADEDRUG_TASK_CONDITION{
	UINT16           wUpgradeNum; //
}DT_UPGRADEDRUG_TASK_CONDITION;

typedef struct tagDT_CHALLENGE_TASK_CONDITION{
	UINT16           wChallengeNum; //
}DT_CHALLENGE_TASK_CONDITION;

typedef struct tagDT_PLUNDER_TASK_CONDITION{
	UINT16           wPlunderNum; //
}DT_PLUNDER_TASK_CONDITION;

typedef struct tagDT_DRESSSKILL_TASK_CONDITION{
	UINT16           wSkillID; //
	UINT8            byDressFlag; //
}DT_DRESSSKILL_TASK_CONDITION;

typedef struct tagDT_DRESSEQUIP_TASK_CONDITION{
	UINT16           wEquipID; //
	UINT8            byDressFlag; //
}DT_DRESSEQUIP_TASK_CONDITION;

typedef struct tagDT_UPGRADESKILL_TASK_CONDITION{
	UINT16           wSkillID; //����ID
	UINT16           wUpgradeNum; //��ɱ�־
}DT_UPGRADESKILL_TASK_CONDITION;

typedef struct tagDT_UPGRADEEQUIP_TASK_CONDITION{
	UINT16           wEquipID; //װ��ID
	UINT8            byUpgradeFlag; //��ɱ�־
}DT_UPGRADEEQUIP_TASK_CONDITION;

typedef struct tagDT_USEEXPRIENCEDRUG_TASK_CONDITION{
	UINT16           wNum; //���ô���
}DT_USEEXPRIENCEDRUG_TASK_CONDITION;

typedef struct tagDT_MULT_TASK_CONDITION{
	UINT16           wNum; //���ô���
}DT_MULT_TASK_CONDITION;

typedef struct tagDT_COMPOSEGOOD_TASK_CONDITION{
	UINT16           wMaterialID; //ԭ��ID
	UINT16           wMaterialNum; //ԭ�Ϻϳɸ���
	UINT16           wKindID; //�ϳɵ���ƷID
	UINT16           wNum; //�ϳɴ���
}DT_COMPOSEGOOD_TASK_CONDITION;

typedef struct tagDT_ELITEINSTANCE_TASK_CONDITION{
	UINT16           wSceneIdx; //�����������
	UINT8            byTownIdx; //���������������
	UINT8            byInstanceIdx; //�������
	UINT8            byUpgradeFlag; //��ɱ�־
}DT_ELITEINSTANCE_TASK_CONDITION;

typedef struct tagDT_UPGRADSCIENCE_TASK_CONDITION{
	UINT16           wNum; //��һ�����Ϣ
}DT_UPGRADSCIENCE_TASK_CONDITION;

typedef struct tagDT_STRENGTHATTACK_TASK_CONDITION{
	UINT16           wNum; //��һ�����Ϣ
}DT_STRENGTHATTACK_TASK_CONDITION;

typedef struct tagDT_STRENGTHLIFE_TASK_CONDITION{
	UINT16           wNum; //��һ�����Ϣ
}DT_STRENGTHLIFE_TASK_CONDITION;

typedef struct tagDT_CROP_TASK_CONDITION{
	UINT16           wNum; //��һ�����Ϣ
}DT_CROP_TASK_CONDITION;

typedef union tagDT_TASK_CONDITION{
	DT_CROWN_TASK_CONDITION stCrown; //��һ�����Ϣ
	DT_RECRUITHERO_TASK_CONDITION stRecruitHero; //<item name="BuildUpgrade" type="DT_BUILDUPGRADE_TASK_CONDITION" id="BUILDUPGRADE" />
	DT_FIRSTPASSINSTANCE_TASK_CONDITION stFirstPassInstance; //<item name="HeroUpgrade" type="DT_CROWN_HEROUPGRADE_CONDITION" id="HEROUPGRADE" />
	DT_SCOREPASSINSTANCE_TASK_CONDITION stScorePassInstance; //<item name="HeroUpgrade" type="DT_CROWN_HEROUPGRADE_CONDITION" id="HEROUPGRADE" />
	DT_TIMESPASSINSTANCE_TASK_CONDITION stTimesPassInstance; //<item name="HeroUpgrade" type="DT_CROWN_HEROUPGRADE_CONDITION" id="HEROUPGRADE" />
	DT_KILLMONSTERINSTANCE_TASK_CONDITION stKillMonstersInstance; //<item name="HeroUpgrade" type="DT_CROWN_HEROUPGRADE_CONDITION" id="HEROUPGRADE" />
	DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION stStrengthenEquipLevel; //<item name="HeroUpgrade" type="DT_CROWN_HEROUPGRADE_CONDITION" id="HEROUPGRADE" />
	DT_STRENGTHENEQUIPNUM_TASK_CONDITION stStrengthenEquipNum; //<item name="HeroUpgrade" type="DT_CROWN_HEROUPGRADE_CONDITION" id="HEROUPGRADE" />
	DT_ACTIVATEGODWEAPON_TASK_CONDITION stActivateGodweapon; //<item name="ItemCollect" type="DT_ITEMCOLLECT_TASK_CONDITION" id="ITEMCOLLECT" />
	DT_UPGRADEGODWEAPON_TASK_CONDITION stUpgradeGodweapon; //<item name="ItemCollect" type="DT_ITEMCOLLECT_TASK_CONDITION" id="ITEMCOLLECT" />
	DT_CHALLENGE_TASK_CONDITION stChallenge; //<item name="ItemCollect" type="DT_ITEMCOLLECT_TASK_CONDITION" id="ITEMCOLLECT" />
	DT_PLUNDER_TASK_CONDITION stPlunder; //<item name="ItemCollect" type="DT_ITEMCOLLECT_TASK_CONDITION" id="ITEMCOLLECT" />
	DT_DRESSEQUIP_TASK_CONDITION stDressEquip; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_USEEXPRIENCEDRUG_TASK_CONDITION stUseExprienceDrug; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_COMPOSEGOOD_TASK_CONDITION stComposeGood; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_ELITEINSTANCE_TASK_CONDITION stEliteInstance; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_UPGRADSCIENCE_TASK_CONDITION stUpgradeScience; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_STRENGTHATTACK_TASK_CONDITION stStrengthAttack; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_STRENGTHLIFE_TASK_CONDITION stStrengthLife; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_CROP_TASK_CONDITION stCrop; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
	DT_MULT_TASK_CONDITION stMult; //<item name="UpgradeEquip" type="DT_UPGRADEEQUIP_TASK_CONDITION" id="UPGRADEEQUIP" />
}DT_TASK_CONDITION;

typedef struct tagDT_TASK_DATA{
	UINT8            byTaskLine; //������
	UINT32           dwTaskIdx; //�������(�ڸ��������ڵ�)
	UINT64           qwStateUpdateTime; //״̬����ʱ��
	UINT8            byTaskState; //����״̬��0δ���ܣ�1�ѽ���δ���
	UINT8            byTaskType; //�������������¼
	DT_TASK_CONDITION stTaskConditionInfo; //�������������¼
}DT_TASK_DATA;

typedef struct tagDT_TASK_DATA_LIST{
	UINT8            byTaskNum; //������(ÿ��1��)
	DT_TASK_DATA     astTaskInfoList[MAX_TASK_LINE_NUM]; //������Ϣ
}DT_TASK_DATA_LIST;

typedef struct tagDT_RACE_DATA{
	UINT32           dwRank; //����
	UINT16           wContiWin; //��ǰ��ʤ����
	UINT64           qwRecvEncourageTime; //��ȡ����������ʱ��
	UINT64           qwLastChallTime; //������սʱ��
	UINT8            byChallTimes; //������ս����
	UINT8            byFailedFlag; //�Ƿ�������ս��
	UINT8            byUnreadBattleLogNum; //δ�ۿ�ս������
	UINT32           dwRecvEncourageRank; //��ȡ��������(��һ��(��������)������)
}DT_RACE_DATA;

typedef struct tagDT_LOCALE_HOME{
	UINT8            byExt; //��չ�ֶΣ���ʱ����
}DT_LOCALE_HOME;

typedef struct tagDT_LOCALE_INSTANCE{
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
	UINT8            byInstanceIdx; //�������
	UINT8            byBattleIdx; //ս�����
	UINT8            bySuccessFlag; //ս����Ӯ��0Ϊ����1ΪӮ
}DT_LOCALE_INSTANCE;

typedef struct tagDT_LOCALE_ONHOOK{
	UINT16           wSceneIdx; //�������
	UINT8            byTownIdx; //�������
	UINT8            byInstanceIdx; //�������
}DT_LOCALE_ONHOOK;

typedef union tagDT_LOCALE_DATA_UNION{
	DT_LOCALE_HOME   stHome; //��һ�����Ϣ
	DT_LOCALE_INSTANCE stInstance; //��һ�����Ϣ
	DT_LOCALE_ONHOOK stOnhook; //��һ�����Ϣ
}DT_LOCALE_DATA_UNION;

typedef struct tagDT_LOCALE_DATA{
	UINT8            byLocaleType; //λ������
	DT_LOCALE_DATA_UNION stLocaleInfo; //λ����Ϣ
}DT_LOCALE_DATA;

typedef struct tagUnlockScienceInfo{
	UINT8            byUnlockNum; //�����Ƽ���
	UINT8            abyUnlockScienceID[MAX_SCIENCE_ATTR_NUM]; //�Ƽ�ID
}UnlockScienceInfo;

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
}DT_STATE_DATA;

typedef struct tagDT_MONSTER_BASE_DATA{
	UINT16           wKindID; //����������
	UINT16           wLevel; //������ȼ�
}DT_MONSTER_BASE_DATA;

typedef struct tagDT_MONSTER_DATA_LIST{
	UINT16           wMonsterNum; //�������
	DT_MONSTER_BASE_DATA astMonsterInfListo[MAX_INSTANCE_MONSTER_NUM]; //������Ϣ
}DT_MONSTER_DATA_LIST;

typedef struct tagDT_BATTLE_OBJ_DATA{
	UINT16           wKindID; //����ID
	UINT8            byCareerID; //ְҵID
	UINT16           wLevel; //�ȼ�
	UINT8            byFomationIdx; //����λ��(��1��ʼ)
	DT_BATTLE_ATTRIBUTE stBattleAttr; //ս������
	UINT16           wSkillID; //����ID(0��ʾû�м���)
	UINT16           wSkillLevel; //���ܵȼ�
	UINT16           wNeedAngry; //�ͷ�����ŭ��
	UINT16           wInitAngry; //��ʼŭ��
	UINT8            byHPGridNum; //HP������
}DT_BATTLE_OBJ_DATA;

typedef struct tagDT_BATTLE_OBJ_GROUP_DATA{
	UINT8            byObjNum; //ս������Ϣ
	DT_BATTLE_OBJ_DATA astBattleObjInfo[MAX_FORMATION_IDX_NUM]; //ս������Ϣ
}DT_BATTLE_OBJ_GROUP_DATA;

typedef struct tagDT_ITEM_DATA{
	UINT16           wKindID; //��������ID
	UINT16           wNum; //����
}DT_ITEM_DATA;

typedef struct tagDT_BUFF_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT16           wAddDelFlag; //����/ɾ����־(0,������1ɾ��)
	UINT8            byBuffID; //BuffID
}DT_BUFF_DATA;

typedef struct tagDT_HP_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	INT32            nHP; //HP, >0���Ѫ��<0��ȥѪ
}DT_HP_DATA;

typedef struct tagDT_ANGRY_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	INT16            shAngry; //ŭ��, >0��ӣ�<0��ȥ
}DT_ANGRY_DATA;

typedef struct tagDT_PARRY_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT8            byParryFlag; //�񵲱�־��1��,
}DT_PARRY_DATA;

typedef struct tagDT_SKILL_EFFECT_ID_DATA{
	UINT8            byFormationIdx; //������ţ���1��ʼ)
	UINT16           wEffectID; //Ч��ID
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
}DT_ATTACK_OBJ_DATA;

typedef struct tagDT_ATTACK_DATA{
	DT_ATTACK_OBJ_DATA stMyselfObjInfo; //�ҷ���Ϣ
	DT_ATTACK_OBJ_DATA stEnemyObjInfo; //�з���Ϣ
}DT_ATTACK_DATA;

typedef struct tagDT_ATTACK_ALL_DATA{
	UINT8            byAttackerIdx; //������������ţ���1��ʼ)
	UINT16           wAttackSkillID; //��������KindID(0Ϊ��ͨ����������Ϊ����ID)
	UINT16           wAttackSkillLevel; //�������ܵȼ�(AttackSkillID��Ϊ0��Ч)
	UINT8            byCritFlag; //������־(��������1����,2ֹͣ����)
	UINT8            byBeAttackerIdxNum; //�ܻ�������Ϣ����1��ʼ)
	DT_PARRY_DATA    astBeAttackerIdxInfo[MAX_FORMATION_IDX_NUM]; //�ܻ�������Ϣ����1��ʼ)
	DT_ATTACK_DATA   stBeforeAttack; //�ܻ�ǰ��Ϣ
	DT_ATTACK_DATA   stAfterAttack; //�ܻ�����Ϣ
}DT_ATTACK_ALL_DATA;

typedef struct tagDT_BATTLE_ANGRY_DATA{
	UINT8            bySlot; //���ܲ�(��0��ʼ)
	UINT16           wCurAngry; //��ǰŭ��
}DT_BATTLE_ANGRY_DATA;

typedef struct tagDT_BATTLE_ROUND_DATA{
	UINT8            byAttackerFlag; //�����߱�־��0Ϊ�ҷ�
	DT_ATTACK_ALL_DATA stAttackData; //������Ϣ
}DT_BATTLE_ROUND_DATA;

typedef struct tagDT_BATTLE_DATA{
	DT_BATTLE_OBJ_GROUP_DATA stMyselfInfo; //�ҷ���Ϣ(����/������)
	DT_BATTLE_OBJ_GROUP_DATA stEnemyInfo; //�з���Ϣ
	UINT8            byBattleResult; //��սս�������0Ϊ�ҷ�Ӯ��1�Է�Ӯ��2�ҷ�Ӯ������ͨ��
	UINT8            byScore; //ս������
	UINT8            byBattleRoundNum; //ս���غ���
	DT_BATTLE_ROUND_DATA astBattleRoundInfo[MAX_BATTLE_ROUND_NUM]; //ս���غ���Ϣ
	DT_BATTLE_ATTRIBUTE stMyselfInfoAfterBattle; //ս�����ҷ���Ϣ
}DT_BATTLE_DATA;

typedef struct tagDT_ONLINE_ENCOURAGE_RECORD_DATA{
	UINT8            byRecvDays; //����ȡ����
	UINT64           qwLastRecvTime; //�ϴ���ȡʱ��
	UINT8            byLastRecvIndex; //�ϴ���ȡ�������
}DT_ONLINE_ENCOURAGE_RECORD_DATA;

typedef struct tagDT_LOGIN_ENCOURAGE_RECORD_DATA{
	UINT16           wKeepDays; //������¼����
	UINT8            byLastRecvNum; //�ϴ���ȡ����
	UINT64           qwLastRecvTime; //�ϴ���ȡʱ��
	UINT8            byLastSelectIndex; //�ϴ�ѡ�е����(��1��ʼ)
	UINT8            byStateFlag; //״̬(LastSelectIndex��Ϊ0ʱ��Ч)(0���·���1��ѡ��2�����)
}DT_LOGIN_ENCOURAGE_RECORD_DATA;

typedef struct tagDT_RACE_BATTLELOG_DATA{
	UINT8            byChallengeFlag; //��ս��־,0Ϊ������ս��1Ϊ����ս
	UINT64           qwChallengeTime; //��սʱ��
	UINT32           dwEnemyPlayerID; //�Է����ID
	UINT8            byResult; //��ս�����0Ϊ�ҷ�Ӯ��1Ϊ�Է�Ӯ
	UINT32           dwBeginChallengeRank; //��սǰ����
	UINT32           dwAfterChallengeRank; //��ս������
	UINT8            byNewFlag; //�Ƿ���ս����1Ϊ��
}DT_RACE_BATTLELOG_DATA;

typedef struct tagDT_RACE_BATTLELOG_DATA_LIST{
	UINT8            byBattleLogNum; //ս������
	DT_RACE_BATTLELOG_DATA astBattleLogInfo[MAX_RACE_BATTLELOG_NUM]; //ս����Ϣ
}DT_RACE_BATTLELOG_DATA_LIST;

typedef struct tagDT_CAPTURE_DATA{
	UINT32           dwCapturePlayerID; //����²�����ID
	UINT64           qwCaptureTime; //��²��ʱ��
	UINT8            byCaptureGridIdx; //��²�������(��0��ʼ)
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT64           qwLastCollectTime; //�ϴ���ȡ����ʱ��
}DT_CAPTURE_DATA;

typedef struct tagDT_CAPTURE_DATA_LIST{
	UINT8            byCaptureNum; //��²����
	DT_CAPTURE_DATA  astCaptureInfo[MAX_CAPTURE_NUM]; //��²��Ϣ
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
}DT_PLUNDER_BATTLELOG_DATA;

typedef struct tagDT_PLUNDER_BATTLELOG_DATA_LIST{
	UINT8            byBattleLogNum; //ս������
	DT_PLUNDER_BATTLELOG_DATA astBattleLogInfo[MAX_PLUNDER_BATTLELOG_NUM]; //ս����Ϣ
}DT_PLUNDER_BATTLELOG_DATA_LIST;

typedef struct tagDT_PLUNDER_GRID_DATA{
	UINT8            byIncomeType; //��������(0δ���ã�1ͭ�ң�2����)
	UINT32           dwIncomeValue; //����ֵ
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
}DT_PLUNDER_BASE_DATA;

typedef struct tagDT_ENEMY_DATA{
	UINT32           dwEnemyPlayerID; //������ID
	UINT16           wBattleNum; //���ִ���
	UINT64           qwAddTime; //���ʱ��
}DT_ENEMY_DATA;

typedef struct tagDT_ENEMY_DATA_LIST{
	UINT8            byEnemyNum; //ս������
	DT_ENEMY_DATA    astEnemyInfo[MAX_ENEMY_NUM]; //ս����Ϣ
}DT_ENEMY_DATA_LIST;

typedef struct tagDT_MONEY_TREE_DATA{
	UINT8            byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
	UINT16           wRockNum; //�ϴ���ҡ����
	UINT64           qwRockTime; //�ϴ�ҡ��ʱ��
	UINT8            byMoodValue; //�ϴ�����ֵ
	UINT64           qwMoodStartTime; //�ϴ�����ֵ��ʼʱ��
}DT_MONEY_TREE_DATA;

typedef struct tagDT_STUDY_DATA{
	UINT16           wID; //ID(�������ݿ����)
	UINT8            byGridIdx; //�洢�������(���Ѵ�����Ϊ��Ӧ�ĸ��ӣ���0��ʼ)
	UINT16           wHeroKindID; //�������佫ID(0Ϊδ����)
	UINT8            byKind; //�ĵ�����
	UINT8            byColor; //��ɫ(0��ʾ������)
	UINT8            byLevel; //�ȼ�
}DT_STUDY_DATA;

typedef struct tagDT_STUDY_CLIP_DATA{
	UINT16           wID; //ID(�������ݿ����)
	UINT8            byGridIdx; //�洢�������(��ʰȡ��Ϊ4����ɫ��Ӧ�ĸ��ӣ���0��ʼ)
	UINT8            byPickupFlag; //ʰȡ��־
	UINT8            byColor; //��ɫ(0Ϊû������)
	UINT16           wNum; //����(��ʰȡ��Ч)
}DT_STUDY_CLIP_DATA;

typedef struct tagDT_AWAKEN_DATA{
	UINT8            byLevel; //����ȼ���0��û�����ݣ�
	UINT8            byAuto2ExpFlag; //�Զ����ĵ���Ƭת���ɾ����־��0δѡ�У�1ѡ�У�
	UINT64           qwStudyExp; //�ĵþ���
}DT_AWAKEN_DATA;

typedef struct tagDT_INSTANCE_BATTLE_DATA{
	DT_INSTANCE_ID   stInstanceID; //�������
	UINT8            byBattleIndex; //ս�����
	UINT64           qwBattleTime; //�ϴ�ս��ʱ��
}DT_INSTANCE_BATTLE_DATA;

typedef struct tagDT_PHYSTRENGTH_DATA{
	UINT64           qwLastPhyStrengthRefreshTime; //�ϴ�����ˢ��ʱ��
	UINT64           qwLastBuyPhyStrengthTime; //�ϴι�������ʱ��
	UINT8            byLastBuyPhyStrengthNum; //�ϴι�����������
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
}DT_ONHOOK_RESULT;

typedef struct tagDT_ONHOOK_RCD_DATA{
	UINT8            byOnhookFlag; //�Ƿ�һ���
	DT_ONHOOK_RESULT stOnhookResult; //�һ������¼
	DT_INSTANCE_ID   stOnhookInstanceID; //�һ�����,wSceneIdxΪ0��ʾû�йһ�
	UINT64           qwLastOnhookResultReqTime; //�ϴ�����һ����ʱ��
}DT_ONHOOK_RCD_DATA;

typedef struct tagDT_FEW_PARAM_DATA{
	UINT64           qwLastStrengthenTime; //�ϴ�ǿ��ʱ��
	UINT16           wLastStrengthenCD; //�ϴ�ǿ���ۼ�CD
	UINT64           qwLastRefreshEliteTime; //�ϴ�ˢ�¾�Ӣ����ʱ��
	UINT16           wLastRefreshEliteNum; //�ϴ�ˢ�¾�Ӣ��������
}DT_FEW_PARAM_DATA;

typedef struct tagDT_CROP_INFO_DATA{
	UINT8            byOpen; //��ֲID
	UINT16           wCropKindID; //��ֲID
	UINT64           qwLastCropTime; //��ֲʱ��
}DT_CROP_INFO_DATA;

typedef struct tagDT_CROP_DATA{
	UINT8            byHaveDataFlag; //�Ƿ񱣴����ݿ�
	DT_CROP_INFO_DATA astCropInfoList[MAX_CROP_NUM]; //��ֲ��Ϣ
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
}DT_SCIENCE_TREE_DATA;

typedef struct tagDT_FORMATION_HERO_DATA{
	UINT8            byFormationIdx; //����λ��(��1��ʼ��1��6)
	UINT16           wHeroID; //�佫ID
}DT_FORMATION_HERO_DATA;

typedef struct tagDT_FORMATION_IDX_DATA{
	UINT8            byFormationKind; //��������
	UINT8            byOpenIdxNum; //���Ϳ���λ����
	DT_FORMATION_HERO_DATA astOpenIdxInfo[MAX_FORMATION_IDX_NUM]; //���Ϳ���λ����Ϣ
}DT_FORMATION_IDX_DATA;

typedef struct tagDT_FORMATION_DATA_LIST{
	UINT8            byFormationKindNum; //����������
	DT_FORMATION_IDX_DATA astFormationInfo[MAX_FORMATION_NUM]; //������Ϣ
}DT_FORMATION_DATA_LIST;

typedef struct tagDT_FORMATION_DATA{
	UINT8            bySelectIdx; //��ѡ������ţ���0��ʼ��
	DT_FORMATION_DATA_LIST stFormationList; //������Ϣ
}DT_FORMATION_DATA;

typedef struct tagDT_VERSION_DATA{
	UINT32           dwVersionID; //�汾ID,ȡ2λС����(/100)
	UINT8            byForceUpdateFlag; //�Ƿ�ǿ�Ƹ��£�1ǿ�Ƹ���
	TCHAR            aszUpdateContent[MAX_CONTENT_SIZE]; //��������
	TCHAR            aszUpdateURL[MAX_CONTENT_SIZE]; //���µ�ַ
}DT_VERSION_DATA;

typedef struct tagDT_NOTICE_DATA{
	UINT32           dwNoticeID; //����ID
	UINT8            byForcePopFlag; //�Ƿ���뵯,1Ϊ���뵯��
	UINT8            byUrlFlag; //����Ϊurl��־
	TCHAR            aszNoticeContent[MAX_CONTENT_SIZE]; //��������
}DT_NOTICE_DATA;

typedef struct tagDT_PLAYER_DATA{
	DT_PLAYER_BASE_DATA stBaseData; //��һ�����Ϣ
	DT_HERO_DATA_LIST stHeroData; //����佫��Ϣ�б�
	DT_BAG_DATA      stBagData; //��ұ�����Ϣ
	DT_BAG_EQUIP_DATA_LST stBagEquipData; //��ұ���װ��������Ϣ(����ڱ�����װ������������װ����װ��)
	DT_BAG_GOODS_DATA_LST stBagGoodsData; //��ұ�����Ʒ������Ϣ
	DT_BUILD_DATA_LIST stBuildData; //��ҽ�����Ϣ
	DT_TASK_DATA_LIST stTaskData; //���������Ϣ
	DT_RACE_DATA     stRaceData; //��Ҿ�������Ϣ
	DT_RACE_BATTLELOG_DATA_LIST stRaceBattleLog; //��Ҿ�����ս����Ϣ
	DT_LOCALE_DATA   stLocaleData; //��ҵ�ǰλ����Ϣ
	DT_STATE_DATA    stCurState; //��ҵ�ǰ״̬��Ϣ
	DT_ONLINE_ENCOURAGE_RECORD_DATA stOnlineEncRecdData; //���߽�����Ϣ
	DT_LOGIN_ENCOURAGE_RECORD_DATA stLoginEncRecdData; //��½������Ϣ
	DT_INSTANCE_DATA_LIST stCommonInstanceData; //�����ͨ������Ϣ
	DT_INSTANCE_DATA_LIST stEliteInstanceData; //��Ҿ�Ӣ������Ϣ
	DT_PLUNDER_BASE_DATA stPlunderBaseData; //�Ӷ������Ϣ
	DT_PLUNDER_BATTLELOG_DATA_LIST stPlunderBattleLog; //�Ӷ�ս����Ϣ
	DT_CAPTURE_DATA_LIST stCaptureData; //�Ӷ��²��Ϣ
	DT_ENEMY_DATA_LIST stEnemyData; //�����Ϣ
	DT_MONEY_TREE_DATA stMoneyTreeData; //ҡǮ����Ϣ
	DT_ONHOOK_RCD_DATA stOnhookRcdData; //�һ���¼��Ϣ
	DT_INSTANCE_BATTLE_DATA stCommonBattleRcd; //��ͨ����ս����¼
	DT_INSTANCE_BATTLE_DATA stEliteBattleRcd; //��Ӣ����ս����¼
	DT_SKILL_DATA_LIST stSkillData; //������Ϣ
	DT_PHYSTRENGTH_DATA stPhystrengthData; //������Ϣ
	DT_FEW_PARAM_DATA stFewParamData; //�ٲ�����Ϣ
	DT_CROP_DATA     stCropData; //��ֲ��Ϣ
	DT_SCIENCE_TREE_DATA stScienceTree; //�Ƽ�����Ϣ
	DT_FORMATION_DATA stFormationInfo; //������Ϣ
	CHAR             szLastOrderID[MAX_ORDER_ID_LEN]; //�ϴδ���Ķ����ţ����ڱ����ظ�����
}DT_PLAYER_DATA;

/*Define Structs and Unions        End*/


enum EN_ProtoCommonData_MessageID
{
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodeDT_PLAYER_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_BASE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLAYER_BASE_DATA( DT_PLAYER_BASE_DATA &data );
BOOL FromJsonDT_PLAYER_BASE_DATA(const string &strData, DT_PLAYER_BASE_DATA &data);
BOOL FromJsonDT_PLAYER_BASE_DATA(Json::Value &root, DT_PLAYER_BASE_DATA &data);
INT32 EncodeDT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_ATTRIBUTE( DT_BATTLE_ATTRIBUTE &data );
BOOL FromJsonDT_BATTLE_ATTRIBUTE(const string &strData, DT_BATTLE_ATTRIBUTE &data);
BOOL FromJsonDT_BATTLE_ATTRIBUTE(Json::Value &root, DT_BATTLE_ATTRIBUTE &data);
INT32 EncodeDT_HIDE_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HIDE_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HIDE_BATTLE_ATTRIBUTE( DT_HIDE_BATTLE_ATTRIBUTE &data );
BOOL FromJsonDT_HIDE_BATTLE_ATTRIBUTE(const string &strData, DT_HIDE_BATTLE_ATTRIBUTE &data);
BOOL FromJsonDT_HIDE_BATTLE_ATTRIBUTE(Json::Value &root, DT_HIDE_BATTLE_ATTRIBUTE &data);
INT32 EncodeDT_EXT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXT_BATTLE_ATTRIBUTE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EXT_BATTLE_ATTRIBUTE( DT_EXT_BATTLE_ATTRIBUTE &data );
BOOL FromJsonDT_EXT_BATTLE_ATTRIBUTE(const string &strData, DT_EXT_BATTLE_ATTRIBUTE &data);
BOOL FromJsonDT_EXT_BATTLE_ATTRIBUTE(Json::Value &root, DT_EXT_BATTLE_ATTRIBUTE &data);
INT32 EncodeDT_HERO_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_UPDATE_ATTR_DATA( DT_HERO_UPDATE_ATTR_DATA &data );
BOOL FromJsonDT_HERO_UPDATE_ATTR_DATA(const string &strData, DT_HERO_UPDATE_ATTR_DATA &data);
BOOL FromJsonDT_HERO_UPDATE_ATTR_DATA(Json::Value &root, DT_HERO_UPDATE_ATTR_DATA &data);
INT32 EncodeDT_HERO_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_BASE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_BASE_DATA( DT_HERO_BASE_DATA &data );
BOOL FromJsonDT_HERO_BASE_DATA(const string &strData, DT_HERO_BASE_DATA &data);
BOOL FromJsonDT_HERO_BASE_DATA(Json::Value &root, DT_HERO_BASE_DATA &data);
INT32 EncodeDT_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_DATA( DT_EQUIP_DATA &data );
BOOL FromJsonDT_EQUIP_DATA(const string &strData, DT_EQUIP_DATA &data);
BOOL FromJsonDT_EQUIP_DATA(Json::Value &root, DT_EQUIP_DATA &data);
INT32 EncodeDT_HERO_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_EQUIP_DATA_LST( DT_HERO_EQUIP_DATA_LST &data );
BOOL FromJsonDT_HERO_EQUIP_DATA_LST(const string &strData, DT_HERO_EQUIP_DATA_LST &data);
BOOL FromJsonDT_HERO_EQUIP_DATA_LST(Json::Value &root, DT_HERO_EQUIP_DATA_LST &data);
INT32 EncodeDT_BAG_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BAG_EQUIP_DATA_LST( DT_BAG_EQUIP_DATA_LST &data );
BOOL FromJsonDT_BAG_EQUIP_DATA_LST(const string &strData, DT_BAG_EQUIP_DATA_LST &data);
BOOL FromJsonDT_BAG_EQUIP_DATA_LST(Json::Value &root, DT_BAG_EQUIP_DATA_LST &data);
INT32 EncodeDT_GOODS_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GOODS_DATA( DT_GOODS_DATA &data );
BOOL FromJsonDT_GOODS_DATA(const string &strData, DT_GOODS_DATA &data);
BOOL FromJsonDT_GOODS_DATA(Json::Value &root, DT_GOODS_DATA &data);
INT32 EncodeDT_BAG_GOODS_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_GOODS_DATA_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BAG_GOODS_DATA_LST( DT_BAG_GOODS_DATA_LST &data );
BOOL FromJsonDT_BAG_GOODS_DATA_LST(const string &strData, DT_BAG_GOODS_DATA_LST &data);
BOOL FromJsonDT_BAG_GOODS_DATA_LST(Json::Value &root, DT_BAG_GOODS_DATA_LST &data);
INT32 EncodeDT_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRUG_DATA( DT_DRUG_DATA &data );
BOOL FromJsonDT_DRUG_DATA(const string &strData, DT_DRUG_DATA &data);
BOOL FromJsonDT_DRUG_DATA(Json::Value &root, DT_DRUG_DATA &data);
INT32 EncodeDT_DRUG_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_DATA_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRUG_DATA_LST( DT_DRUG_DATA_LST &data );
BOOL FromJsonDT_DRUG_DATA_LST(const string &strData, DT_DRUG_DATA_LST &data);
BOOL FromJsonDT_DRUG_DATA_LST(Json::Value &root, DT_DRUG_DATA_LST &data);
INT32 EncodeDT_GODWEAPON_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GODWEAPON_DATA( DT_GODWEAPON_DATA &data );
BOOL FromJsonDT_GODWEAPON_DATA(const string &strData, DT_GODWEAPON_DATA &data);
BOOL FromJsonDT_GODWEAPON_DATA(Json::Value &root, DT_GODWEAPON_DATA &data);
INT32 EncodeDT_SKILL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_DATA( DT_SKILL_DATA &data );
BOOL FromJsonDT_SKILL_DATA(const string &strData, DT_SKILL_DATA &data);
BOOL FromJsonDT_SKILL_DATA(Json::Value &root, DT_SKILL_DATA &data);
INT32 EncodeDT_SKILL_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_DATA_LIST( DT_SKILL_DATA_LIST &data );
BOOL FromJsonDT_SKILL_DATA_LIST(const string &strData, DT_SKILL_DATA_LIST &data);
BOOL FromJsonDT_SKILL_DATA_LIST(Json::Value &root, DT_SKILL_DATA_LIST &data);
INT32 EncodeDT_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_DATA( DT_HERO_DATA &data );
BOOL FromJsonDT_HERO_DATA(const string &strData, DT_HERO_DATA &data);
BOOL FromJsonDT_HERO_DATA(Json::Value &root, DT_HERO_DATA &data);
INT32 EncodeDT_HERO_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_DATA_LIST( DT_HERO_DATA_LIST &data );
BOOL FromJsonDT_HERO_DATA_LIST(const string &strData, DT_HERO_DATA_LIST &data);
BOOL FromJsonDT_HERO_DATA_LIST(Json::Value &root, DT_HERO_DATA_LIST &data);
INT32 EncodeDT_BAG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BAG_DATA( DT_BAG_DATA &data );
BOOL FromJsonDT_BAG_DATA(const string &strData, DT_BAG_DATA &data);
BOOL FromJsonDT_BAG_DATA(Json::Value &root, DT_BAG_DATA &data);
INT32 EncodeDT_BUILD_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILD_BASE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BUILD_BASE_DATA( DT_BUILD_BASE_DATA &data );
BOOL FromJsonDT_BUILD_BASE_DATA(const string &strData, DT_BUILD_BASE_DATA &data);
BOOL FromJsonDT_BUILD_BASE_DATA(Json::Value &root, DT_BUILD_BASE_DATA &data);
INT32 EncodeDT_BUILD_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILD_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BUILD_DATA_LIST( DT_BUILD_DATA_LIST &data );
BOOL FromJsonDT_BUILD_DATA_LIST(const string &strData, DT_BUILD_DATA_LIST &data);
BOOL FromJsonDT_BUILD_DATA_LIST(Json::Value &root, DT_BUILD_DATA_LIST &data);
INT32 EncodeDT_INSTANCE_ID(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_ID(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INSTANCE_ID( DT_INSTANCE_ID &data );
BOOL FromJsonDT_INSTANCE_ID(const string &strData, DT_INSTANCE_ID &data);
BOOL FromJsonDT_INSTANCE_ID(Json::Value &root, DT_INSTANCE_ID &data);
INT32 EncodeDT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INSTANCE_DATA( DT_INSTANCE_DATA &data );
BOOL FromJsonDT_INSTANCE_DATA(const string &strData, DT_INSTANCE_DATA &data);
BOOL FromJsonDT_INSTANCE_DATA(Json::Value &root, DT_INSTANCE_DATA &data);
INT32 EncodeDT_INSTANCE_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INSTANCE_DATA_LIST( DT_INSTANCE_DATA_LIST &data );
BOOL FromJsonDT_INSTANCE_DATA_LIST(const string &strData, DT_INSTANCE_DATA_LIST &data);
BOOL FromJsonDT_INSTANCE_DATA_LIST(Json::Value &root, DT_INSTANCE_DATA_LIST &data);
INT32 EncodeDT_SCIENCE_ATTREXT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_ATTREXT(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SCIENCE_ATTREXT( DT_SCIENCE_ATTREXT &data );
BOOL FromJsonDT_SCIENCE_ATTREXT(const string &strData, DT_SCIENCE_ATTREXT &data);
BOOL FromJsonDT_SCIENCE_ATTREXT(Json::Value &root, DT_SCIENCE_ATTREXT &data);
INT32 EncodeDT_SCIENCE_ATTREXT_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_ATTREXT_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SCIENCE_ATTREXT_LIST( DT_SCIENCE_ATTREXT_LIST &data );
BOOL FromJsonDT_SCIENCE_ATTREXT_LIST(const string &strData, DT_SCIENCE_ATTREXT_LIST &data);
BOOL FromJsonDT_SCIENCE_ATTREXT_LIST(Json::Value &root, DT_SCIENCE_ATTREXT_LIST &data);
INT32 EncodeDT_CROWN_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROWN_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROWN_TASK_CONDITION( DT_CROWN_TASK_CONDITION &data );
BOOL FromJsonDT_CROWN_TASK_CONDITION(const string &strData, DT_CROWN_TASK_CONDITION &data);
BOOL FromJsonDT_CROWN_TASK_CONDITION(Json::Value &root, DT_CROWN_TASK_CONDITION &data);
INT32 EncodeDT_BUILDUPGRADE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILDUPGRADE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BUILDUPGRADE_TASK_CONDITION( DT_BUILDUPGRADE_TASK_CONDITION &data );
BOOL FromJsonDT_BUILDUPGRADE_TASK_CONDITION(const string &strData, DT_BUILDUPGRADE_TASK_CONDITION &data);
BOOL FromJsonDT_BUILDUPGRADE_TASK_CONDITION(Json::Value &root, DT_BUILDUPGRADE_TASK_CONDITION &data);
INT32 EncodeDT_RECRUITHERO_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUITHERO_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RECRUITHERO_TASK_CONDITION( DT_RECRUITHERO_TASK_CONDITION &data );
BOOL FromJsonDT_RECRUITHERO_TASK_CONDITION(const string &strData, DT_RECRUITHERO_TASK_CONDITION &data);
BOOL FromJsonDT_RECRUITHERO_TASK_CONDITION(Json::Value &root, DT_RECRUITHERO_TASK_CONDITION &data);
INT32 EncodeDT_CROWN_HEROCOLOR_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROWN_HEROCOLOR_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROWN_HEROCOLOR_CONDITION( DT_CROWN_HEROCOLOR_CONDITION &data );
BOOL FromJsonDT_CROWN_HEROCOLOR_CONDITION(const string &strData, DT_CROWN_HEROCOLOR_CONDITION &data);
BOOL FromJsonDT_CROWN_HEROCOLOR_CONDITION(Json::Value &root, DT_CROWN_HEROCOLOR_CONDITION &data);
INT32 EncodeDT_CROWN_HEROUPGRADE_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROWN_HEROUPGRADE_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROWN_HEROUPGRADE_CONDITION( DT_CROWN_HEROUPGRADE_CONDITION &data );
BOOL FromJsonDT_CROWN_HEROUPGRADE_CONDITION(const string &strData, DT_CROWN_HEROUPGRADE_CONDITION &data);
BOOL FromJsonDT_CROWN_HEROUPGRADE_CONDITION(Json::Value &root, DT_CROWN_HEROUPGRADE_CONDITION &data);
INT32 EncodeDT_FIRSTPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FIRSTPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FIRSTPASSINSTANCE_TASK_CONDITION( DT_FIRSTPASSINSTANCE_TASK_CONDITION &data );
BOOL FromJsonDT_FIRSTPASSINSTANCE_TASK_CONDITION(const string &strData, DT_FIRSTPASSINSTANCE_TASK_CONDITION &data);
BOOL FromJsonDT_FIRSTPASSINSTANCE_TASK_CONDITION(Json::Value &root, DT_FIRSTPASSINSTANCE_TASK_CONDITION &data);
INT32 EncodeDT_SCOREPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCOREPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SCOREPASSINSTANCE_TASK_CONDITION( DT_SCOREPASSINSTANCE_TASK_CONDITION &data );
BOOL FromJsonDT_SCOREPASSINSTANCE_TASK_CONDITION(const string &strData, DT_SCOREPASSINSTANCE_TASK_CONDITION &data);
BOOL FromJsonDT_SCOREPASSINSTANCE_TASK_CONDITION(Json::Value &root, DT_SCOREPASSINSTANCE_TASK_CONDITION &data);
INT32 EncodeDT_TIMESPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TIMESPASSINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TIMESPASSINSTANCE_TASK_CONDITION( DT_TIMESPASSINSTANCE_TASK_CONDITION &data );
BOOL FromJsonDT_TIMESPASSINSTANCE_TASK_CONDITION(const string &strData, DT_TIMESPASSINSTANCE_TASK_CONDITION &data);
BOOL FromJsonDT_TIMESPASSINSTANCE_TASK_CONDITION(Json::Value &root, DT_TIMESPASSINSTANCE_TASK_CONDITION &data);
INT32 EncodeDT_KILLMONSTERINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_KILLMONSTERINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_KILLMONSTERINSTANCE_TASK_CONDITION( DT_KILLMONSTERINSTANCE_TASK_CONDITION &data );
BOOL FromJsonDT_KILLMONSTERINSTANCE_TASK_CONDITION(const string &strData, DT_KILLMONSTERINSTANCE_TASK_CONDITION &data);
BOOL FromJsonDT_KILLMONSTERINSTANCE_TASK_CONDITION(Json::Value &root, DT_KILLMONSTERINSTANCE_TASK_CONDITION &data);
INT32 EncodeDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION( DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION &data );
BOOL FromJsonDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION(const string &strData, DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION &data);
BOOL FromJsonDT_STRENGTHENEQUIPLEVEL_TASK_CONDITION(Json::Value &root, DT_STRENGTHENEQUIPLEVEL_TASK_CONDITION &data);
INT32 EncodeDT_STRENGTHENEQUIPNUM_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHENEQUIPNUM_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STRENGTHENEQUIPNUM_TASK_CONDITION( DT_STRENGTHENEQUIPNUM_TASK_CONDITION &data );
BOOL FromJsonDT_STRENGTHENEQUIPNUM_TASK_CONDITION(const string &strData, DT_STRENGTHENEQUIPNUM_TASK_CONDITION &data);
BOOL FromJsonDT_STRENGTHENEQUIPNUM_TASK_CONDITION(Json::Value &root, DT_STRENGTHENEQUIPNUM_TASK_CONDITION &data);
INT32 EncodeDT_ITEMCOLLECT_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEMCOLLECT_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEMCOLLECT_TASK_CONDITION( DT_ITEMCOLLECT_TASK_CONDITION &data );
BOOL FromJsonDT_ITEMCOLLECT_TASK_CONDITION(const string &strData, DT_ITEMCOLLECT_TASK_CONDITION &data);
BOOL FromJsonDT_ITEMCOLLECT_TASK_CONDITION(Json::Value &root, DT_ITEMCOLLECT_TASK_CONDITION &data);
INT32 EncodeDT_ACTIVATEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACTIVATEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ACTIVATEGODWEAPON_TASK_CONDITION( DT_ACTIVATEGODWEAPON_TASK_CONDITION &data );
BOOL FromJsonDT_ACTIVATEGODWEAPON_TASK_CONDITION(const string &strData, DT_ACTIVATEGODWEAPON_TASK_CONDITION &data);
BOOL FromJsonDT_ACTIVATEGODWEAPON_TASK_CONDITION(Json::Value &root, DT_ACTIVATEGODWEAPON_TASK_CONDITION &data);
INT32 EncodeDT_UPGRADEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEGODWEAPON_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPGRADEGODWEAPON_TASK_CONDITION( DT_UPGRADEGODWEAPON_TASK_CONDITION &data );
BOOL FromJsonDT_UPGRADEGODWEAPON_TASK_CONDITION(const string &strData, DT_UPGRADEGODWEAPON_TASK_CONDITION &data);
BOOL FromJsonDT_UPGRADEGODWEAPON_TASK_CONDITION(Json::Value &root, DT_UPGRADEGODWEAPON_TASK_CONDITION &data);
INT32 EncodeDT_UPGRADEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPGRADEDRUG_TASK_CONDITION( DT_UPGRADEDRUG_TASK_CONDITION &data );
BOOL FromJsonDT_UPGRADEDRUG_TASK_CONDITION(const string &strData, DT_UPGRADEDRUG_TASK_CONDITION &data);
BOOL FromJsonDT_UPGRADEDRUG_TASK_CONDITION(Json::Value &root, DT_UPGRADEDRUG_TASK_CONDITION &data);
INT32 EncodeDT_CHALLENGE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHALLENGE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CHALLENGE_TASK_CONDITION( DT_CHALLENGE_TASK_CONDITION &data );
BOOL FromJsonDT_CHALLENGE_TASK_CONDITION(const string &strData, DT_CHALLENGE_TASK_CONDITION &data);
BOOL FromJsonDT_CHALLENGE_TASK_CONDITION(Json::Value &root, DT_CHALLENGE_TASK_CONDITION &data);
INT32 EncodeDT_PLUNDER_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_TASK_CONDITION( DT_PLUNDER_TASK_CONDITION &data );
BOOL FromJsonDT_PLUNDER_TASK_CONDITION(const string &strData, DT_PLUNDER_TASK_CONDITION &data);
BOOL FromJsonDT_PLUNDER_TASK_CONDITION(Json::Value &root, DT_PLUNDER_TASK_CONDITION &data);
INT32 EncodeDT_DRESSSKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRESSSKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRESSSKILL_TASK_CONDITION( DT_DRESSSKILL_TASK_CONDITION &data );
BOOL FromJsonDT_DRESSSKILL_TASK_CONDITION(const string &strData, DT_DRESSSKILL_TASK_CONDITION &data);
BOOL FromJsonDT_DRESSSKILL_TASK_CONDITION(Json::Value &root, DT_DRESSSKILL_TASK_CONDITION &data);
INT32 EncodeDT_DRESSEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRESSEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRESSEQUIP_TASK_CONDITION( DT_DRESSEQUIP_TASK_CONDITION &data );
BOOL FromJsonDT_DRESSEQUIP_TASK_CONDITION(const string &strData, DT_DRESSEQUIP_TASK_CONDITION &data);
BOOL FromJsonDT_DRESSEQUIP_TASK_CONDITION(Json::Value &root, DT_DRESSEQUIP_TASK_CONDITION &data);
INT32 EncodeDT_UPGRADESKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADESKILL_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPGRADESKILL_TASK_CONDITION( DT_UPGRADESKILL_TASK_CONDITION &data );
BOOL FromJsonDT_UPGRADESKILL_TASK_CONDITION(const string &strData, DT_UPGRADESKILL_TASK_CONDITION &data);
BOOL FromJsonDT_UPGRADESKILL_TASK_CONDITION(Json::Value &root, DT_UPGRADESKILL_TASK_CONDITION &data);
INT32 EncodeDT_UPGRADEEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADEEQUIP_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPGRADEEQUIP_TASK_CONDITION( DT_UPGRADEEQUIP_TASK_CONDITION &data );
BOOL FromJsonDT_UPGRADEEQUIP_TASK_CONDITION(const string &strData, DT_UPGRADEEQUIP_TASK_CONDITION &data);
BOOL FromJsonDT_UPGRADEEQUIP_TASK_CONDITION(Json::Value &root, DT_UPGRADEEQUIP_TASK_CONDITION &data);
INT32 EncodeDT_USEEXPRIENCEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_USEEXPRIENCEDRUG_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_USEEXPRIENCEDRUG_TASK_CONDITION( DT_USEEXPRIENCEDRUG_TASK_CONDITION &data );
BOOL FromJsonDT_USEEXPRIENCEDRUG_TASK_CONDITION(const string &strData, DT_USEEXPRIENCEDRUG_TASK_CONDITION &data);
BOOL FromJsonDT_USEEXPRIENCEDRUG_TASK_CONDITION(Json::Value &root, DT_USEEXPRIENCEDRUG_TASK_CONDITION &data);
INT32 EncodeDT_MULT_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MULT_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_MULT_TASK_CONDITION( DT_MULT_TASK_CONDITION &data );
BOOL FromJsonDT_MULT_TASK_CONDITION(const string &strData, DT_MULT_TASK_CONDITION &data);
BOOL FromJsonDT_MULT_TASK_CONDITION(Json::Value &root, DT_MULT_TASK_CONDITION &data);
INT32 EncodeDT_COMPOSEGOOD_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_COMPOSEGOOD_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_COMPOSEGOOD_TASK_CONDITION( DT_COMPOSEGOOD_TASK_CONDITION &data );
BOOL FromJsonDT_COMPOSEGOOD_TASK_CONDITION(const string &strData, DT_COMPOSEGOOD_TASK_CONDITION &data);
BOOL FromJsonDT_COMPOSEGOOD_TASK_CONDITION(Json::Value &root, DT_COMPOSEGOOD_TASK_CONDITION &data);
INT32 EncodeDT_ELITEINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ELITEINSTANCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ELITEINSTANCE_TASK_CONDITION( DT_ELITEINSTANCE_TASK_CONDITION &data );
BOOL FromJsonDT_ELITEINSTANCE_TASK_CONDITION(const string &strData, DT_ELITEINSTANCE_TASK_CONDITION &data);
BOOL FromJsonDT_ELITEINSTANCE_TASK_CONDITION(Json::Value &root, DT_ELITEINSTANCE_TASK_CONDITION &data);
INT32 EncodeDT_UPGRADSCIENCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPGRADSCIENCE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPGRADSCIENCE_TASK_CONDITION( DT_UPGRADSCIENCE_TASK_CONDITION &data );
BOOL FromJsonDT_UPGRADSCIENCE_TASK_CONDITION(const string &strData, DT_UPGRADSCIENCE_TASK_CONDITION &data);
BOOL FromJsonDT_UPGRADSCIENCE_TASK_CONDITION(Json::Value &root, DT_UPGRADSCIENCE_TASK_CONDITION &data);
INT32 EncodeDT_STRENGTHATTACK_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHATTACK_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STRENGTHATTACK_TASK_CONDITION( DT_STRENGTHATTACK_TASK_CONDITION &data );
BOOL FromJsonDT_STRENGTHATTACK_TASK_CONDITION(const string &strData, DT_STRENGTHATTACK_TASK_CONDITION &data);
BOOL FromJsonDT_STRENGTHATTACK_TASK_CONDITION(Json::Value &root, DT_STRENGTHATTACK_TASK_CONDITION &data);
INT32 EncodeDT_STRENGTHLIFE_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STRENGTHLIFE_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STRENGTHLIFE_TASK_CONDITION( DT_STRENGTHLIFE_TASK_CONDITION &data );
BOOL FromJsonDT_STRENGTHLIFE_TASK_CONDITION(const string &strData, DT_STRENGTHLIFE_TASK_CONDITION &data);
BOOL FromJsonDT_STRENGTHLIFE_TASK_CONDITION(Json::Value &root, DT_STRENGTHLIFE_TASK_CONDITION &data);
INT32 EncodeDT_CROP_TASK_CONDITION(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_TASK_CONDITION(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROP_TASK_CONDITION( DT_CROP_TASK_CONDITION &data );
BOOL FromJsonDT_CROP_TASK_CONDITION(const string &strData, DT_CROP_TASK_CONDITION &data);
BOOL FromJsonDT_CROP_TASK_CONDITION(Json::Value &root, DT_CROP_TASK_CONDITION &data);
INT32 EncodeUnDT_TASK_CONDITION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_TASK_CONDITION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_DATA( DT_TASK_DATA &data );
BOOL FromJsonDT_TASK_DATA(const string &strData, DT_TASK_DATA &data);
BOOL FromJsonDT_TASK_DATA(Json::Value &root, DT_TASK_DATA &data);
INT32 EncodeDT_TASK_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_DATA_LIST( DT_TASK_DATA_LIST &data );
BOOL FromJsonDT_TASK_DATA_LIST(const string &strData, DT_TASK_DATA_LIST &data);
BOOL FromJsonDT_TASK_DATA_LIST(Json::Value &root, DT_TASK_DATA_LIST &data);
INT32 EncodeDT_RACE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RACE_DATA( DT_RACE_DATA &data );
BOOL FromJsonDT_RACE_DATA(const string &strData, DT_RACE_DATA &data);
BOOL FromJsonDT_RACE_DATA(Json::Value &root, DT_RACE_DATA &data);
INT32 EncodeDT_LOCALE_HOME(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_HOME(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOCALE_HOME( DT_LOCALE_HOME &data );
BOOL FromJsonDT_LOCALE_HOME(const string &strData, DT_LOCALE_HOME &data);
BOOL FromJsonDT_LOCALE_HOME(Json::Value &root, DT_LOCALE_HOME &data);
INT32 EncodeDT_LOCALE_INSTANCE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_INSTANCE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOCALE_INSTANCE( DT_LOCALE_INSTANCE &data );
BOOL FromJsonDT_LOCALE_INSTANCE(const string &strData, DT_LOCALE_INSTANCE &data);
BOOL FromJsonDT_LOCALE_INSTANCE(Json::Value &root, DT_LOCALE_INSTANCE &data);
INT32 EncodeDT_LOCALE_ONHOOK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_ONHOOK(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOCALE_ONHOOK( DT_LOCALE_ONHOOK &data );
BOOL FromJsonDT_LOCALE_ONHOOK(const string &strData, DT_LOCALE_ONHOOK &data);
BOOL FromJsonDT_LOCALE_ONHOOK(Json::Value &root, DT_LOCALE_ONHOOK &data);
INT32 EncodeUnDT_LOCALE_DATA_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_LOCALE_DATA_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_LOCALE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCALE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOCALE_DATA( DT_LOCALE_DATA &data );
BOOL FromJsonDT_LOCALE_DATA(const string &strData, DT_LOCALE_DATA &data);
BOOL FromJsonDT_LOCALE_DATA(Json::Value &root, DT_LOCALE_DATA &data);
INT32 EncodeUnlockScienceInfo(void *pHost, CNetData* poNetData);
INT32 DecodeUnlockScienceInfo(void *pHost, CNetData* poNetData);
Json::Value GetJsonUnlockScienceInfo( UnlockScienceInfo &data );
BOOL FromJsonUnlockScienceInfo(const string &strData, UnlockScienceInfo &data);
BOOL FromJsonUnlockScienceInfo(Json::Value &root, UnlockScienceInfo &data);
INT32 EncodeDT_STATE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STATE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STATE_DATA( DT_STATE_DATA &data );
BOOL FromJsonDT_STATE_DATA(const string &strData, DT_STATE_DATA &data);
BOOL FromJsonDT_STATE_DATA(Json::Value &root, DT_STATE_DATA &data);
INT32 EncodeDT_MONSTER_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONSTER_BASE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_MONSTER_BASE_DATA( DT_MONSTER_BASE_DATA &data );
BOOL FromJsonDT_MONSTER_BASE_DATA(const string &strData, DT_MONSTER_BASE_DATA &data);
BOOL FromJsonDT_MONSTER_BASE_DATA(Json::Value &root, DT_MONSTER_BASE_DATA &data);
INT32 EncodeDT_MONSTER_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONSTER_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_MONSTER_DATA_LIST( DT_MONSTER_DATA_LIST &data );
BOOL FromJsonDT_MONSTER_DATA_LIST(const string &strData, DT_MONSTER_DATA_LIST &data);
BOOL FromJsonDT_MONSTER_DATA_LIST(Json::Value &root, DT_MONSTER_DATA_LIST &data);
INT32 EncodeDT_BATTLE_OBJ_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_OBJ_DATA( DT_BATTLE_OBJ_DATA &data );
BOOL FromJsonDT_BATTLE_OBJ_DATA(const string &strData, DT_BATTLE_OBJ_DATA &data);
BOOL FromJsonDT_BATTLE_OBJ_DATA(Json::Value &root, DT_BATTLE_OBJ_DATA &data);
INT32 EncodeDT_BATTLE_OBJ_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_OBJ_GROUP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_OBJ_GROUP_DATA( DT_BATTLE_OBJ_GROUP_DATA &data );
BOOL FromJsonDT_BATTLE_OBJ_GROUP_DATA(const string &strData, DT_BATTLE_OBJ_GROUP_DATA &data);
BOOL FromJsonDT_BATTLE_OBJ_GROUP_DATA(Json::Value &root, DT_BATTLE_OBJ_GROUP_DATA &data);
INT32 EncodeDT_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEM_DATA( DT_ITEM_DATA &data );
BOOL FromJsonDT_ITEM_DATA(const string &strData, DT_ITEM_DATA &data);
BOOL FromJsonDT_ITEM_DATA(Json::Value &root, DT_ITEM_DATA &data);
INT32 EncodeDT_BUFF_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUFF_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BUFF_DATA( DT_BUFF_DATA &data );
BOOL FromJsonDT_BUFF_DATA(const string &strData, DT_BUFF_DATA &data);
BOOL FromJsonDT_BUFF_DATA(Json::Value &root, DT_BUFF_DATA &data);
INT32 EncodeDT_HP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HP_DATA( DT_HP_DATA &data );
BOOL FromJsonDT_HP_DATA(const string &strData, DT_HP_DATA &data);
BOOL FromJsonDT_HP_DATA(Json::Value &root, DT_HP_DATA &data);
INT32 EncodeDT_ANGRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ANGRY_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ANGRY_DATA( DT_ANGRY_DATA &data );
BOOL FromJsonDT_ANGRY_DATA(const string &strData, DT_ANGRY_DATA &data);
BOOL FromJsonDT_ANGRY_DATA(Json::Value &root, DT_ANGRY_DATA &data);
INT32 EncodeDT_PARRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PARRY_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PARRY_DATA( DT_PARRY_DATA &data );
BOOL FromJsonDT_PARRY_DATA(const string &strData, DT_PARRY_DATA &data);
BOOL FromJsonDT_PARRY_DATA(Json::Value &root, DT_PARRY_DATA &data);
INT32 EncodeDT_SKILL_EFFECT_ID_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_EFFECT_ID_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_EFFECT_ID_DATA( DT_SKILL_EFFECT_ID_DATA &data );
BOOL FromJsonDT_SKILL_EFFECT_ID_DATA(const string &strData, DT_SKILL_EFFECT_ID_DATA &data);
BOOL FromJsonDT_SKILL_EFFECT_ID_DATA(Json::Value &root, DT_SKILL_EFFECT_ID_DATA &data);
INT32 EncodeDT_ATTACK_OBJ_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_OBJ_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ATTACK_OBJ_DATA( DT_ATTACK_OBJ_DATA &data );
BOOL FromJsonDT_ATTACK_OBJ_DATA(const string &strData, DT_ATTACK_OBJ_DATA &data);
BOOL FromJsonDT_ATTACK_OBJ_DATA(Json::Value &root, DT_ATTACK_OBJ_DATA &data);
INT32 EncodeDT_ATTACK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ATTACK_DATA( DT_ATTACK_DATA &data );
BOOL FromJsonDT_ATTACK_DATA(const string &strData, DT_ATTACK_DATA &data);
BOOL FromJsonDT_ATTACK_DATA(Json::Value &root, DT_ATTACK_DATA &data);
INT32 EncodeDT_ATTACK_ALL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_ALL_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ATTACK_ALL_DATA( DT_ATTACK_ALL_DATA &data );
BOOL FromJsonDT_ATTACK_ALL_DATA(const string &strData, DT_ATTACK_ALL_DATA &data);
BOOL FromJsonDT_ATTACK_ALL_DATA(Json::Value &root, DT_ATTACK_ALL_DATA &data);
INT32 EncodeDT_BATTLE_ANGRY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ANGRY_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_ANGRY_DATA( DT_BATTLE_ANGRY_DATA &data );
BOOL FromJsonDT_BATTLE_ANGRY_DATA(const string &strData, DT_BATTLE_ANGRY_DATA &data);
BOOL FromJsonDT_BATTLE_ANGRY_DATA(Json::Value &root, DT_BATTLE_ANGRY_DATA &data);
INT32 EncodeDT_BATTLE_ROUND_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ROUND_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_ROUND_DATA( DT_BATTLE_ROUND_DATA &data );
BOOL FromJsonDT_BATTLE_ROUND_DATA(const string &strData, DT_BATTLE_ROUND_DATA &data);
BOOL FromJsonDT_BATTLE_ROUND_DATA(Json::Value &root, DT_BATTLE_ROUND_DATA &data);
INT32 EncodeDT_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_DATA( DT_BATTLE_DATA &data );
BOOL FromJsonDT_BATTLE_DATA(const string &strData, DT_BATTLE_DATA &data);
BOOL FromJsonDT_BATTLE_DATA(Json::Value &root, DT_BATTLE_DATA &data);
INT32 EncodeDT_ONLINE_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONLINE_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ONLINE_ENCOURAGE_RECORD_DATA( DT_ONLINE_ENCOURAGE_RECORD_DATA &data );
BOOL FromJsonDT_ONLINE_ENCOURAGE_RECORD_DATA(const string &strData, DT_ONLINE_ENCOURAGE_RECORD_DATA &data);
BOOL FromJsonDT_ONLINE_ENCOURAGE_RECORD_DATA(Json::Value &root, DT_ONLINE_ENCOURAGE_RECORD_DATA &data);
INT32 EncodeDT_LOGIN_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOGIN_ENCOURAGE_RECORD_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOGIN_ENCOURAGE_RECORD_DATA( DT_LOGIN_ENCOURAGE_RECORD_DATA &data );
BOOL FromJsonDT_LOGIN_ENCOURAGE_RECORD_DATA(const string &strData, DT_LOGIN_ENCOURAGE_RECORD_DATA &data);
BOOL FromJsonDT_LOGIN_ENCOURAGE_RECORD_DATA(Json::Value &root, DT_LOGIN_ENCOURAGE_RECORD_DATA &data);
INT32 EncodeDT_RACE_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RACE_BATTLELOG_DATA( DT_RACE_BATTLELOG_DATA &data );
BOOL FromJsonDT_RACE_BATTLELOG_DATA(const string &strData, DT_RACE_BATTLELOG_DATA &data);
BOOL FromJsonDT_RACE_BATTLELOG_DATA(Json::Value &root, DT_RACE_BATTLELOG_DATA &data);
INT32 EncodeDT_RACE_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RACE_BATTLELOG_DATA_LIST( DT_RACE_BATTLELOG_DATA_LIST &data );
BOOL FromJsonDT_RACE_BATTLELOG_DATA_LIST(const string &strData, DT_RACE_BATTLELOG_DATA_LIST &data);
BOOL FromJsonDT_RACE_BATTLELOG_DATA_LIST(Json::Value &root, DT_RACE_BATTLELOG_DATA_LIST &data);
INT32 EncodeDT_CAPTURE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CAPTURE_DATA( DT_CAPTURE_DATA &data );
BOOL FromJsonDT_CAPTURE_DATA(const string &strData, DT_CAPTURE_DATA &data);
BOOL FromJsonDT_CAPTURE_DATA(Json::Value &root, DT_CAPTURE_DATA &data);
INT32 EncodeDT_CAPTURE_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CAPTURE_DATA_LIST( DT_CAPTURE_DATA_LIST &data );
BOOL FromJsonDT_CAPTURE_DATA_LIST(const string &strData, DT_CAPTURE_DATA_LIST &data);
BOOL FromJsonDT_CAPTURE_DATA_LIST(Json::Value &root, DT_CAPTURE_DATA_LIST &data);
INT32 EncodeDT_PLUNDER_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BATTLELOG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_BATTLELOG_DATA( DT_PLUNDER_BATTLELOG_DATA &data );
BOOL FromJsonDT_PLUNDER_BATTLELOG_DATA(const string &strData, DT_PLUNDER_BATTLELOG_DATA &data);
BOOL FromJsonDT_PLUNDER_BATTLELOG_DATA(Json::Value &root, DT_PLUNDER_BATTLELOG_DATA &data);
INT32 EncodeDT_PLUNDER_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BATTLELOG_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_BATTLELOG_DATA_LIST( DT_PLUNDER_BATTLELOG_DATA_LIST &data );
BOOL FromJsonDT_PLUNDER_BATTLELOG_DATA_LIST(const string &strData, DT_PLUNDER_BATTLELOG_DATA_LIST &data);
BOOL FromJsonDT_PLUNDER_BATTLELOG_DATA_LIST(Json::Value &root, DT_PLUNDER_BATTLELOG_DATA_LIST &data);
INT32 EncodeDT_PLUNDER_GRID_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_GRID_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_GRID_DATA( DT_PLUNDER_GRID_DATA &data );
BOOL FromJsonDT_PLUNDER_GRID_DATA(const string &strData, DT_PLUNDER_GRID_DATA &data);
BOOL FromJsonDT_PLUNDER_GRID_DATA(Json::Value &root, DT_PLUNDER_GRID_DATA &data);
INT32 EncodeDT_PLUNDER_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BASE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_BASE_DATA( DT_PLUNDER_BASE_DATA &data );
BOOL FromJsonDT_PLUNDER_BASE_DATA(const string &strData, DT_PLUNDER_BASE_DATA &data);
BOOL FromJsonDT_PLUNDER_BASE_DATA(Json::Value &root, DT_PLUNDER_BASE_DATA &data);
INT32 EncodeDT_ENEMY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENEMY_DATA( DT_ENEMY_DATA &data );
BOOL FromJsonDT_ENEMY_DATA(const string &strData, DT_ENEMY_DATA &data);
BOOL FromJsonDT_ENEMY_DATA(Json::Value &root, DT_ENEMY_DATA &data);
INT32 EncodeDT_ENEMY_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENEMY_DATA_LIST( DT_ENEMY_DATA_LIST &data );
BOOL FromJsonDT_ENEMY_DATA_LIST(const string &strData, DT_ENEMY_DATA_LIST &data);
BOOL FromJsonDT_ENEMY_DATA_LIST(Json::Value &root, DT_ENEMY_DATA_LIST &data);
INT32 EncodeDT_MONEY_TREE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONEY_TREE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_MONEY_TREE_DATA( DT_MONEY_TREE_DATA &data );
BOOL FromJsonDT_MONEY_TREE_DATA(const string &strData, DT_MONEY_TREE_DATA &data);
BOOL FromJsonDT_MONEY_TREE_DATA(Json::Value &root, DT_MONEY_TREE_DATA &data);
INT32 EncodeDT_STUDY_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STUDY_DATA( DT_STUDY_DATA &data );
BOOL FromJsonDT_STUDY_DATA(const string &strData, DT_STUDY_DATA &data);
BOOL FromJsonDT_STUDY_DATA(Json::Value &root, DT_STUDY_DATA &data);
INT32 EncodeDT_STUDY_CLIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_CLIP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STUDY_CLIP_DATA( DT_STUDY_CLIP_DATA &data );
BOOL FromJsonDT_STUDY_CLIP_DATA(const string &strData, DT_STUDY_CLIP_DATA &data);
BOOL FromJsonDT_STUDY_CLIP_DATA(Json::Value &root, DT_STUDY_CLIP_DATA &data);
INT32 EncodeDT_AWAKEN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_AWAKEN_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_AWAKEN_DATA( DT_AWAKEN_DATA &data );
BOOL FromJsonDT_AWAKEN_DATA(const string &strData, DT_AWAKEN_DATA &data);
BOOL FromJsonDT_AWAKEN_DATA(Json::Value &root, DT_AWAKEN_DATA &data);
INT32 EncodeDT_INSTANCE_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_BATTLE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INSTANCE_BATTLE_DATA( DT_INSTANCE_BATTLE_DATA &data );
BOOL FromJsonDT_INSTANCE_BATTLE_DATA(const string &strData, DT_INSTANCE_BATTLE_DATA &data);
BOOL FromJsonDT_INSTANCE_BATTLE_DATA(Json::Value &root, DT_INSTANCE_BATTLE_DATA &data);
INT32 EncodeDT_PHYSTRENGTH_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PHYSTRENGTH_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PHYSTRENGTH_DATA( DT_PHYSTRENGTH_DATA &data );
BOOL FromJsonDT_PHYSTRENGTH_DATA(const string &strData, DT_PHYSTRENGTH_DATA &data);
BOOL FromJsonDT_PHYSTRENGTH_DATA(Json::Value &root, DT_PHYSTRENGTH_DATA &data);
INT32 EncodeDT_ONHOOK_RESULT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONHOOK_RESULT(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ONHOOK_RESULT( DT_ONHOOK_RESULT &data );
BOOL FromJsonDT_ONHOOK_RESULT(const string &strData, DT_ONHOOK_RESULT &data);
BOOL FromJsonDT_ONHOOK_RESULT(Json::Value &root, DT_ONHOOK_RESULT &data);
INT32 EncodeDT_ONHOOK_RCD_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONHOOK_RCD_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ONHOOK_RCD_DATA( DT_ONHOOK_RCD_DATA &data );
BOOL FromJsonDT_ONHOOK_RCD_DATA(const string &strData, DT_ONHOOK_RCD_DATA &data);
BOOL FromJsonDT_ONHOOK_RCD_DATA(Json::Value &root, DT_ONHOOK_RCD_DATA &data);
INT32 EncodeDT_FEW_PARAM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FEW_PARAM_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FEW_PARAM_DATA( DT_FEW_PARAM_DATA &data );
BOOL FromJsonDT_FEW_PARAM_DATA(const string &strData, DT_FEW_PARAM_DATA &data);
BOOL FromJsonDT_FEW_PARAM_DATA(Json::Value &root, DT_FEW_PARAM_DATA &data);
INT32 EncodeDT_CROP_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_INFO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROP_INFO_DATA( DT_CROP_INFO_DATA &data );
BOOL FromJsonDT_CROP_INFO_DATA(const string &strData, DT_CROP_INFO_DATA &data);
BOOL FromJsonDT_CROP_INFO_DATA(Json::Value &root, DT_CROP_INFO_DATA &data);
INT32 EncodeDT_CROP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROP_DATA( DT_CROP_DATA &data );
BOOL FromJsonDT_CROP_DATA(const string &strData, DT_CROP_DATA &data);
BOOL FromJsonDT_CROP_DATA(Json::Value &root, DT_CROP_DATA &data);
INT32 EncodeDT_SCIENCE_TREE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_TREE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SCIENCE_TREE_DATA( DT_SCIENCE_TREE_DATA &data );
BOOL FromJsonDT_SCIENCE_TREE_DATA(const string &strData, DT_SCIENCE_TREE_DATA &data);
BOOL FromJsonDT_SCIENCE_TREE_DATA(Json::Value &root, DT_SCIENCE_TREE_DATA &data);
INT32 EncodeDT_FORMATION_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_HERO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FORMATION_HERO_DATA( DT_FORMATION_HERO_DATA &data );
BOOL FromJsonDT_FORMATION_HERO_DATA(const string &strData, DT_FORMATION_HERO_DATA &data);
BOOL FromJsonDT_FORMATION_HERO_DATA(Json::Value &root, DT_FORMATION_HERO_DATA &data);
INT32 EncodeDT_FORMATION_IDX_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_IDX_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FORMATION_IDX_DATA( DT_FORMATION_IDX_DATA &data );
BOOL FromJsonDT_FORMATION_IDX_DATA(const string &strData, DT_FORMATION_IDX_DATA &data);
BOOL FromJsonDT_FORMATION_IDX_DATA(Json::Value &root, DT_FORMATION_IDX_DATA &data);
INT32 EncodeDT_FORMATION_DATA_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_DATA_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FORMATION_DATA_LIST( DT_FORMATION_DATA_LIST &data );
BOOL FromJsonDT_FORMATION_DATA_LIST(const string &strData, DT_FORMATION_DATA_LIST &data);
BOOL FromJsonDT_FORMATION_DATA_LIST(Json::Value &root, DT_FORMATION_DATA_LIST &data);
INT32 EncodeDT_FORMATION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FORMATION_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FORMATION_DATA( DT_FORMATION_DATA &data );
BOOL FromJsonDT_FORMATION_DATA(const string &strData, DT_FORMATION_DATA &data);
BOOL FromJsonDT_FORMATION_DATA(Json::Value &root, DT_FORMATION_DATA &data);
INT32 EncodeDT_VERSION_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_VERSION_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_VERSION_DATA( DT_VERSION_DATA &data );
BOOL FromJsonDT_VERSION_DATA(const string &strData, DT_VERSION_DATA &data);
BOOL FromJsonDT_VERSION_DATA(Json::Value &root, DT_VERSION_DATA &data);
INT32 EncodeDT_NOTICE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NOTICE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_NOTICE_DATA( DT_NOTICE_DATA &data );
BOOL FromJsonDT_NOTICE_DATA(const string &strData, DT_NOTICE_DATA &data);
BOOL FromJsonDT_NOTICE_DATA(Json::Value &root, DT_NOTICE_DATA &data);
INT32 EncodeDT_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLAYER_DATA( DT_PLAYER_DATA &data );
BOOL FromJsonDT_PLAYER_DATA(const string &strData, DT_PLAYER_DATA &data);
BOOL FromJsonDT_PLAYER_DATA(Json::Value &root, DT_PLAYER_DATA &data);
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
