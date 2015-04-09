#include "godweaponmgr.h"
#include "godweaponbasepropmgr.h"
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <common/client/errdef.h>
#include <logic/build/buildmgr.h>
#include <logic/player/playermgr.h>
#include <logic/record/recordmgr.h>
#include <logic/vip/vippropmgr.h>
#include <logic/other/singleprammgr.h>
#include <logic/base/basedefine.h>
#include <logic/base/logicfunc.h>
#include <logic/hero/hero.h>
#include <logic/bag/bag.h>
#include <logic/task/taskmgr.h>
#include <sddir.h>
#include <logic/player/player.h>
#include <utility.h>

#include <logic/item/goods/goodspropmgr.h>

IMPLEMENT_SINGLETON(CGodweaponMgr)


CGodweaponMgr::CGodweaponMgr()
{
    m_dwUpgradeQualityItemPrice = 0;
    m_wUpgradeQualityItemID = 0;
    m_dwActiveCoin = 0;
}

CGodweaponMgr::~CGodweaponMgr()
{
}

BOOL CGodweaponMgr::Init()
{

    // ��ʼ��CGodweaponBasePropMgr������
    if(FALSE == CGodweaponBasePropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGodweaponBasePropMgr::CreateBuild failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CGodweaponBasePropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGodweaponBasePropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    // ��ʼ��CGodweaponPropMgr������
    if(FALSE == CGodweaponPropMgr::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGodweaponPropMgr::CreateBuild failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CGodweaponPropMgr::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CGodweaponPropMgr Init failed!"), MSG_MARK);
        return FALSE;
    }

    SGoodsProp* pstGoodsProp = CGoodsPropMgr::Instance()->GetPropByPrimaryKey(CGodweaponBasePropMgr::Instance()->GetUpgradeQualityItemID());
    if(pstGoodsProp)
    {
        m_dwUpgradeQualityItemPrice = pstGoodsProp->dwBuyGold;
        m_wUpgradeQualityItemID = pstGoodsProp->wKindID;
    }
    m_dwActiveCoin = CGodweaponBasePropMgr::Instance()->GetActiveCoin();

    return TRUE;
}


VOID CGodweaponMgr::UnInit()
{
    CGodweaponBasePropMgr::Instance()->UnInit();
    CGodweaponPropMgr::Instance()->UnInit();
}


CGodWeapon* CGodweaponMgr::CreateGodWeapon(UINT32 dwPlayerID, UINT16 wHeroKindID)
{
    CGodWeapon*poGodWeapon = m_oGodWeaponShmemObjMgr.Alloc();
    if(NULL == poGodWeapon)
    {
        return NULL;
    }
    UINT64 qwKey = CLogicFunc::GetObjKey(dwPlayerID, wHeroKindID);
    m_mapID2GodWeapon[qwKey] = poGodWeapon;

    return poGodWeapon;
}

VOID CGodweaponMgr::RemoveGodWeapon(UINT32 dwPlayerID, UINT16 wHeroKindID)
{
    UINT64 qwKey = CLogicFunc::GetObjKey(dwPlayerID, wHeroKindID);
    CID2GodWeaponMapItr itr = m_mapID2GodWeapon.find(qwKey);
    if (m_mapID2GodWeapon.end() != itr)
    {
        CGodWeapon* poGodWeapon = itr->second;
        m_oGodWeaponShmemObjMgr.Free(poGodWeapon);
        m_mapID2GodWeapon.erase(itr);
    }
}
//
//VOID CGodweaponMgr::UpgradeGodweapon4Enc(CPlayer* poPlayer)
//{
//    if(NULL == poPlayer)
//    {
//        return;
//    }
//    if(!poPlayer->GetBuild(EBK_GODWEAPON))
//    {
//        return;
//    }
//
//
//    //��������
//    string  ssTxt;
//    map<UINT16, CHero*> mapHero;
//    CGodWeapon* apoGodWeapon[3] = {0};
//    CFormationHeroShmemMap& mapFormationHero = poPlayer->GetFormationHeroMap();
//    CHero* poHero = mapFormationHero.GetFistData();
//    do
//    {
//        if(NULL == poHero)
//        {
//            break;
//        }
//        mapHero[poHero->GetDT_HERO_BASE_DATA().wKindID] = poHero;
//        CGodWeapon* poGodweapon = poHero->GetGodweapon();
//        if(NULL == poGodweapon)
//        {
//            continue;
//        }
//        GetTop3(poGodweapon, apoGodWeapon);
//    }
//    while(poHero = mapFormationHero.GetNextData());
//
//    CKindID2HeroShmemMap& mapKind2HeroAllCarry = poPlayer->GetAllCarryHeroMap();
//    poHero = mapKind2HeroAllCarry.GetFistData();
//    do
//    {
//        if(NULL == poHero)
//        {
//            break;
//        }
//        if(NULL != mapHero[poHero->GetDT_HERO_BASE_DATA().wKindID])
//        {
//            continue;
//        }
//        CGodWeapon* poGodweapon = poHero->GetGodweapon();
//        if(NULL == poGodweapon)
//        {
//            continue;
//        }
//        GetTop3(poGodweapon, apoGodWeapon);
//    }
//    while(poHero = mapKind2HeroAllCarry.GetNextData());
//
//
//    for(UINT8 byIdx = 0; byIdx < 3; byIdx++)
//    {
//        if(apoGodWeapon[byIdx])
//        {
//            UpgradeGodweaponByScience(poPlayer, apoGodWeapon[byIdx], ssTxt, byIdx + 1);
//        }
//    }
//
//    //poPlayer->GetExtData() = 3;//��������������ת��������ʱ��ȡ��ʾ��Ϣ
//
//    //��Ϊ�գ���ֱ�ӷ���
//    //if(ssTxt.empty())
//    //{
//    //    return;
//    //}
//
//    //string strTmp = SDGBK2UTF8(ssTxt.c_str());
//
//    ////����ʾ��Ϣд���ļ��У����´δ�����ʹ��
//    //CHAR szDir[1024] = {0};
//    //sprintf( szDir, "%s../%s", (const CHAR*)SDGetModulePath(), "godweaponprompt");
//    //if( !SDDirectoryExists( szDir ) )
//    //{
//    //    if( !SDCreateDirectory( szDir, TRUE ) )
//    //    {
//    //        SYS_CRITICAL(_SDT("[%s: %d]: create directory failed!path:%s"), MSG_MARK, szDir);
//    //        return;
//    //    }
//    //}
//    //sprintf( szDir, "%s%s_%d", szDir, "gdp_",  poPlayer->GetID() % 10);
//    //if( !SDDirectoryExists( szDir ) )
//    //{
//    //    if( !SDCreateDirectory( szDir, TRUE ) )
//    //    {
//    //        SYS_CRITICAL(_SDT("[%s: %d]: create directory failed!path:%s"), MSG_MARK, szDir);
//    //        return;
//    //    }
//    //}
//
//    //CHAR szFilePath[1024] = {0};
//
//    //sprintf( szFilePath, "%s/%d.txt", szDir, poPlayer->GetID() );
//    //std::ofstream outFile;
//    //outFile.open( szFilePath, ios::trunc | ios::in);
//
//    //if( !outFile.is_open() )
//    //{
//    //    SYS_CRITICAL(_SDT("[%s: %d]: create file failed!path:%s"), MSG_MARK, szFilePath);
//    //    return;
//    //}
//
//    //outFile.write( strTmp.c_str(), strTmp.size() );
//    //outFile << endl;
//
//    //outFile.close();
//}

//VOID CGodweaponMgr::UpgradeGodweaponByScience(CPlayer* poPlayer, CGodWeapon* poGodweapon, string& ssTxt, UINT8 byIdx)
//{
//    /*
//    1~5		40000
//    6~10	70000
//    11~15	120000
//    16~20	200000
//    */
//
//    DT_GODWEAPON_DATA stOldDT_GODWEAPON_DATA = poGodweapon->GetDT_GODWEAPON_DATA();
//    if(stOldDT_GODWEAPON_DATA.wQuality < 6)
//    {
//        poGodweapon->UpgradeByScience(40000);
//    }
//    else if(stOldDT_GODWEAPON_DATA.wQuality < 11)
//    {
//        poGodweapon->UpgradeByScience(70000);
//    }
//    else if(stOldDT_GODWEAPON_DATA.wQuality < 16)
//    {
//        poGodweapon->UpgradeByScience(120000);
//    }
//    else
//    {
//        poGodweapon->UpgradeByScience(200000);
//    }
//
//    DT_GODWEAPON_DATA stNewDT_GODWEAPON_DATA = poGodweapon->GetDT_GODWEAPON_DATA();
//
//    CHero* poHero = poPlayer->GetHero(stNewDT_GODWEAPON_DATA.wHeroKindID);
//    if(NULL == poHero)
//    {
//        return;
//    }
//    SHeroProp* pstHeroProp = poHero->GetHeroProp();
//    if(NULL == pstHeroProp)
//    {
//        return;
//    }
//    //����txt
//    if(1 == byIdx)
//    {
//        ssTxt += "���ڱ��θİ�������淨�����Ϊ��л���ԡ������Ρ���֧�֣����ǽ��������ڸİ�ǰ������ϵͳ���������ľ�����Ԫ�������������ǡ��Լ������ȼ���ߵ�2�����������Ƚ׷ֱ�������Ӧ������";
//        ssTxt += "�İ�ǰ�������Ƚױ仯��";
//    }
//
//    char v_szTemp[256] = {0};
//    sprintf(v_szTemp, "%u", (UINT32)byIdx);
//    ssTxt += v_szTemp;
//    ssTxt += "�� ";
//    if(stOldDT_GODWEAPON_DATA.wHeroKindID < 10)
//    {
//        ssTxt += "����";
//    }
//    else
//    {
//        ssTxt += "���";
//        ssTxt += SDUTF82Source("GBK", pstHeroProp->szName);
//    }
//    ssTxt += "��������";
//    sprintf(v_szTemp, "%u", (UINT32)stOldDT_GODWEAPON_DATA.wQuality);
//    ssTxt += v_szTemp;
//    ssTxt += "��";
//    sprintf(v_szTemp, "%u", (UINT32)stOldDT_GODWEAPON_DATA.wLevel);
//    ssTxt += v_szTemp;
//    ssTxt += "������Ϊ";
//    sprintf(v_szTemp, "%u", (UINT32)stNewDT_GODWEAPON_DATA.wQuality);
//    ssTxt += v_szTemp;
//    ssTxt += "��";
//    sprintf(v_szTemp, "%u", (UINT32)stNewDT_GODWEAPON_DATA.wLevel);
//    ssTxt += v_szTemp;
//    ssTxt += "��";
//    if(3 == byIdx)
//    {
//        ssTxt += "\n";
//        ssTxt += "ϣ����������Ϸ��������Ȥ��ף����Ϸ��졣";
//    }
//}

BOOL HighGodweapon(DT_GODWEAPON_DATA& stSrc, DT_GODWEAPON_DATA& stDst)
{
    if(stSrc.wQuality > stDst.wQuality)
    {
        return TRUE;
    }
    else if((stSrc.wQuality == stDst.wQuality) && (stSrc.wLevel > stDst.wLevel))
    {
        return TRUE;
    }

    return FALSE;
}

//VOID CGodweaponMgr::GetTop3(CGodWeapon* poGodweapon, CGodWeapon* apoGodWeapon[3])
//{
//    if(NULL == apoGodWeapon[0])
//    {
//        apoGodWeapon[0] = poGodweapon;
//    }
//    else if(NULL == apoGodWeapon[1])
//    {
//        apoGodWeapon[1] = poGodweapon;
//    }
//    else if(NULL == apoGodWeapon[2])
//    {
//        apoGodWeapon[2] = poGodweapon;
//    }
//    else
//    {
//        if(HighGodweapon(poGodweapon->GetDT_GODWEAPON_DATA(), apoGodWeapon[0]->GetDT_GODWEAPON_DATA()))
//        {
//            apoGodWeapon[0] = poGodweapon;
//        }
//        else if(HighGodweapon(poGodweapon->GetDT_GODWEAPON_DATA(), apoGodWeapon[1]->GetDT_GODWEAPON_DATA()))
//        {
//            apoGodWeapon[1] = poGodweapon;
//        }
//        else if(HighGodweapon(poGodweapon->GetDT_GODWEAPON_DATA(), apoGodWeapon[2]->GetDT_GODWEAPON_DATA()))
//        {
//            apoGodWeapon[2] = poGodweapon;
//        }
//    }
//}

UINT16 CGodweaponMgr::OpenGodweapon(CPlayer* poPlayer, UINT16& wGodweaponNum, DT_GODWEAPON_DATA_CLI astGodweaponLst[MAX_HERO_NUM], UINT16& wUpgradeQualityItemNum,
                                    UINT32& dwUpgradeQualityItemPrice, UINT16& wUpgradeQualityItemID, UINT32& dwActiveCoin, TCHAR aszExtContext[MAX_COMMON_TXT_LEN])
{
    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    wGodweaponNum = 0;

    //�Ȱ������˳���·���Ȼ���·�������
    map<UINT16, CHero*> mapHero;
    vector<CGodWeapon*> vecAllGodWeapon;
    CFormationHeroShmemMap& mapFormationHero = poPlayer->GetFormationHeroMap();
    CHero* poHero = mapFormationHero.GetFistData();
    do
    {
        if(NULL == poHero)
        {
            break;
        }
        mapHero[poHero->GetDT_HERO_BASE_DATA().wKindID] = poHero;
        CGodWeapon* poGodweapon = poHero->GetGodweapon();
        if(NULL == poGodweapon)
        {
            continue;
        }
        vecAllGodWeapon.push_back(poGodweapon);
    }
    while(poHero = mapFormationHero.GetNextData());

    CKindID2HeroShmemMap& mapKind2HeroAllCarry = poPlayer->GetAllCarryHeroMap();
    poHero = mapKind2HeroAllCarry.GetFistData();
    do
    {
        if(NULL == poHero)
        {
            break;
        }
        if(NULL != mapHero[poHero->GetDT_HERO_BASE_DATA().wKindID])
        {
            continue;
        }
        CGodWeapon* poGodweapon = poHero->GetGodweapon();
        if(NULL == poGodweapon)
        {
            continue;
        }
        vecAllGodWeapon.push_back(poGodweapon);
    }
    while(poHero = mapKind2HeroAllCarry.GetNextData());

    UINT8 bySize = (UINT8)(vecAllGodWeapon.size());
    for(UINT8 byIdx = 0; byIdx < bySize; byIdx++)
    {
        vecAllGodWeapon[byIdx]->GetDT_GODWEAPON_DATA_CLI(astGodweaponLst[wGodweaponNum++]);
    }

    //������Ʒ
    CGoods* poGoods = poPlayer->GetBag().GetGoodsItem(m_wUpgradeQualityItemID);
    if(NULL == poGoods)
    {
        wUpgradeQualityItemNum = 0;
    }
    else
    {
        wUpgradeQualityItemNum = poGoods->GetCurPileNum();
    }
    dwUpgradeQualityItemPrice = m_dwUpgradeQualityItemPrice;
    wUpgradeQualityItemID = m_wUpgradeQualityItemID;
    dwActiveCoin = m_dwActiveCoin;

    //��ȡ����������ʾ
    //if(3 == poPlayer->GetExtData())
    //{
    //    do
    //    {
    //        CHAR szDir[1024] = {0};
    //        sprintf( szDir, "%s../%s/%s_%d", (const CHAR*)SDGetModulePath(), "godweaponprompt", "gdp_",  poPlayer->GetID() % 10);
    //        if( !SDDirectoryExists( szDir ) )
    //        {
    //            if( !SDCreateDirectory( szDir, TRUE ) )
    //            {
    //                SYS_CRITICAL(_SDT("[%s: %d]: create directory failed!path:%s"), MSG_MARK, szDir);
    //                break;
    //            }
    //        }

    //        CHAR szFilePath[1024] = {0};
    //        sprintf( szFilePath, "%s/%d.txt", szDir, poPlayer->GetID() );
    //        ifstream inFile( szFilePath );
    //        if( !inFile.is_open() )
    //        {
    //            break;
    //        }

    //        inFile.read(aszExtContext, MAX_COMMON_TXT_LEN - 1);
    //        SDFileRemove(szFilePath); //ɾ����ʾ��ֻ��ʾһ��

    //        //ɾ����Ŀ¼
    //        if( SDIsEmptyDirectory( szDir ) )
    //        {
    //            if( !SDDeleteDirectory(szDir) )
    //            {
    //                SYS_CRITICAL(_SDT("[%s: %d]: delete dir failed!path:%s"), MSG_MARK, szDir);
    //            }
    //        }

    //    }
    //    while (0);

    //    poPlayer->GetExtData() = 0;//������ʾ
    //}

    return ERR_OPEN_GODWEAPON::ID_SUCCESS;
}

UINT16 CGodweaponMgr::OpenGodWeaponByPlayerInfo(CPlayer* poPlayer, UINT16& wGodweaponNum, DT_GODWEAPON_DATA_CLI astGodweaponLst[MAX_HERO_NUM], UINT8 abyLockStatus[MAX_HERO_NUM])
{
	if ( NULL == poPlayer)
	{
		return ERR_PLAYER_INFO_GODWEAPON::ID_NOT_PLAYER_INFO;
	}
	set<CHero*> setHero;
	CHero* poHero = poPlayer->GetCoachHero();
	if ( NULL == poHero)
	{
		return ERR_PLAYER_INFO_GODWEAPON::ID_COACH_HERO_LOST;
	}
	
	setHero.insert(poHero);
	CGodWeapon* poGodweapon = poHero->GetGodweapon();
	if ( NULL != poGodweapon )
	{
		poGodweapon->GetDT_GODWEAPON_DATA_CLI(astGodweaponLst[wGodweaponNum]);
		abyLockStatus[wGodweaponNum] = ESM_YES;
	}
	wGodweaponNum++;
	

	CFormationHeroShmemMap& mapFormationHero = poPlayer->GetFormationHeroMap();
	poHero = mapFormationHero.GetFistData();
	while ( poHero)
	{
		if(setHero.find(poHero) != setHero.end())
		{
			poHero = mapFormationHero.GetNextData();
			continue;
		}
		setHero.insert(poHero);
		CGodWeapon* poGodweapon = poHero->GetGodweapon();
		if ( NULL != poGodweapon )
		{
			poGodweapon->GetDT_GODWEAPON_DATA_CLI(astGodweaponLst[wGodweaponNum]);
			abyLockStatus[wGodweaponNum] = ESM_YES;
		}
		wGodweaponNum++;
		poHero = mapFormationHero.GetNextData();
	}
		


	CKindID2HeroShmemMap& mapKind2HeroAllCarry = poPlayer->GetAllCarryHeroMap();
	poHero = mapKind2HeroAllCarry.GetFistData();
	while ( poHero)
	{
		if(setHero.find(poHero) != setHero.end())
		{
			poHero = mapKind2HeroAllCarry.GetNextData();
			continue;
		}
		setHero.insert(poHero);
		CGodWeapon* poGodweapon = poHero->GetGodweapon();
		if ( NULL != poGodweapon )
		{
			poGodweapon->GetDT_GODWEAPON_DATA_CLI(astGodweaponLst[wGodweaponNum]);
			abyLockStatus[wGodweaponNum] = ESM_YES;
		}
		wGodweaponNum++;
		poHero = mapKind2HeroAllCarry.GetNextData();
	}

	return ERR_PLAYER_INFO_GODWEAPON::ID_SUCCESS;
}


UINT16 CGodweaponMgr::UpgradeGodweapon(CPlayer* poPlayer, UINT16 wHeroKindID, UINT16 wQuality, UINT16 wLevel, DT_GODWEAPON_DATA_CLI& stGodweaponInfo, UINT16& wUpgradeQualityItemNum)
{
    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    if(NULL == poPlayer->GetBuild(EBK_GODWEAPON))
    {
        return ERR_UPGRADE_GODWEAPON::ID_GODWEAPON_UNLOCK;
    }

    CHero* poHero = poPlayer->GetHero(wHeroKindID);
    if(NULL == poHero)
    {
        return ERR_UPGRADE_GODWEAPON::ID_HERO_NOT_EXIST;
    }

    UINT16 wErrCode = 0;
    CGodWeapon* poGodweapon = NULL;
    //�¿�������
    if((1 == wQuality) && (0 == wLevel))
    {
        wErrCode = NewGodweapon(poPlayer, poHero, stGodweaponInfo);
        //������Ʒ
        CGoods* poGoods = poPlayer->GetBag().GetGoodsItem(m_wUpgradeQualityItemID);
        if(NULL == poGoods)
        {
            wUpgradeQualityItemNum = 0;
        }
        else
        {
            wUpgradeQualityItemNum = poGoods->GetCurPileNum();
        }
    }
    else
    {
        poGodweapon = poHero->GetGodweapon();
        if(NULL == poGodweapon)
        {
            return ERR_UPGRADE_GODWEAPON::ID_GODWEAPON_UNLOCK;
        }

        wErrCode = poGodweapon->Upgrade(wQuality, wLevel);
        poGodweapon->GetDT_GODWEAPON_DATA_CLI(stGodweaponInfo);
        //������Ʒ
        CGoods* poGoods = poPlayer->GetBag().GetGoodsItem(m_wUpgradeQualityItemID);
        if(NULL == poGoods)
        {
            wUpgradeQualityItemNum = 0;
        }
        else
        {
            wUpgradeQualityItemNum = poGoods->GetCurPileNum();
        }
    }

    if(ERR_UPGRADE_GODWEAPON::ID_SUCCESS == wErrCode)
    {
        //��¼������
        poPlayer->AddGuideRecord( EGF_GODWEAPON);
    }

    return wErrCode;
}

UINT16 CGodweaponMgr::FreeGodweapon(CPlayer* poPlayer, UINT16 wHeroKindID, DT_GODWEAPON_DATA_CLI &stGodweaponInfo, BOOL bUseGold, BOOL bIsFreeUseGold /* = FALSE */)
{
    USR_INFO(_SDT("[%s: %d]: PlayerID:%u Free Godweapon! HeroKindID:%u, UseGold:%u"), MSG_MARK, poPlayer->GetID(), wHeroKindID, bUseGold);

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }
    CHero* poHero = poPlayer->GetHero(wHeroKindID);
    if(NULL == poHero)
    {
        return ERR_FREE_GODWEAPON::ID_HERO_NOT_EXIST;
    }

    //��ȡ������Ϣ, ������Ϣ�����ͷ�
    if(poPlayer->GetCoachHero() == poHero)
    {
        return ERR_FREE_GODWEAPON::ID_COACH_HERO_NOT_FREE;
    }

    CGodWeapon* poGodweapon = poHero->GetGodweapon();
    if(NULL == poGodweapon)
    {
        return ERR_FREE_GODWEAPON::ID_GODWEAPON_UNLOCK;
    }

    if( bUseGold )
    {
        if( !CVipPropMgr::Instance()->CkOpenFunc( EVF_GODWEAPONPERFECTRELEASE, poPlayer->GetDT_PLAYER_BASE_DATA().byVipLevel ) )
        {
            return ERR_FREE_GODWEAPON::ID_VIP_LEVEL_NOT_ENOUGH;
        }
        if( poPlayer->GetDT_PLAYER_BASE_DATA().qwGold < CSinglePramMgr::Instance()->GetPerfectFreeGodweaponGold() )
        {
            return ERR_COMMON::ID_GOLD_NOT_ENOUGH;
        }
    }
    //poGodweapon->Free();
    poGodweapon->Recover(bUseGold);

    if( bUseGold && !bIsFreeUseGold)
    {
        poPlayer->DecGold( CSinglePramMgr::Instance()->GetPerfectFreeGodweaponGold(), CRecordMgr::EDGT_PERFECTFREEGODWEAPON );
    }

    poGodweapon->GetDT_GODWEAPON_DATA_CLI(stGodweaponInfo);
    return ERR_FREE_GODWEAPON::ID_SUCCESS;
}

//������������
UINT16 CGodweaponMgr::NewGodweapon(CPlayer* poPlayer, CHero* poHero, DT_GODWEAPON_DATA_CLI& stGodweaponInfo)
{
    CGodWeapon* poGodweapon = poHero->GetGodweapon();
    if(NULL != poGodweapon)
    {
        return ERR_UPGRADE_GODWEAPON::ID_GODWEAPON_HAVE_EXIST;
    }

    SGodweaponQualityUpgradeProp* pstGodweaponUpgradeProp = CGodweaponPropMgr::Instance()->GetGodweaponQualiryUpgradeProp(poHero->GetDT_HERO_BASE_DATA().wKindID, 1);
    if(NULL == pstGodweaponUpgradeProp)
    {
        RETURN_OTHER_ERR;
    }
    UINT32 dwCostCoin = 0;//��������ͭ��0
    if(!poPlayer->CKGuide( EGF_GODWEAPON))
    {
        dwCostCoin = CGodweaponBasePropMgr::Instance()->GetActiveCoin();
    }

    if(poPlayer->GetDT_PLAYER_BASE_DATA().qwCoin < dwCostCoin)
    {
        return ERR_COMMON::ID_COIN_NOT_ENOUGH;
    }

    //poPlayer->GetDT_PLAYER_BASE_DATA().qwCoin -= dwCostCoin;
    poPlayer->DecCoin(dwCostCoin, CRecordMgr::EDCT_GODWEAPON, poHero->GetDT_HERO_BASE_DATA().wKindID);

    //û�������ģ�������
    if(NULL == poGodweapon)
    {
        DT_GODWEAPON_DATA stDT_GODWEAPON_DATA;
        stDT_GODWEAPON_DATA.byHaveDataFlag = 1;
        stDT_GODWEAPON_DATA.wHeroKindID = poHero->GetDT_HERO_BASE_DATA().wKindID;
        stDT_GODWEAPON_DATA.wQuality = 1;
        stDT_GODWEAPON_DATA.wLevel = 0;//��0��ʼ
        poGodweapon = poHero->NewGodweapon(&stDT_GODWEAPON_DATA);
        if(NULL == poGodweapon)
        {
            RETURN_OTHER_ERR;
        }
        //poGodweapon->SetObjDataSaveType(EODST_INSERT);
        //poGodweapon->SetSaveState(ESS_WANT_SAVE);
    }
    //�ѿ���������ɾ���������
    else
    {
        poGodweapon->Reupdate();
    }

    poGodweapon->GetDT_GODWEAPON_DATA_CLI(stGodweaponInfo);

    CTaskMgr::Instance()->OnActivateGodweapon(poPlayer);

    return ERR_UPGRADE_GODWEAPON::ID_SUCCESS;
}

