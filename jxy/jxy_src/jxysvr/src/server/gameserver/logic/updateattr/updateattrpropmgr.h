#ifndef _UPDATE_ATTR_PROP_MGR_H_
#define _UPDATE_ATTR_PROP_MGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

typedef struct tagUpdateCostData
{
	UINT32 dwCostCoinValue;
	UINT16 wCostItemValue;
}SUpdateCostData;

//�������ӵ�����
typedef struct tagUpdateData
{
	SUpdateCostData stCost;
	UINT32 dwPerCountAddValue; //ÿ�����ӵ�����
}SUpdateData;

class CUpdateAttrPropMgr : public CBasePopMgr
{
public:
	DECLARE_SINGLETON_PROPMGR( CUpdateAttrPropMgr );
	CUpdateAttrPropMgr();
	~CUpdateAttrPropMgr();

public:
	//typedef HashMap< UINT8, tagUpdateCostData > CUpdateCostInfoMgr;
	struct STParam
	{
		//FLOAT fTalentAttackFactor;
		//FLOAT fTalentHPFactor;
		//FLOAT fHPScaleToAttack;
		//FLOAT fH_AttackFactor;
		//FLOAT fH_HPFactor;
		//FLOAT fA_AttackFactor;
		//FLOAT fA_HPFactor;
		UINT16 wStrengthScaleToNormal;
		UINT16 wUpdateLevelAddCount;
	};
public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_UPDATE_ATTR ; }
	BOOL Init();
	VOID UnInit();

	//byTypeΪ��ѯ����������,wLevelΪ��Ҽ���
	BOOL GetUpdateAttrNeedInfo( BOOL bLeader, UINT8 byAttrType, UINT8 byJobType, UINT16 wAttrLevel, UINT32 dwTalent, SUpdateData &data, UINT16 wLevel );

	//����ܹ�����
	UINT16 GetTotalCount( UINT16 wLevel );

	//�������ʺ����ԵȲ����������ʵ�ʼ������ӵ�ֵ,
	//����bIncludeDefaultAttr������ȷ���Ƿ������ʼ���е�1J�����ݣ���Ϊ����ʼֵ�Ѿ�����1�������ݣ��������Լӳ�ʱ���󲿷ֶ���Ӧ���ظ������һ��������
	DOUBLE GetAttrAddValue( UINT32 dwTalent, UINT16 wLevel, UINT8 byAttrType, UINT8 byJobType, BOOL bIncludeDefaultAttr=TRUE );
private:
	//��ʼ������
	BOOL InitData();

	//wLeveΪ�佫�ȼ�
	UINT32 GetAttrPerAddValue( UINT8 byAttrType, UINT8 byJobType, UINT16 wLevel, UINT32 dwTalent );
private:
	STParam m_oParam;
};


#endif