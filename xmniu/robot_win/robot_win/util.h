#ifndef util_h__
#define util_h__

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <time.h>

#include "types.h"

#define oops(msg) { perror("oops:" msg); }

#undef min
#undef max

/*
#define min(x,y) ({ \
    __typeof(x) _x = (x); \
    __typeof(y) _y = (y); \
    (void) (&_x == &_y); \
    _x < _y ? _x : _y; })

#define max(x,y) ({ \
    __typeof(x) _x = (x); \
    __typeof(y) _y = (y); \
    (void) (&_x == &_y); \
    _x > _y ? _x : _y; })
*/

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

namespace log
{
    extern bool log_or_not; // �Ƿ��ӡ

    void enable_log();

    void disable_log();

#define LOG_TRACE(xxx, ...) if(log_or_not){fprintf(stdout, xxx,  __VA_ARGS__);}
#define LOG_ERR(xxx, ...) if(log_or_not){fprintf(stderr, xxx,  __VA_ARGS__);}
}

using namespace log;

void setnonblocking(int sock);

int gettimeofday(struct timeval *tp, void *tzp);

// ��ȡʱ�䣨���¼�Ԫʱ�䡹Epoch��1970��1��1���賿������������ĺ�������
time_in_ms now();

// ���÷��ͳ�ʱʱ�䣬ʹ��sendʱ���ڳ���һ��ʱ��ò������������
void set_socket_send_timeout(int sockfd, long tv_sec, long tv_usec);

// ���ý��ճ�ʱʱ��
void set_socket_recv_timeout(int sockfd, long tv_sec, long tv_usec);

void print_host_ent(hostent *host_ent, const char *host_name);

// ������������ַ��֧��127.0.0.1��ip��ʽ��www.xxxxxx.com��url��ʽ
// ʧ�ܷ���unsigned long(-1)
unsigned long name_resolve(const char *host_name);

void str_err(int err, char buf[], int size);

#endif // util_h__
