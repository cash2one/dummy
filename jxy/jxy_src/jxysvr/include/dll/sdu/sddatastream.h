/******************************************************************************
	sdnetdata.h - ���紫�����ݷ�װ��ʵ��

******************************************************************************/

#ifndef SDNETDATA_H
#define SDNETDATA_H
/**
* @file sdnetdata.h

* @brief ��������ת��ϵ��
*
**/
#include <stdio.h>
#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup groupnetdata ���紫���װ
    * @ingroup  SGDP
    * @{
    */

    /**
    *@brief ���紫�����ݷ�װ��ʵ��
    */
    class CSDDataStream
    {
    public:
        CSDDataStream();
        virtual ~CSDDataStream();

        /**
        * @brief
        * ��ʼ��net data
        * @param pszBuf : ��������buffer
        * @param dwBufLen : buffer�ĳ���
        * @return VOID
        */
        VOID  Prepare(CHAR *pszBuf, INT32 dwBufLen);

        /**
        * @brief
        * ������������
        * @return VOID
        */
        VOID  Reset();

        /**
        * @brief
        * �õ���װ�õ����ݻ�����
        * @return ��װ�õ����ݻ�����ָ��
        */
        inline CHAR*  GetData()
        {
            return m_pBuf;
        }

        /**
        * @brief
        * �õ���װ�õ����ݻ���������
        * @return ��װ�õ����ݻ���������
        */
        inline INT32  GetDataLen()
        {
            return m_pos;
        }

        /**
        * @brief
        * ���ݰ����byte�������ݣ�1�ֽڣ�
        * @param byValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        inline INT32  AddByte(UCHAR byValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��byte�������ݣ�1�ֽڣ�
        * @param byValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelByte( UCHAR  &byValue);

        /**
        * @brief
        * ���ݰ����char�������ݣ�1�ֽڣ�
        * @param chChar : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddChar(CHAR  chChar);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��char�������ݣ�1�ֽڣ�
        * @param chChar : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelChar(CHAR &chChar);

        /**
        * @brief
        * ���ݰ����USHORT�������ݣ�2�ֽڣ�
        * @param wValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddWord(UINT16 wValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��USHORT�������ݣ�1�ֽڣ�
        * @param wValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelWord(UINT16 &wValue);

        /**
        * @brief
        * ���ݰ����short�������ݣ�2�ֽڣ�
        * @param sValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddShort(INT16 sValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��short�������ݣ�2�ֽڣ�
        * @param sValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelShort(INT16 &sValue);

        /**
        * @brief
        * ���ݰ����unsigned int��������
        * @param dwValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddDword(UINT32 dwValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��unsigned int��������
        * @param dwValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelDword(UINT32 &dwValue);

        /**
        * @brief
        * ���ݰ����int��������
        * @param iValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddInt(INT32 iValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��int��������
        * @param iValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelInt(INT32 &iValue);

        /**
        * @brief
        * ���ݰ����UINT64��������(8�ֽ�)
        * @param uullValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddUint64(UINT64 uullValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��UINT64��������(8�ֽ�)
        * @param uullValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelUint64(UINT64& uullValue);

        /**
        * @brief
        * ���ݰ����INT64��������(8�ֽ�)
        * @param llValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddInt64(INT64 llValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��INT64��������(8�ֽ�)
        * @param llValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelInt64(INT64 &llValue);

        /**
        * @brief
        * ���ݰ����float��������
        * @param fValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddFloat(FLOAT fValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��float��������
        * @param fValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelFloat(FLOAT &fValue);

        /**
        * @brief
        * ���ݰ����double��������
        * @param dbValue : ��ӵ���������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddDouble(DOUBLE dbValue);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��double��������
        * @param dbValue : �õ�����������
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelDouble(DOUBLE &dbValue);

        /**
        * @brief
        * ���ݰ����string��������
        * @param pszStr : ��ӵ���������
        * @param dwBufLen : ��ӵ����ݳ���
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddString(const CHAR *pszStr, INT32 dwBufLen);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ���ַ�����������
        * @param pszOut :�õ�����������
        * @param dwBufLen : �õ������ݳ���
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelString(CHAR *pszOut, INT32 dwBufLen);
        /**
        * @brief
        * ���ݰ����wstring��������
        * @param wpszStr : ��ӵ���������
        * @param dwBufLen : ��ӵ����ݳ���
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddWString(const WCHAR *wpszStr, INT32 dwBufLen);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ���ַ�����������
        * @param wpszOut :�õ�����������
        * @param dwBufLen : �õ������ݳ���
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelWString(WCHAR *wpszOut, INT32 dwBufLen);
        /**
        * @brief
        * ���ݰ����һ��buffer����
        * @param pszBuf : ��ӵ�buf��ַ
        * @param dwBufLen : ��ӵ�buf����
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  AddBuf(const UCHAR *pszBuf, INT32 dwBufLen);

        /**
        * @brief
        * ���ݰ���ȡ��ɾ��һ��buffer����
        * @param pszBuf :���뻺�����õ�buffer����
        * @param dwBufLen : �õ������ݳ���
        * @return ���ݰ���ǰ��ָ��λ��
        */
        INT32  DelBuf(UCHAR *pszBuf, INT32 dwBufLen);

    private:
        CHAR    *m_pBuf;
        INT32   m_bufLen;
        INT32   m_pos;
    };

    /** @} */
}
#endif

