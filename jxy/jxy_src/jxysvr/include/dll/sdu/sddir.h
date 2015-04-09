/******************************************************************************
			

sddir.h - Ŀ¼����

******************************************************************************/
#ifndef SDDIR_H
#define SDDIR_H
/**
* @file sddir.h

* @brief dir utility
*
**/
#if (defined(WIN32) || defined(WIN64))
#else
#include <sys/types.h>
#include <dirent.h>
#endif
#include <string>
#include "sdtype.h"
#include "sdfile.h"

#ifdef __linux__
#include <unistd.h>
#else
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir    
#endif

#include <vector>
using namespace std;
namespace SGDP
{
    /**
    * @defgroup groupdir Ŀ¼����
    * @ingroup  SGDP
    * @{
    */

    struct SFileAttr
    {
        BOOL isDir; //�Ƿ�ΪĿ¼
    };
    /**
    *@brief Ŀ¼�����࣬�����ڻ�ȡ��Ŀ¼�����е��ļ����ļ��е�����
    */
    class CSDDirectory
    {
    public:

        CSDDirectory();
        ~CSDDirectory();
        /**
        * @brief
        * ��һ��Ŀ¼��������fopenһ��
        * @param pszPath : Ŀ¼��·��
        * @return FALSE �����ʧ�ܣ�TRUE����򿪳ɹ�
        */
        BOOL  Open(const TCHAR* pszPath);

        /**
        * @brief
        * �رմ�Ŀ¼
        * @return VOID
        */
        VOID  Close();

        /**
        * @brief
        * ��ȡ��Ŀ¼����һ���ļ������ƣ�����֪�����ļ��Ƿ�ΪĿ¼
        * @param pszName : [�������]�Ӹ�Ŀ¼�л�ȡ���ļ���
        * @param nBufLen : [�������]�ܹ���ֵ����󳤶�
        * @param pAttr : [�������]�����ļ�����, isDir���Ϊ1����ΪĿ¼������Ϊ0����������ΪNULL�����޷���ֵ
        * @return �ɹ�����TRUE����ȡʧ�ܣ����ߵ���Ŀ¼���ļ��Ľ�β����FALSE
        */
        BOOL  Read(TCHAR *pszName, INT32 nBufLen, SFileAttr *pAttr = NULL);

		/**
        * @brief
        * ��ȡ��Ŀ¼�������ļ�
        * @param vecFile : [�������]�Ӹ�Ŀ¼�л�ȡ���ļ����б�
        * @return �ɹ�����TRUE����ȡʧ�ܣ����ߵ���Ŀ¼���ļ��Ľ�β����FALSE
        */
		BOOL  ReadAllFile(vector<string>& vecFile);
    private:
#if (defined(WIN32) || defined(WIN64))
        tstring m_szPath;
        HANDLE m_fHandle;
#else
        DIR * m_dir;
		CHAR m_curDir[SD_MAX_PATH]; 
#endif
    };


    /**
    * @brief
    * ����Ŀ¼
    * @param pszDirName : ��������Ŀ¼·��������
    * @param bforce : ��û���ϼ�Ŀ¼ʱ���Ƿ�ǿ�ƴ���Ŀ¼
    * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL  SDCreateDirectory(const TCHAR *pszDirName, BOOL bForce= FALSE);

    /**
    * @brief
    * ɾ��һ��Ŀ¼
    * @param pszDirName : ��ɾ����Ŀ¼·��������
    * @param bForce     : �Ƿ�ǿ��ɾ��Ŀ¼
    * @return �ɹ�����TRUE��ʧ�ܷ���FALSE(�ļ����������ݻ���û��ɾ��Ȩ��)
    */
    BOOL  SDDeleteDirectory(const TCHAR *pszDirName, BOOL bForce = FALSE);

    /**
    * @brief
    * ɾ��һ��Ŀ¼
    * @param pszDirName : ��ɾ����Ŀ¼·��������
    * @return �ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL  SDDirectoryExists(const TCHAR *pszDirName);

	/**
	* @brief
	* �ж�һ���ļ��Ƿ�Ϊ�ļ���
	* @param pszFileName : �ļ���
	* @return �ɹ�����TRUE��ʧ�ܷ���FALSE
	*/
    BOOL  SDIsDirectory(const TCHAR * pszFileName);

	/**
	* @brief
	* �ж�һ���ļ����Ƿ�Ϊ��
	* @param pszFileName :  �ļ���
	* @return �ɹ�����TRUE��ʧ�ܷ���FALSE
	*/
    BOOL  SDIsEmptyDirectory(const TCHAR* pszFileName);

	//TODO Ŀ¼����

    /** @} */
}

#endif


