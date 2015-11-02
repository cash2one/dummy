///<------------------------------------------------------------------------------
//< @file:   gameconfig.h
//< @author: ������
//< @date:   2015��11��2��
//< @brief:	 ��Ϸ����������
//< Copyright (c) 2015 ������. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _gameconfig_h_
#define _gameconfig_h_

struct IpPort {
	IpPort()
		: port(0)
	{}

	std::string ip;
	int			port;
	std::string peerName;
};

class GameConfig : public Singleton<GameConfig>
{
public:
	GameConfig()
		: m_lanThreadNum(0)
		, m_saveToDBInterval(0)
		, m_sleep(0)
	{}

	bool load(const char* configFile);

	std::vector<IpPort> m_lanConnects;		// �������������б�
	int					m_lanThreadNum;		// �����߳���

	int					m_saveToDBInterval;	// ���ݱ��浽���ݿ��ʱ��������λ����
	int					m_sleep;			// ÿ����Ϸ��ѭ����sleep��ʱ�䣬��λ����
};

#endif // _gameconfig_h_