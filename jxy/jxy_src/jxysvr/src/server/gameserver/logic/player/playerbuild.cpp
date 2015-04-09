#include "player.h"
#include <net/cli/user.h>
#include <net/gt/gtpktbuilder.h>
#include <logic/race/racepropmgr.h>
#include <logic/build/buildpropmgr.h>
#include <logic/item/equip/strengthenpropmgr.h>
#include <logic/item/equip/openlightpropmgr.h>
#include <framework/gsapi.h>
#include <logic/record/recordmgr.h>
#include <logic/lua/luamgr.h>
#include <logic/record/recordmgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/activityencourage/activityencouragemgr.h>
#include <framework/gsconfig.h>
#include <logic/hero/heropropmgr.h>
#include <net/cli/usermgr.h>
#include <logic/task/taskmgr.h>
#include <logic/build/buildmgr.h>
#include <logic/race/racemgr.h>
#include <logic/other/worship.h>
#include <logic/other/rdchallenge.h>
#include "logic/build/build.h"
#include "logic/jingjie/jingjie.h"
#include "logic/hero/hero.h"
#include "logic/yabiao/yabiaoinfo.h"
#include "logic/gvg/local/gvgbuild.h"
#include "logic/item/equip/equipmakemgr.h"


CBuild* CPlayer::NewBuild(UINT8 byKindID)
{
    DT_BUILD_BASE_DATA stDT_BUILD_BASE_DATA;
    memset(&stDT_BUILD_BASE_DATA, 0, sizeof(DT_BUILD_BASE_DATA));
    stDT_BUILD_BASE_DATA.byKindID = byKindID;
    
	//�ֳ彨��
	if (EBK_RECHARGE == byKindID)
    {
		if (0 == GetDT_PLAYER_BASE_DATA().dwTotalAmount)
		{
			stDT_BUILD_BASE_DATA.wLevel = 1;	//���ϳ�ֵ��־
		}
		else
		{
			stDT_BUILD_BASE_DATA.wLevel = 2;//��ȡ��ֵ������־
		}
    }
	else
	{
		stDT_BUILD_BASE_DATA.wLevel = 0;
	}

    stDT_BUILD_BASE_DATA.bySort = CBuildPropMgr::Instance()->GetBuildSort(stDT_BUILD_BASE_DATA.byKindID);
    //stDT_BUILD_BASE_DATA.bySort = m_mapKind2Build.Size() + 1; //������˳��

    //�ж��Ƿ���ڸ����ͽ����������ڣ�������������
    if(NULL != m_mapKind2Build.GetData(byKindID))
    {
        USR_INFO(_SDT("[%s: %d]: CPlayer::NewBuild failed, rebuild %d !"), MSG_MARK, byKindID);
        return NULL;
    }
    CBuild* poBuild = CBuildMgr::Instance()->CreateBuild(m_dwPlayerID, byKindID);
    if(NULL == poBuild)
    {
        return NULL;
    }
    if(FALSE == poBuild->Init(&stDT_BUILD_BASE_DATA, this))
    {
        CBuildMgr::Instance()->RemoveBuild(m_dwPlayerID, byKindID);
        return NULL;
    }
    //poBuild->SetObjDataSaveType(EODST_INSERT);
    //poBuild->SetSaveState(ESS_WANT_SAVE);//�����޸ģ����豣��

    //��������(��ʾ���ż�԰)���ж�����Ƿ�ע���û�����δע���û�����ͨ���ͻ���ע���û���
    if(EBK_MAINTOWN == byKindID)
    {
        CkRegUserName();
    }

    m_mapKind2Build.AddData(byKindID, poBuild);//���build����AddFunctionModuleAndGuide��ʹ��
    //��ӽ�������ģ��
    if(!poBuild->AddFunctionModuleAndGuide())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Build[%d] AddFunctionModuleAndGuide failed !"), MSG_MARK, byKindID);
        CBuildMgr::Instance()->RemoveBuild(m_dwPlayerID, byKindID);
        m_mapKind2Build.DelData(byKindID);
        return NULL;
    }

    return poBuild;
}


CBuild* CPlayer::GetBuild(EBuildKind eBuildKind)
{
	return m_mapKind2Build.GetData(eBuildKind);
}

//��ʼ������
BOOL CPlayer::InitBuild(DT_BUILD_DATA_LIST& stBuildData)
{
    UINT16 wBuildNum = stBuildData.wBuildNum;
    for(UINT16 wIdx = 0; wIdx < wBuildNum && wIdx < MAX_BUILD_NUM; wIdx++)
    {
        DT_BUILD_BASE_DATA* pstDT_BUILD_BASE_DATA = &(stBuildData.astBuildInfoLst[wIdx]);

		//if(FALSE == CheckEmBuile(pstDT_BUILD_BASE_DATA->byKindID))
		//{
		//	SYS_CRITICAL(_SDT("[%s: %d]: CPlayer::Build ID failed, ID %d !"), MSG_MARK, pstDT_BUILD_BASE_DATA->byKindID);
		//	continue;
		//}

		//����0��Ч�Ľ�������
		if(0 == pstDT_BUILD_BASE_DATA->byKindID)
		{
			continue;
		}

        CBuild* poBuild = CBuildMgr::Instance()->CreateBuild(m_dwPlayerID, pstDT_BUILD_BASE_DATA->byKindID);
        if(NULL == poBuild)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CreateBuild failed !"), MSG_MARK);
            return FALSE;
        }
        if(FALSE == poBuild->Init(pstDT_BUILD_BASE_DATA, this))
        {
            USR_INFO(_SDT("[%s: %d]: Build init failed !"), MSG_MARK);
            CBuildMgr::Instance()->RemoveBuild(m_dwPlayerID, pstDT_BUILD_BASE_DATA->byKindID);
            continue;//��������������
        }
        m_mapKind2Build.AddData(poBuild->GetBuildKind(), poBuild);
    }

    m_pstMaintownLevyProp = CBuildPropMgr::Instance()->GetMaintownLevyProp();

    return TRUE;
}


//����Ƿ���Ҫע���û���
VOID CPlayer::CkRegUserName()
{
    return ;//todo

    //��������(��ʾ���ż�԰)���ж�����Ƿ�ע���û�����δע���û�����ͨ���ͻ���ע���û���

	CUser* poUser=CUserMgr::Instance()->FindUser( GetID() );
    if(poUser)
    {
        tstring strName = poUser->GetUserName();
        if(strName.empty())
        {
            //��GT֪ͨ�����ע���û���
            UINT16 wMsgID = CGTPktBuilder::Instance()->RegiUserNameNtf();
            SendMsg(CGTPktBuilder::Instance()->GetPacketBuffer(), wMsgID);
        }
    }
}

VOID CPlayer::GetBuildList(UINT16& wBuildNum , DT_BUILD_DATA_CLI astBuildInfo[MAX_BUILD_NUM])
{
	wBuildNum = 0;
	DT_INSTANCE_ID& stMaxInstance = m_poInstance->GetMaxCommonInstanceID();
	SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(stMaxInstance.wSceneIdx, stMaxInstance.byTownIdx, stMaxInstance.byInstanceIdx);
	if(NULL == pstInstanceProp)
	{
		return;
	}
	C8Set& setOpenBuild = pstInstanceProp->stInstanceOpenFunc.setOpenBuild;

	UINT16 wNum = 0;
    CBuild* poBuild = m_mapKind2Build.GetFistData();

    UINT32 dwCliVer = GetCliVer();
    
    // 410�汾�����﹦�ܡ�ת�����ܣ�֮ǰ�Ŀͻ������ֻ�ܽ���50������������410�汾�������Ѿ�����50�ˣ�������Ҫ���汾����
    UINT16 wMaxBuildNum = (GetCliVer() < VERSION_FLY ?  MAX_BUILD_NUM_BEFORE_v410 : MAX_BUILD_NUM);
    while((poBuild) && (wNum < wMaxBuildNum))
    {
        UINT8 eBuildKind = (EBuildKind)(poBuild->GetDT_BUILD_BASE_DATA().byKindID);

		//��ֵ��� ��������ȡ������
		if (EBK_RECHARGE == eBuildKind && 
			0 != m_poActivityEncourage->GeDT_ACTIVITY_ENCOURAGE_DATA().byRechargeFlag)
		{
			poBuild = m_mapKind2Build.GetNextData();
			continue;
		}

		else if (EBK_SCORE == eBuildKind && 
			(0 != m_poActivityEncourage->GeDT_ACTIVITY_ENCOURAGE_DATA().byScoreFlag ||
			0 == strlen(CSinglePramMgr::Instance()->GetAppAddress())))
		{
			poBuild = m_mapKind2Build.GetNextData();
			continue;
		}

        //����ǻ�������������һ���Ƿ��н�������ȡ
        else if (EBK_ACTIVITY_ENCOURAGE == eBuildKind &&
                !m_poActivityEncourage->CkActivityEncourage())
        {
            poBuild = m_mapKind2Build.GetNextData();
            continue;
        }

        //�������޸ģ����·�
        if((setOpenBuild.find(eBuildKind) == setOpenBuild.end())
                && (EBK_FROMATION != eBuildKind && EBK_ENCHANT != eBuildKind && EBK_EQUIP_MAKE != eBuildKind))//������ϵͳ����
        {
            poBuild = m_mapKind2Build.GetNextData();
            continue;
        }

		//�ۼ������ڵͰ汾2.90�в��·�
		if((EBK_COLLECTGAS == eBuildKind) && (dwCliVer <= 290))
		{
			poBuild = m_mapKind2Build.GetNextData();
			continue;
		}

		if ( EBK_FACTION == eBuildKind && (dwCliVer < 302))
		{
			poBuild = m_mapKind2Build.GetNextData();
			continue;
		}

		if ( EBK_FRIENDS == eBuildKind && (dwCliVer < 302))
		{
			poBuild = m_mapKind2Build.GetNextData();
			continue;
		}

        if ((EBK_GVG == eBuildKind || EBK_MEDAL == eBuildKind || EBK_SOUL == eBuildKind) && dwCliVer < VERSION_GVG_ACTIVITY)
        {
            poBuild = m_mapKind2Build.GetNextData();
            continue;
        }
		
        if (dwCliVer < VERSION_FLY && (EBK_ENCHANT == eBuildKind || EBK_EQUIP_MAKE == eBuildKind || EBK_FLY == eBuildKind || EBK_OUT_BOUND == eBuildKind))
        {
            poBuild = m_mapKind2Build.GetNextData();
            continue;
        }

		poBuild->GetDT_BUILD_DATA_CLI(astBuildInfo[wNum]);

        poBuild = m_mapKind2Build.GetNextData();
        wNum++;
    }

    wBuildNum = wNum;
}


UINT16 CPlayer::GetOpenCruitAck(PKT_CLIGS_OPEN_RECRUIT_ACK& stAck)
{
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild)
    {
        return ERR_OPEN_RECUIT::ID_NOT_EXIST_ERR;
    }
    poBuild->OnOpen();

	stAck.wJingJieLevel = 0;
	if(m_poJingJie)
	{
		stAck.wJingJieLevel = m_poJingJie->GetDT_JINGJIE_DATA().stBaseData.wLevel;
	}

    stAck.wHeroNum = 0;

    //��õ�ǰ�����������佫
    DT_INSTANCE_ID& stMaxInstance = m_poInstance->GetMaxCommonInstanceID();
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(stMaxInstance.wSceneIdx, stMaxInstance.byTownIdx, stMaxInstance.byInstanceIdx);
    if(NULL == pstInstanceProp)
    {
        return ERR_OPEN_RECUIT::ID_SUCCESS;
    }

    vector<UINT16> & mapOpenHero = pstInstanceProp->stInstanceOpenFunc.vecOpenHero;
	UINT16 wEncHeroID = CActivityEncourageMgr::Instance()->GetHeroID();

    map<UINT16,UINT16>map_HeroID;
	vector<UINT16>::reverse_iterator ritr;
	for (ritr = mapOpenHero.rbegin(); ritr != mapOpenHero.rend(); ritr++)
	{
		//�����͵ģ��Ҳ��ǿ��ŵģ�����
		if(*ritr == wEncHeroID)
		{
			continue;
		}

		CHero* poHero = m_mapKind2Hero.GetData(*ritr);
		if((NULL == poHero) || (stAck.wHeroNum >= MAX_HERO_NUM))
		{
			SYS_CRITICAL( _SDT( "[%s %d]Hero:%d not exist!" ), MSG_MARK, *ritr);
			continue;
		}
        map_HeroID[poHero->GetDT_HERO_BASE_DATA().wKindID] = poHero->GetDT_HERO_BASE_DATA().wKindID;
		if(GetDT_RECRUIT_HERO_DATA(poHero, stAck.astHeroInfoLst[stAck.wHeroNum]))
		{
			stAck.wHeroNum++;
		}
	}

	//�����͵Ļ��
	CHero* poHero = m_mapKind2Hero.GetData(wEncHeroID);
	if (NULL != poHero)
	{
        map_HeroID[poHero->GetDT_HERO_BASE_DATA().wKindID] = poHero->GetDT_HERO_BASE_DATA().wKindID;
		if(GetDT_RECRUIT_HERO_DATA(poHero, stAck.astHeroInfoLst[stAck.wHeroNum]))
		{
			stAck.wHeroNum++;
		}
	}

    //����GMֱ�Ӹ��Ļ��
    CHero* poHeroNew = m_mapKind2Hero.GetFistData();
    while(poHeroNew)
    {
        UINT16 wKindID =  poHeroNew->GetDT_HERO_BASE_DATA().wKindID;
        if (GetCoachHeroKindID() == poHeroNew->GetDT_HERO_BASE_DATA().wKindID)
        {
            poHeroNew = m_mapKind2Hero.GetNextData();
        }
        else
        {
            map<UINT16,UINT16>::iterator itr = map_HeroID.find(wKindID);
            if (itr == map_HeroID.end())
            {
                if(GetDT_RECRUIT_HERO_DATA_OF_GM(poHeroNew, stAck.astHeroInfoLst[stAck.wHeroNum]))
                {
                    stAck.wHeroNum++;
                }
            }
            poHeroNew = m_mapKind2Hero.GetNextData();
        }
    }

    return ERR_OPEN_RECUIT::ID_SUCCESS;
}

// ������ұ����ɺõ����������
bool SortByTalentAsc(const SHeroProp* pstHeroProp1, const SHeroProp* pstHeroProp2)
{
    if (pstHeroProp1->wTalent == pstHeroProp2->wTalent){
        return pstHeroProp1->wKindID > pstHeroProp2->wKindID;
    }

    return pstHeroProp1->wTalent > pstHeroProp2->wTalent;
}

UINT16 CPlayer::GetOpenCruitAck_v410(PKT_CLIGS_OPEN_RECRUIT_ACK_v410& stAck)
{
    CBuild* poBuild = GetBuild(EBK_RECRUIT);
    if(NULL == poBuild){
        return ERR_OPEN_RECUIT::ID_NOT_EXIST_ERR;
    }
    poBuild->OnOpen();

    stAck.wJingJieLevel = 0;
    if(m_poJingJie){
        stAck.wJingJieLevel = m_poJingJie->GetDT_JINGJIE_DATA().stBaseData.wLevel;
    }

    stAck.wHeroNum = 0;

    //1. ��õ�ǰ�����������佫
    DT_INSTANCE_ID& stMaxInstance = m_poInstance->GetMaxCommonInstanceID();
    SInstanceProp* pstInstanceProp = CInstancePropMgr::Instance()->GetInstanceProp(stMaxInstance.wSceneIdx, stMaxInstance.byTownIdx, stMaxInstance.byInstanceIdx);
    if(NULL == pstInstanceProp){
        return ERR_OPEN_RECUIT::ID_SUCCESS;
    }

    vector<UINT16> & vecOpenHero = pstInstanceProp->stInstanceOpenFunc.vecOpenHero;
    UINT16 wEncHeroID = CActivityEncourageMgr::Instance()->GetHeroID();

    typedef std::set<UINT16> HeroIDSet;
    typedef std::list<UINT16> HeroIDList;

    HeroIDSet setHeroID;          // ǰ�����
    HeroIDSet setGMHeroID;        // GMֱ�Ӹ��Ļ��
    HeroIDList listLegendHeroID;  // �⴫���
    HeroIDList listShowHeroID;    // ��ʾ��ȫ������б���ʾ˳���ǣ� �⴫��� + ǰ����� + �������� + GM���Ļ��

    for (vector<UINT16>::reverse_iterator ritr = vecOpenHero.rbegin(); ritr != vecOpenHero.rend(); ritr++){
        if(*ritr == wEncHeroID){
            //�����͵ģ��Ҳ��ǿ��ŵģ�����
            continue;
        }

        CHero* poHero = m_mapKind2Hero.GetData(*ritr);
        if((NULL == poHero) || (stAck.wHeroNum >= MAX_HERO_NUM)){
            SYS_CRITICAL( _SDT( "[%s %d]Hero:%d not exist!" ), MSG_MARK, *ritr);
            continue;
        }

        SHeroProp* pstHeroProp = poHero->GetHeroProp();
        if(NULL == pstHeroProp){
            return FALSE;
        }

        if (pstHeroProp->wUpgradeToHeroID > 0){
            CHero *poUpgradeHero = GetHero(pstHeroProp->wUpgradeToHeroID);
            if (poUpgradeHero && poUpgradeHero->IsRecruit()){
                // ����ƹ���û��Ľ��װ����ѱ���ļ����ֻ��ʾ���׻��
                continue;
            }
        }

        if (pstHeroProp->wUpgradeFromHeroID > 0){
            CHero *poUpgradeFromHero = GetHero(pstHeroProp->wUpgradeFromHeroID);
            if (poUpgradeFromHero && !poHero->IsRecruit()){
                // ����û����ĳ�����Ľ��װ���δ����ļ����ֻ��ʾδ���׻��
                continue;
            }
        }

        setHeroID.insert(poHero->GetHeroID());
        listShowHeroID.push_back(poHero->GetHeroID());
    }

    //2. �����͵Ļ��
    CHero* poHero = m_mapKind2Hero.GetData(wEncHeroID);
    if (poHero){
        setHeroID.insert(poHero->GetHeroID());
        listShowHeroID.push_back(poHero->GetHeroID());
    }

    //3. ʣ�µĻ�� = �⴫��� + GMֱ�Ӹ��Ļ��
    for(CHero* poHeroNew = m_mapKind2Hero.GetFistData(); poHeroNew; poHeroNew = m_mapKind2Hero.GetNextData())
    {
        UINT16 wKindID =  poHeroNew->GetDT_HERO_BASE_DATA().wKindID;
        if (poHeroNew->IsCoachHero()){
            // ���˵�����
            continue;
        }

        HeroIDSet::iterator itr = setHeroID.find(wKindID);
        if (itr == setHeroID.end()){
            SHeroProp *pstNewHeroProp = poHeroNew->GetHeroProp();
            if (pstNewHeroProp->bIsLegendHero){
                if (pstNewHeroProp->wUpgradeFromHeroID > 0 && !poHeroNew->IsRecruit()){
                    continue;
                }else{
                    listLegendHeroID.push_back(poHeroNew->GetHeroID());
                    // listShowHeroID.push_back(poHeroNew->GetHeroID());
                }
            }else{
                listShowHeroID.push_back(poHeroNew->GetHeroID());
                setGMHeroID.insert(poHeroNew->GetHeroID());
            }
        }
    }

    // listLegendHeroID.sort(std::greater<UINT16>());
    listShowHeroID.insert(listShowHeroID.begin(), listLegendHeroID.begin(), listLegendHeroID.end());

    typedef std::vector<SHeroProp*> HeroPropVec;
    HeroPropVec vecHeroProp;

    for (HeroIDList::iterator itr = listShowHeroID.begin(); itr != listShowHeroID.end(); ++itr){
        UINT16 wHeroID = *itr;
        SHeroProp *pstHeroProp = CHeroPropMgr::Instance()->GetHeroProp(wHeroID);
        if (pstHeroProp){
            vecHeroProp.push_back(pstHeroProp);
        }
    }

    std::sort(vecHeroProp.begin(), vecHeroProp.end(), SortByTalentAsc);

    // ȡ��������ͻ�����ʾ�ṹ��
    //for(HeroIDList::iterator itr = listShowHeroID.begin(); itr != listShowHeroID.end(); ++itr){
    for(UINT16 i = 0; i < vecHeroProp.size(); i++){
        SHeroProp *pstHeroProp = vecHeroProp[i];

        CHero *poHero = GetHero(pstHeroProp->wKindID);
        if (NULL == poHero){
            continue;
        }

        bool bIsGMHero = (setGMHeroID.find(pstHeroProp->wKindID) != setGMHeroID.end());
        if (bIsGMHero){
            if(GetDT_RECRUIT_HERO_DATA_OF_GM_v410(poHero, stAck.astHeroList[stAck.wHeroNum])){
                stAck.wHeroNum++;
            }
        }else{
            if(GetDT_RECRUIT_HERO_DATA_v410(poHero, stAck.astHeroList[stAck.wHeroNum])){
                stAck.wHeroNum++;
            }
        }
    }

    return ERR_OPEN_RECUIT::ID_SUCCESS;
}

BOOL CPlayer::GetDT_RECRUIT_HERO_DATA(CHero* poHero, DT_RECRUIT_HERO_DATA& stDT_RECRUIT_HERO_DATA)
{
    SHeroProp*	pstHeroProp = poHero->GetHeroProp();
    if(NULL == pstHeroProp)
    {
        return FALSE;
    }
    UINT16 wJingjieQualityLevel = 0;
    if (NULL != m_poJingJie)
    {
        wJingjieQualityLevel = m_poJingJie->GetJingjieQualityLevel();
    }

	DT_HERO_BASE_DATA& stDT_HERO_BASE_DATA = poHero->GetDT_HERO_BASE_DATA();
	poHero->GetDT_HERO_BASE_DATA_EQUIP_CLI( stDT_RECRUIT_HERO_DATA.stHeroBaseInfo, TRUE );	
	stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.wTalent = poHero->GetTalent();
	//���δ��Я������ô����ʾ�ӳ�����
	if( NULL == m_mapKind2HeroAllCarry.GetData( stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.wKindID ) )
	{
		stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.stBattleAttribute.dwAttack = pstHeroProp->dwAttack;
		stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.stBattleAttribute.dwHP = pstHeroProp->dwHP;
		//stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.wTalent = poHero->GetTalent();//-poHero->GetGodweaponAddTalent();

		stDT_RECRUIT_HERO_DATA.stHeroAttrAddInfo.dwAddAttack = 0;
		stDT_RECRUIT_HERO_DATA.stHeroAttrAddInfo.dwAddHP = 0;
	}
	else
	{
		stDT_RECRUIT_HERO_DATA.stHeroAttrAddInfo.dwAddAttack =
			stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.stBattleAttribute.dwAttack - pstHeroProp->dwAttack;
		stDT_RECRUIT_HERO_DATA.stHeroAttrAddInfo.dwAddHP =
			stDT_RECRUIT_HERO_DATA.stHeroBaseInfo.stBattleAttribute.dwHP - pstHeroProp->dwHP;
	}

	//������û��Я�����������������ӵ�����
	stDT_RECRUIT_HERO_DATA.stHeroAttrAddInfo.dwAddTalent = poHero->GetGodweaponAddTalent();

	stDT_RECRUIT_HERO_DATA.byNeedVisitNum = pstHeroProp->byVisitNum;
	stDT_RECRUIT_HERO_DATA.byCurVisitNum = stDT_HERO_BASE_DATA.byVisitNum > pstHeroProp->byVisitNum ? pstHeroProp->byVisitNum : stDT_HERO_BASE_DATA.byVisitNum;
	stDT_RECRUIT_HERO_DATA.dwVisitCoin = pstHeroProp->dwVisitCoin;
	stDT_RECRUIT_HERO_DATA.wVisitGold = pstHeroProp->wVisitGold;
	poHero->GetHeroSkillCli(stDT_RECRUIT_HERO_DATA.stSkillInfo);
	stDT_RECRUIT_HERO_DATA.wRecuitLevel = pstHeroProp->wRecuitLevel;
	stDT_RECRUIT_HERO_DATA.wRequireJingjieLevel = pstHeroProp->wRequireJingjieLevel;
	stDT_RECRUIT_HERO_DATA.byRecommend = pstHeroProp->byRecommend;	


    if ((GetLevel() >= pstHeroProp->wRecuitLevel) && (wJingjieQualityLevel >= pstHeroProp->wRequireJingjieLevel))
    {
        stDT_RECRUIT_HERO_DATA.byRecuitUnLock = 1;
    }
    else
    {
        stDT_RECRUIT_HERO_DATA.byRecuitUnLock = 0;
    }


	return TRUE;
}

BOOL CPlayer::GetDT_RECRUIT_HERO_DATA_v410(CHero* poHero, DT_RECRUIT_HERO_DATA_v410 &stHeroCli_v410)
{
    memset(&stHeroCli_v410, 0, sizeof(stHeroCli_v410));
    
    SHeroProp* pstHeroProp = poHero->GetHeroProp();
    if(NULL == pstHeroProp){
        return FALSE;
    }

    // ���δ����������ʾ�⴫���
    if (pstHeroProp->bIsLegendHero && !IsFly()){
        return FALSE;
    }

    DT_RECRUIT_HERO_DATA stHeroCli;
    if (!GetDT_RECRUIT_HERO_DATA(poHero, stHeroCli)){
        return FALSE;
    }

    stHeroCli_v410.byNeedVisitNum = stHeroCli.byNeedVisitNum;
    stHeroCli_v410.byCurVisitNum = stHeroCli.byCurVisitNum;
    stHeroCli_v410.dwVisitCoin = stHeroCli.dwVisitCoin;
    stHeroCli_v410.wVisitGold = stHeroCli.wVisitGold;
    stHeroCli_v410.wRecuitLevel = stHeroCli.wRecuitLevel;
    stHeroCli_v410.wRequireJingjieLevel = stHeroCli.wRequireJingjieLevel;
    stHeroCli_v410.byRecuitUnLock = stHeroCli.byRecuitUnLock;
    stHeroCli_v410.byRecommend = stHeroCli.byRecommend;
    
    stHeroCli_v410.stHeroInfo.stHeroBaseInfo = stHeroCli.stHeroBaseInfo;
    stHeroCli_v410.stHeroInfo.stSkillInfo = stHeroCli.stSkillInfo;

    DT_HERO_ATTR_ADD_CLI_v410 &stHeroAttrAddInfo = stHeroCli_v410.stHeroInfo.stHeroAttrAddInfo;
    stHeroAttrAddInfo.dwDefense  = 0;
    stHeroAttrAddInfo.dwAddTalent = stHeroCli.stHeroAttrAddInfo.dwAddTalent;

    //����ѱ�Я����������ϣ�����ʾ�ӳ�����
    if(m_mapKind2HeroAllCarry.GetData(stHeroCli_v410.stHeroInfo.stHeroBaseInfo.wKindID ) ){
        stHeroAttrAddInfo.dwAddAttack = stHeroCli.stHeroAttrAddInfo.dwAddAttack;
        stHeroAttrAddInfo.dwAddHP     = stHeroCli.stHeroAttrAddInfo.dwAddHP;

        DT_BATTLE_BASE_ATTRIBUTE &stAttr = poHero->GetDT_BATTLE_ATTRIBUTE();
        stHeroAttrAddInfo.dwAddDefense    = stAttr.dwDefend - 0;
    }

    stHeroCli_v410.byIsFlyHero = pstHeroProp->bIsLegendHero;
    stHeroCli_v410.byCanUpgrade = IsUpgradable(poHero->GetHeroID());

    // ��ȡ���ײ����б�
    if (stHeroCli_v410.byCanUpgrade){
        SHeroProp* pstUpgradeHeroProp = CHeroPropMgr::Instance()->GetHeroProp(pstHeroProp->wUpgradeToHeroID);
        if (pstUpgradeHeroProp){
            CEquipMakeMgr::TakeMaterialListCli(*this, pstUpgradeHeroProp->vecCostMaterial, stHeroCli_v410.stUpgradeMaterials);
        }
    }

    // ��ȡ��ļ�����б�
    if (pstHeroProp->bIsLegendHero && 0 == pstHeroProp->wUpgradeFromHeroID){
        CEquipMakeMgr::TakeMaterialListCli(*this, pstHeroProp->vecCostMaterial, stHeroCli_v410.stRecruitMaterials);
    }
    
    if (stHeroCli_v410.byCanUpgrade){
        DT_RECRUIT_HERO_INFO &stUpgradeHeroCli_v410 = stHeroCli_v410.astUpgradeHeroInfo[0];

        CHero *poUpgradeHero = GetUpgradeHero(poHero->GetHeroID());
        
        DT_RECRUIT_HERO_DATA stUpgradeHeroCli;
        GetDT_RECRUIT_HERO_DATA(poUpgradeHero, stUpgradeHeroCli);

        DT_HERO_ATTR_ADD_CLI_v410 &stUpgradeHeroAddAttr_v410 = stUpgradeHeroCli_v410.stHeroAttrAddInfo;
        stUpgradeHeroAddAttr_v410.dwAddAttack = stUpgradeHeroCli.stHeroAttrAddInfo.dwAddAttack;
        stUpgradeHeroAddAttr_v410.dwAddHP     = stUpgradeHeroCli.stHeroAttrAddInfo.dwAddHP;
        stUpgradeHeroAddAttr_v410.dwAddTalent = stUpgradeHeroCli.stHeroAttrAddInfo.dwAddTalent;

        stUpgradeHeroCli_v410.stHeroBaseInfo = stUpgradeHeroCli.stHeroBaseInfo;
        stUpgradeHeroCli_v410.stSkillInfo = stUpgradeHeroCli.stSkillInfo;
    }

    return TRUE;
}

BOOL CPlayer::GetDT_RECRUIT_HERO_DATA_OF_GM(CHero* poHero, DT_RECRUIT_HERO_DATA& stDT_RECRUIT_HERO_DATA)
{
    if (!GetDT_RECRUIT_HERO_DATA(poHero, stDT_RECRUIT_HERO_DATA))
    {
        return FALSE;
    }

    stDT_RECRUIT_HERO_DATA.byRecuitUnLock = 1;
    return TRUE;
}

BOOL CPlayer::GetDT_RECRUIT_HERO_DATA_OF_GM_v410(CHero* poHero, DT_RECRUIT_HERO_DATA_v410& stRecruitData)
{
    if (!GetDT_RECRUIT_HERO_DATA_v410(poHero, stRecruitData)){
        return FALSE;
    }

    stRecruitData.byRecuitUnLock = 1;
    return TRUE;
}


//��ȡ�򿪾�������Ϣ
UINT16 CPlayer::GetOpenRaceBuildAck(PKT_CLIGS_OPEN_RACE_BUILD_ACK& stAck)
{
    CBuild* poBuild = GetBuild(EBK_RACEBUILD);
    if(NULL == poBuild)
    {
        return ERR_OPEN_RACE_BUILD::ID_NOT_EXIST_ERR;
    }
    poBuild->OnOpen();

    if(NULL == m_poRace)
    {
		SET_OTHER_ERR(stAck.wErrCode);
        return stAck.wErrCode;
    }

    //������Ϣ
    stAck.wLevel = GetLevel();
    //stAck.dwFame = m_poOwner->GetDT_PLAYER_BASE_DATA().dwFame;
    DT_RACE_BASE_DATA& stDT_RACE_BASE_DATA = m_poRace->GetDT_RACE_BASE_DATA();
    stAck.dwRank = stDT_RACE_BASE_DATA.dwRank;
    stAck.wContiWin = stDT_RACE_BASE_DATA.wContiWin;
    SRaceBaseProp& stRaceBaseProp = CRacePropMgr::Instance()->GetRaceProp();
    stAck.qwScience = m_stDT_PLAYER_BASE_DATA.qwScience;
    stAck.dwPower = m_stDT_PLAYER_BASE_DATA.dwPower;
	stAck.qwJingJie = m_stDT_PLAYER_BASE_DATA.qwJingJie;
    stAck.dwClrCDGold = CRacePropMgr::Instance()->GetRaceProp().dwClrCDGoldPerMinute;

    //�ж�ʱ��
    stAck.byHaveRecvEncourageFlag = 0;
    //�ϴ���ȡ����Ϊ����
    if(IsToday(stDT_RACE_BASE_DATA.qwRecvEncourageTime))
    {
        stAck.byHaveRecvEncourageFlag = 1;

		USR_INFO( _SDT("PlayerID[%u] Not Recv Encourage"), GetDT_PLAYER_BASE_DATA().dwID);
    }

    CRacePropMgr::Instance()->GetRankEncourage(stDT_RACE_BASE_DATA.dwRecvEncourageRank, stAck.stTodayRankEncourage);
    CRacePropMgr::Instance()->GetRankEncourage(stDT_RACE_BASE_DATA.dwRank, stAck.stTomorrowRankEncourage);
    CRacePropMgr::Instance()->GetCanChallengeTimes(this, stDT_RACE_BASE_DATA.qwLastChallTime, stDT_RACE_BASE_DATA.byChallTimes, stDT_RACE_BASE_DATA.wContiWin, stDT_RACE_BASE_DATA.byFailedFlag,
            stAck.wChallengeCountDown, stAck.wTotalChallengeNum, stAck.wCanChallengeNum, stAck.wVipExtNum, stAck.wFreeChallengeNum, stAck.dwChallengeNeedGold);
    CRaceMgr::Instance()->GetChallengePlayerList(stAck.dwRank, stAck.byChallengeNum, stAck.astChallengePlayerList);

	//DBG_INFO( _SDT("PlayerID[%u] Race Info [%u, %u, %u, %u]"), GetDT_PLAYER_BASE_DATA().dwID, 
		//stAck.wChallengeCountDown, stAck.wCanChallengeNum, stAck.wFreeChallengeNum, stAck.dwChallengeNeedGold);
	if (m_poWorship)
	{
		stAck.byHaveWorship = m_poWorship->CKCanWorship(EWT_RACE, FALSE) ? 0 : 1;
	}

	INT32 nTmp = SDNow().DiffDateDay(CGSConfig::Instance()->GetServerOpentTime());
	UINT16 wRecvRankPassDay = CRacePropMgr::Instance()->GetRaceProp().wRecvRankPassDay;
	stAck.byRecvEncCountDown = nTmp < wRecvRankPassDay ? wRecvRankPassDay - nTmp : 0;//2���ſ���ȡ����������

    stAck.wErrCode = ERR_OPEN_RACE_BUILD::ID_SUCCESS;
    return stAck.wErrCode;
}

UINT16 CPlayer::GetOpenSimthyAck(PKT_CLIGS_OPEN_SMITHY_ACK& stAck)
{
    CBuild* poBuild = GetBuild(EBK_SMITHY);
    if(NULL == poBuild)
    {
        return ERR_OPEN_SMITHY::ID_NOT_EXIST_ERR;
    }
    poBuild->OnOpen();

    memset(&stAck, 0, sizeof(PKT_CLIGS_OPEN_SMITHY_ACK));

    //��ȡ���е�װ��
    GetAllEquip(stAck.stEquipList, stAck.adwStrengthen10CoinInfo);

    // 
    stAck.wEquipNum = stAck.stEquipList.wEquipNum;
    // ��ȡ�����ʶ�ֽڴ�
    COpenLightPropMgr::Instance()->GetOpenLightFlagInfo(stAck);

    CBuildPropMgr::Instance()->GetBuyEquipCliData(stAck.astByEquipInfo);

    stAck.dwClrCDGold = CEquipStrengthenPropMgr::Instance()->GetClrStrengthenCDGold();
    stAck.wStrengthenCD = CEquipStrengthenPropMgr::Instance()->GetTotalCD();
    stAck.wStrengthenCountDown = GetStrenthenCountDown();
	stAck.qwBlueGas = m_stDT_PLAYER_BASE_DATA.qwBlueGas;

    return ERR_OPEN_SMITHY::ID_SUCCESS;
}

UINT16 CPlayer::GetOpenSmithyAck_v410(PKT_CLIGS_OPEN_SMITHY_ACK_v410& stAck)
{
    CBuild* poBuild = GetBuild(EBK_SMITHY);
    if(NULL == poBuild)
    {
        return ERR_OPEN_SMITHY::ID_NOT_EXIST_ERR;
    }

    CBuild* poEnchantBuild = GetBuild(EBK_ENCHANT);
    if (poEnchantBuild){
        poEnchantBuild->OnOpen();
    }

    poBuild->OnOpen();
    memset(&stAck, 0, sizeof(stAck));

    //��ȡ���е�װ��
    GetAllEquip_v410(stAck.stEquipList);

    // ��ȡ�����ʶ�ֽڴ�
    COpenLightPropMgr::Instance()->GetOpenLightFlagInfo_v410(stAck);
    CBuildPropMgr::Instance()->GetBuyEquipCliData(stAck.astByEquipInfo);

    stAck.dwClrCDGold = CEquipStrengthenPropMgr::Instance()->GetClrStrengthenCDGold();
    stAck.wStrengthenCD = CEquipStrengthenPropMgr::Instance()->GetTotalCD();
    stAck.wStrengthenCountDown = GetStrenthenCountDown();
    stAck.qwBlueGas = m_stDT_PLAYER_BASE_DATA.qwBlueGas;
    return ERR_OPEN_SMITHY::ID_SUCCESS;
}

UINT16 CPlayer::Crown(UINT8& byCanCrowFlag)
{
    CBuild* poBuild = GetBuild(EBK_MAINTOWN);
    if(NULL == poBuild)
    {
        return ERR_RECV_MAINTOWN_INCOME::ID_BUILD_NOT_EXIST;
    }

    DT_BUILD_BASE_DATA&  stDT_BUILD_BASE_DATA = poBuild->GetDT_BUILD_BASE_DATA();

    //Value1 ,��������Ϊ�ջ�ʱ��
    //Value2 ,��������Ϊ����ʱ��
    //Value3 ,��������Ϊ���յĴ���

    //�ж�ʱ��
    //�����Ѿ��ջ��
    if(IsToday(stDT_BUILD_BASE_DATA.qwValue1))
    {
        byCanCrowFlag = 0;
        return ERR_RECV_MAINTOWN_INCOME::ID_HAVE_RECV;
    }
    UINT16 wCurLevel = GetLevel();
	AddCoin( CLuamgr::Instance()->GetMaintownCrownCoin(wCurLevel), CRecordMgr::EGGT_ADDFLAGCROWN );	
	AddGold( CLuamgr::Instance()->GetMaintownCrownGold(wCurLevel), CRecordMgr::EGGT_ADDFLAGCROWN );
	//if(GetBuild(EBK_JINGJIE))
	//{
	AddJingJie( CLuamgr::Instance()->GetMaintownCrownJingJie(wCurLevel), CRecordMgr::EGGT_ADDFLAGCROWN );
	//}
	
    byCanCrowFlag = 0;
    stDT_BUILD_BASE_DATA.qwValue1 = SDTimeSecs();

    //��¼������
    AddGuideRecord( EGF_CROWN);

    return ERR_RECV_MAINTOWN_INCOME::ID_SUCCESS;
}

UINT16 CPlayer::Levy(UINT32& dwLevyCountDown, UINT8& byLevyNum)
{
    CBuild* poBuild = GetBuild(EBK_LEVY);
    if(NULL == poBuild)
    {
        return ERR_LEVY_MAINTOWN_INCOME::ID_BUILD_NOT_EXIST;
    }
    poBuild->OnOpen();

    DT_BUILD_BASE_DATA&  stDT_BUILD_BASE_DATA = poBuild->GetDT_BUILD_BASE_DATA();

    //Value1 ,��������Ϊ�ջ�ʱ��
    //Value2 ,��������Ϊ����ʱ��
    //Value3 ,��������Ϊ���յĴ���

    //����δ���գ����¸�ֵ���մ���0
    if(!IsToday(stDT_BUILD_BASE_DATA.qwValue2))
    {
        stDT_BUILD_BASE_DATA.byValue3 = 0; //
    }
	UINT64 qnPassTime = SDTimeSecs() - stDT_BUILD_BASE_DATA.qwValue2;
	if(qnPassTime < m_pstMaintownLevyProp->dwLevyCD)
	{
		dwLevyCountDown = m_pstMaintownLevyProp->dwLevyCD - (UINT32)qnPassTime;
		return ERR_LEVY_MAINTOWN_INCOME::ID_IN_CD;
	}
    byLevyNum = (m_pstMaintownLevyProp->byLevyNumPerDay > stDT_BUILD_BASE_DATA.byValue3) ? m_pstMaintownLevyProp->byLevyNumPerDay - stDT_BUILD_BASE_DATA.byValue3 : 0;
    if(0 == byLevyNum)
    {
        return ERR_LEVY_MAINTOWN_INCOME::ID_REACH_MAX_LEVY_NUM;
    }
	AddCoin(CLuamgr::Instance()->GetMaintownLevyCoin(GetLevel()), CRecordMgr::EACT_LEVY);
	//if(GetBuild(EBK_JINGJIE))
	//{
	AddJingJie(CLuamgr::Instance()->GetMaintownLevyJingJie(GetLevel()), CRecordMgr::EAJT_LEVY);	
	//}	
    stDT_BUILD_BASE_DATA.qwValue2 = SDTimeSecs();

    stDT_BUILD_BASE_DATA.byValue3++;
    byLevyNum--;
    dwLevyCountDown = m_pstMaintownLevyProp->dwLevyCD;

    CTaskMgr::Instance()->OnCrown(this);
    AddGuideRecord( EGF_LEVY);
    return ERR_LEVY_MAINTOWN_INCOME::ID_SUCCESS;
}


UINT32 CPlayer::GetLevyCountDown()
{
    CBuild* poBuild = GetBuild(EBK_LEVY);
    if(NULL == poBuild)
    {
        return 0;
    }

    DT_BUILD_BASE_DATA&  stDT_BUILD_BASE_DATA = poBuild->GetDT_BUILD_BASE_DATA();

    //Value1 ,��������Ϊ�ջ�ʱ��
    //Value2 ,��������Ϊ����ʱ��
    //Value3 ,��������Ϊ���յĴ���

    //�ж�ʱ��
    UINT64 qnGap = SDTimeSecs() - stDT_BUILD_BASE_DATA.qwValue2;
    if(qnGap < 0)
    {
        return 0;
    }
    else
    {
        if(qnGap >= m_pstMaintownLevyProp->dwLevyCD)
        {
            return 0;
        }
        else
        {
            return m_pstMaintownLevyProp->dwLevyCD - (UINT32)qnGap;
        }
    }

    return 0;
}


UINT16 CPlayer::OpenMainTown(UINT16& wCurLevel,UINT8& byCanCrowFlag, UINT32& dwCrownCoin, UINT32& dwCrownGold, UINT32& dwCrownJingJie,
	UINT32& dwLevyCountDown, UINT32& dwLevyCoin, UINT32& dwLevyJingJie, UINT8& byLevyNum, UINT8 &byTotalLevyNum)
{
    CBuild* poBuild = GetBuild(EBK_MAINTOWN);
    if(NULL == poBuild)
    {
        return ERR_OPEN_MAINTOWN::ID_BUILD_NOT_EXIST;
    }
    poBuild->OnOpen();



    wCurLevel = GetLevel();

    //Value1 ,��������Ϊ�ջ�ʱ��
    //Value2 ,��������Ϊ����ʱ��
    //Value3 ,��������Ϊ���յĴ���

    DT_BUILD_BASE_DATA&  stDT_BUILD_BASE_DATA = poBuild->GetDT_BUILD_BASE_DATA();
    //�����Ѿ��ջ��
    if(IsToday(stDT_BUILD_BASE_DATA.qwValue1))
    {
        byCanCrowFlag = 0;
    }
    else
    {
        byCanCrowFlag = 1;
        stDT_BUILD_BASE_DATA.byValue3 = 0; //���¸�ֵ���մ���
    }
    dwCrownCoin = CLuamgr::Instance()->GetMaintownCrownCoin(wCurLevel);
    dwCrownGold = CLuamgr::Instance()->GetMaintownCrownGold(wCurLevel);
	//if(GetBuild(EBK_JINGJIE))
	//{
	dwCrownJingJie = CLuamgr::Instance()->GetMaintownCrownJingJie(wCurLevel);
	dwLevyJingJie = CLuamgr::Instance()->GetMaintownLevyJingJie(wCurLevel);
	//}	
	//else
	//{
	//	dwCrownJingJie = 0;
	//	dwLevyJingJie = 0;
	//}
    dwLevyCoin = CLuamgr::Instance()->GetMaintownLevyCoin(wCurLevel);

    CBuild* poBuildEx = GetBuild(EBK_LEVY);
    if(NULL == poBuildEx)
    {
        return ERR_OPEN_MAINTOWN::ID_SUCCESS;
    }
    poBuildEx->OnOpen();
    DT_BUILD_BASE_DATA&  stDT_BUILD_BASE_DATAEX = poBuildEx->GetDT_BUILD_BASE_DATA();

    //����δ���գ����¸�ֵ���մ���0
    if(!IsToday(stDT_BUILD_BASE_DATAEX.qwValue2))
    {
        stDT_BUILD_BASE_DATAEX.byValue3 = 0; //
    }
    byLevyNum = (m_pstMaintownLevyProp->byLevyNumPerDay > stDT_BUILD_BASE_DATAEX.byValue3) ? m_pstMaintownLevyProp->byLevyNumPerDay - stDT_BUILD_BASE_DATAEX.byValue3 : 0;
    if(byLevyNum > 0)
    {
        dwLevyCountDown = GetLevyCountDown();
    }
    byTotalLevyNum = m_pstMaintownLevyProp->byLevyNumPerDay;
    return ERR_OPEN_MAINTOWN::ID_SUCCESS;
}

UINT16 CPlayer::OpenSmithyIcon(UINT8 &byNum, DT_DOGFECES_BUILD_TIP astDogFecesBuildTip[MAX_DOGFECES_BUILD_TIP_NUM], DT_FUNC_PROMPT_DATA &stPromptInfo)
{
    CBuild* poBuild = GetBuild(EBK_SMITHY);
    if(NULL == poBuild)
    {
        return ERR_OPEN_DOGFECES::ID_SUCCESS;
    }

    /*
    if (poBuild = GetBuild(EBK_EQUPUPGRADE)){
        poBuild->OnOpen();
        DT_FUNC_COMMON_PROMPT &stBuildPrompt = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
        stBuildPrompt.byBuildKindID = EBK_EQUPUPGRADE;
    }

    if (poBuild = GetBuild(EBK_XIANGQIAN)){
        poBuild->OnOpen();
        DT_FUNC_COMMON_PROMPT &stBuildPrompt = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
        stBuildPrompt.byBuildKindID = EBK_XIANGQIAN;
    }
    */

    if (poBuild = GetBuild(EBK_SMITHY)){
        poBuild->OnOpen();
        DT_FUNC_COMMON_PROMPT &stBuildPrompt = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
        GetStrengthenPrompt(stBuildPrompt);
    }

    if (poBuild = GetBuild(EBK_ENCHANT)){
        poBuild->OnOpen();
        DT_FUNC_COMMON_PROMPT &stBuildPrompt = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
        GetEnchantPrompt(stBuildPrompt);
    }

    if (poBuild = GetBuild(EBK_EQUIP_MAKE)){
        poBuild->OnOpen();
        DT_FUNC_COMMON_PROMPT &stBuildPrompt = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
        GetEquipMakePrompt(stBuildPrompt);
    }

    return ERR_OPEN_DOGFECES::ID_SUCCESS;
}

UINT16 CPlayer::OpenDogFeces(UINT8 byType, UINT8 &byNum, DT_DOGFECES_BUILD_TIP astDogFecesBuildTip[MAX_DOGFECES_BUILD_TIP_NUM], DT_FUNC_PROMPT_DATA &stPromptInfo)
{
	byNum = 0;
	if (EPDFB_RACE == byType)
	{
		CBuild* poBuild = GetBuild(EBK_PVP);
		if(NULL == poBuild)
		{
			return ERR_OPEN_DOGFECES::ID_SUCCESS;
		}
		poBuild->OnOpen();

		//������
		CC_LOOP_DO
		CC_LOOP_BREAK(NULL == GetBuild(EBK_RACEBUILD))
		CRace *poRace = GetRace();
		CC_LOOP_BREAK (NULL == poRace)
		astDogFecesBuildTip[byNum].wBuildID = EBK_RACEBUILD;
		poRace->GetChallengeTimes(astDogFecesBuildTip[byNum].dwParameter1, astDogFecesBuildTip[byNum].dwParameter2);
		byNum++;
		GetRacePrompt(stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++]); //��������ʾ��Ϣ
		CC_LOOP_WHILE(0)

		
		//������
		CC_LOOP_DO
		CC_LOOP_BREAK(NULL == GetBuild(EBK_RDCHALLENGE) || NULL == m_poRdChallenge)
		astDogFecesBuildTip[byNum].wBuildID = EBK_RDCHALLENGE;
		m_poRdChallenge->GetChallengeTimes(astDogFecesBuildTip[byNum].dwParameter1, astDogFecesBuildTip[byNum].dwParameter2);
		byNum++;
		GetRdChallengePrompt(stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++]); //������ʾ��Ϣ
		CC_LOOP_WHILE(0)
	}
	else if (EPDFB_ADVENTURE == byType)
	{
		CBuild* poBuild = GetBuild(EBK_ADVENTURE);
		if(NULL == poBuild)
		{
			return ERR_OPEN_DOGFECES::ID_SUCCESS;
		}
		poBuild->OnOpen();

		//��Ӣ����
		CC_LOOP_DO
		CC_LOOP_BREAK(NULL == GetBuild(EBK_ELITEINSTANCE))
		CRace *poRace = GetRace();
		CC_LOOP_BREAK (NULL == poRace)
		astDogFecesBuildTip[byNum].wBuildID = EBK_ELITEINSTANCE;
		m_poInstance->GetEliteInstanceNum(astDogFecesBuildTip[byNum].dwParameter1, astDogFecesBuildTip[byNum].dwParameter2);
		byNum++;
		GetElitePrompt(stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++]); //��Ӣ��ʾ��Ϣ
		CC_LOOP_WHILE(0)

        //���ݸ���
        CC_LOOP_DO
        CC_LOOP_BREAK(NULL == GetBuild(EBK_CLIMBTOWER))
        astDogFecesBuildTip[byNum].wBuildID = EBK_CLIMBTOWER;
        m_poInstance->GetClimbTownInstanceNum(astDogFecesBuildTip[byNum].dwParameter1, astDogFecesBuildTip[byNum].dwParameter2);
        byNum++;
        GetClimbTowerPrompt(stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++]); //������ʾ��Ϣ
        CC_LOOP_WHILE(0)


        //Ѻ�ڸ���
        CC_LOOP_DO
        CC_LOOP_BREAK(NULL == GetBuild(EBK_YABIAO))
        CC_LOOP_BREAK(NULL == m_poYabiaoInfo)

        m_poYabiaoInfo->Check4Reset();
        astDogFecesBuildTip[byNum].wBuildID = EBK_YABIAO;
        astDogFecesBuildTip[byNum].dwParameter1	= m_poYabiaoInfo->GetRemainYabiaoCnt();
        astDogFecesBuildTip[byNum].dwParameter2	= m_poYabiaoInfo->GetRemainJiebiaoCnt();
        DT_FUNC_COMMON_PROMPT &stBuildPromptInfo = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
        GetYabiaoPrompt(stBuildPromptInfo); //Ѻ����ʾ��Ϣ

		//�����ʾ����ȡ��������ʱ�仹�е���ʱ��
		if (stBuildPromptInfo.byFuncFlag == ms_nPromotYabiaoRunning && stBuildPromptInfo.dwFuncCountDown > 0)
		{
			stBuildPromptInfo.byFuncFlag = 0;
			//�����ش�������0��ֱ����ʾ�����ء�
			if (astDogFecesBuildTip[byNum].dwParameter2 > 0)
			{
				//�ͻ���ֻʶ��������BUG
				stBuildPromptInfo.byFuncFlag = ms_nPromotYabiaoSucceed;
			}
		}
		byNum++;
		CC_LOOP_WHILE(0)

		CC_LOOP_DO
		CC_LOOP_BREAK(NULL == GetBuild(EBK_FACTION))
		CC_LOOP_BREAK(NULL == m_poFactionPlayer)
		DT_FUNC_COMMON_PROMPT &stBuildPromptInfo = stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++];
		GetFactionPrompt(stBuildPromptInfo);
		CC_LOOP_WHILE(0)

		//ս�긱��
		CC_LOOP_DO
		CC_LOOP_BREAK(NULL == GetBuild(EBK_SOUL))
		CPlayerSoul *poSoul = GetPlayerSoul();
		CC_LOOP_BREAK (NULL == poSoul)
		GetSoulInstancePrompt(stPromptInfo.astBuildPromptInfo[stPromptInfo.byBuildNum++]); //��Ӣ��ʾ��Ϣ
		CC_LOOP_WHILE(0)
	}
    else if (EPDFB_SMITHY== byType)
    {
        return OpenSmithyIcon(byNum, astDogFecesBuildTip, stPromptInfo);
    }

	return ERR_OPEN_DOGFECES::ID_SUCCESS;
}

