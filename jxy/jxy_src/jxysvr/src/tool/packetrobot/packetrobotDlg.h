// PacketRobotDlg.h : header file
//
#ifndef PACKETROBOTDLG_H_
#define PACKETROBOTDLG_H_
#pragma once

#include "afxcmn.h"
#include "protocolmgr.h"
#include "clipktparser.h"
#include "Resource.h"
#include <list>

using namespace SGDP;

// �����־����
#define LOG_MAX_LENGTH 102400
// ��������
#define INPUT_MAX_COUNT 8
// ������ɷ���ʱ��
#define TIMER_ID_LOADFINISH 1
// ������ʱ��
#define TIMER_ID_HEARTBEAT 2
// Ƶ���ƶ�
#define TIMER_ID_MOVEVAST 3

// ��־����
typedef enum eLogType
{
	LOG_DATA,
	LOG_DESCRIBE,
	LOG_ERROR,
	LOG_NOPRINT
}LogType;

// CPacketRobotDlg dialog
class CPacketRobotDlg : public CDialog
{
// Construction
public:
	CPacketRobotDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PACKETROBOT_DIALOG };

protected:
	virtual VOID DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	ISDNet* m_pISDClient;
    ISDConnector* m_poConnector;

	// Generated message map functions
	virtual SDBOOL OnInitDialog();
	afx_msg VOID OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	// ---------------- ��  �� ----------------

	// ���ӷ�����
	UINT32 ConnectServer(const CHAR* _IP, const UINT32 _Port);
	// �Ͽ�����
	VOID CutOffServer();
	// ���ӳɹ�
	virtual VOID SDAPI OnConnect(INT32 nErrorCode);
	// �Ͽ�����
	virtual VOID SDAPI OnDisConnect(INT32 nErrorCode);
	// ��������
	virtual VOID SDAPI OnRecvMsg(UINT16 wMsgID, const CHAR* pBuf, INT32 nLen);

	// ---------------- ����Э�� ----------------
	// ��������
	VOID SendHeartBeat(UINT8 _ExtInfo = 0);
	// У��ʱ��
	VOID SendCheckTime();


    // ���ͳ�����Ϣ
    VOID Send_COMMON(INT32 nMsgID, VOID* pReq, const CHAR* szDescription);

	// ---------------- �������� ----------------

	// ��ӡ��־
	VOID PrintText(const CHAR* cpText, const LogType _LogType = LOG_DATA);
	// ��ӡ��־
	VOID WriteText(const TCHAR* cpText, const LogType _LogType = LOG_DATA);
	// �����ṹ����־
	VOID ParseLog(const CHAR* _Log);
	// ˢ��Э���
	VOID FlushList();


	// ���������
	VOID AdjustEdit(INT32 _Index, CHAR* Caption, CHAR* Value);
	// ��������
	VOID ClearInput();
	// ��������
	VOID AdjustInput(INT32 _Index);

public:
	// ---------------- UI�ӿ� ----------------

	// ���ӷ�����
	afx_msg VOID OnBnClickedOk();
	// �Ͽ�
	afx_msg void OnBnClickedButtonCut();
	// ���ͱ���
	afx_msg VOID OnBnClickedButtonSend();
	// �����Ϣ��
	afx_msg void OnBnClickedButtonClear();
	// �˳�
	afx_msg VOID OnBnClickedCancel();
	// ѡ��Э��
	afx_msg VOID OnNMClickListSelect(NMHDR *pNMHDR, LRESULT *pResult);
	// ѡ�нṹ��
	afx_msg void OnTvnSelchangedTreeStruct(NMHDR *pNMHDR, LRESULT *pResult);
	// 
	afx_msg VOID OnTimer(UINT_PTR nIDEvent);

private:
	// �б�ؼ�
	CListCtrl m_lcList;
	// Rich Edit
	CRichEditCtrl m_richEdit;
	// �ṹ��չʾ
	CTreeCtrl m_Tree;
	// ��Դ����
	std::list<CHAR*> m_LsResource;
	// �û�Id����
	CHAR m_szUserId[USERNAME_LEN];
	
};

#endif

