///<------------------------------------------------------------------------------
//< @file:   gateconfig.h
//< @author: ������
//< @date:   2015��11��2��
//< @brief:
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gateconfig_h_
#define _gateconfig_h_

struct IpPort {
	IpPort()
		: port(0)
	{}

	std::string ip;
	int			port;
};

struct GateConfig {
	GateConfig()
		: m_wanThreadNum(0)
		, m_lanThreadNum(0)
		, m_enableEncrypt(false)
		, m_maxPlayers(0)
		, m_sleep(0)
	{
		m_encryptKey[0] = '\0';
	}

	bool load(const char* configFile);

	IpPort				m_wanListen;		// ������������
	std::vector<IpPort> m_lanListens;		// ���������б�
	std::vector<IpPort> m_lanConnects;		// �������������б�

	int					m_wanThreadNum;		// �����߳���
	int					m_lanThreadNum;		// �����߳���

	bool				m_enableEncrypt;	// �Ƿ�������
	char				m_encryptKey[16];	// ����key

	int					m_maxPlayers;		// ���������ɵ���������������������ҽ��޷���¼��
	uint16				m_sleep;			// ������ÿ����ѭ�����sleepʱ�䣬��λ���루���ڷ�ֹ����cpu��
};

#endif // _gateconfig_h_