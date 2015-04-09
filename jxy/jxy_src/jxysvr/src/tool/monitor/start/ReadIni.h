/**
 * @file ReadIni.h
 * 
 * ��ȡini�ļ���������
 * �����ļ����ݸ�ʽ
 * [����]
 * [��������] = ����ֵ
 * 
 * @author 
 * @version 1.0
 * @date 
 * @bug �½�����bug
 * @bug ��Ԫ���ԣ�δ����bug
 * @warning δ���쳣������ԣ�ʹ��ʱ��ע�����
 */

#ifndef __READINI_H__
#define __READINI_H__

#include <string>
#include <iostream>
#include <fcntl.h>

#define LINEMAXCHARS 1000
#define MAX_ITEM_NAME_LEN 64
#define FILEMAXCHARS 40000

/**
 * @brief CReadIni
 *
 * ���ڶ�ȡini�����ļ�����
 * 
 */
class CReadIni
{
public:
    /**
     * @brief ���죬Ҫ������pszFileName!=NULL��ini�ļ���ַ
     * 
     * @param pszFileName [in] 
     * @return 
     * @retval 
     */
    CReadIni(const char *pszFileName);
    /**
     * @brief ���������ڹرմ򿪵�ini�ļ�
     * 
     * @param
     * @return 
     * @retval 
     */
    virtual ~CReadIni();
    /**
     * @brief ��ȡ�ַ���
     * 
     * ���ڶ�ȡini�ļ��ж�Ӧ�Ķ���Ϊ[pszSection]��������[pszIdent]��Ӧ�Ĳ����������pszItem
     * 
     * @param pszSection [in] ����
     * @param pszIdent [in] ����������
     * @param pszDefStr [in] Ĭ��ֵ
     * @param pszItem [out] ����ֵ
     * @return char*
     * @retval pszItem �ɹ�
     * @retval NULL ʧ��
     */
    char* ReadString (const char *pszSection, const char *pszIdent, char *pszItem, const char *pszDefStr );
    /**
     * @brief ��ȡ��ֵ����
     * 
     * �ȵ�����ReadString��ȡ�������ַ���ֵ��Ȼ������ת����
     * 
     * @param pszSection [in] ����
     * @param pszIdent [in] ����������
     * @param nDefint [in] Ĭ��ֵ
     * @return int
     * @retval ini�ļ���Ӧ�����Ͳ������͵Ĳ���ֵ
     * @retval nDefint
     */
    int ReadInteger(const char *pszSection, const char *pszIdent, const int nDefint );
    /**
     * @brief д��������
     * 
     * ��ini�ļ��еĶ�[pszSection]��������[pszIdent]д���Ӧֵ[pszItem]
     * 
     * @param pszSection [in] ����
     * @param pszIdent [in] ����������
     * @param pszItem [in] ����ֵ
     * @return int
     * @retval 0 �ɹ�
     * @retval ����ʧ��
     */
    int WriteString(const char *pszSection, const char *pszIdent, char *pszItem);
    /**
     * @brief ����ļ����Ƿ���ڸò�����
     * 
     * @param pszSection [in] ����
     * @return bool
     * @retval true ����
     * @retval false ������
     */
    bool SectionCheck(const char *pszSection);
    
    /**
     * @brief ��ȡ������Ϣ
     * 
     * @param  [in] 
     * @param  [out]
     * @return char*
     * @retval m_pszLastError
     */
    char* GetLastError();
private:
    /**
     * @brief ��ʼ������
     * 
     * @param  [in] 
     * @param  [out]
     * @return int
     * @retval 0 �ɹ�
     * @retval ����ʧ��
     */
    int Init();
    /**
     * @brief �ַ�������
     * 
     * ��pszStrSrc�ĳ���nLen�ַ����Ƶ�pszStrDest��
     * 
     * @param pszStrSrc [in] 
     * @param nLen [in] 
     * @param pszStrDest [out]
     * @return char*
     * @retval pszStrDest
     */
    char *TruncStr( char *pszStrSrc , char *pszStrDest , int nLen);
    /**
     * @brief ��ʽ���ַ���
     * 
     * �����ַ������ӵ�һ���ǿո���Ʊ����ʼ������м�ո���Ʊ������ֹͣ�����������ַ�����ֹ���ء�
     * 
     * @param pszStr [in/out] 
     * @return char*
     * @retval pszStr
     * @retval NULl
     */
    char *Trim( char *pszStr );
    /**
     * @brief ��cext����ַ����ұ�
     * 
     * ���ַ���pszStr���Ҳ����cExt�ַ���ʹ�ַ������ȴﵽnLen��
     * 
     * @param pszStr [in/out] �ַ��� 
     * @param cExt [in] �滻�ַ�
     * @param nLen [in] �ַ����滻��ĳ���
     * @return char*
     * @retval pszStr
     */
    char* RightPad( char *pszStr , char cExt , int nLen);

    FILE *m_fd;///<ini�ļ�ָ��

    bool m_bIsInit;///<�ļ��Ƿ��ʼ��

    char* m_pszFileName;///<�ļ�����ַָ��

    std::string m_strFileName;///<�ļ���

    char* m_pszLastError;///<������Ϣ
};

#endif///<__READINI_H__

