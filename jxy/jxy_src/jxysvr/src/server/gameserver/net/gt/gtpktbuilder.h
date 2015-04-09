

#ifndef _GT_SERVER_PACKAGE_BUILDER_H_
#define _GT_SERVER_PACKAGE_BUILDER_H_

#include "sdpkg.h"
#include <common/client/errdef.h>
#include <protocligs.h>

using namespace SGDP;

class CPlayer;

class CGTPktBuilder : public CSDPacketBuilder
{
public:
    static CGTPktBuilder* Instance()
    {
        static CGTPktBuilder oGTPkgBuilder;
        return &oGTPkgBuilder;
    }
protected:
    CGTPktBuilder();
    ~CGTPktBuilder();
public:
    CHAR*  EncodeToCliBuffer(const UINT16 wMsgID) ;
    INT32  EncodedToCliLength() ;
private:
    CHAR    m_szEncodeBuffer[MAX_PACKET_LEN];
    INT32   m_nEncodedLen;
public:

    UINT16 EnterGSAck(UINT16 wErrCode, CPlayer* poPlayer = NULL);

    UINT16 GetHeroInfoErrorAck( UINT32 dwError );
    UINT16 GetHeroInfoAck(CPlayer* poPlayer, UINT8 byEquipBagFlag, BOOL bSelfQuery);

    UINT16 OnEnterHomeAck(CPlayer* poPlayer, UINT8 byKind);

    UINT16 EnterInstanceAck(UINT16 wErrCode, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, CPlayer* poPlayer);

    //UINT16 BattleAck(CPlayer* poPlayer, UINT8 byMonsterIdx, UINT16 wHangNum, UINT32 adwHangIDList[]);
    //UINT16 BattleAck(PKT_CLIGS_BATTLE_ACK* pstPKT_CLIGS_BATTLE_ACK);

    UINT16 PickUpAck(UINT16 wErrCode);

    UINT16 ExitInstanceAck(CPlayer* poPlayer);

    UINT16 GetInstanceRecordAck(PKT_CLIGS_GET_SCENE_INSTANCE_ACK* pstPKT_CLIGS_GET_SCENE_INSTANCE_ACK);

    UINT16 OpenSmithyAck(CPlayer* poPlayer, UINT8 byBuildKindID);

    UINT16 SmithyBuyEquipAck(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byEquipPos);

    UINT16 StrengthenAck(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT8 byStrengthenType, UINT16 wLevel);

    UINT16 EquipEnchantAck(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT16 wLevel);

	UINT16 GetOpenLightInfoAck(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx);

	UINT16 OpenLightAck(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT8 byGoldFlag);

    UINT16 OpenRecruitAck(CPlayer* poPlayer, UINT8 byBuildKindID);

    UINT16 RecruitHeroAck(CPlayer* poPlayer, UINT16 wHeroKindID);

    UINT16 DisbandHeroAck(CPlayer* poPlayer, UINT16 wHeroKindID);

    UINT16 OpenProduceAck(CPlayer* poPlayer, UINT8 byBuildKindID);

    UINT16 OpenBagAck(CPlayer* poPlayer);

    UINT16 OpenScienceAck(CPlayer* poPlayer, UINT8 byBuildKindID);

    UINT16 ScienceAttrUpgrade(CPlayer* poPlayer, UINT8 byAttrKindID, UINT16 wLevel);

    UINT16 ScienceBuildUpgradeAck(UINT16 wErrCode, CPlayer* poPlayer, UINT8 byBuildKindID);

    UINT16 RecvTaskEncourageAck(CPlayer* poPlayer, UINT8 byTaskLineIdx, UINT32 dwTaskIdx);

    UINT16 OpenRaceBuildAck(CPlayer* poPlayer, UINT8 byBuildKindID);

    UINT16 ChallengeAck(UINT16 wErrCode, CPlayer* poPlayer, CPlayer* poEnemy);

    UINT16 RecvRankEncourageAck(CPlayer* poPlayer);

    UINT16 OpenShopAck(CPlayer* poPlayer, UINT8 byTabID);

    UINT16 BuyItemAck(CPlayer* poPlayer, UINT8 byTabID, UINT16 wItemKindID, UINT16 wPileCount);

    UINT16 SellItemAck(CPlayer* poPlayer, UINT16 wItemKindID, UINT16 wIdx, UINT16 wNum);

    UINT16 ClrPlayerCache(UINT8 byExt = 0);//0Ϊ״̬�ж��Ƿ����µ�¼(����ʹ��)��1Ϊǿ��������
    UINT16 RegiUserNameNtf();//ע���û���֪ͨ

    UINT16 EquipAck(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byDressType, UINT16 wDressItemKindID, UINT16 wDressItemIdx, UINT16 wUndressItemKindID, UINT16 wUndressItemIdx);

    UINT16 QuickEquipAck(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byEquipNum, DT_EQUIP_ID astEquipIDLst[EQUIP_POS_NUM]);

    UINT16 EmbattleAck(CPlayer* poPlayer, DT_FORMATION_DATA& stFormationInfo);

    UINT16 OpenEmbattleAck(CPlayer* poPlayer);

    UINT16 OpenItemMakerAck(CPlayer* poPlayer, UINT16 wItemKindID);

    UINT16 MakeItemAck(CPlayer* poPlayer, UINT16 wItemKindID, UINT16 wEquipKindID, UINT16 wEquipIdx);

    UINT16 GetHeroBrugAck(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byNeedDrugItemFlag);

    UINT16 UseBrugAck(CPlayer* poPlayer, UINT16 wHeroKindID, UINT16 wKindID);

    UINT16 OnhookAck(CPlayer* poPlayer, UINT8 byRunTimes, DT_INSTANCE_ID stDT_INSTANCE_ID);

    UINT16 OnOpenInstanceEncourageBoxAck(CPlayer* poPlayer);

    UINT16 OnIncreaseBagSizeAck(CPlayer* poPlayer, UINT16 wInc2Size, UINT8 byGoldFlag);

    UINT16 OnInterruptOnhookAck(CPlayer* poPlayer);

    UINT16 OnNoCDOnhookAck(CPlayer* poPlayer);

    UINT16 OnOnhookResultAck(CPlayer* poPlayer);

    UINT16 OnClrChallengeCDAck(CPlayer* poPlayer);

    UINT16 OnRecvOnlineEncourageAck(CPlayer* poPlayer);

    UINT16 OnSyncTimeAck(UINT64 qwCliTime);

    UINT16 OnRegisterDspNameAck(CPlayer* poPlayer, CHAR* pszDspName);

    UINT16 UseGoodsAck(CPlayer* poPlayer, UINT16 wGoodsKindID, UINT8 byGetBagInfoFlag, UINT16 wUseNum);

    UINT16 OnOpenLoginEncourageAck(CPlayer* poPlayer);

    UINT16 OnRateLoginEncourageAck(CPlayer* poPlayer);

    UINT16 OnPutLoginEncourageIntoBagAck(CPlayer* poPlayer);

    UINT16 OnGetRankAck();

    UINT16 OnAcceptTaskAck(CPlayer* poPlayer, UINT8 byTaskLineIdx, UINT32 dwTaskIdx);

    UINT16 OnGiveUpTaskAck(CPlayer* poPlayer, UINT8 byTaskLineIdx, UINT32 dwTaskIdx);

    UINT16 OnGetRaceBattleLogAck(CPlayer* poPlayer);

    UINT16 OnOpenCaptureTabAck(CPlayer* poPlayer);
    UINT16 PlunderAck(UINT16 wErrCode, CPlayer* poActive, CPlayer* poPassive = NULL, CPlayer* poCapture = NULL);
    UINT16 OnPlayerUpgrqage(UINT32 dwPlayerID, UINT16 wLevel);
    UINT16 OnOpenEnemyTabAck(CPlayer* poPlayer, UINT16 wStartIdx);
    UINT16 OnDelEnemyAck(CPlayer* poPlayer, UINT32 dwEnemyID, UINT16 wStartIdx);
    UINT16 OnOpenPlunderRecommendPlayerAck(CPlayer* poPlayer);
    UINT16 OnFreeCaptureAck(CPlayer* poPlayer, UINT32 dwCapturePlayerID);
    UINT16 OnGetPlunderBattleLogAck(CPlayer* poPlayer);
    UINT16 OnRefreshPlunderRecommendAck(CPlayer* poPlayer);
    UINT16 OnCollectIncomeAck(CPlayer* poPlayer, UINT32  dwCapturePlayerID, UINT32 dwIncomeValue);
    UINT16 OnBleedCaptureAck(CPlayer* poPlayer, UINT32 dwCapturePlayerID);
    UINT16 OnSetWorkTypeAck(CPlayer* poPlayer, UINT32 dwCapturePlayerID, UINT8 byIncomeType);
    UINT16 OnDriveAwayAck(CPlayer* poPlayer, UINT16 wErrCode = 0);
    UINT16 OnRecvLeftIncomeAck(CPlayer* poPlayer, UINT8 byGridIdx);

    UINT16 OnOpenMoneyTreeAck(CPlayer* poPlayer);
    UINT16 OnRockMoneyTreeAck(CPlayer* poPlayer, UINT8 byGuideFlag);

    UINT16 OnOpenGodweaponAck(CPlayer* poPlayer);
    UINT16 OnUpgradeGodweaponAck(CPlayer* poPlayer, UINT16 wHeroKindID,	UINT16 wQuality, UINT16 wLevel);
    UINT16 OnFreeGodweaponAck(CPlayer* poPlayer, UINT16 wHeroKindID, BOOL bUseGold);

    UINT16 OnOpenAwakenTabReq(CPlayer* poPlayer);
    UINT16 OnAwakenReq(CPlayer* poPlayer, UINT8 byQuickFlag, UINT8 byGoldFlag);
    UINT16 OnOpenDressStudyTabReq(CPlayer* poPlayer);
    UINT16 OnDressStudyReq(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byBagGridIdx, UINT8 byHeroGridIdx);
    UINT16 OnStudyToExpReq(CPlayer* poPlayer, UINT8 byBagGridIdx, UINT8 byAllFlag, UINT8 abySelectConvertColor[MAX_COLOR_NUM]);
    UINT16 OnStudyUpgradeReq(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byGridIdx, UINT8 byLevel);
	/////////////////////////////
	UINT16 OnOpenAwakenTabReq2(CPlayer* poPlayer);
	UINT16 OnAwakenReq2(CPlayer* poPlayer, UINT8 byQuickFlag, UINT8 byGoldFlag);
	UINT16 OnOpenDressStudyTabReq2(CPlayer* poPlayer);
	UINT16 OnDressStudyReq2(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byBagGridIdx, UINT8 byHeroGridIdx);
	UINT16 OnStudyToExpReq2(CPlayer* poPlayer, UINT8 byBagGridIdx, UINT8 byAllFlag, UINT8 abySelectConvertColor[MAX_COLOR_NUM]);
	UINT16 OnStudyUpgradeReq2(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 byGridIdx, UINT8 byLevel);
	/////////////////////////////////

    UINT16 OnOpenResolveTrigram(CPlayer* poPlayer, UINT8 byPos);
    UINT16 OnResolveTrigram(CPlayer* poPlayer, UINT8 byPos ,UINT8 byUseGold);
    UINT16 OnVisitHeroAck(CPlayer* poPlayer, UINT16 wHeroKindID, UINT8 bySizeFlag, UINT8 byGoldFlag);

    UINT16 OnBuyPhystrengthAck(CPlayer* poPlayer);

    UINT16 OnOpenMaintownAck(CPlayer* poPlayer);
    UINT16 OnRecvIncomeAck(CPlayer* poPlayer);
    UINT16 OnLevyIncomeAck(CPlayer* poPlayer);

    //////////////////////////////////////////////////////////////////////////
    UINT16 OnOpenDrugUseTabAck(CPlayer* poPlayer);
    //���佫��ҩ�����������
    UINT16 OnOpenHeroDrugUseTabAck(CPlayer* poPlayer, UINT16 wKindID);
    //�����ҩ����CD����
    UINT16 OnClrUseDrugCDAck(CPlayer* poPlayer, UINT16 wKindID);
    //ʹ�õ�ҩ����
    UINT16 OnUseDrugAckEx(CPlayer* poPlayer, UINT16 wHeroKindID, UINT16	wUseLevel);
    //�򿪵�ҩ�����������
    UINT16 OnOpenUpgreadeDrugAck(CPlayer* poPlayer);
    //��ҩ��������
    UINT16 OnUpgreadeDrugAck(CPlayer* poPlayer, UINT8 byUseDrugLevel);
    //��ҩ�ϳ�����
    UINT16 OnComposeEquipAck(CPlayer* poPlayer, 	UINT16 wEquipItemID, UINT16 wEquipIdx, UINT8 byGoldComposeFlag);

    //�������������
    UINT16 OnOpenPhyStrengthAck(CPlayer* poPlayer);

    UINT16 OnClrStrengthenCDAck(CPlayer* poPlayer);


    UINT16	OnOpenCropReq(CPlayer* poPlayer);
    UINT16	OnOpenCropFieldReq(CPlayer* poPlayer, UINT8 byFieldID);
    UINT16	OnCropReq(CPlayer* poPlayer, UINT8 byFieldID, UINT16 wCropKindID);
    UINT16	OnGainCropReq(CPlayer* poPlayer, UINT8 byFieldID);
    UINT16	OnOpenScienceBuildReq(CPlayer* poPlayer);
    UINT16	OnUpdateScienceReq( CPlayer* poPlayer, UINT8 byKind, UINT16 wCurLevel );
    UINT16	OnClrCropReq(CPlayer* poPlayer, UINT8 byFieldID);
    UINT16	OnOpenExperienceDrugReq(CPlayer* poPlayer, UINT16 wHeroID);
    UINT16	OnUserExperienceDrugReq(CPlayer* poPlayer, UINT16 wHeroID, UINT16 byExperienceDrugID, UINT16 wGoldExperienceRemainCount);
    UINT16	OnOpenMeltEquipReq(CPlayer* poPlayer);
	UINT16	OnMeltReq(CPlayer* poPlayer, UINT8 byGoldFlag, UINT16 wEquipNum, DT_MELT_EQUIP_DATA stDT_MELT_EQUIP_DATA[MAX_BAG_OPEN_NUM], UINT16 wGoodNum, DT_MELT_GOOD_DATA astMeltGoodDataList[MAX_BAG_OPEN_NUM]);
    UINT16	OnOpenUpdateAttrPannelReq( CPlayer* poPlayer, UINT16 wKind, UINT8 byAttrKind );
    UINT16	OnUpdateAttrReq( CPlayer* poPlayer, UINT16 wHeroID, UINT8 byAttrKind, UINT8 byUpdateKind, UINT16 wCurCount );
    UINT16	OnComposeReq( CPlayer* poPlayer, UINT16 wItemKindID, UINT8 byFlag);
    UINT16	OnGetItemReq( CPlayer* poPlayer, UINT16 wItemKindID);
    UINT16	OnGenOrderIDReqError( UINT16 wErrorCode );
    UINT16	OnComposeSeedReq( CPlayer* poPlayer, UINT16 wItemKindID);
    UINT16	OnChatReq( CPlayer* poPlayer, UINT32 dwPlayerID, UINT8 byChatType, UINT8 abyChatContent[MAX_CHAT_CONTENT_NUM], UINT32 dwChatLen);
    UINT16	OnOpenChatReq( CPlayer* poPlayer, UINT32 dwSerialNumber);

    UINT16	OnOpenActivityCenterAck(CPlayer* poPlayer);
    UINT16	OnOpneEatBreadAck(CPlayer* poPlayer);
    UINT16	OnObtainPhystrengthenAck(CPlayer* poPlayer, UINT8 byHaveObtainPhyStrengthenCli, UINT32 dwHaveObtainCoinCli);
    UINT16	OnOLeaveEatBreadAck(CPlayer* poPlayer, UINT8 byHaveObtainPhyStrengthenCli, UINT32 dwHaveObtainCoinCli);

    //��������
    UINT16	OnClimbTowerResetReq(CPlayer* poPlayer,  UINT16 wSceneIdx, UINT8 byTownIdx);
    //�����һ�
    UINT16	OnClimbTowerOnHookReq(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx);

    UINT16	OnOpenPaoshangBuildReq( CPlayer* poPlayer );
    UINT16	OnOpenYabiaoReq( CPlayer* poPlayer );
    UINT16	OnBeginYabiaoReq( CPlayer* poPlayer );
    UINT16	OnFlushBiaoQualityReq( CPlayer* poPlayer, UINT16 wCurQuality, BOOL bDirectMaxLevel );
    UINT16	OnOpenJiebiaoReq( CPlayer* poPlayer, BOOL bEnemy, UINT16 wTimeToEnd, UINT8 byNum );
    UINT16	OnBeginJiebiaoReq( CPlayer* poPlayer, UINT32 dwEnemyID, UINT8 byCount, UINT64 &qwBattleIndex, BOOL &bRepeat );
    UINT16	BattleDataAck5( CPlayer*poPlayer, const DT_BATTLE_DATA5 &data, BOOL bHaveData );
    UINT16	BattleDataAck2( CPlayer*poPlayer, const DT_BATTLE_DATA3 &data, BOOL bHaveData );
	UINT16	BattleDataAck4( CPlayer*poPlayer, const DT_BATTLE_DATA4 &data, BOOL bHaveData );
    UINT16	BeJiebiaoEventNtf( BOOL bRevoltSuccess, UINT64 qwIndex, UINT64 qwCoinDec, UINT32 dwScienceDec,
                               const string &strEnemyDispName, UINT16 wEnemyLevel, UINT32 dwEnemyPower, BYTE byUnreadBattleLogNum );
    UINT16	OnQueryYabiaoBattleLogReq( CPlayer *poPlayer );
    UINT16	OnQueryYabiaoEncourageReq( CPlayer *poPlayer );
    UINT16	OnClearJiebiaoCDReq( CPlayer *poPlayer );
    ////////////////////////
    //��������
    UINT16	OnUpgradeJingjieReq(CPlayer *poPlayer, UINT16 wLevel);
    //����������
    UINT16	OnGenGasBallReq(CPlayer *poPlayer, UINT8 byFlag);
    //����������ȼ�
    UINT16	OnUpGasBallLevelReq(CPlayer *poPlayer, UINT8 byFullLevelFlag);
    //�ռ������ȼ�
    UINT16	OnCollectGasReq(CPlayer *poPlayer);
    //����������ʽ�ȼ�
    UINT16	OnUpgradeSkillActionLevelReq(CPlayer *poPlayer, UINT16 wActionID, UINT16 wActionLevelCli);
    //ѡ������ʽЧ��
    UINT16	OnSelectSkillActionEffectReq(CPlayer *poPlayer, 	UINT16 wActionID, UINT16 wEffectID, UINT8 byAttackRangKind, UINT8 byTraceBuffKind);
    //�򿪾������
    UINT16	OnOpenJingjieTabReq(CPlayer *poPlayer);
    //���������
    UINT16	OnOpenGenGasTabReq(CPlayer *poPlayer);
    //�򿪼������
    UINT16	OnOpenSkillTabReq(CPlayer *poPlayer);

    //��VIP���
    UINT16	OnOpenVipTabReq(CPlayer *poPlayer);

    //����������
    UINT16	OnOpenClimbTowerReq(CPlayer *poPlayer);


    //�������ô�������
    //UINT16 OnBuyClimbTowerResetReq(CPlayer *poPlayer, UINT8 byBuyNum);

    //����Ƕ���
    UINT16 OnOpenXiangqianTabReq( CPlayer *poPlayer );

    //��Ƕ����
    UINT16 OnXiangqianReq( CPlayer *poPlayer, UINT16 wEquipID, UINT16 wEquipIdx, UINT16 wItemID, UINT8 byXiangqianPos, UINT16 wHeroID );

    //
    UINT16 OnAppIDCheckError( UINT16 wErrorCode, UINT32 dwPlayerID, string strTransactionID);

    //byPos ��ʯ��λ��
    UINT16 OnRemoveXiangqianReq( CPlayer *poPlayer, UINT16 wHeroID, UINT16 wEquipID, UINT16 wIdx, UINT8 byPos, BOOL bRemoveAll );

    //��ȡ��Ӣ����
    UINT16 OnGetEliteInstance( CPlayer *poPlayer );

    UINT16 OnResetEliteInstance( CPlayer *poPlayer, UINT8 byIndex, UINT16 wRemainRetNum );
    //��Ӣ�����һ�
    UINT16 OnEliteInstanceOnHook( CPlayer *poPlayer, UINT8 byIndex );

    //��û��ʾ
    UINT16 OnGetActivityPromptReq(CPlayer *poPlayer);

    //����ת����
    UINT16 OnBlueToPurpleReq( CPlayer *poPlayer, UINT32 dwBlueGas);

    //�д�
    UINT16 OnPKBattleReq(CPlayer *poMyself, CPlayer *poEnemy);
    //��ȡ��Դ������ʾ
    UINT16 OnResourcesPromptReq( CPlayer *poPlayer, UINT32 dwRsID);;
    //BOSSս
    UINT16 OnEnterBossbReq(CPlayer *poPlayer, UINT16 wPosX, UINT16 wPosY);
    UINT16 OnLeaveBossbReq(CPlayer *poPlayer);
    UINT16 OnBossbMoveReq(CPlayer *poPlayer, UINT16 wPosX, UINT16 wPosY);
    UINT16 OnBossbHurtReq(CPlayer *poPlayer);
    UINT16 OnOpenInspireTabReq(CPlayer *poPlayer);
    UINT16 OnInspirePowerReq(CPlayer *poPlayer, UINT8 byGoldInspireFlag);
    UINT16 OnBossBReliveReq(CPlayer *poPlayer);
    UINT16 OnGetLastBossBInfoReq(CPlayer *poPlayer);
    UINT16 OnOpenBossBBLReq(CPlayer *poPlayer);
    //appstore��ֵ��֤����
    UINT32 OnAppPayCheckReq( CPlayer *poPlayer, const string &strOrderID, const string &strReceiptData, UINT32 dwTransID, UINT32 dwPayPlayerID );

    //appstore��ֵ�ɹ�,��ұ������ߣ�������ɷ������
    UINT32	OnAppPaySuccess( UINT8 byVipLevel, UINT32 dwTotalAmount, UINT64 qwAllGold, UINT32 dwExchangeGold, const string &strTransactionID, UINT32 dwPlayerID);

public:

    UINT16	GenGUIDAck2GT(string strOrderID, UINT16 wErrCode);
    UINT16	OnOpenRechargeEncourageReq( CPlayer *poPlayer );
    UINT16	OnRecvRechargeEncourageReq( CPlayer *poPlayer );
    UINT16	OnOpenScoreEncourageReq( CPlayer *poPlayer );
    UINT16	OnRecvScoreEncourageReq( CPlayer *poPlayer );
    UINT16	OnGetRandomDspNameReq( CPlayer *poPlayer );

    UINT16	OnOpenExperienceTransferReq( CPlayer *poPlayer, UINT16 wHeroID);
    UINT16	OnExperienceTransferReq( CPlayer *poPlayer, UINT16 wHeroID, UINT16 wTransHeroID, UINT8 byGold);

    UINT16	OnOpenRdchallengeTabReq( CPlayer *poPlayer, UINT8 byRefreshFlag);
    UINT16	OnRdchallengeReq(CPlayer *poPlayer, CPlayer * poEnemyPlayer);
    UINT16	OnClrRDChallengeCDReq(CPlayer *poPlayer);

    UINT16	OnOpenWorshipTabReq(CPlayer *poPlayer, UINT8 byWorshipType);
    UINT16	OnWorshipReq(CPlayer *poPlayer, UINT8 byWorshipType, UINT8 byWorshipTypeLevel);

    UINT16	OnActivityNotifyReq(CPlayer *poPlayer, UINT8 byActivityType, UINT8 byNotify);

    UINT16	OnOpenDogFecesReq(CPlayer *poPlayer, UINT8 byType);

    UINT16	OnGetActivityCenterReq(CPlayer* poPlayer);

    UINT16	OnGetActivityEncourageInfoReq(CPlayer* poPlayer);
	UINT16	OnGetActivityEncourageInfoAck(CPlayer* poPlayer);
	UINT16	OnRecvActivityEncourageAck(CPlayer* poPlayer, UINT16 wActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM], UINT16 wErrCode = ERR_RECV_ACTIVITY_ENCOURRAGE::ID_SUCCESS);
    UINT16	OnRecvActivityEncourageAck(CPlayer* poPlayer, UINT64 qwActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM], UINT16 wErrCode = ERR_RECV_ACTIVITY_ENCOURRAGE::ID_SUCCESS);

    UINT16	OnRecvActivityEncourageAck(UINT16 wErrCode);


    UINT16	OnOpenGemMakerTabReq(CPlayer* poPlayer);
	UINT16	OnOpenGemMakerTabExReq(CPlayer* poPlayer);

    UINT16	OnRecvRatingEncourageReq(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byType, UINT16 wChapter);


    UINT16	OnOpenAwakenExchangeTabReq(CPlayer* poPlayer);
    UINT16	OnExchangeStudyReq(CPlayer* poPlayer, UINT8 byStudyColorKind, UINT8 byStudyAttrKind1, UINT8 byStudyAttrKind2, UINT8 byStudyLevel);

    UINT16	OnOpenEquipComposeTabReq(CPlayer* poPlayer);
    UINT16	OnEquipComposeReq(CPlayer* poPlayer, UINT16 wEquipLevel, UINT8 byCurColorFlag);
    UINT16	OnRecvComposeEquipReq(CPlayer* poPlayer, UINT16 wEquipLevel);



    // �򿪰������
    UINT16		  OnOpenFactionReq( CPlayer* poPlayer );
    // ����������
    UINT16		  OnApplyFactionReq( CPlayer* poPlayer, UINT32 dwFactionID);
    // �����������
    UINT16		  OnCancelApplyFactionReq( CPlayer* poPlayer, UINT32 dwFactionID );
    // ��������
    UINT16		  OnCreateFactionReq( CPlayer* poPlayer, UINT16 byCreateFactionType, TCHAR aszFactionName[MAX_FACTION_NUM], TCHAR aszFactionDescName[MAX_FACTION_DESC_NUM], UINT32 dwFactionID, UINT16 wErrCode);
    // ���Ұ���
    UINT16		  OnSearchFactionReq( CPlayer* poPlayer, TCHAR aszFactionName[MAX_FACTION_NUM]);
    // �������Լ�����
    UINT16		  OnOpenOwnerFactionReq( CPlayer* poPlayer );
    // �򿪰����Ź�
    UINT16		  OnOpenDoorsTributeFactionReq( CPlayer* poPlayer );
    // �Ź�����
    UINT16		  OnDoorsTributeFactionReq( CPlayer* poPlayer, UINT8 byDoorsTributeFlag);
    // ��ȡ�Ź����ɽ���
    UINT16		  OnRecvDoorsTributeFactionReq( CPlayer* poPlayer );
    // �����߳�
    UINT16		  OnKickedFactionReq( CPlayer* poPlayer, UINT32 dwJoinPlayerID);
    // ���ð���ְλ
    UINT16		  OnJobFactionReq( CPlayer* poPlayer, UINT32 dwJoinPlayerID, UINT8 byFlag );
    // ���ð��ɻ�����Ϣ
    UINT16		  OnSetNoticeFactionReq( CPlayer* poPlayer, UINT8 byFlag, TCHAR aszFactionNotice[MAX_FACTION_DESC_NUM]);
    // ���ɽ�ɢ
    UINT16		  OnDissolveFactionReq( CPlayer* poPlayer );

    // �������
    UINT16		  OnAuditFactionReq( CPlayer* poPlayer, UINT32 dwFactionNum, DT_FACTION_AUDIT_PLAYER_DATA astAuditPlayerData[DT_FACTION_PLAYER_NUM]);
	UINT16 OnAuditFactionReq2( CPlayer* poPlayer, UINT32 dwAuditPlayerID, UINT8 byAuditWay);
    // �򿪰��������б�
    UINT16		  OnOpenApplyFactionReq( CPlayer* poPlayer);
    // �򿪰��������б�
    UINT16		  OnOpenRankFactionReq( CPlayer* poPlayer );
    // �򿪰�������б�
    UINT16		  OnOpenAuditFactionReq( CPlayer* poPlayer );
	UINT16		  OnOpenAuditFactionAck( CPlayer* poPlayer );
    // �򿪰�����־�б�
    UINT16		  OnOpenLogFactionReq( CPlayer* poPlayer );

    // �򿪾ۻ����
    UINT16		  OnOpenGetherScienceReq( CPlayer* poPlayer );
    // �ۻ�
    UINT16		  OnGetherScienceReq( CPlayer* poPlayer, UINT8 byGatherType);


	// ����¶��
	UINT16 OnOpenBluePavilionReq(CPlayer* poPlayer);
	// ����¶
	UINT16 OnBegBlueReq(CPlayer* poPlayer);
	// ����¶����
	UINT16 OnImproveLuckReq(CPlayer* poPlayer);
	// ����¶ȷ��������
	UINT16 OnComfirmBegBlueReq(CPlayer* poPlayer);

    // ��ȡ����¶����
    UINT16 OnGetBlueEncourage(CPlayer* poPlayer);

	//ת��ְҵ����
	UINT16 OnChangeCareerReq(CPlayer* poPlayer, UINT8 byCareerID);
	//�Լ���ְҵ��ս����
	UINT16 OnChallengeMyselfReq(CPlayer* poPlayer, UINT8 byCareerID);

	//�򿪵��߶һ��������
	UINT16 OnOpenItemExchangeReq( CPlayer* poPlayer );
	//���߶һ�����
	UINT16 OnItemExchangeReq( CPlayer* poPlayer, UINT16 wExchangeIdx );

	//��Ӫ�ս������
	UINT16 OnOperatingActivityBattleReq(CPlayer* poPlayer, TCHAR* pszBattleKey);

    // ����������
    UINT16 OnOpenCourageReq(CPlayer* poPlayer);

    //�򿪴�������
    UINT16  OnCourageOpenCreateGroupReq(CPlayer* poPlayer);

    //ȷ�ϴ�������
    UINT16  OnCourageCreateGroupReq(CPlayer* poPlayer,UINT8 byJoinType,DT_INSTANCE_ID wInstanceID);

    //����������Э������
    UINT16  OnCourageJoinGroupReq(CPlayer* poPlayer,UINT8 byBattleType,UINT32 dwGroupID);
    
    //����������
    UINT16  OnCourageRandomJoinGroupReq(CPlayer* poPlayer);

    //��ӻ��߸��Ļ��
    UINT16  OnCourageOperateHeroReq(CPlayer* poPlayer);

    //ȷ����ӻ��߸��Ļ��
    UINT16  OnCourageConfirmHeroReq(CPlayer* poPlayer,UINT16 dwKindID);

    //�ߵ���Ա
    UINT16  OnCourageFireGroupMemberReq(CPlayer* poPlayer,UINT32 dwGroupID,UINT32 dwPlayID);

    //��������
    UINT16  OnCourageBuyPractiseTimesReq(CPlayer* poPlayer);

    //�򿪹�������
    UINT16  OnCourageOpenShopReq(CPlayer* poPlayer);

    //���׼��
    UINT16  OnCouragePlayerReadyReq(CPlayer* poPlayer,UINT8 byTpye);

    //��ҿ�ʼ
    UINT16 OnCouragPlayerStartReq(CPlayer* poPlayer);

    //����뿪
    UINT16 OnCouragLeaveGroupReq(CPlayer* poPlayer);

    //���ˢ�¶���
    UINT16 OnCouragRefreshGroup(CPlayer* poPlayer);

    //����������
    UINT16  OnCourageEnterGroupReq(CPlayer* poPlayer);

    //�뿪��������
    UINT16 OnLeaveCourageReq(CPlayer *poPlayer);

    //�뿪��������
    UINT16 OnCourageLeaveBattleReq(CPlayer *poPlayer);

    //����׼����Ϣ
    UINT16 OnCouragReceiveReady(CPlayer *poPlayer);

    //����ˢ����Ϣ
    UINT16 OnCouragReceiveRefresh(CPlayer *poPlayer);

    //����ս������
    UINT16 OnCourageBattleReq(CPlayer *poPlayer, UINT8 byIndex);

    //��ȡ��������
    UINT16 OnCourageGetAwardReq(CPlayer* poPlayer, UINT32 dwIndex = 0);

    //����ս�����
    UINT16 OnCouragGetBattleResultReq(CPlayer* poPlayer);

	// ��ȡ����ϵͳ����б�
	UINT16 OnGetFriendSysPlayerListAck(CPlayer* poPlayer, UINT8 byGetListType, UINT8 byPageCapacity, UINT8 byPageNo);
	// ��ȡ����ϵͳ����б�
	UINT16 OnGetFriendSysPlayerListAck2(CPlayer* poPlayer, UINT8 byGetListType, UINT8 byPageCapacity, UINT8 byPageNo);

	// ɾ������
	UINT16 OnDelFriendAck(CPlayer* poPlayer, UINT32 dwFirendPlayerID);

	// �������
	UINT16 OnSearchPlayerAck(CPlayer* poPlayer, TCHAR aszPlayerName[USERNAME_LEN], UINT8 byPageCapacity, UINT8 byPageNo);

	// �������
	UINT16 OnSearchPlayerAck2(CPlayer* poPlayer, TCHAR aszPlayerName[USERNAME_LEN], UINT8 byPageCapacity, UINT8 byPageNo);


	// �鿴�����Ϣ
	UINT16 OnViewPlayerAck(CPlayer* poPlayer, UINT32 dwPlayerID);

	// ��Ӻ���
	UINT16 OnAddFriendAck(CPlayer* poPlayer, CPlayer *poTargetPlayer);

	// ���ʻ�
	UINT16 OnSendFlowerAck(CPlayer* poPlayer, CPlayer* poTargetPlayer, UINT32 dwSendFlowerNum);

	// ��ȡĳ����ʻ���Ϣ���ջ���¼
	UINT16 OnGetFlowerByPlayerIDAck(CPlayer* poPlayer);

	// ��ȡ��ĳ��ҵ�˽�ļ�¼
	UINT16 OnGetPrivateMsgLogListAck(CPlayer* poPlayer, UINT32 dwRecverID, UINT32 dwStartIdx, UINT8 byGetMsgNum);

	// ����˽����Ϣ
	UINT16 OnSendPrivateMsgAck(CPlayer* poPlayer, CPlayer* poTargetPlayer, TCHAR aszMsgContent[PRIVATE_MSG_CONTENT_LEN]);

	// ɾ��˽�ļ�¼
	UINT16 OnDelPrivateMsgAck(CPlayer* poPlayer, UINT32 dwPlayerID);

	// ���������
	UINT16 OnAddToBlackListAck(CPlayer* poPlayer, CPlayer *poTargetPlayer);

	// �Ƴ�������
	UINT16 OnMoveFromBlackListAck(CPlayer* poPlayer, UINT32 dwPlayerID);

    // ���ͻ����
    UINT16 OnOpenSendFlowerTabAck(CPlayer* poPlayer, UINT32 dwRecvPlayerID);

    // ��ȡ�ʻ���
    UINT16 OnGetFlowerRankingAck(CPlayer* poPlayer);

	// ��ȡ��������Ϣ������б�
	UINT16 OnGetSendOfflineMsgPlayerListAck(CPlayer* poPlayer);  

	// ��ȡĳ��������ҵ�������Ϣ����
	UINT16 OnReadOfflineMsgAck(CPlayer* poPlayer, UINT32 dwPlayerID); 

	//����Ʒ������
	UINT16 OnOpenRareItemAck(CPlayer* poPlayer );

	//�һ���Ʒ����
	UINT16 OnExchangeRareItemAck(CPlayer* poPlayer, UINT32 byGoodID);

	//��Ʒ����������
	UINT16 OnOpenUpgradeRareItemAck(CPlayer* poPlayer );

	//����ȷ������
	UINT16 OnUpgradeRareItemAck(CPlayer* poPlayer );
	
	//������Ӧ��
	UINT16 OnOpenGymnasiumAck( CPlayer* poPlayer );

	//ѧϰ���ü���Ӧ��
	UINT16 OnLearnGymnasiumSkillAck( CPlayer* poPlayer, UINT32 dwSkillID );

	//����������Ӧ��
	UINT16 OnOpenGymnasiumUpgradeAck( CPlayer* poPlayer );

	//ȷ����������Ӧ��
	UINT16 OnGymnasiumUpgradeAck( CPlayer* poPlayer );

	//�򿪰���
	UINT16 OnOpenShadeAck( CPlayer* poPlayer );

	//�򿪻ƽ�ģʽ
	UINT16 OnOpenGoldModeAck( CPlayer* poPlayer );

	//�򿪰�������
	UINT16 OnOpenShadeUpgradeAck( CPlayer* poPlayer );

	//��������
	UINT16 OnShadeUpgradeAck(CPlayer* poPlayer );
	//��׽��
	UINT16 OnOpenHuntingAck(CPlayer* poPlayer );
	//Ѱ������
	UINT16 OnFindMonsterAck(CPlayer* poPlayer, PKT_CLIGS_FIND_MONSTER_REQ& oReq);
	////��������
	//UINT16 OnChangeMonsterAck( CPlayer* poPlayer);
	//����ս��
	UINT16 OnHuntingBattleAck(CPlayer* poPlayer);
    //����ս��
    UINT16 OnHuntingBattleAck2(CPlayer* poPlayer);
	//����ս��
	UINT16 OnHuntingBattleAck3(CPlayer* poPlayer);
	//��������֪ͨ
	UINT16 ChangeSchedule(CPlayer* poPlayer, UINT32 dwCurSchedule);
	//����ȪӦ��
	UINT16 OnHotSpringAck( CPlayer* poPlayer, UINT16 wPosX, UINT16 wPosY );
	//ѡ��
	UINT16 OnSelectWineAck(CPlayer* poPlayer, UINT32 dwWineID);
	//�Ⱦ�
	UINT16 OnDrinkWineAck(CPlayer* poPlayer);
	//�ƶ�λ��
	UINT16 OnDrinkWineMoveAck(CPlayer* poPlayer, UINT16 wPosX, UINT16 wPosY);
	//�뿪��Ȫ
	UINT16 OnLeaveHotSpringAck(CPlayer* poPlayer);

	UINT16 OnChangeOtherAck( CPlayer* poPlayer, UINT32 dwSendPlayerID );
	UINT16 OnGiveWineAck( CPlayer* poPlayer );
	UINT16 OnClickSelectWineAck( CPlayer* poPlayer, UINT8 byDrinkWIneState);
	//UINT16 OnFirstFindMonsterAck( CPlayer* poPlayer );
	UINT16 OnSureGiveWineAck( CPlayer* poPlayer );
	UINT16 OnClosedMonsterAck( CPlayer* poPlayer, UINT8 byChoice );
	UINT16 OnFactionPlayerMarkAck(CPlayer* poPlayer);
	UINT16 OnOpenLeaveFactionAck(CPlayer* poPlayer);
	UINT16 OnOpenFactionUpgradeAck(CPlayer* poPlayer);
	UINT16 OnFactionUpgradeAck(CPlayer* poPlayer);
	UINT16 GetFactionBattleLogAck( CPlayer* poPlayer );
	UINT16 OpenFindDrinkAck( CPlayer* poPlayer );
// 
    // װ����ͨ����װ����ͨ���
    UINT16 OnOpenEquipMasterAck(CPlayer& oPlayer);  

    // װ����ͨ������װ����ͨ
    UINT16 OnActivateEquipMasterAck(CPlayer& oPlayer, BYTE byEquipKind);

    // װ����ͨ��ͻ��
    UINT16 OnBreakMasterAck(CPlayer& oPlayer, BYTE byEquipKind);

    // װ����ͨ��������֮ͨ��
    UINT16 OnGetMasterBookAck(CPlayer& oPlayer);  

    // װ����ͨ���ο���ͨ���������
    UINT16 OnWipeMasterBookAck(CPlayer& oPlayer);  

    // װ����ͨ����ǧ
    UINT16 OnMasterBookCheatAck(CPlayer& oPlayer);

    // װ����ͨ��ȷ��ʹ�þ�ͨ������
    UINT16 OnConfirmMasterBookAck(CPlayer& oPlayer);

	// ����ս��Ӧ��
	UINT16 OnCourageBattleAck(CPlayer* poPlayer);
	
	UINT16 OpenFactionBuildGroupAck(CPlayer* poPlayer);

	UINT16 HotSpringRewardNtf(CPlayer* poPlayer);

	UINT16 OnHotSpringOverRewardAck( CPlayer* poPlayer );

	UINT16 HuntingIntegralAck(CPlayer* poPlayer);

	UINT16 OnIgnorePromptAck( CPlayer* poPlayer, UINT8 byActiviID );

	UINT16 OnOpenLeaveHotSpring(CPlayer* poPlayer);

	UINT16 OnAuditAllRefuseAck(CPlayer* poPlayer);

	UINT16 OnOpenRecvFlowerTabAck(CPlayer* poPlayer);
	UINT16 OnAcceptFlowerAck(CPlayer* poPlayer, UINT32 dwSendPlayerID, UINT64 qwSendTime);
	UINT16 OnOpenSendFlowerTabExAck(CPlayer* poPlayer);
	UINT16 OnSendFlowerExAck(CPlayer* poPlayer, CPlayer *poTargetPlayer, UINT32 dwKindID);
	UINT16 OnBuyRareItemAck(CPlayer* poPlayer, UINT32 dwGoodsID, UINT8 byLeftTime);
	UINT16 OnLearnGymnasiumSkillAck2(CPlayer* poPlayer, UINT32 dwSkillID, UINT8 bySkillCurLevel);
	UINT16 OnFactionPlayerInfoAck(CPlayer* poPlayer);
	UINT16 OnOpenChangeIconAck(CPlayer* poPlayer);
	UINT16 OnChangeIconAck(CPlayer* poPlayer, UINT8 byIconID);
	UINT16 OnOpenFindBackDoorsTributeAck(CPlayer* poPlayer);
	UINT16 OnFindBackDoorsTributeAck(CPlayer* poPlayer, UINT8 byFindBackType);
	UINT16 OnOpenEmbattleAck2(CPlayer* poPlayer);
	UINT16 OnUpgradeFormationAck(CPlayer* poPlayer, UINT8 byFormationID, DT_FORMATION_DATA& stFormation);
	UINT16 OnRegisterFactionNameAck(CPlayer* poPlayer, CHAR* pszDspName);
	UINT16 OnOpenFormationScienceAck(CPlayer* poPlayer);

    // gvg������������ɿ��ս
    UINT16 OnApplyGvGAck(CPlayer& oPlayer);


	UINT16 OnUpgradeFormationScienceAck(CPlayer* poPlayer, UINT8 byFormationID);
	UINT16 OnGetExpeienceHotSpringAck(CPlayer* poPlayer, UINT32 dwExprienceValue);
	UINT16 OnOpenFactionSkillAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerPanelAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoAwakenAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoSkillAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoGodWeaponAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoJewelryAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoEquipAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoSoulAck(CPlayer* poPlayer);
	UINT16 OnOpenPlayerInfoPetAck(CPlayer* poPlayer);
	UINT16 OnDressJewelryAck(CPlayer* poPlayer, PKT_CLIGS_DRESS_JEWELRY_REQ& pReq);
	UINT16 OnOpenHeroSelectPanelAck(CPlayer* poPlayer);
	UINT16 OnOpenJewlryGenerateAck(CPlayer* poPlayer);
	UINT16 OnJewlryGenerateAck(CPlayer* poPlayer, PKT_CLIGS_JEWELRY_GENERATE_REQ& stReq);
	UINT16 OnJewlryGenerateInfoAck(CPlayer* poPlayer, PKT_CLIGS_JEWELRY_GENERATE_INFO_REQ& stReq);
	UINT16 OnJewlryStrengthAck(CPlayer* poPlayer, PKT_CLIGS_JEWELRY_STRENGTH_REQ& stReq);
	UINT16 OnJewelryResolveAck(CPlayer* poPlayer, PKT_CLIGS_JEWELRY_RESOLVE_REQ& stReq);
	UINT16 OnOpenJewelryStrengthAck(CPlayer* poPlayer);
	UINT16 OnJewelryCompareAck(CPlayer* poPlayer, PKT_CLIGS_JEWELRY_COMPARE_REQ& stReq);
	UINT16 OnJewelryExtStrengAck(CPlayer* poPlayer, PKT_CLIGS_JEWELRY_EXT_UPGRADE_REQ& stReq);
	UINT16 OnOpenJewelryResolve(CPlayer* poPlayer, PKT_CLIGS_OPEN_JEWELRY_RESOLVE_REQ& stReq);

    UINT16 OnOpenGVGActivityAck(CPlayer* poPlayer);
    UINT16 OnGVGApplyAck(CPlayer* poPlayer);
    UINT16 OnGVGMoneyGameAck(CPlayer* poPlayer);
    UINT16 OnGVGChaosGameAck(CPlayer* poPlayer);
    UINT16 OpenGVG16To8To4Ack(CPlayer* poPlayer);
    UINT16 OpenGVGFinalWarAck(CPlayer* poPlayer);
    UINT16 OpenGVGChampionAck(CPlayer* poPlayer);
    UINT16 OpenGVGNotOpenMsgAck(CPlayer* poPlayer);

	UINT16 OnOpenGVGFormationAck(CPlayer* poPlayer);	
	UINT16 OnOpenAlreadApplayAck(CPlayer* poPlayer);
	UINT16 OnOpenGVGLastResultAck(CPlayer* poPlayer);
	UINT16 OnGVGOpenMyGambleAck(CPlayer* poPlayer);
	UINT16 OnGVGOpenGambleAck(CPlayer* poPlayer, PKT_CLIGS_GVG_OPEN_GAMBLE_REQ& stReq);
	UINT16 OnGVGOpenRuleAck(CPlayer* poPlayer);
    UINT16 OnGVGGambleAck(CPlayer* poPlayer, PKT_CLIGS_GVG_GAMBLE_REQ& stReq);
    UINT16 OnOpenMyFactionGvGLogAck(CPlayer* poPlayer);
	UINT16 OnOpenGvGLogAck(CPlayer* poPlayer, UINT32 dwFactionID);
    UINT16 OnSeeGVGVideoAck(CPlayer &oPlayer, UINT64 qwVideoID, BYTE byVideoNum);
    UINT16 OnEndGvGVideoAck(CPlayer &oPlayer, UINT64 qwVideoID, BYTE byEndType);
    UINT16 OnShowGvGMVPAck(UINT64 qwVideoID);

	UINT16 OnOpenGVGMoneyRankAck(CPlayer* poPlayer);
	UINT16 OnReadFormationPlayerTipAck(CPlayer* poPlayer);
	UINT16 OnGvGFactionEmbattleAck(CPlayer* poPlayer, PKT_CLIGS_GVG_FACTION_EMBATTLE_REQ& stReq);
	UINT16 OnOpenGvGiftAck(CPlayer* poPlayer);
	UINT16 OnGetGvGiftAck(CPlayer* poPlayer, PKT_CLIGS_GET_GVG_GIFT_REQ& stReq);
	UINT16 OnSelectGroupTypeAck(CPlayer* poPlayer, PKT_CLIGS_SELECT_GROUP_TYPE_REQ& stReq);
	UINT16 OnGvGFactionApplayAck(CPlayer* poPlayer);
	UINT16 OnReadBattleLogAck(CPlayer* poPlayer, PKT_CLIGS_READ_BATTLE_LOG_REQ& stReq);

	// ս��ϵͳ
	UINT16 OnSoulRepInfoAck(CPlayer* poPlayer, PKT_CLIGS_SOULREP_INFO_REQ& rMsgReq);
	UINT16 OnProductSoulAck(CPlayer* poPlayer, PKT_CLIGS_PRODUCT_SOUL_REQ& rMsgReq);
	UINT16 OnEquipSoulAck(CPlayer* poPlayer, PKT_CLIGS_HERO_EQUIP_SOUL_REQ& rMsgReq);
	UINT16 OnUnDressSoulAck(CPlayer* poPlayer, PKT_CLIGS_HERO_UNDRESS_SOUL_REQ& rMsgReq);
	UINT16 OnReplaceSoulAck(CPlayer* poPlayer, PKT_CLIGS_HERO_REPLACE_SOUL_REQ& rMsgReq);
	UINT16 OnOpenDeourSoulAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_DEVOUR_SOUL_REQ& stReq);
	UINT16 OnDeourSoulAck(CPlayer* poPlayer, PKT_CLIGS_DEVOUR_SOUL_REQ& stReq);
	UINT16 OnOpenReflashSoulAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_REFLASH_SOUL_REQ& stReq);
	UINT16 OnReflashSoulAck(CPlayer* poPlayer, PKT_CLIGS_REFLASH_SOUL_REQ& stReq);
	UINT16 OnSaveReflashSoulAck(CPlayer* poPlayer, PKT_CLIGS_SAVE_REFLASH_SOUL_REQ& stReq);
	UINT16 OnSoulExchangeInfoReq(CPlayer* poPlayer, PKT_CLIGS_SOULEXCHANGE_INFO_REQ& stReq);
	UINT16 OnExchangeSoulReq(CPlayer* poPlayer, PKT_CLIGS_EXCHANGE_SOUL_REQ& stReq);

	//ѫ��
	UINT16 OnOpenMyMedalAck(CPlayer*);
    //ѫ��
    UINT16 OnViewFactionMembersAck(UINT32 dwFactionID);
	//�⴫
	UINT16 OnOpenMapAck(CPlayer*);
	UINT16 OnOpenOutBoundMapAck(CPlayer*, PKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ& );
	UINT16 OnOutBoundBattleAck(CPlayer*, PKT_CLIGS_OUT_BOUND_BATTLE_REQ&);
	UINT16 OnTestAck(CPlayer*, PKT_CLIGS_TEST_REQ&);
	// ����
	UINT16 OnOpenPetRepAck(CPlayer* poPlayer, PKT_CLIGS_PETREP_INFO_REQ& stReq);
	UINT16 OnProductPetAck(CPlayer* poPlayer, PKT_CLIGS_PRODUCT_PET_REQ& stReq);
	UINT16 OnOpenRefinePetAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_REFINEPET_REQ& stReq);
	UINT16 OnRefinePetAck(CPlayer* poPlayer, PKT_CLIGS_REFINEPET_REQ& stReq);
	UINT16 OnOpenPetPanel(CPlayer* poPlayer, PKT_CLIGS_OPEN_PET_PANEL_REQ& stReq);
	UINT16 OnOpenStarPanelAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_STAR_PANEL_REQ& stReq);
	UINT16 OnUpPetStarAck(CPlayer* poPlayer, PKT_CLIGS_UP_STAR_LV_REQ& stReq);
	UINT16 OnOpenPetFeedAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_PETFEED_REQ& stReq);
	UINT16 OnFirstDrawAck(CPlayer* poPlayer, PKT_CLIGS_FIRST_DRAW_REQ& stReq);
	UINT16 OnResetDrawAck(CPlayer* poPlayer, PKT_CLIGS_RESET_DRAW_REQ& stReq);
	UINT16 OnConfirmFeedAck(CPlayer* poPlayer, PKT_CLIGS_CONFIRM_FEED_REQ& stReq);
	UINT16 OnPetMerge(CPlayer* poPlayer, PKT_CLIGS_MERGE_PET_REQ& stReq);
	UINT16 OnOpenPetStoreAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_PET_STORE_REQ& stReq);
	UINT16 OnBuyPetStoreItemAck(CPlayer* poPlayer, PKT_CLIGS_BUY_PET_STORE_ITEM_REQ& stReq);
	UINT16 OnOpenWashQualityAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_WASH_QUALITY_REQ& stReq);
	UINT16 OnWashQualityAck(CPlayer* poPlayer, PKT_CLIGS_WASH_QUALITY_REQ& stReq);
	UINT16 OnChangePetStateAck(CPlayer* poPlayer, PKT_CLIGS_CHANGE_PET_STATE_REQ& stReq);
	UINT16 OnOpenInheritPetAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_PET_INHERIT_REQ& stReq);
	UINT16 OnPetInheritAck(CPlayer* poPlayer, PKT_CLIGS_PET_INHERIT_REQ& stReq);
	UINT16 OnOpenPlayerPetPanel(CPlayer* poPlayer, PKT_CLIGS_OPEN_PLAYERPET_PANEL_REQ& stReq);
	UINT16 OnRequestAllPetInfo(CPlayer* poPlayer, PKT_CLIGS_REQUEST_ALL_PET_INFO_REQ& stReq);
	UINT16 OnOpenStoreAck(CPlayer* poPlayer);
	UINT16 OnExchangeGoodsAck(CPlayer* poPlayer, PKT_CLIGS_EXCHANGE_GOODS_REQ& stReq);
	UINT16 OnOpenPetRuleAck(CPlayer* poPlayer);
	

    // ����
    UINT16 OnOpenEquipMakeAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_EQUIP_MAKE_REQ& stReq);
    UINT16 OnEquipMakeAck(CPlayer* poPlayer, PKT_CLIGS_EQUIP_MAKE_REQ& stReq);

    UINT16 OnUpgradeHeroAck(CPlayer* poPlayer, PKT_CLIGS_UPGRADE_HERO_REQ& stReq);
    UINT16 OnOpenFlyAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_FLY_REQ& stReq);
    UINT16 OnFlyAck(CPlayer* poPlayer, PKT_CLIGS_FLY_REQ& stReq);

	UINT16 OnOpenSoulUpdateTypeAck(CPlayer*, PKT_CLIGS_OPEN_SOUL_UPDATE_TYPE_REQ& stReq);
	UINT16 OnSoulUpdateTypeAck(CPlayer*, PKT_CLIGS_SOUL_UPDATE_TYPE_REQ& stReq);

	UINT16 OnOpenNeiDanAck(CPlayer* poPlayer, PKT_CLIGS_OPEN_NEIDAN_REQ& stReq);
	UINT16 OnDressNeiDanAck(CPlayer* poPlayer, PKT_CLIGS_DRESS_NEIDAN_REQ& stReq);
	UINT16 OnUpdataNeiDanAck(CPlayer* poPlayer, PKT_CLIGS_UPDATA_NEIDAN_REQ& stReq);
	UINT16 OnOpenNeiDanInstanceAck(CPlayer* );
	UINT16 OnNeiDanBattleAck(CPlayer*, PKT_CLIGS_NEIDAN_BATTLE_REQ& stReq);
	UINT16 OnRecvNeiDanAwardAck(CPlayer*, PKT_CLIGS_RECV_NEIDAN_AWARD_REQ& stReq);
	UINT16 OnSkipNeiDanBattleAck(CPlayer*, PKT_CLIGS_SKIP_NEIDAN_BATTLE_REQ& stReq);
protected:
	VOID	FillBiaoAckInfo( PKT_CLIGS_FLUSH_BIAO_QUALITY_ACK &ack, CPlayer &oPlayer );
	UINT16	OnPKBattleReq5(CPlayer *poMyself, CPlayer *poEnemy);
    UINT16	OnPKBattleReq3(CPlayer *poMyself, CPlayer *poEnemy);
	UINT16	OnPKBattleReq4(CPlayer *poMyself, CPlayer *poEnemy);
	UINT16  PlunderAck5(UINT16 wErrCode, CPlayer* poActive, CPlayer* poPassive = NULL, CPlayer* poCapture = NULL);
    UINT16  PlunderAck3(UINT16 wErrCode, CPlayer* poActive, CPlayer* poPassive = NULL, CPlayer* poCapture = NULL);
	UINT16  PlunderAck4(UINT16 wErrCode, CPlayer* poActive, CPlayer* poPassive = NULL, CPlayer* poCapture = NULL);
	UINT16	OnBeginJiebiaoReq5( CPlayer* poPlayer, UINT32 dwEnemyID, UINT8 byCount, UINT64 &qwBattleIndex, BOOL &bRepeat );
    UINT16	OnBeginJiebiaoReq3( CPlayer* poPlayer, UINT32 dwEnemyID, UINT8 byCount, UINT64 &qwBattleIndex, BOOL &bRepeat );
	UINT16	OnBeginJiebiaoReq4( CPlayer* poPlayer, UINT32 dwEnemyID, UINT8 byCount, UINT64 &qwBattleIndex, BOOL &bRepeat );

	UINT16	OnRdchallengeReq5(CPlayer *poPlayer, CPlayer * poEnemyPlayer);
    UINT16	OnRdchallengeReq3(CPlayer *poPlayer, CPlayer * poEnemyPlayer);
	UINT16	OnRdchallengeReq4(CPlayer *poPlayer, CPlayer * poEnemyPlayer);
	UINT16	ChallengeAck5(UINT16 wErrCode, CPlayer* poPlayer, CPlayer* poEnemy);
    UINT16	ChallengeAck3(UINT16 wErrCode, CPlayer* poPlayer, CPlayer* poEnemy);
	UINT16	ChallengeAck4(UINT16 wErrCode, CPlayer* poPlayer, CPlayer* poEnemy);
	UINT16	BattleDataAck5( CPlayer*poPlayer, DT_BATTLE_DATA5 &data, BOOL bHaveData );
    UINT16	BattleDataAck3( CPlayer*poPlayer, DT_BATTLE_DATA3 &data, BOOL bHaveData );
	UINT16	BattleDataAck4( CPlayer*poPlayer, DT_BATTLE_DATA4 &data, BOOL bHaveData );


};

#endif //#ifndef _GATE_SERVER_PACKAGE_BUILDER_H_

