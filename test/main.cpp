/*************************************************************************
    > File Name: vectordtor_main.cpp
    > Author: 
    > Mail:  
    > Created Time: Sun 22 Dec 2013 09:56:39 PM PST
************************************************************************/

#include<iostream>
#include <vector>
#include <string>
#include <memory.h>
#include "sdobjectpool.h"
#include <map>

using namespace std;

 struct DT_PLUNDER_BASE_DATA{
    int byHaveDataFlag; //�Ƿ�������(����DB������0��û������)
    int dwCaptureOwnerPlayerID; //��²������ID��0��ʾû�б���²
    int qwBeCaptureTime; //����²��ʱ��
    int wExtPlunderNum; //�������ӵ��Ӷ����
    int qwLastPlunderTime; //�ϴ��Ӷ�ʱ��
    int wLastPlunderNum; //�ϴ�(����)�Ӷ����
    int wLastDriveAwayNum; //�ϴ�(����)���Ϸ�²������
};

struct SPlunderSaveData
{
    SPlunderSaveData() { dwPlayerID = 0; memset(&stPlunderBaseData, 0, sizeof(stPlunderBaseData));}
    ~SPlunderSaveData(){};

    int dwPlayerID;
    DT_PLUNDER_BASE_DATA stPlunderBaseData; //�Ӷ������Ϣ
};

typedef vector<SPlunderSaveData*> PlunderVec;
class CPlayersPlunderSaveData
{
public:
    CPlayersPlunderSaveData(){ m_wErrCode = 0; m_vecPlunderSaveData.clear();}; 
    ~CPlayersPlunderSaveData(){};

	void print()
	{
		std::cout << "current size = " << m_vecPlunderSaveData.size() << std::endl;
		for(PlunderVec::iterator itr = m_vecPlunderSaveData.begin(); itr != m_vecPlunderSaveData.end(); ++itr)
		{
			SPlunderSaveData *p = *itr;
			p->dwPlayerID = 0;
		}
	}

public:
    PlunderVec  m_vecPlunderSaveData;
    int				          m_wErrCode;
};

class Test
{
public:
	void vectordtortest()
	{
		CPlayersPlunderSaveData *playerData = m_oPlayersPlunderSaveDataPool.Alloc();
		SPlunderSaveData plunderData;

		for(int i = 0; i < 1000; i++)
		{
			playerData->m_vecPlunderSaveData.push_back(&plunderData);
		}

		m_oPlayersPlunderSaveDataPool.Free(playerData);

		// playerData->~CPlayersPlunderSaveData();
		playerData = m_oPlayersPlunderSaveDataPool.Alloc();
		playerData->print();
	}

private:
    CSDObjectPool<CPlayersPlunderSaveData> m_oPlayersPlunderSaveDataPool;
};

class Player
{
public:
	Player(int playerId)
		: m_playerId(playerId)
	{
	}

private:
	int m_playerId;
};

typedef std::map<int, Player*> PlayerMap;
class MapEraseTest
{
public:
	void test()
	{
		char dummy[102400 * 1024] = {0};
		int len = sizeof(dummy);
		dummy[sizeof(dummy) - 1] = '\0';

		for(int i = 0; i < len; i++)
		{
			dummy[i] = (char)i;
		}

		std::cout << "dummy size = " << sizeof(dummy) << std::endl;

		PlayerMap players;
		for(int i = 1; i < 10000; i++)
		{
			players[i] = new Player(i);
		}


		for(int j = 1; j <= 10000; j++)
		{
			m_players = players;
			for(PlayerMap::iterator itr = m_players.begin(); itr != m_players.end(); )
			{
				m_players.erase(itr++);	
			}
		}


		if(m_players.empty())
		{
			std::cout << "ok: playermap is empty" << std::endl;
		}
		else
		{
			std::cout << "fail: playermap is not empty" << std::endl;
		}
	}

private:
	PlayerMap m_players;
};

int main(int argc, char *argv[])
{
	MapEraseTest test;
	test.test();

	return 0;
}
