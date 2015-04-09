

#ifndef _LOGIC_MODEL_H_
#define _LOGIC_MODEL_H_

#include <sdtype.h>
#include <sdsingleton.h>

/**
*@brief ��ģ���װ����Ϸ�߼������з�������Init�������ⲿ��ܿɼ���
*�ⲿ���ģ�鲻����Logic���ֵľ���ʵ�֣�ֻ��Ҫ��ʱ����Init�������ɡ�
*
*/


class CLogicModel
{    
    DECLARE_SINGLETON(CLogicModel)

public:
    CLogicModel();
    ~CLogicModel();

public:
    BOOL    Init();
    BOOL    InitGvG();
	BOOL	OnAtExit();//�˳�ǰ�Ļص����������ݵȵȣ�
    VOID    Destroy();

	VOID	Run();

private:

};



#endif //_LOGIC_MODEL_H_

