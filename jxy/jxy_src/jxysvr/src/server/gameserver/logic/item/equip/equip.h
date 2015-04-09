#ifndef _EQUIP_H_
#define _EQUIP_H_

#include <logic/item/item.h>
#include "equippropmgr.h"
#include <logic/battle/battleattrobj.h>
#include "logic/base/basedefine.h"
#include "logic/fly/flydef.h"

struct SEquipProperty
{
    SEquipProperty(){ memset(this, 0, sizeof(*this)); }

    DT_EQUIP_DATA *pstEquip;  // װ������
    UINT16 wEnchantLevel; // ��ħ�ȼ�
};

class CHero;
class CEquip:public CItem
{
public:
    typedef std::map<GoodsID, UINT32> EnchantStone2NumMap; // <��ħʯID����Ӧ����>

public:
	CEquip();
	~CEquip();
public:
	virtual UINT8		GetItemKind() { return EIK_EQUIP; } ; 
    virtual UINT16	GetItemKindID() { return m_stDT_EQUIP_DATA.wKindID; }
	virtual UINT16	GetCurPileNum() { return 1; };//��ǰ��������װ��������Ϊ1
	virtual VOID		AddPileNum(UINT16 wPileNum, CRecordMgr::EAddItemType emOpType) {};//װ��������ֻ����1�����ܵ���
	//ɾ��������	
	virtual VOID		DecPileNum(UINT16 wPileNum, CRecordMgr::EDecItemType emOpType, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, UINT64 qwParam4 = 0){};
	virtual UINT16&	GetBagPos() { return m_stDT_EQUIP_DATA.wBagPos; };//��ȡ���ߵ��ߴ�ŵı���λ��
	virtual BOOL		Init(VOID* pData, CPlayer* poOwner);//��������ʱInit
	virtual UINT16	Sell(UINT16 wNum, DT_ITEM_NUM_DATA_LIST_CLI &stRecvItemNumList);//����

    UINT16	GetEquipIdx() { return m_stDT_EQUIP_DATA.wIdx; }

	VOID ClearJewelryAttr();
	VOID AddJewelryAttribute(UINT32 dwKey, UINT32 dwValue);
	VOID GetJewelryAttribute(UINT32& dwHP, UINT32& dwAttack);

public:	
	VOID		SetHero(CHero* poHero); //װ��/ж�±�����ø÷���
	CHero*	GetHero() { return m_poHero; } //װ��/ж�±�����ø÷���
	INT16	Strengthen(UINT8 byStrengthenType, UINT16 wLevel);//ǿ��

    INT16	Enchant(UINT16 wTargetEnchantLevel);//��ħ��ָ���ȼ�

	//UINT16  OpenLight( , ); // װ������ 
	BOOL		Xiangqian( UINT16 wItemID, UINT8 byPos );
	UINT8	GetMosaicGemNum();

	DT_EQUIP_DATA&			GetDT_EQUIP_DATA() { return m_stDT_EQUIP_DATA; }
	SEquipProp*				GetEquipProp();
	VOID						InitBattleAttribute();//��m_stBattleAttribute��ֵ
	const DT_BATTLE_ATTRIBUTE2& GetBattleAttr() { return m_stBattleAttribute; }
	static DT_BATTLE_ATTRIBUTE	BattleAttCountByLevel(UINT16 wLevel, UINT16 wEnchantLevel, SEquipProp* pstEquipProp); //�ȼ�ͳ��ս�����ԣ����ݵȼ�������õȼ���Ӧ��ս������

    static DT_BATTLE_ATTRIBUTE2	CalcAttrByLevel(UINT16 wLevel, UINT16 wEnchantLevel/* ��ħ�ȼ� */, SEquipProp* pstEquipProp); // ����ǿ���ȼ��͸�ħ�ȼ�������õȼ���Ӧ��ս������

    UINT16 GetEnchantLevel(){ return m_wEnchantLevel; }
    VOID SetEnchantLevel(UINT16 wEnchantLevel){ m_wEnchantLevel = wEnchantLevel; }
    UINT16 GetLevel(){ return m_stDT_EQUIP_DATA.wLevel; }

    // ��װ����ǰ�Ƿ�ɱ���ħ�������Ǹ�ħʯ�Ƿ��㹻��
    BOOL CanBeEnchant();

	UINT32	GetRecoverPrice();//���ռ۸�,todo,��Ա�����洢������ÿ�μ��㣬�ɱ仯����
	UINT16	GetUpgradeDressLevel();//��ȡ��װ������������װ���ȼ�
	
	UINT16	Melt(UINT8 byGoldFlag);//��������
	VOID 	GetRecoverScience(UINT32 &dwMinScience, UINT32 &dwMaxScience);//��������
	static VOID	GetRecoverScience(UINT16 wKindID, UINT32 & dwMinScience, UINT32 & dwMaxScience);//��������

	VOID GetDT_EQUIP_DATA_CLI(DT_EQUIP_DATA_CLI& stDT_EQUIP_DATA_CLI);//��ȡװ�����ͻ��˵���Ϣ
    VOID GetDT_EQUIP_DATA_CLI_v410(DT_EQUIP_DATA_CLI_v410&);//��ȡװ�����ͻ��˵���Ϣ
    VOID GetDT_EQUIP_DATA_STRENGTHEN_CLI(DT_EQUIP_DATA_STRENGTHEN_CLI& stDT_EQUIP_DATA_CLI);//��ȡװ�����ͻ��˵���Ϣ
	VOID GetDT_EQUIP_DATA_ENCHANT_CLI(DT_EQUIP_ENCHANT_DATA_CLI&);//��ȡװ�����ͻ��˵���Ϣ
	VOID GetDT_EQUIP_DATA_COMPOSE_CLI(DT_EQUIP_COMPOSE_DATA_CLI& stDT_EQUIP_DATA_CLI);//��ȡװ���ϳɵ���Ϣ
	VOID GetDT_ENEMY_EQUIP_DATA(DT_ENEMY_EQUIP_DATA& stDT_ENEMY_EQUIP_DATA);//��ȡװ�����ͻ��˵���Ϣ
	VOID GetDT_EQUIP_MELT_DATA_CLI(DT_EQUIP_MELT_DATA_CLI& stDT_EQUIP_MELT_DATA_CLI);//��ȡװ���������ͻ��˵���Ϣ
	UINT32 GetUpLevelCoin(UINT8 byUpLevel);//����������صȼ�ͭǮ

    VOID GetDT_EQUIP_DATA_CLI_with_enchant_lvl(DT_EQUIP_DATA_CLI& stDT_EQUIP_DATA_CLI);//��ȡװ�����ͻ��˵���Ϣ��װ������Я����ħ�ȼ���Ϣ


    EnchantStone2NumMap GetSellEnchantStone(); // ��ó���ʱ�������ĸ�ħʯ

	static UINT32 GetUpLevelCoin(UINT16 wCurStrengthenLevel, UINT8 byUpLevel, UINT16 wDressLevel, UINT16 wPlayerLevel);//����������صȼ�ͭǮ

protected:
	UINT32 GetStrengthenCost(UINT8 byStrengthenType, UINT16 wLevel);//��ȡǿ�������ĵĽ�Ǯ
    UINT16 GetEnchantCostStone(UINT16 wEnchantLevel);//��ȡ��ħ�����ĵĸ�ħʯ
    UINT16 GetEnchantStoneID(UINT16 wEnchantLevel);//��ȡ��ħ�����ĵĸ�ħʯ

    VOID GetBattleAttribute(DT_BATTLE_ATTRIBUTE& stBattleAttribute);//��ȡװ��ս������
	VOID GetBattleAttribute2(DT_BATTLE_ATTRIBUTE2& stBattleAttribute);//��ȡװ��ս������

    VOID GetBasicAttr(DT_BATTLE_ATTRIBUTE2& stAddAttr); //��ȡǿ����������
    VOID GetAttrAddByStrengthen(DT_BATTLE_ATTRIBUTE2& stAddAttr); //��ȡǿ����������
    VOID GetAttrAddByEnchant(DT_BATTLE_ATTRIBUTE2& stAddAttr); //��ȡ��ħ��������

	VOID GetNextLevelBattleAttr(DT_BATTLE_ATTRIBUTE& stBattleAttribute);//��ȡװ����һ����ս������
    VOID GetNextEnchantLevelBattleAttr(DT_BATTLE_ATTRIBUTE2& stBattleAttribute);//��ȡ��ħ����һ�ȼ�������

    VOID GetStrengthenInfo(UINT8& byCanStrengthenFlag, UINT32& dwStrengthenCoin, UINT32& dwStrengthenGold, UINT16& wStrengthenRate);//��ȡǿ����Ϣ
	
private:
	DT_EQUIP_DATA			m_stDT_EQUIP_DATA; //װ����Ϣ
    UINT16 m_wEnchantLevel; // ��ħ�ȼ�
	DT_BATTLE_ATTRIBUTE2 m_stBattleAttribute;//ս������
	CHero*				m_poHero;//��δװ������ΪNULL
	C3232Map            m_mapJewelryAttr;
};

#endif

