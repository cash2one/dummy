/********************************************************************
	@file:   dealframepower.h
	@author: yewenhui
	@date:   2014��5��6�� 15��56��
	@brief:  ��̨��ȡս�������а�

	Copyright (c) 2014 heihuo. All rights reserved.
*********************************************************************/
#pragma once
#include "gmdealframe.h"
#include "protocol/server/protocommondata.h"


class DealFramePower
	: public InterfaceDealBase::CGmDealFrame
{
	enum {
		eServerRankNum		= 300,		// ȫ�����е�����
		eZoneRankNum		= 100,		// ȫ�����е�����
	};

	struct PlayerPowerRankData {
		UINT32   unPlayerID;					//���ID
		UINT32   unPower;						//���ս����
		TCHAR    szPlayerName[USERNAME_LEN];		//����ǳ�

		PlayerPowerRankData() : unPlayerID(0), unPower(0) {
			memset(szPlayerName, 0, sizeof(szPlayerName));
		}
	};

	typedef vector<PlayerPowerRankData> VecPowerRankData;

	class SortPlayerPowerRank
	{
	public:
		BOOL operator()(const PlayerPowerRankData& p1, const PlayerPowerRankData& p2) {
			return p1.unPower > p2.unPower;
		}
	};

public:
	DealFramePower(InterfaceDealBase::CGmManager* pGmManager);
	~DealFramePower();

	virtual void		Deal(CRCClient* poClinet, UINT32 dwSerialNumber, UINT8 byAction, UINT32 dwAreaID, UINT32 dwPlayerID, UINT32 dwParam1, UINT64 qwParam2, UINT64 qwParam3, TCHAR* pszParam4, TCHAR* pszParam5, TCHAR *pszDesc);   //����Э������
	virtual void		Deal(CRCClient* poClinet,UINT32 dwSerialNumber,UINT32 dwAreaID,UINT32 dwPlayerID,map<string,string> &mapField);
	virtual void		Interface(CRCClient* poClinet);
	virtual UINT16		GetFrameType();          //��ȡ��Э���෵�ص�Э�����ͺ�
	virtual string		GetStrFrameType();          //��ȡ��Э���෵�ص�Э�����ͺ�
	virtual string		GetStrFrameDesc();
	virtual void		Release();               //�ͷŶ����ṩ�ⲿ
	virtual bool		init(InterfaceDealBase::CGmManager * IN_pManager);//��ʼ��Э�������

};
