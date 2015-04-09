
#ifndef _PLAYERMGR_H_
#define _PLAYERMGR_H_

#include "player.h"
#include <sdsingleton.h>
#include <protogsdb.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <protocol/server/protocommondata.h>
#include <net/cli/user.h>


using namespace SGDP;

#define SAVE_PLAYER_DATA_SQL "../SavePlayerDataSql"

typedef map<UINT32, CPlayer*> CID2PlayerMap;
typedef CID2PlayerMap::iterator	CID2PlayerMapItr;
typedef CID2PlayerMap::const_iterator CID2PlayerMapConstItr;

typedef vector<UINT16>      SSkillVec;
typedef SSkillVec::iterator SSkillVecItr;

typedef vector<UINT32> CID2PlayerVec;
typedef CID2PlayerVec::iterator	CID2PlayerVecItr;


/**
* @brief ��ҹ�����
*/
class CPlayerMgr
{
public:
    DECLARE_SINGLETON(CPlayerMgr)

    /**
    * @brief
    * ��ʼ������,��ȡ�����ļ���
    * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
    */
    BOOL Init();

    /**
    * @brief
    * ж�غ���
    */
    VOID UnInit();

public:
    CPlayer*			FindPlayer(UINT32 dwPlayerID);

    CPlayer*			CreatePlayer(UINT32 dwPlayerID);

    VOID				RemovePlayer(UINT32 dwPlayerID);

	const CID2PlayerMap &	GetID2PlayerMap(){return m_mapID2PlayerMap;};

	void				GetID2PlayerVec(CID2PlayerVec &vecPlayerCache);


public:
    BOOL	CreateNewPlayer(UINT32 dwTransID, CUser* poUser);//��������ң�CareerID��Ч����FALSE
	BOOL	CreateNewPlayerInMem(UINT32 dwTransID, CUser* poUser);//��������������ڴ棬���������	
    BOOL	CreateNewPlayerGM(UINT32 dwPlayerID, UINT8 byRobotFunc = ERFK_OTHER, UINT16 wLevel = 1, TCHAR* pszDspName = NULL);//���������(GM)
	BOOL	CreateNewPlayerGMMoreParam(UINT32 dwPlayerID, UINT16 wCareerID, UINT32 dwAmount, UINT32 dwTotalAmount, UINT8 byVipLevel, TCHAR* pszDspName, TCHAR* pszDeviceID, TCHAR* pszNotifyID);//���������

public:
    VOID	OnSaveOnlineEvent(UINT32 dwPlayerID);//���������Ϣ�¼��ص��������������
    VOID	OnSaveCkOfflineEvent(UINT32 dwPlayerID);//����/���ǵ�¼���������ݣ���������ڴ������
    VOID	SaveAllPlayerData();////���������������,�����˳�����ʱ
	VOID    GetTodaySavePlayerPath(TCHAR* aszSavePath, UINT32 dwPlayerID);//��ұ���·��
	BOOL	RetreatePlayerData(const UINT32 &dwPlayerId,string strFile,UINT64 dwTime);//���и�����ҵ����ݻص�
	BOOL	AllPlayerRetreate(UINT32 dwTransID);//��������ҽ��лص�ʱ���̻ض�ʧ�ĳ�ֵ��¼

    //VOID	ClrPlayerData(CPlayer* poPlayer);//���������ݣ�fortest��

protected:
	BOOL	SetFormationByHeroID(UINT16 wCoachHeroID, DT_NEW_FORMATION_DATA& stFormationInfo);
	BOOL	SetFormationByHeroID(vector<UINT16>& vecHeroID, DT_NEW_FORMATION_DATA& stFormationInfo);

protected:
    BOOL	InitPlayerDefault();

    BOOL	ReadPlayerDefaltBase();

protected:


protected:
    CPlayerMgr();
    ~CPlayerMgr();

private:
    DT_PLAYER_DATA					m_stPlayerDefault;//������ҳ�ʼĬ������
    CID2PlayerMap						m_mapID2PlayerMap;
    //CSDObjectPool<CPlayer, CSDMutex>	m_oPlayerShmemObjMgr;	
};



#endif //#ifndef _PLAYERMGR_H_

