public:
	CEnemy* AddEnemy(UINT32 dwEnemyID);//��ӳ�У����Ѵ��ڣ���ս����++	
	UINT16 GetEnemyInfo(UINT16 wStartIdx, UINT16& wTotalNum, UINT16& wCurNum, DT_ENEMY_DATA_CLI astEnemyInfo[MAX_GET_ENEMY_NUM]);
	CEnemy* GetEnemy(UINT32 dwEnemyID);
	UINT16 DelEnemy(UINT32 dwEnemyID, UINT16& wStartIdx,UINT16& wTotalNum, UINT16& wCurNum, DT_ENEMY_DATA_CLI astEnemyInfo[MAX_GET_ENEMY_NUM]);
	vector<CEnemy *> GetEnemyList();
protected:
	BOOL InitEnemy(DT_ENEMY_DATA_LIST& stEnemyData);//��ʼ�����
	BOOL  OnDelEnemy(UINT32 dwEnemyID);//������
private:
	CShmemMap<UINT32, CEnemy>		m_mapEnemy;	//keyΪPlayerID
	//map<UINT64, CEnemy*>			m_mapTimeEnemy;//keyΪ��սʱ�䣬���ظ�+1
	vector<CEnemy*>					m_vecEnemy;//
	
	