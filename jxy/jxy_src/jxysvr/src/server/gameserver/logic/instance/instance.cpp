#include "instance.h"
#include "instancemgr.h"
#include <net/db/dbpktbuilder.h>
#include <db/autosqlbuf.h>
#include <logic/player/player.h>
#include <logic/player/playergetdatamgr.h>
#include <common/client/errdef.h>
#include <logic/monster/monstergroup.h>
#include <logic/monster/monstermgr.h>
#include <logic/other/locale.h>
#include <common/client/errdef.h>
#include <logic/build/build.h>
#include <logic/build/buildmgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/other/phystrengthmgr.h>
#include <logic/other/state.h>
#include <common/server/utility.h>
#include <logic/other/singleprammgr.h>
#include "logic/record/recordmgr.h"
#include "logic/lua/luamgr.h"
#include <logic/score/scorepropmgr.h>
#include <logic/base/basedefine.h>
#include <logic/activityencourage/oprateingactivitymgr.h>
#include <logic/task/taskmgr.h>
#include <logic/item/goods/goodspropmgr.h>
#include <logic/item/itemmgr.h>
#include <logic/instance/instance.h>
#include <logic/bag/bag.h>
#include <logic/score/score.h>
#include <logic/vip/vippropmgr.h>
#include <common/server/ngstring.h>
#include <sdtype.h>
#include "logic/medal/playermedal.h"
#include "logic/battle/battlemgr.h"
#include "logic/instance/instancepropmgr.h"
#include "logic/other/fewparam.h"
IMPLEMENT_CLASS_POOL_MGR(CInstance)


enum RecvRatingType
{
    em_Chaper = 0,		//�½�
    em_Accumulated = 1,	//�ۼƽ���
};


CInstance::CInstance()
{
    memset(&m_stMaxCommonInstanceID, 0, sizeof(DT_INSTANCE_ID));
    memset(&m_stMaxEliteInstanceID, 0, sizeof(DT_INSTANCE_ID));
    memset(&m_stMaxClimbTowerInstanceID, 0, sizeof(DT_INSTANCE_ID));
	memset(&m_stMaxNanDanInstanceID, 0,sizeof(DT_INSTANCE_ID));
    m_stCurBattleInstance.Clear();
    m_mapCommonInstanceRecord.Clear();
    m_mapEliteInstanceRecord.Clear();
    m_mapClimbTowerInstanceRecord.Clear();
    m_byCommonPhyStrength = CPhystrengthMgr::Instance()->GetCommonPhyStrength();

    //��ʼ��Ĭ�Ͽ�����һ����
    m_stMaxClimbTowerInstanceID.wSceneIdx = EIT_TOWER;
    m_stMaxClimbTowerInstanceID.byTownIdx = 1;
    m_stMaxClimbTowerInstanceID.byInstanceIdx = 0;
    STownInstanceProp * pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, 1);
    if (NULL != pstTownInstanceProp)
    {
        m_stMaxClimbTowerInstanceID.byInstanceIdx = 0;
    }
    m_bHaveEnterInstance = FALSE;
}


CInstance::~CInstance()
{
    CInstanceRecord* poInstanceRecord = m_mapCommonInstanceRecord.GetFistData();
    while(poInstanceRecord)
    {
        DT_INSTANCE_ID& stInstanceID = poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID;
        CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);

        poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
    }
    m_mapCommonInstanceRecord.Clear();

    poInstanceRecord = m_mapEliteInstanceRecord.GetFistData();
    while(poInstanceRecord)
    {
        DT_INSTANCE_ID& stInstanceID = poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID;
        CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);

        poInstanceRecord = m_mapEliteInstanceRecord.GetNextData();
    }
    m_mapEliteInstanceRecord.Clear();

    poInstanceRecord = m_mapClimbTowerInstanceRecord.GetFistData();
    while(poInstanceRecord)
    {
        DT_INSTANCE_ID& stInstanceID = poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID;
        CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);

        poInstanceRecord = m_mapClimbTowerInstanceRecord.GetNextData();
    }
    m_mapClimbTowerInstanceRecord.Clear();
}

BOOL CInstance::Init(DT_INSTANCE_DB_DATA &stDT_INSTANCE_DB_DATA, CPlayer* poOwner)
{
    if(NULL == poOwner)
    {
        return FALSE;
    }

    //��ǰ������¼�����ڸ����У���localeλ�ûص�
    m_stCurBattleInstance.Clear();

    m_poOwner = poOwner;

    if(!m_oCommonInstanceBattleRcd.Init(stDT_INSTANCE_DB_DATA.stCommonBattleRcd, m_poOwner))
    {
        return FALSE;
    }

    if(!m_oEliteInstanceBattleRcd.Init(stDT_INSTANCE_DB_DATA.stEliteBattleRcd, m_poOwner))
    {
        return FALSE;
    }

    if(!m_oClimbTowerInstanceBattleRcd.Init(stDT_INSTANCE_DB_DATA.stClimbTowerBattleRcd, m_poOwner))
    {
        return FALSE;
    }

    AddSceneInstanceRecord(EIT_COMMON, stDT_INSTANCE_DB_DATA.stCommonInstanceData);
    AddSceneInstanceRecord(EIT_ELITE, stDT_INSTANCE_DB_DATA.stEliteInstanceData);
    AddSceneInstanceRecord(EIT_TOWER, stDT_INSTANCE_DB_DATA.stClimbTowerInstanceData);
	AddSceneInstanceRecord(EIT_OUT_BOUND, stDT_INSTANCE_DB_DATA.stOutBoundInstanceData);

    return TRUE;
}


//��ȡ�¿ɴ���ͨ����,1��ʾ���µĿɴ򸱱�
UINT8 CInstance::GetNewCommonInstanceID(UINT8 UnlockNewInstanceFlag, DT_INSTANCE_DATA_CLI& stNewCommonInstanceID)
{
    //����δ�����¸���,û���¿ɴ򸱱�
    if(0 == UnlockNewInstanceFlag)
    {
        return 0;
    }

    //DT_INSTANCE_ID stUnlock2ID;
    //GetMaxUnlockCommonInstanceID(stUnlock2ID);
    DT_INSTANCE_ID& stMaxID = GetMaxCommonInstanceID();
    SNextInstance stNextInstance;
    CInstancePropMgr::Instance()->GetNextInstance(stMaxID.wSceneIdx, stMaxID.byTownIdx, stMaxID.byInstanceIdx, stNextInstance);
    if(!stNextInstance.bHaveNext)
    {
        return 0;
    }
    DT_INSTANCE_ID& stNextID = stNextInstance.stDT_INSTANCE_DATA.stInstanceID;

    /*
    //�¸������ս��������ظ��ͻ���
    if((stNextID.wSceneIdx == stUnlock2ID.wSceneIdx) && (stNextID.byTownIdx == stUnlock2ID.byTownIdx) && (stNextID.byInstanceIdx == stUnlock2ID.byInstanceIdx))
    {
    	stNewCommonInstanceID.stInstanceID = stNextID;
    	stNewCommonInstanceID.wEnterLevel = 1;//pstInstanceProp->wEnterLevel;	//ȥ�������ȼ�����
    	memcpy(&(stNewCommonInstanceID.stBurstItemInfo), &(stNextInstance.pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
    	stNewCommonInstanceID.dwBurstExperience = stNextInstance.pstInstanceProp->dwAllExperience;
    	return 1;
    }

    return 0;
    */

    //ֻҪ�н����¸������򷵻���һ���ɴ�
    DT_INSTANCE_ID stMaxUnlockCommonInstanceID;
    m_poOwner->GetMaxUnlockCommonInstanceID(stMaxUnlockCommonInstanceID);//��ȡ����������ĸ���
    if((stNextInstance.bHaveNext) &&
            (TRUE == CInstance::CkLessEqualID(stNextID.byTownIdx, stNextID.byInstanceIdx, stMaxUnlockCommonInstanceID.byTownIdx, stMaxUnlockCommonInstanceID.byInstanceIdx)))
    {
        stNewCommonInstanceID.stInstanceID = stNextID;
        stNewCommonInstanceID.wEnterLevel = 1;//pstInstanceProp->wEnterLevel;	//ȥ�������ȼ�����
        memcpy(&(stNewCommonInstanceID.stBurstItemInfo), &(stNextInstance.pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
        stNewCommonInstanceID.dwBurstExperience = stNextInstance.pstInstanceProp->dwAllExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;
        stNewCommonInstanceID.dwMaxMonstorPower = stNextInstance.pstInstanceProp->dwMaxMonsterPower;
        return 1;
    }

    return 0;
}



VOID CInstance::AddSceneInstanceRecord(UINT16 wScenceIdx, DT_INSTANCE_DATA_LIST& stInstanceData)
{
    if(0 == stInstanceData.wSceneIdx)
    {
        return;
    }

    UINT16 wSize = stInstanceData.wInstanceNum;
    if(0 == wSize)
    {
        return;
    }
    CInstanceRecordShmemMap* pmapCommonInstanceRecord = NULL;
    if(EIT_COMMON == wScenceIdx)
    {
        pmapCommonInstanceRecord = &m_mapCommonInstanceRecord;
    }
    else if(EIT_ELITE == wScenceIdx)
    {
        pmapCommonInstanceRecord = &m_mapEliteInstanceRecord;
    }
    else if (EIT_TOWER == wScenceIdx)
    {
        pmapCommonInstanceRecord = &m_mapClimbTowerInstanceRecord;
    }
	else if ( EIT_OUT_BOUND == wScenceIdx )
	{
		pmapCommonInstanceRecord = &m_mapOutBoundRecord;
	}
	else
	{
		return;
	}

    UINT32 dwPlayerID = m_poOwner->GetDT_PLAYER_BASE_DATA().dwID;
    for(UINT16 wIdx = 0; wIdx < wSize && wIdx < MAX_INSTANCE_PER_SCENE_NUM; wIdx++)
    {
        DT_INSTANCE_DATA& stDT_INSTANCE_DATA = stInstanceData.astInstanceInfo[wIdx];
        DT_INSTANCE_ID& stInstanceID = stDT_INSTANCE_DATA.stInstanceID;
        if(pmapCommonInstanceRecord->GetData(CLogicFunc::GetInstanceIdxKey(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx)))
        {
            continue;
        }

        CInstanceRecord* poInstanceRecord = NULL;
        poInstanceRecord = CInstanceMgr::Instance()->CreatInstanceRecord(dwPlayerID, stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
        if(NULL == poInstanceRecord)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: create InstanceRecord failed!"), MSG_MARK);
            continue;
        }

        if(FALSE == poInstanceRecord->Init(&stDT_INSTANCE_DATA, m_poOwner))
        {
            SYS_CRITICAL(_SDT("[%s: %d]: InstanceRecord init failed, playerID = %u!"), MSG_MARK, m_poOwner->GetID());
            CInstanceMgr::Instance()->RemoveInsanceRecord(dwPlayerID, stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
            continue;
        }

        //��ֵ��󸱱���¼
        if((stDT_INSTANCE_DATA.dwSuccessNum > 0) &&
                (((EIT_COMMON == stInstanceID.wSceneIdx) && (stInstanceID.byTownIdx > m_stMaxCommonInstanceID.byTownIdx)) ||
                 ((EIT_COMMON == stInstanceID.wSceneIdx) && (stInstanceID.byTownIdx == m_stMaxCommonInstanceID.byTownIdx) && (stInstanceID.byInstanceIdx > m_stMaxCommonInstanceID.byInstanceIdx))))
        {
            memcpy(&m_stMaxCommonInstanceID, &stInstanceID, sizeof(stInstanceID));
        }

        //��ֵ��󸱱���¼
        if((stDT_INSTANCE_DATA.dwSuccessNum > 0) &&
                (((EIT_ELITE == stInstanceID.wSceneIdx) && (stInstanceID.byTownIdx > m_stMaxEliteInstanceID.byTownIdx)) ||
                 ((EIT_ELITE == stInstanceID.wSceneIdx) && (stInstanceID.byTownIdx == m_stMaxEliteInstanceID.byTownIdx) && (stInstanceID.byInstanceIdx > m_stMaxEliteInstanceID.byInstanceIdx))))
        {
            memcpy(&m_stMaxEliteInstanceID, &stInstanceID, sizeof(stInstanceID));
        }

        if((stDT_INSTANCE_DATA.dwSuccessNum > 0) &&
                (((EIT_TOWER == stInstanceID.wSceneIdx) && (stInstanceID.byTownIdx > m_stMaxClimbTowerInstanceID.byTownIdx)) ||
                 ((EIT_TOWER == stInstanceID.wSceneIdx) && (stInstanceID.byTownIdx == m_stMaxClimbTowerInstanceID.byTownIdx) && (stInstanceID.byInstanceIdx > m_stMaxClimbTowerInstanceID.byInstanceIdx))))
        {
            memcpy(&m_stMaxClimbTowerInstanceID, &stInstanceID, sizeof(stInstanceID));
        }

        pmapCommonInstanceRecord->AddData(CLogicFunc::GetInstanceIdxKey(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx), poInstanceRecord);
    }
}

VOID CInstance::GiveFirstInsance(PKT_CLIGS_GET_SCENE_INSTANCE_ACK& stAck)
{
    //1-1-1����
    stAck.wIndex = 1;
    stAck.byTownNum = 1;
    stAck.astTownInstanceInfo[0].byIndex = 1;
    stAck.astTownInstanceInfo[0].byInstanceNum = 1;
    DT_INSTANCE_RECORD_DATA_CLI& stDT_INSTANCE_RECORD_DATA_CLI = stAck.astTownInstanceInfo[0].astInstanceInfo[0];
    stDT_INSTANCE_RECORD_DATA_CLI.byIndex = 1;
    stDT_INSTANCE_RECORD_DATA_CLI.byScore = 0;

    SInstanceProp* pstInstanceProp = NULL;
    pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(1, 1, 1);
    //�쳣
    if(NULL == pstInstanceProp)
    {
        SET_OTHER_ERR(stAck.wErrCode)
        SYS_CRITICAL(_SDT("[%s: %d]: CInstance::GetInstanceRecord pstInstanceProp is NULL!"), MSG_MARK);
    }
    else
    {
        stDT_INSTANCE_RECORD_DATA_CLI.wEnterLevel = 1;//pstInstanceProp->wEnterLevel;	//ȥ�������ȼ�����
        memcpy(&(stDT_INSTANCE_RECORD_DATA_CLI.stBurstItemInfo), &(pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
        stDT_INSTANCE_RECORD_DATA_CLI.dwBurstExperience = pstInstanceProp->dwAllExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;
    }
}

BOOL CInstance::GetInstanceRecord(UINT16 wSceneIdx, PKT_CLIGS_GET_SCENE_INSTANCE_ACK& stAck)
{
    stAck.wErrCode = ERR_GET_SCENEINSTANCE::ID_SUCCESS;
    SDStrncpy(stAck.aszContent, CSinglePramMgr::Instance()->GetScienceDspContent(), MAX_CONTENT_SIZE - 1);
    if(wSceneIdx == EIT_COMMON)
    {
        if(!GetCommonInstanceRecord(stAck))
        {
            return FALSE;
        }
    }
    else
    {
        stAck.wErrCode = ERR_GET_SCENEINSTANCE::ID_SCENE_NOT_EXIST_ERR;
        return FALSE;
    }

    return TRUE;
}

UINT16  CInstance::GetOutBoundInfo(PKT_CLIGS_OPEN_OUT_BOUND_ACK& stAck)
{
	//��Դ��Ϣ
	UINT8 byResNum = 0;
	stAck.stResInfo.astPlayerRes[byResNum].byResKind = ACTE_COIN;
	stAck.stResInfo.astPlayerRes[byResNum].qwResValue = m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin;
	byResNum++;
	stAck.stResInfo.astPlayerRes[byResNum].byResKind = ACTE_GOLD;
	stAck.stResInfo.astPlayerRes[byResNum].qwResValue = m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;
	byResNum++;
	stAck.stResInfo.astPlayerRes[byResNum].byResKind = ACTE_PHYSTRENGTH;
	stAck.stResInfo.astPlayerRes[byResNum].qwResValue = m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength;
	byResNum++;
	stAck.stResInfo.byResNum = byResNum;
	//�⴫��Ϣ
	UINT8 byOutBoundNum = 0;
	//����⴫����
	UINT8 byMaxOutBoundNum = CInstancePropMgr::Instance()->GetMaxOutBoundTownIdx();
	//������ʾ�⴫����
	UINT8 byMinOutBoundNum = CSinglePramMgr::Instance()->GetMinDisPlayerOutBoundNum();
	byMinOutBoundNum = byMaxOutBoundNum < byMinOutBoundNum ? byMaxOutBoundNum : byMinOutBoundNum;
	BOOL bSuccess = TRUE;
	CIndex2SceneTownPropMap& mapAllScene = CInstancePropMgr::Instance()->GetAllSceneInstance();
	CIndex2SceneTownPropMapItr sceneItr = mapAllScene.find(EIT_OUT_BOUND);
	if ( sceneItr != mapAllScene.end())
	{
		UINT8 byOutBoundNum = 0;
		for ( CIndex2TownInstancePropMapItr townItr = sceneItr->second->m_mapTownInstance.begin(); townItr != sceneItr->second->m_mapTownInstance.end(); townItr++, byOutBoundNum++)
		{
			SInstanceProp* poProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_OUT_BOUND, townItr->second->byTownIndex, 1);
			if ( NULL == poProp)
			{
				break;
			}

			CInstanceRecord* poData = GetSingleInstaceRecord(EIT_OUT_BOUND, townItr->second->byTownIndex, 1);
			stAck.astOutBoundInfo[byOutBoundNum].wScenceIdx = EIT_OUT_BOUND;
			stAck.astOutBoundInfo[byOutBoundNum].byTownIdx = townItr->second->byTownIndex;
			SDStrncpy( stAck.astOutBoundInfo[byOutBoundNum].aszHeroDesc, poProp->strHeroDesc.c_str(), MAX_OUT_BOUND_DESC_LEN - 1);
			SDStrncpy( stAck.astOutBoundInfo[byOutBoundNum].aszItemDesc, poProp->strItemDesc.c_str(), MAX_OUT_BOUND_DESC_LEN - 1);
			//��ͨ�أ����⴫�ѿ���
			if ( NULL != poData)
			{
				//�������ѿ�����δȫ��ͨ��
				stAck.astOutBoundInfo[byOutBoundNum].byState = 0;
				UINT8 byMaxInstanceIdx = CInstancePropMgr::Instance()->GetMaxOutBoundInstanceIdx(townItr->second->byTownIndex);
				poData = GetSingleInstaceRecord( EIT_OUT_BOUND, townItr->second->byTownIndex, byMaxInstanceIdx);
				if ( NULL != poData)
				{
					//ȫ��ͨ��
					stAck.astOutBoundInfo[byOutBoundNum].byState = 3;
				}
			}
			//δͨ������
			else
			{
				//���ת���ȼ��Ƿ�����
				if (m_poOwner->GetLevel() >= poProp->wEnterLevel)
				{
					poData = GetSingleInstaceRecord(EIT_OUT_BOUND, poProp->stParentInstance.byTownIdx, poProp->stParentInstance.byInstanceIdx);
					if ( (NULL == poData) &&  (0 != poProp->stParentInstance.byTownIdx) && (0 != poProp->stParentInstance.byInstanceIdx) )
					{
						//δ����
						stAck.astOutBoundInfo[byOutBoundNum].byState = 1;
						SDStrncpy(stAck.astOutBoundInfo[byOutBoundNum].aszUnlockReq, poProp->strParentReqDesc.c_str(), NORMAL_MSG_LEN - 1);
					}
					else
					{
						//�����ѿ���
						stAck.astOutBoundInfo[byOutBoundNum].byState = 0;
					}
				}
				else
				{
					//δ����
					stAck.astOutBoundInfo[byOutBoundNum].byState = 2;
					SDStrncpy(stAck.astOutBoundInfo[byOutBoundNum].aszUnlockReq, poProp->strLeveReqDesc.c_str(), MAX_OUT_BOUND_DESC_LEN - 1);
					//�������������⴫��ʾʱ��break
					if ( byOutBoundNum + 1 > byMinOutBoundNum)
					{
						break;
					}
				}
			}
		}
		stAck.byOutBoundNum = byOutBoundNum;
	}
	return ERR_OPEN_OUT_BOUND::ID_SUCCESS;
}

UINT16  CInstance::OnOpenOutBoundMapAck(PKT_CLIGS_OPEN_OUT_BOUND_MAP_REQ& stReq, PKT_CLIGS_OPEN_OUT_BOUND_MAP_ACK& stAck)
{
	//����Ƿ��ܽ���
	UINT16 wRet = CkCanEnter( EIT_OUT_BOUND, stReq.byTownIdx, 1, FALSE );
	
	if( ERR_ENTER_INSTANCE::ID_NOT_REFREASH == wRet)
	{
		return ERR_OPEN_OUT_BOUND_MAP::ID_NOT_FRESH;
	}
	else if(ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_ERR == wRet || ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_LEVEL_ERR == wRet)
	{
		return ERR_OPEN_OUT_BOUND_MAP::ID_NOT_OPEN;
	}

	GetDetailOutBound(stReq.byTownIdx, stAck.stInstanceLstInfo);
	
	return ERR_OPEN_OUT_BOUND_MAP::ID_SUCCESS;
}

UINT16 CInstance::OnOutBoundBattleAck(PKT_CLIGS_OUT_BOUND_BATTLE_REQ& stReq, PKT_CLIGS_OUT_BOUND_BATTLE_ACK& stAck)
{
	if ( EIT_OUT_BOUND != stReq.stInstanceID.wSceneIdx)
	{
		return ERR_OUT_BOUND_BATTLE::ID_NOT_EXIST;
	}
	//��⸱���Ƿ����
	SInstanceProp* poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx);
	if ( NULL == poInstanceProp)
	{
		return ERR_OUT_BOUND_BATTLE::ID_NOT_EXIST;
	}
	//���ȼ��Ƿ�����
	if ( m_poOwner->GetLevel() < poInstanceProp->wEnterLevel )
	{
		return ERR_OUT_BOUND_BATTLE::ID_LEVEL_NOT_ENOUGH;
	}
	//��⸱���Ƿ�ɴ�
	CInstanceRecord* poCurRecord = GetSingleInstaceRecord(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx);
	if ( NULL == poCurRecord)
	{
		//û�и�����
		if ( !( 0 == poInstanceProp->stParentInstance.wSceneIdx && 0 == poInstanceProp->stParentInstance.byTownIdx && 0 == poInstanceProp->stParentInstance.byInstanceIdx) )
		{
			CInstanceRecord* poParentRecord = GetSingleInstaceRecord(poInstanceProp->stParentInstance.wSceneIdx, poInstanceProp->stParentInstance.byTownIdx, poInstanceProp->stParentInstance.byInstanceIdx);
			if ( NULL == poParentRecord)
			{
				return ERR_OUT_BOUND_BATTLE::ID_NOT_OPEN;
			}
		}
		//ûͨ�ع����޷��һ�
		if ( 0 != stReq.byIsHook )
		{
			return ERR_OUT_BOUND_BATTLE::ID_HOOK_ERR;
		}
	}
	else
	{
		if( poInstanceProp->byBattleNum <= poCurRecord->GetDT_INSTANCE_DATA().dwSuccessNum )
		{
			ERR_OUT_BOUND_BATTLE::ID_NOT_BATTLE_NUM;
		}
	}
	stAck.stPowerInfo.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
	//��������Ƿ����
	//�Ȼظ�����(����������������󴥷����Ƕ�ʱ�������ȳ��Իظ�����)
	m_poOwner->GetPhystrength().PhyStrengthRecover();//
	//�����ж�
	UINT16 wCostPhyStrenth = CPhystrengthMgr::Instance()->GetCommonPhyStrength();
	if(m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength < wCostPhyStrenth)
	{
		return ERR_OUT_BOUND_BATTLE::ID_NOT_PHYSICAL;
	}
	//��ⱳ���Ƿ��㹻�ռ�
	CBag& oBag = m_poOwner->GetBag();
	if( 0 == oBag.GetIdleSize())
	{
		return ERR_OUT_BOUND_BATTLE::ID_BAG_IS_FULL;
	}
	CMonsterGroup* poMonsterGroup = CMonsterMgr::Instance()->FindMonsterGroup(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx, 1);
	if(NULL == poMonsterGroup)
	{
		return ERR_OUT_BOUND_BATTLE::ID_CONFIG_ERR;
	}
	m_poOwner->EnterInstance(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx);
	//���õ�ǰ����ͨ��״̬
	m_stCurBattleInstance.bPass = FALSE;
	//ս��
	BOOL bInstancePass = FALSE;
	if ( 0 == stReq.byIsHook )
	{
		CBattleMgr::Instance()->Battle4(m_poOwner, poMonsterGroup, stAck.astBattleInfo[0]);
		stAck.byHaveBattleInfo = 1;
		bInstancePass = (0 == stAck.astBattleInfo[0].byBattleResult);
	}
	else
	{
		bInstancePass = TRUE;
	}
	if ( bInstancePass )
	{
		stAck.astBattleInfo[0].byBattleResult = 2;
	}
	else 
	{
		stAck.astBattleInfo[0].byBattleResult = 1;
	}
	//�۳�����
	m_poOwner->DecPhyStrength( wCostPhyStrenth, CRecordMgr::EDPST_OUT_BOUND, stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx);

	//�Ƿ�ͨ��
	if(bInstancePass)
	{
		//��ʼս�� ��ͬʱ�����ȡ�Ľ�����
		m_poOwner->GetInstance().BattlePass(poMonsterGroup, 1);
		//��ȡ������Ϣ
		m_poOwner->GetBattleEncourage(stAck.stBattleEncourage, &stAck.stAfterBattleEncourage);
		stAck.byPassFlag = ESM_YES;
		//��¼ͨ�ظ���
		CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx, FALSE);
		//û�м�¼��ͨ��Ӯ�ļ�¼
		if((NULL == poInstanceRecord) )
		{
			poInstanceRecord = CInstanceMgr::Instance()->CreatInstanceRecord(m_poOwner->GetID(), stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx);
			if(NULL == poInstanceRecord)
			{
				return ERR_OUT_BOUND_BATTLE::ID_NOT_OPEN;
			}

			DT_INSTANCE_DATA stDT_INSTANCE_DATA = {0};
			stDT_INSTANCE_DATA.stInstanceID.wSceneIdx = stReq.stInstanceID.wSceneIdx;
			stDT_INSTANCE_DATA.stInstanceID.byTownIdx = stReq.stInstanceID.byTownIdx;
			stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx = stReq.stInstanceID.byInstanceIdx;
			stDT_INSTANCE_DATA.byScore = 0;
			stDT_INSTANCE_DATA.qwLastPassTime = SDTimeSecs();
			stDT_INSTANCE_DATA.dwSuccessNum = 1;
			if(FALSE == poInstanceRecord->Init(&stDT_INSTANCE_DATA, m_poOwner))
			{
				SYS_CRITICAL(_SDT("[%s: %d]:  InstanceRecord init failed!"), MSG_MARK);
				CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx);
				return ERR_OUT_BOUND_BATTLE::ID_NOT_OPEN;
			}

			DT_UNLOCK_DATA stUnlockInfo;
			//����
			DoUnlock(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx, stUnlockInfo.byUnlockBuildKindID, stUnlockInfo.awUnlockHeroID);
			
			m_mapOutBoundRecord.AddData(CLogicFunc::GetInstanceIdxKey(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx), poInstanceRecord);
		}
		else
		{
			poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime = SDTimeSecs();
			poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum++;
			poInstanceRecord->GetDT_INSTANCE_DATA().wLastConFailedNum = 0;
		}

 		//��ȡͨ�ؽ���
 		m_poOwner->GetInstance().PassEncourage(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx, 1, &stAck.astPassEncourage[0], &stAck.astAfterPassEncourage[0]);
 		//�򿪱���
 		m_poOwner->GetInstance().RatePassBoxEnc(stReq.stInstanceID.wSceneIdx, stReq.stInstanceID.byTownIdx, stReq.stInstanceID.byInstanceIdx, stAck.astPassEncourageBox[0]);
		
		if ( ESM_YES == stReq.byIsHook )
		{
			DT_PASS_ENCOURAGE_BOX_DATA stPassBox;
			m_poOwner->GetInstance().OpenEncourageBox( stPassBox, NULL);
			m_poOwner->ExitInstance();
		}
	}
	else
	{
		m_poOwner->ExitInstance();
	}
	
	//ͬ������
	GetDetailOutBound(stReq.stInstanceID.byTownIdx, stAck.stInstanceLstInfo);
	//��Դ��Ϣ
	UINT8 byResNum = 0;
	stAck.stResInfo.astPlayerRes[byResNum].byResKind = ACTE_COIN;
	stAck.stResInfo.astPlayerRes[byResNum].qwResValue = m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin;
	byResNum++;
	stAck.stResInfo.astPlayerRes[byResNum].byResKind = ACTE_GOLD;
	stAck.stResInfo.astPlayerRes[byResNum].qwResValue = m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;
	byResNum++;
	stAck.stResInfo.astPlayerRes[byResNum].byResKind = ACTE_PHYSTRENGTH;
	stAck.stResInfo.astPlayerRes[byResNum].qwResValue = m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength;
	byResNum++;
	stAck.stResInfo.byResNum = byResNum;
	stAck.stPowerInfo.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
	return ERR_OUT_BOUND_BATTLE::ID_SUCCESS;
}

UINT16  CInstance::GetDetailOutBound(UINT8 byTownIdx, DT_OUT_BOUND_DETAIL_LST_DATA& stInstanceLstInfo)
{
	//��ֵ�⴫��Ϣ
	STownInstanceProp* poTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_OUT_BOUND, byTownIdx);
	if ( NULL == poTownInstanceProp)
	{
		return ERR_OPEN_OUT_BOUND_MAP::ID_NOT_EXIST;
	}
	UINT8 byInstanceNum = 0;
	BOOL bChangeInstance = FALSE;
	for ( CIndex2InstancePropMapItr itr = poTownInstanceProp->m_mapInstance.begin(); itr != poTownInstanceProp->m_mapInstance.end(); itr++, byInstanceNum++)
	{
		//����ID
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stInstanceID.wSceneIdx = EIT_OUT_BOUND;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stInstanceID.byTownIdx = byTownIdx;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stInstanceID.byInstanceIdx = itr->second->byIndex;
		
		//��������
		SDStrncpy(stInstanceLstInfo.astInstanceInfo[byInstanceNum].aszInstanceName, itr->second->strInstanceDesc.c_str(), NORMAL_MSG_LEN - 1);

		CInstanceRecord* poData = GetSingleInstaceRecord(EIT_OUT_BOUND, byTownIdx, itr->second->byIndex);
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].wLevelReq = itr->second->wEnterLevel;
		//ʣ�����
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].byLeftCrossNum = itr->second->byBattleNum;
		//δͨ�ع�
		if ( NULL == poData)
		{
			//���ȼ��Ƿ�
			if ( m_poOwner->GetLevel() < itr->second->wEnterLevel)
			{
				stInstanceLstInfo.astInstanceInfo[byInstanceNum].byState = 2;
			}
			else if ( (NULL == GetSingleInstaceRecord( itr->second->stParentInstance.wSceneIdx, itr->second->stParentInstance.byTownIdx, itr->second->stParentInstance.byInstanceIdx))
				&& ( 0 != itr->second->stParentInstance.wSceneIdx && 0 != itr->second->stParentInstance.byTownIdx && 0 != itr->second->stParentInstance.byInstanceIdx))
			{
				//��⸸�����Ƿ�ͨ��
				stInstanceLstInfo.astInstanceInfo[byInstanceNum].byState = 3;
			}
			else
			{
				if ( !bChangeInstance)
				{
					stInstanceLstInfo.bySelectIdx = itr->second->byIndex;
					bChangeInstance = TRUE;
				}
				stInstanceLstInfo.astInstanceInfo[byInstanceNum].byState = 0;
			}
		}
		//��ͨ�ع�
		else
		{
			stInstanceLstInfo.bySelectIdx = itr->second->byIndex;
			//�ɹһ�
			stInstanceLstInfo.astInstanceInfo[byInstanceNum].byState = 1;
			stInstanceLstInfo.astInstanceInfo[byInstanceNum].byLeftCrossNum = itr->second->byBattleNum < static_cast<UINT8>(poData->GetDT_INSTANCE_DATA().dwSuccessNum) ? 0 : itr->second->byBattleNum - static_cast<UINT8>(poData->GetDT_INSTANCE_DATA().dwSuccessNum);
		}
		//��
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].byIsMajor = itr->second->bIsMajor;
		//ʤ�����
		UINT8 byResNum = 0;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.astPlayerRes[byResNum].byResKind = ACTE_HERO_EXP;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.astPlayerRes[byResNum].qwResValue = itr->second->stOutBoundEncourage.dwExperience;
		byResNum++;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.astPlayerRes[byResNum].byResKind = ACTE_COIN;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.astPlayerRes[byResNum].qwResValue =  itr->second->stOutBoundEncourage.dwCoin;
		byResNum++;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.astPlayerRes[byResNum].byResKind = ACTE_STORY;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.astPlayerRes[byResNum].qwResValue =  itr->second->stOutBoundEncourage.dwStory;
		byResNum++;
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stResInfo.byResNum = byResNum;

		UINT8 byItemNum = 0;
		
		for ( C32VecItr vecItr = itr->second->vecDisplayItem.begin(); vecItr != itr->second->vecDisplayItem.end(); vecItr++, byItemNum++)
		{
			CItemMgr::Instance()->GetDT_ITEM_DATA_CLI3(*vecItr, 1, stInstanceLstInfo.astInstanceInfo[byInstanceNum].stItemInfo.astItemList[byItemNum]);
		}
		stInstanceLstInfo.astInstanceInfo[byInstanceNum].stItemInfo.byItemNum = byItemNum;
		
	}

	stInstanceLstInfo.byInstanceNum = byInstanceNum;
	return ERR_OPEN_OUT_BOUND_MAP::ID_SUCCESS;
}

VOID CInstance::ExitInstanceWhenPass(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byScore)
{
    if(NULL == m_poOwner)
    {
        return;
    }
    //���Ҽ�¼�����Ƿ��м�¼
    CInstanceRecord* poInstanceRecord = NULL;
    poInstanceRecord = GetSingleInstaceRecord(wSceneIdx, byTownIdx, byInstanceIdx, FALSE);
    //û�м�¼��ͨ��Ӯ�ļ�¼
    if((NULL == poInstanceRecord) || (0 == poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum))
    {
        if(NULL == poInstanceRecord)
        {
            poInstanceRecord = CInstanceMgr::Instance()->CreatInstanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, wSceneIdx, byTownIdx, byInstanceIdx);
            if(NULL == poInstanceRecord)
            {
                return;
            }

            DT_INSTANCE_DATA stDT_INSTANCE_DATA = {0};
            stDT_INSTANCE_DATA.stInstanceID.wSceneIdx = wSceneIdx;
            stDT_INSTANCE_DATA.stInstanceID.byTownIdx = byTownIdx;
            stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx = byInstanceIdx;
            stDT_INSTANCE_DATA.byScore = byScore;
            stDT_INSTANCE_DATA.qwLastPassTime = SDTimeSecs();
            stDT_INSTANCE_DATA.dwSuccessNum = 1;
            if(FALSE == poInstanceRecord->Init(&stDT_INSTANCE_DATA, m_poOwner))
            {
                SYS_CRITICAL(_SDT("[%s: %d]:  InstanceRecord init failed!"), MSG_MARK);
                CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, wSceneIdx, byTownIdx, byInstanceIdx);
                return;
            }
        }
        else
        {
            DT_INSTANCE_DATA& stDT_INSTANCE_DATA = poInstanceRecord->GetDT_INSTANCE_DATA();
            stDT_INSTANCE_DATA.dwSuccessNum++;
            stDT_INSTANCE_DATA.byScore = byScore;
            stDT_INSTANCE_DATA.qwLastPassTime = SDTimeSecs();
            stDT_INSTANCE_DATA.wLastConFailedNum = 0;
            if(byScore > stDT_INSTANCE_DATA.byScore)
            {
                stDT_INSTANCE_DATA.byScore = byScore;
            }
        }


        if(EIT_COMMON == wSceneIdx)
        {
            m_mapCommonInstanceRecord.AddData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx), poInstanceRecord);
        }
        else if(EIT_ELITE == wSceneIdx)
        {
            m_mapEliteInstanceRecord.AddData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx), poInstanceRecord);
        }
        else if(EIT_TOWER == wSceneIdx)
        {
            m_mapClimbTowerInstanceRecord.AddData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx), poInstanceRecord);
        }
		/*else if ( EIT_OUT_BOUND == wSceneIdx)
		{
			m_mapOutBoundRecord.AddData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx), poInstanceRecord);
		}*/
    }
    else
    {
        poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime = SDTimeSecs();
        poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum++;
        poInstanceRecord->GetDT_INSTANCE_DATA().wLastConFailedNum = 0;
        if(byScore > poInstanceRecord->GetDT_INSTANCE_DATA().byScore)
        {
            poInstanceRecord->GetDT_INSTANCE_DATA().byScore = byScore;
        }
    }

    //����ص�
    CTaskMgr::Instance()->CkWantCheckAccept(m_poOwner);
    CTaskMgr::Instance()->OnPassInstance(m_poOwner, wSceneIdx, byTownIdx, byInstanceIdx);
    if(EIT_ELITE == wSceneIdx)
    {
        CTaskMgr::Instance()->OnEliteInstance(m_poOwner, m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx);
    }
    else if (EIT_TOWER == wSceneIdx)
    {
        CTaskMgr::Instance()->OnClimbTower(m_poOwner);
    }
}


UINT16 CInstance::CkCanEnter(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byNewFlag)
{
    //�����Ƿ���ڸø�������
    SInstanceProp* poInstanceProp = NULL;
    poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(wSceneIdx, byTownIdx, byInstanceIdx);
    if(NULL == poInstanceProp)
    {
        return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
    }

    SNextInstance stNextInstance;
    if(EIT_COMMON == wSceneIdx)
    {
        CInstancePropMgr::Instance()->GetNextInstance(EIT_COMMON, m_stMaxCommonInstanceID.byTownIdx, m_stMaxCommonInstanceID.byInstanceIdx, stNextInstance);
        DT_INSTANCE_ID* pstInstanceID = &m_stMaxCommonInstanceID;
        if(stNextInstance.bHaveNext)
        {
            //�ж��Ƿ�С�ڵ�ǰ������һ������
            pstInstanceID = &(stNextInstance.stDT_INSTANCE_DATA.stInstanceID);
        }
        if((byTownIdx > pstInstanceID->byTownIdx) || ((byTownIdx == pstInstanceID->byTownIdx) && (byInstanceIdx > pstInstanceID->byInstanceIdx)))
        {
            return ERR_ENTER_INSTANCE::ID_INDEX_ERR;

        }

        return ERR_ENTER_INSTANCE::ID_SUCCESS;
    }
    else if(EIT_ELITE == wSceneIdx)
    {
        if(NULL == m_poOwner->GetBuild(EBK_ELITEINSTANCE))
        {
            return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
        }

        //�ж��Ƿ�˳���
        SNextInstance stNextInstance;
        CInstancePropMgr::Instance()->GetNextInstance(EIT_ELITE, m_stMaxEliteInstanceID.byTownIdx, m_stMaxEliteInstanceID.byInstanceIdx, stNextInstance);
        DT_INSTANCE_ID* pstInstanceID = &m_stMaxEliteInstanceID;
        if(stNextInstance.bHaveNext)
        {
            //�ж��Ƿ�С�ڵ�ǰ������һ������
            pstInstanceID = &(stNextInstance.stDT_INSTANCE_DATA.stInstanceID);
        }
        //��������ǰ��ĸ�����
        if(byTownIdx > pstInstanceID->byTownIdx)
        {
            return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
        }

        //�ж��Ƿ����
        if(!CkEliteUnlock(byTownIdx, byInstanceIdx))
        {
            return ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_ERR;
        }

        //�¿�����
        if(!byNewFlag)
        {
            return ERR_ENTER_INSTANCE::ID_SUCCESS;
        }

        //�жϽ����Ƿ��Ѿ�ͨ�ع�
        CInstanceRecord* pstInstanceRecord = GetSingleInstaceRecord(wSceneIdx, byTownIdx, byInstanceIdx);
        if((pstInstanceRecord) && (IsToday(pstInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime)))
        {
            //�����Ѿ�ͨ�ع�
            return ERR_ENTER_INSTANCE::ID_ELITE_ONLY_ONE_PER_DAY_ERR;
        }

        return ERR_ENTER_INSTANCE::ID_SUCCESS;
    }
    else if(EIT_TOWER == wSceneIdx)
    {
        if(NULL == m_poOwner->GetBuild(EBK_CLIMBTOWER))
        {
            return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
        }

        //�ж��Ƿ�˳���
        SNextInstance stNextInstance;
        CInstancePropMgr::Instance()->GetNextInstance(EIT_TOWER, m_stMaxClimbTowerInstanceID.byTownIdx, m_stMaxClimbTowerInstanceID.byInstanceIdx, stNextInstance);
        DT_INSTANCE_ID* pstInstanceID = &m_stMaxClimbTowerInstanceID;
        if(stNextInstance.bHaveNext)
        {
            //�ж��Ƿ�С�ڵ�ǰ������һ������
            pstInstanceID = &(stNextInstance.stDT_INSTANCE_DATA.stInstanceID);
        }
        //��������ǰ��ĸ�����
        if((byTownIdx > pstInstanceID->byTownIdx) || ((byTownIdx == pstInstanceID->byTownIdx) && (byInstanceIdx > pstInstanceID->byInstanceIdx)))
        {
            return ERR_ENTER_INSTANCE::ID_INDEX_ERR;

        }

        //�ȼ����ơ�
        if (m_poOwner->GetLevel() < poInstanceProp->wEnterLevel)
        {
            return ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_LEVEL_ERR;
        }



        //�¿�����
        if(!byNewFlag)
        {
            return ERR_ENTER_INSTANCE::ID_SUCCESS;
        }

        ////�жϽ����Ƿ���ͨ���ĸ���
        CInstanceRecord* pstInstanceRecord = NULL;
        pstInstanceRecord = GetSingleInstaceRecord(wSceneIdx, byTownIdx, byInstanceIdx);
        if((pstInstanceRecord) && (IsToday(pstInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime)))
        {
            //�����Ѿ�ͨ�ع�
            return ERR_ENTER_INSTANCE::ID_CLIMBTOWER_ONLY_ONE_PER_DAY_ERR;
        }
        return ERR_ENTER_INSTANCE::ID_SUCCESS;
    }
	else if (EIT_OUT_BOUND == wSceneIdx)//����Э��
	{
		//�Ƿ�ת��
		if ( !m_poOwner->IsFly() )
		{
			return ERR_ENTER_INSTANCE::ID_NOT_REFREASH;
		}


		CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(EIT_OUT_BOUND, byTownIdx, byInstanceIdx);
		if ( NULL == poInstanceRecord)
		{
			//����ת���ȼ��Ƿ�����Ҫ��
			if ( m_poOwner->GetLevel() < poInstanceProp->wEnterLevel )
			{
				return ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_LEVEL_ERR;
			}

			//���ڵ��Ƿ�ͨ��
			if ( !((NULL != GetSingleInstaceRecord(EIT_OUT_BOUND, poInstanceProp->stParentInstance.byTownIdx, poInstanceProp->stParentInstance.byInstanceIdx)) 
				|| (0 == poInstanceProp->stParentInstance.wSceneIdx && 0 == poInstanceProp->stParentInstance.byTownIdx && 0 == poInstanceProp->stParentInstance.byInstanceIdx)))
			{
				return ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_ERR;
			}
		}
		else
		{
			if ( poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum >= poInstanceProp->byBattleNum )
			{
				return ERR_ENTER_INSTANCE::ID_NOT_TIMES_OUT_BOUND;
			}
		}
		
		return ERR_ENTER_INSTANCE::ID_SUCCESS;
	}
	else if ( EIT_NEIDAN == wSceneIdx)
	{
		if( !m_poOwner->GetBuild(EBK_NEIDAN_INSTANCE) )
		{
			return ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_ERR;
		}

		if ( m_poOwner->GetLevel() < poInstanceProp->wEnterLevel)
		{
			return ERR_ENTER_INSTANCE::ID_LEVEL_ERR;
		}

		if ( byInstanceIdx != 1)
		{
			CInstanceRecord* poNeiDanRecord = GetSingleInstaceRecord(wSceneIdx, byTownIdx, byInstanceIdx - 1);
			if ( NULL == poNeiDanRecord)
			{
				return ERR_ENTER_INSTANCE::ID_NOT_UNLOCK_ERR;
			}
			//û�а�˳����ս
			if( m_stCurBattleInstance.wSceneIdx != wSceneIdx || m_stCurBattleInstance.byTownIdx != byTownIdx 
				|| m_stCurBattleInstance.byInstanceIdx != byInstanceIdx - 1)
			{
				return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
			}
		}

		if ( 0 == GetNeiDanCanBattleNum() )
		{
			return ERR_ENTER_INSTANCE::ID_NOT_TIMES_OUT_BOUND;
		}

		return ERR_ENTER_INSTANCE::ID_SUCCESS;
	}
    else
    {
        return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
    }

    return ERR_ENTER_INSTANCE::ID_INDEX_ERR;
}



BOOL CInstance::CkHaveRecord(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx)
{
    if(EIT_COMMON == wSceneIdx)
    {
        return m_mapCommonInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx)) ? TRUE : FALSE;
    }
    else if(EIT_ELITE == wSceneIdx)
    {
        return m_mapEliteInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx)) ? TRUE : FALSE;
    }
    else if (EIT_TOWER == wSceneIdx)
    {
        return m_mapClimbTowerInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx)) ? TRUE : FALSE;
    }
	else if ( EIT_OUT_BOUND == wSceneIdx)
	{
		return m_mapOutBoundRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx)) ? TRUE : FALSE;
	}

    return FALSE;
}

BOOL CInstance::EnterInstance(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx)
{
    SInstanceProp* poInstanceProp = NULL;
    poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(wSceneIdx, byTownIdx, byInstanceIdx);
    if(NULL == poInstanceProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CInstance::EnterInstance poInstanceProp[%d.%d.%d] is NUMM!"), MSG_MARK, wSceneIdx, byTownIdx, byInstanceIdx);
        return FALSE;
    }

    //���ϴβ���ͬһ����������ս����Ų���ı䣬ʹ���ѱ����
    //������¿�ʼս��
    if((m_stCurBattleInstance.wSceneIdx != wSceneIdx) ||
            (m_stCurBattleInstance.byTownIdx != byTownIdx) ||
            (m_stCurBattleInstance.byInstanceIdx != byInstanceIdx))
    {
        m_stCurBattleInstance.byBattleIdx = 0;
    }
    m_stCurBattleInstance.bFirstPass = FALSE;
    m_stCurBattleInstance.wSceneIdx = wSceneIdx;
    m_stCurBattleInstance.byTownIdx = byTownIdx;
    m_stCurBattleInstance.byInstanceIdx = byInstanceIdx;

    m_stCurBattleInstance.byBattleNum = poInstanceProp->vecWholeMonsterProp.size();


    //λ�ûص�
    if(m_poOwner)
    {
        m_poOwner->GetLocale().OnEnterInstance(wSceneIdx, byTownIdx, byInstanceIdx, m_stCurBattleInstance.byBattleIdx);
        //COprateingActivityMgr::Instance()->CloseActivityOnEnterInstance(m_poOwner); //�رջ
    }

    if(EIT_ELITE == wSceneIdx)
    {
        CBuild* poBuild = m_poOwner->GetBuild(EBK_ELITEINSTANCE);
        if(poBuild)
        {
            poBuild->OnOpen();
        }
    }
    else if (EIT_TOWER == wSceneIdx)
    {
        CBuild* poBuild = m_poOwner->GetBuild(EBK_CLIMBTOWER);
        if(poBuild)
        {
            poBuild->OnOpen();
        }
    }
	else if ( EIT_NEIDAN == wSceneIdx)
	{
		CBuild* poBuild = m_poOwner->GetBuild(EBK_NEIDAN_INSTANCE);
		if(poBuild)
		{
			poBuild->OnOpen();
		}
	}
    return TRUE;
}

BOOL CInstance::ExitInstance()
{
    if(NONINSTANCE == m_stCurBattleInstance.wSceneIdx)
    {
        return FALSE;
    }

    //λ�ûص�

    m_poOwner->GetLocale().OnExitInstance();

    m_stCurBattleInstance.Clear();

    m_bHaveEnterInstance = TRUE;

    return TRUE;
}

UINT16 CInstance::EnterBattle(UINT8 byBattleIndex)
{
    //���ڸ�����
    if(NONINSTANCE == m_stCurBattleInstance.wSceneIdx)
    {
        return ERR_BATTLE::ID_NOT_IN_INSTANCE_ERR;
    }

    //�Ѿ����
    if(byBattleIndex <= m_stCurBattleInstance.byBattleIdx)
    {
        return ERR_BATTLE::ID_HAVE_BATTLE_ERR;
    }

    //Ҫ��˳���,�Ѿ�����Ĳ����ٴ�,Ҳ��������δ���
    if(byBattleIndex != m_stCurBattleInstance.byBattleIdx + 1)
    {
        return ERR_BATTLE::ID_INDEX_ERR;
    }

    //�Ƿ���ڸùؿ�
    if(byBattleIndex > m_stCurBattleInstance.byBattleNum)
    {
        return ERR_BATTLE::ID_INDEX_ERR;
    }

    //

    return ERR_BATTLE::ID_SUCCESS;
}

BOOL CInstance::BattlePass(CMonsterGroup* poMonsterGroup, UINT8 byBattleIndex)
{
    if(NULL == poMonsterGroup)
    {
        return FALSE;
    }


    //��һ���ֿ۳�����
    //δ������԰���򲻿۳�����.
    //��Ӣ������������
    if((1 == byBattleIndex) && (EIT_COMMON == m_stCurBattleInstance.wSceneIdx))
    {
        if((NULL != m_poOwner->GetBuild(EBK_MAINTOWN)) || (m_bHaveEnterInstance))
        {
            //��ֹ��ҽ��븱����һ����������ٴ��
            UINT16 wPhyStrength = m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength;
            if( wPhyStrength >= m_byCommonPhyStrength )
            {
                m_poOwner->DecPhyStrength(m_byCommonPhyStrength, CRecordMgr::EDPST_INSTANCE);
            }
            else
            {
                m_poOwner->DecPhyStrength( m_poOwner->GetDT_PLAYER_BASE_DATA().wPhyStrength , CRecordMgr::EDPST_INSTANCE);
            }
        }
    }

    //��¼�Ѿ������
    //m_stCurBattleInstance.mapBattleIdx[byBattleIndex] = byBattleIndex;
    m_stCurBattleInstance.byBattleIdx = byBattleIndex;

    m_stCurBattleInstance.bFirstPass = FALSE;
    m_stCurBattleInstance.bPass = FALSE;
    //�ж��Ƿ�ͨ��
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx)	;
    if(pstInstanceProp && (byBattleIndex >= pstInstanceProp->vecWholeMonsterProp.size()))
    {
        m_stCurBattleInstance.bPass = TRUE;
        //�Ƿ�������¼(�������)���������¼
        if(((m_stCurBattleInstance.wSceneIdx == EIT_COMMON) && (m_stCurBattleInstance.byTownIdx > m_stMaxCommonInstanceID.byTownIdx)) ||
                ((m_stCurBattleInstance.wSceneIdx == EIT_COMMON) && (m_stCurBattleInstance.byTownIdx == m_stMaxCommonInstanceID.byTownIdx)) && (m_stCurBattleInstance.byInstanceIdx > m_stMaxCommonInstanceID.byInstanceIdx))
        {
            m_stMaxCommonInstanceID.wSceneIdx = m_stCurBattleInstance.wSceneIdx;
            m_stMaxCommonInstanceID.byTownIdx = m_stCurBattleInstance.byTownIdx;
            m_stMaxCommonInstanceID.byInstanceIdx = m_stCurBattleInstance.byInstanceIdx;
            m_stCurBattleInstance.bFirstPass = TRUE;
        }

        else if(((m_stCurBattleInstance.wSceneIdx == EIT_ELITE) && (m_stCurBattleInstance.byTownIdx > m_stMaxEliteInstanceID.byTownIdx)) ||
                ((m_stCurBattleInstance.wSceneIdx == EIT_ELITE) && (m_stCurBattleInstance.byTownIdx == m_stMaxEliteInstanceID.byTownIdx)) && (m_stCurBattleInstance.byInstanceIdx > m_stMaxEliteInstanceID.byInstanceIdx))
        {
            m_stMaxEliteInstanceID.wSceneIdx = m_stCurBattleInstance.wSceneIdx;
            m_stMaxEliteInstanceID.byTownIdx = m_stCurBattleInstance.byTownIdx;
            m_stMaxEliteInstanceID.byInstanceIdx = m_stCurBattleInstance.byInstanceIdx;
            m_stCurBattleInstance.bFirstPass = TRUE;
        }

        else if(((m_stCurBattleInstance.wSceneIdx == EIT_TOWER) && (m_stCurBattleInstance.byTownIdx > m_stMaxClimbTowerInstanceID.byTownIdx)) ||
                ((m_stCurBattleInstance.wSceneIdx == EIT_TOWER) && (m_stCurBattleInstance.byTownIdx == m_stMaxClimbTowerInstanceID.byTownIdx)) && (m_stCurBattleInstance.byInstanceIdx > m_stMaxClimbTowerInstanceID.byInstanceIdx))
        {
            m_stMaxClimbTowerInstanceID.wSceneIdx = m_stCurBattleInstance.wSceneIdx;
            m_stMaxClimbTowerInstanceID.byTownIdx = m_stCurBattleInstance.byTownIdx;
            m_stMaxClimbTowerInstanceID.byInstanceIdx = m_stCurBattleInstance.byInstanceIdx;
			CPlayerMedal* poPlayerMedal = m_poOwner->GetPlayerMedal();
			if ( NULL != poPlayerMedal )
			{
				poPlayerMedal->CheckMedalBySmallType(EMST_CLIMB_TOWER);
			}
            m_stCurBattleInstance.bFirstPass = TRUE;
        }
		else if ( EIT_OUT_BOUND == m_stCurBattleInstance.wSceneIdx)
		{
			if( NULL == GetSingleInstaceRecord(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx))
			{
				m_stCurBattleInstance.bFirstPass = TRUE;	
			}
		}
    }

    //ս������
    BOOL bFirstBattle = FALSE;
    if(EIT_COMMON == m_stCurBattleInstance.wSceneIdx)
    {
        bFirstBattle = m_oCommonInstanceBattleRcd.CkFirstBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
    }
    else if (EIT_ELITE == m_stCurBattleInstance.wSceneIdx)
    {
        bFirstBattle = m_oEliteInstanceBattleRcd.CkFirstBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
    }
    else if (EIT_TOWER == m_stCurBattleInstance.wSceneIdx)
    {
        bFirstBattle = m_oClimbTowerInstanceBattleRcd.CkFirstBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
    }
	else if ( EIT_OUT_BOUND == m_stCurBattleInstance.wSceneIdx)
	{
		//�����ս����¼ ��֮ǰ�����������
		bFirstBattle = (NULL == GetSingleInstaceRecord( m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx)) ? TRUE : FALSE;	
	}
    //�����������û�н���
    if (EIT_TOWER != m_stCurBattleInstance.wSceneIdx)
    {
        poMonsterGroup->Encourage(m_poOwner, bFirstBattle);
    }


    CMonster* poMonster = poMonsterGroup->GetMainMonster();
    if(poMonster)
    {
        SMonsterProp* poSMonsterProp = poMonster->GetMonsterProp();
        if(poSMonsterProp)
        {
            CTaskMgr::Instance()->OnKillMonsterInstance(m_poOwner, m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, poSMonsterProp->wKindID);
        }
    }


    //λ�ûص�
	if ( EIT_OUT_BOUND != m_stCurBattleInstance.wSceneIdx)
	{
		m_poOwner->GetLocale().OnPassBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
	}
    
    //��ǰս����ż�¼
    if(EIT_COMMON == m_stCurBattleInstance.wSceneIdx)
    {
        m_oCommonInstanceBattleRcd.OnInstanceBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
    }
    else if (EIT_ELITE == m_stCurBattleInstance.wSceneIdx)
    {
        m_oEliteInstanceBattleRcd.OnInstanceBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
    }
    else if (EIT_TOWER == m_stCurBattleInstance.wSceneIdx)
    {
        m_oClimbTowerInstanceBattleRcd.OnInstanceBattle(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byBattleIndex);
    }

    return TRUE;
}

//������Ӧ����
VOID CInstance::DoUnlock(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8& byBuildID, UINT16 awUnlockHeroID[MAX_UNLOCK_HERO_NUM])
{
    byBuildID = 0;

    for (int i = 0; i < MAX_UNLOCK_HERO_NUM; i++)
    {
        awUnlockHeroID[i] = 0;
    }

    //���ǵ�һ��ͨ�أ�ֱ�ӷ���
    if(!m_stCurBattleInstance.bFirstPass)
    {
        return;
    }
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(wSceneIdx, byTownIdx, byInstanceIdx);
    if(NULL == pstInstanceProp)
    {
        return;
    }

    byBuildID = UnlockBuild(pstInstanceProp);
    UnlockHero(wSceneIdx, byTownIdx, byInstanceIdx, awUnlockHeroID);
	if ( EIT_OUT_BOUND != wSceneIdx )
	{
		UnlockEliteTownIdx(pstInstanceProp);
	}
}

UINT8 CInstance::UnlockBuild(SInstanceProp* pstInstanceProp)
{
    if(NULL == pstInstanceProp)
    {
        return 0;
    }

    UINT8 byBuildKindID = 0;
    //����û�����1����������, ���·�	(��Э��ֻ֧��һ��������������Ӧ�����ö������ͬʱ����)
    CUnlockBuildKindMap& mapUnlockBuild = pstInstanceProp->mapUnlockBuildKind;
    for(CUnlockBuildKindMapItr itr = mapUnlockBuild.begin(); itr != mapUnlockBuild.end(); itr ++)
    {
        UINT8 byBuildKindID = itr->first;
        //��ҩ���ɱ�����ҩʱ����
        //if(EBK_TALENT == byBuildKindID)
        //{
        //	continue;
        //}

        CBuild* poBuild = m_poOwner->NewBuild(byBuildKindID);
        if(NULL == poBuild)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: unlock NewBuild[%d] failed!"), MSG_MARK, byBuildKindID);
        }
    }

    return byBuildKindID;
}

DT_INSTANCE_ID CInstance::GetMaxPassInstanceOfItem(UINT16 wItemID)
{
    DT_INSTANCE_ID stNullInstanceID;
    memset(&stNullInstanceID, 0, sizeof(stNullInstanceID));

    InstanceVec* pvecDropInstance = CInstancePropMgr::Instance()->GetDropInstanceListOfItem(wItemID);
    if (NULL == pvecDropInstance || pvecDropInstance->empty()){
        return stNullInstanceID;
    }

    InstanceVec &vecDropInstance = *pvecDropInstance;

    for(INT16 i = vecDropInstance.size() - 1; i >= 0; i--){
        DT_INSTANCE_ID &stInstanceID = vecDropInstance[i];

        UINT32 dwInstanceKey = CLogicFunc::GetInstanceIdxKey(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
        CInstanceRecord *pstRecord = m_mapOutBoundRecord.GetData(dwInstanceKey);
        if (NULL == pstRecord){
            continue;
        }
        
        if (pstRecord->GetDT_INSTANCE_DATA().dwSuccessNum < pstRecord->GetInstanceProp()->byBattleNum){
            return stInstanceID;
        }
    }

    return stNullInstanceID;
}

UINT16 CInstance::UnlockHero(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT16 awUnlockHeroID[MAX_UNLOCK_HERO_NUM])
{
    UINT16 wHeroKindID = 0;
    //��һ��ͨ�أ��������佫
    if(m_stCurBattleInstance.bFirstPass)
    {
        m_poOwner->GetState().ResetUnlockHero();
        SHeroUnlockProp* pstHeroUnlockProp = CInstancePropMgr::Instance()->GetUnlockHero(wSceneIdx, byTownIdx, byInstanceIdx);
        for(int i = 0; i < MAX_UNLOCK_HERO_NUM; i++)
        {
            if((NULL == pstHeroUnlockProp) || (0 == pstHeroUnlockProp->wUnlockHeroKindID[i]))
            {
                return 0;
            }
            CHero* poHero = m_poOwner->NewHero(pstHeroUnlockProp->wUnlockHeroKindID[i]);
            if(NULL == poHero)
            {
                return 0;
            }
            awUnlockHeroID[i] = wHeroKindID;
            wHeroKindID = pstHeroUnlockProp->wUnlockHeroKindID[i];
            m_poOwner->GetState().OnUnlockHero(wHeroKindID);
        }
    }
    return wHeroKindID;
}

UINT32 CInstance::UnlockEliteTownIdx(SInstanceProp* pstInstanceProp)
{
    if(NULL == pstInstanceProp)
    {
        return 0;
    }

    //������Ӣ������ʾ(0��ʾû�У���1���ֽڱ�ʾ��Ӣ��������idx����2���ֽڱ�ʾ��Ӣ��������InstanceIdx,  ��3/4���ֽڱ�ʾ������ID)

    UINT32 dwUnlockElite = 0;
    if(0 != pstInstanceProp->stUnlockEliteInstanceID.byTownIdx)
    {
        dwUnlockElite = CLogicFunc::Get1688Key(pstInstanceProp->wMainMonsterKindID, pstInstanceProp->stUnlockEliteInstanceID.byTownIdx, pstInstanceProp->stUnlockEliteInstanceID.byInstanceIdx);
        m_poOwner->GetState().OnUnlockEliteInstanceID(dwUnlockElite);
    }

    return dwUnlockElite;
}


CInstanceRecord* CInstance::GetSingleInstaceRecord(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, BOOL bGetSuccessRecord)
{
    CInstanceRecord* poInstanceRecord = NULL;
    if(EIT_COMMON == wSceneIdx)
    {
        poInstanceRecord = m_mapCommonInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx));
    }
    else if(EIT_ELITE == wSceneIdx)
    {
        poInstanceRecord = m_mapEliteInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx));
    }
    else if(EIT_TOWER == wSceneIdx)
    {
        poInstanceRecord = m_mapClimbTowerInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx));
    }
	else if ( EIT_OUT_BOUND == wSceneIdx)
	{
		
		poInstanceRecord = m_mapOutBoundRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx));
		if ( poInstanceRecord)
		{
			if ( !IsToday(poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime))
			{
				poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum = 0;
			}
		}
	}
	else if ( EIT_NEIDAN == wSceneIdx)
	{
		poInstanceRecord = m_mapNeiDanInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, byInstanceIdx));
	}
    if((bGetSuccessRecord && poInstanceRecord) && (EIT_OUT_BOUND != wSceneIdx))
    {
        return 0 == poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum ? NULL : poInstanceRecord;
    }

    return poInstanceRecord;
}

void		CInstance::DelClimbTownInstaceRecord(UINT16 wSceneIdx, UINT8 byTownIdx)//ɾ������������¼
{
    //��ȡ������Ϣ
    STownInstanceProp* pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, byTownIdx);
    if (NULL == pstTownInstanceProp)
    {
        return ;
    }

    //�ӵ�һ����ʼ���Ҽ�¼�����ؼ�¼
    SInstanceProp *pstInstanceProp = NULL;
    CIndex2InstancePropMapItr itr = pstTownInstanceProp->m_mapInstance.begin();
    for (itr = pstTownInstanceProp->m_mapInstance.begin(); itr != pstTownInstanceProp->m_mapInstance.end(); itr++)
    {
        pstInstanceProp = itr->second;
        if (NULL == pstInstanceProp)
        {
            continue;
        }
        m_mapClimbTowerInstanceRecord.DelData(CLogicFunc::GetInstanceIdxKey(wSceneIdx, byTownIdx, pstInstanceProp->byIndex));
        CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetDT_PLAYER_BASE_DATA().dwID, wSceneIdx, byTownIdx, pstInstanceProp->byIndex);
    }

    //��ʼ��Ĭ�Ͽ�����һ����
    m_stMaxClimbTowerInstanceID.wSceneIdx = EIT_TOWER;
    m_stMaxClimbTowerInstanceID.byTownIdx = 1;
    m_stMaxClimbTowerInstanceID.byInstanceIdx = 0;
}




UINT16  CInstance::OpenEncourageBox(DT_PASS_ENCOURAGE_BOX_DATA& stDT_PASS_ENCOURAGE_BOX_DATA, DT_DATA_AFTER_PASS_ENCOURAGE_BOX* pstAfterEncourage)
{
    //�ж��Ƿ�ͨ��
    if(FALSE == m_stCurBattleInstance.bPass)
    {
        return ERR_OPEN_INSTANCE_ENCOURAGE_BOX::ID_NOT_PASS;
    }

    //�ж��Ƿ��Ѿ���ȡ��
    if(1 == m_poOwner->GetState().GetDT_STATE_DATA().byOpenBoxFlag)
    {
        return ERR_OPEN_INSTANCE_ENCOURAGE_BOX::ID_HAVE_OPEN;
    }

    UINT16 wErrCode = PassBoxEnc(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, stDT_PASS_ENCOURAGE_BOX_DATA, pstAfterEncourage);
    if(ERR_OPEN_INSTANCE_ENCOURAGE_BOX::ID_SUCCESS == wErrCode)
    {
        m_poOwner->GetState().OnOpenEncourageBox();

        //�򿪱�����˳�����
        m_poOwner->ExitInstance();
    }

    return wErrCode;
}


VOID CInstance::PassEncourage(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byRunTimes, DT_PASS_ENCOURAGE_DATA* pstDT_PASS_ENCOURAGE_DATA, DT_DATA_AFTER_PASS_ENCOURAGE* pstAfterEncourage)
{
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(wSceneIdx, byTownIdx, byInstanceIdx);
    if(NULL == pstInstanceProp)
    {
        return ;
    }



    SPassEncourageProp& stPassEncourageProp = pstInstanceProp->stPassEncourageProp;
    UINT32	dwExperience =	stPassEncourageProp.dwExperience;
    if(m_poOwner->GetState().GetDT_STATE_DATA().wDoubleExpNum > 0)
    {
        dwExperience = dwExperience * 2;
    }

    CNGString strData;
    strData += (UINT64)byRunTimes;

    m_poOwner->AllotExperience(dwExperience * byRunTimes);
    UINT32	dwStory		=	stPassEncourageProp.dwStory * byRunTimes ;
    m_poOwner->AddStory(dwStory * byRunTimes, CRecordMgr::EASTT_INSTANCE, m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byRunTimes, strData.str());

    UINT32	dwCoin		=	stPassEncourageProp.dwCoin * byRunTimes;
    m_poOwner->AddCoin(dwCoin * byRunTimes, CRecordMgr::EACT_INSTANCE, m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx, byRunTimes, strData.str());

    //�·���ֵ
    if(pstDT_PASS_ENCOURAGE_DATA)
    {
        pstDT_PASS_ENCOURAGE_DATA->dwCoachExperience = pstInstanceProp->dwAllExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;
        pstDT_PASS_ENCOURAGE_DATA->dwExperience = pstInstanceProp->dwAllExperience;
        pstDT_PASS_ENCOURAGE_DATA->dwStory		= dwStory;
        pstDT_PASS_ENCOURAGE_DATA->dwCoin		= dwCoin;
    }
    if(pstAfterEncourage)
    {
        m_poOwner->GetPassInstanceHeroUpgradeInfo(pstInstanceProp->dwAllExperience, pstAfterEncourage->byHeroNum, pstAfterEncourage->astHeroUpgradeInfo);
    }
}

//����ͨ�ر��佱��
VOID CInstance::RatePassBoxEnc(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, DT_PASS_ENCOURAGE_BOX_DATA& stPassEncourageBox, BOOL bOnhook)
{


    UINT8 abyHitItemIdx[MAX_ENCOURAGE_BOX_GROUP_NUM] = {0};
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(wSceneIdx, byTownIdx, byInstanceIdx);
    if(NULL == pstInstanceProp)
    {
        m_poOwner->GetState().OnRatePassBox(abyHitItemIdx);
        SYS_CRITICAL(_SDT("[%s: %d]: RatePassBoxEnc pstInstanceProp[%d.%d.%d] is NULL!"), MSG_MARK, wSceneIdx, byTownIdx, byInstanceIdx);
        return ;
    }
    SPassBoxProp& stPassBoxProp = pstInstanceProp->stPassBoxProp;
    CItemGroupMap& mapItemGroup = stPassBoxProp.mapItemGroup;
    if(0 == mapItemGroup.size())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: RatePassBoxEnc pstInstanceProp[%d.%d.%d] mapItemGroup size is 0!"), MSG_MARK, wSceneIdx, byTownIdx, byInstanceIdx);
        m_poOwner->GetState().OnRatePassBox(abyHitItemIdx);
        return ;
    }

    UINT8 byGroupNum = 0;
    for(CItemGroupMapItr itr = mapItemGroup.begin(); ((itr != mapItemGroup.end()) && (byGroupNum < MAX_ENCOURAGE_BOX_GROUP_NUM)); itr++, byGroupNum++)
    {
        SItemGroupProp& stItemGroupProp = itr->second;
        DT_PASS_ENCOURAGE_BOX_GROUP_DATA& stBoxGroupInfo = stPassEncourageBox.astBoxGroupInfo[byGroupNum];
        UINT16 wItemKindID = 0;
        UINT16 wPileNum = 0;
        UINT8 byHitItemIdx = 0; //0��ʾδ����
        if((FALSE == bOnhook) && (m_stCurBattleInstance.bFirstPass) && (0 != stItemGroupProp.wFirstItemKindID)) //�״�ͨ�������״αر���Ʒ
        {
            wItemKindID = stItemGroupProp.wFirstItemKindID;
            wPileNum = stItemGroupProp.wFirstItemPileNum;
            byHitItemIdx = stItemGroupProp.byFirstItemHitIdx;
        }
        else
        {
            CItemRateMap& mapItem = stItemGroupProp.mapItem;
            //�������ֵ
            CRandomVec vecRandom;
            CItemRateMapItr itr;
            for(itr = mapItem.begin(); itr != mapItem.end(); itr++)
            {
                vecRandom.push_back(itr->second.wRate);
            }
            //���
            INT32 nRandomHitIdx = GetRandomIdx(vecRandom, 10000);//��ֱ�
            if(RANDOM_UNHIT != nRandomHitIdx) //����
            {
                byHitItemIdx = nRandomHitIdx + 1; //
                UINT8 byIdx = 0;
                for(itr = mapItem.begin(); itr != mapItem.end(); itr++, byIdx++)
                {
                    if(byIdx == nRandomHitIdx)
                    {
                        wItemKindID = itr->first;
                        wPileNum = itr->second.wItemNum;
                    }
                }
            }
            else
            {
                USR_INFO(_SDT("[%s: %d]: RatePassBoxEnc pstInstanceProp[%d.%d.%d] UNHIT!"), MSG_MARK, wSceneIdx, byTownIdx, byInstanceIdx);
                byHitItemIdx = 0;
            }
        }

        abyHitItemIdx[byGroupNum] = byHitItemIdx;

        stBoxGroupInfo.byHitItemIdx = byHitItemIdx;
        memcpy(&stBoxGroupInfo.stItemInfo, &stItemGroupProp.stBoxItem, sizeof(DT_ITEM_DATA_LIST_CLI));
    }
    stPassEncourageBox.byGroupNum = byGroupNum;

    m_poOwner->GetState().OnRatePassBox(abyHitItemIdx);
}


UINT16 CInstance::PassBoxEnc(UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 byInstanceIdx, DT_PASS_ENCOURAGE_BOX_DATA& stDT_PASS_ENCOURAGE_BOX_DATA, DT_DATA_AFTER_PASS_ENCOURAGE_BOX* pstAfterPassEncourage)
{
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(wSceneIdx, byTownIdx, byInstanceIdx);
    if(NULL == pstInstanceProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: PassBoxEnc pstInstanceProp[%d.%d.%d] is NULL!"), MSG_MARK, wSceneIdx, byTownIdx, byInstanceIdx);
        RETURN_OTHER_ERR;
    }

    UINT8 abyHitItemIdx[MAX_ENCOURAGE_BOX_GROUP_NUM] = {0};
    memcpy(&abyHitItemIdx, &m_poOwner->GetState().GetDT_STATE_DATA().abyHitItemIdx, sizeof(abyHitItemIdx));
    CItemGroupMap& mapItemGroup = pstInstanceProp->stPassBoxProp.mapItemGroup;
    CItemKindID2NumMap mapHitItem; //������Ʒmap
    UINT32 dwCoin = 0;
    UINT32 dwGold = 0;
    UINT32 dwBlueGas = 0;
    UINT8 byGroupNum = 0;
    UINT8 byNeedBagGrid = 0;
    CBag& oBag = m_poOwner->GetBag();
    for(CItemGroupMapItr itrGoup = mapItemGroup.begin(); ((itrGoup != mapItemGroup.end()) && (byGroupNum < MAX_ENCOURAGE_BOX_GROUP_NUM)); itrGoup++, byGroupNum++)
    {
        UINT8 byHitItemIdx = abyHitItemIdx[byGroupNum];
        DT_PASS_ENCOURAGE_BOX_GROUP_DATA& stBoxGroupInfo = stDT_PASS_ENCOURAGE_BOX_DATA.astBoxGroupInfo[byGroupNum];
        UINT16 wItemKindID = 0;
        UINT16 wPileNum = 0;
        if((0 != byHitItemIdx) && (byHitItemIdx <= itrGoup->second.stBoxItem.byItemNum)) //0��ʾδ����
        {
            DT_ITEM_DATA_CLI& stDT_ITEM_DATA_CLI = itrGoup->second.stBoxItem.astItemList[byHitItemIdx - 1];
            wItemKindID = stDT_ITEM_DATA_CLI.wKindID;
            wPileNum = stDT_ITEM_DATA_CLI.wPileNum;
        }
        else
        {
            USR_INFO(_SDT("[%s: %d]: PassBoxEnc pstInstanceProp[%d.%d.%d] byHitItemIdx[%d] !<= byItemNum[%d]!"), MSG_MARK, wSceneIdx, byTownIdx, byInstanceIdx, byHitItemIdx, itrGoup->second.stBoxItem.byItemNum);
            byHitItemIdx = 0; //����byHitItemIdxֵ�쳣
        }

        stBoxGroupInfo.byHitItemIdx = byHitItemIdx;
        if((0 != wItemKindID) && (0 != byHitItemIdx))
        {
            BOOL bGive = FALSE;
            SGoodsProp* pstGoodsProp = CGoodsPropMgr::Instance()->GetPropByPrimaryKey(wItemKindID);
            if(pstGoodsProp)
            {
                switch(pstGoodsProp->byMainKindID)
                {
                case EGMK_COIN:
                {
                    UINT32 dwValue = pstGoodsProp->dwValue * wPileNum;
                    dwCoin += dwValue;
                    stBoxGroupInfo.dwCoin = dwValue;
                    bGive = TRUE;
                }
                break;
                case EGMK_GOLD:
                {
                    UINT32 dwValue = pstGoodsProp->dwValue * wPileNum;
                    dwGold += dwValue;
                    stBoxGroupInfo.dwGold = dwValue;
                    bGive = TRUE;
                }
                break;
                case EGMK_BLUEGAS:
                {
                    UINT32 dwValue = pstGoodsProp->dwValue * wPileNum;
                    dwBlueGas += dwValue;
                    stBoxGroupInfo.dwBlueGas = dwBlueGas;
                    bGive = TRUE;
                }
                break;
                }
            }

            if((FALSE == bGive) && (0 != wItemKindID) && (0 != byHitItemIdx))
            {
                mapHitItem[wItemKindID] += wPileNum;

                stBoxGroupInfo.stItemInfo.byItemNum = 1;
                DT_ITEM_DATA_CLI& stDT_ITEM_DATA_CLI = stBoxGroupInfo.stItemInfo.astItemList[0];
                stDT_ITEM_DATA_CLI.wKindID = wItemKindID;
                stDT_ITEM_DATA_CLI.wPileNum = wPileNum;
                if(pstGoodsProp)
                {
                    stDT_ITEM_DATA_CLI.byGoodsMainKindID = pstGoodsProp->byMainKindID;
                }
                if(!oBag.GetGoodsItem(wItemKindID))
                {
                    byNeedBagGrid++; //װ����������һ��ͬʱ������
                }
            }
        }
    }
    stDT_PASS_ENCOURAGE_BOX_DATA.byGroupNum = byGroupNum;

    if(oBag.GetIdleSize() < byNeedBagGrid)
    {
        return ERR_OPEN_INSTANCE_ENCOURAGE_BOX::ID_BAG_FULL;
    }

    //����������
    m_poOwner->AddCoin(dwCoin, CRecordMgr::EACT_INSTANCE, wSceneIdx, byTownIdx, byInstanceIdx);
    m_poOwner->AddGold(dwGold, CRecordMgr::EGGT_ADDGOLDINSTANCE, wSceneIdx, byTownIdx, byInstanceIdx);
    m_poOwner->AddBlueGas(dwBlueGas, CRecordMgr::EABGT_INSTANCEBURST, wSceneIdx, byTownIdx, byInstanceIdx);
    for(CItemKindID2NumMapItr itrItem = mapHitItem.begin(); itrItem != mapHitItem.end(); itrItem++)
    {
        UINT16 wItemKindID = itrItem->first;
        UINT16 wPileNum = itrItem->second;

        //ͭ��/Ԫ��/����ֱ��ʹ��
        SGoodsProp* pstGoodsProp = CGoodsPropMgr::Instance()->GetPropByPrimaryKey(wItemKindID);
        if(pstGoodsProp)
        {
            switch(pstGoodsProp->byMainKindID)
            {
            case EGMK_COIN:
            {
                //m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin += pstGoodsProp->dwValue * wPileNum;
                m_poOwner->AddCoin(pstGoodsProp->dwValue * wPileNum, CRecordMgr::EACT_INSTANCEGOODS, wSceneIdx, byTownIdx, byInstanceIdx);
            }
            continue;
            case EGMK_GOLD:
            {
                //m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold += pstGoodsProp->dwValue * wPileNum;
                m_poOwner->AddGold(pstGoodsProp->dwValue * wPileNum, CRecordMgr::EGGT_ADDGOLDINSTANCEGOODS, wSceneIdx, byTownIdx, byInstanceIdx);
            }
            continue;
            case EGMK_BLUEGAS:
            {
                m_poOwner->AddBlueGas(pstGoodsProp->dwValue * wPileNum, CRecordMgr::EABGT_INSTANCEBURST, wSceneIdx, byTownIdx, byInstanceIdx);
            }
            continue;
            }
        }

        ECreateItemRet Ret = ECIR_SUCCESS;
        CItem* poItem = CItemMgr::Instance()->CreateItemIntoBag(m_poOwner, wItemKindID, wPileNum, Ret, 0, CRecordMgr::EAIT_INSTANCE);
        if(NULL != poItem)
        {
            /*
            //��Ϊװ�������ж��Ƿ��贩������
            if(EIK_EQUIP == CItemMgr::Instance()->GetItemKindBYKindID(poItem->GetItemKindID()))
            {
            	m_poOwner->CKGuide( EGF_EQUIP);
            }
            else
            {
            	//��Ϊ��ҩ��δ�е�ҩ������������ҩ��
            	if((NULL == m_poOwner->GetBuild(EBK_TALENT) && (CDrugPropMgr::Instance()->IsDrugGoods(wItemKindID))))
            	{
            		m_poOwner->NewBuild(EBK_TALENT);
            	}

            	//��Ϊ�������ܿ�Ƭ�������ѧϰ����
            	else if((CSkillPropMgr::Instance()->GetSkillBaseProp().wNormalUpgradeItemID == itrItem->first) && (NULL != m_poOwner->GetBuild(EBK_SKILL)))
            	{
            		m_poOwner->CKGuide( EGF_STUDYSKILL);
            	}

            }
            */
        }
    }


    if(pstAfterPassEncourage)
    {
        pstAfterPassEncourage->qwCurCoin = m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin;
        pstAfterPassEncourage->qwCurGold = m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;
        pstAfterPassEncourage->qwCurBlueGas = m_poOwner->GetDT_PLAYER_BASE_DATA().qwBlueGas;
    }

    return ERR_OPEN_INSTANCE_ENCOURAGE_BOX::ID_SUCCESS;
}


UINT8 CInstance::GetCanCarryNum()
{
    DT_INSTANCE_ID& stInstanceID = m_stMaxCommonInstanceID;
    SHeroUnlockProp* pstHeroUnlockProp = NULL;
    pstHeroUnlockProp = CInstancePropMgr::Instance()->GetUnlockHero(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
    if(NULL == pstHeroUnlockProp)
    {
        return 1;
    }
    return pstHeroUnlockProp->byCarryNum;
}

DT_INSTANCE_ID* CInstance::GetCurMaxUnlockEliteInstanceID()
{
    SInstanceProp* poInstanceProp = NULL;
    poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(m_stMaxCommonInstanceID.wSceneIdx, m_stMaxCommonInstanceID.byTownIdx, m_stMaxCommonInstanceID.byInstanceIdx);
    if(poInstanceProp)
    {
        return &(poInstanceProp->stUnlock2EliteInstanceID);
    }
    return NULL;
}

//DT_INSTANCE_ID CInstance::GetCurMaxUnlockClimbTowerInstanceID()
//{
//    //��ȡ��һ����δ��������Ϣ
//    DT_INSTANCE_ID stDT_INSTANCE_ID;
//    memset(&stDT_INSTANCE_ID, 0x00, sizeof(stDT_INSTANCE_ID));
//    SInstanceProp* poInstanceProp = NULL;
//    poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(m_stMaxClimbTowerInstanceID.wSceneIdx, m_stMaxClimbTowerInstanceID.byTownIdx + 1, 1);
//    if(poInstanceProp)
//    {
//        stDT_INSTANCE_ID.wSceneIdx = m_stMaxClimbTowerInstanceID.wSceneIdx;
//        stDT_INSTANCE_ID.byTownIdx = m_stMaxClimbTowerInstanceID.byTownIdx + 1;
//        stDT_INSTANCE_ID.byInstanceIdx = 1;
//    }
//    return stDT_INSTANCE_ID;
//}


//����Ƿ�����þ�Ӣ����
BOOL CInstance::CkEliteUnlock(UINT8 byTownIdx, UINT8 byInstanceIdx)
{
    //�ж��Ƿ����
    SInstanceProp* poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(m_stMaxCommonInstanceID.wSceneIdx, m_stMaxCommonInstanceID.byTownIdx, m_stMaxCommonInstanceID.byInstanceIdx);
    if(NULL == poInstanceProp)
    {
        return FALSE;
    }
    UINT16 wKey = CLogicFunc::Get88Key(byTownIdx, byInstanceIdx);
    if(poInstanceProp->mapUnlockEliteInstanceID.find(wKey) != poInstanceProp->mapUnlockEliteInstanceID.end())
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    return FALSE;
}


VOID	 CInstance::GetEliteInstanceNum(UINT32 &dwMaxInstanceNum, UINT32  &dwMaxUnlockInstanceNum)//������//������¼��Ϣ
{
    dwMaxInstanceNum = 0;
    dwMaxUnlockInstanceNum = 0;
    UINT8 byTownIdx = 1;
    while((CkEliteUnlock(byTownIdx, 1)) && (byTownIdx <= MAX_TOWN_PER_SCENE_NUM))
    {
        UINT8 byInstandeIdx = 1;
        while( byInstandeIdx < MAX_INSTANCE_PER_TOWN_NUM && (CkEliteUnlock(byTownIdx, byInstandeIdx) ) )
        {
            CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(EIT_ELITE, byTownIdx, byInstandeIdx);
            //û�м�¼����ֵ���ֵ
            if(NULL != poInstanceRecord)
            {
                dwMaxUnlockInstanceNum++;
            }
            dwMaxInstanceNum++;
            byInstandeIdx++;
        }
        byTownIdx++;
    }
    dwMaxInstanceNum -= dwMaxUnlockInstanceNum;
}


UINT8 CInstance::GetEliteInstanceRecordData( DT_ELITE_INSTANCE_RECORD_DATA_CLI &stData, DT_ELITE_INSTANCE_RECORD_SCORE_DATA_CLI &stScoreData, UINT8 byTownIndex)
{
    stData.byIndex = byTownIndex;
    UINT8	byInstandeIdx		=	1;
    UINT16	wScore			=	0;
    while( byInstandeIdx < MAX_INSTANCE_PER_TOWN_NUM && (CkEliteUnlock(byTownIndex, byInstandeIdx) ) )
    {
        CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(EIT_ELITE, byTownIndex, byInstandeIdx);
        DT_ELITE_INSTANCE_RECORD_DATA& stDT_INSTANCE_RECORD_DATA_CLI = stData.astInstanceInfo[byInstandeIdx - 1]; //��Ӣ����ÿ������

        //û�м�¼����ֵ���ֵ
        if(NULL == poInstanceRecord)
        {
            SInstanceProp* pstProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_ELITE, byTownIndex, byInstandeIdx);
            if(NULL == pstProp)
            {
                break;
            }
            //poInstanceRecord->GetInstanceProp()->wEnterLevel
            stDT_INSTANCE_RECORD_DATA_CLI.byIndex = pstProp->byIndex;
            memcpy(&(stDT_INSTANCE_RECORD_DATA_CLI.stBurstItemInfo), &(pstProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
            stDT_INSTANCE_RECORD_DATA_CLI.wMainMonsterKindID = pstProp->wMainMonsterKindID;
            stDT_INSTANCE_RECORD_DATA_CLI.byCanBattle = 1;
        }
        //��¼���ڣ���ֵ��¼ֵ
        else
        {
            DT_INSTANCE_DATA& stDT_INSTANCE_DATA = poInstanceRecord->GetDT_INSTANCE_DATA();
            stDT_INSTANCE_RECORD_DATA_CLI.byIndex = stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx;
            stScoreData.abyScore[byInstandeIdx - 1] = stDT_INSTANCE_DATA.byScore;

            wScore += stDT_INSTANCE_DATA.byScore;
            SInstanceProp* pstInstanceProp = poInstanceRecord->GetInstanceProp();
            if(pstInstanceProp)
            {
                memcpy(&(stDT_INSTANCE_RECORD_DATA_CLI.stBurstItemInfo), &(pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
            }
            else
            {
                SYS_CRITICAL(_SDT("[%s: %d]: pstInstanceProp is nULL!"), MSG_MARK);
                break;
            }
            //�����Ѿ����
            if(IsToday(stDT_INSTANCE_DATA.qwLastPassTime))
            {
                stDT_INSTANCE_RECORD_DATA_CLI.byCanBattle = 0;
            }
            else
            {
                stDT_INSTANCE_RECORD_DATA_CLI.byCanBattle = 1;
            }
            stDT_INSTANCE_RECORD_DATA_CLI.wMainMonsterKindID = pstInstanceProp->wMainMonsterKindID;
        }

        byInstandeIdx++;
    }


    //////////////////////////////////////////////////////////////////////////
    //���������Ϣ
    CScore *poScore = m_poOwner->GetScore();
    if (NULL != poScore)
    {
        SScoreProp *poScoreProp = CScorePropMgr::Instance()->GetScoreProp(EIT_ELITE, byTownIndex);
        if (NULL != poScoreProp)
        {
            DT_CHAPTER_SCORE & stChapterInfo = stScoreData.stChapterInfo;
            if (wScore >= poScoreProp->wScore)
            {
                //���ʱ���Ƿ����0���������0��������ȡ����
                if(!poScore->IsRecvedChapter(EIT_ELITE, byTownIndex))
                {
                    stChapterInfo.byFlag = 1;
                }
                else
                {
                    stChapterInfo.byFlag = 2;
                }
            }
            else
            {
                stChapterInfo.byFlag = 0;
            }
            PackRatingEncourage(stChapterInfo.stChapterEncourage, poScoreProp);
        }

    }


    stData.byInstanceNum = byInstandeIdx - 1;
    stScoreData.byInstanceNum = byInstandeIdx - 1;

    stData.wRemainResetNum = m_poOwner->GetVipExtData().GetRemainResetEliteInstanceNum( byTownIndex );
    stData.qwCostGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_RESETELITEINSTANCE, m_poOwner->GetVipExtData().GetResetEliteInstanceNum( byTownIndex ), byTownIndex);

    stData.wOnhookLevel = 0;
    STownInstanceProp* psSTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_ELITE, byTownIndex);
    if(psSTownInstanceProp)
    {
        stData.wOnhookLevel = psSTownInstanceProp->wOnhookLevel;
    }

    return byInstandeIdx;
}

BOOL CInstance::GetCommonInstanceRecord(PKT_CLIGS_GET_SCENE_INSTANCE_ACK& stAck)
{
    memcpy(&stAck.stMaxInstanceData, &m_stMaxCommonInstanceID, sizeof(DT_INSTANCE_ID));
    m_poOwner->GetMaxUnlockCommonInstanceID(stAck.stMaxUnlockInstance);

    if(m_poOwner->GetCliVer() <= 292)
    {
        if (stAck.stMaxInstanceData.byTownIdx > 78)
        {
            stAck.stMaxInstanceData.byTownIdx = 78;
        }
        if (stAck.stMaxUnlockInstance.byTownIdx > 78)
        {
            stAck.stMaxUnlockInstance.byTownIdx = 78;
        }
    }

	if ( m_poOwner->GetCliVer() <= 306)
	{
		if (stAck.stMaxInstanceData.byTownIdx > 87)
		{
			stAck.stMaxInstanceData.byTownIdx = 87;
		}
		if (stAck.stMaxUnlockInstance.byTownIdx > 87)
		{
			stAck.stMaxUnlockInstance.byTownIdx = 87;
		}
	}

    //��ȡ��ͨ��������
    stAck.byEnterPhyStrength = CPhystrengthMgr::Instance()->GetCommonPhyStrength();

    //���û�,�ͷ��ص�һ��������Ϣ
    if((0 == m_mapCommonInstanceRecord.Size()) || (0 == m_mapCommonInstanceRecord.GetFistData()->GetDT_INSTANCE_DATA().dwSuccessNum))
    {
        GiveFirstInsance(stAck);
    }
    else
    {
        DT_INSTANCE_ID stMaxUnlockCommonInstanceID;
        m_poOwner->GetMaxUnlockCommonInstanceID(stMaxUnlockCommonInstanceID);//��ȡ����������ĸ���

        //��ȡ��ǰ��󸱱�����һ��������Ϣ
        SNextInstance stNextInstance;
        CInstancePropMgr::Instance()->GetNextInstance(EIT_COMMON, m_stMaxCommonInstanceID.byTownIdx, m_stMaxCommonInstanceID.byInstanceIdx, stNextInstance);

        stAck.wIndex = EIT_COMMON;
        UINT8	byTownNum = 0;
        BOOL		bHaveNextInstance = FALSE;
        UINT8	byLastTownIdx = 0;
        UINT8	byLastInstanceIdx = 0;
        UINT8	byInstanceNum = 0;

        UINT32   dwCurSocre =	0;
        UINT32   dwChapterScore =	0;
        DT_TOWN_INSTANCE_RECORD_DATA_CLI* pstDT_TOWN_INSTANCE_RECORD_DATA_CLI = NULL;
        DT_INSTANCE_RECORD_DATA_CLI* pstDT_INSTANCE_RECORD_DATA_CLI = NULL;
        CInstanceRecord* poInstanceRecord = m_mapCommonInstanceRecord.GetFistData();
        while(poInstanceRecord)
        {
            //292�汾֮ǰֻ����78������
            if(m_poOwner->GetCliVer() <= 292 && byTownNum > 78)
            {
                byTownNum = 78;
                break;
            }
			if(m_poOwner->GetCliVer() <= 306 && byTownNum > 87)
			{
				byTownNum = 87;
				break;
			}

            if(0 == poInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum) //����ʧ�ܵļ�¼
            {
                poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
                continue;
            }
            UINT8 byTownIdx		= poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID.byTownIdx;
            UINT8 byInstanceIdx	= poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID.byInstanceIdx;
            if(byLastTownIdx != byTownIdx)
            {
                if(pstDT_TOWN_INSTANCE_RECORD_DATA_CLI)
                {
                    pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->byInstanceNum = byInstanceNum;
                }
                pstDT_TOWN_INSTANCE_RECORD_DATA_CLI = &(stAck.astTownInstanceInfo[byTownNum++]);
                pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->byIndex = poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID.byTownIdx;
                pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->byCanBattle = 1;
                pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->wMainMonsterKindID = 0;
                byInstanceNum = 0;
            }
            if(NULL == pstDT_TOWN_INSTANCE_RECORD_DATA_CLI)
            {
                SET_OTHER_ERR(stAck.wErrCode)
                return FALSE;
            }

            //ͳ������
            dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
            dwChapterScore += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;

            pstDT_INSTANCE_RECORD_DATA_CLI = &(pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->astInstanceInfo[byInstanceNum++]);
            pstDT_INSTANCE_RECORD_DATA_CLI->byIndex = poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID.byInstanceIdx;
            pstDT_INSTANCE_RECORD_DATA_CLI->byScore = poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
            SInstanceProp* pstInstanceProp = poInstanceRecord->GetInstanceProp();
            if(pstInstanceProp)
            {
                pstDT_INSTANCE_RECORD_DATA_CLI->wEnterLevel = 1;//pstInstanceProp->wEnterLevel; //ȥ�������ȼ�����
                memcpy(&(pstDT_INSTANCE_RECORD_DATA_CLI->stBurstItemInfo), &(pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
                pstDT_INSTANCE_RECORD_DATA_CLI->dwBurstExperience = pstInstanceProp->dwAllExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;
                pstDT_INSTANCE_RECORD_DATA_CLI->dwMaxMonstorPower = pstInstanceProp->dwMaxMonsterPower;
            }
            else
            {
                SYS_CRITICAL(_SDT("[%s: %d]: pstInstanceProp is nULL!"), MSG_MARK);
            }


            //////////////////////////////////////////////////////////////////////////
            //���������Ϣ��ÿ���½���������ÿ����������������
            if (byTownIdx && byInstanceIdx && byTownIdx % 3 == 0 && byInstanceIdx % 3 == 0)
            {
                CScore *poScore = m_poOwner->GetScore();
                if (NULL != poScore)
                {
                    UINT8	byChapterIdx = byTownIdx / 3;
                    SScoreProp *poScoreProp = CScorePropMgr::Instance()->GetScoreProp(EIT_COMMON, byChapterIdx);
                    if (NULL != poScoreProp)
                    {
                        stAck.byChapterNum = (UINT8)byChapterIdx;
                        DT_CHAPTER_SCORE & stChapterInfo = stAck.astChapterInfo[byChapterIdx - 1];

                        //���ʱ���Ƿ����0���������0��������ȡ����
                        if (dwChapterScore >= poScoreProp->wScore)
                        {
                            if(!poScore->IsRecvedChapter(EIT_COMMON, byChapterIdx))
                            {
                                stChapterInfo.byFlag = 1;
                            }
                            else
                            {
                                stChapterInfo.byFlag = 2;
                            }
                        }
                        else
                        {
                            stChapterInfo.byFlag = 0;
                        }
                        PackRatingEncourage(stChapterInfo.stChapterEncourage, poScoreProp);
                    }
                    dwChapterScore = 0;
                }
            }

            //////////////////////////////////////////////////////////////////////////

            byLastTownIdx = byTownIdx;
            byLastInstanceIdx = byInstanceIdx;
            poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
        }


        //////////////////////////////////////////////////////////////////////////
        //���������Ϣ��ÿ���½���������ÿ����������������
        if ((byLastTownIdx % 3 != 0) || (byLastInstanceIdx % 3 != 0))
        {
            CScore *poScore = m_poOwner->GetScore();
            if (NULL != poScore)
            {

                UINT8		byChapterIdx		= (byLastTownIdx / 3) + 1;
                SScoreProp *	poScoreProp	= CScorePropMgr::Instance()->GetScoreProp(EIT_COMMON, byChapterIdx);
                if (NULL != poScoreProp)
                {
                    stAck.byChapterNum = (UINT8)byChapterIdx;
                    DT_CHAPTER_SCORE & stChapterInfo = stAck.astChapterInfo[byChapterIdx - 1];

                    //���ʱ���Ƿ����0���������0��������ȡ����
                    if (dwChapterScore >= poScoreProp->wScore)
                    {
                        if(!poScore->IsRecvedChapter(EIT_COMMON, byChapterIdx))
                        {
                            stChapterInfo.byFlag = 1;
                        }
                        else
                        {
                            stChapterInfo.byFlag = 2;
                        }
                    }
                    else
                    {
                        stChapterInfo.byFlag = 0;
                    }
                    PackRatingEncourage(stChapterInfo.stChapterEncourage, poScoreProp);
                }
                dwChapterScore = 0;
            }
        }

        //ͳ�ƾ�Ӣ�������Ǹ���
        poInstanceRecord = m_mapEliteInstanceRecord.GetFistData();
        while(poInstanceRecord)
        {
            //ͳ������
            dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
            poInstanceRecord = m_mapEliteInstanceRecord.GetNextData();
        }

        //////////////////////////////////////////////////////////////////////////
        CScore *poScore = m_poOwner->GetScore();
        if (NULL != poScore)
        {
            //�����ֽ���
            UINT16	wGrade = 0;
            DT_ACCUMULATED_SCORE_ENCOURAGE &stDT_ACCUMULATED_SCORE_ENCOURAGE = stAck.stAccumulatedEncourage; //���۽�����Ϣ
            stDT_ACCUMULATED_SCORE_ENCOURAGE.dwCurSocre = dwCurSocre;
            CScoreAccumulatePropMap & mapScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulatePropMap();
            CScoreAccumulatePropMapItr itr;
            for (itr = mapScoreAccumulateProp.begin(); itr != mapScoreAccumulateProp.end(); itr++)
            {
                CScoreAccumulateProp &stScoreAccumulateProp = itr->second;
                if (dwCurSocre > stScoreAccumulateProp.wScore)
                {
                    if(!poScore->IsRecvedAccumulated(stScoreAccumulateProp.wGrade))
                    {
                        wGrade = stScoreAccumulateProp.wGrade;
                        stDT_ACCUMULATED_SCORE_ENCOURAGE.byFlag = 1;
                        stDT_ACCUMULATED_SCORE_ENCOURAGE.dwEncourageSocre = stScoreAccumulateProp.wScore;
                        break;
                    }
                }
                else
                {
                    wGrade = stScoreAccumulateProp.wGrade;
                    stDT_ACCUMULATED_SCORE_ENCOURAGE.byFlag = 0;
                    stDT_ACCUMULATED_SCORE_ENCOURAGE.dwEncourageSocre = stScoreAccumulateProp.wScore;
                    break;
                }
            }



            CScoreAccumulateProp *poScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulateProp(wGrade);
            if (NULL != poScoreAccumulateProp)
            {
                PackRatingEncourage(stDT_ACCUMULATED_SCORE_ENCOURAGE.stAccumulatedEncourage, poScoreAccumulateProp);
            }
        }

        //////////////////////////////////////////////////////////////////////////

        if(NULL == pstDT_TOWN_INSTANCE_RECORD_DATA_CLI)
        {
            SET_OTHER_ERR(stAck.wErrCode);
            return FALSE;
        }

        //�ó����ĸ���û���꣬��һ�������Ǹó������һ������,��ֵ��һ��������Ϣ
        if((ENIT_NEXT_INSTANCE == stNextInstance.eNextInstanceType) && ( TRUE == stNextInstance.bHaveNext) &&
                (TRUE == CkLessEqualID(stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byTownIdx, stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx, stMaxUnlockCommonInstanceID.byTownIdx, stMaxUnlockCommonInstanceID.byInstanceIdx)))
        {
            pstDT_INSTANCE_RECORD_DATA_CLI = &(pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->astInstanceInfo[byInstanceNum++]);
            pstDT_INSTANCE_RECORD_DATA_CLI->byIndex = stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx;
            pstDT_INSTANCE_RECORD_DATA_CLI->byScore = 0;

            //�쳣
            if(NULL == stNextInstance.pstInstanceProp)
            {
                SYS_CRITICAL(_SDT("[%s: %d]: CInstance::GetInstanceRecord scene not found!"), MSG_MARK);
                SET_OTHER_ERR(stAck.wErrCode)
                return FALSE;
            }
            else
            {
                pstDT_INSTANCE_RECORD_DATA_CLI->wEnterLevel = 1;//stNextInstance.pstInstanceProp->wEnterLevel;//ȥ�������ȼ�����
                memcpy(&(pstDT_INSTANCE_RECORD_DATA_CLI->stBurstItemInfo), &(stNextInstance.pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
                pstDT_INSTANCE_RECORD_DATA_CLI->dwBurstExperience = stNextInstance.pstInstanceProp->dwAllExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;
                pstDT_INSTANCE_RECORD_DATA_CLI->dwMaxMonstorPower = stNextInstance.pstInstanceProp->dwMaxMonsterPower;
            }
        }
        pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->byInstanceNum = byInstanceNum;

        //�ó����ĸ���û���꣬��һ����������һ������,��ֵ��һ��������Ϣ
        if((ENIT_NEXT_TOWN == stNextInstance.eNextInstanceType) && ( TRUE == stNextInstance.bHaveNext) &&
                (TRUE == CkLessEqualID(stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byTownIdx, stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx, stMaxUnlockCommonInstanceID.byTownIdx, stMaxUnlockCommonInstanceID.byInstanceIdx)))
        {
            pstDT_TOWN_INSTANCE_RECORD_DATA_CLI = &(stAck.astTownInstanceInfo[byTownNum++]);
            pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->byIndex = stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byTownIdx;
            DT_INSTANCE_RECORD_DATA_CLI* pstDT_INSTANCE_RECORD_DATA_CLI = &(pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->astInstanceInfo[0]);
            pstDT_INSTANCE_RECORD_DATA_CLI->byIndex = stNextInstance.stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx;
            pstDT_INSTANCE_RECORD_DATA_CLI->byScore = 0;
            pstDT_INSTANCE_RECORD_DATA_CLI->wEnterLevel = 1;//stNextInstance.pstInstanceProp->wEnterLevel;//ȥ�������ȼ�����
            pstDT_TOWN_INSTANCE_RECORD_DATA_CLI->byInstanceNum = 1;
            memcpy(&(pstDT_INSTANCE_RECORD_DATA_CLI->stBurstItemInfo), &(stNextInstance.pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
            pstDT_INSTANCE_RECORD_DATA_CLI->dwBurstExperience = stNextInstance.pstInstanceProp->dwAllExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;
            pstDT_INSTANCE_RECORD_DATA_CLI->dwMaxMonstorPower = stNextInstance.pstInstanceProp->dwMaxMonsterPower;
        }
        stAck.byTownNum = byTownNum;
    }

    return TRUE;
}


BOOL CInstance::GetEliteInstanceRecordAck(PKT_CLIGS_GET_ELITE_INSTANCE_ACK& stAck)
{
    memcpy(&stAck.stMaxInstanceData, &m_stMaxEliteInstanceID, sizeof(DT_INSTANCE_ID));

    m_poOwner->GetVipExtData().Check4ResetEliteInstance();

    DT_INSTANCE_ID* pstDT_INSTANCE_ID = GetCurMaxUnlockEliteInstanceID();

    //��ȡ��Ӣ��������

    if(NULL == m_poOwner->GetBuild(EBK_ELITEINSTANCE))
    {
        stAck.wErrCode = ERR_GET_SCENEINSTANCE::ID_SCENE_NOT_EXIST_ERR;
        return FALSE;
    }

    //��¼������
    m_poOwner->AddGuideRecord( EGF_ELITEINSTANCE);

    //�ӵ�һ����ʼ���Ҽ�¼�����ؼ�¼
    //��Ӣ����ÿ������ֻ��1������
    UINT8	byTownIdx = 1;
    UINT8	byInstandeIdx = 1;
    while((CkEliteUnlock(byTownIdx, 1)) && (byTownIdx <= MAX_TOWN_PER_SCENE_NUM))
    {
        UINT16	wScore = 0;
        byInstandeIdx = GetEliteInstanceRecordData( stAck.astTownInstanceInfo[byTownIdx - 1], stAck.astTownInstanceScoreInfo[byTownIdx - 1], byTownIdx);
        byTownIdx++;
    }

    stAck.wRemainResetNum = m_poOwner->GetVipExtData().GetRemainResetEliteInstanceNum( 1 );
    stAck.byTownNum = byTownIdx - 1;
    stAck.stEliteInstanceVipExt = GetEliteInstanceVipExt();

    stAck.wMaxResetNum = CVipPropMgr::Instance()->GetIncNum( EVINF_RESETELITEINSTANCE, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel );
    //˵���������ĳ���������
    UINT8 byDataTown = byTownIdx - 1;
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_ELITE, byDataTown, byInstandeIdx);
    if(NULL != pstInstanceProp)
    {
        stAck.wNextUnlockInstanceTownID = byDataTown;
    }
    else
    {
        pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp( EIT_ELITE, ++byDataTown, 1 );
        if( NULL != pstInstanceProp )
        {
            stAck.wNextUnlockInstanceTownID = byDataTown;
        }
    }
    //������ͨ��������������
    UINT32	dwCurSocre			=	0;
    CInstanceRecord* poInstanceRecord = m_mapCommonInstanceRecord.GetFistData();
    while(poInstanceRecord)
    {
        //ͳ������
        dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
        poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
    }

    poInstanceRecord = m_mapEliteInstanceRecord.GetFistData();
    while(poInstanceRecord)
    {
        //ͳ������
        dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
        poInstanceRecord = m_mapEliteInstanceRecord.GetNextData();
    }


    //////////////////////////////////////////////////////////////////////////

    CScore *poScore = m_poOwner->GetScore();
    if (NULL != poScore)
    {
        //�����ֽ���
        UINT16	wGrade = 0;
        DT_ACCUMULATED_SCORE_ENCOURAGE &stDT_ACCUMULATED_SCORE_ENCOURAGE = stAck.stAccumulatedEncourage; //���۽�����Ϣ
        stDT_ACCUMULATED_SCORE_ENCOURAGE.dwCurSocre = dwCurSocre;
        CScoreAccumulatePropMap & mapScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulatePropMap();
        CScoreAccumulatePropMapItr itr;
        for (itr = mapScoreAccumulateProp.begin(); itr != mapScoreAccumulateProp.end(); itr++)
        {
            CScoreAccumulateProp &stScoreAccumulateProp = itr->second;
            if (dwCurSocre > stScoreAccumulateProp.wScore)
            {
                if(!poScore->IsRecvedAccumulated(stScoreAccumulateProp.wGrade))
                {
                    wGrade = stScoreAccumulateProp.wGrade;
                    stDT_ACCUMULATED_SCORE_ENCOURAGE.byFlag = 1;
                    stDT_ACCUMULATED_SCORE_ENCOURAGE.dwEncourageSocre = stScoreAccumulateProp.wScore;
                    break;
                }
            }
            else
            {
                wGrade = stScoreAccumulateProp.wGrade;
                stDT_ACCUMULATED_SCORE_ENCOURAGE.byFlag = 0;
                stDT_ACCUMULATED_SCORE_ENCOURAGE.dwEncourageSocre = stScoreAccumulateProp.wScore;
                break;
            }
        }

        CScoreAccumulateProp *poScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulateProp(wGrade);
        if (NULL != poScoreAccumulateProp)
        {
            PackRatingEncourage(stDT_ACCUMULATED_SCORE_ENCOURAGE.stAccumulatedEncourage, poScoreAccumulateProp);
        }
    }
    return TRUE;
}

DT_ELITE_INSTANCE_VIP_EXT_DATA_CLI CInstance::GetEliteInstanceVipExt()
{
    DT_ELITE_INSTANCE_VIP_EXT_DATA_CLI data;
// 	data.wMaxResetNum=CVipPropMgr::Instance()->GetIncNum( EVINF_RESETELITEINSTANCE,
// 		m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel );
// 	data.wRemainResetNum=m_poOwner->GetRemainResetEliteInstanceNum();
// 	data.qwCurGold=m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;
//
// 	data.qwCostGold=CLuamgr::Instance()->GetFuncCost( EGCF_RESETELITEINSTANCE, m_poOwner->GetVipExtData().GetDT_VIP_EXT_DATA().wResetEliteInstanceCnt );
    data.wNextVipLevelNum = CVipPropMgr::Instance()->GetIncNum( EVINF_RESETELITEINSTANCE, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel + 1 );
    data.qwCurGold = m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;
    return data;
}

BOOL	CInstance::GetClimbTowerInstanceAck(PKT_CLIGS_OPEN_CLIMB_TOWER_ACK& stAck)
{
    //��ȡ��Ӣ��������
    stAck.stClimbTowerInfo.byEnterPhyStrength = 0;
    if(NULL == m_poOwner->GetBuild(EBK_CLIMBTOWER))
    {
        stAck.wErrCode = ERR_OPEN_CLIMB_TOWER::ID_CLIMB_TOWER_NOT_OPEN_ERR;
        return FALSE;
    }

    //������������
    m_poOwner->AddGuideRecord( EGF_CLIMBTOWER );
    stAck.stClimbTowerInfo.wIndex = EIT_TOWER;
    stAck.wErrCode = GetClimbTownInstanceInfo(stAck.stClimbTowerInfo.byMaxInstanceNum, stAck.stClimbTowerInfo.byMaxUnlockInstanceNum, stAck.stClimbTowerInfo.stCurInstanceInfo);
    return TRUE;
}

VOID CInstance::GetClimbTownInstanceNum(UINT32 &dwMaxUnlockInstanceNum, UINT32  &dwMaxInstanceNum)//������//������¼��Ϣ
{
    dwMaxInstanceNum = 0;
    dwMaxUnlockInstanceNum = 0;
    //��ȡ�������������Ϣ
    STownInstanceProp * pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, 1);
    if (NULL == pstTownInstanceProp)
    {
        return;
    }

    for (UINT32 dwInstanceIdx = 1; dwInstanceIdx <= pstTownInstanceProp->m_mapInstance.size(); dwInstanceIdx++)
    {
        SInstanceProp* pstInstanceProp = NULL;
        pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_TOWER, 1, dwInstanceIdx);
        if (NULL == pstInstanceProp)
        {
            continue;
        }
        if (pstInstanceProp->wEnterLevel <= m_poOwner->GetLevel())
        {
            dwMaxInstanceNum = pstInstanceProp->byIndex;
        }
        else
        {
            break;
        }
    }

    //��ȡ��ǰ����������Ϣ
    SInstanceProp* pstInstanceProp = NULL;
    pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_TOWER, 1, m_stMaxClimbTowerInstanceID.byInstanceIdx);
    if(pstInstanceProp)
    {
        dwMaxUnlockInstanceNum = pstInstanceProp->byIndex;
    }
    else
    {
        dwMaxUnlockInstanceNum = m_stMaxClimbTowerInstanceID.byInstanceIdx;
    }

}


UINT16	CInstance::GetClimbTownInstanceInfo(UINT8 &byMaxInstanceNum, UINT8  &byMaxUnlockInstanceNum, DT_INSTANCE_RECORD_DATA_CLI &stInstanceInfo)
{
    //��ȡ�������������Ϣ
    STownInstanceProp * pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, 1);
    if (NULL == pstTownInstanceProp)
    {
        return ERR_OPEN_CLIMB_TOWER::ID_CLIMB_TOWER_NOT_EXIST_ERR;
    }



    //if (pstTownInstanceProp->m_mapInstance.size() > MAX_INSTANCE_CLIMB_TOWER_NUM)
    //{
    //    byMaxInstanceNum  = MAX_INSTANCE_CLIMB_TOWER_NUM;
    //}
    //else
    //{
    //    byMaxInstanceNum  = pstTownInstanceProp->m_mapInstance.size();
    //}

    for (UINT32 dwInstanceIdx = 1; dwInstanceIdx <= pstTownInstanceProp->m_mapInstance.size(); dwInstanceIdx++)
    {
        SInstanceProp* pstInstanceProp = NULL;
        pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_TOWER, 1, dwInstanceIdx);
        if (NULL == pstInstanceProp)
        {
            continue;
        }
        if (pstInstanceProp->wEnterLevel <= m_poOwner->GetLevel())
        {
            byMaxInstanceNum = pstInstanceProp->byIndex;
        }
        else
        {
            break;
        }
    }



    //��ȡ��һ����δ��������Ϣ
    SInstanceProp* pstInstanceProp = NULL;
    pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_TOWER, 1, m_stMaxClimbTowerInstanceID.byInstanceIdx + 1);
    if(pstInstanceProp)
    {
        byMaxUnlockInstanceNum = pstInstanceProp->byIndex;
    }
    else
    {
        byMaxUnlockInstanceNum = m_stMaxClimbTowerInstanceID.byInstanceIdx + 1;
    }

    UINT64	qwLastPassTime	= 1;
    UINT8	byCurInstanceIdx	= 1;
    for (UINT8 byInstanceIdx = 1; byInstanceIdx <= byMaxInstanceNum; byInstanceIdx++)
    {
        //�鿴����ĸ����Ƿ��д�ͨ�ؼ�¼��
        CInstanceRecord* poInstanceRecord = NULL;
        poInstanceRecord = GetSingleInstaceRecord(EIT_TOWER, 1, byInstanceIdx);
        //û�м�¼����ֵ���ֵ
        if(NULL != poInstanceRecord)
        {
            if (qwLastPassTime <= poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime)
            {
                byCurInstanceIdx = byInstanceIdx + 1;
                qwLastPassTime = poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime;
            }
        }
        else
        {
            break;
        }
    }

    //��ȡ���򸱱��������Ϣ
    pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_TOWER, 1, byCurInstanceIdx);
    if(NULL == pstInstanceProp)
    {
        //SYS_CRITICAL(_SDT("[%s: %d]: pstInstanceProp is NULL, ID[%d.%d.%d]!"), MSG_MARK, EIT_TOWER, 1, byCurInstanceIdx); //byCurInstanceIdx = byInstanceIdx + 1 �ɳ�������
        stInstanceInfo.byIndex = byCurInstanceIdx;
        return ERR_OPEN_CLIMB_TOWER::ID_SUCCESS;
    }
    stInstanceInfo.byIndex = pstInstanceProp->byIndex;
    stInstanceInfo.byScore = 0;
    stInstanceInfo.wEnterLevel = pstInstanceProp->wEnterLevel; //ȥ�������ȼ�����
    memcpy(&(stInstanceInfo.stBurstItemInfo), &(pstInstanceProp->stPassBoxProp.stDT_BURST_ITEM_DATA), sizeof(DT_BURST_ITEM_DATA));
    stInstanceInfo.dwMaxMonstorPower = pstInstanceProp->dwMaxMonsterPower;

    stInstanceInfo.stPassEncourage.dwCoin = pstInstanceProp->stPassEncourageProp.dwCoin;
    stInstanceInfo.stPassEncourage.dwStory = pstInstanceProp->stPassEncourageProp.dwStory;
    stInstanceInfo.stPassEncourage.dwExperience = pstInstanceProp->stPassEncourageProp.dwExperience;
    if(m_poOwner->GetState().GetDT_STATE_DATA().wDoubleExpNum > 0)
    {
        stInstanceInfo.stPassEncourage.dwExperience = stInstanceInfo.stPassEncourage.dwExperience * 2;
    }

    stInstanceInfo.dwBurstExperience = 0;
    stInstanceInfo.stPassEncourage.dwExperience = 0;
    stInstanceInfo.stPassEncourage.dwCoachExperience = 0;

    return ERR_OPEN_CLIMB_TOWER::ID_SUCCESS;
}




VOID CInstance::ClrChallengeTime()
{
    //�ӵ�һ����ʼ���Ҽ�¼�����ؼ�¼
    //��Ӣ����ÿ������ֻ��1������
    UINT8 byTownIdx = 1;
    while((CkEliteUnlock(byTownIdx, 1)) && (byTownIdx <= MAX_TOWN_PER_SCENE_NUM))
    {
        CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(EIT_ELITE, byTownIdx, 1);
        //û�м�¼������
        if(NULL == poInstanceRecord)
        {
            byTownIdx++;
            continue;
        }
        //��¼���������սʱ��
        else
        {
            DT_INSTANCE_DATA& stDT_INSTANCE_DATA = poInstanceRecord->GetDT_INSTANCE_DATA();
            //������սʱ��Ϊ0
            stDT_INSTANCE_DATA.qwLastPassTime = 0;
        }
        byTownIdx++;
    }
}

UINT16 CInstance::ResetEliteTime(UINT8 byTownIdx)//������սʱ��
{
    //��ȡ������Ϣ
    STownInstanceProp* pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_ELITE, byTownIdx);
    if (NULL == pstTownInstanceProp)
    {
        return ERR_RESET_ELITE_INSTANCE::ID_TOWN_NOT_EXIST;
    }

    //�����������þ�Ӣ����
    if( m_poOwner->GetVipExtData().GetRemainResetEliteInstanceNum(byTownIdx) == 0 )
    {
        return ERR_RESET_ELITE_INSTANCE::ID_INDEX_ERROR;
    }

    UINT16 wCostGold = 0;
    wCostGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_RESETELITEINSTANCE, m_poOwner->GetVipExtData().GetResetEliteInstanceNum( byTownIdx ), byTownIdx);

    if( wCostGold > m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold )
    {
        return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
    }

    if( !m_poOwner->GetVipExtData().ResetEliteInstance( byTownIdx ) )
    {
        return ERR_RESET_ELITE_INSTANCE::ID_RESET_ERROR;
    }
    m_poOwner->DecGold( wCostGold, CRecordMgr::EDGT_GOLDRESETELITINSTANCE );
	CPlayerMedal* poPlayerMedal = m_poOwner->GetPlayerMedal();
	if ( NULL != poPlayerMedal)
	{
		poPlayerMedal->AddEliteInstanceResetNum();
		poPlayerMedal->CheckMedalBySmallType(EMST_RESET_ELITEINSTANCE);
	}
    return ERR_RESET_ELITE_INSTANCE::ID_SUCCESS;
}

VOID CInstance::GetEliteInstanceData( PKT_CLIGS_RESET_ELITE_INSTANCE_ACK &ackData, UINT8 byIndex )
{
    //PKT_CLIGS_RESET_ELITE_INSTANCE_ACK sceneAck;
    //GetEliteInstanceData( ackData );
    //ackData.stPromptInfo=sceneAck.stPromptInfo;
    //ackData.wErrCode=sceneAck.wErrCode;
    ackData.stEliteInstanceVipExt = GetEliteInstanceVipExt();
    ackData.wRemainResetNum = m_poOwner->GetVipExtData().GetRemainResetEliteInstanceNum( byIndex );
    ackData.byIndex = byIndex;
    ackData.qwCostGold = CLuamgr::Instance()->GetFuncCost(m_poOwner, EGCF_RESETELITEINSTANCE, m_poOwner->GetVipExtData().GetResetEliteInstanceNum( byIndex ), byIndex );
    ackData.wMaxResetNum = CVipPropMgr::Instance()->GetIncNum( EVINF_RESETELITEINSTANCE, m_poOwner->GetDT_PLAYER_BASE_DATA().byVipLevel );
    ackData.stPromptInfo;
}

UINT16 CInstance::ResetChallengeTime(UINT8 byTownIdx)//������սʱ��
{
    //��ȡ������Ϣ
    STownInstanceProp* pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, byTownIdx);
    if (NULL == pstTownInstanceProp)
    {
        return ERR_CLIMB_TOWER_RESET::ID_NOT_TOWER;
    }

    //�ӵ�һ����ʼ���Ҽ�¼�����ؼ�¼
    SInstanceProp *pstInstanceProp = NULL;
    CInstanceRecord* poInstanceRecord = NULL;
    CIndex2InstancePropMapItr itr = pstTownInstanceProp->m_mapInstance.begin();
    for (itr = pstTownInstanceProp->m_mapInstance.begin(); itr != pstTownInstanceProp->m_mapInstance.end(); itr++)
    {
        pstInstanceProp = itr->second;
        if (NULL == pstInstanceProp)
        {
            continue;
        }
        poInstanceRecord = GetSingleInstaceRecord(EIT_TOWER, byTownIdx, pstInstanceProp->byIndex);
        if (NULL == poInstanceRecord)
        {
            continue;//û�м�¼������
        }

        poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime = 0;//������սʱ��Ϊ0
    }
    return ERR_CLIMB_TOWER_RESET::ID_SUCCESS;
}

//��鸱��ID�Ƿ�С�ڵ���
BOOL CInstance::CkLessEqualID(UINT8 byTownIdx, UINT8 byInstanceIdx, UINT8 byTargeTownIdx, UINT8 byTargeInstanceIdx)
{
    if((byTownIdx < byTargeTownIdx) ||
            ((byTownIdx == byTargeTownIdx)  && (byInstanceIdx <= byTargeInstanceIdx)))
    {
        return TRUE;
    }

    return FALSE;
}


VOID CInstance::GenEncInfo(UINT8& byHaveBoxFlag, DT_PASS_ENCOURAGE_BOX_DATA& stBoxInfo, DT_HERO_UPGRADE_DATA_LIST& stHeroUpgradeInfo)
{
    DT_STATE_DATA& stDT_STATE_DATA = m_poOwner->GetState().GetDT_STATE_DATA();
    if((TRUE == m_stCurBattleInstance.bPass) && (0 == stDT_STATE_DATA.byOpenBoxFlag))
    {
        byHaveBoxFlag = 1;

        SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(m_stCurBattleInstance.wSceneIdx, m_stCurBattleInstance.byTownIdx, m_stCurBattleInstance.byInstanceIdx);
        if(NULL == pstInstanceProp)
        {
            return ;
        }
        UINT8 abyHitItemIdx[MAX_ENCOURAGE_BOX_GROUP_NUM] = {0};
        memcpy(&abyHitItemIdx, &m_poOwner->GetState().GetDT_STATE_DATA().abyHitItemIdx, sizeof(abyHitItemIdx));
        CItemGroupMap& mapItemGroup = pstInstanceProp->stPassBoxProp.mapItemGroup;
        UINT8 byGroupNum = 0;
        for(CItemGroupMapItr itrGoup = mapItemGroup.begin(); ((itrGoup != mapItemGroup.end()) && (byGroupNum < MAX_ENCOURAGE_BOX_GROUP_NUM)); itrGoup++, byGroupNum++)
        {
            UINT16 wItemKindID = 0;
            UINT16 wPileNum = 0;
            UINT8 byHitItemIdx = abyHitItemIdx[byGroupNum];
            DT_PASS_ENCOURAGE_BOX_GROUP_DATA& stBoxGroupInfo = stBoxInfo.astBoxGroupInfo[byGroupNum];
            DT_ITEM_DATA_LIST_CLI& stBoxItem = itrGoup->second.stBoxItem;
            if((0 != byHitItemIdx) && (byHitItemIdx <= stBoxItem.byItemNum)) //0��ʾδ����
            {
                DT_ITEM_DATA_CLI& stDT_ITEM_DATA_CLI = stBoxItem.astItemList[byHitItemIdx - 1];
                wItemKindID = stDT_ITEM_DATA_CLI.wKindID;
                wPileNum = stDT_ITEM_DATA_CLI.wPileNum;
            }
            else
            {
                byHitItemIdx = 0; //����byHitItemIdxֵ�쳣
            }

            SGoodsProp* pstGoodsProp = CGoodsPropMgr::Instance()->GetPropByPrimaryKey(wItemKindID);
            if(pstGoodsProp)
            {
                switch(pstGoodsProp->byMainKindID)
                {
                case EGMK_COIN:
                {
                    UINT32 dwValue = pstGoodsProp->dwValue * wPileNum;
                    stBoxGroupInfo.dwCoin = dwValue;
                }
                break;
                case EGMK_GOLD:
                {
                    UINT32 dwValue = pstGoodsProp->dwValue * wPileNum;
                    stBoxGroupInfo.dwGold = dwValue;
                }
                break;
                }
            }

            stBoxGroupInfo.byHitItemIdx = byHitItemIdx;
            memcpy(&stBoxGroupInfo.stItemInfo, &stBoxItem, sizeof(DT_ITEM_DATA_LIST_CLI));
        }
        stBoxInfo.byGroupNum = byGroupNum;

        stHeroUpgradeInfo.byUpgradeHeroNum = m_poOwner->GetState().GetDT_STATE_DATA().byUpgradeHeroNum;
        memcpy(stHeroUpgradeInfo.astHeroUpgradeInfo, m_poOwner->GetState().GetDT_STATE_DATA().astHeroUpgradeInfo, sizeof(stHeroUpgradeInfo.astHeroUpgradeInfo));
    }
}

UINT16 CInstance::GetMaxPassClimbTower()
{
    //��ȡ�������������Ϣ
    STownInstanceProp * pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, 1);
    if (NULL == pstTownInstanceProp)
    {
        return 0;
    }

    UINT8 byMaxInstanceNum = 0;
    if (pstTownInstanceProp->m_mapInstance.size() > MAX_INSTANCE_CLIMB_TOWER_NUM)
    {
        byMaxInstanceNum  = MAX_INSTANCE_CLIMB_TOWER_NUM;
    }
    else
    {
        byMaxInstanceNum  = pstTownInstanceProp->m_mapInstance.size();
    }

    UINT8 byPassInstanceIdx = 0;
    for (UINT8 byInstanceIdx = 1; byInstanceIdx <= byMaxInstanceNum; byInstanceIdx++)
    {
        //�鿴����ĸ����Ƿ��д�ͨ�ؼ�¼��
        CInstanceRecord* poInstanceRecord = NULL;
        poInstanceRecord = GetSingleInstaceRecord(EIT_TOWER, 1, byInstanceIdx);

        if(NULL == poInstanceRecord)
        {
            break;
        }
        byPassInstanceIdx = byInstanceIdx;
    }
    return byPassInstanceIdx;
}

UINT8 CInstance::GetAlreadyBattleMaxIndex( UINT8 byTownIdx )
{
    UINT8 byInstanceIndex = 0;
    while((CkEliteUnlock(byTownIdx, byInstanceIndex + 1)) && (byInstanceIndex <= MAX_INSTANCE_PER_TOWN_NUM))
    {
        CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(EIT_ELITE, byTownIdx, byInstanceIndex + 1);
        //û�м�¼����ֵ���ֵ
        if(NULL == poInstanceRecord)
        {
            SInstanceProp* pstProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_ELITE, byTownIdx, byInstanceIndex + 1);
            if(NULL == pstProp)
            {
                break;
            }

        }
        byInstanceIndex++;
    }

    return byInstanceIndex;
}

UINT16 CInstance::GetCurrentClimbTower()
{
    STownInstanceProp * pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_TOWER, 1);
    if (NULL == pstTownInstanceProp)
    {
        return 0;
    }

    UINT8	byCurInstance		=	1;
    UINT64	qwLastPassTime	=	1;
    for (UINT8 byInstanceIdx = 1; byInstanceIdx <= pstTownInstanceProp->m_mapInstance.size() && byInstanceIdx < MAX_INSTANCE_CLIMB_TOWER_NUM; byInstanceIdx++)
    {
        //�鿴����ĸ����Ƿ��д�ͨ�ؼ�¼��
        CInstanceRecord* poInstanceRecord = NULL;
        poInstanceRecord = GetSingleInstaceRecord(EIT_TOWER, 1 , byInstanceIdx);
        //û�м�¼����ֵ���ֵ
        if(NULL != poInstanceRecord)
        {
            if (qwLastPassTime <= poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime)
            {
                byCurInstance		= byInstanceIdx + 1;
                qwLastPassTime	= poInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime;
            }
        }
        else
        {
            break;
        }
    }
    return byCurInstance;
}



UINT16	CInstance::RecvRatingEncourageReq(UINT16 wSceneIdx, UINT8 byType, UINT16 wChapterIdx, DT_ACCUMULATED_SCORE_ENCOURAGE &stAccumulatedEncourage)
{
    CScore *poScore = m_poOwner->GetScore();
    if (NULL == poScore)
    {
        return ERR_RECV_RATING_ENCOURAGE::ID_SUCCESS;
    }

    if (EIT_ELITE == wSceneIdx)
    {
        if (em_Chaper == byType)
        {
            UINT16	wScore			=	0;
            UINT8	byInstandeIdx		= 1;
            while( byInstandeIdx < MAX_INSTANCE_PER_TOWN_NUM && (CkEliteUnlock((UINT8)wChapterIdx, byInstandeIdx) ) )
            {

                CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(EIT_ELITE, (UINT8)wChapterIdx, byInstandeIdx);
                //��¼���ڣ���ֵ��¼ֵ
                if(NULL != poInstanceRecord)
                {
                    DT_INSTANCE_DATA& stDT_INSTANCE_DATA = poInstanceRecord->GetDT_INSTANCE_DATA();
                    //�ۻ�����
                    wScore	+= stDT_INSTANCE_DATA.byScore;
                }
                else
                {
                    return ERR_RECV_RATING_ENCOURAGE::ID_NOT_THROUGH;//δȫ��ͨ��
                }
                byInstandeIdx++;
            }

            SScoreProp *poScoreProp = CScorePropMgr::Instance()->GetScoreProp(EIT_ELITE, wChapterIdx);
            if (NULL != poScoreProp)
            {
                //���ʱ���Ƿ����0���������0��������ȡ����
                if(poScore->IsRecvedChapter(EIT_ELITE, wChapterIdx))
                {
                    return ERR_RECV_RATING_ENCOURAGE::ID_ENCOURAGE_RECEVED;
                }

                if (wScore < poScoreProp->wScore)
                {
                    return ERR_RECV_RATING_ENCOURAGE::ID_RAGING_NOT_ENOUGH;
                }

                //��ⱳ���Ƿ�����
                vector<UINT16> vecItemID;
                for(UINT8 byNum = 0; byNum < poScoreProp->byNum; byNum++)
                {
                    if (ACTE_GOOD == poScoreProp->astValue[byNum].byType)
                    {
                        vecItemID.push_back(poScoreProp->astValue[byNum].dwValue);
                    }
                }

                if(CItemMgr::Instance()->CkBagFull(m_poOwner, vecItemID))
                {
                    return ERR_RECV_RATING_ENCOURAGE::ID_BAGFUL;
                }

                GetRatingEncourage(poScoreProp);
                poScore->AddRecvedChapter(EIT_ELITE, poScoreProp->wChapterIdx);
            }
        }
        else if (em_Accumulated == byType)
        {
            UINT32	dwCurSocre			=	0;
            CInstanceRecord* poInstanceRecord = m_mapCommonInstanceRecord.GetFistData();
            while(poInstanceRecord)
            {
                //ͳ������
                dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
                poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
            }

            poInstanceRecord = m_mapEliteInstanceRecord.GetFistData();
            while(poInstanceRecord)
            {
                //ͳ������
                dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
                poInstanceRecord = m_mapEliteInstanceRecord.GetNextData();
            }

            UINT16	wGrade = 0;
            CScoreAccumulatePropMap & mapScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulatePropMap();
            CScoreAccumulatePropMapItr itr;
            for (itr = mapScoreAccumulateProp.begin(); itr != mapScoreAccumulateProp.end(); itr++)
            {
                CScoreAccumulateProp &stScoreAccumulateProp = itr->second;
                //�����۵������Ƿ�ﵽָ���ĸ���
                if (dwCurSocre > stScoreAccumulateProp.wScore)
                {
                    //����Ƿ�����ȡ����
                    if(!poScore->IsRecvedAccumulated(stScoreAccumulateProp.wGrade))
                    {
                        //��ⱳ���Ƿ�����
                        vector<UINT16> vecItemID;
                        for(UINT8 byNum = 0; byNum < stScoreAccumulateProp.byNum; byNum++)
                        {
                            if (ACTE_GOOD == stScoreAccumulateProp.astValue[byNum].byType)
                            {
                                vecItemID.push_back(stScoreAccumulateProp.astValue[byNum].dwValue);
                            }
                        }

                        if(CItemMgr::Instance()->CkBagFull(m_poOwner, vecItemID))
                        {
                            return ERR_RECV_RATING_ENCOURAGE::ID_BAGFUL;
                        }

                        GetRatingEncourage(&stScoreAccumulateProp);
                        poScore->AddRecvedAccumulated(stScoreAccumulateProp.wGrade);
                    }
                }
                else
                {
                    return ERR_RECV_RATING_ENCOURAGE::ID_RAGING_NOT_ENOUGH;
                }
            }
            //���¼������ȡ�Ļ������ǽ���
            stAccumulatedEncourage.dwCurSocre = dwCurSocre;
            for (itr = mapScoreAccumulateProp.begin(); itr != mapScoreAccumulateProp.end(); itr++)
            {
                CScoreAccumulateProp &stScoreAccumulateProp = itr->second;

                if (dwCurSocre > stScoreAccumulateProp.wScore)
                {
                    if(!poScore->IsRecvedAccumulated(stScoreAccumulateProp.wGrade))
                    {
                        wGrade = stScoreAccumulateProp.wGrade;
                        stAccumulatedEncourage.byFlag = 1;
                        stAccumulatedEncourage.dwEncourageSocre = stScoreAccumulateProp.wScore;
                        break;
                    }
                }
                else
                {
                    wGrade = stScoreAccumulateProp.wGrade;
                    stAccumulatedEncourage.byFlag = 0;
                    stAccumulatedEncourage.dwEncourageSocre = stScoreAccumulateProp.wScore;
                    break;
                }
            }

            CScoreAccumulateProp *poScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulateProp(wGrade);
            if (NULL != poScoreAccumulateProp)
            {
                PackRatingEncourage(stAccumulatedEncourage.stAccumulatedEncourage, poScoreAccumulateProp);
            }
        }
        else
        {
            return ERR_RECV_RATING_ENCOURAGE::ID_TYPE_NOT_EXIT;
        }

    }
    else if (EIT_COMMON == wSceneIdx)
    {
        if (em_Chaper == byType)
        {
            UINT16	wScore			=	0;
            CInstanceRecord* poInstanceRecord = m_mapCommonInstanceRecord.GetFistData();
            while(poInstanceRecord)
            {
                //����ID��С��1��ʼ
                UINT8 byTownIdx		= poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID.byTownIdx;
                UINT8 byInstanceIdx	= poInstanceRecord->GetDT_INSTANCE_DATA().stInstanceID.byInstanceIdx;
                if (((byTownIdx - 1) / 3 + 1) == wChapterIdx)
                {
                    //ͳ������
                    wScore += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
                    //////////////////////////////////////////////////////////////////////////
                    //���������Ϣ��ÿ���½���������ÿ����������������
                    if (byTownIdx && byInstanceIdx && byTownIdx / 3 == wChapterIdx && byInstanceIdx == 3)
                    {
                        UINT16	wChapterIdx = byTownIdx / 3;
                        SScoreProp *poScoreProp = CScorePropMgr::Instance()->GetScoreProp(EIT_COMMON, wChapterIdx);
                        if (NULL != poScoreProp)
                        {
                            //���ʱ���Ƿ����0���������0��������ȡ����
                            if(poScore->IsRecvedChapter(EIT_COMMON, wChapterIdx))
                            {
                                return ERR_RECV_RATING_ENCOURAGE::ID_ENCOURAGE_RECEVED;
                            }

                            if (wScore < poScoreProp->wScore)
                            {
                                return ERR_RECV_RATING_ENCOURAGE::ID_RAGING_NOT_ENOUGH;
                            }

                            //��ⱳ���Ƿ�����
                            vector<UINT16> vecItemID;
                            for(UINT8 byNum = 0; byNum < poScoreProp->byNum; byNum++)
                            {
                                if (ACTE_GOOD == poScoreProp->astValue[byNum].byType)
                                {
                                    vecItemID.push_back(poScoreProp->astValue[byNum].dwValue);
                                }
                            }

                            if(CItemMgr::Instance()->CkBagFull(m_poOwner, vecItemID))
                            {
                                return ERR_RECV_RATING_ENCOURAGE::ID_BAGFUL;
                            }

                            GetRatingEncourage(poScoreProp);

                            poScore->AddRecvedChapter(EIT_COMMON, poScoreProp->wChapterIdx);
                        }
                    }
                }
                poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
            }
        }
        else if (em_Accumulated == byType)
        {
            UINT32	dwCurSocre			=	0;
            CInstanceRecord* poInstanceRecord = m_mapCommonInstanceRecord.GetFistData();
            while(poInstanceRecord)
            {
                //ͳ������
                dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
                poInstanceRecord = m_mapCommonInstanceRecord.GetNextData();
            }

            poInstanceRecord = m_mapEliteInstanceRecord.GetFistData();
            while(poInstanceRecord)
            {
                //ͳ������
                dwCurSocre += poInstanceRecord->GetDT_INSTANCE_DATA().byScore;
                poInstanceRecord = m_mapEliteInstanceRecord.GetNextData();
            }

            UINT16	wGrade = 0;
            CScoreAccumulatePropMap & mapScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulatePropMap();
            CScoreAccumulatePropMapItr itr;
            for (itr = mapScoreAccumulateProp.begin(); itr != mapScoreAccumulateProp.end(); itr++)
            {
                CScoreAccumulateProp &stScoreAccumulateProp = itr->second;
                //�����۵������Ƿ�ﵽָ���ĸ���
                if (dwCurSocre > stScoreAccumulateProp.wScore)
                {
                    //����Ƿ�����ȡ����
                    if(!poScore->IsRecvedAccumulated(stScoreAccumulateProp.wGrade))
                    {
                        //��ⱳ���Ƿ�����
                        vector<UINT16> vecItemID;
                        for(UINT8 byNum = 0; byNum < stScoreAccumulateProp.byNum; byNum++)
                        {
                            if (ACTE_GOOD == stScoreAccumulateProp.astValue[byNum].byType)
                            {
                                vecItemID.push_back(stScoreAccumulateProp.astValue[byNum].dwValue);
                            }
                        }

                        if(CItemMgr::Instance()->CkBagFull(m_poOwner, vecItemID))
                        {
                            return ERR_RECV_RATING_ENCOURAGE::ID_BAGFUL;
                        }

                        GetRatingEncourage(&stScoreAccumulateProp);

                        poScore->AddRecvedAccumulated(stScoreAccumulateProp.wGrade);
                        break;
                    }
                }
                else
                {
                    return ERR_RECV_RATING_ENCOURAGE::ID_RAGING_NOT_ENOUGH;
                }
            }

            //���¼������ȡ�Ļ������ǽ���
            stAccumulatedEncourage.dwCurSocre = dwCurSocre;
            for (itr = mapScoreAccumulateProp.begin(); itr != mapScoreAccumulateProp.end(); itr++)
            {
                CScoreAccumulateProp &stScoreAccumulateProp = itr->second;
                if (dwCurSocre > stScoreAccumulateProp.wScore)
                {
                    if(!poScore->IsRecvedAccumulated(stScoreAccumulateProp.wGrade))
                    {
                        wGrade = stScoreAccumulateProp.wGrade;
                        stAccumulatedEncourage.byFlag = 1;
                        stAccumulatedEncourage.dwEncourageSocre = stScoreAccumulateProp.wScore;
                        break;
                    }
                }
                else
                {
                    wGrade = stScoreAccumulateProp.wGrade;
                    stAccumulatedEncourage.byFlag = 0;
                    stAccumulatedEncourage.dwEncourageSocre = stScoreAccumulateProp.wScore;
                    break;
                }
            }

            CScoreAccumulateProp *poScoreAccumulateProp = CScorePropMgr::Instance()->GetScoreAccumulateProp(wGrade);
            if (NULL != poScoreAccumulateProp)
            {
                PackRatingEncourage(stAccumulatedEncourage.stAccumulatedEncourage, poScoreAccumulateProp);
            }
        }
        else
        {
            return ERR_RECV_RATING_ENCOURAGE::ID_TYPE_NOT_EXIT;
        }
    }
    else
    {
        return ERR_RECV_RATING_ENCOURAGE::ID_SCREEN_NOT_EXIT;
    }
    return ERR_RECV_RATING_ENCOURAGE::ID_SUCCESS;
}


BOOL CInstance::GetRatingEncourage(SScoreProp * poScoreProp)
{

    CItem* poItem	 = NULL;
    ECreateItemRet ItemRet = ECIR_SUCCESS;
    for (UINT8 byNum = 0; byNum < poScoreProp->byNum; byNum++)
    {
        CValue &stValue = poScoreProp->astValue[byNum];
        switch(stValue.byType)
        {
        case	ACTE_GOOD://��Ʒ
            ItemRet = ECIR_SUCCESS;
            poItem = CItemMgr::Instance()->CreateItemIntoBag(m_poOwner, stValue.dwValue, stValue.byNum, ItemRet, 0, CRecordMgr::EAIT_RATING_SCORE);
            if(NULL == poItem)
            {
                SYS_CRITICAL(_SDT("[%s: %d]: CreateItem failed[%d], ItemKindID=%d !"), MSG_MARK, ItemRet, stValue.dwValue);
            }
            break;
        case	ACTE_HERO://�佫
            break;
        case	ACTE_COIN://ͭǮ
            m_poOwner->AddCoin(stValue.dwValue, CRecordMgr::EACT_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_GOLD://Ԫ��
            m_poOwner->AddGold(stValue.dwValue, CRecordMgr::EGGT_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_PHYSTRENGTH://����
            m_poOwner->AddPhyStrength(stValue.dwValue, CRecordMgr::EAPST_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_SCIENCE://�����
            m_poOwner->AddScience(stValue.dwValue, CRecordMgr::EAST_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_STORY://����
            m_poOwner->AddStory(stValue.dwValue, CRecordMgr::EASTT_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_BLUEGAS://����
            m_poOwner->AddBlueGas(stValue.dwValue, CRecordMgr::EABGT_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_PRUPLEGAS://����
            m_poOwner->AddPurpleGas(stValue.dwValue, CRecordMgr::EAPGT_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        case	ACTE_JINGJIE://����
            m_poOwner->AddJingJie(stValue.dwValue, CRecordMgr::EAJT_RATING_SCORE, poScoreProp->wSceneIdx, poScoreProp->wChapterIdx, poScoreProp->wScore);
            break;
        default:
            break;
        }
    }
    return TRUE;
}


BOOL	CInstance::GetRatingEncourage(CScoreAccumulateProp * poScoreAccumulateProp)
{
    CItem* poItem	 = NULL;
    ECreateItemRet ItemRet = ECIR_SUCCESS;
    for (UINT8 byNum = 0; byNum < poScoreAccumulateProp->byNum; byNum++)
    {
        CValue &stValue = poScoreAccumulateProp->astValue[byNum];
        switch(stValue.byType)
        {
        case	ACTE_GOOD://��Ʒ
            ItemRet = ECIR_SUCCESS;
            poItem = CItemMgr::Instance()->CreateItemIntoBag(m_poOwner, stValue.dwValue, stValue.byNum, ItemRet, 0, CRecordMgr::EAIT_RATING_SCORE_ACCUMULATE);
            if(NULL == poItem)
            {
                SYS_CRITICAL(_SDT("[%s: %d]: CreateItem failed[%d], ItemKindID=%d !"), MSG_MARK, ItemRet, stValue.dwValue);
            }
            break;
        case	ACTE_HERO://�佫
            break;
        case	ACTE_COIN://ͭǮ
            m_poOwner->AddCoin(stValue.dwValue, CRecordMgr::EACT_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_GOLD://Ԫ��
            m_poOwner->AddGold(stValue.dwValue, CRecordMgr::EGGT_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_PHYSTRENGTH://����
            m_poOwner->AddPhyStrength(stValue.dwValue, CRecordMgr::EAPST_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_SCIENCE://�����
            m_poOwner->AddScience(stValue.dwValue, CRecordMgr::EAST_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_STORY://����
            m_poOwner->AddStory(stValue.dwValue, CRecordMgr::EASTT_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_BLUEGAS://����
            m_poOwner->AddBlueGas(stValue.dwValue, CRecordMgr::EABGT_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_PRUPLEGAS://����
            m_poOwner->AddPurpleGas(stValue.dwValue, CRecordMgr::EAPGT_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        case	ACTE_JINGJIE://����
            m_poOwner->AddJingJie(stValue.dwValue, CRecordMgr::EAJT_RATING_SCORE_ACCUMULATE, poScoreAccumulateProp->wGrade, poScoreAccumulateProp->wScore);
            break;
        default:
            break;
        }
    }
    return TRUE;
}


BOOL	CInstance::PackRatingEncourage(DT_ENCOURAGE_DATA & stChapterEncourage, SScoreProp * poScoreProp)
{
    for (UINT8 byNum = 0; byNum < poScoreProp->byNum; byNum++)
    {
        CValue &stValue = poScoreProp->astValue[byNum];
        switch(stValue.byType)
        {
        case ACTE_GOOD:
        {
            DT_ITEM_DATA_CLI2 & astItemInfoList = stChapterEncourage.astItemInfoList[stChapterEncourage.byItemNum++];
            CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(stValue.dwValue, stValue.byNum, astItemInfoList);
        }
        break;
        case ACTE_HERO:
            break;
        case ACTE_COIN:
            stChapterEncourage.dwCoin = stValue.dwValue;
            break;
        case ACTE_GOLD:
            stChapterEncourage.dwGold = stValue.dwValue;
            break;
        case ACTE_PHYSTRENGTH:
            stChapterEncourage.wPhyStrength = stValue.dwValue;
            break;
        case ACTE_SCIENCE:
            stChapterEncourage.dwScience = stValue.dwValue;
            break;
        case ACTE_STORY:
            stChapterEncourage.dwStory = stValue.dwValue;
            break;
        case ACTE_BLUEGAS:
            stChapterEncourage.dwBlueGas = stValue.dwValue;
            break;
        case ACTE_PRUPLEGAS:
            stChapterEncourage.dwPurpleGas = stValue.dwValue;
            break;
        case ACTE_JINGJIE:
            stChapterEncourage.dwJingJie = stValue.dwValue;
            break;
        default:
            break;
        }
    }
    return TRUE;
}

BOOL	CInstance::PackRatingEncourage(DT_ENCOURAGE_DATA & stAccumulatedEncourage, CScoreAccumulateProp * poScoreAccumulateProp)
{
    for (UINT8 byNum = 0; byNum < poScoreAccumulateProp->byNum; byNum++)
    {
        CValue &stValue = poScoreAccumulateProp->astValue[byNum];
        switch(stValue.byType)
        {
        case ACTE_GOOD:
        {
            DT_ITEM_DATA_CLI2 & astItemInfoList = stAccumulatedEncourage.astItemInfoList[stAccumulatedEncourage.byItemNum++];
            CItemMgr::Instance()->GetDT_ITEM_DATA_CLI2(stValue.dwValue, stValue.byNum, astItemInfoList);
        }
        break;
        case ACTE_HERO:
            break;
        case ACTE_COIN:
            stAccumulatedEncourage.dwCoin = stValue.dwValue;
            break;
        case ACTE_GOLD:
            stAccumulatedEncourage.dwGold = stValue.dwValue;
            break;
        case ACTE_PHYSTRENGTH:
            stAccumulatedEncourage.wPhyStrength = stValue.dwValue;
            break;
        case ACTE_SCIENCE:
            stAccumulatedEncourage.dwScience = stValue.dwValue;
            break;
        case ACTE_STORY:
            stAccumulatedEncourage.dwStory = stValue.dwValue;
            break;
        case ACTE_BLUEGAS:
            stAccumulatedEncourage.dwBlueGas = stValue.dwValue;
            break;
        case ACTE_PRUPLEGAS:
            stAccumulatedEncourage.dwPurpleGas = stValue.dwValue;
            break;
        case ACTE_JINGJIE:
            stAccumulatedEncourage.dwJingJie = stValue.dwValue;
            break;
        default:
            break;
        }
    }
    return TRUE;
}


VOID CInstance::AddFailedRecord(UINT16 wScenceIdx, UINT8 byTownIdx, UINT8 byInstanceIdx)
{
    CInstanceRecord* poInstanceRecord = GetSingleInstaceRecord(wScenceIdx, byTownIdx, byInstanceIdx, FALSE);
    if(poInstanceRecord)
    {
        DT_INSTANCE_DATA& stDT_INSTANCE_DATA = poInstanceRecord->GetDT_INSTANCE_DATA();
        stDT_INSTANCE_DATA.dwFailedNum++;
        stDT_INSTANCE_DATA.wLastConFailedNum++;
        if(stDT_INSTANCE_DATA.wLastConFailedNum > stDT_INSTANCE_DATA.wMaxConFailedNum)
        {
            stDT_INSTANCE_DATA.wMaxConFailedNum = stDT_INSTANCE_DATA.wLastConFailedNum;
        }

        return;
    }

    CInstanceRecordShmemMap* pmapCommonInstanceRecord = NULL;
    if(EIT_COMMON == wScenceIdx)
    {
        pmapCommonInstanceRecord = &m_mapCommonInstanceRecord;
    }
    else if(EIT_ELITE == wScenceIdx)
    {
        pmapCommonInstanceRecord = &m_mapEliteInstanceRecord;
    }
    else if (EIT_TOWER == wScenceIdx)
    {
        pmapCommonInstanceRecord = &m_mapClimbTowerInstanceRecord;
    }
	else if(EIT_OUT_BOUND == wScenceIdx)
	{
		return ;
	}

    poInstanceRecord = CInstanceMgr::Instance()->CreatInstanceRecord(m_poOwner->GetID(), wScenceIdx, byTownIdx, byInstanceIdx);
    if(NULL == poInstanceRecord)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: create InstanceRecord failed!"), MSG_MARK);
        return;
    }
    DT_INSTANCE_DATA stDT_INSTANCE_DATA = {0};
    stDT_INSTANCE_DATA.dwFailedNum = 1;
    stDT_INSTANCE_DATA.wLastConFailedNum = 1;
    stDT_INSTANCE_DATA.wMaxConFailedNum = 1;
    stDT_INSTANCE_DATA.stInstanceID.wSceneIdx = wScenceIdx;
    stDT_INSTANCE_DATA.stInstanceID.byTownIdx = byTownIdx;
    stDT_INSTANCE_DATA.stInstanceID.byInstanceIdx = byInstanceIdx;
    if(FALSE == poInstanceRecord->Init(&stDT_INSTANCE_DATA, m_poOwner))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InstanceRecord init  failed!"), MSG_MARK);
        CInstanceMgr::Instance()->RemoveInsanceRecord(m_poOwner->GetID(), wScenceIdx, byTownIdx, byInstanceIdx);
        return;
    }
    pmapCommonInstanceRecord->AddData(CLogicFunc::GetInstanceIdxKey(wScenceIdx, byTownIdx, byInstanceIdx), poInstanceRecord);
}

UINT8 CInstance::GetInstanceStateByNeiDan(UINT8 byTownIdx)
{
	UINT8 byMaxInstanceIdx = CInstancePropMgr::Instance()->GetMaxNaiDanInstanceIdx();
	CInstanceRecord* poRecord = m_mapNeiDanInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(EIT_NEIDAN, byTownIdx, byMaxInstanceIdx));
	if ( NULL != poRecord)
	{
		return 1;//ͨ��
	}
	SInstanceProp* poInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(EIT_NEIDAN, byTownIdx, 1);
	if ( NULL == poInstanceProp)
	{
		return 2;//������ս
	}
	if ( m_poOwner->GetLevel() < poInstanceProp->wEnterLevel)
	{
		return 2;
	}
	if ( 1 != byTownIdx)
	{
		poRecord = m_mapNeiDanInstanceRecord.GetData(CLogicFunc::GetInstanceIdxKey(EIT_NEIDAN, byTownIdx - 1, byMaxInstanceIdx));
		if ( NULL != poRecord)
		{
			return 0;//����ս
		}
	}
	else
	{
		return 0;
	}
	return 2;
}

UINT16 CInstance::GetNeiDanCanBattleNum()
{
	UINT16 wAlreadPassNum = m_poOwner->GetFewParam().GetDT_FEW_PARAM_DATA().wPassNaiDanNum;
	UINT16 wMaxPassNum = CSinglePramMgr::Instance()->GetNeiDanInstanceNum();
	return wMaxPassNum < wAlreadPassNum ? 0 : wMaxPassNum - wAlreadPassNum;
}