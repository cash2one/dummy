#ifndef _TOLUAFUNC_H_
#define _TOLUAFUNC_H_

#include <sdtype.h>

class CPlayer;

UINT64 GetTimeValue(const CHAR* pszDateTime); //���ڸ�ʽ�ַ����� 2013/11/28 17:23:37

UINT32 GetRank(CPlayer* poPlayer); //��ȡ������0��ʾû������

INT32 LuaRandomReseed(UINT32 dwRange); //�������Ӳ����

#endif

