#ifndef BASICLOGGER_H
#define BASICLOGGER_H
#include "sdtime.h"
#include "loggerutils.h"
using namespace SGDP;
class CBasicLogger
{
public:
	CBasicLogger();
	~CBasicLogger();

	bool Init(INT32 nMode, UINT32 dwID,	const CHAR* pszDir, const CHAR* pszName);
	bool Log(const TCHAR* pData, INT32 nLen);
    bool LogEx(const TCHAR* pData, INT32 nLen);
	void Flush();

protected:
	void _UpdateFilePointer();  //����ʱ�����־�ļ��ļ�¼��ʽ�����Ƿ�Ҫ����һ���µ���־�ļ�

protected:
	INT32		m_nLogMode;
	UINT32		m_dwID;
	CHAR		m_szDir[MAX_PATH];
	CHAR		m_szName[128];
	FILE*		m_fpFile;
	bool		m_bDirty;
	INT32		m_nSubFile;
	CSDDateTime m_stTime ;
};

#endif

