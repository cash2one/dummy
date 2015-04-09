#ifndef _SCIENCE_UPDATE_PROP_MGR_H_
#define _SCIENCE_UPDATE_PROP_MGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <logic/base/basepropmgr.h>

using namespace std;
using namespace SGDP;

typedef struct tagScienceUpdateData
{
	UINT16 wLevel; //��ǰ�ȼ�
	UINT32 dwCost; //��������ǰ
	UINT32 dwAddValue; //���ӵ�����
	UINT16 wNeedPlayerLevel; //��Ҫ��ҵļ���
} SScienceUpdateData;

typedef struct tagScienceData
{
	vector<SScienceUpdateData> vecScienceUpdateData;
	UINT16 wVisibleLevel; //�ɼ��ļ���,δ�ﵽ����������Ƽ�
	UINT16 wUnlockLevel;  //�����ļ���δ�ﵽ���ܵ�����
} SScienceData;

class CScienceUpdatePropMgr : public CBasePopMgr
{
public:
	//��ÿƼ�����Ϣ
	enum EGetScienceInfoError
	{ 
		GUIE_SUCCESS=0,
		GUIE_AT_MAXMIUM_LEVEL, //�ﵽ���õ����ֵ,û��������Ϣ
		GUIE_CANNOT_FIND_SCIENCE, //�޷��ҵ�ָ���Ƽ�
	};
	DECLARE_SINGLETON_PROPMGR( CScienceUpdatePropMgr );

	virtual EConfigModule	GetConfigModuleType() { return ECM_SCIENCE_UPDATE ; }

public:
	typedef HashMap< UINT8, tagScienceData > CSciencePropMap; //keyΪ�Ƽ����ԣ�valueΪʵ�����ĵ�����

public:
	CScienceUpdatePropMgr();
	~CScienceUpdatePropMgr();
	BOOL Init();
	VOID UnInit();
	EGetScienceInfoError GetInfo( UINT8 byKind, UINT16 wLevel, UINT32 &wCostVaue, UINT32 &wAddValue ); //����������˼������ĺ����ӵ�ֵ
	EGetScienceInfoError GetInfo( UINT8 byKind, UINT16 wLevel, UINT32 &wCostVaue, UINT32 &wAddValue, UINT16 &wUnlockLevel );
	EGetScienceInfoError GetUnlockInfo( UINT8 byKind, UINT16 wLevel, BOOL &bVisible, BOOL &bUnlock ); //��ô������͵��Ƿ�ɼ����߽���
	INT32 GetKindCount(); //��ÿƼ�����������
	INT32 GetUpdateNeedLevel( UINT8 byKind, UINT16 wSicenceLevel ); //���������Ҫ�ĵȼ�

	vector<UINT8> GetSortScienceKindList(); //��ð�����˳��ĿƼ��б�

	//����wUpdateScienceLevelΪ�����ĿƼ���Ϣ
	BOOL IsCanUpdateAttr( UINT64 qwCurStory, UINT16 wUpdateScienceLevel, UINT16 wPlayerLevel );
	BOOL IsCanUpdateAttr( UINT64 qwCurStory, UINT16 wUpdateScienceLevel, UINT16 wPlayerLevel, UINT8 byType );

	//���ĳһ��������ĿƼ��б�
	vector<UINT8> GetUnlockKindListAtLevel( UINT16 wPlayerLevel );

	//������Ե���󼶱�
	UINT16 GetMaxLevel( UINT8 byKind );
private:
	/**
     * @brief ������Դ��ȡ��������
     * @return ִ�н�����ɹ�����TRUE��ʧ�ܷ���FALSE
     */
	BOOL LoadFromDBEx();

	VOID LogAllKind(); //������еĿƼ�����

	static bool SortByUnlockLevel( UINT8 kind1, UINT8 kind2 );
private:
	CSciencePropMap m_mapUpdateProp; //������������
	vector<UINT8> m_vecSortScienceList; //�Ƽ��б�(��������˳��)
};

#endif