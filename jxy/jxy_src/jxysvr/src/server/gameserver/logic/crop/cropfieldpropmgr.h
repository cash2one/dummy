
#ifndef _CROPFIELDMGRPROP_H_
#define _CROPFIELDMGRPROP_H_


#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>

//������󳤶�
#define NAME_LEN_MAX	32

//��ҩ����
typedef struct tagCropFieldProp
{
	UINT16	wKindID;					//��ҩ�ȼ�
	TCHAR	szName[NAME_LEN_MAX];		//��Ʒ����
	UINT8	byLevel;					//����ʹ����Ŀ
	UINT32	dwGold;					//ʹ�ü��ʱ��
	UINT32	dwCoin;					//���ʻ����ӳ�ֵ
}SCropFieldProp;


typedef std::map<UINT16, SCropFieldProp> CCropFieldPropMap; //keyΪLevel
typedef CCropFieldPropMap::iterator CCropFieldPropMapItr;


class CCropFieldPropMgr
{
public:
	DECLARE_SINGLETON(CCropFieldPropMgr);

public:

	BOOL Init();

	VOID UnInit();
public:
	CCropFieldPropMap & GetCropFieldPropMap()	
	{ 
		return m_mapCropFieldProp;	
	}

	SCropFieldProp * GetCropFieldProp(UINT16 wFieldID)
	{
		CCropFieldPropMapItr itr = m_mapCropFieldProp.find(wFieldID);
		if (itr != m_mapCropFieldProp.end())
		{
			return &itr->second;
		}
		return NULL;
	}
protected:
	CCropFieldPropMgr();
	virtual ~CCropFieldPropMgr();
protected:

	BOOL LoadFromDB();

private:
	CCropFieldPropMap m_mapCropFieldProp;

};




#endif //#ifndef _ROLEMGR_H_

