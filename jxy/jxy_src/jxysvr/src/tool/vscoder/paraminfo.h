#pragma once
#include "afxwin.h"
#include "singleton.h"

class CCoderParamInfo
	: public Singleton<CCoderParamInfo>
{
public:
    enum
    {
        JAVA = 1,
        AS   = 2,
        CPP  = 3
    };

public:
    CCoderParamInfo();
    ~CCoderParamInfo();
    BOOL ParseParam(int iArgNum, char** pszParams);

    BOOL m_bJAVA;
    BOOL m_bAS;
    BOOL m_bCPP;					// c++��ʽ��
    BOOL m_bConfig;					// xml�ļ���
    BOOL m_bOutput;					// ���·��
    BOOL m_bSilence;
    BOOL m_bHelp;
    BOOL m_bSaveEnDe;				// �Ƿ����ɱ������뷽��
    BOOL m_bCliEnDe;				// �Ƿ����ɿͻ��˸�ʽ����
    CString m_strConfigFullName;
    CString m_strOutputPath;
    CString m_strCharsetNet;
    CString m_strCharsetHost;
    INT32 m_nCharsetNet;
    INT32 m_nCharsetHost;

	INT32 m_nSidOffset;

};
