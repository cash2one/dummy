public:
	CTask* GetTask(UINT8 byLineIdx);

	CLineIdx2TaskShmemMap& GetGiveTask(){ return m_mapGiveTask; };//��ȡ����δ���ܵ�����
	CLineIdx2TaskShmemMap& GetAcceptTask() { return m_mapAcceptTask; } ;//��ȡ����δ��ɵ�����
	CLineIdx2TaskShmemMap& GetEncourageTask(){ return m_mapEncourageTask; };//��ȡ���δ��ȡ����������
	CLineIdx2TaskShmemMap& GetFinishTask(){ return m_mapFinishTask; };//��ȡ����ȡ�����ѽ���������
	CLineIdx2TaskShmemMap& GetAllTask() { return m_mapAllTask; } //��ȡ���е�����
	CTask* GetTaskByLine(UINT8 byTaskLine);

	CLineIdx2TaskShmemMap& GetChangeTask() { return m_mapChangeTask; }	
	VOID RecordChangeTask(CTask* poTask);//��¼�仯������
	BOOL CkNeedTaskBaseInfo(CTask* poTask);//����Ƿ�����ȡ�������������·����������Ϣ	

	VOID	GetDT_TASK_DATA_LIST_CLI(DT_TASK_DATA_LIST_CLI& stTaskInfoList, BOOL bLogin = FALSE);	
	VOID	GetDT_TASK_DATA_LIST_CLI_Change(DT_TASK_DATA_LIST_CLI& stTaskInfoList);	
	VOID	GetDT_TASK_COND_RECORD_LIST(DT_TASK_COND_RECORD_LIST& stTaskRecordList);	

	UINT8	GetMaxUnlockCommonInstanceID(DT_INSTANCE_ID& stDT_INSTANCE_ID, BOOL bAcceptTask = FALSE);//����ֵΪ��ǰ����ȡ���������Ƿ��½�������
	VOID	SetLastMainLineTaskProp(UINT32 dwTaskIdx) { m_dwLastAcceptMainLineTaskIdx = dwTaskIdx;};//��һ�����ܵ�������������ǰ��������Ϊ����״̬����Ϊ������

	BOOL CkTaskFinish(UINT8 byTaskLine, UINT32 dwTaskIdx);//��������Ƿ��Ѿ���ɣ�����ɷ���TRUE

	VOID GetUnlockNewInstance(UINT8& byUnlockNewInstanceFlag, UINT8& byHaveNewInstanceFlag, DT_INSTANCE_ID& stUnlockCommonInstanceID, DT_INSTANCE_DATA_CLI& stNewCommonInstanceID);//��ȡ�����¸�����Ϣ.������GetDT_TASK_DATA_LIST_CLI/GetDT_TASK_DATA_LIST_CLI_Change֮ǰ����
protected:
	BOOL	InitTask(DT_TASK_DATA_LIST& stTaskData);//��ʼ������
	CTask*	InitTask(DT_TASK_DATA* pstDT_TASK_DATA);
	VOID	GetDT_TASK_DATA_CLI(CTask* poTask, DT_TASK_DATA_CLI& stDT_TASK_DATA_CLI, BOOL bLogin = FALSE);
private:
	CLineIdx2TaskShmemMap	m_mapAllTask;			//��������
	CLineIdx2TaskShmemMap	m_mapGiveTask;			//����δ���ܵ�����
	CLineIdx2TaskShmemMap	m_mapAcceptTask;		//����δ��ɵ�����	
	CLineIdx2TaskShmemMap	m_mapEncourageTask;		//���δ��ȡ����������
	CLineIdx2TaskShmemMap	m_mapChangeTask;		//�仯���������б仯������(����m_mapNBIEncourageTask,���������������)��ÿ�η��ظ��ͻ��˺����
	CLineIdx2TaskShmemMap	m_mapNBIEncourageTask;	//�仯��������Ҫ������Ϣ�Ľ���״̬����(���ڸս��ܵ��������������������������)	
	CLineIdx2TaskShmemMap	m_mapFinishTask;		//�ѽ�������
	UINT32					m_dwLastAcceptMainLineTaskIdx;	//��һ�����ܵ���������(�����жϽ�������)������ǰ��������Ϊ����״̬����Ϊ������
