///<------------------------------------------------------------------------------
//< @file:   logic\medal\playermedal.h
//< @author: Kang_zhiquan
//< @date:   2014��6��18�� 19:54:8
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _playermedal_h_
#define _playermedal_h_
#include "logic/base/baseobj.h"
#include <map>
#include "protocol/server/protocligs.h"
#include "logic/base/basedefine.h"
#include "common/server/utility.h"
#include "common/client/commondef.h"
using namespace std;
class CMedal;
class CPlayerMedal : public CBaseObj
{
	typedef map<UINT16, CMedal*> CMapMedal;//KeyΪsmallType, ValueΪѫ�¶���
	typedef CMapMedal::iterator CMapMedalItr;//

	typedef multimap<UINT16, CMedal*> CMultiMapMedal;
	typedef CMultiMapMedal::iterator CMultiMapMedalItr;

	typedef map<UINT32, CMedal*> CMapSmallLevelMedal;
	typedef CMapSmallLevelMedal::iterator CMapSmallLevelMedalItr;
public:
	CPlayerMedal();
	~CPlayerMedal();
	VOID Clear();
	BOOL Init(const DT_PLAYER_MEDAL_DATA&, CPlayer*);

	//У��ʧЧ
	VOID CheckLostMedal();
	VOID AddMedalToPlayer(CMedal*);
	DT_PLAYER_MEDAL_DATA& GetDT_PLAYER_MEDAL_DATA();

	//��Ӻ�������ѫ��
	VOID AddNewMedal();
	VOID AddNewMedalByBuild(UINT8 byBuildID);
	//ÿ����һ��
	VOID CheckEveryDay();
	//�������Լӳ�
	VOID InitBattleAttr();
	//��ȡ���Թ̶�ֵ
	const C3232Map& GetBattleAttrFix();
	//��ȡ���԰ٷֱ�
	const C3232Map& GetBattleAttrPercent();
	//���ѫ��
	BOOL CheckMedalBySmallType(UINT16 wSmallType);
	//��ȡ������Ϣ
	DT_MEDAL_BASE_DATA& GetDT_MEDAL_BASE_DATA(){ return m_stMedalBaseData; }
	//����½ѫ��
	BOOL CheckMedalByLogin();
public:
	////////////////////////////////�ճ�����//////////////////////////////////////////
	//����������½ʱ��
	VOID ContinueLogin();
	//���㹺������d
	VOID AddBuyPhystrength();
	//�������ش���
	VOID AddInterceptNum();
	//���ʹ���
	VOID AddEscortNum();
	//�вƴ���
	VOID AddRankMoneyNum();
	//��ͨ�ۻ����
	VOID AddNormalGatherNum();
	//Ԫ���ۻ����
	VOID AddGoldGatherNum();
	//Ĥ��1�������
	VOID AddWorshipPlayer1Num();
	//Ĥ��2�������
	VOID AddWorshipPlayer2Num();
	//Ĥ��3�������
	VOID AddWorshipPlayer3Num();
	//����1�������
	VOID AddWorshipGod1Num();
	//����2�������
	VOID AddWorshipGod2Num();
	//����3�������
	VOID AddWorshipGod3Num();
	//����ʦ���Դ���
	VOID AddZTSNum();
	//Ц������
	VOID AddSmileNum(UINT32 dwSmileNum);
	//С����ץ������
	VOID AddArrestNum();
	//С�ڲ����ϴ���
	VOID AddDriveNum();
	//�������ô���
	VOID AddTowerResetNum();
	//��Ӣ�������ô���
	VOID AddEliteInstanceResetNum();
	//������������
	VOID AddGVECourageNum();
	//��ѫ��ʧЧ
	VOID UnActivityMedal(MEDAL_SMALL_TYPE);
	//�����ʱѫ��
	VOID CheckLimitMedal(MEDAL_SMALL_TYPE, BOOL bIsUnActivity = TRUE);
	//���þ���������
	BOOL SetRaceRank();
public:
	//��ӿ���ѫ��
	VOID AddCanUseMedal(CMedal* poMedal);
	UINT16 OnOpenMyMedal(PKT_CLIGS_OPEN_MY_MEDAL_ACK& stAck);
	VOID GetUseMedal(DT_MEDAL_DATA_LST_CLI& stCli);
protected:
	//����ʧЧѫ��
	VOID DealLostMedal();
	//��������Чѫ��
	VOID DealEffectMedal();
private:
	CMapMedal m_mapAllMedal;//����ѫ�£�������ѫ��+��������ѫ��+δ����ѫ��
	CMultiMapMedal m_mapUseMedal;//�����õ�ѫ��
	CMultiMapMedal m_multiMapAllMedal;//����ѫ��
	CMapMedal m_mapUnlockMedal;//��ʾδ����ѫ��

	C3232Map m_mapBattleAttrFixed;//ս�����Թ̶�ֵ�ӳ�
	C3232Map m_mapBattleAttrPercent;//ս�����԰ٷֱȼӳ�

	C1616MultiMap m_mapBuildID;//�����ѫ�°�����ID����
	UINT64 m_qwLastUpdateTime ;
	DT_PLAYER_MEDAL_DATA m_stPlayerMedal;
	DT_MEDAL_BASE_DATA m_stMedalBaseData;
};

DECLARE_CLASS_POOL_MGR(CPlayerMedal)
#endif //_playermedal_h_