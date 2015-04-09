
#ifndef _DRUGPROPMGR_H_
#define _DRUGPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

//������󳤶�
#define NAME_LEN_MAX	32

//��ҩ����
typedef struct tagDrugProp
{
	UINT8	byLevel;					//��ҩ�ȼ�
	TCHAR	szName[NAME_LEN_MAX];		//��Ʒ����
	UINT8	byCanUseNum;				//����ʹ����Ŀ
	UINT16	wUseCD;					//ʹ�ü��ʱ��
	UINT16	wBaseTalent;				//���ʻ����ӳ�ֵ
	UINT16	wDecTalent;				//ÿ��ʹ��1�����ʼӳɵݼ�ֵ
	UINT16   wDrugItemKindID;			//��Ӧ�ĵ�ҩ��ƷID
}SDrugProp;


typedef std::map<UINT8, SDrugProp> CDrugPropMap; //keyΪLevel
typedef CDrugPropMap::iterator CDrugPropMapItr;

typedef std::map<UINT16, SDrugProp> CItemID2DrugPropMap; //keyΪ��ҩ��ƷID
typedef CItemID2DrugPropMap::iterator CItemID2DrugPropMapItr;


class CDrugPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CDrugPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_DRUG; }

    BOOL Init();

    VOID UnInit();
public:
	SDrugProp* GetDrugProp(UINT8 byLevel);
	UINT16 GetDrugLevel(UINT16 wDrugItemID); //��ȡ��ҩ�ȼ�

	CDrugPropMap & GetDrugPropMap()	{ return m_mapDrugProp;	}

	UINT8	GetDT_MIX_DRUG_LEAVE_BY_INDEX(const UINT8 byIndex);

	BOOL	IsDrugGoods(UINT16 wItemID) { return (m_mapItemID2DrugProp.end() != m_mapItemID2DrugProp.find(wItemID)); }; //�Ƿ�Ϊ��ҩ��Ʒ

	UINT8	GetMaxDrugNum();

public:
    CDrugPropMgr();
    virtual ~CDrugPropMgr();
protected:

	BOOL LoadFromDB();

private:
	CDrugPropMap m_mapDrugProp;
	CItemID2DrugPropMap m_mapItemID2DrugProp;//��ҩ��ƷID map
};

#endif // 
