#include "encouragemgr.h"
#include "onlineencouragemgr.h"
#include "loginencouragemgr.h"
#include <dll/sdframework/sdloggerimpl.h>

IMPLEMENT_SINGLETON(CEncourageMgr)


CEncourageMgr::CEncourageMgr()
{

}

CEncourageMgr::~CEncourageMgr()
{
	COnlineEncourageMgr::DestroyInstance();
}

BOOL CEncourageMgr::Init()
{
	// ��ʼ��COnlineEncourageMgr������
	if(FALSE == COnlineEncourageMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: COnlineEncourageMgr::CreateInstance failed!"), MSG_MARK);        
		return FALSE;
	}
	if(FALSE == COnlineEncourageMgr::Instance()->Init())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: COnlineEncourageMgr Init failed!"), MSG_MARK);        
		return FALSE;
	}

	// ��ʼ��CLoginEncourageMgr������
	if(FALSE == CLoginEncourageMgr::CreateInstance())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CLoginEncourageMgr::CreateInstance failed!"), MSG_MARK);        
		return FALSE;
	}
	if(FALSE == CLoginEncourageMgr::Instance()->Init())
	{
		SYS_CRITICAL(_SDT("[%s: %d]: CLoginEncourageMgr Init failed!"), MSG_MARK);        
		return FALSE;
	}
	

	return TRUE;

}

VOID CEncourageMgr::UnInit()
{
	COnlineEncourageMgr::Instance()->UnInit();
}

