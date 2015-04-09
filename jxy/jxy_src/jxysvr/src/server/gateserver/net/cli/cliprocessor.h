#ifndef __SDF_CLI_HANDLER_INCLUDE_H_
#define __SDF_CLI_HANDLER_INCLUDE_H_
#include "sdframework.h"
#include "protocol/server/protocligt.h"

class CCliProcessor : public CSDPacketProcessor
{
public:
    CCliProcessor();
public:
    ~CCliProcessor();
    virtual BOOL Init();
    virtual CSDProtocol* GetProtocol();

protected:
    //���������Ϸ��Ϣ
    static BOOL			OnEnterGsReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //����ע���ʺ���Ϣ
    static BOOL			OnRegisterReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //������֤��Ϣ
    static BOOL			OnLoginExReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);




    //�����û�����Ϣ
    static BOOL			OnBindReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����û�����Ϣ
    static BOOL			OnUnBindReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //����ǳ���Ϣ
    static BOOL			OnLogoutReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����޸���Ϣ
    static BOOL			OnChangePwdReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����޸���Ϣ
    static BOOL			OnBindMobileReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����޸���Ϣ
    static BOOL			OnBindCheckVerCodeReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����޸���Ϣ
    static BOOL			OnUnBindMobileReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����޸���Ϣ
    static BOOL			OnUnBindCheckVerCodeReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);

    //�����޸���Ϣ
    static BOOL			OnGetUserExpandReq (VOID* poReceiver, VOID* pHeader, const CHAR* pszBody, UINT32 dwLen);
private:

};

#endif

