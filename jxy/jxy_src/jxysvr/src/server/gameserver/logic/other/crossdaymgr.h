
#ifndef _CROSSDAYMGR_H_
#define _CROSSDAYMGR_H_

#include <common/server/utility.h>

class CPlayer;
class CCrossDayMgr
{
public:

	static VOID OnCrossDayEvent();
	//���߽���
	static VOID OnOnlineEncourage(CPlayer* poPlayer);
	//��ʱѫ�¼���
	static VOID OnLimitTimeMedal(CPlayer* poPlayer);
};

#endif // 
