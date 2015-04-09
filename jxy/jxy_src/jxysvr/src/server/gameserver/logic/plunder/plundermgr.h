
#ifndef _PLUNDERMGR_H_
#define _PLUNDERMGR_H_

#include "plunder.h"
#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdmutex.h>
#include <protocol/server/protocligs.h>
#include <common/client/commondef.h>
#include <logic/player/playerbasedatacachemgr.h>
#include <logic/event/releasecaptureevent.h>

using namespace SGDP;
using namespace std;

typedef HashMap<UINT32, CPlunder*> CID2PlunderMap;
typedef CID2PlunderMap::iterator	CID2PlunderMapItr;


class CPlunderMgr
{

public:
    DECLARE_SINGLETON(CPlunderMgr)

    BOOL Init();

    VOID UnInit();

public:

public:
    BOOL		Plunder(CPlayer* poMyself, CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, DT_BATTLE_DATA5& stDT_BATTLE_DATA, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage);
    BOOL		Plunder2(CPlayer* poMyself, CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, DT_BATTLE_DATA3& stDT_BATTLE_DATA, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage);
	BOOL		Plunder3(CPlayer* poMyself, CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, DT_BATTLE_DATA4& stDT_BATTLE_DATA, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage);
    UINT16	OpenPlunderScence(CPlayer* poOwner, UINT16& wCanPlunderNum, UINT16& wFreePlunderNum, UINT32& dwPlunderGold,  UINT16& wPlunderItemNum,
                                  UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM]);//���Ӷ᳡��(�Ƽ��Ӷ����)

    VOID		GetPlunderLevelGapItem(UINT8& byUseItemGapLevel, UINT32& dwPlunderItemPrice, UINT16& wPlunderItemID);

    UINT16	RefreshPlunderRecommend(CPlayer* poOwner, UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM]);//�����Ӷ����

    BOOL		AddReleaseBattleLog(UINT32 dwOwnerID, UINT32 dwCaptureID, EPlunderBattleLogType eReleaseType, UINT32 dwCoin, UINT32 dwScience);//��ӷ�²�ͷ�ս��
public:
    VOID		OnReleaseCaptureEvent(UINT32 dwOwnerID, UINT32 dwCaptureID); //���ͷŷ�²�¼�
    VOID		GetLeftIncome(CPlayer* poOwner, UINT32 dwCaptureID, UINT32& dwCoin, UINT32& dwScience, BOOL bManualFree = FALSE);//��ȡ��������
protected:
    BOOL OnPlunder(CPlayer* poMyself, CPlayer* poEney, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stReqRaram, BOOL bChallengeSuccess, DT_PLUNDER_ENCOURAGE_DATA& stPlunderEncourage);//�Ӷ�ص�
    BOOL AddPlunderBattleLog(CPlayer* poMyself, CPlayer* poEney, CPlayer* poCapture, UINT8 byResistFlag, BOOL bChallengeSuccess, UINT64 qwPlunderCoin, UINT64 qwPlunderScience); //����Ӷ�ս��
    EPlunderBattleLogType GetPlunderBattleLogType(CPlayer* poEney, CPlayer* poCapture, UINT8 byResistFlag);
    VOID CaptureChange(CPlayer* poMyself, CPlayer* poEney, CPlayer* poCapture, UINT8 byResistFlag, UINT8 byCaptureGridIdx, BOOL bChallengeSuccess);
    VOID PlunderEncourage(CPlayer* poMyself, CPlayer* poEney, UINT8 byResistFlag, BOOL bChallengeSuccess, UINT32& dwCoin, UINT32& dwScience);//�Ӷ��²����
    BOOL InitRobot();//��ʼ���Ӷ������
    VOID GetRecommendRobot(UINT16 wLevel, UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM], CPlunder &oOwnPlunder);//��ȡ�Ƽ���ң�20~21 ������
    VOID GetRecommendLimit(UINT32 dwPlayerID, UINT16 wPlayerLevel, SRecommendPlayerRcd& stRecommendPlayerRcd, UINT8& byPlunderPlayerNum,
                           DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM], BOOL bNotBecapture, CPlunder &oOwnPlunder);//��ȡ�Ƽ���ң�22~25 û�б���²,25���� �ȼ�����
    VOID GetPlayerData(CPlayerBaseDataVec& vecPlayer, UINT8& byPlunderPlayerNum, DT_PLUNDER_PLAYER_DATA astPlunderPlayerInfo[MAX_GET_PLUNDER_ENEMY_NUM], C3232Map& mapHave);//��ȡ�����Ϣ
protected:
    CPlunderMgr();
    ~CPlunderMgr();


private:
    DT_PLUNDER_PLAYER_DATA				m_astPlunderRobot[MAX_ROBOT_NUM];//�Ӷ������
    BOOL								m_bRobotInit; //�������Ƿ��ʼ��
    UINT32								m_dwPlunderItemPrice;//�Ӷ���߼۸�
    UINT16								m_wPlunderItemID;//�Ӷ����ID
    UINT32								m_dwCaptureWorkSecond;//��²����ʱ��
    UINT16								m_wPlunderOpenLevel;//�ӶῪ�ŵȼ�
};



#endif

