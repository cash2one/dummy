///<------------------------------------------------------------------------------
//< @file:  %cfg%.h
//< @brief: ��ͷ�ļ��ɹ����Զ����ɣ������ڱ��ļ������Ķ�
//< @Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _%cfg%_h_
#define _%cfg%_h_

#include <string>

#include <map>
#include <vector>
#include <set>

%structs_part%

// %cfg_member%
class %cfg%mgr
{
public:
%mgr_typedefs_part%

public:
	%cfg%mgr(){}
	~%cfg%mgr(){}

	static %cfg%mgr& instance(){
		static %cfg%mgr static_%cfg%mgr;
		return static_%cfg%mgr;
	}

private:
    %cfg%mgr& operator=(const %cfg%mgr&){}
    %cfg%mgr(const %cfg%mgr&){}

public:
	// @impl ��ȡ������������
	std::string mgr_name(){ return "%cfg%"; }

    // ��ȡ����������·��
    std::string get_path(std::string xml){ return "../../xml/" + xml;}

public:
    // ����%cfg_member%
	bool load();

    // ���%cfg_member%
    void clear();

// ���뷽��
public:
%mgr_load_funcs_part%

// ��շ���
public:
%mgr_clear_funcs_part%

// ���ҷ���
public:
%mgr_find_funcs_part%

// ��ȡ��Ա����
public:
%mgr_get_funcs_part%

// ��Ա������
public:
%mgr_members_part%
};

#endif // _%cfg%_h_
