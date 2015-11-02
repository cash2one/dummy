///<------------------------------------------------------------------------------
//< @file:   server\tool\echotool.h
//< @author: ������
//< @date:   2015��4��9�� 11:10:13
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _echotool_h_
#define _echotool_h_

enum ECHO_COLOR {
	COLOR_DEFAULT,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_YELLOW
};

void ColoredPrintf(ECHO_COLOR color, const char* fmt, ...);

#define ECHO_ERR(fmt, ...)		ColoredPrintf(COLOR_RED, fmt"\n", __VA_ARGS__)
#define ECHO_OK(fmt, ...)		ColoredPrintf(COLOR_GREEN, fmt"\n", __VA_ARGS__)
#define ECHO_WARN(fmt, ...)		ColoredPrintf(COLOR_YELLOW, fmt"\n", __VA_ARGS__)
#define ECHO_INFO(fmt, ...)		fprintf(stdout, fmt"\n", __VA_ARGS__);


namespace echotool
{
	// �ı����̨��ɫ
	void changeToColor(ECHO_COLOR);

	// �ָ�����̨��ɫ
	void changeToOldColor();

	// ���ݴ���ĸ�ʽ�ı��Ͳ����������յ��ı���
	const char* getmsg(const char* fmt, ...);
}

#endif //_echotool_h_