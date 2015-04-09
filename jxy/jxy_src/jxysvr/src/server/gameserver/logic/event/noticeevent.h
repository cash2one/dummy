#ifndef _NOTICE_EVENT_H
#define _NOTICE_EVENT_H
#include <sdframework.h>

class CNoticeEvent : public CEvent
{
public:
	CNoticeEvent();
	virtual ~CNoticeEvent();
	/**
	 * @brief
	 * ��ʱ������
	 */
	virtual UINT32 OnEvent();
    virtual INT32  OnDestroy();
	VOID		SetParam(UINT8	byNoticeType, UINT32 dwStartTime, UINT32	 dwEndTime, UINT32 dwStartEnterTime) 
	{ 
		m_byNoticeType		=	byNoticeType;
		m_dwStartTime			=	dwStartTime;
		m_dwEndTime			=	dwEndTime;
		m_dwStartEnterTime	=	dwStartEnterTime;
	}
	UINT32	GetInterval();
public:
	UINT8	m_byNoticeType;//֪ͨ������
	UINT32	m_dwStartTime;
	UINT32	m_dwEndTime;
	UINT32	m_dwStartEnterTime;
};

#endif