/******************************************************************************



******************************************************************************/


#ifndef SD_THREAD_H
#define SD_THREAD_H

/**
* @file sdthread.h

* @brief �̹߳�����
**/

#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup groupthread ����̶��߳�(�����̳߳�)
    * @ingroup  SGDP
    * @{
    */

#if (defined(WIN32) || defined(WIN64))
    typedef UINT32 SDTHREADID;
#else
    typedef pthread_t  SDTHREADID;
#endif // WIN32 

    /**
    * @brief
    * �õ��߳�id��
    * @return �߳�id��
    */
    SDTHREADID  SDGetThreadId();

    typedef struct tagSThreadAttr
    {

    } SThreadAttr;

#if (defined(WIN32) || defined(WIN64))
    typedef unsigned int (WINAPI *PFThrdProc)(VOID *);
#define SDTHREAD_DECLARE(x)  unsigned int WINAPI  x
#define SDTHREAD_RETURN(x)   return x;
#define SDTHREAD_IMP		  unsigned int WINAPI
#else
    typedef VOID *  (*PFThrdProc)(VOID *);
#define SDTHREAD_DECLARE(x)  VOID *  x
#define SDTHREAD_RETURN(x)   return x;
#define SDTHREAD_IMP		  VOID *
#endif // 


    SDHANDLE  SDCreateThread(
        SThreadAttr * pAttr,
        PFThrdProc pThrdProc,
        VOID * pArg,
        SDTHREADID *pThreadId = NULL,
        BOOL bSuspend = FALSE,
		UINT32 dwStackSize = 0);

    INT32  SDThreadWait(SDHANDLE handle);

    VOID  SDThreadCloseHandle(SDHANDLE handle);

    VOID  SDThreadTerminate(SDHANDLE handle);

    VOID  SDThreadSuspend(SDHANDLE handle);

    VOID  SDThreadResume(SDHANDLE handle);

    VOID  SDSetThreadAttr(SDHANDLE,SThreadAttr * pAttr);

    SThreadAttr*  SDGetThreadAttr(SDHANDLE);

    /**
    * @brief �̲߳�����
    */
    class CSDThread
    {

    public:
        CSDThread();
        virtual ~CSDThread();

        /**
        * @brief
        * ����һ���߳�
        * @param pThredProc: �߳�ִ�д�������ע�⣺ʹ�ôνӿں󣬲��������ĳ�Ա����ThrdProc
        * @param pArg : �߳�ִ�в���
        * @param bSuspend : �����߳�״̬Ϊ����
        * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
        */
        BOOL  Start(PFThrdProc pfThrdProc, VOID *pArg, BOOL bSuspend = FALSE, UINT32 dwStackSize = 0);

        /**
        * @brief
        * ����һ���߳� ע�⣺ʹ�ô˽ӿ������̻߳Ὣ���Ա����ThrdProc��Ϊ�߳�ִ�к������û���̳д�
        * ����ִ���߳�
        * @param bSuspend : �����߳�״̬Ϊ����
        * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
        */
        BOOL  Start(BOOL bSuspend = FALSE, UINT32 dwStackSize = 0);


        /**
        * @brief
        * ���߳���ֹʱ�Ļص����������Լ̳д˺���ʵ���û��Լ��Ĺ���
        * @return VOID
        */
        virtual VOID  OnTerminated()
        {
        }

        /**
        * @brief
        * �ȴ��߳�ֹͣ
        * @return VOID
        */
        VOID  Wait();

        /**
        * @brief
        * ǿ���߳���ֹ
        * @return VOID
        */
        VOID  Terminate();

        /**
        * @brief
        * �����̣߳��˷���ֻ��Windows����ϵͳ�п���
        * @return VOID
        */
        VOID  Suspend();

        /**
        * @brief
        * �ظ��̣߳��˷���ֻ��Windows����ϵͳ�п���
        * @return VOID
        */
        VOID  Resume();

        /**
        * @brief
        * �����߳�����
        * @param pAttr : ���õ����Խṹ��
        * @return VOID
        */
        VOID  SetAttribute(SThreadAttr *pAttr);

        /**
        * @brief
        * ��ȡ�߳�����
        * @return ���ػ�ȡ���߳�����
        */
        SThreadAttr*  GetAttribute();

		inline BOOL IsStart() { return m_bstart; }
	protected:
        /**
        * @brief
        * �߳�����߳�ִ�к�����. �û���Ҫ���ش˺��������Լ����̺߳���
        * ����û�����Start(bSuspend)�������̣߳�CSDThread�ཫ�����ThrdProcִ���߳�
        * @return VOID
        */
        virtual VOID  ThrdProc()
        {
        }
    protected:

		static SDTHREAD_DECLARE(SDThreadFunc) (VOID * arg); 
        CSDThread (const CSDThread&);
        CSDThread& operator = (const CSDThread&);

        BOOL m_bstart;
        SDTHREADID m_tid;
        SDHANDLE m_handle;
        VOID* m_arg;			/**<�̺߳�������*/
    };


    /** @} */
}//

#endif



