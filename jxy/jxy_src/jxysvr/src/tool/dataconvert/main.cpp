#include <iostream>
#include <sddb.h>
#include <dll/sdframework/sdloggerimpl.h>
#include <dll/sdnet/sdnet.h>
#include "convert.h"
using namespace std;
using namespace SGDP;

void Exit()
{
	std::system("pause");
	exit(0);
}

int main()
{
	string strCfgName("loggercfg.xml");
	if( !CSDLoggerImpl::Init( strCfgName.c_str() ) )
	{
		cout<<"��־��ʼ��ʧ�ܣ����������ļ���"<<strCfgName<<endl;
		Exit();
	}

// 	CSDComLoggerImpl netLogger;
// 	netLogger.Init(_SDT("[SDNET] "));
	//SGDP::SDNetSetLogger(&netLogger, 0);


	USR_INFO( _SDT( "��ʼת��" ) );
	Convert conv;
	if( !conv.Init() )
	{
		cout<<"��ʼ��ʧ�ܣ�ת��ʧ��"<<endl;
		Exit();
	}

	cout<<"��ʼִ��"<<endl;
	if( !conv.Process() )
	{
		cout<<"����ʧ�ܣ�������ϸ��Ϣ��鿴log"<<endl;
		SYS_CRITICAL( _SDT( "����ʧ��!" ) );
	}
	else
	{
		cout<<"ִ�����:"<<endl<<conv.GetResultDes();
	}
	if( !conv.UnInit() )
	{
		cout<<"�ͷ�ʱʧ��"<<endl;
		Exit();
	}
	USR_INFO( "ִ�����:%s", conv.GetResultDes().c_str() );
	CSDLoggerImpl::UnInit();
	Exit();
	return 0;
}