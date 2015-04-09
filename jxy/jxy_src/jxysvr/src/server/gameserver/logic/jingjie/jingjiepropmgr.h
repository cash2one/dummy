
#ifndef _JINGJIEPROPMGR_H_
#define _JINGJIEPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basedefine.h>
#include <common/client/commondef.h>
#include <common/server/utility.h>
#include <protocol/server/protocligs.h>
#include <logic/base/basepropmgr.h>

using namespace std;

////���ɻ�ȡ�ľ�������
//struct SGenGasProp
//{
//	UINT8		byType;		//��������
//	UINT8		byLevel;	//�����ȼ�
//	UINT32		dwValue;	//����ֵ
//	UINT8		byRate;		//���ɸ���
//};
//
////���������ȼ�����
//struct SUpGasLevelProp
//{
//	UINT8		byIncLevel;	//�����ȼ�
//	UINT8		byRate;		//����
//};
//
////���������ȼ�����ͭ��
//typedef map<UINT16, UINT32> CUpGasLevelCostCoinMap; //��˳��map��keyΪʹ�ô����� valueΪʹ��ͭ��
//typedef CUpGasLevelCostCoinMap::iterator CUpGasLevelCostCoinMapItr;
//
//
////�������������ʽ����
//struct SUnlockSkillActionProp
//{
//	UINT16 SkillActionID;
//	UINT16 SkillActionLevel;
//};


//��������������
struct SFullQualityLevelAttr
{
	SAllAttrProp stAllIncAttr;					///< ���ý׶�ʱ��������������
	UINT8	byIncAttrNum;						///< ���ý׶�ʱ��������������
	DT_ATTR_INC_DATA astIncAttrInfo[MAX_JINGJIE_ATTR_INC_NUM];///< ���ý׶�ʱ��������������
};


//�����Ӽ���������
struct SJingJieSubLevelUpgradeProp
{
	UINT8	byCareerKind;						///< ְҵID
	UINT16	wLevel;								///< ����Ʒ�ʼ���
	UINT16	wSubLevel;							///< �����Ӽ�
	UINT32	dwUpgradeGas;						///< ���������Ӽ���������
	UINT8	byIncAttrKind;						///< ���Ӽ�����������
	UINT32	dwIncAttrValue;						///< ���Ӽ�������ֵ

	SAllAttrProp stAllIncAttr;					///< ���ý׶�ʱ��������������
	UINT8	byIncAttrNum;						///< ���ý׶�ʱ��������������
	DT_ATTR_INC_DATA astIncAttrInfo[MAX_JINGJIE_ATTR_INC_NUM];///< ���ý׶�ʱ��������������
};

typedef map<UINT32, SJingJieSubLevelUpgradeProp> CJingJieSubLevelUpgradePropMap; //��˳��map��keyΪwLevel+wSubLevel
typedef CJingJieSubLevelUpgradePropMap::iterator CJingJieSubLevelUpgradePropMapItr;
typedef map<UINT16, DT_JINGJIE_PER_LEVEL_DATA> CJingJiePerLevelDataMap; //keyΪ����ȼ�
typedef CJingJiePerLevelDataMap::iterator CJingJiePerLevelDataMapItr;

typedef map<UINT16, UINT16> CJingJieColorMap; //keyΪ����ȼ�
typedef CJingJieColorMap::iterator CJingJieColorMapItr;




class CJingJiePropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CJingJiePropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_JINGJIE ; }

    BOOL Init();


    VOID UnInit();

public:
	inline UINT16 GetMaxQuality()   {  return m_wMaxQualityLevel;  }
	inline UINT16 GetSubLevelNum()	{ return m_wSubLevelNum; }	

	//////////////////////////////////////////////////////////////	
	UINT32 GetJingJieSubLevelUpgradeGas(UINT8 byCareerID, UINT16 wLevel, UINT16 wSubLevel);
	const SAllAttrProp* GetAllIncAttr(UINT8	byCareerID, UINT16 wLevel, UINT16 wSubLevel);
	VOID GetAllIncAttr(UINT8 byCareerID, UINT16 wLevel, UINT16 wSubLevel, UINT8& byIncAttrNum, DT_ATTR_INC_DATA astIncAttrInfo[]);
	VOID GetJingJiePerLevelData(UINT8 byCareerID, UINT16 wLevel, DT_JINGJIE_PER_LEVEL_DATA& stDT_JINGJIE_PER_LEVEL_DATA);

	UINT16 GetJingJieColor(UINT16 wLevel);


public:
    CJingJiePropMgr();
    virtual ~CJingJiePropMgr();

protected:
	
	BOOL LoadFromDB();
	BOOL LoadJingJieBaseropFromDB();
	BOOL LoadJingJieSubLevelUpgradePropFromDB();
	BOOL LoadJingJieColorPropFromDB();
	/////////////////////
	VOID InitIncAttr();

private:
	UINT16				m_wMaxQualityLevel;			//���Ʒ��(��)
	UINT16				m_wSubLevelNum;				//Ʒ���ӵȼ���
	CJingJieSubLevelUpgradePropMap		m_mapAttackCarrerJingJieSubLevelUpgradeProp;//�����;����Ӽ���������
	CJingJieSubLevelUpgradePropMap		m_mapDefenseCarrerJingJieSubLevelUpgradeProp;//�����;����Ӽ���������
	SFullQualityLevelAttr				m_stAttackCarrerFullAttr;	//������ְҵ��������������
	SFullQualityLevelAttr				m_stDefenseCarrerFullAttr;	//������ְҵ��������������
	CJingJiePerLevelDataMap			m_mapAttackCarrerJingJiePerLevelData;	//������ְҵÿ��������Ϣ
	CJingJiePerLevelDataMap			m_mapDefenseCarrerJingJiePerLevelData;	//������ְҵÿ��������Ϣ
	CJingJieColorMap					m_mapJingJieColor;



};

#endif // #ifndef 
