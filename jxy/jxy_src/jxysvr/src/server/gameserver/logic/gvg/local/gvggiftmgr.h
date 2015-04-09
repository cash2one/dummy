///<------------------------------------------------------------------------------
//< @file:   gvg\local\gvggiftmgr.h
//< @author: Kang_zhiquan
//< @date:   2014��5��7�� 20:25:48
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvggiftmgr_h_
#define _gvggiftmgr_h_

#include <map>
#include <sdsingleton.h>
#include "protocol/server/protocligs.h"
#include "logic/base/basedefine.h"

enum EM_RESULT
{
	GIFT_SUCCESS = 0,//�ɹ�
	GIFT_ID_NOT_EXIST = 1,//ID������
	GIFT_BAG_FULL = 2,//������
};
using namespace std;

typedef vector<DT_GVG_GIFT_REWARD_DATA> CVecGiftRewardData;
typedef CVecGiftRewardData::iterator CVecGiftRewardDataItr;

class CPlayer;

class CGvGGiftMgr 
{
	DECLARE_SINGLETON(CGvGGiftMgr)
	typedef map<UINT64, DT_GVG_GIFT_REWARD_DATA> CMapGvGGiftReward;
	typedef CMapGvGGiftReward::iterator CMapGvGGiftRewardItr;

public:
	CGvGGiftMgr()
	{
		m_mapGiftReward.clear();
		m_vecAddToDBGift.clear();
	}
	~CGvGGiftMgr()
	{
		m_mapGiftReward.clear();
		m_vecAddToDBGift.clear();
	}
	BOOL Init();
	//ȥ���������
	VOID RemoveOverGift();
	//��ȡ�Լ������Ϣ(�ͻ���)
	VOID GetGiftInfo(UINT32 dwPlayerID, C64Set& setKey, DT_GVG_GIFT_DATA_LST_CLI& stGiftCli);
	//��ȡ�Լ������Ϣ(�����)
	BOOL GetGiftInfo(UINT64 qwKey, DT_GVG_GIFT_REWARD_DATA& stData);
	//��ȡ�����Ʒ
	EM_RESULT AddGiftGoods(CPlayer* poPlayer, UINT64 qwKey);
	//��ȡ�Լ�δ��ȡ�����ID
	VOID GetUnGetGiftKey(UINT32 dwPlayerID, C64Set& getKey, C64Set& ungetKey);
	//�����ն����
	BOOL AddContinueKill(UINT32 dwPlayerID, UINT16 wSessionID, UINT8 byGvGRound, UINT8 byBattleIdx, UINT8 byKillNum);
	//���ս�����
	VOID AddBattleReward(UINT32 dwFactionID, UINT8 byRound, UINT8 byBattleIdx, const TCHAR* aszFactionName, UINT8 byResult);
	//������ν���
	VOID AddRankReward(UINT32 dwFactionID, UINT8 byRound, UINT8 byRank);
	//�����������
	VOID AddHononReward( UINT32 dwFactionID);

	//��������DB
	VOID AddGiftTODB();
	//Ҫ��ӵ����ID
	UINT8 GetBattleGiftID(UINT8 byRound, UINT8 byResult);
	UINT8 GetRankGiftID(UINT8 byRound, UINT8 byRank);
public:
	//�����KEY
	UINT64 GetGiftKey(UINT32 dwPlayerID, UINT16 wSessionID, UINT8 byGvGRound, UINT8 byBattleIdx);
	//��ն��KEY
	UINT64 GetContinueKillKey(UINT32 dwPlayerID, UINT16 wSessionID, UINT8 byGvgRound, UINT8 byBattleIdx);
private:
	//���ս�����
	VOID AddBattleRewardByPlayerID(UINT32 dwPlayerID, UINT8 byRound, UINT8 byBattleIdx, const TCHAR* aszFactionName, UINT8 byResult);
	//������ν���
	VOID AddRankRewardByPlayerID(UINT32 dwPlayerID, UINT8 byRound, UINT8 byRank);
	//�����������
	VOID AddHononRewardByPlayerID(UINT32 dwPlayerID, TCHAR* aszFactionName);
	//������
	VOID AddGiftReward(DT_GVG_GIFT_REWARD_DATA& stData);
	BOOL LoadGiftFromDB();
private:
	CVecGiftRewardData m_vecAddToDBGift;//Ҫ�������ݿ��е�
	CMapGvGGiftReward m_mapGiftReward;//�Ѿ�����DB�е����
};
#endif //_gvggiftmgr_h_