#pragma once
#include "resource.h"


// CEditDlg �Ի���

class CEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDlg)

public:
	CEditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_strTitle;
	CString m_strPro;
	CString m_strValue;
};
