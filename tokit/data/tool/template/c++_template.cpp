///<------------------------------------------------------------------------------
//< @file:  %cfg%.cpp
//< @brief: ��ͷ�ļ��ɹ����Զ����ɣ������ڱ��ļ������Ķ�
//< @Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "%cfg%.h"

#include <iostream>
#include <string.h>
#include <rapidxml_utils.hpp>
#include "tickutil.h"
#include "str_util.h"

%structs_ctor%

void %cfg%mgr::clear()
{
%clear_stmt%
}

bool %cfg%mgr::load()
{
	bool is_succ = true;
%load_stmt%
	return is_succ;
}

%mgr_load_funcs_part%

%mgr_clear_funcs_part%

%mgr_find_funcs_part%