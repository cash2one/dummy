///<------------------------------------------------------------------------------
//< @file:   server\tool\randtool.h
//< @author: ������
//< @date:   2015��3��17�� 22:40:38
//< @brief:	 ��ȡ�����
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _randtool_h_
#define _randtool_h_

typedef std::vector<uint32> HitVec;

namespace randtool
{
	// ��ʼ����������ӣ�����������ʱ����
	void initSeed();

	// ���������
	uint32 random();

	// ��ȡ���������Χ��[0, unRange - 1]
	uint32 random(uint32 range);

	// ��ȡ���������Χ��[unMinRange, unMaxRange - 1]
	uint32 random(uint32 minnum, uint32 maxnum);

	// ���������㷨���������еĸ������(hitVec�е�˳��),û�и��ʷ���0���
	uint32 rollHit(HitVec &hitVec);

	// ��ȡһ������������ڼ��ܵ�α�������������Cryptographically Secure Pseudo-Random Number Generator �C CSPRNG��
	void secureRandom(uint8 nums[], uint32 cnt, int beg, int end);
}

#endif //_randtool_h_