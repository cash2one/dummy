
#ifndef _SEND_FLOWER_H_
#define _SEND_FLOWER_H_

#include <protocol/server/protocommondata.h>
#include <protocol/server/protocligs.h>
#include <logic/base/baseobj.h>
#include <queue>
#include <set>
#include <map>
#include <common/server/utility.h>
#include <list>
using namespace std;


// ����ϵͳ���ջ���Ϣ(�ͻ��ߡ��͵Ļ����������ͻ�ʱ��)
struct SRecvFlowerInfo
{
    UINT32 dwSenderID;
    UINT32 dwFlowerNum;
    UINT64 qwSendTime;
};

typedef std::deque<SRecvFlowerInfo> CRecvFlowerLogDeq; // ����ϵͳ���ջ�����(����Ϊ20)
typedef CRecvFlowerLogDeq::iterator CRecvFlowerLogDeqIter;


// ����ϵͳ�����Ϣ
struct SFSPlayerInfo
{
    UINT32           dwPlayerID; //���ID
    string           strPlayerName; //�����
    UINT16           wMainHeroKindID; //������ǽ�ɫID
    UINT8            byIsOnline; //�Ƿ�����
};

// �����������º���
struct strLess
{
    bool operator() (const SFSPlayerInfo& p1, const SFSPlayerInfo& p2) const
    {
        return p1.strPlayerName < p2.strPlayerName;
    }
};

typedef std::set<SFSPlayerInfo, strLess> CFSPlayerSet;
typedef CFSPlayerSet::iterator CFSPlayerSetIter;

typedef std::vector<SFSPlayerInfo> CFSPlayerVec;
typedef CFSPlayerVec::iterator CFSPlayerVecIter;

// ����ϵͳ���ͻ�ͳ����Ϣ
typedef std::map<UINT32, UINT16> CSendFlowerStatMap; // keyΪ�ͻ���������valueΪ�Ѿ��ͳ��Ĵ���
typedef CSendFlowerStatMap::iterator CSendFlowerStatMapIter;

struct SSendFlowerStat
{
    UINT64 qwLastUpdateTime; // ������ʱ��(���ڿ�������)
    CSendFlowerStatMap m_mapSendFlowerStat;
};

// ����ϵͳ������ĳ���ջ������ͻ���ϸͳ����Ϣ
typedef std::map<UINT32, SSendFlowerStat> CSendFlowerDetailStatMap; // keyΪ�ջ���ID
typedef CSendFlowerDetailStatMap::iterator CSendFlowerDetailStatMapIter;


typedef list<DT_RECV_FLOWER_DATA_LOG> CRecvFlowerDataList;
typedef CRecvFlowerDataList::iterator CRecvFlowerDataListItr;

typedef list<DT_RECV_FLOWER_DATA_EX_LOG>	CRecvFlowerDataExList;
typedef CRecvFlowerDataExList::iterator	CRecvFlowerDataExListItr;


typedef std::map<UINT32, UINT32>		CPlayerIDEvenMap;
typedef CPlayerIDEvenMap::iterator		CPlayerIDEvenMapItr;

// ����ϵͳ, ͨ�����set��vector
typedef map<UINT32, UINT64> CPlayerIDMap;
typedef CPlayerIDMap::iterator CPlayerIDMapIter;


typedef std::list<DT_FINALLY_CONTACT_DATA> CFinallyContactList; // ����ϵͳ�������ϵ��
typedef CFinallyContactList::iterator CFinallyContactListIter;





class CMultiMapFriends
{
    typedef multimap<UINT32, UINT32>		MultiMapFriends;
    typedef MultiMapFriends::iterator		MultiMapFriendsItr;
    typedef MultiMapFriends::const_iterator	MultiMapFriendsConstItr;
    typedef pair<MultiMapFriendsItr,		MultiMapFriendsItr> FriendsRange;

public:
    CMultiMapFriends()
    {
        m_multiMapFriends.clear();
    }
    ~CMultiMapFriends()
    {
        m_multiMapFriends.clear();
    }

    void Add(UINT32 dwPlayerA, UINT32 dwPlayerB)
    {
        //������ұ������ѹ�ϵ��
        BOOL bFound = FALSE;
        FriendsRange   range = m_multiMapFriends.equal_range(dwPlayerA);
        for(MultiMapFriendsItr itr = range.first; itr != range.second; itr++)
        {
            if (itr->second == dwPlayerB)
            {
                bFound = TRUE;
                break;
            }
        }

        //������ѵ�ȫ�ֹ�ϵ��
        if (!bFound)
        {
            m_multiMapFriends.insert(make_pair(dwPlayerA, dwPlayerB));
        }
    }

    void earse(UINT32 dwPlayerA, UINT32 dwPlayerB)
    {
        FriendsRange   range = m_multiMapFriends.equal_range(dwPlayerA);
        for(MultiMapFriendsItr itr = range.first; itr != range.second;)
        {
            if (itr->second == dwPlayerB)
            {
                m_multiMapFriends.erase(itr++);
                break;
            }
            else
            {
                itr++;
            }
        }
    }

    void GetFriends(UINT32 dwPlayerID, vector<UINT32> &vecPlayerid)
    {
        FriendsRange   range = m_multiMapFriends.equal_range(dwPlayerID);
        for(MultiMapFriendsItr itr = range.first; itr != range.second; itr++)
        {
            vecPlayerid.push_back(itr->second);
        }
    }

private:
    MultiMapFriends m_multiMapFriends;

};



class CPlayer;
class CFriends: public CBaseObj
{
public:
    CFriends();
    ~CFriends();
public:
    // ��ʼ����ض���

    BOOL Init(DT_FRIENDS_DATA &stDT_FRIENDS_DATA, CPlayer* poOwner);



    DT_FRIENDS_BASE_DATA& GetDT_FRIENDS_BASE_DATA();

    // 1��ȡ��ϵ����б�
    UINT16 GetFriendSysPlayerList(UINT8 byGetListType, UINT8 byPageCapacity, UINT8 byPageNo, UINT32& dwTotalNum, DT_FRIEND_SYS_PLAYER_LIST_CLI& stFriendSysPlayerList);

	// 1��ȡ��ϵ����б�
	UINT16 GetFriendSysPlayerList2(UINT8 byGetListType, UINT8 byPageCapacity, UINT8 byPageNo, UINT32& dwTotalNum, DT_FRIEND_SYS_PLAYER_LIST_CLI2& stFriendSysPlayerList);

    // 2ɾ������
    UINT16 DelFriend(UINT32 dwFirendPlayerID);

    // 3�������(Э�����޸�)
    UINT16 SearchPlayer(TCHAR aszPlayerName[USERNAME_LEN], UINT8 byPageCapacity, UINT8 byPageNo, UINT32& dwTotalNum, DT_FRIEND_SYS_PLAYER_LIST_CLI& stFriendSysPlayerList);

	// 3�������(Э�����޸�)
	UINT16 SearchPlayer2(TCHAR aszPlayerName[USERNAME_LEN], UINT8 byPageCapacity, UINT8 byPageNo, UINT32& dwTotalNum, DT_FRIEND_SYS_PLAYER_LIST_CLI2& stFriendSysPlayerList);


    // 4�鿴��Ҹ�Ҫ��Ϣ
    UINT16 ViewPlayerInfo(UINT32 dwPlayerID, PKT_CLIGS_VIEW_PLAYER_ACK& stAck);

    // 5��Ӻ���
    UINT16 AddFriend(UINT32 dwPlayerID);

    // 6�����ʻ����
    UINT16 OpenSendFlowerTab(DT_SEND_FLOWER_PROP_LIST_CLI& stSendFlowerPropList, UINT32 dwRecvPlayerID);


    // 7���ʻ�
    UINT16 SendFlower(CPlayer* poTargetPlayer, UINT32 dwSendFlowerNum, UINT64& qwRecverFlowerSum);

    // 8��ȡ�ʻ���Ϣ
    UINT16 GetFlowerByPlayerID(UINT64& qwFlowerSum, UINT32& dwMyFlowerRanking, DT_RECV_FLOWER_LOG_LIST_CLI& stRecvFlowerLogList);


    // �����Ҽ�Ĺ�ϵ(�����Ƿ�����)
    UINT16 GetRelationType(UINT32 dwRefPlayerID, UINT8& byRelationType);

    // ���İ����
    UINT16 AddStranger(UINT32 dwRefPlayerID);

    // 12���������
    UINT16 AddToBlackList(CPlayer *poTargetPlayer);

    // 13�Ƴ�������
    UINT16 MoveFromBlackList(UINT32 dwPlayerID);


    // 14��ȡ��������Ϣ������б�
    UINT16 GetSendOfflineMsgPlayerList(DT_SEND_OFFLINE_MSG_PLAYER_LIST_CLI& stSendOfflineMsgPlayerList);



    // ��ȡ����ĳ����Ұ������Ϊ���ѵ��¼�֪ͨ(�����ߵ�ʱ��)
    UINT16 ReadOfflineMsg(UINT32 dwAddPlayerID);

    void AddRecvFlowerData(UINT32 dwSendPlayerID, UINT32 dwFlowerNum);

    UINT8 CkRelationType(UINT32 dwPlayerID);

    VOID AddRelationEven(UINT32 dwPlayerID);
    VOID AddUnReadEven(UINT32 dwSendPlayerID);
    VOID DelUnReadEven(UINT32 dwSendPlayerID);
    // ��ȡ��ҵ�������Ϣ����
    UINT16 GetOfflinePrivateMsgNum(UINT16& wOfflineMsgNum);

    //���������
    VOID AddFinallyContact(UINT32 dwPlayerID);


    UINT16 OpenRecvFlowerTab(DT_RECV_FLOWER_LOG_LIST_CLI_EX &stRecvFlowerLogListCLiEx);

    //�ͻ�
    UINT16 AcceptFlower(UINT32 dwSendPlayerID, UINT64 qwSendTime, PKT_CLIGS_ACCEPT_FLOWER_ACK &stAck);

    // 6�����ʻ����
    UINT16 OpenSendFlowerTabEx(PKT_CLIGS_OPEN_SEND_FLOWER_TAB_EX_ACK &stAck);

    // 7���ʻ�
    UINT16 SendFlowerEx(CPlayer* poTargetPlayer, UINT32 dwKindID, PKT_CLIGS_SEND_FLOWER_EX_ACK &stAck);

    //�����ͻ�
    void AddRecvFlowerDataEx(UINT32 dwSendPlayerID, UINT32 dwKindID);

	//����ͻ��Ƿ�����ͻ�
	BOOL CkRecvFlowerDataEx();

	UINT8 GetUnReceiveNum();

    UINT32  GetFriendsNum() { return m_mapFriend.size(); }
public:
    BOOL GetRelationDataList(DT_RELATION_DATA_LIST &stRelationDataList);

    BOOL GetDataEvenList(DT_DATA_EVEN_LIST &stDT_DATA_EVEN_LIST);

    BOOL GetRecvFlowerLogList(DT_RECV_FLOWER_LOG_LIST &stRecvFlowerLogList);

	void CkRecvFlowerNtf();

protected:
    //
    UINT16 GetFSPlayerInfoByID(UINT32 dwRefPlayerID, SFSPlayerInfo& stFSPlayerInfo);


    // �����û����ܲ��ҵ���Ҹ���
    UINT16 GetSearchPlayerRowCnt(TCHAR aszPlayerName[USERNAME_LEN], UINT32& dwTotalNum);

    BOOL ChkAndSetSendFlowerInitVal();

	VOID CkDataEveryDay();

public:
    static void GetFriends(UINT32 dwPlayerID, vector<UINT32> &vecPlayerid)
    {
        s_multiMapFriends.GetFriends(dwPlayerID, vecPlayerid);
    }


private:
    CPlayerIDMap			m_mapFriend; // ����
    CPlayerIDMap			m_mapStranger; // İ����
    CPlayerIDMap			m_mapBlackList; // ������
    CPlayerIDEvenMap		m_mapRelationEven;
    CPlayerIDEvenMap		m_mapUnReadEven;
    CRecvFlowerLogDeq		m_deqFlowerLog; // �ջ�����(����Ϊ20)
    CRecvFlowerDataList	m_listRecvFlowerData;
    CRecvFlowerDataExList	m_listRecvFlowerDataEx;
    DT_FRIENDS_BASE_DATA	m_stDT_FRIENDS_BASE_DATA;

    CFinallyContactList	m_listFinallyContact;

    static CMultiMapFriends	s_multiMapFriends;


};
DECLARE_CLASS_POOL_MGR(CFriends)

#endif // #ifndef 