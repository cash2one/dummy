#ifndef DBSESSIONMGR_H_20110504
#define DBSESSIONMGR_H_20110504

#include <sdidpool.h>
#include "sdpipechannel.h"
#include <map>

	/*
	����dbִ�лظ���Ϣʱ����session�Ĺ�����ֹ�ظ�ʹ��sessionʱ��session�Ѿ��ͷ�
	*/

#define MAX_SESSION_NUM 10000

class CDbSessionMgr
{
public:
	~CDbSessionMgr();
	static CDbSessionMgr* Instance() { static CDbSessionMgr oInstance; return &oInstance; }

	UINT32 AddSession(CSDPipeChannel* poSession);
	VOID DelSession(UINT32 dwSessionId);
	CSDPipeChannel* FindSession(UINT32 dwSessionId);
protected:
	CDbSessionMgr();
private:	
	CSDIDPool<CSDPipeChannel*>		m_oIDSessionPool;//session ID �����
};

#endif //#ifndef DBSESSIONMGR_H_20110504

