#pragma once


// CCheckDataDlg �Ի���

class CCheckDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckDataDlg)

public:
	CCheckDataDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckDataDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHECK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
