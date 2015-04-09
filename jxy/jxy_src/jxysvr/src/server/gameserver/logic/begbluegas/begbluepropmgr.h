
#ifndef _BEGBLUEPROPMGR_H_
#define _BEGBLUEPROPMGR_H_

#include <sdtype.h>
#include <sdhashmap.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;

const UINT32 CLIENT_VER = 304;
// ����¶����
struct SBegBlueProp
{
    UINT8   byCurrSmileCnt; // ��ǰЦ������
    
    UINT8   by0SmileOdds;   // 0��Ц���ĸ���
    UINT8   by1SmileOdds;   // 1��Ц���ĸ���
    UINT8   by2SmileOdds;   // 2��Ц���ĸ���
    UINT8   by3SmileOdds;   // 3��Ц���ĸ���
    UINT8   by4SmileOdds;   // 4��Ц���ĸ���
    UINT8   by5SmileOdds;   // 5��Ц���ĸ���
    UINT8   by6SmileOdds;   // 6��Ц���ĸ���
    
    UINT8   byX1Odds;       // ����Ϊ1�ĸ���
    UINT8   byX2Odds;       // ����Ϊ2�ĸ���
    UINT8   byX3Odds;       // ����Ϊ3�ĸ���
    UINT8   byX4Odds;       // ����Ϊ4�ĸ���
    UINT8   byX5Odds;       // ����Ϊ5�ĸ���
    UINT8   byX6Odds;       // ����Ϊ6�ĸ���

	CRandomVec vecSmileRandom; // ��ͬ����Ц���ĸ��ʣ���Ц������˳�����
	CRandomVec vecXnMultipleRandom; // ��ͬ���ʵĸ��ʣ������ʴ�С˳�����    

    UINT32  dwBlueUnit;     // ������¶ֵ
    UINT32  dwStoryUnit;    // ��������ֵ
    TCHAR   aszLuckPrompt[BEGBLUE_LUCK_PROMPT];
};

struct SBegBlueCourageProp
{
    UINT32 dwSmileNum;     //Ц������
    UINT32 dwBlue;         //����ȡ����¶
};

typedef map<UINT16, SBegBlueProp> CBegBluePropMap; // keyΪЦ���ĸ���
typedef CBegBluePropMap::iterator CBegBluePropMapItr;

typedef map<UINT32, SBegBlueCourageProp> CBegBlueCouragePropMap; // keyΪ�ۼƵ���¶
typedef CBegBlueCouragePropMap::iterator CBegBlueCouragePropMapItr;
typedef CBegBlueCouragePropMap::reverse_iterator CBegBlueReverseCouragePropItr;

class CBegBluePropMgr : public CBasePopMgr
{
public:
	DECLARE_SINGLETON_PROPMGR(CBegBluePropMgr);

public:
	virtual EConfigModule GetConfigModuleType() { return ECM_BEGBLUE; }

	BOOL Init();

	VOID UnInit();

public:	
	//CBegBluePropMap& GetBegBluePropMap() { return m_mapBegBluePropMap; }
	BOOL GetBegBlueRes(UINT16 wLastSmileCnt, UINT16& wNewSmileCnt, UINT16& wXnMultiple, 
		               UINT32& dwBlueUnit, UINT32& dwStoryUnit, TCHAR aszLuckPrompt[BEGBLUE_LUCK_PROMPT], UINT32 dwCliver);
    SBegBlueCourageProp* GetBegBlueCourageProp(UINT32 dwSmileNum);

    CBegBlueCouragePropMap GetEncourageProp() { return m_mapBegBlueCourageProp; }
    //��ȡ������ʾ
    VOID GetEncouragePrompt(UINT32 dwSmileNum ,TCHAR aszEncouragePrompt[BEGBLUE_ENCOURAGE_PROMPT]);
public:
	CBegBluePropMgr();
	virtual ~CBegBluePropMgr();

protected:
	BOOL LoadBegBluePropFromDB();
    BOOL LoadBegBlueCouragePropFromDB();
    
private:
	CBegBluePropMap m_mapBegBluePropMap; // ����¶����
    CBegBlueCouragePropMap m_mapBegBlueCourageProp;
};

#endif // 

