#ifndef __ERRDEF_H__
#define __ERRDEF_H__

namespace ERR_COMMON 
{
	static const unsigned int ID_OTHER_ERR = 110;
	static const char* STR_OTHER_ERR = "��������";

	static const unsigned int ID_VIP_LEVEL_NOT_REACH = 111;
	static const char* STR_VIP_LEVEL_NOT_REACH = "δ�ﵽ���Ÿù��ܵ�VIP�ȼ�";

	static const unsigned int ID_COIN_NOT_ENOUGH = 112;
	static const char* STR_COIN_NOT_ENOUGH = "ͭǮ����";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 113;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_FACTION_IS_EXCEPTION = 114;
	static const char* STR_FACTION_IS_EXCEPTION = "�������쳣������ϵGM���н��";

	static const char* STR_NAMESPACE = "ERR_COMMON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_OTHER_ERR
	,STR_VIP_LEVEL_NOT_REACH
	,STR_COIN_NOT_ENOUGH
	,STR_GOLD_NOT_ENOUGH
	,STR_FACTION_IS_EXCEPTION
	};
}

namespace ERR_GM_PARM_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLAYER_INIT_ERR = 1;
	static const char* STR_PLAYER_INIT_ERR = "��ҳ�ʼ��ʧ��";

	static const unsigned int ID_PLAYER_NOT_EXIT_ERR = 2;
	static const char* STR_PLAYER_NOT_EXIT_ERR = "��Ҳ�����";

	static const unsigned int ID_TYPE_NOT_EXIT_ERR = 3;
	static const char* STR_TYPE_NOT_EXIT_ERR = "���Ͳ�����";

	static const unsigned int ID_OTHER_ERR = 4;
	static const char* STR_OTHER_ERR = "��������";

	static const unsigned int ID_PARAM_ERR = 5;
	static const char* STR_PARAM_ERR = "��������";

	static const unsigned int ID_FIND_NO = 6;
	static const char* STR_FIND_NO = "����û���ҵ�";

	static const unsigned int ID_NOT_DATA = 7;
	static const char* STR_NOT_DATA = "����Ϊ��";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 8;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_PLAYER_IS_NOT_ONLINE = 9;
	static const char* STR_PLAYER_IS_NOT_ONLINE = "��ҵ�ǰ������";

	static const unsigned int ID_INSTANCE_PASS = 10;
	static const char* STR_INSTANCE_PASS = "����ͨ��";

	static const unsigned int ID_BUILD_NO_OPEN = 11;
	static const char* STR_BUILD_NO_OPEN = "����û�п���";

	static const unsigned int ID_BAG_IS_NOT_ENOUTH = 12;
	static const char* STR_BAG_IS_NOT_ENOUTH = "�����ռ䲻��";

	static const unsigned int ID_STUDY_IS_NOT_OPEN = 13;
	static const char* STR_STUDY_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_STUDY_BAG_IS_NOT_ENOUGH = 14;
	static const char* STR_STUDY_BAG_IS_NOT_ENOUGH = "���󱳰��ռ䲻��";

	static const unsigned int ID_DEL_ITEM_NO_ENOUGH = 15;
	static const char* STR_DEL_ITEM_NO_ENOUGH = "Ҫɾ���ĵ�����������";

	static const unsigned int ID_FACTION_NO_OPEN = 16;
	static const char* STR_FACTION_NO_OPEN = "δ�������";

	static const unsigned int ID_OVER_TIME = 17;
	static const char* STR_OVER_TIME = "����ʱ";

	static const unsigned int ID_REDUPLICATIVE = 18;
	static const char* STR_REDUPLICATIVE = "�ظ�����";

	static const unsigned int ID_NO_ACTIVITY = 19;
	static const char* STR_NO_ACTIVITY = "��ǰû�л";

	static const unsigned int ID_NO_THIS_ACTIVITY = 20;
	static const char* STR_NO_THIS_ACTIVITY = "��ǰ��������";

	static const unsigned int ID_ACTIVITY_NO_START_UP = 21;
	static const char* STR_ACTIVITY_NO_START_UP = "���δ����";

	static const unsigned int ID_ACTIVITY_OVER_TIME = 22;
	static const char* STR_ACTIVITY_OVER_TIME = "��Ѿ�����";

	static const unsigned int ID_INSTANCE_ID_FAULT = 23;
	static const char* STR_INSTANCE_ID_FAULT = "����ID����";

	static const unsigned int ID_INNER_BATTLE_FAULT = 24;
	static const char* STR_INNER_BATTLE_FAULT = "����ս��ʧ��";

	static const unsigned int ID_PLAYER_NOT_MEMORT = 25;
	static const char* STR_PLAYER_NOT_MEMORT = "��Ҳ����ڴ���";

	static const unsigned int ID_SOURCE_INVALID = 26;
	static const char* STR_SOURCE_INVALID = "��Դ�Ϸ��Լ��ʧ��";

	static const unsigned int ID_FILE_NO_EXIST = 27;
	static const char* STR_FILE_NO_EXIST = "�ص����ļ�������";

	static const unsigned int ID_DATA_GET_ERR = 28;
	static const char* STR_DATA_GET_ERR = "���ݽ�������";

	static const unsigned int ID_DATA_SAVE_ERR = 29;
	static const char* STR_DATA_SAVE_ERR = "���ݱ������";

	static const unsigned int ID_DATA_IS_NULL = 30;
	static const char* STR_DATA_IS_NULL = "û��Ҫ�ص�������";

	static const unsigned int ID_HERO_NOT_EXIST_ERR = 31;
	static const char* STR_HERO_NOT_EXIST_ERR = "��鲻����";

	static const unsigned int ID_RECUIT_NOT_EXIST_ERR = 32;
	static const char* STR_RECUIT_NOT_EXIST_ERR = "��ļ�ݲ�����";

	static const unsigned int ID_UPPER_LIMIT_ERR = 33;
	static const char* STR_UPPER_LIMIT_ERR = "��Я����������ﵽ����";

	static const unsigned int ID_NOT_ENOUGH_PLAYER_LEVEL = 34;
	static const char* STR_NOT_ENOUGH_PLAYER_LEVEL = "���ǵȼ�δ�ﵽ";

	static const unsigned int ID_CANNOT_RECUIT_COACH = 35;
	static const char* STR_CANNOT_RECUIT_COACH = "������ļ����";

	static const unsigned int ID_TOO_LONG_MESS = 36;
	static const char* STR_TOO_LONG_MESS = "��������̫��,���ܳ����������������ڵ�250������";

	static const char* STR_NAMESPACE = "ERR_GM_PARM_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLAYER_INIT_ERR
	,STR_PLAYER_NOT_EXIT_ERR
	,STR_TYPE_NOT_EXIT_ERR
	,STR_OTHER_ERR
	,STR_PARAM_ERR
	,STR_FIND_NO
	,STR_NOT_DATA
	,STR_GOLD_NOT_ENOUGH
	,STR_PLAYER_IS_NOT_ONLINE
	,STR_INSTANCE_PASS
	,STR_BUILD_NO_OPEN
	,STR_BAG_IS_NOT_ENOUTH
	,STR_STUDY_IS_NOT_OPEN
	,STR_STUDY_BAG_IS_NOT_ENOUGH
	,STR_DEL_ITEM_NO_ENOUGH
	,STR_FACTION_NO_OPEN
	,STR_OVER_TIME
	,STR_REDUPLICATIVE
	,STR_NO_ACTIVITY
	,STR_NO_THIS_ACTIVITY
	,STR_ACTIVITY_NO_START_UP
	,STR_ACTIVITY_OVER_TIME
	,STR_INSTANCE_ID_FAULT
	,STR_INNER_BATTLE_FAULT
	,STR_PLAYER_NOT_MEMORT
	,STR_SOURCE_INVALID
	,STR_FILE_NO_EXIST
	,STR_DATA_GET_ERR
	,STR_DATA_SAVE_ERR
	,STR_DATA_IS_NULL
	,STR_HERO_NOT_EXIST_ERR
	,STR_RECUIT_NOT_EXIST_ERR
	,STR_UPPER_LIMIT_ERR
	,STR_NOT_ENOUGH_PLAYER_LEVEL
	,STR_CANNOT_RECUIT_COACH
	,STR_TOO_LONG_MESS
	};
}

namespace ERR_LOGIN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PWD_ERR = 1;
	static const char* STR_PWD_ERR = "�������";

	static const unsigned int ID_ALL_EMPTY_ERR = 2;
	static const char* STR_ALL_EMPTY_ERR = "�û������豸�Ŷ�Ϊ��";

	static const unsigned int ID_INVALID_CAREER = 3;
	static const char* STR_INVALID_CAREER = "��Чְҵ";

	static const unsigned int ID_INVALID_CHARACTER = 4;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_INVALID_ZONEID = 5;
	static const char* STR_INVALID_ZONEID = "��Ч����";

	static const unsigned int ID_REACH_MAX_PLAYER_NUM = 6;
	static const char* STR_REACH_MAX_PLAYER_NUM = "��Ҹ����Ѵ�����";

	static const unsigned int ID_PLAYER_NOT_EXIT = 7;
	static const char* STR_PLAYER_NOT_EXIT = "��Ҳ�����";

	static const unsigned int ID_VERSION_NEED_UPDATE = 8;
	static const char* STR_VERSION_NEED_UPDATE = "�汾�����";

	static const unsigned int ID_INVALID_USER = 9;
	static const char* STR_INVALID_USER = "��Ч�û�";

	static const unsigned int ID_LS_SERVER_NOT_STARTUP = 10;
	static const char* STR_LS_SERVER_NOT_STARTUP = "��֤������δ����";

	static const unsigned int ID_GS_SERVER_NOT_STARTUP = 11;
	static const char* STR_GS_SERVER_NOT_STARTUP = "��Ϸ������δ����";

	static const unsigned int ID_PLAYER_NOT_BIND = 12;
	static const char* STR_PLAYER_NOT_BIND = "�˺�δ��";

	static const unsigned int ID_FORBID_CREATE_NEW_USER = 13;
	static const char* STR_FORBID_CREATE_NEW_USER = "������ֹ�������û�";

	static const unsigned int ID_INVALID_USER_TYPE = 14;
	static const char* STR_INVALID_USER_TYPE = "��Ч�û�����";

	static const unsigned int ID_SYSTEM_MAINTAIN = 15;
	static const char* STR_SYSTEM_MAINTAIN = "ϵͳ����ά�������Ժ�����";

	static const unsigned int ID_INVALID_STATE = 16;
	static const char* STR_INVALID_STATE = "״̬��Ч";

	static const unsigned int ID_USERNAME_NOT_EXIT = 17;
	static const char* STR_USERNAME_NOT_EXIT = "�û�������";

	static const unsigned int ID_FORBID_LOGIN = 18;
	static const char* STR_FORBID_LOGIN = "��ұ���ֹ��¼";

	static const unsigned int ID_FORBID_REGISTERED = 19;
	static const char* STR_FORBID_REGISTERED = "��ֹע�����û�";

	static const unsigned int ID_LOGIN_TIME_OUT = 20;
	static const char* STR_LOGIN_TIME_OUT = "��¼��ʱ��������";

	static const char* STR_NAMESPACE = "ERR_LOGIN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PWD_ERR
	,STR_ALL_EMPTY_ERR
	,STR_INVALID_CAREER
	,STR_INVALID_CHARACTER
	,STR_INVALID_ZONEID
	,STR_REACH_MAX_PLAYER_NUM
	,STR_PLAYER_NOT_EXIT
	,STR_VERSION_NEED_UPDATE
	,STR_INVALID_USER
	,STR_LS_SERVER_NOT_STARTUP
	,STR_GS_SERVER_NOT_STARTUP
	,STR_PLAYER_NOT_BIND
	,STR_FORBID_CREATE_NEW_USER
	,STR_INVALID_USER_TYPE
	,STR_SYSTEM_MAINTAIN
	,STR_INVALID_STATE
	,STR_USERNAME_NOT_EXIT
	,STR_FORBID_LOGIN
	,STR_FORBID_REGISTERED
	,STR_LOGIN_TIME_OUT
	};
}

namespace ERR_ENTER_GS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ENTER_FAILED = 1;
	static const char* STR_ENTER_FAILED = "������Ϸʧ��";

	static const unsigned int ID_INVALID_CAREER = 2;
	static const char* STR_INVALID_CAREER = "��Чְҵ";

	static const unsigned int ID_UNMATCH_PARAM = 3;
	static const char* STR_UNMATCH_PARAM = "������ƥ��";

	static const unsigned int ID_INVALID_STATE = 4;
	static const char* STR_INVALID_STATE = "��Ч״̬";

	static const unsigned int ID_SAVE_DATA_ERROR = 5;
	static const char* STR_SAVE_DATA_ERROR = "�˺ų����쳣��������1������ϵGM";

	static const char* STR_NAMESPACE = "ERR_ENTER_GS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ENTER_FAILED
	,STR_INVALID_CAREER
	,STR_UNMATCH_PARAM
	,STR_INVALID_STATE
	,STR_SAVE_DATA_ERROR
	};
}

namespace ERR_ENTER_INSTANCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INDEX_ERR = 1;
	static const char* STR_INDEX_ERR = "�������";

	static const unsigned int ID_REENTER_ERR = 2;
	static const char* STR_REENTER_ERR = "�ظ�����";

	static const unsigned int ID_LEVEL_ERR = 3;
	static const char* STR_LEVEL_ERR = "�ȼ�����";

	static const unsigned int ID_PHYSTRENGTH_ERR = 4;
	static const char* STR_PHYSTRENGTH_ERR = "��������";

	static const unsigned int ID_NOT_UNLOCK_ERR = 5;
	static const char* STR_NOT_UNLOCK_ERR = "δ����";

	static const unsigned int ID_ELITE_ONLY_ONE_PER_DAY_ERR = 6;
	static const char* STR_ELITE_ONLY_ONE_PER_DAY_ERR = "����ս";

	static const unsigned int ID_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR = 7;
	static const char* STR_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR = "����ͨ�����һ����";

	static const unsigned int ID_NOT_UNLOCK_LEVEL_ERR = 8;
	static const char* STR_NOT_UNLOCK_LEVEL_ERR = "�ȼ�δ�ﵽ��δ����";

	static const unsigned int ID_NOT_TIMES_OUT_BOUND = 9;
	static const char* STR_NOT_TIMES_OUT_BOUND = "�ø���������ս����";

	static const unsigned int ID_NOT_REFREASH = 10;
	static const char* STR_NOT_REFREASH = "����ת��";

	static const char* STR_NAMESPACE = "ERR_ENTER_INSTANCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INDEX_ERR
	,STR_REENTER_ERR
	,STR_LEVEL_ERR
	,STR_PHYSTRENGTH_ERR
	,STR_NOT_UNLOCK_ERR
	,STR_ELITE_ONLY_ONE_PER_DAY_ERR
	,STR_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR
	,STR_NOT_UNLOCK_LEVEL_ERR
	,STR_NOT_TIMES_OUT_BOUND
	,STR_NOT_REFREASH
	};
}

namespace ERR_BATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INDEX_ERR = 1;
	static const char* STR_INDEX_ERR = "�������";

	static const unsigned int ID_HAVE_BATTLE_ERR = 2;
	static const char* STR_HAVE_BATTLE_ERR = "�Ѿ����";

	static const unsigned int ID_MYSELF_DEAD_ERR = 3;
	static const char* STR_MYSELF_DEAD_ERR = "�ҷ�������";

	static const unsigned int ID_ENEMY_DEAD_ERR = 4;
	static const char* STR_ENEMY_DEAD_ERR = "����������";

	static const unsigned int ID_NOT_IN_INSTANCE_ERR = 5;
	static const char* STR_NOT_IN_INSTANCE_ERR = "���ڸ�����";

	static const unsigned int ID_CLIMBTOWER_ONE_PER_DAY_ERR = 6;
	static const char* STR_CLIMBTOWER_ONE_PER_DAY_ERR = "����ÿ��ֻ����һ��";

	static const unsigned int ID_REENTER_ERR = 7;
	static const char* STR_REENTER_ERR = "�ظ�����";

	static const unsigned int ID_LEVEL_ERR = 8;
	static const char* STR_LEVEL_ERR = "�ȼ�����";

	static const unsigned int ID_PHYSTRENGTH_ERR = 9;
	static const char* STR_PHYSTRENGTH_ERR = "��������";

	static const unsigned int ID_NOT_UNLOCK_ERR = 10;
	static const char* STR_NOT_UNLOCK_ERR = "δ����";

	static const unsigned int ID_ELITE_ONLY_ONE_PER_DAY_ERR = 11;
	static const char* STR_ELITE_ONLY_ONE_PER_DAY_ERR = "����ս";

	static const unsigned int ID_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR = 12;
	static const char* STR_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR = "����ͨ�����һ����";

	static const unsigned int ID_NOT_UNLOCK_LEVEL_ERR = 13;
	static const char* STR_NOT_UNLOCK_LEVEL_ERR = "�ȼ�δ�ﵽ��δ����";

	static const unsigned int ID_BAG_FULL = 14;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_MAX_HIGH_FLOOR = 15;
	static const char* STR_MAX_HIGH_FLOOR = "�Ѵﵽ���";

	static const char* STR_NAMESPACE = "ERR_BATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INDEX_ERR
	,STR_HAVE_BATTLE_ERR
	,STR_MYSELF_DEAD_ERR
	,STR_ENEMY_DEAD_ERR
	,STR_NOT_IN_INSTANCE_ERR
	,STR_CLIMBTOWER_ONE_PER_DAY_ERR
	,STR_REENTER_ERR
	,STR_LEVEL_ERR
	,STR_PHYSTRENGTH_ERR
	,STR_NOT_UNLOCK_ERR
	,STR_ELITE_ONLY_ONE_PER_DAY_ERR
	,STR_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR
	,STR_NOT_UNLOCK_LEVEL_ERR
	,STR_BAG_FULL
	,STR_MAX_HIGH_FLOOR
	};
}

namespace ERR_EXIT_INSTANCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NONIN_ERR = 1;
	static const char* STR_NONIN_ERR = "���ڸ�����";

	static const char* STR_NAMESPACE = "ERR_EXIT_INSTANCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NONIN_ERR
	};
}

namespace ERR_STRENGTHEN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_REACH_MAX_LEVEL_ERR = 1;
	static const char* STR_REACH_MAX_LEVEL_ERR = "�Ѿ��ﵽ���ȼ�";

	static const unsigned int ID_NOT_EQUIP_ERR = 2;
	static const char* STR_NOT_EQUIP_ERR = "δװ��";

	static const unsigned int ID_BUILD_NOT_EXIST_ERR = 3;
	static const char* STR_BUILD_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_IN_CD = 4;
	static const char* STR_IN_CD = "ǿ��CD��";

	static const unsigned int ID_NOT_EXIST_ERR = 5;
	static const char* STR_NOT_EXIST_ERR = "װ��������";

	static const unsigned int ID_OTHER_OWNER_ERR = 6;
	static const char* STR_OTHER_OWNER_ERR = "��Ʒ�Ǳ��˵�";

	static const unsigned int ID_HAVE_UPGRADE_ERR = 7;
	static const char* STR_HAVE_UPGRADE_ERR = "�Ѿ������õȼ�";

	static const unsigned int ID_LEVEL_ERR = 8;
	static const char* STR_LEVEL_ERR = "�ȼ�����(ÿ��ֻ����1����Ҳ�����Խ���)";

	static const unsigned int ID_CANNT_OVER_PLAYER_LEVEL_ERR = 9;
	static const char* STR_CANNT_OVER_PLAYER_LEVEL_ERR = "���ܳ�����ҵȼ�";

	static const unsigned int ID_LEVEL_MAX = 10;
	static const char* STR_LEVEL_MAX = "ǿ���ȼ��Ѿ��ﵽ����";

	static const unsigned int ID_CANNT_OVER_LEVEL_120 = 11;
	static const char* STR_CANNT_OVER_LEVEL_120 = "�޷�����ǿ�������ֻ��ǿ����120��";

	static const char* STR_NAMESPACE = "ERR_STRENGTHEN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_REACH_MAX_LEVEL_ERR
	,STR_NOT_EQUIP_ERR
	,STR_BUILD_NOT_EXIST_ERR
	,STR_IN_CD
	,STR_NOT_EXIST_ERR
	,STR_OTHER_OWNER_ERR
	,STR_HAVE_UPGRADE_ERR
	,STR_LEVEL_ERR
	,STR_CANNT_OVER_PLAYER_LEVEL_ERR
	,STR_LEVEL_MAX
	,STR_CANNT_OVER_LEVEL_120
	};
}

namespace ERR_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_POS_HAVE_EQUIP_ERR = 1;
	static const char* STR_POS_HAVE_EQUIP_ERR = "��λ������װ��";

	static const unsigned int ID_NOT_REACH_LEVEL_ERR = 2;
	static const char* STR_NOT_REACH_LEVEL_ERR = "δ�ﵽװ���ȼ�Ҫ��";

	static const unsigned int ID_EQUIP_NOT_EXIST_ERR = 3;
	static const char* STR_EQUIP_NOT_EXIST_ERR = "װ��������";

	static const unsigned int ID_HAVE_EQUIP_ERR = 4;
	static const char* STR_HAVE_EQUIP_ERR = "��װ���Ѿ�����";

	static const unsigned int ID_NOT_EQUIP_ERR = 5;
	static const char* STR_NOT_EQUIP_ERR = "δװ��";

	static const unsigned int ID_POS_NOT_MATCH_ERR = 6;
	static const char* STR_POS_NOT_MATCH_ERR = "�滻��װ��λ�ò���";

	static const unsigned int ID_HERO_NOT_EXIST_ERR = 7;
	static const char* STR_HERO_NOT_EXIST_ERR = "��鲻����";

	static const unsigned int ID_BAG_FULL_ERR = 8;
	static const char* STR_BAG_FULL_ERR = "�����ռ䲻��";

	static const unsigned int ID_NOT_IN_EQUIP_BAG_ERR = 9;
	static const char* STR_NOT_IN_EQUIP_BAG_ERR = "����װ��������װ��";

	static const unsigned int ID_EQUIP_NUM_MISMATCH_ERR = 10;
	static const char* STR_EQUIP_NUM_MISMATCH_ERR = "����������ƥ��";

	static const char* STR_NAMESPACE = "ERR_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_POS_HAVE_EQUIP_ERR
	,STR_NOT_REACH_LEVEL_ERR
	,STR_EQUIP_NOT_EXIST_ERR
	,STR_HAVE_EQUIP_ERR
	,STR_NOT_EQUIP_ERR
	,STR_POS_NOT_MATCH_ERR
	,STR_HERO_NOT_EXIST_ERR
	,STR_BAG_FULL_ERR
	,STR_NOT_IN_EQUIP_BAG_ERR
	,STR_EQUIP_NUM_MISMATCH_ERR
	};
}

namespace ERR_GET_SCENEINSTANCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SCENE_NOT_EXIST_ERR = 1;
	static const char* STR_SCENE_NOT_EXIST_ERR = "����������";

	static const char* STR_NAMESPACE = "ERR_GET_SCENEINSTANCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SCENE_NOT_EXIST_ERR
	};
}

namespace ERR_OPEN_CLIMB_TOWER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_CLIMB_TOWER_NOT_OPEN_ERR = 1;
	static const char* STR_CLIMB_TOWER_NOT_OPEN_ERR = "����������";

	static const unsigned int ID_CLIMB_TOWER_NOT_EXIST_ERR = 2;
	static const char* STR_CLIMB_TOWER_NOT_EXIST_ERR = "����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_CLIMB_TOWER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_CLIMB_TOWER_NOT_OPEN_ERR
	,STR_CLIMB_TOWER_NOT_EXIST_ERR
	};
}

namespace ERR_CROWN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_NOT_PRODUCE_ERR = 2;
	static const char* STR_NOT_PRODUCE_ERR = "������������";

	static const unsigned int ID_TIME_ERR = 3;
	static const char* STR_TIME_ERR = "δ���ջ�ʱ��";

	static const unsigned int ID_Level0_ERR = 4;
	static const char* STR_Level0_ERR = "0�������ջ�";

	static const char* STR_NAMESPACE = "ERR_CROWN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_NOT_PRODUCE_ERR
	,STR_TIME_ERR
	,STR_Level0_ERR
	};
}

namespace ERR_UPGRADE_BUILD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_REACH_MAX_LEVEL_ERR = 2;
	static const char* STR_REACH_MAX_LEVEL_ERR = "�Ѵﵽ���ȼ�";

	static const unsigned int ID_TIME_ERR = 3;
	static const char* STR_TIME_ERR = "δ������ʱ��";

	static const unsigned int ID_HAVE_UPGRADE_ERR = 4;
	static const char* STR_HAVE_UPGRADE_ERR = "�Ѿ������õȼ�";

	static const unsigned int ID_LEVEL_ERR = 5;
	static const char* STR_LEVEL_ERR = "�ȼ�����(ÿ��ֻ����1����Ҳ�����Խ���)";

	static const unsigned int ID_CANNT_OVER_MAINTOWN_LEVEL_ERR = 6;
	static const char* STR_CANNT_OVER_MAINTOWN_LEVEL_ERR = "���ܳ������ǵȼ�";

	static const unsigned int ID_CANNT_OVER_PLAYER_LEVEL_ERR = 7;
	static const char* STR_CANNT_OVER_PLAYER_LEVEL_ERR = "���ܳ�����ҵȼ�";

	static const unsigned int ID_LEVEL_NOT_UNLOCK_ERR = 8;
	static const char* STR_LEVEL_NOT_UNLOCK_ERR = "�����ǵȼ�δ����";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_BUILD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_REACH_MAX_LEVEL_ERR
	,STR_TIME_ERR
	,STR_HAVE_UPGRADE_ERR
	,STR_LEVEL_ERR
	,STR_CANNT_OVER_MAINTOWN_LEVEL_ERR
	,STR_CANNT_OVER_PLAYER_LEVEL_ERR
	,STR_LEVEL_NOT_UNLOCK_ERR
	};
}

namespace ERR_OPEN_SMITHY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_KIND_ERR = 2;
	static const char* STR_KIND_ERR = "�������Ͳ���";

	static const unsigned int ID_OWNER_ERR = 3;
	static const char* STR_OWNER_ERR = "�������˲����Լ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_SMITHY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_KIND_ERR
	,STR_OWNER_ERR
	};
}

namespace ERR_OPEN_RECUIT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_KIND_ERR = 2;
	static const char* STR_KIND_ERR = "�������Ͳ���";

	static const unsigned int ID_OWNER_ERR = 3;
	static const char* STR_OWNER_ERR = "�������˲����Լ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_RECUIT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_KIND_ERR
	,STR_OWNER_ERR
	};
}

namespace ERR_RECUIT_HERO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIST_ERR = 1;
	static const char* STR_HERO_NOT_EXIST_ERR = "��鲻����";

	static const unsigned int ID_RECUIT_NOT_EXIST_ERR = 2;
	static const char* STR_RECUIT_NOT_EXIST_ERR = "��ļ�ݲ�����";

	static const unsigned int ID_UPPER_LIMIT_ERR = 3;
	static const char* STR_UPPER_LIMIT_ERR = "��Я����������ﵽ����";

	static const unsigned int ID_NOT_REACH_VISIT_NUM = 4;
	static const char* STR_NOT_REACH_VISIT_NUM = "�øж�δ�ﵽ";

	static const unsigned int ID_CANNOT_RECUIT_COACH = 5;
	static const char* STR_CANNOT_RECUIT_COACH = "������ļ����";

	static const unsigned int ID_NOT_ENOUGH_JINGJIE_LEVEL = 6;
	static const char* STR_NOT_ENOUGH_JINGJIE_LEVEL = "����ȼ�δ�ﵽ";

	static const unsigned int ID_NOT_ENOUGH_PLAYER_LEVEL = 7;
	static const char* STR_NOT_ENOUGH_PLAYER_LEVEL = "���ǵȼ�δ�ﵽ";

	static const unsigned int ID_MUST_UPGRADE = 8;
	static const char* STR_MUST_UPGRADE = "�û����������ļ�����ף��޷�ֱ����ļ";

	static const unsigned int ID_MATERIAL_NOT_ENOUGH = 9;
	static const char* STR_MATERIAL_NOT_ENOUGH = "��ļ���ϲ���";

	static const char* STR_NAMESPACE = "ERR_RECUIT_HERO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIST_ERR
	,STR_RECUIT_NOT_EXIST_ERR
	,STR_UPPER_LIMIT_ERR
	,STR_NOT_REACH_VISIT_NUM
	,STR_CANNOT_RECUIT_COACH
	,STR_NOT_ENOUGH_JINGJIE_LEVEL
	,STR_NOT_ENOUGH_PLAYER_LEVEL
	,STR_MUST_UPGRADE
	,STR_MATERIAL_NOT_ENOUGH
	};
}

namespace ERR_DISBAND_HERO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIST_ERR = 1;
	static const char* STR_HERO_NOT_EXIST_ERR = "��鲻����";

	static const unsigned int ID_RECUIT_NOT_EXIST_ERR = 2;
	static const char* STR_RECUIT_NOT_EXIST_ERR = "��ļ�ݲ�����";

	static const unsigned int ID_COACH_CANNOT_DISBAND_ERR = 3;
	static const char* STR_COACH_CANNOT_DISBAND_ERR = "���ǲ���ǲɢ";

	static const char* STR_NAMESPACE = "ERR_DISBAND_HERO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIST_ERR
	,STR_RECUIT_NOT_EXIST_ERR
	,STR_COACH_CANNOT_DISBAND_ERR
	};
}

namespace ERR_OPEN_PRODUCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_KIND_ERR = 2;
	static const char* STR_KIND_ERR = "�������Ͳ���";

	static const unsigned int ID_OWNER_ERR = 3;
	static const char* STR_OWNER_ERR = "�������˲����Լ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_PRODUCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_KIND_ERR
	,STR_OWNER_ERR
	};
}

namespace ERR_OPEN_BAG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_BAG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	};
}

namespace ERR_OPEN_SCIENCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_KIND_ERR = 2;
	static const char* STR_KIND_ERR = "�������Ͳ���";

	static const unsigned int ID_OWNER_ERR = 3;
	static const char* STR_OWNER_ERR = "�������˲����Լ�";

	static const unsigned int ID_SERVER_INNER_ERR = 4;
	static const char* STR_SERVER_INNER_ERR = "���ݴ���";

	static const unsigned int ID_SCIENCE_UNLOCK = 5;
	static const char* STR_SCIENCE_UNLOCK = "�Ƽ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SCIENCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_KIND_ERR
	,STR_OWNER_ERR
	,STR_SERVER_INNER_ERR
	,STR_SCIENCE_UNLOCK
	};
}

namespace ERR_UPGRADE_SCIENCE_ATTREXT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_REACH_MAX_LEVEL_ERR = 1;
	static const char* STR_REACH_MAX_LEVEL_ERR = "�ÿƼ��Ѵﵽ��߼�";

	static const unsigned int ID_NOT_ENOUGH_SCIENCE_ERR = 2;
	static const char* STR_NOT_ENOUGH_SCIENCE_ERR = "�����㲻��";

	static const unsigned int ID_ATTR_NOT_EXIST_ERR = 3;
	static const char* STR_ATTR_NOT_EXIST_ERR = "�Ƽ�������";

	static const unsigned int ID_ATTR_NOT_UNLOCK_ERR = 4;
	static const char* STR_ATTR_NOT_UNLOCK_ERR = "�Ƽ�δ����";

	static const unsigned int ID_SCIENCE_NOT_EXIST_ERR = 5;
	static const char* STR_SCIENCE_NOT_EXIST_ERR = "�Ƽ�������";

	static const unsigned int ID_HAVE_UPGRADE_ERR = 6;
	static const char* STR_HAVE_UPGRADE_ERR = "�õȼ��Ƽ����о�";

	static const unsigned int ID_LEVEL_ERR = 7;
	static const char* STR_LEVEL_ERR = "�ȼ�����(ÿ��ֻ����1����Ҳ�����Խ���)";

	static const unsigned int ID_NOT_ENOUGH_PLAYER_LEVEL_ERR = 8;
	static const char* STR_NOT_ENOUGH_PLAYER_LEVEL_ERR = "���ǵȼ�����";

	static const unsigned int ID_SERVER_INNER_ERR = 9;
	static const char* STR_SERVER_INNER_ERR = "���ݴ���";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_SCIENCE_ATTREXT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_REACH_MAX_LEVEL_ERR
	,STR_NOT_ENOUGH_SCIENCE_ERR
	,STR_ATTR_NOT_EXIST_ERR
	,STR_ATTR_NOT_UNLOCK_ERR
	,STR_SCIENCE_NOT_EXIST_ERR
	,STR_HAVE_UPGRADE_ERR
	,STR_LEVEL_ERR
	,STR_NOT_ENOUGH_PLAYER_LEVEL_ERR
	,STR_SERVER_INNER_ERR
	};
}

namespace ERR_RECV_TASK_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_TASK_NOT_EXIT_ERR = 1;
	static const char* STR_TASK_NOT_EXIT_ERR = "���񲻴���";

	static const unsigned int ID_STATE_ERR = 2;
	static const char* STR_STATE_ERR = "����״̬����";

	static const unsigned int ID_HAVE_RECV_ERR = 3;
	static const char* STR_HAVE_RECV_ERR = "�Ѿ���ȡ";

	static const unsigned int ID_BAG_FULL_ERR = 4;
	static const char* STR_BAG_FULL_ERR = "�����ռ䲻��";

	static const char* STR_NAMESPACE = "ERR_RECV_TASK_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_TASK_NOT_EXIT_ERR
	,STR_STATE_ERR
	,STR_HAVE_RECV_ERR
	,STR_BAG_FULL_ERR
	};
}

namespace ERR_OPEN_RACE_BUILD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_EXIST_ERR = 1;
	static const char* STR_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_KIND_ERR = 2;
	static const char* STR_KIND_ERR = "�������Ͳ���";

	static const unsigned int ID_OWNER_ERR = 3;
	static const char* STR_OWNER_ERR = "�������˲����Լ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_RACE_BUILD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_EXIST_ERR
	,STR_KIND_ERR
	,STR_OWNER_ERR
	};
}

namespace ERR_CHALLENGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ENEMY_NOT_EXIST_ERR = 1;
	static const char* STR_ENEMY_NOT_EXIST_ERR = "��սĿ�겻����";

	static const unsigned int ID_IN_CD_ERR = 2;
	static const char* STR_IN_CD_ERR = "CDʱ����";

	static const unsigned int ID_REACH_MAX_TIMES_ERR = 3;
	static const char* STR_REACH_MAX_TIMES_ERR = "�Ѵﵽ�����ս����";

	static const unsigned int ID_UNLOCK_ERR = 4;
	static const char* STR_UNLOCK_ERR = "������δ����";

	static const unsigned int ID_ENEMY_CANNOT_MYSELF_ERR = 5;
	static const char* STR_ENEMY_CANNOT_MYSELF_ERR = "��սĿ�겻�����Լ�";

	static const unsigned int ID_OUT_CHALLENGE_RANG_ERR = 6;
	static const char* STR_OUT_CHALLENGE_RANG_ERR = "������ս��Χ";

	static const char* STR_NAMESPACE = "ERR_CHALLENGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ENEMY_NOT_EXIST_ERR
	,STR_IN_CD_ERR
	,STR_REACH_MAX_TIMES_ERR
	,STR_UNLOCK_ERR
	,STR_ENEMY_CANNOT_MYSELF_ERR
	,STR_OUT_CHALLENGE_RANG_ERR
	};
}

namespace ERR_RECV_RANK_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RACE_NOT_EXIST_ERR = 1;
	static const char* STR_RACE_NOT_EXIST_ERR = "����������";

	static const unsigned int ID_HAVE_RECVED_ERR = 2;
	static const char* STR_HAVE_RECVED_ERR = "�����Ѿ���ȡ��";

	static const unsigned int ID_TIME_ERR = 3;
	static const char* STR_TIME_ERR = "δ����ȡʱ��";

	static const char* STR_NAMESPACE = "ERR_RECV_RANK_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RACE_NOT_EXIST_ERR
	,STR_HAVE_RECVED_ERR
	,STR_TIME_ERR
	};
}

namespace ERR_OPEN_SHOP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_TAB_NOT_EXIST_ERR = 1;
	static const char* STR_TAB_NOT_EXIST_ERR = "�̵���಻����";

	static const unsigned int ID_SHOP_NOT_EXIST_ERR = 2;
	static const char* STR_SHOP_NOT_EXIST_ERR = "�̵겻����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SHOP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_TAB_NOT_EXIST_ERR
	,STR_SHOP_NOT_EXIST_ERR
	};
}

namespace ERR_BUG_ITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ITEM_NOT_EXIST_ERR = 1;
	static const char* STR_ITEM_NOT_EXIST_ERR = "���߲�����";

	static const unsigned int ID_BAG_FULL_ERR = 2;
	static const char* STR_BAG_FULL_ERR = "�����ռ䲻��";

	static const unsigned int ID_TABID_ERR = 3;
	static const char* STR_TABID_ERR = "�̵���಻����";

	static const unsigned int ID_PILE_NOT_MATCH_TAB_ERR = 4;
	static const char* STR_PILE_NOT_MATCH_TAB_ERR = "���������̵���಻ƥ��";

	static const unsigned int ID_SHOP_NOT_EXIST_ERR = 5;
	static const char* STR_SHOP_NOT_EXIST_ERR = "�̵겻����";

	static const unsigned int ID_PILENUM0 = 6;
	static const char* STR_PILENUM0 = "����������Ϊ0";

	static const unsigned int ID_LEVEL_NOT_REACH = 7;
	static const char* STR_LEVEL_NOT_REACH = "�ȼ�����";

	static const char* STR_NAMESPACE = "ERR_BUG_ITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ITEM_NOT_EXIST_ERR
	,STR_BAG_FULL_ERR
	,STR_TABID_ERR
	,STR_PILE_NOT_MATCH_TAB_ERR
	,STR_SHOP_NOT_EXIST_ERR
	,STR_PILENUM0
	,STR_LEVEL_NOT_REACH
	};
}

namespace ERR_SELL_ITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ITEM_NOT_EXIST_ERR = 1;
	static const char* STR_ITEM_NOT_EXIST_ERR = "���߲�����";

	static const unsigned int ID_OVER_CUR_NUM = 2;
	static const char* STR_OVER_CUR_NUM = "���۸�������ʵ�ʸ���";

	static const unsigned int ID_SELL_PROHIBIT = 3;
	static const char* STR_SELL_PROHIBIT = "�õ����޷�����";

	static const unsigned int ID_BAG_FULL = 4;
	static const char* STR_BAG_FULL = "�����ռ䲻�㣬����������";

	static const char* STR_NAMESPACE = "ERR_SELL_ITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ITEM_NOT_EXIST_ERR
	,STR_OVER_CUR_NUM
	,STR_SELL_PROHIBIT
	,STR_BAG_FULL
	};
}

namespace ERR_REGISTER_USERNAME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_USERNAME_EMPTY_ERR = 1;
	static const char* STR_USERNAME_EMPTY_ERR = "�û�������Ϊ��";

	static const unsigned int ID_PASSWORD_EMPTY_ERR = 2;
	static const char* STR_PASSWORD_EMPTY_ERR = "���벻��Ϊ��";

	static const unsigned int ID_USERNAME_EXIST_ERR = 3;
	static const char* STR_USERNAME_EXIST_ERR = "���û����Ѿ���ע��";

	static const unsigned int ID_REGISTERED_ERR = 4;
	static const char* STR_REGISTERED_ERR = "�Ѿ�ע����û���";

	static const unsigned int ID_USER_NOT_EXIST_ERR = 5;
	static const char* STR_USER_NOT_EXIST_ERR = "�û�������";

	static const unsigned int ID_INVALID_CHARACTER = 6;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_REGISTER_SUCCESS = 7;
	static const char* STR_REGISTER_SUCCESS = "ע��ɹ�";

	static const char* STR_NAMESPACE = "ERR_REGISTER_USERNAME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_USERNAME_EMPTY_ERR
	,STR_PASSWORD_EMPTY_ERR
	,STR_USERNAME_EXIST_ERR
	,STR_REGISTERED_ERR
	,STR_USER_NOT_EXIST_ERR
	,STR_INVALID_CHARACTER
	,STR_REGISTER_SUCCESS
	};
}

namespace ERR_EMBATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIST_ERR = 1;
	static const char* STR_HERO_NOT_EXIST_ERR = "��鲻����";

	static const unsigned int ID_FORMATION_INDEX_INVALID_ERR = 2;
	static const char* STR_FORMATION_INDEX_INVALID_ERR = "����λ����Ч";

	static const unsigned int ID_FORMATION_INDEX_HAVE_HERO_ERR = 3;
	static const char* STR_FORMATION_INDEX_HAVE_HERO_ERR = "λ���Ѿ��л��";

	static const unsigned int ID_FORMATION_KIND_NOT_EXIST = 4;
	static const char* STR_FORMATION_KIND_NOT_EXIST = "���Ͳ�����";

	static const unsigned int ID_COACH_NOT_IN_FORMATION = 5;
	static const char* STR_COACH_NOT_IN_FORMATION = "���ǲ�������";

	static const unsigned int ID_FORMATION_EXCEPTION = 6;
	static const char* STR_FORMATION_EXCEPTION = "����λ���쳣";

	static const unsigned int ID_POSTION_NOT_PLAYER = 7;
	static const char* STR_POSTION_NOT_PLAYER = "�����쳣��δ������λ�����л��";

	static const char* STR_NAMESPACE = "ERR_EMBATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIST_ERR
	,STR_FORMATION_INDEX_INVALID_ERR
	,STR_FORMATION_INDEX_HAVE_HERO_ERR
	,STR_FORMATION_KIND_NOT_EXIST
	,STR_COACH_NOT_IN_FORMATION
	,STR_FORMATION_EXCEPTION
	,STR_POSTION_NOT_PLAYER
	};
}

namespace ERR_OPEN_EMBATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FORMATION_NOT_OPEN = 1;
	static const char* STR_FORMATION_NOT_OPEN = "������δ����";

	static const unsigned int ID_FORMATION_ID_INVALID = 2;
	static const char* STR_FORMATION_ID_INVALID = "�������ݳ����쳣����ϵ�ͷ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_EMBATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FORMATION_NOT_OPEN
	,STR_FORMATION_ID_INVALID
	};
}

namespace ERR_OPEN_ITEM_MAKER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ITEM_NOT_EXIST = 1;
	static const char* STR_ITEM_NOT_EXIST = "���߲�����";

	static const unsigned int ID_NOT_ITEM_MAKER = 2;
	static const char* STR_NOT_ITEM_MAKER = "���߲���������";

	static const unsigned int ID_NEED_EQUIP_NULL = 3;
	static const char* STR_NEED_EQUIP_NULL = "û������װ��";

	static const unsigned int ID_MAKER_CONFIG_ERR = 4;
	static const char* STR_MAKER_CONFIG_ERR = "���������ô���";

	static const char* STR_NAMESPACE = "ERR_OPEN_ITEM_MAKER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ITEM_NOT_EXIST
	,STR_NOT_ITEM_MAKER
	,STR_NEED_EQUIP_NULL
	,STR_MAKER_CONFIG_ERR
	};
}

namespace ERR_MAKE_ITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ITEM_NOT_EXIST = 1;
	static const char* STR_ITEM_NOT_EXIST = "���߲�����";

	static const unsigned int ID_NOT_ITEM_MAKER = 2;
	static const char* STR_NOT_ITEM_MAKER = "�õ��߲���������";

	static const unsigned int ID_NEED_EQUIP_NULL = 3;
	static const char* STR_NEED_EQUIP_NULL = "û������װ��";

	static const unsigned int ID_SELECTED_EQUIP_NOT_EXIST = 4;
	static const char* STR_SELECTED_EQUIP_NOT_EXIST = "��ѡװ��������";

	static const unsigned int ID_SELECTED_EQUIP_NOT_MATCH = 5;
	static const char* STR_SELECTED_EQUIP_NOT_MATCH = "��ѡװ����ƥ��";

	static const unsigned int ID_MAKER_CONFIG_ERR = 6;
	static const char* STR_MAKER_CONFIG_ERR = "���������ô���";

	static const unsigned int ID_BAG_FULL = 7;
	static const char* STR_BAG_FULL = "��������";

	static const unsigned int ID_LEVEL_NOT_MATCH_FULL = 8;
	static const char* STR_LEVEL_NOT_MATCH_FULL = "װ�������ȼ��������ұ�������";

	static const unsigned int ID_NEED_ITEM_NOT_ENOUGH = 9;
	static const char* STR_NEED_ITEM_NOT_ENOUGH = "������߲���";

	static const unsigned int ID_NEED_BLUEGAS_NOT_ENOUGH = 10;
	static const char* STR_NEED_BLUEGAS_NOT_ENOUGH = "������¶����";

	static const unsigned int ID_MAKER_LEVEL_UNLOCK = 11;
	static const char* STR_MAKER_LEVEL_UNLOCK = "�����ȼ�δ����";

	static const char* STR_NAMESPACE = "ERR_MAKE_ITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ITEM_NOT_EXIST
	,STR_NOT_ITEM_MAKER
	,STR_NEED_EQUIP_NULL
	,STR_SELECTED_EQUIP_NOT_EXIST
	,STR_SELECTED_EQUIP_NOT_MATCH
	,STR_MAKER_CONFIG_ERR
	,STR_BAG_FULL
	,STR_LEVEL_NOT_MATCH_FULL
	,STR_NEED_ITEM_NOT_ENOUGH
	,STR_NEED_BLUEGAS_NOT_ENOUGH
	,STR_MAKER_LEVEL_UNLOCK
	};
}

namespace ERR_GET_HERO_DRUG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIST = 1;
	static const char* STR_HERO_NOT_EXIST = "��鲻����";

	static const char* STR_NAMESPACE = "ERR_GET_HERO_DRUG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIST
	};
}

namespace ERR_RECV_ONLINE_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BAG_FULL = 1;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_IN_CD = 2;
	static const char* STR_IN_CD = "ʱ��δ��";

	static const unsigned int ID_HAVE_RECV_ALL = 3;
	static const char* STR_HAVE_RECV_ALL = "�����Ѿ���ȡ��";

	static const unsigned int ID_HAVE_NOT_ENCOURAGE = 4;
	static const char* STR_HAVE_NOT_ENCOURAGE = "�Ѿ�û�н���";

	static const char* STR_NAMESPACE = "ERR_RECV_ONLINE_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BAG_FULL
	,STR_IN_CD
	,STR_HAVE_RECV_ALL
	,STR_HAVE_NOT_ENCOURAGE
	};
}

namespace ERR_OPEN_INSTANCE_ENCOURAGE_BOX 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BAG_FULL = 1;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_HAVE_OPEN = 2;
	static const char* STR_HAVE_OPEN = "�Ѿ��򿪹�";

	static const unsigned int ID_NOT_PASS = 3;
	static const char* STR_NOT_PASS = "δͨ��";

	static const char* STR_NAMESPACE = "ERR_OPEN_INSTANCE_ENCOURAGE_BOX";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BAG_FULL
	,STR_HAVE_OPEN
	,STR_NOT_PASS
	};
}

namespace ERR_INCREASE_SIZE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HAVE_REACH_MAX_SIZE = 1;
	static const char* STR_HAVE_REACH_MAX_SIZE = "�Ѿ��ﵽ��������";

	static const unsigned int ID_SIZE_SMALL_EQUAL_THAN_CUR = 2;
	static const char* STR_SIZE_SMALL_EQUAL_THAN_CUR = "��������С�ڵ��ڵ�Ȼ����";

	static const char* STR_NAMESPACE = "ERR_INCREASE_SIZE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HAVE_REACH_MAX_SIZE
	,STR_SIZE_SMALL_EQUAL_THAN_CUR
	};
}

namespace ERR_ONHOOK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PHYSTRENGTH_NOT_ENOUGH = 1;
	static const char* STR_PHYSTRENGTH_NOT_ENOUGH = "��������";

	static const unsigned int ID_BAG_FULL = 2;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_INSTANCE_NOT_EXIST = 3;
	static const char* STR_INSTANCE_NOT_EXIST = "����������";

	static const unsigned int ID_INSTANCE_NOT_BATTLED = 4;
	static const char* STR_INSTANCE_NOT_BATTLED = "�ø�����δͨ�أ��޷��һ�";

	static const unsigned int ID_OUT_MAX_RUN_RANG = 5;
	static const char* STR_OUT_MAX_RUN_RANG = "�һ�����ܳ���40��";

	static const unsigned int ID_RUN_TIMES_0 = 6;
	static const char* STR_RUN_TIMES_0 = "�һ���������Ϊ0";

	static const unsigned int ID_NOT_IN_ONHOOK = 7;
	static const char* STR_NOT_IN_ONHOOK = "û�д��ڹһ�״̬";

	static const unsigned int ID_ONHOOK_ING = 8;
	static const char* STR_ONHOOK_ING = "���ڹһ���";

	static const unsigned int ID_ONHOOK_UNLOCK = 9;
	static const char* STR_ONHOOK_UNLOCK = "�һ�δ����";

	static const char* STR_NAMESPACE = "ERR_ONHOOK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PHYSTRENGTH_NOT_ENOUGH
	,STR_BAG_FULL
	,STR_INSTANCE_NOT_EXIST
	,STR_INSTANCE_NOT_BATTLED
	,STR_OUT_MAX_RUN_RANG
	,STR_RUN_TIMES_0
	,STR_NOT_IN_ONHOOK
	,STR_ONHOOK_ING
	,STR_ONHOOK_UNLOCK
	};
}

namespace ERR_CLR_CHALLENGE_CD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RACE_NOT_EXIST_ERR = 1;
	static const char* STR_RACE_NOT_EXIST_ERR = "������������";

	static const unsigned int ID_CHALLENGE_TIMES_OVER_ERR = 2;
	static const char* STR_CHALLENGE_TIMES_OVER_ERR = "������ս�����Ѿ�����";

	static const char* STR_NAMESPACE = "ERR_CLR_CHALLENGE_CD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RACE_NOT_EXIST_ERR
	,STR_CHALLENGE_TIMES_OVER_ERR
	};
}

namespace ERR_GET_ZONE_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ZONE_NOT_EXIST_ERR = 1;
	static const char* STR_ZONE_NOT_EXIST_ERR = "��������";

	static const char* STR_NAMESPACE = "ERR_GET_ZONE_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ZONE_NOT_EXIST_ERR
	};
}

namespace ERR_SELECT_ZONE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ZONE_NOT_EXIST_ERR = 1;
	static const char* STR_ZONE_NOT_EXIST_ERR = "��������";

	static const unsigned int ID_USERNAME_NOT_EXIST = 2;
	static const char* STR_USERNAME_NOT_EXIST = "�û���������";

	static const unsigned int ID_PWD_ERR = 3;
	static const char* STR_PWD_ERR = "�û��������";

	static const unsigned int ID_INVALID_AUTH_TYPE = 4;
	static const char* STR_INVALID_AUTH_TYPE = "��Ч��֤��ʽ";

	static const unsigned int ID_INVALID_CHARACTER = 5;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_FORBIDLOGIN = 6;
	static const char* STR_FORBIDLOGIN = "���˺Ž�ֹ��¼";

	static const char* STR_NAMESPACE = "ERR_SELECT_ZONE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ZONE_NOT_EXIST_ERR
	,STR_USERNAME_NOT_EXIST
	,STR_PWD_ERR
	,STR_INVALID_AUTH_TYPE
	,STR_INVALID_CHARACTER
	,STR_FORBIDLOGIN
	};
}

namespace ERR_REGISTER_DSPNAME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_CHARACTER = 1;
	static const char* STR_INVALID_CHARACTER = "�ǳ�ֻ��ʹ�����ġ�Ӣ�ĺ�����";

	static const unsigned int ID_DSPNAME_CONFLICT = 2;
	static const char* STR_DSPNAME_CONFLICT = "���ǳ��ѱ�������ʹ��";

	static const unsigned int ID_TOO_LONG = 3;
	static const char* STR_TOO_LONG = "�ǳ�̫�������ܳ���6�����ֻ�12����ĸ��1������ = 2����ĸ��";

	static const unsigned int ID_SENSITIVE_WORD = 4;
	static const char* STR_SENSITIVE_WORD = "�ǳ��к������дʻ㣬����������";

	static const unsigned int ID_HAVE_DONE = 5;
	static const char* STR_HAVE_DONE = "�Ѿ�ע����ǳ�";

	static const char* STR_NAMESPACE = "ERR_REGISTER_DSPNAME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_CHARACTER
	,STR_DSPNAME_CONFLICT
	,STR_TOO_LONG
	,STR_SENSITIVE_WORD
	,STR_HAVE_DONE
	};
}

namespace ERR_GOODS_USE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GOODS_NOT_EXIST = 1;
	static const char* STR_GOODS_NOT_EXIST = "��Ʒ������";

	static const unsigned int ID_BAG_FULL = 2;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_IN_CD = 3;
	static const char* STR_IN_CD = "��CD��";

	static const unsigned int ID_REACH_MAX_TODAY = 4;
	static const char* STR_REACH_MAX_TODAY = "�Ѵﵽ����ʹ�ô���";

	static const unsigned int ID_NOT_ENOUGH_NUM = 5;
	static const char* STR_NOT_ENOUGH_NUM = "��Ʒ��������";

	static const unsigned int ID_NOT_REACH_USE_LEVEL = 6;
	static const char* STR_NOT_REACH_USE_LEVEL = "δ�ﵽʹ�õȼ�";

	static const unsigned int ID_CAN_NOT_USE_IN_BAG = 7;
	static const char* STR_CAN_NOT_USE_IN_BAG = "����Ʒ�����ڱ�����ʹ��";

	static const unsigned int ID_POS_CANNOT_XIANGQIAN = 8;
	static const char* STR_POS_CANNOT_XIANGQIAN = "��λ�ò�����Ƕ";

	static const unsigned int ID_PET_BAG_FULL = 9;
	static const char* STR_PET_BAG_FULL = "���ﱳ������";

	static const unsigned int ID_UNKOWND_ERR = 10;
	static const char* STR_UNKOWND_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_GOODS_USE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GOODS_NOT_EXIST
	,STR_BAG_FULL
	,STR_IN_CD
	,STR_REACH_MAX_TODAY
	,STR_NOT_ENOUGH_NUM
	,STR_NOT_REACH_USE_LEVEL
	,STR_CAN_NOT_USE_IN_BAG
	,STR_POS_CANNOT_XIANGQIAN
	,STR_PET_BAG_FULL
	,STR_UNKOWND_ERR
	};
}

namespace ERR_LOGIN_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_USE_OUT_NUM = 1;
	static const char* STR_USE_OUT_NUM = "������ȡ����������";

	static const unsigned int ID_STATE_INVALID = 2;
	static const char* STR_STATE_INVALID = "״̬����ȷ";

	static const unsigned int ID_BAG_FULL = 3;
	static const char* STR_BAG_FULL = "��������";

	static const char* STR_NAMESPACE = "ERR_LOGIN_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_USE_OUT_NUM
	,STR_STATE_INVALID
	,STR_BAG_FULL
	};
}

namespace ERR_GET_RANK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_GET_RANK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_GET_RACE_BATTLE_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK_RACE_ERR = 1;
	static const char* STR_UNLOCK_RACE_ERR = "������δ����";

	static const char* STR_NAMESPACE = "ERR_GET_RACE_BATTLE_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK_RACE_ERR
	};
}

namespace ERR_ACCEPT_TASK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_STATE_NOT_MATCH = 1;
	static const char* STR_STATE_NOT_MATCH = "����״̬��ƥ��";

	static const unsigned int ID_TASK_LINE_INVALID = 2;
	static const char* STR_TASK_LINE_INVALID = "��Ч������";

	static const unsigned int ID_TASK_NOT_EXIST = 3;
	static const char* STR_TASK_NOT_EXIST = "���񲻴���";

	static const unsigned int ID_HAVEN_ACCEPT_TASK = 4;
	static const char* STR_HAVEN_ACCEPT_TASK = "��ǰ���н��ܵ�����";

	static const unsigned int ID_NOT_RACHE_LEVEL = 5;
	static const char* STR_NOT_RACHE_LEVEL = "δ�ﵽָ���ȼ�";

	static const unsigned int ID_NOT_PASS_INSTANCE = 6;
	static const char* STR_NOT_PASS_INSTANCE = "δͨ��ָ������";

	static const unsigned int ID_NOT_RACHE_BUILD_LEVEL = 7;
	static const char* STR_NOT_RACHE_BUILD_LEVEL = "δ�ﵽָ�������ȼ�";

	static const unsigned int ID_NOT_PASS_MAINTASK = 8;
	static const char* STR_NOT_PASS_MAINTASK = "δͨ��ָ����������";

	static const char* STR_NAMESPACE = "ERR_ACCEPT_TASK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_STATE_NOT_MATCH
	,STR_TASK_LINE_INVALID
	,STR_TASK_NOT_EXIST
	,STR_HAVEN_ACCEPT_TASK
	,STR_NOT_RACHE_LEVEL
	,STR_NOT_PASS_INSTANCE
	,STR_NOT_RACHE_BUILD_LEVEL
	,STR_NOT_PASS_MAINTASK
	};
}

namespace ERR_GIVEUP_TASK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_STATE_NOT_MATCH = 1;
	static const char* STR_STATE_NOT_MATCH = "����״̬��ƥ��";

	static const unsigned int ID_TASK_LINE_INVALID = 2;
	static const char* STR_TASK_LINE_INVALID = "��Ч������";

	static const unsigned int ID_TASK_NOT_EXIST = 3;
	static const char* STR_TASK_NOT_EXIST = "���񲻴���";

	static const unsigned int ID_CAN_NOT_GIVE_UP_MAIN_TASK = 4;
	static const char* STR_CAN_NOT_GIVE_UP_MAIN_TASK = "���������޷�����";

	static const char* STR_NAMESPACE = "ERR_GIVEUP_TASK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_STATE_NOT_MATCH
	,STR_TASK_LINE_INVALID
	,STR_TASK_NOT_EXIST
	,STR_CAN_NOT_GIVE_UP_MAIN_TASK
	};
}

namespace ERR_PLUNDER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "С����δ����";

	static const unsigned int ID_IN_CD = 2;
	static const char* STR_IN_CD = "ץ��CD��";

	static const unsigned int ID_REACH_MAX_TIMES = 3;
	static const char* STR_REACH_MAX_TIMES = "�Ѵﵽ������";

	static const unsigned int ID_ENEMY_CANNOT_MYSELF = 4;
	static const char* STR_ENEMY_CANNOT_MYSELF = "ץ��Ŀ�겻�����Լ�";

	static const unsigned int ID_ENEMY_UNLOCK = 5;
	static const char* STR_ENEMY_UNLOCK = "�Է�С����δ����";

	static const unsigned int ID_OUT_PLUNDER_RANG = 6;
	static const char* STR_OUT_PLUNDER_RANG = "������ץ���ĵȼ���Χ";

	static const unsigned int ID_ENEMY_AVOID_BATTLE = 7;
	static const char* STR_ENEMY_AVOID_BATTLE = "�Է���ս��";

	static const unsigned int ID_ITEM_NOT_ENOUGH = 8;
	static const char* STR_ITEM_NOT_ENOUGH = "������������";

	static const unsigned int ID_ENEMY_NOT_EXIST = 9;
	static const char* STR_ENEMY_NOT_EXIST = "ץ��Ŀ�겻����";

	static const unsigned int ID_YOUR_CAPTURE = 10;
	static const char* STR_YOUR_CAPTURE = "ץ��Ŀ���Ѿ�����ķ�²";

	static const unsigned int ID_CAN_NOT_REPLUNDER = 11;
	static const char* STR_CAN_NOT_REPLUNDER = "���ܶ�ʱ�����ظ�ץ�������";

	static const unsigned int ID_GRID_NOT_IDLE = 12;
	static const char* STR_GRID_NOT_IDLE = "��²�����ѱ�ռ��";

	static const unsigned int ID_GRID_NOT_UNLOCK = 13;
	static const char* STR_GRID_NOT_UNLOCK = "��²����δ����";

	static const unsigned int ID_NOT_BECAPTURE = 14;
	static const char* STR_NOT_BECAPTURE = "�Լ�û�б�����ҷ�²";

	static const unsigned int ID_HAVE_BECAPTURE = 15;
	static const char* STR_HAVE_BECAPTURE = "ץ��Ŀ������������ҵķ�²";

	static const unsigned int ID_NOT_THIS_OWNER = 16;
	static const char* STR_NOT_THIS_OWNER = "ץ��Ŀ��ķ�²�����������";

	static const unsigned int ID_NO_OWNER = 17;
	static const char* STR_NO_OWNER = "ץ��Ŀ��û�з�²��";

	static const char* STR_NAMESPACE = "ERR_PLUNDER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	,STR_IN_CD
	,STR_REACH_MAX_TIMES
	,STR_ENEMY_CANNOT_MYSELF
	,STR_ENEMY_UNLOCK
	,STR_OUT_PLUNDER_RANG
	,STR_ENEMY_AVOID_BATTLE
	,STR_ITEM_NOT_ENOUGH
	,STR_ENEMY_NOT_EXIST
	,STR_YOUR_CAPTURE
	,STR_CAN_NOT_REPLUNDER
	,STR_GRID_NOT_IDLE
	,STR_GRID_NOT_UNLOCK
	,STR_NOT_BECAPTURE
	,STR_HAVE_BECAPTURE
	,STR_NOT_THIS_OWNER
	,STR_NO_OWNER
	};
}

namespace ERR_OPEN_ENEMY_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IDX_INVALID = 1;
	static const char* STR_IDX_INVALID = "��Ч���";

	static const char* STR_NAMESPACE = "ERR_OPEN_ENEMY_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IDX_INVALID
	};
}

namespace ERR_OPEN_PLUNDER_RECOMMEND_PLAYER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_PLUNDER_RECOMMEND_PLAYER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	};
}

namespace ERR_FREE_CAPTURE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_CAPTURE_NOT_EXIST = 2;
	static const char* STR_CAPTURE_NOT_EXIST = "��²������";

	static const char* STR_NAMESPACE = "ERR_FREE_CAPTURE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_CAPTURE_NOT_EXIST
	};
}

namespace ERR_OPEN_MONEY_TREE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_MONEY_TREE_UNLOCK = 1;
	static const char* STR_MONEY_TREE_UNLOCK = "�в�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_MONEY_TREE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_MONEY_TREE_UNLOCK
	};
}

namespace ERR_ROCK_MONEY_TREE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_MONEY_TREE_UNLOCK = 1;
	static const char* STR_MONEY_TREE_UNLOCK = "�в�δ����";

	static const unsigned int ID_USE_OUT_NUM = 2;
	static const char* STR_USE_OUT_NUM = "�вƴ����Ѿ�����";

	static const char* STR_NAMESPACE = "ERR_ROCK_MONEY_TREE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_MONEY_TREE_UNLOCK
	,STR_USE_OUT_NUM
	};
}

namespace ERR_GET_PLUNDER_BATTLE_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const char* STR_NAMESPACE = "ERR_GET_PLUNDER_BATTLE_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	};
}

namespace ERR_OPEN_GODWEAPON 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GODWEAPON_UNLOCK = 1;
	static const char* STR_GODWEAPON_UNLOCK = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_GODWEAPON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GODWEAPON_UNLOCK
	};
}

namespace ERR_UPGRADE_GODWEAPON 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GODWEAPON_UNLOCK = 1;
	static const char* STR_GODWEAPON_UNLOCK = "����δ����";

	static const unsigned int ID_QUALITY_INVALID = 2;
	static const char* STR_QUALITY_INVALID = "Ʒ����Ч";

	static const unsigned int ID_LEVEL_INVALID = 3;
	static const char* STR_LEVEL_INVALID = "�ȼ���Ч";

	static const unsigned int ID_HERO_NOT_EXIST = 4;
	static const char* STR_HERO_NOT_EXIST = "��鲻����";

	static const unsigned int ID_NOT_REACH_MAX_LEVEL = 5;
	static const char* STR_NOT_REACH_MAX_LEVEL = "δ�ﵽ��ǰƷ�����ȼ������ܽ���";

	static const unsigned int ID_NOT_ENOUGH_SCIENCE = 6;
	static const char* STR_NOT_ENOUGH_SCIENCE = "����㲻��";

	static const unsigned int ID_HERO_LEVEL_NOT_REACH = 7;
	static const char* STR_HERO_LEVEL_NOT_REACH = "���ȼ�û�ﵽ����Ҫ��";

	static const unsigned int ID_GODWEAPON_HAVE_EXIST = 8;
	static const char* STR_GODWEAPON_HAVE_EXIST = "�����ѿ���";

	static const unsigned int ID_ITEM_NOT_EXIST = 9;
	static const char* STR_ITEM_NOT_EXIST = "���׷�������";

	static const unsigned int ID_ITEM_NOT_ENOUGH = 10;
	static const char* STR_ITEM_NOT_ENOUGH = "���׷�����";

	static const unsigned int ID_LEVEL_NOT_REACH = 11;
	static const char* STR_LEVEL_NOT_REACH = "���ǵȼ�δ�ﵽ����Ҫ��";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_GODWEAPON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GODWEAPON_UNLOCK
	,STR_QUALITY_INVALID
	,STR_LEVEL_INVALID
	,STR_HERO_NOT_EXIST
	,STR_NOT_REACH_MAX_LEVEL
	,STR_NOT_ENOUGH_SCIENCE
	,STR_HERO_LEVEL_NOT_REACH
	,STR_GODWEAPON_HAVE_EXIST
	,STR_ITEM_NOT_EXIST
	,STR_ITEM_NOT_ENOUGH
	,STR_LEVEL_NOT_REACH
	};
}

namespace ERR_FREE_GODWEAPON 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GODWEAPON_UNLOCK = 1;
	static const char* STR_GODWEAPON_UNLOCK = "����δ����";

	static const unsigned int ID_HERO_NOT_EXIST = 2;
	static const char* STR_HERO_NOT_EXIST = "��鲻����";

	static const unsigned int ID_VIP_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_VIP_LEVEL_NOT_ENOUGH = "VIP�ȼ����������ܽ��������ͷ�";

	static const unsigned int ID_COACH_HERO_NOT_FREE = 4;
	static const char* STR_COACH_HERO_NOT_FREE = "���ǲ������ͷ�����";

	static const char* STR_NAMESPACE = "ERR_FREE_GODWEAPON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GODWEAPON_UNLOCK
	,STR_HERO_NOT_EXIST
	,STR_VIP_LEVEL_NOT_ENOUGH
	,STR_COACH_HERO_NOT_FREE
	};
}

namespace ERR_DEL_ENEMY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IDX_INVALID = 1;
	static const char* STR_IDX_INVALID = "��Ч���";

	static const unsigned int ID_ENEMY_NOT_EXIST = 2;
	static const char* STR_ENEMY_NOT_EXIST = "��в�����";

	static const char* STR_NAMESPACE = "ERR_DEL_ENEMY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IDX_INVALID
	,STR_ENEMY_NOT_EXIST
	};
}

namespace ERR_OPEN_AWAKEN  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_AWAKEN ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	};
}

namespace ERR_AWAKEN  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const unsigned int ID_STUDY_BAG_FULL = 2;
	static const char* STR_STUDY_BAG_FULL = "���󱳰�����";

	static const unsigned int ID_INVALID_STATE = 3;
	static const char* STR_INVALID_STATE = "��ǰ״̬����һ������";

	static const unsigned int ID_REACH_CALL_NUM = 4;
	static const char* STR_REACH_CALL_NUM = "�����ٻ������Ѿ�����";

	static const char* STR_NAMESPACE = "ERR_AWAKEN ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	,STR_STUDY_BAG_FULL
	,STR_INVALID_STATE
	,STR_REACH_CALL_NUM
	};
}

namespace ERR_OPEN_DRESS_STUDY_TAB  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_DRESS_STUDY_TAB ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	};
}

namespace ERR_DRESS_STUDY  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const unsigned int ID_IDX_INVALID = 2;
	static const char* STR_IDX_INVALID = "��Ч���";

	static const unsigned int ID_STUDY_NOT_EXIST = 3;
	static const char* STR_STUDY_NOT_EXIST = "���󲻴���";

	static const unsigned int ID_HERO_NOT_EXIST = 4;
	static const char* STR_HERO_NOT_EXIST = "��鲻����";

	static const unsigned int ID_POS_NOT_UNLOCK = 5;
	static const char* STR_POS_NOT_UNLOCK = "����λ����δ����";

	static const unsigned int ID_EXIST_SAME_STUDY_ATTR_KIND = 6;
	static const char* STR_EXIST_SAME_STUDY_ATTR_KIND = "�Ѵ��ڸ���������";

	static const unsigned int ID_CANNOT_DRESS_THIS_STUDY = 7;
	static const char* STR_CANNOT_DRESS_THIS_STUDY = "�������ܴ���";

	static const unsigned int ID_STUDY_BAG_FULL = 8;
	static const char* STR_STUDY_BAG_FULL = "���󱳰���";

	static const char* STR_NAMESPACE = "ERR_DRESS_STUDY ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	,STR_IDX_INVALID
	,STR_STUDY_NOT_EXIST
	,STR_HERO_NOT_EXIST
	,STR_POS_NOT_UNLOCK
	,STR_EXIST_SAME_STUDY_ATTR_KIND
	,STR_CANNOT_DRESS_THIS_STUDY
	,STR_STUDY_BAG_FULL
	};
}

namespace ERR_STUDY_TO_EXP  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const unsigned int ID_IDX_INVALID = 2;
	static const char* STR_IDX_INVALID = "��Ч���";

	static const unsigned int ID_STUDY_NOT_EXIST = 3;
	static const char* STR_STUDY_NOT_EXIST = "���󲻴���";

	static const char* STR_NAMESPACE = "ERR_STUDY_TO_EXP ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	,STR_IDX_INVALID
	,STR_STUDY_NOT_EXIST
	};
}

namespace ERR_UPGRADE_STUDY  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const unsigned int ID_IDX_INVALID = 2;
	static const char* STR_IDX_INVALID = "��Ч���";

	static const unsigned int ID_STUDY_NOT_EXIST = 3;
	static const char* STR_STUDY_NOT_EXIST = "���󲻴���";

	static const unsigned int ID_HERO_NOT_EXIST = 4;
	static const char* STR_HERO_NOT_EXIST = "��鲻����";

	static const unsigned int ID_NOT_ENOUGH_STUDYEXP = 5;
	static const char* STR_NOT_ENOUGH_STUDYEXP = "�����鲻��";

	static const unsigned int ID_CANNOT_JMP_LEVEL = 6;
	static const char* STR_CANNOT_JMP_LEVEL = "��������";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_STUDY ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	,STR_IDX_INVALID
	,STR_STUDY_NOT_EXIST
	,STR_HERO_NOT_EXIST
	,STR_NOT_ENOUGH_STUDYEXP
	,STR_CANNOT_JMP_LEVEL
	};
}

namespace ERR_REFRESH_PLUNDER_RECOMMEND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const char* STR_NAMESPACE = "ERR_REFRESH_PLUNDER_RECOMMEND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	};
}

namespace ERR_STUDY_CLIP_AUTO2EXP  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const char* STR_NAMESPACE = "ERR_STUDY_CLIP_AUTO2EXP ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	};
}

namespace ERR_VISIT_HERO  
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RECUIT_NOT_EXIST_ERR = 1;
	static const char* STR_RECUIT_NOT_EXIST_ERR = "���͹ݲ�����";

	static const unsigned int ID_HERO_NOT_EXIST = 2;
	static const char* STR_HERO_NOT_EXIST = "��鲻����";

	static const unsigned int ID_ALREADY_RECUIT = 3;
	static const char* STR_ALREADY_RECUIT = "����ļ";

	static const unsigned int ID_NOT_ENOUGH_JINGJIE_LEVEL = 4;
	static const char* STR_NOT_ENOUGH_JINGJIE_LEVEL = "����ȼ�δ�ﵽ";

	static const unsigned int ID_NOT_ENOUGH_PLAYER_LEVEL = 5;
	static const char* STR_NOT_ENOUGH_PLAYER_LEVEL = "���ǵȼ�δ�ﵽ";

	static const char* STR_NAMESPACE = "ERR_VISIT_HERO ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RECUIT_NOT_EXIST_ERR
	,STR_HERO_NOT_EXIST
	,STR_ALREADY_RECUIT
	,STR_NOT_ENOUGH_JINGJIE_LEVEL
	,STR_NOT_ENOUGH_PLAYER_LEVEL
	};
}

namespace ERR_BUY_PHYSTRENGTH 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_REACH_MAX_NUM = 1;
	static const char* STR_REACH_MAX_NUM = "�Ѵﵽ��������";

	static const char* STR_NAMESPACE = "ERR_BUY_PHYSTRENGTH";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_REACH_MAX_NUM
	};
}

namespace ERR_CLR_PLUNDER_CD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_PLUNDER_TIMES_OVER_ERR = 2;
	static const char* STR_PLUNDER_TIMES_OVER_ERR = "����ץ�������Ѿ�����";

	static const char* STR_NAMESPACE = "ERR_CLR_PLUNDER_CD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_PLUNDER_TIMES_OVER_ERR
	};
}

namespace ERR_OPEN_CAPTURE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_CAPTURE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	};
}

namespace ERR_COLLECT_INCOME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_CAPTURE_NOT_EXIST = 2;
	static const char* STR_CAPTURE_NOT_EXIST = "��²������";

	static const unsigned int ID_WORK_TYPE_NOT_SET = 3;
	static const char* STR_WORK_TYPE_NOT_SET = "��������δָ��";

	static const char* STR_NAMESPACE = "ERR_COLLECT_INCOME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_CAPTURE_NOT_EXIST
	,STR_WORK_TYPE_NOT_SET
	};
}

namespace ERR_BLEED_CAPTURE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_CAPTURE_NOT_EXIST = 2;
	static const char* STR_CAPTURE_NOT_EXIST = "��²������";

	static const unsigned int ID_WORK_TYPE_NOT_SET = 3;
	static const char* STR_WORK_TYPE_NOT_SET = "��������δָ��";

	static const char* STR_NAMESPACE = "ERR_BLEED_CAPTURE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_CAPTURE_NOT_EXIST
	,STR_WORK_TYPE_NOT_SET
	};
}

namespace ERR_OPEN_MAINTOWN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_NOT_EXIST = 1;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_MAINTOWN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_NOT_EXIST
	};
}

namespace ERR_RECV_MAINTOWN_INCOME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_NOT_EXIST = 1;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const unsigned int ID_HAVE_RECV = 2;
	static const char* STR_HAVE_RECV = "��������ȡ";

	static const char* STR_NAMESPACE = "ERR_RECV_MAINTOWN_INCOME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_NOT_EXIST
	,STR_HAVE_RECV
	};
}

namespace ERR_LEVY_MAINTOWN_INCOME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_NOT_EXIST = 1;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const unsigned int ID_REACH_MAX_LEVY_NUM = 2;
	static const char* STR_REACH_MAX_LEVY_NUM = "�������մ���������";

	static const unsigned int ID_IN_CD = 3;
	static const char* STR_IN_CD = "����CD��";

	static const char* STR_NAMESPACE = "ERR_LEVY_MAINTOWN_INCOME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_NOT_EXIST
	,STR_REACH_MAX_LEVY_NUM
	,STR_IN_CD
	};
}

namespace ERR_SET_WORK_TYPE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_CAPTURE_NOT_EXIST = 2;
	static const char* STR_CAPTURE_NOT_EXIST = "��²������";

	static const unsigned int ID_HAVE_SET = 3;
	static const char* STR_HAVE_SET = "�Ѿ�ָ����";

	static const unsigned int ID_INVALID_TYPE = 4;
	static const char* STR_INVALID_TYPE = "����������Ч";

	static const char* STR_NAMESPACE = "ERR_SET_WORK_TYPE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_CAPTURE_NOT_EXIST
	,STR_HAVE_SET
	,STR_INVALID_TYPE
	};
}

namespace ERR_DRIVE_AWAY_OWNER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_OWNER_NOT_EXIST = 2;
	static const char* STR_OWNER_NOT_EXIST = "��²��������";

	static const char* STR_NAMESPACE = "ERR_DRIVE_AWAY_OWNER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_OWNER_NOT_EXIST
	};
}

namespace ERR_OPEN_DRUG_USE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_NOT_EXIST = 1;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_DRUG_USE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_NOT_EXIST
	};
}

namespace ERR_OPEN_HERO_DRUG_USE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERONOTEXIST = 1;
	static const char* STR_HERONOTEXIST = "��鲻����";

	static const char* STR_NAMESPACE = "ERR_OPEN_HERO_DRUG_USE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERONOTEXIST
	};
}

namespace ERR_CLR_USE_DRUG_CD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERONOTEXIST = 1;
	static const char* STR_HERONOTEXIST = "��鲻����";

	static const char* STR_NAMESPACE = "ERR_CLR_USE_DRUG_CD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERONOTEXIST
	};
}

namespace ERR_USE_DRUG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERONOTEXIST = 1;
	static const char* STR_HERONOTEXIST = "��鲻����";

	static const unsigned int ID_DRUGNOTEXIST = 2;
	static const char* STR_DRUGNOTEXIST = "��ҩ������";

	static const unsigned int ID_BAGDRUGNOTEXIST = 3;
	static const char* STR_BAGDRUGNOTEXIST = "�����в����ڸõ�ҩ";

	static const char* STR_NAMESPACE = "ERR_USE_DRUG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERONOTEXIST
	,STR_DRUGNOTEXIST
	,STR_BAGDRUGNOTEXIST
	};
}

namespace ERR_OPEN_UPGRADE_DRUG_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_UPGRADE_DRUG_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_UPGRADE_DRUG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_DRUGNOTEXIST = 1;
	static const char* STR_DRUGNOTEXIST = "��ҩ������";

	static const unsigned int ID_BAGDRUGNOTEXIST = 2;
	static const char* STR_BAGDRUGNOTEXIST = "�����в����ڸõ�ҩ";

	static const unsigned int ID_BAGDRUGNOTENOUGH = 3;
	static const char* STR_BAGDRUGNOTENOUGH = "�����е�ҩ��������";

	static const unsigned int ID_DRUGMIXBAGFULL = 4;
	static const char* STR_DRUGMIXBAGFULL = "��������";

	static const unsigned int ID_DRUGMIXERROR = 5;
	static const char* STR_DRUGMIXERROR = "��ҩ�ϳ�ʧ��";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_DRUG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_DRUGNOTEXIST
	,STR_BAGDRUGNOTEXIST
	,STR_BAGDRUGNOTENOUGH
	,STR_DRUGMIXBAGFULL
	,STR_DRUGMIXERROR
	};
}

namespace ERR_COMPOSE_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_EQUIPNOTEXIST = 1;
	static const char* STR_EQUIPNOTEXIST = "װ��������";

	static const unsigned int ID_MATERIALNOTENOUGH = 2;
	static const char* STR_MATERIALNOTENOUGH = "���ϲ���";

	static const unsigned int ID_COMPOSEERROR = 3;
	static const char* STR_COMPOSEERROR = "�ϳ�ʧ��";

	static const unsigned int ID_HERONOTENOUGHLEAVER = 4;
	static const char* STR_HERONOTENOUGHLEAVER = "���ȼ�����";

	static const unsigned int ID_BAGFULL = 5;
	static const char* STR_BAGFULL = "��������";

	static const char* STR_NAMESPACE = "ERR_COMPOSE_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_EQUIPNOTEXIST
	,STR_MATERIALNOTENOUGH
	,STR_COMPOSEERROR
	,STR_HERONOTENOUGHLEAVER
	,STR_BAGFULL
	};
}

namespace ERR_OPEN_STRENGTH 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_STRENGTH";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_RECV_LEFT_INCOME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLUNDER_UNLOCK = 1;
	static const char* STR_PLUNDER_UNLOCK = "С����δ����";

	static const unsigned int ID_GRID_INVALID = 2;
	static const char* STR_GRID_INVALID = "���������Ч";

	static const unsigned int ID_NO_INCOME = 3;
	static const char* STR_NO_INCOME = "û������";

	static const char* STR_NAMESPACE = "ERR_RECV_LEFT_INCOME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLUNDER_UNLOCK
	,STR_GRID_INVALID
	,STR_NO_INCOME
	};
}

namespace ERR_GET_HERO_LIST 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLAY_NOT_EXIT = 1;
	static const char* STR_PLAY_NOT_EXIT = "��Ҳ�����";

	static const char* STR_NAMESPACE = "ERR_GET_HERO_LIST";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLAY_NOT_EXIT
	};
}

namespace ERR_GET_HERO_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLAY_NOT_EXIT = 1;
	static const char* STR_PLAY_NOT_EXIT = "��Ҳ�����";

	static const unsigned int ID_HERO_NOT_EXIT = 2;
	static const char* STR_HERO_NOT_EXIT = "��鲻����";

	static const char* STR_NAMESPACE = "ERR_GET_HERO_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLAY_NOT_EXIT
	,STR_HERO_NOT_EXIT
	};
}

namespace ERR_SMITHY_BUY_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SMITHY_NOT_EXIT = 1;
	static const char* STR_SMITHY_NOT_EXIT = "�����̲�����";

	static const unsigned int ID_HERO_NOT_EXIT = 2;
	static const char* STR_HERO_NOT_EXIT = "��鲻����";

	static const unsigned int ID_INVALID_EQUIP_POS = 3;
	static const char* STR_INVALID_EQUIP_POS = "��Ч����λ��";

	static const unsigned int ID_HAVE_EQUIP = 4;
	static const char* STR_HAVE_EQUIP = "��λ������װ��";

	static const char* STR_NAMESPACE = "ERR_SMITHY_BUY_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SMITHY_NOT_EXIT
	,STR_HERO_NOT_EXIT
	,STR_INVALID_EQUIP_POS
	,STR_HAVE_EQUIP
	};
}

namespace ERR_CLR_STRENGTHEN_CD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_CLR_STRENGTHEN_CD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_CROP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_CROP_IS_NOT_OPEN = 1;
	static const char* STR_CROP_IS_NOT_OPEN = "ũ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_CROP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_CROP_IS_NOT_OPEN
	};
}

namespace ERR_CROP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FIELD_NOT_EXIT = 1;
	static const char* STR_FIELD_NOT_EXIT = "�ؿ鲻����";

	static const unsigned int ID_FIELD_NOT_OPEN = 2;
	static const char* STR_FIELD_NOT_OPEN = "�ؿ�δ����";

	static const unsigned int ID_FIELD_HAVE_CROP = 3;
	static const char* STR_FIELD_HAVE_CROP = "�ؿ�����ֵ";

	static const unsigned int ID_SEED_NOT_EXIT = 4;
	static const char* STR_SEED_NOT_EXIT = "���Ӳ�����";

	static const unsigned int ID_CROP_IS_NOT_OPEN = 5;
	static const char* STR_CROP_IS_NOT_OPEN = "ũ��δ����";

	static const unsigned int ID_CROP_IS_NOT_POWER = 6;
	static const char* STR_CROP_IS_NOT_POWER = "��ǰ��ػ�������ֲ��˶������";

	static const unsigned int ID_CROP_IS_NOT_SEED = 7;
	static const char* STR_CROP_IS_NOT_SEED = "������������";

	static const char* STR_NAMESPACE = "ERR_CROP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FIELD_NOT_EXIT
	,STR_FIELD_NOT_OPEN
	,STR_FIELD_HAVE_CROP
	,STR_SEED_NOT_EXIT
	,STR_CROP_IS_NOT_OPEN
	,STR_CROP_IS_NOT_POWER
	,STR_CROP_IS_NOT_SEED
	};
}

namespace ERR_GAIN_CROP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FIELD_NOT_EXIT = 1;
	static const char* STR_FIELD_NOT_EXIT = "�ؿ鲻����";

	static const unsigned int ID_FIELD_NOT_OPEN = 2;
	static const char* STR_FIELD_NOT_OPEN = "�ؿ�δ����";

	static const unsigned int ID_FIELD_NOT_CROP = 3;
	static const char* STR_FIELD_NOT_CROP = "�ؿ�δ��ֵ";

	static const unsigned int ID_NOT_TIME_OUT = 4;
	static const char* STR_NOT_TIME_OUT = "�ؿ鲻���ջ�ʱ��δ����";

	static const unsigned int ID_BAG_FULL = 5;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_CROP_IS_NOT_OPEN = 6;
	static const char* STR_CROP_IS_NOT_OPEN = "ũ��δ����";

	static const char* STR_NAMESPACE = "ERR_GAIN_CROP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FIELD_NOT_EXIT
	,STR_FIELD_NOT_OPEN
	,STR_FIELD_NOT_CROP
	,STR_NOT_TIME_OUT
	,STR_BAG_FULL
	,STR_CROP_IS_NOT_OPEN
	};
}

namespace ERR_CROP_FIELD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FIELD_NOT_EXIT = 1;
	static const char* STR_FIELD_NOT_EXIT = "�ؿ鲻����";

	static const unsigned int ID_FIELD_IS_OPEN = 2;
	static const char* STR_FIELD_IS_OPEN = "�ؿ��ѿ���";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_LEVEL_NOT_ENOUGH = "���ǵȼ�����";

	static const unsigned int ID_CROP_IS_NOT_OPEN = 4;
	static const char* STR_CROP_IS_NOT_OPEN = "ũ��δ����";

	static const char* STR_NAMESPACE = "ERR_CROP_FIELD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FIELD_NOT_EXIT
	,STR_FIELD_IS_OPEN
	,STR_LEVEL_NOT_ENOUGH
	,STR_CROP_IS_NOT_OPEN
	};
}

namespace ERR_CLR_CROP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FIELD_NOT_EXIT = 1;
	static const char* STR_FIELD_NOT_EXIT = "�ؿ鲻����";

	static const unsigned int ID_FIELD_NOT_OPEN = 2;
	static const char* STR_FIELD_NOT_OPEN = "�ؿ�δ����";

	static const unsigned int ID_FIELD_NOT_CROP = 3;
	static const char* STR_FIELD_NOT_CROP = "�ؿ�δ��ֵ";

	static const unsigned int ID_CROP_IS_NOT_OPEN = 4;
	static const char* STR_CROP_IS_NOT_OPEN = "ũ��δ����";

	static const char* STR_NAMESPACE = "ERR_CLR_CROP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FIELD_NOT_EXIT
	,STR_FIELD_NOT_OPEN
	,STR_FIELD_NOT_CROP
	,STR_CROP_IS_NOT_OPEN
	};
}

namespace ERR_OPEN_ECPERIENCE_DRUG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ECPERIENCE_NOT_EXIT = 1;
	static const char* STR_ECPERIENCE_NOT_EXIT = "���鵤������";

	static const unsigned int ID_BAG_ECPERIENCE_NOT_EXIT = 2;
	static const char* STR_BAG_ECPERIENCE_NOT_EXIT = "�����в����ڸ��ྭ�鵤";

	static const unsigned int ID_HERO_NOT_EXIT = 3;
	static const char* STR_HERO_NOT_EXIT = "��鲻����";

	static const unsigned int ID_TAKING_FULL = 4;
	static const char* STR_TAKING_FULL = "���շ��ô�������";

	static const unsigned int ID_HERO_IS_COACH = 5;
	static const char* STR_HERO_IS_COACH = "�����޷����þ��鵤";

	static const unsigned int ID_ECPERIENCE_UNLOCK = 6;
	static const char* STR_ECPERIENCE_UNLOCK = "���þ��鵤����δ����";

	static const unsigned int ID_CUR_INDEX_ERROR = 7;
	static const char* STR_CUR_INDEX_ERROR = "��ǰ��������";

	static const char* STR_NAMESPACE = "ERR_OPEN_ECPERIENCE_DRUG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ECPERIENCE_NOT_EXIT
	,STR_BAG_ECPERIENCE_NOT_EXIT
	,STR_HERO_NOT_EXIT
	,STR_TAKING_FULL
	,STR_HERO_IS_COACH
	,STR_ECPERIENCE_UNLOCK
	,STR_CUR_INDEX_ERROR
	};
}

namespace ERR_USER_ECPERIENCE_DRUG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ECPERIENCE_NOT_EXIT = 1;
	static const char* STR_ECPERIENCE_NOT_EXIT = "���鵤������";

	static const unsigned int ID_BAG_ECPERIENCE_NOT_EXIT = 2;
	static const char* STR_BAG_ECPERIENCE_NOT_EXIT = "�����в����ڸ��ྭ�鵤";

	static const unsigned int ID_HERO_NOT_EXIT = 3;
	static const char* STR_HERO_NOT_EXIT = "��鲻����";

	static const unsigned int ID_TAKING_FULL = 4;
	static const char* STR_TAKING_FULL = "���շ��ô�������";

	static const unsigned int ID_HERO_IS_COACH = 5;
	static const char* STR_HERO_IS_COACH = "�����޷����þ��鵤";

	static const unsigned int ID_HERO_ENOUGH_LEAVER = 6;
	static const char* STR_HERO_ENOUGH_LEAVER = "���ȼ��޷��������ǵȼ�";

	static const unsigned int ID_GOOD_TYPE_ERR = 7;
	static const char* STR_GOOD_TYPE_ERR = "��Ʒ���ͳ���";

	static const unsigned int ID_NOT_REMAIN_GOLD_EXPERIENCE_CNT = 8;
	static const char* STR_NOT_REMAIN_GOLD_EXPERIENCE_CNT = "���մ����þ�";

	static const unsigned int ID_CUR_INDEX_ERROR = 9;
	static const char* STR_CUR_INDEX_ERROR = "��ǰ��������";

	static const unsigned int ID_NEED_FLY = 10;
	static const char* STR_NEED_FLY = "���ȼ���������Ҫ��������ܼ���ʹ�þ��鵤";

	static const char* STR_NAMESPACE = "ERR_USER_ECPERIENCE_DRUG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ECPERIENCE_NOT_EXIT
	,STR_BAG_ECPERIENCE_NOT_EXIT
	,STR_HERO_NOT_EXIT
	,STR_TAKING_FULL
	,STR_HERO_IS_COACH
	,STR_HERO_ENOUGH_LEAVER
	,STR_GOOD_TYPE_ERR
	,STR_NOT_REMAIN_GOLD_EXPERIENCE_CNT
	,STR_CUR_INDEX_ERROR
	,STR_NEED_FLY
	};
}

namespace ERR_OPEN_MELT_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_NOT_OPEN = 1;
	static const char* STR_BUILD_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_MELT_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_NOT_OPEN
	};
}

namespace ERR_MELT_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BAG_EQUIP_NOT_EXIT = 1;
	static const char* STR_BAG_EQUIP_NOT_EXIT = "����װ��������";

	static const unsigned int ID_BUILD_NOT_OPEN = 2;
	static const char* STR_BUILD_NOT_OPEN = "����δ����";

	static const unsigned int ID_EQUIP_HAVE_MOSAIC_GEM = 3;
	static const char* STR_EQUIP_HAVE_MOSAIC_GEM = "װ������Ƕ�б�ʯ,����ж��";

	static const unsigned int ID_BAG_GOOD_NOT_EXIT = 4;
	static const char* STR_BAG_GOOD_NOT_EXIT = "����װ����Ƭ������";

	static const unsigned int ID_BAG_GOOD_NOT_ENOUGH = 5;
	static const char* STR_BAG_GOOD_NOT_ENOUGH = "����װ����Ƭ��������";

	static const unsigned int ID_EQUIP_ENCHANT_ERR = 6;
	static const char* STR_EQUIP_ENCHANT_ERR = "װ���ѱ���ħ���޷�Ͷ������¯";

	static const char* STR_NAMESPACE = "ERR_MELT_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BAG_EQUIP_NOT_EXIT
	,STR_BUILD_NOT_OPEN
	,STR_EQUIP_HAVE_MOSAIC_GEM
	,STR_BAG_GOOD_NOT_EXIT
	,STR_BAG_GOOD_NOT_ENOUGH
	,STR_EQUIP_ENCHANT_ERR
	};
}

namespace ERR_OPEN_UPDATE_ATTR_PANNEL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_CANNOT_FIND = 1;
	static const char* STR_HERO_CANNOT_FIND = "��鲻����";

	static const unsigned int ID_ATTR_CANNOT_FIND = 2;
	static const char* STR_ATTR_CANNOT_FIND = "���Բ�����";

	static const unsigned int ID_ATTR_PARAM_ERROR = 3;
	static const char* STR_ATTR_PARAM_ERROR = "��������";

	static const unsigned int ID_ATTR_UPDATE_ATTR_UNLOCK = 4;
	static const char* STR_ATTR_UPDATE_ATTR_UNLOCK = "����ǿ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_UPDATE_ATTR_PANNEL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_CANNOT_FIND
	,STR_ATTR_CANNOT_FIND
	,STR_ATTR_PARAM_ERROR
	,STR_ATTR_UPDATE_ATTR_UNLOCK
	};
}

namespace ERR_UPDATE_ATTR 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_CANNOT_FIND = 1;
	static const char* STR_HERO_CANNOT_FIND = "��鲻����";

	static const unsigned int ID_ATTR_CANNOT_FIND = 2;
	static const char* STR_ATTR_CANNOT_FIND = "���Բ�����";

	static const unsigned int ID_ATTR_UPDATE_FULL = 3;
	static const char* STR_ATTR_UPDATE_FULL = "���������Ѵﵽ������";

	static const unsigned int ID_ATTR_PARAM_ERROR = 4;
	static const char* STR_ATTR_PARAM_ERROR = "��������";

	static const unsigned int ID_CANNOT_FIND_UPDATE_ITEM_ERROR = 5;
	static const char* STR_CANNOT_FIND_UPDATE_ITEM_ERROR = "�޷��ҵ�����������Ʒ";

	static const unsigned int ID_NOT_ENOUGH_ITEM = 6;
	static const char* STR_NOT_ENOUGH_ITEM = "û���㹻����Ʒ";

	static const char* STR_NAMESPACE = "ERR_UPDATE_ATTR";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_CANNOT_FIND
	,STR_ATTR_CANNOT_FIND
	,STR_ATTR_UPDATE_FULL
	,STR_ATTR_PARAM_ERROR
	,STR_CANNOT_FIND_UPDATE_ITEM_ERROR
	,STR_NOT_ENOUGH_ITEM
	};
}

namespace ERR_COMPOSE_GOODS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GOODS_NOT_COMPOSE = 1;
	static const char* STR_GOODS_NOT_COMPOSE = "��Ʒ���ɺϳ�";

	static const unsigned int ID_BAG_NOT_EXIST = 2;
	static const char* STR_BAG_NOT_EXIST = "��������Ʒ������";

	static const unsigned int ID_BAD_TYPE = 3;
	static const char* STR_BAD_TYPE = "��Ʒ���ͳ���";

	static const unsigned int ID_BAG_NOT_ENOUGH = 4;
	static const char* STR_BAG_NOT_ENOUGH = "��Ʒ��������";

	static const unsigned int ID_BAG_FULL = 5;
	static const char* STR_BAG_FULL = "��������";

	static const unsigned int ID_BAG_BOX_HIT = 6;
	static const char* STR_BAG_BOX_HIT = "�ϳ�ʧ��";

	static const char* STR_NAMESPACE = "ERR_COMPOSE_GOODS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GOODS_NOT_COMPOSE
	,STR_BAG_NOT_EXIST
	,STR_BAD_TYPE
	,STR_BAG_NOT_ENOUGH
	,STR_BAG_FULL
	,STR_BAG_BOX_HIT
	};
}

namespace ERR_GET_ITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_GET_ITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_BIND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_PARM = 1;
	static const char* STR_INVALID_PARM = "��������ȷ";

	static const unsigned int ID_PLAYERID_NOT_EXIT = 2;
	static const char* STR_PLAYERID_NOT_EXIT = "��Ҳ�����";

	static const unsigned int ID_USERID_IS_BINDED = 3;
	static const char* STR_USERID_IS_BINDED = "���û��˺��Ѱ�";

	static const unsigned int ID_ACCOUNT_IS_BINDED = 4;
	static const char* STR_ACCOUNT_IS_BINDED = "���˺��Ѱ������û�";

	static const unsigned int ID_AUTHTYPE_NOT_EXIT = 5;
	static const char* STR_AUTHTYPE_NOT_EXIT = "�󶨵��˺����Ͳ�֧��";

	static const char* STR_NAMESPACE = "ERR_BIND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_PARM
	,STR_PLAYERID_NOT_EXIT
	,STR_USERID_IS_BINDED
	,STR_ACCOUNT_IS_BINDED
	,STR_AUTHTYPE_NOT_EXIT
	};
}

namespace ERR_UNBIND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PLAYERID_NOT_EXIT = 1;
	static const char* STR_PLAYERID_NOT_EXIT = "��Ҳ�����";

	static const unsigned int ID_AUTHTYPE_NOT_EXIT = 2;
	static const char* STR_AUTHTYPE_NOT_EXIT = "�󶨵��˺����Ͳ�֧��";

	static const unsigned int ID_PLAYERID_NOT_BIND = 3;
	static const char* STR_PLAYERID_NOT_BIND = "����˺�δ��";

	static const unsigned int ID_PLAYERID_IS_COMPETENCE = 4;
	static const char* STR_PLAYERID_IS_COMPETENCE = "�û�û��Ȩ��";

	static const char* STR_NAMESPACE = "ERR_UNBIND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PLAYERID_NOT_EXIT
	,STR_AUTHTYPE_NOT_EXIT
	,STR_PLAYERID_NOT_BIND
	,STR_PLAYERID_IS_COMPETENCE
	};
}

namespace ERR_GET_ORDER_ID 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ERR_DISCONNECT_EXCHANGE_SERVER = 1;
	static const char* STR_ERR_DISCONNECT_EXCHANGE_SERVER = "��ֵʧ�ܣ������룺1";

	static const unsigned int ID_ERR_SEND_TO_EXCHANGE_SERVER = 2;
	static const char* STR_ERR_SEND_TO_EXCHANGE_SERVER = "��ֵʧ�ܣ������룺2";

	static const unsigned int ID_ERR_PARSE_DATA_FROM_EXCHANGE_SERVER = 3;
	static const char* STR_ERR_PARSE_DATA_FROM_EXCHANGE_SERVER = "��ֵʧ�ܣ������룺3";

	static const char* STR_NAMESPACE = "ERR_GET_ORDER_ID";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ERR_DISCONNECT_EXCHANGE_SERVER
	,STR_ERR_SEND_TO_EXCHANGE_SERVER
	,STR_ERR_PARSE_DATA_FROM_EXCHANGE_SERVER
	};
}

namespace ERR_EXCHANGE_RESULT_ID 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_EXCHANGE_RESULT_ID";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_COMPOSE_SEED 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GOODS_NOT_COMPOSE = 1;
	static const char* STR_GOODS_NOT_COMPOSE = "���Ӳ��ɺϳ�";

	static const unsigned int ID_BAG_NOT_EXIST = 2;
	static const char* STR_BAG_NOT_EXIST = "���������Ӳ�����";

	static const unsigned int ID_BAD_TYPE = 3;
	static const char* STR_BAD_TYPE = "�������ͳ���";

	static const unsigned int ID_BAG_NOT_ENOUGH = 4;
	static const char* STR_BAG_NOT_ENOUGH = "���Ӹ�������";

	static const unsigned int ID_BAG_FULL = 5;
	static const char* STR_BAG_FULL = "��������";

	static const char* STR_NAMESPACE = "ERR_COMPOSE_SEED";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GOODS_NOT_COMPOSE
	,STR_BAG_NOT_EXIST
	,STR_BAD_TYPE
	,STR_BAG_NOT_ENOUGH
	,STR_BAG_FULL
	};
}

namespace ERR_CHAT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_CHAT_PLAYERID_ERROR = 1;
	static const char* STR_CHAT_PLAYERID_ERROR = "�û�ID����";

	static const unsigned int ID_CHAT_TYPE_ERROR = 2;
	static const char* STR_CHAT_TYPE_ERROR = "�������Ͳ�֧��";

	static const unsigned int ID_CHAT_DATA_ERROR = 3;
	static const char* STR_CHAT_DATA_ERROR = "��������̫��";

	static const unsigned int ID_CHAT_SILENCE_ERROR = 4;
	static const char* STR_CHAT_SILENCE_ERROR = "��ұ����ԣ�����ϵ����Ա";

	static const unsigned int ID_CHAT_VERIFY_ERROR = 5;
	static const char* STR_CHAT_VERIFY_ERROR = "�������ݺ��зǷ����ݣ���ֹ";

	static const unsigned int ID_CHAT_BUSY_ERROR = 6;
	static const char* STR_CHAT_BUSY_ERROR = "��������æ�����Ժ�����";

	static const unsigned int ID_CHAT_EMPTY = 7;
	static const char* STR_CHAT_EMPTY = "�������ݲ���Ϊ��";

	static const unsigned int ID_CHAT_NOT_ENTER_FACTION = 8;
	static const char* STR_CHAT_NOT_ENTER_FACTION = "δ��������";

	static const char* STR_NAMESPACE = "ERR_CHAT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_CHAT_PLAYERID_ERROR
	,STR_CHAT_TYPE_ERROR
	,STR_CHAT_DATA_ERROR
	,STR_CHAT_SILENCE_ERROR
	,STR_CHAT_VERIFY_ERROR
	,STR_CHAT_BUSY_ERROR
	,STR_CHAT_EMPTY
	,STR_CHAT_NOT_ENTER_FACTION
	};
}

namespace ERR_OPEN_YABIAO_BUILD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_UNLOCK = 1;
	static const char* STR_BUILD_UNLOCK = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_YABIAO_BUILD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_UNLOCK
	};
}

namespace ERR_BEGIN_YABIAO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_MAX_YABIAO_COUNT_ERROR = 1;
	static const char* STR_MAX_YABIAO_COUNT_ERROR = "ȡ�������þ�";

	static const unsigned int ID_YABIAOING = 2;
	static const char* STR_YABIAOING = "����ȡ����";

	static const char* STR_NAMESPACE = "ERR_BEGIN_YABIAO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_MAX_YABIAO_COUNT_ERROR
	,STR_YABIAOING
	};
}

namespace ERR_OPEN_JIEBIAO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_QUERY_PLAYER_NUM_ERROR = 1;
	static const char* STR_QUERY_PLAYER_NUM_ERROR = "���������������";

	static const char* STR_NAMESPACE = "ERR_OPEN_JIEBIAO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_QUERY_PLAYER_NUM_ERROR
	};
}

namespace ERR_JIEBIAO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_MAX_JIEBIAO_COUNT_ERROR = 1;
	static const char* STR_MAX_JIEBIAO_COUNT_ERROR = "���ش����þ�";

	static const unsigned int ID_PLAYER_NOT_IN_YABIAO_ERROR = 2;
	static const char* STR_PLAYER_NOT_IN_YABIAO_ERROR = "����Ҳ���ȡ��";

	static const unsigned int ID_PLAYER_MAX_BE_JIEBIAO_COUNT_ERROR = 3;
	static const char* STR_PLAYER_MAX_BE_JIEBIAO_COUNT_ERROR = "����ұ�����̫��Σ�����������";

	static const unsigned int ID_CANNOT_FIND_PLAYER = 4;
	static const char* STR_CANNOT_FIND_PLAYER = "�޷��ҵ������";

	static const unsigned int ID_BATTLE_ERROR = 5;
	static const char* STR_BATTLE_ERROR = "ս������δ֪����";

	static const unsigned int ID_JIEBIAO_IN_CD = 6;
	static const char* STR_JIEBIAO_IN_CD = "���ػ�����ȴ��";

	static const unsigned int ID_CANNOT_JIEBIAO_SELF = 7;
	static const char* STR_CANNOT_JIEBIAO_SELF = "���������Լ�";

	static const unsigned int ID_CANNOT_REPEAT_JIEBIAO_PLAYER = 8;
	static const char* STR_CANNOT_REPEAT_JIEBIAO_PLAYER = "���Ѿ����ع������";

	static const char* STR_NAMESPACE = "ERR_JIEBIAO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_MAX_JIEBIAO_COUNT_ERROR
	,STR_PLAYER_NOT_IN_YABIAO_ERROR
	,STR_PLAYER_MAX_BE_JIEBIAO_COUNT_ERROR
	,STR_CANNOT_FIND_PLAYER
	,STR_BATTLE_ERROR
	,STR_JIEBIAO_IN_CD
	,STR_CANNOT_JIEBIAO_SELF
	,STR_CANNOT_REPEAT_JIEBIAO_PLAYER
	};
}

namespace ERR_OPNE_ACTIVITY_CENTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "δ����";

	static const char* STR_NAMESPACE = "ERR_OPNE_ACTIVITY_CENTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_OPNE_EAT_BREAD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "δ����";

	static const char* STR_NAMESPACE = "ERR_OPNE_EAT_BREAD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_OBTAIN_PHYSTRENGTHEN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "δ����";

	static const unsigned int ID_NOT_IN_ACTIVITY = 2;
	static const char* STR_NOT_IN_ACTIVITY = "δ�μӻ";

	static const unsigned int ID_ACTIVITY_OVER = 3;
	static const char* STR_ACTIVITY_OVER = "��ѽ���";

	static const char* STR_NAMESPACE = "ERR_OBTAIN_PHYSTRENGTHEN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	,STR_NOT_IN_ACTIVITY
	,STR_ACTIVITY_OVER
	};
}

namespace ERR_LEAVE_EAT_BREAD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "δ����";

	static const char* STR_NAMESPACE = "ERR_LEAVE_EAT_BREAD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_FLUSH_BIAO_QUALITY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_MAX_QUALITY_LEVEL = 1;
	static const char* STR_MAX_QUALITY_LEVEL = "����Ʒ���Ѿ�����õ�";

	static const unsigned int ID_YABIAOING = 2;
	static const char* STR_YABIAOING = "ȡ��ʱ����ˢ��Ʒ��";

	static const char* STR_NAMESPACE = "ERR_FLUSH_BIAO_QUALITY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_MAX_QUALITY_LEVEL
	,STR_YABIAOING
	};
}

namespace ERR_CLIMB_TOWER_RESET 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_SCIENCE = 1;
	static const char* STR_NOT_SCIENCE = "����������";

	static const unsigned int ID_NOT_TOWER = 2;
	static const char* STR_NOT_TOWER = "���򲻴���";

	static const unsigned int ID_NOT_ENOUGH_RESET_TIMES = 3;
	static const char* STR_NOT_ENOUGH_RESET_TIMES = "����������ô������ù�";

	static const unsigned int ID_BUY_TIMES_NOT_ENOUGH = 4;
	static const char* STR_BUY_TIMES_NOT_ENOUGH = "����ɹ������ô������ù�";

	static const unsigned int ID_UNDER_NO_RESET = 5;
	static const char* STR_UNDER_NO_RESET = "��ǰ���ڵײ㣬��������";

	static const char* STR_NAMESPACE = "ERR_CLIMB_TOWER_RESET";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_SCIENCE
	,STR_NOT_TOWER
	,STR_NOT_ENOUGH_RESET_TIMES
	,STR_BUY_TIMES_NOT_ENOUGH
	,STR_UNDER_NO_RESET
	};
}

namespace ERR_BUY_CLIMB_TOWER_RESET 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUY_TIMES_NOT_ENOUGH = 1;
	static const char* STR_BUY_TIMES_NOT_ENOUGH = "���칺��������ù�";

	static const char* STR_NAMESPACE = "ERR_BUY_CLIMB_TOWER_RESET";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUY_TIMES_NOT_ENOUGH
	};
}

namespace ERR_CLIMB_TOWER_ONHOOK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PHYSTRENGTH_NOT_ENOUGH = 1;
	static const char* STR_PHYSTRENGTH_NOT_ENOUGH = "��������";

	static const unsigned int ID_CLIMBTOWER_ONE_PER_DAY_ERR = 2;
	static const char* STR_CLIMBTOWER_ONE_PER_DAY_ERR = "�������ͨ�ع����";

	static const unsigned int ID_BAG_FULL = 3;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_INSTANCE_NOT_EXIST = 4;
	static const char* STR_INSTANCE_NOT_EXIST = "�ò㲻����";

	static const unsigned int ID_INSTANCE_NOT_BATTLED = 5;
	static const char* STR_INSTANCE_NOT_BATTLED = "������δͨ�أ������Զ�����";

	static const unsigned int ID_OUT_MAX_RUN_RANG = 6;
	static const char* STR_OUT_MAX_RUN_RANG = "���ֻ���Զ�����40�β�";

	static const unsigned int ID_RUN_TIMES_0 = 7;
	static const char* STR_RUN_TIMES_0 = "�Զ�������������Ϊ0";

	static const unsigned int ID_NOT_IN_ONHOOK = 8;
	static const char* STR_NOT_IN_ONHOOK = "û�д����Զ�����״̬";

	static const unsigned int ID_ONHOOK_ING = 9;
	static const char* STR_ONHOOK_ING = "�����Զ�������";

	static const unsigned int ID_ONHOOK_UNLOCK = 10;
	static const char* STR_ONHOOK_UNLOCK = "�Զ�����δ����";

	static const unsigned int ID_NOT_SCIENCE = 11;
	static const char* STR_NOT_SCIENCE = "����������";

	static const unsigned int ID_NOT_TOWER = 12;
	static const char* STR_NOT_TOWER = "�ò�Ŀ�겻����";

	static const char* STR_NAMESPACE = "ERR_CLIMB_TOWER_ONHOOK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PHYSTRENGTH_NOT_ENOUGH
	,STR_CLIMBTOWER_ONE_PER_DAY_ERR
	,STR_BAG_FULL
	,STR_INSTANCE_NOT_EXIST
	,STR_INSTANCE_NOT_BATTLED
	,STR_OUT_MAX_RUN_RANG
	,STR_RUN_TIMES_0
	,STR_NOT_IN_ONHOOK
	,STR_ONHOOK_ING
	,STR_ONHOOK_UNLOCK
	,STR_NOT_SCIENCE
	,STR_NOT_TOWER
	};
}

namespace ERR_GET_YABIAO_BATTLE_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK_YABIAO_ERR = 1;
	static const char* STR_UNLOCK_YABIAO_ERR = "ȡ��������δ����";

	static const char* STR_NAMESPACE = "ERR_GET_YABIAO_BATTLE_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK_YABIAO_ERR
	};
}

namespace ERR_GET_YABIAO_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK_YABIAO_ERR = 1;
	static const char* STR_UNLOCK_YABIAO_ERR = "ȡ��������δ����";

	static const unsigned int ID_CANNOT_FIND_ENCOURAGE = 2;
	static const char* STR_CANNOT_FIND_ENCOURAGE = "û�н���";

	static const unsigned int ID_TIME_NOT_DOWN = 3;
	static const char* STR_TIME_NOT_DOWN = "ȡ��δ��ɣ�������ȡ����";

	static const char* STR_NAMESPACE = "ERR_GET_YABIAO_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK_YABIAO_ERR
	,STR_CANNOT_FIND_ENCOURAGE
	,STR_TIME_NOT_DOWN
	};
}

namespace ERR_GET_BATTLE_DATA 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BATTLE_NOT_EXIST = 1;
	static const char* STR_BATTLE_NOT_EXIST = "��ø�ս����Ϣʧ��";

	static const char* STR_NAMESPACE = "ERR_GET_BATTLE_DATA";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BATTLE_NOT_EXIST
	};
}

namespace ERR_OPEN_YABIAO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_YABIAO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_UPGRADE_JINGJIE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_JINGJIE_UNLOCK = 1;
	static const char* STR_JINGJIE_UNLOCK = "������δ����";

	static const unsigned int ID_QUALITY_INVALID = 2;
	static const char* STR_QUALITY_INVALID = "����Ч";

	static const unsigned int ID_LEVEL_INVALID = 3;
	static const char* STR_LEVEL_INVALID = "�ȼ���Ч";

	static const unsigned int ID_NOT_REACH_MAX_LEVEL = 4;
	static const char* STR_NOT_REACH_MAX_LEVEL = "δ�ﵽ��ǰ�׵����ȼ�����������";

	static const unsigned int ID_NOT_ENOUGH_JINGJIE = 5;
	static const char* STR_NOT_ENOUGH_JINGJIE = "����㲻��";

	static const unsigned int ID_MAX_QUALITY_LEVEL = 6;
	static const char* STR_MAX_QUALITY_LEVEL = "�����Ѵﵽ����";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_JINGJIE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_JINGJIE_UNLOCK
	,STR_QUALITY_INVALID
	,STR_LEVEL_INVALID
	,STR_NOT_REACH_MAX_LEVEL
	,STR_NOT_ENOUGH_JINGJIE
	,STR_MAX_QUALITY_LEVEL
	};
}

namespace ERR_GEN_GAS_BALL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_REACH_MAX_NUM = 1;
	static const char* STR_REACH_MAX_NUM = "�Ѿ��ﵽ������";

	static const unsigned int ID_COLLECT_GAS_UNLOCK = 2;
	static const char* STR_COLLECT_GAS_UNLOCK = "�ۻ깦����δ����";

	static const unsigned int ID_VIP_NOT_ENOUGH_UNLOCK = 3;
	static const char* STR_VIP_NOT_ENOUGH_UNLOCK = "δ�ﵽVIP�ȼ�����δ����";

	static const char* STR_NAMESPACE = "ERR_GEN_GAS_BALL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_REACH_MAX_NUM
	,STR_COLLECT_GAS_UNLOCK
	,STR_VIP_NOT_ENOUGH_UNLOCK
	};
}

namespace ERR_UP_GAS_BALL_LEVEL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_VIP_NOT_ENOUGH_UNLOCK = 1;
	static const char* STR_VIP_NOT_ENOUGH_UNLOCK = "δ�ﵽVIP�ȼ�����δ����";

	static const unsigned int ID_UN_GEN = 2;
	static const char* STR_UN_GEN = "��δ�ۻ�";

	static const unsigned int ID_COLLECT_GAS_UNLOCK = 3;
	static const char* STR_COLLECT_GAS_UNLOCK = "�ۻ깦����δ����";

	static const unsigned int ID_COLLECT_GAS_FULL = 4;
	static const char* STR_COLLECT_GAS_FULL = "��ʹ��һ�����ɳ�";

	static const char* STR_NAMESPACE = "ERR_UP_GAS_BALL_LEVEL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_VIP_NOT_ENOUGH_UNLOCK
	,STR_UN_GEN
	,STR_COLLECT_GAS_UNLOCK
	,STR_COLLECT_GAS_FULL
	};
}

namespace ERR_COLLECT_GAS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UN_GEN = 1;
	static const char* STR_UN_GEN = "��δ�ۻ�";

	static const unsigned int ID_COLLECT_GAS_UNLOCK = 2;
	static const char* STR_COLLECT_GAS_UNLOCK = "�ۻ깦����δ����";

	static const char* STR_NAMESPACE = "ERR_COLLECT_GAS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UN_GEN
	,STR_COLLECT_GAS_UNLOCK
	};
}

namespace ERR_UPGRADE_SKILL_ACTION_LEVEL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SKILL_UNLOCK = 1;
	static const char* STR_SKILL_UNLOCK = "����δ����";

	static const unsigned int ID_ACTION_NOT_EXIST = 2;
	static const char* STR_ACTION_NOT_EXIST = "��ʽ������";

	static const unsigned int ID_LEVEL_UNLOCK = 3;
	static const char* STR_LEVEL_UNLOCK = "��ǰ�޷��������������ǿ������ʽ�ȼ�����";

	static const unsigned int ID_LEVEL_INVALID = 4;
	static const char* STR_LEVEL_INVALID = "�ȼ���Ч";

	static const unsigned int ID_REACH_MAX_LEVEL = 5;
	static const char* STR_REACH_MAX_LEVEL = "�Ѿ��ﵽ���ȼ�";

	static const unsigned int ID_CAN_NOT_GREATE_PRE = 6;
	static const char* STR_CAN_NOT_GREATE_PRE = "���ܴ���ǰ����ʽ�ȼ�";

	static const unsigned int ID_NOT_ENOUGH_PURPLEGAS = 7;
	static const char* STR_NOT_ENOUGH_PURPLEGAS = "��������";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_SKILL_ACTION_LEVEL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SKILL_UNLOCK
	,STR_ACTION_NOT_EXIST
	,STR_LEVEL_UNLOCK
	,STR_LEVEL_INVALID
	,STR_REACH_MAX_LEVEL
	,STR_CAN_NOT_GREATE_PRE
	,STR_NOT_ENOUGH_PURPLEGAS
	};
}

namespace ERR_SELECT_SKILL_ACTION_EFFECT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SKILL_UNLOCK = 1;
	static const char* STR_SKILL_UNLOCK = "����δ����";

	static const unsigned int ID_ACTION_UNLOCK = 2;
	static const char* STR_ACTION_UNLOCK = "��ʽδ����";

	static const unsigned int ID_EFFECT_UNLOCK = 3;
	static const char* STR_EFFECT_UNLOCK = "Ч��δ����";

	static const unsigned int ID_RANG_UNLOCK = 4;
	static const char* STR_RANG_UNLOCK = "��Χδ����";

	static const char* STR_NAMESPACE = "ERR_SELECT_SKILL_ACTION_EFFECT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SKILL_UNLOCK
	,STR_ACTION_UNLOCK
	,STR_EFFECT_UNLOCK
	,STR_RANG_UNLOCK
	};
}

namespace ERR_OPEN_JINGJIE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_JINGJIE_UNLOCK = 1;
	static const char* STR_JINGJIE_UNLOCK = "������δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_JINGJIE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_JINGJIE_UNLOCK
	};
}

namespace ERR_OPEN_GEN_GAS_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_COLLECT_GAS_UNLOCK = 1;
	static const char* STR_COLLECT_GAS_UNLOCK = "�ռ�����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_GEN_GAS_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_COLLECT_GAS_UNLOCK
	};
}

namespace ERR_OPEN_SKILL_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SKILL_UNLOCK = 1;
	static const char* STR_SKILL_UNLOCK = "������δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SKILL_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SKILL_UNLOCK
	};
}

namespace ERR_CLEAR_JIEBIAO_CD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_CLEAR_JIEBIAO_CD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_VIP_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_VIP_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_XIANGQIAN_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_XIANGQIAN_UNLOCK = 1;
	static const char* STR_XIANGQIAN_UNLOCK = "��Ƕ������δ����";

	static const unsigned int ID_XIANGQIAN_FUNC_NOT_EXIST = 2;
	static const char* STR_XIANGQIAN_FUNC_NOT_EXIST = "��Ƕ���ܲ�����";

	static const char* STR_NAMESPACE = "ERR_OPEN_XIANGQIAN_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_XIANGQIAN_UNLOCK
	,STR_XIANGQIAN_FUNC_NOT_EXIST
	};
}

namespace ERR_XIANGQIAN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_EQUIP_NOT_EXIST = 1;
	static const char* STR_EQUIP_NOT_EXIST = "װ��������";

	static const unsigned int ID_GOODS_NOT_EXIST = 2;
	static const char* STR_GOODS_NOT_EXIST = "��Ʒ������";

	static const unsigned int ID_HOLE_LOCK = 3;
	static const char* STR_HOLE_LOCK = "��Ƕ��δ�������޷���Ƕ";

	static const unsigned int ID_NOT_EXIST_HOLE = 4;
	static const char* STR_NOT_EXIST_HOLE = "����Ƕ�ײ�����";

	static const unsigned int ID_ALREADY_XIANGQIAN = 5;
	static const char* STR_ALREADY_XIANGQIAN = "����Ƕ���Ѿ���Ƕ��ʯ";

	static const unsigned int ID_BUILD_UNLOCK = 6;
	static const char* STR_BUILD_UNLOCK = "��Ƕ������δ����";

	static const unsigned int ID_ALREADY_XIANGQIAN_THIS_TYPE = 7;
	static const char* STR_ALREADY_XIANGQIAN_THIS_TYPE = "��λ�ò�����Ƕ";

	static const unsigned int ID_XIANGQIAN_GEM_CHANGE = 8;
	static const char* STR_XIANGQIAN_GEM_CHANGE = "�滻��ʯʧ�ܣ����鱳���Ƿ�����";

	static const unsigned int ID_EQUIP_POS_CANNOT_XIANGQIAN = 9;
	static const char* STR_EQUIP_POS_CANNOT_XIANGQIAN = "�ý�װ��������Ƕ";

	static const char* STR_NAMESPACE = "ERR_XIANGQIAN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_EQUIP_NOT_EXIST
	,STR_GOODS_NOT_EXIST
	,STR_HOLE_LOCK
	,STR_NOT_EXIST_HOLE
	,STR_ALREADY_XIANGQIAN
	,STR_BUILD_UNLOCK
	,STR_ALREADY_XIANGQIAN_THIS_TYPE
	,STR_XIANGQIAN_GEM_CHANGE
	,STR_EQUIP_POS_CANNOT_XIANGQIAN
	};
}

namespace ERR_CHECK_APPSTORE_ORDER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PROCESS_ERROR_WITH_APPLE = 1;
	static const char* STR_PROCESS_ERROR_WITH_APPLE = "��ƻ�����������������з�������";

	static const unsigned int ID_ORDER_ID_ERROR = 2;
	static const char* STR_ORDER_ID_ERROR = "��ֵ�����Ƿ�";

	static const unsigned int ID_PLAYER_ID_ERROR = 3;
	static const char* STR_PLAYER_ID_ERROR = "���ID���󣬳�ֵʧ��";

	static const unsigned int ID_SERVER_INNER_ERROR = 4;
	static const char* STR_SERVER_INNER_ERROR = "�������ڲ����󣬳�ֵʧ�ܣ�����ϵGM";

	static const char* STR_NAMESPACE = "ERR_CHECK_APPSTORE_ORDER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PROCESS_ERROR_WITH_APPLE
	,STR_ORDER_ID_ERROR
	,STR_PLAYER_ID_ERROR
	,STR_SERVER_INNER_ERROR
	};
}

namespace ERR_REMOVE_XIANGQIAN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_EQUIP_NOT_EXIST = 1;
	static const char* STR_EQUIP_NOT_EXIST = "װ��������";

	static const unsigned int ID_EQUIP_NOT_XIANGQIAN = 2;
	static const char* STR_EQUIP_NOT_XIANGQIAN = "����Ƕ��û����ʯ";

	static const unsigned int ID_BUILD_UNLOCK = 3;
	static const char* STR_BUILD_UNLOCK = "��Ƕ������δ����";

	static const unsigned int ID_CHECK_BAG_AREA = 4;
	static const char* STR_CHECK_BAG_AREA = "ժ��ʧ�ܣ����鱳���ռ�";

	static const char* STR_NAMESPACE = "ERR_REMOVE_XIANGQIAN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_EQUIP_NOT_EXIST
	,STR_EQUIP_NOT_XIANGQIAN
	,STR_BUILD_UNLOCK
	,STR_CHECK_BAG_AREA
	};
}

namespace ERR_RESET_ELITE_INSTANCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_TOWN_NOT_EXIST = 1;
	static const char* STR_TOWN_NOT_EXIST = "���鸱��������";

	static const unsigned int ID_INDEX_ERROR = 2;
	static const char* STR_INDEX_ERROR = "���ô�������";

	static const unsigned int ID_RESET_ERROR = 3;
	static const char* STR_RESET_ERROR = "���÷�������";

	static const char* STR_NAMESPACE = "ERR_RESET_ELITE_INSTANCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_TOWN_NOT_EXIST
	,STR_INDEX_ERROR
	,STR_RESET_ERROR
	};
}

namespace ERR_ELITE_INSTANCE_ON_HOOK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_PHYSTRENGTH_NOT_ENOUGH = 1;
	static const char* STR_PHYSTRENGTH_NOT_ENOUGH = "��������";

	static const unsigned int ID_BAG_FULL = 2;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_INSTANCE_NOT_EXIST = 3;
	static const char* STR_INSTANCE_NOT_EXIST = "����������";

	static const unsigned int ID_INSTANCE_NOT_BATTLED = 4;
	static const char* STR_INSTANCE_NOT_BATTLED = "�ø�����δͨ�أ��޷�ɨ��";

	static const unsigned int ID_NOT_TOWER = 5;
	static const char* STR_NOT_TOWER = "���鸱��������";

	static const unsigned int ID_NOT_SCIENCE = 6;
	static const char* STR_NOT_SCIENCE = "����������";

	static const unsigned int ID_ONHOOK_UNLOCK = 7;
	static const char* STR_ONHOOK_UNLOCK = "ɨ��δ����";

	static const unsigned int ID_TODAY_ALREADY_BATTLED = 8;
	static const char* STR_TODAY_ALREADY_BATTLED = "�����Ѿ���ս";

	static const char* STR_NAMESPACE = "ERR_ELITE_INSTANCE_ON_HOOK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_PHYSTRENGTH_NOT_ENOUGH
	,STR_BAG_FULL
	,STR_INSTANCE_NOT_EXIST
	,STR_INSTANCE_NOT_BATTLED
	,STR_NOT_TOWER
	,STR_NOT_SCIENCE
	,STR_ONHOOK_UNLOCK
	,STR_TODAY_ALREADY_BATTLED
	};
}

namespace ERR_GET_ACTIVITY_PROMPT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_GET_ACTIVITY_PROMPT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_BLUE_TO_PURPLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_JINGJIE_UNLOCK = 1;
	static const char* STR_JINGJIE_UNLOCK = "������δ����";

	static const unsigned int ID_BLUE_NOT_ENOUGH = 2;
	static const char* STR_BLUE_NOT_ENOUGH = "��������";

	static const char* STR_NAMESPACE = "ERR_BLUE_TO_PURPLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_JINGJIE_UNLOCK
	,STR_BLUE_NOT_ENOUGH
	};
}

namespace ERR_REPORT_USER_DEVICE_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_REPORT_USER_DEVICE_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_PKBATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ENEMY_NOT_EXIST = 1;
	static const char* STR_ENEMY_NOT_EXIST = "Ŀ�겻����";

	static const unsigned int ID_ENEMY_MYSELF = 2;
	static const char* STR_ENEMY_MYSELF = "���ɺ��Լ��д�";

	static const char* STR_NAMESPACE = "ERR_PKBATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ENEMY_NOT_EXIST
	,STR_ENEMY_MYSELF
	};
}

namespace ERR_DEVICE_UN_BIND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_DEVICE_UN_BIND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_ENTER_BOSSB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_BOSSB_UNSTART = 2;
	static const char* STR_BOSSB_UNSTART = "�δ��ʼ";

	static const char* STR_NAMESPACE = "ERR_ENTER_BOSSB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_BOSSB_UNSTART
	};
}

namespace ERR_LEAVE_BOSSB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const char* STR_NAMESPACE = "ERR_LEAVE_BOSSB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	};
}

namespace ERR_BOSSB_MOVE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_BOSSB_UNSTART = 2;
	static const char* STR_BOSSB_UNSTART = "�δ��ʼ";

	static const unsigned int ID_RELIVE_CD = 3;
	static const char* STR_RELIVE_CD = "����CD��";

	static const unsigned int ID_MOVE_FREQUENTLY = 4;
	static const char* STR_MOVE_FREQUENTLY = "�ƶ�����Ƶ��";

	static const unsigned int ID_MOVE_LEN_INVALID = 5;
	static const char* STR_MOVE_LEN_INVALID = "�ƶ�����Ƿ�";

	static const unsigned int ID_NOT_IN_ACTIVITY = 6;
	static const char* STR_NOT_IN_ACTIVITY = "δ������";

	static const unsigned int ID_READY_CD = 7;
	static const char* STR_READY_CD = "ս����δ��ʼ�������뿪׼����";

	static const char* STR_NAMESPACE = "ERR_BOSSB_MOVE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_BOSSB_UNSTART
	,STR_RELIVE_CD
	,STR_MOVE_FREQUENTLY
	,STR_MOVE_LEN_INVALID
	,STR_NOT_IN_ACTIVITY
	,STR_READY_CD
	};
}

namespace ERR_BOSSB_HURT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_BOSSB_UNSTART = 2;
	static const char* STR_BOSSB_UNSTART = "�δ��ʼ";

	static const unsigned int ID_RELIVE_CD = 3;
	static const char* STR_RELIVE_CD = "����CD��";

	static const unsigned int ID_NOT_IN_ACTIVITY = 4;
	static const char* STR_NOT_IN_ACTIVITY = "δ������";

	static const unsigned int ID_READY_CD = 5;
	static const char* STR_READY_CD = "ս����δ��ʼ�������뿪׼����";

	static const char* STR_NAMESPACE = "ERR_BOSSB_HURT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_BOSSB_UNSTART
	,STR_RELIVE_CD
	,STR_NOT_IN_ACTIVITY
	,STR_READY_CD
	};
}

namespace ERR_BOSSB_POS_NTF 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const char* STR_NAMESPACE = "ERR_BOSSB_POS_NTF";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	};
}

namespace ERR_BOSSB_PLAYER_HRUT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const char* STR_NAMESPACE = "ERR_BOSSB_PLAYER_HRUT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	};
}

namespace ERR_OPEN_INSPIRE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_NOT_IN_ACTIVITY = 2;
	static const char* STR_NOT_IN_ACTIVITY = "δ������";

	static const unsigned int ID_BOSSB_UNSTART = 3;
	static const char* STR_BOSSB_UNSTART = "�δ��ʼ";

	static const char* STR_NAMESPACE = "ERR_OPEN_INSPIRE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_NOT_IN_ACTIVITY
	,STR_BOSSB_UNSTART
	};
}

namespace ERR_INSPIRE_POWER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_STORY_NOT_ENOUGH = 2;
	static const char* STR_STORY_NOT_ENOUGH = "��������";

	static const unsigned int ID_NOT_IN_ACTIVITY = 3;
	static const char* STR_NOT_IN_ACTIVITY = "δ������";

	static const unsigned int ID_BOSSB_UNSTART = 4;
	static const char* STR_BOSSB_UNSTART = "�δ��ʼ";

	static const unsigned int ID_REACH_MAX = 5;
	static const char* STR_REACH_MAX = "ս���ӳ��Ѵﵽ����";

	static const char* STR_NAMESPACE = "ERR_INSPIRE_POWER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_STORY_NOT_ENOUGH
	,STR_NOT_IN_ACTIVITY
	,STR_BOSSB_UNSTART
	,STR_REACH_MAX
	};
}

namespace ERR_BOSSB_RELIVE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_NOT_IN_ACTIVITY = 2;
	static const char* STR_NOT_IN_ACTIVITY = "δ������";

	static const unsigned int ID_BOSSB_UNSTART = 3;
	static const char* STR_BOSSB_UNSTART = "�δ��ʼ";

	static const unsigned int ID_GOLD_RELIVE_CD = 4;
	static const char* STR_GOLD_RELIVE_CD = "Ԫ������CD��";

	static const char* STR_NAMESPACE = "ERR_BOSSB_RELIVE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_NOT_IN_ACTIVITY
	,STR_BOSSB_UNSTART
	,STR_GOLD_RELIVE_CD
	};
}

namespace ERR_GET_LAST_BOSSB_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const unsigned int ID_BOSSB_UNOVER = 2;
	static const char* STR_BOSSB_UNOVER = "bossս��δ����";

	static const char* STR_NAMESPACE = "ERR_GET_LAST_BOSSB_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	,STR_BOSSB_UNOVER
	};
}

namespace ERR_OPEN_RECHARGE_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RECEVED_RECHARGE_ENCOURAGE_ERR = 1;
	static const char* STR_RECEVED_RECHARGE_ENCOURAGE_ERR = "����ȡ��ֵ����";

	static const unsigned int ID_NOT_EXIST_BUILD_ERR = 2;
	static const char* STR_NOT_EXIST_BUILD_ERR = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_RECHARGE_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RECEVED_RECHARGE_ENCOURAGE_ERR
	,STR_NOT_EXIST_BUILD_ERR
	};
}

namespace ERR_RECV_RECHARGE_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_RECHARGE_ENCOURAGE_ERR = 1;
	static const char* STR_NO_RECHARGE_ENCOURAGE_ERR = "δ��ֵ,������ȡ����";

	static const unsigned int ID_RECEVED_RECHARGE_ENCOURAGE_ERR = 2;
	static const char* STR_RECEVED_RECHARGE_ENCOURAGE_ERR = "����ȡ��ֵ����";

	static const unsigned int ID_BAG_FULL_ERR = 3;
	static const char* STR_BAG_FULL_ERR = "��������������������";

	static const unsigned int ID_NOT_EXIST_BUILD_ERR = 4;
	static const char* STR_NOT_EXIST_BUILD_ERR = "������δ����";

	static const unsigned int ID_UPPER_LIMIT_ERR = 5;
	static const char* STR_UPPER_LIMIT_ERR = "��Я����������ﵽ����";

	static const char* STR_NAMESPACE = "ERR_RECV_RECHARGE_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_RECHARGE_ENCOURAGE_ERR
	,STR_RECEVED_RECHARGE_ENCOURAGE_ERR
	,STR_BAG_FULL_ERR
	,STR_NOT_EXIST_BUILD_ERR
	,STR_UPPER_LIMIT_ERR
	};
}

namespace ERR_OPEN_SCORE_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RECEVED_RECHARGE_ENCOURAGE_ERR = 1;
	static const char* STR_RECEVED_RECHARGE_ENCOURAGE_ERR = "����ȡ���ֽ���";

	static const unsigned int ID_NOT_EXIST_BUILD_ERR = 2;
	static const char* STR_NOT_EXIST_BUILD_ERR = "����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_SCORE_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RECEVED_RECHARGE_ENCOURAGE_ERR
	,STR_NOT_EXIST_BUILD_ERR
	};
}

namespace ERR_RECV_SCORE_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RECEVED_RECHARGE_ENCOURAGE_ERR = 1;
	static const char* STR_RECEVED_RECHARGE_ENCOURAGE_ERR = "����ȡ���ֽ���";

	static const unsigned int ID_BAG_FULL_ERR = 2;
	static const char* STR_BAG_FULL_ERR = "��������������������";

	static const unsigned int ID_NOT_EXIST_BUILD_ERR = 3;
	static const char* STR_NOT_EXIST_BUILD_ERR = "����������";

	static const char* STR_NAMESPACE = "ERR_RECV_SCORE_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RECEVED_RECHARGE_ENCOURAGE_ERR
	,STR_BAG_FULL_ERR
	,STR_NOT_EXIST_BUILD_ERR
	};
}

namespace ERR_GET_RANDOM_DSPNAME 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_GET_RANDOM_DSPNAME";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_BOSSB_BATTLE_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BOSSB_UNLOCK = 1;
	static const char* STR_BOSSB_UNLOCK = "bossս��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_BOSSB_BATTLE_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BOSSB_UNLOCK
	};
}

namespace ERR_OPEN_EXPERIENCE_TRANSFER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIT = 1;
	static const char* STR_HERO_NOT_EXIT = "��鲻����";

	static const unsigned int ID_BUILD_NOT_EXIT = 2;
	static const char* STR_BUILD_NOT_EXIT = "���鴫����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_EXPERIENCE_TRANSFER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIT
	,STR_BUILD_NOT_EXIT
	};
}

namespace ERR_EXPERIENCE_TRANSFER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIT = 1;
	static const char* STR_HERO_NOT_EXIT = "���о���Ļ�鲻����";

	static const unsigned int ID_TRANS_HERO_NOT_EXIT = 2;
	static const char* STR_TRANS_HERO_NOT_EXIT = "���ܾ��鴫�еĻ�鲻����";

	static const unsigned int ID_TRANS_HERO_EQUIL = 3;
	static const char* STR_TRANS_HERO_EQUIL = "�޷������Լ��ľ��鴫��";

	static const unsigned int ID_TRANS_HERO_OVER_STEP = 4;
	static const char* STR_TRANS_HERO_OVER_STEP = "�û���ѽ��ܹ����鴫��";

	static const unsigned int ID_TRANS_HERO_COACH = 5;
	static const char* STR_TRANS_HERO_COACH = "���ǲ��ɽ��ܾ��鴫��";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 6;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_BUILD_NOT_EXIT = 7;
	static const char* STR_BUILD_NOT_EXIT = "���鴫����δ����";

	static const unsigned int ID_HERO_TWICE_ERR = 8;
	static const char* STR_HERO_TWICE_ERR = "���ֻ�ɽ���һ�ξ��鴫��";

	static const unsigned int ID_HERO_MUTUAL_TRANSFER = 9;
	static const char* STR_HERO_MUTUAL_TRANSFER = "�������䲻�ɻ�����ܾ��鴫��";

	static const char* STR_NAMESPACE = "ERR_EXPERIENCE_TRANSFER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIT
	,STR_TRANS_HERO_NOT_EXIT
	,STR_TRANS_HERO_EQUIL
	,STR_TRANS_HERO_OVER_STEP
	,STR_TRANS_HERO_COACH
	,STR_GOLD_NOT_ENOUGH
	,STR_BUILD_NOT_EXIT
	,STR_HERO_TWICE_ERR
	,STR_HERO_MUTUAL_TRANSFER
	};
}

namespace ERR_OPEN_RDCHALLENGE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "�����սδ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_RDCHALLENGE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_RDCHALLENGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "�����ս������δ����";

	static const unsigned int ID_ENEMY_NOT_EXIST = 2;
	static const char* STR_ENEMY_NOT_EXIST = "Ŀ�겻����";

	static const unsigned int ID_NUM_OVER = 3;
	static const char* STR_NUM_OVER = "��ս����������";

	static const unsigned int ID_IN_CD = 4;
	static const char* STR_IN_CD = "��սCD��";

	static const unsigned int ID_HAVE_CHALLENGE = 5;
	static const char* STR_HAVE_CHALLENGE = "����ս";

	static const unsigned int ID_NOT_REFRESH_PLAYER = 6;
	static const char* STR_NOT_REFRESH_PLAYER = "������ս������ˢ�³��ֵ�Ŀ��";

	static const unsigned int ID_NOT_BAG = 7;
	static const char* STR_NOT_BAG = "����������������";

	static const char* STR_NAMESPACE = "ERR_RDCHALLENGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	,STR_ENEMY_NOT_EXIST
	,STR_NUM_OVER
	,STR_IN_CD
	,STR_HAVE_CHALLENGE
	,STR_NOT_REFRESH_PLAYER
	,STR_NOT_BAG
	};
}

namespace ERR_CLR_RDCHALLENGE_CD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "�����ս������δ����";

	static const char* STR_NAMESPACE = "ERR_CLR_RDCHALLENGE_CD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_OPEN_WORSHIP_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "Ĥ�ݹ�����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_WORSHIP_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_WORSHIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "Ĥ�ݹ�����δ����";

	static const unsigned int ID_HAVE_DONE = 2;
	static const char* STR_HAVE_DONE = "������Ĥ��";

	static const unsigned int ID_NO_DATA = 3;
	static const char* STR_NO_DATA = "��Ĥ����Ϣ������";

	static const char* STR_NAMESPACE = "ERR_WORSHIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	,STR_HAVE_DONE
	,STR_NO_DATA
	};
}

namespace ERR_LOGOUT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_USERNAME_EMPTY_ERR = 1;
	static const char* STR_USERNAME_EMPTY_ERR = "�û�������Ϊ��";

	static const unsigned int ID_INVALID_CHARACTER = 2;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_UNBIND_ACCOUNT = 3;
	static const char* STR_UNBIND_ACCOUNT = "��δע���˺ţ����ܽ��н�����";

	static const char* STR_NAMESPACE = "ERR_LOGOUT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_USERNAME_EMPTY_ERR
	,STR_INVALID_CHARACTER
	,STR_UNBIND_ACCOUNT
	};
}

namespace ERR_CHANGE_PWD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_CHARACTER = 1;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_USER_PWD_ERR = 2;
	static const char* STR_USER_PWD_ERR = "�û��������";

	static const unsigned int ID_USER_AUTH_TYPE_ERR = 3;
	static const char* STR_USER_AUTH_TYPE_ERR = "�û����ͳ���";

	static const char* STR_NAMESPACE = "ERR_CHANGE_PWD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_CHARACTER
	,STR_USER_PWD_ERR
	,STR_USER_AUTH_TYPE_ERR
	};
}

namespace ERR_UNBIND_DEVICE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_USERNAME_EMPTY_ERR = 1;
	static const char* STR_USERNAME_EMPTY_ERR = "�û�������Ϊ��";

	static const unsigned int ID_INVALID_CHARACTER = 2;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_UNBIND_ACCOUNT = 3;
	static const char* STR_UNBIND_ACCOUNT = "��δע���˺ţ����ܽ��н�����";

	static const char* STR_NAMESPACE = "ERR_UNBIND_DEVICE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_USERNAME_EMPTY_ERR
	,STR_INVALID_CHARACTER
	,STR_UNBIND_ACCOUNT
	};
}

namespace ERR_ACTIVITY_NOTIFY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ACTIVITY_TYPE_NOT_EXIT = 1;
	static const char* STR_ACTIVITY_TYPE_NOT_EXIT = "����Ͳ�����";

	static const unsigned int ID_ACTIVITY_NOT_OPEN = 2;
	static const char* STR_ACTIVITY_NOT_OPEN = "���δ����";

	static const char* STR_NAMESPACE = "ERR_ACTIVITY_NOTIFY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ACTIVITY_TYPE_NOT_EXIT
	,STR_ACTIVITY_NOT_OPEN
	};
}

namespace ERR_OPEN_DOGFECES 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_DOGFECES";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_GET_ACTIVITY_CENTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNLOCK = 1;
	static const char* STR_UNLOCK = "�������δ����";

	static const char* STR_NAMESPACE = "ERR_GET_ACTIVITY_CENTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNLOCK
	};
}

namespace ERR_GET_USERINFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FORBID = 1;
	static const char* STR_FORBID = "���豸������";

	static const char* STR_NAMESPACE = "ERR_GET_USERINFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FORBID
	};
}

namespace ERR_GET_ACTIVITY_ENCOURRAGE_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UPDATE_NEW_VERSION = 1;
	static const char* STR_UPDATE_NEW_VERSION = "������°汾�ͻ���";

	static const char* STR_NAMESPACE = "ERR_GET_ACTIVITY_ENCOURRAGE_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UPDATE_NEW_VERSION
	};
}

namespace ERR_RECV_ACTIVITY_ENCOURRAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BAGFUL = 1;
	static const char* STR_BAGFUL = "��������";

	static const unsigned int ID_ENCOURRAGE_RECVD = 2;
	static const char* STR_ENCOURRAGE_RECVD = "��������ȡ";

	static const unsigned int ID_ACTIVITY_NOT_EXIT = 3;
	static const char* STR_ACTIVITY_NOT_EXIT = "������Ϣ������";

	static const unsigned int ID_ACTIVITY_NEED_CD_KEY = 4;
	static const char* STR_ACTIVITY_NEED_CD_KEY = "��Ҫ����CD_KEY�ſ���ȡ";

	static const unsigned int ID_CD_KEY_NOT_EXIT = 5;
	static const char* STR_CD_KEY_NOT_EXIT = "CD_KEY������";

	static const unsigned int ID_CD_KEY_IS_USERD = 6;
	static const char* STR_CD_KEY_IS_USERD = "CD_KEY�ѱ�ʹ��";

	static const unsigned int ID_HERO_CARRY_FULL = 7;
	static const char* STR_HERO_CARRY_FULL = "�佫Я�������Ѵﵽ����";

	static const unsigned int ID_UPDATE_NEW_VERSION = 8;
	static const char* STR_UPDATE_NEW_VERSION = "������°汾�ͻ���";

	static const char* STR_NAMESPACE = "ERR_RECV_ACTIVITY_ENCOURRAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BAGFUL
	,STR_ENCOURRAGE_RECVD
	,STR_ACTIVITY_NOT_EXIT
	,STR_ACTIVITY_NEED_CD_KEY
	,STR_CD_KEY_NOT_EXIT
	,STR_CD_KEY_IS_USERD
	,STR_HERO_CARRY_FULL
	,STR_UPDATE_NEW_VERSION
	};
}

namespace ERR_OPEN_GEM_MAKER_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_GEM_MAKER_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_RECV_RATING_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SCREEN_NOT_EXIT = 1;
	static const char* STR_SCREEN_NOT_EXIT = "����������";

	static const unsigned int ID_TYPE_NOT_EXIT = 2;
	static const char* STR_TYPE_NOT_EXIT = "�����ڸ�����";

	static const unsigned int ID_CHAPTER_NOT_EXIT = 3;
	static const char* STR_CHAPTER_NOT_EXIT = "�½ڲ�����";

	static const unsigned int ID_RAGING_NOT_ENOUGH = 4;
	static const char* STR_RAGING_NOT_ENOUGH = "������������";

	static const unsigned int ID_ENCOURAGE_RECEVED = 5;
	static const char* STR_ENCOURAGE_RECEVED = "��������ȡ";

	static const unsigned int ID_NOT_THROUGH = 6;
	static const char* STR_NOT_THROUGH = "δȫ��ͨ��";

	static const unsigned int ID_BAGFUL = 7;
	static const char* STR_BAGFUL = "��������";

	static const char* STR_NAMESPACE = "ERR_RECV_RATING_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SCREEN_NOT_EXIT
	,STR_TYPE_NOT_EXIT
	,STR_CHAPTER_NOT_EXIT
	,STR_RAGING_NOT_ENOUGH
	,STR_ENCOURAGE_RECEVED
	,STR_NOT_THROUGH
	,STR_BAGFUL
	};
}

namespace ERR_OPEN_AWAKEN_EXCHANGE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const unsigned int ID_STUDY_EXCHANGE_UNLOCK = 2;
	static const char* STR_STUDY_EXCHANGE_UNLOCK = "����һ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_AWAKEN_EXCHANGE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	,STR_STUDY_EXCHANGE_UNLOCK
	};
}

namespace ERR_EXCHANGE_STUDY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_AWAKEN_UNLOCK = 1;
	static const char* STR_AWAKEN_UNLOCK = "����δ����";

	static const unsigned int ID_NOT_ENOUGH_CLIP = 2;
	static const char* STR_NOT_ENOUGH_CLIP = "Ǭ����Ƭ����";

	static const unsigned int ID_PLAYER_LEVEL_NOT_REACH = 3;
	static const char* STR_PLAYER_LEVEL_NOT_REACH = "δ�ﵽ���Ŷһ��ĵȼ�";

	static const unsigned int ID_STUDY_NOT_EXIST = 4;
	static const char* STR_STUDY_NOT_EXIST = "Ҫ�һ������󲻴���";

	static const unsigned int ID_STUDY_BAG_FULL = 5;
	static const char* STR_STUDY_BAG_FULL = "���󱳰�����";

	static const unsigned int ID_STUDY_EXCHANGE_UNLOCK = 6;
	static const char* STR_STUDY_EXCHANGE_UNLOCK = "����һ�δ����";

	static const char* STR_NAMESPACE = "ERR_EXCHANGE_STUDY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_AWAKEN_UNLOCK
	,STR_NOT_ENOUGH_CLIP
	,STR_PLAYER_LEVEL_NOT_REACH
	,STR_STUDY_NOT_EXIST
	,STR_STUDY_BAG_FULL
	,STR_STUDY_EXCHANGE_UNLOCK
	};
}

namespace ERR_OPEN_EQUIP_COMPOSE_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_EQUIP_COMPOSE_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_EQUIP_COMPOSE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_EQUIP_LEVEL_INVALID = 1;
	static const char* STR_EQUIP_LEVEL_INVALID = "����װ���ȼ���Ч";

	static const unsigned int ID_CLIP_NOT_ENOUGH = 2;
	static const char* STR_CLIP_NOT_ENOUGH = "��Ƭ����";

	static const unsigned int ID_IN_CD = 3;
	static const char* STR_IN_CD = "�ϳ�CD��";

	static const char* STR_NAMESPACE = "ERR_EQUIP_COMPOSE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_EQUIP_LEVEL_INVALID
	,STR_CLIP_NOT_ENOUGH
	,STR_IN_CD
	};
}

namespace ERR_RECV_COMPOSE_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNCOMPOSE = 1;
	static const char* STR_UNCOMPOSE = "��δ�ϳ�װ��";

	static const unsigned int ID_BAG_FULL = 2;
	static const char* STR_BAG_FULL = "��������";

	static const unsigned int ID_EQUIP_LEVEL_INVALID = 3;
	static const char* STR_EQUIP_LEVEL_INVALID = "����װ���ȼ���Ч";

	static const char* STR_NAMESPACE = "ERR_RECV_COMPOSE_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNCOMPOSE
	,STR_BAG_FULL
	,STR_EQUIP_LEVEL_INVALID
	};
}

namespace ERR_OPEN_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_NOT_JOIN_FACTION = 2;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const unsigned int ID_HEAD_INFO_NOT_FIND = 3;
	static const char* STR_HEAD_INFO_NOT_FIND = "�Ҳ���������Ϣ������ϵGM";

	static const char* STR_NAMESPACE = "ERR_OPEN_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NOT_JOIN_FACTION
	,STR_HEAD_INFO_NOT_FIND
	};
}

namespace ERR_APPLY_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_NOT_EXIT_FACTION = 2;
	static const char* STR_NOT_EXIT_FACTION = "�����������ɲ�����";

	static const unsigned int ID_HAVE_FACTION = 3;
	static const char* STR_HAVE_FACTION = "���Ѽ���һ������";

	static const unsigned int ID_HAVE_APPLY_FACTION = 4;
	static const char* STR_HAVE_APPLY_FACTION = "����������������";

	static const unsigned int ID_CAPS_PLAYER_FACTION = 5;
	static const char* STR_CAPS_PLAYER_FACTION = "��Ա�����Ѵﵽ����";

	static const unsigned int ID_TIME_NOT_ENOUGH = 6;
	static const char* STR_TIME_NOT_ENOUGH = "�˳����ɺ�24Сʱ�ڲ��ܼ�������";

	static const unsigned int ID_PLAYER_NOT_EXIST = 7;
	static const char* STR_PLAYER_NOT_EXIST = "��Ҳ�����";

	static const unsigned int ID_APPLY_FACTION_NUM_IS_MAX = 8;
	static const char* STR_APPLY_FACTION_NUM_IS_MAX = "����������ɸ����Ѵ�����";

	static const unsigned int ID_FACTION_PLAYER_IS_MAX = 9;
	static const char* STR_FACTION_PLAYER_IS_MAX = "������������������������������";

	static const unsigned int ID_APPLY_NUM_TOO_MUCH = 10;
	static const char* STR_APPLY_NUM_TOO_MUCH = "�����������������࣬���Ժ�����";

	static const char* STR_NAMESPACE = "ERR_APPLY_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NOT_EXIT_FACTION
	,STR_HAVE_FACTION
	,STR_HAVE_APPLY_FACTION
	,STR_CAPS_PLAYER_FACTION
	,STR_TIME_NOT_ENOUGH
	,STR_PLAYER_NOT_EXIST
	,STR_APPLY_FACTION_NUM_IS_MAX
	,STR_FACTION_PLAYER_IS_MAX
	,STR_APPLY_NUM_TOO_MUCH
	};
}

namespace ERR_CANCEL_APPLY_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_NOT_EXIT_FACTION = 2;
	static const char* STR_NOT_EXIT_FACTION = "�����ɲ�����";

	static const unsigned int ID_NOT_APPLY_FACTION = 3;
	static const char* STR_NOT_APPLY_FACTION = "��δ������������";

	static const char* STR_NAMESPACE = "ERR_CANCEL_APPLY_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NOT_EXIT_FACTION
	,STR_NOT_APPLY_FACTION
	};
}

namespace ERR_KICKED_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 2;
	static const char* STR_PLAYER_NOT_IN_FACTION = "���ɲ�����";

	static const unsigned int ID_NOT_APPLY_FACTION = 3;
	static const char* STR_NOT_APPLY_FACTION = "����Ҳ���������";

	static const unsigned int ID_PLAYER_NOT_AUTHOR = 4;
	static const char* STR_PLAYER_NOT_AUTHOR = "����Ȩ��������߳�����";

	static const unsigned int ID_NOT_EXIT_FACTION = 5;
	static const char* STR_NOT_EXIT_FACTION = "���ɲ�����";

	static const unsigned int ID_PLAYRE_ID_NOT_REAL = 6;
	static const char* STR_PLAYRE_ID_NOT_REAL = "��Ҳ�����";

	static const unsigned int ID_ONLY_KICKED_NORMAL = 7;
	static const char* STR_ONLY_KICKED_NORMAL = "ֻ���߳���ͨ����";

	static const unsigned int ID_ONLY_KICKED_ELITE_AND_NORMAL = 8;
	static const char* STR_ONLY_KICKED_ELITE_AND_NORMAL = "ֻ���߳���Ӣ���Ӻ���ͨ����";

	static const unsigned int ID_IN_GVG_ACTIVITY_CAN_NOT_KICK = 9;
	static const char* STR_IN_GVG_ACTIVITY_CAN_NOT_KICK = "�μ����ɿ��ս�ڼ��޷��߳����";

	static const char* STR_NAMESPACE = "ERR_KICKED_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_IN_FACTION
	,STR_NOT_APPLY_FACTION
	,STR_PLAYER_NOT_AUTHOR
	,STR_NOT_EXIT_FACTION
	,STR_PLAYRE_ID_NOT_REAL
	,STR_ONLY_KICKED_NORMAL
	,STR_ONLY_KICKED_ELITE_AND_NORMAL
	,STR_IN_GVG_ACTIVITY_CAN_NOT_KICK
	};
}

namespace ERR_CREATE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_HAVE_FACTION = 2;
	static const char* STR_PLAYER_HAVE_FACTION = "���Ѽ���򴴽���һ������";

	static const unsigned int ID_COIN_NOT_ENOUGH = 3;
	static const char* STR_COIN_NOT_ENOUGH = "ͭǮ����";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 4;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_FACTION_NAME_SAME = 5;
	static const char* STR_FACTION_NAME_SAME = "�������ѱ�ʹ��";

	static const unsigned int ID_STRING_NOT_ENOUGH = 6;
	static const char* STR_STRING_NOT_ENOUGH = "���������к������дʻ㣬����������";

	static const unsigned int ID_NAME_TOO_LONG = 7;
	static const char* STR_NAME_TOO_LONG = "�������ƹ��������ó���6�����ֻ�12Ӣ���ַ�";

	static const unsigned int ID_TIME_NOT_ENOUGH = 8;
	static const char* STR_TIME_NOT_ENOUGH = "�˳����ɺ�24Сʱ���޷��������ɻ����������������";

	static const unsigned int ID_EMOJI_NOT_USE = 9;
	static const char* STR_EMOJI_NOT_USE = "������ֻ��ʹ�����ġ�Ӣ�ĺ�����";

	static const char* STR_NAMESPACE = "ERR_CREATE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_HAVE_FACTION
	,STR_COIN_NOT_ENOUGH
	,STR_GOLD_NOT_ENOUGH
	,STR_FACTION_NAME_SAME
	,STR_STRING_NOT_ENOUGH
	,STR_NAME_TOO_LONG
	,STR_TIME_NOT_ENOUGH
	,STR_EMOJI_NOT_USE
	};
}

namespace ERR_SEARCH_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_NOT_PLAYER_FACTION_HEAD = 2;
	static const char* STR_NOT_PLAYER_FACTION_HEAD = "�������������ݲ�����";

	static const char* STR_NAMESPACE = "ERR_SEARCH_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NOT_PLAYER_FACTION_HEAD
	};
}

namespace ERR_OPEN_OWNER_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const char* STR_NAMESPACE = "ERR_OPEN_OWNER_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	};
}

namespace ERR_OPEN_DOORS_TRIBUTE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_NOT_FIND_PLAYER = 4;
	static const char* STR_NOT_FIND_PLAYER = "�Ҳ����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_DOORS_TRIBUTE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_NOT_FIND_PLAYER
	};
}

namespace ERR_DOORS_TRIBUTE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_COIN_NOT_ENOUGH = 4;
	static const char* STR_COIN_NOT_ENOUGH = "ͭǮ����";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 5;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_COIN_NOT_TIME = 6;
	static const char* STR_COIN_NOT_TIME = "����ͭǮ���״����ﵽ����";

	static const unsigned int ID_GOLD_NOT_TIME = 7;
	static const char* STR_GOLD_NOT_TIME = "����Ԫ�����״����ﵽ����";

	static const char* STR_NAMESPACE = "ERR_DOORS_TRIBUTE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_COIN_NOT_ENOUGH
	,STR_GOLD_NOT_ENOUGH
	,STR_COIN_NOT_TIME
	,STR_GOLD_NOT_TIME
	};
}

namespace ERR_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_BAG_FULL = 4;
	static const char* STR_BAG_FULL = "��������";

	static const unsigned int ID_CONDITION_NOT_ENOUGH = 5;
	static const char* STR_CONDITION_NOT_ENOUGH = "ͭǮ���״�����δ�ﵽ����";

	static const unsigned int ID_REWARD_IS_GET = 6;
	static const char* STR_REWARD_IS_GET = "����ȡ";

	static const unsigned int ID_GOODS_INFO_EXCEPTION = 7;
	static const char* STR_GOODS_INFO_EXCEPTION = "��Ʒ�����쳣������ϵGM";

	static const unsigned int ID_GET_REWARD_NOT_ENOUGH = 8;
	static const char* STR_GET_REWARD_NOT_ENOUGH = "���Ȱ�ͭǮ����";

	static const char* STR_NAMESPACE = "ERR_RECV_DOORS_TRIBUTE_FACTION_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_BAG_FULL
	,STR_CONDITION_NOT_ENOUGH
	,STR_REWARD_IS_GET
	,STR_GOODS_INFO_EXCEPTION
	,STR_GET_REWARD_NOT_ENOUGH
	};
}

namespace ERR_JOB_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_PLAYER_NOT_AUTHOR = 4;
	static const char* STR_PLAYER_NOT_AUTHOR = "����Ȩ������ְ�뽵ְ";

	static const unsigned int ID_JOIN_PLAYER_NOT_IN_FACTION = 5;
	static const char* STR_JOIN_PLAYER_NOT_IN_FACTION = "����Ҳ���������";

	static const unsigned int ID_JOIN_PLAYER_JOB_LIMIT = 6;
	static const char* STR_JOIN_PLAYER_JOB_LIMIT = "��ְλ�����Ѵ�����";

	static const unsigned int ID_JOB_IS_MAX = 7;
	static const char* STR_JOB_IS_MAX = "����ְ����߼���";

	static const unsigned int ID_JOB_IS_MIN = 8;
	static const char* STR_JOB_IS_MIN = "�ѽ�ְ����ͼ���";

	static const char* STR_NAMESPACE = "ERR_JOB_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_PLAYER_NOT_AUTHOR
	,STR_JOIN_PLAYER_NOT_IN_FACTION
	,STR_JOIN_PLAYER_JOB_LIMIT
	,STR_JOB_IS_MAX
	,STR_JOB_IS_MIN
	};
}

namespace ERR_SET_NOTICE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_PLAYER_NOT_AUTHOR = 4;
	static const char* STR_PLAYER_NOT_AUTHOR = "����Ȩ�޸���������";

	static const unsigned int ID_STRING_NOT_ENOUGH = 5;
	static const char* STR_STRING_NOT_ENOUGH = "�������뺬�����дʻ㣬����������";

	static const char* STR_NAMESPACE = "ERR_SET_NOTICE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_PLAYER_NOT_AUTHOR
	,STR_STRING_NOT_ENOUGH
	};
}

namespace ERR_DISSOLVE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_PLAYER_NOT_AUTHOR = 4;
	static const char* STR_PLAYER_NOT_AUTHOR = "����Ȩ��ɢ����";

	static const unsigned int ID_IN_GVG_ACTIVITY = 5;
	static const char* STR_IN_GVG_ACTIVITY = "��ǰ���ڲμӿ������ս���޷���ɢ����";

	static const char* STR_NAMESPACE = "ERR_DISSOLVE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_PLAYER_NOT_AUTHOR
	,STR_IN_GVG_ACTIVITY
	};
}

namespace ERR_OPEN_AUDIT_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_PLAYER_NOT_AUTHOR = 4;
	static const char* STR_PLAYER_NOT_AUTHOR = "����Ȩ�鿴��˽���";

	static const char* STR_NAMESPACE = "ERR_OPEN_AUDIT_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_PLAYER_NOT_AUTHOR
	};
}

namespace ERR_AUDIT_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const unsigned int ID_PLAYER_NOT_IN_FACTION = 3;
	static const char* STR_PLAYER_NOT_IN_FACTION = "�㲻�Ǹ����ɳ�Ա";

	static const unsigned int ID_PLAYER_NOT_AUTHOR = 4;
	static const char* STR_PLAYER_NOT_AUTHOR = "����Ȩ�������߽������";

	static const unsigned int ID_PLAYER_NUM_IS_MAX = 5;
	static const char* STR_PLAYER_NUM_IS_MAX = "������ɳ�Ա�����Ѵﵽ����";

	static const unsigned int ID_AUDIT_NUM_IS_MAX = 6;
	static const char* STR_AUDIT_NUM_IS_MAX = "������������Ѵ����ޣ�����������";

	static const unsigned int ID_ALREADY_AUDIT_OTHER = 7;
	static const char* STR_ALREADY_AUDIT_OTHER = "������Ѽ����������ɣ���Ϊ��ˢ�����ݣ����������";

	static const unsigned int ID_MULTI_ALREADY_AUDIT_OTHER = 8;
	static const char* STR_MULTI_ALREADY_AUDIT_OTHER = "��ѡ����������Ѽ����������ɣ���Ϊ��ˢ�����ݣ����������";

	static const unsigned int ID_ALREAD_CANCEL_APPLY = 9;
	static const char* STR_ALREAD_CANCEL_APPLY = "�������ȡ��������뱾���ɣ���Ϊ��ˢ�����ݣ����������";

	static const unsigned int ID_MULTI_ALREAD_CANCEL_APPLY = 10;
	static const char* STR_MULTI_ALREAD_CANCEL_APPLY = "��ѡ�����������ȡ��������뱾���ɣ���Ϊ��ˢ�����ݣ����������";

	static const char* STR_NAMESPACE = "ERR_AUDIT_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	,STR_PLAYER_NOT_IN_FACTION
	,STR_PLAYER_NOT_AUTHOR
	,STR_PLAYER_NUM_IS_MAX
	,STR_AUDIT_NUM_IS_MAX
	,STR_ALREADY_AUDIT_OTHER
	,STR_MULTI_ALREADY_AUDIT_OTHER
	,STR_ALREAD_CANCEL_APPLY
	,STR_MULTI_ALREAD_CANCEL_APPLY
	};
}

namespace ERR_OPEN_LOG_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const unsigned int ID_PLAYER_NOT_HAVE_FACTION = 2;
	static const char* STR_PLAYER_NOT_HAVE_FACTION = "��û�м�������";

	static const char* STR_NAMESPACE = "ERR_OPEN_LOG_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_PLAYER_NOT_HAVE_FACTION
	};
}

namespace ERR_OPEN_APPLY_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const char* STR_NAMESPACE = "ERR_OPEN_APPLY_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_RANK_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��δ��������ϵͳ";

	static const char* STR_NAMESPACE = "ERR_OPEN_RANK_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_GATHER_SCIENCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_GATHER_SCIENCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_GATHER_SCIENCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_VIP_NOT_LEVEL = 1;
	static const char* STR_VIP_NOT_LEVEL = "VIP�ȼ�������������VIP�ȼ�";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 2;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_COIN_NOT_ENOUGH = 3;
	static const char* STR_COIN_NOT_ENOUGH = "ͭǮ����";

	static const char* STR_NAMESPACE = "ERR_GATHER_SCIENCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_VIP_NOT_LEVEL
	,STR_GOLD_NOT_ENOUGH
	,STR_COIN_NOT_ENOUGH
	};
}

namespace ERR_BIND_MOBILE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HAVE_BIND_MOBILE = 1;
	static const char* STR_HAVE_BIND_MOBILE = "�Ѱ󶨹��ֻ���";

	static const unsigned int ID_SEND_FAILD = 2;
	static const char* STR_SEND_FAILD = "���Ͷ���ʧ��";

	static const unsigned int ID_MOBILECHF = 3;
	static const char* STR_MOBILECHF = "�Ƿ��ֻ���";

	static const unsigned int ID_MOBILE_HAVE_BIND = 4;
	static const char* STR_MOBILE_HAVE_BIND = "�ú����ѱ���";

	static const char* STR_NAMESPACE = "ERR_BIND_MOBILE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HAVE_BIND_MOBILE
	,STR_SEND_FAILD
	,STR_MOBILECHF
	,STR_MOBILE_HAVE_BIND
	};
}

namespace ERR_BIND_CHECK_VER_CODE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_VER_CODE_FAILD = 1;
	static const char* STR_VER_CODE_FAILD = "��֤ʧ��";

	static const char* STR_NAMESPACE = "ERR_BIND_CHECK_VER_CODE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_VER_CODE_FAILD
	};
}

namespace ERR_UNBIND_MOBILE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HAVE_UNBIND_MOBILE = 1;
	static const char* STR_HAVE_UNBIND_MOBILE = "��δ���ֻ���";

	static const unsigned int ID_SEND_FAILD = 2;
	static const char* STR_SEND_FAILD = "���Ͷ���ʧ��";

	static const char* STR_NAMESPACE = "ERR_UNBIND_MOBILE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HAVE_UNBIND_MOBILE
	,STR_SEND_FAILD
	};
}

namespace ERR_UNBIND_CHECK_VER_CODE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_VER_CODE_FAILD = 1;
	static const char* STR_VER_CODE_FAILD = "��֤ʧ��";

	static const char* STR_NAMESPACE = "ERR_UNBIND_CHECK_VER_CODE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_VER_CODE_FAILD
	};
}

namespace ERR_RESET_PASSWD_MOBILE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HAVE_NOT_BIND = 1;
	static const char* STR_HAVE_NOT_BIND = "��δ���˺�";

	static const unsigned int ID_SEND_FAILD = 2;
	static const char* STR_SEND_FAILD = "���Ͷ���ʧ��";

	static const unsigned int ID_MOBILECHF = 3;
	static const char* STR_MOBILECHF = "�Ƿ��ֻ���";

	static const char* STR_NAMESPACE = "ERR_RESET_PASSWD_MOBILE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HAVE_NOT_BIND
	,STR_SEND_FAILD
	,STR_MOBILECHF
	};
}

namespace ERR_RESET_PASSWD_CHECK_VER_CODE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_VER_CODE_FAILD = 1;
	static const char* STR_VER_CODE_FAILD = "��֤ʧ��";

	static const char* STR_NAMESPACE = "ERR_RESET_PASSWD_CHECK_VER_CODE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_VER_CODE_FAILD
	};
}

namespace ERR_RESET_PASSWD_NEWPASSWD_CODE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_CHARACTER = 1;
	static const char* STR_INVALID_CHARACTER = "��Ч�ַ�";

	static const unsigned int ID_UNAUTH = 2;
	static const char* STR_UNAUTH = "δ��֤";

	static const char* STR_NAMESPACE = "ERR_RESET_PASSWD_NEWPASSWD_CODE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_CHARACTER
	,STR_UNAUTH
	};
}

namespace ERR_GET_USER_EXPAND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_GET_USER_EXPAND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_BLUE_PAVILION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_BUILD_NOT_EXIST = 1;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const char* STR_NAMESPACE = "ERR_OPEN_BLUE_PAVILION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BUILD_NOT_EXIST
	};
}

namespace ERR_BEGBLUE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_CURR_BEGBLUE_USEUP = 1;
	static const char* STR_CURR_BEGBLUE_USEUP = "��ǰ����¶����������";

	static const unsigned int ID_BUILD_NOT_EXIST = 2;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const char* STR_NAMESPACE = "ERR_BEGBLUE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_CURR_BEGBLUE_USEUP
	,STR_BUILD_NOT_EXIST
	};
}

namespace ERR_IMPROVE_LUCK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_BEGBLUE_RES = 1;
	static const char* STR_NO_BEGBLUE_RES = "����ȷ����ȡ������ʹ���������";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 2;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_BUILD_NOT_EXIST = 3;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const char* STR_NAMESPACE = "ERR_IMPROVE_LUCK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_BEGBLUE_RES
	,STR_GOLD_NOT_ENOUGH
	,STR_BUILD_NOT_EXIST
	};
}

namespace ERR_COMFIRM_BEGBLUE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_TO_COMFIRM_BEGBLUE = 1;
	static const char* STR_NO_TO_COMFIRM_BEGBLUE = "���ѳɹ���ȡ��¶";

	static const unsigned int ID_BUILD_NOT_EXIST = 2;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const char* STR_NAMESPACE = "ERR_COMFIRM_BEGBLUE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_TO_COMFIRM_BEGBLUE
	,STR_BUILD_NOT_EXIST
	};
}

namespace ERR_GET_BLUE_ENCOURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_SMILE_NUM = 1;
	static const char* STR_NO_SMILE_NUM = "Ц����������";

	static const unsigned int ID_BUILD_NOT_EXIST = 2;
	static const char* STR_BUILD_NOT_EXIST = "����������";

	static const unsigned int ID_NO_BLUE = 3;
	static const char* STR_NO_BLUE = "���տ���ȡЦ�������Ѿ�����";

	static const char* STR_NAMESPACE = "ERR_GET_BLUE_ENCOURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_SMILE_NUM
	,STR_BUILD_NOT_EXIST
	,STR_NO_BLUE
	};
}

namespace ERR_GET_OPENLIGHT_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_EQUIP_NOT_EXIST = 1;
	static const char* STR_EQUIP_NOT_EXIST = "װ��������";

	static const unsigned int ID_EQUIP_HAS_OPENLIGHT = 2;
	static const char* STR_EQUIP_HAS_OPENLIGHT = "װ���ѽ���";

	static const unsigned int ID_EQUIP_CAN_NOT_OPENLIGHT = 3;
	static const char* STR_EQUIP_CAN_NOT_OPENLIGHT = "װ�����ɽ���";

	static const char* STR_NAMESPACE = "ERR_GET_OPENLIGHT_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_EQUIP_NOT_EXIST
	,STR_EQUIP_HAS_OPENLIGHT
	,STR_EQUIP_CAN_NOT_OPENLIGHT
	};
}

namespace ERR_OPENLIGHT_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_EQUIP_NOT_EXIST = 1;
	static const char* STR_EQUIP_NOT_EXIST = "װ��������";

	static const unsigned int ID_EQUIP_HAS_OPENLIGHT = 2;
	static const char* STR_EQUIP_HAS_OPENLIGHT = "װ���ѽ���";

	static const unsigned int ID_EQUIP_CAN_NOT_OPENLIGHT = 3;
	static const char* STR_EQUIP_CAN_NOT_OPENLIGHT = "װ�����ɽ���";

	static const unsigned int ID_OPENLIGHT_STONE_NOT_ENOUGH = 4;
	static const char* STR_OPENLIGHT_STONE_NOT_ENOUGH = "����ʯ����";

	static const unsigned int ID_OPENLIGHT_RATE_NOT_HIT = 5;
	static const char* STR_OPENLIGHT_RATE_NOT_HIT = "����ʧ��";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 6;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const char* STR_NAMESPACE = "ERR_OPENLIGHT_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_EQUIP_NOT_EXIST
	,STR_EQUIP_HAS_OPENLIGHT
	,STR_EQUIP_CAN_NOT_OPENLIGHT
	,STR_OPENLIGHT_STONE_NOT_ENOUGH
	,STR_OPENLIGHT_RATE_NOT_HIT
	,STR_GOLD_NOT_ENOUGH
	};
}

namespace ERR_CHANGE_CAREER_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_CAREERID_NOT_EXIST = 1;
	static const char* STR_CAREERID_NOT_EXIST = "ְҵ������";

	static const char* STR_NAMESPACE = "ERR_CHANGE_CAREER_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_CAREERID_NOT_EXIST
	};
}

namespace ERR_CHALLENGE_MYSELF_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_CAREERID_NOT_EXIST = 1;
	static const char* STR_CAREERID_NOT_EXIST = "ְҵ������";

	static const char* STR_NAMESPACE = "ERR_CHALLENGE_MYSELF_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_CAREERID_NOT_EXIST
	};
}

namespace ERR_GET_FRIEND_SYS_PLAYER_LIST 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_PAGE_CAPACITY = 1;
	static const char* STR_INVALID_PAGE_CAPACITY = "��Ч�ķ�ҳ����";

	static const unsigned int ID_NO_LIST_DATA = 2;
	static const char* STR_NO_LIST_DATA = "���������";

	static const unsigned int ID_NO_OPEN = 3;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_GET_FRIEND_SYS_PLAYER_LIST";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_PAGE_CAPACITY
	,STR_NO_LIST_DATA
	,STR_NO_OPEN
	};
}

namespace ERR_DEL_FRIEND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SELF_INFO_LOST = 1;
	static const char* STR_SELF_INFO_LOST = "������Ϣ��ʧ";

	static const unsigned int ID_FRIEND_INFO_LOST = 2;
	static const char* STR_FRIEND_INFO_LOST = "�Է���Ϣ��ʧ";

	static const unsigned int ID_REF_PLAYER_NOT_YOUR_FRIEND = 3;
	static const char* STR_REF_PLAYER_NOT_YOUR_FRIEND = "�Է��Ѳ����������";

	static const unsigned int ID_NO_OPEN = 4;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_DEL_FRIEND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SELF_INFO_LOST
	,STR_FRIEND_INFO_LOST
	,STR_REF_PLAYER_NOT_YOUR_FRIEND
	,STR_NO_OPEN
	};
}

namespace ERR_SEARCH_PLAYER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_REF_DATA = 1;
	static const char* STR_NO_REF_DATA = "�Ҳ���������";

	static const unsigned int ID_INVALID_PAGE_CAPACITY = 2;
	static const char* STR_INVALID_PAGE_CAPACITY = "��Ч�ķ�ҳ����";

	static const unsigned int ID_NO_OPEN = 3;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_SEARCH_PLAYER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_REF_DATA
	,STR_INVALID_PAGE_CAPACITY
	,STR_NO_OPEN
	};
}

namespace ERR_VIEW_PLAYER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_REF_DATA = 1;
	static const char* STR_NO_REF_DATA = "���������";

	static const unsigned int ID_NO_OPEN = 2;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_VIEW_PLAYER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_REF_DATA
	,STR_NO_OPEN
	};
}

namespace ERR_ADD_FRIEND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SELF_INFO_LOST = 1;
	static const char* STR_SELF_INFO_LOST = "������Ϣ��ʧ";

	static const unsigned int ID_FRIEND_NUM_TO_UPPERLIMIT = 2;
	static const char* STR_FRIEND_NUM_TO_UPPERLIMIT = "��ĺ����Ѵ�����200��";

	static const unsigned int ID_REF_PLAYER_INFO_LOST = 3;
	static const char* STR_REF_PLAYER_INFO_LOST = "�Է���Ϣ��ʧ";

	static const unsigned int ID_YOU_ARE_IN_REF_PLAYER_BLACKLIST = 4;
	static const char* STR_YOU_ARE_IN_REF_PLAYER_BLACKLIST = "�Է��Ѱ������������";

	static const unsigned int ID_REF_PLAYER_IN_YOUR_BLACKLIST = 5;
	static const char* STR_REF_PLAYER_IN_YOUR_BLACKLIST = "���ѰѶԷ����������";

	static const unsigned int ID_REF_PLAYER_HAS_BEEN_YOUR_FRIEND = 6;
	static const char* STR_REF_PLAYER_HAS_BEEN_YOUR_FRIEND = "�Է�������ĺ���";

	static const unsigned int ID_REF_MYSELF = 7;
	static const char* STR_REF_MYSELF = "���ܼ��Լ�Ϊ����";

	static const unsigned int ID_NO_OPEN = 8;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const unsigned int ID_TARGET_NO_OPEN = 9;
	static const char* STR_TARGET_NO_OPEN = "�Է����ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_ADD_FRIEND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SELF_INFO_LOST
	,STR_FRIEND_NUM_TO_UPPERLIMIT
	,STR_REF_PLAYER_INFO_LOST
	,STR_YOU_ARE_IN_REF_PLAYER_BLACKLIST
	,STR_REF_PLAYER_IN_YOUR_BLACKLIST
	,STR_REF_PLAYER_HAS_BEEN_YOUR_FRIEND
	,STR_REF_MYSELF
	,STR_NO_OPEN
	,STR_TARGET_NO_OPEN
	};
}

namespace ERR_OPEN_SEND_FLOWER_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SEND_FLOWER_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_SEND_FLOWER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_SEND_FLOWER_NUM = 1;
	static const char* STR_INVALID_SEND_FLOWER_NUM = "��Ч���ͻ����";

	static const unsigned int ID_SEND_CHANCE_USEUP = 2;
	static const char* STR_SEND_CHANCE_USEUP = "�ͻ�����������";

	static const unsigned int ID_NO_OPEN = 3;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const unsigned int ID_OTHER_NOT_FRIEND = 4;
	static const char* STR_OTHER_NOT_FRIEND = "����һ���������ѣ��޷�����";

	static const unsigned int ID_BAG_NOT_EXIT = 5;
	static const char* STR_BAG_NOT_EXIT = "������Ʒ������";

	static const unsigned int ID_ITEM_TYPE_ERR = 6;
	static const char* STR_ITEM_TYPE_ERR = "���Ͳ�֧��";

	static const unsigned int ID_BAG_FULL = 7;
	static const char* STR_BAG_FULL = "��������";

	static const unsigned int ID_OTHER_NOT_OPEN_FRIENDS = 8;
	static const char* STR_OTHER_NOT_OPEN_FRIENDS = "�Է�δ���ź��ѹ��ܣ��޷�����";

	static const unsigned int ID_OTHER_RECV_FLOWER_FULL = 9;
	static const char* STR_OTHER_RECV_FLOWER_FULL = "�Է��ջ������������޷����ͣ����Ժ����͡�";

	static const unsigned int ID_YOU_NOT_OTHER_FRIEND = 10;
	static const char* STR_YOU_NOT_OTHER_FRIEND = "�㲻�ǶԷ����ѣ��޷�����";

	static const char* STR_NAMESPACE = "ERR_SEND_FLOWER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_SEND_FLOWER_NUM
	,STR_SEND_CHANCE_USEUP
	,STR_NO_OPEN
	,STR_OTHER_NOT_FRIEND
	,STR_BAG_NOT_EXIT
	,STR_ITEM_TYPE_ERR
	,STR_BAG_FULL
	,STR_OTHER_NOT_OPEN_FRIENDS
	,STR_OTHER_RECV_FLOWER_FULL
	,STR_YOU_NOT_OTHER_FRIEND
	};
}

namespace ERR_OPEN_SEND_FLOWER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_SEND_FLOWER_NUM = 1;
	static const char* STR_INVALID_SEND_FLOWER_NUM = "��Ч���ͻ����";

	static const unsigned int ID_SEND_CHANCE_USEUP = 2;
	static const char* STR_SEND_CHANCE_USEUP = "�ͻ�����������";

	static const unsigned int ID_NO_OPEN = 3;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const unsigned int ID_OTHER_NOT_FRIEND = 4;
	static const char* STR_OTHER_NOT_FRIEND = "����һ���������ѣ��޷�����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SEND_FLOWER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_SEND_FLOWER_NUM
	,STR_SEND_CHANCE_USEUP
	,STR_NO_OPEN
	,STR_OTHER_NOT_FRIEND
	};
}

namespace ERR_GET_FLOWER_BY_PLAYERID 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_GET_FLOWER_BY_PLAYERID";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_GET_FLOWER_RANKING 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_GET_FLOWER_RANKING";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_GET_PRIVATE_MSG_LOG_LIST 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_INVALID_REQ_PARAM = 1;
	static const char* STR_INVALID_REQ_PARAM = "�Ƿ����������";

	static const unsigned int ID_NO_REF_DATA = 2;
	static const char* STR_NO_REF_DATA = "���������";

	static const unsigned int ID_NO_OPEN = 3;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_GET_PRIVATE_MSG_LOG_LIST";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_INVALID_REQ_PARAM
	,STR_NO_REF_DATA
	,STR_NO_OPEN
	};
}

namespace ERR_SEND_PRIVATE_MSG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_YOU_ARE_IN_REF_PLAYER_BLACKLIST = 1;
	static const char* STR_YOU_ARE_IN_REF_PLAYER_BLACKLIST = "����ʧ�ܣ��Է��Ѱ������������";

	static const unsigned int ID_SELF_INFO_LOST = 2;
	static const char* STR_SELF_INFO_LOST = "������Ϣ��ʧ";

	static const unsigned int ID_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST = 3;
	static const char* STR_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST = "����ʧ�ܣ����ѰѶԷ����������";

	static const unsigned int ID_NO_OPEN = 4;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const unsigned int ID_VERIFY_ERROR = 5;
	static const char* STR_VERIFY_ERROR = "���зǷ����δ�";

	static const char* STR_NAMESPACE = "ERR_SEND_PRIVATE_MSG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_YOU_ARE_IN_REF_PLAYER_BLACKLIST
	,STR_SELF_INFO_LOST
	,STR_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST
	,STR_NO_OPEN
	,STR_VERIFY_ERROR
	};
}

namespace ERR_DEL_PRIVATE_MSG_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_DEL_PRIVATE_MSG_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_ADD_TO_BLACKLIST 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SELF_INFO_LOST = 1;
	static const char* STR_SELF_INFO_LOST = "������Ϣ��ʧ";

	static const unsigned int ID_BLACKLIST_NUM_TO_UPPERLIMIT = 2;
	static const char* STR_BLACKLIST_NUM_TO_UPPERLIMIT = "��ĺ����Ѵ�����200��";

	static const unsigned int ID_REF_PLAYER_INFO_LOST = 3;
	static const char* STR_REF_PLAYER_INFO_LOST = "�Է���Ϣ��ʧ";

	static const unsigned int ID_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST = 4;
	static const char* STR_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST = "�Է�������ĺ�����";

	static const unsigned int ID_NO_OPEN = 5;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const unsigned int ID_NOT_JOIN_BLACK_SELF = 6;
	static const char* STR_NOT_JOIN_BLACK_SELF = "�޷����Լ����������";

	static const char* STR_NAMESPACE = "ERR_ADD_TO_BLACKLIST";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SELF_INFO_LOST
	,STR_BLACKLIST_NUM_TO_UPPERLIMIT
	,STR_REF_PLAYER_INFO_LOST
	,STR_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST
	,STR_NO_OPEN
	,STR_NOT_JOIN_BLACK_SELF
	};
}

namespace ERR_MOVE_FROM_BLACKLIST 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SELF_INFO_LOST = 1;
	static const char* STR_SELF_INFO_LOST = "������Ϣ��ʧ";

	static const unsigned int ID_REF_PLAYER_INFO_LOST = 2;
	static const char* STR_REF_PLAYER_INFO_LOST = "�Է���Ϣ��ʧ";

	static const unsigned int ID_REF_PLAYER_NOT_YOUR_FRIEND = 3;
	static const char* STR_REF_PLAYER_NOT_YOUR_FRIEND = "�Է��Ѳ������������";

	static const unsigned int ID_NO_OPEN = 4;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_MOVE_FROM_BLACKLIST";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SELF_INFO_LOST
	,STR_REF_PLAYER_INFO_LOST
	,STR_REF_PLAYER_NOT_YOUR_FRIEND
	,STR_NO_OPEN
	};
}

namespace ERR_GET_SEND_OFFLINE_MSG_PLAYER_LIST 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_GET_SEND_OFFLINE_MSG_PLAYER_LIST";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_READ_OFFLINE_MSG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_READ_OFFLINE_MSG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_OPEN_RAREITEMROOM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RAREITEM_ROOM_NOT_EXIST = 1;
	static const char* STR_RAREITEM_ROOM_NOT_EXIST = "��Ʒ����δ����";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "��û�м�������";

	static const unsigned int ID_IS_UNOPEN = 3;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_RAREITEMROOM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RAREITEM_ROOM_NOT_EXIST
	,STR_FACTION_NOT_EXIST
	,STR_IS_UNOPEN
	};
}

namespace ERR_BUY_RAREITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_RAREITEM_ROOM_NOT_EXIST = 1;
	static const char* STR_RAREITEM_ROOM_NOT_EXIST = "��Ʒ����δ����";

	static const unsigned int ID_DOORSTRIBUTE_NOT_ENOUGH = 2;
	static const char* STR_DOORSTRIBUTE_NOT_ENOUGH = "ʣ���Ź�����";

	static const unsigned int ID_SUMDOORSTRIBUTE_NOT_ENOUGH = 3;
	static const char* STR_SUMDOORSTRIBUTE_NOT_ENOUGH = "�ۼ��Ź�����";

	static const unsigned int ID_EXCHANGE_TIMES_NOT_ENOUGH = 4;
	static const char* STR_EXCHANGE_TIMES_NOT_ENOUGH = "�����ո���Ʒ�����������, �������ٳ���";

	static const unsigned int ID_KINDID_INVALID = 5;
	static const char* STR_KINDID_INVALID = "��Ч����ƷID";

	static const unsigned int ID_BAG_FULL = 6;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_NOT_JOIN_FACTION = 7;
	static const char* STR_NOT_JOIN_FACTION = "��û�м�������";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 8;
	static const char* STR_LEVEL_NOT_ENOUGH = "�㻹δ�ﵽ����Ʒ�Ĺ���ȼ�";

	static const unsigned int ID_UNOPEN = 9;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_BUY_RAREITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_RAREITEM_ROOM_NOT_EXIST
	,STR_DOORSTRIBUTE_NOT_ENOUGH
	,STR_SUMDOORSTRIBUTE_NOT_ENOUGH
	,STR_EXCHANGE_TIMES_NOT_ENOUGH
	,STR_KINDID_INVALID
	,STR_BAG_FULL
	,STR_NOT_JOIN_FACTION
	,STR_LEVEL_NOT_ENOUGH
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_UPGRADERAREITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 1;
	static const char* STR_LIMIT_NOT_ENOUGH = "����Ȩ������Ʒ��";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_RAREITEM_LEVEL_IS_MAX = 3;
	static const char* STR_RAREITEM_LEVEL_IS_MAX = "��Ʒ���ȼ��Ѵ�����";

	static const unsigned int ID_RAREITEM_NOT_EXIST = 4;
	static const char* STR_RAREITEM_NOT_EXIST = "��Ʒ����δ����";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_UPGRADERAREITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_LIMIT_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_RAREITEM_LEVEL_IS_MAX
	,STR_RAREITEM_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_UPGRADE_RAREITEM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 1;
	static const char* STR_LIMIT_NOT_ENOUGH = "����Ȩ������Ʒ��";

	static const unsigned int ID_UNITED_GRADE_NOT_ENOUGH = 2;
	static const char* STR_UNITED_GRADE_NOT_ENOUGH = "���ɵȼ�����";

	static const unsigned int ID_UNITED_FUNDS_NOT_ENOUGH = 3;
	static const char* STR_UNITED_FUNDS_NOT_ENOUGH = "�����ʽ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 4;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_RAREITEM_NOT_EXIST = 5;
	static const char* STR_RAREITEM_NOT_EXIST = "��Ʒ����δ����";

	static const unsigned int ID_FACTION_LEVEL_IS_MAX = 6;
	static const char* STR_FACTION_LEVEL_IS_MAX = "��Ʒ���ȼ��Ѵ�����";

	static const unsigned int ID_UNOPEN = 7;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_RAREITEM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_LIMIT_NOT_ENOUGH
	,STR_UNITED_GRADE_NOT_ENOUGH
	,STR_UNITED_FUNDS_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_RAREITEM_NOT_EXIST
	,STR_FACTION_LEVEL_IS_MAX
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_GYMNASIUM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GYMNASIUM_NOT_EXIST = 1;
	static const char* STR_GYMNASIUM_NOT_EXIST = "���û�δ����";

	static const unsigned int ID_FACTION_NOT_EXITS = 2;
	static const char* STR_FACTION_NOT_EXITS = "�����ɲ�����";

	static const unsigned int ID_UNOPEN = 3;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_GYMNASIUM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GYMNASIUM_NOT_EXIST
	,STR_FACTION_NOT_EXITS
	,STR_UNOPEN
	};
}

namespace ERR_LEARN_GYMNASIUM_SKILL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_DOORSTRIBUTE_NOT_ENOUGH = 1;
	static const char* STR_DOORSTRIBUTE_NOT_ENOUGH = "�Ź�����";

	static const unsigned int ID_GYMNASIUM_LEVEL_NOT_ENOUGH = 2;
	static const char* STR_GYMNASIUM_LEVEL_NOT_ENOUGH = "������������";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_IS_FULL_LEVEL = 4;
	static const char* STR_IS_FULL_LEVEL = "����������";

	static const unsigned int ID_SKILL_NOT_EXIST = 5;
	static const char* STR_SKILL_NOT_EXIST = "���ܲ�����";

	static const unsigned int ID_GYMNASIUM_NOT_EXIST = 6;
	static const char* STR_GYMNASIUM_NOT_EXIST = "���û�δ����";

	static const unsigned int ID_SKILL_NOT_UNLOCK = 7;
	static const char* STR_SKILL_NOT_UNLOCK = "����δ����";

	static const unsigned int ID_PLAYERID_NOT_FIND = 8;
	static const char* STR_PLAYERID_NOT_FIND = "�Ҳ����������";

	static const unsigned int ID_UNOPEN = 9;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_SUM_DOORSTRINUTE_NOT_ENOUGH = 10;
	static const char* STR_SUM_DOORSTRINUTE_NOT_ENOUGH = "����ۼ��Ź�δ�ﵽҪ���޷�ѧϰ�ü���";

	static const char* STR_NAMESPACE = "ERR_LEARN_GYMNASIUM_SKILL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_DOORSTRIBUTE_NOT_ENOUGH
	,STR_GYMNASIUM_LEVEL_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_IS_FULL_LEVEL
	,STR_SKILL_NOT_EXIST
	,STR_GYMNASIUM_NOT_EXIST
	,STR_SKILL_NOT_UNLOCK
	,STR_PLAYERID_NOT_FIND
	,STR_UNOPEN
	,STR_SUM_DOORSTRINUTE_NOT_ENOUGH
	};
}

namespace ERR_OPEN_GYMNASIUM_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GYMNASIUM_LEVEL_IS_FULL = 1;
	static const char* STR_GYMNASIUM_LEVEL_IS_FULL = "���õȼ��Ѵ�����";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 3;
	static const char* STR_LIMIT_NOT_ENOUGH = "����Ȩ��������";

	static const unsigned int ID_GYMNASIUM_NOT_EXIST = 4;
	static const char* STR_GYMNASIUM_NOT_EXIST = "���û�δ����";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_GYMNASIUM_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GYMNASIUM_LEVEL_IS_FULL
	,STR_FACTION_NOT_EXIST
	,STR_LIMIT_NOT_ENOUGH
	,STR_GYMNASIUM_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_GYMNASIUM_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_LEVEL_NOT_ENOUGH = 1;
	static const char* STR_FACTION_LEVEL_NOT_ENOUGH = "���ɵȼ�����";

	static const unsigned int ID_FACTION_FUNDS_NOT_ENOUGH = 2;
	static const char* STR_FACTION_FUNDS_NOT_ENOUGH = "�����ʽ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 4;
	static const char* STR_LIMIT_NOT_ENOUGH = "����Ȩ��������";

	static const unsigned int ID_GYMNASIUM_LEVEL_IS_FULL = 5;
	static const char* STR_GYMNASIUM_LEVEL_IS_FULL = "���õȼ��Ѵ�����";

	static const unsigned int ID_GYMNASIUM_NOT_EXIST = 6;
	static const char* STR_GYMNASIUM_NOT_EXIST = "���û�δ����";

	static const unsigned int ID_UNOPEN = 7;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_GYMNASIUM_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_LEVEL_NOT_ENOUGH
	,STR_FACTION_FUNDS_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_LIMIT_NOT_ENOUGH
	,STR_GYMNASIUM_LEVEL_IS_FULL
	,STR_GYMNASIUM_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_SHADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_SHADE_NOT_EXIST = 2;
	static const char* STR_SHADE_NOT_EXIST = "����δ����";

	static const unsigned int ID_UNOPEN = 3;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SHADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_SHADE_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_SHADE_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 1;
	static const char* STR_LIMIT_NOT_ENOUGH = "����Ȩ��������";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_SHADE_LEVEL_IS_FULL = 3;
	static const char* STR_SHADE_LEVEL_IS_FULL = "�����ȼ��Ѵ�����";

	static const unsigned int ID_SHADE_NOT_EXIST = 4;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_SHADE_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_LIMIT_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_SHADE_LEVEL_IS_FULL
	,STR_SHADE_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_SHADE_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_LEVEL_NOT_ENOUGH = 1;
	static const char* STR_FACTION_LEVEL_NOT_ENOUGH = "���ɵȼ�����";

	static const unsigned int ID_FACTION_FUNDS_NOT_ENOUGH = 2;
	static const char* STR_FACTION_FUNDS_NOT_ENOUGH = "�����ʽ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 4;
	static const char* STR_LIMIT_NOT_ENOUGH = "����Ȩ��������";

	static const unsigned int ID_SHADE_LEVEL_IS_FULL = 5;
	static const char* STR_SHADE_LEVEL_IS_FULL = "�����ȼ��Ѵ�����";

	static const unsigned int ID_ACTIVI_NOT_UPGRADE = 6;
	static const char* STR_ACTIVI_NOT_UPGRADE = "׽����ڼ䣬������������";

	static const unsigned int ID_SHADE_NOT_OPEN = 7;
	static const char* STR_SHADE_NOT_OPEN = "������δ����";

	static const unsigned int ID_UNOPEN = 8;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_SHADE_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_LEVEL_NOT_ENOUGH
	,STR_FACTION_FUNDS_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_LIMIT_NOT_ENOUGH
	,STR_SHADE_LEVEL_IS_FULL
	,STR_ACTIVI_NOT_UPGRADE
	,STR_SHADE_NOT_OPEN
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_GOLDMODE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 1;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_STATE_IS_OPEN = 2;
	static const char* STR_STATE_IS_OPEN = "���������ѿ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_VIP_LEVEL_NOT_ENOUGH = 4;
	static const char* STR_VIP_LEVEL_NOT_ENOUGH = "VIP�ȼ�����";

	static const unsigned int ID_TIME_NOT_ENOUGH = 5;
	static const char* STR_TIME_NOT_ENOUGH = "��ǰ��׽������ʱ��";

	static const unsigned int ID_SHADE_NOT_EXIST = 6;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_UNOPEN = 7;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_HUNTING_NUM_NOT_ENOUGH = 8;
	static const char* STR_HUNTING_NUM_NOT_ENOUGH = "׽���������㣬�޷�ʹ�ø�������";

	static const char* STR_NAMESPACE = "ERR_OPEN_GOLDMODE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GOLD_NOT_ENOUGH
	,STR_STATE_IS_OPEN
	,STR_FACTION_NOT_EXIST
	,STR_VIP_LEVEL_NOT_ENOUGH
	,STR_TIME_NOT_ENOUGH
	,STR_SHADE_NOT_EXIST
	,STR_UNOPEN
	,STR_HUNTING_NUM_NOT_ENOUGH
	};
}

namespace ERR_OPEN_HUNTING 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_NOT_OPEN_HUNTING = 2;
	static const char* STR_NOT_OPEN_HUNTING = "������û��׽������";

	static const unsigned int ID_TIME_NOT_ENOUGH = 3;
	static const char* STR_TIME_NOT_ENOUGH = "��ǰ��׽������ʱ��";

	static const unsigned int ID_SHADE_NOT_EXIST = 4;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_HUNTING";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_NOT_OPEN_HUNTING
	,STR_TIME_NOT_ENOUGH
	,STR_SHADE_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_FIND_MONSTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 2;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_VIP_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_VIP_LEVEL_NOT_ENOUGH = "VIP�ȼ�����";

	static const unsigned int ID_MONSTER_IS_EXIST = 4;
	static const char* STR_MONSTER_IS_EXIST = "��ǰ��������";

	static const unsigned int ID_NOT_FIND_MONSTER_NUM = 5;
	static const char* STR_NOT_FIND_MONSTER_NUM = "û��׽������";

	static const unsigned int ID_IS_MAX_MONSTER = 6;
	static const char* STR_IS_MAX_MONSTER = "��ǰ�������Ʒ������";

	static const unsigned int ID_SHADE_NOT_EXIST = 7;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_TIME_NOT_ENOUGH = 8;
	static const char* STR_TIME_NOT_ENOUGH = "��ǰ��׽������ʱ��";

	static const unsigned int ID_UNOPEN = 9;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_HUNTING_NUM_NOT_ENOUGH_FIND = 10;
	static const char* STR_HUNTING_NUM_NOT_ENOUGH_FIND = "׽���������㣬�޷�ʹ��ǧ����";

	static const unsigned int ID_HUNTING_NUM_NOT_ENOUGH_CHANGE = 11;
	static const char* STR_HUNTING_NUM_NOT_ENOUGH_CHANGE = "׽���������㣬�޷�ʹ�û�һֻ";

	static const char* STR_NAMESPACE = "ERR_FIND_MONSTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_GOLD_NOT_ENOUGH
	,STR_VIP_LEVEL_NOT_ENOUGH
	,STR_MONSTER_IS_EXIST
	,STR_NOT_FIND_MONSTER_NUM
	,STR_IS_MAX_MONSTER
	,STR_SHADE_NOT_EXIST
	,STR_TIME_NOT_ENOUGH
	,STR_UNOPEN
	,STR_HUNTING_NUM_NOT_ENOUGH_FIND
	,STR_HUNTING_NUM_NOT_ENOUGH_CHANGE
	};
}

namespace ERR_HUNTING_BATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_MONSTER_NOT_EXIST = 1;
	static const char* STR_MONSTER_NOT_EXIST = "�����ֲ�����";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_SHADE_NOT_EXIST = 3;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_TIME_NOT_ENOUGH = 4;
	static const char* STR_TIME_NOT_ENOUGH = "��ǰ��׽������ʱ��";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_HUNTING_BATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_MONSTER_NOT_EXIST
	,STR_FACTION_NOT_EXIST
	,STR_SHADE_NOT_EXIST
	,STR_TIME_NOT_ENOUGH
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_HOT_SPRING 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 2;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_PLAYER_ID_NOT_FIND = 3;
	static const char* STR_PLAYER_ID_NOT_FIND = "��������쳣";

	static const unsigned int ID_UNOPEN = 4;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_HOT_SPRING";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_HOT_SPRING_NOT_EXIST
	,STR_PLAYER_ID_NOT_FIND
	,STR_UNOPEN
	};
}

namespace ERR_SELECT_WINE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_WINE_IS_DRINKING = 1;
	static const char* STR_WINE_IS_DRINKING = "���������ܷ�����";

	static const unsigned int ID_COIN_NOT_ENOUGH = 2;
	static const char* STR_COIN_NOT_ENOUGH = "ͭǮ����";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 3;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_VIP_LEVEL_NOT_ENOUGH = 4;
	static const char* STR_VIP_LEVEL_NOT_ENOUGH = "VIP�ȼ�����";

	static const unsigned int ID_WINE_NOT_EXIST = 5;
	static const char* STR_WINE_NOT_EXIST = "���񲻴���";

	static const unsigned int ID_FACTION_NOT_EXIST = 6;
	static const char* STR_FACTION_NOT_EXIST = "δ��������";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 7;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_PLAYER_ID_NOT_FIND = 8;
	static const char* STR_PLAYER_ID_NOT_FIND = "��������쳣";

	static const unsigned int ID_UNOPEN = 9;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_ALREAD_DRINK = 10;
	static const char* STR_ALREAD_DRINK = "�������ʹ�ù���Ȫ���񣬻�ӭ��������";

	static const char* STR_NAMESPACE = "ERR_SELECT_WINE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_WINE_IS_DRINKING
	,STR_COIN_NOT_ENOUGH
	,STR_GOLD_NOT_ENOUGH
	,STR_VIP_LEVEL_NOT_ENOUGH
	,STR_WINE_NOT_EXIST
	,STR_FACTION_NOT_EXIST
	,STR_HOT_SPRING_NOT_EXIST
	,STR_PLAYER_ID_NOT_FIND
	,STR_UNOPEN
	,STR_ALREAD_DRINK
	};
}

namespace ERR_DRINK_WINE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_WINE_NOT_EXIST = 1;
	static const char* STR_WINE_NOT_EXIST = "���񲻴���";

	static const unsigned int ID_IS_EMPTY = 2;
	static const char* STR_IS_EMPTY = "�����ѽ���";

	static const unsigned int ID_TIME_NOT_ENOUGH = 3;
	static const char* STR_TIME_NOT_ENOUGH = "�㻹�����ܷ���";

	static const unsigned int ID_WINE_IS_BAD = 4;
	static const char* STR_WINE_IS_BAD = "��ѡ�ķ����ѳ���ʱ��";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_DRINK_WINE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_WINE_NOT_EXIST
	,STR_IS_EMPTY
	,STR_TIME_NOT_ENOUGH
	,STR_WINE_IS_BAD
	,STR_UNOPEN
	};
}

namespace ERR_DRINK_WINE_MOVE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 1;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_UNOPEN = 2;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_DRINK_WINE_MOVE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HOT_SPRING_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_CHANGE_OTHER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_MARTIAL_HEAD = 1;
	static const char* STR_NOT_MARTIAL_HEAD = "�㲻������";

	static const unsigned int ID_POSITION_NOT_ENOUGH = 2;
	static const char* STR_POSITION_NOT_ENOUGH = "ֻ�ܽ�����֮λ�������ϻ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_PEOPLE_NOT_EXIST = 4;
	static const char* STR_PEOPLE_NOT_EXIST = "��Ҳ�����";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_CHANGE_OTHER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_MARTIAL_HEAD
	,STR_POSITION_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_PEOPLE_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_GIVE_WINE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 1;
	static const char* STR_LIMIT_NOT_ENOUGH = "ֻ�г�������ְλ���ܿ�������ʱ��";

	static const unsigned int ID_NOT_ACTIVI_TIME = 2;
	static const char* STR_NOT_ACTIVI_TIME = "���տ������������꣬����������";

	static const unsigned int ID_GIVE_WINE_IS_OPEN = 3;
	static const char* STR_GIVE_WINE_IS_OPEN = "����ʱ���ѿ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 4;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_TIME_NOT_ENOUGH = 5;
	static const char* STR_TIME_NOT_ENOUGH = "���ܶ��������";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 6;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_UNOPEN = 7;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_GIVE_WINE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_LIMIT_NOT_ENOUGH
	,STR_NOT_ACTIVI_TIME
	,STR_GIVE_WINE_IS_OPEN
	,STR_FACTION_NOT_EXIST
	,STR_TIME_NOT_ENOUGH
	,STR_HOT_SPRING_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_CLICK_SELECT_WINE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_WINE_IS_DRINKING = 1;
	static const char* STR_WINE_IS_DRINKING = "���������ܷ�����";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "��δ��������";

	static const unsigned int ID_NOW_CAN_NOT_SELECT = 3;
	static const char* STR_NOW_CAN_NOT_SELECT = "����ʱ���ڼ��޷��һ��ϴη������";

	static const unsigned int ID_NOT_FIND_DRINK = 4;
	static const char* STR_NOT_FIND_DRINK = "�������һ��ϴη�����������";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 5;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_UNOPEN = 6;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_CLICK_SELECT_WINE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_WINE_IS_DRINKING
	,STR_FACTION_NOT_EXIST
	,STR_NOW_CAN_NOT_SELECT
	,STR_NOT_FIND_DRINK
	,STR_HOT_SPRING_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_SURE_GIVE_WINE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ACTIVITY_TIME_NOT_ENOUGH = 1;
	static const char* STR_ACTIVITY_TIME_NOT_ENOUGH = "���ڻʱ����";

	static const unsigned int ID_GIVE_WINE_NOT_TIMES = 2;
	static const char* STR_GIVE_WINE_NOT_TIMES = "��������ʱ��Ĵ���������";

	static const unsigned int ID_FACTION_FUNDS_NOT_ENOUGH = 3;
	static const char* STR_FACTION_FUNDS_NOT_ENOUGH = "�����ʽ���";

	static const unsigned int ID_FACTION_NOT_EXIST = 4;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_GIVE_WINE_IS_OPEN = 5;
	static const char* STR_GIVE_WINE_IS_OPEN = "����ʱ���ѿ���";

	static const unsigned int ID_CD_TIME_NOT_ENOUGH = 6;
	static const char* STR_CD_TIME_NOT_ENOUGH = "���ܶ��������";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 7;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_UNOPEN = 8;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_SURE_GIVE_WINE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ACTIVITY_TIME_NOT_ENOUGH
	,STR_GIVE_WINE_NOT_TIMES
	,STR_FACTION_FUNDS_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_GIVE_WINE_IS_OPEN
	,STR_CD_TIME_NOT_ENOUGH
	,STR_HOT_SPRING_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_CLOSED_MONSTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 1;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_MONSTER_NOT_EXIST = 2;
	static const char* STR_MONSTER_NOT_EXIST = "�����ֲ�����";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_SHADE_NOT_EXIST = 4;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_CLOSED_MONSTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_GOLD_NOT_ENOUGH
	,STR_MONSTER_NOT_EXIST
	,STR_FACTION_NOT_EXIST
	,STR_SHADE_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_LEAVE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_HEAD_NOT_LEAVE = 2;
	static const char* STR_HEAD_NOT_LEAVE = "���ų�Ա��������1�ˣ��޷���ɢ����";

	static const unsigned int ID_UNOPEN = 3;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_IN_GVG_ACTIVITY = 4;
	static const char* STR_IN_GVG_ACTIVITY = "��ǰ���ڲμӿ������ս���޷���ɢ����";

	static const unsigned int ID_IN_GVG_ACTIVITY_CAN_NOT_LEAVE = 5;
	static const char* STR_IN_GVG_ACTIVITY_CAN_NOT_LEAVE = "�����ɵ�ǰ���ڲμӿ������ս���޷��뿪����";

	static const char* STR_NAMESPACE = "ERR_LEAVE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_HEAD_NOT_LEAVE
	,STR_UNOPEN
	,STR_IN_GVG_ACTIVITY
	,STR_IN_GVG_ACTIVITY_CAN_NOT_LEAVE
	};
}

namespace ERR_OPEN_LEAVE_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_HEAD_NOT_LEAVE = 2;
	static const char* STR_HEAD_NOT_LEAVE = "���ų�Ա��������1�ˣ������޷��˳�����";

	static const unsigned int ID_UNOPEN = 3;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_LEAVE_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_HEAD_NOT_LEAVE
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_FACTION_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_FULL_LEVEL = 1;
	static const char* STR_IS_FULL_LEVEL = "����������";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_UPGRADE_LIMIT_NOT_ENOUGH = 3;
	static const char* STR_UPGRADE_LIMIT_NOT_ENOUGH = "ֻ�����Ų�����������";

	static const unsigned int ID_UNOPEN = 4;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FACTION_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_FULL_LEVEL
	,STR_FACTION_NOT_EXIST
	,STR_UPGRADE_LIMIT_NOT_ENOUGH
	,STR_UNOPEN
	};
}

namespace ERR_FACTION_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_UPGRADE_LIMIT_NOT_ENOUGH = 2;
	static const char* STR_UPGRADE_LIMIT_NOT_ENOUGH = "ֻ�����Ų�����������";

	static const unsigned int ID_FACTION_FUNDS_NOT_ENOUGH = 3;
	static const char* STR_FACTION_FUNDS_NOT_ENOUGH = "�����ʽ𲻹�";

	static const unsigned int ID_FACTION_LEVEL_IS_FULL = 4;
	static const char* STR_FACTION_LEVEL_IS_FULL = "����������";

	static const unsigned int ID_UNOPEN = 5;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_FACTION_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_UPGRADE_LIMIT_NOT_ENOUGH
	,STR_FACTION_FUNDS_NOT_ENOUGH
	,STR_FACTION_LEVEL_IS_FULL
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_EQUIP_MASTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_EQUIP_MASTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_ACTIVATE_MASTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const unsigned int ID_MEDAL_NOT_ENOUGH = 2;
	static const char* STR_MEDAL_NOT_ENOUGH = "����ѫ�²���";

	static const unsigned int ID_PLAYER_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_PLAYER_LEVEL_NOT_ENOUGH = "��ҵȼ�����";

	static const char* STR_NAMESPACE = "ERR_ACTIVATE_MASTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_MEDAL_NOT_ENOUGH
	,STR_PLAYER_LEVEL_NOT_ENOUGH
	};
}

namespace ERR_BREAK_MASTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const unsigned int ID_MEDAL_NOT_ENOUGH = 2;
	static const char* STR_MEDAL_NOT_ENOUGH = "����ѫ�²���";

	static const unsigned int ID_PLAYER_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_PLAYER_LEVEL_NOT_ENOUGH = "��ҵȼ�����";

	static const char* STR_NAMESPACE = "ERR_BREAK_MASTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_MEDAL_NOT_ENOUGH
	,STR_PLAYER_LEVEL_NOT_ENOUGH
	};
}

namespace ERR_GET_MASTER_BOOK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const unsigned int ID_NOT_ACTIVATE_ALL = 2;
	static const char* STR_NOT_ACTIVATE_ALL = "�㻹ûȫ�����ȫ�������ſ�������";

	static const unsigned int ID_MEDAL_NOT_ENOUGH = 3;
	static const char* STR_MEDAL_NOT_ENOUGH = "����ѫ�²���";

	static const unsigned int ID_MASTER_MAX = 4;
	static const char* STR_MASTER_MAX = "��ľ�ͨ�����Ѿ��Ƿ��켫��������������";

	static const unsigned int ID_UPGRADE_MASTER_PLEASE = 5;
	static const char* STR_UPGRADE_MASTER_PLEASE = "�㻹ûͻ�ƣ�����ͻ��������";

	static const char* STR_NAMESPACE = "ERR_GET_MASTER_BOOK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NOT_ACTIVATE_ALL
	,STR_MEDAL_NOT_ENOUGH
	,STR_MASTER_MAX
	,STR_UPGRADE_MASTER_PLEASE
	};
}

namespace ERR_WIPE_MASTER_BOOK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const char* STR_NAMESPACE = "ERR_WIPE_MASTER_BOOK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_MASTER_CHEAT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const unsigned int ID_CHEAT_UNOPEN = 2;
	static const char* STR_CHEAT_UNOPEN = "�ȼ����㣬��ǧδ����";

	static const unsigned int ID_GOLD_NOT_ENOUGH = 3;
	static const char* STR_GOLD_NOT_ENOUGH = "Ԫ������";

	static const unsigned int ID_NOT_NEED_TO_CHEAT = 4;
	static const char* STR_NOT_NEED_TO_CHEAT = "��֮ͨ�鶼�Ѵﵽ��߼�������Ҫ��ǧ";

	static const char* STR_NAMESPACE = "ERR_MASTER_CHEAT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_CHEAT_UNOPEN
	,STR_GOLD_NOT_ENOUGH
	,STR_NOT_NEED_TO_CHEAT
	};
}

namespace ERR_CONFIRM_MASTER_BOOK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "װ����ͨδ����";

	static const char* STR_NAMESPACE = "ERR_CONFIRM_MASTER_BOOK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_BAD_REWARD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_WINE_NOT_BAD = 1;
	static const char* STR_WINE_NOT_BAD = "��δ����";

	static const unsigned int ID_FACTION_NOT_EXIST = 2;
	static const char* STR_FACTION_NOT_EXIST = "��δ��������";

	static const unsigned int ID_WINE_NOT_EXIST = 3;
	static const char* STR_WINE_NOT_EXIST = "�Ʋ�����";

	static const char* STR_NAMESPACE = "ERR_OPEN_BAD_REWARD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_WINE_NOT_BAD
	,STR_FACTION_NOT_EXIST
	,STR_WINE_NOT_EXIST
	};
}

namespace ERR_GET_BAD_REWARD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_WINE_NOT_BAD = 1;
	static const char* STR_WINE_NOT_BAD = "��δ����";

	static const unsigned int ID_COIN_NOT_ENOUGH = 2;
	static const char* STR_COIN_NOT_ENOUGH = "ͭǮ����";

	static const unsigned int ID_FACTION_NOT_EXIST = 3;
	static const char* STR_FACTION_NOT_EXIST = "��δ��������";

	static const unsigned int ID_WINT_NOT_EXIST = 4;
	static const char* STR_WINT_NOT_EXIST = "�Ʋ�����";

	static const char* STR_NAMESPACE = "ERR_GET_BAD_REWARD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_WINE_NOT_BAD
	,STR_COIN_NOT_ENOUGH
	,STR_FACTION_NOT_EXIST
	,STR_WINT_NOT_EXIST
	};
}

namespace ERR_OPEN_COURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_GROUP = 2;
	static const char* STR_NO_GROUP = "û�к��ʵĶ���";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_COURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_GROUP
	,STR_LOCK
	};
}

namespace ERR_COURAGE_OPEN_CREATE_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const char* STR_NAMESPACE = "ERR_COURAGE_OPEN_CREATE_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_COURAGE_CREATE_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_TIMES = 2;
	static const char* STR_NO_TIMES = "�����������������꣬���ܴ�������";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_MAX_GROUP = 4;
	static const char* STR_MAX_GROUP = "�����Ѵ�������������鴴��ʧ��";

	static const unsigned int ID_NO_HERO = 5;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_FACTION = 6;
	static const char* STR_NO_FACTION = "����û�м�����ɣ����ܴ������ɶ���";

	static const unsigned int ID_NO_SCENE = 7;
	static const char* STR_NO_SCENE = "���س�������";

	static const unsigned int ID_NO_LEVEL = 8;
	static const char* STR_NO_LEVEL = "���ܴ������Լ��ȼ��ߵĸ���";

	static const char* STR_NAMESPACE = "ERR_COURAGE_CREATE_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_TIMES
	,STR_LOCK
	,STR_MAX_GROUP
	,STR_NO_HERO
	,STR_NO_FACTION
	,STR_NO_SCENE
	,STR_NO_LEVEL
	};
}

namespace ERR_COURAGE_BATTLE_ENTER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_ENOUGH_LEVEL = 2;
	static const char* STR_NO_ENOUGH_LEVEL = "�ȼ���δ�ﵽ���������";

	static const unsigned int ID_HAS_FULL = 3;
	static const char* STR_HAS_FULL = "��̫���˶����Ѿ�������";

	static const unsigned int ID_NO_GROUP = 4;
	static const char* STR_NO_GROUP = "��ѡ��Ķ��鱻��ɢ��";

	static const unsigned int ID_LOCK = 5;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 6;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_RIGHT_GROUP = 7;
	static const char* STR_NO_RIGHT_GROUP = "û�к��ʵĶ��飬����һ����";

	static const unsigned int ID_NO_HELP_TIMES = 8;
	static const char* STR_NO_HELP_TIMES = "�����տ�Э�������Ѿ�����";

	static const unsigned int ID_NO_HELP_TIMES_NOON = 9;
	static const char* STR_NO_HELP_TIMES_NOON = "���ʱ�ε�Э�������Ѵ�����";

	static const unsigned int ID_NO_HELP_TIMES_NIGHT = 10;
	static const char* STR_NO_HELP_TIMES_NIGHT = "���ʱ�ε�Э�������Ѵ�����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_BATTLE_ENTER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_ENOUGH_LEVEL
	,STR_HAS_FULL
	,STR_NO_GROUP
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_RIGHT_GROUP
	,STR_NO_HELP_TIMES
	,STR_NO_HELP_TIMES_NOON
	,STR_NO_HELP_TIMES_NIGHT
	};
}

namespace ERR_COURAGE_RANDOM_JOIN_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_ENOUGH_LEVEL = 2;
	static const char* STR_NO_ENOUGH_LEVEL = "�ȼ���δ�ﵽ���������";

	static const unsigned int ID_HAS_FULL = 3;
	static const char* STR_HAS_FULL = "��̫���˶����Ѿ�������";

	static const unsigned int ID_NO_GROUP = 4;
	static const char* STR_NO_GROUP = "��ѡ��Ķ��鱻��ɢ��";

	static const unsigned int ID_LOCK = 5;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 6;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_RIGHT_GROUP = 7;
	static const char* STR_NO_RIGHT_GROUP = "û�к��ʵĶ��飬����һ����";

	static const unsigned int ID_NO_HELP_TIMES = 8;
	static const char* STR_NO_HELP_TIMES = "�����տ�Э�������Ѿ�����";

	static const unsigned int ID_NO_HELP_TIMES_NOON = 9;
	static const char* STR_NO_HELP_TIMES_NOON = "���ʱ�ε�Э�������Ѵ�����";

	static const unsigned int ID_NO_HELP_TIMES_NIGHT = 10;
	static const char* STR_NO_HELP_TIMES_NIGHT = "���ʱ�ε�Э�������Ѵ�����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_RANDOM_JOIN_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_ENOUGH_LEVEL
	,STR_HAS_FULL
	,STR_NO_GROUP
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_RIGHT_GROUP
	,STR_NO_HELP_TIMES
	,STR_NO_HELP_TIMES_NOON
	,STR_NO_HELP_TIMES_NIGHT
	};
}

namespace ERR_COURAGE_OPERATE_HERO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_HAS_REANY = 3;
	static const char* STR_HAS_REANY = "׼�����ܽ��д˲���";

	static const unsigned int ID_LOCK = 4;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 5;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_IN_GROUP = 6;
	static const char* STR_NO_IN_GROUP = "��δ������鲻�ܽ��д˲���";

	static const char* STR_NAMESPACE = "ERR_COURAGE_OPERATE_HERO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_HAS_REANY
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_IN_GROUP
	};
}

namespace ERR_COURAGE_CONFIRM_HERO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_HAS_REANY = 3;
	static const char* STR_HAS_REANY = "׼�����ܽ��д˲���";

	static const unsigned int ID_NO_HERO_INFO = 4;
	static const char* STR_NO_HERO_INFO = "�佫��Ϣ������";

	static const unsigned int ID_LOCK = 5;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 6;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_IN_GROUP = 7;
	static const char* STR_NO_IN_GROUP = "��δ������鲻�ܽ��д˲���";

	static const char* STR_NAMESPACE = "ERR_COURAGE_CONFIRM_HERO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_HAS_REANY
	,STR_NO_HERO_INFO
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_IN_GROUP
	};
}

namespace ERR_COURAGE_FIRE_GROUP_MEMBER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_HAS_REANY = 3;
	static const char* STR_HAS_REANY = "׼�����ܽ��д˲���";

	static const unsigned int ID_NO_GROUP = 4;
	static const char* STR_NO_GROUP = "��δ������鲻�ܽ��д˲���";

	static const unsigned int ID_NO_POWER = 5;
	static const char* STR_NO_POWER = "û��Ȩ��";

	static const unsigned int ID_NO_PLAYER = 6;
	static const char* STR_NO_PLAYER = "���������ˣ������Լ�����";

	static const unsigned int ID_NO_MYSELF = 7;
	static const char* STR_NO_MYSELF = "�������Լ�";

	static const unsigned int ID_LOCK = 8;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_FIRE_GROUP_MEMBER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_HAS_REANY
	,STR_NO_GROUP
	,STR_NO_POWER
	,STR_NO_PLAYER
	,STR_NO_MYSELF
	,STR_LOCK
	};
}

namespace ERR_COURAGE_PLAYER_READY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_NO_GROUP = 3;
	static const char* STR_NO_GROUP = "��δ������鲻�ܽ��д˲���";

	static const unsigned int ID_LOCK = 4;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 5;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const char* STR_NAMESPACE = "ERR_COURAGE_PLAYER_READY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_NO_GROUP
	,STR_LOCK
	,STR_NO_HERO
	};
}

namespace ERR_COURAGE_PLAYER_START 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_NO_GROUP = 3;
	static const char* STR_NO_GROUP = "��δ������鲻�ܽ��д˲���";

	static const unsigned int ID_NO_ALL_READY = 4;
	static const char* STR_NO_ALL_READY = "���ж�Աδ׼�������ܿ�ʼ��Ϸ";

	static const unsigned int ID_NO_POWER = 5;
	static const char* STR_NO_POWER = "ֻ�жӳ����ܿ�ʼ��ϷŶ";

	static const unsigned int ID_LOCK = 6;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 7;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_FULL = 8;
	static const char* STR_NO_FULL = "�����������ܿ�ʼ��ϷŶ";

	static const char* STR_NAMESPACE = "ERR_COURAGE_PLAYER_START";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_NO_GROUP
	,STR_NO_ALL_READY
	,STR_NO_POWER
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_FULL
	};
}

namespace ERR_COURAGE_BUY_PRACTISE_TIMES 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_MAX_BUY_TIMES = 2;
	static const char* STR_MAX_BUY_TIMES = "�������տɹ���Ĵ���";

	static const unsigned int ID_NO_GOLD = 3;
	static const char* STR_NO_GOLD = "Ԫ������";

	static const unsigned int ID_LOCK = 4;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_BUY_PRACTISE_TIMES";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_MAX_BUY_TIMES
	,STR_NO_GOLD
	,STR_LOCK
	};
}

namespace ERR_COURAGE_LEAVE_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_NO_GROUP = 3;
	static const char* STR_NO_GROUP = "û�к��ʵĶ���";

	static const unsigned int ID_LOCK = 4;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_LEAVE_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_NO_GROUP
	,STR_LOCK
	};
}

namespace ERR_COURAGE_BATTLE_LEAVE_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_BATTLEING = 2;
	static const char* STR_BATTLEING = "ս��״̬���ܽ��д˲���";

	static const unsigned int ID_NO_GROUP = 3;
	static const char* STR_NO_GROUP = "û�к��ʵĶ���";

	static const unsigned int ID_LOCK = 4;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_BATTLE_LEAVE_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_BATTLEING
	,STR_NO_GROUP
	,STR_LOCK
	};
}

namespace ERR_OPEN_COURAGE_SHOP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_MAX_BUY_TIMES = 2;
	static const char* STR_MAX_BUY_TIMES = "�������տɹ���Ĵ���";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_COURAGE_SHOP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_MAX_BUY_TIMES
	,STR_LOCK
	};
}

namespace ERR_COURAGE_RCV_READY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_MAX_BUY_TIMES = 2;
	static const char* STR_MAX_BUY_TIMES = "�������տɹ���Ĵ���";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_RCV_READY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_MAX_BUY_TIMES
	,STR_LOCK
	};
}

namespace ERR_COURAGE_RCV_REFRESH 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_MAX_BUY_TIMES = 2;
	static const char* STR_MAX_BUY_TIMES = "�������տɹ���Ĵ���";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_RCV_REFRESH";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_MAX_BUY_TIMES
	,STR_LOCK
	};
}

namespace ERR_PLAYER_FACTION_READ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_PLAYER_FACTION_READ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_FIND_DRINK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "δ��������";

	static const unsigned int ID_NOT_FIND_BACK_DRINK = 2;
	static const char* STR_NOT_FIND_BACK_DRINK = "�������һ��ϴη�����������";

	static const unsigned int ID_NOT_FIND_BACK_IN_GIVE_WINE = 3;
	static const char* STR_NOT_FIND_BACK_IN_GIVE_WINE = "����ʱ���ڼ��޷��һ��ϴη������";

	static const unsigned int ID_HAVE_A_WINE = 4;
	static const char* STR_HAVE_A_WINE = "���������ܷ�����";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 5;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_UNOPEN = 6;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FIND_DRINK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_NOT_FIND_BACK_DRINK
	,STR_NOT_FIND_BACK_IN_GIVE_WINE
	,STR_HAVE_A_WINE
	,STR_HOT_SPRING_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_OPEN_FACTION_BUILD_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "��δ��������";

	static const unsigned int ID_UNOPEN = 2;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FACTION_BUILD_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_COURAGE_PLAYER_FIRED 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ӳ��߳�����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_PLAYER_FIRED";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_COURAGE_GROUP_DISMISS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "���鱻�ӳ���ɢ��";

	static const char* STR_NAMESPACE = "ERR_COURAGE_GROUP_DISMISS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_COURAGE_GROUP_REFRESH 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "ˢ�³ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_GROUP = 2;
	static const char* STR_NO_GROUP = "û�����������Ķ���";

	static const char* STR_NAMESPACE = "ERR_COURAGE_GROUP_REFRESH";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_GROUP
	};
}

namespace ERR_FACTION_PLAYER_CHANGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_EXIST = 1;
	static const char* STR_FACTION_NOT_EXIST = "�����ɲ�����";

	static const unsigned int ID_UNOPEN = 2;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_FACTION_PLAYER_CHANGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_EXIST
	,STR_UNOPEN
	};
}

namespace ERR_COURAGE_ENTER_GROUP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_GROUP = 2;
	static const char* STR_NO_GROUP = "���鱻�ӳ���ɢ��";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 4;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const char* STR_NAMESPACE = "ERR_COURAGE_ENTER_GROUP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_GROUP
	,STR_LOCK
	,STR_NO_HERO
	};
}

namespace ERR_LEAVE_COURAGE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_LOCK = 2;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_LEAVE_COURAGE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_LOCK
	};
}

namespace ERR_HOT_SPRING_OVER_REWARD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HOT_SPRING_NOT_EXIST = 1;
	static const char* STR_HOT_SPRING_NOT_EXIST = "��Ȫ��δ����";

	static const unsigned int ID_NOT_OVER_REWARD = 2;
	static const char* STR_NOT_OVER_REWARD = "û�й��ڽ���";

	static const unsigned int ID_UNOPEN = 3;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_HOT_SPRING_OVER_REWARD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HOT_SPRING_NOT_EXIST
	,STR_NOT_OVER_REWARD
	,STR_UNOPEN
	};
}

namespace ERR_HUNTING_ITEGRAL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_SHADE_NOT_EXIST = 1;
	static const char* STR_SHADE_NOT_EXIST = "������δ����";

	static const unsigned int ID_TIME_NOT_ENOUGH = 2;
	static const char* STR_TIME_NOT_ENOUGH = "��ǰ��׽������ʱ��";

	static const unsigned int ID_UNOPEN = 3;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_HUNTING_ITEGRAL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_SHADE_NOT_EXIST
	,STR_TIME_NOT_ENOUGH
	,STR_UNOPEN
	};
}

namespace ERR_PROMPT_IGNORE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_OPEN = 1;
	static const char* STR_FACTION_NOT_OPEN = "���ɻ�δ����";

	static const unsigned int ID_UNOPEN = 2;
	static const char* STR_UNOPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_PROMPT_IGNORE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_OPEN
	,STR_UNOPEN
	};
}

namespace ERR_COURAGE_BATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FAILED = 1;
	static const char* STR_FAILED = "ս��ʧ��";

	static const unsigned int ID_UNOPEN = 2;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_GROUP = 3;
	static const char* STR_NO_GROUP = "��δ������鲻�ܽ��д˲���";

	static const unsigned int ID_LOCK = 4;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 5;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_BATTLE = 6;
	static const char* STR_NO_BATTLE = "ս��δ��ʼ";

	static const char* STR_NAMESPACE = "ERR_COURAGE_BATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FAILED
	,STR_UNOPEN
	,STR_NO_GROUP
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_BATTLE
	};
}

namespace ERR_OPEN_LEAVE_HOT_SPRING 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_LEAVE_HOT_SPRING";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_COURAGE_GET_AWARD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HAVEGETAWARD = 1;
	static const char* STR_HAVEGETAWARD = "������ȡ������";

	static const unsigned int ID_LOCK = 2;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_BAG_FULL = 3;
	static const char* STR_BAG_FULL = "��������";

	static const char* STR_NAMESPACE = "ERR_COURAGE_GET_AWARD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HAVEGETAWARD
	,STR_LOCK
	,STR_BAG_FULL
	};
}

namespace ERR_COURAGE_ENTER_BATTLE_SCENE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "��ǰ������ˣ���ȴ��´ΰ�";

	static const unsigned int ID_NO_GROUP = 2;
	static const char* STR_NO_GROUP = "��δ������鲻�ܽ��д˲���";

	static const unsigned int ID_LOCK = 3;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const unsigned int ID_NO_HERO = 4;
	static const char* STR_NO_HERO = "������Я��һ�����μӻ";

	static const unsigned int ID_NO_BATTLE = 5;
	static const char* STR_NO_BATTLE = "ս��δ��ʼ";

	static const char* STR_NAMESPACE = "ERR_COURAGE_ENTER_BATTLE_SCENE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_NO_GROUP
	,STR_LOCK
	,STR_NO_HERO
	,STR_NO_BATTLE
	};
}

namespace ERR_COURAGE_GET_BATTLE_RESULT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HAVEGETAWARD = 1;
	static const char* STR_HAVEGETAWARD = "������ȡ������";

	static const unsigned int ID_LOCK = 2;
	static const char* STR_LOCK = "�����������ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_COURAGE_GET_BATTLE_RESULT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HAVEGETAWARD
	,STR_LOCK
	};
}

namespace ERR_UPGRADE_CROP_FIELD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FIELD_NOT_EXIT = 1;
	static const char* STR_FIELD_NOT_EXIT = "�ؿ鲻����";

	static const unsigned int ID_FIELD_IS_MAX = 2;
	static const char* STR_FIELD_IS_MAX = "�Ѿ�������߼���";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_LEVEL_NOT_ENOUGH = "���ǵȼ�����";

	static const unsigned int ID_CROP_IS_NOT_OPEN = 4;
	static const char* STR_CROP_IS_NOT_OPEN = "ũ��δ����";

	static const unsigned int ID_CROP_IS_NOT_GOLD = 5;
	static const char* STR_CROP_IS_NOT_GOLD = "��Ҳ��㣬��������";

	static const unsigned int ID_CROP_IS_NOT_VIP = 6;
	static const char* STR_CROP_IS_NOT_VIP = "VIP�ȼ���������������";

	static const unsigned int ID_FIELD_HAVE_CROP = 7;
	static const char* STR_FIELD_HAVE_CROP = "�ؿ�����ֵ������������";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_CROP_FIELD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FIELD_NOT_EXIT
	,STR_FIELD_IS_MAX
	,STR_LEVEL_NOT_ENOUGH
	,STR_CROP_IS_NOT_OPEN
	,STR_CROP_IS_NOT_GOLD
	,STR_CROP_IS_NOT_VIP
	,STR_FIELD_HAVE_CROP
	};
}

namespace ERR_OPEN_RESOLVE_ORANGE_AWAKEN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "�ֽ⹦�ܻ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_RESOLVE_ORANGE_AWAKEN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	};
}

namespace ERR_RESOLVE_ORANGE_AWAKEN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "�ֽ⹦�ܻ�δ����";

	static const unsigned int ID_ID_INVALID = 2;
	static const char* STR_ID_INVALID = "����ʶ��";

	static const unsigned int ID_ITEM_NUM_NOT_ENOUGH = 3;
	static const char* STR_ITEM_NUM_NOT_ENOUGH = "������������";

	static const unsigned int ID_NOT_HAVE_AWAKEN = 4;
	static const char* STR_NOT_HAVE_AWAKEN = "������û�д�����";

	static const unsigned int ID_ITEM_ID_INVALID = 5;
	static const char* STR_ITEM_ID_INVALID = "������Ϣ�쳣������ϵ�ͷ�";

	static const unsigned int ID_IS_NOT_ORANGE_STUDY = 6;
	static const char* STR_IS_NOT_ORANGE_STUDY = "���ǻ�ɫ�����ֽܷ�";

	static const char* STR_NAMESPACE = "ERR_RESOLVE_ORANGE_AWAKEN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_ID_INVALID
	,STR_ITEM_NUM_NOT_ENOUGH
	,STR_NOT_HAVE_AWAKEN
	,STR_ITEM_ID_INVALID
	,STR_IS_NOT_ORANGE_STUDY
	};
}

namespace ERR_OPEN_RESOLVE_TRIGRAM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "�ֽ⹦�ܻ�δ����";

	static const unsigned int ID_IS_NOT_ORANGE_STUDY = 2;
	static const char* STR_IS_NOT_ORANGE_STUDY = "�������ֽܷ�";

	static const unsigned int ID_ID_INVALID = 3;
	static const char* STR_ID_INVALID = "���󲻴���";

	static const char* STR_NAMESPACE = "ERR_OPEN_RESOLVE_TRIGRAM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_IS_NOT_ORANGE_STUDY
	,STR_ID_INVALID
	};
}

namespace ERR_RESOLVE_TRIGRAM 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "�ֽ⹦�ܻ�δ����";

	static const unsigned int ID_ID_INVALID = 2;
	static const char* STR_ID_INVALID = "���󲻴���";

	static const unsigned int ID_NOT_ENOUGH_GOLD = 3;
	static const char* STR_NOT_ENOUGH_GOLD = "Ԫ������";

	static const unsigned int ID_IS_NOT_ORANGE_STUDY = 4;
	static const char* STR_IS_NOT_ORANGE_STUDY = "�������ֽܷ�";

	static const unsigned int ID_NOT_ENOUGH_COIN = 5;
	static const char* STR_NOT_ENOUGH_COIN = "ͭǮ����";

	static const char* STR_NAMESPACE = "ERR_RESOLVE_TRIGRAM";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_ID_INVALID
	,STR_NOT_ENOUGH_GOLD
	,STR_IS_NOT_ORANGE_STUDY
	,STR_NOT_ENOUGH_COIN
	};
}

namespace ERR_AUDIT_ALL_REFUSE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_UNOPEN = 1;
	static const char* STR_UNOPEN = "���ɹ��ܻ�δ����";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 2;
	static const char* STR_LIMIT_NOT_ENOUGH = "��û�����Ȩ��";

	static const unsigned int ID_PLAYER_NUM_IS_ZERO = 3;
	static const char* STR_PLAYER_NUM_IS_ZERO = "��ǰ��������";

	static const unsigned int ID_NOT_JOIN_FACTION = 4;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const char* STR_NAMESPACE = "ERR_AUDIT_ALL_REFUSE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_UNOPEN
	,STR_LIMIT_NOT_ENOUGH
	,STR_PLAYER_NUM_IS_ZERO
	,STR_NOT_JOIN_FACTION
	};
}

namespace ERR_OPEN_VIP_GIFT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_VIP_GIFT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_GET_VIP_GIFT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "����ɹ�";

	static const unsigned int ID_BAG_FULL = 1;
	static const char* STR_BAG_FULL = "�����ռ䲻��";

	static const unsigned int ID_GET_NUM_IS_NULL = 2;
	static const char* STR_GET_NUM_IS_NULL = "���չ���������㣬����������";

	static const unsigned int ID_VIP_LEVEL_NOT_AFFORD = 3;
	static const char* STR_VIP_LEVEL_NOT_AFFORD = "VIP�ȼ�����";

	static const char* STR_NAMESPACE = "ERR_GET_VIP_GIFT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_BAG_FULL
	,STR_GET_NUM_IS_NULL
	,STR_VIP_LEVEL_NOT_AFFORD
	};
}

namespace ERR_OPEN_RECV_FLOWER_TAB 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_RECV_FLOWER_TAB";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	};
}

namespace ERR_ACCEPT_FLOWER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NO_OPEN = 1;
	static const char* STR_NO_OPEN = "���ѹ���δ����";

	static const unsigned int ID_RECEVED = 2;
	static const char* STR_RECEVED = "����ȡ";

	static const unsigned int ID_REQ_ERR = 3;
	static const char* STR_REQ_ERR = "��ȡ�ļ�¼������";

	static const unsigned int ID_TODAY_NO_TIME = 4;
	static const char* STR_TODAY_NO_TIME = "����������þ�";

	static const unsigned int ID_BAG_FULL = 5;
	static const char* STR_BAG_FULL = "��������";

	static const char* STR_NAMESPACE = "ERR_ACCEPT_FLOWER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NO_OPEN
	,STR_RECEVED
	,STR_REQ_ERR
	,STR_TODAY_NO_TIME
	,STR_BAG_FULL
	};
}

namespace ERR_FACTION_PLAYERS_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_JOIN_FACTION = 2;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const char* STR_NAMESPACE = "ERR_FACTION_PLAYERS_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_JOIN_FACTION
	};
}

namespace ERR_CHANGE_FACTION_ICON 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_JOIN_FACTION = 2;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 3;
	static const char* STR_LIMIT_NOT_ENOUGH = "ֻ�����Ų��ܸ������ɱ�־";

	static const char* STR_NAMESPACE = "ERR_CHANGE_FACTION_ICON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_JOIN_FACTION
	,STR_LIMIT_NOT_ENOUGH
	};
}

namespace ERR_OPEN_CHANGE_FACTION_ICON 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_JOIN_FACTION = 2;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const unsigned int ID_LIMIT_NOT_ENOUGH = 3;
	static const char* STR_LIMIT_NOT_ENOUGH = "ֻ�����Ų��ܸ������ɱ�־";

	static const char* STR_NAMESPACE = "ERR_OPEN_CHANGE_FACTION_ICON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_JOIN_FACTION
	,STR_LIMIT_NOT_ENOUGH
	};
}

namespace ERR_REGISTER_FACTION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_UNREGISTER = 2;
	static const char* STR_UNREGISTER = "��ֹ�޸���������";

	static const unsigned int ID_NOTLEAD_UNREGISTER = 3;
	static const char* STR_NOTLEAD_UNREGISTER = "�����Ž�ֹ�޸���������";

	static const unsigned int ID_INVALID_CHARACTER = 4;
	static const char* STR_INVALID_CHARACTER = "��������ֻ��ʹ�����ġ�Ӣ�ĺ�����";

	static const unsigned int ID_DSPNAME_CONFLICT = 5;
	static const char* STR_DSPNAME_CONFLICT = "�������ѱ��������ʹ��";

	static const unsigned int ID_SENSITIVE_WORD = 6;
	static const char* STR_SENSITIVE_WORD = "���������к������дʻ㣬����������";

	static const unsigned int ID_TOO_LONG = 7;
	static const char* STR_TOO_LONG = "�������ƹ��������ܳ���6�����ֻ�12����ĸ";

	static const char* STR_NAMESPACE = "ERR_REGISTER_FACTION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNREGISTER
	,STR_NOTLEAD_UNREGISTER
	,STR_INVALID_CHARACTER
	,STR_DSPNAME_CONFLICT
	,STR_SENSITIVE_WORD
	,STR_TOO_LONG
	};
}

namespace ERR_OPEN_FIND_BACK_DOORSTRIBUTE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_DOORSTRIBUTE_FIND_BACK = 2;
	static const char* STR_NOT_DOORSTRIBUTE_FIND_BACK = "�㵱ǰû����ʷʣ���Ź����һ�";

	static const unsigned int ID_NOT_JOIN_FACTION = 3;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const char* STR_NAMESPACE = "ERR_OPEN_FIND_BACK_DOORSTRIBUTE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_DOORSTRIBUTE_FIND_BACK
	,STR_NOT_JOIN_FACTION
	};
}

namespace ERR_FIND_BACK_DOORSTRIBUTE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_DOORSTRIBUTE_FIND_BACK = 2;
	static const char* STR_NOT_DOORSTRIBUTE_FIND_BACK = "�㵱ǰû����ʷʣ���Ź����һ�";

	static const unsigned int ID_NOT_JOIN_FACTION = 3;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const char* STR_NAMESPACE = "ERR_FIND_BACK_DOORSTRIBUTE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_DOORSTRIBUTE_FIND_BACK
	,STR_NOT_JOIN_FACTION
	};
}

namespace ERR_UPGRADE_FORMATION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FORMATION_NOT_OPEN = 1;
	static const char* STR_FORMATION_NOT_OPEN = "����ϵͳ��δ����";

	static const unsigned int ID_FORMATION_ID_INVALIAD = 2;
	static const char* STR_FORMATION_ID_INVALIAD = "δ�ҵ��������Ϣ";

	static const unsigned int ID_PLAYER_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_PLAYER_LEVEL_NOT_ENOUGH = "�Ѵﵽ��ǰ������������������󷨵ȼ�";

	static const unsigned int ID_STORY_NOT_ENOUGH = 4;
	static const char* STR_STORY_NOT_ENOUGH = "���������޷�����";

	static const unsigned int ID_FORMATION_UNLOCK = 5;
	static const char* STR_FORMATION_UNLOCK = "���󷨻�δ����";

	static const unsigned int ID_FORMATION_NOT_UPGRADE = 6;
	static const char* STR_FORMATION_NOT_UPGRADE = "�Ƽ��ݻ�δ���ţ�����������";

	static const unsigned int ID_MAX_FORMATION_LEVEL = 7;
	static const char* STR_MAX_FORMATION_LEVEL = "�ü���������";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_FORMATION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FORMATION_NOT_OPEN
	,STR_FORMATION_ID_INVALIAD
	,STR_PLAYER_LEVEL_NOT_ENOUGH
	,STR_STORY_NOT_ENOUGH
	,STR_FORMATION_UNLOCK
	,STR_FORMATION_NOT_UPGRADE
	,STR_MAX_FORMATION_LEVEL
	};
}

namespace ERR_OPEN_FORMATION_SCIENCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FORMATION_NOT_OPEN = 1;
	static const char* STR_FORMATION_NOT_OPEN = "����ϵͳ��δ����";

	static const unsigned int ID_SCIENCE_NOT_OPEN = 2;
	static const char* STR_SCIENCE_NOT_OPEN = "�Ƽ��ݻ�δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FORMATION_SCIENCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FORMATION_NOT_OPEN
	,STR_SCIENCE_NOT_OPEN
	};
}

namespace ERR_UPGRADE_FORMATION_SCIENCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_NOT_EXIST_ERR = 1;
	static const char* STR_HERO_NOT_EXIST_ERR = "��鲻����";

	static const unsigned int ID_FORMATION_INDEX_INVALID_ERR = 2;
	static const char* STR_FORMATION_INDEX_INVALID_ERR = "��λ����Ч";

	static const unsigned int ID_FORMATION_INDEX_HAVE_HERO_ERR = 3;
	static const char* STR_FORMATION_INDEX_HAVE_HERO_ERR = "����λ�Ѿ��л��";

	static const unsigned int ID_FORMATION_KIND_NOT_EXIST = 4;
	static const char* STR_FORMATION_KIND_NOT_EXIST = "�󷨲�����";

	static const unsigned int ID_COACH_NOT_IN_FORMATION = 5;
	static const char* STR_COACH_NOT_IN_FORMATION = "���ǲ�������";

	static const unsigned int ID_FORMATION_EXCEPTION = 6;
	static const char* STR_FORMATION_EXCEPTION = "��λ���쳣";

	static const unsigned int ID_POSTION_NOT_PLAYER = 7;
	static const char* STR_POSTION_NOT_PLAYER = "�����쳣��δ��������λ���л��";

	static const unsigned int ID_FORMATION_NOT_OPEN = 8;
	static const char* STR_FORMATION_NOT_OPEN = "����ϵͳ��δ����";

	static const unsigned int ID_FORMATION_ID_INVALIAD = 9;
	static const char* STR_FORMATION_ID_INVALIAD = "δ�ҵ��������Ϣ";

	static const unsigned int ID_PLAYER_LEVEL_NOT_ENOUGH = 10;
	static const char* STR_PLAYER_LEVEL_NOT_ENOUGH = "�Ѵﵽ��ǰ������������������󷨵ȼ�";

	static const unsigned int ID_STORY_NOT_ENOUGH = 11;
	static const char* STR_STORY_NOT_ENOUGH = "���������޷�����";

	static const unsigned int ID_FORMATION_UNLOCK = 12;
	static const char* STR_FORMATION_UNLOCK = "���󷨻�δ����";

	static const unsigned int ID_FORMATION_NOT_UPGRADE = 13;
	static const char* STR_FORMATION_NOT_UPGRADE = "�Ƽ��ݻ�δ���ţ�����������";

	static const unsigned int ID_MAX_FORMATION_LEVEL = 14;
	static const char* STR_MAX_FORMATION_LEVEL = "�ü���������";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_FORMATION_SCIENCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_NOT_EXIST_ERR
	,STR_FORMATION_INDEX_INVALID_ERR
	,STR_FORMATION_INDEX_HAVE_HERO_ERR
	,STR_FORMATION_KIND_NOT_EXIST
	,STR_COACH_NOT_IN_FORMATION
	,STR_FORMATION_EXCEPTION
	,STR_POSTION_NOT_PLAYER
	,STR_FORMATION_NOT_OPEN
	,STR_FORMATION_ID_INVALIAD
	,STR_PLAYER_LEVEL_NOT_ENOUGH
	,STR_STORY_NOT_ENOUGH
	,STR_FORMATION_UNLOCK
	,STR_FORMATION_NOT_UPGRADE
	,STR_MAX_FORMATION_LEVEL
	};
}

namespace ERR_GET_EXPRIENCE_HOT_SPRING 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_OPEN = 1;
	static const char* STR_FACTION_NOT_OPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_HAVE_FACTION = 2;
	static const char* STR_NOT_HAVE_FACTION = "��δ��������";

	static const unsigned int ID_HERO_EXCEPTION = 3;
	static const char* STR_HERO_EXCEPTION = "���������쳣�����˳���������";

	static const char* STR_NAMESPACE = "ERR_GET_EXPRIENCE_HOT_SPRING";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_OPEN
	,STR_NOT_HAVE_FACTION
	,STR_HERO_EXCEPTION
	};
}

namespace ERR_OPEN_FACTION_SKILL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_FACTION_NOT_OPEN = 1;
	static const char* STR_FACTION_NOT_OPEN = "����ϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FACTION_SKILL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_FACTION_NOT_OPEN
	};
}

namespace ERR_OPEN_PLAYER_PANEL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_PLAYER_PANEL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_PLAYER_INFO_AWAKEN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_COACH_HERO_LOST = 2;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_PLAYER_INFO_AWAKEN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_PLAYER_INFO_SKILL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_COACH_HERO_LOST = 1;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_PLAYER_INFO_SKILL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_PLAYER_INFO_GODWEAPON 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳ��δ����";

	static const unsigned int ID_NOT_PLAYER_INFO = 2;
	static const char* STR_NOT_PLAYER_INFO = "�Ҳ��������Ϣ";

	static const unsigned int ID_COACH_HERO_LOST = 3;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_PLAYER_INFO_GODWEAPON";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_PLAYER_INFO
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_PLAYER_INFO_JEWELRY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_COACH_HERO_LOST = 1;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_PLAYER_INFO_JEWELRY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_DRESS_JEWELRY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_HERO_ID_NOT_FIND = 1;
	static const char* STR_HERO_ID_NOT_FIND = "�Ҳ�����صĻ����Ϣ";

	static const unsigned int ID_DRESS_TYPE_ERR = 2;
	static const char* STR_DRESS_TYPE_ERR = "δ֪��������";

	static const unsigned int ID_NOT_HAVE_JEWELRY = 3;
	static const char* STR_NOT_HAVE_JEWELRY = "������û��Ҫ��������Ʒ";

	static const unsigned int ID_IS_ALREAD_DRESS = 4;
	static const char* STR_IS_ALREAD_DRESS = "����Ʒ�Ѵ���";

	static const unsigned int ID_IS_ALREAD_UNDRESS = 5;
	static const char* STR_IS_ALREAD_UNDRESS = "����Ʒ������";

	static const unsigned int ID_BAG_IS_FULL = 6;
	static const char* STR_BAG_IS_FULL = "�����ռ�����������������";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 7;
	static const char* STR_LEVEL_NOT_ENOUGH = "�û��ȼ��������������Ʒ��������������";

	static const char* STR_NAMESPACE = "ERR_DRESS_JEWELRY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_HERO_ID_NOT_FIND
	,STR_DRESS_TYPE_ERR
	,STR_NOT_HAVE_JEWELRY
	,STR_IS_ALREAD_DRESS
	,STR_IS_ALREAD_UNDRESS
	,STR_BAG_IS_FULL
	,STR_LEVEL_NOT_ENOUGH
	};
}

namespace ERR_OPEN_HREO_SELECT_PANEL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_HREO_SELECT_PANEL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_JEWELRY_GENERATE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_JEWELRY_GENERATE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_JEWELRY_GENERATE_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_EXCEPTION = 1;
	static const char* STR_IS_EXCEPTION = "�ϳ���Ϣ�����쳣";

	static const char* STR_NAMESPACE = "ERR_JEWELRY_GENERATE_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_EXCEPTION
	};
}

namespace ERR_JEWELRY_GENERATE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_ALREAD_STRENG = 1;
	static const char* STR_ALREAD_STRENG = "����������Ʒ���ܲ���ϳɣ�����ͨ���ֽ��þ�������";

	static const unsigned int ID_SELECT_JEWELRY = 2;
	static const char* STR_SELECT_JEWELRY = "��Ʒ���������Ժϳɣ���ѡ��4����Ʒ";

	static const unsigned int ID_IS_EXCEPTION = 3;
	static const char* STR_IS_EXCEPTION = "�ϳ���Ϣ�����쳣";

	static const unsigned int ID_BAG_IS_FULL = 4;
	static const char* STR_BAG_IS_FULL = "��������������������";

	static const char* STR_NAMESPACE = "ERR_JEWELRY_GENERATE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_ALREAD_STRENG
	,STR_SELECT_JEWELRY
	,STR_IS_EXCEPTION
	,STR_BAG_IS_FULL
	};
}

namespace ERR_JEWELRY_STRENGTH 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FIND_JEWELRY = 1;
	static const char* STR_NOT_FIND_JEWELRY = "δ�ҵ��������ҵ���Ʒ��Ϣ";

	static const unsigned int ID_IS_MAX_LEVEL = 2;
	static const char* STR_IS_MAX_LEVEL = "�Ѿ�������߼�";

	static const unsigned int ID_ITEM_NOT_ENOUGH = 3;
	static const char* STR_ITEM_NOT_ENOUGH = "�������߲���";

	static const unsigned int ID_PALYER_LEVEL_NOT_ENOUGH = 4;
	static const char* STR_PALYER_LEVEL_NOT_ENOUGH = "��ҵȼ������Ծ�������Ʒ";

	static const unsigned int ID_NOT_STRENG_EXT = 5;
	static const char* STR_NOT_STRENG_EXT = "����Ʒ�����ȼ��������Ծ�����������";

	static const unsigned int ID_IS_EXCEPTION = 6;
	static const char* STR_IS_EXCEPTION = "��Ʒ������Ϣ�����쳣";

	static const char* STR_NAMESPACE = "ERR_JEWELRY_STRENGTH";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FIND_JEWELRY
	,STR_IS_MAX_LEVEL
	,STR_ITEM_NOT_ENOUGH
	,STR_PALYER_LEVEL_NOT_ENOUGH
	,STR_NOT_STRENG_EXT
	,STR_IS_EXCEPTION
	};
}

namespace ERR_PLAYER_INFO_EQUIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_COACH_HERO_LOST = 1;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_PLAYER_INFO_EQUIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_JEWELRY_RESOLVE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_HAVE_JEWELRY = 1;
	static const char* STR_NOT_HAVE_JEWELRY = "�Ҳ�������Ʒ��Ϣ";

	static const unsigned int ID_BAG_IS_FULL = 2;
	static const char* STR_BAG_IS_FULL = "�����ռ䲻�㣬����������";

	static const unsigned int ID_JEWELRY_INFO_UNNORMAL = 3;
	static const char* STR_JEWELRY_INFO_UNNORMAL = "��Ʒ�����쳣";

	static const char* STR_NAMESPACE = "ERR_JEWELRY_RESOLVE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_HAVE_JEWELRY
	,STR_BAG_IS_FULL
	,STR_JEWELRY_INFO_UNNORMAL
	};
}

namespace ERR_OPEN_JEWELRY_STRENGTH 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_COACH_HERO_LOST = 1;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_OPEN_JEWELRY_STRENGTH";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_JEWELRY_COMPARE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FIND_JEWELRY = 1;
	static const char* STR_NOT_FIND_JEWELRY = "�Ҳ�����Ʒ��Ϣ";

	static const unsigned int ID_COACH_HERO_LOST = 2;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_JEWELRY_COMPARE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FIND_JEWELRY
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_JEWELRY_EXT_UPGRADE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_MAX = 1;
	static const char* STR_IS_MAX = "����������������߼�";

	static const unsigned int ID_NOT_FIND_JEWELRY = 2;
	static const char* STR_NOT_FIND_JEWELRY = "�Ҳ�����Ʒ��Ϣ";

	static const unsigned int ID_NOT_STRENG_NUM = 3;
	static const char* STR_NOT_STRENG_NUM = "������������ʣ��ǿ������";

	static const unsigned int ID_EXT_ID_NOT_FIND = 4;
	static const char* STR_EXT_ID_NOT_FIND = "�Ҳ�����صĸ�������";

	static const char* STR_NAMESPACE = "ERR_JEWELRY_EXT_UPGRADE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_MAX
	,STR_NOT_FIND_JEWELRY
	,STR_NOT_STRENG_NUM
	,STR_EXT_ID_NOT_FIND
	};
}

namespace ERR_OPEN_JEWELRY_RESOLVE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FIND_JEWELRY = 1;
	static const char* STR_NOT_FIND_JEWELRY = "�Ҳ�����Ʒ��Ϣ";

	static const unsigned int ID_JEWELRY_INFO_EXCEPTION = 2;
	static const char* STR_JEWELRY_INFO_EXCEPTION = "��Ʒ��Ϣ�쳣";

	static const char* STR_NAMESPACE = "ERR_OPEN_JEWELRY_RESOLVE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FIND_JEWELRY
	,STR_JEWELRY_INFO_EXCEPTION
	};
}

namespace ERR_GVG_OPEN_MY_GAMBLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "�������ս��δ����";

	static const char* STR_NAMESPACE = "ERR_GVG_OPEN_MY_GAMBLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_OPEN_FACTION_MONEY_RANK 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_FACTION_MONEY_RANK";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_GVG_RULE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_GVG_RULE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_ALREAD_APPLAY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_APPLAY_TIME = 1;
	static const char* STR_NOT_APPLAY_TIME = "��ǰ�����ڱ����׶Σ���ȴ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_ALREAD_APPLAY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_APPLAY_TIME
	};
}

namespace ERR_OPEN_GVG_FORMATION 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_HEAD = 1;
	static const char* STR_NOT_HEAD = "ֻ�����Ų��ܽ��д˲���";

	static const unsigned int ID_TIME_NOT_MATCH = 2;
	static const char* STR_TIME_NOT_MATCH = "���ڻ����ܶ����ͽ��е���";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_LEVEL_NOT_ENOUGH = "���ɵȼ�δ�ﵽ����Ҫ��";

	static const unsigned int ID_RANK_NOT_ENOUGH = 4;
	static const char* STR_RANK_NOT_ENOUGH = "��������δ�ﵽ����Ҫ��";

	static const unsigned int ID_APPLAY_FIRST = 5;
	static const char* STR_APPLAY_FIRST = "���ȱ���";

	static const char* STR_NAMESPACE = "ERR_OPEN_GVG_FORMATION";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_HEAD
	,STR_TIME_NOT_MATCH
	,STR_LEVEL_NOT_ENOUGH
	,STR_RANK_NOT_ENOUGH
	,STR_APPLAY_FIRST
	};
}

namespace ERR_GVG_APPLAY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_GVG_APPLAY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_GVG_MONEY_CHAOS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_GVG_MONEY_CHAOS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_OPEN_GVG_MONEY_CHAOS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_GVG_MONEY_CHAOS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_OPEN_16_TO_8_TO_4 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_16_TO_8_TO_4";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_OPEN_FINAL_WAR 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FINAL_WAR";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_GVG_LAST_RESULT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_GVG_LAST_RESULT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_OPEN_GVG_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const unsigned int ID_NOT_JOIN_FACTION = 2;
	static const char* STR_NOT_JOIN_FACTION = "�㻹δ��������";

	static const unsigned int ID_NOT_FIND_FACTION = 3;
	static const char* STR_NOT_FIND_FACTION = "�����ɵ�ս���ѹ��ڣ��޷��ۿ�";

	static const char* STR_NAMESPACE = "ERR_OPEN_GVG_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_JOIN_FACTION
	,STR_NOT_FIND_FACTION
	};
}

namespace ERR_SEE_GVG_VIDEO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FIND_VIDEO = 1;
	static const char* STR_NOT_FIND_VIDEO = "�ó�����ս���Ѿ����ڣ��޷��ۿ�";

	static const unsigned int ID_NOT_START = 2;
	static const char* STR_NOT_START = "ս����δ��ʼ�������ĵȴ�";

	static const unsigned int ID_REACH_END = 3;
	static const char* STR_REACH_END = "�������ս���Ѿ������һ��";

	static const unsigned int ID_NOT_FIND_PVP_VIDEO = 4;
	static const char* STR_NOT_FIND_PVP_VIDEO = "�ó����ս���ѹ��ڣ��޷��ۿ�";

	static const unsigned int ID_IS_UNOPEN = 5;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_SEE_GVG_VIDEO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FIND_VIDEO
	,STR_NOT_START
	,STR_REACH_END
	,STR_NOT_FIND_PVP_VIDEO
	,STR_IS_UNOPEN
	};
}

namespace ERR_END_GVG_VIDEO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FIND_VIDEO = 1;
	static const char* STR_NOT_FIND_VIDEO = "�ó�ս���Ѿ����ڣ��޷��ۿ�";

	static const unsigned int ID_IS_UNOPEN = 2;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_END_GVG_VIDEO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FIND_VIDEO
	,STR_IS_UNOPEN
	};
}

namespace ERR_SHOW_GVG_MVP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FIND_VIDEO = 1;
	static const char* STR_NOT_FIND_VIDEO = "�ó�ս���Ѿ����ڣ��޷��ۿ�";

	static const unsigned int ID_IS_UNOPEN = 2;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_SHOW_GVG_MVP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FIND_VIDEO
	,STR_IS_UNOPEN
	};
}

namespace ERR_GVG_OPEN_GAMBLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_HAVE_BATTLE = 1;
	static const char* STR_NOT_HAVE_BATTLE = "û�п���Ѻע����Ϣ";

	static const unsigned int ID_ALREAD_BATTLE = 2;
	static const char* STR_ALREAD_BATTLE = "ս���ѽ�������Ѻע";

	static const unsigned int ID_NOT_FIND_FACTION = 3;
	static const char* STR_NOT_FIND_FACTION = "�Ҳ���������Ϣ";

	static const unsigned int ID_IS_UNOPEN = 4;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_GVG_OPEN_GAMBLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_HAVE_BATTLE
	,STR_ALREAD_BATTLE
	,STR_NOT_FIND_FACTION
	,STR_IS_UNOPEN
	};
}

namespace ERR_GVG_GAMBLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ս���ܻ�δ����";

	static const unsigned int ID_ALREAD_BATTLE = 2;
	static const char* STR_ALREAD_BATTLE = "ս���ѽ�������Ѻע";

	static const unsigned int ID_NOT_HAVE_BATTLE = 3;
	static const char* STR_NOT_HAVE_BATTLE = "û�п���Ѻע����Ϣ";

	static const unsigned int ID_ALREAD_GAMBLE = 4;
	static const char* STR_ALREAD_GAMBLE = "��Ѻע����ȴ�����Ѻע";

	static const unsigned int ID_GAMBLE_IS_ERR = 5;
	static const char* STR_GAMBLE_IS_ERR = "Ѻע��Ϣ����";

	static const char* STR_NAMESPACE = "ERR_GVG_GAMBLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_ALREAD_BATTLE
	,STR_NOT_HAVE_BATTLE
	,STR_ALREAD_GAMBLE
	,STR_GAMBLE_IS_ERR
	};
}

namespace ERR_READ_FORMATION_PLAYER_TIP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UPOPEN = 1;
	static const char* STR_IS_UPOPEN = "�Է����ܻ�δ����";

	static const unsigned int ID_NOT_JOIN_FACTION = 2;
	static const char* STR_NOT_JOIN_FACTION = "�Է���δ��������";

	static const unsigned int ID_IS_UNOPEN = 3;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_READ_FORMATION_PLAYER_TIP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UPOPEN
	,STR_NOT_JOIN_FACTION
	,STR_IS_UNOPEN
	};
}

namespace ERR_GVG_FACTION_EMBATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_HEAD = 1;
	static const char* STR_NOT_HEAD = "�˲���ֻ��������Ȩ��";

	static const unsigned int ID_NOT_HAVE_FACTION = 2;
	static const char* STR_NOT_HAVE_FACTION = "��δ��������";

	static const unsigned int ID_IS_UNOPEN = 3;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const unsigned int ID_HEAD_MUST_IN_FORMATION = 4;
	static const char* STR_HEAD_MUST_IN_FORMATION = "���ű���������";

	static const unsigned int ID_MORE_ONE = 5;
	static const char* STR_MORE_ONE = "�빴ѡ��Ա����";

	static const char* STR_NAMESPACE = "ERR_GVG_FACTION_EMBATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_HEAD
	,STR_NOT_HAVE_FACTION
	,STR_IS_UNOPEN
	,STR_HEAD_MUST_IN_FORMATION
	,STR_MORE_ONE
	};
}

namespace ERR_OPEN_GVG_GIFT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_GVG_GIFT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_GET_GVG_GIFT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const unsigned int ID_NOT_EXIST = 2;
	static const char* STR_NOT_EXIST = "�ý������������";

	static const unsigned int ID_ALREAD_GET = 3;
	static const char* STR_ALREAD_GET = "�ý����������ȡ";

	static const unsigned int ID_BAG_FULL = 4;
	static const char* STR_BAG_FULL = "��������������ȡ����";

	static const char* STR_NAMESPACE = "ERR_GET_GVG_GIFT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_EXIST
	,STR_ALREAD_GET
	,STR_BAG_FULL
	};
}

namespace ERR_16_TO_8_TO_4 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_16_TO_8_TO_4";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_FINAL_WAR 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_FINAL_WAR";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_LAST_RESULT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_LAST_RESULT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_SELECT_GROUP_TYPE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const char* STR_NAMESPACE = "ERR_SELECT_GROUP_TYPE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_GVG_FACTION_APPLAY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���սϵͳ��δ����";

	static const unsigned int ID_NOT_HEAD = 2;
	static const char* STR_NOT_HEAD = "ֻ�����Ų��ܽ��д˲���";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_LEVEL_NOT_ENOUGH = "���ɵȼ�δ�ﵽ����Ҫ��";

	static const unsigned int ID_RANK_NOT_ENOUGH = 4;
	static const char* STR_RANK_NOT_ENOUGH = "��������δ�ﵽ����Ҫ��";

	static const unsigned int ID_ALREAD_APPLAY = 5;
	static const char* STR_ALREAD_APPLAY = "���������ѱ���";

	static const unsigned int ID_NOT_APPLAY_TIME = 6;
	static const char* STR_NOT_APPLAY_TIME = "��ǰ�����ڱ����׶Σ���ȴ�";

	static const char* STR_NAMESPACE = "ERR_GVG_FACTION_APPLAY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_HEAD
	,STR_LEVEL_NOT_ENOUGH
	,STR_RANK_NOT_ENOUGH
	,STR_ALREAD_APPLAY
	,STR_NOT_APPLAY_TIME
	};
}

namespace ERR_READ_BATTLE_LOG 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const char* STR_NAMESPACE = "ERR_READ_BATTLE_LOG";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	};
}

namespace ERR_OPEN_DEVOUR_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NOT_FIND_SOUL = 2;
	static const char* STR_NOT_FIND_SOUL = "�Ҳ���ս�꿨";

	static const char* STR_NAMESPACE = "ERR_OPEN_DEVOUR_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_FIND_SOUL
	};
}

namespace ERR_DEVOUR_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NOT_FIND_SOUL = 2;
	static const char* STR_NOT_FIND_SOUL = "�Ҳ���ս�꿨";

	static const unsigned int ID_IS_SAME = 3;
	static const char* STR_IS_SAME = "ս�꿨�쳣";

	static const unsigned int ID_DEVOUR_SOUL_NO_DEVOUR = 4;
	static const char* STR_DEVOUR_SOUL_NO_DEVOUR = "����ս��ֻ�ܱ�����";

	static const unsigned int ID_IS_FULL = 5;
	static const char* STR_IS_FULL = "���������޷�����";

	static const char* STR_NAMESPACE = "ERR_DEVOUR_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_FIND_SOUL
	,STR_IS_SAME
	,STR_DEVOUR_SOUL_NO_DEVOUR
	,STR_IS_FULL
	};
}

namespace ERR_OPEN_REFLASH_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NOT_FIND_SOUL = 2;
	static const char* STR_NOT_FIND_SOUL = "�Ҳ���ս�꿨";

	static const char* STR_NAMESPACE = "ERR_OPEN_REFLASH_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_FIND_SOUL
	};
}

namespace ERR_REFLASH_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_DEVOUR_SOUL_NO_REFLASH = 2;
	static const char* STR_DEVOUR_SOUL_NO_REFLASH = "����ս�겻��ϴ��";

	static const unsigned int ID_NO_ENOUGHT_GOLD = 3;
	static const char* STR_NO_ENOUGHT_GOLD = "û���㹻��Ԫ������ս��";

	static const unsigned int ID_NOT_FIND_SOUL = 4;
	static const char* STR_NOT_FIND_SOUL = "�Ҳ���ս�꿨";

	static const char* STR_NAMESPACE = "ERR_REFLASH_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_DEVOUR_SOUL_NO_REFLASH
	,STR_NO_ENOUGHT_GOLD
	,STR_NOT_FIND_SOUL
	};
}

namespace ERR_SAVE_REFLASH_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NOT_FIND_SOUL = 2;
	static const char* STR_NOT_FIND_SOUL = "�Ҳ���ս�꿨";

	static const char* STR_NAMESPACE = "ERR_SAVE_REFLASH_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_FIND_SOUL
	};
}

namespace ERR_SOULREP_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_ALREADY_IN_SOULREP = 2;
	static const char* STR_ALREADY_IN_SOULREP = "�Ѿ��ڽ��긱����";

	static const char* STR_NAMESPACE = "ERR_SOULREP_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_ALREADY_IN_SOULREP
	};
}

namespace ERR_PRODUCT_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NO_ENOUGHT_COIN = 2;
	static const char* STR_NO_ENOUGHT_COIN = "û���㹻��ͭǮ";

	static const unsigned int ID_NO_ENOUGHT_GOLD = 3;
	static const char* STR_NO_ENOUGHT_GOLD = "û���㹻��Ԫ��";

	static const unsigned int ID_SOUL_BAG_FULL = 4;
	static const char* STR_SOUL_BAG_FULL = "���걳������";

	static const unsigned int ID_ITEM_BAG_FULL = 5;
	static const char* STR_ITEM_BAG_FULL = "���ϱ�������";

	static const unsigned int ID_NO_IN_ACTIVITY = 6;
	static const char* STR_NO_IN_ACTIVITY = "������ս����";

	static const unsigned int ID_UNKNOWN_ERROR = 7;
	static const char* STR_UNKNOWN_ERROR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_PRODUCT_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NO_ENOUGHT_COIN
	,STR_NO_ENOUGHT_GOLD
	,STR_SOUL_BAG_FULL
	,STR_ITEM_BAG_FULL
	,STR_NO_IN_ACTIVITY
	,STR_UNKNOWN_ERROR
	};
}

namespace ERR_HERO_SOUL_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NO_HERO = 2;
	static const char* STR_NO_HERO = "�������û����ֻӢ��";

	static const char* STR_NAMESPACE = "ERR_HERO_SOUL_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NO_HERO
	};
}

namespace ERR_HERO_EQUIP_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NO_HERO = 2;
	static const char* STR_NO_HERO = "�������û����ֻӢ��";

	static const unsigned int ID_HERO_ALL_EQUIP = 3;
	static const char* STR_HERO_ALL_EQUIP = "Ӣ�����϶�װ��ս����";

	static const unsigned int ID_NO_THIS_SOUL = 4;
	static const char* STR_NO_THIS_SOUL = "�������û�����ս��";

	static const unsigned int ID_DEVOUR_SOUL_NO_EQUIP = 5;
	static const char* STR_DEVOUR_SOUL_NO_EQUIP = "����ս�겻�ܴ���";

	static const unsigned int ID_UNKNOWN_ERROR = 6;
	static const char* STR_UNKNOWN_ERROR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_HERO_EQUIP_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NO_HERO
	,STR_HERO_ALL_EQUIP
	,STR_NO_THIS_SOUL
	,STR_DEVOUR_SOUL_NO_EQUIP
	,STR_UNKNOWN_ERROR
	};
}

namespace ERR_HERO_UNDRESS_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NO_HERO = 2;
	static const char* STR_NO_HERO = "�������û����ֻӢ��";

	static const unsigned int ID_SOUL_BAG_FULL = 3;
	static const char* STR_SOUL_BAG_FULL = "���걳������";

	static const unsigned int ID_NO_THIS_SOUL = 4;
	static const char* STR_NO_THIS_SOUL = "Ӣ������û�����ս��";

	static const unsigned int ID_UNKNOWN_ERROR = 5;
	static const char* STR_UNKNOWN_ERROR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_HERO_UNDRESS_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NO_HERO
	,STR_SOUL_BAG_FULL
	,STR_NO_THIS_SOUL
	,STR_UNKNOWN_ERROR
	};
}

namespace ERR_HERO_REPLACE_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NO_HERO = 2;
	static const char* STR_NO_HERO = "�������û����ֻӢ��";

	static const unsigned int ID_NO_THIS_SOUL = 3;
	static const char* STR_NO_THIS_SOUL = "Ӣ������û�����ս��";

	static const unsigned int ID_DEVOUR_SOUL_NO_REPLACE = 4;
	static const char* STR_DEVOUR_SOUL_NO_REPLACE = "����ս�겻�ܶһ�";

	static const unsigned int ID_UNKNOWN_ERROR = 5;
	static const char* STR_UNKNOWN_ERROR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_HERO_REPLACE_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NO_HERO
	,STR_NO_THIS_SOUL
	,STR_DEVOUR_SOUL_NO_REPLACE
	,STR_UNKNOWN_ERROR
	};
}

namespace ERR_SOULEXCHANGE_INFO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERROR = 2;
	static const char* STR_UNKNOWN_ERROR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_SOULEXCHANGE_INFO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERROR
	};
}

namespace ERR_EXCHANGE_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_NO_ENOUGHT_METERIAL = 2;
	static const char* STR_NO_ENOUGHT_METERIAL = "ս����ϲ���";

	static const unsigned int ID_SOUL_BAG_FULL = 3;
	static const char* STR_SOUL_BAG_FULL = "ս�걳�����������ܶһ�";

	static const unsigned int ID_UNKNOWN_ERROR = 4;
	static const char* STR_UNKNOWN_ERROR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_EXCHANGE_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NO_ENOUGHT_METERIAL
	,STR_SOUL_BAG_FULL
	,STR_UNKNOWN_ERROR
	};
}

namespace ERR_CLIGS_PLAYER_INFO_SOUL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ս��ϵͳδ����";

	static const unsigned int ID_COACH_HERO_LOST = 2;
	static const char* STR_COACH_HERO_LOST = "������Ϣ��ʧ";

	static const char* STR_NAMESPACE = "ERR_CLIGS_PLAYER_INFO_SOUL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_COACH_HERO_LOST
	};
}

namespace ERR_OPEN_MY_MEDAL 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "ѫ��ϵͳδ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_MY_MEDAL";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_VIEW_FACTION_MEMBER 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FOUND_FACTION = 1;
	static const char* STR_NOT_FOUND_FACTION = "�Ҳ���������";

	static const char* STR_NAMESPACE = "ERR_VIEW_FACTION_MEMBER";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FOUND_FACTION
	};
}

namespace ERR_OPEN_OUT_BOUND 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FRESH = 1;
	static const char* STR_NOT_FRESH = "����ת��";

	static const char* STR_NAMESPACE = "ERR_OPEN_OUT_BOUND";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FRESH
	};
}

namespace ERR_OPEN_OUT_BOUND_MAP 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FRESH = 1;
	static const char* STR_NOT_FRESH = "����ת��";

	static const unsigned int ID_NOT_OPEN = 2;
	static const char* STR_NOT_OPEN = "���⴫��δ����";

	static const unsigned int ID_NOT_EXIST = 3;
	static const char* STR_NOT_EXIST = "���⴫������";

	static const char* STR_NAMESPACE = "ERR_OPEN_OUT_BOUND_MAP";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FRESH
	,STR_NOT_OPEN
	,STR_NOT_EXIST
	};
}

namespace ERR_OUT_BOUND_BATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_FRESH = 1;
	static const char* STR_NOT_FRESH = "����ת��";

	static const unsigned int ID_NOT_OPEN = 2;
	static const char* STR_NOT_OPEN = "����ͨ����һ������";

	static const unsigned int ID_NOT_EXIST = 3;
	static const char* STR_NOT_EXIST = "���⴫������";

	static const unsigned int ID_NOT_PHYSICAL = 4;
	static const char* STR_NOT_PHYSICAL = "�������㣬��Ϣһ��";

	static const unsigned int ID_BAG_IS_FULL = 5;
	static const char* STR_BAG_IS_FULL = "�����ռ䲻�㣬����������";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 6;
	static const char* STR_LEVEL_NOT_ENOUGH = "��ǰ�ȼ��޷���ս�ø�������������";

	static const unsigned int ID_CONFIG_ERR = 7;
	static const char* STR_CONFIG_ERR = "ս����������ϵGM";

	static const unsigned int ID_HOOK_ERR = 8;
	static const char* STR_HOOK_ERR = "δͨ�ع����޷�����ս��";

	static const unsigned int ID_NOT_BATTLE_NUM = 9;
	static const char* STR_NOT_BATTLE_NUM = "������ս�������ù⣬������������ս";

	static const char* STR_NAMESPACE = "ERR_OUT_BOUND_BATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_FRESH
	,STR_NOT_OPEN
	,STR_NOT_EXIST
	,STR_NOT_PHYSICAL
	,STR_BAG_IS_FULL
	,STR_LEVEL_NOT_ENOUGH
	,STR_CONFIG_ERR
	,STR_HOOK_ERR
	,STR_NOT_BATTLE_NUM
	};
}

namespace ERR_CLIGS_PETREP_INFO_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_PETREP_INFO_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_CLIGS_PRODUCT_PET_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_ENOUGHT_GOLD = 3;
	static const char* STR_NO_ENOUGHT_GOLD = "Ԫ������";

	static const unsigned int ID_NO_ENOUGHT_BAG_SIZE = 4;
	static const char* STR_NO_ENOUGHT_BAG_SIZE = "�����ռ䲻��";

	static const unsigned int ID_NO_ENOUGHT_PETBAG_SIZE = 5;
	static const char* STR_NO_ENOUGHT_PETBAG_SIZE = "��迨Ƭ�ı����ռ䲻��";

	static const char* STR_NAMESPACE = "ERR_CLIGS_PRODUCT_PET_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_ENOUGHT_GOLD
	,STR_NO_ENOUGHT_BAG_SIZE
	,STR_NO_ENOUGHT_PETBAG_SIZE
	};
}

namespace ERR_CLIGS_OPEN_BORNPET_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_BORNPET_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_CLIGS_BORNPET_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_BORNPET_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_CLIGS_OPEN_STAR_PANEL_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_STAR_PANEL_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	};
}

namespace ERR_CLIGS_UP_STAR_LV_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_PET_SATR_FULL = 3;
	static const char* STR_PET_SATR_FULL = "����ǽ��Ѵﵽ��ǰ���";

	static const unsigned int ID_DRAGON_ITEM_NO_ENOUGHT = 4;
	static const char* STR_DRAGON_ITEM_NO_ENOUGHT = "δ�����㹻����������";

	static const unsigned int ID_NO_THIS_PET = 5;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_PET_LEVEL_LOW = 6;
	static const char* STR_PET_LEVEL_LOW = "���ȼ������޷�����";

	static const unsigned int ID_PLAYER_LEVEL_LOW = 7;
	static const char* STR_PLAYER_LEVEL_LOW = "��ҵȼ�δ�ﵽҪ������޷�����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_UP_STAR_LV_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_PET_SATR_FULL
	,STR_DRAGON_ITEM_NO_ENOUGHT
	,STR_NO_THIS_PET
	,STR_PET_LEVEL_LOW
	,STR_PLAYER_LEVEL_LOW
	};
}

namespace ERR_CLIGS_OPEN_PET_PANEL_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_PET_PANEL_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_CLIGS_OPEN_PETFEED_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_PETFEED_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	};
}

namespace ERR_CLIGS_FIRST_DRAW_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_NO_TODAY_FIRST_DRAW = 4;
	static const char* STR_NO_TODAY_FIRST_DRAW = "����ιʳ�������ù�";

	static const unsigned int ID_EAT_CUR_FRUIT = 5;
	static const char* STR_EAT_CUR_FRUIT = "����ιʳ�굱ǰʳ���ٽ������˲���";

	static const unsigned int ID_VIPFEED_NO_ENOUGHT_GOLD = 6;
	static const char* STR_VIPFEED_NO_ENOUGHT_GOLD = "VIPι��Ԫ������";

	static const char* STR_NAMESPACE = "ERR_CLIGS_FIRST_DRAW_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	,STR_NO_TODAY_FIRST_DRAW
	,STR_EAT_CUR_FRUIT
	,STR_VIPFEED_NO_ENOUGHT_GOLD
	};
}

namespace ERR_CLIGS_RESET_DRAW_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_NOT_ENOUGHT_GOLD = 4;
	static const char* STR_NOT_ENOUGHT_GOLD = "û���㹻��Ԫ��";

	static const unsigned int ID_IS_BEST_RESULT = 5;
	static const char* STR_IS_BEST_RESULT = "5���˲ι�����ߵ��ε����";

	static const unsigned int ID_NO_FIRST_DRAW = 6;
	static const char* STR_NO_FIRST_DRAW = "��δ������ѹ�£��޷�������ҡ";

	static const char* STR_NAMESPACE = "ERR_CLIGS_RESET_DRAW_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	,STR_NOT_ENOUGHT_GOLD
	,STR_IS_BEST_RESULT
	,STR_NO_FIRST_DRAW
	};
}

namespace ERR_CLIGS_CONFIRM_FEED_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const char* STR_NAMESPACE = "ERR_CLIGS_CONFIRM_FEED_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	};
}

namespace ERR_CLIGS_MERGE_PET_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const char* STR_NAMESPACE = "ERR_CLIGS_MERGE_PET_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	};
}

namespace ERR_CLIGS_OPEN_PET_STORE_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_PET_STORE_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_CLIGS_BUY_PET_STORE_ITEM_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_ENOUGHT_PETSOTRE = 3;
	static const char* STR_NO_ENOUGHT_PETSOTRE = "���ֲ���";

	static const unsigned int ID_NO_ENOUGHT_GOLD = 4;
	static const char* STR_NO_ENOUGHT_GOLD = "Ԫ������";

	static const unsigned int ID_ON_ENOUGHT_BAG_SIZE = 5;
	static const char* STR_ON_ENOUGHT_BAG_SIZE = "�����ռ䲻��";

	static const unsigned int ID_Cant_BUY = 6;
	static const char* STR_Cant_BUY = "����Ʒ���ɶһ�";

	static const char* STR_NAMESPACE = "ERR_CLIGS_BUY_PET_STORE_ITEM_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_ENOUGHT_PETSOTRE
	,STR_NO_ENOUGHT_GOLD
	,STR_ON_ENOUGHT_BAG_SIZE
	,STR_Cant_BUY
	};
}

namespace ERR_CLIGS_OPEN_REFINEPET_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_REFINEPET_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_CLIGS_REFINEPET_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const char* STR_NAMESPACE = "ERR_CLIGS_REFINEPET_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	};
}

namespace ERR_CLIGS_OPEN_WASH_QUALITY_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_WASH_QUALITY_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	};
}

namespace ERR_CLIGS_WASH_QUALITY_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_PSYCHIC_FULL = 4;
	static const char* STR_PSYCHIC_FULL = "������������������ϴ��";

	static const unsigned int ID_NO_ENOUGHT_GOLD = 5;
	static const char* STR_NO_ENOUGHT_GOLD = "Ԫ������";

	static const unsigned int ID_NO_ENOUGHT_WASHITEM = 6;
	static const char* STR_NO_ENOUGHT_WASHITEM = "ȱ��ϴ�������ĵ���";

	static const unsigned int ID_CANT_WASH = 7;
	static const char* STR_CANT_WASH = "��������δ����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_WASH_QUALITY_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	,STR_PSYCHIC_FULL
	,STR_NO_ENOUGHT_GOLD
	,STR_NO_ENOUGHT_WASHITEM
	,STR_CANT_WASH
	};
}

namespace ERR_CLIGS_CHANGE_PET_STATE_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_OVER_MAX_FOLLOW = 4;
	static const char* STR_OVER_MAX_FOLLOW = "�������������������";

	static const unsigned int ID_OVER_MAX_FIGHT = 5;
	static const char* STR_OVER_MAX_FIGHT = "������ս�����������";

	static const char* STR_NAMESPACE = "ERR_CLIGS_CHANGE_PET_STATE_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	,STR_OVER_MAX_FOLLOW
	,STR_OVER_MAX_FIGHT
	};
}

namespace ERR_CLIGS_OPEN_PET_INHERIT_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_NO_INHERIT_PET = 4;
	static const char* STR_NO_INHERIT_PET = "û�пɱ��̳е����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_PET_INHERIT_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	,STR_NO_INHERIT_PET
	};
}

namespace ERR_CLIGS_PET_INHERIT_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_THIS_PET = 3;
	static const char* STR_NO_THIS_PET = "û����ֻ���";

	static const unsigned int ID_NO_ENOUGHT_GOLD = 4;
	static const char* STR_NO_ENOUGHT_GOLD = "Ԫ������";

	static const unsigned int ID_NO_ENOUGHT_COIN = 5;
	static const char* STR_NO_ENOUGHT_COIN = "ͭǮ����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_PET_INHERIT_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_THIS_PET
	,STR_NO_ENOUGHT_GOLD
	,STR_NO_ENOUGHT_COIN
	};
}

namespace ERR_CLIGS_OPEN_PLAYERPET_PANEL_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "���ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const unsigned int ID_NO_FIGHT_PET = 3;
	static const char* STR_NO_FIGHT_PET = "û����账�ڳ�ս״̬";

	static const char* STR_NAMESPACE = "ERR_CLIGS_OPEN_PLAYERPET_PANEL_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	,STR_NO_FIGHT_PET
	};
}

namespace ERR_CLIGS_REQUEST_ALL_PET_INFO_REQ 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "����ϵͳδ����";

	static const unsigned int ID_UNKNOWN_ERR = 2;
	static const char* STR_UNKNOWN_ERR = "δ֪����";

	static const char* STR_NAMESPACE = "ERR_CLIGS_REQUEST_ALL_PET_INFO_REQ";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_UNKNOWN_ERR
	};
}

namespace ERR_OPEN_STORE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_STORE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	};
}

namespace ERR_EXCHANGE_GOODS 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_NOT_ITEM_ID = 2;
	static const char* STR_NOT_ITEM_ID = "�Ҳ�������Ʒ";

	static const unsigned int ID_RES_NOT_ENOUGH = 3;
	static const char* STR_RES_NOT_ENOUGH = "��ǰ��Դ�����Թ���˵���";

	static const unsigned int ID_NUM_NOT_ENOUGH = 4;
	static const char* STR_NUM_NOT_ENOUGH = "��������Ϊ0";

	static const unsigned int ID_BAG_IS_FULL = 5;
	static const char* STR_BAG_IS_FULL = "�����ռ���������������";

	static const char* STR_NAMESPACE = "ERR_EXCHANGE_GOODS";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_NOT_ITEM_ID
	,STR_RES_NOT_ENOUGH
	,STR_NUM_NOT_ENOUGH
	,STR_BAG_IS_FULL
	};
}

namespace ERR_ENCHANT 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "��ħ����δ����";

	static const unsigned int ID_REACH_MAX_LEVEL_ERR = 2;
	static const char* STR_REACH_MAX_LEVEL_ERR = "��ħ�Ѵﵽ���ȼ�";

	static const unsigned int ID_NOT_EQUIP_ERR = 3;
	static const char* STR_NOT_EQUIP_ERR = "�ȴ��ϸ�װ�����ܸ�ħ";

	static const unsigned int ID_NOT_EXIST_ERR = 4;
	static const char* STR_NOT_EXIST_ERR = "װ��������";

	static const unsigned int ID_LEVEL_ERR = 5;
	static const char* STR_LEVEL_ERR = "����ȼ�����ֻ������һ����ʮ��";

	static const unsigned int ID_CANNOT_GREATER_THAN_PLAYER_LV = 6;
	static const char* STR_CANNOT_GREATER_THAN_PLAYER_LV = "��ҵȼ����㣨������ÿ����һ���ɻ��һ�θ�ħ���ᣩ";

	static const unsigned int ID_ENCHANT_STONE_NOT_ENOUGH = 7;
	static const char* STR_ENCHANT_STONE_NOT_ENOUGH = "��ħʯ����";

	static const unsigned int ID_NOT_FLY_EQUIP = 8;
	static const char* STR_NOT_FLY_EQUIP = "ֻ���⴫װ�����ܸ�ħ";

	static const unsigned int ID_NOT_FLY = 9;
	static const char* STR_NOT_FLY = "����֮����ܸ�ħ";

	static const unsigned int ID_STRENGTHEN_LV_NOT_ENOUGH = 10;
	static const char* STR_STRENGTHEN_LV_NOT_ENOUGH = "װ��ǿ���ȼ����㣬����ǿ���ٸ�ħ";

	static const char* STR_NAMESPACE = "ERR_ENCHANT";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_REACH_MAX_LEVEL_ERR
	,STR_NOT_EQUIP_ERR
	,STR_NOT_EXIST_ERR
	,STR_LEVEL_ERR
	,STR_CANNOT_GREATER_THAN_PLAYER_LV
	,STR_ENCHANT_STONE_NOT_ENOUGH
	,STR_NOT_FLY_EQUIP
	,STR_NOT_FLY
	,STR_STRENGTHEN_LV_NOT_ENOUGH
	};
}

namespace ERR_EQUIP_MAKE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "�⴫װ����������δ����";

	static const unsigned int ID_MATERIAL_NOT_ENOUGH = 2;
	static const char* STR_MATERIAL_NOT_ENOUGH = "���ϲ��㣬�޷�����";

	static const unsigned int ID_EQUIP_NOT_ENOUGH = 3;
	static const char* STR_EQUIP_NOT_ENOUGH = "ȱ������װ�����޷�����";

	static const unsigned int ID_BOOK_NOT_EXIST = 4;
	static const char* STR_BOOK_NOT_EXIST = "���������ڣ������´򿪱����";

	static const unsigned int ID_VIP_LEVEL_NOT_ENOUGH = 5;
	static const char* STR_VIP_LEVEL_NOT_ENOUGH = "VIP�ȼ����㣬�޷�ʹ�ò�����Ϲ���";

	static const unsigned int ID_BAG_FULL = 6;
	static const char* STR_BAG_FULL = "���������޷�����������������";

	static const char* STR_NAMESPACE = "ERR_EQUIP_MAKE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_MATERIAL_NOT_ENOUGH
	,STR_EQUIP_NOT_ENOUGH
	,STR_BOOK_NOT_EXIST
	,STR_VIP_LEVEL_NOT_ENOUGH
	,STR_BAG_FULL
	};
}

namespace ERR_OPEN_EQUIP_MAKE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "�⴫װ����������δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_EQUIP_MAKE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_UPGRADE_HERO 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "�����׹���δ����";

	static const unsigned int ID_NOT_FLY = 2;
	static const char* STR_NOT_FLY = "���Ƿ���֮��ſɽ���";

	static const unsigned int ID_NOT_UPGRADABLE = 3;
	static const char* STR_NOT_UPGRADABLE = "��������ļ�û����ܽ���";

	static const unsigned int ID_MATERIAL_NOT_ENOUGH = 4;
	static const char* STR_MATERIAL_NOT_ENOUGH = "���ϲ��㣬�޷�����";

	static const unsigned int ID_NOT_PASS_OUTBOUND = 5;
	static const char* STR_NOT_PASS_OUTBOUND = "�û�������ͨ�ض�Ӧ���⴫�ſɽ���";

	static const unsigned int ID_NOT_FOUND_HERO = 6;
	static const char* STR_NOT_FOUND_HERO = "�Ҳ����û�飬�޷�����";

	static const char* STR_NAMESPACE = "ERR_UPGRADE_HERO";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_NOT_FLY
	,STR_NOT_UPGRADABLE
	,STR_MATERIAL_NOT_ENOUGH
	,STR_NOT_PASS_OUTBOUND
	,STR_NOT_FOUND_HERO
	};
}

namespace ERR_OPEN_FLY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "��������δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_FLY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	};
}

namespace ERR_FLY 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_UNOPEN = 1;
	static const char* STR_IS_UNOPEN = "��������δ����";

	static const unsigned int ID_COACH_NOT_FLY = 2;
	static const char* STR_COACH_NOT_FLY = "���Ƿ�������ܷ���";

	static const unsigned int ID_LEVEL_ERR = 3;
	static const char* STR_LEVEL_ERR = "�ȼ����㣬�޷�����";

	static const unsigned int ID_JINGJIE_LEVEL_ERR = 4;
	static const char* STR_JINGJIE_LEVEL_ERR = "����ȼ����㣬�޷�����";

	static const unsigned int ID_MATERIAL_NOT_ENOUGH = 5;
	static const char* STR_MATERIAL_NOT_ENOUGH = "�������ϲ��㣬�޷�����";

	static const unsigned int ID_EXP_NOT_ENOUGH = 6;
	static const char* STR_EXP_NOT_ENOUGH = "�����������ֵ�ſɷ���";

	static const char* STR_NAMESPACE = "ERR_FLY";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_UNOPEN
	,STR_COACH_NOT_FLY
	,STR_LEVEL_ERR
	,STR_JINGJIE_LEVEL_ERR
	,STR_MATERIAL_NOT_ENOUGH
	,STR_EXP_NOT_ENOUGH
	};
}

namespace ERR_OPEN_PET_RULE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_PET_RULE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	};
}

namespace ERR_PLAYER_INFO_PET 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_NOT_OPEN = 1;
	static const char* STR_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_PLAYER_INFO_PET";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_NOT_OPEN
	};
}

namespace ERR_OPEN_SOUL_UPDATE_TYPE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_NOT_EXIST_SOUL = 2;
	static const char* STR_NOT_EXIST_SOUL = "��ս�꿨������";

	static const char* STR_NAMESPACE = "ERR_OPEN_SOUL_UPDATE_TYPE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_NOT_EXIST_SOUL
	};
}

namespace ERR_SOUL_UPDATE_TYPE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_NOT_EXIST_SOUL = 2;
	static const char* STR_NOT_EXIST_SOUL = "��ս�꿨������";

	static const unsigned int ID_ITEM_NOT_ENOUGH = 3;
	static const char* STR_ITEM_NOT_ENOUGH = "��Ʒ������ϲ���";

	static const unsigned int ID_MAX_POTENCY = 4;
	static const char* STR_MAX_POTENCY = "�Ѿ����������Ʒ���޷��ٷ�����";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 5;
	static const char* STR_LEVEL_NOT_ENOUGH = "Ŀǰս��ȼ������Լ�����Ʒ";

	static const char* STR_NAMESPACE = "ERR_SOUL_UPDATE_TYPE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_NOT_EXIST_SOUL
	,STR_ITEM_NOT_ENOUGH
	,STR_MAX_POTENCY
	,STR_LEVEL_NOT_ENOUGH
	};
}

namespace ERR_OPEN_NEIDAN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_NOT_FIND_PET = 2;
	static const char* STR_NOT_FIND_PET = "�Ҳ�����������´�";

	static const char* STR_NAMESPACE = "ERR_OPEN_NEIDAN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_NOT_FIND_PET
	};
}

namespace ERR_DRESS_NEIDAN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_BAG_IS_FULL = 2;
	static const char* STR_BAG_IS_FULL = "�ڵ���������";

	static const unsigned int ID_NOT_FIND_PET = 3;
	static const char* STR_NOT_FIND_PET = "�Ҳ�����������´�";

	static const unsigned int ID_NOT_FIND_NEIDAN = 4;
	static const char* STR_NOT_FIND_NEIDAN = "�Ҳ����ڵ��������´�";

	static const char* STR_NAMESPACE = "ERR_DRESS_NEIDAN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_BAG_IS_FULL
	,STR_NOT_FIND_PET
	,STR_NOT_FIND_NEIDAN
	};
}

namespace ERR_UPDATA_NEIDAN 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_NOT_FIND_NEIDAN = 2;
	static const char* STR_NOT_FIND_NEIDAN = "�Ҳ����ڵ��������´�";

	static const char* STR_NAMESPACE = "ERR_UPDATA_NEIDAN";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_NOT_FIND_NEIDAN
	};
}

namespace ERR_OPEN_NEIDAN_ALL_INSTANCE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_OPEN_NEIDAN_ALL_INSTANCE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	};
}

namespace ERR_NEIDAN_BATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const unsigned int ID_PREVIOUS_INSTANCE_NOT_PASS = 2;
	static const char* STR_PREVIOUS_INSTANCE_NOT_PASS = "����ͨ��ǰ��ĸ���";

	static const unsigned int ID_LEVEL_NOT_ENOUGH = 3;
	static const char* STR_LEVEL_NOT_ENOUGH = "�ȼ���������ս�ø���";

	static const unsigned int ID_NOT_TIME_BATTLE_NUM = 4;
	static const char* STR_NOT_TIME_BATTLE_NUM = "����������ս����������������";

	static const unsigned int ID_NOT_MONSTER_CONFIG = 5;
	static const char* STR_NOT_MONSTER_CONFIG = "�Ҳ�������";

	static const char* STR_NAMESPACE = "ERR_NEIDAN_BATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	,STR_PREVIOUS_INSTANCE_NOT_PASS
	,STR_LEVEL_NOT_ENOUGH
	,STR_NOT_TIME_BATTLE_NUM
	,STR_NOT_MONSTER_CONFIG
	};
}

namespace ERR_RECV_NEIDAN_AWARD 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_RECV_NEIDAN_AWARD";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	};
}

namespace ERR_SKIP_NEIDAN_BATTLE 
{
	static const unsigned int ID_SUCCESS = 0;
	static const char* STR_SUCCESS = "�����ɹ�";

	static const unsigned int ID_IS_NOT_OPEN = 1;
	static const char* STR_IS_NOT_OPEN = "����δ����";

	static const char* STR_NAMESPACE = "ERR_SKIP_NEIDAN_BATTLE";
	static void func(){ const char * psz = STR_NAMESPACE; psz = psz;}

	static const char* ErrMsg[] = {
	STR_SUCCESS
	,STR_IS_NOT_OPEN
	};
}

#endif
