#ifndef _HTTP_SYNC_EVENT_H
#define _HTTP_SYNC_EVENT_H
#include <sdframework.h>

class CHttpSyncEvent:public CEvent
{
public:
	CHttpSyncEvent();
	virtual ~CHttpSyncEvent();
	/**
	 * @brief
	 * ��ʱ������
	 */
	virtual UINT32 OnEvent();
    virtual INT32  OnDestroy();

	UINT32	GetInterval();
public:
	const static int ms_nInterval = 180;
};

#endif