
#ifndef _CSAVEPVPEVENT_H
#define _CSAVEPVPEVENT_H


#include "eventreactor.h"

using namespace SGDP;

///�������pvp��Ϣ�¼�
class CSavePvpEvent: public CEvent
{
public:
	CSavePvpEvent();
	virtual ~CSavePvpEvent();
	virtual UINT32 OnEvent();
	virtual BOOL OnDestroy();
};

#endif


