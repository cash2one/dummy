
#ifndef _AWAKENBASEPROPPROPMGR_H_2
#define _AWAKENBASEPROPPROPMGR_H_2

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <common/server/utility.h>
#include <common/client/commondef.h>
#include <logic/base/basepropmgr.h>
#include <logic/base/basedefine.h>
#include <protocommondata.h>
#include <set>
using namespace SGDP;
using namespace std;


#define GOLD_RUDING_PROP		110		//����ȼ�����Ԫ������붨״̬����
#define GOLD_CHEWU_PROP			111		//����ȼ�����Ԫ���������״̬����

typedef set<UINT16> CSetResolveItemID;
typedef CSetResolveItemID::iterator CSetResolveItemIDItr;
//��������
struct SAwakenBaseProp2
{
	UINT32	dwGoldAwaken; //Ԫ����������붨״̬����Ԫ��
	UINT32	dwGenStudyCoin; //����ĵû��ͭǮʱ��ͭǮ
	UINT32	dwGenStudyClip;	//����ĵû���ĵ���Ƭʱ���ĵ���Ƭ
	UINT16	wGenStudyClipLevel;	// ����ĵ���Ƭ������ҵȼ�
	UINT8	byMaxStudyLevel; //�ĵ����ȼ�
	UINT8	byCallStudyColorKind;	// �ٻ������ĵõ���ɫ����
	UINT8	byCallStudyAttrKind1;	// �ٻ������ĵõ���������1
	UINT8	byCallStudyAttrKind2;	// �ٻ������ĵõ���������2
	UINT8	byCallStudyLevel;		// �ٻ������ĵõĵȼ�
};

//����ȼ�����
struct SAwakenLevelProp2
{
	UINT16	wStartPlayerLevel;		// �����ʼ�ȼ�
	UINT8	byAwakenLevel;			// �򵽵���(��1��ʼ����5��(�˯/����/ڤ˼/�붨/����), (������110ΪԪ������붨״̬���ã�111Ϊ����)
	UINT32	dwNeedCoin;				// �������ͭ��
	UINT8	byNextLevelRate;		// ������һ������(ʧ���򷵻ص�һ��)
	UINT8	byCoinRate;				// ͭǮ����
	UINT8	byClipRate;				// ��Ƭ����
	UINT8	byBuleStudyRate;		// ��ɫ�ĵ���Ƭ����
	UINT8	byPurpleStudyRate;		// ��ɫ�ĵ���Ƭ����
	UINT8	byRedStudyRate;			// ��ɫ�ĵ���Ƭ����
	UINT8	byOrangeStudyRate;		// ��ɫ�ĵ���Ƭ����

	CRandomVec vecRandom; //�ĵø���,����ɫ����˳��
};


//�ĵ����ɸ��ʼ���������(�õȼ������ʾ�ѽ���)
struct SAwakenStudyGenUnlockProp2
{
	UINT16	wPlayerLevel;				// ��ҵȼ�
	UINT8	byStudyColorKind;			// �ĵ���ɫ����
	UINT8	byStudyAttrKind1;			// �ĵ���������1
	UINT8	byStudyAttrKind2;			// �ĵ���������2
	UINT8	byGenRate;					// ���ɸ���
};
typedef vector<SAwakenStudyGenUnlockProp2> CAwakenStudyGenUnlockPropVec2; 
//���ÿ�ȼ��ĵ����ɸ��ʼ���������
struct  SPlayerAwakenStudyGenUnlockProp2
{
	UINT16 wPlayerLevel;
	CAwakenStudyGenUnlockPropVec2 avecAwakenStudyGenUnlockProp[EC_ORANGE+1]; //4����ɫ������,�±�Ϊ��ɫ
	CRandomVec avecRandom[EC_ORANGE+1]; //4����ɫ���ɸ��ʣ���vecAwakenStudyGenUnlockProp����˳��
};
//�ĵ����ɸ��ʼ���������(�õȼ��е��ĵ����ʾ�ѽ���)
typedef HashMap<UINT16, SPlayerAwakenStudyGenUnlockProp2> CLevel2UnlockStudyColorProMap2; //keyΪ��ҵȼ�wStartPlayerLevel
typedef CLevel2UnlockStudyColorProMap2::iterator CLevel2UnlockStudyColorProMapItr2;


//�ĵ���������
struct SAwakenStudyAttrProp2
{
	UINT8	byStudyColorKind;			// �ĵ���ɫ����
	UINT8	byStudyAttrKind1;			// �ĵ���������1
	UINT8	byStudyAttrKind2;			// �ĵ���������2
	UINT8	byStudyLevel;				// �ĵõȼ�
	UINT32	dwAttrValue1;				// �ĵ�����ֵ1	
	UINT32	dwAttrValue2;				// �ĵ�����ֵ2	
	UINT32	dwHaveExp;					// ӵ�еľ���
};
typedef HashMap<UINT32, SAwakenStudyAttrProp2> CAwakenStudyAttrPropMap2; //keyΪbyStudyColorKind+byStudyAttrKind1/2+byStudyLevel
typedef CAwakenStudyAttrPropMap2::iterator CAwakenStudyAttrPropMapItr2;


//�ĵ���Ƭ�һ��ĵ�����
struct SAwakenClipToStudyProp2
{
	UINT8	byStudyColorKind;			// �ĵ���ɫ����
	UINT8	byStudyAttrKind1;			// �ĵ���������1
	UINT8	byStudyAttrKind2;			// �ĵ���������2
	UINT8	byStudyLevel;				// �ĵõȼ�
	UINT32	dwNeedCoin;					// ����ͭǮ
	UINT32	dwNeedClip;					// ������Ƭ
	UINT16	wNeedPlayerLevel;			// ������ҵȼ�
};
typedef HashMap<UINT32, SAwakenClipToStudyProp2> CAwakenClipToStudyPropMap2; //keyΪbyStudyColorKind+byStudyAttrKind1/2+byStudyLevel
typedef CAwakenClipToStudyPropMap2::iterator CAwakenClipToStudyPropMapItr2;
typedef vector<SAwakenClipToStudyProp2>CAwakenClipToStudyPropVec2;//

struct SPlayerAwakenLevelProp2
{
	SAwakenLevelProp2		m_astAwakenLevelProp[MAX_AWAKEN_LEVEL+1];//����ȼ����ã��±�Ϊ����ȼ�
	SAwakenLevelProp2		m_stRudingGoldAwakenLevelProp; //Ԫ������붨״̬�������
	SAwakenLevelProp2		m_stChewuGoldAwakenLevelProp;	//Ԫ���������״̬�������
};

typedef map<UINT16, SPlayerAwakenLevelProp2> CPlayerAwakenLevelPropMap2; //keyΪ�����ʼ�ȼ�wStartPlayerLeve
typedef CPlayerAwakenLevelPropMap2::iterator CPlayerAwakenLevelPropMapItr2;

//�ֽ���Ƭ����
struct  SAwakenResolveProp
{
    UINT8   byStudyColorKind;        //��ɫ���� ˫���Զ�Ӧ����Ϊ8
    UINT8   byIfResolve;             //�Ƿ���Էֽ�
    UINT16  wCommonNum;              //��ͨ�ֽ�ɵ���Ƭ����
    UINT16  wSpecialNum;             //Ԫ���ֽ�ɵ���Ƭ����
    UINT32  dwCommonCoin;            //��ͨ�ֽ����ĵ�ͭǮ
    UINT32  dwSpecialGold;           //Ԫ���ֽ����ĵ�ͭǮ
};

typedef map<UINT8, SAwakenResolveProp> CAwakenResolvePropMap;
typedef CAwakenResolvePropMap::iterator CAwakenResolvePropMapItr;


class CAwakenPropMgr2 : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CAwakenPropMgr2);

public:
	virtual EConfigModule	GetConfigModuleType() { return ECM_AWAKEN2 ; }

    BOOL Init();

    VOID UnInit();

public:	
	SAwakenBaseProp2& GetAwakenBaseProp() { return m_stAwakenBaseProp; }
	//////////////////////////
	inline	UINT32 GetAwakenGold() { return m_stAwakenBaseProp.dwGoldAwaken; }
	inline VOID	GetwLevelStudyUnlockLevelInfo(UINT16 awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]) { memcpy(awStudyUnlockLevelInfo, m_awStudyUnlockLevelInfo, sizeof(m_awStudyUnlockLevelInfo)); }
	inline UINT16 GetMaxStudyLevel() { return m_stAwakenBaseProp.byMaxStudyLevel; }
	//////////////////////////
	UINT32	GetAwakenCoin(UINT16 wPlayerLevel, UINT8 byGoldFlag, UINT8 byAwakenLevel);
	VOID	GetAwakenCoin(UINT32 adwAwakenCoin[MAX_AWAKEN_NUM]) { memcpy(adwAwakenCoin, m_adwAwakenCoin, sizeof(m_adwAwakenCoin)); }
	UINT8	AwakenStudy(UINT16 wPlayerLevel, BOOL bOpenExpStudy, UINT8 byAwakenLevel, UINT8 byGoldFlag, UINT8& byStudyColorKind, UINT8& byStudyAttrKind1, UINT8& byStudyAttrKind2, 
		UINT32& dwGenCoin, UINT32& dwGenClip, UINT8& byZTSUseTime);
	UINT32	GetStudyExp(UINT8 byStudyColorKind, UINT8 byStudyAttrKind1, UINT8 byStudyAttrKind2, UINT8 byStudyLevel);
	UINT32	GetStudyUpgradeNeedExp(UINT8 byStudyColorKind, UINT8 byStudyAttrKind1, UINT8 byStudyAttrKind2, UINT8 byStudyCurLevel);
	BOOL	CkUnlockHeroGrid(UINT16 wHeroLevel, UINT8 byGridIdx);
	VOID	GetStudyAttrValue(UINT8 byStudyColorKind, UINT8 byStudyAttrKind1, UINT8 byStudyAttrKind2, UINT8 byStudyLevel, UINT32& dwAttrValue1, UINT32& dwAttrValue2);
	CAwakenClipToStudyPropVec2& GetAwakenClipToStudyPropVec() { return m_vecAwakenClipToStudyProp; }
	SAwakenClipToStudyProp2* GetClipToStudyProp(UINT8 byStudyColorKind, UINT8 byStudyAttrKind1, UINT8 byStudyAttrKind2, UINT8 byStudyLevel);
	CSetResolveItemID& GetResolveItemID() { return m_setResolveItemID; }
	UINT8 GetRandomCliByItemID(UINT16 wItemID);
    CAwakenResolvePropMap& GetAwakenResolveProp(){return m_mapResolveProp;}
    SAwakenResolveProp* GetAwakenResolvePropByID(UINT8 byStudyColorKind);
    UINT8 GetAwakenIfResolveByID(UINT8 byStudyColorKind);
public:
    CAwakenPropMgr2();
    virtual ~CAwakenPropMgr2();

protected:
	BOOL LoadBaseFromDB();
	BOOL LoadAwakenLevelFromDB();
	BOOL LoadUnlockHeroStudyGridFromDB();
	BOOL LoadLevel2UnlockAwakenStudyFromDB();
	BOOL LoadAwakenStudyAttrFromDB();
	BOOL LoadAwakenClipToStudyFromDB();
    BOOL LoadAwakenResolvePropFromDB();

private:
	SAwakenBaseProp2			m_stAwakenBaseProp; //��������
	CPlayerAwakenLevelPropMap2	m_mapPlayerAwakenLevelProp;//�������
	UINT32					m_adwAwakenCoin[MAX_AWAKEN_NUM];//�������ͭǮ
	C1616Map				m_mapLevel2OpenNumProp; //keyΪ���ȼ���valueΪ���ŵ��ĵø�����
	C1616Map				m_mapOpenNum2LevelProp; //keyΪ���ŵ��ĵø�����, valueΪ�����Ļ��ȼ�
	UINT16					m_awStudyUnlockLevelInfo[MAX_HERO_STUDY_GRID_NUM]; //�ĵý����ȼ���Ϣ
	UINT16					m_wMaxOpenNumHeroLevel;//��󿪷��ĵø��������佫�ȼ�
	CLevel2UnlockStudyColorProMap2 m_mapLevel2AwakenStudyGenUnlockPropMap; //�ĵ����ɸ��ʼ��������ã�keyΪ��ҵȼ�(�õȼ��е��ĵ����ʾ�ѽ���)
	CAwakenStudyAttrPropMap2	m_mapAwakenStudyAttrProp; //�ĵ��������ã�keyΪbyStudyColorKind+byStudyAttrKind+byStudyLevel
	CAwakenClipToStudyPropMap2	m_mapAwakenClipToStudyProp;//��Ƭ�һ��ĵ�����
	CAwakenClipToStudyPropVec2	m_vecAwakenClipToStudyProp;//��Ƭ�һ��ĵ�����
	CSetResolveItemID       m_setResolveItemID;
	CAwakenStudyAttrPropMap2   m_mapResolveOrangeProp;
    CAwakenResolvePropMap    m_mapResolveProp;
};

#endif // #ifndef _AWAKENBASEPROPPROPMGR_H_