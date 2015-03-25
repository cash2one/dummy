/******************************************************************************
		

sdobjectpool.h - ������࣬����͹�����󣬿���֧�ֶ��߳�ģʽ

******************************************************************************/


#ifndef SDOBJECTPOOL_H
#define SDOBJECTPOOL_H
/**
* @file sdobjectpool.h

* @brief �������
*
**/
#include "sdobject_allocator.h"

#define SDNew               new

namespace SGDP
{
    /**
    * @defgroup groupmemorypool �ڴ��(���������)
    * @ingroup  SGDP
    * @{
    */

    /**
    *@brief �������
    */
    template <typename _Tp, typename _Alloc=ObjectAllocator<_Tp> >
    class CSDObjectPool
    {
    public:

		/**
		* @brief ���캯�������������С���ڴ�
		* @param dwInitCount : �ڴ�ĳ�ʼ��С
		* @param dwGrouCount : �ڴ��ĸ���
		*/
        CSDObjectPool(UINT32 dwInitCount = 0, UINT32 dwGrouCount = 1)
            :m_allocator(dwInitCount,dwGrouCount)
        {
        }

        /**
        * @brief
        * ����һ������, ��������캯��û�в�����ʹ�ô˽ӿ�
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
        inline _Tp*   Alloc()
        {
            return SDNew (m_allocator.allocate())_Tp;
        }

        /**
        * @brief
        * ����һ������, ����Ĺ��캯������һ���������
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
        template<typename P1>
        _Tp *  Alloc(P1 p1)
        {
            return SDNew (m_allocator.allocate())_Tp(p1);
        }

		 /**
        * @brief
        * ����һ������, ����Ĺ��캯������2���������
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
        template<typename P1,typename P2>
        _Tp*  Alloc(P1 p1,P2 p2)
        {
            return SDNew (m_allocator.allocate())_Tp(p1,p2);
        }

		 /**
        * @brief
        * ����һ������, ����Ĺ��캯������3���������
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
        template<typename P1,typename P2,typename P3>
        _Tp*  Alloc(P1 p1,P2 p2,P3 p3)
        {
            return SDNew (m_allocator.allocate())_Tp(p1,p2,p3);
        }

		 /**
        * @brief
        * ����һ������, ����Ĺ��캯������4���������
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
        template<typename P1,typename P2,typename P3,typename P4>
        _Tp*  Alloc(P1 p1,P2 p2,P3 p3,P4 p4)
        {
            return SDNew (m_allocator.allocate())_Tp(p1,p2,p3,p4);
        }

		 /**
        * @brief
        * ����һ������, ����Ĺ��캯������5���������
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
        template<typename P1,typename P2,typename P3,typename P4,typename P5>
        _Tp*  Alloc(P1 p1,P2 p2,P3 p3,P4 p4,P5 p5)
        {
            return SDNew (m_allocator.allocate())_Tp(p1,p2,p3,p4,p5);
        }

        /**
        * @brief
        * �黹һ������
        * @param pObj : ����ָ��
        * @return void
        */
        void  Free(_Tp * p)
        {
            p->~_Tp();
            m_allocator.deallocate(p);
        }

        /**
        * @brief ��ȡ�����
        * @return �����
        */
        _Alloc &  GetAllocator()
        {
            return m_allocator;
        }

    private:
        _Alloc m_allocator;

    };

}

using namespace SGDP;

#endif //

