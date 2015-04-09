#include "breakpad.h"
#include "common/server/utility.h"

#ifndef __linux__

google_breakpad::ExceptionHandler *CBreakPad::sm_pHandler=NULL;

//windowsƽ̨�µ�break�ص�����
bool CBreakPad::DumpsCallback(const wchar_t *pStrDumpPath, const wchar_t *pStrID,  
	void *pContext, EXCEPTION_POINTERS *pExceptInfo,  
	MDRawAssertionInfo *pAssertion,  
	bool bSucceeded)
{  
	if (bSucceeded) 
	{  
		wstring strDes=L"dump·����";
		strDes+=pStrDumpPath;
		strDes+=L"\\";
		strDes+=pStrID;
		strDes+=L".dmp";
		//::MessageBoxW( NULL, strDes.c_str(), L"�����Ѿ�����", NULL ); 
	} 
	else 
	{  
		//::MessageBoxW( NULL, L"Minidumpʧ��", L"�����Ѿ�����", NULL );  
	}  
	fflush(stdout);
	return bSucceeded;  
}

#else

google_breakpad::MinidumpDescriptor *CBreakPad::sm_pDumpDescript(NULL);
google_breakpad::ExceptionHandler *CBreakPad::sm_apHandler(NULL);

//linuxƽ̨�µ�break�ص�����
bool CBreakPad::DumpsCallback(const google_breakpad::MinidumpDescriptor& descriptor,
	void* pContext,
	bool bSucceeded)
{
	printf("Dump path: %s\n", descriptor.path());
	return bSucceeded;
}

#endif

VOID CBreakPad::Init()
{
#ifndef __linux__
	wchar_t szPath[MAX_PATH];
	GetCurrentDirectoryW( MAX_PATH, szPath );
	sm_pHandler=new google_breakpad::ExceptionHandler(
		szPath, NULL, DumpsCallback, NULL,  
		google_breakpad::ExceptionHandler::HANDLER_ALL) ;  
#else
	sm_pDumpDescript=new google_breakpad::MinidumpDescriptor("");
	sm_pHandler=new ( *sm_pDumpDescript,NULL,
		DumpsCallback, NULL, true, -1 );
#endif
}


VOID CBreakPad::UnInit()
{
	SAFE_DELETE( sm_pHandler );
#ifdef __linux__
	SAFE_DELETE( sm_pDumpDescript );
#endif
}