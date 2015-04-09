#include "player.h"
#include "playerbasedatacachemgr.h"
#include <common/client/errdef.h>
#include <net/gt/gtpktbuilder.h>
#include <protocol/server/protogsls.h>
#include "logic/player/playermgr.h"
#include "logic/player/playersavemgr.h"
#include "logic/other/singleprammgr.h"
#include <framework/gsapi.h>
#include <json/json.h>
#include <logic/vip/vippropmgr.h>
#include <logic/record/recordmgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/base/basedefine.h>
#include <logic/http/httpmgr.h>
#include <logic/http/levelhttpcmd.h>
#include <logic/hero/heropropmgr.h>
#include <logic/updateattr/updateattrpropmgr.h>
#include <logic/task/taskmgr.h>
#include <logic/hero/heromgr.h>
#include <logic/formation/formation.h>
#include "logic/build/build.h"
#include "logic/other/state.h"
#include "logic/jingjie/jingjie.h"
#include "logic/other/xiangqianmgr.h"
#include "logic/item/jewelry/jewelrypropmgr.h"
#include "logic/item/equip/equipmakemgr.h"
#include "../soul/soul.h"
#include "logic/battle/battlemgr.h"
CHero* CPlayer::GetHero(UINT16 wKindID)
{
    return m_mapKind2Hero.GetData(wKindID);
}

UINT16 CPlayer::GetLevel()
{
    if(NULL == m_poCoachHero) return 1;
    return m_poCoachHero->GetDT_HERO_BASE_DATA().wLevel;
}
UINT16 CPlayer::GetCoachHeroKindID()
{
    if(NULL == m_poCoachHero) return 0;
    return m_poCoachHero->GetDT_HERO_BASE_DATA().wKindID;
}

VOID CPlayer::SetCoachHero(CHero* poCoachHero)
{
    m_poCoachHero = poCoachHero;
}

CHero* CPlayer::NewHero(UINT16 wHeroKindId)
{
    //��ֵ��������
    DT_HERO_DATA stDT_HERO_DATA;
    memset(&stDT_HERO_DATA, 0, sizeof(stDT_HERO_DATA));
    stDT_HERO_DATA.stHeroBaseData.wLevel = 1;//�����佫1��
    stDT_HERO_DATA.stHeroBaseData.byPos = EHP_RECRUIT;//�����佫������ļ����
    stDT_HERO_DATA.stHeroBaseData.byCoach = 0;
    stDT_HERO_DATA.stHeroBaseData.byFormationIdx = 0;
    stDT_HERO_DATA.stHeroBaseData.wTalent = 0;
    stDT_HERO_DATA.stHeroBaseData.wKindID = wHeroKindId;
    //�����佫����չ����Ϊ0,���踳ֵ
	DT_JEWELRY_DATA_LST stJewelryLst = {0};
	DT_HERO_SOUL_DATA rSoulData;
	memset(&rSoulData, 0, sizeof(DT_HERO_SOUL_DATA));

    //�ж��Ƿ���ڸ������佫�������ڣ�������������
    if(NULL != m_mapKind2Hero.GetData(wHeroKindId))
    {
        USR_INFO(_SDT("[%s: %d]: CPlayer::AddHero failed, rebuild %d !"), MSG_MARK, wHeroKindId);
        return NULL;
    }

    SHeroProp *pstHeroProp = CHeroPropMgr::Instance()->GetHeroProp(wHeroKindId);
    if (NULL == pstHeroProp){
        return NULL;
    }

    /*
    // ������ж�Ӧ�Ľ��׻�飬���ٴ����û��
    if (pstHeroProp->wUpgradeToHeroID){
        if (GetHero(pstHeroProp->wUpgradeToHeroID)){
            return NULL;
        }
    }
    */

    CHero* poHero = CHeroMgr::Instance()->CreateHero(m_dwPlayerID, wHeroKindId);
    if(NULL == poHero)
    {
        return NULL;
    }
    
    if(FALSE == poHero->Init(&stDT_HERO_DATA, stJewelryLst, rSoulData, this))
    {
        CHeroMgr::Instance()->RemoveHero(m_dwPlayerID, wHeroKindId);
        return NULL;
    }
    //poHero->SetObjDataSaveType(EODST_INSERT);
    //poHero->SetSaveState(ESS_WANT_SAVE);//�����޸ģ����豣��

    //�����佫��ӵ���ļ����
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild)
    {
        CHeroMgr::Instance()->RemoveHero(m_dwPlayerID, wHeroKindId);
        return NULL;
    }

    //��û�п����ͣ�������
    if(NULL == GetBuild(EBK_FROMATION))
    {
        NewBuild(EBK_FROMATION);
    }
    
    if (pstHeroProp->bIsLegendHero){
        if (pstHeroProp->wUpgradeFromHeroID){
            CHero *poUpgradeFromHero = GetHero(pstHeroProp->wUpgradeFromHeroID);
            if (poUpgradeFromHero){
                poBuild->GetDT_BUILD_BASE_DATA().qwValue1 = 1; //������ļ�ݣ����ʾ�Ƿ�����»��ɽ���
            }
        }
    }

    poBuild->GetDT_BUILD_BASE_DATA().byValue3 = 1;//������ļ�ݣ����ʾ�Ƿ�����»�����ļ
    //m_poMinUpgradeGodweapon = 0;

    m_mapKind2Hero.AddData(poHero->GetDT_HERO_BASE_DATA().wKindID, poHero);

    return poHero;
}

CHero* CPlayer::NewHeroNoBuild(UINT16 wHeroKindId)
{
    //��ֵ��������
    DT_HERO_DATA stDT_HERO_DATA;
    memset(&stDT_HERO_DATA, 0, sizeof(stDT_HERO_DATA));
    stDT_HERO_DATA.stHeroBaseData.wLevel = 1;//�����佫1��
    stDT_HERO_DATA.stHeroBaseData.byPos = EHP_CARRY;//�����佫������ļ����
    stDT_HERO_DATA.stHeroBaseData.byCoach = 0;
    stDT_HERO_DATA.stHeroBaseData.byFormationIdx = 0;
    stDT_HERO_DATA.stHeroBaseData.wTalent = 0;
    stDT_HERO_DATA.stHeroBaseData.wKindID = wHeroKindId;
    //�����佫����չ����Ϊ0,���踳ֵ
	DT_JEWELRY_DATA_LST stJewelryLst = {0};
	DT_HERO_SOUL_DATA rSoulData = {0};
    //�ж��Ƿ���ڸ������佫�������ڣ�������������
    CHero* poHero = m_mapKind2Hero.GetData(wHeroKindId);
    if(NULL != poHero)
    {
        return poHero;
    }

    poHero = CHeroMgr::Instance()->CreateHero(m_dwPlayerID, wHeroKindId);
    if(NULL == poHero)
    {
        return NULL;
    }
    if(FALSE == poHero->Init(&stDT_HERO_DATA, stJewelryLst, rSoulData, this))
    {
        CHeroMgr::Instance()->RemoveHero(m_dwPlayerID, wHeroKindId);
        return NULL;
    }

    //��û�п����ͣ�������
    if(NULL == GetBuild(EBK_FROMATION))
    {
        NewBuild(EBK_FROMATION);
    }

    m_mapKind2Hero.AddData(poHero->GetDT_HERO_BASE_DATA().wKindID, poHero);

    return poHero;
}

BOOL CPlayer::OnUpgrade(UINT16 wLevel)
{
    if (FALSE == m_poState)
    {
        return FALSE;
    }


    if(wLevel > CSinglePramMgr::Instance()->GetMaxPlayerLevel())
        return FALSE;
    //����ص�
    CTaskMgr::Instance()->CkWantCheckAccept(this);

    CPlayerBaseDataCacheMgr::Instance()->OnLevelChange(m_dwPlayerID, wLevel);

    //���¼�������
    ResetBattleAttr();
    //
    m_poState->OnMainUpgrade(wLevel, m_stMaxBattleAttribute.qwHP, m_stCurBattleAttribute.qwHP);

    //��GT֪ͨ�������
    PKT_GSLS_PLAYER_UPGRADE_NTF stNtf;
    stNtf.dwPlayerID = m_dwPlayerID;
    stNtf.wLevel = wLevel;
    SendMsg((CHAR*)(&stNtf), GSLS_PLAYER_UPGRADE_NTF);

    SLevelInfo stLevelInfo;
    stLevelInfo.dwPlayerID = m_dwPlayerID;
    stLevelInfo.wLevel = wLevel;
    CUser *poUser = GetUser();
    if (NULL != poUser)
    {
        stLevelInfo.strDeviceID = poUser->GetDeviceID();
        stLevelInfo.strIp = SDInetNtoa(poUser->GetLoginIP());
		stLevelInfo.byAuthType = poUser->GetAuthType();
    }

    CBaseHttpCMD *poHttpCmd = CHttpMgr::Instance()->CreateCmd(EHCT_LEVEL);
    if (NULL == poHttpCmd)
    {
        SYS_CRITICAL( _SDT("[%s:%d] player:%u in memory"), MSG_MARK, m_dwPlayerID );
        return TRUE;
    }
    poHttpCmd->SetUserData(&stLevelInfo, sizeof(SLevelInfo), 0);
    poHttpCmd->Init();
    if(FALSE == CHttpMgr::Instance()->AddCommand(poHttpCmd))
    {
        CHttpMgr::Instance()->FreeCmd(poHttpCmd);
        SYS_CRITICAL( _SDT("[%s:%d] can't AddCommand player:%u in memory"), MSG_MARK, stLevelInfo.dwPlayerID );
    }
    return TRUE;


    //m_stDT_PLAYER_TODAY_CONSUME_DATA.wAddLevel += (GetLevel() - m_stDT_PLAYER_TODAY_CONSUME_DATA.byAfterVipLevel);
    //m_stDT_PLAYER_TODAY_CONSUME_DATA.wAfterLevel = GetLevel();


    //��¼�������ʱ��������Ϣ
    //CPlayer *pPlayer = CPlayerMgr::Instance()->FindPlayer( m_dwPlayerID );

    //if( NULL == pPlayer )
    //{
    //   //��¼
    //    SYS_CRITICAL( _SDT("[%s: %d]: Player[%u] not found!"), MSG_MARK, m_dwPlayerID );
    //    return FALSE;
    //}

//     BOOL bSucceed = CPlayerSaveMgr::Instance()->SavePlayerData( pPlayer, ESDBT_RECORD );
//     if( bSucceed )
//     {
//         DBG_INFO( _SDT( "׼����������������ݳɹ�!ID:%d Level:%d" ), m_dwPlayerID, wLevel );
//     }
//     else
//     {
//         USR_IMPORTANT( _SDT( "[%s: %d]: ׼�����������������ʧ��!ID:%d Level:%d" ), MSG_MARK, m_dwPlayerID, wLevel );
//     }

    return TRUE;
}


//����ҵ������佫����
VOID CPlayer::AllotExperience(UINT32 dwExperience)
{
    if(0 == dwExperience)
    {
        return;
    }

    CHero* poCoachHero = GetCoachHero();
	UINT32 dwAddExperience = 0;
    map<UINT8, CHero*>& mapHeroData = m_mapFormationHero.GetDataMap();
    for(map<UINT8, CHero*>::iterator itr = mapHeroData.begin(); itr != mapHeroData.end(); itr++)
    {
        CHero* poHero = itr->second;
        if(NULL == poHero)
        {
            continue;
        }
		
		dwAddExperience = ((100 + poHero->GetJewelryAttr(EJEA_INSTANCE_EXPERIENCE)) *  dwExperience / 100);

        if (poCoachHero == poHero)
        {
            poHero->AddExperience(dwAddExperience * CSinglePramMgr::Instance()->GetCoachExpRate() / 100);
        }
        else
        {
            poHero->AddExperience(dwAddExperience, poCoachHero->GetDT_HERO_BASE_DATA().wLevel);
        }
    }

}


BOOL CPlayer::InitHero(DT_HERO_DATA_LIST& stHeroData)
{
    UINT16 wHeroNum = stHeroData.wHeroNum;
    //������û���佫
    if(0 == wHeroNum)
    {
        return FALSE;
    }

    for(UINT16 wIdx = 0; wIdx < wHeroNum && wIdx < MAX_HERO_NUM; wIdx++)
    {
        DT_HERO_DATA* pstDT_HERO_DATA = &(stHeroData.astHeroInfoLst[wIdx]);
        CHero* poHero = CHeroMgr::Instance()->CreateHero(m_dwPlayerID, pstDT_HERO_DATA->stHeroBaseData.wKindID);
        if(NULL == poHero)
        {
            return FALSE;
        }
        if(FALSE == poHero->Init(pstDT_HERO_DATA, stHeroData.astjewelryInfoLst[wIdx], stHeroData.astSoulInfoLst[wIdx], this))
        {
            SYS_CRITICAL(_SDT("[%s: %d]: hero init failed!"), MSG_MARK);
            CHeroMgr::Instance()->RemoveHero(m_dwPlayerID, pstDT_HERO_DATA->stHeroBaseData.wKindID);
            continue;//��������������
        }
        if(COACHHERO == pstDT_HERO_DATA->stHeroBaseData.byCoach)
        {
            m_poCoachHero = poHero;
        }
        //��ļ�ݵ��佫����ӵ�Я������
        if(EHP_RECRUIT == poHero->GetDT_HERO_BASE_DATA().byPos)
        {

        }
        else
        {
            m_mapKind2HeroAllCarry.AddData(pstDT_HERO_DATA->stHeroBaseData.wKindID, poHero);
        }
        m_mapKind2Hero.AddData(poHero->GetDT_HERO_BASE_DATA().wKindID, poHero);
    }
    if(NULL == m_poCoachHero)
    {
        return FALSE;
    }

    //��Я���������������ã������Ļ���ļ��
    INT8 cDownNum = m_mapKind2HeroAllCarry.Size() - m_poInstance->GetCanCarryNum();
    CHero* poHero = m_mapKind2HeroAllCarry.GetFistData();
    while((cDownNum > 0) && (poHero))
    {
        if((poHero) && (EHP_BATTLE != poHero->GetDT_HERO_BASE_DATA().byPos))
        {
            Disbang(poHero->GetDT_HERO_BASE_DATA().wKindID);
            cDownNum--;
        }
        poHero = m_mapKind2HeroAllCarry.GetNextData();
    }

    return TRUE;
}

VOID CPlayer::GetHeroUpgradeInfo(UINT8& byHeroNum, DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM])
{
    byHeroNum = 0;
    for(UINT8 byIdx = 1; byIdx <= MAX_FORMATION_IDX_NUM; byIdx++)
    {
        CBattleAttrObj* poObj = GetFormationObj(byIdx);
        CHero* poHero = NULL;
        if(poObj)
        {
            poHero = dynamic_cast<CHero*>(poObj);
            if(poHero)
            {
                poHero->GetUpgrageInfo(astHeroUpgradeInfo[byHeroNum++]);
            }
        }
    }
}

VOID CPlayer::GetMainHeroUpgradeInfo(DT_HERO_UPGRADE_DATA& astHeroUpgradeInfo)
{
    memset(&astHeroUpgradeInfo, 0, sizeof(DT_HERO_UPGRADE_DATA));
    if(m_poCoachHero)
    {
        m_poCoachHero->GetUpgrageInfo(astHeroUpgradeInfo);
    }
}

VOID CPlayer::GetPassInstanceHeroUpgradeInfo(UINT32 dwExp, UINT8& byHeroNum, DT_HERO_UPGRADE_DATA astHeroUpgradeInfo[MAX_FORMATION_IDX_NUM])
{
    byHeroNum = 0;
    for(UINT8 byIdx = 1; byIdx <= MAX_FORMATION_IDX_NUM; byIdx++)
    {
        CBattleAttrObj* poObj = GetFormationObj(byIdx);
        CHero* poHero = NULL;
        if(poObj)
        {
            poHero = dynamic_cast<CHero*>(poObj);
            if(poHero)
            {
                DT_HERO_UPGRADE_DATA& stDT_HERO_UPGRADE_DATA = astHeroUpgradeInfo[byHeroNum++];
                poHero->GetUpgrageInfo(stDT_HERO_UPGRADE_DATA);
                stDT_HERO_UPGRADE_DATA.dwEncExperience = dwExp;
                if(stDT_HERO_UPGRADE_DATA.wHeroKindID == GetCoachHeroKindID())
                {
                    stDT_HERO_UPGRADE_DATA.dwEncExperience = dwExp * CSinglePramMgr::Instance()->GetCoachExpRate() / 100;;
                }
                if(0 == stDT_HERO_UPGRADE_DATA.byUpgradeFlag)
                {
                    UINT32 dwLastExp = (UINT32)(poHero->GetDT_HERO_BASE_DATA().qwExperience - dwExp);
                    SHeroUpgradeProp* pstProp = CHeroPropMgr::Instance()->GetHeroUpgradeProp(stDT_HERO_UPGRADE_DATA.wLevel);
                    if(pstProp)
                    {
                        if(dwLastExp < pstProp->qwExperience)
                        {
                            stDT_HERO_UPGRADE_DATA.byUpgradeFlag = 1;
                        }
                    }
                }
            }
        }
    }

}


VOID CPlayer::GetExperienceInfo(DT_EXPERIENCE_DATA& stExperienceInfo)
{
    if(m_poCoachHero)
    {
        m_poCoachHero->GetExperienceInfo(stExperienceInfo);
    }
}

//����Ƿ�ﵽ����Я��
BOOL CPlayer::CkCarryHeroFull()
{
    //Я�����ް��������
    //if((m_mapKind2HeroAllCarry.Size() - m_mapFormationHero.Size()) >= m_poInstance->GetCanCarryNum())
    if(m_mapKind2HeroAllCarry.Size() >= m_poInstance->GetCanCarryNum())
    {
        return TRUE;
    }

    return FALSE;
}

UINT16 CPlayer::GetCarryHeroInfoNew(UINT16& wHeroNum, 
	DT_HERO_PANEL_CLI astHeroInfoLst[MAX_HERO_NUM], 
	DT_HERO_EQUIP_DATA_LST_CLI *poEquipDataLst , 
	DT_ATTR_ENABLE_UPDATE_INFO *poAttrEnableUpdateLst ,
	DT_SKILL_DATA_LST_CLI *poSkillInfo , 
	DT_HERO_JEWELRY_DATA_LST_CLI* poJewelryInfo ,
	DT_HERO_SOUL_DATA_LST_CLI* pSoulInfo,
    DT_HERO_SOUL_POTENCY_DATA_LST_CLI* poSoulPotencyInfo,
    DT_JEWELRY_SUIT_LIST_CLI *pJewelrySuitInfo)
{
	GetFormation().CheckFormation();
	
	vector<CHero*> setHero;
	GetPlayerAllHero(setHero);
	
	size_t nIndex = 0;
	for (vector<CHero*>::iterator itor = setHero.begin(), end = setHero.end()
		; end != itor
		; ++ itor)
	{
		CHero* poHero = (*itor);
		if (NULL != poHero) {
			FillDataListByIndexNew(nIndex, *poHero, astHeroInfoLst, poEquipDataLst, poAttrEnableUpdateLst, poSkillInfo, poJewelryInfo, pJewelrySuitInfo);
			if ( NULL != pSoulInfo)
			{
				pSoulInfo[nIndex].wSoulEquipNum = poHero->GetHeroSoulData().wSoulNum;
				if ( NULL != poSoulPotencyInfo)
				{
					poSoulPotencyInfo[nIndex].wSoulEquipNum = pSoulInfo[nIndex].wSoulEquipNum;
				}
				
				for (size_t n = 0; n < pSoulInfo[nIndex].wSoulEquipNum && n < MAX_SOUL_EQUIP_NUM; ++n) {
					CSoul soul;
					soul.Init(this, poHero->GetHeroSoulData().astSoulLstData[n], poHero->GetHeroSoulData().astSoulPotencyLstData[n], poHero);
					soul.GetSoulCli(pSoulInfo[nIndex].astSoulEquipLstData[n]);
					if ( NULL != poSoulPotencyInfo)
					{
						soul.GetSoulPotencyCli(poSoulPotencyInfo[nIndex].astSoulEquipLstData[n]);
					}
				}
			}
		}
		++ nIndex;
	}

	wHeroNum = nIndex;

    if (pJewelrySuitInfo){
        pJewelrySuitInfo->wHeroNum = wHeroNum;
    }

	return ERR_GET_HERO_LIST::ID_SUCCESS;
}

UINT16 CPlayer::GetCarryHeroInfo(UINT16& wHeroNum, DT_HERO_BASE_DATA_CLI astHeroInfoLst[MAX_HERO_NUM],
                                 DT_HERO_EQUIP_DATA_LST_CLI *poEquipDataLst/*=NULL*/, DT_ATTR_ENABLE_UPDATE_INFO *poAttrEnableUpdateLst/*=NULL*/,
                                 DT_SKILL_DATA_CLI *poSkillInfo/*=NULL*/  )
{

	GetFormation().CheckFormation();
    map<UINT16, UINT16> mapAlreadyIn;

    INT32 nFillIndex = 0;
//   //�ȴ��������
//   UINT32 nResult = m_mapFormationHero.Size();

    //��д�����ǵ���Ϣ
    FillDataListByIndex( nFillIndex++, *m_poCoachHero, astHeroInfoLst, poEquipDataLst, poAttrEnableUpdateLst, poSkillInfo);
    mapAlreadyIn[m_poCoachHero->GetDT_HERO_BASE_DATA().wKindID] = 1;

    for(CHero* poHero = m_mapFormationHero.GetFistData(); poHero != NULL; poHero = m_mapFormationHero.GetNextData())
    {
        if( NULL == poHero )
        {
            //�Ҳ���ָ�����͵Ļ�����п��ܵģ���Ϊ�������δ��Я���û��
            continue;
        }

        //����Ѿ���Ӵ��ڣ������
        map<UINT16, UINT16>::iterator itr = mapAlreadyIn.find(poHero->GetDT_HERO_BASE_DATA().wKindID);
        if( itr != mapAlreadyIn.end() )
        {
            continue;
        }

        FillDataListByIndex( nFillIndex++, *poHero, astHeroInfoLst, poEquipDataLst, poAttrEnableUpdateLst, poSkillInfo);
        mapAlreadyIn[poHero->GetDT_HERO_BASE_DATA().wKindID] = 1;

        //ssLog << poHero->GetDT_HERO_BASE_DATA().wKindID;
    }

    //DBG_INFO( ssLog.str().c_str() );


    //���������Լ�
    wHeroNum = m_mapKind2HeroAllCarry.Size();

    vector<UINT8> vecPos;
    for( std::size_t nHeroIndex = 0; nHeroIndex < m_mapKind2HeroAllCarry.Size(); ++nHeroIndex )
    {
        CHero* poHero = m_mapKind2HeroAllCarry.GetDataByIndex( nHeroIndex );

        if( NULL == poHero )
        {
            //�Ҳ���ָ�����͵Ļ�����п��ܵģ���Ϊ�������δ��Я���û��
            continue;
        }

        //����Ѿ���Ӵ��ڣ������
        map<UINT16, UINT16>::iterator itr = mapAlreadyIn.find(poHero->GetDT_HERO_BASE_DATA().wKindID);
        if( itr != mapAlreadyIn.end() )
        {
            continue;
        }

        FillDataListByIndex( nFillIndex++, *poHero, astHeroInfoLst, poEquipDataLst, poAttrEnableUpdateLst, poSkillInfo );

        mapAlreadyIn[poHero->GetDT_HERO_BASE_DATA().wKindID] = 1;
    }
    return ERR_GET_HERO_LIST::ID_SUCCESS;
}

bool CPlayer::FormationHeroSortByCarryIndex( UINT16 byHeroKind1, UINT16 byHeroKind2 )
{
    return m_mapKind2HeroAllCarry.GetDataIndexByKey( byHeroKind1 ) < m_mapKind2HeroAllCarry.GetDataIndexByKey( byHeroKind2 );
}

BOOL CPlayer::FillDataListByIndex( UINT16 wIndex, CHero &oHero, DT_HERO_BASE_DATA_CLI *poBaseDataLst,
                                   DT_HERO_EQUIP_DATA_LST_CLI *poEquipDataLst, DT_ATTR_ENABLE_UPDATE_INFO *poAttrEnableUpdateLst,
                                   DT_SKILL_DATA_CLI *poSkillInfo)
{
    return GetHeroData( oHero, &poBaseDataLst[wIndex], poEquipDataLst ? &poEquipDataLst[wIndex] : NULL,
                        poAttrEnableUpdateLst ? &poAttrEnableUpdateLst[wIndex] : NULL,
                        poSkillInfo ? &poSkillInfo[wIndex] : NULL );
}

BOOL CPlayer::GetHeroData( CHero &oHero, DT_HERO_BASE_DATA_CLI *poBaseData,
                           DT_HERO_EQUIP_DATA_LST_CLI *poEquipData, DT_ATTR_ENABLE_UPDATE_INFO *poAttrEnableUpdateLst,
                           DT_SKILL_DATA_CLI *poSkillInfo)
{
    if( NULL != poBaseData )
    {
        oHero.GetDT_HERO_BASE_DATA_EQUIP_CLI(*poBaseData);
    }

    if( NULL != poEquipData )
    {
        oHero.GetEquip( *poEquipData );
    }

    if( NULL != poAttrEnableUpdateLst )
    {
        //�����ǰֵС�����ֵ����ô������
        poAttrEnableUpdateLst->byEnableAttrAttackUpdate = ( oHero.GetDT_HERO_BASE_DATA().stUpdateAttrInfo.wAttrAttack
                < CUpdateAttrPropMgr::Instance()->GetTotalCount( oHero.GetDT_HERO_BASE_DATA().wLevel ) );
        poAttrEnableUpdateLst->byEnableAttrHPUpdate = ( oHero.GetDT_HERO_BASE_DATA().stUpdateAttrInfo.wAttrHP
                < CUpdateAttrPropMgr::Instance()->GetTotalCount( oHero.GetDT_HERO_BASE_DATA().wLevel ));
    }

    if( NULL != poSkillInfo )
    {
        oHero.GetHeroSkillCli(*poSkillInfo);
    }

    return TRUE;
}

//��������������ָ����������
BOOL CPlayer::FillDataListByIndexNew( UINT16 wIndex, CHero &oHero, DT_HERO_PANEL_CLI *poBaseDataLst, 
	DT_HERO_EQUIP_DATA_LST_CLI *poEquipDataLst, DT_ATTR_ENABLE_UPDATE_INFO *poAttrEnableUpdateLst,
	DT_SKILL_DATA_LST_CLI *poSkillInfo, DT_HERO_JEWELRY_DATA_LST_CLI* poJewelry, DT_JEWELRY_SUIT_LIST_CLI *pJewelrySuit)
{
	return GetHeroDataNew( oHero, &poBaseDataLst[wIndex], poEquipDataLst ? &poEquipDataLst[wIndex] : NULL,
		poAttrEnableUpdateLst ? &poAttrEnableUpdateLst[wIndex] : NULL,
		poSkillInfo ? &poSkillInfo[wIndex] : NULL, poJewelry ? &poJewelry[wIndex] : NULL, pJewelrySuit ? &pJewelrySuit->astSuitList[wIndex] : NULL);
}

BOOL CPlayer::GetHeroDataNew( CHero &oHero, DT_HERO_PANEL_CLI *poBaseData, 
	DT_HERO_EQUIP_DATA_LST_CLI *poEquipData, DT_ATTR_ENABLE_UPDATE_INFO *poAttrEnableUpdateLst,
	DT_SKILL_DATA_LST_CLI *poSkillInfo, DT_HERO_JEWELRY_DATA_LST_CLI* poJewelry, DT_JEWELRY_SUIT_CLI *pJewelrySuit)
{
	if( NULL != poBaseData )
	{
		oHero.GetHeroPanelInfo(*poBaseData);
	}

	if( NULL != poEquipData )
	{
		oHero.GetEquip( *poEquipData );
	}

	if( NULL != poAttrEnableUpdateLst )
	{
		//�����ǰֵС�����ֵ����ô������
		poAttrEnableUpdateLst->byEnableAttrAttackUpdate = ( oHero.GetDT_HERO_BASE_DATA().stUpdateAttrInfo.wAttrAttack
			< CUpdateAttrPropMgr::Instance()->GetTotalCount( oHero.GetDT_HERO_BASE_DATA().wLevel ) );
		poAttrEnableUpdateLst->byEnableAttrHPUpdate = ( oHero.GetDT_HERO_BASE_DATA().stUpdateAttrInfo.wAttrHP
			< CUpdateAttrPropMgr::Instance()->GetTotalCount( oHero.GetDT_HERO_BASE_DATA().wLevel ));
	}

	if( NULL != poSkillInfo )
	{
		poSkillInfo->bySkillNum = 1;
		oHero.GetHeroSkillLstCli(*poSkillInfo);
	}

	if (NULL != poJewelry)
	{
		oHero.GetJeweryCli(*poJewelry);
	}

    if (pJewelrySuit){
        oHero.GetJewerySuitCli(*pJewelrySuit);
    }

	return TRUE;
}

UINT16 CPlayer::Recuit(UINT16 wHeroKindID, DT_HERO_BASE_DATA_CLI& stDT_HERO_BASE_DATA_CLI)
{
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild)
    {
        return ERR_RECUIT_HERO::ID_RECUIT_NOT_EXIST_ERR;
    }

    CHero* poHero = m_mapKind2Hero.GetData(wHeroKindID);
    if(NULL == poHero)
    {
        return ERR_RECUIT_HERO::ID_HERO_NOT_EXIST_ERR;
    }
    UINT16 wJingjieQualityLevel = 0;
    if (m_poJingJie)
    {
        wJingjieQualityLevel = m_poJingJie->GetJingjieQualityLevel();
    }

    BOOL bAlreadyRecuit = FALSE;
    if( EHP_RECRUIT != poHero->GetDT_HERO_BASE_DATA().byPos )
    {
        bAlreadyRecuit = TRUE;
    }

    if( poHero->GetDT_HERO_BASE_DATA().byCoach )
    {
        //�������򷵻���Ӧ����
        return ERR_RECUIT_HERO::ID_CANNOT_RECUIT_COACH;
    }

    //����Ѿ�Я�����жϿ�Я����Ŀ
    if( !bAlreadyRecuit )
    {
        //�жϿ�Я����Ŀ
        DT_INSTANCE_ID& stInstanceID = m_poInstance->GetMaxCommonInstanceID();
        SHeroUnlockProp* pstHeroUnlockProp = CInstancePropMgr::Instance()->GetUnlockHero(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
        if(NULL == pstHeroUnlockProp)
        {
            RETURN_OTHER_ERR;
        }
        if(CkCarryHeroFull())
        {
            return ERR_RECUIT_HERO::ID_UPPER_LIMIT_ERR;
        }
    }


    SHeroProp* pstHeroProp = poHero->GetHeroProp();
    if(NULL == pstHeroProp)
    {
        RETURN_OTHER_ERR;
    }

    if (CKGuide( EGF_RECUIT))
    {
        poHero->GetDT_HERO_BASE_DATA().byVisitNum = pstHeroProp->byVisitNum;
    }
    
    //û����ļ�������жϰݷô���/�ȼ�/�����Ƿ��Ѿ��㹻
    if(0 == poHero->GetDT_HERO_BASE_DATA().byRecuitedFlag)
    {
        if (pstHeroProp->bIsLegendHero && pstHeroProp->wUpgradeFromHeroID > 0){
            return ERR_RECUIT_HERO::ID_MUST_UPGRADE;
        }

        if(poHero->GetDT_HERO_BASE_DATA().byVisitNum < pstHeroProp->byVisitNum){
            // ��������⴫Ӣ�ۣ�����Ҫҡ���������øж�
            if (!pstHeroProp->bIsLegendHero){
                return ERR_RECUIT_HERO::ID_NOT_REACH_VISIT_NUM;
            }
        }else if (wJingjieQualityLevel < pstHeroProp->wRequireJingjieLevel){
            return ERR_RECUIT_HERO::ID_NOT_ENOUGH_JINGJIE_LEVEL;
        }else if(GetLevel() < pstHeroProp->wRecuitLevel){
            return ERR_RECUIT_HERO::ID_NOT_ENOUGH_PLAYER_LEVEL;
        }

        if (pstHeroProp->bIsLegendHero){
            DT_MATERIAL_LIST stMaterials;
            CEquipMakeMgr::TakeMaterialListCli(*this, pstHeroProp->vecCostMaterial, stMaterials);

            for(UINT16 i = 0; i < stMaterials.byMaterialCnt; i++){
                DT_MATERIAL &stMaterial = stMaterials.astMaterialList[i];
                if (stMaterial.wCurNum < stMaterial.wRequiredNum){
                    return ERR_RECUIT_HERO::ID_MATERIAL_NOT_ENOUGH;
                }
            }

            BOOL bCostSucc = CEquipMakeMgr::CostMaterialList(*this, stMaterials, CRecordMgr::EDIT_RECRUIT_LEGEND_HERO);
            if (!bCostSucc){
                return ERR_RECUIT_HERO::ID_MATERIAL_NOT_ENOUGH;
            }

            CRecordMgr::Instance()->RecordInfo(GetPlayerID(), ERM_FLY, CRecordMgr::EF_RECRUIT_HERO, poHero->GetHeroID(), poHero->GetDT_HERO_BASE_DATA().byRecuitedFlag,
                poHero->GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, 0, 0, 0, 0);
        }
    }


    if( !bAlreadyRecuit )
    {
        //��ļ,Я��
        m_mapKind2HeroAllCarry.AddData(wHeroKindID, poHero);
        poHero->OnRecuit();

        CTaskMgr::Instance()->OnRecruitHero(this, wHeroKindID);

        CTaskMgr::Instance()->OnRecruitHeroNum(this, wHeroKindID);
    }
    poHero->InitBattleAttribute();
    //������Ϣ
    poHero->GetDT_HERO_BASE_DATA_EQUIP_CLI(stDT_HERO_BASE_DATA_CLI);

    //��¼��ļ����
    AddGuideRecord( EGF_RECUIT);
    //�ж��Ƿ��貼��
    CKGuide( EGF_EMBATTLE);
    //3���佫ʱ2�β�������
    if(m_mapKind2HeroAllCarry.Size() == 3)
    {
        //�ж��Ƿ���2�β�������
        CKGuide( EGF_SECOND_EMBATTLE);
    }

    return ERR_RECUIT_HERO::ID_SUCCESS;
}

BOOL CPlayer::IsUpgradable(UINT16 wHeroKindID)
{
    CHero *poUpgradeHero = GetUpgradeHero(wHeroKindID);
    if (NULL == poUpgradeHero){
        return FALSE;
    }

    if (poUpgradeHero->IsRecruit()){
        return FALSE;
    }

    return TRUE;

    /*
    SInstanceID &stNeedPassInstance = pstUpgradeHeroProp->stNeedPassInstanceID;
    if (!m_poInstance->CkHaveRecord(stNeedPassInstance.wSceneIdx, stNeedPassInstance.byTownIdx, stNeedPassInstance.byInstanceIdx)){
        return FALSE;
    }

    return TRUE;
    */
}

CHero* CPlayer::GetUpgradeHero(UINT16 wHeroKindID)
{
    if (!IsFly()){
        return NULL;
    }

    SHeroProp* pstProp = CHeroPropMgr::Instance()->GetHeroProp(wHeroKindID);
    if (NULL == pstProp || 0 == pstProp->wUpgradeToHeroID){
        return NULL;
    }

    SHeroProp* pstUpgradeHeroProp = CHeroPropMgr::Instance()->GetHeroProp(pstProp->wUpgradeToHeroID);
    if (NULL == pstUpgradeHeroProp){
        return NULL;
    }

    return GetHero(pstProp->wUpgradeToHeroID);
}

UINT16 CPlayer::UpgradeHero(UINT16 wHeroKindID, PKT_CLIGS_UPGRADE_HERO_ACK &stAck)
{
    if (!IsFly()){
        return ERR_UPGRADE_HERO::ID_NOT_FLY;
    }

    // �����ļ���Ƿ��ѽ���
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild){
        return ERR_UPGRADE_HERO::ID_IS_UNOPEN;
    }

    CHero *poHero = GetHero(wHeroKindID);
    if (NULL == poHero){
        return ERR_UPGRADE_HERO::ID_NOT_FOUND_HERO;
    }

    // ����Ƿ��ѱ���ļ���ѱ���ļ���ܽ���
    if (!poHero->IsRecruit()){
        return ERR_UPGRADE_HERO::ID_NOT_UPGRADABLE;
    }

    SHeroProp* pstHeroProp = CHeroPropMgr::Instance()->GetHeroProp(wHeroKindID);
    if (NULL == pstHeroProp){
        return ERR_UPGRADE_HERO::ID_NOT_FOUND_HERO;
    }

    SHeroProp* pstUpgradeHeroProp = CHeroPropMgr::Instance()->GetHeroProp(pstHeroProp->wUpgradeToHeroID);
    if (NULL == pstUpgradeHeroProp){
        return ERR_UPGRADE_HERO::ID_NOT_UPGRADABLE;
    }

    // ��ȡ��Ӧ�Ľ��׻��
    CHero *poUpgradeHero = GetHero(pstHeroProp->wUpgradeToHeroID);
    if (NULL == poUpgradeHero){
        return ERR_UPGRADE_HERO::ID_NOT_PASS_OUTBOUND;
    }

    if (poUpgradeHero->IsRecruit()){
        return ERR_UPGRADE_HERO::ID_SUCCESS;
    }

    // �����ײ�����Ϣ
    DT_MATERIAL_LIST stMaterialsCli;
    CEquipMakeMgr::TakeMaterialListCli(*this, pstUpgradeHeroProp->vecCostMaterial, stMaterialsCli);

    for (UINT16 i = 0; i < stMaterialsCli.byMaterialCnt; i++){
        DT_MATERIAL &stMaterial = stMaterialsCli.astMaterialList[i];
        if (stMaterial.wCurNum < stMaterial.wRequiredNum){
            return ERR_UPGRADE_HERO::ID_MATERIAL_NOT_ENOUGH;
        }
    }

    BOOL bCostSucc = CEquipMakeMgr::CostMaterialList(*this, stMaterialsCli, CRecordMgr::EDIT_UPGRADE_HERO);
    if (!bCostSucc){
        return ERR_UPGRADE_HERO::ID_MATERIAL_NOT_ENOUGH;
    }

    // ��ʼ����
    stAck.stPowerChange.dwOldPower = GetDT_PLAYER_BASE_DATA().dwPower;

    // ���ײ���1. ���ѽ�������б����Ƴ��ɻ��
    CHeroMgr::Instance()->SwapHero(m_dwPlayerID, pstHeroProp->wKindID, pstUpgradeHeroProp->wKindID);
    CHeroMgr::Instance()->RemoveHero(m_dwPlayerID, pstHeroProp->wKindID);

    poHero->GetDT_HERO_BASE_DATA().wKindID = pstUpgradeHeroProp->wKindID;
    poHero->InitBattleAttribute();

    m_mapKind2Hero.DelData(pstHeroProp->wKindID);
    m_mapKind2Hero.DelData(pstUpgradeHeroProp->wKindID);
    m_mapKind2Hero.AddData(poHero->GetHeroID(), poHero);

    // ���ײ���2. ����ɻ�����������滻�ɽ��׻��
    if (m_mapKind2HeroAllCarry.GetData(pstHeroProp->wKindID)){
        m_mapKind2HeroAllCarry.DelData(pstHeroProp->wKindID);
        m_mapKind2HeroAllCarry.AddData(poHero->GetHeroID(), poHero);
    }

    if (m_mapFormationHero.GetData(pstHeroProp->wKindID)){
        m_mapFormationHero.DelData(pstHeroProp->wKindID);
        m_mapFormationHero.AddData(poHero->GetHeroID(), poHero);
    }

    poHero->ResetSkill();
    poHero->ResetEquipOwner();

    GetDT_RECRUIT_HERO_DATA_v410(poHero, stAck.stUpgradeHero);

    // ���´���ԭ���Ļ�飬��Ϊ���ֱ��ɾ��ԭ���Ļ�飬��ô���ݿ��оɵĻ����Ϣ�Ͳ��ᱻ���£��´������¾ɻ����ܳ�����λ�ظ��ȳ�ͻ
    UINT8 byNewHeroFlag = poBuild->GetDT_BUILD_BASE_DATA().byValue3;
    NewHero(wHeroKindID);
    poBuild->GetDT_BUILD_BASE_DATA().byValue3 = byNewHeroFlag;

    CGodWeapon *poGodWeapon = poHero->GetGodweapon();
    if (poGodWeapon){
        // poGodWeapon->GetDT_GODWEAPON_DATA().wHeroKindID = poHero->GetHeroID();

        DT_GODWEAPON_DATA_CLI stGodweaponInfo;
        memset(&stGodweaponInfo, 0, sizeof(stGodweaponInfo));

        CGodweaponMgr::Instance()->FreeGodweapon(this, poHero->GetHeroID(), stGodweaponInfo, TRUE);
    }

    poBuild->GetDT_BUILD_BASE_DATA().qwValue1 = 0;

    // ���¾ƹݱ�ʶ��������л��ɽ��ף���ƹݽ����Ϸ���ʾ���ɽ���
    for (CHero *poOwnHero = m_mapKind2Hero.GetFistData(); poOwnHero; poOwnHero = m_mapKind2Hero.GetNextData()){
        if (IsUpgradable(poOwnHero->GetHeroID())){
            poBuild->GetDT_BUILD_BASE_DATA().qwValue1 = 1;
            break;
        }
    }

    InitBattleAttr(TRUE);
    stAck.stPowerChange.dwCurPower = GetDT_PLAYER_BASE_DATA().dwPower;
    stAck.wHeroID = wHeroKindID;

    GetRecruitPrompt(stAck.stPromptInfo.astBuildPromptInfo[stAck.stPromptInfo.byBuildNum++]);

    CRecordMgr::Instance()->RecordInfo(GetPlayerID(), ERM_FLY, CRecordMgr::EF_UPGRADE_HERO, pstHeroProp->wKindID, pstUpgradeHeroProp->wKindID,
        poHero->GetLevel(), GetDT_PLAYER_BASE_DATA().byVipLevel, stAck.stPowerChange.dwOldPower, stAck.stPowerChange.dwCurPower, 0, 0);

    return ERR_UPGRADE_HERO::ID_SUCCESS;
}

UINT16 CPlayer::Disbang(UINT16 wHeroKindID)
{
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild)
    {
        return ERR_DISBAND_HERO::ID_RECUIT_NOT_EXIST_ERR;
    }

    CHero* poHero = GetHero(wHeroKindID);
    if(NULL == poHero)
    {
        return 	ERR_DISBAND_HERO::ID_HERO_NOT_EXIST_ERR;
    }

    if( EHP_RECRUIT == poHero->GetDT_HERO_BASE_DATA().byPos )
    {
        return ERR_DISBAND_HERO::ID_SUCCESS;
    }

    if(poHero == GetCoachHero())
    {
        return 	ERR_DISBAND_HERO::ID_COACH_CANNOT_DISBAND_ERR;
    }

    //���Я��/����
    m_mapKind2HeroAllCarry.DelData(wHeroKindID);
    m_mapFormationHero.DelData(poHero->GetDT_HERO_BASE_DATA().byFormationIdx);

    //vector< UINT16 >::iterator itrPos = std::find( m_vecCostarIndexByAllCarry.begin(), m_vecCostarIndexByAllCarry.end(), wHeroKindID );
    //if( itrPos != m_vecCostarIndexByAllCarry.end() )
    //{
    //    m_vecCostarIndexByAllCarry.erase( itrPos );
    //}


    m_apoFormationObj[poHero->GetDT_HERO_BASE_DATA().byFormationIdx] = NULL;
    if (m_poFormation)
    {
        m_poFormation->OnDisband(wHeroKindID);
    }

    poHero->OnDisband();

    //������ļ����
    poHero->GetDT_HERO_BASE_DATA().byPos = EHP_RECRUIT;


    //���¼�������
    ResetBattleAttr();

    //poHero->SetSaveState(ESS_WANT_SAVE);

    return ERR_DISBAND_HERO::ID_SUCCESS;
}


//�ݷ��佫
UINT16 CPlayer::Visit(UINT16 wHeroKindID, UINT8 bySizeFlag, UINT8 byGoldFlag, UINT8 &byWinFlag, UINT8& byNeedVisitNum, UINT8& byCurVisitNum, UINT16 &wUpgradeVisitNum, UINT32 &dwReturnCoin)
{
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild)
    {
        return ERR_VISIT_HERO::ID_RECUIT_NOT_EXIST_ERR;
    }

    CHero* poHero = m_mapKind2Hero.GetData(wHeroKindID);
    if(NULL == poHero)
    {
        return ERR_VISIT_HERO::ID_HERO_NOT_EXIST;
    }

    if( poHero->GetDT_HERO_BASE_DATA().byRecuitedFlag )
    {
        return ERR_VISIT_HERO::ID_ALREADY_RECUIT;
    }

    SHeroProp*	pstHeroProp = poHero->GetHeroProp();
    if(NULL == pstHeroProp)
    {
        //�쳣
        SYS_CRITICAL(_SDT("[%s: %d]: pstHeroProp is NULL!"), MSG_MARK);
        RETURN_OTHER_ERR;
    }
    UINT16 wJingjieQualityLevel = 0;
    if (m_poJingJie)
    {
        wJingjieQualityLevel = m_poJingJie->GetJingjieQualityLevel();
    }

    if (wJingjieQualityLevel < pstHeroProp->wRequireJingjieLevel)
    {
        return ERR_VISIT_HERO::ID_NOT_ENOUGH_JINGJIE_LEVEL;
    }
    if(GetLevel() < pstHeroProp->wRecuitLevel)
    {
        return ERR_RECUIT_HERO::ID_NOT_ENOUGH_PLAYER_LEVEL;
    }

    byNeedVisitNum  = pstHeroProp->byVisitNum;

    if(!byGoldFlag && m_stDT_PLAYER_BASE_DATA.qwCoin < pstHeroProp->dwVisitCoin)
    {
        return ERR_COMMON::ID_COIN_NOT_ENOUGH;
    }

    if((byGoldFlag) && (!CVipPropMgr::Instance()->CkOpenFunc(EVF_VISITGOLD, m_stDT_PLAYER_BASE_DATA.byVipLevel)))
    {
        return ERR_COMMON::ID_VIP_LEVEL_NOT_REACH;
    }

    if(byGoldFlag && m_stDT_PLAYER_BASE_DATA.qwGold < pstHeroProp->wVisitGold)
    {
        return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
    }

    if(poHero->GetDT_HERO_BASE_DATA().byVisitNum >= pstHeroProp->byVisitNum)
    {
        poHero->GetDT_HERO_BASE_DATA().byVisitNum = pstHeroProp->byVisitNum;
        byCurVisitNum = pstHeroProp->byVisitNum;
        return ERR_VISIT_HERO::ID_SUCCESS;
    }

    wUpgradeVisitNum = 0;
    byWinFlag = 0;
    if (byGoldFlag)
    {
        CRandomVec vecRandom;
        vecRandom.push_back(pstHeroProp->wGoldLeopardProbability);
        vecRandom.push_back(100 - pstHeroProp->wGoldLeopardProbability);
        //���ȡһ����������У��п���ʧ��
        INT32 nRandomHitIdx = GetRandomIdxMustHit(vecRandom);	//������
        if (0 == nRandomHitIdx)
        {
            byWinFlag = 2;
            wUpgradeVisitNum = (UINT8)CSinglePramMgr::Instance()->GetRecruitFavorability();
        }
        else
        {
            byWinFlag = 1;
            wUpgradeVisitNum = 1;
        }
    }
    else
    {
        //////////////////////////////////////////////////////////////////////////
        //��ȡ���ɵĵȼ�����

        CRandomVec vecRandom;
        vecRandom.push_back(pstHeroProp->wProbability);
        vecRandom.push_back(100 - pstHeroProp->wProbability);
        //���ȡһ����������У��п���ʧ��
        INT32 nRandomHitIdx = GetRandomIdxMustHit(vecRandom);	//������
        if (0 == nRandomHitIdx)
        {
            CRandomVec vecRandom;
            vecRandom.push_back(pstHeroProp->wCoinLeopardProbability);
            vecRandom.push_back(100 - pstHeroProp->wCoinLeopardProbability);
            //���ȡһ����������У��п���ʧ��
            INT32 nRandomHitIdx = GetRandomIdxMustHit(vecRandom);	//������
            if (0 == nRandomHitIdx)
            {
                byWinFlag = 2;
                wUpgradeVisitNum = (UINT8)CSinglePramMgr::Instance()->GetRecruitFavorability();
            }
            else
            {
                byWinFlag = 1;
                wUpgradeVisitNum = 1;
            }
        }
        else
        {
            byWinFlag = 0;
        }

    }
    //����ʣ�¶��ٴο���ļ
    UINT8 byLeftVisitNum =  pstHeroProp->byVisitNum - poHero->GetDT_HERO_BASE_DATA().byVisitNum;
    wUpgradeVisitNum = wUpgradeVisitNum > byLeftVisitNum ? byLeftVisitNum : wUpgradeVisitNum;
    if (byWinFlag)
    {
        poHero->OnVisit((UINT8)wUpgradeVisitNum);
    }

    if (byGoldFlag)
    {
        DecGold( pstHeroProp->wVisitGold, CRecordMgr::EDGT_VISITHERO, pstHeroProp->wKindID, poHero->GetDT_HERO_BASE_DATA().byVisitNum);
    }
    else
    {
        //����Ӯȡ�Ļ���ֱ�ӿ�ͭǮ������ʧ�ܣ�Ҫ����һ���ı�����
        if (byWinFlag)
        {
            DecCoin(pstHeroProp->dwVisitCoin, CRecordMgr::EDCT_VISITHERO, pstHeroProp->wKindID, poHero->GetDT_HERO_BASE_DATA().byVisitNum);
        }
        else
        {
            dwReturnCoin = (pstHeroProp->dwVisitCoin * CSinglePramMgr::Instance()->GetRecruitReturnCoinPercentage()) / 100;
            DecCoin(dwReturnCoin, CRecordMgr::EDCT_VISITHERO, pstHeroProp->wKindID, poHero->GetDT_HERO_BASE_DATA().byVisitNum);
        }
    }

    byCurVisitNum = poHero->GetDT_HERO_BASE_DATA().byVisitNum;
    return ERR_VISIT_HERO::ID_SUCCESS;
}

//�����ã�ɾ����ʯ
UINT16 CPlayer::DelItem(UINT16 wItemKindID)
{
    UINT16 wTotal = 0;
    CHero* poHero = m_mapKind2Hero.GetFistData();
    do
    {
        if (NULL == poHero)
        {
            break;
        }
        CEquipMap &	mapEquip = poHero->GetEquipMap();
        CEquip*		poEquip = mapEquip.GetFistData();
        while(poEquip)
        {


            DT_EQUIP_DATA & stDT_EQUIP_DATA = poEquip->GetDT_EQUIP_DATA();
            for (int i = 0; i < MAX_XIANGQIAN_NUM; i++)
            {
                if(stDT_EQUIP_DATA.astXiangqianList[i].wItemID >= wItemKindID)
                {
                    wTotal++;
                    stDT_EQUIP_DATA.astXiangqianList[i].wItemID = 0;
                }
            }
            poEquip = mapEquip.GetNextData();
        }
    }
    while (poHero = m_mapKind2Hero.GetNextData());
    return wTotal;
}

UINT16 CPlayer::OpenExperienceTransfer(UINT16 wHeroID, PKT_CLIGS_OPEN_EXPERIENCE_TRANSFER_ACK &stAck)
{
    if(NULL == GetBuild(EBK_EXPTRAN))
    {
        return ERR_OPEN_EXPERIENCE_TRANSFER::ID_BUILD_NOT_EXIT;
    }

    CHero *poHero = GetHero(wHeroID);
    if (NULL == poHero)
    {
        return ERR_OPEN_EXPERIENCE_TRANSFER::ID_HERO_NOT_EXIT;
    }
    stAck.byFreePercentage = (UINT8)CSinglePramMgr::Instance()->GetHeroTransFreePercentage();
    stAck.byGoldPercentage = (UINT8)CSinglePramMgr::Instance()->GetHeroTransGoldPercentage();
    stAck.wGold = CSinglePramMgr::Instance()->GetTransGold();

    poHero->GetDT_HERO_BASE_DATA_EQUIP_CLI(stAck.stHeroInfo);

    CHero * poTransHero = m_mapKind2HeroAllCarry.GetFistData();
    while(poTransHero)
    {
        //ȥ���佫�Լ��Լ����������Ϣ
        if (wHeroID == poTransHero->GetHeroID() || poTransHero->GetHeroID() == m_poCoachHero->GetHeroID())
        {
            poTransHero = m_mapKind2HeroAllCarry.GetNextData();
            continue;
        }

        BOOL bIsFly = poHero->IsFly();

        //��ȡ�佫������Ϣ
        poTransHero->GetDT_HERO_BASE_DATA_EQUIP_CLI(stAck.astHeroInfoLst[stAck.wHeroNum]);

        UINT64 qwExperience = 0;
        //�佫�ﵽ���ȼ������黹�������ǣ�Ҫ���ǵ�
        if (poTransHero->GetDT_HERO_BASE_DATA().wLevel == CSinglePramMgr::Instance()->GetMaxPlayerLevel())
        {
            SHeroUpgradeProp *poHeroUpgradeProp = CHeroPropMgr::Instance()->GetHeroUpgradeProp(poTransHero->GetDT_HERO_BASE_DATA().wLevel);
            if(NULL != poHeroUpgradeProp)
            {
                qwExperience = poHeroUpgradeProp->qwExperience;
            }
        }
        else
        {
            qwExperience =  poTransHero->GetDT_HERO_BASE_DATA().qwExperience;
        }

        qwExperience =  qwExperience * CSinglePramMgr::Instance()->GetHeroTransFreePercentage() / 100;
        qwExperience += poHero->GetDT_HERO_BASE_DATA().qwExperience;

        DT_HERO_UPGRADE_LEVEL &stUpgradeLevel = stAck.astUpgradeHeroInfoLst[stAck.wHeroNum];

        stUpgradeLevel.byFreeLevel = (UINT8)CHeroPropMgr::Instance()->GetLevel(qwExperience);

        if (stUpgradeLevel.byFreeLevel > GetLevel()){
            stUpgradeLevel.byFreeLevel = (UINT8)GetLevel();
        }

        qwExperience = 0;
        //�佫�ﵽ���ȼ������黹�������ǣ�Ҫ���ǵ�
        if (poTransHero->GetDT_HERO_BASE_DATA().wLevel == CSinglePramMgr::Instance()->GetMaxPlayerLevel())
        {
            SHeroUpgradeProp *poHeroUpgradeProp = CHeroPropMgr::Instance()->GetHeroUpgradeProp(poTransHero->GetDT_HERO_BASE_DATA().wLevel);
            if(NULL != poHeroUpgradeProp)
            {
                qwExperience = poHeroUpgradeProp->qwExperience;
            }
        }
        else
        {
            qwExperience =  poTransHero->GetDT_HERO_BASE_DATA().qwExperience;
        }
        qwExperience =  qwExperience * CSinglePramMgr::Instance()->GetHeroTransGoldPercentage() / 100;
        qwExperience += poHero->GetDT_HERO_BASE_DATA().qwExperience;

        stUpgradeLevel.byGoldLevel = (UINT8)CHeroPropMgr::Instance()->GetLevel(qwExperience);

        if (stUpgradeLevel.byGoldLevel > GetLevel()){
            stUpgradeLevel.byGoldLevel = (UINT8)GetLevel();
        }

        stAck.wHeroNum++;
        poTransHero = m_mapKind2HeroAllCarry.GetNextData();
    }
    return ERR_OPEN_EXPERIENCE_TRANSFER::ID_SUCCESS;
}

UINT16 CPlayer::ExperienceTransfer(UINT16 wHeroID, UINT16 wTransHeroID, UINT8 byGold, DT_HERO_BASE_DATA_CLI &stHeroInfo, DT_HERO_BASE_DATA_CLI &stTransHeroInfo)
{
    if(NULL == GetBuild(EBK_EXPTRAN))
    {
        return ERR_OPEN_EXPERIENCE_TRANSFER::ID_BUILD_NOT_EXIT;
    }

    if (NULL == m_poCoachHero)
    {
        RETURN_OTHER_ERR;
    }

    if (wHeroID == wTransHeroID)
    {
        return ERR_EXPERIENCE_TRANSFER::ID_TRANS_HERO_EQUIL;
    }

    if (wHeroID == m_poCoachHero->GetHeroID())
    {
        return ERR_EXPERIENCE_TRANSFER::ID_TRANS_HERO_COACH;
    }

    if (wTransHeroID == m_poCoachHero->GetHeroID())
    {
        return ERR_EXPERIENCE_TRANSFER::ID_TRANS_HERO_COACH;
    }

    CHero *poHero = GetHero(wHeroID);
    if (NULL == poHero)
    {
        return ERR_EXPERIENCE_TRANSFER::ID_HERO_NOT_EXIT;
    }

    SHeroProp* pstHeroProp = CHeroPropMgr::Instance()->GetHeroProp(wHeroID);
    if(NULL == pstHeroProp)
    {
        return ERR_EXPERIENCE_TRANSFER::ID_HERO_NOT_EXIT;
    }

    if(poHero->GetDT_ABSORB_DATA_LST().byAbsorbNum > pstHeroProp->wMaxAbsorbNum)
    {
        return ERR_EXPERIENCE_TRANSFER::ID_TRANS_HERO_OVER_STEP;
    }
    //Ҫ���յ��佫
    CHero * poTransHero = GetHero(wTransHeroID);
    if (NULL == poTransHero)
    {
        return ERR_EXPERIENCE_TRANSFER::ID_HERO_NOT_EXIT;
    }

    if(poTransHero->GetAbsorbKindID() > 0)
    {
        return ERR_EXPERIENCE_TRANSFER::ID_HERO_TWICE_ERR;
    }

    if (poTransHero->GetTransHeroID(wHeroID))
    {
        return ERR_EXPERIENCE_TRANSFER::ID_HERO_MUTUAL_TRANSFER;
    }

    UINT64 qwExperience = 0;
    if (byGold > 0)
    {
        if (CSinglePramMgr::Instance()->GetTransGold() > GetDT_PLAYER_BASE_DATA().qwGold)
        {
            return ERR_EXPERIENCE_TRANSFER::ID_GOLD_NOT_ENOUGH;
        }
        DecGold(CSinglePramMgr::Instance()->GetTransGold(), CRecordMgr::EDGT_EXPTRANS);
        //�佫�ﵽ���ȼ������黹�������ǣ�Ҫ���ǵ�
        if (poTransHero->GetDT_HERO_BASE_DATA().wLevel == CSinglePramMgr::Instance()->GetMaxPlayerLevel())
        {
            SHeroUpgradeProp *poHeroUpgradeProp = CHeroPropMgr::Instance()->GetHeroUpgradeProp(poTransHero->GetDT_HERO_BASE_DATA().wLevel);
            if(NULL != poHeroUpgradeProp)
            {
                qwExperience = poHeroUpgradeProp->qwExperience;
            }
        }
        else
        {
            qwExperience =  poTransHero->GetDT_HERO_BASE_DATA().qwExperience;
        }
        qwExperience =  qwExperience * CSinglePramMgr::Instance()->GetHeroTransGoldPercentage() / 100;
        //qwExperience += poHero->GetDT_HERO_BASE_DATA().dwExperience;
    }
    else
    {
        //�佫�ﵽ���ȼ������黹�������ǣ�Ҫ���ǵ�
        if (poTransHero->GetDT_HERO_BASE_DATA().wLevel == CSinglePramMgr::Instance()->GetMaxPlayerLevel())
        {
            SHeroUpgradeProp *poHeroUpgradeProp = CHeroPropMgr::Instance()->GetHeroUpgradeProp(poTransHero->GetDT_HERO_BASE_DATA().wLevel);
            if(NULL != poHeroUpgradeProp)
            {
                qwExperience = poHeroUpgradeProp->qwExperience;
            }
        }
        else
        {
            qwExperience =  poTransHero->GetDT_HERO_BASE_DATA().qwExperience;
        }
        qwExperience =  qwExperience * CSinglePramMgr::Instance()->GetHeroTransFreePercentage() / 100;
        //qwExperience += poHero->GetDT_HERO_BASE_DATA().dwExperience;
    }

    SHeroUpgradeProp *poFlyLevelUpgradeProp = CHeroPropMgr::Instance()->GetHeroUpgradeProp(FLY_LEVEL);
    if(poFlyLevelUpgradeProp){
        UINT64 qwFlyLevelExp = poFlyLevelUpgradeProp->qwExperience;

        UINT64 qwFinalExp = poHero->GetDT_HERO_BASE_DATA().qwExperience + qwExperience;
        if (qwFinalExp > qwFlyLevelExp){
            UINT32 dwFlyExp = (UINT32)(qwFinalExp - qwFlyLevelExp);
            poHero->AddFlyExp(dwFlyExp);
        }
    }

    poHero->AddExperience((UINT32)qwExperience, m_poCoachHero->GetDT_HERO_BASE_DATA().wLevel);
    poTransHero->SetAbsorbKindID(wHeroID);
    poHero->AddTransHeroID(wTransHeroID);

    poHero->GetDT_HERO_BASE_DATA_EQUIP_CLI(stHeroInfo);
    poTransHero->GetDT_HERO_BASE_DATA_EQUIP_CLI(stTransHeroInfo);
    ResetBattleAttr();//�����������
    return ERR_EXPERIENCE_TRANSFER::ID_SUCCESS;
}

UINT16 CPlayer::Change2NewCareer(UINT8 byCareerID)
{
    UINT8 byOldCareerID = (UINT8)(GetCoachHeroKindID());
    if(byOldCareerID == byCareerID)
    {
        return ERR_CHANGE_CAREER_INFO::ID_SUCCESS;
    }

    if(byCareerID >= 10)
    {
        return ERR_CHANGE_CAREER_INFO::ID_CAREERID_NOT_EXIST;
    }

    SHeroProp* pstProp = CHeroPropMgr::Instance()->GetHeroProp(byCareerID);
    if(NULL == pstProp)
    {
        return ERR_CHANGE_CAREER_INFO::ID_CAREERID_NOT_EXIST;
    }

    DT_HERO_BASE_DATA stDT_HERO_BASE_DATATmp = m_poCoachHero->GetDT_HERO_BASE_DATA();
    UINT16 wErrCode = m_poCoachHero->Change2NewCareer(byCareerID);
    if(0 != wErrCode)
    {
        return wErrCode;
    }

    //�޸�hero����
    m_mapKind2Hero.DelData(byOldCareerID);
    m_mapKind2HeroAllCarry.DelData(byOldCareerID);
    m_mapKind2HeroAllCarry.AddData(byCareerID, m_poCoachHero);
    m_mapKind2Hero.AddData(byCareerID, m_poCoachHero);



    //�޸������е�λ��
    if (m_poFormation)
    {
        DT_NEW_FORMATION_DATA& stFormationData = m_poFormation->GetDT_FORMATION_DATA();
        for(UINT8 byFormationKindNum = 0; byFormationKindNum < stFormationData.stFormationList.byFormationKindNum; byFormationKindNum++)
        {
            DT_FORMATION_IDX_DATA& stDT_FORMATION_IDX_DATA = stFormationData.stFormationList.astFormationInfo[byFormationKindNum];
            for(UINT8 byOpenIdxNum = 0; byOpenIdxNum < stDT_FORMATION_IDX_DATA.byOpenIdxNum; byOpenIdxNum++)
            {
                DT_FORMATION_HERO_DATA& stDT_FORMATION_HERO_DATA = stDT_FORMATION_IDX_DATA.astOpenIdxInfo[byOpenIdxNum];
                if(stDT_FORMATION_HERO_DATA.wHeroID == byOldCareerID)
                {
                    stDT_FORMATION_HERO_DATA.wHeroID = byCareerID;
                }
            }
        }
        m_mapFormationHero.Clear();
        InitFormation(stFormationData);
    }

    //�޸Ļ�����Ϣ�е�ְҵ
    const SPlayerBaseData* pstPlayerBaseData = CPlayerBaseDataCacheMgr::Instance()->GetPlayerBaseData(m_dwPlayerID);
    if(pstPlayerBaseData)
    {
        (const_cast<SPlayerBaseData*>(pstPlayerBaseData))->wMainHeroKindID = byCareerID;
    }

    m_stOldCareerBeforeChange = stDT_HERO_BASE_DATATmp;
    m_stOldCareerBeforeChange.byCoach = 2;//��ʾתְҵ

    ResetBattleAttr(FALSE);

    return ERR_CHANGE_CAREER_INFO::ID_SUCCESS;;
}


UINT16 CPlayer::GMRecuit( UINT16 wHeroKindID, UINT64 qwIndex)
{
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild)
    {
        return ERR_GM_PARM_INFO::ID_RECUIT_NOT_EXIST_ERR;
    }

    BOOL	bNew = FALSE;
    CHero* poHero = m_mapKind2Hero.GetData(wHeroKindID);
    if(NULL == poHero)
    {
        //ѡ�����佫����
        bNew = TRUE;
        poHero = NewHeroNoBuild(wHeroKindID);
        poHero->GetDT_HERO_BASE_DATA().byPos = EHP_RECRUIT;
    }
    UINT16 wJingjieQualityLevel = 0;
    if (m_poJingJie)
    {
        wJingjieQualityLevel = m_poJingJie->GetJingjieQualityLevel();
    }

    BOOL bAlreadyRecuit = FALSE;
    if( EHP_RECRUIT != poHero->GetDT_HERO_BASE_DATA().byPos )
    {
        bAlreadyRecuit = TRUE;
    }

    if( poHero->GetDT_HERO_BASE_DATA().byCoach )
    {
        //�������򷵻���Ӧ����
        return ERR_GM_PARM_INFO::ID_CANNOT_RECUIT_COACH;
    }

    //����Ѿ�Я�����жϿ�Я����Ŀ
    if( !bAlreadyRecuit )
    {
        //�жϿ�Я����Ŀ
        DT_INSTANCE_ID& stInstanceID = m_poInstance->GetMaxCommonInstanceID();
        SHeroUnlockProp* pstHeroUnlockProp = CInstancePropMgr::Instance()->GetUnlockHero(stInstanceID.wSceneIdx, stInstanceID.byTownIdx, stInstanceID.byInstanceIdx);
        if(NULL == pstHeroUnlockProp)
        {
            RETURN_OTHER_ERR;
        }
        if(CkCarryHeroFull())
        {
            if (qwIndex == 0)
            {
                //�����������˾�ֱ�Ӹ���ҡ����
                SHeroProp* pstHeroProp = poHero->GetHeroProp();
                if(NULL != pstHeroProp)
                {
                     poHero->GetDT_HERO_BASE_DATA().byVisitNum = pstHeroProp->byVisitNum;
                }
                return ERR_GM_PARM_INFO::ID_UPPER_LIMIT_ERR;
            }
            else
            {
                GMDisbang();
            }
        }
    }

    SHeroProp* pstHeroProp = poHero->GetHeroProp();
    if(NULL == pstHeroProp)
    {
        RETURN_OTHER_ERR;
    }

    poHero->GetDT_HERO_BASE_DATA().byVisitNum = pstHeroProp->byVisitNum;
    
    if( !bAlreadyRecuit )
    {
        //��ļ,Я��
        m_mapKind2HeroAllCarry.AddData(wHeroKindID, poHero);
        poHero->OnRecuit();

        CTaskMgr::Instance()->OnRecruitHero(this, wHeroKindID);

        CTaskMgr::Instance()->OnRecruitHeroNum(this, wHeroKindID);
    }

    poHero->InitBattleAttribute();


    //��¼��ļ����
    AddGuideRecord( EGF_RECUIT);
    //�ж��Ƿ��貼��
    CKGuide( EGF_EMBATTLE);
    //3���佫ʱ2�β�������
    if(m_mapKind2HeroAllCarry.Size() == 3)
    {
        //�ж��Ƿ���2�β�������
        CKGuide( EGF_SECOND_EMBATTLE);
    }

    return ERR_GM_PARM_INFO::ID_SUCCESS;
}

VOID CPlayer::GMDisbang()
{
    map<UINT16, UINT16> mapAlreadyIn;
    //��д�����ǵ���Ϣ
    mapAlreadyIn[m_poCoachHero->GetDT_HERO_BASE_DATA().wKindID] = 1;

    for(CHero* poHero = m_mapFormationHero.GetFistData(); poHero != NULL; poHero = m_mapFormationHero.GetNextData())
    {
        if( NULL == poHero )
        {
            //�Ҳ���ָ�����͵Ļ�����п��ܵģ���Ϊ�������δ��Я���û��
            continue;
        }

        //����Ѿ���Ӵ��ڣ������
        map<UINT16, UINT16>::iterator itr = mapAlreadyIn.find(poHero->GetDT_HERO_BASE_DATA().wKindID);
        if( itr != mapAlreadyIn.end() )
        {
            continue;
        }

        mapAlreadyIn[poHero->GetDT_HERO_BASE_DATA().wKindID] = 1;
    }

    //���������Լ�
    UINT16 wHeroNum = m_mapKind2HeroAllCarry.Size();

    map<UINT16, UINT16> mapNotAlready;
    for( std::size_t nHeroIndex = 0; nHeroIndex < m_mapKind2HeroAllCarry.Size(); ++nHeroIndex )
    {
        CHero* poHero = m_mapKind2HeroAllCarry.GetDataByIndex( nHeroIndex );

        if( NULL == poHero )
        {
            //�Ҳ���ָ�����͵Ļ�����п��ܵģ���Ϊ�������δ��Я���û��
            continue;
        }

        //����Ѿ���Ӵ��ڣ������
        map<UINT16, UINT16>::iterator itr = mapAlreadyIn.find(poHero->GetDT_HERO_BASE_DATA().wKindID);
        if( itr != mapAlreadyIn.end() )
        {
            continue;
        }

        mapNotAlready[poHero->GetDT_HERO_BASE_DATA().wLevel] = poHero->GetDT_HERO_BASE_DATA().wKindID;
    }

    UINT16 wKindID = 0;

    map<UINT16, UINT16>::iterator itr = mapNotAlready.begin();
    if (itr != mapNotAlready.end())
    {
        wKindID = itr->second;
    }
    CHero* poHeroNew = GetHero(wKindID);
    if(NULL == poHeroNew)
    {
        return;
    }

    //���Я��/����
    m_mapKind2HeroAllCarry.DelData(wKindID);
    m_mapFormationHero.DelData(poHeroNew->GetDT_HERO_BASE_DATA().byFormationIdx);

    m_apoFormationObj[poHeroNew->GetDT_HERO_BASE_DATA().byFormationIdx] = NULL;
    if (m_poFormation)
    {
        m_poFormation->OnDisband(wKindID);
    }

    poHeroNew->OnDisband();

    //������ļ����
    poHeroNew->GetDT_HERO_BASE_DATA().byPos = EHP_RECRUIT;

    //���¼�������
    ResetBattleAttr();

}

UINT16 CPlayer::OpenPlayerInfoSkill(PKT_CLIGS_PLAYER_INFO_SKILL_ACK& stAck)
{
	UINT8 byHeroNum = 0;
	set<CHero*> setHero;
	CHero* poHero = GetCoachHero();
	if ( NULL == poHero)
	{
		return ERR_PLAYER_INFO_SKILL::ID_COACH_HERO_LOST;
	}
	stAck.astSkillInfo[byHeroNum].bySkillNum = 1;
	poHero->GetHeroSkillLstCli(stAck.astSkillInfo[byHeroNum]);
	setHero.insert(poHero);
	byHeroNum++;

	poHero = m_mapFormationHero.GetFistData();
	while ( poHero)
	{
		if (setHero.end() != setHero.find(poHero))
		{
			poHero = m_mapFormationHero.GetNextData();
			continue;
		}
		stAck.astSkillInfo[byHeroNum].bySkillNum = 1;
		poHero->GetHeroSkillLstCli(stAck.astSkillInfo[byHeroNum]);
		setHero.insert(poHero);
		byHeroNum++;
		poHero = m_mapFormationHero.GetNextData();
	}

	poHero = m_mapKind2HeroAllCarry.GetFistData();
	while ( poHero)
	{
		if (setHero.end() != setHero.find(poHero))
		{
			poHero = m_mapKind2HeroAllCarry.GetNextData();
			continue;
		}
		stAck.astSkillInfo[byHeroNum].bySkillNum = 1;
		poHero->GetHeroSkillLstCli(stAck.astSkillInfo[byHeroNum]);
		setHero.insert(poHero);
		byHeroNum++;
		poHero = m_mapKind2HeroAllCarry.GetNextData();
	}

	stAck.byHeroNum = byHeroNum;
	return ERR_PLAYER_INFO_SKILL::ID_SUCCESS;
}

VOID CPlayer::GetAllCarryHeroAttr(DT_HERO_ATTR_LST_INFO& stAttrInfo, UINT8* abyJobType)
{
	vector<CHero*> vecHero;
	GetPlayerAllHero(vecHero);

	UINT32 unIndex = 0;
	for (vector<CHero*>::iterator itor = vecHero.begin(), end = vecHero.end()
		; end != itor
		; ++ itor)
	{
		CHero* pHero = *(itor);
		if (NULL != pHero) {
			stAttrInfo.awHeroID[unIndex] = pHero->GetHeroID();
			stAttrInfo.adwPower[unIndex] = pHero->GetPower();
			stAttrInfo.astBaseAttr[unIndex] = CBattleMgr::Instance()->ConvertAttribute2ToBase(pHero->GetDT_BATTLE_ATTRIBUTE());
			stAttrInfo.astHideAttr[unIndex] = pHero->GetDT_HIDE_BATTLE_ATTRIBUTE();
			stAttrInfo.awTalent[unIndex] = pHero->GetTalent();
			stAttrInfo.awLevel[unIndex] = pHero->GetDT_HERO_BASE_DATA().wLevel;
			SHeroProp* pHeroProp = CHeroPropMgr::Instance()->GetHeroProp(pHero->GetHeroID());
			if (NULL != pHeroProp) {
				abyJobType[unIndex] = pHeroProp->byCareerID;
			} else {
				abyJobType[unIndex] = 1;
			}
		}

		++unIndex;
	}

	stAttrInfo.wHeroNum = unIndex;
}

UINT16 CPlayer::GetPlayerInfoEquip(PKT_CLIGS_PLAYER_INFO_EQUIP_ACK& stAck)
{
	set<CHero*> setHero;
	CHero* poHero = GetCoachHero();
	UINT8 byHeroNum = 0;
	if(NULL == poHero)
	{
		return ERR_PLAYER_INFO_EQUIP::ID_COACH_HERO_LOST;
	}
	poHero->GetEquip( stAck.astEquipDataList[byHeroNum]);
	poHero->GetDT_HERO_BASE_DATA_CLI(stAck.astHeroBaseData[byHeroNum]);
	byHeroNum++;
	setHero.insert(poHero);

	poHero = m_mapFormationHero.GetFistData();
	while( poHero )
	{
		if(setHero.find(poHero) != setHero.end() )
		{
			poHero = m_mapFormationHero.GetNextData();
			continue;
		}
		poHero->GetEquip(stAck.astEquipDataList[byHeroNum]);
		poHero->GetDT_HERO_BASE_DATA_CLI(stAck.astHeroBaseData[byHeroNum]);
		byHeroNum++;
		setHero.insert(poHero);
		poHero = m_mapFormationHero.GetNextData();
	}

	poHero = m_mapKind2HeroAllCarry.GetFistData();
	while( poHero )
	{
		if(setHero.find(poHero) != setHero.end() )
		{
			poHero = m_mapKind2HeroAllCarry.GetNextData();
			continue;
		}
		poHero->GetEquip(stAck.astEquipDataList[byHeroNum]);
		poHero->GetDT_HERO_BASE_DATA_CLI(stAck.astHeroBaseData[byHeroNum]);
		byHeroNum++;
		setHero.insert(poHero);
		poHero = m_mapKind2HeroAllCarry.GetNextData();
	}
	stAck.byHeroNum = byHeroNum;
	stAck.dwPlayerID = m_stDT_PLAYER_BASE_DATA.dwID;
	stAck.byVipLevel = m_stDT_PLAYER_BASE_DATA.byVipLevel;

	CXiangqianMgr::Instance()->GetXiangqianEquipDes( stAck.stEquipXiangqianDes.aszEquipPos1Des, stAck.stEquipXiangqianDes.aszEquipPos2Des,
		stAck.stEquipXiangqianDes.aszEquipPos3Des, stAck.stEquipXiangqianDes.aszEquipPos4Des );
	return ERR_PLAYER_INFO_EQUIP::ID_SUCCESS;
}

UINT16 CPlayer::JewelryCompare(PKT_CLIGS_JEWELRY_COMPARE_REQ& stReq, PKT_CLIGS_JEWELRY_COMPARE_ACK& stAck)
{
	CJewelry* poJewelry = GetJewelry( stReq.wJewelryID, stReq.wJewelryIdx);
	if ( NULL == poJewelry)
	{
		return ERR_JEWELRY_COMPARE::ID_NOT_FIND_JEWELRY;
	}
	CJewelry* poLowJewelry = NULL;
	UINT8 byPosID = poJewelry->GetDT_JEWELRY_DATA().byJewelryDressPos;
	poJewelry->GetJewelryDataCli(stAck.stCompareJewelryInfo);

	CHero* poHero = GetCoachHero();
	if ( NULL == poHero)
	{
		return ERR_JEWELRY_COMPARE::ID_COACH_HERO_LOST;
	}
	CJewelry* poCurJewelry = poHero->GetJewelryByPos(byPosID);
	if ( NULL != poCurJewelry)
	{
		poLowJewelry = poCurJewelry;
	}
	set<CHero*> setHero;
	setHero.insert(poHero);
	poHero = m_mapFormationHero.GetFistData();
	while(poHero)
	{
		if ( setHero.end() != setHero.find(poHero))
		{
			poHero = m_mapFormationHero.GetNextData();
			continue;
		}
		setHero.insert(poHero);
		poCurJewelry = poHero->GetJewelryByPos(byPosID);
		poLowJewelry = CJewelryPropMgr::Instance()->CompareJewelry(poLowJewelry, poCurJewelry);
		
		poHero = m_mapFormationHero.GetNextData();
	}


	if ( NULL != poLowJewelry)
	{
		poLowJewelry->GetJewelryDataCli(stAck.stDressJewelryInfo);
	}

	return ERR_JEWELRY_COMPARE::ID_SUCCESS;
}

VOID CPlayer::GetHeroPanelLstCli(DT_HERO_PANEL_LST_CLI& stHeroLstCli)
{
	CHero* poHero = GetCoachHero();
	if ( NULL == poHero)
	{
		return ;
	}
	set<CHero*> setHero;
	UINT8 byHeroNum = 0;
	poHero->GetHeroPanelInfo(stHeroLstCli.astHeroPanelInfo[byHeroNum++]);
	setHero.insert(poHero);
	poHero = m_mapFormationHero.GetFistData();
	while(poHero)
	{
		if ( setHero.end() != setHero.find(poHero))
		{
			poHero = m_mapFormationHero.GetNextData();
			continue;
		}
		poHero->GetHeroPanelInfo( stHeroLstCli.astHeroPanelInfo[byHeroNum++] );
		setHero.insert(poHero);
		poHero = m_mapFormationHero.GetNextData();
	}

	poHero = m_mapKind2HeroAllCarry.GetFistData();

	while(poHero)
	{
		if ( setHero.end() != setHero.find(poHero))
		{
			poHero = m_mapKind2HeroAllCarry.GetNextData();
			continue;
		}
		poHero->GetHeroPanelInfo(stHeroLstCli.astHeroPanelInfo[byHeroNum++]);
		setHero.insert(poHero);
		poHero = m_mapKind2HeroAllCarry.GetNextData();
	}

	stHeroLstCli.wHeroNum = byHeroNum;
}
//set��������򣬲��ܰ�ָ��˳���·�����vector�ȽϺ�
VOID CPlayer::GetPlayerAllHero(vector<CHero*>& vecHero) {
	vecHero.clear();
	CHero* poHero = GetCoachHero();
	if (NULL != poHero) {
		vecHero.push_back(poHero);
	}

	poHero = m_mapFormationHero.GetFistData();
	while (NULL != poHero) {
		if (find(vecHero.begin(), vecHero.end(), poHero) != vecHero.end()) {
			poHero = m_mapFormationHero.GetNextData();
			continue;
		}
		vecHero.push_back(poHero);
		poHero = m_mapFormationHero.GetNextData();
	}

	poHero = m_mapKind2HeroAllCarry.GetFistData();
	while (NULL != poHero) {
		if (find(vecHero.begin(), vecHero.end(), poHero) != vecHero.end()) {
			poHero = m_mapKind2HeroAllCarry.GetNextData();
			continue;
		}

		vecHero.push_back(poHero);
		poHero = m_mapKind2HeroAllCarry.GetNextData();
	}
}
