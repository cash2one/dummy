// PacketRobotDlg.cpp : implementation file
//

#include "stdafx.h"
#include "common.h"
#include "PacketRobotDlg.h"
#include "PacketRobot.h"
#include "config.h"
#include "sdclientlogin.h"
#include "sdmsg.h"
#include "clidata.h"
#include <sdstring.h>
#include <sdtime.h>
#include <stack>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Ĭ�������ַ�����С
#define INPUT_DEFAULT_SIZE 128

CPacketRobotDlg::CPacketRobotDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CPacketRobotDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    m_pISDClient = NULL ;
}

VOID CPacketRobotDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_SELECT, m_lcList);
    DDX_Control(pDX, IDC_EDIT_TEXT, m_richEdit);
    DDX_Control(pDX, IDC_TREE_STRUCT, m_Tree);
}

BEGIN_MESSAGE_MAP(CPacketRobotDlg, CDialog)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDOK, &CPacketRobotDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDC_BUTTON_SEND, &CPacketRobotDlg::OnBnClickedButtonSend)
    ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CPacketRobotDlg::OnBnClickedButtonClear)
    ON_BN_CLICKED(IDC_BUTTON_CUT, &CPacketRobotDlg::OnBnClickedButtonCut)
    ON_BN_CLICKED(IDCANCEL, &CPacketRobotDlg::OnBnClickedCancel)
    ON_NOTIFY(NM_CLICK, IDC_LIST_SELECT, &CPacketRobotDlg::OnNMClickListSelect)
    ON_WM_TIMER()
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_STRUCT, &CPacketRobotDlg::OnTvnSelchangedTreeStruct)
END_MESSAGE_MAP()


// CPacketRobotDlg message handlers

SDBOOL CPacketRobotDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    CProtoCliGT* pProtoCli = CProtoCliGT::Instance();
    pProtoCli->SetMaxMsgId(200);
    pProtoCli->SetMinMsgId(1);
    pProtoCli->SetName("ProtoCli");
    if (NULL == CProtocolMgr::Instance()->AddProtocol(pProtoCli))
    {
        return FALSE;
    }

    CProtoCliZS* pProtoCliZS = CProtoCliZS::Instance();
    pProtoCliZS->SetMaxMsgId(200);
    pProtoCliZS->SetMinMsgId(1);
    pProtoCliZS->SetName("ProtoCliZS");
    if (NULL == CProtocolMgr::Instance()->AddProtocol(pProtoCliZS))
    {
        return FALSE;
    }

    m_szUserId[0] = 0;

    BOOL bReturn = LoadFromXML("robot.xml");
    CHAR czInfo[1024];
    if(FALSE == bReturn)
    {
        strcpy(czInfo, "robot.xml ����ʧ�ܡ�");
        PrintText(czInfo, LOG_ERROR);
    }
    else
    {
        TimeString(czInfo);
        // INT32 nRet = WriteLog(czInfo);
        INT32 nRet = 1;
        if(0 == nRet)
        {
            sprintf(czInfo, "[ robot.xml ������ϡ���־ = \"%s\"��������IP = \"%s\"���˿ں� = %d��]", "����", g_acServerIP, g_dwServerPort);
        }
        else
        {
            sprintf(czInfo, "[ robot.xml ������ϡ���־ = \"%s\"��������IP = \"%s\"���˿ں� = %d��]", "�ر�", g_acServerIP, g_dwServerPort);
        }
        PrintText(czInfo, LOG_DESCRIBE);
    }

    // �б�
    m_lcList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    FlushList();

    // ����ͼ
    m_Tree.ModifyStyle(NULL, TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT | TVS_SHOWSELALWAYS);


    return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

VOID CPacketRobotDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // Center icon in client rectangle
        INT32 cxIcon = GetSystemMetrics(SM_CXICON);
        INT32 cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        INT32 x = (rect.Width() - cxIcon + 1) / 2;
        INT32 y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPacketRobotDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

// ���ӷ�����
UINT32 CPacketRobotDlg::ConnectServer(const CHAR* _IP, const UINT32 _Port)
{
    if (m_pISDClient)
    {
        m_pISDClient->Release();
        m_pISDClient = NULL;
    }
    m_pISDClient = SDNetGetModule(&SDCLIENT_MODULE_VERSION);
    m_poConnector = m_pISDClient->CreateConnector(NETIO_ASYNCSELECT);
    m_poConnector->SetSession(CGlobe::m_poSeesion);
    m_poConnector->SetPacketParser(CCliPacketParser::Instance());
    m_poConnector->SetBufferSize(102400, 102400);
    m_poConnector->Connect(_IP, _Port);
    return 0;
}

// �Ͽ�����
VOID CPacketRobotDlg::CutOffServer()
{
    if (m_pISDClient)
    {
        m_poConnector->Release();
        m_pISDClient->Release();
        m_pISDClient = NULL;
        OnDisConnect(0);
        // m_poConnector = NULL;
    }
}

VOID CPacketRobotDlg::OnConnect(INT32 nErrorCode)
{
    CHAR szText[LOG_MAX_LENGTH];
    sprintf(szText, "[ ������������� �������� = %d��]", nErrorCode);
    PrintText(szText, LOG_DESCRIBE);
    if(0 == nErrorCode)
    {
        ::EnableWindow(::GetDlgItem(this->m_hWnd, IDC_BUTTON_CUT), TRUE);
        ::EnableWindow(::GetDlgItem(this->m_hWnd, IDC_BUTTON_SEND), TRUE);
        ::EnableWindow(::GetDlgItem(this->m_hWnd, IDOK), FALSE);
    }
}

VOID CPacketRobotDlg::OnDisConnect(INT32 nErrorCode)
{
    PrintText("[ �����ѶϿ���]", LOG_ERROR);
    ::EnableWindow(::GetDlgItem(this->m_hWnd, IDC_BUTTON_CUT), FALSE);
    ::EnableWindow(::GetDlgItem(this->m_hWnd, IDC_BUTTON_SEND), FALSE);
    ::EnableWindow(::GetDlgItem(this->m_hWnd, IDOK), TRUE);
    // ֹͣʱ��
    KillTimer(TIMER_ID_MOVEVAST);
    KillTimer(TIMER_ID_HEARTBEAT);

    CGlobe::m_poSeesion->ClrKey();
}

// ---------------- ����Э�� ----------------


// ���ͳ�����Ϣ
VOID CPacketRobotDlg::Send_COMMON(INT32 nMsgID, VOID* pReq, const CHAR* szDescription)
{
    CHAR szTip[256] = {0};
    sprintf(szTip, "[ �շ���(%s)����]", szDescription);
    PrintText(szTip, LOG_DESCRIBE);
    CSDProtocol* pProtocol = CProtocolMgr::Instance()->FindProtocol(nMsgID);
    if (pProtocol && m_pISDClient)
    {
        static CHAR acMsgData[PACKAGE_CONTENT_LENGTH] = {0};
        INT32 nEncodeRet = pProtocol->Encode(nMsgID, pReq, acMsgData, PACKAGE_CONTENT_LENGTH);
        if (nEncodeRet < 0)
        {
            CHAR szText[LOG_MAX_LENGTH] = {0};
            sprintf(szText, "[ MsgID = %d, Len = %d] encode error!", nMsgID);
            PrintText(szText, LOG_DESCRIBE);
            return ;
        }
        CGlobe::m_poSeesion->SendMsg(nMsgID, acMsgData, nEncodeRet);
    }
}


// ---------------- �������� ----------------

// ��ӡ��־
VOID CPacketRobotDlg::PrintText(const CHAR* cpText, const LogType _LogType)
{
    if(LOG_DATA == _LogType)
    {
        // ��ӡ����ͼ
        ParseLog(cpText);
    }
    else if(LOG_NOPRINT == _LogType)
    {
        // ����ӡ����ͼ
        ParseLog(cpText);
        return;
    }
    TCHAR acTemp[LOG_MAX_LENGTH];
    _tcscpy(acTemp, _SDTLocal2T(cpText));
    _tcscat(acTemp, _T("\r\n"));
    WriteText(acTemp, _LogType);
}

// ��ӡ��־
VOID CPacketRobotDlg::WriteText(const TCHAR* cpText, const LogType _LogType)
{
    INT32 nOldLines = 0, nNewLines = 0, nScroll = 0;
    LONG nInsertionPoint = 0;
    COLORREF wCollor;
    CHARFORMAT cf;
    switch(_LogType)
    {
    case LOG_DATA:
        wCollor = RGB(0, 0, 0);
        break;
    case LOG_DESCRIBE:
        wCollor = RGB(0, 0, 255);
        break;
    case LOG_ERROR:
        wCollor = RGB(255, 0, 0);
        break;
    }

    // Save number of lines before insertion of new text
    nOldLines = m_richEdit.GetLineCount();

    // Initialize character format structure
    cf.cbSize = sizeof(CHARFORMAT);
    cf.dwMask = CFM_COLOR | CFM_SIZE | CFM_FACE;
    cf.dwEffects = 0;	// To disable CFE_AUTOCOLOR
    cf.crTextColor	= wCollor;
    cf.yHeight = 13 * 13;
    _tcscpy(cf.szFaceName, _T("΢���ź�"));

    // Set insertion point to end of text
    nInsertionPoint = m_richEdit.GetWindowTextLength();
    m_richEdit.SetSel(nInsertionPoint, -1);

    //  Set the character format
    m_richEdit.SetSelectionCharFormat(cf);

    // Replace selection. Because we have nothing selected, this will simply insert
    // the string at the current caret position.
    m_richEdit.ReplaceSel(cpText);

    // Get new line count
    nNewLines = m_richEdit.GetLineCount();

    // Scroll by the number of lines just inserted
    nScroll = nNewLines - nOldLines;
    m_richEdit.LineScroll(nScroll);
}

// �����ṹ����־
VOID CPacketRobotDlg::ParseLog(const CHAR* _Log)
{
    static INT32 s_nDepth = -1; // ��һ���������
    static std::stack<HTREEITEM> s_Tree;
    static HTREEITEM s_TreeItem = NULL;
    if(NULL == _Log) // ��ʼ����������
    {
        s_nDepth = -1;
        while(false == s_Tree.empty())s_Tree.pop();
        s_TreeItem = NULL;
        return;
    }
    // �������
    const CHAR* pszNext = strstr(_Log, "\r\n");
    if(pszNext == _Log || '\0' == *_Log)
        return;
    // ������
    CHAR* pszLine;
    if(NULL == pszNext)
    {
        pszLine = new CHAR[strlen(_Log) + 1];
        strcpy(pszLine, _Log);
    }
    else
    {
        pszLine = new CHAR[pszNext - _Log + 1];
        memset(pszLine, 0, pszNext - _Log + 1);
        strncpy(pszLine, _Log, pszNext - _Log);
        pszNext += 2;
    }
    // ��ȡ��ǰ���
    INT32 nCurDepth = 0; // ��ǰ�������
    while(*(_Log + nCurDepth) == '\t')nCurDepth++;
    // ������ǰ��
    CHAR* pKey = NULL, *pValue = NULL;
    CHAR* pszTemp = pszLine + nCurDepth;
    if(*pszTemp == '{' || *pszTemp == '}' || *pszTemp == '\0')
    {
        if(nCurDepth < s_nDepth)
        {
            s_Tree.pop();
            s_TreeItem = NULL;
            s_nDepth = nCurDepth;
        }
        delete[] pszLine;
        if(NULL != pszNext)
        {
            ParseLog(pszNext);
        }
        return;
    }
    else
    {
        CHAR* pszBuf = strstr(pszTemp, "=");
        pKey = new CHAR[strlen(pszTemp) + 1];
        if(NULL == pszBuf)
        {
            strcpy(pKey, pszTemp);
        }
        else
        {
            *(pszBuf++) = '\0';
            strcpy(pKey, pszTemp);
            pValue = new CHAR[strlen(pszBuf) + 1];
            strcpy(pValue, pszBuf);
            m_LsResource.push_back(pValue);
        }
        m_LsResource.push_back(pKey);
    }

    // ��ʼ����
    HTREEITEM hTreeItem;
    if(nCurDepth == s_nDepth)
    {
        // �����ֵ�����
        hTreeItem = s_Tree.top();
        if(0 == nCurDepth)
            s_TreeItem = m_Tree.InsertItem(_SDTA2T(pKey), NULL, NULL);
        else
            s_TreeItem = m_Tree.InsertItem(_SDTA2T(pKey), NULL, NULL, hTreeItem);
    }
    else if(nCurDepth > s_nDepth)
    {
        hTreeItem = s_TreeItem;
        s_Tree.push(hTreeItem);
        if(0 == nCurDepth)
            s_TreeItem = m_Tree.InsertItem(_SDTA2T(pKey), NULL, NULL);
        else
            s_TreeItem = m_Tree.InsertItem(_SDTA2T(pKey), NULL, NULL, hTreeItem);
        s_nDepth = nCurDepth;
    }
    else
    {
        s_Tree.pop();
        hTreeItem = s_Tree.top();

        if(0 == nCurDepth)
            s_TreeItem = m_Tree.InsertItem(_SDTA2T(pKey), NULL, NULL);
        else
            s_TreeItem = m_Tree.InsertItem(_SDTA2T(pKey), NULL, NULL, hTreeItem);

        s_nDepth = nCurDepth;
    }
    m_Tree.SetItemData(s_TreeItem, (INT32)pValue);
    delete[] pszLine;
    // ������һ��
    if(NULL != pszNext)
    {
        ParseLog(pszNext);
    }
}

// ˢ���б�
VOID CPacketRobotDlg::FlushList()
{
    // ����б�ͱ�����
    m_lcList.DeleteAllItems();
    while(FALSE != m_lcList.DeleteColumn(0));
    // ��ӱ�����
    m_lcList.InsertColumn(0, _T("Э����"), LVCFMT_LEFT, 100);
    m_lcList.InsertColumn(1, _T("���ı�־"), LVCFMT_LEFT, 220);
    m_lcList.InsertColumn(2, _T("��ע"), LVCFMT_LEFT, 80);
    // ����б�
    INT32 i = 0;
    for(std::list<MsgInfo>::iterator itor = g_lsMessages.begin(); itor != g_lsMessages.end(); itor++)
    {
        m_lcList.InsertItem(i, _SDTLocal2T(itor->szCaption));
        m_lcList.SetItemText(i, 1, _SDTLocal2T(itor->szDescribe));
        m_lcList.SetItemText(i, 2, _SDTLocal2T(itor->szNote));
        i++;
    }
}

// ---------------- �������� ----------------

// ��������
VOID CPacketRobotDlg::AdjustInput(INT32 _Index)
{
    std::list<MsgInfo>::iterator itorMsg;
    std::list<InputInfo>::iterator itorInput;

    // ���������
    ClearInput();

    itorMsg = g_lsMessages.begin();
    if(0 != _Index)
    {
        std::advance(itorMsg, _Index);
    }
    for(itorInput = itorMsg->lsInputs.begin(); itorInput != itorMsg->lsInputs.end(); itorInput++)
    {
        AdjustEdit(itorInput->nCtrlId, itorInput->szCaption, itorInput->szValue);
    }
}

// ��������
VOID CPacketRobotDlg::ClearInput()
{
    for(INT32 i = 0; i < INPUT_MAX_COUNT; i++)
    {
        ::EnableWindow(::GetDlgItem(this->m_hWnd, IDC_EDIT1 + i), FALSE);
        ::SetDlgItemTextA(this->m_hWnd, IDC_EDIT1 + i, "");
        ::SetDlgItemTextA(this->m_hWnd, IDC_LABEL1 + i, "");
    }
}

// ���������
VOID CPacketRobotDlg::AdjustEdit(INT32 _Index, CHAR* Caption, CHAR* Value)
{
    // Label Id
    INT32 nLabelId = _Index + IDC_LABEL1;
    // Edit Id
    INT32 nEditId = _Index + IDC_EDIT1;

    if(NULL == Caption)
    {
        ::SetDlgItemTextA(this->m_hWnd, nLabelId, "");
    }
    else
    {
        ::SetDlgItemTextA(this->m_hWnd, nLabelId, Caption);
    }
    ::EnableWindow(::GetDlgItem(this->m_hWnd, nEditId), TRUE);
    if(NULL == Value)
    {
        ::SetDlgItemTextA(this->m_hWnd, nEditId, "");
    }
    else
    {
        ::SetDlgItemTextA(this->m_hWnd, nEditId, Value);
    }
}


// ---------------- UI�ӿ� ----------------

// ���ӷ�����
VOID CPacketRobotDlg::OnBnClickedOk()
{
    ConnectServer(g_acServerIP, g_dwServerPort);
}

// �Ͽ�����
void CPacketRobotDlg::OnBnClickedButtonCut()
{
    CutOffServer();
}


// �����Ϣ��
VOID CPacketRobotDlg::OnBnClickedButtonClear()
{
    CHAR czLine[LOG_MAX_LENGTH];
    ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT_TEXT, czLine, LOG_MAX_LENGTH);
    // WriteLog(czLine);
    ::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_TEXT, "");
    m_Tree.DeleteAllItems();
    ParseLog(NULL);
}

// �˳�
VOID CPacketRobotDlg::OnBnClickedCancel()
{
    OnBnClickedButtonClear();
    if(NULL != m_pISDClient)
    {
        m_pISDClient->Release();
        m_pISDClient = NULL;
    }
    for(std::list<CHAR*>::iterator iter = m_LsResource.begin(); iter != m_LsResource.end(); iter++)
    {
        CHAR* pszTemp = *iter;
        delete[] pszTemp;
        pszTemp = NULL;
    }
    m_LsResource.clear();

    OnOK();
}

// ѡ��Э��
VOID CPacketRobotDlg::OnNMClickListSelect(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE *>(pNMHDR);
    // ��������򣬷������
    if(-1 != pNMItemActivate->iItem)
    {
        AdjustInput(pNMItemActivate->iItem);
    }
    *pResult = 0;
}

// ѡ�нṹ��
void CPacketRobotDlg::OnTvnSelchangedTreeStruct(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

    HTREEITEM hTreeItem = pNMTreeView->itemNew.hItem;
    INT32 n = m_Tree.GetItemData(hTreeItem);
    CHAR* pszData = (CHAR*)n;
    if(NULL == pszData)
        ::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_INFO, "NULL");
    else
        ::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_INFO, pszData);

    *pResult = 0;
}

VOID CPacketRobotDlg::OnTimer(UINT_PTR nIDEvent)
{
    switch(nIDEvent)
    {
    case TIMER_ID_LOADFINISH:
        //SendLoadFinsh(0);
        // KillTimer(TIMER_ID_LOADFINISH);
        break;
    case TIMER_ID_HEARTBEAT:
        //SendHeartBeat();
        break;
    }
    __super::OnTimer(nIDEvent);
}


// ���ͱ���
VOID CPacketRobotDlg::OnBnClickedButtonSend()
{
    INT32 nIndex = 0;
    POSITION pos = m_lcList.GetFirstSelectedItemPosition();
    if(NULL != pos)
    {
        nIndex = m_lcList.GetNextSelectedItem(pos) + 1;
        switch(nIndex)
        {
            //��֤
        case 1:
        {
            // ��½
            CHAR szTemp[128] = {0};
            PKT_CLILS_LOGIN_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwCliVersion = (UINT32)(SDStrtod(szTemp, NULL) * 100);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byAuthType = atoi(szTemp);
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT3, stReq.aszDeviceID, INPUT_DEFAULT_SIZE);
            //::GetDlgItemText(this->m_hWnd, IDC_EDIT4, stReq.aszNotifyID, INPUT_DEFAULT_SIZE);
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT4, stReq.aszUserName, INPUT_DEFAULT_SIZE);
            CHAR aszUserPwd[USERNAME_LEN] = { 0 }; //����
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT5, aszUserPwd, INPUT_DEFAULT_SIZE);
            if(1 == stReq.byAuthType)
            {
                CHAR acNetBuf[USERNAME_LEN] = {0};
                memcpy(acNetBuf + ENCRYPT_HEAD_LEN, aszUserPwd, strlen(aszUserPwd));
                UINT8* pszDecryptBuff =  (UINT8*)(acNetBuf);
                INT32 nDecryptBuffLen = strlen(aszUserPwd) + ENCRYPT_HEAD_LEN + ENCRYPT_TAIL_LEN;//��Ӽӽ���ͷβ
                CGlobe::m_poSeesion->GetMGEncrypt().encryptionDatas(pszDecryptBuff, nDecryptBuffLen);
                memcpy(stReq.abyUserPwd, pszDecryptBuff, nDecryptBuffLen);
                stReq.byPwdLen = nDecryptBuffLen;
            }
            else
            {
                stReq.byPwdLen = strlen(aszUserPwd);
                memcpy(stReq.abyUserPwd, aszUserPwd, strlen(aszUserPwd));
            }
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT6, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wZoneID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT7, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwPlayerID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT8, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wCareerID = atoi(szTemp);
			stReq.byAuthMethod = 1;
            // ���ͱ���
            Send_COMMON(CLILS_LOGIN_REQ, &stReq, "��½");
        }
        break;
        //������Ϸ
        case 2:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_ENTERGS_REQ stReq;
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT1, stReq.aszDeviceID, INPUT_DEFAULT_SIZE);
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT2, stReq.aszNotifyID, INPUT_DEFAULT_SIZE);
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT3, stReq.aszUserName, INPUT_DEFAULT_SIZE);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT4, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwPlayerID = SDAtou(szTemp);
			::GetDlgItemTextA(this->m_hWnd, IDC_EDIT5, szTemp, INPUT_DEFAULT_SIZE);
			stReq.dwCliVer = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT6, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wCareerID = SDAtou(szTemp);
            // ���ͱ���
            Send_COMMON(CLIGS_ENTERGS_REQ, &stReq, "������Ϸ");
        }
        break;
        //��ȡ�佫��ϸ��Ϣ
        case 4:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_GET_HERO_INFO_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byEquipBagFlag = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwPlayerID = atoi(szTemp);


            // ���ͱ���
            Send_COMMON(CLIGS_GET_HERO_INFO_REQ, &stReq, "��ȡ�佫��ϸ��Ϣ");
        }
        break;
        //�����԰
        case 5:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_ENTER_HOME_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byKind = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_ENTER_HOME_REQ, &stReq, "�����԰");
        }
        break;
        //��ȡ������������
        case 6:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_GET_SCENE_INSTANCE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wIndex = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_GET_SCENE_INSTANCE_REQ, &stReq, "��ȡ��������");
        }
        break;
        //���븱������
        case 7:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_ENTER_INSTANCE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wSceneIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byTownIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byInstanceIdx = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_ENTER_INSTANCE_REQ, &stReq, "���븱��");
        }
        break;
        //ս������
        case 8:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_BATTLE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byBattleIndex = atoi(szTemp);
            // ���ͱ���
            Send_COMMON(CLIGS_BATTLE_REQ, &stReq, "ս��");

        }
        break;
        //�˳�����
        case 9:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_EXIT_INSTANCE_REQ stReq;
            // ���ͱ���
            Send_COMMON(CLIGS_EXIT_INSTANCE_REQ, &stReq, "�˳�����");
        }
        break;
        //������������
        case 10:
        {

        }
        break;
        //�ջ�����
        case 11:
        {

        }
        break;
        //������������
        case 12:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_SMITHY_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byBuildKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_SMITHY_REQ, &stReq, "��������");
        }
        break;
        //װ��ǿ������
        case 13:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_EQUIP_STRENGTHEN_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byStrengthenType = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_EQUIP_STRENGTHEN_REQ, &stReq, "װ��ǿ��");
        }
        break;
        //����ļ������
        case 14:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_RECRUIT_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byBuildKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_RECRUIT_REQ, &stReq, "��������");
        }
        break;
        //��ļ�佫����
        case 15:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_RECRUIT_HERO_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_RECRUIT_HERO_REQ, &stReq, "��ļ�佫");
        }
        break;
        //��������������
        case 16:
        {
        }
        break;
        //�򿪱�������
        case 17:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_BAG_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_BAG_REQ, &stReq, "�򿪱���");
        }
        break;
        //�򿪿Ƽ�������
        case 18:

            break;
            //�����Ƽ�����
        case 19:

            break;
            //�򿪾���������
        case 20:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_RACE_BUILD_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byBuildKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_RACE_BUILD_REQ, &stReq, "�򿪾�����");
        }
        break;
        //��ȡ��������
        case 21:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_RECV_RANK_ENCOURAGE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_RECV_RANK_ENCOURAGE_REQ, &stReq, "��ȡ����");
        }
        break;
        //�����������
        case 22:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_BUY_ITEM_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byTabID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wPileCount = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_BUY_ITEM_REQ, &stReq, "�������");
        }
        break;
        //��������������
        case 23:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_CLR_PLAYER_DATA_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_CLR_PLAYER_DATA_REQ, &stReq, "����������");
        }
        break;
        //��ȡ����������
        case 24:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_RECV_TASK_ENCOURAGE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byTaskLineIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwTaskIdx = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_RECV_TASK_ENCOURAGE_REQ, &stReq, "��ȡ������");
        }
        break;
        //��������
        case 25:
        {
            /*
            CHAR szTemp[128] = {0};
            PKT_CLIGS_EMBATTLE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byEmbattleType = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byFormationIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wUpHeroKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT4, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wDownHeroKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_EMBATTLE_REQ, &stReq, "����");
            */
        }
        break;
        //װ����������
        case 26:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_EQUIP_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byDressType = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wDressItemKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT4, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wDressItemIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT5, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wUndressItemKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT6, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wUndressItemIdx = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_EQUIP_REQ, &stReq, "װ������");
        }
        break;
        //��ս����
        case 27:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_CHALLENGE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwRank = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_CHALLENGE_REQ, &stReq, "��ս");
        }
        break;
        //��ȡ�佫��ҩ����
        case 28:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_GET_HERO_DRUG_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byNeedDrugItemFlag = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_GET_HERO_DRUG_REQ, &stReq, "��ȡ�佫��ҩ");
        }
        break;
        //ʹ�õ�ҩ����
        case 29:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_USE_DRUG_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_USE_DRUG_REQ, &stReq, "ʹ�õ�ҩ");
        }
        break;
        //������������
        case 30:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_ITEM_MAKER_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wItemKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_ITEM_MAKER_REQ, &stReq, "��������");
        }
        break;
        //������������
        case 31:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_MAKE_ITEM_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wItemKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wEquipKindID = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wEquipIdx = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_MAKE_ITEM_REQ, &stReq, "��������");
        }
        break;
        //ǲɢ�佫����
        case 32:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_DISBAND_HERO_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_DISBAND_HERO_REQ, &stReq, "ǲɢ�佫");
        }
        break;

        //�򿪸���������������
        case 33:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_REQ, &stReq, "�򿪸�����������");
        }
        break;
        //�һ�����
        case 34:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_ONHOOK_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.stInstanceID.wSceneIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.stInstanceID.byTownIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.stInstanceID.byInstanceIdx = atoi(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT4, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byRunTimes = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_ONHOOK_REQ, &stReq, "�һ�");
        }
        break;
        //��ȡ���߽�������
        case 35:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_RECV_ONLINE_ENCOURAGE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = atoi(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_RECV_ONLINE_ENCOURAGE_REQ, &stReq, "��ȡ���߽���");
        }
        break;
        //ע���ǳ�����
        case 36:
        {
            CHAR szTemp[128] = {0};
            PKT_CLILS_REGISTER_DSPNAME_REQ stReq;
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT1, stReq.aszDspName, INPUT_DEFAULT_SIZE);

            // ���ͱ���
            Send_COMMON(CLILS_REGISTER_DSPNAME_REQ, &stReq, "ע���ǳ�");
        }
        break;
        //�򿪲����������
        case 37:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_EMBATTLE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = atoi(szTemp);


            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_EMBATTLE_REQ, &stReq, "�򿪲������");
        }
        break;
        //��Ʒʹ������
        case 38:
        {
            CHAR szTemp[128] = {0};
            PKT_CLILS_USE_GOODS_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wGoodsKindID = atoi(szTemp);


            // ���ͱ���
            Send_COMMON(CLILS_USE_GOODS_REQ, &stReq, "��Ʒʹ��");
        }
        break;
        //ʱ��ͬ��
        case 39:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_SYNC_TIME_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.qwCliTime = SDAtou64(szTemp);


            // ���ͱ���
            Send_COMMON(CLIGS_SYNC_TIME_REQ, &stReq, "ʱ��ͬ��");
        }
        break;
        //�򿪵�¼�����������
        case 40:
        {
            CHAR szTemp[128] = {0};
            PKT_CLILS_OPEN_LOGIN_ENCOURAGE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);


            // ���ͱ���
            Send_COMMON(CLILS_OPEN_LOGIN_ENCOURAGE_REQ, &stReq, "�򿪵�¼�������");
        }
        break;
        //��¼����ҡ������
        case 41:
        {
            CHAR szTemp[128] = {0};
            PKT_CLILS_RATE_LOGIN_ENCOURAGE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);


            // ���ͱ���
            Send_COMMON(CLILS_RATE_LOGIN_ENCOURAGE_REQ, &stReq, "��¼����ҡ��");
        }
        break;
        //��¼�������뱳������
        case 42:
        {
            CHAR szTemp[128] = {0};
            PKT_CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);


            // ���ͱ���
            Send_COMMON(CLILS_PUT_LOGIN_ENCOURAGE_INTO_BAG_REQ, &stReq, "��¼�������뱳��");
        }
        break;
        //��ȡ��������������
        case 43:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_GET_RANK_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);


            // ���ͱ���
            Send_COMMON(CLIGS_GET_RANK_REQ, &stReq, "��ȡ����������");
        }
        break;
        //��������
        case 44:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_ACCEPT_TASK_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byTaskLineIdx = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwTaskIdx = SDAtou(szTemp);


            // ���ͱ���
            Send_COMMON(CLIGS_ACCEPT_TASK_REQ, &stReq, "��������");
        }
        break;
        //�򿪷�²�������
        case 45:
        {
        }
        break;
        //ָ�ɷ�²����λ��
        case 46:
        {
        }
        break;
        //ˢ�·�²��������
        case 47:
        {
        }
        break;
        //��²�����ջ�����
        case 48:
        {
        }
        break;
        //������²����λ��
        case 49:
        {
        }
        break;
        //�����������CD
        case 50:
        {
        }
        break;
        //�жϹ�������
        case 51:
        {

        }
        break;
        //�����²����CD����
        case 52:
        {

        }
        break;
        //�ͷŷ�²����
        case 53:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_FREE_CAPTURE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwCapturePlayerID = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_FREE_CAPTURE_REQ, &stReq, "�ͷŷ�²");
        }
        break;
        //������������
        case 54:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_UPGRADE_GODWEAPON_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wQuality = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wLevel = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_UPGRADE_GODWEAPON_REQ, &stReq, "��������");
        }
        break;
        //���Ӷ᳡������
        case 55:
        {

        }
        break;
        //�Ӷ�����
        case 56:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_PLUNDER_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwEnemyID = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwCaptureID = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT3, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byUseItemFlag = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT4, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byResistFlag = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT5, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byCaptureGridIdx = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_PLUNDER_REQ, &stReq, "�Ӷ�");
        }
        break;
        //�򿪳�����
        case 57:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_ENEMY_TAB_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wStartIdx = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_ENEMY_TAB_REQ, &stReq, "�򿪳�����");
        }
        break;
        //ɾ�����
        case 58:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_DEL_ENEMY_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.dwEnemyID = SDAtou(szTemp);
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wStartIdx = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_DEL_ENEMY_REQ, &stReq, "ɾ�����");
        }
        break;
        //��ҡǮ��
        case 59:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_MONEY_TREE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_MONEY_TREE_REQ, &stReq, "��ҡǮ��");
        }
        break;
        //��ȡ�Ӷ�ս��
        case 60:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_GET_PLUNDER_BATTLELOG_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_GET_PLUNDER_BATTLELOG_REQ, &stReq, "��ȡ�Ӷ�ս��");
        }
        break;
        //�򿪼������
        case 61:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_SKILL_TAB_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_SKILL_TAB_REQ, &stReq, "�򿪼������");
        }
        break;
        //������������
        case 62:
        {

        }
        break;
        //�򿪷�²�������
        case 63:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_CAPTURE_TAB_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_CAPTURE_TAB_REQ, &stReq, "�򿪷�²���");
        }
        break;
        //�򿪵�ҩ�������
        case 64:
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_DRUG_USE_TAB_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_DRUG_USE_TAB_REQ, &stReq, "�򿪵�ҩ�������");
        }
        break;
        case 65://���佫��ҩ�������
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ	stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wKindID = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_HERO_DRUG_USE_TAB_REQ, &stReq, "���佫��ҩ�������");
        }
        break;
        case 66://�����ҩ����CD
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_CLR_USE_DRUG_CD_REQ	stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wKindID = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_CLR_USE_DRUG_CD_REQ, &stReq, "�����ҩ����CD");
        }
        break;
        case 67://ʹ�õ�ҩ
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_USE_DRUG_REQ	stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wHeroKindID = SDAtou(szTemp);

            memset(szTemp, 0x00, sizeof(szTemp));
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT2, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wUseLevel = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_CLR_USE_DRUG_CD_REQ, &stReq, "ʹ�õ�ҩ");
        }
        break;
        case 68://�򿪵�ҩ�������
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byExt = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ, &stReq, "�򿪵�ҩ�������");
        }
        break;
        case 69://��ҩ����
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGS_COMPOSE_EQUIP_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wEquipItemID = SDAtou(szTemp);

            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wEquipIdx = SDAtou(szTemp);

            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
            stReq.byGoldComposeFlag = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGS_OPEN_UPGRADE_DRUG_TAB_REQ, &stReq, "װ���ϳ�");
        }
        break;
        case 70://ѡ��
        {
            CHAR szTemp[128] = {0};
            PKT_CLIGT_SELECT_ZONE_REQ stReq;
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, szTemp, INPUT_DEFAULT_SIZE);
			stReq.byAuthType = SDAtou(szTemp);
			::GetDlgItemText(this->m_hWnd, IDC_EDIT2, stReq.aszDeviceID, INPUT_DEFAULT_SIZE);
            ::GetDlgItemText(this->m_hWnd, IDC_EDIT3, stReq.aszUserName, INPUT_DEFAULT_SIZE);			
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT4, (CHAR*)(stReq.abyUserPwd), INPUT_DEFAULT_SIZE);
			stReq.byPwdLen = strlen((CHAR*)(stReq.abyUserPwd));
            ::GetDlgItemTextA(this->m_hWnd, IDC_EDIT5, szTemp, INPUT_DEFAULT_SIZE);
            stReq.wZoneIdx = SDAtou(szTemp);

            // ���ͱ���
            Send_COMMON(CLIGT_SELECT_ZONE_REQ, &stReq, "ѡ��");
        }
        break;

		case 71://��������
			{
				CHAR szTemp[128] = {0};
				PKT_CLIGS_OPEN_AWAKEN_TAB_REQ stReq;

				// ���ͱ���
				Send_COMMON(CLIGS_OPEN_AWAKEN_TAB_REQ, &stReq, "��������");
			}
			break;

        default:
            break;
        }
    }
    else
    {
        PrintText("[ û��ѡ��Э�顣]", LOG_ERROR);
    }
}





VOID CPacketRobotDlg::OnRecvMsg(UINT16 wMsgID, const CHAR* pBuf, INT32 nLen)
{
    CHAR szText[LOG_MAX_LENGTH];
    CHAR acTemp[LOG_MAX_LENGTH];
    INT32 nTrack = 0; // �ڱ�
    if(0 == nLen)
    {
        return;
    }

    sprintf(szText, "[ �յ����ݣ�MsgID = %d, Len = %d��]", wMsgID, nLen);
    PrintText(szText, LOG_DESCRIBE);
    //sprintf(szText, "[sizeof(PKT_CLIGS_CHALLENGE_ACK) = %d]", sizeof(PKT_CLIGS_CHALLENGE_ACK));
	//sprintf(szText, "[sizeof(DT_JINGJIE_DATA)*4 = %d]", sizeof(DT_JINGJIE_DATA)*4);
    PrintText(szText, LOG_DESCRIBE);
    CSDProtocol *pProtocol = CProtocolMgr::Instance()->FindProtocol(wMsgID);
    if(pProtocol)
    {
        static CHAR DecodeData[PACKAGE_LENGTH] = {0};
        CHAR* cpMsgData = (CHAR*)(pBuf);
        INT32 nRet = pProtocol->Decode(wMsgID, cpMsgData, nLen, DecodeData,	PACKAGE_LENGTH);
        if(nRet <= 0 )
        {
            sprintf(szText, "[ MsgID = %d, Len = %d] decode error!", wMsgID);
            PrintText(szText, LOG_DESCRIBE);
            return;
        }
        sprintf(szText, "[ wMsgID = %d]", wMsgID);
        PrintText(szText, LOG_DESCRIBE);
        switch(wMsgID)
        {
        case CLIGT_ENDEC_KEY_NTF:
        {
            PKT_CLIGT_ENDEC_KEY_NTF* pNtf = (PKT_CLIGT_ENDEC_KEY_NTF*)DecodeData;
            PrintText("PKT_CLIGT_ENDEC_KEY_NTF\r\n{");
            sprintf(acTemp, "\t abyKeyInfo = \"%s\"", pNtf->abyKeyInfo);
            PrintText(acTemp);
            PrintText("}");
            CGlobe::m_poSeesion->SetKey(pNtf->abyKeyInfo, ENDEC_KEY_LEN);
            break;
        }
        case CLIZS_ENDEC_KEY_NTF:
        {
            PKT_CLIZS_ENDEC_KEY_NTF* pNtf = (PKT_CLIZS_ENDEC_KEY_NTF*)DecodeData;
            PrintText("PKT_CLIZS_ENDEC_KEY_NTF\r\n{");
            sprintf(acTemp, "\t abyKeyInfo = \"%s\"", pNtf->abyKeyInfo);
            PrintText(acTemp);
            PrintText("}");
            CGlobe::m_poSeesion->SetKey(pNtf->abyKeyInfo, ENDEC_KEY_LEN);
            break;
        }

        case CLIGT_HEARTBEAT_ACK:
        {
            PKT_CLIGT_HEARTBEAT_ACK* pAck = (PKT_CLIGT_HEARTBEAT_ACK*)DecodeData;
            PrintText("PKT_CLIGT_HEARTBEAT_ACK\r\n{");
            PrintText("}");
        }
        break;
        case CLILS_LOGIN_ACK:
        {
            PKT_CLILS_LOGIN_ACK* pAck = (PKT_CLILS_LOGIN_ACK*)DecodeData;
            PrintText("PKT_CLILS_LOGIN_ACK\r\n{");

            sprintf(acTemp, "\t nErrCode = %d", pAck->wErrCode);
            PrintText(acTemp);
            sprintf(acTemp, "\t aszDeviceID = \"%s\"", _SDTT2Local(pAck->aszDeviceID));
            PrintText(acTemp);
            sprintf(acTemp, "\t aszNotifyID = \"%s\"", _SDTT2Local(pAck->aszNotifyID));
            PrintText(acTemp);
            sprintf(acTemp, "\t aszUserName = \"%s\"", _SDTT2Local(pAck->aszUserName));
            PrintText(acTemp);
            sprintf(acTemp, "\t dwPlayerID = \"%u\"", pAck->dwPlayerID);
            PrintText(acTemp);

            PrintText("}");
            break;
        }


        case CLIGS_ENTERGS_ACK:
        {
            PKT_CLIGS_ENTERGS_ACK* pAck = (PKT_CLIGS_ENTERGS_ACK*)DecodeData;
            PrintText("PKT_CLIGS_ENTERGS_ACK\r\n{");

            sprintf(acTemp, "\t sizeof(PKT_CLIGS_ENTERGS_ACK) = %d", sizeof(PKT_CLIGS_ENTERGS_ACK));
            PrintText(acTemp);

            sprintf(acTemp, "\t nErrCode = %d", pAck->wErrCode);
            PrintText(acTemp);
            if(0 != pAck->wErrCode)
            {
                PrintText("}");
                break;
            }
            sprintf(acTemp, "\t dwID = %d", pAck->stPlayerInfo.dwID);
            PrintText(acTemp);
            sprintf(acTemp, "\t aszDispName = \"%s\"", _SDTT2Local(pAck->stPlayerInfo.aszDispName));
            PrintText(acTemp);
            sprintf(acTemp, "\t qwCoin = %d", pAck->stPlayerInfo.qwCoin);
            PrintText(acTemp);
            sprintf(acTemp, "\t qwGold = %d", pAck->stPlayerInfo.qwGold);
            PrintText(acTemp);
            sprintf(acTemp, "\t wLevel = %d", pAck->stPlayerInfo.wLevel);
            PrintText(acTemp);
            sprintf(acTemp, "\t wPhyStrength = %d", pAck->stPlayerInfo.stPhyStrengthInfo.wPhyStrength);
            PrintText(acTemp);
            sprintf(acTemp, "\t wMaxPhyStrength = %d", pAck->stPlayerInfo.stPhyStrengthInfo.wMaxPhyStrength);
            PrintText(acTemp);
            sprintf(acTemp, "\t wPhyStrengthCountDown = %d", pAck->stPlayerInfo.stPhyStrengthInfo.wPhyStrengthCountDown);
            PrintText(acTemp);
            sprintf(acTemp, "\t wPhyStrengthRefreshCD = %d", pAck->stPlayerInfo.stPhyStrengthInfo.wPhyStrengthRefreshCD);
            PrintText(acTemp);
            sprintf(acTemp, "\t dwExperience = %d", pAck->stPlayerInfo.stExperienceInfo.dwExperience);
            PrintText(acTemp);
            sprintf(acTemp, "\t dwUpgrateExperience = %d", pAck->stPlayerInfo.stExperienceInfo.dwUpgradeExperience);
            PrintText(acTemp);
            sprintf(acTemp, "\t dwScience = %d", pAck->stPlayerInfo.qwScience);
            PrintText(acTemp);

            PrintText("}");
            break;
        }

        case CLIGS_GET_HERO_INFO_ACK:
        {
            PKT_CLIGS_GET_HERO_INFO_ACK* pAck = (PKT_CLIGS_GET_HERO_INFO_ACK*)DecodeData;
            PrintText("PKT_CLIGS_GET_HERO_INFO_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_ENTER_HOME_ACK:
        {
            PKT_CLIGS_ENTER_HOME_ACK* pAck = (PKT_CLIGS_ENTER_HOME_ACK*)DecodeData;
            PrintText("PKT_CLIGS_ENTER_HOME_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_ENTER_INSTANCE_ACK:
        {
            PKT_CLIGS_ENTER_INSTANCE_ACK* pAck = (PKT_CLIGS_ENTER_INSTANCE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_ENTER_INSTANCE_ACK\r\n{");
            sprintf(acTemp, "\t nErrCode = %d", pAck->wErrCode);
            PrintText(acTemp);
            PrintText("}");
            break;
        }
        case CLIGS_BATTLE_ACK:
        {
            PKT_CLIGS_BATTLE_ACK* pAck = (PKT_CLIGS_BATTLE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_BATTLE_ACK\r\n{");
            /*
            sprintf(acTemp, "Myself CurHP:%d\n", pAck->stBattleInfo.stMyselfInfo.stCurTotalBattleAttr.dwHP);
            PrintText(acTemp);
            sprintf(acTemp, "Enemy CurHP:%d\n", pAck->stBattleInfo.stEnemyInfo.stCurTotalBattleAttr.dwHP);
            PrintText(acTemp);
            for(UINT8 byIdx = 0; byIdx < pAck->stBattleInfo.byBattleRoundNum; byIdx++)
            {
                DT_BATTLE_ROUND_DATA& stDT_BATTLE_ROUND_DATA = pAck->stBattleInfo.astBattleRoundInfo[byIdx];

                if(0 == stDT_BATTLE_ROUND_DATA.byAttackerFlag)
                {
                    sprintf(acTemp, "Myself Attack:");
                    PrintText(acTemp);
                }
                else
                {
                    sprintf(acTemp, "Enymy Attack:");
                    PrintText(acTemp);
                }

                sprintf(acTemp, "\t stBeforeAttack.dwMyselfBuffState:[%d][%d]", stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.astMyselfBuffState[0].wSkillID, stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.astMyselfBuffState[0].byBuffID);
                PrintText(acTemp);
                sprintf(acTemp, "\t stAfterAttack.dwMyselfBuffState:[%d][%d]\n", stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.astMyselfBuffState[0].wSkillID, stDT_BATTLE_ROUND_DATA.stAttackData.stAfterAttack.astMyselfBuffState[0].byBuffID);
                PrintText(acTemp);
                sprintf(acTemp, "\t stBeforeAttack.byCritDodge:%d", stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.byCritDodge);
                PrintText(acTemp);
                sprintf(acTemp, "\t stBeforeAttack.byMyselfHpChangeNum:%d, anMyselfHpChangeInfo[0]:%d",
                	stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.byMyselfHpChangeNum, stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.anMyselfHpChangeInfo[0]);
                PrintText(acTemp);
                sprintf(acTemp, "\t stBeforeAttack.byEnemyHpChangeNum:%d, anEnemyHpChangeInfo[0]:%d\n",
                	stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.byEnemyHpChangeNum, stDT_BATTLE_ROUND_DATA.stAttackData.stBeforeAttack.anEnemyHpChangeInfo[0]);
                PrintText(acTemp);

                sprintf(acTemp, "\t stAfterAttack.byCritDodge:%d", stDT_BATTLE_ROUND_DATA.stAttackData.stAfterAttack.byCritDodge);
                PrintText(acTemp);
                sprintf(acTemp, "\t stAfterAttack.byMyselfHpChangeNum:%d, anMyselfHpChangeInfo[0]:%d",
                	stDT_BATTLE_ROUND_DATA.stAttackData.stAfterAttack.byMyselfHpChangeNum, stDT_BATTLE_ROUND_DATA.stAttackData.stAfterAttack.anMyselfHpChangeInfo[0]);
                PrintText(acTemp);
                sprintf(acTemp, "\t stAfterAttack.byEnemyHpChangeNum:%d, anEnemyHpChangeInfo[0]:%d\n",
                	stDT_BATTLE_ROUND_DATA.stAttackData.stAfterAttack.byEnemyHpChangeNum, stDT_BATTLE_ROUND_DATA.stAttackData.stAfterAttack.anEnemyHpChangeInfo[0]);
                PrintText(acTemp);


            }
            */
            PrintText("}");
            break;
        }
        case CLIGS_EXIT_INSTANCE_ACK:
        {
            PKT_CLIGS_EXIT_INSTANCE_ACK* pAck = (PKT_CLIGS_EXIT_INSTANCE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_EXIT_INSTANCE_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_GET_SCENE_INSTANCE_ACK:
        {
            PKT_CLIGS_GET_SCENE_INSTANCE_ACK* pAck = (PKT_CLIGS_GET_SCENE_INSTANCE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_GET_SCENE_INSTANCE_ACK\r\n{");

            PrintText("}");
            break;
        }

        case CLIGS_OPEN_SMITHY_ACK:
        {
            PKT_CLIGS_OPEN_SMITHY_ACK* pAck = (PKT_CLIGS_OPEN_SMITHY_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_SMITHY_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_EQUIP_STRENGTHEN_ACK:
        {
            PKT_CLIGS_EQUIP_STRENGTHEN_ACK* pAck = (PKT_CLIGS_EQUIP_STRENGTHEN_ACK*)DecodeData;
            PrintText("PKT_CLIGS_EQUIP_STRENGTHEN_ACK\r\n{");

            PrintText("}");
            break;
        }

        case CLIGS_OPEN_RECRUIT_ACK:
        {
            PKT_CLIGS_OPEN_RECRUIT_ACK* pAck = (PKT_CLIGS_OPEN_RECRUIT_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_RECRUIT_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_RECRUIT_HERO_ACK:
        {
            PKT_CLIGS_RECRUIT_HERO_ACK* pAck = (PKT_CLIGS_RECRUIT_HERO_ACK*)DecodeData;
            PrintText("PKT_CLIGS_RECRUIT_HERO_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_OPEN_BAG_ACK:
        {
            PKT_CLIGS_OPEN_BAG_ACK* pAck = (PKT_CLIGS_OPEN_BAG_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_BAG_ACK\r\n{");

            PrintText("}");
            break;
        }

        case CLIGS_OPEN_RACE_BUILD_ACK:
        {
            PKT_CLIGS_OPEN_RACE_BUILD_ACK* pAck = (PKT_CLIGS_OPEN_RACE_BUILD_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_RACE_BUILD_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_RECV_RANK_ENCOURAGE_ACK:
        {
            PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK* pAck = (PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_RECV_RANK_ENCOURAGE_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_BUY_ITEM_ACK:
        {
            PKT_CLIGS_BUY_ITEM_ACK* pAck = (PKT_CLIGS_BUY_ITEM_ACK*)DecodeData;
            PrintText("PKT_CLIGS_BUY_ITEM_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_RECV_TASK_ENCOURAGE_ACK:
        {
            PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK* pAck = (PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_RECV_TASK_ENCOURAGE_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_EMBATTLE_ACK:
        {
            PKT_CLIGS_EMBATTLE_ACK* pAck = (PKT_CLIGS_EMBATTLE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_EMBATTLE_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_EQUIP_ACK:
        {
            PKT_CLIGS_EQUIP_ACK* pAck = (PKT_CLIGS_EQUIP_ACK*)DecodeData;
            PrintText("PKT_CLIGS_EQUIP_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_CHALLENGE_ACK:
        {
            PKT_CLIGS_CHALLENGE_ACK* pAck = (PKT_CLIGS_CHALLENGE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_CHALLENGE_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_GET_HERO_DRUG_ACK:
        {
            PKT_CLIGS_GET_HERO_DRUG_ACK* pAck = (PKT_CLIGS_GET_HERO_DRUG_ACK*)DecodeData;
            PrintText("PKT_CLIGS_GET_HERO_DRUG_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_USE_DRUG_ACK:
        {
            PKT_CLIGS_USE_DRUG_ACK* pAck = (PKT_CLIGS_USE_DRUG_ACK*)DecodeData;
            PrintText("PKT_CLIGS_USE_DRUG_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_OPEN_ITEM_MAKER_ACK:
        {
            PKT_CLIGS_OPEN_ITEM_MAKER_ACK* pAck = (PKT_CLIGS_OPEN_ITEM_MAKER_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_ITEM_MAKER_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_MAKE_ITEM_ACK:
        {
            PKT_CLIGS_MAKE_ITEM_ACK* pAck = (PKT_CLIGS_MAKE_ITEM_ACK*)DecodeData;
            PrintText("PKT_CLIGS_MAKE_ITEM_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_DISBAND_HERO_ACK:
        {
            PKT_CLIGS_DISBAND_HERO_ACK* pAck = (PKT_CLIGS_DISBAND_HERO_ACK*)DecodeData;
            PrintText("PKT_CLIGS_DISBAND_HERO_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK:
        {
            PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK* pAck = (PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_INSTANCE_ENCOURAGE_BOX_ACK\r\n{");

            PrintText("}");
            break;
        }
        case CLIGS_OPEN_EMBATTLE_ACK:
        {
            PKT_CLIGS_OPEN_EMBATTLE_ACK* pAck = (PKT_CLIGS_OPEN_EMBATTLE_ACK*)DecodeData;
            PrintText("PKT_CLIGS_OPEN_EMBATTLE_ACK\r\n{");

            PrintText("}");
            break;

        }
        case CLIGS_SYNC_TIME_ACK:
        {
            PKT_CLIGS_SYNC_TIME_ACK* pAck = (PKT_CLIGS_SYNC_TIME_ACK*)DecodeData;
            PrintText("PKT_CLIGS_SYNC_TIME_ACK\r\n{");

            PrintText("}");
            break;

        }

        case CLIGT_SELECT_ZONE_ACK:
        {
            PKT_CLIGT_SELECT_ZONE_ACK* pAck = (PKT_CLIGT_SELECT_ZONE_ACK*)DecodeData;
            PrintText("PKT_CLIGT_SELECT_ZONE_ACK\r\n{");

            PrintText("}");
            break;
        }

        case CLILS_BIND_ACK:
        {
            PKT_CLILS_BIND_ACK* pAck = (PKT_CLILS_BIND_ACK*)DecodeData;
            PrintText("PKT_CLILS_BIND_ACK\r\n{");
            PrintText("}");
            break;
        }
        break;
		case CLIGS_OPEN_AWAKEN_TAB_ACK:
		{
			PKT_CLIGS_OPEN_AWAKEN_TAB_ACK* pAck = (PKT_CLIGS_OPEN_AWAKEN_TAB_ACK*)DecodeData;
			PrintText("PKT_CLIGS_OPEN_AWAKEN_TAB_ACK\r\n{");
			PrintText("}");
			break;
		}

        default:
        {
            PrintText("[ δ����Э�顣]", LOG_ERROR);
        }
        }
    }
    else
    {
        PrintText("[ Э�����ʧ�ܡ�]", LOG_ERROR);
    }
}
