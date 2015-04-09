#pragma once

#include "resource.h"
#include "DialogResize.h"
#include "afxwin.h"
#include "ColorListBox.h"

// CEditDlg �Ի���

class CEditDlg : public CDialogResize
{
    DECLARE_DYNAMIC(CEditDlg)

public:
    CEditDlg(CWnd* pParent = NULL);   // ��׼���캯��
    virtual ~CEditDlg();

    void AddTraceLine(int nLevel, LPCTSTR pstrFormat, ...);
// �Ի�������
    enum { IDD = IDD_DIALOG_EDIT };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
    virtual BOOL OnInitDialog();
    afx_msg void OnSize(UINT nType, int cx, int cy);

    LRESULT OnAddTraceLine(WPARAM, LPARAM);
    DECLARE_MESSAGE_MAP()
    DECLARE_DLGRESIZE_MAP;
public:
    CString m_strSQL;
    CColorListBox m_TraceList;

private:
    CObList m_LogQueue;
    CCriticalSection m_QueueLock;

    class CLogMsg : public CObject
    {
    public:
        CLogMsg() {};
        virtual ~CLogMsg()
        {
        };

        SYSTEMTIME m_sysTime;
        int		m_nLevel;
        CString m_strText;
    };
};
