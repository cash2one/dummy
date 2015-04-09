#ifndef _equipmaster_h_
#define _equipmaster_h_

#include <protocol/server/protocommondata.h>
#include <logic/base/baseobj.h>
#include <common/client/commondef.h>
#include <protocol/server/protocligs.h>
#include "common/server/utility.h"

using namespace std ;

class CPlayer;
class CEquip;

/**
 * @brief ��ҵ�װ����ͨ��
 */
class CEquipMaster : public CBaseObj
{
public:
    CEquipMaster();

public:
    // ��ʼ����ض���
    BOOL Init(DT_EQUIP_MASTER &stData, CPlayer* poOwner);
    VOID CopyTo(DT_EQUIP_MASTER &dst) { memcpy(&dst, &m_stData, sizeof(DT_EQUIP_MASTER)); }

public:
    // �ǲ��Ǽ�����������ͨ���ǵĻ�װ�����Եõ�����
    void AddAttrByEquipMaster(CEquip&, DT_BATTLE_ATTRIBUTE&);

public:
    // ��װ����ͨ���
    UINT16 OnOpenEquipMaster(PKT_CLIGS_OPEN_EQUIP_MASTER_ACK&);

    // ����װ����ͨ
    UINT16 OnActivateEquipMaster(PKT_CLIGS_ACTIVATE_MASTER_ACK&, EEquipPosType eEquipKind);

    // ͻ��
    UINT16 OnBreakMaster(PKT_CLIGS_BREAK_MASTER_ACK&, EEquipPosType byEquipKind);

    // ������֮ͨ��
    UINT16 OnCultivateMasterBook(PKT_CLIGS_GET_MASTER_BOOK_ACK&);

    // �ο���ͨ���������
    UINT16 OnWipeMasterBook(PKT_CLIGS_WIPE_MASTER_BOOK_ACK&);

    // ��ͨ�������ǧ
    UINT16 OnCheatMasterBook(PKT_CLIGS_MASTER_CHEAT_ACK&);

    // ȷ��ʹ�þ�ͨ������
    UINT16 OnConfirmMasterBook(PKT_CLIGS_CONFIRM_MASTER_BOOK_ACK&);

public:
    // װ����ͨ�ȼ����������ã�����gmָ��
    void Reset();

    // �Ƿ��Ѽ���
    BOOL IsActivated(DT_EQUIP_MASTER_DETAIL&);

    // ��������װ����ͨ�Ƿ���ȫ��������
    BOOL IsAllActivated();
    
    // �Ƿ�ﵽͻ������
    BOOL IsBreakable(DT_EQUIP_MASTER_DETAIL&);

	// �ǲ����Ѿ��Ƿ��켫�ˣ����о�ͨȫ����
	BOOL IsAllLevelMax();

    // ָ����ͨ����ǲ����Ѿ��Ƿ��켫��
    BOOL IsLevelMax(DT_EQUIP_MASTER_DETAIL&);

	// �Ƿ���ĳ����ͨ����ڿ�ͻ��״̬
	BOOL IsAnyBreakable();

    // ��ȡ��֮ͨ������״̬
    EMasterBookPanelState GetMasterBookState();

    // ��������ȡ��Ӧװ����ͨ����ϸ��Ϣ
    DT_EQUIP_MASTER_DETAIL* GetMasterInfoByKind(UINT16 wEquipKind);

    // ���о�ͨ���Ľ׼��Ƿ�����
    BOOL IsAllRankTop();

    // ��ȡ��ǧ���ĵ�Ԫ��
    UINT32 GetCheatGold();

private:
    // ����װ����ͨ
    void Activate(DT_EQUIP_MASTER_DETAIL&);

    // ͻ�ƾ�ͨ�׼�
    void BreakThrough(DT_EQUIP_MASTER_DETAIL&);

    // ���þ�ͨ���������״̬
    void SetExpBookPanelState(EMasterBookPanelState);

    // ���ɾ�ͨ������
    void GenerateMasterExpBook();

    // ���ݻ�ȡ���ľ�������еȼ��������������˶��پ��������
    void LevelUpByExpBooks();

    // ����ָ��װ�����͵ľ�ͨ���飬������ʵ�ʼ��˶��پ���
    UINT32 AddExp(EEquipPosType eEquipKind, UINT32 dwExp);

    // �����������岢����״̬
    void ClearExpBooks();

    // ͳ�ƴ����������
    BYTE CountBigExpBook();

    // ͳ��С�����������
    BYTE CountSmallExpBook();

    // ��ȡ��ǧ����
    BYTE GetCheatTimes();

    // �����һ���������ǧ
    EEquipPosType RollCheatKind();

    // ��ָ������ϳ�ǧ
    void CheatAt(EEquipPosType byCheatKind);

    // ��ǧ��ʧ�ܷ���0���ɹ����س�ǧ���
    EEquipPosType Cheat();
    
    // �Ƿ��ѻ�ȡ����֮ͨ��
    BOOL IsMasterBookGotten();

    // ��ȡ��ǰ�ľ�ͨ�ȼ�
    UINT16 GetCurEquipLevel(EEquipPosType eEquipKind);

    // ��ȡ������ͨ���ǰ�ĵȼ�
    void GetCurEquipLevels(UINT16 wCurLevel[EQUIP_KIND_COUNT]);

	// ���㾭��������ϵľ����ܺͣ����ڴ˻����Ͻ��д����龭�鷭������
	void GetExpUp(UINT16 awExpUp[EQUIP_KIND_COUNT]);

    // �������㾭��������ϵľ����ܺ�
    void GetExpSum(UINT16 awExpSum[EQUIP_KIND_COUNT]);

public:
    // �����װ����ͨ����Ӧ��Ϣ��
    void StoreOpenMasterAck(PKT_CLIGS_OPEN_EQUIP_MASTER_ACK &ack);

    // ���뼤���Ӧ��Ϣ��
    void StoreActivateAck(PKT_CLIGS_ACTIVATE_MASTER_ACK &ack, DT_EQUIP_MASTER_DETAIL&);

    // ����ͻ�ƻ�Ӧ��Ϣ��
    void StoreBreakAck(PKT_CLIGS_BREAK_MASTER_ACK &ack, DT_EQUIP_MASTER_DETAIL&);

    // ����������֮ͨ���Ӧ��Ϣ��
    void StoreCultivateAck(PKT_CLIGS_GET_MASTER_BOOK_ACK &ack);

    // ����ȷ�Ϲο������Ӧ
    void StoreConfirmWipeAck(PKT_CLIGS_CONFIRM_MASTER_BOOK_ACK &ack, UINT16 awPreEquipLevel[EQUIP_KIND_COUNT], UINT16 awUpExps[EQUIP_KIND_COUNT]);

    // �����ǧ��Ӧ
    void StoreCheatAck(PKT_CLIGS_MASTER_CHEAT_ACK &ack);

private:
    // ����װ����ͨ����ϸ��Ϣ�б�
    void StoreIntoMasterDetail(DT_EQUIP_MASTER_DETAIL_CLI astData[EQUIP_KIND_COUNT]);

    // ����ʹ�þ�����������������Ϣ
    void StoreIntoLevelUpInfo(DT_MASTER_LEVEL_UP_INFO astInfo[EQUIP_KIND_COUNT], UINT16 awPreLevel[EQUIP_KIND_COUNT], UINT16 awUpExps[EQUIP_KIND_COUNT]);

    // ����ĳ������װ����ͨ��ϸ��Ϣ
    void StoreIntoMasterDetailByKind(DT_EQUIP_MASTER_DETAIL_CLI&, DT_EQUIP_MASTER_DETAIL&);

    // ���뾫ͨ������������ϸ��Ϣ�б�
    void StoreIntoBookPanel(DT_MASTER_EXP_BOOK_PANEL_CLI &stBookPanel);

    // ����������֮ͨ�����ĳ�ǧ��Ϣ
    void StoreIntoCheatInfo(DT_MASTER_CHEAT_INFO_CLI &stCheatInfo);

private:

    // ��ȡָ��װ����ͨ����ʲô״̬��������0���ɼ���1����ͻ��2���޷�����3����ͻ�Ƶ���ҵȼ�����4
    EEquipMasterDetailState GetActivateOrBreakState(DT_EQUIP_MASTER_DETAIL&);

    // ָ�����ĵ�ǰ�ȼ��������Ƿ�����
    BOOL IsExpBarFull(DT_EQUIP_MASTER_DETAIL&);

    // ָ�����ľ�ͨ�׼��Ƿ��Ѿ��Ƕ���
    BOOL IsRankTop(DT_EQUIP_MASTER_DETAIL&);

    // ָ�����ľ�ͨ����Ƿ�������
    BOOL IsLevelFull(DT_EQUIP_MASTER_DETAIL&);

    // ��ȡָ��װ�������������ٷֱ�
    UINT16 GetCurPromote(DT_EQUIP_MASTER_DETAIL&);

    // ����ʹ�þ�����������������Ϣ
    void GenLeveUpInfo(DT_MASTER_LEVEL_UP_INFO&, EEquipPosType eEquipKind, UINT16 wPreLevel);

    // ����װ����ͨ���ݣ��������쳣
    void FixMaster();

private:
    DT_EQUIP_MASTER	m_stData;
};

DECLARE_CLASS_POOL_MGR(CEquipMaster)

#endif // _equipmaster_h_
