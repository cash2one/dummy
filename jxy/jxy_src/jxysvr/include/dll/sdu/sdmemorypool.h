/******************************************************************************
					


******************************************************************************/
#ifndef SDMEMORYPOOL_H
#define SDMEMORYPOOL_H

/**
* @file sdmemorypool.h

* @brief �ɱ�ͷǿɱ��ڴ��
*
**/
#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup groupmemorypool �ڴ��(���������)
    * @ingroup  SGDP
    * @{
    */

    /**
    * @brief �ɱ��ڴ���С�ڴ�أ�
    * �ڴ��������ڴ治���Զ��ͷţ�ֻ���ڴ������ʱ�ͷš�
    * ע�⣺���ࡰ�ǡ��̰߳�ȫ
    * ʹ��ʾ����
    * CSDVarMemoryPool pool;
    * pool.Create();
    * ĳһ�̣߳�
    * char * p1 = pool.Malloc(512);//�ǵü���
    * char * p2 = pool.Malloc(31);//�ǵü���
    * char * p3 = pool.Malloc(128);//�ǵü���
    *
    * ����һ���̣߳�
    * pool.Free(p3);//�ǵü���
    * pool.Free(p2);//�ǵü���
    * pool.Free(p1);//�ǵü���
    */
    class CSDVarMemoryPool
    {
        struct MemoryPage
        {
            MemoryPage* Next;	// next memory page
        };

    public:

		/**
		* @brief ���캯������ʼ���ڴ�ҳ�ͻ�����
		*/
        CSDVarMemoryPool();

		/**
		* @brief �����������ͷ��ڴ�
		*/
        ~CSDVarMemoryPool();

        /**
        * @brief
        * �����ɱ��ڴ��
        * @param dwPageSize : �ڲ�������ڴ�ҳ��С���ڴ治��ʱ���ڴ�ػ�����һ���µ��ڴ�ҳ
        * @return �����ɹ�����TRUE�����򷵻�FALSE
        **/
        BOOL  Create(UINT32 dwPageSize = 0x80000);

        /**
        * @brief
        * ����Len���ȵ�Buffer
        * @param dwLen : ��õ��ڴ���С����
        * @return  ���ص��ڴ棬�������ΪNULL����������ʧ��
        **/
        VOID*  Malloc(UINT32 dwLen);

        /**
        * @brief
        * �����ڴ�
        * @param p : ָ����Ҫ���յ��ڴ�
        * @return VOID
        **/
        VOID  Free(VOID* p);

        /**
        * @brief
        * ����ڴ�أ�ʹ���е��ڴ涼����ʹ�ã��˷������Ὣ�ڴ淵�ظ�����ϵͳ
        * @return VOID
        **/
        VOID  Clear();

        /**
        * @brief
        * ��ȡ��ǰ�ڴ�ʹ����
        * @return ��ǰ�ڴ�ʹ����
        **/
        INT32  GetMemUsed();

    private:
        
        /**
        * @brief ��ȡ������С���ڴ�
        * @param dwLen : �ڴ���С
        * @return ָ����С��buffer
        */
        VOID* GetPoolMemory(UINT32 dwLen);

        /**
        * @brief �ͷ�ָ���������ڴ��
        * @param pMemBlock : Ҫ�ͷŵ��ڴ��
        * @param dwType    : �ڴ�ҳ������
        * @return VOID
        */
        VOID FreePoolMemory(VOID* pMemBlock, UCHAR dwType);

        /**
        * @brief ����ָ�������������һ�ο����ڴ�
        * @param dwIndex : ָ������
        * @return TRUE:����ɹ� FALSE:����ʧ��
        */
        BOOL AddFreeMemory(INT32 dwIndex);

        /**
        * @brief �����ڴ�ҳ��
        * @return TRUE:���óɹ� FALSE:����ʧ��
        */
        BOOL SetMemoryPage();

        /**
        * @brief ��ȡ��ҳ�ڴ�
        * @param pPage : �ڴ��
        * @return TRUE:����ɹ� FALSE:����ʧ��
        */
        inline BYTE* GetPageBufGegin(MemoryPage *pPage)
        {
            return (BYTE*)(pPage + 1);
        }

        /**
        * @brief ��ȡĩҳ�ڴ�
        * @param pPage : �ڴ��
        * @return TRUE:����ɹ� FALSE:����ʧ��
        */
        inline BYTE* GetPageBufEnd(MemoryPage *pPage)
        {
            return (BYTE*)(pPage + 1) + m_nPageSize;
        }

    private:
        static const UINT32 ALIGNMENT = 8;
        static const UINT32 ALLOC_COUNT = 16;
        static const UINT32 MIN_PAGESIZE = 0x40000;	// min pPage size
        static const UINT32 MAX_UNIT_SIZE = 128;
        static const UINT32 UNIT_TYPE_COUNT = 16;

        BYTE* m_pFreeHead[UNIT_TYPE_COUNT];
        INT32 m_nFreeCount[UNIT_TYPE_COUNT];

        MemoryPage* m_pHeadPage;
        MemoryPage* m_pWorkPage;
        BYTE* m_pPageBuf;
        UINT32 m_nPageSize;
    };




    /**
    *@brief �̶��ڴ���С�ڴ�أ����ڷ���̶���С���ڴ��
    * �ڴ��������ڴ治���Զ��ͷţ�ֻ���ڴ������ʱ�ͷ�
    * ע�⣺���ࡰ�ǡ��̰߳�ȫ
    * ʹ��ʾ����
    * CSDFixMemoryPool pool;
    * pool.Create(128);
    * ĳһ�̣߳�
    * char * p1 = pool.Malloc();//�ǵü���
    * char * p2 = pool.Malloc();//�ǵü���
    * char * p3 = pool.Malloc();//�ǵü���
    *
    * ����һ���̣߳�
    * pool.Free(p3);//�ǵü���
    * pool.Free(p2);//�ǵü���
    * pool.Free(p1);//�ǵü���
    */
    class CSDFixMemoryPool
    {
        struct MemoryPage
        {
            MemoryPage* Next;	// next memory page
            INT32 nFreeHead;		// the first free unit in page
            INT32 nFreecount;		// free unit in page
        };

    public:

		/**
		* @brief ���캯������ʼ��ҳ�����С��ҳ���С
		*/
        CSDFixMemoryPool();

		/**
		* @brief �����������ͷ������ڴ�ҳ
		*/
        ~CSDFixMemoryPool();

        /**
        * @brief
        * ��ʼ���ڴ��
        * @param dwUnitSize : ÿһ��������ڴ���С
        * @param dwPageSize : �ڲ�������ڴ�ҳ��С���ڴ治��ʱ���ڴ�ػ�����һ���µ��ڴ�ҳ
        * @return  �����ɹ�����true��ʧ�ܷ���false
        **/
        BOOL  Create(UINT32 dwUnitSize, UINT32 dwPageSize = 0x40000);

        /**
        * @brief
        * �õ�һ���µ��ڴ�
        * @return  VOID*
        **/
        VOID*  Malloc();

        /**
        * @brief
        * �黹һ�������ڴ�
        * @param p : �ڴ�ĵ�ַ
        * @return  VOID
        **/
        VOID  Free(VOID* p);

        /**
        * @brief
        * ����ڴ�أ�ʹ���е��ڴ涼����ʹ�ã��˷������Ὣ�ڴ淵�ظ�����ϵͳ
        * @return VOID
        **/
        VOID  Clear();

        /**
        * @brief
        * ��ȡ��ǰ�ڴ�ʹ����
        * @return ��ǰ�ڴ�ʹ����
        **/
        INT32  GetMemUsed();

    private:
        /**
        * @brief �����ڴ�ҳ
        * @return TRUE:����ɹ� FALSE:����ʧ��
        */
        BOOL AddMemoryPage();

        /**
        * @brief ��ʼ���ڴ��
        * @return VOID
        */
        VOID InitPage(MemoryPage *pPage);

        /**
        * @brief ��ȡ�ڴ��buffer
        * @param pPage : �ڴ��
        * @return �ڴ��buffer
        */
        inline char* GetPageBuf(MemoryPage *pPage)
        {
            return (char*)(pPage + 1);
        }

    private:
        static const INT32 ALIGNMENT = 4;
        static const UINT32 MIN_PAGESIZE = 0x40000;	// min page size

        MemoryPage* m_pHeadPage;					// first page
        UINT32 m_nUnitSize;					// unit memory size
        UINT32 m_nPageSize;					// total memory in page
    };


}//namespace SGDP

#endif

