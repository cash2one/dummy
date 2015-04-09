/******************************************************************************
            

����ģ�飺�����ڴ���־ ����־���ƿ���Ϣ���� 
�ļ����ݣ������� ��־�����ڴ�Ŀ��ƿ���Ϣ
��    �ܣ�

******************************************************************************/

#ifndef LOGSERVICECTRL_H
#define LOGSERVICECTRL_H

#include <stdio.h>
#include <string.h>
#include "sdtype.h"

using namespace SGDP; 

#pragma pack(push, 1)

struct  SFileLogDesc
{

    char  m_szFileDir[256];
    char  m_szFileName[128];
    INT32 m_nId;
    INT32 m_nMode;
};

union ULogType
{
    SFileLogDesc  m_stFilelogdesc;
    char          m_acReserved[800];

};

struct SLogInfo
{
    SLogInfo()
    {

    }

    //
    //���ݿ�Ĺ����ڴ� key,-1��ʾ��ǰ�����ڴ�
    //
    INT32   m_nKey;

    //
    //���С�����û�͸�����û���д��ʱ����Ҫע�ⲻ�ܳ��������С
    //
    UINT32  m_dwSize;

    //
    //�ڹ����ڴ��е�ƫ��
    //
    UINT32  m_dwOffSet;
};

struct SLogServiceCtrItem
{
    enum STATE 
    {
        FREE=0,
        APPLY,
        INUSE,
        RELEASE
    };
    enum LOGTYPE 
    {
        FILE_LOG=0
    };

    SLogServiceCtrItem():m_nState(FREE),m_dwSecond(0)
    {
        memset(this,0,sizeof(SLogServiceCtrItem));
    }
    //
    //״̬�������ÿ��ƽṹ��״̬
    //
    INT32     m_nState;

    //
    //��������־���ͣ�Ŀǰֻʵ�����ļ���־
    //
    INT32     m_nType;
    
    //
    //��ǰʱ�䣬���������ÿ��ƿ��Ӧ����־�����Ƿ���
    //
    UINT32    m_dwSecond;

    //
    //��־��ϸ��¼��ʽ˵��
    //
    ULogType  m_stLogCtrl;

    //
    //��־��¼��λ��
    //
    SLogInfo  m_stLogPos;


};
#pragma pack(pop)

class CLogServiceCtr
{
public:
    CLogServiceCtr()
    {
        m_pnCount   = NULL;
        m_pnSize    = NULL;
        m_pItem     = NULL;
        m_pAddress  = NULL;
        m_pDataAddress = NULL;
    }


    CLogServiceCtr(char* pAddress)
    {
        m_pnCount = (INT32*)pAddress;
        m_pnSize = (INT32*)(pAddress + sizeof(INT32));
        m_pAddress = pAddress;
        m_pItem = (SLogServiceCtrItem*)(pAddress + sizeof(INT32) * 2);
        m_pDataAddress = pAddress + sizeof(INT32) * 2 + (*m_pnCount) * sizeof(SLogServiceCtrItem);
    }



    ~CLogServiceCtr()
    {
        m_pnCount     = NULL;
        m_pnSize      = NULL;
        m_pAddress    = NULL;
        m_pDataAddress= NULL;
        m_pItem       = NULL;
    }
    //
    //���ƿ�ĸ���
    //
    INT32*             m_pnCount;

    //
    //ָ�����ڴ�ͷ������ÿ�����ݿ�Ĵ�С
    //
    INT32*             m_pnSize;

    //
    //���ƿ����飬ָ�����ڴ�
    //
    SLogServiceCtrItem *m_pItem;

    //
    //�����ڴ���ʼ��ַ
    //
    char*              m_pAddress;

    //
    //���ݶ���ʼ��ַ
    //
    char*              m_pDataAddress;
};

#endif

