#include "str_util.h"

#include <time.h>

#define IS_SPACE(c) (c == ' ' || c == '\t')

namespace strutil
{
    // �Ƴ����ַ�����ͷ��ĩβ���Ŀո��\t����
    // ����: trim("   start xxx end   ") = "start xxx end"
    string trim(char* str)
    {
        if(NULL == str)
        {
            return "";
        }
        
        while(IS_SPACE(*str)){str++;}
        char *start = str;

        while(*str){str++;}
        char *end   = str;

        while((end != start) && IS_SPACE(*end)){--end;}
        *(end) = '\0';

        return start;
    }

    // �滻�ַ���
    // ���磺replace("this is an expmple", "is", "") = "th  an expmple"
    string& replace(string &str, const char *old, const char* to)
    {
        string::size_type pos = 0;
        int len_old = strlen(old);
        int len_new = strlen(to);

        while((pos = str.find(old, pos)) != string::npos){   
            str.replace(pos, len_old, to);   
            pos += len_new;
        }

        return str;   
    }

    // ѭ���滻����ÿ���ַ������滻�������滻�����ַ����н����滻
    // ����: replace("dbdb", "db", "bd") = "bbbd"
    // ����: replace("good", "o", "oo") = "���ᵼ����ѭ��"
    string& cycle_replace(string &str, const char *old, const char* to)
    {
        string::size_type pos = 0;
        int len_old = strlen(old);

        while((pos = str.find(to)) != string::npos)
        {
            str.replace(pos, len_old, to);   
        }

        return str;  
    }

    // �����ļ���·��
    // ���磺../../xxxx.txt -> ../../
    string get_dir(const string &path)
    {
        if(path.empty())
        {
            return path;
        }

        int i = path.size() - 1;
        for(; i >= 0; i--)
        {
            if('\\' == path[i] || '/' == path[i])
            {
                break;
            }
        }

        if(i < 0)
        {
            return "";
        }

        return string(path.begin(), path.begin() + i);
    }

    // �Ƶ�·����ֻ�����ļ�����
    // ���磺../../xxxx.txt -> xxxx.txt
    string strip_dir(const string &path)
    {
        if(path.empty())
        {
            return path;
        }

        int i = path.size();
        for(; i >= 0; i--)
        {
            if('\\' == path[i] || '/' == path[i])
            {
                break;
            }
        }

        return path.c_str() + (i + 1);
    }

    // �Ƶ��ļ�����׺
    // ���磺strip_ext(xxxx.txt) = xxxx
    string strip_ext(const string &filename)
    {
        return trip_to(filename, '.');
    }

    // ��ȡ��ǰʱ���ַ���
    void time_str()
    {
        time_t rawtime;
        struct tm* timeinfo = NULL;
        
        time(&rawtime);
        if(localtime_s(timeinfo, &rawtime))
        {
            return;
        }

        static char buf[1024];
        sprintf_s(buf, sizeof(buf), "%4d-%02d-%02d %02d:%02d:%02d", 1900 + timeinfo->tm_year, 1 + timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    }

    // ��������ֱ��ָ���ָ������ַ���
    // ���磺trip_at("123_456", '_') = 123
    string trip_at(const string &str, char delimiter)
    {
        string::size_type pos = str.find(delimiter);
        if(pos == string::npos)
        {
            return str;
        }

        return string(str.begin(), str.begin() + pos);
    }

    // ��������ֱ�����һ���ָ������ַ���
    // ���磺trip_to("123_456_789", '_') = 123_456
    string trip_to(const string &str, char delimiter)
    {
        string::size_type pos = str.rfind(delimiter);
        if(pos == string::npos)
        {
            return str;
        }

        return string(str.begin(), str.begin() + pos);
    }

    // ��������ֱ��ָ���ָ������ַ���
    // ���磺r_trip_at("123_456", '_') = 456
    string r_trip_at(const string &str, char delimiter)
    {
        string::size_type pos = str.rfind(delimiter);
        if(pos == string::npos)
        {
            return str;
        }

        return string(str.begin() + pos + 1, str.end());
    }

    // ���޷���64λ����ת��Ϊ�ַ���
    // ���磺tostr(100123) = "100123"
    string tostr(uint64_t n)
    {
        char buf[64] = {0};
        errno_t err = _ui64toa_s (n, buf, sizeof(buf), 10);
        if(err)
        {
            return "";
        }

        return buf;
    }
}