///<------------------------------------------------------------------------------
//< @file:   logic\gvg\gvgdef.h
//< @author: hongkunan
//< @date:   2014��1��23�� 9:44:23
//< @brief:  ���ɿ��ս��ͨ�ö���
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvgdef_h_
#define _gvgdef_h_

#include "commondef.h"
#include "protocol/server/protocommondata.h"
#include <map>
#include <set>
#include <vector>
#include "logic/base/basedefine.h"
#include <string>

// ǰ������
class CPKFaction;
class CPKZone;
class CGvGArena;
class CZvZYard;
class CZvvZYard;
class CZvZvZvZYard;
class CGvGPullGroup;
class CPullPlayer;
class CPlayer;
class CPullGroup;
class CFaction;

struct SGvGVideo;

// �Զ�������
typedef UINT32 GroupID;  // ��ID
typedef UINT32 PlayerID; // ���ID
typedef UINT32 ZoneID;   // ��ID

typedef UINT16 ArenaID; // ���ɿ��ս��̨ID
typedef UINT64 VideoID;

typedef std::set<VideoID> VideoIDSet;
typedef std::vector<DT_GVG_PK_VIDEO> SPvPVideoVec;
typedef std::map<UINT16, DT_GVG_PK_VIDEO> SPvPVideoMap; // ���ɶ�ս�е����¼��map���� = ������ֵ = ¼������

typedef std::map<ZoneID, ArenaID> Zone2ArenaMap;

typedef std::map<ZoneID, CPKZone*> CPKZoneMap;
typedef std::map<UINT32, CPKFaction*> CPKFactionMap; // key = ����ID

typedef std::vector<CPKZone*> PKZoneVec;

typedef std::vector<CPlayer*> CPlayerVec;
typedef std::set<PlayerID> CPlayerIDSet;
typedef std::map<PlayerID, ZoneID> Player2ZoneMap;

typedef std::map<ZoneID, CPlayerIDSet> ZoneToPlayersMap;

typedef std::vector<CGvGArena*> CGvGArenaVec;

typedef std::map<PlayerID, CPullPlayer*> CPullPlayerMap;    // ��ս����б�
typedef std::map<GroupID, CPullGroup*> CPullGroupMap;       // ����vs������map

typedef std::vector<CFaction*> CFactionVec; // �����б�

typedef std::vector<UINT32> FactionIDVec; // ����ID�б�
typedef std::map<ZoneID, FactionIDVec> ZoneID2FactionIDMap; // �洢��Ӧ��������id�б�

typedef std::map<UINT32, UINT32> FactionSupportMap; // �� = ����ID, ֵ = δͬ�������ս�������ĸ�����Ѻע��

typedef std::set<UINT32> FactionIDSet; // ����ID�б�
typedef std::map<UINT32, FactionIDSet> EachZoneFactionIDListMap; // ���������б��� = ��ID��ֵ = ��Ӧ��������ID�б�

typedef std::map<UINT8, ZoneIDVec> GroupZoneIDMap; // key = ��ID, value = �����Ӧ�����б�

// ���ս���
enum EPullGroupType
{
    EPullType_GvG = 1, // ��ȡ�������gvg��̭��
    EPullType_PvP = 2, // ��ȡ�������pvp
};

// ��ǰ���ս�����ĸ��׶�
enum GVG_STAGE
{
    GVG_0_NOT_START = 0,     // δ�����׶�

    // ��һ�֣���������
    GVG_1_APPLY,             // �����׶�

    // �ڶ��֣�������һ�֣��������ƴ��
	GVG_2_MONEY,			 // ��ʼ������ƴ�׶�

    // �����֣������ڶ��֣����ɴ��Ҷ���
    GVG_3_CHAOS_WAR_BEGIN,   // �������ɴ��Ҷ��׶�
    GVG_3_CHAOS_WAR_END,     // ���ɴ��Ҷ��ѽ������������

    // �����֣�˫��16��8��̭��
    GVG_4_16_TO_8_BEGIN,     // ����16��8��̭���׶�
    GVG_4_16_TO_8_GO,        // ������ڲ���ʼ����16��8��̭�����㣨��ʼ��ֹ����
    GVG_4_16_TO_8_END,       // ����16��8��ʤ����

    // �����֣�˫��8��4��̭��
    GVG_5_8_TO_4_BEGIN,      // ����8��4��̭���׶�
    GVG_5_8_TO_4_GO,         // ������ڲ���ʼ����8��4��̭�����㣨��ʼ��ֹ����
    GVG_5_8_TO_4_END,        // ����8��4��ʤ����

    // �����֣��ķ������ܾ���
    GVG_6_FINAL_WAR_BEGIN,   // �����ķ������ܾ����׶�
    GVG_6_FINAL_WAR_GO,      // ��ʼ����4������������ʼ��ֹ����

    GVG_7_END,               // ���ο��ս�ѽ���
    GVG_8_SLEEPING,          // ������һ������߽׶�
    GVG_STAGE_MAX
};

// ���ɺ����ɵĶ�ս���
enum GvGResult
{
    GR_NOT_START, // δ��ʼ
    GR_LEFT_WIN,  // �������Ӯ
    GR_RIGHT_WIN, // �ұ�����Ӯ
    GR_NO_ENEMY   // �ֿ�
};

namespace gvgutil
{
    // ��ȡָ���׶ζ�Ӧ���ִ�
    GvGRound Stage2Round(GVG_STAGE eStage);

    // ��ȡ��һ�׶�
    GVG_STAGE GetNextStage(GVG_STAGE);

    // ����ָ���ִε�����ս��
    DT_FACTION_GVG_SINGLE_LOG* FindGvGLog(DT_FACTION_GVG_LOG_LIST &stLogList, DT_GVG_ROUND &stRound);

    // ��ȡ������賿0�㣬��λ����
    UINT64 GetTodayZero();

    // �������Ż�ȡ��������˫����ս��ID
    BYTE GetGroupIDByZone(ZoneID zoneID, const DT_GROUP_ZONE_ID_LIST &stGroupZoneIDList);

    // �������ʱ��ת��<ʱ:��:��>�ĸ�ʽ���紫��3701���򷵻�<01:00:01>
    std::string TimeToDayHourMinuteSec(UINT32 dwTime);
}

#endif //_gvgdef_h_