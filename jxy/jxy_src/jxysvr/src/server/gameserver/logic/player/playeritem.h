public:
	VOID GetIdleEquip(DT_EQUIP_DATA_LST_CLI& stEquipList);//��ȡ���п���װ��
	VOID GetAllEquip(DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI& stEquipList);//��ȡ����װ��
	VOID GetAllEquip(DT_EQUIP_STRENGTHEN_COMPOSE_DATA_LST_CLI& stEquipList, UINT32 adwStrengthen10CoinInfo[MAX_BAG_OPEN_NUM]);//��ȡ����װ��

    void GetAllEquip_v410(DT_EQUIP_STRENGTHEN_ENCHANT_DATA_LST_CLI&);

	CBag&	GetBag() { return m_oBag; }
	CItemKind2IdxMap&		GetEquipKind2IdxMap() { return m_mapEquipKind2Idx; }
	CPlayerEquipShmemMap&	GetAllEquip() { return m_mapAllEquip; }
	CEquip*	GetEquip(UINT16 wEquipKindID, UINT16 wEquipIdx);
	UINT16	GetNextEquipIdx(UINT16 wItemKindID);//��ȡĳ��װ�����ߵ�idx,�� �ı䵱ǰ��idx
	UINT16  CkNextEquipIdx(UINT16 wItemKindID);//��ȡĳ��װ�����ߵ�idx,���� �ı䵱ǰ��idx
	UINT16  GetNextJeweryIdx(UINT16 wItemKindID);//��ȡĳ��װ�����ߵ���Ʒ,�� �ı䵱ǰ��idx
	VOID	ReturnNextEquipIdx(UINT16 wItemKindID, UINT16 wIdx);//����ʧ�ܣ��黹idx
	//VOID	SetStrengthenPromptEquip(CEquip* poEquip);
	UINT32  GetStrenthenCountDown();//��ȡǿ��CD����ʱ

	VOID OnDeleteEquip(CEquip* poEquip);//���װ���ص�,�ڲ��ص�OnDeleteItem
	VOID OnAddEquip(CEquip* poEquip, BOOL bHaveDress = FALSE); //����װ���ص�
	VOID OnDeleteItem(CItem* poItem); //������߻ص�,�ڲ��ص��б����ص�
	VOID ReduceItem( CGoods *poItem, CRecordMgr::EDecItemType emOpType ); //������Ʒ�����������Ϊ0�������, nParam1��ʾ����
	
	// ADD by WYX 2012-11-22 ���ӻ�ȡ��ҩ����
	VOID GetDT_DRUG_NUM(UINT16 awDrugNum[MAX_DRUG_LEVEL]);//��ȡ��ҩ����
	VOID GetDT_DRUG_NUM(UINT16 &awDrugNum, const UINT16 wDrugLeavel);//��ȡ��ҩ����
	VOID GetDT_MIX_DRUG_NUM(UINT8 byDrugNum[MAX_DRUG_LEVEL]);		//��ȡÿƷ�ϳɵĵ�ҩ����Ҫ�ĸ���
	
	UINT16 GetDT_MIX_DRUG(UINT8 &byDrugLevel, UINT16 &wUseDrugNum, UINT16 &wProduceDrugNum);	//�ϳɵ�ҩ

	UINT16 ClrUseDrugCD(UINT16 wKindID);

	UINT8  GetBagFullFlag();

	UINT16 SmithyBuyEquip(UINT16 wHeroKindID, UINT8 byEquipPos, DT_EQUIP_DATA_STRENGTHEN_CLI& stEquipStrengthenInfo, DT_EQUIP_DATA_CLI& stEquipInfo, UINT32& dwStrengthen10Coin);
	UINT16 ClrStrengthenCD();

	//��ȡװ���������Ƕ��ʯ������
	UINT8 GetMaxMosaicGemNum();
	//��ȡ��Ʒռ�õĸ�����
	UINT16 GetItemUseBagNum(UINT16 wItemID, UINT8 byNum = 1);
	//VOID	ResetStrenthenUpgradeEquipPrompt(CEquip* poEquip = NULL);//����ǿ��/����װ����ʾ��Ϣ
public:
	////////////////////////////////////////////////��Ʒ//////////////////////////////////////////////
	CPlayerJewelryShmemMap& GetAllJewelry() { return m_mapAllJewelry; }
	CJewelry* GetJewelry(UINT16 wJewelryID, UINT16 wIdx);
	UINT8 OnJewelryGenerateCheck(vector<UINT32>& vecKey, UINT16& wDressLevel, UINT8& byColorType, DT_RES_DATA& stRes);
	UINT16 OnJewelryGenerateInfo(PKT_CLIGS_JEWELRY_GENERATE_INFO_REQ& stReq, PKT_CLIGS_JEWELRY_GENERATE_INFO_ACK& stAck);
	UINT16 OnJewelryGenerate(PKT_CLIGS_JEWELRY_GENERATE_REQ& stReq, PKT_CLIGS_JEWELRY_GENERATE_ACK& stAck);
	UINT16 OnGetPlayerInfoJewelry(PKT_CLIGS_PLAYER_INFO_JEWELRY_ACK& stAck);
	UINT16 OnJewelryResolve(PKT_CLIGS_JEWELRY_RESOLVE_REQ& stReq, PKT_CLIGS_JEWELRY_RESOLVE_ACK& stAck);
	UINT16 OnJewelryResolve(PKT_CLIGS_JEWELRY_RESOLVE_REQ& stReq, PKT_CLIGS_JEWELRY_RESOLVE_ACK2& stAck);
	UINT16 OpenJewelryStrength(PKT_CLIGS_OPEN_JEWELRY_STRENGTH_ACK& stAck);
	VOID OnDeleteJewelry(CJewelry* poJewelry);
protected:
	BOOL	InitBag(UINT8 byBagOpenNum);//��ʼ������
	BOOL	InitBagEquipItem(DT_BAG_EQUIP_DATA_LST& stBagEquipData);//��ʼ������װ������
	BOOL	InitBagGoodsItem(DT_BAG_GOODS_DATA_LST& stBagGoodsData);//��ʼ��������Ʒ����
	BOOL	InitBagJewelryItem(DT_BAG_JEWELRY_DATA_LST& stBagJewelryData);//��ʼ��������Ʒ����
	BOOL	RecordClrUseDrugCD( INT32 nCostGold ); //��¼	
	CEquip*	DressSmithyBuyEquip(CHero* poHero, UINT16 wEquipID);//���������̹���װ��
private:
	CBag				m_oBag;					//ӵ�еı���	
	CItemKind2IdxMap	m_mapEquipKind2Idx;		//�������ɵ������(��С���Կ��ƣ���ʹ��ԭʼmap,װ��Attachʱ���¸�ֵ)
	CPlayerEquipShmemMap m_mapAllEquip;			//ӵ�б�����ͬ���͵�����װ��(������+װ��������)
	CPlayerJewelryShmemMap m_mapAllJewelry;		//����+����
	//CEquip*				m_poMinStrengthenLevelEquip;//��Сǿ���ȼ�װ���������������Ƿ��ǿ����ʾ.(ֻ��Я���佫������װ��)
	//���׹����ѷϳ�
	//CEquip*				m_poMaxUpgradeLevelEquip;	//��󴩴��ȼ�װ���������������Ƿ��������ʾ