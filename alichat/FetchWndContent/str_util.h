#ifndef STR_UTIL
#define STR_UTIL

namespace strutil
{
    // ��char*ת��Ϊwchar_t*, ���صĿռ����ֶ�ɾ��
    wchar_t* char_to_wchar(const char*);

    // ��wchar_t*ת��Ϊchar*, ���صĿռ����ֶ�ɾ��
    char* wchar_to_char(wchar_t*);
}

#endif