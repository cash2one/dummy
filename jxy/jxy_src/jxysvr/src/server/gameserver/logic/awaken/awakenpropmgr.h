
#ifndef _AWAKENBASEPROPPROPMGR_H_
#define _AWAKENBASEPROPPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>

using namespace SGDP;


#define GOLD_RUDING_PROP		110		//����ȼ�����Ԫ������붨״̬����
#define GOLD_CHEWU_PROP			111		//����ȼ�����Ԫ���������״̬����


//��������
struct SAwakenBaseProp
{
	UINT32	dwGoldAwaken; //Ԫ����������붨״̬����Ԫ��
	UINT32	dwGenStudyCoin; //����ĵû��ͭǮʱ��ͭǮ
	UINT8	byMaxStudyLevel; //�ĵ����ȼ�
};

//����ȼ�����
struct SAwakenLevelProp
{
	UINT8	byAwakenLevel;			// �򵽵���(��1��ʼ����5��(�˯/����/ڤ˼/�붨/����), (������110ΪԪ������붨״̬���ã�111Ϊ����)
	UINT32	dwNeedCoin;				// �������ͭ��
	UINT8	byNextLevelRate;		// ������һ������(ʧ���򷵻ص�һ��)
	UINT8	byCoinRate;				// ͭǮ����
	UINT8	byBuleStudyRate;		// ��ɫ�ĵ���Ƭ����
	UINT8	byPurpleStudyRate;		// ��ɫ�ĵ���Ƭ����
	UINT8	byRedStudyRate;			// ��ɫ�ĵ���Ƭ����
	UINT8	byOrangeStudyRate;		// ��ɫ�ĵ���Ƭ����

	CRandomVec vecRandom; //�ĵø���,����ɫ����˳��
};


//�ĵ����ɸ��ʼ���������(�õȼ������ʾ�ѽ���)
struct SAwakenStudyGenUnlockProp
{
	UINT16	wPlayerLevel;				// ��ҵȼ�
	UINT8	byStudyColorKind;			// �ĵ���ɫ����
	UINT8	byStudyAttrKind;			// �ĵ���������
	UINT8	byGenRate;					// ���ɸ���
};
typedef vector<SAwakenStudyGenUnlockProp> CAwakenStudyGenUnlockPropVec; 
//���ÿ�ȼ��ĵ����ɸ��ʼ���������
struct  SPlayerAwakenStudyGenUnlockProp
{
	UINT16 wPlayerLevel;
	CAwakenStudyGenUnlockPropVec avecAwakenStudyGenUnlockProp[EC_ORANGE+1]; //4����ɫ������,�±�Ϊ��ɫ
	CRandomVec avecRandom[EC_ORANGE+1]; //4����ɫ���ɸ��ʣ���vecAwakenStudyGenUnlockProp����˳��
};
//�ĵ����ɸ��ʼ���������(�õȼ��е��ĵ����ʾ�ѽ���)
typedef HashMap<UINT16, SPlayerAwakenStudyGenUnlockProp> CLevel2UnlockStudyColorProMap; //keyΪ��ҵȼ�wPlayerLevel
typedef CLevel2UnlockStudyColorProMap::iterator CLevel2UnlockStudyColorProMapItr;


//�ĵ���������
struct SAwakenStudyAttrProp
{
	UINT8	byStudyColorKind;			// �ĵ���ɫ����
	UINT8	byStudyAttrKind;			// �ĵ���������
	UINT8	byStudyLevel;				// �ĵõȼ�
	UINT32	dwAttrValue;				// �ĵ�����ֵ	
	UINT32	dwHaveExp;					// ӵ�еľ���
};
typedef HashMap<UINT32, SAwakenStudyAttrProp> CAwakenStudyAttrPropMap; //keyΪbyStudyColorKind+byStudyAttrKind+byStudyLevel
typedef CAwakenStudyAttrPropMap::iterator CAwakenStudyAttrPropMapItr;



class CAwakenPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CAwakenPropMgr);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_AWAKEN ; }

    BOOL Init();

    VOID UnInit();

public:	
	inline	UINT32 GetAwakenGold() { return m_stAwakenBaseProp.dwGoldAwaken; }
	inline VOID	GetwLevelStudyUnlockLevelInfo(UINT16 awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]) { memcpy(awStudyUnlockLevelInfo, m_awStudyUnlockLevelInfo, sizeof(m_awStudyUnlockLevelInfo)); }
	inline UINT16 GetMaxStudyLevel() { return m_stAwakenBaseProp.byMaxStudyLevel; }
	//////////////////////////
	UINT32	GetAwakenCoin(UINT8 byGoldFlag, UINT8 byAwakenLevel);
	VOID	GetAwakenCoin(UINT32 adwAwakenCoin[MAX_AWAKEN_NUM]) { memcpy(adwAwakenCoin, m_adwAwakenCoin, sizeof(m_adwAwakenCoin)); }
	UINT8	AwakenStudy(UINT16 wPlayerLevel, UINT8 byAwakenLevel, UINT8 byGoldFlag, UINT8& byStudyColorKind, UINT8& byStudyAttrKind, UINT32& dwGenCoin);
	UINT32	GetStudyExp(UINT8 byStudyColorKind, UINT8 byStudyAttrKind, UINT8 byStudyLevel);
	UINT32	GetStudyUpgradeNeedExp(UINT8 byStudyColorKind, UINT8 byStudyAttrKind, UINT8 byStudyCurLevel);
	BOOL	CkUnlockHeroGrid(UINT16 wHeroLevel, UINT8 byGridIdx);
	UINT32	GetStudyAttrValue(UINT8 byStudyColorKind, UINT8 byStudyAttrKind, UINT8 byStudyLevel);
	
public:
    CAwakenPropMgr();
    virtual ~CAwakenPropMgr();

protected:
	BOOL LoadBaseFromDB();
	BOOL LoadAwakenLevelFromDB();
	BOOL LoadUnlockHeroStudyGridFromDB();
	BOOL LoadLevel2UnlockAwakenStudyFromDB();
	BOOL LoadAwakenStudyAttrFromDB();

private:
	SAwakenBaseProp			m_stAwakenBaseProp; //��������
	SAwakenLevelProp		m_astAwakenLevelProp[MAX_AWAKEN_LEVEL+1];//����ȼ����ã��±�Ϊ����ȼ�
	SAwakenLevelProp		m_stRudingGoldAwakenLevelProp; //Ԫ������붨״̬�������
	SAwakenLevelProp		m_stChewuGoldAwakenLevelProp; //Ԫ���������״̬�������
	UINT32					m_adwAwakenCoin[MAX_AWAKEN_NUM];//�������ͭǮ
	C1616Map				m_mapLevel2OpenNumProp; //keyΪ���ȼ���valueΪ���ŵ��ĵø�����
	C1616Map				m_mapOpenNum2LevelProp; //keyΪ���ŵ��ĵø�����, valueΪ�����Ļ��ȼ�
	UINT16					m_awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵý����ȼ���Ϣ
	UINT16					m_wMaxOpenNumHeroLevel;//��󿪷��ĵø��������佫�ȼ�
	CLevel2UnlockStudyColorProMap m_mapLevel2AwakenStudyGenUnlockPropMap; //�ĵ����ɸ��ʼ��������ã�keyΪ��ҵȼ�(�õȼ��е��ĵ����ʾ�ѽ���)
	CAwakenStudyAttrPropMap	m_mapAwakenStudyAttrProp; //�ĵ��������ã�keyΪbyStudyColorKind+byStudyAttrKind+byStudyLevel
};

#endif // #ifndef _AWAKENBASEPROPPROPMGR_H_