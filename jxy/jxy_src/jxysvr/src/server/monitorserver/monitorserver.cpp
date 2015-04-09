#include "sdframework.h"
#include "framework/msapplication.h"
#include "common/server/utility.h"


#include <iostream>


#if (!(defined(WIN32) && !defined(WIN64)))
#include<sys/types.h>
#include<sys/stat.h>
#endif

#define CONFIG_FILE_NAME      _SDT("ms_config.xml")



INT32 main(INT32 argc, TCHAR** argv) 
{ 

#if (!(defined(WIN32) && !defined(WIN64)))
	switch (fork())
	{
	case -1:
		perror("fork:");
		exit(0);
	case 0:
		break;
	default:
		exit(0);
		break;
	}
	setsid();//��һ�ӽ��̳�Ϊ�µĻỰ�鳤�ͽ����鳤 
	//chdir("/tmp");//�ı乤��Ŀ¼��/tmp 
	//umask(0);//�����ļ�������ģ 
#endif

	SetLocateCharSet();
    TCHAR szConfig[MAX_PATH] = {0};
    _SDTsnprintf(szConfig, MAX_PATH, _SDT("%s%s"), SDGetModulePath(), CONFIG_FILE_NAME);

    CMSApplication* pApp = (CMSApplication*)SDGetApp();
    pApp->OnSetCmdLine(argc,argv); 
    if (FALSE == pApp->Init(szConfig)) 
        return 0; 

    while(FALSE == pApp->IsTerminated()) 
    { 
        pApp->Run(); 
    }; 
    pApp->UnInit(); 
	system("pause");

    return 0; 
}



