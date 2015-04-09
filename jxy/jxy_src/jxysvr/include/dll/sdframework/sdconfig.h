

#ifndef __SGDP_CONFIG_XML_H_
#define __SGDP_CONFIG_XML_H_

#include <string>
#include <string.h>
#include "sdxmlfile.h"
#include "sdtype.h"

using namespace std;

namespace SGDP {  
    /**
    * @brief CSDConfig��
    * �ײ����������ĵ������ࡣ
    */
    class CSDConfig  
    {
    public:
        /**
	    * @brief ���캯��
	    */
	    CSDConfig();
    
        /**
	    * @brief ��������
	    */
	    ~CSDConfig();

        /**
	    * @brief �ͷŵײ�����ϵͳ�������Դ
	    */
	    virtual VOID        UnInit();

	    /**
	    * @brief �ײ������ݡ����󡢲�����ʼ������
	    * @param pszConfigFilename : �������ĵ�·����utf8��ʽ��xml�ļ�
	    * @return BOOL�����ݣ�TRUE�����ʼ���ɹ���FALSE�����ʼ��ʧ��
	    */
	    virtual BOOL        Init(const TCHAR* pszFilename);
	    
        /**
	    * @brief ��ȡ����������
	    * @return ���ط���������
	    */
        std::string         GetServerName();
        
        /**
	    * @brief ��ȡpipe���Ӻڰ����������ĵ�·��
	    * @return ����pipe���Ӻڰ����������ĵ�·��
	    */
        std::string         GetIpListFile();

        /**
	    * @brief ��ȡpipe���������ĵ�·��
	    * @return ����pipe���������ĵ�·��
	    */
        std::string         GetPipeFile();

        /**
	    * @brief ��ȡ������ServerID
	    * @return ���ط�����ServerID
	    */
	    UINT32              GetServerID();

        /**
	    * @brief ��ȡPipeModel��run�����趨�Ĳ���
	    * @return ����PipeModel��run�����趨�Ĳ���
	    */
        UINT32              GetPipeModuleCount();

        /**
	    * @brief ��ȡNetModel��run�����趨�Ĳ���
	    * @return ����NetModel��run�����趨�Ĳ���
	    */
        UINT32              GetNetModuleCount();

        /**
	    * @brief ��ȡ�Ƿ��ڿ���̨��ʾ��Ϣ��״̬��ʶ
	    * @return �����Ƿ��ڿ���̨��ʾ��Ϣ��״̬��ʶ��TRUE������Ҫ��ʾ�ڿ���̨��FALSE��ʶ����ʾ
	    */
        BOOL                GetShowConnectionStatus();

        /**
	    * @brief �趨�Ƿ��ڿ���̨��ʾ��Ϣ��״̬��ʶ
	    * @param bShowConnectionStatus �����Ƿ��ڿ���̨��ʾ��Ϣ��״̬��ʶ
	    */
        VOID                SetShowConnectionStatus(const BOOL bShowConnectionStatus);
      
        /**
	    * @brief ��ȡNetModel�н��ջ�������С
	    * @return ����NetModel�н��ջ�������С
	    */
        UINT32              GetRecvBufferSize();

        /**
	    * @brief ��ȡNetModel�з��ͻ�������С
	    * @return ����NetModel�з��ͻ�������С
	    */
        UINT32              GetSendBufferSize();

        /**
	    * @brief ��ȡNetModel��������IP��ַ
	    * @return ����NetModel��������IP��ַ
	    */
        std::string         GetListenIp();

        /**
	    * @brief ��ȡNetModel�������Ķ˿�
	    * @return ����NetModel�������Ķ˿�
	    */
        UINT16              GetListenPort();

        /**
	    * @brief ��ȡ������������û���Ŀ
	    * @return ����������������û���Ŀ
	    */
        UINT32              GetMaxUsers();

		UINT32				GetNetLevel();
		UINT32				GetPipeLevel();
		UINT32				GetDbLevel();

    protected:
	    tstring             m_strFilename;           ///< �������ĵ�·��
	    std::string         m_strServerName;         ///< ����������
        std::string         m_strPipeFile;           ///< pipe���������ĵ�·��
        std::string         m_strIpList;             ///< pipe���Ӻڰװ������ĵ�·��
        std::string         m_strListenIp;           ///< ������IP��ַ
        UINT16              m_wPort;                 ///< �����Ķ˿�
	    UINT32              m_dwServerID;            ///< ��������ServerID
        UINT32              m_dwNetModuleCount;      ///< NetModel���к���Run�Ĳ���
        UINT32              m_dwPipeModuleCount;     ///< PipeModel���к���Run�Ĳ���
        UINT32              m_dwRecvBufferSize;      ///< ���ջ�������С
        UINT32              m_dwSendBufferSize;      ///< ���ͻ�������С
        BOOL                m_bShowConnectionStatus; ///< ����̨�Ƿ���ʾ��Ϣ��ʶ
        UINT32				m_dwMaxUsers;            ///< ������������û���Ŀ
		UINT32				m_dwNetLevel;
		UINT32				m_dwPipeLevel;
		UINT32				m_dwDbLevel;
        
    };
}

#endif

