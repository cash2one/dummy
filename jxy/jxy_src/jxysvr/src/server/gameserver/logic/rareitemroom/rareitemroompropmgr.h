#ifndef _RAREITEMROOM_PROP_MGR_
#define _RAREITEMROOM_PROP_MGR_

#include <sdtype.h>
#include <logic/base/basedefine.h>
#include <protocol/server/protocligs.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>
#include <map>

using std::map;
using namespace SGDP;
#define MSG_COL_LEN 32

//��Ʒ����
struct SRareItemProp
{
	UINT32 dwKindID;
	UINT32 dwBuyCost;
	UINT32 dwSumDoorsTributeRequire;
	UINT8  byRareItemType; //��Ʒ����(1װ��,2ҩƷ,3��Դ,4����,5����)
	UINT8  byRareItemExchangeRule; //��Ʒ�һ�����(1���� 2���� 3���� 4����)
	UINT8  byBuyNeedLevel;
	SRareItemProp(){memset(this, 0, sizeof(SRareItemProp));}
};

struct SRareItemRoomProp
{
	UINT8 byRareItemGrade;		//��Ʒ��ȼ�
	UINT32 qwUnitedFunds;		//Ҫ�������ʽ�
	SRareItemRoomProp() { memset( this, 0, sizeof(SRareItemRoomProp)); }
};

struct SRareItemNumberInfo
{
	UINT8 byRareItemLevel;
	UINT16 wRareItemID;
	UINT32 dwCurMaxRareItem;
};

typedef multimap<UINT8, SRareItemNumberInfo> CMapRareItemNumber;
typedef CMapRareItemNumber::iterator CMapRareItemNumberItr;
typedef pair<CMapRareItemNumberItr, CMapRareItemNumberItr> CMapRareItemNumberPair;

typedef map<UINT32, SRareItemNumberInfo> UpgradeRareItemMap;
typedef UpgradeRareItemMap::iterator UpgradeRareItemItr;
typedef UpgradeRareItemMap::const_iterator UpgradeRareItemConstItr;

typedef map<UINT32, UpgradeRareItemMap> UpgradeRareItemListMap;
typedef UpgradeRareItemListMap::iterator UpgradeRareItemListItr;

typedef map<UINT32, SRareItemProp> SRareItemPropMap;
typedef map<UINT32, SRareItemProp>::iterator SRareItemPropItr;
typedef map<UINT8, SRareItemRoomProp> SRareItemRoomPropMap;
typedef map<UINT8, SRareItemRoomProp>::iterator SRareItemRoomPropItr; 



//��Ʒ�������
class CRareItemRoomPropMgr: public CBasePopMgr
{

	DECLARE_SINGLETON_PROPMGR( CRareItemRoomPropMgr );
public:
	virtual EConfigModule GetConfigModuleType() { return ECM_RAREITEMROOM; }
	BOOL Init();
	VOID UnInit();
	//��ȡ����
	BOOL GetConfig(SRareItemProp& stRareItem, UINT32 dwRareItemID);
	//��ȡ��Ʒ����
	UINT8 GetRareItemRule(UINT32 dwRareItemID);
	//��ȡ������Ϣ
	BOOL GetUpgradeInfo(UINT32 dwRareItemGrade, UINT32& dwConsumptionMoney);
	const UpgradeRareItemMap* GetRareItemInfoByFaction(UINT32 dwRareItemLevel);

	
public:
	CRareItemRoomPropMgr(){}
	virtual ~CRareItemRoomPropMgr(){}
protected:
	BOOL LoadFromDB();
	BOOL LoadUpgradeInfoFromDB();
	BOOL LoadRareItemNumberFromDB();
	VOID UpdataNumberInfo();
private:
	CMapRareItemNumber m_mapRareItemNumber;


	SRareItemPropMap m_mapRareItemProp;  //����ƷIDΪKEY, ��ǰ��Ʒ��ȼ��µ���Ʒ����
	SRareItemRoomPropMap m_mapRareItemRoomProp;	//����Ʒ��ȼ�ΪKEY, ��ǰ��Ʒ������Ҫ������
	UpgradeRareItemListMap m_mapUpgradeRareItemList; //��һ��MAP����Ʒ��ȼ�ΪKEY,������MAP����ƷIDΪKEY, ����Ʒ��ȼ��µ���Ʒ��������

};



#endif