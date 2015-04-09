

//  Defines the entry point for the console application.
//  ʱ�䣺2010-12-28��
//

#ifndef _SGDP_FRAMEWORK_LOGGER_H_
#define _SGDP_FRAMEWORK_LOGGER_H_

#include "sdlogger.h"
#include "sdstring.h"

#include <sdmutex.h>
#include <sdobjectpool.h>

#ifndef MAX_PATH
#define MAX_PATH   260
#endif
namespace SGDP {

    enum EExeLogLvl
    {
        LOGLVL_SYS_CRITICAL = 0,  ///< ϵͳ������������־
        LOGLVL_SYS_IMPORTANT,     ///< ϵͳ����Ҫ��־
        LOGLVL_SYS_INFO,          ///< ϵͳ����Ϣ��־
        LOGLVL_USR_CRITICAL,      ///< �û�������������־
        LOGLVL_USR_IMPORTANT,     ///< �û�����Ҫ��־
        LOGLVL_USR_INFO,          ///< �û�����Ϣ��־
        LOGLVL_DBG_INFO,          ///< �û���������־
        LOGLVL_MAX,               ///< ����������־����
    };

	//�쳣������־�����ڼ�¼�쳣���
    #define SYS_CRITICAL    if(CSDLoggerImpl::NeedLog(LOGLVL_SYS_CRITICAL))CSDLoggerImpl::SysCritical   ///< ϵͳ������������־
    //#define SYS_IMPORTANT   if(CSDLoggerImpl::NeedLog(LOGLVL_SYS_IMPORTANT))CSDLoggerImpl::SysImportant ///< ϵͳ����Ҫ��־
    //#define SYS_INFO        if(CSDLoggerImpl::NeedLog(LOGLVL_SYS_INFO))CSDLoggerImpl::SysInfo           ///< ϵͳ����Ϣ��־
    //#define USR_CRITICAL    if(CSDLoggerImpl::NeedLog(LOGLVL_USR_CRITICAL))CSDLoggerImpl::UsrCritical   ///< �û�������������־
    //#define USR_IMPORTANT   if(CSDLoggerImpl::NeedLog(LOGLVL_USR_IMPORTANT))CSDLoggerImpl::UsrImportant ///< �û�����Ҫ��־
	//�û���־������׷�ٺ�ʵ�û�������Ϣ
    #define USR_INFO        if(CSDLoggerImpl::NeedLog(LOGLVL_USR_INFO))CSDLoggerImpl::UsrInfo           ///< �û�����Ϣ��־
	//������־�����ڶ�λbug
    #define DBG_INFO        if(CSDLoggerImpl::NeedLog(LOGLVL_DBG_INFO))CSDLoggerImpl::DbgInfo           ///< ������Ϣ��־

	//#define	PRINT_ERR_INFO		if(CSDLoggerImpl::NeedLog(LOGLVL_SYS_CRITICAL))CSDLoggerImpl::SysCritical(_SDT("[%s: %d]: "), MSG_MARK);

	#define MAX_LOG_DATA_LEN 8192

	typedef struct _tagLOGDATA
	{
		_tagLOGDATA()
		{
			Init();
		}
		void Init()
		{
			memset(this, 0x00, sizeof(_tagLOGDATA));
		}
		TCHAR	szData[MAX_LOG_DATA_LEN];
	}CLOGDATA, *pLOGDATA;

    /**
    * @brief CSDLoggerImpl��
    * �ײ�����־ʵ�ִ����࣬ͳһ�ṩ��־api����Ҫ�ṩ���¼����ܣ�
    * 1���ļ���־��
    * 2��udp��־����
    * 3��tcp��־����
    * 4���������ɿ���������־����
    * 5��Ϊ��־��Ϣ����ģ�����ǰ׺����ʶ��־��Ϣ�ķ���
    */
    class CSDLoggerImpl : public ISDLogger
    {
        /**
	    * @brief ���캯��
	    */
        CSDLoggerImpl();

        /**
	    * @brief ��������
	    */
        virtual ~CSDLoggerImpl();
    public:
        /**
	    * @brief ��̬��������ʼ��Ӧ�ó�����־���������Ϣ
	    * @param pszConfig : �������ĵ�·����utf8��ʽ��xml�ļ�
	    * @return BOOL�����ݣ�TRUE�����ʼ���ɹ���FALSE�����ʼ��ʧ��
	    */
        static BOOL Init(const TCHAR *pszConfig);

        /**
	    * @brief ��̬��������ʼ��Ӧ�ó�����־���������Ϣ
	    * @return BOOL�����ݣ�TRUE�����ʼ���ɹ���FALSE�����ʼ��ʧ��
	    */
        static BOOL Reload();

        /**
	    * @brief �ͷŵײ�����ϵͳ�������Դ
	    */
        static VOID UnInit();

        /**
	    * @brief ��̬�������ж�ָ����־�����Ƿ���Ҫ����
	    * @param nLevel : ��־����
	    * @return BOOL�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        static BOOL NeedLog(EExeLogLvl nLevel);

        /**
	    * @brief ��̬��������¼ϵͳ������������־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID SysCritical(const TCHAR *format, ...);

        /**
	    * @brief ��̬��������¼ϵͳ����Ҫ��־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID SysImportant(const TCHAR *format, ...);

        /**
	    * @brief ��̬��������¼ϵͳ����Ϣ��־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID SysInfo(const TCHAR *format, ...);
        
        /**
	    * @brief ��̬��������¼�û�������������־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID UsrCritical(const TCHAR *format, ...);

        /**
	    * @brief ��̬��������¼�û�����Ҫ��־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID UsrImportant(const TCHAR *format, ...);

        /**
	    * @brief ��̬��������¼�û�����Ϣ��־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID UsrInfo(const TCHAR *format, ...);

        /**
	    * @brief ��̬��������¼������Ϣ��־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID DbgInfo(const TCHAR *format, ...);

        /**
	    * @brief δ�ӷ���ͷ����ʶ��Ϣ����־
	    * @param format : ��־��Ϣ��ʽ
	    */
        static VOID NoHeadLog(const TCHAR *format, ...);

        /**
	    * @brief ��/��ָ����־����
	    * @param nIndex : ��־����
        * @param bVal : TRUE������ָ������־����FALSE����ر�ָ������־����
	    */
        static VOID SetLogLevel(INT32 nIndex, BOOL bVal);

        /**
	    * @brief ��̬�������ж�ָ������־�����Ƿ���Ҫ��¼
	    * @param nLevel : ��־����
	    * @return BOOL�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        static BOOL GetLevelValue(INT32 nIndex);

        /**
	    * @brief ��̬�������ж��Ƿ���Ҫ�����ļ���־����
	    * @return BOOL�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        static BOOL IsLogToFile() { return m_bLogToFile; }
        
        /**
	    * @brief ��̬�������ж��Ƿ���Ҫ����Debug��־����
	    * @return BOOL�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        static BOOL IsLogToDebugger() { return m_bLogToDebugger; }
        
        /**
	    * @brief ��̬�������ж��Ƿ���Ҫ����udp��־��Ϣ���ݲ���
	    * @return BOOL�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        static BOOL IsLogToUdp() { return m_bLogToUdp; }
        
        /**
	    * @brief ��̬�������ж��Ƿ���Ҫ����tcp��־��Ϣ���ݲ���
	    * @return BOOL�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        static BOOL IsLogToTcp() { return m_bLogToTcp; }

        /**
	    * @brief ��̬�������趨�Ƿ���Ҫ�����ļ���־��Ϣ����
	    * @param bLog : �Ƿ����ļ���־
	    */
        static VOID SetLogToFile(BOOL bLog) { m_bLogToFile = bLog; }

        /**
	    * @brief ��̬�������趨�Ƿ���Ҫ����Debug��־��Ϣ����
	    * @param bLog : �Ƿ���Debug��־
	    */
        static VOID SetLogToDebugger(BOOL bLog) { m_bLogToDebugger = bLog; }

        /**
	    * @brief ��̬�������趨�Ƿ���Ҫ����Udp��־��Ϣ���ݲ���
	    * @param bLog : �Ƿ���Udp��־��Ϣ����
	    */
        static VOID SetLogToUdp(BOOL bLog) { m_bLogToUdp = bLog; }
        
        /**
	    * @brief ��̬�������趨�Ƿ���Ҫ����tcp��־��Ϣ���ݲ���
	    * @param bLog : �Ƿ���tcp��־��Ϣ����
	    */
        static VOID SetLogToTcp(BOOL bLog) { m_bLogToTcp = bLog; }

        /**
	    * @brief ���ַ�����ʽ��¼��־
	    * @param pszLog : ��Ҫ��¼����־��Ϣ
        * @return bool�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        virtual bool SDAPI LogText(const TCHAR* pszLog);

        /**
	    * @brief �Զ�������ʽ��¼��־
	    * @param pLog : ��Ҫ��¼����־��Ϣ�ڴ�ָ��
	    * @param dwLen : ��Ҫ��¼����־��Ϣ�ڴ泤������
        * @return bool�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        virtual bool SDAPI LogBinary(const UINT8* pLog, UINT32 dwLen);

    protected:

        /**
	    * @brief ��̬����������ڲ������������ṩ�ⲿʹ�ã�
        *                  �����û��ṩ�ĸ�ʽ��Ϣ����־���𣬼�¼��־
	    * @param nLevel : ָ������־����
        * @param format : ��־��ʽ��Ϣ
        * @param argptr : �β��б�
	    */
        static VOID _Log(EExeLogLvl nLevel, const TCHAR *format, va_list argptr);
    protected:

        static BOOL     m_abLogLevel[LOGLVL_MAX];   ///< ��Ӧ��־�����Ƿ�����ʶ����
        static TCHAR *  m_aszLogPrefix[LOGLVL_MAX]; ///< ��Ӧ��־����ǰ׺��ʶ����
        static CHAR     m_szConfig[MAX_PATH];       ///< ��Ӧ��־��Ϣ���ù����ĵ�·��
        static TCHAR    m_szSysLogFileName[MAX_PATH];  ///< �ļ���־���ļ���
		static TCHAR    m_szUsrLogFileName[MAX_PATH];  ///< �ļ���־���ļ���
		static TCHAR    m_szDbgLogFileName[MAX_PATH];  ///< �ļ���־���ļ���

        static ISDFileLogger   *	m_pSYSFileLogger;      ///< �ļ���־���ָ��
		static ISDFileLogger   *	m_pUsrFileLogger;      ///< �ļ���־���ָ��
		static ISDFileLogger   *	m_pDbgFileLogger;      ///< �ļ���־���ָ��
        static BOOL				m_bLogToFile;       ///< �Ƿ����ļ���־��ʶ
        static BOOL				m_bLogToDebugger;    ///< �Ƿ���debug��־��ʶ

        static ISDUdpLogger   *m_pUdpLogger;        ///< Udp��־���ݾ��ָ��
        static BOOL			m_bLogToUdp;                ///< �Ƿ���Udp��־���ݱ�ʶ

        static ISDTcpLogger   *m_pTcpLogger;        ///< tcp��־���ݾ��ָ��
        static BOOL			m_bLogToTcp;          ///< �Ƿ���tcp��־���ݱ�ʶ

		static CSDObjectPool<CLOGDATA, CSDMutex> m_oLogDataPool; //��־��Ϣ�ṹ��
    };

    /**
    * @brief CSDComLoggerImpl��
    * �ײ�����־ʵ�ִ����࣬ͳһ�ṩ��־api��
    * Ϊ��־��Ϣ����ǰ׺����ʶ��־��Ϣ�ķ���
    */
    class CSDComLoggerImpl : public ISDLogger
    {
    public:
        /**
	    * @brief ���캯��
	    */
        CSDComLoggerImpl();
        ~CSDComLoggerImpl();
        /**
	    * @brief ��̬������ָ����־ģ������ǰ׺�����磺[sdnet]��[sdpipe]
	    * @param pszConfig : �������ĵ�·����utf8��ʽ��xml�ļ�
	    * @return BOOL�����ݣ�TRUE�����ʼ���ɹ���FALSE�����ʼ��ʧ��
	    */
        VOID Init(const TCHAR* pszPrefix);

        /**
	    * @brief ���ַ�����ʽ��¼��־
	    * @param pszLog : ��Ҫ��¼����־��Ϣ
        * @return bool�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        virtual bool SDAPI LogText(const TCHAR *pszLog);
      
        /**
	    * @brief �Զ�������ʽ��¼��־
	    * @param pLog : ��Ҫ��¼����־��Ϣ�ڴ�ָ��
	    * @param dwLen : ��Ҫ��¼����־��Ϣ�ڴ泤������
        * @return bool�����ݣ�TRUE������Ҫ����FALSE������Ҫ����
	    */
        virtual bool SDAPI LogBinary(const UINT8 *pLog, UINT32 dwLen);

    protected:
        TCHAR	m_szPrefix[16];      ///< ָ����־ǰ׺������
    };

}

#endif

