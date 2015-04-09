

#ifndef _DBSQLSTRING_H_
#define _DBSQLSTRING_H_

#pragma once

//������indexmgr����������
//���������ڶ�λ���²�������ݵ�ID
enum EIndexKind
{
	INDEX_EQUIP = 1,//װ��
	INDEX_GOODS = 2,//��Ʒ
	INDEX_BOX = 3,//����
	INDEX_SCIENCEATTR = 4,//�Ƽ�����
};

///////////////////////////////////////////��ȡ/////////////////////////////////////////////
/// ��ȡ�����Ϣ
/*
#define SQL_READ_GET_PLAYER_DATA_BY_USERNAME_STRING "select * from player "\
	" where UserName = '%s'"
#define SQL_READ_GET_PLAYER_DATA_BY_DEVICEID_STRING "select * from player "\
	" where DeviceID = '%s'"
	*/
#define SQL_READ_GET_PLAYER_DATA_BY_PLAYERID_STRING "select * from player "\
	" where ID = '%u'"

/// ��ȡ��Ҽ�����Ϣ
#define SQL_READ_GET_PLAYER_SKILL_DATA_STRING "select * from skill "\
	" where PlayerID = '%u' and DeleteFlag = '0'"

/// ��ȡ�佫��Ϣ
#define SQL_READ_GET_HERO_DATA_STRING "select * from hero "\
	" where PlayerID = '%u' and DeleteFlag = '0'"

/// ��ȡ�佫װ����Ϣ
#define SQL_READ_GET_HERO_EQUIP_DATA_STRING "select * from equip "\
	" where PlayerID = '%u' and HeroID = '%u' and DeleteFlag = '0' order by BagPos"

/// ��ȡ��ұ�����Ϣ
#define SQL_READ_GET_PALYER_BAG_DATA_STRING "select * from bag "\
	" where PlayerID = '%u' and DeleteFlag = '0'"

/// ��ȡ��ұ���װ����Ϣ
#define SQL_READ_GET_PALYER_BAG_EQUIP_ITEM_DATA_STRING "select * from equip "\
	" where PlayerID = '%u' and HeroID = '0' and DeleteFlag = '0'  order by BagPos"

/// ��ȡ��ұ�����Ʒ��Ϣ
#define SQL_READ_GET_PALYER_BAG_GOODS_ITEM_DATA_STRING "select * from goods "\
	" where PlayerID = '%u' and DeleteFlag = '0'  order by BagPos"

/// ��ȡ��ұ���������Ϣ
#define SQL_READ_GET_PALYER_BAG_BOX_ITEM_DATA_STRING "select * from box "\
	" where PlayerID = '%u' and DeleteFlag = '0'  order by BagPos"

/// ��ȡ��ҽ�����Ϣ
#define SQL_READ_GET_PALYER_BUILD_DATA_STRING "select * from build "\
	" where PlayerID = '%u' and DeleteFlag = '0' order by Sort"

/// ��ȡ��Ҹ�����Ϣ
#define SQL_READ_GET_PALYER_CURINSTANCE_DATA_STRING "select * from curinstance "\
	" where PlayerID = '%u'"
/// ��ȡ��ҵ�ǰ�����ͨ������Ϣ
#define SQL_READ_GET_PALYER_MAX_COMMON_INSTANCEID_DATA_STRING "select SceneIndex, TownIndex, InstanceIndex from instancerecord "\
	" where PlayerID='%u' and SceneIndex = '1' order by TownIndex DESC, InstanceIndex DESC limit 1 "
/// ��ȡ��ҵ�ǰ���Ӣ������Ϣ
#define SQL_READ_GET_PALYER_MAX_ELITE_INSTANCEID_DATA_STRING "select SceneIndex, TownIndex, InstanceIndex from instancerecord "\
	" where PlayerID='%u' and SceneIndex = '2' order by TownIndex DESC, InstanceIndex DESC limit 1 "

/// ��ȡ��ҽ�����Ϣ
#define SQL_READ_GET_PLAYER_SCIENCE_ATTREXT_STRING "select * from scienceattr "\
	" where PlayerID = '%u'"

/// ��ȡ���������Ϣ
#define SQL_READ_GET_PLAYER_TASK_STRING "select * from curtask "\
	" where PlayerID = '%u' order by TaskLine"

/// ��ȡ��Ҿ�����Ϣ
#define SQL_READ_GET_PLAYER_RACE_STRING "select * from race "\
	" where PlayerID = '%u'"

/// ��ȡ���λ����Ϣ
#define SQL_READ_GET_PLAYER_LOCALE_STRING "select * from locale "\
	" where PlayerID = '%u'"

/// ��ȡ�佫��ҩ��Ϣ
#define SQL_READ_GET_HERO_DRUG_DATA_STRING "select * from drug "\
	" where PlayerID = '%u' and HeroID = '%u' and DeleteFlag = '0' order by Level"

/// ��ȡ���״̬��Ϣ
#define SQL_READ_GET_PLAYER_STATE_STRING "select * from curstate "\
	" where PlayerID = '%u'"

//////////////////////////////////////����//////////////////////////////////////////////////
/// ���������Ϣ

#define SQL_UPDATE_PLAYER_DATA_STRING "update player set DispName='%s', Coin='%u', Gold='%u' "\
	", PhyStrength = '%u', LastPhyStrengthRefreshTime = '%lld', UpdateTime = now() "\
	" where UserName = '%s' and DeviceID = '%s' and ID = '%u'"


#define SQL_UPDATE_PLAYER_BASE_DATA_STRING "update player set DispName='%s', Coin='%lld', Gold='%lld' "\
	", PhyStrength = '%u', Science = '%lld' "\
	", GuideRecord = '%lld', SkillGrade='%u', OpenDefenseSkillFlag='%u', UpdateTime = now() "\
	" where ID = '%u'"


/// ������Ҽ�����Ϣ
#define SQL_UPDATE_PLAYER_SKILL_DATA_STRING "update skill set Level = '%u', UpdateTime = now() "\
	" where PlayerID = '%u' and DeleteFlag = '0' and ID = '%u'"

/// �����佫��Ϣ
#define SQL_UPDATE_HERO_DATA_STRING "update hero set Pos = '%u', FormationIdx = '%u', Level = '%u', Talent = '%u', Experience = '%u'"\
	", HP = '%u', Attack = '%u', HitRate='%u',DodgeRate='%u',CritRate='%u',DeCritRate='%u', RecuitedFlag='%u', VisitNum='%u', UpdateTime = now() "\
	" where PlayerID = '%u' and DeleteFlag = '0' and KindID = '%u'"

/// ������ұ�����Ϣ
#define SQL_UPDATE_PALYER_BAG_DATA_STRING "update bag set OpenNum = '%u', UpdateTime = now() "\
	" where DeleteFlag = '0' and PlayerID = '%u'"

/// �������װ����Ϣ
#define SQL_UPDATE_PALYER_EQUIP_DATA_STRING "update equip set HeroID = '%u', Level='%u', BagPos='%u', UpdateTime = now() "\
	" where PlayerID = '%u' and DeleteFlag = '0' and KindID = '%u' and Idx = '%u'"

/// ���������Ʒ��Ϣ
#define SQL_UPDATE_PALYER_GOODS_DATA_STRING "update goods set PileCount = '%u', LastUseTime = '%lld', BagPos='%u', UpdateTime = now() "\
	" where PlayerID = '%u' and DeleteFlag = '0' and KindID = '%u'"

/// ������ұ�����Ϣ
#define SQL_UPDATE_PALYER_BOX_DATA_STRING "update box set PileCount = '%u', BagKind='%u', BagPos='%u', UpdateTime = now() "\
	" where PlayerID = '%u' and DeleteFlag = '0' and KindID = '%u' and Idx='%u'"

/// ������ҽ�����Ϣ
#define SQL_UPDATE_PALYER_BUILD_DATA_STRING "update build set Level = '%u', Value1 = '%lld', Value2 = '%u', Sort = '%u', FunctionRecord = '%u', UpdateTime = now() "\
	" where PlayerID = '%u' and DeleteFlag = '0' and KindID = '%u'"

/// ������Ҿ�����Ϣ
#define SQL_UPDATE_PALYER_RACE_DATA_STRING "update race set Rank = '%u', ContiWin = '%u', RecvEncourageTime = '%lld', LastChallTime = '%lld', ChallTimes = '%u', ClrCDFlag='%u', UnreadBattleLogNum='%u', RecvEncourageRank='%u', UpdateTime = now() "\
	" where PlayerID = '%u'"

/////////////////////////////����///////////////////////////////////////////////////////////
/// ���������Ϣ
#define SQL_ADD_PLAYER_DATA_STRING "insert into player (ID, UserName,DeviceID,NotifyID,DispName,Coin,Gold,PhyStrength, CreateTime) values( "\
	" '%u','%s', '%s', '%s', '%s', '%lld', '%lld', '%u', now())"

/// ������Ҽ�����Ϣ
#define SQL_ADD_PLAYER_SKILL_DATA_STRING "insert into skill (PlayerID,KindID,Level, DeleteFlag, CreateTime) values( "\
	" '%u', '%u', '%u', '0', now())"

/// �����佫��Ϣ
#define SQL_ADD_HERO_DATA_STRING "insert into hero (PlayerID,Coach,KindID,Pos,FormationIdx,Level,Talent,Experience"\
	",HP,Attack,HitRate,DodgeRate,CritRate,DeCritRate, RecuitedFlag, VisitNum, DeleteFlag, CreateTime) values( "\
	"'%u', '%u', '%u','%u', '%u', '%u', '%u','%u'"\
	",'%u', '%u', '%u', '%u', '%u', '%u','%u', '%u', '0', now())"

/// ������ұ�����Ϣ
#define SQL_ADD_PALYER_BAG_DATA_STRING "insert into bag (PlayerID,OpenNum, DeleteFlag, CreateTime) values( "\
	"'%u', '%u', '0', now())"

/// �������װ����Ϣ
#define SQL_ADD_PALYER_EQUIP_DATA_STRING "insert into equip (PlayerID,HeroID,KindID,Idx,Level, BagPos, ItemNewTime, DeleteFlag, CreateTime) values( "\
	"'%u', '%u', '%u', '%u', '%u', '%u', '%lld', '0', now())"

/// ���������Ʒ��Ϣ
#define SQL_ADD_PALYER_GOODS_DATA_STRING "insert into goods (PlayerID,KindID,PileCount,LastUseTime, BagPos, ItemNewTime, DeleteFlag, CreateTime) values( "\
	"'%u', '%u','%u', '%lld', '%u', '%lld', '0', now())"

/// ������ұ�����Ϣ
#define SQL_ADD_PALYER_BOX_DATA_STRING "insert into box (PlayerID,KindID, Idx, BagKind, PileCount, BagPos, ItemNewTime, DeleteFlag, CreateTime) values( "\
	"'%u', '%u', '%u', '%u', '%u', '%u', '%lld', '0', now())"

/// ������ҽ�����Ϣ
#define SQL_ADD_PALYER_BUILD_DATA_STRING "insert into build (PlayerID,KindID,Level,Value1,Value2,Sort, FunctionRecord, DeleteFlag, CreateTime) values( "\
	"'%u', '%u', '%u','%lld', '%u', '%u', '%u', '0', now())"

/// ������Ҹ�����Ϣ
#define SQL_ADD_PALYER_INSTANCE_DATA_STRING "insert into instance (PlayerID,InstanceIndexA,InstanceIndexB,InstanceIndexC,EnterTimesA, EnterTimesB, EnterTimesC, CreateTime) values( "\
	"'%u', '%s', '%s','%s', '%u', '%u','%u',now())"

/// �������������Ϣ
#define SQL_ADD_PALYER_TASK_DATA_STRING "insert into curtask (PlayerID,TaskLine,TaskIdx,TaskState,StateUpdateTime, TaskConditonType, FinishContitionRecord,CreateTime) values( "\
	"'%u', '%u', '%u', '%u', '%lld', '%u','%s', now())"

/// ������Ҿ�����Ϣ
#define SQL_ADD_PALYER_RACE_DATA_STRING "insert into race (PlayerID,Rank,ContiWin,RecvEncourageTime,LastChallTime, ChallTimes, ClrCDFlag, UnreadBattleLogNum, RecvEncourageRank, CreateTime) values( "\
	"'%u', '%u', '%u', '%lld', '%lld', '%u','%u', '%u', '%u', now())"

/// ������ҵ�ҩ��Ϣ
#define SQL_ADD_PALYER_DRUG_DATA_STRING "insert into drug (PlayerID,HeroID,Level,Num,CreateTime) values( "\
	"'%u', '%u', '%u', '%u', now())"

/////////////////////////////ɾ��///////////////////////////////////////////////////////////


/// ɾ�����װ����Ϣ
//#define SQL_DEL_PALYER_EQUIP_DATA_STRING "update equip set DeleteFlag = '1', DetelteTime = now() where PlayerID = '%u' and KindID = '%u' and Idx = '%u'"
#define SQL_DEL_PALYER_EQUIP_DATA_STRING "delete from equip where PlayerID = '%u' and KindID = '%u' and Idx = '%u'"

/// ɾ�������Ʒ��Ϣ
//#define SQL_DEL_PALYER_GOODS_DATA_STRING "update goods set DeleteFlag = '1', DetelteTime = now() where PlayerID = '%u' and KindID = '%u' and Idx = '%u'"
#define SQL_DEL_PALYER_GOODS_DATA_STRING "delete from goods where PlayerID = '%u' and KindID = '%u'"



/////////////////////////////xxx///////////////////////////////////////////////////////////

/// ��ȡ��������ս����¼
#define SQL_READ_PALYER_INSTANCE_RECORD_DATA_STRING "select * from instancerecord "\
	" where PlayerID = '%u' order by SceneIndex,TownIndex,InstanceIndex "

/// ��ѯ�Ƿ���ڳ�������ս����¼
#define SQL_QUERY_PALYER_INSTANCE_RECORD_DATA_STRING "select * from instancerecord "\
	" where PlayerID = '%u' and SceneIndex = '%u' and TownIndex = '%u' and InstanceIndex = '%u'" 

/// ��Ӹ���ս����¼
#define SQL_ADD_INSTANCE_RECORD_DATA_STRING "insert into instancerecord(PlayerID, SceneIndex, TownIndex, InstanceIndex, Score, EnterTimes, LastPassTime, CreateTime, UpdateTime)"\
	" values('%u', '%u', '%u', '%u', '%u', '%u', '%lld', now(), now())"

/// ���¸���ս����¼
#define SQL_UPDATE_INSTANCE_RECORD_DATA_STRING "update instancerecord set EnterTimes='%u', Score='%u', LastPassTime='%lld',  UpdateTime=now()"\
	" where PlayerID = '%u' and SceneIndex = '%u' and TownIndex = '%u' and InstanceIndex = '%u'" 

/// ��ӵ�ǰ������¼
#define SQL_ADD_CURINSTANCE_RECORD_DATA_STRING "insert into curinstance(PlayerID, CurSceneIndex, CurTownIndex, CurInstanceIndex, CurBattleIndex, CreateTime, UpdateTime)"\
	" values('%u', '%u', '%u', '%u', '%u', now(), now())"

/// ���µ�ǰ������¼
#define SQL_UPDATE_CURINSTANCE_RECORD_DATA_STRING "update curinstance set CurSceneIndex='%u',CurTownIndex='%u',CurInstanceIndex='%u',CurBattleIndex='%u',UpdateTime=now()"\
	" where PlayerID = '%u'" 

/// ��ӿƼ����Լӳɼ�¼
#define SQL_ADD_SCIENCE_ATTREXT_DATA_STRING "insert into scienceattr(PlayerID, AttrKindID, AttrLevel,CreateTime, UpdateTime)"\
	" values('%u', '%u', '%u', now(), now())"

/// ���¿Ƽ����Լӳ�
#define SQL_UPDATE_SCIENCE_ATTREXT_DATA_STRING "update scienceattr set AttrLevel='%u', UpdateTime=now()"\
	" where PlayerID = '%u' and AttrKindID = '%u'" 

/// ����������Ϣ
#define SQL_UPDATE_TASK_DATA_STRING "update curtask set TaskIdx='%u', StateUpdateTime='%lld',TaskState='%u', TaskConditonType='%u',FinishContitionRecord='%s', UpdateTime=now()"\
	" where PlayerID = '%u' and TaskLine='%u'" 


/// ��ӵ�ǰλ����Ϣ
#define SQL_ADD_LOCALE_DATA_STRING "insert into locale(PlayerID, LocaleType, SceneIndex, TownIndex, InstanceIndex, BattleIndex, CreateTime, UpdateTime)"\
	" values('%u', '%u', '%u', '%u', '%u', '%u', now(), now())"

/// ���µ�ǰλ����Ϣ
#define SQL_UPDATE_LOCALE_DATA_STRING "update locale set LocaleType='%u', SceneIndex='%u',TownIndex='%u', InstanceIndex='%u',BattleIndex='%u', UpdateTime=now()"\
	" where PlayerID = '%u'" 

/// ���µ�ҩ��Ϣ
#define SQL_UPDATE_DRUG_DATA_STRING "update drug set Num='%u', UpdateTime=now()"\
	" where PlayerID = '%u' and HeroID = '%u' and Level = '%u'" 


/// ��ӵ�ǰ״̬��Ϣ
#define SQL_ADD_STATE_DATA_STRING "insert into curstate(PlayerID, InstanceMaxHP, InstanceCurHP, OpenBoxFlag, UpdateTime)"\
	" values('%u', '%u', '%u', '%u', now())"

/// ���µ�ǰ״̬��Ϣ
#define SQL_UPDATE_STATE_DATA_STRING "update curstate set InstanceMaxHP='%u', InstanceCurHP='%u', DoubleExpNum='%u', OpenBoxFlag='%u', UpdateTime=now()"\
	" where PlayerID = '%u'" 


/// ��ȡ���߽�����Ϣ
#define SQL_GET_ONLINE_ENCOURAGE_RECORD_STRING "select * from onlineencouragerecord where PlayerID='%u' "

/// ������߽�����Ϣ
#define SQL_ADD_ONLINE_ENCOURAGE_RECORD_STRING "insert into onlineencouragerecord(PlayerID, RecvDays, LastRecvTime, LastRecvIndex, CreateTime)"\
	" values('%u', 0, 0, 0, now())"

/// �������߽�����Ϣ
#define SQL_UPDATE_ONLINE_ENCOURAGE_RECORD_STRING "update onlineencouragerecord set RecvDays='%u', LastRecvTime='%lld', LastRecvIndex='%u', UpdateTime=now()"\
	" where PlayerID = '%u'" 



/// ��ȡ��¼������Ϣ
#define SQL_GET_LOGIN_ENCOURAGE_RECORD_STRING "select * from loginencouragerecord where PlayerID='%u' "

/// ��ӵ�¼������Ϣ
#define SQL_ADD_LOGIN_ENCOURAGE_RECORD_STRING "insert into loginencouragerecord(PlayerID, KeepDays, LastRecvNum, LastRecvTime, LastSelectIndex, StateFlag, CreateTime)"\
	" values('%u', 0, 0, 0, 0, 0, now())"

/// ���µ�¼������Ϣ
#define SQL_UPDATE_LOGIN_ENCOURAGE_RECORD_STRING "update loginencouragerecord set KeepDays='%u', LastRecvNum='%u', LastRecvTime='%lld', LastSelectIndex='%u', StateFlag = '%u',"\
	" UpdateTime=now() where PlayerID = '%u'" 



/// ��ȡ������ս����Ϣ
#define SQL_GET_RACE_BATTLE_LOG_STRING "select * from racebattlelog where PlayerID='%u' order by ChallengeTime asc"

/// ��Ӿ�����ս����Ϣ
#define SQL_ADD_RACE_BATTLE_LOG_STRING "insert into racebattlelog(PlayerID, Idx, ChallengeFlag, ChallengeTime, EnemyPlayerID, EnemyDispName, Result, BeginChallengeRank, AfterChallengeRank, CreateTime)"\
	" values('%u', '%u', '%u', '%lld', '%u', '%s', '%u', '%u', '%u', now())"

/// ���¾�����ս����Ϣ
#define SQL_UPDATE_RACE_BATTLE_LOG_STRING "update racebattlelog set ChallengeFlag='%u', ChallengeTime='%lld', EnemyPlayerID='%u', EnemyDispName='%s', Result = '%u',"\
	" BeginChallengeRank='%u', AfterChallengeRank='%u', UpdateTime=now() where PlayerID = '%u' and Idx = '%u' " 



/// ��ȡ�Ӷ������Ϣ
#define SQL_GET_PLUNDER_BASE_STRING "select * from plunderbase where PlayerID='%u' "
/// ��ȡ�Ӷ�ս����Ϣ
#define SQL_GET_PLUNDER_BATTLE_LOG_STRING "select * from plunderbattlelog where PlayerID='%u' order by PlunderTime asc"
/// ��ȡ�ӶṤ��λ����Ϣ
#define SQL_GET_PLUNDER_WORK_POS_STRING "select * from plundeworkpos where PlayerID='%u' "
/// ��ȡ�Ӷ��²��Ϣ
#define SQL_GET_PLUNDER_CAPTURE_STRING "select * from plundercapture where PlayerID='%u' "

/// ����Ӷ������Ϣ
#define SQL_ADD_PLUNDER_BASE_STRING "insert into plunderbase(PlayerID, CaptureOwnerPlayerID, BeCaptureTime, ExtPlunderNum, LastRefreashWorkPosTime, LastRefreashWorkPosNum, "\
	" LastPlunderSuccessFlag, LastPlunderTime, LastPlunderNum, CaptureGridNum, UnreadBattleLogNum, ClrCDFlag, CreateTime)"\
	" values('%u', '%u', '%lld', '%u', '%lld', '%u',  '%u', '%lld', '%u', '%u', '%u', '%u',now())"
// �����Ӷ������Ϣ
#define SQL_UPDATE_PLUNDER_BASE_STRING "update plunderbase set CaptureOwnerPlayerID='%u', BeCaptureTime='%lld', ExtPlunderNum='%u', LastRefreashWorkPosTime='%lld', LastRefreashWorkPosNum='%u', "\
	" LastPlunderSuccessFlag='%u', LastPlunderTime='%lld', LastPlunderNum='%u', CaptureGridNum='%u', UnreadBattleLogNum='%u', ClrCDFlag='%u', UpdateTime=now() where PlayerID = '%u'"
/// ����Ӷ�ս����Ϣ
#define SQL_ADD_PLUNDER_BATTLE_LOG_STRING "insert into plunderbattlelog(PlayerID, Idx, PlunderFlag, PlunderTime, ActivePlayerID, PassivePlayerID, CapturePlayerID, "\
	" ActiveDispName, PassiveDispName, CaptureDispName, Result, PlunderCoin, PlunderScience, CreateTime)"\
	" values('%u', '%u', '%u', '%lld', '%u', '%u', '%u', '%s', '%s', '%s', '%u', '%lld', '%lld', now())"
/// �����Ӷ�ս����Ϣ
#define SQL_UPDATE_PLUNDER_BATTLE_LOG_STRING "update plunderbattlelog set PlunderFlag='%u', PlunderTime='%lld', ActivePlayerID='%u', PassivePlayerID='%u', CapturePlayerID='%u', "\
	" ActiveDispName='%s', PassiveDispName='%s', CaptureDispName='%s', Result = '%u', PlunderCoin='%lld', PlunderScience='%lld', "\
	" UpdateTime=now() where PlayerID = '%u' and Idx = '%u' " 
/// ����ӶṤ��λ����Ϣ
#define SQL_ADD_PLUNDER_WORK_POS_STRING "insert into plundeworkpos(PlayerID, WorkPosIdx, CoinPosLevel, SciencePosLevel, WorkCaptureID, NeedWorkTime, HaveWorkTime, StartWorkTime, CreateTime)"\
	" values('%u', '%u', '%u', '%u', '%u', '%u', '%u', '%lld', now())"
/// �����ӶṤ��λ����Ϣ
#define SQL_UPDATE_PLUNDER_WORK_POS_STRING "update plundeworkpos set CoinPosLevel='%u', SciencePosLevel='%u',  WorkCaptureID='%u', NeedWorkTime='%u', HaveWorkTime='%u', StartWorkTime='%lld', "\
	" UpdateTime=now() where PlayerID = '%u' and WorkPosIdx = '%u' " 
/// ����Ӷ��²��Ϣ
#define SQL_ADD_PLUNDER_CAPTURE_STRING "insert into plundercapture(PlayerID, CapturePlayerID, CaptureTime, ReleaseFlag, ReleaseTime, WorkPosIdx, CreateTime)"\
	" values('%u', '%u', '%lld', '%u', '%lld', '%u', now())"
/// �����Ӷ��²��Ϣ
#define SQL_UPDATE_PLUNDER_CAPTURE_STRING "update plundercapture set CaptureTime='%lld', ReleaseFlag='%u', ReleaseTime='%lld', WorkPosIdx='%u', "\
	" UpdateTime=now() where PlayerID = '%u' and CapturePlayerID='%u' " 
/// �����²��Ϣ
#define SQL_DELETE_PLUNDER_CAPTURE_STRING "delete from plundercapture where PlayerID = '%u' and CapturePlayerID='%u' " 
/// ����ӶṤ������Ϣ
#define SQL_ADD_PLUNDER_WORK_LOG_STRING "insert into plunderworklog(PlayerID, Idx, WorkFlag, WorkTime, WorkCaptureID, CaptureOwnerID, UpperOwnerID, "\
	" WorkCaptureDispName, CaptureOwnerDispName, UpperOwnerDispName, WorkCoin, HandinCoin, CreateTime)"\
	" values('%u', '%u', '%u', '%lld', '%u', '%u', '%u', '%s', '%s', '%s', '%lld', '%lld', now())"
/// �����Ӷ�ս����Ϣ
#define SQL_UPDATE_PLUNDER_WORK_LOG_STRING "update plunderworklog set WorkFlag='%u', WorkTime='%lld', WorkCaptureID='%u', CaptureOwnerID='%u', UpperOwnerID='%u', "\
	" WorkCaptureDispName='%s', CaptureOwnerDispName='%s', UpperOwnerDispName='%s', PlunderCoin='%lld', PlunderScience='%lld', "\
	" UpdateTime=now() where PlayerID = '%u' and Idx = '%u' " 


/// ��ȡ�����Ϣ
#define SQL_GET_ENEMY_STRING "select * from enemy where PlayerID='%u' order by AddTime asc"
/// ��ӳ����Ϣ
#define SQL_ADD_ENEMY_STRING "insert into enemy(PlayerID, EnemyPlayerID, BattleNum, AddTime, CreateTime)"\
	" values('%u', '%u', '%u', '%lld',now())"
/// ���³����Ϣ
#define SQL_UPDATE_ENEMY_STRING "update enemy set BattleNum='%u', UpdateTime=now() where PlayerID = '%u' and EnemyPlayerID='%u' " 
/// ��������Ϣ
#define SQL_DELETE_ENEMY_STRING "delete from enemy where PlayerID = '%u' and EnemyPlayerID='%u' " 


/// ��ȡҡǮ����Ϣ
#define SQL_GET_MONEYTREE_STRING "select * from moneytree where PlayerID='%u' "
/// ���ҡǮ����Ϣ
#define SQL_ADD_MONEYTREE_STRING "insert into moneytree(PlayerID, RockNum, RockTime, MoodValue, MoodStartTime, CreateTime)"\
	" values('%u', '%u','%lld','%u','%lld',now())"
/// ����ҡǮ����Ϣ
#define SQL_UPDATE_MONEYTREE_STRING "update moneytree set RockNum='%u', RockTime='%lld', MoodValue='%u', MoodStartTime='%lld',"\
	" UpdateTime=now() where PlayerID = '%u'" 


/// ��ȡ�佫������Ϣ
#define SQL_READ_GET_HERO_GODWEAPON_DATA_STRING "select * from godweapon "\
	" where PlayerID = '%u' and HeroKindID = '%u'"
/// ����佫������Ϣ
#define SQL_ADD_HERO_GODWEAPON_STRING "insert into godweapon(PlayerID, HeroKindID, Quality, Level, CreateTime)"\
	" values('%u','%u','%u','%u',now())"
/// �����佫������Ϣ
#define SQL_UPDATE_HERO_GODWEAPON_STRING "update godweapon set Quality='%u', Level='%u', "\
	" UpdateTime=now() where PlayerID = '%u' and HeroKindID='%u' " 
/// ɾ���佫������Ϣ
#define SQL_DELETE_HERO_GODWEAPON_STRING "delete from godweapon where PlayerID = '%u' and HeroKindID='%u' " 



/// ��ȡ��������Ϣ
#define SQL_READ_GET_AWAKEN_DATA_STRING "select * from awaken "\
	" where PlayerID = '%u'"
/// ��ȡ����ĵ���Ϣ
#define SQL_READ_GET_PLAYER_STUDY_DATA_STRING "select * from study "\
	" where PlayerID = '%u' order by HeroKindID"
/// ��ȡ����ĵ���Ƭ��Ϣ
#define SQL_READ_GET_STUDY_CLIP_DATA_STRING "select * from studyclip "\
	" where PlayerID = '%u'"
/// �����������Ϣ
#define SQL_ADD_AWAKEN_STRING "insert into awaken(PlayerID, Level, Auto2ExpFlag, StudyExp, CreateTime)"\
	" values('%u','%u','%u','%lld',now())"
/// ������������Ϣ
#define SQL_UPDATE_AWAKEN_STRING "update awaken set Level='%u', Auto2ExpFlag='%u', StudyExp='%lld' "\
	" UpdateTime=now() where PlayerID = '%u' " 
/// ��������ĵ���Ϣ
#define SQL_ADD_STUDY_DATA_STRING "insert into study (PlayerID, ID, HeroKindID,GridIdx,Kind,Color, Level, CreateTime) values( "\
	"'%u', '%u', '%u', '%u', '%u', '%u', '%u', now())"
///��������ĵ���Ϣ
#define SQL_UPDATE_STUDY_DATA_STRING "update study set HeroKindID='%u',GridIdx='%u',Kind='%u',Color='%u', Level='%u' "\
	" UpdateTime=now() where PlayerID = '%u' and ID='%u' " 
/// ��������ĵ���Ƭ��Ϣ
#define SQL_ADD_STUDYCLIP_DATA_STRING "insert into studyclip (PlayerID, ID, GridIdx,PickupFlag, Color, Num, CreateTime) values( "\
	"'%u', '%u', '%u', '%u', '%u', '%u', now())"
///��������ĵ���Ƭ��Ϣ
#define SQL_UPDATE_STUDYCLIP_DATA_STRING "update studyclip set GridIdx='%u', PickupFlag='%u', Color='%u', Num='%u' "\
	" UpdateTime=now() where PlayerID = '%u' and ID='%u' " 



/// ��ӹһ���Ϣ
#define SQL_ADD_ONHOOK_RECORD_STRING "insert into onhookrecord(PlayerID, SceneIndex, TownIndex, InstanceIndex, LastOnhookResultReqTime, LastOnhookResult, CreateTime)"\
	" values('%u', '%u', '%u', '%u', '%lld', '%s', now())"
/// ���¹һ���Ϣ
#define SQL_UPDATE_ONHOOK_RECORD_STRING "update onhookrecord set SceneIndex='%u', TownIndex='%u', InstanceIndex='%u', LastOnhookResultReqTime='%lld', LastOnhookResult='%s', "\
	" UpdateTime=now() where PlayerID = '%u' " 
/// ��ȡ�һ���Ϣ
#define SQL_GET_ONHOOK_RECORD_STRING "select * from onhookrecord where PlayerID = '%u' " 


/// ��Ӹ���ս����¼��Ϣ��Ϣ
#define SQL_ADD_COMMON_BATTLE_RECORD_STRING "insert into instancebattlerecord(PlayerID, SceneIndex, TownIndex, InstanceIndex, BattleIndex, BattleTime, CreateTime)"\
	" values('%u', 1, 0, 0, 0, 0, now())"
#define SQL_ADD_ELITE_BATTLE_RECORD_STRING "insert into instancebattlerecord(PlayerID, SceneIndex, TownIndex, InstanceIndex, BattleIndex, BattleTime, CreateTime)"\
	" values('%u', 2, 0, 0, 0, 0, now())"
/// ���¸���ս����¼��Ϣ��Ϣ
#define SQL_UPDATE_BATTLE_RECORD_STRING "update instancebattlerecord set TownIndex='%u', InstanceIndex='%u', BattleIndex='%u', BattleTime='%lld', "\
	" UpdateTime=now() where PlayerID = '%u' and SceneIndex = '%u' " 
/// ��ȡ����ս����¼��Ϣ��Ϣ
#define SQL_GET_BATTLE_RECORD_STRING "select * from  instancebattlerecord where PlayerID = '%u' and SceneIndex = '%u' " 

/// ��ȡ��Ҽ�����Ϣ
#define SQL_READ_GET_PLAYER_SKILL_STRING "select * from skill "\
	" where PlayerID = '%u'"
/// ��Ӽ�����Ϣ
#define SQL_ADD_SKILL_STRING "insert into skill(PlayerID, ID, Level, SlotIdx, CreateTime)"\
	" values('%u', '%u', '%u', '%u',now())"
/// ���¼�����Ϣ
#define SQL_UPDATE_SKILL_STRING "update skill set Level='%u', SlotIdx='%u', UpdateTime=now() where PlayerID = '%u' and ID='%u' " 


/// ���������Ϣ
#define SQL_ADD_PHYSTRENGTH_STRING "insert into phystrength(PlayerID, LastPhyStrengthRefreshTime, LastBuyPhyStrengthTime, LastBuyPhyStrengthNum, CreateTime)"\
	" values('%u', 0, 0, 0, now())"

/// ��ȡ������Ϣ
#define SQL_GET_PHYSTRENGTH_STRING "select * from  phystrength where PlayerID = '%u' " 
/// ����������Ϣ
#define SQL_UPDATE_PHYSTRENGTH_STRING "update phystrength set LastPhyStrengthRefreshTime='%lld', LastBuyPhyStrengthTime='%lld', LastBuyPhyStrengthNum='%u', UpdateTime=now()"\
	" where PlayerID = '%u'" 











































#endif //#ifndef _DBSQLSTRING_H_

