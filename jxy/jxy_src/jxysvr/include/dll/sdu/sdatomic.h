/******************************************************************************
			

sdatomic.h - ����ԭ�Ӳ����ĺ���ϵ��

******************************************************************************/

#ifndef SDATOMIC_H
#define SDATOMIC_H

/**
* @file sdatomic.h

* @brief ����ԭ�Ӳ����ĺ���ϵ��
*
**/
#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup groupatomic ԭ�Ӳ���
    * @ingroup  SGDP
    * @{
    */

    /*
    * ԭ�Ӳ���32λ��ֵ,ע�ⲻҪ��Win32ģʽ��ʹ��64λ��ԭ�Ӳ����������ڲ�ʹ����64λ��API��
		��ҪWindows Vista���ϵİ汾
    * ��Ҫע����ǣ�ÿ���������ڲ�ʵ�ֶ����ɲ���ϵͳ�Լ�ȷ�ϵ�
    * �ڱ��麯���У�
    * Add����ӷ�
    * Sub�������
    * Inc�����1
    * Dec�����1
    */


    /**
    * @brief
    * ���ڴ���ԭ�Ӷ�ȡһ��32λֵ
    * @param pdwMem : ָ����Ҫ����ȡֵ��ָ��
    * @return mem��ֵ
    */
    INT32  SDAtomicRead32(volatile INT32 *pdwMem);

	/**
	* @brief
	* ���ڴ���ԭ�Ӷ�ȡһ��64λֵ, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pqwMem : ָ����Ҫ����ȡֵ��ָ��
	* @return mem��ֵ
	*/
    INT64  SDAtomicRead64(volatile INT64 *pdwMem);

    /**
    * @brief
    * ���ڴ���ԭ������һ��32λ��ֵ
    * @param pdwMem : ָ����Ҫ����ֵ��ָ��
    * @param dwValue : ��Ҫ���õ�ֵ
    * @return VOID
    */
    VOID  SDAtomicSet32(volatile INT32 *pdwMem, INT32 dwValue);

	/**
	* @brief
	* ���ڴ���ԭ������һ��64λ��ֵ, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pqwMem : ָ����Ҫ����ֵ��ָ��
	* @param dwValue : ��Ҫ���õ�ֵ
	* @return VOID
	*/
    VOID  SDAtomicSet64(volatile INT64 *pdwMem, INT64 dwValue);

    /**
    * @brief
    * 32λԭ�Ӽӷ�����ԭʼֵ���һ��valֵ
    * @param pdwMem : ָ�򱻼�����ָ��
    * @param dwValue : ����
    * @return mem�б���ǰ��ԭʼֵ
    */
    INT32  SDAtomicAdd32(volatile INT32 *pdwMem, INT32 dwValue);

	/**
	* @brief
	* 64λԭ�Ӽӷ�����ԭʼֵ���һ��valֵ, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pdwMem : ָ�򱻼�����ָ��
	* @param dwValue : ����
	* @return mem�б���ǰ��ԭʼֵ
	*/
    INT64  SDAtomicAdd64(volatile INT64 *pdwMem, INT64 dwValue);

    /**
    * @brief
    * 32λԭ�Ӽ�������ԭʼֵ��ȥһ��valֵ
    * @param pdwMem : ָ�򱻼�����ָ��
    * @param dwValue : ����
    * @return ����ǰ��ԭֵ
    */
    INT32  SDAtomicSub32(volatile INT32 *pdwMem, INT32 dwValue);

	/**
	* @brief
	* 64λԭ�Ӽ�������ԭʼֵ��ȥһ��valֵ, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pdwMem : ָ�򱻼�����ָ��
	* @param dwValue : ����
	* @return ����ǰ��ԭֵ
	*/
    INT64  SDAtomicSub64(volatile INT64 *pdwMem, INT64 dwValue);

    /**
    * @brief
    * 32λԭ�Ӽ�1�㷨����ԭʼֵ��1
    * @param pdwMem : ָ�򱻼�����ָ��
    * @return mem�б���ǰ��ԭʼֵ
    */
    INT32  SDAtomicInc32(volatile INT32 *pdwMem);
	
	/**
	* @brief
	* 64λԭ�Ӽ�1�㷨����ԭʼֵ��1, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pdwMem : ָ�򱻼�����ָ��
	* @return mem�б���ǰ��ԭʼֵ
	*/
    INT64  SDAtomicInc64(volatile INT64 *pdwMem);

    /**
    * @brief
    * 32λԭ�Ӽ�1�㷨����ԭʼֵ��1
    * @param pdwMem : ָ�򱻼�����ָ��
    * @return mem�б���ǰ��ԭʼֵ
    */
    INT32  SDAtomicDec32(volatile INT32 *pdwMem);

	/**
	* @brief
	* 64λԭ�Ӽ�1�㷨����ԭʼֵ��1, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pdwMem : ָ�򱻼�����ָ��
	* @return mem�б���ǰ��ԭʼֵ
	*/
    INT64  SDAtomicDec64(volatile INT64 *pdwMem);

    /**
    * @brief
    * 32λԭ�ӵ�CAS(Compare and Swap)�㷨����32λֵpdwMemָ���ֵ��dwCmp�Ƚϣ�
    * ���һ�£���dwValue��ֵ��ֵ��*pdwMem
    * @param pdwMem : ָ�򱻱Ƚϵ�ֵ��ָ��
    * @param dwValue : ��memָ���ֵ��cmpһ�£�����ֵ��ֵ
    * @param dwCmp : �Ƚϵ�ֵ
    * @return mem�б���ֵǰ��ԭʼֵ
    */
    INT32  SDAtomicCas32(volatile INT32 *pdwMem, INT32 dwValue, INT32 dwCmp);

	/**
	* @brief
	* 64λԭ�ӵ�CAS(Compare and Swap)�㷨����64λֵmemָ���ֵ��cmp�Ƚ�, ��ҪWindows Vista���ϲ���ϵͳ
	* ���һ�£���with��ֵ��ֵ��*pdwMem
	* @param pdwMem : ָ�򱻱Ƚϵ�ֵ��ָ��
	* @param dwValue : ��memָ���ֵ��cmpһ�£�����ֵ��ֵ
	* @param dwCmp : �Ƚϵ�ֵ
	* @return mem�б���ֵǰ��ԭʼֵ
	*/
    INT64  SDAtomicCas64(volatile INT64 *pdwMem, INT64 dwValue, INT64 dwCmp);

    /**
    * @brief
    * �����㷨������val��memָ���ֵ
    * @param pdwMem : ָ�򱻽�����ֵ��ָ��
    * @param dwValue : ������ֵ
    * @return mem�б�����ǰ��ԭʼֵ
    */
    INT32  SDAtomicXchg32(volatile INT32 *pdwMem, INT32 dwValue);

	/**
	* @brief
	* �����㷨������val��memָ���ֵ, ��ҪWindows Vista���ϲ���ϵͳ
	* @param pdwMem : ָ�򱻽�����ֵ��ָ��
	* @param dwValue : ������ֵ
	* @return mem�б�����ǰ��ԭʼֵ
	*/
    INT64  SDAtomicXchg64(volatile INT64 *pdwMem, INT64 dwValue);

    /**
    * @brief
    * ԭ�ӵ�ָ���CAS(Compare and Swap)�㷨����pPtrָ���ָ����pCmpָ��Ƚϣ�
    * ���һ�£���pWithָ����pPtrָ���ָ�뽻��
    * @param pPtr : ָ�򱻱Ƚϵ�ָ���ָ��
    * @param pWith : ��pPtrָ���ָ����pCmpһ�£�����ֵ��ָ��
    * @param pCmp : �Ƚϵ�ָ��
    * @return ԭʼ��ָ��
    */
    VOID*  SDAtomicCasptr(volatile VOID **pPtr, VOID *pWith, const VOID *pCmp);

    /**
    * @brief
    * ����ָ���㷨
    * @param pPtr : pointer to the pointerָ�򱻽�����ָ���ָ��
    * @param pWith : what to swap it with��������ָ��
    * @return ��������ԭʼָ��
    */
    VOID*  SDAtomicXchgptr(volatile VOID **pPtr, VOID *pWith);

    /** @} */
}

#endif


