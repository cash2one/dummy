#include <sdutil.h>
#include <common/client/commondef.h>
#include <common/server/utility.h>
#include <logic/base/dbconfig.h>
#include <common/client/errdef.h>
#include <logic/other/singleprammgr.h>
#include <logic/event/timereventmgr.h>
#include <logic/other/phystrengthmgr.h>
#include <logic/onhook/onhook.h>
#include <logic/bag/bag.h>
#include <logic/vip/vippropmgr.h>
#include "onhookmgr.h"
#include <logic/record/recordmgr.h>
#include <framework/gsapi.h>
#include <db/dbmgr.h>
#include <logic/player/player.h>

IMPLEMENT_SINGLETON(COnhookMgr);

COnhookMgr::COnhookMgr()
{
    memset(&m_stOnHookProp, 0, sizeof(m_stOnHookProp));
}

COnhookMgr::~COnhookMgr()
{
}

BOOL COnhookMgr::Init()
{
    return LoadFromDB();
}

VOID COnhookMgr::UnInit()
{

}


// ������Դ��ȡ����
BOOL COnhookMgr::LoadFromDB()
{
    return TRUE;//�Ѿ�����
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetCfgDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }
    SGDP::ISDDBRecordSet* pRes = NULL;
    UINT32 dwErrID = 0;
    string strErr;
    INT32 nRet = pDBSession->ExecuteSqlRs(GetPropTableSelectSql("onhook").c_str(), &pRes, &dwErrID,  &strErr);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    if(pRes->GetRecord())// �����н��ʱ
    {
        m_stOnHookProp.wPassSecondPerInstance = SGDP::SDAtou(pRes->GetFieldValueByName("PassSecondPerInstance"));
        m_stOnHookProp.wNoCDGoldPerInstance = SGDP::SDAtou(pRes->GetFieldValueByName("NoCDGoldPerInstance"));
    }
    else
    {
        return FALSE;
    }

    if(NULL != pRes)
    {
        pRes->Release();
        pRes = NULL;
    }
    return TRUE;
}

UINT16 COnhookMgr::Onhook(CPlayer* poPlayer, UINT8 byRunTimes, DT_INSTANCE_ID stDT_INSTANCE_ID, DT_ONHOOK_RESULT& stOnhookResult, DT_DATA_AFTER_ONHOOK& stAfterOnhookData)
{
    UINT16 wErrCode = ERR_ONHOOK::ID_SUCCESS;

    CInstanceRecord *pInstanceRecord = NULL;
    pInstanceRecord = poPlayer->GetInstance().GetSingleInstaceRecord(stDT_INSTANCE_ID.wSceneIdx, stDT_INSTANCE_ID.byTownIdx, stDT_INSTANCE_ID.byInstanceIdx);
    if(NULL == pInstanceRecord)
    {
        return ERR_ONHOOK::ID_INSTANCE_NOT_BATTLED;
    }

    if(EIT_COMMON != stDT_INSTANCE_ID.wSceneIdx)
    {
        return ERR_ONHOOK::ID_ONHOOK_UNLOCK;
    }
	//�⴫�һ�����Э��
	//if ( EIT_OUT_BOUND == stDT_INSTANCE_ID.wSceneIdx)
	//{
	//	if ( 1 != byRunTimes)
	//	{
	//		return ERR_ONHOOK::ID_OUT_BOUND_ERR;
	//	}

	//	SInstanceProp* poOutBoundProp = CInstancePropMgr::Instance()->GetInstanceProp(stDT_INSTANCE_ID.wSceneIdx, stDT_INSTANCE_ID.byTownIdx, stDT_INSTANCE_ID.byInstanceIdx);
	//	if ( NULL != poOutBoundProp)
	//	{
	//		if ( pInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum >= poOutBoundProp->byBattleNum )
	//		{
	//			return ERR_ONHOOK::ID_NOT_TIME_OUT_BOUND;
	//		}
	//		
	//	}

	//}

    if(byRunTimes > MAX_INSTANCE_RUN_TIMES)
    {
        return ERR_ONHOOK::ID_OUT_MAX_RUN_RANG;
    }
    if(0 == byRunTimes)
    {
        return ERR_ONHOOK::ID_RUN_TIMES_0;
    }

    //�����ж�
    CBag& oBag = poPlayer->GetBag();
    if(0 == oBag.GetIdleSize())
    {
        return ERR_ONHOOK::ID_BAG_FULL;
    }


    //�Ȼظ�����(����������������󴥷����Ƕ�ʱ�������ȳ��Իظ�����)
    poPlayer->GetPhystrength().PhyStrengthRecover();//

    //�����ж�
    UINT16 wCostPhyStrenth = byRunTimes * CPhystrengthMgr::Instance()->GetCommonPhyStrength();
    if(poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength < wCostPhyStrenth)
    {
        return ERR_ONHOOK::ID_PHYSTRENGTH_NOT_ENOUGH;
    }

	COnhook* poOnhook = poPlayer->GetOnhook();
	if(NULL == poOnhook)
	{
		return ERR_COMMON::ID_OTHER_ERR;
	}
    poOnhook->SetOnHookParam(byRunTimes, &stDT_INSTANCE_ID);
    DT_ONHOOK_RCD_DATA& stDT_ONHOOK_RCD_DATA = poOnhook->GetDT_ONHOOK_RCD_DATA();


    //��ȡ����
    if(poOnhook->OnHookEncourage(byRunTimes))
    {
        wErrCode = ERR_ONHOOK::ID_BAG_FULL;
    }
    //�۳�����
    wCostPhyStrenth = byRunTimes * CPhystrengthMgr::Instance()->GetCommonPhyStrength();
    UINT16 wPhyStrength = poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength;
    //poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength = poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength < wCostPhyStrenth ? 0 : (poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength - wCostPhyStrenth);
    if(wPhyStrength < wCostPhyStrenth)
    {
        poPlayer->DecPhyStrength( poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength, CRecordMgr::EDPST_ONHOOK, stDT_INSTANCE_ID.wSceneIdx, stDT_INSTANCE_ID.byTownIdx, stDT_INSTANCE_ID.byInstanceIdx);
    }
    else
    {
        poPlayer->DecPhyStrength( wCostPhyStrenth, CRecordMgr::EDPST_ONHOOK, stDT_INSTANCE_ID.wSceneIdx, stDT_INSTANCE_ID.byTownIdx, stDT_INSTANCE_ID.byInstanceIdx);
    }
    //poPlayer->GetDT_PLAYER_BASE_DATA().wPhyStrength = wPhyStrength;

    //��ȡ����������Ϣ
    poOnhook->GetOnhookResult(stOnhookResult, stAfterOnhookData);

    //һ���Է����ˣ��һ�����
    stDT_ONHOOK_RCD_DATA.byOnhookFlag = 0;//�һ�����
    //poPlayer->GetLocale().OnOnhookEnd();

    //�����������Ҫ��¼���ʱ�䣬�������ƴ���
    if (NULL != pInstanceRecord)
    {
        //pInstanceRecord->GetDT_INSTANCE_DATA().wPassTimes += byIdx;
        pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime = SDTimeSecs();
		//if ( EIT_OUT_BOUND == stDT_INSTANCE_ID.wSceneIdx)
		//{
		//	 pInstanceRecord->GetDT_INSTANCE_DATA().dwSuccessNum += 1;
		//}
    }
    return wErrCode;
}

UINT16	COnhookMgr::OnhookTower(CPlayer* poPlayer, DT_INSTANCE_ID stDT_INSTANCE_ID, UINT8 byMaxInstanceIdx, DT_ONHOOK_RESULT& stOnhookResult, DT_DATA_AFTER_ONHOOK& stAfterOnhookData)
{
    UINT16 wErrCode = ERR_CLIMB_TOWER_ONHOOK::ID_SUCCESS;
    CInstanceRecord *pInstanceRecord = NULL;
    pInstanceRecord = poPlayer->GetInstance().GetSingleInstaceRecord(stDT_INSTANCE_ID.wSceneIdx, stDT_INSTANCE_ID.byTownIdx, stDT_INSTANCE_ID.byInstanceIdx);
    if(NULL == pInstanceRecord)
    {
        return ERR_CLIMB_TOWER_ONHOOK::ID_INSTANCE_NOT_BATTLED;
    }

    if(EIT_TOWER != stDT_INSTANCE_ID.wSceneIdx)
    {
        return ERR_CLIMB_TOWER_ONHOOK::ID_ONHOOK_UNLOCK;
    }

    if (IsToday(pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime))
    {
        return ERR_CLIMB_TOWER_ONHOOK::ID_CLIMBTOWER_ONE_PER_DAY_ERR;
    }

    //�����ж�
    CBag& oBag = poPlayer->GetBag();
    if(0 == oBag.GetIdleSize())
    {
        return ERR_CLIMB_TOWER_ONHOOK::ID_BAG_FULL;
    }

    COnhook* poOnhook = poPlayer->GetOnhook();
	if (NULL == poOnhook)
	{
		return ERR_COMMON::ID_OTHER_ERR;
	}


    poOnhook->SetOnHookParam(1, &stDT_INSTANCE_ID);
    DT_ONHOOK_RCD_DATA& stDT_ONHOOK_RCD_DATA = poOnhook->GetDT_ONHOOK_RCD_DATA();

    //��ȡ����
    UINT8 byRunTimes = 1;
    if(poOnhook->OnHookEncourage(byRunTimes))
    {
        wErrCode = ERR_CLIMB_TOWER_ONHOOK::ID_BAG_FULL;
    }

    //��ȡ����������Ϣ
    poOnhook->GetOnhookResult(stOnhookResult, stAfterOnhookData);

    //һ���Է����ˣ��һ�����
    stDT_ONHOOK_RCD_DATA.byOnhookFlag = 0;//�һ�����
    //poPlayer->GetLocale().OnOnhookEnd();

    //�����������Ҫ��¼���ʱ�䣬�������ƴ���
    if (NULL != pInstanceRecord && EIT_TOWER == stDT_INSTANCE_ID.wSceneIdx &&  ERR_CLIMB_TOWER_ONHOOK::ID_BAG_FULL != wErrCode)
    {
        //pInstanceRecord->GetDT_INSTANCE_DATA().wPassTimes ++;
        pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime = SDTimeSecs();
    }
    stOnhookResult.byCurRunTimes = stDT_INSTANCE_ID.byInstanceIdx;
    stOnhookResult.byAllRunTimes = byMaxInstanceIdx;
    return wErrCode;
}


UINT16	COnhookMgr::OnhookTower(CPlayer* poPlayer, UINT16 wSceneIdx, UINT8 byTownIdx, UINT8 &byOnhookResultNum, DT_ONHOOK_RESULT astOnhookResult[MAX_INSTANCE_CLIMB_TOWER_NUM], DT_DATA_AFTER_ONHOOK &stAfterOnhookData)
{
    UINT16 wErrCode = ERR_CLIMB_TOWER_ONHOOK::ID_SUCCESS;
    STownInstanceProp *pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(wSceneIdx, byTownIdx);
    if (NULL == pstTownInstanceProp)
    {
        return ERR_CLIMB_TOWER_ONHOOK::ID_NOT_TOWER;
    }

    //���㵱ǰ���������ڵڼ���
    UINT64			qwLastPassTime	= 1;
    UINT8			byCurInstanceIdx	= 1;
    UINT8			byMaxInstanceIdx	= 1;
    UINT8			byInstanceIdx		= 1;
    BOOL				bPassInstance		=	FALSE;
    byOnhookResultNum					=	0;
    for (byInstanceIdx = 1; byInstanceIdx <= pstTownInstanceProp->m_mapInstance.size() && byInstanceIdx < MAX_INSTANCE_CLIMB_TOWER_NUM; byInstanceIdx++)
    {
        CInstanceRecord *pInstanceRecord = NULL;
        pInstanceRecord = poPlayer->GetInstance().GetSingleInstaceRecord(wSceneIdx, byTownIdx, byInstanceIdx);
        if(NULL == pInstanceRecord)
        {
            break;
        }
        if(pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime >= qwLastPassTime)
        {
            byCurInstanceIdx = byInstanceIdx;
            qwLastPassTime = pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime;
        }
        bPassInstance = TRUE;
        byMaxInstanceIdx = byInstanceIdx;
    }

    //���ڴ��ڵ�һ�����ҿ������⴦��
    if (bPassInstance && (byCurInstanceIdx != byMaxInstanceIdx || 1 == byCurInstanceIdx))
    {
        //��֤��Ҵӵ�һ�㿪ʼ
        if (0 == byCurInstanceIdx )
        {
            byCurInstanceIdx = 1;
        }

        for (byInstanceIdx = byCurInstanceIdx; byInstanceIdx <= byMaxInstanceIdx && byOnhookResultNum < MAX_INSTANCE_CLIMB_TOWER_NUM; byInstanceIdx++)
        {
            CIndex2InstancePropMapItr itr = pstTownInstanceProp->m_mapInstance.find(byInstanceIdx);
            if (itr == pstTownInstanceProp->m_mapInstance.end())
            {
                break;
            }

            DT_INSTANCE_ID stDT_INSTANCE_ID;
            stDT_INSTANCE_ID.wSceneIdx = wSceneIdx;
            stDT_INSTANCE_ID.byTownIdx = byTownIdx;
            stDT_INSTANCE_ID.byInstanceIdx = byInstanceIdx;

            DT_DATA_AFTER_ONHOOK stDT_DATA_AFTER_ONHOOK; //ɨ����Һ���Ϣ
            memset(&stDT_DATA_AFTER_ONHOOK, 0x00, sizeof(stDT_DATA_AFTER_ONHOOK));
            wErrCode = COnhookMgr::Instance()->OnhookTower(poPlayer, stDT_INSTANCE_ID, byMaxInstanceIdx, astOnhookResult[byOnhookResultNum], stDT_DATA_AFTER_ONHOOK);


            if (ERR_CLIMB_TOWER_ONHOOK::ID_CLIMBTOWER_ONE_PER_DAY_ERR == wErrCode)
            {
                continue;//��������Ѿ�����ռ����һ���Ƿ�ɹҡ�������
            }

            if (ERR_CLIMB_TOWER_ONHOOK::ID_BAG_FULL == wErrCode)
            {
                byMaxInstanceIdx = byInstanceIdx - 1;//�����⵽�������ˣ�Ҫ�޸����Ĺһ�����
                break;
            }

            //�����д���ģ�ֱ����ֹ�һ��˳�
            if(ERR_CLIMB_TOWER_ONHOOK::ID_SUCCESS != wErrCode)
            {
                break;
            }
            byOnhookResultNum++;
            memcpy(&stAfterOnhookData, &stDT_DATA_AFTER_ONHOOK, sizeof(DT_DATA_AFTER_ONHOOK));
        }
    }
    else
    {
        wErrCode = ERR_CLIMB_TOWER_ONHOOK::ID_INSTANCE_NOT_BATTLED;
    }

    //�����⵽�������ˣ�Ҫ�޸����Ĺһ�����
    if (byOnhookResultNum > 0 && ERR_CLIMB_TOWER_ONHOOK::ID_BAG_FULL == wErrCode)
    {
        UINT8 byOnhookResultNum = 0;
        for (byOnhookResultNum = 0; byOnhookResultNum < byOnhookResultNum; byOnhookResultNum++)
        {
            astOnhookResult[byOnhookResultNum].byAllRunTimes = byMaxInstanceIdx;
        }
    }

    //��⵱ǰ�����룬����з��Ϲһ������ģ��������롰����ÿ��ֻ����һ�Ρ������ø���û�д����
    if (byOnhookResultNum > 0 && (ERR_CLIMB_TOWER_ONHOOK::ID_CLIMBTOWER_ONE_PER_DAY_ERR == wErrCode || ERR_CLIMB_TOWER_ONHOOK::ID_INSTANCE_NOT_BATTLED == wErrCode))
    {
        wErrCode = ERR_CLIMB_TOWER_ONHOOK::ID_SUCCESS;
    }
    return wErrCode;
}


UINT16  COnhookMgr::OnhookElitInstance( CPlayer* poPlayer, DT_INSTANCE_ID stDT_INSTANCE_ID, UINT8 &byMaxOnHookNum,
                                        DT_ONHOOK_RESULT& stOnhookResult, DT_DATA_AFTER_ONHOOK& stAfterOnhookData )
{
    UINT16 wErrCode = ERR_ELITE_INSTANCE_ON_HOOK::ID_SUCCESS;
    CInstanceRecord *pInstanceRecord = NULL;
    pInstanceRecord = poPlayer->GetInstance().GetSingleInstaceRecord(stDT_INSTANCE_ID.wSceneIdx, stDT_INSTANCE_ID.byTownIdx, stDT_INSTANCE_ID.byInstanceIdx);
    if(NULL == pInstanceRecord)
    {
        return ERR_ELITE_INSTANCE_ON_HOOK::ID_INSTANCE_NOT_BATTLED;
    }

    if(EIT_ELITE != stDT_INSTANCE_ID.wSceneIdx)
    {
        return ERR_ELITE_INSTANCE_ON_HOOK::ID_ONHOOK_UNLOCK;
    }

    //�����ж�
    CBag& oBag = poPlayer->GetBag();
    if(0 == oBag.GetIdleSize())
    {
        return ERR_ELITE_INSTANCE_ON_HOOK::ID_BAG_FULL;
    }

    if( IsToday( pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime ) )
    {
        return ERR_ELITE_INSTANCE_ON_HOOK::ID_TODAY_ALREADY_BATTLED;
    }

    byMaxOnHookNum++;



	COnhook* poOnhook = poPlayer->GetOnhook();
	if (NULL == poOnhook)
	{
		return ERR_COMMON::ID_OTHER_ERR;
	}

    poOnhook->SetOnHookParam(1, &stDT_INSTANCE_ID);
    DT_ONHOOK_RCD_DATA& stDT_ONHOOK_RCD_DATA = poOnhook->GetDT_ONHOOK_RCD_DATA();

    //��ȡ����
    UINT8 byRunTimes = 1;
    if(poOnhook->OnHookEncourage(byRunTimes))
    {
        wErrCode = ERR_ELITE_INSTANCE_ON_HOOK::ID_BAG_FULL;
    }

    //��ȡ����������Ϣ
    poOnhook->GetOnhookResult(stOnhookResult, stAfterOnhookData);

    //һ���Է����ˣ��һ�����
    stDT_ONHOOK_RCD_DATA.byOnhookFlag = 0;//�һ�����
    //poPlayer->GetLocale().OnOnhookEnd();

    //Ҫ��¼���ʱ�䣬�������ƴ���
    if (NULL != pInstanceRecord && EIT_ELITE == stDT_INSTANCE_ID.wSceneIdx &&  ERR_ELITE_INSTANCE_ON_HOOK::ID_BAG_FULL != wErrCode)
    {
        //pInstanceRecord->GetDT_INSTANCE_DATA().wPassTimes ++;
        pInstanceRecord->GetDT_INSTANCE_DATA().qwLastPassTime = SDTimeSecs();
    }

    return wErrCode;
}

UINT16 COnhookMgr::OnhookElitInstanceByTownIndex( CPlayer *poPlayer, UINT8 byTownIndex, PKT_CLIGS_ELITE_INSTANCE_ON_HOOK_ACK *pstAck )
{
    UINT16   wErrCode = ERR_ELITE_INSTANCE_ON_HOOK::ID_SUCCESS; //�����룬��0Ϊ����
    pstAck->stPowerInfo.dwOldPower = poPlayer->GetDT_PLAYER_BASE_DATA().dwPower;
    UINT8 byMaxInstanceIdx = poPlayer->GetInstance().GetAlreadyBattleMaxIndex( byTownIndex );
    UINT8 byMaxCanHookInstance = 0;

    map<UINT32, DT_HERO_UPGRADE_DATA2> mapHeroUpgrade;
    DT_DATA_AFTER_ONHOOK stAfterOnhookData; //ɨ����Һ���Ϣ

    STownInstanceProp *pstTownInstanceProp = NULL;
    pstTownInstanceProp = CInstancePropMgr::Instance()->GetSceneInstance(EIT_ELITE, byTownIndex);
    if (NULL == pstTownInstanceProp)
    {
        return ERR_ELITE_INSTANCE_ON_HOOK::ID_NOT_TOWER;
    }


    //��ҵȼ��ж�,vip�ȼ��ж�
    if((poPlayer->GetLevel() < pstTownInstanceProp->wOnhookLevel) && (!CVipPropMgr::Instance()->CkOpenFunc(EVF_ONHOOKETELITEINSTANCE, poPlayer->GetDT_PLAYER_BASE_DATA().byVipLevel)))
    {
        return ERR_ELITE_INSTANCE_ON_HOOK::ID_ONHOOK_UNLOCK;
    }

    for (UINT8 byInstanceIdx = 1; byInstanceIdx <= byMaxInstanceIdx && pstAck->byOnhookResultNum < MAX_ELITE_INSTANCE_TOWN_NUM; byInstanceIdx++)
    {
        memset(&stAfterOnhookData, 0x00, sizeof(stAfterOnhookData));

        DT_INSTANCE_ID stDT_INSTANCE_ID;
        stDT_INSTANCE_ID.wSceneIdx = EIT_ELITE;
        stDT_INSTANCE_ID.byTownIdx = byTownIndex;
        stDT_INSTANCE_ID.byInstanceIdx = byInstanceIdx;

        wErrCode = COnhookMgr::Instance()->OnhookElitInstance(poPlayer, stDT_INSTANCE_ID, byMaxCanHookInstance,
                   pstAck->astOnhookResult[pstAck->byOnhookResultNum], stAfterOnhookData);

        //�Ѿ����ɴ�����
        if(ERR_ELITE_INSTANCE_ON_HOOK::ID_INSTANCE_NOT_BATTLED == wErrCode)
        {
            break;
        }

        //�����Ѿ������
        if (ERR_ELITE_INSTANCE_ON_HOOK::ID_TODAY_ALREADY_BATTLED == wErrCode)
        {
            continue;
        }

        //��������ֱ����ֹ�һ��˳�
        if( ERR_ELITE_INSTANCE_ON_HOOK::ID_SUCCESS != wErrCode )
        {
            break;
        }
        pstAck->byOnhookResultNum++;

        //��¼���������Ϣ
        for( INT32 nIndex = 0; nIndex < stAfterOnhookData.byUpgradeHeroNum; ++nIndex )
        {
            UINT16 wHeroID = stAfterOnhookData.astHeroUpgradeInfo[nIndex].wHeroKindID;
            map<UINT32, DT_HERO_UPGRADE_DATA2>::iterator itrFind = mapHeroUpgrade.find( wHeroID );
            if( itrFind != mapHeroUpgrade.end() )
            {
                //��¼������ʼ��Ϣ����Ϊ�ڹһ������п��ܻ���N�μ�
                stAfterOnhookData.astHeroUpgradeInfo[nIndex].wStartLevel = itrFind->second.wStartLevel;
            }

            mapHeroUpgrade[ wHeroID ] = stAfterOnhookData.astHeroUpgradeInfo[nIndex];

            //��¼��ʼ�ȼ�
// 			if( mapHeroStartLevel.find( wHeroID )!=mapHeroStartLevel.end() )
// 			{
// 				continue;
// 			}
//
// 			mapHeroStartLevel[wHeroID]=stAfterOnhookData.astHeroUpgradeInfo[nIndex].wStartLevel;
        }

        memcpy(&pstAck->stAfterOnhookData, &stAfterOnhookData, sizeof(stAfterOnhookData));
    }

    //DBG_INFO( _SDT( "elite instance onhook result:" ) );
    for( map<UINT32, DT_HERO_UPGRADE_DATA2>::iterator itr = mapHeroUpgrade.begin(); itr != mapHeroUpgrade.end(); ++itr )
    {
        DT_HERO_UPGRADE_DATA2 &data = pstAck->stAfterOnhookData.astHeroUpgradeInfo[pstAck->stAfterOnhookData.byUpgradeHeroNum];

        data = itr->second;
        pstAck->stAfterOnhookData.byUpgradeHeroNum++;

        //������ڵ���
        //DBG_INFO( _SDT( "hero:%u, start level:%u, cur level:%u" ), data.wHeroKindID, data.wStartLevel, data.wCurLevel );

        //pstAck->stAfterOnhookData.astHeroUpgradeInfo[pstAck->stAfterOnhookData.byUpgradeHeroNum++]=itr->second;
    }

    pstAck->wAllOnhookNum = byMaxCanHookInstance;
    poPlayer->GetInstance().GetEliteInstanceRecordData( pstAck->stInstanceData, pstAck->stInstanceScoreData, byTownIndex);

    pstAck->stPowerInfo.dwCurPower = poPlayer->GetDT_PLAYER_BASE_DATA().dwPower;

    pstAck->stInstanceData.wRemainResetNum = poPlayer->GetVipExtData().GetRemainResetEliteInstanceNum( byTownIndex );

    //��Щ�һ���������ڶ�ιһ�����ȷ����Ҫ�ڴ����¸�ֵ���ͻ���ʹ��
    pstAck->stAfterOnhookData.qwCurGold = poPlayer->GetDT_PLAYER_BASE_DATA().qwGold;
    pstAck->stAfterOnhookData.qwCurCoin = poPlayer->GetDT_PLAYER_BASE_DATA().qwCoin;
    pstAck->stAfterOnhookData.qwCurStory = poPlayer->GetDT_PLAYER_BASE_DATA().qwStory;
    poPlayer->GetPhystrength().GetPhyStrengthInfo( pstAck->stAfterOnhookData.stCurPhyStrengthInfo );
    poPlayer->GetExperienceInfo( pstAck->stAfterOnhookData.stExperienceInfo );

    //������Ǳ������������гɹ��Ĵ�������ô����Ϊ�ɹ�
    if( wErrCode != ERR_ELITE_INSTANCE_ON_HOOK::ID_BAG_FULL && wErrCode != ERR_ELITE_INSTANCE_ON_HOOK::ID_SUCCESS && pstAck->byOnhookResultNum )
    {
        wErrCode =  ERR_ELITE_INSTANCE_ON_HOOK::ID_SUCCESS;
    }

    return wErrCode;
}

