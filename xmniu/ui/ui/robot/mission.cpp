#include "mission.h"

#include <stdio.h>
#include <process.h>
#include <memory.h>
#include <WinSock2.h>

#include "monitor.h"
#include "robot.h"
#include "util.h"

#include "thread_pool.h"

#include "RobotForm.h"

namespace inner_mission
{
    static mission_t *g_mission = NULL;
    static ThreadPool *m_pool = new ThreadPool(1000);

    long g_n_started = 0;
    long g_n_ended = 0;
    CRITICAL_SECTION crit_sec;
    CRITICAL_SECTION start_sec;

    void on_thread_end()
    {
        EnterCriticalSection(&crit_sec);

        g_n_ended++;
        if(g_n_ended == g_mission->m_n_robot)
        {
            g_mission->m_monitor->end();
            g_mission->sum_up();

            ListViewItem^ item = (*ui::RobotForm::g_robotForm)->listView1->Items[0];

            item->SubItems[0]->Text = "�ɹ�����������";
            item->SubItems[1]->Text = "" + g_mission->m_monitor->m_chart->n_succ;

            ListViewItem^ item2 = (*ui::RobotForm::g_robotForm)->listView1->Items[1];

            item2->SubItems[0]->Text = "ʧ�ܻ���������";
            item2->SubItems[1]->Text = "" + g_mission->m_monitor->m_chart->n_fail;

            (*ui::RobotForm::g_robotForm)->poweron->Enabled = true;
        }

        int progress = (int)((float)(g_n_ended) / g_mission->m_n_robot * 100);
        progressbar::delegate_set_progress(progress);

        LeaveCriticalSection(&crit_sec);
    }

    // �����������̵߳Ļص�����
    unsigned __stdcall robot_thread_cb(void *un_used)
    {
        robot_t *robot = (robot_t*)un_used;

        svr_t &svr = g_mission->m_svrs[robot->m_idx % g_mission->m_n_svr];
        robot->go(&svr);

        on_thread_end();

        return 0;
    }

    void new_thread_robot(robot_t *robot)
    {
        m_pool->Call(robot_thread_cb, robot);

        /*
        unsigned  uiThread1ID = 0;

        pthread_t tid = 0;
        pthread_t handle = (pthread_t)_beginthreadex(NULL, 0, robot_thread_cb, robot, CREATE_SUSPENDED, &uiThread1ID);
        // pthread_create(&tid, NULL, robot_thread_cb, robot); 
        if(handle == NULL)
        {
            return;
        }

        robot->t_id = handle;
        */
    }
}

using namespace inner_mission;

mission_t::mission_t(int n_robot, bool log_all, svr_t *svrs, int n_svr) :
    m_n_robot(n_robot),
    m_log_all(log_all),
    m_svrs(svrs),
    m_n_svr(n_svr)
{
    g_mission = this;
}

mission_t::~mission_t()
{
    delete m_monitor;
    delete[] m_robots;
    delete m_pool;

    DeleteCriticalSection(&crit_sec);
    DeleteCriticalSection(&start_sec);
}

void mission_t::init()
{
    m_monitor = new monitor_t;

    // ���л�����ִ�������״������ʼʱ�䡢����ʱ�䡢ʧ��ԭ��ȣ���Ӧ���������������
    m_robots = new robot_t[m_n_robot];

    socket_startup();

    logutil::enable_log();

    // delete m_pool;
    // static ThreadPool *m_pool = new ThreadPool(m_n_robot);

    if(m_pool->Size() < m_n_robot)
    {
        m_pool->AdjustSize(m_n_robot - m_pool->Size());
    }

    g_n_started = 0;
    g_n_ended = 0;

    InitializeCriticalSection(&crit_sec);
    InitializeCriticalSection(&start_sec);
}

void mission_t::start()
{
    LOG_TRACE("start to launch <%d> robot\r\n", m_n_robot);

    if(false == m_log_all)
    {
        logutil::disable_log();
    }

    m_monitor->start();

    // pthread_t *t_ids = new pthread_t[m_n_robot];

    // ���ݻ�����������Ϊÿ�������˿���һ���߳�����ִ������    
    for(int i = 0; i < m_n_robot; i++)
    {
        robot_t *robot = &m_robots[i];
        memset(robot, 0, sizeof(robot_t));

        robot->m_idx = i;
        new_thread_robot(robot); 

        // t_ids[i] = robot->t_id;
    }

    // pool->EndAndWait();

    /*

    // ���̵߳ȴ����л������߳�ִ�����
    for(int i = 0; i < m_n_robot; i++)
    {
        robot_t *robot = &robots[i];
 
        WaitForSingleObject(robot->t_id, INFINITE);
        // pthread_join(robot->t_id, NULL);
    }
    */

    // WaitForMultipleObjects(m_n_robot, t_ids, true, INFINITE);

//    m_monitor->end();

  //  sum_up();
}

void mission_t::sum_up()
{
    m_monitor->print(m_robots, m_n_robot, m_svrs, m_n_svr);
}