#ifndef _HUNTING_EVENT_H_
#define _HUNTING_EVENT_H_
#include <sdframework.h>

class CHuntingEvent:public CEvent
{
public:
	CHuntingEvent();
	virtual ~CHuntingEvent();
	/**
	 * @brief
	 * ��ʱ������
	 */
	virtual UINT32 OnEvent();
    virtual INT32  OnDestroy();
	VOID SetParam( BOOL bFlag );
	UINT32 GetInterval();
	BOOL GetOpenFlag(){ return m_bOpenFlag; }
public:
	BOOL m_bOpenFlag;
};
#endif