
#ifndef _CSAVECKOFFLINEEVENT_H
#define _CSAVECKOFFLINEEVENT_H


#include "eventreactor.h"

using namespace SGDP;

///����/���ǵ�¼�����������¼�,�豣���򱣳֣�����������ڴ�
class CSaveCkOfflineEvent: public CEvent
{
public:
	CSaveCkOfflineEvent();
	virtual ~CSaveCkOfflineEvent();
	virtual UINT32 OnEvent();
	virtual BOOL OnDestroy();
public:
	VOID SetParam(UINT32 dwPlayerID);
private:
	UINT32	m_dwPlayerID;
};

#endif


