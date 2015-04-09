
#ifndef _EXPERIENCEDRUGPROPMGR_H_
#define _EXPERIENCEDRUGPROPMGR_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <logic/base/basepropmgr.h>

//������󳤶�
#define NAME_LEN_MAX	32

//��ҩ����
typedef struct tagExperienceDrugProp
{
    UINT8	byLevel;						//��ҩ�ȼ�
    TCHAR	szName[NAME_LEN_MAX];			//��Ʒ����
    UINT16   wExperienceDrugItemKindID;		//��Ӧ�ĵ�ҩ��ƷID
} SExperienceDrugProp;

typedef std::map<UINT16, SExperienceDrugProp> CExperienceDrugPropMap; //keyΪ��ҩ��ƷID
typedef CExperienceDrugPropMap::iterator CExperienceDrugPropMapItr;
class CExperienceDrugPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CExperienceDrugPropMgr);
public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_EXP_DRUG ; }
    BOOL Init();
    VOID UnInit();
public:
    CExperienceDrugPropMap & GetExperienceDrugPropMap()
    {
        return m_mapExperienceDrugProp;
    }

    //�Ƿ�Ϊ��ҩ��Ʒ
    BOOL	IsExperienceDrugGoods(UINT16 wItemID)
    {
        return (m_mapExperienceDrugProp.end() != m_mapExperienceDrugProp.find(wItemID));
    };

	SExperienceDrugProp * GetExperienceDrugProp(UINT16 wKindID)
	{
		CExperienceDrugPropMapItr itr = m_mapExperienceDrugProp.find(wKindID);
		if (m_mapExperienceDrugProp.end() != itr)
		{
			return &itr->second;
		}
		return NULL;
	}
public:
    CExperienceDrugPropMgr();
    virtual ~CExperienceDrugPropMgr();
protected:
    BOOL LoadFromDB();
private:
    CExperienceDrugPropMap			m_mapExperienceDrugProp;//��ҩ��ƷID map
};

#endif // 
