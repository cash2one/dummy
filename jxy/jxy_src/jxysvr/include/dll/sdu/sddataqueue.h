


#ifndef SDDATAQUEUE_H
#define SDDATAQUEUE_H
/**
* @file sdthrdqueue.h

* @brief ѭ�����ݶ���
*
**/
#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup grouploopbuffer ������ѭ�����ݶ���
    * @ingroup  SGDP
    * @{
    */

    /**
    *@brief ѭ��ָ����У���ȡΪ������ָ�룬֧�ֵ��̶߳�д
    */
    class CSDDataQueue
    {
    public:
        CSDDataQueue();
        ~CSDDataQueue();

        /**
        * @brief
        * ��ʼ��ѭ��������
        * @param nSize ������ĳ��ȣ�ʵ�ʳ���Ϊ����ĳ��ȼ�1
        * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
        */
        BOOL  Init(INT32 nSize);

        /**
        * @brief
        * ��ʹ����ϵ�Buffer����ѭ���������Ľ�β
        * @param ptr : ָ��Buffer�ĵ�ַ
        * @return ���ѭ��������ӵ�еĴ�С����nLen������TRUE�����򷵻�FALSE
        * @remark �˺��������̰߳�ȫ��
        */
        BOOL  PushBack(VOID *ptr);

        /**
        * @brief
        * ��ȡ�µ�Buffer
        * @return ָ��Buffer�ĵ�ַ�����ʧ�ܣ�����NULL
        * @remark �˺��������̰߳�ȫ��
        */
        VOID*  PopFront();

    protected:
        VOID            **m_pArray;	/**<��ȡ��ַ������*/
        INT32			m_nHead;	/**<������ͷ��*/
        INT32			m_nTail;	/**<������β��*/
        INT32			m_nSize;	/**<��������С*/
    };

    /** @} */
}

#endif

