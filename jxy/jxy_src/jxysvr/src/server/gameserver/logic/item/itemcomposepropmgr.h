
#ifndef _ITEMCOMPOSEPROPMGR_H
#define _ITEMCOMPOSEPROPMGR_H

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basedefine.h>
#include <logic/base/basepropmgr.h>
#include <logic/item/equip/equippropmgr.h>

using namespace std;
using namespace SGDP;

typedef struct tagItemComposeProp
{
    UINT16			wKindID;				///< ��������
    CItemRateMap		mapComposeItem;		///< ��ϵĵ���(�����Ϊ�򿪱���ĵ���)
} SItemComposeProp;

struct SComposeEquipProp
{
    UINT16	wEquipLevel;		//װ���ȼ�
    UINT16	wClipItemID;		//��Ƭ��ƷID
    UINT16	wNeedClipNum;		//�ϳ�������Ƭ��
    UINT32	dwCommonComposeGold;//��ͨ�ϳ�����Ԫ��
    UINT32	dwPurpleComposeGold;//��ɫ�ϳ�����Ԫ��
    UINT32	dwRedComposeGold;	//��ɫ�ϳ�����Ԫ��
    UINT32	dwOrangeComposeGold;//��ɫ�ϳ�����Ԫ��
    UINT16	wBlueRate;			//��ɫ����
    UINT16	wPurpleRate;		//��ɫ����
    UINT16	wRedRate;			//��ɫ����
    UINT16	wOrageRate;			//��ɫ����
    UINT16	wEquipComposeCD;	//װ���ϳ�CD
};

typedef map<UINT16, SComposeEquipProp> CComposeEquipPropMap; //keyΪwEquipLevel
typedef CComposeEquipPropMap::iterator CComposeEquipPropMapItr;

typedef vector<SEquipProp> CEquipPropVec;
typedef CEquipPropVec::iterator CEquipPropVecItr;
typedef map<UINT8, CEquipPropVec> CColor2EquipPropVecMap;//keyΪװ����ɫ
typedef CColor2EquipPropVecMap::iterator CColor2EquipPropVecMapItr;
typedef map<UINT16, CColor2EquipPropVecMap> CLevel2Color2EquipPropVecMap; //keyΪװ���ȼ�
typedef CLevel2Color2EquipPropVecMap::iterator CLevel2Color2EquipPropVecMapItr;


class CPlayer;
class CItemComposePropMgr : public CBasePopMgr
{
public:
    typedef HashMap<UINT16, SItemComposeProp*> CItemComposePropMap;		//keyΪwKindID
    typedef CItemComposePropMap::iterator CItemComposePropMapItr;

    DECLARE_SINGLETON_PROPMGR(CItemComposePropMgr);

public:
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_ITEM_COMPOSE ;
    }

    /**
     * @brief ��ʼ�����Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL Init();

    /**
     * @brief �������Թ�����
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    VOID UnInit();

    /**
    * @brief ��������
    * @return ����
    */
    SItemComposeProp* GetProp(UINT16 wKindID);
    BOOL GetDT_NEED_ITEM_DATA(CPlayer* poPlayer, DT_NEED_ITEM_DATA &stDT_NEED_ITEM_DATA, UINT16 wItemKindID, UINT16 wSubKindID);
    UINT16 GetGemMakeOpenNeedTowerNum(UINT16 wGemLevel);
    VOID GetInitDT_GEM_MAKER_DATA(DT_GEM_MAKER_DATA	astDT_GEM_MAKER_DATA[], UINT8 byMaxGemLevel)
    {
        for (UINT8 byNum = 0 ; byNum < m_byMaxGemLevel && byNum < byMaxGemLevel; byNum++)
        {
            memcpy(&astDT_GEM_MAKER_DATA[byNum], &m_astDT_GEM_MAKER_DATA[byNum], sizeof(DT_GEM_MAKER_DATA));
        }
    }
    CComposeEquipPropMap& GetComposeEquipProp()
    {
        return m_mapComposeEquipProp;
    }
    CColor2EquipPropVecMap* GetEquipLevelProp(UINT16 wEquipLevel)
    {
        return &m_mapLevel2Color2EquipPropVec[wEquipLevel];
    }
    UINT32	GetColorComposeNeedGold(UINT16 wEquipLevel, UINT8 byCurLowColor);
    SComposeEquipProp* GetComposeEquipProp(UINT16 wEquipLevel);

	UINT8	GetMaxGemLevel(){return m_byMaxGemLevel;}
public:
    CItemComposePropMgr();
    virtual ~CItemComposePropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    //BOOL LoadFromDB();

    BOOL LoadFromDBEx();

    BOOL LoadGemMakerOpenPropFromDB();

    BOOL LoadComposeEquipPropFromDB();

    //��ʼ����ʯ�ϳ���Ϣ
    BOOL InitGemMakerInfo();

    //��ʼ��������Ե���ϵ���
    VOID InitBoxComposeItem();

    //��ʼ��װ���ϳɵ���
    VOID InitEquipCompose();

private:
    CItemComposePropMap			m_mapItemComposeProp;
    C1616Map						m_mapGemMakerOpenProp;

    UINT8						m_byMaxGemLevel;
    DT_GEM_MAKER_DATA				m_astDT_GEM_MAKER_DATA[MAX_GEM_LEVEL_EX];
    CComposeEquipPropMap			m_mapComposeEquipProp;
    CLevel2Color2EquipPropVecMap	m_mapLevel2Color2EquipPropVec;
};

#endif // #ifndef _EQUIPPROPMGR_H_
