#pragma once
#include "protocommondata.h"
#include "DialogResize.h"

// CDriverDlg �Ի���

class CDriverDlg : public CDialogResize
{
	DECLARE_DYNAMIC(CDriverDlg)

public:
	CDriverDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDriverDlg();

// �Ի�������
	enum { IDD = IDD_DRIVER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP() DECLARE_DLGRESIZE_MAP;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedOk();

	void Init(char* _szDriverID);

private:
	CString m_strDriverID;
};
