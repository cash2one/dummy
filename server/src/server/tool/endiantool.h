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
	uint64_t hostToNetwork64(uint64_t host64);

	// ��32λ�������������ֽ�˳��ת���������ֽ�˳��
	uint32_t hostToNetwork32(uint32_t host32);

	// ��16λ�������������ֽ�˳��ת���������ֽ�˳��
	uint16_t hostToNetwork16(uint16_t host16);

	// ��64λ�������������ֽ�˳��ת���������ֽ�˳��
	uint64_t networkToHost64(uint64_t net64);

	// ��32λ�������������ֽ�˳��ת���������ֽ�˳��
	uint32_t networkToHost32(uint32_t net32);

	// ��16λ�������������ֽ�˳��ת���������ֽ�˳��
	uint16_t networkToHost16(uint16_t net16);
}

#endif //_endiantool_h_