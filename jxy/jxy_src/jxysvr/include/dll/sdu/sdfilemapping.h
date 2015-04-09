/******************************************************************************
		


******************************************************************************/

#ifndef SD_FILEMAPPING_H
#define SD_FILEMAPPING_H
/**
* @file sdfilemapping.h

* @brief �ļ�ӳ����
*
**/
#include <string>

#if (defined(WIN32) || defined(WIN64))
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/mman.h>
#include <stddef.h>
#include <unistd.h>
#endif

#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup groupfilemapping �ļ�ӳ��
    * @ingroup  SGDP
    * @{
    */


    /**
    * @brief �ļ�ӳ��ṹ��
    *
    */
    struct SFileMapping
    {
        VOID* mem;				/**<�����ڴ����ʼ��ַ*/
        VOID * pos;            /** ��ȡ�ڴ�ӳ���λ��*/
        UINT32 size;			/**<ӳ���ڴ�Ĵ�С*/
        SDHANDLE maphandle;		/**<�ļ���Ӧ��handle*/
    };

    /**
    * @brief
    * ӳ��һ���ļ��ε��ڴ���
    * @param stFileMapping : �ļ�ӳ��ṹ��
    * @param pszFileName : �ļ�·��
    * @param dwBeg : ӳ����ʼ���ļ�λ�ã���λ�ñ������ļ��������ȵ�������
    * @param dwSize : �ڴ��С�����Ϊ0�������ļ�����ӳ��
    * @return TRUEΪӳ��ɹ���FALSEΪӳ��ʧ��
    */
    BOOL  SDFileMapping(SFileMapping& stFileMapping, const TCHAR* pszFileName, UINT32 dwBeg =0 , UINT32 dwSize = 0 );

    /**
    * @brief
    * ȡ���ļ����ڴ��ӳ���ϵ
    * @param stFileMapping : �ļ�ӳ��ṹ��
    * @return VOID
    */
    VOID  SDFileUnMapping(SFileMapping& stFileMapping);

    /**
    * @brief
    * ���ڴ��е�����д���ڴ�ӳ����ļ���
    * @param pMem : ָ��д��ӳ���ļ����ڴ���ʼ��ַ
    * @param len : ��Ҫд��Ĵ�С����λbyte
    * @return VOID
    */
    VOID  SDFileFlushMapping(VOID* pMem, UINT32 len);

    /** @} */
}//

#endif

