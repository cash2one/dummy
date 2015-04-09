#include "jsonencourage.h"
#include "logic/player/player.h"
#include "logic/hero/hero.h"
#include "logic/task/taskmgr.h"
#include "logic/awaken/awaken.h"
#include "protocol/server/protocligs.h"
#include "logic/other/phystrength.h"


void ParseResItem(CJsonResItemVector &vecJsonResItem, Json::Value &item, ACTE_KIND_TYPE byKindType)
{
    if (item.isNull())
    {
        return ;
    }

    if (!item.isObject())
    {
        return ;
    }

    CJsonResItem stItem;
    if (!item["value"].isInt())
    {
        return ;
    }
    else
    {
        stItem.dwKindValue	= item["value"].asInt();
    }

    if (item["num"].isInt())
    {
        stItem.byNum			= item["num"].asInt();
    }
    else
    {
        stItem.byNum			= 1;
    }

    if (item["percent"].isInt())
    {
        stItem.wPercent		= item["percent"].asInt();
    }
    else
    {
        stItem.wPercent		= 100;
    }

    stItem.byKindType	= byKindType;

    if(0 != stItem.dwKindValue)
    {
        vecJsonResItem.push_back(stItem);
    }
}

void ParseAttrJson(CVecJsonAttrBase& vecAttrBase, Json::Value &jsonValue, EBattleAttributeKind byKindType)
{
	if (jsonValue.isNull())
	{
		return ;
	}

	if (!jsonValue.isObject())
	{
		return ;
	}

	DT_ATTR_BASE_DATA stAttrBase;
	if (!jsonValue["value"].isInt())
	{
		return ;
	}
	else
	{
		stAttrBase.dwAttrValue	= jsonValue["value"].asInt();
	}

	if (jsonValue["type"].isInt())
	{
		stAttrBase.byValueType	= jsonValue["type"].asInt();
	}
	else
	{
		stAttrBase.byValueType = 1;
	}


	stAttrBase.byKindID	= byKindType;

	if(0 != stAttrBase.dwAttrValue)
	{
		vecAttrBase.push_back(stAttrBase);
	}
}


BOOL JsonParseResItem(CJsonResItemVectorInfo &JsonResItemVectorInfo, string strJsonValues)
{
    Json::Value root;
    Json::Reader reader;
    if( !reader.parse( strJsonValues, root ) )
    {
        SYS_CRITICAL( _SDT( "json parse error, result:%s" ), strJsonValues.c_str() );
        return FALSE;
    }

    //������ݸ��������Ϊ���Ϊ������ֹ����
    if (!root.isObject())
    {
        SYS_CRITICAL( _SDT( "json size error, result:%s" ), strJsonValues.c_str() );
        return FALSE;
    }
    return JsonParseResItem(JsonResItemVectorInfo, root);
}


BOOL JsonParseResItem(CJsonResItemVectorInfo &JsonResItemVectorInfo, Json::Value &root)
{
    //����ȡ��Դ������
    if (root["empercent"].isString() && root["empercent"].asString() == "all")
    {
        JsonResItemVectorInfo.emPercent	 = em_All;
    }
    else
    {
        JsonResItemVectorInfo.emPercent	 = em_SINGLE ;
    }

    //������Ʒ�ĸ���
    if (root["item"].isArray())
    {
        Json::Value items = root["item"];
        for (UINT32 idx = 0; idx < items.size(); idx++)
        {
            ParseResItem(JsonResItemVectorInfo.vecJsonResItem, items[idx], ACTE_GOOD);
        }
    }


	if (root["soul"].isArray()) {
		Json::Value items = root["soul"];
		for (UINT32 idx = 0; idx < items.size(); idx++) {
			ParseResItem(JsonResItemVectorInfo.vecJsonResItem, items[idx], ACTE_SOUL);
		}
	}

    //������Դ���ݵ�ֵ
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["hero"],			ACTE_HERO);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["coin"],			ACTE_COIN);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["gold"],			ACTE_GOLD);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["phystrength"],		ACTE_PHYSTRENGTH);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["science"],			ACTE_SCIENCE);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["story"],			ACTE_STORY);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["bluegas"],			ACTE_BLUEGAS);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["pruplegas"],		ACTE_PRUPLEGAS);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["jingjie"],			ACTE_JINGJIE);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["doorstribute"],	ACTE_DoorsTribute);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["factionfunds"],	ACTE_FactionFunds);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["factiontaskintegral"],	ACTE_FactionTaskIntegral);
    ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["studyclip"],			ACTE_StudyClip);
	ParseResItem(JsonResItemVectorInfo.vecJsonResItem, root["studyexp"], ACTE_STUDYEXP);
    return JsonResItemVectorInfo.vecJsonResItem.size() > 0 ? TRUE : FALSE;

}


UINT16 JsonGetResItem(CJsonResItem &stItem, CPlayer* poPlayer, DT_RES_ITEM_DATA &stGainResItemData, DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData, DT_RES_NUM_ITEM_DATA &stResNumItemData, CRecordMgr::EAddItemType emOpType)
{
    switch (stItem.byKindType)
    {
    case	ACTE_GOOD://��Ʒ
    {
        ECreateItemRet ItemRet = ECIR_SUCCESS;
        CItem* poItem = CItemMgr::Instance()->CreateItemIntoBag(poPlayer, stItem.dwKindValue, stItem.byNum, ItemRet, 0, emOpType);
        if(NULL == poItem)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CreateItem failed[%d], ItemKindID=%d !"), MSG_MARK, ItemRet, stItem.dwKindValue);
        }
        //��ȡ����Դ
        CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(poItem->GetItemKindID(), stItem.byNum, stGainResItemData.astItemList[stGainResItemData.byItemNum++]);

        DT_ITEM_DATA &stDT_ITEM_DATA = stResNumItemData.astItemList[stResNumItemData.byItemNum++];
        stDT_ITEM_DATA.wKindID		= stItem.dwKindValue;
        stDT_ITEM_DATA.wNum		= stItem.byNum;
    }
    break;
    case	ACTE_HERO://�佫
    {
        BOOL	bAlreadyRecuit = FALSE;
        CKindID2HeroShmemMap& mapKind2Hero = poPlayer->GeHeroMap();
        CHero* poHero = mapKind2Hero.GetData(stItem.dwKindValue);
        if(NULL != poHero)
        {
            if( EHP_RECRUIT != poHero->GetDT_HERO_BASE_DATA().byPos )
            {
                bAlreadyRecuit = TRUE;
            }
        }
        else
        {
            poHero = poPlayer->NewHeroNoBuild(stItem.dwKindValue);
        }

        //����Ѿ�Я�����жϿ�Я����Ŀ
        if( !bAlreadyRecuit )
        {
            CInstance &oInstance = poPlayer->GetInstance();
            //�жϿ�Я����Ŀ
            DT_INSTANCE_ID& stInstanceID = oInstance.GetMaxCommonInstanceID();
            SHeroUnlockProp* pstHeroUnlockProp = CInstancePropMgr::Instance()->GetUnlockHero(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
            if(NULL == pstHeroUnlockProp)
            {
                SYS_CRITICAL(_SDT("[%s: %d]: ERR_COMMON::ID_OTHER_ERR!"), MSG_MARK);
                break;
            }
            if(poPlayer->CkCarryHeroFull())
            {
                return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_HERO_CARRY_FULL;
            }
        }

        //��ļ,Я��
        if (NULL != poHero)
        {
            poPlayer->GetAllCarryHeroMap().AddData(stItem.dwKindValue, poHero);
            poHero->OnRecuit();//��־Ϊ����ļ
            CTaskMgr::Instance()->OnRecruitHero(poPlayer, stItem.dwKindValue);
        }
    }
    break;
    case	ACTE_COIN://ͭǮ
    {
        poPlayer->AddCoin(stItem.dwKindValue, CRecordMgr::EACT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwCoin;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_GOLD://Ԫ��
    {
        poPlayer->AddGold(stItem.dwKindValue, CRecordMgr::EGGT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwGold;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_PHYSTRENGTH://����
    {
        poPlayer->AddPhyStrength(stItem.dwKindValue, CRecordMgr::EAPST_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        //DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        //stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        //stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwp;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_SCIENCE://�����
    {
        poPlayer->AddScience(stItem.dwKindValue, CRecordMgr::EAST_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwScience;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_STORY://����
    {
        poPlayer->AddStory(stItem.dwKindValue, CRecordMgr::EASTT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwStory;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_BLUEGAS://����
    {
        poPlayer->AddBlueGas(stItem.dwKindValue, CRecordMgr::EABGT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwBlueGas;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_PRUPLEGAS://����
    {
        poPlayer->AddPurpleGas(stItem.dwKindValue, CRecordMgr::EAPGT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwPurpleGas;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_JINGJIE://����
    {
        poPlayer->AddJingJie(stItem.dwKindValue, CRecordMgr::EAJT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        //ͬ����Դ
        DT_RES_DATA &stRSYNC_DT_RES_DATA = stRsyncResItemData.astResList[stRsyncResItemData.byResNum++];
        stRSYNC_DT_RES_DATA.byResKind	= stItem.byKindType;
        stRSYNC_DT_RES_DATA.qwResValue	= poPlayer->GetDT_PLAYER_BASE_DATA().qwJingJie;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case ACTE_DoorsTribute: //�Ź�
    {
        CFaction* poFaction = poPlayer->GetFaction();
        if (NULL == poFaction)
        {
            break;
        }
        poFaction->AddDoorsTribute(poPlayer->GetID(), stItem.dwKindValue, CRecordMgr::EAJT_ENCOURAGE);

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_FactionFunds:  //�����ʽ�
    {
        CFaction* poFaction = poPlayer->GetFaction();
        if (NULL != poFaction)
        {
            poFaction->AddFactionFunds(stItem.dwKindValue, CRecordMgr::EAJT_ENCOURAGE);
        }

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
    case	ACTE_FactionTaskIntegral: //�����������
    {

    }
    break;
    case ACTE_StudyClip://
    {
        CAwaken *poAwaken = poPlayer->GetAwaken();
        if ( NULL != poAwaken )
        {
            poAwaken->AddStudyClip(stItem.dwKindValue, CRecordMgr::EASCTUDYTCLIP_ENCOURAGE);
        }

        DT_RES_DATA &stDT_RES_DATA = stGainResItemData.astResList[stGainResItemData.byResNum++];
        stDT_RES_DATA.byResKind	= stItem.byKindType;
        stDT_RES_DATA.qwResValue	= stItem.dwKindValue;

        DT_RES_DATA &stDT_RES_DATA1 = stResNumItemData.astResList[stResNumItemData.byResNum++];
        stDT_RES_DATA1.byResKind	= stItem.byKindType;
        stDT_RES_DATA1.qwResValue	= stItem.dwKindValue;
    }
    break;
	case ACTE_SOUL:
	{
		poPlayer->AddReward(ACTE_SOUL, stItem.dwKindValue, stItem.byNum);
	}
	break;
	case ACTE_STUDYEXP://
	{
		CAwaken *poAwaken = poPlayer->GetAwaken();
		if ( NULL != poAwaken )
		{
			poAwaken->AddStudyExpForGm(stItem.dwKindValue);
		}
	}
	break;
    default:
        break;
    }
    return 0;
}


UINT16 JsonGetResItemVec(CJsonResItemVectorInfo &JsonResItemVectorInfo, CPlayer* poPlayer, DT_RES_ITEM_DATA &stGainResItemData, DT_RSYNC_RES_ITEM_DATA &stRsyncResItemData, DT_RES_NUM_ITEM_DATA &stResNumItemData, CRecordMgr::EAddItemType emOpType)
{
    UINT16 wErrCode = 0;
    if(em_All == JsonResItemVectorInfo.emPercent)
    {
        CRandomVec vecRandom;
        UINT32 wIdx = 0;
        for(wIdx = 0; wIdx < JsonResItemVectorInfo.vecJsonResItem.size(); wIdx++)
        {
            vecRandom.push_back(JsonResItemVectorInfo.vecJsonResItem[wIdx].wPercent);
        }

        //���ȡһ��
        INT32 nRandomHitIdx = GetRandomIdx(vecRandom);
        if(RANDOM_UNHIT == nRandomHitIdx)
        {
            return FALSE;
        }

        if (nRandomHitIdx >= (INT32)JsonResItemVectorInfo.vecJsonResItem.size())
        {
            return FALSE;
        }


        CJsonResItem &stItem = JsonResItemVectorInfo.vecJsonResItem[nRandomHitIdx];
        if (ACTE_GOOD == stItem.byKindType)
        {
            vector<UINT16> vecItemID;
            vecItemID.push_back(stItem.dwKindValue);
            if(CItemMgr::Instance()->CkBagFull(poPlayer, vecItemID))
            {
                return BAG_FULL_ERR;
            }
        }
        wErrCode = JsonGetResItem(stItem, poPlayer, stGainResItemData, stRsyncResItemData, stResNumItemData, emOpType);
        poPlayer->GetPhystrength().GetPhyStrengthInfo(stRsyncResItemData.stCurPhyStrengthInfo);
        return SUCCESS;
    }
    else
    {
        //��ⱳ����Ʒ
        CJsonResItemVectorItr itr;
        vector<UINT16> vecItemID;
        for(itr = JsonResItemVectorInfo.vecJsonResItem.begin(); itr != JsonResItemVectorInfo.vecJsonResItem.end(); itr++)
        {
            if (ACTE_GOOD == itr->byKindType)
            {
                vecItemID.push_back(itr->dwKindValue);
            }
        }

        if(CItemMgr::Instance()->CkBagFull(poPlayer, vecItemID))
        {
            return BAG_FULL_ERR;
        }

        UINT16 wErrCode = 0;
        for (itr = JsonResItemVectorInfo.vecJsonResItem.begin(); itr != JsonResItemVectorInfo.vecJsonResItem.end(); itr++)
        {

            CJsonResItem &stItem = *itr;
            CRandomVec	vecRandom;
            vecRandom.push_back(stItem.wPercent);

            //���ȡһ��
            INT32 nRandomHitIdx = GetRandomIdx(vecRandom);
            if(RANDOM_UNHIT == nRandomHitIdx)
            {
                continue;;
            }

            wErrCode = JsonGetResItem(stItem, poPlayer, stGainResItemData, stRsyncResItemData, stResNumItemData, emOpType);
            if (SUCCESS != wErrCode)
            {
                return wErrCode;
            }
        }
        poPlayer->GetPhystrength().GetPhyStrengthInfo(stRsyncResItemData.stCurPhyStrengthInfo);
        return SUCCESS;
    }
    return SUCCESS;
}

void	 JsonPackResItem(CJsonResItemVectorInfo& JsonResItemVectorInfo, DT_RES_ITEM_DATA &stDT_RES_ITEM_DATA)
{
    for (CJsonResItemVectorItr itr = JsonResItemVectorInfo.vecJsonResItem.begin(); itr != JsonResItemVectorInfo.vecJsonResItem.end(); itr++)
    {
        CJsonResItem &stItem =  *itr;
        switch (stItem.byKindType)
        {
        case	ACTE_GOOD://��Ʒ
        {
            CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(stItem.dwKindValue, stItem.byNum, stDT_RES_ITEM_DATA.astItemList[stDT_RES_ITEM_DATA.byItemNum++]);
        }
        break;
        case	ACTE_HERO://�佫
        {

        }
        break;
        case	ACTE_COIN://ͭǮ
        case	ACTE_GOLD://Ԫ��
        case	ACTE_PHYSTRENGTH://����
        case	ACTE_SCIENCE://�����
        case	ACTE_STORY://����
        case	ACTE_BLUEGAS://����
        case	ACTE_PRUPLEGAS://����
        case	ACTE_JINGJIE://����
        case ACTE_DoorsTribute://�Ź�
        case ACTE_FactionFunds://�����ʽ�
        case ACTE_FactionTaskIntegral://�����������
        case ACTE_StudyClip:////Ǭ����Ƭ
        {
            DT_RES_DATA &stDT_RES_DATA = stDT_RES_ITEM_DATA.astResList[stDT_RES_ITEM_DATA.byResNum++];
            stDT_RES_DATA.byResKind	= stItem.byKindType;
            stDT_RES_DATA.qwResValue	= stItem.dwKindValue;
        }
        break;
        default:
            break;
        }
    }
    return ;
}

BOOL   JsonParseAttrJson(CVecJsonAttrBase &JsonAttrVectorInfo, string strJsonValues)
{
	Json::Value root;
	Json::Reader reader;
	if ( "" == strJsonValues )
	{
		return TRUE;
	}
	if( !reader.parse( strJsonValues, root ) )
	{
		SYS_CRITICAL( _SDT( "json parse error, result:%s" ), strJsonValues.c_str() );
		return FALSE;
	}

	//������ݸ��������Ϊ���Ϊ������ֹ����
	if (!root.isObject())
	{
		SYS_CRITICAL( _SDT( "json size error, result:%s" ), strJsonValues.c_str() );
		return FALSE;
	}
	return JsonParseAttrJson(JsonAttrVectorInfo, root);
}

BOOL   JsonParseAttrJson(CVecJsonAttrBase &JsonAttrVectorInfo, Json::Value &root)
{


	//������Դ���ݵ�ֵ
	ParseAttrJson(JsonAttrVectorInfo, root["HP"],			EBAK_HP);
	ParseAttrJson(JsonAttrVectorInfo, root["Attack"],		EBAK_ATTACK);
	ParseAttrJson(JsonAttrVectorInfo, root["Defend"],		EBAK_DEFEND);
	ParseAttrJson(JsonAttrVectorInfo, root["HitRate"],		EBAK_HITRATE);
	ParseAttrJson(JsonAttrVectorInfo, root["DodgeRate"],	EBAK_DODGERATE);
	ParseAttrJson(JsonAttrVectorInfo, root["CritRate"],		EBAK_CRITRATE);
	ParseAttrJson(JsonAttrVectorInfo, root["DecRitRate"],	EBAK_DECRITRATE);
	
	return JsonAttrVectorInfo.size() > 0 ? TRUE : FALSE;
}