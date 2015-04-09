///<------------------------------------------------------------------------------
//< @file:   logic\pet\petdef.h
//< @author: yewenhui10@qq.com
//< @date:   2014��8��6�� 16:58:17
//< @brief:  ����������ݽṹ����
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _PET_DEF_H_ 
#define _PET_DEF_H_

#include "sdtype.h"
#include <vector>
#include <map>
#include "protocol/server/protocommondata.h"
#include "protocol/server/protocligs.h"
using namespace std;
enum ePetType {
	ePT_Wind		= 1,	// ��
	ePT_Water		,		// ˮ
	ePT_Fire		,		// ��
	ePT_Land		,		// ��
	ePT_Ice			,		// ��
	ePT_Sand		,		// ɰ
	ePT_Hot			,		// ��
	ePT_Soul		,		// ����
	ePT_Dream		,		// ��
	ePT_Legend		,		// ��˵
	
	ePT_Cnt = ePT_Legend,
};

enum ePetQuality {
	ePQ_NormalPet		= 1,//Ұ��
	ePQ_BabyPet			,	//��ͨ
	ePQ_VariantPet		,	//����

	ePQ_Cnt = ePQ_VariantPet ,
};

//���ﵵ��
enum ePetLevel
{
	EPL_FIRST = 1,//��һ��
	EPL_SECOND = 2,//�ڶ���
	EPL_THIRD = 3,//������
	EPL_FOURTH = 4,//���ĵ�
};

// enum ePetWashQualityType{
// 	ePWQT_Ten		= 1, 
// 	ePWQT_Hundred	,
// 	ePWQT_Thousand	,
// 	ePWQT_TenThousand,
// };

struct PetSysCfg {
	UINT16		usMaxCarryPet;			// ������������Ŀ
	UINT8		ucFreeFeedCnt;			// һ��ι����ѳ�ȡ����
	UINT32		unResetFruitCost;		// ���ó齱���ѵ�Ԫ��
	UINT32		unMaxFruitCost;			// һ����ˮ��Ū����û��ѵ�Ԫ��

	UINT8		ucTriggerWashQuality;	// ������һ���ӵ�Ʒ��

	UINT32		unPerfectInheritCostGold;	// �����̳л��ѵ�Ԫ��
	UINT32		unNormalInheritCostCoin;	// ��ͨ�̳л��ѵ�ͭǮ

	UINT8		ucNormalInheritExp;		// ��ͨ�̳о���ٷֱ�
	UINT8		ucGoodInheritExp;		// �����̳о���ٷֱ�

	string		strWashDesc;
	string		strRuleDesc;
	string		strLowDesc;
	string		strMiddleDesc;
	string		strHighDesc;
	string		strItemDesc;
	vector<UINT32>		vecItemID;//���������ʾ�ĵ���

	UINT16		usNormalFreeProductCnt;

// 	UINT32		unJinliuluItemId;
// 	UINT32		unSuperJinliuluItemId;
// 	std::vector<UINT32> vJinliuluRange;
// 	std::vector<UINT32>	vSuperJinliuluRange;

	PetSysCfg() 
		: usMaxCarryPet(0)
		, ucFreeFeedCnt(0)
		, unResetFruitCost(0)
		, unMaxFruitCost(0)
		, ucTriggerWashQuality(0)
		, unPerfectInheritCostGold(0)
		, unNormalInheritCostCoin(0)
		, usNormalFreeProductCnt(0)
// 		, unJinliuluItemId(0)
// 		, unSuperJinliuluItemId(0)
	{
	}
};

struct PetBaseCfg {
	UINT16		usPetCfgId;
	std::string	strPetName;
	UINT8		ucPetType;
	UINT8		ucPetQuality;
	UINT32		unDevourExp;
	UINT32		unSkillId;
	UINT32		unPhyChicMax;
	vector<UINT16> vecSkill;
	UINT8		ucPhyChicValPerMin;
	UINT8		ucPhyChicValPerMax;
	UINT32		dwBaseLiLing;
	UINT8		ucPetColor;

	std::string	strPetPic;
	std::string	strPetDesc;

	PetBaseCfg() 
		: usPetCfgId(0) 
		, ucPetType(0)
		, ucPetQuality(0)
		, unDevourExp(0)
		, unSkillId(0)
		, unPhyChicMax(0)
		, ucPhyChicValPerMin(0)
		, ucPhyChicValPerMax(0)
		, ucPetColor(1)
	{
		vecSkill.clear();
	}
};

typedef std::map<UINT16, PetBaseCfg*> PetBaseCfgList;
typedef multimap<UINT16, PetBaseCfg*> CMultiMapBaseProp;
struct PetLvKey {
	UINT16		usPetLv;

	PetLvKey()
		: usPetLv(0)
	{

	}

	bool operator<(const PetLvKey& rhs) const {
		return usPetLv < rhs.usPetLv;
	}

};

struct PetLvCfg {
	UINT32		unExp;

	PetLvCfg() 
		: unExp(0)
	{

	}
};

typedef std::map<PetLvKey, PetLvCfg*> MapPetLvCfg;

struct PetProductCfg {
	UINT8		ucProductPhrase;		// 
	UINT8		ucProductType;			// 
	UINT16		usPlayerMinLv;			//
	UINT16		usPlayerMaxLv;			//
	std::vector<UINT32> vGetPetType;	//
	std::vector<UINT32> vPetWeight;	//

	std::vector<UINT32> vGetPetQuality;	//
	std::vector<UINT32> vQualityWeight;	//
	UINT32		unScore;

	std::vector<UINT32> vGetItemId;		//
	std::vector<UINT32> vGetItemNum;		//
	std::vector<UINT32> vGetItemPercent;	//

	UINT32		unCostGold;
	UINT16		usFreeTimeInterval;		// ��ѳ�ȡ������ʱ�䣨��λ���ӣ�

	PetProductCfg()
		: ucProductPhrase(0)
		, ucProductType(0)
		, usPlayerMinLv(0)
		, usPlayerMaxLv(0)
		, unScore(0)
		, unCostGold(0)
		, usFreeTimeInterval(0)
	{
	}
};

typedef std::vector<PetProductCfg*> PetProductCfgList;

struct PetProductExtraCfg {
	UINT8		ucProductPhrase;		// 
	BOOL		bIsGoodProduct;
	UINT16		usProductCnt;

	std::vector<UINT32> vExtraItemId;	// �����ٻ������õ���id
	std::vector<UINT32>	vExtraItemNum;	// �����ٻ������õ�������

	PetProductExtraCfg() 
		: ucProductPhrase(0)
		, bIsGoodProduct(FALSE)
		, usProductCnt(0)
	{

	}
};

typedef std::vector<PetProductExtraCfg*> PetProductExtraCfgList;

struct PetStarKey {
	UINT8		ucPetType;
	UINT8		ucPetQuality;
	UINT16		usPetStarLv;

	PetStarKey()
		: ucPetType(0)
		, ucPetQuality(0)
		, usPetStarLv(0)
	{

	}

	bool operator<(const PetStarKey& rhs) const {
		return ucPetType < rhs.ucPetType
			|| (ucPetType == rhs.ucPetType && ucPetQuality < rhs.ucPetQuality)
			|| (ucPetType == rhs.ucPetType && ucPetQuality == rhs.ucPetQuality && usPetStarLv < rhs.usPetStarLv);
	}
};

struct PetStarCfg {
	UINT16		usPetMaxLv;				// �������ȼ�
	UINT8		ucPlayerLvLimit;
	vector<UINT32> vCostItemId;
	vector<UINT32> vCostItemNum;
	UINT32		unAddLingliPer;

	PetStarCfg() 
		: usPetMaxLv(0)
		, ucPlayerLvLimit(0)
		, unAddLingliPer(0)
	{
	}
};

typedef std::map<PetStarKey, PetStarCfg*> MapPetStarCfg;

enum ePetFruitType {
	ePFT_Banana			= 1,
	ePFT_Apple			,
	ePFT_Stawberry		,
	ePFT_Cherry			,
	ePFT_Sapodilla 		,			// �˲ι�
		
	ePetFruitCnt		= ePFT_Sapodilla,
};

struct PetFeedCfg {
	UINT8		ucFruitType;				// ͼ������
	UINT8		ucPercent;					// ���ָ���
	UINT32		unBaseExp;					// ��������
	UINT16		vExpTimes[MAX_PET_FEED_FRUIT_CNT];	// ˮ������Ϊn �ı���

	PetFeedCfg() {
		memset(this, 0, sizeof(*this));
	}
};

typedef std::map<UINT8, PetFeedCfg*> MapPetFeedCfg;

struct PetStoreCfg {
	UINT32			unItemId;
	UINT32			unCostPetScore;
	UINT32			unCostGold;
	UINT16			usPlayerLvLimit;
	UINT16			usShowLv;

	UINT8			ucItemType;			// �̳ǵ�������

	PetStoreCfg() 
		: unItemId(0), unCostPetScore(0)
		, unCostGold(0), usPlayerLvLimit(0)
		, usShowLv(0)
	{
		
	}
};

typedef std::map<UINT16, PetStoreCfg*> MapPetStoreCfg;

// ϴ����
struct PetWashKey {
	UINT8		ucPetType;
	UINT8		ucPetQuality;
	UINT8		ucWashQuality;

	PetWashKey()
		: ucPetType(0)
		, ucPetQuality(0)
		, ucWashQuality(0)
	{

	}

	bool operator<(const PetWashKey& rhs) const {
		return ucPetType < rhs.ucPetType
			|| (ucPetType == rhs.ucPetType && ucPetQuality < rhs.ucPetQuality)
			|| (ucPetType == rhs.ucPetType && ucPetQuality == rhs.ucPetQuality && ucWashQuality < rhs.ucWashQuality);
	}

};

// ��������
struct PetPsychicRange {
	UINT32			unMinVal;
	UINT32			unMaxVal;

	PetPsychicRange() 
		: unMinVal(0), unMaxVal(0)
	{

	}
};

struct PetWashCfg {
	std::vector<UINT32>	vPossibleWashQuality;
	std::vector<UINT32>	vWashQualityWeight;
	std::vector<UINT32>	vUseItemid;
	std::vector<UINT32>	vUseItemNum;

	UINT32				unLockCostGold;

	std::vector<PetPsychicRange> vPsychicRange;			
	std::vector<UINT32>	vPsychicWeight;

	PetPsychicRange		totalRange;

	PetWashCfg()
		: unLockCostGold(0)
	{

	}

};

typedef std::map<PetWashKey, PetWashCfg*> MapPetWashCfg;

typedef std::pair<UINT8, UINT8> PetRefineKey;

struct PetRefineData {
	UINT8			ucPetTypeLevel;
	UINT8			ucPetQuality;

	PetRefineData()
		: ucPetTypeLevel(0), ucPetQuality(0)
	{

	}
};

struct PetRefineCfg {
	std::vector<PetRefineData> vGetPetData;
	std::vector<UINT32>		vGetPetWeight;

	PetRefineCfg() {

	}
};

typedef std::map<PetRefineKey, PetRefineCfg*> MapRefineCfg;

enum {
	P_SUCCESS,	//�ɹ�
	P_NOT_HAVE_PET,//�Ҳ�������
	P_NOT_PET_CFG,//�Ҳ���������
	P_OTHER_ERR,//��������
};

struct SPetNeiDanProp
{
	UINT16 wNeiDanID;//�ڵ�ID
	string strNeiDanName;//�ڵ�����
	UINT8 byWuXing;//����
	UINT8 byQuality;//Ʒ��
	UINT8 byType;//Ʒ��
	UINT32 dwBaseLingLi;//��������
	UINT32 dwIncLingLi;//��������
	UINT16 wDressReq;//����Ҫ��Ƚ�
	UINT32 dwCostCoin;//���ɺķ�ͭǮ
	UINT32 dwBaseExperience;//��������ֵ
	SPetNeiDanProp()
	{
		wNeiDanID = 0;
		byWuXing = 0;
		byQuality = 0;
		byType = 0;
		dwBaseLingLi = 0;
		dwIncLingLi = 0;
		strNeiDanName = "";
		wDressReq = 0;
	}
};

typedef map<UINT16, SPetNeiDanProp> CMapPetNeiDanProp;
typedef CMapPetNeiDanProp::iterator CMapPetNeiDanPropItr;

struct SPetNeiDanUpdateProp
{
	UINT8 byType;	//Ʒ��
	UINT16 wLevel;	//�ȼ�
	UINT8 byQuality;//Ʒ��
	UINT64 qwExperience;//����
	SPetNeiDanUpdateProp()
	{
		byType = 0;
		wLevel = 0;
		qwExperience = 0;
		byQuality = 0;
	}
};

typedef map<UINT32, SPetNeiDanUpdateProp> CMapPetNeiDanUpdateProp;
typedef CMapPetNeiDanUpdateProp::iterator CMapPetNeiDanUpdatePropItr;

#endif // _PET_DEF_H_
