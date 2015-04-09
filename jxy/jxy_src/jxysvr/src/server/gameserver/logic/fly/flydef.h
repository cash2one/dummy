///<------------------------------------------------------------------------------
//< @file:   logic\fly\flydef.h
//< @author: hongkunan
//< @date:   2014��8��27�� 20:24:47
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _flydef_h_
#define _flydef_h_
#include "sdtype.h"
#include <vector>
#include <memory.h>
using namespace std;
typedef UINT16 GoodsID; // ��ƷID����Ӧ���ݿ�goodsprop��
typedef GoodsID EquipMakeBookID; // ���������ƷID

typedef UINT16 EquipID; // װ��ID����Ӧ���ݿ�equipprop��
typedef UINT16 SeriesID; // װ��ϵ��ID����Ӧ���ݿ�equipseriesprop���SeriesID�ֶ�

// ��������
struct SMaterialProp
{
    SMaterialProp(){ memset(this, 0, sizeof(*this)); }

    UINT8 byMaterialType; // �������ͣ���Ϊ��EIK_EQUIP��EIK_GOODS
    UINT16 wMaterialID; // ��ƷID����װ��ID�����ݲ������;���
    UINT16 wMaterialCnt; // ���������
};

typedef std::vector<SMaterialProp> MaterialVec; // �����б�

#define FLY_REQUIRE_JINGJIE_LVL 25 // �������辳��ȼ�
#define ENCHANT_STONE_ITEM_ID 10000 // ��ħʯ����ƷID

#endif //_flydef_h_