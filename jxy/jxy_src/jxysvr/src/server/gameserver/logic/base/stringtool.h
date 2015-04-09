///<------------------------------------------------------------------------------
//< @file:   soultool.h
//< @author: yewenhui
//< @date:   2014��6��13�� 15��20��
//< @brief:  ������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------
#ifndef _STRING_TOOL_H_ 
#define _STRING_TOOL_H_

#include "sdstring.h"
#include <vector>
#include <set>
using namespace std;
namespace StringTool
{
	void SDSplitStringToUInt(std::vector<UINT32>& vUIntSplit, const std::string& strSrc, CHAR delim);

	void SDSplitStringToSet( set<UINT16>& setT, const string& strValue, CHAR strSplit);
}

#endif // _STRING_TOOL_H_
