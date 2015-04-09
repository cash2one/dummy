

#ifndef _SGDP_GAMESERVER_APPLICATION_H_
#define _SGDP_GAMESERVER_APPLICATION_H_

#include "sdframework.h"
#include <net/gt/gtprocessor.h>
#include <net/db/dbprocessor.h>
#include <net/ns/nsprocessor.h>
#include <net/ks/ksprocessor.h>
#include <net/recharge/rechargeclient.h>
#include <net/recharge/rcclient.h>
#include <net/recharge/httppacketparser.h>
#include <common/server/packetparser.h>
#include <list>
#include <db/dbmgr.h>
#include <sdmemorypool.h>
#include "logic/player/playersavemgr.h"
#include "logic/base/basedefine.h"

using namespace std;
using namespace SGDP;

class CGSPipeChannel;

typedef map<UINT16, CSDPipeChannel*> CZoneID2PipeChannelMap;
typedef CZoneID2PipeChannelMap::iterator CZoneID2PipeChannelMapItr;

class CGSApplication : public CSDApplication
{
private:
    // ����Ϸ�������������б�key = ��id�� val = ���������Ϸ�����������ӹܵ�
    typedef std::map<UINT16, CSDPipeChannel*> CZoneID2GSPipeChannelMap;

public:
    CGSApplication();
    virtual ~CGSApplication();

public:
    virtual BOOL        Init(const TCHAR* pszConfigFilename);
    virtual VOID        UnInit();
    virtual BOOL        Run();
    virtual VOID        OnHandleUserCmd(const TCHAR* szCmd);

    virtual CSDPipeChannel* OnPipeChannelConnected(UINT32 dwPipeID);
    virtual VOID        OnPipeChannelDisconnected(CSDPipeChannel* poChannel);

    virtual VOID			UpdateSvrStatus(UINT32 dwID, UINT32 dwIP, BOOL bConnect);

	inline CZoneID2PipeChannelMap&	GetAllGTPipeChannel() { return m_mapGTPipeChannel; } 
	CSDPipeChannel*		GetGTPipeChannel(UINT16 wZoneID);
    CSDPipeChannel*		GetGSPipeChannelByZoneID(UINT16 wZoneID);

    CSDPipeChannel*		GetNSPipeChannel();
    CSDPipeChannel*		GetGSPipeChannel();
	CSDPipeChannel*		GetPKPipeChannel();
	CDBProcessor*		GetDBProcessor() { return &m_oDBProcessor; }


	inline	CDBMgr*					GetDBMgr() { return &m_oDBMgr; }
	inline CRechargeClientMgr*		GetRechargeClientMgr() { return &m_oRechargeClientMgr; }
	inline CRCClientMgr*			GetRCClientMgr() { return &m_oRCClientMgr; }

	////////////////////////////////
	VOID* GetSQLMemory();
	VOID FreeSQL(VOID* p);


	//������Ϣ����
	VOID NoticeMsg(UINT32 dwPlayerID, const CHAR* pBuf);
	VOID NoticeMsg(UINT32 dwPlayerID, UINT8 byAction, const CHAR* szToken, const CHAR* pBuf);
	
	VOID GMMsgResponse(UINT32 dwMsgID, UINT32 dwPlayerID, const CHAR* pBuf);

	UINT64				GetServerStartTime() { return m_qwServerStartTime; }

	CCliPacketParser    &GetPacketParser(){ return m_oCliPacketParser; }
	ISDListener*		GetRechargeListener() { return m_poListener; }	
	BOOL&				GetNeedSave2DB() { return m_bNeedSave2DB; }

    // ��ȡ�������б���������Ϊ���ս������ʱ����Ч
    ZoneIDSet GetZoneList();

    // �ǲ���PK������
    BOOL				IsServerType(eServerType eST);

protected:
	BOOL				InitRecharge();

protected:
	///////////////////GM///////////////////////
	BOOL				DealUserCmd(const TCHAR* szCmd);

private:
    // ֹͣ��Ϸ�������ĸ������񣬱��綨ʱ��д������ݡ���ʱȡ����ȣ��������ǿ��ս������ʱ����Ȼ��������Ϸ���������߼�����ĳЩ��Ϸ�������������ǲ���Ҫִ�еģ�
    VOID				StopGameServerTask();

    // ��ʼ�����ս�������ĸ�����Ϸ�߼�
    BOOL				InitGvGSvrLogic();

    eServerType	GetServerType();

private:
    eServerType					m_eThisServerType; // �������������ͣ���Ϸ������/���ս������

    CGTProcessor				m_oGTProcessor;
	CNSProcessor				m_oNSProcessor;
	CGMProcessor				m_oGMProcessor;
    CDBProcessor				m_oDBProcessor;    

	CZoneID2PipeChannelMap	    m_mapGTPipeChannel;//���е����أ�Ϊ�����������keyΪ��ID
    CZoneID2GSPipeChannelMap    m_mapGSPipeChannel; // ���ӵ�������������Ϸ�������б���������Ϊ���ս������ʱ����Ч��
	CSDPipeChannel*		        m_poNSPipeChannel;
	CSDPipeChannel*		        m_poGMPipeChannel;
	CSDPipeChannel*		        m_poGSPipeChannel;
    CSDPipeChannel*		        m_poPKPipeChannel; // ����ս������������

	CDBMgr				        m_oDBMgr;

	CSDFixMemoryPool*		    m_pSQLMemoryPool;
	CSDMutex				    m_oSQLLock;

	//////
	CRechargeClientMgr		    m_oRechargeClientMgr;
	CRCClientMgr			    m_oRCClientMgr;
	ISDListener*			    m_poListener;
	CCliPacketParser		    m_oCliPacketParser;
	CHttpCliPacketParser	    m_oRCPacketParser;

	UINT64				        m_qwServerStartTime; //��������ʱ��
	BOOL					    m_bNeedSave2DB;
};


#endif


