#ifndef SDRANDOM_H
#define SDRANDOM_H
/**
* @file sdrandom.h
* @brief �����ϵ��
*
**/
#include "sdtype.h"
#include <stdlib.h>

namespace SGDP
{
    /**
    * @defgroup grouprandom ���������
    * @ingroup  SGDP
    * @{
    */

    /**
    * @brief
    * C-API��ʽ���������������
    * @param dwSeed �����������
    * @return VOID
    */
    VOID SDSetSeed(UINT32 dwSeed);

    /**
    * @brief
    * C-API��ʽ����ȡ�����
    * @return ���������
    */
    INT32 SDRandom();

    /**
    * @brief
    * C-API��ʽ����ȡ�����
    * @param dwRange : ָ���ķ�Χ
    * @return ����ָ����Χ�ڵ������
    */
    UINT32 SDRandom(UINT32 dwRange);

    /**
    *@brief ����������ӿ�
    */
    class CSDRandom
    {
    public:

		/**
		* @brief ���캯������ʼ���������
		*/
        CSDRandom();

        /**
        * @brief
        * �������������
        * @param dwSeed �����������
        * @return VOID
        */
        inline VOID SetSeed(UINT32 dwSeed)
        {
            m_seed = dwSeed;
        }

        /**
        * @brief
        * ��ȡ�����
        * @return ���������
        */
        UINT32 Random();


        /**
        * @brief
        * ��ȡ���������Χ��[0, unRange - 1]
        * @param unRange �����ֵ
        * @return ���������
        */
        UINT32 Random(UINT32 dwRange);


        /**
        * @brief
        * ��ȡ���������Χ��[unMinRange, unMaxRange - 1]
        * @param dwMin ����Сֵ
        * @param dwMax �����ֵ
        * @return ���������
        */
        UINT32 Random(UINT32 dwMin, UINT32 dwMax);


    private:
        UINT32 m_seed;
    };

    /** @} */
}

#endif

