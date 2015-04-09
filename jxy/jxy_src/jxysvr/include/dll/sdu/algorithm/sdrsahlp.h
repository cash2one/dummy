
#ifndef SDRSAHLP_H
#define SDRSAHLP_H
/**
* @file sdrsahlp.h
* @brief ����RSA�����
*
**/
#include "config.h"
#include "sdtype.h"

#if SDU_WITH_OPENSSL

#include <openssl/rsa.h>
#include <openssl/crypto.h>
namespace SGDP
{
    /**
    * @defgroup groupcrypto �ӽ��ܲ���
    * @ingroup  SGDP
    * @{
    */

    /**
    *@brief RSA�����������������openssl��
    */

    /**
    * @brief
    * ����rsa key
    * @param nBit : ��Կ��λ��
    * @param pstPublicKey : ���ɵĹ�Կ
    * @param pstPrivateKey : ���ɵ�˽Կ
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL GenerateRsaKey(INT32 nBit, RSA* pstPublicKey, RSA* pstPrivateKey);

    /**
    * @brief
    * ���湫Կ���ļ�
    * @param pstPublicKey : ��Ӧ�Ĺ�Կָ��
    * @param pszFile : ������ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL SavePublicKey(const RSA* pstPublicKey, const CHAR* pszFile);

    /**
    * @brief
    * ����˽Կ���ļ�
    * @param pstPrivateKey : ��Ӧ��˽Կָ��
    * @param pszFile : ������ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL SavePrivateKey(const RSA* pstPrivateKey, const CHAR* pszFile);

    /**
     * @brief
     * ���ļ������빫Կ
     * @param pstPublicKey : ��Ӧ�Ĺ�Կָ��
     * @param pszFile : ��Կ��Ӧ���ļ���
     * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadPublicKey(RSA*& pstPublicKey, const CHAR* pszFile);

    /**
    * @brief
    * ���ļ������빫Կ
    * @param pstPrivateKey : ��Ӧ�Ĺ�Կָ��
    * @param pszFile : ��Կ��Ӧ���ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL LoadPrivateKey(RSA*& pstPrivateKey, const CHAR* pszFile);

    /**
    * @brief
    * ���ڴ������빫Կ
    * @param pstKey : ��Կָ��
    * @param pbyKeyBuf : �ڴ�ĵ�ַ
    * @param wKeyLen : �ڴ�ĳ���
	* @param iElemSize : BN_ULONG���͵Ĵ�С
    * @return VOID
    */
    // VOID LoadPublicKeyFromMem(RSA* &pstKey, UINT8* pbyKeyBuf, UINT16 wKeyLen, INT32 iElemSize);

    /**
     * @brief
     * ���ڴ������빫Կ
     * @param pstKey : ��Կָ��
     * @param pbyKeyBuf : �ڴ�ĵ�ַ
     * @param wKeyLen : �ڴ�ĳ���
     */
    VOID LoadPublicKeyFromMem(RSA* &pstKey, UINT8* pbyKeyBuf, UINT16 wKeyLen);

    /**
    * @brief
    * ���ڴ�������˽Կ
    * @param pstKey : ˽Կָ��
    * @param pbyKeyBuf : �ڴ�ĵ�ַ
    * @param wKeyLen : �ڴ�ĳ���
	* @param iElemSize : BN_ULONG���͵Ĵ�С
    * @return VOID
    */
    VOID LoadPrivateKeyFromMem(RSA* &pstKey, UINT8* pbyKeyBuf, UINT16 wKeyLen, INT32 iElemSize );

    /**
    * @brief
    * �����ݽ��м���
    * @param from : ��Ҫ���ܵĻ�������ַ
    * @param dwFromSize : ���ܻ���������
    * @param to : �������ݴ洢λ��
    * @param pPubKey : �����õĹ�Կ
    * @return VOID
    */
    UINT32 PubEncrypt(UINT8* from, UINT32 dwFromSize, UINT8* to, RSA* pPubKey);

    /**
    * @brief
    * �����ݽ��н���
    * @param from : ��Ҫ���ܵĻ�������ַ
    * @param dwFromSize : ��Ҫ���ܵĻ���������
    * @param to : �������ݴ洢λ��
    * @param pPriKey : �����õ�˽Կ
    * @return VOID
    */
    UINT32 PriDecrypt(UINT8* from, UINT32 dwFromSize, UINT8* to, RSA* pPriKey);

    /**
    * @brief
    * �ͷŹ�Կ��Դ
    * @param pstPublicKey : ��Կָ��
    * @return VOID
    */
    VOID FreePublicKey(RSA* &pstPublicKey);

    /**
    * @brief
    * �ͷ�˽Կ��Դ
    * @param pstPrivateKey : ˽Կָ��
    * @return VOID
    */
    VOID FreePrivateKey(RSA* &pstPrivateKey);

	/**
    * @brief
    * �ͷ�Crypto����ģʽȫ���ڴ�
    * @return VOID
    */
    VOID FreeCrypto();

    /** @} */

}

#endif // #if SDU_WITH_OPENSSL 

#endif /*#ifndef RSAHLP_H__ */


