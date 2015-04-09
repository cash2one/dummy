
#ifndef SDCRC_H
#define SDCRC_H
/**
* @file sdcrc.h

* @brief crc check
*
**/
#include "sdtype.h"
#include <string>

namespace SGDP
{
    /**
    * @defgroup groupsrc CrcУ��
    * @ingroup  SGDP
    * @{
    */

    /**
    * @brief
    * �õ�һ�黺������Ӧ��crcУ����
    * @param pBuf : ����Ļ�����
    * @param dwLen : ����������
    * @param dwCrcVal : ������ڵ���0��С��256������λ
    * @return crcУ����
    */
    UINT32  SDCRC(const VOID* pBuf, UINT32 dwLen, UINT32 dwCrcVal = 0);

    /**
    * @brief
    * �����ļ����ݵ�crcУ����,ע�����CRCʱʹ���˶����Ʒ�ʽ��ȡ,
    * �����ͬһ���ļ���crcֵ��һ��,��ȷ���ļ��Ķ�ȡ��ʽ.
    * @param pszFileName : �ļ���
    * @param bFileMapping : �Ƿ��ļ�ӳ�䵽һ���ڴ���
    * @return �ļ����ݵ�crcУ���룬ʧ�ܷ���0
    */
    UINT32  SDFileCRC(const TCHAR* pszFileName, BOOL bFileMapping = TRUE);

    /** @} */
}

#endif

