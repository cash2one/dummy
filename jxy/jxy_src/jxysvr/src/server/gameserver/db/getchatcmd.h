

#ifndef _GET_CHAT_NOTICE_CMD_H_
#define _GET_CHAT_NOTICE_CMD_H_

#include <db/basedbccmd.h>
#include <sddb.h>
#include "protocol/server/protogsdb.h"
#include <protocol/server/protocligs.h>
#include <logic/base/basedefine.h>
#include "db/dbmgr.h"

using namespace std;

#define MAX_WORD_FILTER 64


struct SYS_CHAT_DATA
{
	UINT32		uiNoticeID;		//����IDeas
	UINT8		byOptType;		//��������
	UINT64		qwExpiresTime;	//����ʱ��
	CHAT_DATA	stData;			//��������
	
    SYS_CHAT_DATA()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(SYS_CHAT_DATA));
	}
};

struct ACTIVITY_CHAT_DATA
{
    CHAT_DATA stData;			// ��������
    UINT64 qwActivityStartTime; // ���ʼʱ�䣬��>0ʱ��ʾʱ�䵽ʱ�ŷ�����=0ʱ��ʾ��������

    ACTIVITY_CHAT_DATA()
    {
        memset(this, 0x00, sizeof(ACTIVITY_CHAT_DATA));
    }
};

typedef struct _tagWordFilterData
{
	TCHAR	m_szWordFilters[MAX_WORD_FILTER];	// Limited words for filter
	int	    m_kmpvalue[MAX_WORD_FILTER];		// KMP Next Value
	_tagWordFilterData()
	{
		Init();
	}
	void Init()
	{
		memset(this, 0x00, sizeof(_tagWordFilterData));
	}
} TWordFilterData;


typedef std::map<string, UINT32>				CChatSilenceByDeviceIDMap;
typedef CChatSilenceByDeviceIDMap::iterator		CChatSilenceByDeviceIDMapItr;

typedef std::map<UINT32, UINT32>				CChatSilenceByUserIDMap;
typedef CChatSilenceByUserIDMap::iterator		CChatSilenceByUserIDMapItr;

typedef std::map<UINT32, UINT32>				CChatSilenceByPlayerIDMap;
typedef CChatSilenceByPlayerIDMap::iterator		CChatSilenceByPlayerIDMapItr;

typedef std::list<SYS_CHAT_DATA*>				CSysChatNoticePtrList;
typedef std::list<SYS_CHAT_DATA>				CSysChatNoticeList;
typedef CSysChatNoticeList::iterator	        CSysChatNoticeListItr;

typedef std::map<string, TWordFilterData> CWordFilterDataMap;
typedef CWordFilterDataMap::iterator CWordFilterDataMapItr;

struct SSyncSilenceWordfileter2Db
{
    SSyncSilenceWordfileter2Db()
    {
        m_bModifySilenceByDeviceID = TRUE;
        m_bModifySilenceByUserID = TRUE;
        m_bModifySilenceByPlayerID = TRUE;
        m_bModifyWordFilter = TRUE;
        m_bGetDataFromDB = FALSE;
        m_bGetDataFromDBSuccess = FALSE;
        m_bModifyGmPlayerID = TRUE;
        m_bModifyGmDeviceID = TRUE;
		m_bModifySYSChatDataNotice = TRUE;
        m_wZoneID = 0;
    }
    CChatSilenceByDeviceIDMap				m_mapModifySilenceByDeviceID;//valueΪ0��ʾɾ����1��ʾ����
    CChatSilenceByUserIDMap				m_mapModifySilenceByUserID;//valueΪ0��ʾɾ����1��ʾ����
    CChatSilenceByPlayerIDMap				m_mapModifySilenceByPlayerID;//valueΪ0��ʾɾ����1��ʾ����
    map<string, UINT32>					m_mapModifyWordFilter;//valueΪ0��ʾɾ����1��ʾ����
    CStr32Map							m_mapGmDeviceID;		//valueΪ0��ʾɾ����1��ʾ����
    C3232Map								m_mapGmPlayerID;		////valueΪ0��ʾɾ����1��ʾ����
    BOOL									m_bModifyGmPlayerID;
    BOOL									m_bModifyGmDeviceID;
    BOOL									m_bModifySilenceByDeviceID;
    BOOL									m_bModifySilenceByUserID;
    BOOL									m_bModifySilenceByPlayerID;
    BOOL									m_bModifyWordFilter;
    BOOL									m_bGetDataFromDB;
    BOOL									m_bGetDataFromDBSuccess;
    UINT16								    m_wZoneID;

	BOOL									m_bModifySYSChatDataNotice;
	CSysChatNoticeList					    m_listSYSChatDataNotice;

};


/**
* @brief DBCommand,�첽�����DBCommand
*
*
*/
class CGetChatCMD : public CBaseDBCMD
{
public:
    CGetChatCMD();
    ~CGetChatCMD();

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

public:
    virtual EDBCmdType GetDBCmdType()
    {
        return EDBCT_CHAT ;
    }

    virtual VOID SetUserData(VOID* pUserData);
protected:

    BOOL AddGmDeviceID(SGDP::ISDDBConnection *poDBConn);
    BOOL DelGmDeviceID(SGDP::ISDDBConnection *poDBConn);

    BOOL AddGmPlayerID(SGDP::ISDDBConnection *poDBConn);
    BOOL DelGmPlayerID(SGDP::ISDDBConnection *poDBConn);

    BOOL AddChatSilenceByDeviceID(SGDP::ISDDBConnection *poDBConn);
    BOOL DelChatSilenceByDeviceID(SGDP::ISDDBConnection *poDBConn);

    BOOL AddChatSilenceByUserID(SGDP::ISDDBConnection *poDBConn);
    BOOL DelAddChatSilenceByUserID(SGDP::ISDDBConnection *poDBConn);

    BOOL AddChatSilenceByPlayerID(SGDP::ISDDBConnection *poDBConn);
    BOOL DelAddChatSilenceByPlayerID(SGDP::ISDDBConnection *poDBConn);

    BOOL AddModifyWordFilter(SGDP::ISDDBConnection *poDBConn);
    BOOL DelModifyWordFilter(SGDP::ISDDBConnection *poDBConn);

	BOOL AddSYSChatDataNotice(SGDP::ISDDBConnection *poDBConn);
	BOOL DelSYSChatDataNotice(SGDP::ISDDBConnection *poDBConn);



    BOOL GetDataFromDB(SGDP::ISDDBConnection *poDBConn);
    BOOL GetSilenceDataFromDB(SGDP::ISDDBConnection *poDBConn);
    BOOL GetSysChatFromDB(SGDP::ISDDBConnection *poDBConn);
    BOOL GetWordFilterDataFromDB(SGDP::ISDDBConnection *poDBConn);
    BOOL GetGMDataFromDB(SGDP::ISDDBConnection *poDBConn);

private:
    CChatSilenceByDeviceIDMap					m_mapSilenceByDeviceID;
    CChatSilenceByUserIDMap					m_mapSilenceByUserID;
    CChatSilenceByPlayerIDMap					m_mapSilenceByPlayerID;
    CSysChatNoticeList						m_listSYSChatDataNotice;
    CWordFilterDataMap						m_mapWordFilterData;
    CWordFilterDataMap						m_mapDspNameWordFilterData;
    CStr32Map								m_mapGmDeviceID;
    C3232Map									m_mapGmPlayerID;

    SSyncSilenceWordfileter2Db		m_stSyncSilenceWordfileter2Db;
};

#endif //#ifndef _GETPLAYERDATACMD_H_

