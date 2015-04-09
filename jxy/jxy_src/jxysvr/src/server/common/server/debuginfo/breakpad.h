#ifndef _CBREAKPAD_H_
#define _CBREAKPAD_H_
#include <sdtype.h>
#include <memory>
using std::auto_ptr;

#ifndef __linux__
#include "client/windows/handler/exception_handler.h"
#else
#include "client/linux/handler/exception_handler.h"
#endif

class CBreakPad
{
public:
	CBreakPad();
	virtual ~CBreakPad();

	/**
	* @brief ��ʼ���쳣������Ϣ
	* @return VOID
	*/
	static VOID Init();

	/**
	* @brief ���ʼ�����ͷ���Դ
	* @return VOID
	*/
	static VOID UnInit();
private:

#ifndef __linux
	static bool DumpsCallback(const wchar_t *pStrDumpPath, const wchar_t *pStrID,  
		void *pContext, EXCEPTION_POINTERS *pExceptInfo,  
		MDRawAssertionInfo *pAssertion,  
		bool bSucceeded);

#else
	static bool DumpsCallback(const google_breakpad::MinidumpDescriptor& descriptor,
		void* pContext,
		bool bSucceeded);

#endif


private:

#ifndef __linux__
	static google_breakpad::ExceptionHandler *sm_pHandler; //�����쳣�Ķ���
#else
	static google_breakpad::MinidumpDescriptor *sm_pDumpDescript; //��������������
	static google_breakpad::ExceptionHandler *sm_pHandler; //�����쳣�Ķ���
#endif

};

#endif