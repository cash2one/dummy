
#include "twodaysnotonlinenotifyevent.h"
#include "framework/nsapplication.h"
#include "logic/basedbccmd.h"
#include <sdutil.h>

CTwoDaysNotOnlineNotityEvent::CTwoDaysNotOnlineNotityEvent()
{
    m_qwNoticeTime = 0;
}

CTwoDaysNotOnlineNotityEvent::~CTwoDaysNotOnlineNotityEvent()
{

}

UINT32 CTwoDaysNotOnlineNotityEvent::OnEvent()
{
    if (IsToday(m_qwNoticeTime))
    {
        return 0;
    }

    //��ǰʱ��
    CSDDateTime SDNow(SDTimeSecs());
    if (SDNow.GetHour() != ((CNSApplication*)SDGetApp())->GetNSConfig()->GetNoticeTime())
    {
        return 0;
    }

    static char * szdata = "����Ѿ���������δ��¼��";
    CBaseDBCMD* poCMD = ((CNSApplication*)SDGetApp())->GetDBMgr()->CreateCmd(EDBCT_TWO_DAYS_NOT_ONLINE_NOTICE_INFO);
    if(NULL == poCMD)
    {
        SYS_CRITICAL(_SDT("[%s: %d]:OnEvent CNoticeEvent �����쳣 "), MSG_MARK);
        return 0;
	}

	poCMD->SetUserData((const VOID*)SDLocal2UTF8(szdata).c_str(), SDLocal2UTF8(szdata).size(), 0);
	((CNSApplication*)SDGetApp())->GetDBMgr()->AddCommand(poCMD);

	m_qwNoticeTime = SDTimeSecs();
	//DBG_INFO(_SDT("[%s: %d]:OnEvent CNoticeEvent �������"), MSG_MARK);
	return 0;
}

INT32  CTwoDaysNotOnlineNotityEvent::OnDestroy()
{
    return 0;
}

