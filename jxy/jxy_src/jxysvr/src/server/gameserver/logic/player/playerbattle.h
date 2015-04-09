public:	
	inline SBattleEncourageProp& GetBattleEncourage() { return m_stBattleEncourage; }
	VOID GetBattleEncourage(DT_BATTLE_ENCOURAGE_DATA& stEncourageInfo, DT_DATA_AFTER_BATTLE_ENCOURAGE* pstAfterBattleEncourage = NULL);//��ȡս�������������¼	
	VOID ResetBattleAttr(BOOL bResetHero = FALSE);//����ս������(��ǰֵҲ����ֵΪ���ֵ)
	//VOID ResetConvertBattleAttr();//���û���ս������(��ǰֵ���ٷֱȻ���)������ս��������ǿ��/����
	VOID GetUnreadBattleLogNum(UINT8& byBattleLogTypeNum, DT_UNREAD_BATTLE_LOG_DATA_CLI astUnreadBattleLogInfo[MAX_BATTLE_LOG_TYPE_NUM]);
public:
	//CRace* AddRace(DT_RACE_BASE_DATA& stDT_RACE_BASE_DATA);
	//inline CRace* GetRace() { return m_poRace; }
	UINT32 GetRank() ;

public:
	//CPlunder* NewPlunder();//�����Ӷ�
	//inline CPlunder* GetPlunder() { return m_poPlunder; }
	inline VOID SetPlunder(CPlunder* poPlunder) { m_poPlunder = poPlunder; } //ע�⣬ֻ����CPlunder::Init�е���

public:
	
	inline VOID	RecordLastBattleAck5(PKT_CLIGS_BATTLE_ACK5& stBattleAck) { memcpy(&m_stLastBattleAck5, &stBattleAck, sizeof(PKT_CLIGS_BATTLE_ACK5)); }
    inline VOID	RecordLastBattleAck3(PKT_CLIGS_BATTLE_ACK3& stBattleAck) { memcpy(&m_stLastBattleAck3, &stBattleAck, sizeof(PKT_CLIGS_BATTLE_ACK3)); }
	inline VOID	RecordLastBattleAck4(PKT_CLIGS_BATTLE_ACK4& stBattleAck) { memcpy(&m_stLastBattleAck4, &stBattleAck, sizeof(PKT_CLIGS_BATTLE_ACK4)); }
	
	inline PKT_CLIGS_BATTLE_ACK5* GetLastBattleAck5() { return m_stLastBattleAck5.stBattleInfo.byBattleRoundNum != 0 ? &m_stLastBattleAck5 : NULL; }
    inline PKT_CLIGS_BATTLE_ACK3* GetLastBattleAck3() { return m_stLastBattleAck3.stBattleInfo.byBattleRoundNum != 0 ? &m_stLastBattleAck3 : NULL; }
	inline PKT_CLIGS_BATTLE_ACK4* GetLastBattleAck4() { return m_stLastBattleAck4.stBattleInfo.byBattleRoundNum != 0 ? &m_stLastBattleAck4 : NULL; }

	C3232Map& GetJewelryAttr(){ return m_mapJewelryAttr; }
	UINT32 GetJewelryAttr(UINT32 dwKey);

public:
    VOID	InitBattleAttr(BOOL bResetHero);//��ʼ��ս������

protected:
	VOID    InitJewelryAttr();
	//BOOL	InitRace(DT_RACE_DATA& stDT_RACE_DATA);//��ʼ������
	//BOOL	InitPlunder(DT_PLUNDER_DATA);
	//BOOL	InitRdChallenge(DT_RANDOM_CHALLENGE_DATA& stDT_RANDOM_CHALLENGE_DATA);
	//BOOL	InitWorship(DT_WORSHIP_DATA_LST& stWorshipData);


protected:

private:
	SBattleEncourageProp	m_stBattleEncourage;	//ս��������Ϣ
	//CRace*				m_poRace;			//��������Ϣ
	//CPlunder*			m_poPlunder;			//�Ӷ�	
	//CRdChallenge*			m_poRdChallenge;		//�����ս
	//CWorship*			m_poWorship;			//Ĥ��
	C3232Map				m_mapJewelryAttr;//�ӳ�ָ��
	PKT_CLIGS_BATTLE_ACK5	m_stLastBattleAck5;//�ϴε�ս����¼
    PKT_CLIGS_BATTLE_ACK3   m_stLastBattleAck3;//�ϴε�ս����¼
	PKT_CLIGS_BATTLE_ACK4   m_stLastBattleAck4;//�ϴε�ս����¼

	DECLARE_BUILD_INIT_DESTORY(Worship, CWorship, DT_WORSHIP_DATA_LST)
	DECLARE_BUILD_INIT_DESTORY(RdChallenge, CRdChallenge, DT_RANDOM_CHALLENGE_DATA)
	DECLARE_BUILD_INIT_DESTORY(Race, CRace, DT_RACE_DATA)
	DECLARE_BUILD_INIT_DESTORY(Plunder, CPlunder, DT_PLUNDER_DATA)

	



	