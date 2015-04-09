#ifndef _BAG_H_
#define _BAG_H_

#include <logic/base/baseobj.h>
#include <sdhashmap.h>
#include "bagpropmgr.h"
#include <logic/item/item.h>
#include <logic/item/equip/equip.h>
#include <logic/item/goods/goods.h>
#include <common/client/commondef.h>
#include <logic/shmem/shmemmap.h>
#include <common/server/utility.h>

typedef HashMap<UINT64, CItem*> CItemMap;
typedef CItemMap::iterator CItemMapItr;

typedef map<UINT16, CItem*> CItemPosMap;//ע�⣬��key������ʹ��map��HashMap��key�����������(8)
typedef CItemPosMap::iterator CItemPosMapItr;

class CGoods;//
class CJewelry;
typedef HashMap<UINT16, CItem*> CKindID2ItemMap;
typedef CKindID2ItemMap::iterator CKindID2ItemMapItr;

typedef CShmemMap<UINT64, CItem> CID2ItemShmemMap;
typedef CShmemMap<UINT16, CItem> CPos2ItemShmemMap;
typedef CShmemMap<UINT32, CEquip> CID2EquipShmemMap;
typedef CShmemMap<UINT16, CGoods> CID2GoodsShmemMap;
typedef CShmemMap<UINT32, CJewelry> CID2JewelryShmemMap;

class CPlayer;
class CBag:public CBaseObj
{
public:
	CBag();
	~CBag();
public:
	//��ʼ����ض���
	BOOL Init(UINT8 byBagOpenNum, CPlayer*	poOwner);
	//��ӵ���,���������ߵ���������ϲ�
	BOOL AddItem(CItem* poItem, BOOL bNewItem = TRUE); //bNewItem�Ƿ������ĵ��ߣ�ע�⣬װ��������ֵΪFALSE��
	//�������
	BOOL DelItem(CItem* poItem, BOOL bDeleteItem = TRUE, CRecordMgr::EDecItemType wRecordType = (CRecordMgr::EDecItemType)0);//bDeleteItem�Ƿ�������ĵ��ߣ�ע�⣬װ��������ֵΪFALSE��
	//�滻����
	BOOL ReplaceItem(CItem* poItem_IN, CItem* poItem_OUT);

	// ɾ����Ʒ
	BOOL DelGoodItem(UINT16 usItemKindID, UINT32 unDelNum);

	// �����Ƿ�����
	BOOL IsBagFull();

	//��������
	UINT16 IncreaseSize(UINT16 wInc2Size, UINT8 byGoldFlag);

	UINT8			GetOpenNum() { return m_byOpenNum; }
	UINT16			GetUsedSize() { return m_mapItem.Size(); }
	UINT16			GetIdleSize();
	CID2ItemShmemMap& GetItemMap() { return m_mapItem; }
    CGoods*			GetGoodsItem(UINT16 wItemKindID);
	CEquip*			GetEquipItem(UINT16 wItemKindID);
	UINT16			GetGoodsPileNum(UINT16 wItemKindID);
	CItem*			GetItem();
	CItem*			GetItem(UINT64 qwMemID);

    CID2GoodsShmemMap& GetGoodsMap() { return m_mapKindID2Goods; }
	CID2EquipShmemMap& GetEquipMap() { return m_mapKindID2Equip; }

	VOID				GetDT_BAG_DATA_CLI(DT_BAG_DATA_CLI& stDT_BAG_DATA_CLI);//��ȡ���ͻ��˵ı���������Ϣ
	VOID				GetDT_BAG_DATA_CLI(DT_BAG_DATA_CLI2& stDT_BAG_DATA_CLI);//��ȡ���ͻ��˵ı���������Ϣ
	VOID				GetDT_EQUIP_DATA_LST_CLI(DT_EQUIP_DATA_LST_CLI& stDT_EQUIP_DATA_LST_CLI);//��ȡ���ͻ��˵ı���װ����Ϣ
    VOID				GetDT_EQUIP_DATA_LST_STRENGTHEN_COMPOSE_CLI(DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI& stDT_EQUIP_DATA_LST_CLI);//��ȡ���ͻ��˵ı���װ����Ϣ
	VOID				GetEquipStrengthenEnchantCli(DT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI &stEquips); //��ȡ���ͻ��˵ı���װ����Ϣ
	VOID				GetDT_GOODS_DATA_LST_CLI(DT_GOODS_DATA_LST_CLI& stDT_GOODS_DATA_LST_CLI);//��ȡ���ͻ��˵ı���װ����Ϣ	
	VOID				GetBagItem(DT_ITEM_DATA_LIST_CLI2& stBagItemInfo);
	VOID				GetBagItem(DT_ITEM_DATA_LIST_CLI3& stBagItemInfo);
	VOID				GetBagItem(DT_ITEM_DATA_LIST_CLI4& stBagItemInfo);
    VOID				GetBagItem(DT_ITEM_DATA_CLI2& stDT_ITEM_DATA_CLI2, UINT16 KindID);
	VOID				GetBagItemNum(DT_ITEM_NUM_DATA_LIST_CLI&);
	VOID				GetXiangqianGemList( DT_ITEM_DATA_LIST_CLI2& stBagItemInfo );
	VOID				GetXiangqianGemList( DT_ITEM_DATA_LIST_CLI3& stBagItemInfo );
	VOID				GetDT_EQUIP_MELT_DATA_LST_CLI(DT_EQUIP_MELT_DATA_LST_CLI& stDT_EQUIP_MELT_DATA_LST_CLI);
	VOID				GetDT_GOOD_MELT_DATA_LST_CLI(DT_GOOD_MELT_DATA_LST_CLI &stDT_GOOD_MELT_DATA_LST_CLI );
	UINT8			GetGoodsCellNum() { return m_mapKindID2Goods.Size(); } //��ȡ��Ʒռ�ø�����
	VOID				GetEquipByPlayerPanel(DT_ITEM_DATA_LIST_CLI3& stItemData);
	VOID				GetEquipByPlayerPanel(DT_ITEM_DATA_LIST_CLI4& stItemData);
	VOID				GetDT_JEWELRY_DATA_LST_CLI(DT_JEWELRY_DATA_LST_CLI& stItemData);
	VOID				GetDT_JEWELRY_DATA_LST_CLI(DT_ITEM_DATA_LIST_CLI3& stItemData);
	VOID				GetAboutJewelryLstCli(DT_ITEM_DATA_LIST_CLI3& stItemData);
	VOID				GetAboutJewelryLstCli(DT_ITEM_DATA_LIST_CLI4& stItemData);
	CID2JewelryShmemMap& GetJewelryMap(){ return m_mapKindID2Jewery; }
	VOID				GetJewelryStrengthInfo(DT_BAG_JEWELRY_STRENGTH_INFO& stIfno);
	//��ȡװ���������Ƕ��ʯ������
	UINT8			GetMaxMosaicGemNum();

	//��ȡ�Ǳ�������װ�� 
	BOOL				HaveEquip();

	
protected:
private:
	UINT8				m_byOpenNum;			//������Ϣ	
	CID2ItemShmemMap		m_mapItem;			//�����еĵ���

	CPos2ItemShmemMap		m_mapItemPos;			//�����еĵ���,��˳�򱣴���ߣ�Ϊ�˸��ͻ��˰�˳���·�
	CID2GoodsShmemMap		m_mapKindID2Goods;	//�����е���Ʒ
	CID2EquipShmemMap		m_mapKindID2Equip;	//�����е�װ��
	CID2JewelryShmemMap		m_mapKindID2Jewery; //�����е���Ʒ
	UINT16				m_wItemPos;			//���ߴ��λ�ã��·����ͻ���ʱ�������·�����λ�ò�������λ�ã���λ��ֻ���ڴ�С�����м���ܻ��п�ȱ
};
DECLARE_CLASS_POOL_MGR(CBag)
#endif

