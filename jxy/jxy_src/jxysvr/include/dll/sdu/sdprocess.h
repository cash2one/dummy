/******************************************************************************


sdprocess.h - ���̴���

******************************************************************************/

#ifndef SDPROCESS_H
#define SDPROCESS_H
/**
* @file sdprocess.h

* @brief ���̴���
*
**/
#include "sdtype.h"
#include <string>
#if (defined(WIN32) || defined(WIN64))
#include "Aclapi.h"
#include "Winbase.h"
#else
#include <dlfcn.h>
#endif // 

#include <vector>
using namespace std;


namespace SGDP
{
    /**
    * @defgroup groupthread ����̶��߳�(�����̳߳�)
    * @ingroup  SGDP
    * @{
    */
#if (defined(WIN32) || defined(WIN64))
	typedef struct tagProcessSecInfo 
	{
		BOOL bSet; // �Ƿ����ô˰�ȫ��Ϣ
		SE_OBJECT_TYPE objectType;
		SECURITY_INFORMATION securityInfo;
		PSID psidOwner;
		PSID psidGroup;
		PACL pDacl;
		PACL pSacl;
		PSECURITY_DESCRIPTOR pSecurityDescriptor; // ��ȡʱʹ��
	} SProcessSecInfo; 
#endif 

	/**
	* @brief ��������
	*/
    struct SProcessAttr
    {
        std::string  workDir;  //����ִ�еĹ���Ŀ¼
        std::string  environment;
        UINT32       createFlags;  // ���̴�����ʶ fow windows.
        BOOL         inherithandle;// for Windows
#if (defined(WIN32) || defined(WIN64))
		SProcessAttr()
		{
			secInfo.bSet = FALSE; 
		}
		SProcessSecInfo secInfo; 
#endif // 
    };


#if (defined(WIN32) || defined(WIN64))
typedef UINT32 SDPROCESSID; 
#else 
typedef pid_t  SDPROCESSID; 
#endif // 

    /**
    * @brief
    * ����һ������
    * @param progName : �ý��̵�ִ���ļ�
    * @param pCmdline : ������
    * @param pWorkDir : �ý��̵Ĺ���Ŀ¼
    * @param pAttr    : �ý��̵�����
    * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    SDHANDLE  SDCreateProcess(
        const CHAR *progName,
        const CHAR *pCmdLine = NULL,
        const CHAR *pWorkDir = NULL,
        SProcessAttr *pAttr = NULL);

    /**
    * @brief
    * ��ֹһ������
    * @param handle : ���̾��
    * @param err  :ָ�������˳�ʱ�Ĵ�������Ϣ
    * @return VOID
    */
    VOID  SDTerminateProcess(SDHANDLE handle, INT32 err = 0);

    /**
    * @brief
    * �رս��̵ľ��,���ڽ��̲�Ҫʹ��ͨ�õ�SDCloseHandle���رվ��,����ᵼ����Դδ�ͷ�
    * @param handle : ���̾��
    * @return VOID
    */
    VOID  SDCloseProcess(SDHANDLE handle);

	/**
	* @brief
	* ��ȡ����ID�����̱�����������
	* @param handle : ���̾��
	* @return VOID
	*/
	SDPROCESSID  SDGetProcessId(SDHANDLE handle); 

	/**
	* @brief
	* ͨ������ID��ȡ����handle��
	* @param pid: ����ʵ��ID
	* @return VOID
	*/
	SDHANDLE  SDOpenProcess(SDPROCESSID pid); 

	/**
	* @brief
	* ��ȡ��ǰ�Ľ���
	* @return ��ǰ���̾��
	*/
	SDHANDLE  SDGetCurrentProcess(); 

	/**
	* @brief
	* ��ȡ��ǰ�Ľ���id
	* @return ��ǰ�Ľ���id
	*/
	SDPROCESSID  SDGetCurrentProcessId(); 

    /**
    * @brief
    * �ȴ�������ֹ
    * @param handle : ���̾��
    * @return VOID
    */
    VOID  SDWaitProcess(SDHANDLE handle);

	/**
	* @brief
	* ���ý�������
	* @param handle : ���̾��
    * @param pAttr  : ��������
	* @return ���ý��
	*/
    BOOL  SDSetProcessAttr(SDHANDLE handle, const SProcessAttr &pAttr);

	/**
	* @brief
	* ��ȡ��������
	* @param handle : ���̾��
	* @param procAttr : ��������
	* @return ��ȡ�Ƿ�ɹ�
	*/
	BOOL  SDGetProcessAttr(SDHANDLE handle, SProcessAttr & procAttr); 

    /**
    * @brief ���̲�����
    */
    class CSDProcess
    {
    public:

		/**
		* @brief ���캯������ʼ�����̾��
		*/
        CSDProcess();

		/**
		* @brief ������������������
		*/
        ~CSDProcess();

        /**
        * @brief
        * ��������
        * @param path : �ý��̵�ִ���ļ�
        * @param pArgs: �ý��̵��������
        * @param pEnvs: �ý��̵Ļ�������
        * @param pAttr: �ý��̵�����
        * @return ����ɹ�����TRUE, ʧ�ܷ���FALSE
        */
        BOOL  Create(
            const CHAR *pProgName,
            const CHAR *pArgs = NULL,
            const CHAR *pEnvs = NULL,
            SProcessAttr *pAttr = NULL);

        /**
        * @brief
        * ��ֹ����
        * @return VOID
        */
        VOID  Terminate();

        /**
        * @brief
        * �ȴ�������ֹ����ִ�н���
        * @return VOID
        */
        VOID  Wait();

		/**
		* @brief
		* ��ȡ����ID
		* @return SDHANDLE
		*/
		UINT32  GetProcessID(); 

        /**
        * @brief
        * ��ȡ���̾��
        * @return SDHANDLE
        */
        SDHANDLE  GetHandle();

        /**
        * @brief
        * ���ý�������
        * @param pAttr : �����õĽ�������
        * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
        */
        BOOL  SetAttribute(const SProcessAttr &pAttr);

        /**
        * @brief
        * ��ȡ��������
        * @param handle : ���̾��
        * @param procAttr : �����ȡ���Ľ�������
        * @return TRUE:��ȡ�ɹ� FALSE:��ȡʧ��
        */
        BOOL  GetAttribute(SDHANDLE handle, SProcessAttr & procAttr);

    private:

		/**
		* @brief �������캯��
		* @param CSDProcess���������
		*/
        CSDProcess (const CSDProcess&);

		/**
		* @brief ����=��������ʵ��CSDProcess����Ŀ���
		* @param CSDProcess���������
		* @return CSDProcess���������
		*/
        CSDProcess& operator = (const CSDProcess&);
        SDHANDLE m_handle;
    };

    /**
    * @brief ������ļ�
    * @param pszFileName : ���ļ���
    * @param nMode       : linuxϵͳ������ģʽ
    * @return ��ģ��ľ��
    */
    SDHANDLE SDLoadLibrary(const TCHAR* pszFileName,INT32 nMode = 0);

    /**
    * @brief �ͷſ�ģ����
    * @param handle : ��ģ����
    * @return TRUE:�ͷųɹ� FALSE:�ͷ�ʧ��
    */
    BOOL SDFreeLibrary(SDHANDLE handle);

    /** @} */
}

#endif


