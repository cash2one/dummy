#ifndef _MOCKSESSION_H_
#define _MOCKSESSION_H_

#include "sdnet.h"
#include "clidefine.h"
#include "mgencrypt.h"

class CCliSession : public SGDP::ISDSession
{
public:
    /**
     * @brief ��������ͷ
     * @return ���ر��Ĵ�С
     */
    INT32 BuildNetHeader(STNetMsgHeader* pstHead, UINT16 wMsgID, UINT32 dwDataLen);
    
    /**
     * @brief ��ȡ����
     * @return �������ӽӿ�ָ��
     */
    SGDP::ISDConnection* GetConnection();

    /**
     * @brief ����Э�鱨��
     * @param wMsgID : Э��ID
     * @param pBuf : ��������ַ
     * @param nLen : ��������С
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL SendMsg(UINT16 wMsgID, const CHAR* pBuf, INT32 nLen);

public:
    //
    // Name     : SetConnection
    // Function : Set the ISDConnection object to the ISDSession object.
    //
    virtual VOID SDAPI SetConnection(SGDP::ISDConnection* poConnection);

    //
    // Name     : OnEstablish
    // Function : Callback when the connection is established.
    //
    virtual VOID SDAPI OnEstablish();

    //
    // Name     : OnTerminate
    // Function : Callback when the connection is closed.
    //
    virtual VOID SDAPI OnTerminate();

    //
    // Name     : OnError
    // Function : Callback when TCP connection has error.
    //
    virtual bool SDAPI OnError(INT32 nModuleErr, INT32 nSysErr);

    //
    // Name     : OnRecv
    // Function : Callback when receive a packet, which is parsed by ISDPacketParser.
    //            
    //
    virtual VOID SDAPI OnRecv(const char* pBuf, UINT32 dwLen);

    //
    // Name     : Release
    // Function : Release ISDSession object. It will be callback when SDNet no
    //            more use it.
    //
    virtual VOID SDAPI Release();

	MGEncrypt& GetMGEncrypt() { return m_oMGEncrypt; }

public:
	VOID SetKey(const unsigned char * pEncryptKey, unsigned int keyLength){ m_oMGEncrypt.setKey(pEncryptKey, keyLength); }
	VOID ClrKey() { m_oMGEncrypt.clear(); }

protected:
    SGDP::ISDConnection*  m_poConnection;         ///< TCP���ӣ������Ա����ŷ��ͱ��Ľӿ�

	//�ӽ���
	MGEncrypt	m_oMGEncrypt;
};

#endif // #ifndef _MOCKSESSION_H_

