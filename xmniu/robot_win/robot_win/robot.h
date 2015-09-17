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
    void start(svr_t *svr);

    void end();

    int robot_connect(svr_t *svr);

    bool robot_send(const char buf[], int n);

    bool robot_recv(char buf[], int buf_len, ssize_t &n_recv);

    // ��������ʧ��ԭ��
    void err_cache();

public:
    pthread_t t_id; // �����߳�id
    int idx;

    int sockfd;

    bool closed; // �Ƿ��ѹر�
    int error_no; // �����

    time_in_ms start_conn_time; // ��ʼconnect��ʱ��
    time_in_ms conn_succ_time; // connect�ɹ����¼����粻�ɹ���Ϊ0
    time_in_ms finish_time; // robotһ������ɹ�ִ�к���¼�

    time_in_ms error_occur_time; // ���������ʱ��
};

#endif // robot_h__
