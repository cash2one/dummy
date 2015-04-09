///<------------------------------------------------------------------------------
//< @file:   item\equip\equipmakemgr.h
//< @author: hongkunan
//< @date:   2014��8��25�� 17:15:33
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _equipmakemgr_h_
#define _equipmakemgr_h_

#include "logic/base/singleton.h"
#include "logic/base/basepropmgr.h"
#include "logic/fly/flydef.h"
#include "logic/record/recordmgr.h"
#include "protocol/server/protocligs.h"
#include <set>

// ��Ӧ��ÿ���������װ���Ͳ����б�
struct SEquipMakeProp
{
    SEquipMakeProp(){ wMakeBookID = 0; wSeriesID = 0; wEquipID = 0; vecMaterial.clear(); dwCostCoin = 0; }

    EquipMakeBookID wMakeBookID; // ������ID
    SeriesID wSeriesID;          // װ������ϵ��
    EquipID wEquipID;            // ��������װ��ID
    MaterialVec vecMaterial;     // ��������б�
    
    UINT32 dwCostCoin;           // ����ͭǮ
};

// ÿ��װ��ϵ�е�����
struct SSeriesProp
{
    typedef std::set<EquipID> EquipList;

    SeriesID wSeriesID; // ��ϵ�е�ID
    UINT16 wLevel; // ��ϵ�������ȼ�
    std::string m_strSeriesName; // ��ϵ������

    EquipList m_equips; // ��ϵ�е�װ���б�
};

class CPlayer;

// 
class CEquipMakePropMgr
    : public Singleton<CEquipMakePropMgr>
    , public CBasePopMgr
{
public:
    typedef std::map<EquipMakeBookID, SEquipMakeProp> EquipMakeMap; // <װ�����������ID����Ӧ������>
    typedef std::map<SeriesID, SSeriesProp> SeriesMap;

public:
    ///< @impl >
    BOOL ReLoadProp(){ return TRUE; }

    EConfigModule GetConfigModuleType() { return ECM_PET; }

    BOOL Init();
    VOID UnInit(){}

public:
    const SEquipMakeProp* GetMakeProp(EquipMakeBookID);
    SeriesID GetSeriesIDOfEquip(EquipID);

    UINT32 GetCostGoldOfMaterial(GoodsID);
    UINT32 GetCostCoinOfBook(GoodsID);

    SSeriesProp* GetSeriesProp(SeriesID);

    const EquipMakeMap& GetEquipMakeCfg(){ return m_mapMakeCfg; }

private:
    BOOL LoadEquipMakeProp();
    BOOL LoadSeriesProp();

private:
    EquipMakeMap m_mapMakeCfg; // װ�����������ñ�
    SeriesMap m_mapSeries; // װ��ϵ�б�
};

class CEquipMakeMgr
{
public:
    static BOOL TakeEquipMakeBookInfo(CPlayer &oPlayer, GoodsID makeBookID, DT_EQUIP_MAKE_BOOK&);
    static BOOL TakeMaterialListCli(CPlayer &oPlayer, const MaterialVec&, DT_MATERIAL_LIST&);

    static BOOL CostMaterialList(CPlayer &oPlayer, const DT_MATERIAL_LIST&, CRecordMgr::EDecItemType wRecordType, BOOL bBuyMaterial = FALSE/*�Ƿ���Ԫ������ʣ�಻��Ĳ���*/);
};

#endif //_equipmakemgr_h_