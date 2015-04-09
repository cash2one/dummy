
#ifndef _GOODSPROPMGR_H_
#define _GOODSPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <protocol/server/protocommondata.h>
#include <logic/base/basepropmgr.h>
#include <logic/base/propcontainer.h>

/// ��Ʒ����������󳤶�
#define NAME_LEN_MAX	32
/// ��Ʒ����������󳤶�
#define INTRODUCTION_LEN_MAX	255


struct tagDT_GOODS_DATA_CLI;
typedef tagDT_GOODS_DATA_CLI DT_GOODS_DATA_CLI;

/**
 * @brief
 */
typedef struct tagGoodsProp
{
    UINT16	wKindID;		///< ��Ʒ����
    TCHAR	szName[NAME_LEN_MAX];		///< ��Ʒ����
    TCHAR	szIntroduction[INTRODUCTION_LEN_MAX];		///< ��Ʒ����
    UINT8	byMainKindID;		///< ��Ʒ������(��+����,+��Ǯ,+����ȷ���)���� EGoodsMainKind
    UINT16	wUseLevel;		///< ʹ�õȼ�Ҫ��
    UINT32	dwBuyCoin;		///< �����Ҽ۸񣬶�ѡһ
    UINT32	dwBuyGold;		///< ����Ԫ���۸񣬶�ѡһ
    UINT32	dwRecoverPrice;	///< ���ռ۸�(���ٷֱ�?����ǿ�����ģ�)
    //UINT16	wPileNum;		///< ��������,������������
    UINT16	wUseTimesPerDay;	///< ÿ��ʹ�ô�����0��ʾ������
    UINT16	wUseCD;			///< ʹ��CDʱ��(��λ/��,0��ʾ��CD)
    UINT32	dwValue;			///< ʹ��Ч��ֵ(��+������Ʒ+�ľ���ֵ)

	UINT16	wComposeCount;	//��Ʒ�ϳ���Ҫ����
	UINT16	wComposeKindID;	//��Ʒ�ϳɵ�ID

    UINT8   byComposeItemNum;					//�û����ظ��ͻ��ˣ����Ϻϳɵĵ���/����еĵ���
    UINT16  awComposeItem[MAX_COMPOSE_ITEM_NUM];	//�û����ظ��ͻ��ˣ����Ϻϳɵĵ���/����еĵ���

	UINT32  dwParam1; //���������Ƕ��ʯ����ôwParam1��ʾ��ʯ������. ��ʯ��������Ϊ������������
	UINT32  dwParam2; //�������Ƕ��ʯ�����¼����Ƕ��װ��λ��. ��ʯ��������Ϊ������ȼ�(��Ӧ��ʯ�ȼ�)
	UINT32  dwParam3; //�������Ƕ��ʯ�����¼����Ƕ��װ��λ��. ��ʯ��������Ϊת��������
	UINT32  dwParam4; //�������Ƕ��ʯ�����¼��ת��������ֵ
} SGoodsProp;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CGoodsPropMgr : public CPropContainer<SGoodsProp, UINT16, TCHAR> , CBasePopMgr
{
public:
    typedef std::map<UINT16, SGoodsProp> CGoodsPropPriMap;
    typedef std::map<UINT16, SGoodsProp>::iterator CGoodsPropPriMapItr;

    DECLARE_SINGLETON_PROPMGR(CGoodsPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_GOODS ; }

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
     * @brief ��ȡ������ӳ��
     * @return ������ӳ�����ָ��
     */
    CGoodsPropPriMap* GetPropPriMap();

	VOID FillGoodsData( SGoodsProp *pProp, DT_GOODS_DATA_CLI& data, UINT16 wPileCount );

	SGoodsProp* GetGemMakerProp(UINT16 wGemMakerLevel);

public:
    CGoodsPropMgr();
    virtual ~CGoodsPropMgr();

protected:

    /**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
    BOOL LoadFromDB();

private:
	CGoodsPropPriMap m_mapGemMakerProp;//keyΪ��ʯ������ȼ�(��Ӧ��ʯ�ȼ�)

};

#endif // #ifndef _GOODSPROPMGR_H_
