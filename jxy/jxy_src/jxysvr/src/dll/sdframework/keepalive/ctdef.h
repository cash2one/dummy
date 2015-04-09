#ifndef CTDEF_H_
#define CTDEF_H_


#include <sdprocess.h>

using namespace SGDP;

#pragma pack(push, 1)

//������Ϣ
typedef struct tagProcessDaemon
{
	SDPROCESSID	pid;
	time_t 		starttimer;
	time_t 		lasttimer;
	int 			useFlag; //ʹ�ñ�־
	int 			alive;
}SProcessDaemon;

#pragma pack(pop)
#endif