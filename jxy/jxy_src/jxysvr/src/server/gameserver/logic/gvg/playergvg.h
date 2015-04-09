///<------------------------------------------------------------------------------
//< @file:   logic\gvg\playergvg.h
//< @author: kang_zhiquan
//< @date:   2014��4��25�� 14:22:27
//< @brief:  ������ϵĿ������ս���󣬹���Ѻע��ʷ������ȡ�������Ϣ
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _playergvg_h_
#define _playergvg_h_

#include <protocol/server/protocligs.h>

#include "logic/base/baseobj.h"
#include "logic/base/basedefine.h"
#include "common/client/commondef.h"

#include "common/server/utility.h"

class CPlayerGVG : public CBaseObj
{

	typedef std::map<UINT64, DT_GAMBLE_DATA> CMapGambleData;
	typedef CMapGambleData::iterator CMapGambleDataItr;
public:
	CPlayerGVG()
	{
		Clear();
	}
	~CPlayerGVG()
	{
		Clear();
	}

    void Clear()
    {
        memset(&m_stGVGData, 0, sizeof(DT_PLAYER_GVG_DATA));
        m_mapGambleData.clear();
    }

	BOOL Init(DT_PLAYER_GVG_DATA& stData, CPlayer* poOwner);
	DT_PLAYER_GVG_DATA& GetPlayerGVGData();

	VOID ResetGambleInfo();

	VOID GetGambleReward();

	UINT32 GetGambleFactionID(DT_GVG_ROUND&);

	//����ֵ��TRUE Ϊ ��Ѻע�� FALSE ΪδѺע
	BOOL IsGamble(DT_GVG_ROUND&);
public:
	UINT16 OpenMyGamble(PKT_CLIGS_GVG_OPEN_MY_GAMBLE_ACK& stAck);
	UINT16 GambleFactionAck(PKT_CLIGS_GVG_GAMBLE_REQ& stReq);
	UINT16 GetGvGFormationPlayerTip(PKT_CLIGS_READ_FORMATION_PLAYER_TIP_ACK& stAck);
	UINT16 OpenMyGvGift(PKT_CLIGS_OPEN_GVG_GIFT_ACK& stAck);
	UINT16 GetMyGift( PKT_CLIGS_GET_GVG_GIFT_REQ& stReq, PKT_CLIGS_GET_GVG_GIFT_ACK& stAck);
	UINT8 GetUnGetGiftNum();

    // ��ȡδ������ս������
    UINT16 GetUnReadLogCnt();

    // ������ҵ�ս���Ķ����Ϊ�����Ķ���ȫ��ս��
    void ClearUnReadLogCnt();

private:
	BOOL GetIdxByGambleRound(DT_GVG_ROUND& eRound, UINT8& byIdx );
	//���Ѻע��Ϣ
	BOOL AddGambleInfo(DT_GVG_ROUND& eGvGGamble, DT_GAMBLE_DATA& stData);
	//��ȡѺע��Ϣ
	BOOL GetGambleFactionInfo(UINT64 qwGambleID, GvGGambleResult eResult, UINT32 dwSuportFactionID, DT_GAMBLE_GAME_INFO& stInfo);
	//��ȡһ�����
	UINT16 GetSingleGift(UINT64 qwKey);
	//��ȡȫ�����
	UINT16 GetAllGift();

private:
	DT_PLAYER_GVG_DATA m_stGVGData; // ������ϵ����ɿ��սʵ������
	C64Set m_setGiftKey;	//�����Ϣ
	CMapGambleData m_mapGambleData;	//Ѻע��Ϣ
	
};
DECLARE_CLASS_POOL_MGR(CPlayerGVG)

#endif //_playergvg_h_