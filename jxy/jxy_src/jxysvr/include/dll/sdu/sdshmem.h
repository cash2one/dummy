/******************************************************************************
		


******************************************************************************/


#ifndef SDSHMEM_H
#define SDSHMEM_H
/**
* @file sdshmem.h

* @brief �����ڴ湤��
*
**/
#include <string>
#include "sdtype.h"

namespace SGDP
{
    /**
    * @defgroup groupsharememory �����ڴ�
    * @ingroup  SGDP
    * @{
    */

    /**
    * @brief �����ڴ�Ľṹ��
    *
    */
    struct SShmem
    {
		SShmem()
		{
			Init();
		}
		void Init()
		{
			handle = NULL;
			mem = NULL;
		}
        SDHANDLE    handle;		/**<�ļ���Ӧ��handle*/
        VOID *      mem;		/**<�����ڴ����ʼ��ַ*/
        std::string file;		/**<�����ڴ��Ӧ���ļ�·��*/
    };

    /**
    * @brief
    * ��һ�������ڴ�
    * @param pszFileName : �����ڴ�ӳ���ļ�
    * @param bCreate : ���û�иù����ڴ�ʱ���Ƿ񴴽������ڴ�
    * @param size : �����ڴ��С
    * @return �����ڴ�Ľṹ��
    */
    SShmem  SDOpenShmem( const CHAR * pszFileName, BOOL bCreate = FALSE, UINT64 size = 0 );

    /**
    * @brief
    * ����һ�������ڴ�
    * @param pszFileName : �����ڴ�ӳ���ļ�
    * @param size : �����ڴ��С
    * @return �����ڴ�Ľṹ��
    */
    SShmem  SDCreateShmem( const CHAR * pszFileName, UINT64 size );

    /**
    * @brief
    * ����һ�������ڴ�
    * @param file : �����ڴ�ӳ���ļ�
    * @param size : �����ڴ��С
    * @return �����ڴ�Ľṹ��
    */
    BOOL  SDShmemExist( const CHAR * pszFileName );

	/**
    * @brief
    * ����һ�������ڴ�
    * @param file : �����ڴ�ӳ���ļ�
    * @param size : �����ڴ��С
    * @return �����ڴ�Ľṹ��
    */
	BOOL SDAttachShm(SShmem *shm, const CHAR *file);

	/**
    * @brief
    * �ر�һ�������ڴ�
    * ��windows����ϵͳ�У�����򿪴������ڹرմ������ڴ潫������
    * ��linux����ϵͳ�У� ��ֱ�ӱ�����
    * @param shm : �����ڴ�Ľṹ��
    * @return VOID
    */
    VOID  SDUnAttachShm( SShmem * shm );

    /**
    * @brief
    * �ر�һ�������ڴ�
    * ��windows����ϵͳ�У�����򿪴������ڹرմ������ڴ潫������
    * ��linux����ϵͳ�У� ��ֱ�ӱ�����
    * @param shm : �����ڴ�Ľṹ��
    * @return VOID
    */
    VOID  SDCloseShmem( SShmem * shm );

	/**
    * @brief
    * �ر�һ�������ڴ�
    * ������linux�� �����ڴ�ֱ�ӱ�����
    * @return VOID
    */
    VOID  SDCloseShmemByPath(CHAR* pszFilePath, UINT32 dwSize);

    /**
    * @brief
    * ����һ�������ڴ���
    */
    class CSDShmem
    {
    public:
        CSDShmem();

        /**
        * @brief
        * ��һ�������ڴ�
        * @param pszFileName : �ļ�·��
        * @return ָ�����ڴ��ָ��
        */
        VOID *  Open( const CHAR * pszFileName );

        /**
        * @brief
        * ����һ�������ڴ�
        * @param pszFileName : �ļ�·��
        * @param size : �ļ���С
        * @return ָ�����ڴ��ָ��
        */
        VOID *  Create( const CHAR * pszFileName, UINT64 size );

        /**
        * @brief
        * �رչ����ڴ�
        * @return VOID
        */
        VOID  Close();

        /**
        * @brief
        * ��ȡ�����ڴ���
        * @return �����ڴ���
        */
        SDHANDLE GetHandle();

    private:
        SShmem m_shm;
    };

    /** @} */
}//

#endif


