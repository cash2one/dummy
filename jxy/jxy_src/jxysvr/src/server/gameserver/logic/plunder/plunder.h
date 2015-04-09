#ifndef _PLUNDER_H_
#define _PLUNDER_H_

#include <sdtype.h>
#include <logic/base/basedefine.h>
#include <logic/base/baseobj.h>
#include <logic/shmem/shmemmap.h>
#include <set>
#include <common/server/utility.h>
#include <protocligs.h>

using namespace std;

class CPlunderCapture;
class CPlunderBattleLog;

//typedef CShmemMap<UINT8, CPlunderBattleLog, MAX_PLUNDER_BATTLELOG_NUM> CPlunderBattleLogMap;//keyΪ���1��30
//typedef CPlunderBattleLogMap::iterator CPlunderBattleLogMapItr;
typedef deque<CPlunderBattleLog*> CPlunderBattleLogDeq;
typedef CPlunderBattleLogDeq::iterator CPlunderBattleLogDeqItr;


typedef CShmemMap<UINT32, CPlunderCapture> CPlayerID2CaptureMap;//keyΪ��²�����ID
//typedef CPlayerID2CaptureMap::iterator CPlayerID2CaptureMapItr;
typedef CShmemMap<UINT8, CPlunderCapture> CGridIdx2CaptureMap;//keyΪ��²�������
//typedef CGridIdx2CaptureMap::iterator CGridIdx2CaptureMapItr;

typedef map<UINT32, PKT_CLIGS_PLUNDER_REQ> CPKT_CLIGS_PLUNDER_REQMap; //keyΪ���ID
typedef CPKT_CLIGS_PLUNDER_REQMap::iterator CPKT_CLIGS_PLUNDER_REQMapItr;

class CPluderBuild;
class CPlayer;


class CPlunder:public CBaseObj
{
	friend class CPluderBuild;
public:
	CPlunder();
	~CPlunder();
public:
	BOOL Init(DT_PLUNDER_DATA& stDT_PLUNDER_DATA, CPlayer* poOwner);
	DT_PLUNDER_BASE_DATA& GetDT_PLUNDER_BASE_DATA() { return m_stDT_PLUNDER_BASE_DATA; }
	//CPlayer* GetOwner() { return m_poOwner; }
	/////////////////////////////////////////////////
	UINT16 CkContiction(CPlayer* poEnemy, CPlayer* poCapture, PKT_CLIGS_PLUNDER_REQ& stPlunderReq);//����Ӷ�����
	VOID SetReqParam(UINT32 dwPlayerID, PKT_CLIGS_PLUNDER_REQ& stPlunderReq);
	PKT_CLIGS_PLUNDER_REQ& GetReqParam(UINT32 dwPlayerID);
	//VOID   CkBeRelease();//����Ƿ񱻷�²���ͷ�
	////////////////////////////////////////////////
	BOOL AddBattleLog(DT_PLUNDER_BATTLELOG_DATA* pstDT_PLUNDER_BATTLELOG_DATA);
	CPlunderBattleLogDeq& GetBattleLogDeq() { return m_deqPlunderBattleLog; }
	VOID GetShowPlunderBattleLog(UINT8& byShowNum, DT_PLUNDER_BATTLELOG_DATA_CLI astPlunderBattleLogInfo[MAX_PLUNDER_BATTLELOG_NUM]);//��ȡ���ͻ�����ʾ��ս��
	VOID OnPlunderComplete(BOOL bSuccess, PKT_CLIGS_PLUNDER_REQ& stReqRaram);//������ɻص�(�۳�Ԫ��/���ߵ�)
	VOID GetPlunderData(UINT16& wCanPlunderNum, UINT16& wFreePlunderNum, UINT32& dwPlunderGold, UINT16& wPlunderItemNum, UINT32& dwCaptureOwnerPlayerID);//��ȡ�Ӷ���Ϣ
	/////////////////////////////////////////////////
	UINT16 OpenCaptureTab(DT_BECAPTURE_DATA& stOwner, UINT16& wPlunderNumPerDay, UINT16& wCanPlunderNum, UINT16& wVipExtNum, UINT16& wFreeCanPlunderNum, UINT8& byCaptureNum, UINT32 &dwPlunderGold, DT_CAPTURE_DATA_CLI astCaptureInfo[MAX_CAPTURE_NUM], 
		UINT16 awUnlockGridLevel[MAX_CAPTURE_NUM], UINT8& byUnreadPlunderBattleLogNum, DT_PLUNDER_BATTLELOG_DATA_CLI& stLastBattleLog,
		DT_PLUNDER_GRID_DATA astCaptureGridInfo[MAX_CAPTURE_NUM]);
	VOID GetBeCaptureInfo(DT_BECAPTURE_DATA& stBeCaptureInfo); //��ȡ������Ϣ
	BOOL AddCapture(UINT32 dwCapturePlayerID, UINT8 byGridIdx);//��ӷ�²
	BOOL DelCapture(UINT32 dwCapturePlayerID);//�ͷŷ�²,�ͷŶ��󼰹���	
	BOOL OnFree();//�Լ��Ƿ�²�������ʱ�ص�
	BOOL OnCapture(UINT32 dwPlayerIDr);//�Լ�����²ʱ�ص�
	VOID GetCapture(UINT8& byCaptureNum, DT_CAPTURE_DATA_CLI astCaptureInfo[MAX_CAPTURE_NUM]);//��ȡ��²��Ϣ���ͻ���
	VOID GetCapture(UINT32 dwCaptureID, DT_CAPTURE_DATA_CLI& stCaptureInfo);
	UINT16 FreeCapture(UINT32 dwCapturePlayerID, UINT32& dwCoinIncome, UINT32& dwScienceIncome);//�����ͷŷ�²
	UINT16 DriveAway(UINT32& dwDriveAwayGold);
	////////////////////////////////////////////////
	UINT16 CollectIncome(UINT32 dwCapturePlayerID, UINT32& dwIncomeValue, DT_CAPTURE_WORK_DATA_CLI& stWorkInfo, UINT8& byCaptureReleaseFlag, UINT8 &byHalved); //dwIncomeValue�������漰����ʵ������
	UINT16 BleedCapture(UINT32 dwCapturePlayerID, UINT8& byIncomeType, UINT32& dwIncomeValue);
	UINT16 SetWorkType(UINT32 dwCapturePlayerID, UINT8 byIncomeType,DT_CAPTURE_WORK_DATA_CLI& stWorkInfo);
	UINT32 GetDriveAwayGold();
	UINT16 RecvLeftIncome(UINT8 byGridIdx, UINT8& byIncomeType, UINT32& dwIncomeValue);
	////////////////////////////////////////////////
	CPlayerID2CaptureMap& GetCaptureMap() { return m_mapCapture; }
	CPlunderCapture* GetCapture(UINT32 dwCapturePlayerID);	
	////////////////////////////////////////////////
	SRecommendPlayerRcd&	GetRecommendPlayerRcd() { return m_stRecommendPlayerRcd; }

	///////////////
	UINT16	GetCanPlunderNum(); //��ȡ���Ӷ����
	UINT16	GetFreePlunderNum(); //��ȡ���Ӷ����
	UINT32   GetPlunderGold();		//�´�Ҫ���ѵ�Ԫ��
	BOOL	HaveIdleGrid();//�ͷ��п��и���
	set<UINT32> GetEnemySet();
protected:
	BOOL InitBattleLog(const DT_PLUNDER_BATTLELOG_DATA_LIST& stPlunderBattleLog);
	BOOL InitCapture(const DT_CAPTURE_DATA_LIST& stCaptureData);
	VOID CkCaptureRelease();
	VOID CkBeRelease();
	/////////////////////////////////////////////////////////////	
	UINT16	CkIdleCaptureGrid(UINT8 byCaptureGridIdx);//����Ƿ��п��з�²����
	UINT16	CkOutPlunderLevelRang(CPlayer* poEnemy, UINT8 byUseItemFlag);//����Ƿ񳬳��Ӷ�ȼ���Χ	
	UINT16	CkYourCapture(CPlayer* poEnemy);	//����Ƿ�������ķ�²
	UINT16	CkPlunderNeedGold();//����շ��Ӷ�Ԫ���Ƿ��㹻	
	UINT16	CkPlunderType(CPlayer* poEnemy, CPlayer* poCapture); //����Ƿ��Ӷ᷽ʽ����
	//////////////////////////////////////////
	VOID	CaptureBefree(UINT32 dwCapturePlayerID);//��²���ͷ�
	/////////////////////////////////////////		

private:
	DT_PLUNDER_BASE_DATA	m_stDT_PLUNDER_BASE_DATA;
	UINT32					m_dwPlayerID;//���ڻ��棬����ÿ�β���	
	CPlunderBattleLogDeq	m_deqPlunderBattleLog;//���ڰ���ս˳��ʱ���¼��ʼ������
	CPlayerID2CaptureMap	m_mapCapture;//keyΪ��²ID
	CGridIdx2CaptureMap		m_mapCridCapture;//keyΪ��²�������
	CPKT_CLIGS_PLUNDER_REQMap	m_mapPlunderReq;//�Ӷ�������������ڱ����Ӷ�����������첽ȡ���ݡ�ͬ�����˲���������򸲸�ֻȡ���һ��
	UINT16					m_wUseItemNum;//ʹ�õĵ��߸�������ʱ����
	UINT32					m_dwPlunderNeedGold;//�շ��Ӷ���Ҫ��Ԫ��
	SRecommendPlayerRcd		m_stRecommendPlayerRcd;//���ڼ�¼�ϴ��Ƽ������ID
	UINT32					m_dwCaptureKeepSecond;//��²ӵ�б���ʱ��(��λСʱ�����˸�ʱ�����Զ��ͷ�). ���ڻ��棬����ÿ��ȡ
	//UINT32					m_dwDriveAwayBaseGold;	// ���Ϸ�²���������Ԫ��. ���ڻ��棬����ÿ��ȡ
	//UINT32					m_dwDriveAwayIncGold;	// ÿ�����Ϸ�²��1���������Ԫ��. ���ڻ��棬����ÿ��ȡ
	UINT16					m_wPlunderLowerLevelItemID;// �Ӷ���Լ�5�����ϵĵ���. ���ڻ��棬����ÿ��ȡ
};
DECLARE_CLASS_POOL_MGR(CPlunder)


#endif
