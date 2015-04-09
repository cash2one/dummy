
#ifndef _OPENLIGHTPROPMGR_H_
#define _OPENLIGHTPROPMGR_H_

#include <sdtype.h>
#include <sdhashmap.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>

struct tagPKT_CLIGS_OPEN_SMITHY_ACK;
typedef tagPKT_CLIGS_OPEN_SMITHY_ACK PKT_CLIGS_OPEN_SMITHY_ACK;

struct tagDT_EQUIP_DATA_CLI;
typedef tagDT_EQUIP_DATA_CLI DT_EQUIP_DATA_CLI;

using namespace SGDP;

// ��������
struct SOpenLightProp
{
    UINT16  wKindID;            // װ��KindID
    UINT8   byIsCanOpenLight;   // �Ƿ�ɿ���
    UINT16  wNeedGoodsKindID;   // ������Ҫ����Ʒ����
    UINT16  wNeedGoodsCnt;      // ������Ҫ����Ʒ����
    UINT8   bySuccessRate;      // ����ɹ���
    UINT32  dwFullRateGold;     // ��ȫ������Ҫ��Ԫ��
    UINT16  wNewKindID;         // ������װ��KindID
};


typedef map<UINT16, SOpenLightProp> COpenLightPropMap; // keyΪװ��ID
typedef COpenLightPropMap::iterator COpenLightPropMapItr;

// ��װ��
typedef set<UINT16, less<UINT16> > CRealEquipSet; 
typedef CRealEquipSet::iterator CRealEquipSetItr;


class COpenLightPropMgr : public CBasePopMgr
{
public:
	DECLARE_SINGLETON_PROPMGR(COpenLightPropMgr);

public:
	virtual EConfigModule GetConfigModuleType() { return ECM_OPENLIGHT; }

	BOOL Init();

	VOID UnInit();

public:	
	COpenLightPropMap& GetOpenLightPropMap() { return m_mapOpenLightPropMap; }

	void GetOpenLightFlagInfo(PKT_CLIGS_OPEN_SMITHY_ACK& stAck);    // ��ȡ����װ���Ŀɿ����ʶ��
    void GetOpenLightFlagInfo_v410(PKT_CLIGS_OPEN_SMITHY_ACK_v410& stAck); // ��ȡ����װ���Ŀɿ����ʶ��

    UINT8 GetOpenLightFlagOfEquip(DT_EQUIP_DATA_CLI &stEquipInfo); // ��ȡװ���Ŀɿ����ʶ

    // ��ȡĳ��װ���Ŀ���������Ϣ     
	UINT16 GetOpenLightPropInfo(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, 
								DT_EQUIP_DATA_CLI& stAfterOpenLightInfo, UINT16& wOpenLightGoodsID,
								UINT16& wNeedOpenLightGoodsNum, UINT16& wOpenLightGoodsNum,
								UINT8& byOpenLightRate, UINT32& dwOpenLightGold,
								DT_BATTLE_ATTRIBUTE& stOldEquipInitBatlAttr, DT_BATTLE_ATTRIBUTE& stNewEquipInitBatlAttr,
								DT_BATTLE_ATTRIBUTE& stOldEquipCurrAttr);	

	//װ������			
	UINT16 OpenLight(CPlayer* poPlayer, UINT16 wEquipKindID, UINT16 wIdx, UINT8 byGoldFlag,
										UINT16& wNewEquipKindID, UINT16& wNewIdx, UINT8& byNewOpenLightFlag, 
										UINT16& wOpenLightGoodsID, UINT16& wOpenLightGoodsNum);		

public:
	COpenLightPropMgr();
	virtual ~COpenLightPropMgr();

protected:
	BOOL LoadOpenLightPropFromDB();
    
private:
	COpenLightPropMap m_mapOpenLightPropMap; // ��������
	CRealEquipSet m_setRealEquipSet; // ��װ��SET��
	
};

#endif // 

