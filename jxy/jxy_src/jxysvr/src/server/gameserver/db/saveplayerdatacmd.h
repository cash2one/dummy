

#ifndef _SAVEPLAYERDATACMD_H_
#define _SAVEPLAYERDATACMD_H_

#include "basedbccmd.h"
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <logic/player/playersavemgr.h>
#include "src/dll/sddb/db_mysqlconn.h"
#include <map>
using namespace std;
using namespace  SGDP;

struct SPlayerSaveInfo
{
    SPlayerSaveInfo()
    {
        poPlayerSaveData = NULL;
        enType = ESDBT_GAME;
        bSaveAll = FALSE;
    }
    CPlayerSaveData *poPlayerSaveData;
    ESaveDBType enType;
    BOOL bSaveAll; //�Ƿ񱣴�ȫ������
};

/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/

class CSavePlayerDataCMD : public CBaseDBCMD
{
public:
    CSavePlayerDataCMD();
    ~CSavePlayerDataCMD();

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
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_SAVE ;
    }

protected:
    ///////////////////////////////////////////////////////////////////////////////////////////////
    BOOL	SaveData(ISDDBConnection* poDBConn);//����
	BOOL	SavePlayerDataSqlByFile(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID);
    BOOL SavePlayerBase(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA* pstPlayerData);
    BOOL SavePlayerTodayConsume(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA* pstPlayerData);

    BOOL SavePlayerExt(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_PLAYER_NOPVP_DATA* pstPlayerData);
    BOOL SaveBag(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_BAG_EQUIP_DATA_LST& stBagEquipData, DT_BAG_GOODS_DATA_LST& stBagGoodsData, DT_BAG_JEWELRY_DATA_LST& stBagJewelryData);
    BOOL SaveBuild(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_BUILD_DATA_LIST& stBuildData);
    BOOL SaveHeroBase(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_HERO_DATA_LIST& stHeroData);
    BOOL SaveHeroExt(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_HERO_DATA_LIST& stHeroData);
    BOOL SaveInstance(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_INSTANCE_DATA_LIST& stInstanceData);
    BOOL SaveTask(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_TASK_DATA_LIST& stTaskData);

    BOOL SaveSendFlowerLog(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_RECV_FLOWER_LOG_LIST &stRecvFlowerLogList);

    BOOL SaveRelationData(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_RELATION_DATA_LIST &stRelationDataList);

	BOOL SaveEvenData(SGDP::ISDDBConnection* poDBConn, UINT32 dwPlayerID, DT_DATA_EVEN_LIST &stDT_DATA_EVEN_LIST);

private:
    //����pszSql�洢�ŷ��ص�sql����,�贫����Ч�ĵ�ַ
    //��Ҫע��bChanged��������ʹ�Ǳ���ȫ�������ݣ�Ҳ�п�����FALSE����Ϊ��Щ������ȷʵ��û�����ݣ����������;�Ӣ��������������û��ս�����ݵ�

    BOOL GetPlayerBaseSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, DT_PLAYER_NOPVP_DATA* pstPlayerData );
    BOOL GetPlayerTodayConsumeSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, DT_PLAYER_NOPVP_DATA* pstPlayerData );
    BOOL GetPlayerExtSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, DT_PLAYER_NOPVP_DATA* pstPlayerData, BOOL &bChanged );
    BOOL GetSaveBagSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_BAG_EQUIP_DATA_LST& stBagEquipData, DT_BAG_GOODS_DATA_LST& stBagGoodsData, DT_BAG_JEWELRY_DATA_LST& stBagJewelryData );
    BOOL GetSaveBuildSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_BUILD_DATA_LIST& stBuildData, BOOL &bChanged , BOOL bGetAll = TRUE);
    BOOL GetSaveHeroBaseSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_HERO_DATA_LIST& stHeroData, BOOL &bChanged, BOOL bGetAll = TRUE );
    BOOL GetSaveHeroExtSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_HERO_DATA_LIST& stHeroData, BOOL &bChanged, BOOL bGetAll = FALSE );//����
    BOOL GetSaveInstanceSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_INSTANCE_DATA_LIST& stInstanceData, BOOL &bChanged, BOOL bGetAll = TRUE );
    BOOL GetSaveTaskSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_TASK_DATA_LIST& stTaskData, BOOL &bChanged, BOOL bGetAll = FALSE );
    BOOL GetSaveSendFlowerLogSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_RECV_FLOWER_LOG_LIST &stRecvFlowerLogList, BOOL &bChanged, BOOL bGetAll = TRUE );
    BOOL GetSaveRelationDataSql1( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_RELATION_DATA_LIST &stRelationDataList, BOOL &bChanged, BOOL bGetAll = TRUE );
	BOOL GetSaveRelationDataSql2( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_RELATION_DATA_LIST &stRelationDataList, BOOL &bChanged, BOOL bGetAll = TRUE );
	BOOL GetSaveEvenDataSql( SGDP::ISDDBConnection* poDBConn, char *pszSql, UINT32 dwPlayerID, DT_DATA_EVEN_LIST &stDT_DATA_EVEN_LIST, BOOL &bChanged, BOOL bGetAll = TRUE );

	BOOL GetPlayerExSqlBySaveLocal( SGDP::ISDDBConnection* poDBConn, char *pszSql, DT_PLAYER_NOPVP_DATA* pstPlayerData);

    //�������SQL���
    vector<string> GetAllSql(SGDP::ISDDBConnection* poDBConn);
	//������б�����ı�SQL���
	vector<string> GetAllSqlBySaveText(SGDP::ISDDBConnection* poDBConn);
private:
    SPlayerSaveInfo	m_oPlayerSaveInfo;
	
};


#endif //#ifndef _GETPLAYERDATACMD_H_

