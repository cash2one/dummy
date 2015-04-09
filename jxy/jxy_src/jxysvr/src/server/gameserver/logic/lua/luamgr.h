#ifndef _CALCULATEMGR_H_
#define _CALCULATEMGR_H_

#include <sdtype.h>
#include <LuaPlus.h>
#include <LuaState.h>
#include <sdsingleton.h>
#include <logic/base/basedefine.h>
#include <src/server/common/client/commondef.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;
using namespace LuaPlus;

//�������
enum EActivityErrCode
{
    ACTIVITY_ERR_PLAYER_NULL 			= 1, 	//��Ҷ���Ϊ��
    ACTIVITY_ERR_INVALID_ID				= 2, 	//��Ч�ID
    ACTIVITY_ERR_ACTIVITY_HAVE_FINISH 	= 3, 	//��Ѿ����
    ACTIVITY_ERR_ACTIVITY_NOT_START 	= 4, 	//���δ��ʼ
    ACTIVITY_ERR_ACTIVITY_OVERDUE 		= 5, 	//��Ѿ�����
    ACTIVITY_ERR_ACTIVITY_CON_NOT_MATCH	= 6, 	//�����δ��
};

struct SActivityInfo
{
    UINT32 dwID;
    UINT64 qwDspDate;
    UINT64 qwStartDate;
    UINT64 qwEndDate;
    UINT16 wEnterLevel; //����ȼ�
    tstring strName;
};
typedef map<UINT32, SActivityInfo> CActivityInfoMap;
typedef CActivityInfoMap::iterator CActivityInfoMapItr;

class CPlayer;
class CLuamgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CLuamgr);

public:
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_LUA ;
    }
    BOOL Init();
    VOID UnInit();
public:
    ///////////////////////////��ʽ����ģ��///////////////////////////
    //ǿ��ͭ��
    UINT32 GetStrengthenCoin(UINT16 wStrenthenLevel, UINT16 wDressLevel);
    //��ħ���踽ħʯID
    UINT16 GetEnchantStoneID(UINT16 wEnchantLevel);
    //��ħ���踽ħʯ
    UINT32 GetEnchantStoneCost(UINT16 wEnchantLevel, UINT16 wDressLevel);
    //��²��������ͭ��
    UINT32 GetCaptureWorkCoin(UINT16 wCaptureLevel);
    //��²������������
    UINT32 GetCaptureWorkScience(UINT16 wCaptureLevel);
    //������������ͭ��
    UINT32 GetRankEncourageCoin(UINT32 dwRank);
    //����������������
    UINT32 GetRankEncourageScience(UINT32 dwRank);
    //�����������������
    UINT32 GetRankEncourageJingJie(UINT32 dwRank);
    //��ս��������ͭ��
    UINT32 GetChallengeEncourageCoin(UINT16 wPlayerLevel, BOOL bWinFlag);
    //��ս������������
    UINT32 GetChallengeEncourageScience(UINT16 wPlayerLevel, BOOL bWinFlag);
    //��ս������������
    UINT32 GetChallengeEncourageJingJie(UINT16 wPlayerLevel, BOOL bWinFlag);
    //ҡǮ����������ͭ��
    UINT32 GetMoneyTreeProduceCoin(UINT16 wPlayerLevel);
    //���������������ӵ�����ֵ
    DOUBLE GetAttrAddValue(UINT16 wTalent, UINT16 wHeroLevel, UINT8 byAttrType, UINT8 byCareerType);
    //����������������ͭ��
    UINT32 GetUpdateAttrCostCoin(UINT16 wTalent, UINT16 wAttrLevel, BOOL bCoachFlag);
    //����ٻ�����
    //UINT16 GetAwakenCallNum();
    //��������ת����������(����������1����)
    UINT16 GetBlueNumToPerPurple();
    //ÿ�ε�����ֵ
    UINT32 GetClickBlueValue();
    //��������ջ�ͭǮ
    UINT32 GetMaintownCrownCoin(UINT16 wPlayerLevel);
    //��������ջ�Ԫ��
    UINT32 GetMaintownCrownGold(UINT16 wPlayerLevel);
    //��������ջ񾳽��
    UINT32 GetMaintownCrownJingJie(UINT16 wPlayerLevel);
    //�����������ͭǮ
    UINT32 GetMaintownLevyCoin(UINT16 wPlayerLevel);
    //����������վ����
    UINT32 GetMaintownLevyJingJie(UINT16 wPlayerLevel);
    //���Ҹ�����Ƿ�����ʾ
    BOOL   CkBoxGoodsPrompt(UINT16 wBoxGoodsID);
    ///////////////////////////�ģ��///////////////////////////
    //����Ƿ���ڸû
    BOOL	  CkHaveActivity(UINT32 dwId);
    //����Ƿ����ɸû
    UINT16 CkFinishActivity(CPlayer* poPlayer, UINT32 dwId);
    //��ù��ܵ����ĵ�Ԫ��
    UINT32 GetFuncCost(CPlayer* poPlayer, ECostFunc func, INT32 nCount, INT32 nIdx = 0);

    //��ù��ܵ�������
    UINT32 GetFuncObtain(CPlayer* poPlayer, EObtainFunc func, INT32 nCount, INT32 nIdx = 0);

	//��þ����Ĵ���
	UINT32 GetGenGasNum(UINT8 byVipLevel, UINT8 byLevel, UINT8 byTownIdx, UINT8 byInstanceIdx);

	//��û�걶��
	UINT32 GetGatherScienceIncrease(INT32 nIdx);

	//��û�걶�ʰٷֱ�
	UINT32 GetGatherScienceIncreasePer(INT32 nIdx, INT32 nFunc);

    //��øչ�����ӻ�ȡ��������ʱ�䣨��ǰ�ѹ�������,0��ʾû��
    UINT32 GetPassIncGenGasNumTime();
    ///////////////////////////bossս/////////////////////////////
    UINT32 GetBossBTopEncCoin(UINT16 wPlayerLevel, UINT16 wTop); //��ȡbossս��������
    UINT32 GetBossBTopEncJingJie(UINT16 wPlayerLevel, UINT16 wTop);//��ȡbossս��������
    UINT32 GetBossBKillEncCoin(UINT16 wBossLevel);//��ȡbossս��ɱ����
    UINT32 GetBossBKillEncJingJie(UINT16 wBossLevel);//��ȡbossս��ɱ����
    UINT32 GetBossBHurtEncCoin(UINT16 wPlayerLevel, UINT32 dwHurtValue);//��ȡbossս�˺�����
    UINT32 GetBossBHurtEncJingJie(UINT16 wPlayerLevel, UINT32 dwHurtValue);//��ȡbossս�˺�����
    UINT32 GetBossBHeroHurtEncCoin();//��ȡbossսӢ�۽���
    UINT32 GetBossBHeroHurtEncJingJie();//��ȡbossսӢ�۽���
    UINT8  GetInspireRate(UINT8 byGoldInspireFlag, UINT16 wIncPowerRate);//��ȡbossս�������
    UINT16 GetIncRateByStory();
    UINT16 GetIncRateByGold();
    ////////////////////////////�����ս//////////////////////////////
    UINT32 GetRdchallengeEncJingJie(UINT8 byRet, UINT16 wMyLevel, UINT16 wEnemyLevel);
    UINT32 GetRdchallengeEncPurpleGas(UINT8 byRet, UINT16 wMyLevel, UINT16 wEnemyLevel);
    ////////////////
    UINT32 GetMeltGold(UINT32 dwScience);

    UINT32 GetBegBlueMaxTimes(UINT32 dwClimbTowerLayer); // ���ݵ�ǰ������������ȡ��ǰ����¶��������
    UINT32 GetFreeImproveLuckTimes(); // ��ȡ����¶ÿ����Ѹ��˴���
    UINT32 GetClimbTowerPrompt(UINT32 dwClimbTowerLayer);  // ��ȡ��һ��������ʾ��
    UINT8  GetBegBlueIsIgnoreXnMultiple(); // ��ȡ����¶�Ƿ���Ա���

	UINT16 GetTotalFreeCommonUpGasNum();
    
    UINT32 GetBossBHurtValueByPower(UINT32 dwPower);//����ս����ȡbossս�˺�

	//��Ʒ���
	UINT32 GetFindMonsterGold();
	//��ȡ��Ѹ������ִ���
	UINT32 GetFreeRefreshNum();
	//��ȡ�Ʊ��ʽ�������Coin
	UINT32 GetCoinByBadWine();
	//�Ź�������ֱ���ֵ
	UINT32 GetDoorsTributeIntegral();
	//��ȡ����һ������ͭǮ
	UINT32 GetCostCoinByDonate(UINT32 FactionLevel);
	//��ȡ����һ������Ԫ��
	UINT32 GetCostGoldByDonate(UINT32 FactionLevel);
	//����һ��ͭǮ�����ʽ���
	UINT32 GetFundsByDonateCoin(UINT32 FactionLevel);
	//����һ��Ԫ�������ʽ���
	UINT32 GetFundsByDonateGold(UINT32 FactionLevel);
	//����һ��ͭǮ�����Ź�
	UINT32 GetDoorsTributeByDonateCoin(UINT32 FactionLevel);
	//����һ��Ԫ�������Ź�
	UINT32 GetDoorsTributeByDonateGold(UINT32 FactionLevel);
    //��������ȼ���ȡ������ӵ���͵ȼ�
    UINT32 GetCourageGroupLevel(UINT32 dwLevel);
    //��ȡÿ�������������
    UINT32 GetTotalFreeCourageTimes();
    //ÿ��Э������ ����������������
    UINT32 GetTotalHelpCourageTimes();
    //Э����ÿ�����ӵ���������
    UINT32 GetAddCourageTimes();
    //��ǰVIP�ɹ������������
    UINT32 GetVipBuyCourageTimes(UINT8 byVip);
	//�ƽ�ģʽ�ı�����ϵ
	UINT32 GetGoldModeMulti();
	//��������ʱ����
	UINT32 GetJoinFactionInterval();
	//��ͨ�һ��Ź�����ͭǮ
	UINT32 GetNormalFindBackDoorsTribute(UINT32 dwLeftDoorsTribute);
	//��ȫ�һ��Ź�����Ԫ��
	UINT32 GetPerfectFindBackDoorsTribute(UINT32 dwLeftDoorsTribute);
	//��Ȫ�п��ύ��������
	UINT32 GetMaxExprience(UINT32 dwVipLevel, UINT32 dwFactionLevel);
	//��Ȫ�о������ӻ���
	UINT32 GetExprienceBase(UINT32 dwPlayerLevel, UINT32 dwFactionLevel);
	//������Ʒ�ȼ�
	UINT32 GenerateJewelryLevel(UINT16 wFirstLevel, UINT16 wSecondLevel, UINT16 wThirdLevel, UINT16 wFourthLevel);
	//������ƷƷ��
	UINT8 GenerateJewelryColor(UINT8 byColor1, UINT8 byColor2, UINT8 byColor3, UINT8 byColor4);
	//����Ʒ������
	UINT32 GenerateJewelryCost(UINT16 wDressLevel, UINT8 byColor);

	UINT8 GetProcuctSoulCostType(UINT8 ucProductyType, UINT8 ucSearchType, UINT32 unNum);
	UINT32 GetProcuctSoulCostNum(UINT8 ucProductyType, UINT8 ucSearchType, UINT32 unNum);

	UINT32 GetSoulRefleshCost(UINT8 ucLockNum);
	UINT32 GetSoulDevourCost(UINT8 ucDevourCost);
	//������������
	UINT32 GetSkillNumByPlayerLevel(UINT8 bySkillType, UINT16 wPlayerLevel);
// 	UINT32 RefinePetGetPetType(UINT8 ucPetType1, UINT8 ucPetType2);
// 	UINT32 RefinePetGetPetQuality(UINT8 ucPetQuality1, UINT8 ucPetQuality2);
	UINT32 GetPetFeedVIPCostGold(UINT8 ucVipLevel, UINT8 ucVipPetFeedCnt);

protected:
    BOOL InitLua();
    BOOL LoadLuaScript();

    BOOL InitLuaActivity();

    //��ù������ģ�����VIP�����Ӵ�����Ҫ������
    UINT32 GetCostByFunc(UINT8 byVipLevel, ECostFunc func, INT32 nCount, INT32 nIdx);

    //�����Դ�� ����VIP�����Ӵ��������Դ
    UINT32 GetObtainByFunc(UINT8 byVipLevel, UINT8 byLevel, EObtainFunc func, INT32 nCount, INT32 nIdx);

public:
    CLuamgr();
    ~CLuamgr();
private:
    LuaStateOwner		m_oLuaState;
    CActivityInfoMap	m_mapActivityInfo;
};



#endif

