
#ifndef SDERRNO_H
#define SDERRNO_H
/**
* @file sderrno.h
* @brief �������
*
**/
#include "sdtype.h"

#if (defined(WIN32) || defined(WIN64))
#else
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sdstring.h>
#endif
/**
* @brief Type for specifying an error or status code.
*/
namespace SGDP
{
    /**
    * @defgroup grouperror errno����
    * @ingroup  SGDP
    * @{
    */

    typedef INT32  SDErrNo;

#if (defined(WIN32) || defined(WIN64))
    /**
    * @brief
    * ����errno����
    * @param dwErrCode : �����error code
    * @return VOID
    */
    inline VOID  SDSetLastError(DWORD dwErrCode)
    {
        SetLastError(dwErrCode);
    }

    /**
    * @brief
    * ��ȡerrno����
    * @return ����errno code
    */
    inline SDErrNo  SDGetLastError()
    {
        return GetLastError();
    }

    /**
    * @brief
    * ��error����ת�����ַ���
    * @param errnum : �����error code
    * @return error code��Ӧ���ַ���
    */
    inline TCHAR*  SDStrError(INT32 errnum)
    {
		return _tcserror(errnum);
    }

    /**
    * @brief
    * �õ���������µ��ַ�������
    * @return ������ַ�������
    */
    inline TCHAR*  SDLastStrError()
    {
		return _tcserror(NULL);
    }
#else
    /**
    * @brief
    * ����error����
    * @param dwErrCode : �����error code
    * @return VOID
    */
    inline VOID  SDSetLastError(INT32 dwErrCode)
    {
        errno = dwErrCode;
    }

    /**
    * @brief
    * ��ȡerror����
    * @return ����error code
    */
    inline SDErrNo  SDGetLastError()
    {
        return errno;
    }

    /**
    * @brief
    * ��error����ת�����ַ���
    * @param errnum : �����error code
    * @return errno code��Ӧ���ַ���
    */
    inline TCHAR*  SDStrError(INT32 errnum)
    {
        CHAR* szError = strerror(errnum);
        if (szError)
        {
            return (TCHAR*)_SDTA2T(szError);
        }
        return _SDT("");
    }

    /**
    * @brief
    * �õ���������µ��ַ�������
    * @return ������ַ�������
    */
    inline TCHAR*   SDLastStrError()
    {
        return SDStrError(errno);
    }
#endif // WIN32 


} // namespace SGDP

#endif // 

