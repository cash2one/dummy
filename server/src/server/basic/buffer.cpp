///<------------------------------------------------------------------------------
//< @file:   server\basic\buffer.cpp
//< @author: ������
//< @date:   2015��2��26�� 18:33:12
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#include "buffer.h"

const char Buffer::kCRLF[] = "\r\n";

const size_t Buffer::g_cheapPrepend = 0;
const size_t Buffer::g_initSize = 128;