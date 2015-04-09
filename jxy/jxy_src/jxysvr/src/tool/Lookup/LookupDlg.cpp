
// lookupDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "dbmgr.h"
#include "DbSetDlg.h"

#include "stdafx.h"
#include "lookup.h"
#include "lookupDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogResize
{
public:
    CAboutDlg();

// �Ի�������
    enum { IDD = IDD_ABOUTBOX };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
    DECLARE_MESSAGE_MAP()
    DECLARE_DLGRESIZE_MAP;
public:
    afx_msg void OnAddDb();
};

CAboutDlg::CAboutDlg() : CDialogResize(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogResize::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogResize)
END_MESSAGE_MAP()


BEGIN_DLGRESIZE_MAP(CAboutDlg)
END_DLGRESIZE_MAP()
// ClookupDlg �Ի���




CLookupDlg::CLookupDlg(CWnd* pParent /*=NULL*/)
    : CDialogResize(CLookupDlg::IDD, pParent)
{
    m_bFlag = FALSE;
    m_bInitialized	= FALSE;
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLookupDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogResize::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_DB_TREE, m_hDbTree);
}

BEGIN_MESSAGE_MAP(CLookupDlg, CDialogResize)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_SIZE()
    ON_WM_CLOSE()
    ON_NOTIFY(TVN_SELCHANGED, IDC_DB_TREE, &CLookupDlg::OnTvnSelchangedBasePlayTree)
    ON_MESSAGE(WM_KICKIDLE, &CLookupDlg::OnKickIdle)
    ON_BN_CLICKED(IDOK, &CLookupDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDC_EXEC, &CLookupDlg::OnBnClickedExec)
    ON_NOTIFY(NM_RCLICK, IDC_DB_TREE, &CLookupDlg::OnNMRClickDbTree)
    ON_COMMAND(ID_ADD_DB, &CLookupDlg::OnAddDb)
    ON_COMMAND(ID_EDIT_DB, &CLookupDlg::OnEditDb)
    ON_COMMAND(ID_OPEN_CONN, &CLookupDlg::OnOpenConn)
    ON_COMMAND(ID_CLOSE_COMM, &CLookupDlg::OnCloseComm)
END_MESSAGE_MAP()





BEGIN_DLGRESIZE_MAP(CLookupDlg)
DLGRESIZE_CONTROL(IDOK,  DLSZ_MOVE_X )
DLGRESIZE_CONTROL(IDCANCEL,  DLSZ_MOVE_X )
DLGRESIZE_CONTROL(IDC_TOOL_LINE, DLSZ_SIZE_X)
DLGRESIZE_CONTROL(IDC_STATIC_LINE, DLSZ_SIZE_X)
DLGRESIZE_CONTROL(IDC_DB_TREE, DLSZ_SIZE_Y)
DLGRESIZE_CONTROL(IDC_DIALOG_AREA, DLSZ_SIZE_X | DLSZ_SIZE_Y)
DLGRESIZE_CONTROL(IDC_EXEC,  DLSZ_MOVE_X | DLSZ_MOVE_Y )
END_DLGRESIZE_MAP()




// CLookupDlg ��Ϣ�������

BOOL CLookupDlg::OnInitDialog()
{
    CDialogResize::OnInitDialog();

    // ��������...���˵�����ӵ�ϵͳ�˵��С�

    InitResizing(FALSE);
    // IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    //ShowWindow(SW_MAXIMIZE);


    int s, t, b, r, l;

    if (AfxGetApp()->GetProfileInt("Settings", "SavePosition", 1))
    {
        // only restore if there is a previously saved position
        if ( -1 != (s = AfxGetApp()->GetProfileInt("Settings", "FrameStatus",   -1)) &&
                -1 != (t = AfxGetApp()->GetProfileInt("Settings", "FrameTop",      -1)) &&
                -1 != (l = AfxGetApp()->GetProfileInt("Settings", "FrameLeft",     -1)) &&
                -1 != (b = AfxGetApp()->GetProfileInt("Settings", "FrameBottom",   -1)) &&
                -1 != (r = AfxGetApp()->GetProfileInt("Settings", "FrameRight",    -1))
           )
        {
            WINDOWPLACEMENT wp;

            // restore the window's status
            wp.showCmd = s;

            // restore the window's width and height
            wp.rcNormalPosition.bottom = b;
            wp.rcNormalPosition.right = r;

            // the following correction is needed when the taskbar is
            // at the left or top and it is not "auto-hidden"
            RECT workArea;
            SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);
            l += workArea.left;
            t += workArea.top;

            // make sure the window is not completely out of sight
            int max_x = GetSystemMetrics(SM_CXSCREEN) -
                        GetSystemMetrics(SM_CXICON);
            int max_y = GetSystemMetrics(SM_CYSCREEN) -
                        GetSystemMetrics(SM_CYICON);
            wp.rcNormalPosition.top = min(t, max_y);
            wp.rcNormalPosition.left = min(l, max_x);

            SetWindowPlacement(&wp);
        }
    }

    m_oTraceDlg.Create(IDD_DIALOG_EDIT, this);

    DWORD dwStyle = GetWindowLong(m_hDbTree.m_hWnd, GWL_STYLE);
    dwStyle |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
    SetWindowLong(m_hDbTree.m_hWnd, GWL_STYLE, dwStyle);

    m_oUserManager.Serialize(FALSE);
    InitTree();


    if(!CDBMgr::Instance()->Init())
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "mysql module init error!");
    }
    else
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "mysql module init ok!");
    }


    // TODO: �ڴ���Ӷ���ĳ�ʼ������
    ActivatePage(0);
    m_bInitialized = TRUE;
    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLookupDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogResize::OnSysCommand(nID, lParam);
    }
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLookupDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogResize::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLookupDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CLookupDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogResize::OnSize(nType, cx, cy);
    if (m_bInitialized)
        MoveChilds();
}


void CLookupDlg::OnClose()
{
    if (AfxGetApp()->GetProfileInt("Settings", "SavePosition", 1))
    {
        // Save main window position
        WINDOWPLACEMENT wp;
        GetWindowPlacement(&wp);
        AfxGetApp()->WriteProfileInt("Settings", "FrameStatus", wp.showCmd);
        AfxGetApp()->WriteProfileInt("Settings", "FrameTop",    wp.rcNormalPosition.top);
        AfxGetApp()->WriteProfileInt("Settings", "FrameLeft",   wp.rcNormalPosition.left);
        AfxGetApp()->WriteProfileInt("Settings", "FrameBottom", wp.rcNormalPosition.bottom);
        AfxGetApp()->WriteProfileInt("Settings", "FrameRight",  wp.rcNormalPosition.right);
    }
    CDialogResize::OnClose();
}




BOOL CLookupDlg::InitTree()
{
    // ��ʼ���ڵ����ݡ�
    map<string, SDDBAccount>::iterator itr;
    m_hDbTree.DeleteAllItems();
    CArray<CUser, CUser&> array;
    m_oUserManager.GetUserList(array);
    for (int i = 0; i < array.GetCount(); i++)
    {
        CUser &user = array.GetAt(i);
        m_hDbTree.InsertItem(user.m_strConnName, NULL, NULL, NULL);
    }
    return TRUE;
}

void CLookupDlg::OnTvnSelchangedBasePlayTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    CString		strUser   = m_hDbTree.GetItemText(pNMTreeView->itemNew.hItem);		//��ȡ�ڵ��KEYֵ
    CUser		user;
    if(!m_oUserManager.GetUser(strUser, user))
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "get user error!");
        return;
    }

    SGDP::ISDDBSession*	pDBSession = CDBMgr::Instance()->GetDBSession(user.m_strConnName.GetBuffer(0), user.m_stAccount);
    if(NULL == pDBSession)
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "get dbsession error!");
        return;
    }

    UINT32	dwErr;
    string	strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = pDBSession->ExecuteSqlRs("show databases", &pRecordSet, &dwErr, &strError );
    if(SDDB_HAS_RECORDSET == nRet)
    {
        CString strDatabase = "";
        while(pRecordSet->GetRecord())
        {
            strDatabase = pRecordSet->GetFieldValueByName("Database");
            if (NULL != FindItem(pNMTreeView->itemNew.hItem, strDatabase.GetBuffer(0)))
            {
                continue;
            }
            m_hDbTree.InsertItem(strDatabase, NULL, NULL, pNMTreeView->itemNew.hItem);
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }
    m_hDbTree.Expand(pNMTreeView->itemNew.hItem, TVE_EXPAND);

    *pResult = 0;
}

void CLookupDlg::DeleteTreeNode(HTREEITEM hTreeItem, BOOL bMySelf)
{
    //ɾ���ڵ�����������ӽڵ㼰�ֵܽڵ�

    //ɾ���ڵ�����������ӽڵ㼰�ֵܽڵ�
    if(NULL == hTreeItem)
        return;
    CString strText		=	"";
    CString strText1		=	"";
    while(m_hDbTree.ItemHasChildren(hTreeItem))
    {
        HTREEITEM		hChild   =   m_hDbTree.GetChildItem(hTreeItem);
        DeleteTreeNode(hChild);
        DeleteTreeNode(m_hDbTree.GetNextSiblingItem(hChild));
    }

    if (TRUE == bMySelf)
    {
        m_hDbTree.DeleteItem(hTreeItem);
    }
}

void CLookupDlg::ExpandTreeNode(HTREEITEM hTreeItem)
{
    //չ����
    HTREEITEM   hChild = NULL;
    while(hTreeItem != NULL)
    {
        if(m_hDbTree.ItemHasChildren(hTreeItem))
        {
            m_hDbTree.Expand(hTreeItem, TVE_EXPAND);
            hChild   =   m_hDbTree.GetChildItem(hTreeItem);
            ExpandTreeNode(hChild);
            ExpandTreeNode(m_hDbTree.GetNextSiblingItem(hChild));
        }
        hTreeItem = m_hDbTree.GetNextSiblingItem(hTreeItem);
    }
}

/********************************************************************/
/*															*/
/* Function name : OnKickIdle									*/
/* Description   : Make ON_UPDATE_COMMAND_UI work for this dialog.	*/
/*															*/
/********************************************************************/
LRESULT CLookupDlg::OnKickIdle(WPARAM wParam, LPARAM lParam)
{
    UpdateDialogControls(this, FALSE);

    CMenu* pMainMenu = GetMenu();
    CCmdUI cmdUI;
    // update menu enable/disable state
    for (INT n = 0; n < pMainMenu->GetMenuItemCount(); ++n)
    {
        CMenu* pSubMenu = pMainMenu->GetSubMenu(n);
        cmdUI.m_nIndexMax = pSubMenu->GetMenuItemCount();
        for (UINT i = 0; i < cmdUI.m_nIndexMax; ++i)
        {
            cmdUI.m_nIndex = i;
            cmdUI.m_nID = pSubMenu->GetMenuItemID(i);
            cmdUI.m_pMenu = pSubMenu;
            cmdUI.DoUpdate(this, FALSE);
        }
    }
    return Default();
}

void CLookupDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateData();
}


/********************************************************************/
/*																	*/
/* Function name : CApplicationDlg::MoveChilds						*/
/* Description   : Move child windows into place holder area.		*/
/*																	*/
/********************************************************************/
void CLookupDlg::MoveChilds()
{
    // position property pages
    CRect rcDlgs;
    // get dialog area rect
    GetDlgItem(IDC_DIALOG_AREA)->GetWindowRect(rcDlgs);
    ScreenToClient(rcDlgs);
    m_oTraceDlg.MoveWindow(rcDlgs);//��Ӣ����ս����¼
}


/********************************************************************/
/*																	*/
/* Function name : CApplicationDlg::ActivatePage					*/
/* Description   : Called when an icon on the outlookbar is pressed.*/
/*																	*/
/********************************************************************/
void CLookupDlg::ActivatePage(int nIndex)
{
    switch(nIndex)
    {
    case 1:
        m_oTraceDlg.ShowWindow(SW_SHOW);//���ID
        break;
    default:
        m_oTraceDlg.ShowWindow(SW_SHOW);//���ID
        break;
    }
    MoveChilds();
}

// ����lpszText��������������������
HTREEITEM CLookupDlg::FindItem(HTREEITEM hRoot, LPSTR lpszText)
{
    //���hRoot = NULL��ָ��hRootΪTree�ĸ�
    if (hRoot == NULL)
        hRoot = m_hDbTree.GetRootItem();
    //���hRoot = NULL������NULL
    if (hRoot == NULL)
        return NULL;
    //�ж�hRoot�Ƿ����������������ϣ�����hRoot
    if (m_hDbTree.GetItemText(hRoot).Compare(lpszText) == 0)
        return hRoot;

    //���hRootû���ӽڵ㣬����NULL
    if (m_hDbTree.ItemHasChildren(hRoot) == FALSE)
        return NULL;
    //�ݹ����hRoot�������ӽڵ�
    HTREEITEM hItem = m_hDbTree.GetChildItem(hRoot);
    while (hItem)
    {
        if (m_hDbTree.GetItemText(hItem).Find(lpszText) >= 0)     //�������hItemΪ����֦���ҵ������ؽ��
        {
            return hItem;
        }
        else        //���򣬲�����hItemͬ������һ��֦
        {
            hItem = m_hDbTree.GetNextSiblingItem(hItem);
        }
    } // end of while(hItem != NULL, has next item)

    return NULL;
}



void CLookupDlg::OnBnClickedExec()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    m_oTraceDlg.UpdateData();
    UpdateData();

    if (m_oTraceDlg.m_strSQL.IsEmpty())
    {
        return;
    }

    HTREEITEM hRoot = m_hDbTree.GetRootItem();
    //���hRoot = NULL������NULL
    while (hRoot)
    {
        //���hRootû���ӽڵ㣬����NULL
        if (m_hDbTree.ItemHasChildren(hRoot) == FALSE)
            return;
        //�ݹ����hRoot�������ӽڵ�
        HTREEITEM hItem = m_hDbTree.GetChildItem(hRoot);
        while (hItem)
        {
            CUser		user;
            UINT32		dwErr;
            string		strError;
            HTREEITEM	hRoot		= m_hDbTree.GetParentItem(hItem);
            CString		strConn		= m_hDbTree.GetItemText(hRoot);
            SGDP::ISDDBRecordSet* pRecordSet = NULL;
            if(!m_oUserManager.GetUser(strConn, user))
            {
                m_oTraceDlg.AddTraceLine(1, "%s", "get Conn error!");
                return;
            }

            SGDP::ISDDBSession*	pDBSession = CDBMgr::Instance()->GetDBSession(user.m_strConnName.GetBuffer(0), user.m_stAccount);
            if(NULL == pDBSession)
            {
                m_oTraceDlg.AddTraceLine(1, "%s", "get dbsession error!");
                return;
            }

            //��ȡѡ��״̬
            if(TRUE != m_hDbTree.GetCheck(hItem))
            {
                hItem = m_hDbTree.GetNextSiblingItem(hItem);
                continue;
            }
            CString strDbName = m_hDbTree.GetItemText(hItem);
            char v_szSQL[1024] = {0};
            sprintf(v_szSQL, "use %s", strDbName.GetBuffer(0));
            INT32 nRet = pDBSession->ExecuteSqlRs(v_szSQL, &pRecordSet, &dwErr, &strError);
            if (nRet >= 0)
            {
                m_oTraceDlg.AddTraceLine(1, "[SQL] %s", v_szSQL);
            }
            else
            {
                m_oTraceDlg.AddTraceLine(1, "[SQL] %s", v_szSQL);
                m_oTraceDlg.AddTraceLine(3, "[Err] %d - %s ", dwErr, strError.c_str());
            }
			if(NULL != pRecordSet)
			{
				pRecordSet->Release();
				pRecordSet = NULL;
			}

            sprintf(v_szSQL, "%s", m_oTraceDlg.m_strSQL.GetBuffer(0));
            nRet = pDBSession->ExecuteSqlRs(m_oTraceDlg.m_strSQL.GetBuffer(0), &pRecordSet, &dwErr, &strError );
            if (nRet >= 0)
            {
                m_oTraceDlg.AddTraceLine(1, "[SQL] %s", v_szSQL);
            }
            else
            {
                m_oTraceDlg.AddTraceLine(1, "[SQL] %s", v_szSQL);
                m_oTraceDlg.AddTraceLine(3, "[Err] %d - %s ", dwErr, strError.c_str());
            }

            if(NULL != pRecordSet)
            {
                pRecordSet->Release();
                pRecordSet = NULL;
            }
            hItem = m_hDbTree.GetNextSiblingItem(hItem);
        } // end of while(hItem != NULL, has next item)
        hRoot = m_hDbTree.GetNextSiblingItem(hRoot);
    }
}


void CLookupDlg::OnNMRClickDbTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CPoint point;
    GetCursorPos(&point);
    CPoint pointInTree = point;
    m_hDbTree.ScreenToClient(&pointInTree);
    HTREEITEM item;
    UINT flag = TVHT_ONITEM;
    item = m_hDbTree.HitTest(pointInTree, &flag);
    if(item != NULL)
    {
        m_bFlag = TRUE;
        CMenu menu;
        menu.LoadMenu(MAKEINTRESOURCE(IDR_MENU2));
        menu.GetSubMenu(0)->TrackPopupMenu(0, point.x, point.y, this, NULL);
    }
    *pResult = 0;
}


void CLookupDlg::OnAddDb()
{
    //�����������ݿ�����
    CDbSetDlg dlg;
    if(IDOK != dlg.DoModal())
    {
        return;
    }
    CUser oUser;
    oUser.m_strConnName		= dlg.m_strConnName;
    memcpy(oUser.m_stAccount.m_szHostName, dlg.m_strHostName.GetBuffer(0), dlg.m_strHostName.GetLength());
    memcpy(oUser.m_stAccount.m_szDBName, dlg.m_strDBName.GetBuffer(0), dlg.m_strDBName.GetLength());
    memcpy(oUser.m_stAccount.m_szLoginName, dlg.m_strUser.GetBuffer(0), dlg.m_strUser.GetLength());
    memcpy(oUser.m_stAccount.m_szLoginPwd, dlg.m_strPwd.GetBuffer(0), dlg.m_strPwd.GetLength());
    memcpy(oUser.m_stAccount.m_szCharactSet, dlg.m_strChartSet.GetBuffer(0), dlg.m_strChartSet.GetLength());
    oUser.m_stAccount.m_wConnPort = dlg.m_nPort;
    oUser.m_stAccount.m_wDBType = 0;;
    m_oUserManager.AddUser(oUser);
    InitTree();
}

void CLookupDlg::OnEditDb()
{
    // TODO: �ڴ���������������
    HTREEITEM ht = m_hDbTree.GetSelectedItem();
    if(!ht)
    {
        return;
    }
    CString	strConn;
    strConn = m_hDbTree.GetItemText(ht);
    CUser	user;
    if(!m_oUserManager.GetUser(strConn, user))
    {
        return;
    }

    CDbSetDlg dlg(NULL, user.m_strConnName,
                  user.m_stAccount.m_szHostName,
                  user.m_stAccount.m_szDBName,
                  user.m_stAccount.m_szLoginPwd,
                  user.m_stAccount.m_szLoginName,
                  user.m_stAccount.m_wConnPort,
                  user.m_stAccount.m_szCharactSet);
    if(IDOK != dlg.DoModal())
    {
        return;
    }
    CUser oUser;
    oUser.m_strConnName		= dlg.m_strConnName;
    memcpy(oUser.m_stAccount.m_szHostName, dlg.m_strHostName.GetBuffer(0), dlg.m_strHostName.GetLength());
    memcpy(oUser.m_stAccount.m_szDBName, dlg.m_strDBName.GetBuffer(0), dlg.m_strDBName.GetLength());
    memcpy(oUser.m_stAccount.m_szLoginName, dlg.m_strUser.GetBuffer(0), dlg.m_strUser.GetLength());
    memcpy(oUser.m_stAccount.m_szLoginPwd, dlg.m_strPwd.GetBuffer(0), dlg.m_strPwd.GetLength());
    memcpy(oUser.m_stAccount.m_szCharactSet, dlg.m_strChartSet.GetBuffer(0), dlg.m_strChartSet.GetLength());
    oUser.m_stAccount.m_wConnPort = dlg.m_nPort;
    oUser.m_stAccount.m_wDBType = 0;;
    m_oUserManager.EditUser(strConn, oUser);
    InitTree();
}


void CLookupDlg::OnOpenConn()
{
    HTREEITEM hItem = m_hDbTree.GetSelectedItem();
    if(!hItem)
    {
        return;
    }

    CString		strUser   = m_hDbTree.GetItemText(hItem);		//��ȡ�ڵ��KEYֵ
    CUser		user;
    if(!m_oUserManager.GetUser(strUser, user))
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "get user error!");
        return;
    }

    SGDP::ISDDBSession*	pDBSession = CDBMgr::Instance()->GetDBSession(user.m_strConnName.GetBuffer(0), user.m_stAccount);
    if(NULL == pDBSession)
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "get dbsession error!");
        return;
    }

    UINT32	dwErr;
    string	strError;
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = pDBSession->ExecuteSqlRs("show databases", &pRecordSet, &dwErr, &strError );
    if(SDDB_HAS_RECORDSET == nRet)
    {
        CString strDatabase = "";
        while(pRecordSet->GetRecord())
        {
            strDatabase = pRecordSet->GetFieldValueByName("Database");
            if (NULL != FindItem(hItem, strDatabase.GetBuffer(0)))
            {
                continue;
            }
            m_hDbTree.InsertItem(strDatabase, NULL, NULL, hItem);
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }
    m_hDbTree.Expand(hItem, TVE_EXPAND);
}


void CLookupDlg::OnCloseComm()
{
    HTREEITEM hItem = m_hDbTree.GetSelectedItem();
    if(!hItem)
    {
        return;
    }

    CString		strUser   = m_hDbTree.GetItemText(hItem);		//��ȡ�ڵ��KEYֵ
    CUser		user;
    if(!m_oUserManager.GetUser(strUser, user))
    {
        m_oTraceDlg.AddTraceLine(1, "%s", "get user error!");
        return;
    }
    if(!CDBMgr::Instance()->CloseDBSession(user.m_strConnName.GetBuffer(0)))
    {
        return;
    }
    DeleteTreeNode(hItem, FALSE);
}
