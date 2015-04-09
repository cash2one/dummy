#ifndef SDRSA_H
#define SDRSA_H
/**
* @file sdrsa.h

* @brief ����RSA�����
*
**/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <time.h>
#include "sdtype.h"



namespace SGDP
{
    /**
    * @defgroup groupcrypto �ӽ��ܲ���
    * @ingroup  SGDP
    * @{
    */

#define SDCRYPTO_HAVE_ASM   /**<asm compiler supported flag*/

    /**
    *@brief RSA error code macros
    */
#define SDCRYPTO_ERR_RSA_BAD_INPUT_DATA       -0x0400
#define SDCRYPTO_ERR_RSA_INVALID_PADDING      -0x0410
#define SDCRYPTO_ERR_RSA_KEY_GEN_FAILED       -0x0420
#define SDCRYPTO_ERR_RSA_KEY_CHECK_FAILED     -0x0430
#define SDCRYPTO_ERR_RSA_PUBLIC_FAILED        -0x0440
#define SDCRYPTO_ERR_RSA_PRIVATE_FAILED       -0x0450
#define SDCRYPTO_ERR_RSA_VERIFY_FAILED        -0x0460

    /**
    *@brief PKCS#1 constants
    */
#define RSA_RAW         0
#define RSA_MD2         2
#define RSA_MD4         3
#define RSA_MD5         4
#define RSA_SHA1        5
#define RSA_SHA256      6

#define RSA_PUBLIC      0
#define RSA_PRIVATE     1

#define RSA_PKCS_V15    0
#define RSA_PKCS_V21    1

#define RSA_SIGN        1
#define RSA_CRYPT       2

    /**
    * @brief typedef Big Number structure
    * be used to hold big integer more than 100 bits
    * ��������ṹ��
    */
    typedef struct tagBigNum
    {
        INT32		s;			/**<signed flag*/
        UINT32		n;			/**<total limbs number*/
        UINT32*		p;			/**<pointer to limbs*/
    } BigNum;

    /**
    * @brief typedef RSA context structure
    * ����RSA�����Ľṹ��
    */
    typedef struct tagRSAContext
    {
        INT32 ver;				/**<always 0*/
        INT32 len;				/**<size(N) in chars*/
        BigNum N;				/**<public modulus*/
        BigNum E;				/**<public exponent*/
        BigNum D;				/**<private exponent*/
        BigNum P;				/**<1st prime factor*/
        BigNum Q;				/**<2nd prime factor*/
        BigNum DP;				/**<D % (P - 1)*/
        BigNum DQ;				/**<D % (Q - 1)*/
        BigNum QP;				/**<1 / (Q % P)*/
        BigNum RN;				/**<cached R^2 mod N*/
        BigNum RP;				/**<cached R^2 mod P*/
        BigNum RQ;				/**<cached R^2 mod Q*/
        INT32 padding;			/**<1.5 or OAEP/PSS*/
        INT32 hash_id;			/**<hash identifier*/
        INT32 (*f_rng)(VOID *);	/**<RNG function*/
        VOID *p_rng;			/**<RNG parameter*/
    } SRSAContext;

    /**
    *@brief rsa�ӽ��ܷ�װ��
    */
    class CSDRsa
    {
    public:

        /**
        * @brief
        * Initialize an RSA context ��ʼ��һ��RSA������
        * @param pCtx : RSA context to be initialized ��Ҫ����ʼ����RSA������
        * @return VOID
        */
        VOID  RSAContextInit( SRSAContext *pCtx );

        /**
        * @brief
        * Free the components of an RSA key �ͷ�һ��RSA������
        * @param pCtx : RSA context to be freed ��Ҫ���ͷŵ�RSA������
        * @return VOID
        */
        VOID  RSAContextFree( SRSAContext *pCtx );

        /**
        * @brief
        * Get the length of RSA ��ȡRSA�ĳ���
        * @param pCtx : RSA context �����RSA������
        * @return the length of RSA ����RSA�ĳ���
        */
        INT32  RSANSize( SRSAContext *pCtx );

        /**
        * @brief
        * Get a SDNew RSA context ��ȡһ���µ�RSA������
        * @return pointer of SDNew RSA context, return NULL if failed
        * ����һ���µ�RSA�����ĵ�ָ�룬�������NULL������ʧ��
        */
        SRSAContext*  RSANew();

        /**
        * @brief
        * Generate an RSA keypair ����һ��RSA��Կ��Կ��
        * @param pKeyPair : RSA context that will hold the key
        * ��Ҫ���д�RSA��Կ��Կ�Ե�RSA������
        * @param nNBits : size of the public key in bits
        * ��Կ��bitλ��
        * @param nExponent : public exponent ����ָ��
        * @return success return true, else false �ɹ�����true��ʧ�ܷ���false
        */
        BOOL  RSAGenKeyPair(SRSAContext *pKeyPair, INT32 nNBits = 1024, INT32 nExponent = 65537);

        /**
        * @brief
        * Get public key length ��ȡһ����Կ����
        * @param pPubKey : RSA context that hold the key
        * ���д�RSA��Կ��RSA������
        * @return the length of public key
        * ��RSA��Կ�ĳ���
        */
        INT32  RSAGetPubKeyLen(SRSAContext *pPubKey);

        /**
        * @brief
        * Get private key length ��ȡ��Կ�ĳ���
        * @param pPrivKey : RSA context that hold the key
        * ���д�RSA��Կ��RSA������
        * @return the length of private key
        * ��RSA��Կ�ĳ���
        */
        INT32  RSAGetPrivKeyLen(SRSAContext *pPrivKey);

        /**
        * @brief
        * Save public key to file �洢��Կ���ļ�
        * @param pPubKey : RSA context that hold the key
        * ���д�RSA��Կ��RSA������
        * @param pszFile : file name which save the public key
        * �洢���ļ�·��
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSASavePubKey(SRSAContext *pPubKey, const char *pszFile);

        /**
        * @brief
        * Save public key to memory �洢��Կ�����ڴ�
        * @param pPubKey : RSA context that hold the key
        * ���д�RSA��Կ��RSA������
        * @param pBuffer : buffer to save the key
        * �洢��RSA��Կ�Ļ�����
        * @param nBufLen : buffer length
        * �˻������ĳ���
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSASavePubKeyToMem(SRSAContext *pPubKey, UCHAR* pBuffer, INT32 nBufLen);

        /**
        * @brief
        * load public key from file ���ļ������빫Կ
        * @param pPubKey : RSA context that hold the key
        * ��Ҫ���д�RSA��Կ��RSA������
        * @param pszFile : file name which save the public key
        * ��Ҫ���빫Կ���ļ�·��
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSALoadPubKey(SRSAContext *&pPubKey, const char *pszFile);

        /**
        * @brief
        * load public key from memory ���ڴ������빫Կ
        * @param pPubKey : RSA context that will hold the key
        * ��Ҫ���д�RSA��Կ��RSA������
        * @param pBuffer : buffer to save the key
        * ��Ҫ���빫Կ�Ļ�����
        * @param nBufLen : buffer length ����������
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSALoadPubKeyFromMem(SRSAContext *&pPubKey, const UCHAR* pBuffer, INT32 nBufLen);

        /**
        * @brief
        * Save private key to file �洢��Կ���ļ�
        * @param pPrivKey : RSA context that will hold the key
        * ���д�RSA��Կ��RSA������
        * @param pszFile : file name which save the public key
        * �洢��Կ���ļ�·��
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSASavePrivKey(SRSAContext *pPrivKey, const char *pszFile);

        /**
        * @brief
        * Save private key to memory �洢��Կ�����ڴ�
        * @param pPrivKey : RSA context that will hold the key
        * ���д�RSA��Կ��RSA������
        * @param pBuffer : buffer to save the key
        * �洢��RSA��Կ�Ļ�����
        * @param nBufLen : buffer length
        * �˻������ĳ���
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSASavePrivKeyToMem(SRSAContext *pPrivKey, UCHAR* pBuffer, INT32 nBufLen);

        /**
        * @brief
        * load private key from file ���ļ���������Կ
        * @param pPrivKey : RSA context that will hold the key
        * ��Ҫ���д�RSA��Կ��RSA������
        * @param pszFile : file name which save the public key
        * ��Ҫ������Կ���ļ�·��
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSALoadPrivKey(SRSAContext *&pPrivKey, const char *pszFile);

        /**
        * @brief
        * load private key from memory ���ڴ���������Կ
        * @param pPrivKey : RSA context that will hold the key
        * ��Ҫ���д�RSA��Կ��RSA������
        * @param pBuffer : buffer to save the key
        * ��Ҫ������Կ�Ļ�����
        * @param nBufLen : buffer length
        * �˻������ĳ���
        * @return sucess return true, else false �Ƿ�ɹ���trueΪ�ɹ���falseΪʧ��
        */
        BOOL   RSALoadPrivKeyFromMem(SRSAContext *&pPrivKey, const UCHAR* pBuffer, INT32 nBufLen);

        /**
        * @brief
        * encrypt from public key �ӹ�Կ����
        * @param pPubKey : RSA context that will hold the key
        * ���д�RSA��Կ��RSA������
        * @param nInLen : input buffer size ���뻺�����Ĵ�С
        * @param pInput : input buffer ����Ļ�����
        * @param pOutput : output buffer ����Ļ�����
        * @return length of encrypt buffer ����ĳ���
        */
        INT32  RSAPubEncrypt(SRSAContext *pPubKey,
                                  INT32		  nInLen,
                                  UCHAR *pInput,
                                  UCHAR *pOutput);

        /**
        * @brief
        * decrypt from private key ����Կ����
        * @param pPrivKey : RSA context that will hold the key
        * ���д�RSA��Կ��RSA������
        * @param nInLen : input buffer size ���뻺�����Ĵ�С
        * @param pInput : input buffer ����Ļ�����
        * @param pOutput : output buffer ����Ļ�����
        * @return length of decrypt buffer ����ĳ���
        */
        INT32  RSAPrivDecrypt(SRSAContext *pPrivKey,
                                   INT32		  nInLen,
                                   UCHAR *pInput,
                                   UCHAR *pOutput);

    private:

        /**
        * @brief ��ȡ��Կ
        * @param pPubKey : ���д�RSA��Կ��RSA������
        * @param pBuf    : ����Ļ�����
        * @param nRet    : ������
        * @return TRUE:�ɹ���ȡ FALSE:���ִ���
        */
        BOOL RSAReadPubKeySub(SRSAContext* pPubKey, UCHAR* pBuf, INT32 nRet);

        /**
        * @brief ��ȡ��Կ
        * @param pPrivKey : ���д�RSA��Կ��RSA������
        * @param pBuf    : ����Ļ�����
        * @param nRet    : ������
        * @return TRUE:�ɹ���ȡ FALSE:���ִ���
        */
        BOOL RSAReadPrivKeySub(SRSAContext* pPrivKey, UCHAR* pBuf, INT32 nRet);

        /**
        * @brief д�빫Կ
        * @param pPubKey : ���д�RSA��Կ��RSA������
        * @param pBuf    : ����Ļ�����
        * @param nRet    : ������
        * @return TRUE:�ɹ�д�� FALSE:���ִ���
        */
        BOOL RSAWritePubKeySub(SRSAContext* pPubKey, UCHAR* pBuf, INT32 nRet);

        /**
        * @brief д����Կ
        * @param pPrivKey : ���д�RSA��Կ��RSA������
        * @param pBuf    : ����Ļ�����
        * @param nRet    : ������
        * @return TRUE:�ɹ�д�� FALSE:���ִ���
        */
        BOOL RSAWritePrivKeySub(SRSAContext* pPrivKey, UCHAR* pBuf, INT32 nRet);

        /**
        * @brief ��ȡ��Կ�ĳ���
        * @param pPubKey : ����RSA��Կ��RSA������
        * @return ��Կ�ĳ���
        */
        INT32 RSAGetPubKeyLenSub(SRSAContext *pPubKey);

        /**
        * @brief ��ȡ��Կ�ĳ���
        * @param pPrivKey : ����RSA��Կ��RSA������
        * @return ��Կ�ĳ���
        */
        INT32 RSAGetPrivKeyLenSub(SRSAContext *pPrivKey);
        //
    };


    /** @} */

}


#endif //SD_RSA_H


