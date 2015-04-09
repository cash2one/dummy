#ifndef _BURSTPROP_H_
#define _BURSTPROP_H_

#include <sdtype.h>
#include <sdhashmap.h>
#include <sdxmlfile.h>
#include <sdstring.h>
#include <common/client/commondef.h>

using namespace SGDP;
using namespace std;

//
struct SProp
{
	//
	union 
	{
		UINT16 wMin;
		UINT16 wKindID;		
	};
	//
	union		
	{
		UINT32 dwMax;
		UINT16 wNum; //����ʱ
		UINT32 dwValue;//�̶�ֵʱ,��Ǯ��������Ӧ��Ϊ����
		INT32 nValue;//�̶�ֵʱ
		INT32 nNum; //����ʱ��value�ֶ�
	};
	UINT16 wRate;		//�ٷֱ�
	BOOL bFirstFalg;  //��һ�αظ���־��TRUE�������һ��SBurst��ֻ����1����

	SProp() 
	{ 
		wMin = 0;
		dwMax = 0;
		wRate =  0;
		bFirstFalg = FALSE;
	}
};

//����/����/������Ʒ����
struct SBurst
{
	EBurstKind	eBurstKind; //������Ʒ����
	BOOL		bRandom;	//���������(������)��FALSEΪ�̶�ֵ��ȡ��һ����¼��wValue (�� <Gold Value="10" /> )
	vector<SProp*>	vecProp;	//����ÿ����Ϣ��bRandomTypeΪFALSE(�̶�ֵ)ʱֻ��1����¼;����������ȡvecProp�е�1��SProp����ʹ��SProp��wRate�������һ��ֵ����һ�ν�����ѡFirstFalgΪ1��ֵ
		/*
		<Coin>
			<Prop Min="1" Max="100" Rate="50" />
			<Prop Min="101" Max="200" Rate="30" />
			<Prop Min="201" Max="300" Rate="20" FirstFalg="1" />
		</Coin>
		*/

	SBurst() 
	{ 
		eBurstKind = EBKIND_INVALID;
		bRandom = FALSE;
	}
	~SBurst();
};


typedef vector<SBurst*> CBurstVec;
typedef CBurstVec::iterator CBurstVecItr;

typedef HashMap<string, EBattleAttributeKind> CStr2BattleAttrKindMap;
typedef CStr2BattleAttrKindMap::iterator CStr2BattleAttrKindMapItr;	

//��������
struct SEncourageProp
{
	CBurstVec		vecBurst;	//����������
	CBurstVec		vecBurstItemGroup;	//�������ߵ�����(���飬ÿ��1��SBurst)�����ȡ1��
	/*
	<Item>
		<Group>
			<Prop KindID="10001" Num="1" Rate="50" FirstFalg="1" />
			<Prop KindID="10002" Num="1" Rate="10" />
		</Group>				
		<Group>
			<Prop KindID="10002" Num="1" Rate="50" />
			<Prop KindID="10003" Num="1" Rate="10" />
		</Group>	
		<Group>
			<Prop KindID="10001" Num="1" Rate="50" />
			<Prop KindID="10002" Num="1" Rate="10" />
		</Group>
		<Group KindID="10001" Num="1" />				
	</Item>
	*/
	~SEncourageProp();
};

BOOL ReadRandomBurst(EBurstKind eBurstKind, SBurst* pstBurst, CSDXMLNode xmlNode);
BOOL ReadBurstItem(EBurstKind eBurstKind, CBurstVec& vecBurst, CSDXMLNode xmlNode);
EBattleAttributeKind GetBattleAttrKindByStr(string strAttr);
BOOL ReadEncourageItemGroup(CBurstVec& vecBurst, CSDXMLNode xmlNode);
BOOL ReadEncourage(SEncourageProp* pstEncourageProp, CSDXMLNode xmlNode);////��ȡ����

#endif

