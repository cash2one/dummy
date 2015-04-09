#include "stdafx.h"
#include "vscoder.h"
#include "vscoderDlg.h"
#include "paraminfo.h"
#include "java/javaloader.h"
#include "java/javamaker.h"
#include "as/ascompiler.h"
#include "compiler.h"


BEGIN_MESSAGE_MAP(CCoderApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CCoderApp::CCoderApp()
{
}

CCoderApp theApp;

SDBOOL CCoderApp::InitInstance()
{
	AfxEnableControlContainer();
#ifdef _AFXDLL
	Enable3dControls();			
#else
	Enable3dControlsStatic();
#endif

	AfxInitRichEdit2() ;
#ifdef _GENERATE_DLL_
	return TRUE;
#else
    if (__argc > 1)
    {
        RunOnConsole();
        PostQuitMessage(1);
        return FALSE;
    }
    else
    {
		CCoderDlg dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();
    }
	exit(0);
	return FALSE;
#endif
}

void CCoderApp::RunOnConsole()
{
    CCoderParamInfo& oParamInfo = CCoderParamInfo::Instance();
    BOOL bRet = oParamInfo.ParseParam(__argc, __argv);
    if (!bRet)
    {
		MessageBox(NULL, "���������벻�ԣ�������/h�鿴����", "����", MB_OK);
		return;
	}
    if (oParamInfo.m_bHelp)
    {
		const char* pszHelpString = "Usage: coder.exe type /CONFIG ConfigFile /OUT OutputDir [/ENDN] [/CLI]\n"	\
			"Sample: coder.exe /CPP /CONFIG proto.xml /OUT d:\\SampleOuput /NET UTF-8 /host UTF-16LE /ENDN\n"	\
			"type    /JAVA, /CPP, /AS\n"
			"charset /NET, /HOST\n"
			"/S        donot show message box\n";
        MessageBox(NULL, pszHelpString, "Usage", MB_OK);
        return;
    }

    if (oParamInfo.m_bCPP)
    {
        // only support charset conversion mode
		CString str;
		str.Format("����ID:%d ����ID:%d", oParamInfo.m_nCharsetNet, oParamInfo.m_nCharsetHost);
        CCompiler oCompiler(1, oParamInfo.m_nCharsetNet, oParamInfo.m_nCharsetHost);

        CString outName = CParser::GetNameFromConfig(oParamInfo.m_strConfigFullName.GetBuffer());
        outName = strlwr((char*)outName.GetBuffer());
        
        oCompiler.SetHFilePath(oParamInfo.m_strOutputPath+outName+".h");
	    oCompiler.SetCppFilePath(oParamInfo.m_strOutputPath+outName+".cpp") ;

        m_bCompare = FALSE;
        g_emCharSetHost = (emCharSet)oParamInfo.m_nCharsetHost;

        if (!oCompiler.Compile(oParamInfo.m_strConfigFullName, oParamInfo.m_bCliEnDe, oParamInfo.m_bSaveEnDe ))
        {
            if (!oParamInfo.m_bSilence)
            {
                MessageBox(NULL, oCompiler.GetErrMsg()+"����·����"+oParamInfo.m_strConfigFullName, "����", MB_OK);
            }
        }
        else
        {
			//�ɹ�������ֱ�ӽ���
        }
    }

    if (oParamInfo.m_bAS)
    {
	    CASCompiler asCompiler;
	    asCompiler.SetOutPutPath(oParamInfo.m_strOutputPath);
	    if (false == asCompiler.Compile(oParamInfo.m_strConfigFullName))
	    {
            if (!oParamInfo.m_bSilence)
            {
                MessageBox(NULL, asCompiler.GetErrString(), "����", MB_OK);
            }
	    }
        else
        {
            if (!oParamInfo.m_bSilence)
            {
                MessageBox(NULL, "Compile OK!", "��Ϣ", MB_OK);
            }
        }
    }

    if (oParamInfo.m_bJAVA)
    {
        CJavaLoader javaLoader;
        if (!javaLoader.Load(oParamInfo.m_strConfigFullName))
        {
            if (!oParamInfo.m_bSilence)
            {
                MessageBox(NULL, javaLoader.GetErrString(), "����", MB_OK);
            }
        }
        else
        {
            CJavaMaker javaMaker;
            if (!javaMaker.Make(&javaLoader, oParamInfo.m_strOutputPath))
            {
                if (!oParamInfo.m_bSilence)
                {
                    MessageBox(NULL, javaMaker.GetErrString(), "����", MB_OK);
                }
            }
            else
            {
                if (!oParamInfo.m_bSilence)
                {
                    MessageBox(NULL, "Compile OK!", "��Ϣ", MB_OK);
                }
            }
        }
    }
}

#ifdef _GENERATE_DLL_

#define  CODER_NAME        "Э������"

stSDMemuItem* g_pstSDMemuItem  = NULL ;

extern "C" PLUGIN_DECLDIR char* SDGetModuleName()
{
	return CODER_NAME ;
}

extern "C" PLUGIN_DECLDIR bool InitModule()
{
	g_pstSDMemuItem = new stSDMemuItem[3];
	memset(g_pstSDMemuItem,0,sizeof(stSDMemuItem)) ;
	g_pstSDMemuItem[0].dwFlag = MF_STRING | MF_ENABLED ;
	g_pstSDMemuItem[0].dwCommandId = 5000 ;
	strcpy(g_pstSDMemuItem[0].szName,"c++") ;

	g_pstSDMemuItem[1].dwFlag = MF_STRING | MF_ENABLED ;
	g_pstSDMemuItem[1].dwCommandId = 5001 ;
	strcpy(g_pstSDMemuItem[1].szName,"JAVA") ;

	g_pstSDMemuItem[2].dwFlag = MF_STRING | MF_ENABLED ;
	g_pstSDMemuItem[2].dwCommandId = 5002 ;
	strcpy(g_pstSDMemuItem[2].szName,"AS") ;
	return true ;
}


extern "C" PLUGIN_DECLDIR int GetModuleMenuCount()
{

	return 3 ;
}

extern "C"   void PLUGIN_DECLDIR ExcuteCommand(DWORD dwCommandId)
{
	//����2��״̬���

	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	CCoderDlg dlg;

	dlg.DoModal();


}

extern "C"  bool PLUGIN_DECLDIR GetModuleMenuInfoCommandId(int nNumber,DWORD& dwCommandId,DWORD& dwFlag,char* szName)
{
	if (nNumber < 3 && nNumber >= 0 )
	{
		dwFlag = g_pstSDMemuItem[nNumber].dwFlag;
		dwCommandId = g_pstSDMemuItem[nNumber].dwCommandId ;
		strcpy(szName,g_pstSDMemuItem[nNumber].szName) ;
		return true ;
	}
	return false ;
}
#endif