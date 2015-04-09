
#ifndef _LOGICFUNC_H_
#define _LOGICFUNC_H_

#include <sdtype.h>
#include "burstprop.h"
#include "basedefine.h"
#include <common/client/commondef.h>


struct tagDT_ATTR_INC_DATA;
typedef tagDT_ATTR_INC_DATA DT_ATTR_INC_DATA ;

//������������ֵ
struct SEncouragePropValue
{
	EBurstKind	eBurstKind; //������Ʒ����
	//
	UINT16 wSubKind;//eBurstKindΪEBKIND_ITEM�����ǵ���ID��ΪEBKIND_ATTRIBUTEʱ������EBattleAttributeKind
	
	//����������ʱ��,ֵ(����/��Ǯ/�����/����ʱΪ����ֵ)
	union 
	{
		UINT16 wNum;
		UINT32 dwValue;//��Ǯ��������Ӧ��Ϊ����
		INT32 nValue; 
	};
	SEncouragePropValue()
	{
		eBurstKind = EBKIND_INVALID;
		wSubKind = 0;
		wNum = 0;
	}
};



//��������
enum EEncourageType
{
	EET_BATTLE = 0, //ս��
	EET_PASS = 1, //ͨ��
	EET_TASK = 2, //����
	EET_RACE = 3, //����
};

class CPlayer;

//���õ��߼���������
class CLogicFunc
{
public:
	static BOOL Encourage(CPlayer* poOwner, SBurst* pstBurst, BOOL bFirstFlag = FALSE);//����
	static BOOL Encourage(CPlayer* poOwner, SEncourageProp& stEncourageProp, BOOL bFirstFlag = FALSE);//����

	static BOOL FirmPropValue(SEncouragePropValue& stEncouragePropValue, SBurst* pstBurst, BOOL bFirstFlag);//ȷ����������ֵ
	static BOOL FixValue(SEncouragePropValue& stEncouragePropValue, EBurstKind eBurstKind, SProp* pstProp);//�̶�ֵ��ֵ
	static BOOL RandomValue(SEncouragePropValue& stEncouragePropValue, EBurstKind eBurstKind, vector<SProp*>& vecProp);//���ֵ��ֵ������δ���У���FALSE

	//static BOOL EncourageItem(CPlayer* poOwner, UINT16 wItemKindID, UINT16 wItemNum);//������Ʒ,����������FALSE��ͬʱ������ʱ������
	
	static UINT32 GetInstanceIdxKey(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);
	static UINT64 GetInstanceIdxKey(UINT32 dwPlayerID,UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx);
	static VOID	  GetInctanceID(UINT32 dwID, DT_INSTANCE_ID& stInstanceID);

	static UINT64 GetObjKey(UINT32 dwPlayerID, UINT16 wKindID);
	static UINT64 GetObjKey(UINT32 dwPlayerID, UINT16 wID1, UINT16 wID2);
	static UINT64 GetItemKey(UINT32 dwPlayerID, UINT16 wKindID, UINT16 wIdx=1); //wIdxΪͬ���͵��ߵ����
	//static UINT64 Get321616Key(UINT32 dwPlayerID,UINT16 wValue1,UINT16 wValue2); 
	static UINT16 Get88Key(UINT8 bywValue1,UINT8 byValue2);
	static UINT32 Get888Key(UINT8 bywValue1,UINT8 byValue2, UINT8 byValue3);
	static UINT32 Get8888Key(UINT8 bywValue1,UINT8 byValue2, UINT8 bywValue3, UINT8 byValue4);
	static UINT32 Get1688Key(UINT16 wValue1,UINT8 bywValue2,UINT8 byValue3);
	static UINT32 Get1616Key(UINT16 wValue1,UINT16 wValue2);
	static UINT64 Get161616Key(UINT16 wValue1,UINT16 wValue2,UINT16 wValue3);
	static UINT64 Get3232Key(UINT32 dwValue1,UINT32 dwValue2);
    static UINT64 Get3216Key(UINT32 dwGroupID, UINT16 wLevel);
	static VOID AddAttr(SAllAttrProp& stAttr, UINT8 byAttrKind, UINT32 dwAttrValue);
	static VOID AddAttr(const SAllAttrProp* pstSrc, DT_BATTLE_BASE_ATTRIBUTE& stDstBattleAttr, DT_HIDE_BATTLE_ATTRIBUTE& stDstHideBattleAttr, DT_EXT_BATTLE_ATTRIBUTE& stDstExtBattleAttr);
	static VOID ParseAttr(const SAllAttrProp& stAttr, const UINT8 byMaxDstNum, UINT8& byIncAttrNum, DT_ATTR_INC_DATA astIncAttrInfo[]);
};


#endif

