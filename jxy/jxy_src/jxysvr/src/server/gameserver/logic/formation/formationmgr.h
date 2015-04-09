
#ifndef _FORMATIONMGR_H_
#define _FORMATIONMGR_H_

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdmutex.h>
#include <protocol/server/protocommondata.h>

#include "formation.h"

using namespace SGDP;

class CPlayer;

class CFormationMgr
{
public:
    DECLARE_SINGLETON(CFormationMgr)

    BOOL Init();

    VOID UnInit();

public:

	UINT16	Embattle(CPlayer* poPlayer, UINT8 byEmbattleType, UINT8 byFormationIdx, UINT16 wUpHeroKindID, UINT16 wDownHeroKindID);//����

	VOID	GetFormationIdx(CPlayer* poPlayer, DT_FORMATION_DATA_LIST& stDT_FORMATION_DATA_LIST);

	/*bChoice=FALSEΪ��ת��Ϊ�ɰ汾�� TRUEΪ�°汾
	*����stNew
	*���stOld
	*��DT_NEW_FORMATION_DATAת����DT_FORMATION_DATA
	*/
	VOID ConvertFormation(DT_FORMATION_DATA& stOld, DT_NEW_FORMATION_DATA& stNew, CPlayer* poPlayer);
	/*
	*	*����stOld
	*	���stNew
	*	��DT_FORMATION_DATAת����DT_NEW_FORMATION_DATA
	*/
	VOID ConvertOldToNew(DT_NEW_FORMATION_DATA& stNew, DT_FORMATION_DATA& stOld, DT_NEW_FORMATION_DATA& stSource );
	/*
	*����stNew
	*���stOld
	*/
	VOID ConvertFormationIdx(DT_FORMATION_IDX_DATA& stOld, DT_NEW_FORMATION_INFO& stNew);
	
	VOID ConvertIdxDataToInfo(DT_NEW_FORMATION_INFO& stTarget, DT_FORMATION_IDX_DATA& stChange);
	//����TRUEΪʹ���°汾
	BOOL CheckConvertFormation(CPlayer* poPlayer);

	BOOL SetIdxHeroID(DT_NEW_FORMATION_INFO& stNewInfo, UINT16 wHeroID, UINT8 byOldIdx);
	BOOL SetIdxHeroID(DT_FORMATION_IDX_DATA& stOldInfo, DT_NEW_FORMATION_INFO& stNewInfo, UINT16 wHeroID);
protected:
	UINT16 Up(CPlayer* poPlayer, UINT8 byFormationIdx, UINT16 wUpHeroKindID);

	UINT16 Down(CPlayer* poPlayer, UINT16 wUpHeroKindID);

	UINT16 Replace(CPlayer* poPlayer, UINT8 byFormationIdx, UINT16 wUpHeroKindID, UINT16 wDownHeroKindID);

	UINT16 Exchange(CPlayer* poPlayer, UINT8 byFormationIdx, UINT16 wUpHeroKindID, UINT16 wDownHeroKindID);


protected:
    CFormationMgr();
    ~CFormationMgr();


//public:
//    DT_NEW_FORMATION_INFO* CreateFormation();
//    VOID        RemoveFormation(DT_NEW_FORMATION_INFO*);
//
//private:
//    CSDObjectPool<DT_NEW_FORMATION_INFO, CSDMutex>  m_stFormationPool;
};




#endif //#ifndef _ROLEMGR_H_

