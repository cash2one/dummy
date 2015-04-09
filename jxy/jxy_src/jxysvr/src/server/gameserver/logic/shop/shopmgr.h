
#ifndef _SHOPMGR_H_
#define _SHOPMGR_H_

#include <sdsingleton.h>
#include <sdtype.h>
#include <sddb.h>
#include <logic/base/basedefine.h>
#include <vector>
#include <logic/base/basepropmgr.h>
#include <protocligs.h>

using namespace SGDP;
using namespace std;

//�̵�tab����
enum EShopTabType
{
	ESTT_INVALID = 0,
	ESTT_HOTSELL = 1,
	ESTT_EQUIP	= 2,
	ESTT_GOODS	= 3,
	ESTT_COIN	= 4,
	ESTT_OTHER	= 5,
	ESTT_PILENUM= 99,//ָ������������.��������
	ESTT_MAX,
};

//�̵���ߵ��������ȼ�
struct SShopPileLevel
{
	UINT16 wPileNum; //���ߵ�����
	UINT16 wRequireLevel; //���߹�����Ҫ�ȼ�
};

struct SShopItemLevel
{
	UINT16 wItemID; //����ID
	UINT16 wPileNum; //���ߵ�����
	UINT16 wRequireLevel; //���߹�����Ҫ�ȼ�
};

//�̵�����·���Ϣ
struct SShopItemCliData
{
	UINT8				byItemNum; //������Ϣ
	DT_ITEM_DATA_SHOP	astItemDataList[MAX_SHOP_ITEM_NUM]; //������Ϣ
};

//
typedef HashMap<UINT32, SShopPileLevel> CKey2PileLevelMap;//keyΪ����ID+������
typedef CKey2PileLevelMap::iterator CKey2PileLevelMapItr;
typedef vector<SShopItemLevel> CItemIDLevelVector;//����ID�ȼ�
typedef CItemIDLevelVector::iterator CItemIDLevelVectorItr;

typedef HashMap<UINT16, UINT16> CKindID2KindIDMap;//keyΪ����ID��valueҲ��keyΪ����ID
typedef CKindID2KindIDMap::iterator CKindID2KindIDMapItr;

typedef HashMap<UINT16, SShopItemCliData> CLevel2ItemCliDataMap;//keyΪ��ҵȼ�
typedef CLevel2ItemCliDataMap::iterator CLevel2ItemCliDataMapItr;

class CPlayer;
class CShopMgr : public CBasePopMgr
{
public:
	DECLARE_SINGLETON_PROPMGR(CShopMgr)

	virtual EConfigModule	GetConfigModuleType() { return ECM_SHOP; }

	BOOL Init();
	VOID UnInit();	
public:
	UINT16 OpenShopByTab(UINT16 wPlayerLevel, UINT8 byTabID, UINT8& byItemNum, DT_ITEM_DATA_SHOP astItemDataList[]);
	UINT16 Buy(CPlayer* poPlayer, UINT8 byTabID, UINT16 wItemKindID, UINT16 wPileCount);
	UINT8  GetTabID(UINT16 wItemKindID, UINT8 & byTabID);
public:
	CShopMgr();
	~CShopMgr();
protected:
	BOOL LoadFromDB();

	BOOL InitShopData();
private:	
	CKey2PileLevelMap		m_amapShopTabProp[ESTT_MAX];	////�̵�����
	CItemIDLevelVector		m_avecShopTabProp[ESTT_MAX];	////�̵�����
	CLevel2ItemCliDataMap	m_amapLevelItemCliData[ESTT_MAX];	////ÿ����ҵȼ����̵�����
	CKindID2KindIDMap		m_mapAllSellItem;				//���еĿ���ĵ���
	CKindID2KindIDMap		m_mapAllSellItemTab;

};



#endif
