#ifndef _CHAT_EVENT_H
#define _CHAT_EVENT_H
#include <sdframework.h>

class CChatEvent:public CEvent
{
public:
	CChatEvent();
	virtual ~CChatEvent();
	/**
	 * @brief
	 * ��ʱ������
	 */
	virtual UINT32 OnEvent();
    virtual INT32  OnDestroy();

	UINT32	GetInterval();
public:
	const static int ms_nInterval = 5;
};

#endif