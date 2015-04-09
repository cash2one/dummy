#ifndef _CTIMEREVENTMGR_H_
#define _CTIMEREVENTMGR_H_

#include <eventreactor.h>
#include <sdsingleton.h>
#include <sdhashmap.h>
#include "saveckofflineevent.h"
#include "saveckonlineevent.h"
#include "releasecaptureevent.h"
#include "rechargeevent.h"
#include "savepvpevent.h"
#include "chatevent.h"
#include "crossdayevent.h"
#include "yabiaoevent.h"
#include "noticeevent.h"
#include "bossbattleevent.h"
#include "gsnoticeevent.h"
#include "activityencourageevent.h"
#include "httpsyncevent.h"
#include "courageevent.h"
#include "givewineevent.h"
#include "drinkwine.h"
#include "huntingevent.h"
#include "couragerefreshevent.h"
#include "logic/gvg/global/gvgevent.h"

#define MAX_SAVE_ONLINE_EVENT_NUM		10000
#define MAX_SAVE_CK_OFFLINE_EVENT_NUM	10000
#define MAX_RELEASE_CAPTURE_EVENT_NUM	10000


typedef map<UINT64, CReleaseCaptureEvent*> CReleaseCaptureEventMap;
typedef CReleaseCaptureEventMap::iterator CReleaseCaptureEventMapItr;

typedef map<UINT64, CSaveCkOfflineEvent*> CSaveCkOfflineEventMap;
typedef CSaveCkOfflineEventMap::iterator CSaveCkOfflineEventMapItr;

typedef map<UINT64, CSaveOnlineEvent*> CSaveOnlineEventMap;
typedef CSaveOnlineEventMap::iterator CSaveOnlineEventMapItr;

typedef map<UINT32, CYabiaoEvent*> CYabiaoEventMap;
typedef CYabiaoEventMap::iterator CYabiaoEventMapItr;

typedef map<UINT16, CBossBattleEvent*> CBossBattleEventMap;
typedef CBossBattleEventMap::iterator CBossBattleEventMapItr;


typedef map<UINT16, CCourageEvent*> CCourageEventMap;
typedef CCourageEventMap::iterator CCourageEventMapItr;

typedef map<UINT32, CGiveWineEvent*> CGiveWineEventMap;
typedef CGiveWineEventMap::iterator  CGiveWineEventMapItr;

typedef map<UINT32, CDrinkWineEvent*> CDrinkWineEventMap;
typedef CDrinkWineEventMap::iterator  CDrinkWineEventMapItr;

typedef map<BOOL, CHuntingEvent*> CHuntingEventMap;
typedef CHuntingEventMap::iterator CHuntingEventMapItr;

//typedef map<UINT32, CCourageFireEvent*>CCourageFireEventMap;
//typedef CCourageFireEventMap::iterator CCourageFireEventMapItr;

/**
* @brief��ʱ���¼�������
*/
class CTimerEventMgr
{
    DECLARE_SINGLETON(CTimerEventMgr)

public:

	//��ʼ�����ҹ���һЩ��פϵͳ�¼�
    BOOL            Init();

    BOOL            UnInit();

    /**
    * @brief ��Ӧ�������ڷ�Ӧ��������������ӵ���Ӧ���е��¼�����
    */
	VOID            Run();

    // ������еĶ�ʱ��
    VOID Clear();

public:	
	//

	CReleaseCaptureEvent* AddReleaseCaptureEvent(UINT32 dwOwnerID, UINT32 dwCaptureID, UINT32 dwInterval);
	BOOL DelReleaseCaptureEvent(UINT32 dwOwnerID, UINT32 dwCaptureID);

	CSaveCkOfflineEvent* AddSaveCkOfflineEvent(UINT32 dwPlayerID, UINT32 dwInterval);
	BOOL DelSaveCkOfflineEvent(UINT32 dwPlayerID);

	CSaveOnlineEvent* AddSaveOnlineEvent(UINT32 dwPlayerID, UINT32 dwInterval);
	BOOL DelSaveOnlineEvent(UINT32 dwPlayerID);

	VOID ResetCrossDayEventInterval();
	CYabiaoEvent *AddYabiaoEvent( UINT32 dwPlayerID, UINT32 dwInterval );
	BOOL DelYabiaoEvent( UINT32 dwPlayerID );

	CBossBattleEvent* AddBossBattleEvent(UINT8 byActivityID, BOOL bStartFlag);
	VOID ResetBossBattleEventInterval(CBossBattleEvent* poBossBattleEvent);

	CCourageEvent* AddCourageEvent(UINT8 byActivityID, BOOL bStartFlag);
	VOID ResetCourageEventInterval(CCourageEvent* poCourageEvent);

	CNoticeEvent* AddNoticeEventEvent(UINT8 byNoticeType, UINT32 dwStartTime, UINT32 dwEndTime, UINT32 dwStartEnterTime = 0);
	VOID ResetNotityEventInterval(CNoticeEvent* poNoticeEvent);

	CGiveWineEvent* AddGiveWineEvent(UINT32 dwFactionID, UINT32 dwInterval);
	VOID DelGiveWineEvent(UINT32 dwFactionID);

	CDrinkWineEvent* AddDrinkWineEvent(UINT32 dwPlayerID, UINT32 dwInterval);
	VOID DelDrinkWineEvent(UINT32 dwPlayerID);

	CHuntingEvent* AddHuntingEvent(BOOL bFlag);
	VOID ResetHuntingEvent(CHuntingEvent* poEvent);

    BOOL AddGvGEvent();
    void StopGvGEvent();

    VOID ResetGvGEventInterval(CGvGEvent* poNoticeEvent, UINT32 dwInterval);
    UINT32 GetGvGEventInterval();
    CGvGEvent* GetGvGEvent(){ return m_poGvGEvent; }

    CGvGReloadPropEvent* AddGvGReloadPropEvent();
    VOID ResetGvGReloadPropEventInterval(CGvGReloadPropEvent* poNoticeEvent, UINT32 dwInterval);

    CGvGRePullEvent* AddGvGRePullEvent();

protected:
    CTimerEventMgr();
    virtual ~CTimerEventMgr();

private:
    CGvGEvent *m_poGvGEvent;

private:
	CEventReactor<CSaveCkOfflineEvent>	m_oSaveCkOfflineEventReactor;		//����/���ǵ�¼�����������¼���Ӧ��
	CSaveCkOfflineEventMap				m_mapSaveCkOfflineEvent;
	CEventReactor<CReleaseCaptureEvent> m_oReleaseCaptureEventReactor;		//�ͷŷ�²��Ӧ��
	CReleaseCaptureEventMap			m_mapReleaseCaptureEvent;			
	CEventReactor<CSaveOnlineEvent>		m_oSaveOnlineEventReactor;			//�����¼�����������¼���Ӧ��
	CSaveOnlineEventMap				m_mapSaveOnlineEvent;
	CEventReactor<CRechargeEvent>		m_oRechargeEventReactor;			//��ֵ�������¼�
	CEventReactor<CSavePvpEvent>		m_oSavePvpEventReactor;			//����pvp��Ϣ�¼�
	CEventReactor<CChatEvent>			m_oChatEventReactor;				//�����¼�
	CEventReactor<CCrossDayEvent>		m_oCrossDayEventReactor;			//�����¼�
	CCrossDayEvent*					m_poCrossDayEvent;				//�����¼�
	CEventReactor<CYabiaoEvent>		m_oYabiaoEventReactor;				//Ѻ���¼�
	CYabiaoEventMap					m_mapYabiaoEvent;					//Ѻ���¼�
	CEventReactor<CNoticeEvent>		m_oNoticeEventReactor;				//֪ͨ�¼�
	CEventReactor<CBossBattleEvent>		m_oBossBattleEvenReactor;			//BOSSս�¼�
	CBossBattleEventMap				m_mapBossBattleEvent;				//BOSSս�¼�,keyΪ�ID
	CEventReactor<CGetGsNoticeEvent>	m_oGsNoticeEventReactor;		//GS����ͬ��
	CEventReactor<CCActivityEncourageEvent> m_oActivityEncourageEventReactor;//�����ͬ���¼�
	CEventReactor<CHttpSyncEvent>			m_oHttpSyncEventReactor;//�����ͬ���¼�
	
	CEventReactor<CCourageEvent>		m_oCourageEvenReactor;			//���������¼�
	CCourageEventMap					m_mapCourageEvent;			//���������¼�,keyΪ�ID
	CEventReactor<CGiveWineEvent>	m_oGiveWineEventReactor;	//�;��¼�
	CGiveWineEventMap				m_mapGiveWineEvent;

	CEventReactor<CDrinkWineEvent> m_oDrinkWineEventReactor;	//�Ⱦ�
	CDrinkWineEventMap	m_mapDrinkWineEvent;

	CEventReactor<CHuntingEvent> m_oHuntingEventRector;	//׽���¼�
	CHuntingEventMap m_mapHuntingEvent;

    CEventReactor<CCourageRefreshEvent>			m_oCourageReEventReactor;				//����ˢ���¼�

    CEventReactor<CGvGEvent>       m_oGvGEvenReactor;			    // ���ս�ִθ��涨ʱ��
    CEventReactor<CGvGReloadPropEvent> m_oGvGReloadPropEvenReactor;		    // ���ս�ػ���ʱ��
    CEventReactor<CGvGRePullEvent> m_oGvGRePullEvenReactor;			// ���ս���˶�ʱ��
};



#endif

