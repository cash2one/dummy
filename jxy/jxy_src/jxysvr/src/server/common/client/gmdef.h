#ifndef _GMDEF_H_
#define _GMDEF_H_

//GM����
enum EGMType
{
    EGMT_ADDCOIN = 1,	//ͭǮ
    EGMT_ADDGOLD = 2,	//Ԫ��
    EGMT_ADDSTORY = 3,	//����
    EGMT_ADDSCIENCE = 4,//����
    EGMT_ADDPHYSTRENGTH = 5,//����
    EGMT_ADDBUILE = 6,//����
    EGMT_ADDITEM = 7,//��Ʒ
    EGMT_RELOADCFG	=	8,//������
    EGMT_SETLEVEL	=	9,//�ȼ�
    EGMT_PASSALLCOMMINSTANCE	=	10,//����
    EGMT_PASSALLGUIDE = 11,//����
    EGMT_ADDBLUE = 12,//����
    EGMT_ADDPURPLE = 13,//����
    EGMT_SETVIPLEVEL = 14, //VIP
    EGMT_ADDSTUDY = 15, //����
    EGMT_ADDSTUDYEXP = 16, //������
    EGMT_ADDPAYGOLD = 17, //���
    EGMT_DEC_CLIP = 18,//�۳�������Ƭ
    EGMT_ALL_STORY = 19,//ȫ����������
    EGMT_ALL_SCIENCE = 20,//ȫ����������
    EGMT_ALL_PHYSTRENGTH = 21,//ȫ����������
    EGMT_ALL_ITEM = 22,//ȫ��������Ʒ
    EGMT_ADDJINGJIE = 23, //����
    EGMT_DEC_ITEM = 24,//ɾ����Ʒ,�����ã�ɾ����ʯ
    EGMT_SET_JINGJIE_LEVEL = 25, //���þ���ȼ�
    EGMT_SET_JINGJIE = 26, //����ֵ
    EGMT_GET_PLAYER_INFO = 27, //��ȡ�����Ϣ
    EGMT_INSTANCE_BATTLE = 28, //����ս��
    EGMT_PLAYER_OL_NUM = 29, //��������
    EGMT_SILENCE_CHAT = 30, //���η���
    EGMT_WORD_FILTER = 31, //�ؼ���
    EGMT_GET_CHAT_MSG = 32, //��ȡ�����¼
    EGMT_DECCOIN = 33,	//�۳�ͭǮ
    EGMT_DECGOLD = 34,	//�۳�Ԫ��
    EGMT_DECRECHARGERMB = 35,	//�۳���ֵ��ͬʱ�޸�vip�ȼ�/��ֵ��¼/Ԫ��
    EGMT_GET_SLIENCE_LST = 36, //��ȡ�����б�
    EGMT_GET_PLAYER_RES = 37, //��ȡ�����Դ
    EGMT_GET_ACTIVITY_ENCOURAGE = 38, //��ȡ����������ӿڣ�
    EGMT_RESET_PWD = 39, //�����������
    EGMT_FORBIB_LOGIN = 40, //��ֹ��ҵ�¼
    EGMT_FORBID_REGISTERED = 41, //��ֹ���ע��
    EGMT_SETACCOUNTTYPE = 42, //�����˺�����
    EGMT_SETGMINFO = 43, //�������ΪGM�˺�
    EGMT_SYSCHATDATA = 44, //����ϵͳ���칫��
    EGMT_KICKOUT = 45, //��������
    EGMT_ACTIVITY_ENCOURAGE = 46, //����������ӿڣ�����������/ɾ�����
    EGMT_CKITEMNUM = 47, //�����߸���
    EGMT_GETGIVERES = 48, //�۳���Դ������Դ
    EGMT_STARTSERVER = 49, //���ÿ���ʱ��
    EGMT_OPRATINGACTIVITYBATTLE = 50, //��Ӫ�ս��
    EGMT_GETPLAYERLEVEL = 51, //�����ҵȼ�
    EGMT_HTTPDECGOLD = 52,	//�۳�Ԫ����Ԫ�����㷵�ش�����
    EGMT_GETCONSUME = 53,	//�������Ѽ�¼
    EGMT_ADD_MEDAL = 54, // ��������ѫ��
	EGMT_ADD_FACTION_FUNDS = 55,//���������ʽ�
	EGMT_GET_ONLINE_PLAYER_INFO = 56,//�������������ҵ�PLAYER_ID,NAME,LEVEL
	EGMT_ADD_DOORSTRIBUTE = 57,//���������Ź�
	EGMT_SET_FACTION_LEVEL = 58,//�������ɵȼ�
	EGMT_GET_CLIVER = 59,//��õ�ǰ��Ұ汾��
	EGMT_RETREATE = 60,//��һص��ӿ�
	EGMT_RESET_FACTION_NAME = 61,//���ð�������
    EGMT_ADD_COURAGE_TIMES = 62, //����������������
    EGMT_GET_RANK_BYLVEX = 63,//�����ҵȼ�����
    EGMT_GET_VIP_LEVEL = 64,//������VIP�ȼ�
    EGMT_GET_FRIENDS_NUM = 65,//�����Һ�������
	EGMT_IS_JOIN_IN_FACTION = 66,//�Ƿ��������
	EGMT_QUERY_SUM_DOORSTRIBUTE = 67,//��ѯ�ۻ��Ź�
    EGMT_ADD_HERO = 68,//��ָ�������ӻ��
    EGMT_CHANGE_NOTICE = 69,//���Ĺ�������
	EGMT_GET_POWER_RANK = 70, // ��ȡս��������
	EGMT_ADD_JEWELRY = 71,//���ָ��������Ʒ
	EGMT_CHAGNE_NAME = 72,//��������
	EGMT_ADD_GIFT = 73,//������
    EGMT_OPERATING_ACTIVITY = 74, //�����
    EGMT_SHOW_GVG_PAIR = 75, // ��ʾ���ս16��8ѡ�ֵĶԾ�����
	EGMT_SET_GVG_PAIR = 76, // �������ս16��8ѡ�ֵĶԾ�����

    EGMT_MYSELF = 200, // ���Լ���gmָ��
    EGMT_RESET_EQUIP_MASTER, // ����װ����ͨ
    EGMT_ACTIVITY_CHAT, // ��ӻ����
    EGMT_SYS_CHAT,      // ���ϵͳ����
    EGMT_WORLD_CHAT,      // �������
    EGMT_RECORD_CHART,      // ����ͳ��
    EGMT_SEND_FACTION_ACTIVITY_CHAT, // �������ɻ����
    EGMT_APPLE_PAY_CHECK,      // ƻ����ֵ��֤
    EGMT_TONGBUTUI_PAY_CHECK1, // ͬ������֤��һ��
    EGMT_TONGBUTUI_PAY_CHECK2, // ͬ������֤�ڶ���
    EGMT_ROBOT_FACTION, // ���������˰���
    EGMT_ADD_CHAT_WITH_FACTION, // �����ڵ������죬���ڲ�����ʾ����ͼ��
    EGMT_GVG_NEXT_ROUND, // ���ս
    EGMT_GVG_STOP, // ���ս

	EGMT_MAX,
};

#define ADD_COIN_DESC "����ͭǮ"
#define ADD_GOLD_DESC "����Ԫ��"
#define ADD_STORY_DESC "��������"
#define ADD_SCIENCE_DESC "��������"
#define ADD_PHYSTRENGTH_DESC "��������"
#define ADD_BUILD_DESC "���ӽ���"
#define ADD_ITEM_DESC "������Ʒ"
#define RELOAD_CFG_DESC "��������"
#define SET_LEVEL_DESC "���õȼ�"
#define PASS_ALL_COMMINSTANCE_DESC "ͨ�ظ���"
#define PASS_ALL_GUIDE_DESC "ͨ������"
#define ADD_BLUE_DESC "�������"
#define ADD_PURPLE_DESC "�������"
#define SET_VIP_LEVEL_DESC "����VIP�ȼ�"
#define ADD_STUDY_DESC "��������"
#define ADD_STUDY_EXP_DESC "����������"
#define ADD_PAY_GOLD_DESC "���ӳ�ֵԪ��"
#define ALL_GOLD_DESC "ȫ������Ԫ��"
#define ALL_STORY_DESC "ȫ����������"
#define ALL_SCIENCE_DESC "ȫ����������"
#define ALL_PHYSTRENGTH_DESC "ȫ����������"
#define ALL_ITEM_DESC  "ȫ��������Ʒ"
#define ADD_JING_JIE_DESC "���Ӿ���"
#define DEC_ITEM_DESC "ɾ����Ʒ"
#define SET_JINGJIE_LEVEL_DESC "���þ���ȼ�"
#define SET_JINGJIE_DESC "���þ���ֵ"
#define GET_PLAYER_INFO_DESC "��������Ϣ"
#define INSTANCE_BATTLE_DESC "����ս��"
#define	PLAYER_OL_NUM_DESC "��������"
#define SILENCE_CHAT_DESC "���η���"
#define WORD_FILTER_DESC "�ؼ���"
#define GET_CHAT_MSG_DESC "��ȡ�����¼"
#define DEC_COIN_DESC "�۳�ͭǮ"
#define DEC_GOLD_DESC "�۳�Ԫ��"
#define DEC_RECHARG_ERMB_DESC "�۳���ֵ���"
#define GET_SLIENCE_LST_DESC "��ȡ�����б�"
#define GET_PLAYER_RES_DESC "��ȡ�����Դ"
#define GET_ACTIVITY_ENCOURAGE_DESC "��ȡ��ҽ����ӿ�"
#define RESET_PWD_DESC "�����������"
#define FORBIB_LOGIN_DESC "��ֹ��ҵ�½"
#define FORBID_REGISTERED_DESC "��ֹ���ע��"
#define SET_ACCOUNT_TYPE_DESC "�����ʺ�����"
#define SET_GM_INFO_DESC "�������ΪGM��"
#define SYS_CHATDATA_DESC "����ϵͳ���칫��"
#define KICK_OUT_DESC "��������"
#define ACTIVITY_ENCOURAGE_DESC "����������ӿ�"
#define CK_ITEM_NUM_DESC "�����߸���"
#define GET_GIVE_RES_DESC "�۳��Լ�����Դ"
#define START_SERVER_DESC "���ÿ���ʱ��"
#define OPRATING_ACTIVITY_BATTLE_DESC "��Ӫ�ս��"
#define GET_PLAYER_LEVEL_DESC	"��ȡ��ҵȼ�"
#define HTTP_DEC_GOLD_DESC "�۳�Ԫ��"
#define GET_CONSUME_DESC "�������Ѽ�¼"
#define ADD_MEDAL_DESC "��������ѫ��"
#define ADD_FACTION_FUNDS_DESC "���������ʽ�"
#define GET_ONLINE_PLAYER_INFO_DESC "���������ҵ���Ϣ"
#define ADD_DOORSTRIBUTE_DESC "�����Ź�"
#define SET_FACTION_LEVEL_DESC "�������ɵȼ�"
#define GET_CLIVER_DESC "��õ�ǰ��Ұ汾��"
#define RETREATE_DESC "��һص�"
#define RESET_FACTION_NAME_DESC "���ð�������"
#define ADD_COURAGE_TIMES_DESC "����������������"
#define GET_RANK_DESC "��õȼ�����ǰ�������"
#define GET_VIP_LEVEL_DESC "������vip�ȼ�"
#define GET_FRIEDS_NUM_DESC "�����Һ�������"
#define IS_JOIN_IN_FACTION_DESC "�Ƿ��������"
#define QUERY_SUM_DOORSTRIBUTE_DESC "��ѯ�ۻ��Ź�"
#define ADD_HERO_DESC "��ָ��������Ӣ��"
#define CHANGE_NOTICE_DESC "���Ĺ�������"
#define GET_POWER_RANK_DESC "���ȫ�����ս��������"
#define ADD_JEWELRY_DESC "���ָ�����Ե���Ʒ"
#define CHANGE_PLAYER_NAME_DESC "�����������"
#define ADD_GIFT_DESC "�����������"
#define OPERATING_ACTIVITY_DESC "�����ʱ��"
#define SHOW_GVG_PAIR_DESC "��ʾ���ս16��8ѡ�����"
#define SET_GVG_PAIR_DESC "���ÿ��ս16��8ѡ�����"

#define PLAYER_ID_GBK "���ID"
#define ADD_COIN_GBK "ͭǮ������"
#define ADD_GOLD_GBK "Ԫ��������"
#define ADD_STORY_GBK "����������"
#define ADD_SCIENCE_GBK "����������"
#define ADD_PHYSTRENGT_GBK "����������"
#define ADD_BUILD_TYPE_GBK "��ӵĽ�������"
#define ADD_BUILD_COUNT_GBK "��ӵĽ�������"
#define ADD_ITEM_TYPE_GBK "��ӵ��ߵ�����"
#define ADD_ITEM_COUNT_GBK "��ӵ��ߵ�����"
#define SET_LEVEL_GBK "���õĵȼ�"
#define ADD_BLUE_GBK "��¶�����"
#define ADD_PURPLE_GBK "����������"
#define SET_VIP_LEVLE_GBK "VIP�ȼ�"
#define ADD_PAY_GOLD_GBK "���ѽ���������"
#define ADD_JINGJIE_GBK "����������"
#define SILENCE_CHAT_TYPE_GBK "��������"
#define SILENCE_CHAT_INFO_GBK "������Ϣ"
#define WORD_FILTER_TYPE_GBK "�ؼ�������"
#define WORD_FILTER_INFO_GBK "�ؼ�����Ϣ"
#define DEC_COIN_GBK "�۳�ͭǮ��"
#define DEC_GOLD_GBK "�۳�Ԫ����"
#define DEC_RECHARGE_RMB_GBK "�۳�Ԫ����ֵ��"
#define PLAYER_USER_ID "���PLAYER_ID"
#define ADD_STUDY_GBK "����������"
#define ADD_STUDY_EXP_GBK "������������"
#define ALL_GOLD_GBK "ȫ��Ԫ��������"
#define ALL_STORY_GBK "ȫ������������"
#define ALL_SCIENCE_GBK "ȫ������������"
#define ALL_PHYSTRENGTH_GBK "ȫ������������"
#define ALL_ITEM_TYPE_GBK "ȫ�����ӵĵ�������"
#define ALL_ITEM_COUNT_GBK "ȫ�����ӵĵ�������"
#define DEC_ITEM_TYPE_GBK "ɾ����������"
#define DEC_ITEM_COUNT_GBK "ɾ����������"
#define SET_JINGJIE_LEVEL_GBK "���õľ���ȼ�ֵ"
#define SET_JINGJIE_SUB_LEVEL_COUNT_GBK "���õ��Ӿ���ĵȼ�"
#define SET_JINGJIE_GBK "���õľ���ֵ"
#define DEC_RECHARG_ERMB_GBK "�۳��ĳ�ֵ���"
#define RESET_PWD_GBK "���õ�����"
#define FORBID_REGISTERED_USER_ID_GBK "��ֹע������ID"
#define FORBID_REGISTERED_EQU_ID_GBK "��ֹע����豸ID"
#define SET_ACCOUNT_TYPE_GBK	"��ҵ��ʺ�����"
#define SYS_CHATDATA_GBK "���칫������"
#define ACTIVITY_ENCOURAGE_GBK "�������Ϣ"
#define CK_ITEM_NUM_GBK "��ѯ�ĵ���ID"
#define GET_RES_GBK "�����Դ����Ϣ"
#define GIVE_RES_GBK "ɾ����Դ����Ϣ"
#define OPRATING_ACTIVITY_BATTLE_GBK "�ID"
#define TOWN_ID_GBK "����ID"
#define AREA_ID_GBK "����ID"
#define ADD_MEDAL_GBK "��������ѫ�µ�ֵ"
#define START_TIME_GBK "��ʼʱ��"
#define END_TIME_GBK "����ʱ��"
#define ADD_FACTION_FUNDS_GBK "�����ʽ�������"
#define SET_GM_INFO_OPTTYPE_GBK "����GM����"
#define SYS_CHATDATA_EXPIRESTIME_GBK "ϵͳ�������ʱ��"
#define SYS_CHATDATA_TYPE_GBK "ϵͳ���������"
#define HTTP_DEC_GOLD_GBK "Ҫ��ȥ��Ԫ����ֵ"
#define INSTANCE_BATTLE_SCENE_ID_GBK "����ID"
#define INSTANCE_BATTLE_TOWN_ID_GBK "����ID"
#define	INSTANCE_BATTLE_INSTANCE_ID_GBK "����ID"
#define INSTANCE_BATTLE_NUM_GBK "������ս��������"
#define RES_BUILD_TYPE_IS_OPEN_GBK "��������"
#define RES_BAG_ELSE_AMOUNT_GBK "����ʣ����"
#define	RES_STUDY_BAG_ELSE_AMOUNT_GBK "���󱳰�ʣ����"
#define	RELOAD_CFG_PARAM_GBK "�������ò���"
#define	START_SERVER_TIME_GBK "����ʱ��"
#define	ADD_STUDY_ATTR_KINT_GBK "������������"
#define	ADD_STUDY_COLOR_KIND_GBK "������ɫ����"
#define ADD_STUDY_LEVEL_GBK "����ȼ�"
#define ADD_DOORSTRIBUTE_COUNT_GBK "�����Ź�����"
#define SET_FACTION_LEVEL_VALUE_GBK "���ɵȼ�"
#define	SET_VIP_LEVEL_TOTAL_AMOUNT_GBK "�ܳ�ֵ��"
#define RETREATE_TYPE_GBK "�ص�����"
#define RETREATE_FILE_NAME_GBK "�ص����ļ���"
#define FACTION_NAME_GBK "��������"
#define ADD_COURAGE_TIMES_GBK "������������"
#define IS_JOIN_IN_FACTION_GBK "�Ƿ��������"
#define POWER_GBK "ս����"
#define POWER_RANK_GBK "ս��������"
#define ADD_ATTRIBUTE_1_GBK "ָ������1"
#define ADD_ATTRIBUTE_2_GBK "ָ������2"
#define ADD_ATTRIBUTE_3_GBK "ָ������3"
#define ADD_ATTRIBUTE_4_GBK "ָ������4"
#define PLAYER_NAME "�������"
#define ADD_GIFT_NAME_AND_DESC_GBK "�������|�������"
#define ADD_GIFT_OUT_TIME_GBK "����ʱ��"
#define START_ZONE_ID_GBK "��ʼ��ID"
#define END_ZONE_ID_GBK "������ID"
#define START_TIME_GBK "��ʼʱ��"
#define END_TIME_GBK "����ʱ��"

#define GM_PARAM_INT "int"
#define GM_PARAM_STR "string"
#define GM_PARAM_PLAYER_ID "playerid"
#define GM_PARAM_DATATIME "data"
#define GM_PARAM_USER_ID "userid"


#define		PLAYER_ID "playerid"
#define		START_ZONE_ID "start_zoneid"
#define		END_ZONE_ID "end_zoneid"
#define		ADD_COIN "add_coin"
#define 	ADD_GOLD  "add_gold"
#define 	ADD_STORY  "add_story"
#define 	ADD_SCIENCE  "add_science"
#define 	ADD_PHYSTRENGTH "add_phystrength"
#define 	ADD_BUILD	 "add_build"
#define 	ADD_ITEM	"add_item"
#define 	RELOAD_CFG	 "reload_cfg"
#define 	SET_LEVEL	 "set_level"
#define 	PASS_ALL_COMMINSTANCE  "pass_all_comminstance"
#define 	PASS_ALL_GUIDE	 "pass_all_guide"
#define 	ADD_BLUE	 "add_blue"
#define 	ADD_PURPLE	 "add_purple"
#define 	SET_VIP_LEVEL	 "set_vip_level"
#define 	ADD_STUDY	 "add_study"
#define 	ADD_STUDY_EXP	 "add_study_exp"
#define 	ADD_PAYGOLD	 "add_pay_gold"
#define 	ALL_GOLD	 "all_gold"
#define 	ALL_STORY	 "all_story"
#define 	ALL_SCIENCE	 "all_science"
#define 	ALL_PHYSTRENGTH  "all_phystrength"
#define 	ALL_ITEM	 "all_item"
#define 	ADD_JINGJIE	 "add_jingjie"
#define 	DEC_ITEM	 "dec_item"
#define		SET_JINGJIE_LEVEL	 "set_jingjie_level"
#define		SET_JINGJIE  "set_jingjie"
#define		GET_PLAYER_INFO  "get_player_info"
#define		INSTANCE_BATTLE  "instance_battle"
#define		PLAYER_OL_NUM  "player_ol_num"
#define		SILENCE_CHAT  "silence_chat"
#define		WORD_FILTER  "word_filter"
#define		GET_CHAT_MSG  "get_chat_msg"
#define		DEC_COIN  "dec_coin"
#define		DEC_GOLD  "dec_gold"
#define		DEC_RECHARGE_RMB  "dec_recharge_rmb"
#define		GET_SLIENCE_LST  "get_slience_lst"
#define		GET_PLAYER_RES  "get_player_res"
#define		GET_ACTIVITY_ENCOURAGE  "get_activity_encourage"
#define		RESET_PWD  "reset_pwd"
#define		FORBIB_LOGIN  "forbid_login"
#define		FORBID_REGISTERED  "forbid_registered"
#define		SET_ACCOUNT_TYPE	 "set_account_type"
#define		SET_GM_INFO  "set_gm_info"
#define		SYS_CHATDATA  "sys_chat_data"
#define		KICKOUT	 "kick_out"
#define		ACTIVITY_ENCOURAGE  "activity_encourage"
#define		CK_ITEM_NUM  "ck_item_num"
#define		GET_GIVE_RES	 "get_give_res"
#define		START_SERVER	 "start_server"
#define		OPRATING_ACTIVITY_BATTLE  "oprating_activity_battle"
#define		GET_PLAYER_LEVEL	 "get_player_level"
#define		HTTP_DEC_GOLD	 "http_dec_gold"
#define		GET_CONSUME	 "get_consume"
#define		ADD_MEDAL "add_medal"
#define		ADD_FACTION_FUNDS "add_faction_funds"
#define		GET_ONLINE_PLAYER_INFO "get_online_player_info"
#define		ADD_DOORSTRIBUTE "add_doorstribute"
#define		SET_FACTION_LEVEL "set_faction_level"
#define		GET_CLIVER "get_cliver"
#define		RETREATE "retreate"
#define		RESET_FACTION_NAME "reset_faction_name"
#define     ADD_COURAGE_TIMES "add_courage_times"
#define     GET_RANK "get_rank"
#define     GET_VIP_LEVEL "get_vip_level"
#define     GET_FRIEDS_NUM "get_friends_num"
#define     IS_JOIN_IN_FACTION "is_join_in_faction"
#define     QUERY_SUM_DOORSTRIBUTE "query_sum_doorstribute"
#define     ADD_HERO "add_hero"   
#define     CHANGE_NOTICE "change_notice"   
#define     CHANGE_POWER_RANK "get_power_rank" 
#define     ADD_JEWELRY_GM "add_jewelry"
#define		CHANGE_PLAYER_NAME "change_player_name"
#define     ADD_GIFT_GM "add_gift"
#define     OPERATING_ACTIVITY_GM "Operating_Activity"
#define		START_TIME "start_time"
#define		END_TIME "end_time"
#define     SHOW_GVG_PAIR "show_gvg_pair"
#define     SET_GVG_PAIR "set_gvg_pair"
#define     ZONE_ID "zone_id"
#define     ARENA_ID "arena_id"

#define		ADD_COIN_NUM_PARAM "add_coin_num"
#define		ADD_GOLD_NUM_PARAM "add_gold_num"
#define		ADD_STORY_NUM_PARAM "add_story_num"
#define		ADD_SCIENCE_NUM_PARAM "add_science_num"
#define		ADD_PHYSTRENGTH_NUM_PARAM "add_phystrength_num"
#define		ADD_BUILD_TYPE_PARAM "add_build_type"
#define		ADD_ITEM_TYPE_PARAM	"add_item_type"
#define		ADD_ITEM_COUNT_PARAM	"add_item_count"
#define		SET_LEVEL_COUNT_PARAM	"set_level_count"
#define		ADD_BLUE_COUNT_PARAM	"add_blue_count"
#define		ADD_PURPLE_COUNT_PARAM	"add_purple_count"
#define		SET_VIP_LEVEL_COUNT_PARAM "set_vip_level_count"
#define		ADD_STUDY_COUNT_PARAM "add_study_count"
#define		ADD_STUDY_EXP_COUNT_PARAM "add_study_exp_count"
#define		ADD_PAYGOLD_COUNT_PARAM	"add_paygold_count"
#define		ALL_GOLD_COUNT_PARAM	"all_gold_count"
#define		ALL_STORY_COUNT_PARAM	"all_story_count"
#define		ALL_SCIENCE_COUNT_PARAM	"all_science_count"
#define		ALL_PHYSTRENGTH_COUNT_PARAM	"all_phystrength_count"
#define		ALL_ITEM_TYPE_PARAM "all_item_type"
#define		ALL_ITEM_COUNT_PARAM "all_item_count"
#define		ADD_JINGJIE_COUNT_PARAM "add_jingjie_count"
#define		DEC_ITEM_TYPE_PARAM "dec_item_type"
#define		DEC_ITEM_COUNT_PARAM "dec_item_count"
#define		SET_JINGJIE_LEVLE_COUNT_PARAM "set_jingjie_level_count"
#define		SET_JINGJIE_SUB_LEVEL_COUNT_PARAM "set_jingjie_sub_level_count"
#define		SET_JINGJIE_COUNT_PARAM "set_jingjie_count"
#define		SILENCE_CHAT_TYPE_PARAM "silence_chat_type"
#define		SILENCE_CHAT_INFO_PARAM "silence_chat_info"
#define		WORD_FILTER_TYPE_PARAM	"word_filter_type"
#define		WORD_FILTER_INFO_PARAM	"word_filter_info"
#define		DEC_COIN_COUNT_PARAM "dec_coin_count"
#define		DEC_GOLD_COUNT_PARAM "dec_gold_count"
#define		DEC_RECHARGE_RMB_COUNT_PARAM "dec_recharge_rmb_count"
#define		NEW_PWD_PARAM "new_pwd"
#define		FORBID_REGISTERED_USER_ID_PARAM "forbid_registered_user_id"
#define		FORBID_REGISTERED_EQU_ID_PARAM "forbid_registered_equ_id"
#define		SET_ACCOUNT_TYPE_PARAM "set_account_type_value"
#define		ACTIVITY_ENCOURAGE_VALUE_PARAM	"activity_encourage_value"
#define		CK_ITEM_NUM_VALUE_PARAM "ck_item_num_value"
#define		GET_RES_INFO_VALUE_PARAM	"get_res_info_value"
#define		GIVE_RES_INFO_VALUE_PARAM	"give_res_info_value"
#define		START_SERVER_TIME_PARAM	"start_server_time"
#define		ACTIVITY_ID_PARAM "activity_version_id"
#define		TOWN_ID_PARAM	"town_id"
#define		COPY_ID_PARAM	"copy_id"
#define		START_TIME_PARAM "start_time"
#define		END_TIME_PARAM "end_time"
#define		ADD_MEDAL_VALUE_PARAM "add_medal_value"
#define		ADD_FACTION_FUNDS_VALUE_PARAM "add_faction_funds_value"
#define		RELOAD_CFG_TYPE_PARAM "reload_cfg_type"
#define		OPTTYPE_PARAM "opttype"
#define		SYS_CHATDATA_INFO_PARAM "sys_chatdata_info"
#define		SYS_CHATDATA_EXPIRESTIME_PARAM	"sys_chatdata_expirestime"
#define		HTTP_DEC_GOLD_VALUE_PARAM "http_dec_gold_value"
#define		INSTANCE_BATTLE_SCENE_ID_PARAM "instance_battle_scene_id"
#define		INSTANCE_BATTLE_TOWN_ID_PARAM "instance_battle_town_id"
#define		INSTANCE_BATTLE_INSTANCE_ID_PARAM "instance_battle_instance_id"
#define		INSTANCE_BATTLE_NUM_PARAM	"instance_battle_num"
#define		RES_BUILD_TYPE_IS_OPEN_PARAM "res_build_type"
#define		RES_BAG_ELSE_AMOUNT_PARAM "res_bag_else_amount"
#define		RES_STUDY_BAG_ELSE_AMOUNT_PARAM "res_study_bag_else_amount"
#define		ADD_STUDY_COLOR_KIND_PARAM "color_kind"
#define		ADD_STUDY_ATTR_KINT_PARAM "attr_kind"
#define		ADD_STUDY_LEVEL_PARAM "study_level"
#define		ADD_DOORSTRIBUTE_COUNT_PARAM "add_doorstribute_count"
#define		SET_FACTION_LEVEL_VALUE_PARAM "faction_level_value"
#define		SET_VIP_LEVEL_TOTAL_AMOUNT_PARAM "total_amount"
#define		RETREATE_TYPE_PARAM "retreate_type"
#define		RETREATE_FILE_NAME_PAMAM "retreate_file_name"
#define		RESET_FACTION_NAME_PAMAM "new_faction_name"
#define     ADD_COURAGE_TIMES_PARAM "add_courage_time_times"
#define		IS_JOIN_IN_FACTION_PARAM "is_join_in_faction"
#define     ADD_HERO_PARAM "add_hero_id"
#define     ADD_JEWELRY_KINDID "add_jewelry_kindID"
#define     ADD_JEWELRY_ATTR_NUM "add_jewelry_attr_num"
#define     ADD_JEWELRY_ATTR "add_jewelry_attr"
#define		ADD_GIFT_NAME_AND_DESC "add_gift_name_and_desc"
#define		ADD_GIFT_OUT_TIME "add_gift_out_time"
#endif //#ifndef _COMMONDEF_H_
