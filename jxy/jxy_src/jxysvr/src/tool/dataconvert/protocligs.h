/*       Version Number: 3          */

#ifndef PROTOCLIGS_H_INCLUDE_VERSION_3
#define PROTOCLIGS_H_INCLUDE_VERSION_3

#include "netdata.h"
#include "protocommondata.h"
#include "sdtype.h"
#include "sdstring.h"
#include <json/json.h>
#pragma pack(push, 1)

/*Defines Begin*/
#define MAX_EXT_FUN_NUM          10
#define MAX_CHAT_CONTENT_NUM     512
#define MAX_CHAT_NUM             10
#define PROTOCLIGS_MSGID_RANGE 2265
#define PROTOCLIGS_MSGID_OFFSET 0
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagPKT_CLIGS_ENTERGS_REQ{
	tagPKT_CLIGS_ENTERGS_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTERGS_REQ)); }
	UINT16           wZoneID; //��ID
	TCHAR            aszDeviceID[DEVICEID_LEN]; //��ID
	TCHAR            aszNotifyID[NOTIFYID_LEN]; //��ID
	TCHAR            aszUserName[USERNAME_LEN]; //��ID
	UINT32           dwPlayerID; //���ID�����û���¼��Ч
	UINT16           wCareerID; //ְҵ������Ϸ��Ч
}PKT_CLIGS_ENTERGS_REQ;

typedef struct tagDT_EXT_FUNC_PARAM{
	UINT8            byParam1; //����1
	UINT16           wParam2; //����2
	UINT32           dwParam3; //����3
}DT_EXT_FUNC_PARAM;

typedef struct tagDT_EXT_FUNC_PARAM_LST{
	UINT8            byFuncNum; //��չ������
	DT_EXT_FUNC_PARAM astExtFuncParaInfo[MAX_EXT_FUN_NUM]; //��չ������Ϣ
}DT_EXT_FUNC_PARAM_LST;

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

typedef struct tagDT_SKILL_EFFECT_DATA{
	UINT8            byEffectKindID; //����Ч��ID
	UINT8            byEffectHurtRate; //Ч���˺�����(�ٷֱ�)
	UINT32           dwExtHurtValue; //�����˺�ֵ
	UINT16           wEffectParam; //Ч������
}DT_SKILL_EFFECT_DATA;

typedef struct tagDT_ATTACK_RANG_DATA{
	UINT8            byAttackRangKind; //������Χ����
	UINT8            byTraceBuffKind; //׷�ٵ�buff����(ֻ��AttackRangKindΪEARK_BUFF��Ч)
}DT_ATTACK_RANG_DATA;

typedef struct tagDT_SKILL_DATA_CLI{
	DT_SKILL_DATA    stSkillBaseInfo; //���ܻ�����Ϣ���ȼ�Ϊ0��ʾ�ü����ѿ��ŵ�δѧϰ
	DT_SKILL_EFFECT_DATA stEffectInfo; //����Ч��
	DT_ATTACK_RANG_DATA stAttackRang; //����Ŀ�귶Χ
	UINT8            byBuffNum; //����BUFF
	DT_SKILL_BUFF_DATA astBuffInfo[MAX_SKILL_BUFF_NUM]; //����BUFF
}DT_SKILL_DATA_CLI;

typedef struct tagDT_SKILL_DATA_LIST_CLI{
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_DATA_CLI astSkillInfo[MAX_SKILL_NUM]; //�����б�
}DT_SKILL_DATA_LIST_CLI;

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
	UINT16           wSelectSkillID; //��ѡ����
	UINT16           wSelectSkillLevel; //��ѡ���ܵȼ�
}DT_HERO_BASE_DATA_CLI;

typedef struct tagDT_HERO_UPGRADE_DATA{
	UINT16           wHeroKindID; //�佫����ID
	UINT8            byUpgradeFlag; //�Ƿ�����
	UINT16           wLevel; //��ǰ�ȼ�
	UINT32           dwExperience; //��ǰ����
	UINT32           dwUpgradeExperience; //��һ����������
}DT_HERO_UPGRADE_DATA;

typedef struct tagDT_EQUIP_DATA_STRENGTHEN_CLI{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT16           wLevel; //װ���ȼ�
	UINT16           wDressLevel; //�����ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //��ǰս������
	UINT8            byCanStrengthenFlag; //�Ƿ����ǿ����1����ǿ����0����ǿ��
	UINT32           dwStrengthenCoin; //ǿ�����
	UINT32           dwStrengthenGold; //ǿ��Ԫ��
	UINT16           wStrengthenRate; //ǿ���ɹ���
	DT_BATTLE_ATTRIBUTE stNextBattleAttribute; //��һ��ս������
	UINT32           dwRecoverPrice; //���ռ۸�
}DT_EQUIP_DATA_STRENGTHEN_CLI;

typedef struct tagDT_EQUIP_DATA_CLI{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT8            byDressPos; //����λ��
	UINT16           wLevel; //װ���ȼ�
	UINT16           wDressLevel; //װ�������ȼ�
	DT_BATTLE_ATTRIBUTE stBattleAttribute; //��ǰս������
	UINT32           dwRecoverPrice; //���ռ۸�
	UINT32           dwScience; //��������
}DT_EQUIP_DATA_CLI;

typedef struct tagDT_EQUIP_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI astEquipList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}DT_EQUIP_DATA_LST_CLI;

typedef struct tagDT_HERO_EQUIP_DATA_LST_CLI{
	UINT16           wEquipNum; //װ������
	DT_EQUIP_DATA_CLI astEquipList[EQUIP_POS_NUM]; //װ����Ϣ
}DT_HERO_EQUIP_DATA_LST_CLI;

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
	DT_ESTIMATE_EQUIP_DATA stEquip; //������Ϸ����
	DT_ESTIMATE_DRUG_DATA stDrug; //������Ϸ����
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
	DT_EQUIP_DATA_STRENGTHEN_CLI astEquipStrengthenInfo[MAX_BAG_OPEN_NUM]; //װ��ǿ����Ϣ
	DT_EQUIP_COMPOSE_DATA_CLI astEquipComposeInfo[MAX_BAG_OPEN_NUM]; //װ���ϳ���Ϣ
}DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI;

typedef struct tagDT_SEED_DATA_CLI{
	UINT8            byType; //��������
	UINT16           wValue; //����ֵ
	UINT16           wKindID; //��ȡ����ƷID
}DT_SEED_DATA_CLI;

typedef struct tagDT_GOODS_DATA_CLI{
	UINT16           wKindID; //��Ʒ����
	UINT8            byGoodsMainKindID; //��Ʒ����
	UINT16           wUseLevel; //ʹ�õȼ�
	UINT16           wPileCount; //������
	UINT32           dwRecoverPrice; //���ռ۸�
	UINT32           dwValue; //ʹ��Ч��ֵ(��ͬ��Ʒ��ͬ����)
	UINT16           wComposeCount; //��Ʒ�ϳɸ���
	UINT16           wComposeKindID; //��Ʒ�ϳ�ID
	UINT8            byComposeItemNum; //���Ϻϳɵĵ���/����еĵ���
	UINT16           awComposeItem[MAX_COMPOSE_ITEM_NUM]; //������Ϣ
	UINT8            bySeedFlag; //���ӱ�־
	DT_SEED_DATA_CLI astSeedData[1]; //������Ϣ
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
	DT_EQUIP_DATA_CLI stEquip; //������Ϸ����
	DT_GOODS_DATA_CLI stGoods; //������Ϸ����
}DT_ITEM_DATA_UNOIN;

typedef struct tagDT_ITEM_DATA_CLI2{
	UINT8            byItemType; //��������
	DT_ITEM_DATA_UNOIN stItemInfo; //��������
}DT_ITEM_DATA_CLI2;

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
	DT_GIVEN_TASK_DATA stGivenTask; //������Ϸ����
	DT_ACCEPT_TASK_DATA stAcceptTask; //������Ϸ����
	DT_ENCOURAGE_TASK_DATA stEncourageTask; //������Ϸ����
	DT_INVALID_TASK_DATA stInvalidTask; //������Ϸ����
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

typedef struct tagDT_PHYSTRENGTH_DATA_CLI{
	UINT16           wPhyStrength; //��ǰ����
	UINT16           wMaxPhyStrength; //��������
	UINT16           wPhyStrengthRefreshCD; //����ˢ�¼��,��λs
	UINT16           wPhyStrengthCountDown; //����ˢ�µ���ʱ
}DT_PHYSTRENGTH_DATA_CLI;

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
	UINT32           dwGuide; //��ǰ��Ҫ��������
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

typedef struct tagPKT_CLIGS_ENTERGS_ACK{
	tagPKT_CLIGS_ENTERGS_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTERGS_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
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
	UINT8            byUnreadRaceBattleLogNum; //δ�ۿ�������ս������
	UINT8            byUnreadPlunderBattleLogNum; //δ�ۿ��Ӷ�ս������
	UINT16           wJuniorLevel; //���ֵȼ�
	DT_EXT_FUNC_PARAM_LST stExtFuncParamLst; //��չ���ܲ����б�
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
	DT_SKILL_DATA_LIST_CLI astSkillInfo[MAX_HERO_NUM]; //�佫������Ϣ
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
	DT_PLAYER_BATTLE_INFO stPlayerBattleInfo; //���ս����Ϣ
	DT_HERO_DATA_CLI stHeroInfo; //�佫��Ϣ
	UINT8            byEquipBagFlag; //�Ƿ�װ��������Ϣ
	DT_EQUIP_BAG_DATA_CLI astEquipBagDataInfo[1]; //δװ����װ����Ϣ
	UINT8            byGoodsCellNum; //��Ʒռ�ø�����
}PKT_CLIGS_GET_HERO_INFO_ACK;

typedef struct tagDT_FUNC_COMMON_PROMPT{
	UINT8            byBuildKindID; //��������
	UINT8            byFuncFlag; //��������(0������ʾ��>0��ͬ��ֵ��ͬ������ʾ��ͬ����)
	UINT32           dwFuncCountDown; //���ܵĵ���ʱ
	UINT8            byExt; //��չ�ֶ�
}DT_FUNC_COMMON_PROMPT;

typedef struct tagDT_FUNC_PROMPT_DATA{
	UINT8            byBuildNum; //��������
	DT_FUNC_COMMON_PROMPT astBuildPromptInfo[MAX_BUILD_NUM]; //������ʾ��Ϣ
}DT_FUNC_PROMPT_DATA;

typedef struct tagDT_OTHER_PROMPT_DATA{
	UINT8            byHaveBetterHeroFlag; //�Ƿ��и�ǿ������ļ��1�У�0û��
}DT_OTHER_PROMPT_DATA;

typedef struct tagDT_NEW_EQUIP_PROMPT_DATA{
	UINT8            byEquipNum; //װ������
	UINT16           awEquipIDInfo[EQUIP_POS_NUM]; //װ��������Ϣ
	UINT16           wHeroID; //�������ĵ�һ�����(װ����������0��Ч)��0��ʾû��
}DT_NEW_EQUIP_PROMPT_DATA;

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
	UINT8            byUnreadRaceBattleLogNum; //δ�ۿ�������ս������
	UINT8            byUnreadPlunderBattleLogNum; //δ�ۿ��Ӷ�ս������
	UINT16           awUnlockHeroID[MAX_UNLOCK_HERO_NUM]; //���������ʾ(0��ʾû��)
	UINT16           wUnlockEquipLevel; //����װ����ʾ(0��ʾû��)
	UINT32           dwUnlockElite; //������Ӣ������ʾ(0��ʾû�У���1���ֽڱ�ʾ��Ӣ��������idx����2/3���ֽڱ�ʾ������ID)
	UnlockScienceInfo stUnlockScienceList; //�����Ƽ���ʾ
	UINT32           dwGuide; //��ǰ��Ҫ��������
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
	DT_OTHER_PROMPT_DATA stOtherPromptInfo; //������ʾ��Ϣ
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
	UINT16           wEliteUnBattleNum; //δ��ľ�Ӣ��������
}PKT_CLIGS_ENTER_HOME_ACK;

typedef struct tagDT_BATTLE_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwExperience; //����
	UINT32           dwStory; //����
}DT_BATTLE_ENCOURAGE_DATA;

typedef struct tagDT_DATA_AFTER_BATTLE_ENCOURAGE{
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurStory; //��ǰ����
	UINT8            byHeroNum; //�佫����
	DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
}DT_DATA_AFTER_BATTLE_ENCOURAGE;

typedef struct tagDT_RACE_CHALLENGE_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwScience; //�����
}DT_RACE_CHALLENGE_ENCOURAGE_DATA;

typedef struct tagDT_RACE_RANK_ENCOURAGE_DATA{
	UINT32           dwCoin; //ͭǮ
	UINT32           dwScience; //�����
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
	UINT32           dwExperience; //��������
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
}DT_PASS_ENCOURAGE_BOX_GROUP_DATA;

typedef struct tagDT_PASS_ENCOURAGE_BOX_DATA{
	UINT8            byGroupNum; //���������
	DT_PASS_ENCOURAGE_BOX_GROUP_DATA astBoxGroupInfo[MAX_ENCOURAGE_BOX_GROUP_NUM]; //��������Ϣ
}DT_PASS_ENCOURAGE_BOX_DATA;

typedef struct tagPKT_CLIGS_ENTER_INSTANCE_ACK{
	tagPKT_CLIGS_ENTER_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_ENTER_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_PHYSTRENGTH_DATA_CLI stPhyStrengthInfo; //������Ϣ
	UINT32           dwMaxHP; //��HP���������������佫���ԣ�
	UINT32           dwCurHP; //��ǰHP���������������佫���ԣ�
	DT_MONSTER_DATA_LIST stMonsterInfo; //������Ϣ
	UINT8            byHaveBoxFlag; //�Ƿ��н������䣬1Ϊ�б���
	DT_PASS_ENCOURAGE_BOX_DATA astBoxInfo[1]; //����������Ϣ
	UINT16           wDoubleExpNum; //����˫��������������0��ʾ��ʹ��˫����
}PKT_CLIGS_ENTER_INSTANCE_ACK;

typedef struct tagPKT_CLIGS_BATTLE_REQ{
	tagPKT_CLIGS_BATTLE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_BATTLE_REQ)); }
	UINT8            byBattleIndex; //ս�����(�ڼ����֣���1��ʼ)
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

typedef struct tagPKT_CLIGS_BATTLE_ACK{
	tagPKT_CLIGS_BATTLE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_BATTLE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BATTLE_DATA   stBattleInfo; //ս����Ϣ
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
	UINT32           dwGuide; //��ǰ��Ҫ��������
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_BATTLE_ACK;

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

typedef struct tagPKT_CLIGS_GET_SCENE_INSTANCE_ACK{
	tagPKT_CLIGS_GET_SCENE_INSTANCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_SCENE_INSTANCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wIndex; //�������
	UINT8            byEnterPhyStrength; //��������Ҫ��
	DT_INSTANCE_ID   stMaxInstanceData; //��󸱱���Ϣ
	DT_INSTANCE_ID   stMaxUnlockInstance; //����������Ϣ
	UINT8            byTownNum; //������
	DT_TOWN_INSTANCE_RECORD_DATA_CLI astTownInstanceInfo[MAX_TOWN_PER_SCENE_NUM]; //���򸱱���Ϣ
}PKT_CLIGS_GET_SCENE_INSTANCE_ACK;

typedef struct tagPKT_CLIGS_EQUIP_STRENGTHEN_REQ{
	tagPKT_CLIGS_EQUIP_STRENGTHEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_STRENGTHEN_REQ)); }
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
	UINT8            byStrengthenType; //ǿ����ʽ��0��ң�1Ԫ��
	UINT16           wLevel; //Ҫ�����ĵȼ�(ÿ��ֻ����1��)
}PKT_CLIGS_EQUIP_STRENGTHEN_REQ;

typedef struct tagPKT_CLIGS_EQUIP_STRENGTHEN_ACK{
	tagPKT_CLIGS_EQUIP_STRENGTHEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_EQUIP_STRENGTHEN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //װ��ǿ����Ϣ
	DT_EQUIP_COMPOSE_DATA_CLI stEquipComposeInfo; //װ���ϳ���Ϣ
	UINT16           wStrengthenCountDown; //װ��ǿ������ʱ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT32           dwPlayerMaxHP; //��ҵ�ǰ��Ѫ��
	UINT32           dwPlayerCurHP; //��ҵ�ǰѪ��(�ڸ�������Ч)
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
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
}PKT_CLIGS_OPEN_SMITHY_ACK;

typedef struct tagPKT_CLIGS_OPEN_RECRUIT_REQ{
	tagPKT_CLIGS_OPEN_RECRUIT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECRUIT_REQ)); }
	UINT8            byBuildKindID; //��������
}PKT_CLIGS_OPEN_RECRUIT_REQ;

typedef struct tagDT_HERO_ATTR_ADD_CLI{
	UINT32           dwAddAttack; //����
	UINT32           dwAddHP; //Ѫ��
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
	UINT8            byRecuitUnLock; //�Ƿ�ɲ���
}DT_RECRUIT_HERO_DATA;

typedef struct tagPKT_CLIGS_OPEN_RECRUIT_ACK{
	tagPKT_CLIGS_OPEN_RECRUIT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_RECRUIT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
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
	UINT32           dwGuide; //��ǰ��Ҫ��������
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

typedef struct tagPKT_CLIGS_OPEN_BAG_REQ{
	tagPKT_CLIGS_OPEN_BAG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAG_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_BAG_REQ;

typedef struct tagPKT_CLIGS_OPEN_BAG_ACK{
	tagPKT_CLIGS_OPEN_BAG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_BAG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_BAG_DATA_CLI  stBagInfo; //����������Ϣ
	DT_ITEM_DATA_LIST_CLI2 stBagItemInfo; //����������Ϣ
}PKT_CLIGS_OPEN_BAG_ACK;

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
	UINT32           dwGuide; //��ǰ��Ҫ��������
	UINT64           qwStory; //����
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
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
	UINT32           dwPower; //ս��
	UINT32           dwFirstAttack; //�ȹ�ֵ
	UINT8            byHaveRecvEncourageFlag; //�����Ƿ���ȡ����������
	DT_RACE_RANK_ENCOURAGE_DATA stTodayRankEncourage; //���տ���ȡ����������(δ��ȡ��Ч)
	DT_RACE_RANK_ENCOURAGE_DATA stTomorrowRankEncourage; //���տ���ȡ����������
	UINT16           wCanChallengeNum; //��ҵ�ǰ����ս����
	UINT16           wFreeChallengeNum; //���տ������ս����
	UINT32           dwChallengeNeedGold; //�շ���ս��Ԫ����
	UINT16           wChallengeCountDown; //��ս����ʱ����λ��
	UINT32           dwClrCDGold; //���CD����Ԫ��(ÿ����)
	UINT8            byChallengeNum; //��ս��Ҹ���
	DT_CHALLENGE_PLAYER_DATA astChallengePlayerList[MAX_CHALLENGE_NUM]; //��ս�����Ϣ�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //������ʾ��Ϣ
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

typedef struct tagPKT_CLIGS_CHALLENGE_ACK{
	tagPKT_CLIGS_CHALLENGE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHALLENGE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_CHALLENGE_PLAYER_DATA stEnemyPlayerData; //�Է������Ϣ
	UINT8            byEnemyHeroNum; //�Է���Ϣ
	DT_ENEMY_HERO_DATA astEnemyInfoList[MAX_FORMATION_IDX_NUM]; //�Է���Ϣ
	DT_BATTLE_DATA   stBattleInfo; //ս����Ϣ
	DT_RACE_CHALLENGE_ENCOURAGE_DATA stChallengeEncourage; //��ս����
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ����
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_CHALLENGE_ACK;

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
	UINT16           wErrCode; //������Ϸ����
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
	UINT8            bySkillNum; //������
	DT_SKILL_DATA_CLI astSkillInfo[MAX_SKILL_SLOT_NUM]; //������Ϣ
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

typedef struct tagPKT_CLIGS_OPEN_ITEM_MAKER_REQ{
	tagPKT_CLIGS_OPEN_ITEM_MAKER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ITEM_MAKER_REQ)); }
	UINT16           wItemKindID; //��������������
}PKT_CLIGS_OPEN_ITEM_MAKER_REQ;

typedef struct tagDT_EQUIP_DATA_MAKER_NEED{
	UINT16           wKindID; //װ������
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��(0��ʾû�и�װ��)
	UINT16           wHeroKindID; //װ�����佫ID��0Ϊδװ��
	UINT16           wLevel; //װ���ȼ�
	DT_INSTANCE_ID   stBurstInstance; //���ܵ���ĸ���
}DT_EQUIP_DATA_MAKER_NEED;

typedef struct tagPKT_CLIGS_OPEN_ITEM_MAKER_ACK{
	tagPKT_CLIGS_OPEN_ITEM_MAKER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_ITEM_MAKER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byEquipNum; //װ������
	DT_EQUIP_DATA_MAKER_NEED astEquipList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
	UINT8            byItemNum; //������߸���
	DT_NEED_ITEM_DATA astItemInfoList[MAX_ITEM_MAKER_NEED_NUM]; //���������Ϣ
	UINT8            byEstimateItemNum; //���߸���
	DT_ESTIMATE_ITEM_DATA astEstimateItemList[MAX_BAG_OPEN_NUM]; //������Ϣ�б�
}PKT_CLIGS_OPEN_ITEM_MAKER_ACK;

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
}PKT_CLIGS_MAKE_ITEM_ACK;

typedef struct tagDT_DRUG_DATA_CLI{
	UINT8            byLevel; //��ҩ�ȼ�(Ʒ)
	UINT8            byUsedNum; //�ѷ��ø���
	UINT8            byOddNum; //ʣ����ø���
	UINT16           wBaseTalent; //��Ϊ�����ӳ�ֵ
	UINT16           wDecTalent; //ÿ��ʹ��1����Ϊ�ӳɵݼ�ֵ
}DT_DRUG_DATA_CLI;

typedef struct tagDT_DRUG_DATA_LST_CLI{
	UINT8            byNum; //��ҩ����
	DT_DRUG_DATA_CLI astDrugList[MAX_DRUG_LEVEL]; //��ҩ��Ϣ
}DT_DRUG_DATA_LST_CLI;

typedef struct tagPKT_CLIGS_GET_HERO_DRUG_REQ{
	tagPKT_CLIGS_GET_HERO_DRUG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_HERO_DRUG_REQ)); }
	UINT16           wHeroKindID; //�佫����ID
	UINT8            byNeedDrugItemFlag; //�Ƿ���Ҫ���ص�ҩ������Ϣ,1Ϊ��Ҫ
}PKT_CLIGS_GET_HERO_DRUG_REQ;

typedef struct tagDT_DRUG_ITEM_DATA{
	UINT16           wKindID; //��Ʒ����
	UINT16           wUseLevel; //ʹ�õȼ�
	UINT16           wPileCount; //������
	UINT16           wDrugLevel; //��ҩ�ȼ�
	UINT16           wBaseTalent; //��Ϊ�����ӳ�ֵ
	UINT16           wDecTalent; //ÿ��ʹ��1����Ϊ�ӳɵݼ�ֵ
}DT_DRUG_ITEM_DATA;

typedef struct tagDT_DRUG_ITEM_DATA_LST{
	UINT16           wItemNum; //����
	DT_DRUG_ITEM_DATA astDrugItemLst[MAX_BAG_OPEN_NUM]; //��Ϣ
}DT_DRUG_ITEM_DATA_LST;

typedef struct tagPKT_CLIGS_GET_HERO_DRUG_ACK{
	tagPKT_CLIGS_GET_HERO_DRUG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_GET_HERO_DRUG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫����ID
	DT_DRUG_DATA_LST_CLI stDrugInfo; //�佫��ҩ��Ϣ
	UINT8            byHaveDrugItemFlag; //�Ƿ��е�ҩ������Ϣ��1Ϊ��
	DT_DRUG_ITEM_DATA_LST astDrugItemInfo[1]; //��ҩ������Ϣ
}PKT_CLIGS_GET_HERO_DRUG_ACK;

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
}PKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK;

typedef struct tagDT_DATA_AFTER_PASS_ENCOURAGE_BOX{
	UINT64           qwCurCoin; //ͭǮ
	UINT64           qwCurGold; //Ԫ��
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
	UINT32           dwGuide; //��ǰ��Ҫ��������
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
	UINT32           dwExperience; //��ǰ����
	UINT32           dwUpgradeExperience; //��һ����������
}DT_HERO_UPGRADE_DATA2;

typedef struct tagDT_DATA_AFTER_ONHOOK{
	UINT8            byUpgradeHeroNum; //�����佫����
	DT_HERO_UPGRADE_DATA2 astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM]; //�佫������Ϣ
	UINT64           qwCurCoin; //��ǰͭǮ
	UINT64           qwCurGold; //��ǰԪ��
	UINT64           qwCurStory; //����
	DT_PHYSTRENGTH_DATA_CLI stCurPhyStrengthInfo; //��ǰ���������Ϣ
	DT_EXPERIENCE_DATA stExperienceInfo; //������Ϣ
	UINT16           wUnlockEquipLevel; //����װ����ʾ(0��ʾû��)
	UnlockScienceInfo stUnlockScienceList; //�����Ƽ���ʾ
	UINT8            byUnlockNewInstanceFlag; //�Ƿ�����¸���
	DT_INSTANCE_ID   astUnlockCommonInstanceID[1]; //��������ͨ����ID
	UINT8            byHaveNewInstanceFlag; //�Ƿ����¿ɴ���ͨ����,1��Ч
	DT_INSTANCE_DATA_CLI astNewCommonInstanceID[1]; //�¿ɴ���ͨ����ID
}DT_DATA_AFTER_ONHOOK;

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
	TCHAR            aszDspName[USERNAME_LEN]; //������Ϸ����
}PKT_CLILS_REGISTER_DSPNAME_REQ;

typedef struct tagPKT_CLILS_REGISTER_DSPNAME_ACK{
	tagPKT_CLILS_REGISTER_DSPNAME_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_REGISTER_DSPNAME_ACK)); }
	UINT16           wErrCode; //������Ϸ����
	TCHAR            aszDspName[USERNAME_LEN]; //������Ϸ����
}PKT_CLILS_REGISTER_DSPNAME_ACK;

typedef struct tagPKT_CLILS_USE_GOODS_REQ{
	tagPKT_CLILS_USE_GOODS_REQ() { memset(this, 0, sizeof(tagPKT_CLILS_USE_GOODS_REQ)); }
	UINT16           wGoodsKindID; //��Ʒ����ID
}PKT_CLILS_USE_GOODS_REQ;

typedef struct tagPKT_CLILS_USE_GOODS_ACK{
	tagPKT_CLILS_USE_GOODS_ACK() { memset(this, 0, sizeof(tagPKT_CLILS_USE_GOODS_ACK)); }
	UINT16           wErrCode; //������Ϸ����
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
	UINT16           wErrCode; //������Ϸ����
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
	UINT16           wErrCode; //������Ϸ����
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

typedef struct tagPKT_CLIGS_PLUNDER_ACK{
	tagPKT_CLIGS_PLUNDER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PLUNDER_ACK)); }
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
	DT_BATTLE_DATA   stBattleInfo; //ս����Ϣ
	DT_PLUNDER_ENCOURAGE_DATA stPlunderEncourage; //�Ӷά��
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭ��
	UINT64           qwCurScience; //��ҵ�ǰ�������
	UINT64           qwCurGold; //��ҵ�ǰ��Ԫ��
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
	UINT16           wFreePlunderNum; //�������Ӷ����
	UINT32           dwPlunderGold; //�շ��Ӷ�Ԫ��(��������ѵ���Ϊ0)
	UINT16           wPlunderItemNum; //��ǰӵ�е��Ӷ����
	UINT8            byCaptureFlag; //�Ƿ��²��ң�1Ϊ�Է���Ϊ��ķ�²
	DT_CAPTURE_DATA_CLI astCaptureInfo[1]; //��²��Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_PLUNDER_ACK;

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
	UINT16           wCanPlunderNum; //��ҵ�ǰ���Ӷ����
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
	UINT16           wCareerID; //ְҵ
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

typedef struct tagDT_GODWEAPON_ATTR_INC_DATA{
	UINT8            byAttrKind; //��������
	UINT32           dwAttrValue; //����ֵ
}DT_GODWEAPON_ATTR_INC_DATA;

typedef struct tagDT_GODWEAPON_ATTR_DATA{
	DT_BATTLE_ATTRIBUTE stBattleAttr; //ս������
	DT_HIDE_BATTLE_ATTRIBUTE stHideBattleAttr; //���ص�ս������
	DT_EXT_BATTLE_ATTRIBUTE stExtBattleAttr; //��չ��ս������
}DT_GODWEAPON_ATTR_DATA;

typedef struct tagDT_GODWEAPON_DATA_CLI{
	UINT16           wHeroKindID; //�佫����ID
	UINT16           wQuality; //Ʒ��
	UINT16           wLevel; //�ȼ�
	DT_GODWEAPON_ATTR_DATA stIncAttr; //��������������
	DT_GODWEAPON_ATTR_INC_DATA stNextLevelIncAttr; //��һ������������
	UINT16           wQualityRequireLevel; //����������ҵȼ�Ҫ��
	UINT32           dwUpgrageScience; //��һ������������(�Ƽ�)��
	UINT64           qwRecoverScience; //�ͷ���������������(�Ƽ�)��
	UINT16           wUpgradeQualityNeedItemNum; //������Ҫ�Ľ��׵��߸���
	UINT8            byMaxLevelFlag; //�Ǵﵽ���ȼ�(1Ϊ�ﵽ���ȼ�)
	DT_GODWEAPON_ATTR_INC_DATA astQualityUpgradeEncAttr[MAX_GODWEAPON_QUALITY_NUM]; //����Ʒ��������������
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
}PKT_CLIGS_FREE_GODWEAPON_REQ;

typedef struct tagPKT_CLIGS_FREE_GODWEAPON_ACK{
	tagPKT_CLIGS_FREE_GODWEAPON_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_FREE_GODWEAPON_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫����ID
	UINT64           qwPlayerScience; //��ҵ�ǰ������(�Ƽ�)��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
	DT_GODWEAPON_DATA_CLI stGodweaponInfo; //������Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_FREE_GODWEAPON_ACK;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_REQ{
	tagPKT_CLIGS_OPEN_AWAKEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_AWAKEN_REQ;

typedef struct tagPKT_CLIGS_OPEN_AWAKEN_ACK{
	tagPKT_CLIGS_OPEN_AWAKEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_AWAKEN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_AWAKEN_DATA   stAwakenInfo; //�����Ϣ
	UINT32           dwAwakenCoin; //�������ͭ��
	UINT32           dwStudyClipColorExp; //�ĵþ�����Ƭ��ɫ�ľ���ֵ
	UINT8            abyGridStudyClipColor[MAX_GRID_STUDY_CLIP_NUM]; //��Ÿ��ӵ��ĵ���Ƭ��Ϣ(��ɫΪ0��û��)
	UINT16           awPickupStudyClipNum[STUDY_COLOR_NUM]; //��ʰȡ���ĵ���Ƭ��Ϣ(����Ϊ0��û��)
}PKT_CLIGS_OPEN_AWAKEN_ACK;

typedef struct tagPKT_CLIGS_AWAKEN_REQ{
	tagPKT_CLIGS_AWAKEN_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_AWAKEN_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_AWAKEN_REQ;

typedef struct tagPKT_CLIGS_AWAKEN_ACK{
	tagPKT_CLIGS_AWAKEN_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_AWAKEN_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byAwakenLevel; //����ȼ�
	UINT8            byStudyColor; //��������ĵ�(�ĵ���ɫ)
	UINT32           dwStudyExp; //��������ĵþ���
	UINT32           dwAwakenCoin; //�������ͭ��
	UINT64           qwPlayerCoin; //��ҵ�ǰ��ͭ��
}PKT_CLIGS_AWAKEN_ACK;

typedef struct tagPKT_CLIGS_PICKUP_STUDY_CLIP_REQ{
	tagPKT_CLIGS_PICKUP_STUDY_CLIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_PICKUP_STUDY_CLIP_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_PICKUP_STUDY_CLIP_REQ;

typedef struct tagPKT_CLIGS_PICKUP_STUDY_CLIP_ACK{
	tagPKT_CLIGS_PICKUP_STUDY_CLIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_PICKUP_STUDY_CLIP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwStudyExp; //��ҵ�ǰ���ĵþ���
	UINT16           awPickupStudyClipNum[STUDY_COLOR_NUM]; //��ʰȡ���ĵ���Ƭ��Ϣ(����Ϊ0��û��)
}PKT_CLIGS_PICKUP_STUDY_CLIP_ACK;

typedef struct tagPKT_CLIGS_OPEN_STUDY_REQ{
	tagPKT_CLIGS_OPEN_STUDY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STUDY_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_STUDY_REQ;

typedef struct tagDT_STUDY_DATA_CLI{
	UINT8            byKind; //�ĵ�����
	UINT8            byColor; //��ɫ
	UINT8            byLevel; //�ȼ�
	UINT8            byPos; //���λ��
	UINT8            byAttrKind; //�ĵ�Ӱ����������
	UINT32           dwAttrValue; //�ĵ�Ӱ������ֵ
}DT_STUDY_DATA_CLI;

typedef struct tagDT_STUDY_DATA_LST_CLI{
	UINT8            byNum; //�ĵø���
	DT_STUDY_DATA_CLI astStudyLst[MAX_STUDY_STORE_NUM]; //�ĵ���Ϣ�б�
}DT_STUDY_DATA_LST_CLI;

typedef struct tagDT_HERO_STUDY_DATA_CLI{
	UINT16           wHeroID; //�佫ID
	DT_STUDY_DATA_LST_CLI stStudyInfo; //�ĵ���Ϣ
}DT_HERO_STUDY_DATA_CLI;

typedef struct tagDT_HERO_STUDY_DATA_LST_CLI{
	UINT8            byNum; //�佫����
	DT_HERO_STUDY_DATA_CLI astHeroStudyLst[MAX_FORMATION_IDX_NUM]; //�佫�ĵ���Ϣ
}DT_HERO_STUDY_DATA_LST_CLI;

typedef struct tagPKT_CLIGS_OPEN_STUDY_ACK{
	tagPKT_CLIGS_OPEN_STUDY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STUDY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwStudyExp; //��ҵ�ǰ���ĵþ���
	UINT16           awPickupStudyClipNum[STUDY_COLOR_NUM]; //��ʰȡ���ĵ���Ƭ��Ϣ(����Ϊ0��û��)
	DT_STUDY_DATA_LST_CLI stStoreStudyInfo; //�ĵô洢������Ϣ
	DT_HERO_STUDY_DATA_LST_CLI stHeroStudyInfo; //�佫�ĵ���Ϣ
}PKT_CLIGS_OPEN_STUDY_ACK;

typedef struct tagPKT_CLIGS_DRESS_STUDY_REQ{
	tagPKT_CLIGS_DRESS_STUDY_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_STUDY_REQ)); }
	UINT8            byOpPos; //��������(0�佫�ĵã�1�洢�ĵã�2�佫�ʹ洢����)
	UINT16           wHeroKindID; //�佫ID
	UINT8            byDressType; //������ʽ(����(SrcPosΪ�洢�ĵ�)/ж��(SrcPosΪ�佫�ĵ�)/�滻(SrcPosΪ�洢�ĵ�))
	UINT8            bySrcPos; //Դλ��
	UINT8            byDstPos; //Ŀ��λ��
}PKT_CLIGS_DRESS_STUDY_REQ;

typedef struct tagPKT_CLIGS_DRESS_STUDY_ACK{
	tagPKT_CLIGS_DRESS_STUDY_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_STUDY_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID
	UINT8            byDressType; //������ʽ(����(SrcPosΪ�洢�ĵ�)/ж��(SrcPosΪ�佫�ĵ�)/�滻(SrcPosΪ�洢�ĵ�))
	UINT8            bySrcPos; //Դλ��
	UINT8            byDstPos; //Ŀ��λ��
}PKT_CLIGS_DRESS_STUDY_ACK;

typedef struct tagPKT_CLIGS_STUDY_CLIP_TO_EXP_REQ{
	tagPKT_CLIGS_STUDY_CLIP_TO_EXP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_CLIP_TO_EXP_REQ)); }
	UINT8            byColor; //�ĵ���ɫ
	UINT16           wNum; //�ĵø���
}PKT_CLIGS_STUDY_CLIP_TO_EXP_REQ;

typedef struct tagPKT_CLIGS_STUDY_CLIP_TO_EXP_ACK{
	tagPKT_CLIGS_STUDY_CLIP_TO_EXP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_CLIP_TO_EXP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwStudyExp; //��ҵ�ǰ���ĵþ���
	UINT16           awPickupStudyClipNum[STUDY_COLOR_NUM]; //��ʰȡ���ĵ���Ƭ��Ϣ(����Ϊ0��û��)
}PKT_CLIGS_STUDY_CLIP_TO_EXP_ACK;

typedef struct tagPKT_CLIGS_STUDY_TO_EXP_REQ{
	tagPKT_CLIGS_STUDY_TO_EXP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_TO_EXP_REQ)); }
	UINT16           wHeroKindID; //�佫ID(0��Ϊ�洢���ĵã���0��Ϊ�佫�ĵ�)
	UINT8            byPosIdx; //λ�����
}PKT_CLIGS_STUDY_TO_EXP_REQ;

typedef struct tagPKT_CLIGS_STUDY_TO_EXP_ACK{
	tagPKT_CLIGS_STUDY_TO_EXP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_TO_EXP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID(0��Ϊ�洢���ĵã���0��Ϊ�佫�ĵ�)
	UINT8            byPosIdx; //λ�����
	UINT64           qwStudyExp; //��ҵ�ǰ���ĵþ���
	UINT16           awPickupStudyClipNum[STUDY_COLOR_NUM]; //��ʰȡ���ĵ���Ƭ��Ϣ(����Ϊ0��û��)
	UINT8            byHeroStudyFlag; //�佫�ĵñ�־��1Ϊ�佫�ĵ�
	DT_STUDY_DATA_LST_CLI astHeroStudyInfo[1]; //�佫�ĵ���Ϣ
}PKT_CLIGS_STUDY_TO_EXP_ACK;

typedef struct tagPKT_CLIGS_OPEN_STUDY_CONVERT_REQ{
	tagPKT_CLIGS_OPEN_STUDY_CONVERT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STUDY_CONVERT_REQ)); }
	UINT8            byExt; //��չ��Ϣ��δʹ��
}PKT_CLIGS_OPEN_STUDY_CONVERT_REQ;

typedef struct tagDT_STUDY_CFG_DATA{
	UINT8            byKind; //�ĵ�����
	UINT8            byColor; //��ɫ
	UINT8            byAttrKind; //�ĵ�Ӱ����������
	UINT32           dwAttrValue; //�ĵ�Ӱ������ֵ
	UINT32           dwIncAttrValue; //ÿ��1�����ӵ�����ֵ
	UINT16           wNeedClipNum; //�һ�������Ƭ����
}DT_STUDY_CFG_DATA;

typedef struct tagPKT_CLIGS_OPEN_STUDY_CONVERT_ACK{
	tagPKT_CLIGS_OPEN_STUDY_CONVERT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_STUDY_CONVERT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_STUDY_CFG_DATA astStudyCfgInfo[MAX_STUDY_KIND_NUM]; //�����ĵ�����������Ϣ
}PKT_CLIGS_OPEN_STUDY_CONVERT_ACK;

typedef struct tagPKT_CLIGS_STUDY_CONVERT_REQ{
	tagPKT_CLIGS_STUDY_CONVERT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_CONVERT_REQ)); }
	UINT8            byKind; //�ĵ�����
	UINT8            byColor; //��ɫ
}PKT_CLIGS_STUDY_CONVERT_REQ;

typedef struct tagPKT_CLIGS_STUDY_CONVERT_ACK{
	tagPKT_CLIGS_STUDY_CONVERT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_CONVERT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_STUDY_CONVERT_ACK;

typedef struct tagPKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ{
	tagPKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ)); }
	UINT8            bySellectFlag; //ѡ������,0��ѡ��1ѡ��
}PKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ;

typedef struct tagPKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK{
	tagPKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            bySellectFlag; //ѡ������,0��ѡ��1ѡ��
}PKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK;

typedef struct tagPKT_CLIGS_STUDY_UPGRADE_REQ{
	tagPKT_CLIGS_STUDY_UPGRADE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_UPGRADE_REQ)); }
	UINT16           wHeroKindID; //�佫ID
	UINT8            byPos; //Դλ��
	UINT8            byLevel; //Ҫ�������ĵȼ�
}PKT_CLIGS_STUDY_UPGRADE_REQ;

typedef struct tagPKT_CLIGS_STUDY_UPGRADE_ACK{
	tagPKT_CLIGS_STUDY_UPGRADE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_STUDY_UPGRADE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wHeroKindID; //�佫ID
	UINT8            byPos; //Դλ��
	UINT8            byLevel; //Ҫ�������ĵȼ�
	DT_HERO_STUDY_DATA_CLI stHeroStudyInfo; //�佫�ĵ���Ϣ
}PKT_CLIGS_STUDY_UPGRADE_ACK;

typedef struct tagPKT_CLIGS_RACE_BATTLELOG_NTF{
	tagPKT_CLIGS_RACE_BATTLELOG_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_RACE_BATTLELOG_NTF)); }
	UINT8            byUnreadNum; //δ�ۿ�ս������
	DT_RACE_BATTLELOG_DATA_CLI stBattleLog; //ս��
	UINT64           qwPlayerCoin; //��ҵ�ǰͭ��
	UINT64           qwPlayerScience; //��ҵ�ǰ�����
}PKT_CLIGS_RACE_BATTLELOG_NTF;

typedef struct tagDT_LOCK_SKILL_DATA{
	UINT16           wSkillID; //����ID
	DT_INSTANCE_ID   stUnlockInstanceID; //��������
}DT_LOCK_SKILL_DATA;

typedef struct tagPKT_CLIGS_OPEN_SKILL_TAB_REQ{
	tagPKT_CLIGS_OPEN_SKILL_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SKILL_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδ��
}PKT_CLIGS_OPEN_SKILL_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_SKILL_TAB_ACK{
	tagPKT_CLIGS_OPEN_SKILL_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SKILL_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCoachTalent; //��ǰ��������Ϊ
	UINT16           wCoachSkillTalent; //��ǰ����鼼����������Ϊ
	UINT16           wTrainNormalTalent; //���������һ����ͨ�������ӵ���Ϊ
	UINT16           wTrainRareTalent; //���������һ��ϡ�м������ӵ���Ϊ
	UINT16           wCurNormalCardNum; //��ǰӵ�е���ͨ���ܿ�Ƭ��
	UINT16           wCurRareCardNum; //��ǰӵ�е�ϡ�м��ܿ�Ƭ��
	UINT8            bySkillNum; //���ܸ���
	DT_SKILL_DATA_CLI astSkillInfo[MAX_SKILL_NUM]; //������Ϣ
	UINT8            byLockSkillNum; //����(δ����)���ܸ���
	DT_LOCK_SKILL_DATA astLockSkillInfo[MAX_SKILL_NUM]; //����(δ����)������Ϣ
}PKT_CLIGS_OPEN_SKILL_TAB_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_SKILL_REQ{
	tagPKT_CLIGS_UPGRADE_SKILL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_SKILL_REQ)); }
	UINT16           wSkillID; //����ID
}PKT_CLIGS_UPGRADE_SKILL_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_SKILL_ACK{
	tagPKT_CLIGS_UPGRADE_SKILL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_SKILL_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCoachTalent; //��ǰ��������Ϊ
	UINT16           wCoachSkillTalent; //��ǰ����鼼����������Ϊ
	UINT16           wCurNormalCardNum; //��ǰӵ�е���ͨ���ܿ�Ƭ��
	UINT16           wCurRareCardNum; //��ǰӵ�е�ϡ�м��ܿ�Ƭ��
	DT_SKILL_DATA_CLI stSkillInfo; //������Ϣ
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_UPGRADE_SKILL_ACK;

typedef struct tagPKT_CLIGS_DRESS_SKILL_REQ{
	tagPKT_CLIGS_DRESS_SKILL_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_SKILL_REQ)); }
	UINT16           wHeroID; //�佫ID
	UINT16           wSkillID; //����ID
	UINT16           wSkillLevel; //���ܵȼ�
}PKT_CLIGS_DRESS_SKILL_REQ;

typedef struct tagPKT_CLIGS_DRESS_SKILL_ACK{
	tagPKT_CLIGS_DRESS_SKILL_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_DRESS_SKILL_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
}PKT_CLIGS_DRESS_SKILL_ACK;

typedef struct tagPKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ{
	tagPKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδ��
}PKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ;

typedef struct tagPKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK{
	tagPKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCurNormalCardNum; //��ǰӵ�е���ͨ���ܿ�Ƭ��
	UINT16           wCurRareCardMakerNum; //��ǰӵ�е�ϡ�м��ܿ��ϳ�ʯ��
	UINT16           wNeedNormalCardNum; //�ϳ�ϡ�м��ܿ�������ͨ���ܿ���
	UINT8            byMakerRate; //�ϳɳɹ���
}PKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK;

typedef struct tagPKT_CLIGS_MAKER_SKILL_CARD_REQ{
	tagPKT_CLIGS_MAKER_SKILL_CARD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MAKER_SKILL_CARD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδ��
}PKT_CLIGS_MAKER_SKILL_CARD_REQ;

typedef struct tagPKT_CLIGS_MAKER_SKILL_CARD_ACK{
	tagPKT_CLIGS_MAKER_SKILL_CARD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MAKER_SKILL_CARD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wCurNormalCardNum; //��ǰӵ�е���ͨ���ܿ�Ƭ��
	UINT16           wCurRareCardNum; //��ǰӵ�е�ϡ�м��ܿ�Ƭ��
	UINT16           wCurRareCardMakerNum; //��ǰӵ�е�ϡ�м��ܿ��ϳ�ʯ��
}PKT_CLIGS_MAKER_SKILL_CARD_ACK;

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
	UINT32           dwNextBuyGold; //�´ι�������Ԫ��
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
	UINT32           dwLevyCountDown; //���յĵ���ʱ
	UINT32           dwLevyCoin; //�����յ�ͭ��
	UINT8            byLevyNum; //�����յĴ���
	UINT8            byTotalLevyNum; //���յ��ܴ���
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

typedef struct tagPKT_CLIGS_OPEN_DRUG_USE_TAB_REQ{
	tagPKT_CLIGS_OPEN_DRUG_USE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DRUG_USE_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_DRUG_USE_TAB_REQ;

typedef struct tagDT_TALENT_DATA{
	UINT16           wKindID; //�������ID
	UINT16           wLevel; //���ȼ�
	UINT16           wTalent; //��Ϊ
	UINT16           wUseCountDown; //���õ�ҩ����ʱ
}DT_TALENT_DATA;

typedef struct tagPKT_CLIGS_OPEN_DRUG_USE_TAB_ACK{
	tagPKT_CLIGS_OPEN_DRUG_USE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_DRUG_USE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byHeroNum; //��������Ϣ
	DT_TALENT_DATA   astHeroInfo[MAX_HERO_NUM]; //�����Ϣ
	UINT16           awDrugNum[MAX_DRUG_LEVEL]; //��ǰ��Ʒ��ҩ������Ϣ
	UINT16           wNoCDGoldPerMin; //�������ÿ��������Ԫ��
	UINT8            byBagFullFlag; //�����Ƿ�����1Ϊ��
}PKT_CLIGS_OPEN_DRUG_USE_TAB_ACK;

typedef struct tagPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ{
	tagPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ)); }
	UINT16           wKindID; //�������ID
}PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK{
	tagPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wKindID; //�������ID
	DT_DRUG_DATA_CLI astDrugInfo[MAX_DRUG_LEVEL]; //��鵤ҩ��Ϣ
	UINT8            byBagFullFlag; //�����Ƿ�����1Ϊ��
}PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK;

typedef struct tagPKT_CLIGS_CLR_USE_DRUG_CD_REQ{
	tagPKT_CLIGS_CLR_USE_DRUG_CD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_USE_DRUG_CD_REQ)); }
	UINT16           wKindID; //�������ID
}PKT_CLIGS_CLR_USE_DRUG_CD_REQ;

typedef struct tagPKT_CLIGS_CLR_USE_DRUG_CD_ACK{
	tagPKT_CLIGS_CLR_USE_DRUG_CD_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CLR_USE_DRUG_CD_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT64           qwCurGold; //��ǰ���Ԫ��
	DT_TALENT_DATA   stHeroTalentInfo; //�����Ϊ��Ϣ
}PKT_CLIGS_CLR_USE_DRUG_CD_ACK;

typedef struct tagPKT_CLIGS_USE_DRUG_REQ{
	tagPKT_CLIGS_USE_DRUG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_USE_DRUG_REQ)); }
	UINT16           wHeroKindID; //�佫����ID
	UINT16           wUseLevel; //��ҩ�ȼ�(Ʒ)
}PKT_CLIGS_USE_DRUG_REQ;

typedef struct tagPKT_CLIGS_USE_DRUG_ACK{
	tagPKT_CLIGS_USE_DRUG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_USE_DRUG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wUseLevel; //��ҩ�ȼ�(Ʒ)
	UINT16           wCurDrugNum; //��ǰ�õȼ�(Ʒ)��ҩ����
	DT_TALENT_DATA   stHeroTalentInfo; //�����Ϊ��Ϣ
	UINT8            byBagFullFlag; //�����Ƿ�����1Ϊ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_USE_DRUG_ACK;

typedef struct tagPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ{
	tagPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ;

typedef struct tagPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK{
	tagPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            abyDrugNum[MAX_DRUG_LEVEL]; //������ҩ�����Ʒ������Ϣ
}PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK;

typedef struct tagPKT_CLIGS_UPGRADE_DRUG_REQ{
	tagPKT_CLIGS_UPGRADE_DRUG_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_DRUG_REQ)); }
	UINT8            byUseDrugLevel; //ʹ�õĵ�ҩ�ȼ�(Ʒ)
}PKT_CLIGS_UPGRADE_DRUG_REQ;

typedef struct tagPKT_CLIGS_UPGRADE_DRUG_ACK{
	tagPKT_CLIGS_UPGRADE_DRUG_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_UPGRADE_DRUG_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byUseDrugLevel; //ʹ�õĵ�ҩ�ȼ�(Ʒ)
	UINT16           wUseDrugNum; //��ǰʹ�õĵ�ҩ)����
	UINT8            byProduceDrugLevel; //���ɵĵ�ҩ�ȼ�(Ʒ)
	UINT16           wProduceDrugNum; //��ǰ���ɵĵ�ҩ����
	UINT8            byBagFullFlag; //�����Ƿ�����1Ϊ��
}PKT_CLIGS_UPGRADE_DRUG_ACK;

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
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //װ��ǿ����Ϣ
	DT_EQUIP_COMPOSE_DATA_CLI stEquipComposeInfo; //װ���ϳ���Ϣ
	UINT64           qwCurGold; //��ҵ�ǰԪ��
	DT_POWER_CHANGE_DATA stPowerInfo; //ս����Ϣ
}PKT_CLIGS_COMPOSE_EQUIP_ACK;

typedef struct tagPKT_CLIGS_OPEN_PHYSTRENGTH_REQ{
	tagPKT_CLIGS_OPEN_PHYSTRENGTH_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PHYSTRENGTH_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδ��
}PKT_CLIGS_OPEN_PHYSTRENGTH_REQ;

typedef struct tagPKT_CLIGS_OPEN_PHYSTRENGTH_ACK{
	tagPKT_CLIGS_OPEN_PHYSTRENGTH_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_PHYSTRENGTH_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT8            byStrength; //����ֵ
	UINT8            byBuyTimes; //�������
	UINT32           dwBuyGold; //���ѵ�Ԫ��
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
	DT_EQUIP_DATA_STRENGTHEN_CLI stEquipStrengthenInfo; //װ��ǿ����Ϣ
	DT_EQUIP_COMPOSE_DATA_CLI stEquipComposeInfo; //װ���ϳ���Ϣ
	UINT64           qwCurCoin; //��ҵ�ǰ��ͭǮ
	DT_POWER_CHANGE_DATA stPowerInfo; //���ս����Ϣ
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
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
	UINT16           wCropValue; //��������
	UINT16           wCropGainKindID; //�������ƷID
	UINT16           wCoin; //����ͭ�Ҽ۸�
	UINT16           wGold; //����Ԫ���۸�
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
	UINT8            byCropType; //��ֲ����
	UINT32           dwCropValue; //��������
	UINT16           wCropKindID; //������ƷID
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
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

typedef struct tagPKT_CLIGS_OPEN_EXPERIENCE_ACK{
	tagPKT_CLIGS_OPEN_EXPERIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_EXPERIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	UINT16           wLevel; //�佫�ȼ�
	UINT32           dwExperience; //��ǰ����
	UINT32           dwUpgradeExperience; //��������
	DT_EXPERIENCE_DRUG_DATA astExperienceDrugDataList[3]; //���鵤��Ϣ
}PKT_CLIGS_OPEN_EXPERIENCE_ACK;

typedef struct tagPKT_CLIGS_USER_EXPERIENCE_REQ{
	tagPKT_CLIGS_USER_EXPERIENCE_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_USER_EXPERIENCE_REQ)); }
	UINT16           wHeroID; //�佫ID
	UINT16           wExperienceDrugID; //���鵤ID
}PKT_CLIGS_USER_EXPERIENCE_REQ;

typedef struct tagPKT_CLIGS_USER_EXPERIENCE_ACK{
	tagPKT_CLIGS_USER_EXPERIENCE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_USER_EXPERIENCE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_EXPERIENCE_DRUG_DATA stExperienceDrugData; //���鵤��Ϣ
	DT_POWER_CHANGE_DATA stPowerChangeData; //�佫ս����Ϣ
	DT_HERO_BASE_DATA_CLI stHeroBaseDataCli; //�佫�����Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_USER_EXPERIENCE_ACK;

typedef struct tagPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ{
	tagPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ)); }
	UINT8            byExt; //��չ�ֶΣ���ʱδʹ��
}PKT_CLIGS_OPEN_SCIENCE_BUILD_REQ;

typedef struct tagDT_SCIENCE_ALREADY_OPEN_DATA{
	UINT8            byKind; //��������
	UINT16           wLevel; //����
	UINT16           wCurValue; //��ǰ��ֵ
	UINT16           wNextValue; //��������ֵ
	UINT16           wCostStory; //������������
	UINT16           wNeedPlayerLevel; //������������ȼ�
	UINT8            byMaxLevel; //�Ƿ�����
}DT_SCIENCE_ALREADY_OPEN_DATA;

typedef struct tagDT_SCIENCE_WILL_OPEN_DATA{
	UINT8            byKind; //��������
	UINT16           wOpenLevel; //���ŵȼ�
	UINT16           wLv1Value; //��һ������ֵ
	UINT16           wCostStory; //������������
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
	DT_EQUIP_DATA_LST_CLI stEquipDataLstCli; //������������Ϣ
}PKT_CLIGS_OPEN_MELT_EQUIP_ACK;

typedef struct tagDT_MELT_EQUIP_DATA{
	UINT16           wEquipID; //װ��ID
	UINT16           wIdx; //��ͬ����װ������ţ�����������ͬ���͵�װ��
}DT_MELT_EQUIP_DATA;

typedef struct tagPKT_CLIGS_MELT_EQUIP_REQ{
	tagPKT_CLIGS_MELT_EQUIP_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_MELT_EQUIP_REQ)); }
	UINT16           wEquipNum; //װ������
	DT_MELT_EQUIP_DATA astMeltEquipDataList[MAX_BAG_OPEN_NUM]; //װ����Ϣ
}PKT_CLIGS_MELT_EQUIP_REQ;

typedef struct tagPKT_CLIGS_MELT_EQUIP_ACK{
	tagPKT_CLIGS_MELT_EQUIP_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_MELT_EQUIP_ACK)); }
	UINT16           wErrorCode; //��������
	UINT64           qwScience; //��ǰ�����
	DT_EQUIP_DATA_LST_CLI stEquipDataLstCli; //������������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_FUNC_PROMPT_DATA stPromptInfo; //Ӱ�����ʾ��Ϣ
}PKT_CLIGS_MELT_EQUIP_ACK;

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
}PKT_CLIGS_COMPOSE_REQ;

typedef struct tagPKT_CLIGS_COMPOSE_ACK{
	tagPKT_CLIGS_COMPOSE_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_COMPOSE_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	DT_ITEM_DATA_CLI2 stItemInfo; //���ɵĵ�����Ϣ
	DT_ITEM_DATA_LIST_CLI2 stGoodsBagItemInfo; //��Ʒ������Ϣ
	DT_TASK_DATA_LIST_CLI stTaskInfoList; //�仯��������Ϣ�б�
	DT_TASK_COND_RECORD_LIST stTaskRecordList; //����(����״̬��)��������¼�б�
	DT_NEW_EQUIP_PROMPT_DATA stNewEquipPromptInfo; //��װ����ǿ��ʾ��Ϣ
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
	UINT64           qwExchangeGold; //��ֵԪ����
}PKT_CLIGS_EXCHANGE_RESULT;

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

typedef struct tagPKT_CLIGS_CHAT_REQ{
	tagPKT_CLIGS_CHAT_REQ() { memset(this, 0, sizeof(tagPKT_CLIGS_CHAT_REQ)); }
	UINT32           dwPlayerID; //��������ID
	UINT8            byChatType; //��������
	UINT32           dwChatLen; //��������
	UINT8            abyChatContent[MAX_CHAT_CONTENT_NUM]; //��������
}PKT_CLIGS_CHAT_REQ;

typedef struct tagCHAT_DATA{
	UINT32           dwPlayerID; //��������ID
	TCHAR            aszUserName[USERNAME_LEN]; //������������
	UINT8            byChatType; //��������
	UINT64           qwChatTime; //����ʱ��
	UINT32           dwChatLen; //���쳤��
	UINT8            abyChatContent[MAX_CHAT_CONTENT_NUM]; //��������
}CHAT_DATA;

typedef struct tagPKT_CLIGS_CHAT_ACK{
	tagPKT_CLIGS_CHAT_ACK() { memset(this, 0, sizeof(tagPKT_CLIGS_CHAT_ACK)); }
	UINT16           wErrCode; //�����룬��0Ϊ����
	CHAT_DATA        stChatData; //��������
}PKT_CLIGS_CHAT_ACK;

typedef struct tagPKT_CLIGS_CHAT_NTF{
	tagPKT_CLIGS_CHAT_NTF() { memset(this, 0, sizeof(tagPKT_CLIGS_CHAT_NTF)); }
	UINT8            byChatNum; //�����¼����
	CHAT_DATA        astChatData[MAX_CHAT_NUM]; //��������
}PKT_CLIGS_CHAT_NTF;

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
	CLIGS_BATTLE_ACK                = 2011        ,
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
	CLIGS_CHALLENGE_ACK             = 2045        ,
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
	CLIGS_OPEN_ITEM_MAKER_REQ       = 2066        ,
	CLIGS_OPEN_ITEM_MAKER_ACK       = 2067        ,
	CLIGS_MAKE_ITEM_REQ             = 2068        ,
	CLIGS_MAKE_ITEM_ACK             = 2069        ,
	CLIGS_GET_HERO_DRUG_REQ         = 2070        ,
	CLIGS_GET_HERO_DRUG_ACK         = 2071        ,
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
	CLIGS_PLUNDER_ACK               = 2109        ,
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
	CLIGS_OPEN_AWAKEN_REQ           = 2148        ,
	CLIGS_OPEN_AWAKEN_ACK           = 2149        ,
	CLIGS_AWAKEN_REQ                = 2150        ,
	CLIGS_AWAKEN_ACK                = 2151        ,
	CLIGS_PICKUP_STUDY_CLIP_REQ     = 2152        ,
	CLIGS_PICKUP_STUDY_CLIP_ACK     = 2153        ,
	CLIGS_OPEN_STUDY_REQ            = 2154        ,
	CLIGS_OPEN_STUDY_ACK            = 2155        ,
	CLIGS_DRESS_STUDY_REQ           = 2156        ,
	CLIGS_DRESS_STUDY_ACK           = 2157        ,
	CLIGS_STUDY_CLIP_TO_EXP_REQ     = 2158        ,
	CLIGS_STUDY_CLIP_TO_EXP_ACK     = 2159        ,
	CLIGS_STUDY_TO_EXP_REQ          = 2160        ,
	CLIGS_STUDY_TO_EXP_ACK          = 2161        ,
	CLIGS_OPEN_STUDY_CONVERT_REQ    = 2162        ,
	CLIGS_OPEN_STUDY_CONVERT_ACK    = 2163        ,
	CLIGS_STUDY_CONVERT_REQ         = 2164        ,
	CLIGS_STUDY_CONVERT_ACK         = 2165        ,
	CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ  = 2166        ,
	CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK  = 2167        ,
	CLIGS_STUDY_CLIP_AUTO2EXP_REQ   = 2168        ,
	CLIGS_STUDY_CLIP_AUTO2EXP_ACK   = 2169        ,
	CLIGS_STUDY_UPGRADE_REQ         = 2170        ,
	CLIGS_STUDY_UPGRADE_ACK         = 2171        ,
	CLIGS_RACE_BATTLELOG_NTF        = 2172        ,
	CLIGS_OPEN_SKILL_TAB_REQ        = 2174        ,
	CLIGS_OPEN_SKILL_TAB_ACK        = 2175        ,
	CLIGS_UPGRADE_SKILL_REQ         = 2176        ,
	CLIGS_UPGRADE_SKILL_ACK         = 2177        ,
	CLIGS_DRESS_SKILL_REQ           = 2178        ,
	CLIGS_DRESS_SKILL_ACK           = 2179        ,
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
	CLIGS_OPEN_SKILL_CARD_MAKER_REQ  = 2196        ,
	CLIGS_OPEN_SKILL_CARD_MAKER_ACK  = 2197        ,
	CLIGS_MAKER_SKILL_CARD_REQ      = 2198        ,
	CLIGS_MAKER_SKILL_CARD_ACK      = 2199        ,
	CLIGS_OPEN_DRUG_USE_TAB_REQ     = 2200        ,
	CLIGS_OPEN_DRUG_USE_TAB_ACK     = 2201        ,
	CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ  = 2202        ,
	CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK  = 2203        ,
	CLIGS_CLR_USE_DRUG_CD_REQ       = 2204        ,
	CLIGS_CLR_USE_DRUG_CD_ACK       = 2205        ,
	CLIGS_USE_DRUG_REQ              = 2206        ,
	CLIGS_USE_DRUG_ACK              = 2207        ,
	CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ  = 2208        ,
	CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK  = 2209        ,
	CLIGS_UPGRADE_DRUG_REQ          = 2210        ,
	CLIGS_UPGRADE_DRUG_ACK          = 2211        ,
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
	CLIGS_MELT_EQUIP_REQ            = 2242        ,
	CLIGS_MELT_EQUIP_ACK            = 2243        ,
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
	CLIGS_SEED_COMPOSE_REQ          = 2259        ,
	CLIGS_SEED_COMPOSE_ACK          = 2260        ,
	CLIGS_CHAT_REQ                  = 2261        ,
	CLIGS_CHAT_ACK                  = 2262        ,
	CLIGS_CHAT_NTF                  = 2264        ,
};

/*Encode and Decode Function Declare Begin*/
INT32 EncodePKT_CLIGS_ENTERGS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTERGS_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ENTERGS_REQ( PKT_CLIGS_ENTERGS_REQ &data );
BOOL FromJsonPKT_CLIGS_ENTERGS_REQ(const string &strData, PKT_CLIGS_ENTERGS_REQ &data);
BOOL FromJsonPKT_CLIGS_ENTERGS_REQ(Json::Value &root, PKT_CLIGS_ENTERGS_REQ &data);
INT32 EncodeDT_EXT_FUNC_PARAM(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXT_FUNC_PARAM(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EXT_FUNC_PARAM( DT_EXT_FUNC_PARAM &data );
BOOL FromJsonDT_EXT_FUNC_PARAM(const string &strData, DT_EXT_FUNC_PARAM &data);
BOOL FromJsonDT_EXT_FUNC_PARAM(Json::Value &root, DT_EXT_FUNC_PARAM &data);
INT32 EncodeDT_EXT_FUNC_PARAM_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXT_FUNC_PARAM_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EXT_FUNC_PARAM_LST( DT_EXT_FUNC_PARAM_LST &data );
BOOL FromJsonDT_EXT_FUNC_PARAM_LST(const string &strData, DT_EXT_FUNC_PARAM_LST &data);
BOOL FromJsonDT_EXT_FUNC_PARAM_LST(Json::Value &root, DT_EXT_FUNC_PARAM_LST &data);
INT32 EncodeDT_POWER_CHANGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_POWER_CHANGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_POWER_CHANGE_DATA( DT_POWER_CHANGE_DATA &data );
BOOL FromJsonDT_POWER_CHANGE_DATA(const string &strData, DT_POWER_CHANGE_DATA &data);
BOOL FromJsonDT_POWER_CHANGE_DATA(Json::Value &root, DT_POWER_CHANGE_DATA &data);
INT32 EncodeDT_SKILL_BUFF_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_BUFF_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_BUFF_DATA( DT_SKILL_BUFF_DATA &data );
BOOL FromJsonDT_SKILL_BUFF_DATA(const string &strData, DT_SKILL_BUFF_DATA &data);
BOOL FromJsonDT_SKILL_BUFF_DATA(Json::Value &root, DT_SKILL_BUFF_DATA &data);
INT32 EncodeDT_SKILL_EFFECT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_EFFECT_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_EFFECT_DATA( DT_SKILL_EFFECT_DATA &data );
BOOL FromJsonDT_SKILL_EFFECT_DATA(const string &strData, DT_SKILL_EFFECT_DATA &data);
BOOL FromJsonDT_SKILL_EFFECT_DATA(Json::Value &root, DT_SKILL_EFFECT_DATA &data);
INT32 EncodeDT_ATTACK_RANG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTACK_RANG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ATTACK_RANG_DATA( DT_ATTACK_RANG_DATA &data );
BOOL FromJsonDT_ATTACK_RANG_DATA(const string &strData, DT_ATTACK_RANG_DATA &data);
BOOL FromJsonDT_ATTACK_RANG_DATA(Json::Value &root, DT_ATTACK_RANG_DATA &data);
INT32 EncodeDT_SKILL_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_DATA_CLI( DT_SKILL_DATA_CLI &data );
BOOL FromJsonDT_SKILL_DATA_CLI(const string &strData, DT_SKILL_DATA_CLI &data);
BOOL FromJsonDT_SKILL_DATA_CLI(Json::Value &root, DT_SKILL_DATA_CLI &data);
INT32 EncodeDT_SKILL_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SKILL_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SKILL_DATA_LIST_CLI( DT_SKILL_DATA_LIST_CLI &data );
BOOL FromJsonDT_SKILL_DATA_LIST_CLI(const string &strData, DT_SKILL_DATA_LIST_CLI &data);
BOOL FromJsonDT_SKILL_DATA_LIST_CLI(Json::Value &root, DT_SKILL_DATA_LIST_CLI &data);
INT32 EncodeDT_HERO_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_BASE_DATA_CLI( DT_HERO_BASE_DATA_CLI &data );
BOOL FromJsonDT_HERO_BASE_DATA_CLI(const string &strData, DT_HERO_BASE_DATA_CLI &data);
BOOL FromJsonDT_HERO_BASE_DATA_CLI(Json::Value &root, DT_HERO_BASE_DATA_CLI &data);
INT32 EncodeDT_HERO_UPGRADE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPGRADE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_UPGRADE_DATA( DT_HERO_UPGRADE_DATA &data );
BOOL FromJsonDT_HERO_UPGRADE_DATA(const string &strData, DT_HERO_UPGRADE_DATA &data);
BOOL FromJsonDT_HERO_UPGRADE_DATA(Json::Value &root, DT_HERO_UPGRADE_DATA &data);
INT32 EncodeDT_EQUIP_DATA_STRENGTHEN_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_STRENGTHEN_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_DATA_STRENGTHEN_CLI( DT_EQUIP_DATA_STRENGTHEN_CLI &data );
BOOL FromJsonDT_EQUIP_DATA_STRENGTHEN_CLI(const string &strData, DT_EQUIP_DATA_STRENGTHEN_CLI &data);
BOOL FromJsonDT_EQUIP_DATA_STRENGTHEN_CLI(Json::Value &root, DT_EQUIP_DATA_STRENGTHEN_CLI &data);
INT32 EncodeDT_EQUIP_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_DATA_CLI( DT_EQUIP_DATA_CLI &data );
BOOL FromJsonDT_EQUIP_DATA_CLI(const string &strData, DT_EQUIP_DATA_CLI &data);
BOOL FromJsonDT_EQUIP_DATA_CLI(Json::Value &root, DT_EQUIP_DATA_CLI &data);
INT32 EncodeDT_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_DATA_LST_CLI( DT_EQUIP_DATA_LST_CLI &data );
BOOL FromJsonDT_EQUIP_DATA_LST_CLI(const string &strData, DT_EQUIP_DATA_LST_CLI &data);
BOOL FromJsonDT_EQUIP_DATA_LST_CLI(Json::Value &root, DT_EQUIP_DATA_LST_CLI &data);
INT32 EncodeDT_HERO_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EQUIP_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_EQUIP_DATA_LST_CLI( DT_HERO_EQUIP_DATA_LST_CLI &data );
BOOL FromJsonDT_HERO_EQUIP_DATA_LST_CLI(const string &strData, DT_HERO_EQUIP_DATA_LST_CLI &data);
BOOL FromJsonDT_HERO_EQUIP_DATA_LST_CLI(Json::Value &root, DT_HERO_EQUIP_DATA_LST_CLI &data);
INT32 EncodeDT_NEED_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEED_ITEM_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_NEED_ITEM_DATA( DT_NEED_ITEM_DATA &data );
BOOL FromJsonDT_NEED_ITEM_DATA(const string &strData, DT_NEED_ITEM_DATA &data);
BOOL FromJsonDT_NEED_ITEM_DATA(Json::Value &root, DT_NEED_ITEM_DATA &data);
INT32 EncodeDT_ESTIMATE_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ESTIMATE_EQUIP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ESTIMATE_EQUIP_DATA( DT_ESTIMATE_EQUIP_DATA &data );
BOOL FromJsonDT_ESTIMATE_EQUIP_DATA(const string &strData, DT_ESTIMATE_EQUIP_DATA &data);
BOOL FromJsonDT_ESTIMATE_EQUIP_DATA(Json::Value &root, DT_ESTIMATE_EQUIP_DATA &data);
INT32 EncodeDT_ESTIMATE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ESTIMATE_DRUG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ESTIMATE_DRUG_DATA( DT_ESTIMATE_DRUG_DATA &data );
BOOL FromJsonDT_ESTIMATE_DRUG_DATA(const string &strData, DT_ESTIMATE_DRUG_DATA &data);
BOOL FromJsonDT_ESTIMATE_DRUG_DATA(Json::Value &root, DT_ESTIMATE_DRUG_DATA &data);
INT32 EncodeUnDT_ESTIMATE_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_ESTIMATE_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_ESTIMATE_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ESTIMATE_ITEM_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ESTIMATE_ITEM_DATA( DT_ESTIMATE_ITEM_DATA &data );
BOOL FromJsonDT_ESTIMATE_ITEM_DATA(const string &strData, DT_ESTIMATE_ITEM_DATA &data);
BOOL FromJsonDT_ESTIMATE_ITEM_DATA(Json::Value &root, DT_ESTIMATE_ITEM_DATA &data);
INT32 EncodeDT_EQUIP_COMPOSE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_COMPOSE_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_COMPOSE_DATA_CLI( DT_EQUIP_COMPOSE_DATA_CLI &data );
BOOL FromJsonDT_EQUIP_COMPOSE_DATA_CLI(const string &strData, DT_EQUIP_COMPOSE_DATA_CLI &data);
BOOL FromJsonDT_EQUIP_COMPOSE_DATA_CLI(Json::Value &root, DT_EQUIP_COMPOSE_DATA_CLI &data);
INT32 EncodeDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI( DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI &data );
BOOL FromJsonDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI(const string &strData, DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI &data);
BOOL FromJsonDT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI(Json::Value &root, DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI &data);
INT32 EncodeDT_SEED_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SEED_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SEED_DATA_CLI( DT_SEED_DATA_CLI &data );
BOOL FromJsonDT_SEED_DATA_CLI(const string &strData, DT_SEED_DATA_CLI &data);
BOOL FromJsonDT_SEED_DATA_CLI(Json::Value &root, DT_SEED_DATA_CLI &data);
INT32 EncodeDT_GOODS_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GOODS_DATA_CLI( DT_GOODS_DATA_CLI &data );
BOOL FromJsonDT_GOODS_DATA_CLI(const string &strData, DT_GOODS_DATA_CLI &data);
BOOL FromJsonDT_GOODS_DATA_CLI(Json::Value &root, DT_GOODS_DATA_CLI &data);
INT32 EncodeDT_GOODS_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GOODS_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GOODS_DATA_LST_CLI( DT_GOODS_DATA_LST_CLI &data );
BOOL FromJsonDT_GOODS_DATA_LST_CLI(const string &strData, DT_GOODS_DATA_LST_CLI &data);
BOOL FromJsonDT_GOODS_DATA_LST_CLI(Json::Value &root, DT_GOODS_DATA_LST_CLI &data);
INT32 EncodeDT_ITEM_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEM_DATA_CLI( DT_ITEM_DATA_CLI &data );
BOOL FromJsonDT_ITEM_DATA_CLI(const string &strData, DT_ITEM_DATA_CLI &data);
BOOL FromJsonDT_ITEM_DATA_CLI(Json::Value &root, DT_ITEM_DATA_CLI &data);
INT32 EncodeDT_ITEM_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEM_DATA_LIST_CLI( DT_ITEM_DATA_LIST_CLI &data );
BOOL FromJsonDT_ITEM_DATA_LIST_CLI(const string &strData, DT_ITEM_DATA_LIST_CLI &data);
BOOL FromJsonDT_ITEM_DATA_LIST_CLI(Json::Value &root, DT_ITEM_DATA_LIST_CLI &data);
INT32 EncodeUnDT_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_ITEM_DATA_UNOIN(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_ITEM_DATA_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_CLI2(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEM_DATA_CLI2( DT_ITEM_DATA_CLI2 &data );
BOOL FromJsonDT_ITEM_DATA_CLI2(const string &strData, DT_ITEM_DATA_CLI2 &data);
BOOL FromJsonDT_ITEM_DATA_CLI2(Json::Value &root, DT_ITEM_DATA_CLI2 &data);
INT32 EncodeDT_ITEM_DATA_LIST_CLI2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_LIST_CLI2(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEM_DATA_LIST_CLI2( DT_ITEM_DATA_LIST_CLI2 &data );
BOOL FromJsonDT_ITEM_DATA_LIST_CLI2(const string &strData, DT_ITEM_DATA_LIST_CLI2 &data);
BOOL FromJsonDT_ITEM_DATA_LIST_CLI2(Json::Value &root, DT_ITEM_DATA_LIST_CLI2 &data);
INT32 EncodeDT_TASK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_ENCOURAGE_DATA( DT_TASK_ENCOURAGE_DATA &data );
BOOL FromJsonDT_TASK_ENCOURAGE_DATA(const string &strData, DT_TASK_ENCOURAGE_DATA &data);
BOOL FromJsonDT_TASK_ENCOURAGE_DATA(Json::Value &root, DT_TASK_ENCOURAGE_DATA &data);
INT32 EncodeDT_TASK_BASE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_BASE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_BASE_DATA( DT_TASK_BASE_DATA &data );
BOOL FromJsonDT_TASK_BASE_DATA(const string &strData, DT_TASK_BASE_DATA &data);
BOOL FromJsonDT_TASK_BASE_DATA(Json::Value &root, DT_TASK_BASE_DATA &data);
INT32 EncodeDT_GIVEN_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GIVEN_TASK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GIVEN_TASK_DATA( DT_GIVEN_TASK_DATA &data );
BOOL FromJsonDT_GIVEN_TASK_DATA(const string &strData, DT_GIVEN_TASK_DATA &data);
BOOL FromJsonDT_GIVEN_TASK_DATA(Json::Value &root, DT_GIVEN_TASK_DATA &data);
INT32 EncodeDT_ACCEPT_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCEPT_TASK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ACCEPT_TASK_DATA( DT_ACCEPT_TASK_DATA &data );
BOOL FromJsonDT_ACCEPT_TASK_DATA(const string &strData, DT_ACCEPT_TASK_DATA &data);
BOOL FromJsonDT_ACCEPT_TASK_DATA(Json::Value &root, DT_ACCEPT_TASK_DATA &data);
INT32 EncodeDT_ENCOURAGE_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENCOURAGE_TASK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENCOURAGE_TASK_DATA( DT_ENCOURAGE_TASK_DATA &data );
BOOL FromJsonDT_ENCOURAGE_TASK_DATA(const string &strData, DT_ENCOURAGE_TASK_DATA &data);
BOOL FromJsonDT_ENCOURAGE_TASK_DATA(Json::Value &root, DT_ENCOURAGE_TASK_DATA &data);
INT32 EncodeDT_INVALID_TASK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INVALID_TASK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INVALID_TASK_DATA( DT_INVALID_TASK_DATA &data );
BOOL FromJsonDT_INVALID_TASK_DATA(const string &strData, DT_INVALID_TASK_DATA &data);
BOOL FromJsonDT_INVALID_TASK_DATA(Json::Value &root, DT_INVALID_TASK_DATA &data);
INT32 EncodeUnDT_TASK_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 DecodeUnDT_TASK_UNION(void *pHost, INT32 iSelect, CNetData* poNetData);
INT32 EncodeDT_TASK_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_DATA_CLI( DT_TASK_DATA_CLI &data );
BOOL FromJsonDT_TASK_DATA_CLI(const string &strData, DT_TASK_DATA_CLI &data);
BOOL FromJsonDT_TASK_DATA_CLI(Json::Value &root, DT_TASK_DATA_CLI &data);
INT32 EncodeDT_TASK_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_DATA_LIST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_DATA_LIST_CLI( DT_TASK_DATA_LIST_CLI &data );
BOOL FromJsonDT_TASK_DATA_LIST_CLI(const string &strData, DT_TASK_DATA_LIST_CLI &data);
BOOL FromJsonDT_TASK_DATA_LIST_CLI(Json::Value &root, DT_TASK_DATA_LIST_CLI &data);
INT32 EncodeDT_ACCEPT_TASK_COND_RECORD(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ACCEPT_TASK_COND_RECORD(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ACCEPT_TASK_COND_RECORD( DT_ACCEPT_TASK_COND_RECORD &data );
BOOL FromJsonDT_ACCEPT_TASK_COND_RECORD(const string &strData, DT_ACCEPT_TASK_COND_RECORD &data);
BOOL FromJsonDT_ACCEPT_TASK_COND_RECORD(Json::Value &root, DT_ACCEPT_TASK_COND_RECORD &data);
INT32 EncodeDT_TASK_COND_RECORD_LIST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TASK_COND_RECORD_LIST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TASK_COND_RECORD_LIST( DT_TASK_COND_RECORD_LIST &data );
BOOL FromJsonDT_TASK_COND_RECORD_LIST(const string &strData, DT_TASK_COND_RECORD_LIST &data);
BOOL FromJsonDT_TASK_COND_RECORD_LIST(Json::Value &root, DT_TASK_COND_RECORD_LIST &data);
INT32 EncodeDT_PHYSTRENGTH_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PHYSTRENGTH_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PHYSTRENGTH_DATA_CLI( DT_PHYSTRENGTH_DATA_CLI &data );
BOOL FromJsonDT_PHYSTRENGTH_DATA_CLI(const string &strData, DT_PHYSTRENGTH_DATA_CLI &data);
BOOL FromJsonDT_PHYSTRENGTH_DATA_CLI(Json::Value &root, DT_PHYSTRENGTH_DATA_CLI &data);
INT32 EncodeDT_EXPERIENCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXPERIENCE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EXPERIENCE_DATA( DT_EXPERIENCE_DATA &data );
BOOL FromJsonDT_EXPERIENCE_DATA(const string &strData, DT_EXPERIENCE_DATA &data);
BOOL FromJsonDT_EXPERIENCE_DATA(Json::Value &root, DT_EXPERIENCE_DATA &data);
INT32 EncodeDT_PLAYER_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_BASE_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLAYER_BASE_DATA_CLI( DT_PLAYER_BASE_DATA_CLI &data );
BOOL FromJsonDT_PLAYER_BASE_DATA_CLI(const string &strData, DT_PLAYER_BASE_DATA_CLI &data);
BOOL FromJsonDT_PLAYER_BASE_DATA_CLI(Json::Value &root, DT_PLAYER_BASE_DATA_CLI &data);
INT32 EncodeDT_BUILD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUILD_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BUILD_DATA_CLI( DT_BUILD_DATA_CLI &data );
BOOL FromJsonDT_BUILD_DATA_CLI(const string &strData, DT_BUILD_DATA_CLI &data);
BOOL FromJsonDT_BUILD_DATA_CLI(Json::Value &root, DT_BUILD_DATA_CLI &data);
INT32 EncodeDT_ONLINE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ONLINE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ONLINE_ENCOURAGE_DATA( DT_ONLINE_ENCOURAGE_DATA &data );
BOOL FromJsonDT_ONLINE_ENCOURAGE_DATA(const string &strData, DT_ONLINE_ENCOURAGE_DATA &data);
BOOL FromJsonDT_ONLINE_ENCOURAGE_DATA(Json::Value &root, DT_ONLINE_ENCOURAGE_DATA &data);
INT32 EncodeDT_DATA_AFTER_ONLINE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_ONLINE_ENCOURAGE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DATA_AFTER_ONLINE_ENCOURAGE( DT_DATA_AFTER_ONLINE_ENCOURAGE &data );
BOOL FromJsonDT_DATA_AFTER_ONLINE_ENCOURAGE(const string &strData, DT_DATA_AFTER_ONLINE_ENCOURAGE &data);
BOOL FromJsonDT_DATA_AFTER_ONLINE_ENCOURAGE(Json::Value &root, DT_DATA_AFTER_ONLINE_ENCOURAGE &data);
INT32 EncodePKT_CLIGS_ENTERGS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTERGS_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ENTERGS_ACK( PKT_CLIGS_ENTERGS_ACK &data );
BOOL FromJsonPKT_CLIGS_ENTERGS_ACK(const string &strData, PKT_CLIGS_ENTERGS_ACK &data);
BOOL FromJsonPKT_CLIGS_ENTERGS_ACK(Json::Value &root, PKT_CLIGS_ENTERGS_ACK &data);
INT32 EncodeDT_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BAG_DATA_CLI( DT_BAG_DATA_CLI &data );
BOOL FromJsonDT_BAG_DATA_CLI(const string &strData, DT_BAG_DATA_CLI &data);
BOOL FromJsonDT_BAG_DATA_CLI(Json::Value &root, DT_BAG_DATA_CLI &data);
INT32 EncodeDT_EQUIP_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_BAG_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_BAG_DATA_CLI( DT_EQUIP_BAG_DATA_CLI &data );
BOOL FromJsonDT_EQUIP_BAG_DATA_CLI(const string &strData, DT_EQUIP_BAG_DATA_CLI &data);
BOOL FromJsonDT_EQUIP_BAG_DATA_CLI(Json::Value &root, DT_EQUIP_BAG_DATA_CLI &data);
INT32 EncodePKT_CLIGS_GET_HERO_INFO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_HERO_INFO_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_HERO_INFO_REQ( PKT_CLIGS_GET_HERO_INFO_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_HERO_INFO_REQ(const string &strData, PKT_CLIGS_GET_HERO_INFO_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_HERO_INFO_REQ(Json::Value &root, PKT_CLIGS_GET_HERO_INFO_REQ &data);
INT32 EncodeDT_ATTR_ENABLE_UPDATE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ATTR_ENABLE_UPDATE_INFO(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ATTR_ENABLE_UPDATE_INFO( DT_ATTR_ENABLE_UPDATE_INFO &data );
BOOL FromJsonDT_ATTR_ENABLE_UPDATE_INFO(const string &strData, DT_ATTR_ENABLE_UPDATE_INFO &data);
BOOL FromJsonDT_ATTR_ENABLE_UPDATE_INFO(Json::Value &root, DT_ATTR_ENABLE_UPDATE_INFO &data);
INT32 EncodeDT_HERO_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_DATA_CLI( DT_HERO_DATA_CLI &data );
BOOL FromJsonDT_HERO_DATA_CLI(const string &strData, DT_HERO_DATA_CLI &data);
BOOL FromJsonDT_HERO_DATA_CLI(Json::Value &root, DT_HERO_DATA_CLI &data);
INT32 EncodeDT_PLAYER_BATTLE_INFO(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLAYER_BATTLE_INFO(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLAYER_BATTLE_INFO( DT_PLAYER_BATTLE_INFO &data );
BOOL FromJsonDT_PLAYER_BATTLE_INFO(const string &strData, DT_PLAYER_BATTLE_INFO &data);
BOOL FromJsonDT_PLAYER_BATTLE_INFO(Json::Value &root, DT_PLAYER_BATTLE_INFO &data);
INT32 EncodePKT_CLIGS_GET_HERO_INFO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_HERO_INFO_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_HERO_INFO_ACK( PKT_CLIGS_GET_HERO_INFO_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_HERO_INFO_ACK(const string &strData, PKT_CLIGS_GET_HERO_INFO_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_HERO_INFO_ACK(Json::Value &root, PKT_CLIGS_GET_HERO_INFO_ACK &data);
INT32 EncodeDT_FUNC_COMMON_PROMPT(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FUNC_COMMON_PROMPT(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FUNC_COMMON_PROMPT( DT_FUNC_COMMON_PROMPT &data );
BOOL FromJsonDT_FUNC_COMMON_PROMPT(const string &strData, DT_FUNC_COMMON_PROMPT &data);
BOOL FromJsonDT_FUNC_COMMON_PROMPT(Json::Value &root, DT_FUNC_COMMON_PROMPT &data);
INT32 EncodeDT_FUNC_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_FUNC_PROMPT_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_FUNC_PROMPT_DATA( DT_FUNC_PROMPT_DATA &data );
BOOL FromJsonDT_FUNC_PROMPT_DATA(const string &strData, DT_FUNC_PROMPT_DATA &data);
BOOL FromJsonDT_FUNC_PROMPT_DATA(Json::Value &root, DT_FUNC_PROMPT_DATA &data);
INT32 EncodeDT_OTHER_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_OTHER_PROMPT_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_OTHER_PROMPT_DATA( DT_OTHER_PROMPT_DATA &data );
BOOL FromJsonDT_OTHER_PROMPT_DATA(const string &strData, DT_OTHER_PROMPT_DATA &data);
BOOL FromJsonDT_OTHER_PROMPT_DATA(Json::Value &root, DT_OTHER_PROMPT_DATA &data);
INT32 EncodeDT_NEW_EQUIP_PROMPT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEW_EQUIP_PROMPT_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_NEW_EQUIP_PROMPT_DATA( DT_NEW_EQUIP_PROMPT_DATA &data );
BOOL FromJsonDT_NEW_EQUIP_PROMPT_DATA(const string &strData, DT_NEW_EQUIP_PROMPT_DATA &data);
BOOL FromJsonDT_NEW_EQUIP_PROMPT_DATA(Json::Value &root, DT_NEW_EQUIP_PROMPT_DATA &data);
INT32 EncodePKT_CLIGS_ENTER_HOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_HOME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ENTER_HOME_REQ( PKT_CLIGS_ENTER_HOME_REQ &data );
BOOL FromJsonPKT_CLIGS_ENTER_HOME_REQ(const string &strData, PKT_CLIGS_ENTER_HOME_REQ &data);
BOOL FromJsonPKT_CLIGS_ENTER_HOME_REQ(Json::Value &root, PKT_CLIGS_ENTER_HOME_REQ &data);
INT32 EncodePKT_CLIGS_ENTER_HOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_HOME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ENTER_HOME_ACK( PKT_CLIGS_ENTER_HOME_ACK &data );
BOOL FromJsonPKT_CLIGS_ENTER_HOME_ACK(const string &strData, PKT_CLIGS_ENTER_HOME_ACK &data);
BOOL FromJsonPKT_CLIGS_ENTER_HOME_ACK(Json::Value &root, PKT_CLIGS_ENTER_HOME_ACK &data);
INT32 EncodeDT_BATTLE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BATTLE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BATTLE_ENCOURAGE_DATA( DT_BATTLE_ENCOURAGE_DATA &data );
BOOL FromJsonDT_BATTLE_ENCOURAGE_DATA(const string &strData, DT_BATTLE_ENCOURAGE_DATA &data);
BOOL FromJsonDT_BATTLE_ENCOURAGE_DATA(Json::Value &root, DT_BATTLE_ENCOURAGE_DATA &data);
INT32 EncodeDT_DATA_AFTER_BATTLE_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_BATTLE_ENCOURAGE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DATA_AFTER_BATTLE_ENCOURAGE( DT_DATA_AFTER_BATTLE_ENCOURAGE &data );
BOOL FromJsonDT_DATA_AFTER_BATTLE_ENCOURAGE(const string &strData, DT_DATA_AFTER_BATTLE_ENCOURAGE &data);
BOOL FromJsonDT_DATA_AFTER_BATTLE_ENCOURAGE(Json::Value &root, DT_DATA_AFTER_BATTLE_ENCOURAGE &data);
INT32 EncodeDT_RACE_CHALLENGE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_CHALLENGE_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RACE_CHALLENGE_ENCOURAGE_DATA( DT_RACE_CHALLENGE_ENCOURAGE_DATA &data );
BOOL FromJsonDT_RACE_CHALLENGE_ENCOURAGE_DATA(const string &strData, DT_RACE_CHALLENGE_ENCOURAGE_DATA &data);
BOOL FromJsonDT_RACE_CHALLENGE_ENCOURAGE_DATA(Json::Value &root, DT_RACE_CHALLENGE_ENCOURAGE_DATA &data);
INT32 EncodeDT_RACE_RANK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_RANK_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RACE_RANK_ENCOURAGE_DATA( DT_RACE_RANK_ENCOURAGE_DATA &data );
BOOL FromJsonDT_RACE_RANK_ENCOURAGE_DATA(const string &strData, DT_RACE_RANK_ENCOURAGE_DATA &data);
BOOL FromJsonDT_RACE_RANK_ENCOURAGE_DATA(Json::Value &root, DT_RACE_RANK_ENCOURAGE_DATA &data);
INT32 EncodePKT_CLIGS_ENTER_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_INSTANCE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ENTER_INSTANCE_REQ( PKT_CLIGS_ENTER_INSTANCE_REQ &data );
BOOL FromJsonPKT_CLIGS_ENTER_INSTANCE_REQ(const string &strData, PKT_CLIGS_ENTER_INSTANCE_REQ &data);
BOOL FromJsonPKT_CLIGS_ENTER_INSTANCE_REQ(Json::Value &root, PKT_CLIGS_ENTER_INSTANCE_REQ &data);
INT32 EncodeDT_PASS_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PASS_ENCOURAGE_DATA( DT_PASS_ENCOURAGE_DATA &data );
BOOL FromJsonDT_PASS_ENCOURAGE_DATA(const string &strData, DT_PASS_ENCOURAGE_DATA &data);
BOOL FromJsonDT_PASS_ENCOURAGE_DATA(Json::Value &root, DT_PASS_ENCOURAGE_DATA &data);
INT32 EncodeDT_DATA_AFTER_PASS_ENCOURAGE(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_PASS_ENCOURAGE(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DATA_AFTER_PASS_ENCOURAGE( DT_DATA_AFTER_PASS_ENCOURAGE &data );
BOOL FromJsonDT_DATA_AFTER_PASS_ENCOURAGE(const string &strData, DT_DATA_AFTER_PASS_ENCOURAGE &data);
BOOL FromJsonDT_DATA_AFTER_PASS_ENCOURAGE(Json::Value &root, DT_DATA_AFTER_PASS_ENCOURAGE &data);
INT32 EncodeDT_PASS_ENCOURAGE_BOX_GROUP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_BOX_GROUP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PASS_ENCOURAGE_BOX_GROUP_DATA( DT_PASS_ENCOURAGE_BOX_GROUP_DATA &data );
BOOL FromJsonDT_PASS_ENCOURAGE_BOX_GROUP_DATA(const string &strData, DT_PASS_ENCOURAGE_BOX_GROUP_DATA &data);
BOOL FromJsonDT_PASS_ENCOURAGE_BOX_GROUP_DATA(Json::Value &root, DT_PASS_ENCOURAGE_BOX_GROUP_DATA &data);
INT32 EncodeDT_PASS_ENCOURAGE_BOX_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PASS_ENCOURAGE_BOX_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PASS_ENCOURAGE_BOX_DATA( DT_PASS_ENCOURAGE_BOX_DATA &data );
BOOL FromJsonDT_PASS_ENCOURAGE_BOX_DATA(const string &strData, DT_PASS_ENCOURAGE_BOX_DATA &data);
BOOL FromJsonDT_PASS_ENCOURAGE_BOX_DATA(Json::Value &root, DT_PASS_ENCOURAGE_BOX_DATA &data);
INT32 EncodePKT_CLIGS_ENTER_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ENTER_INSTANCE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ENTER_INSTANCE_ACK( PKT_CLIGS_ENTER_INSTANCE_ACK &data );
BOOL FromJsonPKT_CLIGS_ENTER_INSTANCE_ACK(const string &strData, PKT_CLIGS_ENTER_INSTANCE_ACK &data);
BOOL FromJsonPKT_CLIGS_ENTER_INSTANCE_ACK(Json::Value &root, PKT_CLIGS_ENTER_INSTANCE_ACK &data);
INT32 EncodePKT_CLIGS_BATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BATTLE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BATTLE_REQ( PKT_CLIGS_BATTLE_REQ &data );
BOOL FromJsonPKT_CLIGS_BATTLE_REQ(const string &strData, PKT_CLIGS_BATTLE_REQ &data);
BOOL FromJsonPKT_CLIGS_BATTLE_REQ(Json::Value &root, PKT_CLIGS_BATTLE_REQ &data);
INT32 EncodeDT_BURST_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BURST_ITEM_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BURST_ITEM_DATA( DT_BURST_ITEM_DATA &data );
BOOL FromJsonDT_BURST_ITEM_DATA(const string &strData, DT_BURST_ITEM_DATA &data);
BOOL FromJsonDT_BURST_ITEM_DATA(Json::Value &root, DT_BURST_ITEM_DATA &data);
INT32 EncodeDT_NEXT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_NEXT_INSTANCE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_NEXT_INSTANCE_DATA( DT_NEXT_INSTANCE_DATA &data );
BOOL FromJsonDT_NEXT_INSTANCE_DATA(const string &strData, DT_NEXT_INSTANCE_DATA &data);
BOOL FromJsonDT_NEXT_INSTANCE_DATA(Json::Value &root, DT_NEXT_INSTANCE_DATA &data);
INT32 EncodeDT_UNLOCK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UNLOCK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UNLOCK_DATA( DT_UNLOCK_DATA &data );
BOOL FromJsonDT_UNLOCK_DATA(const string &strData, DT_UNLOCK_DATA &data);
BOOL FromJsonDT_UNLOCK_DATA(Json::Value &root, DT_UNLOCK_DATA &data);
INT32 EncodePKT_CLIGS_BATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BATTLE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BATTLE_ACK( PKT_CLIGS_BATTLE_ACK &data );
BOOL FromJsonPKT_CLIGS_BATTLE_ACK(const string &strData, PKT_CLIGS_BATTLE_ACK &data);
BOOL FromJsonPKT_CLIGS_BATTLE_ACK(Json::Value &root, PKT_CLIGS_BATTLE_ACK &data);
INT32 EncodePKT_CLIGS_EXIT_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXIT_INSTANCE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EXIT_INSTANCE_REQ( PKT_CLIGS_EXIT_INSTANCE_REQ &data );
BOOL FromJsonPKT_CLIGS_EXIT_INSTANCE_REQ(const string &strData, PKT_CLIGS_EXIT_INSTANCE_REQ &data);
BOOL FromJsonPKT_CLIGS_EXIT_INSTANCE_REQ(Json::Value &root, PKT_CLIGS_EXIT_INSTANCE_REQ &data);
INT32 EncodePKT_CLIGS_EXIT_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXIT_INSTANCE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EXIT_INSTANCE_ACK( PKT_CLIGS_EXIT_INSTANCE_ACK &data );
BOOL FromJsonPKT_CLIGS_EXIT_INSTANCE_ACK(const string &strData, PKT_CLIGS_EXIT_INSTANCE_ACK &data);
BOOL FromJsonPKT_CLIGS_EXIT_INSTANCE_ACK(Json::Value &root, PKT_CLIGS_EXIT_INSTANCE_ACK &data);
INT32 EncodeDT_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INSTANCE_RECORD_DATA_CLI( DT_INSTANCE_RECORD_DATA_CLI &data );
BOOL FromJsonDT_INSTANCE_RECORD_DATA_CLI(const string &strData, DT_INSTANCE_RECORD_DATA_CLI &data);
BOOL FromJsonDT_INSTANCE_RECORD_DATA_CLI(Json::Value &root, DT_INSTANCE_RECORD_DATA_CLI &data);
INT32 EncodeDT_TOWN_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TOWN_INSTANCE_RECORD_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TOWN_INSTANCE_RECORD_DATA_CLI( DT_TOWN_INSTANCE_RECORD_DATA_CLI &data );
BOOL FromJsonDT_TOWN_INSTANCE_RECORD_DATA_CLI(const string &strData, DT_TOWN_INSTANCE_RECORD_DATA_CLI &data);
BOOL FromJsonDT_TOWN_INSTANCE_RECORD_DATA_CLI(Json::Value &root, DT_TOWN_INSTANCE_RECORD_DATA_CLI &data);
INT32 EncodePKT_CLIGS_GET_SCENE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_SCENE_INSTANCE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_SCENE_INSTANCE_REQ( PKT_CLIGS_GET_SCENE_INSTANCE_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_SCENE_INSTANCE_REQ(const string &strData, PKT_CLIGS_GET_SCENE_INSTANCE_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_SCENE_INSTANCE_REQ(Json::Value &root, PKT_CLIGS_GET_SCENE_INSTANCE_REQ &data);
INT32 EncodePKT_CLIGS_GET_SCENE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_SCENE_INSTANCE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_SCENE_INSTANCE_ACK( PKT_CLIGS_GET_SCENE_INSTANCE_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_SCENE_INSTANCE_ACK(const string &strData, PKT_CLIGS_GET_SCENE_INSTANCE_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_SCENE_INSTANCE_ACK(Json::Value &root, PKT_CLIGS_GET_SCENE_INSTANCE_ACK &data);
INT32 EncodePKT_CLIGS_EQUIP_STRENGTHEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_STRENGTHEN_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EQUIP_STRENGTHEN_REQ( PKT_CLIGS_EQUIP_STRENGTHEN_REQ &data );
BOOL FromJsonPKT_CLIGS_EQUIP_STRENGTHEN_REQ(const string &strData, PKT_CLIGS_EQUIP_STRENGTHEN_REQ &data);
BOOL FromJsonPKT_CLIGS_EQUIP_STRENGTHEN_REQ(Json::Value &root, PKT_CLIGS_EQUIP_STRENGTHEN_REQ &data);
INT32 EncodePKT_CLIGS_EQUIP_STRENGTHEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_STRENGTHEN_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EQUIP_STRENGTHEN_ACK( PKT_CLIGS_EQUIP_STRENGTHEN_ACK &data );
BOOL FromJsonPKT_CLIGS_EQUIP_STRENGTHEN_ACK(const string &strData, PKT_CLIGS_EQUIP_STRENGTHEN_ACK &data);
BOOL FromJsonPKT_CLIGS_EQUIP_STRENGTHEN_ACK(Json::Value &root, PKT_CLIGS_EQUIP_STRENGTHEN_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_SMITHY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SMITHY_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SMITHY_REQ( PKT_CLIGS_OPEN_SMITHY_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_SMITHY_REQ(const string &strData, PKT_CLIGS_OPEN_SMITHY_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_SMITHY_REQ(Json::Value &root, PKT_CLIGS_OPEN_SMITHY_REQ &data);
INT32 EncodeDT_BUY_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BUY_EQUIP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BUY_EQUIP_DATA( DT_BUY_EQUIP_DATA &data );
BOOL FromJsonDT_BUY_EQUIP_DATA(const string &strData, DT_BUY_EQUIP_DATA &data);
BOOL FromJsonDT_BUY_EQUIP_DATA(Json::Value &root, DT_BUY_EQUIP_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_SMITHY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SMITHY_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SMITHY_ACK( PKT_CLIGS_OPEN_SMITHY_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_SMITHY_ACK(const string &strData, PKT_CLIGS_OPEN_SMITHY_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_SMITHY_ACK(Json::Value &root, PKT_CLIGS_OPEN_SMITHY_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_RECRUIT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECRUIT_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_RECRUIT_REQ( PKT_CLIGS_OPEN_RECRUIT_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_RECRUIT_REQ(const string &strData, PKT_CLIGS_OPEN_RECRUIT_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_RECRUIT_REQ(Json::Value &root, PKT_CLIGS_OPEN_RECRUIT_REQ &data);
INT32 EncodeDT_HERO_ATTR_ADD_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_ATTR_ADD_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_ATTR_ADD_CLI( DT_HERO_ATTR_ADD_CLI &data );
BOOL FromJsonDT_HERO_ATTR_ADD_CLI(const string &strData, DT_HERO_ATTR_ADD_CLI &data);
BOOL FromJsonDT_HERO_ATTR_ADD_CLI(Json::Value &root, DT_HERO_ATTR_ADD_CLI &data);
INT32 EncodeDT_RECRUIT_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RECRUIT_HERO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RECRUIT_HERO_DATA( DT_RECRUIT_HERO_DATA &data );
BOOL FromJsonDT_RECRUIT_HERO_DATA(const string &strData, DT_RECRUIT_HERO_DATA &data);
BOOL FromJsonDT_RECRUIT_HERO_DATA(Json::Value &root, DT_RECRUIT_HERO_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_RECRUIT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RECRUIT_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_RECRUIT_ACK( PKT_CLIGS_OPEN_RECRUIT_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_RECRUIT_ACK(const string &strData, PKT_CLIGS_OPEN_RECRUIT_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_RECRUIT_ACK(Json::Value &root, PKT_CLIGS_OPEN_RECRUIT_ACK &data);
INT32 EncodePKT_CLIGS_RECRUIT_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECRUIT_HERO_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECRUIT_HERO_REQ( PKT_CLIGS_RECRUIT_HERO_REQ &data );
BOOL FromJsonPKT_CLIGS_RECRUIT_HERO_REQ(const string &strData, PKT_CLIGS_RECRUIT_HERO_REQ &data);
BOOL FromJsonPKT_CLIGS_RECRUIT_HERO_REQ(Json::Value &root, PKT_CLIGS_RECRUIT_HERO_REQ &data);
INT32 EncodePKT_CLIGS_RECRUIT_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECRUIT_HERO_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECRUIT_HERO_ACK( PKT_CLIGS_RECRUIT_HERO_ACK &data );
BOOL FromJsonPKT_CLIGS_RECRUIT_HERO_ACK(const string &strData, PKT_CLIGS_RECRUIT_HERO_ACK &data);
BOOL FromJsonPKT_CLIGS_RECRUIT_HERO_ACK(Json::Value &root, PKT_CLIGS_RECRUIT_HERO_ACK &data);
INT32 EncodePKT_CLIGS_VISIT_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VISIT_HERO_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_VISIT_HERO_REQ( PKT_CLIGS_VISIT_HERO_REQ &data );
BOOL FromJsonPKT_CLIGS_VISIT_HERO_REQ(const string &strData, PKT_CLIGS_VISIT_HERO_REQ &data);
BOOL FromJsonPKT_CLIGS_VISIT_HERO_REQ(Json::Value &root, PKT_CLIGS_VISIT_HERO_REQ &data);
INT32 EncodePKT_CLIGS_VISIT_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_VISIT_HERO_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_VISIT_HERO_ACK( PKT_CLIGS_VISIT_HERO_ACK &data );
BOOL FromJsonPKT_CLIGS_VISIT_HERO_ACK(const string &strData, PKT_CLIGS_VISIT_HERO_ACK &data);
BOOL FromJsonPKT_CLIGS_VISIT_HERO_ACK(Json::Value &root, PKT_CLIGS_VISIT_HERO_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_BAG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_BAG_REQ( PKT_CLIGS_OPEN_BAG_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_BAG_REQ(const string &strData, PKT_CLIGS_OPEN_BAG_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_BAG_REQ(Json::Value &root, PKT_CLIGS_OPEN_BAG_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_BAG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_BAG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_BAG_ACK( PKT_CLIGS_OPEN_BAG_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_BAG_ACK(const string &strData, PKT_CLIGS_OPEN_BAG_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_BAG_ACK(Json::Value &root, PKT_CLIGS_OPEN_BAG_ACK &data);
INT32 EncodePKT_CLIGS_ACCEPT_TASK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACCEPT_TASK_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ACCEPT_TASK_REQ( PKT_CLIGS_ACCEPT_TASK_REQ &data );
BOOL FromJsonPKT_CLIGS_ACCEPT_TASK_REQ(const string &strData, PKT_CLIGS_ACCEPT_TASK_REQ &data);
BOOL FromJsonPKT_CLIGS_ACCEPT_TASK_REQ(Json::Value &root, PKT_CLIGS_ACCEPT_TASK_REQ &data);
INT32 EncodeDT_INSTANCE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_INSTANCE_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_INSTANCE_DATA_CLI( DT_INSTANCE_DATA_CLI &data );
BOOL FromJsonDT_INSTANCE_DATA_CLI(const string &strData, DT_INSTANCE_DATA_CLI &data);
BOOL FromJsonDT_INSTANCE_DATA_CLI(Json::Value &root, DT_INSTANCE_DATA_CLI &data);
INT32 EncodePKT_CLIGS_ACCEPT_TASK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ACCEPT_TASK_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ACCEPT_TASK_ACK( PKT_CLIGS_ACCEPT_TASK_ACK &data );
BOOL FromJsonPKT_CLIGS_ACCEPT_TASK_ACK(const string &strData, PKT_CLIGS_ACCEPT_TASK_ACK &data);
BOOL FromJsonPKT_CLIGS_ACCEPT_TASK_ACK(Json::Value &root, PKT_CLIGS_ACCEPT_TASK_ACK &data);
INT32 EncodePKT_CLIGS_GIVEUP_TASK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVEUP_TASK_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GIVEUP_TASK_REQ( PKT_CLIGS_GIVEUP_TASK_REQ &data );
BOOL FromJsonPKT_CLIGS_GIVEUP_TASK_REQ(const string &strData, PKT_CLIGS_GIVEUP_TASK_REQ &data);
BOOL FromJsonPKT_CLIGS_GIVEUP_TASK_REQ(Json::Value &root, PKT_CLIGS_GIVEUP_TASK_REQ &data);
INT32 EncodePKT_CLIGS_GIVEUP_TASK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GIVEUP_TASK_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GIVEUP_TASK_ACK( PKT_CLIGS_GIVEUP_TASK_ACK &data );
BOOL FromJsonPKT_CLIGS_GIVEUP_TASK_ACK(const string &strData, PKT_CLIGS_GIVEUP_TASK_ACK &data);
BOOL FromJsonPKT_CLIGS_GIVEUP_TASK_ACK(Json::Value &root, PKT_CLIGS_GIVEUP_TASK_ACK &data);
INT32 EncodePKT_CLIGS_RECV_TASK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_TASK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_TASK_ENCOURAGE_REQ( PKT_CLIGS_RECV_TASK_ENCOURAGE_REQ &data );
BOOL FromJsonPKT_CLIGS_RECV_TASK_ENCOURAGE_REQ(const string &strData, PKT_CLIGS_RECV_TASK_ENCOURAGE_REQ &data);
BOOL FromJsonPKT_CLIGS_RECV_TASK_ENCOURAGE_REQ(Json::Value &root, PKT_CLIGS_RECV_TASK_ENCOURAGE_REQ &data);
INT32 EncodePKT_CLIGS_RECV_TASK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_TASK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_TASK_ENCOURAGE_ACK( PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK &data );
BOOL FromJsonPKT_CLIGS_RECV_TASK_ENCOURAGE_ACK(const string &strData, PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK &data);
BOOL FromJsonPKT_CLIGS_RECV_TASK_ENCOURAGE_ACK(Json::Value &root, PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_RACE_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RACE_BUILD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_RACE_BUILD_REQ( PKT_CLIGS_OPEN_RACE_BUILD_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_RACE_BUILD_REQ(const string &strData, PKT_CLIGS_OPEN_RACE_BUILD_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_RACE_BUILD_REQ(Json::Value &root, PKT_CLIGS_OPEN_RACE_BUILD_REQ &data);
INT32 EncodeDT_CHALLENGE_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CHALLENGE_PLAYER_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CHALLENGE_PLAYER_DATA( DT_CHALLENGE_PLAYER_DATA &data );
BOOL FromJsonDT_CHALLENGE_PLAYER_DATA(const string &strData, DT_CHALLENGE_PLAYER_DATA &data);
BOOL FromJsonDT_CHALLENGE_PLAYER_DATA(Json::Value &root, DT_CHALLENGE_PLAYER_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_RACE_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_RACE_BUILD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_RACE_BUILD_ACK( PKT_CLIGS_OPEN_RACE_BUILD_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_RACE_BUILD_ACK(const string &strData, PKT_CLIGS_OPEN_RACE_BUILD_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_RACE_BUILD_ACK(Json::Value &root, PKT_CLIGS_OPEN_RACE_BUILD_ACK &data);
INT32 EncodeDT_ENEMY_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_EQUIP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENEMY_EQUIP_DATA( DT_ENEMY_EQUIP_DATA &data );
BOOL FromJsonDT_ENEMY_EQUIP_DATA(const string &strData, DT_ENEMY_EQUIP_DATA &data);
BOOL FromJsonDT_ENEMY_EQUIP_DATA(Json::Value &root, DT_ENEMY_EQUIP_DATA &data);
INT32 EncodeDT_ENEMY_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_EQUIP_DATA_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENEMY_EQUIP_DATA_LST( DT_ENEMY_EQUIP_DATA_LST &data );
BOOL FromJsonDT_ENEMY_EQUIP_DATA_LST(const string &strData, DT_ENEMY_EQUIP_DATA_LST &data);
BOOL FromJsonDT_ENEMY_EQUIP_DATA_LST(Json::Value &root, DT_ENEMY_EQUIP_DATA_LST &data);
INT32 EncodeDT_ENEMY_HERO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_HERO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENEMY_HERO_DATA( DT_ENEMY_HERO_DATA &data );
BOOL FromJsonDT_ENEMY_HERO_DATA(const string &strData, DT_ENEMY_HERO_DATA &data);
BOOL FromJsonDT_ENEMY_HERO_DATA(Json::Value &root, DT_ENEMY_HERO_DATA &data);
INT32 EncodePKT_CLIGS_CHALLENGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CHALLENGE_REQ( PKT_CLIGS_CHALLENGE_REQ &data );
BOOL FromJsonPKT_CLIGS_CHALLENGE_REQ(const string &strData, PKT_CLIGS_CHALLENGE_REQ &data);
BOOL FromJsonPKT_CLIGS_CHALLENGE_REQ(Json::Value &root, PKT_CLIGS_CHALLENGE_REQ &data);
INT32 EncodePKT_CLIGS_CHALLENGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHALLENGE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CHALLENGE_ACK( PKT_CLIGS_CHALLENGE_ACK &data );
BOOL FromJsonPKT_CLIGS_CHALLENGE_ACK(const string &strData, PKT_CLIGS_CHALLENGE_ACK &data);
BOOL FromJsonPKT_CLIGS_CHALLENGE_ACK(Json::Value &root, PKT_CLIGS_CHALLENGE_ACK &data);
INT32 EncodePKT_CLIGS_RECV_RANK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RANK_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_RANK_ENCOURAGE_REQ( PKT_CLIGS_RECV_RANK_ENCOURAGE_REQ &data );
BOOL FromJsonPKT_CLIGS_RECV_RANK_ENCOURAGE_REQ(const string &strData, PKT_CLIGS_RECV_RANK_ENCOURAGE_REQ &data);
BOOL FromJsonPKT_CLIGS_RECV_RANK_ENCOURAGE_REQ(Json::Value &root, PKT_CLIGS_RECV_RANK_ENCOURAGE_REQ &data);
INT32 EncodePKT_CLIGS_RECV_RANK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_RANK_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_RANK_ENCOURAGE_ACK( PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK &data );
BOOL FromJsonPKT_CLIGS_RECV_RANK_ENCOURAGE_ACK(const string &strData, PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK &data);
BOOL FromJsonPKT_CLIGS_RECV_RANK_ENCOURAGE_ACK(Json::Value &root, PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK &data);
INT32 EncodePKT_CLIGS_GET_RANK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RANK_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_RANK_REQ( PKT_CLIGS_GET_RANK_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_RANK_REQ(const string &strData, PKT_CLIGS_GET_RANK_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_RANK_REQ(Json::Value &root, PKT_CLIGS_GET_RANK_REQ &data);
INT32 EncodeDT_RANK_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RANK_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RANK_DATA( DT_RANK_DATA &data );
BOOL FromJsonDT_RANK_DATA(const string &strData, DT_RANK_DATA &data);
BOOL FromJsonDT_RANK_DATA(Json::Value &root, DT_RANK_DATA &data);
INT32 EncodePKT_CLIGS_GET_RANK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RANK_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_RANK_ACK( PKT_CLIGS_GET_RANK_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_RANK_ACK(const string &strData, PKT_CLIGS_GET_RANK_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_RANK_ACK(Json::Value &root, PKT_CLIGS_GET_RANK_ACK &data);
INT32 EncodePKT_CLIGS_GET_RACE_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RACE_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_RACE_BATTLELOG_REQ( PKT_CLIGS_GET_RACE_BATTLELOG_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_RACE_BATTLELOG_REQ(const string &strData, PKT_CLIGS_GET_RACE_BATTLELOG_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_RACE_BATTLELOG_REQ(Json::Value &root, PKT_CLIGS_GET_RACE_BATTLELOG_REQ &data);
INT32 EncodeDT_RACE_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_RACE_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_RACE_BATTLELOG_DATA_CLI( DT_RACE_BATTLELOG_DATA_CLI &data );
BOOL FromJsonDT_RACE_BATTLELOG_DATA_CLI(const string &strData, DT_RACE_BATTLELOG_DATA_CLI &data);
BOOL FromJsonDT_RACE_BATTLELOG_DATA_CLI(Json::Value &root, DT_RACE_BATTLELOG_DATA_CLI &data);
INT32 EncodePKT_CLIGS_GET_RACE_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_RACE_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_RACE_BATTLELOG_ACK( PKT_CLIGS_GET_RACE_BATTLELOG_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_RACE_BATTLELOG_ACK(const string &strData, PKT_CLIGS_GET_RACE_BATTLELOG_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_RACE_BATTLELOG_ACK(Json::Value &root, PKT_CLIGS_GET_RACE_BATTLELOG_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_SHOP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHOP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SHOP_REQ( PKT_CLIGS_OPEN_SHOP_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_SHOP_REQ(const string &strData, PKT_CLIGS_OPEN_SHOP_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_SHOP_REQ(Json::Value &root, PKT_CLIGS_OPEN_SHOP_REQ &data);
INT32 EncodeDT_ITEM_DATA_SHOP(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ITEM_DATA_SHOP(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ITEM_DATA_SHOP( DT_ITEM_DATA_SHOP &data );
BOOL FromJsonDT_ITEM_DATA_SHOP(const string &strData, DT_ITEM_DATA_SHOP &data);
BOOL FromJsonDT_ITEM_DATA_SHOP(Json::Value &root, DT_ITEM_DATA_SHOP &data);
INT32 EncodePKT_CLIGS_OPEN_SHOP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SHOP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SHOP_ACK( PKT_CLIGS_OPEN_SHOP_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_SHOP_ACK(const string &strData, PKT_CLIGS_OPEN_SHOP_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_SHOP_ACK(Json::Value &root, PKT_CLIGS_OPEN_SHOP_ACK &data);
INT32 EncodePKT_CLIGS_BUY_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_ITEM_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BUY_ITEM_REQ( PKT_CLIGS_BUY_ITEM_REQ &data );
BOOL FromJsonPKT_CLIGS_BUY_ITEM_REQ(const string &strData, PKT_CLIGS_BUY_ITEM_REQ &data);
BOOL FromJsonPKT_CLIGS_BUY_ITEM_REQ(Json::Value &root, PKT_CLIGS_BUY_ITEM_REQ &data);
INT32 EncodePKT_CLIGS_BUY_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_ITEM_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BUY_ITEM_ACK( PKT_CLIGS_BUY_ITEM_ACK &data );
BOOL FromJsonPKT_CLIGS_BUY_ITEM_ACK(const string &strData, PKT_CLIGS_BUY_ITEM_ACK &data);
BOOL FromJsonPKT_CLIGS_BUY_ITEM_ACK(Json::Value &root, PKT_CLIGS_BUY_ITEM_ACK &data);
INT32 EncodePKT_CLIGS_SELL_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELL_ITEM_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SELL_ITEM_REQ( PKT_CLIGS_SELL_ITEM_REQ &data );
BOOL FromJsonPKT_CLIGS_SELL_ITEM_REQ(const string &strData, PKT_CLIGS_SELL_ITEM_REQ &data);
BOOL FromJsonPKT_CLIGS_SELL_ITEM_REQ(Json::Value &root, PKT_CLIGS_SELL_ITEM_REQ &data);
INT32 EncodePKT_CLIGS_SELL_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SELL_ITEM_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SELL_ITEM_ACK( PKT_CLIGS_SELL_ITEM_ACK &data );
BOOL FromJsonPKT_CLIGS_SELL_ITEM_ACK(const string &strData, PKT_CLIGS_SELL_ITEM_ACK &data);
BOOL FromJsonPKT_CLIGS_SELL_ITEM_ACK(Json::Value &root, PKT_CLIGS_SELL_ITEM_ACK &data);
INT32 EncodePKT_CLIGS_DISBAND_HERO_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DISBAND_HERO_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DISBAND_HERO_REQ( PKT_CLIGS_DISBAND_HERO_REQ &data );
BOOL FromJsonPKT_CLIGS_DISBAND_HERO_REQ(const string &strData, PKT_CLIGS_DISBAND_HERO_REQ &data);
BOOL FromJsonPKT_CLIGS_DISBAND_HERO_REQ(Json::Value &root, PKT_CLIGS_DISBAND_HERO_REQ &data);
INT32 EncodePKT_CLIGS_DISBAND_HERO_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DISBAND_HERO_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DISBAND_HERO_ACK( PKT_CLIGS_DISBAND_HERO_ACK &data );
BOOL FromJsonPKT_CLIGS_DISBAND_HERO_ACK(const string &strData, PKT_CLIGS_DISBAND_HERO_ACK &data);
BOOL FromJsonPKT_CLIGS_DISBAND_HERO_ACK(Json::Value &root, PKT_CLIGS_DISBAND_HERO_ACK &data);
INT32 EncodePKT_CLIGS_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EQUIP_REQ( PKT_CLIGS_EQUIP_REQ &data );
BOOL FromJsonPKT_CLIGS_EQUIP_REQ(const string &strData, PKT_CLIGS_EQUIP_REQ &data);
BOOL FromJsonPKT_CLIGS_EQUIP_REQ(Json::Value &root, PKT_CLIGS_EQUIP_REQ &data);
INT32 EncodePKT_CLIGS_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EQUIP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EQUIP_ACK( PKT_CLIGS_EQUIP_ACK &data );
BOOL FromJsonPKT_CLIGS_EQUIP_ACK(const string &strData, PKT_CLIGS_EQUIP_ACK &data);
BOOL FromJsonPKT_CLIGS_EQUIP_ACK(Json::Value &root, PKT_CLIGS_EQUIP_ACK &data);
INT32 EncodePKT_CLIGS_REGISTER_USERNAME_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REGISTER_USERNAME_NTF(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_REGISTER_USERNAME_NTF( PKT_CLIGS_REGISTER_USERNAME_NTF &data );
BOOL FromJsonPKT_CLIGS_REGISTER_USERNAME_NTF(const string &strData, PKT_CLIGS_REGISTER_USERNAME_NTF &data);
BOOL FromJsonPKT_CLIGS_REGISTER_USERNAME_NTF(Json::Value &root, PKT_CLIGS_REGISTER_USERNAME_NTF &data);
INT32 EncodePKT_CLIGS_OPEN_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_EMBATTLE_REQ( PKT_CLIGS_OPEN_EMBATTLE_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_EMBATTLE_REQ(const string &strData, PKT_CLIGS_OPEN_EMBATTLE_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_EMBATTLE_REQ(Json::Value &root, PKT_CLIGS_OPEN_EMBATTLE_REQ &data);
INT32 EncodeDT_HERO_EMBATLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_EMBATLE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_EMBATLE_DATA( DT_HERO_EMBATLE_DATA &data );
BOOL FromJsonDT_HERO_EMBATLE_DATA(const string &strData, DT_HERO_EMBATLE_DATA &data);
BOOL FromJsonDT_HERO_EMBATLE_DATA(Json::Value &root, DT_HERO_EMBATLE_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_EMBATTLE_ACK( PKT_CLIGS_OPEN_EMBATTLE_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_EMBATTLE_ACK(const string &strData, PKT_CLIGS_OPEN_EMBATTLE_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_EMBATTLE_ACK(Json::Value &root, PKT_CLIGS_OPEN_EMBATTLE_ACK &data);
INT32 EncodePKT_CLIGS_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EMBATTLE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EMBATTLE_REQ( PKT_CLIGS_EMBATTLE_REQ &data );
BOOL FromJsonPKT_CLIGS_EMBATTLE_REQ(const string &strData, PKT_CLIGS_EMBATTLE_REQ &data);
BOOL FromJsonPKT_CLIGS_EMBATTLE_REQ(Json::Value &root, PKT_CLIGS_EMBATTLE_REQ &data);
INT32 EncodePKT_CLIGS_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EMBATTLE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EMBATTLE_ACK( PKT_CLIGS_EMBATTLE_ACK &data );
BOOL FromJsonPKT_CLIGS_EMBATTLE_ACK(const string &strData, PKT_CLIGS_EMBATTLE_ACK &data);
BOOL FromJsonPKT_CLIGS_EMBATTLE_ACK(Json::Value &root, PKT_CLIGS_EMBATTLE_ACK &data);
INT32 EncodePKT_CLIGS_CLR_PLAYER_DATA_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_PLAYER_DATA_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_PLAYER_DATA_REQ( PKT_CLIGS_CLR_PLAYER_DATA_REQ &data );
BOOL FromJsonPKT_CLIGS_CLR_PLAYER_DATA_REQ(const string &strData, PKT_CLIGS_CLR_PLAYER_DATA_REQ &data);
BOOL FromJsonPKT_CLIGS_CLR_PLAYER_DATA_REQ(Json::Value &root, PKT_CLIGS_CLR_PLAYER_DATA_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_ITEM_MAKER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ITEM_MAKER_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_ITEM_MAKER_REQ( PKT_CLIGS_OPEN_ITEM_MAKER_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_ITEM_MAKER_REQ(const string &strData, PKT_CLIGS_OPEN_ITEM_MAKER_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_ITEM_MAKER_REQ(Json::Value &root, PKT_CLIGS_OPEN_ITEM_MAKER_REQ &data);
INT32 EncodeDT_EQUIP_DATA_MAKER_NEED(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EQUIP_DATA_MAKER_NEED(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EQUIP_DATA_MAKER_NEED( DT_EQUIP_DATA_MAKER_NEED &data );
BOOL FromJsonDT_EQUIP_DATA_MAKER_NEED(const string &strData, DT_EQUIP_DATA_MAKER_NEED &data);
BOOL FromJsonDT_EQUIP_DATA_MAKER_NEED(Json::Value &root, DT_EQUIP_DATA_MAKER_NEED &data);
INT32 EncodePKT_CLIGS_OPEN_ITEM_MAKER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ITEM_MAKER_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_ITEM_MAKER_ACK( PKT_CLIGS_OPEN_ITEM_MAKER_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_ITEM_MAKER_ACK(const string &strData, PKT_CLIGS_OPEN_ITEM_MAKER_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_ITEM_MAKER_ACK(Json::Value &root, PKT_CLIGS_OPEN_ITEM_MAKER_ACK &data);
INT32 EncodePKT_CLIGS_MAKE_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MAKE_ITEM_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_MAKE_ITEM_REQ( PKT_CLIGS_MAKE_ITEM_REQ &data );
BOOL FromJsonPKT_CLIGS_MAKE_ITEM_REQ(const string &strData, PKT_CLIGS_MAKE_ITEM_REQ &data);
BOOL FromJsonPKT_CLIGS_MAKE_ITEM_REQ(Json::Value &root, PKT_CLIGS_MAKE_ITEM_REQ &data);
INT32 EncodePKT_CLIGS_MAKE_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MAKE_ITEM_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_MAKE_ITEM_ACK( PKT_CLIGS_MAKE_ITEM_ACK &data );
BOOL FromJsonPKT_CLIGS_MAKE_ITEM_ACK(const string &strData, PKT_CLIGS_MAKE_ITEM_ACK &data);
BOOL FromJsonPKT_CLIGS_MAKE_ITEM_ACK(Json::Value &root, PKT_CLIGS_MAKE_ITEM_ACK &data);
INT32 EncodeDT_DRUG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRUG_DATA_CLI( DT_DRUG_DATA_CLI &data );
BOOL FromJsonDT_DRUG_DATA_CLI(const string &strData, DT_DRUG_DATA_CLI &data);
BOOL FromJsonDT_DRUG_DATA_CLI(Json::Value &root, DT_DRUG_DATA_CLI &data);
INT32 EncodeDT_DRUG_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRUG_DATA_LST_CLI( DT_DRUG_DATA_LST_CLI &data );
BOOL FromJsonDT_DRUG_DATA_LST_CLI(const string &strData, DT_DRUG_DATA_LST_CLI &data);
BOOL FromJsonDT_DRUG_DATA_LST_CLI(Json::Value &root, DT_DRUG_DATA_LST_CLI &data);
INT32 EncodePKT_CLIGS_GET_HERO_DRUG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_HERO_DRUG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_HERO_DRUG_REQ( PKT_CLIGS_GET_HERO_DRUG_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_HERO_DRUG_REQ(const string &strData, PKT_CLIGS_GET_HERO_DRUG_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_HERO_DRUG_REQ(Json::Value &root, PKT_CLIGS_GET_HERO_DRUG_REQ &data);
INT32 EncodeDT_DRUG_ITEM_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_ITEM_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRUG_ITEM_DATA( DT_DRUG_ITEM_DATA &data );
BOOL FromJsonDT_DRUG_ITEM_DATA(const string &strData, DT_DRUG_ITEM_DATA &data);
BOOL FromJsonDT_DRUG_ITEM_DATA(Json::Value &root, DT_DRUG_ITEM_DATA &data);
INT32 EncodeDT_DRUG_ITEM_DATA_LST(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DRUG_ITEM_DATA_LST(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DRUG_ITEM_DATA_LST( DT_DRUG_ITEM_DATA_LST &data );
BOOL FromJsonDT_DRUG_ITEM_DATA_LST(const string &strData, DT_DRUG_ITEM_DATA_LST &data);
BOOL FromJsonDT_DRUG_ITEM_DATA_LST(Json::Value &root, DT_DRUG_ITEM_DATA_LST &data);
INT32 EncodePKT_CLIGS_GET_HERO_DRUG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_HERO_DRUG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_HERO_DRUG_ACK( PKT_CLIGS_GET_HERO_DRUG_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_HERO_DRUG_ACK(const string &strData, PKT_CLIGS_GET_HERO_DRUG_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_HERO_DRUG_ACK(Json::Value &root, PKT_CLIGS_GET_HERO_DRUG_ACK &data);
INT32 EncodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ( PKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ &data );
BOOL FromJsonPKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ(const string &strData, PKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ &data);
BOOL FromJsonPKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ(Json::Value &root, PKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ &data);
INT32 EncodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK( PKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK &data );
BOOL FromJsonPKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK(const string &strData, PKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK &data);
BOOL FromJsonPKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK(Json::Value &root, PKT_CLIGS_RECV_ONLINE_ENCOURAGE_ACK &data);
INT32 EncodeDT_DATA_AFTER_PASS_ENCOURAGE_BOX(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_PASS_ENCOURAGE_BOX(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DATA_AFTER_PASS_ENCOURAGE_BOX( DT_DATA_AFTER_PASS_ENCOURAGE_BOX &data );
BOOL FromJsonDT_DATA_AFTER_PASS_ENCOURAGE_BOX(const string &strData, DT_DATA_AFTER_PASS_ENCOURAGE_BOX &data);
BOOL FromJsonDT_DATA_AFTER_PASS_ENCOURAGE_BOX(Json::Value &root, DT_DATA_AFTER_PASS_ENCOURAGE_BOX &data);
INT32 EncodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ( PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ(const string &strData, PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ(Json::Value &root, PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK( PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK(const string &strData, PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK(Json::Value &root, PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK &data);
INT32 EncodePKT_CLIGS_INCREASE_BAG_SIZE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_INCREASE_BAG_SIZE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_INCREASE_BAG_SIZE_REQ( PKT_CLIGS_INCREASE_BAG_SIZE_REQ &data );
BOOL FromJsonPKT_CLIGS_INCREASE_BAG_SIZE_REQ(const string &strData, PKT_CLIGS_INCREASE_BAG_SIZE_REQ &data);
BOOL FromJsonPKT_CLIGS_INCREASE_BAG_SIZE_REQ(Json::Value &root, PKT_CLIGS_INCREASE_BAG_SIZE_REQ &data);
INT32 EncodePKT_CLIGS_INCREASE_BAG_SIZE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_INCREASE_BAG_SIZE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_INCREASE_BAG_SIZE_ACK( PKT_CLIGS_INCREASE_BAG_SIZE_ACK &data );
BOOL FromJsonPKT_CLIGS_INCREASE_BAG_SIZE_ACK(const string &strData, PKT_CLIGS_INCREASE_BAG_SIZE_ACK &data);
BOOL FromJsonPKT_CLIGS_INCREASE_BAG_SIZE_ACK(Json::Value &root, PKT_CLIGS_INCREASE_BAG_SIZE_ACK &data);
INT32 EncodePKT_CLIGS_ONHOOK_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ONHOOK_REQ( PKT_CLIGS_ONHOOK_REQ &data );
BOOL FromJsonPKT_CLIGS_ONHOOK_REQ(const string &strData, PKT_CLIGS_ONHOOK_REQ &data);
BOOL FromJsonPKT_CLIGS_ONHOOK_REQ(Json::Value &root, PKT_CLIGS_ONHOOK_REQ &data);
INT32 EncodeDT_HERO_UPGRADE_DATA2(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_UPGRADE_DATA2(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_UPGRADE_DATA2( DT_HERO_UPGRADE_DATA2 &data );
BOOL FromJsonDT_HERO_UPGRADE_DATA2(const string &strData, DT_HERO_UPGRADE_DATA2 &data);
BOOL FromJsonDT_HERO_UPGRADE_DATA2(Json::Value &root, DT_HERO_UPGRADE_DATA2 &data);
INT32 EncodeDT_DATA_AFTER_ONHOOK(void *pHost, CNetData* poNetData);
INT32 DecodeDT_DATA_AFTER_ONHOOK(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_DATA_AFTER_ONHOOK( DT_DATA_AFTER_ONHOOK &data );
BOOL FromJsonDT_DATA_AFTER_ONHOOK(const string &strData, DT_DATA_AFTER_ONHOOK &data);
BOOL FromJsonDT_DATA_AFTER_ONHOOK(Json::Value &root, DT_DATA_AFTER_ONHOOK &data);
INT32 EncodePKT_CLIGS_ONHOOK_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ONHOOK_ACK( PKT_CLIGS_ONHOOK_ACK &data );
BOOL FromJsonPKT_CLIGS_ONHOOK_ACK(const string &strData, PKT_CLIGS_ONHOOK_ACK &data);
BOOL FromJsonPKT_CLIGS_ONHOOK_ACK(Json::Value &root, PKT_CLIGS_ONHOOK_ACK &data);
INT32 EncodePKT_CLIGS_CLR_CHALLENGE_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CHALLENGE_CD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_CHALLENGE_CD_REQ( PKT_CLIGS_CLR_CHALLENGE_CD_REQ &data );
BOOL FromJsonPKT_CLIGS_CLR_CHALLENGE_CD_REQ(const string &strData, PKT_CLIGS_CLR_CHALLENGE_CD_REQ &data);
BOOL FromJsonPKT_CLIGS_CLR_CHALLENGE_CD_REQ(Json::Value &root, PKT_CLIGS_CLR_CHALLENGE_CD_REQ &data);
INT32 EncodePKT_CLIGS_CLR_CHALLENGE_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CHALLENGE_CD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_CHALLENGE_CD_ACK( PKT_CLIGS_CLR_CHALLENGE_CD_ACK &data );
BOOL FromJsonPKT_CLIGS_CLR_CHALLENGE_CD_ACK(const string &strData, PKT_CLIGS_CLR_CHALLENGE_CD_ACK &data);
BOOL FromJsonPKT_CLIGS_CLR_CHALLENGE_CD_ACK(Json::Value &root, PKT_CLIGS_CLR_CHALLENGE_CD_ACK &data);
INT32 EncodePKT_CLIGS_SYNC_TIME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SYNC_TIME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SYNC_TIME_REQ( PKT_CLIGS_SYNC_TIME_REQ &data );
BOOL FromJsonPKT_CLIGS_SYNC_TIME_REQ(const string &strData, PKT_CLIGS_SYNC_TIME_REQ &data);
BOOL FromJsonPKT_CLIGS_SYNC_TIME_REQ(Json::Value &root, PKT_CLIGS_SYNC_TIME_REQ &data);
INT32 EncodePKT_CLIGS_SYNC_TIME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SYNC_TIME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SYNC_TIME_ACK( PKT_CLIGS_SYNC_TIME_ACK &data );
BOOL FromJsonPKT_CLIGS_SYNC_TIME_ACK(const string &strData, PKT_CLIGS_SYNC_TIME_ACK &data);
BOOL FromJsonPKT_CLIGS_SYNC_TIME_ACK(Json::Value &root, PKT_CLIGS_SYNC_TIME_ACK &data);
INT32 EncodePKT_CLILS_REGISTER_DSPNAME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_DSPNAME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_REGISTER_DSPNAME_REQ( PKT_CLILS_REGISTER_DSPNAME_REQ &data );
BOOL FromJsonPKT_CLILS_REGISTER_DSPNAME_REQ(const string &strData, PKT_CLILS_REGISTER_DSPNAME_REQ &data);
BOOL FromJsonPKT_CLILS_REGISTER_DSPNAME_REQ(Json::Value &root, PKT_CLILS_REGISTER_DSPNAME_REQ &data);
INT32 EncodePKT_CLILS_REGISTER_DSPNAME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_REGISTER_DSPNAME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_REGISTER_DSPNAME_ACK( PKT_CLILS_REGISTER_DSPNAME_ACK &data );
BOOL FromJsonPKT_CLILS_REGISTER_DSPNAME_ACK(const string &strData, PKT_CLILS_REGISTER_DSPNAME_ACK &data);
BOOL FromJsonPKT_CLILS_REGISTER_DSPNAME_ACK(Json::Value &root, PKT_CLILS_REGISTER_DSPNAME_ACK &data);
INT32 EncodePKT_CLILS_USE_GOODS_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_USE_GOODS_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_USE_GOODS_REQ( PKT_CLILS_USE_GOODS_REQ &data );
BOOL FromJsonPKT_CLILS_USE_GOODS_REQ(const string &strData, PKT_CLILS_USE_GOODS_REQ &data);
BOOL FromJsonPKT_CLILS_USE_GOODS_REQ(Json::Value &root, PKT_CLILS_USE_GOODS_REQ &data);
INT32 EncodePKT_CLILS_USE_GOODS_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_USE_GOODS_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_USE_GOODS_ACK( PKT_CLILS_USE_GOODS_ACK &data );
BOOL FromJsonPKT_CLILS_USE_GOODS_ACK(const string &strData, PKT_CLILS_USE_GOODS_ACK &data);
BOOL FromJsonPKT_CLILS_USE_GOODS_ACK(Json::Value &root, PKT_CLILS_USE_GOODS_ACK &data);
INT32 EncodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ( PKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ &data );
BOOL FromJsonPKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ(const string &strData, PKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ &data);
BOOL FromJsonPKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ(Json::Value &root, PKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ &data);
INT32 EncodeDT_LOGIN_ENCOURAG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOGIN_ENCOURAG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOGIN_ENCOURAG_DATA( DT_LOGIN_ENCOURAG_DATA &data );
BOOL FromJsonDT_LOGIN_ENCOURAG_DATA(const string &strData, DT_LOGIN_ENCOURAG_DATA &data);
BOOL FromJsonDT_LOGIN_ENCOURAG_DATA(Json::Value &root, DT_LOGIN_ENCOURAG_DATA &data);
INT32 EncodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK( PKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK &data );
BOOL FromJsonPKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK(const string &strData, PKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK &data);
BOOL FromJsonPKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK(Json::Value &root, PKT_CLILS_OPEN_LOGIN_ENCOURAGE_ACK &data);
INT32 EncodePKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ( PKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ &data );
BOOL FromJsonPKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ(const string &strData, PKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ &data);
BOOL FromJsonPKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ(Json::Value &root, PKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ &data);
INT32 EncodePKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK( PKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK &data );
BOOL FromJsonPKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK(const string &strData, PKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK &data);
BOOL FromJsonPKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK(Json::Value &root, PKT_CLILS_RATE_LOGIN_ENCOURAGE_ACK &data);
INT32 EncodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ( PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ &data );
BOOL FromJsonPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ(const string &strData, PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ &data);
BOOL FromJsonPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ(Json::Value &root, PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ &data);
INT32 EncodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK( PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK &data );
BOOL FromJsonPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK(const string &strData, PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK &data);
BOOL FromJsonPKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK(Json::Value &root, PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_ACK &data);
INT32 EncodeDT_CAPTURE_WORK_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_WORK_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CAPTURE_WORK_DATA_CLI( DT_CAPTURE_WORK_DATA_CLI &data );
BOOL FromJsonDT_CAPTURE_WORK_DATA_CLI(const string &strData, DT_CAPTURE_WORK_DATA_CLI &data);
BOOL FromJsonDT_CAPTURE_WORK_DATA_CLI(Json::Value &root, DT_CAPTURE_WORK_DATA_CLI &data);
INT32 EncodeDT_CAPTURE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CAPTURE_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CAPTURE_DATA_CLI( DT_CAPTURE_DATA_CLI &data );
BOOL FromJsonDT_CAPTURE_DATA_CLI(const string &strData, DT_CAPTURE_DATA_CLI &data);
BOOL FromJsonDT_CAPTURE_DATA_CLI(Json::Value &root, DT_CAPTURE_DATA_CLI &data);
INT32 EncodePKT_CLIGS_PLUNDER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_PLUNDER_REQ( PKT_CLIGS_PLUNDER_REQ &data );
BOOL FromJsonPKT_CLIGS_PLUNDER_REQ(const string &strData, PKT_CLIGS_PLUNDER_REQ &data);
BOOL FromJsonPKT_CLIGS_PLUNDER_REQ(Json::Value &root, PKT_CLIGS_PLUNDER_REQ &data);
INT32 EncodeDT_PLUNDER_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_ENCOURAGE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_ENCOURAGE_DATA( DT_PLUNDER_ENCOURAGE_DATA &data );
BOOL FromJsonDT_PLUNDER_ENCOURAGE_DATA(const string &strData, DT_PLUNDER_ENCOURAGE_DATA &data);
BOOL FromJsonDT_PLUNDER_ENCOURAGE_DATA(Json::Value &root, DT_PLUNDER_ENCOURAGE_DATA &data);
INT32 EncodeDT_BECAPTURE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_BECAPTURE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_BECAPTURE_DATA( DT_BECAPTURE_DATA &data );
BOOL FromJsonDT_BECAPTURE_DATA(const string &strData, DT_BECAPTURE_DATA &data);
BOOL FromJsonDT_BECAPTURE_DATA(Json::Value &root, DT_BECAPTURE_DATA &data);
INT32 EncodePKT_CLIGS_PLUNDER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_PLUNDER_ACK( PKT_CLIGS_PLUNDER_ACK &data );
BOOL FromJsonPKT_CLIGS_PLUNDER_ACK(const string &strData, PKT_CLIGS_PLUNDER_ACK &data);
BOOL FromJsonPKT_CLIGS_PLUNDER_ACK(Json::Value &root, PKT_CLIGS_PLUNDER_ACK &data);
INT32 EncodeDT_PLUNDER_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_BATTLELOG_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_BATTLELOG_DATA_CLI( DT_PLUNDER_BATTLELOG_DATA_CLI &data );
BOOL FromJsonDT_PLUNDER_BATTLELOG_DATA_CLI(const string &strData, DT_PLUNDER_BATTLELOG_DATA_CLI &data);
BOOL FromJsonDT_PLUNDER_BATTLELOG_DATA_CLI(Json::Value &root, DT_PLUNDER_BATTLELOG_DATA_CLI &data);
INT32 EncodePKT_CLIGS_OPEN_CAPTURE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CAPTURE_TAB_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_CAPTURE_TAB_REQ( PKT_CLIGS_OPEN_CAPTURE_TAB_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_CAPTURE_TAB_REQ(const string &strData, PKT_CLIGS_OPEN_CAPTURE_TAB_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_CAPTURE_TAB_REQ(Json::Value &root, PKT_CLIGS_OPEN_CAPTURE_TAB_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_CAPTURE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CAPTURE_TAB_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_CAPTURE_TAB_ACK( PKT_CLIGS_OPEN_CAPTURE_TAB_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_CAPTURE_TAB_ACK(const string &strData, PKT_CLIGS_OPEN_CAPTURE_TAB_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_CAPTURE_TAB_ACK(Json::Value &root, PKT_CLIGS_OPEN_CAPTURE_TAB_ACK &data);
INT32 EncodeDT_ENEMY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_ENEMY_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_ENEMY_DATA_CLI( DT_ENEMY_DATA_CLI &data );
BOOL FromJsonDT_ENEMY_DATA_CLI(const string &strData, DT_ENEMY_DATA_CLI &data);
BOOL FromJsonDT_ENEMY_DATA_CLI(Json::Value &root, DT_ENEMY_DATA_CLI &data);
INT32 EncodePKT_CLIGS_OPEN_ENEMY_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ENEMY_TAB_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_ENEMY_TAB_REQ( PKT_CLIGS_OPEN_ENEMY_TAB_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_ENEMY_TAB_REQ(const string &strData, PKT_CLIGS_OPEN_ENEMY_TAB_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_ENEMY_TAB_REQ(Json::Value &root, PKT_CLIGS_OPEN_ENEMY_TAB_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_ENEMY_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_ENEMY_TAB_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_ENEMY_TAB_ACK( PKT_CLIGS_OPEN_ENEMY_TAB_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_ENEMY_TAB_ACK(const string &strData, PKT_CLIGS_OPEN_ENEMY_TAB_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_ENEMY_TAB_ACK(Json::Value &root, PKT_CLIGS_OPEN_ENEMY_TAB_ACK &data);
INT32 EncodePKT_CLIGS_DEL_ENEMY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_ENEMY_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DEL_ENEMY_REQ( PKT_CLIGS_DEL_ENEMY_REQ &data );
BOOL FromJsonPKT_CLIGS_DEL_ENEMY_REQ(const string &strData, PKT_CLIGS_DEL_ENEMY_REQ &data);
BOOL FromJsonPKT_CLIGS_DEL_ENEMY_REQ(Json::Value &root, PKT_CLIGS_DEL_ENEMY_REQ &data);
INT32 EncodePKT_CLIGS_DEL_ENEMY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DEL_ENEMY_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DEL_ENEMY_ACK( PKT_CLIGS_DEL_ENEMY_ACK &data );
BOOL FromJsonPKT_CLIGS_DEL_ENEMY_ACK(const string &strData, PKT_CLIGS_DEL_ENEMY_ACK &data);
BOOL FromJsonPKT_CLIGS_DEL_ENEMY_ACK(Json::Value &root, PKT_CLIGS_DEL_ENEMY_ACK &data);
INT32 EncodePKT_CLIGS_PLUNDER_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PLUNDER_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_PLUNDER_BATTLELOG_NTF( PKT_CLIGS_PLUNDER_BATTLELOG_NTF &data );
BOOL FromJsonPKT_CLIGS_PLUNDER_BATTLELOG_NTF(const string &strData, PKT_CLIGS_PLUNDER_BATTLELOG_NTF &data);
BOOL FromJsonPKT_CLIGS_PLUNDER_BATTLELOG_NTF(Json::Value &root, PKT_CLIGS_PLUNDER_BATTLELOG_NTF &data);
INT32 EncodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ( PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ(const string &strData, PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ(Json::Value &root, PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_REQ &data);
INT32 EncodeDT_PLUNDER_PLAYER_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_PLUNDER_PLAYER_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_PLUNDER_PLAYER_DATA( DT_PLUNDER_PLAYER_DATA &data );
BOOL FromJsonDT_PLUNDER_PLAYER_DATA(const string &strData, DT_PLUNDER_PLAYER_DATA &data);
BOOL FromJsonDT_PLUNDER_PLAYER_DATA(Json::Value &root, DT_PLUNDER_PLAYER_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK( PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK(const string &strData, PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK(Json::Value &root, PKT_CLIGS_OPEN_PLUNDER_RECOMMEND_PLAYER_ACK &data);
INT32 EncodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ( PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ &data );
BOOL FromJsonPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ(const string &strData, PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ &data);
BOOL FromJsonPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ(Json::Value &root, PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_REQ &data);
INT32 EncodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK( PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK &data );
BOOL FromJsonPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK(const string &strData, PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK &data);
BOOL FromJsonPKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK(Json::Value &root, PKT_CLIGS_REFRESH_PLUNDER_RECOMMEND_ACK &data);
INT32 EncodePKT_CLIGS_FREE_CAPTURE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_CAPTURE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_FREE_CAPTURE_REQ( PKT_CLIGS_FREE_CAPTURE_REQ &data );
BOOL FromJsonPKT_CLIGS_FREE_CAPTURE_REQ(const string &strData, PKT_CLIGS_FREE_CAPTURE_REQ &data);
BOOL FromJsonPKT_CLIGS_FREE_CAPTURE_REQ(Json::Value &root, PKT_CLIGS_FREE_CAPTURE_REQ &data);
INT32 EncodePKT_CLIGS_FREE_CAPTURE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_CAPTURE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_FREE_CAPTURE_ACK( PKT_CLIGS_FREE_CAPTURE_ACK &data );
BOOL FromJsonPKT_CLIGS_FREE_CAPTURE_ACK(const string &strData, PKT_CLIGS_FREE_CAPTURE_ACK &data);
BOOL FromJsonPKT_CLIGS_FREE_CAPTURE_ACK(Json::Value &root, PKT_CLIGS_FREE_CAPTURE_ACK &data);
INT32 EncodePKT_CLIGS_COLLECT_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COLLECT_INCOME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_COLLECT_INCOME_REQ( PKT_CLIGS_COLLECT_INCOME_REQ &data );
BOOL FromJsonPKT_CLIGS_COLLECT_INCOME_REQ(const string &strData, PKT_CLIGS_COLLECT_INCOME_REQ &data);
BOOL FromJsonPKT_CLIGS_COLLECT_INCOME_REQ(Json::Value &root, PKT_CLIGS_COLLECT_INCOME_REQ &data);
INT32 EncodePKT_CLIGS_COLLECT_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COLLECT_INCOME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_COLLECT_INCOME_ACK( PKT_CLIGS_COLLECT_INCOME_ACK &data );
BOOL FromJsonPKT_CLIGS_COLLECT_INCOME_ACK(const string &strData, PKT_CLIGS_COLLECT_INCOME_ACK &data);
BOOL FromJsonPKT_CLIGS_COLLECT_INCOME_ACK(Json::Value &root, PKT_CLIGS_COLLECT_INCOME_ACK &data);
INT32 EncodePKT_CLIGS_BLEED_CAPTURE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BLEED_CAPTURE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BLEED_CAPTURE_REQ( PKT_CLIGS_BLEED_CAPTURE_REQ &data );
BOOL FromJsonPKT_CLIGS_BLEED_CAPTURE_REQ(const string &strData, PKT_CLIGS_BLEED_CAPTURE_REQ &data);
BOOL FromJsonPKT_CLIGS_BLEED_CAPTURE_REQ(Json::Value &root, PKT_CLIGS_BLEED_CAPTURE_REQ &data);
INT32 EncodePKT_CLIGS_BLEED_CAPTURE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BLEED_CAPTURE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BLEED_CAPTURE_ACK( PKT_CLIGS_BLEED_CAPTURE_ACK &data );
BOOL FromJsonPKT_CLIGS_BLEED_CAPTURE_ACK(const string &strData, PKT_CLIGS_BLEED_CAPTURE_ACK &data);
BOOL FromJsonPKT_CLIGS_BLEED_CAPTURE_ACK(Json::Value &root, PKT_CLIGS_BLEED_CAPTURE_ACK &data);
INT32 EncodePKT_CLIGS_SET_WORK_TYPE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SET_WORK_TYPE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SET_WORK_TYPE_REQ( PKT_CLIGS_SET_WORK_TYPE_REQ &data );
BOOL FromJsonPKT_CLIGS_SET_WORK_TYPE_REQ(const string &strData, PKT_CLIGS_SET_WORK_TYPE_REQ &data);
BOOL FromJsonPKT_CLIGS_SET_WORK_TYPE_REQ(Json::Value &root, PKT_CLIGS_SET_WORK_TYPE_REQ &data);
INT32 EncodePKT_CLIGS_SET_WORK_TYPE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SET_WORK_TYPE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SET_WORK_TYPE_ACK( PKT_CLIGS_SET_WORK_TYPE_ACK &data );
BOOL FromJsonPKT_CLIGS_SET_WORK_TYPE_ACK(const string &strData, PKT_CLIGS_SET_WORK_TYPE_ACK &data);
BOOL FromJsonPKT_CLIGS_SET_WORK_TYPE_ACK(Json::Value &root, PKT_CLIGS_SET_WORK_TYPE_ACK &data);
INT32 EncodeDT_MONEY_TREE_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MONEY_TREE_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_MONEY_TREE_DATA_CLI( DT_MONEY_TREE_DATA_CLI &data );
BOOL FromJsonDT_MONEY_TREE_DATA_CLI(const string &strData, DT_MONEY_TREE_DATA_CLI &data);
BOOL FromJsonDT_MONEY_TREE_DATA_CLI(Json::Value &root, DT_MONEY_TREE_DATA_CLI &data);
INT32 EncodePKT_CLIGS_OPEN_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_MONEY_TREE_REQ( PKT_CLIGS_OPEN_MONEY_TREE_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_MONEY_TREE_REQ(const string &strData, PKT_CLIGS_OPEN_MONEY_TREE_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_MONEY_TREE_REQ(Json::Value &root, PKT_CLIGS_OPEN_MONEY_TREE_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_MONEY_TREE_ACK( PKT_CLIGS_OPEN_MONEY_TREE_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_MONEY_TREE_ACK(const string &strData, PKT_CLIGS_OPEN_MONEY_TREE_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_MONEY_TREE_ACK(Json::Value &root, PKT_CLIGS_OPEN_MONEY_TREE_ACK &data);
INT32 EncodePKT_CLIGS_ROCK_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ROCK_MONEY_TREE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ROCK_MONEY_TREE_REQ( PKT_CLIGS_ROCK_MONEY_TREE_REQ &data );
BOOL FromJsonPKT_CLIGS_ROCK_MONEY_TREE_REQ(const string &strData, PKT_CLIGS_ROCK_MONEY_TREE_REQ &data);
BOOL FromJsonPKT_CLIGS_ROCK_MONEY_TREE_REQ(Json::Value &root, PKT_CLIGS_ROCK_MONEY_TREE_REQ &data);
INT32 EncodePKT_CLIGS_ROCK_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ROCK_MONEY_TREE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ROCK_MONEY_TREE_ACK( PKT_CLIGS_ROCK_MONEY_TREE_ACK &data );
BOOL FromJsonPKT_CLIGS_ROCK_MONEY_TREE_ACK(const string &strData, PKT_CLIGS_ROCK_MONEY_TREE_ACK &data);
BOOL FromJsonPKT_CLIGS_ROCK_MONEY_TREE_ACK(Json::Value &root, PKT_CLIGS_ROCK_MONEY_TREE_ACK &data);
INT32 EncodePKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ( PKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ(const string &strData, PKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ(Json::Value &root, PKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ &data);
INT32 EncodePKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK( PKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK(const string &strData, PKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK(Json::Value &root, PKT_CLIGS_GET_PLUNDER_BATTLELOG_ACK &data);
INT32 EncodeDT_GODWEAPON_ATTR_INC_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_ATTR_INC_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GODWEAPON_ATTR_INC_DATA( DT_GODWEAPON_ATTR_INC_DATA &data );
BOOL FromJsonDT_GODWEAPON_ATTR_INC_DATA(const string &strData, DT_GODWEAPON_ATTR_INC_DATA &data);
BOOL FromJsonDT_GODWEAPON_ATTR_INC_DATA(Json::Value &root, DT_GODWEAPON_ATTR_INC_DATA &data);
INT32 EncodeDT_GODWEAPON_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_ATTR_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GODWEAPON_ATTR_DATA( DT_GODWEAPON_ATTR_DATA &data );
BOOL FromJsonDT_GODWEAPON_ATTR_DATA(const string &strData, DT_GODWEAPON_ATTR_DATA &data);
BOOL FromJsonDT_GODWEAPON_ATTR_DATA(Json::Value &root, DT_GODWEAPON_ATTR_DATA &data);
INT32 EncodeDT_GODWEAPON_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_GODWEAPON_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_GODWEAPON_DATA_CLI( DT_GODWEAPON_DATA_CLI &data );
BOOL FromJsonDT_GODWEAPON_DATA_CLI(const string &strData, DT_GODWEAPON_DATA_CLI &data);
BOOL FromJsonDT_GODWEAPON_DATA_CLI(Json::Value &root, DT_GODWEAPON_DATA_CLI &data);
INT32 EncodePKT_CLIGS_OPEN_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_GODWEAPON_REQ( PKT_CLIGS_OPEN_GODWEAPON_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_GODWEAPON_REQ(const string &strData, PKT_CLIGS_OPEN_GODWEAPON_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_GODWEAPON_REQ(Json::Value &root, PKT_CLIGS_OPEN_GODWEAPON_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_GODWEAPON_ACK( PKT_CLIGS_OPEN_GODWEAPON_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_GODWEAPON_ACK(const string &strData, PKT_CLIGS_OPEN_GODWEAPON_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_GODWEAPON_ACK(Json::Value &root, PKT_CLIGS_OPEN_GODWEAPON_ACK &data);
INT32 EncodePKT_CLIGS_UPGRADE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPGRADE_GODWEAPON_REQ( PKT_CLIGS_UPGRADE_GODWEAPON_REQ &data );
BOOL FromJsonPKT_CLIGS_UPGRADE_GODWEAPON_REQ(const string &strData, PKT_CLIGS_UPGRADE_GODWEAPON_REQ &data);
BOOL FromJsonPKT_CLIGS_UPGRADE_GODWEAPON_REQ(Json::Value &root, PKT_CLIGS_UPGRADE_GODWEAPON_REQ &data);
INT32 EncodePKT_CLIGS_UPGRADE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPGRADE_GODWEAPON_ACK( PKT_CLIGS_UPGRADE_GODWEAPON_ACK &data );
BOOL FromJsonPKT_CLIGS_UPGRADE_GODWEAPON_ACK(const string &strData, PKT_CLIGS_UPGRADE_GODWEAPON_ACK &data);
BOOL FromJsonPKT_CLIGS_UPGRADE_GODWEAPON_ACK(Json::Value &root, PKT_CLIGS_UPGRADE_GODWEAPON_ACK &data);
INT32 EncodePKT_CLIGS_FREE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_GODWEAPON_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_FREE_GODWEAPON_REQ( PKT_CLIGS_FREE_GODWEAPON_REQ &data );
BOOL FromJsonPKT_CLIGS_FREE_GODWEAPON_REQ(const string &strData, PKT_CLIGS_FREE_GODWEAPON_REQ &data);
BOOL FromJsonPKT_CLIGS_FREE_GODWEAPON_REQ(Json::Value &root, PKT_CLIGS_FREE_GODWEAPON_REQ &data);
INT32 EncodePKT_CLIGS_FREE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_FREE_GODWEAPON_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_FREE_GODWEAPON_ACK( PKT_CLIGS_FREE_GODWEAPON_ACK &data );
BOOL FromJsonPKT_CLIGS_FREE_GODWEAPON_ACK(const string &strData, PKT_CLIGS_FREE_GODWEAPON_ACK &data);
BOOL FromJsonPKT_CLIGS_FREE_GODWEAPON_ACK(Json::Value &root, PKT_CLIGS_FREE_GODWEAPON_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_AWAKEN_REQ( PKT_CLIGS_OPEN_AWAKEN_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_AWAKEN_REQ(const string &strData, PKT_CLIGS_OPEN_AWAKEN_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_AWAKEN_REQ(Json::Value &root, PKT_CLIGS_OPEN_AWAKEN_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_AWAKEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_AWAKEN_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_AWAKEN_ACK( PKT_CLIGS_OPEN_AWAKEN_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_AWAKEN_ACK(const string &strData, PKT_CLIGS_OPEN_AWAKEN_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_AWAKEN_ACK(Json::Value &root, PKT_CLIGS_OPEN_AWAKEN_ACK &data);
INT32 EncodePKT_CLIGS_AWAKEN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AWAKEN_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_AWAKEN_REQ( PKT_CLIGS_AWAKEN_REQ &data );
BOOL FromJsonPKT_CLIGS_AWAKEN_REQ(const string &strData, PKT_CLIGS_AWAKEN_REQ &data);
BOOL FromJsonPKT_CLIGS_AWAKEN_REQ(Json::Value &root, PKT_CLIGS_AWAKEN_REQ &data);
INT32 EncodePKT_CLIGS_AWAKEN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_AWAKEN_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_AWAKEN_ACK( PKT_CLIGS_AWAKEN_ACK &data );
BOOL FromJsonPKT_CLIGS_AWAKEN_ACK(const string &strData, PKT_CLIGS_AWAKEN_ACK &data);
BOOL FromJsonPKT_CLIGS_AWAKEN_ACK(Json::Value &root, PKT_CLIGS_AWAKEN_ACK &data);
INT32 EncodePKT_CLIGS_PICKUP_STUDY_CLIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PICKUP_STUDY_CLIP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_PICKUP_STUDY_CLIP_REQ( PKT_CLIGS_PICKUP_STUDY_CLIP_REQ &data );
BOOL FromJsonPKT_CLIGS_PICKUP_STUDY_CLIP_REQ(const string &strData, PKT_CLIGS_PICKUP_STUDY_CLIP_REQ &data);
BOOL FromJsonPKT_CLIGS_PICKUP_STUDY_CLIP_REQ(Json::Value &root, PKT_CLIGS_PICKUP_STUDY_CLIP_REQ &data);
INT32 EncodePKT_CLIGS_PICKUP_STUDY_CLIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_PICKUP_STUDY_CLIP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_PICKUP_STUDY_CLIP_ACK( PKT_CLIGS_PICKUP_STUDY_CLIP_ACK &data );
BOOL FromJsonPKT_CLIGS_PICKUP_STUDY_CLIP_ACK(const string &strData, PKT_CLIGS_PICKUP_STUDY_CLIP_ACK &data);
BOOL FromJsonPKT_CLIGS_PICKUP_STUDY_CLIP_ACK(Json::Value &root, PKT_CLIGS_PICKUP_STUDY_CLIP_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_STUDY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STUDY_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_STUDY_REQ( PKT_CLIGS_OPEN_STUDY_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_REQ(const string &strData, PKT_CLIGS_OPEN_STUDY_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_REQ(Json::Value &root, PKT_CLIGS_OPEN_STUDY_REQ &data);
INT32 EncodeDT_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STUDY_DATA_CLI( DT_STUDY_DATA_CLI &data );
BOOL FromJsonDT_STUDY_DATA_CLI(const string &strData, DT_STUDY_DATA_CLI &data);
BOOL FromJsonDT_STUDY_DATA_CLI(Json::Value &root, DT_STUDY_DATA_CLI &data);
INT32 EncodeDT_STUDY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STUDY_DATA_LST_CLI( DT_STUDY_DATA_LST_CLI &data );
BOOL FromJsonDT_STUDY_DATA_LST_CLI(const string &strData, DT_STUDY_DATA_LST_CLI &data);
BOOL FromJsonDT_STUDY_DATA_LST_CLI(Json::Value &root, DT_STUDY_DATA_LST_CLI &data);
INT32 EncodeDT_HERO_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_STUDY_DATA_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_STUDY_DATA_CLI( DT_HERO_STUDY_DATA_CLI &data );
BOOL FromJsonDT_HERO_STUDY_DATA_CLI(const string &strData, DT_HERO_STUDY_DATA_CLI &data);
BOOL FromJsonDT_HERO_STUDY_DATA_CLI(Json::Value &root, DT_HERO_STUDY_DATA_CLI &data);
INT32 EncodeDT_HERO_STUDY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
INT32 DecodeDT_HERO_STUDY_DATA_LST_CLI(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_HERO_STUDY_DATA_LST_CLI( DT_HERO_STUDY_DATA_LST_CLI &data );
BOOL FromJsonDT_HERO_STUDY_DATA_LST_CLI(const string &strData, DT_HERO_STUDY_DATA_LST_CLI &data);
BOOL FromJsonDT_HERO_STUDY_DATA_LST_CLI(Json::Value &root, DT_HERO_STUDY_DATA_LST_CLI &data);
INT32 EncodePKT_CLIGS_OPEN_STUDY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STUDY_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_STUDY_ACK( PKT_CLIGS_OPEN_STUDY_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_ACK(const string &strData, PKT_CLIGS_OPEN_STUDY_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_ACK(Json::Value &root, PKT_CLIGS_OPEN_STUDY_ACK &data);
INT32 EncodePKT_CLIGS_DRESS_STUDY_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_STUDY_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DRESS_STUDY_REQ( PKT_CLIGS_DRESS_STUDY_REQ &data );
BOOL FromJsonPKT_CLIGS_DRESS_STUDY_REQ(const string &strData, PKT_CLIGS_DRESS_STUDY_REQ &data);
BOOL FromJsonPKT_CLIGS_DRESS_STUDY_REQ(Json::Value &root, PKT_CLIGS_DRESS_STUDY_REQ &data);
INT32 EncodePKT_CLIGS_DRESS_STUDY_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_STUDY_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DRESS_STUDY_ACK( PKT_CLIGS_DRESS_STUDY_ACK &data );
BOOL FromJsonPKT_CLIGS_DRESS_STUDY_ACK(const string &strData, PKT_CLIGS_DRESS_STUDY_ACK &data);
BOOL FromJsonPKT_CLIGS_DRESS_STUDY_ACK(Json::Value &root, PKT_CLIGS_DRESS_STUDY_ACK &data);
INT32 EncodePKT_CLIGS_STUDY_CLIP_TO_EXP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_CLIP_TO_EXP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_CLIP_TO_EXP_REQ( PKT_CLIGS_STUDY_CLIP_TO_EXP_REQ &data );
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_TO_EXP_REQ(const string &strData, PKT_CLIGS_STUDY_CLIP_TO_EXP_REQ &data);
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_TO_EXP_REQ(Json::Value &root, PKT_CLIGS_STUDY_CLIP_TO_EXP_REQ &data);
INT32 EncodePKT_CLIGS_STUDY_CLIP_TO_EXP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_CLIP_TO_EXP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_CLIP_TO_EXP_ACK( PKT_CLIGS_STUDY_CLIP_TO_EXP_ACK &data );
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_TO_EXP_ACK(const string &strData, PKT_CLIGS_STUDY_CLIP_TO_EXP_ACK &data);
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_TO_EXP_ACK(Json::Value &root, PKT_CLIGS_STUDY_CLIP_TO_EXP_ACK &data);
INT32 EncodePKT_CLIGS_STUDY_TO_EXP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_TO_EXP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_TO_EXP_REQ( PKT_CLIGS_STUDY_TO_EXP_REQ &data );
BOOL FromJsonPKT_CLIGS_STUDY_TO_EXP_REQ(const string &strData, PKT_CLIGS_STUDY_TO_EXP_REQ &data);
BOOL FromJsonPKT_CLIGS_STUDY_TO_EXP_REQ(Json::Value &root, PKT_CLIGS_STUDY_TO_EXP_REQ &data);
INT32 EncodePKT_CLIGS_STUDY_TO_EXP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_TO_EXP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_TO_EXP_ACK( PKT_CLIGS_STUDY_TO_EXP_ACK &data );
BOOL FromJsonPKT_CLIGS_STUDY_TO_EXP_ACK(const string &strData, PKT_CLIGS_STUDY_TO_EXP_ACK &data);
BOOL FromJsonPKT_CLIGS_STUDY_TO_EXP_ACK(Json::Value &root, PKT_CLIGS_STUDY_TO_EXP_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_STUDY_CONVERT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STUDY_CONVERT_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_STUDY_CONVERT_REQ( PKT_CLIGS_OPEN_STUDY_CONVERT_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_CONVERT_REQ(const string &strData, PKT_CLIGS_OPEN_STUDY_CONVERT_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_CONVERT_REQ(Json::Value &root, PKT_CLIGS_OPEN_STUDY_CONVERT_REQ &data);
INT32 EncodeDT_STUDY_CFG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_STUDY_CFG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_STUDY_CFG_DATA( DT_STUDY_CFG_DATA &data );
BOOL FromJsonDT_STUDY_CFG_DATA(const string &strData, DT_STUDY_CFG_DATA &data);
BOOL FromJsonDT_STUDY_CFG_DATA(Json::Value &root, DT_STUDY_CFG_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_STUDY_CONVERT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_STUDY_CONVERT_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_STUDY_CONVERT_ACK( PKT_CLIGS_OPEN_STUDY_CONVERT_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_CONVERT_ACK(const string &strData, PKT_CLIGS_OPEN_STUDY_CONVERT_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_STUDY_CONVERT_ACK(Json::Value &root, PKT_CLIGS_OPEN_STUDY_CONVERT_ACK &data);
INT32 EncodePKT_CLIGS_STUDY_CONVERT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_CONVERT_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_CONVERT_REQ( PKT_CLIGS_STUDY_CONVERT_REQ &data );
BOOL FromJsonPKT_CLIGS_STUDY_CONVERT_REQ(const string &strData, PKT_CLIGS_STUDY_CONVERT_REQ &data);
BOOL FromJsonPKT_CLIGS_STUDY_CONVERT_REQ(Json::Value &root, PKT_CLIGS_STUDY_CONVERT_REQ &data);
INT32 EncodePKT_CLIGS_STUDY_CONVERT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_CONVERT_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_CONVERT_ACK( PKT_CLIGS_STUDY_CONVERT_ACK &data );
BOOL FromJsonPKT_CLIGS_STUDY_CONVERT_ACK(const string &strData, PKT_CLIGS_STUDY_CONVERT_ACK &data);
BOOL FromJsonPKT_CLIGS_STUDY_CONVERT_ACK(Json::Value &root, PKT_CLIGS_STUDY_CONVERT_ACK &data);
INT32 EncodePKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ( PKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ &data );
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ(const string &strData, PKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ &data);
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ(Json::Value &root, PKT_CLIGS_STUDY_CLIP_AUTO2EXP_REQ &data);
INT32 EncodePKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK( PKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK &data );
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK(const string &strData, PKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK &data);
BOOL FromJsonPKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK(Json::Value &root, PKT_CLIGS_STUDY_CLIP_AUTO2EXP_ACK &data);
INT32 EncodePKT_CLIGS_STUDY_UPGRADE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_UPGRADE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_UPGRADE_REQ( PKT_CLIGS_STUDY_UPGRADE_REQ &data );
BOOL FromJsonPKT_CLIGS_STUDY_UPGRADE_REQ(const string &strData, PKT_CLIGS_STUDY_UPGRADE_REQ &data);
BOOL FromJsonPKT_CLIGS_STUDY_UPGRADE_REQ(Json::Value &root, PKT_CLIGS_STUDY_UPGRADE_REQ &data);
INT32 EncodePKT_CLIGS_STUDY_UPGRADE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_STUDY_UPGRADE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_STUDY_UPGRADE_ACK( PKT_CLIGS_STUDY_UPGRADE_ACK &data );
BOOL FromJsonPKT_CLIGS_STUDY_UPGRADE_ACK(const string &strData, PKT_CLIGS_STUDY_UPGRADE_ACK &data);
BOOL FromJsonPKT_CLIGS_STUDY_UPGRADE_ACK(Json::Value &root, PKT_CLIGS_STUDY_UPGRADE_ACK &data);
INT32 EncodePKT_CLIGS_RACE_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RACE_BATTLELOG_NTF(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RACE_BATTLELOG_NTF( PKT_CLIGS_RACE_BATTLELOG_NTF &data );
BOOL FromJsonPKT_CLIGS_RACE_BATTLELOG_NTF(const string &strData, PKT_CLIGS_RACE_BATTLELOG_NTF &data);
BOOL FromJsonPKT_CLIGS_RACE_BATTLELOG_NTF(Json::Value &root, PKT_CLIGS_RACE_BATTLELOG_NTF &data);
INT32 EncodeDT_LOCK_SKILL_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_LOCK_SKILL_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_LOCK_SKILL_DATA( DT_LOCK_SKILL_DATA &data );
BOOL FromJsonDT_LOCK_SKILL_DATA(const string &strData, DT_LOCK_SKILL_DATA &data);
BOOL FromJsonDT_LOCK_SKILL_DATA(Json::Value &root, DT_LOCK_SKILL_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_SKILL_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SKILL_TAB_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SKILL_TAB_REQ( PKT_CLIGS_OPEN_SKILL_TAB_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_TAB_REQ(const string &strData, PKT_CLIGS_OPEN_SKILL_TAB_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_TAB_REQ(Json::Value &root, PKT_CLIGS_OPEN_SKILL_TAB_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_SKILL_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SKILL_TAB_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SKILL_TAB_ACK( PKT_CLIGS_OPEN_SKILL_TAB_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_TAB_ACK(const string &strData, PKT_CLIGS_OPEN_SKILL_TAB_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_TAB_ACK(Json::Value &root, PKT_CLIGS_OPEN_SKILL_TAB_ACK &data);
INT32 EncodePKT_CLIGS_UPGRADE_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_SKILL_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPGRADE_SKILL_REQ( PKT_CLIGS_UPGRADE_SKILL_REQ &data );
BOOL FromJsonPKT_CLIGS_UPGRADE_SKILL_REQ(const string &strData, PKT_CLIGS_UPGRADE_SKILL_REQ &data);
BOOL FromJsonPKT_CLIGS_UPGRADE_SKILL_REQ(Json::Value &root, PKT_CLIGS_UPGRADE_SKILL_REQ &data);
INT32 EncodePKT_CLIGS_UPGRADE_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_SKILL_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPGRADE_SKILL_ACK( PKT_CLIGS_UPGRADE_SKILL_ACK &data );
BOOL FromJsonPKT_CLIGS_UPGRADE_SKILL_ACK(const string &strData, PKT_CLIGS_UPGRADE_SKILL_ACK &data);
BOOL FromJsonPKT_CLIGS_UPGRADE_SKILL_ACK(Json::Value &root, PKT_CLIGS_UPGRADE_SKILL_ACK &data);
INT32 EncodePKT_CLIGS_DRESS_SKILL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_SKILL_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DRESS_SKILL_REQ( PKT_CLIGS_DRESS_SKILL_REQ &data );
BOOL FromJsonPKT_CLIGS_DRESS_SKILL_REQ(const string &strData, PKT_CLIGS_DRESS_SKILL_REQ &data);
BOOL FromJsonPKT_CLIGS_DRESS_SKILL_REQ(Json::Value &root, PKT_CLIGS_DRESS_SKILL_REQ &data);
INT32 EncodePKT_CLIGS_DRESS_SKILL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRESS_SKILL_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DRESS_SKILL_ACK( PKT_CLIGS_DRESS_SKILL_ACK &data );
BOOL FromJsonPKT_CLIGS_DRESS_SKILL_ACK(const string &strData, PKT_CLIGS_DRESS_SKILL_ACK &data);
BOOL FromJsonPKT_CLIGS_DRESS_SKILL_ACK(Json::Value &root, PKT_CLIGS_DRESS_SKILL_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ( PKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ(const string &strData, PKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ(Json::Value &root, PKT_CLIGS_OPEN_SKILL_CARD_MAKER_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK( PKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK(const string &strData, PKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK(Json::Value &root, PKT_CLIGS_OPEN_SKILL_CARD_MAKER_ACK &data);
INT32 EncodePKT_CLIGS_MAKER_SKILL_CARD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MAKER_SKILL_CARD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_MAKER_SKILL_CARD_REQ( PKT_CLIGS_MAKER_SKILL_CARD_REQ &data );
BOOL FromJsonPKT_CLIGS_MAKER_SKILL_CARD_REQ(const string &strData, PKT_CLIGS_MAKER_SKILL_CARD_REQ &data);
BOOL FromJsonPKT_CLIGS_MAKER_SKILL_CARD_REQ(Json::Value &root, PKT_CLIGS_MAKER_SKILL_CARD_REQ &data);
INT32 EncodePKT_CLIGS_MAKER_SKILL_CARD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MAKER_SKILL_CARD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_MAKER_SKILL_CARD_ACK( PKT_CLIGS_MAKER_SKILL_CARD_ACK &data );
BOOL FromJsonPKT_CLIGS_MAKER_SKILL_CARD_ACK(const string &strData, PKT_CLIGS_MAKER_SKILL_CARD_ACK &data);
BOOL FromJsonPKT_CLIGS_MAKER_SKILL_CARD_ACK(Json::Value &root, PKT_CLIGS_MAKER_SKILL_CARD_ACK &data);
INT32 EncodePKT_CLIGS_BUY_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BUY_PHYSTRENGTH_REQ( PKT_CLIGS_BUY_PHYSTRENGTH_REQ &data );
BOOL FromJsonPKT_CLIGS_BUY_PHYSTRENGTH_REQ(const string &strData, PKT_CLIGS_BUY_PHYSTRENGTH_REQ &data);
BOOL FromJsonPKT_CLIGS_BUY_PHYSTRENGTH_REQ(Json::Value &root, PKT_CLIGS_BUY_PHYSTRENGTH_REQ &data);
INT32 EncodePKT_CLIGS_BUY_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_BUY_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_BUY_PHYSTRENGTH_ACK( PKT_CLIGS_BUY_PHYSTRENGTH_ACK &data );
BOOL FromJsonPKT_CLIGS_BUY_PHYSTRENGTH_ACK(const string &strData, PKT_CLIGS_BUY_PHYSTRENGTH_ACK &data);
BOOL FromJsonPKT_CLIGS_BUY_PHYSTRENGTH_ACK(Json::Value &root, PKT_CLIGS_BUY_PHYSTRENGTH_ACK &data);
INT32 EncodePKT_CLIGS_CLR_PLUNDER_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_PLUNDER_CD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_PLUNDER_CD_REQ( PKT_CLIGS_CLR_PLUNDER_CD_REQ &data );
BOOL FromJsonPKT_CLIGS_CLR_PLUNDER_CD_REQ(const string &strData, PKT_CLIGS_CLR_PLUNDER_CD_REQ &data);
BOOL FromJsonPKT_CLIGS_CLR_PLUNDER_CD_REQ(Json::Value &root, PKT_CLIGS_CLR_PLUNDER_CD_REQ &data);
INT32 EncodePKT_CLIGS_CLR_PLUNDER_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_PLUNDER_CD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_PLUNDER_CD_ACK( PKT_CLIGS_CLR_PLUNDER_CD_ACK &data );
BOOL FromJsonPKT_CLIGS_CLR_PLUNDER_CD_ACK(const string &strData, PKT_CLIGS_CLR_PLUNDER_CD_ACK &data);
BOOL FromJsonPKT_CLIGS_CLR_PLUNDER_CD_ACK(Json::Value &root, PKT_CLIGS_CLR_PLUNDER_CD_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_MAINTOWN_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MAINTOWN_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_MAINTOWN_REQ( PKT_CLIGS_OPEN_MAINTOWN_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_MAINTOWN_REQ(const string &strData, PKT_CLIGS_OPEN_MAINTOWN_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_MAINTOWN_REQ(Json::Value &root, PKT_CLIGS_OPEN_MAINTOWN_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_MAINTOWN_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MAINTOWN_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_MAINTOWN_ACK( PKT_CLIGS_OPEN_MAINTOWN_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_MAINTOWN_ACK(const string &strData, PKT_CLIGS_OPEN_MAINTOWN_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_MAINTOWN_ACK(Json::Value &root, PKT_CLIGS_OPEN_MAINTOWN_ACK &data);
INT32 EncodePKT_CLIGS_RECV_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_MAINTOWN_INCOME_REQ( PKT_CLIGS_RECV_MAINTOWN_INCOME_REQ &data );
BOOL FromJsonPKT_CLIGS_RECV_MAINTOWN_INCOME_REQ(const string &strData, PKT_CLIGS_RECV_MAINTOWN_INCOME_REQ &data);
BOOL FromJsonPKT_CLIGS_RECV_MAINTOWN_INCOME_REQ(Json::Value &root, PKT_CLIGS_RECV_MAINTOWN_INCOME_REQ &data);
INT32 EncodePKT_CLIGS_RECV_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_MAINTOWN_INCOME_ACK( PKT_CLIGS_RECV_MAINTOWN_INCOME_ACK &data );
BOOL FromJsonPKT_CLIGS_RECV_MAINTOWN_INCOME_ACK(const string &strData, PKT_CLIGS_RECV_MAINTOWN_INCOME_ACK &data);
BOOL FromJsonPKT_CLIGS_RECV_MAINTOWN_INCOME_ACK(Json::Value &root, PKT_CLIGS_RECV_MAINTOWN_INCOME_ACK &data);
INT32 EncodePKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ( PKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ &data );
BOOL FromJsonPKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ(const string &strData, PKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ &data);
BOOL FromJsonPKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ(Json::Value &root, PKT_CLIGS_LEVY_MAINTOWN_INCOME_REQ &data);
INT32 EncodePKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK( PKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK &data );
BOOL FromJsonPKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK(const string &strData, PKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK &data);
BOOL FromJsonPKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK(Json::Value &root, PKT_CLIGS_LEVY_MAINTOWN_INCOME_ACK &data);
INT32 EncodePKT_CLIGS_DRIVE_AWAY_OWNER_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRIVE_AWAY_OWNER_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DRIVE_AWAY_OWNER_REQ( PKT_CLIGS_DRIVE_AWAY_OWNER_REQ &data );
BOOL FromJsonPKT_CLIGS_DRIVE_AWAY_OWNER_REQ(const string &strData, PKT_CLIGS_DRIVE_AWAY_OWNER_REQ &data);
BOOL FromJsonPKT_CLIGS_DRIVE_AWAY_OWNER_REQ(Json::Value &root, PKT_CLIGS_DRIVE_AWAY_OWNER_REQ &data);
INT32 EncodePKT_CLIGS_DRIVE_AWAY_OWNER_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_DRIVE_AWAY_OWNER_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_DRIVE_AWAY_OWNER_ACK( PKT_CLIGS_DRIVE_AWAY_OWNER_ACK &data );
BOOL FromJsonPKT_CLIGS_DRIVE_AWAY_OWNER_ACK(const string &strData, PKT_CLIGS_DRIVE_AWAY_OWNER_ACK &data);
BOOL FromJsonPKT_CLIGS_DRIVE_AWAY_OWNER_ACK(Json::Value &root, PKT_CLIGS_DRIVE_AWAY_OWNER_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_DRUG_USE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DRUG_USE_TAB_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_DRUG_USE_TAB_REQ( PKT_CLIGS_OPEN_DRUG_USE_TAB_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_DRUG_USE_TAB_REQ(const string &strData, PKT_CLIGS_OPEN_DRUG_USE_TAB_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_DRUG_USE_TAB_REQ(Json::Value &root, PKT_CLIGS_OPEN_DRUG_USE_TAB_REQ &data);
INT32 EncodeDT_TALENT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_TALENT_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_TALENT_DATA( DT_TALENT_DATA &data );
BOOL FromJsonDT_TALENT_DATA(const string &strData, DT_TALENT_DATA &data);
BOOL FromJsonDT_TALENT_DATA(Json::Value &root, DT_TALENT_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_DRUG_USE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_DRUG_USE_TAB_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_DRUG_USE_TAB_ACK( PKT_CLIGS_OPEN_DRUG_USE_TAB_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_DRUG_USE_TAB_ACK(const string &strData, PKT_CLIGS_OPEN_DRUG_USE_TAB_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_DRUG_USE_TAB_ACK(Json::Value &root, PKT_CLIGS_OPEN_DRUG_USE_TAB_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ( PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ(const string &strData, PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ(Json::Value &root, PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK( PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK(const string &strData, PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK(Json::Value &root, PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_ACK &data);
INT32 EncodePKT_CLIGS_CLR_USE_DRUG_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_USE_DRUG_CD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_USE_DRUG_CD_REQ( PKT_CLIGS_CLR_USE_DRUG_CD_REQ &data );
BOOL FromJsonPKT_CLIGS_CLR_USE_DRUG_CD_REQ(const string &strData, PKT_CLIGS_CLR_USE_DRUG_CD_REQ &data);
BOOL FromJsonPKT_CLIGS_CLR_USE_DRUG_CD_REQ(Json::Value &root, PKT_CLIGS_CLR_USE_DRUG_CD_REQ &data);
INT32 EncodePKT_CLIGS_CLR_USE_DRUG_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_USE_DRUG_CD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_USE_DRUG_CD_ACK( PKT_CLIGS_CLR_USE_DRUG_CD_ACK &data );
BOOL FromJsonPKT_CLIGS_CLR_USE_DRUG_CD_ACK(const string &strData, PKT_CLIGS_CLR_USE_DRUG_CD_ACK &data);
BOOL FromJsonPKT_CLIGS_CLR_USE_DRUG_CD_ACK(Json::Value &root, PKT_CLIGS_CLR_USE_DRUG_CD_ACK &data);
INT32 EncodePKT_CLIGS_USE_DRUG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_USE_DRUG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_USE_DRUG_REQ( PKT_CLIGS_USE_DRUG_REQ &data );
BOOL FromJsonPKT_CLIGS_USE_DRUG_REQ(const string &strData, PKT_CLIGS_USE_DRUG_REQ &data);
BOOL FromJsonPKT_CLIGS_USE_DRUG_REQ(Json::Value &root, PKT_CLIGS_USE_DRUG_REQ &data);
INT32 EncodePKT_CLIGS_USE_DRUG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_USE_DRUG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_USE_DRUG_ACK( PKT_CLIGS_USE_DRUG_ACK &data );
BOOL FromJsonPKT_CLIGS_USE_DRUG_ACK(const string &strData, PKT_CLIGS_USE_DRUG_ACK &data);
BOOL FromJsonPKT_CLIGS_USE_DRUG_ACK(Json::Value &root, PKT_CLIGS_USE_DRUG_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ( PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ(const string &strData, PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ(Json::Value &root, PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK( PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK(const string &strData, PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK(Json::Value &root, PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_ACK &data);
INT32 EncodePKT_CLIGS_UPGRADE_DRUG_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_DRUG_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPGRADE_DRUG_REQ( PKT_CLIGS_UPGRADE_DRUG_REQ &data );
BOOL FromJsonPKT_CLIGS_UPGRADE_DRUG_REQ(const string &strData, PKT_CLIGS_UPGRADE_DRUG_REQ &data);
BOOL FromJsonPKT_CLIGS_UPGRADE_DRUG_REQ(Json::Value &root, PKT_CLIGS_UPGRADE_DRUG_REQ &data);
INT32 EncodePKT_CLIGS_UPGRADE_DRUG_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPGRADE_DRUG_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPGRADE_DRUG_ACK( PKT_CLIGS_UPGRADE_DRUG_ACK &data );
BOOL FromJsonPKT_CLIGS_UPGRADE_DRUG_ACK(const string &strData, PKT_CLIGS_UPGRADE_DRUG_ACK &data);
BOOL FromJsonPKT_CLIGS_UPGRADE_DRUG_ACK(Json::Value &root, PKT_CLIGS_UPGRADE_DRUG_ACK &data);
INT32 EncodePKT_CLIGS_COMPOSE_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_EQUIP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_COMPOSE_EQUIP_REQ( PKT_CLIGS_COMPOSE_EQUIP_REQ &data );
BOOL FromJsonPKT_CLIGS_COMPOSE_EQUIP_REQ(const string &strData, PKT_CLIGS_COMPOSE_EQUIP_REQ &data);
BOOL FromJsonPKT_CLIGS_COMPOSE_EQUIP_REQ(Json::Value &root, PKT_CLIGS_COMPOSE_EQUIP_REQ &data);
INT32 EncodePKT_CLIGS_COMPOSE_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_EQUIP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_COMPOSE_EQUIP_ACK( PKT_CLIGS_COMPOSE_EQUIP_ACK &data );
BOOL FromJsonPKT_CLIGS_COMPOSE_EQUIP_ACK(const string &strData, PKT_CLIGS_COMPOSE_EQUIP_ACK &data);
BOOL FromJsonPKT_CLIGS_COMPOSE_EQUIP_ACK(Json::Value &root, PKT_CLIGS_COMPOSE_EQUIP_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PHYSTRENGTH_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_PHYSTRENGTH_REQ( PKT_CLIGS_OPEN_PHYSTRENGTH_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_PHYSTRENGTH_REQ(const string &strData, PKT_CLIGS_OPEN_PHYSTRENGTH_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_PHYSTRENGTH_REQ(Json::Value &root, PKT_CLIGS_OPEN_PHYSTRENGTH_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_PHYSTRENGTH_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_PHYSTRENGTH_ACK( PKT_CLIGS_OPEN_PHYSTRENGTH_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_PHYSTRENGTH_ACK(const string &strData, PKT_CLIGS_OPEN_PHYSTRENGTH_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_PHYSTRENGTH_ACK(Json::Value &root, PKT_CLIGS_OPEN_PHYSTRENGTH_ACK &data);
INT32 EncodePKT_CLIGS_RECV_LEFT_INCOME_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_LEFT_INCOME_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_LEFT_INCOME_REQ( PKT_CLIGS_RECV_LEFT_INCOME_REQ &data );
BOOL FromJsonPKT_CLIGS_RECV_LEFT_INCOME_REQ(const string &strData, PKT_CLIGS_RECV_LEFT_INCOME_REQ &data);
BOOL FromJsonPKT_CLIGS_RECV_LEFT_INCOME_REQ(Json::Value &root, PKT_CLIGS_RECV_LEFT_INCOME_REQ &data);
INT32 EncodePKT_CLIGS_RECV_LEFT_INCOME_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_RECV_LEFT_INCOME_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_RECV_LEFT_INCOME_ACK( PKT_CLIGS_RECV_LEFT_INCOME_ACK &data );
BOOL FromJsonPKT_CLIGS_RECV_LEFT_INCOME_ACK(const string &strData, PKT_CLIGS_RECV_LEFT_INCOME_ACK &data);
BOOL FromJsonPKT_CLIGS_RECV_LEFT_INCOME_ACK(Json::Value &root, PKT_CLIGS_RECV_LEFT_INCOME_ACK &data);
INT32 EncodePKT_CLIGS_SMITHY_BUY_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SMITHY_BUY_EQUIP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SMITHY_BUY_EQUIP_REQ( PKT_CLIGS_SMITHY_BUY_EQUIP_REQ &data );
BOOL FromJsonPKT_CLIGS_SMITHY_BUY_EQUIP_REQ(const string &strData, PKT_CLIGS_SMITHY_BUY_EQUIP_REQ &data);
BOOL FromJsonPKT_CLIGS_SMITHY_BUY_EQUIP_REQ(Json::Value &root, PKT_CLIGS_SMITHY_BUY_EQUIP_REQ &data);
INT32 EncodePKT_CLIGS_SMITHY_BUY_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SMITHY_BUY_EQUIP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SMITHY_BUY_EQUIP_ACK( PKT_CLIGS_SMITHY_BUY_EQUIP_ACK &data );
BOOL FromJsonPKT_CLIGS_SMITHY_BUY_EQUIP_ACK(const string &strData, PKT_CLIGS_SMITHY_BUY_EQUIP_ACK &data);
BOOL FromJsonPKT_CLIGS_SMITHY_BUY_EQUIP_ACK(Json::Value &root, PKT_CLIGS_SMITHY_BUY_EQUIP_ACK &data);
INT32 EncodePKT_CLIGS_CLR_STRENGTHEN_CD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_STRENGTHEN_CD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_STRENGTHEN_CD_REQ( PKT_CLIGS_CLR_STRENGTHEN_CD_REQ &data );
BOOL FromJsonPKT_CLIGS_CLR_STRENGTHEN_CD_REQ(const string &strData, PKT_CLIGS_CLR_STRENGTHEN_CD_REQ &data);
BOOL FromJsonPKT_CLIGS_CLR_STRENGTHEN_CD_REQ(Json::Value &root, PKT_CLIGS_CLR_STRENGTHEN_CD_REQ &data);
INT32 EncodePKT_CLIGS_CLR_STRENGTHEN_CD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_STRENGTHEN_CD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_STRENGTHEN_CD_ACK( PKT_CLIGS_CLR_STRENGTHEN_CD_ACK &data );
BOOL FromJsonPKT_CLIGS_CLR_STRENGTHEN_CD_ACK(const string &strData, PKT_CLIGS_CLR_STRENGTHEN_CD_ACK &data);
BOOL FromJsonPKT_CLIGS_CLR_STRENGTHEN_CD_ACK(Json::Value &root, PKT_CLIGS_CLR_STRENGTHEN_CD_ACK &data);
INT32 EncodeDT_CROP_SEED_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_SEED_INFO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROP_SEED_INFO_DATA( DT_CROP_SEED_INFO_DATA &data );
BOOL FromJsonDT_CROP_SEED_INFO_DATA(const string &strData, DT_CROP_SEED_INFO_DATA &data);
BOOL FromJsonDT_CROP_SEED_INFO_DATA(Json::Value &root, DT_CROP_SEED_INFO_DATA &data);
INT32 EncodeDT_CROP_FIELD_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_FIELD_INFO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROP_FIELD_INFO_DATA( DT_CROP_FIELD_INFO_DATA &data );
BOOL FromJsonDT_CROP_FIELD_INFO_DATA(const string &strData, DT_CROP_FIELD_INFO_DATA &data);
BOOL FromJsonDT_CROP_FIELD_INFO_DATA(Json::Value &root, DT_CROP_FIELD_INFO_DATA &data);
INT32 EncodeDT_CROP_MORE_INFO_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_CROP_MORE_INFO_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_CROP_MORE_INFO_DATA( DT_CROP_MORE_INFO_DATA &data );
BOOL FromJsonDT_CROP_MORE_INFO_DATA(const string &strData, DT_CROP_MORE_INFO_DATA &data);
BOOL FromJsonDT_CROP_MORE_INFO_DATA(Json::Value &root, DT_CROP_MORE_INFO_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_CROP_REQ( PKT_CLIGS_OPEN_CROP_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_CROP_REQ(const string &strData, PKT_CLIGS_OPEN_CROP_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_CROP_REQ(Json::Value &root, PKT_CLIGS_OPEN_CROP_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_CROP_ACK( PKT_CLIGS_OPEN_CROP_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_CROP_ACK(const string &strData, PKT_CLIGS_OPEN_CROP_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_CROP_ACK(Json::Value &root, PKT_CLIGS_OPEN_CROP_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_CROP_FIELD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_FIELD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_CROP_FIELD_REQ( PKT_CLIGS_OPEN_CROP_FIELD_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_CROP_FIELD_REQ(const string &strData, PKT_CLIGS_OPEN_CROP_FIELD_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_CROP_FIELD_REQ(Json::Value &root, PKT_CLIGS_OPEN_CROP_FIELD_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_CROP_FIELD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_CROP_FIELD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_CROP_FIELD_ACK( PKT_CLIGS_OPEN_CROP_FIELD_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_CROP_FIELD_ACK(const string &strData, PKT_CLIGS_OPEN_CROP_FIELD_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_CROP_FIELD_ACK(Json::Value &root, PKT_CLIGS_OPEN_CROP_FIELD_ACK &data);
INT32 EncodePKT_CLIGS_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CROP_REQ( PKT_CLIGS_CROP_REQ &data );
BOOL FromJsonPKT_CLIGS_CROP_REQ(const string &strData, PKT_CLIGS_CROP_REQ &data);
BOOL FromJsonPKT_CLIGS_CROP_REQ(Json::Value &root, PKT_CLIGS_CROP_REQ &data);
INT32 EncodePKT_CLIGS_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CROP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CROP_ACK( PKT_CLIGS_CROP_ACK &data );
BOOL FromJsonPKT_CLIGS_CROP_ACK(const string &strData, PKT_CLIGS_CROP_ACK &data);
BOOL FromJsonPKT_CLIGS_CROP_ACK(Json::Value &root, PKT_CLIGS_CROP_ACK &data);
INT32 EncodePKT_CLIGS_GAIN_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GAIN_CROP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GAIN_CROP_REQ( PKT_CLIGS_GAIN_CROP_REQ &data );
BOOL FromJsonPKT_CLIGS_GAIN_CROP_REQ(const string &strData, PKT_CLIGS_GAIN_CROP_REQ &data);
BOOL FromJsonPKT_CLIGS_GAIN_CROP_REQ(Json::Value &root, PKT_CLIGS_GAIN_CROP_REQ &data);
INT32 EncodePKT_CLIGS_GAIN_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GAIN_CROP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GAIN_CROP_ACK( PKT_CLIGS_GAIN_CROP_ACK &data );
BOOL FromJsonPKT_CLIGS_GAIN_CROP_ACK(const string &strData, PKT_CLIGS_GAIN_CROP_ACK &data);
BOOL FromJsonPKT_CLIGS_GAIN_CROP_ACK(Json::Value &root, PKT_CLIGS_GAIN_CROP_ACK &data);
INT32 EncodePKT_CLIGS_CLR_CROP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CROP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_CROP_REQ( PKT_CLIGS_CLR_CROP_REQ &data );
BOOL FromJsonPKT_CLIGS_CLR_CROP_REQ(const string &strData, PKT_CLIGS_CLR_CROP_REQ &data);
BOOL FromJsonPKT_CLIGS_CLR_CROP_REQ(Json::Value &root, PKT_CLIGS_CLR_CROP_REQ &data);
INT32 EncodePKT_CLIGS_CLR_CROP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CLR_CROP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CLR_CROP_ACK( PKT_CLIGS_CLR_CROP_ACK &data );
BOOL FromJsonPKT_CLIGS_CLR_CROP_ACK(const string &strData, PKT_CLIGS_CLR_CROP_ACK &data);
BOOL FromJsonPKT_CLIGS_CLR_CROP_ACK(Json::Value &root, PKT_CLIGS_CLR_CROP_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_EXPERIENCE_REQ( PKT_CLIGS_OPEN_EXPERIENCE_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_EXPERIENCE_REQ(const string &strData, PKT_CLIGS_OPEN_EXPERIENCE_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_EXPERIENCE_REQ(Json::Value &root, PKT_CLIGS_OPEN_EXPERIENCE_REQ &data);
INT32 EncodeDT_EXPERIENCE_DRUG_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_EXPERIENCE_DRUG_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_EXPERIENCE_DRUG_DATA( DT_EXPERIENCE_DRUG_DATA &data );
BOOL FromJsonDT_EXPERIENCE_DRUG_DATA(const string &strData, DT_EXPERIENCE_DRUG_DATA &data);
BOOL FromJsonDT_EXPERIENCE_DRUG_DATA(Json::Value &root, DT_EXPERIENCE_DRUG_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_EXPERIENCE_ACK( PKT_CLIGS_OPEN_EXPERIENCE_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_EXPERIENCE_ACK(const string &strData, PKT_CLIGS_OPEN_EXPERIENCE_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_EXPERIENCE_ACK(Json::Value &root, PKT_CLIGS_OPEN_EXPERIENCE_ACK &data);
INT32 EncodePKT_CLIGS_USER_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_USER_EXPERIENCE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_USER_EXPERIENCE_REQ( PKT_CLIGS_USER_EXPERIENCE_REQ &data );
BOOL FromJsonPKT_CLIGS_USER_EXPERIENCE_REQ(const string &strData, PKT_CLIGS_USER_EXPERIENCE_REQ &data);
BOOL FromJsonPKT_CLIGS_USER_EXPERIENCE_REQ(Json::Value &root, PKT_CLIGS_USER_EXPERIENCE_REQ &data);
INT32 EncodePKT_CLIGS_USER_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_USER_EXPERIENCE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_USER_EXPERIENCE_ACK( PKT_CLIGS_USER_EXPERIENCE_ACK &data );
BOOL FromJsonPKT_CLIGS_USER_EXPERIENCE_ACK(const string &strData, PKT_CLIGS_USER_EXPERIENCE_ACK &data);
BOOL FromJsonPKT_CLIGS_USER_EXPERIENCE_ACK(Json::Value &root, PKT_CLIGS_USER_EXPERIENCE_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_SCIENCE_BUILD_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SCIENCE_BUILD_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ( PKT_CLIGS_OPEN_SCIENCE_BUILD_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ(const string &strData, PKT_CLIGS_OPEN_SCIENCE_BUILD_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_SCIENCE_BUILD_REQ(Json::Value &root, PKT_CLIGS_OPEN_SCIENCE_BUILD_REQ &data);
INT32 EncodeDT_SCIENCE_ALREADY_OPEN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_ALREADY_OPEN_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SCIENCE_ALREADY_OPEN_DATA( DT_SCIENCE_ALREADY_OPEN_DATA &data );
BOOL FromJsonDT_SCIENCE_ALREADY_OPEN_DATA(const string &strData, DT_SCIENCE_ALREADY_OPEN_DATA &data);
BOOL FromJsonDT_SCIENCE_ALREADY_OPEN_DATA(Json::Value &root, DT_SCIENCE_ALREADY_OPEN_DATA &data);
INT32 EncodeDT_SCIENCE_WILL_OPEN_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_SCIENCE_WILL_OPEN_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_SCIENCE_WILL_OPEN_DATA( DT_SCIENCE_WILL_OPEN_DATA &data );
BOOL FromJsonDT_SCIENCE_WILL_OPEN_DATA(const string &strData, DT_SCIENCE_WILL_OPEN_DATA &data);
BOOL FromJsonDT_SCIENCE_WILL_OPEN_DATA(Json::Value &root, DT_SCIENCE_WILL_OPEN_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_SCIENCE_BUILD_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_SCIENCE_BUILD_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_SCIENCE_BUILD_ACK( PKT_CLIGS_OPEN_SCIENCE_BUILD_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_SCIENCE_BUILD_ACK(const string &strData, PKT_CLIGS_OPEN_SCIENCE_BUILD_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_SCIENCE_BUILD_ACK(Json::Value &root, PKT_CLIGS_OPEN_SCIENCE_BUILD_ACK &data);
INT32 EncodePKT_CLIGS_UPDATE_SCIENCE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_SCIENCE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPDATE_SCIENCE_REQ( PKT_CLIGS_UPDATE_SCIENCE_REQ &data );
BOOL FromJsonPKT_CLIGS_UPDATE_SCIENCE_REQ(const string &strData, PKT_CLIGS_UPDATE_SCIENCE_REQ &data);
BOOL FromJsonPKT_CLIGS_UPDATE_SCIENCE_REQ(Json::Value &root, PKT_CLIGS_UPDATE_SCIENCE_REQ &data);
INT32 EncodePKT_CLIGS_UPDATE_SCIENCE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_SCIENCE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPDATE_SCIENCE_ACK( PKT_CLIGS_UPDATE_SCIENCE_ACK &data );
BOOL FromJsonPKT_CLIGS_UPDATE_SCIENCE_ACK(const string &strData, PKT_CLIGS_UPDATE_SCIENCE_ACK &data);
BOOL FromJsonPKT_CLIGS_UPDATE_SCIENCE_ACK(Json::Value &root, PKT_CLIGS_UPDATE_SCIENCE_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_MELT_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MELT_EQUIP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_MELT_EQUIP_REQ( PKT_CLIGS_OPEN_MELT_EQUIP_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_MELT_EQUIP_REQ(const string &strData, PKT_CLIGS_OPEN_MELT_EQUIP_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_MELT_EQUIP_REQ(Json::Value &root, PKT_CLIGS_OPEN_MELT_EQUIP_REQ &data);
INT32 EncodePKT_CLIGS_OPEN_MELT_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_MELT_EQUIP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_MELT_EQUIP_ACK( PKT_CLIGS_OPEN_MELT_EQUIP_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_MELT_EQUIP_ACK(const string &strData, PKT_CLIGS_OPEN_MELT_EQUIP_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_MELT_EQUIP_ACK(Json::Value &root, PKT_CLIGS_OPEN_MELT_EQUIP_ACK &data);
INT32 EncodeDT_MELT_EQUIP_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_MELT_EQUIP_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_MELT_EQUIP_DATA( DT_MELT_EQUIP_DATA &data );
BOOL FromJsonDT_MELT_EQUIP_DATA(const string &strData, DT_MELT_EQUIP_DATA &data);
BOOL FromJsonDT_MELT_EQUIP_DATA(Json::Value &root, DT_MELT_EQUIP_DATA &data);
INT32 EncodePKT_CLIGS_MELT_EQUIP_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MELT_EQUIP_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_MELT_EQUIP_REQ( PKT_CLIGS_MELT_EQUIP_REQ &data );
BOOL FromJsonPKT_CLIGS_MELT_EQUIP_REQ(const string &strData, PKT_CLIGS_MELT_EQUIP_REQ &data);
BOOL FromJsonPKT_CLIGS_MELT_EQUIP_REQ(Json::Value &root, PKT_CLIGS_MELT_EQUIP_REQ &data);
INT32 EncodePKT_CLIGS_MELT_EQUIP_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_MELT_EQUIP_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_MELT_EQUIP_ACK( PKT_CLIGS_MELT_EQUIP_ACK &data );
BOOL FromJsonPKT_CLIGS_MELT_EQUIP_ACK(const string &strData, PKT_CLIGS_MELT_EQUIP_ACK &data);
BOOL FromJsonPKT_CLIGS_MELT_EQUIP_ACK(Json::Value &root, PKT_CLIGS_MELT_EQUIP_ACK &data);
INT32 EncodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ( PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ &data );
BOOL FromJsonPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ(const string &strData, PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ &data);
BOOL FromJsonPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ(Json::Value &root, PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_REQ &data);
INT32 EncodeDT_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPDATE_ATTR_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPDATE_ATTR_DATA( DT_UPDATE_ATTR_DATA &data );
BOOL FromJsonDT_UPDATE_ATTR_DATA(const string &strData, DT_UPDATE_ATTR_DATA &data);
BOOL FromJsonDT_UPDATE_ATTR_DATA(Json::Value &root, DT_UPDATE_ATTR_DATA &data);
INT32 EncodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK( PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK &data );
BOOL FromJsonPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK(const string &strData, PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK &data);
BOOL FromJsonPKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK(Json::Value &root, PKT_CLIGS_OPEN_UPDATE_ATTR_PANNEL_ACK &data);
INT32 EncodePKT_CLIGS_UPDATE_ATTR_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_ATTR_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPDATE_ATTR_REQ( PKT_CLIGS_UPDATE_ATTR_REQ &data );
BOOL FromJsonPKT_CLIGS_UPDATE_ATTR_REQ(const string &strData, PKT_CLIGS_UPDATE_ATTR_REQ &data);
BOOL FromJsonPKT_CLIGS_UPDATE_ATTR_REQ(Json::Value &root, PKT_CLIGS_UPDATE_ATTR_REQ &data);
INT32 EncodeDT_UPDATED_ATTR_BATTLE_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeDT_UPDATED_ATTR_BATTLE_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonDT_UPDATED_ATTR_BATTLE_DATA( DT_UPDATED_ATTR_BATTLE_DATA &data );
BOOL FromJsonDT_UPDATED_ATTR_BATTLE_DATA(const string &strData, DT_UPDATED_ATTR_BATTLE_DATA &data);
BOOL FromJsonDT_UPDATED_ATTR_BATTLE_DATA(Json::Value &root, DT_UPDATED_ATTR_BATTLE_DATA &data);
INT32 EncodePKT_CLIGS_UPDATE_ATTR_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_UPDATE_ATTR_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_UPDATE_ATTR_ACK( PKT_CLIGS_UPDATE_ATTR_ACK &data );
BOOL FromJsonPKT_CLIGS_UPDATE_ATTR_ACK(const string &strData, PKT_CLIGS_UPDATE_ATTR_ACK &data);
BOOL FromJsonPKT_CLIGS_UPDATE_ATTR_ACK(Json::Value &root, PKT_CLIGS_UPDATE_ATTR_ACK &data);
INT32 EncodePKT_CLIGS_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_COMPOSE_REQ( PKT_CLIGS_COMPOSE_REQ &data );
BOOL FromJsonPKT_CLIGS_COMPOSE_REQ(const string &strData, PKT_CLIGS_COMPOSE_REQ &data);
BOOL FromJsonPKT_CLIGS_COMPOSE_REQ(Json::Value &root, PKT_CLIGS_COMPOSE_REQ &data);
INT32 EncodePKT_CLIGS_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_COMPOSE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_COMPOSE_ACK( PKT_CLIGS_COMPOSE_ACK &data );
BOOL FromJsonPKT_CLIGS_COMPOSE_ACK(const string &strData, PKT_CLIGS_COMPOSE_ACK &data);
BOOL FromJsonPKT_CLIGS_COMPOSE_ACK(Json::Value &root, PKT_CLIGS_COMPOSE_ACK &data);
INT32 EncodePKT_CLIGS_REFRESH_ELITE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_ELITE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_REFRESH_ELITE_REQ( PKT_CLIGS_REFRESH_ELITE_REQ &data );
BOOL FromJsonPKT_CLIGS_REFRESH_ELITE_REQ(const string &strData, PKT_CLIGS_REFRESH_ELITE_REQ &data);
BOOL FromJsonPKT_CLIGS_REFRESH_ELITE_REQ(Json::Value &root, PKT_CLIGS_REFRESH_ELITE_REQ &data);
INT32 EncodePKT_CLIGS_REFRESH_ELITE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_REFRESH_ELITE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_REFRESH_ELITE_ACK( PKT_CLIGS_REFRESH_ELITE_ACK &data );
BOOL FromJsonPKT_CLIGS_REFRESH_ELITE_ACK(const string &strData, PKT_CLIGS_REFRESH_ELITE_ACK &data);
BOOL FromJsonPKT_CLIGS_REFRESH_ELITE_ACK(Json::Value &root, PKT_CLIGS_REFRESH_ELITE_ACK &data);
INT32 EncodePKT_CLIGS_ONHOOK_ELITE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_ELITE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ONHOOK_ELITE_REQ( PKT_CLIGS_ONHOOK_ELITE_REQ &data );
BOOL FromJsonPKT_CLIGS_ONHOOK_ELITE_REQ(const string &strData, PKT_CLIGS_ONHOOK_ELITE_REQ &data);
BOOL FromJsonPKT_CLIGS_ONHOOK_ELITE_REQ(Json::Value &root, PKT_CLIGS_ONHOOK_ELITE_REQ &data);
INT32 EncodePKT_CLIGS_ONHOOK_ELITE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_ONHOOK_ELITE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_ONHOOK_ELITE_ACK( PKT_CLIGS_ONHOOK_ELITE_ACK &data );
BOOL FromJsonPKT_CLIGS_ONHOOK_ELITE_ACK(const string &strData, PKT_CLIGS_ONHOOK_ELITE_ACK &data);
BOOL FromJsonPKT_CLIGS_ONHOOK_ELITE_ACK(Json::Value &root, PKT_CLIGS_ONHOOK_ELITE_ACK &data);
INT32 EncodePKT_CLIGS_GET_ITEM_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ITEM_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_ITEM_REQ( PKT_CLIGS_GET_ITEM_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_ITEM_REQ(const string &strData, PKT_CLIGS_GET_ITEM_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_ITEM_REQ(Json::Value &root, PKT_CLIGS_GET_ITEM_REQ &data);
INT32 EncodePKT_CLIGS_GET_ITEM_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ITEM_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_ITEM_ACK( PKT_CLIGS_GET_ITEM_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_ITEM_ACK(const string &strData, PKT_CLIGS_GET_ITEM_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_ITEM_ACK(Json::Value &root, PKT_CLIGS_GET_ITEM_ACK &data);
INT32 EncodePKT_CLIGS_GET_ORDER_ID_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ORDER_ID_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_ORDER_ID_REQ( PKT_CLIGS_GET_ORDER_ID_REQ &data );
BOOL FromJsonPKT_CLIGS_GET_ORDER_ID_REQ(const string &strData, PKT_CLIGS_GET_ORDER_ID_REQ &data);
BOOL FromJsonPKT_CLIGS_GET_ORDER_ID_REQ(Json::Value &root, PKT_CLIGS_GET_ORDER_ID_REQ &data);
INT32 EncodePKT_CLIGS_GET_ORDER_ID_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_GET_ORDER_ID_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_GET_ORDER_ID_ACK( PKT_CLIGS_GET_ORDER_ID_ACK &data );
BOOL FromJsonPKT_CLIGS_GET_ORDER_ID_ACK(const string &strData, PKT_CLIGS_GET_ORDER_ID_ACK &data);
BOOL FromJsonPKT_CLIGS_GET_ORDER_ID_ACK(Json::Value &root, PKT_CLIGS_GET_ORDER_ID_ACK &data);
INT32 EncodePKT_CLIGS_EXCHANGE_RESULT(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_EXCHANGE_RESULT(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_EXCHANGE_RESULT( PKT_CLIGS_EXCHANGE_RESULT &data );
BOOL FromJsonPKT_CLIGS_EXCHANGE_RESULT(const string &strData, PKT_CLIGS_EXCHANGE_RESULT &data);
BOOL FromJsonPKT_CLIGS_EXCHANGE_RESULT(Json::Value &root, PKT_CLIGS_EXCHANGE_RESULT &data);
INT32 EncodePKT_CLIGS_SEED_COMPOSE_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEED_COMPOSE_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SEED_COMPOSE_REQ( PKT_CLIGS_SEED_COMPOSE_REQ &data );
BOOL FromJsonPKT_CLIGS_SEED_COMPOSE_REQ(const string &strData, PKT_CLIGS_SEED_COMPOSE_REQ &data);
BOOL FromJsonPKT_CLIGS_SEED_COMPOSE_REQ(Json::Value &root, PKT_CLIGS_SEED_COMPOSE_REQ &data);
INT32 EncodePKT_CLIGS_SEED_COMPOSE_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_SEED_COMPOSE_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_SEED_COMPOSE_ACK( PKT_CLIGS_SEED_COMPOSE_ACK &data );
BOOL FromJsonPKT_CLIGS_SEED_COMPOSE_ACK(const string &strData, PKT_CLIGS_SEED_COMPOSE_ACK &data);
BOOL FromJsonPKT_CLIGS_SEED_COMPOSE_ACK(Json::Value &root, PKT_CLIGS_SEED_COMPOSE_ACK &data);
INT32 EncodePKT_CLIGS_CHAT_REQ(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHAT_REQ(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CHAT_REQ( PKT_CLIGS_CHAT_REQ &data );
BOOL FromJsonPKT_CLIGS_CHAT_REQ(const string &strData, PKT_CLIGS_CHAT_REQ &data);
BOOL FromJsonPKT_CLIGS_CHAT_REQ(Json::Value &root, PKT_CLIGS_CHAT_REQ &data);
INT32 EncodeCHAT_DATA(void *pHost, CNetData* poNetData);
INT32 DecodeCHAT_DATA(void *pHost, CNetData* poNetData);
Json::Value GetJsonCHAT_DATA( CHAT_DATA &data );
BOOL FromJsonCHAT_DATA(const string &strData, CHAT_DATA &data);
BOOL FromJsonCHAT_DATA(Json::Value &root, CHAT_DATA &data);
INT32 EncodePKT_CLIGS_CHAT_ACK(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHAT_ACK(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CHAT_ACK( PKT_CLIGS_CHAT_ACK &data );
BOOL FromJsonPKT_CLIGS_CHAT_ACK(const string &strData, PKT_CLIGS_CHAT_ACK &data);
BOOL FromJsonPKT_CLIGS_CHAT_ACK(Json::Value &root, PKT_CLIGS_CHAT_ACK &data);
INT32 EncodePKT_CLIGS_CHAT_NTF(void *pHost, CNetData* poNetData);
INT32 DecodePKT_CLIGS_CHAT_NTF(void *pHost, CNetData* poNetData);
Json::Value GetJsonPKT_CLIGS_CHAT_NTF( PKT_CLIGS_CHAT_NTF &data );
BOOL FromJsonPKT_CLIGS_CHAT_NTF(const string &strData, PKT_CLIGS_CHAT_NTF &data);
BOOL FromJsonPKT_CLIGS_CHAT_NTF(Json::Value &root, PKT_CLIGS_CHAT_NTF &data);
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
