// EditListCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Lookup.h"
#include "EditListCtrl.h"


// CEditListCtrl

#define ID_LISTEDIT WM_USER + 301

IMPLEMENT_DYNAMIC(CEditListCtrl, CListCtrl)

CEditListCtrl::CEditListCtrl()
{
    m_edit = NULL;
    m_item = -1;
    m_subitem = -1;
}

CEditListCtrl::~CEditListCtrl()
{
}


BEGIN_MESSAGE_MAP(CEditListCtrl, CListCtrl)
    ON_NOTIFY_REFLECT(NM_CLICK, &CEditListCtrl::OnNMClick)
    ON_NOTIFY_REFLECT(NM_SETFOCUS, &CEditListCtrl::OnNMSetfocus)
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
    ON_NOTIFY_REFLECT(NM_RCLICK, &CEditListCtrl::OnNMRClick)
END_MESSAGE_MAP()



// CEditListCtrl ��Ϣ�������

void CEditListCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    if(!m_edit)
    {
        m_subitem = pNMListView->iSubItem;
        if(pNMListView->iItem != m_item)
        {
            m_item = pNMListView->iItem; //��־����������Ŀ
            return;
        }
    }

    RECT m_itemrect, m_r;
    GetItemRect(m_item , &m_itemrect, 2);
    GetItemRect(0 , &m_r, 2);
    int m_height = m_itemrect.bottom - m_itemrect.top ;
    int x = m_r.left , y = m_r.top, cx, cy; //(x,y,cx,cy)Ϊ�༭����ʾ��λ��
    for(int i = 0; i < m_item; i++)
        y += m_height;
    cy = y + m_height;
    int i = 0;
    for(i = 0; i < m_subitem; i++)
        x += GetColumnWidth(i);
    cx = x + GetColumnWidth(i);
    if(m_edit)//���༭���Ѵ��ڡ�
    {
        CString s1;
        s1.Format ("%d %d %d %d", x, y, cx, cy);
        m_edit->MoveWindow(x, y, cx - x, cy - y); //�ƶ�����ǰ����Ŀ��λ�á�
        Invalidate();//ˢ����Ļ��
        return;
    }
    //���༭�򲻴���,�򴴽��༭��,���ڵ�ǰ����Ŀ����ʾ�༭��
    CRect rect(x, y, cx, cy);
    m_edit = new CEdit();
    m_edit->Create (WS_CHILD | WS_VISIBLE | WS_BORDER, rect, this, ID_LISTEDIT);
    CString str = GetItemText (pNMListView->iItem, pNMListView->iSubItem);
    m_edit->UpdateData(0);
    m_edit->SetWindowText(str);
    DWORD dwSel = m_edit->GetSel();
    m_edit->SetSel(HIWORD(dwSel), -1);
    m_edit->ShowWindow (SW_SHOW);//��ʾ�༭��
    m_edit->SetFocus ();
    *pResult = 0;
}


void CEditListCtrl::OnNMSetfocus(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if(m_edit)
    {
        //���༭���е�����д�ض�Ӧ������Ŀ��
        UpdateData( );
        CString str;
        m_edit->GetWindowText(str);
        SetItemText(m_item, m_subitem, str);
        delete m_edit;
        m_edit = NULL;
    }
    *pResult = 0;
}


void CEditListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    //ˮƽ����ʱ,�ƶ�����ʾ�ı༭��
    CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
    LRESULT* pResult = new LRESULT;
    if(m_edit)
        OnNMClick((NMHDR*)this, pResult) ;
}


void CEditListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    //��ֱ����ʱ,�ƶ�����ʾ�ı༭��
    CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
    LRESULT* pResult = new LRESULT;
    if(m_edit)
    {
        RECT m_itemrect, m_headrect;
        GetItemRect(m_item , &m_itemrect, 2);
        GetHeaderCtrl()->GetWindowRect(&m_headrect);
        if(m_itemrect.top < m_headrect.bottom - m_headrect.top)
        {
            RECT m_rect;
            m_edit->GetWindowRect(&m_rect);
            m_edit->MoveWindow(m_rect.left, -(m_rect.bottom - m_rect.top), m_rect.right, 0);
        }
        else
        {
            OnNMClick((NMHDR*)this, pResult) ;
        }
    }
}

BOOL CEditListCtrl::DestroyWindow()
{
    if (m_edit)
    {
        delete m_edit;
    }
    // TODO: �ڴ����ר�ô����/����û���
    return CListCtrl::DestroyWindow();
}

void CEditListCtrl::OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    POINT pt = {0};
    GetCursorPos(&pt);//�õ������λ��
    *pResult = 0;
}


void CEditListCtrl::OnAddLine()
{
    // TODO: �ڴ���������������
    int nCount = GetItemCount();
    InsertItem(nCount, "(NULL)");
}


void CEditListCtrl::OnDeleteLine()
{
    // TODO: �ڴ���������������
    int nSelIndex = GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
    if(nSelIndex == -1)
        return;
    DeleteItem(nSelIndex);
}
