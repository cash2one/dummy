#ifndef __GT_PACKETPROCESSOR_INCLUDE_H_
#define __GT_PACKETPROCESSOR_INCLUDE_H_

#include "sdframework.h"
#include <protocol/server/protogtgs.h>
#include <net/cli/usermgr.h>

using namespace SGDP;


class CGTProcessor : public CSDPacketProcessor
{
public:
    CGTProcessor();
    ~CGTProcessor();
public:
    virtual BOOL  Init() ;
    virtual CSDProtocol* GetProtocol() ;
private:
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////// δ����CUserʱ��Э��,ʹ��CGTPipeChannel���� ///////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    static BOOL        OnEnterGSReq(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////// ���û�������Э��,ʹ��CGTPipeChannel���� ///////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	static BOOL        OnKickOutAck(VOID* pPipeChannel, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////// δ����CRole����Ϸ���ݲ�����ʱ��Э��,ʹ��CUser���� ////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    //�û��Ͽ�����
    static BOOL        OnUserDisconnect(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ�佫��Ϣ����
    static BOOL        OnGetHeroInfoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�����԰����
    static BOOL        OnEnterHomeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //���븱������
    static BOOL        OnEnterInstanceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ս������
    static BOOL        OnBattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ս������
    static BOOL        OnPickReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�뿪��������
    static BOOL        OnExitInstanceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ������������
    static BOOL        OnGetSceneInstanceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�ջ�����
    static BOOL        OnCrownReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnUpgradeBuildReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnOpenSmithyReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�����̹���װ������
    static BOOL        OnSmithyBuyEquipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ǿ������
    static BOOL        OnStrengthenReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ħ����
    static BOOL        OnEquipEnchantReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	// ��ȡ������Ϣ����
	static BOOL		   OnGetOpenLightInfoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	// ��������
	static BOOL		   OnOpenLightReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //����ļ������
    static BOOL        OnOpenRecruitReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ļ�佫����
    static BOOL        OnRecruitHeroReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ǲɢ�佫����
    static BOOL        OnDisbandHeroReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��������������
    static BOOL        OnOpenProduceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪱�������
    static BOOL        OnOpenBagReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�Ƽ�������������
    static BOOL        OnScienceAttrUpgrade(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�Ƽ��ݽ�����������
    static BOOL        OnScienceBuildUpgrade(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����������
    static BOOL        OnRecvTaskEncourage(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪾���������
    static BOOL        OnOpenRaceBuildReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ս����
    static BOOL        OnChallengeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ��������
    static BOOL        OnRecvRankEncourageReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //���̵�����
    static BOOL        OnOpenShopReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�����������
    static BOOL        OnBuyItemReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�����������
    static BOOL        OnSellItemReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����װ������
    static BOOL        OnEquipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //һ������װ������
    static BOOL        OnQuickEquipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ע���û�������
    static BOOL        OnRegisterUserNameReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��������
    static BOOL        OnEmbattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��������������
    static BOOL        OnClrPlayerDataReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪲�������
    static BOOL        OnOpenEmbattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪵�������������
    static BOOL        OnOpenItemMakerReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnMakeItemReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ�佫��ҩ��Ϣ����
    static BOOL        OnGetHeroDrugReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ʹ�õ�ҩ����
    static BOOL        OnUseDrugReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪸���������������
    static BOOL        OnOpenEncourageInstanceBoxReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnIncreaseBagSize(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�һ�����
    static BOOL        OnHookReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�һ��ж�����
    static BOOL        OnInterruptOnhook(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�һ�������������
    static BOOL        OnNoCDOnhook(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ�һ��������
    static BOOL        OnOnhookResult(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�����սCD����
    static BOOL        OnClrChallengeCD(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ���߽�������
    static BOOL        OnRecvOnlineEncourage(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ͬ��ʱ������
    static BOOL        OnSyncTime(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ע���ǳ�����
    static BOOL        OnRegisterDspName(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��Ʒʹ��
    static BOOL        OnUseGoodsReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪵�¼�������
    static BOOL        OnOpenLoginEncourageReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��¼����ҡ������
    static BOOL        OnRateLoginEncourageReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��¼�������뱳������
    static BOOL        OnPutLoginEncourageIntoBagReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ��������������
    static BOOL        OnGetRankReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnAcceptTaskReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnGiveUpTaskReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ������ս������
    static BOOL        OnGetRaceBattleLogReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪷�²�������
    static BOOL        OnOpenCaptureTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�Ӷ�����
    static BOOL        OnPlunderReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�򿪳���������
    static BOOL        OnOpenEnemyTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //���Ӷ��Ƽ����
    static BOOL        OnOpenPlunderRecommendPlayerReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�ͷŷ�²
    static BOOL        OnFreeCaptureReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��ȡ�Ӷ�ս��
    static BOOL        OnGetPlunderBattleLogReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ˢ���Ӷ����
    static BOOL        OnRefreshPlunderRecommendReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ɾ�����
    static BOOL        OnDelEnemyReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��ȡ��²����
    static BOOL        OnCollectIncomeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ե�ɷ�²
    static BOOL        OnBleedCaptureReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //���ù�������
    static BOOL        OnSetWorkTypeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //���Ϸ�²��
    static BOOL        OnDriveAwayReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��ȡ��²��������
    static BOOL        OnRecvLeftIncomeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //��ҡǮ��
    static BOOL        OnOpenMoneyTreeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ҡǮ
    static BOOL        OnRockMoneyTreeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������
    static BOOL        OnOpenGodweaponReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��������
    static BOOL        OnUpgradeGodweaponReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�ͷ�����
    static BOOL        OnFreeGodweaponReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);



    //���������
    static BOOL        OnOpenAwakenTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�������
    static BOOL        OnAwakenReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�򿪴����ĵ��������
    static BOOL        OnOpenDressStudyTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�ĵô�������
    static BOOL        OnDressStudyReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ת���ĵþ�������
    static BOOL        OnStudyToExpReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�Զ�ת����ɫ��Ƭ���ĵþ���ѡ������
    static BOOL        OnStudyUpgradeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//////////////////////////////////////
	//���������
	static BOOL        OnOpenAwakenTabReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�������
	static BOOL        OnAwakenReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�򿪴����ĵ��������
	static BOOL        OnOpenDressStudyTabReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�ĵô�������
	static BOOL        OnDressStudyReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//ת���ĵþ�������
	static BOOL        OnStudyToExpReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�Զ�ת����ɫ��Ƭ���ĵþ���ѡ������
	static BOOL        OnStudyUpgradeReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪷ֽ�����
    static BOOL        OnOpenResolveTrigramReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�ֽ�����
    static BOOL        OnResolveTrigramReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //�ݷ��佫����
    static BOOL        OnVisitHeroReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������������
    static BOOL        OnBuyPhystrengthReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����������
    static BOOL        OnOpenMaintownReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��ȡ��������
    static BOOL        OnRecvIncomeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //������������
    static BOOL        OnLevyIncomeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);



    //�򿪵�ҩ�������
    static BOOL        OnOpenDrugUseTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //���佫��ҩ�����������
    static BOOL        OnOpenHeroDrugUseTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�����ҩ����CD����
    static BOOL        OnClrUseDrugCDReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ʹ�õ�ҩ����
    static BOOL        OnUseDrugReqEx(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�򿪵�ҩ�����������
    static BOOL        OnOpenUpgradeDrugReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��ҩ��������
    static BOOL        OnUpgradeDrugReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //װ���ϳ�
    static BOOL        OnComposeEquipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪹����������
    static BOOL        OnOpenPhyStrengthReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //���ǿ��CD
    static BOOL        OnClrStrengthenCDReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //////////////////////////////////////////////////////////////////////////
    //�ɰ汾��ֲ
    static BOOL        OnOpenCropReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL        OnOpenCropFieldReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL        OnCropReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL        OnGainCropReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL        OnClrCropReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //���þ��鵤
    static BOOL        OnOpenExperienceDrugReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL        OnUserExperienceDrugReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL		  OnOpenScienceBuildReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL		  OnUpdateScienceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL		  OnOpenUpdateAttrPannelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL		  OnUpdateAttrReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //װ��������
    static BOOL		  OnOpenMeltEquipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL		  OnMeltReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��Ʒ�ϳ�
    static BOOL		  OnComposeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��ȡ��Ʒ��Ϣ
    static BOOL		  OnGetItemReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL		  OnGetOrderIDReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //���Ӻϳ�
    static BOOL		  OnComposeSeedReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����
    static BOOL		  OnChatReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����
    static BOOL		  OnOpenChatReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //�򿪻��������
    static BOOL		  OnOpenActivityCenterReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�򿪳԰�����������
    static BOOL		  OnOpneEatBreadReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�õ���������
    static BOOL		  OnObtainPhystrengthenReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�뿪�԰�����������
    static BOOL		  OnOLeaveEatBreadReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //��������
    static BOOL		  OnClimbTowerResetReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�����һ�
    static BOOL		  OnClimbTowerOnHookReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //����
    static BOOL		  OnOpenPaoshangBuildReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��Ѻ�ڽ���
    static BOOL		  OnOpenYabiaoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //ˢ��Ʒ��
    static BOOL		  OnFlushBiaoQualityReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);


    //��ʼѺ��
    static BOOL		  OnBeginYabiaoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�򿪽��ڽ���
    static BOOL		  OnOpenJiebiaoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��ʼ����
    static BOOL		  OnBeginJiebiaoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����ս����Ϣ
    static BOOL		  OnQueryBattleRecordReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����Ѻ��ս����Ϣ
    static BOOL		  OnQueryYabiaoBattleLogReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����Ѻ�ڽ�����Ϣ
    static BOOL		  OnQueryYabiaoEncourageReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //������ս���CD
    static BOOL		  OnClearJiebiaoCDReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //////////////////////////////////////
    //��������
    static BOOL		  OnUpgradeJingjieReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//���������
	static BOOL		  OnOpenGenGasTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //����������
    static BOOL		  OnGenGasBallReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //����������ȼ�
    static BOOL		  OnUpGasBallLevelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�ռ������ȼ�
    static BOOL		  OnCollectGasReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //����������ʽ�ȼ�
    static BOOL		  OnUpgradeSkillActionLevelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //ѡ������ʽЧ��
    static BOOL		  OnSelectSkillActionEffectReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�򿪾������
    static BOOL		  OnOpenJingjieTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�򿪼������
    static BOOL		  OnOpenSkillTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //��VIP���
    static BOOL		  OnOpenVipTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //���������
    static BOOL		  OnOpenClimbTowerReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�����ô�������
    //static BOOL		  OnBuyClimbTowerResetReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //����Ƕ���
    static BOOL		  OnOpenXiangqianTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //�϶�װ����Ƕ��ʯ
    static BOOL		  OnDragEquipToXiangqianReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //��Ƕ��ʯ
    static BOOL		  OnXiangqianReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    //APP�汾�ĳ�ֵ�����֤����
    static BOOL		  OnAppExchangeCheckReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //�Ƴ���Ƕ
    static BOOL		  OnRemoveXiangqianReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //��ȡ��Ӣ��������
    static BOOL		  OnGetEliteInstanceReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //���þ�Ӣ��������
    static BOOL		  OnResetEliteInstanceReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //��Ӣ�����һ�����
    static BOOL		  OnEliteInstanceOnHookReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //��û��ʾ����
    static BOOL		  OnGetActivityPromptReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //����ת��������
    static BOOL		  OnBlueToPurpleReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //�д�����
    static BOOL		  OnPKBattleReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //��Դ��������
    static BOOL		  OnResourcesPromptReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    //bossս
    static BOOL		  OnEnterBossbReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnLeaveBossbReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnBossbMoveReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnBossbHurtReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnOpenInspireTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnInspirePowerReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnBossBReliveReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnGetLastBossBInfoReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnOpenBossBBLReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenRechargeEncourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnRecvRechargeEncourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnOpenScoreEncourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnRecvScoreEncourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnGetRandomDspNameReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenExperienceTransferReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnExperienceTransferReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenRdchallengeTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnRdchallengeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnClrRDChallengeCDReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenWorshipTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnWorshipReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnActivityNotifyReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenDogFecesReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnGetActivityCenterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnGetActivityEncourageInfoReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnRecvActivityEncourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	static BOOL		  OnGetActivityEncourageInfoReq2( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	static BOOL		  OnRecvActivityEncourageReq2( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenGemMakerTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	static BOOL		  OnOpenGemMakerTabExReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnOpenAwakenExchangeTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnExchangeStudyReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnRecvRatingEncourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    static BOOL		  OnOpenEquipComposeTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnEquipComposeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    static BOOL		  OnRecvComposeEquipReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // �򿪰������
    static BOOL		  OnOpenFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ����������
    static BOOL		  OnApplyFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �����������
    static BOOL		  OnCancelApplyFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ��������
    static BOOL		  OnCreateFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ���Ұ���
    static BOOL		  OnSearchFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �������Լ�����
    static BOOL		  OnOpenOwnerFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �򿪰����Ź�
    static BOOL		  OnOpenDoorsTributeFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �Ź�����
    static BOOL		  OnDoorsTributeFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ��ȡ�Ź����ɽ���
    static BOOL		  OnRecvDoorsTributeFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �����߳�
    static BOOL		  OnKickedFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ���ð���ְλ
    static BOOL		  OnJobFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ���ð��ɻ�����Ϣ
    static BOOL		  OnSetNoticeFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ���ɽ�ɢ
    static BOOL		  OnDissolveFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �������
    static BOOL		  OnAuditFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	static BOOL		  OnAuditFactionReq2( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �򿪰��������б�
    static BOOL		  OnOpenApplyFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �򿪰��������б�
    static BOOL		  OnOpenRankFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �򿪰�������б�
    static BOOL		  OnOpenAuditFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	static BOOL		  OnOpenAuditFactionReq2( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �򿪰�����־�б�
    static BOOL		  OnOpenLogFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // �򿪾ۻ����
    static BOOL		  OnOpenGetherScienceReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �ۻ�
    static BOOL		  OnGetherScienceReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	// ����¶��
	static BOOL		  OnOpenBluePavilionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	// ����¶
	static BOOL		  OnBegBlueReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	// ����¶����
	static BOOL		  OnImproveLuckReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	// ����¶ȷ��������
	static BOOL       OnComfirmBegBlueReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ��ȡ����¶����
    static BOOL       OnGetBlueEncourage( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//ת��ְҵ����
	static BOOL       OnChangeCareerReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//�Լ���ְҵ��ս����
	static BOOL       OnChallengeMyselfReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�򿪵��߶һ��������
	static BOOL       OnOpenItemExchangeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//���߶һ�����
	static BOOL       OnItemExchangeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//��Ӫ�ս������
	static BOOL       OnOperatingActivityBattleReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    

    // ��ȡ����ϵͳ����б�
    static BOOL       OnGetFriendSysPlayerListReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	// ��ȡ����ϵͳ����б�
	static BOOL       OnGetFriendSysPlayerListReq2( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ɾ������
    static BOOL       OnDelFriendReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // �������
    static BOOL       OnSearchPlayerReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	// �������
	static BOOL       OnSearchPlayerReq2( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // �鿴�����Ϣ
    static BOOL       OnViewPlayerReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ��Ӻ���
    static BOOL       OnAddFriendReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ���ͻ����
    static BOOL       OnOpenSendFlowerTabReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // �ͻ�
    static BOOL       OnSendFlowerReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ��ȡ�ʻ���Ϣ
    static BOOL       OnGetFlowerByPlayerIDReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ��ȡ�ʻ���
    static BOOL       OnGetFlowerRankingReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ��ȡ˽�ļ�¼
    static BOOL       OnGetPrivateMsgLogListReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ����˽����Ϣ
    static BOOL       OnSendPrivateMsgReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ɾ��˽����Ϣ
    static BOOL       OnDelPrivateMsgReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // ���������
    static BOOL       OnAddToBlacklistReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

    // �Ӻ��������Ƴ�
    static BOOL       OnMoveFromBlacklistReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );    

	// ��ȡ��������Ϣ������б�
	static BOOL       OnGetSendOfflineMsgPlayerListReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  

	// ��ȡĳ��������ҵ�������Ϣ����
	static BOOL       OnReadOfflineMsgReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  
    // ����������
    static BOOL       OnOpenCourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  
    // �򿪴�������
    static BOOL       OnCourageOpenCreateGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ȷ�ϴ�������
    static BOOL       OnCourageCreateGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ����Э������
    static BOOL       OnCourageJoinGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // �������Э������
    static BOOL       OnCourageRandomJoinGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ��Ӹ��Ļ��
    static BOOL       OnCourageOperateHeroReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ȷ����Ӹ��Ļ��
    static BOOL       OnCourageConfirmHeroReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // �ߵ���Ա
    static BOOL       OnCourageFireGroupMemberReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // �򿪹�������
    static BOOL       OnCouragOpenShopReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ������������
    static BOOL       OnCouragBuyPractiseTimesReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ���׼��
    static BOOL       OnCouragPlayerReadyReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ��ҿ�ʼ
    static BOOL       OnCouragPlayerStartReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ����뿪
    static BOOL       OnCouragLeaveGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
    // ���ˢ�¶���
    static BOOL       OnCourageRefreshGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ����������
    static BOOL       OnCourageEnterGroupReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // �뿪��������
    static BOOL		  OnLeaveCourageReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ս���뿪��������
    static BOOL		  OnCourageLeaveBattleReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ��ȡ��������
    static BOOL		  OnCourageGetAwardReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ��������ս������
    static BOOL		  OnCourageEnterBattleSceneReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    // ��������ս�����
    static BOOL       OnCouragGetBattleResultReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen ); 
	//����Ʒ������
	static BOOL		  OnOpenRareItemReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�һ���Ʒ����
	static BOOL		  OnExchangeRareItemReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//����Ʒ���������
	static BOOL       OnOpenUpgradeRareItemReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//������Ʒ������
	static BOOL       OnUpgradeRareItemReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//����������
	static BOOL       OnOpenGymnasiumReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//ѧϰ���ü�������
	static BOOL       OnLearnGymnasiumSkillReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	
	//��������������
	static BOOL       OnOpenGymnasiumUpgradeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//ȷ��������������
	static BOOL       OnGymnasiumUpgradeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//�򿪰�������
	static BOOL		  OnOpenShadeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//�򿪻ƽ�ģʽ����
	static BOOL       OnOpenGoldModeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�򿪰�����������
	static BOOL       OnOpenShadeUpgradeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//������������
	static BOOL       OnShadeUpgradeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//׽������
	static BOOL      OnOpenHuntingReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�ȥ����
	static BOOL		OnFindMonsterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	////��������		
	//static BOOL     OnChangeMonsterReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//ս������
	static BOOL     OnHuntingBattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//����Ȫ����
	static BOOL     OnOpenHotSpringReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//ѡ��
	static BOOL    OnSelectWineReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//����
	static BOOL    OnDrinkWineReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//��Ȫ�ƶ�
	static BOOL    OnDrinkWineMoveReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�뿪��Ȫ
	static BOOL    OnLeaveHotSpringReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	////ѡ�ƣ��ϴ�δ��
	//static BOOL    OnSelectWineNotDrink(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//��λ����
	static BOOL    OnChangeOtherReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�;�
	static BOOL    OnGiveWineReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//���ѡ��
	static BOOL    OnClickSelectWineReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	////Ѱ������
	//static BOOL    OnFirstFindMonsterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//ȷ�ϴ;�
	static BOOL    OnSureGiveWineReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//����
	static BOOL    OnClosedMonsterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//��Ա�䶯��ʶ����
	static BOOL    OnFactionPlayerMarkReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//���˳�����
	static BOOL		OnOpenLeaveFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen  );

	//�˳�����
	static BOOL		OnLeaveFactionReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen  );

	//������
	static BOOL     OnOpenFactionUpgradeReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen  );

	static BOOL    OnFactionUpgradeReq(  VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	static BOOL    OnGetFactionBattleLogReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL    OnOpenFindDrinkReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

// װ����ͨ
    // ��װ����ͨ���
    static BOOL       OnOpenEquipMasterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  
    
    // ����װ����ͨ
    static BOOL       OnActivateEquipMasterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  

    // ͻ��
    static BOOL       OnBreakMasterReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  

    // ������֮ͨ��
    static BOOL       OnGetMasterBookReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  

    // �ο���ͨ���������
    static BOOL       OnWipeMasterBookReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );  

    // ��ǧ
    static BOOL       OnCheatMasterBookReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
    
    // ȷ��ʹ�þ�ͨ������
    static BOOL       OnConfirmMasterBookReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	// ����ս������
	static BOOL       OnCourageBattleReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//�����ɽ���Ⱥ
	static BOOL		OnOpenFactionBuildGroupReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//�鿴���ڽ���
	static BOOL    OnHotSpringOverRewardReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	static BOOL    OnHuntingIntegralReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	static BOOL   OnIgnorePromptReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	static BOOL    OnOpenLevelHotSpring(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//���ȫ���ܾ�
	static BOOL OnAuditAllRefuseReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

    static BOOL OnOpenRecvFlowerTabReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnAcceptFlowerReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL       OnOpenSendFlowerTabExReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//��Ʒ�һ�
	static BOOL   OnBuyRareItemReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	// �ͻ�
	static BOOL	OnSendFlowerExReq( VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );
	//���ü���ѧϰ
	static BOOL   OnLearnGymnasiumSkillReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen );

	//�����ɳ�Ա�б�
	static BOOL   OnFactionPlayerInfoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//ע�������ǳ�����
	static BOOL        OnRegisterFactionName(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��ͷ�����
	static BOOL   OnOpenChangeIconReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//ͷ�����
	static BOOL   OnChangeIconReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//���һ��Ź�
	static BOOL	OnOpenFindBackDoorsTributeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�һ��Ź�
	static BOOL	OnFindBackDoorsTributeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�򿪲���2
	static BOOL OnOpenEmbattleReq2(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//������
	static BOOL OnUpgradeFormationReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//���󷨣��Ƽ��ݣ�
	static BOOL OnOpenFormationScienceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
// 
// 
// 	//��VIP�������
// 	static BOOL		OnOpenVipGift(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
// 
// 	//���VIP���
// 	static BOOL		OnGetVipGift(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//������
	static BOOL OnUpgradeFormationScienceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��ȡ����
	static BOOL OnGetExprienceHotSpringReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//ѧϰ���ɼ���
	static BOOL OnOpenFactionSkillReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//���������
	static BOOL OnOpenPlayerPanelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��������Ϣ--����
	static BOOL OnOpenPlayerInfoAwakenReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��������Ϣ--����
	static BOOL OnOpenPlayerInfoSkillReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��������Ϣ--����
	static BOOL OnOpenPlayerInfoGodWeaponReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��������Ϣ--��Ʒ
	static BOOL OnOpenPlayerInfoJewelryReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��������Ϣ--װ��
	static BOOL OnOpenPlayerInfoEquipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��������Ϣ--ս��
	static BOOL OnOpenPlayerInfoSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��������Ϣ--����
	static BOOL OnOpenPlayerInfoPetReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//������Ʒ����
	static BOOL OnDressJewelryReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//������ѡ�����
	static BOOL OnOpenHeroSelectPanelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//����Ʒ�ϳ�
	static BOOL OnOpenJewelryGenerateReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��Ʒ�ϳ�
	static BOOL OnJewelryGenerateReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��Ʒǿ��
	static BOOL OnJewelryStrengthReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��Ʒ�ϳ���Ϣ
	static BOOL OnJewelryGenerateInfoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//�ֽ���Ϣ
	static BOOL OnJewelryResolveReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��ǿ���������
	static BOOL OnOpenJewelryStrengthReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//���ζԱ�
	static BOOL OnCompareJewelryReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//���θ�������ǿ��
	static BOOL OnJewelryExtStrengReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//�����ηֽ�
	static BOOL OnOpenJewelryResolveReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//////////////////////////////start GVG//////////////////////////////////////////
	//�����Ͳ���
	static BOOL OnOpenGVGFormationReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��GVG�����
	static BOOL OnOpenGVGActivityReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//���ѱ�����������
	static BOOL OnOpenAlreadApplayReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//���Ͻ�������
	static BOOL OnOpenGVGLastResultReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//���ҵ�Ѻע
	static BOOL OnOpenGVGMyGambleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//������Ѻע
	static BOOL OnGVGOpenGambleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//�򿪹������
	static BOOL OnGVGOpenRuleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//Ѻע����
	static BOOL OnGVGGambleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//�򿪲���������
	static BOOL OnOpenGVGMoneyRankReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
    //��ָ�����ɵ�����ս��
    static BOOL OnOpenGvGLogReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
    //�ۿ�����ս��¼��
    static BOOL OnSeeGvGVideoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
    //��������ս��¼��
    static BOOL OnEndGvGVideoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
    //�鿴����ս���б���ͻ��������б�
    static BOOL OnShowGvGMVPReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��ȡTIP����
	static BOOL OnReadFormationPlayerTipReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//����ȷ��
	static BOOL OnGvGFactiomEmbattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//�鿴���
	static BOOL OnOpenGvGiftReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��ȡ���
	static BOOL OnGetGvGiftReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//GVEɸѡ����
	static BOOL OnSelectGroupTypeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//���ɱ���
	static BOOL OnGvGFactionApplayReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��ȡδ��ս��
	static BOOL OnReadBattleLogReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwlen);
	//��ս������
	static BOOL OnOpenDevourSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//����ս��
	static BOOL OnDevourSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//��ս��ϴ��
	static BOOL OnOpenReflashSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//ϴ��ս��
	static BOOL OnReflashSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//����ս��
	static BOOL OnSaveReflashSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	// ������뽫�긱��
	static BOOL OnSoulRepInfoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	// �ڸ�����ˢ����
	static BOOL OnProductSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	// ����ս��
	static BOOL OnEquipSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	// ���½���
	static BOOL OnUnDressSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	// �滻����
	static BOOL	OnReplaceSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	// ����ս��һ���Ϣ
	static BOOL OnSoulExchangeInfoReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	// ���϶һ�ս��
	static BOOL OnExchangeSoulReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//���ҵ�ѫ��
	static BOOL OnOpenMyMedalReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�򿪵�ͼ
	static BOOL OnOpenMapReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//����ϸ�⴫��ͼ
	static BOOL OnOpenOutBoundMapReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    //�鿴�������ɵĳ�Ա��Ϣ
    static BOOL OnViewFactionMembersReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�⴫ս��
	static BOOL OnOutBoundBattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	//����Э��
	static BOOL OnTestReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	// ����ģ��
	static BOOL	OnOpenPetRepReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL	OnProductPetReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL	OnOpenRefinePetReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL	OnOpenPetPanelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL	OnRefinePetReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL	OnOpenStarPanelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL	OnUpPetStarReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenPetFeedPanelReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnPetFristDrawReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnPetResetDrawReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnConfirmFeedReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnPetMerge(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenPetStoreReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnBuyPetStoreItem(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenWashQuality(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnWashQuality(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnChangePetState(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenPetInherit(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnInheritPet(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenPlayerPetPanel(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnRequestAllPetInfo(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	static BOOL OnOpenStoreReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnExchangeGoodsReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    
    // ����
    static BOOL OnOpenEquipMakeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnEquipMakeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnUpgradeHeroReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnOpenFlyReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL OnFlyReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);

	static BOOL OnOpenPetRule(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenSoulUpdateTypeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnSoulUpdateTypeReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	//�ڵ�
	static BOOL OnOpenNeiDanReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnUpdataNeiDanReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnDressNeiDanReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnOpenNeiDanInstanceReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnNeiDanBattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnRecvNeiDanAwardReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL OnSkipNeiDanBattleReq(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
private:
    static BOOL		   SendMsg( CUser *poUser, UINT16 wMsgID );

protected:
	static BOOL        OnBattleReq5(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
    static BOOL        OnBattleReq3(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
	static BOOL        OnBattleReq4(VOID* pUser, VOID* pHeader, const CHAR* pBody, UINT32 dwLen);
};

#endif

