
// lookupDlg.h : ͷ�ļ�
//

#pragma once
#include <map>
#include "afxcmn.h"
#include "DialogResize.h"
#include "afxwin.h"


#include "dbmgr.h"
#include "DbSetDlg.h"
#include "DialogResize.h"
#include "User.h"
#include "EditDlg.h"
#include <map>




// ClookupDlg �Ի���
class CLookupDlg : public CDialogResize
{
// ����
public:
    CLookupDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
    enum { IDD = IDD_LOOKUP_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
    HICON m_hIcon;
    BOOL m_bInitialized;

    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
    DECLARE_DLGRESIZE_MAP;


public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnClose();
    afx_msg void OnTvnSelchangedBasePlayTree(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg LRESULT OnKickIdle(WPARAM wParam, LPARAM lParam);

private:
    void DeleteTreeNode(HTREEITEM hTreeItem, BOOL bMySelf = TRUE);
    void ExpandTreeNode(HTREEITEM hTreeItem);

	HTREEITEM FindItem(HTREEITEM hRoot, LPSTR lpszText);

private:
	BOOL InitTree();


private:

    void MoveChilds();
    void ActivatePage(int nIndex);
public:
    afx_msg void OnBnClickedOk();
private:
    CTreeCtrl		m_hDbTree;
	CUserManager		m_oUserManager;
	CEditDlg			m_oTraceDlg;

private:
	BOOL				m_bFlag;
public:
	afx_msg void OnBnClickedExec();
	afx_msg void OnNMRClickDbTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAddDb();
	afx_msg void OnEditDb();
	afx_msg void OnOpenConn();
	afx_msg void OnCloseComm();
};


