

#ifndef _GETPLAYERDATACMD_H_
#define _GETPLAYERDATACMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playergetdatamgr.h>


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetPlayerDataCMD : public CBaseDBCMD
{
public:
	CGetPlayerDataCMD();
	~CGetPlayerDataCMD();

	/**
	* @brief �첽ִ��SQL����
	* @poDBConn �첽ִ��SQL�����Connection����
	* @return VOID
	*/						
	VOID SDAPI OnExecuteSql(SGDP::ISDDBConnection* poDBConn);

	/**
	* @brief ͬ��ִ��SQL������ص��߼�����
	* @return VOID
	*/
    VOID SDAPI OnExecuted();


	virtual VOID SetUserData(VOID* pUserData);

public:
	virtual EDBCmdType GetDBCmdType() { return EDBCT_GET1 ; }

	static BOOL GetData(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData, DT_PLAYER_PVP_DATA& stPlayerPvpData, UINT16& wErrCode);

	//����з������ݴ������󣬱��ݵ�SQL�ļ�����ִ��SQL���ɹ��򷵻�SUCCESS,���򷵻ؾܾ���¼
	static INT32 CheckAndProcessBackupSql( SGDP::ISDDBConnection *poDBConn, UINT32 dwPlayerID );
protected:


	static BOOL GetPlayerBase(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetPlayerTodayConsume(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetPlayerExt(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetBag(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetBuild(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetHeroBase(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetHeroExt(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetInstance(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetTask(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetPvp(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_PVP_DATA& stPlayerPvpData);
	static BOOL GetRelationData(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetEvenData(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);
	static BOOL GetSendFlowerLog(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA& stPlayerNoPvpData);

private:
	SGetPlayerData* m_pstGetPlayerData;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

