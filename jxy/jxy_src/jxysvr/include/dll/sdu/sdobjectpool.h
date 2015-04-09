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
#include "detail/sdobject_allocator.h"
#include "detail/sdobject_allocator_ex.h"
#include "detail/sdobject_dqueue_allocator.h"
#include "config.h"
#include "sdtype.h"
#include "sddebug.h"

#if SDU_WITH_BOOST
#include <boost/preprocessor/repetition.hpp>
#endif

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
    template <typename _Tp,typename MT = CSDNonMutex,
             typename _Alloc=ObjectAllocator<_Tp,MT> >
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

#if SDU_WITH_BOOST

        /**
        * @brief
        * ����һ������, ʹ��boost�⣬���Խ�֧�ֵĹ��캯���Ĳ�����չΪ20��
        * @return ���ض����ָ�룬���ʧ�ܷ���NULL
        */
#define DECL(z,n,text) T##n t##n
#define MALLOC_DECL(z,n,text)  \
	BOOST_PP_IF(n,template < , ) BOOST_PP_ENUM_PARAMS(n,typename T) BOOST_PP_IF(n,>, ) \
	_Tp*  Alloc(BOOST_PP_ENUM(n,DECL,~))   \
		{ \
		return SDNew (m_allocator.allocate())_Tp(BOOST_PP_ENUM_PARAMS(n,t)); \
		}

        BOOST_PP_REPEAT (20,MALLOC_DECL,~)



#else
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
#endif // 
        /**
        * @brief
        * �黹һ������
        * @param pObj : ����ָ��
        * @return VOID
        */
        VOID  Free(_Tp * p)
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

#endif //

