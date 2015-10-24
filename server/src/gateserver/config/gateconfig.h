#ifndef _gateconfig_h_
#define _gateconfig_h_

struct IpPort {
	IpPort()
		: port(0)
	{}

	std::string ip;
	int port;
};

struct GateConfig {
	GateConfig()
		: m_wanThreadNum(0)
		, m_lanThreadNum(0)
		, m_enableEncrypt(false)
		, m_maxPlayers(0)
		, m_sleepMsEachLoop(0)
	{
		m_encryptKey[0] = '\0';
	}

	bool load(const char* configFile);

	IpPort m_wanListen;
	std::vector<IpPort> m_lanListens;
	std::vector<IpPort> m_lanConnects;

	int m_wanThreadNum;
	int m_lanThreadNum;

	bool m_enableEncrypt;
	char m_encryptKey[16];

	int m_maxPlayers; // ���������ɵ���������������������ҽ��޷���¼��
	uint16 m_sleepMsEachLoop; // ������ÿ����ѭ�����sleepʱ�䣬��λ���루���ڷ�ֹ����cpu��
};

#endif