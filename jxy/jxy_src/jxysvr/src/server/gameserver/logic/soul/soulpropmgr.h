///<------------------------------------------------------------------------------
//< @file:   logic\soul\soulpropmgr.h
//< @author: Kang_zhiquan
//< @date:   2014��6��12�� 11:58:17
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _soulpropmgr_h_
#define _soulpropmgr_h_
#include "protocol/server/protocligs.h"
#include "logic/base/basepropmgr.h"
#include "souldef.h"
#include "commondef.h"
using namespace std;

class CSoul;
class CSoulPropMgr : public CBasePopMgr
{
	DECLARE_SINGLETON_PROPMGR(CSoulPropMgr)
public:
	CSoulPropMgr();
	virtual ~CSoulPropMgr();

	// implement from CBasePopMgr
	EConfigModule	GetConfigModuleType() { return ECM_SOUL; }
	BOOL			Init();
	VOID			UnInit();

	//��ȡ���Ի���ֵ
	UINT32 GetAttrBaseValue(UINT8 byStarLevel, UINT16 wStrengLevel, UINT8 byKindID);
	//��ȡ������������
	const CRandomMap* GetAttrNumRandom(UINT8 byStarLevel, UINT8 byCurNum);
	//��ȡ����ֵ����
	BOOL GetAttrValueRandom(UINT8 byStarLevel, UINT8 byAttrNum, UINT8 byCurIdx, const SSoulAttrRandomProp*& pstProp);
	//����ս��ṹ��
	DT_SOUL_DATA GenerateSoulData(UINT16 wSoulID);
	
	//��ȡϴ������
	DT_PLAYER_RES_DATA& GetReflashCost();
	//ÿ��ϴ������
	UINT8 GetFreeReflashNum();

	// �����������
	const SoulProductCfg* GetSoulProductCfg(UINT8 ucType);
	// ������Ϣ����
	const MapSoulCfg& GetMapSoulCfg() const;
	const SoulBaseCfg* GetSoulBaseCfg(UINT32 unSoulId);
	// ��ȡս��ȼ��������
	const SoulLvCfg* GetSoulLvCfg(UINT8 ucStarLv, UINT8 ucStrengthLv);

	UINT8 GetSoulLv(UINT8 ucStarLv, UINT32 unExp);

	// 0������ߵȼ���
	UINT32 NextSoulLvExp(UINT8 ucStarLv, UINT8 ucStrengthLv);

	const SoulExchangeCfg* GetSoulExchangeCfg(UINT8 unId);
	const MapSoulExchangeCfg& GetSoulExchangeAllCfg();
	BOOL GetSoulPotencyProp(CPlayer* poPlayer, UINT16 wSoulID, UINT8 byLevel, DT_POTENCY_ATTR_DATA_LST& stAttrData );
	BOOL GetSoulPotencyCountAttr(UINT16 wSoulID, UINT8 byLevel, UINT8 bySubLevel, DT_POTENCY_ATTR_LST_INFO& stAttrLstInfo);
	BOOL GetSoulPotencyCountAttr(UINT16 wSoulID, UINT8 byLevel, UINT8 bySubLevel, C3232Map &poAttrMap);
	UINT8 GetMaxPotencySubLevel(){ return m_byMaxSubLevel; }
	SSoulPotencyProp* GetSoulPotencyProp(UINT16 wSoulID, UINT8 byLevel, UINT8 bySubLevel);
protected:
	//���Ի���ֵ
	BOOL LoadAttrProp();
	//���������Χ
	BOOL LoadAttrRandomProp();
	//�����������
	BOOL LoadRandomProp();
	//ս�꾭������
	BOOL LoadExperience();
	BOOL LoadSoulBaseCfg();
	BOOL LoadSoulProductCfg();
	BOOL LoadSoulLvCfg();
	BOOL LoadSoulExchangeLvCfg();
	BOOL LoadSoulPotencyProp();
private:
	CMapSoulRandom		m_mapSoulRandom;//�����������
	CMapSoulAttrRandom	m_mapSoulAttrRandom;//����ֵ�����Χ
	CMapSoulAttrProp	m_mapSoulAttrProp;//��Ӧ�����Ի���ֵ
	DT_PLAYER_RES_DATA	m_stReflashCost;//ϴ������
	UINT8				m_byFreeReflashNum;//ÿ�����ϴ������
	CMapSoulPotencyProp   m_mapSoulPotencyProp;//Ǳ����������

	MapSoulCfg			m_mpSoulCfg;
	MapSoulStarWeight	m_mpStarWeight;
	MapSoulProductCfg	m_mpProfuctCfg;
	VecSoulLvCfg		m_vecSoulLvCfg;
	MapSoulExchangeCfg	m_mpSoulExchangeCfg;

	UINT8 m_byMaxSubLevel;//Ǳ�����ڵ�
};

#endif //_soulpropmgr_h_
