
#include "activityencourage.h"
#include <common/client/errdef.h>
#include <common/client/commondef.h>
#include <logic/player/player.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include "activityencouragemgr.h"
#include "logic/other/locale.h"
#include "logic/build/build.h"
#include "logic/hero/hero.h"
#include "logic/hero/heromgr.h"
#include "logic/task/taskmgr.h"
#include "logic/other/singleprammgr.h"
#include "logic/awaken/awaken.h"
#include "logic/base/jsonencourage.h"
using namespace SGDP;

IMPLEMENT_CLASS_POOL_MGR(CActivityEncourage)


CActivityEncourage::CActivityEncourage()
{
    m_byLastActivityEncourageNum = 0;
    memset(&m_stDT_ACTIVITY_ENCOURAGE_DATA, 0, sizeof(DT_ACTIVITY_ENCOURAGE_DATA));
}


CActivityEncourage::~CActivityEncourage()
{

}

BOOL CActivityEncourage::Init(DT_ACTIVITY_ENCOURAGE_DATA &stDT_ACTIVITY_ENCOURAGE_DATA, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }
    m_poOwner = poOwner;
    memcpy(&m_stDT_ACTIVITY_ENCOURAGE_DATA, &stDT_ACTIVITY_ENCOURAGE_DATA, sizeof(DT_ACTIVITY_ENCOURAGE_DATA));
    return TRUE;
}

VOID CActivityEncourage::AddActivityEncourageID(UINT64 qwActivityID)
{
    //���λ,��ǰ��λһλ
    if (m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum >= MAX_ACTIVITY_ENCOURAGE_INFO_NUM)
    {
        for (INT32 i = 1; i < m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum && i < MAX_ACTIVITY_ENCOURAGE_INFO_NUM; i++)
        {
            DT_ACTIVITY_ENCOURAGE_INFO2 &astActivityInfo1 = m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[i - 1];
            DT_ACTIVITY_ENCOURAGE_INFO2 &astActivityInfo2 = m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[i];
            astActivityInfo1.qwActivityID = astActivityInfo1.qwActivityID;
            astActivityInfo1.qwActivityTime = astActivityInfo1.qwActivityTime;
        }
        m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum--;
    }

    //���һID�Ƿ����
    BOOL bActivityID = FALSE;
    for (INT32 wInfoNum = 0; wInfoNum < m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum && wInfoNum < MAX_ACTIVITY_ENCOURAGE_INFO_NUM; wInfoNum++)
    {
        if(m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[wInfoNum].qwActivityID == qwActivityID)
        {
            bActivityID = TRUE;
            m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[wInfoNum].byActivityTimes++;
            m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[wInfoNum].qwActivityTime = SDTimeSecs();
        }
    }

    //����û���ҵ�Ҫ�ĵ���
    if (!bActivityID)
    {
        m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum].qwActivityID = qwActivityID;
        m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum].byActivityTimes++;
        m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum].qwActivityTime = SDTimeSecs();
        m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum++;
    }
}

//���ID�Ƿ����ȡ
BOOL CActivityEncourage::CkActivityEncourage(UINT64 qwActivityID)
{
    if (NULL == m_poOwner)
    {
        return FALSE;
    }

    SActivityEncouragePro  * poPro = CActivityEncourageMgr::Instance()->GetActivityEncouragePro(qwActivityID);
    if (NULL == poPro)
    {
        return FALSE;
    }
    //��⵱ǰʱ��
    if (SDTimeSecs() < poPro->qwStartTime || SDTimeSecs() > poPro->qwEndTime)
    {
        return FALSE;
    }

    CActivityEncouragePlayerMap	&mapActivityEncourageStartPlayerID = poPro->mapActivityEncourageStartPlayerID;
    CActivityEncouragePlayerMap	&mapActivityEncourageEndPlayerID = poPro->mapActivityEncourageEndPlayerID;
    UINT32 dwPlayerID = m_poOwner->GetID();

    BOOL bHavePri = FALSE;
    CActivityEncouragePlayerMapItr itr = mapActivityEncourageStartPlayerID.find(dwPlayerID);
    if(itr != mapActivityEncourageStartPlayerID.end())
    {
        bHavePri = TRUE;
    }
    else
    {
        itr = mapActivityEncourageEndPlayerID.lower_bound(dwPlayerID);
        if(itr != mapActivityEncourageEndPlayerID.end())
        {
            if(dwPlayerID <= itr->first && dwPlayerID >= itr->second)
            {
                bHavePri = TRUE;
            }
        }
    }


    if(!bHavePri)
    {
        return FALSE;
    }

    for (INT32 i = 0; i < m_stDT_ACTIVITY_ENCOURAGE_DATA.wInfoNum && i < MAX_ACTIVITY_ENCOURAGE_INFO_NUM; i++)
    {
        DT_ACTIVITY_ENCOURAGE_INFO2 &astActivityInfo = m_stDT_ACTIVITY_ENCOURAGE_DATA.astActivityInfo[i];
        if (astActivityInfo.qwActivityID == qwActivityID)
        {
            //
            if (poPro->byNeedCdKey)
            {
                if(astActivityInfo.byActivityTimes < poPro->byNeedCdKey)
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

//����Ƿ����ȡ
BOOL CActivityEncourage::CkActivityEncourage()
{
    CActivityEncouragePropMap &mapActivityEncourageProp = CActivityEncourageMgr::Instance()->GetNorActivityEncouragePropMap();

    CActivityEncouragePropMapItr itr ;
    for (itr = mapActivityEncourageProp.begin(); itr != mapActivityEncourageProp.end(); itr++)
    {
        SActivityEncouragePro &stPro = itr->second;
        //�����Ƿ��Ѿ���¼��û��¼�Ϳ�����ȡ
        if(CkActivityEncourage(stPro.qwActivityID))
        {
            return TRUE;
        }
    }
    return FALSE;
}

//��ȡ���ȡ����ȡ����
UINT8 CActivityEncourage::GetCanActivityEncourageNum()
{
    //�ڸ����в���ʾ������������
    if(EPL_INSTANCE == m_poOwner->GetLocale().GetDT_LOCALE_DATA().byLocaleType)
    {
        return 0;
    }
    UINT8 byNum = 0;
    CActivityEncouragePropMap &mapActivityEncourageProp = CActivityEncourageMgr::Instance()->GetNorActivityEncouragePropMap();
    CActivityEncouragePropMapItr itr ;
    for (itr = mapActivityEncourageProp.begin(); itr != mapActivityEncourageProp.end(); itr++)
    {
        SActivityEncouragePro &stPro = itr->second;

        //�����Ƿ��Ѿ���¼��û��¼�Ϳ�����ȡ
        if(CkActivityEncourage(stPro.qwActivityID))
        {
			USR_INFO("[%s:%d], ActivityID = %llu, PlayerID=%u", MSG_MARK, stPro.qwActivityID, m_poOwner->GetID());
            byNum++;
        }
    }
    return byNum;
}



UINT16 CActivityEncourage::OpenRechargeEncourage(PKT_CLILS_OPEN_RECHARGE_ENCOURAGE_ACK &stAck)
{
    CBuild* poBuild = m_poOwner->GetBuild(EBK_RECHARGE);
    if(NULL == poBuild)
    {
        return ERR_OPEN_RECHARGE_ENCOURAGE::ID_NOT_EXIST_BUILD_ERR;
    }
    poBuild->OnOpen();

    if(1 == m_stDT_ACTIVITY_ENCOURAGE_DATA.byRechargeFlag)
    {
        return ERR_OPEN_RECHARGE_ENCOURAGE::ID_RECEVED_RECHARGE_ENCOURAGE_ERR;
    }
    //���û�г�ֵ������ң���ʾ���ϳ�ֵ �������Ѿ���ֵ���������ʾ����ȡ����
    if (0 == m_poOwner->GetDT_PLAYER_BASE_DATA().dwTotalAmount)
    {
        stAck.byFlag = 0;
    }
    else
    {
        stAck.byFlag = 1;
    }

    CJsonResItemVectorInfo & vecProp = CActivityEncourageMgr::Instance()->GetRechargeActivityEncourageItem();

    CJsonResItemVectorItr itr;
    for (itr = vecProp.vecJsonResItem.begin(); itr != vecProp.vecJsonResItem.end(); itr++)
    {
        if (ACTE_HERO == itr->byKindType)
        {
            BOOL	bNew = FALSE;

            CKindID2HeroShmemMap& mapKind2Hero = m_poOwner->GeHeroMap();
            //ѡ�����佫����
            CHero* poHero = mapKind2Hero.GetData(itr->dwKindValue);
            if(NULL == poHero)
            {
                bNew = TRUE;
                poHero = m_poOwner->NewHeroNoBuild(itr->dwKindValue);
            }

            //������Ϣ
            if(NULL != poHero)
            {
                poHero->GetDT_HERO_BASE_DATA_EQUIP_CLI(stAck.stHeroBaseInfo);
                poHero->GetHeroSkillCli(stAck.stSkillInfo);
            }
            if (TRUE == bNew && NULL != poHero)
            {
                //ɾ����ʱ���ݣ����ڻ�ȡ��ʱ����
                mapKind2Hero.DelData(itr->dwKindValue);
                CHeroMgr::Instance()->RemoveHero(m_poOwner->GetID(), itr->dwKindValue);
            }
            //CHeroPropMgr::Instance()->GetDT_HERO_BASE_DATA_CLI(stAck.stHeroBaseInfo, stAck.stSkillInfo, itr->dwKindValue);
        }
        else if (ACTE_GOOD == itr->byKindType)
        {
            CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(itr->dwKindValue, itr->byNum, stAck.astItemList[stAck.byItemNum++]);
        }
    }
    return ERR_OPEN_RECHARGE_ENCOURAGE::ID_SUCCESS;
}

UINT16 CActivityEncourage::RecvRechargeEncourage(PKT_CLIGS_RECV_RECHARGE_ENCOURAGE_ACK &stAck)
{
    CBuild* poBuild = m_poOwner->GetBuild(EBK_RECHARGE);
    if(NULL == poBuild)
    {
        return ERR_RECV_RECHARGE_ENCOURAGE::ID_NOT_EXIST_BUILD_ERR;
    }

    if(1 == m_stDT_ACTIVITY_ENCOURAGE_DATA.byRechargeFlag)
    {
        return ERR_RECV_RECHARGE_ENCOURAGE::ID_RECEVED_RECHARGE_ENCOURAGE_ERR;
    }

    if (0 == m_poOwner->GetDT_PLAYER_BASE_DATA().dwTotalAmount)
    {
        return ERR_RECV_RECHARGE_ENCOURAGE::ID_NO_RECHARGE_ENCOURAGE_ERR;
    }

	if ( m_poOwner->CkCarryHeroFull())
	{
		return ERR_RECV_RECHARGE_ENCOURAGE::ID_UPPER_LIMIT_ERR;
	}

    DT_RES_ITEM_DATA stGainResItemData = {0};
    DT_RSYNC_RES_ITEM_DATA stRsyncResItemData = {0};
    DT_RES_NUM_ITEM_DATA stResNumItemData = {0};
    CJsonResItemVectorInfo &vecEncourageItem = CActivityEncourageMgr::Instance()->GetRechargeActivityEncourageItem();
    if(BAG_FULL_ERR == JsonGetResItemVec(vecEncourageItem, m_poOwner, stGainResItemData, stRsyncResItemData, stResNumItemData,CRecordMgr::EAIT_RECHARGE_ENCOURAGE))
    {
        return ERR_RECV_RECHARGE_ENCOURAGE::ID_BAG_FULL_ERR;
    }

    m_stDT_ACTIVITY_ENCOURAGE_DATA.byRechargeFlag = 1;
    m_stDT_ACTIVITY_ENCOURAGE_DATA.qwRechargeRecvTime = SDTimeSecs();
    return ERR_RECV_RECHARGE_ENCOURAGE::ID_SUCCESS;
}

UINT16 CActivityEncourage::OpenScoreEncourage(PKT_CLILS_OPEN_SCORE_ENCOURAGE_ACK &stAck)
{
    CBuild* poBuild = m_poOwner->GetBuild(EBK_SCORE);
    if(NULL == poBuild)
    {
        return ERR_OPEN_SCORE_ENCOURAGE::ID_NOT_EXIST_BUILD_ERR;
    }
    poBuild->OnOpen();

    if(1 == m_stDT_ACTIVITY_ENCOURAGE_DATA.byScoreFlag)
    {
        return ERR_OPEN_SCORE_ENCOURAGE::ID_RECEVED_RECHARGE_ENCOURAGE_ERR;
    }
    stAck.byAppAddNum = strlen(CSinglePramMgr::Instance()->GetAppAddress());
    SDStrcat((CHAR *)stAck.abyAppAddress, CSinglePramMgr::Instance()->GetAppAddress());

    CJsonResItemVectorInfo &vecProp = CActivityEncourageMgr::Instance()->GetScoreActivityEncourageItem();
    CJsonResItemVectorItr itr;
    for (itr = vecProp.vecJsonResItem.begin(); itr != vecProp.vecJsonResItem.end(); itr++)
    {
        CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(itr->dwKindValue, itr->byNum, stAck.astItemList[stAck.byItemNum++]);
    }
    return ERR_OPEN_SCORE_ENCOURAGE::ID_SUCCESS;
}

UINT16 CActivityEncourage::RecvScoreEncourage(PKT_CLIGS_RECV_SCORE_ENCOURAGE_ACK &stAck)
{
    CBuild* poBuild = m_poOwner->GetBuild(EBK_SCORE);
    if(NULL == poBuild)
    {
        return ERR_RECV_SCORE_ENCOURAGE::ID_NOT_EXIST_BUILD_ERR;
    }

    if(1 == m_stDT_ACTIVITY_ENCOURAGE_DATA.byScoreFlag)
    {
        return ERR_RECV_SCORE_ENCOURAGE::ID_RECEVED_RECHARGE_ENCOURAGE_ERR;
    }

    //CJsonResItemVector & vecProp = CActivityEncourageMgr::Instance()->GetScoreActivityEncourageItem();

    //vector<UINT16> vecItemID;
    //CJsonResItemVectorItr itr;
    //for(itr = vecProp.begin(); itr != vecProp.end(); itr++)
    //{
    //    if (ACTE_GOOD == itr->byKindType)
    //    {
    //        vecItemID.push_back(itr->dwKindValue);
    //    }
    //}

    //if(CItemMgr::Instance()->CkBagFull(this, vecItemID))
    //{
    //    return ERR_RECV_SCORE_ENCOURAGE::ID_BAG_FULL_ERR;
    //}

    //ECreateItemRet ItemRet = ECIR_SUCCESS;
    //for (itr = vecProp.begin(); itr != vecProp.end(); itr++)
    //{
    //    ItemRet = ECIR_SUCCESS;
    //    CItem* poItem = CItemMgr::Instance()->CreateItemIntoBag(this, itr->dwKindValue, itr->byNum, ItemRet, 0, CRecordMgr::EAIT_RECHARGE_ENCOURAGE);
    //    if(NULL == poItem)
    //    {
    //        SYS_CRITICAL(_SDT("[%s: %d]: CreateItem failed[%d], ItemKindID=%d !"), MSG_MARK, ItemRet, itr->dwKindValue);
    //    }
    //}
    m_stDT_ACTIVITY_ENCOURAGE_DATA.byScoreFlag = 1;
    m_stDT_ACTIVITY_ENCOURAGE_DATA.qwScoreRecvTime = SDTimeSecs();
    return ERR_RECV_SCORE_ENCOURAGE::ID_SUCCESS;
}

UINT16 CActivityEncourage::GetActivityEncourageInfo(PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK2 &stAck)
{
    CActivityEncouragePropMap &mapActivityEncourageProp = CActivityEncourageMgr::Instance()->GetNorActivityEncouragePropMap();

    CActivityEncouragePropMapItr itr ;
    for (itr = mapActivityEncourageProp.begin(); itr != mapActivityEncourageProp.end(); itr++)
    {
        SActivityEncouragePro &stPro = itr->second;

        //�����Ƿ��Ѿ���¼��û��¼�Ϳ�����ȡ
        if(!CkActivityEncourage(stPro.qwActivityID))
        {
            continue;;
        }

        DT_ACTIVITY_ENCOURAGE_DATA_CLI2 & stActivityEncourageInfo = stAck.astActivityEncourageInfo[stAck.byActivityEncourageNum++];
        stActivityEncourageInfo.qwActivityID = stPro.qwActivityID;
        stActivityEncourageInfo.byCanReceive = 1;
        stActivityEncourageInfo.bySeriesNo = CActivityEncourageMgr::Instance()->IsNeedCdKey(stPro.qwActivityID);
        SDStrcat(stActivityEncourageInfo.aszActivityName, stPro.szActivityName);
        SDStrcat(stActivityEncourageInfo.aszActivityDesc, stPro.szActivityDesc);


        CJsonResItemVectorItr itr;
        for (itr = stPro.vecActivityEncourageItemInfo.vecJsonResItem.begin(); itr != stPro.vecActivityEncourageItemInfo.vecJsonResItem.end(); itr++)
        {
            CJsonResItem &stActivityEncourageItem =  *itr;
            switch (stActivityEncourageItem.byKindType)
            {
            case	ACTE_GOOD://��Ʒ
            {
                DT_ITEM_DATA_CLI2 & astItemInfoList = stActivityEncourageInfo.stEncourageData.astItemInfoList[stActivityEncourageInfo.stEncourageData.byItemNum++];
                CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(stActivityEncourageItem.dwKindValue, stActivityEncourageItem.byNum, astItemInfoList);
            }
            break;
            case	ACTE_HERO://�佫
                break;
            case	ACTE_COIN://ͭǮ
                stActivityEncourageInfo.stEncourageData.dwCoin = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_GOLD://Ԫ��
                stActivityEncourageInfo.stEncourageData.dwGold = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_PHYSTRENGTH://����
                stActivityEncourageInfo.stEncourageData.wPhyStrength = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_SCIENCE://�����
                stActivityEncourageInfo.stEncourageData.dwScience = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_STORY://����
                stActivityEncourageInfo.stEncourageData.dwStory = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_BLUEGAS://����
                stActivityEncourageInfo.stEncourageData.dwBlueGas = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_PRUPLEGAS://����
                stActivityEncourageInfo.stEncourageData.dwPurpleGas = stActivityEncourageItem.dwKindValue;
                break;
            case	ACTE_JINGJIE://����
                stActivityEncourageInfo.stEncourageData.dwJingJie = stActivityEncourageItem.dwKindValue;
                break;
            case ACTE_StudyClip://
                break;
            default:
                break;
            }
        }
    }

	UINT8 byBagOpen = m_poOwner->GetDT_PLAYER_BASE_DATA().byBagOpenNum;
	if ( 0 != byBagOpen)
	{
		SBagProp& stBagProp = CBagPropMgr::Instance()->GetBagProp();
		DT_ACTIVITY_ENCOURAGE_DATA_CLI2 & stActivityEncourageInfo = stAck.astActivityEncourageInfo[stAck.byActivityEncourageNum++];
		stActivityEncourageInfo.qwActivityID = BAG_GIFT_ID;
		stActivityEncourageInfo.byCanReceive = 1;
		stActivityEncourageInfo.bySeriesNo = 0;
		SDStrncpy(stActivityEncourageInfo.aszActivityName, stBagProp.strGiftName.c_str(), MAX_ACTIVITY_ENCOURAGE_NAME_LEN - 1);
		SDStrncpy(stActivityEncourageInfo.aszActivityDesc, stBagProp.strGiftDesc.c_str(), MAX_ACTIVITY_ENCOURAGE_NAME_LEN - 1);

		stActivityEncourageInfo.stEncourageData.dwGold = CBagPropMgr::Instance()->GetEnourageGold(m_poOwner->GetDT_PLAYER_BASE_DATA().byBagOpenNum);
		
	}
    return ERR_GET_ACTIVITY_ENCOURRAGE_INFO::ID_SUCCESS;
}


UINT16 CActivityEncourage::GetActivityEncourageInfo(PKT_CLIGS_GET_ACTIVITY_ENCOURRAGE_INFO_ACK &stAck)
{
	CActivityEncouragePropMap &mapActivityEncourageProp = CActivityEncourageMgr::Instance()->GetNorActivityEncouragePropMap();

	CActivityEncouragePropMapItr itr ;
	for (itr = mapActivityEncourageProp.begin(); itr != mapActivityEncourageProp.end(); itr++)
	{
		SActivityEncouragePro &stPro = itr->second;

		//�����Ƿ��Ѿ���¼��û��¼�Ϳ�����ȡ
		if(!CkActivityEncourage(stPro.qwActivityID))
		{
			continue;;
		}

		DT_ACTIVITY_ENCOURAGE_DATA_CLI & stActivityEncourageInfo = stAck.astActivityEncourageInfo[stAck.byActivityEncourageNum++];
		stActivityEncourageInfo.wActivityID = (UINT16)stPro.qwActivityID;
		stActivityEncourageInfo.byCanReceive = 1;
		stActivityEncourageInfo.bySeriesNo = CActivityEncourageMgr::Instance()->IsNeedCdKey(stPro.qwActivityID);
		SDStrcat(stActivityEncourageInfo.aszActivityName, stPro.szActivityName);
		SDStrcat(stActivityEncourageInfo.aszActivityDesc, stPro.szActivityDesc);


		CJsonResItemVectorItr itr;
		for (itr = stPro.vecActivityEncourageItemInfo.vecJsonResItem.begin(); itr != stPro.vecActivityEncourageItemInfo.vecJsonResItem.end(); itr++)
		{
			CJsonResItem &stActivityEncourageItem =  *itr;
			switch (stActivityEncourageItem.byKindType)
			{
			case	ACTE_GOOD://��Ʒ
				{
					DT_ITEM_DATA_CLI2 & astItemInfoList = stActivityEncourageInfo.stEncourageData.astItemInfoList[stActivityEncourageInfo.stEncourageData.byItemNum++];
					CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(stActivityEncourageItem.dwKindValue, stActivityEncourageItem.byNum, astItemInfoList);
				}
				break;
			case	ACTE_HERO://�佫
				break;
			case	ACTE_COIN://ͭǮ
				stActivityEncourageInfo.stEncourageData.dwCoin = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_GOLD://Ԫ��
				stActivityEncourageInfo.stEncourageData.dwGold = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_PHYSTRENGTH://����
				stActivityEncourageInfo.stEncourageData.wPhyStrength = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_SCIENCE://�����
				stActivityEncourageInfo.stEncourageData.dwScience = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_STORY://����
				stActivityEncourageInfo.stEncourageData.dwStory = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_BLUEGAS://����
				stActivityEncourageInfo.stEncourageData.dwBlueGas = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_PRUPLEGAS://����
				stActivityEncourageInfo.stEncourageData.dwPurpleGas = stActivityEncourageItem.dwKindValue;
				break;
			case	ACTE_JINGJIE://����
				stActivityEncourageInfo.stEncourageData.dwJingJie = stActivityEncourageItem.dwKindValue;
				break;
			case ACTE_StudyClip://
				break;
			default:
				break;
			}
		}
	}

	return ERR_GET_ACTIVITY_ENCOURRAGE_INFO::ID_SUCCESS;
}

UINT8  CActivityEncourage::GetActivityEncourageNum()
{
    UINT8 byActivityEncourageNum = 0;
    CActivityEncouragePropMap &mapActivityEncourageProp = CActivityEncourageMgr::Instance()->GetNorActivityEncouragePropMap();
    for (CActivityEncouragePropMapItr itr = mapActivityEncourageProp.begin(); itr != mapActivityEncourageProp.end(); itr++)
    {
        SActivityEncouragePro &stPro = itr->second;

        //�����Ƿ��Ѿ���¼��û��¼�Ϳ�����ȡ
        if(!CkActivityEncourage(stPro.qwActivityID))
        {
            continue;;
        }
        byActivityEncourageNum++;
    }
	
    m_byLastActivityEncourageNum = byActivityEncourageNum;

    return byActivityEncourageNum;
}


UINT16 CActivityEncourage::RecvActivityEncourage(PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK &stAck, UINT16 wActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM], BOOL bCdKeyValid)
{

	stAck.wActivityIDOld = wActivityID;
	SActivityEncouragePro  * poActivityEncouragePro = CActivityEncourageMgr::Instance()->GetActivityEncouragePro(wActivityID);
	if (NULL == poActivityEncouragePro)
	{
		return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_ACTIVITY_NOT_EXIT;
	}

	//����ȡ������Ϣ
	if (!CkActivityEncourage(wActivityID))
	{
		return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_ENCOURRAGE_RECVD;
	}

	//��ȡ����
	DT_RES_ITEM_DATA stGainResItemData = {0};
	DT_RSYNC_RES_ITEM_DATA stRsyncResItemData = {0};
	DT_RES_NUM_ITEM_DATA stResNumItemData = {0};
	if(BAG_FULL_ERR == JsonGetResItemVec(poActivityEncouragePro->vecActivityEncourageItemInfo, m_poOwner, stGainResItemData, stRsyncResItemData, stResNumItemData, CRecordMgr::EAIT_RECHARGE_ENCOURAGE))
	{
		return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_BAGFUL;
	}

	AddActivityEncourageID(wActivityID);
	return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_SUCCESS;
}

UINT16 CActivityEncourage::RecvActivityEncourage(PKT_CLIGS_RECV_ACTIVITY_ENCOURRAGE_ACK2 &stAck, UINT64 qwActivityID, TCHAR aszSeriesNo[MAX_SERIES_NO_NUM], BOOL bCdKeyValid)
{
	
     stAck.qwActivityID = qwActivityID;
     SActivityEncouragePro  * poActivityEncouragePro = CActivityEncourageMgr::Instance()->GetActivityEncouragePro(qwActivityID);
     if (NULL == poActivityEncouragePro)
     {
         return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_ACTIVITY_NOT_EXIT;
     }
 
     //����ȡ������Ϣ
     if (!CkActivityEncourage(qwActivityID))
     {
         return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_ENCOURRAGE_RECVD;
     }
 
     //��ȡ����
     DT_RES_ITEM_DATA stGainResItemData = {0};
     DT_RSYNC_RES_ITEM_DATA stRsyncResItemData = {0};
     DT_RES_NUM_ITEM_DATA stResNumItemData = {0};
     if(BAG_FULL_ERR == JsonGetResItemVec(poActivityEncouragePro->vecActivityEncourageItemInfo, m_poOwner, stGainResItemData, stRsyncResItemData, stResNumItemData, CRecordMgr::EAIT_RECHARGE_ENCOURAGE))
     {
         return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_BAGFUL;
     }
 
     AddActivityEncourageID(qwActivityID);
     return ERR_RECV_ACTIVITY_ENCOURRAGE::ID_SUCCESS;
}





