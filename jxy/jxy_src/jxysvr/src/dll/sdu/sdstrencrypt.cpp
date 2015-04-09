#include "sdstrencrypt.h"

using namespace SGDP;

//��ÿ���ֽڸߵ�4bit��������KEY�����������
void  CSDStrEncrypt::Encode(std::string& sContent)
{
    Encode( (BYTE*)sContent.c_str(), sContent.size());
}

void  CSDStrEncrypt::Encode(BYTE* pBuf, INT32 nLen)
{
    if(nLen > 2)
    {
        for (int i = 2; i < nLen; ++i)
        {
            pBuf[i] = (pBuf[i]<<4) | (pBuf[i]>>4);
            pBuf[i] ^= CODE_KEY;
        }
    }
}

void  CSDStrEncrypt::Decode(std::string& sContent)
{
    Decode((BYTE*)sContent.c_str(), sContent.size());
}

void  CSDStrEncrypt::Decode(BYTE* pBuf, INT32 nLen)
{
    if(nLen > 2)
    {
        for (int i = 2; i < nLen; ++i)
        {
            pBuf[i] ^= CODE_KEY;
            pBuf[i] = (pBuf[i]<<4) | (pBuf[i]>>4);
        }
    }
}


