///<------------------------------------------------------------------------------
//< @file:   pkapplication.h
//< @author: hongkunan
//< @date:   2014��1��2�� 15:52:58
//< @brief:  ���ս��������ר�Ÿ�������ս�������ң��п��ܲ�ֹ��ս�������磬ȫ�����������������������gameserver��ά��һ������
//< Copyright (c) 2014 heihuo. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _pkapplication_h_
#define _pkapplication_h_

#include <sdframework.h>
#include <net/db/dbprocessor.h>
#include <common/server/packetparser.h>
#include <db/dbmgr.h>
#include <sdmemorypool.h>

class CGSPipeChannel;

// ���ڲ�gameserver��ͨ�Źܵ��б�ÿ����id��Ӧ������gameserver��key = gameserver����Id��val = �������������gameserver��ͨ�Źܵ�
typedef std::map<UINT16, CGSPipeChannel*> CZoneID2GSPipeChannelMap;

// ���ս������
class CPKApplication : public CSDApplication
{
public:
    CPKApplication();

public:
    // ������Id�����������gameserver������
    CGSPipeChannel*	GetGSPipeChannel(UINT16 wZoneID);

    ///<@impl>
    virtual CSDPipeChannel* OnPipeChannelConnected(UINT32 dwPipeID);

    ///<@impl>
    virtual VOID OnPipeChannelDisconnected(CSDPipeChannel* poChannel);

private:
    CDBProcessor			 m_oDBProcessor;      // ���ݿ����ɹ��ص�ʱ�Ĵ�����

    CZoneID2GSPipeChannelMap m_mapGSPipeChannel;  // ���ӵ����������ĸ���gameserver
    CSDPipeChannel*		     m_poGMPipeChannel;   // ��gm������������ͨ��
    ISDListener*			 m_poListener;        // ������������������gameserver������

    CDBMgr				     m_oDBMgr;
    CSDFixMemoryPool		 m_oSQLMemoryPool;
    CSDMutex				 m_oSQLLock;
    
    CHttpCliPacketParser	 m_oRCPacketParser;

    UINT64				     m_qwServerStartTime; //��������ʱ��
    BOOL					 m_bNeedSave2DB;
};

#endif //_pkapplication_h_