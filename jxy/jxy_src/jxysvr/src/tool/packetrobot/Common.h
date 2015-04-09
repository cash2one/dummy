
#ifndef _COMMON_H_
#define _COMMON_H_

#include <sdtype.h>

// ---------------- ��  �� ----------------
#ifndef UNICODE
// asc�ַ���תutf-8�ַ���
INT32 ASC2UTF(TCHAR* _Output, TCHAR* _Input);

// utf-8�ַ���תasc�ַ���
INT32 UTF2ASC(TCHAR* _Output, TCHAR* _Input);
#endif

// ��ȡ��ǰʱ���ַ���
VOID TimeString(CHAR* _Output);

// д���ļ�
INT32 WriteLog(CHAR* _Data);

// ��������ת�ַ���
template<typename T>
VOID ArrayToString(T* _Data, UINT32 _Size, CHAR* _Output)
{
	if(NULL == _Data || NULL == _Output)
		return;
	strcpy(_Output, "{");
	for(UINT32 i = 0; i < _Size; i++)
	{
		if(i == _Size - 1)
		{
			sprintf(_Output, "%s%d}", _Output, *(_Data + i));
		}
		else
		{
			sprintf(_Output, "%s%d, ", _Output, *(_Data + i));
		}
	}
}

/**
 * @brief �ַ���ת����
 * @param szInput : ���������ַ���
 * @param cFilter : �����ַ�
 * @param acArray : ��ֵ������
 * @param nArrayCount : �����С
 * @param nRetCount : �����ĸ���
 * @return ת�����
 */

template<typename T>
BOOL StringToArray(const CHAR* szInput, const CHAR cFilter, T acArray[], INT32 nArrayCount, UINT16& wRetCount )
{
	CHAR* pszTemp = SDNew CHAR[strlen(szInput) + 1];
	strcpy(pszTemp, szInput);
	CHAR* pszBegin = pszTemp;
	CHAR* pszEnd = NULL;
	wRetCount = 0;
	memset(acArray, 0, sizeof(T) * nArrayCount);
	do
	{
		if('\0' == *pszBegin)
		{
			break;
		}
		pszEnd = strchr(pszBegin, cFilter);
		if(pszEnd != NULL)
		{
			*pszEnd = '\0';
			if(nArrayCount > wRetCount)
			{
				acArray[wRetCount++] = SDAtoi(pszBegin);
			}
			else
			{
				SDDelete[] pszTemp;
				return FALSE;
			}
			pszBegin = pszEnd + 1;
		}
		else
		{
			if(nArrayCount > wRetCount)
			{
				acArray[wRetCount++] = SDAtoi(pszBegin);
			}
			break;
		}
	}
	while(TRUE);
	SDDelete[] pszTemp;
	return TRUE;
}



#endif

