///<------------------------------------------------------------------------------
//< @file:   rsa.h
//< @author: hongkunan
//< @date:   2014��1��7�� 11:21:8
//< @brief:  ��Կ���ƽ̨��rsa����������������ƽ̨���ܲ����ã����磬����ƽ̨���ܲ���pkcs#1����pkcs#8���ӽ��ܣ���֤ǩ��ʱ���ܲ���sha1/sha/md5��ǩ���㷨����
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _rsa_h_
#define _rsa_h_

/****************rsa���ܽ���************************************************/

/**
  * ���ù�Կ��������
  * @encrypted_text : ����
  * @encrypted_len  : ���ĳ���
  * @pub_key        : ��Կ�������Կ����û�пշ��źͻ��з��ģ�����: 
  *                       MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC+WNnrVVHQEcE3VwiuOPdAMZ5NGgs4Dikn6vd+XTURtAwn/86jd7En86F4s61pq7zjABNsVka8lpeq0Dq9XbXOQAPHJBt4PyEKA9EJ9XMeGF63UeJYPmN5VgrGtLJdPoFLY5AdTiNf3v6+CHyIoDs0NWsw3OSbostMbgwm7Z5A+wIDAQAB
  * @decrypt_len    : ���ؽ��ܽ���ĳ��ȣ�����ʧ��Ϊ0
  * @err_msg        : ʧ��ʱ���صĴ�����Ϣ
  * @return         �����ؽ��ܺ�����ģ�����ʧ�ܷ���NULL
  */
char* public_key_decrypt(const char* encrypted_text, int encrypted_len, const char* pub_key, int *decrypt_len, char **err_msg);

/**
  * ���ù�Կpem��������
  * @encrypted_text : ����
  * @encrypted_len  : ���ĳ���
  * @pub_key_pem    : ��Կ�������Կ�������openssl֧�ֵ�pem��ʽ������: 
  *                       -----BEGIN PUBLIC KEY-----      
  *                       MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC+WNnrVVHQEcE3VwiuOPdAMZ5N      
  *                       Ggs4Dikn6vd+XTURtAwn/86jd7En86F4s61pq7zjABNsVka8lpeq0Dq9XbXOQAPH      
  *                       JBt4PyEKA9EJ9XMeGF63UeJYPmN5VgrGtLJdPoFLY5AdTiNf3v6+CHyIoDs0NWsw      
  *                       3OSbostMbgwm7Z5A+wIDAQAB      
  *                       -----END PUBLIC KEY-----      
  * @decrypt_len    : ���ؽ��ܽ���ĳ��ȣ�����ʧ��Ϊ0
  * @err_msg        : ʧ��ʱ���صĴ�����Ϣ
  * @return         �����ؽ��ܺ�����ģ�����ʧ�ܷ���NULL
  */
char* public_key_decrypt_by_pem(const char* encrypted_text, int encrypted_len, const char* pub_key_pem, int *decrypt_len, char **err_msg);

/**
  * ���ù�Կ�ļ���������
  * @encrypted_text : ����
  * @encrypted_len  : ���ĳ���
  * @pub_key        : ��Ź�Կ���ļ���ַ����:"publickey.pem"���ļ����ŵ���pem��ʽ�Ĺ�Կ
  * @decrypt_len    : ���ؽ��ܽ���ĳ��ȣ�����ʧ��Ϊ0
  * @err_msg        : ʧ��ʱ���صĴ�����Ϣ
  * @return         �����ؽ��ܺ�����ģ�����ʧ�ܷ���NULL
  */
char* public_key_decrypt_from_file(const char* encrypted_text, int encrypted_len, const char* pub_key_file, int *decrypt_len, char **err_msg);

/**
  * ����˽Կ��������
  * @plain_text  : ����
  * @plain_len   : ���ĳ���
  * @pri_key     : ˽Կ�����˽Կ��û�пշ��źͻ��з��ģ����磺
  *                    MIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAL5Y2etVUdARwTdXCK4490Axnk0aCzgOKSfq935dNRG0DCf/zqN3sSfzoXizrWmrvOMAE2xWRryWl6rQOr1dtc5AA8ckG3g/IQoD0Qn1cx4YXrdR4lg+Y3lWCsa0sl0+gUtjkB1OI1/e/r4IfIigOzQ1azDc5Juiy0xuDCbtnkD7AgMBAAECgYEAjuu39HODkm9CXIMFCYvMWm7nJY1Ajz5SuJ48Zq0lg71kw0PXq/XbFtxfiXmf45AHq4oLC3Vcd427I45mDHmoX4ApaaKozk/+QOGdBuM1mattfqX2D/MDqbUNa2yVo1lN9/4KtWf9+vKIusL70+iYTOuNAw946M/9cN9qBxZfkcECQQDvcz5ncjfLA9fsqYwhHtAWf7+5RuUifZyJn4fvgpqjGth5qP+1zzE+xo+5mQA79w+8iXpz0CIx+zMR+MtgUxotAkEAy4DK7pdvBXdhSZDpFLuJZINPj60baV/IRsi4NG3l59kPwXn41MizY3pT9EqBKySGVzOgXtzT9TZ6WVBLxrGIxwJAbmnpwLG+YHLpQkv8PdmDgpxtv/Wc+waJBDz35c2HmOZsI811/FQKFTRiWebfYMdQDlQmjvjOi9WVexgKT+SCEQJBAItIOBx6qvLr1Ttbohudi5iuwuqMSWGiu9mukVzZBuzbRIxgZe2E/DqOxB1ETQnxMr1GSXID5FJFmhG9AlAYvIsCQQDEVQ1hO9q2nOeAkD5w6ly3G72uI1jBduzRLyCLUte+QmNKA+0b2LoIyCzgZk9ghlIU3m86TLpVNxGEyha4uLId
  * @encrypt_len : ���ؼ��ܽ���ĳ��ȣ�����ʧ��Ϊ0
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      �����ؼ��ܺ�����ģ�����ʧ�ܷ���NULL
  */
char* private_key_encrypt(const char* plain_text, int plain_len, const char* pri_key, int *encrypt_len, char **err_msg);

/**
  * ����˽Կpem��������
  * @plain_text  : ����
  * @plain_len   : ���ĳ���
  * @pri_key_pem : ˽Կ�����˽Կ�������openssl֧�ֵ�pem��ʽ������: 
  *                    -----BEGIN RSA PRIVATE KEY-----
  *                    MIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAL5Y2etVUdARwTdX
  *                    CK4490Axnk0aCzgOKSfq935dNRG0DCf/zqN3sSfzoXizrWmrvOMAE2xWRryWl6rQ
  *                    Or1dtc5AA8ckG3g/IQoD0Qn1cx4YXrdR4lg+Y3lWCsa0sl0+gUtjkB1OI1/e/r4I
  *                    fIigOzQ1azDc5Juiy0xuDCbtnkD7AgMBAAECgYEAjuu39HODkm9CXIMFCYvMWm7n
  *                    JY1Ajz5SuJ48Zq0lg71kw0PXq/XbFtxfiXmf45AHq4oLC3Vcd427I45mDHmoX4Ap
  *                    aaKozk/+QOGdBuM1mattfqX2D/MDqbUNa2yVo1lN9/4KtWf9+vKIusL70+iYTOuN
  *                    Aw946M/9cN9qBxZfkcECQQDvcz5ncjfLA9fsqYwhHtAWf7+5RuUifZyJn4fvgpqj
  *                    Gth5qP+1zzE+xo+5mQA79w+8iXpz0CIx+zMR+MtgUxotAkEAy4DK7pdvBXdhSZDp
  *                    FLuJZINPj60baV/IRsi4NG3l59kPwXn41MizY3pT9EqBKySGVzOgXtzT9TZ6WVBL
  *                    xrGIxwJAbmnpwLG+YHLpQkv8PdmDgpxtv/Wc+waJBDz35c2HmOZsI811/FQKFTRi
  *                    WebfYMdQDlQmjvjOi9WVexgKT+SCEQJBAItIOBx6qvLr1Ttbohudi5iuwuqMSWGi
  *                    u9mukVzZBuzbRIxgZe2E/DqOxB1ETQnxMr1GSXID5FJFmhG9AlAYvIsCQQDEVQ1h
  *                    O9q2nOeAkD5w6ly3G72uI1jBduzRLyCLUte+QmNKA+0b2LoIyCzgZk9ghlIU3m86
  *                    TLpVNxGEyha4uLId
  *                    -----END RSA PRIVATE KEY-----   
  * @encrypt_len : ���ؼ��ܽ���ĳ��ȣ�����ʧ��Ϊ0
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      �����ؼ��ܺ�����ģ�����ʧ�ܷ���NULL
  */
char* private_key_encrypt_pem(const char* plain_text, int plain_len, const char* pri_key_pem, int *encrypt_len, char **err_msg);


/**
  * ����˽Կ�ļ���������
  * @plain_text  : ����
  * @plain_len   : ���ĳ���
  * @pri_key     : ���˽Կ���ļ���ַ����:"privatekey.pem"���ļ����ŵ���pem��ʽ��˽Կ
  * @encrypt_len : ���ؼ��ܽ���ĳ��ȣ�����ʧ��Ϊ0
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      �����ؼ��ܺ�����ģ�����ʧ�ܷ���NULL
  */
char* private_key_encrypt_from_file(const char* plain_text, int plain_len, const char* pri_key_file, int *encrypt_len, char **err_msg);

/****************rsa���ܽ���************************************************/


/****************rsa��ǩ************************/

/**
  * ����˽Կ����rsaǩ��������SHA1�㷨��������ǩ��
  * @plain_text: ����
  * @plain_len : ���ĳ���
  * @pri_key   : ˽Կ�����˽Կ��û�пշ��źͻ��з��ģ����磺
  *                    MIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAL5Y2etVUdARwTdXCK4490Axnk0aCzgOKSfq935dNRG0DCf/zqN3sSfzoXizrWmrvOMAE2xWRryWl6rQOr1dtc5AA8ckG3g/IQoD0Qn1cx4YXrdR4lg+Y3lWCsa0sl0+gUtjkB1OI1/e/r4IfIigOzQ1azDc5Juiy0xuDCbtnkD7AgMBAAECgYEAjuu39HODkm9CXIMFCYvMWm7nJY1Ajz5SuJ48Zq0lg71kw0PXq/XbFtxfiXmf45AHq4oLC3Vcd427I45mDHmoX4ApaaKozk/+QOGdBuM1mattfqX2D/MDqbUNa2yVo1lN9/4KtWf9+vKIusL70+iYTOuNAw946M/9cN9qBxZfkcECQQDvcz5ncjfLA9fsqYwhHtAWf7+5RuUifZyJn4fvgpqjGth5qP+1zzE+xo+5mQA79w+8iXpz0CIx+zMR+MtgUxotAkEAy4DK7pdvBXdhSZDpFLuJZINPj60baV/IRsi4NG3l59kPwXn41MizY3pT9EqBKySGVzOgXtzT9TZ6WVBLxrGIxwJAbmnpwLG+YHLpQkv8PdmDgpxtv/Wc+waJBDz35c2HmOZsI811/FQKFTRiWebfYMdQDlQmjvjOi9WVexgKT+SCEQJBAItIOBx6qvLr1Ttbohudi5iuwuqMSWGiu9mukVzZBuzbRIxgZe2E/DqOxB1ETQnxMr1GSXID5FJFmhG9AlAYvIsCQQDEVQ1hO9q2nOeAkD5w6ly3G72uI1jBduzRLyCLUte+QmNKA+0b2LoIyCzgZk9ghlIU3m86TLpVNxGEyha4uLId
  * @sign_len  : ���ص�ǩ�����ȣ�ʧ�ܷ���0
  * @err_msg   : ʧ��ʱ���صĴ�����Ϣ
  * @return    : ����ǩ����ʧ�ܷ���NULL
  */
char* private_key_sign(const char* plain_text, int plain_len, const char* pri_key, unsigned int *sign_len, char **err_msg);

/**
  * ����˽Կpem����rsaǩ��������SHA1�㷨��������ǩ��
  * @plain_text  : ����
  * @plain_len   : ���ĳ���
  * @pri_key_pem : ˽Կ�����˽Կ�������openssl֧�ֵ�pem��ʽ������: 
  *                    -----BEGIN RSA PRIVATE KEY-----
  *                    MIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAL5Y2etVUdARwTdX
  *                    CK4490Axnk0aCzgOKSfq935dNRG0DCf/zqN3sSfzoXizrWmrvOMAE2xWRryWl6rQ
  *                    Or1dtc5AA8ckG3g/IQoD0Qn1cx4YXrdR4lg+Y3lWCsa0sl0+gUtjkB1OI1/e/r4I
  *                    fIigOzQ1azDc5Juiy0xuDCbtnkD7AgMBAAECgYEAjuu39HODkm9CXIMFCYvMWm7n
  *                    JY1Ajz5SuJ48Zq0lg71kw0PXq/XbFtxfiXmf45AHq4oLC3Vcd427I45mDHmoX4Ap
  *                    aaKozk/+QOGdBuM1mattfqX2D/MDqbUNa2yVo1lN9/4KtWf9+vKIusL70+iYTOuN
  *                    Aw946M/9cN9qBxZfkcECQQDvcz5ncjfLA9fsqYwhHtAWf7+5RuUifZyJn4fvgpqj
  *                    Gth5qP+1zzE+xo+5mQA79w+8iXpz0CIx+zMR+MtgUxotAkEAy4DK7pdvBXdhSZDp
  *                    FLuJZINPj60baV/IRsi4NG3l59kPwXn41MizY3pT9EqBKySGVzOgXtzT9TZ6WVBL
  *                    xrGIxwJAbmnpwLG+YHLpQkv8PdmDgpxtv/Wc+waJBDz35c2HmOZsI811/FQKFTRi
  *                    WebfYMdQDlQmjvjOi9WVexgKT+SCEQJBAItIOBx6qvLr1Ttbohudi5iuwuqMSWGi
  *                    u9mukVzZBuzbRIxgZe2E/DqOxB1ETQnxMr1GSXID5FJFmhG9AlAYvIsCQQDEVQ1h
  *                    O9q2nOeAkD5w6ly3G72uI1jBduzRLyCLUte+QmNKA+0b2LoIyCzgZk9ghlIU3m86
  *                    TLpVNxGEyha4uLId
  *                    -----END RSA PRIVATE KEY-----
  * @sign_len    : ���ص�ǩ�����ȣ�ʧ�ܷ���0
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      : ����ǩ����ʧ�ܷ���NULL
  */
char* private_key_sign_pem(const char* plain_text, int plain_len, const char* pri_key_pem, unsigned int *sign_len, char **err_msg);

/**
  * ���ù�Կ����rsa��ǩ(����SHA1�㷨)����������֤�������֤ͨ��true/��֤ʧ��false
  * @plain_text: ����
  * @plain_len : ���ĳ���
  * @sign_text : ǩ��
  * @sign_len  : ǩ������
  * @pub_key   : ��Կ�������Կ��û�пշ��źͻ��з��ģ�����: 
  *                       MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC+WNnrVVHQEcE3VwiuOPdAMZ5NGgs4Dikn6vd+XTURtAwn/86jd7En86F4s61pq7zjABNsVka8lpeq0Dq9XbXOQAPHJBt4PyEKA9EJ9XMeGF63UeJYPmN5VgrGtLJdPoFLY5AdTiNf3v6+CHyIoDs0NWsw3OSbostMbgwm7Z5A+wIDAQAB
  * @err_msg   : ʧ��ʱ���صĴ�����Ϣ
  * @return    ��������֤�������֤ͨ��true/��֤ʧ��false
  */
bool public_key_verify(const char* plain_text, int plain_len, const char* sign_text, int sign_len, const char* pub_key, char **err_msg);

/**
  * ���ù�Կpem����rsa��ǩ(����SHA1�㷨)����������֤�������֤ͨ��true/��֤ʧ��false
  * @plain_text  : ����
  * @plain_len   : ���ĳ���
  * @sign_text   : ǩ��
  * @sign_len    : ǩ������
  * @pub_key_pem : ��Կ�������Կ�������openssl֧�ֵ�pem��ʽ������: 
  *                    -----BEGIN PUBLIC KEY-----      
  *                    MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC+WNnrVVHQEcE3VwiuOPdAMZ5N      
  *                    Ggs4Dikn6vd+XTURtAwn/86jd7En86F4s61pq7zjABNsVka8lpeq0Dq9XbXOQAPH      
  *                    JBt4PyEKA9EJ9XMeGF63UeJYPmN5VgrGtLJdPoFLY5AdTiNf3v6+CHyIoDs0NWsw      
  *                    3OSbostMbgwm7Z5A+wIDAQAB      
  *                    -----END PUBLIC KEY-----      
  * @err_msg     : ʧ��ʱ���صĴ�����Ϣ
  * @return      ��������֤�������֤ͨ��true/��֤ʧ��false
  */
bool public_key_verify_pem(const char* plain_text, int plain_len, const char* sign_text, int sign_len, const char* pub_key_pem, char **err_msg);

/****************rsa��ǩ************************/


/* 
��ע��

ͨ����������ƽ̨�ṩ�Ĺ�Կ��˽Կ���������Դ��µ�֪������ƽ̨��ͨ��openssl����rsa��Կ�ģ����������ǻ�ȡ���Ĺ�Կ������ƽ̨����ת�������ԣ�����÷���ת����ԿΪopenssl֧�ֵĸ�ʽ

1. ����ת����Կ

    ����ƽ̨���ṩ�Ĺ�Կ��
        MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC+WNnrVVHQEcE3VwiuOPdAMZ5NGgs4Dikn6vd+XTURtAwn/86jd7En86F4s61pq7zjABNsVka8lpeq0Dq9XbXOQAPHJBt4PyEKA9EJ9XMeGF63UeJYPmN5VgrGtLJdPoFLY5AdTiNf3v6+CHyIoDs0NWsw3OSbostMbgwm7Z5A+wIDAQAB;

    ������openssl��ʽ�Ĺ�Կһ���������ģ������Լ���openssl�������ɶ��գ���
        -----BEGIN PUBLIC KEY-----
        MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC+WNnrVVHQEcE3VwiuOPdAMZ5N
        Ggs4Dikn6vd+XTURtAwn/86jd7En86F4s61pq7zjABNsVka8lpeq0Dq9XbXOQAPH
        JBt4PyEKA9EJ9XMeGF63UeJYPmN5VgrGtLJdPoFLY5AdTiNf3v6+CHyIoDs0NWsw
        3OSbostMbgwm7Z5A+wIDAQAB
        -----END PUBLIC KEY-----

    ���ԣ�Ӧ�Կ���ƽ̨�Ĵ����Ĺ�Կ�������´���
    1. ÿ��64���ַ�����\r\n
    2. ͷ������-----BEGIN PUBLIC KEY-----\r\n
    3. β������\r\n-----END PUBLIC KEY-----\r\n

2. ����˽Կ������������ò���˽Կ�ģ�������Ҳһ���г�˽Կ������ݣ�

    ����ƽ̨�Ǳߵ�˽ԿӦ����������ӵģ�
        -----BEGIN RSA PRIVATE KEY-----
        MIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAL5Y2etVUdARwTdX
        CK4490Axnk0aCzgOKSfq935dNRG0DCf/zqN3sSfzoXizrWmrvOMAE2xWRryWl6rQ
        Or1dtc5AA8ckG3g/IQoD0Qn1cx4YXrdR4lg+Y3lWCsa0sl0+gUtjkB1OI1/e/r4I
        fIigOzQ1azDc5Juiy0xuDCbtnkD7AgMBAAECgYEAjuu39HODkm9CXIMFCYvMWm7n
        JY1Ajz5SuJ48Zq0lg71kw0PXq/XbFtxfiXmf45AHq4oLC3Vcd427I45mDHmoX4Ap
        aaKozk/+QOGdBuM1mattfqX2D/MDqbUNa2yVo1lN9/4KtWf9+vKIusL70+iYTOuN
        Aw946M/9cN9qBxZfkcECQQDvcz5ncjfLA9fsqYwhHtAWf7+5RuUifZyJn4fvgpqj
        Gth5qP+1zzE+xo+5mQA79w+8iXpz0CIx+zMR+MtgUxotAkEAy4DK7pdvBXdhSZDp
        FLuJZINPj60baV/IRsi4NG3l59kPwXn41MizY3pT9EqBKySGVzOgXtzT9TZ6WVBL
        xrGIxwJAbmnpwLG+YHLpQkv8PdmDgpxtv/Wc+waJBDz35c2HmOZsI811/FQKFTRi
        WebfYMdQDlQmjvjOi9WVexgKT+SCEQJBAItIOBx6qvLr1Ttbohudi5iuwuqMSWGi
        u9mukVzZBuzbRIxgZe2E/DqOxB1ETQnxMr1GSXID5FJFmhG9AlAYvIsCQQDEVQ1h
        O9q2nOeAkD5w6ly3G72uI1jBduzRLyCLUte+QmNKA+0b2LoIyCzgZk9ghlIU3m86
        TLpVNxGEyha4uLId
        -----END RSA PRIVATE KEY-----    

*/

#endif //_rsa_h_