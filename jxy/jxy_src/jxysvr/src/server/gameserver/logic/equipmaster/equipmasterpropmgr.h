#ifndef _equipmasterpropmgr_h_
#define _equipmasterpropmgr_h_

/**
 * @brief װ����ͨ��������
 */

#include <vector>

#include <utility.h>
#include <sdtype.h>
#include <sddebug.h>
#include <common/client/commondef.h>
#include <sdhashmap.h>

#include "equipmaster.h"
#include "logic/base/basepropmgr.h"

namespace SGDP
{
class ISDDBSession;
}

// װ����ͨ��ͻ������
struct SEquipMasterBreakProp
{
    EEquipPosType    eEquipKind;        // װ�����ͷ����ս�ۡ�������սѥ��
    EEquipMasterRank eEquipRank;        // װ����ͨ�׼���δ����0����1����2����3����4��
    UINT32           wBreakMedal;       // ͻ�Ƶ���һ����������ѫ��
    UINT16           wBreakLevel;       // ͻ�����辫ͨ�ȼ�
    UINT16           wBreakPlayerLevel; // ͻ��������ҵȼ�
};

// װ����ͨ�ľ��鼰�ӳ�����
struct SEquipMasterExpProp
{
    EEquipPosType    eEquipKind;  // װ�����ͷ����ս�ۡ�������սѥ��
    EEquipMasterRank eEquipRank;  // װ����ͨ�׼���δ����0����1����2����3����4��
    UINT16           wEquipLevel; // ��ͨ����
    UINT32           qwExp;       // ��������������
    UINT32           qwPromote;   // ���Լӳɣ�����20���ʾ���Լӳ�+20%
};

// ������֮ͨ�龭�������ɵĸ�������
struct SEquipMasterRateProp
{
    EEquipPosType eEquipKind;      // װ�����ͷ����ս�ۡ�������սѥ��
    BYTE          byBigExpBookCnt; // ������������0��1��2��3��
    BYTE          byRate;          // ��Ӧ���ʣ�����ֵ10��ʾ10%
    UINT16        qwExp;           // �Ӷ��پ���
};

// ������֮ͨ���������⾭������
struct SEquipMasterExtraExpProp
{
    BYTE byBigExpBookCnt; // ����������(1-12)
    UINT16 wExtraExp;     // ��Ӧ�Ķ��⾭��ֵ
};

// ��ǧ�ķ�Ԫ������
struct SEquipMasterCheatCostProp
{
    BYTE byCheatTimes;    // ��ǧ��������Χ1-12
    UINT16 wGoldCost;     // Ԫ���ķ�����
};

// ���ͻ�����ݱ�
typedef std::map<UINT64, SEquipMasterBreakProp> CMasterBreakPropMap; // key = ��ͨ��� + ��ͨ�׼�

// ���鼰�ӳ����ݱ�
typedef std::map<UINT64, SEquipMasterExpProp> CMasterExpPropMap; // key = ��� + �׼� + ����

// ������֮ͨ��ʱ���ɾ�ͨ������ĸ��ʱ�
typedef std::map<UINT64, SEquipMasterRateProp> CMasterRatePropMap; // key = ��� + ����������

// ���⾭�����ݱ�
typedef std::vector<SEquipMasterExtraExpProp> CMasterExtraExpPropVec;

// ��ǧ�ķ�Ԫ������
typedef std::vector<SEquipMasterCheatCostProp> CMasterCheatCostPropVec;


// ��ͨ�����������ʱ�
typedef std::vector<BYTE> ExpBookRateVec;

// ���ɴ�ͨ������ĸ��ʱ�
// �����������£�
// [
//     ͷ��{0����������ʣ� 1�����ʣ� 2�����ʣ� 3������}
//     ս��{0����������ʣ� 1�����ʣ� 2�����ʣ� 3������}
//     ����{0����������ʣ� 1�����ʣ� 2�����ʣ� 3������}
//     սѥ{0����������ʣ� 1�����ʣ� 2�����ʣ� 3������}
// ]
typedef std::vector<CRandomVec> CRollBigExpBookVec;

/**
 * @brief װ����ͨ��������
 */
class CEquipMasterPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CEquipMasterPropMgr);

    CEquipMasterPropMgr();

public:
    // @impl
    virtual EConfigModule GetConfigModuleType()
    {
        return ECM_EQUIP_MASTER;
    }

    BOOL Init();

    VOID UnInit();

public:
    // ��ȡ�������辭��
    UINT32 GetMaxExp(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel);

    // ��ȡ�׼�ͻ������ѫ�£����׼�Ϊ0ʱ�൱��ͻ�ƣ�
    UINT32 GetBreakMedal(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank);

    // ��ȡ�׼�ͻ������ȼ�
    UINT16 GetBreakLevel(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank);

    // ��ȡ�׼�ͻ���������ҵȼ�
    UINT16 GetBreakPlayerLevel(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank);

    // ��ȡ���Լӳɰٷֱ�
    UINT16 GetAttrPromotion(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel);

    // ��ȡ��һ��������Լӳɰٷֱ�
    UINT16 GetNextPromotion(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel);

    // ���ݵ�ǰ�ȼ���ȡ��һ��
    BOOL GetNextLevel(/* IN */EEquipPosType eEquipKind, /* IN OUT */EEquipMasterRank &eEquipRank, /* IN OUT */UINT16 &wMasterLevel);

    // �������ͨ�����������
    BYTE RollBigExpBookCnt(EEquipPosType eEquipKind);

    // ���ݴ�����������ȡ���飬����ֵ = �����龭�� + ʣ��С�����龭��
    UINT32 GetBookExp(EEquipPosType eEquipKind, BYTE byBigExpBookCnt);

    // ���ݳ�ǧ������ȡ����Ԫ��
    UINT16 GetCheatGoldCost(BYTE byCheatTimes);

    // ÿ��������֮ͨ�������ѳ�ǧ����
    BYTE   GetMaxFreeCheatCnt(){return m_byMaxFreeCheatCnt;}
    
    // ÿ��С������Ӷ��پ���
    UINT32 GetSmallBookExp(){return m_dwSmallBookExp;}

    // ÿ��������Ӷ��پ���
    UINT32 GetBigBookExp(){return m_dwBigBookExp;}

    // ��ȡ������֮ͨ�������ѫ������
    UINT32 GetMasterCultivateMedalCost(){return m_dwMasterCultivateMedalCost;}

    // װ����ͨ��ǧ���ܶ��ټ�����
    UINT32 GetMasterCheatPlayerLevel(){return m_dwMasterCheatPlayerLevel;}

    // ĳ��ͨ���Ĵ�����������������Զ��ٱ�
    BYTE   GetExpXnum(){return m_byExpXnum;}

private:
    // ����װ����ͨ������������
    BOOL LoadFromDB();

    // ������������Ƿ�������쳣������TRUE/�쳣FALSE
    BOOL CheckProp();

    // ����ͻ������
    BOOL LoadBreakPropFromDB(SGDP::ISDDBSession&);

    // ���뾭������
    BOOL LoadExpPropFromDB(SGDP::ISDDBSession&);

    // �����������
    BOOL LoadRatePropFromDB(SGDP::ISDDBSession&);

    // ���������������ǧ����
    BOOL LoadCheatPropFromDB(SGDP::ISDDBSession&);

    // ���붨������
    BOOL LoadDefPropFromDB(SGDP::ISDDBSession&);

    // �������ݿ�ȡ�������ݽ����ɷ����ȡ�����ø�ʽ
    void CastProps();

private:
    // ���ݾ�ͨ��𡢽׼����ȼ���ȡָ����װ����ͨ������Ϣ
    const SEquipMasterExpProp* GetExpProp(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank, UINT16 wEquipLevel);

    // ���ݾ�ͨ��𡢽׼���ȡװ����ͨͻ����Ϣ
    const SEquipMasterBreakProp* GetBreakProp(EEquipPosType eEquipKind, EEquipMasterRank eEquipRank);

private:
    // ������֮ͨ��ʱ���ɾ�ͨ������ĸ����б�
    CMasterRatePropMap m_mapRate;

    // ���ͻ�����ݱ�
    CMasterBreakPropMap m_mapBreak;

    // ���鼰�ӳ����ݱ�
    CMasterExpPropMap m_mapExp;

    // ��ǧ�ķ�Ԫ������
    CMasterCheatCostPropVec m_vecCheatCost;

    UINT32 m_dwMasterCultivateMedalCost; // ������֮ͨ��ķѵ�����ѫ��
    UINT32 m_dwMasterCheatPlayerLevel;   // װ����ͨ��ǧ���ܶ��ټ�����
    UINT32 m_dwBigBookExp;               // ÿ��������Ӷ��پ���
    UINT32 m_dwSmallBookExp;             // ÿ��С������Ӷ��پ���
    BYTE   m_byMaxFreeCheatCnt;          // ÿ��������֮ͨ�������ѳ�ǧ����
    BYTE   m_byExpXnum;                  // ĳ��ͨ���Ĵ�����������������Լ���

private:
    // ���ɴ�ͨ������ĸ��ʱ�
    CRollBigExpBookVec m_vecBigExpBookRate;

    // �ﵽ���ٱ���������ܻ�ö��⾭��
    BYTE m_byExtraExpBigBookCnt;
};

#endif // _equipmasterpropmgr_h_