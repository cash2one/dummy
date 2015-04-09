///<------------------------------------------------------------------------------
//< @file:   pkconfig.h
//< @author: hongkunan
//< @date:   2014��1��2�� 16:8:55
//< @brief:  ���ս�������������ļ�������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pkconfig_h_
#define _pkconfig_h_

#include <sdutil.h>
#include <sdframework.h>
#include <sdsingleton.h>
#include <sdxmlfile.h>
#include <sddb.h>

using namespace std;
using namespace SGDP;

// ���ս�������������ļ�
class CPKConfig
{
public:
    DECLARE_SINGLETON(CPKConfig);

public:
    BOOL Init(const TCHAR* pszConfig);
    VOID UnInit();


public:

    /**
    * @brief ��ȡ���ݿ�������Ϣ
    * @param pszHost : ���ݿ������IP��ַ
    * @param wPort : ���ݿ�������˿�
    * @param pszLoginName : ���ݿ��ʺ�
    * @param pszPassword : ���ݿ�����
    * @param pszDBName : ���ݿ�����
    * @param pszCharacterSet : �ַ���
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL GetDBConfig(CHAR* pszHost, UINT16 &wPort, CHAR* pszLoginName, CHAR* pszPassword, CHAR* pszDBName, CHAR* pszCharacterSet, CHAR* pszUnixSocket);

    /**
     * @brief ��ȡ�������ݿ��ļ���ַ
     * @param pszPath : �������ݿ��ļ���ַ������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL    GetConfigDataPath(CHAR* pszPath);

    tstring  GetConfigFile();

    BOOL	GetCfgDBAccount( SGDP::SDDBAccount& DBAccount );
    UINT32	GetCfgPoolCoreSize(){ return 1; }
    UINT32	GetCfgPoolMaxSize(){ return 1; }

    string GetSpeCfgTablePrefix()
    {
        return m_strSpeCfgTablePrefix;
    }

    UINT64 &GetServerOpentTime()
    {
        return m_qwServerOpentTime;
    }

protected:
    CPKConfig();
    ~CPKConfig();

    BOOL _LoadCfg(CSDXMLFile* poConfig);
    BOOL _LoadGateListenerInfo(CSDXMLFile* poSDXMLFile);

private:
    BOOL CopyDBAccountInfo( SGDP::SDDBAccount &DBAccountDst, const SGDP::SDDBAccount &DBAccountSrc );
    BOOL LoadDBConnInfo( CSDXMLNode &oNode, SGDP::SDDBAccount &oDBAccount );

private:
    CHAR m_szDBConfigPath[MAX_PATH];
    CHAR m_szConfigFile[MAX_PATH];

    //app��ֵ�����ݿ������Ϣ
    SGDP::SDDBAccount  m_oPayDBAccount; //�ɼ����ݿ���˺���Ϣ
    UINT32	m_dwPayPoolCoreSize;
    UINT32  m_dwPayPoolMaxSize;

    SGDP::SDDBAccount  m_oCfgDBAccount; //�������ݿ���˺���Ϣ

    string	m_strSpeCfgTablePrefix;//��ָ���ñ�ǰ׺
    UINT64	m_qwServerOpentTime;//����ʱ��
};

#endif //_pkconfig_h_