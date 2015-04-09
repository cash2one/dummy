
#ifndef _BASEDEFINE_H_
#define _BASEDEFINE_H_

#include <sdhashmap.h>
#include <protocol/server/protocommondata.h>
#include <map>
#include <set>

using namespace std;

#define VERSION_GVG_ACTIVITY 312 // �������ս�����İ汾
#define VERSION_SOUL 312         // ս�������İ汾
#define VERSION_FLY 410         // ����ϵͳ�����İ汾
#define VER_PET      402
#define VERSION_PET      402

#define BAG_GIFT_ID 0xFFFFFFFFFFFFFFFF

//���ݱ���״̬������������ݱ���
enum ESaveState
{
	ESS_NON_SAVE = 0 ,//���豣��
	ESS_WANT_SAVE = 1 ,//��Ҫ����
	ESS_SAVEING = 2 ,//������
	//ESS_SAVEING_DIRTY = 3 ,//�������ֱ��޸�
};


//�����˹���
enum ERobotFuncKind
{
	ERFK_PLAYER	=	0,//��ͨ�������
	ERFK_PLUNDER = 1,//�����Ӷ�
	ERFK_RACE = 2,//���ھ�����
	ERFK_OTHER = 99,//����
};


//�����������
#define MAXPHYSTRENGTH	48

typedef HashMap<UINT16, UINT16> CItemKindID2NumMap;//keyΪ����kindid��valueΪ��Ӧ�ĸ���
typedef CItemKindID2NumMap::iterator CItemKindID2NumMapItr;


//���߸���
struct SItemRate
{
	UINT16	wItemNum;//���߸���
	UINT16	wRate;//��������(��ֱ�)
};
typedef HashMap<UINT16, SItemRate> CItemRateMap;//keyΪ����kindid��valueΪSItemRate
typedef CItemRateMap::iterator CItemRateMapItr;


//ȫ����
struct SAllAttrProp
{
	SAllAttrProp()
	{
		memset(&stBattleAttr, 0, sizeof(stBattleAttr));
		memset(&stHideBattleAttr, 0, sizeof(stHideBattleAttr));
		memset(&stExtBattleAttr, 0, sizeof(stExtBattleAttr));
	};

	DT_BATTLE_BASE_ATTRIBUTE			stBattleAttr;
	DT_HIDE_BATTLE_ATTRIBUTE	stHideBattleAttr;
	DT_EXT_BATTLE_ATTRIBUTE		stExtBattleAttr;
};

//���ڼ�¼�ϴ��Ƽ������ID
struct SRecommendPlayerRcd
{
	UINT32 dwPlayerH1;//��1����
	UINT32 dwPlayerE;//��ͬ�ȼ���
	UINT32 dwPlayerL1;//��1����
};


typedef map<UINT32, UINT32> C3232Map;
typedef C3232Map::iterator C3232MapItr;
typedef C3232Map::reverse_iterator C3232MapRitr;

typedef map<UINT16, UINT16> C1616Map;
typedef C1616Map::iterator C1616MapItr;

typedef map<UINT8, UINT8> C88Map;
typedef C88Map::iterator C88MapItr;

typedef multimap<UINT16, UINT16> C1616MultiMap;
typedef C1616MultiMap::iterator C1616MultiMapItr;

typedef vector<UINT32> C32Vec;
typedef C32Vec::iterator C32VecItr;

typedef set<UINT32> C32Set;
typedef C32Set::iterator C32SetItr;

typedef set<UINT64> C64Set;
typedef C64Set::iterator C64SetItr;

typedef set<UINT8> C8Set;
typedef C8Set::iterator C8SetItr;

typedef set<UINT16> C16Set;
typedef C16Set::iterator C16SetItr;

typedef map<string, UINT32> CStr32Map;
typedef CStr32Map::iterator CStr32MapItr;

typedef map<UINT32, C3232Map> C3232MapM;
typedef C3232MapM::iterator C3232MapMItr;
typedef C3232MapM::reverse_iterator C3232MapMIitr;

typedef map<UINT32, UINT64> C3264Map;
typedef C3264Map::iterator C3264MapItr;
typedef C3264Map::reverse_iterator C3264MapRitr;

typedef map<UINT64, UINT64> C6464Map;
typedef C6464Map::iterator C6464MapItr;
typedef C6464Map::reverse_iterator C6464MapRitr;

// ��ID�б�
typedef std::vector<UINT16> ZoneIDVec;
typedef std::set<UINT16> ZoneIDSet;

#endif

