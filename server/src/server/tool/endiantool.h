///<------------------------------------------------------------------------------
//< @file:   server\tool\endiantool.h
//< @author: ������
//< @date:   2014��11��25�� 15:26:49
//< @brief:
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _endiantool_h_
#define _endiantool_h_

namespace endiantool
{
	// ��64λ�������������ֽ�˳��ת���������ֽ�˳��
	uint64_t hostToNetwork(uint64_t host64);

	// ��32λ�������������ֽ�˳��ת���������ֽ�˳��
	uint32 hostToNetwork(uint32 host32);

	// ��16λ�������������ֽ�˳��ת���������ֽ�˳��
	uint16 hostToNetwork(uint16 host16);

	// ��64λ�������������ֽ�˳��ת���������ֽ�˳��
	uint64_t networkToHost64(uint64_t net64);

	// ��32λ�������������ֽ�˳��ת���������ֽ�˳��
	uint32 networkToHost32(uint32 net32);

	// ��16λ�������������ֽ�˳��ת���������ֽ�˳��
	uint16 networkToHost16(uint16 net16);
}

#endif //_endiantool_h_