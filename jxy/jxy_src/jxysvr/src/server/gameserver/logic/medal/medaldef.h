///<------------------------------------------------------------------------------
//< @file:   logic\medal\medaldef.h
//< @author: Kang_zhiquan
//< @date:   2014��6��18�� 14:3:11
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _medaldef_h_
#define _medaldef_h_
#include <sdtype.h>
#include "protocol/server/protocligs.h"
#include <map>
#include "logic/base/jsonencourage.h"
using namespace std;
struct SMedalProp
{
	UINT16 wMedalID;//ѫ��ID
	string strMedalName;//ѫ������
	string strMedalIconName;//ͼ��ID
	UINT8 byOpenBuildID;//����ID
	UINT8 byIsLevelMedal;//�Ƿ��еȼ�
	UINT16 wSmallType;//С����������ֲ�ͬ����ѫ�£�
	string strFinishDesc;//�������
	CVecJsonAttrBase vecAttr;//����
	UINT16 wLevel;//ѫ�µȼ�
	UINT32 dwOverTime;//��Ч��
	UINT64 qwFirstCondition;//��ʼ����
	UINT64 qwSecondCondition;//ĩβ����
	UINT64 qwThirdCondition;//ĩβ����
	UINT8 byIsOverly;//�Ƿ�ɵ���
	UINT8 byMedalColor;
	SMedalProp()
	{
		wMedalID = 0;//ѫ��ID
		strMedalName ="";//ѫ������
		strMedalIconName = "";//ͼ��ID
		wSmallType = 0;//С�������������Դѫ�£�
		strFinishDesc = "";//�������
		vecAttr.clear();//����
		wLevel = 0;//ѫ�µȼ�
		dwOverTime = 0;//��Ч��
		qwFirstCondition = 0;//��ʼ����
		qwSecondCondition = 0;//��ʼ����
		qwThirdCondition = 0;
		byOpenBuildID = 0;//����ID
		byIsOverly = 0;
		byMedalColor = 0;
	}
};

typedef map<UINT16, SMedalProp> CMapMedalProp;
typedef CMapMedalProp::iterator CMapMedalPropItr;

typedef map<UINT32, SMedalProp> CMap32MedalProp;
typedef CMap32MedalProp::iterator CMap32MedalPropItr;

#endif //_medaldef_h_