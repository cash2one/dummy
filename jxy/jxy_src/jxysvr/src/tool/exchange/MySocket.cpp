// MySocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exchange.h"
#include "MySocket.h"
#include "exchangeDlg.h"


// MySocket

MySocket::MySocket()
{

}

MySocket::~MySocket()
{
}


// MySocket ��Ա����


void MySocket::OnClose(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	//if (0 == nErrorCode)
	{
		m_poExchangeDlg->OnClose(nErrorCode);
	}
	CAsyncSocket::OnClose(nErrorCode);
}


void MySocket::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (0 == nErrorCode)
	{
		m_poExchangeDlg->OnConnect(nErrorCode);
	}
	CAsyncSocket::OnConnect(nErrorCode);
}


void MySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (0 == nErrorCode)
	{
		m_poExchangeDlg->OnReceive(nErrorCode);
	}
	CAsyncSocket::OnReceive(nErrorCode);
}


void MySocket::SetParent(CExchangeDlg * poExchangeDlg)
{
	m_poExchangeDlg = poExchangeDlg;
}