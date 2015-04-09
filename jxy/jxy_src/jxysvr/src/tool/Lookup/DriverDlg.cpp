// DriverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Lookup.h"
#include "DriverDlg.h"
#include "afxdialogex.h"


// CDriverDlg �Ի���

IMPLEMENT_DYNAMIC(CDriverDlg, CDialogEx)

CDriverDlg::CDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialogResize(CDriverDlg::IDD, pParent)
	, m_strDriverID(_T(""))
{

}

CDriverDlg::~CDriverDlg()
{
}

void CDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogResize::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DRIVER_ID, m_strDriverID);
}


BEGIN_MESSAGE_MAP(CDriverDlg, CDialogResize)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDOK, &CDriverDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BEGIN_DLGRESIZE_MAP(CDriverDlg)
	DLGRESIZE_CONTROL(IDC_DRIVER_ID, DLSZ_SIZE_X)
	DLGRESIZE_CONTROL(IDOK, DLSZ_MOVE_X)
	DLGRESIZE_CONTROL(IDCANCEL, DLSZ_MOVE_X)
END_DLGRESIZE_MAP()

// CDriverDlg ��Ϣ�������


BOOL CDriverDlg::OnInitDialog()
{
	CDialogResize::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitResizing(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDriverDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogResize::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}


void CDriverDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CDriverDlg::Init(char* _szDriverID)
{
	m_strDriverID = _szDriverID;
}
