#include "monitor.h"

#include <map>

#include "robot.h"
#include "util.h"

#include "RobotForm.h"

namespace chart
{
    void chart_init(robot_chart &chart)
    {
        chart.n_succ = 0;
        chart.n_fail = 0;

        chart.error_map.clear();
    }

    void chart_sum_up(robot_chart &chart, const robot_t *robot)
    {
        if(robot->m_error_no == 0)
        {
            chart.n_succ++;
        }
        else
        {
            chart.n_fail++;
            chart.error_map[robot->m_error_no]++;
        }
    }

    void print_robot_chart(robot_chart &chart)
    {
        typedef robot_chart::error_map_t error_map_t;

        LOG_TRACE("robot succ num = %d\r\n", chart.n_succ);
        LOG_TRACE("robot fail num = %d\r\n", chart.n_fail);

        char   buf[128];

        for(error_map_t::iterator itr = chart.error_map.begin(); itr != chart.error_map.end(); itr++)
        {
            int err_type = itr->first;
            int err_occur_num = itr->second;

            str_err(err_type, buf, sizeof(buf));
            

            LOG_TRACE("num of error<%d, %s> is %d\r\n", err_type, buf, err_occur_num);
        }
    }
};

using namespace chart;

monitor_t::monitor_t()
{
    m_chart = new robot_chart;
}

monitor_t::~monitor_t()
{
    delete m_chart;
}

void monitor_t::start()
{
    start_ms = now();
}

void monitor_t::end()
{
    end_ms = now();
}

void monitor_t::print(const robot_t robots[], int n_robot, svr_t *svrs, int n_svr)
{
    chart_init(*m_chart);

    int total_conn_time = 0;
    int total_send_recv_time = 0;
    int total_succ_robot_life = 0;

    int n_conn_succ = 0; // ���ӳɹ��Ļ���������
    int n_safebox_succ = 0; // ִ������ɹ��Ļ���������

#define MS_PER_MINUTE 60000

    int min_conn_time = 0; // �����ٶ����Ļ����˻��˶೤ʱ������
    int max_conn_time = 0;

    int min_send_recv_time = 0; // ���ͺͽ������ݵ����ʱ��
    int max_send_recv_time = 0;

    int min_robot_life = 0; // ����������Ļ����˻��˶���ʱ��
    int max_robot_life = 0;

    for(int i = 0; i < n_robot; i++)
    {
        // LOG_TRACE("<robot %d>", i);

        const robot_t *robot = &robots[i];
        if(NULL == robot)
        {
            LOG_TRACE("null");
            continue;
        }

        chart_sum_up(*m_chart, robot);

        // LOG_TRACE("robot fd = %d, ", conn->fd);
        if(robot->m_error_no)
        {
            int err_time_diff = (int)(robot->m_error_occur_time - robot->m_start_conn_time);

            static char buf[128];
            str_err(robot->m_error_no, buf, sizeof(buf));

            LOG_TRACE("robot[idx=%d,fd=%d] failed after launched <%f> s, errormsg: <%d>%s\r\n\r\n", 
                robot->m_idx, robot->m_sockfd, ms_to_s(err_time_diff), robot->m_error_no, buf);

            continue;
        }

        if(robot->m_conn_succ_time)
        {
            ++n_conn_succ;

            int conn_time = (int)(robot->m_conn_succ_time - robot->m_start_conn_time); // ���Ӻ�ʱ
            total_conn_time += conn_time;

            if(robot->m_finish_time)
            {
                ++n_safebox_succ;

                int robot_life = (int)(robot->m_finish_time - robot->m_start_conn_time); // ��������������
                int send_recv_time = robot_life - conn_time; // ���ͽ������ݵĺ�ʱ

                total_succ_robot_life += robot_life;
                total_send_recv_time += send_recv_time;

                min_send_recv_time = (min_send_recv_time > 0 ? min(send_recv_time, min_send_recv_time) : send_recv_time);
                max_send_recv_time = max(send_recv_time, max_send_recv_time);

                min_robot_life = (min_robot_life > 0 ? min(robot_life, min_robot_life) : robot_life);
                max_robot_life = max(robot_life, max_robot_life);
            }

            min_conn_time = (min_conn_time > 0 ? min(conn_time, min_conn_time) : conn_time);
            max_conn_time = max(conn_time, max_conn_time);
        }
    }

    int total_cost_time = (int)(end_ms - start_ms); // ���β��Ե��ܺ�ʱ

    double avg_conn_ms = (n_conn_succ == 0 ? 0 : (double)total_conn_time / n_conn_succ); // ƽ��ÿ�������˻��˶���ʱ���������
    double avg_send_recv_ms = ((n_safebox_succ == 0) ? 0 : (double)total_send_recv_time / n_safebox_succ); // ƽ�����ݴ���ʱ��
    double avg_robot_life = ((n_safebox_succ == 0) ? 0 : (double)total_succ_robot_life / n_safebox_succ); // �����˵�ƽ����������

    double conn_per_sec = ((n_conn_succ == 0) ? 0 : (double)n_conn_succ / ms_to_s(total_cost_time)); // ÿ���������
    double robots_per_sec = ((n_safebox_succ == 0) ? 0 :(double)n_safebox_succ / ms_to_s(total_cost_time)); // ÿ����ٻ�����

    logutil::enable_log();
    LOG_TRACE("/----------------------------------------\r\n");

    LOG_TRACE("total launched robot number = %d connect to %d svrs:\r\n", n_robot, n_svr);

    for(int i = 0; i < n_svr; i++)
    {
        svr_t *svr = &svrs[i];
        LOG_TRACE("    svrs[%d]:<%s:%d>\r\n", i + 1, svr->addr, svr->port);
    }

    LOG_TRACE("\r\n");

    print_robot_chart(*m_chart);

    // LOG_TRACE("conn succ num = %d\r\n", n_conn_succ);
    // LOG_TRACE("safebox succ num = %d\r\n", n_safebox_succ);

    LOG_TRACE("\r\n");

    LOG_TRACE("total cost = %f s\r\n", ms_to_s(total_cost_time));

    LOG_TRACE("\r\n");

    LOG_TRACE("min conn time = %f s\r\n", ms_to_s(min_conn_time));
    LOG_TRACE("max conn time = %f s\r\n", ms_to_s(max_conn_time));

    LOG_TRACE("min send recv time = %f s\r\n", ms_to_s(min_send_recv_time));
    LOG_TRACE("max send recv time = %f s\r\n", ms_to_s(max_send_recv_time));

    LOG_TRACE("min robot life = %f s\r\n", ms_to_s(min_robot_life));
    LOG_TRACE("max robot life = %f s\r\n", ms_to_s(max_robot_life));

    LOG_TRACE("\r\n");

    LOG_TRACE("avg conn time = %f s\r\n", ms_to_s(avg_conn_ms));
    LOG_TRACE("avg send_recv time = %f s\r\n", ms_to_s(avg_send_recv_ms));
    LOG_TRACE("avg robot life = %f s\r\n", ms_to_s(avg_robot_life));

    LOG_TRACE("\r\n");

    LOG_TRACE("conns per second = %f\r\n", conn_per_sec);
    LOG_TRACE("robots per second = %f\r\n", robots_per_sec);//(double)MS_PER_SECOND / avg_robot_life);

    LOG_TRACE("----------------------------------------/\r\n");
    LOG_TRACE("\r\n\r\n");
}
