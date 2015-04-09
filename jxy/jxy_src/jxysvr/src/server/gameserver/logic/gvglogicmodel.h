///<------------------------------------------------------------------------------
//< @file:   gvglogicmodel.h
//< @author: hongkunan
//< @date:   2014��1��14�� 17:24:54
//< @brief:  
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gvglogicmodel_h_
#define _gvglogicmodel_h_

#include <sdtype.h>
#include <sdsingleton.h>

/**
*@brief ��ģ���װ����Ϸ�߼������з�������Init�������ⲿ��ܿɼ���
*�ⲿ���ģ�鲻����Logic���ֵľ���ʵ�֣�ֻ��Ҫ��ʱ����Init�������ɡ�
*/

class CGvGLogicModel
{    
    DECLARE_SINGLETON(CGvGLogicModel)

public:
    CGvGLogicModel();
    ~CGvGLogicModel();

public:
    BOOL    Init();
    BOOL	OnAtExit();//�˳�ǰ�Ļص����������ݵȵȣ�
    VOID    Stop();
    VOID    Destroy();

private:

};

#endif //_gvglogicmodel_h_