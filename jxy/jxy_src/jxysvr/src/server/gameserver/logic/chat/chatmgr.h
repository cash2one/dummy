#ifndef CHATMGR_H_
#define CHATMGR_H_

#include <sdsingleton.h>
#include <sdobjectpool.h>
#include <sdmutex.h>

#include <list>
#include <logic/base/basepropmgr.h>
#include <protocommondata.h>
#include <db/getchatcmd.h>

using namespace SGDP;

class CUser;

struct tagCHAT_DATA;
typedef tagCHAT_DATA CHAT_DATA;

struct ACTIVITY_CHAT_DATA;

typedef struct tagSHILDED
{
    CHAR		szDeviceID[DEVICEID_LEN];
    UINT32	dwUserID;
    UINT32	dwPlayerID;
    tagSHILDED()
    {
        memset(this, 0x00, sizeof(tagSHILDED));
    }
} CSHILDED;


// ���͸���ҵ���������
struct ChatInfo
{
    ChatInfo()
        : byVipLevel(0)
        , dwFactionIconID(NULL_FACTION_ICON_ID)
    {
        memset(&stData, 0, sizeof(stData));
    }

    CHAT_DATA  stData;      // ��ҷ��͵���������
    BYTE       byVipLevel;  // ���vip�ȼ�
    BYTE       dwFactionIconID; // ����������ɵ�����ͼ��ID
};

// ����칫���б�
typedef std::list<ACTIVITY_CHAT_DATA>   	CActivityChatList;
typedef CActivityChatList::iterator        CActivityChatListItr;

// �����¼ָ���б�
typedef std::list<ChatInfo*>		    	CChatDataList;
typedef CChatDataList::iterator		    	CChatDataListItr;

// �����б�
typedef std::list<ChatInfo>		    	    CChatList;

// �����Ӧ��Ϣ���б�
typedef std::vector<PKT_CLIGS_CHAT_NTF>		CChatAckVec;
typedef CChatAckVec::iterator			    CChatAckVecItr;

typedef std::map<UINT32, UINT32>		    CChatSilenceMap;
typedef CChatSilenceMap::iterator           CChatSilenceMapItr;

class CPlayer;
class CFaction;

// ���������
class CChatMgr
{
public:
    DECLARE_SINGLETON(CChatMgr)

    BOOL Init();

    VOID UnInit();

    VOID ResetChat();

    UINT16	AddChatData(CPlayer *poPlayer, CHAT_DATA &stCHAT_DATA, TCHAR* pszErrInfo);

    // �������Ƶ�������¼
    VOID AddWorldChat(ChatInfo*);

    UINT32	OnEvent();

    // �����ع����б�����Ϊ���ݿ��ȡ���Ĺ����б�
    VOID SetSYSChatDataNoticeData(CSysChatNoticeList &listChatDataNotice);
    VOID SetWordFilterData(CWordFilterDataMap &mapWordFilterData, CWordFilterDataMap &mapDspNameWordFilterData);

    VOID AddWordFilterData(vector<string> &vecWordFilterData);
    VOID DelWordFilterData(vector<string> &vecWordFilterData);

    // ȡ����������¼�浽��Ϣ��
    VOID GetChatData(PKT_CLIGS_OPEN_CHAT_ACK &stAck, CPlayer* poPlayer, UINT32 dwSerialNumber);

    // ȡ����������¼�浽����
    VOID GetChatData(CHAT_DATA  astChatData[100], UINT8& byChatNum);


    VOID SetSilenceData(CChatSilenceByDeviceIDMap &mapSilenceByDeviceID,
                        CChatSilenceByUserIDMap &mapSilenceByUserID,
                        CChatSilenceByPlayerIDMap	&mapSilenceByPlayerID);

    VOID SetGMData(CStr32Map mapGmDeviceID, C3232Map mapGmPlayerID);

    // ����gm����
    VOID AddGmData(UINT32 dwPlayerID, string strDeviceID, UINT8 byOptType);

    // ���ϵͳ���칫��
    VOID AddSysChat(string strChatContent, string strExpiresTime, UINT8 byOptType);

    // ��ӻ���칫��
    VOID AddActivityChat(const string &strChatContent, UINT64 qwActivityStartTime = 0/*���ʼʱ�䣬��>0ʱ��ʾʱ�䵽ʱ�ŷ�����=0ʱ��ʾ��������*/);

	VOID AddFriendsOnline(UINT32 dwPlayerID, vector<UINT32> vecPlayerID);

    // ������������
    VOID BuildActivityChat(ACTIVITY_CHAT_DATA&, const string &strChatContent, UINT64 qwActivityStartTime = 0/*���ʼʱ�䣬��>0ʱ��ʾʱ�䵽ʱ�ŷ�����=0ʱ��ʾ��������*/);

    // ������ɻ����
    ChatInfo* BuildFactionActivityChat(UINT32 dwFactionID, const string &strChatContent);

    VOID AddSilenceData(vector<string> &vecSilenceByDeviceID,
                        vector<string> &vecSilenceByUserID,
                        vector<string>	&vecSilenceByPlayerID);

    VOID DelSilenceData(vector<string> &vecSilenceByDeviceID,
                        vector<string> &vecSilenceByUserID,
                        vector<string>	&vecSilenceByPlayerID);


    BOOL DspNameHaveSensitiveWord(CPlayer* poPlayer, const CHAR* pszData);//true:�����д�

    // �Ƴ�������ͻʱ���ɵ��ǳƺ�׺������������ƣ�С����ˮ(��3��)->С����ˮ
    string EraseDspNameSuffix(const TCHAR aszDispName[USERNAME_LEN]);

    SSyncSilenceWordfileter2Db& GetSyncSilenceWordfileter2Db()
    {
        return m_oSyncSilenceWordfileter2Db;
    }

    CChatSilenceByDeviceIDMap&	GetSilenceByDeviceID()
    {
        return m_mapSilenceByDeviceID;
    }
    CChatSilenceByUserIDMap&	GetSilenceByUserID()
    {
        return m_mapSilenceByUserID;
    }
    CChatSilenceByPlayerIDMap&	GetSilenceByPlayerID()
    {
        return m_mapSilenceByPlayerID;
    }

    // �ɷ�ָ�������ڵ�������Ϣ
    VOID SendChatInFaction(CFaction *poFaction);

    // ����������Ϣ�ڴ�
    VOID FreeChat(ChatInfo*);

    UINT32 AllocChatSerialNum()
    {
        return ++s_dwSerialNumber;
    }

    // �Ƿ���gm
    BOOL IsGm(CPlayer *poPlayer);

    // �Ƿ���gm
    BOOL IsGm(UINT32 dwPlayerID);

private:
    // �������� = �������� + �������� + ϵͳ���� + �����
    VOID SendChat();

    // ͬ����������δ�ɷ��������¼
    VOID SendFactionChat();

    // ��������Ƶ�������¼
    VOID ClearWorldChat();

    // ����Ƶ�������¼
    VOID ClearActivityChat();

    // ��������ɵ������¼
    VOID ClearFactionChat();

    // ȡ������Ƶ���������¼
    VOID TakeWorldChat(CChatList &listChat);

    // ȡ������Ƶ���������¼������Ϣ��
    VOID TakeFactionChat(PKT_CLIGS_CHAT_NTF &stAck, UINT32 dwPlayerID, CFaction *poFaction);

    // ��ȡϵͳ����
    VOID TakeSysChat(CChatList &listChat);

    // ��ȡ�����(ȫ��֪ͨ)
    VOID TakeActivityChat(CChatList &listChat/*�����*/);

    // ���������¼�б����ң���������¼�϶࣬����ɼ���������
    VOID SendChatList(CChatList &listChat, CUser *poUser);

    // ȡ������������¼�浽�б������硢����Ƶ��
    VOID GetChatCacheList(CChatList &listChat, CPlayer* poPlayer, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */, BOOL bGm/*�Ƿ���gm��gm���Կ�����������ҵ�����*/);

    // ȡ�����������Ƶ�������¼
    VOID GetWorldChatCache(CChatList &listChat, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */, BOOL bGm/*�Ƿ���gm��gm���Կ�����������ҵ�����*/);

    // ȡ�������ϵͳƵ�������¼
    VOID GetSysChatCache(CChatList &listChat, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */);

    // ȡ������ĻƵ�������¼
    VOID GetActivityChatCache(CChatList &listChat, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */);

    // ȡ�����������Ƶ�������¼
    VOID GetFactionChatCache(CChatList &listChat, CPlayer* poPlayer, UINT32 dwSerialNumber, UINT16 wGetCnt/* ȡ���������¼ */);

    // �Ƿ���gm
    BOOL IsGmByPlayerID(UINT32 dwPlayerID);

    // �Ƿ񱻽���
    BOOL IsSilenced(CPlayer *poPlayer);

    // �������ID����Ƿ񱻽���
    BOOL IsSilencedByPlayerID(UINT32 dwPlayerID);

protected:
    CChatMgr();
    ~CChatMgr();

protected:
    // ȡ��ϵͳ�����б�
    BOOL InitSysChatDB();
    BOOL InitSilenceDB();
    BOOL InitGMInfoDB();

private:
    CChatDataList						m_listWorldChat;         // ��ǰδ���͵�����Ƶ�������¼
    CChatDataList						m_listWorldChatPool;	 // ����Ƶ�������¼��ʷ

    CActivityChatList					m_listActivityChat;      // ��ǰδ���͵ĻƵ�������¼
    CActivityChatList                   m_listActivityChatPool;	 // �Ƶ������������ʷ

    UINT16                              m_wCurSysChatIdx;        // ��ǰ�ֲ���ϵͳ�����¼����
    CSysChatNoticeList  				m_listSysChatNotExpired; // δ���ڵ�ϵͳ�����¼
    CSysChatNoticeList				    m_listSysChatNotice;     // ϵͳ�����¼�б� = δ���� + �ѹ���

    UINT64								m_qwSendNoticeTime;      // �ϴη���ϵͳ�����ʱ��
    UINT64								m_qwChatSyncTime;        // �ϴδ����ݿ�ͬ�������¼��ʱ��

    CChatSilenceByDeviceIDMap			m_mapSilenceByDeviceID;
    CChatSilenceByUserIDMap				m_mapSilenceByUserID;
    CChatSilenceByPlayerIDMap			m_mapSilenceByPlayerID;
    CSDObjectPool<ChatInfo, CSDMutex>	m_oChatDataPool; //������칫����Ϣ

    SSyncSilenceWordfileter2Db			m_oSyncSilenceWordfileter2Db;

    CStr32Map							m_mapGmDeviceID;
    C3232Map							m_mapGmPlayerID;

    static UINT32                       s_dwSerialNumber;        // ��ˮ��
};

#endif
