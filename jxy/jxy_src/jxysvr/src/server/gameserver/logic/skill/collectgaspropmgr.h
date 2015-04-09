
#ifndef _COLLECTGASPROPMGR_H_
#define _COLLECTGASPROPMGR_H_

#include <sddb.h>
#include <sdsingleton.h>
#include <sdtype.h>
#include <sdhashmap.h>
#include <logic/base/basepropmgr.h>
#include <common/client/commondef.h>
#include <common/server/utility.h>
#include <map>
#include <vector>

using namespace std;

/// ��������������󳤶�
#define NAME_LEN_MAX	32
/// ���ܽ���������󳤶�
#define INTRODUCTION_LEN_MAX	255





//���ɻ�ȡ�ľ�������
struct SGenGasProp
{
    UINT8		byGasType;		//��������
    UINT8		byLevel;			//�����ȼ�
	UINT32		dwValue;			//������ֵ
    UINT8		byCoinRate;		//���ɸ���
	UINT8		byGoldRate;		//���ɸ���
};

//���������ȼ�����
struct SUpGasLevelProp
{
    UINT8		byType;		//��������
    UINT8		byIncLevel;	//�����ȼ�
    UINT8		byRate;		//����
};

//���������ȼ�����
struct SGasNumProp
{
	UINT8		byVipLevel;		//VIP�ȼ�
	UINT8		byLevel;			//�ȼ�
	UINT8		byTownIdx;		//����ID
	UINT8		byInstanceIdx;	//����ID
	UINT8		byValue;			//����
};



//���������ȼ�����ͭ��
typedef map<UINT16, UINT32> CUpGasLevelCostCoinMap; //��˳��map��keyΪʹ�ô����� valueΪʹ��ͭ��
typedef CUpGasLevelCostCoinMap::iterator CUpGasLevelCostCoinMapItr;


//���������ȼ�����ͭ��
typedef vector<SGasNumProp> CGasNumPropVector;
typedef CGasNumPropVector::iterator CGasNumPropVectorItr;


class CPlayer;

/**
 * @brief ���Թ�����
 *
 * ������ص��������ԣ��̳���CPropContainer\n
 * �ṩ�˸���ID�����Ʋ������ԵĹ���\n
 */
class CCollectGasPropMgr : public CBasePopMgr
{
public:
    DECLARE_SINGLETON_PROPMGR(CCollectGasPropMgr);

public:
    virtual EConfigModule	GetConfigModuleType()
    {
        return ECM_COLLECTGAS ;
    }
    BOOL Init();
    VOID UnInit();
public:
	UINT32	GetGas(CPlayer *poPlayer, UINT8 byGasType, UINT8 byLevel);
    VOID		GenGas(CPlayer *poPlayer, UINT8 byFlag, DT_GAS_BALL_DATA& stDT_GAS_BALL_DATA);
    VOID		UpGasBallLevel(CPlayer *poPlayer, UINT8 byFullLevelFlag, DT_GAS_BALL_DATA &stDT_GAS_BALL_DATA);
    UINT32	GetGuidePurpleGas(CPlayer *poPlayer);

	//��þ����Ĵ���
	UINT32 GetGenGasNum(UINT8 byVipLevel, UINT8 byLevel, UINT8 byTownIdx, UINT8 byInstanceIdx);
	
	SGasNumProp * GetNextGenGasNumProp(UINT8 byVipLevel, UINT8 byLevel, UINT8 byTownIdx, UINT8 byInstanceIdx);


public:
    CCollectGasPropMgr();
    virtual ~CCollectGasPropMgr();

protected:
    BOOL LoadGenGasPropFromDB();
	BOOL LoadGenGasNumPropFromDB();
    BOOL LoadUpGasLevelRatePropFromDB();

private:
    /////////////////////////////////////////
    vector<SGenGasProp>			m_vecGenGasProp;					//����������
    CRandomVec					m_vecCoinGenGasPropRandom;			//���ɾ������� ����vec
	CRandomVec					m_vecGoldGenGasPropRandom;			//���ɾ������� ����vec
    HashMap<UINT16, SGenGasProp>	m_mapGenGasProp;					//���ɾ�������
    vector<SUpGasLevelProp>		m_vecUpBlueGasLevelProp;			//���������ȼ�����
    CRandomVec					m_vecUpBlueGasLevelPropRandom;		//���������ȼ����� ����vec
    vector<SUpGasLevelProp>		m_vecUpPurpleGasLevelProp;			//���������ȼ�����
    CRandomVec					m_vecUpPurpleGasLevelPropRandom;	//���������ȼ����� ����vec
    UINT8						m_byGasBallLevelNum;				//������ȼ���

	CGasNumPropVector				m_vectorGasNumProp;
};

#endif // #ifndef _SKILLPROPMGR_H_
