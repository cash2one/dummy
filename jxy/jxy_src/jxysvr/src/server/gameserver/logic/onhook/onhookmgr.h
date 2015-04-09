
#ifndef _ONHOOKMGR_H_
#define _ONHOOKMGR_H_

#include "onhook.h"

#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/instance/instance.h>
#include <sdobjectpool.h>
#include <sdmutex.h>

using namespace std;
using namespace SGDP;


typedef struct tagOnHookProp
{
    UINT16	wPassSecondPerInstance;		///< ͨ��ʱ������ÿ������
    UINT32	wNoCDGoldPerInstance;		///< ��CDÿ��������Ԫ��
} SOnHookProp;


//�һ��¼��ص�����
enum EOnhookEventRunType
{
    EOERT_START = 0,//��ʼ��һ��
    EOERT_ING = 1,//������
    EOERT_END = 2,//���һ��
};

class COnhookMgr
{
public:

    DECLARE_SINGLETON(COnhookMgr);

public:
    BOOL Init();
    VOID UnInit();

    //UINT16 GetPassSecondPerInstance() { return m_stOnHookProp.wPassSecondPerInstance; }
public:

    UINT16	Onhook(CPlayer* poPlayer, UINT8 byRunTimes, DT_INSTANCE_ID stDT_INSTANCE_ID, DT_ONHOOK_RESULT& stOnhookResult, DT_DATA_AFTER_ONHOOK& stAfterOnhookData);

    UINT16	OnhookTower(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 &byOnhookResultNum, DT_ONHOOK_RESULT astOnhookResult[MAX_INSTANCE_CLIMB_TOWER_NUM], DT_DATA_AFTER_ONHOOK &stAfterOnhookData);

    UINT16	OnhookElitInstanceByTownIndex( CPlayer *poPlayer, UINT8 byTownIndex, PKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK *pstAck );


private:
    UINT16	OnhookElitInstance( CPlayer* poPlayer, DT_INSTANCE_ID stDT_INSTANCE_ID, UINT8 &byMaxOnHookNum,
                                DT_ONHOOK_RESULT& stOnhookResult, DT_DATA_AFTER_ONHOOK& stAfterOnhookData );

    UINT16	GetOnhookResult(CPlayer* poPlayer, DT_INSTANCE_ID& stInstanceID,	UINT32& dwNoCDGold,	UINT16& wAllFinishCountDown,
                           UINT16& wNextFinishCountDown, DT_ONHOOK_RESULT& stOnhookResult, DT_DATA_AFTER_ONHOOK& stAfterOnhookData);

    UINT16	OnhookTower(CPlayer* poPlayer, DT_INSTANCE_ID stDT_INSTANCE_ID, UINT8 byMaxInstanceIdx, DT_ONHOOK_RESULT& stOnhookResult,
                        DT_DATA_AFTER_ONHOOK& stAfterOnhookData);


protected:
    COnhookMgr();
    virtual ~COnhookMgr();

protected:
    BOOL LoadFromDB();

    //��CD�һ�
    //BOOL RecordOnNoCD( CPlayer* poPlayer, UINT32 dwCostGold );
private:

    SOnHookProp	m_stOnHookProp;
};

#endif
