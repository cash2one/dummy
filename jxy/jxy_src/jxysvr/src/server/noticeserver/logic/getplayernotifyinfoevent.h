

#ifndef _GET_PLAYER_NOTITY_INFO_EVENT_H_
#define _GET_PLAYER_NOTITY_INFO_EVENT_H_

#include <sdframework.h>

using namespace SGDP;

class CGetPlayerNotifyInfoEvent : public CEvent
{
public:
    CGetPlayerNotifyInfoEvent();
    virtual ~CGetPlayerNotifyInfoEvent();
    /**
     * @brief
     * ��ʱ������
     */
    virtual UINT32 OnEvent();
    virtual INT32  OnDestroy();
	UINT32		  GetInterval(){return ms_nInterval;};
public:
	const static int ms_nInterval = 60;
};
#endif

