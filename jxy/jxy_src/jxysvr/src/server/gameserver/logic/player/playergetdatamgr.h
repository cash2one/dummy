
#ifndef _PLAYERGETDATAMGR_H_
#define _PLAYERGETDATAMGR_H_

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdhashmap.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <logic/base/basedefine.h>
#include <protocol/server/protocligs.h>
#include <net/recharge/rcclient.h>

using namespace SGDP;

#define MAX_PLAYER_GET_DATA_POOL_NUM	100		//ͬʱ�첽ȡ���ݵ��������

struct SGetPlayerDataReq
{
    SGetPlayerDataReq()
    {
        Init();
    }

    void Init()
    {
        memset(this, 0x00, sizeof(SGetPlayerDataReq));
    }

    UINT8		byGetKind;
    UINT32		dwPlayerID;
    UINT32		dwTransID;
    UINT8		byAction;		//GM������������
    UINT32		dwParam1;		//����1�����ڲ�ͬ����
    UINT64		qwParam2;		//����2�����ڲ�ͬ����
    UINT64		qwParam3;		//����3�����ڲ�ͬ����
    union
    {
        TCHAR		szParam[1024];	//����4�����ڲ�ͬ����
        TCHAR		szOrderID[1024];	//����4�����ڲ�ͬ����
        TCHAR		szMsg[1024];		//����4�����ڲ�ͬ����
    };
    UINT32		dwSerialNumber;
	TCHAR		szDesc[1024];		//����4�����ڲ�ͬ����
    CRCClient*  poClinet;           
};


struct SGetPlayerDataAck
{
    SGetPlayerDataAck()
    {
        wErrCode = 0;
        memset(&stDT_PLAYER_DATA, 0, sizeof(stDT_PLAYER_DATA));
    };

    UINT16 wErrCode;
    DT_PLAYER_DATA stDT_PLAYER_DATA;
};


struct SGetPlayerData
{
    SGetPlayerData()
    {
        stGetPlayerDataReq.Init();
    }
    SGetPlayerDataReq stGetPlayerDataReq;
    SGetPlayerDataAck stGetPlayerDataAck;
};

struct SGetPlayerData2
{
    SGetPlayerData2()
    {
        memset( this, 0, sizeof( SGetPlayerData2 ) );
    }
    UINT8		byGetKind;
    UINT32		dwPlayerID1;
    UINT32		dwPlayerID2;
    UINT32		dwTransID;
    UINT32		dwParam1;//����1�����ڲ�ͬ����
    UINT64		qwParam2;//����2�����ڲ�ͬ����
    UINT16		wErrCode;
    DT_PLAYER_DATA stDT_PLAYER_DATA1;
    DT_PLAYER_DATA stDT_PLAYER_DATA2;
};

class CGetPlayerDataMgr
{
public:
    DECLARE_SINGLETON(CGetPlayerDataMgr)

    BOOL Init();


    VOID UnInit();

public:
    VOID	GetPlayerData( UINT32 dwTransID, UINT8 byGetKind, UINT32 dwPlayerID, UINT32 dwParam1 = 0, UINT64 qwParam2 = 0, UINT64 qwParam3 = 0, string strParam = "", UINT8	byAction = 0, UINT32 dwSerialNumber = 0, string strDesc = "",CRCClient* poClinet = NULL);
    //VOID	GetPlayerDataOld( UINT32 dwTransID, UINT8 byGetKind, UINT32 dwPlayerID, UINT32 dwParam1 = 0, UINT64 qwParam2 = 0, string strParam = "", UINT8	byAction = 0, UINT32   dwSerialNumber = 0);
    VOID	OnGetPlayerData(SGetPlayerData* pstGetPlayerData);

    VOID	GetPlayerData2(UINT32 dwTransID, UINT8 byGetKind, UINT32 dwPlayerID1, UINT32 dwPlayerID2, UINT32 dwParam1 = 0, UINT64 qwParam2 = 0 );
    VOID	OnGetPlayerData2(SGetPlayerData2* pstGetPlayerData);

protected:
    CGetPlayerDataMgr();
    ~CGetPlayerDataMgr();


private:
    CSDObjectPool<SGetPlayerData, CSDMutex>		m_oGetPlayerDataPool;
    CSDObjectPool<SGetPlayerData2, CSDMutex>		m_oGetPlayerDataPool2;
};



#endif

