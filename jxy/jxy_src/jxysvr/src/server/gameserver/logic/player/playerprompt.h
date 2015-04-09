public:
	VOID  GetPrompt(DT_FUNC_PROMPT_DATA& stPromptInfo);
	VOID  GetSideActiviPrompt(DT_ACTIVI_SIDE_PROMPT_DATA_LST& stPromptInfo);

	VOID GetMaintownPrompt1(DT_FUNC_COMMON_PROMPT& stMaintownPrompt);//��ȡ�����ջ���ʾ
	VOID GetMaintownPrompt2(DT_FUNC_COMMON_PROMPT& stMaintownPrompt);//��ȡ������ʾ��ʾ
    VOID GetSmithyPrompt(DT_FUNC_COMMON_PROMPT& stSmithyPrompt);//��ȡ��������ʾ
    VOID GetStrengthenPrompt(DT_FUNC_COMMON_PROMPT& stStrengthenPrompt);//��ȡ������ǿ����ʾ
    VOID GetEnchantPrompt(DT_FUNC_COMMON_PROMPT& stEnchantPrompt);//��ȡ�����̸�ħ��ʾ
	VOID GetEquipMakePrompt(DT_FUNC_COMMON_PROMPT& stEquipMakePrompt);//��ȡ������װ��������ʾ
	VOID GetRecruitPrompt(DT_FUNC_COMMON_PROMPT& stRecruitPrompt); //��ȡ��ļ����ʾ��Ϣ
	VOID GetPVPPrompt(DT_FUNC_COMMON_PROMPT& stPvpPrompt); //������ʾ��Ϣ
	VOID GetGodweaponPrompt(DT_FUNC_COMMON_PROMPT& stGodweaponPrompt); //������ʾ��Ϣ	
	VOID GetMoneyTreePrompt(DT_FUNC_COMMON_PROMPT& stMoneyTreePrompt); //�в�����ʾ��Ϣ	
	VOID GetCropPrompt(DT_FUNC_COMMON_PROMPT& stDT_CROP_PROMPT); //��ֲ��ʾ��Ϣ
	VOID GetSciencePrompt(DT_FUNC_COMMON_PROMPT& stDT_SCIENCE_PROMPT); //�Ƽ���ʾ��Ϣ	
	VOID GetPlunderPrompt(DT_FUNC_COMMON_PROMPT& stPlunderPrompt); //�Ӷ���ʾ��Ϣ
	VOID GetEmprisePrompt(DT_FUNC_COMMON_PROMPT& stPlunderPrompt); //ð����ʾ��Ϣ
	VOID GetJingJiePrompt(DT_FUNC_COMMON_PROMPT& stJingJiePrompt); //������ʾ��Ϣ
	VOID GetActivityCenterPrompt(DT_FUNC_COMMON_PROMPT& stPrompt); //�������ʾ��Ϣ
	VOID GetActivityEncouragePrompt(DT_FUNC_COMMON_PROMPT& stPrompt); //���ȡ������ʾ��Ϣ

	VOID GetRacePrompt(DT_FUNC_COMMON_PROMPT& stPvpPrompt); //������ʾ��Ϣ
	VOID GetRdChallengePrompt(DT_FUNC_COMMON_PROMPT& stPvpPrompt); //������ʾ��Ϣ
	
	VOID GetElitePrompt(DT_FUNC_COMMON_PROMPT& stPlunderPrompt); //��Ӣ��ʾ��Ϣ
	VOID GetSoulInstancePrompt(DT_FUNC_COMMON_PROMPT& stPlunderPrompt);	//ս�긱����ʾ��Ϣ
	VOID GetClimbTowerPrompt(DT_FUNC_COMMON_PROMPT& stPlunderPrompt); //������ʾ��Ϣ
	VOID GetYabiaoPrompt(DT_FUNC_COMMON_PROMPT& stPlunderPrompt); //Ѻ����ʾ��Ϣ
	VOID GetFactionPrompt(DT_FUNC_COMMON_PROMPT& stFactionPrompt);//������ʾ��Ϣ
	VOID GetJewelryPrompt(DT_FUNC_COMMON_PROMPT& stFactionPrompt);//��Ʒ��ʾ��Ϣ
	/////////////////////////////////////������ʾ/////////////////////////////////////////
	VOID GetHotSpringPrompt(DT_ACTIVI_SIDE_PROMPT_DATA_LST& stHotSpringPrompt);//��Ȫ��ʾ��Ϣ
	VOID GetShadePrompt(DT_ACTIVI_SIDE_PROMPT_DATA_LST& stShadePrompt);//������ʾ��Ϣ
	//////////////
	BOOL HaveBetterHero();//�Ƿ��и�ǿ���
	VOID GetNewEquipPrompt(DT_NEW_EQUIP_PROMPT_DATA& stNewEquipPrompt); //��ȡ��װ����ǿ��ʾ��Ϣ
	UINT16 GetBoxGoodsPrompt();//��ȡ��ʹ�ñ���ID


	VOID GetCoinResourcePrompt(DT_RESOURCES_PROMPT_DATA &stRsPromptData);
	VOID GetStoryResourcePrompt(DT_RESOURCES_PROMPT_DATA &stRsPromptData);
	VOID GetScienceResourcePrompt(DT_RESOURCES_PROMPT_DATA &stRsPromptData);
	VOID GetJingJieResourcePrompt(DT_RESOURCES_PROMPT_DATA &stRsPromptData);

	//////////////////////////////////////////////////////////////////////////
	VOID GetMainCoinResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetCropCoinResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetMoneyTreeCoinResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetSellCoinResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetMonsterCoinResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetBuddhistSutrasCoinResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);

	//////////////////////////////////////////////////////////////////////////
	VOID GetCropStoryResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);

	//////////////////////////////////////////////////////////////////////////
	VOID GetMeltScienceResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetCropScienceResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);

	//////////////////////////////////////////////////////////////////////////
	VOID GetFirstBossJingJieResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetBuddhistSutrasJingJieResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetRaceJingJieResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetCropJingJieResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetBaishengJingJieResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);
	VOID GetShangXiangJingJieResourcePrompt(DT_RESOURCES_PROMPT &stRsPrompt);

	UINT16 SetIgnorePrompt(UINT8 byActiviID, PKT_CLIGS_PROMPT_IGNORE_ACK& stAck);
protected:	
	BOOL IsScienceCanGet( UINT16 wAppointScienceLevel, UINT8 byScienceKind ); //�Ƿ�ָ���Ƽ�����������ָ���ļ���

	BOOL CkCanPromote(CEquip* poEquip, DT_NEW_EQUIP_PROMPT_DATA& stNewEquipPrompt,  BOOL bJunior);//װ���Ƿ���������
	BOOL CkCanPromote(CHero* poHero, CEquip* poEquip, DT_NEW_EQUIP_PROMPT_DATA& stNewEquipPrompt);//װ���Ƿ���������
private:
	vector<CEquip*>				m_vecNewEquip;//

	const static INT32 ms_nPromotYabiaoCanYabiao=1;
	const static INT32 ms_nPromotYabiaoRunning=2;
	const static INT32 ms_nPromotYabiaoSucceed=3;
	const static INT32 ms_nPromotYabiaoCanJiebiao=4;
	


