#ifndef util_h__
#define util_h__

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <time.h>

#include "types.h"
#include<vcclr.h>

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

using namespace System;
using namespace System::Windows::Forms;


namespace logutil
{
    extern gcroot<System::Windows::Forms::TextBox^>* g_textBox;

    void log_info(String^ str);

    void delegate_log(char buf[]);

    extern bool log_or_not; // �Ƿ��ӡ

    void enable_log();

    void disable_log();
}

namespace progressbar
{
    void delegate_set_progress(int progress);

    void set_progress(int progress);
}

using namespace logutil;

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

double ms_to_s(double ms);

void socket_startup();

#endif // util_h__
