#include "sdthreadpool.h"
#include "sdlock.h"
#include "sdtime.h"
#include "sddebug.h"

namespace SGDP
{

    CSDThreadPool::CSDThreadPool()
        : m_minThreads(0), m_maxThreads(0),
         m_maxPendingJobs(0), m_waitTerminate(false),
         m_quickTerminate(false)
    {

    }

    CSDThreadPool::~CSDThreadPool()
    {
        TerminateQuick();

        for (ThreadArgMap::iterator iter = m_threadArgMap.begin();
                iter != m_threadArgMap.end(); iter++)
        {
            if (iter->second->pThread != NULL)
            {
                delete iter->second->pThread;
            }
            delete iter->second;
        }

        for (ThreadArgContainer::iterator iter = m_threadArgContainer.begin();
                iter != m_threadArgContainer.end(); iter++)
        {
            if ((*iter)->pThread != NULL)
            {
                delete (*iter)->pThread;
            }
            delete *iter;
        }
    }

    BOOL CSDThreadPool::Init( UINT32 minThreads, UINT32 maxThreads, UINT32 maxPendingJobs )
    {
        m_minThreads = minThreads;
        m_maxThreads = maxThreads;
        m_maxPendingJobs = maxPendingJobs;

        m_quickTerminate = false;
        m_waitTerminate = false;
        for (UINT32 i = 0; i < m_minThreads; i++)
        {
            ThreadArg* pthreadArg = SDNew ThreadArg;
            if (pthreadArg == NULL)
            {
                TerminateQuick();
                return false;
            }
            m_threadArgMap.insert(ThreadArgPair(pthreadArg, pthreadArg));

            CSDThread* pthread = SDNew CSDThread;
            if (pthread == NULL)
            {
                pthreadArg->pThread = NULL;
                TerminateQuick();
                return false;
            }

            pthreadArg->pThreadPool = this;
            pthreadArg->keepWorking = true;
            pthreadArg->pThread = pthread;

            if (pthread->Start(WorkThreadFunc, pthreadArg) == FALSE)
            {
                TerminateQuick();
                return false;
            }
        }

        return true;
    }

    BOOL CSDThreadPool::ScheduleJob( ISDRunable* job )
    {
        //������ֹ�̳߳أ��������������
        if (m_quickTerminate || m_waitTerminate)
        {
            return false;
        }

        m_jobMutex.Lock();
        if (m_jobContainer.size() >= m_maxPendingJobs)
        {
            m_jobMutex.Unlock();
            return false;
        }
        m_jobContainer.push_back(job);
        m_jobCondition.Signal();
        m_jobMutex.Unlock();

        m_threadMutex.Lock();
        if (m_threadArgMap.size() < m_maxThreads )
        {
            ThreadArg* pthreadArg = NULL;
            if (!m_threadArgContainer.empty())
            {
                pthreadArg = m_threadArgContainer.back();
                if (pthreadArg->pThread == NULL)
                {
                    pthreadArg->pThread = SDNew CSDThread;
                    if (pthreadArg->pThread == NULL)
                    {
                        m_threadMutex.Unlock();
						assert(FALSE);
                        return true;
                    }
                }
                else
                {
                    pthreadArg->pThread->Wait();
                }

                pthreadArg->pThreadPool = this;
                pthreadArg->keepWorking = true;

                if (pthreadArg->pThread->Start(WorkThreadFunc, pthreadArg) == FALSE)
                {
                    m_threadMutex.Unlock();
                    return true;
                }

                m_threadArgContainer.pop_back();
                m_threadArgMap.insert(ThreadArgPair(pthreadArg, pthreadArg));
            }
            else
            {
                pthreadArg = SDNew ThreadArg;
                if (pthreadArg == NULL)
                {
                    m_threadMutex.Unlock();
                    return true;
                }

                CSDThread* pthread = SDNew CSDThread;
                if (pthread == NULL)
                {
                    pthreadArg->pThread = NULL;
                    m_threadArgContainer.push_back(pthreadArg);
                    m_threadMutex.Unlock();
					assert(FALSE);
                    return true;
                }

                pthreadArg->pThreadPool = this;
                pthreadArg->keepWorking = true;
                pthreadArg->pThread = pthread;
                if (pthread->Start(WorkThreadFunc, pthreadArg) == FALSE)
                {
                    return true;
                }
                m_threadArgMap.insert(ThreadArgPair(pthreadArg, pthreadArg));
            }
        }
        m_threadMutex.Unlock();

        return true;
    }

    void CSDThreadPool::TerminateQuick()
    {
        m_quickTerminate = true;
        for (ThreadArgMap::iterator iter = m_threadArgMap.begin();
                iter != m_threadArgMap.end(); iter++)
        {
            iter->second->keepWorking = false;
        }

        for (ThreadArgMap::iterator iter = m_threadArgMap.begin();
                iter != m_threadArgMap.end(); iter++)
        {
            iter->second->pThread->Wait();
        }

        return;
    }

    void CSDThreadPool::TerminateWaitJobs()
    {
        m_waitTerminate = true;
        while (!m_jobContainer.empty())
        {
            SDSleep(50);
        }

        for (ThreadArgMap::iterator iter = m_threadArgMap.begin();
                iter != m_threadArgMap.end(); iter++)
        {
            iter->second->keepWorking = false;
        }


        for (ThreadArgMap::iterator iter = m_threadArgMap.begin();
                iter != m_threadArgMap.end(); iter++)
        {
            iter->second->pThread->Wait();
        }

    }

    UINT32 CSDThreadPool::GetThreadNum()
    {
        CSDLock<CSDMutex> Lock(m_threadMutex);

        return m_threadArgMap.size();
    }

    UINT32 CSDThreadPool::GetJobPending()
    {
        CSDLock<CSDMutex> Lock(m_jobMutex);

        return m_jobContainer.size();
    }

    SDTHREAD_DECLARE(CSDThreadPool::WorkThreadFunc)( void* arg )
    {
        ThreadArg* pThreadArg = (ThreadArg*)arg;
        CSDThreadPool* pThreadPool = pThreadArg->pThreadPool;

        UINT32 count = 0;
        while(pThreadArg->keepWorking && !pThreadPool->m_quickTerminate)
        {
            ++ count;

            pThreadPool->m_jobMutex.Lock();
            if (pThreadPool->m_jobContainer.empty())
            {
                BOOL ret = pThreadPool->m_jobCondition.Wait(pThreadPool->m_jobMutex, WAITTIME);

                if (ret == FALSE && count > WAITCOUNT)
                {
                    pThreadPool->m_threadMutex.Lock();
                    if(pThreadPool->m_threadArgMap.size() > pThreadPool->m_minThreads)
                    {
                        pThreadPool->m_threadArgMap.erase(pThreadArg);
                        pThreadPool->m_threadArgContainer.push_back(pThreadArg);
                        pThreadPool->m_threadMutex.Unlock();
                        pThreadPool->m_jobMutex.Unlock();
                        return NULL;
                    }
                    else
                    {
                        pThreadPool->m_threadMutex.Unlock();
                    }
                }
                pThreadPool->m_jobMutex.Unlock();
                continue;
            }

            ISDRunable* job = pThreadPool->m_jobContainer.front();
            pThreadPool->m_jobContainer.pop_front();

            pThreadPool->m_jobMutex.Unlock();

            job->Run();

            count = 0;
        }

        SDTHREAD_RETURN(NULL);
    }

}


