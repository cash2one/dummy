#ifndef _JEWELRY_H_
#define _JEWELRY_H_

#include <logic/item/item.h>
#include <protocol/server/protocligs.h>

class CHero;
struct SJewelryProp;
struct SJewelryUpgradeProp;

class CJewelry : public CItem
{
public: 
	CJewelry();
	~CJewelry();
public:
	
	CHero* GetHero(){ return m_poHero; }
	VOID SetHero(CHero* poHero);

	virtual UINT8		GetItemKind() { return EIK_JEWELRY; };//����������(װ��/��Ʒ)
	virtual UINT16	GetItemKindID() { return m_stDT_JEWELRY_DATA.wJewelryID; }//����������
	virtual UINT16	GetCurPileNum(){ return 1;} //��ǰ������}
	virtual VOID		AddPileNum(UINT16 wPileNum, CRecordMgr::EAddItemType emOpType) {};//��ӵ�����
	virtual VOID		DecPileNum(UINT16 wPileNum, CRecordMgr::EDecItemType emOpType, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0) {};//ɾ��������	
	virtual UINT16&	GetBagPos();//��ȡ���ߵ��ߴ�ŵı���λ��
	virtual BOOL		Init(VOID* pData, CPlayer* poOwner);//��������ʱInit
	virtual UINT16	Sell(UINT16 wNum, DT_ITEM_NUM_DATA_LIST_CLI &stRecvItemNumList) ;//���۵���
	virtual	void		GetRecoverScience(UINT32 & dwMinScience, UINT32 & dwMaxScience) ;//��������
	DT_JEWELRY_DATA& GetDT_JEWELRY_DATA();

	SJewelryProp* GetProp();
	SJewelryUpgradeProp* GetUpgradeProp();
	UINT8 GetColorType();	//��ȡ��ƷƷ��
	UINT16 GetStrengLevel();	//��ȡǿ���ȼ�
	UINT16 GetDressLevel();	//��ȡ�����ȼ�
	UINT8 GetExtStrengLeftNum();	//ʣ��ǿ������
	BOOL IsCanUpgrade();
	BOOL IsMaxLevel();

    UINT16	GetJewelryIdx() { return m_stDT_JEWELRY_DATA.wIdx; }

	BOOL UnDressBag();
	BOOL DressHero(CHero* poHero);

public:
    static BOOL IsOneHeroAttr(JewelryExtAttr);
    static BOOL IsAllHeroAttr(JewelryExtAttr);

public:
	UINT16 OnStrengExt(UINT8 byExtID, PKT_CLIGS_JEWELRY_EXT_UPGRADE_ACK& stAck);
	UINT16 OnUpgrade(PKT_CLIGS_JEWELRY_STRENGTH_ACK& stAck);
	UINT16 OnOpenJewelryResolve(PKT_CLIGS_OPEN_JEWELRY_RESOLVE_ACK& stAck);
public:
	VOID GetJewelryDataCli(DT_JEWELRY_DATA_CLI& stJewelryCli);	//��ȡ���ͻ�������
	DT_BATTLE_ATTR_LST_INFO& GetBaseAttribute();
	UINT8 ResolveJewelry(DT_GOODS_DATA_LST_CLI& stGoodsCli, UINT32& dwRes);

	BOOL GetJewelryStrength(DT_JEWELRY_DATA_CLI& stCurInfo, DT_JEWELRY_DATA_CLI& stStrengthInfo);
	BOOL GetStrengItemInfo( DT_STRENGTH_INFO& stItemInfo);
protected:
	BOOL UpgradeJewelry();	//������Ʒ
private:
	DT_JEWELRY_DATA		m_stDT_JEWELRY_DATA;//��Ʒ��ǰ��Ϣ
	CHero*				m_poHero;//��δװ������ΪNULL
};

#endif