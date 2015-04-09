#include "sdclientlogin.h"
#include "clidefine.h"
#include <protocligt.h>
#include "sdmsg.h"
#include <WinSock2.h>


using namespace SGDP;

/// ��¼���Ļ�������С
#define SDLOGIN_BUF_SIZE	40960
/// ��¼��ʽ
const TCHAR*    TYPE_PT         = _T("pt");
/// �û�����־
const CHAR*     CLIKEY_USERNAME = "UserName";
/// �����־
const CHAR*     CLIKEY_PASSWORD = "PassWord";
/// ��������ͷ��С
const INT32 gnNetMsgHeaderSize  = sizeof(STNetMsgHeader);

/// ��������ͷ
VOID BuildNetHeader(CHAR* pBuf, UINT16 wMsgID, UINT32 dwLen)
{
    STNetMsgHeader* pNetMsgHeader = (STNetMsgHeader*)pBuf;
    UINT32 dwMsgLen = htonl(dwLen);
    pNetMsgHeader->dwDataLen = dwMsgLen;
    pNetMsgHeader->wMsgID = htons(wMsgID);
}

/// Э�����
INT32 Encode(INT32 iMsgID, CHAR* pHost, CHAR* pNet, INT32 iNetSize)
{
    if (NULL == pHost || NULL == pNet || iNetSize < gnNetMsgHeaderSize)
    {
        return -2;
    }
    INT32 iEncodeLen = CProtoCliGT::Instance()->Encode(iMsgID, 
        pHost, 
        pNet + gnNetMsgHeaderSize, 
        iNetSize - gnNetMsgHeaderSize);
    if(-1 == iEncodeLen)
    {
        return -1;
    }
    UINT16 wMsgID = (UINT16)iMsgID;
    BuildNetHeader(pNet, wMsgID, iEncodeLen);
    return iEncodeLen + gnNetMsgHeaderSize;
}

/// Э�����
INT32 Decode(INT32 iMsgID, CHAR* pNet, INT32 iNetSize, CHAR* pHost, INT32 iHostSize)
{
    if (NULL == pNet || NULL == pHost)
    {
        return -2;
    }
    INT32 iDecodeLen = CProtoCliGT::Instance()->Decode(iMsgID,
        pNet,
        iNetSize,
        pHost,
        iHostSize);

    if(-1 == iDecodeLen)
    {
        return -1;
    }
    return iDecodeLen;
}

/// ��ȡ�������ݳ���
INT32 GetDataLength(CHAR *pBuf)
{
    if(NULL == pBuf)
    {
        return -1;
    }
    STNetMsgHeader* pNetMsgHeader = (STNetMsgHeader*)pBuf;
    return ntohl(pNetMsgHeader->dwDataLen);
}

/// ��ȡ����Э���
INT32 GetMsgID(CHAR *pBuf)
{
    if(NULL == pBuf)
    {
        return -1;
    }
    STNetMsgHeader* pNetMsgHeader = (STNetMsgHeader*)pBuf;
    INT32 nMsgID = ntohs(pNetMsgHeader->wMsgID);
    return nMsgID;
}

/// ��ȡ����ͷ����
INT32 GetHeaderLen()
{
    return gnNetMsgHeaderSize;
}

