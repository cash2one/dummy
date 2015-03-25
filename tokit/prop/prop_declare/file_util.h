#ifndef _file_util_h_
#define _file_util_h_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace fileuitl
{
    // ָ��·���Ƿ����
    // ���磺dir = "../../example"
    bool is_dir_exist(const std::string &dir);
    
    // ָ��·���Ƿ���ڣ���Ϊ�ļ�·�������ļ���·��
    // ���磺path = "../../example"
    // ���磺path = "../../abc.xml"
    // ���磺path = "../../"
    bool exist(const std::string &path);

    // �г�ָ���ļ����µ��ļ����б����ļ��н������ԣ���������windows�������µ�dir
    // ���磺path = ../../*.*,   �� files = { "a.txt", "b.txt", "c.exe" }
    // ���磺path = ../../*.txt, �� files = { "a.txt", "b.txt" }
    typedef std::vector<string> filevec_t;
    bool dir(const std::string &path, /* out */filevec_t &files);

    // �г�ָ���ļ����µ��ļ����б������ļ���ȥ����׺
    // ���磺�ļ�������һЩ�ļ� = { "a.txt", "b.txt", "c.exe" }, �� files = { "a", "b", "c" }
    bool dir_no_ext(const std::string &path, /* out */filevec_t &files);

    // �Զ����Ʒ�ʽ��ȡ�����ļ��������ļ���С���仺���������ļ����ݴ��뻺�����в�����
    // �û�����ͨ��new���䣬����Ҫ�ֶ�delete[]
    char* get_whole_file_buf(const std::string &path);

    // ���ַ���ʽ��ȡ�����ļ��������ı������ַ������ļ���ʱ���ʺ��ô˷���,��Ϊ���ص�string���������
    string get_whole_file_str(const std::string &path);
}

#endif // _file_util_h_
