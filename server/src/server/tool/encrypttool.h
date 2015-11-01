///<------------------------------------------------------------------------------
//< @file:   server\tool\encrypttool.h
//< @author: ������
//< @date:   2015��3��17�� 0:56:2
//< @brief:	 �ӽ��ܹ�����
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _encrypttool_h_
#define _encrypttool_h_

// �ӽ��ܹ�����
namespace encrypttool
{
	// ���ʽ���ܣ���ԭʼ�ļ��ܷ�ʽ�����ױ��ƽ⣩
	void xor_encrypt(uint8 *data, int dataLen, uint8 encryptKey[], uint32 keyLen);

	// ���ʽ���ܣ���ԭʼ�Ľ��ܷ�ʽ�����ױ��ƽ⣩
	bool xor_decrypt(uint8 *data, int dataLen, const uint8 encryptKey[], uint32 keyLen);
}

#endif //_encrypttool_h_