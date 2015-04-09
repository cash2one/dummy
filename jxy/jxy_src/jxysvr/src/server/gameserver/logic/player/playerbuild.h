public:
	CBuild* NewBuild(UINT8 byKindID);//��ӽ���	
	CBuild* GetBuild(EBuildKind eBuildKind);
	VOID CkRegUserName();//����Ƿ���Ҫע���û���
	VOID GetBuildList(UINT16& wBuildNum , DT_BUILD_DATA_CLI astBuildInfo[MAX_BUILD_NUM]);
public:
    UINT16	GetOpenCruitAck(PKT_CLIGS_OPEN_RECRUIT_ACK& stAck);//��ȡ����ļ����Ϣ
	UINT16	GetOpenCruitAck_v410(PKT_CLIGS_OPEN_RECRUIT_ACK_v410& stAck);//��ȡ����ļ����Ϣ
	UINT16	GetOpenRaceBuildAck(PKT_CLIGS_OPEN_RACE_BUILD_ACK& stAck);//��ȡ�򿪾�������Ϣ
	UINT16	GetOpenSimthyAck(PKT_CLIGS_OPEN_SMITHY_ACK& stAck);//��ȡ����������Ϣ
    UINT16  GetOpenSmithyAck_v410(PKT_CLIGS_OPEN_SMITHY_ACK_v410& stAck);

	UINT16 OpenMainTown(UINT16& wCurLevel,UINT8& byCanCrowFlag, UINT32& dwCrownCoin, UINT32& dwCrownGold, UINT32& dwCrownJingJie,
		UINT32& dwLevyCountDown, UINT32& dwLevyCoin, UINT32& dwLevyJingJie, UINT8& byLevyNum, UINT8 &byTotalLevyNum); //������
	UINT16 Crown(UINT8& byCanCrowFlag);//�ջ�
	UINT16 Levy(UINT32& dwLevyCountDown,UINT8& byLevyNum);//����

	UINT16 OpenDogFeces(UINT8 byType, UINT8 &byNum, DT_DOGFECES_BUILD_TIP astDogFecesBuildTip[MAX_DOGFECES_BUILD_TIP_NUM], DT_FUNC_PROMPT_DATA &stPromptInfo);
    UINT16 OpenSmithyIcon(UINT8 &byNum, DT_DOGFECES_BUILD_TIP astDogFecesBuildTip[MAX_DOGFECES_BUILD_TIP_NUM], DT_FUNC_PROMPT_DATA &stPromptInfo);

	CShmemMap<UINT8, CBuild>& GetBuildMap(){ return m_mapKind2Build; }
protected:
	BOOL	InitBuild(DT_BUILD_DATA_LIST& stBuildData);//��ʼ������,�����ȳ�ʼ������������ģ����ݽ����ж��Ƿ񿪷�
	VOID	AddBuildFunctionGuide(UINT8 byKindID);//��ӽ�����������
	UINT32	GetLevyCountDown();//��ȡ�´����յ���ʱ
	BOOL	GetDT_RECRUIT_HERO_DATA(CHero* poHero, DT_RECRUIT_HERO_DATA& stDT_RECRUIT_HERO_DATA);
    BOOL	GetDT_RECRUIT_HERO_DATA_v410(CHero* poHero, DT_RECRUIT_HERO_DATA_v410&);

    BOOL	GetDT_RECRUIT_HERO_DATA_OF_GM(CHero* poHero, DT_RECRUIT_HERO_DATA& stDT_RECRUIT_HERO_DATA);
    BOOL	GetDT_RECRUIT_HERO_DATA_OF_GM_v410(CHero* poHero, DT_RECRUIT_HERO_DATA_v410& stDT_RECRUIT_HERO_DATA);

private:
	CShmemMap<UINT8, CBuild>	m_mapKind2Build;		//ӵ�еĽ���,keyΪ�������ͣ�Ϊ�˲���,ͬ�����Ͳ����ظ�����	
	//Value1 ,��������Ϊ�ջ�ʱ��
	//Value2 ,��������Ϊ����ʱ��
	//Value3 ,��������Ϊ���յĴ���
	SMaintownLevyProp*	m_pstMaintownLevyProp;