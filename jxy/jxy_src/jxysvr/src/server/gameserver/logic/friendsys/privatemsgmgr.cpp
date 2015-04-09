#include <common/server/utility.h>
#include <logic/base/dbconfig.h>
#include <sdstring.h>
#include <sdutil.h>
#include <sdloggerimpl.h>
#include <common/client/errdef.h>
#include <common/client/commondef.h>
#include "privatemsgmgr.h"
#include "sddb.h"
#include <framework/gsapi.h>
#include <logic/base/logicfunc.h>
#include "logic/player/player.h"

#include <db/dbmgr.h>
#include <db/basedbccmd.h>

using namespace SGDP;



const int MAX_PRIVATE_MSG_POOL_CACHE_NUM = 50;
const int MAX_MSG_TIMES = 600;

IMPLEMENT_SINGLETON(CPrivateMsgMgr);

CPrivateMsgMgr::CPrivateMsgMgr()
{
    m_dbMsgTime = SDTimeSecs();
    m_dbLastTime = SDTimeSecs();
    m_dbPrivateMsgList.clear();
    m_mapPrivateMsg.clear();
}

CPrivateMsgMgr::~CPrivateMsgMgr()
{

}

BOOL CPrivateMsgMgr::Init()
{
    m_dbLastTime = SDTimeSecs();
    m_dbPrivateMsgList.clear();
    m_mapPrivateMsg.clear();
    return TRUE;
}

VOID CPrivateMsgMgr::UnInit()
{

}

// �����ʱͬ����˽����Ϣsql
UINT16 CPrivateMsgMgr::AddPrivateMsg(SPrivateMsg& stPrivateMsg)
{
    SPrivateMsgList *	poPrivateMsgList = NULL;
    do
    {
        UINT64 qwKey1 = 0;
        qwKey1 = CLogicFunc::Get3232Key(stPrivateMsg.dwSenderID, stPrivateMsg.dwRecverID);
        CPrivateMsgMapItr itr = m_mapPrivateMsg.find(qwKey1);
        if (itr != m_mapPrivateMsg.end())
        {
            poPrivateMsgList = itr->second;
            break;
        }

        UINT64 qwKey2 = 0;
        qwKey2 = CLogicFunc::Get3232Key(stPrivateMsg.dwRecverID, stPrivateMsg.dwSenderID);
        itr = m_mapPrivateMsg.find(qwKey2);
        if (itr != m_mapPrivateMsg.end())
        {
            poPrivateMsgList = itr->second;
            break;
        }

        poPrivateMsgList = m_oPrivateMsgVecPool.Alloc();
        m_mapPrivateMsg.insert(make_pair(qwKey1, poPrivateMsgList));
        m_mapPrivateMsg.insert(make_pair(qwKey2, poPrivateMsgList));
    }
    while (0);

    if (NULL != poPrivateMsgList)
    {
        stPrivateMsg.dwMsgIdx = ++poPrivateMsgList->dwMaxMsgIdx;
        poPrivateMsgList->qwLastTime = SDTimeSecs();
        poPrivateMsgList->listPrivateMsg.push_back(stPrivateMsg);

        //���������ӣ�����
        m_dbPrivateMsgList.push_back(stPrivateMsg);

        //�����¼�������ݼ���Ƿ񱣴���࣬�ڴ�ֻ����50����
        if (poPrivateMsgList->listPrivateMsg.size() > MAX_PRIVATE_MSG_POOL_CACHE_NUM)
        {
            poPrivateMsgList->listPrivateMsg.pop_front();
        }
    }
    return 0;
}

// �����ҵ�˽����Ϣ
BOOL  CPrivateMsgMgr::CkPrivateMsg(UINT32 dwSenderID, UINT32 dwRecverID)
{
    UINT64			qwKey = 0;
    SPrivateMsgList *	poPrivateMsgList = NULL;
    do
    {
        qwKey = CLogicFunc::Get3232Key(dwSenderID, dwRecverID);
        CPrivateMsgMapItr itr = m_mapPrivateMsg.find(qwKey);
        if (itr != m_mapPrivateMsg.end())
        {
            return TRUE;
        }
        qwKey = CLogicFunc::Get3232Key(dwRecverID, dwSenderID);
        itr = m_mapPrivateMsg.find(qwKey);
        if (itr != m_mapPrivateMsg.end())
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CkPrivateMsg very import error!"), MSG_MARK);
            return FALSE;
        }
    }
    while (0);
    return FALSE;
}

//������Ϣ
BOOL CPrivateMsgMgr::SetPrivateMsgVec(UINT32 dwSenderID, UINT32 dwRecverID, SPrivateMsgList listPrivateMsg)
{
    do
    {
        UINT64 qwKey1 = CLogicFunc::Get3232Key(dwSenderID, dwRecverID);
        CPrivateMsgMapItr itr = m_mapPrivateMsg.find(qwKey1);
        if (itr != m_mapPrivateMsg.end())
        {
            SYS_CRITICAL(_SDT("[%s: %d]: SetPrivateMsgVec very import error at key1, sender = %u, recver = %u!!"), MSG_MARK, dwSenderID, dwRecverID);
            return TRUE;
        }

        UINT64 qwKey2 = CLogicFunc::Get3232Key(dwRecverID, dwSenderID);
        itr = m_mapPrivateMsg.find(qwKey2);
        if (itr != m_mapPrivateMsg.end())
        {
            SYS_CRITICAL(_SDT("[%s: %d]: SetPrivateMsgVec very import error at key2, recver = %u, sender = %u!!"), MSG_MARK, dwSenderID, dwRecverID);
            return TRUE;
        }

        SPrivateMsgList *poPrivateMsgList = m_oPrivateMsgVecPool.Alloc();
        if (NULL == poPrivateMsgList)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: SetPrivateMsgVec very import error: alloc msglist fail!!"), MSG_MARK);
            return FALSE;
        }

        *poPrivateMsgList = listPrivateMsg;
        m_mapPrivateMsg.insert(make_pair(qwKey1, poPrivateMsgList));
        m_mapPrivateMsg.insert(make_pair(qwKey2, poPrivateMsgList));
    }
    while (0);
    return FALSE;
}

// ����˽����Ϣ
UINT16 CPrivateMsgMgr::SendPrivateMsg(CPlayer* poPlayer, CPlayer* poTargetPlayer, TCHAR aszMsgContent[PRIVATE_MSG_CONTENT_LEN])
{
    // �������Ƿ�����
    CFriends *poFriends = poPlayer->GetFriends();
    if (NULL == poFriends)
    {
        return ERR_SEND_PRIVATE_MSG::ID_NO_OPEN;
    }

    UINT8 byFriendSysRelationType = poFriends->CkRelationType(poTargetPlayer->GetID());

    // �����˺���Ĺ�ϵ
    if(EFSRT_BLACKLIST == byFriendSysRelationType)
    {
        return ERR_SEND_PRIVATE_MSG::ID_REF_PLAYER_ALREADY_IN_YOUR_BLACKLIST; // ������Ϣʧ��, ���ѰѶԷ����������
    }

	CFriends *poTargetFriends = poTargetPlayer->GetFriends();
	if (NULL == poTargetFriends)
	{
		return ERR_SEND_PRIVATE_MSG::ID_NO_OPEN;
	}

    // ����Լ��ǲ��Ǳ��Է����������
    byFriendSysRelationType = poTargetFriends->CkRelationType(poPlayer->GetID());
    if(EFSRT_BLACKLIST == byFriendSysRelationType)
    {
        return ERR_SEND_PRIVATE_MSG::ID_YOU_ARE_IN_REF_PLAYER_BLACKLIST; // ������Ϣʧ��, �Է��Ѱ������������
    }

    // ����Լ���������Ϣ����˵��·�˼ף���ô���Լ��ӵ��Է���İ�����б���
    if(EFSRT_OTHER == byFriendSysRelationType)
    {
        byFriendSysRelationType = EFSRT_STRANGER;
        poTargetFriends->AddStranger(poPlayer->GetID());
    }

    SPrivateMsg stPrivateMsg;
    stPrivateMsg.dwSenderID		= poPlayer->GetID();
    stPrivateMsg.dwRecverID		= poTargetPlayer->GetID();
    SDStrncpy(stPrivateMsg.aszMsgContent, aszMsgContent, PRIVATE_MSG_CONTENT_LEN);
    stPrivateMsg.qwSendTime		= SGDP::SDTimeSecs();

	//������������¼
	poFriends->AddFinallyContact(poTargetPlayer->GetID());
	poTargetFriends->AddFinallyContact(poPlayer->GetID());

    AddPrivateMsg(stPrivateMsg);

    // 1 �Է�����
    if (poTargetPlayer->CkLogin())
    {
        stPrivateMsg.byIsRead = 1;

        // 1.2 ������Ϣ
        PKT_CLIGS_ONLINE_PRIVATE_MSG_NTF stNtf;
        stNtf.dwMsgIdx = stPrivateMsg.dwMsgIdx;
        stNtf.dwSendPlayerID = poPlayer->GetID();
        memcpy(stNtf.aszSendPlayerName, poPlayer->GetDT_PLAYER_BASE_DATA().aszDispName, USERNAME_LEN);
        stNtf.wMainHeroKindID = poPlayer->GetCoachHeroKindID();
        stNtf.byRelationType = byFriendSysRelationType;
        memcpy(stNtf.aszMsgContent, aszMsgContent, PRIVATE_MSG_CONTENT_LEN);
        stNtf.qwSendTime = stPrivateMsg.qwSendTime;
        poTargetPlayer->SendMsg((const CHAR*)(&stNtf), CLIGS_ONLINE_PRIVATE_MSG_NTF);
    }
    else
    {
        stPrivateMsg.byIsRead			= 0;
        poTargetFriends->AddUnReadEven(poPlayer->GetID());
    }

    return ERR_SEND_PRIVATE_MSG::ID_SUCCESS;
}

// ��ȡ��ĳ��ҵ�˽�ļ�¼
UINT16 CPrivateMsgMgr::GetPrivateMsgLogList(UINT32 dwSenderID, UINT32 dwRecverID, UINT32 dwStartIdx, UINT8 byGetMsgNum, UINT32& dwTotalNum, DT_PRIVATE_MSG_LIST_CLI& stMsgListCli)
{
    if (byGetMsgNum > MAX_PRIVATE_MSG_LIST_ELEM_NUM)
    {
        return ERR_GET_PRIVATE_MSG_LOG_LIST::ID_INVALID_REQ_PARAM; // ��Ч�Ĳ���
    }

    UINT64 qwKey = CLogicFunc::Get3232Key(dwSenderID, dwRecverID);
    CPrivateMsgMapItr itr = m_mapPrivateMsg.find(qwKey);
    if (itr == m_mapPrivateMsg.end())
    {
        return ERR_GET_PRIVATE_MSG_LOG_LIST::ID_NO_REF_DATA; // ��Ч�Ĳ���
    }

    SPrivateMsgList *poPrivateMsgList = itr->second;
    dwTotalNum = poPrivateMsgList->listPrivateMsg.size();

    stMsgListCli.dwMsgNum = 0;

    // ����˽���б��е�˽�ļ�¼Խ��end()�ķ���Խ�£�����������reverse_iterator���Ӻ���ǰȡС��ָ��������˽�ļ�¼
    for(CPrivateMsgList::reverse_iterator v_itr = poPrivateMsgList->listPrivateMsg.rbegin(); v_itr != poPrivateMsgList->listPrivateMsg.rend(); v_itr++)
    {
        SPrivateMsg &stMsg = *v_itr;

        // ����0��������ţ�ֱ�Ӵ��������
        if (0 != dwStartIdx && stMsg.dwMsgIdx >= dwStartIdx)
        {
            continue;
        }

        if(stMsgListCli.dwMsgNum >= byGetMsgNum || stMsgListCli.dwMsgNum >= MAX_PRIVATE_MSG_LIST_ELEM_NUM)
        {
            break;
        }

        DT_PRIVATE_MSG_DATA &stMsgData = stMsgListCli.astListData[stMsgListCli.dwMsgNum];
        memset(&stMsgData, 0x00, sizeof(DT_PRIVATE_MSG_DATA));

        stMsgData.dwMsgIdx   = stMsg.dwMsgIdx;

        //����Ƿ����Լ�������
        stMsgData.byIsRecv = (stMsg.dwSenderID == dwSenderID ? 0 : 1);

        // ���յ���δ����˽������Ϊ�Ѷ�����������������ݿ�
        //if (0 == stMsg.byIsRead && stMsg.dwRecverID == dwSenderID)
        //{
        //    stMsg.byIsRead = 1;

        //    //�����б仯�����޸ı���
        //    m_dbPrivateMsgList.push_back(stMsg);
        //}

        stMsgData.qwSendTime = stMsg.qwSendTime;
        memcpy(&stMsgData.aszMsgContent, stMsg.aszMsgContent, PRIVATE_MSG_CONTENT_LEN);

        stMsgListCli.dwMsgNum++;
    }

    // Ȼ��ߵ������ͻ��˵�˽���б��˳��ʹ��Խ���������˽��Խ��
    std::reverse(stMsgListCli.astListData, stMsgListCli.astListData + stMsgListCli.dwMsgNum);
    return ERR_GET_PRIVATE_MSG_LOG_LIST::ID_SUCCESS;
}

//��ʱ��������
BOOL CPrivateMsgMgr::OnSave()
{
    // ���ڼ�������¼�����ڹ��ڵ�����ɾ��
    UINT64 qwNow = SDTimeSecs();

    do{
        // ÿ10���Ӽ��һ�Σ���Ȼ̫�˷�ʱ���ˡ�
        if(qwNow - m_dbMsgTime < 10)
        {
            break;
        }

        m_dbMsgTime = qwNow;
		//��δ����Ϣ���ó��Ѷ�
		if ( 0 < m_setReadID.size())
		{
			CBaseDBCMD* poCMD = gsapi::GetDBMgr()->CreateCmd(EDBCT_SET_READ_PRIVATE_MSG);
			if(NULL == poCMD)
			{
				SYS_CRITICAL(_SDT("[%s: %d]: CreateCmd failed!"), MSG_MARK);
				return FALSE;
			}

			poCMD->SetUserData( &m_setReadID, 0 );
			gsapi::GetDBMgr()->AddCommand( poCMD );
			m_setReadID.clear();
		}

        SPrivateMsgList	*poExpiredMsgList = NULL;
        for (CPrivateMsgMapItr v_itr = m_mapPrivateMsg.begin(); v_itr != m_mapPrivateMsg.end(); v_itr++)
        {
            SPrivateMsgList	*poMsgList = v_itr->second;
            if(qwNow - poMsgList->qwLastTime > MAX_MSG_TIMES)
            {
                poExpiredMsgList = poMsgList;
                break;
            }
        }

        if(NULL == poExpiredMsgList)
        {
            break;
        }

        for (CPrivateMsgMapItr v_itr = m_mapPrivateMsg.begin(); v_itr != m_mapPrivateMsg.end();)
        {
            SPrivateMsgList	*poMsgList = v_itr->second;
            if(poMsgList == poExpiredMsgList)
            {
                m_mapPrivateMsg.erase(v_itr++);
            }
            else
            {
                v_itr++;
            }
        }

        m_oPrivateMsgVecPool.Free(poExpiredMsgList);
    }while(0);

    //����ڴ��Ƿ�������
    if(m_dbPrivateMsgList.empty())
    {
        return FALSE;
    }

    // �ڴ��е����ݳ���50�����߼�⵽ʱ���Ѿ�����һ��
    if(m_dbPrivateMsgList.size() > 50 || (qwNow - m_dbLastTime > 1))
    {
        CBaseDBCMD* poCMD = gsapi::GetDBMgr()->CreateCmd(EDBCT_SAVEPRIVATEMSGLOG);
        if(NULL == poCMD)
        {
            SYS_CRITICAL(_SDT("[%s: %d]: CreateCmd failed!"), MSG_MARK);
            return FALSE;
        }

        poCMD->SetUserData( &m_dbPrivateMsgList, 0 );
        gsapi::GetDBMgr()->AddCommand( poCMD );

        m_dbPrivateMsgList.clear();
        m_dbLastTime = qwNow;

        return TRUE;
    }

	
    return FALSE;
}

VOID CPrivateMsgMgr::AddReadMsg(UINT32 dwSendID, UINT32 dwRecvID)
{
	m_setReadID.insert(CLogicFunc::Get3232Key(dwSendID, dwRecvID));
}