
#ifndef _SKILLPROPMGR_H_
#define _SKILLPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <logic/base/basepropmgr.h>
#include <common/client/commondef.h>
#include <common/server/utility.h>
#include <map>
#include <vector>
#include <protocommondata.h>

struct tagDT_SKILL_ACTION_DATA_CLI;
typedef tagDT_SKILL_ACTION_DATA_CLI DT_SKILL_ACTION_DATA_CLI;

struct tagDT_SKILL_EFFECT_DATA_CLI;
typedef tagDT_SKILL_EFFECT_DATA_CLI DT_SKILL_EFFECT_DATA_CLI;

struct tagDT_ATTACK_RANG_DATA_CLI;
typedef tagDT_ATTACK_RANG_DATA_CLI DT_ATTACK_RANG_DATA_CLI;

struct tagDT_EFFECT_RECOMMEND_CLI;
typedef tagDT_EFFECT_RECOMMEND_CLI DT_EFFECT_RECOMMEND_CLI;




using namespace std;

/// ��������������󳤶�
#define NAME_LEN_MAX	32
/// ���ܽ���������󳤶�
#define INTRODUCTION_LEN_MAX	255

//���ܻ�����Ϣ
struct SSkillBaseProp
{
	//UINT16	wMaxGenNumPerDay;	//ÿ��������ɾ�������
	UINT32	dwGenGasCoin;		//��������ͭ�ң���һ�����
	UINT32	dwUpFullGasBallLevelGold;	//�������о�������������Ԫ��	
	UINT16	wAddExpPerUpgrade ;// ÿ���������ӵľ���ֵ
	UINT16	wCostGasPerUpgrade;// ÿ���������ĵ�����
};


//������ʽ
struct SSkillActionProp
{
	UINT16	wID;				// ID
	UINT16	wLevel;				// �ȼ�

	UINT16	wEffectHurtRate;	// Ч���˺�����(�ٷֱ�)
	UINT32	dwExtHurtValue;	// �����˺�ֵ

	UINT32	dwExp;			// �������õȼ���ӵ�еľ���

	UINT16	wUnlockSkillEffectID; //������Ч��ID
	UINT16  wDspUnlockSkillEffectIDPlayerLevel;//��ʾ����Ч���������ҵȼ�
	
	UINT8	byUnlockAttackRangKind;	// ������Χ����
	UINT8	byUnlockTraceBuffKind;	// ׷��buff����		

	UINT16	wAttackRangHurtRate;	// ������Χ���˺����ʣ���ʽ�˺������ϣ�
	UINT16	wDspUnlockAttackRangPlayerLevel; //��ʾ������Χ�������ҵȼ�

	vector<UINT16> vecCurUnlockSkillEffectID; //��ǰ���н�����Ч��ID
	vector<DT_ATTACK_RANG_DATA> vecCurUnlockAttackRang; //��ǰ���н����Ĺ�����Χ
};
typedef map<UINT16, UINT16> CMaxSkillActionLevelMap; //��ʽ���ȼ�
typedef CMaxSkillActionLevelMap::iterator CMaxSkillActionLevelMapItr;
typedef map<UINT32, SSkillActionProp> CID2SkillActionPropMap; //keyΪID+Level
typedef CID2SkillActionPropMap::iterator CID2SkillActionPropMapItr;
typedef map<UINT32, SSkillActionProp> CRang2ActionPropMap; //keyΪID+byUnlockAttackRangKind+byUnlockTraceBuffKind
typedef CRang2ActionPropMap::iterator CRang2ActionPropMapItr;
typedef map<UINT32, SSkillActionProp> CEffect2ActionPropMap; //keyΪID+wUnlockSkillEffectID
typedef CEffect2ActionPropMap::iterator CEffect2ActionPropMapItr;
typedef map<UINT16, vector<DT_ATTACK_RANG_DATA> >CActionID2AllRangMap;//keyΪID
typedef CActionID2AllRangMap::iterator CActionID2AllRangMapItr;
typedef map<UINT16, vector<UINT16> >CActionID2AllEffectMap;//keyΪID
typedef CActionID2AllEffectMap::iterator CActionID2AllEffectMapItr;

//
//���ܵ���buffЧ������
struct SSkillOnceBuffProp
{
	UINT8	byBuffKindID;		// buff����
	UINT8	byBuffRound;		// buff�����غ���
	UINT16	wBuffParam;			// buff����
	UINT8	byBuffRate;			// buff����
};

//����Ч������
struct SSkillEffectProp
{
	SSkillEffectProp() { wID = 0; byOnceEffectKindID = 0; wOnceEffectParam = 0; wOnceEffectRate = 0; memset(astSkillBuffrop, 0, sizeof(astSkillBuffrop)); }

	UINT16	wID;					// ID

	UINT8	byOnceEffectKindID;		// Ч������
	UINT16	wOnceEffectParam;		// Ч������
	UINT16  wOnceEffectRate;		//Ч������

	SSkillOnceBuffProp astSkillBuffrop[MAX_SKILL_BUFF_NUM]; //����buffЧ��
};
typedef map<UINT16, SSkillEffectProp> CID2SkillEffectPropMap; //keyΪID
typedef CID2SkillEffectPropMap::iterator CID2SkillEffectPropMapItr;



////����ÿ���ȼ�������
//struct SSkillProp
//{
//	UINT16	wID;		// ����ID
//	TCHAR	szName[NAME_LEN_MAX];		// ��������
//	TCHAR	szIntroduction[INTRODUCTION_LEN_MAX];		// ���ܽ���
//	UINT8	byColor;		// ������ɫ����������㣬ֻ���ڱ�ʶ
//	UINT16	wSkillLevel;	// ���ܵȼ�����������㣬ֻ���ڱ�ʶ	
//	UINT16	wSkillActionID; // ������ʽID, ����Ϊ0
//	UINT16	wSkillActionLevel; // ������ʽ�ȼ�
//	UINT16	wSkillEffectID; // ����Ч��ID������Ϊ0
//};

//����Ч���Ƽ��������
struct SSkillEffectRecommendProp
{
	UINT16 wEffectID; //Ч��ID
	UINT16 wStartRecommendJingJieLevel; //��ʼ�Ƽ�����ȼ�
	UINT16 wRecommendHeroID1; //�Ƽ����ID
	UINT8  wRecommendHeroEffectID1; //�Ƽ�����Ч��ID(0��ʾû��)
	UINT8 byRecommendHeroRangKind1;
	UINT8 byRecommendHeroRangBuff1;
	UINT16 wRecommendHeroID2;
	UINT16 wRecommendHeroEffectID2;
	UINT8 byRecommendHeroRangKind2;
	UINT8 byRecommendHeroRangBuff2;

};
typedef map<UINT16, SSkillEffectRecommendProp> CJingJieLevel2RecommendPropMap; // keyΪwStartRecommendJingJieLevel
typedef CJingJieLevel2RecommendPropMap::iterator CJingJieLevel2RecommendPropMapItr;
typedef map<UINT16, CJingJieLevel2RecommendPropMap> CEffect2RecommendPropMapMap; // keyΪwEffectID
typedef CEffect2RecommendPropMapMap::iterator CEffect2RecommendPropMapMapItr;

struct SPetSkillEffectProp
{
	UINT16 wSkillID;		//����ID
	string strSkillName;	//��������
	string strSkillDesc;	//��������
	string strSkillBeginRound;//��ʼ�غ�����
	UINT16 wSkillLevel;		//���ܵȼ�
	UINT16 wHurtRate;		//���ܹ����˺���Χ
	UINT8  byAttackRangType;	//������Χ����
	UINT32 dwExtHurtValue;	//���ܶ����˺�
	UINT16 wFinalHurtValue; //�����˺���
	UINT8  byMaxTargetNum;	//�����������
	UINT8 byOnceEffectID;	//��ЧID
	UINT16 wOnceEffectRate;	//��Ч����
	UINT16 wOnceEffectParam;	//��Ч����

	vector<SSkillOnceBuffProp> vecBuffProp;

	SPetSkillEffectProp()
	{
		clear();
	}
	void clear()
	{
		wSkillID = 0;
		strSkillDesc = "";
		strSkillName = "";
		wSkillLevel = 0;
		wHurtRate = 0;
		byAttackRangType = 0;
		dwExtHurtValue = 0;
		byOnceEffectID = 0;
		wOnceEffectRate = 0;
		wOnceEffectParam = 0;
		vecBuffProp.clear();
		wFinalHurtValue = 100;
	}
};

struct SRandomPetSkillProp
{
	SPetSkillEffectProp stMainProp;
	vector<SPetSkillEffectProp> vecRandomProp;
};

typedef map<UINT32, SPetSkillEffectProp> CMapPetSkillEffectProp;
typedef CMapPetSkillEffectProp::iterator CMapPetSkillEffectPropItr;

typedef map<UINT32, SRandomPetSkillProp> CMapVecRandomSkillProp;
typedef CMapVecRandomSkillProp::iterator CMapVecRandomSkillPropItr;

class CPlayer;

//typedef map<UINT32, SSkillProp> CIDLevel2SkillPropMap; //keyΪID+Level
//typedef CIDLevel2SkillPropMap::iterator CIDLevel2SkillPropMapItr;




/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CSkillPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CSkillPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_SKILL ; }
    BOOL Init();
    VOID UnInit();
public:
	SSkillBaseProp&	  GetSkillBaseProp() { return m_stSkillBaseProp; }
	SSkillActionProp* GetSkillActionProp(UINT16 wID, UINT16 wLevel);
	SSkillEffectProp* GetSkillEffectProp(UINT16 wID);
	UINT16 GetMaxSkillActionLevel(UINT16 wID);
	SSkillActionProp* GetSkillActionInfoCli(UINT16 wActionID, UINT16 wLevel, DT_SKILL_ACTION_DATA_CLI& stActionData);
	SSkillEffectProp* GetSkillEffectInfoCli(UINT16 wEffectID, DT_SKILL_EFFECT_DATA_CLI& stEffectData);
	SSkillActionProp* GetSkillAttackRangInfoCli(UINT16 wActionID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind, DT_ATTACK_RANG_DATA_CLI& stRangInfo);
	SSkillActionProp* GetAttackRangActionProp(UINT16 wActionID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind);
	UINT16 GetAttackRangHurtRate(UINT16 wActionID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind);
	UINT16 GetAttackRangUnlockLevel(UINT16 wActionID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind);
	UINT16 GetAttackRangDspLevel(UINT16 wActionID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind);
	UINT16 GetEffectUnlockLevel(UINT16 wActionID, UINT16 wEffectID);
	UINT16 GetEffectDspLevel(UINT16 wActionID, UINT16 wEffectID);
	vector<DT_ATTACK_RANG_DATA>& GetActionAllRang(UINT16 wActionID);
	vector<UINT16>& GetActionAllEffect(UINT16 wActionID);
	SPetSkillEffectProp* GetPetSkillProp(UINT16 wSkillID, UINT16 wLevel);
	SRandomPetSkillProp* GetPetRandomSkillProp(UINT16 wSkillID, UINT16 wLevel);
	///////////////////////////////
	UINT32 GetJingJieSubLevelUpgradeGas(UINT8 byCareerID, UINT16 wLevel, UINT16 wSubLevel);
	VOID GenGas(UINT8 byPurpleFlag, DT_GAS_BALL_DATA& stDT_GAS_BALL_DATA);
	VOID UpGasBallLevel(UINT8 byFullLevelFlag, UINT8& byLevel);
	UINT32 GetGas(UINT8 byGasType, UINT8 byLevel);
	UINT32 GetGuidePurpleGas();
	UINT32 GetCommonUpGasCoin(UINT16 wUpNum);
	//inline UINT16 GetMaxGenNumPerDay()	{ return m_stSkillBaseProp.wMaxGenNumPerDay; }
	inline UINT16 GetGenGasCoin()	{ return m_stSkillBaseProp.dwGenGasCoin; }
	inline UINT32 GetUpFullGasBallLevelGold()	{ return m_stSkillBaseProp.dwUpFullGasBallLevelGold; }
	inline UINT32 GetAddExpPerUpgrade() { return m_stSkillBaseProp.wAddExpPerUpgrade; }
	inline UINT32 GetCostGasPerUpgrade() { return m_stSkillBaseProp.wCostGasPerUpgrade; }
	///////////////////////////////

	SSkillEffectRecommendProp* GetSkillEffectRecommendCli(UINT16 wEffectID, UINT16 wCurJingJieLevel, DT_EFFECT_RECOMMEND_CLI astRecommendInfo[2]);
	SSkillEffectRecommendProp* GetSkillEffectRecommendProp(UINT16 wEffectID, UINT16 wJingJieLevel);
	UINT32 GetPetSkillTrigerNum(UINT16 wSkillID, UINT16 wPetLevel);
public:
    CSkillPropMgr();
    virtual ~CSkillPropMgr();

	BOOL LoadSkillBaseFromDB();
	BOOL LoadSkillEffectRecommendPropFromDB();
	BOOL LoadSkillActionPropFromDB();
	BOOL LoadSkillEffectPropFromDB();
	BOOL LoadSkillPropFromDB();
	BOOL LoadPetSkillFromDB();

protected:
	BOOL ParsePetSkill(const string& strXMLValue);
	BOOL ParseRandomPetSkill(const string& strXMLValue);
private:
	SSkillBaseProp			m_stSkillBaseProp;
	//CIDLevel2SkillPropMap	m_mapIDLevel2SkillProp; 
	CID2SkillActionPropMap	m_mapIDLevel2SkillActionProp;
	CID2SkillEffectPropMap	m_mapIDLevel2SkillEffectProp;
	CMaxSkillActionLevelMap	m_mapMaxSkillActionLevel;
	CEffect2RecommendPropMapMap m_mapSkillEffectRecommendProp;
	CRang2ActionPropMap		m_mapRang2ActionProp;
	CEffect2ActionPropMap	m_mapEffect2ActionProp;
	CActionID2AllRangMap	m_mapActionID2AllRang;
	CActionID2AllEffectMap	m_mapActionID2AllEffect;

	CMapPetSkillEffectProp  m_mapPetSkillProp;
	CMapVecRandomSkillProp  m_mapRandomPetSkillProp;
};

#endif // #ifndef _SKILLPROPMGR_H_
