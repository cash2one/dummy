#include "equipmaster.h"

#include "logic/player/player.h"
#include "logic/lua/luamgr.h"
#include "logic/item/equip/equip.h"
#include "logic/other/singleprammgr.h"
#include <dll/sdframework/sdloggerimpl.h>
#include <logic/build/build.h>
#include <common/server/utility.h>

#include "equipmasterpropmgr.h"


IMPLEMENT_CLASS_POOL_MGR(CEquipMaster)

CEquipMaster::CEquipMaster()
{
    memset(&m_stData, 0 , sizeof(m_stData));
}

BOOL CEquipMaster::Init(DT_EQUIP_MASTER &stData, CPlayer* poOwner)
{
    memcpy(&m_stData, &stData, sizeof(stData));
    FixMaster();

    m_poOwner = poOwner;
    return TRUE;
}

// ����װ����ͨ���ݣ��������쳣
void CEquipMaster::FixMaster()
{
    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_EQUIP_MASTER_DETAIL &stInfo = m_stData.astMasterInfo[i];
        stInfo.byMasterKind = i + 1;
        stInfo.byMasterRank = MIN(stInfo.byMasterRank, EMG_GRADE_4);

        // �Ѽ���ȼ�ȴΪ0����������Ϊ1��
        if(stInfo.wMasterLevel == 0 && stInfo.byMasterRank != 0)
        {
            stInfo.wMasterLevel = 1;
        }
    }
}

// װ����ͨ�ȼ����������ã�������gmָ��
void CEquipMaster::Reset()
{
    memset(&m_stData, 0, sizeof(m_stData));

    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        m_stData.astMasterInfo[i].byMasterKind = i + 1;
    }

    m_stData.byHaveDataFlag = TRUE;

    FixMaster();
}

// ��װ����ͨ���
UINT16 CEquipMaster::OnOpenEquipMaster(PKT_CLIGS_OPEN_EQUIP_MASTER_ACK &ack)
{
    CBuild *poBuild = m_poOwner->GetBuild(EBK_EQUIP_MASTER);
    if(NULL == poBuild)
    {
        return ERR_OPEN_EQUIP_MASTER::ID_UNOPEN;
    }

    poBuild->OnOpen();

    StoreOpenMasterAck(ack);
    return ERR_OPEN_EQUIP_MASTER::ID_SUCCESS;
}

// ����װ����ͨ
UINT16 CEquipMaster::OnActivateEquipMaster(PKT_CLIGS_ACTIVATE_MASTER_ACK &ack, EEquipPosType eEquipKind)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return ERR_ACTIVATE_MASTER::ID_UNOPEN;
    }

    DT_EQUIP_MASTER_DETAIL *pstData = GetMasterInfoByKind(eEquipKind);
    if(NULL == pstData)
    {
        return ERR_COMMON::ID_OTHER_ERR;
    }

    // ���ѫ����
    UINT32 dwMedalCost = CEquipMasterPropMgr::Instance()->GetBreakMedal(eEquipKind, EMG_GRADE_0); // ��������ѫ���൱��0��ͻ��
    if(m_poOwner->GetMedal() < dwMedalCost)
    {
        return ERR_ACTIVATE_MASTER::ID_MEDAL_NOT_ENOUGH;
    }

    // ��������Ƿ��Ѽ���
    if(IsActivated(*pstData))
    {
        StoreActivateAck(ack, *pstData);
        return ERR_ACTIVATE_MASTER::ID_SUCCESS;
    }

    // �۳�ѫ��
    m_poOwner->DecMedal(dwMedalCost, CRecordMgr::EDMT_BREAK_THROUGH_MASTER, pstData->byMasterKind, pstData->byMasterRank, pstData->wMasterLevel);

    // �ɹ�������������Լӳ�
    ack.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
    Activate(*pstData);
    m_poOwner->ResetBattleAttr(TRUE);
    ack.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;

    StoreActivateAck(ack, *pstData);
    return ERR_ACTIVATE_MASTER::ID_SUCCESS;
}

// ͻ��
UINT16 CEquipMaster::OnBreakMaster(PKT_CLIGS_BREAK_MASTER_ACK &ack, EEquipPosType eEquipKind)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return ERR_BREAK_MASTER::ID_UNOPEN;
    }

    DT_EQUIP_MASTER_DETAIL *pstData = GetMasterInfoByKind(eEquipKind);
    if(NULL == pstData)
    {
        return ERR_COMMON::ID_OTHER_ERR;
    }

    // ���ѫ����
    UINT32 dwMedalCost = CEquipMasterPropMgr::Instance()->GetBreakMedal(eEquipKind, (EEquipMasterRank)pstData->byMasterRank);
    if(m_poOwner->GetMedal() < dwMedalCost)
    {
        return ERR_BREAK_MASTER::ID_MEDAL_NOT_ENOUGH;
    }

    // �����ҵȼ�
    UINT16 wRequiredPlayerLevel = CEquipMasterPropMgr::Instance()->GetBreakPlayerLevel(eEquipKind, (EEquipMasterRank)pstData->byMasterRank); // ͻ���������ҵȼ�
    if(m_poOwner->GetLevel() < wRequiredPlayerLevel)
    {
        return ERR_BREAK_MASTER::ID_PLAYER_LEVEL_NOT_ENOUGH;
    }

    // ����Ƿ��ͻ��
    if(FALSE == IsBreakable(*pstData))
    {
        StoreBreakAck(ack, *pstData);
        return ERR_BREAK_MASTER::ID_SUCCESS;
    }

    // �۳�ѫ��
    m_poOwner->DecMedal(dwMedalCost, CRecordMgr::EDMT_BREAK_THROUGH_MASTER, pstData->byMasterKind, pstData->byMasterRank, pstData->wMasterLevel);

    // �ɹ�ͻ�ƣ�����������ֵ����
    ack.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
    BreakThrough(*pstData);
    m_poOwner->ResetBattleAttr(TRUE);
    ack.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;

    StoreBreakAck(ack, *pstData);
    return ERR_BREAK_MASTER::ID_SUCCESS;
}

// ������֮ͨ��
UINT16 CEquipMaster::OnCultivateMasterBook(PKT_CLIGS_GET_MASTER_BOOK_ACK &ack)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return ERR_GET_MASTER_BOOK::ID_UNOPEN;
    }

    // �����������ѫ��
    UINT32 dwMedalCost = CEquipMasterPropMgr::Instance()->GetMasterCultivateMedalCost();
    if(m_poOwner->GetMedal() < dwMedalCost)
    {
        return ERR_GET_MASTER_BOOK::ID_MEDAL_NOT_ENOUGH;
    }

    // ����Ƿ���ȫ������
    if(FALSE == IsAllActivated())
    {
        return ERR_GET_MASTER_BOOK::ID_NOT_ACTIVATE_ALL;
    }

    // �Ƿ���ĳ����ͨ����ͻ�ƣ��ǵĻ�����ʾ�����ͻ��
    if(IsAnyBreakable())
    {
        return ERR_GET_MASTER_BOOK::ID_UPGRADE_MASTER_PLEASE;
    }

    // �Ƿ��Ѿ����о�ͨȫ����ȫ����û��Ҫ������
    if(IsAllLevelMax())
    {
        return ERR_GET_MASTER_BOOK::ID_MASTER_MAX;
    }

    // ������״̬��������֮ͨ�����Ӧ����δ��״̬
    if(GetMasterBookState() != MASTER_BOOK_PANEL_UN_OPEN)
    {
        StoreCultivateAck(ack);
        return ERR_GET_MASTER_BOOK::ID_SUCCESS;
    }    

    // �۳�ѫ��
    m_poOwner->DecMedal(dwMedalCost, CRecordMgr::EDMT_BREAK_THROUGH_MASTER);

    // ���ɾ�����ι���
    GenerateMasterExpBook();
    StoreCultivateAck(ack);

    return ERR_GET_MASTER_BOOK::ID_SUCCESS;
}

// �ο���ͨ���������
UINT16 CEquipMaster::OnWipeMasterBook(PKT_CLIGS_WIPE_MASTER_BOOK_ACK &ack)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return ERR_WIPE_MASTER_BOOK::ID_UNOPEN;
    }

    // �Ƿ�ɹΣ�Ӧ���ڴ򿪵�δ�ο�״̬
    if(GetMasterBookState() != MASTER_BOOK_PANEL_GET_BUT_NOT_WIPED)
    {
        return ERR_WIPE_MASTER_BOOK::ID_SUCCESS;
    }

    SetExpBookPanelState(MASTER_BOOK_PANEL_WIPED_BUT_NOT_CONFIRMED);
    return ERR_WIPE_MASTER_BOOK::ID_SUCCESS;
}

// ��ͨ�������ǧ
UINT16 CEquipMaster::OnCheatMasterBook(PKT_CLIGS_MASTER_CHEAT_ACK &ack)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return ERR_MASTER_CHEAT::ID_UNOPEN;
    }

    // ״̬��⣺Ӧ�����о�������ܳ�ǧ
    if(FALSE == IsMasterBookGotten())
    {
        StoreCheatAck(ack);
        return ERR_MASTER_CHEAT::ID_SUCCESS;
    }

    SetExpBookPanelState(MASTER_BOOK_PANEL_WIPED_BUT_NOT_CONFIRMED);

    // Ԫ���Ƿ��㹻
    if(m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold < GetCheatGold())
    {
        return ERR_MASTER_CHEAT::ID_GOLD_NOT_ENOUGH;
    }

    // �Ƿ���Ҫ��ǧ��û��С����������Ҫ��ǧ
    if(CountSmallExpBook() == 0 || GetCheatTimes() >= MASTER_EXP_BOOK_COUNT)
    {
        return ERR_MASTER_CHEAT::ID_NOT_NEED_TO_CHEAT;
    }

    // ��ǧ����ȼ����
    if(m_poOwner->GetLevel() < CEquipMasterPropMgr::Instance()->GetMasterCheatPlayerLevel())
    {
        return ERR_MASTER_CHEAT::ID_CHEAT_UNOPEN;
    }

    // ��ʼ��ǧ
    EEquipPosType byCheatKind = Cheat();
    if (0 == byCheatKind)
    {
        return ERR_MASTER_CHEAT::ID_NOT_NEED_TO_CHEAT;
    }

    // �۳�Ԫ��
    UINT32 dwCheatGold = GetCheatGold();
    m_poOwner->DecGold(dwCheatGold, CRecordMgr::EDGT_EQUIP_MASTER_CHEAT, GetCheatTimes() - 1);

    StoreCheatAck(ack);
    return ERR_MASTER_CHEAT::ID_SUCCESS;
}

// ȷ��ʹ�þ�ͨ������
UINT16 CEquipMaster::OnConfirmMasterBook(PKT_CLIGS_CONFIRM_MASTER_BOOK_ACK &ack)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return ERR_CONFIRM_MASTER_BOOK::ID_UNOPEN;
    }

    UINT16 awCurLevel[EQUIP_KIND_COUNT];
    GetCurEquipLevels(awCurLevel);

    UINT16 awUpExps[EQUIP_KIND_COUNT] = {0}; // �ĸ������õ��˶��پ���

    // �Ƿ��ȷ�ϣ�Ӧ�����Ѵ򿪾��������״̬
    if(FALSE == IsMasterBookGotten())
    {
        StoreConfirmWipeAck(ack, awCurLevel, awUpExps);
        return ERR_CONFIRM_MASTER_BOOK::ID_SUCCESS;
    }

    GetExpSum(awUpExps);

    // ʹ�þ����飬�����¼������Լӳ�
    ack.dwOldPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;
    LevelUpByExpBooks();
    m_poOwner->ResetBattleAttr(TRUE);
    ack.dwCurPower = m_poOwner->GetDT_PLAYER_BASE_DATA().dwPower;

    SetExpBookPanelState(MASTER_BOOK_PANEL_UN_OPEN);
    m_stData.byCheatTimes = 0;

    StoreConfirmWipeAck(ack, awCurLevel, awUpExps);
    return ERR_CONFIRM_MASTER_BOOK::ID_SUCCESS;
}


// �Ƿ��Ѽ���
BOOL CEquipMaster::IsActivated(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    return stDetail.byMasterRank;
}

// ��������װ����ͨ�Ƿ���ȫ��������
BOOL CEquipMaster::IsAllActivated()
{
    for(BYTE i = 1; i <= EQUIP_KIND_COUNT; i++)
    {
        DT_EQUIP_MASTER_DETAIL &stData = m_stData.astMasterInfo[i - 1];
        if(FALSE == IsActivated(stData))
        {
            return FALSE;
        }
    }

    return TRUE;
}

// ����
void CEquipMaster::Activate(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    if(IsActivated(stDetail))
    {
        return;
    }

    stDetail.byMasterRank = EMG_GRADE_1;
    stDetail.wMasterLevel = 1;
    stDetail.dwExp       = 0;
}

// ��������ȡ��Ӧװ����ͨ����ϸ��Ϣ
DT_EQUIP_MASTER_DETAIL* CEquipMaster::GetMasterInfoByKind(UINT16 wEquipKind)
{
    if(wEquipKind == 0 || wEquipKind > EQUIP_KIND_COUNT)
    {
        return NULL;
    }

    return &m_stData.astMasterInfo[wEquipKind - 1];
}

// �Ƿ�ﵽͻ������
BOOL CEquipMaster::IsBreakable(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    // ��⵱ǰ����ֵ�Ƿ���������ǰ�ȼ��Ƿ��������׼��Ƿ��ѵ�����
    if(FALSE == IsExpBarFull(stDetail))
    {
        return FALSE;
    }

    if(FALSE == IsLevelFull(stDetail))
    {
        return FALSE;
    }

    if(IsRankTop(stDetail))
    {
        return FALSE;
    }

    return TRUE;
}

// ͻ��
void CEquipMaster::BreakThrough(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    if(FALSE == IsBreakable(stDetail))
    {
        return;
    }

    stDetail.byMasterRank++;
    stDetail.wMasterLevel = 1;
    stDetail.dwExp       = 0;
}

// ���о�ͨ���Ľ׼��Ƿ��Ѿ������
BOOL CEquipMaster::IsAllRankTop()
{
    for(BYTE i = 1; i <= EQUIP_KIND_COUNT; i++)
    {
        DT_EQUIP_MASTER_DETAIL &stData = m_stData.astMasterInfo[i - 1];
        if(stData.byMasterRank < MASTER_RANK_COUNT)
        {
            return FALSE;
        }
    }

    return TRUE;
}

// ��ȡ��ǧ���ĵ�Ԫ��
UINT32 CEquipMaster::GetCheatGold()
{
    return CEquipMasterPropMgr::Instance()->GetCheatGoldCost(m_stData.byCheatTimes + 1);
}

// ��ȡָ��װ�������������ٷֱ�
UINT16 CEquipMaster::GetCurPromote(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    UINT16 wPromote = CEquipMasterPropMgr::Instance()->GetAttrPromotion((EEquipPosType)stDetail.byMasterKind, (EEquipMasterRank)stDetail.byMasterRank, stDetail.wMasterLevel);
    return wPromote;
}

// �Ƿ���ĳ����ͨ����ڿ�ͻ��״̬
BOOL CEquipMaster::IsAnyBreakable()
{
    for(BYTE i = 1; i <= EQUIP_KIND_COUNT; i++)
    {
        DT_EQUIP_MASTER_DETAIL &stData = m_stData.astMasterInfo[i - 1];
        if(IsBreakable(stData))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// �ǲ����Ѿ��Ƿ��켫�ˣ����о�ͨȫ����
BOOL CEquipMaster::IsAllLevelMax()
{
    for(BYTE i = 1; i <= EQUIP_KIND_COUNT; i++)
    {
        DT_EQUIP_MASTER_DETAIL &stData = m_stData.astMasterInfo[i - 1];
        if(FALSE == IsLevelMax(stData))
        {
            return FALSE;
        }
    }

    return TRUE;
}

// ָ����ͨ����ǲ����Ѿ��Ƿ��켫��
BOOL CEquipMaster::IsLevelMax(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    return IsLevelFull(stDetail) && IsRankTop(stDetail);
}

// ָ�����ľ�ͨ�׼��Ƿ��Ѿ��Ƕ���
BOOL CEquipMaster::IsRankTop(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    return stDetail.byMasterRank >= EMG_GRADE_4;
}

// ָ�����ľ�ͨ����Ƿ�ȼ�����
BOOL CEquipMaster::IsLevelFull(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    UINT16 wBreakLevel = CEquipMasterPropMgr::Instance()->GetBreakLevel((EEquipPosType)stDetail.byMasterKind, (EEquipMasterRank)stDetail.byMasterRank);
    if(0 == wBreakLevel)
    {
        return FALSE;
    }

    return stDetail.wMasterLevel >= wBreakLevel;
}

// ���ɾ�ͨ������
void CEquipMaster::GenerateMasterExpBook()
{
    // ÿ�����������ɼ��������飬ʣ�µľ���С������
    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_MASTER_EXP_BOOK_DETAIL &stExpBook = m_stData.astExpBookPanel[i];
        stExpBook.byBigExpBookCnt = CEquipMasterPropMgr::Instance()->RollBigExpBookCnt((EEquipPosType)(i + 1));
    }

    // ���õ�ǰ���������״̬Ϊ��δ�ο�������
    m_stData.byCultivatePanelState = MASTER_BOOK_PANEL_GET_BUT_NOT_WIPED;
}

// �����װ����ͨ����Ӧ����Ϣ�ṹ����
void CEquipMaster::StoreOpenMasterAck(PKT_CLIGS_OPEN_EQUIP_MASTER_ACK &ack)
{
    StoreIntoMasterDetail(ack.astEquipMasterDetail);
    if(GetMasterBookState() != MASTER_BOOK_PANEL_UN_OPEN)
    {
        StoreIntoBookPanel(ack.stExpBookPanelData);
    }

    ack.byExpBookPanelState = GetMasterBookState();
    ack.dwGetBookMedalCost  = CEquipMasterPropMgr::Instance()->GetMasterCultivateMedalCost();
    ack.qwCoin              = m_poOwner->GetDT_PLAYER_BASE_DATA().qwCoin;
    ack.dwGold              = (UINT32)m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;
    ack.dwMedal             = (UINT32)m_poOwner->GetDT_PLAYER_BASE_DATA().qwMedal;
}

// ���뼤��װ����ͨ��Ӧ��Ϣ��
void CEquipMaster::StoreActivateAck(PKT_CLIGS_ACTIVATE_MASTER_ACK &ack, DT_EQUIP_MASTER_DETAIL &stDetail)
{
    StoreIntoMasterDetailByKind(ack.stEquipMasterInfo, stDetail);
    ack.dwMedal             = (UINT32)m_poOwner->GetMedal();
    ack.byCanGetMasterBook  = IsAllActivated();
}

// ����ͻ�ƻ�Ӧ��Ϣ��
void CEquipMaster::StoreBreakAck(PKT_CLIGS_BREAK_MASTER_ACK &ack, DT_EQUIP_MASTER_DETAIL &stDetail)
{
    StoreIntoMasterDetailByKind(ack.stEquipMasterInfo, stDetail);
    ack.dwMedal = (UINT32)m_poOwner->GetMedal();
}

// ����������֮ͨ���Ӧ��Ϣ��
void CEquipMaster::StoreCultivateAck(PKT_CLIGS_GET_MASTER_BOOK_ACK &ack)
{
    StoreIntoBookPanel(ack.stExpBookPanelData);

    ack.dwNextMedalCost = CEquipMasterPropMgr::Instance()->GetMasterCultivateMedalCost();
    ack.dwMedal         = (UINT32)m_poOwner->GetMedal();
}

// ����ȷ�Ϲο������Ӧ
void CEquipMaster::StoreConfirmWipeAck(PKT_CLIGS_CONFIRM_MASTER_BOOK_ACK &ack, UINT16 awPreEquipLevel[EQUIP_KIND_COUNT], UINT16 awUpExps[EQUIP_KIND_COUNT])
{
    ack.wCurPlayerLevel = m_poOwner->GetLevel();

    StoreIntoLevelUpInfo(ack.astLevelUpInfo, awPreEquipLevel, awUpExps);
    StoreIntoMasterDetail(ack.astEquipMasterDetail);
}

// �����ǧ��Ӧ
void CEquipMaster::StoreCheatAck(PKT_CLIGS_MASTER_CHEAT_ACK &ack)
{
    ack.dwGold = (UINT32)m_poOwner->GetDT_PLAYER_BASE_DATA().qwGold;

    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        ack.astExpBooks[i].byBigExpBookCnt = m_stData.astExpBookPanel[i].byBigExpBookCnt;
    }

    StoreIntoCheatInfo(ack.stCheatInfo);
}

// ����ĳ������װ����ͨ��ϸ��Ϣ
void CEquipMaster::StoreIntoMasterDetailByKind(DT_EQUIP_MASTER_DETAIL_CLI &stCliData, DT_EQUIP_MASTER_DETAIL &stInfo)
{
    CEquipMasterPropMgr &oPropMgr  = *CEquipMasterPropMgr::Instance();
    EEquipPosType eEquipKind       = (EEquipPosType)stInfo.byMasterKind;
    EEquipMasterRank eEquipRank    = (EEquipMasterRank)stInfo.byMasterRank;

    stCliData.byEquipKind          = eEquipKind;
    stCliData.byMasterRank         = eEquipRank;
    stCliData.wMasterLevel         = stInfo.wMasterLevel;
    stCliData.dwCurMasterExp       = stInfo.dwExp;
    stCliData.dwMaxMasterExp       = oPropMgr.GetMaxExp(eEquipKind, eEquipRank, stInfo.wMasterLevel);
    stCliData.wCurPromote          = oPropMgr.GetAttrPromotion(eEquipKind, eEquipRank, stInfo.wMasterLevel);
    stCliData.wNextPromote         = oPropMgr.GetNextPromotion(eEquipKind, eEquipRank, stInfo.wMasterLevel);
    stCliData.byActivateOrBreak    = GetActivateOrBreakState(stInfo);
    stCliData.dwMedalCost          = oPropMgr.GetBreakMedal(eEquipKind, eEquipRank);
    stCliData.wRequiredPlayerLevel = oPropMgr.GetBreakPlayerLevel(eEquipKind, eEquipRank);

    // �޷�������ʱ�������Ͳ���ʾ�ˣ���Ϊ0
    if(IsLevelMax(stInfo))
    {
        stCliData.dwMaxMasterExp   = 0;
    }
}

// ����װ����ͨ����ϸ��Ϣ�б�
void CEquipMaster::StoreIntoMasterDetail(DT_EQUIP_MASTER_DETAIL_CLI astData[EQUIP_KIND_COUNT])
{
    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_EQUIP_MASTER_DETAIL_CLI &stCliData = astData[i];
        DT_EQUIP_MASTER_DETAIL &stData = m_stData.astMasterInfo[i];

        StoreIntoMasterDetailByKind(stCliData, stData);
    }
}

// ����ʹ�þ�����������������Ϣ
void CEquipMaster::StoreIntoLevelUpInfo(DT_MASTER_LEVEL_UP_INFO astInfo[EQUIP_KIND_COUNT], UINT16 awPreLevel[EQUIP_KIND_COUNT], UINT16 awUpExps[EQUIP_KIND_COUNT])
{
    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_MASTER_LEVEL_UP_INFO &stInfo = astInfo[i];
        stInfo.wUpExp = awUpExps[i];

        GenLeveUpInfo(stInfo, (EEquipPosType)(i + 1), awPreLevel[i]);
    }
}

// ��ȡָ��װ����ͨ����ʲô״̬��������0���ɼ���1����ͻ��2���޷�����3����ͻ�Ƶ���ҵȼ�����4
EEquipMasterDetailState CEquipMaster::GetActivateOrBreakState(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    if(FALSE == IsActivated(stDetail))
    {
        return EQUIP_MASTER_ACTIVATABLE; // �ɼ���
    }

    // �Ƿ��ͻ��
    if(IsBreakable(stDetail))
    {
        // ��ҵȼ��Ƿ���
        if(m_poOwner->GetLevel() < CEquipMasterPropMgr::Instance()->GetBreakPlayerLevel((EEquipPosType)stDetail.byMasterKind, (EEquipMasterRank)stDetail.byMasterRank))
        {
            return EQUIP_MASTER_PLAYER_LVL_NOT_ENOUGH;
        }

        return EQUIP_MASTER_BREAKABLE; // ��ͻ��
    }

    // �Ƿ��Ѿ��۷�
    if(IsLevelFull(stDetail) && IsRankTop(stDetail))
    {
        return EQUIP_MASTER_TOP;
    }

    return EQUIP_MASTER_UPGRADABLE;
}

// ����������֮ͨ�����ĳ�ǧ��Ϣ
void CEquipMaster::StoreIntoCheatInfo(DT_MASTER_CHEAT_INFO_CLI &stCheatInfo)
{
    stCheatInfo.wCheatGold          = GetCheatGold();

    CHAR freeChatTime = CEquipMasterPropMgr::Instance()->GetMaxFreeCheatCnt() - GetCheatTimes();
    stCheatInfo.byFreeCheatCnt =  (freeChatTime > 0 ? freeChatTime : 0);
}

// ���뾫ͨ������������ϸ��Ϣ�б�
void CEquipMaster::StoreIntoBookPanel(DT_MASTER_EXP_BOOK_PANEL_CLI &stBookPanel)
{
    for(int i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        stBookPanel.astExpBooks[i].byBigExpBookCnt = m_stData.astExpBookPanel[i].byBigExpBookCnt;
    }

    stBookPanel.wBigBookExp     = CEquipMasterPropMgr::Instance()->GetBigBookExp();
    stBookPanel.wSmallBookExp   = CEquipMasterPropMgr::Instance()->GetSmallBookExp();

    stBookPanel.byIsOpenUpCheat = (m_poOwner->GetLevel() >= CEquipMasterPropMgr::Instance()->GetMasterCheatPlayerLevel());
    if(stBookPanel.byIsOpenUpCheat)
    {
        StoreIntoCheatInfo(stBookPanel.stCheatInfo);
    }
}

// ��ȡ��֮ͨ������״̬
EMasterBookPanelState CEquipMaster::GetMasterBookState()
{
    return (EMasterBookPanelState)m_stData.byCultivatePanelState;
}

// �Ƿ��ѻ�ȡ����֮ͨ��
BOOL CEquipMaster::IsMasterBookGotten()
{
    return (MASTER_BOOK_PANEL_WIPED_BUT_NOT_CONFIRMED == GetMasterBookState() || MASTER_BOOK_PANEL_GET_BUT_NOT_WIPED == GetMasterBookState());
}

// ��ȡ��ǰ�ľ�ͨ�ȼ�
UINT16 CEquipMaster::GetCurEquipLevel(EEquipPosType eEquipKind)
{
    DT_EQUIP_MASTER_DETAIL *pstDetail = GetMasterInfoByKind(eEquipKind);
    if(NULL == pstDetail)
    {
        return 0;
    }

    return pstDetail->wMasterLevel;
}

// ��ȡ������ͨ���ǰ�ĵȼ�
void CEquipMaster::GetCurEquipLevels(UINT16 wCurLevel[EQUIP_KIND_COUNT])
{
    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        wCurLevel[i] = GetCurEquipLevel((EEquipPosType)(i + 1));
    }
}


// ���þ�ͨ���������״̬
void CEquipMaster::SetExpBookPanelState(EMasterBookPanelState ePanelState)
{
    m_stData.byCultivatePanelState = ePanelState;
}

// ���㾭��������ϵľ����ܺͣ����ڴ˻����Ͻ��д����龭�鷭������
void CEquipMaster::GetExpUp(UINT16 awExpUp[EQUIP_KIND_COUNT])
{
    GetExpSum(awExpUp);

    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_MASTER_EXP_BOOK_DETAIL &stExpBook = m_stData.astExpBookPanel[i];

        // ������������ˣ������վ���ֵ = ԭ������ֵ X ��������
        if(MASTER_EXP_BOOK_COUNT_PER_KIND == stExpBook.byBigExpBookCnt)
        {
            awExpUp[i] *= CEquipMasterPropMgr::Instance()->GetExpXnum();
        }
    }
}

// �������㾭��������ϵľ����ܺ�
void CEquipMaster::GetExpSum(UINT16 awExpSum[EQUIP_KIND_COUNT])
{
    memset(awExpSum, 0, sizeof(awExpSum[0]) * EQUIP_KIND_COUNT);

    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_MASTER_EXP_BOOK_DETAIL &stExpBook = m_stData.astExpBookPanel[i];

        UINT32 dwBigExp = CEquipMasterPropMgr::Instance()->GetBigBookExp() * stExpBook.byBigExpBookCnt;
        UINT32 dwSmallExp = CEquipMasterPropMgr::Instance()->GetSmallBookExp() * (MASTER_EXP_BOOK_COUNT_PER_KIND - stExpBook.byBigExpBookCnt);

        // �����龭�� = С�龭�� + ���龭��
        awExpSum[i] =  dwBigExp + dwSmallExp;
    }
}

// ���ݻ�ȡ���ľ�������еȼ�����������
void CEquipMaster::LevelUpByExpBooks()
{
    UINT16 awExpUp[EQUIP_KIND_COUNT];
    GetExpUp(awExpUp);

    for(BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        AddExp((EEquipPosType)(i + 1), awExpUp[i]);
    }

    ClearExpBooks();
}

// ��ǰ�ȼ��������Ƿ�����
BOOL CEquipMaster::IsExpBarFull(DT_EQUIP_MASTER_DETAIL &stDetail)
{
    UINT32 dwCurLevelMaxExp = CEquipMasterPropMgr::Instance()->GetMaxExp((EEquipPosType)stDetail.byMasterKind, (EEquipMasterRank)stDetail.byMasterRank, stDetail.wMasterLevel);
    if(stDetail.dwExp >= dwCurLevelMaxExp)
    {
        return TRUE;
    }

    return FALSE;
}

// ����ָ��װ�����͵ľ�ͨ���飬������ʵ�ʼ��˶��پ���
UINT32 CEquipMaster::AddExp(EEquipPosType eEquipKind, UINT32 dwExpAdd)
{
    DT_EQUIP_MASTER_DETAIL *pstData = GetMasterInfoByKind(eEquipKind);
    if(NULL == pstData)
    {
        return 0;
    }

    UINT32 dwLeftExp = dwExpAdd;

    // ͻ�Ƶȼ�
    UINT16 wBreakLevel = CEquipMasterPropMgr::Instance()->GetBreakLevel(eEquipKind, (EEquipMasterRank)pstData->byMasterRank);
    if(0 == wBreakLevel)
    {
        return 0;
    }

    // �������õľ���һֱ����
    while(dwLeftExp > 0)
    {
        UINT32 dwMaxExp = CEquipMasterPropMgr::Instance()->GetMaxExp(eEquipKind, (EEquipMasterRank)pstData->byMasterRank, pstData->wMasterLevel);
        if(0 == dwMaxExp)
        {
            break;;
        }

        // ���þ����Ƿ��㹻������һ��
        if(pstData->dwExp + dwLeftExp >= dwMaxExp)
        {
            // �ǲ��ǿ�Ҫͻ����
            if(pstData->wMasterLevel >= wBreakLevel)
            {
                // �Ƿ��Ѿ��������ף������Ļ��޷���ͻ�ƣ���������Ϊ0
                if(pstData->byMasterRank >= EMG_GRADE_4)
                {
                    pstData->dwExp = 0;
                }
                else
                {
                    dwLeftExp -= dwMaxExp - pstData->dwExp;
                    pstData->dwExp = dwMaxExp;
                }

                break;
            }
            else
            {
                dwLeftExp -= dwMaxExp - pstData->dwExp;
                pstData->wMasterLevel++;
                pstData->dwExp = 0;
            }
        }
        else
        {
            // ����������һ��
            pstData->dwExp += dwLeftExp;
            dwLeftExp = 0;

            break;
        }
    }

    return dwExpAdd - dwLeftExp;
}

// ����ʹ�þ�����������������Ϣ
void CEquipMaster::GenLeveUpInfo(DT_MASTER_LEVEL_UP_INFO &stInfo, EEquipPosType eEquipKind, UINT16 wPreLevel)
{
    DT_EQUIP_MASTER_DETAIL *pstDetail = GetMasterInfoByKind(eEquipKind);
    if(NULL == pstDetail)
    {
        return;
    }

    EEquipMasterRank eEquipRank = (EEquipMasterRank)pstDetail->byMasterRank;

    BYTE byLevelDiff = pstDetail->wMasterLevel - wPreLevel - 1;
    BYTE byMinLevelDiff = MIN(byLevelDiff, MASTER_MAX_LEVEL_UP);
    
    for (BYTE i = 0; i < byMinLevelDiff; i++)
    {
        DT_MASTER_LEVEL_UP &stLevelUp = stInfo.astLevelUp[i];

        stLevelUp.dwMaxMasterExp = CEquipMasterPropMgr::Instance()->GetMaxExp(eEquipKind, eEquipRank, wPreLevel + i + 1);
        stLevelUp.wPromote       = CEquipMasterPropMgr::Instance()->GetAttrPromotion(eEquipKind, eEquipRank, wPreLevel + i + 1);
        stLevelUp.wNextPromote   = CEquipMasterPropMgr::Instance()->GetAttrPromotion(eEquipKind, eEquipRank, wPreLevel + i + 2);
    }

    stInfo.byLevelDiff = byMinLevelDiff;
    stInfo.wPreLevel = wPreLevel;
}

// �����������岢����״̬
void CEquipMaster::ClearExpBooks()
{
    memset(m_stData.astExpBookPanel, 0, sizeof(m_stData.astExpBookPanel));
}

// �ǲ��Ǽ�����������ͨ���ǵĻ�װ�����Եõ�����
void CEquipMaster::AddAttrByEquipMaster(CEquip &oEquip, DT_BATTLE_ATTRIBUTE& stAttr)
{
    if(NULL == m_poOwner->GetBuild(EBK_EQUIP_MASTER))
    {
        return;
    }

    SEquipProp* pstEquipProp =  CEquipPropMgr::Instance()->GetProp(oEquip.GetItemKindID());
    if(NULL == pstEquipProp)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: pstEquipProp is NULL,KindID[%d]!"), MSG_MARK, oEquip.GetItemKindID());
        return;
    }

    EEquipPosType eEquipKind = (EEquipPosType)pstEquipProp->byPosKindID; // ��ȡװ����λ�����ͣ�ͷ����ս�ۡ�������սѥ��
    DT_EQUIP_MASTER_DETAIL *pstData = GetMasterInfoByKind(eEquipKind);
    if(NULL == pstData)
    {
        return;
    }

    if(FALSE == IsActivated(*pstData))
    {
        return;
    }

    // ��ȡװ�����������ٷֱ�
    UINT16 wPromote = GetCurPromote(*pstData);
    stAttr.dwAttack += (UINT32)(stAttr.dwAttack * FLOAT(wPromote) / 100);
}

// ͳ�ƴ����������
BYTE CEquipMaster::CountBigExpBook()
{
    BYTE byBigExpBookCnt = 0;

    // �ĸ��������������ۼ�
    for (BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        byBigExpBookCnt += m_stData.astExpBookPanel[i].byBigExpBookCnt;
    }

    return byBigExpBookCnt;
}

// ͳ��С�����������
BYTE CEquipMaster::CountSmallExpBook()
{
    return MASTER_EXP_BOOK_COUNT - CountBigExpBook();
}

// ��ȡ��ǧ����
BYTE CEquipMaster::GetCheatTimes()
{
    return m_stData.byCheatTimes;
}

// �����һ���������ǧ
EEquipPosType CEquipMaster::RollCheatKind()
{
    // ��ͳ�Ƴ����������С��������Գ�ǧ
    BYTE byCanCheatKindCnt = 0;
    for (BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_MASTER_EXP_BOOK_DETAIL &stExpBook   = m_stData.astExpBookPanel[i];
        if(stExpBook.byBigExpBookCnt < MASTER_EXP_BOOK_COUNT_PER_KIND)
        {
            byCanCheatKindCnt++;
        }
    }

    if(0 == byCanCheatKindCnt)
    {
        return (EEquipPosType)(0);
    }

    // Ȼ�����ѡ�����Գ�ǧ�����
    BYTE byRand = Random(1, byCanCheatKindCnt);

    BYTE byCheatKind = 0;
    for (BYTE i = 0; i < EQUIP_KIND_COUNT; i++)
    {
        DT_MASTER_EXP_BOOK_DETAIL &stExpBook   = m_stData.astExpBookPanel[i];
        if(stExpBook.byBigExpBookCnt < MASTER_EXP_BOOK_COUNT_PER_KIND)
        {
            byRand--;

            if(0 == byRand)
            {
                byCheatKind = i + 1;
                break;;
            }
        }
    }

    return (EEquipPosType)byCheatKind;
}

// ��ָ������ϳ�ǧ
void CEquipMaster::CheatAt(EEquipPosType byCheatKind)
{
    if(byCheatKind == 0 || byCheatKind > EQUIP_KIND_COUNT)
    {
        return;
    }

    DT_MASTER_EXP_BOOK_DETAIL &stExpBook   = m_stData.astExpBookPanel[byCheatKind - 1];
    if(stExpBook.byBigExpBookCnt >= MASTER_EXP_BOOK_COUNT_PER_KIND)
    {
        return;
    }

    stExpBook.byBigExpBookCnt++;
    m_stData.byCheatTimes++;
}

// ��ǧ��ʧ�ܷ���0���ɹ����س�ǧ���
EEquipPosType CEquipMaster::Cheat()
{
    EEquipPosType byCheatKind = RollCheatKind();
    CheatAt(byCheatKind);

    return byCheatKind;
}
