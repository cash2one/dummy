
#ifndef _ITEMMGR_H_
#define _ITEMMGR_H_

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <logic/item/item.h>
//#include <logic/item/box/box.h>
#include <logic/item/equip/equip.h>
#include <logic/item/goods/goods.h>
#include "logic/item/jewelry/jewelry.h"
#include <logic/record/recordmgr.h>
#include <vector>

using namespace std;
using namespace SGDP;

typedef HashMap<UINT64, CItem*> CID2ItemMap;
typedef CID2ItemMap::iterator	CID2ItemMapItr;

typedef vector<CItem*>	CItemVec;
typedef CItemVec::iterator CItemVecItr;


//�������߽��
enum ECreateItemRet
{
    ECIR_SUCCESS = 0,//�����ɹ�
    ECIR_FAILED_BAG_FULL = 1,//������
    ECIR_FAILED_KIND_INVALID = 2,//����������Ч
    ECIR_FAILED_OTHER = 3,//��������
	ECIR_FAILED_HIT = 4,	//δ���б���
	ECIR_COIN_NOT_ENOUGH = 5, //ͭǮ����
};

/**
* @brief ���߹�����
*/
class CItemMgr
{
public:
    DECLARE_SINGLETON(CItemMgr)

    /**
    * @brief
    * ��ʼ������,��ȡ�����ļ���
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL Init();

    /**
    * @brief
    * ж�غ���
    */
    VOID UnInit();

public:

	CItem*  FindItem(UINT32 dwPlayerID, UINT16 wKindID, UINT16 wIdx);
	//CEquip* FindEquip(UINT32 dwPlayerID, UINT16 wKindID, UINT16 wIdx);

    /**
    * @brief
    * �������ߣ������뱳��
    * @param wKindID		: Ҫ�����ĵ�������ID
    * @param wPileNum		: Ҫ�����ĵ��߸���(װ������Ϊ1����Ʒ>=1)����Ʒʱ��Ч
    * @param eRet			: �������
    * @param bGive			: �Ƿ�ϵͳ���ģ���ϵͳ���ı�����ʱ�ӵ���ʱ�����У����򴴽�ʧ��
    * @param wLevel			: Ҫ�����ĵ��ߵȼ�(װ���У���װ��Ĭ�ϳ�ʼ�ȼ�1)
    */
    CItem*			CreateItemIntoBag(CPlayer* poPlayer, UINT16 wKindID, UINT16 wPileNum, ECreateItemRet& eRet, UINT16 wLevel, CRecordMgr::EAddItemType emOpType, UINT64 qwParam2=0, UINT64 qwParam3=0, UINT64 qwParam4=0);
    CItem*			AttachItem(CPlayer* poPlayer, UINT16 wKindID, VOID* pData); //���ݻ�ԭ

    //����װ������ ���뱳��
    CEquip*			CreateEquip(CPlayer* poPlayer, UINT16 wKindID, UINT16 wPileNum, ECreateItemRet& eRet, UINT16 wLevel);
		/**
    * @brief
    * �Ƴ����ߣ��ӹ��������Ƴ�
    * @return VOID
    */
    VOID            RemoveItem(CItem* poItem);

	//ɾ����Ʒ
	VOID            RemoveItem(CItem* poItem, CPlayer* poPlayer, CRecordMgr::EDecItemType eDecType, UINT64 qwParam1 = 0, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0);

    	 /**
    * @brief
    * �������Σ������뱳��
    * @param stDT_JEWELRY_DATA		: Ҫ�����ĵ��ߵ�����
    * @param wPileNum		        : Ҫ�����ĵ��߸���(װ������Ϊ1����Ʒ>=1)����Ʒʱ��Ч
    * @param wRet			        : �������
    */
    CItem*			CreateJewelryIntoBag(CPlayer* poPlayer, DT_JEWELRY_DATA& stDT_JEWELRY_DATA, UINT16 wPileNum,ECreateItemRet& eRet, UINT16 wLevel,  CRecordMgr::EAddItemType emOpType);
	CItem*			CreateJewelryIntoBagByGM(CPlayer* poPlayer, UINT16 wItemID, C32Vec& vec32, ECreateItemRet& eRet );

	// ����������Ʒ
	UINT16			RandomItemInnerBox(UINT16 wKindID);

public:
    UINT8			GetItemKindBYKindID(UINT16 wKindID);
    VOID				GetDT_ITEM_DATA_CLI2(CItem* poItem, DT_ITEM_DATA_CLI2& stDT_ITEM_DATA_CLI2);
    BOOL				GetDT_ITEM_DATA_CLI2(UINT16 wKindID, UINT16 wPileCount, DT_ITEM_DATA_CLI2& stDT_ITEM_DATA_CLI2);
	BOOL				GetDT_ITEM_DATA_CLI3(UINT16 wKindID, UINT16 wPileCount, DT_ITEM_DATA_CLI3& stDT_ITEM_DATA_CLI3);

//////////////////////////////// ���߲���  begin //////////////////////////////////////////
public:
    UINT16			Equip(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byDressType, UINT16 wDressItemKindID, UINT16 wDressItemIdx, UINT16 wUndressItemKindID, UINT16 wUndressItemIdx, DT_POWER_CHANGE_DATA& stHeroPowerInfo); //װ��
	UINT16			QuickEquip(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byEquipNum, DT_EQUIP_ID astEquipIDLst[EQUIP_POS_NUM], DT_POWER_CHANGE_DATA& stHeroPowerInfo);
    UINT16          Strengthen(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT8 byStrengthenType, UINT16 wLevel, 
		                        DT_EQUIP_DATA_STRENGTHEN_CLI& stEquipStrengthenInfo, DT_EQUIP_ENCHANT_DATA_CLI &stEquipEnchantInfo, DT_EQUIP_DATA_CLI &stEquipInfo, UINT32& dwStrengthen10Coin);//ǿ��

    UINT16          Enchant(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT16 wLevel, DT_EQUIP_DATA_STRENGTHEN_CLI& stEquipStrengthenInfo, DT_EQUIP_ENCHANT_DATA_CLI&, DT_EQUIP_DATA_CLI_v410&);//ǿ��

    // װ������
    UINT16          MakeEquip(CPlayer* poPlayer, UINT16 wEquipMakeBookID, UINT16 wBookCnt, BOOL bIsBuyMaterial);

    UINT16			Sell(CPlayer* poPlayer, UINT16 wItemKindID, UINT16 wIdx, UINT16 wNum, DT_ITEM_NUM_DATA_LIST_CLI&);//���۵���
	UINT16			MeltEquip(CPlayer* poPlayer, UINT8 byGoldFlag, UINT16 wItemKindID, UINT16 wIdx);//��������
	UINT16			MeltGood(CPlayer* poPlayer, UINT8 byGoldFlag, UINT16 wItemKindID, UINT16 wNum);//��������

	UINT16			CheckMeltEquip(CPlayer* poPlayer, UINT16 wItemKindID, UINT16 wIdx, UINT32& dwCostGold);//��������
	UINT16			CheckMeltGood(CPlayer* poPlayer, UINT16 wItemKindID, UINT16 wNum, UINT32& dwCostGold);//��������
    UINT16			UseGoods(CPlayer* poPlayer, UINT16 wGoodsKindID, UINT16 wUseNum, UINT8& byUseBoxFlag, DT_ITEM_DATA_LIST_CLI2& stBoxItemInfo);//��Ʒʹ��

	BOOL				CkBagFull(CPlayer* poPlayer, vector<UINT16> vecItemID);//��鱳������vecItemID��Ʒ���Ƿ���(װ��ֻ��1����������Ч)
	BOOL				SysUseGoods(CPlayer* poPlayer, UINT16 wItemID, UINT16 wPileNum);//ϵͳ��æʹ�ã��Ƿ����ʹ�ã�������ʹ����ʹ��
	UINT16			DelItem(CPlayer* poPlayer, UINT16 wItemKindID);//ֱ��ɾ��װ��������GM����
protected:

//////////////////////////////// ���߲���  end //////////////////////////////////////////
protected:
    VOID            RemoveItem(CItemVec& vecItem);

	/**
    * @brief
    * ������Ʒ�������뱳��
    * @param wKindID		: Ҫ�����ĵ�������ID
    * @param wPileNum		: Ҫ�����ĵ��߸���(װ������Ϊ1����Ʒ>=1)����Ʒʱ��Ч
    * @param wRet			: �������
    */
	CItem*			CreateGoodsIntoBag(CPlayer* poPlayer, UINT16 wKindID, UINT16 wPileNum, ECreateItemRet& eRet, CRecordMgr::EAddItemType emOpType, UINT64 qwParam2=0, UINT64 qwParam3=0, UINT64 qwParam4=0);

    /**
    * @brief
    * ����װ���������뱳��
    * @param wKindID		: Ҫ�����ĵ�������ID
    * @param wPileNum		: Ҫ�����ĵ��߸���(װ������Ϊ1����Ʒ>=1)����Ʒʱ��Ч
    * @param wRet			: �������
    */
    CItem*			CreateEquipIntoBag(CPlayer* poPlayer, UINT16 wKindID, UINT16 wPileNum, ECreateItemRet& eRet, UINT16 wLevel,  CRecordMgr::EAddItemType emOpType, UINT64 qwParam2=0, UINT64 qwParam3=0, UINT64 qwParam4=0);

	 /**
    * @brief
    * ����װ���������뱳��
    * @param wKindID		: Ҫ�����ĵ�������ID
    * @param wPileNum		: Ҫ�����ĵ��߸���(װ������Ϊ1����Ʒ>=1)����Ʒʱ��Ч
    * @param wRet			: �������
    */
    CItem*			CreateJewelryIntoBag(CPlayer* poPlayer, UINT16 wKindID, UINT16 wPileNum,ECreateItemRet& eRet, UINT16 wLevel,  CRecordMgr::EAddItemType emOpType);
    //CItem*			CreateBox(CPlayer* poPlayer, UINT16 wKindID, UINT16 wPileNum, ECreateItemRet& eRet, BOOL bGive, UINT16 wLevel);
    UINT16			GetInnerBoxRateKindID(UINT16 wInnerBoxKindID);//��ȡ�ڲ����������������ƷID

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

protected:
    CItemMgr();
    ~CItemMgr();

private:

    CID2ItemMap				m_mapID2Item;
	CSDObjectPool<CEquip, CSDMutex>	m_oEquipShmemObjMgr;
	CSDObjectPool<CGoods, CSDMutex>	m_oGoodsShmemObjMgr;
	CSDObjectPool<CJewelry, CSDMutex>	m_oJewelryShmemObjMgr;
};



#endif //#ifndef _ITEMMGR_H_

