///<------------------------------------------------------------------------------
//< @file:   server\tool\atomictool.h
//< @author: ������
//< @date:   2015��3��27�� 15:15:8
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _atomictool_h_
#define _atomictool_h_

namespace atomictool
{
	// 32λԭ�Ӽ�1�㷨����ԭʼֵ��1
	int inc(volatile int *mem);

	// 32λԭ�Ӽ�1�㷨����ԭʼֵ��1
	int dec(volatile int *mem);

	// 32λԭ�Ӽӷ�
	int add(volatile int *mem, int val);

	// 32λԭ�Ӽ���
	int sub(volatile int *mem, int val);
}

#endif //_atomictool_h_