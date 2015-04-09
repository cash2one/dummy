/******************************************************************************


sdcondition.h - ��������,�����߳�ͬ��

******************************************************************************/


#ifndef SDCONDITION_H
#define SDCONDITION_H
/**
* @file sdcondition.h

* @brief ����������
*
**/
//#ifndef WIN32
#if !(defined(WIN32) || defined(WIN64))
#  include <pthread.h>
#  include <errno.h>
#  include <sys/time.h>
#endif
#include "sdtype.h"

namespace  SGDP
{
    /**
    * @defgroup groupsync �߳�ͬ��
    * @ingroup  SGDP
    * @{
    */

// Attempt to resolve POSIX behaviour conformance for win32 build.
#define CONDITION_WIN32_CONFORMANCE_TO_POSIX

    class CSDMutex;

    /**
    *@brief ���������������߳�ͬ��
    */
    class CSDCondition
    {
    public:

	/**
	* @brief ���캯������ʼ������
	*/
        CSDCondition();

	/**
	* @brief �����������ر��������
	*/
        ~CSDCondition();


        /**
        * @brief
        * �ȴ����������������������������һΪ�����ı䣬��Ϊ���жϣ���Ϊ��ʱ��
        * ��������������ԭ�ӵĽ��뻥�����Ļ��ⷶΧ�ڡ�
        * @param mutex : ������������صĻ�����������
        * @param dwMs : �ȴ���ʱʱ�䣬��λΪ����
        * @return TRUE ����������; FALSE ��ʱ���߱��ж�
        **/
        BOOL  Wait (CSDMutex &mutex, UINT32 dwMs = SDINFINITE);



        /**
        * @brief
        * �ȴ����������������������������һΪ�����ı䣬��Ϊ���жϣ���Ϊ��ʱ.
        * ��������������ԭ�ӵĽ��뻥�����Ļ��ⷶΧ�ڡ�
        * @param mutex : ������������صĻ�������ָ��
        * @param dwMs : �ȴ���ʱʱ�䣬��λΪ����
        * @return TRUE ����������; FALSE ��ʱ���߱��ж�
        **/
        BOOL  Wait (CSDMutex *mutex, UINT32 dwMs = SDINFINITE);

        /**
        * @brief
        * �������еȴ��е����һ���ȴ���Wait��
        * @return VOID
        **/
        VOID  Signal();

        /**
        * @brief
        * �������еĵȴ���Wait��
        * @return VOID
        **/
        VOID  Broadcast();

    private:

        //  no value sematics, therefore private and not implemented.
	/**
	* @brief �������캯��
	* @param CSDCondition���������
	*/
        CSDCondition (const CSDCondition&);

	/**
	* @brief ����=������,���ڶ���ĸ�ֵ
	* @param CSDCondition���������
	* @return CSDCondition���������
	*/
        CSDCondition& operator = (const CSDCondition&);

    private:
#if (defined(WIN32) || defined(WIN64))
#  ifdef CONDITION_WIN32_CONFORMANCE_TO_POSIX

        // boost clone with modification
        // licesnse text below

	/**
	* @brief �����¼����ź�״̬�ȴ���
	* @return VOID
	*/
        VOID EnterWait ();

        VOID* m_gate;
        VOID* m_queue;
        VOID* m_mutex;
        UINT32 m_gone;  // # threads that timed out and never made it to m_queue
        ULONG m_blocked; // # threads blocked on the condition
        UINT32 m_waiting; // # threads no longer waiting for the condition but
        // still waiting to be removed from m_queue
#  else
        HANDLE mId;
#  endif

#else
        mutable  pthread_cond_t mId;
#endif
    };

    /** @} */
}

#endif


