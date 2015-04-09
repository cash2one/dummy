///<------------------------------------------------------------------------------
//< @file:   logic\medal\medal.h
//< @author: Kang_zhiquan
//< @date:   2014��6��17�� 19:21:34
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _medal_h_
#define _medal_h_
#include "logic/base/baseobj.h"
#include "protocol/server/protocommondata.h"
#include "logic/medal/medaldef.h"
#include "logic/player/player.h"

class CMedal : public CBaseObj
{
public:
	CMedal();
	virtual ~CMedal();
	 BOOL Init(CPlayer* poPlayer, const DT_MEDAL_DATA& stData);
public:
	 //��ȡ������
	 virtual UINT8 GetBigType() = 0;
	 //��ȡС����
	 UINT16 GetSmallType();
	 //�Ƿ�ɵ��� True���ɵ���
	 BOOL GetIsOverlay();
	 //�Ƿ��ǵȼ�ѫ��
	 BOOL IsLevelMedal();
	 //��ȡѫ��ID
	 UINT16 GetMedalID();
	 //��ȡѫ��LEVEL
	 UINT16 GetLevel();
	 //��ȡ�����Ľ���ID
	 UINT16 GetBuildID();
	 //�Ƿ񼤻�
	virtual BOOL IsActivate();
	const DT_MEDAL_DATA& GetMedalData();
	//��⼤��
	virtual BOOL CheckActivate() = 0;
	//����ֵ
	BOOL GetMedalAttr(const CVecJsonAttrBase*&);
	//��ȡ����
	BOOL GetProp(const SMedalProp*& poProp);
	//���ü���
	virtual BOOL SetActivateState(BOOL bIsActivate, UINT64 qwActivateTime = SGDP::SDTimeSecs());
	//��ȡ�ͻ�����Ϣ
	virtual VOID GetMedalCli(DT_MEDAL_DATA_CLI& stCli);
	//��ȡѫ��ͼ��ID
	string GetMedalIconID();
protected:
	DT_MEDAL_DATA m_stMedalData;
};

class CTimeMedal : public CMedal
{
public:
	//TRUEΪ����
	//FALSEΪδ����
	virtual BOOL IsOverTime();
	virtual UINT8 GetBigType();
protected:
};

class CNoneTimeMedal : public CMedal
{
public:
	virtual UINT8 GetBigType();
protected:
};

#endif //_medal_h_