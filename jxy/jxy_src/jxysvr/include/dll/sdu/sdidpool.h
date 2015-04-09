#ifndef SD_IDPOOL_H
#define SD_IDPOOL_H
#include <list>
#include "sdtype.h"
#include "sdstring.h"
#include "sddebug.h"
#include "sddebug.h"
using namespace std;
namespace SGDP
{
    /**
    * @brief IDPool
    */
    template <typename T>
	class CSDIDPool
	{
        /*���ṹ*/
		typedef struct Node
		{
			T obj;           //����д洢��ģ�����Ͷ��� 
			UINT32 next;     //��ǰ������һ���ڵ�λ��
		}Ele;
	public:
        /**
        * @brief ��ʼ��IDPool
        * @param dwSize : ID�صĴ�С
        * @return TRUE:�ɹ���ʼ��
        */
		BOOL Init(UINT32 dwSize)
		{			
			m_aObject = SDNew Ele[dwSize];
			memset(m_aObject,0,dwSize*sizeof(Ele));
			for ( UINT32 i = 0; i < dwSize; i++ )
				m_aObject[i].next = i+1;
			m_dwSize = m_freeSize = dwSize;
			m_dwFreeHead = 0;
			m_dwFreeTail = dwSize-1;
			return TRUE;
		}

		/**
		* @brief ���캯������ʼ��ID����غʹ�С
		*/
		CSDIDPool(): m_aObject(NULL), m_dwSize(0) {}

		/**
		* @brief �����������ͷ�ID�����
		*/
		~CSDIDPool()
		{
			SDDelete [] m_aObject;
		}

        /**
        * @brief ��IDPool�����һ������
        * @param object : Ҫ��ӵĶ���
        * @return dwID ����������ڵ�λ��
        */
		UINT32 Add(T object)
		{
			if ( 0 == m_freeSize) return (UINT32)(-1);
			UINT32 dwID = m_dwFreeHead;
			m_aObject[m_dwFreeHead].obj = object;   //��ͷ��һ��
			m_dwFreeHead = m_aObject[m_dwFreeHead].next; // ���¶�ͷ
			m_aObject[dwID].next = (UINT32)-1;//next�ǣ�1��ʾ��ʹ����
			--m_freeSize;		
			return dwID;
		}

        /**
        * @brief ��������ID�Ͷ�����IDPool�в����Ƿ�ƥ��
        * @param dwID   : Ҫ���ҵ�λ��
        * @param object : Ҫ���ҵĶ���
        * @return TRUE:���ҳɹ� FALSE:����ʧ��
        */
		BOOL Find(UINT32 dwID, T& pObject)
		{
			if ((dwID >= m_dwSize) )
			{
				return FALSE;
			}

			if (m_aObject[dwID].next != (UINT32)(-1)) //������ʹ����
				 return FALSE;

			pObject = m_aObject[dwID].obj;
			return TRUE;
		}

        /**
        * @brief ɾ��ָ��λ�õĽڵ�
        * @param dwID : ָ����λ��
        * @return VOID
        */
		VOID Del(UINT32 dwID)
		{
			if ((dwID >= m_dwSize) )
			{
				return;
			}

			if (m_aObject[dwID].next != (UINT32)(-1))  //������ʹ����
				return;
			++m_freeSize;
			if ( m_freeSize == 1) //�������ĵ�һ���ڵ㣬��ͷ����β
			{
				m_dwFreeHead = m_dwFreeTail = dwID;
				m_aObject[m_dwFreeHead].next = m_dwSize;
				return;
			}
			m_aObject[dwID].next = m_dwSize;  //�����ʾ�޺����
			m_aObject[m_dwFreeTail].next = dwID; //�ŵ���β
			m_dwFreeTail = dwID;  //���¶�β		
		}

        /**
        * @brief ��ȡIDPool�����һ��ʵ�ʴ洢�Ķ���
        * @param oFunc : ����ȡ���Ķ���
        * @return TRUE:��ȡ�ɹ�
        */
        template<class CFunc>
        BOOL For_Each(CFunc oFunc)
        {
            if(IsEmpty())
                return TRUE;

            UINT32 dwSize = 0;
            UINT32 dwCurrentSize = Capacity() - GetFreeCount();
            for(UINT32 i = 0; i < m_dwSize; ++i)
            {
                if(m_aObject[i].next == (UINT32)(-1))
                {
                    oFunc(m_aObject[i].obj);
                    dwSize++;

                    if(dwSize == dwCurrentSize)
                        break;
                }
            }
            return TRUE;
        }

        /**
        * @brief ��ȡIDPool�п��еĸ���
        * @return ���и���
        */
		std::list<UINT32>::size_type GetFreeCount() const
		{
			return m_freeSize;
		}

        /**
        * @brief �ж�IDPool��ʵ�ʴ洢�����Ƿ�Ϊ��
        * @return TRUE:�� FALSE:�ǿ�
        */
		BOOL IsEmpty() const
		{
			return ( m_freeSize == m_dwSize );
		}

        /**
        * @brief �ж�IDPool��ʵ�ʴ洢�����Ƿ���
        * @return TRUE:�� FALSE:�п���
        */
		BOOL IsFull() const
		{
			return ( m_freeSize == 0 );
		}

        /**
        * @brief ��ȡIDPool����
        * @return IDPool�洢��С
        */
		std::list<UINT32>::size_type Capacity() const
		{
			return m_dwSize;
		}

        /**
        * @brief ��ȡ��ǰʹ����
        * @return ��ǰʹ����
        */
		UINT32 GetUSG()
		{
			return 100 - m_freeSize*100/m_dwSize;
		}
		
	private:
		UINT32			m_dwSize;
		UINT32			m_freeSize;
		Ele *			m_aObject;
		UINT32			m_dwFreeHead;
		UINT32			m_dwFreeTail;	
	};
}
#endif

