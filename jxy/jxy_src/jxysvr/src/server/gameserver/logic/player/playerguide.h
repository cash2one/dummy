public:
	//����Ƿ��������������Ƿ���TRUE,������������¼
	BOOL	CKGuide(EGuideFunction eGuideFunction);//dwGuideRecordǰ4λΪ������¼����4λΪ�ѿ�����Ϊ��ɵ�����

	//�����������¼�����������������¼
	VOID	AddGuideRecord(EGuideFunction eGuideFunction);

protected:
	VOID	InitmAllGuildFunction();

protected:
	static UINT8	m_abyAllGuildFunction[MAX_GUIDE_NUM];//���е���������