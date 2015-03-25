#include "Logging.h"

#include <string.h>

__declspec(thread) char t_errnobuf[512];

const char* strerror_tl(int savedErrno)
{
    strerror_s(t_errnobuf, sizeof t_errnobuf, savedErrno);
    return t_errnobuf;
}

namespace logging
{
    void Init(const char* program_name, const char* log_path)
    {
        google::InitGoogleLogging(program_name); // ��ʼ��
        google::SetLogDestination(google::GLOG_INFO, log_path);//����INFO����ģ���¼�ڵ�ǰĿ¼���ļ���Ϊlog_ǰ׺
        google::SetStderrLogging(google::GLOG_INFO); //�����������׼�������������ռǼ���
    }
}