

#ifndef SDCOMMANDLINE_H
#define SDCOMMANDLINE_H

#include <sdtype.h>
#include "sdstring.h"
#include <vector>
#include <sddebug.h>

#define COMMAND_NAME_LENGTH 20  ///< �����������������    
#define COMMAND_PARAM_LENGTH 512 ///< �����в������������    

namespace SGDP{
    /**
    * @brief CSDCommandLine��
    * �ײ��������д����ࡣ
    */
    class CSDCommandLine
    {
    public:
        /**
        * @brief CCommand��
        * ������������ࡣ
        */
        class CCommand
        {
        public:
			CCommand()
			{
				memset(m_pszCommandName, 0x00, sizeof(m_pszCommandName));
				memset(m_pszCommandParam, 0x00, sizeof(m_pszCommandParam));
			}
	        /**
	        * @brief �趨��������
	        * @param pszName : ��������
	        */
            VOID SetCommand(const TCHAR* pszName)
            {
                _SDTStrcpy(m_pszCommandName,pszName);
            }

	        /**
	        * @brief ��ȡ����ֵ
	        * @return ����ֵ
	        */
            const TCHAR* GetCommand()
            {
                return m_pszCommandName;
            }

	        /**
	        * @brief �趨�������
	        * @param pszName : �������
	        */
            VOID SetCommandParam(const TCHAR* pszParam)
            {
                _SDTStrcpy(m_pszCommandParam,pszParam);
            }

            /**
	        * @brief ��ȡ�������
	        * @return �������
	        */
            const TCHAR* GetCommandParam()
            {
                return m_pszCommandParam;
            }
        private:
            TCHAR m_pszCommandName[COMMAND_NAME_LENGTH];   ///< ��������
            TCHAR m_pszCommandParam[COMMAND_PARAM_LENGTH]; ///< �����Ӧ����
        };
    public:
        /**
	    * @brief ���캯��
	    */
        CSDCommandLine();
        
        /**
	    * @brief ���캯�����ڲ�������ParserCommandLine();
	    * @param pszCommandLine : �ַ���
	    */
        CSDCommandLine(const TCHAR* pszCommandLine);

        /**
	    * @brief ��������
	    */
        ~CSDCommandLine();

	    /**
	    * @brief �趨����������
	    * @param pszName : ����������
	    */
        VOID SetCommandLine(const TCHAR* pszCommandLine);

        /**
	    * @brief �ƶ���ǰ�������ָ��Ϊ��һ��
	    * @return ��һ���������ָ��
	    */
        CCommand* GetFirstCommand();

        /**
	    * @brief �ƶ���ǰ�������ָ��Ϊ��һ��
	    * @return ��һ���������ָ��
	    */
        CCommand* GetNextCommand();
    protected:

        /**
	    * @brief ����m_pszCommandLine������������
	    */
        VOID ParserCommandLine();
        const TCHAR* m_pszCommandLine;        ///< �������ַ���ָ��
        std::vector<CCommand*> m_oCommandVec;  ///< �������
        INT32 m_nCurrent;                     ///< ��¼��ǰָ��λ��
    };
};

#endif

