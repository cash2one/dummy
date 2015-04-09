#pragma once
#include "resource.h"
#include "DialogResize.h"

// CDbSetDlg �Ի���

class CDbSetDlg : public CDialogResize
{
    DECLARE_DYNAMIC(CDbSetDlg)

public:
    CDbSetDlg(CWnd* pParent = NULL, CString	strConnName = _T(""),
              CString	strHostName = _T(""),
              CString	strDBName = _T(""),
              CString	strPwd = _T(""),
              CString	strUser = _T(""),
              int		nPort = 3306,
              CString	strChartSet =  _T("utf8"));   // ��׼���캯��
    virtual ~CDbSetDlg();

// �Ի�������
    enum { IDD = IDD_DIALOG_DBSET };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    DECLARE_MESSAGE_MAP()
    DECLARE_DLGRESIZE_MAP;

    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnOK();
public:
    CString	m_strConnName;
    CString	m_strHostName;
    CString	m_strDBName;
    CString	m_strPwd;
    CString	m_strUser;
    int		m_nPort;
    CString	m_strChartSet;
};
