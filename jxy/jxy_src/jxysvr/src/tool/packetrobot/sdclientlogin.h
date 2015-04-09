
#ifndef _SDCLIENTLOGIN_H_
#define _SDCLIENTLOGIN_H_

/**
 * @file �ͻ��˵�¼ģ��
 *
 * @author �������ķ��������沿
 */
#include <sdtype.h>

/**
 * @brief PT��֤��¼
 * @param pUserName �ʺ�
 * @param pPassword ����
 * @param pNet ���Ļ�������ַ
 * @param iNetSize ���Ļ�������С
 * @return �ɹ����ص�¼���Ĵ�С��ʧ�ܷ��ظ���
 */
INT32 PTLogin(CHAR* pUserName, CHAR* pPassword, CHAR* pNet, INT32 iNetSize);

/**
 * @brief Э�����
 * @param iMsgID Э����
 * @param pHost �����������
 * @param pNet ����������
 * @param iNetSize �������������
 * @return ���ر��������ݳ���
 */
INT32 Encode(INT32 iMsgID, CHAR* pHost, CHAR* pNet, INT32 iNetSize);

/**
 * @brief Э�����
 * @param iMsgID Э����
 * @param pHost �����������
 * @param pNet ����������
 * @param iNetSize �������������
 * @return ���ر��������ݳ���
 */
INT32 Decode(INT32 iMsgID, CHAR* pNet, INT32 iNetSize, CHAR* pHost, INT32 iHostSize);

/**
 * @brief ��ȡ�������ݳ���
 * @param pBuf ���Ļ�������ַ
 * @return �������ݴ�С�����󷵻�-1
 */
INT32 GetDataLength(CHAR *pBuf);

/**
 * @brief ��ȡ����Э���
 * @param pBuf ���Ļ�������ַ
 * @return ����Э��ţ����󷵻�-1
 */
INT32 GetMsgID(CHAR *pBuf);

/**
 * @brief ��ȡ����ͷ����
 * @return ����ͷ����
 */
INT32 GetHeaderLen();

#endif // #ifndef _SDCLIENTLOGIN_H_

