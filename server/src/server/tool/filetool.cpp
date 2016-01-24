///<------------------------------------------------------------------------------
//< @file:   server\tool\filetool.cpp
//< @author: ������
//< @date:   2014��11��20�� 10:49:56
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#include "filetool.h"

// #include <sys/stat.h>
#include <fstream>
#include <sstream>

#include "echotool.h"

#ifdef WIN
	#include <io.h>
	#define access _access
#else
	#include <unistd.h>
#endif

using namespace std;

namespace filetool
{
	bool exist(const std::string &path)
	{
		return access(path.c_str(), 0) != -1;
	}

	char* open(const char *path)
	{
		if(false == exist(path)) {
			LOG_SYSTEM_ERR << "open <" << path << "> file failed: not found";
			return NULL;
		}

		/* ��Ҫһ��byte��©�ض��������ļ���ֻ�ܲ��ö����Ʒ�ʽ�� */
		FILE *file = NULL;

#ifdef WIN
		int err = fopen_s(&file, path, "rb" );
		if (NULL == file || err > 0) {
			LOG_SYSTEM_ERR << "��<" << path << ">�ļ�ʧ�ܣ������:" << err;
			return NULL;
		}
#else
		file = fopen(path, "rb" );
		if (NULL == file) {
			LOG_SYSTEM_ERR << "��<" << path << ">�ļ�ʧ��";
			return NULL;
		}
#endif

		/* ��ȡ�ļ���С */
		fseek (file , 0 , SEEK_END);
		long size = ftell (file);
		rewind (file);

		/* �����ڴ�洢�����ļ� */
		char *buf = new char[size + 1];
		if (buf == NULL)        {
			LOG_SYSTEM_ERR << "����<" << path << ">�ļ�ʧ�ܣ�����ԭ��:����<" << size << ">���ڴ�ʧ��";
			return NULL;
		}

		/* ���ļ�������buffer�� */
		size_t ret = fread (buf, 1, size, file);
		if (ret != (size_t)size) {
			LOG_SYSTEM_ERR << "����<" << path << ">�ļ�ʧ�ܣ�����ԭ��:�ļ���ȡ��С����" << ret << " != " << size;
			delete[] buf;
			return NULL;
		}

		/* ���������ļ��Ѿ���buffer�� */
		/* �ر��ļ����ͷ��ڴ� */
		fclose (file);

		buf[size] = '\0';
		return buf;
	}

	bool get_whole_file_str(const std::string &path, std::string &text)
	{
		if(false == exist(path)) {
			text = "";
			return false;
		}

		std::ifstream file(path.c_str());
		std::stringstream buf;
		buf << file.rdbuf();

		text = buf.str();
		return true;
	}
}

namespace tool
{
	std::string GetAbsolutePath()
	{
#ifdef WIN
		char path[300];
		GetModuleFileName(NULL, path, sizeof(path));
		char *p = strrchr(path, '\\');
		*p = '\0';
		strcat_s(path, sizeof(path), "\\");

		return path;
#else
		return "";
#endif
	}

}
