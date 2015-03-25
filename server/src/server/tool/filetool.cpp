///<------------------------------------------------------------------------------
//< @file:   server\tool\filetool.cpp
//< @author: ������
//< @date:   2014��11��20�� 10:49:56
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#include "filetool.h"
#include <windows.h>
#include <tchar.h>

namespace tool
{
	std::string GetAbsolutePath()
	{
		char path[300];
		GetModuleFileName(NULL, path, sizeof(path));
		char *p = strrchr(path, '\\');
		*p = '\0';
		strcat_s(path, sizeof(path), "\\");

		return path;
	}
}
