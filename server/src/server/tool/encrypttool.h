///<------------------------------------------------------------------------------
//< @file:   server\tool\encrypttool.h
//< @author: ������
//< @date:   2015��3��17�� 0:56:2
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _encrypttool_h_
#define _encrypttool_h_

namespace encrypttool
{
	void encrypt(uint8 *data, int dataLen, uint8 encryptKey[], uint32 keyLen);

	bool decrypt(uint8 *data, int dataLen, uint8 encryptKey[], uint32 keyLen);
}

#endif //_encrypttool_h_