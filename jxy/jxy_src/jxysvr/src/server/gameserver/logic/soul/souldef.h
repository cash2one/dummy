///<------------------------------------------------------------------------------
//< @file:   soulmanager.h
//< @author: yewenhui
//< @date:   2014��6��13�� 10��10��
//< @brief:  ������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------
#ifndef _SOUL_DEF_H_
#define _SOUL_DEF_H_

#include <map>
#include <include/sdtype.h>
#include <common/server/utility.h>
#include "protocol/server/protocommondata.h"

// �����������ַ�ʽ
enum ProductSoulType
{
	ePST_Low		= 0,
	ePST_Middle		,
	ePST_High		,
	ePST_Activity	,
	ePST_Cnt		,
};

enum eSoulConst {
	eDevourSoul		= 0,
	eNormalSoul		= 1,
};

enum eSoulBoxType {
	eBT_CopperBox	= 0,
	eBT_SliverBox	,
	eBT_GoldBox		,
};

enum eSoulUpdatePotency
{
	ESP_SUCCESS = 0,//�ɹ�
	ESP_ITEM_NOT_ENOUGH = 1,//���߲���
	ESP_MAX_LEVEL = 2,//�ѵ���ߵȼ�
	ESP_NOT_CONFIG = 3,//û������
	ESP_LEVEL_NOT_ENOUGH = 4,//ս��ȼ�����
};
struct SSoulRandomProp
{
	UINT8 byStarLevel;		//�Ǽ�
	UINT8 byCurAttrNum;		//��ǰ���Ը���
	UINT8 byOneAttrProb;	//����һ�����Եĸ���
	UINT8 byTwoAttrProb;	//�����������Եĸ���
	UINT8 byThreeAttrProb;	//�����������Եĸ���
	UINT8 byFourAttrPropb;	//�����ĸ����Եĸ���
	UINT8 byFiveAttrPropb;	//����������Եĸ���
	UINT8 bySixAttrPropb;	//�����������Եĸ���
};
typedef map<UINT16, CRandomMap> CMapSoulRandom;
typedef CMapSoulRandom::iterator CMapSoulRandomItr;

struct SSoulAttrRandomProp
{
	UINT8 byStarLevel;	//�Ǽ�
	UINT8 byAttrNum;//���Ը���
	UINT8 byCurAttrIdx;//��ǰ���Ա��
	UINT8 byBeginRandom;//������ֵ 
	UINT8 byEndRandom;//������ֵ 
};

typedef map<UINT32, SSoulAttrRandomProp> CMapSoulAttrRandom;
typedef CMapSoulAttrRandom::iterator CMapSoulAttrRandomItr;

struct SSoulAttrProp
{
	UINT8 byStarLevel;			//�Ǽ�
	UINT8 byAttrNum;		//ǿ���ȼ�
	UINT8 byKindID;				//����ID
	UINT32 dwValue;				//���Ի���ֵ
};

typedef map<UINT32, SSoulAttrProp> CMapSoulAttrProp;
typedef CMapSoulAttrProp::iterator CMapSoulAttrPropItr;

struct SoulBaseCfg {
	UINT32		unSoulId;
	UINT8		ucStar;
	string		strSoulName;
	UINT32		unWeight;//Ȩ��
	UINT8		ucSoulType; // ս������ 2��������� 1�������� 0 ������ս��
	UINT32		unDevourExp; // ���ɾ���
	string		strSoulPic;
	UINT32		unEffectId;		// ��Чid
	UINT8		ucEffectOdd;	// ��Ч����
	string		strNamePic;

	SoulBaseCfg() 
		: unSoulId(0), ucStar(0), unWeight(0), ucSoulType(0)
		, unDevourExp(0)
		, unEffectId(0), ucEffectOdd(0)
	{

	}
};

// key->��id value->������
typedef map<UINT32, SoulBaseCfg*> MapSoulCfg;
// key->���� value->��Ȩ��
typedef map<UINT8, UINT32> MapSoulStarWeight;

// ��Ĳ�������
struct SoulProductCfg {
	UINT8		ucId;
	UINT8		ucSoulPercent;
	UINT32		unMeterialGoodId;
	vector<UINT32> vPossibleStar;
	vector<UINT32> vStarWeight;

	SoulProductCfg()
		: ucId(0)
		, ucSoulPercent(0), unMeterialGoodId(0)
	{

	}
};

// key->��id value->���������
typedef map<UINT8, SoulProductCfg*> MapSoulProductCfg;

typedef map<UINT32, CRandomMap> CSoulRandom;
typedef CSoulRandom::iterator CSoulRandomItr;

struct SoulLvCfg {
	UINT8		ucStarLv;
	UINT8		ucStrengthLv;
	UINT32		unAddAttrPercent;
	UINT32		unExp;

	SoulLvCfg() : ucStarLv(0), ucStrengthLv(0)
		, unAddAttrPercent(0), unExp(0)
	{

	}

};

typedef vector<SoulLvCfg*> VecSoulLvCfg;

struct SoulExchangeCfg
{
	UINT32		unId;
	string		strName;
	vector<UINT32> vMeterialId;
	vector<UINT32> vMeterialNum;
	vector<UINT32> vGetStar;
	vector<UINT32> vGetStarWeight;

	SoulExchangeCfg() : unId(0) {

	}
};

typedef map<UINT32, SoulExchangeCfg*> MapSoulExchangeCfg;

struct SSoulPotencyAttrProp
{
	UINT8 byPotencyKindID;
	UINT32 dwPotencyValue;
};

struct SSoulPotencyProp
{
	UINT16 wSoulID;//Ǳ�����
	UINT8 byPotencyLevel;//Ǳ�ܵȽ�
	UINT8 byPotencySubLevel;//Ǳ�ܵȼ�
	UINT16 wNeedSoulLevel;//��Ҫ��ս��ȼ�
	vector<DT_ITEM_DATA> vecItemData;//���ĵ���Ʒ
	C3232Map mapCountItemData;//�ۻ���Ʒ

	vector<DT_POTENCY_ATTR_INFO> vecPotency;
	C3232Map mapCountAttrValue;//��ǰ�ȼ��ۻ���
	
	SSoulPotencyProp()
	{
		wSoulID = 0;
		byPotencyLevel = 0;
		byPotencySubLevel = 0;
		vecPotency.clear();
		mapCountAttrValue.clear();
		vecItemData.clear();
		wNeedSoulLevel = 0;
	}
};

typedef map<UINT32, SSoulPotencyProp> CMapSoulPotencyProp;
typedef CMapSoulPotencyProp::iterator CMapSoulPotencyPropItr;
#endif // _SOUL_DEF_H_
