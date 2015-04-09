#ifndef __SDRSA_H__
#define __SDRSA_H__

/**
* @file sdrsahlp.h

* @brief ����RSA�����
*
**/
#include "config.h"
#include "sdtype.h"

#if SDU_WITH_OPENSSL

namespace SGDP
{
	typedef VOID* RSAKEY;

	/**
    * @defgroup groupcrypto �ӽ��ܲ���
    * @ingroup  SGDP
    * @{
    */

    /**
    *@brief RSA�����������������openssl��
    */

    /**
    * @brief ����rsa key
    * @param nBit : ��Կ��λ��
    * @param pPublicKey : ���ɵĹ�Կ
    * @param pPrivateKey : ���ɵ�˽Կ
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL  GenerateRsaKey(INT32 nBit, RSAKEY *pPublicKey, RSAKEY *pPrivateKey);

    /**
    * @brief ���湫Կ���ļ�
    * @param PublicKey : ��Ӧ�Ĺ�Կָ��
    * @param pszFile : ������ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL  SavePublicKey(const RSAKEY PublicKey, const CHAR *pszFile);

    /**
    * @brief ����˽Կ���ļ�
    * @param PrivateKey : ��Ӧ��˽Կָ��
    * @param pszFile : ������ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL  SavePrivateKey(const RSAKEY PrivateKey, const CHAR* pszFile);

    /**
    * @brief ���ļ������빫Կ
    * @param pPublicKey : ��Ӧ�Ĺ�Կָ��
    * @param pszFile : ��Կ��Ӧ���ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL  LoadPublicKey(RSAKEY* pPublicKey, const CHAR* pszFile);

    /**
    * @brief ���ļ������빫Կ
    * @param pPrivateKey : ��Ӧ�Ĺ�Կָ��
    * @param pszFile : ��Կ��Ӧ���ļ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    BOOL  LoadPrivateKey(RSAKEY* pPrivateKey, const CHAR* pszFile);

	/**
    * @brief ���湫Կ���ڴ�
    * @param PublicKey : ��Ӧ�Ĺ�Կָ��
	* @param pbyKeyBuf : �ڴ�ĵ�ַ
    * @param wKeyLen : �ڴ�ĳ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    UINT16  SavePublicKeyToMem(const RSAKEY PublicKey, UINT8 *pbyKeyBuf, UINT16 wKeyLen);

    /**
    * @brief ����˽Կ���ڴ�
    * @param PrivateKey : ��Ӧ��˽Կָ��
	* @param pbyKeyBuf : �ڴ�ĵ�ַ
    * @param wKeyLen : �ڴ�ĳ���
    * @return �ɹ�����true��ʧ�ܷ���false
    */
    UINT16  SavePrivateKeyToMem(const RSAKEY PrivateKey, UINT8 *pbyKeyBuf, UINT16 wKeyLen);

    /**
    * @brief ���ڴ������빫Կ
    * @param PublicKey : ��Կָ��
    * @param pbyKeyBuf : �ڴ�ĵ�ַ
    * @param wKeyLen : �ڴ�ĳ���
    * @return VOID
    */
    VOID  LoadPublicKeyFromMem(RSAKEY PublicKey, UINT8 *pbyKeyBuf, UINT16 wKeyLen);

    /**
    * @brief ���ڴ�������˽Կ
    * @param PrivateKey : ˽Կָ��
    * @param pbyKeyBuf : �ڴ�ĵ�ַ
    * @param wKeyLen : �ڴ�ĳ���
    * @return VOID
    */
    VOID  LoadPrivateKeyFromMem(RSAKEY PrivateKey, UINT8 *pbyKeyBuf, UINT16 wKeyLen);

    /**
    * @brief �����ݽ��м���
    * @param PublicKey : �����õĹ�Կ
    * @param from : ��Ҫ���ܵĻ�������ַ
    * @param dwFromSize : ���ܻ���������
    * @param to : �������ݴ洢λ��
    * @return ���صļ��ܺ�ĳ���
    */
    UINT32  PubEncrypt(RSAKEY PublicKey, UINT8 *from, UINT32 dwFromSize, UINT8 *to);

    /**
    * @brief �����ݽ��н���
    * @param PrivateKey : �����õ�˽Կ
    * @param from : ��Ҫ���ܵĻ�������ַ
    * @param dwFromSize : ��Ҫ���ܵĻ���������
    * @param to : �������ݴ洢λ��
    * @return ���صĽ��ܺ�ĳ���
    */
    UINT32  PriDecrypt(RSAKEY PrivateKey, UINT8 *from, UINT32 dwFromSize, UINT8 *to);

	enum ERsaSign {
		NID_UNDEF = 0,
		NID_MD5 = 4,
		NID_SHA = 41,
		NID_SHA1 = 64,
		NID_MD5_SHA = 114,
	};

	/**
	* @brief ����Կ��ȡ��Ϣ��ǩ������Ҫע����ǣ�msglen��ò�Ҫ����100
    * @param PrivateKey : ǩ������Կ
	* @param msg : ��Ҫǩ�����ֽڴ�
	* @param msglen : �ֽڴ�����
	* @param sigret : [�����������]���ص�ǩ��
	* @param siglen : [�����������]���ص�ǩ������
    * @param type : ʹ��ժҪ���㷨
	* @return �Ƿ��ȡǩ���ɹ���TRUEΪ�ɹ���FALSEΪʧ��
	*/
	BOOL  PriSign(RSAKEY PrivateKey, const UCHAR *msg, UINT32 msglen, UCHAR *sigret, UINT32 *siglen, INT32 type = NID_MD5);

	/**
	* @brief �ù�Կ��֤ǩ������Ҫע����ǣ�msglen��ò�Ҫ����100
    * @param PublicKey : ��֤�Ĺ�Կ
	* @param msg : ��Ҫ��֤���ַ���
	* @param msglen : �ֽڴ�����
	* @param sigbuf : [�����������]���ص�ǩ��
	* @param siglen : [�����������]���ص�ǩ������
    * @param type : ʹ��ժҪ���㷨
	* @return �Ƿ���֤�ɹ���TRUEΪ�ɹ���FALSEΪʧ��
	*/
	BOOL  PubVerify(RSAKEY PublicKey, const UCHAR *msg, UINT32 msglen, UCHAR *sigbuf, UINT32 siglen, INT32 type = NID_MD5);

    /**
    * @brief �ͷŹ�Կ��Դ
    * @param pstPublicKey : ��Կָ��
    * @return VOID
    */
    VOID  FreePublicKey(RSAKEY* pPublicKey);

    /**
    * @brief �ͷ�˽Կ��Դ
    * @param pstPrivateKey : ˽Կָ��
    * @return VOID
    */
    VOID  FreePrivateKey(RSAKEY* pPrivateKey);


    /** @} */
}

#endif // #if SDU_WITH_OPENSSL

#endif


