#ifndef SDSTRENCRYPT_H
#define SDSTRENCRYPT_H
/**
* @file sdstrencrypt.h
* @brief �ַ������ܽ���ϵ��
*
**/
#include "sdtype.h"
#include <string>


namespace SGDP
{
    /**
    * @defgroup groupencrypt �ַ�������
    * @ingroup  SGDP
    * @{
    */

    /**
    *@brief �ַ������ܴ�����
    */
    class CSDStrEncrypt
    {
    public:

		/**
		* @brief ���캯��
		*/
        CSDStrEncrypt() {}

		/**
		* @brief ��������
		*/
        ~CSDStrEncrypt() {}
        static const BYTE CODE_KEY = 0x96;	/**<���ܶ�Ӧ��key*/

        //��ÿ���ֽڸߵ�4bit��������KEY�����������

        /**
        * @brief static, encode a string ���ַ������м���
        * @param sContent : string to be encoded Ҫ���ܵ��ַ���
        * @return VOID
        */
        static VOID  Encode(std::string& sContent);

        /**
        * @brief static, encode a string ���ַ������м���
        * @param pBuf : pointer to the buf to be encode Ҫ���ܵĻ�����
        * @param nLen : buf len ����������
        * @return VOID
        */
        static VOID  Encode(BYTE *pBuf, INT32 nLen);

        /**
        * @brief static, decode a string ���ַ������н���
        * @param sContent : string to be decode Ҫ���ܵ��ַ���
        * @return VOID
        */
        static VOID  Decode(std::string &sContent);

        /**
        * @brief static, decode a string ���ַ������н���
        * @param pBuf : pointer to the buf to be encode Ҫ���ܵĻ�����
        * @param nLen : buf len ����������
        * @return VOID
        */
        static VOID  Decode(BYTE *pBuf, INT32 nLen);
    };

    /** @} */

} // namespace SGDP



#endif //


