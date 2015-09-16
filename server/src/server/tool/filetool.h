///<------------------------------------------------------------------------------
//< @file:   server\tool\filetool.h
//< @author: ������
//< @date:   2014��11��20�� 10:45:10
//< @brief:	 �ļ���������
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _filetool_h_
#define _filetool_h_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace filetool
{
	// ��ȡ��ǰ���������ľ���·��
	std::string GetAbsolutePath();

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

	// �Զ����Ʒ�ʽ��ȡ�����ļ��������ļ���С���仺���������ļ����ݴ��뻺�����в�����
	// �û�����ͨ��new���䣬����Ҫ�ֶ�delete[]
	char* get_whole_file_buf(const std::string &path);

	// ���ַ���ʽ��ȡ�����ļ��������ı������ַ������ļ���ʱ���ʺ��ô˷���,��Ϊ���ص�string���������
	bool get_whole_file_str(const std::string &path, std::string &text);

	// �����ļ�������ļ����ݲ��䣬��������������ֱ�����µ��ļ������滻��ԭ���ģ���ô����ϣ�����ļ����ݲ���ʱ����ֹ�ļ���ʱ��������仯��
	bool overwrite_file(const std::string &path, const std::string &text);
}

#endif //_filetool_h_