#include "chatmgr.h"
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <sdutil.h>
#include <framework/gsconfig.h>
#include <net/cli/usermgr.h>
#include <db/getchatcmd.h>
#include <logic/player/player.h>
#include <db/dbcommoperate.h>
#include <logic/other/errmsgmgr.h>
#include <errdef.h>
#include <framework/gsapi.h>
#include "wordfilter.h"
#include "logic/faction/factionmgr.h"
#include <dll/sdnet/sdpkg.h>
#include <math.h>

#define MAX_SEND_CHAT_NOTICE_TIME		60
#define MAX_SYNC_CHAT_NOTICE_TIME		600

// �����¼��ʷ�����ĸ���
#define MAX_CHAT_HISTORY (MAX_CHAT_NUM * 3)

#define CLI_NEW_CHAT_SUPPORT_VERSION 301 // �ͻ��˰汾��Ҫ>=301��֧���µ�����Ƶ�������ɡ��Ƶ��

using namespace SGDP;

UINT32 CChatMgr::s_dwSerialNumber = 0;

namespace chatutil
{
// ��������ʱ����������¼������ʱ�������ͬһ�룬����ˮ��������
VOID InsertChatByTime(CChatList &listChat, ChatInfo &stChatInfo)
{
    for(CChatList::iterator itr = listChat.begin(); itr != listChat.end(); ++itr)
    {
        ChatInfo &stItrChat = *itr;

        // ����ʱ��
        if(stItrChat.stData.qwChatTime > stChatInfo.stData.qwChatTime)
        {
            listChat.insert(itr, stChatInfo);
            return;
        }
        else if(stItrChat.stData.qwChatTime == stChatInfo.stData.qwChatTime)
        {
            if(stItrChat.stData.dwSerialNumber > stChatInfo.stData.dwSerialNumber)
            {
                listChat.insert(itr, stChatInfo);
                return;
            }
        }
    }

    listChat.push_back(stChatInfo);
}

// ��ȡ���ɵ�ͼ��ID
BYTE GetFactionIconIDByFaction(UINT32 dwFactionID)
{
    CFaction *poFaction = CFactionMgr::Instance()->GetFaction(dwFactionID);
    if(NULL == poFaction)
    {
        return NULL_FACTION_ICON_ID;
    }

    return poFaction->GetFactionIconID();
}
}

IMPLEMENT_SINGLETON(CChatMgr)

CChatMgr::CChatMgr() :
    m_wCurSysChatIdx(0)
{
    ResetChat();

    m_qwSendNoticeTime = SDTimeSecs();
    m_qwChatSyncTime = SDTimeSecs();
}

CChatMgr::~CChatMgr()
{
    ResetChat();
}

BOOL CChatMgr::Init()
{
    if(FALSE == CWordFilter::CreateInstance())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: CreateInstance failed!"), MSG_MARK);
        return FALSE;
    }
    if(FALSE == CWordFilter::Instance()->Init())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: Init failed!"), MSG_MARK);
        return FALSE;
    }

    if(!InitSysChatDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitSysChatDB failed!"), MSG_MARK);
        return FALSE;
    }
    if(!InitSilenceDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitSilenceDB failed!"), MSG_MARK);
        return FALSE;
    }
    if(!InitGMInfoDB())
    {
        SYS_CRITICAL(_SDT("[%s: %d]: InitGMInfoDB failed!"), MSG_MARK);
        return FALSE;
    }

    return TRUE;
}

VOID CChatMgr::UnInit()
{
    ResetChat();
}

VOID CChatMgr::ResetChat()
{
    m_listWorldChat.clear();
    m_listActivityChat.clear();
    m_listSysChatNotExpired.clear();
    m_listSysChatNotice.clear();
}

// �����ع����б�����Ϊ���ݿ��ȡ���Ĺ����б�
VOID CChatMgr::SetSYSChatDataNoticeData(CSysChatNoticeList &listDBSysChat)
{
    // ֱ�������ݿ�����ݸ��Ǳ������ݣ�����Ҫע�⣬���ݿ�ȡ���������¼��û����ˮ�ŵ�
    m_listSysChatNotice = listDBSysChat;

    UINT32 i = 0;

    // ��������δ���ڵ�ϵͳ�����б�
    const UINT64 qwNow = SDTimeSecs();

    m_listSysChatNotExpired.clear();

    // ��δ���ڵ�ϵͳ���������б�
    for(CSysChatNoticeList::iterator itr = m_listSysChatNotice.begin(); itr != m_listSysChatNotice.end(); ++itr)
    {
        SYS_CHAT_DATA &stSysChat = *itr;
        stSysChat.stData.dwSerialNumber = ++i; // ����������ˮ������Ϊ�ͻ��˲�������ͬ��ˮ�ŵ������¼

        // �Ƿ��ѹ���
        if(stSysChat.qwExpiresTime >= qwNow)
        {
            // δ����
            stSysChat.stData.dwSerialNumber = AllocChatSerialNum(); // ����δ���ڵ������¼��ȷ���������¼���нϴ����ˮ��
            m_listSysChatNotExpired.push_back(stSysChat);
        }
    }
}

VOID CChatMgr::SetSilenceData(CChatSilenceByDeviceIDMap &mapSilenceByDeviceID,
                              CChatSilenceByUserIDMap &mapSilenceByUserID,
                              CChatSilenceByPlayerIDMap	&mapSilenceByPlayerID)
{

    m_mapSilenceByDeviceID.clear();
    m_mapSilenceByUserID.clear();
    m_mapSilenceByPlayerID.clear();
    m_mapSilenceByDeviceID = mapSilenceByDeviceID;
    m_mapSilenceByUserID = mapSilenceByUserID;
    m_mapSilenceByPlayerID = mapSilenceByPlayerID;

}

VOID CChatMgr::SetGMData(CStr32Map mapGmDeviceID, C3232Map mapGmPlayerID)
{
    m_mapGmDeviceID.clear();
    m_mapGmPlayerID.clear();

    m_mapGmDeviceID = mapGmDeviceID;
    m_mapGmPlayerID = mapGmPlayerID;
}

// ����gm����
VOID CChatMgr::AddGmData(UINT32 dwPlayerID, string strDeviceID, UINT8 byOptType)
{
    if (0 != dwPlayerID)
    {
        m_mapGmPlayerID.insert(pair<UINT32, UINT32>(dwPlayerID, byOptType));
        m_oSyncSilenceWordfileter2Db.m_mapGmPlayerID.insert(pair<UINT32, UINT32>(dwPlayerID, byOptType));
    }
    if (strDeviceID.size())
    {
        m_mapGmDeviceID.insert(pair<string, UINT32>(strDeviceID, byOptType));
        m_oSyncSilenceWordfileter2Db.m_mapGmDeviceID.insert(pair<string, UINT32>(strDeviceID, byOptType));
    }
}

// ���ϵͳ���칫��
VOID CChatMgr::AddSysChat(string strChatContent, string strExpiresTime, UINT8 byOptType)
{
    if (strChatContent.empty())
    {
        return;
    }

    const UINT64 qwNow = SDTimeSecs();

    SYS_CHAT_DATA stSysChat;
    stSysChat.byOptType = byOptType;

    CSDDateTime stDateTime;
    if(SDTimeFromString(strExpiresTime, stDateTime))
    {
        stSysChat.qwExpiresTime = stDateTime.GetTimeValue();
    }
    else
    {
        stSysChat.qwExpiresTime = qwNow;
    }

    stSysChat.stData.dwPlayerID = 0;
    stSysChat.stData.byChatType = ECT_SYS;
    stSysChat.stData.dwSerialNumber = AllocChatSerialNum();
    stSysChat.stData.qwChatTime = qwNow;
    stSysChat.stData.dwChatLen = strChatContent.size() >= MAX_CHAT_CONTENT_NUM ? MAX_CHAT_CONTENT_NUM - 1 : strChatContent.size();
    memcpy(stSysChat.stData.abyChatContent, strChatContent.c_str(), stSysChat.stData.dwChatLen);

    m_listSysChatNotice.push_back(stSysChat);
    m_oSyncSilenceWordfileter2Db.m_listSYSChatDataNotice.push_back(stSysChat);

    // �Ƿ�δ���ڣ�δ���ڵĻ��������δ���ڹ����б�ʹ�䶨ʱ����
    if(qwNow <= stSysChat.qwExpiresTime)
    {
        m_listSysChatNotExpired.push_back(stSysChat);
    }

}

// ��ӻ���칫��
VOID CChatMgr::AddActivityChat(const string &strChatContent, UINT64 qwActivityStartTime/* ���ʼʱ�䣬��>0ʱ��ʾʱ�䵽ʱ�ŷ�����=0ʱ��ʾ��������*/)
{
    if (strChatContent.empty())
    {
        return;
    }

    ACTIVITY_CHAT_DATA stActChat;
    BuildActivityChat(stActChat, strChatContent, qwActivityStartTime);

    m_listActivityChat.push_back(stActChat);
}

// ������������
VOID CChatMgr::BuildActivityChat(ACTIVITY_CHAT_DATA &stActChat, const string &strChatContent, UINT64 qwActivityStartTime/*���ʼʱ�䣬��>0ʱ��ʾʱ�䵽ʱ�ŷ�����=0ʱ��ʾ��������*/)
{
    memset(&stActChat, 0, sizeof(stActChat));

    stActChat.qwActivityStartTime = qwActivityStartTime;

    CHAT_DATA &stChat = stActChat.stData;
    stChat.dwPlayerID = 0;
    stChat.byChatType = ECT_ACTIVITY;
    stChat.qwChatTime = (qwActivityStartTime == 0 ? SDTimeSecs() : qwActivityStartTime);
    stChat.dwChatLen  = (strChatContent.size() >= MAX_CHAT_CONTENT_NUM ? MAX_CHAT_CONTENT_NUM - 1 : strChatContent.size());
    memcpy(stChat.abyChatContent, strChatContent.c_str(), stChat.dwChatLen);
    stChat.dwSerialNumber = AllocChatSerialNum();
}

// ������ɻ����
ChatInfo* CChatMgr::BuildFactionActivityChat(UINT32 dwFactionID, const string &strChatContent)
{
    ChatInfo *pstChatInfo = m_oChatDataPool.Alloc(); // �·���һ��ChatInfo
    if (NULL == pstChatInfo)
    {
        return NULL;
    }

    CHAT_DATA &stChat = pstChatInfo->stData;
    memset(&stChat, 0, sizeof(stChat));

    stChat.dwPlayerID = 0;
    stChat.byChatType = ECT_FACTION;
    stChat.qwChatTime = SDTimeSecs();
    stChat.dwChatLen  = (strChatContent.size() >= MAX_CHAT_CONTENT_NUM ? MAX_CHAT_CONTENT_NUM - 1 : strChatContent.size());
    memcpy(stChat.abyChatContent, strChatContent.c_str(), stChat.dwChatLen);
    stChat.dwSerialNumber = AllocChatSerialNum();

    pstChatInfo->byVipLevel      = 0;
    pstChatInfo->dwFactionIconID = chatutil::GetFactionIconIDByFaction(dwFactionID);

    return pstChatInfo;
}

VOID CChatMgr::AddSilenceData(vector<string> &vecSilenceByDeviceID, vector<string> &vecSilenceByUserID, vector<string>	&vecSilenceByPlayerID)
{
    UINT32 dwSize = vecSilenceByDeviceID.size();
    UINT32 dwIdx = 0;
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        if(0 == vecSilenceByDeviceID[dwIdx].compare("0"))
        {
            continue;
        }
        m_mapSilenceByDeviceID[vecSilenceByDeviceID[dwIdx]] = 1;
        m_oSyncSilenceWordfileter2Db.m_mapModifySilenceByDeviceID[vecSilenceByDeviceID[dwIdx]] = 1;
    }
    dwSize = vecSilenceByUserID.size();
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        if(0 == vecSilenceByUserID[dwIdx].compare("0"))
        {
            continue;
        }
        m_mapSilenceByUserID[SDAtou(vecSilenceByUserID[dwIdx].c_str())] = 1;
        m_oSyncSilenceWordfileter2Db.m_mapModifySilenceByUserID[SDAtou(vecSilenceByUserID[dwIdx].c_str())] = 1;
    }
    dwSize = vecSilenceByPlayerID.size();
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        if(0 == vecSilenceByPlayerID[dwIdx].compare("0"))
        {
            continue;
        }
        m_mapSilenceByPlayerID[SDAtou(vecSilenceByPlayerID[dwIdx].c_str())] = 1;
        m_oSyncSilenceWordfileter2Db.m_mapModifySilenceByPlayerID[SDAtou(vecSilenceByPlayerID[dwIdx].c_str())] = 1;
    }
}



VOID CChatMgr::DelSilenceData(vector<string> &vecSilenceByDeviceID, vector<string> &vecSilenceByUserID, vector<string>	&vecSilenceByPlayerID)
{
    UINT32 dwSize = vecSilenceByDeviceID.size();
    UINT32 dwIdx = 0;
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        if(0 == vecSilenceByDeviceID[dwIdx].compare("0"))
        {
            continue;
        }
        m_mapSilenceByDeviceID.erase(vecSilenceByDeviceID[dwIdx]);
        m_oSyncSilenceWordfileter2Db.m_mapModifySilenceByDeviceID[vecSilenceByDeviceID[dwIdx]] = 0;
    }
    dwSize = vecSilenceByUserID.size();
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        if(0 == vecSilenceByUserID[dwIdx].compare("0"))
        {
            continue;
        }
        m_mapSilenceByUserID.erase(SDAtou(vecSilenceByUserID[dwIdx].c_str()));
        m_oSyncSilenceWordfileter2Db.m_mapModifySilenceByUserID[SDAtou(vecSilenceByUserID[dwIdx].c_str())] = 0;
    }
    dwSize = vecSilenceByPlayerID.size();
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        if(0 == vecSilenceByPlayerID[dwIdx].compare("0"))
        {
            continue;
        }
        m_mapSilenceByPlayerID.erase(SDAtou(vecSilenceByPlayerID[dwIdx].c_str()));
        m_oSyncSilenceWordfileter2Db.m_mapModifySilenceByPlayerID[SDAtou(vecSilenceByPlayerID[dwIdx].c_str())] = 0;
    }
}


VOID CChatMgr::SetWordFilterData(CWordFilterDataMap &mapWordFilterData, CWordFilterDataMap &mapDspNameWordFilterData)
{
    CWordFilter::Instance()->SetWordFilterData(mapWordFilterData, mapDspNameWordFilterData);
}

VOID CChatMgr::AddWordFilterData(vector<string> &vecWordFilterData)
{
    UINT32 dwSize = vecWordFilterData.size();
    UINT32 dwIdx = 0;
    CWordFilterDataMap& mapWordFilterData = CWordFilter::Instance()->GetWordFilterData();
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        TWordFilterData stWordFilterData;
        stWordFilterData.Init();
        _SDTStrncpy(stWordFilterData.m_szWordFilters, vecWordFilterData[dwIdx].c_str(), MAX_WORD_FILTER);
        KMP_GetNext(stWordFilterData.m_szWordFilters, stWordFilterData.m_kmpvalue);	// �õ�һ���������йص���ֵm_kmpvalue[i]
        mapWordFilterData[stWordFilterData.m_szWordFilters] = stWordFilterData;
        m_oSyncSilenceWordfileter2Db.m_mapModifyWordFilter[vecWordFilterData[dwIdx]] = 1;
    }
}

VOID CChatMgr::DelWordFilterData(vector<string> &vecWordFilterData)
{
    UINT32 dwSize = vecWordFilterData.size();
    UINT32 dwIdx = 0;
    CWordFilterDataMap& mapWordFilterData = CWordFilter::Instance()->GetWordFilterData();
    for(dwIdx = 0; dwIdx < dwSize; dwIdx++)
    {
        mapWordFilterData.erase(vecWordFilterData[dwIdx]);
        m_oSyncSilenceWordfileter2Db.m_mapModifyWordFilter[vecWordFilterData[dwIdx]] = 0;
    }
}


UINT32 CChatMgr::OnEvent()
{
    SendChat();

    static UINT16 wIdx = 1;
    //�����������ݵ���
    if (SDTimeSecs() - m_qwChatSyncTime > CGSConfig::Instance()->GetChatSyncTime())
    {
        CBaseDBCMD* poCMD = gsapi::GetDBMgr()->CreateCmd(EDBCT_CHAT);
        poCMD->SetUserData(&m_oSyncSilenceWordfileter2Db);
        if(0 == wIdx++ % 3) // 3�����ȡһ������
        {
            m_oSyncSilenceWordfileter2Db.m_bGetDataFromDB = TRUE;
        }
        if(NULL != poCMD)
        {
            gsapi::GetDBMgr()->AddPayCommand(poCMD);
        }
        m_qwChatSyncTime = SDTimeSecs();
    }
    return 0;
}

// ȡ��ϵͳ�����б�
BOOL CChatMgr::InitSysChatDB()
{
    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetPayDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }

    m_oSyncSilenceWordfileter2Db.m_wZoneID = gsapi::GetZoneID();
    m_listSysChatNotice.clear();
    CHAR szSql[1024] = {0};
    sprintf(szSql, "select NoticeID, NoticeContent, ExpiresTime from syschat where ZoneID='%u' or ZoneID='0' order by ZoneID asc, ExpiresTime asc;", m_oSyncSilenceWordfileter2Db.m_wZoneID);

    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = pDBSession->ExecuteSqlRs(szSql, &pRecordSet);
    if(SDDB_HAS_RECORDSET != nRet && SDDB_NO_RECORDSET != nRet && SDDB_SUCCESS != nRet)
    {
        return FALSE;
    }

    if(SDDB_HAS_RECORDSET == nRet)
    {
        UINT64 qwNow = SDTimeSecs();

        while(pRecordSet->GetRecord())
        {
            SYS_CHAT_DATA stSysChat;
            stSysChat.uiNoticeID = SDAtou(pRecordSet->GetFieldValueByName("NoticeID"));
            stSysChat.stData.dwPlayerID = 0;
            stSysChat.stData.aszUserName[0] = '\0';// �����ǳ�Ϊ�վ���
            stSysChat.stData.byChatType = ECT_SYS;
            stSysChat.stData.dwChatLen = pRecordSet->GetFieldLengthByName("NoticeContent");
            stSysChat.stData.dwChatLen = stSysChat.stData.dwChatLen >= MAX_CHAT_CONTENT_NUM ? MAX_CHAT_CONTENT_NUM - 1 : stSysChat.stData.dwChatLen;
            stSysChat.stData.dwSerialNumber = AllocChatSerialNum();
            memcpy(stSysChat.stData.abyChatContent, (VOID*)(pRecordSet->GetFieldValueByName("NoticeContent")), stSysChat.stData.dwChatLen);
            GetDateTime2Stamp(stSysChat.qwExpiresTime, "ExpiresTime");
            stSysChat.stData.qwChatTime = qwNow > stSysChat.qwExpiresTime ? stSysChat.qwExpiresTime : qwNow;

            m_listSysChatNotice.push_back(stSysChat);

            // �Ƿ�δ���ڣ�δ���ڵĻ����뵱ǰδ�����б�
            if(stSysChat.qwExpiresTime >= qwNow)
            {
                // δ����
                m_listSysChatNotExpired.push_back(stSysChat);
            }
        }
    }

    if(pRecordSet)
    {
        pRecordSet->Release();
    }

    m_qwChatSyncTime = SDTimeSecs();
    return TRUE;
}

BOOL CChatMgr::InitSilenceDB()
{
    UINT32 dwPlayerID	=	0;
    UINT32 dwUserID	=	0;
    string strDeviceID = "";

    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetPayDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = pDBSession->ExecuteSqlRs("select * from  silencedeviceid;", &pRecordSet);
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            strDeviceID	= pRecordSet->GetFieldValueByName("DeviceID");
            if (0 != strDeviceID.length())
            {
                m_mapSilenceByDeviceID[strDeviceID] = 1;
            }
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    /////////////////////////////////////

    nRet = pDBSession->ExecuteSqlRs("select * from  silenceplayerid;", &pRecordSet);
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            dwPlayerID	= SDAtou(pRecordSet->GetFieldValueByName("PlayerID"));
            if (0 != dwPlayerID)
            {
                m_mapSilenceByPlayerID[dwPlayerID] = 1;
            }
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    /////////////////////////////////////

    nRet = pDBSession->ExecuteSqlRs("select * from  silenceuserid;", &pRecordSet);
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            dwUserID	= SDAtou(pRecordSet->GetFieldValueByName("UserID"));
            if (0 != dwUserID)
            {
                m_mapSilenceByUserID[dwUserID] = 1;
            }
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    return TRUE;
}


BOOL CChatMgr::InitGMInfoDB()
{
    UINT32 dwPlayerID	=	0;
    UINT32 dwUserID	=	0;
    string strDeviceID = "";

    SGDP::ISDDBSession*	pDBSession = gsapi::GetDBMgr()->GetPayDBSession();
    if(NULL == pDBSession)
    {
        return FALSE;
    }
    SGDP::ISDDBRecordSet* pRecordSet = NULL;
    INT32 nRet = pDBSession->ExecuteSqlRs("select * from  gmdeviceid;", &pRecordSet);
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            strDeviceID	= pRecordSet->GetFieldLengthByName("DeviceID");
            if (0 != strDeviceID.length())
            {
                m_mapGmDeviceID[strDeviceID] = 1;
            }
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }

    /////////////////////////////////////

    nRet = pDBSession->ExecuteSqlRs("select * from  gmplayerid;", &pRecordSet);
    if(SDDB_HAS_RECORDSET == nRet)
    {
        while(pRecordSet->GetRecord())
        {
            dwPlayerID	= SDAtou(pRecordSet->GetFieldValueByName("PlayerID"));
            if (0 != dwPlayerID)
            {
                m_mapGmPlayerID[dwPlayerID] = 1;
            }
        }
    }
    if(NULL != pRecordSet)
    {
        pRecordSet->Release();
        pRecordSet = NULL;
    }


    return TRUE;
}

BOOL CChatMgr::IsGm(CPlayer *poPlayer)
{
    CUser* poUser = poPlayer->GetUser();

    return (IsGmByPlayerID(poPlayer->GetID()))
           || ((NULL != poUser) && (m_mapGmDeviceID.find(poUser->GetDeviceID()) != m_mapGmDeviceID.end()));
}

BOOL CChatMgr::IsGm(UINT32 dwPlayerID)
{
    CPlayer *poPlayer = CPlayerMgr::Instance()->FindPlayer(dwPlayerID);
    if(NULL == poPlayer)
    {
        return IsGmByPlayerID(dwPlayerID);
    }

    return IsGm(poPlayer);
}

BOOL CChatMgr::IsGmByPlayerID(UINT32 dwPlayerID)
{
    return m_mapGmPlayerID.find(dwPlayerID) != m_mapGmPlayerID.end();
}

// �Ƿ񱻽���
BOOL CChatMgr::IsSilenced(CPlayer *poPlayer)
{
    //��ȡ�û���Ϣ
    CUser* poUser = poPlayer->GetUser();
    if (NULL != poUser)
    {
        //�����豸ID����Ƿ����
        string strDeviceID = poUser->GetDeviceID();
        if (m_mapSilenceByDeviceID.find(strDeviceID) != m_mapSilenceByDeviceID.end())
        {
            return TRUE;
        }
        //����UserID����Ƿ����
        if (m_mapSilenceByUserID.find(poUser->GetUserID()) != m_mapSilenceByUserID.end())
        {
            return TRUE;
        }
    }
    //�������ID����Ƿ����
    if (IsSilencedByPlayerID(poPlayer->GetID()))
    {
        return TRUE;
    }

    return FALSE;
}

// �������ID����Ƿ񱻽���
BOOL CChatMgr::IsSilencedByPlayerID(UINT32 dwPlayerID)
{
    if (m_mapSilenceByPlayerID.find(dwPlayerID) != m_mapSilenceByPlayerID.end())
    {
        return TRUE;
    }

    return FALSE;
}

// ��������Ƶ�������¼
VOID CChatMgr::ClearWorldChat()
{
    // �������Ƶ���ľ������¼
    m_listWorldChatPool.insert(m_listWorldChatPool.end(), m_listWorldChat.begin(), m_listWorldChat.end());
    m_listWorldChat.clear();

    // ������������¼���棬ֻ���������ļ�������
    while (m_listWorldChatPool.size() > MAX_CHAT_HISTORY)
    {
        CChatDataListItr itr  = m_listWorldChatPool.begin();
        if (itr != m_listWorldChatPool.end())
        {
            m_oChatDataPool.Free(*itr);
            m_listWorldChatPool.erase(itr);
        }
    }
}

// ����Ƶ�������¼
VOID CChatMgr::ClearActivityChat()
{
    // ����Ƶ���ľɹ����¼����Щδ�����Ĺ�������
    for (CActivityChatListItr chatitr = m_listActivityChat.begin(); chatitr != m_listActivityChat.end();)
    {
        ACTIVITY_CHAT_DATA &stChat = *chatitr;

        // ������ʱ��δ��������������
        if (stChat.qwActivityStartTime > 0 && SDTimeSecs() < stChat.qwActivityStartTime)
        {
            chatitr++;
            continue;
        }

        m_listActivityChatPool.push_back(stChat);
        m_listActivityChat.erase(chatitr++);
    }

    // ����������칫�滺�棬ֻ��������ļ�����¼
    UINT32 dwSize = m_listActivityChatPool.size();
    if(dwSize > MAX_CHAT_HISTORY)
    {
        CActivityChatListItr eraseItr = m_listActivityChatPool.begin();
        advance(eraseItr, dwSize - MAX_CHAT_HISTORY);

        m_listActivityChatPool.erase(m_listActivityChatPool.begin(), eraseItr);
    }
}

// ��������ɵ������¼
VOID CChatMgr::ClearFactionChat()
{
    CMapFaction &mapFaction = CFactionMgr::Instance()->GetFactions();

    for(CMapFaction::iterator itr = mapFaction.begin(); itr != mapFaction.end(); ++itr)
    {
        CFaction *poFaction = itr->second;
        if(NULL == poFaction)
        {
            continue;
        }

        poFaction->ClearChat();
    }
}

VOID CChatMgr::FreeChat(ChatInfo *pstChat)
{
    if(NULL == pstChat)
    {
        return;
    }

    m_oChatDataPool.Free(pstChat);
}

// ȡ������Ƶ���������¼
VOID CChatMgr::TakeWorldChat(CChatList &listChat)
{
    for(CChatDataList::iterator itr = m_listWorldChat.begin(); itr != m_listWorldChat.end(); ++itr)
    {
        ChatInfo &stChatInfo = **itr;

        // ��������ҵ����콫�����·�
        if(IsSilencedByPlayerID(stChatInfo.stData.dwPlayerID))
        {
            continue;
        }

        listChat.push_back(stChatInfo); // ���
    }
}

// ȡ������Ƶ���������¼
VOID CChatMgr::TakeFactionChat(PKT_CLIGS_CHAT_NTF &stAck, UINT32 dwPlayerID, CFaction *poFaction)
{
    memset(&stAck, 0x00, sizeof(PKT_CLIGS_CHAT_NTF));

    if(NULL == poFaction)
    {
        return;
    }

    // ȡ�����������¼
    CChatDataList &listChatData = poFaction->GetChat();
    for (CChatDataList::iterator chatitr = listChatData.begin(); chatitr != listChatData.end(); chatitr++)
    {
        if(stAck.byChatNum >= MAX_CHAT_NUM)
        {
            break;
        }

        ChatInfo *pstChatInfo = *chatitr;
        if (pstChatInfo->stData.dwPlayerID == dwPlayerID)
        {
            continue;
        }

        // ����������ԣ����������ڵ����첻�ᱻ�·�
        if(IsSilencedByPlayerID(pstChatInfo->stData.dwPlayerID))
        {
            continue;
        }

        // ������Ϣ��
        memcpy(&stAck.astChatData[stAck.byChatNum], &pstChatInfo->stData, sizeof(CHAT_DATA));
        stAck.abyVipLevel[stAck.byChatNum]          = pstChatInfo->byVipLevel;
        stAck.abyFactionIconIDList[stAck.byChatNum] = pstChatInfo->dwFactionIconID;
        stAck.byChatNum++;
    }
}

// ��ȡϵͳ����
VOID CChatMgr::TakeSysChat(CChatList &listChat)
{
    const UINT64 qwNow = SDTimeSecs();

    // ÿ��һ��ʱ��ŷ���ϵͳ����
    if (qwNow - m_qwSendNoticeTime < CGSConfig::Instance()->GetChatSendNotice())
    {
        return;
    }

    m_qwSendNoticeTime = qwNow;

    // ����ѹ��ڵ�ϵͳ����
    for(CSysChatNoticeList::iterator itr = m_listSysChatNotExpired.begin(); itr != m_listSysChatNotExpired.end(); )
    {
        SYS_CHAT_DATA &stSysChat = *itr;

        // �Ƿ��ѹ���
        if(qwNow > stSysChat.qwExpiresTime)
        {
            // �ѹ���
            m_listSysChatNotExpired.erase(itr++);
        }
        else
        {
            ++itr;
        }
    }

    if(m_listSysChatNotExpired.empty())
    {
        return;
    }

    // ������ǰ����
    ++m_wCurSysChatIdx;
    if(m_wCurSysChatIdx >= m_listSysChatNotExpired.size())
    {
        m_wCurSysChatIdx = 0;
    }

    // ��������δ���ڵ�ϵͳ����
    CSysChatNoticeList::iterator itr = m_listSysChatNotExpired.begin();
    advance(itr, m_wCurSysChatIdx);

    SYS_CHAT_DATA &stSysChat = *itr;

    // ��δ���ڼ�¼�����б�
    ChatInfo stChatInfo;

    memcpy(&stChatInfo.stData, &stSysChat.stData, sizeof(CHAT_DATA));
    stChatInfo.stData.qwChatTime     = SDTimeSecs();
    stChatInfo.stData.dwSerialNumber = AllocChatSerialNum();
    stChatInfo.byVipLevel            = 0;
    stChatInfo.dwFactionIconID       = NULL_FACTION_ICON_ID;

    listChat.push_back(stChatInfo);
}

// ��ȡ�����(ȫ��֪ͨ)
VOID CChatMgr::TakeActivityChat(CChatList &listChat/*�����*/)
{
    UINT64 qwNow = SDTimeSecs();

    for (CActivityChatListItr chatitr = m_listActivityChat.begin(); chatitr != m_listActivityChat.end(); ++chatitr)
    {
        ACTIVITY_CHAT_DATA &stActChat = *chatitr;

        // ���͸û�����ʱ����Ƿ��ѵ�
        if (stActChat.qwActivityStartTime > 0 && qwNow < stActChat.qwActivityStartTime)
        {
            continue;
        }

        // �����칫������б�
        ChatInfo stChatInfo;

        memcpy(&stChatInfo.stData, &stActChat.stData, sizeof(CHAT_DATA));
        stChatInfo.byVipLevel      = 0;
        stChatInfo.dwFactionIconID = NULL_FACTION_ICON_ID;

        listChat.push_back(stChatInfo);
    }
}

// ���������¼�б����ң���������¼�϶࣬����ɼ���������
VOID CChatMgr::SendChatList(CChatList &listChat, CUser *poUser)
{
    if(NULL == poUser || listChat.empty())
    {
        return;
    }

    CPlayer* poPlayer = poUser->GetPlayer();
    if(NULL == poPlayer)
    {
        return;
    }

    // ���п�������
    if(!poPlayer->GetBuild(EBK_VIEWCHAT))
    {
        return;
    }

    // �Ƿ��ǻ�����
    if(poPlayer->IsRobot())
    {
        return;
    }

    UINT32 dwPlayerID = poPlayer->GetID();

    static PKT_CLIGS_CHAT_NTF stAck;
    memset(&stAck, 0x00, sizeof(PKT_CLIGS_CHAT_NTF));

    // ��ɼ���������ȥ
    for(CChatList::iterator itr = listChat.begin(); itr != listChat.end(); ++itr)
    {
        ChatInfo &stChatInfo    = *itr;
        CHAT_DATA &stCliChat = stAck.astChatData[stAck.byChatNum];

        //�����ѹ�ϵ������Ǻ�����
        if (poPlayer->GetFriends())
        {
            if(EFSRT_BLACKLIST == poPlayer->GetFriends()->CkRelationType(stChatInfo.stData.dwPlayerID))
            {
                continue;
            }
        }

        // ���ͻ��˰汾�Ƿ�֧�����ɺͻ����Ƶ��
        if(poPlayer->GetCliVer() < CLI_NEW_CHAT_SUPPORT_VERSION)
        {
            if(ECT_FACTION == stChatInfo.stData.byChatType || ECT_ACTIVITY == stChatInfo.stData.byChatType)
            {
                continue;
            }
        }

        // ����ǻ�������ͣ��ж�����Ƿ��ѿ��������
        if(ECT_ACTIVITY == stChatInfo.stData.byChatType && NULL == poPlayer->GetBuild(EBK_ACTIVITY))
        {
            continue;
        }

        // ���������¼�Ƿ�����ұ��˷������ǵĻ������·�
        if (stChatInfo.stData.dwPlayerID == dwPlayerID)
        {
            continue;
        }

        memcpy(&stCliChat, &stChatInfo.stData, sizeof(CHAT_DATA));
        stAck.abyVipLevel[stAck.byChatNum]          = stChatInfo.byVipLevel;
        stAck.abyFactionIconIDList[stAck.byChatNum] = stChatInfo.dwFactionIconID;

        stAck.byChatNum++;

        // �Ƿ���Ҫ�ٶ��һ����
        if(MAX_CHAT_NUM == stAck.byChatNum)
        {
            poUser->SendMsg((CHAR*)&stAck, CLIGS_CHAT_NTF);
            memset(&stAck, 0x00, sizeof(PKT_CLIGS_CHAT_NTF));
        }
    }

    // �������Ǹ���Ϣ��Ҳ����ȥ
    if(stAck.byChatNum > 0)
    {
        poUser->SendMsg((CHAR*)&stAck, CLIGS_CHAT_NTF);
    }
}

// �������Ƶ�������¼
VOID CChatMgr::AddWorldChat(ChatInfo *pstChat)
{
    m_listWorldChat.push_back(pstChat);
    if(m_listWorldChat.size() >= MAX_CHAT_NUM)
    {
        SendChat();
    }
}

UINT16 CChatMgr::AddChatData(CPlayer *poPlayer, CHAT_DATA &stCHAT_DATA, TCHAR* pszErrInfo)
{
    if(NULL == poPlayer)
    {
        RETURN_OTHER_ERR;
    }

    // �ͻ��˻����������ģ����pszErrInfo��Ϊ�գ���������ʾpszErrInfo��������ݴ���������жϣ�Ϊ�˼��ݾɿͻ��ˣ��еĴ�����ʾ�޷��ô�����������

    // �Ƿ�ӵ������Ȩ��
    if(!poPlayer->GetBuild(EBK_SNDCHAT))
    {
        SDStrcpy(pszErrInfo, CMsgDefMgr::Instance()->GetErrMsg("LEVEL_NOT_REACH") .c_str());
        RETURN_OTHER_ERR;
    }

    // �������Ƿ񱻽���
    if(IsSilenced(poPlayer))
    {
        USR_INFO(_SDT("[%s: %d]: player [%u] is Silence \n"), MSG_MARK, stCHAT_DATA.dwPlayerID);
        return ERR_CHAT::ID_CHAT_SILENCE_ERROR;
    }

    // �Ƿ�ӵ�ж�ӦƵ��������Ȩ��
    if(ECT_FACTION == stCHAT_DATA.byChatType && NULL == poPlayer->GetFaction())
    {
        return ERR_CHAT::ID_CHAT_NOT_ENTER_FACTION;
    }

    //����Ƿ��йؼ��ֹ���
    TCHAR	*pWordFilter = NULL;
    pWordFilter = CWordFilter::Instance()->VerifyString((const TCHAR *)stCHAT_DATA.abyChatContent);
    if(NULL != pWordFilter)
    {
		//���������в��������<XXX>�ؼ���
		std::vector<string> vecFillMsg;
		vecFillMsg.push_back(pWordFilter);
        SDStrcpy(pszErrInfo, CMsgDefMgr::Instance()->GetErrMsg("WORDFILTER", &vecFillMsg) .c_str());
        return  ERR_CHAT::ID_CHAT_VERIFY_ERROR;
    }

    //gmʹ��ϵͳ����
    if(IsGm(poPlayer))
    {
        stCHAT_DATA.byChatType = ECT_GM;
    }

    ChatInfo *pstChat = m_oChatDataPool.Alloc();
    if (NULL == pstChat)
    {
        return  ERR_CHAT::ID_CHAT_BUSY_ERROR;
    }

    memcpy(&pstChat->stData, &stCHAT_DATA, sizeof(CHAT_DATA));
    pstChat->byVipLevel      = poPlayer->GetDT_PLAYER_BASE_DATA().byVipLevel;
    pstChat->dwFactionIconID = poPlayer->GetFactionIconID();

    switch(stCHAT_DATA.byChatType)
    {
        // ȫ��Ƶ��
    case ECT_USER:
        AddWorldChat(pstChat);
        break;

    case ECT_GM:
        pstChat->dwFactionIconID = NULL_FACTION_ICON_ID;
        AddWorldChat(pstChat);
        break;

        // ����Ƶ��
    case ECT_FACTION:
        CFactionMgr::Instance()->AddChatData(poPlayer->GetID(), *pstChat);
        break;
    }

    return ERR_CHAT::ID_SUCCESS;
}

// �������� = �������� + �������� + ϵͳ���� + �����
VOID CChatMgr::SendChat()
{
    // ��ȡ��Ҫȫ���㲥�������¼ = �������� + ϵͳ���� + �����
    CChatList listChat;

    // ϵͳƵ�������¼
    TakeSysChat(listChat);

    // �Ƶ�������¼
    TakeActivityChat(listChat);

    // ����Ƶ�������¼
    TakeWorldChat(listChat);

    if (!listChat.empty())
    {
        // ��������������ң�һһ�����Ƿ���������Ϣ
        CSessionID2UserMapItr itr = CUserMgr::Instance()->m_mapSessionID2User.begin();
        for (itr; itr != CUserMgr::Instance()->m_mapSessionID2User.end(); itr++)
        {
            CUser* poUser = itr->second;

            // ���������¼�б����ң���������¼�϶����ɼ���������
            SendChatList(listChat, poUser);
        }
    }

    // �������������¼
    SendFactionChat();

    // ���������¼
    ClearWorldChat();
    ClearFactionChat();
    ClearActivityChat();
}

// �ɷ�ָ�������ڵ�������Ϣ
VOID CChatMgr::SendChatInFaction(CFaction *poFaction)
{
    if(NULL == poFaction)
    {
        return;
    }

    // ȡ�����������¼
    CChatDataList &listChatData = poFaction->GetChat();
    if(listChatData.empty())
    {
        return;
    }

    PKT_CLIGS_CHAT_NTF stAck;

    // �������ڵ����һһ��������Ƶ����������Ϣ
    CMapFactionPlayerData &mapPlayers = poFaction->GetFactionPlayers();
    for(CMapFactionPlayerData::iterator itr = mapPlayers.begin(); itr != mapPlayers.end(); ++itr)
    {
        DT_FACTION_PLAYER_DATA &stData = itr->second;

        CUser* poUser = CUserMgr::Instance()->FindUser(stData.dwJoinPlayerID);
        if (NULL == poUser)
        {
            continue;
        }

        CPlayer* poPlayer = poUser->GetPlayer();
        if(NULL == poPlayer)
        {
            continue;
        }

        // ���ͻ��˰汾�Ƿ�֧������Ƶ��
        if(poPlayer->GetCliVer() < CLI_NEW_CHAT_SUPPORT_VERSION)
        {
            continue;
        }

        // ���п������졢����
        if(NULL == poPlayer->GetBuild(EBK_FACTION) || NULL == poPlayer->GetBuild(EBK_VIEWCHAT))
        {
            continue;
        }

        TakeFactionChat(stAck, stData.dwJoinPlayerID, poFaction);
        if(stAck.byChatNum > 0)
        {
            poUser->SendMsg((CHAR*)&stAck, CLIGS_CHAT_NTF);
        }
    }

    // ���������¼
    poFaction->ClearChat();
}

VOID CChatMgr::AddFriendsOnline(UINT32 dwPlayerID, vector<UINT32> vecPlayerID)
{
    CPlayer *poPlayer = CPlayerMgr::Instance()->FindPlayer(dwPlayerID);
    if (NULL == poPlayer)
    {
        return;
    }

    PKT_CLIGS_CHAT_NTF stAck;
    memset(&stAck, 0x00, sizeof(PKT_CLIGS_CHAT_NTF));

    CHAT_DATA &stCHAT_DATA = stAck.astChatData[0];

    std::vector<string> vecFillMsg;
    vecFillMsg.clear();
    vecFillMsg.push_back(poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName);

    //��������{��������}������
    string strReport	   =  CMsgDefMgr::Instance()->GetErrMsg("ONLINE_REPORT", &vecFillMsg);
    stCHAT_DATA.dwPlayerID = 0;
    stCHAT_DATA.byChatType = ECT_SYS;
    stCHAT_DATA.qwChatTime = SDTimeSecs();
    stCHAT_DATA.dwChatLen  = (strReport.size() >= MAX_CHAT_CONTENT_NUM ? MAX_CHAT_CONTENT_NUM - 1 : strReport.size());
    memcpy(stCHAT_DATA.abyChatContent, strReport.c_str(), stCHAT_DATA.dwChatLen);
    stCHAT_DATA.dwSerialNumber = AllocChatSerialNum();

    stAck.byChatNum               = 1;
    stAck.abyVipLevel[0]          = 0;
    stAck.abyFactionIconIDList[0] = NULL_FACTION_ICON_ID;

    for (vector<UINT32>::iterator itr = vecPlayerID.begin(); itr != vecPlayerID.end(); itr++)
    {
        CPlayer *poPlayer = CPlayerMgr::Instance()->FindPlayer(*itr);
        if (NULL == poPlayer)
        {
            continue;
        }
        // ���п�������
        if(NULL == poPlayer->GetBuild(EBK_VIEWCHAT))
        {
            continue;
        }
        poPlayer->SendMsg((CHAR*)&stAck, CLIGS_CHAT_NTF);
    }
}

// ͬ����������δ�ɷ��������¼
VOID CChatMgr::SendFactionChat()
{
    CMapFaction &mapFaction = CFactionMgr::Instance()->GetFactions();
    for(CMapFactionItr itr = mapFaction.begin(); itr != mapFaction.end(); ++itr)
    {
        CFaction *poFaction = itr->second;
        SendChatInFaction(poFaction);
    }
}

// ȡ����������¼�浽��Ϣ��
VOID CChatMgr::GetChatData(PKT_CLIGS_OPEN_CHAT_ACK &stAck, CPlayer* poPlayer, UINT32 dwSerialNumber)
{
    CChatList listChat;
    GetChatCacheList(listChat, poPlayer, dwSerialNumber, MAX_CHAT_NUM, FALSE);

    // ������Ϣ��
    memset(&stAck, 0x00, sizeof(PKT_CLIGS_CHAT_NTF));
    for (CChatList::iterator itr = listChat.begin(); itr != listChat.end() && stAck.byChatNum < MAX_CHAT_NUM; itr++)
    {
        ChatInfo &stChatInfo = *itr;

        memcpy(&stAck.astChatData[stAck.byChatNum], &stChatInfo.stData, sizeof(CHAT_DATA));
        stAck.abyVipLevel[stAck.byChatNum]          = stChatInfo.byVipLevel;
        stAck.abyFactionIconIDList[stAck.byChatNum] = stChatInfo.dwFactionIconID;

        stAck.byChatNum++;
    }
}

// ȡ����������¼�浽����
VOID CChatMgr::GetChatData(CHAT_DATA astChatData[100], UINT8& byChatNum)
{
    CChatList listChat;
    GetChatCacheList(listChat, NULL, 0, 100, TRUE);

    byChatNum = 0;
    for (CChatList::iterator itr = listChat.begin(); itr != listChat.end() && byChatNum < 100; itr++)
    {
        ChatInfo &stChatInfo = *itr;
        memcpy(&astChatData[byChatNum++], &stChatInfo.stData, sizeof(CHAT_DATA));
    }
}

// ȡ������������¼�浽�б������硢����Ƶ��
VOID CChatMgr::GetChatCacheList(CChatList &listChat, CPlayer* poPlayer, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */, BOOL bGm/*�Ƿ���gm��gm���Կ�����������ҵ�����*/)
{
    listChat.clear();

    // �Ȱ�����Ƶ��������Ƶ����������������¼��ȡ�����ŵ��б�����б��������ʱ���ź���
    GetWorldChatCache(listChat, dwSerialNumber, wGetCnt, bGm);
    GetSysChatCache(listChat, dwSerialNumber, wGetCnt);

    if(NULL != poPlayer)
    {
        // ���ͻ��˰汾�Ƿ�֧�����ɺͻƵ��
        if(poPlayer->GetCliVer() >= CLI_NEW_CHAT_SUPPORT_VERSION)
        {
            GetFactionChatCache(listChat, poPlayer, dwSerialNumber, wGetCnt);

            // �ж�����Ƿ��ѿ�������ģ����򲻷��ͻ�����¼
            if(poPlayer->GetBuild(EBK_ACTIVITY))
            {
                GetActivityChatCache(listChat, dwSerialNumber, wGetCnt);
            }
        }
    }

    // Ȼ��ֻ����������������¼
    CChatList::iterator cutItr = listChat.begin();
    UINT32 dwSize = listChat.size();
    if(dwSize > wGetCnt)
    {
        advance(cutItr, dwSize - wGetCnt);
    }

    listChat.erase(listChat.begin(), cutItr);
}

// ȡ�����������Ƶ�������¼
VOID CChatMgr::GetWorldChatCache(CChatList &listChat, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */, BOOL bGm/*�Ƿ���gm��gm���Կ�����������ҵ�����*/)
{
    CChatDataListItr itr = m_listWorldChatPool.begin();

    UINT32 dwSize = m_listWorldChatPool.size();
    if(dwSize > wGetCnt)
    {
        advance(itr, dwSize - wGetCnt);
    }

    // ȡ������ָ����ˮ�ŵ������������Ƶ����¼
    for (; itr != m_listWorldChatPool.end(); itr++)
    {
        ChatInfo *pstChat = *itr;

        // ��������ҵ����콫�����·�����ͨ���
        if(FALSE == bGm && IsSilencedByPlayerID(pstChat->stData.dwPlayerID))
        {
            continue;
        }

        if (pstChat->stData.dwSerialNumber > dwSerialNumber)
        {
            listChat.push_back(*pstChat);
        }
    }
}

// ȡ�������ϵͳƵ�������¼
VOID CChatMgr::GetSysChatCache(CChatList &listChat, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */)
{
    CSysChatNoticeListItr itr = m_listSysChatNotice.begin();

    UINT32 dwSize = m_listSysChatNotice.size();
    if(dwSize > wGetCnt)
    {
        advance(itr, dwSize - wGetCnt);
    }

    // ȡ������ָ����ˮ�ŵĹ����¼
    for (; itr != m_listSysChatNotice.end(); itr++)
    {
        SYS_CHAT_DATA &stSysChat = *itr;
        if (stSysChat.stData.dwSerialNumber > dwSerialNumber)
        {
            ChatInfo stChatInfo;

            // ������Ϣ��
            memcpy(&stChatInfo.stData, &stSysChat.stData, sizeof(CHAT_DATA));
            stChatInfo.byVipLevel      = 0;
            stChatInfo.dwFactionIconID = NULL_FACTION_ICON_ID;

            // ��������ʱ�佫�����¼˳������б���
            chatutil::InsertChatByTime(listChat, stChatInfo);
        }
    }
}

// ȡ������ĻƵ�������¼
VOID CChatMgr::GetActivityChatCache(CChatList &listChat, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */)
{
    CActivityChatListItr itr = m_listActivityChatPool.begin();

    UINT32 dwSize = m_listActivityChatPool.size();
    if(dwSize > wGetCnt)
    {
        advance(itr, dwSize - wGetCnt);
    }

    // ȡ������ָ����ˮ�ŵĻƵ����¼
    for (; itr != m_listActivityChatPool.end(); itr++)
    {
        ACTIVITY_CHAT_DATA &stActChat = *itr;
        if (stActChat.stData.dwSerialNumber > dwSerialNumber)
        {
            ChatInfo stChatInfo;

            // ������Ϣ��
            memcpy(&stChatInfo.stData, &stActChat.stData, sizeof(CHAT_DATA));
            stChatInfo.byVipLevel      = 0;
            stChatInfo.dwFactionIconID = NULL_FACTION_ICON_ID;

            // ��������ʱ�佫�����¼˳������б���
            chatutil::InsertChatByTime(listChat, stChatInfo);
        }
    }
}

// ȡ�����������Ƶ�������¼
VOID CChatMgr::GetFactionChatCache(CChatList &listChat, CPlayer* poPlayer, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */)
{
    CFaction *poFaction = poPlayer->GetFaction();
    if(NULL == poFaction)
    {
        return;
    }

    // ��ȡ������Ƶ�������¼�б�
    CChatDataList &listFactionChat = poFaction->GetChatCache();
    CChatDataList::iterator itr = listFactionChat.begin();

    UINT32 dwSize = listFactionChat.size();
    if(dwSize > wGetCnt)
    {
        advance(itr, dwSize - wGetCnt);
    }

    // ȡ������ָ����ˮ�ŵ���������Ƶ����¼
    for (; itr != listFactionChat.end(); itr++)
    {
        ChatInfo *pstChat = *itr;
        if (pstChat->stData.dwSerialNumber > dwSerialNumber)
        {
            // ��������ʱ�佫�����¼˳������б���
            chatutil::InsertChatByTime(listChat, *pstChat);
        }
    }
}

BOOL CChatMgr::DspNameHaveSensitiveWord(CPlayer* poPlayer, const CHAR* pszData)
{
    if(NULL == poPlayer)
    {
        return TRUE;
    }

    //gm����ʹ�����д�
    if(IsGm(poPlayer))
    {
        return FALSE;
    }

    if(!CWordFilter::Instance()->VerifyDspNameString(pszData))
    {
        return  TRUE;
    }

    return FALSE;
}


//��ʾ����
string CChatMgr::EraseDspNameSuffix(const TCHAR aszDispName[USERNAME_LEN])
{
    TCHAR aszCopyDispName[USERNAME_LEN];
    SDStrncpy(aszCopyDispName, aszDispName, USERNAME_LEN);

    for(UINT16 i = 0; i < USERNAME_LEN; i++)
    {
        if(aszCopyDispName[i] == '(' || aszCopyDispName[i] == '#')
        {
            aszCopyDispName[i] = '\0';
            break;
        }
    }

    return aszCopyDispName;
}
