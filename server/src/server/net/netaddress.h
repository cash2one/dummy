///<------------------------------------------------------------------------------
//< @file:   server\net\netaddress.h
//< @author: ������
//< @date:   2014��11��25�� 15:14:15
//< @brief:  ����ip��ַ��װ��
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _netaddress_h_
#define _netaddress_h_

#include <string>

using namespace std;

// ����ip��ַ��װ��
class NetAddress
{
public:
	// ���ݶ˿ڽ��й��죬һ������listen
	explicit NetAddress(uint16 port = 0);

	// ����ip�Ͷ˿ڽ��й��죬ip��ʽ��"x.x.x.x"
	explicit NetAddress(const std::string &ip, uint16 port);

	// ����sockaddr_in���й��죬һ���ڽ���������ʱ���õ�
	explicit NetAddress(const struct sockaddr_in& addr)
		: m_addr(addr)
	{
	}

	// ��ȡ��Ӧ��ip�ַ���
	string toIp() const;

	// ��ȡip:port�ı�
	string toIpPort() const;

	// ��ȡ�˿ں�
	uint16 toPort() const;

	// ��ȡsockaddr_in�ṹ��
	inline const struct sockaddr_in& getSockAddr() const { return m_addr; }

	// �������õ�ַ
	inline void setSockAddr(const struct sockaddr_in& addr) { m_addr = addr; }

	// ��ȡ�����ֽ����ip
	uint32 ipNetEndian() const { return m_addr.sin_addr.s_addr; }

	// ��ȡ�����ֽ���Ķ˿�
	uint16 portNetEndian() const { return m_addr.sin_port; }

	// ����ָ����host
	static bool resolve(string hostname, NetAddress* result);

public:
	struct sockaddr_in m_addr;
};

#endif //_netaddress_h_