#include "stdafx.h"
#include "Coder.h"
#include "CoderDlg.h"
#include "compiler.h"

#include "java/javaloader.h"
#include "java/javamaker.h"

#include "tinyxml.h"

#include "as/ascompiler.h"
#include "charset.h"

CString	GetRootPath()
{
	CString strRoot;
	GetModuleFileName(NULL,strRoot.GetBuffer(MAX_PATH),MAX_PATH);
	strRoot.ReleaseBuffer();
	strRoot = strRoot.Left(strRoot.ReverseFind('\\'));
	return strRoot;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:

	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

CCoderDlg::CCoderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCoderDlg::IDD, pParent)
	, m_strCppFilePath(_T(""))
	, m_strHFilePath(_T(""))
	, m_bCpp(FALSE)
	, m_bAs(FALSE)
    , m_bJava(FALSE)
	, m_strAsPath(_T(""))
    , m_strJavaPath(_T(""))
    , m_strType(_T(""))
    , m_strNetCharset(_T(""))
    , m_strHostCharset(_T(""))
    , m_nType(1)
    , m_nCharsetNet(-1)
    , m_nCharsetHost(-1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCoderDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDITOUTPUT, m_edtHFilePath);
    DDX_Control(pDX, IDC_EDITOUTPUT2, m_edtCppFilePath);
    DDX_Text(pDX, IDC_EDITOUTPUT2, m_strCppFilePath);
    DDX_Control(pDX, IDC_RICHEDIT_LOGS, m_richLogs);
    DDX_Text(pDX, IDC_EDITOUTPUT, m_strHFilePath);
    DDX_Control(pDX, IDC_EDITFILE, m_edtLoadFile);
    DDX_Check(pDX, IDC_CHECK_CPP, m_bCpp);
    DDX_Check(pDX, IDC_CHECK_AS, m_bAs);
    DDX_Check(pDX, IDC_CHECK_JAVA, m_bJava);
    DDX_Text(pDX, IDC_EDIT_AS_OUTPUT, m_strAsPath);
    DDX_Control(pDX, IDC_EDIT_AS_OUTPUT, m_edtAsPath);
    DDX_Control(pDX, IDC_EDIT_JAVA_OUTPUT, m_edtJavaPath);
}

BEGIN_MESSAGE_MAP(CCoderDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNLOAD, OnBtnload)
	ON_BN_CLICKED(IDC_BTNCOMPILE, OnBtncompile)
	ON_BN_CLICKED(IDC_BTNOUTPATH, OnBtnoutpath)
	ON_MESSAGE(WM_COMMAND_LOG_MSG,OnLogMsg)
	ON_BN_CLICKED(IDC_BTNOUTPATH2, &CCoderDlg::OnBnClickedBtnoutpath2)
	ON_BN_CLICKED(IDC_CHECK_CPP, &CCoderDlg::OnBnClickedCheckCpp)
	ON_BN_CLICKED(IDC_CHECK_AS, &CCoderDlg::OnBnClickedCheckAs)
	ON_BN_CLICKED(IDC_BTNOUT_AS_PATH, &CCoderDlg::OnBnClickedBtnoutAsPath)
    ON_BN_CLICKED(IDC_CHECK_JAVA, &CCoderDlg::OnBnClickedCheckJava)
    ON_BN_CLICKED(IDC_BTNOUT_JAVA_PATH, &CCoderDlg::OnBnClickedBtnoutJavaPath)
    ON_CBN_SELCHANGE(IDC_COMBO_TYPE, &CCoderDlg::OnCbnSelchangeComboType)
    ON_CBN_SELCHANGE(IDC_COMBO_NET, &CCoderDlg::OnCbnSelchangeComboNet)
    ON_CBN_SELCHANGE(IDC_COMBO_HOST, &CCoderDlg::OnCbnSelchangeComboHost)
END_MESSAGE_MAP()

SDBOOL CCoderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);	
	LoadPath();
	GetDlgItem(IDC_BTNOUTPATH)->EnableWindow(m_bCpp) ;
	GetDlgItem(IDC_BTNOUTPATH2)->EnableWindow(m_bCpp) ;

	GetDlgItem(IDC_EDITOUTPUT)->EnableWindow(m_bCpp) ;
	GetDlgItem(IDC_EDITOUTPUT2)->EnableWindow(m_bCpp) ;
	GetDlgItem(IDC_EDIT_AS_OUTPUT)->EnableWindow(m_bAs) ;
	GetDlgItem(IDC_BTNOUT_AS_PATH)->EnableWindow(m_bAs) ;

    GetDlgItem(IDC_EDIT_JAVA_OUTPUT)->EnableWindow(m_bJava) ;
	GetDlgItem(IDC_BTNOUT_JAVA_PATH)->EnableWindow(m_bJava) ;

    //CComboBox* poComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TYPE);
	//if (poComboBox)
    //{
    //    poComboBox->AddString(_T("tstring"));
    //    poComboBox->AddString(_T("ԭ������"));
    //}

    CComboBox* poComboBoxNet = (CComboBox*)GetDlgItem(IDC_COMBO_NET);
    CComboBox* poComboBoxHost = (CComboBox*)GetDlgItem(IDC_COMBO_HOST);
    for (int i = 0; i < nCharset; i++)
    {
        poComboBoxNet->AddString(szCharset[i]);
        poComboBoxHost->AddString(szCharset[i]);
    }

    // Read config file to config combobox for charset

	return TRUE; 
}

void CCoderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CCoderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CCoderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCoderDlg::OnBtnload() 
{
	CFileDialog dlgFile(TRUE, "*.xml", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
						"XML Files (*.xml)|*.xml||", this);

	if(IDOK == dlgFile.DoModal())
	{
		CString strFile = dlgFile.GetPathName() ;
		m_edtLoadFile.SetWindowText(strFile);
		CString strPath = strFile.Left(strFile.ReverseFind('\\')) ;
		TiXmlDocument* pDocument = new TiXmlDocument ;
		if (pDocument->LoadFile((const char*)strFile.GetBuffer()))
		{
			TiXmlElement* pRootElement = pDocument->RootElement() ;
			if (pRootElement)
			{
				char* cpName = (char*)pRootElement->Attribute("name") ;
				if (cpName)
				{
					m_strOutName = cpName ;
					GetDlgItem(IDC_EDITFILE)->SetWindowText(strFile);
					m_edtHFilePath.SetWindowText(strPath + CString("\\") + CString(strlwr(cpName))+ CString(".h")) ;
					m_edtCppFilePath.SetWindowText(strPath + CString("\\") + CString(strlwr(cpName))+ CString(".cpp")) ;

				}
			}
		}
		delete pDocument ;		
	}
}

void CCoderDlg::OnBtncompile() 
{
	GetDlgItem(IDC_EDITFILE)->GetWindowText(m_strLoadFile);
	UpdateData() ;
	if (m_bCpp)
	{
		g_nCharsetHost = m_nCharsetHost;
		CCompiler oCompiler(m_nType, m_nCharsetNet, m_nCharsetHost);	
		oCompiler.SetHFilePath(m_strHFilePath);
		oCompiler.SetCppFilePath(m_strCppFilePath) ;
		oCompiler.Compile(m_strLoadFile);
		AppendToLog(oCompiler.GetErrMsg()+"\n",RGB(255,100,0));
		if (m_strLoadFile.IsEmpty() && m_strAsPath.IsEmpty())
		{
			AppendToLog("Error : path not set!\n",RGB(255,100,0));
			return;
		}
	}

	if (m_bAs)
	{
		CASCompiler asCompiler;
		asCompiler.SetOutPutPath(m_strAsPath);
		if (false == asCompiler.Compile(m_strLoadFile))
		{
			AppendToLog(asCompiler.GetErrString()+"\n",RGB(255,100,0));
			return;
		}	
		else
		{
			AppendToLog("Compile Success!\n",RGB(255,100,0));
		}
	}

    if (m_bJava)
    {
        CJavaLoader javaLoader;
        if (!javaLoader.Load(m_strLoadFile))
        {
            AppendToLog(javaLoader.GetErrString()+"\n",RGB(255,100,0));
			return;
        }

        CJavaMaker javaMaker;
        if (!javaMaker.Make(&javaLoader, m_strJavaPath))
        {
            AppendToLog(javaMaker.GetErrString()+"\n",RGB(255,100,0));
            return;
        }
        else
        {
            AppendToLog("Compile Success!\n",RGB(255,100,0));
        }
    }
}

void CCoderDlg::OnBtnoutpath() 
{
	BROWSEINFO bInfo;
	memset(&bInfo, '\0', sizeof(BROWSEINFO));
	bInfo.hwndOwner = GetSafeHwnd();
	bInfo.lpszTitle = "ѡ�������Ŀ¼";
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pidl;
	pidl = ::SHBrowseForFolder(&bInfo);
	if(pidl == NULL)
		return;
	char szPath[MAX_PATH];
	szPath[0] = '\0';
	if(SHGetPathFromIDList(pidl, szPath) == FALSE)
		return;
	//���·����'\'��β������ȥ��
	size_t n = strlen(szPath);
	if('\\' == szPath[n-1])
		szPath[n-1] = '\0';

	m_edtHFilePath.SetWindowText(szPath+CString("\\")+strlwr((char*)m_strOutName.GetBuffer())+CString(".h"));
}

void CCoderDlg::LoadPath()
{
	CString strRoot = GetRootPath();
	TiXmlDocument* pDocument = new TiXmlDocument ;
	if(false == pDocument->LoadFile(strRoot + "\\config.xml"))
		return;
	TiXmlElement* pRootElement = pDocument->RootElement() ;
	if (NULL == pRootElement)
	{
		delete pDocument ;
		return ;
	}

	if(strcmp(pRootElement->Value(),"config") != 0)
	{
		delete pDocument ;
		return;
	}
	TiXmlElement* pLoadElement = pRootElement->FirstChildElement("load") ;
	if(NULL == pLoadElement)
	{
		delete pDocument ;
		return;
	}
	m_strLoadFile = (char*)pLoadElement->Attribute("file");
	m_edtLoadFile.SetWindowText(m_strLoadFile);
	CString strFile = m_strLoadFile;
	CString strPath = strFile.Left(strFile.ReverseFind('\\')) ;
	TiXmlDocument* pParseDocument = new TiXmlDocument ;
	if (pParseDocument->LoadFile((const char*)strFile.GetBuffer()))
	{
		TiXmlElement* pParseElement = pParseDocument->RootElement() ;
		if (pParseElement)
		{
			char* cpName = (char*)pParseElement->Attribute("name") ;
			if (cpName)
			{
				m_strOutName = cpName ;
			}
		}
	}
	delete pParseDocument ;		

	TiXmlElement* pOutElement = pRootElement->FirstChildElement("output") ;
	if(NULL == pOutElement)
	{
		delete pDocument ;
		return;
	}
	while(pOutElement)
	{
		char* cpName = (char*)pOutElement->Attribute("name") ;
		if (cpName )
		{
			if (strcmp(cpName,"c++") == 0 )
			{
				TiXmlElement* pHeadElement = pOutElement->FirstChildElement("head") ;
				if (pHeadElement)
				{
					m_strHFilePath = pHeadElement->Attribute("file") == NULL ? "" : pHeadElement->Attribute("file") ;
					m_edtHFilePath.SetWindowText(m_strHFilePath) ;
				}
				TiXmlElement* pCppElement = pOutElement->FirstChildElement("cpp") ;
				if (pCppElement)
				{
					m_strCppFilePath = pCppElement->Attribute("file") == NULL ? "" : pCppElement->Attribute("file") ;
					m_edtCppFilePath.SetWindowText(m_strCppFilePath) ;
				}
				char* cpOpen = (char*)pOutElement->Attribute("open") ;
				if (cpOpen)
				{
					m_bCpp = atoi(cpOpen) ;
				}

				CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_CPP) ;
				if (pBtn)
				{
					pBtn->SetCheck(m_bCpp) ;
				}

			}
			else if (strcmp(cpName,"as") == 0)
			{
				char* cpOpen = (char*)pOutElement->Attribute("open") ;
				if (cpOpen)
				{
					m_bAs = atoi(cpOpen) ;
				}

				char* cpFile = (char*)pOutElement->Attribute("file") ;
				if (cpFile)
				{
					m_strAsPath = cpFile ;
					m_edtAsPath.SetWindowText(m_strAsPath);
				}

				CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_AS) ;
				if (pBtn)
				{
					pBtn->SetCheck(m_bAs) ;
				}
			}
            else if (strcmp(cpName,"java") == 0)
			{
				char* cpOpen = (char*)pOutElement->Attribute("open") ;
				if (cpOpen)
				{
					m_bJava = atoi(cpOpen) ;
				}

				char* cpFile = (char*)pOutElement->Attribute("file") ;
				if (cpFile)
				{
					m_strJavaPath = cpFile ;
					m_edtJavaPath.SetWindowText(m_strJavaPath);
				}

				CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_JAVA) ;
				if (pBtn)
				{
					pBtn->SetCheck(m_bJava) ;
				}
			}
		}
		pOutElement = pOutElement->NextSiblingElement("output") ;
	}

	delete pDocument ;
}

LRESULT CCoderDlg::OnLogMsg(WPARAM wParam ,LPARAM lParam)
{
	CHAR* cpMsg = (char*)lParam ;
	if (cpMsg)
	{
		switch((LOG_LEVEL)wParam)
		{
		case LOG_WARNING:
			AppendToLog(cpMsg, RGB(0, 120, 0));
			break;
		case LOG_ERROR:
			AppendToLog(cpMsg, RGB(255, 0, 0));
			break;
		case LOG_CRITIL:
			AppendToLog(cpMsg, RGB(255, 100, 0));
			break;
		case LOG_INFO:
			AppendToLog(cpMsg, RGB(0, 0, 0));
			break;
		default:
			break;
		}
	}
	return 0 ;
}


void CCoderDlg::SavePath()
{
	UpdateData() ;
	GetDlgItem(IDC_EDITFILE)->GetWindowText(m_strLoadFile);

	CString strRoot = GetRootPath();
	DeleteFile(strRoot + "\\config.xml") ;
	TiXmlDocument* pDocument = new TiXmlDocument ;
	TiXmlElement rootElement("config") ;
	TiXmlElement loadElement("load") ;
	loadElement.SetAttribute("file",(const char*)m_strLoadFile.GetBuffer()) ;
	TiXmlElement outElement("output") ;
	outElement.SetAttribute("name","c++");
	outElement.SetAttribute("open",m_bCpp);
	TiXmlElement headElement("head");
	headElement.SetAttribute("file",(const char*)m_strHFilePath.GetBuffer()) ;
	outElement.InsertEndChild(headElement);
	TiXmlElement cppElement("cpp");
	cppElement.SetAttribute("file",(const char*)m_strCppFilePath.GetBuffer()) ;
	outElement.InsertEndChild(cppElement);


	TiXmlElement asOutElement("output") ;
	asOutElement.SetAttribute("name","as");
	asOutElement.SetAttribute("file",(const char*)m_strAsPath.GetBuffer()) ;
	asOutElement.SetAttribute("open",m_bAs);

    TiXmlElement javaOutElement("output") ;
	javaOutElement.SetAttribute("name","java");
	javaOutElement.SetAttribute("file",(const char*)m_strJavaPath.GetBuffer()) ;
	javaOutElement.SetAttribute("open",m_bJava);

	rootElement.InsertEndChild(loadElement) ;
	rootElement.InsertEndChild(outElement);
	rootElement.InsertEndChild(asOutElement);
    rootElement.InsertEndChild(javaOutElement);

	CString strFile = strRoot + "\\config.xml" ;
	pDocument->InsertEndChild(rootElement) ;
	pDocument->SaveFile((const char*)strFile.GetBuffer());
	delete pDocument ;
}

void CCoderDlg::OnCancel()
{
	SavePath();	
	CDialog::OnCancel();
}
UINT32 CCoderDlg::AppendToLog(CString str, COLORREF color)
{
	UINT32 nOldLines = 0, nNewLines = 0, nScroll = 0;
	UINT32 nInsertionPoint = 0;
	CHARFORMAT cf;

	// Save number of lines before insertion of new text
	nOldLines		= m_richLogs.GetLineCount();

	// Initialize character format structure
	cf.cbSize		= sizeof(CHARFORMAT);
	cf.dwMask		= CFM_COLOR;
	cf.dwEffects	= 0;	// To disable CFE_AUTOCOLOR
	cf.crTextColor	= color;

	// Set insertion point to end of text
	nInsertionPoint = m_richLogs.GetWindowTextLength();
	m_richLogs.SetSel(nInsertionPoint, -1);

	//  Set the character format
	m_richLogs.SetSelectionCharFormat(cf);

	// Replace selection. Because we have nothing selected, this will simply insert
	// the string at the current caret position.
	m_richLogs.ReplaceSel(str);

	// Get new line count
	nNewLines		= m_richLogs.GetLineCount();

	// Scroll by the number of lines just inserted
	nScroll			= nNewLines - nOldLines;
	m_richLogs.LineScroll(nScroll);

	return 0;
}
void CCoderDlg::OnBnClickedBtnoutpath2()
{
	BROWSEINFO bInfo;
	memset(&bInfo, '\0', sizeof(BROWSEINFO));
	bInfo.hwndOwner = GetSafeHwnd();
	bInfo.lpszTitle = "ѡ�������Ŀ¼";
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pidl;
	pidl = ::SHBrowseForFolder(&bInfo);
	if(pidl == NULL)
		return;
	CHAR szPath[MAX_PATH];
	szPath[0] = '\0';
	if(SHGetPathFromIDList(pidl, szPath) == FALSE)
		return;
	//���·����'\'��β������ȥ��
	size_t n = strlen(szPath);
	if('\\' == szPath[n-1])
		szPath[n-1] = '\0';

	m_edtCppFilePath.SetWindowText(szPath+CString("\\")+strlwr((char*)m_strOutName.GetBuffer())+CString(".cpp"));
}

void CCoderDlg::OnBnClickedCheckCpp()
{
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_CPP) ;
	if (pBtn)
	{
		if (pBtn->GetCheck())
		{
			m_bCpp = TRUE ;
		}
		else
			m_bCpp = FALSE ;

		GetDlgItem(IDC_BTNOUTPATH)->EnableWindow(m_bCpp) ;
		GetDlgItem(IDC_BTNOUTPATH2)->EnableWindow(m_bCpp) ;

		GetDlgItem(IDC_EDITOUTPUT)->EnableWindow(m_bCpp) ;
		GetDlgItem(IDC_EDITOUTPUT2)->EnableWindow(m_bCpp) ;
	}


}

void CCoderDlg::OnBnClickedCheckAs()
{
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_AS) ;
	if (pBtn)
	{
		if (pBtn->GetCheck())
		{
			m_bAs = TRUE ;
		}
		else
			m_bAs = FALSE ;

		GetDlgItem(IDC_EDIT_AS_OUTPUT)->EnableWindow(m_bAs) ;
		GetDlgItem(IDC_BTNOUT_AS_PATH)->EnableWindow(m_bAs) ;
	}
}

void CCoderDlg::OnBnClickedBtnoutAsPath()
{
	BROWSEINFO bInfo;
	memset(&bInfo, '\0', sizeof(BROWSEINFO));
	bInfo.hwndOwner = GetSafeHwnd();
	bInfo.lpszTitle = "ѡ�������Ŀ¼";
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pidl;
	pidl = ::SHBrowseForFolder(&bInfo);
	if(pidl == NULL)
		return;
	CHAR szPath[MAX_PATH];
	szPath[0] = '\0';
	if(SHGetPathFromIDList(pidl, szPath) == FALSE)
		return;
	//���·����'\'��β������ȥ��
	size_t n = strlen(szPath);
	if('\\' == szPath[n-1])
		szPath[n-1] = '\0';

	m_edtAsPath.SetWindowText(CString(szPath)+"\\");
}

void CCoderDlg::OnBnClickedCheckJava()
{
    CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_JAVA) ;
	if (pBtn)
	{
		if (pBtn->GetCheck())
		{
			m_bJava = TRUE;
		}
		else
        {
			m_bJava = FALSE;
        }

		GetDlgItem(IDC_EDIT_JAVA_OUTPUT)->EnableWindow(m_bJava) ;
		GetDlgItem(IDC_BTNOUT_JAVA_PATH)->EnableWindow(m_bJava) ;
	}
}

void CCoderDlg::OnBnClickedBtnoutJavaPath()
{
    BROWSEINFO bInfo;
	memset(&bInfo, '\0', sizeof(BROWSEINFO));
	bInfo.hwndOwner = GetSafeHwnd();
	bInfo.lpszTitle = "ѡ�������Ŀ¼";
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pidl;
	pidl = ::SHBrowseForFolder(&bInfo);
	if(pidl == NULL)
		return;
	CHAR szPath[MAX_PATH];
	szPath[0] = '\0';
	if(SHGetPathFromIDList(pidl, szPath) == FALSE)
		return;
	//���·����'\'��β������ȥ��
	size_t n = strlen(szPath);
	if('\\' == szPath[n-1])
		szPath[n-1] = '\0';

    m_strJavaPath = CString(szPath)+"\\";
	m_edtJavaPath.SetWindowText(CString(szPath)+"\\");
}

void CCoderDlg::OnCbnSelchangeComboType()
{
    /*CComboBox* poComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TYPE);
	if (poComboBox)
    {
        INT32 nSel = poComboBox->GetCurSel();

        CComboBox* poComboBoxNet = (CComboBox*)GetDlgItem(IDC_COMBO_NET);
        CComboBox* poComboBoxHost = (CComboBox*)GetDlgItem(IDC_COMBO_HOST);

        if (0 == nSel) // tstring
        {            
            poComboBoxNet->EnableWindow(FALSE);            
            poComboBoxHost->EnableWindow(FALSE);
        }
        else // ԭ������
        {
            poComboBoxNet->EnableWindow(TRUE);            
            poComboBoxHost->EnableWindow(TRUE);
        }

        m_nType = nSel;
    }*/
}

void CCoderDlg::OnCbnSelchangeComboNet()
{
    CComboBox* poComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_NET);
	if (poComboBox)
    {
        INT32 nSel = poComboBox->GetCurSel();
        if (0 <= nSel)
        {
            m_strNetCharset = szCharset[nSel];
            m_nCharsetNet   = nSel;
        }
    }
}

void CCoderDlg::OnCbnSelchangeComboHost()
{
    CComboBox* poComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_HOST);
	if (poComboBox)
    {
        INT32 nSel = poComboBox->GetCurSel();
        if (0 <= nSel)
        {
            m_strNetCharset = szCharset[nSel];
            m_nCharsetHost  = nSel;
        }
    }
}
