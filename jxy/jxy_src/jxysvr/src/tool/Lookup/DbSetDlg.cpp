// DbSetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lookup.h"
#include "DbSetDlg.h"
#include "afxdialogex.h"


// CDbSetDlg �Ի���

IMPLEMENT_DYNAMIC(CDbSetDlg, CDialogEx)

CDbSetDlg::CDbSetDlg(CWnd* pParent /*=NULL*/, CString	strConnName ,
                     CString	strHostName,
                     CString	strDBName,
                     CString	strPwd,
                     CString	strUser,
                     int		nPort,
                     CString	strChartSet)
    : CDialogResize(CDbSetDlg::IDD, pParent)
    , m_strConnName(strConnName)
    , m_strHostName(strHostName)
    , m_strDBName(strDBName)
    , m_strPwd(strPwd)
    , m_strUser(strUser)
    , m_nPort(nPort)
    , m_strChartSet(strChartSet)
{

}

CDbSetDlg::~CDbSetDlg()
{
}

void CDbSetDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogResize::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_IP, m_strHostName);
    DDX_Text(pDX, IDC_EDIT_NAME, m_strDBName);
    DDX_Text(pDX, IDC_EDIT_PWD, m_strPwd);
    DDX_Text(pDX, IDC_EDIT_USER, m_strUser);
    DDX_Text(pDX, IDC_EDIT_CHARTSET, m_strChartSet);
    DDX_Text(pDX, IDC_EDIT_CONNECT, m_strConnName);
    DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
}


BEGIN_MESSAGE_MAP(CDbSetDlg, CDialogResize)
    ON_BN_CLICKED(IDOK, &CDbSetDlg::OnOK)
    ON_WM_SIZE()
END_MESSAGE_MAP()


BEGIN_DLGRESIZE_MAP(CDbSetDlg)
END_DLGRESIZE_MAP()
// CDbSetDlg ��Ϣ�������


void CDbSetDlg::OnOK()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateData();
    CDialogResize::OnOK();
}


void CDbSetDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogResize::OnSize(nType, cx, cy);

    // TODO: �ڴ˴������Ϣ����������
}
