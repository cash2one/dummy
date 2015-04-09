#include <sdutil.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <logic/base/logicfunc.h>
#include <logic/other/singleprammgr.h>
#include <framework/gsapi.h>
#include "openlightpropmgr.h"
#include <logic/item/equip/equippropmgr.h>
#include <logic/record/recordmgr.h>
#include <logic/item/equip/strengthenpropmgr.h>
#include <logic/item/equip/equip.h>
#include <logic/bag/bag.h>
#include <logic/hero/heromgr.h>
#include <logic/task/taskmgr.h>
#include <logic/player/player.h>
#include <errdef.h>

#include <db/dbmgr.h>

using namespace SGDP;

//const int MAX_OPENLIGHTPROP_ROW = 28;

IMPLEMENT_SINGLETON_PROPMGR(COpenLightPropMgr);

COpenLightPropMgr::COpenLightPropMgr()
{

}

COpenLightPropMgr::~COpenLightPropMgr()
{
}

BOOL COpenLightPropMgr::Init()
{
    if(!LoadOpenLightPropFromDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: LoadOpenLightPropFromDB failed!"), MSG_MARK);
        return FALSE;
    }

    return TRUE;
}

VOID COpenLightPropMgr::UnInit()
{
    m_mapOpenLightPropMap.clear();
    m_setRealEquipSet.clear();
}


BOOL COpenLightPropMgr::LoadOpenLightPropFromDB()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetCfgDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }
    SGDP::ISDDBRecordSet* pRes = NULL;

    UINT32 dwErrID = 0;
    string strErr;

    INT32 nRet = pDBSession->ExecuteSqlRs(GetPropTableSelectSql("equipopenlightprop", " order by KindID ").c_str(), &pRes, &dwErrID,  &strErr);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    UINT8 byRowNum = 0;

    while(pRes->GetRecord()) // �����н��ʱ
    {
        SOpenLightProp stProp = {0};

        stProp.wKindID          = SGDP::SDAtou(pRes->GetFieldValueByName("KindID"));
        stProp.byIsCanOpenLight = SGDP::SDAtou(pRes->GetFieldValueByName("IsCanOpenLight"));
        stProp.wNeedGoodsKindID = SGDP::SDAtou(pRes->GetFieldValueByName("NeedGoodsKindID"));
        stProp.wNeedGoodsCnt    = SGDP::SDAtou(pRes->GetFieldValueByName("NeedGoodsCnt"));
        stProp.bySuccessRate    = SGDP::SDAtou(pRes->GetFieldValueByName("SuccessRate"));
        stProp.dwFullRateGold   = SGDP::SDAtou(pRes->GetFieldValueByName("FullRateGold"));
        stProp.wNewKindID       = SGDP::SDAtou(pRes->GetFieldValueByName("NewKindID"));

        //stProp.vecSuccessRate.push_back(stProp.bySuccessRate);

        m_mapOpenLightPropMap[stProp.wKindID] = stProp;

        if (0 != stProp.wNewKindID)
        {
            m_setRealEquipSet.insert(stProp.wNewKindID);
        }

        byRowNum++;
    }

    if(NULL != pRes)
    {
        pRes->Release();
        pRes = NULL;
    }
    /*
    if(byRowNum != MAX_OPENLIGHTPROP_ROW)
    {
    	SYS_CRITICAL(_SDT("[%s: %d]: OpenLightprop row[%d] not match[%d] !"), MSG_MARK, byRowNum, MAX_OPENLIGHTPROP_ROW);
    	return FALSE;
    }
    */

    return TRUE;
}


// ��ȡ����װ���Ŀɿ����ʶ��
void COpenLightPropMgr::GetOpenLightFlagInfo(PKT_CLIGS_OPEN_SMITHY_ACK& stAck)
{
    memset(&stAck.abyEquipOpenLightFlagInfo, 0, sizeof(stAck.abyEquipOpenLightFlagInfo));
    for(size_t i = 0; i < stAck.wEquipNum; ++i)
    {
        stAck.abyEquipOpenLightFlagInfo[i] = GetOpenLightFlagOfEquip(stAck.stEquipList.astEquipInfo[i]); // �ѿ������װ��
    }
}

void COpenLightPropMgr::GetOpenLightFlagInfo_v410(PKT_CLIGS_OPEN_SMITHY_ACK_v410& stAck)
{
    memset(stAck.stEquipList.abyEquipOpenLightFlagInfo, 0, sizeof(stAck.stEquipList.abyEquipOpenLightFlagInfo));
    for(size_t i = 0; i < stAck.stEquipList.wEquipNum && i < MAX_BAG_OPEN_NUM; ++i)
    {
        stAck.stEquipList.abyEquipOpenLightFlagInfo[i] = GetOpenLightFlagOfEquip(stAck.stEquipList.astEquipInfo[i].stEquipData); 
    }
}

UINT8 COpenLightPropMgr::GetOpenLightFlagOfEquip(DT_EQUIP_DATA_CLI &stEquip)
{
    CRealEquipSetItr equipItr = m_setRealEquipSet.find(stEquip.wKindID);

    if (equipItr != m_setRealEquipSet.end())
    {
        return 2; // �ѿ������װ��
    }

    COpenLightPropMapItr propItr = m_mapOpenLightPropMap.find(stEquip.wKindID);
    if(propItr == m_mapOpenLightPropMap.end())
    {
        return 0;
    }

    SOpenLightProp& stProp = propItr->second;
    return stProp.byIsCanOpenLight;
}

// ��ȡĳ��װ���Ŀ���������Ϣ
UINT16 COpenLightPropMgr::GetOpenLightPropInfo(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx,
        DT_EQUIP_DATA_CLI& stAfterOpenLightInfo, UINT16& wOpenLightGoodsID,
        UINT16& wNeedOpenLightGoodsNum, UINT16& wOpenLightGoodsNum,
        UINT8& byOpenLightRate, UINT32& dwOpenLightGold,
        DT_BATTLE_ATTRIBUTE& stOldEquipInitBatlAttr, DT_BATTLE_ATTRIBUTE& stNewEquipInitBatlAttr,
        DT_BATTLE_ATTRIBUTE& stOldEquipCurrAttr)

{
    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    CEquip* poEquip = poPlayer->GetEquip(wEquipKindID, wIdx);
    if(NULL == poEquip)
    {
        return ERR_GET_OPENLIGHT_INFO::ID_EQUIP_NOT_EXIST; // װ��������
    }

    SEquipProp* pstOldEquipProp = CEquipPropMgr::Instance()->GetProp(wEquipKindID);
    if(NULL == pstOldEquipProp)
    {
        RETURN_OTHER_ERR;
    }

    // ��װ��0��ս������(to cli)
    stOldEquipInitBatlAttr.dwHP     = pstOldEquipProp->dwHP;
    stOldEquipInitBatlAttr.dwAttack = pstOldEquipProp->dwAttack;
    // ��װ����ǰս������(to cli)
    stOldEquipCurrAttr = CEquip::BattleAttCountByLevel(poEquip->GetDT_EQUIP_DATA().wLevel, poEquip->GetEnchantLevel(), pstOldEquipProp);

    // ���װ���Ƿ��ѿ���
    CRealEquipSetItr iter = m_setRealEquipSet.find(wEquipKindID);
    if (iter != m_setRealEquipSet.end())
    {
        return ERR_GET_OPENLIGHT_INFO::ID_EQUIP_HAS_OPENLIGHT; // װ���ѿ���
    }

    COpenLightPropMapItr itr = m_mapOpenLightPropMap.find(wEquipKindID);
    if(itr == m_mapOpenLightPropMap.end())
    {
        // �������ô���
        return ERR_GET_OPENLIGHT_INFO::ID_EQUIP_CAN_NOT_OPENLIGHT; // װ�����ɿ���
    }

    SOpenLightProp& stProp = itr->second;

    if (0 == stProp.byIsCanOpenLight)
    {
        return ERR_GET_OPENLIGHT_INFO::ID_EQUIP_CAN_NOT_OPENLIGHT; // װ�����ɿ���
    }

    if (pstOldEquipProp->bIsLegendEquip){
        return ERR_GET_OPENLIGHT_INFO::ID_EQUIP_CAN_NOT_OPENLIGHT; // �⴫װ�����ɽ���
    }

    SEquipProp* pstNewEquipProp = CEquipPropMgr::Instance()->GetProp(stProp.wNewKindID);
    if(NULL == pstNewEquipProp){
        return ERR_GET_OPENLIGHT_INFO::ID_EQUIP_CAN_NOT_OPENLIGHT; // װ�����ɿ���
    }


    stAfterOpenLightInfo.wKindID					= pstNewEquipProp->wKindID;
    stAfterOpenLightInfo.wIdx						= poPlayer->CkNextEquipIdx(stProp.wNewKindID);
    stAfterOpenLightInfo.byDressPos					= pstNewEquipProp->byPosKindID;
    stAfterOpenLightInfo.wLevel                     = poEquip->GetDT_EQUIP_DATA().wLevel;
    stAfterOpenLightInfo.wDressLevel                = pstNewEquipProp->wDressLevel;

    // ��ȡ�ȼ�ս������
    stAfterOpenLightInfo.stBattleAttribute = CEquip::BattleAttCountByLevel(stAfterOpenLightInfo.wLevel, 0, pstNewEquipProp);

    // ��ȡ������Ϣ
    CEquip::GetRecoverScience(stAfterOpenLightInfo.wKindID, stAfterOpenLightInfo.dwMinScience, stAfterOpenLightInfo.dwMaxScience);

    // ��ȡԭװ������Ƕ��Ϣ
    DT_EQUIP_DATA_CLI stDT_EQUIP_DATA_CLI = {0};
    poEquip->GetDT_EQUIP_DATA_CLI(stDT_EQUIP_DATA_CLI);

    //
    stAfterOpenLightInfo.byXiangqianNum = stDT_EQUIP_DATA_CLI.byXiangqianNum;
    memcpy( stAfterOpenLightInfo.astXiangqianList, stDT_EQUIP_DATA_CLI.astXiangqianList, sizeof(stDT_EQUIP_DATA_CLI.astXiangqianList));

    // ���ؿͻ��˵���Ϣ
    wOpenLightGoodsID      = stProp.wNeedGoodsKindID;
    wNeedOpenLightGoodsNum = stProp.wNeedGoodsCnt;
    byOpenLightRate        = stProp.bySuccessRate;
    dwOpenLightGold        = stProp.dwFullRateGold;

    // ��ҵ�ǰ������Ϳ���ʯ������
    CGoods* poOpenLightGoods = poPlayer->GetBag().GetGoodsItem(stProp.wNeedGoodsKindID);
    if (NULL == poOpenLightGoods)
    {
        wOpenLightGoodsNum = 0;
    }
    else
    {
        wOpenLightGoodsNum = poOpenLightGoods->GetCurPileNum();
    }

    // �±�0��ս������
    stNewEquipInitBatlAttr.dwHP     = pstNewEquipProp->dwHP;
    stNewEquipInitBatlAttr.dwAttack = pstNewEquipProp->dwAttack;
    poPlayer->AddGuideRecord(EGF_OPENLIGHT);
    return ERR_GET_OPENLIGHT_INFO::ID_SUCCESS;
}

//װ������
UINT16 COpenLightPropMgr::OpenLight(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT8 byGoldFlag,
                                    UINT16& wNewEquipKindID, UINT16& wNewIdx, UINT8& byNewOpenLightFlag,
                                    UINT16& wOpenLightGoodsID, UINT16& wOpenLightGoodsNum)
{

    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    CEquip* poEquip = poPlayer->GetEquip(wEquipKindID, wIdx);
    if(NULL == poEquip)
    {
        return ERR_OPENLIGHT_INFO::ID_EQUIP_NOT_EXIST;//return //װ��������
    }

    CRealEquipSetItr iter = m_setRealEquipSet.find(wEquipKindID);

    if (iter != m_setRealEquipSet.end())
    {
        return ERR_OPENLIGHT_INFO::ID_EQUIP_HAS_OPENLIGHT; // װ���ѿ���
    }

    COpenLightPropMapItr itr = m_mapOpenLightPropMap.find(wEquipKindID);
    if(itr == m_mapOpenLightPropMap.end())
    {
        RETURN_OTHER_ERR;
    }

    SOpenLightProp& stProp = itr->second;

    if (0 == stProp.byIsCanOpenLight)
    {
        return ERR_OPENLIGHT_INFO::ID_EQUIP_CAN_NOT_OPENLIGHT; // װ�����ɿ���
    }


    UINT16 wNeedGoodsKindID = stProp.wNeedGoodsKindID;  // ������Ҫ�Ŀ���ʯ����
    UINT16 wNeedGoodsCnt    = stProp.wNeedGoodsCnt;     // ������Ҫ�Ŀ���ʯ����
    UINT32 dwFullRateGold   = stProp.dwFullRateGold;

    //�жϿ���ʯ�Ƿ��㹻
    CGoods* poOpenLightGoods = poPlayer->GetBag().GetGoodsItem(stProp.wNeedGoodsKindID);

    if((NULL == poOpenLightGoods) || (poOpenLightGoods->GetCurPileNum() < stProp.wNeedGoodsCnt))
    {
        return ERR_OPENLIGHT_INFO::ID_OPENLIGHT_STONE_NOT_ENOUGH; // ����ʯ����
    }

    // û����Ԫ������û������
    if((0 == byGoldFlag) && (RandomReseed(100) > stProp.bySuccessRate))
    {
        // �۳�����ʯ
        //UINT16 wPileCount = poOpenLightGoods->GetDT_GOODS_DATA().wPileCount;
        //poOpenLightGoods->GetDT_GOODS_DATA().wPileCount = (wPileCount >= wNeedGoodsCnt) ? wPileCount - wNeedGoodsCnt : 0;

		//�۳�����
		poOpenLightGoods->DecPileNum(wNeedGoodsCnt, CRecordMgr::EDIT_OPENLIGHT);

        // ��ǰ�Ŀ���ʯ(to cli)
        wOpenLightGoodsID  = wNeedGoodsKindID;
        // ��ǰ�Ŀ���ʯ����(to cli)
        wOpenLightGoodsNum = poOpenLightGoods->GetCurPileNum();

        if(0 == poOpenLightGoods->GetCurPileNum())
        {
            poPlayer->OnDeleteItem(poOpenLightGoods);
        }

        return ERR_OPENLIGHT_INFO::ID_OPENLIGHT_RATE_NOT_HIT; // �������û������
    }

    // ʹ��Ԫ��,���Ԫ���Ƿ���
    if (byGoldFlag)
    {
        if (poPlayer->GetDT_PLAYER_BASE_DATA().qwGold < stProp.dwFullRateGold)
        {
            return ERR_OPENLIGHT_INFO::ID_GOLD_NOT_ENOUGH; // Ԫ������
        }
    }


    SEquipProp* pstNewEquipProp = CEquipPropMgr::Instance()->GetProp(stProp.wNewKindID);
    if(NULL == pstNewEquipProp)
    {
        RETURN_OTHER_ERR;
    }

	SEquipProp* poEquipProp =poEquip->GetEquipProp();
	if (NULL == poEquipProp)
	{
		RETURN_OTHER_ERR;
	}
    //
    if(poEquipProp->byPosKindID != pstNewEquipProp->byPosKindID)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: new byPosKindID != old byPosKindID!"), MSG_MARK);
        //SDStrncpy(aszErrInfo, SDGBK2UTF8(ERR_MAKE_ITEM::STR_MAKER_CONFIG_ERR).c_str(), MAX_COMMON_TXT_NUM-1);
        RETURN_OTHER_ERR;
    }

    //�жϾ�װ���Ƿ񴩴�
    UINT16 wHeroKindID = poEquip->GetDT_EQUIP_DATA().wHeroKindID;
    BOOL   bDress      = FALSE;  // �贩���ҿɴ�����־
    CHero* poHero      = NULL;

    if(0 != wHeroKindID)
    {
        poHero = poPlayer->GetHero(wHeroKindID);
        if(NULL == poHero)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: poHero is NULL!, poHero = %u"), MSG_MARK, wHeroKindID);
            RETURN_OTHER_ERR;
        }

        //�жϾ�װ���������佫�Ƿ��ܴ�����װ��
        if(poHero->GetDT_HERO_BASE_DATA().wLevel >= pstNewEquipProp->wDressLevel)
        {
            //�贩���ҿɴ���
            bDress = TRUE;
        }
    }


    //������װ��
    ECreateItemRet eRet;
    CEquip* poNewEquip = CItemMgr::Instance()->CreateEquip(poPlayer, pstNewEquipProp->wKindID, 1, eRet, poEquip->GetDT_EQUIP_DATA().wLevel);
    if(NULL == poNewEquip)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CreateEquip failed! KindID[%d],eRet[%d]"), MSG_MARK, pstNewEquipProp->wKindID, eRet);
        RETURN_OTHER_ERR;
    }

    // ��ȡ��Ƕ�б�
    DT_EQUIP_DATA_CLI stDT_EQUIP_DATA_CLI = {0};
    poEquip->GetDT_EQUIP_DATA_CLI(stDT_EQUIP_DATA_CLI);


    //�������װ�������ܷ��뱳������ֹԭ�ȱ������޷���������
    poPlayer->OnDeleteEquip(poEquip);

    //��Ҫ���������佫����װ��,����Ҫ���������ñ�����Ϣ���ű���
    if(bDress)
    {
        //������װ��
        poHero->DressMakeEquip(poNewEquip);
    }
    poPlayer->OnAddEquip(poNewEquip, bDress);


    // ת����Ƕ�б�
    for(size_t i = 0; i < MAX_XIANGQIAN_NUM; ++i)
    {
        poNewEquip->GetDT_EQUIP_DATA().astXiangqianList[i].wItemID = stDT_EQUIP_DATA_CLI.astXiangqianList[i].wKindID;
    }

    if(bDress)
    {
        // ���¼���ս��
        poPlayer->ResetBattleAttr(TRUE);
    }

    // ��Ԫ��
    if (byGoldFlag)
    {
        poPlayer->DecGold(stProp.dwFullRateGold, CRecordMgr::EDGT_EQUIP_OPENLIGHT, stProp.wNewKindID, stProp.wNeedGoodsKindID, stProp.wNeedGoodsCnt);
    }

    // �ۿ���ʯ
    UINT16 wPileCount = poOpenLightGoods->GetDT_GOODS_DATA().wPileCount;

	//�۳�����
	poOpenLightGoods->DecPileNum(wNeedGoodsCnt, CRecordMgr::EDIT_OPENLIGHT);


    // ��ǰ�����õĿ���ʯ������(to cli)
    wOpenLightGoodsID  = wNeedGoodsKindID;
    // ��ǰ�Ŀ���ʯ����(to cli)
    wOpenLightGoodsNum = poOpenLightGoods->GetCurPileNum();

    //��־
    //CRecordMgr::Instance()->RecordInfo( poPlayer->GetID(), ERM_DECITEM, CRecordMgr::EDIT_OPENLIGHT, poOpenLightGoods->GetItemKindID(), SDTimeToString(SDNow()), poOpenLightGoods->GetDT_GOODS_DATA().wPileCount,
    //                                    poPlayer->GetLevel(), poPlayer->GetDT_PLAYER_BASE_DATA().byVipLevel, wNeedGoodsKindID);

    if(0 == poOpenLightGoods->GetCurPileNum())
    {
        poPlayer->OnDeleteItem(poOpenLightGoods);
    }



    // ���׺��װ����Ϣ(to cli)
    wNewEquipKindID = poNewEquip->GetDT_EQUIP_DATA().wKindID;
    wNewIdx = poNewEquip->GetDT_EQUIP_DATA().wIdx;
    byNewOpenLightFlag = 2;
    CTaskMgr::Instance()->OnOpenLight(poPlayer);
    return ERR_OPENLIGHT_INFO::ID_SUCCESS;
}




