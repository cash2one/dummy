#include "equipmasterpropmgr.h"

#include <db/dbmgr.h>
#include <framework/gsapi.h>
#include <logic/base/logicfunc.h>
#include <dll/sdframework/sdloggerimpl.h>

namespace masterutil
{
    BOOL IsKindValid(EEquipPosType eEquipKind)
    {
        if(eEquipKind == 0 || eEquipKind > EQUIP_KIND_COUNT)
        {
            return FALSE;
        }

        return TRUE;
    }

    BOOL IsValid(EEquipPosType eEquipKind, EEquipMasterRank byEquipRank)
    {
        if(FALSE == IsKindValid(eEquipKind) || byEquipRank > MASTER_RANK_COUNT)
        {
            return FALSE;
        }

        return TRUE;
    }
}

IMPLEMENT_SINGLETON_PROPMGR(CEquipMasterPropMgr);

CEquipMasterPropMgr::CEquipMasterPropMgr() :
    m_dwMasterCultivateMedalCost(0),
    m_dwMasterCheatPlayerLevel(0),
    m_dwBigBookExp(0),
    m_dwSmallBookExp(0),
    m_byMaxFreeCheatCnt(0),
    m_byExpXnum(0)
{

}

BOOL CEquipMasterPropMgr::Init()
{
    m_byExtraExpBigBookCnt = 0;

    if(!LoadFromDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CEquipMasterPropMgr::LoadFromDB failed!"), MSG_MARK);
        return FALSE;
    }

    return TRUE;
}

VOID CEquipMasterPropMgr::UnInit()
{
}

// ����װ����ͨ������������
BOOL CEquipMasterPropMgr::LoadFromDB()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetCfgDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }

    if(FALSE == (LoadBreakPropFromDB(*pDBSession) &&
                 LoadExpPropFromDB(*pDBSession) &&
                 LoadRatePropFromDB(*pDBSession) &&
                 LoadCheatPropFromDB(*pDBSession) &&
                 LoadDefPropFromDB(*pDBSession)))
    {
        return FALSE;
    }

    CastProps();
    return CheckProp();
}

// ������������Ƿ�������쳣������TRUE/�쳣FALSE
BOOL CEquipMasterPropMgr::CheckProp()
{
    if(m_mapBreak.size() != EQUIP_KIND_COUNT * (MASTER_RANK_COUNT + 1))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: detected <masterbreakprop> table data error: some record is missing!"), MSG_MARK);
        return FALSE;
    }

    if(m_mapRate.size() != EQUIP_KIND_COUNT * (MASTER_EXP_BOOK_COUNT_PER_KIND + 1))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: detected <masterrateprop> table data error: some record is missing!"), MSG_MARK);
        return FALSE;
    }

    if(0 != (m_mapExp.size() % 4))
    {
        SYS_CRITICAL(_SDT("[%s: %d]: detected <masterexpprop> table data error: some record is missing!"), MSG_MARK);
        return FALSE;
    }

    if(m_vecCheatCost.size() != MASTER_EXP_BOOK_COUNT + 1)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: detected <mastercheatprop> table data error: some record is missing!"), MSG_MARK);
        return FALSE;
    }

    return TRUE;
}

// �������ݿ�ȡ�������ݽ����ɷ����ȡ�����ø�ʽ
void CEquipMasterPropMgr::CastProps()
{
    m_vecBigExpBookRate.clear();
    m_vecBigExpBookRate.resize(EQUIP_KIND_COUNT + 1);

    // �洢�����������������ʱ�
    for (BYTE i = 1; i <= EQUIP_KIND_COUNT; i++)
    {
        CRandomVec &vecRandom = m_vecBigExpBookRate[i];

        for (BYTE j = 0; j <= MASTER_EXP_BOOK_COUNT_PER_KIND; j++)
        {
            SEquipMasterRateProp &stProp = m_mapRate[CLogicFunc::Get3232Key(i, j)];
            vecRandom.push_back(stProp.byRate);
        }
    }

    m_byMaxFreeCheatCnt = 0;

    // �����ÿ��������֮ͨ������ѳ�ǧ����
    for(BYTE i = 1; i <= MASTER_EXP_BOOK_COUNT; i++)
    {
        SEquipMasterCheatCostProp &prop = m_vecCheatCost[i];

        if(0 == prop.wGoldCost)
        {
            m_byMaxFreeCheatCnt++;
        }
        else
        {
            break;
        }
    }
}

// ����ͻ������
BOOL CEquipMasterPropMgr::LoadBreakPropFromDB(SGDP::ISDDBSession &oDBSession)
{
    SGDP::ISDDBRecordSet* pRes = NULL;

    INT32 nRet = oDBSession.ExecuteSqlRs(GetPropTableSelectSql("masterbreakprop").c_str(), &pRes);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    SEquipMasterBreakProp stProp = {(EEquipPosType)0};
    while(pRes->GetRecord()) // �����н��ʱ
    {
        stProp.eEquipKind        = (EEquipPosType)SGDP::SDAtou(pRes->GetFieldValueByName("EquipKind"));
        stProp.eEquipRank        = (EEquipMasterRank)SGDP::SDAtou(pRes->GetFieldValueByName("Rank"));
        stProp.wBreakMedal       = SGDP::SDAtou(pRes->GetFieldValueByName("BreakMedal"));
        stProp.wBreakLevel       = SGDP::SDAtou(pRes->GetFieldValueByName("BreakLevel"));
        stProp.wBreakPlayerLevel = SGDP::SDAtou(pRes->GetFieldValueByName("BreakPlayerLevel"));

        UINT64 qwKey = CLogicFunc::Get3232Key(stProp.eEquipKind, stProp.eEquipRank);
        m_mapBreak[qwKey] = stProp;
    }

    pRes->Release();
    return TRUE;
}

// ���뾭������
BOOL CEquipMasterPropMgr::LoadExpPropFromDB(SGDP::ISDDBSession &oDBSession)
{
    SGDP::ISDDBRecordSet* pRes = NULL;

    INT32 nRet = oDBSession.ExecuteSqlRs(GetPropTableSelectSql("masterexpprop").c_str(), &pRes);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    SEquipMasterExpProp stProp = {(EEquipPosType)0};
    while(pRes->GetRecord()) // �����н��ʱ
    {
        stProp.eEquipKind  = (EEquipPosType)SGDP::SDAtou(pRes->GetFieldValueByName("EquipKind"));
        stProp.eEquipRank  = (EEquipMasterRank)SGDP::SDAtou(pRes->GetFieldValueByName("Rank"));
        stProp.wEquipLevel = SGDP::SDAtou(pRes->GetFieldValueByName("Level"));
        stProp.qwExp       = SGDP::SDAtou(pRes->GetFieldValueByName("Exp"));
        stProp.qwPromote   = SGDP::SDAtou(pRes->GetFieldValueByName("Promote"));

        UINT64 qwKey = CLogicFunc::Get161616Key(stProp.eEquipKind, stProp.eEquipRank, stProp.wEquipLevel);
        m_mapExp[qwKey] = stProp;
    }

    pRes->Release();
    return TRUE;
}

// �����������
BOOL CEquipMasterPropMgr::LoadRatePropFromDB(SGDP::ISDDBSession &oDBSession)
{
    SGDP::ISDDBRecordSet* pRes = NULL;

    INT32 nRet = oDBSession.ExecuteSqlRs(GetPropTableSelectSql("masterrateprop").c_str(), &pRes);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    while(pRes->GetRecord()) // �����н��ʱ
    {
        SEquipMasterRateProp stProp;
        stProp.eEquipKind      = (EEquipPosType)SGDP::SDAtou(pRes->GetFieldValueByName("EquipKind"));;
        stProp.byBigExpBookCnt = SGDP::SDAtou(pRes->GetFieldValueByName("BigExpBookCnt"));
        stProp.byRate          = SGDP::SDAtou(pRes->GetFieldValueByName("Rate"));
        stProp.qwExp           = SGDP::SDAtou(pRes->GetFieldValueByName("Exp"));

        UINT64 qwKey = CLogicFunc::Get3232Key(stProp.eEquipKind, stProp.byBigExpBookCnt);
        m_mapRate[qwKey] = stProp;
    }

    pRes->Release();
    return TRUE;
}

// ���������������ǧ����
BOOL CEquipMasterPropMgr::LoadCheatPropFromDB(SGDP::ISDDBSession &oDBSession)
{
    SGDP::ISDDBRecordSet* pRes = NULL;

    INT32 nRet = oDBSession.ExecuteSqlRs(GetPropTableSelectSql("mastercheatprop").c_str(), &pRes);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    m_vecCheatCost.resize(MASTER_EXP_BOOK_COUNT + 1);

    while(pRes->GetRecord()) // �����н��ʱ
    {
        SEquipMasterCheatCostProp stProp;
        stProp.byCheatTimes = (EEquipPosType)SGDP::SDAtou(pRes->GetFieldValueByName("CheatTimes"));;
        stProp.wGoldCost    = SGDP::SDAtou(pRes->GetFieldValueByName("GoldCost"));

        m_vecCheatCost[stProp.byCheatTimes] = stProp;
    }

    pRes->Release();
    return TRUE;
}

// ���붨������
BOOL CEquipMasterPropMgr::LoadDefPropFromDB(SGDP::ISDDBSession &oDBSession)
{
    SGDP::ISDDBRecordSet* pRes = NULL;

    INT32 nRet = oDBSession.ExecuteSqlRs(GetPropTableSelectSql("masterdefprop").c_str(), &pRes);
    if(SDDB_HAS_RECORDSET != nRet)
    {
        SYS_CRITICAL(_SDT("[%s: %d]: has no data!"), MSG_MARK);
        return FALSE;
    }

    if(pRes->GetRecord())
    {
        m_dwMasterCultivateMedalCost  = SGDP::SDAtou( pRes->GetFieldValueByName("MasterCultivateMedalCost") );
        m_dwMasterCheatPlayerLevel    = SGDP::SDAtou( pRes->GetFieldValueByName("MasterCheatPlayerLevel") );
        m_dwBigBookExp                = SGDP::SDAtou( pRes->GetFieldValueByName("BigBookExp") );
        m_dwSmallBookExp              = SGDP::SDAtou( pRes->GetFieldValueByName("SmallBookExp") );
        m_byExpXnum                   = 2; // SGDP::SDAtou( pRes->GetFieldValueByName("MaterExpXnum") );
    }

    pRes->Release();
    return TRUE;
}

// ��ȡ�������辭��
UINT32 CEquipMasterPropMgr::GetMaxExp(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel)
{
    const SEquipMasterExpProp *pExpProp = GetExpProp(eEquipKind, eEquipRank, wEquipLevel);
    if(NULL == pExpProp)
    {
        return 0;
    }

    return pExpProp->qwExp;
}

// ��ȡ�׼�ͻ������ѫ��
UINT32 CEquipMasterPropMgr::GetBreakMedal(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank)
{
    const SEquipMasterBreakProp *pBreakProp = GetBreakProp(eEquipKind, eEquipRank);
    if(NULL == pBreakProp)
    {
        return 0;
    }

    return pBreakProp->wBreakMedal;
}

// ��ȡ�׼�ͻ�����辫ͨ�ȼ�
UINT16 CEquipMasterPropMgr::GetBreakLevel(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank)
{
    const SEquipMasterBreakProp *pBreakProp = GetBreakProp(eEquipKind, eEquipRank);
    if(NULL == pBreakProp)
    {
        return 0;
    }

    return pBreakProp->wBreakLevel;
}

// ��ȡ�׼�ͻ��������ҵȼ�
UINT16 CEquipMasterPropMgr::GetBreakPlayerLevel(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank)
{
    const SEquipMasterBreakProp *pBreakProp = GetBreakProp(eEquipKind, eEquipRank);
    if(NULL == pBreakProp)
    {
        return 0;
    }

    return pBreakProp->wBreakPlayerLevel;
}

// ��ȡ���Լӳɰٷֱ�
UINT16 CEquipMasterPropMgr::GetAttrPromotion(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel)
{
    const SEquipMasterExpProp *pExpProp = GetExpProp(eEquipKind, eEquipRank, wEquipLevel);
    if(NULL == pExpProp)
    {
        return 0;
    }

    return pExpProp->qwPromote;
}

// ��ȡ��һ��������Լӳɰٷֱ�
UINT16 CEquipMasterPropMgr::GetNextPromotion(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel)
{
    if(FALSE == GetNextLevel(eEquipKind, eEquipRank, wEquipLevel))
    {
        return 0;
    }

    return GetAttrPromotion(eEquipKind, eEquipRank, wEquipLevel);
}

// ���ݵ�ǰ�ȼ���ȡ��һ��
BOOL CEquipMasterPropMgr::GetNextLevel(/* IN */EEquipPosType eEquipKind, /* IN OUT */EEquipMasterRank &eEquipRank, /* IN OUT */UINT16 &wMasterLevel)
{
    if(FALSE == masterutil::IsValid(eEquipKind, eEquipRank))
    {
        return FALSE;
    }

    if(EMG_GRADE_0 == eEquipRank)
    {
        eEquipRank = EMG_GRADE_1;
        wMasterLevel = 1;

        return TRUE;
    }

    UINT16 wBreakLevel = GetBreakLevel(eEquipKind, eEquipRank);
    if(0 == wBreakLevel)
    {
        return FALSE;
    }

    if(wMasterLevel < wBreakLevel)
    {
        wMasterLevel++;
        return TRUE;
    }

    if(eEquipRank + 1 > MASTER_RANK_COUNT)
    {
        return FALSE;
    }

    eEquipRank = (EEquipMasterRank)(eEquipRank + 1);
    wMasterLevel = 1;

    return TRUE;
}

// �������ͨ�����������
BYTE CEquipMasterPropMgr::RollBigExpBookCnt(EEquipPosType eEquipKind)
{
    if(FALSE == masterutil::IsKindValid(eEquipKind))
    {
        return 0;
    }

    CRandomVec &vecRandom = m_vecBigExpBookRate[eEquipKind];
    INT32 randBigExpBookCnt = GetRandomIdxMustHit(vecRandom);
    return (randBigExpBookCnt > MASTER_EXP_BOOK_COUNT_PER_KIND ? MASTER_EXP_BOOK_COUNT_PER_KIND : randBigExpBookCnt);
}

// ���ݾ�������𼰴�С��ȡ����
UINT32 CEquipMasterPropMgr::GetBookExp(EEquipPosType eEquipKind, BYTE byBigExpBookCnt)
{
    if(FALSE == masterutil::IsKindValid(eEquipKind))
    {
        return 0;
    }

    UINT64 qwKey = CLogicFunc::Get3232Key(eEquipKind, byBigExpBookCnt);

    CMasterRatePropMap::iterator itr = m_mapRate.find(qwKey);
    if(itr == m_mapRate.end())
    {
        return 0;
    }

    SEquipMasterRateProp &stProp = itr->second;
    return stProp.qwExp;
}

// ���ݳ�ǧ������ȡ����Ԫ��
UINT16 CEquipMasterPropMgr::GetCheatGoldCost(BYTE byCheatTimes)
{
    if(byCheatTimes == 0 || m_vecCheatCost.empty())
    {
        // ���������10Ԫ��
        return 10;
    }

    if(byCheatTimes >= m_vecCheatCost.size())
    {
        return m_vecCheatCost.back().wGoldCost;
    }

    return m_vecCheatCost[byCheatTimes].wGoldCost;
}

// ���ݾ�ͨ��𡢽׼����ȼ���ȡָ����װ����ͨ������Ϣ
const SEquipMasterExpProp* CEquipMasterPropMgr::GetExpProp(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel)
{
    if(FALSE == masterutil::IsValid(eEquipKind, eEquipRank))
    {
        return NULL;
    }

    UINT64 qwKey = CLogicFunc::Get161616Key(eEquipKind, eEquipRank, wEquipLevel);

    CMasterExpPropMap::iterator itr = m_mapExp.find(qwKey);
    if(itr == m_mapExp.end())
    {
        return NULL;
    }

    SEquipMasterExpProp &stProp = itr->second;
    return &stProp;
}

// ���ݾ�ͨ��𡢽׼���ȡװ����ͨͻ����Ϣ
const SEquipMasterBreakProp* CEquipMasterPropMgr::GetBreakProp(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank)
{
    if(FALSE == masterutil::IsValid(eEquipKind, eEquipRank))
    {
        return NULL;
    }

    UINT64 qwKey = CLogicFunc::Get3232Key(eEquipKind, eEquipRank);

    CMasterBreakPropMap::iterator itr = m_mapBreak.find(qwKey);
    if(itr == m_mapBreak.end())
    {
        return NULL;
    }

    SEquipMasterBreakProp &stProp = itr->second;
    return &stProp;
}
