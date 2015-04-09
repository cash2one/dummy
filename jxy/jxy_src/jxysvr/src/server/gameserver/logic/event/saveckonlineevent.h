
#ifndef _CSAVEONLINEEVENT_H 
#define _CSAVEONLINEEVENT_H


#include "eventreactor.h"

using namespace SGDP;

///�����¼�����������¼�
class CSaveOnlineEvent: public CEvent
{
public:
	CSaveOnlineEvent();
	virtual ~CSaveOnlineEvent();
	virtual UINT32 OnEvent();
	virtual BOOL OnDestroy();
public:
	VOID SetParam(UINT32 dwPlayerID);
private:
	UINT32	m_dwPlayerID;
};

#endif


