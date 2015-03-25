#include "util.h"

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <time.h>
#include <stdio.h>
#include <atlconv.h>

#include "RobotForm.h"

namespace logutil
{
    extern gcroot<System::Windows::Forms::TextBox^>* g_textBox = new gcroot<System::Windows::Forms::TextBox^>;
    // extern gcroot<RobotForm^>* g_robotForm = NULL;
    // RobotForm *g_robotForm = NULL;
    bool log_or_not = true; // �Ƿ��ӡ

    void enable_log()
    {
        log_or_not = true;
    }

    void disable_log()
    {
        log_or_not = false;
    }

    using namespace System;

    void log_info(String^ str)
    {
        // String ^str = gcnew String(buf);
        (*g_textBox)->AppendText(str);
        // (*g_textBox)->AppendText(Environment::NewLine);
        
        // (*g_textBox)->EnsureVisible((*g_textBox)->Items->Count - 1);
        // delete str;
    }

    void delegate_log(char buf[])
    {
        if ((*g_textBox)->InvokeRequired)
        {
            log_delegate^ l = gcnew log_delegate(log_info);
            (*g_textBox)->BeginInvoke(l, gcnew String(buf));
        }
        else
        {
            log_info(gcnew String(buf));
        }
    }
}

namespace progressbar
{
    void delegate_set_progress(int progress)
    {
        gcroot<ProgressBar^>* progressBar = new gcroot<ProgressBar^>;
        *progressBar =(*ui::RobotForm::g_robotForm)->progressBar1;

        if ((*progressBar)->InvokeRequired)
        {
            progress_delegate^ p = gcnew progress_delegate(set_progress);
            (*progressBar)->BeginInvoke(p, progress);
        }
        else
        {
            set_progress(progress);
        }
    }

    void set_progress(int progress)
    {
        gcroot<ProgressBar^>* progressBar = new gcroot<ProgressBar^>;
        *progressBar =(*ui::RobotForm::g_robotForm)->progressBar1;

        (*progressBar)->Value = progress;
        (*progressBar)->Refresh();
    }
}

void setnonblocking(int sock)
{
    unsigned long ul = 1;
    int n = ioctlsocket(sock, FIONBIO, (unsigned long*)&ul);                 //�����׽��ַ�����ģʽ
    if (n == SOCKET_ERROR)
    {
        //�����׽��ַ�����ģʽ��ʧ�ܴ���
        perror("fcntl(sock,GETFL)");
        return;
    }
}

int gettimeofday(struct timeval *tp, void *tzp)
{
    time_t clock;
    struct tm tm;
    SYSTEMTIME wtm;
    GetLocalTime(&wtm);
    tm.tm_year     = wtm.wYear - 1900;
    tm.tm_mon     = wtm.wMonth - 1;
    tm.tm_mday     = wtm.wDay;
    tm.tm_hour     = wtm.wHour;
    tm.tm_min     = wtm.wMinute;
    tm.tm_sec     = wtm.wSecond;
    tm. tm_isdst    = -1;
    clock = mktime(&tm);
    tp->tv_sec = (long)clock;
    tp->tv_usec = wtm.wMilliseconds * 1000;
    return (0);
}

// ��ȡʱ�䣨���¼�Ԫʱ�䡹Epoch��1970��1��1���賿������������ĺ�������
time_in_ms now()
{
    struct timeval time;
    gettimeofday(&time, NULL);

    time_in_ms present = time.tv_sec;
    present *= 1000;
    present += time.tv_usec / 1000;;

    return present;
}


// ���÷��ͳ�ʱʱ�䣬ʹ��sendʱ���ڳ���һ��ʱ��ò������������
void set_socket_send_timeout(int sockfd, long tv_sec, long tv_usec)
{
    struct timeval timeout;             //��ʱʱ��
    timeout.tv_sec = tv_sec;
    timeout.tv_usec = tv_usec;

    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,sizeof(struct timeval)); 
}

// ���ý��ճ�ʱʱ��
void set_socket_recv_timeout(int sockfd, long tv_sec, long tv_usec)
{
    struct timeval timeout;             //��ʱʱ��
    timeout.tv_sec = tv_sec;
    timeout.tv_usec = tv_usec;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,sizeof(struct timeval)); 
}


void print_host_ent(hostent *host_ent, const char *host_name)
{
    char **pptr;

    char str[32];

    /* �������Ĺ淶������� */  
    LOG_TRACE("resolve url<%s> success, the official hostname = <%s>, ", host_name, host_ent->h_name);

    /* ���������ж�������������б����ֱ����� */
    for (pptr = host_ent->h_aliases; *pptr != NULL; pptr++)   
    {
        LOG_TRACE("alias:%s\r\n", *pptr);
    }

    /* ���ݵ�ַ���ͣ�����ַ����� */ 
    switch(host_ent->h_addrtype)   
    {   
    case AF_INET:   
    case AF_INET6:   
        pptr = host_ent->h_addr_list;   

        /* ���õ������е�ַ������� */  
        for(;*pptr!=NULL;pptr++) 
        {
            printf("ip = <%s>\r\n", inet_ntop(host_ent->h_addrtype, *pptr, str, sizeof(str)));   
        }

        break;   

    default:   
        printf("unknown address type\r\n");   
        break;   
    }
}

// ������������ַ��֧��127.0.0.1��ip��ʽ��www.xxxxxx.com��url��ʽ
// ʧ�ܷ���unsigned long(-1)
unsigned long name_resolve(const char *host_name)  
{  
    struct in_addr addr;  

    if((addr.s_addr=inet_addr(host_name)) == INADDR_NONE ) 
    {  
        struct hostent *host_ent = gethostbyname(host_name);  
        if(host_ent==NULL)
        {
            LOG_ERR("resolve svr addr<%s> fail at gethostbyname!\r\n", host_name);
            return INADDR_NONE ;
        }

        memcpy((char *)&addr.s_addr, host_ent->h_addr, host_ent->h_length);  
        print_host_ent(host_ent, host_name);
    }

    return addr.s_addr;
}

void filter(char buf[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(buf[i] == '\n')
        {
            buf[i] = '\0';
            break;
        }
    }
}

void str_err(int err, char buf[], int size)
{
    USES_CONVERSION;
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM,(void*)FORMAT_MESSAGE_FROM_STRING, err,0,(buf),size,0);

    filter(buf, size);
}

double ms_to_s(double ms)
{
#define  MS_PER_SECOND 1000
    double s = ms / MS_PER_SECOND;
    return s;
}

void socket_startup()
{
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2,2), &wsaData)) 
    { 
        printf("WSA failed/n"); 
        return; 
    } 
}