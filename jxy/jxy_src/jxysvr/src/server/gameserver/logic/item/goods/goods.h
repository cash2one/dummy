#ifndef _GOODS_H_
#define _GOODS_H_


#include <logic/item/item.h>
#include "goodspropmgr.h"
#include <protocol/server/protocligs.h>


class CGoods:public CItem
{
public:
	CGoods();
	~CGoods();
public:
	virtual UINT8		GetItemKind() { return EIK_GOODS; } ; 
	virtual UINT16	GetItemKindID() { return m_stDT_GOODS_DATA.wKindID; } ;
	virtual UINT16	GetCurPileNum() { return m_stDT_GOODS_DATA.wPileCount; };//��ǰ��������װ��/���������Ϊ1
	virtual VOID		AddPileNum(UINT16 wPileNum,CRecordMgr::EAddItemType emOpType);//��ӵ�����	
	virtual VOID		DecPileNum(UINT16 wPileNum,CRecordMgr::EDecItemType emOpType, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0);//ɾ��������	
	virtual UINT16&	GetBagPos() { return m_stDT_GOODS_DATA.wBagPos; };//��ȡ���ߵ��ߴ�ŵı���λ��
	virtual BOOL		Init(VOID* pData, CPlayer* poOwner);//��������ʱInit
	virtual UINT16	Sell(UINT16 wNum, DT_ITEM_NUM_DATA_LIST_CLI &stRecvItemNumList);//����
	virtual	void		GetRecoverScience(UINT32 & dwMinScience, UINT32 & dwMaxScience);//��������


public:
	const DT_GOODS_DATA&	GetDT_GOODS_DATA() { return m_stDT_GOODS_DATA; }
	UINT16			Use(UINT8& byUseBoxFlag, DT_ITEM_DATA_LIST_CLI2& stBoxItemInfo, UINT16 wUseNum = 1 ); //��Ʒʹ��
	SGoodsProp*		GetGoodsProp();
	VOID				GetDT_GOODS_DATA_CLI(DT_GOODS_DATA_CLI& stDT_GOODS_DATA_CLI);
	UINT8			GetGoodsMainKindID();
	VOID				GetDT_GOOD_MELT_DATA_CLI(DT_GOOD_MELT_DATA_CLI& DT_GOOD_MELT_DATA_CLI);//��ȡװ���������ͻ��˵���Ϣ

	UINT16			Melt(UINT8 byGoldFlag);//��������
protected:
	UINT16			UseByMainKind(UINT8& byUseBoxFlag, DT_ITEM_DATA_LIST_CLI2& stBoxItemInfo, UINT16 wUseNum);
	UINT16			UseBox(DT_ITEM_DATA_LIST_CLI2& stBoxItemInfo);
	UINT16			UseRateBox(DT_ITEM_DATA_LIST_CLI2& stBoxItemInfo);
private:
	DT_GOODS_DATA		m_stDT_GOODS_DATA;//��Ʒ��ǰ��Ϣ

};

#endif
