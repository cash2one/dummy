///<------------------------------------------------------------------------------
//< @file:   rsa.cpp
//< @author: hongkunan
//< @date:   2014��1��7�� 11:21:22
//< @brief:  ���ļ�����openssl�е�rsa�⣬�汾Ϊopenssl 1.0.1e
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#include "rsa.h"


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <errno.h>
#include <string>
#include <string.h>
#include <stdio.h>

#include <openssl/rsa.h>
#include <openssl/pem.h>  
#include <openssl/ossl_typ.h>
#include <openssl/err.h>

using namespace std;

typedef unsigned char byte;
typedef int errno_t;

char err_buf[1024];
char rsa_err[1024] = "";
size_t err_len = sizeof(rsa_err);

byte encrypt_buf[1024] = "";
byte decrypt_buf[1024] = "";

byte buf[1024] = "";

void get_err(char buf[], const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
}

// ���openssl��rsa���߷�������Щ��������openssl��rsaģ��Դ�����������һЩС����
namespace openssl_rsa
{
    // ��������opensslԴ����crypto/pem/pem_all.c�е�162�п�������
    RSA *pkey_get_rsa(EVP_PKEY *key, RSA **rsa)
    {
        RSA *rtmp;
        if(!key) return NULL;
        rtmp = EVP_PKEY_get1_RSA(key);
        EVP_PKEY_free(key);
        if(!rtmp) return NULL;
        if(rsa) {
            RSA_free(*rsa);
            *rsa = rtmp;
        }
        return rtmp;
    }

    // ���ݸ����Ĺ�Կ��ȡRSA�ṹ
    // 
    // ��������opensslԴ����crypto/pem/pem_all.c�е�252��:
    //         IMPLEMENT_PEM_rw(RSA_PUBKEY, RSA, PEM_STRING_PUBLIC, RSA_PUBKEY)
    // �Ķ����޸Ķ������ɴ�pem�ļ���ȡ��Ϊ���ڴ��ж�ȡ
    RSA* get_rsa_from_public_key(const char* public_key)
    {
        RSA* rsa  = NULL;
        BIO *bio  = NULL;
        void *ret = NULL;

        if ((bio=BIO_new(BIO_s_mem())) == NULL)
        {
            PEMerr(PEM_F_PEM_ASN1_READ,ERR_R_BUF_LIB);
            return NULL;
        }

        BIO_puts(bio, public_key);

        ret=PEM_ASN1_read_bio((d2i_of_void *)d2i_RSA_PUBKEY,"PUBLIC KEY",bio,(void **)rsa,NULL, NULL);
        BIO_free(bio);

        return (RSA*)ret;
    }

    // ���ݸ�����˽Կ��ȡRSA�ṹ
    // 
    // ��������opensslԴ����crypto/pem/pem_all.c�е�186��:
    //         RSA *PEM_read_RSAPrivateKey(FILE *fp, RSA **rsa, pem_password_cb *cb, void *u)
    // �ĺ����޸Ķ������ɴ�pem�ļ���ȡ��Ϊ���ڴ��ж�ȡ
    RSA* get_rsa_from_private_key(const char* private_key)
    {
        RSA* rsa        = NULL;

        BIO *bio        = NULL;
        EVP_PKEY *pktmp = NULL;

        if ((bio=BIO_new(BIO_s_mem())) == NULL)
        {
            PEMerr(PEM_F_PEM_READ_PRIVATEKEY,ERR_R_BUF_LIB);
            return(0);
        }
        BIO_puts(bio, private_key);

        pktmp=PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
        BIO_free(bio);

        return pkey_get_rsa(pktmp, &rsa);
    }
}

namespace kuaiyong
{
    // �ѿ���ƽ̨�Ĺ�Կת����openssl֧�ֵĸ�ʽ�����ͷ�ļ��еĸ�ע
    std::string convert_public_key(const char public_key[], int len)
    {
        string key;

        int cnt = 0;
        for(int i = 0; i < len; i++)
        {
            if(cnt < 64)
            {
                key += public_key[i];
                ++cnt;
            }
            else
            {
                key += "\r\n";
                key += public_key[i];
                cnt = 1;
            }
        }

        key = "-----BEGIN PUBLIC KEY-----\r\n" + key;
        key += "\r\n-----END PUBLIC KEY-----\r\n";
        return key;
    }

    // �ѿ���ƽ̨��˽Կת����openssl֧�ֵĸ�ʽ�����ͷ�ļ��еĸ�ע
    std::string convert_private_key(const char public_key[], int len)
    {
        string key;

        int cnt = 0;
        for(int i = 0; i < len; i++)
        {
            if(cnt < 64)
            {
                key += public_key[i];
                ++cnt;
            }
            else
            {
                key += "\r\n";
                key += public_key[i];
                cnt = 1;
            }
        }

        key = "-----BEGIN RSA PRIVATE KEY-----\r\n" + key;
        key += "\r\n-----END RSA PRIVATE KEY-----\r\n";
        return key;
    }
}

// ���ù�Կ��������
char* public_key_decrypt(const char* encrypted_text, int encrypted_len, const char* pub_key, int *decrypt_len, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';

    // �ѹ�Կת����pem��ʽ
    string pub_key_pem = kuaiyong::convert_public_key(pub_key, strlen(pub_key));
    return public_key_decrypt_by_pem(encrypted_text, encrypted_len, pub_key_pem.c_str(), decrypt_len, err_msg);
}

// ���ù�Կpem��������
char* public_key_decrypt_by_pem(const char* encrypted_text, int encrypted_len, const char* pub_key_pem, int *decrypt_len, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';

    // ���ݹ�Կ��ȡrsa�ṹ
    RSA* rsa = openssl_rsa::get_rsa_from_public_key(pub_key_pem);
    if(NULL == rsa)
    {
        get_err(rsa_err, "fail: given public key is invalid: %s!\n", pub_key_pem);
        return NULL;
    }

    // �ù�Կ��������
    int len = RSA_public_decrypt(encrypted_len, (unsigned char*)encrypted_text, (unsigned char*)decrypt_buf, rsa, RSA_PKCS1_PADDING);
    if(-1 == len){
        get_err(rsa_err, "failed to decrypt! please recheck the decrypted text and the format of %s\n", pub_key_pem);
        return NULL;
    }

    decrypt_buf[len] = '\0';

    *decrypt_len = len;
    return (char*)decrypt_buf;
}

// ���ù�Կ�ļ���������
char* public_key_decrypt_from_file(const char* encrypted_text, int encrypted_len, const char* pub_key_file, int *decrypt_len, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';
    decrypt_buf[0] = '\0';

    // �򿪹�Կ�ļ�
    FILE* pub_fp = fopen(pub_key_file, "r");
	if(NULL == pub_fp)
	{
        get_err(rsa_err, "failed to open public key file %s: %s!\n", pub_key_file, strerror(errno));
        return NULL;
	}

    // ���ļ��ж�ȡ��Կ
    RSA* rsa = PEM_read_RSA_PUBKEY(pub_fp, NULL, NULL, NULL);
    if(NULL == rsa)
    {
        get_err(rsa_err, "fail: unable to read public key from %s!\n", pub_key_file);
        return NULL;
    }

    // �ù�Կ����
    int len = RSA_public_decrypt(encrypted_len, (unsigned char*)encrypted_text, (unsigned char*)decrypt_buf, rsa, RSA_PKCS1_PADDING);
    if(-1 == len){
        get_err(rsa_err, "failed to decrypt! please recheck the decrypted text and the format of %s\n", pub_key_file);
        return NULL;
    }

    fclose(pub_fp);

    decrypt_buf[len] = '\0';

    *decrypt_len = len;
    return (char*)decrypt_buf;
}

// ����˽Կ��������
char* private_key_encrypt(const char* plain_text, int plain_len, const char* pri_key, int *encrypt_len, char **err_msg)
{
    // ��˽Կ����ת��
    string pri_key_pem = kuaiyong::convert_private_key(pri_key, strlen(pri_key));
    return private_key_encrypt_pem(plain_text, plain_len, pri_key_pem.c_str(), encrypt_len, err_msg);
}

char* private_key_encrypt_pem(const char* plain_text, int plain_len, const char* pri_key_pem, int *encrypt_len, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';
    encrypt_buf[0] = '\0';
    *encrypt_len = 0;

    // ����˽Կ��ȡrsa�ṹ
    RSA* rsa = openssl_rsa::get_rsa_from_private_key(pri_key_pem);
    if(NULL == rsa)
    {
        get_err(rsa_err, "fail: given private key is invalid!\n");
        return NULL;
    }

    // ��rsa���ܵ����ĳ��Ȳ���̫��
    int rsa_size  = RSA_size(rsa);
    if(plain_len >= rsa_size - 41)
    {
        get_err(rsa_err, "failed to encrypt: length of plain text(= %d) is too long, must be less than rsa_size(=%d) - 41 = %d\n", plain_len, rsa_size, rsa_size - 41);
        return NULL;
    }

    // ��˽Կ����
    int len = RSA_private_encrypt(plain_len, (unsigned char*)plain_text, (unsigned char*)encrypt_buf, rsa, RSA_PKCS1_PADDING);
    if(-1 == len){
        get_err(rsa_err, "failed to encrypt! please recheck the plain text and the format of %s\n", pri_key_pem);
        return NULL;
    }

    encrypt_buf[len] = '\0';

    *encrypt_len = len;
    return (char*)encrypt_buf;
}

// ����˽Կ�ļ���������
char* private_key_encrypt_from_file(const char* plain_text, int plain_len, const char* pri_key_file, int *encrypt_len, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';

    // ��˽Կ�ļ�
    FILE* priv_fp = fopen(pri_key_file, "r");
	if(NULL == priv_fp)
	{
        get_err(rsa_err, "failed to open private key file %s: %s!\n", pri_key_file, strerror(errno));
        return NULL;
	}

    // ���ļ��ж�ȡ˽Կ
    RSA *rsa = PEM_read_RSAPrivateKey(priv_fp, NULL, NULL, NULL);
    if(NULL == rsa){
        get_err(rsa_err, "fail: unable to read private key from %s!\n", pri_key_file);
        return NULL; 
    }

    int rsa_size  = RSA_size(rsa);
    if(plain_len >= rsa_size - 41)
    {
        get_err(rsa_err, "failed to encrypt: length of plain text(= %d) is too long, must be less than rsa_size(=%d) - 41 = %d\n", plain_len, rsa_size, rsa_size - 41);
        return NULL;
    }

    // ��˽Կ����
    int len = RSA_private_encrypt(plain_len, (unsigned char*)plain_text, (unsigned char*)encrypt_buf, rsa, RSA_PKCS1_PADDING);
    if(-1 == len){
        get_err(rsa_err, "failed to encrypt! please recheck the plain text and the format of %s\n", pri_key_file);
        return NULL;
    }

    fclose(priv_fp);

    encrypt_buf[len] = '\0';

    *encrypt_len = len;
    return (char*)encrypt_buf;
}

// ����˽Կ����rsaǩ��������SHA1�㷨��������ǩ��
char* private_key_sign(const char* plain_text, int plain_len, const char* pri_key, unsigned int *sign_len, char **err_msg)
{
    // ��˽Կ����ת��
    string pri_key_pem = kuaiyong::convert_private_key(pri_key, strlen(pri_key));
    return private_key_sign_pem(plain_text, plain_len, pri_key_pem.c_str(), sign_len, err_msg);
}

// ����˽Կpem����rsaǩ��������SHA1�㷨��������ǩ��
char* private_key_sign_pem(const char* plain_text, int plain_len, const char* pri_key_pem, unsigned int *sign_len, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';
    encrypt_buf[0] = '\0';
    *sign_len = 0;

    // ����˽Կ��ȡrsa�ṹ
    RSA* rsa = openssl_rsa::get_rsa_from_private_key(pri_key_pem);
    if(NULL == rsa)
    {
        get_err(rsa_err, "fail: given private key is invalid!\n");
        return NULL;
    }

    // �ȶ�������sha1ժҪ
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, plain_text, plain_len);
    SHA1_Final(buf, &ctx);

    // ����RSA��sha1ժҪ����ǩ��
    int ret = RSA_sign(NID_sha1, (unsigned char*)buf, SHA_DIGEST_LENGTH, encrypt_buf, sign_len, rsa);
    if(ret != 1)
    {
        get_err(rsa_err, "fail: can not sign with given private key!\n");
        return NULL;
    }

	encrypt_buf[*sign_len] = '\0';
    return (char*)encrypt_buf;
}

// ���ù�Կ����rsa��ǩ(����SHA1�㷨)����������֤�������֤ͨ��true/��֤ʧ��false
bool public_key_verify(const char* plain_text, int plain_len, const char* sign_text, int sign_len, const char* pub_key, char **err_msg)
{
    // �Թ�Կ����ת��
    string pub_key_pem = kuaiyong::convert_public_key(pub_key, strlen(pub_key));
    return public_key_verify_pem(plain_text, plain_len, sign_text, sign_len, pub_key_pem.c_str(), err_msg);
}

// ���ù�Կpem����rsa��ǩ(����SHA1�㷨)����������֤�������֤ͨ��true/��֤ʧ��false
bool public_key_verify_pem(const char* plain_text, int plain_len, const char* sign_text, int sign_len, const char* pub_key_pem, char **err_msg)
{
    *err_msg = rsa_err;
    rsa_err[0] = '\0';

    // ���ݹ�Կ��ȡrsa�ṹ
    RSA* rsa = openssl_rsa::get_rsa_from_public_key(pub_key_pem);
    if(NULL == rsa)
    {
        get_err(rsa_err, "fail: given public key is invalid: %s!\n", pub_key_pem);
        return NULL;
    }

    // �ȶ�������sha1ժҪ
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, plain_text, plain_len);
    SHA1_Final(buf, &ctx);

    // ����RSA��sha1ժҪ������ǩ
    int ret = RSA_verify(NID_sha1, (unsigned char*)buf, SHA_DIGEST_LENGTH, (unsigned char*)sign_text, sign_len, rsa);
    return (ret == 1);
}
