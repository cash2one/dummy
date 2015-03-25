#ifndef robot_h__
#define robot_h__

#include "types.h"

struct svr_t;



struct svr_t
{
    char *addr; // ������ip����url:192.168.0.1��www.xxx.com
    int port; // �������˿��б�

    unsigned long cast_addr;
};

class robot_t
{
public:
    void go(svr_t *svr);

    void end();

    int robot_connect(svr_t *svr);
    void on_connect_fail(svr_t *svr);

    bool robot_send(const char buf[], int n);
    void on_send_fail(const char buf[], int n);

    bool robot_recv(char buf[], int buf_len, ssize_t &n_recv);
    void on_recv_fail();

    // ��������ʧ��ԭ��
    void err_cache();

public:
    svr_t *m_svr;

    pthread_t m_t_id; // �����߳�id
    int m_idx;

    int m_sockfd;

    bool closed; // �Ƿ��ѹر�
    int m_error_no; // �����

    time_in_ms m_start_conn_time; // ��ʼconnect��ʱ��
    time_in_ms m_conn_succ_time; // connect�ɹ����¼����粻�ɹ���Ϊ0
    time_in_ms m_finish_time; // robotһ������ɹ�ִ�к���¼�

    time_in_ms m_error_occur_time; // ���������ʱ��
};

#endif // robot_h__
