

//  Defines the entry point for the console application.
//  ʱ�䣺2010-12-28��
//

#ifndef _SGDP_APPLICATION_H_
#define _SGDP_APPLICATION_H_

#include <list>
#include <vector>
#include <string>
#include <map>
#include <sdserverid.h>
#include <sdshmem.h>
#include "sdpipechannel.h"
#include "sdconfig.h"
#include "sdloggerimpl.h"
//#include "sdconsole.h"
#include "sdu.h"
#include "netdata.h"
#include "sdcommandline.h"


namespace SGDP {

    /**
    * @brief CSDApplication��
    * �ײ����࣬����Ӧ�ó�����ڡ���Ҫ���й������������ļ���ȡ
    *                                             ��־����
    *                                             ������֮���������ƹ������
    *                                             �����п���̨
    */

    class CSDApplication
    {    
    public:


    public:
	    /**
	    * @brief ���캯��
	    */
        CSDApplication(void);

        /**
	    * @brief ��������
	    */
        ~CSDApplication(void);

	    /**
	    * @brief �ײ������ݡ����󡢲�����ʼ������
	    * @param pszConfigFilename : �������ĵ�·����utf8��ʽ��xml�ļ�
	    * @return BOOL�����ݣ�TRUE�����ʼ���ɹ���FALSE�����ʼ��ʧ��
	    */
        virtual BOOL        Init(const TCHAR* pszConfigFilename);
        
        /**
	    * @brief �ͷŵײ�����ϵͳ�������Դ
	    */
        virtual VOID        UnInit();

		/**
	    * @brief �ͷ���־ģ���������Դ
	    */
        virtual VOID        UnInitLog();

		/**
	    * @brief �ͷſ���̨ģ���������Դ
	    */
		virtual VOID        UnInitConsole();

        /**
	    * @brief ���߳��������庯��	  
	    * @return BOOL�����ݣ�TRUE����ǰ���й���ִ���˾�������
                              FALSE����ǰ���й���δִ�о�������
	    */
        virtual BOOL        Run();
       	
        /**
	    * @brief �趨����̨�̶���ʾ�����������
	    * @param nCount : ָ���Ŀ���̨�̶�������ʾ����	   
	    */
        VOID                SetFixedLineCount(INT32 nCount);

        /**
	    * @brief �ڿ���̨�������������־������̬��Ϣ
	    * @param format : ������ݵĸ�ʽ�ַ���	   
	    */
        VOID                PrintScreen(const TCHAR *format, ...);

        /**
	    * @brief ���¿���ָ̨���е���Ϣ����
        * @param wLine :  ָ����Ҫ���µ�����
	    * @param format : ������ݵĸ�ʽ�ַ���	   
	    */
        VOID                UpdateScreen(const UINT16 wLine , const TCHAR *format, ...);
        
        /**
	    * @brief ��ȡ�������ָ��
        * @return ISDNetָ�룬���صײ���ʹ�õ��������ָ��
	    */
        ISDNet*             GetNetModule();

        /**
	    * @brief ��ȡӦ�ÿ�ܵײ������֮�以���Ĺ�����
        * @return CSDPipeChannelMgrָ�룬����Ӧ�ÿ�ܵײ������֮�以���Ĺ��������ָ��
	    */
        CSDPipeChannelMgr*  GetPipeChannelMgr();

        /**
	    * @brief ��ȡӦ�ÿ���������ļ�������ָ��
        * @return CSDConfigָ�룬����Ӧ�ÿ���������ļ�������ָ��
	    */
        CSDConfig*          GetConfig();

        /**
	    * @brief ��ȡ������֮�以����Ϣ����
        * @return CPipeInfoVect���󣬷��ط�����֮�以����Ϣ����
	    */
        //CPipeInfoVect*      GetPipeVect();
        
        /**
	    * @brief ��ȡ�����д�����ָ��
        * @return CSDCommandLineָ�룬���������д�����ָ��
	    */
        CSDCommandLine*     GetCmdLine();

        /**
	    * @brief ��ֹӦ�ó��������
	    */
        VOID                Terminate();

        /**
	    * @brief ��ѯӦ�ó����Ƿ��Ѿ�����ֹ���С�
        * @return BOOL�����ݣ�TRUE ����Ӧ�ó�������ֹ��FALSE ����Ӧ�ó���δ��ֹ��
	    */
        BOOL                IsTerminated();


		/**
	    * @brief ��ø�Server��ServerID
        * @return ServerID
	    */
		UINT32				GetLocalID();

		/**
	    * @brief ��ø�Server��ZoneID
        * @return ZoneID
	    */
		UINT16				GetZoneID();

        /**
	    * @brief ���¿���̨����������״̬��Ϣ
        * @param dwID :  ��������ServerID
	    * @param dwIP :  ��������IP��ַ	   
	    * @param bConnect :  ����״̬��TRUE�������ӳɹ���FALSE�������ӶϿ���	 
	    */
        virtual VOID		UpdateSvrStatus(UINT32 dwID,UINT32 dwIP, BOOL bConnect);
        
        /**
	    * @brief ��������ʱ����������������������ܵ�m_oSDCommandLine
        * @param argc :  ������Ŀ
	    * @param argv :  �����ַ�������	    
	    */
        virtual VOID        OnSetCmdLine(INT32 argc, TCHAR** argv);

        /**
	    * @brief �����û��ӿ���̨���������Ǵ��麯������Ҫ�û��Լ�ʵ���ڲ����ܡ�
        * @param argc :  ������Ŀ
	    * @param argv :  �����ַ�������	    
	    */
        virtual VOID        OnHandleUserCmd(const TCHAR* szCmd) ;

        /**
	    * @brief ���������ӳɹ������������û����н���CSDPipeChannel��CSDProcessor�����Ľӿڡ�
        * @param dwPipeID :  �������ӵķ�������ServerID��
        * @return CSDPipeChannelָ�룬��Ӧ�ò㴴���������ظ��ײ���й�����   
	    */
        virtual CSDPipeChannel* OnPipeChannelConnected(UINT32 dwPipeID) = 0;
        
        /**
	    * @brief ���������ӶϿ����ײ㽫���CSDPipeChannelָ�봫��Ӧ�ò㣬Ӧ�ò���������Դ����
        * @param poChannel : ���ӶϿ���PipeChannelָ��
	    */
        virtual VOID        OnPipeChannelDisconnected(CSDPipeChannel* poChannel) = 0;

    private:
        /**
	    * @brief ��ܵײ��ڲ�ʹ�������ʼ����
        * @return BOOL�����ݣ�TRUE���������ʼ���ɹ���FALSE�����ʼ��ʧ�ܡ�   
	    */
        virtual BOOL		_InitComponent();
        
        /**
	    * @brief �ͷſ�ܵײ��ڲ�ʹ�������ϵͳ��Դ��
	    */
        virtual VOID		_UnInitComponent();

        /**
	    * @brief ���·���������״̬��Ϣ��
	    */
        virtual VOID        _UpdateSvrStatus();

        /**
	    * @brief �������ĵ��ж�ȡ������������Ϣ��
        * @param strPipeFile : ������Ϣ�����ĵ�·��
	    */
        VOID                _InitPipeInfoList(const string strPipeFile);
        
        /**
	    * @brief ɾ�����з���������״̬��Ϣ��
	    */
        VOID                _DeleteAllPipeInfo();

        /**
	    * @brief ����ServerID���ҷ�����������Ϣ�ṹ��
        * @param dwServerID : ָ���ķ�����ServerID
        * @return SPipeInfoָ�룬����ServerID�������׷�����������Ϣ�ṹ��
	    */
        SPipeInfo*          _FindPipeInfo(UINT32 dwServerID);
        
/*        ISDConsole*         m_poConsole;          ///< ����ָ̨��
        INT32               m_nMaxFixedAreaLines; ///< ����̨�̶���������������     */    
        ISDNet*				m_poNetModule;        ///< sdnet�������ָ��
        ISDPipeModule*		m_poPipeModule;       ///< sdpipe�������ָ��
        CSDPipeChannelMgr		m_oPipeChannelMgr;    ///< ����������������
        BOOL					m_bTerminated;        ///< ��ʶ���������߳��Ƿ����˳�
        tstring				m_strConfigFilename;  ///< �������ļ�·��
     
        CSDConfig			m_oConfig;            ///< �������ĵ��������
        CSDComLoggerImpl		m_oNetLogger;         ///< �������־�������
        CSDComLoggerImpl		m_oPipeLogger;        ///< sdpipe��־�������
		CSDComLoggerImpl		m_oDBLogger;        ///< sdpipe��־�������

		SShmem				m_shmemPipeInfo;		///< �����������б����ڴ�
        //SAllPipeInfo*			m_pstAllPipeInfo;		///< �����������б�
		vector<SPipeInfo>	m_vecPipeInfo;			//�����������б�	
        CSDCommandLine		m_oSDCommandLine;     ///< ������������������в����������
    };
}

/**
* @brief ��ȡӦ�ó���ȫ��Ψһ���ָ�룬Ӧ�ó������ͨ�����api�ڳ����κεط��ܷ���Ļ�ȡ��������ڡ�
*/
extern  CSDApplication* SDGetApp();

#endif

