///<------------------------------------------------------------------------------
//< @file:   server\tool\atomictool.h
//< @author: ������
//< @date:   2015��3��27�� 15:15:8
//< @brief:	 ԭ�Ӳ����㷨
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _atomictool_h_
#define _atomictool_h_

namespace atomictool
{
	int cas(int *x, int y, int z);

	// 32λԭ�Ӽ�1�㷨����ԭʼֵ��1
	int inc(volatile int *x);

	// 32λԭ�Ӽ�1�㷨����ԭʼֵ��1
	int dec(volatile int *x);

	// 32λԭ�Ӽӷ�
	int add(volatile int *x, int val);

	// 32λԭ�Ӽ���
	int sub(volatile int *x, int val);
}

#endif //_atomictool_h_