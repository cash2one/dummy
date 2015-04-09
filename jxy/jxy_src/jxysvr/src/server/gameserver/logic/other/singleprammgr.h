
#ifndef _SINGLEPRAMMGR_H_
#define _SINGLEPRAMMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>
#include <protocommondata.h>
#include "logic/pet/petdef.h"

class CSinglePramMgr : public CBasePopMgr
{
public:

    DECLARE_SINGLETON_PROPMGR(CSinglePramMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_SINGLE_PRAM ; }

    BOOL Init();

    VOID UnInit();
public:
    UINT16 GetMaxPlayerLevel() { return m_wMaxPlayerLevel; }
	UINT8 GetRechargeFlag(){ return m_byRechargeFlag; }
    UINT8 GetOnlineEncourageKeepDays() { return m_byOnlineEncourageKeepDays; }
    UINT8 GetLoginEncourageKeepDays() { return m_byLoginEncourageKeepDays; }
	UINT16 GetRefreshEliteNumPerDay() { return m_wRefreshEliteNumPerDay;}
	UINT16 GetGainCropCDGoldPerMin() { return m_wGainCropCDGoldPerMin;}
	UINT8  GetMaxHPGridNum() { return m_byMaxHPGridNum; }
	UINT16 GetRecruitReturnCoinPercentage(){ return m_wRecruitReturnCoinPercentage;}	//���ص�ͭǮ����
	UINT16 GetRecruitFavorability(){ return m_wRecruitFavorability;}		//���������ĺøж�
	UINT16 GetJuniorLevel() { return m_wJuniorLevel; }
	//UINT16 GetResetClimbTower() {return m_wResetClimbTower;}
	UINT8 GetTotalYabiaoCnt(){ return m_byTotalYabiaoCnt; }
	UINT8 GetTotalJiebiaoCnt(){ return m_byTotalJiebiaoCnt; }
	INT32 GetMaxLevelCostGold(){ return m_nMaxLevelCostGold; }
	UINT8 GetTotalBeJiebiaoCnt(){ return m_byTotalBeJiebiaoCnt; }
	UINT8 GetJiebiaoViewPlayerCnt(){ return m_byJiebiaoViewPlayerCnt; }
	UINT16 GetJiebiaoCD(){ return m_wJiebiaoCD; }
	UINT16 GetClearJiebiaoCDCostGoldPerMin(){ return m_wClearJiebiaoCDCostGoldPerMin; }
	UINT16 GetUpdateRecordDataToSqlInterval(){ return m_wUpdateRecordDataToSqlInterval; }
    UINT16 GetSaveOpHistoryToDBInterval(){ return m_wSaveOpHistoryToDBInterval; }
	UINT16 GetPerfectFreeGodweaponGold(){ return m_wPerfectFreeGodponGold;}
	UINT32 GetGoldExperienceAddValue(){ return m_dwGoldExperienceAddValue; }
	UINT16 GetGoldExperienceCostGold(){ return m_wGoldExperienceCostGold; }
	UINT16 GetFreeFlushBiaoCnt(){ return m_wFreeFlushBiaoCnt; }
	CHAR * GetAppAddress(){return m_szAppAddress;}

	UINT16 GetHeroTransFreePercentage(){ return m_wHeroTransFreePercentage; }
	UINT16 GetHeroTransGoldPercentage(){ return m_wHeroTransGoldPercentage; }
	UINT16 GetTransGold(){ return m_wTransGold; }
	UINT16 GetCoachExpRate() { return m_wCoachExpRate; }

	UINT16 GetRdChallengeRefreshCD() { return m_wRdChallengeRefreshCD; }
	CHAR * GetScienceDspContent() { return m_szScienceDspContent; }

	UINT16 GetOpenOprateingActivityLevel() { return m_wOpenOprateingActivityLevel; }

    BOOL   GetReCalcHowManyTopRacer(){ return m_wReCalcHowManyTopRacer; }
    BOOL   GetIsSaveNewRacerPowerToDB(){ return m_bIsSaveNewRacerPowerToDB; }
	UINT32 GetSavePlayerInterval() { return m_dwSavePlayerInterval;}
	UINT16 GetApplyFactionMaxNum() { return m_wApplyFactionMaxNum; }
	UINT8  GetEveryDayAuditMaxNum() { return m_byEveryDayAuditMaxNum; }
	UINT8  GetSureOutOrangeAwaken() {return m_bySureOutOrangeAwaken; }
	UINT16 GetEveryDayRecvFlowers() {return m_wEveryDayRecvFlowers; }
	UINT32 GetExpiresRecvFlower() {return m_dwExpiresRecvFlower; }
	
	UINT8 GetFreeChangeIconNum() { return m_byFreeChangeIconNum; }
	UINT8 GetNormalFindBackDoorsTribute() { return m_byNormalFindBackDoorsTribute; }
	UINT8 GetPerfectFindBackDoorsTribute() { return m_byPerfectFindBackDoorsTribute; }
	UINT32 GetExprienceAddInterval(){ return m_dwHotSpringExprienceInterval; }
	UINT32 GetChangeFactionIcon() { return m_dwChangeFactionIcon; }
	UINT32 GetCloseAreaBoosMulti() { return m_dwCloseAreaBoosMulti; }
	UINT32 GetMaxScienceLevel() { return m_dwMaxScienceLevel;}
	UINT8 GetJewelryStrengIntervalLevel() { return m_byJewelryStrengIntervalLevel; }
	UINT32 GetJewelryResolveReturn(){ return m_dwJewelryResolveReturn;	}
	UINT32 GetJewelryBlueNum() { return m_dwJewelryBlueNum; }
	UINT32 GetJewelryPurpleNum(){ return m_dwJewelryPurpleNum; }
	UINT32 GetJewelryRedNum(){ return m_dwJewelryRedNum; }
	UINT32 GetJewelryOrangeNum(){ return m_dwJewelryOrangeNum; }
	UINT8 GetMaxJewelryStrengNum() { return m_byMaxJewelryStrengNum; }
	
    UINT32 GetCourageHelpTimes() {return m_dwCourageHelpTimes;}	
	UINT8 GetMinDisPlayerOutBoundNum(){ return m_byMinDisPlayerOutBoundNum;}
	UINT8 GetInterceptFlag(){ return m_byInterceptFlag; }
	UINT8 GetHotSpringFlag(){ return m_byHotSpringFlag; }
	UINT8 GetAdvertisementFlag(){ return m_byAdvertisementFlag; }
	UINT16 GetNeiDanInstanceNum(){ return m_wMaxNeiDanInstanceNum; }
public:
    CSinglePramMgr();
    virtual ~CSinglePramMgr();
protected:

    BOOL LoadFromDB();
private:
    UINT16	m_wMaxPlayerLevel;//������ȼ�
	UINT8 m_byRechargeFlag;//��ֵ��ť��ʶ
	UINT8 m_byInterceptFlag;//���ر�ʶ
	UINT8 m_byHotSpringFlag;//��Ȫ��ʶ
	UINT8 m_byAdvertisementFlag;//����ʶ
    UINT8	m_byOnlineEncourageKeepDays;//���߽�����������
    UINT8	m_byLoginEncourageKeepDays;//��¼������������
	UINT16  m_wRefreshEliteNumPerDay;//ÿ��(ʹ��Ԫ��)ˢ�¾�Ӣ��������

	UINT16  m_wGainCropCDGoldPerMin;//��ֲǿ��

	UINT8		m_byMaxHPGridNum; //���Ѫ��������
	UINT16		m_wRecruitReturnCoinPercentage;		//���ص�ͭǮ����
	UINT16		m_wRecruitFavorability;		//���������ĺøж�

	UINT16		m_wJuniorLevel;//���ֵȼ�

	//UINT16		m_wResetClimbTower; //���������������

	UINT8	m_byTotalYabiaoCnt; //ÿ�յ����Ѻ�ڴ���
	UINT8	m_byTotalJiebiaoCnt; //ÿ�յ���߽��ڴ���
	INT32	m_nMaxLevelCostGold; //ֱ�Ӵﵽ��õ�Ѻ��Ʒ�������ĵ�Ԫ��
	UINT8	m_byTotalBeJiebiaoCnt; //ÿ��Ѻ����౻���ڵĴ���
	UINT8	m_byJiebiaoViewPlayerCnt; //���ڿɼ�����Ҹ�������
	UINT16	m_wJiebiaoCD; //���ڵ�CD
	UINT16	m_wClearJiebiaoCDCostGoldPerMin; //��ս���CDÿ���ӻ��ѵ�Ԫ��

	UINT16	m_wUpdateRecordDataToSqlInterval; //���²ɼ����ݵ����ݿ��ʱ����
    UINT16	m_wSaveOpHistoryToDBInterval;     // ��Դ����ͳ�Ʊ�Ĳɼ����ݵ����ݿ�ļ��, ophistory������Դ������ʷ

	UINT16	m_wPerfectFreeGodponGold;		//�����ͷ���������Ԫ��
	UINT32	m_dwGoldExperienceAddValue;		//Ԫ�����鵤���ӵľ���
	UINT16	m_wGoldExperienceCostGold;		//Ԫ�����þ��鵤����Ԫ��
	UINT16	m_wFreeFlushBiaoCnt;			//���ˢ���ڵĴ���


	UINT16	m_wHeroTransFreePercentage;	//��Ѵ��аٷֱ�
	UINT16	m_wHeroTransGoldPercentage;	//Ԫ�����аٷֱ�
	UINT16	m_wTransGold;					//���л���Ԫ��
	CHAR		m_szAppAddress[512]; //app���ֵ�ַ
	UINT16	m_wCoachExpRate;	//���Ǿ��鱶��(�ٷֱ�)

	UINT16	m_wRdChallengeRefreshCD;//�����ս��ظ�CD

	TCHAR	m_szScienceDspContent[MAX_CONTENT_SIZE];//�򿪳���Ҫ��ʾ����������

	UINT16	m_wOpenOprateingActivityLevel;//��Ӫ�����������ҵȼ�

    UINT16	m_wReCalcHowManyTopRacer;      // ����ʱ���¼��㾺����ǰ���ٸ���һ����ǰ100������ҵ�ս�����ȶԣ������0���ʾ�����¼���
    BOOL		m_bIsSaveNewRacerPowerToDB;    // �Ƿ������ս����д�����ݿ⣺��1/��0
	UINT32	m_dwSavePlayerInterval;			//��ұ���ʱ��
	UINT16	m_wApplyFactionMaxNum;			//ͬʱ��������������
	UINT8	m_byEveryDayAuditMaxNum;			//ÿ�����ͨ������
	UINT8	m_bySureOutOrangeAwaken;			//���κ�س���ɫ����
	UINT16	m_wEveryDayRecvFlowers;

	UINT32	m_dwExpiresRecvFlower;//�ջ�����ʱ�䣨�룩
	UINT8 m_byFreeChangeIconNum;			//��Ѹ�������ͷ�����
	UINT8 m_byNormalFindBackDoorsTribute;	//�ۻ��Ź�
	UINT8 m_byPerfectFindBackDoorsTribute;	//ʣ���Ź�
	UINT32 m_dwHotSpringExprienceInterval;//��Ȫ�������Ӽ��
	UINT32 m_dwChangeFactionIcon;//��������ͷ������Ԫ��
	UINT32 m_dwCloseAreaBoosMulti;//������BOSS��Ѫ������
	UINT32 m_dwMaxScienceLevel;//���Ƽ��ȼ�
	UINT8 m_byJewelryStrengIntervalLevel; //��Ʒ���ǿ���ȼ�
	UINT8 m_byMaxJewelryStrengNum;//��Ʒ���ǿ������
	UINT32 m_dwJewelryResolveReturn; //��Ʒ�ֽⷵ������
	UINT32 m_dwJewelryBlueNum;
	UINT32 m_dwJewelryPurpleNum;
	UINT32 m_dwJewelryRedNum;
	UINT32 m_dwJewelryOrangeNum;
	
    UINT32 m_dwCourageHelpTimes;   //GVEЭ������
	UINT8 m_byMinDisPlayerOutBoundNum; //������ʾ���⴫����
	UINT16 m_wMaxNeiDanInstanceNum;//ÿ�����սն���������
};

#endif
