#include "autosqlbuf.h"

#include <framework/gsapi.h>

CAutoSqlBuf::CAutoSqlBuf()
{
    m_pszSqlBuf = (CHAR*)(gsapi::GetSQLMemory());
    *m_pszSqlBuf = 0;//����strcatû�д�ͷ��ʼ
}
CAutoSqlBuf::~CAutoSqlBuf()
{
    if(m_pszSqlBuf)
    {
        gsapi::FreeSQL(m_pszSqlBuf);
        m_pszSqlBuf = NULL;
    }
}

CHAR* CAutoSqlBuf::GetSqlBuf()
{
    return m_pszSqlBuf;
}
